// use std::rc::Rc;

// use crate::machine;

use crate::parser_peg::{
    ast::{Declaration, Tree},
    ast::{Module, Node, NodeVariant},
};
use queues::{Buffer, IsQueue};

pub struct Compiler {
    stream: Buffer<u8>,
}

#[allow(dead_code)]
impl Compiler {
    pub fn new() -> Self {
        Self {
            stream: Buffer::new(1024),
        }
    }

    pub fn compile_file(&mut self, _file_name: String) {
        // let output_file_name = file_name.replace(".xva", ".xvo");

        // let mut tree = parser_peg::parse_file(file_name);
        // self.walk_tree(&mut tree);
        // let unparsed_file = std::fs::read_to_string(&file_name).expect("Failed to read the file");
        // let mut lexer = Lexer::new(&unparsed_file.as_str());
    }

    pub fn walk_tree(&mut self, tree: &mut Tree) {
        for i in 0..tree.nodes.len() {
            // let (owned_node, _) = tree.nodes.split_at(i + 1);
            match &tree.nodes[i].variant {
                NodeVariant::Module { name } => {
                    let module = Module {
                        name: String::from(name.as_str()),
                    };

                    let cloned_node = tree.nodes[i].clone();
                    self.walk_module(module, cloned_node.children);
                }
                _ => {}
            }
        }
    }

    pub fn walk_module(&mut self, module: Module, nodes: Vec<Node>) {
        println!("compiling {}", module.name);
        for node in nodes {
            let cloned_node = (&node).clone();
            match node.variant {
                NodeVariant::Statement => {
                    let _reowned_node = self.walk_statement(node, cloned_node.children);
                }
                _ => {}
            }
        }
    }
    // pub fn walk_module(&mut self, module: Module, children: &[Node], module_name: &String) {
    //     println!("Compiling module {}", module_name);
    //     for node in children {
    //         match &node.variant {
    //             NodeVariant::Statement => self.walk_statement(node),
    //             _ => {}
    //         }
    //     }
    // }

    pub fn walk_statement(&mut self, statement: Node, children: Vec<Node>) -> Node {
        for node in children {
            // let cloned_node = (&node).clone();
            match node.variant {
                NodeVariant::Declaration {
                    identifier,
                    type_annotation,
                    assignment,
                    is_mutable: _is_mutable,
                } => {
                    let dec = Declaration {
                        identifier: identifier,
                        type_annotation: type_annotation,
                        assignment: assignment,
                    };
                    self.compile_declaration(dec);
                }
                _ => {}
            }
        }

        return statement;
    }

    pub fn compile_declaration(&mut self, _declaration: Declaration) {}

    pub fn add_stream(&mut self, _val: u8) {
        match self.stream.add(0) {
            Ok(_) => {}
            Err(err) => println!("failed to add instruction to stream: {}", err),
        };
    }
}
