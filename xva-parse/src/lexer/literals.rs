use chumsky::{prelude::*, Parser};
use std::num::ParseIntError;

use super::{LexerError, LexerInput, TokenKind};

fn hex_pattern<'src>() -> impl Parser<'src, LexerInput<'src>, &'src str, LexerError<'src>> {
    any() // Match any char
        .filter(|c| match *c {
            '0'..='9' | 'a'..='f' | 'A'..='F' => true, // Filter to only valid hexadecimal characters
            _ => false,
        })
        .repeated() // Repeated N times
        .to_slice() // Collect (::<String> by inference)
}

fn unicode_sequence<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    let token = just('\\')
        .ignore_then(just('u'))
        .ignore_then(hex_pattern())
        .validate(|val, extra, emitter| match u32::from_str_radix(&val, 16) {
            Ok(uni) => match char::from_u32(uni) {
                Some(c) => TokenKind::Char(c),
                None => {
                    // emit_rich(
                    //     emitter,
                    //     extra.span(),
                    //     format!("`\\u{val}` is an invalid Unicode scalar value."),
                    // );

                    TokenKind::Error(extra.slice())
                }
            },
            Err(_) => {
                // emit_rich(
                //     emitter,
                //     extra.span(),
                //     format!("`{val}` is an invalid integer representation."),
                // );
                TokenKind::Error(extra.slice())
            }
        });
    token
}

fn ascii_sequence<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    just('\\') // Escape backslash (ignored)
        .ignore_then(
            just('\\')
                .or(just('/')) // Forward slash
                .or(just('"')) // Double quote
                .or(just('\'')) // Single quote
                .or(just('0').to('\0')) // Null char
                .or(just('n').to('\n')) // Line feed
                .or(just('r').to('\r')) // Carriage return
                .or(just('t').to('\t')), // Tab
        )
        .map(TokenKind::Char) // Map to type constructor
}

const BOOLEAN_TRUE: &str = "true";
const BOOLEAN_FALSE: &str = "false";
fn bool<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    just(BOOLEAN_TRUE)
        .or(just(BOOLEAN_FALSE))
        .map(|w| TokenKind::Boolean(w == BOOLEAN_TRUE))
}

fn char<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    let normal_char = any().filter(|c: &char| c.is_ascii()).map(TokenKind::Char);
    just('\'')
        .ignore_then(choice((unicode_sequence(), ascii_sequence(), normal_char)))
        .then_ignore(just('\''))
}

fn int<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    any()
        .filter(|c: &char| c.is_digit(10))
        .then(any().filter(|c: &char| c.is_digit(10)).repeated())
        .then(just('.').not())
        .ignored()
        .or(just('0').ignored())
        .to_slice()
        .map(|x: &str| x.parse::<i128>().unwrap())
        .map(TokenKind::Integer)
}

fn digits1<'src>() -> impl Parser<'src, &'src str, &'src str, LexerError<'src>> {
    chumsky::text::digits(10).at_least(1).to_slice()
}

fn dot<'src>() -> impl Parser<'src, &'src str, (), LexerError<'src>> {
    just('.').ignored()
}

fn maybe_dot<'src>() -> impl Parser<'src, &'src str, bool, LexerError<'src>> {
    dot().or_not().map(|x| x.is_some())
}

fn maybe_digits1<'src>() -> impl Parser<'src, &'src str, Option<&'src str>, LexerError<'src>> {
    digits1().or_not()
}

const HEX_PREFIX: &str = "0x";
fn hex_int<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    just(HEX_PREFIX)
        .ignore_then(hex_pattern())
        .map(|x| i128::from_str_radix(x, 16).unwrap())
        .map(TokenKind::Integer)
}

const OCTAL_PREFIX: &str = "0o";
fn octal_int<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    let octal_pattern = any()
        .filter(|c| match *c {
            '0'..='7' => true,
            _ => false,
        })
        .repeated()
        .to_slice();

    just(OCTAL_PREFIX)
        .ignore_then(octal_pattern)
        .map(|text| i128::from_str_radix(text, 8).unwrap())
        .map(TokenKind::Integer)
}

const BINARY_PREFIX: &str = "0b";
fn binary_int<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    let binary_pattern = any()
        .filter(|c| *c == '0' || *c == '1')
        .repeated()
        .to_slice();

    just(BINARY_PREFIX)
        .ignore_then(binary_pattern)
        .map(|text| i128::from_str_radix(text, 2).unwrap())
        .map(TokenKind::Integer)
}

fn hex_or_octal_or_binary_int<'src>(
) -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    choice((hex_int(), octal_int(), binary_int()))
}

fn float_or_int<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    digits1() // Any digit, at least 1
        .then(maybe_dot()) // Maybe a dot
        .then(maybe_digits1()) // Maybe any digit, at least 1
        .try_map_with(|((whole, dot), frac), _extra| {
            if !dot {
                // No dot, must be an int
                Ok(TokenKind::Integer(str::parse::<i128>(whole).unwrap()))
            } else {
                if let Some(frac) = frac {
                    // Dot found and fractional part found, must be a float
                    // Allocation below is super expensive
                    let mut temp = String::with_capacity(whole.len() + ".".len() + frac.len());
                    temp.push_str(whole);
                    temp.push('.');
                    temp.push_str(frac);

                    Ok(TokenKind::Float(str::parse::<f64>(temp.as_str()).unwrap()))
                } else {
                    // Dot found but no fractional part, still parses as a float.
                    Ok(TokenKind::Float(str::parse::<f64>(whole).unwrap()))
                }
            }
        })
}

