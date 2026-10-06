//! slog-lint in Studio: the static analysis of Slog written in Slog
//! (`analysis/`), run over the program being edited on a lane of its own,
//! so it never disturbs the author's session
//! (docs/REPL-exploration-kris/notes/slog-in-slog.md).
//!
//! A job is the project's working texts. `compiler/reify.rkt --serve`, one
//! long-lived process, reads them with the compiler's parser and writes
//! their facts as the database `data/<name>`; then the analysis lane opens
//! it and runs each tier of the analysis, each a program including the one
//! before, publishing its findings and the relations the editor shows as
//! soon as it finishes. Requests are debounced, and a new one interrupts
//! the job in flight, which stops between tiers.
//!
//! The analysis is read from the repository's `analysis/`, or, while a
//! project is editing that directory, from a copy of its working texts, so
//! an edit to the analysis shows at once in every program's findings.

use crate::forms;
use crate::lane::{Lane, Mode};
use crate::session::Session;
use crate::store::Files;
use serde::{Deserialize, Serialize};
use std::collections::BTreeMap;
use std::path::{Path, PathBuf};
use std::process::Stdio;
use std::sync::{Arc, Weak};
use std::time::{Duration, Instant};
use tokio::io::{AsyncBufReadExt, AsyncWriteExt, BufReader, Lines};
use tokio::process::{Child, ChildStdin, ChildStdout, Command};
use tokio::sync::{Mutex, Notify};
use tokio::time::timeout;

/// How long editing pauses before the analysis runs.
const DEBOUNCE: Duration = Duration::from_millis(400);
const REIFY_LIMIT: Duration = Duration::from_secs(60);

/// The tiers, quick to deep: each program adds its rules over the
/// relations of the ones before, and these relations to what the editor
/// is shown.
const TIERS: [(&str, &[(&str, &str)]); 3] = [
    (
        "lint-local.slog",
        &[
            ("finding", "?(finding S F L C K M)"),
            ("writer", "?(writer R F L)"),
            ("reader", "?(reader R F L S)"),
        ],
    ),
    (
        "lint-graph.slog",
        &[
            ("dep", "?(dep A B S)"),
            ("recursive", "?(recursive R)"),
            ("cycle_with", "?(cycle_with A B)"),
            ("inhabited", "?(inhabited R)"),
            ("never_fires", "?(never_fires F L)"),
        ],
    ),
    ("lint-deep.slog", &[("demand_calls", "?(demand_calls F G)")]),
];

/// Whether tier k+1 runs as a layer on tier k's session, computing only
/// its own rules. Without, each tier reopens the facts and runs every tier
/// up to it again, in a fresh session.
const LAYERED: bool = true;

/// The facts' databases are `data/slog-lint-...`, apart from the author's.
pub const DATABASE_PREFIX: &str = "slog-lint-";

/// The daemon's provenance budget on the analysis lane: a finding sits at
/// the end of a long chain of derivations, past the default 4096.
const PROOF_RECORDS: &str = "1000000";

/// What the linter has to say, for every tab.
#[derive(Clone, Debug, Default, Serialize)]
pub struct View {
    /// A job is waiting or running.
    pub working: bool,
    /// Tiers done for the newest job, of `tiers`.
    pub tier: usize,
    pub tiers: usize,
    pub findings: Vec<Finding>,
    /// Relation -> rows, for hover and the dependency graph. Files in them
    /// are project paths.
    pub facts: BTreeMap<String, Vec<Vec<String>>>,
    /// Reify and freeze, then each tier, in milliseconds.
    pub ms: Vec<u64>,
    pub error: Option<String>,
    /// The directory the analysis was read from.
    pub analysis: String,
}

#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
pub struct Finding {
    pub severity: String,
    /// The project path, or the absolute path of a file outside it.
    pub file: String,
    pub line: u32,
    pub col: u32,
    pub code: String,
    pub message: String,
    /// The tier that found it.
    #[serde(default)]
    pub tier: usize,
    /// The top-level form it is in, and the line that form starts on, so
    /// the editor can carry it onto a text where the form is unchanged.
    #[serde(default)]
    pub form_line: u32,
    #[serde(default)]
    pub form: String,
    /// From an earlier job, its tier not yet run again.
    #[serde(default)]
    pub stale: bool,
}

