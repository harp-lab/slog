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
use crate::results::{self, Lineage, Plan, Row, SetId};
use crate::session::{Outcome, Session, SessionView, run_argument};
use crate::studio::{Event, Origin, Phase, Studio};
use serde::{Deserialize, Serialize};
use serde_json::Value;
use std::collections::BTreeSet;
use std::time::Instant;

/// The project store's record of the states.
pub(crate) const RECORD: &str = "states";

/// Prompts kept per state, the newest.
const PROMPTS: usize = 50;

#[derive(Clone, Debug, Eq, PartialEq, Serialize, Deserialize)]
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

#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct Prompt {
    pub line: String,
    pub ok: bool,
}

/// A relation's size moved by a state's change.
#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct Delta {
    pub relation: String,
    pub net: i64,
}

#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct State {
    pub id: u64,
    /// What the author named it (`baseline`), if anything.
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub name: Option<String>,
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
    #[serde(default, skip_serializing_if = "Vec::is_empty")]
    pub staged: Vec<String>,
    /// How long making it took, in milliseconds.
    #[serde(default)]
    pub ms: Option<u64>,
    /// The strata its change ran, and the relations whose sizes moved most.
    #[serde(default)]
    pub strata: Option<u64>,
    #[serde(default)]
    pub deltas: Vec<Delta>,
}

/// The tree of states, which one the session is at, and which one, if any,
/// the prompt explores.
#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct States {
    pub states: Vec<State>,
    pub current: u64,
    #[serde(default)]
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
#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize, Deserialize)]
pub struct Stamp {
    pub id: u64,
    pub pred: Option<u64>,
}

