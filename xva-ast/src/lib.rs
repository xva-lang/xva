mod traits;

#[derive(Debug, Clone, Copy)]
pub struct NodeId(u32);

impl PartialEq for NodeId {
    fn eq(&self, other: &Self) -> bool {
        // self.0 == other.0
        let Self(this) = self;
        let Self(other) = other;
        this == other
    }
}

impl Eq for NodeId {}

pub struct Brick {
    items: Vec<Item>,
}

pub struct Item {
    id: NodeId,
    kind: ItemKind,
}

pub enum ItemKind {
    Expression(Expression),
}

pub struct Expression {
    id: NodeId,
    kind: ExpressionKind,
}

pub enum ExpressionKind {
    Literal,
}

pub enum LiteralKind {
    Integer(u128, LiteralIntegerKind),
    Boolean(bool),
    Char(char),
    Float(f64),
    String(String), // TODO PLEASE change this to interned strings bruh
}

pub enum LiteralIntegerKind {
    Signed,
    Unsigned,
}
