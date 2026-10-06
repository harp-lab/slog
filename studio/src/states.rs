//! The session's states, by logical timestamp (`t0`, `t1`, …).
//!
//! t0 is the session before anything. Every committed change to the
//! database makes the next state, derived from the one before: a Run, and
//! a REPL command whose answer reports a `change` (`add`, `del`, `flush`, a
//! scratch rule, `rename`, `drop`, …). A query makes none; it is kept, as a
//! prompt, with the state it ran at. Each state records what made it, the
//! program version a Run evaluated, and the session server's own name for
//! it: the update revision and boundary key its answer reported.
//!
//! A past state is re-derived, not looked up: the daemon keeps old
//! boundaries' names, but `add` and `del` change a relation's contents in
//! place, so an old boundary does not hold its old rows. Studio runs the
//! state's Run's program again, at the version it evaluated, and replays
//! the changes made since (`replay`):
//! - to explore it, on a lane of its own, made read-only, which the prompt
//!   answers from until it returns; the session stays where it was;
//! - to branch from it, in a fresh session on the main lane, as a new
//!   state whose predecessor is the branched one, so the states form a
//!   tree.
//! The notes are in docs/REPL-exploration-kris/notes/repl-timestamps.md.

use crate::lane::Lane;
use crate::session::{Outcome, Session, SessionView, run_argument};
use crate::studio::{Event, Origin, Phase, Studio};
use serde::Serialize;
use serde_json::Value;
use std::time::Instant;

/// Prompts kept per state, the newest.
const PROMPTS: usize = 50;

#[derive(Clone, Debug, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Kind {
    /// The session before anything.
    Start,
    /// A Run evaluated the program from nothing.
    Run,
    /// A committed change made at the prompt.
    Change,
    /// A past state, re-derived to continue from.
    Branch,
}

#[derive(Clone, Debug, Serialize)]
pub struct Prompt {
    pub line: String,
    pub ok: bool,
}

#[derive(Clone, Debug, Serialize)]
pub struct State {
    pub id: u64,
    /// The state this one was derived from; none for t0.
    pub pred: Option<u64>,
    pub kind: Kind,
    /// The command that made it.
    pub line: String,
    /// The program version (versions.rs) a Run evaluated, and every state
    /// derived from it since.
    pub version: Option<u64>,
    /// The session server's update revision and committed boundary, when
    /// its answer reported them.
    pub revision: Option<u64>,
    pub boundary: Option<String>,
    /// The queries asked at this state, oldest first.
    pub prompts: Vec<Prompt>,
    /// The `stage` and `unstage` lines its change committed, before `line`.
    #[serde(skip_serializing_if = "Vec::is_empty")]
    pub staged: Vec<String>,
}

/// The tree of states, which one the session is at, and which one, if any,
/// the prompt explores.
#[derive(Clone, Debug, Serialize)]
pub struct States {
    pub states: Vec<State>,
    pub current: u64,
    pub exploring: Option<u64>,
    /// The main lane's server the states were made on (`Lane::generation`).
    #[serde(skip)]
    pub generation: u64,
    /// Edits staged since the last change, which the next one commits.
    #[serde(skip)]
    pub staged: Vec<String>,
}

/// What a state's entry says of it: `{id, pred}`, on transcript entries and
/// result sets.
#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize)]
pub struct Stamp {
    pub id: u64,
    pub pred: Option<u64>,
}

impl Default for States {
    fn default() -> Self {
        Self {
            states: vec![State {
                id: 0,
                pred: None,
                kind: Kind::Start,
                line: String::new(),
                version: None,
                revision: None,
                boundary: None,
                prompts: Vec::new(),
                staged: Vec::new(),
            }],
            current: 0,
            exploring: None,
            generation: 0,
            staged: Vec::new(),
        }
    }
}

impl States {
    pub fn get(&self, id: u64) -> Option<&State> {
        self.states.get(id as usize)
    }

    pub fn stamp(&self, id: u64) -> Stamp {
        Stamp {
            id,
            pred: self.get(id).and_then(|state| state.pred),
        }
    }

