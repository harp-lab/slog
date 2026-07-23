//! Client-side Slog source drafts.
//!
//! This module records editing intent only. A draft is not "compiled" merely
//! because Rust can store it: acceptance and diagnostics must eventually come
//! from a compiler/session response carrying the submitted revision.

use std::collections::BTreeMap;

#[derive(Clone, Copy, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub struct DraftId(u64);

impl DraftId {
    pub fn get(self) -> u64 {
        self.0
    }
}

#[derive(Clone, Copy, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub struct DraftRevision(u64);

impl DraftRevision {
    pub fn get(self) -> u64 {
        self.0
    }
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum DiagnosticSeverity {
    Error,
    Warning,
    Note,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct DraftDiagnostic {
    pub severity: DiagnosticSeverity,
    pub message: String,
    pub line: Option<u32>,
    pub column: Option<u32>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum DraftCheck {
    Unchecked,
    Pending(DraftRevision),
    Accepted(DraftRevision),
    Rejected {
        revision: DraftRevision,
        diagnostics: Vec<DraftDiagnostic>,
    },
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct Draft {
    id: DraftId,
    name: String,
    text: String,
    revision: DraftRevision,
    check: DraftCheck,
}

impl Draft {
    pub fn id(&self) -> DraftId {
        self.id
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn text(&self) -> &str {
        &self.text
    }

    pub fn revision(&self) -> DraftRevision {
        self.revision
    }

    pub fn check(&self) -> &DraftCheck {
        &self.check
    }

    pub fn has_unchecked_changes(&self) -> bool {
        matches!(self.check, DraftCheck::Unchecked)
    }
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum WorkspaceError {
    UnknownDraft(DraftId),
    CheckNotPending(DraftId),
    StaleCheck {
        draft: DraftId,
        expected: DraftRevision,
        received: DraftRevision,
    },
}

#[derive(Debug, Default)]
pub struct Workspace {
    next_id: u64,
    drafts: BTreeMap<DraftId, Draft>,
    active: Option<DraftId>,
}

impl Workspace {
    pub fn create(&mut self, name: impl Into<String>, text: impl Into<String>) -> DraftId {
        let id = DraftId(self.next_id);
        self.next_id = self.next_id.wrapping_add(1);
        let text = text.into();
        let revision = DraftRevision(u64::from(!text.is_empty()));
        self.drafts.insert(
            id,
            Draft {
                id,
                name: name.into(),
                text,
                revision,
                check: DraftCheck::Unchecked,
            },
        );
        self.active = Some(id);
        id
    }

    pub fn active(&self) -> Option<&Draft> {
        self.active.and_then(|id| self.drafts.get(&id))
    }

    pub fn get(&self, id: DraftId) -> Option<&Draft> {
        self.drafts.get(&id)
    }

    pub fn select(&mut self, id: DraftId) -> Result<(), WorkspaceError> {
        if !self.drafts.contains_key(&id) {
            return Err(WorkspaceError::UnknownDraft(id));
        }
        self.active = Some(id);
        Ok(())
    }

    pub fn update(
        &mut self,
        id: DraftId,
        text: impl Into<String>,
    ) -> Result<DraftRevision, WorkspaceError> {
        let draft = self
            .drafts
            .get_mut(&id)
            .ok_or(WorkspaceError::UnknownDraft(id))?;
        let text = text.into();
        if draft.text != text {
            draft.text = text;
            draft.revision = DraftRevision(draft.revision.0.wrapping_add(1));
            draft.check = DraftCheck::Unchecked;
        }
        Ok(draft.revision)
    }

    /// Marks the exact revision sent to the future compiler/session endpoint.
    pub fn mark_pending(&mut self, id: DraftId) -> Result<DraftRevision, WorkspaceError> {
        let draft = self
            .drafts
            .get_mut(&id)
            .ok_or(WorkspaceError::UnknownDraft(id))?;
        draft.check = DraftCheck::Pending(draft.revision);
        Ok(draft.revision)
    }

    pub fn accept(&mut self, id: DraftId, revision: DraftRevision) -> Result<(), WorkspaceError> {
        let draft = self.pending_revision(id, revision)?;
        draft.check = DraftCheck::Accepted(revision);
        Ok(())
    }

    pub fn reject(
        &mut self,
        id: DraftId,
        revision: DraftRevision,
        diagnostics: Vec<DraftDiagnostic>,
    ) -> Result<(), WorkspaceError> {
        let draft = self.pending_revision(id, revision)?;
        draft.check = DraftCheck::Rejected {
            revision,
            diagnostics,
        };
        Ok(())
    }

    fn pending_revision(
        &mut self,
        id: DraftId,
        revision: DraftRevision,
    ) -> Result<&mut Draft, WorkspaceError> {
        let draft = self
            .drafts
            .get_mut(&id)
            .ok_or(WorkspaceError::UnknownDraft(id))?;
        if draft.revision != revision {
            return Err(WorkspaceError::StaleCheck {
                draft: id,
                expected: draft.revision,
                received: revision,
            });
        }
        match draft.check {
            DraftCheck::Pending(expected) if expected == revision => Ok(draft),
            DraftCheck::Pending(expected) => Err(WorkspaceError::StaleCheck {
                draft: id,
                expected,
                received: revision,
            }),
            _ => Err(WorkspaceError::CheckNotPending(id)),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::{DiagnosticSeverity, DraftCheck, DraftDiagnostic, Workspace, WorkspaceError};

    #[test]
    fn revisions_make_the_edit_submit_accept_lifecycle_explicit() {
        let mut workspace = Workspace::default();
        let id = workspace.create("scratch", "rule (edge X Y)");
        assert_eq!(workspace.active().map(|draft| draft.id()), Some(id));
        assert_eq!(workspace.get(id).expect("draft").revision().get(), 1);
        assert!(workspace.get(id).expect("draft").has_unchecked_changes());

        let submitted = workspace.mark_pending(id).expect("submit");
        assert_eq!(
            workspace.get(id).expect("draft").check(),
            &DraftCheck::Pending(submitted)
        );
        workspace.accept(id, submitted).expect("accept");
        assert_eq!(
            workspace.get(id).expect("draft").check(),
            &DraftCheck::Accepted(submitted)
        );

        workspace.update(id, "rule (edge X _)").expect("edit");
        let submitted = workspace.mark_pending(id).expect("submit");
        let diagnostics = vec![
            DraftDiagnostic {
                severity: DiagnosticSeverity::Warning,
                message: "anonymous output".to_owned(),
                line: Some(1),
                column: Some(14),
            },
            DraftDiagnostic {
                severity: DiagnosticSeverity::Note,
                message: "the backend owns final source semantics".to_owned(),
                line: None,
                column: None,
            },
        ];
        workspace
            .reject(id, submitted, diagnostics.clone())
            .expect("reject");
        assert_eq!(
            workspace.get(id).expect("draft").check(),
            &DraftCheck::Rejected {
                revision: submitted,
                diagnostics,
            }
        );
    }

    #[test]
    fn a_late_compiler_reply_cannot_replace_a_newer_edit() {
        let mut workspace = Workspace::default();
        let id = workspace.create("scratch", "rule v1");
        let submitted = workspace.mark_pending(id).expect("submit");
        let current = workspace.update(id, "rule v2").expect("edit");
        let error = workspace
            .reject(
                id,
                submitted,
                vec![DraftDiagnostic {
                    severity: DiagnosticSeverity::Error,
                    message: "old diagnostic".to_owned(),
                    line: Some(1),
                    column: None,
                }],
            )
            .expect_err("stale response");
        assert_eq!(
            error,
            WorkspaceError::StaleCheck {
                draft: id,
                expected: current,
                received: submitted,
            }
        );
        assert_eq!(workspace.get(id).expect("draft").text(), "rule v2");
        assert_eq!(
            workspace.get(id).expect("draft").check(),
            &DraftCheck::Unchecked
        );
    }

    #[test]
    fn drafts_have_stable_ids_even_when_names_repeat() {
        let mut workspace = Workspace::default();
        let first = workspace.create("query", "");
        let second = workspace.create("query", "");
        assert_ne!(first, second);
        assert_eq!(first.get(), 0);
        assert_eq!(second.get(), 1);
        workspace.select(first).expect("select first");
        assert_eq!(workspace.active().map(|draft| draft.name()), Some("query"));
        assert_eq!(workspace.get(first).expect("draft").text(), "");
        assert_eq!(workspace.get(first).expect("draft").revision().get(), 0);
        assert_eq!(workspace.get(second).expect("draft").revision().get(), 0);
    }
}
