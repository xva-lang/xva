use crate::utils::intern_str;

use super::{LexerError, LexerInput, TokenKind};
use chumsky::prelude::*;

pub(crate) fn ident_or_keyword<'src>() -> impl Parser<'src, LexerInput<'src>, TokenKind, LexerError>
{
    text::ident().map(|ident| TokenKind::Identifier(intern_str(ident))) //.and_is(keyword().not()) TODO
}
