mod cli;
mod compiler;
mod constants;
mod error_resolver;
mod machine;
mod repl;
mod runtime;
mod syntax;
mod typecheck;
mod utils;
use cli::cli;

fn main() {
    cli();
}
