mod cli;
mod compiler;
mod constants;
mod machine;
mod repl;
mod runtime;

use cli::cli;

fn main() {
    cli();
}
