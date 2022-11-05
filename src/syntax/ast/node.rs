// use super::NodeVariant

use super::{expression::Expression, LiteralVariant};
use crate::syntax::lexer::span::Span;

#[derive(Debug)]
pub(crate) enum NodeVariant {
    Root {
        expressions: Option<Vec<Expression>>,
    },
    Literal(LiteralVariant),
    Error,
}

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
