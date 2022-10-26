use crate::machine::bytecode::Opcode;
use crate::runtime::typing::byte_sizeable::{BOOLEAN_SIZE, CHAR_SIZE, FLOAT_SIZE, INT_SIZE};

use super::bytecode::Opcodeable;

const STACK_WIDTH: usize = 8;
// const CARRY_FLAG: u32 = 0x01;
const PARITY_FLAG: u32 = 0x02;
const ZERO_FLAG: u32 = 0x04;
// const OVERFLOW_FLAG: u32 = 0x08;
const SIGN_FLAG: u32 = 0x10;
pub struct VirtualMachine {
    stack: super::stack::Stack<u8>,
    stream: super::istream::IStream,
    flags: u32,
}

impl VirtualMachine {
    pub fn new(stream: super::istream::IStream) -> Self {
        VirtualMachine {
            stack: super::stack::Stack::new(1024),
            stream: stream,
            flags: 0,
        }
    }

    pub fn run(&mut self) {
        loop {
            let next_byte = (&mut self.stream).pop_next();

            match next_byte {
                Ok(v) => {
                    self.match_opcode(v.as_opcode());
                }
                Err(_) => {
                    break;
                }
            }
        }
        println!("end");
    }

    #[allow(dead_code)]
    pub fn execute_instructions(&mut self, instructions: Vec<u8>) {
        let inst_slice = instructions.as_slice();
        for i in 0..inst_slice.len() {
            self.match_opcode(inst_slice[i].as_opcode());
        }
    }

    fn match_opcode(&mut self, opcode: Opcode) {
        match opcode {
            Opcode::Nop => {}
            Opcode::PushConstInteger => self.push_next_bytes(INT_SIZE, false),
            Opcode::PushConstFloat => self.push_next_bytes(FLOAT_SIZE, false),
            Opcode::PushConstChar => self.push_next_bytes(CHAR_SIZE, false),
            Opcode::PushConstBoolean => self.push_next_bytes(BOOLEAN_SIZE, false),
            Opcode::Add => self.stack_integer_add(),
            Opcode::Subtract => self.stack_integer_subtract(),
            Opcode::IntegerMultiply => self.stack_integer_multiply(),
            Opcode::IntegerDivide => self.stack_integer_divide(),
        };
    }

    fn push_next_byte(&mut self) {
        let byte = match self.stream.pop_next() {
            Ok(b) => b,
            Err(_) => {
                self.panic("Failed to read next byte", -2);
                0
            }
        };

        self.stack.push(byte);
    }

    fn push_next_bytes(&mut self, bytes: usize, sign_extend: bool) {
        if bytes == STACK_WIDTH {
            for _ in 0..bytes {
                self.push_next_byte();
            }
        } else {
            let popped_bytes = self.stream.pop_bytes(bytes);
            let negative = (popped_bytes[popped_bytes.len() - 1] & 0b10000000) != 0;
            for i in 0..STACK_WIDTH {
                if i >= (STACK_WIDTH - bytes) {
                    self.stack.push(popped_bytes[STACK_WIDTH - i - 1])
                } else {
                    if sign_extend {
                        self.stack.push(if negative { 0xFF } else { 0 });
                    } else {
                        self.stack.push(0);
                    }
                }
            }
        }
    }

    fn panic(&self, msg: &str, exit_code: i32) {
        println!("Xva panicked!\n{}", msg);
        std::process::exit(exit_code);
    }

    fn pop_long(&mut self) -> i64 {
        let bytes = self.stack.pop_bytes(8);
        let mut result: i64 = 0;
        for i in 0..8 {
            result += bytes[i] as i64;
        }

        result
    }

    fn push_long(&mut self, value: i64) {
        for i in 0..STACK_WIDTH {
            let shift_length = (8 * 7) - (8 * i);
            self.stack.push(((value >> shift_length) & 0xFF) as u8);
        }
    }

    fn pop_binary_operands(&mut self) -> (i64, i64) {
        (self.pop_long(), self.pop_long())
    }

    fn stack_integer_add(&mut self) {
        let right = self.pop_long();
        let left = self.pop_long();
        let result = left + right;
        self.check_flags(result);

        for i in 0..STACK_WIDTH {
            let shift_length = (8 * 7) - (8 * i);
            self.stack.push(((result >> shift_length) & 0xFF) as u8);
        }
    }

    fn stack_integer_subtract(&mut self) {
        let right = self.pop_long();
        let left = self.pop_long();
        let result = left - right;
        self.check_flags(result);
        self.push_long(result);
    }

    fn stack_integer_multiply(&mut self) {
        let (right, left) = self.pop_binary_operands();
        let result = left * right;
        self.check_flags(result);
        self.push_long(result);
    }

    fn stack_integer_divide(&mut self) {
        let (right, left) = self.pop_binary_operands();
        let result = left / right;
        self.check_flags(result);
        self.push_long(result);
    }

    fn check_flags(&mut self, result: i64) {
        let mut flag = 0;
        if self.get_parity(result) {
            flag |= PARITY_FLAG;
        }

        if result == 0 {
            flag |= ZERO_FLAG;
        }

        if result as u64 & 0x8000_0000_0000_0000 != 0 {
            flag |= SIGN_FLAG;
        }

        self.set_flags(flag);
    }

    fn set_flags(&mut self, flag: u32) {
        self.flags |= flag;
    }

    fn get_parity(&self, value: i64) -> bool {
        let mut num_set = 0;
        for i in 0..64 {
            if value >> i != 0 {
                num_set += 1
            }
        }

        num_set % 2 == 0
    }
}
