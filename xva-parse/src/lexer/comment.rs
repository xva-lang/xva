use super::{LexerExtra, TokenKind};
use chumsky::prelude::*;
use internment::Intern;

const LINE_COMMENT_SYMBOL: &str = "//";
const DOC_COMMENT_SYMBOL: &str = "///";

pub(crate) fn comment<'src>() -> impl Parser<'src, &'src str, TokenKind, LexerExtra> {
    just(DOC_COMMENT_SYMBOL) // `///`, doc comment symbol has higher precedence
        .or(just(LINE_COMMENT_SYMBOL)) // `//`
        .then(any().and_is(just("\n").not()).repeated().to_slice()) // Then repeat until newline, into slice
        .map(|(sigil, content): (&str, &str)| match sigil {
            LINE_COMMENT_SYMBOL => TokenKind::Comment(Intern::new(content.into())),
            DOC_COMMENT_SYMBOL => TokenKind::DocComment(Intern::new(content.trim_start().into())),
            _ => unreachable!("Invalid comment start sequence"),
        })
}

#[cfg(test)]
mod tests {
    use internment::Intern;

    use crate::lexer::{tests::assert_single_no_errors, TokenKind};

    #[test]
    fn comment() {
        const TEST_CASE: &str = " This is a comment";
        let interned = Intern::new(TEST_CASE.into());
        assert_single_no_errors(
            format!("//{TEST_CASE}").as_str(),
            &TokenKind::Comment(interned),
        );
    }

    #[test]
    fn doc_comment() {
        const TEST_CASE: &str = "This is a doc comment";
        let interned = Intern::new(TEST_CASE.into());
        assert_single_no_errors(
            format!("///{TEST_CASE}").as_str(),
            &TokenKind::DocComment(interned),
        );
    }
}
