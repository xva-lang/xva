use parser::Parse;

mod language;
mod lexer;

#[allow(dead_code)]
pub mod parser;

pub fn parse(input: &str) -> Parse {
    let parse = parser::Parser::new(input).parse();
    println!("{}", parse.debug_tree());
    parse
}
