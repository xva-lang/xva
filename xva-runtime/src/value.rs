#[derive(Clone)]
pub enum Value {
    Unit,
    Boolean(bool),
    Byte(u8),
    SignedByte(i8),
    Short(u16),
    SignedShort(i16),
    Int(u32),
    SignedInt(i32),
    Long(u64),
    SignedLong(i64),
    Float(f32),
    Double(f64),
    Char(char),
    Pointer(*const u8),
}

#[cfg(test)]
mod tests {}
