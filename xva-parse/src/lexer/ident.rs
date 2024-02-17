use super::{LexerError, LexerInput, LexerOutput, TokenKind};
use chumsky::prelude::*;

pub(crate) fn ident_or_keyword<'src>(
) -> impl Parser<'src, LexerInput<'src>, TokenKind<'src>, LexerError<'src>> {
    text::ident().map(TokenKind::Identifier) //.and_is(keyword().not()) TODO
}
