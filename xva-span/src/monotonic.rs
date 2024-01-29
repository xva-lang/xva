use std::ops::Deref;

/// A `MonotonicVec` is a `Vec` which can only be grown.
/// Once inserted, an element can never be removed or swapped,
/// guaranteeing that any indices into a `MonotonicVec` are stable
///
/// This implementation was borrowed from the
/// [Rust compiler](https://github.com/rust-lang/rust/blob/master/compiler/rustc_span/src/source_map.rs).
#[derive(Debug)]
pub(crate) struct MonotonicVec<T>(Vec<T>);
impl<T> MonotonicVec<T> {
    pub(super) fn push(&mut self, val: T) {
        self.0.push(val);
    }
}

impl<T> Default for MonotonicVec<T> {
    fn default() -> Self {
        MonotonicVec(vec![])
    }
}

impl<T> Deref for MonotonicVec<T> {
    type Target = Vec<T>;
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}
