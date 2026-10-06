//! The open project, the lane that evaluates it, and the events every open
//! browser tab observes.
//!
//! The server owns the text of each file. A tab edits a file by sending its
//! whole text with the version it edited; an edit to a superseded version is
//! refused and answered with the current text, so two tabs cannot silently
//! overwrite each other. Edits are kept as the branch's draft at once, and
//! become versions when editing pauses, on save and evaluation, and on
//! restore and branch (`versions.rs`).

use crate::agent::{Agent, AgentEvent};
use crate::lane::{Lane, LaneStatus, Mode};
use crate::projects::{Project, Projects, valid_file};
use crate::review::{Review, ReviewView};
use crate::scenario::{self, Report};
use crate::session::{Outcome, Session, SessionView, run_argument};
use crate::summary::{self, Summarizer};
use crate::store::Files;
use crate::versions::{Origin as Made, Refs, Version};
use serde::Serialize;
use std::collections::BTreeMap;
use std::path::PathBuf;
use std::sync::{Arc, OnceLock};
use std::time::{Duration, Instant};
use tokio::sync::{Mutex, Notify, broadcast};

/// How long editing pauses before the edits become an Auto version.
const PAUSE: Duration = Duration::from_secs(2);

/// Everything a tab needs to render the studio from scratch.
#[derive(Clone, Debug, Serialize)]
pub struct Snapshot {
    pub project: String,
    pub projects: Vec<String>,
    pub main: String,
    /// Where the files are written and evaluated: the files that error
    /// spans name are in it.
    pub directory: String,
    pub files: Vec<FileView>,
    pub lane: LaneStatus,
    pub session: SessionView,
    /// File -> 1-based lines carrying breakpoints.
    pub breakpoints: BTreeMap<String, Vec<u32>>,
    pub review: ReviewView,
    /// Why the agent cannot run here, if it cannot.
    pub agent_unavailable: Option<String>,
    /// `None` until a summarizer is attached.
    pub summary: Option<summary::View>,
}

#[derive(Clone, Debug, Serialize)]
pub struct FileView {
    pub path: String,
    pub text: String,
    pub version: u64,
    /// The text is what was last written to the project's directory.
    pub saved: bool,
}

/// The version DAG, for the history view.
#[derive(Clone, Debug, Serialize)]
pub struct HistoryView {
    pub main: String,
    #[serde(flatten)]
    pub refs: Refs,
    pub versions: Vec<Version>,
}

#[derive(Clone, Debug, Serialize)]
#[serde(tag = "t", rename_all = "kebab-case")]
pub enum Event {
    /// A file's text changed; `origin` is the connection that changed it.
    Text {
        file: String,
        version: u64,
        text: String,
        origin: u64,
    },
    /// The set of files, their texts, or the main file changed as a whole:
    /// a file was added, renamed or deleted, or a version was restored.
    Files {
        main: String,
        files: Vec<FileView>,
    },
    /// These files, at these versions, were written to disk.
    Saved {
        files: BTreeMap<String, u64>,
    },
    /// The lines of `file` carrying breakpoints changed.
    Breakpoints {
        file: String,
        lines: Vec<u32>,
    },
    /// A new version, and the branches as they now stand.
    Version {
        version: Version,
        #[serde(flatten)]
        refs: Refs,
    },
    Lane(LaneStatus),
    Session(SessionView),
    /// A line of the session server's stderr, or a problem keeping files.
    Log {
        line: String,
    },
    /// One command and its outcome.
    Entry {
        origin: Origin,
        #[serde(flatten)]
        outcome: Outcome,
    },
    Evaluation { phase: Phase, ok: bool, ms: u64 },
    /// Progress of an agent turn.
    Agent(AgentEvent),
    /// Threads, changesets or proposals changed.
    Review(ReviewView),
    /// A scenario beside the program started, or finished with a report or
    /// an error that kept it from running.
    Scenario {
        name: String,
        running: bool,
        report: Option<Report>,
        error: Option<String>,
    },
    /// The program summary and analyzer findings changed.
    Summary(summary::View),
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

/// Why an edit was not taken.
#[derive(Debug, Eq, PartialEq)]
pub enum Refused {
    /// The edit was made to a superseded version: this is the current one.
    Stale {
        version: u64,
        text: String,
    },
    NoFile,
}

const SCENARIO_SUFFIX: &str = ".scenario.toml";

struct Doc {
    text: String,
    version: u64,
    saved: bool,
}

/// The open project and the working state of its files.
struct Open {
    project: Project,
    docs: BTreeMap<String, Doc>,
    breakpoints: BTreeMap<String, Vec<u32>>,
    /// Above every version any file has had, across projects: a file that
    /// comes into being starts here, so a version never names two texts
    /// of one path.
    clock: u64,
}

impl Open {
    fn new(project: Project, files: Files, clock: u64) -> Self {
        let mut open = Self {
            project,
            docs: BTreeMap::new(),
            breakpoints: BTreeMap::new(),
            clock,
        };
        // Unreadable, the saved files compare unequal: shown as unsaved.
        let saved = open.project.saved().unwrap_or_default();
        open.adopt(files);
        for (path, doc) in &mut open.docs {
            doc.saved = saved.get(path) == Some(&doc.text);
        }
        open
    }

