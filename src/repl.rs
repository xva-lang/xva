use crate::{
    compiler,
    machine::vm::VirtualMachine,
    syntax::{
        ast::ast_type::ASTType,
        lexer::{self, language::TokenKind, token_stream::TokenStream},
        parser::Parser,
    },
    typecheck,
};
// use built::util::strptime;
use chrono::DateTime;
use logos::Logos;
use std::io::{self, Write};

pub mod built_info {
    // The file has been placed there by the build script.
    include!(concat!(env!("OUT_DIR"), "/built.rs"));
}

pub(crate) fn repl_main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut stdout = io::stdout();
    let _stderr = io::stderr();

    let mut vm = VirtualMachine::new();

    let built_time = DateTime::parse_from_rfc2822(built_info::BUILT_TIME_UTC)
        .unwrap()
        .with_timezone(&chrono::Local);

    println!(
        "Xva {}\n[{}: {}]\n[{} on {}]\n",
        built_info::PKG_VERSION,
        built_info::GIT_HEAD_REF.unwrap().replace("refs/heads/", ""),
        built_time.format("%A, %B %d %Y %I:%M:%S%P"),
        built_info::RUSTC_VERSION,
        built_info::TARGET,
    );

    loop {
        write!(stdout, "> ")?;
        stdout.flush()?;

        let mut input = String::new();
        stdin.read_line(&mut input)?;

        let lines = lexer::utils::input_lines_as_vec(input.as_str());
        let mut lexer = TokenKind::lexer(input.as_str());
        let token_stream = TokenStream::new(&mut lexer);
        let mut parser = Parser::new(token_stream, lines.clone());
        let mut parse_result = parser.parse();
        if parser.get_errors().len() > 0 {
            println!("");
            for error in parser.get_errors() {
                println!("{error}")
            }

            println!("");
            continue;
        }

        let mut compiler = compiler::Compiler::new(lines.clone());
        compiler.compile(&mut parse_result);

        if compiler.errors.len() > 0 {
            for error in compiler.errors {
                println!("{}\n", error);
            }

            continue;
        }

        vm.program = compiler.get_output_as_slice().to_vec();

        compiler.clear_output();
        vm.run();
        vm.reset_program_counter();

        match parse_result.expressions.first() {
            Some(e) => match e.get_type() {
                ASTType::Integer => println!("{}", vm.pop_i64().unwrap_or(0)),
                ASTType::Boolean => match vm.pop_i64().unwrap() {
                    0 => println!("false"),
                    1 => println!("true"),
                    _ => panic!("bad boolean"),
                },
                ASTType::Float => println!("{}", vm.pop_f64().unwrap()),
                _ => println!("{}", typecheck::TypeChecker::repr_type(e.get_type())),
            },
            None => println!("{}", typecheck::TypeChecker::repr_type(&ASTType::Void)),
        }
        
        input.clear();
        stdout.flush()?;
    }
}
