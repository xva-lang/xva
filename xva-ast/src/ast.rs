use crate::has_node_id;
use crate::node_id::NodeId;
use crate::traits::HasNodeId;

use std::ops::Range;

#[derive(Debug)]
pub struct Brick {
    pub items: Vec<Item>,
}

impl Brick {
    pub fn new_from_items(items: Vec<Item>) -> Self {
        Self { items }
    }
}

#[derive(Debug)]
pub struct Item {
    pub id: NodeId,
    pub kind: ItemKind,

    /// The item's start (inclusive) and end (exclusive) range, in byte offsets
    /// from the source text.
    pub range: Range<usize>,
}

#[derive(Debug)]
pub enum ItemKind {
    Expression(Expression),
    Module(Module),
}

#[derive(Debug)]
pub struct Module {
    pub items: Vec<Item>,
}

#[derive(Debug)]
pub struct Expression {
    pub id: NodeId,
    pub kind: ExpressionKind,
    pub span: Range<usize>,
}

#[derive(Debug)]
pub enum ExpressionKind {
    Literal(LiteralKind),
    Unary(UnaryOperator, Box<Expression>),
}

#[derive(Debug)]
pub enum LiteralKind {
    Integer(u128, LiteralIntegerKind),
    Boolean(bool),
    Char(char),
    Float(f64),
    String(String), // TODO PLEASE change this to interned strings bruh
}

#[derive(Debug)]
pub enum UnaryOperator {
    Negation,
}

#[derive(Debug)]
pub enum LiteralIntegerKind {
    Signed,
    Unsigned,
}

has_node_id!(Item, Expression);
