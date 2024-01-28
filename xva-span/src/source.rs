use sha2::{Digest, Sha256};
use std::{
    collections::HashMap,
    io::Read,
    path::PathBuf,
    sync::{Arc, RwLock},
};

use crate::monotonic::MonotonicVec;

#[derive(Debug)]
pub enum SourceFilePath {
    /// A real file that exists on disk. The path must be absolute and canonicalized.
    Real(PathBuf),

    /// A virtual file, such as stdin, the REPL input, etc.
    Virtual(String),
}

/// A container for a source file being compiled. The actual source text is immutable.
///
/// The implementation of [`Debug`](std::fmt::Debug) is hand-written to be able to display the hash as a hex string, rather
/// than an array of bytes.

pub struct SourceFile {
    /// The path of the source file. This may be an anonymous "fake" path, e.g. `<repl>` for code
    /// entered in the REPL.
    pub path: SourceFilePath,

    /// The name of the source file. This may be an anonymous "fake" path, e.g. `<repl>` for code
    /// entered in the REPL.
    ///
    /// If the file is a real file, this name should be the path to this file, relative
    /// to either:
    /// - The file on which the compiler was invoked on, or
    /// - The working directory where the compiler was invoked.
    pub name: String,

    /// The SHA2 of the file's content.
    pub hash: [u8; 32],

    /// The original content of the file.
    pub src: Arc<String>,
}

impl SourceFile {
    fn hash_as_hex(&self) -> String {
        self.hash
            .iter()
            .map(|h| format!("{h:02x}"))
            .collect::<String>()
    }
}

impl std::fmt::Debug for SourceFile {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("SourceFile")
            .field("path", &self.path)
            .field("name", &self.name)
            .field("hash", &self.hash_as_hex())
            .field("src", &self.src)
            .finish()
    }
}
impl SourceFile {
    pub fn new(name: String, path: SourceFilePath, src: String) -> Self {
        Self {
            path,
            name,
            hash: {
                let mut hasher: Sha256 = Sha256::new();
                hasher.update(src.as_bytes());
                hasher
                    .finalize()
                    .as_slice()
                    .try_into()
                    .expect("Wrong length")
            },
            src: Arc::new(src),
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct SrcId(u32);

impl From<u32> for SrcId {
    fn from(value: u32) -> Self {
        Self(value)
    }
}

pub struct SourceMap {
    files: RwLock<MonotonicVec<Arc<SourceFile>>>,
    map: HashMap<SrcId, Arc<SourceFile>>,
}

impl SourceMap {
    const FIRST_SRC_ID: SrcId = SrcId(0);

    /// Loads a real file into the source map.
    pub fn load(&mut self, path: PathBuf) -> std::io::Result<SrcId> {
        let name = path.clone().into_os_string().into_string().unwrap();

        let mut buf = String::new();
        let mut file = std::fs::OpenOptions::new().read(true).open(&path)?;
        file.read_to_string(&mut buf)?;

        Ok(self.new_file(name, SourceFilePath::Real(path.canonicalize()?), buf))
    }

    /// Loads a virtual file into the source map. A virtual file is just a named string of text.
    pub fn load_virtual(&mut self, name: String, src: String) -> SrcId {
        let virtual_file_name = name.clone();
        self.new_file(name, SourceFilePath::Virtual(virtual_file_name), src)
    }

    fn new_file(&mut self, name: String, path: SourceFilePath, src: String) -> SrcId {
        let mut files = match self.files.write() {
            Ok(l) => l,
            Err(e) => panic!("Source map lock is poisoned: {e}"),
        };

        let arc = Arc::new(SourceFile::new(name, path, src));
        files.push(arc.clone());
        let id = self.next_id();
        self.map.insert(id.clone(), arc.clone());
        id
    }

    fn next_id(&self) -> SrcId {
        self.map
            .iter()
            .last()
            .map_or_else(|| Self::FIRST_SRC_ID, |(k, _)| *k)
    }

    /// Locates a file in the source map and returns an `Arc` to it, if it has previously been loaded.
    pub fn get<I: Into<SrcId>>(&self, id: I) -> Option<Arc<SourceFile>> {
        match self.map.get(&id.into()) {
            Some(v) => Some(v.clone()),
            None => None,
        }
    }
}

impl Default for SourceMap {
    fn default() -> Self {
        Self {
            files: Default::default(),
            map: Default::default(),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::SourceMap;

    #[test]
    fn can_load_real_source_file() {
        let mut map = SourceMap::default();
        map.load("../xva-treesitter/main.xva".into()).unwrap();
        println!("{:#?}", map.get(0))
    }

    #[test]
    fn source_map_returns_not_found() {
        let mut map = SourceMap::default();
        assert_eq!(map.load("nonexistent.txt".into()).is_err(), true)
    }
}
