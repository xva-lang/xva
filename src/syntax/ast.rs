pub(crate) mod ast_type;
pub(crate) mod expression;
pub(crate) mod literal;
mod node;
pub(crate) mod operator;
pub(crate) mod root;

use self::expression::Expression;
use self::operator::{InfixOperator, PrefixOperator};

#[derive(Debug)]
pub struct BinaryExpression {
    left: Box<Expression>,
    operator: InfixOperator,
    right: Box<Expression>,
}

impl BinaryExpression {
    pub(crate) fn new(
        left: Box<Expression>,
        operator: InfixOperator,
        right: Box<Expression>,
    ) -> Self {
        Self {
            left,
            operator,
            right,
        }
    }

    pub(crate) fn get_operator(&self) -> InfixOperator {
        self.operator.clone()
    }

    pub(crate) fn get_left(&self) -> &Expression {
        self.left.as_ref()
    }

    pub(crate) fn get_right(&self) -> &Expression {
        self.right.as_ref()
    }
}

impl std::fmt::Display for BinaryExpression {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "BinaryExpression({}, {}, {})",
            self.operator, self.left, self.right
        )
    }
}

#[derive(Debug)]
pub(crate) struct PrefixExpression {
    prefix: PrefixOperator,
    inner: Box<Expression>,
}

impl PrefixExpression {
    pub(crate) fn new(prefix: PrefixOperator, inner: Box<Expression>) -> Self {
        Self { prefix, inner }
    }

    pub(crate) fn get_prefix(&self) -> PrefixOperator {
        self.prefix.clone()
    }

    pub(crate) fn get_expression(&self) -> &Expression {
        self.inner.as_ref()
    }
}

impl std::fmt::Display for PrefixExpression {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Prefix({}, {})", self.prefix, self.inner)
    }
}



#[derive(Debug)]
pub(crate) struct ParenthesisedExpression {
    inner: Box<Expression>,
}

impl ParenthesisedExpression {
    pub fn new(expression: Box<Expression>) -> Self {
        Self { inner: expression }
    }

    pub fn get_inner_expression(&self) -> &Expression {
        self.inner.as_ref()
    }
}

impl std::fmt::Display for ParenthesisedExpression {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Parenthesised({})", self.inner)
    }
}