    fn files(&self) -> Files {
        self.docs
            .iter()
            .map(|(path, doc)| (path.clone(), doc.text.clone()))
            .collect()
    }

    fn tick(&mut self) -> u64 {
        self.clock += 1;
        self.clock
    }

    /// Make `files` the working files: changed files move to a new version,
    /// unchanged ones keep theirs, and files that are gone are dropped. The
    /// main file stays, empty if `files` lacks it (a version from before it
    /// was named).
    fn adopt(&mut self, mut files: Files) {
        files.entry(self.project.main().to_owned()).or_default();
        let mut docs = BTreeMap::new();
        for (path, text) in files {
            let doc = match self.docs.remove(&path) {
                Some(doc) if doc.text == text => doc,
                Some(doc) => Doc {
                    text,
                    version: doc.version.max(self.clock) + 1,
                    saved: false,
                },
                None => Doc {
                    text,
                    version: self.clock + 1,
                    saved: false,
                },
            };
            self.clock = self.clock.max(doc.version);
            docs.insert(path, doc);
        }
        self.docs = docs;
        self.breakpoints
            .retain(|path, _| self.docs.contains_key(path));
    }

    fn views(&self) -> Vec<FileView> {
        self.docs
            .iter()
            .map(|(path, doc)| FileView {
                path: path.clone(),
                text: doc.text.clone(),
                version: doc.version,
                saved: doc.saved,
            })
            .collect()
    }

    /// A `break FILE:LINE` for each breakpoint. A file `run` cannot name
    /// gets none; evaluation reports such a main file.
    fn breaks(&self) -> Vec<String> {
        let directory = self.project.directory();
        let mut breaks = Vec::new();
        for (path, lines) in &self.breakpoints {
            let file = directory.join(path);
            if let Some(file) = run_argument(&file) {
                breaks.extend(lines.iter().map(|line| format!("break {file}:{line}")));
            }
        }
        breaks
    }

    fn files_event(&self) -> Event {
        Event::Files {
            main: self.project.main().to_owned(),
            files: self.views(),
        }
    }

