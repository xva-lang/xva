use sha2::{Digest, Sha256};
use std::{
    collections::HashMap,
    io::Read,
    marker::PhantomData,
    ops::Range,
    path::PathBuf,
    sync::{Arc, RwLock},
};

use crate::monotonic::MonotonicVec;

mod codespan;

#[derive(Debug)]
pub enum LineEnding {
    /// LF, or `\n`
    Unix,

    /// CRLF, or `\r\n`
    Windows,

    /// The file only has one line
    OneLine,
}

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
    // pub src: String,
    pub src: Arc<str>,
    line_ending: LineEnding,
    line_ranges: HashMap<Range<usize>, usize>,
}

impl SourceFile {
    pub fn new(name: String, path: SourceFilePath, src: String) -> Self {
        let line_ending = get_line_ending(src.as_bytes());
        let mut current_line = 0usize;
        let mut current_byte = 0usize;
        let mut line_start_byte = 0usize;

        let line_ranges = match line_ending {
            LineEnding::Unix => {
                let mut temp = HashMap::new();

                for b in src.as_bytes() {
                    if *b == '\n' as u8 {
                        temp.insert(line_start_byte..current_byte, current_line);

                        line_start_byte = current_byte + 1;
                        current_line += 1;
                    }

                    current_byte += 1;
                }

                temp
            }
            LineEnding::Windows => todo!(),
            LineEnding::OneLine => HashMap::from([(0..src.as_bytes().len(), 0)]),
        };

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
            src: Arc::from(src.as_str()),
            line_ranges,
            line_ending,
        }
    }

    fn hash_as_hex(&self) -> String {
        self.hash
            .iter()
            .map(|h| format!("{h:02x}"))
            .collect::<String>()
    }

    pub fn content(&self) -> Arc<str> {
        self.src.clone()
    }

    pub fn bytes(&self) -> &[u8] {
        self.src.as_ref().as_bytes()
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

fn get_line_ending(src: &[u8]) -> LineEnding {
    match src.iter().enumerate().find(|(_, b)| **b == '\n' as u8) {
        Some((index, _)) => {
            if src[index - 1] == '\r' as u8 {
                LineEnding::Windows
            } else {
                LineEnding::Unix
            }
        }
        None => LineEnding::OneLine,
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct SrcId(u32);

impl From<u32> for SrcId {
    fn from(value: u32) -> Self {
        Self(value)
    }
}

#[derive(Debug)]
pub struct SourceMap<'map> {
    files: RwLock<MonotonicVec<Arc<SourceFile>>>,
    map: HashMap<SrcId, Arc<SourceFile>>,
    _phantom_lt: PhantomData<&'map ()>,
}

impl SourceMap<'_> {
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

impl Default for SourceMap<'_> {
    fn default() -> Self {
        Self {
            files: Default::default(),
            map: Default::default(),
            _phantom_lt: Default::default(),
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