    /// A new state derived from the current one, made current.
    pub fn derive(&mut self, kind: Kind, line: &str, version: Option<u64>, result: Option<&Value>) -> Stamp {
        self.derive_from(self.current, kind, line, version, result)
    }

    /// A new state derived from `pred`, made current.
    pub fn derive_from(
        &mut self,
        pred: u64,
        kind: Kind,
        line: &str,
        version: Option<u64>,
        result: Option<&Value>,
    ) -> Stamp {
        let version = version.or_else(|| self.get(pred).and_then(|state| state.version));
        let id = self.states.len() as u64;
        let (revision, boundary) = result.map_or((None, None), names);
        // a change commits what was staged; anything else starts afresh
        let staged = std::mem::take(&mut self.staged);
        let staged = if kind == Kind::Change { staged } else { Vec::new() };
        self.states.push(State {
            id,
            pred: Some(pred),
            kind,
            line: line.to_owned(),
            version,
            revision,
            boundary,
            prompts: Vec::new(),
            staged,
        });
        self.current = id;
        self.exploring = None;
        self.stamp(id)
    }

    /// What the session server reported of a state after it was made: a
    /// Run's `tables` names the boundary its `run` committed.
    pub fn name(&mut self, id: u64, result: &Value) {
        let (revision, boundary) = names(result);
        if let Some(state) = self.states.get_mut(id as usize) {
            state.revision = revision.or(state.revision);
            state.boundary = boundary.or(state.boundary.take());
        }
    }

    /// A server that restarted has none of the session: a state from
    /// nothing, unless the session is already there.
    pub fn restarted(&mut self, generation: u64) {
        let known = std::mem::replace(&mut self.generation, generation);
        let fresh = self.get(self.current).is_some_and(|state| state.kind == Kind::Start);
        if known != 0 && known != generation && !fresh {
            self.derive(Kind::Start, "restart", None, None);
        }
    }

    /// Keep a prompt with the state it ran at. A `stage` or `unstage` that
    /// was taken is kept for the change that commits it, too.
    pub fn ask(&mut self, id: u64, line: &str, ok: bool) {
        if ok && matches!(line.split_whitespace().next(), Some("stage" | "unstage")) {
            self.staged.push(line.to_owned());
        }
        if let Some(state) = self.states.get_mut(id as usize) {
            state.prompts.push(Prompt {
                line: line.to_owned(),
                ok,
            });
            let over = state.prompts.len().saturating_sub(PROMPTS);
            state.prompts.drain(..over);
        }
    }

    /// The changes that re-derive `id` from the Run before it: that Run's
    /// state, then the lines of each change since, oldest first. None when
    /// no Run precedes it since the session began from nothing.
    pub fn replay(&self, id: u64) -> (Option<&State>, Vec<&State>) {
        let mut changes = Vec::new();
        let mut at = self.get(id);
        while let Some(state) = at {
            match state.kind {
                Kind::Run => {
                    changes.reverse();
                    return (Some(state), changes);
                }
                Kind::Change => changes.push(state),
                // a session from nothing: t0, or a restarted server
                Kind::Start => break,
                Kind::Branch => {}
            }
            // a branch's predecessor is the state it re-derived
            at = state.pred.and_then(|pred| self.get(pred));
        }
        changes.reverse();
        (None, changes)
    }
}

/// Whether a command's answer committed a change to the database: every
/// semantic verb reports a `change` with its update revision.
pub fn committed(result: &Value) -> bool {
    result
        .get("change")
        .is_some_and(|change| change.get("update-revision").is_some_and(|r| !r.is_null()))
}

/// The update revision and boundary key an answer reports, if any.
fn names(result: &Value) -> (Option<u64>, Option<String>) {
    let revision = result.pointer("/change/update-revision").and_then(Value::as_u64);
    let boundary = result
        .get("boundary-key")
        .and_then(Value::as_str)
        .map(str::to_owned);
    (revision, boundary)
}

// ---- Studio's side ------------------------------------------------------------

/// A past state, re-derived on a lane of its own and made read-only, which
/// the prompt's commands go to while it is explored.
pub(crate) struct Explorer {
    lane: Lane,
    session: Session,
    at: u64,
}

