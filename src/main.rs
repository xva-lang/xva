mod cli;
mod compiler;
mod constants;
mod error_resolver;
mod machine;
mod repl;
mod runtime;
mod syntax;
mod typecheck;

use cli::cli;

fn main() {
    cli();
}
