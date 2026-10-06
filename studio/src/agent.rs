//! The in-app agent: headless `claude` runs that change the program through
//! this server's own `/mcp` endpoint (mcp.rs), the way the slides app's
//! agent edits decks. It is just another MCP client: everything it writes is
//! a proposal the author accepts or rejects (review.rs).
//!
//! Each question the author asks is a thread: its own claude session
//! (resumed for follow-ups), transcript, and changesets, one per turn.
//! Threads run in parallel. The MCP config each run gets carries a header
//! naming its thread, so the server attributes its proposals. Progress
//! streams to every tab as `Event::Agent`.

use crate::knowledge;
use crate::review::Message;
use crate::studio::{Event, Studio};
use serde::Serialize;
use serde_json::{Value, json};
use std::collections::{HashMap, HashSet};
use std::path::{Path, PathBuf};
use std::process::Stdio;
use std::sync::{Arc, Mutex};
use std::time::Instant;
use tokio::io::{AsyncBufReadExt, AsyncReadExt, BufReader};
use tokio::process::{Child, Command};

/// The header a run's MCP config carries: its thread id.
pub const THREAD_HEADER: &str = "x-studio-thread";

/// How the agent works. With the reference (knowledge.rs) it makes the
/// system prompt, which stays the same for every run and every thread so
/// that runs share its prompt cache; what differs per run goes in the
/// message.
const PERSONA: &str = "\
You are the programming agent inside Slog Studio, building a Slog program together with its \
author, who is watching the editor and often dictates. The Slog reference above is your \
knowledge of the language: follow it. The `slog` MCP tools are your only way to read or change \
the program and to look anything up.

Knowing Slog -- never guess syntax:
- Write only syntax, primitives, and idioms the reference shows. Before using anything it does \
not cover, search_docs for it (e.g. `cput`, `lattice soundness`, `instantiate`) and read_doc the \
passage or a whole example; list_examples names complete programs worth copying from \
(examples/ for analyses, tests/ for one feature each).
- When evaluate_proposal reports an error, find its message in the reference's section on \
compile errors before changing anything, and fix the cause it names.

