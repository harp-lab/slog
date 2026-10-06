//! The program summary, kept current in the background: a short account of
//! what the program does and a one-liner per top-level form, written by a
//! no-tools `claude -p`, beside the findings of an optional external
//! analyzer (`STUDIO_ANALYZER`).
//!
//! A save or a run requests a job for the text it saved. Jobs run one at a
//! time, and a request replaces any job still waiting, so only the newest
//! text is ever summarized after the current job. Summaries are cached by a
//! hash of exactly what the model is shown, in memory and in a small file in
//! the program's directory under the studio's data. Analyzer results are not cached: the analyzer is
//! expected to be under development, so its output for a text can change.

use serde::{Deserialize, Serialize};
use std::path::{Path, PathBuf};
use std::process::Stdio;
use std::sync::{Arc, Mutex};
use tokio::io::AsyncWriteExt;
use tokio::process::Command;
use tokio::sync::Notify;
use tokio::time::{Duration, timeout};

/// How long one `claude -p` call or one analyzer run may take.
const CLAUDE_LIMIT: Duration = Duration::from_secs(180);
const ANALYZER_LIMIT: Duration = Duration::from_secs(60);
/// Summaries kept in the cache file; the oldest go first.
const CACHE_ENTRIES: usize = 128;

const SYSTEM_PROMPT: &str = "\
You summarize programs for Slog Studio, an editor for Slog, a Datalog-family \
logic language: `table` declares a relation, `rule` derives facts (a body, \
then `-->`, then the head facts; a rule with no arrow states facts), and \
evaluation runs the rules to a fixpoint.

Reply with one JSON object and nothing else: no prose, no code fence.
{\"summary\": \"...\", \"forms\": [{\"line\": 1, \"text\": \"...\"}]}
- summary: 2-4 sentences on what the program computes, as it now stands. \
Use the relation counts when they are given, and mention anything that looks \
unfinished or inconsistent with them.
- forms: one entry per listed form, `line` exactly as listed, `text` one \
short line (under 80 characters) saying what that form does.";

/// A relation and its size after an evaluation, as `tables` reports it.
#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
pub struct Relation {
    pub name: String,
    pub rows: u64,
}

/// The relations a `tables` result lists, or `None` if it has none to read.
pub fn relations(tables: &serde_json::Value) -> Option<Vec<Relation>> {
    serde_json::from_value(tables.get("relations")?.clone()).ok()
}

/// What the model must answer.
#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
#[serde(deny_unknown_fields)]
pub struct Summary {
    pub summary: String,
    pub forms: Vec<FormNote>,
}

#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
#[serde(deny_unknown_fields)]
pub struct FormNote {
    pub line: u32,
    pub text: String,
}

/// What the analyzer must answer. Unknown fields are allowed, so the
/// analyzer can grow (e.g. derived facts) ahead of Studio.
#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
pub struct Analysis {
    pub summary: Option<String>,
    pub findings: Vec<Finding>,
}

#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
pub struct Finding {
    pub line: u32,
    pub severity: Severity,
    pub message: String,
}

#[derive(Clone, Copy, Debug, Deserialize, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Severity {
    Error,
    Warning,
    Info,
}

/// A result and the version of the text it describes.
#[derive(Clone, Debug, Serialize)]
pub struct Versioned<T> {
    pub version: u64,
    #[serde(flatten)]
    pub value: T,
}

/// What every tab shows.
#[derive(Clone, Debug, Default, Serialize)]
pub struct View {
    /// Why there is no model summary, when there cannot be one.
    pub unavailable: Option<String>,
    /// An analyzer is configured.
    pub analyzer: bool,
    /// A job is running or waiting.
    pub working: bool,
    /// The newest valid results; a failed job leaves them in place.
    pub summary: Option<Versioned<Summary>>,
    pub analysis: Option<Versioned<Analysis>>,
    /// What went wrong in the last job.
    pub errors: Vec<String>,
}

pub struct Config {
    /// The `claude` executable, or why there is none.
    pub claude: Result<PathBuf, String>,
    /// `--model` for `claude`; `None` leaves the CLI's default.
    pub model: Option<String>,
    pub analyzer: Option<PathBuf>,
    /// Holds the cache file and each job's working files.
    pub home: PathBuf,
    /// The program's file name, for the prompt and the analyzer's copy.
    pub name: String,
}

