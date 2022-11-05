use super::{
    ast_type::ASTType, BinaryExpression, LiteralVariant, ParenthesisedExpression, PrefixExpression,
};
use crate::syntax::lexer::span::Span;

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
