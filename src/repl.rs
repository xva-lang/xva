use std::io::Write;

#[allow(dead_code)]
pub fn repl_loop() {
    repl_header();
    loop {
        let input = repl_prompt();
        match input.as_str() {
            "exit();" => exit_repl(0),
            _ => {}
        }
    }
}

fn repl_header() {
    println!("Xva {}\n", env!("CARGO_PKG_VERSION"));
}

fn repl_prompt() -> String {
    let mut line = String::new();
    print!("> ");
    std::io::stdout().flush().unwrap();
    std::io::stdin()
        .read_line(&mut line)
        .expect("Error: Could not read a line");

    return line.trim().to_string();
}

fn exit_repl(exit_code: i32) {
    println!("Repl will exit with exit code {}", exit_code);
    std::process::exit(exit_code);
}