impl Config {
    /// `claude` from PATH, `STUDIO_SUMMARY_MODEL`, `STUDIO_ANALYZER`. Each
    /// program gets a directory of its own under `data`, named by a hash of
    /// its path, since one server can hold several programs.
    pub fn from_env(data: &Path, program: &Path) -> Self {
        let claude = std::env::var_os("PATH")
            .and_then(|path| {
                std::env::split_paths(&path)
                    .map(|directory| directory.join("claude"))
                    .find(|candidate| is_executable(candidate))
            })
            .ok_or_else(|| "`claude` is not on PATH, so there is no model summary".to_owned());
        let set = |name| std::env::var(name).ok().filter(|value| !value.is_empty());
        Self {
            claude,
            model: set("STUDIO_SUMMARY_MODEL"),
            analyzer: set("STUDIO_ANALYZER").map(PathBuf::from),
            home: data
                .join("summary")
                .join(format!("{:016x}", fingerprint(&[&program.to_string_lossy()]))),
            name: program.file_name().map_or_else(
                || "program.slog".to_owned(),
                |name| name.to_string_lossy().into_owned(),
            ),
        }
    }
}

fn is_executable(path: &Path) -> bool {
    use std::os::unix::fs::PermissionsExt;
    path.metadata()
        .is_ok_and(|metadata| metadata.is_file() && metadata.permissions().mode() & 0o111 != 0)
}

struct Job {
    version: u64,
    text: String,
    relations: Option<Vec<Relation>>,
}

struct State {
    view: View,
    /// The newest request not yet started.
    pending: Option<Job>,
    /// Oldest first.
    cache: Vec<CacheEntry>,
    /// The relations of the last evaluation, and the hash of its text.
    evaluated: Option<(u64, Vec<Relation>)>,
}

pub struct Summarizer {
    config: Config,
    state: Mutex<State>,
    wake: Notify,
    publish: Box<dyn Fn(View) + Send + Sync>,
}

impl Summarizer {
    /// Load the cache and start the worker; `publish` sees every change to
    /// the view.
    pub fn start(config: Config, publish: impl Fn(View) + Send + Sync + 'static) -> Arc<Self> {
        let cache = std::fs::read(cache_file(&config))
            .ok()
            .and_then(|bytes| serde_json::from_slice(&bytes).ok())
            .unwrap_or_default();
        let view = View {
            unavailable: config.claude.as_ref().err().cloned(),
            analyzer: config.analyzer.is_some(),
            ..View::default()
        };
        let summarizer = Arc::new(Self {
            config,
            state: Mutex::new(State {
                view,
                pending: None,
                cache,
                evaluated: None,
            }),
            wake: Notify::new(),
            publish: Box::new(publish),
        });
        tokio::spawn(summarizer.clone().work());
        summarizer
    }

    pub fn view(&self) -> View {
        self.state.lock().expect("summary lock").view.clone()
    }

    /// Summarize `text`, the program as of `version`. `evaluated` carries
    /// the relations when `text` was just evaluated; otherwise those of the
    /// last evaluation are used if it was of this same text.
    pub fn request(&self, version: u64, text: String, evaluated: Option<Vec<Relation>>) {
        if self.config.claude.is_err() && self.config.analyzer.is_none() {
            return;
        }
        let mut state = self.state.lock().expect("summary lock");
        let hash = fingerprint(&[&text]);
        if let Some(relations) = evaluated {
            state.evaluated = Some((hash, relations));
        }
        let relations = state
            .evaluated
            .as_ref()
            .filter(|(evaluated, _)| *evaluated == hash)
            .map(|(_, relations)| relations.clone());
        state.pending = Some(Job {
            version,
            text,
            relations,
        });
        state.view.working = true;
        let view = state.view.clone();
        drop(state);
        (self.publish)(view);
        self.wake.notify_one();
    }

