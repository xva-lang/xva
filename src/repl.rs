use std::io::Write;

use crate::{
    compiler::Compiler,
    parser_peg::{ast, parse_repl},
};

pub struct Repl {}

#[allow(dead_code)]
impl Repl {
    pub fn new() -> Self {
        Repl {}
    }

    pub fn run(&self) {
        Self::print_header();
        let mut module_node = ast::Node {
            variant: ast::NodeVariant::Module {
                name: String::from(".repl"),
            },
            children: vec![],
        };

        let mut _module = ast::Module {
            name: String::from(".repl"),
        };

        let mut compiler = Compiler::new();

        //<type name at 0xaddress>

        loop {
            let input = self.prompt();
            match input.as_str() {
                "exit()" => self.exit(0),
                _ => {
                    let statement = parse_repl(self, input, &mut module_node);
                    match statement {
                        Some(v) => {
                            compiler.walk_statement(v.clone(), v.children);
                        }
                        None => {}
                    }
                }
            }
        }
    }

    fn print_header() {
        println!("Xva {}\n", env!("CARGO_PKG_VERSION"));
    }

    fn prompt(&self) -> String {
        let mut line = String::new();
        print!("> ");
        std::io::stdout().flush().unwrap();
        std::io::stdin()
            .read_line(&mut line)
            .expect("Error: Could not read a line");

        return line.trim().to_string();
    }

    fn exit(&self, exit_code: i32) {
        std::process::exit(exit_code);
    }
}
