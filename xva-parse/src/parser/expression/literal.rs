use tree_sitter::Node;
use xva_ast::ast::{Expression, ExpressionKind, LiteralIntegerKind, LiteralKind};

use crate::parser::error::{ParserError, ParserResult, TextParseError};

use super::Parser;

const LIT_KIND_INTEGER: &str = "integer_literal";
const LIT_KIND_INTEGER_DECIMAL: &str = "decimal_literal";
const LIT_KIND_INTEGER_BINARY: &str = "binary_literal";
const LIT_KIND_INTEGER_OCTAL: &str = "octal_literal";
const LIT_KIND_INTEGER_HEX: &str = "hex_literal";

const PREFIX_BINARY: &str = "0b";
const PREFIX_OCTAL: &str = "0o";
const PREFIX_HEX: &str = "0x";

const RADIX_BINARY: u32 = 2;
const RADIX_OCTAL: u32 = 8;
const RADIX_HEX: u32 = 16;

impl Parser {
    pub(crate) fn literal(&self, root: Node<'_>) -> ParserResult<Expression> {
        let mut cursor = root.walk();
        cursor.goto_first_child();
        match cursor.node().kind() {
            LIT_KIND_INTEGER => {
                cursor.goto_first_child();
                match cursor.node().kind() {
                    LIT_KIND_INTEGER_DECIMAL => Ok(Expression {
                        id: (cursor.node().id() as u32).into(),
                        kind: ExpressionKind::Literal(node_text_into_decimal_literal(
                            self.current_source.as_bytes(),
                            cursor.node(),
                        )?),
                    }),

                    LIT_KIND_INTEGER_BINARY => Ok(Expression {
                        id: (cursor.node().id() as u32).into(),
                        kind: ExpressionKind::Literal(node_text_into_radix_literal(
                            self.current_source.as_bytes(),
                            cursor.node(),
                            RADIX_BINARY,
                        )?),
                    }),

                    LIT_KIND_INTEGER_OCTAL => Ok(Expression {
                        id: (cursor.node().id() as u32).into(),
                        kind: ExpressionKind::Literal(node_text_into_radix_literal(
                            self.current_source.as_bytes(),
                            cursor.node(),
                            RADIX_OCTAL,
                        )?),
                    }),

                    LIT_KIND_INTEGER_HEX => Ok(Expression {
                        id: (cursor.node().id() as u32).into(),
                        kind: ExpressionKind::Literal(node_text_into_radix_literal(
                            self.current_source.as_bytes(),
                            cursor.node(),
                            RADIX_HEX,
                        )?),
                    }),

                    x => panic!("Unknown integer literal variant: {x}"),
                }
            }
            x => panic!("Unknown literal variant: {x}"),
        }
    }
}

fn node_text_into_decimal_literal(src: &[u8], node: Node<'_>) -> ParserResult<LiteralKind> {
    let text = match node.utf8_text(src) {
        Ok(r) => r,
        Err(e) => return Err(ParserError::Utf8Error(e)),
    };

    let integer = match text.parse::<u128>() {
        Ok(i) => i,
        Err(e) => {
            return Err(ParserError::TextParseError(TextParseError::ParseIntError(
                e,
            )))
        }
    };

    Ok(LiteralKind::Integer(integer, LiteralIntegerKind::Signed))
}

fn node_text_into_radix_literal(
    src: &[u8],
    node: Node<'_>,
    radix: u32,
) -> ParserResult<LiteralKind> {
    let prefix = match radix {
        RADIX_BINARY => PREFIX_BINARY,
        RADIX_HEX => PREFIX_HEX,
        RADIX_OCTAL => PREFIX_OCTAL,
        _ => {
            return Err(ParserError::TextParseError(TextParseError::InvalidRadix(
                radix,
            )))
        }
    };

    let text = match node.utf8_text(src) {
        Ok(r) => r,
        Err(e) => return Err(ParserError::Utf8Error(e)),
    };

    let integer = match u128::from_str_radix(&text.replace(prefix, ""), radix) {
        Ok(i) => i,
        Err(e) => {
            return Err(ParserError::TextParseError(TextParseError::ParseIntError(
                e,
            )))
        }
    };

    Ok(LiteralKind::Integer(integer, LiteralIntegerKind::Signed))
}
