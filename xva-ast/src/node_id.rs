use std::ops::AddAssign;

/// A unique ID for every node in the AST.
///
/// This is (usually) set directly to the node ID we receive from TreeSitter.
///
/// The [`Debug`] implementation is overridden with a custom version that just prints the
/// inner number, because otherwise the debug print of the entire AST has a **huge** amount of
/// unnecessary indentation because of the default derivation of [`Debug`] for tuple structs.
#[derive(Clone, Copy)]
pub struct NodeId(pub u32);

// Custom implementation of [`Debug`] instead of the derive macro
// to reduce noisy indentation of AST debug prints.
impl std::fmt::Debug for NodeId {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        // f.debug_tuple("NodeId").field(&self.0).finish()
        write!(f, "{}", self.0)
    }
}

impl PartialEq for NodeId {
    fn eq(&self, other: &Self) -> bool {
        // self.0 == other.0
        let Self(this) = self;
        let Self(other) = other;
        this == other
    }
}

impl Eq for NodeId {}

impl From<u32> for NodeId {
    fn from(value: u32) -> Self {
        Self(value)
    }
}

impl AddAssign<u32> for NodeId {
    fn add_assign(&mut self, rhs: u32) {
        self.0 += rhs
    }
}

pub const PLACEHOLDER_NODE_ID: NodeId = NodeId(u32::MAX);
