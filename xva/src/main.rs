mod cli;
mod compiler;
mod constants;
mod machine;
mod repl;
mod runtime;
mod typecheck;

use cli::cli;

fn main() {
    cli();
}
