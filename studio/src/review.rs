//! Proposals: what an agent wants to change, held until the author accepts
//! it. Nothing an agent writes reaches the program by fiat.
//!
//! A proposal is an exact-text edit -- replace `old` with `new`, where `old`
//! occurs exactly once in the program -- or an append of new forms. Text
//! anchors need no notion of position: edits elsewhere leave a proposal
//! applicable, and an edit to its own text makes it *stale* (never applied).
//! Pending proposals of different threads whose old text overlaps are in
//! *conflict*; neither can be accepted until the author rejects one.
//!
//! The ported shape is the slides app's review model (threads, changesets,
//! ops); the anchoring is Slog Studio's own.

use serde::{Deserialize, Serialize};
use serde_json::Value;
use std::collections::BTreeMap;

#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
#[serde(tag = "kind", rename_all = "lowercase")]
pub enum Change {
    /// Replace the one occurrence of `old` with `new`.
    Edit { old: String, new: String },
    /// Add `source` at the end of the program.
    Append { source: String },
}

#[derive(Clone, Copy, Debug, Deserialize, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Status {
    Pending,
    Accepted,
    Rejected,
}

#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct Op {
    pub id: u32,
    pub thread: u32,
    pub changeset: u32,
    #[serde(flatten)]
    pub change: Change,
    pub note: String,
    pub status: Status,
}

/// One agent turn's proposals, titled with the request that caused them.
#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct Changeset {
    pub id: u32,
    pub thread: u32,
    pub title: String,
}

/// One entry of a thread's transcript.
#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct Message {
    /// "user", "assistant", "thinking", "tool", "plan", "notice", "error",
    /// or "turn" (a turn's closing line).
    pub role: String,
    pub text: String,
    /// When it was said, in milliseconds since the epoch.
    #[serde(default)]
    pub at: u64,
    /// What the role carries beyond text: a tool call's name, input, status
    /// and result; a plan's items; a thought's duration; a turn's usage.
    #[serde(default, skip_serializing_if = "Value::is_null")]
    pub data: Value,
}

impl Message {
    pub fn new(role: &str, text: &str, data: Value) -> Self {
        Self {
            role: role.to_owned(),
            text: text.to_owned(),
            at: now(),
            data,
        }
    }
}

/// Milliseconds since the epoch.
pub fn now() -> u64 {
    std::time::SystemTime::now()
        .duration_since(std::time::UNIX_EPOCH)
        .map_or(0, |since| since.as_millis() as u64)
}

/// A finding or decision an agent recorded to keep (`record_note`).
#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct Note {
    pub title: String,
    pub text: String,
    pub at: u64,
}

/// One line of questioning: its own claude session, resumed for follow-ups.
#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct Thread {
    pub id: u32,
    pub title: String,
    #[serde(skip)]
    pub session: Option<String>,
    pub messages: Vec<Message>,
    #[serde(default)]
    pub notes: Vec<Note>,
    #[serde(default)]
    pub running: bool,
    /// Asked at the REPL prompt: the REPL assistant's (assist.rs), which
    /// reads the author's session and proposes nothing.
    #[serde(default, skip_serializing_if = "std::ops::Not::not")]
    pub repl: bool,
}

/// What the author and the agents see of an op.
#[derive(Clone, Debug, Serialize)]
pub struct OpView {
    #[serde(flatten)]
    pub op: Op,
    /// It cannot apply to the current program any more.
    pub stale: bool,
    /// Pending ops of other threads that touch the same text.
    pub conflicts: Vec<u32>,
    /// Whether accepting it leaves a program that passes the static check;
    /// absent until the studio has checked (ask.rs).
    #[serde(skip_serializing_if = "Option::is_none")]
    pub check: Option<Acceptance>,
}

/// What accepting a pending op would take.
#[derive(Clone, Debug, Default, PartialEq, Serialize)]
pub struct Acceptance {
    /// The program checks with it accepted.
    pub ok: bool,
    /// The earlier pending ops of its thread it builds on, accepted with it.
    pub with: Vec<u32>,
    /// Why it cannot be accepted: the located errors.
    #[serde(skip_serializing_if = "String::is_empty")]
    pub reason: String,
}

#[derive(Clone, Debug, Default, Serialize)]
pub struct ReviewView {
    pub threads: Vec<Thread>,
    pub changesets: Vec<Changeset>,
    pub ops: Vec<OpView>,
}

#[derive(Default)]
pub struct Review {
    threads: Vec<Thread>,
    changesets: Vec<Changeset>,
    ops: Vec<Op>,
}

