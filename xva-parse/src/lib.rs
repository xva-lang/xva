pub(crate) mod macros;
// pub mod parserx;
pub mod parser;
pub(crate) mod traits;

pub(crate) mod lexer;

// pub use parserx::Parser;

#[cfg(test)]
mod tests {
    use std::error::Error;
    use xva_treesitter::utils::print_node;

    // use crate::parserx::Parser;

    // fn check(input: &str) -> String {
    //     let mut result = String::new();
    //     let parser = Parser::new_from_str(input).unwrap();

    //     let mut depth = 0;
    //     print_node(
    //         input,
    //         parser.tree(),
    //         parser.tree().root_node(),
    //         &mut depth,
    //         &mut result,
    //         None,
    //     );
    //     result
    // }

    // #[test]
    // fn test() -> Result<(), Box<dyn Error>> {
    //     println!("{}", check("true"));
    //     Ok(())
    // }

    #[test]
    fn test() -> Result<(), Box<dyn Error>> {
        // println!("{:#?}", )
        Ok(())
    }
}
