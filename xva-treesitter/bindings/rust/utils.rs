use tree_sitter::{Node, Parser, Tree};

pub(crate) fn get_parser() -> Parser {
    let mut parser = tree_sitter::Parser::new();
    parser
        .set_language(super::language())
        .expect("Error loading Xva language");
    parser
}

pub fn get_tree(input: &str) -> Tree {
    let mut parser = get_parser();
    parser.parse(input, None).expect("Failed to parse")
}

pub fn node_text_as_bytes<'src>(source: &'src [u8], n: &'src Node<'src>) -> &'src [u8] {
    &source.as_ref()[n.byte_range()]
}

/// Formats a node and all its children and places the result in a buffer, according to the following format:
///
/// ```text
/// parent_kind @start_row:start_col..end_row:end_col "node_text"
///   [field_name?] child1_kind @start_row:start_col..end_row:end_col "node_text"
///   ..
///   child1_kind @start_row:start_col..end_row:end_col "node_text"
/// ```
///
/// The `end_row` and `end_col` values are **zero-based** and **exclusive**.
///
/// For nodes that are hidden rules, if their kind is equal to their text, only
/// the kind is displayed.
pub fn print_node<'a>(
    source: impl AsRef<[u8]>,
    tree: &Tree,
    node: Node,
    depth: &'a mut usize,
    result: &mut String,
    field_name: Option<&str>,
) {
    let mut cursor = tree.walk();
    let (field_name, space, node_kind, start_row, start_col, end_row, end_col, text) = (
        field_name.map_or("".into(), |x| format!("\"{x}\" ")),
        "  ".repeat(depth.clone()),
        node.kind(),
        node.start_position().row,
        node.start_position().column,
        node.end_position().row,
        node.end_position().column,
        if node.kind().as_bytes() == node_text_as_bytes(source.as_ref(), &node) {
            "".into()
        } else {
            format!(" \"{}\"", node.utf8_text(source.as_ref()).unwrap())
        },
    );

    result.push_str(&format!(
        r#"{space}{field_name}{node_kind} @{start_row}:{start_col}..{end_row}:{end_col}{text}"#
    ));

    if node.child_count() > 0 {
        result.push_str("\n");
        *depth += 1;
        for (i, child) in node.children(&mut cursor).into_iter().enumerate() {
            let child_field_name = node.field_name_for_child(i as u32);
            print_node(
                source.as_ref(),
                &tree,
                child,
                depth,
                result,
                child_field_name,
            );

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

/// Checks that the result of parsing `input` with TreeSitter matches the `expected_tree`. The `expected_tree`
/// is a tree structure written in the same format of the result of [`print_node`], wrapped
/// in an [`expect!`] macro invocation.
///
/// # Examples:
///
/// ```
/// use xva_treesitter::utils::test_tree;
/// use expect_test::expect;
/// test_tree(
///     "1 + 1", expect![[r#"
/// root @0:0..0:5 "1 + 1"
///   expression @0:0..0:5 "1 + 1"
///     binary_expression @0:0..0:5 "1 + 1"
///       "left" expression @0:0..0:1 "1"
///         literal @0:0..0:1 "1"
///           integer_literal @0:0..0:1 "1"
///             decimal_literal @0:0..0:1 "1"
///       "operator" + @0:2..0:3
///       "right" expression @0:4..0:5 "1"
///         literal @0:4..0:5 "1"
///           integer_literal @0:4..0:5 "1"
///             decimal_literal @0:4..0:5 "1""#]],
///)
/// ```
pub fn test_tree(input: &str, expected_tree: expect_test::Expect) {
    let mut result = String::new();
    let tree = get_tree(input);
    let mut depth = 0;
    print_node(
        input,
        &tree,
        tree.root_node(),
        &mut depth,
        &mut result,
        None,
    );

    expected_tree.assert_eq(&result);
}

#[cfg(test)]
mod tests {
    use super::print_node;
    use crate::utils::get_tree;

    #[test]
    fn test_print_node() {
        let input = r#"1+1"#;
        let mut result = String::new();
        let tree = get_tree(input);
        let mut depth = 0;
        print_node(
            input,
            &tree,
            tree.root_node(),
            &mut depth,
            &mut result,
            None,
        );

        println!("{result}")
    }
}
