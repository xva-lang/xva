pub struct CompilerOptions {
    pub print_cst: bool,
}

impl Default for CompilerOptions {
    fn default() -> Self {
        Self {
            print_cst: Default::default(),
        }
    }
}

#[cfg(test)]
mod tests {}
