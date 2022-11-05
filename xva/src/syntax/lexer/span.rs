use std::ops::Range;

#[derive(Debug, Copy, Clone)]
pub struct Span {
    pub start: usize,
    pub end: usize,
}

impl From<Range<usize>> for Span {
    fn from(v: Range<usize>) -> Self {
        Self {
            start: v.start,
            end: v.end,
        }
    }
}

impl From<Span> for Range<usize> {
    fn from(v: Span) -> Self {
        Self {
            start: v.start,
            end: v.end,
        }
    }
}

impl std::fmt::Display for Span {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}..{}", self.start, self.end)
    }
}
