pub const NOP: u8 = 0;
/// Pushes a constant byte onto the stack.
pub const PUSH_UINT8: u8 = 1;

/// Pushes a constant unsigned short (2 bytes, little-endian) onto the stack.
pub const PUSH_UINT16: u8 = 2;

/// Pushes a constant unsigned integer (4 bytes, little-endian) onto the stack.
pub const PUSH_UINT32: u8 = 3;

/// Pushes a constant unsigned long (8 bytes, little-endian) onto the stack.
#[allow(dead_code)]
pub const PUSH_UINT64: u8 = 4;

/// Declares a local variable with a specified name and size.
pub const DECLARE_LOCAL: u8 = 5;

/// Pops x bytes off the stack and stores in the specified local,
/// where x is the size of the specified local
pub const STORE_LOCAL: u8 = 6;
