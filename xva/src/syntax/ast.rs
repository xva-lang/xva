use self::operator::{InfixOperator, PrefixOperator};

use super::lexer::span::Span;

pub(crate) mod operator;
#[derive(Debug)]
pub(crate) struct Node {
    pub(crate) variant: NodeVariant,
    line: usize,
    span: Span,
}

impl Node {
    pub fn new(variant: NodeVariant, line: usize, span: Span) -> Self {
        Self {
            variant,
            line,
            span,
        }
    }
}

pub(crate) struct Root {
    expressions: Vec<Expression>,
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
pub(crate) enum NodeVariant {
    Root {
        expressions: Option<Vec<Expression>>,
    },
    Literal(LiteralVariant),
    Error,
}

#[derive(Debug)]
pub(crate) struct Expression {
    pub(crate) variant: ExpressionVariant,
    line: usize,
    span: Span,
}

impl Expression {
    pub fn new(variant: ExpressionVariant, line: usize, span: Span) -> Self {
        Self {
            variant,
            line,
            span,
        }
    }

    pub fn get_span(&self) -> Span {
        self.span
    }

    pub fn get_line(&self) -> usize {
        self.line
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
}

impl std::fmt::Display for ExpressionVariant {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ExpressionVariant::Literal(l) => write!(f, "{}", l),
            ExpressionVariant::Binary(b) => write!(f, "{}", b),
            ExpressionVariant::Prefix(p) => write!(f, "{}", p),
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
