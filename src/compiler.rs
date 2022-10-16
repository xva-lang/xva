// use crate::machine;
use crate::parser;
use queues::Buffer;

pub struct Compiler {
    stream: Buffer<u8>,
}

impl Compiler {
    pub fn new() -> Self {
        Self {
            stream: Buffer::new(1024),
        }
    }

    pub fn compile_file(&self, file_name: String) {
        // let output_file_name = file_name.replace(".xva", ".xvo");
        parser::parse_file(file_name);
    }
}
