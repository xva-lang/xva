use crate::utils::intern_str;

use super::{LexerError, TokenKind};
use chumsky::prelude::*;

pub(crate) fn ident_or_keyword<'src>() -> impl Parser<'src, &'src str, TokenKind, LexerError> {
    text::ident().map(|ident| TokenKind::Identifier(intern_str(ident))) //.and_is(keyword().not()) TODO
}
