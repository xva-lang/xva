use logos::Logos;
use num_derive::{FromPrimitive, ToPrimitive};
use num_traits::{FromPrimitive, ToPrimitive};

#[derive(
    Debug, Copy, Clone, PartialEq, Logos, FromPrimitive, Ord, PartialOrd, Eq, ToPrimitive, Hash,
)]
pub enum SyntaxKind {
    #[regex("[ \n\t]+")]
    Whitespace,

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

    Literal,

    #[regex("[0-9]+")]
    IntegerLiteral,

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

impl SyntaxKind {
    /// Detects if a `SyntaxKind` is a trivia item - that is, it is not compiled.
    ///
    /// Thanks Roslyn!
    pub(crate) fn is_trivia(self) -> bool {
        matches!(self, Self::Whitespace | Self::Comment)
    }
}

#[derive(Debug, Copy, Clone, Ord, PartialOrd, Eq, PartialEq, Hash)]
pub enum XvaLanguage {}

impl rowan::Language for XvaLanguage {
    type Kind = SyntaxKind;

    fn kind_from_raw(raw: rowan::SyntaxKind) -> Self::Kind {
        Self::Kind::from_u16(raw.0).unwrap()
    }

    fn kind_to_raw(kind: Self::Kind) -> rowan::SyntaxKind {
        rowan::SyntaxKind(kind.to_u16().unwrap())
    }
}
