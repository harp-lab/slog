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
use crate::results::{
    self, Lineage, MAX_REQUEST_ROWS, Opening, Plan, Refinement, Results, Row, SORT_ROWS, SetId, Total,
};
use crate::review::{Review, ReviewView};
use crate::scenario::{self, Report};
use crate::breakpoints::Breakpoint;
use crate::session::{Outcome, Session, SessionView};
use crate::states::{Stamp, States};
use crate::summary::{self, Summarizer};
use crate::lint::{self, Linter};
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
    /// File -> its breakpoints.
    pub breakpoints: BTreeMap<String, Vec<Breakpoint>>,
    pub review: ReviewView,
    /// Why the agent cannot run here, if it cannot.
    pub agent_unavailable: Option<String>,
    /// `None` until a summarizer is attached.
    pub summary: Option<summary::View>,
    /// `None` when the analysis does not run here.
    pub lint: Option<lint::View>,
    pub results: Vec<results::View>,
    /// Plain Runs record their trace.
    pub tracing: bool,
    pub states: States,
    /// The session's last unfiltered `tables` answer, for the prompt's
    /// completion to start from.
    pub tables: Option<serde_json::Value>,
    /// The latest run's progress, as far as it has got (trace.rs).
    pub progress: Option<serde_json::Value>,
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
    /// The breakpoints of `file` changed.
    Breakpoints {
        file: String,
        points: Vec<Breakpoint>,
    },
    /// What the session says of each breakpoint: whether it can stop, its
    /// hits.
    BreakpointStatus {
        statuses: Vec<crate::breakpoints::Status>,
    },
    /// A new version, and the branches as they now stand.
    Version {
        version: Version,
        #[serde(flatten)]
        refs: Refs,
    },
    Lane(LaneStatus),
    Session(SessionView),
    /// The session's states changed: one was made, explored, or asked at.
    States(States),
    /// Whether plain Runs record their trace.
    Tracing {
        on: bool,
    },
    /// A line of the session server's stderr, or a problem keeping files.
    Log {
        line: String,
    },
    /// One command and its outcome; a `?` query's names the result set
    /// its rows opened.
    Entry {
        origin: Origin,
        #[serde(skip_serializing_if = "Option::is_none")]
        set: Option<SetId>,
        /// The session state it ran at, or made (states.rs).
        state: Stamp,
        /// It ran at a past state, explored read-only.
        #[serde(skip_serializing_if = "std::ops::Not::not")]
        exploring: bool,
        #[serde(flatten)]
        outcome: Outcome,
    },
    /// A result set opened, or what is known about it changed.
    ResultSet(results::View),
    /// The database queries see may have changed: what was read of it
    /// before `epoch` is stale.
    Database { epoch: u64 },
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
    /// The analysis of the working files moved on (lint.rs).
    Lint(lint::View),
    /// The run in flight got further: its strata from `from` on, and the
    /// one running (trace.rs).
    Progress(serde_json::Value),
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
    /// The edit was made in a tab of another project: this Studio's
    /// files are not the ones it was made to.
    OtherProject { project: String },
}

const SCENARIO_SUFFIX: &str = ".scenario.toml";

/// The project store's record of the agent threads (`review::Record`).
const THREADS: &str = "threads";

/// The project store's record of the result sets (`results::Record`).
const RESULTS: &str = "results";

struct Doc {
    text: String,
    version: u64,
    saved: bool,
}

/// The open project and the working state of its files.
struct Open {
    project: Project,
    docs: BTreeMap<String, Doc>,
    breakpoints: BTreeMap<String, Vec<Breakpoint>>,
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
    results: std::sync::Mutex<Results>,
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
    /// The agent's debug lane, breakpoints and traces (trace.rs).
    pub(crate) debugger: crate::trace::Debugger,
    /// The author asked plain Runs to record their trace too; Debug always
    /// does.
    tracing: std::sync::atomic::AtomicBool,
    /// The breaks armed for the editor's breakpoints (breakpoints.rs).
    pub(crate) armed: std::sync::Mutex<crate::breakpoints::Armed>,
    /// The latest run's progress, relayed as it runs (trace.rs).
    pub(crate) progress: std::sync::Mutex<crate::trace::Progress>,
    /// Rows read for peeks, by query, while the database stands (peek.rs).
    pub(crate) peeks: std::sync::Mutex<crate::peek::Peeks>,
    /// The port this studio serves on, which agent runs connect back to.
    port: OnceLock<u16>,
    /// Summarizes each saved text in the background, once attached.
    summary: OnceLock<Arc<Summarizer>>,
    /// The session's states, and the lane exploring a past one (states.rs).
    pub(crate) states: std::sync::Mutex<States>,
    pub(crate) pasts: Mutex<crate::states::Pasts>,
    /// The result sets' record as last kept, so it is written on change.
    kept_sets: std::sync::Mutex<String>,
    /// The session's last unfiltered `tables` answer.
    tables: std::sync::Mutex<Option<serde_json::Value>>,
    /// The static check, apart from every lane (check.rs).
    pub(crate) checker: crate::check::Checker,
    /// Each pending op's acceptance, with the key of what it was checked
    /// against (ask.rs).
    pub(crate) acceptances: std::sync::Mutex<std::collections::HashMap<u32, (u64, crate::review::Acceptance)>>,
    /// Signalled when the review or the program changes, so acceptances are
    /// checked again.
    pub(crate) review_changed: Arc<Notify>,
    /// Each thread's last evaluate_proposal: the hash of the program it
    /// evaluated, and whether that succeeded.
    pub(crate) evaluated: std::sync::Mutex<std::collections::HashMap<u32, (u64, bool)>>,
    /// Analyzes the working files on every edit, once attached (lint.rs).
    linter: OnceLock<Arc<Linter>>,
    /// Set when this project is the analysis itself.
    analysis: OnceLock<Arc<lint::Analysis>>,
}

