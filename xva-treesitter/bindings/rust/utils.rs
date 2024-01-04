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
        r#"{}{} @{}:{}..{}:{} "{}""#,
        "  ".repeat(depth.clone()),
        node.kind(),
        node.start_position().row,
        node.start_position().column,
        node.end_position().row,
        node.end_position().column,
        node.utf8_text(source.as_ref()).unwrap()
    ));

    if node.child_count() > 0 {
        result.push_str("\n");
        *depth += 1;
        for child in node.children(&mut cursor) {
            print_node(source.as_ref(), &tree, child, depth, result);

            // Lowkey probably a better way to write these two if statements?
            if child.next_sibling().is_some() {
                result.push_str("\n");
            }

            if child.next_sibling().is_none() && depth.clone() > 0 {
                *depth -= 1;
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::print_node;
    use crate::tests::get_tree;

    #[test]
    fn test_print_node() {
        let input = r#""some string \u1234""#;
        let mut result = String::new();
        let tree = get_tree(input);
        let mut depth = 0;
        print_node(input, &tree, tree.root_node(), &mut depth, &mut result);

        println!("{result}")
    }
}
