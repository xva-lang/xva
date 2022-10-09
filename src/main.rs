extern crate pest;
#[macro_use]
extern crate pest_derive;

mod constants;
mod machine;
// use machine::stack;
mod parser;

mod repl;

fn main() {
    parser::parse_file();
}