How to work -- the author is waiting:
- Read once (get_program), then propose. Make form-sized changes: propose_edit replaces an exact, \
unique piece of the current program text (include enough context to be unique); propose_append \
adds new forms at the end. Declare a relation before rules use it. Give every proposal a \
one-sentence `note` saying what it does and why.
- Then check your work: evaluate_proposal runs the program as your proposals would leave it, in \
a fresh session, and reports its relations and row counts or its errors; query runs a `?` query \
against that evaluation, e.g. `?(eval E V)` or `? (path X Y) (edge Y Z) -> (X Z)`, within the \
limits the reference lists. Fix what you broke before you reply, and cite the evidence (row \
counts, a sample row) in your reply.
- When something derives wrongly, trace it before guessing: trace_run shows each stratum's \
iterations and signed deltas, get_trace the rows behind them, and debug_run stops at your \
breakpoints; cite the iteration or rule that explains the bug.
- Your proposals are not applied until the author accepts them. Each of your turns is one \
changeset; proposing the same text again in a later turn builds on your earlier proposals.
- The author dictates: read requests charitably, honour self-corrections (\"or sorry, a data \
type\"), ignore filler. When a request is ambiguous, propose the most plausible reading and name \
the alternative in your reply instead of asking.
- Other threads may be proposing changes too; leave theirs alone. Where two threads change the \
same text the author settles it.
- Reply when done with a short summary of what you proposed and what you checked. No preamble.";

/// What a run can do besides the `slog` tools, appended to the persona.
const RESEARCH: &str = "\
## Research, plans and notes
- Read, Grep and Glob read Slog's own repository -- your working directory: compiler/, docs/, \
examples/, tests/ -- and the project's directory. Nothing you can run writes a file: every change \
to the program is a proposal.
- WebSearch and WebFetch find papers, Datalog techniques and documentation; say what you used.
- For work of several steps, keep a short plan with your task tools (TaskCreate and TaskUpdate, or \
TodoWrite); the author watches it as a checklist.
- record_note keeps a finding or decision with this thread -- why a rule is stratified the way it \
is, what a design choice rests on; get_notes reads them back in later turns.
- Task runs subagents with the same read-only tools, for investigations that split cleanly.
- Write replies in Markdown, with Slog in ```slog fences.";

/// The built-in tools a run has: research that reads, never writes.
const TOOLS: &str = "Read,Grep,Glob,WebSearch,WebFetch,TodoWrite,TaskCreate,TaskUpdate,TaskList,TaskGet,Task,Agent";
/// Refused even if a setting would allow them.
const DENIED: &str = "Bash,Write,Edit,NotebookEdit,Skill";
/// Tools whose calls make the turn's plan rather than transcript entries.
const PLAN_TOOLS: [&str; 5] = ["TodoWrite", "TaskCreate", "TaskUpdate", "TaskList", "TaskGet"];
/// Claude Code's own plumbing, never shown.
const HIDDEN_TOOLS: [&str; 1] = ["ToolSearch"];
/// How much of a tool's input string or result a transcript keeps.
const CLIP: usize = 4000;

pub struct Agent {
    /// The bearer token `/mcp` requires; it never leaves this machine except
    /// in the 0600 config file a run reads.
    pub mcp_token: String,
    model: Option<String>,
    effort: String,
    /// The claude process of every run in flight, by thread.
    running: Mutex<HashMap<u32, Child>>,
    /// Threads whose run the author stopped, so its end is no failure.
    stopped: Mutex<HashSet<u32>>,
}

#[derive(Clone, Debug, Serialize)]
pub struct AgentEvent {
    pub thread: u32,
    /// "start"; "phase" (what the run is doing: "thinking", "replying" or
    /// "tool NAME"); "delta" and "thinking" (streamed text of the reply or
    /// the thought in progress); "entry" (transcript entry `index`, new or
    /// changed); or "done".
    pub kind: &'static str,
    #[serde(skip_serializing_if = "String::is_empty")]
    pub text: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub index: Option<usize>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub entry: Option<Message>,
}

impl Agent {
    pub fn new(mcp_token: String) -> Self {
        Self {
            mcp_token,
            // The CLI's own default model unless the operator picks one.
            model: std::env::var("STUDIO_AGENT_MODEL").ok().filter(|model| !model.is_empty()),
            effort: std::env::var("STUDIO_AGENT_EFFORT").unwrap_or_else(|_| "high".to_owned()),
            running: Mutex::new(HashMap::new()),
            stopped: Mutex::new(HashSet::new()),
        }
    }

    /// Why the agent cannot run, if it cannot.
    pub fn unavailable() -> Option<String> {
        which("claude")
            .is_none()
            .then(|| "no `claude` on PATH: install Claude Code to ask the agent".to_owned())
    }

    pub fn is_running(&self, thread: u32) -> bool {
        self.running.lock().expect("agent lock").contains_key(&thread)
    }

    pub fn stop(&self, thread: u32) -> bool {
        let killed = self
            .running
            .lock()
            .expect("agent lock")
            .get_mut(&thread)
            .is_some_and(|child| child.start_kill().is_ok());
        if killed {
            self.stopped.lock().expect("agent lock").insert(thread);
        }
        killed
    }

    /// The MCP config for one run (mode 0600): our loopback `/mcp`, the
    /// bearer token, and the header naming the thread.
    fn write_config(&self, port: u16, thread: u32) -> Result<PathBuf, String> {
        use std::io::Write;
        use std::os::unix::fs::OpenOptionsExt;
        let config = json!({ "mcpServers": { "slog": {
            "type": "http",
            "url": format!("http://127.0.0.1:{port}/mcp"),
            "headers": {
                "Authorization": format!("Bearer {}", self.mcp_token),
                "X-Studio-Thread": thread.to_string(),
            },
        }}});
        let path = std::env::temp_dir().join(format!("slog-studio-mcp-{}-{thread}.json", std::process::id()));
        std::fs::OpenOptions::new()
            .write(true)
            .create(true)
            .truncate(true)
            .mode(0o600)
            .open(&path)
            .and_then(|mut file| file.write_all(config.to_string().as_bytes()))
            .map_err(|error| format!("cannot write the MCP config: {error}"))?;
        Ok(path)
    }
}

/// The first line of a request, cut to a title's length.
pub fn title_of(message: &str) -> String {
    let line = message.lines().find(|line| !line.trim().is_empty()).unwrap_or("").trim();
    let title: String = line.chars().take(72).collect();
    if title.len() < line.len() {
        format!("{}…", title.trim_end())
    } else {
        title
    }
}

/// One thread's transcript as a run writes it: each change is kept by the
/// studio and streamed to every tab.
struct Transcript<'a> {
    studio: &'a Studio,
    thread: u32,
}

impl Transcript<'_> {
    fn event(&self, kind: &'static str, text: impl Into<String>) {
        self.studio.publish(Event::Agent(AgentEvent {
            thread: self.thread,
            kind,
            text: text.into(),
            index: None,
            entry: None,
        }));
    }

    fn show(&self, index: usize, entry: Message) {
        self.studio.publish(Event::Agent(AgentEvent {
            thread: self.thread,
            kind: "entry",
            text: String::new(),
            index: Some(index),
            entry: Some(entry),
        }));
    }

    fn push(&self, role: &str, text: &str, data: Value) -> usize {
        let entry = Message::new(role, text, data);
        let index = self.studio.thread_push(self.thread, entry.clone());
        self.show(index, entry);
        index
    }

    fn update(&self, index: usize, change: impl FnOnce(&mut Message)) {
        if let Some(entry) = self.studio.thread_update(self.thread, index, change) {
            self.show(index, entry);
        }
    }
}

/// One turn of `thread`: run claude until it finishes, streaming its
/// progress, then close the turn's changeset. `context` (the program's
/// name, say) leads the message, not the system prompt, which stays fixed.
pub async fn run(studio: Arc<Studio>, thread: u32, message: String, context: String) {
    let transcript = Transcript { studio: &studio, thread };
    let agent = &studio.agent;
    let config = match agent.write_config(studio.port(), thread) {
        Ok(path) => path,
        Err(error) => {
            transcript.push("error", &error, Value::Null);
            studio.finish_turn(thread);
            transcript.event("done", "");
            return;
        }
    };
    // Research reads Slog's own repository, and the project's directory
    // when it lies elsewhere.
    let root = studio.lane.root().to_path_buf();
    let project = studio.main_file().0.parent().map(Path::to_path_buf);
    let mut resume = studio.thread_session(thread);
    loop {
        let mut args: Vec<String> = vec![
            "-p".into(), format!("{context}\n{message}"),
            "--output-format".into(), "stream-json".into(), "--verbose".into(),
            // Partial events show "thinking…" / "calling query…" while a turn runs.
            "--include-partial-messages".into(),
            "--effort".into(), agent.effort.clone(),
            "--disable-slash-commands".into(),
            // Only the operator's own settings: none of the repository's.
            "--setting-sources".into(), "user".into(),
            "--mcp-config".into(), config.to_string_lossy().into_owned(), "--strict-mcp-config".into(),
            "--tools".into(), TOOLS.into(),
            "--allowedTools".into(), format!("mcp__slog,{TOOLS}"),
            "--disallowedTools".into(), DENIED.into(),
            "--max-turns".into(), "40".into(),
            "--append-system-prompt".into(), format!("{}\n\n{PERSONA}\n\n{RESEARCH}", knowledge::REFERENCE),
            // Keep the machine's details (cwd, date, ...) out of the system
            // prompt too, for the same cache.
            "--exclude-dynamic-system-prompt-sections".into(),
        ];
        if let Some(project) = project.as_ref().filter(|project| !project.starts_with(&root)) {
            args.extend(["--add-dir".to_owned(), project.to_string_lossy().into_owned()]);
        }
        if let Some(model) = &agent.model {
            args.extend(["--model".to_owned(), model.clone()]);
        }
        if let Some(session) = &resume {
            args.extend(["--resume".to_owned(), session.clone()]);
        }
        transcript.event("start", "");
        let mut child = match Command::new("claude")
            .args(&args)
            .current_dir(&root)
            .stdin(Stdio::null())
            .stdout(Stdio::piped())
            .stderr(Stdio::piped())
            .kill_on_drop(true)
            .spawn()
        {
            Ok(child) => child,
            Err(error) => {
                transcript.push("error", &format!("could not start claude: {error}"), Value::Null);
                break;
            }
        };
        let stdout = child.stdout.take().expect("piped stdout");
        let mut stderr = child.stderr.take().expect("piped stderr");
        agent.running.lock().expect("agent lock").insert(thread, child);
        let stderr_text = tokio::spawn(async move {
            let mut text = String::new();
            let _ = stderr.read_to_string(&mut text).await;
            text
        });

        let mut lines = BufReader::new(stdout).lines();
        let mut stream = Stream { effort: agent.effort.clone(), ..Stream::default() };
        while let Ok(Some(line)) = lines.next_line().await {
            if let Ok(event) = serde_json::from_str::<Value>(&line) {
                stream.read(&event, &transcript);
            }
        }
        let child = agent.running.lock().expect("agent lock").remove(&thread);
        let status = match child {
            Some(mut child) => child.wait().await.ok(),
            None => None,
        };
        let stderr_text = stderr_text.await.unwrap_or_default();
        if agent.stopped.lock().expect("agent lock").remove(&thread) {
            transcript.push("notice", "stopped", Value::Null);
            break;
        }
        let failed = !stream.got_result && !status.is_some_and(|status| status.success());
        if failed && resume.is_some() {
            // A stale session id (its transcript gone) is the usual cause.
            studio.set_thread_session(thread, None);
            resume = None;
            transcript.push("notice", "could not resume the conversation; starting a new one", Value::Null);
            continue;
        }
        if failed {
            let message = format!(
                "claude exited without a result{}",
                stderr_text
                    .lines()
                    .rev()
                    .find(|line| !line.trim().is_empty())
                    .map(|line| format!(": {line}"))
                    .unwrap_or_default()
            );
            transcript.push("error", &message, Value::Null);
        }
        break;
    }
    let _ = std::fs::remove_file(&config);
    studio.finish_turn(thread);
    transcript.event("done", "");
}

/// What a turn's stream-json has shown so far, made into transcript entries:
/// replies, thoughts, tool calls with their results, the plan, and the
/// turn's closing line.
#[derive(Default)]
struct Stream {
    effort: String,
    model: String,
    /// The thought being streamed: its block's index, when it began, its
    /// text, and the tokens it is estimated to have used.
    thinking: Option<(u64, Instant, String, u64)>,
    /// Tool call id -> its transcript entry, or the plan item it made.
    calls: HashMap<String, Call>,
    /// The turn's plan, and its transcript entry once shown.
    plan: Vec<Item>,
    plan_entry: Option<usize>,
    last_text: String,
    got_result: bool,
}

enum Call {
    Entry(usize),
    Plan(usize),
}

#[derive(Serialize)]
struct Item {
    /// The task tools' id, once its creation is answered.
    #[serde(skip)]
    id: Option<String>,
    text: String,
    /// What it reads as while in progress ("Reading the parser").
    active: String,
    /// "pending", "in_progress", or "completed".
    status: String,
}

impl Stream {
    fn read(&mut self, event: &Value, out: &Transcript) {
        // A subagent's own steps: its call's result reports them.
        if !event["parent_tool_use_id"].is_null() {
            return;
        }
        match event["type"].as_str() {
            Some("system") if event["subtype"] == "init" => {
                if let Some(session) = event["session_id"].as_str() {
                    out.studio.set_thread_session(out.thread, Some(session.to_owned()));
                }
                self.model = event["model"].as_str().unwrap_or("").to_owned();
            }
            Some("stream_event") => self.partial(&event["event"], out),
            Some("assistant") => {
                for block in event["message"]["content"].as_array().into_iter().flatten() {
                    match block["type"].as_str() {
                        Some("text") => {
                            let text = block["text"].as_str().unwrap_or("").trim();
                            if !text.is_empty() {
                                self.last_text = text.to_owned();
                                out.push("assistant", text, Value::Null);
                            }
                        }
                        Some("tool_use") => self.call(block, out),
                        _ => {}
                    }
                }
            }
            Some("user") => {
                for block in event["message"]["content"].as_array().into_iter().flatten() {
                    if block["type"] == "tool_result" {
                        self.answer(block, out);
                    }
                }
            }
            Some("result") => self.result(event, out),
            _ => {}
        }
    }

    /// A partial event: what the run is doing, and the text streaming in.
    fn partial(&mut self, event: &Value, out: &Transcript) {
        match event["type"].as_str() {
            Some("content_block_start") => {
                let block = &event["content_block"];
                match block["type"].as_str() {
                    Some("thinking" | "redacted_thinking") => {
                        let index = event["index"].as_u64().unwrap_or(0);
                        self.thinking = Some((index, Instant::now(), String::new(), 0));
                        out.event("phase", "thinking");
                    }
                    Some("tool_use") => {
                        let name = tool_name(block);
                        if !HIDDEN_TOOLS.contains(&name) {
                            out.event("phase", format!("tool {name}"));
                        }
                    }
                    Some("text") => out.event("phase", "replying"),
                    _ => {}
                }
            }
            Some("content_block_delta") => {
                let delta = &event["delta"];
                match delta["type"].as_str() {
                    Some("text_delta") => out.event("delta", delta["text"].as_str().unwrap_or("")),
                    Some("thinking_delta") => {
                        if let Some((_, _, text, tokens)) = &mut self.thinking {
                            let more = delta["thinking"].as_str().unwrap_or("");
                            text.push_str(more);
                            *tokens = (*tokens).max(delta["estimated_tokens"].as_u64().unwrap_or(0));
                            if !more.is_empty() {
                                out.event("thinking", more);
                            }
                        }
                    }
                    _ => {}
                }
            }
            Some("content_block_stop") => {
                let index = event["index"].as_u64().unwrap_or(0);
                if self.thinking.as_ref().is_some_and(|(open, ..)| *open == index) {
                    let (_, began, text, tokens) = self.thinking.take().expect("a thought is open");
                    let ms = began.elapsed().as_millis() as u64;
                    out.push("thinking", text.trim(), json!({ "ms": ms, "tokens": tokens }));
                }
            }
            _ => {}
        }
    }

    fn call(&mut self, block: &Value, out: &Transcript) {
        let name = tool_name(block);
        let id = block["id"].as_str().unwrap_or("").to_owned();
        let input = &block["input"];
        if HIDDEN_TOOLS.contains(&name) {
            return;
        }
        if PLAN_TOOLS.contains(&name) {
            self.plan_call(name, id, input, out);
            return;
        }
        let data = json!({ "id": id, "name": name, "input": clip(input), "status": "running" });
        let index = out.push("tool", "", data);
        self.calls.insert(id, Call::Entry(index));
    }

    /// A tool's result: its entry is done, or a task the plan made has its id.
    fn answer(&mut self, block: &Value, out: &Transcript) {
        let text = match &block["content"] {
            Value::String(text) => text.clone(),
            Value::Array(parts) => parts.iter().filter_map(|part| part["text"].as_str()).collect::<Vec<_>>().join("\n"),
            _ => String::new(),
        };
        let error = block["is_error"].as_bool().unwrap_or(false);
        match block["tool_use_id"].as_str().and_then(|id| self.calls.get(id)) {
            Some(Call::Entry(index)) => out.update(*index, |entry| {
                entry.data["status"] = json!(if error { "error" } else { "ok" });
                // A proposal's id, for its card.
                if let Some(op) = serde_json::from_str::<Value>(&text).ok().and_then(|value| value["proposed"].as_u64()) {
                    entry.data["op"] = json!(op);
                }
                entry.data["result"] = json!(clip_text(&text));
            }),
            // "Task #3 created successfully: …"
            Some(Call::Plan(item)) => {
                let id: String = text.split('#').nth(1).unwrap_or("").chars().take_while(char::is_ascii_digit).collect();
                if let Some(item) = self.plan.get_mut(*item).filter(|_| !id.is_empty()) {
                    item.id = Some(id);
                }
            }
            None => {}
        }
    }

    fn plan_call(&mut self, name: &str, id: String, input: &Value, out: &Transcript) {
        let text = |key: &str| input[key].as_str().unwrap_or("").to_owned();
        match name {
            "TodoWrite" => {
                self.plan = input["todos"]
                    .as_array()
                    .into_iter()
                    .flatten()
                    .map(|todo| Item {
                        id: None,
                        text: todo["content"].as_str().unwrap_or("").to_owned(),
                        active: todo["activeForm"].as_str().unwrap_or("").to_owned(),
                        status: todo["status"].as_str().unwrap_or("pending").to_owned(),
                    })
                    .collect();
            }
            "TaskCreate" => {
                self.plan.push(Item { id: None, text: text("subject"), active: text("activeForm"), status: "pending".to_owned() });
                self.calls.insert(id, Call::Plan(self.plan.len() - 1));
            }
            "TaskUpdate" => {
                let task = text("taskId");
                let Some(at) = self.plan.iter().position(|item| item.id.as_deref() == Some(task.as_str())) else {
                    return;
                };
                match input["status"].as_str() {
                    Some("deleted") => {
                        self.plan.remove(at);
                    }
                    Some(status) => self.plan[at].status = status.to_owned(),
                    None => {}
                }
                if let Some(item) = self.plan.get_mut(at) {
                    for (key, field) in [("subject", &mut item.text), ("activeForm", &mut item.active)] {
                        if let Some(value) = input[key].as_str() {
                            *field = value.to_owned();
                        }
                    }
                }
            }
            _ => return,
        }
        let data = json!({ "items": self.plan });
        match self.plan_entry {
            Some(index) => out.update(index, |entry| entry.data = data),
            None => self.plan_entry = Some(out.push("plan", "", data)),
        }
    }

    /// The turn's end: an error, or the reply if no text block carried it,
    /// and the closing line with what the turn took.
    fn result(&mut self, event: &Value, out: &Transcript) {
        self.got_result = true;
        if let Some(session) = event["session_id"].as_str() {
            out.studio.set_thread_session(out.thread, Some(session.to_owned()));
        }
        let text = event["result"].as_str().unwrap_or("").trim();
        if event["is_error"].as_bool().unwrap_or(false) {
            let message = match (text, event["subtype"].as_str()) {
                ("", Some("error_max_turns")) => "stopped at the limit of 40 steps; ask it to go on",
                ("", subtype) => subtype.unwrap_or("error"),
                (text, _) => text,
            };
            out.push("error", message, Value::Null);
        } else if !text.is_empty() && text != self.last_text {
            out.push("assistant", text, Value::Null);
        }
        let usage = &event["usage"];
        let count = |key: &str| usage[key].as_u64().unwrap_or(0);
        out.push("turn", "", json!({
            "ms": event["duration_ms"],
            "cost": event["total_cost_usd"],
            "input": count("input_tokens") + count("cache_read_input_tokens") + count("cache_creation_input_tokens"),
            "output": count("output_tokens"),
            "model": self.model,
            "effort": self.effort,
        }));
    }
}

/// A tool's name without its MCP server's prefix: "get_program", not
/// "mcp__slog__get_program".
fn tool_name(block: &Value) -> &str {
    let name = block["name"].as_str().unwrap_or("tool");
    name.rsplit("__").next().unwrap_or(name)
}

/// `value` with its long strings cut, for the transcript.
fn clip(value: &Value) -> Value {
    match value {
        Value::String(text) => json!(clip_text(text)),
        Value::Array(items) => Value::Array(items.iter().map(clip).collect()),
        Value::Object(fields) => Value::Object(fields.iter().map(|(key, value)| (key.clone(), clip(value))).collect()),
        other => other.clone(),
    }
}

fn clip_text(text: &str) -> String {
    match text.char_indices().nth(CLIP) {
        Some((end, _)) => format!("{}\n… ({} more characters)", &text[..end], text[end..].chars().count()),
        None => text.to_owned(),
    }
}

fn which(binary: &str) -> Option<PathBuf> {
    std::env::var_os("PATH").and_then(|paths| {
        std::env::split_paths(&paths)
            .map(|directory| directory.join(binary))
            .find(|path| path.is_file())
    })
}
