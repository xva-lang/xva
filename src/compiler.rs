use crate::machine::opcode::Opcode;
use crate::syntax::ast::{
    operator::InfixOperator, Expression, ExpressionVariant, LiteralVariant, Root,
};

pub(crate) struct Compiler<'input> {
    output: Vec<u8>,
    pub(crate) errors: Vec<String>,
    original_lines: Vec<&'input str>,
}

impl<'input> Compiler<'input> {
    pub(crate) fn new(original_lines: Vec<&'input str>) -> Self {
        Self {
            output: vec![],
            original_lines,
            errors: vec![],
        }
    }

    pub(crate) fn compile(&mut self, root_node: &mut Root) {
        let mut type_checker = super::typecheck::TypeChecker::new(self);
        type_checker.walk_untyped_tree(root_node);
        for expression in root_node.expressions.iter() {
            self.compile_expression(&expression.variant);
        }
    }

    fn compile_expression(&mut self, variant: &ExpressionVariant) {
        match variant {
            ExpressionVariant::Binary(e) => {
                let left = e.get_left();
                self.compile_expression(&left.variant);

                let right = e.get_right();
                self.compile_expression(&right.variant);

                self.compile_operator(e.get_operator());
            }
            ExpressionVariant::Parenthesised(pe) => {
                self.compile_expression(&pe.get_inner_expression().variant)
            }
            ExpressionVariant::Literal(e) => match e {
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
            ExpressionVariant::Prefix(_) => todo!(),
            // ExpressionVariant::Declaration(_) => todo!(),
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
        }
    }

    pub(crate) fn raise_error(&mut self, expression: &Expression, error: &str) {
        let start_position = expression.get_span().start;
        let line = self.original_lines[expression.get_line() - 1];

        let error_line = format!(
            "      |\n    {} | {}\n      |{}^",
            expression.get_line(),
            line,
            " ".repeat(start_position),
        );

        self.errors.push(format!(
            "error: {} (at line {}, position {}):\n\n{}",
            error,
            expression.get_line(),
            start_position,
            error_line,
        ));
    }
}

#[cfg(test)]
mod tests {
    use logos::Logos;

    use super::Compiler;
    use super::Opcode;
    use crate::syntax::lexer;
    use crate::syntax::lexer::{language::TokenKind, token_stream::TokenStream};
    use crate::syntax::parser::Parser;

    fn expect_program(input: &str, expected: Vec<u8>) {
        let original_lines = lexer::utils::input_lines_as_vec(input);
        let mut lexer = TokenKind::lexer(input);
        let token_stream = TokenStream::new(&mut lexer);
        let mut parser = Parser::new(token_stream);

        let mut compiler = Compiler::new(original_lines);

        compiler.compile(&mut parser.parse());
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
