use crate::{
    compiler::Compiler,
    syntax::ast::{
        ast_type::ASTType,
        operator::{InfixOperator, PrefixOperator},
        root::Root,
        Expression, ExpressionVariant, LiteralVariant,
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

                // TODO allow floats
                match &op_type {
                    ASTType::Function(inputs, _) => {
                        if left_type != *inputs.get(0).unwrap() {
                            self.compiler
                                .raise_error(be.get_left(), "Expected an integer")
                        }

                        if right_type != *inputs.get(1).unwrap() {
                            self.compiler
                                .raise_error(be.get_right(), "Expected an integer")
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
        }
    }
}
