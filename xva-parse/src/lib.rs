use std::{
    io::{self, Read, Seek},
    path::PathBuf,
};

use parser::Parser;

mod parser;
mod session;

#[cfg(test)]
mod tests {

    use super::Parser;
    use std::error::Error;
    use xva_treesitter::utils::print_node;

    fn check(input: &str) -> String {
        let mut result = String::new();
        let parser = Parser::new_from_str(input).unwrap();

        let mut depth = 0;
        print_node(
            input,
            parser.tree(),
            parser.tree().root_node(),
            &mut depth,
            &mut result,
            None,
        );
        result
    }

    #[test]
    fn test() -> Result<(), Box<dyn Error>> {
        println!("{}", check("true"));
        Ok(())
    }
}
