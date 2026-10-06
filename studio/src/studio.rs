//! One program file, the lane that evaluates it, and the events every open
//! browser tab observes.
//!
//! The server owns the text. A tab edits by sending the whole text with the
//! version it edited; an edit to a superseded version is refused and answered
//! with the current text, so two tabs cannot silently overwrite each other.

use crate::lane::{Lane, LaneStatus};
use crate::scenario::{self, Report};
use crate::session::{Outcome, Session, SessionView, run_argument};
use serde::Serialize;
use std::path::PathBuf;
use std::sync::Arc;
use std::time::Instant;
use tokio::sync::{Mutex, broadcast};

/// Everything a tab needs to render the studio from scratch.
#[derive(Clone, Debug, Serialize)]
pub struct Snapshot {
    pub file: String,
    pub text: String,
    pub version: u64,
    pub saved: bool,
    pub lane: LaneStatus,
    pub session: SessionView,
    pub breakpoints: Vec<u32>,
}

#[derive(Clone, Debug, Serialize)]
#[serde(tag = "t", rename_all = "kebab-case")]
pub enum Event {
    /// The text changed; `origin` is the connection that changed it.
    Text { version: u64, text: String, origin: u64 },
    Saved { version: u64 },
    /// The lines carrying breakpoints changed.
    Breakpoints { lines: Vec<u32> },
    Lane(LaneStatus),
    Session(SessionView),
    /// A line of the session server's stderr.
    Log { line: String },
    /// One command and its outcome.
    Entry {
        origin: Origin,
        #[serde(flatten)]
        outcome: Outcome,
    },
    Evaluation { phase: Phase, ok: bool, ms: u64 },
    /// A scenario beside the program started, or finished with a report or
    /// an error that kept it from running.
    Scenario {
        name: String,
        running: bool,
        report: Option<Report>,
        error: Option<String>,
    },
}

#[derive(Clone, Copy, Debug, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Phase {
    Start,
    Done,
}

#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Origin {
    /// Typed at the REPL prompt.
    Repl,
    /// Issued by Studio to evaluate the program.
    Evaluate,
}

const SCENARIO_SUFFIX: &str = ".scenario.toml";

struct Doc {
    text: String,
    version: u64,
    saved_version: u64,
}

pub struct Studio {
    file: PathBuf,
    doc: std::sync::Mutex<Doc>,
    /// 1-based lines whose rule a debug run stops in (`break FILE:LINE`).
    breakpoints: std::sync::Mutex<Vec<u32>>,
    pub lane: Lane,
    /// Held across each command, and across a whole evaluation, so commands
    /// from different tabs never interleave within one.
    session: Mutex<Session>,
    events: broadcast::Sender<Event>,
}

impl Studio {
    /// `file` must be absolute; it need not exist yet.
    pub fn new(file: PathBuf, text: String, lane: Lane) -> Self {
        Self {
            file,
            doc: std::sync::Mutex::new(Doc {
                text,
                version: 0,
                saved_version: 0,
            }),
            breakpoints: std::sync::Mutex::new(Vec::new()),
            session: Mutex::new(Session::new(&lane)),
            lane,
            events: broadcast::channel(1024).0,
        }
    }

    /// Relay the lane's status changes and stderr to every tab, for as long
    /// as the studio lives.
    pub fn relay_lane(self: &Arc<Self>) {
        let mut status = self.lane.status();
        let studio = Arc::downgrade(self);
        tokio::spawn(async move {
            while status.changed().await.is_ok() {
                let Some(studio) = studio.upgrade() else { return };
                studio.publish(Event::Lane(status.borrow_and_update().clone()));
            }
        });
        let mut log = self.lane.log();
        let studio = Arc::downgrade(self);
        tokio::spawn(async move {
            loop {
                let line = match log.recv().await {
                    Ok(line) => line,
                    Err(broadcast::error::RecvError::Lagged(skipped)) => {
                        format!("[{skipped} lines of server output skipped]")
                    }
                    Err(broadcast::error::RecvError::Closed) => return,
                };
                let Some(studio) = studio.upgrade() else { return };
                studio.publish(Event::Log { line });
            }
        });
    }

