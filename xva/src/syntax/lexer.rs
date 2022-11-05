pub(crate) mod language;
pub(super) mod lexeme;
pub(crate) mod span;
pub(crate) mod token_stream;
use token_stream::*;

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
}
