use parser::Parser;

use crate::parser::error::ParserResult;

pub(crate) mod macros;
mod parser;

pub fn new_parser_from_str(input: &str) -> ParserResult<Parser> {
    Parser::new_from_str(input)
}
#[cfg(test)]
mod tests {
    use std::error::Error;
    use xva_treesitter::utils::print_node;

    use crate::parser::Parser;

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
