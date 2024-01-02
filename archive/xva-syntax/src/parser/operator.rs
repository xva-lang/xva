use crate::ast::{BinaryOperator, PrefixOperator};
use tree_sitter::Node;

pub(super) fn binary_operator(node: &Node<'_>, input: &str) -> BinaryOperator {
    match node.utf8_text(input.as_ref()) {
        Ok(t) => match t {
            "+" => BinaryOperator::Plus,
            o => panic!("unknown operator '{o}'"),
        },
        Err(e) => panic!("{}", e),
    }
}

pub(super) fn prefix_operator(node: &Node<'_>, input: &str) -> PrefixOperator {
    match node.utf8_text(input.as_ref()) {
        Ok(t) => match t {
            "-" => PrefixOperator::Negate,
            o => panic!("Unknown prefix operator: '{o}'"),
        },
        Err(e) => panic!("{}", e),
    }
}
