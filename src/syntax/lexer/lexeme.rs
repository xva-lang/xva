use super::{language::TokenKind, span::Span};

#[derive(Debug, Clone, Copy)]
pub struct Lexeme<'text> {
    line: usize,
    _absolute_span: Span,
    line_span: Span,
    text: &'text str,
    variant: TokenKind,
}

impl<'text> Lexeme<'text> {
    pub fn new(
        line: usize,
        absolute_span: Span,
        line_span: Span,
        text: &'text str,
        variant: TokenKind,
    ) -> Self {
        Self {
            line,
            _absolute_span: absolute_span,
            line_span,
            text,
            variant,
        }
    }

    pub(crate) fn get_variant(&self) -> TokenKind {
        self.variant
    }

    pub(crate) fn get_text(&self) -> &str {
        self.text
    }

    pub(crate) fn get_line(&self) -> usize {
        self.line
    }

    pub(crate) fn get_line_span(&self) -> Span {
        self.line_span
    }
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
