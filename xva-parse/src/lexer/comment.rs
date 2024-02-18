use super::{LexerError, TokenKind, TokenSpan};
use chumsky::prelude::*;

const LINE_COMMENT_SYMBOL: &str = "//";
const DOC_COMMENT_SYMBOL: &str = "///";

pub(crate) fn comment<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    just(DOC_COMMENT_SYMBOL) // `///`, doc comment symbol has higher precedence
        .or(just(LINE_COMMENT_SYMBOL)) // `//`
        .then(any().and_is(just("\n").not()).repeated().to_slice()) // Then repeat until newline, into slice
        .map(|(sigil, content)| match sigil {
            LINE_COMMENT_SYMBOL => TokenKind::Comment(content),
            DOC_COMMENT_SYMBOL => TokenKind::DocComment(content.trim_start()),
            _ => unreachable!("Invalid comment start sequence"),
        })
}

#[cfg(test)]
mod tests {
    use crate::lexer::{tests::assert_single_no_errors, TokenKind};

    #[test]
    fn comment() {
        assert_single_no_errors(
            "// This is a comment",
            &TokenKind::Comment(" This is a comment"),
        );
    }

    #[test]
    fn doc_comment() {
        assert_single_no_errors(
            "/// This is a doc comment",
            &TokenKind::DocComment("This is a doc comment"),
        );
    }
}
