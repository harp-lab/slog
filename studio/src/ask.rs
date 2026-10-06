//! The studio's side of the agent: threads, the tools mcp.rs exposes, and
//! the author's accept and reject. Agents never touch the author's session:
//! a thread's proposed program is evaluated on the preview lane.

use crate::agent::{self, Agent};
use crate::review::{Change, Message, Note, Status, now};
use crate::lane::Lane;
use crate::session::{Outcome, Session, run_argument};
use crate::studio::{Event, Studio};
use crate::versions::Origin as Made;
use serde_json::{Value, json};
use std::sync::Arc;

impl Studio {
    /// Ask in `thread`, or in a new thread when `None`. Returns its id; the
    /// run's progress arrives as events.
    pub fn ask(self: &Arc<Self>, thread: Option<u32>, message: String) -> Result<u32, String> {
        if let Some(why) = Agent::unavailable() {
            return Err(why);
        }
        let message = message.trim().to_owned();
        if message.is_empty() {
            return Err("ask something".to_owned());
        }
        let mut review = self.review.lock().expect("review lock");
        let thread = match thread {
            Some(id) => {
                review.thread(id).ok_or_else(|| format!("no thread {id}"))?;
                if self.agent.is_running(id) {
                    return Err("this thread is still working: wait for it, or ask in a new one".to_owned());
                }
                id
            }
            None => review.new_thread(agent::title_of(&message)),
        };
        let entry = review.thread_mut(thread).expect("the thread exists");
        entry.messages.push(Message::new("user", &message, Value::Null));
        entry.running = true;
        // Each turn's proposals form one changeset, named after the request.
        review.open_changeset(thread, agent::title_of(&message));
        drop(review);
        self.publish_review();
        let file = self.main_name();
        let (main, _) = self.main_file();
        let directory = main.parent().map(|dir| dir.display().to_string()).unwrap_or_default();
        let root = self.lane.root().display();
        let context = format!(
            "(Slog Studio: the program file is {file}, in {directory}; your working directory is the Slog repository, {root}.)\n"
        );
        tokio::spawn(agent::run(self.clone(), agent::Kind::Ask, thread, message, context));
        Ok(thread)
    }

    pub fn stop_thread(&self, thread: u32) -> bool {
        self.agent.stop(thread)
    }

    /// Add `message` to `thread`'s transcript; returns its index there.
    pub(crate) fn thread_push(&self, thread: u32, message: Message) -> usize {
        let mut review = self.review.lock().expect("review lock");
        let Some(entry) = review.thread_mut(thread) else { return 0 };
        entry.messages.push(message);
        entry.messages.len() - 1
    }

    /// Change entry `index` of `thread`'s transcript; returns it as changed.
    pub(crate) fn thread_update(&self, thread: u32, index: usize, change: impl FnOnce(&mut Message)) -> Option<Message> {
        let mut review = self.review.lock().expect("review lock");
        let message = review.thread_mut(thread)?.messages.get_mut(index)?;
        change(message);
        Some(message.clone())
    }

    pub(crate) fn thread_session(&self, thread: u32) -> Option<String> {
        self.review.lock().expect("review lock").thread(thread).and_then(|entry| entry.session.clone())
    }

    pub(crate) fn set_thread_session(&self, thread: u32, session: Option<String>) {
        let mut review = self.review.lock().expect("review lock");
        let Some(entry) = review.thread_mut(thread) else { return };
        if entry.session != session {
            entry.session = session;
            drop(review);
            self.keep_review();
        }
    }

    pub(crate) fn finish_turn(&self, thread: u32) {
        if let Some(entry) = self.review.lock().expect("review lock").thread_mut(thread) {
            entry.running = false;
        }
        self.publish_review();
    }

    /// Show every tab the review as it stands, and keep it.
    pub(crate) fn publish_review(&self) {
        let text = self.text();
        let view = self.review.lock().expect("review lock").view(&text);
        self.publish(Event::Review(view));
        self.keep_review();
    }

    /// The main file's working text: the program agents read and change.
    fn text(&self) -> String {
        self.main_file().1
    }

