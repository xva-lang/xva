use tree_sitter::Node;
use xva_ast::ast::{Item, ItemKind};
use xva_span::SourceLocation;

use super::{error::ParserResult, Parser};

mod literal;

const EXPR_KIND_LITERAL: &str = "literal";

impl<'p> Parser<'p> {
    pub(crate) fn expression(&self, root: Node<'_>) -> ParserResult<Item> {
        let mut cursor = root.walk();
        cursor.goto_first_child();
        match cursor.node().kind() {
            EXPR_KIND_LITERAL => Ok(Item {
                id: (cursor.node().id() as u32).into(),
                kind: ItemKind::Expression(self.literal(cursor.node())?),
                span: SourceLocation::new(
                    cursor.node().start_position().into(),
                    cursor.node().end_position().into(),
                ),
            }),
            x => panic!("Unknown expression variant: {x}"),
        }
    }
}
