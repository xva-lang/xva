use crate::utils::intern_str;

use super::{LexerExtra, TokenKind};
use chumsky::prelude::*;

pub(crate) fn ident_or_keyword<'src>() -> impl Parser<'src, &'src str, TokenKind, LexerExtra> {
    text::ident().map(|ident| TokenKind::Identifier(intern_str(ident))) //.and_is(keyword().not()) TODO
}
