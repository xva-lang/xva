use super::{language::TokenKind, lexeme::Lexeme, span::Span};
use logos::Lexer;

pub(crate) struct TokenStream<'text> {
    lexemes: Vec<Lexeme<'text>>,
    cursor: usize,
    original_length: usize,
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
                    line_offset += current_line_length + 1; // plus 1 for the newline
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

            lexemes.push(Lexeme::new(
                current_line,
                lexer.span().into(),
                line_span,
                lexer.slice(),
                variant,
            ))
        }

        Self {
            lexemes,
            cursor: 0,
            original_length: lexer.span().end,
        }
    }

    pub fn peek_variant(&self) -> Option<TokenKind> {
        match self.lexemes.get(self.cursor) {
            Some(l) => Some(l.get_variant()),
            None => None,
        }
    }

    #[allow(dead_code)]
    pub fn get_original_length(&self) -> usize {
        self.original_length
    }

    pub(crate) fn peek_next_variant(&self) -> Option<TokenKind> {
        match self.lexemes.get(self.cursor + 1) {
            Some(l) => Some(l.get_variant()),
            None => None,
        }
    }

    pub(crate) fn current_as_ref(&self) -> Option<&Lexeme<'_>> {
        self.lexemes.get(self.cursor)
    }

    pub(crate) fn previous_as_ref(&self) -> Option<&Lexeme<'_>> {
        self.lexemes.get(self.cursor - 1)
    }
}

impl<'text> std::fmt::Display for TokenStream<'text> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut result = String::new();
        for (index, token) in self.lexemes.iter().enumerate() {
            if index == self.lexemes.len() - 1 {
                result.push_str(format!("{}", token).as_str());
            } else {
                result.push_str(format!("{}", token).as_str());
            }
        }

        write!(f, "{}", result)
    }
}

impl<'text> Iterator for TokenStream<'text> {
    type Item = Lexeme<'text>;

    fn next(&mut self) -> Option<Self::Item> {
        let result: Option<Self::Item>;
        if self.cursor > self.lexemes.len() - 1 {
            result = None;
        } else {
            let ref_lexeme = self.lexemes.get(self.cursor);
            result = match ref_lexeme {
                Some(l) => Some(*l),
                None => None,
            };
        }

        self.cursor += 1;
        return result;
    }
}
