mod lexer;
mod tree_sitter;

pub use lexer::{lex, Span, Token};

#[cfg(test)]
mod tests {}
