use super::builtins::Type;
pub trait IsValueType {
    fn is_value_type(&self) -> bool;
}

impl IsValueType for Type {
    fn is_value_type(&self) -> bool {
        match self {
            Type::SignedInt(si) => true,
            Type::UnsignedInt(ui) => true,
            Type::Char(chr) => true,
        }
    }
}
