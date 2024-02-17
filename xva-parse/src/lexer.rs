use chumsky::{input::Emitter, prelude::*};
use xva_span::SourceSpan;
mod comment;
mod ident;
mod literals;
mod operators;

use self::{comment::comment, ident::ident_or_keyword, literals::literal};

// pub struct Token<'src> {
//     /// The token type
//     kind: TokenKind<'src>,

//     /// The original text of the token, including surrounding whitespace.
//     ///
//     /// Whitespace is included here to assist with recreating the original text, for auto-formatting, IDEs, etc.
//     original: &'src str,
// }

/// A single token produced by the lexer.
///
/// Contains a [`TokenKind`] as the variant, a [`SourceSpan`] indicating its span in the input text,
/// and a reference to the original text, with full-fidelity.
#[derive(Debug, Clone, PartialEq)]
pub struct Token<'src> {
    kind: TokenKind<'src>,
    span: SourceSpan,
    original: &'src str,
}

#[allow(dead_code)]
#[derive(Clone, Debug, PartialEq)]
pub enum TokenKind<'src> {
    // Literals
    Boolean(bool),
    Char(char),
    String(&'src str),
    Integer(i128),
    Float(f64),

    // Comments
    Comment(&'src str),
    DocComment(&'src str),

    // Symbols
    OpenParen,
    CloseParen,
    OpenBrace,
    CloseBrace,
    Colon,
    Comma,
    DoubleQuote,
    SingleQuote,
    Plus,
    Minus,
    Star,
    Slash,
    Percent,
    DoubleStar,
    Equals,
    LeftAngle,
    RightAngle,
    Increment,
    Decrement,
    Dot,
    Ampersand,
    Pipe,
    Caret,
    DoubleRightAngle,
    DoubleLeftAngle,
    GreaterThanEquals,
    LessThanEquals,
    DoubleEquals,
    NotEquals,
    And,
    Or,
    Not,

    /// Identifier
    Identifier(&'src str),

    /// Error token.
    ///
    /// Only contains a single character, error tokens should be collected at a later stage.
    CharError(char),

    /// Error token
    ///
    /// Contains multiple characters.
    Error(&'src str),
}

impl<'src> std::fmt::Display for TokenKind<'src> {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            TokenKind::Boolean(b) => write!(f, "'{b}'"),
            TokenKind::Char(c) => write!(f, "'{c}'"),
            TokenKind::String(s) => write!(f, "'{s}'"),
            TokenKind::Integer(i) => write!(f, "'{i}'"),
            TokenKind::Float(fl) => write!(f, "'{fl}'"),
            TokenKind::Comment(co) => write!(f, "'{co}'"),
            TokenKind::DocComment(dco) => write!(f, "'{dco}'"),
            TokenKind::OpenParen => write!(f, "'('"),
            TokenKind::CloseParen => write!(f, "')'"),
            TokenKind::OpenBrace => write!(f, "'{{'"),
            TokenKind::CloseBrace => write!(f, "'}}'"),
            TokenKind::Colon => write!(f, "':'"),
            TokenKind::Comma => write!(f, "','"),
            TokenKind::DoubleQuote => write!(f, "'\"'"),
            TokenKind::SingleQuote => write!(f, "'\''"),
            TokenKind::Plus => write!(f, "'+'"),
            TokenKind::Minus => write!(f, "'-'"),
            TokenKind::Star => write!(f, "'*'"),
            TokenKind::Slash => write!(f, "'/'"),
            TokenKind::Percent => write!(f, "'%'"),
            TokenKind::DoubleStar => write!(f, "'**'"),
            TokenKind::Equals => write!(f, "'='"),
            TokenKind::LeftAngle => write!(f, "'<'"),
            TokenKind::RightAngle => write!(f, "'>'"),
            TokenKind::Increment => write!(f, "'++'"),
            TokenKind::Decrement => write!(f, "'--'"),
            TokenKind::Dot => write!(f, "'.'"),
            TokenKind::Ampersand => write!(f, "'&'"),
            TokenKind::Pipe => write!(f, "'|'"),
            TokenKind::Caret => write!(f, "'^'"),
            TokenKind::DoubleRightAngle => write!(f, "'>>'"),
            TokenKind::DoubleLeftAngle => write!(f, "'<<'"),
            TokenKind::GreaterThanEquals => write!(f, "'>='"),
            TokenKind::LessThanEquals => write!(f, "'<='"),
            TokenKind::DoubleEquals => write!(f, "'=='"),
            TokenKind::NotEquals => write!(f, "'!='"),
            TokenKind::And => write!(f, "'and'"),
            TokenKind::Or => write!(f, "'or'"),
            TokenKind::Not => write!(f, "'not'"),

            TokenKind::Identifier(i) => write!(f, "'{i}"),
            TokenKind::CharError(err) => write!(f, "'{err}'"),
            TokenKind::Error(err) => write!(f, "'{err}'"),
        }
    }
}

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
pub(crate) type LexerOutputStream<'a> = Vec<(TokenKind<'a>, SourceSpan)>;

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

    let token = choice((control, operator, literal, comment, ident_or_keyword, error))
        .map_with(move |token, extra| (token, extra.span()))
        .padded();

    token.padded().repeated().collect()
}

pub fn lex<'src>(
    input: &'src str,
    debug: bool,
) -> (
    Vec<(TokenKind<'src>, SourceSpan)>,
    Vec<FullLexerError<'src>>,
) {
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
        let (first, _) = &tokens.unwrap_or_else(|| {
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
