use crate::language::SyntaxKind;
use smol_str::SmolStr;

#[derive(Debug, Clone)]
pub(super) enum Event {
    StartNode {
        node_kind: SyntaxKind,
    },
    StartNodeAt {
        node_kind: SyntaxKind,
        checkpoint: usize,
    },
    AddToken {
        token_kind: SyntaxKind,
        text: SmolStr,
    },
    FinishNode,
}
