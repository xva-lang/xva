use crate::parser::SyntaxNode;

/// Produces an `i64` from the text of a `SyntaxNode`.
/// # Arguments
/// `syntax_node` - The node from which text is parsed into an `i64`
pub(crate) fn i64_from_node_text(syntax_node: SyntaxNode) -> i64 {
    str::parse(String::from(syntax_node.text()).as_str().trim()).unwrap()
}
