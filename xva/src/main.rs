use clap::arg;
use clap::command;
use clap::Parser;

mod constants;
mod machine;
use machine::istream;
use machine::vm;
mod repl;
mod runtime;

fn main() {
    cli();
}

#[derive(Parser)]
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
        match repl::repl_main() {
            Ok(_) => {}
            Err(_) => {}
        }
    }
}

fn execute_precompiled(file_name: String) {
    let mut machine =
        vm::VirtualMachine::new(istream::IStream::from_file(&file_name.as_str()).unwrap());
    machine.run();
}

fn compile_and_execute(_file_name: String) {}
