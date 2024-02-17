use chumsky::{input::Stream, prelude::*};
use std::{
    ops::Range,
    sync::atomic::{AtomicI64, Ordering},
};

use xva_ast::{
    ast::{Expression, ExpressionKind, Item, ItemKind, LiteralKind, Module},
    node_id::{NodeId, ERROR_NODE_ID},
};
use xva_span::SourceSpan;

use crate::lexer::{lex, LexerOutputStream, Token, TokenKind};

pub(self) static NODE_ID_SEED: AtomicI64 = AtomicI64::new(0);
pub(self) fn next_node_id() -> NodeId {
    NODE_ID_SEED.fetch_add(1, Ordering::SeqCst).into()
}

pub(crate) type ParseInput<'tokens, 'src> = chumsky::input::SpannedInput<
    TokenKind<'src>,
    SourceSpan,
    &'tokens [(TokenKind<'src>, SourceSpan)],
>;

// pub(crate) type ParseInput<'tokens, 'src> = &'tokens [(TokenKind<'src>, )]

pub(crate) type ParseOutput = Item;
pub(crate) type ParseError<'tokens, 'src> = Rich<'tokens, TokenKind<'src>, SourceSpan>;
pub(crate) type ParseExtra<'tokens, 'src> = extra::Err<ParseError<'tokens, 'src>>;

// pub(crate) fn error<'tokens, 'src>(
// ) -> impl Parser<'tokens, ParseInput<'tokens, 'src>, Item, ParseExtra<'tokens, 'src>> + Clone
// where
//     'src: 'tokens,
// {
//     let str_err_token = chumsky::primitive::select(|token, _| match token {
//         TokenKind::Error(s) => Some(s.to_string()),
//         _ => None,
//     });
//     str_err_token.map_with(|err, extra| Item::error(extra.span(), err))
// }

pub fn parser<'tokens, 'src>(
) -> impl Parser<'tokens, ParseInput<'tokens, 'src>, Vec<Item>, ParseExtra<'tokens, 'src>>
where
    'src: 'tokens,
{
    let error_kind = chumsky::primitive::select(|token, _| {
        if let TokenKind::Error(s) = token {
            Some(s)
        } else {
            None
        }
    });

    let error = error_kind.map_with(|err, extra| Item::error(extra.span(), err.into()));

    let expr = choice((literals(), identifier())).or(error);

    expr.repeated().collect()
}

pub fn literals<'tokens, 'src>(
) -> impl Parser<'tokens, ParseInput<'tokens, 'src>, Item, ParseExtra<'tokens, 'src>>
where
    'src: 'tokens,
{
    let x = chumsky::primitive::select(move |token, extra| match token {
        TokenKind::Boolean(b) => Some((LiteralKind::Boolean(b), extra.span())),
        TokenKind::Char(c) => Some((LiteralKind::Char(c), extra.span())),
        TokenKind::Integer(i) => Some((LiteralKind::Integer(i), extra.span())),
        TokenKind::Float(f) => Some((LiteralKind::Float(f), extra.span())),
        _ => None,
    })
    .map(|(x, span)| Item {
        id: next_node_id(),
        kind: ItemKind::Expression(Expression {
            id: next_node_id(),
            kind: ExpressionKind::Literal(x),
            span,
        }),
        span,
    });
    x
}

pub fn identifier<'tokens, 'src>(
) -> impl Parser<'tokens, ParseInput<'tokens, 'src>, Item, ParseExtra<'tokens, 'src>>
where
    'src: 'tokens,
{
    chumsky::primitive::select(move |kind, extra| {
        if let TokenKind::Identifier(s) = kind {
            Some((s, extra.span()))
        } else {
            None
        }
    })
    .map(|(ident, span)| Item {
        id: next_node_id(),
        kind: ItemKind::Expression(Expression {
            id: next_node_id(),
            kind: ExpressionKind::Identifier(ident.into()),
            span,
        }),
        span,
    })
}

pub fn parse<'tokens, 'src>(input: &'src str, debug_lexer: bool) -> Vec<Item> {
    let (tokens, lex_errors) = lex(input, debug_lexer);
    let eoi = SourceSpan::new(0, input.bytes().len());
    let (tree, parse_errors) = parser()
        .parse(tokens.as_slice().spanned(eoi))
        .into_output_errors();
    #[cfg(debug_assertions)]
    {
        println!("tree: {tree:#?}");
    }
    if lex_errors.len() != 0 {
        for error in lex_errors {
            println!("error: {error}");
        }
    }

    if parse_errors.len() != 0 {
        for error in parse_errors {
            println!("error: {error}");
        }
    }

    // SAFETY: the parser is infallible - it will always produce a tree, even if the tree is empty.
    // (tree.unwrap(), errors)
    tree.unwrap()
}

#[cfg(test)]
mod tests {
    use chumsky::{input::Input, Parser};
    use xva_span::SourceSpan;

    use crate::{lexer::lex, parser::parser};

    #[test]
    fn tree() {
        let input = "keyword";

        let len = input.bytes().len();
        let eoi = SourceSpan::new(0, len);
        let (tokens, lex_errors) = lex(input, false);

        let (ast, parse_errs) = parser()
            .map_with(|ast, e| (ast, e.span()))
            .parse(tokens.as_slice().spanned((input.len()..input.len()).into()))
            .into_output_errors();

        println!("tree: {:#?}", ast);
    }
}