    pub fn subscribe(&self) -> broadcast::Receiver<Event> {
        self.events.subscribe()
    }

    pub fn publish(&self, event: Event) {
        // No subscribers is not an error: nobody has a tab open.
        let _ = self.events.send(event);
    }

    pub async fn snapshot(&self) -> Snapshot {
        let session = self.session.lock().await.view().clone();
        let doc = self.doc.lock().expect("doc lock");
        Snapshot {
            file: self.file.display().to_string(),
            text: doc.text.clone(),
            version: doc.version,
            saved: doc.saved_version == doc.version,
            lane: self.lane.status().borrow().clone(),
            session,
            breakpoints: self.breakpoints.lock().expect("breakpoints lock").clone(),
        }
    }

    /// Replace the breakpoint lines; the editor tracks them as text moves.
    pub fn set_breakpoints(&self, mut lines: Vec<u32>) {
        lines.sort_unstable();
        lines.dedup();
        *self.breakpoints.lock().expect("breakpoints lock") = lines.clone();
        self.publish(Event::Breakpoints { lines });
    }

    /// Replace the text of version `base`. Returns the new version, or the
    /// current version and text when `base` is not current.
    pub fn edit(&self, origin: u64, base: u64, text: String) -> Result<u64, (u64, String)> {
        let mut doc = self.doc.lock().expect("doc lock");
        if base != doc.version {
            return Err((doc.version, doc.text.clone()));
        }
        doc.version += 1;
        doc.text = text.clone();
        let version = doc.version;
        drop(doc);
        self.publish(Event::Text {
            version,
            text,
            origin,
        });
        Ok(version)
    }

    /// Write the current text to the file if it changed since the last save.
    pub fn save(&self) -> Result<(), String> {
        let mut doc = self.doc.lock().expect("doc lock");
        if doc.saved_version == doc.version && self.file.exists() {
            return Ok(());
        }
        std::fs::write(&self.file, &doc.text)
            .map_err(|error| format!("cannot write {}: {error}", self.file.display()))?;
        doc.saved_version = doc.version;
        let version = doc.version;
        drop(doc);
        self.publish(Event::Saved { version });
        Ok(())
    }

    /// Run one line typed at the REPL prompt.
    pub async fn command(&self, line: &str) {
        let mut session = self.session.lock().await;
        let before = session.view().clone();
        let outcome = session.execute(&self.lane, line).await;
        self.publish_outcome(Origin::Repl, &before, &outcome);
    }

    /// Save, then evaluate the file from nothing in a fresh session.
    pub async fn evaluate(&self) {
        let started = Instant::now();
        let mut session = self.session.lock().await;
        self.publish(Event::Evaluation {
            phase: Phase::Start,
            ok: false,
            ms: 0,
        });
        let ok = match self.save() {
            Err(message) => {
                let failure = session.failure("save", "save", &message);
                self.publish_outcome(Origin::Evaluate, session.view(), &failure);
                false
            }
            Ok(()) => {
                let mut shown = session.view().clone();
                session
                    .evaluate(&self.lane, &self.file, &mut |outcome| {
                        self.publish_outcome(Origin::Evaluate, &shown, outcome);
                        shown = outcome.session.clone();
                    })
                    .await
            }
        };
        self.publish(Event::Evaluation {
            phase: Phase::Done,
            ok,
            ms: started.elapsed().as_millis() as u64,
        });
    }

    /// The scenario files beside the program: `*.scenario.toml` in its
    /// directory, by name.
    pub fn scenarios(&self) -> Vec<String> {
        let Some(directory) = self.file.parent() else {
            return Vec::new();
        };
        let mut names: Vec<String> = std::fs::read_dir(directory)
            .into_iter()
            .flatten()
            .filter_map(|entry| entry.ok()?.file_name().into_string().ok())
            .filter(|name| name.ends_with(SCENARIO_SUFFIX))
            .collect();
        names.sort();
        names
    }

