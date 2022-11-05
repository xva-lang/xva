use xvasyntax::ast::expression::Expression;
use xvasyntax::ast::literal::LiteralVariant;
use xvasyntax::ast::{ast_type::ASTType, expression, literal::Literal, root::Root};

use xvasyntax::parser::operator::InfixOperator;

use crate::compiler::Compiler;

// pub(crate) trait TypeCheck<T: HasASTType> {
//     fn infer(&self) -> ASTType;
// }

pub(crate) struct TypeChecker<'compiler, 'lines> {
    compiler: &'compiler mut Compiler<'lines>,
}

impl<'compiler, 'lines> TypeChecker<'compiler, 'lines> {
    pub fn new(compiler: &'compiler mut Compiler<'lines>) -> Self {
        Self { compiler }
    }

    pub fn walk_untyped_tree(&mut self, root: &mut Root) -> Vec<Expression> {
        let mut expressions = root.expressions();
        for i in 0..expressions.len() {
            let ast_type = self.infer_expression(&expressions[i]);
            let _ = std::mem::replace(&mut expressions[i].ast_type, ast_type);
        }

        expressions
    }

    pub fn infer_expression(&mut self, expression: &expression::Expression) -> ASTType {
        match &expression.variant {
            expression::ExpressionVariant::BinaryExpression(be) => {
                let op_type = self.infer_operator(be.operator.unwrap());

                let opt_left = be.left.as_ref();
                let left_type = match opt_left {
                    Some(l) => self.infer_expression(l),
                    None => todo!(),
                };

                let opt_right = be.right.as_ref();
                let right_type = match opt_right {
                    Some(r) => self.infer_expression(r),
                    None => todo!(),
                };

                // TODO allow floats
                match &op_type {
                    ASTType::Function(inputs, _) => {
                        if left_type != *inputs.get(0).unwrap() {
                            match be.left.as_ref() {
                                Some(left) => {
                                    self.compiler.raise_error(left, "Expected an integer")
                                }
                                None => {}
                            }
                        }

                        if right_type != *inputs.get(1).unwrap() {
                            match be.right.as_ref() {
                                Some(right) => {
                                    self.compiler.raise_error(right, "Expected an integer")
                                }
                                None => {}
                            }
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
                    Some(p) => self.infer_expression(p),
                    None => panic!("cant infer parenthesised expression"),
                }
            }
            expression::ExpressionVariant::Literal(l) => self.infer_literal(&l),
            expression::ExpressionVariant::Declaration(d) => match &d.assignment.as_ref() {
                Some(a) => self.infer_expression(a),
                None => ASTType::Void,
            },
        }
    }

    pub fn infer_literal(&self, literal: &Literal) -> ASTType {
        match literal.get_variant_as_ref() {
            LiteralVariant::Integer(_) => ASTType::Integer,
            LiteralVariant::Boolean(_) => ASTType::Boolean,
        }
    }

    pub fn infer_operator(&self, operator: InfixOperator) -> ASTType {
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
}
