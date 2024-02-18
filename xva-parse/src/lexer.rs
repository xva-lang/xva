//! The lexer, tokenizer, lexical analyser: whatever you want to call it.
//!
//! The lexer is a parser combinator - it is a type of parser built from successively applying smaller parsers
//! in order to produce meaningful output.
//!
//! These smaller parsers, or parser combinators, are provided by [`chumsky`]. Chumsky is extremely heavy on
//! trait solving and type inference, but if you do things in the right way it will sort itself out.
//!
//! A typical Chumsky parsing function looks like the following:
//! ```no_run
//! fn parser<'a>() -> impl Parser<'a, Input, Output, Extra> {
//!     ...
//! }
//! ```
//!
//! A Chumsky parsing component requires 4 types: a lifetime, and an input, output and "extra" type. Typically, for
//! each of the lexing components defined in this module, these will be the following:
//! - Lifetime: `'src`, the lifetime of the input,
//! - Input: `&'src str`, a string slice that must live at least as long as the lexer (hence `'src``),
//! - Output: [`TokenKind`], a variant representing what kind of token the lexer has produced,
//! - Extra: [`SyntaxError`], wrapped in Chumsky's [`extra::Err`](chumsky::extra::Err). To avoid writing out
//! the whole thing, there is a type alias for the wrapped type: [`LexerError`]
//!
//! The ultimate output of this module are [`Token`]s - a structure containing a token variant, its span in context of
//! the file currently being processed, and the original text that the token was produced from.

use chumsky::prelude::*;
use internment::Intern;
use xva_span::{CheapRange, SourceId, SourceSpan, TokenSpan};

mod comment;
mod ident;
mod literals;
mod operators;

use crate::{
    error::SyntaxError,
    token::{Token, TokenKind},
};

use self::{comment::comment, ident::ident_or_keyword, literals::literal};

/// Convenience type to avoid writing out the wrapping type from Chumsky.
pub(crate) type LexerError = extra::Err<SyntaxError>;

pub(crate) fn lexer<'src>(
) -> impl Parser<'src, &'src str, Vec<(TokenKind, TokenSpan, &'src str)>, LexerError> {
    let control = operators::control();
    let operator = operators::operator();
    let literal = literal();
    let comment = comment();
    let ident_or_keyword = ident_or_keyword();

    let error = any::<'src, &'src str, LexerError>()
        .to_slice()
        .map(|err| TokenKind::Error(Intern::new(err.into())));

    let token_kind = choice((control, operator, literal, comment, ident_or_keyword, error));

    token_kind
        .padded()
        .map_with(|kind, extra| (kind, extra.span(), extra.slice()))
        .repeated()
        .collect()
}

/// Transforms the input into a series of [`Token`]s that may be analysed further.
///
/// # Arguments
/// `input` - The input, as a string slice.
///
/// `src_id` - The source file that the input came from.
///
/// `debug` - TODO remove this
///
/// # Returns
/// `Vec<Token>`, plus a `Vec` of any errors that occurred while processing the input.
pub fn lex<'src>(
    input: &'src str,
    src_id: SourceId,
    debug: bool,
) -> (Vec<Token>, Vec<SyntaxError>) {
    let (tokens, errors) = lexer().parse(input).into_output_errors();

    // SAFETY: the lexer is infallible, it will always a maybe-empty vector. This .unwrap() call is safe.
    let tokens = tokens
        .unwrap()
        .into_iter()
        // The lex() function returns a vector of 3-tuples: token kind, basic span, and the original text.
        // Map these  into a complete structure, and add context of the source id to the span
        // (i.e. TokenSpan to SourceSpan)
        .map(|(kind, span, original)| Token {
            kind,
            span: {
                let TokenSpan { start, end, .. } = span;
                SourceSpan::new(src_id, CheapRange::new(start, end))
            },
            original: Intern::new(original.into()),
        })
        .collect();

    if debug {
        println!("tokens: {tokens:#?}");
    }

    (tokens, errors)
}

#[cfg(test)]
pub(crate) mod tests {
    use chumsky::Parser;

    use super::{lexer, TokenKind};

    pub(crate) fn assert_single_no_errors(input: &str, expected: &TokenKind) {
        let result = lexer().parse(input);
        let result_has_errors = result.has_errors();
        let (tokens, errors) = result.into_output_errors();
        let (first, _, _) = &tokens.unwrap_or_else(|| {
            panic!(
                r"Lexer test failed. Input did not produce tokens.
Input: {input}
Errors: {errors:#?}"
            )
        })[0];

        if result_has_errors || first != expected {
            panic!(
                r"Lexer test failed.
Input: {input}
Parsed as: {first:#?}
Expected: {expected:#?}
Errors: {errors:#?}"
            );
        }
    }
}