fn float_dot_only<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    text::int(10)
        .then(just('.'))
        .map(|(text, _)| str::parse::<f64>(text).unwrap()) // `_` in closure param is the dot.
        .map(TokenKind::Float)
}

pub(crate) fn literal<'src>() -> impl Parser<'src, &'src str, TokenKind<'src>, LexerError<'src>> {
    choice((bool(), char(), hex_or_octal_or_binary_int(), float_or_int()))
}

#[derive(Debug)]
pub(crate) enum UnicodeError {
    ParseInt(ParseIntError),
    InvalidUnicode(u32),
}

#[cfg(test)]
mod tests {
    use crate::lexer::{lexer, tests::assert_single_no_errors, TokenKind};
    use chumsky::prelude::*;

    #[test]
    fn bool_true() {
        assert_single_no_errors("true", &TokenKind::Boolean(true))
    }

    #[test]
    fn bool_false() {
        assert_single_no_errors("false", &TokenKind::Boolean(false))
    }

    #[test]
    fn chars() {
        assert_single_no_errors("'c'", &TokenKind::Char('c'));
    }

    #[test]
    fn ascii_carriage_return() {
        assert_single_no_errors(r"'\r'", &TokenKind::Char('\r'))
    }

    #[test]
    fn ascii_tab() {
        assert_single_no_errors(r"'\t'", &TokenKind::Char('\t'))
    }

    #[test]
    fn ascii_line_feed() {
        assert_single_no_errors(r"'\n'", &TokenKind::Char('\n'))
    }

    #[test]
    fn ascii_null() {
        assert_single_no_errors(r"'\0'", &TokenKind::Char('\0'))
    }

    #[test]
    fn unicode_escapes() {
        assert_single_no_errors(r"'\u2502'", &TokenKind::Char('\u{2502}'));
    }

    #[test]
    fn invalid_unicode() {
        let input = r"'\u12ffff'";
        let (_, errs) = lexer().parse(input).into_output_errors();
        assert_eq!(errs.len(), 1);
    }

    #[test]
    fn int_zero() {
        assert_single_no_errors("0", &TokenKind::Integer(0));
    }

    #[test]
    fn int_one() {
        assert_single_no_errors("1", &TokenKind::Integer(1))
    }

    #[test]
    fn int_multi() {
        assert_single_no_errors("123", &TokenKind::Integer(123))
    }

    #[test]
    fn int_leading_zero() {
        assert_single_no_errors("0123", &TokenKind::Integer(123))
    }

    #[test]
    fn hex_int_zero() {
        assert_single_no_errors("0x0", &TokenKind::Integer(0));
    }

    #[test]
    fn hex_int_one() {
        assert_single_no_errors("0x1", &TokenKind::Integer(1))
    }

    #[test]
    fn hex_int_multi() {
        assert_single_no_errors("0x1aB", &TokenKind::Integer(427))
    }

    #[test]
    fn hex_int_leading_zero() {
        assert_single_no_errors("0x01Ab", &TokenKind::Integer(427))
    }

    #[test]
    fn octal_int_zero() {
        assert_single_no_errors("0o0", &TokenKind::Integer(0));
    }

    #[test]
    fn octal_int_one() {
        assert_single_no_errors("0o1", &TokenKind::Integer(1))
    }

    #[test]
    fn octal_int_multi() {
        assert_single_no_errors("0o123", &TokenKind::Integer(83))
    }

    #[test]
    fn octal_int_leading_zero() {
        assert_single_no_errors("0o0123", &TokenKind::Integer(83))
    }

    #[test]
    fn binary_int_zero() {
        assert_single_no_errors("0b0", &TokenKind::Integer(0));
    }

    #[test]
    fn binary_int_one() {
        assert_single_no_errors("0b1", &TokenKind::Integer(1))
    }

    #[test]
    fn binary_int_multi() {
        assert_single_no_errors("0b1010", &TokenKind::Integer(10))
    }

    #[test]
    fn binary_int_leading_zero() {
        assert_single_no_errors("0b01010", &TokenKind::Integer(10))
    }

    #[test]
    fn float_zero() {
        // let input = "0.0 0. 1.0 1. 1.2 1.2340 0.1234";
        // let (tokens, errs) = lexer().parse(input).into_output_errors();
        // println!("tokens: {tokens:#?}");
        // println!("erorrs: {errs:#?}");
        assert_single_no_errors("0.0", &TokenKind::Float(0.0));
    }

    #[test]
    fn float_zero_no_fraction() {
        assert_single_no_errors("0.", &TokenKind::Float(0.0))
    }

    #[test]
    fn float_one() {
        assert_single_no_errors("1.0", &TokenKind::Float(1.0))
    }

    #[test]
    fn float_one_no_fraction() {
        assert_single_no_errors("1.", &TokenKind::Float(1.))
    }

    #[test]
    fn float() {
        assert_single_no_errors("1.2", &TokenKind::Float(1.2))
    }

    #[test]
    fn float_multi() {
        assert_single_no_errors("1.2340", &TokenKind::Float(1.234))
    }

    #[test]
    fn float_leading_zero() {
        assert_single_no_errors("0.1234", &TokenKind::Float(0.1234))
    }
}
