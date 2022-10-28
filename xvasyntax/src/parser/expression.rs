use crate::{language::SyntaxKind, parser::Parser};

enum InfixOperator {
    Addition,
    Subtraction,
    Multiplication,
    Division,
}

enum PrefixOperator {
    Negation,
}

const ADDITION_BINDING_POWER: u8 = 1;
const SUBTRACTION_BINDING_POWER: u8 = 2;
const MULTUPLICATION_BINDING_POWER: u8 = 3;
const DIVISION_BINDING_POWER: u8 = 4;
const NEGATION_BINDING_POWER: u8 = 5;

/// Trait for operators that describe their left and right binding powers for parsing expressions.
pub trait HasBindingPower {
    /// Determines the left and right binding powers for a given operator.
    /// # Returns
    /// A tuple containing a `Some(u8)` and a `u8` representing the left and right binding powers, respectively. If an
    /// operator does not bind left (prefixes, for instance) then the return value is `(None, u8)`.
    fn binding_power(&self) -> (Option<u8>, u8);
}

impl HasBindingPower for InfixOperator {
    fn binding_power(&self) -> (Option<u8>, u8) {
        // 1 + 2 + 3 + 4
        // -> ((1 + 2) + 3) + 4
        // 1   +   2   +   3   +   4    <- item
        //   1   2   1   2   1   2      <- binding power
        match self {
            Self::Addition | Self::Subtraction => {
                (Some(ADDITION_BINDING_POWER), SUBTRACTION_BINDING_POWER)
            }
            Self::Multiplication | Self::Division => {
                (Some(MULTUPLICATION_BINDING_POWER), DIVISION_BINDING_POWER)
            }
        }
    }
}

impl HasBindingPower for PrefixOperator {
    fn binding_power(&self) -> (Option<u8>, u8) {
        match self {
            Self::Negation => (None, NEGATION_BINDING_POWER),
        }
    }
}

pub(super) fn expression(parser: &mut Parser) {
    expression_binding_power(parser, 0)
}

fn parse_prefix_expression(parser: &mut Parser, checkpoint: usize, operator: PrefixOperator) {
    let (_, right_binding_power) = operator.binding_power();

    parser.bump();

    parser.start_node_at(checkpoint, SyntaxKind::PrefixExpression);
    expression_binding_power(parser, right_binding_power);
    parser.finish_node();
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
    let checkpoint = parser.checkpoint();

    match parser.peek() {
        Some(SyntaxKind::IntegerLiteral) | Some(SyntaxKind::Identifier) => parser.bump(),
        Some(SyntaxKind::Minus) => {
            parse_prefix_expression(parser, checkpoint, PrefixOperator::Negation)
        }
        Some(SyntaxKind::LeftParenthesis) => {
            parser.start_node_at(parser.checkpoint(), SyntaxKind::ParenthesisedExpression);
            parser.bump();
            expression_binding_power(parser, 0);
            assert_eq!(
                parser.peek(),
                Some(SyntaxKind::RightParenthesis),
                "No matching right parenthesis."
            );
            parser.bump();
            parser.finish_node();
        }
        _ => {}
    }

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
        parser.start_node_at(checkpoint, SyntaxKind::BinaryExpression);

        expression_binding_power(parser, right_binding_power);
        parser.finish_node();
    }
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
  IntegerLiteral@0..3 "123""#]],
        );
    }

    #[test]
    fn parse_identifier() {
        check_parse(
            "counter",
            expect![[r#"
Root@0..7
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
    IntegerLiteral@0..1 "1"
    Plus@1..2 "+"
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
        IntegerLiteral@0..1 "1"
        Plus@1..2 "+"
        IntegerLiteral@2..3 "2"
      Plus@3..4 "+"
      IntegerLiteral@4..5 "3"
    Plus@5..6 "+"
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
      IntegerLiteral@0..1 "1"
      Plus@1..2 "+"
      BinaryExpression@2..5
        IntegerLiteral@2..3 "2"
        Star@3..4 "*"
        IntegerLiteral@4..5 "3"
    Minus@5..6 "-"
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
      IntegerLiteral@1..3 "20"
    Plus@3..4 "+"
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
    IntegerLiteral@0..1 "5"
    Star@1..2 "*"
    ParenthesisedExpression@2..7
      LeftParenthesis@2..3 "("
      BinaryExpression@3..6
        IntegerLiteral@3..4 "2"
        Plus@4..5 "+"
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
    IntegerLiteral@1..2 "1"
    Whitespace@2..3 " "
    Plus@3..4 "+"
    Whitespace@4..7 "   "
    BinaryExpression@7..12
      IntegerLiteral@7..8 "2"
      Star@8..9 "*"
      Whitespace@9..10 " "
      IntegerLiteral@10..11 "3"
      Whitespace@11..12 " ""#]],
        )
    }
}
