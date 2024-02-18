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

pub(crate) type LexerError = extra::Err<SyntaxError>;
//Vec<chumsky::extra::Full<chumsky::error::Rich<'src, _, _, &'static _>, (), ()>
pub(crate) type FullLexerError<'a> = chumsky::error::Rich<'a, char, SourceSpan>;

pub(crate) type LexerInput<'a> = &'a str;
pub(crate) type LexerOutput = (TokenKind, TokenSpan);
pub(crate) type LexerOutputStream = Vec<Token>;

// pub(crate) type LexerOutputStream<'a> = Vec<Token<'a>>;

pub(crate) fn lexer<'src>(// src_id: SourceId,
) -> impl Parser<'src, LexerInput<'src>, Vec<(TokenKind, TokenSpan, &'src str)>, LexerError> {
    let control = operators::control();
    let operator = operators::operator();
    let literal = literal();
    let comment = comment();
    let ident_or_keyword = ident_or_keyword();

    let error = any::<'src, &'src str, LexerError>()
        .to_slice()
        .map(|err| TokenKind::Error(Intern::new(err.into())));
    // .validate(|t, extra, emitter| {
    //     emitter.emit(Rich::custom(
    //         extra.span(),
    //         format!("Unexpected token: '{t}'"),
    //     ));
    //     t
    // });

    let token_kind = choice((control, operator, literal, comment, ident_or_keyword, error));
    // let token = token_kind.padded().map_with(|kind, extra| Token {
    //     kind,
    //     span: extra.span(),
    //     original: extra.slice(),
    // });
    // let token = token_kind.padded().map_with(move |kind, extra| Token {
    //     kind,
    //     span: {
    //         let TokenSpan { start, end, .. } = extra.span();
    //         SourceSpan::new(src_id, CheapRange::new(start, end))
    //     },
    //     original: extra.slice(),
    // });
    // .map_with(move |token, extra| (token, extra.span()));
    // .padded();
    // let token = ;
    token_kind
        .padded()
        .map_with(|kind, extra| (kind, extra.span(), extra.slice()))
        .repeated()
        .collect()
}

pub fn lex<'src>(
    input: &'src str,
    src_id: SourceId,
    debug: bool,
) -> (Vec<Token>, Vec<SyntaxError>) {
    // let (tokens, errors) = lexer(src_id).parse(input).into_output_errors();
    let (tokens, errors) = lexer().parse(input).into_output_errors();

    // SAFETY: the lexer is infallible, it will always a maybe-empty vector. This .unwrap() call is safe.
    let tokens = tokens
        .unwrap()
        .into_iter()
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
