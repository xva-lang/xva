use crate::tests::{extract_nth_node_at_mth_level, get_tree};

const KIND_EXPRESSION: &str = "expression";
const KIND_LITERAL: &str = "literal";
const KIND_INTEGER_LITERAL: &str = "integer_literal";
const KIND_DECIMAL_LITERAL: &str = "decimal_literal";
const KIND_HEX_LITERAL: &str = "hex_literal";
const KIND_OCTAL_LITERAL: &str = "octal_literal";
const KIND_BINARY_LITERAL: &str = "binary_literal";
const KIND_CHARACTER_LITERAL: &str = "character_literal";
const KIND_STRING_LITERAL: &str = "string_literal";
const KIND_FLOAT_LITERAL: &str = "float_literal";

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

    assert_eq!(first.kind(), KIND_EXPRESSION);
    assert_eq!(second.kind(), KIND_LITERAL);
    assert_eq!(third.kind(), KIND_INTEGER_LITERAL);
    assert_eq!(fourth.kind(), KIND_DECIMAL_LITERAL);
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

    assert_eq!(first.kind(), KIND_EXPRESSION);
    assert_eq!(second.kind(), KIND_LITERAL);
    assert_eq!(third.kind(), KIND_INTEGER_LITERAL);
    assert_eq!(fourth.kind(), KIND_BINARY_LITERAL);
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

    assert_eq!(first.kind(), KIND_EXPRESSION);
    assert_eq!(second.kind(), KIND_LITERAL);
    assert_eq!(third.kind(), KIND_INTEGER_LITERAL);
    assert_eq!(fourth.kind(), KIND_HEX_LITERAL);
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

    assert_eq!(first.kind(), KIND_EXPRESSION);
    assert_eq!(second.kind(), KIND_LITERAL);
    assert_eq!(third.kind(), KIND_INTEGER_LITERAL);
    assert_eq!(fourth.kind(), KIND_OCTAL_LITERAL);
}

fn assert_char_literal(input: &str) {
    let tree = get_tree(input);
    let root = tree.root_node();
    let (first, second, third) = (
        extract_nth_node_at_mth_level(&root, 0, 0),
        extract_nth_node_at_mth_level(&root, 0, 1),
        extract_nth_node_at_mth_level(&root, 0, 2),
    );

    assert_eq!(first.kind(), KIND_EXPRESSION);
    assert_eq!(second.kind(), KIND_LITERAL);
    assert_eq!(third.kind(), KIND_CHARACTER_LITERAL);
}

fn assert_string_literal(input: &str) {
    let tree = get_tree(input);
    let root = tree.root_node();
    let (first, second, third) = (
        extract_nth_node_at_mth_level(&root, 0, 0),
        extract_nth_node_at_mth_level(&root, 0, 1),
        extract_nth_node_at_mth_level(&root, 0, 2),
    );
    assert_eq!(first.kind(), KIND_EXPRESSION);
    assert_eq!(second.kind(), KIND_LITERAL);
    assert_eq!(third.kind(), KIND_STRING_LITERAL);
}

fn assert_float_literal(input: &str) {
    let tree = get_tree(input);
    let root = tree.root_node();
    let (first, second, third) = (
        extract_nth_node_at_mth_level(&root, 0, 0),
        extract_nth_node_at_mth_level(&root, 0, 1),
        extract_nth_node_at_mth_level(&root, 0, 2),
    );
    assert_eq!(first.kind(), KIND_EXPRESSION);
    assert_eq!(second.kind(), KIND_LITERAL);
    assert_eq!(third.kind(), KIND_FLOAT_LITERAL);
}

/// Expensive: this function clones a [`tree_sitter::Tree`]
fn assert_float_literal_returning_tree(input: &str) -> tree_sitter::Tree {
    let tree = get_tree(input);
    let cloned_tree = tree.clone();
    let root = tree.root_node();
    let (first, second, third) = (
        extract_nth_node_at_mth_level(&root, 0, 0),
        extract_nth_node_at_mth_level(&root, 0, 1),
        extract_nth_node_at_mth_level(&root, 0, 2),
    );
    assert_eq!(first.kind(), KIND_EXPRESSION);
    assert_eq!(second.kind(), KIND_LITERAL);
    assert_eq!(third.kind(), KIND_FLOAT_LITERAL);

    cloned_tree
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

#[test]
fn strings() {
    assert_string_literal(r#""abcdef\0\r\n\t\x39\u211B\"\'\"""#)
}

#[test]
fn floats() {
    assert_float_literal("1.23")
}

#[test]
fn float_literal_leading_zero() {
    assert_float_literal("0.1");
}

#[test]
fn float_literal_trailing_dot() {
    assert_float_literal("1.");
}

#[test]
fn float_literal_capital_exponent() {
    let input = "1.0E5";
    let tree = assert_float_literal_returning_tree(input);
    let root = tree.root_node();
    let float_node = extract_nth_node_at_mth_level(&root, 0, 2);
    let exponent_node = float_node.child_by_field_name("exponent").unwrap();
    assert_eq!(exponent_node.utf8_text(input.as_bytes()).unwrap(), "E5")
}

#[test]
fn float_literal_negative_exponent() {
    let input = "1.0e-5";
    let tree = assert_float_literal_returning_tree(input);
    let root = tree.root_node();
    let float_node = extract_nth_node_at_mth_level(&root, 0, 2);
    let exponent_node = float_node.child_by_field_name("exponent").unwrap();
    assert_eq!(exponent_node.utf8_text(input.as_bytes()).unwrap(), "e-5")
}

#[test]
fn float_literal_underscore_fraction() {
    assert_float_literal("0.12_34");
}
