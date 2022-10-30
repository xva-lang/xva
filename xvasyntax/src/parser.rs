mod event;
mod expression;
mod line_index;
mod marker;
pub mod operator;
mod sink;
mod statement;
use std::ops::Range;

use crate::{
    language::SyntaxKind,
    language::XvaLanguage,
    lexer::{Lexeme, LexemeSource, Lexer},
};
use rowan::GreenNode;

use event::Event;
use expression::expression;
use marker::Marker;
use smol_str::SmolStr;

use self::line_index::LineIndexes;

const RECOVERY_SET: [SyntaxKind; 1] = [SyntaxKind::LetKeyword];

#[derive(Debug)]
struct Parser<'lexemes, 'input> {
    // Lifetime 'a is needed because Logos’ lexers store the input they were created with,
    //and pull from it as tokens are requested.
    source: LexemeSource<'lexemes, 'input>,
    events: Vec<Event>,
    errors: Vec<(String, Lexeme<'lexemes>)>,
}

impl<'lexemes, 'input> Parser<'lexemes, 'input> {
    pub(crate) fn new(lexemes: &'lexemes [Lexeme<'input>]) -> Self {
        Self {
            source: LexemeSource::new(lexemes),
            events: Vec::new(),
            errors: Vec::new(),
        }
    }

    pub(crate) fn parse(mut self) -> Vec<Event> {
        let marker = self.start();
        while !self.at_end() {
            match expression(&mut self) {
                Some(_) => {}
                None => break,
            }
        }

        marker.complete(&mut self, SyntaxKind::Root);

        self.events
    }

    fn start(&mut self) -> Marker {
        let position = self.events.len();
        self.events.push(Event::MarkerPlaceholder);

        Marker::new(position)
    }

    /// Starts a new node on the current branch of the parse tree.
    /// # Arguments
    /// * `kind` - A `SyntaxKind` describing the new node to start.
    fn start_node(&mut self, node_kind: SyntaxKind) {
        // self.builder.start_node(XvaLanguage::kind_to_raw(kind))
        self.events.push(Event::StartNode {
            node_kind,
            parent_offset: None,
        })
    }

    /// Completes the parse tree
    fn finish_node(&mut self) {
        self.events.push(Event::FinishNode);
    }

    /// Peeks at the next token without consuming it.
    /// # Returns
    /// `Some(SyntaxKind)` if there was a token available, else `None`.
    fn peek(&mut self) -> Option<SyntaxKind> {
        self.source.peek_kind()
    }

    fn peek_lexeme(&mut self) -> Option<Lexeme> {
        self.source.peek_current_as_deref()
    }

    /// Consumes the next token and appends it to the current branch of the parse tree
    /// # Panics
    /// If there are no available tokens the thread will panic. This is intentional as it represents
    /// an error with the construction of the syntax tree.
    fn bump(&mut self) {
        let lexeme = self.source.next_lexeme().unwrap();
        self.events.push(Event::AddToken {
            token_kind: lexeme.kind,
            text: lexeme.text.into(),
            span: Range::<usize> {
                start: lexeme.span.start,
                end: lexeme.span.end,
            },
        })
    }

    fn bump_this(&mut self, lexeme: Lexeme) {
        self.events.push(Event::AddToken {
            token_kind: lexeme.kind,
            text: lexeme.text.into(),
            span: lexeme.span,
        })
    }

    fn bump_with_error(&mut self, error: &str, suggestion: Option<&str>) {
        let lexeme = self.source.next_lexeme().unwrap();
        self.error_on_existing_lexeme(error, lexeme, suggestion);
        self.events.push(Event::AddToken {
            token_kind: lexeme.kind,
            text: lexeme.text.into(),
            span: Range::<usize> {
                start: lexeme.span.start,
                end: lexeme.span.end,
            },
        });
    }

    /// Consumes the next token, but does not add it to the parse tree.
    /// Use this for advancing the parser without adding unnecessary tokens to the tree such as in the case of
    /// parenthesised expressions.
    /// # Panics
    /// If there are no available tokens the thread will panic. This is intentional as it represents
    /// an error with the construction of the syntax tree.
    fn consume(&mut self) {
        self.source.consume();
    }

    /// Branches off the current Rowan node and begins adding nodes to this "child" branch.
    fn start_node_at(&mut self, checkpoint: usize, node_kind: SyntaxKind) {
        // self.builder
        //     .start_node_at(checkpoint, XvaLanguage::kind_to_raw(node_kind));
        self.events.push(Event::StartNodeAt {
            node_kind,
            checkpoint: checkpoint,
        })
    }

    fn at_end(&mut self) -> bool {
        self.peek().is_none()
    }

    fn at(&mut self, kind: SyntaxKind) -> bool {
        self.peek().is_some() && self.peek() == Some(kind)
    }

    fn at_one_of(&mut self, set: &[SyntaxKind]) -> bool {
        self.peek().is_some() && self.peek().map_or(false, |kind| set.contains(&kind))
    }

    fn error(&mut self, error: &str, suggestion: Option<&str>) {
        self.error_on_existing_marker(error, suggestion);
    }

    fn error_on_existing_marker(&mut self, error: &str, suggestion: Option<&str>) {
        if !self.at_one_of(&RECOVERY_SET) {
            if !self.at_end() {
                let lexeme = self.source.next_lexeme().unwrap();
                self.events.push(Event::Error {
                    text: lexeme.text.into(),
                    span: Range::<usize> {
                        start: lexeme.span.start,
                        end: lexeme.span.end,
                    },
                    error: SmolStr::from(error),
                    suggestion: match suggestion {
                        Some(s) => Some(SmolStr::from(s)),
                        None => None,
                    },
                });
            } else {
                let lexeme = self.source.peek_previous_as_deref().unwrap();
                self.events.push(Event::Error {
                    text: lexeme.text.into(),
                    span: Range::<usize> {
                        start: lexeme.span.start + 1,
                        end: lexeme.span.end + 1,
                    },
                    error: SmolStr::from(error),
                    suggestion: match suggestion {
                        Some(s) => Some(SmolStr::from(s)),
                        None => None,
                    },
                })
            }
        }
    }

