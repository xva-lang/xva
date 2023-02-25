/// An alias for an immutable pointer to a `MethodTable`.
pub type MethodTablePtr = *const MethodTable;

#[repr(C)]
#[derive(Debug)]
pub struct MethodTable {
    phantom: *const (),
}

impl MethodTable {
    pub fn new() -> Self {
        // TODO there should be something here other than a useless ()!
        Self {
            phantom: &() as *const (),
        }
    }

    #[allow(dead_code)]
    pub(super) fn as_ptr(&self) -> MethodTablePtr {
        self as MethodTablePtr
    }
}
