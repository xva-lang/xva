use super::builtins::ValueType;
pub trait IsValueType {
    fn is_value_type(&self) -> bool;
}

impl IsValueType for ValueType {
    fn is_value_type(&self) -> bool {
        match self {
            ValueType::Integer(_) | ValueType::Boolean(_) | ValueType::Float(_) => true,
            // Type::Float(_) => true,
            // Type::Boolean(_) => true,
            // Type::Char(_) => true,
            ValueType::Void => false,
        }
    }
}
