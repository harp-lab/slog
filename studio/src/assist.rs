//! The REPL's assistant: questions asked at the prompt (`?? …`), answered
//! inline in the transcript with commands the author can run or edit.
//!
//! Each question is a thread, as in the Ask drawer (ask.rs), and claude runs
//! it as it runs the Ask agent (agent.rs), with the same reference leading
//! its system prompt but its own persona and tools. Those tools read the
//! author's live session through commands that cannot change it, so a query
//! the assistant suggests has been tried. The same reads give the prompt its
//! live preview of a query being typed.

use crate::agent::{self, Agent, Kind};
use crate::knowledge;
use crate::results::{self, Total};
use crate::review::Message;
use crate::session::{Outcome, Session};
use crate::studio::Studio;
use serde::{Deserialize, Serialize};
use serde_json::{Value, json};
use std::fmt::Write;
use std::sync::Arc;
use std::time::Duration;

/// How the assistant works, after the reference in its system prompt.
pub const PERSONA: &str = "\
You are the assistant at the REPL prompt of Slog Studio. The author is exploring or debugging a \
live, evaluated Slog program in the REPL and asked you something; your reply appears inline in \
the REPL transcript, between their commands. The Slog reference above is your knowledge of the \
language and of its `?` query language.

- The message opens with the session: the program, its relations with row counts, the result \
sets (r1, r2, ... are relations holding earlier queries' answers, and can be queried), recent \
REPL lines with their errors, and any held run, breaks and watches.
- `repl` runs one read-only command in the author's session: `?` queries, `?count`, `?exists`, \
`tables`, `count REL`, `show REL`, `why (...)`, `whynot (...)`, `explain ?...`, `uses VALUE`, \
`breaks`, `watches`. Run every query you suggest before suggesting it, and fix it until it runs \
and answers what was asked: the author sees which you ran. The author is waiting, so make the \
calls you need at once, in parallel, and keep to a few.
- Answer briefly: a sentence or two, then the commands. No preamble, no headings.
- Put the commands you suggest in a ```repl block, one command per line, each optionally ending \
in a `;; comment` saying what it shows. The author runs or edits each with one click, and a query \
you ran shows its row count.
- When the author describes a bug -- a fact that should hold but does not, or rows that should \
not be there -- check it first (a query, `whynot (REL v ...)` or `why (REL v ...)`), then give a \
short diagnosis and a plan: one ```plan block of commands in the order to run them, each with a \
`;;` comment saying what to look for; the author ticks the steps off as they run them. Narrow to \
the rule and the missing or unexpected premise.
- Commands beyond queries, for plans: `whynot (REL v ...)` shows, per rule that writes REL, the \
first body position with nothing to match; `why (REL v ...)` the proof tree of a fact; `break \
REL [when (REL t|_ ...)]` or `break FILE:LINE` stops a run when a rule writes REL or fires; \
`watch REL` or `watch ?QUERY` reports a relation or a query's count on each change; `step`, \
`frames`, `peek REL`, `continue` and `abort` work on a held run; `add REL v ...` and `del REL v \
...` change an input fact and propagate it, which fires breaks and watches. Run (or Debug, with \
breakpoints set in the editor's margin) evaluates the program afresh in a new session, which \
drops REPL breaks and watches.
- When the answer is a change to the program -- the fix for a bug you diagnosed, a missing \
rule -- propose it with propose_edit (an exact, unique piece of the program text and its \
replacement) or propose_append (new forms at the end). It appears in the author's editor as a \
proposal to accept or reject. Every proposal is statically checked (parse, types, negation, \
strata) as the program it would leave: one that fails is refused with the located errors, so fix \
it and propose again. Then run evaluate_proposal -- the program as your proposal leaves it, in a \
fresh session apart from the author's -- and say in a line what you proposed and what the \
evaluation showed; do not repeat the change as a ```slog block. Show \
Slog you are not proposing as a ```slog block: it is checked against the program, and the author \
sees whether it checks.";

/// The steps a REPL turn may take.
pub const MAX_TURNS: u32 = 12;

