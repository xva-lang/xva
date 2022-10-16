#[derive(Clone)]
pub enum Type {
    UnsignedInt(UnsignedIntType),
    SignedInt(SignedIntType),
    Char(char),
}

#[derive(Clone)]
pub enum UnsignedIntType {
    UInt8,
    UInt16,
    UInt32,
    UInt64,
}

#[derive(Clone)]
pub enum SignedIntType {
    Int8,
    Int16,
    Int32,
    Int64,
}
