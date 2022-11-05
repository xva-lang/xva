use super::{
    ast::{
        operator::{BindingPowered, InfixOperator, PrefixOperator},
        BinaryExpression, Expression, ExpressionVariant, LiteralVariant, PrefixExpression, Root,
    },
    lexer::token_stream::TokenStream,
    lexer::{language::TokenKind, lexeme::Lexeme},
};

pub(crate) struct Parser<'stream> {
    stream: TokenStream<'stream>,
}

impl<'stream> Parser<'stream> {
    pub fn new(stream: TokenStream<'stream>) -> Self {
        Self { stream }
    }

    pub fn parse(&mut self) -> Root {
        let mut children: Vec<Expression> = vec![];
        while let Some(expression) = self.expression() {
            children.push(expression);
        }

        Root::new(children)
    }

    fn peek_variant(&self) -> Option<TokenKind> {
        self.stream.peek_variant()
    }

    fn peek_next_variant(&self) -> Option<TokenKind> {
        self.stream.peek_next_variant()
    }

    fn bump(&mut self) -> Option<Lexeme<'_>> {
        self.stream.next()
    }

    pub fn expression(&mut self) -> Option<Expression> {
        match self.peek_variant() {
            Some(variant) => match variant {
                TokenKind::IntegerLiteral => self.expression_binding_power(0),
                TokenKind::TrueLiteral | TokenKind::FalseLiteral => {
                    self.expression_binding_power(0)
                }
                TokenKind::Minus => match self.peek_next_variant() {
                    Some(p) => match p {
                        TokenKind::IntegerLiteral => self.expression_binding_power(0),
                        _ => panic!("invalid token kind after prefix: {:?}", p),
                    },
                    None => panic!("missing expression after prefix"),
                },
                _ => panic!("unknown variant {:?}", variant),
            },
            None => None,
        }
    }

    // pub fn declaration(&mut self) -> Option<Node> {
    //     let let_keyword = self.next();
    // }

    fn expression_binding_power(&mut self, minimum_binding_power: u8) -> Option<Expression> {
        let mut left = self.left()?;
        let left_span = left.get_span();
        let left_line = left.get_line();

        loop {
            let operator = match self.peek_variant() {
                Some(TokenKind::Plus) => InfixOperator::Addition,
                Some(TokenKind::Minus) => InfixOperator::Subtraction,
                Some(TokenKind::Star) => InfixOperator::Multiplication,
                Some(TokenKind::Slash) => InfixOperator::Division,
                _ => break,
            };

            let (left_binding_power, right_binding_power) = operator.binding_power();
            if left_binding_power.unwrap() < minimum_binding_power {
                break;
            }

            let _ = self.bump();

            // And recurse
            let right = self.expression_binding_power(right_binding_power);

            if !right.is_some() {
                break;
            }

            let right_span = match &right {
                Some(r) => r.get_span(),
                None => unreachable!("Right span match condition failed"),
            };

            left = Expression::new(
                ExpressionVariant::Binary(BinaryExpression::new(
                    Box::from(left),
                    operator,
                    Box::from(right.unwrap()),
                )),
                left_line,
                (left_span.start..right_span.end).into(),
            );
        }

        Some(left)
    }

    fn left(&mut self) -> Option<Expression> {
        let result = match self.peek_variant() {
            Some(variant) => match variant {
                TokenKind::IntegerLiteral | TokenKind::TrueLiteral | TokenKind::FalseLiteral => {
                    self.literal()
                }
                TokenKind::Minus | TokenKind::Plus => {
                    self.prefix_expression(PrefixOperator::Negation)
                }
                x => unreachable!("{:?}", x),
            },
            None => None,
        };
        // let result = match parser.peek() {
        //     Some(SyntaxKind::Identifier) => identifier_expression(parser),
        //     Some(SyntaxKind::IntegerLiteral) => literal(parser),
        //     Some(SyntaxKind::Minus) => prefix_expression(parser, PrefixOperator::Negation),
        //     Some(SyntaxKind::LeftParenthesis) => parenthesised_expression(parser),
        //     Some(SyntaxKind::TrueLiteral) | Some(SyntaxKind::FalseLiteral) => literal(parser),
        //     _ => return None,
        // };

        // result
        result
    }

    fn literal(&mut self) -> Option<Expression> {
        let literal_lexeme = self.bump().unwrap();

        let literal_variant = match literal_lexeme.get_variant() {
            TokenKind::IntegerLiteral => {
                LiteralVariant::Integer(i64::from_str_radix(literal_lexeme.get_text(), 10).unwrap())
            }
            TokenKind::TrueLiteral => LiteralVariant::Boolean(true),
            TokenKind::FalseLiteral => LiteralVariant::Boolean(false),
            x => todo!("Unimplemented literal kind: {:#?}", x),
        };

        Some(Expression::new(
            ExpressionVariant::Literal(literal_variant),
            literal_lexeme.get_line(),
            literal_lexeme.get_line_span(),
        ))
    }

    fn prefix_expression(&mut self, operator: PrefixOperator) -> Option<Expression> {
        let (_, right_binding_power) = operator.binding_power();

        let marker = self.bump().unwrap();
        let (line, span) = (marker.get_line(), marker.get_line_span());

        Some(Expression::new(
            ExpressionVariant::Prefix(PrefixExpression::new(
                operator,
                Box::from(self.expression_binding_power(right_binding_power).unwrap()),
            )),
            line,
            span,
        ))
    }
}

#[cfg(test)]
mod tests {
    use super::Parser;
    use crate::syntax::lexer::{language::TokenKind, token_stream::TokenStream};
    use expect_test::{expect, Expect};
    use logos::Logos;

    fn check_expression(input: &str, expected: Expect) {
        let mut lexer = TokenKind::lexer(input);
        let token_stream = TokenStream::new(&mut lexer);
        let mut parser = Parser::new(token_stream);

        expected.assert_eq(format!("{}", parser.parse()).as_str())
    }

    #[test]
    fn parse_integer_literal() {
        check_expression("1", expect![["Integer(1)"]])
    }

    #[test]
    fn parse_false_literal() {
        check_expression("false", expect![["Boolean(false)"]])
    }

    #[test]
    fn parse_true_literal() {
        check_expression("true", expect![["Boolean(true)"]])
    }

    #[test]
    fn parse_prefix_expression() {
        check_expression("-1", expect![["Prefix(-, Integer(1))"]])
    }

    #[test]
    fn parse_binary_expression() {
        check_expression(
            "1 + 2",
            expect![["BinaryExpression(+, Integer(1), Integer(2))"]],
        )
    }

    #[test]
    fn parse_nested_binary_expression() {
        check_expression(
            "1 + 1 + 1",
            expect![[
                "BinaryExpression(+, BinaryExpression(+, Integer(1), Integer(1)), Integer(1))"
            ]],
        );
    }
}
