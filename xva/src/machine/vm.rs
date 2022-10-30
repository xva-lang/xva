use super::{flags::Flag, flags::FlagsRegister, opcode::Opcode};

const MAX_REGISTERS: usize = 32;
pub(crate) struct VirtualMachine {
    registers: [i64; MAX_REGISTERS],
    program_counter: usize,
    program: Vec<u8>,
    remainder: i64,
    flags: FlagsRegister,
}

impl VirtualMachine {
    pub(crate) fn new() -> Self {
        Self {
            registers: [0; MAX_REGISTERS],
            program_counter: 0,
            program: vec![],
            remainder: 0,
            flags: FlagsRegister::new(),
        }
    }

    pub(crate) fn run(&mut self) {
        loop {
            if self.program_counter >= self.program.len() {
                break;
            }

            match self.decode() {
                Opcode::Halt => {
                    println!("exit!");
                    break;
                }
                Opcode::LoadRegister => {
                    let register_number = self.require_next_byte() as usize;
                    let value = self.require_next_word() as i64;
                    self.registers[register_number] = value;
                }
                Opcode::Add => {
                    let (left, right) = (
                        self.registers[self.require_next_byte() as usize],
                        self.registers[self.require_next_byte() as usize],
                    );
                    let dest = self.require_next_byte() as usize;
                    self.registers[dest] = left + right;
                    self.assess_flags(self.registers[dest]);
                }
                Opcode::Subtract => {
                    let (left, right) = (
                        self.registers[self.require_next_byte() as usize],
                        self.registers[self.require_next_byte() as usize],
                    );
                    let dest = self.require_next_byte() as usize;
                    self.registers[dest] = left - right;
                    self.assess_flags(self.registers[dest]);
                }
                Opcode::IntegerMultiply => {
                    let (left, right) = (
                        self.registers[self.require_next_byte() as usize],
                        self.registers[self.require_next_byte() as usize],
                    );
                    let dest = self.require_next_byte() as usize;
                    self.registers[dest] = left * right;
                    self.assess_flags(self.registers[dest]);
                }
                Opcode::IntegerDivide => {
                    let (left, right) = (
                        self.registers[self.require_next_byte() as usize],
                        self.registers[self.require_next_byte() as usize],
                    );
                    let dest = self.require_next_byte() as usize;
                    self.registers[dest] = left / right;
                    self.remainder = left % right;
                    self.assess_flags(self.registers[dest]);
                }
                Opcode::AbsoluteJump => {
                    self.program_counter =
                        self.registers[self.require_next_byte() as usize] as usize
                }
                Opcode::BackwardsRelativeJump => {
                    self.program_counter -=
                        self.registers[self.require_next_byte() as usize] as usize;
                }
                Opcode::ForwardsRelativeJump => {
                    self.program_counter +=
                        self.registers[self.require_next_byte() as usize] as usize
                }

                Opcode::Compare => {
                    let (left, right) = (
                        self.registers[self.require_next_byte() as usize],
                        self.registers[self.require_next_byte() as usize],
                    );
                    self.assess_flags(left - right);
                    self.consume();
                }

                Opcode::BranchIfEqual => {
                    let address = self.registers[self.require_next_byte() as usize] as usize;
                    if self.flags.is_flag_set(Flag::Zero) {
                        self.program_counter = address;
                    }
                }

                Opcode::BranchIfNotEqual => {
                    let address = self.registers[self.require_next_byte() as usize] as usize;
                    if !self.flags.is_flag_set(Flag::Zero) {
                        self.program_counter = address;
                    };
                }
                unknown => {
                    println!("Unrecognised opcode: {:?}", unknown)
                }
            }
        }
    }

    fn decode(&mut self) -> Opcode {
        let result = Opcode::from(self.program[self.program_counter]);
        self.program_counter += 1;
        result
    }