/// How long the assistant waits for the lane when the author's own command
/// holds it.
const PATIENCE: Duration = Duration::from_secs(30);
/// Why a read did not run.
pub const BUSY: &str = "the session is busy with another command";
/// Rows a read shows of a query's answers.
const SHOWN_ROWS: usize = 8;
/// Lines a read shows of any other command's answer.
const SHOWN_LINES: usize = 60;
/// How much of the program a question carries; get_program has the rest.
const PROGRAM_CHARS: usize = 24_000;

/// What the prompt knows of the session that the studio does not keep: its
/// transcript, catalog, and listings.
#[derive(Debug, Default, Deserialize)]
pub struct Context {
    /// The latest REPL lines, oldest first.
    #[serde(default)]
    pub recent: Vec<Line>,
    /// The relations of the last `tables`.
    #[serde(default)]
    pub relations: Vec<Relation>,
    #[serde(default)]
    pub breaks: Vec<String>,
    #[serde(default)]
    pub watches: Vec<String>,
    /// Where a held run stopped.
    #[serde(default)]
    pub held: Option<String>,
    /// The line the question is about ("Ask why").
    #[serde(default)]
    pub focus: Option<Line>,
}

#[derive(Debug, Deserialize)]
pub struct Line {
    pub line: String,
    #[serde(default)]
    pub error: Option<String>,
    /// The answer's text, cut short.
    #[serde(default)]
    pub output: Option<String>,
}

#[derive(Debug, Deserialize)]
pub struct Relation {
    pub name: String,
    #[serde(default)]
    pub detail: Vec<String>,
    #[serde(default)]
    pub rows: Option<u64>,
}

/// What a read found: a query's total and first rows, or a command's lines.
#[derive(Debug, Default, Serialize)]
pub struct Read {
    pub line: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub total: Option<Total>,
    /// The query page's title: `Query`, or `Query · (X Z)` naming the
    /// projection's columns.
    #[serde(skip_serializing_if = "String::is_empty")]
    pub title: String,
    #[serde(skip_serializing_if = "Vec::is_empty")]
    pub rows: Vec<String>,
    #[serde(skip_serializing_if = "Vec::is_empty")]
    pub lines: Vec<String>,
}

impl Studio {
    /// Ask the REPL's assistant, following up in `thread` or starting a new
    /// one. Returns its id; the run's progress arrives as agent events.
    pub fn assist(self: &Arc<Self>, thread: Option<u32>, message: String, context: Context) -> Result<u32, String> {
        if let Some(why) = Agent::unavailable() {
            return Err(why);
        }
        let message = message.trim().to_owned();
        if message.is_empty() {
            return Err("ask something".to_owned());
        }
        let mut review = self.review.lock().expect("review lock");
        let thread = match thread.filter(|id| review.thread(*id).is_some_and(|thread| thread.repl)) {
            Some(id) if self.agent.is_running(id) => {
                return Err("still answering: wait for it, or press Esc and ask anew".to_owned());
            }
            Some(id) => id,
            None => {
                let id = review.new_thread(agent::title_of(&message));
                review.thread_mut(id).expect("the thread exists").repl = true;
                id
            }
        };
        let entry = review.thread_mut(thread).expect("the thread exists");
        entry.messages.push(Message::new("user", &message, Value::Null));
        entry.running = true;
        // What it proposes in answer to this question is one changeset.
        review.open_changeset(thread, agent::title_of(&message));
        drop(review);
        self.publish_review();
        let context = self.session_context(&context);
        tokio::spawn(agent::run(self.clone(), Kind::Repl, thread, message, context));
        Ok(thread)
    }

    /// Whether `thread` is the REPL assistant's.
    pub(crate) fn is_repl_thread(&self, thread: u32) -> bool {
        self.review.lock().expect("review lock").thread(thread).is_some_and(|thread| thread.repl)
    }

    /// The session as a question's preamble.
    fn session_context(&self, context: &Context) -> String {
        let (_, program) = self.main_file();
        let sets: Vec<String> = self
            .result_views()
            .into_iter()
            .filter(|set| !set.stale)
            .map(|set| {
                let total = match set.total {
                    Total::Exact(n) => format!("{n} rows"),
                    Total::AtLeast(n) => format!("{n}+ rows"),
                    Total::Unknown => "rows uncounted".to_owned(),
                };
                let columns: Vec<String> =
                    set.columns.iter().map(|column| column.var.clone().unwrap_or_else(|| "_".to_owned())).collect();
                match set.relation {
                    Some(relation) => format!("{relation}({}) = {} · {total}", columns.join(" "), set.query),
                    None => format!("{} = {} · {total}", set.id, set.query),
                }
            })
            .collect();
        preamble(&self.main_name(), &program, &sets, context)
    }

