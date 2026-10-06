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
        "agent.js" => (include_str!("../web/agent.js"), "text/javascript; charset=utf-8"),
        "summary.js" => (include_str!("../web/summary.js"), "text/javascript; charset=utf-8"),
        "files.js" => (include_str!("../web/files.js"), "text/javascript; charset=utf-8"),
        "history.js" => (include_str!("../web/history.js"), "text/javascript; charset=utf-8"),
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
    /// The full set of breakpoint lines of `file`.
    Breakpoints { file: String, lines: Vec<u32> },
    Command { line: String },
    Interrupt,
    /// Kill the session server; the next command starts a fresh one.
    Restart,
    /// Run later servers in this mode, starting now.
    Mode { mode: Mode },
    /// List the scenarios beside the program.
    Scenarios,
    /// Run one of them by name.
    RunScenario { name: String },
    /// Ask the agent, following up in `thread` or starting a new one.
    Ask { thread: Option<u32>, message: String },
    StopThread { thread: u32 },
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
    /// The thread an ask went to (new threads get an id here).
    Asked { thread: u32 },
    Notice { message: &'a str },
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
        Request::Breakpoints { file, lines } => studio.set_breakpoints(file, lines),
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
            studio.lane.kill();
            warm(studio);
        }
        Request::Mode { mode } => {
            studio.lane.set_mode(mode);
            warm(studio);
        }
        Request::Scenarios => {
            let _ = direct.send(json(&Reply::Scenarios {
                names: studio.scenarios(),
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
