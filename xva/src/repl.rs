use std::io::{self, Write};
use xvasyntax::ast::node::*;

use crate::compiler;

pub(crate) fn repl_main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut stdout = io::stdout();
    let _stderr = io::stderr();

    let mut input = String::new();
    let compiler = compiler::Compiler::new();

    let mut debug_tree = false;

    loop {
        write!(stdout, "> ")?;
        stdout.flush()?;

        stdin.read_line(&mut input)?;

        let parse_tree = xvasyntax::parser::parse(input.as_str());
        let mut root = xvasyntax::ast::node::Root::cast(parse_tree.get_root_node()).unwrap();

        dbg!(root
            .statements()
            .map(|s| {
                match s {
                    Statement::Expression(e) => println!("{:#?}", e),
                }
            })
            .collect::<Vec<_>>());

        let root = parse_tree.get_root_node();

        match input.as_str().trim() {
            "debug_tree!()" => {
                debug_tree = !debug_tree;
                input.clear();
                continue;
            }
            _ => {}
        }

        compiler.compile(root);
        input.clear();
        stdout.flush()?;
    }
}
