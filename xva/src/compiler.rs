use crate::machine::opcode::Opcode;
use crate::runtime::typing::type_check;
use xvasyntax::ast::expression::ExpressionVariant;
use xvasyntax::ast::literal::LiteralVariant;
use xvasyntax::ast::root::Root;
use xvasyntax::parser::operator::InfixOperator;

pub(crate) struct Compiler {
    output: Vec<u8>,
}

impl Compiler {
    pub(crate) fn new() -> Self {
        Self { output: vec![] }
    }

    pub(crate) fn compile(&mut self, root_node: &mut Root) {
        super::typecheck::walk_untyped_tree(root_node);
        for expression in root_node.expressions() {
            self.compile_expression(&expression.variant);
        }
    }

    fn compile_expression(&mut self, variant: &ExpressionVariant) {
        match variant {
            ExpressionVariant::BinaryExpression(e) => {
                let left = e.left.as_ref();
                match left {
                    Some(x) => self.compile_expression(&x.variant),
                    None => todo!(),
                }

                let right = e.right.as_ref();
                match right {
                    Some(x) => self.compile_expression(&x.variant),
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
}

#[cfg(test)]
mod tests {
    use super::Compiler;
    use super::Opcode;
    use xvasyntax::ast::root::Root;

    fn expect_program(input: &str, expected: Vec<u8>) {
        let mut compiler = Compiler::new();
        let parse_tree = xvasyntax::parser::parse(input);
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
