use crate::{runtime::typing::builtins::ValueType, syntax::lexer::span::Span};
use std::collections::HashMap;

const SYMBOL_MUTABLE: u32 = 1;

pub(crate) struct SymbolTableEntry {
    value: ValueType,
    flags: u32,
    _line: usize,
    _span: Span,
}

impl SymbolTableEntry {
    pub fn new(value: ValueType, line: usize, span: Span, mutable: bool) -> Self {
        let mut flags = 0;

        if mutable {
            flags += SYMBOL_MUTABLE
        }

        Self {
            value,
            _line: line,
            _span: span,
            flags,
        }
    }

    pub fn get_value(&self) -> ValueType {
        self.value.clone()
    }

    pub fn is_mutable(&self) -> bool {
        self.flags & SYMBOL_MUTABLE != 0
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

    pub fn new_symbol(
        &mut self,
        name: String,
        value_type: ValueType,
        line: usize,
        span: Span,
        mutable: bool,
    ) {
        self.symbols
            .insert(name, SymbolTableEntry::new(value_type, line, span, mutable));
    }

    pub fn lookup(&self, name: &str) -> Option<&SymbolTableEntry> {
        self.symbols.get(&name.to_string())
    }

    #[allow(dead_code)]
    pub fn update_value(&mut self, name: String, new_value: ValueType) {
        match self.symbols.get_mut(&name) {
            Some(val) => val.value = new_value,
            None => panic!("Undeclared symbol '{}'", name),
        }
    }
}
