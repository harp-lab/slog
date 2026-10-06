//! A conversation with a lane's session server: what its answers say about
//! the session (the current database, a held run), and the one way Studio
//! evaluates a program.
//!
//! Evaluation runs the file in a fresh session: the program is the whole
//! file, evaluated from nothing. Re-running into an old session would layer
//! the new program over the last one (audit M-01, M-07).

use crate::lane::Lane;
use serde::Serialize;
use serde_json::Value;
use slog_repl::protocol::{Response, ServerError};
use std::path::Path;
use std::time::Instant;

/// What the session server is doing, as far as its answers have told us.
#[derive(Clone, Debug, Default, Eq, PartialEq, Serialize)]
pub struct SessionView {
    /// The current database (`scratch` for an evaluated program), if any.
    pub current: Option<String>,
    /// A run is paused at a gate, break, step, or interrupt, waiting for
    /// continue, commit, or abort.
    pub held: bool,
}

/// One command and what came of it.
#[derive(Clone, Debug, Serialize)]
pub struct Outcome {
    pub line: String,
    pub ms: u64,
    pub result: Option<Value>,
    pub error: Option<ServerError>,
    /// The session as it stood after this command.
    #[serde(skip)]
    pub session: SessionView,
}

impl Outcome {
    pub fn ok(&self) -> bool {
        self.error.is_none()
    }
}

/// How an evaluation ended.
#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Evaluated {
    /// The program ran to its fixpoint, and its relations were listed.
    Done,
    /// The run is held mid-way (a break, a step, a gate, an interrupt),
    /// waiting for continue, commit or abort; its relations are not listed,
    /// since the session reads nothing while a run is parked.
    Held,
    /// A step failed.
    Failed,
}

impl Evaluated {
    /// The program ran to its fixpoint.
    pub fn done(self) -> bool {
        self == Evaluated::Done
    }
}

pub struct Session {
    /// The lane generation `view` describes; a new server has no session.
    generation: u64,
    view: SessionView,
}

impl Session {
    pub fn new(lane: &Lane) -> Self {
        Self {
            generation: lane.generation(),
            view: SessionView::default(),
        }
    }

    pub fn view(&self) -> &SessionView {
        &self.view
    }

    /// Send one REPL line and follow the session state its answer reports.
    pub async fn execute(&mut self, lane: &Lane, line: &str) -> Outcome {
        let started = Instant::now();
        let answer = lane.command(line).await;
        self.refresh(lane);
        let (result, error) = match answer {
            Ok(Response {
                ok: true, result, ..
            }) => (Some(result.unwrap_or(Value::Null)), None),
            Ok(Response { error, .. }) => (
                None,
                Some(error.unwrap_or_else(|| server_error("server", "unknown server failure"))),
            ),
            Err(message) => (None, Some(server_error("lane", &message))),
        };
        // Failures carry no session state; only successes move it.
        if let Some(result) = &result {
            self.view = SessionView {
                current: result
                    .get("current")
                    .and_then(Value::as_str)
                    .map(str::to_owned),
                held: result.get("held").and_then(Value::as_bool).unwrap_or(false),
            };
        }
        Outcome {
            line: line.to_owned(),
            ms: started.elapsed().as_millis() as u64,
            result,
            error,
            session: self.view.clone(),
        }
    }

    /// Evaluate `file` from nothing: resolve any held run, discard the
    /// current session, send `prepare` (e.g. breaks to arm) to the fresh
    /// one, run the program, and list its relations -- unless the run is
    /// held, when the session would refuse the read. `each` sees every
    /// command's outcome in order.
    pub async fn evaluate(
        &mut self,
        lane: &Lane,
        file: &Path,
        prepare: &[String],
        each: &mut (dyn FnMut(&Outcome) + Send),
    ) -> Evaluated {
        let Some(path) = run_argument(file) else {
            each(&self.failure(
                "run",
                "path",
                &format!(
                    "`run` cannot name {}: its path has whitespace or quotes",
                    file.display()
                ),
            ));
            return Evaluated::Failed;
        };
        self.refresh(lane);
        // `discard` refuses while a run is held, and quitting would commit it.
        let mut steps = Vec::new();
        if self.view.held {
            steps.push("abort".to_owned());
        }
        if self.view.current.is_some() {
            steps.push("discard session".to_owned());
        }
        // A prepare step that is refused (a breakpoint whose condition does
        // not read) is reported, and the run goes on without it.
        let first_prepare = steps.len();
        steps.extend_from_slice(prepare);
        steps.push(format!("run {path}"));
        let run = steps.len() - 1;
        for (index, line) in steps.into_iter().enumerate() {
            let outcome = self.execute(lane, &line).await;
            each(&outcome);
            let preparing = (first_prepare..first_prepare + prepare.len()).contains(&index);
            if !outcome.ok() && !preparing {
                return Evaluated::Failed;
            }
            if index == run && self.view.held {
                return Evaluated::Held;
            }
        }
        let outcome = self.execute(lane, "tables").await;
        each(&outcome);
        if outcome.ok() { Evaluated::Done } else { Evaluated::Failed }
    }

    /// An outcome for a step that failed before reaching the server.
    pub fn failure(&self, line: &str, kind: &str, message: &str) -> Outcome {
        Outcome {
            session: self.view.clone(),
            ..Self::failure_of(line, kind, message)
        }
    }

    /// An outcome for a line refused before any session saw it.
    pub fn failure_of(line: &str, kind: &str, message: &str) -> Outcome {
        Outcome {
            line: line.to_owned(),
            ms: 0,
            result: None,
            error: Some(server_error(kind, message)),
            session: SessionView::default(),
        }
    }

    /// A server that restarted has no session and nothing held.
    fn refresh(&mut self, lane: &Lane) {
        let generation = lane.generation();
        if self.generation != generation {
            self.generation = generation;
            self.view = SessionView::default();
        }
    }
}

fn server_error(kind: &str, message: &str) -> ServerError {
    ServerError {
        kind: kind.to_owned(),
        message: message.to_owned(),
        span: None,
    }
}

/// `run` takes the rest of its line verbatim, with no quoting (audit M-15),
/// so a path is usable only if it has no whitespace or quotes.
pub fn run_argument(file: &Path) -> Option<&str> {
    file.to_str()
        .filter(|path| !path.contains(|c: char| c.is_whitespace() || c == '"' || c == '\''))
}