    /// Run the scenario beside the program named `name`, on a lane of its
    /// own, publishing its start and its report.
    pub async fn run_scenario(&self, name: &str) {
        let publish = |running, report, error| {
            self.publish(Event::Scenario {
                name: name.to_owned(),
                running,
                report,
                error,
            })
        };
        // Only a file directly beside the program: the name is not a path.
        let path = match self.file.parent() {
            Some(directory) if name.ends_with(SCENARIO_SUFFIX) && !name.contains('/') => {
                directory.join(name)
            }
            _ => return publish(false, None, Some(format!("no scenario named {name}"))),
        };
        publish(true, None, None);
        match scenario::run(self.lane.root(), &path).await {
            Ok(report) => publish(false, Some(report), None),
            Err(error) => publish(false, None, Some(error)),
        }
    }

    /// Evaluate, then arm a break at each breakpoint line and run the
    /// program again into the session, so the run stops in those rules.
    /// A break needs the rule resident, hence the evaluation first; the
    /// re-run of the same program derives nothing new, it only passes the
    /// rules' ports again.
    pub async fn debug(&self) {
        let started = Instant::now();
        let mut session = self.session.lock().await;
        self.publish(Event::Evaluation {
            phase: Phase::Start,
            ok: false,
            ms: 0,
        });
        let ok = self.debug_in(&mut session).await;
        self.publish(Event::Evaluation {
            phase: Phase::Done,
            ok,
            ms: started.elapsed().as_millis() as u64,
        });
    }

    async fn debug_in(&self, session: &mut Session) -> bool {
        if let Err(message) = self.save() {
            let failure = session.failure("save", "save", &message);
            self.publish_outcome(Origin::Evaluate, session.view(), &failure);
            return false;
        }
        let mut shown = session.view().clone();
        let evaluated = session
            .evaluate(&self.lane, &self.file, &mut |outcome| {
                self.publish_outcome(Origin::Evaluate, &shown, outcome);
                shown = outcome.session.clone();
            })
            .await;
        // evaluate has already refused a path `run` cannot name
        let (true, Some(path)) = (evaluated, run_argument(&self.file)) else {
            return false;
        };
        let lines = self.breakpoints.lock().expect("breakpoints lock").clone();
        for line in lines {
            let before = session.view().clone();
            let outcome = session.execute(&self.lane, &format!("break {path}:{line}")).await;
            self.publish_outcome(Origin::Evaluate, &before, &outcome);
        }
        let before = session.view().clone();
        let outcome = session.execute(&self.lane, &format!("run {path}")).await;
        self.publish_outcome(Origin::Evaluate, &before, &outcome);
        outcome.ok()
    }

    /// Publish an entry, and the session state when it moved past `before`.
    fn publish_outcome(&self, origin: Origin, before: &SessionView, outcome: &Outcome) {
        if outcome.session != *before {
            self.publish(Event::Session(outcome.session.clone()));
        }
        self.publish(Event::Entry {
            origin,
            outcome: outcome.clone(),
        });
    }
}

#[cfg(test)]
mod tests {
    use super::{Event, Origin, Studio};
    use crate::lane::{Lane, Mode};
    use crate::session::Outcome;
    use slog_repl::server::project_root;
    use std::path::PathBuf;

    fn studio(file: PathBuf, text: &str) -> Studio {
        let lane = Lane::new(project_root().expect("repository root"), Mode::Fast);
        Studio::new(file, text.to_owned(), lane)
    }

    #[test]
    fn an_edit_to_a_superseded_version_is_refused_with_the_current_text() {
        let studio = studio(PathBuf::from("/nonexistent/p.slog"), "a");
        assert_eq!(studio.edit(1, 0, "ab".to_owned()), Ok(1));
        assert_eq!(
            studio.edit(2, 0, "ax".to_owned()),
            Err((1, "ab".to_owned()))
        );
        assert_eq!(studio.edit(2, 1, "abc".to_owned()), Ok(2));
    }

