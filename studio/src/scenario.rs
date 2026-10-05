//! Scenarios: a program, assertions written in Slog, and REPL steps with
//! expectations. A scenario is how a test or a debugging session is written
//! down, kept with the program, and replayed by a person, by CI, or by an
//! agent (docs/REPL-exploration-kris/notes/studio-design.md §9).
//!
//! ```toml
//! format = 2                       # 1 is the tutorial format scenarios extend
//! id = "reach"
//! title = "Transitive closure of a chain"
//! mode = "fast"                    # fast | compiled | debug
//!
//! [program]
//! main = "reach.slog"              # relative to this file
//!
//! [[checks]]                       # Slog forms evaluated with the program;
//! name = "closure-complete"        # each relation in `empty` must stay empty
//! slog = """
//! table (missing int int)
//! rule (edge X Y) ~(path X Y) --> (missing X Y)
//! """
//! empty = ["missing"]
//!
//! [[steps]]                        # an ordinary REPL line
//! run = "?(path 1 Y)"
//! expect = { rows = ["(path 1 2)", "(path 1 3)"] }
//! ```
//!
//! The runner evaluates a harness that includes the program and adds the
//! checks' forms, so checks run in the program's own fixpoint, in a fresh
//! session on a lane of its own; then it runs the steps in that session.
//! `{program}` in a step names the harness, so a debugging scenario can arm
//! a break and `run {program}` again into the session to stop there.

use crate::lane::{Lane, Mode};
use crate::session::{Outcome, Session};
use serde::{Deserialize, Serialize};
use serde_json::Value;
use std::collections::{BTreeMap, BTreeSet};
use std::path::{Path, PathBuf};

pub const SCENARIO_FORMAT: u32 = 2;

/// Rows gathered from one query through `more`, at most; a scenario that
/// needs more than this should assert a count instead.
const MAX_ROWS: usize = 100_000;

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Scenario {
    pub format: u32,
    pub id: String,
    pub title: String,
    #[serde(default)]
    pub mode: Mode,
    pub program: Program,
    #[serde(default)]
    pub checks: Vec<Check>,
    #[serde(default)]
    pub steps: Vec<Step>,
}

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Program {
    pub main: String,
}

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Check {
    pub name: String,
    pub slog: String,
    pub empty: Vec<String>,
}

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Step {
    pub run: String,
    #[serde(default)]
    pub expect: Expect,
}

/// What a step must produce. Without any of these, it must merely succeed.
#[derive(Debug, Default, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Expect {
    /// The command fails, with this text in its message.
    pub refused: Option<String>,
    /// A `?` query's number of answers: exact, never a budget's lower bound.
    pub count: Option<u64>,
    pub exists: Option<bool>,
    /// A `?` query's answers are exactly these rows, as a set.
    pub rows: Option<Vec<String>>,
    /// A `?` query's answers include these rows.
    pub rows_include: Option<Vec<String>>,
    /// Relation sizes after the step.
    pub sizes: Option<BTreeMap<String, u64>>,
    /// The step stops a run; its title contains this (`pre-commit gate`,
    /// `break b1`, `step`, `interrupt`).
    pub paused: Option<String>,
    /// Each of these appears in the result's text.
    pub contains: Option<Vec<String>>,
    /// The expectation is known not to hold yet, for this reason. A step
    /// that meets it anyway fails, so the marker cannot go stale.
    pub xfail: Option<String>,
}

impl Expect {
    fn queries(&self) -> bool {
        self.count.is_some() || self.exists.is_some() || self.rows.is_some() || self.rows_include.is_some()
    }
}

impl Scenario {
    pub fn parse(source: &str) -> Result<Self, String> {
        let scenario: Self = toml::from_str(source).map_err(|error| error.to_string())?;
        scenario.validate()?;
        Ok(scenario)
    }

