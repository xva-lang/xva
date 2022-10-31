use crate::{compiler, machine::vm::VirtualMachine};
use built::util::strptime;
use std::io::{self, Write};
use xvasyntax::ast::root::Root;

pub mod built_info {
    // The file has been placed there by the build script.
    include!(concat!(env!("OUT_DIR"), "/built.rs"));
}

pub(crate) fn repl_main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut stdout = io::stdout();
    let _stderr = io::stderr();

    let mut compiler = compiler::Compiler::new();
    let mut vm = VirtualMachine::new();

    let built_time = strptime(built_info::BUILT_TIME_UTC);
    println!(
        "Xva {}\n[{}: {}]\n[{} on {}]",
        built_info::PKG_VERSION,
        built_info::GIT_HEAD_REF.unwrap().replace("refs/heads/", ""),
        built_time
            .with_timezone(&built::chrono::offset::Local)
            .format("%A, %B %d %Y %I:%M:%S%P"),
        built_info::RUSTC_VERSION,
        built_info::TARGET,
    );

    loop {
        write!(stdout, "> ")?;
        stdout.flush()?;

        let mut input = String::new();
        stdin.read_line(&mut input)?;

        let parse_tree = xvasyntax::parser::parse(input.as_str());
        let parse_errors = parse_tree.get_errors();
        if parse_errors.len() > 0 {
            for error in parse_errors {
                println!("{}\n", error)
            }

            continue;
        }

        let mut root: Root = Root::cast(parse_tree.get_root_node()).unwrap();

        compiler.compile(&mut root);
        vm.program = compiler.get_output_as_slice().to_vec();

        compiler.clear_output();
        vm.run();
        vm.reset_program_counter();
        println!("{}", vm.pop_i64().unwrap());
        input.clear();
        stdout.flush()?;
    }
}
