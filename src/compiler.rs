pub(crate) mod error;
pub(super) mod symtable;

use crate::compiler::error::CompilerError;
use crate::machine::opcode::Opcode;
use crate::runtime::typing::builtins::ValueType;
use crate::syntax::ast::ast_type::ASTPrimitiveType;
use crate::syntax::ast::{
    ast_type::ASTType,
    expression::{Expression, ExpressionVariant},
    literal::LiteralVariant,
    operator::InfixOperator,
    root::Root,
};
use crate::syntax::lexer::span::Span;
use crate::syntax::location::SyntaxLocation;
use symtable::{SymbolTable, SymbolTableEntry};

pub(crate) struct Compiler {
    output: Vec<u8>,
    pub(crate) errors: Vec<CompilerError>,
    globals: SymbolTable,
}

impl Compiler {
    pub(crate) fn new() -> Self {
        Self {
            output: vec![],
            errors: vec![],
            globals: SymbolTable::new(),
        }
    }

    pub(crate) fn compile(&mut self, root_node: &mut Root) -> Result<(), &Vec<CompilerError>> {
        for expression in root_node.expressions.iter() {
            self.collect_symbols(expression, expression.get_type());
        }

        let mut type_checker = super::typecheck::TypeChecker::new(self);
        type_checker.walk_untyped_tree(root_node);

        for expression in root_node.expressions.iter() {
            self.compile_expression(&expression, expression.get_type());
        }

        if self.errors.len() > 0 {
            Err(&self.errors)
        } else {
            Ok(())
        }
    }

