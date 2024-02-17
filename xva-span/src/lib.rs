use std::{
    fmt::{Debug, Display},
    ops::Range,
};

pub(crate) mod monotonic;
pub mod source;

pub type TokenSpan = chumsky::span::SimpleSpan<usize>;

#[derive(Clone, Copy)]
pub struct CheapRange<Idx>(Idx, Idx);

impl<Idx> CheapRange<Idx> {
    pub const fn new(start: Idx, end: Idx) -> Self {
        Self(start, end)
    }
}

impl<Idx> From<Range<Idx>> for CheapRange<Idx> {
    fn from(value: Range<Idx>) -> Self {
        let Range { start, end } = value;
        Self(start, end)
    }
}

impl<Idx> PartialEq for CheapRange<Idx>
where
    Idx: PartialEq,
{
    fn eq(&self, other: &Self) -> bool {
        self.0 == other.0 && self.1 == other.1
    }
}

impl<Idx> Eq for CheapRange<Idx> where Idx: Eq {}

impl<Idx> std::fmt::Debug for CheapRange<Idx>
where
    Idx: Display,
{
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let CheapRange(start, end) = self;
        write!(f, "{start}..{end}")
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct SourceId(u32);

impl From<u32> for SourceId {
    fn from(value: u32) -> Self {
        Self(value)
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct SourceSpan {
    src: SourceId,
    range: CheapRange<usize>,
}

impl SourceSpan {
    pub const fn new(src: SourceId, range: CheapRange<usize>) -> Self {
        Self { src, range }
    }

    pub fn src(&self) -> SourceId {
        self.src
    }
}

impl ariadne::Span for SourceSpan {
    type SourceId = SourceId;

    fn source(&self) -> &Self::SourceId {
        &self.src
    }

    fn start(&self) -> usize {
        let CheapRange(start, _) = self.range;
        start
    }

    fn end(&self) -> usize {
        let CheapRange(_, end) = self.range;
        end
    }
}

#[cfg(test)]
mod tests {
    // #[test]
    // fn from_range() {
    //     use super::Span;
    //     let test: Span = (0..4).into();
    //     assert_eq!(test, Span { start: 0, end: 4 })
    // }
}
