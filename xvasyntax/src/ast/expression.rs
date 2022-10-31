use crate::language::SyntaxKind;
use crate::parser::SyntaxNode;

use super::ast_type::ASTType;
use super::binary_expression::BinaryExpression;
use super::literal::Literal;

#[derive(Debug)]
pub struct Expression {
    pub ast_type: ASTType,
    pub variant: ExpressionVariant,
}

#[derive(Debug)]
pub enum ExpressionVariant {
    BinaryExpression(BinaryExpression),
    ParenthesisedExpression(Box<Option<Expression>>),
    Literal(Literal),
}

impl Expression {
    pub fn cast(node: SyntaxNode) -> Option<Self> {
        let result = match node.kind() {
            SyntaxKind::BinaryExpression => Self {
                variant: ExpressionVariant::BinaryExpression(BinaryExpression::new(node)),
                ast_type: ASTType::Void,
            },
            SyntaxKind::ParenthesisedExpression => Self {
                variant: ExpressionVariant::ParenthesisedExpression(Box::new(Self::cast(
                    node.first_child().unwrap(),
                ))),
                ast_type: ASTType::Void,
            },
            SyntaxKind::Literal => Self {
                variant: ExpressionVariant::Literal(Literal::new(node)),
                ast_type: ASTType::Void,
            },
            _ => return None,
        };

        Some(result)
    }
}
