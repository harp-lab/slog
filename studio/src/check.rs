//! The static check (`compiler/check.rkt`): parse, includes, types,
//! negation safety, stratification and lattices, without running anything.
//!
//! One `check.rkt --serve` process per studio answers every check. It is
//! apart from every lane -- no session, no daemon -- so a check never waits
//! behind a run or disturbs one, and the compiler's modules load once
//! instead of per check. Texts are checked where they would sit on disk, so
//! includes resolve and errors name the project's files; nothing is written.
//! Reports are kept by the texts they checked, so asking again is free.

use crate::studio::Studio;
use serde::{Deserialize, Serialize};
use serde_json::{Value, json};
use std::collections::{BTreeMap, HashMap};
use std::path::{Path, PathBuf};
use std::process::Stdio;
use tokio::io::{AsyncBufReadExt, AsyncWriteExt, BufReader, Lines};
use tokio::process::{Child, ChildStdin, ChildStdout, Command};
use tokio::sync::Mutex;

/// Reports kept, by the texts they checked.
const KEPT: usize = 64;

#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct Report {
    pub ok: bool,
    pub ms: u64,
    pub diagnostics: Vec<Diagnostic>,
    /// Types, signatures, definitions and references, for the editor's
    /// hovers (check.rkt's program-info); null when parsing failed.
    #[serde(default)]
    pub info: Value,
}

#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct Diagnostic {
    /// "error" or "warning".
    pub severity: String,
    /// Absolute.
    pub file: String,
    /// 1-based.
    pub line: u32,
    pub col: u32,
    pub message: String,
    /// False when the error named no place and is shown at line 1.
    #[serde(default = "yes")]
    pub located: bool,
}

fn yes() -> bool {
    true
}

impl Report {
    fn failed(message: String) -> Self {
        Report { ok: false, ms: 0, diagnostics: Vec::new(), info: Value::Null }.with_error(message)
    }

    fn with_error(mut self, message: String) -> Self {
        self.ok = false;
        self.diagnostics.push(Diagnostic {
            severity: "error".to_owned(),
            file: String::new(),
            line: 1,
            col: 1,
            message,
            located: false,
        });
        self
    }

    pub fn errors(&self) -> impl Iterator<Item = &Diagnostic> {
        self.diagnostics.iter().filter(|d| d.severity == "error")
    }

    /// The errors as an agent reads them: `LINE:COL: message`, with the file
    /// named when it is not `main`.
    pub fn describe(&self, main: &Path) -> String {
        self.errors()
            .map(|d| {
                let file = if Path::new(&d.file) == main || d.file.is_empty() {
                    String::new()
                } else {
                    format!("{}:", Path::new(&d.file).file_name().map_or(d.file.clone(), |n| n.to_string_lossy().into_owned()))
                };
                format!("{file}{}:{}: {}", d.line, d.col, d.message)
            })
            .collect::<Vec<_>>()
            .join("\n")
    }
}

pub struct Checker {
    root: PathBuf,
    process: Mutex<Option<Process>>,
    kept: std::sync::Mutex<HashMap<u64, Report>>,
}

struct Process {
    _child: Child,
    input: ChildStdin,
    output: Lines<BufReader<ChildStdout>>,
}

impl Checker {
    /// A checker over the repository at `root`; its process starts on first use.
    pub fn new(root: PathBuf) -> Self {
        Self { root, process: Mutex::new(None), kept: Default::default() }
    }

    /// Check `main` with `sources` (absolute path -> text) read in place of
    /// those files.
    pub async fn check(&self, main: &Path, sources: &BTreeMap<PathBuf, String>) -> Report {
        let request = json!({
            "path": main,
            "sources": sources.iter().map(|(path, text)| (path.to_string_lossy().into_owned(), text)).collect::<BTreeMap<_, _>>(),
        });
        let key = {
            use std::hash::{Hash, Hasher};
            let mut hasher = std::collections::hash_map::DefaultHasher::new();
            request.to_string().hash(&mut hasher);
            hasher.finish()
        };
        if let Some(report) = self.kept.lock().expect("check lock").get(&key) {
            return report.clone();
        }
        let mut process = self.process.lock().await;
        // A process that died is replaced, once.
        let mut answer = Err(String::new());
        for _ in 0..2 {
            if process.is_none() {
                match self.start() {
                    Ok(started) => *process = Some(started),
                    Err(error) => return Report::failed(error),
                }
            }
            answer = exchange(process.as_mut().expect("just started"), &request).await;
            if answer.is_ok() {
                break;
            }
            *process = None;
        }
        let report = match answer {
            Ok(line) => serde_json::from_str::<Report>(&line)
                .unwrap_or_else(|error| Report::failed(format!("the checker answered unreadably: {error}"))),
            Err(error) => return Report::failed(format!("the checker stopped: {error}")),
        };
        let mut kept = self.kept.lock().expect("check lock");
        if kept.len() >= KEPT {
            kept.clear();
        }
        kept.insert(key, report.clone());
        report
    }

    fn start(&self) -> Result<Process, String> {
        let mut child = Command::new("racket")
            .args(["compiler/check.rkt", "--serve"])
            .current_dir(&self.root)
            .stdin(Stdio::piped())
            .stdout(Stdio::piped())
            .stderr(Stdio::null())
            .kill_on_drop(true)
            .spawn()
            .map_err(|error| format!("cannot start racket compiler/check.rkt: {error}"))?;
        let input = child.stdin.take().expect("piped stdin");
        let output = BufReader::new(child.stdout.take().expect("piped stdout")).lines();
        Ok(Process { _child: child, input, output })
    }
}

async fn exchange(process: &mut Process, request: &Value) -> Result<String, String> {
    let mut line = request.to_string();
    line.push('\n');
    process.input.write_all(line.as_bytes()).await.map_err(|error| error.to_string())?;
    process.input.flush().await.map_err(|error| error.to_string())?;
    match process.output.next_line().await {
        Ok(Some(line)) => Ok(line),
        Ok(None) => Err("it exited".to_owned()),
        Err(error) => Err(error.to_string()),
    }
}

impl Studio {
    /// Check the program as the working files have it, with `texts`
    /// (project path -> text) in place of theirs and `extra` appended to the
    /// main file's text.
    pub async fn check_program(&self, texts: &BTreeMap<String, String>, extra: Option<&str>) -> Report {
        let (directory, main, mut files) = self.working_files();
        files.extend(texts.iter().map(|(path, text)| (path.clone(), text.clone())));
        if let (Some(extra), Some(text)) = (extra, files.get_mut(&main)) {
            *text = crate::review::apply(text, &crate::review::Change::Append { source: extra.to_owned() })
                .unwrap_or_else(|_| text.clone());
        }
        let sources = files.into_iter().map(|(path, text)| (directory.join(path), text)).collect();
        self.checker.check(&directory.join(main), &sources).await
    }

    /// Check the program with `text` as its main file.
    pub async fn check_main(&self, text: &str) -> Report {
        let main = self.working_files().1;
        self.check_program(&BTreeMap::from([(main, text.to_owned())]), None).await
    }
}
