//! The studio's side of the agent: threads, the tools mcp.rs exposes, and
//! the author's accept and reject. Agents never touch the author's session:
//! a thread's proposed program is evaluated on the preview lane.
//!
//! No agent-written code reaches the author without passing the static
//! check (check.rs), at three gates:
//! - a proposal is refused, with the located errors as the tool's answer,
//!   unless the thread's program as it would leave it checks; a batch
//!   (`propose_changes`) is checked as a whole, for edits that only check
//!   together;
//! - accepting an op checks the text accepting it makes, taking along the
//!   earlier ops of its thread it builds on, and is refused if that fails;
//!   each pending op's acceptance is kept current for the Accept controls;
//! - a turn may not end with its program failing, or unevaluated
//!   (`turn_gate`, which agent.rs asks before it lets a turn end).

use crate::agent::{self, Agent};
use crate::review::{Acceptance, Change, Message, Note, ReviewView, Status, apply, now};
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

    /// Why `thread`'s turn may not end yet, as a message the agent is
    /// resumed with: its program fails the static check, or was changed
    /// after its last evaluation, or that evaluation failed. None when the
    /// turn proposed nothing pending or all is well.
    pub(crate) async fn turn_gate(&self, thread: u32) -> Option<String> {
        let text = self.text();
        let fork = self.review.lock().expect("review lock").fork(&text, thread);
        if fork == text {
            return None;
        }
        let report = self.check_main(&fork).await;
        if !report.ok {
            let (main, _) = self.main_file();
            return Some(format!(
                "Before you finish: the program as your pending proposals leave it fails the static check:\n{}\nFix them (propose_edit on your proposed text corrects that proposal), then evaluate_proposal.",
                report.describe(&main)
            ));
        }
        match self.evaluated.lock().expect("evaluated lock").get(&thread) {
            Some((hash, true)) if *hash == self::hash(&fork) => None,
            Some((hash, false)) if *hash == self::hash(&fork) => Some(
                "Before you finish: your last evaluate_proposal failed. Fix the proposals until it passes.".to_owned(),
            ),
            _ => Some(
                "Before you finish: your proposals changed after your last evaluate_proposal (or you have not run it). Run evaluate_proposal now, and fix what it reports.".to_owned(),
            ),
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
        self.publish(Event::Review(self.review_view()));
        self.keep_review();
        self.review_changed.notify_one();
    }

    /// The review as tabs see it: each pending op with what accepting it
    /// would take, when that has been checked against the text as it is.
    pub(crate) fn review_view(&self) -> ReviewView {
        let text = self.text();
        let review = self.review.lock().expect("review lock");
        let mut view = review.view(&text);
        let kept = self.acceptances.lock().expect("acceptances lock");
        for op in &mut view.ops {
            op.check = kept
                .get(&op.op.id)
                .filter(|(key, _)| *key == acceptance_key(&text, &review, op.op.id))
                .map(|(_, check)| check.clone());
        }
        view
    }

    /// Keep each pending op's acceptance current: checked again whenever the
    /// review or the program changes, and shown to every tab.
    pub fn watch_proposals(self: &Arc<Self>) {
        let studio = Arc::downgrade(self);
        let changed = self.review_changed.clone();
        tokio::spawn(async move {
            loop {
                changed.notified().await;
                let Some(studio) = studio.upgrade() else { return };
                if studio.refresh_acceptances().await {
                    studio.publish(Event::Review(studio.review_view()));
                }
            }
        });
    }

    /// Check the pending ops whose acceptance is not known for the text as
    /// it is; whether any was.
    async fn refresh_acceptances(&self) -> bool {
        let text = self.text();
        let pending: Vec<(u32, u64)> = {
            let review = self.review.lock().expect("review lock");
            review
                .view(&text)
                .ops
                .iter()
                .filter(|op| op.op.status == Status::Pending)
                .map(|op| (op.op.id, acceptance_key(&text, &review, op.op.id)))
                .collect()
        };
        let mut checked = false;
        for (id, key) in pending {
            let known = self.acceptances.lock().expect("acceptances lock").get(&id).is_some_and(|(k, _)| *k == key);
            if !known {
                let check = self.acceptance(&text, id).await;
                self.acceptances.lock().expect("acceptances lock").insert(id, (key, check));
                checked = true;
            }
        }
        checked
    }

    /// What accepting pending op `id` into the main file's `text` would
    /// take: the op alone if the result checks, else with the fewest
    /// earlier ops of its thread that make it check.
    pub(crate) async fn acceptance(&self, text: &str, id: u32) -> Acceptance {
        let Some((change, before)) = self.review.lock().expect("review lock").chain(id) else {
            return Acceptance { reason: format!("#{id} is not pending"), ..Acceptance::default() };
        };
        let (main, _) = self.main_file();
        let made = |with: &[(u32, Change)]| {
            with.iter()
                .map(|(_, change)| change)
                .chain(std::iter::once(&change))
                .try_fold(text.to_owned(), |text, change| apply(&text, change).ok())
        };
        let mut failure = None;
        if let Some(alone) = made(&[]) {
            let report = self.check_main(&alone).await;
            if report.ok {
                return Acceptance { ok: true, ..Acceptance::default() };
            }
            failure = Some(report.describe(&main));
        }
        if let Some(all) = made(&before)
            && !before.is_empty()
            && self.check_main(&all).await.ok
        {
            let mut needed = before;
            for index in (0..needed.len()).rev() {
                let mut fewer = needed.clone();
                fewer.remove(index);
                if let Some(fewer_text) = made(&fewer)
                    && self.check_main(&fewer_text).await.ok
                {
                    needed = fewer;
                }
            }
            return Acceptance { ok: true, with: needed.iter().map(|(id, _)| *id).collect(), reason: String::new() };
        }
        let reason = match failure {
            Some(errors) => format!("accepting it leaves the program failing the check:\n{errors}"),
            None => "it builds on earlier proposals of its thread that no longer apply".to_owned(),
        };
        Acceptance { ok: false, with: Vec::new(), reason }
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

    /// Propose `changes`, made in order, if the thread's program as they
    /// leave it passes the static check; else refuse them with its errors.
    pub(crate) async fn propose(&self, thread: u32, changes: Vec<Change>, note: String) -> Result<Value, String> {
        let text = self.text();
        let fork = self.review.lock().expect("review lock").fork(&text, thread);
        let count = changes.len();
        let after = changes.iter().enumerate().try_fold(fork.clone(), |after, (index, change)| {
            apply(&after, change).map_err(|why| if count == 1 { why } else { format!("change {} of {count}: {why}", index + 1) })
        })?;
        let report = self.check_main(&after).await;
        if !report.ok {
            let (main, _) = self.main_file();
            let also = if self.check_main(&fork).await.ok {
                ""
            } else {
                "\nThe program fails the check without this change too: fix those errors as well."
            };
            return Err(format!(
                "Refused: the program as this would leave it fails the static check, so nothing was proposed. Fix it and propose again (lines are those of get_program's text with the change made; propose_changes takes edits that only check together):\n{}{also}",
                report.describe(&main)
            ));
        }
        let mut review = self.review.lock().expect("review lock");
        let mut ids: Vec<u32> = Vec::new();
        for change in changes {
            let id = review.propose(&text, thread, change, note.clone())?;
            if !ids.contains(&id) {
                ids.push(id);
            }
        }
        drop(review);
        self.publish_review();
        Ok(json!({
            "proposed": ids[0],
            "ops": ids,
            "checks": "the program as your proposals leave it passes the static check (parse, types, negation, strata)",
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
        self.evaluated.lock().expect("evaluated lock").insert(thread, (hash, ok));
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

    /// Accept the ops `ids`, with the earlier ops of their threads they
    /// build on, as one version labelled with the request that proposed
    /// them -- if the program they leave passes the static check.
    pub async fn accept(&self, ids: &[u32]) -> Result<(), String> {
        let text = self.text();
        let mut all: Vec<u32> = Vec::new();
        for &id in ids {
            let check = self.acceptance(&text, id).await;
            if !check.ok {
                return Err(format!("#{id} cannot be accepted: {}", check.reason));
            }
            all.extend(check.with);
            all.push(id);
        }
        all.sort_unstable();
        all.dedup();
        // The check of the whole, made as accepting will make it.
        let made = {
            let mut review = self.review.lock().expect("review lock").clone_for_check();
            all.iter().try_fold(text.clone(), |text, id| review.accept(&text, *id))?
        };
        let report = self.check_main(&made).await;
        if !report.ok {
            let (main, _) = self.main_file();
            return Err(format!("accepting {} leaves the program failing the check:\n{}", ids_of(&all), report.describe(&main)));
        }
        let request = self.review.lock().expect("review lock").request_of(all[0]);
        self.record_version(Made::Accept, request, |files, main| {
            let mut review = self.review.lock().expect("review lock");
            let updated = all.iter().try_fold(files[main].clone(), |text, id| review.accept(&text, *id))?;
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

    /// Accept every pending op of a changeset, as one version.
    pub async fn accept_changeset(&self, changeset: u32) -> Result<(), String> {
        let ids = self.review.lock().expect("review lock").pending_of(changeset);
        if ids.is_empty() {
            return Err("nothing of it is pending".to_owned());
        }
        self.accept(&ids).await
    }
}

/// Identifies what op `id`'s acceptance was checked against: the text, and
/// the op and its thread's earlier pending ops.
fn acceptance_key(text: &str, review: &crate::review::Review, id: u32) -> u64 {
    hash(&format!("{text}\u{0}{:?}", review.chain(id)))
}

fn ids_of(ids: &[u32]) -> String {
    ids.iter().map(|id| format!("#{id}")).collect::<Vec<_>>().join(", ")
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

#[cfg(test)]
mod tests {
    use crate::lane::Mode;
    use crate::review::Change;
    use crate::store::tests::Scratch;
    use crate::studio::tests::studio;

    fn append(source: &str) -> Change {
        Change::Append { source: source.to_owned() }
    }

    /// What reaches the author checks: a proposal that would leave the
    /// program failing is refused with its located error; changes that only
    /// check together go in as a batch; accepting one of them takes along
    /// the one it builds on; and an accept that would leave the program
    /// failing is refused.
    #[tokio::test]
    async fn only_code_that_checks_reaches_the_author() {
        let scratch = Scratch::new("ask-checks");
        let studio = studio(&scratch, Mode::Fast, "table (edge int int)\nrule (edge 1 2)\n");
        let thread = {
            let mut review = studio.review.lock().unwrap();
            let thread = review.new_thread("t".into());
            review.open_changeset(thread, "t".into());
            thread
        };
        let refused = studio.propose(thread, vec![append("rule (edge 2 3")], "".into()).await.unwrap_err();
        assert!(refused.contains("4:6: the ( at 4:6 opening `(edge 2 3 ...` is never closed"), "{refused}");
        assert_eq!(studio.proposals_of(thread), serde_json::json!([]));

        let rule = append("rule (edge X Y) --> (path X Y)");
        let alone = studio.propose(thread, vec![rule.clone()], "".into()).await.unwrap_err();
        assert!(alone.contains("Table path in (path X Y) is not defined"), "{alone}");
        let taken = studio
            .propose(thread, vec![append("table (path int int)"), rule], "declares and derives path".into())
            .await
            .unwrap();
        let op = |index: usize| taken["ops"][index].as_u64().unwrap() as u32;
        let (table, derive) = (op(0), op(1));

        let text = studio.main_file().1;
        let needs = studio.acceptance(&text, derive).await;
        assert!(needs.ok && needs.with == vec![table], "{needs:?}");
        studio.accept(&[derive]).await.unwrap();
        assert!(studio.main_file().1.contains("table (path int int)\n\nrule (edge X Y) --> (path X Y)"));

        // the author takes away what a pending proposal relies on
        let reads = studio.propose(thread, vec![append("rule (path 1 X) --> (edge X X)")], "".into()).await.unwrap();
        let reads = reads["proposed"].as_u64().unwrap() as u32;
        let version = studio.snapshot().await.files[0].version;
        studio.edit(0, "main.slog", version, "table (edge int int)\nrule (edge 1 2)\n".into()).unwrap();
        let refused = studio.accept(&[reads]).await.unwrap_err();
        assert!(refused.contains("Table path in (path 1 X) is not defined"), "{refused}");
    }
}
