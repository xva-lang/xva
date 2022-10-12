use std::collections::HashMap;

use crate::{constants, machine::code::Binding};

use self::stack::dump_stack;
pub mod code;
pub mod istream;
pub mod stack;

pub struct Machine<'a> {
    stack: &'a mut stack::EvaluationStack,
}

impl Machine<'_> {
    pub fn panic(&self, msg: &str) {
        println!("Xva panicked!");
        println!("{}", msg);
        println!("");
        println!("Current evaluation stack:\n");
        stack::dump_stack(self.stack);
        std::process::exit(-1);
    }
}

pub fn run_machine(stream: &mut istream::IStream, stack: &mut Box<stack::EvaluationStack>) {
    let mut frame = code::Frame {
        locals: HashMap::<u32, code::Binding>::new(),
    };

    let mut instruction: u8;
    loop {
        instruction = match (stream.get_vec_ref()).get(stream.instruction_pointer) {
            Some(inst) => *inst,
            None => {
                println!("end of stream");
                constants::instruction::NOP
            }
        };

        match instruction {
            constants::instruction::NOP => {}
            constants::instruction::PUSH_UINT8 => push_uint8(stream, stack.as_mut()),
            constants::instruction::PUSH_UINT16 => push_uint16(stream, stack.as_mut()),
            constants::instruction::PUSH_UINT32 => push_uint32(stream, stack.as_mut()),
            constants::instruction::DECLARE_LOCAL => {
                let machine = Machine {
                    stack: (stack.as_mut()),
                };
                declare_local(stream, &mut frame, &machine)
            }
            constants::instruction::STORE_LOCAL => {
                let mut machine = Machine {
                    stack: stack.as_mut(),
                };
                store_local(stream, &mut frame, &mut machine);
            }
            _ => panic!("unhandled instruction 0x{:x}", instruction),
        }

        stream.increment_instruction_pointer();
        if stream.instruction_pointer > stream.stream_size {
            break;
        }
    }

    dump_stack(stack.as_ref());
}

fn push_uint8(stream: &mut istream::IStream, current_stack: &mut stack::EvaluationStack) {
    stream.increment_instruction_pointer();
    current_stack.push_uint8(stream.read_uint8());
}

fn push_uint16(stream: &mut istream::IStream, current_stack: &mut stack::EvaluationStack) {
    stream.increment_instruction_pointer();
    current_stack.push_uint16(stream.read_uint16());
}

fn push_uint32(stream: &mut istream::IStream, current_stack: &mut stack::EvaluationStack) {
    stream.increment_instruction_pointer();
    current_stack.push_uint32(stream.read_uint32());
    stream.decrement_instruction_pointer();
}

fn declare_local(stream: &mut istream::IStream, frame: &mut code::Frame, machine: &Machine) {
    // 0x5 @ n
    // size of name, 2 bytes  @ n + 1
    // name @ n + 3
    // size of local, 4 bytes @ n + 3 + size of name
    stream.increment_instruction_pointer();
    let size_of_name = stream.read_uint16();
    let name = stream.read_string(size_of_name as usize, machine);
    let size_of_local = stream.read_uint32();
    let new_local = Binding {
        size: size_of_local as usize,
        name: name,
        bytes: vec![],
    };
    match frame.locals.insert(frame.locals.len() as u32, new_local) {
        Some(_) => {}
        None => {}
    }
    stream.decrement_instruction_pointer();
}

fn store_local(stream: &mut istream::IStream, frame: &mut code::Frame, machine: &mut Machine) {
    // 0x6 @ n
    // index of local (4 bytes) @ n+1
    stream.increment_instruction_pointer();
    let local_index = stream.read_uint32();
    let mut binding = Binding {
        size: 0,
        name: String::from(""),
        bytes: vec![],
    };

    let kv = match frame.locals.get_mut(&local_index) {
        Some(val) => val,
        None => {
            machine.panic("Attempted to store to local variable that does not exist.");
            &mut binding
        }
    };

    for _ in 0..kv.size {
        kv.bytes.push(machine.stack.pop_byte());
    }
}
