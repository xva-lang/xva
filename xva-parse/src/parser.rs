use chumsky::{extra::ParserExtra, prelude::*};
use std::sync::atomic::{AtomicI64, Ordering};

use xva_ast::{
    ast::{Expression, ExpressionKind, Item, ItemKind, LiteralKind},
    node_id::NodeId,
};
use xva_span::SourceSpan;
mod expr;

use crate::lexer::{emit_rich, lex};
use crate::token::{Token, TokenKind};

use self::expr::literal;

pub(self) static NODE_ID_SEED: AtomicI64 = AtomicI64::new(0);
pub(self) fn next_node_id() -> NodeId {
    NODE_ID_SEED.fetch_add(1, Ordering::SeqCst).into()
}

pub fn parse<'tok, 'src>(input: &'src str, debug_lexer: bool) -> Vec<Item> {
    let (tokens, lex_errors) = lex(input, debug_lexer);
    let eoi = SourceSpan::new(0, input.bytes().len());
    let (tree, parse_errors) = parser().parse(tokens.as_slice()).into_output_errors();

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

pub(crate) type ParseInput<'tok, 'src> = &'tok [Token<'src>];
pub(crate) type ParseError<'tok, 'src> = Rich<'tok, Token<'src>, SourceSpan>;
pub(crate) type ParseExtra<'tok, 'src> = extra::Err<ParseError<'tok, 'src>>;

pub(crate) fn parser<'tok, 'src>(
) -> impl Parser<'tok, ParseInput<'tok, 'src>, Vec<Item>, ParseExtra<'tok, 'src>>
where
    'src: 'tok,
{
    // any::<ParseInput<'tok, 'src>, ParseExtra<'tok, 'src>>()
    literal()
        .or(any().validate(|x: Token<'src>, _, emitter| {
            emit_rich(emitter, x.span, format!("Unexpected: {x}"));
            Item {
                id: next_node_id(),
                kind: ItemKind::Error(x.original.to_string()),
                span: x.span,
            }
        }))
        .repeated()
        .collect()
}

#[cfg(test)]
mod tests {
    use chumsky::{input::Input, Parser};
    use xva_span::SourceSpan;

    // use crate::{lexer::lex, parser::parser};

    // #[test]
    // fn tree() {
    //     let input = "keyword";

    //     let len = input.bytes().len();
    //     let eoi = SourceSpan::new(0, len);
    //     let (tokens, lex_errors) = lex(input, false);

    //     let (ast, parse_errs) = parser()
    //         .map_with(|ast, e| (ast, e.span()))
    //         .parse(tokens.as_slice().spanned((input.len()..input.len()).into()))
    //         .into_output_errors();

    //     println!("tree: {:#?}", ast);
    // }
}