    fn version_event(&self, version: Version) -> Event {
        Event::Version {
            version,
            refs: self.project.history.refs().clone(),
        }
    }
}

pub struct Studio {
    /// The user's projects, of which this is one.
    projects: Projects,
    open: std::sync::Mutex<Open>,
    pub lane: Lane,
    /// Held across each command, and across a whole evaluation, so commands
    /// from different tabs never interleave within one.
    session: Mutex<Session>,
    events: broadcast::Sender<Event>,
    /// Signalled on every change to the working files; `watch_edits` makes
    /// an Auto version once they pause.
    edited: Arc<Notify>,
    pub agent: Agent,
    pub(crate) review: std::sync::Mutex<Review>,
    /// Evaluates agents' proposed programs, apart from the author's session.
    pub(crate) preview: Lane,
    /// The preview lane's session, and the (thread, text hash) of the
    /// proposed program it holds, so a query runs against what it names.
    pub(crate) preview_session: Mutex<(Session, Option<(u32, u64)>)>,
    /// The port this studio serves on, which agent runs connect back to.
    port: OnceLock<u16>,
    /// Summarizes each saved text in the background, once attached.
    summary: OnceLock<Arc<Summarizer>>,
}

impl Studio {
    /// `project`, one of `projects`, with `files` as its working files.
    /// `mcp_token` admits agent runs to `/mcp`.
    pub fn new(projects: Projects, project: Project, files: Files, lane: Lane, mcp_token: String) -> Self {
        let preview = Lane::new(lane.root().to_path_buf(), Mode::Fast);
        Self {
            projects,
            open: std::sync::Mutex::new(Open::new(project, files, 0)),
            session: Mutex::new(Session::new(&lane)),
            lane,
            events: broadcast::channel(1024).0,
            edited: Arc::new(Notify::new()),
            agent: Agent::new(mcp_token),
            review: std::sync::Mutex::new(Review::default()),
            preview_session: Mutex::new((Session::new(&preview), None)),
            preview,
            port: OnceLock::new(),
            summary: OnceLock::new(),
        }
    }

    /// Record the port once the listener is bound.
    pub fn set_port(&self, port: u16) {
        let _ = self.port.set(port);
    }

    pub fn port(&self) -> u16 {
        *self.port.get().expect("the port is set before agents run")
    }

    /// Summarize the program from now on: on every save, and after every
    /// evaluation with its relation counts.
    pub fn attach_summarizer(&self, summarizer: Arc<Summarizer>) {
        let _ = self.summary.set(summarizer);
    }

    /// Ask for a summary of `text`, the main file saved as `version`;
    /// `tables` is the complete `tables` result when that text was just
    /// evaluated.
    pub fn summarize(&self, version: u64, text: String, tables: Option<&serde_json::Value>) {
        if let Some(summarizer) = self.summary.get() {
            summarizer.request(version, text, tables.and_then(summary::relations));
        }
    }

