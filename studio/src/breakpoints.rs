//! Breakpoints as the editor sets them: on a rule, or on one clause of it
//! (a body atom it matches, a head it writes, a demand it asks or answers),
//! with a condition, an ignore count, or as a logpoint. Each is kept with
//! the project, arms as one `break` line when Debug runs, and is reconciled
//! with a held run as it is edited, so a change takes effect without a
//! re-run. After a run and at each stop, the session's `breaks` listing
//! says of each whether it can stop, and how often it has.

use crate::session::{Outcome, run_argument};
use crate::studio::{Event, Studio};
use serde::{Deserialize, Serialize};
use serde_json::Value;
use std::collections::HashMap;

/// The project store's record of the breakpoints, file -> breakpoints.
pub const RECORD: &str = "breakpoints";

#[derive(Clone, Debug, Deserialize, Serialize, PartialEq, Eq)]
pub struct Breakpoint {
    /// The editor's name for it, stable across edits and runs.
    pub id: String,
    /// The line of its rule's `rule` keyword, where the compiler locates it.
    pub line: u32,
    /// Where the editor shows it: the clause's line and column. None for
    /// the whole rule, shown at `line`.
    #[serde(default)]
    pub at: Option<(u32, u32)>,
    /// The clause, as `break` spells it: `demand (nf _)`, `answer (nf _ _)`,
    /// `match (edge _ _)` or `emit (path _ _)`. None for the whole rule.
    #[serde(default)]
    pub clause: Option<String>,
    /// Slog guards over the pattern's and the rule's variables.
    #[serde(default)]
    pub condition: String,
    #[serde(default)]
    pub ignore: u64,
    /// Record each hit in the log rather than stop.
    #[serde(default)]
    pub log: bool,
    #[serde(default = "yes")]
    pub enabled: bool,
}

fn yes() -> bool {
    true
}

impl Breakpoint {
    /// The REPL line arming it in `file`, a path `run` can name.
    pub fn command(&self, file: &str) -> String {
        let mut line = format!("break {file}:{}", self.line);
        if let Some(clause) = &self.clause {
            line += " ";
            line += clause.trim();
        }
        if !self.condition.trim().is_empty() {
            line += " when ";
            line += self.condition.trim();
        }
        if self.ignore > 0 {
            line += &format!(" ignore {}", self.ignore);
        }
        if self.log {
            line += " log";
        }
        line
    }
}

/// What the session says of one breakpoint.
#[derive(Clone, Debug, Default, Serialize, PartialEq)]
pub struct Status {
    pub id: String,
    /// The session's break, `b3`, when armed.
    pub server: Option<String>,
    pub hits: u64,
    /// bound | pending | unbound | error | off (disabled, so not armed)
    pub status: String,
    pub why: String,
    /// The port the daemon stops at, as the listing describes it.
    pub compiled: String,
}

/// The breaks armed for the editor's breakpoints in the current session.
#[derive(Default)]
pub struct Armed {
    /// Whether a Debug run made this session: only then is there anything
    /// to reconcile with.
    pub debugging: bool,
    /// editor id -> (break id, the line that armed it)
    pub breaks: HashMap<String, (String, String)>,
    /// editor id -> why its line was refused
    pub refused: HashMap<String, String>,
}

/// The `Break b3` or `Logpoint b3` a `break` answers with.
fn armed_id(outcome: &Outcome) -> Option<String> {
    let title = outcome.result.as_ref()?["title"].as_str()?;
    let (_, id) = title.split_once(' ')?;
    id.starts_with('b').then(|| id.to_owned())
}

/// The verbs a `Quiet` request may send: they observe the session.
const QUIET: [&str; 5] = ["calls", "breaks", "logs", "frames", "watches"];

impl Studio {
    /// One observing REPL line, answered without a transcript entry.
    pub async fn quiet(&self, line: &str) -> Outcome {
        let verb = line.split_whitespace().next().unwrap_or("");
        let mut session = self.session_lock().await;
        if !QUIET.contains(&verb) {
            return session.failure(line, "quiet", &format!("{verb} is not one of {}", QUIET.join(", ")));
        }
        let started = std::time::Instant::now();
        let mut outcome = session.execute(&self.lane, line).await;
        outcome.ms = started.elapsed().as_millis() as u64;
        outcome
    }

    /// The lines arming every enabled breakpoint, with their editor ids.
    pub(crate) fn break_lines(&self) -> Vec<(String, String)> {
        let open = self.open_breakpoints();
        let (directory, points) = (open.0, open.1);
        let mut lines = Vec::new();
        for (path, list) in &points {
            let file = directory.join(path);
            let Some(file) = run_argument(&file) else { continue };
            for point in list.iter().filter(|point| point.enabled) {
                lines.push((point.id.clone(), point.command(file)));
            }
        }
        lines
    }