    async fn work(self: Arc<Self>) {
        loop {
            self.wake.notified().await;
            while let Some(job) = self.next_job() {
                let (summary, analysis) = tokio::join!(self.summarize(&job), self.analyze(&job));
                self.finish(job.version, summary, analysis);
            }
        }
    }

    /// A call of its own: in a `while let` condition the guard would be
    /// held through the loop's body, which takes the lock again.
    fn next_job(&self) -> Option<Job> {
        self.state.lock().expect("summary lock").pending.take()
    }

    /// `None` when there is no `claude` to ask.
    async fn summarize(&self, job: &Job) -> Option<Result<Summary, String>> {
        let claude = self.config.claude.as_ref().ok()?;
        let found = forms(&job.text);
        let prompt = prompt(
            &self.config.name,
            &job.text,
            &found,
            job.relations.as_deref(),
        );
        let key = fingerprint(&[self.config.model.as_deref().unwrap_or(""), &prompt]);
        let cached = self
            .state
            .lock()
            .expect("summary lock")
            .cache
            .iter()
            .find(|entry| entry.key == key)
            .map(|entry| entry.summary.clone());
        if let Some(summary) = cached {
            return Some(Ok(summary));
        }
        let mut command = Command::new(claude);
        // `--tools ""` withholds every built-in tool and `--strict-mcp-config`
        // every MCP server: the model can only answer. (`--bare` would be
        // leaner still, but it refuses OAuth credentials.)
        command.args([
            "-p",
            "--output-format",
            "json",
            "--max-turns",
            "1",
            "--tools",
            "",
            "--strict-mcp-config",
            "--disable-slash-commands",
            "--no-session-persistence",
            "--system-prompt",
            SYSTEM_PROMPT,
        ]);
        if let Some(model) = &self.config.model {
            command.args(["--model", model]);
        }
        let lines: Vec<u32> = found.iter().map(|(line, _)| *line).collect();
        let summary = self
            .run(command, Some(&prompt), CLAUDE_LIMIT)
            .await
            .and_then(|stdout| parse_summary(&stdout, &lines));
        if let Ok(summary) = &summary {
            self.remember(key, summary.clone());
        }
        Some(summary)
    }

    /// `None` when no analyzer is configured.
    async fn analyze(&self, job: &Job) -> Option<Result<Analysis, String>> {
        let analyzer = self.config.analyzer.as_ref()?;
        Some(self.run_analyzer(analyzer, job).await)
    }

    /// The analyzer reads a copy of the job's text, not the program file,
    /// so its lines are the lines of the text the result is shown against.
    async fn run_analyzer(&self, analyzer: &Path, job: &Job) -> Result<Analysis, String> {
        let program = self.config.home.join(&self.config.name);
        let eval = self.config.home.join("eval.json");
        let written = std::fs::create_dir_all(&self.config.home)
            .and_then(|()| std::fs::write(&program, &job.text))
            .and_then(|()| {
                std::fs::write(
                    &eval,
                    serde_json::json!({ "relations": job.relations }).to_string(),
                )
            });
        written.map_err(|error| format!("cannot write the analyzer's input: {error}"))?;
        let mut command = Command::new(analyzer);
        command
            .arg("analyze")
            .arg("--program")
            .arg(&program)
            .arg("--eval")
            .arg(&eval);
        let stdout = self.run(command, None, ANALYZER_LIMIT).await?;
        parse_analysis(&stdout, job.text.lines().count())
    }

