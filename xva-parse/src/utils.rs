use internment::Intern;

/// Helper stub to return an interned `String` from a `&str`
pub(crate) fn intern_str(value: &str) -> Intern<String> {
    Intern::new(value.into())
}