    // ---- tools (mcp.rs) --------------------------------------------------

    pub(crate) async fn assist_tool(&self, name: &str, arguments: &Value) -> Result<Value, String> {
        let text = |key: &str| arguments[key].as_str().ok_or_else(|| format!("missing string argument `{key}`"));
        match name {
            "repl" => {
                let read = self.read(text("line")?, PATIENCE).await?;
                serde_json::to_value(read).map_err(|error| error.to_string())
            }
            "get_program" => {
                let (_, text) = self.main_file();
                Ok(json!({ "file": self.main_name(), "text": text }))
            }
            "search_docs" => Ok(knowledge::search(self.lane.root(), text("query")?, 8)),
            "read_doc" => {
                let number = |key: &str, default: u64| arguments[key].as_u64().unwrap_or(default) as usize;
                knowledge::read(self.lane.root(), text("path")?, number("start", 1), number("lines", 200))
            }
            _ => Err(format!("unknown tool {name}")),
        }
    }

    /// Run a read-only `line` in the author's session, apart from the
    /// transcript. A `?` query's answer is its total and first rows; its
    /// cursor is not left open, so `more` still means the author's own.
    pub(crate) async fn read(&self, line: &str, patience: Duration) -> Result<Read, String> {
        let line = line.trim();
        read_only(line)?;
        let mut session = self.aside(patience).await.ok_or(BUSY)?;
        let answer = |outcome: Outcome| outcome.result.ok_or_else(|| {
            outcome.error.map_or_else(|| "no answer".to_owned(), |error| error.message)
        });
        let result = answer(session.execute(&self.lane, line).await)?;
        let mut read = Read { line: line.to_owned(), ..Read::default() };
        match result["query-mode"].as_str() {
            Some("rows") => {
                read.title = result["title"].as_str().unwrap_or("").to_owned();
                read.rows = strings(&result["lines"])
                    .filter_map(|text| results::row_line(text).map(|(_, tuple)| tuple.to_owned()))
                    .take(SHOWN_ROWS)
                    .collect();
                let shown = result["query-shown"].as_u64().unwrap_or(0);
                read.total = Some(match result["query-status"].as_str() {
                    Some("complete") => Total::Exact(shown),
                    Some("open") => count(&mut session, self, line).await,
                    _ => Total::AtLeast(shown),
                });
            }
            Some("count") => read.total = Total::of_count(&result),
            _ => {
                read.title = result["title"].as_str().unwrap_or("").to_owned();
                read.lines = match result["relations"].as_array() {
                    // `tables`: its relations, as the preamble lists them
                    Some(relations) => relations
                        .iter()
                        .map(|r| format!("{}({}) · {} rows", str_of(&r["name"]), strings(&r["detail"]).collect::<Vec<_>>().join(" "), r["rows"]))
                        .collect(),
                    None => strings(&result["lines"]).take(SHOWN_LINES).map(str::to_owned).collect(),
                };
            }
        }
        Ok(read)
    }
}

/// The total of an open query, by its `?count`, which also discards the
/// cursor the page left open.
pub(crate) async fn count(session: &mut Session, studio: &Studio, line: &str) -> Total {
    let Some(count) = results::count_line(line) else {
        let _ = session.execute(&studio.lane, "cancel").await;
        return Total::Unknown;
    };
    let counted = session.execute(&studio.lane, &count).await;
    counted.result.as_ref().and_then(Total::of_count).unwrap_or(Total::Unknown)
}

fn str_of(value: &Value) -> &str {
    value.as_str().unwrap_or("")
}

fn strings(value: &Value) -> impl Iterator<Item = &str> {
    value.as_array().into_iter().flatten().filter_map(Value::as_str)
}

/// The commands a read may run: ones that observe the session and never
/// change it, hold a cursor past the read, or start a run.
const READ_ONLY: [&str; 18] = [
    "tables", "state", "count", "show", "query", "has", "uses", "find", "why", "whynot", "explain",
    "breaks", "watches", "scratch", "current", "catalog", "tiers", "peek",
];