    /// Note which breaks the Debug run's `break` lines armed.
    pub(crate) fn note_armed(&self, lines: &[(String, String)], outcomes: &[Outcome]) {
        let mut armed = self.armed.lock().expect("armed lock");
        *armed = Armed { debugging: true, ..Armed::default() };
        for (id, line) in lines {
            match outcomes.iter().find(|outcome| &outcome.line == line) {
                Some(outcome) if outcome.ok() => {
                    if let Some(server) = armed_id(outcome) {
                        armed.breaks.insert(id.clone(), (server, line.clone()));
                    }
                }
                Some(outcome) => {
                    let why = outcome.error.as_ref().map(|error| error.message.clone()).unwrap_or_default();
                    armed.refused.insert(id.clone(), why);
                }
                None => {}
            }
        }
    }

    /// Replace `file`'s breakpoints: kept with the project at once and
    /// shown to every tab. Answers whether the session has breaks to
    /// reconcile with them (`reconcile`, in the background).
    pub fn set_breakpoints(&self, file: String, points: Vec<Breakpoint>) -> bool {
        if !self.keep_breakpoints(&file, &points) {
            return false;
        }
        self.publish(Event::Breakpoints { file, points });
        self.armed.lock().expect("armed lock").debugging
    }

    /// Arm, re-arm and remove breaks until the session's match the
    /// breakpoints, then publish what it says of them.
    pub(crate) async fn reconcile(&self) {
        let wanted: HashMap<String, String> = self.break_lines().into_iter().collect();
        let mut session = self.session_lock().await;
        let held = {
            let armed = self.armed.lock().expect("armed lock");
            if !armed.debugging {
                return;
            }
            armed.breaks.clone()
        };
        let lane = &self.lane;
        for (id, (server, line)) in &held {
            if wanted.get(id) != Some(line) {
                session.execute(lane, &format!("unbreak {server}")).await;
                self.armed.lock().expect("armed lock").breaks.remove(id);
            }
        }
        for (id, line) in &wanted {
            if held.get(id).is_some_and(|(_, armed)| armed == line) {
                continue;
            }
            let outcome = session.execute(lane, line).await;
            let mut armed = self.armed.lock().expect("armed lock");
            armed.refused.remove(id);
            match armed_id(&outcome) {
                Some(server) if outcome.ok() => {
                    armed.breaks.insert(id.clone(), (server, line.clone()));
                }
                _ => {
                    let why = outcome.error.map(|error| error.message).unwrap_or_default();
                    armed.refused.insert(id.clone(), why);
                }
            }
        }
        self.publish_status(&mut session).await;
    }

    /// Ask the session about its breaks and publish each breakpoint's
    /// status. Quiet: no transcript entry.
    pub(crate) async fn publish_status(&self, session: &mut crate::session::Session) {
        let listing = session.execute(&self.lane, "breaks").await;
        let listed: HashMap<String, Value> = listing
            .result
            .as_ref()
            .and_then(|result| result["breaks"].as_array())
            .map(|list| {
                list.iter()
                    .filter_map(|b| Some((b["id"].as_str()?.to_owned(), b.clone())))
                    .collect()
            })
            .unwrap_or_default();
        let points = self.open_breakpoints().1;
        let armed = self.armed.lock().expect("armed lock");
        let statuses: Vec<Status> = points
            .values()
            .flatten()
            .map(|point| {
                let mut status = Status { id: point.id.clone(), ..Status::default() };
                if !point.enabled {
                    status.status = "off".into();
                    status.why = "disabled".into();
                } else if let Some(why) = armed.refused.get(&point.id) {
                    status.status = "error".into();
                    status.why = why.clone();
                } else if let Some(b) = armed.breaks.get(&point.id).and_then(|(server, _)| {
                    status.server = Some(server.clone());
                    listed.get(server)
                }) {
                    status.hits = b["hits"].as_u64().unwrap_or(0);
                    status.status = b["status"].as_str().unwrap_or("bound").to_owned();
                    status.why = b["why"].as_str().unwrap_or("").to_owned();
                    status.compiled = b["compiled"].as_str().unwrap_or("").to_owned();
                } else {
                    status.status = "pending".into();
                    status.why = "arms when Debug runs".into();
                }
                status
            })
            .collect();
        drop(armed);
        self.publish(Event::BreakpointStatus { statuses });
    }
}

#[cfg(test)]
mod tests {
    use super::Breakpoint;

    #[test]
    fn a_breakpoint_arms_as_one_break_line() {
        let mut point = Breakpoint {
            id: "p1".into(),
            line: 12,
            at: Some((13, 5)),
            clause: Some("demand (nf _)".into()),
            condition: "(/= T V)".into(),
            ignore: 2,
            log: true,
            enabled: true,
        };
        assert_eq!(point.command("/p/main.slog"), "break /p/main.slog:12 demand (nf _) when (/= T V) ignore 2 log");
        point.clause = None;
        point.condition.clear();
        point.ignore = 0;
        point.log = false;
        assert_eq!(point.command("/p/main.slog"), "break /p/main.slog:12");
    }
}