    /// Run `command` in the job directory and return its stdout, or why it
    /// failed.
    async fn run(
        &self,
        mut command: Command,
        input: Option<&str>,
        limit: Duration,
    ) -> Result<String, String> {
        std::fs::create_dir_all(&self.config.home)
            .map_err(|error| format!("cannot create {}: {error}", self.config.home.display()))?;
        let program = command
            .as_std()
            .get_program()
            .to_string_lossy()
            .into_owned();
        let mut child = command
            .current_dir(&self.config.home)
            .stdin(if input.is_some() {
                Stdio::piped()
            } else {
                Stdio::null()
            })
            .stdout(Stdio::piped())
            .stderr(Stdio::piped())
            .kill_on_drop(true)
            .spawn()
            .map_err(|error| format!("cannot run {program}: {error}"))?;
        let stdin = child.stdin.take();
        let feed = async move {
            if let (Some(mut stdin), Some(input)) = (stdin, input) {
                // A program that exits without reading says why on its own.
                let _ = stdin.write_all(input.as_bytes()).await;
            }
        };
        let (_, output) = timeout(limit, async {
            tokio::join!(feed, child.wait_with_output())
        })
        .await
        .map_err(|_| format!("{program} took longer than {} s", limit.as_secs()))?;
        let output = output.map_err(|error| format!("{program}: {error}"))?;
        if !output.status.success() {
            let stderr = String::from_utf8_lossy(&output.stderr);
            let last = stderr
                .lines()
                .rev()
                .find(|line| !line.trim().is_empty())
                .unwrap_or("");
            return Err(format!("{program} failed ({}): {last}", output.status));
        }
        String::from_utf8(output.stdout)
            .map_err(|_| format!("{program} wrote output that is not UTF-8"))
    }

    fn remember(&self, key: u64, summary: Summary) {
        let mut state = self.state.lock().expect("summary lock");
        state.cache.push(CacheEntry { key, summary });
        let excess = state.cache.len().saturating_sub(CACHE_ENTRIES);
        state.cache.drain(..excess);
        let bytes = serde_json::to_vec(&state.cache);
        drop(state);
        // Write then rename, so a crash never leaves half a cache. Losing
        // the cache only costs a recomputation, so failures are ignored.
        let file = cache_file(&self.config);
        let partial = file.with_extension("json.new");
        if let Ok(bytes) = bytes
            && std::fs::write(&partial, bytes).is_ok()
        {
            let _ = std::fs::rename(&partial, &file);
        }
    }

    fn finish(
        &self,
        version: u64,
        summary: Option<Result<Summary, String>>,
        analysis: Option<Result<Analysis, String>>,
    ) {
        let mut state = self.state.lock().expect("summary lock");
        let view = &mut state.view;
        view.errors.clear();
        match summary {
            Some(Ok(value)) => view.summary = Some(Versioned { version, value }),
            Some(Err(error)) => view.errors.push(format!("summary: {error}")),
            None => {}
        }
        match analysis {
            Some(Ok(value)) => view.analysis = Some(Versioned { version, value }),
            Some(Err(error)) => view.errors.push(format!("analyzer: {error}")),
            None => {}
        }
        state.view.working = state.pending.is_some();
        let view = state.view.clone();
        drop(state);
        (self.publish)(view);
    }
}

#[derive(Deserialize, Serialize)]
struct CacheEntry {
    key: u64,
    summary: Summary,
}

fn cache_file(config: &Config) -> PathBuf {
    config.home.join("cache.json")
}

/// FNV-1a over the parts, each ended by a byte UTF-8 never contains. Stable
/// across builds, which the on-disk cache needs (std's hasher is not).
fn fingerprint(parts: &[&str]) -> u64 {
    let mut hash: u64 = 0xcbf2_9ce4_8422_2325;
    for part in parts {
        for byte in part.bytes().chain([0xff]) {
            hash ^= u64::from(byte);
            hash = hash.wrapping_mul(0x0100_0000_01b3);
        }
    }
    hash
}

/// What the model is shown: the program, its forms, and the relation
/// counts of the last evaluation when it was of this text.
fn prompt(name: &str, text: &str, forms: &[(u32, &str)], relations: Option<&[Relation]>) -> String {
    let lines: Vec<&str> = text.lines().collect();
    let mut prompt = format!(
        "Program `{name}`:\n```\n{text}\n```\n\nTop-level forms (line: first line of the form):\n"
    );
    for (line, _) in forms {
        let first = lines.get(*line as usize - 1).map_or("", |line| line.trim());
        prompt.push_str(&format!("{line}: {first}\n"));
    }
    match relations {
        Some(relations) => {
            prompt.push_str("\nRelation counts after evaluating this text:\n");
            for Relation { name, rows } in relations {
                prompt.push_str(&format!("{name}: {rows}\n"));
            }
        }
        None => prompt.push_str("\nThis text has not been evaluated.\n"),
    }
    prompt
}

