use crate::tests::{extract_nth_node_at_mth_level, get_parser};

use super::get_tree;

#[test]
fn boolean_literal_true() {
    let tree = get_tree("true");
    assert_eq!(
        extract_nth_node_at_mth_level(&tree.root_node(), 0, 2).kind(),
        "boolean_literal"
    );
}

#[test]
fn boolean_literal_false() {
    let tree = get_tree("false");
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

fn assert_binary_literal(input: &str) {
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
    assert_eq!(fourth.kind(), "binary_literal");
}

fn assert_hex_literal(input: &str) {
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
    assert_eq!(fourth.kind(), "hex_literal");
}

fn assert_octal_literal(input: &str) {
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
    assert_eq!(fourth.kind(), "octal_literal");
}

fn assert_char_literal(input: &str) {
    let tree = get_tree(input);
    let root = tree.root_node();
    let (first, second, third) = (
        extract_nth_node_at_mth_level(&root, 0, 0),
        extract_nth_node_at_mth_level(&root, 0, 1),
        extract_nth_node_at_mth_level(&root, 0, 2),
    );

    assert_eq!(first.kind(), "expression");
    assert_eq!(second.kind(), "literal");
    assert_eq!(third.kind(), "character_literal");
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

#[test]
fn binary_literal_zero() {
    assert_binary_literal("0b0")
}

#[test]
fn binary_literal_one() {
    assert_binary_literal("0b1");
}

#[test]
fn binary_literal() {
    assert_binary_literal("0b1100");
}

#[test]
fn binary_literal_with_underscore() {
    assert_binary_literal("0b100_100");
}

#[test]
fn binary_literal_with_trailing_underscore() {
    assert_binary_literal("0b100_100_");
}

#[test]
#[should_panic]
fn binary_literal_without_prefix() {
    assert_binary_literal("0");
}

#[test]
fn hex_literal_zero() {
    assert_hex_literal("0x0");
}

#[test]
fn hex_literal_one() {
    assert_hex_literal("0x1");
}

#[test]
fn hex_literal() {
    assert_hex_literal("0x123456789ABcdEF");
}

#[test]
fn hex_literal_with_underscore() {
    assert_hex_literal("0x12345_6789ABcdEF");
}

#[test]
fn hex_literal_with_trailing_underscore() {
    assert_hex_literal("0x12345_6789ABcdEF_");
}

#[test]
#[should_panic]
fn hex_literal_without_prefix() {
    assert_hex_literal("123456789ABcdEF");
}

#[test]
fn octal_literal_zero() {
    assert_octal_literal("0o0");
}

#[test]
fn octal_literal_one() {
    assert_octal_literal("0o1");
}

#[test]
fn octal_literal() {
    assert_octal_literal("0o1234567");
}

#[test]
fn octal_literal_with_underscore() {
    assert_octal_literal("0o1234_567");
}

#[test]
fn octal_literal_with_trailing_underscore() {
    assert_octal_literal("0o1234_567_");
}

#[test]
fn char_literal() {
    assert_char_literal("\'c\'");
}

#[test]
fn ascii_literals() {
    assert_char_literal(r#"'\x69'"#);
    assert_char_literal(r#"'\r'"#);
    assert_char_literal(r#"'\n'"#);
    assert_char_literal(r#"'\t'"#);
    assert_char_literal(r#"'\0'"#);
    assert_char_literal(r#"'\\'"#);
}

#[test]
fn quote_escape_literals() {
    assert_char_literal(r#"'\''"#);
    assert_char_literal(r#"'\"'"#)
}

#[test]
fn unicode_literal() {
    assert_char_literal(r"'\u211B'");
}
