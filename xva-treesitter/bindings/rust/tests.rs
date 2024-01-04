mod expressions;
mod literals;

#[test]
fn test_can_load_grammar() {
    let mut parser = tree_sitter::Parser::new();
    parser
        .set_language(super::language())
        .expect("Error loading xva language");
}
