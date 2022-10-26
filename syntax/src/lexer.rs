// pub(crate) warns on dead code, just pub does not

use logos::Logos;
use num_derive::{FromPrimitive, ToPrimitive};

#[derive(
    Debug, Copy, Clone, PartialEq, Logos, FromPrimitive, Ord, PartialOrd, Eq, ToPrimitive, Hash,
)]
pub(crate) enum SyntaxKind {
    #[regex(" +")]
    Whitespace,

    #[token("def")]
    DefKeyword,

    #[token("let")]
    LetKeyword,

    #[regex("[A-Za-z_][A-Za-z0-9_]+!?")]
    Identifier,

    #[token("+")]
    Plus,

    #[token("-")]
    Minus,

    #[token("*")]
    Star,

    #[token("/")]
    Slash,

    #[token("=")]
    Equals,

    #[regex("[0-9]+")]
    Number,

    #[error]
    Error,

    Root,
}

pub(crate) struct Lexer<'a> {
    inner: logos::Lexer<'a, SyntaxKind>,
}

impl<'a> Lexer<'a> {
    pub(crate) fn new(input: &'a str) -> Self {
        Self {
            inner: SyntaxKind::lexer(input),
        }
    }
}

impl<'a> Iterator for Lexer<'a> {
    type Item = (SyntaxKind, &'a str);

    fn next(&mut self) -> Option<Self::Item> {
        let kind = self.inner.next()?;
        let text = self.inner.slice();

        Some((kind, text))
    }
}

#[cfg(test)]
mod tests {
    use super::SyntaxKind;
    use crate::lexer::Lexer;

    fn check_lex(input: &str, kind: SyntaxKind) {
        let mut lexer = Lexer::new(input);
        assert_eq!(lexer.next(), Some((kind, input)));
    }

    #[test]
    fn lex_spaces() {
        check_lex("  ", SyntaxKind::Whitespace)
    }

    #[test]
    fn lex_def_keyword() {
        check_lex("def", SyntaxKind::DefKeyword);
    }

    #[test]
    fn lex_let_keyword() {
        check_lex("let", SyntaxKind::LetKeyword);
    }

    #[test]
    fn lex_basic_identifier() {
        check_lex("ident", SyntaxKind::Identifier);
    }

    #[test]
    fn lex_special_identifier() {
        check_lex("system_identifier!", SyntaxKind::Identifier);
    }

    #[test]
    fn lex_plus() {
        check_lex("+", SyntaxKind::Plus);
    }

    #[test]
    fn lex_minus() {
        check_lex("-", SyntaxKind::Minus);
    }

    #[test]
    fn lex_star() {
        check_lex("*", SyntaxKind::Star);
    }

    #[test]
    fn lex_slash() {
        check_lex("/", SyntaxKind::Slash);
    }

    #[test]
    fn lex_equals() {
        check_lex("=", SyntaxKind::Equals);
    }

    #[test]
    fn lex_number() {
        check_lex("03448952", SyntaxKind::Number);
    }
}
