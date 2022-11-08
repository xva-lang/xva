use super::{
    ast::{
        expression::{
            BinaryExpression, Expression, ExpressionVariant, ParenthesisedExpression,
            PrefixExpression,
        },
        literal::LiteralVariant,
        operator::{BindingPowered, InfixOperator, PrefixOperator},
        root::Root,
    },
    lexer::{language::TokenKind, lexeme::Lexeme},
    lexer::{span::Span, token_stream::TokenStream},
};

pub(crate) struct Parser<'stream, 'input> {
    stream: TokenStream<'stream>,
    errors: Vec<String>,
    original_lines: Vec<&'input str>,
}

impl<'stream, 'input> Parser<'stream, 'input> {
    pub fn new(stream: TokenStream<'stream>, original_lines: Vec<&'input str>) -> Self {
        Self {
            stream,
            errors: vec![],
            original_lines,
        }
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
        let (line, span) = match self.previous_as_ref() {
            Some(l) => {
                let mut modified_span = l.get_line_span();
                modified_span.start += l.get_text().len() + 1;
                (l.get_line(), modified_span)
            }
            None => (0, (0..0).into()),
        };

        self.raise_error(message, line, span, suggestion);
    }

    fn raise_error_at_current(&mut self, message: &str, suggestion: Option<&str>) {
        let (line, span) = match self.current_as_ref() {
            Some(l) => {
                let mut modified_span = l.get_line_span();
                modified_span.start += 1;
                (l.get_line(), modified_span)
            }
            None => (0, (0..0).into()),
        };

        self.raise_error(message, line, span, suggestion);
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

    fn raise_error(&mut self, message: &str, line: usize, span: Span, suggestion: Option<&str>) {
        let error_line = match suggestion {
            Some(s) => format!(
                "      |\n    1 | {}\n      |{}^ {}",
                self.original_lines[line - 1],
                " ".repeat(span.start),
                s
            ),
            None => format!(
                "      |\n    1 | {}\n      |{}^",
                self.original_lines[line],
                " ".repeat(span.start)
            ),
        };

        self.errors.push(format!(
            "error: {message} (at line {line}, position {}):\n\n{}",
            span.start, error_line
        ))
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
                TokenKind::LeftParenthesis => self.parenthesised_expression(),
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

    fn parenthesised_expression(&mut self) -> Option<Expression> {
        let marker = self.bump().unwrap();
        let (line, span) = (marker.get_line(), marker.get_line_span());
        let result = Some(Expression::new(
            ExpressionVariant::Parenthesised(ParenthesisedExpression::new(Box::from(
                self.expression_binding_power(0).unwrap(),
            ))),
            line,
            span,
        ));

        // Consume the right parenthesis
        let _ = self.expect_kind_or_error(
            TokenKind::RightParenthesis,
            "Expected a closing parenthesis",
            Some("Consider adding a closing parenthesis here."),
        );

        result
    }

    pub(crate) fn get_errors(&self) -> &Vec<String> {
        &self.errors
    }
}

#[cfg(test)]
mod tests {
    use super::Parser;
    use crate::syntax::lexer::{self, language::TokenKind, token_stream::TokenStream};
    use expect_test::{expect, Expect};
    use logos::Logos;

    fn check_expression(input: &str, expected: Expect) {
        let original_lines = lexer::utils::input_lines_as_vec(input);
        let mut lexer = TokenKind::lexer(input);
        let token_stream = TokenStream::new(&mut lexer);
        let mut parser = Parser::new(token_stream, original_lines);

        expected.assert_eq(format!("{}", parser.parse()).as_str())
    }

    fn expect_error(input: &str, expected_error: Expect) {
        let original_lines = lexer::utils::input_lines_as_vec(input);
        let mut lexer = TokenKind::lexer(input);
        let token_stream = TokenStream::new(&mut lexer);
        let mut parser = Parser::new(token_stream, original_lines);
        let _ = parser.parse();
        expected_error.assert_eq(parser.errors.get(0).unwrap());
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
}