impl Finding {
    fn same(&self, other: &Finding) -> bool {
        (&self.file, self.line, self.col, &self.code, &self.message)
            == (&other.file, other.line, other.col, &other.code, &other.message)
    }
}

/// The project's working files, as one job.
#[derive(Clone, Debug)]
pub struct Job {
    pub directory: PathBuf,
    pub main: String,
    pub files: Files,
}

impl Job {
    fn absolute(&self, file: &str) -> PathBuf {
        self.directory.join(file)
    }

    /// `path` as the project names it, when it is one of its files.
    fn project_path(&self, path: &str) -> Option<String> {
        let path = Path::new(path);
        let canonical = |p: &Path| std::fs::canonicalize(p).unwrap_or_else(|_| p.to_path_buf());
        let dir = canonical(&self.directory);
        let relative = path
            .strip_prefix(&self.directory)
            .ok()
            .map(Path::to_path_buf)
            .or_else(|| canonical(path).strip_prefix(&dir).ok().map(Path::to_path_buf))?;
        Some(relative.to_string_lossy().into_owned())
    }
}

/// Where the analysis is read from: the repository's `analysis/`, or the
/// working texts of the project editing it, written to a scratch copy.
pub struct Analysis {
    dir: PathBuf,
    scratch: PathBuf,
    edited: std::sync::Mutex<bool>,
    linters: std::sync::Mutex<Vec<Weak<Linter>>>,
}

impl Analysis {
    pub fn new(root: &Path, data: &Path) -> Arc<Self> {
        Arc::new(Self {
            dir: root.join("analysis"),
            scratch: data.join("lint").join("analysis"),
            edited: std::sync::Mutex::new(false),
            linters: std::sync::Mutex::new(Vec::new()),
        })
    }

    /// The repository's copy, which "Edit the analysis" opens.
    pub fn dir(&self) -> &Path {
        &self.dir
    }

    fn current(&self) -> PathBuf {
        if *self.edited.lock().expect("analysis lock") {
            self.scratch.clone()
        } else {
            self.dir.clone()
        }
    }

    /// The analysis project's working texts changed: analyze every program
    /// again with them.
    pub fn edited(&self, files: &Files) {
        let written = files.iter().try_for_each(|(path, text)| {
            let file = self.scratch.join(path);
            if let Some(parent) = file.parent() {
                std::fs::create_dir_all(parent)?;
            }
            std::fs::write(file, text)
        });
        *self.edited.lock().expect("analysis lock") = written.is_ok();
        let linters: Vec<Arc<Linter>> = {
            let mut list = self.linters.lock().expect("analysis lock");
            list.retain(|linter| linter.strong_count() > 0);
            list.iter().filter_map(Weak::upgrade).collect()
        };
        for linter in linters {
            linter.rerun();
        }
    }

    fn register(&self, linter: &Arc<Linter>) {
        self.linters.lock().expect("analysis lock").push(Arc::downgrade(linter));
    }
}

pub struct Config {
    /// The repository the lane and the reifier run in.
    pub root: PathBuf,
    /// Holds the dumps of each tier's relations.
    pub home: PathBuf,
    /// The database the facts are written to, under the repository's data/.
    pub database: String,
    pub analysis: Arc<Analysis>,
}

struct Reifier {
    _child: Child,
    input: ChildStdin,
    output: Lines<BufReader<ChildStdout>>,
}

#[derive(Default)]
struct State {
    view: View,
    pending: Option<Job>,
    /// The newest job started, to run again when the analysis changes.
    last: Option<Job>,
    running: bool,
    /// The findings when the newest job started: shown, marked stale, for
    /// the tiers it has not reached.
    before: Vec<Finding>,
}

pub struct Linter {
    config: Config,
    lane: Lane,
    /// Held across a job's commands, and across a why.
    session: Mutex<Session>,
    reifier: Mutex<Option<Reifier>>,
    state: std::sync::Mutex<State>,
    wake: Notify,
    publish: Box<dyn Fn(View) + Send + Sync>,
}

