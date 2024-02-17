use chumsky::{input::Emitter, prelude::*};
use xva_span::SourceSpan;
mod comment;
mod ident;
mod literals;
mod operators;
use crate::token::{Token, TokenKind};

use self::{comment::comment, ident::ident_or_keyword, literals::literal};

#[derive(Debug)]
pub(crate) enum ParseError {
    // Unicode(literals::UnicodeError),
}

fn rich_error<'a, T, S, M>(span: S, message: M) -> Rich<'a, T, S>
where
    M: ToString,
{
    Rich::custom(span, message)
}

pub(crate) fn emit_rich<'a, T, S, M>(emitter: &mut Emitter<Rich<'a, T, S>>, span: S, msg: M)
where
    M: ToString,
{
    emitter.emit(rich_error(span, msg))
}

pub(crate) type LexerError<'a> = extra::Err<Rich<'a, char, SimpleSpan<usize>>>;
//Vec<chumsky::extra::Full<chumsky::error::Rich<'src, _, _, &'static _>, (), ()>
pub(crate) type FullLexerError<'a> = chumsky::error::Rich<'a, char, SourceSpan>;

pub(crate) type LexerInput<'a> = &'a str;
pub(crate) type LexerOutput<'a> = (TokenKind<'a>, SourceSpan);
pub(crate) type LexerOutputStream<'a> = Vec<Token<'a>>;
// pub(crate) type LexerOutputStream<'a> = Vec<Token<'a>>;
pub(crate) fn lexer<'src>(
) -> impl Parser<'src, LexerInput<'src>, LexerOutputStream<'src>, LexerError<'src>> {
    let control = operators::control();
    let operator = operators::operator();
    let literal = literal();
    let comment = comment();
    let ident_or_keyword = ident_or_keyword();

    let error = any()
        .to_slice()
        .map(TokenKind::Error)
        .validate(|t, extra, emitter| {
            emitter.emit(Rich::custom(
                extra.span(),
                format!("Unexpected token: '{t}'"),
            ));
            t
        });

    let token_kind = choice((control, operator, literal, comment, ident_or_keyword, error));
    // let token = token_kind.padded().map_with(|kind, extra| Token {
    //     kind,
    //     span: extra.span(),
    //     original: extra.slice(),
    // });
    let token = token_kind.padded().map_with(|kind, extra| Token {
        kind,
        span: extra.span(),
        original: extra.slice(),
    });
    // .map_with(move |token, extra| (token, extra.span()));
    // .padded();

    token.repeated().collect()
}

pub fn lex<'src>(input: &'src str, debug: bool) -> (Vec<Token<'src>>, Vec<FullLexerError<'src>>) {
    let (tokens, errors) = lexer().parse(input).into_output_errors();

    // SAFETY: the lexer is infallible - it will always produce a vector, but it may be empty.
    let tokens = tokens.unwrap();

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
        let first = &tokens.unwrap_or_else(|| {
            panic!(
                r"Lexer test failed. Input did not produce tokens.
Input: {input}
Errors: {errors:#?}"
            )
        })[0];

        if result_has_errors || &first.kind != expected {
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
