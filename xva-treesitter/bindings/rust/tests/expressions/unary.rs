use crate::tests::test_tree;
use expect_test::expect;

#[test]
fn unary_negation() {
    test_tree(
        "-5",
        expect![[r#"
root @0:0..0:2 "-5"
  expression @0:0..0:2 "-5"
    unary_expression @0:0..0:2 "-5"
      negation_expression @0:0..0:2 "-5"
        expression @0:1..0:2 "5"
          literal @0:1..0:2 "5"
            integer_literal @0:1..0:2 "5"
              decimal_literal @0:1..0:2 "5""#]],
    )
}

#[test]
fn unary_logical_not() {
    test_tree(
        "not false",
        expect![[r#"
root @0:0..0:9 "not false"
  expression @0:0..0:9 "not false"
    unary_expression @0:0..0:9 "not false"
      not_expression @0:0..0:9 "not false"
        expression @0:4..0:9 "false"
          literal @0:4..0:9 "false"
            boolean_literal @0:4..0:9 "false""#]],
    )
}
