# Slog native REPL

This directory is the Rust terminal frontend. It deliberately contains no
compiler or database semantics. On startup it launches
`compiler/repl.rkt`, connects to that process over an authenticated
loopback-only TCP socket, and renders replies with Ratatui and Crossterm.

Build and copy the development executable to the repository root:

```console
$ make -C repl
$ ./slog
```

The current vertical slice supports several databases resident in one shared
REPL. The
main commands are:

```text
library                  browse data/*
open NAME                load NAME, or switch back to its resident copy
current                  describe the selected database
resident                 list databases currently held in memory
mode readonly|mutable    protect or unlock the selected database

tables [FILTER]          live relation schemas and row counts
state [REL]              pipeline summary and relation version state
count REL                current row count
show REL [LIMIT]         rows from a small relation (hard cap: 200)
query REL V...           prefix-existence query

run PATH                 extend the database with a Slog program
add REL V...             add one tuple and propagate
del REL V...             retract one tuple and propagate
save NAME                save the in-memory database

; COMMENT                add a shared transcript comment; do not invoke Slog
:share                   show this REPL's co-author address and discovery file
```

`schema` and `pipeline` retain the raw daemon-facing views, and `help`,
`status`, `ping`, and `quit` remain available. Daemons start lazily. Opening a
database creates an independent compiler workspace and daemon; switching away
does not discard its in-memory extensions. `mode readonly` is a REPL-side
guard around mutating commands, not a different database representation.

`library` opens the first reusable contextual view: a selectable inventory of
`data/*` databases with stored facts and disk size. Arrow keys, PageUp/PageDown,
the mouse wheel, and row clicks change the selection; the contextual sidebar
shows metadata and the persisted table/struct/lattice schema. Enter translates
the selection into a dim `open NAME` command. A filled dot marks the current
resident database and a hollow dot marks another resident database. Esc or `q`
returns to the full-width shell.

Compressed databases use `session-open!`'s existing load plan: retained data
is imported and stored program/recipe layers are replayed when recomputation is
required. The exploratory query surface deliberately works with current daemon
capabilities. `show` only streams relations of at most 200 rows; use `count` or
the prefix-existence `query` for larger relations.

Opening a database is represented as a transient shell workflow. While the
backend loads retained data and replays compressed layers, the local terminal
shows an amber rotating line and animated dots. The temporary row is not part
of history. A successful response replaces it with the durable green
`◆ Loaded database \`NAME\`` result; an error similarly freezes as a durable
error. Co-author connections receive one fixed `Loading database ...` line
for each meaningful stage change instead of terminal animation frames. Current
details are deliberately honest and elapsed-time based (`request sent`,
`waiting for the database runtime`, and eventually an acknowledgement that
relation/tuple progress is not exposed). Measured relation names, tuple counts,
and progress bars require a future streamed backend progress event.

## Trusted-local co-author socket

Every REPL instance also opens an independent, unauthenticated listener on an
ephemeral `127.0.0.1` port. This is intentionally a collaboration surface for
users already trusted on the same machine, separate from the authenticated
private Rust-to-Racket socket. Type `:share` for the current endpoint, or find
all running instances through:

```console
$ ls /tmp/slog-repl.*.*.json
$ cat /tmp/slog-repl.1234.45678.json
```

Each world-readable discovery record contains the process id, endpoint,
project root, start time, and current database. Those fields let an outside
tool distinguish simultaneous REPLs; it should also verify that the recorded
PID still exists because an abnormal process exit can leave a stale record.
Normal shutdown removes the file.

The first wire version is deliberately human-friendly, line-delimited UTF-8:

```console
$ nc 127.0.0.1 45678
/name codex
; I am going to inspect edge
tables edge
/private count edge
```

On connection the peer receives a protocol banner, a plain-text snapshot of
the durable transcript, the current replicated view, then live output.
`/name NAME` sets an advisory display name. Input has two visibility lanes:

- `COMMAND` is shared. It appears as one compact dim line such as
  `› tables edge — codex`, then enters the serialized Racket request queue.
  Bursts remain off-transcript until each command actually begins.
- `/private COMMAND` is returned only to that TCP connection and never painted
  in the terminal. The visibility envelope is not a separate capability: its
  echo is the ordinary command with a `[private]` annotation. This lane accepts
  observations such as `library`, `tables`, `state`, `count`, `show`, and
  `query`; mutation, save, mode changes, and quit are rejected.

A line beginning with `;` remains a visible shared comment without invoking
Racket. Interactive views are controlled by ordinary commands: the library
uses `library select NAME`, `open NAME`, and `library close`. Arrow keys, mouse
selection, Enter, and Escape compile to those same commands and publish them as
dim generated-command lines. Interactive modes publish a text inventory and
selected-item details; animation publishes stable start/completion events.
Thus a headless peer acts on the same semantics without receiving terminal
escape sequences or a copy of the cell buffer. Input lines are capped at 64
KiB.

Source boundaries:

- `app.rs`: state and event reduction; no terminal output or TCP;
- `editor.rs`: grapheme-aware editable command buffer;
- `protocol.rs`: Content-Length-framed JSON over TCP;
- `backend.rs`: Racket child lifecycle and session request queue;
- `share.rs`: trusted-local discovery, line protocol, and transcript fan-out;
- `ui/`: pure-ish Ratatui rendering and Slog-specific widgets;
- `main.rs`: the single terminal owner and asynchronous event loop.

The UI is intentionally a full-screen workbench in this first demo so the
contextual inspector, lightweight multiline editor, colors, and wide characters
are all exercised. PageUp/PageDown or the mouse wheel revisit the session
transcript without moving the editor cursor. Alt+Enter inserts an editor newline;
Ctrl+J is a portable fallback. The same app model can support
an inline-scrollback frontend later without changing the server protocol.
