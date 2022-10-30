use std::{
    env::{args, consts::OS},
    fs,
    io::{self, Write},
    time::SystemTime,
};

use chrono::offset::Local;

use chrono::DateTime;

use crate::{compiler, machine::vm::VirtualMachine};

pub(crate) fn repl_main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut stdout = io::stdout();
    let _stderr = io::stderr();

    let mut compiler = compiler::Compiler::new();
    let mut vm = VirtualMachine::new();

    let meta = fs::metadata(args().nth(0).unwrap())?;
    let build_date: DateTime<Local> = match meta.modified() {
        Ok(m) => m,
        Err(_) => SystemTime::now(),
    }
    .into();

    println!(
        "Xva {}\n[nightly: {}]\n[rustc 1.64.0 (a55dd71d5 2022-09-19) on {}]",
        env!("CARGO_PKG_VERSION").replace("\"", ""),
        build_date.format("%A, %B %d %Y %I:%M:%S%P"),
        OS
    );

    loop {
        write!(stdout, "> ")?;
        stdout.flush()?;

        let mut input = String::new();
        stdin.read_line(&mut input)?;

        let parse_tree = xvasyntax::parser::parse(input.as_str());
        let mut root = xvasyntax::ast::node::Root::cast(parse_tree.get_root_node()).unwrap();

        compiler.compile(&mut root);
        vm.program = compiler.get_output();

        compiler.clear_output();
        vm.run();
        vm.reset_program_counter();
        println!("{}", vm.pop_i64().unwrap());
        input.clear();
        stdout.flush()?;
    }
}
