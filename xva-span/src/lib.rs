pub(crate) mod monotonic;
pub mod source;

pub use source::{CheapRange, SourceId, SourceSpan, TokenSpan};

#[cfg(test)]
mod tests {}
