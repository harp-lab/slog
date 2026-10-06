//! HTTP: the page, its static assets (compiled into the binary), and one
//! WebSocket per browser tab carrying edits and commands in and events out.
//!
//! Only the WebSocket can read or change anything, so only it is guarded: it
//! requires the per-launch token and a same-origin `Origin` header. The page
//! and its assets hold no data. A tab names its project in the handshake;
//! the registry maps the user and the project to their Studio.

use crate::lane::Mode;
use crate::registry::{LOCAL_USER, Registry};
use crate::studio::{Event, Snapshot, Studio};
use axum::Router;
use axum::extract::ws::{Message, WebSocket, WebSocketUpgrade};
use axum::extract::{Path, State};
use axum::http::{HeaderMap, StatusCode, Uri, header};
use axum::response::{IntoResponse, Response};
use axum::routing::get;
use serde::{Deserialize, Serialize};
use std::sync::Arc;
use std::sync::atomic::{AtomicU64, Ordering};
use tokio::sync::{broadcast, mpsc};

struct Web {
    registry: Arc<Registry>,
    token: String,
    next_connection: AtomicU64,
}

pub fn router(registry: Arc<Registry>, token: String) -> Router {
    let web = Arc::new(Web {
        registry,
        token,
        next_connection: AtomicU64::new(1),
    });
    Router::new()
        .route("/", get(|| async { asset("index.html") }))
        .route("/static/{name}", get(|Path(name): Path<String>| async move { asset(&name) }))
        .route("/ws", get(socket))
        .with_state(web)
}

fn asset(name: &str) -> Response {
    let (body, kind) = match name {
        "index.html" => (include_str!("../web/index.html"), "text/html; charset=utf-8"),
        "studio.css" => (include_str!("../web/studio.css"), "text/css; charset=utf-8"),
        "main.js" => (include_str!("../web/main.js"), "text/javascript; charset=utf-8"),
        "editor.js" => (include_str!("../web/editor.js"), "text/javascript; charset=utf-8"),
        "render.js" => (include_str!("../web/render.js"), "text/javascript; charset=utf-8"),
        "forms.js" => (include_str!("../web/forms.js"), "text/javascript; charset=utf-8"),
        _ => return StatusCode::NOT_FOUND.into_response(),
    };
    ([(header::CONTENT_TYPE, kind), (header::CACHE_CONTROL, "no-cache")], body).into_response()
}

/// What a tab asks of the studio.
#[derive(Debug, Deserialize)]
#[serde(tag = "t", rename_all = "kebab-case")]
enum Request {
    /// The whole text, edited from version `base`.
    Edit { base: u64, text: String },
    Save,
    Evaluate,
    /// Evaluate, then re-run under the breakpoints.
    Debug,
    /// The full set of breakpoint lines.
    Breakpoints { lines: Vec<u32> },
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
}

/// Messages meant for one tab only; everything else is a broadcast `Event`.
#[derive(Debug, Serialize)]
#[serde(tag = "t", rename_all = "kebab-case")]
enum Reply<'a> {
    Init(&'a Snapshot),
    /// The edit to `version` was taken.
    Ack { version: u64 },
    /// The edit was refused: this is the current text.
    Reset { version: u64, text: &'a str },
    Scenarios { names: Vec<String> },
    Notice { message: &'a str },
}

async fn socket(
    State(web): State<Arc<Web>>,
    uri: Uri,
    headers: HeaderMap,
    upgrade: WebSocketUpgrade,
) -> Response {
    let token_ok = uri
        .query()
        .and_then(|query| field(query, "token"))
        .is_some_and(|token| same_secret(&token, &web.token));
    if !token_ok || !same_origin(&headers) {
        return StatusCode::FORBIDDEN.into_response();
    }
    let project = uri.query().and_then(|query| field(query, "project"));
    let studio = match web.registry.open(LOCAL_USER, project.as_deref().unwrap_or("")) {
        Ok(studio) => studio,
        Err(message) => return (StatusCode::NOT_FOUND, message).into_response(),
    };
    let connection = web.next_connection.fetch_add(1, Ordering::SeqCst);
    upgrade.on_upgrade(move |socket| serve(socket, studio, connection))
}

/// Browsers send cookies and tokens cross-site on WebSocket handshakes, so
/// the handshake must come from a page this server served.
fn same_origin(headers: &HeaderMap) -> bool {
    let value = |name| headers.get(name).and_then(|value| value.to_str().ok());
    match (value(header::ORIGIN), value(header::HOST)) {
        (Some(origin), Some(host)) => origin.strip_prefix("http://") == Some(host),
        _ => false,
    }
}

/// Comparison whose time does not depend on where the inputs differ.
fn same_secret(given: &str, expected: &str) -> bool {
    given.len() == expected.len()
        && given
            .bytes()
            .zip(expected.bytes())
            .fold(0, |difference, (a, b)| difference | (a ^ b))
            == 0
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

async fn serve(mut socket: WebSocket, studio: Arc<Studio>, connection: u64) {
    let mut events = studio.subscribe();
    let (direct, mut replies) = mpsc::unbounded_channel::<String>();
    if send_init(&mut socket, &studio).await.is_err() {
        return;
    }
    loop {
        let outgoing = tokio::select! {
            incoming = socket.recv() => match incoming {
                Some(Ok(Message::Text(text))) => {
                    handle(&studio, connection, &text, &direct);
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
fn handle(studio: &Arc<Studio>, connection: u64, text: &str, direct: &mpsc::UnboundedSender<String>) {
    let request = match serde_json::from_str::<Request>(text) {
        Ok(request) => request,
        Err(error) => {
            let message = format!("unreadable request: {error}");
            let _ = direct.send(json(&Reply::Notice { message: &message }));
            return;
        }
    };
    let studio = studio.clone();
    match request {
        Request::Edit { base, text } => {
            let reply = match studio.edit(connection, base, text) {
                Ok(version) => json(&Reply::Ack { version }),
                Err((version, text)) => json(&Reply::Reset {
                    version,
                    text: &text,
                }),
            };
            let _ = direct.send(reply);
        }
        Request::Save => {
            if let Err(message) = studio.save() {
                let _ = direct.send(json(&Reply::Notice { message: &message }));
            }
        }
        Request::Evaluate => {
            tokio::spawn(async move { studio.evaluate().await });
        }
        Request::Debug => {
            tokio::spawn(async move { studio.debug().await });
        }
        Request::Breakpoints { lines } => studio.set_breakpoints(lines),
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
    use super::{field, same_origin, same_secret};
    use axum::http::{HeaderMap, HeaderValue, header};

    #[test]
    fn the_socket_accepts_only_its_own_origin() {
        let headers = |origin: &'static str| {
            let mut headers = HeaderMap::new();
            headers.insert(header::HOST, HeaderValue::from_static("127.0.0.1:7300"));
            headers.insert(header::ORIGIN, HeaderValue::from_static(origin));
            headers
        };
        assert!(same_origin(&headers("http://127.0.0.1:7300")));
        assert!(!same_origin(&headers("http://evil.example")));
        assert!(!same_origin(&headers("http://127.0.0.1:7301")));
        assert!(!same_origin(&HeaderMap::new()));
        assert!(same_secret("abc", "abc"));
        assert!(!same_secret("abd", "abc"));
        assert!(!same_secret("ab", "abc"));
    }

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
