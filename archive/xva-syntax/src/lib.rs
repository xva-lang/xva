pub mod parser;
pub mod tree_sitter;
pub use crate::tree_sitter::print_cst;

mod ast;
#[cfg(test)]
mod tests {
    use crate::tree_sitter::{debug_tree, get_tree};

    #[test]
    fn test() {
        debug_tree(&get_tree(r#"let x: mutable boolean = false"#, None))
    }

    #[test]
    fn vec_test() {
        let vect = vec!(1,2,3);
    }
}
