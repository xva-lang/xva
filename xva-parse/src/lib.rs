use std::{
    io::{self, Read, Seek},
    path::PathBuf,
};

use parser::Parser;

mod parser;
mod session;

#[cfg(test)]
mod tests {
    use std::error::Error;

    use super::Parser;

    fn check(input: &str) -> String {
        use tree_sitter::{Node, Tree};
        let mut result = String::new();
        let parser = Parser::new_from_str(input).unwrap();

        fn print_node<'a>(
            source: impl AsRef<[u8]>,
            tree: &Tree,
            node: Node,
            depth: &'a mut usize,
            result: &mut String,
        ) {
            let mut cursor = tree.walk();
            result.push_str(&format!(
                "{}{} @{}:{}..{}:{}",
                "  ".repeat(depth.clone()),
                node.kind(),
                node.start_position().row,
                node.start_position().column,
                node.end_position().row,
                node.end_position().column,
            ));

            if node.child_count() > 0 {
                result.push_str("\n");
                for child in node.children(&mut cursor) {
                    *depth += 1;
                    print_node(source.as_ref(), &tree, child, depth, result);
                    if child.next_sibling().is_none() && depth.clone() > 0 {
                        *depth -= 1;
                    }
                }
            } else {
                if node.start_byte() != node.end_byte() {
                    result.push_str(&format!(
                        " \"{}\"",
                        node.utf8_text(source.as_ref()).unwrap()
                    ))
                }

                if depth.clone() > 0 {
                    *depth -= 1;
                };
            }
        }

        let mut depth = 0;
        print_node(
            input,
            parser.tree(),
            parser.tree().root_node(),
            &mut depth,
            &mut result,
        );
        result
    }

    #[test]
    fn test() -> Result<(), Box<dyn Error>> {
        println!("{}", check("true"));
        Ok(())
    }
}
