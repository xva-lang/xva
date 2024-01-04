use std::{error::Error, io::Read, path::PathBuf};

use tree_sitter::{Node, Tree};
use xva_ast::{
    ast::Brick,
    ast::{Item, ItemKind, Module},
    node_id::NodeId,
};
use xva_span::SourceLocation;

use self::error::ParserResult;

mod error;
mod expression;

// #[derive(Debug)]
pub struct Parser {
    cst: tree_sitter::Tree,
    current_source: String,
    current_node_id: NodeId,
}

// lazy_static! {
//     // static ref NODE_ID_GEN: Arc<NodeId> = Arc::new(NodeId(0));
// }

impl Parser {
    // pub fn brick(&self) -> Brick {}

    pub fn new_from_file(path: PathBuf) -> Result<Parser, Box<dyn Error>> {
        let mut f = std::fs::File::open(path)?;
        let mut source = String::new();
        f.read_to_string(&mut source)?;

        let mut parser = tree_sitter::Parser::new();
        parser.set_language(xva_treesitter::language())?;

        let tree = parser.parse(source.as_str(), None).unwrap();

        let result = Parser {
            current_source: source,
            cst: tree,
            current_node_id: 0.into(),
        };

        Ok(result)
    }

    pub fn new_from_str(input: &str) -> Result<Parser, Box<dyn Error>> {
        let mut parser = tree_sitter::Parser::new();
        parser.set_language(xva_treesitter::language())?;

        let tree = parser.parse(input, None).unwrap();
        let result = Parser {
            current_source: input.to_string(), // expensive
            cst: tree,
            current_node_id: 0.into(),
        };

        Ok(result)
    }

    pub(crate) fn brick(&mut self) -> ParserResult<Brick> {
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

    pub(crate) fn node_id(&mut self) -> NodeId {
        let result = self.current_node_id;
        self.current_node_id += 1;
        result
    }

    pub(crate) fn gen_node_ids(&mut self, items: Vec<Item>) -> Vec<Item> {
        // for mut item in items {
        //     item.id = self.node_id();
        //     match item.kind {
        //         ItemKind::Expression(expr) => todo!(),
        //         ItemKind::Module(modd) => todo!(),
        //     }
        // }

        items
    }
}

pub fn print_node(node: &Node<'_>) -> String {
    let start = node.start_position();
    let end = node.end_position();
    format!(
        "{}@{}:{}..{}:{}",
        node.kind(),
        start.row,
        start.column,
        end.row,
        end.column
    )
}

// pub(crate) fn next_node_id() -> NodeId {
//     let current = NODE_ID_GEN.borrow_mut();
//     current.0 += 1;

//     *NODE_ID_GEN.clone()
// }

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
