//! This crate provides xva language support for the [tree-sitter][] parsing library.
//!
//! Typically, you will use the [language][language func] function to add this language to a
//! tree-sitter [Parser][], and then use the parser to parse some code:
//!
//! ```
//! let code = "";
//! let mut parser = tree_sitter::Parser::new();
//! parser.set_language(tree_sitter_xva::language()).expect("Error loading xva grammar");
//! let tree = parser.parse(code, None).unwrap();
//! ```
//!
//! [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
//! [language func]: fn.language.html
//! [Parser]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Parser.html
//! [tree-sitter]: https://tree-sitter.github.io/

use tree_sitter::Language;

extern "C" {
    fn tree_sitter_xva() -> Language;
}

/// Get the tree-sitter [Language][] for this grammar.
///
/// [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
pub fn language() -> Language {
    unsafe { tree_sitter_xva() }
}

/// The content of the [`node-types.json`][] file for this grammar.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers#static-node-types
pub const NODE_TYPES: &'static str = include_str!("../../src/node-types.json");

// Uncomment these to include any queries that this grammar contains

// pub const HIGHLIGHTS_QUERY: &'static str = include_str!("../../queries/highlights.scm");
// pub const INJECTIONS_QUERY: &'static str = include_str!("../../queries/injections.scm");
// pub const LOCALS_QUERY: &'static str = include_str!("../../queries/locals.scm");
// pub const TAGS_QUERY: &'static str = include_str!("../../queries/tags.scm");

#[cfg(test)]
mod tests {
    use tree_sitter::{Node, Parser};

    #[test]
    fn test_can_load_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(super::language())
            .expect("Error loading xva language");
    }

    fn get_parser() -> Parser {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(super::language())
            .expect("Error loading Xva language");
        parser
    }

    /// Extracts nth sibling node at the mth level descendant from the root
    ///
    /// `n = 0` is the level immediately descendant of the root.
    fn extract_nth_node_at_mth_level(root: Node, n: usize, level: usize) -> Node {
        let mut node: Option<Node> = None;
        for i in 0..=level {
            if i == 0 {
                node = root.child(0)
            } else {
                if i == level {
                    node = node.unwrap().child(n)
                } else {
                    node = node.unwrap().child(0)
                }
            }
        }

        node.unwrap()
    }

    #[test]
    fn boolean_literal() {
        let mut parser = get_parser();
        let tree = parser.parse("true", None).expect("Failed to parse");
        assert_eq!(
            extract_nth_node_at_mth_level(tree.root_node(), 0, 2).kind(),
            "boolean_literal"
        );

        let tree = parser.parse("false", None).expect("Failed to parse");
        assert_eq!(
            extract_nth_node_at_mth_level(tree.root_node(), 0, 2).kind(),
            "boolean_literal"
        )
    }
}
