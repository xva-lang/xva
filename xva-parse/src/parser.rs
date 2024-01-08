pub mod error;
mod expression;

use tree_sitter::{Tree, TreeCursor};
use xva_ast::{
    ast::Brick,
    ast::{Item, ItemKind, Module},
    node_id::NodeId,
};
use xva_span::SourceLocation;

use error::ParserResult;

// #[derive(Debug)]
pub struct Parser {
    cst: tree_sitter::Tree,
    current_source: String,
}

// lazy_static! {
//     // static ref NODE_ID_GEN: Arc<NodeId> = Arc::new(NodeId(0));
// }

impl Parser {
    pub(crate) fn new_from_str(input: &str) -> ParserResult<Self> {
        let mut parser = tree_sitter::Parser::new();
        if let Err(e) = parser.set_language(xva_treesitter::language()) {
            return Err(error::ParserError::TSLanguageError(e));
        };

        let tree = parser.parse(input, None).unwrap();
        let result = Parser {
            current_source: input.to_string(), // expensive
            cst: tree,
        };

        Ok(result)
    }

    pub fn brick(&mut self) -> ParserResult<Brick> {
        let module = self.brick_module()?;
        Ok(Brick {
            items: vec![Item {
                id: 0.into(),
                kind: ItemKind::Module(module),
                span: SourceLocation::new(
                    self.tree().root_node().start_position().into(),
                    self.tree().root_node().end_position().into(),
                ),
            }],
        })
    }

    fn brick_module(&self) -> ParserResult<Module> {
        let mut cursor = self.cst.root_node().walk();
        let mut items = vec![];

        for node in cursor.node().children(&mut cursor) {
            match node.kind() {
                "expression" => items.push(self.expression(node)?),
                _ => panic!("unknown node '{}'", node.kind()),
            }
        }

        Ok(Module { items })
    }

    pub(crate) fn tree(&self) -> &Tree {
        &self.cst
    }
}

#[cfg(test)]
mod tests {
    use super::Parser;

    #[test]
    fn parse() {
        let mut parser = Parser::new_from_str(
            r"
1
0b1
0o1
0x1",
        )
        .unwrap();
        let brick = parser.brick();
        println!("{brick:#?}")
    }
}