/// What a project keeps of its review across restarts: everything, the
/// threads' claude sessions included, so a follow-up still resumes one.
#[derive(Deserialize, Serialize)]
pub struct Record {
    threads: Vec<Thread>,
    sessions: BTreeMap<u32, String>,
    changesets: Vec<Changeset>,
    ops: Vec<Op>,
}

impl Review {
    pub fn record(&self) -> Record {
        Record {
            threads: self.threads.clone(),
            sessions: self
                .threads
                .iter()
                .filter_map(|thread| Some((thread.id, thread.session.clone()?)))
                .collect(),
            changesets: self.changesets.clone(),
            ops: self.ops.clone(),
        }
    }

    /// The review `record` kept. No run survives a restart, so no thread is
    /// running.
    pub fn restore(record: Record) -> Self {
        let Record { mut threads, sessions, changesets, ops } = record;
        for thread in &mut threads {
            thread.session = sessions.get(&thread.id).cloned();
            thread.running = false;
        }
        Self { threads, changesets, ops }
    }

    pub fn new_thread(&mut self, title: String) -> u32 {
        let id = self.threads.len() as u32 + 1;
        self.threads.push(Thread {
            id,
            title,
            session: None,
            messages: Vec::new(),
            notes: Vec::new(),
            running: false,
            repl: false,
        });
        id
    }

    pub fn thread(&self, id: u32) -> Option<&Thread> {
        self.threads.iter().find(|thread| thread.id == id)
    }

    pub fn thread_mut(&mut self, id: u32) -> Option<&mut Thread> {
        self.threads.iter_mut().find(|thread| thread.id == id)
    }

    /// The changeset a thread's next proposals join: one per turn.
    pub fn open_changeset(&mut self, thread: u32, title: String) -> u32 {
        let id = self.changesets.len() as u32 + 1;
        self.changesets.push(Changeset { id, thread, title });
        id
    }

    /// The program as `thread` sees it: `text` with the thread's own pending
    /// ops applied in order, skipping any that no longer apply.
    pub fn fork(&self, text: &str, thread: u32) -> String {
        self.ops
            .iter()
            .filter(|op| op.thread == thread && op.status == Status::Pending)
            .fold(text.to_owned(), |text, op| apply(&text, &op.change).unwrap_or(text))
    }

    /// Queue a change from `thread`, checked against that thread's fork so
    /// it may build on its own earlier proposals. An edit of text that one
    /// of those proposals wrote corrects it instead: that proposal is
    /// rewritten, and its id returned, so the author reviews the final
    /// text, not a chain of fixes.
    pub fn propose(&mut self, text: &str, thread: u32, change: Change, note: String) -> Result<u32, String> {
        apply(&self.fork(text, thread), &change)?;
        if let Change::Edit { old, new } = &change
            && let Some(op) = self.ops.iter_mut().rev().find(|op| {
                op.thread == thread && op.status == Status::Pending && written(&op.change).matches(old.as_str()).count() == 1
            })
        {
            match &mut op.change {
                Change::Append { source } => *source = source.replacen(old.as_str(), new, 1),
                Change::Edit { new: written, .. } => *written = written.replacen(old.as_str(), new, 1),
            }
            if !note.is_empty() {
                op.note = note;
            }
            return Ok(op.id);
        }
        let changeset = self
            .changesets
            .iter()
            .rev()
            .find(|changeset| changeset.thread == thread)
            .map(|changeset| changeset.id)
            .ok_or("this thread has no open changeset")?;
        let id = self.ops.len() as u32 + 1;
        self.ops.push(Op {
            id,
            thread,
            changeset,
            change,
            note,
            status: Status::Pending,
        });
        Ok(id)
    }

    /// Accept op `id` against `text`, returning the new program text.
    pub fn accept(&mut self, text: &str, id: u32) -> Result<String, String> {
        let view = self.view(text);
        let op = view
            .ops
            .iter()
            .find(|view| view.op.id == id)
            .ok_or_else(|| format!("no proposal #{id}"))?;
        if op.op.status != Status::Pending {
            return Err(format!("proposal #{id} is already {:?}", op.op.status).to_lowercase());
        }
        if !op.conflicts.is_empty() {
            return Err(format!(
                "proposal #{id} conflicts with {}; reject one side first",
                ids(&op.conflicts)
            ));
        }
        let updated = apply(text, &op.op.change)
            .map_err(|why| format!("proposal #{id} no longer applies: {why}"))?;
        self.set_status(id, Status::Accepted);
        Ok(updated)
    }

