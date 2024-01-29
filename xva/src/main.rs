use std::{
    fs::File,
    io::{BufRead, Read},
};

use clap::{Arg, Args, Parser};
use xva_buildinfo::get_build_info;
use xva_compiler::CompilerOptions;

const PACKAGE_VERSION: &str = std::env!("CARGO_PKG_VERSION");

// const UNSTABLE_COMPILER_OPTIONS: [&str; 1] = [cli::compiler_options::UNSTABLE_PRINT_CST];

const ARG_UNSTABLE_COMPILER_OPTION: &str = "unstable_compiler_option";
const ARG_INPUT_FILE: &str = "input_file";
use std::error::Error;

fn parse_unstable_option<K>(
    s: &str,
) -> Result<(K, UnstableOptionKind), Box<dyn Error + Send + Sync + 'static>>
where
    K: std::str::FromStr,
    K::Err: Error + Send + Sync + 'static,
{
    if s.contains('=') {
        let pos = s
            .find('=')
            .ok_or_else(|| format!("Invalid KEY=value: no `=` found in `{}`", s))?;
        Ok((
            s[..pos].parse()?,
            UnstableOptionKind::WithValue(s[pos + 1..].parse()?),
        ))
    } else {
        Ok((s.parse()?, UnstableOptionKind::NoValue))
    }
}

#[derive(Debug, Clone)]
enum UnstableOptionKind {
    NoValue,
    WithValue(String),
}

#[derive(Parser, Debug)]
struct Options {
    /// Specify unstable compiler options
    #[arg(short = 'Z', value_parser = parse_unstable_option::<String>)]
    unstable_options: Vec<(String, UnstableOptionKind)>,
}

fn main() -> Result<(), std::io::Error> {
    println!("Xva {} {}", PACKAGE_VERSION, get_build_info());

    let opts = Options::parse();
    run_repl(&opts);

    Ok(())
}

fn run_repl(opts: &Options) {
    let stdin = std::io::stdin();
    loop {
        let line = stdin.lock().lines().next().unwrap().unwrap();

        let tree = xva_parse::Parser::new_from_str(line.as_str())
            .unwrap()
            .items();

        if let Some((key, val)) = opts.unstable_options.iter().find(|(k, _)| k == "pretty") {
            if let UnstableOptionKind::WithValue(pretty) = val {
                if pretty == "ast" {
                    println!("{tree:#?}");
                }
            }
        }
    }
}