impl Default for States {
    fn default() -> Self {
        Self {
            states: vec![State {
                id: 0,
                name: None,
                pred: None,
                kind: Kind::Start,
                line: String::new(),
                version: None,
                revision: None,
                boundary: None,
                prompts: Vec::new(),
                staged: Vec::new(),
                ms: None,
                strata: None,
                deltas: Vec::new(),
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
        let change = result.and_then(|result| result.get("change"));
        let strata = change.and_then(|change| change["strata"].as_array()).map(|strata| strata.len() as u64);
        let deltas = change
            .and_then(|change| change["size-deltas"].as_array())
            .into_iter()
            .flatten()
            .filter_map(|delta| Some(Delta { relation: delta["relation"].as_str()?.to_owned(), net: delta["net"].as_i64()? }))
            .filter(|delta| delta.net != 0)
            .take(4)
            .collect();
        self.states.push(State {
            id,
            name: None,
            pred: Some(pred),
            kind,
            line: line.to_owned(),
            version,
            revision,
            boundary,
            prompts: Vec::new(),
            staged,
            ms: None,
            strata,
            deltas,
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

    /// How long the current state took to make.
    pub fn timed(&mut self, ms: u64) {
        let current = self.current as usize;
        if let Some(state) = self.states.get_mut(current) {
            state.ms = Some(ms);
        }
    }

    /// A state as the author knows it: its name, else `tN`.
    pub fn label(&self, id: u64) -> String {
        self.get(id).and_then(|state| state.name.clone()).unwrap_or_else(|| format!("t{id}"))
    }

    /// The states kept from an earlier studio, whose session is gone: a
    /// state from nothing, unless the current one already is.
    pub fn reopened(mut self) -> Self {
        self.exploring = None;
        let fresh = self.get(self.current).is_some_and(|state| state.kind == Kind::Start);
        if !fresh && self.get(self.current).is_some() {
            self.derive(Kind::Start, "studio restarted", None, None);
        }
        self
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

/// The kept relations (`r1`, `r2`, …) `text` names.
pub fn kept_names(text: &str) -> Vec<String> {
    text.split(|c: char| c.is_whitespace() || "()[]".contains(c))
        .filter(|word| word.len() > 1 && word.starts_with('r') && word[1..].bytes().all(|b| b.is_ascii_digit()))
        .map(str::to_owned)
        .collect()
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

/// Lanes kept re-deriving past states, the least recently used reused.
const PAST_LANES: usize = 2;

/// A past state, re-derived on a lane of its own and made read-only: the
/// explored state's prompt, and the rows of every view bound to it, are
/// read here.
pub(crate) struct Past {
    lane: Lane,
    session: Session,
    /// The state the lane holds; none until one is re-derived.
    at: Option<u64>,
    /// The kept relations (`r1`, …) defined on it.
    defined: BTreeSet<String>,
    /// The set holding the lane's query cursor.
    holder: Option<SetId>,
    used: u64,
}

#[derive(Default)]
pub(crate) struct Pasts {
    lanes: Vec<Past>,
    clock: u64,
}

/// Lines the explored state refuses: they would leave it, or unprotect it.
const LEAVES: [&str; 8] = ["mode", "run", "discard", "open", "use", "save", "activate", "abort"];

impl Studio {
    pub(crate) fn states(&self) -> std::sync::MutexGuard<'_, States> {
        self.states.lock().expect("states lock")
    }

    /// The current state's stamp.
    pub(crate) fn stamp(&self) -> Stamp {
        let states = self.states();
        states.stamp(states.current)
    }

    /// Show every tab the states, and keep them in the project's store.
    pub(crate) fn publish_states(&self) {
        let view = self.states().clone();
        if let Err(error) = self.store_write(RECORD, &view) {
            self.trouble(&format!("cannot keep the session's states: {error}"));
        }
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
                    states.timed(outcome.ms);
                }
                (Origin::Evaluate, Some(result)) if outcome.line == "tables" => states.name(current, result),
                (Origin::Evaluate, _) => return,
                // a held run that commits is its Run's state
                (Origin::Repl, Some(result)) if committed(result) && before.held => {
                    states.derive(Kind::Run, &outcome.line, version, Some(result));
                    states.timed(outcome.ms);
                }
                (Origin::Repl, Some(result)) if committed(result) => {
                    states.derive(Kind::Change, &outcome.line, None, Some(result));
                    states.timed(outcome.ms);
                }
                (Origin::Repl, _) => states.ask(current, &outcome.line, outcome.ok()),
            }
        }
        self.publish_states();
    }

    /// Name state `id` (`baseline`, `after the fix`); an empty name removes
    /// it.
    pub fn name_state(&self, id: u64, name: &str) {
        let name: String = name.split_whitespace().collect::<Vec<_>>().join(" ").chars().take(40).collect();
        if let Some(state) = self.states().states.get_mut(id as usize) {
            state.name = (!name.is_empty()).then_some(name);
        }
        self.publish_states();
    }

    /// Explore state `id`, read-only; `None`, or the current state,
    /// returns the prompt to the current state.
    pub async fn explore(&self, id: Option<u64>) {
        let target = id.filter(|id| {
            let states = self.states();
            *id != states.current && states.get(*id).is_some()
        });
        let Some(target) = target else {
            self.states().exploring = None;
            return self.publish_states();
        };
        let mut pasts = self.pasts.lock().await;
        match self.past_lane(&mut pasts, target).await {
            Ok(_) => self.states().exploring = Some(target),
            Err(why) => {
                self.states().exploring = None;
                self.trouble(&why);
            }
        }
        drop(pasts);
        self.publish_states();
    }

    /// Answer `line` at the explored state, if one is explored.
    pub(crate) async fn explore_command(&self, line: &str) -> bool {
        let Some(at) = self.states().exploring else { return false };
        self.run_past(line, None, at).await;
        true
    }

    /// Run `line` at past state `at`, read-only: a query's answers open a
    /// set bound to `at`, refining `lineage`'s set when given.
    pub(crate) async fn run_past(&self, line: &str, lineage: Option<Lineage>, at: u64) {
        let started = Instant::now();
        let stamp = self.states().stamp(at);
        let verb = line.split_whitespace().next().unwrap_or("");
        let mut pasts = self.pasts.lock().await;
        let (mut shown, set) = match self.past_lane(&mut pasts, at).await {
            Err(why) => (Session::failure_of(line, "state", &why), None),
            Ok(_) if LEAVES.contains(&verb) => {
                let why = format!("{} is read-only: `{verb}` would leave it; branch from it to change it", self.states().label(at));
                (Session::failure_of(line, "state", &why), None)
            }
            Ok(past) => {
                self.define_kept(past, line).await;
                let outcome = past.session.execute(&past.lane, line).await;
                past.holder = None;
                let query = outcome.result.as_ref().and_then(|result| result["query-mode"].as_str());
                match (query, results::rows_line(line)) {
                    (Some("rows" | "exists"), Some(read)) => {
                        let (shown, set) = self
                            .open_set(&mut past.session, &past.lane, line, &read, &outcome, lineage, stamp, false)
                            .await;
                        past.holder = set;
                        (shown, set)
                    }
                    _ => (outcome, None),
                }
            }
        };
        drop(pasts);
        shown.ms = started.elapsed().as_millis() as u64;
        self.states().ask(at, line, shown.ok());
        self.publish_sets(set);
        self.publish(Event::Entry {
            origin: Origin::Repl,
            set,
            state: stamp,
            exploring: true,
            outcome: shown,
        });
        self.publish_states();
    }

    /// Rows `start..end` of set `id`, which is bound to past state `at`:
    /// read on a lane holding `at`.
    pub(crate) async fn rows_past(&self, id: SetId, start: u64, end: u64, at: u64) -> Result<Vec<Row>, String> {
        let mut pasts = self.pasts.lock().await;
        let label = self.states().label(at);
        self.results().set_loading(id, Some(format!("reading at {label}")));
        self.publish_sets([id]);
        let served = async {
            let past = self.past_lane(&mut pasts, at).await?;
            let mut cursor_lost = false;
            loop {
                let plan = self.results().plan(id, start, end);
                let line = match plan {
                    Plan::Serve(rows) => break Ok(rows),
                    Plan::Fail(why) => break Err(why),
                    Plan::More if past.holder == Some(id) => "more".to_owned(),
                    Plan::More | Plan::Rerun(_) => {
                        let read = self.results().read_line(id).ok_or_else(|| format!("{id} is no longer kept"))?;
                        self.define_kept(past, &read).await;
                        read
                    }
                };
                let outcome = past.session.execute(&past.lane, &line).await;
                past.holder = Some(id);
                let absorbed = match &outcome.result {
                    Some(result) => self.results().absorb_past(id, result),
                    None => Err(outcome.error.map_or_else(String::new, |error| error.message)),
                };
                match absorbed {
                    Ok(()) => {}
                    Err(_) if line == "more" && !cursor_lost => {
                        cursor_lost = true;
                        past.holder = None;
                    }
                    Err(why) => break Err(why),
                }
            }
        }
        .await;
        drop(pasts);
        self.results().set_loading(id, None);
        self.publish_sets([id]);
        served
    }

    /// Run set `id`'s query again at the current state, as a new set.
    pub async fn show_now(&self, id: SetId) {
        let Some(query) = self.results().query_line(id) else {
            return self.trouble(&format!("{id} is no longer kept"));
        };
        self.run_main(&query, None).await;
    }

    /// A lane holding past state `at`: one that holds it already, else the
    /// least recently used, re-derived.
    async fn past_lane<'a>(&self, pasts: &'a mut Pasts, at: u64) -> Result<&'a mut Past, String> {
        pasts.clock += 1;
        let clock = pasts.clock;
        let index = match pasts.lanes.iter().position(|past| past.at == Some(at)) {
            Some(index) => index,
            None => {
                if pasts.lanes.len() < PAST_LANES {
                    let lane = Lane::new(self.lane.root().to_path_buf(), self.lane.status().borrow().mode);
                    pasts.lanes.push(Past {
                        session: Session::new(&lane),
                        lane,
                        at: None,
                        defined: BTreeSet::new(),
                        holder: None,
                        used: 0,
                    });
                }
                let index = (0..pasts.lanes.len()).min_by_key(|&i| pasts.lanes[i].used).expect("a lane");
                self.rederive(&mut pasts.lanes[index], at).await?;
                index
            }
        };
        let past = &mut pasts.lanes[index];
        past.used = clock;
        Ok(past)
    }

    /// Re-derive state `at` on `past`'s lane, in a fresh session, and make
    /// it read-only.
    async fn rederive(&self, past: &mut Past, at: u64) -> Result<(), String> {
        let label = self.states().label(at);
        past.at = None;
        past.defined.clear();
        past.holder = None;
        let started = Instant::now();
        let steps = self.replay_lines(at).map_err(|why| format!("cannot re-derive {label}: {why}"))?;
        let replayed = steps.len();
        let fresh = [
            past.session.view().held.then(|| "abort".to_owned()),
            past.session.view().current.is_some().then(|| "discard session".to_owned()),
        ];
        for line in fresh.into_iter().flatten().chain(steps) {
            if let Some(error) = past.session.execute(&past.lane, &line).await.error {
                return Err(format!("cannot re-derive {label}: `{line}`: {}", error.message));
            }
        }
        // with no database (t0) there is nothing to protect
        if past.session.view().current.is_some()
            && let Some(error) = past.session.execute(&past.lane, "mode readonly").await.error
        {
            return Err(format!("{label} could not be made read-only: {}", error.message));
        }
        past.at = Some(at);
        self.publish(Event::Log {
            line: format!(
                "{label} re-derived, read-only, in {:.1} s from {replayed} step{}",
                started.elapsed().as_secs_f64(),
                if replayed == 1 { "" } else { "s" }
            ),
        });
        Ok(())
    }

    /// Define on `past` the kept relations `line` names, and those their
    /// definitions name, that it does not have yet.
    async fn define_kept(&self, past: &mut Past, line: &str) {
        let mut wanted: Vec<(String, String)> = Vec::new();
        let mut pending = vec![line.to_owned()];
        while let Some(text) = pending.pop() {
            for name in kept_names(&text) {
                if past.defined.contains(&name) || wanted.iter().any(|(known, _)| *known == name) {
                    continue;
                }
                if let Some(definition) = self.results().definition(&name).map(str::to_owned) {
                    pending.push(definition.clone());
                    wanted.push((name, definition));
                }
            }
        }
        if wanted.is_empty() {
            return;
        }
        // those named last are needed first
        wanted.reverse();
        let _ = past.session.execute(&past.lane, "mode mutable").await;
        for (name, definition) in wanted {
            match past.session.execute(&past.lane, &definition).await.error {
                None => {
                    past.defined.insert(name);
                }
                Some(error) => self.trouble(&format!("cannot keep {name} at a past state: {}", error.message)),
            }
        }
        let _ = past.session.execute(&past.lane, "mode readonly").await;
        past.holder = None;
    }

    /// Continue from state `id`: re-derive it in a fresh session on the main
    /// lane, as a new state whose predecessor is `id`.
    pub async fn branch_state(&self, id: u64) {
        if self.states().get(id).is_none() {
            return self.trouble_states(&format!("no state t{id}"));
        }
        let label = self.states().label(id);
        let steps = match self.replay_lines(id) {
            Ok(steps) => steps,
            Err(why) => return self.trouble_states(&format!("cannot branch from {label}: {why}")),
        };
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
        let ms = started.elapsed().as_millis() as u64;
        {
            let mut states = self.states();
            states.generation = self.lane.generation();
            states.timed(ms);
        }
        self.publish_states();
        self.publish(Event::Evaluation { phase: Phase::Done, ok, ms });
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
        // named by its contents: another project's version 3 is another
        // directory
        let contents = crate::hash::Hash::of(serde_json::to_string(&files).unwrap_or_default().as_bytes());
        let directory = std::env::temp_dir()
            .join(format!("slog-studio-{}", std::process::id()))
            .join(format!("{project}-v{version}-{}", &contents.to_string()[..12]));
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
    use crate::lane::{Lane, Mode};
    use crate::projects::Projects;
    use crate::results::{self, SetId};
    use crate::store::tests::Scratch;
    use crate::studio::Studio;
    use slog_repl::server::project_root;
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

    /// A chain 1 → 2 → … → 15: its `path` has 105 rows, more than a page.
    fn chain() -> String {
        let mut text = "table (edge int int)\ntable (path int int)\nrule (edge X Y) --> (path X Y)\n\
                        rule (path X Y) (edge Y Z) --> (path X Z)\n"
            .to_owned();
        for i in 1..15 {
            text.push_str(&format!("rule (edge {i} {})\n", i + 1));
        }
        text
    }

    /// The set the newest entry opened.
    fn opened(events: &mut tokio::sync::broadcast::Receiver<Event>) -> SetId {
        std::iter::from_fn(|| events.try_recv().ok())
            .filter_map(|event| match event {
                Event::Entry { set, .. } => set,
                _ => None,
            })
            .last()
            .expect("a set opened")
    }

    /// A set from t1 read past its first page while the session is at t2
    /// reads t1's rows, not the live session's; its refinement runs at t1;
    /// and "show now" runs its query at t2.
    #[tokio::test]
    async fn a_set_pages_at_its_own_state() {
        let scratch = Scratch::new("paging");
        let studio = studio(&scratch, Mode::Fast, &chain());
        let mut events = studio.subscribe();
        studio.evaluate().await;
        studio.command("?(path X Y)").await;
        let r1 = opened(&mut events);
        studio.command("add (edge 15 16)").await;
        assert_eq!(studio.states().current, 2);
        assert_eq!(studio.results().past(r1, 2), Some(1));

        let rows = studio.rows(r1, 0, 1000).await.expect("rows at t1");
        assert_eq!(rows.len(), 105, "t1's path, not t2's 120");
        assert_eq!(studio.result_views().iter().find(|v| v.id == r1).unwrap().state.unwrap().id, 1);

        let (line, lineage) = studio
            .refinement(r1, &results::Refinement::Filter { column: 0, value: "1".into(), guard: None })
            .expect("a refinement");
        studio.run(&line, Some(lineage)).await;
        let r2 = opened(&mut events);
        let view = studio.result_views().into_iter().find(|v| v.id == r2).unwrap();
        assert_eq!((view.state.unwrap().id, view.total), (1, results::Total::Exact(14)), "refined at t1");

        studio.show_now(r1).await;
        let r3 = opened(&mut events);
        let rows = studio.rows(r3, 0, 1000).await.expect("rows at t2");
        assert_eq!(rows.len(), 120);
        assert_eq!(studio.result_views().iter().find(|v| v.id == r3).unwrap().state.unwrap().id, 2);
        studio.lane.shutdown().await;
    }

    /// A studio started again has the states, their names, and the result
    /// sets, each still read at its state; the session is new.
    #[tokio::test]
    async fn states_and_sets_survive_a_restart() {
        let scratch = Scratch::new("reopen");
        let studio = studio(&scratch, Mode::Fast, &chain());
        let mut events = studio.subscribe();
        studio.evaluate().await;
        studio.command("?(path X Y)").await;
        let r1 = opened(&mut events);
        studio.name_state(1, "  the   baseline ");
        studio.command("add (edge 15 16)").await;
        studio.lane.shutdown().await;
        drop(studio);

        let projects = Projects::new(scratch.path());
        let (project, files) = projects.open("p").expect("open");
        let lane = Lane::new(project_root().expect("repository root"), Mode::Fast);
        let studio = Studio::new(projects, project, files, lane, "test".to_owned());
        {
            let states = studio.states();
            assert_eq!(states.label(1), "the baseline");
            assert_eq!(states.states.len(), 4, "t0, the Run, the add, and the restart");
            let restarted = states.get(states.current).unwrap();
            assert_eq!((restarted.kind.clone(), restarted.pred), (Kind::Start, Some(2)));
        }
        let view = studio.result_views().into_iter().find(|v| v.id == r1).expect("r1 is back");
        assert_eq!(view.state.map(|stamp| stamp.id), Some(1));
        let rows = studio.rows(r1, 0, 1000).await.expect("rows at t1");
        assert_eq!(rows.len(), 105);
        studio.lane.shutdown().await;
    }

    #[test]
    fn only_a_change_with_a_revision_is_committed() {
        assert!(committed(&json!({"change": {"update-revision": 2}})));
        assert!(!committed(&json!({"change": {"update-revision": null}})));
        assert!(!committed(&json!({"kind": "query"})));
    }
}
