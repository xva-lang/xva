use std::sync::Arc;

use xva_span::{SourceId, SourceMap};
pub struct Compiler {
    source_map: SourceMap,
}

impl Default for Compiler {
    fn default() -> Self {
        Self {
            source_map: Default::default(),
        }
    }
}

impl Compiler {
    pub fn load_virtual_file(&mut self, name: String, src: String) -> SourceId {
        self.source_map.load_virtual(name, src)
    }

    pub fn get_file_content(&self, id: SourceId) -> Option<Arc<str>> {
        self.source_map.get_raw(id)
    }
}

#[cfg(test)]
mod tests {}
