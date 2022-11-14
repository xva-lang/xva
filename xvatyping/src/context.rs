use crate::Type;
use std::collections::HashMap;

pub struct TypeContext {
    entries: HashMap<String, Type>,
}

impl TypeContext {
    pub fn new() -> Self {
        Self {
            entries: HashMap::new(),
        }
    }
}