    fn require_next_byte(&mut self) -> u8 {
        let result = self.program[self.program_counter];
        self.program_counter += 1;
        result
    }

    fn require_next_word(&mut self) -> u16 {
        ((self.require_next_byte() as u16) << 8) | self.require_next_byte() as u16
    }

    fn consume(&mut self) {
        self.program_counter += 1;
    }

    fn assess_flags(&mut self, value: i64) {
        if value == 0 {
            self.flags.set_flag(Flag::Zero);
        }

        if value < 0 {
            self.flags.set_flag(Flag::Sign);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Flag;
    use super::Opcode;
    use super::VirtualMachine;

    #[test]
    fn create_machine() {
        let vm = VirtualMachine::new();
        assert_eq!(vm.registers[0], 0);
    }

    #[test]
    fn decode_opcode_halt() {
        let mut vm = VirtualMachine::new();
        vm.program = vec![0, 0, 0, 0];
        vm.run();
        assert_eq!(vm.program_counter, 1);
    }

    #[test]
    fn decode_illegal_opcode() {
        let mut vm = VirtualMachine::new();
        vm.program = vec![69, 42, 0xff, 0xff];
        vm.run();
        assert_eq!(vm.program_counter, 4);
    }

    #[test]
    fn decode_load_register() {
        let mut vm = VirtualMachine::new();
        vm.program = vec![Opcode::LoadRegister.into(), 1, 0x34, 0x12];
        vm.run();
        assert_eq!(vm.registers[1], 0x3412);
    }

    #[test]
    fn decode_add() {
        let mut vm = VirtualMachine::new();
        vm.program = vec![
            Opcode::LoadRegister.into(),
            1,
            0,
            0x4,
            Opcode::LoadRegister.into(),
            2,
            0,
            0x5,
            Opcode::Add.into(),
            1,
            2,
            3,
        ];
        vm.run();
        assert_eq!(vm.registers[3], 0x9);
    }

    #[test]
    fn decode_absolute_jump() {
        let mut vm = VirtualMachine::new();
        vm.registers[2] = 7;
        vm.program = vec![
            Opcode::AbsoluteJump.into(),
            2,
            0,
            0,
            0,
            0,
            0,
            Opcode::LoadRegister.into(),
            1,
            0,
            0x4,
            Opcode::LoadRegister.into(),
            2,
            0,
            0x5,
            Opcode::Add.into(),
            1,
            2,
            3,
        ];

        vm.run();
        assert_eq!(vm.registers[3], 0x9);
    }

    #[test]
    fn forward_relative_jump() {
        let mut vm = VirtualMachine::new();
        vm.program = vec![
            Opcode::LoadRegister.into(),
            1,
            0x12,
            0x34,
            Opcode::ForwardsRelativeJump.into(),
            1,
        ];
        vm.run();

        assert_eq!(vm.program_counter, 0x1234 + vm.program.len());
    }

    #[test]
    fn compare() {
        let mut vm = VirtualMachine::new();
        vm.program = vec![
            Opcode::LoadRegister.into(),
            1,
            0,
            1,
            Opcode::LoadRegister.into(),
            2,
            0,
            1,
            Opcode::Compare.into(),
            1,
            2,
            0,
        ];

        vm.run();
        assert!(vm.flags.is_flag_set(Flag::Zero));
    }

    #[test]
    fn branch_if_equal() {
        let mut vm = VirtualMachine::new();
        vm.registers[2] = 7;
        vm.flags.set_flag(Flag::Zero);

        vm.program = vec![
            Opcode::BranchIfEqual.into(),
            2,
            0,
            0,
            0,
            0,
            0,
            Opcode::LoadRegister.into(),
            1,
            0,
            0x4,
            Opcode::LoadRegister.into(),
            2,
            0,
            0x5,
            Opcode::Add.into(),
            1,
            2,
            3,
        ];

        vm.run();
        assert_eq!(vm.registers[3], 0x9);
    }
}