    fn error_on_existing_lexeme(&mut self, error: &str, lexeme: &Lexeme, suggestion: Option<&str>) {
        self.events.push(Event::Error {
            text: lexeme.text.into(),
            span: Range::<usize> {
                start: lexeme.span.start,
                end: lexeme.span.end,
            },
            error: SmolStr::from(error),
            suggestion: match suggestion {
                Some(s) => Some(SmolStr::from(s)),
                None => None,
            },
        });
    }

    fn expect_kind(&mut self, kind: SyntaxKind) {
        if self.at(kind)
            || !self
                .peek()
                .map_or(false, |kind| RECOVERY_SET.contains(&kind))
        {
            self.bump();
        }
    }

    fn expect_kind_or_error(&mut self, kind: SyntaxKind, error: &str, suggestion: Option<&str>) {
        if self.at(kind) {
            self.bump()
        } else {
            self.error(error, suggestion);
        }
    }
}

/// The end result of the parser.
pub struct ConcreteSyntaxTree {
    green_node: GreenNode,
    line_indexes: LineIndexes,
    errors: Vec<String>,
}

impl ConcreteSyntaxTree {
    pub fn debug_tree(&self) -> String {
        let syntax_node = SyntaxNode::new_root(self.green_node.clone());
        let formatted = format!("{:#?}", syntax_node);

        // Cut off the last byte because formatting the SyntaxNode adds on a newline at the end.
        formatted[0..formatted.len() - 1].to_string()
    }

    pub fn get_root_node(&self) -> rowan::SyntaxNode<XvaLanguage> {
        SyntaxNode::new_root(self.green_node.clone())
    }
}

pub type SyntaxNode = rowan::SyntaxNode<XvaLanguage>;
pub type SyntaxToken = rowan::SyntaxToken<XvaLanguage>;

pub fn parse(input: &str) -> ConcreteSyntaxTree {
    let lexemes: Vec<Lexeme> = Lexer::new(input).collect();
    let parser = Parser::new(&lexemes);
    let events = parser.parse();
    let sink = sink::ParserEventSink::new(&lexemes, events);
    let (green_node, line_indexes, errors) = sink.finish();
    ConcreteSyntaxTree {
        green_node: green_node,
        line_indexes: line_indexes,
        errors,
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use expect_test::{expect, Expect};

    pub fn check_parse(input: &str, expected_tree: Expect) {
        let parse = parse(input);

        // Rust iterators are lazy - the .any() at the end forces Rust to evaluate the .map()
        parse.errors.iter().map(|x| println!("{}", x)).any(|_| true);
        expected_tree.assert_eq(&parse.debug_tree());
    }

    #[test]
    fn parse_nothing() {
        check_parse("", expect![[r"Root@0..0"]]);
    }

    #[test]
    fn parse_whitespace() {
        check_parse(
            "   ",
            expect![[r#"
Root@0..3
  Whitespace@0..3 "   ""#]],
        );
    }

    #[test]
    fn preceding_whitespace() {
        check_parse(
            "   1234",
            expect![[r#"
Root@0..7
  Whitespace@0..3 "   "
  Literal@3..7
    IntegerLiteral@3..7 "1234""#]],
        )
    }

    #[test]
    fn succeeding_whitespace() {
        check_parse(
            "1234   ",
            expect![[r#"
Root@0..7
  Literal@0..7
    IntegerLiteral@0..4 "1234"
    Whitespace@4..7 "   ""#]],
        )
    }

    #[test]
    fn surrounding_whitespace() {
        check_parse(
            "   1234   ",
            expect![[r#"
Root@0..10
  Whitespace@0..3 "   "
  Literal@3..10
    IntegerLiteral@3..7 "1234"
    Whitespace@7..10 "   ""#]],
        )
    }

    #[test]
    fn parse_comment() {
        check_parse(
            "// comment",
            expect![[r#"
Root@0..10
  Comment@0..10 "// comment""#]],
        );
    }

    #[test]
    fn get_line_range_by_absolute_range() {
        let mut parse = parse("1 + 1\n2+ 2");
        assert_eq!(
            parse
                .line_indexes
                .get_line(Range::<usize> { start: 4, end: 6 }),
            Some(1..2)
        )
    }

    #[test]
    fn parse_declaration() {
        check_parse(
            "let value = 1",
            expect![[r#"
Root@0..13
  Declaration@0..13
    LetKeyword@0..3 "let"
    Whitespace@3..4 " "
    Identifier@4..9 "value"
    Whitespace@9..10 " "
    Equals@10..11 "="
    Whitespace@11..12 " "
    Literal@12..13
      IntegerLiteral@12..13 "1""#]],
        )
    }

    #[test]
    fn error_expected_closing_parenthesis() {
        let tree = parse("1 + ((1 + 1) + 3");

        expect![[r#"
    error: Expected a closing parenthesis (at line 1, position 17):

          |
        1 | 1 + ((1 + 1) + 3
          |                 ^ Consider adding a closing parenthesis here."#]]
        .assert_eq(tree.errors.first().unwrap())
    }

    #[test]
    fn error_empty_parenthesised_expression() {
        let tree = parse("1 + ()");
        expect![[r#"
error: Expected an expression (at line 1, position 6):

      |
    1 | 1 + ()
      |      ^"#]]
        .assert_eq(tree.errors.first().unwrap());
    }
}
