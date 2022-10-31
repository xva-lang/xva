#[derive(Debug, Clone, PartialEq)]
pub enum ASTType {
    Void,
    Integer,
    Set(Box<Vec<ASTType>>),
    Function(Box<Vec<ASTType>>, Box<ASTType>),
}
