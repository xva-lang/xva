use xva_span::SourceSpan;

/// A single token produced by the lexer.
///
/// Contains a [`TokenKind`] as the variant, a [`SourceSpan`] indicating its span in the input text,
/// and a reference to the original text, with full-fidelity.
#[derive(Debug, Clone, PartialEq)]
pub struct Token<'src> {
    pub kind: TokenKind<'src>,
    pub span: SourceSpan,
    pub original: &'src str,
}

impl std::fmt::Display for Token<'_> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.kind)
    }
}

#[allow(dead_code)]
#[derive(Clone, Debug, PartialEq)]
pub enum TokenKind<'src> {
    // Literals
    Boolean(bool),
    Char(char),
    String(&'src str),
    Integer(i128),
    Float(f64),

    // Comments
    Comment(&'src str),
    DocComment(&'src str),

    // Symbols
    OpenParen,
    CloseParen,
    OpenBrace,
    CloseBrace,
    Colon,
    Comma,
    DoubleQuote,
    SingleQuote,
    Plus,
    Minus,
    Star,
    Slash,
    Percent,
    DoubleStar,
    Equals,
    LeftAngle,
    RightAngle,
    Increment,
    Decrement,
    Dot,
    Ampersand,
    Pipe,
    Caret,
    DoubleRightAngle,
    DoubleLeftAngle,
    GreaterThanEquals,
    LessThanEquals,
    DoubleEquals,
    NotEquals,
    And,
    Or,
    Not,

    /// Identifier
    Identifier(&'src str),

    /// Error token.
    ///
    /// Only contains a single character, error tokens should be collected at a later stage.
    CharError(char),

    /// Error token
    ///
    /// Contains multiple characters.
    Error(&'src str),
}

impl<'src> std::fmt::Display for TokenKind<'src> {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            TokenKind::Boolean(b) => write!(f, "'{b}'"),
            TokenKind::Char(c) => write!(f, "'{c}'"),
            TokenKind::String(s) => write!(f, "'{s}'"),
            TokenKind::Integer(i) => write!(f, "'{i}'"),
            TokenKind::Float(fl) => write!(f, "'{fl}'"),
            TokenKind::Comment(co) => write!(f, "'{co}'"),
            TokenKind::DocComment(dco) => write!(f, "'{dco}'"),
            TokenKind::OpenParen => write!(f, "'('"),
            TokenKind::CloseParen => write!(f, "')'"),
            TokenKind::OpenBrace => write!(f, "'{{'"),
            TokenKind::CloseBrace => write!(f, "'}}'"),
            TokenKind::Colon => write!(f, "':'"),
            TokenKind::Comma => write!(f, "','"),
            TokenKind::DoubleQuote => write!(f, "'\"'"),
            TokenKind::SingleQuote => write!(f, "'\''"),
            TokenKind::Plus => write!(f, "'+'"),
            TokenKind::Minus => write!(f, "'-'"),
            TokenKind::Star => write!(f, "'*'"),
            TokenKind::Slash => write!(f, "'/'"),
            TokenKind::Percent => write!(f, "'%'"),
            TokenKind::DoubleStar => write!(f, "'**'"),
            TokenKind::Equals => write!(f, "'='"),
            TokenKind::LeftAngle => write!(f, "'<'"),
            TokenKind::RightAngle => write!(f, "'>'"),
            TokenKind::Increment => write!(f, "'++'"),
            TokenKind::Decrement => write!(f, "'--'"),
            TokenKind::Dot => write!(f, "'.'"),
            TokenKind::Ampersand => write!(f, "'&'"),
            TokenKind::Pipe => write!(f, "'|'"),
            TokenKind::Caret => write!(f, "'^'"),
            TokenKind::DoubleRightAngle => write!(f, "'>>'"),
            TokenKind::DoubleLeftAngle => write!(f, "'<<'"),
            TokenKind::GreaterThanEquals => write!(f, "'>='"),
            TokenKind::LessThanEquals => write!(f, "'<='"),
            TokenKind::DoubleEquals => write!(f, "'=='"),
            TokenKind::NotEquals => write!(f, "'!='"),
            TokenKind::And => write!(f, "'and'"),
            TokenKind::Or => write!(f, "'or'"),
            TokenKind::Not => write!(f, "'not'"),

            TokenKind::Identifier(i) => write!(f, "'{i}"),
            TokenKind::CharError(err) => write!(f, "'{err}'"),
            TokenKind::Error(err) => write!(f, "'{err}'"),
        }
    }
}