/// The model's summary from `claude -p --output-format json` output: the
/// result must be the requested JSON object, with a summary and notes only
/// for listed form lines.
fn parse_summary(stdout: &str, form_lines: &[u32]) -> Result<Summary, String> {
    #[derive(Deserialize)]
    struct Envelope {
        is_error: bool,
        result: Option<String>,
        subtype: Option<String>,
    }
    let envelope: Envelope = serde_json::from_str(stdout.trim())
        .map_err(|error| format!("claude printed no result ({error})"))?;
    let result = envelope.result.unwrap_or_default();
    if envelope.is_error {
        let why = if result.is_empty() {
            envelope.subtype.unwrap_or_default()
        } else {
            result
        };
        return Err(format!("claude reported an error: {why}"));
    }
    let summary: Summary = serde_json::from_str(result.trim()).map_err(|error| {
        format!(
            "the reply is not the requested JSON ({error}): {}",
            excerpt(&result)
        )
    })?;
    if summary.summary.trim().is_empty() {
        return Err("the reply has an empty summary".to_owned());
    }
    if let Some(note) = summary
        .forms
        .iter()
        .find(|note| !form_lines.contains(&note.line))
    {
        return Err(format!(
            "the reply describes line {}, where no form starts",
            note.line
        ));
    }
    Ok(summary)
}

/// The analyzer's answer; each finding must be on a line of the program.
fn parse_analysis(stdout: &str, line_count: usize) -> Result<Analysis, String> {
    let analysis: Analysis = serde_json::from_str(stdout.trim())
        .map_err(|error| format!("unreadable output ({error}): {}", excerpt(stdout)))?;
    if let Some(finding) = analysis
        .findings
        .iter()
        .find(|finding| finding.line == 0 || finding.line as usize > line_count)
    {
        return Err(format!(
            "a finding is on line {}, outside the program",
            finding.line
        ));
    }
    Ok(analysis)
}

fn excerpt(text: &str) -> String {
    let text = text.trim();
    match text.char_indices().nth(120) {
        Some((end, _)) => format!("{}…", &text[..end]),
        None => text.to_owned(),
    }
}

/// Top-level keywords (compiler/parser.rkt `top-level-keywords`).
const KEYWORDS: [&str; 15] = [
    "def",
    "rule",
    "enum",
    "table",
    "struct",
    "union",
    "demand",
    "extern",
    "lattice",
    "include",
    "instantiate",
    "run",
    "let",
    "import",
    "export",
];

/// The (line, keyword) where each top-level form starts: a keyword at
/// bracket depth 0, outside comments, strings and ref tokens.
///
/// A port of `forms` in web/forms.js, reduced to what the prompt needs; it
/// duplicates the scanner being ported to src/forms.rs, with which it
/// should be reconciled.
fn forms(text: &str) -> Vec<(u32, &str)> {
    let bytes = text.as_bytes();
    let (mut i, mut line, mut depth) = (0, 1, 0u32);
    let mut found = Vec::new();
    // Step over one byte, counting lines.
    let step = |i: &mut usize, line: &mut u32| {
        if let Some(&byte) = bytes.get(*i) {
            *line += u32::from(byte == b'\n');
            *i += 1;
        }
    };
    while let Some(&c) = bytes.get(i) {
        match c {
            b';' if bytes.get(i + 1) == Some(&b';') => {
                while bytes.get(i).is_some_and(|&b| b != b'\n') {
                    step(&mut i, &mut line);
                }
            }
            // A string may span lines; a ref token ends with its line.
            b'"' | b'\'' => {
                step(&mut i, &mut line);
                while let Some(&b) = bytes.get(i)
                    && b != c
                    && !(c == b'\'' && b == b'\n')
                {
                    step(&mut i, &mut line);
                    if b == b'\\' {
                        step(&mut i, &mut line);
                    }
                }
                step(&mut i, &mut line);
            }
            b'(' | b'[' | b'{' => {
                depth += 1;
                step(&mut i, &mut line);
            }
            b')' | b']' | b'}' => {
                depth = depth.saturating_sub(1);
                step(&mut i, &mut line);
            }
            // An identifier, which may contain ' after its first character.
            c if c.is_ascii_alphanumeric() || c == b'_' => {
                let start = i;
                while bytes
                    .get(i)
                    .is_some_and(|&b| b.is_ascii_alphanumeric() || b == b'_' || b == b'\'')
                {
                    i += 1;
                }
                let word = &text[start..i];
                if depth == 0 && KEYWORDS.contains(&word) {
                    found.push((line, word));
                }
            }
            _ => step(&mut i, &mut line),
        }
    }
    found
}

