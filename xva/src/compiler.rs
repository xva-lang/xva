use std::ops::Range;

use crate::machine::opcode::Opcode;
// use crate::runtime::typing::type_check;
// use xvasyntax::ast::ast_type::ASTType;
use xvasyntax::ast::expression::{Expression, ExpressionVariant};
use xvasyntax::ast::literal::LiteralVariant;
use xvasyntax::ast::root::Root;
use xvasyntax::parser::line_index::LineIndexes;
use xvasyntax::parser::operator::InfixOperator;

pub(crate) struct Compiler<'lines> {
    output: Vec<u8>,
    pub(crate) errors: Vec<String>,
    line_indexes: LineIndexes,
    lines: &'lines mut Vec<&'lines str>,
}

impl<'lines> Compiler<'lines> {
    pub(crate) fn new(line_indexes: LineIndexes, lines: &'lines mut Vec<&'lines str>) -> Self {
        Self {
            output: vec![],
            errors: vec![],
            line_indexes,
            lines,
        }
    }

    pub(crate) fn compile(&mut self, root_node: &mut Root) {
        let mut type_checker = super::typecheck::TypeChecker::new(self);
        let typed_root = type_checker.walk_untyped_tree(root_node);
        for expression in &typed_root {
            self.compile_expression(&expression.variant);
        }
    }

    fn compile_expression(&mut self, variant: &ExpressionVariant) {
        match variant {
            ExpressionVariant::BinaryExpression(e) => {
                let left = e.left.as_ref();
                // let mut left_type: &ASTType = &ASTType::Void;
                // let mut right_type: &ASTType = &ASTType::Void;

                match left {
                    Some(x) => {
                        // left_type = &x.ast_type;
                        self.compile_expression(&x.variant)
                    }
                    None => todo!(),
                }

                let right = e.right.as_ref();
                match right {
                    Some(x) => {
                        // right_type = &x.ast_type;
                        self.compile_expression(&x.variant)
                    }
                    None => todo!(),
                }

                match e.operator.into() {
                    Some(o) => self.compile_operator(o),
                    None => todo!(),
                }
            }
            ExpressionVariant::ParenthesisedExpression(pe) => match pe.into() {
                Some(x) => match x.as_ref() {
                    Some(expr) => self.compile_expression(&expr.variant),
                    None => panic!(),
                },
                None => todo!(),
            },
            ExpressionVariant::Literal(e) => match e.get_variant_as_ref() {
                LiteralVariant::Integer(v) => {
                    self.emit(Opcode::LoadInteger);
                    self.emit_vec(v.to_le_bytes().to_vec())
                }
                LiteralVariant::Boolean(v) => {
                    self.emit(Opcode::LoadInteger);
                    self.emit_vec(if *v {
                        1i64.to_le_bytes().to_vec()
                    } else {
                        0i64.to_le_bytes().to_vec()
                    })
                }
            },
        }
    }

    fn emit(&mut self, opcode: Opcode) {
        self.output.push(opcode.into());
    }

    fn emit_raw(&mut self, raw: u8) {
        self.output.push(raw);
    }

    fn emit_vec(&mut self, vec: Vec<u8>) {
        for v in vec {
            self.emit_raw(v);
        }
    }

    #[allow(dead_code)]
    fn debug_output(&self) {
        dbg!(&self.output);
    }

    pub(crate) fn clear_output(&mut self) {
        self.output = vec![];
    }

    pub(crate) fn get_output_as_slice(&mut self) -> &[u8] {
        self.output.as_slice()
    }

    fn compile_operator(&mut self, operator: InfixOperator) {
        match operator {
            InfixOperator::Addition => self.emit(Opcode::Add),
            InfixOperator::Subtraction => self.emit(Opcode::Subtract),
            InfixOperator::Multiplication => self.emit(Opcode::IntegerMultiply),
            InfixOperator::Division => self.emit(Opcode::IntegerDivide),
            InfixOperator::NotAnOperator => unreachable!("unknown operator"),
        }
    }

    pub(crate) fn raise_error(&mut self, expression: &Expression, error: &str) {
        let text_range = expression.get_node().text_range();
        let line_number = self
            .line_indexes
            .get_line_range(expression.get_node().text_range().into())
            .unwrap();

        // let end_position = Into::<Range<usize>>::into(text_range).end;
        let start_position = Into::<Range<usize>>::into(text_range).start + 1;

        // let position = end_position - start_position;
        let constructed_line = self.lines[line_number.start - 1];

        let error_line = format!(
            "      |\n    {} | {}\n      |{}^",
            line_number.start,
            constructed_line,
            " ".repeat(start_position),
        );

        self.errors.push(format!(
            "error: {} (at line {}, position {}):\n\n{}",
            error, line_number.start, start_position, error_line,
        ));
    }
}

#[cfg(test)]
mod tests {
    use super::Compiler;
    use super::Opcode;
    use xvasyntax::ast::root::Root;

    fn expect_program(input: &str, expected: Vec<u8>) {
        let parse_tree = xvasyntax::parser::parse(input);
        let mut lines: Vec<&str> = input.split("\n").collect();
        let mut compiler = Compiler::new(parse_tree.get_line_indexes(), &mut lines);
        let mut root = Root::cast(parse_tree.get_root_node()).unwrap();

        compiler.compile(&mut root);
        let out = compiler.get_output_as_slice();
        assert_eq!(out, expected)
    }

    #[test]
    fn compile_binary_expression() {
        expect_program(
            "1 + 1",
            [
                Opcode::LoadInteger.into(),
                1,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                Opcode::LoadInteger.into(),
                1,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                Opcode::Add.into(),
            ]
            .to_vec(),
        )
    }

    #[test]
    fn compile_parenthesised_expression() {
        expect_program(
            "1 + (2 + 3)",
            [
                Opcode::LoadInteger.into(),
                1,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                Opcode::LoadInteger.into(),
                2,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                Opcode::LoadInteger.into(),
                3,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                Opcode::Add.into(),
                Opcode::Add.into(),
            ]
            .to_vec(),
        )
    }
}
