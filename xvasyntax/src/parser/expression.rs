use super::{
    marker::CompletedMarker,
    operator::{BindingPowered, InfixOperator, PrefixOperator},
};
use crate::{language::SyntaxKind, parser::Parser};

pub(super) fn expression(parser: &mut Parser) {
    expression_binding_power(parser, 0)
}

/// Consumes a single expression then starts a loop that:
/// 1. Parses out an operator and, based on this operator,
/// 2. Identify the left and right binding powers of the operator, then
/// 3. Wrap the expression and the operator in a new node, recurse, and finish the node.
///
/// Once the parser has found an operator with a lower binding power than what is allowed by `minimum_binding_power`,
/// the function returns, allowing the node to be completed and the recursive caller to continue parsing operators
/// with higher binding power.
/// # Arguments
/// `minimum_binding_power` - Tracks the iteratively increased binding power for an operator before the function
/// returns to complete the node.
fn expression_binding_power(parser: &mut Parser, minimum_binding_power: u8) {
    // let checkpoint = parser.checkpoint();

    let mut left = match parser.peek() {
        Some(SyntaxKind::Identifier) => identifier(parser),
        Some(SyntaxKind::IntegerLiteral) => literal(parser),
        Some(SyntaxKind::Minus) => prefix_expression(parser, PrefixOperator::Negation),
        Some(SyntaxKind::LeftParenthesis) => parenthesised_expression(parser),
        _ => return,
    };

    loop {
        let operator = match parser.peek() {
            Some(SyntaxKind::Plus) => InfixOperator::Addition,
            Some(SyntaxKind::Minus) => InfixOperator::Subtraction,
            Some(SyntaxKind::Star) => InfixOperator::Multiplication,
            Some(SyntaxKind::Slash) => InfixOperator::Division,
            _ => return, // Handle errors later
        };

        let (left_binding_power, right_binding_power) = operator.binding_power();
        if left_binding_power.unwrap() < minimum_binding_power {
            return;
        }

        // Consume the token for the operator
        parser.bump();

        // And recurse
        let marker = left.precede(parser);
        // parser.start_node_at(checkpoint, SyntaxKind::BinaryExpression);

        expression_binding_power(parser, right_binding_power);
        // parser.finish_node();
        left = marker.complete(parser, SyntaxKind::BinaryExpression);
    }
}

fn identifier(parser: &mut Parser) -> CompletedMarker {
    let marker = parser.start();
    parser.bump();
    marker.complete(parser, SyntaxKind::IdentifierExpression)
}

fn literal(parser: &mut Parser) -> CompletedMarker {
    let marker = parser.start();
    parser.bump();
    marker.complete(parser, SyntaxKind::Literal)
}

fn prefix_expression(parser: &mut Parser, operator: PrefixOperator) -> CompletedMarker {
    let (_, right_binding_power) = operator.binding_power();

    let marker = parser.start();
    parser.bump();

    expression_binding_power(parser, right_binding_power);
    marker.complete(parser, SyntaxKind::PrefixExpression)
}

fn parenthesised_expression(parser: &mut Parser) -> CompletedMarker {
    let marker = parser.start();
    parser.bump();
    expression_binding_power(parser, 0);
    assert_eq!(
        parser.peek(),
        Some(SyntaxKind::RightParenthesis),
        "No matching right parenthesis."
    );
    parser.bump();
    marker.complete(parser, SyntaxKind::ParenthesisedExpression)
}

#[cfg(test)]
mod tests {
    use crate::parser::tests::check_parse;
    use expect_test::expect;

