pub enum NodeType {
    Module,
    Declaration,
    Statement,
}
pub struct Node {
    pub node_type: NodeType,
    pub raw: String,
}

pub struct Declaration<'a> {
    node: &'a Node,
    identifier: str,
}

pub struct Statement<'a> {
    pub base_node: Node,
    pub parent_node: &'a Node,
}
