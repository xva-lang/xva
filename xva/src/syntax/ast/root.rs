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
        for (index, expression) in self.expressions.iter().enumerate() {
            sb.push_str(format!("{}", expression).as_str());
            if index > 0 {
                sb.push('\n')
            }
        }

        write!(f, "{}", sb)
    }
}
