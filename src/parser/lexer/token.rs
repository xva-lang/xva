#[derive(Debug, Clone, PartialEq)]
pub enum TokenKind {
    Integer(i64),
    Add,
    Subtract,
}
