use std::ops::Range;

/// A mapping from an absolute character offset to its line number relative to the start of the original input.
#[derive(Debug)]
pub(crate) struct LineIndex {
    pub(crate) range: Range<usize>,
    line: usize,
}

impl LineIndex {
    pub(crate) fn new(range: Range<usize>, line: usize) -> Self {
        Self { range, line }
    }
}

/// A container for `LineIndex`es
#[derive(Debug)]
pub(crate) struct LineIndexes {
    indexes: Vec<LineIndex>,
}

impl LineIndexes {
    pub fn new() -> Self {
        Self { indexes: vec![] }
    }

    /// Appends a new `LineIndex` to the container.
    /// # Arguments
    /// `index` - The new `LineIndex` to append to the container.
    pub(crate) fn push(&mut self, index: LineIndex) {
        self.indexes.push(index)
    }

    pub(crate) fn matched_lines_as_vec(&mut self, line: usize) -> Vec<LineIndex> {
        let mut result_vec: Vec<LineIndex> = vec![];
        for index in self.indexes.iter() {
            if index.line == line {
                result_vec.push(LineIndex {
                    range: index.range.clone(),
                    line: index.line,
                })
            }
        }

        result_vec
    }

    /// Retrives the range of lines that a specified character offset occupies.
    /// # Arguments
    /// `requested_range`: A `Range<usize>` representing the start (inclusive) and end (exclusive) of a portion of the
    /// input.
    /// # Returns
    /// `Some(Range<usize>)` if the container has at least one line index that fully contains `requested_range`,
    /// otherwise `None`.
    pub(crate) fn get_line(&mut self, requested_range: Range<usize>) -> Option<Range<usize>> {
        if self.indexes.len() == 0 {
            return None;
        }

        // Cannot safely .unwrap() after the .map() because the conditional above guarantees the iterator
        // returned by .iter() is not empty, but not the chained .filter().
        let (min, max) = (
            self.indexes
                .iter()
                .filter(|entry| Self::token_in_range(entry, &requested_range))
                .map(|x| x.line)
                .min(),
            self.indexes
                .iter()
                .filter(|entry| Self::token_in_range(entry, &requested_range))
                .map(|x| x.line)
                .max(),
        );

        return match (min, max) {
            (Some(min), Some(max)) => Some(Range::<usize> {
                start: min,
                end: max,
            }),
            _ => None,
        };
    }

    fn token_in_range(entry: &LineIndex, requested_range: &Range<usize>) -> bool {
        entry.range.start >= requested_range.start || entry.range.end <= requested_range.end
    }
}
