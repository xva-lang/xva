use std::ops::Range;

/// Represents a section of the original source code.
///
/// Can also be used to represent generic "slices" of "things" with an explicit start and end.
///
/// Copying and cloning should be cheap.
#[derive(Debug, Clone, Copy)]
pub struct Span {
    start: u32,
    end: u32,
}

impl From<Range<u32>> for Span {
    fn from(value: Range<u32>) -> Self {
        let (start, end) = (value.start, value.end);
        Self { start, end }
    }
}

impl PartialEq for Span {
    fn eq(&self, other: &Self) -> bool {
        self.start == other.start && self.end == other.end
    }
}

impl Eq for Span {}

#[cfg(test)]
mod tests {
    #[test]
    fn from_range() {
        use super::Span;
        let test: Span = (0..4).into();
        assert_eq!(test, Span { start: 0, end: 4 })
    }
}
