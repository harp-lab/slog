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

use crate::review::Message;
use crate::studio::{Event, Studio};
use serde::Serialize;
use serde_json::{Value, json};
use std::collections::HashMap;
use std::path::PathBuf;
use std::process::Stdio;
use std::sync::{Arc, Mutex};
use tokio::io::{AsyncBufReadExt, AsyncReadExt, BufReader};
use tokio::process::{Child, Command};

/// The header a run's MCP config carries: its thread id.
pub const THREAD_HEADER: &str = "x-studio-thread";

const PERSONA: &str = "\
You are the programming agent inside Slog Studio, building a Slog program together with its \
author, who is watching the editor and often dictates. Slog is a Datalog-family language: a \
program is top-level forms -- `table (rel type ...)`, `union (T (ctor type ...) ...)`, \
`struct`, `enum`, `lattice`, and `rule BODY... --> HEAD...` (or `rule HEAD <-- BODY`; a `rule` \
followed only by facts states facts). `;;` starts a comment. The `slog` MCP tools are your only \
way to read or change the program.

How to work -- the author is waiting:
- Read once (get_program), then propose. Make form-sized changes: propose_edit replaces an exact, \
unique piece of the current program text (include enough context to be unique); propose_append \
adds new forms at the end. Declare a relation before rules use it. Give every proposal a \
one-sentence `note` saying what it does and why.
- Then check your work: evaluate_proposal runs the program as your proposals would leave it, in \
a fresh session, and reports its relations and row counts or its errors; query runs a `?` query \
against that evaluation, e.g. `?(eval E V)` or `? (path X Y) (edge Y Z) -> (X Z)`. Fix what you \
broke before you reply, and cite the evidence (row counts, a sample row) in your reply.
- Your proposals are not applied until the author accepts them. Each of your turns is one \
changeset; proposing the same text again in a later turn builds on your earlier proposals.
- The author dictates: read requests charitably, honour self-corrections (\"or sorry, a data \
type\"), ignore filler. When a request is ambiguous, propose the most plausible reading and name \
the alternative in your reply instead of asking.
- Other threads may be proposing changes too; leave theirs alone. Where two threads change the \
same text the author settles it.
- Reply when done with a short summary of what you proposed and what you checked. No preamble.";

pub struct Agent {
    /// The bearer token `/mcp` requires; it never leaves this machine except
    /// in the 0600 config file a run reads.
    pub mcp_token: String,
    model: Option<String>,
    effort: String,
    /// The claude process of every run in flight, by thread.
    running: Mutex<HashMap<u32, Child>>,
}

#[derive(Clone, Debug, Serialize)]
pub struct AgentEvent {
    pub thread: u32,
    /// "start", "phase", "delta", "text", "tool", "error", or "done".
    pub kind: &'static str,
    pub text: String,
}

impl Agent {
    pub fn new(mcp_token: String) -> Self {
        Self {
            mcp_token,
            // The CLI's own default model unless the operator picks one.
            model: std::env::var("STUDIO_AGENT_MODEL").ok().filter(|model| !model.is_empty()),
            effort: std::env::var("STUDIO_AGENT_EFFORT").unwrap_or_else(|_| "medium".to_owned()),
            running: Mutex::new(HashMap::new()),
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
        self.running
            .lock()
            .expect("agent lock")
            .get_mut(&thread)
            .is_some_and(|child| child.start_kill().is_ok())
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

/// One turn of `thread`: run claude until it finishes, streaming its
/// progress, then close the turn's changeset.
pub async fn run(studio: Arc<Studio>, thread: u32, message: String, context: String) {
    let emit = |kind: &'static str, text: String| {
        studio.publish(Event::Agent(AgentEvent { thread, kind, text }));
    };
    let agent = &studio.agent;
    let config = match agent.write_config(studio.port(), thread) {
        Ok(path) => path,
        Err(error) => {
            studio.thread_message(thread, "error", &error);
            emit("error", error);
            studio.finish_turn(thread);
            emit("done", String::new());
            return;
        }
    };
    let mut resume = studio.thread_session(thread);
    loop {
        let system = format!("{PERSONA}\n\n## Runtime context (from Slog Studio)\n- Thread: {thread}\n{context}");
        let mut args: Vec<String> = vec![
            "-p".into(), message.clone(),
            "--output-format".into(), "stream-json".into(), "--verbose".into(),
            // Partial events show "thinking…" / "calling query…" while a turn runs.
            "--include-partial-messages".into(),
            "--effort".into(), agent.effort.clone(),
            "--disable-slash-commands".into(),
            "--mcp-config".into(), config.to_string_lossy().into_owned(), "--strict-mcp-config".into(),
            "--allowedTools".into(), "mcp__slog".into(),
            "--disallowedTools".into(),
            "Bash,Task,Agent,Skill,TodoWrite,NotebookEdit,Write,Edit,Read,Glob,Grep,WebSearch,WebFetch".into(),
            "--max-turns".into(), "40".into(),
            "--append-system-prompt".into(), system,
        ];
        if let Some(model) = &agent.model {
            args.extend(["--model".to_owned(), model.clone()]);
        }
        if let Some(session) = &resume {
            args.extend(["--resume".to_owned(), session.clone()]);
        }
        emit("start", agent.model.clone().unwrap_or_default());
        let home = std::env::var("HOME").unwrap_or_else(|_| "/tmp".into());
        let mut child = match Command::new("claude")
            .args(&args)
            .current_dir(&home)
            .stdin(Stdio::null())
            .stdout(Stdio::piped())
            .stderr(Stdio::piped())
            .kill_on_drop(true)
            .spawn()
        {
            Ok(child) => child,
            Err(error) => {
                let message = format!("could not start claude: {error}");
                studio.thread_message(thread, "error", &message);
                emit("error", message);
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
        let mut got_result = false;
        let mut last_text = String::new();
        while let Ok(Some(line)) = lines.next_line().await {
            let Ok(event) = serde_json::from_str::<Value>(&line) else {
                continue;
            };
            match event["type"].as_str() {
                Some("system") if event["subtype"] == "init" => {
                    if let Some(session) = event["session_id"].as_str() {
                        studio.set_thread_session(thread, Some(session.to_owned()));
                    }
                }
                Some("stream_event") => {
                    let inner = &event["event"];
                    match inner["type"].as_str() {
                        Some("content_block_start") => {
                            let block = &inner["content_block"];
                            match block["type"].as_str() {
                                Some("thinking") => emit("phase", "thinking…".into()),
                                Some("tool_use") => {
                                    let name = block["name"].as_str().unwrap_or("tool");
                                    let tool = name.rsplit("__").next().unwrap_or(name);
                                    emit("phase", format!("calling {tool}…"));
                                }
                                Some("text") => emit("phase", "replying…".into()),
                                _ => {}
                            }
                        }
                        Some("content_block_delta") => {
                            if let Some(text) = inner["delta"]["text"].as_str() {
                                emit("delta", text.to_owned());
                            }
                        }
                        _ => {}
                    }
                }
                Some("assistant") => {
                    for block in event["message"]["content"].as_array().into_iter().flatten() {
                        match block["type"].as_str() {
                            Some("text") => {
                                let text = block["text"].as_str().unwrap_or("").trim().to_owned();
                                if !text.is_empty() {
                                    last_text = text.clone();
                                    studio.thread_message(thread, "assistant", &text);
                                    emit("text", text);
                                }
                            }
                            Some("tool_use") => {
                                let label = tool_label(block);
                                studio.thread_message(thread, "tool", &label);
                                emit("tool", label);
                            }
                            _ => {}
                        }
                    }
                }
                Some("result") => {
                    got_result = true;
                    if let Some(session) = event["session_id"].as_str() {
                        studio.set_thread_session(thread, Some(session.to_owned()));
                    }
                    let text = event["result"].as_str().unwrap_or("").trim().to_owned();
                    if event["is_error"].as_bool().unwrap_or(false) {
                        let message = if text.is_empty() {
                            event["subtype"].as_str().unwrap_or("error").to_owned()
                        } else {
                            text
                        };
                        studio.thread_message(thread, "error", &message);
                        emit("error", message);
                    } else if !text.is_empty() && text != last_text {
                        studio.thread_message(thread, "assistant", &text);
                        emit("text", text);
                    }
                }
                _ => {}
            }
        }
        let child = agent.running.lock().expect("agent lock").remove(&thread);
        let status = match child {
            Some(mut child) => child.wait().await.ok(),
            None => None,
        };
        let stderr_text = stderr_text.await.unwrap_or_default();
        let failed = !got_result && !status.is_some_and(|status| status.success());
        if failed && resume.is_some() {
            // A stale session id (its transcript gone) is the usual cause.
            studio.set_thread_session(thread, None);
            resume = None;
            emit("tool", "could not resume the conversation; starting a new one".into());
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
            studio.thread_message(thread, "error", &message);
            emit("error", message);
        }
        break;
    }
    let _ = std::fs::remove_file(&config);
    studio.finish_turn(thread);
    emit("done", String::new());
}

/// "propose_edit · note" for the transcript.
fn tool_label(block: &Value) -> String {
    let name = block["name"].as_str().unwrap_or("tool");
    let tool = name.rsplit("__").next().unwrap_or(name);
    let detail = ["note", "q"]
        .iter()
        .find_map(|key| block["input"][key].as_str())
        .map(|detail| format!(" · {detail}"))
        .unwrap_or_default();
    format!("{tool}{detail}")
}

fn which(binary: &str) -> Option<PathBuf> {
    std::env::var_os("PATH").and_then(|paths| {
        std::env::split_paths(&paths)
            .map(|directory| directory.join(binary))
            .find(|path| path.is_file())
    })
}

impl From<(&str, &str)> for Message {
    fn from((role, text): (&str, &str)) -> Self {
        Message {
            role: role.to_owned(),
            text: text.to_owned(),
        }
    }
}
