#[cfg(test)]
mod tests {
    use tree_sitter::Parser;
    use tree_sitter_xva::language;

    #[test]
    fn test() {
        let lang = language();
        let mut parser = Parser::new();
        parser.set_language(lang).unwrap();
        let tree = parser
            .parse(
                r#"def some_function() {

}"#,
                None,
            )
            .unwrap();
        println!("{:#?}", tree.root_node().to_sexp());
    }
}
