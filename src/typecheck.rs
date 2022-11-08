



use crate::{
    compiler::Compiler,
    syntax::ast::{
        ast_type::ASTType,
        expression::{Expression, ExpressionVariant},
        literal::LiteralVariant,
        operator::{InfixOperator, PrefixOperator},
        root::Root,
    },
};

pub(crate) struct TypeChecker<'compiler, 'input> {
    compiler: &'compiler mut Compiler<'input>,
}

impl<'compiler, 'input> TypeChecker<'compiler, 'input> {
    pub fn new(compiler: &'compiler mut Compiler<'input>) -> Self {
        Self { compiler }
    }

    pub fn walk_untyped_tree(&mut self, root: &mut Root) {
        // TODO: remove this .to_vec() call, it gets expensive with a larger tree
        // let mut expressions = root.expressions.to_vec();
        for expression in root.expressions.iter_mut() {
            let ast_type = self.infer_expression(expression);
            expression.set_type(ast_type);
        }
    }

    pub fn infer_expression(&mut self, expression: &Expression) -> ASTType {
        match &expression.variant {
            ExpressionVariant::Binary(be) => {
                let op_type = self.infer_operator(be.get_operator());
                let left_type = self.infer_expression(be.get_left());
                let right_type = self.infer_expression(be.get_right());
                let (left_is_valid, right_is_valid): (bool, bool);
                // TODO allow floats
                match &op_type {
                    ASTType::Function(inputs, _) => {
                        match inputs.get(0).unwrap() {
                            ASTType::Set(i) => {
                                left_is_valid = if !i.iter().any(|x| left_type == *x) {
                                    self.raise_operator_error(be.get_operator(), &left_type, be.get_left());
                                    false
                                }
                                else {
                                    true
                                };
                            },
                            _ => unreachable!(),
                        }

                        match inputs.get(1).unwrap() {
                            ASTType::Set(i) => {
                                right_is_valid = if !i.iter().any(|x| right_type == *x) {
                                    self.raise_operator_error(be.get_operator(), &right_type, be.get_right());
                                    false
                                }
                                else {
                                    true
                                };
                            },
                            _ => unreachable!(),
                        }
                        
                        // Only raise a type mismatch if both types are already valid for the operation
                        if left_is_valid && right_is_valid {
                            if left_type != right_type {
                                self.raise_operator_type_mismatch(be.get_right(), &left_type);
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
            // ExpressionVariant::ParenthesisedExpression(pe) => {
            //     let opt_pe = pe.as_ref();
            //     match opt_pe {
            //         Some(p) => self.infer_expression(p),
            //         None => panic!("cant infer parenthesised expression"),
            //     }
            // }
            ExpressionVariant::Parenthesised(pe) => {
                self.infer_expression(pe.get_inner_expression())
            }
            ExpressionVariant::Literal(l) => self.infer_literal(&l),
            ExpressionVariant::Prefix(pre) => match pre.get_prefix() {
                PrefixOperator::Negation => todo!("Prefix expression"),
            }
            // ExpressionVariant::Declaration(d) => match &d.assignment.as_ref() {
            //     Some(a) => self.infer_expression(a),
            //     None => ASTType::Void,
            // },
        }
    }

    pub fn infer_literal(&self, literal: &LiteralVariant) -> ASTType {
        match literal {
            LiteralVariant::Integer(_) => ASTType::Integer,
            LiteralVariant::Boolean(_) => ASTType::Boolean,
            LiteralVariant::Float(_) => ASTType::Float,
        }
    }

    pub fn infer_operator(&self, operator: InfixOperator) -> ASTType {
        match operator {
            InfixOperator::Addition
            | InfixOperator::Subtraction
            | InfixOperator::Multiplication
            | InfixOperator::Division => ASTType::Function(
                Box::from(vec![
                    ASTType::Set(Box::from(vec![ASTType::Integer, ASTType::Float])),
                    ASTType::Set(Box::from(vec![ASTType::Integer, ASTType::Float])),
                ]),
                Box::new(ASTType::Integer),
            ),
        }
    }

    pub(crate) fn repr_type(expr_type: &ASTType) -> String {
        String::from(match expr_type {
            ASTType::Void => "<void>",
            ASTType::Integer => "<integer>",
            ASTType::Boolean => "<boolean>",
            ASTType::Float => "<float>",
            ASTType::Set(_) => "<tuple>",
            ASTType::Function(_, _) => "<function>",
        })
    }

    fn raise_operator_error(&mut self, operator: InfixOperator, expr_type: &ASTType, expr: &Expression) {
        let error_type = Self::repr_type(expr_type);

        let error = format!("Operation '{}' cannot be applied to type {}", operator, error_type);
        self.compiler.raise_error(expr, error.as_str(), None);
    }

    fn raise_operator_type_mismatch(&mut self, expr: &Expression, expected_type: &ASTType) {
        let suggestion = format!("Consider changing this expression to be of type: {}", 
            Self::repr_type(expected_type));
        self.compiler.raise_error(expr, "Types in binary operation do not match", 
            Some(suggestion.as_str()));
    }
}
