#[derive(Debug)]
pub enum PrefixOperator {
    Negate,
}

#[derive(Debug)]
pub enum BinaryOperator {
    Plus,
}

#[derive(Debug)]
pub enum Literal {
    Decimal(u128),
}

#[derive(Debug)]
pub struct BinaryExpression {
    left: Expression,
    operator: BinaryOperator,
    right: Expression,
}

impl BinaryExpression {
    pub(super) fn new(left: Expression, operator: BinaryOperator, right: Expression) -> Self {
        Self {
            left,
            operator,
            right,
        }
    }

    pub(super) fn new_boxed(
        left: Expression,
        operator: BinaryOperator,
        right: Expression,
    ) -> Box<Self> {
        Box::new(Self::new(left, operator, right))
    }
}

#[derive(Debug)]
pub enum ExpressionKind {
    Literal(Literal),
    Binary(Box<BinaryExpression>),
    Prefix(Box<PrefixExpression>),
}

#[derive(Debug)]
pub struct PrefixExpression {
    operator: PrefixOperator,
    expr: Box<Expression>,
}

impl PrefixExpression {
    pub(super) fn new(operator: PrefixOperator, expr: Box<Expression>) -> Self {
        Self { operator, expr }
    }

    pub(super) fn new_boxed(operator: PrefixOperator, expr: Box<Expression>) -> Box<Self> {
        Box::new(Self::new(operator, expr))
    }
}

#[derive(Debug)]
pub struct Expression {
    id: u32,
    kind: ExpressionKind,
}

impl Expression {
    pub(super) fn new(id: u32, kind: ExpressionKind) -> Self {
        Self { id, kind }
    }
}

#[derive(Debug)]
pub enum ItemKind {
    // Statement,
    Expression(Expression),
}
#[derive(Debug)]
pub struct Item {
    pub id: u32,
    pub kind: ItemKind,
}

impl Item {
    pub(super) fn kind(&self) -> &ItemKind {
        &self.kind
    }
}