#[cfg(test)]
mod tests {
    use super::{
        Analysis, Config, Relation, Severity, Summarizer, View, forms, parse_analysis,
        parse_summary,
    };
    use std::path::{Path, PathBuf};
    use std::sync::Arc;
    use tokio::sync::mpsc;
    use tokio::time::{Duration, Instant, sleep, timeout};

    /// A directory of its own for each test.
    fn scratch(name: &str) -> PathBuf {
        let directory =
            std::env::temp_dir().join(format!("studio-summary-{name}-{}", std::process::id()));
        let _ = std::fs::remove_dir_all(&directory);
        std::fs::create_dir_all(&directory).expect("scratch directory");
        directory
    }

    /// A stand-in for `claude`: it records each prompt in a `call.*` file,
    /// waits while a `hold` file exists, then prints the `reply` file.
    fn fake_claude(directory: &Path) -> PathBuf {
        use std::os::unix::fs::PermissionsExt;
        let script = directory.join("claude");
        let d = directory.display();
        std::fs::write(
            &script,
            format!(
                "#!/bin/sh\ncat > \"$(mktemp '{d}/call.XXXXXX')\"\n\
                 while [ -e '{d}/hold' ]; do sleep 0.01; done\ncat '{d}/reply'\n"
            ),
        )
        .expect("fake claude");
        std::fs::set_permissions(&script, std::fs::Permissions::from_mode(0o755)).expect("chmod");
        script
    }

    /// What `claude -p --output-format json` prints for a reply.
    fn envelope(reply: &str) -> String {
        serde_json::json!({ "type": "result", "is_error": false, "result": reply }).to_string()
    }

    fn start(
        directory: &Path,
        claude: Result<PathBuf, String>,
        analyzer: Option<PathBuf>,
    ) -> (Arc<Summarizer>, mpsc::UnboundedReceiver<View>) {
        let (views, received) = mpsc::unbounded_channel();
        let config = Config {
            claude,
            model: None,
            analyzer,
            home: directory.join("home"),
            name: "p.slog".to_owned(),
        };
        let summarizer = Summarizer::start(config, move |view| {
            let _ = views.send(view);
        });
        (summarizer, received)
    }

    /// The first published view settled on `version`, or on an error.
    async fn settled(views: &mut mpsc::UnboundedReceiver<View>, version: u64) -> View {
        timeout(Duration::from_secs(20), async {
            loop {
                let view = views.recv().await.expect("the summarizer publishes");
                let done = [
                    view.summary.as_ref().map(|s| s.version),
                    view.analysis.as_ref().map(|a| a.version),
                ];
                if !view.working && (done.contains(&Some(version)) || !view.errors.is_empty()) {
                    return view;
                }
            }
        })
        .await
        .expect("the job finished")
    }

    /// The prompts the fake was given, oldest first.
    fn calls(directory: &Path) -> Vec<String> {
        let mut calls: Vec<(std::time::SystemTime, String)> = std::fs::read_dir(directory)
            .expect("scratch directory")
            .filter_map(|entry| entry.ok())
            .filter(|entry| entry.file_name().to_string_lossy().starts_with("call."))
            .map(|entry| {
                let modified = entry.metadata().and_then(|m| m.modified()).expect("mtime");
                (
                    modified,
                    std::fs::read_to_string(entry.path()).expect("prompt"),
                )
            })
            .collect();
        calls.sort();
        calls.into_iter().map(|(_, prompt)| prompt).collect()
    }

    const A: &str = "table (a int)\n";
    const B: &str = "table (b int)\n";
    const C: &str = "table (c int)\n";

