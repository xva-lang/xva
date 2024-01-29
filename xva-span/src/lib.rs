use std::{fmt::Debug, ops::Range};

pub(crate) mod monotonic;
pub mod source;
/// Represents a section of the original source code.
///
/// Can also be used to represent generic "slices" of "things" with an explicit start and end.
///
/// Copying and cloning should be cheap.
// #[derive(Debug, Clone, Copy)]
// pub struct Span {
//     start: u32,
//     end: u32,
// }

// impl From<Range<u32>> for Span {
//     fn from(value: Range<u32>) -> Self {
//         let (start, end) = (value.start, value.end);
//         Self { start, end }
//     }
// }

// impl From<Span> for Range<usize> {
//     fn from(value: Span) -> Self {
//         let Span { start, end } = value;
//         start as usize..end as usize
//     }
// }

// impl PartialEq for Span {
//     fn eq(&self, other: &Self) -> bool {
//         self.start == other.start && self.end == other.end
//     }
// }

// impl Eq for Span {}

// /// A single point in the source code.
// ///
// /// This type manually implements Debug, to reduce the noise of extra indentation
// /// when pretty-printing big structs that have this type deeply nested.
// #[derive(Clone, Copy)]
// pub struct SourcePoint(u32, u32);

// impl SourcePoint {
//     pub fn new(line: u32, col: u32) -> Self {
//         Self(line, col)
//     }

//     /// Returns the line number of this position
//     pub fn line(&self) -> u32 {
//         let Self(line, _) = self;
//         *line
//     }

//     /// Returns the column of this position
//     pub fn col(&self) -> u32 {
//         let Self(_, col) = self;
//         *col
//     }
// }

// impl std::fmt::Display for SourcePoint {
//     fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
//         let Self(line, col) = self;
//         write!(f, "{line}:{col}")
//     }
// }

// impl std::fmt::Debug for SourcePoint {
//     fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
//         // f.debug_tuple("SourceLocation").field(&self.0).field(&self.1).finish()
//         write!(f, "{self}")
//     }
// }

// impl From<tree_sitter::Point> for SourcePoint {
//     fn from(value: tree_sitter::Point) -> Self {
//         let tree_sitter::Point { row, column } = value;

//         // SAFETY: this cast is safe - the two values inside TSPoint are uint32_t's
//         // https://github.com/tree-sitter/tree-sitter/blob/master/lib/include/tree_sitter/api.h#L63
//         Self(row as u32, column as u32)
//     }
// }

// /// A higher resolution location in source code.
// ///
// /// This type manually implements Debug, to reduce the noise of extra indentation
// /// when pretty-printing big structs that have this type deeply nested.
// #[derive(Clone, Copy)]
// pub struct SourceLocation {
//     pub start: SourcePoint,
//     pub end: SourcePoint,
// }

// impl SourceLocation {
//     pub fn new(start: SourcePoint, end: SourcePoint) -> Self {
//         Self { start, end }
//     }

//     pub fn as_char_offset(&self, _src: &str) -> Span {
//         // TODO this doesn't actually use lines
//         let SourcePoint(_, start_col) = self.start;
//         let SourcePoint(_, end_col) = self.end;
//         (start_col..end_col).into()
//     }
// }

// impl std::fmt::Display for SourceLocation {
//     fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
//         write!(f, "{}..{}", self.start, self.end)
//     }
// }

// impl std::fmt::Debug for SourceLocation {
//     fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
//         // f.debug_tuple("SourceLocation").field(&self.0).field(&self.1).finish()
//         write!(f, "{self}")
//     }
// }

#[cfg(test)]
mod tests {
    // #[test]
    // fn from_range() {
    //     use super::Span;
    //     let test: Span = (0..4).into();
    //     assert_eq!(test, Span { start: 0, end: 4 })
    // }
}
