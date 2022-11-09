use crate::runtime::typing::builtins::ValueType;

use super::{bindtable::BindingTable, flags::Flag, flags::FlagsRegister, opcode::Opcode};

const MAX_STACK: usize = 1024; // FIXME
pub(crate) struct VirtualMachine {
    stack: Vec<ValueType>,
    stack_pointer: usize,
    program_counter: usize,
    pub(crate) program: Vec<u8>,
    remainder: i64,
    flags: FlagsRegister,
    globals: BindingTable,
}

impl VirtualMachine {
    pub(crate) fn new() -> Self {
        Self {
            stack: vec![],
            stack_pointer: 0,
            program_counter: 0,
            program: vec![],
            remainder: 0,
            flags: FlagsRegister::new(),
            globals: BindingTable::new(),
        }
    }

    pub(crate) fn run(&mut self) {
        loop {
            if self.program_counter >= self.program.len() {
                break;
            }

            match self.next_instruction() {
                Opcode::Halt => {
                    break;
                }

                Opcode::Add => {
                    let (right, left) = (self.pop_i64(), self.pop_i64());
                    let value = left + right;
                    self.push_i64(value);
                    self.assess_flags(value);
                }
                Opcode::Subtract => {
                    let (right, left) = (self.pop_i64(), self.pop_i64());
                    let value = left - right;
                    self.push_i64(value);
                    self.assess_flags(value);
                }
                Opcode::IntegerMultiply => {
                    let (right, left) = (self.pop_i64(), self.pop_i64());
                    let value = left * right;
                    self.push_i64(value);
                    self.assess_flags(value);
                }
                Opcode::IntegerDivide => {
                    let (right, left) = (self.pop_i64(), self.pop_i64());
                    let value = left / right;
                    self.remainder = left % right;
                    self.push_i64(value);
                    self.assess_flags(value);
                }

                Opcode::AbsoluteJump => {
                    self.program_counter = self.require_next_double_word() as usize;
                }

                Opcode::LoadInteger => {
                    let value = self.require_next_quad_word();
                    self.push_i64(value);
                }

                Opcode::LoadFloat => {
                    let value = self.require_next_float();
                    self.push_f64(value);
                }

                Opcode::FloatAdd => {
                    let (right, left) = (self.pop_f64(), self.pop_f64());
                    let value = left + right;
                    self.push_f64(value);
                    // self.assess_flags(value);
                }
                Opcode::FloatSubtract => {
                    let (right, left) = (self.pop_f64(), self.pop_f64());
                    let value = left - right;
                    self.push_f64(value);
                    // self.assess_flags(value);
                }

                Opcode::FloatMultiply => {
                    let (right, left) = (self.pop_f64(), self.pop_f64());
                    let value = left * right;
                    self.push_f64(value);
                    // self.assess_flags(value);
                }

                Opcode::FloatDivide => {
                    let (right, left) = (self.pop_f64(), self.pop_f64());
                    let value = left / right;
                    self.push_f64(value);
                    // self.assess_flags(value);
                }

                Opcode::StoreLocal => {
                    let local_name_size = self.require_next_word() as usize;
                    let local_name = match String::from_utf8(self.pop_bytes(local_name_size)) {
                        Ok(n) => n,
                        Err(e) => panic!("String reading error: {}", e),
                    };

                    let local_value = self.pop_indeterminate();
                    self.globals.update_value(local_name, local_value);
                    self.stack.push(ValueType::Void);
                }

                Opcode::LoadLocal => {
                    let local_name_size = self.require_next_word() as usize;
                    let local_name = match String::from_utf8(self.pop_bytes(local_name_size)) {
                        Ok(n) => n,
                        Err(e) => panic!("String reading error: {}", e),
                    };

                    let entry = self.globals.lookup(local_name.as_str());
                    match entry {
                        Some(s) => self.push_value(s.get_value()),
                        None => panic!("undeclared local {}", local_name.as_str()),
                    }
                }
                unknown => {
                    println!("Unrecognised opcode: {:?}", unknown)
                }
            }
        }
    }

    fn next_instruction(&mut self) -> Opcode {
        let result = Opcode::from(self.program[self.program_counter]);
        self.program_counter += 1;
        result
    }

    fn require_next_byte(&mut self) -> u8 {
        let result = self.program[self.program_counter];
        self.program_counter += 1;
        result
    }

    fn consume(&mut self) {
        self.program_counter += 1;
    }

    fn assess_flags(&mut self, value: i64) {
        if value == 0 {
            self.flags.set_flag(Flag::Zero);
        }

        if value < 0 {
            self.flags.set_flag(Flag::Sign);
        }
    }

    fn require_next_quad_word(&mut self) -> i64 {
        self.program_counter += 8;

        i64::from_le_bytes(
            self.program[self.program_counter - 8..self.program_counter]
                .try_into()
                .expect("Bad array"),
        )
    }

    fn require_next_word(&mut self) -> u16 {
        self.program_counter += 2;

        u16::from_le_bytes(
            self.program[self.program_counter - 2..self.program_counter]
                .try_into()
                .expect("Bad array"),
        )
    }

