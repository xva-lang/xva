use crate::utils::test_tree;
use expect_test::expect;

#[test]
fn binary_logical_and() {
    test_tree(
        "true and true",
        expect![[r#"
root @0:0..0:13 "true and true"
  expression @0:0..0:13 "true and true"
    binary_expression @0:0..0:13 "true and true"
      "left" expression @0:0..0:4 "true"
        literal @0:0..0:4 "true"
          boolean_literal @0:0..0:4 "true"
      "operator" and @0:5..0:8
      "right" expression @0:9..0:13 "true"
        literal @0:9..0:13 "true"
          boolean_literal @0:9..0:13 "true""#]],
    )
}

#[test]
fn binary_logical_or() {
    test_tree(
        "true or true",
        expect![[r#"
root @0:0..0:12 "true or true"
  expression @0:0..0:12 "true or true"
    binary_expression @0:0..0:12 "true or true"
      "left" expression @0:0..0:4 "true"
        literal @0:0..0:4 "true"
          boolean_literal @0:0..0:4 "true"
      "operator" or @0:5..0:7
      "right" expression @0:8..0:12 "true"
        literal @0:8..0:12 "true"
          boolean_literal @0:8..0:12 "true""#]],
    )
}

#[test]
fn binary_bitwise_and() {
    test_tree(
        "1 & 1",
        expect![[r#"
root @0:0..0:5 "1 & 1"
  expression @0:0..0:5 "1 & 1"
    binary_expression @0:0..0:5 "1 & 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" & @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_bitwise_or() {
    test_tree(
        "1 | 1",
        expect![[r#"
root @0:0..0:5 "1 | 1"
  expression @0:0..0:5 "1 | 1"
    binary_expression @0:0..0:5 "1 | 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" | @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_bitwise_xor() {
    test_tree(
        "1 ^ 1",
        expect![[r#"
root @0:0..0:5 "1 ^ 1"
  expression @0:0..0:5 "1 ^ 1"
    binary_expression @0:0..0:5 "1 ^ 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" ^ @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_addition() {
    test_tree(
        "1 + 1",
        expect![[r#"
root @0:0..0:5 "1 + 1"
  expression @0:0..0:5 "1 + 1"
    binary_expression @0:0..0:5 "1 + 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" + @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_subtraction() {
    test_tree(
        "1 - 1",
        expect![[r#"
root @0:0..0:5 "1 - 1"
  expression @0:0..0:5 "1 - 1"
    binary_expression @0:0..0:5 "1 - 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" - @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_multiplication() {
    test_tree(
        "1 * 1",
        expect![[r#"
root @0:0..0:5 "1 * 1"
  expression @0:0..0:5 "1 * 1"
    binary_expression @0:0..0:5 "1 * 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" * @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_division() {
    test_tree(
        "1 / 1",
        expect![[r#"
root @0:0..0:5 "1 / 1"
  expression @0:0..0:5 "1 / 1"
    binary_expression @0:0..0:5 "1 / 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" / @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_power() {
    test_tree(
        "1 ** 1",
        expect![[r#"
root @0:0..0:6 "1 ** 1"
  expression @0:0..0:6 "1 ** 1"
    binary_expression @0:0..0:6 "1 ** 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" ** @0:2..0:4
      "right" expression @0:5..0:6 "1"
        literal @0:5..0:6 "1"
          integer_literal @0:5..0:6 "1"
            decimal_literal @0:5..0:6 "1""#]],
    )
}

#[test]
fn binary_modulo() {
    test_tree(
        "1 % 1",
        expect![[r#"
root @0:0..0:5 "1 % 1"
  expression @0:0..0:5 "1 % 1"
    binary_expression @0:0..0:5 "1 % 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" % @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_right_shift() {
    test_tree(
        "1 >> 1",
        expect![[r#"
root @0:0..0:6 "1 >> 1"
  expression @0:0..0:6 "1 >> 1"
    binary_expression @0:0..0:6 "1 >> 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" >> @0:2..0:4
      "right" expression @0:5..0:6 "1"
        literal @0:5..0:6 "1"
          integer_literal @0:5..0:6 "1"
            decimal_literal @0:5..0:6 "1""#]],
    )
}

#[test]
fn binary_left_shift() {
    test_tree(
        "1 << 1",
        expect![[r#"
root @0:0..0:6 "1 << 1"
  expression @0:0..0:6 "1 << 1"
    binary_expression @0:0..0:6 "1 << 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" << @0:2..0:4
      "right" expression @0:5..0:6 "1"
        literal @0:5..0:6 "1"
          integer_literal @0:5..0:6 "1"
            decimal_literal @0:5..0:6 "1""#]],
    )
}

#[test]
fn binary_less_than() {
    test_tree(
        "1 < 1",
        expect![[r#"
root @0:0..0:5 "1 < 1"
  expression @0:0..0:5 "1 < 1"
    binary_expression @0:0..0:5 "1 < 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" < @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_greater_than() {
    test_tree(
        "1 > 1",
        expect![[r#"
root @0:0..0:5 "1 > 1"
  expression @0:0..0:5 "1 > 1"
    binary_expression @0:0..0:5 "1 > 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" > @0:2..0:3
      "right" expression @0:4..0:5 "1"
        literal @0:4..0:5 "1"
          integer_literal @0:4..0:5 "1"
            decimal_literal @0:4..0:5 "1""#]],
    )
}

#[test]
fn binary_equal_to() {
    test_tree(
        "1 == 1",
        expect![[r#"
root @0:0..0:6 "1 == 1"
  expression @0:0..0:6 "1 == 1"
    binary_expression @0:0..0:6 "1 == 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" == @0:2..0:4
      "right" expression @0:5..0:6 "1"
        literal @0:5..0:6 "1"
          integer_literal @0:5..0:6 "1"
            decimal_literal @0:5..0:6 "1""#]],
    )
}

#[test]
fn binary_not_equal_to() {
    test_tree(
        "1 != 1",
        expect![[r#"
root @0:0..0:6 "1 != 1"
  expression @0:0..0:6 "1 != 1"
    binary_expression @0:0..0:6 "1 != 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" != @0:2..0:4
      "right" expression @0:5..0:6 "1"
        literal @0:5..0:6 "1"
          integer_literal @0:5..0:6 "1"
            decimal_literal @0:5..0:6 "1""#]],
    )
}

#[test]
fn binary_greater_or_equal_to() {
    test_tree(
        "1 >= 1",
        expect![[r#"
root @0:0..0:6 "1 >= 1"
  expression @0:0..0:6 "1 >= 1"
    binary_expression @0:0..0:6 "1 >= 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" >= @0:2..0:4
      "right" expression @0:5..0:6 "1"
        literal @0:5..0:6 "1"
          integer_literal @0:5..0:6 "1"
            decimal_literal @0:5..0:6 "1""#]],
    )
}

#[test]
fn binary_less_or_equal_to() {
    test_tree(
        "1 <= 1",
        expect![[r#"
root @0:0..0:6 "1 <= 1"
  expression @0:0..0:6 "1 <= 1"
    binary_expression @0:0..0:6 "1 <= 1"
      "left" expression @0:0..0:1 "1"
        literal @0:0..0:1 "1"
          integer_literal @0:0..0:1 "1"
            decimal_literal @0:0..0:1 "1"
      "operator" <= @0:2..0:4
      "right" expression @0:5..0:6 "1"
        literal @0:5..0:6 "1"
          integer_literal @0:5..0:6 "1"
            decimal_literal @0:5..0:6 "1""#]],
    )
}
