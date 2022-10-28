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
        let mut reordered_events = self.events.clone();
        for (index, event) in self.events.iter().enumerate() {
            if let Event::StartNodeAt {
                node_kind,
                checkpoint,
            } = event
            {
                reordered_events.remove(index);
                reordered_events.insert(
                    *checkpoint,
                    Event::StartNode {
                        node_kind: *node_kind,
                    },
                )
            }
        }

        for event in reordered_events {
            match event {
                Event::StartNode { node_kind } => {
                    self.builder.start_node(XvaLanguage::kind_to_raw(node_kind));
                }
                Event::StartNodeAt { .. } => unreachable!("StartNodeAt should have been replaced!"),
                Event::AddToken { token_kind, text } => self.token(token_kind, text),
                Event::FinishNode => self.builder.finish_node(),
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
