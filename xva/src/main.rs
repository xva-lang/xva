use clap::Parser;
use std::io::{BufRead, Write};

mod opts;

use opts::{Options, UnstableOptionKind};

const BUILD_INFO: &str = include_str!("../.buildinfo");

fn main() -> Result<(), std::io::Error> {
    println!("{BUILD_INFO}");

    let opts = Options::parse();
    run_repl(&opts)?;

    Ok(())
}

fn run_repl(opts: &Options) -> std::io::Result<()> {
    let stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let pretty_ast =
        if let Some((_, val)) = opts.unstable_options.iter().find(|(k, _)| k == "pretty") {
            if let UnstableOptionKind::WithValue(pretty) = val {
                if pretty == "ast" {
                    true
                } else {
                    false
                }
            } else {
                false
            }
        } else {
            false
        };

    loop {
        let _stdout_lock = stdout.lock();
        stdout.write_all("> ".as_bytes())?;
        stdout.flush()?;

        let line = stdin.lock().lines().next().unwrap()?;

        let items = xva_parse::Parser::new_from_str(line.as_str())
            .unwrap()
            .items()
            .unwrap();

        if pretty_ast {
            println!("{items:#?}")
        }
    }
}
