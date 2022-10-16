// pub mod constants;
pub mod instruction;
#[allow(dead_code)]
pub enum ErrorCodes {
    Unknown = -1,
    StackOverflow,
}

pub const MAGIC_NUMBER: [u8; 8] = [0, 0, 120, 118, 97, 0, 0, 1];
