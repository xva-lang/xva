use crate::syntax::location::SyntaxLocation;

pub(crate) struct CompilerError {
    location: SyntaxLocation,
    message: String,
    suggestion: Option<String>,
}

impl CompilerError {
    pub fn new(location: SyntaxLocation, message: &str, suggestion: Option<&str>) -> Self {
        Self {
            location,
            message: String::from(message),
            suggestion: match suggestion {
                Some(s) => Some(String::from(s)),
                None => None,
            },
        }
    }

    pub fn get_line(&self) -> usize {
        self.location.get_line()
    }

    pub fn format_with_line(&self, line: &str) -> String {
        let error_line = match &self.suggestion {
            Some(s) => format!(
                "      |\n    1 | {}\n      |{}^ {}",
                line,
                " ".repeat(self.location.get_line_span().start),
                s
            ),
            None => format!(
                "      |\n    1 | {}\n      |{}^",
                line,
                " ".repeat(self.location.get_line_span().start)
            ),
        };

        format!(
            "error: {} (at line {}, position {}):\n\n{}",
            self.message.as_str(),
            self.location.get_line(),
            self.location.get_line_span().start,
            error_line
        )
    }
}

impl std::fmt::Debug for CompilerError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        // f.debug_struct("CompilerError").field("location", &self.location).field("message", &self.message).field("suggestion", &self.suggestion).finish()
        let (line_span, absolute_span) = (
            self.location.get_line_span(),
            self.location.get_absolute_span(),
        );
        write!(
            f,
            "{} @ {}:[{}..{}] @ [{}..{}]",
            self.message,
            self.location.get_line(),
            line_span.start,
            line_span.end,
            absolute_span.start,
            absolute_span.end
        )
    }
}
