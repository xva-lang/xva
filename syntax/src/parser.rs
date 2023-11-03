use tree_sitter::Node;

mod expression;
mod literal;
mod operator;

use crate::ast::{
    BinaryExpression, BinaryOperator, Expression, ExpressionKind, Item, ItemKind, Literal,
    PrefixExpression, PrefixOperator,
};
use operator::{binary_operator, prefix_operator};

pub fn parse(input: &str) -> Vec<Item> {
    let tree = crate::tree_sitter::get_tree(input, None);
    let mut nodes = Vec::<Item>::new();
    let mut cursor = tree.walk();

    for child in tree.root_node().children(&mut cursor) {
        nodes.push(walk_node(&child, input))
    }

    nodes
}

pub fn additive_expresion(node: &Node<'_>, input: &str) -> Expression {
    Expression::new(
        get_node_id(),
        ExpressionKind::Binary(BinaryExpression::new_boxed(
            expression(&(node.child(0).unwrap()), input).into(),
            binary_operator(&(node.child(1).unwrap()), input.as_ref()),
            expression(&(node.child(2).unwrap()), input.as_ref()),
        )),
    )
}

fn prefix_expression(node: &Node<'_>, input: &str) -> Expression {
    Expression::new(
        get_node_id(),
        ExpressionKind::Prefix(PrefixExpression::new_boxed(
            prefix_operator(&(node.child(0).unwrap()), input),
            expression(&(node.child(1).unwrap()), input).into(),
        )),
    )
}
pub fn expression(node: &Node<'_>, input: &str) -> Expression {
    match node.kind() {
        "additive_expression" => additive_expresion(node, input),
        "prefix_expression" => prefix_expression(node, input),
        "decimal_literal" => decimal_literal(node, input),
        e => panic!("unknown expression kind: '{e}'"),
    }
}

pub fn walk_node(node: &Node<'_>, input: &str) -> Item {
    match node.kind() {
        "additive_expression" => Item {
            id: get_node_id(),
            kind: ItemKind::Expression(additive_expresion(node, input)),
        },
        "decimal_literal" => Item {
            id: get_node_id(),
            kind: ItemKind::Expression(decimal_literal(node, input)),
        },
        e => panic!("unknown kind {}", e),
    }
}

static mut UNSAFE_NODE_ID_SEED_PLEASE_STOP_USING_THIS: u32 = 0;

pub fn get_node_id() -> u32 {
    let val = unsafe { UNSAFE_NODE_ID_SEED_PLEASE_STOP_USING_THIS };
    unsafe { UNSAFE_NODE_ID_SEED_PLEASE_STOP_USING_THIS += 1 };
    val
}

#[cfg(test)]
mod tests {
    use crate::ast::{Expression, Item, ItemKind};

    #[test]
    fn test() {
        let nodes = super::parse("1 + -1");
    }
}
