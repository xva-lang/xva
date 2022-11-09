use super::expression::Expression;

#[derive(Debug)]
pub(crate) struct Declaration {
    name: String,
    assignment: Option<Box<Expression>>,
}

impl Declaration {
    pub fn new(name: String, assignment: Option<Box<Expression>>) -> Self {
        Self { name, assignment }
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
}

impl std::fmt::Display for Declaration {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let formatted_expression = match &self.assignment {
            Some(x) => format!("{}", x),
            None => String::from("None"),
        };

        write!(f, "Declaration({}, {})", self.name, formatted_expression)
    }
}