pub(crate) fn read_only(line: &str) -> Result<(), String> {
    let verb = line.split_whitespace().next().unwrap_or("");
    if line.starts_with('?') && line.len() > 1 {
        return Ok(());
    }
    if READ_ONLY.contains(&verb) {
        return Ok(());
    }
    Err(format!(
        "`{verb}` is not a read: only queries and {} run here; suggest anything else for the author to run",
        READ_ONLY.join(", ")
    ))
}

/// A question's preamble: what the author's session holds. `sets` are the
/// result sets, described.
pub(crate) fn preamble(file: &str, program: &str, sets: &[String], context: &Context) -> String {
    let mut out = String::from("(Slog Studio REPL session.)\n");
    let cut = cut(program, PROGRAM_CHARS);
    let more = if cut.len() < program.len() { "\n;; … cut short: get_program reads it all" } else { "" };
    let _ = writeln!(out, "The program, {file}, evaluated in the session:\n```slog\n{}{more}\n```", cut.trim_end());
    if !context.relations.is_empty() {
        let relations: Vec<String> = context
            .relations
            .iter()
            .map(|r| {
                let rows = r.rows.map(|n| format!(" · {n} rows")).unwrap_or_default();
                format!("{}({}){rows}", r.name, r.detail.join(" "))
            })
            .collect();
        let _ = writeln!(out, "Relations: {}", relations.join("; "));
    }
    if !sets.is_empty() {
        let _ = writeln!(out, "Result sets: {}", sets.join("; "));
    }
    if let Some(held) = &context.held {
        let _ = writeln!(out, "A run is held: {held}");
    }
    for (name, items) in [("Breaks", &context.breaks), ("Watches", &context.watches)] {
        if !items.is_empty() {
            let _ = writeln!(out, "{name}: {}", items.join("; "));
        }
    }
    if !context.recent.is_empty() {
        let _ = writeln!(out, "Recent REPL lines, oldest first:");
        for line in &context.recent {
            describe(&mut out, line);
        }
    }
    if let Some(focus) = &context.focus {
        let _ = writeln!(out, "The question is about this line:");
        describe(&mut out, focus);
    }
    out.push_str("The author asks:");
    out
}

fn describe(out: &mut String, line: &Line) {
    let _ = writeln!(out, "› {}", line.line.trim());
    if let Some(error) = &line.error {
        let _ = writeln!(out, "  error: {}", cut(error, 600));
    } else if let Some(output) = line.output.as_deref().filter(|output| !output.is_empty()) {
        for text in cut(output, 600).lines() {
            let _ = writeln!(out, "  {text}");
        }
    }
}

/// At most `limit` bytes of `text`, cut at a character boundary.
fn cut(text: &str, limit: usize) -> &str {
    if text.len() <= limit {
        return text;
    }
    let mut end = limit;
    while !text.is_char_boundary(end) {
        end -= 1;
    }
    &text[..end]
}

/// The tools a REPL thread's run has.
pub fn tools() -> Value {
    let object = |properties: Value, required: &[&str]| {
        json!({ "type": "object", "properties": properties, "required": required })
    };
    // It proposes changes, and evaluates them, as the Ask agent does (mcp.rs).
    let proposing = crate::mcp::tools()
        .as_array()
        .into_iter()
        .flatten()
        .filter(|tool| matches!(tool["name"].as_str(), Some("propose_edit" | "propose_append" | "evaluate_proposal")))
        .cloned()
        .collect::<Vec<_>>();
    let mut tools = json!([
        {
            "name": "repl",
            "description": "Run one read-only command in the author's live REPL session and see its answer: a query (`?(path 1 Y)`, `? (edge X Y) (edge Y Z) -> (X Z)`, `?count (path X _)`, `?exists ...`), or `tables`, `count REL`, `show REL`, `why (REL v ...)`, `whynot (REL v ...)`, `explain ?...`, `uses VALUE`, `breaks`, `watches`, `state REL`. A `?` query answers its total and first rows. Commands that would change the session are refused.",
            "inputSchema": object(json!({
                "line": { "type": "string", "description": "The command, as typed at the prompt." },
            }), &["line"]),
        },
        {
            "name": "get_program",
            "description": "The whole program file, when the question's copy was cut short.",
            "inputSchema": object(json!({}), &[]),
        },
        {
            "name": "search_docs",
            "description": "Search Slog's documentation, standard library, examples and tests for words; returns the best-matching paragraphs with file and line. For what the reference does not cover.",
            "inputSchema": object(json!({
                "query": { "type": "string", "description": "Words or a phrase to find." },
            }), &["query"]),
        },
        {
            "name": "read_doc",
            "description": "Read lines of a documentation file or example program that search_docs named.",
            "inputSchema": object(json!({
                "path": { "type": "string", "description": "Repository-relative path." },
                "start": { "type": "integer", "description": "First line, 1-based (default 1)." },
                "lines": { "type": "integer", "description": "How many lines (default 200, at most 400)." },
            }), &["path"]),
        },
    ]);
    tools.as_array_mut().expect("a list").extend(proposing);
    tools
}

