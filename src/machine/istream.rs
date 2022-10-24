use queues::{Buffer, IsQueue};
use std::fs;
pub struct IStream {
    data: Buffer<u8>,
    _buffer_pointer: usize,
}

#[allow(dead_code)]
impl IStream {
    pub fn new(data: Buffer<u8>) -> Self {
        Self {
            data: data,
            _buffer_pointer: 0,
        }
    }

    pub fn from_file(file_name: &str) -> Result<Self, std::io::Error> {
        match fs::read(file_name) {
            Ok(data) => {
                let mut buf: Buffer<u8> = Buffer::new(data.len());
                for item in data {
                    match buf.add(item) {
                        Ok(_) => {}
                        Err(err) => panic!("Failed to create IStream buffer from file: {}", err),
                    };
                }
                Ok(Self {
                    data: buf,
                    _buffer_pointer: 0,
                })
            }
            Err(err) => Err(err),
        }
    }

    pub fn pop_next(&mut self) -> Result<u8, ()> {
        match self.data.remove() {
            Ok(value) => Ok(value),
            Err(_) => Err(()),
        }
    }

    pub fn advance_by(&mut self, advance_by: usize) {
        for _i in 0..advance_by {
            _ = self.pop_next();
        }
    }

    pub fn pop_bytes(&mut self, size: usize) -> Vec<u8> {
        let mut result = Vec::with_capacity(size);
        for _ in 0..size {
            match self.data.remove() {
                Ok(byte) => {
                    result.push(byte);
                }
                Err(e) => panic!("error reading bytes from stream: {}", e),
            }
        }

        return result;
    }
}
