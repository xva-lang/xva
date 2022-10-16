use super::builtins::{SignedIntType, UnsignedIntType};

impl Default for SignedIntType {
    fn default() -> Self {
        SignedIntType::Int32
    }
}

impl Default for UnsignedIntType {
    fn default() -> Self {
        UnsignedIntType::UInt32
    }
}
