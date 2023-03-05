use tree_sitter::{Parser, Tree};
use tree_sitter_xva::language;

pub(crate) fn get_tree(input: impl AsRef<[u8]>, existing_tree: Option<&Tree>) -> Tree {
    let mut parser = Parser::new();
    parser.set_language(language()).unwrap();
    parser.parse(input, existing_tree).unwrap()
}
