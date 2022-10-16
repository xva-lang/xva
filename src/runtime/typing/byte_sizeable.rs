use super::builtins::{SignedIntType, Type, UnsignedIntType};

pub const BYTE_SIZE: usize = 1;
pub const SHORT_SIZE: usize = 2;
pub const INT_SIZE: usize = 4;
pub const LONG_SIZE: usize = 8;
pub const CHAR_SIZE: usize = INT_SIZE;

pub trait ByteSizeable {
    fn size_of(&self) -> usize;
}

impl ByteSizeable for Type {
    fn size_of(&self) -> usize {
        match self {
            Type::SignedInt(si) => si.size_of(),
            Type::UnsignedInt(ui) => ui.size_of(),
            Type::Char(_) => 4,
        }
    }
}

impl ByteSizeable for SignedIntType {
    fn size_of(&self) -> usize {
        match self {
            SignedIntType::Int8 => BYTE_SIZE,
            SignedIntType::Int16 => SHORT_SIZE,
            SignedIntType::Int32 => INT_SIZE,
            SignedIntType::Int64 => LONG_SIZE,
        }
    }
}

impl ByteSizeable for UnsignedIntType {
    fn size_of(&self) -> usize {
        match self {
            UnsignedIntType::UInt8 => BYTE_SIZE,
            UnsignedIntType::UInt16 => SHORT_SIZE,
            UnsignedIntType::UInt32 => INT_SIZE,
            UnsignedIntType::UInt64 => LONG_SIZE,
        }
    }
}
