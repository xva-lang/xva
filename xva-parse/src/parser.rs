pub mod error;
mod expression;

use codespan_reporting::{
    diagnostic::{Diagnostic, Label},
    files::{Files, SimpleFiles},
    term::{
        self,
        termcolor::{ColorChoice, StandardStream},
    },
};
use error::ParserResult;
use std::{collections::HashMap, ops::Range, sync::Arc};
use tree_sitter::{Node, Tree};
use xva_ast::{
    ast::Brick,
    ast::{Item, ItemKind, Module},
};
use xva_span::source::{SourceFile, SourceMap, SrcId};

use crate::traits::TSIdentifyable;

// pub struct FileCache {
//     files: HashMap<PathBuf, Source>,
// }

// impl Cache<Path> for FileCache {
//     type Storage = String;

//     fn fetch(&mut self, path: &Path) -> Result<&Source, Box<dyn fmt::Debug + '_>> {
//         Ok(match self.files.entry(path.to_path_buf()) { // TODO: Don't allocate here
//             Entry::Occupied(entry) => entry.into_mut(),
//             Entry::Vacant(entry) => entry.insert(Source::from(fs::read_to_string(path).map_err(|e| Box::new(e) as _)?)),
//         })
//     }
//     fn display<'a>(&self, path: &'a Path) -> Option<Box<dyn fmt::Display + 'a>> { Some(Box::new(path.display())) }
// }

// #[derive(Debug)]
pub struct Parser<'p> {
    cst: tree_sitter::Tree,
    current_file: SrcId,
    // sources: SourceCache,
    sources: SourceMap<'p>,
}

// lazy_static! {
//     // static ref NODE_ID_GEN: Arc<NodeId> = Arc::new(NodeId(0));
// }

impl<'p> Parser<'p> {
    pub(crate) fn new_from_str(input: &str) -> ParserResult<Self> {
        let mut parser = tree_sitter::Parser::new();
        if let Err(e) = parser.set_language(xva_treesitter::language()) {
            return Err(error::ParserError::TSLanguageError(e));
        };

        let tree = parser.parse(input, None).unwrap();

        let mut sources = SourceMap::default();
        // let current_file = sources.add("<input>".into(), input.into());
        let current_file = sources.load_virtual("<input>".into(), input.into());

        let result = Parser {
            cst: tree,
            current_file,
            sources,
        };

        Ok(result)
    }

    pub fn brick(&mut self) -> ParserResult<Brick> {
        let module = self.brick_module()?;

        Ok(Brick {
            items: vec![Item {
                id: 0.into(),
                kind: ItemKind::Module(module),
                range: self.tree().root_node().byte_range(),
            }],
        })
    }

    fn brick_module(&mut self) -> ParserResult<Module> {
        let mut cursor = self.cst.root_node().walk();
        let mut items = vec![];

        for node in cursor.node().children(&mut cursor) {
            match node.kind() {
                "expression" => {
                    let expr = self.expression(node)?;
                    items.push(Item {
                        id: node.node_id(),
                        kind: ItemKind::Expression(expr),
                        range: node.byte_range(),
                    })
                }
                "ERROR" => {
                    let file_id = self.current_file;
                    let range = node.start_byte()..node.end_byte();

                    let diagnostic: Diagnostic<SrcId> = Diagnostic::error()
                        .with_message(format!(
                            "Expected an expression, but found `{}`",
                            node.utf8_text(self.source().unwrap().content().as_bytes())
                                .unwrap()
                        ))
                        .with_labels(vec![Label::primary(file_id, range)
                            .with_message("Expected an expression here".to_string())]);

                    let writer = StandardStream::stderr(ColorChoice::Always);
                    let config = codespan_reporting::term::Config::default();
                    term::emit(&mut writer.lock(), &config, &self.sources, &diagnostic).unwrap();
                }
                e => unreachable!("Unhandled node kind from tree-sitter: {e}"),
            }
        }

        Ok(Module { items })
    }

    pub(crate) fn tree(&self) -> &Tree {
        &self.cst
    }

    fn source(&self) -> Option<Arc<SourceFile>> {
        match self.sources.get(self.current_file) {
            Some(a) => Some(a.clone()),
            None => None,
        }
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

    #[test]
    fn invalid() {
        let mut parser = Parser::new_from_str("something_that_ain't an expression").unwrap();
        parser.brick().unwrap();
    }
}
