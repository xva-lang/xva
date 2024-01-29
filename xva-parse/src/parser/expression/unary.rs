use tree_sitter::Node;
use xva_ast::ast::{Expression, ExpressionKind, Item, ItemKind, UnaryOperator};
use xva_span::SourceLocation;

use crate::{
    parser::{error::ParserResult, Parser},
    strings,
    traits::{TSIdentifyable, TSLocatable},
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
                let SourceLocation { start, .. } = negation_node.ts_span();
                let SourceLocation { end, .. } = expr.span.clone();

                Ok(Expression {
                    id: negation_node.node_id(),
                    kind: ExpressionKind::Unary(UnaryOperator::Negation, expr.into()),
                    span: SourceLocation::new(start, end),
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
}
