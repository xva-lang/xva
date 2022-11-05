use super::expression::Expression;
use crate::{language::SyntaxKind, parser::SyntaxNode};

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

    pub fn expressions(&mut self) -> Vec<Expression> {
        self.0.children().filter_map(Expression::new).collect()
    }

    pub fn print(&mut self) -> String {
        let mut sb = String::new();
        for expression in self.expressions() {
            sb.push_str(String::from(format!("{:#?}", expression)).as_str());
        }

        sb
    }
}

// #[derive(Debug)]
// pub enum StatementVariant {
//     Expression(ExpressionVariant),
// }

// impl StatementVariant {
//     pub fn cast(node: SyntaxNode) -> Option<Self> {
//         let result = match node.kind() {
//             SyntaxKind::BinaryExpression => Self::Expression(ExpressionVariant::BinaryExpression(
//                 BinaryExpression::new(node),
//             )),
//             _ => Self::Expression(ExpressionVariant::cast(node).unwrap()),
//         };

//         Some(result)
//     }
// }

// #[derive(Debug)]
// pub enum ExpressionVariant {
//     BinaryExpression(BinaryExpression),
//     ParenthesisedExpression(ParenthesisedExpression),
//     Literal(Literal),
// }

// impl ExpressionVariant {
//     pub fn cast(node: SyntaxNode) -> Option<Self> {
//         let result = match node.kind() {
//             SyntaxKind::BinaryExpression => Self::BinaryExpression(BinaryExpression::new(node)),
//             SyntaxKind::ParenthesisedExpression => Self::ParenthesisedExpression(
//                 ParenthesisedExpression::new(node.first_child().unwrap()),
//             ),
//             SyntaxKind::Literal => Self::Literal(Literal::new(node)),
//             _ => return None,
//         };

//         Some(result)
//     }
// }

// #[derive(Debug)]
// pub struct ParenthesisedExpression {
//     pub variant: Box<Option<ExpressionVariant>>,
// }

// impl ParenthesisedExpression {
//     pub(super) fn new(syntax_node: SyntaxNode) -> Self {
//         Self {
//             variant: Box::from(ExpressionVariant::cast(syntax_node)),
//         }
//     }
// }

// #[derive(Debug, Clone)]
// pub enum LiteralVariant {
//     Integer(i64), //TODO change this to typey something
// }

// #[allow(dead_code)]
// #[derive(Debug)]
// pub struct Literal {
//     syntax_node: SyntaxNode,
//     variant: LiteralVariant,
// }

// impl Literal {
//     pub(crate) fn new(syntax_node: SyntaxNode) -> Self {
//         Self {
//             syntax_node: syntax_node.clone(),
//             variant: Self::cast(syntax_node.clone()),
//         }
//     }

//     fn cast(syntax_node: SyntaxNode) -> LiteralVariant {
//         match syntax_node.first_child_or_token() {
//             Some(child) => match child.kind() {
//                 SyntaxKind::IntegerLiteral => {
//                     LiteralVariant::Integer(i64_from_node_text(syntax_node))
//                 }
//                 x => unreachable!("Unhandled syntax node kind {:?}", x),
//             },

//             None => unreachable!("Nothing supplied as first child of Literal"),
//         }
//     }

//     pub fn get_variant(&self) -> LiteralVariant {
//         self.variant.clone()
//     }
// }

// #[allow(dead_code)]
// #[derive(Debug)]
// pub struct BinaryExpression {
//     syntax_node: SyntaxNode,
//     pub left: Box<Option<ExpressionVariant>>,
//     pub right: Box<Option<ExpressionVariant>>,
//     pub operator: Option<InfixOperator>,
// }

// impl BinaryExpression {
//     pub(crate) fn new(syntax_node: SyntaxNode) -> Self {
//         Self {
//             left: Self::left(syntax_node.clone()),
//             operator: Self::operator(syntax_node.clone()),
//             right: Self::right(syntax_node.clone()),
//             syntax_node,
//         }
//     }
//     pub(crate) fn left(syntax_node: SyntaxNode) -> Box<Option<ExpressionVariant>> {
//         Box::new(syntax_node.children().find_map(ExpressionVariant::cast))
//     }

//     pub(crate) fn operator(syntax_node: SyntaxNode) -> Option<InfixOperator> {
//         match syntax_node
//             .children_with_tokens()
//             .filter_map(SyntaxElement::into_token)
//             .find(|t| {
//                 matches!(
//                     t.kind(),
//                     SyntaxKind::Plus | SyntaxKind::Minus | SyntaxKind::Star | SyntaxKind::Slash
//                 )
//             }) {
//             Some(t) => match t.kind() {
//                 SyntaxKind::Plus => Some(InfixOperator::Addition),
//                 SyntaxKind::Minus => Some(InfixOperator::Subtraction),
//                 SyntaxKind::Star => Some(InfixOperator::Multiplication),
//                 SyntaxKind::Slash => Some(InfixOperator::Division),
//                 _ => None,
//             },
//             None => None,
//         }
//     }

//     pub(crate) fn right(syntax_node: SyntaxNode) -> Box<Option<ExpressionVariant>> {
//         Box::new(
//             syntax_node
//                 .children()
//                 .filter_map(ExpressionVariant::cast)
//                 .nth(1),
//         )
//     }
// }

// fn i64_from_node_text(syntax_node: SyntaxNode) -> i64 {
//     str::parse(String::from(syntax_node.text()).as_str().trim()).unwrap()
// }

// #[cfg(test)]
// mod tests {
//     use super::Root;
//     use crate::parser::parse;
//     use expect_test::{expect, Expect};

//     fn test_ast(input: &str, expected_tree: Expect) {
//         let parse_tree = parse(input);
//         expected_tree.assert_eq(
//             Root::cast(parse_tree.get_root_node())
//                 .unwrap()
//                 .print()
//                 .as_str(),
//         );
//     }

//     #[test]
//     fn ast_literal() {
//         test_ast(
//             "1",
//             expect![[r#"
// Expression {
//     ast_type: Void,
//     variant: Literal(
//         Literal {
//             syntax_node: Literal@0..1
//               IntegerLiteral@0..1 "1"
//             ,
//             variant: Integer(
//                 1,
//             ),
//         },
//     ),
// }"#]],
//         )
//     }

//     #[test]
//     fn ast_binary_expression() {
//         test_ast(
//             "1 + 1",
//             expect![[r#"
// Expression {
//     ast_type: Void,
//     variant: BinaryExpression(
//         BinaryExpression {
//             syntax_node: BinaryExpression@0..5
//               Literal@0..2
//                 IntegerLiteral@0..1 "1"
//                 Whitespace@1..2 " "
//               Plus@2..3 "+"
//               Whitespace@3..4 " "
//               Literal@4..5
//                 IntegerLiteral@4..5 "1"
//             ,
//             left: Some(
//                 Expression {
//                     ast_type: Void,
//                     variant: Literal(
//                         Literal {
//                             syntax_node: Literal@0..2
//                               IntegerLiteral@0..1 "1"
//                               Whitespace@1..2 " "
//                             ,
//                             variant: Integer(
//                                 1,
//                             ),
//                         },
//                     ),
//                 },
//             ),
//             right: Some(
//                 Expression {
//                     ast_type: Void,
//                     variant: Literal(
//                         Literal {
//                             syntax_node: Literal@4..5
//                               IntegerLiteral@4..5 "1"
//                             ,
//                             variant: Integer(
//                                 1,
//                             ),
//                         },
//                     ),
//                 },
//             ),
//             operator: Some(
//                 Addition,
//             ),
//         },
//     ),
// }"#]],
//         )
//     }
// }