    pub(crate) fn main_name(&self) -> String {
        let (path, _) = self.main_file();
        path.file_name().map(|name| name.to_string_lossy().into_owned()).unwrap_or_default()
    }

    // ---- tools (mcp.rs) ------------------------------------------------

    pub(crate) fn program_for(&self, thread: u32) -> Value {
        let text = self.review.lock().expect("review lock").fork(&self.text(), thread);
        json!({
            "file": self.main_name(),
            "text": text,
            "note": "the author's program with your pending proposals applied",
        })
    }

    pub(crate) fn propose(&self, thread: u32, change: Change, note: String) -> Result<Value, String> {
        let text = self.text();
        let id = self.review.lock().expect("review lock").propose(&text, thread, change, note)?;
        self.publish_review();
        Ok(json!({
            "proposed": id,
            "message": "queued for the author to accept or reject; nothing changed yet. evaluate_proposal runs the program as your proposals would leave it.",
        }))
    }

    pub(crate) fn record_note(&self, thread: u32, title: String, text: String) -> Result<Value, String> {
        if title.trim().is_empty() || text.trim().is_empty() {
            return Err("a note needs a title and a text".to_owned());
        }
        let mut review = self.review.lock().expect("review lock");
        let entry = review.thread_mut(thread).ok_or_else(|| format!("no thread {thread}"))?;
        entry.notes.push(Note { title, text, at: now() });
        let count = entry.notes.len();
        drop(review);
        self.keep_review();
        Ok(json!({ "recorded": count, "message": "kept with this thread; get_notes reads it back in later turns" }))
    }

    pub(crate) fn notes_of(&self, thread: u32) -> Value {
        let review = self.review.lock().expect("review lock");
        json!(review.thread(thread).map(|entry| entry.notes.clone()).unwrap_or_default())
    }

    pub(crate) fn proposals_of(&self, thread: u32) -> Value {
        let view = self.review.lock().expect("review lock").view(&self.text());
        json!(view.ops.into_iter().filter(|op| op.op.thread == thread).collect::<Vec<_>>())
    }

    /// Evaluate `thread`'s proposed program, from nothing, on the preview
    /// lane, and report its relations or what failed.
    pub(crate) async fn evaluate_fork(&self, thread: u32) -> Value {
        let mut preview = self.preview_session.lock().await;
        let (session, loaded) = &mut *preview;
        let (outcomes, ok, hash) = self.evaluate_fork_in(&self.preview, session, thread, &[]).await;
        *loaded = ok.then_some((thread, hash));
        fork_report(&outcomes, ok)
    }

    /// Run a `?` query against `thread`'s proposed program, evaluating it
    /// first unless the preview session already holds exactly that text.
    pub(crate) async fn query_fork(&self, thread: u32, query: &str) -> Result<Value, String> {
        if !query.trim_start().starts_with('?') {
            return Err("a query starts with `?`, e.g. `?(path 1 Y)`".to_owned());
        }
        self.preview_line(thread, query).await
    }

    /// Send one REPL line to the evaluation of `thread`'s proposed program,
    /// evaluating it first unless the preview session already holds exactly
    /// that text.
    pub(crate) async fn preview_line(&self, thread: u32, line: &str) -> Result<Value, String> {
        let mut preview = self.preview_session.lock().await;
        let (session, loaded) = &mut *preview;
        if *loaded != Some((thread, self.fork_hash(thread))) {
            let (outcomes, ok, hash) = self.evaluate_fork_in(&self.preview, session, thread, &[]).await;
            if !ok {
                return Err(format!("the proposed program does not evaluate: {}", fork_report(&outcomes, false)));
            }
            *loaded = Some((thread, hash));
        }
        let outcome = session.execute(&self.preview, line).await;
        match (outcome.result, outcome.error) {
            (Some(result), _) => Ok(json!({ "title": result["title"], "lines": result["lines"] })),
            (None, Some(error)) => Err(error.message),
            (None, None) => Err("no answer".to_owned()),
        }
    }

