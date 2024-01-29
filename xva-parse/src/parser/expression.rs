use tree_sitter::Node;
use xva_ast::ast::Expression;

use crate::strings;

use super::{error::ParserResult, Parser};

mod binary;
mod literal;
mod unary;

strings! {
    EXPR_KIND_LITERAL = "literal"
    EXPR_KIND_UNARY = "unary_expression"
    EXPR_KIND_BINARY = "binary_expression"
}

impl<'p> Parser<'p> {
    pub(crate) fn expression(&self, root: Node<'_>) -> ParserResult<Expression> {
        let mut cursor = root.walk();
        cursor.goto_first_child();
        match cursor.node().kind() {
            EXPR_KIND_LITERAL => Ok(self.literal(cursor.node())?),
            EXPR_KIND_UNARY => Ok(self.unary(cursor.node())?),
            EXPR_KIND_BINARY => Ok(self.binary(cursor.node())?),
            x => panic!("Unknown expression variant: {x}"),
        }
    }
}
