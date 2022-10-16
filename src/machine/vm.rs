// use std::u64::MAX;

use crate::runtime::typing::byte_sizeable::{
    BYTE_SIZE, CHAR_SIZE, INT_SIZE, LONG_SIZE, SHORT_SIZE,
};

const STACK_WIDTH: usize = 8;
// const CARRY_FLAG: u32 = 0x01;
const PARITY_FLAG: u32 = 0x02;
const ZERO_FLAG: u32 = 0x04;
const OVERFLOW_FLAG: u32 = 0x08;
const SIGN_FLAG: u32 = 0x10;
pub struct VirtualMachine {
    stack: super::stack::Stack<u8>,
    stream: super::istream::IStream,
    flags: u32,
}

pub enum Opcode {
    Nop,
    PushConstUInt8,
    PushConstUInt16,
    PushConstUInt32,
    PushConstUInt64,
    PushConstInt8,
    PushConstInt16,
    PushConstInt32,
    PushConstInt64,
    PushChar,
    Add,
    Subtract,
    IntegerMultiply,
    IntegerDivide,
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
                Ok(op) => {
                    self.match_opcode(self.byte_to_opcode(op));
                }
                Err(_) => {
                    break;
                    // std::process::exit(0);
                }
            }
        }
        println!("end");
    }

    fn byte_to_opcode(&self, byte: u8) -> Opcode {
        match byte {
            0 => Opcode::Nop,
            1 => Opcode::PushConstUInt8,
            2 => Opcode::PushConstUInt16,
            3 => Opcode::PushConstUInt32,
            4 => Opcode::PushConstUInt64,
            5 => Opcode::PushConstInt8,
            6 => Opcode::PushConstInt16,
            7 => Opcode::PushConstInt32,
            8 => Opcode::PushConstInt64,
            9 => Opcode::PushChar,
            10 => Opcode::Add,
            11 => Opcode::Subtract,
            12 => Opcode::IntegerMultiply,
            13 => Opcode::IntegerDivide,
            _ => {
                self.panic(format!("Unknown opcode {:#x}", byte).as_str(), -1);
                Opcode::Nop
            }
        }
    }

    fn match_opcode(&mut self, opcode: Opcode) {
        match opcode {
            Opcode::Nop => println!("Nop!"),
            Opcode::PushConstUInt8 => self.push_next_bytes(BYTE_SIZE, false),
            Opcode::PushConstUInt16 => self.push_next_bytes(SHORT_SIZE, false),
            Opcode::PushConstUInt32 => self.push_next_bytes(INT_SIZE, false),
            Opcode::PushConstUInt64 => self.push_next_bytes(LONG_SIZE, false),
            Opcode::PushConstInt8 => self.push_next_bytes(BYTE_SIZE, true),
            Opcode::PushConstInt16 => self.push_next_bytes(SHORT_SIZE, true),
            Opcode::PushConstInt32 => self.push_next_bytes(INT_SIZE, true),
            Opcode::PushConstInt64 => self.push_next_bytes(LONG_SIZE, true),
            Opcode::PushChar => self.push_next_bytes(CHAR_SIZE, true),
            Opcode::Add => self.stack_add(),
            Opcode::Subtract => self.stack_subtract(),
            Opcode::IntegerMultiply => self.stack_multiply(),
            Opcode::IntegerDivide => self.stack_divide(),
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

    fn stack_add(&mut self) {
        let right = self.pop_long();
        let left = self.pop_long();
        let result = left + right;
        self.check_flags(result);

        for i in 0..STACK_WIDTH {
            let shift_length = (8 * 7) - (8 * i);
            self.stack.push(((result >> shift_length) & 0xFF) as u8);
        }
    }

    fn stack_subtract(&mut self) {
        let right = self.pop_long();
        let left = self.pop_long();
        let result = left - right;
        self.check_flags(result);
        self.push_long(result);
    }

    fn stack_multiply(&mut self) {
        let (right, left) = self.pop_binary_operands();
        let result = left * right;
        self.check_flags(result);
        self.push_long(result);
    }

    fn stack_divide(&mut self) {
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
