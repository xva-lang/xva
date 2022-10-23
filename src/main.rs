use clap::command;
use clap::Parser;

extern crate pest;
#[macro_use]
extern crate pest_derive;

mod constants;
mod machine;
use machine::istream;
use machine::vm;
mod compiler;
mod runtime;
// use machine::stack;
mod parser;

mod repl;

fn main() {
    cli();
}

#[derive(Parser, Debug)]
#[command(version)]
#[command(name = "Xva")]
struct Args {
    input_file: Option<String>,

    /// Indicates the input file is a pre-compiled binary
    #[arg(short, long)]
    precompiled: bool,
}

fn cli() {
    let args = Args::parse();

    if args.input_file != None {
        if args.precompiled {
            execute_precompiled(args.input_file.unwrap());
        } else {
            compile_and_execute(args.input_file.unwrap());
        }
    } else {
        let repl = repl::Repl::new();
        repl.run();
    }
}

fn execute_precompiled(file_name: String) {
    let mut machine =
        vm::VirtualMachine::new(istream::IStream::from_file(&file_name.as_str()).unwrap());
    machine.run();
}

fn compile_and_execute(file_name: String) {
    let mut compiler = compiler::Compiler::new();
    compiler.compile_file(file_name);
}
