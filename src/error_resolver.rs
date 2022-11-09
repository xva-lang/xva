use crate::compiler::error::CompilerError;

pub(crate) struct ErrorResolver {
    original_lines: Vec<String>,
}

impl ErrorResolver {
    pub fn new(original_lines: Vec<String>) -> Self {
        Self { original_lines }
    }

    pub fn resolve(&self, error: &CompilerError) -> String {
        let line = &self.original_lines[error.get_line() - 1];
        String::from(error.format_with_line(line))
    }
}
