use super::Parser;
use crate::{language::SyntaxKind, parser::event::Event};
use drop_bomb::DropBomb;

pub(super) struct Marker {
    position: usize,
    drop_check: DropBomb,
}

impl Marker {
    pub(super) fn new(position: usize) -> Self {
        Self {
            position,
            drop_check: DropBomb::new("Incomplete markers cannot be dropped!"),
        }
    }

    pub(super) fn complete(
        mut self,
        parser: &mut Parser,
        node_kind: SyntaxKind,
    ) -> CompletedMarker {
        self.drop_check.defuse();

        let event_at_position = &mut parser.events[self.position];
        assert_eq!(
            *event_at_position,
            Event::MarkerPlaceholder,
            "Event is not an Event::MarkerPlaceholder"
        );

        *event_at_position = Event::StartNode {
            node_kind,
            parent_offset: None,
        };

        parser.events.push(Event::FinishNode);

        CompletedMarker {
            position: self.position,
        }
    }
}

pub(super) struct CompletedMarker {
    position: usize,
}

impl CompletedMarker {
    pub(super) fn precede(self, parser: &mut Parser) -> Marker {
        let new_marker = parser.start();

        if let Event::StartNode {
            ref mut parent_offset,
            ..
        } = parser.events[self.position]
        {
            *parent_offset = Some(new_marker.position - self.position);
        } else {
            unreachable!();
        }

        new_marker
    }
}
