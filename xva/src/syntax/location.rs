use super::lexer::span::Span;

#[derive(Copy, Clone)]
pub(crate) struct SyntaxLocation {
    line: usize,
    line_span: Span,
    absolute_span: Span,
}

impl SyntaxLocation {
    pub fn new(line: usize, line_span: Span, absolute_span: Span) -> Self {
        Self {
            line,
            line_span,
            absolute_span,
        }
    }

    pub fn get_line_span(&self) -> Span {
        self.line_span
    }

    pub fn get_absolute_span(&self) -> Span {
        self.absolute_span
    }

    pub fn get_line(&self) -> usize {
        self.line
    }
}

impl std::fmt::Debug for SyntaxLocation {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}:[{}..{}] @ {}..{}",
            self.line,
            self.line_span.start,
            self.line_span.end,
            self.absolute_span.start,
            self.absolute_span.end
        )
    }
}
