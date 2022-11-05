use std::ops::Range;

use logos::{Lexer, Logos};
use num_derive::{FromPrimitive, ToPrimitive};
use num_traits::{FromPrimitive, ToPrimitive};

#[derive(
    Debug, Copy, Clone, PartialEq, Logos, FromPrimitive, Ord, PartialOrd, Eq, ToPrimitive, Hash,
)]
pub enum TokenKind {
    #[regex("[ \t]+")]
    Whitespace,

    #[regex("\n+")]
    Newline,

    #[token("def")]
    DefKeyword,

    #[token("let")]
    LetKeyword,

    #[regex("[A-Za-z_][A-Za-z0-9_]*!?")]
    Identifier,

    Operator,

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

    #[token("(")]
    LeftParenthesis,

    #[token(")")]
    RightParenthesis,

    #[token(":")]
    Colon,

    Literal,

    #[regex("[0-9]+")]
    IntegerLiteral,

    #[token("true")]
    TrueLiteral,

    #[token("false")]
    FalseLiteral,

    #[regex("//.*")]
    Comment,

    IdentifierExpression,
    BinaryExpression,
    PrefixExpression,
    ParenthesisedExpression,
    Declaration,

    #[error]
    Error,

    Root,
}

pub struct TokenStream<'text> {
    lexemes: Vec<Lexeme<'text>>,
    cursor: usize,
}

impl<'text> TokenStream<'text> {
    pub fn new(lexer: &mut Lexer<'text, TokenKind>) -> Self {
        let mut lexemes: Vec<Lexeme> = vec![];
        let mut current_line: usize = 1;
        let mut current_line_length: usize = 0;
        let mut line_offset: usize = 0;

        while let Some(variant) = lexer.next() {
            match variant {
                TokenKind::Newline => {
                    current_line += 1;
                    line_offset += (current_line_length + 1); // plus 1 for the newline
                    current_line_length = 0;
                    continue;
                }
                t => {
                    current_line_length += lexer.slice().len();
                    if t == TokenKind::Whitespace {
                        continue;
                    }
                }
            }

            let lexer_span = lexer.span();

            let line_span: Span =
                ((lexer_span.start - line_offset)..(lexer_span.end - line_offset)).into();

            lexemes.push(Lexeme {
                variant,
                line: current_line,
                absolute_span: lexer.span().into(),
                line_span,
                text: lexer.slice(),
            })
        }

        Self { lexemes, cursor: 0 }
    }

    pub fn print(&self) {
        println!("{:#?}", self.lexemes);
    }
}

impl<'text> Iterator for TokenStream<'text> {
    type Item = Lexeme<'text>;

    fn next(&mut self) -> Option<Self::Item> {
        self.cursor += 1;
        if self.cursor > self.lexemes.len() - 1 {
            None
        } else {
            let ref_lexeme = self.lexemes.get(self.cursor);
            match ref_lexeme {
                Some(l) => Some(Lexeme {
                    line: l.line,
                    absolute_span: l.absolute_span.clone(),
                    line_span: l.line_span.clone(),
                    text: l.text.clone(),
                    variant: l.variant,
                }),
                None => None,
            }
        }
    }
}

#[derive(Debug, Clone)]
pub struct Lexeme<'text> {
    line: usize,
    absolute_span: Span,
    line_span: Span,
    text: &'text str,
    variant: TokenKind,
}

impl<'text> std::fmt::Display for Lexeme<'text> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{:?}@[{}:{}] \"{}\"",
            self.variant, self.line, self.line_span, self.text
        )
    }
}

#[derive(Debug, Copy, Clone)]
pub struct Span {
    start: usize,
    end: usize,
}

impl From<Range<usize>> for Span {
    fn from(v: Range<usize>) -> Self {
        Self {
            start: v.start,
            end: v.end,
        }
    }
}

impl From<Span> for Range<usize> {
    fn from(v: Span) -> Self {
        Self {
            start: v.start,
            end: v.end,
        }
    }
}

impl std::fmt::Display for Span {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}..{}", self.start, self.end)
    }
}

#[cfg(test)]
mod tests {
    use logos::Logos;

    use super::{TokenKind, TokenStream};

    #[test]
    fn lex() {
        let mut lexer = TokenKind::lexer(
            r#"let number = 123
let another_number = 246"#,
        );
        let token_stream = TokenStream::new(&mut lexer);
        for token in token_stream {
            println!("{}", token);
        }
    }
}