    /// What was asked in the turn that proposed op `id`: its changeset's
    /// title.
    pub fn request_of(&self, id: u32) -> Option<String> {
        let op = self.ops.iter().find(|op| op.id == id)?;
        let changeset = self.changesets.iter().find(|changeset| changeset.id == op.changeset)?;
        Some(changeset.title.clone())
    }

    pub fn reject(&mut self, id: u32) -> Result<(), String> {
        match self.ops.iter().find(|op| op.id == id).map(|op| op.status) {
            None => Err(format!("no proposal #{id}")),
            Some(Status::Pending) => {
                self.set_status(id, Status::Rejected);
                Ok(())
            }
            Some(status) => Err(format!("proposal #{id} is already {status:?}").to_lowercase()),
        }
    }

    fn set_status(&mut self, id: u32, status: Status) {
        if let Some(op) = self.ops.iter_mut().find(|op| op.id == id) {
            op.status = status;
        }
    }

    pub fn view(&self, text: &str) -> ReviewView {
        let pending: Vec<&Op> = self.ops.iter().filter(|op| op.status == Status::Pending).collect();
        let ops = self
            .ops
            .iter()
            .map(|op| {
                let pending_here = op.status == Status::Pending;
                OpView {
                    op: op.clone(),
                    // Built on the thread's own earlier proposal, an op may
                    // apply only to its fork until that one is accepted.
                    stale: pending_here && apply(&self.fork_before(text, op), &op.change).is_err(),
                    conflicts: if pending_here {
                        pending
                            .iter()
                            .filter(|other| other.thread != op.thread && overlaps(text, &op.change, &other.change))
                            .map(|other| other.id)
                            .collect()
                    } else {
                        Vec::new()
                    },
                    check: None,
                }
            })
            .collect();
        ReviewView {
            threads: self.threads.clone(),
            changesets: self.changesets.clone(),
            ops,
        }
    }

    /// Pending op `id`'s change, and the pending changes of its thread
    /// before it, in order.
    pub fn chain(&self, id: u32) -> Option<(Change, Vec<(u32, Change)>)> {
        let op = self.ops.iter().find(|op| op.id == id && op.status == Status::Pending)?;
        let before = self
            .ops
            .iter()
            .filter(|other| other.thread == op.thread && other.status == Status::Pending && other.id < id)
            .map(|other| (other.id, other.change.clone()))
            .collect();
        Some((op.change.clone(), before))
    }

    /// A copy to try accepts on, without changing this one.
    pub fn clone_for_check(&self) -> Review {
        Review { threads: Vec::new(), changesets: self.changesets.clone(), ops: self.ops.clone() }
    }

    /// The pending ops of `changeset`.
    pub fn pending_of(&self, changeset: u32) -> Vec<u32> {
        self.ops
            .iter()
            .filter(|op| op.changeset == changeset && op.status == Status::Pending)
            .map(|op| op.id)
            .collect()
    }

    /// `text` with the pending ops of `op`'s thread that precede it applied.
    fn fork_before(&self, text: &str, op: &Op) -> String {
        self.ops
            .iter()
            .filter(|other| other.thread == op.thread && other.status == Status::Pending && other.id < op.id)
            .fold(text.to_owned(), |text, other| apply(&text, &other.change).unwrap_or(text))
    }
}

/// `text` with `change` made, or why it cannot be.
pub fn apply(text: &str, change: &Change) -> Result<String, String> {
    match change {
        Change::Append { source } => {
            if source.trim().is_empty() {
                return Err("nothing to append".to_owned());
            }
            let mut out = text.trim_end().to_owned();
            if !out.is_empty() {
                out.push_str("\n\n");
            }
            out.push_str(source.trim());
            out.push('\n');
            Ok(out)
        }
        Change::Edit { old, new } => {
            if old.is_empty() {
                return Err("old text is empty; use propose_append to add forms".to_owned());
            }
            match text.match_indices(old.as_str()).count() {
                1 => Ok(text.replacen(old.as_str(), new, 1)),
                0 => Err("the old text does not occur in the program".to_owned()),
                n => Err(format!("the old text occurs {n} times; include more context to make it unique")),
            }
        }
    }
}

/// The text a change writes into the program.
fn written(change: &Change) -> &str {
    match change {
        Change::Append { source } => source,
        Change::Edit { new, .. } => new,
    }
}

