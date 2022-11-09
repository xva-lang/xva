pub(crate) mod language;
pub(super) mod lexeme;
pub(crate) mod span;
pub(crate) mod token_stream;

#[allow(dead_code)]
pub mod utils;

// pub(crate) fn lex(input: &str) -> (Lexer<TokenKind>, String) {
//     let new_string = String::from(input);
//     (TokenKind::lexer(input), new_string)
// }

#[cfg(test)]
mod tests {
    use super::{language::TokenKind, token_stream::TokenStream};
    use expect_test::{expect, Expect};
    use logos::Logos;

    fn check_lex(input: &str, expected_tree: Expect) {
        let mut lexer = TokenKind::lexer(input);
        let token_stream = TokenStream::new(&mut lexer);
        expected_tree.assert_eq(format!("{}", token_stream).as_str());
    }

    #[test]
    fn lex_integer() {
        check_lex("123", expect![[r#"IntegerLiteral@[1:0..3] "123""#]])
    }

    #[test]
    fn lex_plus() {
        check_lex("+", expect![[r#"Plus@[1:0..1] "+""#]])
    }

    #[test]
    fn lex_minus() {
        check_lex("-", expect![[r#"Minus@[1:0..1] "-""#]])
    }

    #[test]
    fn lex_star() {
        check_lex("*", expect![[r#"Star@[1:0..1] "*""#]])
    }

    #[test]
    fn lex_slash() {
        check_lex("/", expect![[r#"Slash@[1:0..1] "/""#]])
    }

    #[test]
    fn lex_identifier() {
        check_lex("number", expect![[r#"Identifier@[1:0..6] "number""#]]);
    }

    #[test]
    fn lex_equals() {
        check_lex("=", expect![[r#"Equals@[1:0..1] "=""#]])
    }

    #[test]
    fn lex_let_keyword() {
        check_lex("let", expect![[r#"LetKeyword@[1:0..3] "let""#]]);
    }

    #[test]
    fn lex_float() {
        check_lex("1.0", expect![[r#"FloatLiteral@[1:0..3] "1.0""#]])
    }

    #[test]
    fn lex_float_non_zero_fraction() {
        check_lex("2.1", expect![[r#"FloatLiteral@[1:0..3] "2.1""#]])
    }

    #[test]
    fn lex_float_multiple_zeroes() {
        check_lex("3.000", expect![[r#"FloatLiteral@[1:0..5] "3.000""#]])
    }

    #[test]
    fn lex_float_multiple_zeroes_with_one() {
        check_lex("3.001", expect![[r#"FloatLiteral@[1:0..5] "3.001""#]])
    }

    #[test]
    fn lex_float_positive_lower_e() {
        check_lex("1.5e6", expect![[r#"FloatLiteral@[1:0..5] "1.5e6""#]])
    }

    #[test]
    fn lex_float_positive_upper_e() {
        check_lex("1.5E6", expect![[r#"FloatLiteral@[1:0..5] "1.5E6""#]])
    }

    #[test]
    fn lex_float_negative_lower_e() {
        check_lex("1.5e-7", expect![[r#"FloatLiteral@[1:0..6] "1.5e-7""#]])
    }

    #[test]
    fn lex_float_negative_upper_e() {
        check_lex("1.5E-7", expect![[r#"FloatLiteral@[1:0..6] "1.5E-7""#]])
    }

    #[test]
    fn lex_mutable_keyword() {
        check_lex("mutable", expect![[r#"MutableKeyword@[1:0..7] "mutable""#]])
    }
}
