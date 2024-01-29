use tree_sitter::Node;
use xva_ast::ast::{Expression, ExpressionKind, Item, ItemKind, UnaryOperator};

use crate::{
    parser::{error::ParserResult, Parser},
    strings,
    traits::TSIdentifyable,
};

strings! {
    EXPR_KIND_NEGATION = "negation_expression"
}

impl<'p> Parser<'p> {
    pub(crate) fn unary(&self, root: Node<'_>) -> ParserResult<Expression> {
        let mut cursor = root.walk();
        cursor.goto_first_child();

        println!("{}", cursor.node().kind());
        match cursor.node().kind() {
            EXPR_KIND_NEGATION => {
                let negation_node = cursor.node();

                // Go to the "-" node
                cursor.goto_first_child();

                // Go to the expression root
                cursor.goto_next_sibling();

                let expr = self.expression(cursor.node())?;

                Ok(Expression {
                    id: negation_node.node_id(),
                    kind: ExpressionKind::Unary(UnaryOperator::Negation, expr.into()),
                    span: negation_node.byte_range(),
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
    fn unary() {
        let mut parser = Parser::new_from_str("-1").unwrap();
        println!("{:#?}", parser.brick());
    }

    #[test]
    fn negation_without_expr() {
        let mut parser = Parser::new_from_str("-").unwrap();
        println!("{:#?}", parser.brick());
    }
}
