//! HTTP: the page, its static assets (compiled into the binary), and one
//! WebSocket per browser tab carrying edits and commands in and events out.
//!
//! Only the WebSocket can read or change anything, so only it is guarded: it
//! requires the gate's credential (`auth.rs`: the launch token, or a login)
//! and a same-origin `Origin` header. The page and its assets hold no data.
//! A tab names its project in the handshake; the registry maps the user and
//! the project to their Studio.

use crate::auth::{self, Gate};
use crate::lane::Mode;
use crate::registry::Registry;
use crate::results::{Refinement, Row, SetId};
use crate::store::Files;
use crate::studio::{Event, HistoryView, Refused, Snapshot, Studio};
use axum::Router;
use axum::extract::ws::{Message, WebSocket, WebSocketUpgrade};
use axum::extract::{Path, State};
use axum::http::{HeaderMap, StatusCode, Uri, header};
use axum::response::{IntoResponse, Response};
use axum::routing::{get, post};
use serde::{Deserialize, Serialize};
use std::sync::Arc;
use std::sync::atomic::{AtomicU64, Ordering};
use tokio::sync::{broadcast, mpsc};

struct Web {
    registry: Arc<Registry>,
    gate: Gate,
    next_connection: AtomicU64,
}

pub fn router(registry: Arc<Registry>, gate: Gate) -> Router {
    let routes = gate.routes();
    let web = Arc::new(Web {
        registry,
        gate,
        next_connection: AtomicU64::new(1),
    });
    Router::new()
        .route("/", get(page))
        // A result set in a window of its own (results-page.js).
        .route(
            "/results",
            get(|State(web): State<Arc<Web>>, headers: HeaderMap| async move {
                web.gate.page(&headers, include_str!("../web/results.html"))
            }),
        )
        .route("/static/{name}", get(|Path(name): Path<String>| async move { asset(&name) }))
        .route("/ws", get(socket))
        .route(
            "/mcp",
            post(|State(web): State<Arc<Web>>, headers: HeaderMap, body: String| async move {
                crate::mcp::handle(&web.registry, headers, body).await
            }),
        )
        .with_state(web)
        .merge(routes)
}

async fn page(State(web): State<Arc<Web>>, headers: HeaderMap) -> Response {
    web.gate.page(&headers, include_str!("../web/index.html"))
}

fn asset(name: &str) -> Response {
    let (body, kind) = match name {
        "studio.css" => (include_str!("../web/studio.css"), "text/css; charset=utf-8"),
        "main.js" => (include_str!("../web/main.js"), "text/javascript; charset=utf-8"),
        "editor.js" => (include_str!("../web/editor.js"), "text/javascript; charset=utf-8"),
        "render.js" => (include_str!("../web/render.js"), "text/javascript; charset=utf-8"),
        "forms.js" => (include_str!("../web/forms.js"), "text/javascript; charset=utf-8"),
        "lexer.js" => (include_str!("../web/lexer.js"), "text/javascript; charset=utf-8"),
        "sexp.js" => (include_str!("../web/sexp.js"), "text/javascript; charset=utf-8"),
        "format.js" => (include_str!("../web/format.js"), "text/javascript; charset=utf-8"),
        "complete.js" => (include_str!("../web/complete.js"), "text/javascript; charset=utf-8"),
        "commands.js" => (include_str!("../web/commands.js"), "text/javascript; charset=utf-8"),
        "paredit.js" => (include_str!("../web/paredit.js"), "text/javascript; charset=utf-8"),
        "emacs.js" => (include_str!("../web/emacs.js"), "text/javascript; charset=utf-8"),
        "structure.css" => (include_str!("../web/structure.css"), "text/css; charset=utf-8"),
        "agent.js" => (include_str!("../web/agent.js"), "text/javascript; charset=utf-8"),
        "thread.js" => (include_str!("../web/thread.js"), "text/javascript; charset=utf-8"),
        "markdown.js" => (include_str!("../web/markdown.js"), "text/javascript; charset=utf-8"),
        "summary.js" => (include_str!("../web/summary.js"), "text/javascript; charset=utf-8"),
        "files.js" => (include_str!("../web/files.js"), "text/javascript; charset=utf-8"),
        "history.js" => (include_str!("../web/history.js"), "text/javascript; charset=utf-8"),
        "hunks.js" => (include_str!("../web/hunks.js"), "text/javascript; charset=utf-8"),
        "graph.js" => (include_str!("../web/graph.js"), "text/javascript; charset=utf-8"),
        "inline-diff.js" => (include_str!("../web/inline-diff.js"), "text/javascript; charset=utf-8"),
        "changes.js" => (include_str!("../web/changes.js"), "text/javascript; charset=utf-8"),
        "proposals.js" => (include_str!("../web/proposals.js"), "text/javascript; charset=utf-8"),
        "diff.css" => (include_str!("../web/diff.css"), "text/css; charset=utf-8"),
        "results.js" => (include_str!("../web/results.js"), "text/javascript; charset=utf-8"),
        "results.css" => (include_str!("../web/results.css"), "text/css; charset=utf-8"),
        "results-page.js" => (include_str!("../web/results-page.js"), "text/javascript; charset=utf-8"),
        "table.js" => (include_str!("../web/table.js"), "text/javascript; charset=utf-8"),
        "table.css" => (include_str!("../web/table.css"), "text/css; charset=utf-8"),
        "trace.js" => (include_str!("../web/trace.js"), "text/javascript; charset=utf-8"),
        "trace.css" => (include_str!("../web/trace.css"), "text/css; charset=utf-8"),
        "hints.js" => (include_str!("../web/hints.js"), "text/javascript; charset=utf-8"),
        "hints.css" => (include_str!("../web/hints.css"), "text/css; charset=utf-8"),
        "palette.js" => (include_str!("../web/palette.js"), "text/javascript; charset=utf-8"),
        "assist.js" => (include_str!("../web/assist.js"), "text/javascript; charset=utf-8"),
        "assist.css" => (include_str!("../web/assist.css"), "text/css; charset=utf-8"),
        "breakpoints.js" => (include_str!("../web/breakpoints.js"), "text/javascript; charset=utf-8"),
        "calls.js" => (include_str!("../web/calls.js"), "text/javascript; charset=utf-8"),
        "debugger.css" => (include_str!("../web/debugger.css"), "text/css; charset=utf-8"),
        _ => return StatusCode::NOT_FOUND.into_response(),
    };
    ([(header::CONTENT_TYPE, kind), (header::CACHE_CONTROL, "no-cache")], body).into_response()
}

