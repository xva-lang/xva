use crate::tests::{extract_nth_node_at_mth_level, get_parser};

use super::get_tree;

#[test]
fn boolean_literal() {
    let mut parser = get_parser();
    let tree = parser.parse("true", None).expect("Failed to parse");
    assert_eq!(
        extract_nth_node_at_mth_level(&tree.root_node(), 0, 2).kind(),
        "boolean_literal"
    );

    let tree = parser.parse("false", None).expect("Failed to parse");
    assert_eq!(
        extract_nth_node_at_mth_level(&tree.root_node(), 0, 2).kind(),
        "boolean_literal"
    )
}

fn assert_decimal_literal(input: &str) {
    let tree = get_tree(input);
    let root = tree.root_node();
    let (first, second, third, fourth) = (
        extract_nth_node_at_mth_level(&root, 0, 0),
        extract_nth_node_at_mth_level(&root, 0, 1),
        extract_nth_node_at_mth_level(&root, 0, 2),
        extract_nth_node_at_mth_level(&root, 0, 3),
    );

    assert_eq!(first.kind(), "expression");
    assert_eq!(second.kind(), "literal");
    assert_eq!(third.kind(), "integer_literal");
    assert_eq!(fourth.kind(), "decimal_literal");
}

#[test]
fn decimal_literals() {
    assert_decimal_literal("0");
    assert_decimal_literal("1");
    assert_decimal_literal("123");
    assert_decimal_literal("123");
    assert_decimal_literal("123_");
    assert_decimal_literal("1_2_3");
}
