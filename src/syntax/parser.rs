use crate::compiler::error::CompilerError;

use super::{
    ast::{
        declaration::Declaration,
        expression::{
            BinaryExpression, Expression, ExpressionVariant, ParenthesisedExpression,
            PrefixExpression,
        },
        identifier::IdentifierExpression,
        literal::LiteralVariant,
        operator::{BindingPowered, InfixOperator, PrefixOperator},
        root::Root,
    },
    lexer::{language::TokenKind, lexeme::Lexeme},
    lexer::{span::Span, token_stream::TokenStream},
    location::SyntaxLocation,
};

pub(crate) struct Parser<'stream> {
    stream: TokenStream<'stream>,
    errors: Vec<CompilerError>,
}

impl<'stream> Parser<'stream> {
    pub fn new(stream: TokenStream<'stream>) -> Self {
        Self {
            stream,
            errors: vec![],
        }
    }

    pub fn parse(&mut self) -> Result<Root, &Vec<CompilerError>> {
        let mut children: Vec<Expression> = vec![];
        while let Some(expression) = self.expression() {
            children.push(expression);
        }

        if self.errors.len() > 0 {
            Err(&self.errors)
        } else {
            Ok(Root {
                expressions: children,
            })
        }
    }

    fn peek_variant(&self) -> Option<TokenKind> {
        self.stream.peek_variant()
    }

    fn peek_next_variant(&self) -> Option<TokenKind> {
        self.stream.peek_next_variant()
    }

