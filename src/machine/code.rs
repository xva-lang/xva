use std::collections::HashMap;

pub struct Frame {
    pub locals: HashMap<u32, Binding>,
}

pub struct Binding {
    pub name: String,
    pub bytes: Vec<u8>,
    pub size: usize,
}