    fn validate(&self) -> Result<(), String> {
        if self.format != SCENARIO_FORMAT {
            return Err(format!(
                "unsupported scenario format {}; expected {SCENARIO_FORMAT}",
                self.format
            ));
        }
        if self.id.is_empty()
            || !self
                .id
                .chars()
                .all(|c| c.is_ascii_lowercase() || c.is_ascii_digit() || c == '-')
        {
            return Err("id must contain lowercase ASCII letters, digits, or hyphens".to_owned());
        }
        if self.title.trim().is_empty() {
            return Err("title must not be empty".to_owned());
        }
        if self.program.main.trim().is_empty() {
            return Err("program.main must name the program file".to_owned());
        }
        let mut names = BTreeSet::new();
        for check in &self.checks {
            if check.name.trim().is_empty() || !names.insert(check.name.as_str()) {
                return Err(format!("check names must be present and unique: {:?}", check.name));
            }
            if check.empty.is_empty() {
                return Err(format!("check {}: `empty` must name at least one relation", check.name));
            }
        }
        for (index, step) in self.steps.iter().enumerate() {
            let invalid = |message: &str| format!("step {}: {message}", index + 1);
            let line = step.run.trim();
            if line.is_empty() {
                return Err(invalid("`run` must not be empty"));
            }
            let expect = &step.expect;
            if expect.refused.is_some()
                && (expect.queries() || expect.sizes.is_some() || expect.paused.is_some() || expect.contains.is_some())
            {
                return Err(invalid("a refused step has no other expectations"));
            }
            if expect.queries() && !line.starts_with('?') {
                return Err(invalid("count, exists and rows expectations need a `?` query"));
            }
            if self.mode != Mode::Debug && stops_runs(line) {
                return Err(invalid(
                    "breakpoints, stepping and level-1 watches need mode = \"debug\"",
                ));
            }
        }
        Ok(())
    }
}

/// Commands whose stopping place is reproducible only on the debug lane.
fn stops_runs(line: &str) -> bool {
    let verb = line.split_whitespace().next().unwrap_or("");
    matches!(verb, "break" | "step" | "frames" | "finish")
        || (verb == "watch" && line.contains("level 1"))
}

#[derive(Clone, Debug, Serialize)]
#[serde(tag = "verdict", content = "why", rename_all = "lowercase")]
pub enum Verdict {
    Pass,
    Fail(String),
    /// Failed as its `xfail` said it would.
    Xfail(String),
}

impl Verdict {
    pub fn passed(&self) -> bool {
        !matches!(self, Verdict::Fail(_))
    }
}

#[derive(Clone, Debug, Serialize)]
pub struct Judged {
    /// The check's name, or the step's REPL line.
    pub what: String,
    #[serde(flatten)]
    pub verdict: Verdict,
}

#[derive(Clone, Debug, Serialize)]
pub struct Report {
    pub id: String,
    pub title: String,
    /// Why nothing could be judged: the program did not evaluate.
    pub setup: Option<String>,
    pub checks: Vec<Judged>,
    pub steps: Vec<Judged>,
    /// Every command sent, in order.
    pub transcript: Vec<Outcome>,
}

impl Report {
    pub fn passed(&self) -> bool {
        self.setup.is_none()
            && self.checks.iter().chain(&self.steps).all(|judged| judged.verdict.passed())
    }
}

/// Run the scenario file at `path` on a fresh lane over the repository at
/// `root`.
pub async fn run(root: &Path, path: &Path) -> Result<Report, String> {
    let source = std::fs::read_to_string(path)
        .map_err(|error| format!("cannot read {}: {error}", path.display()))?;
    let scenario = Scenario::parse(&source).map_err(|error| format!("{}: {error}", path.display()))?;
    let directory = std::path::absolute(path)
        .map_err(|error| error.to_string())?
        .parent()
        .map(Path::to_path_buf)
        .unwrap_or_default();
    let main = directory.join(&scenario.program.main);
    if !main.is_file() {
        return Err(format!("{}: program {} does not exist", path.display(), main.display()));
    }
    let workspace = std::env::temp_dir().join(format!("slog-scenario-{}-{}", std::process::id(), scenario.id));
    std::fs::create_dir_all(&workspace)
        .map_err(|error| format!("cannot create {}: {error}", workspace.display()))?;
    let harness = write_harness(&workspace, &main, &scenario.checks)?;
    let lane = Lane::new(root.to_path_buf(), scenario.mode);
    let report = Runner {
        lane: &lane,
        session: Session::new(&lane),
        transcript: Vec::new(),
    }
    .run(&scenario, &harness)
    .await;
    lane.shutdown().await;
    let _ = std::fs::remove_dir_all(&workspace);
    Ok(report)
}

