use std::rc::Rc;

use rowan::SyntaxElement;

use super::expression::Expression;
use crate::{
    language::SyntaxKind,
    parser::{operator::InfixOperator, SyntaxNode},
};

#[allow(dead_code)]
#[derive(Debug, Clone)]
pub struct BinaryExpression {
    pub(crate) syntax_node: SyntaxNode,
    pub left: Rc<Option<Expression>>,
    pub right: Rc<Option<Expression>>,
    pub operator: Option<InfixOperator>,
}

impl BinaryExpression {
    pub(crate) fn new(syntax_node: SyntaxNode) -> Self {
        Self {
            left: Self::left(&syntax_node),
            operator: Self::operator(&syntax_node),
            right: Self::right(&syntax_node),
            syntax_node,
        }
    }
    pub(crate) fn left(syntax_node: &SyntaxNode) -> Rc<Option<Expression>> {
        Rc::new(syntax_node.children().find_map(Expression::new))
    }

    pub(crate) fn operator(syntax_node: &SyntaxNode) -> Option<InfixOperator> {
        match syntax_node
            .children_with_tokens()
            .filter_map(SyntaxElement::into_token)
            .find(|t| {
                matches!(
                    t.kind(),
                    SyntaxKind::Plus | SyntaxKind::Minus | SyntaxKind::Star | SyntaxKind::Slash
                )
            }) {
            Some(t) => match t.kind() {
                SyntaxKind::Plus => Some(InfixOperator::Addition),
                SyntaxKind::Minus => Some(InfixOperator::Subtraction),
                SyntaxKind::Star => Some(InfixOperator::Multiplication),
                SyntaxKind::Slash => Some(InfixOperator::Division),
                _ => None,
            },
            None => None,
        }
    }

    pub(crate) fn right(syntax_node: &SyntaxNode) -> Rc<Option<Expression>> {
        Rc::new(syntax_node.children().filter_map(Expression::new).nth(1))
    }
}
