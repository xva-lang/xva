use nom::{
    branch::alt,
    // bytes::complete::is_a,
    character::{
        complete::digit1,
        complete::{hex_digit1, oct_digit1, space0},
    },
    combinator::map,
    multi::{many0, many1},
    sequence::{delimited, preceded},
    IResult,
};

use nom::bytes::complete::tag;
use std::str;
use std::str::FromStr;

#[cfg(test)]
#[allow(dead_code)]
mod tests;

pub mod token;
pub mod token_stream;
use token::TokenKind;

#[derive(Clone)]
pub struct Lexer {
    input: String,
    // start: usize,
    // end: usize,
    // accept_literal: bool,
}

#[allow(dead_code)]
impl Lexer {
    pub fn new(input: &str) -> Lexer {
        Lexer {
            input: String::from(input),
            // start: 0,
            // end: input.len(),
            // accept_literal: true, // tokens: vec![],
        }
    }

    pub fn lex(&self) -> Vec<TokenKind> {
        let result = many0(alt((Self::integer, Self::operator)))(self.input.as_str());

        match result {
            Ok(v) => {
                let (_, vec) = v;
                let cloned_vec = vec.clone();
                for item in vec {
                    dbg!(item);
                }

                return cloned_vec;
            }
            Err(_) => panic!(""),
        }
    }

    // fn parse_enum(parsed_num: &str) -> Expr {
    //     let num = f32::from_str(parsed_num).unwrap();
    //     ENum(num)
    // }

    // fn parse_number(input: &str) -> IResult<&str, Expr> {
    //     map(delimited(space0, digit1, space0), parse_enum)(input)
    // }

    // fn unwrap_number_from_sign
    // fn hex_number(input: &str) -> IResult<&str, TokenKind> {
    //     map(preceded(tag("0x"), hex_digit1::<&str, ErrorKind>), |v| println!("{}", v))(input);
    //     Ok(("", TokenKind::Integer(0)))
    // }

    fn lex_one(input: &str) -> IResult<&str, &str> {
        tag("1")(input)
    }

    fn lex_zero(input: &str) -> IResult<&str, &str> {
        tag("0")(input)
    }

    fn unwrap_binary_number(input: &str) -> IResult<&str, String> {
        let rest: &str;
        let result = many1(alt((Self::lex_zero, Self::lex_one)))(input);
        let vec = match result {
            Ok((r, v)) => {
                rest = r;
                v
            }
            Err(_) => panic!("Couldn't unpack"),
        };
        let mut owned_string = String::new();
        for item in vec {
            owned_string.push_str(item);
        }

        Ok((rest, owned_string))
    }

    fn unwrap_with_radix(input: &str, radix: u32) -> TokenKind {
        TokenKind::Integer(i64::from_str_radix(input, radix).unwrap())
    }

    pub fn integer(input: &str) -> IResult<&str, TokenKind> {
        //! Matches decimal, hexadecimal, octal and binary numbers. Decimal numbers can optionally be
        //! preceded by a `+` or `-`
        alt((
            map(preceded(tag("+"), digit1), |v| {
                TokenKind::Integer(i64::from_str(v).unwrap())
            }),
            map(preceded(tag("-"), digit1), |v| {
                TokenKind::Integer(i64::from_str(v).unwrap() * -1)
            }),
            map(preceded(tag("0x"), hex_digit1), |v| {
                Self::unwrap_with_radix(v, 16)
            }),
            map(preceded(tag("0b"), Self::unwrap_binary_number), |v| {
                Self::unwrap_with_radix(v.as_str(), 2)
            }),
            map(preceded(tag("0o"), oct_digit1), |v| {
                Self::unwrap_with_radix(v, 8)
            }),
            map(digit1, |v| TokenKind::Integer(i64::from_str(v).unwrap())),
        ))(input)
    }

    fn operator(input: &str) -> IResult<&str, TokenKind> {
        alt((
            // map(tag("*"), |_| TokenKind::Multiply),
            // map(tag("/"), |_| TokenKind::Divide),
            map(alt((tag("+"), delimited(space0, tag("+"), space0))), |_| {
                TokenKind::Add
            }),
            map(alt((tag("-"), delimited(space0, tag("-"), space0))), |_| {
                TokenKind::Subtract
            }),
            // map(tag("%"), |_| TokenKind::Remainder),
        ))(input)
    }

    // fn add_operator(input: &[u8]) -> IResult<&[u8], TokenKind> {}
}
