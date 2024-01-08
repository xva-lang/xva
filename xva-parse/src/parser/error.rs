use std::{num::ParseIntError, str::Utf8Error};

use tree_sitter::LanguageError;

pub type ParserResult<T> = Result<T, ParserError>;

#[derive(Debug)]
pub enum ParserError {
    Utf8Error(Utf8Error),
    TextParseError(TextParseError),
    TSLanguageError(LanguageError),
}

#[derive(Debug)]
pub enum TextParseError {
    ParseIntError(ParseIntError),
    InvalidRadix(u32),
}