    /// Evaluation starts from nothing: re-evaluating an edited program shows
    /// only the new program's relations, and a syntax error comes back with
    /// its position in the file.
    #[tokio::test]
    async fn evaluation_runs_the_saved_program_in_a_fresh_session() {
        let directory = std::env::temp_dir().join(format!("studio-test-{}", std::process::id()));
        std::fs::create_dir_all(&directory).expect("temporary directory");
        let file = directory.join("arith.slog");
        let studio = studio(
            file.clone(),
            "table (edge int int)\nrule (edge 1 2)\nrule (edge 2 3)\n",
        );
        let mut events = studio.subscribe();

        studio.evaluate().await;
        assert_eq!(relations(&mut events), vec![("edge".to_owned(), 2)]);

        studio
            .edit(0, 0, "table (node int)\nrule (node 7)\n".to_owned())
            .expect("edit");
        studio.evaluate().await;
        assert_eq!(relations(&mut events), vec![("node".to_owned(), 1)]);

        studio
            .edit(0, 1, "table (node int)\nrule (node 7))\n".to_owned())
            .expect("edit");
        studio.evaluate().await;
        let span = outcomes(&mut events)
            .into_iter()
            .find_map(|outcome| outcome.error.and_then(|error| error.span))
            .expect("a positioned syntax error");
        assert_eq!((span.file.as_str(), span.line, span.col), (file.to_str().unwrap(), 2, 14));

        studio.lane.shutdown().await;
        std::fs::remove_dir_all(directory).expect("cleanup");
    }

    /// A debug run stops in the rule on a breakpoint line, and a breakpoint
    /// on a line without a rule is reported rather than silently ignored.
    #[tokio::test]
    async fn a_debug_run_stops_at_a_breakpoint_line() {
        let directory = std::env::temp_dir().join(format!("studio-debug-{}", std::process::id()));
        std::fs::create_dir_all(&directory).expect("temporary directory");
        let file = directory.join("chain.slog");
        let lane = Lane::new(project_root().expect("repository root"), Mode::Debug);
        let studio = Studio::new(
            file.clone(),
            "table (edge int int)\ntable (path int int)\nrule (edge 1 2) (edge 2 3)\n\
             rule (edge X Y) --> (path X Y)\nrule (path X Y) (edge Y Z) --> (path X Z)\n"
                .to_owned(),
            lane,
        );
        let mut events = studio.subscribe();
        studio.set_breakpoints(vec![5, 2]);
        studio.debug().await;
        let outcomes = outcomes(&mut events);
        let missing = outcomes.iter().find(|o| o.line.ends_with(":2")).expect("break at line 2");
        assert!(missing.error.as_ref().is_some_and(|e| e.message.contains("no rule at chain.slog:2")));
        let stop = outcomes.last().and_then(|o| o.result.clone()).expect("the re-run answered");
        assert_eq!(stop["title"], "Paused · break b1");
        assert!(stop["lines"].to_string().contains("chain.slog:5:1"));
        studio.lane.shutdown().await;
        std::fs::remove_dir_all(directory).expect("cleanup");
    }

    fn outcomes(events: &mut tokio::sync::broadcast::Receiver<Event>) -> Vec<Outcome> {
        std::iter::from_fn(|| events.try_recv().ok())
            .filter_map(|event| match event {
                Event::Entry {
                    origin: Origin::Evaluate,
                    outcome,
                } => Some(outcome),
                _ => None,
            })
            .collect()
    }

    /// The (name, rows) pairs of the `tables` that ended an evaluation.
    fn relations(events: &mut tokio::sync::broadcast::Receiver<Event>) -> Vec<(String, u64)> {
        let tables = outcomes(events)
            .into_iter()
            .filter(|outcome| outcome.line == "tables")
            .last()
            .and_then(|outcome| outcome.result)
            .expect("the evaluation listed its relations");
        tables["relations"]
            .as_array()
            .expect("relations")
            .iter()
            .map(|relation| {
                (
                    relation["name"].as_str().unwrap().to_owned(),
                    relation["rows"].as_u64().unwrap(),
                )
            })
            .collect()
    }
}
