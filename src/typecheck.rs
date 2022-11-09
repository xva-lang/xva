use std::{cell::RefCell, rc::Rc};

use crate::{
    compiler::Compiler,
    runtime::typing::builtins::ValueType,
    syntax::ast::{
        ast_type::ASTType,
        expression::{Expression, ExpressionVariant},
        literal::LiteralVariant,
        operator::{InfixOperator, PrefixOperator},
        root::Root,
    },
};

pub(crate) struct TypeChecker<'compiler> {
    compiler: Rc<RefCell<&'compiler mut Compiler>>,
}

impl<'compiler> TypeChecker<'compiler> {
    pub fn new(compiler: &'compiler mut Compiler) -> Self {
        Self {
            compiler: Rc::new(RefCell::new(compiler)),
        }
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
                            ASTType::OneOf(i) => {
                                left_is_valid = if !i.iter().any(|x| left_type == *x) {
                                    self.raise_operator_error(
                                        be.get_operator(),
                                        &left_type,
                                        be.get_left(),
                                    );
                                    false
                                } else {
                                    true
                                };
                            }
                            _ => unreachable!(),
                        }

                        match inputs.get(1).unwrap() {
                            ASTType::OneOf(i) => {
                                right_is_valid = if !i.iter().any(|x| right_type == *x) {
                                    self.raise_operator_error(
                                        be.get_operator(),
                                        &right_type,
                                        be.get_right(),
                                    );
                                    false
                                } else {
                                    true
                                };
                            }
                            _ => unreachable!(),
                        }

                        // Only raise a type mismatch if both types are already valid for the operation
                        if left_is_valid && right_is_valid {
                            if left_type != right_type {
                                self.raise_operator_type_mismatch(be.get_right(), &left_type);
                            } else {
                            }
                        }
                    }
                    _ => panic!("operator must be function type"),
                }

                match op_type {
                    ASTType::Function(_, o) => match *o {
                        ASTType::OneOf(one_of) => {
                            if one_of.contains(&left_type) {
                                left_type
                            } else {
                                ASTType::Void
                            }
                        }
                        _ => panic!("operator result type must be a OneOf"),
                    },
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
            },
            ExpressionVariant::Declaration(_) => ASTType::Void,
            ExpressionVariant::Assignment(_) => ASTType::Void,
            ExpressionVariant::Identifier(i) => {
                let (outer_result, outer_error): (ASTType, Option<String>);

                {
                    let ref_compiler = self.compiler.borrow();
                    let lookup_result = ref_compiler.lookup_symbol(i.get_name());
                    let (result, error) = match lookup_result {
                        Ok(x) => match x.get_value() {
                            ValueType::Void => (ASTType::Void, None),
                            ValueType::Integer(_) => (ASTType::Integer, None),
                            ValueType::Float(_) => (ASTType::Float, None),
                            ValueType::Boolean(_) => (ASTType::Boolean, None),
                        },
                        Err(err) => (ASTType::Void, Some(err)),
                    };

                    outer_result = result;
                    outer_error = error;
                }

                if outer_error.is_some() {
                    self.compiler.borrow_mut().raise_error(
                        expression,
                        outer_error.unwrap().as_str(),
                        None,
                    );
                }

                outer_result
            }
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
                    ASTType::OneOf(Box::from(vec![ASTType::Integer, ASTType::Float])),
                    ASTType::OneOf(Box::from(vec![ASTType::Integer, ASTType::Float])),
                ]),
                Box::new(ASTType::OneOf(Box::from(vec![
                    ASTType::Integer,
                    ASTType::Float,
                ]))),
            ),
        }
    }

    pub(crate) fn repr_type(expr_type: &ASTType) -> String {
        String::from(match expr_type {
            ASTType::Void => "<void>",
            ASTType::Integer => "<integer>",
            ASTType::Boolean => "<boolean>",
            ASTType::Float => "<float>",
            ASTType::OneOf(_) => "<tuple>",
            ASTType::Function(_, _) => "<function>",
        })
    }

    fn raise_operator_error(
        &mut self,
        operator: InfixOperator,
        expr_type: &ASTType,
        expr: &Expression,
    ) {
        let error_type = Self::repr_type(expr_type);

        let error = format!(
            "Operation '{}' cannot be applied to type {}",
            operator, error_type
        );
        self.compiler
            .borrow_mut()
            .raise_error(expr, error.as_str(), None);
    }

    fn raise_operator_type_mismatch(&mut self, expr: &Expression, expected_type: &ASTType) {
        let suggestion = format!(
            "Consider changing this expression to be of type: {}",
            Self::repr_type(expected_type)
        );
        self.compiler.borrow_mut().raise_error(
            expr,
            "Types in binary operation do not match",
            Some(suggestion.as_str()),
        );
    }
}