impl Studio {
    /// `project`, one of `projects`, with `files` as its working files.
    /// `mcp_token` admits agent runs to `/mcp`.
    pub fn new(projects: Projects, project: Project, files: Files, lane: Lane, mcp_token: String) -> Self {
        let preview = Lane::new(lane.root().to_path_buf(), Mode::Fast);
        let checker = crate::check::Checker::new(lane.root().to_path_buf());
        let review = match project.store().read(THREADS) {
            Ok(record) => record.map(Review::restore).unwrap_or_default(),
            Err(error) => {
                eprintln!("slog-studio: cannot read the agent threads of {}: {error}", project.name());
                Review::default()
            }
        };
        let mut open = Open::new(project, files, 0);
        match open.project.store().read(crate::breakpoints::RECORD) {
            Ok(record) => open.breakpoints = record.unwrap_or_default(),
            Err(error) => eprintln!("slog-studio: cannot read the breakpoints: {error}"),
        }
        // The states and their result sets outlive the studio; the session
        // does not (states.rs).
        let states = match open.project.store().read::<States>(crate::states::RECORD) {
            Ok(record) => record.map(States::reopened).unwrap_or_default(),
            Err(error) => {
                eprintln!("slog-studio: cannot read the session's states: {error}");
                States::default()
            }
        };
        let results = match open.project.store().read(RESULTS) {
            Ok(record) => record.map(Results::restore).unwrap_or_default(),
            Err(error) => {
                eprintln!("slog-studio: cannot read the result sets: {error}");
                Results::default()
            }
        };
        let docs: Vec<String> = open.docs.keys().cloned().collect();
        open.breakpoints.retain(|path, _| docs.contains(path));
        Self {
            projects,
            open: std::sync::Mutex::new(open),
            armed: Default::default(),
            progress: Default::default(),
            session: Mutex::new(Session::new(&lane)),
            lane,
            events: broadcast::channel(1024).0,
            edited: Arc::new(Notify::new()),
            agent: Agent::new(mcp_token),
            review: std::sync::Mutex::new(review),
            preview_session: Mutex::new((Session::new(&preview), None)),
            debugger: crate::trace::Debugger::new(preview.root()),
            tracing: std::sync::atomic::AtomicBool::new(false),
            preview,
            port: OnceLock::new(),
            results: std::sync::Mutex::new(results),
            peeks: Default::default(),
            summary: OnceLock::new(),
            states: std::sync::Mutex::new(states),
            pasts: Default::default(),
            kept_sets: Default::default(),
            tables: Default::default(),
            checker,
            acceptances: Default::default(),
            review_changed: Arc::new(Notify::new()),
            evaluated: Default::default(),
            linter: OnceLock::new(),
            analysis: OnceLock::new(),
        }
    }

    /// Keep `result` if it is an unfiltered `tables` answer; `None` forgets
    /// the last, its session gone.
    fn keep_tables(&self, result: Option<&serde_json::Value>) {
        let mut tables = self.tables.lock().expect("tables lock");
        match result {
            None => *tables = None,
            Some(r) if r["kind"] == "tables" && r["relations-filter"].as_str().unwrap_or("").is_empty() => {
                *tables = Some(r.clone())
            }
            Some(_) => {}
        }
    }

    /// Analyze the working files from now on, and now.
    pub fn attach_linter(&self, linter: Arc<Linter>) {
        let _ = self.linter.set(linter);
        self.lint(&self.open());
    }

    /// Stop the analysis's lane and reifier, for the server's exit.
    pub async fn stop_linter(&self) {
        if let Some(linter) = self.linter.get() {
            linter.shutdown().await;
        }
    }

    /// This project is the analysis (`analysis/`): its edits go to every
    /// program's linter.
    pub fn attach_analysis(&self, analysis: Arc<lint::Analysis>) {
        let _ = self.analysis.set(analysis);
    }

