mod node;

use self::operator::{InfixOperator, PrefixOperator};
use super::lexer::span::Span;

pub(crate) mod operator;


pub(crate) struct Root {
    pub(crate) expressions: Vec<Expression>,
}

impl Root {
    pub(crate) fn new(expressions: Vec<Expression>) -> Self {
        Self { expressions }
    }
}

impl std::fmt::Display for Root {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut sb = String::new();
        for expression in self.expressions.iter() {
            sb.push_str(format!("{}", expression).as_str())
        }

        write!(f, "{}", sb)
    }
}



#[derive(Debug)]
pub(crate) struct Expression {
    pub(crate) variant: ExpressionVariant,
    ast_type: ASTType,
    line: usize,
    span: Span,
}

impl Expression {
    pub fn new(variant: ExpressionVariant, line: usize, span: Span) -> Self {
        Self {
            variant,
            line,
            span,
            ast_type: ASTType::Void,
        }
    }

    pub fn get_span(&self) -> Span {
        self.span
    }

    pub fn get_line(&self) -> usize {
        self.line
    }

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
}

impl std::fmt::Display for ExpressionVariant {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ExpressionVariant::Literal(l) => write!(f, "{}", l),
            ExpressionVariant::Binary(b) => write!(f, "{}", b),
            ExpressionVariant::Prefix(p) => write!(f, "{}", p),
            ExpressionVariant::Parenthesised(p) => write!(f, "{}", p),
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
pub(crate) enum LiteralVariant {
    Boolean(bool),
    Integer(i64),
}

impl std::fmt::Display for LiteralVariant {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut str_value = String::new();

        match self {
            LiteralVariant::Boolean(b) => {
                if *b {
                    str_value.push_str("Boolean(true)")
                } else {
                    str_value.push_str("Boolean(false)")
                }
            }
            LiteralVariant::Integer(i) => {
                str_value.push_str(format!("Integer({})", i).as_str());
            }
        }

        write!(f, "{}", str_value)
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

use std::ops::{Deref, DerefMut};

#[derive(Debug, Clone, PartialEq)]
pub enum ASTType {
    Void,
    Integer,
    Boolean,
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
