use super::{
    assignment::Assignment,
    ast_type::ASTType,
    declaration::Declaration,
    identifier::IdentifierExpression,
    literal::LiteralVariant,
    operator::{InfixOperator, PrefixOperator},
};
use crate::syntax::{lexer::span::Span, location::SyntaxLocation};

#[derive(Debug)]
pub(crate) struct Expression {
    pub(crate) variant: ExpressionVariant,
    ast_type: ASTType,
    location: SyntaxLocation,
}

impl Expression {
    pub fn new(variant: ExpressionVariant, location: SyntaxLocation) -> Self {
        Self {
            variant,
            location,
            ast_type: ASTType::Void,
        }
    }

    pub fn get_line_span(&self) -> Span {
        self.location.get_line_span()
    }

    pub fn get_absolute_span(&self) -> Span {
        self.location.get_absolute_span()
    }

    pub fn get_line(&self) -> usize {
        self.location.get_line()
    }

    pub fn get_location(&self) -> SyntaxLocation {
        self.location
    }

    #[allow(dead_code)]
    pub fn get_type(&self) -> &ASTType {
        &self.ast_type
    }

    pub fn set_type(&mut self, ast_type: ASTType) {
        self.ast_type = ast_type;
    }
}

impl std::fmt::Display for Expression {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.variant)
    }
}

#[derive(Debug)]
pub(crate) enum ExpressionVariant {
    Literal(LiteralVariant),
    Binary(BinaryExpression),
    Prefix(PrefixExpression),
    Parenthesised(ParenthesisedExpression),
    Declaration(Declaration),
    Identifier(IdentifierExpression),
    Assignment(Assignment),
}

impl std::fmt::Display for ExpressionVariant {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ExpressionVariant::Literal(l) => write!(f, "{}", l),
            ExpressionVariant::Binary(b) => write!(f, "{}", b),
            ExpressionVariant::Prefix(p) => write!(f, "{}", p),
            ExpressionVariant::Parenthesised(p) => write!(f, "{}", p),
            ExpressionVariant::Declaration(d) => write!(f, "{}", d),
            ExpressionVariant::Identifier(i) => write!(f, "{}", i),
            ExpressionVariant::Assignment(a) => write!(f, "{}", a),
        }
    }
}

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

    #[allow(dead_code)]
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
