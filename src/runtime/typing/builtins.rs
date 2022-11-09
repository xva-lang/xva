#[derive(Debug, Clone, PartialEq)]
#[allow(dead_code)]
pub enum ValueType {
    Void,
    Integer(i64),
    Float(f64),
    Boolean(bool),
    // Char(char),
}
