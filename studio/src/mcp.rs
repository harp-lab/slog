//! `POST /mcp`: the tools an agent uses to read, change, and test the
//! program, as a JSON-RPC MCP server (plain request/response HTTP, as in the
//! slides app). Each Studio's agent has its own bearer token, so the token
//! both admits a call and names the project it may touch; the call is
//! attributed to the thread its `x-studio-thread` header names.

use crate::agent::THREAD_HEADER;
use crate::registry::Registry;
use crate::review::Change;
use crate::studio::Studio;
use axum::http::{HeaderMap, StatusCode, header};
use axum::response::{IntoResponse, Response};
use serde_json::{Value, json};
use std::sync::Arc;

pub async fn handle(registry: &Registry, headers: HeaderMap, body: String) -> Response {
    let bearer = headers
        .get(header::AUTHORIZATION)
        .and_then(|value| value.to_str().ok())
        .and_then(|value| value.strip_prefix("Bearer "));
    let Some(studio) = bearer.and_then(|token| registry.by_mcp_token(token)) else {
        return StatusCode::UNAUTHORIZED.into_response();
    };
    let thread = headers
        .get(THREAD_HEADER)
        .and_then(|value| value.to_str().ok())
        .and_then(|value| value.parse::<u32>().ok());
    let request: Value = match serde_json::from_str(&body) {
        Ok(request) => request,
        Err(error) => return rpc_error(Value::Null, -32700, &format!("parse error: {error}")),
    };
    // A notification (no id) expects no answer.
    let Some(id) = request.get("id").cloned() else {
        return StatusCode::ACCEPTED.into_response();
    };
    let result = match request["method"].as_str().unwrap_or("") {
        "initialize" => json!({
            "protocolVersion": "2025-06-18",
            "capabilities": { "tools": {} },
            "serverInfo": { "name": "slog-studio", "version": env!("CARGO_PKG_VERSION") },
        }),
        "ping" => json!({}),
        "tools/list" => json!({ "tools": tools() }),
        "tools/call" => {
            let name = request["params"]["name"].as_str().unwrap_or("");
            let arguments = &request["params"]["arguments"];
            match call(&studio, thread, name, arguments).await {
                Ok(value) => {
                    let mut result = json!({
                        "content": [{ "type": "text", "text": serde_json::to_string_pretty(&value).unwrap_or_default() }],
                        "isError": false,
                    });
                    // Structured content must be an object; clients refuse a
                    // result whose structured content is a list.
                    if value.is_object() {
                        result["structuredContent"] = value;
                    }
                    result
                }
                // A tool failure is a result the model reads, not a protocol error.
                Err(message) => json!({
                    "content": [{ "type": "text", "text": message }],
                    "isError": true,
                }),
            }
        }
        "resources/list" => json!({ "resources": [] }),
        "prompts/list" => json!({ "prompts": [] }),
        method => return rpc_error(id, -32601, &format!("unknown method {method}")),
    };
    (
        [(header::CONTENT_TYPE, "application/json")],
        json!({ "jsonrpc": "2.0", "id": id, "result": result }).to_string(),
    )
        .into_response()
}

fn rpc_error(id: Value, code: i64, message: &str) -> Response {
    (
        [(header::CONTENT_TYPE, "application/json")],
        json!({ "jsonrpc": "2.0", "id": id, "error": { "code": code, "message": message } }).to_string(),
    )
        .into_response()
}

async fn call(studio: &Arc<Studio>, thread: Option<u32>, name: &str, arguments: &Value) -> Result<Value, String> {
    let thread = thread.ok_or("this MCP session names no thread; the studio's agent runs set one")?;
    let text = |key: &str| {
        arguments[key]
            .as_str()
            .map(str::to_owned)
            .ok_or_else(|| format!("missing string argument `{key}`"))
    };
    let note = arguments["note"].as_str().unwrap_or("").to_owned();
    match name {
        "get_program" => Ok(studio.program_for(thread)),
        "propose_edit" => studio.propose(
            thread,
            Change::Edit {
                old: text("old_text")?,
                new: text("new_text")?,
            },
            note,
        ),
        "propose_append" => studio.propose(thread, Change::Append { source: text("source")? }, note),
        "evaluate_proposal" => Ok(studio.evaluate_fork(thread).await),
        "query" => studio.query_fork(thread, &text("q")?).await,
        "get_proposals" => Ok(studio.proposals_of(thread)),
        // the execution tools (trace.rs)
        _ => match studio.trace_tool(thread, name, arguments).await {
            Some(result) => result,
            None => Err(format!("unknown tool {name}")),
        },
    }
}

fn tools() -> Value {
    let object = |properties: Value, required: &[&str]| {
        json!({ "type": "object", "properties": properties, "required": required })
    };
    let note = json!({
        "type": "string",
        "description": "One sentence for the author: what this changes and why. Shown beside the diff."
    });
    let mut tools = json!([
        {
            "name": "get_program",
            "description": "The program as your proposals so far would leave it (the author's current text with your pending proposals applied), with its file name. Read it before proposing.",
            "inputSchema": object(json!({}), &[]),
        },
        {
            "name": "propose_edit",
            "description": "Propose replacing an exact piece of the program text with new text. `old_text` must occur exactly once in get_program's text: include whole forms or enough context to be unique. Nothing changes until the author accepts.",
            "inputSchema": object(json!({
                "old_text": { "type": "string", "description": "Exact text to replace, occurring once." },
                "new_text": { "type": "string", "description": "Its replacement (may be empty to delete)." },
                "note": note,
            }), &["old_text", "new_text", "note"]),
        },
        {
            "name": "propose_append",
            "description": "Propose adding new top-level forms (declarations, rules, facts) at the end of the program. Nothing changes until the author accepts.",
            "inputSchema": object(json!({
                "source": { "type": "string", "description": "Slog source of the new forms." },
                "note": note,
            }), &["source", "note"]),
        },
        {
            "name": "evaluate_proposal",
            "description": "Evaluate the program as your proposals would leave it, from nothing, in a fresh session separate from the author's. Returns each relation with its row count, or the error (with its line in get_program's text). Run it after proposing, before you reply.",
            "inputSchema": object(json!({}), &[]),
        },
        {
            "name": "query",
            "description": "Run a `?` query against the evaluation of your proposed program, e.g. `?(path 1 Y)`, `? (edge X Y) (edge Y Z) -> (X Z)`, `?count (path X Y)`. Variables are capitalized; `_` matches anything.",
            "inputSchema": object(json!({
                "q": { "type": "string", "description": "A query starting with `?`." },
            }), &["q"]),
        },
        {
            "name": "get_proposals",
            "description": "Your proposals in this thread: status (pending, accepted, rejected), whether each still applies (stale), and conflicts with other threads.",
            "inputSchema": object(json!({}), &[]),
        },
    ]);
    tools.as_array_mut().expect("a list").extend(crate::trace::tools());
    tools
}
