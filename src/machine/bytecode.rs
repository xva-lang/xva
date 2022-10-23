pub enum Opcode {
    Nop,
    PushConstInteger,
    PushConstFloat,
    PushConstBoolean,
    PushConstChar,
    Add,
    Subtract,
    IntegerMultiply,
    IntegerDivide,
}

pub trait Bytecodeable {
    fn as_byte(self) -> u8;
}

pub trait Opcodeable {
    fn as_opcode(self) -> Opcode;
}

impl Bytecodeable for Opcode {
    fn as_byte(self) -> u8 {
        match self {
            Opcode::Nop => 0,
            Opcode::PushConstInteger => 1,
            Opcode::PushConstFloat => 1,
            Opcode::PushConstBoolean => 1,
            Opcode::PushConstChar => 1,
            Opcode::Add => 1,
            Opcode::Subtract => 1,
            Opcode::IntegerMultiply => 1,
            Opcode::IntegerDivide => 1,
        }
    }
}

impl Opcodeable for u8 {
    fn as_opcode(self) -> Opcode {
        match self {
            0 => Opcode::Nop,
            1 => Opcode::PushConstInteger,
            2 => Opcode::PushConstFloat,
            3 => Opcode::PushConstBoolean,
            4 => Opcode::PushConstChar,
            5 => Opcode::Add,
            6 => Opcode::Subtract,
            7 => Opcode::IntegerMultiply,
            8 => Opcode::IntegerDivide,
            _ => {
                println!("Unknown opcode {:#x}", self);
                Opcode::Nop
            }
        }
    }
}
