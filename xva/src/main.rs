mod cli;
mod compiler;
mod constants;
mod machine;
mod repl;
mod runtime;
mod syntax;
mod typecheck;
use cli::cli;

fn main() {
    cli();
}
