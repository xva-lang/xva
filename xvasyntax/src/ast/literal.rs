use super::utils::i64_from_node_text;
use crate::{language::SyntaxKind, parser::SyntaxNode};

#[derive(Debug, Clone)]
pub enum LiteralVariant {
    Integer(i64), //TODO change this to typey something
}

#[allow(dead_code)]
#[derive(Debug)]
pub struct Literal {
    syntax_node: SyntaxNode,
    variant: LiteralVariant,
}

impl Literal {
    pub(crate) fn new(syntax_node: SyntaxNode) -> Self {
        Self {
            syntax_node: syntax_node.clone(),
            variant: Self::cast(syntax_node.clone()),
        }
    }

    fn cast(syntax_node: SyntaxNode) -> LiteralVariant {
        match syntax_node.first_child_or_token() {
            Some(child) => match child.kind() {
                SyntaxKind::IntegerLiteral => {
                    LiteralVariant::Integer(i64_from_node_text(syntax_node))
                }
                x => unreachable!("Unhandled syntax node kind {:?}", x),
            },

            None => unreachable!("Nothing supplied as first child of Literal"),
        }
    }

    pub fn get_variant(&self) -> LiteralVariant {
        self.variant.clone()
    }
}
