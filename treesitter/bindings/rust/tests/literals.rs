use crate::tests::{extract_nth_node_at_mth_level, get_parser};

#[test]
fn boolean_literal() {
    let mut parser = get_parser();
    let tree = parser.parse("true", None).expect("Failed to parse");
    assert_eq!(
        extract_nth_node_at_mth_level(tree.root_node(), 0, 2).kind(),
        "boolean_literal"
    );

    let tree = parser.parse("false", None).expect("Failed to parse");
    assert_eq!(
        extract_nth_node_at_mth_level(tree.root_node(), 0, 2).kind(),
        "boolean_literal"
    )
}
