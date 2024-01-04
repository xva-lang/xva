use expect_test::expect;

use crate::tests::test_tree;

#[test]
fn boolean_literal_true() {
    test_tree(
        "true",
        expect![[r#"
root @0:0..0:4 "true"
  expression @0:0..0:4 "true"
    literal @0:0..0:4 "true"
      boolean_literal @0:0..0:4 "true""#]],
    )
}

#[test]
fn boolean_literal_false() {
    test_tree(
        "false",
        expect![[r#"
root @0:0..0:5 "false"
  expression @0:0..0:5 "false"
    literal @0:0..0:5 "false"
      boolean_literal @0:0..0:5 "false""#]],
    )
}

#[test]
fn decimal_literal_zero() {
    test_tree(
        "0",
        expect![[r#"
root @0:0..0:1 "0"
  expression @0:0..0:1 "0"
    literal @0:0..0:1 "0"
      integer_literal @0:0..0:1 "0"
        decimal_literal @0:0..0:1 "0""#]],
    )
}

#[test]
fn decimal_literal_one() {
    test_tree(
        "1",
        expect![[r#"
root @0:0..0:1 "1"
  expression @0:0..0:1 "1"
    literal @0:0..0:1 "1"
      integer_literal @0:0..0:1 "1"
        decimal_literal @0:0..0:1 "1""#]],
    )
}

#[test]
fn decimal_literal() {
    test_tree(
        "123",
        expect![[r#"
root @0:0..0:3 "123"
  expression @0:0..0:3 "123"
    literal @0:0..0:3 "123"
      integer_literal @0:0..0:3 "123"
        decimal_literal @0:0..0:3 "123""#]],
    )
}

#[test]
fn decimal_literal_underscores() {
    test_tree(
        "1_2_3",
        expect![[r#"
root @0:0..0:5 "1_2_3"
  expression @0:0..0:5 "1_2_3"
    literal @0:0..0:5 "1_2_3"
      integer_literal @0:0..0:5 "1_2_3"
        decimal_literal @0:0..0:5 "1_2_3""#]],
    )
}

#[test]
fn decimal_literal_trailing_underscore() {
    test_tree(
        "123_",
        expect![[r#"
root @0:0..0:4 "123_"
  expression @0:0..0:4 "123_"
    literal @0:0..0:4 "123_"
      integer_literal @0:0..0:4 "123_"
        decimal_literal @0:0..0:4 "123_""#]],
    )
}

#[test]
fn binary_literal_zero() {
    test_tree(
        "0b0",
        expect![[r#"
root @0:0..0:3 "0b0"
  expression @0:0..0:3 "0b0"
    literal @0:0..0:3 "0b0"
      integer_literal @0:0..0:3 "0b0"
        binary_literal @0:0..0:3 "0b0""#]],
    )
}

#[test]
fn binary_literal_one() {
    test_tree(
        "0b1",
        expect![[r#"
root @0:0..0:3 "0b1"
  expression @0:0..0:3 "0b1"
    literal @0:0..0:3 "0b1"
      integer_literal @0:0..0:3 "0b1"
        binary_literal @0:0..0:3 "0b1""#]],
    )
}

#[test]
fn binary_literal() {
    test_tree(
        "0b1100",
        expect![[r#"
root @0:0..0:6 "0b1100"
  expression @0:0..0:6 "0b1100"
    literal @0:0..0:6 "0b1100"
      integer_literal @0:0..0:6 "0b1100"
        binary_literal @0:0..0:6 "0b1100""#]],
    )
}

#[test]
fn binary_literal_with_underscore() {
    test_tree(
        "0b100_100",
        expect![[r#"
root @0:0..0:9 "0b100_100"
  expression @0:0..0:9 "0b100_100"
    literal @0:0..0:9 "0b100_100"
      integer_literal @0:0..0:9 "0b100_100"
        binary_literal @0:0..0:9 "0b100_100""#]],
    )
}

#[test]
fn binary_literal_with_trailing_underscore() {
    test_tree(
        "0b100_100_",
        expect![[r#"
root @0:0..0:10 "0b100_100_"
  expression @0:0..0:10 "0b100_100_"
    literal @0:0..0:10 "0b100_100_"
      integer_literal @0:0..0:10 "0b100_100_"
        binary_literal @0:0..0:10 "0b100_100_""#]],
    )
}

#[test]
fn hex_literal_zero() {
    test_tree(
        "0x0",
        expect![[r#"
root @0:0..0:3 "0x0"
  expression @0:0..0:3 "0x0"
    literal @0:0..0:3 "0x0"
      integer_literal @0:0..0:3 "0x0"
        hex_literal @0:0..0:3 "0x0""#]],
    );
}

#[test]
fn hex_literal_one() {
    test_tree(
        "0x1",
        expect![[r#"
root @0:0..0:3 "0x1"
  expression @0:0..0:3 "0x1"
    literal @0:0..0:3 "0x1"
      integer_literal @0:0..0:3 "0x1"
        hex_literal @0:0..0:3 "0x1""#]],
    );
}

#[test]
fn hex_literal() {
    test_tree(
        "0x123456789ABcdEF",
        expect![[r#"
root @0:0..0:17 "0x123456789ABcdEF"
  expression @0:0..0:17 "0x123456789ABcdEF"
    literal @0:0..0:17 "0x123456789ABcdEF"
      integer_literal @0:0..0:17 "0x123456789ABcdEF"
        hex_literal @0:0..0:17 "0x123456789ABcdEF""#]],
    );
}

#[test]
fn hex_literal_with_underscore() {
    test_tree(
        "0x12345_6789ABcdEF",
        expect![[r#"
root @0:0..0:18 "0x12345_6789ABcdEF"
  expression @0:0..0:18 "0x12345_6789ABcdEF"
    literal @0:0..0:18 "0x12345_6789ABcdEF"
      integer_literal @0:0..0:18 "0x12345_6789ABcdEF"
        hex_literal @0:0..0:18 "0x12345_6789ABcdEF""#]],
    );
}

#[test]
fn hex_literal_with_trailing_underscore() {
    test_tree(
        "0x12345_6789ABcdEF_",
        expect![[r#"
root @0:0..0:19 "0x12345_6789ABcdEF_"
  expression @0:0..0:19 "0x12345_6789ABcdEF_"
    literal @0:0..0:19 "0x12345_6789ABcdEF_"
      integer_literal @0:0..0:19 "0x12345_6789ABcdEF_"
        hex_literal @0:0..0:19 "0x12345_6789ABcdEF_""#]],
    );
}

#[test]
fn octal_literal_zero() {
    test_tree(
        "0o0",
        expect![[r#"
root @0:0..0:3 "0o0"
  expression @0:0..0:3 "0o0"
    literal @0:0..0:3 "0o0"
      integer_literal @0:0..0:3 "0o0"
        octal_literal @0:0..0:3 "0o0""#]],
    )
}

#[test]
fn octal_literal_one() {
    test_tree(
        "0o1",
        expect![[r#"
root @0:0..0:3 "0o1"
  expression @0:0..0:3 "0o1"
    literal @0:0..0:3 "0o1"
      integer_literal @0:0..0:3 "0o1"
        octal_literal @0:0..0:3 "0o1""#]],
    )
}

#[test]
fn octal_literal() {
    test_tree(
        "0o1234567",
        expect![[r#"
root @0:0..0:9 "0o1234567"
  expression @0:0..0:9 "0o1234567"
    literal @0:0..0:9 "0o1234567"
      integer_literal @0:0..0:9 "0o1234567"
        octal_literal @0:0..0:9 "0o1234567""#]],
    )
}

#[test]
fn octal_literal_with_underscore() {
    test_tree(
        "0o1234_567",
        expect![[r#"
root @0:0..0:10 "0o1234_567"
  expression @0:0..0:10 "0o1234_567"
    literal @0:0..0:10 "0o1234_567"
      integer_literal @0:0..0:10 "0o1234_567"
        octal_literal @0:0..0:10 "0o1234_567""#]],
    )
}

#[test]
fn octal_literal_with_trailing_underscore() {
    test_tree(
        "0o1234_567_",
        expect![[r#"
root @0:0..0:11 "0o1234_567_"
  expression @0:0..0:11 "0o1234_567_"
    literal @0:0..0:11 "0o1234_567_"
      integer_literal @0:0..0:11 "0o1234_567_"
        octal_literal @0:0..0:11 "0o1234_567_""#]],
    )
}

#[test]
fn char_literal() {
    test_tree(
        r"'c'",
        expect![[r#"
root @0:0..0:3 "'c'"
  expression @0:0..0:3 "'c'"
    literal @0:0..0:3 "'c'"
      character_literal @0:0..0:3 "'c'""#]],
    )
}

#[test]
fn ascii_literal() {
    test_tree(
        r"'\x69'",
        expect![[r#"
root @0:0..0:6 "'\x69'"
  expression @0:0..0:6 "'\x69'"
    literal @0:0..0:6 "'\x69'"
      character_literal @0:0..0:6 "'\x69'""#]],
    );
}

#[test]
fn char_ascii_carriage_return() {
    test_tree(
        r"'\r'",
        expect![[r#"
root @0:0..0:4 "'\r'"
  expression @0:0..0:4 "'\r'"
    literal @0:0..0:4 "'\r'"
      character_literal @0:0..0:4 "'\r'""#]],
    );
}

#[test]
fn char_ascii_new_line() {
    test_tree(
        r"'\n'",
        expect![[r#"
root @0:0..0:4 "'\n'"
  expression @0:0..0:4 "'\n'"
    literal @0:0..0:4 "'\n'"
      character_literal @0:0..0:4 "'\n'""#]],
    );
}

#[test]
fn char_ascii_tab() {
    test_tree(
        r"'\t'",
        expect![[r#"
root @0:0..0:4 "'\t'"
  expression @0:0..0:4 "'\t'"
    literal @0:0..0:4 "'\t'"
      character_literal @0:0..0:4 "'\t'""#]],
    );
}

#[test]
fn char_ascii_null() {
    test_tree(
        r"'\0'",
        expect![[r#"
root @0:0..0:4 "'\0'"
  expression @0:0..0:4 "'\0'"
    literal @0:0..0:4 "'\0'"
      character_literal @0:0..0:4 "'\0'""#]],
    );
}

#[test]
fn char_ascii_literal_slash() {
    test_tree(
        r"'\\'",
        expect![[r#"
root @0:0..0:4 "'\\'"
  expression @0:0..0:4 "'\\'"
    literal @0:0..0:4 "'\\'"
      character_literal @0:0..0:4 "'\\'""#]],
    );
}

#[test]
fn char_single_quote_escape() {
    test_tree(
        r"'\''",
        expect![[r#"
root @0:0..0:4 "'\''"
  expression @0:0..0:4 "'\''"
    literal @0:0..0:4 "'\''"
      character_literal @0:0..0:4 "'\''""#]],
    );
}

#[test]
fn unicode_literal() {
    test_tree(
        r"'\u211B'",
        expect![[r#"
root @0:0..0:8 "'\u211B'"
  expression @0:0..0:8 "'\u211B'"
    literal @0:0..0:8 "'\u211B'"
      character_literal @0:0..0:8 "'\u211B'""#]],
    );
}

#[test]
fn strings() {
    // assert_string_literal(r#""abcdef\0\r\n\t\x39\u211B\"\'\"""#)
    test_tree(
        r#""abcdef\0\r\n\t\x39\u211B\"\'\"""#,
        expect![[r#"
root @0:0..0:32 ""abcdef\0\r\n\t\x39\u211B\"\'\"""
  expression @0:0..0:32 ""abcdef\0\r\n\t\x39\u211B\"\'\"""
    literal @0:0..0:32 ""abcdef\0\r\n\t\x39\u211B\"\'\"""
      string_literal @0:0..0:32 ""abcdef\0\r\n\t\x39\u211B\"\'\"""
        escape_sequence @0:7..0:9 "\0"
        escape_sequence @0:9..0:11 "\r"
        escape_sequence @0:11..0:13 "\n"
        escape_sequence @0:13..0:15 "\t"
        escape_sequence @0:15..0:19 "\x39"
        escape_sequence @0:19..0:25 "\u211B"
        escape_sequence @0:25..0:27 "\""
        escape_sequence @0:27..0:29 "\'"
        escape_sequence @0:29..0:31 "\"""#]],
    );
}

#[test]
fn floats() {
    test_tree(
        "1.23",
        expect![[r#"
root @0:0..0:4 "1.23"
  expression @0:0..0:4 "1.23"
    literal @0:0..0:4 "1.23"
      float_literal @0:0..0:4 "1.23""#]],
    )
}

#[test]
fn float_literal_leading_zero() {
    test_tree(
        "0.1",
        expect![[r#"
root @0:0..0:3 "0.1"
  expression @0:0..0:3 "0.1"
    literal @0:0..0:3 "0.1"
      float_literal @0:0..0:3 "0.1""#]],
    )
}

#[test]
fn float_literal_trailing_dot() {
    test_tree(
        "1.",
        expect![[r#"
root @0:0..0:2 "1."
  expression @0:0..0:2 "1."
    literal @0:0..0:2 "1."
      float_literal @0:0..0:2 "1.""#]],
    )
}

#[test]
fn float_literal_capital_exponent() {
    // let input = "1.0E5";
    // let tree = assert_float_literal_returning_tree(input);
    // let root = tree.root_node();
    // let float_node = extract_nth_node_at_mth_level(&root, 0, 2);
    // let exponent_node = float_node.child_by_field_name("exponent").unwrap();
    // assert_eq!(exponent_node.utf8_text(input.as_bytes()).unwrap(), "E5")
    test_tree(
        "1.0E5",
        expect![[r#"
root @0:0..0:5 "1.0E5"
  expression @0:0..0:5 "1.0E5"
    literal @0:0..0:5 "1.0E5"
      float_literal @0:0..0:5 "1.0E5"
        float_exponent @0:3..0:5 "E5""#]],
    )
}

#[test]
fn float_literal_negative_exponent() {
    test_tree(
        "1.0e-5",
        expect![[r#"
root @0:0..0:6 "1.0e-5"
  expression @0:0..0:6 "1.0e-5"
    literal @0:0..0:6 "1.0e-5"
      float_literal @0:0..0:6 "1.0e-5"
        float_exponent @0:3..0:6 "e-5""#]],
    )
}

#[test]
fn float_literal_underscore_fraction() {
    // assert_float_literal("0.12_34");

    test_tree(
        "0.12_34",
        expect![[r#"
root @0:0..0:7 "0.12_34"
  expression @0:0..0:7 "0.12_34"
    literal @0:0..0:7 "0.12_34"
      float_literal @0:0..0:7 "0.12_34""#]],
    )
}
