use crate::{
    tests::{extract_nth_node_at_mth_level, get_tree, test_tree},
    utils::print_node,
};

use expect_test::expect;

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
    // assert_binary_literal("0b0")
    // assert_eq!(print_node("0b0", tree, node, depth, result))
    test_tree(
        "0b0",
        expect![[r#"
root @0:0..0:3
  expression @0:0..0:3
    literal @0:0..0:3
      integer_literal @0:0..0:3
        binary_literal @0:0..0:3 "0b0""#]],
    )
}

#[test]
fn binary_literal_one() {
    test_tree(
        "0b1",
        expect![[r#"
root @0:0..0:3
  expression @0:0..0:3
    literal @0:0..0:3
      integer_literal @0:0..0:3
        binary_literal @0:0..0:3 "0b1""#]],
    )
}

#[test]
fn binary_literal() {
    test_tree(
        "0b1100",
        expect![[r#"
root @0:0..0:6
  expression @0:0..0:6
    literal @0:0..0:6
      integer_literal @0:0..0:6
        binary_literal @0:0..0:6 "0b1100""#]],
    )
}

#[test]
fn binary_literal_with_underscore() {
    assert_binary_literal("0b100_100");
    test_tree(
        "0b100_100",
        expect![[r#"
root @0:0..0:9
  expression @0:0..0:9
    literal @0:0..0:9
      integer_literal @0:0..0:9
        binary_literal @0:0..0:9 "0b100_100""#]],
    )
}

#[test]
fn binary_literal_with_trailing_underscore() {
    assert_binary_literal("0b100_100_");
    test_tree(
        "0b100_100_",
        expect![[r#"
root @0:0..0:10
  expression @0:0..0:10
    literal @0:0..0:10
      integer_literal @0:0..0:10
        binary_literal @0:0..0:10 "0b100_100_""#]],
    )
}

#[test]
fn hex_literal_zero() {
    test_tree(
        "0x0",
        expect![[r#"
root @0:0..0:3
  expression @0:0..0:3
    literal @0:0..0:3
      integer_literal @0:0..0:3
        hex_literal @0:0..0:3 "0x0""#]],
    );
}

#[test]
fn hex_literal_one() {
    test_tree(
        "0x1",
        expect![[r#"
root @0:0..0:3
  expression @0:0..0:3
    literal @0:0..0:3
      integer_literal @0:0..0:3
        hex_literal @0:0..0:3 "0x1""#]],
    );
}

#[test]
fn hex_literal() {
    test_tree(
        "0x123456789ABcdEF",
        expect![[r#"
root @0:0..0:17
  expression @0:0..0:17
    literal @0:0..0:17
      integer_literal @0:0..0:17
        hex_literal @0:0..0:17 "0x123456789ABcdEF""#]],
    );
}

#[test]
fn hex_literal_with_underscore() {
    test_tree(
        "0x12345_6789ABcdEF",
        expect![[r#"
root @0:0..0:18
  expression @0:0..0:18
    literal @0:0..0:18
      integer_literal @0:0..0:18
        hex_literal @0:0..0:18 "0x12345_6789ABcdEF""#]],
    );
}

#[test]
fn hex_literal_with_trailing_underscore() {
    test_tree(
        "0x12345_6789ABcdEF_",
        expect![[r#"
root @0:0..0:19
  expression @0:0..0:19
    literal @0:0..0:19
      integer_literal @0:0..0:19
        hex_literal @0:0..0:19 "0x12345_6789ABcdEF_""#]],
    );
}

#[test]
fn octal_literal_zero() {
    test_tree(
        "0o0",
        expect![[r#"
root @0:0..0:3
  expression @0:0..0:3
    literal @0:0..0:3
      integer_literal @0:0..0:3
        octal_literal @0:0..0:3 "0o0""#]],
    )
}

#[test]
fn octal_literal_one() {
    test_tree(
        "0o1",
        expect![[r#"
root @0:0..0:3
  expression @0:0..0:3
    literal @0:0..0:3
      integer_literal @0:0..0:3
        octal_literal @0:0..0:3 "0o1""#]],
    )
}

#[test]
fn octal_literal() {
    test_tree(
        "0o1234567",
        expect![[r#"
root @0:0..0:9
  expression @0:0..0:9
    literal @0:0..0:9
      integer_literal @0:0..0:9
        octal_literal @0:0..0:9 "0o1234567""#]],
    )
}

#[test]
fn octal_literal_with_underscore() {
    test_tree(
        "0o1234_567",
        expect![[r#"
root @0:0..0:10
  expression @0:0..0:10
    literal @0:0..0:10
      integer_literal @0:0..0:10
        octal_literal @0:0..0:10 "0o1234_567""#]],
    )
}

#[test]
fn octal_literal_with_trailing_underscore() {
    test_tree(
        "0o1234_567_",
        expect![[r#"
root @0:0..0:11
  expression @0:0..0:11
    literal @0:0..0:11
      integer_literal @0:0..0:11
        octal_literal @0:0..0:11 "0o1234_567_""#]],
    )
}

#[test]
fn char_literal() {
    test_tree(
        "\'c\'",
        expect![[r#"
root @0:0..0:3
  expression @0:0..0:3
    literal @0:0..0:3
      character_literal @0:0..0:3 "'c'""#]],
    )
}

#[test]
fn ascii_literal() {
    test_tree(
        r"'\x69'",
        expect![[r#"
root @0:0..0:6
  expression @0:0..0:6
    literal @0:0..0:6
      character_literal @0:0..0:6 "'\x69'""#]],
    );
}

#[test]
fn char_ascii_carriage_return() {
    test_tree(
        r"'\r'",
        expect![[r#"
root @0:0..0:4
  expression @0:0..0:4
    literal @0:0..0:4
      character_literal @0:0..0:4 "'\r'""#]],
    );
}

#[test]
fn char_ascii_new_line() {
    test_tree(
        r"'\n'",
        expect![[r#"
root @0:0..0:4
  expression @0:0..0:4
    literal @0:0..0:4
      character_literal @0:0..0:4 "'\n'""#]],
    );
}

#[test]
fn char_ascii_tab() {
    test_tree(
        r"'\t'",
        expect![[r#"
root @0:0..0:4
  expression @0:0..0:4
    literal @0:0..0:4
      character_literal @0:0..0:4 "'\t'""#]],
    );
}

#[test]
fn char_ascii_null() {
    test_tree(
        r"'\0'",
        expect![[r#"
root @0:0..0:4
  expression @0:0..0:4
    literal @0:0..0:4
      character_literal @0:0..0:4 "'\0'""#]],
    );
}

#[test]
fn char_ascii_literal_slash() {
    test_tree(
        r"'\\'",
        expect![[r#"
root @0:0..0:4
  expression @0:0..0:4
    literal @0:0..0:4
      character_literal @0:0..0:4 "'\\'""#]],
    );
}

#[test]
fn char_single_quote_escape() {
    test_tree(
        r"'\''",
        expect![[r#"
root @0:0..0:4
  expression @0:0..0:4
    literal @0:0..0:4
      character_literal @0:0..0:4 "'\''""#]],
    );
}

#[test]
fn unicode_literal() {
    test_tree(
        r"'\u211B'",
        expect![[r#"
root @0:0..0:8
  expression @0:0..0:8
    literal @0:0..0:8
      character_literal @0:0..0:8 "'\u211B'""#]],
    );
}

#[test]
fn strings() {
    // assert_string_literal(r#""abcdef\0\r\n\t\x39\u211B\"\'\"""#)
    test_tree(
        r#""abcdef\0\r\n\t\x39\u211B\"\'\"""#,
        expect![[r#"
root @0:0..0:32
  expression @0:0..0:32
    literal @0:0..0:32
      string_literal @0:0..0:32 ""abcdef\0\r\n\t\x39\u211B\"\'\"""#]],
    );
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