/// Two edits conflict when the text they replace overlaps. Appends never
/// conflict: both land, one after the other.
fn overlaps(text: &str, a: &Change, b: &Change) -> bool {
    let span = |change: &Change| match change {
        Change::Edit { old, .. } => text.find(old.as_str()).map(|start| start..start + old.len()),
        Change::Append { .. } => None,
    };
    match (span(a), span(b)) {
        (Some(a), Some(b)) => a.start < b.end && b.start < a.end,
        _ => false,
    }
}

fn ids(ids: &[u32]) -> String {
    ids.iter().map(|id| format!("#{id}")).collect::<Vec<_>>().join(", ")
}

#[cfg(test)]
mod tests {
    use super::{Change, Review, Status, apply};

    const PROGRAM: &str = "table (edge int int)\nrule (edge 1 2)\n";

    fn edit(old: &str, new: &str) -> Change {
        Change::Edit { old: old.to_owned(), new: new.to_owned() }
    }

    #[test]
    fn an_edit_needs_its_old_text_exactly_once() {
        assert!(apply(PROGRAM, &edit("(edge 1 2)", "(edge 1 3)")).is_ok());
        assert!(apply(PROGRAM, &edit("(edge 9 9)", "x")).unwrap_err().contains("does not occur"));
        assert!(apply(PROGRAM, &edit("edge", "x")).unwrap_err().contains("2 times"));
    }

    /// A thread builds on its own pending proposals; another thread editing
    /// the same text conflicts, and accepting is refused until one side goes.
    #[test]
    fn threads_fork_conflict_and_accept() {
        let mut review = Review::default();
        let a = review.new_thread("a".into());
        let b = review.new_thread("b".into());
        review.open_changeset(a, "a".into());
        review.open_changeset(b, "b".into());
        let first = review
            .propose(PROGRAM, a, Change::Append { source: "table (path int int)".into() }, "".into())
            .unwrap();
        // builds on `first`, which only exists in a's fork, by spanning it
        // and the author's text
        let second = review
            .propose(PROGRAM, a, edit("2)\n\ntable (path int int)", "2)\n\ntable (path int int)\nrule (edge X Y) --> (path X Y)"), "".into())
            .unwrap();
        assert!(review.propose(PROGRAM, b, edit("table (path int int)", "x"), "".into()).is_err());
        let rival_a = review.propose(PROGRAM, a, edit("table (edge int int)", "table (edge int int) ;; edges"), "".into()).unwrap();
        let rival_b = review.propose(PROGRAM, b, edit("table (edge int int)", "table (edge int int) ;; arcs"), "".into()).unwrap();

        let view = review.view(PROGRAM);
        let op = |id| view.ops.iter().find(|view| view.op.id == id).unwrap();
        // `second` applies on top of `first`: not stale, but not acceptable
        // before it either
        assert!(!op(first).stale && !op(second).stale);
        assert!(review.accept(PROGRAM, second).unwrap_err().contains("no longer applies"));
        assert_eq!(op(rival_a).conflicts, vec![rival_b]);
        assert!(review.accept(PROGRAM, rival_a).unwrap_err().contains("conflicts"));

        review.reject(rival_b).unwrap();
        let after = review.accept(PROGRAM, rival_a).unwrap();
        let after = {
            let with_first = review.accept(&after, first).unwrap();
            review.accept(&with_first, second).unwrap()
        };
        assert_eq!(
            after,
            "table (edge int int) ;; edges\nrule (edge 1 2)\n\ntable (path int int)\nrule (edge X Y) --> (path X Y)\n"
        );
        assert!(review.ops.iter().all(|op| op.status != Status::Pending));
    }

    /// Fixing text a pending proposal wrote rewrites that proposal: the
    /// author sees one change with the final text.
    #[test]
    fn a_correction_folds_into_the_proposal_it_corrects() {
        let mut review = Review::default();
        let a = review.new_thread("a".into());
        review.open_changeset(a, "a".into());
        let first = review
            .propose(PROGRAM, a, Change::Append { source: "rule (edge 2 (+ 1 2)".into() }, "adds a fact".into())
            .unwrap();
        let fix = review.propose(PROGRAM, a, edit("(+ 1 2)", "(+ 1 2))"), "".into()).unwrap();
        assert_eq!(fix, first);
        assert_eq!(review.ops.len(), 1);
        assert_eq!(review.ops[0].change, Change::Append { source: "rule (edge 2 (+ 1 2))".into() });
        assert_eq!(review.ops[0].note, "adds a fact");
        // an edit of the author's own text is a proposal of its own
        let other = review.propose(PROGRAM, a, edit("rule (edge 1 2)", "rule (edge 1 3)"), "".into()).unwrap();
        assert_ne!(other, first);
    }
}
