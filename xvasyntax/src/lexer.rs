use std::ops::Range;

use crate::language::SyntaxKind;
use logos::Logos;

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
    type Item = Lexeme<'a>;

    fn next(&mut self) -> Option<Self::Item> {
        let kind = self.inner.next()?;
        let span = self.inner.span();
        let text = self.inner.slice();

        Some(Lexeme {
            kind: kind,
            text: text,
            span: span,
        })
    }
}

#[derive(Debug, Clone, PartialEq)]
pub(crate) struct Lexeme<'a> {
    pub(crate) kind: SyntaxKind,
    pub(crate) text: &'a str,
    pub(crate) span: Range<usize>,
}

#[derive(Debug)]
pub(super) struct LexemeSource<'lexemes, 'input> {
    lexemes: &'lexemes [Lexeme<'input>],
    cursor: usize,
}

impl<'a> Lexeme<'a> {
    #[allow(dead_code)]
    pub(crate) fn new(kind: SyntaxKind, text: &'a str) -> Self {
        Self {
            kind,
            text,
            span: 0..0,
        }
    }
}

impl<'lexemes, 'input> LexemeSource<'lexemes, 'input> {
    pub(super) fn new(lexemes: &'lexemes [Lexeme<'input>]) -> Self {
        Self { lexemes, cursor: 0 }
    }

    pub(super) fn next_lexeme(&mut self) -> Option<&'lexemes Lexeme<'input>> {
        self.consume_trivia();
        let lexeme = self.lexemes.get(self.cursor)?;
        self.cursor += 1;
        Some(lexeme)
    }

    pub(super) fn consume(&mut self) {
        self.cursor += 1;
    }

    pub(super) fn peek_current_as_deref(&self) -> Option<Lexeme> {
        let result = match self.lexemes.get(self.cursor) {
            Some(r) => {
                let cloned = r.clone();
                Some(cloned)
            }
            None => None,
        };

        result
    }

    pub(super) fn peek_previous_as_deref(&self) -> Option<Lexeme> {
        let result = match self.lexemes.get(self.cursor - 1) {
            Some(r) => {
                let cloned = r.clone();
                Some(cloned)
            }
            None => None,
        };

        result
    }

    pub(super) fn peek_kind(&mut self) -> Option<SyntaxKind> {
        self.consume_trivia();
        self.peek_kind_raw()
    }

    fn consume_trivia(&mut self) {
        while self.current_token_is_trivia() {
            self.cursor += 1;
        }
    }

    fn current_token_is_trivia(&mut self) -> bool {
        self.peek_kind_raw().map_or(false, |t| t.is_trivia())
    }

    fn peek_kind_raw(&mut self) -> Option<SyntaxKind> {
        self.lexemes.get(self.cursor).map(|lexeme| lexeme.kind)
    }
}

#[cfg(test)]
mod tests {
    use super::SyntaxKind;
    use crate::lexer::{Lexeme, Lexer};

    fn check_lex(input: &str, kind: SyntaxKind) {
        let mut lexer = Lexer::new(input);
        assert_eq!(
            lexer.next(),
            Some(Lexeme {
                kind,
                text: input,
                span: 0..input.len()
            })
        );
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
    fn lex_single_character_identifier() {
        check_lex("i", SyntaxKind::Identifier);
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
    fn lex_integer_literal() {
        check_lex("03448952", SyntaxKind::IntegerLiteral);
    }

    #[test]
    fn lex_left_parenthesis() {
        check_lex("(", SyntaxKind::LeftParenthesis);
    }

    #[test]
    fn lex_right_parenthesis() {
        check_lex(")", SyntaxKind::RightParenthesis);
    }

    #[test]
    fn lex_comment() {
        check_lex("// comment", SyntaxKind::Comment);
    }

    #[test]
    fn lex_colon() {
        check_lex(":", SyntaxKind::Colon);
    }

    #[test]
    fn lex_true() {
        check_lex("true", SyntaxKind::TrueLiteral);
    }

    #[test]
    fn lex_false() {
        check_lex("false", SyntaxKind::FalseLiteral)
    }
}
