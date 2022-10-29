use rowan::SyntaxElement;

use crate::{
    language::SyntaxKind,
    parser::{SyntaxNode, SyntaxToken},
};

#[derive(Debug)]
pub struct Root(SyntaxNode);

impl Root {
    pub fn cast(node: SyntaxNode) -> Option<Self> {
        if node.kind() == SyntaxKind::Root {
            Some(Self(node))
        } else {
            None
        }
    }

    pub fn statements(&mut self) -> impl Iterator<Item = Statement> {
        self.0.children().filter_map(Statement::cast)
    }
}

#[derive(Debug)]
pub enum Statement {
    Expression(Expression),
}

impl Statement {
    pub fn cast(node: SyntaxNode) -> Option<Self> {
        let result = match node.kind() {
            SyntaxKind::BinaryExpression => {
                Self::Expression(Expression::BinaryExpression(BinaryExpression(node)))
            }
            _ => Self::Expression(Expression::cast(node).unwrap()),
        };

        Some(result)
    }
}

#[derive(Debug)]
pub enum Expression {
    BinaryExpression(BinaryExpression),
    Literal(Literal),
}

#[derive(Debug)]
pub struct Literal(SyntaxNode);

impl Expression {
    pub fn cast(node: SyntaxNode) -> Option<Self> {
        let result = match node.kind() {
            SyntaxKind::Literal => Self::Literal(Literal(node)),
            _ => return None,
        };

        Some(result)
    }
}

#[derive(Debug)]
pub struct BinaryExpression(SyntaxNode);

impl BinaryExpression {
    pub(crate) fn left(&self) -> Option<Expression> {
        self.0.children().find_map(Expression::cast)
    }

    pub(crate) fn operator(&self) -> Option<SyntaxToken> {
        self.0
            .children_with_tokens()
            .filter_map(SyntaxElement::into_token)
            .find(|t| {
                matches!(
                    t.kind(),
                    SyntaxKind::Plus | SyntaxKind::Minus | SyntaxKind::Star | SyntaxKind::Slash
                )
            })
    }

    pub(crate) fn right(&self) -> Option<Expression> {
        self.0.children().filter_map(Expression::cast).nth(1)
    }
}
