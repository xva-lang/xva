use tree_sitter::Node;
use xva_ast::ast::{BinaryOperator, Expression, ExpressionKind, Item, ItemKind, UnaryOperator};

use crate::{
    parser::{error::ParserResult, Parser},
    strings,
    traits::TSIdentifyable,
};

strings! {
    OP_LOGICAL_AND = "and"
    OP_LOGICAL_OR = "or"
    OP_BITWISE_AND = "&"
    OP_BITWISE_OR = "|"
    OP_BITWISE_XOR  = "^"
    OP_ADD = "+"
    OP_SUBTRACT = "-"
    OP_MULTIPLY = "*"
    OP_DIVIDE = "/"
    OP_MODULO = "%"
    OP_POWER = "**"
    OP_LEFT_SHIFT = "<<"
    OP_RIGHT_SHIFT = ">>"
    OP_LESS_THAN = "<"
    OP_GREATER_THAN = ">"
    OP_EQUAL = "=="
    OP_NOT_EQUAL = "!="
    OP_GREATER_THAN_EQUAL = ">="
    OP_LESS_THAN_EQUAL = "<="
}

impl<'p> Parser<'p> {
    pub(crate) fn binary(&self, root: Node<'_>) -> ParserResult<Expression> {
        let mut cursor = root.walk();

        let binary_root = cursor.node();
        // Go to the left expression and eat
        cursor.goto_first_child();
        let left = self.expression(cursor.node())?;

        // Go to the operator and eat
        cursor.goto_next_sibling();
        let op = match cursor.node().kind() {
            OP_LOGICAL_AND => BinaryOperator::LogicalAnd,
            OP_LOGICAL_OR => BinaryOperator::LogicalOr,
            OP_BITWISE_AND => BinaryOperator::BitwiseAnd,
            OP_BITWISE_OR => BinaryOperator::BitwiseOr,
            OP_BITWISE_XOR => BinaryOperator::BitwiseXor,
            OP_ADD => BinaryOperator::Add,
            OP_SUBTRACT => BinaryOperator::Subtract,
            OP_MULTIPLY => BinaryOperator::Multiply,
            OP_DIVIDE => BinaryOperator::Divide,
            OP_MODULO => BinaryOperator::Modulo,
            OP_POWER => BinaryOperator::Power,
            OP_LEFT_SHIFT => BinaryOperator::LeftShift,
            OP_RIGHT_SHIFT => BinaryOperator::RightShift,
            OP_LESS_THAN => BinaryOperator::LessThan,
            OP_GREATER_THAN => BinaryOperator::GreaterThan,
            OP_EQUAL => BinaryOperator::Equal,
            OP_NOT_EQUAL => BinaryOperator::NotEqual,
            OP_GREATER_THAN_EQUAL => BinaryOperator::GreaterThanEqual,
            OP_LESS_THAN_EQUAL => BinaryOperator::LessThanEqual,
            op => unreachable!("Unknown binary operator: {op}"),
        };

        // Go to the right expression and eat
        cursor.goto_next_sibling();
        let right = self.expression(cursor.node())?;

        Ok(Expression {
            id: binary_root.node_id(),
            kind: ExpressionKind::Binary(op, left.into(), right.into()),
            span: binary_root.byte_range(),
        })
    }
}

#[cfg(test)]
mod tests {
    use crate::parser::Parser;

    #[test]
    fn binary() {
        let mut parser = Parser::new_from_str("1 + 1").unwrap();
        println!("{:#?}", parser.brick());
    }
}
