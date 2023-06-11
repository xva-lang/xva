use std::{fs::File, io::Read};

use clap::{Arg, Command};
use xvabuildinfo::get_build_info;
use xvacompiler::CompilerOptions;

const PACKAGE_VERSION: &str = std::env!("CARGO_PKG_VERSION");

// const UNSTABLE_COMPILER_OPTIONS: [&str; 1] = [cli::compiler_options::UNSTABLE_PRINT_CST];

const ARG_UNSTABLE_COMPILER_OPTION: &str = "unstable_compiler_option";
const ARG_INPUT_FILE: &str = "input_file";
fn main() -> Result<(), std::io::Error> {
    println!("Xva {} {}", PACKAGE_VERSION, get_build_info());

    let command = Command::new("Xva")
        .author("Xva Language Team <info@xva-lang.org>")
        .arg(
            Arg::new(ARG_INPUT_FILE)
                .required(false)
                .help("Run the specified Xva source file"),
        )
        .arg(
            Arg::new(ARG_UNSTABLE_COMPILER_OPTION)
                .short('Z')
                .help("Specify unstable compiler options"),
        );

    let matches = command.get_matches();

    let input_file = matches.get_one::<String>(ARG_INPUT_FILE);

    let mut compiler_options = CompilerOptions::default();

    if let Some(zflags) = matches.get_many::<String>(ARG_UNSTABLE_COMPILER_OPTION) {
        for flag in zflags {
            if flag == "print-cst" {
                compiler_options.print_cst = true
            }
        }
    }

    if let Some(file_name) = input_file {
        let mut buffer = String::new();
        File::open(file_name)?.read_to_string(&mut buffer)?;

        if compiler_options.print_cst {
            xvasyntax::print_cst(buffer);
        }
    }

    Ok(())
}