/// The program as the scenario evaluates it: the program itself when there
/// are no checks, else a file including it and adding the checks' forms.
fn write_harness(workspace: &Path, main: &Path, checks: &[Check]) -> Result<PathBuf, String> {
    if checks.is_empty() {
        return Ok(main.to_path_buf());
    }
    let mut text = format!("include {:?}\n", main.display().to_string());
    for check in checks {
        text.push_str(&format!("\n;; check {}\n{}\n", check.name, check.slog.trim_end()));
    }
    let harness = workspace.join("harness.slog");
    std::fs::write(&harness, text)
        .map_err(|error| format!("cannot write {}: {error}", harness.display()))?;
    Ok(harness)
}

struct Runner<'a> {
    lane: &'a Lane,
    session: Session,
    transcript: Vec<Outcome>,
}

impl Runner<'_> {
    async fn run(mut self, scenario: &Scenario, harness: &Path) -> Report {
        let mut transcript = Vec::new();
        let evaluated = self
            .session
            .evaluate(self.lane, harness, &mut |outcome| transcript.push(outcome.clone()))
            .await;
        self.transcript = transcript;
        let mut report = Report {
            id: scenario.id.clone(),
            title: scenario.title.clone(),
            setup: None,
            checks: Vec::new(),
            steps: Vec::new(),
            transcript: Vec::new(),
        };
        if !evaluated {
            let message = self
                .transcript
                .last()
                .and_then(|outcome| outcome.error.as_ref())
                .map_or("evaluation failed".to_owned(), |error| error.message.clone());
            report.setup = Some(format!("the program did not evaluate: {message}"));
            report.transcript = self.transcript;
            return report;
        }
        if !scenario.checks.is_empty() {
            let sizes = self.sizes().await;
            for check in &scenario.checks {
                report.checks.push(Judged {
                    what: check.name.clone(),
                    verdict: self.check(check, &sizes).await,
                });
            }
        }
        for step in &scenario.steps {
            let line = step.run.replace("{program}", &harness.display().to_string());
            let verdict = self.step(&line, &step.expect).await;
            report.steps.push(Judged {
                what: step.run.clone(),
                verdict: match (&step.expect.xfail, verdict) {
                    (None, verdict) => verdict,
                    (Some(why), Verdict::Fail(_)) => Verdict::Xfail(why.clone()),
                    (Some(why), _) => {
                        Verdict::Fail(format!("passes, but is marked xfail ({why}); remove the marker"))
                    }
                },
            });
        }
        report.transcript = self.transcript;
        report
    }

    async fn execute(&mut self, line: &str) -> Outcome {
        let outcome = self.session.execute(self.lane, line).await;
        self.transcript.push(outcome.clone());
        outcome
    }

    /// Every relation's size, internal ones included: a check may name the
    /// built-in `error` relation, which `tables` hides while it is empty.
    async fn sizes(&mut self) -> Result<BTreeMap<String, u64>, String> {
        let outcome = self.execute("tables all").await;
        let result = outcome
            .result
            .ok_or_else(|| outcome.error.map_or_else(String::new, |error| error.message))?;
        Ok(result["relations"]
            .as_array()
            .into_iter()
            .flatten()
            .filter_map(|relation| Some((relation["name"].as_str()?.to_owned(), relation["rows"].as_u64()?)))
            .collect())
    }

    async fn check(&mut self, check: &Check, sizes: &Result<BTreeMap<String, u64>, String>) -> Verdict {
        let sizes = match sizes {
            Ok(sizes) => sizes,
            Err(message) => return Verdict::Fail(format!("cannot list relations: {message}")),
        };
        let mut failures = Vec::new();
        for relation in &check.empty {
            match sizes.get(relation) {
                // An expected-empty relation that does not exist would pass
                // vacuously: a misspelling must not look like success.
                None => failures.push(format!("no relation named {relation}")),
                Some(0) => {}
                Some(rows) => {
                    let sample = self.sample(relation).await;
                    failures.push(format!("{relation} has {rows} rows, e.g. {sample}"));
                }
            }
        }
        if failures.is_empty() {
            Verdict::Pass
        } else {
            Verdict::Fail(failures.join("; "))
        }
    }

    /// A few rows of `relation`, for a failure message.
    async fn sample(&mut self, relation: &str) -> String {
        let outcome = self.execute(&format!("show {relation} 3")).await;
        outcome
            .result
            .and_then(|result| {
                result["lines"].as_array().map(|lines| {
                    lines
                        .iter()
                        .filter_map(Value::as_str)
                        .filter(|line| line.starts_with('('))
                        .collect::<Vec<_>>()
                        .join(" ")
                })
            })
            .unwrap_or_default()
    }

    async fn step(&mut self, line: &str, expect: &Expect) -> Verdict {
        let outcome = self.execute(line).await;
        if let Some(text) = &expect.refused {
            return match &outcome.error {
                Some(error) if error.message.contains(text.as_str()) => Verdict::Pass,
                Some(error) => Verdict::Fail(format!("refused, but with: {}", error.message)),
                None => Verdict::Fail("succeeded; expected a refusal".to_owned()),
            };
        }
        let Some(result) = &outcome.result else {
            let message = outcome.error.map_or_else(String::new, |error| error.message);
            return Verdict::Fail(format!("failed: {message}"));
        };
        let mut failures = Vec::new();
        if let Some(title) = &expect.paused {
            let paused = result["kind"] == "paused"
                && result["title"].as_str().is_some_and(|t| t.contains(title.as_str()));
            if !paused {
                failures.push(format!("did not stop at {title}: {}", result["title"]));
            }
        }
        if let Some(texts) = &expect.contains {
            let lines = text_of(result);
            for text in texts {
                if !lines.contains(text.as_str()) {
                    failures.push(format!("output lacks {text:?}"));
                }
            }
        }
        if expect.queries() {
            failures.extend(self.judge_query(result, expect).await);
        }
        if let Some(expected) = &expect.sizes {
            match self.sizes().await {
                Err(message) => failures.push(format!("cannot list relations: {message}")),
                Ok(sizes) => {
                    for (relation, rows) in expected {
                        match sizes.get(relation) {
                            Some(actual) if actual == rows => {}
                            actual => failures.push(format!(
                                "{relation} has {} rows, expected {rows}",
                                actual.map_or("no".to_owned(), u64::to_string)
                            )),
                        }
                    }
                }
            }
        }
        if failures.is_empty() {
            Verdict::Pass
        } else {
            Verdict::Fail(failures.join("; "))
        }
    }

    async fn judge_query(&mut self, result: &Value, expect: &Expect) -> Vec<String> {
        let mut failures = Vec::new();
        let mode = result["query-mode"].as_str().unwrap_or("");
        let matched = result["query-matched"].as_u64();
        // A count that hit the work budget is printed with a trailing `+`.
        let exact = !text_of(result).contains("+ row");
        let rows = if mode == "rows" {
            match self.all_rows(result).await {
                Ok(rows) => Some(rows),
                Err(message) => {
                    failures.push(message);
                    None
                }
            }
        } else {
            None
        };
        let count = match (mode, &rows) {
            ("rows", Some(rows)) => Some(rows.len() as u64),
            ("count" | "exists", _) if exact => matched,
            _ => None,
        };
        if let Some(expected) = expect.count
            && count != Some(expected)
        {
            failures.push(match count {
                Some(count) => format!("{count} answers, expected {expected}"),
                None => format!("no exact count (query mode {mode:?}); expected {expected}"),
            });
        }
        if let Some(expected) = expect.exists
            && count.map(|count| count > 0) != Some(expected)
        {
            failures.push(format!("exists is {:?}, expected {expected}", count.map(|count| count > 0)));
        }
        let actual: BTreeSet<String> = rows.into_iter().flatten().collect();
        if let Some(expected) = &expect.rows {
            let expected: BTreeSet<String> = expected.iter().map(|row| normalize(row)).collect();
            let missing: Vec<_> = expected.difference(&actual).take(5).collect();
            let unexpected: Vec<_> = actual.difference(&expected).take(5).collect();
            if !missing.is_empty() || !unexpected.is_empty() {
                failures.push(format!("rows differ: missing {missing:?}, unexpected {unexpected:?}"));
            }
        }
        if let Some(included) = &expect.rows_include {
            let missing: Vec<_> = included
                .iter()
                .map(|row| normalize(row))
                .filter(|row| !actual.contains(row))
                .take(5)
                .collect();
            if !missing.is_empty() {
                failures.push(format!("rows lack {missing:?}"));
            }
        }
        failures
    }

    /// The rows of a `?` answer, following `more` until the cursor is done.
    async fn all_rows(&mut self, first: &Value) -> Result<Vec<String>, String> {
        let mut rows = page_rows(first);
        let mut page = first.clone();
        while page["query-status"] == "open" {
            if rows.len() >= MAX_ROWS {
                let _ = self.execute("cancel").await;
                return Err(format!("more than {MAX_ROWS} rows; assert a count instead"));
            }
            let outcome = self.execute("more").await;
            page = outcome.result.ok_or_else(|| {
                format!("more failed: {}", outcome.error.map_or_else(String::new, |error| error.message))
            })?;
            rows.extend(page_rows(&page));
        }
        Ok(rows)
    }
}

