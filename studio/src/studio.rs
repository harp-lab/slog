//! One program file, the lane that evaluates it, and the events every open
//! browser tab observes.
//!
//! The server owns the text. A tab edits by sending the whole text with the
//! version it edited; an edit to a superseded version is refused and answered
//! with the current text, so two tabs cannot silently overwrite each other.
//!
//! Evaluation runs the saved file in a fresh session: the program is the whole
//! file, evaluated from nothing. Re-running into an old session would instead
//! layer the new program over the old one (audit M-01, M-07).

use crate::lane::{Lane, LaneStatus};
use serde::Serialize;
use serde_json::Value;
use slog_repl::protocol::{Response, ServerError};
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
}

#[derive(Clone, Debug, Serialize)]
#[serde(tag = "t", rename_all = "kebab-case")]
pub enum Event {
    /// The text changed; `origin` is the connection that changed it.
    Text { version: u64, text: String, origin: u64 },
    Saved { version: u64 },
    Lane(LaneStatus),
    Session(SessionView),
    /// A line of the session server's stderr.
    Log { line: String },
    /// One command and its outcome.
    Entry(Entry),
    Evaluation { phase: Phase, ok: bool, ms: u64 },
}

#[derive(Clone, Copy, Debug, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Phase {
    Start,
    Done,
}

#[derive(Clone, Debug, Serialize)]
pub struct Entry {
    pub origin: Origin,
    pub line: String,
    pub ms: u64,
    pub result: Option<Value>,
    pub error: Option<ServerError>,
}

#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Origin {
    /// Typed at the REPL prompt.
    Repl,
    /// Issued by Studio to evaluate the program.
    Evaluate,
}

/// What the session server is doing, as far as its answers have told us.
#[derive(Clone, Debug, Default, Eq, PartialEq, Serialize)]
pub struct SessionView {
    /// The current database (`scratch` for an evaluated program), if any.
    pub current: Option<String>,
    /// A run is paused at a gate, break, step, or interrupt, waiting for
    /// continue, commit, or abort.
    pub held: bool,
}

struct Doc {
    text: String,
    version: u64,
    saved_version: u64,
}

struct Session {
    /// The lane generation this view describes; a new server has no session.
    generation: u64,
    view: SessionView,
}

