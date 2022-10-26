use std::io::{self, Write};

pub(crate) fn repl_main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut stdout = io::stdout();
    let _stderr = io::stderr();

    let mut input = String::new();

    loop {
        write!(stdout, "> ")?;
        stdout.flush()?;

        stdin.read_line(&mut input)?;

        let _parse = syntax::parse(input.as_str());

        input.clear();
        stdout.flush()?;
    }
}
