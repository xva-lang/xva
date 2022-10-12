#[allow(dead_code)]
pub enum NodeType {
    Module,
    Declaration,
    Statement,
}
#[allow(dead_code)]
pub struct Node {
    pub node_type: NodeType,
    pub raw: String,
}

#[allow(dead_code)]
pub struct Declaration<'a> {
    node: &'a Node,
    identifier: str,
}

#[allow(dead_code)]
pub struct Statement<'a> {
    pub base_node: Node,
    pub parent_node: &'a Node,
}