    /// A request waits behind the running job and is replaced by a newer
    /// one; the same input is answered from memory, then from the cache
    /// file by a new summarizer; and a save after a run reuses the run's
    /// relation counts.
    #[tokio::test]
    async fn jobs_run_newest_first_and_are_cached() {
        let directory = scratch("cache");
        let claude = fake_claude(&directory);
        let reply = r#"{"summary": "Declares one relation.", "forms": [{"line": 1, "text": "a relation"}]}"#;
        std::fs::write(directory.join("reply"), envelope(reply)).expect("reply");
        std::fs::write(directory.join("hold"), "").expect("hold");
        let (summarizer, mut views) = start(&directory, Ok(claude.clone()), None);

        summarizer.request(1, A.to_owned(), None);
        let deadline = Instant::now() + Duration::from_secs(10);
        while calls(&directory).is_empty() {
            assert!(Instant::now() < deadline, "the first job never started");
            sleep(Duration::from_millis(10)).await;
        }
        summarizer.request(2, B.to_owned(), None);
        summarizer.request(3, C.to_owned(), None);
        std::fs::remove_file(directory.join("hold")).expect("release");
        let view = settled(&mut views, 3).await;
        assert_eq!(
            view.summary.expect("a summary").value.summary,
            "Declares one relation."
        );
        let prompts = calls(&directory);
        assert_eq!(prompts.len(), 2, "B was superseded before it started");
        assert!(prompts[0].contains(A) && prompts[1].contains(C));

        summarizer.request(4, A.to_owned(), None);
        settled(&mut views, 4).await;
        assert_eq!(calls(&directory).len(), 2, "A is cached in memory");

        let counts = vec![Relation {
            name: "c".to_owned(),
            rows: 0,
        }];
        summarizer.request(5, C.to_owned(), Some(counts));
        settled(&mut views, 5).await;
        let prompts = calls(&directory);
        assert!(
            prompts.len() == 3 && prompts[2].contains("c: 0"),
            "counts are part of the input"
        );
        summarizer.request(6, C.to_owned(), None);
        settled(&mut views, 6).await;
        assert_eq!(
            calls(&directory).len(),
            3,
            "a save of the evaluated text reuses its counts"
        );

        let (restarted, mut views) = start(&directory, Ok(claude), None);
        restarted.request(7, A.to_owned(), None);
        settled(&mut views, 7).await;
        assert_eq!(calls(&directory).len(), 3, "A is cached on disk");
        std::fs::remove_dir_all(directory).expect("cleanup");
    }

    /// A malformed reply is reported and leaves the last good summary.
    #[tokio::test]
    async fn a_malformed_reply_keeps_the_previous_summary() {
        let directory = scratch("malformed");
        let reply = r#"{"summary": "Declares a.", "forms": []}"#;
        std::fs::write(directory.join("reply"), envelope(reply)).expect("reply");
        let (summarizer, mut views) = start(&directory, Ok(fake_claude(&directory)), None);
        summarizer.request(1, A.to_owned(), None);
        settled(&mut views, 1).await;

        let prose = envelope("Here is the summary you asked for.");
        std::fs::write(directory.join("reply"), prose).expect("reply");
        summarizer.request(2, B.to_owned(), None);
        let view = settled(&mut views, 2).await;
        let summary = view.summary.expect("the earlier summary");
        assert_eq!(
            (summary.version, summary.value.summary.as_str()),
            (1, "Declares a.")
        );
        assert!(
            view.errors[0].starts_with("summary: the reply is not the requested JSON"),
            "{:?}",
            view.errors
        );
        std::fs::remove_dir_all(directory).expect("cleanup");
    }

    /// Without `claude` the summary is off, and a request does nothing
    /// unless an analyzer can still run.
    #[tokio::test]
    async fn without_claude_only_the_analyzer_runs() {
        let directory = scratch("unavailable");
        let missing = Err("`claude` is not on PATH".to_owned());
        let (off, mut views) = start(&directory, missing.clone(), None);
        off.request(1, A.to_owned(), None);
        assert!(views.try_recv().is_err());
        assert!(off.view().unavailable.is_some() && !off.view().working);

        let (summarizer, mut views) = start(&directory, missing, Some(example_analyzer()));
        summarizer.request(1, A.to_owned(), None);
        let view = settled(&mut views, 1).await;
        assert!(view.summary.is_none() && view.analysis.is_some() && view.errors.is_empty());
        std::fs::remove_dir_all(directory).expect("cleanup");
    }

