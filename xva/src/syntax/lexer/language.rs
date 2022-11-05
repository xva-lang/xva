use logos::Logos;
use num_derive::{FromPrimitive, ToPrimitive};

#[derive(
    Debug, Copy, Clone, PartialEq, Logos, FromPrimitive, Ord, PartialOrd, Eq, ToPrimitive, Hash,
)]
pub enum TokenKind {
    #[regex("[ \t]+")]
    Whitespace,

    #[regex("\n+")]
    Newline,

    #[token("def")]
    DefKeyword,

    #[token("let")]
    LetKeyword,

    #[regex("[A-Za-z_][A-Za-z0-9_]*!?")]
    Identifier,

    Operator,

    #[token("+")]
    Plus,

    #[token("-")]
    Minus,

    #[token("*")]
    Star,

    #[token("/")]
    Slash,

    #[token("=")]
    Equals,

    #[token("(")]
    LeftParenthesis,

    #[token(")")]
    RightParenthesis,

    #[token(":")]
    Colon,

    Literal,

    #[regex("[0-9]+")]
    IntegerLiteral,

    #[token("true")]
    TrueLiteral,

    #[token("false")]
    FalseLiteral,

    #[regex("//.*")]
    Comment,

    IdentifierExpression,
    BinaryExpression,
    PrefixExpression,
    ParenthesisedExpression,
    Declaration,

    #[error]
    Error,

    Root,
}
