use super::builtins::Type;
pub trait IsValueType {
    fn is_value_type(&self) -> bool;
}

impl IsValueType for Type {
    fn is_value_type(&self) -> bool {
        match self {
            Type::Integer(_) => true,
            Type::Float(_) => true,
            Type::Boolean(_) => true,
            Type::Char(_) => true,
            Type::Void => false,
        }
    }
}