    #[test]
    fn parse_number() {
        check_parse(
            "123",
            expect![[r#"
Root@0..3
  Literal@0..3
    IntegerLiteral@0..3 "123""#]],
        );
    }

    #[test]
    fn parse_identifier_expression() {
        check_parse(
            "counter",
            expect![[r#"
Root@0..7
  IdentifierExpression@0..7
    Identifier@0..7 "counter""#]],
        )
    }

    #[test]
    fn parse_simple_binary_expression() {
        check_parse(
            "1+2",
            expect![[r#"
Root@0..3
  BinaryExpression@0..3
    Literal@0..1
      IntegerLiteral@0..1 "1"
    Plus@1..2 "+"
    Literal@2..3
      IntegerLiteral@2..3 "2""#]],
        );
    }

    #[test]
    fn parse_left_associative_binary_expression() {
        check_parse(
            "1+2+3+4",
            expect![[r#"
Root@0..7
  BinaryExpression@0..7
    BinaryExpression@0..5
      BinaryExpression@0..3
        Literal@0..1
          IntegerLiteral@0..1 "1"
        Plus@1..2 "+"
        Literal@2..3
          IntegerLiteral@2..3 "2"
      Plus@3..4 "+"
      Literal@4..5
        IntegerLiteral@4..5 "3"
    Plus@5..6 "+"
    Literal@6..7
      IntegerLiteral@6..7 "4""#]],
        );
    }

    #[test]
    fn parse_binary_expression_with_mixed_binding_power() {
        check_parse(
            "1+2*3-4",
            expect![[r#"
Root@0..7
  BinaryExpression@0..7
    BinaryExpression@0..5
      Literal@0..1
        IntegerLiteral@0..1 "1"
      Plus@1..2 "+"
      BinaryExpression@2..5
        Literal@2..3
          IntegerLiteral@2..3 "2"
        Star@3..4 "*"
        Literal@4..5
          IntegerLiteral@4..5 "3"
    Minus@5..6 "-"
    Literal@6..7
      IntegerLiteral@6..7 "4""#]],
        );
    }

    #[test]
    fn parse_negation_expression() {
        check_parse(
            "-10",
            expect![[r#"
Root@0..3
  PrefixExpression@0..3
    Minus@0..1 "-"
    Literal@1..3
      IntegerLiteral@1..3 "10""#]],
        )
    }

    #[test]
    fn negation_has_higher_binding_power() {
        check_parse(
            "-20+20",
            expect![[r#"
Root@0..6
  BinaryExpression@0..6
    PrefixExpression@0..3
      Minus@0..1 "-"
      Literal@1..3
        IntegerLiteral@1..3 "20"
    Plus@3..4 "+"
    Literal@4..6
      IntegerLiteral@4..6 "20""#]],
        )
    }

    #[test]
    fn nested_parenthesised_expression() {
        check_parse(
            "((((20))))",
            expect![[r#"
Root@0..10
  ParenthesisedExpression@0..10
    LeftParenthesis@0..1 "("
    ParenthesisedExpression@1..9
      LeftParenthesis@1..2 "("
      ParenthesisedExpression@2..8
        LeftParenthesis@2..3 "("
        ParenthesisedExpression@3..7
          LeftParenthesis@3..4 "("
          Literal@4..6
            IntegerLiteral@4..6 "20"
          RightParenthesis@6..7 ")"
        RightParenthesis@7..8 ")"
      RightParenthesis@8..9 ")"
    RightParenthesis@9..10 ")""#]],
        )
    }

    #[test]
    fn parenthesised_expression_has_higher_binding_power() {
        check_parse(
            "5*(2+1)",
            expect![[r#"
Root@0..7
  BinaryExpression@0..7
    Literal@0..1
      IntegerLiteral@0..1 "5"
    Star@1..2 "*"
    ParenthesisedExpression@2..7
      LeftParenthesis@2..3 "("
      BinaryExpression@3..6
        Literal@3..4
          IntegerLiteral@3..4 "2"
        Plus@4..5 "+"
        Literal@5..6
          IntegerLiteral@5..6 "1"
      RightParenthesis@6..7 ")""#]],
        )
    }

    #[test]
    fn whitespace_in_expression() {
        check_parse(
            " 1 +   2* 3 ",
            expect![[r#"
Root@0..12
  Whitespace@0..1 " "
  BinaryExpression@1..12
    Literal@1..3
      IntegerLiteral@1..2 "1"
      Whitespace@2..3 " "
    Plus@3..4 "+"
    Whitespace@4..7 "   "
    BinaryExpression@7..12
      Literal@7..8
        IntegerLiteral@7..8 "2"
      Star@8..9 "*"
      Whitespace@9..10 " "
      Literal@10..12
        IntegerLiteral@10..11 "3"
        Whitespace@11..12 " ""#]],
        )
    }
}
