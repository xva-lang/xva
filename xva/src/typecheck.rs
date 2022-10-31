use xvasyntax::ast::{ast_type::ASTType, expression, literal::Literal, root::Root};

use xvasyntax::parser::operator::InfixOperator;

// pub(crate) trait TypeCheck<T: HasASTType> {
//     fn infer(&self) -> ASTType;
// }
pub fn walk_untyped_tree(root: &mut Root) {
    for (_, mut expression) in root.expressions().enumerate() {
        let ast_type = infer_expression(&expression);
        expression.ast_type = ast_type;
    }
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
            if left_type != op_type {
                panic!("Left type error");
            }

            if right_type != op_type {
                panic!("Right type error");
            }

            op_type
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
