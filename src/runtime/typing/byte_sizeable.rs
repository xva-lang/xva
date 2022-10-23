use super::builtins::Type;

pub const BOOLEAN_SIZE: usize = 1;
pub const INT_SIZE: usize = 8;
pub const FLOAT_SIZE: usize = 8;
pub const PRECISE_SIZE: usize = 16;
pub const CHAR_SIZE: usize = 4;

pub trait ByteSizeable {
    fn size_of(&self) -> usize;
}

impl ByteSizeable for Type {
    fn size_of(&self) -> usize {
        match self {
            Type::Integer(_) => 8,
            Type::Float(_) => 4,
            Type::Boolean(_) => 1,
            Type::Char(_) => 4,
            Type::Void => 0,
        }
    }
}
