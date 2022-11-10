use std::{cell::RefCell, rc::Rc};

use crate::{
    compiler::Compiler,
    runtime::typing::builtins::ValueType,
    syntax::ast::{
        ast_type::{ASTPrimitiveType, ASTType},
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
            expression.type_walk();
        }
    }

    //

    // pub fn infer_literal(&self, literal: &LiteralVariant) -> ASTType {
    //     match literal {
    //         LiteralVariant::Integer(_) => ASTType::Integer,
    //         LiteralVariant::Boolean(_) => ASTType::Boolean,
    //         LiteralVariant::Float(_) => ASTType::Float,
    //     }
    // }

    // pub fn infer_operator(&self, operator: InfixOperator) -> ASTType {
    //     match operator {
    //         InfixOperator::Addition
    //         | InfixOperator::Subtraction
    //         | InfixOperator::Multiplication
    //         | InfixOperator::Division => ASTType::Function(
    //             Box::from(vec![
    //                 ASTType::OneOf(Box::from(vec![ASTType::Integer, ASTType::Float])),
    //                 ASTType::OneOf(Box::from(vec![ASTType::Integer, ASTType::Float])),
    //             ]),
    //             Box::new(ASTType::OneOf(Box::from(vec![
    //                 ASTType::Integer,
    //                 ASTType::Float,
    //             ]))),
    //         ),
    //     }
    // }

    pub(crate) fn repr_type(expr_type: &ASTType) -> String {
        String::from(match expr_type {
            ASTType::Primitive(p) => match p {
                ASTPrimitiveType::Void => "<void>",
                ASTPrimitiveType::Boolean => "<boolean>",
                ASTPrimitiveType::Integer => "<integer>",
                ASTPrimitiveType::Float => "<float>",
            }
            // ASTType::Void => "<void>",
            // ASTType::Integer => "<integer>",
            // ASTType::Boolean => "<boolean>",
            // ASTType::Float => "<float>",
            // ASTType::OneOf(_) => "<tuple>",
            // ASTType::Function(_, _) => "<function>",
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