impl Studio {
    pub(crate) fn states(&self) -> std::sync::MutexGuard<'_, States> {
        self.states.lock().expect("states lock")
    }

    /// The current state's stamp.
    pub(crate) fn stamp(&self) -> Stamp {
        let states = self.states();
        states.stamp(states.current)
    }

    fn publish_states(&self) {
        let view = self.states().clone();
        self.publish(Event::States(view));
    }

    /// Follow the main lane's session through `outcome`: a Run, or a
    /// committed change at the prompt, makes a state; anything else typed
    /// is a prompt of the current one. `before` is the session it ran in.
    pub(crate) fn observe(&self, origin: Origin, before: &SessionView, outcome: &Outcome) {
        let (version, ..) = self.program();
        {
            let mut states = self.states();
            states.restarted(self.lane.generation());
            let current = states.current;
            match (origin, &outcome.result) {
                (Origin::Evaluate, Some(result)) if outcome.line.starts_with("run ") && !outcome.session.held => {
                    states.derive(Kind::Run, &outcome.line, version, Some(result));
                }
                (Origin::Evaluate, Some(result)) if outcome.line == "tables" => states.name(current, result),
                (Origin::Evaluate, _) => return,
                // a held run that commits is its Run's state
                (Origin::Repl, Some(result)) if committed(result) && before.held => {
                    states.derive(Kind::Run, &outcome.line, version, Some(result));
                }
                (Origin::Repl, Some(result)) if committed(result) => {
                    states.derive(Kind::Change, &outcome.line, None, Some(result));
                }
                (Origin::Repl, _) => states.ask(current, &outcome.line, outcome.ok()),
            }
        }
        self.publish_states();
    }

    /// Explore state `id`, read-only, on a lane of its own; `None`, or the
    /// current state, returns the prompt to the current state.
    pub async fn explore(&self, id: Option<u64>) {
        let mut explorer = self.explorer.lock().await;
        let target = id.filter(|id| {
            let states = self.states();
            *id != states.current && states.get(*id).is_some()
        });
        let Some(target) = target else {
            if let Some(gone) = explorer.take() {
                gone.lane.shutdown().await;
            }
            self.states().exploring = None;
            return self.publish_states();
        };
        let started = Instant::now();
        let steps = match self.replay_lines(target) {
            Ok(steps) => steps,
            Err(why) => return self.trouble_states(&format!("cannot explore t{target}: {why}")),
        };
        let replayed = steps.len();
        let ex = explorer.get_or_insert_with(|| {
            let lane = Lane::new(self.lane.root().to_path_buf(), self.lane.status().borrow().mode);
            Explorer { session: Session::new(&lane), lane, at: target }
        });
        // each state is re-derived in a fresh session
        let fresh = [
            ex.session.view().held.then(|| "abort".to_owned()),
            ex.session.view().current.is_some().then(|| "discard session".to_owned()),
        ];
        for line in fresh.into_iter().flatten().chain(steps) {
            if let Some(error) = ex.session.execute(&ex.lane, &line).await.error {
                if let Some(gone) = explorer.take() {
                    gone.lane.shutdown().await;
                }
                self.states().exploring = None;
                return self.trouble_states(&format!("cannot re-derive t{target}: `{line}`: {}", error.message));
            }
        }
        // Protects the explored database; with none (t0) there is nothing
        // to protect.
        if ex.session.view().current.is_some()
            && let Some(error) = ex.session.execute(&ex.lane, "mode readonly").await.error
        {
            self.trouble(&format!("t{target} could not be made read-only: {}", error.message));
        }
        ex.at = target;
        self.states().exploring = Some(target);
        self.publish(Event::Log {
            line: format!(
                "exploring t{target}, read-only: re-derived in {:.1} s from {replayed} step{}",
                started.elapsed().as_secs_f64(),
                if replayed == 1 { "" } else { "s" }
            ),
        });
        self.publish_states();
    }

    /// Answer `line` at the explored state, if one is explored.
    pub(crate) async fn explore_command(&self, line: &str) -> bool {
        let mut explorer = self.explorer.lock().await;
        let Some(ex) = explorer.as_mut() else { return false };
        // a new state since (a Run) ended the exploring
        if self.states().exploring != Some(ex.at) {
            if let Some(gone) = explorer.take() {
                gone.lane.shutdown().await;
            }
            return false;
        }
        let started = Instant::now();
        let mut outcome = ex.session.execute(&ex.lane, line).await;
        outcome.ms = started.elapsed().as_millis() as u64;
        let state = {
            let mut states = self.states();
            states.ask(ex.at, line, outcome.ok());
            states.stamp(ex.at)
        };
        drop(explorer);
        self.publish(Event::Entry {
            origin: Origin::Repl,
            set: None,
            state,
            exploring: true,
            outcome,
        });
        self.publish_states();
        true
    }

    /// Continue from state `id`: re-derive it in a fresh session on the main
    /// lane, as a new state whose predecessor is `id`.
    pub async fn branch_state(&self, id: u64) {
        if self.states().get(id).is_none() {
            return self.trouble_states(&format!("no state t{id}"));
        }
        let steps = match self.replay_lines(id) {
            Ok(steps) => steps,
            Err(why) => return self.trouble_states(&format!("cannot branch from t{id}: {why}")),
        };
        if let Some(gone) = self.explorer.lock().await.take() {
            gone.lane.shutdown().await;
        }
        let mut session = self.session_lock().await;
        let started = Instant::now();
        self.publish(Event::Evaluation { phase: Phase::Start, ok: false, ms: 0 });
        {
            let mut states = self.states();
            states.restarted(self.lane.generation());
            let version = states.get(id).and_then(|state| state.version);
            states.derive_from(id, Kind::Branch, &format!("branch from t{id}"), version, None);
        }
        self.publish_states();
        let touched = {
            let mut results = self.results();
            results.forget_catalog();
            results.changed()
        };
        self.publish_sets(touched);
        let fresh = [
            session.view().held.then(|| "abort".to_owned()),
            session.view().current.is_some().then(|| "discard session".to_owned()),
        ];
        let mut ok = true;
        for line in fresh.into_iter().flatten().chain(steps).chain(["tables".to_owned()]) {
            let before = session.view().clone();
            let outcome = session.execute(&self.lane, &line).await;
            if let Some(result) = &outcome.result {
                self.results().learn(result);
                let mut states = self.states();
                let current = states.current;
                states.name(current, result);
            }
            self.publish_outcome(Origin::Evaluate, &before, &outcome, None);
            if !outcome.ok() {
                ok = false;
                break;
            }
        }
        self.states().generation = self.lane.generation();
        self.publish_states();
        self.publish(Event::Evaluation { phase: Phase::Done, ok, ms: started.elapsed().as_millis() as u64 });
    }

    /// The lines that re-derive state `id` in a fresh session: its Run's
    /// program, at the version it evaluated, then each change since.
    fn replay_lines(&self, id: u64) -> Result<Vec<String>, String> {
        let (version, changes) = {
            let states = self.states();
            let (run, changes) = states.replay(id);
            let lines: Vec<String> = changes
                .iter()
                .flat_map(|state| state.staged.iter().chain([&state.line]).cloned())
                .collect();
            (run.map(|run| run.version), lines)
        };
        let mut lines = Vec::new();
        match version {
            Some(Some(version)) => lines.push(format!("run {}", self.materialize(version)?)),
            Some(None) => return Err("the program its Run evaluated was not kept".to_owned()),
            None => {}
        }
        lines.extend(changes);
        Ok(lines)
    }

    /// The program of `version`, written to a directory of its own, and the
    /// path of its main file, as `run` takes it.
    fn materialize(&self, version: u64) -> Result<String, String> {
        let files = self.version_files(version)?;
        let (_, main, project) = self.program();
        let project: String = project.chars().map(|c| if c.is_ascii_alphanumeric() { c } else { '_' }).collect();
        let directory = std::env::temp_dir()
            .join(format!("slog-studio-{}", std::process::id()))
            .join(format!("{project}-v{version}"));
        for (path, text) in &files {
            let target = directory.join(path);
            if let Some(parent) = target.parent() {
                std::fs::create_dir_all(parent).map_err(|error| error.to_string())?;
            }
            std::fs::write(&target, text).map_err(|error| format!("cannot write {}: {error}", target.display()))?;
        }
        let main = directory.join(main);
        run_argument(&main)
            .map(str::to_owned)
            .ok_or_else(|| format!("`run` cannot name {}", main.display()))
    }

    /// Report `message`, and the states as they stand.
    fn trouble_states(&self, message: &str) {
        self.publish(Event::Log { line: format!("studio: {message}") });
        self.publish_states();
    }
}

