use colored::Colorize;
use pest::{error::Error, iterators::Pair, Parser, RuleType};

use self::ast::Tree;

pub struct CompilerError {
    message: String,
    line_number: usize,
    column: usize,
    line: String,
    file: String,
}

#[derive(Parser)]
#[grammar = "xva.pest"]
pub struct XvaParser {
    tree: ast::Tree,
    errors: Vec<CompilerError>,
    current_file: String,
}

impl XvaParser {
    pub fn parse_module(&mut self, rule: Pair<Rule>) {
        let mut nodes: Vec<ast::Node> = vec![];

        for rule in rule.into_inner() {
            match rule.as_rule() {
                Rule::Statement => self.parse_statement(rule, &mut nodes),
                _ => {}
            }
        }

        let node = ast::Node {
            variant: ast::NodeVariant::Module {
                name: ".main".to_string(),
            },
            children: nodes,
        };
        self.tree.nodes.push(node);
    }

    pub fn parse_declaration(&mut self, rule: Pair<Rule>, parent_node_vec: &mut Vec<ast::Node>) {
        let mut identifier: Option<String> = None;
        let mut type_annotation: Option<String> = None; // TODO: type inference
                                                        // let mut declaration_node =   ast::Node::Declaration { identifier: None, type_annotation: None, assignment: None };
        let mut _type_annotation_rule: Pair<Rule>;
        let whole_line = Box::new(String::from(rule.as_str()));
        let cloned_rule = rule.clone();
        for sub_rule in rule.into_inner() {
            match sub_rule.as_rule() {
                Rule::Identifier => identifier = Some(String::from(sub_rule.as_str())),
                Rule::TypeAnnotation => {
                    type_annotation = Some(String::from(sub_rule.as_str()));
                    _type_annotation_rule = sub_rule;
                    println!("");
                }
                Rule::Expression => self.parse_expression(sub_rule),

                // Ignore these
                Rule::LetKeyword => {}
                Rule::AssignmentOperator => {}
                _ => panic!("unhandled rule while parsing declaration: {}", sub_rule),
            }
        }

        if type_annotation == None {
            for sub_rule in cloned_rule.into_inner() {
                if sub_rule.as_rule() == Rule::AssignmentOperator {
                    self.raise_error(
                        sub_rule,
                        "Type inference is unimplemented".to_string(),
                        Some(whole_line),
                    );
                    break;
                }
            }
        }

        let node = ast::Node {
            variant: ast::NodeVariant::Declaration {
                identifier: identifier.unwrap(),
                type_annotation: type_annotation,
                assignment: None,
            },
            children: vec![],
        };

        parent_node_vec.push(node);
    }

    pub fn parse_expression(&self, rule: Pair<Rule>) {
        println!("{}", rule.as_str());
    }

    pub fn parse_statement(&mut self, rule: Pair<Rule>, parent_node_vec: &mut Vec<ast::Node>) {
        println!("Parsing statement");
        let mut nodes: Vec<ast::Node> = vec![];
        for rule in rule.into_inner() {
            match rule.as_rule() {
                Rule::Declaration => self.parse_declaration(rule, &mut nodes),
                _ => {}
            }
        }

        parent_node_vec.push(ast::Node {
            variant: ast::NodeVariant::Statement,
            children: nodes,
        })
    }

    pub fn raise_error(
        &mut self,
        rule: Pair<Rule>,
        message: String,
        whole_line: Option<Box<String>>,
    ) {
        let (line, col) = rule.as_span().start_pos().line_col();
        self.errors.push(CompilerError {
            message,
            line_number: line,
            column: col,
            line: if whole_line == None {
                String::from(rule.as_str())
            } else {
                String::from(whole_line.unwrap().as_str())
            },
            file: String::from(self.current_file.as_str()),
        });
    }
}

pub mod ast;
#[allow(dead_code)]
pub fn parse_file(file_name: String) {
    let mut parser = XvaParser {
        tree: Tree { nodes: vec![] },
        errors: vec![],
        current_file: String::from(&file_name),
    };

    let unparsed_file = std::fs::read_to_string(&file_name).expect("Failed to read the file");

    let file = match XvaParser::parse(Rule::Module, &unparsed_file) {
        Ok(val) => val,
        Err(err) => {
            print_parser_error(err.with_path(&file_name.as_str()));

            std::process::exit(-1);
        }
    };

    let rules = file;

    for rule in rules {
        match rule.as_rule() {
            Rule::Module => parser.parse_module(rule),

            _ => println!("unhandled rule {}", rule.as_str()),
        }
    }

    if parser.errors.len() > 0 {
        for error in parser.errors {
            print_compiler_error(error);
        }
    }
}

fn print_parser_error<R>(error: Error<R>)
where
    R: RuleType,
{
    let end_position: usize;
    let (line_number, position_str) = match error.line_col {
        pest::error::LineColLocation::Pos(pos) => {
            end_position = pos.1;
            (pos.0, format!("{}", pos.1))
        }
        pest::error::LineColLocation::Span(first, second) => {
            end_position = second.1;
            (first.0, format!("{}:{}", second.0, second.1))
        }
    };

    let warning = format!("{}", "error").red();
    let file_path = match error.path() {
        Some(path) => format!("--> {}\n", path),
        None => String::from("\n"),
    };

    let message = format!(
        "{} (at line {}, position {})",
        error.variant.message(),
        line_number,
        position_str
    );

    let line_marker = format!(
        "\n |\n{}| {}\n | {}",
        line_number,
        error.line(),
        format!(
            "{}^ {}",
            " ".repeat(end_position),
            error.variant.message().red()
        )
    );

    println!("{warning}: {message}\n{file_path}{line_marker}");
}

fn print_compiler_error(error: CompilerError) {
    let warning = format!("{}", "error").red();
    let file_path = format!("\n--> {}\n", error.file);

    let position_message = format!(
        "(at line {}, position {}).",
        error.line_number, error.column
    );
    let message = format!("{} {}{file_path}", error.message, position_message);
    let spacer = " ".repeat(error.column);

    let line_marker = format!(
        " |\n{}| {}\n | {}",
        error.line_number,
        error.line,
        format!("{spacer}^ {}", error.message.red())
    );

    println!("{warning}: {message}{line_marker}");
}
