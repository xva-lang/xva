use tree_sitter::Node;
use xva_ast::ast::{Expression, ExpressionKind, LiteralIntegerKind, LiteralKind};

use crate::{
    parser::error::{ParserError, ParserResult, TextParseError},
    strings,
    traits::TSIdentifyable,
};

use super::Parser;

strings! {
    LIT_KIND_INTEGER = "integer_literal"
    LIT_KIND_BOOLEAN  = "boolean_literal"
    LIT_KIND_FLOAT = "float_literal"
    LIT_KIND_CHAR = "character_literal"
    LIT_KIND_STRING = "string_literal"

    LIT_KIND_INTEGER_DECIMAL = "decimal_literal"
    LIT_KIND_INTEGER_BINARY = "binary_literal"
    LIT_KIND_INTEGER_OCTAL = "octal_literal"
    LIT_KIND_INTEGER_HEX = "hex_literal"

    LIT_TRUE = "true"
    LIT_FALSE = "false"

    PREFIX_BINARY = "0b"
    PREFIX_OCTAL = "0o"
    PREFIX_HEX = "0x"
}

const RADIX_BINARY: u32 = 2;
const RADIX_OCTAL: u32 = 8;
const RADIX_HEX: u32 = 16;

impl<'p> Parser<'p> {
    pub(crate) fn literal(&self, root: Node<'_>) -> ParserResult<Expression> {
        let source = self.source().unwrap();
        let source_bytes = source.bytes();
        let mut cursor = root.walk();
        cursor.goto_first_child();

        match cursor.node().kind() {
            LIT_KIND_INTEGER => {
                cursor.goto_first_child();
                let node_kind = cursor.node().kind();

                match node_kind {
                    LIT_KIND_INTEGER_DECIMAL => Ok(Expression {
                        id: cursor.node_id(),
                        kind: ExpressionKind::Literal(node_text_into_decimal_literal(
                            source_bytes,
                            cursor.node(),
                        )?),
                        span: cursor.node().byte_range(),
                    }),

                    LIT_KIND_INTEGER_BINARY | LIT_KIND_INTEGER_OCTAL | LIT_KIND_INTEGER_HEX => {
                        Ok(Expression {
                            id: cursor.node_id(),
                            kind: ExpressionKind::Literal(node_text_into_radix_literal(
                                source_bytes,
                                cursor.node(),
                                match node_kind {
                                    LIT_KIND_INTEGER_BINARY => RADIX_BINARY,
                                    LIT_KIND_INTEGER_OCTAL => RADIX_OCTAL,
                                    LIT_KIND_INTEGER_HEX => RADIX_HEX,
                                    _ => unreachable!(),
                                },
                            )?),
                            span: cursor.node().byte_range(),
                        })
                    }

                    x => panic!("Unknown integer literal variant: {x}"),
                }
            }

            LIT_KIND_BOOLEAN => {
                cursor.goto_first_child();
                match cursor.node().utf8_text(source_bytes) {
                    Ok(t) => match t {
                        LIT_TRUE | LIT_FALSE => Ok(Expression {
                            id: cursor.node_id(),
                            kind: ExpressionKind::Literal(node_text_into_boolean_literal(
                                source_bytes,
                                cursor.node(),
                            )?),
                            span: cursor.node().byte_range(),
                        }),
                        _ => unreachable!(),
                    },
                    Err(e) => return Err(ParserError::Utf8Error(e)),
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

fn node_text_into_boolean_literal(src: &[u8], node: Node<'_>) -> ParserResult<LiteralKind> {
    let text = match node.utf8_text(src) {
        Ok(r) => r,
        Err(e) => return Err(ParserError::Utf8Error(e)),
    };

    match text {
        LIT_TRUE => Ok(LiteralKind::Boolean(true)),
        LIT_FALSE => Ok(LiteralKind::Boolean(false)),
        _ => unreachable!(),
    }
}

#[cfg(test)]
mod tests {
    use crate::parser::Parser;

    fn no_errors(input: &str) {
        let mut parser = Parser::new_from_str(input).unwrap();
        let _ = parser.brick().unwrap();
    }

    #[test]
    fn decimal_literal() {
        no_errors("123")
    }

    #[test]
    fn binary_literal() {
        no_errors("0b1011")
    }

    #[test]
    fn octal_literal() {
        no_errors("0o123456")
    }

    #[test]
    fn hex_literal() {
        no_errors("0x12AB")
    }

    #[test]
    fn true_literal() {
        no_errors("true")
    }

    #[test]
    fn false_literal() {
        no_errors("false")
    }

    #[test]
    fn errors() {
        let mut parser = Parser::new_from_str(r"\u5FFF").unwrap();
        let _ = parser.brick().unwrap();
    }
}