    fn current_as_ref(&self) -> Option<&Lexeme<'_>> {
        self.stream.current_as_ref()
    }

    fn previous_as_ref(&self) -> Option<&Lexeme<'_>> {
        self.stream.previous_as_ref()
    }

    fn bump(&mut self) -> Option<Lexeme<'_>> {
        self.stream.next()
    }

    fn raise_error_at_previous(&mut self, message: &str, suggestion: Option<&str>) {
        let (line, line_span, absolute_span) = match self.previous_as_ref() {
            Some(l) => {
                let mut modified_span = l.get_line_span();
                modified_span.start += l.get_text().len() + 1;
                let absolute_span = l.get_absolute_span();
                (l.get_line(), modified_span, absolute_span)
            }
            None => (0, (0..0).into(), (0..0).into()),
        };

        self.raise_error(
            message,
            SyntaxLocation::new(line, line_span, absolute_span),
            suggestion,
        );
    }

    fn raise_error_at_current(&mut self, message: &str, suggestion: Option<&str>) {
        let (line, line_span, absolute_span) = match self.current_as_ref() {
            Some(l) => {
                let mut modified_span = l.get_line_span();
                modified_span.start += 1;

                (l.get_line(), modified_span, l.get_absolute_span())
            }
            None => (0, (0..0).into(), (0..0).into()),
        };

        self.raise_error(
            message,
            SyntaxLocation::new(line, line_span, absolute_span),
            suggestion,
        );
    }

    fn expect_kind_or_error(
        &mut self,
        kind: TokenKind,
        message: &str,
        suggestion: Option<&str>,
    ) -> Option<Lexeme<'_>> {
        let next_var = self.peek_variant();
        match next_var {
            Some(v) => {
                if v == kind {
                    self.stream.next()
                } else {
                    self.raise_error_at_current(message, suggestion);
                    None
                }
            }
            None => {
                self.raise_error_at_previous(message, suggestion);
                None
            }
        }
    }

    fn raise_error(&mut self, message: &str, location: SyntaxLocation, suggestion: Option<&str>) {
        self.errors
            .push(CompilerError::new(location, message, suggestion));
    }

    pub fn expression(&mut self) -> Option<Expression> {
        match self.peek_variant() {
            Some(variant) => match variant {
                TokenKind::IntegerLiteral | TokenKind::FloatLiteral => {
                    self.expression_binding_power(0)
                }
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
                TokenKind::LeftParenthesis => self.parenthesised_expression(),
                TokenKind::LetKeyword => self.declaration(),
                TokenKind::Identifier => self.identifier(),
                _ => {
                    self.raise_error_at_current(
                        format!(
                            "Unexpected token: '{}'",
                            self.current_as_ref().unwrap().get_text()
                        )
                        .as_str(),
                        Some("Consider removing this token."),
                    );
                    None
                }
            },
            None => None,
        }
    }

    fn declaration(&mut self) -> Option<Expression> {
        let let_keyword = self.bump();
        let line_start = let_keyword.unwrap().get_line_span().start;
        let absolute_start = let_keyword.unwrap().get_absolute_span().start;
        let (ident, line, line_end, absolute_end) = match self.expect_kind_or_error(
            TokenKind::Identifier,
            "Expected an identifier",
            None,
        ) {
            Some(ident) => (
                ident.get_text().to_string(),
                ident.get_line(),
                ident.get_line_span().end,
                ident.get_absolute_span().end,
            ),
            None => {
                return None;
            }
        };

        match self.peek_variant() {
            Some(v) => match v {
                TokenKind::Equals => {
                    let _ = self.bump();
                    Some(Expression::new(
                        ExpressionVariant::Declaration(Declaration::new(
                            ident,
                            match self.expression() {
                                Some(e) => Some(Box::from(e)),
                                None => None,
                            },
                        )),
                        SyntaxLocation::new(
                            line,
                            Span {
                                start: line_start,
                                end: line_end,
                            },
                            Span {
                                start: absolute_start,
                                end: absolute_end,
                            },
                        ),
                    ))
                }
                _ => Some(Expression::new(
                    ExpressionVariant::Declaration(Declaration::new(ident, None)),
                    SyntaxLocation::new(
                        line,
                        Span {
                            start: line_start,
                            end: line_end,
                        },
                        Span {
                            start: absolute_start,
                            end: absolute_end,
                        },
                    ),
                )),
            },
            None => Some(Expression::new(
                ExpressionVariant::Declaration(Declaration::new(ident, None)),
                SyntaxLocation::new(
                    line,
                    Span {
                        start: line_start,
                        end: line_end,
                    },
                    Span {
                        start: absolute_start,
                        end: absolute_end,
                    },
                ),
            )),
        }
    }

    fn identifier(&mut self) -> Option<Expression> {
        let ident = self.bump().unwrap();
        let (line, line_span, absolute_span) = (
            ident.get_line(),
            ident.get_line_span(),
            ident.get_absolute_span(),
        );
        Some(Expression::new(
            ExpressionVariant::Identifier(IdentifierExpression::new(ident.get_text().to_string())),
            SyntaxLocation::new(line, line_span, absolute_span),
        ))
    }

    fn expression_binding_power(&mut self, minimum_binding_power: u8) -> Option<Expression> {
        let mut left = self.left()?;
        let (left_line_span, left_absolute_span) = (left.get_line_span(), left.get_absolute_span());
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

            let (right_line_span, right_absolute_span) = match &right {
                Some(r) => (r.get_line_span(), r.get_absolute_span()),
                None => unreachable!("Right span match condition failed"),
            };

            left = Expression::new(
                ExpressionVariant::Binary(BinaryExpression::new(
                    Box::from(left),
                    operator,
                    Box::from(right.unwrap()),
                )),
                SyntaxLocation::new(
                    left_line,
                    Span {
                        start: left_line_span.start,
                        end: right_line_span.end,
                    },
                    Span {
                        start: left_absolute_span.start,
                        end: right_absolute_span.end,
                    },
                ),
            );
        }

        Some(left)
    }

    fn left(&mut self) -> Option<Expression> {
        let result = match self.peek_variant() {
            Some(variant) => match variant {
                TokenKind::IntegerLiteral
                | TokenKind::TrueLiteral
                | TokenKind::FalseLiteral
                | TokenKind::FloatLiteral => self.literal(),
                TokenKind::Minus | TokenKind::Plus => {
                    self.prefix_expression(PrefixOperator::Negation)
                }
                TokenKind::LeftParenthesis => self.parenthesised_expression(),
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
        let (line_span, absolute_span) = (
            literal_lexeme.get_line_span(),
            literal_lexeme.get_absolute_span(),
        );

        let literal_variant = match literal_lexeme.get_variant() {
            TokenKind::IntegerLiteral => {
                LiteralVariant::Integer(i64::from_str_radix(literal_lexeme.get_text(), 10).unwrap())
            }
            TokenKind::TrueLiteral => LiteralVariant::Boolean(true),
            TokenKind::FalseLiteral => LiteralVariant::Boolean(false),
            TokenKind::FloatLiteral => {
                LiteralVariant::Float(literal_lexeme.get_text().parse::<f64>().unwrap())
            }

            x => todo!("Unimplemented literal kind: {:#?}", x),
        };

        Some(Expression::new(
            ExpressionVariant::Literal(literal_variant),
            SyntaxLocation::new(literal_lexeme.get_line(), line_span, absolute_span),
        ))
    }

    fn prefix_expression(&mut self, operator: PrefixOperator) -> Option<Expression> {
        let (_, right_binding_power) = operator.binding_power();

        let marker = self.bump().unwrap();
        let (line, line_span, absolute_span) = (
            marker.get_line(),
            marker.get_line_span(),
            marker.get_absolute_span(),
        );

        Some(Expression::new(
            ExpressionVariant::Prefix(PrefixExpression::new(
                operator,
                Box::from(self.expression_binding_power(right_binding_power).unwrap()),
            )),
            SyntaxLocation::new(line, line_span, absolute_span),
        ))
    }

    fn parenthesised_expression(&mut self) -> Option<Expression> {
        let marker = self.bump().unwrap();
        let (line, line_span, absolute_span) = (
            marker.get_line(),
            marker.get_line_span(),
            marker.get_absolute_span(),
        );
        let result = Some(Expression::new(
            ExpressionVariant::Parenthesised(ParenthesisedExpression::new(Box::from(
                self.expression_binding_power(0).unwrap(),
            ))),
            SyntaxLocation::new(line, line_span, absolute_span),
        ));

        // Consume the right parenthesis
        let _ = self.expect_kind_or_error(
            TokenKind::RightParenthesis,
            "Expected a closing parenthesis",
            Some("Consider adding a closing parenthesis here."),
        );

        result
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
        expected.assert_eq(format!("{}", parser.parse().unwrap()).as_str())
    }

    fn expect_error(input: &str, expected_error: Expect) {
        let mut lexer = TokenKind::lexer(input);
        let token_stream = TokenStream::new(&mut lexer);
        let mut parser = Parser::new(token_stream);
        let _ = parser.parse();
        expected_error.assert_eq(
            parser
                .errors
                .get(0)
                .unwrap()
                .format_with_line(input)
                .as_str(),
        );
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

    #[test]
    fn expect_closing_parenthesis() {
        expect_error(
            "1 + (2 + 2",
            expect![[r#"
error: Expected a closing parenthesis (at line 1, position 11):

      |
    1 | 1 + (2 + 2
      |           ^ Consider adding a closing parenthesis here."#]],
        );
    }

    #[test]
    fn parse_float() {
        check_expression("1.0", expect![[r#"Float(1)"#]])
    }

    #[test]
    fn parse_float_with_non_zero_fraction() {
        check_expression("3.1", expect![[r#"Float(3.1)"#]])
    }

    #[test]
    fn parse_declaration_with_assignment() {
        check_expression(
            "let number = 123",
            expect![[r#"Declaration(number, Integer(123))"#]],
        )
    }

    #[test]
    fn parse_declaration_without_assignment() {
        check_expression("let number", expect![[r#"Declaration(number, None)"#]])
    }
}
