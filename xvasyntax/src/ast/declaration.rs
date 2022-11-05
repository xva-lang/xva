use rowan::SyntaxElement;

use crate::{language::SyntaxKind, parser::SyntaxNode};

use super::{ast_type::ASTType, expression::Expression};

#[derive(Debug, Clone)]
pub struct Declaration {
    pub syntax_node: SyntaxNode,
    name: String,
    ast_type: ASTType,
    pub assignment: Box<Option<Expression>>,
}
impl Declaration {
    pub(crate) fn new(node: SyntaxNode) -> Self {
        let dec_name = match node
            .children_with_tokens()
            .filter_map(SyntaxElement::into_token)
            .find(|t| matches!(t.kind(), SyntaxKind::Identifier))
        {
            Some(n) => String::from(n.text()),
            None => unreachable!("cant get dec name"),
        };

        let assignment = Box::from(node.children().find_map(Expression::new));

        Self {
            syntax_node: node,
            name: dec_name,
            ast_type: ASTType::Void,
            assignment: assignment,
        }
    }
}
