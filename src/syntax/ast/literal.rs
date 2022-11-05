#[derive(Debug)]
pub(crate) enum LiteralVariant {
    Boolean(bool),
    Integer(i64),
}

impl std::fmt::Display for LiteralVariant {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut str_value = String::new();

        match self {
            LiteralVariant::Boolean(b) => {
                if *b {
                    str_value.push_str("Boolean(true)")
                } else {
                    str_value.push_str("Boolean(false)")
                }
            }
            LiteralVariant::Integer(i) => {
                str_value.push_str(format!("Integer({})", i).as_str());
            }
        }

        write!(f, "{}", str_value)
    }
}
