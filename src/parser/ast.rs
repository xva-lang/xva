use crate::runtime::typing::builtins::Type;
use queues::{Buffer, Queue};

#[allow(dead_code)]
#[derive(Clone)]
pub enum NodeVariant {
    Module {
        name: String,
    },
    Declaration {
        identifier: String,
        type_annotation: Option<Type>,
        assignment: Option<Expression>,
        is_mutable: bool,
    },
    Statement,
}

#[derive(Clone)]
pub enum Expression {
    Void,
    Constant(Type),
}

#[derive(Clone)]
pub struct Node {
    pub variant: NodeVariant,
    pub children: Vec<Node>,
}

#[derive(Clone)]
pub struct Module {
    pub name: String,
}

pub struct Declaration {
    pub identifier: String,
    pub type_annotation: Option<Type>,
    pub assignment: Option<Expression>,
}

pub struct Tree {
    pub nodes: Vec<Node>,
}
