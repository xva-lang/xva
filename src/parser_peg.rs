use colored::Colorize;
use pest::{error::Error, iterators::Pair, Parser, RuleType};

use crate::parser::lexer::Lexer;
use crate::{repl, runtime::typing::builtins::Type};

use self::ast::{Expression, Tree};

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
                Rule::Statement => {
                    self.parse_statement(rule, &mut nodes);
                }
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
        // let mut type_annotation: Option<String> = None;
        // let mut expression_type: Expression = Expression::Void;
        let mut assignment: Option<Expression> = None;
        let mut type_annotation_rule: Option<Pair<Rule>> = None;
        let mut is_mutable = false;
        let cloned_rule = (&rule).clone();
        for sub_rule in rule.into_inner() {
            match sub_rule.as_rule() {
                Rule::Identifier => identifier = Some(String::from(sub_rule.as_str())),
                Rule::MutableKeyword => is_mutable = true,
                Rule::TypeAnnotation => type_annotation_rule = Some(sub_rule.clone()),
                Rule::Assignment => {
                    for assignment_rule in sub_rule.clone().into_inner() {
                        match assignment_rule.as_rule() {
                            Rule::Expression => {
                                let whole_line = Some(Box::new(String::from(cloned_rule.as_str())));
                                assignment = Some(
                                    self.parse_assignment(assignment_rule.clone(), whole_line),
                                );
                            }
                            _ => {}
                        }
                    }
                }
                _ => {}
            }
        }

        let node = ast::Node {
            variant: ast::NodeVariant::Declaration {
                identifier: identifier.unwrap(),
                type_annotation: match self.parse_type_annotation(type_annotation_rule) {
                    Type::Void => None,
                    x => Some(x),
                },
                assignment: assignment,
                is_mutable: is_mutable,
            },
            children: vec![],
        };

        parent_node_vec.push(node);
    }

    pub fn parse_assignment(
        &mut self,
        rule: Pair<Rule>,
        whole_line: Option<Box<String>>,
    ) -> Expression {
        let mut result: Expression = Expression::Void;
        for rule in rule.into_inner() {
            println!("{}", rule);
            match rule.as_rule() {
                Rule::IntegerConstant => {
                    result = self.parse_integer_constant(rule, whole_line);
                    break;
                }
                _ => {}
            }
        }
        return result;
    }

    pub fn parse_integer_constant(
        &mut self,
        rule: Pair<Rule>,
        whole_line: Option<Box<String>>,
    ) -> Expression {
        let cloned_rule = (&rule).clone();
        let mut result: Expression = Expression::Void;
        for rule in rule.into_inner() {
            match rule.as_rule() {
                Rule::IntegerConstantDecimal => {
                    let i64result: Option<i64> = match i64::from_str_radix(cloned_rule.as_str(), 10)
                    {
                        Ok(v) => Some(v),
                        Err(_) => {
                            self.raise_error(
                                rule,
                                format!("Invalid integer constant: {}", (&cloned_rule.as_str())),
                                whole_line,
                            );
                            None
                        }
                    };

                    if i64result != None {
                        result = Expression::Constant(Type::Integer(i64result.unwrap()));
                    }
                    break;
                }
                _ => {}
            }
        }

        return result;
    }
    // pub fn parse_expression(&self, rule: Pair<Rule>, expression_type: Type) -> Option<Expression> {
    //     let result: Option<Expression> = None;
    //     for rule in rule.into_inner() {
    //         match rule.as_rule() {
    //             Rule::IntegerConstant => {
    //                 result = Some(self.parse_integer_constant(rule, expression_type))
    //             }
    //             _ => result = None,
    //         }
    //     }

    //     result
    // }

    // pub fn parse_integer_constant(&self, rule: Pair<Rule>, expression_type: Type) -> Expression {
    //     let result: Expression;
    //     for rule in rule.into_inner() {
    //         match rule.as_rule() {
    //             Rule::IntegerConstantDecimal => match expression_type {
    //                 Type::SignedInt(si) => {
    //                     let value = rule.as_str();
    //                     println!("break");
    //                 }
    //                 _ => {}
    //             },
    //             _ => todo!(),
    //         }
    //     }

    //     result
    // }

    pub fn parse_statement(
        &mut self,
        rule: Pair<Rule>,
        parent_node_vec: &mut Vec<ast::Node>,
    ) -> ast::Node {
        let mut nodes: Vec<ast::Node> = vec![];
        for rule in rule.into_inner() {
            match rule.as_rule() {
                Rule::Declaration => self.parse_declaration(rule, &mut nodes),
                _ => {}
            }
        }

        let result = ast::Node {
            variant: ast::NodeVariant::Statement,
            children: nodes,
        };

        parent_node_vec.push(result.clone());
        return result;
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

    pub fn parse_type_annotation(&mut self, rule: Option<Pair<Rule>>) -> Type {
        if rule == None {
            return Type::Void;
        }

        let cloned_rule = rule.unwrap().clone();
        let str_rule = (&cloned_rule).as_str();
        let whole_line = Some(Box::new(String::from((&cloned_rule).as_str())));
        match cloned_rule.as_str() {
            "int" => Type::Integer(0),
            _ => {
                self.raise_error(
                    cloned_rule,
                    format!("Unknown type {}", str_rule),
                    whole_line,
                );
                Type::Void
            }
        }
    }
}

pub mod ast;
#[allow(dead_code)]
pub fn parse_file(file_name: String) -> ast::Tree {
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

    return parser.tree;
}

pub fn parse_repl(
    _repl: &repl::Repl,
    input: String,
    _module_node: &mut ast::Node,
) -> Option<ast::Node> {
    let lexer = Lexer::new(input.as_str());
    lexer.lex();
    // let pairs: Option<pest::iterators::Pairs<Rule>> =
    //     match XvaParser::parse(Rule::Statement, &input) {
    //         Ok(val) => Some(val),
    //         Err(err) => {
    //             print_parser_error(err);
    //             None
    //         }
    //     };

    // let mut parser = XvaParser {
    //     tree: Tree { nodes: vec![] },
    //     errors: vec![],
    //     current_file: String::from(".repl"),
    // };

    // let mut statement_result: Option<ast::Node> = None;

    // if pairs != None {
    //     for rule in pairs.unwrap() {
    //         let _count_before = module_node.children.len();
    //         match rule.as_rule() {
    //             Rule::Statement => {
    //                 statement_result =
    //                     Some(parser.parse_statement(rule, &mut module_node.children));
    //                 // println!();
    //                 // if module_node.children.len() > count_before {
    //                 //     statement_result = match module_node.children.last() {
    //                 //         Some(v) => Some(v.to_owned()),
    //                 //         None => None,
    //                 //     }
    //                 //     // statement_result = Some(module_node.children.last());
    //                 // }
    //             }
    //             _ => {}
    //         }
    //     }
    // }

    return None;
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
