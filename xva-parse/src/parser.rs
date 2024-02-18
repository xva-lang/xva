use chumsky::prelude::*;

use std::sync::atomic::{AtomicI64, Ordering};

use xva_ast::{ast::Item, node_id::NodeId};
use xva_span::SourceId;
mod expr;

use crate::token::Token;
use crate::{
    error::{ErrorPattern, SyntaxErrorKind},
    lexer::lex,
};

use self::expr::literal;

pub(self) static NODE_ID_SEED: AtomicI64 = AtomicI64::new(0);
pub(self) fn next_node_id() -> NodeId {
    NODE_ID_SEED.fetch_add(1, Ordering::SeqCst).into()
}

pub fn parse<'src>(
    input: &'src str,
    src_id: SourceId,
    debug_lexer: bool,
) -> (Vec<SyntaxError<'src>>, Vec<Item>) {
    let (tokens, lex_errors) = lex(input, src_id, debug_lexer);

    let (tree, parse_errors) = parser().parse(tokens.as_slice()).into_output_errors();

    // SAFETY: the parser is infallible - it will always produce a tree, even if the tree is empty.
    // (tree.unwrap(), errors)
    // a.into_iter().chain(b.into_iter()).collect();
    (
        lex_errors
            .into_iter()
            .chain(parse_errors.into_iter())
            .collect(),
        tree.unwrap(),
    )
}

pub(crate) type ParseInput<'tok, 'src> = &'tok [Token<'src>];
pub(crate) type ParseError<'src> = SyntaxError<'src>;

use crate::error::SyntaxError;
pub(crate) type ParseExtra<'src> = extra::Err<ParseError<'src>>;

pub(crate) fn parser<'src>(
) -> impl Parser<'src, &'src [Token<'src>], Vec<Item>, extra::Err<SyntaxError<'src>>>
// where
    // 'src: 'tok,
{
    // any::<ParseInput<'tok, 'src>, ParseExtra<'tok, 'src>>()
    literal()
        .or(any().validate(|tok: Token<'_>, _extra, emitter| {
            emitter.emit(SyntaxError::new(
                SyntaxErrorKind::UnexpectedPattern(ErrorPattern::Token(tok.kind)),
                tok.span,
            ));

            Item::error(tok.span, tok.original.into())
        }))
        // .or(any().validate(|x: Token<'src>, _, emitter| {
        //     // emit_rich(emitter, x.span, format!("Unexpected: {x}"));
        //     emitter.emit(SyntaxError::new(
        //         SyntaxErrorKind::UnexpectedPattern(
        //             ErrorPattern::Token(x.kind), x.span
        //         )
        //     ))
        //     Item {
        //         id: next_node_id(),
        //         kind: ItemKind::Error(x.original.to_string()),
        //         span: x.span,
        //     }
        // }))
        .repeated()
        .collect()
}

#[cfg(test)]
mod tests {

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
