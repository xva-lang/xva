use crate::syntax::location::SyntaxLocation;

use super::expression::Expression;

#[derive(Debug)]
pub(crate) struct Assignment {
    target_identifier: String,
    _location: SyntaxLocation,
    expression: Box<Expression>,
}

impl Assignment {
    pub fn new(
        target_identifier: String,
        location: SyntaxLocation,
        expression: Box<Expression>,
    ) -> Self {
        Self {
            target_identifier,
            _location: location,
            expression,
        }
    }

    pub fn get_target_identifier(&self) -> &str {
        &self.target_identifier
    }

    pub fn get_expression(&self) -> &Expression {
        &self.expression
    }
}

impl std::fmt::Display for Assignment {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "Assignment({}, {})",
            self.target_identifier, self.expression
        )
    }
}
