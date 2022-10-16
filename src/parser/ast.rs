#[allow(dead_code)]
pub enum NodeVariant {
    Module {
        name: String,
    },
    Declaration {
        identifier: String,
        type_annotation: Option<String>,
        assignment: Option<String>,
    },
    Statement,
}

pub struct Node {
    pub variant: NodeVariant,
    pub children: Vec<Node>,
}

pub struct Tree {
    pub nodes: Vec<Node>,
}
