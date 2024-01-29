use tree_sitter::Node;
use xva_ast::ast::{Expression, ExpressionKind, Item, ItemKind, UnaryOperator};

use crate::{
    parser::{error::ParserResult, Parser},
    strings,
    traits::TSIdentifyable,
};

strings! {
    EXPR_KIND_NEGATION = "negation_expression"
    EXPR_KIND_NOT = "not_expression"
}

impl<'p> Parser<'p> {
    pub(crate) fn unary(&self, root: Node<'_>) -> ParserResult<Expression> {
        let mut cursor = root.walk();
        cursor.goto_first_child();

        println!("{}", cursor.node().kind());
        match cursor.node().kind() {
            // Unary prefixes: `not <expr>`, `-<expr>`.

            // Note pattern binding syntax: var @ pattern
            root_kind @ (EXPR_KIND_NEGATION | EXPR_KIND_NOT) => {
                let root_node = cursor.node();

                // Go to the operator node
                cursor.goto_first_child();

                // Go to the root node of the expression
                cursor.goto_next_sibling();

                let expr = self.expression(cursor.node())?;

                Ok(Expression {
                    id: root_node.node_id(),
                    kind: ExpressionKind::Unary(
                        match root_kind {
                            EXPR_KIND_NEGATION => UnaryOperator::Negation,
                            EXPR_KIND_NOT => UnaryOperator::Not,
                            _ => unreachable!("Unknown unary expression variant: {root_kind}"),
                        },
                        expr.into(),
                    ),
                    span: root_node.byte_range(),
                })
            }

            x => unreachable!("Unknown unary expression variant: {x}"),
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::parser::Parser;

    #[test]
    fn negation() {
        let mut parser = Parser::new_from_str("-1").unwrap();
        println!("{:#?}", parser.brick());
    }

    #[test]
    fn not() {
        let mut parser = Parser::new_from_str("not false").unwrap();
        println!("{:#?}", parser.brick());
    }

    #[test]
    fn unary_without_expr() {
        let mut parser = Parser::new_from_str("-").unwrap();
        println!("{:#?}", parser.brick());
    }
}
