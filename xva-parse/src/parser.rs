use std::{error::Error, io::Read, path::PathBuf};

use xva_ast::{Brick, Item};

#[derive(Debug)]
pub struct Parser<'parse> {
    cst: tree_sitter::Tree,
    current_source: String,
    current_cst_node: Option<&'parse tree_sitter::Node<'parse>>,
}

impl<'parse> Parser<'parse> {
    // pub fn brick(&self) -> Brick {}

    pub fn new_from_file(path: PathBuf) -> Result<Parser<'parse>, Box<dyn Error>> {
        let mut f = std::fs::File::open(path)?;
        let mut source = String::new();
        f.read_to_string(&mut source)?;

        let mut parser = tree_sitter::Parser::new();
        parser.set_language(xva_treesitter::language())?;

        let tree = parser.parse(source.as_str(), None).unwrap();
        let root = (&tree).root_node().clone();
        let result = Parser {
            current_source: source,
            cst: tree,
            current_cst_node: None,
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
            current_cst_node: None,
        };

        Ok(result)
    }

    pub fn brick(&self) -> Brick {
        let items = self.items();
        Brick::new_from_items(items)
    }

    pub fn items(&self) -> Vec<Item> {
        vec![]
    }
}

#[cfg(test)]
mod tests {
    use std::{
        error::Error,
        path::{Path, PathBuf},
    };

    use super::Parser;

    #[test]
    fn test() -> Result<(), Box<dyn Error>> {
        let parser = Parser::new_from_str("true")?;
        println!("{:#?}", parser);
        Ok(())
    }
}