use crate::{Expression, Item, NodeId};

/// Trait for marking AST items that have a [`NodeId`] on them, and providing functionalty to retrieve
/// the `NodeId`.
pub trait HasNodeId {
    fn node_id(&self) -> NodeId;
}

/// Convenience macro for automatically implementing [`HasNodeId`] on a given type. The given type
/// must have a field named `id`.
///
/// The macro also automatically tries to `#[inline]` the implementation.
macro_rules! has_node_id {
    // Start a repition `$(...)` with `$this`, which is a type `ty`,
    // seperated by commas, repeating zero or more times.
    ($($this:ty),*) => {
        $(impl HasNodeId for $this {
            #[inline]
            fn node_id(&self) -> NodeId {
                self.id
            }
        })*
    };
}

has_node_id!(Item, Expression);

#[cfg(test)]
mod tests {
    use crate::{traits::HasNodeId, NodeId};

    #[test]
    fn has_node_id_macro() {
        struct SomethingThatHasNodeId {
            id: NodeId,
        }

        has_node_id!(SomethingThatHasNodeId);
        let test = SomethingThatHasNodeId { id: NodeId(0) };

        assert_eq!(test.node_id(), NodeId(0))
    }
}
