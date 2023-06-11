mod lexer;
pub mod tree_sitter;

pub use crate::tree_sitter::print_cst;
pub use lexer::{lex, Span, Token};
#[cfg(test)]
mod tests {
    use crate::tree_sitter::{debug_tree, get_tree};

    #[test]
    fn test() {
        debug_tree(&get_tree(r#"let x: mutable boolean = false"#, None))
    }
}
