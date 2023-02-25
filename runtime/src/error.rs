#[derive(Debug)]
pub struct RuntimeError {
    inner: String,
}

impl RuntimeError {
    pub fn new(inner: &str) -> Self {
        Self {
            inner: inner.into(),
        }
    }
}

impl std::fmt::Display for RuntimeError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", &self.inner)
    }
}
