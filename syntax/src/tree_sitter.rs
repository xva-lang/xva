use tree_sitter::{Node, Parser, Tree};
use tree_sitter_traversal::{traverse_tree, Order};
use tree_sitter_xva::language;

#[allow(dead_code)]
pub(crate) fn get_tree(input: impl AsRef<[u8]>, existing_tree: Option<&Tree>) -> Tree {
    let mut parser = Parser::new();
    parser.set_language(language()).unwrap();
    parser.parse(input, existing_tree).unwrap()
}

#[allow(dead_code)]
pub(crate) fn debug_tree(tree: &Tree) {
    let nodes = traverse_tree(tree, Order::Post).collect::<Vec<_>>();
    println!("{:#?}", nodes);
}

pub fn print_cst(input: impl AsRef<[u8]>) {
    let cloned_input = input.as_ref().clone();
    let mut parser = Parser::new();
    parser.set_language(language()).unwrap();
    let tree = parser.parse(cloned_input, None).unwrap();
    let root = tree.root_node();
    let mut depth = 0usize;
    print_node(&cloned_input, &tree, root, &mut depth);
}

const NODE_KIND_SOURCE_FILE: &str = "source_file";

fn print_node<'a>(source: &impl AsRef<[u8]>, tree: &Tree, node: Node, depth: &'a mut usize) {
    let mut cursor = tree.walk();
    println!(
        "{} {} @ {},{} - {},{} {}",
        "  ".repeat(depth.clone()),
        node.kind(),
        node.start_position().row,
        node.start_position().column,
        node.end_position().row,
        node.end_position().column,
        if node.kind() != NODE_KIND_SOURCE_FILE {
            match node.utf8_text(source.as_ref()) {
                Ok(v) => format!("\"{v}\""),
                Err(_) => "".into(),
            }
        } else {
            "".into()
        }
    );

    if node.child_count() > 0 {
        for child in node.children(&mut cursor) {
            *depth += 1;
            print_node(source, &tree, child, depth);
            if child.next_sibling().is_none() && depth.clone() > 0 {
                *depth -= 1;
            }
        }
    } else {
        if depth.clone() > 0 {
            *depth -= 1;
        };
    }
}
