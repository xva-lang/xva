use crate::machine::opcode::Opcode;
use crate::machine::symtable::{SymbolTable, SymbolTableEntry};
use crate::runtime::typing::builtins::ValueType;
use crate::syntax::ast::ast_type::ASTType;
use crate::syntax::ast::{
    expression::{Expression, ExpressionVariant},
    literal::LiteralVariant,
    operator::InfixOperator,
    root::Root,
};

pub(crate) struct Compiler {
    output: Vec<u8>,
    pub(crate) errors: Vec<String>,
    original_lines: Vec<String>,
    globals: SymbolTable,
}

impl Compiler {
    pub(crate) fn new() -> Self {
        Self {
            output: vec![],
            original_lines: vec![],
            errors: vec![],
            globals: SymbolTable::new(),
        }
    }

    pub(crate) fn compile(&mut self, root_node: &mut Root, original_lines: Vec<String>) {
        self.original_lines = original_lines;
        let mut type_checker = super::typecheck::TypeChecker::new(self);
        type_checker.walk_untyped_tree(root_node);
        for expression in root_node.expressions.iter() {
            self.compile_expression(&expression, expression.get_type());
        }
    }

    fn compile_expression(&mut self, expression: &Expression, expr_type: &ASTType) {
        match &expression.variant {
            ExpressionVariant::Binary(e) => {
                let left = e.get_left();
                self.compile_expression(left, expr_type);

                let right = e.get_right();
                self.compile_expression(right, expr_type);

                self.compile_operator(e.get_operator(), expr_type);
            }
            ExpressionVariant::Parenthesised(pe) => {
                self.compile_expression(&pe.get_inner_expression(), expr_type)
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
                LiteralVariant::Float(v) => {
                    self.emit(Opcode::LoadFloat);
                    self.emit_vec(v.to_le_bytes().to_vec());
                }
            },
            ExpressionVariant::Prefix(_) => todo!(),
            ExpressionVariant::Declaration(d) => {
                // self.globals.new_symbol(d.get_name().to_string(), value_type)
                let sym_table_type: ValueType;
                match d.get_assignment() {
                    Some(a) => {
                        sym_table_type = match a.get_type() {
                            ASTType::Void => ValueType::Void,
                            ASTType::Integer => ValueType::Integer(0),
                            ASTType::Boolean => ValueType::Boolean(false),
                            ASTType::Float => ValueType::Float(0.0),
                            ASTType::OneOf(_) => todo!(),
                            ASTType::Function(_, _) => todo!(),
                        };

                        self.compile_expression(a, a.get_type());
                        self.emit(Opcode::StoreLocal);
                        self.emit_vec(
                            (d.get_name().as_bytes().len() as u16)
                                .to_le_bytes()
                                .to_vec(),
                        );
                        self.emit_vec(d.get_name().as_bytes().to_vec());
                    }
                    None => {
                        sym_table_type = ValueType::Void;
                    }
                }

                let (line, span) = (expression.get_line(), expression.get_span());
                self.globals
                    .new_symbol(d.get_name().to_string(), sym_table_type, line, span);
            }
            ExpressionVariant::Identifier(i) => {
                self.emit(Opcode::LoadLocal);
                self.emit_vec((i.get_name().len() as u16).to_le_bytes().to_vec());
                self.emit_vec(i.get_name().as_bytes().to_vec());
            }
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

    fn compile_operator(&mut self, operator: InfixOperator, expr_type: &ASTType) {
        match expr_type {
            ASTType::Integer => match operator {
                InfixOperator::Addition => self.emit(Opcode::Add),
                InfixOperator::Subtraction => self.emit(Opcode::Subtract),
                InfixOperator::Multiplication => self.emit(Opcode::IntegerMultiply),
                InfixOperator::Division => self.emit(Opcode::IntegerDivide),
            },
            ASTType::Float => match operator {
                InfixOperator::Addition => self.emit(Opcode::FloatAdd),
                InfixOperator::Subtraction => self.emit(Opcode::FloatSubtract),
                InfixOperator::Multiplication => self.emit(Opcode::FloatMultiply),
                InfixOperator::Division => self.emit(Opcode::FloatDivide),
            },
            _ => {}
        }
    }

    pub(crate) fn raise_error(
        &mut self,
        expression: &Expression,
        error: &str,
        suggestion: Option<&str>,
    ) {
        let start_position = expression.get_span().start + 1;
        let line = &self.original_lines[expression.get_line() - 1];
        let mut temp = String::new();
        let suggest = match suggestion {
            Some(x) => {
                temp.push(' ');
                temp.push_str(x);
                temp.as_str()
            }
            None => "",
        };

        let error_line = format!(
            "      |\n    {} | {}\n      |{}^{}",
            expression.get_line(),
            line,
            " ".repeat(start_position),
            suggest
        );

        self.errors.push(format!(
            "error: {} (at line {}, position {}):\n\n{}",
            error,
            expression.get_line(),
            start_position,
            error_line,
        ));
    }

    pub(crate) fn lookup_symbol(&self, name: &str) -> Result<&SymbolTableEntry, String> {
        match self.globals.lookup(name) {
            Some(x) => Ok(x),
            None => Err(format!("The name '{}' is not declared in this scope", name)),
        }
    }

    pub fn get_lines_as_slice(&self) -> &[String] {
        self.original_lines.as_slice()
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
        let original_lines = lexer::utils::string_lines_as_vec(String::from(input));
        let mut lexer = TokenKind::lexer(input);
        let token_stream = TokenStream::new(&mut lexer);
        let mut parser = Parser::new(token_stream, original_lines.clone());

        let mut compiler = Compiler::new();

        compiler.compile(&mut parser.parse(), original_lines.clone());
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
