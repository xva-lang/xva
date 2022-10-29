pub struct Compiler {
    _output: Vec<u8>,
}

impl Compiler {
    pub fn new() -> Self {
        Self { _output: vec![] }
    }
    pub fn compile(&self, _root_node: xvasyntax::parser::SyntaxNode) {}
}
