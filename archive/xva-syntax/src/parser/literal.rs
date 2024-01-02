use super::get_node_id;
use crate::ast::{Expression, ExpressionKind, Literal};
use tree_sitter::Node;

pub(super) fn decimal_literal(node: &Node<'_>, input: impl AsRef<[u8]>) -> Expression {
    match node.utf8_text(input.as_ref()) {
        Ok(t) => {
            let value = match t.parse::<u128>() {
                Ok(v) => v,
                Err(e) => panic!("{}", e),
            };

            Expression::new(
                get_node_id(),
                ExpressionKind::Literal(Literal::Decimal(value)),
            )
        }
        Err(e) => panic!("{}", e),
    }
}