    #[test]
    fn replies_are_validated() {
        let lines = [1, 3];
        let good =
            r#"{"summary": "Edges and paths.", "forms": [{"line": 3, "text": "the closure"}]}"#;
        assert_eq!(
            parse_summary(&envelope(good), &lines).expect("valid").forms[0].line,
            3
        );
        let refused = |stdout: &str| parse_summary(stdout, &lines).expect_err(stdout);
        // claude itself failed, or printed something other than its envelope
        assert!(
            refused(r#"{"is_error": true, "subtype": "error_max_turns"}"#)
                .contains("error_max_turns")
        );
        assert!(refused("Not logged in").contains("no result"));
        // the reply is not exactly the requested object
        refused(&envelope(
            "```json\n{\"summary\": \"x\", \"forms\": []}\n```",
        ));
        refused(&envelope(r#"{"summary": "x"}"#));
        refused(&envelope(
            r#"{"summary": "x", "forms": [], "mood": "upbeat"}"#,
        ));
        assert!(refused(&envelope(r#"{"summary": " ", "forms": []}"#)).contains("empty"));
        let stray = r#"{"summary": "x", "forms": [{"line": 2, "text": "y"}]}"#;
        assert!(refused(&envelope(stray)).contains("line 2"));

        let finding =
            r#"{"findings": [{"line": 2, "severity": "warning", "message": "m"}], "facts": []}"#;
        let analysis: Analysis =
            parse_analysis(finding, 2).expect("valid; unknown fields are allowed");
        assert_eq!(
            (analysis.summary, analysis.findings[0].severity),
            (None, Severity::Warning)
        );
        assert!(
            parse_analysis(finding, 1)
                .expect_err("line 2 of 1")
                .contains("outside")
        );
        let fatal = r#"{"findings": [{"line": 1, "severity": "fatal", "message": "m"}]}"#;
        assert!(parse_analysis(fatal, 1).is_err());
        assert!(parse_analysis(r#"{"summary": "no findings"}"#, 1).is_err());
    }

    /// Keywords count only at the top level, outside comments, strings and
    /// ref tokens; a string may span lines.
    #[test]
    fn the_form_scanner_finds_top_level_keywords() {
        let text = ";; a rule in a comment\ntable (t int) rule\n(t 1)\n\
                    rule (t \"rule\nrule\") --> (u 'rule')\n  def x 1";
        assert_eq!(
            forms(text),
            vec![(2, "table"), (2, "rule"), (4, "rule"), (6, "def")]
        );
    }

    fn example_analyzer() -> PathBuf {
        Path::new(env!("CARGO_MANIFEST_DIR")).join("examples/analyzer/empty-relations")
    }

    /// The example analyzer keeps the contract: it reads the program and
    /// the evaluation, and flags the declared relation the run left empty.
    #[tokio::test]
    async fn the_example_analyzer_keeps_the_contract() {
        let directory = scratch("analyzer");
        let missing = Err("no claude in this test".to_owned());
        let (summarizer, mut views) = start(&directory, missing, Some(example_analyzer()));
        let text =
            "table (edge int int)\n;; table (old int)\ntable (path int int)\nrule (edge 1 2)\n";
        let counts = [("edge", 1), ("path", 0)]
            .map(|(name, rows)| Relation {
                name: name.to_owned(),
                rows,
            })
            .to_vec();
        summarizer.request(1, text.to_owned(), Some(counts));
        let view = settled(&mut views, 1).await;
        assert!(view.errors.is_empty(), "{:?}", view.errors);
        let analysis = view.analysis.expect("an analysis").value;
        assert_eq!(analysis.findings.len(), 1, "{analysis:?}");
        let finding = &analysis.findings[0];
        assert_eq!((finding.line, finding.severity), (3, Severity::Warning));
        assert!(finding.message.contains("path"));
        std::fs::remove_dir_all(directory).expect("cleanup");
    }
}