    /// The main file: its path, absolute, and its working text.
    pub(crate) fn main_file(&self) -> (PathBuf, String) {
        let open = self.open();
        let main = open.project.main();
        (open.project.directory().join(main), open.docs[main].text.clone())
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

    /// Settle the working files into an Auto version each time editing
    /// pauses, for as long as the studio lives.
    pub fn watch_edits(self: &Arc<Self>) {
        let edited = self.edited.clone();
        let studio = Arc::downgrade(self);
        tokio::spawn(async move {
            loop {
                edited.notified().await;
                while tokio::time::timeout(PAUSE, edited.notified()).await.is_ok() {}
                let Some(studio) = studio.upgrade() else { return };
                studio.settle();
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
        let projects = self.projects.names().unwrap_or_default();
        let open = self.open();
        let main = &open.docs[open.project.main()].text;
        Snapshot {
            review: self.review.lock().expect("review lock").view(main),
            agent_unavailable: Agent::unavailable(),
            summary: self.summary.get().map(|summarizer| summarizer.view()),
            project: open.project.name().to_owned(),
            projects,
            main: open.project.main().to_owned(),
            directory: open.project.directory().display().to_string(),
            files: open.views(),
            lane: self.lane.status().borrow().clone(),
            session,
            breakpoints: open.breakpoints.clone(),
        }
    }

    /// Replace the breakpoint lines of `file`; the editor tracks them as
    /// text moves.
    pub fn set_breakpoints(&self, file: String, mut lines: Vec<u32>) {
        lines.sort_unstable();
        lines.dedup();
        let mut open = self.open();
        if !open.docs.contains_key(&file) {
            return;
        }
        open.breakpoints.insert(file.clone(), lines.clone());
        drop(open);
        self.publish(Event::Breakpoints { file, lines });
    }

    /// Replace the text of `file` at version `base`. Returns the new version.
    pub fn edit(&self, origin: u64, file: &str, base: u64, text: String) -> Result<u64, Refused> {
        let mut open = self.open();
        let Some(doc) = open.docs.get_mut(file) else {
            return Err(Refused::NoFile);
        };
        if base != doc.version {
            return Err(Refused::Stale {
                version: doc.version,
                text: doc.text.clone(),
            });
        }
        doc.version += 1;
        doc.text = text.clone();
        doc.saved = false;
        let version = doc.version;
        open.clock = open.clock.max(version);
        self.keep_draft(&open);
        drop(open);
        self.publish(Event::Text {
            file: file.to_owned(),
            version,
            text,
            origin,
        });
        Ok(version)
    }

    /// Write the files to the project's directory, and checkpoint them with
    /// `label` (save, run, debug).
    /// Returns the version and text the main file now holds.
    pub fn save(&self, label: &str) -> Result<(u64, String), String> {
        let mut open = self.open();
        let files = open.files();
        let version = open.project.save(&files, label).map_err(|error| {
            format!(
                "cannot save {}: {error}",
                open.project.directory().display()
            )
        })?;
        let mut saved = BTreeMap::new();
        for (path, doc) in &mut open.docs {
            doc.saved = true;
            saved.insert(path.clone(), doc.version);
        }
        let version = version.map(|version| open.version_event(version));
        let main = &open.docs[open.project.main()];
        let main = (main.version, main.text.clone());
        drop(open);
        self.publish(Event::Saved { files: saved });
        if let Some(event) = version {
            self.publish(event);
        }
        Ok(main)
    }

    /// Make an Auto version of the working files if a form changed since
    /// the head.
    pub fn settle(&self) {
        let mut open = self.open();
        let files = open.files();
        match open.project.history.settle(&files) {
            Ok(Some(version)) => {
                let event = open.version_event(version);
                drop(open);
                self.publish(event);
            }
            Ok(None) => {}
            Err(error) => {
                drop(open);
                self.trouble(&format!("cannot record a version: {error}"));
            }
        }
    }

    /// Change the working files by `change`, which is given them and the
    /// main file's path, and record the result as a version on the current
    /// branch, after its head; every tab is shown the new files. Nothing
    /// changes if `change` fails.
    ///
    /// This is how anything outside the editor changes the program, such as
    /// accepting an agent's proposal (`Origin::Accept`, labelled with what
    /// was asked). The working files cannot move under `change`.
    pub fn record_version(
        &self,
        origin: Made,
        label: Option<String>,
        change: impl FnOnce(&mut Files, &str) -> Result<(), String>,
    ) -> Result<Version, String> {
        let mut open = self.open();
        let mut files = open.files();
        change(&mut files, open.project.main())?;
        let version = open
            .project
            .history
            .record(origin, &files, label)
            .map_err(|error| format!("cannot record a version: {error}"))?;
        self.adopt(open, files, version.clone());
        Ok(version)
    }

    /// Restore version `id` as a new version on the current branch.
    pub fn restore(&self, id: u64) -> Result<(), String> {
        let mut open = self.open();
        let (version, files) = open
            .project
            .history
            .revert(id)
            .map_err(|error| format!("cannot restore version {id}: {error}"))?;
        self.adopt(open, files, version);
        Ok(())
    }

    /// Start a branch at version `id` and continue on it.
    pub fn branch(&self, id: u64) -> Result<(), String> {
        let mut open = self.open();
        let (version, files) = open
            .project
            .history
            .branch(id)
            .map_err(|error| format!("cannot branch from version {id}: {error}"))?;
        self.adopt(open, files, version);
        Ok(())
    }

    pub fn history(&self) -> HistoryView {
        let open = self.open();
        HistoryView {
            main: open.project.main().to_owned(),
            refs: open.project.history.refs().clone(),
            versions: open.project.history.versions().to_vec(),
        }
    }

    /// The files of version `id`, to look at.
    pub fn version_files(&self, id: u64) -> Result<Files, String> {
        self.open()
            .project
            .history
            .files(id)
            .map_err(|error| format!("cannot read version {id}: {error}"))
    }

    /// Add an empty file.
    pub fn new_file(&self, path: &str) -> Result<(), String> {
        self.change_files(|open| {
            if !valid_file(path) {
                return Err(format!(
                    "{path:?} is not a file name: use letters, digits, - _ . and end in .slog"
                ));
            }
            if open.docs.contains_key(path) {
                return Err(format!("{path} exists"));
            }
            let mut files = open.files();
            files.insert(path.to_owned(), String::new());
            open.adopt(files);
            Ok(())
        })
    }

    pub fn rename_file(&self, from: &str, to: &str) -> Result<(), String> {
        self.change_files(|open| {
            if !valid_file(to) {
                return Err(format!(
                    "{to:?} is not a file name: use letters, digits, - _ . and end in .slog"
                ));
            }
            if open.docs.contains_key(to) {
                return Err(format!("{to} exists"));
            }
            let Some(doc) = open.docs.remove(from) else {
                return Err(format!("no file {from}"));
            };
            if open.project.main() == from {
                open.project
                    .set_main(to)
                    .map_err(|error| format!("cannot make {to} the main file: {error}"))?;
            }
            let version = open.tick();
            open.docs.insert(
                to.to_owned(),
                Doc {
                    text: doc.text,
                    version,
                    saved: false,
                },
            );
            if let Some(lines) = open.breakpoints.remove(from) {
                open.breakpoints.insert(to.to_owned(), lines);
            }
            Ok(())
        })
    }

    pub fn delete_file(&self, path: &str) -> Result<(), String> {
        self.change_files(|open| {
            if open.project.main() == path {
                return Err(format!(
                    "{path} is the main file; make another file main first"
                ));
            }
            open.docs
                .remove(path)
                .ok_or_else(|| format!("no file {path}"))?;
            open.breakpoints.remove(path);
            Ok(())
        })
    }

    /// Make `path` the file Run and Debug evaluate.
    pub fn set_main(&self, path: &str) -> Result<(), String> {
        self.change_files(|open| {
            if !open.docs.contains_key(path) {
                return Err(format!("no file {path}"));
            }
            open.project
                .set_main(path)
                .map_err(|error| format!("cannot make {path} the main file: {error}"))
        })
    }

    /// Run one line typed at the REPL prompt.
    pub async fn command(&self, line: &str) {
        let mut session = self.session.lock().await;
        let before = session.view().clone();
        let outcome = session.execute(&self.lane, line).await;
        self.publish_outcome(Origin::Repl, &before, &outcome);
    }

    /// Save, then evaluate the main file from nothing in a fresh session.
    pub async fn evaluate(&self) {
        self.evaluate_with(false).await;
    }

    /// Evaluate with a break armed at each breakpoint line first, so the
    /// run stops in the first marked rule it reaches.
    pub async fn debug(&self) {
        self.evaluate_with(true).await;
    }

    async fn evaluate_with(&self, debug: bool) {
        let started = Instant::now();
        let mut session = self.session.lock().await;
        self.publish(Event::Evaluation {
            phase: Phase::Start,
            ok: false,
            ms: 0,
        });
        let ok = match self.save(if debug { "debug" } else { "run" }) {
            Err(message) => {
                let failure = session.failure("save", "save", &message);
                self.publish_outcome(Origin::Evaluate, session.view(), &failure);
                false
            }
            Ok((version, text)) => {
                let (main, prepare) = {
                    let open = self.open();
                    let main = open.project.directory().join(open.project.main());
                    (main, if debug { open.breaks() } else { Vec::new() })
                };
                let mut shown = session.view().clone();
                let mut tables = None;
                let ok = session
                    .evaluate(&self.lane, &main, &prepare, &mut |outcome| {
                        self.publish_outcome(Origin::Evaluate, &shown, outcome);
                        shown = outcome.session.clone();
                        if outcome.line == "tables" {
                            tables = outcome.result.clone();
                        }
                    })
                    .await;
                // A held run's relations are partial: not the program's.
                let complete = tables.as_ref().filter(|_| !session.view().held);
                self.summarize(version, text, complete);
                ok
            }
        };
        self.publish(Event::Evaluation {
            phase: Phase::Done,
            ok,
            ms: started.elapsed().as_millis() as u64,
        });
    }

    /// The scenario files beside the program: `*.scenario.toml` in the
    /// project's directory, by name.
    pub fn scenarios(&self) -> Vec<String> {
        let directory = self.open().project.directory();
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
        // Only a file directly in the project's directory: the name is not
        // a path.
        if !name.ends_with(SCENARIO_SUFFIX) || name.contains('/') {
            return publish(false, None, Some(format!("no scenario named {name}")));
        }
        let path = self.open().project.directory().join(name);
        publish(true, None, None);
        match scenario::run(self.lane.root(), &path).await {
            Ok(report) => publish(false, Some(report), None),
            Err(error) => publish(false, None, Some(error)),
        }
    }

    fn open(&self) -> std::sync::MutexGuard<'_, Open> {
        self.open.lock().expect("open project lock")
    }

    /// Apply `change` to the working files and show every tab the result.
    fn change_files(
        &self,
        change: impl FnOnce(&mut Open) -> Result<(), String>,
    ) -> Result<(), String> {
        let mut open = self.open();
        change(&mut open)?;
        self.keep_draft(&open);
        let event = open.files_event();
        drop(open);
        self.publish(event);
        Ok(())
    }

    /// Show every tab `files`, which `version` just recorded.
    fn adopt(&self, mut open: std::sync::MutexGuard<'_, Open>, files: Files, version: Version) {
        open.adopt(files);
        // The draft is the new version's files; nothing is left to settle.
        if let Err(error) = open.project.history.save_draft(&open.files()) {
            self.trouble(&format!("cannot keep the draft: {error}"));
        }
        let events = [open.files_event(), open.version_event(version)];
        drop(open);
        for event in events {
            self.publish(event);
        }
    }

    /// Keep the working files as the branch's draft, and note the edit for
    /// `watch_edits`.
    fn keep_draft(&self, open: &Open) {
        if let Err(error) = open.project.history.save_draft(&open.files()) {
            self.trouble(&format!("cannot keep the draft: {error}"));
        }
        self.edited.notify_one();
    }

    fn trouble(&self, message: &str) {
        self.publish(Event::Log {
            line: format!("studio: {message}"),
        });
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
    use super::{Event, Made, Origin, Refused, Studio};
    use crate::review::Change;
    use crate::lane::{Lane, Mode};
    use crate::projects::Projects;
    use crate::session::Outcome;
    use crate::store::tests::Scratch;
    use slog_repl::server::project_root;

    /// A studio on a new project in `scratch` whose main file holds `text`.
    fn studio(scratch: &Scratch, mode: Mode, text: &str) -> Studio {
        let projects = Projects::new(scratch.path());
        projects.create("p").expect("project");
        let (project, files) = projects.open("p").expect("open");
        let lane = Lane::new(project_root().expect("repository root"), mode);
        let studio = Studio::new(projects, project, files, lane, "test".to_owned());
        let base = studio.snapshot_version("main.slog");
        studio
            .edit(0, "main.slog", base, text.to_owned())
            .expect("edit");
        studio
    }

    impl Studio {
        fn snapshot_version(&self, file: &str) -> u64 {
            self.open().docs[file].version
        }
    }

    #[test]
    fn an_edit_to_a_superseded_version_is_refused_with_the_current_text() {
        let scratch = Scratch::new("stale");
        let studio = studio(&scratch, Mode::Fast, "a");
        let v = studio.snapshot_version("main.slog");
        assert_eq!(studio.edit(1, "main.slog", v, "ab".to_owned()), Ok(v + 1));
        assert_eq!(
            studio.edit(2, "main.slog", v, "ax".to_owned()),
            Err(Refused::Stale {
                version: v + 1,
                text: "ab".to_owned()
            })
        );
        assert_eq!(
            studio.edit(2, "main.slog", v + 1, "abc".to_owned()),
            Ok(v + 2)
        );
        assert_eq!(
            studio.edit(2, "other.slog", 0, "x".to_owned()),
            Err(Refused::NoFile)
        );
    }

    /// A file that goes and comes back starts above every version it had,
    /// so an edit made to its old text is refused.
    #[test]
    fn a_recreated_file_never_reuses_a_version() {
        let scratch = Scratch::new("recreate");
        let studio = studio(&scratch, Mode::Fast, "table (t int)\n");
        studio.new_file("lib.slog").unwrap();
        let old = studio.snapshot_version("lib.slog");
        studio
            .edit(0, "lib.slog", old, "rule (t 1)\n".to_owned())
            .unwrap();
        studio.delete_file("lib.slog").unwrap();
        studio.new_file("lib.slog").unwrap();
        assert!(studio.snapshot_version("lib.slog") > old + 1);
        assert!(matches!(
            studio.edit(0, "lib.slog", old + 1, "x".to_owned()),
            Err(Refused::Stale { .. })
        ));
        assert!(
            studio.delete_file("main.slog").is_err(),
            "the main file stays"
        );
    }

    /// Restoring an old version shows its files in every tab, as a new
    /// version on the branch; an edit made before the restore is stale.
    #[test]
    fn restoring_a_version_replaces_the_working_files() {
        let scratch = Scratch::new("restore");
        let studio = studio(&scratch, Mode::Fast, "table (t int)\n");
        studio.save("save").unwrap();
        let saved = studio.history().versions.last().unwrap().id;
        let before = studio.snapshot_version("main.slog");
        studio
            .edit(0, "main.slog", before, "table (u int)\n".to_owned())
            .unwrap();
        studio.new_file("lib.slog").unwrap();
        let mut events = studio.subscribe();

        studio.restore(saved).unwrap();
        let files = studio.version_files(saved).unwrap();
        assert_eq!(studio.open().files(), files);
        assert!(matches!(
            studio.edit(0, "main.slog", before + 1, "x".to_owned()),
            Err(Refused::Stale { .. })
        ));
        let published: Vec<Event> = std::iter::from_fn(|| events.try_recv().ok()).collect();
        assert!(matches!(
            &published[..],
            [Event::Files { .. }, Event::Version { .. }]
        ));
    }

    /// Accepting a proposal changes the main file and records an Accept
    /// version labelled with what was asked; one that no longer applies
    /// changes nothing.
    #[test]
    fn an_accepted_proposal_is_a_version() {
        let scratch = Scratch::new("accept");
        let studio = studio(&scratch, Mode::Fast, "table (t int)\nrule (t 1)\n");
        studio.new_file("lib.slog").unwrap();
        studio.settle();
        let op = {
            let mut review = studio.review.lock().unwrap();
            let thread = review.new_thread("facts".to_owned());
            review.open_changeset(thread, "add a fact".to_owned());
            let change = Change::Edit { old: "rule (t 1)".to_owned(), new: "rule (t 1) (t 2)".to_owned() };
            review.propose("table (t int)\nrule (t 1)\n", thread, change, String::new()).unwrap()
        };
        let versions = studio.history().versions.len();
        studio.accept(op).unwrap();

        let head = studio.history().versions.last().cloned().unwrap();
        assert_eq!((head.origin, head.label.as_deref()), (Made::Accept, Some("add a fact")));
        assert_eq!(head.forms_changed, ["main.slog:rule→t"]);
        assert_eq!(studio.main_file().1, "table (t int)\nrule (t 1) (t 2)\n");
        assert_eq!(studio.open().files()["lib.slog"], "", "other files are kept");
        assert!(studio.accept(op).is_err());
        assert_eq!(studio.history().versions.len(), versions + 1);
    }

    /// Evaluation starts from nothing: re-evaluating an edited program shows
    /// only the new program's relations, and a syntax error comes back with
    /// its position in the file.
    #[tokio::test]
    async fn evaluation_runs_the_saved_program_in_a_fresh_session() {
        let scratch = Scratch::new("evaluate");
        let studio = studio(
            &scratch,
            Mode::Fast,
            "table (edge int int)\nrule (edge 1 2)\nrule (edge 2 3)\n",
        );
        let mut events = studio.subscribe();

        studio.evaluate().await;
        assert_eq!(relations(&mut events), vec![("edge".to_owned(), 2)]);

        let v = studio.snapshot_version("main.slog");
        studio
            .edit(
                0,
                "main.slog",
                v,
                "table (node int)\nrule (node 7)\n".to_owned(),
            )
            .expect("edit");
        studio.evaluate().await;
        assert_eq!(relations(&mut events), vec![("node".to_owned(), 1)]);

        studio
            .edit(
                0,
                "main.slog",
                v + 1,
                "table (node int)\nrule (node 7))\n".to_owned(),
            )
            .expect("edit");
        studio.evaluate().await;
        let span = outcomes(&mut events)
            .into_iter()
            .find_map(|outcome| outcome.error.and_then(|error| error.span))
            .expect("a positioned syntax error");
        let file = studio.open().project.directory().join("main.slog");
        assert_eq!(
            (span.file.as_str(), span.line, span.col),
            (file.to_str().unwrap(), 2, 14)
        );
        studio.lane.shutdown().await;
    }

    /// The main file includes another file of the project, which resolves
    /// among the project's files.
    #[tokio::test]
    async fn the_main_file_includes_the_projects_other_files() {
        let scratch = Scratch::new("include");
        let studio = studio(
            &scratch,
            Mode::Fast,
            "include \"edges.slog\"\nrule (edge X Y) --> (path X Y)\n",
        );
        studio.new_file("edges.slog").unwrap();
        let v = studio.snapshot_version("edges.slog");
        studio
            .edit(
                0,
                "edges.slog",
                v,
                "table (edge int int)\ntable (path int int)\nrule (edge 1 2) (edge 2 3)\n"
                    .to_owned(),
            )
            .unwrap();
        let mut events = studio.subscribe();
        studio.evaluate().await;
        assert_eq!(
            relations(&mut events),
            vec![("edge".to_owned(), 2), ("path".to_owned(), 2)]
        );
        studio.lane.shutdown().await;
    }

    /// A debug run arms its breaks before the program's first run and stops
    /// in the rule on a breakpoint line. A line without a rule cannot be
    /// told from a rule not yet run, so its break waits and never fires.
    #[tokio::test]
    async fn a_debug_run_stops_at_a_breakpoint_line() {
        let scratch = Scratch::new("debug");
        let studio = studio(
            &scratch,
            Mode::Debug,
            "table (edge int int)\ntable (path int int)\nrule (edge 1 2) (edge 2 3)\n\
             rule (edge X Y) --> (path X Y)\nrule (path X Y) (edge Y Z) --> (path X Z)\n",
        );
        let mut events = studio.subscribe();
        studio.set_breakpoints("main.slog".to_owned(), vec![5, 2]);
        studio.debug().await;
        let outcomes = outcomes(&mut events);
        let run = outcomes
            .iter()
            .find(|o| o.line.starts_with("run "))
            .and_then(|o| o.result.clone())
            .expect("the run answered");
        // b1 is line 2's waiting break; b2 is the rule on line 5
        assert_eq!(run["title"], "Paused · break b2");
        assert!(run["lines"].to_string().contains("main.slog:5:1"));
        assert!(outcomes.last().is_some_and(|o| o.session.held));
        studio.lane.shutdown().await;
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