    /// Why the analysis made `finding`: its derivation's nodes.
    pub async fn lint_why(&self, finding: &lint::Finding) -> Result<Vec<serde_json::Value>, String> {
        self.linter.get().ok_or("the analysis is not running")?.why(finding).await
    }

    /// Write this program's facts for the analysis to run on, and name the
    /// project of the analysis itself, linked to `analysis/`.
    pub async fn analysis_project(&self) -> Result<String, String> {
        let linter = self.linter.get().ok_or("the analysis is not running")?;
        linter.write_facts().await?;
        let main = linter.analysis_dir().join("slog-lint.slog");
        self.projects
            .linked(&main)
            .map_err(|error| format!("cannot open a project for {}: {error}", main.display()))
    }

    /// Whether plain Runs record their trace, from the next Run on.
    pub fn set_tracing(&self, on: bool) {
        self.tracing.store(on, std::sync::atomic::Ordering::Relaxed);
        self.publish(Event::Tracing { on });
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

    /// Where the project's files are written and evaluated.
    pub(crate) fn directory(&self) -> PathBuf {
        self.open().project.directory()
    }

    /// The main file: its path, absolute, and its working text.
    pub(crate) fn main_file(&self) -> (PathBuf, String) {
        let open = self.open();
        let main = open.project.main();
        (open.project.directory().join(main), open.docs[main].text.clone())
    }

    /// The project's directory, its main file's path in it, and every
    /// file's working text by path.
    pub(crate) fn working_files(&self) -> (PathBuf, String, BTreeMap<String, String>) {
        let open = self.open();
        (open.project.directory().to_path_buf(), open.project.main().to_owned(), open.files())
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
        crate::trace::relay_progress(self);
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
        let review = self.review_view();
        let open = self.open();
        Snapshot {
            review,
            agent_unavailable: Agent::unavailable(),
            summary: self.summary.get().map(|summarizer| summarizer.view()),
            lint: self.linter.get().map(|linter| linter.view()),
            project: open.project.name().to_owned(),
            projects,
            main: open.project.main().to_owned(),
            directory: open.project.directory().display().to_string(),
            files: open.views(),
            lane: self.lane.status().borrow().clone(),
            session,
            breakpoints: open.breakpoints.clone(),
            results: self.results().views(),
            tracing: self.tracing.load(std::sync::atomic::Ordering::Relaxed),
            states: self.states.lock().expect("states lock").clone(),
            tables: self.tables.lock().expect("tables lock").clone(),
            progress: self.progress.lock().expect("progress lock").whole(),
        }
    }

    /// The project's directory and its breakpoints, as they stand.
    pub(crate) fn open_breakpoints(&self) -> (PathBuf, BTreeMap<String, Vec<Breakpoint>>) {
        let open = self.open();
        (open.project.directory().to_path_buf(), open.breakpoints.clone())
    }

    /// Make `points` the breakpoints of `file` and keep them with the
    /// project; false when the project has no such file.
    pub(crate) fn keep_breakpoints(&self, file: &str, points: &[Breakpoint]) -> bool {
        let mut open = self.open();
        if !open.docs.contains_key(file) {
            return false;
        }
        open.breakpoints.insert(file.to_owned(), points.to_vec());
        open.breakpoints.retain(|_, list| !list.is_empty());
        if let Err(error) = open.project.store().write(crate::breakpoints::RECORD, &open.breakpoints) {
            drop(open);
            self.trouble(&format!("cannot keep the breakpoints: {error}"));
        }
        true
    }

    pub(crate) async fn session_lock(&self) -> tokio::sync::MutexGuard<'_, Session> {
        self.session.lock().await
    }

