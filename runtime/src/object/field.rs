/// A convenience type for a container of `ObjectFieldPair`s. Users of the type must **not** assume
/// the collection is ordered.
pub(crate) type ObjectFieldDescriptors = Vec<ObjectFieldDescriptor>;

/// Represents a field inside an object, containing its offset relative to the
/// bottom of the object header and the field's size.
///
/// This object is cheap to clone.
///
/// # Stability
/// This API is **unstable** and is therefore highly subject to change without warning.
#[derive(Clone)]
pub(crate) struct ObjectFieldDescriptor {
    /// The size of the field, in bytes.
    size: usize,
}

impl ObjectFieldDescriptor {
    pub(super) fn new(size: usize) -> Self {
        Self { size }
    }

    pub(super) fn get_size(&self) -> usize {
        self.size
    }
}