#[cfg(test)]
mod tests {
    use super::{Kind, States, committed};
    use crate::lane::Mode;
    use crate::store::tests::Scratch;
    use crate::studio::Event;
    use crate::studio::tests::studio;
    use serde_json::json;

    fn lines(states: &States, id: u64) -> (Option<String>, Vec<String>) {
        let (run, changes) = states.replay(id);
        (run.map(|run| run.line.clone()), changes.iter().map(|state| state.line.clone()).collect())
    }

    /// t0, a Run, two changes; a branch from the first change, and one more.
    #[test]
    fn states_form_a_tree_and_replay_from_their_run() {
        let mut states = States::default();
        let run = json!({"change": {"update-revision": 3}, "boundary-key": "b1:x:0"});
        states.derive(Kind::Run, "run main.slog", Some(4), Some(&run));
        states.derive(Kind::Change, "add (edge 3 4)", None, None);
        states.ask(2, "?(path 1 X)", true);
        states.derive(Kind::Change, "del (edge 1 2)", None, None);
        let branch = states.derive_from(2, Kind::Branch, "branch from t2", None, None);
        states.derive(Kind::Change, "add (edge 9 9)", None, None);

        assert_eq!((branch.id, branch.pred), (4, Some(2)));
        assert_eq!(states.current, 5);
        let run = states.get(1).unwrap();
        assert_eq!((run.revision, run.boundary.as_deref()), (Some(3), Some("b1:x:0")));
        assert_eq!(states.get(5).unwrap().version, Some(4), "a change is at its Run's program");
        assert_eq!(states.get(2).unwrap().prompts.len(), 1);
        assert_eq!(
            lines(&states, 3),
            (Some("run main.slog".into()), vec!["add (edge 3 4)".into(), "del (edge 1 2)".into()])
        );
        assert_eq!(
            lines(&states, 5),
            (Some("run main.slog".into()), vec!["add (edge 3 4)".into(), "add (edge 9 9)".into()]),
            "a branch replays what it branched from"
        );
    }

