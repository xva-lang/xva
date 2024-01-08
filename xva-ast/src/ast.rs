use xva_span::SourceLocation;

use crate::has_node_id;
use crate::node_id::NodeId;
use crate::traits::HasNodeId;

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

    /// The item's location in the source text.
    /// - The offsets are zero-based.
    /// - The end line is **inclusive**, but,
    /// - The end column is **exclusive**
    ///
    /// This is because TreeSitter reports node spans as such.
    pub span: SourceLocation,
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
    pub span: SourceLocation,
}

#[derive(Debug)]
pub enum ExpressionKind {
    Literal(LiteralKind),
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
pub enum LiteralIntegerKind {
    Signed,
    Unsigned,
}

has_node_id!(Item, Expression);
