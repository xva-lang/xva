use std::ops::Range;

use crate::language::SyntaxKind;
use smol_str::SmolStr;

#[derive(Debug, Clone, PartialEq)]
pub(super) enum Event {
    StartNode {
        node_kind: SyntaxKind,
        parent_offset: Option<usize>,
    },
    StartNodeAt {
        node_kind: SyntaxKind,
        checkpoint: usize,
    },
    AddToken {
        token_kind: SyntaxKind,
        text: SmolStr,
        span: Range<usize>,
    },
    FinishNode,
    MarkerPlaceholder,
}
