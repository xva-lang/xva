use super::builtins::ValueType;

// pub const BOOLEAN_SIZE: usize = 1;
// pub const INT_SIZE: usize = 8;
// pub const FLOAT_SIZE: usize = 8;
// //pub const PRECISE_SIZE: usize = 16;
// pub const CHAR_SIZE: usize = 4;

pub trait ByteSizeable {
    fn size_of(&self) -> usize;
}

impl ByteSizeable for ValueType {
    fn size_of(&self) -> usize {
        match self {
            ValueType::Integer(_) => 8,
            ValueType::Float(_) => 8,
            ValueType::Boolean(_) => 8,
            // ValueType::Char(_) => 4,
            ValueType::Void => 0,
        }
    }
}