    fn require_next_float(&mut self) -> f64 {
        self.program_counter += 8;
        f64::from_le_bytes(
            self.program[self.program_counter - 8..self.program_counter]
                .try_into()
                .expect("Bad array"),
        )
    }

    fn require_next_double_word(&mut self) -> i32 {
        self.program_counter += 4;

        i32::from_le_bytes(
            self.program[self.program_counter - 4..self.program_counter]
                .try_into()
                .expect("Bad array"),
        )
    }

    fn pop_bytes(&mut self, num_bytes: usize) -> Vec<u8> {
        self.program_counter += num_bytes;
        self.program[self.program_counter - num_bytes..self.program_counter].to_vec()
    }

    fn push_i64(&mut self, value: i64) {
        self.stack.push(ValueType::Integer(value));
    }

    fn push_f64(&mut self, value: f64) {
        self.stack.push(ValueType::Float(value));
    }

    fn push_value(&mut self, value: ValueType) {
        self.stack.push(value);
    }

    pub fn pop_f64(&mut self) -> f64 {
        match self.stack.pop() {
            Some(v) => match v {
                ValueType::Float(f) => f,
                _ => panic!("Top of stack is not a float"),
            },
            None => panic!("VM stack underflow"),
        }
    }

    pub(crate) fn pop_i64(&mut self) -> i64 {
        match self.stack.pop() {
            Some(v) => match v {
                ValueType::Integer(i) => i,
                _ => panic!("Top of stack is not an int"),
            },
            None => panic!("VM stack underflow"),
        }
    }

    pub(crate) fn pop_indeterminate(&mut self) -> ValueType {
        match self.stack.pop() {
            Some(v) => v,
            None => panic!("VM stack underflow"),
        }
    }

    pub(crate) fn reset_program_counter(&mut self) {
        self.program_counter = 0;
    }

    #[allow(dead_code)]
    pub(crate) fn print_stack(&self) {
        for i in (0..MAX_STACK).step_by(8) {
            println!(
                "{} {} {} {} {} {} {} {}",
                self.stack[i],
                self.stack[i + 1],
                self.stack[i + 2],
                self.stack[i + 3],
                self.stack[i + 4],
                self.stack[i + 5],
                self.stack[i + 6],
                self.stack[i + 7]
            )
        }
    }
}

#[cfg(test)]
mod tests {
    use logos::Logos;

    use super::VirtualMachine;
    use crate::{
        compiler::Compiler,
        error_resolver,
        runtime::typing::builtins::ValueType,
        syntax::{
            self,
            lexer::{language::TokenKind, token_stream::TokenStream},
            parser::Parser,
        },
    };

    #[test]
    fn decode_opcode_halt() {
        let mut vm = VirtualMachine::new();
        vm.program = vec![0, 0, 0, 0];
        vm.run();
        assert_eq!(vm.program_counter, 1);
    }

    #[test]
    fn decode_illegal_opcode() {
        let mut vm = VirtualMachine::new();
        vm.program = vec![69, 42, 0xff, 0xff];
        vm.run();
        assert_eq!(vm.program_counter, 4);
    }

    fn expect_return_value(input: &str, return_val: ValueType) {
        let original_lines = syntax::lexer::utils::string_lines_as_vec(String::from(input));
        let error_resolver = error_resolver::ErrorResolver::new(original_lines);
        let mut lexer = TokenKind::lexer(input);
        let token_stream = TokenStream::new(&mut lexer);
        let mut parser = Parser::new(token_stream);

        let mut compiler = Compiler::new();
        match parser.parse() {
            Ok(mut r) => {
                println!("{}", r);
                match compiler.compile(&mut r) {
                    Ok(_) => {
                        let mut vm = VirtualMachine::new();
                        vm.program = compiler.get_output_as_slice().to_vec();
                        vm.run();
                        assert_eq!(vm.pop_indeterminate(), return_val);
                    }
                    Err(e) => {
                        let mut full_error = String::new();
                        for err in e {
                            full_error.push_str(&error_resolver.resolve(err));
                        }

                        panic!("{}", full_error);
                    }
                }
            }
            Err(e) => {
                let mut full_error = String::new();
                for err in e {
                    full_error.push_str(&error_resolver.resolve(err));
                }

                panic!("{}", full_error);
            }
        }
    }

    #[test]
    fn expression_program() {
        expect_return_value("1 + 36 * 32 - 1477", ValueType::Integer(-324));
    }

    #[test]
    fn parenthesised_expression_program() {
        expect_return_value("2 * (3 * 3)", ValueType::Integer(18))
    }

    #[test]
    fn variable() {
        expect_return_value(
            r#"let number = 123
number"#,
            ValueType::Integer(123),
        )
    }

    #[test]
    fn expression_variable() {
        expect_return_value(
            r#"
let number = 2.3 + 3.4
number"#,
            ValueType::Float(5.7),
        )
    }
}