#[cfg(test)]
mod tests {
    use super::{Context, Line, Relation, preamble, read_only};
    use crate::lane::Mode;
    use crate::store::tests::Scratch;
    use crate::studio::tests::studio;
    use std::time::Duration;

    #[test]
    fn reads_are_queries_and_observations_only() {
        for line in ["?(path 1 Y)", "?count (path X _)", "tables", "whynot (path 1 5)", "show edge", "explain ?(a X)"] {
            assert!(read_only(line).is_ok(), "{line}");
        }
        for line in ["?", "add edge 1 2", "rule (p 1)", "break path", "continue", "run x.slog", "more", "tablesx"] {
            assert!(read_only(line).is_err(), "{line}");
        }
    }

    #[test]
    fn the_preamble_carries_the_session_and_the_line_in_question() {
        let context = Context {
            recent: vec![Line { line: "?(pth X)".into(), error: Some("no relation pth".into()), output: None }],
            relations: vec![Relation { name: "path".into(), detail: vec!["int".into(), "int".into()], rows: Some(3) }],
            held: Some("Paused · break b1".into()),
            focus: Some(Line { line: "tables".into(), error: None, output: Some("path 3".into()) }),
            ..Context::default()
        };
        let text = preamble("main.slog", "table (path int int)\n", &["r1(Y) = ?(path 1 Y) · 2 rows".into()], &context);
        for part in [
            "```slog\ntable (path int int)\n```",
            "Relations: path(int int) · 3 rows",
            "Result sets: r1(Y) = ?(path 1 Y) · 2 rows",
            "A run is held: Paused · break b1",
            "› ?(pth X)\n  error: no relation pth",
            "about this line:\n› tables\n  path 3",
        ] {
            assert!(text.contains(part), "{part} in\n{text}");
        }
        assert!(text.ends_with("The author asks:"));
    }

    /// A read answers a query with its total and first rows, leaves no
    /// cursor behind for `more` to continue, and refuses to change the
    /// session.
    #[tokio::test]
    async fn a_read_counts_a_query_and_leaves_the_session_as_it_was() {
        let scratch = Scratch::new("assist-read");
        let facts: String = (1..=60).map(|n| format!("rule (n {n})\n")).collect();
        let studio = studio(&scratch, Mode::Fast, &format!("table (n int)\n{facts}"));
        studio.evaluate().await;
        let wait = Duration::from_secs(60);

        let read = studio.read("?(n X)", wait).await.expect("a read");
        assert_eq!(read.total, Some(super::Total::Exact(60)));
        assert_eq!(read.rows.len(), super::SHOWN_ROWS);
        let more = studio.read("?count (n X)", wait).await.unwrap();
        assert_eq!(more.total, Some(super::Total::Exact(60)));
        assert!(studio.read("add n 61", wait).await.is_err());
        let tables = studio.read("tables", wait).await.unwrap();
        assert!(tables.lines.contains(&"n(int) · 60 rows".to_owned()), "{:?}", tables.lines);
        let mut events = studio.subscribe();
        studio.command("more").await;
        let refused = std::iter::from_fn(|| events.try_recv().ok()).any(|event| {
            matches!(event, crate::studio::Event::Entry { outcome, .. } if outcome.error.is_some())
        });
        assert!(refused, "no cursor was left open");
        studio.lane.shutdown().await;
    }
}
