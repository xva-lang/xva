#[derive(Debug, Clone, PartialEq)]
#[allow(dead_code)]
pub enum ValueType {
    Void,
    Integer(i64),
    Float(f64),
    Boolean(bool),
    // Char(char),
}

impl std::fmt::Display for ValueType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ValueType::Void => write!(f, "<void>"),
            ValueType::Integer(i) => write!(f, "{}", i),
            ValueType::Float(fl) => write!(f, "{}", fl),
            ValueType::Boolean(b) => {
                if *b {
                    write!(f, "true")
                } else {
                    write!(f, "false")
                }
            }
        }
    }
}
