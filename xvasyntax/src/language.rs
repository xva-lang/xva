use logos::Logos;
use num_derive::{FromPrimitive, ToPrimitive};

#[derive(
    Debug, Copy, Clone, PartialEq, Logos, FromPrimitive, Ord, PartialOrd, Eq, ToPrimitive, Hash,
)]
pub(crate) enum SyntaxKind {
    #[regex(" +")]
    Whitespace,

    #[token("def")]
    DefKeyword,

    #[token("let")]
    LetKeyword,

    #[regex("[A-Za-z_][A-Za-z0-9_]*!?")]
    Identifier,

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

    #[regex("[0-9]+")]
    IntegerLiteral,

    BinaryExpression,
    PrefixExpression,
    ParenthesisedExpression,

    #[error]
    Error,

    Root,
}

use num_traits::{FromPrimitive, ToPrimitive};

#[derive(Debug, Copy, Clone, Ord, PartialOrd, Eq, PartialEq, Hash)]
pub(crate) enum XvaLanguage {}

impl rowan::Language for XvaLanguage {
    type Kind = SyntaxKind;

    fn kind_from_raw(raw: rowan::SyntaxKind) -> Self::Kind {
        Self::Kind::from_u16(raw.0).unwrap()
    }

    fn kind_to_raw(kind: Self::Kind) -> rowan::SyntaxKind {
        rowan::SyntaxKind(kind.to_u16().unwrap())
    }
}
