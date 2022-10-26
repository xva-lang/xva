use std::iter::Peekable;

use crate::{
    language::XvaLanguage,
    lexer::{Lexer, SyntaxKind},
};
use rowan::{GreenNode, GreenNodeBuilder, Language};

pub struct Parser<'a> {
    // Lifetime 'a is needed because Logos’ lexers store the input they were created with,
    //and pull from it as tokens are requested.
    lexer: Peekable<Lexer<'a>>,
    builder: GreenNodeBuilder<'static>,
}

impl<'a> Parser<'a> {
    pub(crate) fn new(input: &'a str) -> Self {
        Self {
            lexer: Lexer::new(input).peekable(),
            builder: GreenNodeBuilder::new(),
        }
    }

    pub(crate) fn parse(mut self) -> Parse {
        self.start_node(SyntaxKind::Root);

        match self.peek() {
            Some(SyntaxKind::Number) | Some(SyntaxKind::Identifier) => self.bump(),
            _ => {}
        }

        self.finish_node();

        Parse {
            // builder.finish() outputs the finished syntax tree.
            // The tree must be of a single root node, hence SyntaxKind::Root
            green_node: self.builder.finish(),
        }
    }

    /// Starts a new node on the current branch of the parse tree.
    /// # Arguments
    /// * `kind` - A `SyntaxKind` describing the new node to start.
    fn start_node(&mut self, kind: SyntaxKind) {
        self.builder.start_node(XvaLanguage::kind_to_raw(kind))
    }

    /// Completes the parse tree
    fn finish_node(&mut self) {
        self.builder.finish_node();
    }

    /// Peeks at the next token without consuming it.
    fn peek(&mut self) -> Option<SyntaxKind> {
        self.lexer.peek().map(|(kind, _)| *kind)
    }

    /// Consumes the next token and appends it to the current branch of the parse tree
    /// # Panics
    /// If there are no available tokens the thread will panic. This is intentional as it represents
    /// an error with the construction of the syntax tree.
    fn bump(&mut self) {
        let (kind, text) = self.lexer.next().unwrap();
        self.builder.token(XvaLanguage::kind_to_raw(kind), text);
    }
}

pub struct Parse {
    green_node: GreenNode,
}

impl Parse {
    pub fn debug_tree(&self) -> String {
        let syntax_node = SyntaxNode::new_root(self.green_node.clone());
        let formatted = format!("{:#?}", syntax_node);

        // Cut off the last byte because formatting the SyntaxNode adds on a newline at the end.
        formatted[0..formatted.len() - 1].to_string()
    }
}

pub(crate) type SyntaxNode = rowan::SyntaxNode<XvaLanguage>;

#[cfg(test)]
mod tests {
    use super::*;
    use expect_test::{expect, Expect};

    fn check_parse(input: &str, expected_tree: Expect) {
        let parse = Parser::new(input).parse();
        expected_tree.assert_eq(&parse.debug_tree());
    }

    #[test]
    fn parse_nothing() {
        check_parse("", expect![[r"Root@0..0"]]);
    }

    #[test]
    fn parse_number() {
        check_parse(
            "123",
            expect![[r#"
Root@0..3
  Number@0..3 "123""#]],
        );
    }

    #[test]
    fn parse_identifier() {
        check_parse(
            "counter",
            expect![[r#"
Root@0..7
  Identifier@0..7 "counter""#]],
        )
    }
}
