use xvasyntax::ast::expression::Expression;
use xvasyntax::ast::{ast_type::ASTType, expression, literal::Literal, root::Root};

use xvasyntax::parser::operator::InfixOperator;

// pub(crate) trait TypeCheck<T: HasASTType> {
//     fn infer(&self) -> ASTType;
// }
pub fn walk_untyped_tree(root: &mut Root) -> Vec<Expression> {
    let mut expressions = root.expressions();
    for i in 0..expressions.len() {
        let ast_type = infer_expression(&expressions[i]);

        // expressions[i].ast_type = ast_type;
        let _ = std::mem::replace(&mut expressions[i].ast_type, ast_type);
    }

    expressions
}

pub fn infer_expression(expression: &expression::Expression) -> ASTType {
    match &expression.variant {
        expression::ExpressionVariant::BinaryExpression(be) => {
            let op_type = infer_operator(be.operator.unwrap());

            let opt_left = be.left.as_ref();
            let left_type = match opt_left {
                Some(l) => match infer_expression(l) {
                    ASTType::Integer => ASTType::Integer,
                    _ => unreachable!("Type annotation required"),
                },
                None => todo!(),
            };

            let opt_right = be.right.as_ref();
            let right_type = match opt_right {
                Some(r) => match infer_expression(r) {
                    ASTType::Integer => ASTType::Integer,
                    _ => unreachable!("Type annotation required"),
                },
                None => todo!(),
            };

            // TODO allow floats
            match &op_type {
                ASTType::Function(inputs, _) => {
                    if left_type != *inputs.get(0).unwrap() {
                        panic!("left type error");
                    }

                    if right_type != *inputs.get(1).unwrap() {
                        panic!("right type error")
                    }
                }
                _ => panic!("operator must be function type"),
            }

            match op_type {
                ASTType::Function(_, o) => *o,
                _ => ASTType::Void,
            }
        }
        expression::ExpressionVariant::ParenthesisedExpression(pe) => {
            let opt_pe = pe.as_ref();
            match opt_pe {
                Some(p) => infer_expression(p),
                None => panic!("cant infer parenthesised expression"),
            }
        }
        expression::ExpressionVariant::Literal(l) => infer_literal(&l),
    }
}

pub fn infer_literal(literal: &Literal) -> ASTType {
    match literal.get_variant_as_ref() {
        xvasyntax::ast::literal::LiteralVariant::Integer(_) => ASTType::Integer,
    }
}

pub fn infer_operator(operator: InfixOperator) -> ASTType {
    match operator {
        InfixOperator::Addition
        | InfixOperator::Subtraction
        | InfixOperator::Multiplication
        | InfixOperator::Division => ASTType::Function(
            Box::from(vec![ASTType::Integer, ASTType::Integer]),
            Box::new(ASTType::Integer),
        ),

        InfixOperator::NotAnOperator => ASTType::Void,
    }
}