impl Linter {
    /// Start the worker; `publish` sees every change to the view.
    pub fn start(config: Config, publish: impl Fn(View) + Send + Sync + 'static) -> Arc<Self> {
        // The interpreter, on one thread: a tier runs for a second, which
        // native code (fast mode's tiering) never pays back, its compiles
        // only taking the author's cores; and one thread keeps it clear of
        // the multi-threaded interpreter's heap corruption (1458a53).
        let env = vec![("SLOG_OPT", "interp"), ("SLOG_THREADS", "1"), ("SLOG_PROOF_RECORDS", PROOF_RECORDS)];
        let lane = Lane::with_env(config.root.clone(), Mode::Fast, env);
        let linter = Arc::new(Self {
            session: Mutex::new(Session::new(&lane)),
            lane,
            reifier: Mutex::new(None),
            state: std::sync::Mutex::new(State {
                view: View {
                    tiers: TIERS.len(),
                    ..View::default()
                },
                ..State::default()
            }),
            wake: Notify::new(),
            publish: Box::new(publish),
            config,
        });
        linter.config.analysis.register(&linter);
        tokio::spawn(linter.clone().work());
        linter
    }

    pub fn view(&self) -> View {
        self.state.lock().expect("lint lock").view.clone()
    }

    /// The repository's analysis, which "Edit the analysis" opens.
    pub fn analysis_dir(&self) -> &Path {
        self.config.analysis.dir()
    }

    /// Analyze `job` once editing pauses; a job in flight stops.
    pub fn request(self: &Arc<Self>, job: Job) {
        let mut state = self.state.lock().expect("lint lock");
        state.pending = Some(job);
        state.view.working = true;
        let running = state.running;
        let view = state.view.clone();
        drop(state);
        (self.publish)(view);
        self.wake.notify_one();
        if running {
            // the run's own answer then comes back paused, ending the job
            let linter = self.clone();
            tokio::spawn(async move { linter.lane.interrupt().await });
        }
    }

    /// Analyze the newest job again, as when the analysis changed.
    pub fn rerun(self: &Arc<Self>) {
        let last = self.state.lock().expect("lint lock").last.clone();
        if let Some(job) = last {
            self.request(job);
        }
    }

    /// Stop the lane and the reifier, for the server's exit.
    pub async fn shutdown(&self) {
        self.lane.shutdown().await;
        *self.reifier.lock().await = None;
    }

    async fn work(self: Arc<Self>) {
        loop {
            self.wake.notified().await;
            loop {
                while timeout(DEBOUNCE, self.wake.notified()).await.is_ok() {}
                let Some(job) = self.state.lock().expect("lint lock").pending.take() else {
                    break;
                };
                self.run(job).await;
            }
        }
    }

    fn superseded(&self) -> bool {
        self.state.lock().expect("lint lock").pending.is_some()
    }

    async fn run(&self, job: Job) {
        let view = {
            let mut state = self.state.lock().expect("lint lock");
            state.running = true;
            state.last = Some(job.clone());
            state.before = state.view.findings.clone();
            state.view.tier = 0;
            state.view.error = None;
            state.view.analysis = self.config.analysis.current().display().to_string();
            state.view.clone()
        };
        (self.publish)(view);
        let started = Instant::now();
        let mut ms = Vec::new();
        let reified = self.reify(&job, None).await;
        ms.push(started.elapsed().as_millis() as u64);
        let mut failure = reified.err();
        if failure.is_none() {
            let mut session = self.session.lock().await;
            for tier in 0..TIERS.len() {
                if self.superseded() {
                    break;
                }
                let started = Instant::now();
                match self.tier(&mut session, tier, &job).await {
                    Ok((findings, facts)) => {
                        ms.push(started.elapsed().as_millis() as u64);
                        self.publish_tier(tier, findings, facts, &ms);
                    }
                    Err(error) => {
                        if !self.superseded() {
                            failure = Some(error);
                        }
                        break;
                    }
                }
            }
        }
        let mut state = self.state.lock().expect("lint lock");
        state.running = false;
        state.view.working = state.pending.is_some();
        if failure.is_some() {
            state.view.error = failure;
        }
        let view = state.view.clone();
        drop(state);
        (self.publish)(view);
    }

