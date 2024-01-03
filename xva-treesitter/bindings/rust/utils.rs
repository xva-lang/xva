use tree_sitter::{Node, Tree};

/// Formats a node and all its children and places the result in a buffer, according to the following format:
///
/// ```ignore
/// parent_kind @start_row:start_col..end_row:end_col
///   child1_kind @start_row:start_col..end_row:end_col
///   ..
///   child1_kind @start_row:start_col..end_row:end_col "terminal_text"
/// ```
///
/// The `end_row` and `end_col` values are **zero-based** and **exclusive**.
pub fn print_node<'a>(
    source: impl AsRef<[u8]>,
    tree: &Tree,
    node: Node,
    depth: &'a mut usize,
    result: &mut String,
) {
    let mut cursor = tree.walk();
    result.push_str(&format!(
        "{}{} @{}:{}..{}:{}",
        "  ".repeat(depth.clone()),
        node.kind(),
        node.start_position().row,
        node.start_position().column,
        node.end_position().row,
        node.end_position().column,
    ));

    if node.child_count() > 0 {
        result.push_str("\n");
        for child in node.children(&mut cursor) {
            *depth += 1;
            print_node(source.as_ref(), &tree, child, depth, result);
            if child.next_sibling().is_none() && depth.clone() > 0 {
                *depth -= 1;
            }
        }
    } else {
        // If the node has no children, but its start byte does not equal its end byte,
        // it's (probably?) a terminal node with text in it.
        if node.start_byte() != node.end_byte() {
            result.push_str(&format!(
                " \"{}\"",
                node.utf8_text(source.as_ref()).unwrap()
            ))
        }

        if depth.clone() > 0 {
            *depth -= 1;
        };
    }
}
