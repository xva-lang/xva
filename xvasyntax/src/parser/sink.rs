use std::{mem, ops::Range};

use crate::{
    language::{SyntaxKind, XvaLanguage},
    lexer::Lexeme,
};

use super::{
    event::Event,
    line_index::{LineIndex, LineIndexes},
};
use logos::Span;
use rowan::{GreenNode, GreenNodeBuilder, Language};
use smol_str::SmolStr;

pub(super) struct ParseError {
    text: SmolStr,
    error: SmolStr,
    span: Range<usize>,
    suggestion: Option<SmolStr>,
}

pub(super) struct ParserEventSink<'lexemes, 'input> {
    builder: GreenNodeBuilder<'static>,
    lexemes: &'lexemes [Lexeme<'input>],
    cursor: usize,
    events: Vec<Event>,
    current_span: Span,
    current_line: usize,
    line_indexes: LineIndexes,
    errors: Vec<ParseError>,
}

impl<'lexemes, 'input> ParserEventSink<'lexemes, 'input> {
    pub(super) fn new(lexemes: &'lexemes [Lexeme<'input>], events: Vec<Event>) -> Self {
        Self {
            builder: GreenNodeBuilder::new(),
            lexemes: lexemes,
            cursor: 0,
            events: events,
            current_span: 0..0,
            current_line: 1,
            line_indexes: LineIndexes::new(),
            errors: vec![],
        }
    }

    pub(super) fn finish(mut self) -> (GreenNode, LineIndexes, Vec<String>) {
        let mut str_errors: Vec<String> = vec![];

        for index in 0..self.events.len() {
            match mem::replace(&mut self.events[index], Event::MarkerPlaceholder) {
                Event::StartNode {
                    node_kind,
                    parent_offset,
                } => {
                    let mut kinds = vec![node_kind];

                    let mut index = index;
                    let mut parent_offset = parent_offset;

                    // Walk through the forward parent of the forward parent, and the forward parent
                    // of that, and of that, etc. until we reach a StartNode event without a forward
                    // parent.
                    while let Some(offset) = parent_offset {
                        index += offset;

                        parent_offset = if let Event::StartNode {
                            node_kind,
                            parent_offset,
                        } =
                            mem::replace(&mut self.events[index], Event::MarkerPlaceholder)
                        {
                            kinds.push(node_kind);
                            parent_offset
                        } else {
                            unreachable!()
                        };
                    }

                    for kind in kinds.into_iter().rev() {
                        self.builder.start_node(XvaLanguage::kind_to_raw(kind));
                    }
                }
                Event::StartNodeAt { .. } => unreachable!(),
                Event::AddToken {
                    token_kind,
                    text,
                    span,
                } => self.token(token_kind, text, span),
                Event::FinishNode => self.builder.finish_node(),
                Event::MarkerPlaceholder => {}
                Event::Error {
                    text,
                    span,
                    error,
                    suggestion,
                } => self.errors.push(ParseError {
                    text,
                    error,
                    span,
                    suggestion,
                }),
            }

            self.consume_trivia();
        }

        for error in self.errors {
            let position = error.span.clone();
            let line_number = self.line_indexes.get_line(error.span.clone());

            let mut constructed_line = String::new();
            for index in self
                .line_indexes
                .matched_lines_as_vec(line_number.clone().unwrap().start)
            {
                for lexeme in self.lexemes {
                    if lexeme.span.start == index.range.start && lexeme.span.end == index.range.end
                    {
                        constructed_line.push_str(lexeme.text);
                    }
                }
            }

            let suggestion = match error.suggestion {
                Some(s) => {
                    let mut val = String::new();
                    val.push_str(" ");
                    val.push_str(s.as_str());
                    val
                }
                None => String::from(""),
            };
            let error_cursor_position = position.end;
            let error_line = format!(
                "      |\n    1 | {}\n      |{}^{}",
                constructed_line.as_str(),
                " ".repeat(error_cursor_position),
                suggestion
            );

            str_errors.push(format!(
                "error: {} (at line {}, position {}):\n\n{}",
                error.error,
                self.line_indexes.get_line(error.span).unwrap().start,
                position.end,
                error_line,
            ));
        }

        (self.builder.finish(), self.line_indexes, str_errors)
    }

    fn token(&mut self, token_kind: SyntaxKind, text: smol_str::SmolStr, span: Range<usize>) {
        if token_kind == SyntaxKind::Whitespace {
            for (_, character) in text.as_str().char_indices() {
                match character {
                    '\n' => self.current_line += 1,
                    _ => {}
                }
            }
        }

        self.line_indexes
            .push(LineIndex::new(span, self.current_line));
        self.builder
            .token(XvaLanguage::kind_to_raw(token_kind), text.as_str());
        self.cursor += 1;
    }

    fn consume_trivia(&mut self) {
        while let Some(lexeme) = self.lexemes.get(self.cursor) {
            let cloned_lexeme = lexeme.clone();
            if !lexeme.kind.is_trivia() {
                break;
            }

            self.token(
                lexeme.kind,
                lexeme.text.into(),
                Range::<usize> {
                    start: cloned_lexeme.span.start,
                    end: cloned_lexeme.span.end,
                },
            );
        }
    }
}
