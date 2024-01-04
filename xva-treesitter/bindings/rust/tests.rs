mod expressions;
mod literals;

use tree_sitter::{Parser, Tree};

use crate::utils::print_node;

#[test]
fn test_can_load_grammar() {
    let mut parser = tree_sitter::Parser::new();
    parser
        .set_language(super::language())
        .expect("Error loading xva language");
}

fn get_parser() -> Parser {
    let mut parser = tree_sitter::Parser::new();
    parser
        .set_language(super::language())
        .expect("Error loading Xva language");
    parser
}

pub(crate) fn get_tree(input: &str) -> Tree {
    let mut parser = get_parser();
    parser.parse(input, None).expect("Failed to parse")
}

pub(self) fn test_tree(input: &str, expected_tree: expect_test::Expect) {
    let mut result = String::new();
    let tree = get_tree(input);
    println!("sexp: {}", tree.root_node().to_sexp());
    let mut depth = 0;
    print_node(input, &tree, tree.root_node(), &mut depth, &mut result);

    expected_tree.assert_eq(&result);
}
