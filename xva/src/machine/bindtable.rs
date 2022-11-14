use crate::runtime::typing::builtins::ValueType;
use std::collections::HashMap;

#[derive(Debug)]
pub(crate) struct BindingTableEntry {
    value: ValueType,
}

impl BindingTableEntry {
    pub fn new(value: ValueType) -> Self {
        Self { value }
    }

    pub fn get_value(&self) -> ValueType {
        self.value.clone()
    }
}

pub(crate) struct BindingTable {
    symbols: HashMap<String, BindingTableEntry>,
}

impl BindingTable {
    pub fn new() -> Self {
        Self {
            symbols: HashMap::new(),
        }
    }

    pub fn new_symbol(&mut self, name: String, value_type: ValueType) {
        self.symbols
            .insert(name, BindingTableEntry::new(value_type));
    }

    pub fn lookup(&self, name: &str) -> Option<&BindingTableEntry> {
        self.symbols.get(&name.to_string())
    }

    pub fn update_value(&mut self, name: String, new_value: ValueType) {
        match self.symbols.get_mut(&name) {
            Some(val) => val.value = new_value,
            None => self.new_symbol(name, new_value),
        }
    }
}
