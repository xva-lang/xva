use xva_ast::node_id::NodeId;
use xva_span::SourceLocation;

/// Convenience trait marking an item exported by TreeSitter as having some location in the source text,
/// that can be safely represented as a [`SourceLocation`].
pub(crate) trait TSLocatable {
    fn ts_span(&self) -> SourceLocation;
}

/// Convenience trait marking an item exported by TreeSitter as having some unique identifier in the tree,
/// that can be safely represented as a [`NodeId`].
pub(crate) trait TSIdentifyable {
    fn node_id(&self) -> NodeId;
}

impl TSLocatable for tree_sitter::TreeCursor<'_> {
    /// Returns the span of the cursor's current node, as a [`SourceLocation`]
    fn ts_span(&self) -> SourceLocation {
        SourceLocation::new(
            self.node().start_position().into(),
            self.node().end_position().into(),
        )
    }
}

impl TSIdentifyable for tree_sitter::TreeCursor<'_> {
    /// Returns the node ID of the cursor's current node, as a [`NodeId`].
    fn node_id(&self) -> NodeId {
        (self.node().id() as u32).into()
    }
}

impl TSLocatable for tree_sitter::Node<'_> {
    /// Returns the span of the node, as a [`SourceLocation`]
    fn ts_span(&self) -> SourceLocation {
        SourceLocation::new(self.start_position().into(), self.end_position().into())
    }
}

impl TSIdentifyable for tree_sitter::Node<'_> {
    /// Returns the node ID of the node, as a [`NodeId`].
    fn node_id(&self) -> NodeId {
        (self.id() as u32).into()
    }
}
