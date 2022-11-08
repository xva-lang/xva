use std::ops::{Deref, DerefMut};

#[derive(Debug, Clone, PartialEq)]
pub enum ASTType {
    Void,
    Integer,
    Boolean,
    Float,

    #[allow(dead_code)]
    Set(Box<Vec<ASTType>>),

    Function(Box<Vec<ASTType>>, Box<ASTType>),
}

impl Deref for ASTType {
    type Target = ASTType;

    fn deref(&self) -> &Self::Target {
        self
    }
}

impl DerefMut for ASTType {
    fn deref_mut(&mut self) -> &mut Self::Target {
        self
    }
}
