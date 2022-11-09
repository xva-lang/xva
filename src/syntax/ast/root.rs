use super::expression::Expression;

#[derive(Debug)]
pub(crate) struct Root {
    pub(crate) expressions: Vec<Expression>,
}

impl Root {
    pub(crate) fn new(expressions: Vec<Expression>) -> Self {
        Self { expressions }
    }
}

impl std::fmt::Display for Root {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut sb = String::new();
        for expression in self.expressions.iter() {
            sb.push_str(format!("{}\n", expression).as_str())
        }

        write!(f, "{}", sb)
    }
}