    fn compile_expression(&mut self, expression: &Expression, expr_type: &ASTType) {
        match &expression.variant {
            ExpressionVariant::Binary(e) => {
                let (left_type, right_type) = e.get_type();
                if left_type != right_type {
                    self.raise_error(expression, "Types in binary expression do not match", None);
                }

                let left = e.get_left();
                self.compile_expression(left, expr_type);

                let right = e.get_right();
                self.compile_expression(right, expr_type);

                // left.get_type() is safe because type checker has already guaranteed type compatibility
                self.compile_operator(e.get_operator(), left.get_type());
            }
            ExpressionVariant::Parenthesised(pe) => {
                self.compile_expression(&pe.get_inner_expression().as_ref().borrow(), expr_type)
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
            ExpressionVariant::Declaration(d) => match d.get_assignment() {
                Some(a) => {
                    self.compile_expression(a, a.get_type());
                    self.emit(Opcode::StoreLocal);
                    self.emit_vec(
                        (d.get_name().as_bytes().len() as u16)
                            .to_le_bytes()
                            .to_vec(),
                    );
                    self.emit_vec(d.get_name().as_bytes().to_vec());
                }
                None => {}
            },
            ExpressionVariant::Identifier(i) => {
                println!("{}", i);
                let match_result = self.lookup_symbol(i.get_name());
                match match_result {
                    Ok(_) => {
                        self.emit(Opcode::LoadLocal);
                        self.emit_vec((i.get_name().len() as u16).to_le_bytes().to_vec());
                        self.emit_vec(i.get_name().as_bytes().to_vec());
                    }

                    Err(e) => self.raise_error_at_location(
                        expression.get_location(),
                        e.as_str(),
                        Some(
                            format!("Consider declaring a variable named '{}'", i.get_name())
                                .as_str(),
                        ),
                    ),
                }
            }
            ExpressionVariant::Assignment(a) => match self.lookup_symbol(a.get_target_identifier())
            {
                Ok(s) => {
                    if s.is_mutable() {
                        self.compile_expression(a.get_expression(), a.get_expression().get_type());
                        self.emit(Opcode::StoreLocal);
                        self.emit_vec(
                            (a.get_target_identifier().as_bytes().len() as u16)
                                .to_le_bytes()
                                .to_vec(),
                        );
                        self.emit_vec(a.get_target_identifier().as_bytes().to_vec());
                    } else {
                        self.raise_error_at_location(
                            expression.get_location(),
                            "Attempted assignment to immutable variable",
                            Some(
                                format!(
                                    "Consider adding the 'mutable' keyword to the declaration of '{}'",
                                    a.get_target_identifier()
                                )
                                .as_str(),
                            ),
                        )
                    }
                }

                Err(e) => self.raise_error_at_location(
                    expression.get_location(),
                    e.as_str(),
                    Some(
                        format!(
                            "Consider declaring a variable named '{}'",
                            a.get_target_identifier()
                        )
                        .as_str(),
                    ),
                ),
            },
        }
    }

    fn collect_symbols(&mut self, expression: &Expression, expr_type: &ASTType) {
        match &expression.variant {
            ExpressionVariant::Declaration(d) => match self.lookup_symbol(d.get_name()) {
                Ok(_) => self.raise_error_at_location(
                    d.get_identifier_location(),
                    format!("Re-declaring existing name '{}'", d.get_name()).as_str(),
                    Some("Consider changing this declaration to use a different name"),
                ),
                Err(_) => {
                    let sym_table_type = match d.get_assignment() {
                        Some(e) => match e.get_type() {
                            ASTType::Primitive(p) => match p {
                                ASTPrimitiveType::Void => ValueType::Void,
                                ASTPrimitiveType::Integer => ValueType::Integer(0),
                                ASTPrimitiveType::Boolean => ValueType::Boolean(false),
                                ASTPrimitiveType::Float => ValueType::Float(0.0),
                            },
                        },
                        None => ValueType::Void,
                    };

                    let (line, span) = (expression.get_line(), expression.get_line_span());
                    self.globals.new_symbol(
                        d.get_name().to_string(),
                        sym_table_type,
                        line,
                        span,
                        d.is_mutable(),
                    );
                }
            },
            _ => {}
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
        println!("expr_type: {:?}", expr_type);
        match expr_type {
            ASTType::Primitive(p) => match p {
                ASTPrimitiveType::Integer => match operator {
                    InfixOperator::Addition => self.emit(Opcode::Add),
                    InfixOperator::Subtraction => self.emit(Opcode::Subtract),
                    InfixOperator::Multiplication => self.emit(Opcode::IntegerMultiply),
                    InfixOperator::Division => self.emit(Opcode::IntegerDivide),
                },
                ASTPrimitiveType::Float => match operator {
                    InfixOperator::Addition => self.emit(Opcode::FloatAdd),
                    InfixOperator::Subtraction => self.emit(Opcode::FloatSubtract),
                    InfixOperator::Multiplication => self.emit(Opcode::FloatMultiply),
                    InfixOperator::Division => self.emit(Opcode::FloatDivide),
                },
                _ => {
                    println!("");
                }
            },
        }
    }

    pub(crate) fn raise_error(
        &mut self,
        expression: &Expression,
        error: &str,
        suggestion: Option<&str>,
    ) {
        self.errors.push(CompilerError::new(
            SyntaxLocation::new(
                expression.get_line(),
                Span {
                    start: expression.get_line_span().start,
                    end: expression.get_line_span().end,
                },
                expression.get_absolute_span(),
            ),
            error,
            suggestion,
        ));
    }

    pub(crate) fn raise_error_at_location(
        &mut self,
        location: SyntaxLocation,
        error: &str,
        suggestion: Option<&str>,
    ) {
        self.errors
            .push(CompilerError::new(location, error, suggestion));
    }

    pub(crate) fn lookup_symbol(&self, name: &str) -> Result<&SymbolTableEntry, String> {
        match self.globals.lookup(name) {
            Some(x) => Ok(x),
            None => Err(format!("The name '{}' is not declared in this scope", name)),
        }
    }

    pub(crate) fn clear_errors(&mut self) {
        self.errors.clear();
    }
}

#[cfg(test)]
mod tests {
    use super::Compiler;
    use super::Opcode;
    use crate::syntax::lexer::{language::TokenKind, token_stream::TokenStream};
    use crate::syntax::parser::Parser;
    use logos::Logos;

    fn expect_program(input: &str, expected: Vec<u8>) {
        // let original_lines = lexer::utils::string_lines_as_vec(String::from(input));
        let mut lexer = TokenKind::lexer(input);
        let token_stream = TokenStream::new(&mut lexer);
        let mut parser = Parser::new(token_stream);

        let mut compiler = Compiler::new();

        match parser.parse() {
            Ok(mut r) => match compiler.compile(&mut r) {
                Ok(_) => {
                    let out = compiler.get_output_as_slice();
                    assert_eq!(out, expected)
                }
                Err(e) => {
                    let mut full_error = String::new();
                    for err in e {
                        full_error.push_str(&err.format_with_line(input))
                    }
                    panic!("{}", full_error);
                }
            },
            Err(e) => {
                let mut full_error = String::new();
                for err in e {
                    full_error.push_str(&err.format_with_line(input))
                }
                panic!("{}", full_error);
            }
        };
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