pub struct Studio {
    file: PathBuf,
    doc: std::sync::Mutex<Doc>,
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
            session: Mutex::new(Session {
                generation: lane.generation(),
                view: SessionView::default(),
            }),
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
        let session = self.session.lock().await.view.clone();
        let doc = self.doc.lock().expect("doc lock");
        Snapshot {
            file: self.file.display().to_string(),
            text: doc.text.clone(),
            version: doc.version,
            saved: doc.saved_version == doc.version,
            lane: self.lane.status().borrow().clone(),
            session,
        }
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
        self.execute(&mut session, Origin::Repl, line).await;
    }

    /// Save, then evaluate the file from nothing: resolve any held run,
    /// discard the current session, run the program, and list its relations.
    pub async fn evaluate(&self) {
        let started = Instant::now();
        let mut session = self.session.lock().await;
        self.publish(Event::Evaluation {
            phase: Phase::Start,
            ok: false,
            ms: 0,
        });
        let ok = self.evaluate_in(&mut session).await;
        self.publish(Event::Evaluation {
            phase: Phase::Done,
            ok,
            ms: started.elapsed().as_millis() as u64,
        });
    }

    async fn evaluate_in(&self, session: &mut Session) -> bool {
        if let Err(message) = self.save() {
            self.report(Origin::Evaluate, "save", "save", message);
            return false;
        }
        let Some(path) = run_argument(&self.file) else {
            self.report(
                Origin::Evaluate,
                "run",
                "path",
                format!(
                    "`run` cannot name {}: its path has whitespace or quotes",
                    self.file.display()
                ),
            );
            return false;
        };
        self.refresh(session);
        // `discard` refuses while a run is held, and quitting would commit it.
        if session.view.held && self.execute(session, Origin::Evaluate, "abort").await.is_none()
        {
            return false;
        }
        if session.view.current.is_some()
            && self
                .execute(session, Origin::Evaluate, "discard session")
                .await
                .is_none()
        {
            return false;
        }
        let run = format!("run {path}");
        self.execute(session, Origin::Evaluate, &run).await.is_some()
            && self
                .execute(session, Origin::Evaluate, "tables")
                .await
                .is_some()
    }

    /// Send `line`, publish the entry, and follow the session state the
    /// answer reports. Returns the result of a successful command.
    async fn execute(&self, session: &mut Session, origin: Origin, line: &str) -> Option<Value> {
        let started = Instant::now();
        let outcome = self.lane.command(line).await;
        self.refresh(session);
        let ms = started.elapsed().as_millis() as u64;
        let (result, error) = match outcome {
            Ok(Response {
                ok: true, result, ..
            }) => (Some(result.unwrap_or(Value::Null)), None),
            Ok(Response { error, .. }) => (
                None,
                Some(error.unwrap_or_else(|| server_error("server", "unknown server failure"))),
            ),
            Err(message) => (None, Some(server_error("lane", &message))),
        };
        if let Some(result) = &result {
            // Failures carry no session state; only successes move it.
            let view = SessionView {
                current: result
                    .get("current")
                    .and_then(Value::as_str)
                    .map(str::to_owned),
                held: result.get("kind").and_then(Value::as_str) == Some("paused"),
            };
            self.set_session(session, view);
        }
        self.publish(Event::Entry(Entry {
            origin,
            line: line.to_owned(),
            ms,
            result: result.clone(),
            error,
        }));
        result
    }

    /// A server that restarted has no session and nothing held.
    fn refresh(&self, session: &mut Session) {
        let generation = self.lane.generation();
        if session.generation != generation {
            session.generation = generation;
            self.set_session(session, SessionView::default());
        }
    }

    fn set_session(&self, session: &mut Session, view: SessionView) {
        if session.view != view {
            session.view = view.clone();
            self.publish(Event::Session(view));
        }
    }

    fn report(&self, origin: Origin, line: &str, kind: &str, message: String) {
        self.publish(Event::Entry(Entry {
            origin,
            line: line.to_owned(),
            ms: 0,
            result: None,
            error: Some(server_error(kind, &message)),
        }));
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
fn run_argument(file: &std::path::Path) -> Option<&str> {
    file.to_str()
        .filter(|path| !path.contains(|c: char| c.is_whitespace() || c == '"' || c == '\''))
}

#[cfg(test)]
mod tests {
    use super::{Event, Origin, Studio};
    use crate::lane::Lane;
    use slog_repl::server::project_root;
    use std::path::PathBuf;

    fn studio(file: PathBuf, text: &str) -> Studio {
        let lane = Lane::new(
            project_root().expect("repository root"),
            vec![("SLOG_OPT", "interp")],
        );
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
        let first = relations(&mut events);
        assert_eq!(first, vec![("edge".to_owned(), 2)]);

        studio
            .edit(0, 0, "table (node int)\nrule (node 7)\n".to_owned())
            .expect("edit");
        studio.evaluate().await;
        assert_eq!(relations(&mut events), vec![("node".to_owned(), 1)]);

        studio
            .edit(0, 1, "table (node int)\nrule (node 7))\n".to_owned())
            .expect("edit");
        studio.evaluate().await;
        let span = entries(&mut events)
            .into_iter()
            .find_map(|entry| entry.error.and_then(|error| error.span))
            .expect("a positioned syntax error");
        assert_eq!((span.file.as_str(), span.line, span.col), (file.to_str().unwrap(), 2, 14));

        studio.lane.shutdown().await;
        std::fs::remove_dir_all(directory).expect("cleanup");
    }

    fn entries(events: &mut tokio::sync::broadcast::Receiver<Event>) -> Vec<super::Entry> {
        std::iter::from_fn(|| events.try_recv().ok())
            .filter_map(|event| match event {
                Event::Entry(entry) => Some(entry),
                _ => None,
            })
            .collect()
    }

    /// The (name, rows) pairs of the `tables` that ended an evaluation.
    fn relations(events: &mut tokio::sync::broadcast::Receiver<Event>) -> Vec<(String, u64)> {
        let tables = entries(events)
            .into_iter()
            .filter(|entry| entry.origin == Origin::Evaluate && entry.line == "tables")
            .last()
            .and_then(|entry| entry.result)
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
