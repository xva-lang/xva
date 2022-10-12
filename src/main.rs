use machine::stack::stack_create;

extern crate pest;
#[macro_use]
extern crate pest_derive;

mod constants;
mod machine;
// use machine::stack;
mod parser;

mod repl;

fn main() {
    let path = std::env::args().nth(1).expect("No input file specified");
    let mut stream = machine::istream::from_file(path.as_str());

    machine::run_machine(&mut stream, &mut Box::new(stack_create(1024)));
}