    #[test]
    fn a_change_replays_what_it_staged() {
        let mut states = States::default();
        states.derive(Kind::Run, "run main.slog", Some(1), None);
        states.ask(1, "stage +(edge 5 6)", true);
        states.ask(1, "stage +(nosuch 1)", false);
        states.ask(1, "?(edge X Y)", true);
        states.derive(Kind::Change, "flush", None, None);
        states.derive(Kind::Change, "add (edge 1 1)", None, None);
        assert_eq!(states.get(2).unwrap().staged, vec!["stage +(edge 5 6)".to_owned()]);
        assert!(states.get(3).unwrap().staged.is_empty());
    }

    #[test]
    fn a_restarted_server_replays_from_nothing() {
        let mut states = States::default();
        states.derive(Kind::Run, "run main.slog", Some(1), None);
        states.derive(Kind::Start, "restart", None, None);
        states.derive(Kind::Change, "stage + (edge 1 2)", None, None);
        assert_eq!(lines(&states, 3), (None, vec!["stage + (edge 1 2)".into()]));
    }

    /// Entries published since `events` was last drained: (line, state,
    /// exploring, the answer's first lines or error).
    fn entries(events: &mut tokio::sync::broadcast::Receiver<Event>) -> Vec<(String, u64, bool, String)> {
        std::iter::from_fn(|| events.try_recv().ok())
            .filter_map(|event| match event {
                Event::Entry { state, exploring, outcome, .. } => Some((
                    outcome.line.clone(),
                    state.id,
                    exploring,
                    match (&outcome.result, &outcome.error) {
                        (_, Some(error)) => format!("error: {}", error.message),
                        (Some(result), _) => result["lines"].to_string(),
                        _ => String::new(),
                    },
                )),
                _ => None,
            })
            .collect()
    }

