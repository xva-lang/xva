use super::ast_type::ASTType;
use super::binary_expression::BinaryExpression;
use super::literal::{Literal, LiteralVariant};
use crate::language::SyntaxKind;
use crate::parser::SyntaxNode;

#[derive(Debug, Clone)]
pub struct Expression {
    pub ast_type: ASTType,
    pub variant: ExpressionVariant,
}

#[derive(Debug, Clone)]
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
            SyntaxKind::Literal => {
                let lit = Literal::new(node);
                let cloned_variant = lit.get_variant_as_ref().clone();
                Self {
                    variant: ExpressionVariant::Literal(lit),
                    ast_type: match cloned_variant {
                        LiteralVariant::Integer(_) => ASTType::Integer,
                    },
                }
            }
            _ => return None,
        };

        Some(result)
    }

    pub fn update_type(&mut self, ast_type: ASTType) {
        self.ast_type = ast_type;
    }
}
