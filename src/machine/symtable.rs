use crate::{runtime::typing::builtins::ValueType, syntax::lexer::span::Span};
use std::collections::HashMap;

pub(crate) struct SymbolTableEntry {
    value: ValueType,
    line: usize,
    span: Span,
}

impl SymbolTableEntry {
    pub fn new(value: ValueType, line: usize, span: Span) -> Self {
        Self { value, line, span }
    }

    pub fn get_type(&self) -> &ValueType {
        &self.value
    }
}

pub(crate) struct SymbolTable {
    symbols: HashMap<String, SymbolTableEntry>,
}

impl SymbolTable {
    pub fn new() -> Self {
        Self {
            symbols: HashMap::new(),
        }
    }

    pub fn new_symbol(&mut self, name: String, value_type: ValueType, line: usize, span: Span) {
        self.symbols
            .insert(name, SymbolTableEntry::new(value_type, line, span));
    }

    pub fn lookup(&self, name: &str) -> Option<&SymbolTableEntry> {
        self.symbols.get(&name.to_string())
    }
}
