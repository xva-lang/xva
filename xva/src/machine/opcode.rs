#[derive(Debug, PartialEq)]
pub(crate) enum Opcode {
    /// Size: 1 byte
    Halt,
    Illegal,

    /// Size: 4 bytes
    ///
    /// n - `OPCODE_LOAD_REGISTER`
    ///
    /// n + 1 - Register number
    ///
    /// n + 2 - Constant high byte
    ///
    /// n + 3 - Constant low byte
    LoadRegister,

    /// Size: 4 bytes
    /// n - `OPCODE_ADD`
    ///
    /// n + 1 - Left register number
    ///
    /// n + 2 - Right register number
    ///
    /// n + 3 - Destination register
    Add,

    /// Size: 4 bytes
    /// n - `OPCODE_SUBTRACT`
    ///
    /// n + 1 - Left register number
    ///
    /// n + 2 - Right register number
    ///
    /// n + 3 - Destination register
    Subtract,

    /// Size: 4 bytes
    /// n - `OPCODE_INT_MULTIPLY`
    ///
    /// n + 1 - Left register number
    ///
    /// n + 2 - Right register number
    ///
    /// n + 3 - Destination register
    IntegerMultiply,

    /// Size: 4 bytes
    /// n - `OPCODE_INT_DIVIDE`
    ///
    /// n + 1 - Left register number
    ///
    /// n + 2 - Right register number
    ///
    /// n + 3 - Destination register
    IntegerDivide,

    /// Size: 2 bytes
    /// n - `OPCODE_ABSOLUTE_JUMP`
    ///
    /// n + 1  - Address of register containing absolute address
    AbsoluteJump,

    /// Size: 2 byes
    /// n - `OPCODE_BACKWARDS_RELATIVE_JUMP`
    ///
    /// n + 1 - Address of register containing address offset, program counter-relative
    BackwardsRelativeJump,

    /// Size: 2 byes
    /// n - `OPCODE_FORWARDS_RELATIVE_JUMP`
    ///
    /// n + 1 - Address of register containing address offset, program counter-relative
    ForwardsRelativeJump,

    /// Size: 4 bytes
    ///
    /// n - `OPCODE_COMPARE`
    ///
    /// n + 1 - Address of register with left operand
    ///
    /// n + 2 - Address of register with right operand
    ///
    /// n + 3 - Consumed for alignment
    Compare,

    /// Size: 2 bytes
    ///
    /// n - `OPCODE_BRANCH_IF_EQUAL`
    ///
    /// n + 1 - Address of register with absolute address
    BranchIfEqual,

    /// Size: 2 bytes
    ///
    /// n - `OPCODE_BRANCH_IF_NOT_EQUAL`
    ///
    /// n + 1 - Address of register with absolute address
    BranchIfNotEqual,
}

const OPCODE_HALT: u8 = 0;
const OPCODE_LOAD_REGISTER: u8 = 1;
const OPCODE_ADD: u8 = 2;
const OPCODE_SUBTRACT: u8 = 3;
const OPCODE_INT_MULTIPLY: u8 = 4;
const OPCODE_INT_DIVIDE: u8 = 5;
const OPCODE_ABSOLUTE_JUMP: u8 = 6;
const OPCODE_BACKWARDS_RELATIVE_JUMP: u8 = 7;
const OPCODE_FORWARDS_RELATIVE_JUMP: u8 = 8;
const OPCODE_COMPARE: u8 = 9;
const OPCODE_BRANCH_IF_EQUAL: u8 = 0xA;
const OPCODE_BRANCH_IF_NOT_EQUAL: u8 = 0xB;

impl From<u8> for Opcode {
    fn from(value: u8) -> Self {
        match value {
            OPCODE_HALT => Opcode::Halt,
            OPCODE_LOAD_REGISTER => Opcode::LoadRegister,
            OPCODE_ADD => Opcode::Add,
            OPCODE_SUBTRACT => Opcode::Subtract,
            OPCODE_INT_MULTIPLY => Opcode::IntegerMultiply,
            OPCODE_INT_DIVIDE => Opcode::IntegerDivide,
            OPCODE_ABSOLUTE_JUMP => Opcode::AbsoluteJump,
            OPCODE_BACKWARDS_RELATIVE_JUMP => Opcode::BackwardsRelativeJump,
            OPCODE_FORWARDS_RELATIVE_JUMP => Opcode::ForwardsRelativeJump,
            OPCODE_COMPARE => Opcode::Compare,
            OPCODE_BRANCH_IF_EQUAL => Opcode::BranchIfEqual,
            OPCODE_BRANCH_IF_NOT_EQUAL => Opcode::BranchIfNotEqual,
            _ => Opcode::Illegal,
        }
    }
}

impl From<Opcode> for u8 {
    fn from(value: Opcode) -> Self {
        match value {
            Opcode::Halt => OPCODE_HALT,
            Opcode::Illegal => panic!("Can't convert illegal opcode"),
            Opcode::LoadRegister => OPCODE_LOAD_REGISTER,
            Opcode::Add => OPCODE_ADD,
            Opcode::Subtract => OPCODE_SUBTRACT,
            Opcode::IntegerMultiply => OPCODE_INT_MULTIPLY,
            Opcode::IntegerDivide => OPCODE_INT_DIVIDE,
            Opcode::AbsoluteJump => OPCODE_ABSOLUTE_JUMP,
            Opcode::BackwardsRelativeJump => OPCODE_BACKWARDS_RELATIVE_JUMP,
            Opcode::ForwardsRelativeJump => OPCODE_FORWARDS_RELATIVE_JUMP,
            Opcode::Compare => OPCODE_COMPARE,
            Opcode::BranchIfEqual => OPCODE_BRANCH_IF_EQUAL,
            Opcode::BranchIfNotEqual => OPCODE_BRANCH_IF_NOT_EQUAL,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Opcode;

    #[test]
    fn illegal_opcode() {
        assert_eq!(Opcode::from(0xFF), Opcode::Illegal);
    }

    #[test]
    fn halt_opcode() {
        assert_eq!(Opcode::from(0), Opcode::Halt);
    }
}
