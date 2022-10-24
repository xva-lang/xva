use super::{Lexer, TokenKind};

#[test]
fn positive_integer_no_sign() {
    match Lexer::integer("123") {
        Ok((_, token_kind)) => match token_kind {
            TokenKind::Integer(v) => {
                assert_eq!(v, 123, "Test: literal {} is equal to integer {}", v, 123);
            }
            _ => panic!("Incorrect token result: {:?}", token_kind),
        },
        Err(e) => {
            panic!("{}", e)
        }
    }
}

#[test]
fn positive_integer() {
    let input = "+246";
    let test_case = 246;
    match Lexer::integer(input) {
        Ok((_, token_kind)) => match token_kind {
            TokenKind::Integer(v) => {
                assert_eq!(
                    v, test_case,
                    "Test: literal {} is equal to integer {}",
                    input, test_case
                );
            }
            _ => panic!("Incorrect token result: {:?}", token_kind),
        },
        Err(e) => {
            panic!("{}", e)
        }
    }
}

#[test]
fn negative_integer() {
    let input = "-369";
    let test_case = -369;
    match Lexer::integer(input) {
        Ok((_, token_kind)) => match token_kind {
            TokenKind::Integer(v) => {
                assert_eq!(
                    v, test_case,
                    "Test: literal {} is equal to integer {}",
                    input, test_case
                );
            }
            _ => panic!("Incorrect token result: {:?}", token_kind),
        },
        Err(e) => {
            panic!("{}", e)
        }
    }
}

#[test]
fn hex_integer() {
    let input = "0x20";
    let test_case = 32;
    match Lexer::integer(input) {
        Ok((_, token_kind)) => match token_kind {
            TokenKind::Integer(v) => {
                assert_eq!(
                    v, test_case,
                    "Test: literal {} is equal to integer {}",
                    input, test_case
                );
            }
            _ => panic!("Incorrect token result: {:?}", token_kind),
        },
        Err(e) => {
            panic!("{}", e)
        }
    }
}

#[test]
fn binary_integer() {
    let input = "0b1100";
    let test_case = 12;
    match Lexer::integer(input) {
        Ok((_, token_kind)) => match token_kind {
            TokenKind::Integer(v) => {
                assert_eq!(
                    v, test_case,
                    "Test: literal {} is equal to integer {}",
                    input, test_case
                );
            }
            _ => panic!("Incorrect token result: {:?}", token_kind),
        },
        Err(e) => {
            panic!("{}", e)
        }
    }
}

#[test]
fn octal_integer() {
    let input = "0o644";
    let test_case = 420;
    match Lexer::integer("0o644") {
        Ok((_, token_kind)) => match token_kind {
            TokenKind::Integer(v) => {
                assert_eq!(
                    v, test_case,
                    "Test: literal {} is equal to integer {}",
                    input, test_case
                );
            }
            _ => panic!("Incorrect token result: {:?}", token_kind),
        },
        Err(e) => {
            panic!("{}", e)
        }
    }
}

#[test]
fn addition_operator() {
    let input = "+  ";
    match Lexer::operator(input) {
        Ok((_, t)) => match t {
            TokenKind::Add => {}
            _ => panic!("Incorrect token result for addition: {:?}", t),
        },
        Err(e) => {
            panic!("{}", e)
        }
    }
}

#[test]
fn subtraction_operator() {
    let input = "  -";
    match Lexer::operator(input) {
        Ok((_, t)) => match t {
            TokenKind::Subtract => {}
            _ => panic!("Incorrect token result for subtraction: {:?}", t),
        },
        Err(e) => {
            panic!("{}", e)
        }
    }
}

#[test]
fn lex() {
    let input = "1 + 3 + 4 - 16 + 5-1";
    let expected = vec![
        TokenKind::Integer(1),
        TokenKind::Add,
        TokenKind::Integer(3),
        TokenKind::Add,
        TokenKind::Integer(4),
        TokenKind::Subtract,
        TokenKind::Integer(16),
        TokenKind::Add,
        TokenKind::Integer(5),
        TokenKind::Integer(-1),
    ];

    let lexer = Lexer::new(input);
    let result = lexer.lex();
    assert_eq!(result, expected);
}