    /// A Run and three changes (one staged) make t1..t4; exploring t3 answers there,
    /// read-only, while the session stays at t4; branching from t3 makes
    /// t5, whose database is t3's.
    #[tokio::test]
    async fn explore_and_branch_from_a_past_state() {
        let scratch = Scratch::new("states");
        let program = "table (edge int int)\ntable (path int int)\nrule (edge X Y) --> (path X Y)\n";
        let studio = studio(&scratch, Mode::Fast, program);
        let mut events = studio.subscribe();
        studio.evaluate().await;
        studio.command("add (edge 1 2)").await;
        studio.command("stage +(edge 2 3)").await;
        studio.command("flush").await;
        studio.command("?(path X Y)").await;
        studio.command("del (edge 1 2)").await;
        {
            let states = studio.states();
            let made: Vec<_> = states.states.iter().map(|s| (s.id, s.pred, s.kind.clone(), s.prompts.len())).collect();
            assert_eq!(made, vec![
                (0, None, Kind::Start, 0),
                (1, Some(0), Kind::Run, 0),
                (2, Some(1), Kind::Change, 1),
                (3, Some(2), Kind::Change, 1),
                (4, Some(3), Kind::Change, 0),
            ]);
            assert!(states.get(1).unwrap().boundary.is_some(), "the Run's boundary is named");
            assert!(states.get(1).unwrap().version.is_some(), "the Run's program version is kept");
        }
        entries(&mut events);

        studio.explore(Some(3)).await;
        assert_eq!(studio.states().exploring, Some(3));
        studio.command("?(path X Y)").await;
        studio.command("add (edge 5 5)").await;
        let seen = entries(&mut events);
        assert!(seen.iter().all(|(_, state, exploring, _)| *state == 3 && *exploring), "{seen:?}");
        assert!(seen[0].3.contains("(path 1 2)"), "t3 still has (path 1 2): {seen:?}");
        assert!(seen[0].3.contains("(path 2 3)"), "and what t3's flush committed: {seen:?}");
        assert!(seen[1].3.contains("read-only"), "exploring refuses changes: {seen:?}");
        assert_eq!(studio.states().current, 4);

        studio.explore(None).await;
        studio.command("?(path 1 X)").await;
        let seen = entries(&mut events);
        assert_eq!((seen[0].1, seen[0].2), (4, false));
        assert!(!seen[0].3.contains(" 1 2)"), "t4 has no (path 1 2): {seen:?}");

        studio.branch_state(3).await;
        let branched = studio.states().get(5).map(|s| (s.pred, s.kind.clone()));
        assert_eq!(branched, Some((Some(3), Kind::Branch)));
        entries(&mut events);
        studio.command("?(path 1 X)").await;
        let seen = entries(&mut events);
        assert!(seen[0].3.contains(" 1 2)"), "the branch has t3's (path 1 2): {seen:?}");
        studio.command("add (edge 7 7)").await;
        assert_eq!(studio.states().get(6).map(|s| s.pred), Some(Some(5)));

        // a Run while exploring ends it: the prompt answers at the Run
        studio.explore(Some(2)).await;
        studio.evaluate().await;
        entries(&mut events);
        studio.command("?(path 1 X)").await;
        let seen = entries(&mut events);
        assert_eq!((seen[0].1, seen[0].2), (7, false), "{seen:?}");
        studio.lane.shutdown().await;
    }

    #[test]
    fn only_a_change_with_a_revision_is_committed() {
        assert!(committed(&json!({"change": {"update-revision": 2}})));
        assert!(!committed(&json!({"change": {"update-revision": null}})));
        assert!(!committed(&json!({"kind": "query"})));
    }
}
