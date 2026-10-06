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

use serde::Serialize;

#[derive(Clone, Debug, Eq, PartialEq, Serialize)]
#[serde(tag = "kind", rename_all = "lowercase")]
pub enum Change {
    /// Replace the one occurrence of `old` with `new`.
    Edit { old: String, new: String },
    /// Add `source` at the end of the program.
    Append { source: String },
}

#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Status {
    Pending,
    Accepted,
    Rejected,
}

#[derive(Clone, Debug, Serialize)]
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
#[derive(Clone, Debug, Serialize)]
pub struct Changeset {
    pub id: u32,
    pub thread: u32,
    pub title: String,
}

#[derive(Clone, Debug, Serialize)]
pub struct Message {
    /// "user", "assistant", "tool", or "error".
    pub role: String,
    pub text: String,
}

/// One line of questioning: its own claude session, resumed for follow-ups.
#[derive(Clone, Debug, Serialize)]
pub struct Thread {
    pub id: u32,
    pub title: String,
    #[serde(skip)]
    pub session: Option<String>,
    pub messages: Vec<Message>,
    pub running: bool,
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

impl Review {
    pub fn new_thread(&mut self, title: String) -> u32 {
        let id = self.threads.len() as u32 + 1;
        self.threads.push(Thread {
            id,
            title,
            session: None,
            messages: Vec::new(),
            running: false,
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
    /// it may build on its own earlier proposals.
    pub fn propose(&mut self, text: &str, thread: u32, change: Change, note: String) -> Result<u32, String> {
        apply(&self.fork(text, thread), &change)?;
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
                }
            })
            .collect();
        ReviewView {
            threads: self.threads.clone(),
            changesets: self.changesets.clone(),
            ops,
        }
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
        // builds on `first`, which only exists in a's fork
        let second = review
            .propose(PROGRAM, a, edit("table (path int int)", "table (path int int)\nrule (edge X Y) --> (path X Y)"), "".into())
            .unwrap();
        assert!(review.propose(PROGRAM, b, edit("table (path int int)", "x"), "".into()).is_err());
        let rival_a = review.propose(PROGRAM, a, edit("rule (edge 1 2)", "rule (edge 1 3)"), "".into()).unwrap();
        let rival_b = review.propose(PROGRAM, b, edit("rule (edge 1 2)", "rule (edge 2 2)"), "".into()).unwrap();

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
            "table (edge int int)\nrule (edge 1 3)\n\ntable (path int int)\nrule (edge X Y) --> (path X Y)\n"
        );
        assert!(review.ops.iter().all(|op| op.status != Status::Pending));
    }
}