    /// Replace the text of `file` at version `base` in `project`, a tab's
    /// edit: refused unless `project` is this Studio's. A version names a
    /// text only within one Studio, so a tab that has wandered to another
    /// project (a reconnect, a default that moved) must not have its text
    /// taken for this one's file of the same name.
    pub fn edit_in(&self, project: &str, origin: u64, file: &str, base: u64, text: String) -> Result<u64, Refused> {
        let own = self.open().project.name().to_owned();
        if project != own {
            return Err(Refused::OtherProject { project: own });
        }
        self.edit(origin, file, base, text)
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
        self.review_changed.notify_one();
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

    /// The program version the working files were last saved as, and the
    /// main file's and the project's names: what a Run evaluates
    /// (states.rs).
    pub(crate) fn program(&self) -> (Option<u64>, String, String) {
        let open = self.open();
        (
            open.project.history.head().map(|version| version.id),
            open.project.main().to_owned(),
            open.project.name().to_owned(),
        )
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
        self.run(line, None).await;
    }

    /// Run a REPL line. A `?` or `?exists` query's answers open a result
    /// set, refining `lineage`'s set when given.
    pub async fn run(&self, line: &str, lineage: Option<Lineage>) {
        // A refinement of a set reads where the set was read: at its state
        // (states.rs).
        let current = self.states().current;
        let past = lineage.as_ref().and_then(|lineage| self.results().past(lineage.parent, current));
        if let Some(at) = past {
            return self.run_past(line, lineage, at).await;
        }
        // A past state being explored answers the prompt.
        if self.explore_command(line).await {
            return;
        }
        self.run_main(line, lineage).await;
    }

    /// Run a REPL line on the main lane, at the current state.
    pub(crate) async fn run_main(&self, line: &str, lineage: Option<Lineage>) {
        let mut session = self.session.lock().await;
        let before = session.view().clone();
        let started = Instant::now();
        let outcome = session.execute(&self.lane, line).await;
        self.observe(Origin::Repl, &before, &outcome);
        let touched = {
            let mut results = self.results();
            // Any command may have discarded the cursor (audit Q-10).
            let mut touched: Vec<SetId> = results.park().into_iter().collect();
            if changes_database(&before, &outcome) {
                touched = results.changed();
            }
            if let Some(result) = &outcome.result {
                results.learn(result);
                self.keep_tables(Some(result));
            }
            touched
        };
        if changes_database(&before, &outcome) {
            self.publish_database();
        }
        self.publish_sets(touched);
        let query = outcome.result.as_ref().and_then(|result| result["query-mode"].as_str());
        let (mut shown, set) = match (query, results::rows_line(line)) {
            // A held stop's answers stay in the transcript: keeping them as a
            // relation would define one in the middle of the held run.
            (Some("rows" | "exists"), Some(read)) if !session.view().held => {
                let state = self.stamp();
                self.open_set(&mut session, &self.lane, line, &read, &outcome, lineage, state, true).await
            }
            _ => (outcome, None),
        };
        shown.ms = started.elapsed().as_millis() as u64;
        self.publish_sets(set);
        self.publish_outcome(Origin::Repl, &before, &shown, set);
        // A step or continue moves the hit counts the margin shows.
        if self.armed.lock().expect("armed lock").debugging {
            self.publish_status(&mut session).await;
        }
    }

    /// Open the set a query's answers make. They are kept as the relation
    /// the set is named for and read back from it; if they cannot be kept,
    /// the set reads the query itself, and says why. `read` is the query's
    /// rows form and `answered` its answer as typed. Returns the entry to
    /// show for the query, and the set.
    /// `session` is on `lane`, at `state`; `main` when that is the main
    /// lane, the only one whose answers are kept as a relation.
    #[allow(clippy::too_many_arguments)]
    pub(crate) async fn open_set(
        &self,
        session: &mut Session,
        lane: &Lane,
        line: &str,
        read: &str,
        answered: &Outcome,
        lineage: Option<Lineage>,
        state: Stamp,
        main: bool,
    ) -> (Outcome, Option<SetId>) {
        let rows = answered.result.as_ref().is_some_and(|result| result["query-mode"] == "rows");
        // A rows page's title names the projection. An existence answer has
        // none: ask for the rows, which a query without variables also
        // answers with an existence.
        let page = if rows {
            answered.result.clone()
        } else {
            match session.execute(lane, read).await.result {
                Some(result) => Some(result).filter(|result| result["query-mode"] == "rows"),
                None => return (answered.clone(), None),
            }
        };
        let keep = if main {
            self.results().keep(read, page.as_ref())
        } else {
            Err(String::new())
        };
        let (read, kept) = match keep {
            Ok(keep) => match session.execute(lane, &keep.definition).await.error {
                None => (keep.read, Ok(keep.kept)),
                Some(error) => (read.to_owned(), Err(error.message)),
            },
            Err(why) => (read.to_owned(), Err(why)),
        };
        // Counted before the cursor opens: once it does, any other command
        // would discard it (audit Q-10).
        let total = match results::count_line(&read) {
            Some(count) => {
                let counted = session.execute(lane, &count).await;
                match (&counted.result, counted.error) {
                    (Some(result), _) => {
                        Total::of_count(result).ok_or_else(|| "the count's answer was unreadable".to_owned())
                    }
                    (None, error) => Err(error.map_or_else(String::new, |error| error.message)),
                }
            }
            None => Ok(Total::Unknown),
        };
        let outcome = session.execute(lane, &read).await;
        let opened = match &outcome.result {
            Some(result) => {
                let opening = Opening {
                    query: line.to_owned(),
                    read,
                    kept,
                    parent: lineage,
                    state: Some(state),
                };
                let mut results = self.results();
                let opened = if main { results.open(opening, result) } else { results.open_past(opening, result) };
                if let Ok(Some(id)) = opened {
                    results.counted(id, total);
                }
                opened
            }
            None => Ok(None),
        };
        let set = opened.unwrap_or_else(|why| {
            self.publish(Event::Log {
                line: format!("Studio could not read the query's rows: {why}"),
            });
            None
        });
        // A rows query shows the rows it opened; an existence answer stays
        // the answer, with its set beside it.
        let shown = if rows && set.is_some() {
            Outcome {
                line: line.to_owned(),
                ..outcome
            }
        } else {
            answered.clone()
        };
        (shown, set)
    }

    /// The query a gesture on a result set runs, and its lineage.
    pub fn refinement(&self, id: SetId, refinement: &Refinement) -> Result<(String, Lineage), String> {
        self.results().refine(id, refinement)
    }

    /// Rows `start..end` (0-based) of a result set: from its cache, or read
    /// from its query on the main lane, running the query again when
    /// another set holds the cursor or the rows lie behind it.
    pub async fn rows(&self, id: SetId, start: u64, end: u64) -> Result<Vec<Row>, String> {
        let end = end.min(start.saturating_add(MAX_REQUEST_ROWS));
        // Cached rows are served even while a long command holds the lane.
        if let Plan::Serve(rows) = self.results().plan(id, start, end) {
            return Ok(rows);
        }
        // A set of another state than the session's reads at that state.
        let current = self.states().current;
        let past = self.results().past(id, current);
        if let Some(at) = past {
            return self.rows_past(id, start, end, at).await;
        }
        let mut session = self.session.lock().await;
        let mut cursor_lost = false;
        let served = loop {
            let plan = self.results().plan(id, start, end);
            let line = match plan {
                Plan::Serve(rows) => break Ok(rows),
                Plan::Fail(why) => break Err(why),
                Plan::More => "more".to_owned(),
                Plan::Rerun(query) => {
                    let parked = {
                        let mut results = self.results();
                        let note = format!("running the query again to reach row {}", start + 1);
                        results.set_loading(id, Some(note));
                        results.park()
                    };
                    self.publish_sets(parked.into_iter().chain([id]));
                    query
                }
            };
            let before = session.view().clone();
            let outcome = session.execute(&self.lane, &line).await;
            if outcome.session != before {
                self.publish(Event::Session(outcome.session.clone()));
            }
            let absorbed = match &outcome.result {
                Some(result) => self.results().absorb(id, result),
                None => Err(outcome.error.map_or_else(String::new, |error| error.message)),
            };
            match absorbed {
                Ok(()) => {}
                // The cursor went some way this studio did not see: run
                // the query again, once.
                Err(_) if line == "more" && !cursor_lost => {
                    cursor_lost = true;
                    self.results().park();
                }
                Err(why) => break Err(why),
            }
        };
        self.results().set_loading(id, None);
        self.publish_sets([id]);
        served
    }

    /// Open a set of `id`'s rows sorted by `column`. Queries have no order,
    /// so Studio reads every row, up to `SORT_ROWS`, and sorts them; the
    /// transcript shows the sort as an entry naming the new set.
    pub async fn sort(&self, id: SetId, column: usize, descending: bool) -> Result<(), String> {
        let started = Instant::now();
        let lineage = self.results().sorting(id, column, descending)?;
        let mut rows: Vec<Row> = Vec::new();
        let read = loop {
            let start = rows.len() as u64;
            self.results().set_loading(id, Some(format!("reading rows to sort: {start} so far")));
            self.publish_sets([id]);
            match self.rows(id, start, start + MAX_REQUEST_ROWS).await {
                Ok(window) if window.is_empty() => break Ok(()),
                Ok(window) => rows.extend(window),
                Err(why) => break Err(why),
            }
            if rows.len() > SORT_ROWS {
                break Err(format!("{id} has more than {SORT_ROWS} rows, too many to sort here"));
            }
        };
        self.results().set_loading(id, None);
        self.publish_sets([id]);
        read?;
        let line = format!("sort {id} by {}", lineage.refinement.trim_start_matches("sort by "));
        let n = rows.len();
        let sorted = self.results().sorted(lineage, column, descending, rows)?;
        self.publish_sets([sorted]);
        // Shown as a query's entry is: a link to its set, with its rows.
        let result = serde_json::json!({"kind": "query", "query-mode": "rows",
            "query-status": "complete", "query-shown": n, "lines": []});
        let session = self.session.lock().await.view().clone();
        let outcome = Outcome {
            line,
            ms: started.elapsed().as_millis() as u64,
            result: Some(result),
            error: None,
            session: session.clone(),
        };
        self.publish_outcome(Origin::Repl, &session, &outcome, Some(sorted));
        Ok(())
    }

    /// Kill the main lane's server; its session and cursor go with it.
    pub fn restart(&self) {
        self.lane.kill();
        self.keep_tables(None);
        let touched = self.results().changed();
        self.publish_database();
        self.publish_sets(touched);
    }

    /// Run the server in `mode` from now on; it restarts.
    pub fn set_mode(&self, mode: Mode) {
        self.lane.set_mode(mode);
        self.keep_tables(None);
        let touched = self.results().changed();
        self.publish_database();
        self.publish_sets(touched);
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
        // Debug always has debug semantics: compiled strata have no ports,
        // so a breakpoint there would be silently passed.  (Fast mode runs
        // the interpreter, where breaks stop; only single-port stepping is
        // exact on one thread.)
        if debug && self.lane.status().borrow().mode == Mode::Compiled {
            self.set_mode(Mode::Debug);
            self.trouble("Debug switched to debug mode: compiled strata cannot stop at a breakpoint");
        }
        let mut session = self.session.lock().await;
        self.publish(Event::Evaluation {
            phase: Phase::Start,
            ok: false,
            ms: 0,
        });
        let touched = {
            let mut results = self.results();
            results.forget_catalog();
            self.keep_tables(None);
            results.changed()
        };
        self.publish_database();
        self.publish_sets(touched);
        // A program that fails the static check is refused at once, at its
        // error, without starting or discarding a session.
        let checked = self.check_program(&BTreeMap::new(), None).await;
        let ok = match self.save(if debug { "debug" } else { "run" }) {
            Err(message) => {
                let failure = session.failure("save", "save", &message);
                self.publish_outcome(Origin::Evaluate, session.view(), &failure, None);
                false
            }
            // (an error naming no file is the checker's own trouble: no reason
            // to refuse)
            Ok(_) if checked.errors().any(|error| !error.file.is_empty()) => {
                let error = checked.errors().find(|error| !error.file.is_empty()).expect("just found");
                let mut failure = session.failure("check", "check", &format!("does not check: {}", error.message));
                if let Some(server) = failure.error.as_mut() {
                    server.span = Some(slog_repl::protocol::Span { file: error.file.clone(), line: error.line, col: error.col });
                }
                self.publish_outcome(Origin::Evaluate, session.view(), &failure, None);
                false
            }
            Ok((version, text)) => {
                let main = {
                    let open = self.open();
                    open.project.directory().join(open.project.main())
                };
                // A debug run records its demand calls and arms a break per
                // breakpoint (breakpoints.rs).
                let breaks = if debug { self.break_lines() } else { Vec::new() };
                let mut prepare: Vec<String> = if debug {
                    std::iter::once("calls on".to_owned())
                        .chain(breaks.iter().map(|(_, line)| line.clone()))
                        .collect()
                } else {
                    Vec::new()
                };
                // A traced run records its execution trace, and so does
                // every change after it in this session (trace.rs).
                let wanted = debug || self.tracing.load(std::sync::atomic::Ordering::Relaxed);
                prepare.extend(crate::trace::arm(self.lane.status().borrow().mode, wanted));
                let mut shown = session.view().clone();
                let mut tables = None;
                let mut outcomes = Vec::new();
                let ok = session
                    .evaluate(&self.lane, &main, &prepare, &mut |outcome| {
                        if outcome.line.starts_with("break ") {
                            outcomes.push(outcome.clone());
                        }
                        self.observe(Origin::Evaluate, &shown, outcome);
                        self.publish_outcome(Origin::Evaluate, &shown, outcome, None);
                        shown = outcome.session.clone();
                        if let Some(result) = &outcome.result {
                            self.results().learn(result);
                        }
                        if outcome.line == "tables" {
                            tables = outcome.result.clone();
                        }
                    })
                    .await;
                if debug {
                    self.note_armed(&breaks, &outcomes);
                    self.publish_status(&mut session).await;
                } else {
                    *self.armed.lock().expect("armed lock") = Default::default();
                }
                // A held run's relations are partial: not the program's.
                let complete = tables.as_ref().filter(|_| !session.view().held);
                self.keep_tables(complete);
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

    /// The saved databases `open` can name, for the prompt to offer: read
    /// from disk, so asking puts no command on the lane.
    pub fn databases(&self) -> Vec<String> {
        databases(self.lane.root())
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
        self.lint(&open);
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
        self.lint(open);
    }

    /// Analyze the working files (lint.rs); this project being the analysis
    /// itself, analyze every program again with it as it now stands.
    fn lint(&self, open: &Open) {
        if let Some(linter) = self.linter.get() {
            linter.request(lint::Job {
                directory: open.project.directory(),
                main: open.project.main().to_owned(),
                files: open.files(),
            });
        }
        if let Some(analysis) = self.analysis.get() {
            analysis.edited(&open.files());
        }
    }

    /// Keep the agent threads, their transcripts and proposals in the
    /// project's store. The open project is locked first, as everywhere, so
    /// records are written in the order they were taken.
    pub(crate) fn keep_review(&self) {
        let open = self.open();
        let record = self.review.lock().expect("review lock").record();
        if let Err(error) = open.project.store().write(THREADS, &record) {
            drop(open);
            self.trouble(&format!("cannot keep the agent threads: {error}"));
        }
    }

    /// Write `record` to the project's store as `name`.
    pub(crate) fn store_write<T: Serialize>(&self, name: &str, record: &T) -> std::io::Result<()> {
        self.open().project.store().write(name, record)
    }

    pub(crate) fn trouble(&self, message: &str) {
        self.publish(Event::Log {
            line: format!("studio: {message}"),
        });
    }

    /// Publish an entry, and the session state when it moved past `before`.
    pub(crate) fn publish_outcome(&self, origin: Origin, before: &SessionView, outcome: &Outcome, set: Option<SetId>) {
        if outcome.session != *before {
            self.publish(Event::Session(outcome.session.clone()));
        }
        self.publish(Event::Entry {
            origin,
            set,
            state: self.stamp(),
            exploring: false,
            outcome: outcome.clone(),
        });
    }

    pub(crate) fn publish_sets(&self, ids: impl IntoIterator<Item = SetId>) {
        let (views, record): (Vec<results::View>, _) = {
            let results = self.results();
            (ids.into_iter().filter_map(|id| results.view(id)).collect(), results.record())
        };
        // kept for the next studio, when what is kept changed
        let text = serde_json::to_string(&record).unwrap_or_default();
        let changed = {
            let mut kept = self.kept_sets.lock().expect("kept sets lock");
            let changed = *kept != text;
            *kept = text;
            changed
        };
        if changed && let Err(error) = self.store_write(RESULTS, &record) {
            self.trouble(&format!("cannot keep the result sets: {error}"));
        }
        for view in views {
            self.publish(Event::ResultSet(view));
        }
    }

    // ---- The REPL assistant's reads (assist.rs) --------------------------

    /// The main lane's session, for reads that make no entry and open no
    /// result set: the REPL assistant's, and the prompt's live preview. The
    /// live set's cursor is parked first, since any command discards it
    /// (audit Q-10). None if another command holds the lane past `patience`.
    pub(crate) async fn aside(&self, patience: Duration) -> Option<tokio::sync::MutexGuard<'_, Session>> {
        let session = tokio::time::timeout(patience, self.session.lock()).await.ok()?;
        let parked = self.results().park();
        self.publish_sets(parked);
        Some(session)
    }

    pub(crate) fn result_views(&self) -> Vec<results::View> {
        self.results().views()
    }

    fn publish_database(&self) {
        let epoch = self.results().epoch();
        self.publish(Event::Database { epoch });
    }

    pub(crate) fn epoch(&self) -> u64 {
        self.results().epoch()
    }

    pub(crate) fn results(&self) -> std::sync::MutexGuard<'_, Results> {
        self.results.lock().expect("results lock")
    }
}

/// Whether a command may have changed what queries on its lane see: every
/// semantic verb reports a `change`, and a switched, discarded or held
/// session shows in the session view.
fn changes_database(before: &SessionView, outcome: &Outcome) -> bool {
    outcome.session != *before || outcome.result.as_ref().is_some_and(|result| result.get("change").is_some())
}

/// The directories under `root/data`, by name: the databases the REPL
/// knows (compiler/dbtool.rkt `all-db-names`), but for the analysis's
/// facts (lint.rs).
fn databases(root: &std::path::Path) -> Vec<String> {
    let mut names: Vec<String> = std::fs::read_dir(root.join("data"))
        .into_iter()
        .flatten()
        .filter_map(|entry| {
            let entry = entry.ok()?;
            entry.file_type().ok()?.is_dir().then_some(())?;
            entry.file_name().into_string().ok()
        })
        .filter(|name| !name.starts_with(lint::DATABASE_PREFIX))
        .collect();
    names.sort();
    names
}

#[cfg(test)]
pub(crate) mod tests {
    use super::{databases, Event, Made, Origin, Refused, Studio};
    use crate::review::{Change, Message};
    use serde_json::{Value, json};
    use crate::lane::{Lane, Mode};
    use crate::projects::Projects;
    use crate::session::Outcome;
    use crate::store::tests::Scratch;
    use slog_repl::server::project_root;

    /// A studio on a new project in `scratch` whose main file holds `text`.
    pub(crate) fn studio(scratch: &Scratch, mode: Mode, text: &str) -> Studio {
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
    fn the_databases_are_the_directories_under_data() {
        let root = std::env::temp_dir().join(format!("slog-studio-databases-{}", std::process::id()));
        std::fs::create_dir_all(root.join("data/reach")).unwrap();
        std::fs::create_dir_all(root.join("data/kcfa")).unwrap();
        std::fs::write(root.join("data/notes.txt"), "").unwrap();
        assert_eq!(databases(&root), ["kcfa", "reach"]);
        std::fs::remove_dir_all(&root).unwrap();
        assert!(databases(&root).is_empty());
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

    /// Two projects, each with a main.slog at the same version: a tab's
    /// edit is taken only by its own project's Studio, so saving one never
    /// writes the other's text.
    #[test]
    fn an_edit_for_another_project_is_refused() {
        let scratch = Scratch::new("two-projects");
        let open = |name: &str| {
            let projects = Projects::new(scratch.path());
            projects.create(name).expect("project");
            let (project, files) = projects.open(name).expect("open");
            let lane = Lane::new(project_root().expect("repository root"), Mode::Fast);
            Studio::new(projects, project, files, lane, "test".to_owned())
        };
        let (one, two) = (open("one"), open("two"));
        let v = one.snapshot_version("main.slog");
        assert_eq!(v, two.snapshot_version("main.slog"));
        assert_eq!(one.edit_in("one", 1, "main.slog", v, "rule (one)\n".into()), Ok(v + 1));
        assert_eq!(two.edit_in("two", 2, "main.slog", v, "rule (two)\n".into()), Ok(v + 1));
        assert_eq!(
            two.edit_in("one", 1, "main.slog", v + 1, "rule (one)\n".into()),
            Err(Refused::OtherProject { project: "two".into() })
        );
        one.save("save").expect("save one");
        two.save("save").expect("save two");
        let text = |name: &str| {
            std::fs::read_to_string(scratch.path().join(format!("projects/{name}/files/main.slog"))).unwrap()
        };
        assert_eq!((text("one"), text("two")), ("rule (one)\n".to_owned(), "rule (two)\n".to_owned()));
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
    #[tokio::test]
    async fn an_accepted_proposal_is_a_version() {
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
        studio.accept(&[op]).await.unwrap();

        let head = studio.history().versions.last().cloned().unwrap();
        assert_eq!((head.origin, head.label.as_deref()), (Made::Accept, Some("add a fact")));
        assert_eq!(head.forms_changed, ["main.slog:rule→t"]);
        assert_eq!(studio.main_file().1, "table (t int)\nrule (t 1) (t 2)\n");
        assert_eq!(studio.open().files()["lib.slog"], "", "other files are kept");
        assert!(studio.accept(&[op]).await.is_err());
        assert_eq!(studio.history().versions.len(), versions + 1);
    }

    /// The agent threads outlive the studio: a studio opened on the project
    /// again has each thread's transcript, notes and claude session (so a
    /// follow-up resumes it), and its proposals, with new ids after theirs.
    #[test]
    fn agent_threads_survive_a_restart() {
        let scratch = Scratch::new("threads");
        let text = "table (t int)\nrule (t 1)\n";
        let (thread, op) = {
            let studio = studio(&scratch, Mode::Fast, text);
            let ids = {
                let mut review = studio.review.lock().unwrap();
                let thread = review.new_thread("facts".to_owned());
                review.open_changeset(thread, "add a fact".to_owned());
                let change = Change::Append { source: "rule (t 2)".to_owned() };
                (thread, review.propose(text, thread, change, "a second fact".to_owned()).unwrap())
            };
            studio.thread_push(ids.0, Message::new("user", "add a fact", Value::Null));
            studio.thread_update(ids.0, 0, |message| message.data = json!({ "kept": true }));
            studio.record_note(ids.0, "why".to_owned(), "two facts".to_owned()).unwrap();
            studio.set_thread_session(ids.0, Some("session-1".to_owned()));
            studio.review.lock().unwrap().thread_mut(ids.0).unwrap().running = true;
            studio.publish_review();
            ids
        };

        let projects = Projects::new(scratch.path());
        let (project, files) = projects.open("p").unwrap();
        let lane = Lane::new(project_root().unwrap(), Mode::Fast);
        let studio = Studio::new(projects, project, files, lane, "test".to_owned());
        assert_eq!(studio.thread_session(thread).as_deref(), Some("session-1"));
        let view = studio.review.lock().unwrap().view(text);
        let kept = &view.threads[0];
        assert_eq!((kept.title.as_str(), kept.running), ("facts", false));
        assert_eq!(kept.messages[0].text, "add a fact");
        assert_eq!(kept.messages[0].data, json!({ "kept": true }));
        assert_eq!(kept.notes[0].text, "two facts");
        assert_eq!(view.ops[0].op.id, op);
        assert_eq!(view.ops[0].op.change, Change::Append { source: "rule (t 2)".to_owned() });

        let mut review = studio.review.lock().unwrap();
        let next = review.new_thread("more".to_owned());
        review.open_changeset(next, "more".to_owned());
        assert_eq!(next, thread + 1);
        let change = Change::Append { source: "rule (t 3)".to_owned() };
        assert_eq!(review.propose(text, next, change, String::new()).unwrap(), op + 1);
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
        let point = |id: &str, line| crate::breakpoints::Breakpoint {
            id: id.to_owned(),
            line,
            at: None,
            clause: None,
            condition: String::new(),
            ignore: 0,
            log: false,
            enabled: true,
        };
        studio.set_breakpoints("main.slog".to_owned(), vec![point("p1", 5), point("p2", 2)]);
        studio.debug().await;
        let outcomes = outcomes(&mut events);
        let run = outcomes
            .iter()
            .find(|o| o.line.starts_with("run "))
            .and_then(|o| o.result.clone())
            .expect("the run answered");
        // b1 is the rule on line 5; b2 is line 2's waiting break
        assert_eq!(run["title"], "Paused · break b1");
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
                    ..
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
