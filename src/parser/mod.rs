use pest::{iterators::Pair, Parser};

#[derive(Parser)]
#[grammar = "xva.pest"]
pub struct XvaParser;

pub mod ast;
#[allow(dead_code)]
pub fn parse_file() {
    let unparsed_file = std::fs::read_to_string("/Users/dylan/Projects/xva/tests/test.xva")
        .expect("Failed to read the file");

    let file = XvaParser::parse(Rule::Module, &unparsed_file)
        .expect("Parser error")
        .next()
        .unwrap();

    let rules = file.into_inner();
    let mut module = ast::Node {
        node_type: ast::NodeType::Module,
        raw: String::from("<module>"),
    };

    for rule in rules {
        match rule.as_rule() {
            Rule::Module => println!("Module"),
            Rule::Statement => parse_statement(&mut module, rule),
            Rule::Declaration => println!("dec"),

            _ => println!("unhandled rule {}", rule.as_str()),
        }
    }
}

#[allow(dead_code)]
fn create_node(rule: &Pair<Rule>, node_type: ast::NodeType, _parent_node: &ast::Node) -> ast::Node {
    ast::Node {
        node_type: node_type,
        raw: String::from(rule.as_str()),
    }
}

#[allow(dead_code)]
fn parse_statement(parent_node: &ast::Node, statement: Pair<Rule>) {
    let base_node = create_node(&statement, ast::NodeType::Statement, parent_node);

    let mut statement_node = ast::Statement {
        parent_node: parent_node,
        base_node: base_node,
    };

    println!("Parsing statement: {}", &&statement_node.base_node.raw);

    for rule in statement.into_inner() {
        match rule.as_rule() {
            //Statement = {(Declaration | Assignment | FunctionCall | BreakKeyword) ~ Semicolon}
            Rule::Declaration => parse_declaration(&mut statement_node.base_node, rule),
            Rule::Assignment => println!("Assignment in Statement"),
            Rule::FunctionCall => println!("Function call in Statement"),
            Rule::BreakKeyword => println!("Break keyword in Statement"),
            Rule::Semicolon => println!("Semicolon in Statement"),
            _ => println!("Unhandled rule in Statement"),
        }
    }
}

fn parse_declaration(_parent_node: &mut ast::Node, declaration: Pair<Rule>) {
    println!("Parsing declaration: {}", declaration.as_str());
    for rule in declaration.into_inner() {
        match rule.as_rule() {
            //Declaration = {LetKeyword ~ Identifier ~ TypeAnnotation? ~ AssignmentOperator ~ Expression}
            Rule::Identifier => {
                println!("Declaration with ident {}", rule.as_str());
            }
            Rule::TypeAnnotation => println!("TypeAnnotation in Declaration"),
            Rule::AssignmentOperator => {}
            Rule::Expression => {}
            _ => {}
        }
    }
}
