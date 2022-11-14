// use super::NodeVariant

use super::{expression::Expression, literal::LiteralVariant};
use crate::syntax::lexer::span::Span;

#[allow(dead_code)]
#[derive(Debug)]
pub(crate) enum NodeVariant {
    Root {
        expressions: Option<Vec<Expression>>,
    },
    Literal(LiteralVariant),
    Error,
}

#[allow(dead_code)]
#[derive(Debug)]
pub(crate) struct Node {
    pub(crate) variant: NodeVariant,
    line: usize,
    span: Span,
}

impl Node {
    #[allow(dead_code)]
    pub fn new(variant: NodeVariant, line: usize, span: Span) -> Self {
        Self {
            variant,
            line,
            span,
        }
    }
}
