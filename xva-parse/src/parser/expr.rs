use chumsky::{prelude::*, primitive::select};
use xva_ast::ast::{Expression, ExpressionKind, Item, ItemKind, LiteralKind};

use super::{next_node_id, ParseExtra, ParseInput};
use crate::{
    error::SyntaxError,
    token::{Token, TokenKind},
};

pub(crate) fn literal<'src>(
) -> impl Parser<'src, &'src [Token<'src>], Item, extra::Err<SyntaxError<'src>>>
// where
//     'src: 'tok,
{
    select(move |token: Token<'_>, _| match token.kind {
        TokenKind::Boolean(b) => Some((LiteralKind::Boolean(b), token.span)),
        TokenKind::Char(c) => Some((LiteralKind::Char(c), token.span)),
        TokenKind::Integer(i) => Some((LiteralKind::Integer(i), token.span)),
        TokenKind::Float(f) => Some((LiteralKind::Float(f), token.span)),
        _ => None,
    })
    .map(|(lit, span)| Item {
        id: next_node_id(),
        kind: ItemKind::Expression(Expression {
            id: next_node_id(),
            kind: ExpressionKind::Literal(lit),
            span,
        }),
        span,
    })
}
