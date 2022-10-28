use std::mem;

use crate::{
    language::{SyntaxKind, XvaLanguage},
    lexer::Lexeme,
};

use super::event::Event;
use rowan::{GreenNode, GreenNodeBuilder, Language};

pub(super) struct ParserEventSink<'lexemes, 'input> {
    builder: GreenNodeBuilder<'static>,
    lexemes: &'lexemes [Lexeme<'input>],
    cursor: usize,
    events: Vec<Event>,
}

impl<'lexemes, 'input> ParserEventSink<'lexemes, 'input> {
    pub(super) fn new(lexemes: &'lexemes [Lexeme<'input>], events: Vec<Event>) -> Self {
        Self {
            builder: GreenNodeBuilder::new(),
            lexemes: lexemes,
            cursor: 0,
            events: events,
        }
    }

    pub(super) fn finish(mut self) -> GreenNode {
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

                    // if let Some(offset) = parent_offset {
                    //     if let Event::StartNode { node_kind, .. } =
                    //         mem::replace(&mut self.events[index + offset], Event::MarkerPlaceholder)
                    //     {
                    //         self.builder.start_node(XvaLanguage::kind_to_raw(node_kind));
                    //     } else {
                    //         unreachable!()
                    //     }
                    // }

                    // self.builder.start_node(XvaLanguage::kind_to_raw(node_kind));
                }
                Event::StartNodeAt { .. } => unreachable!(),
                Event::AddToken { token_kind, text } => self.token(token_kind, text),
                Event::FinishNode => self.builder.finish_node(),
                Event::MarkerPlaceholder => {}
            }

            self.consume_trivia();
        }

        self.builder.finish()
    }

    fn token(&mut self, token_kind: SyntaxKind, text: smol_str::SmolStr) {
        self.builder
            .token(XvaLanguage::kind_to_raw(token_kind), text.as_str());
        self.cursor += 1;
    }

    fn consume_trivia(&mut self) {
        while let Some(lexeme) = self.lexemes.get(self.cursor) {
            if !lexeme.kind.is_trivia() {
                break;
            }

            self.token(lexeme.kind, lexeme.text.into());
        }
    }
}
