use xva_ast::node_id::NodeId;

/// Convenience trait marking an item exported by TreeSitter as having some unique identifier in the tree,
/// that can be safely represented as a [`NodeId`].
pub(crate) trait TSIdentifyable {
    fn node_id(&self) -> NodeId;
}

impl TSIdentifyable for tree_sitter::TreeCursor<'_> {
    /// Returns the node ID of the cursor's current node, as a [`NodeId`].
    fn node_id(&self) -> NodeId {
        (self.node().id() as u32).into()
    }
}

impl TSIdentifyable for tree_sitter::Node<'_> {
    /// Returns the node ID of the node, as a [`NodeId`].
    fn node_id(&self) -> NodeId {
        (self.id() as u32).into()
    }
}
