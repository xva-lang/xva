use std::ops::{Deref, DerefMut};

#[derive(Debug, Clone, PartialEq)]

pub enum ASTType {
    Primitive(ASTPrimitiveType),
    Function(Box<ASTType>, Vec<ASTType>)
}

#[derive(Debug, Clone, PartialEq)]
pub enum ASTPrimitiveType {
    Void,
    Boolean,
    Integer,
    Float,
}
