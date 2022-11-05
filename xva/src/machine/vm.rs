use super::{flags::Flag, flags::FlagsRegister, opcode::Opcode};

pub(crate) const MAX_REGISTERS: usize = 256;
const MAX_STACK: usize = 1024; // FIXME
pub(crate) struct VirtualMachine {
    registers: [i64; MAX_REGISTERS],
    stack: [i64; MAX_STACK],
    stack_pointer: usize,
    program_counter: usize,
    pub(crate) program: Vec<u8>,
    remainder: i64,
    flags: FlagsRegister,
}

impl VirtualMachine {
    pub(crate) fn new() -> Self {
        Self {
            registers: [0; MAX_REGISTERS],
            stack: [0; MAX_STACK],
            stack_pointer: 0,
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

            match self.next_instruction() {
                Opcode::Halt => {
                    break;
                }

                Opcode::Add => {
                    let (right, left) = (
                        match self.pop_i64() {
                            Some(x) => x,
                            None => {
                                println!("Stack underflow!");
                                break;
                            }
                        },
                        match self.pop_i64() {
                            Some(x) => x,
                            None => {
                                println!("Stack underflow!");
                                break;
                            }
                        },
                    );
                    let value = left + right;
                    self.push_i64(value);
                    self.assess_flags(value);
                }
                Opcode::Subtract => {
                    let (right, left) = (
                        match self.pop_i64() {
                            Some(x) => x,
                            None => {
                                println!("Stack underflow!");
                                break;
                            }
                        },
                        match self.pop_i64() {
                            Some(x) => x,
                            None => {
                                println!("Stack underflow!");
                                break;
                            }
                        },
                    );
                    let value = left - right;
                    self.push_i64(value);
                    self.assess_flags(value);
                }
                Opcode::IntegerMultiply => {
                    let (right, left) = (
                        match self.pop_i64() {
                            Some(x) => x,
                            None => {
                                println!("Stack underflow!");
                                break;
                            }
                        },
                        match self.pop_i64() {
                            Some(x) => x,
                            None => {
                                println!("Stack underflow!");
                                break;
                            }
                        },
                    );
                    let value = left * right;
                    self.push_i64(value);
                    self.assess_flags(value);
                }
                Opcode::IntegerDivide => {
                    let (right, left) = (
                        match self.pop_i64() {
                            Some(x) => x,
                            None => {
                                println!("Stack underflow!");
                                break;
                            }
                        },
                        match self.pop_i64() {
                            Some(x) => x,
                            None => {
                                println!("Stack underflow!");
                                break;
                            }
                        },
                    );
                    let value = left / right;
                    self.remainder = left % right;
                    self.push_i64(value);
                    self.assess_flags(value);
                }
                Opcode::AbsoluteJump => {
                    self.program_counter = self.require_next_double_word() as usize;
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

                Opcode::LoadInteger => {
                    let value = self.require_next_quad_word();
                    self.push_i64(value);
                }
                unknown => {
                    println!("Unrecognised opcode: {:?}", unknown)
                }
            }
        }
    }

    fn next_instruction(&mut self) -> Opcode {
        let result = Opcode::from(self.program[self.program_counter]);
        self.program_counter += 1;
        result
    }

    fn require_next_byte(&mut self) -> u8 {
        let result = self.program[self.program_counter];
        self.program_counter += 1;
        result
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

    fn require_next_quad_word(&mut self) -> i64 {
        self.program_counter += 8;

        i64::from_le_bytes(
            self.program[self.program_counter - 8..self.program_counter]
                .try_into()
                .expect("Bad array"),
        )
    }

    fn require_next_double_word(&mut self) -> i32 {
        self.program_counter += 4;

        i32::from_le_bytes(
            self.program[self.program_counter - 4..self.program_counter]
                .try_into()
                .expect("Bad array"),
        )
    }

    fn push_i64(&mut self, value: i64) {
        self.stack[self.stack_pointer] = value;
        self.stack_pointer += 1;
    }

    pub(crate) fn pop_i64(&mut self) -> Option<i64> {
        if self.stack_pointer == 0 {
            return None;
        }

        self.stack_pointer -= 1;
        Some(self.stack[self.stack_pointer])
    }

    pub(crate) fn reset_program_counter(&mut self) {
        self.program_counter = 0;
    }

    #[allow(dead_code)]
    pub(crate) fn print_stack(&self) {
        for i in (0..MAX_STACK).step_by(8) {
            println!(
                "0x{:x} 0x{:x} 0x{:x} 0x{:x} 0x{:x} 0x{:x} 0x{:x} 0x{:x}",
                self.stack[i],
                self.stack[i + 1],
                self.stack[i + 2],
                self.stack[i + 3],
                self.stack[i + 4],
                self.stack[i + 5],
                self.stack[i + 6],
                self.stack[i + 7]
            )
        }
    }
}

#[cfg(test)]
mod tests {
    use super::VirtualMachine;
    use crate::compiler::Compiler;

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

    fn expect_return_value(input: &str, return_val: i64) {
        let parse_tree = xvasyntax::parser::parse(input);
        let mut lines: Vec<&str> = input.split("\n").collect();
        let mut compiler = Compiler::new(parse_tree.get_line_indexes(), &mut lines);

        let mut root = xvasyntax::ast::root::Root::cast(parse_tree.get_root_node()).unwrap();

        compiler.compile(&mut root);
        let mut vm = VirtualMachine::new();
        vm.program = compiler.get_output_as_slice().to_vec();
        vm.run();
        assert_eq!(vm.pop_i64().unwrap(), return_val);
    }

    #[test]
    fn expression_program() {
        expect_return_value("1 + 36 * 32 - 1477", -324);
    }

    #[test]
    fn parenthesised_expression_program() {
        expect_return_value("2 * (3 * 3)", 18)
    }
}
