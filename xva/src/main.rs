use clap::Parser;
use std::io::BufRead;

mod opts;

use opts::{Options, UnstableOptionKind};

const BUILD_INFO: &str = include_str!("../.buildinfo");

fn main() -> Result<(), std::io::Error> {
    println!("{BUILD_INFO}");

    let opts = Options::parse();
    run_repl(&opts);

    Ok(())
}

fn run_repl(opts: &Options) {
    let stdin = std::io::stdin();
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
        let line = stdin.lock().lines().next().unwrap().unwrap();

        let items = xva_parse::Parser::new_from_str(line.as_str())
            .unwrap()
            .items()
            .unwrap();

        if pretty_ast {
            println!("{items:#?}")
        }
    }
}