    /// The facts of `job`'s program, as the database; with `program`, also
    /// as a Slog program in that file.
    async fn reify(&self, job: &Job, program: Option<&Path>) -> Result<(), String> {
        let mut sources = serde_json::Map::new();
        for (path, text) in &job.files {
            let absolute = job.absolute(path);
            // an include resolves through normalize-path, which follows
            // symlinks: key each text both ways
            if let Ok(resolved) = std::fs::canonicalize(&absolute) {
                sources.insert(resolved.display().to_string(), text.clone().into());
            }
            sources.insert(absolute.display().to_string(), text.clone().into());
        }
        let mut request = serde_json::json!({
            "id": 1,
            "path": job.absolute(&job.main),
            "sources": sources,
            "freeze": self.config.database,
        });
        if let Some(program) = program {
            request["program"] = program.display().to_string().into();
        }
        let mut reifier = self.reifier.lock().await;
        if reifier.is_none() {
            *reifier = Some(self.spawn_reifier()?);
        }
        let process = reifier.as_mut().expect("a reifier was just ensured");
        let answer = async {
            process.input.write_all(format!("{request}\n").as_bytes()).await.ok()?;
            process.input.flush().await.ok()?;
            process.output.next_line().await.ok()?
        };
        let Ok(Some(line)) = timeout(REIFY_LIMIT, answer).await.map(Some).map(Option::flatten) else {
            *reifier = None;
            return Err("the reifier (compiler/reify.rkt) stopped answering".to_owned());
        };
        let answer: serde_json::Value =
            serde_json::from_str(&line).map_err(|error| format!("the reifier's answer is unreadable: {error}"))?;
        if answer["ok"].as_bool() == Some(true) {
            Ok(())
        } else {
            Err(answer["error"].as_str().unwrap_or("the reifier failed").to_owned())
        }
    }

    fn spawn_reifier(&self) -> Result<Reifier, String> {
        let mut child = Command::new("racket")
            .args(["compiler/reify.rkt", "--serve"])
            .current_dir(&self.config.root)
            .stdin(Stdio::piped())
            .stdout(Stdio::piped())
            .stderr(Stdio::null())
            .kill_on_drop(true)
            .spawn()
            .map_err(|error| format!("cannot start compiler/reify.rkt: {error}"))?;
        let input = child.stdin.take().expect("piped stdin");
        let output = BufReader::new(child.stdout.take().expect("piped stdout")).lines();
        Ok(Reifier {
            _child: child,
            input,
            output,
        })
    }

    /// Run tier `tier` over the facts; its findings, and the rows of every
    /// relation the tiers so far add.
    async fn tier(
        &self,
        session: &mut Session,
        tier: usize,
        job: &Job,
    ) -> Result<(Vec<Finding>, BTreeMap<String, Vec<Vec<String>>>), String> {
        let analysis = self.config.analysis.current();
        let mut steps = Vec::new();
        let first = if LAYERED { tier } else { 0 };
        if first == 0 {
            steps.extend(self.fresh(session));
        }
        for (program, _) in &TIERS[first..=tier] {
            steps.push(format!("run {}", analysis.join(program).display()));
        }
        for line in steps {
            let outcome = session.execute(&self.lane, &line).await;
            if let Some(error) = outcome.error {
                return Err(format!("{line}: {}", error.message));
            }
            // an interrupt answers the run with a pause
            if outcome.result.as_ref().and_then(|result| result["kind"].as_str()) == Some("paused") {
                return Err("interrupted".to_owned());
            }
        }
        let mut facts = BTreeMap::new();
        for (name, query) in TIERS[..=tier].iter().flat_map(|(_, dumps)| dumps.iter()) {
            facts.insert((*name).to_owned(), self.dump(session, name, query, job).await?);
        }
        let findings = facts
            .get("finding")
            .map(|rows| rows.iter().filter_map(|row| finding(row, job)).collect())
            .unwrap_or_default();
        Ok((findings, facts))
    }

