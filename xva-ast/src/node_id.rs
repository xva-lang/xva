use std::ops::AddAssign;

/// A unique ID for every node in the AST.
///
/// The [`Debug`] implementation is overridden with a custom version that just prints the
/// inner number, because otherwise the debug print of the entire AST has a **huge** amount of
/// unnecessary indentation because of the default derivation of [`Debug`] for tuple structs.
#[derive(Clone, Copy)]
pub struct NodeId(pub i64);

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

impl From<i64> for NodeId {
    fn from(value: i64) -> Self {
        Self(value)
    }
}

impl AddAssign<i64> for NodeId {
    fn add_assign(&mut self, rhs: i64) {
        self.0 += rhs
    }
}

pub const PLACEHOLDER_NODE_ID: NodeId = NodeId(i64::MAX);
pub const ERROR_NODE_ID: NodeId = NodeId(-1);
