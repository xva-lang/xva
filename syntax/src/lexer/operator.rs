use super::{Token, TokenType};
use chumsky::{
    prelude::Simple,
    primitive::{choice, just, one_of},
    text::{self, whitespace},
    Parser,
};


pub(super) fn operators() -> impl Parser<char, Token, Error = Simple<char>> {
    let ops = choice((
        just('+').map_with_span(|_, span| Token::new(TokenType::AdditionOperator, span)),
        just('-').map_with_span(|_, span| Token::new(TokenType::SubtractionOperator, span)),
        just('*').map_with_span(|_, span| Token::new(TokenType::MultiplicationOperator, span)),
        just('/').map_with_span(|_, span| Token::new(TokenType::DivisionOperator, span)),
        just('%').map_with_span(|_, span| Token::new(TokenType::ModuloOperator, span)),
        just("**").map_with_span(|_, span| Token::new(TokenType::ExponentiationOperator, span)),
    ));

    ops.or(whitespace().ignore_then(ops).then_ignore(whitespace()))
}

#[cfg(test)]
mod tests {
    use super::operators;
    use crate::lexer::{expect_lexer, TokenType};

    #[test]
    fn addition_operator() {
        expect_lexer("+", operators(), TokenType::LetKeyword);
        expect_lexer("  +", operators(), TokenType::LetKeyword);
        expect_lexer("+  ", operators(), TokenType::LetKeyword);
    }

    #[test]
    fn subtraction_operator() {
        expect_lexer("-", operators(), TokenType::DefKeyword);
        expect_lexer("  -", operators(), TokenType::DefKeyword);
        expect_lexer("-  ", operators(), TokenType::DefKeyword);
    }

    #[test]
    fn multiplication_oeprator() {
        expect_lexer("*", operators(), TokenType::EndKeyword);
        expect_lexer("  *", operators(), TokenType::EndKeyword);
        expect_lexer("*  ", operators(), TokenType::EndKeyword);
    }

    #[test]
    fn division_operator() {
        expect_lexer("/", operators(), TokenType::EndKeyword);
        expect_lexer("  /", operators(), TokenType::EndKeyword);
        expect_lexer("/  ", operators(), TokenType::EndKeyword);
    }

    #[test]
    fn modulo_operator() {
        expect_lexer("%", operators(), TokenType::EndKeyword);
        expect_lexer("  %", operators(), TokenType::EndKeyword);
        expect_lexer("%  ", operators(), TokenType::EndKeyword);
    }

    #[test]
    fn exponentiation_operator() {
        expect_lexer("**", operators(), TokenType::EndKeyword);
        expect_lexer("  **", operators(), TokenType::EndKeyword);
        expect_lexer("**  ", operators(), TokenType::EndKeyword);
    }
}