fn text_of(result: &Value) -> String {
    result["lines"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(Value::as_str)
        .collect::<Vec<_>>()
        .join("\n")
}

/// A page's rows: its "N  (…)" lines, without the index, value handles, or
/// spacing differences.
fn page_rows(page: &Value) -> Vec<String> {
    page["lines"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(Value::as_str)
        .filter_map(|line| {
            let line = line.trim_start();
            let rest = line.trim_start_matches(|c: char| c.is_ascii_digit());
            // The header ("3 rows") also starts with a number.
            let tuple = rest.trim_start();
            (rest.len() < line.len() && tuple.len() < rest.len() && tuple.starts_with('('))
                .then(|| normalize(tuple))
        })
        .collect()
}

/// A row as text compared across runs: whitespace collapsed outside
/// strings, and value handles (`#3`, numbered per session) dropped.
fn normalize(row: &str) -> String {
    let mut out = String::new();
    let mut chars = row.trim().chars().peekable();
    let mut in_string = false;
    while let Some(c) = chars.next() {
        if in_string {
            out.push(c);
            match c {
                '\\' => out.extend(chars.next()),
                '"' => in_string = false,
                _ => {}
            }
        } else if c == '"' {
            in_string = true;
            out.push(c);
        } else if c.is_whitespace() {
            while chars.next_if(|c| c.is_whitespace()).is_some() {}
            // ` #12` is a value handle, not part of the value.
            let mut probe = chars.clone();
            if probe.next() == Some('#') && probe.peek().is_some_and(char::is_ascii_digit) {
                chars.next();
                while chars.next_if(char::is_ascii_digit).is_some() {}
                continue;
            }
            if !out.is_empty() && !out.ends_with('(') && chars.peek() != Some(&')') {
                out.push(' ');
            }
        } else {
            out.push(c);
        }
    }
    out
}

#[cfg(test)]
mod tests {
    use super::{Scenario, normalize, run};
    use slog_repl::server::project_root;
    use std::path::Path;

    #[test]
    fn rows_compare_without_spacing_or_value_handles() {
        assert_eq!(normalize("  (path  1\t2) "), "(path 1 2)");
        assert_eq!(normalize("(prog (add (num 1) (var \"x  y\")) #12)"), "(prog (add (num 1) (var \"x  y\")))");
        assert_eq!(normalize("( a \"q\\\" #1\" )"), "(a \"q\\\" #1\")");
    }

    #[test]
    fn validation_rejects_scenarios_that_cannot_mean_what_they_say() {
        let base = "format = 2\nid = \"t\"\ntitle = \"t\"\n[program]\nmain = \"p.slog\"\n";
        let with = |rest: &str| Scenario::parse(&format!("{base}{rest}")).map(|_| ());
        assert!(with("").is_ok());
        assert!(with("[[steps]]\nrun = \"tables\"\nexpect = { count = 3 }\n").is_err());
        assert!(with("[[steps]]\nrun = \"break path\"\n").is_err());
        assert!(with("[[steps]]\nrun = \"?(p X)\"\nexpect = { refused = \"x\", count = 1 }\n").is_err());
        assert!(with("[[checks]]\nname = \"c\"\nslog = \"\"\nempty = []\n").is_err());
        assert!(with("[[steps]]\nrun = \"?(p X)\"\nexpect = { cuont = 1 }\n").is_err());
    }

    /// The shipped example is a working scenario, so it stays one: every
    /// check and step passes, including its expected failure and its stop at
    /// a breakpoint.
    #[tokio::test]
    async fn the_reach_example_passes() {
        let root = project_root().expect("repository root");
        let path = Path::new(env!("CARGO_MANIFEST_DIR")).join("examples/reach/reach.scenario.toml");
        let report = run(&root, &path).await.expect("the scenario runs");
        let failures: Vec<_> = report
            .checks
            .iter()
            .chain(&report.steps)
            .filter(|judged| !judged.verdict.passed())
            .collect();
        assert!(report.setup.is_none(), "{:?}", report.setup);
        assert!(failures.is_empty(), "{failures:#?}");
        assert!(!report.steps.is_empty() && !report.checks.is_empty());
    }

    /// A scenario that is wrong fails, with the reason.
    #[tokio::test]
    async fn a_wrong_expectation_fails_with_the_difference() {
        let root = project_root().expect("repository root");
        let directory = std::env::temp_dir().join(format!("scenario-test-{}", std::process::id()));
        std::fs::create_dir_all(&directory).unwrap();
        std::fs::write(directory.join("p.slog"), "table (n int)\nrule (n 1) (n 2)\n").unwrap();
        std::fs::write(
            directory.join("p.scenario.toml"),
            "format = 2\nid = \"wrong\"\ntitle = \"wrong\"\n[program]\nmain = \"p.slog\"\n\
             [[checks]]\nname = \"spelled\"\nslog = \"\"\nempty = [\"nn\"]\n\
             [[steps]]\nrun = \"?(n X)\"\nexpect = { rows = [\"(n 1)\", \"(n 3)\"] }\n",
        )
        .unwrap();
        let report = run(&root, &directory.join("p.scenario.toml")).await.unwrap();
        std::fs::remove_dir_all(&directory).unwrap();
        let why = |judged: &super::Judged| match &judged.verdict {
            super::Verdict::Fail(why) => why.clone(),
            verdict => panic!("expected a failure, got {verdict:?}"),
        };
        assert!(why(&report.checks[0]).contains("no relation named nn"));
        assert!(why(&report.steps[0]).contains(r#"missing ["(n 3)"], unexpected ["(n 2)"]"#));
        assert!(!report.passed());
    }
}