    /// Identifies `thread`'s proposed program as it stands.
    pub(crate) fn fork_hash(&self, thread: u32) -> u64 {
        hash(&self.review.lock().expect("review lock").fork(&self.text(), thread))
    }

    /// Where a proposed program is evaluated from: beside the main file (so
    /// its includes resolve), under a hidden name.
    pub(crate) fn preview_path(&self) -> std::path::PathBuf {
        let (main, _) = self.main_file();
        let name = format!(
            ".{}.studio-preview.slog",
            main.file_stem().map(|stem| stem.to_string_lossy().into_owned()).unwrap_or_default()
        );
        main.with_file_name(name)
    }

    /// The fork, written to `preview_path`, evaluated on `lane` after the
    /// `prepare` commands, and removed.
    pub(crate) async fn evaluate_fork_in(
        &self,
        lane: &Lane,
        session: &mut Session,
        thread: u32,
        prepare: &[String],
    ) -> (Vec<Outcome>, bool, u64) {
        let text = self.review.lock().expect("review lock").fork(&self.text(), thread);
        let hash = hash(&text);
        let path = self.preview_path();
        if run_argument(&path).is_none() {
            return (vec![session.failure("run", "path", "the program's directory cannot be named by `run`")], false, hash);
        }
        if let Err(error) = std::fs::write(&path, &text) {
            let message = format!("cannot write {}: {error}", path.display());
            return (vec![session.failure("run", "write", &message)], false, hash);
        }
        let mut outcomes = Vec::new();
        let ok = session
            .evaluate(lane, &path, prepare, &mut |outcome| outcomes.push(outcome.clone()))
            .await;
        let _ = std::fs::remove_file(&path);
        (outcomes, ok, hash)
    }

    // ---- the author's decisions ----------------------------------------

    /// Apply op `op` to the main file, as a version labelled with the
    /// request that proposed it.
    pub fn accept(&self, op: u32) -> Result<(), String> {
        let request = self.review.lock().expect("review lock").request_of(op);
        self.record_version(Made::Accept, request, |files, main| {
            let updated = self.review.lock().expect("review lock").accept(&files[main], op)?;
            files.insert(main.to_owned(), updated);
            Ok(())
        })?;
        self.publish_review();
        Ok(())
    }

    pub fn reject(&self, op: u32) -> Result<(), String> {
        self.review.lock().expect("review lock").reject(op)?;
        self.publish_review();
        Ok(())
    }

    /// Accept every pending op of a changeset in order; ones that no longer
    /// apply or conflict stay pending and are reported.
    pub fn accept_changeset(&self, changeset: u32) -> Vec<String> {
        let ids: Vec<u32> = {
            let review = self.review.lock().expect("review lock");
            review
                .view(&self.text())
                .ops
                .into_iter()
                .filter(|op| op.op.changeset == changeset && op.op.status == Status::Pending)
                .map(|op| op.op.id)
                .collect()
        };
        ids.into_iter().filter_map(|id| self.accept(id).err()).collect()
    }
}

/// What an agent learns from evaluating its proposed program.
pub(crate) fn fork_report(outcomes: &[Outcome], ok: bool) -> Value {
    if ok {
        let relations = outcomes
            .iter()
            .rev()
            .find(|outcome| outcome.line == "tables")
            .and_then(|outcome| outcome.result.as_ref())
            .map(|result| result["relations"].clone())
            .unwrap_or(Value::Null);
        json!({ "ok": true, "relations": relations })
    } else {
        let error = outcomes.iter().rev().find_map(|outcome| outcome.error.as_ref());
        json!({
            "ok": false,
            "error": error.map(|error| error.message.clone()),
            // the span's file is the hidden preview copy; its lines are the
            // proposed program's lines
            "line": error.and_then(|error| error.span.as_ref()).map(|span| span.line),
        })
    }
}

/// FNV-1a 64: identifies the proposed text the preview session holds.
fn hash(text: &str) -> u64 {
    text.bytes()
        .fold(0xcbf2_9ce4_8422_2325, |hash, byte| (hash ^ u64::from(byte)).wrapping_mul(0x0100_0000_01b3))
}