    /// The steps to a fresh session over the facts.
    fn fresh(&self, session: &Session) -> Vec<String> {
        let mut steps = Vec::new();
        if session.view().held {
            steps.push("abort".to_owned());
        }
        if session.view().current.is_some() {
            steps.push("discard session".to_owned());
        }
        steps.push(format!("open {}", self.config.database));
        steps
    }

    async fn dump(&self, session: &mut Session, name: &str, query: &str, job: &Job) -> Result<Vec<Vec<String>>, String> {
        std::fs::create_dir_all(&self.config.home).map_err(|error| error.to_string())?;
        let file = self.config.home.join(format!("{name}.csv"));
        let outcome = session
            .execute(&self.lane, &format!("dump {query} to {}", file.display()))
            .await;
        if let Some(error) = outcome.error {
            return Err(format!("{query}: {}", error.message));
        }
        let text = std::fs::read_to_string(&file).map_err(|error| error.to_string())?;
        Ok(text
            .lines()
            .skip(1)
            .map(|line| {
                csv_fields(line)
                    .into_iter()
                    .map(|cell| if cell.starts_with('/') { job.project_path(&cell).unwrap_or(cell) } else { cell })
                    .collect()
            })
            .collect())
    }

    fn publish_tier(&self, tier: usize, mut findings: Vec<Finding>, facts: BTreeMap<String, Vec<Vec<String>>>, ms: &[u64]) {
        let mut state = self.state.lock().expect("lint lock");
        let earlier: Vec<Finding> = if tier == 0 { Vec::new() } else { state.view.findings.clone() };
        for found in &mut findings {
            found.tier = earlier
                .iter()
                .find(|known| !known.stale && known.same(found))
                .map_or(tier, |known| known.tier);
        }
        let carried: Vec<Finding> = state
            .before
            .iter()
            .filter(|old| old.tier > tier && !findings.iter().any(|new| new.same(old)))
            .map(|old| Finding { stale: true, ..old.clone() })
            .collect();
        findings.extend(carried);
        let view = &mut state.view;
        view.findings = findings;
        view.facts.extend(facts);
        view.tier = tier + 1;
        view.ms = ms.to_vec();
        let view = view.clone();
        drop(state);
        (self.publish)(view);
    }

    /// Why the analysis made `finding`: rerun it on the analysis lane with
    /// its derivations recorded, and ask. The proof tree's nodes, as the
    /// REPL's `why` gives them, with the project's files named as it names
    /// them (web/lint-why.js tells them).
    pub async fn why(&self, finding: &Finding) -> Result<Vec<serde_json::Value>, String> {
        let (job, analysis) = {
            let state = self.state.lock().expect("lint lock");
            (state.last.clone().ok_or("nothing has been analyzed yet")?, self.config.analysis.current())
        };
        let mut session = self.session.lock().await;
        let path = if finding.file.starts_with('/') {
            finding.file.clone()
        } else {
            job.absolute(&finding.file).display().to_string()
        };
        let mut steps = self.fresh(&session);
        // `finding` must be live before the run for a watch to record it
        steps.push(format!("run {}", analysis.join("schema.slog").display()));
        steps.push("watch finding level 1 why".to_owned());
        steps.push(format!("run {}", analysis.join("lint.slog").display()));
        for line in steps {
            if let Some(error) = session.execute(&self.lane, &line).await.error {
                return Err(format!("{line}: {}", error.message));
            }
        }
        let fact = format!(
            "(finding {} {} {} {} {} {})",
            quote(&finding.severity),
            quote(&path),
            finding.line,
            finding.col,
            quote(&finding.code),
            quote(&finding.message)
        );
        let outcome = session.execute(&self.lane, &format!("why {fact} depth 16")).await;
        // the run waits at its watch; nothing of it is kept
        session.execute(&self.lane, "abort").await;
        if let Some(error) = outcome.error {
            return Err(error.message);
        }
        // the directory as the facts spell it, and as it is
        let mut prefixes = vec![format!("\"{}/", job.directory.display())];
        if let Ok(real) = std::fs::canonicalize(&job.directory) {
            prefixes.push(format!("\"{}/", real.display()));
        }
        let mut nodes: Vec<serde_json::Value> = outcome
            .result
            .and_then(|result| serde_json::from_value(result["nodes"].clone()).ok())
            .unwrap_or_default();
        for node in &mut nodes {
            if let Some(row) = node["row"].as_str() {
                let row = prefixes.iter().fold(row.to_owned(), |row, prefix| row.replace(prefix, "\""));
                node["row"] = row.into();
            }
        }
        Ok(nodes)
    }