/// What a tab asks of the studio.
#[derive(Debug, Deserialize)]
#[serde(tag = "t", rename_all = "kebab-case")]
enum Request {
    /// The whole text of `file`, edited from version `base`.
    Edit { file: String, base: u64, text: String },
    Save,
    Evaluate,
    /// Evaluate, then re-run under the breakpoints.
    Debug,
    /// The full set of breakpoints of `file`.
    Breakpoints { file: String, points: Vec<crate::breakpoints::Breakpoint> },
    /// A REPL line that observes the session (`calls`, `breaks`, `logs`,
    /// `frames`), answered to this tab only and kept out of the
    /// transcript: the debugger's panels read with it.
    Quiet { line: String, tag: u64 },
    Command { line: String },
    Interrupt,
    /// Kill the session server; the next command starts a fresh one.
    Restart,
    /// Run later servers in this mode, starting now.
    Mode { mode: Mode },
    /// Whether plain Runs record their trace.
    Trace { on: bool },
    /// List the scenarios beside the program.
    Scenarios,
    /// Run one of them by name.
    RunScenario { name: String },
    /// List the saved databases, for the prompt to offer.
    Databases,
    /// Ask the agent, following up in `thread` or starting a new one.
    Ask { thread: Option<u32>, message: String },
    StopThread { thread: u32 },
    /// Ask the REPL's assistant, following up in `thread` or starting a new
    /// thread, with what the prompt knows of the session.
    Assist {
        thread: Option<u32>,
        message: String,
        #[serde(default)]
        context: crate::assist::Context,
    },
    /// The total and first rows of the query being typed, apart from the
    /// transcript; `seq` names the answer.
    Preview { line: String, seq: u64 },
    Accept { op: u32 },
    Reject { op: u32 },
    AcceptChangeset { changeset: u32 },
    /// The version DAG and the branches.
    History,
    /// The files of version `id`, to look at.
    ViewVersion { id: u64 },
    /// Restore version `id` as a new version on the current branch.
    Restore { id: u64 },
    /// Start a branch at version `id` and continue on it.
    Branch { id: u64 },
    NewFile { path: String },
    RenameFile { from: String, to: String },
    DeleteFile { path: String },
    /// Make `path` the file Run and Debug evaluate.
    SetMain { path: String },
    /// Rows `start..end` (0-based) of a result set.
    Rows { set: SetId, start: u64, end: u64 },
    /// Run a refinement of a result set as a new query.
    Refine { set: SetId, refinement: Refinement },
}

