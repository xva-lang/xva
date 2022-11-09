use crate::syntax::location::SyntaxLocation;

use super::expression::Expression;

#[derive(Debug)]
pub(crate) struct Declaration {
    name: String,
    assignment: Option<Box<Expression>>,
    identifier_location: SyntaxLocation,
    mutable: bool,
}

impl Declaration {
    pub fn new(
        name: String,
        identifier_location: SyntaxLocation,
        assignment: Option<Box<Expression>>,
        mutable: bool,
    ) -> Self {
        Self {
            name,
            identifier_location,
            assignment,
            mutable,
        }
    }

    pub fn get_assignment(&self) -> Option<&Expression> {
        match &self.assignment {
            Some(x) => Some(x.as_ref()),
            None => None,
        }
    }

    pub fn get_name(&self) -> &str {
        &self.name
    }

    pub fn get_identifier_location(&self) -> SyntaxLocation {
        self.identifier_location
    }

    pub fn is_mutable(&self) -> bool {
        self.mutable
    }
}

impl std::fmt::Display for Declaration {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let formatted_expression = match &self.assignment {
            Some(x) => format!("{}", x),
            None => String::from("None"),
        };

        if self.is_mutable() {
            write!(
                f,
                "Declaration({}, mutable, {})",
                self.name, formatted_expression
            )
        } else {
            write!(f, "Declaration({}, {})", self.name, formatted_expression)
        }
    }
}