    /// Write `job`'s facts as the analysis's own `facts.slog`, the program
    /// it analyzes when run as a project ("Edit the analysis").
    pub async fn write_facts(&self) -> Result<(), String> {
        let job = self.state.lock().expect("lint lock").last.clone().ok_or("nothing has been analyzed yet")?;
        self.reify(&job, Some(&self.config.analysis.dir().join("facts.slog"))).await
    }
}

/// A finding row (severity, file, line, col, code, message), with its form.
fn finding(row: &[String], job: &Job) -> Option<Finding> {
    let [severity, file, line, col, code, message] = row else { return None };
    // a file outside the project (an include from elsewhere) is not the
    // author's to fix here
    if file.starts_with('/') {
        return None;
    }
    let line: u32 = line.parse().ok()?;
    let (form_line, form) = job
        .files
        .get(file)
        .and_then(|text| form_of(text, line))
        .unwrap_or_default();
    Some(Finding {
        severity: severity.clone(),
        file: file.clone(),
        line,
        col: col.parse().ok()?,
        code: code.clone(),
        message: message.clone(),
        tier: 0,
        form_line,
        form,
        stale: false,
    })
}

/// The top-level form of `text` holding `line`: its first line, and its
/// lines without the blank and comment lines trailing it (web/lint.js
/// reads forms the same way).
fn form_of(text: &str, line: u32) -> Option<(u32, String)> {
    let form = forms::forms(text)
        .into_iter()
        .take_while(|form| form.line <= line)
        .last()?;
    let lines: Vec<&str> = text.lines().collect();
    let mut body = lines.get(form.line as usize - 1..(form.end_line as usize).min(lines.len()))?;
    while let [rest @ .., last] = body
        && !rest.is_empty()
        && (last.trim().is_empty() || last.trim_start().starts_with(";;"))
    {
        body = rest;
    }
    Some((form.line, body.join("\n").trim_end().to_owned()))
}

/// A string as Slog writes it.
fn quote(text: &str) -> String {
    format!("\"{}\"", text.replace('\\', "\\\\").replace('"', "\\\""))
}

/// One CSV line, as `dump` writes it.
fn csv_fields(line: &str) -> Vec<String> {
    let mut fields = Vec::new();
    let mut field = String::new();
    let mut quoted = false;
    let mut chars = line.chars().peekable();
    while let Some(c) = chars.next() {
        match c {
            '"' if quoted && chars.peek() == Some(&'"') => {
                field.push('"');
                chars.next();
            }
            '"' => quoted = !quoted,
            ',' if !quoted => fields.push(std::mem::take(&mut field)),
            c => field.push(c),
        }
    }
    fields.push(field);
    fields
}

#[cfg(test)]
mod tests {
    use super::{csv_fields, form_of};

    #[test]
    fn csv_fields_keep_quoted_commas_and_quotes() {
        assert_eq!(
            csv_fields(r#"warning,/a/b.slog,3,7,type,"this is a ""str"", not an int""#),
            ["warning", "/a/b.slog", "3", "7", "type", r#"this is a "str", not an int"#]
        );
    }

    #[test]
    fn a_line_belongs_to_the_form_before_it() {
        let text = "table (a int)\n\nrule (a 1)\n     (a 2)\n\n;; note\nrule (a X) --> (a X)\n";
        assert_eq!(form_of(text, 4), Some((3, "rule (a 1)\n     (a 2)".to_owned())));
        assert_eq!(form_of(text, 7), Some((7, "rule (a X) --> (a X)".to_owned())));
    }
}