impl Request {
    /// Whether the request puts the lane to work, starting a server if none
    /// runs. (A scenario runs on a lane of its own.)
    fn uses_lane(&self) -> bool {
        matches!(
            self,
            Request::Evaluate
                | Request::Debug
                | Request::Command { .. }
                | Request::Restart
                | Request::Mode { .. }
                | Request::Rows { .. }
                | Request::Refine { .. }
                | Request::Assist { .. }
                | Request::Preview { .. }
        )
    }
}

/// Messages meant for one tab only; everything else is a broadcast `Event`.
#[derive(Debug, Serialize)]
#[serde(tag = "t", rename_all = "kebab-case")]
enum Reply<'a> {
    Init(&'a Snapshot),
    /// The edit making `file`'s `version` was taken.
    Ack { file: &'a str, version: u64 },
    /// The edit was refused: this is the current text.
    Reset { file: &'a str, version: u64, text: &'a str },
    /// The edit was refused: `file` is no longer in the project.
    Gone { file: &'a str },
    History(&'a HistoryView),
    /// The files of version `id`.
    VersionFiles { id: u64, files: &'a Files },
    Scenarios { names: Vec<String> },
    Databases { names: Vec<String> },
    /// The thread an ask went to (new threads get an id here).
    Asked { thread: u32 },
    /// The thread the REPL's assistant answers `message` in, or why it
    /// cannot.
    Assisted {
        thread: Option<u32>,
        message: &'a str,
        error: Option<String>,
    },
    /// A preview's answer; `busy` when another command held the lane.
    Preview {
        seq: u64,
        #[serde(flatten)]
        read: Option<crate::assist::Read>,
        error: Option<String>,
        busy: bool,
    },
    Notice { message: &'a str },
    /// The answer to a `Quiet` request.
    Quiet { tag: u64, #[serde(flatten)] outcome: &'a crate::session::Outcome },
    /// The rows asked for, as many as exist; or why they cannot be had.
    Rows {
        set: SetId,
        start: u64,
        rows: Vec<Row>,
        error: Option<String>,
    },
}

async fn socket(
    State(web): State<Arc<Web>>,
    uri: Uri,
    headers: HeaderMap,
    upgrade: WebSocketUpgrade,
) -> Response {
    let Some(user) = web.gate.socket_user(&uri, &headers) else {
        return StatusCode::FORBIDDEN.into_response();
    };
    if !auth::same_origin(&headers) {
        return StatusCode::FORBIDDEN.into_response();
    }
    let project = uri.query().and_then(|query| field(query, "project"));
    let studio = match web.registry.open(&user, project.as_deref().unwrap_or("")) {
        Ok(studio) => studio,
        Err(message) => return (StatusCode::NOT_FOUND, message).into_response(),
    };
    let connection = web.next_connection.fetch_add(1, Ordering::SeqCst);
    upgrade.on_upgrade(move |socket| serve(socket, web, studio, connection))
}

/// The value of `key` in `a=1&b=2`, a query or a form's body, decoded.
pub fn field(encoded: &str, key: &str) -> Option<String> {
    encoded.split('&').find_map(|pair| {
        let (name, value) = pair.split_once('=').unwrap_or((pair, ""));
        if decode(name)? == key { decode(value) } else { None }
    })
}

/// Undo form encoding: `+` is a space and `%XX` a byte.
fn decode(text: &str) -> Option<String> {
    let hex = |digit: Option<u8>| char::from(digit?).to_digit(16);
    let mut bytes = Vec::with_capacity(text.len());
    let mut rest = text.bytes();
    while let Some(byte) = rest.next() {
        bytes.push(match byte {
            b'+' => b' ',
            b'%' => (hex(rest.next())? * 16 + hex(rest.next())?) as u8,
            byte => byte,
        });
    }
    String::from_utf8(bytes).ok()
}

async fn serve(mut socket: WebSocket, web: Arc<Web>, studio: Arc<Studio>, connection: u64) {
    let mut events = studio.subscribe();
    let (direct, mut replies) = mpsc::unbounded_channel::<String>();
    if send_init(&mut socket, &studio).await.is_err() {
        return;
    }
    loop {
        let outgoing = tokio::select! {
            incoming = socket.recv() => match incoming {
                Some(Ok(Message::Text(text))) => {
                    handle(&web.registry, &studio, connection, &text, &direct);
                    continue;
                }
                Some(Ok(_)) => continue,
                Some(Err(_)) | None => return,
            },
            reply = replies.recv() => reply.expect("the sender lives in this loop"),
            event = events.recv() => match event {
                // A tab's own edit is already on its screen.
                Ok(Event::Text { origin, .. }) if origin == connection => continue,
                Ok(event) => json(&event),
                // Too far behind to patch up event by event: start over.
                Err(broadcast::error::RecvError::Lagged(_)) => {
                    if send_init(&mut socket, &studio).await.is_err() {
                        return;
                    }
                    continue;
                }
                Err(broadcast::error::RecvError::Closed) => return,
            },
        };
        if socket.send(Message::Text(outgoing.into())).await.is_err() {
            return;
        }
    }
}

async fn send_init(socket: &mut WebSocket, studio: &Studio) -> Result<(), axum::Error> {
    let snapshot = studio.snapshot().await;
    socket
        .send(Message::Text(json(&Reply::Init(&snapshot)).into()))
        .await
}

/// Edits are answered at once; everything that talks to the session server
/// runs as its own task so this tab can still interrupt it.
fn handle(
    registry: &Registry,
    studio: &Arc<Studio>,
    connection: u64,
    text: &str,
    direct: &mpsc::UnboundedSender<String>,
) {
    let request = match serde_json::from_str::<Request>(text) {
        Ok(request) => request,
        Err(error) => {
            let message = format!("unreadable request: {error}");
            let _ = direct.send(json(&Reply::Notice { message: &message }));
            return;
        }
    };
    // A server about to start counts against its user's lanes.
    if request.uses_lane() {
        registry.admit(studio);
    }
    let studio = studio.clone();
    match request {
        Request::Edit { file, base, text } => {
            let reply = match studio.edit(connection, &file, base, text) {
                Ok(version) => json(&Reply::Ack { file: &file, version }),
                Err(Refused::Stale { version, text }) => json(&Reply::Reset {
                    file: &file,
                    version,
                    text: &text,
                }),
                Err(Refused::NoFile) => json(&Reply::Gone { file: &file }),
            };
            let _ = direct.send(reply);
        }
        Request::Save => match studio.save("save") {
            Ok((version, text)) => studio.summarize(version, text, None),
            Err(message) => {
                let _ = direct.send(json(&Reply::Notice { message: &message }));
            }
        },
        Request::Evaluate => {
            tokio::spawn(async move { studio.evaluate().await });
        }
        Request::Debug => {
            tokio::spawn(async move { studio.debug().await });
        }
        Request::Breakpoints { file, points } => {
            if studio.set_breakpoints(file, points) {
                tokio::spawn(async move { studio.reconcile().await });
            }
        }
        Request::Quiet { line, tag } => {
            let direct = direct.clone();
            tokio::spawn(async move {
                let outcome = studio.quiet(&line).await;
                let _ = direct.send(json(&Reply::Quiet { tag, outcome: &outcome }));
            });
        }
        Request::Command { line } => {
            tokio::spawn(async move { studio.command(&line).await });
        }
        Request::Interrupt => {
            let direct = direct.clone();
            tokio::spawn(async move {
                if let Err(message) = studio.lane.interrupt().await {
                    let _ = direct.send(json(&Reply::Notice { message: &message }));
                }
            });
        }
        Request::Restart => {
            studio.restart();
            warm(studio);
        }
        Request::Mode { mode } => {
            studio.set_mode(mode);
            warm(studio);
        }
        Request::Trace { on } => studio.set_tracing(on),
        Request::Scenarios => {
            let _ = direct.send(json(&Reply::Scenarios {
                names: studio.scenarios(),
            }));
        }
        Request::Databases => {
            let _ = direct.send(json(&Reply::Databases {
                names: studio.databases(),
            }));
        }
        Request::RunScenario { name } => {
            tokio::spawn(async move { studio.run_scenario(&name).await });
        }
        Request::Ask { thread, message } => match studio.ask(thread, message) {
            Ok(thread) => {
                let _ = direct.send(json(&Reply::Asked { thread }));
            }
            Err(message) => {
                let _ = direct.send(json(&Reply::Notice { message: &message }));
            }
        },
        Request::StopThread { thread } => {
            studio.stop_thread(thread);
        }
        Request::Assist { thread, message, context } => {
            let (thread, error) = match studio.assist(thread, message.clone(), context) {
                Ok(thread) => (Some(thread), None),
                Err(error) => (None, Some(error)),
            };
            let _ = direct.send(json(&Reply::Assisted { thread, message: &message, error }));
        }
        Request::Preview { line, seq } => {
            let direct = direct.clone();
            tokio::spawn(async move {
                // Never queued behind the author's own commands.
                let (read, error, busy) = match studio.read(&line, std::time::Duration::ZERO).await {
                    Ok(read) => (Some(read), None, false),
                    Err(why) => {
                        let busy = why == crate::assist::BUSY;
                        (None, (!busy).then_some(why), busy)
                    }
                };
                let _ = direct.send(json(&Reply::Preview { seq, read, error, busy }));
            });
        }
        Request::Accept { op } => {
            if let Err(message) = studio.accept(op) {
                let _ = direct.send(json(&Reply::Notice { message: &message }));
            }
        }
        Request::Reject { op } => {
            if let Err(message) = studio.reject(op) {
                let _ = direct.send(json(&Reply::Notice { message: &message }));
            }
        }
        Request::AcceptChangeset { changeset } => {
            let skipped = studio.accept_changeset(changeset);
            if !skipped.is_empty() {
                let message = format!("not accepted: {}", skipped.join("; "));
                let _ = direct.send(json(&Reply::Notice { message: &message }));
            }
        }
        Request::History => {
            let _ = direct.send(json(&Reply::History(&studio.history())));
        }
        Request::ViewVersion { id } => match studio.version_files(id) {
            Ok(files) => {
                let _ = direct.send(json(&Reply::VersionFiles { id, files: &files }));
            }
            Err(message) => notice(direct, Err(message)),
        },
        Request::Restore { id } => notice(direct, studio.restore(id)),
        Request::Branch { id } => notice(direct, studio.branch(id)),
        Request::NewFile { path } => notice(direct, studio.new_file(&path)),
        Request::RenameFile { from, to } => notice(direct, studio.rename_file(&from, &to)),
        Request::DeleteFile { path } => notice(direct, studio.delete_file(&path)),
        Request::SetMain { path } => notice(direct, studio.set_main(&path)),
        Request::Rows { set, start, end } => {
            let direct = direct.clone();
            tokio::spawn(async move {
                let (rows, error) = match studio.rows(set, start, end).await {
                    Ok(rows) => (rows, None),
                    Err(why) => (Vec::new(), Some(why)),
                };
                let _ = direct.send(json(&Reply::Rows {
                    set,
                    start,
                    rows,
                    error,
                }));
            });
        }
        Request::Refine {
            set,
            refinement: Refinement::Sort { column, descending },
        } => {
            let direct = direct.clone();
            tokio::spawn(async move { notice(&direct, studio.sort(set, column, descending).await) });
        }
        Request::Refine { set, refinement } => match studio.refinement(set, &refinement) {
            Ok((line, lineage)) => {
                tokio::spawn(async move { studio.run(&line, Some(lineage)).await });
            }
            Err(message) => notice(direct, Err(message)),
        },
    }
}

/// Tell the tab why its request failed, if it did.
fn notice(direct: &mpsc::UnboundedSender<String>, outcome: Result<(), String>) {
    if let Err(message) = outcome {
        let _ = direct.send(json(&Reply::Notice { message: &message }));
    }
}

/// Start a replacement server at once, so the lane reads as starting and
/// then ready, rather than dead until the next command.
pub fn warm(studio: Arc<Studio>) {
    tokio::spawn(async move { studio.lane.command(":ping").await });
}

fn json<T: Serialize>(value: &T) -> String {
    serde_json::to_string(value).expect("studio messages serialize")
}

#[cfg(test)]
mod tests {
    use super::field;

    /// Queries and forms (and the passwords in them) arrive encoded, so
    /// every byte must survive decoding.
    #[test]
    fn form_fields_decode_exactly() {
        let body = "user=alice&password=p%40ss+w%26rd%3D%25&next=";
        assert_eq!(field(body, "user").as_deref(), Some("alice"));
        assert_eq!(field(body, "password").as_deref(), Some("p@ss w&rd=%"));
        assert_eq!(field(body, "next").as_deref(), Some(""));
        assert_eq!(field(body, "token"), None);
        assert_eq!(field("password=%4", "password"), None);
        assert_eq!(field("password=%+1", "password"), None);
        assert_eq!(field("password=%C3%A9", "password").as_deref(), Some("é"));
    }
}
