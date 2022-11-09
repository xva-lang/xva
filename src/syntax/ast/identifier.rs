#[derive(Debug)]
pub(crate) struct IdentifierExpression {
    name: String,
}

impl IdentifierExpression {
    pub fn new(name: String) -> Self {
        Self { name }
    }

    pub fn get_name(&self) -> &str {
        &self.name
    }
}

impl std::fmt::Display for IdentifierExpression {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Identifier({})", self.name)
    }
}
