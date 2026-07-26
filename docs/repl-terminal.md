# Native REPL implementation and terminal plan

2026-07-15. **Normative for the REPL process split, terminal substrate, and
Linux/macOS interaction envelope.** [repl.md](repl.md) remains authoritative
for Slog identities and session behavior; [repl-ux.md](repl-ux.md) describes
the intended experience.

The first connected vertical slice now exists. Running the copied `./slog`
binary starts a Rust terminal application, which launches the sole Racket
REPL entry point, `compiler/repl.rkt`. Racket owns compilation, a registry of
persistent `compiler/session.rkt` objects, and one C++ daemon per resident
session. Rust owns terminal input,
editing, layout, rendering, and process supervision. There is no longer a
Racket Expeditor or `repl-x.rkt` frontend.

## 1. Decision

Use Rust for the native terminal client and keep the language/database control
plane in Racket:

```text
terminal
   │ keys, paste, resize
   ▼
repl/src/main.rs       one terminal owner and asynchronous event loop
   ├── app.rs          state reducer, command history, transcript policy
   ├── editor.rs       grapheme-aware multiline editing
   ├── ui/             Ratatui layout and Slog-specific presentation widgets
   ├── share.rs ────── trusted-local line stream for shell co-authors
   └── backend.rs
          │ authenticated Content-Length JSON, loopback TCP
          ▼
compiler/repl.rkt      command dispatch and lazy database-session registry
   └── session.rkt     compilation, recipe/session state, daemon ownership
          ▼
       slogd           one process per resident session
```

This split gives the UI a mature low-level terminal stack without moving Slog
semantics out of Racket or embedding Racket in the UI process. It also makes
the wire boundary real enough for later editor, notebook, or remote frontends
to reuse. `compiler/run.rkt` remains a separate batch command and never enters
the interactive process tree.

## 2. Why Crossterm and Ratatui

`crossterm` is the low-level portability layer. It supplies raw mode,
alternate-screen control, keyboard/paste/resize events, cursor operations,
styles, and terminal cleanup on Unix terminals. It is the layer to use when a
Slog interaction eventually needs exact escape-sequence or event control.

`ratatui` supplies a retained cell buffer, layout constraints, clipping,
Unicode-aware text widgets, and differential rendering. It naturally supports
fixed regions, contextual sidebars, and an independently scrollable transcript.
It does not impose an application architecture: our
state, editor, command model, and Slog presentation widgets remain ordinary
Rust modules.

The alternatives are less suitable for this project:

| substrate | assessment |
|---|---|
| Racket Expeditor | excellent multiline Racket expression editor, but not a whole-screen composition API |
| private Racket `#%terminal` | granular but an unstable implementation interface; would require building the widget/rendering stack ourselves |
| ncurses/PDCurses wrappers | mature screen control, but add a native ABI/deployment dependency and a global screen model; no advantage over the Rust cell-buffer stack here |
| Rust `reedline`/`rustyline` | strong shell-style line editors, but awkward for a fixed header/sidebar plus asynchronous structured results |
| Rust `termwiz`/`crossterm` alone | maximum control, appropriate below a custom renderer, but too much repaint and layout machinery for the first REPL |
| Rust `tui-realm`/Cursive | more prescriptive component frameworks than needed; Ratatui leaves the Slog architecture exposed |

The control escape hatch is deliberate: Ratatui widgets can be replaced one
panel at a time, custom cell-buffer widgets can be added directly, and raw
Crossterm commands remain available. We do not need to go down to ncurses or
termios to build the intended UI.

## 3. Current product envelope

The first frontend is a full-screen workbench. It demonstrates the hard
layout and terminal cases early:

- a large transcript/canvas with no permanent top chrome;
- a fixed multiline editor separated by one horizontal rule and a compact
  unboxed footer;
- no permanent sidebar in the shell, with a roughly 28%-wide contextual
  sidebar available to modes such as the database library;
- a transcript that follows new output and can be revisited with PageUp and
  PageDown or the mouse wheel;
- true color, modifiers, gauges, tables, box drawing, wide characters,
  combining graphemes, and emoji clusters;
- grapheme-aware cursor movement and deletion in the editor;
- bracketed paste, negotiated enhanced keyboard events, mouse capture, and
  terminal resize redraws through Crossterm; and
- a single writer, so daemon responses can never corrupt the edit buffer.

The full-screen choice uses the alternate screen, so normal shell scrollback
is not the session history. The application transcript is the durable UI
surface during a session. If field use shows that shell-native scrollback is
more valuable, add an inline renderer over the same `App`, backend, protocol,
and presentation model; do not weaken the server boundary to obtain it.

The supported release targets are modern Linux and macOS terminals, locally
or through SSH. WSL, VMs, and other VT-compatible environments may work but
are not initial release gates. Narrow terminals omit the sidebar. The shipped
`--plain` frontend consumes the same structured responses without initializing
Ratatui, raw mode, mouse capture, or the co-author listener; terminal
capability does not affect Slog semantics. Non-TTY stdout selects this path
automatically; `--plain` is the explicit form.

## 4. Private local protocol

Rust spawns `racket compiler/repl.rkt` with a fresh 256-bit token inherited in
`SLOG_REPL_TOKEN`. Racket binds one listener to `127.0.0.1`, selecting a high
port by default, and writes one JSON bootstrap announcement on its captured
stdout. Rust immediately connects and authenticates with the token and
protocol version.

All later traffic is JSON framed as:

```text
Content-Length: N\r\n
\r\n
N UTF-8 bytes
```

Frames are capped at 16 MiB. Requests carry an id, method, and parameters;
responses echo the id and contain either a structured result or structured
error. The first protocol version is intentionally request/response. Add
server events with the same envelope when watches and progress reporting need
them. The socket is transport-private, not a security boundary for hostile
local users; loopback binding, an unguessable per-process token, and a single
accepted connection prevent accidental attachment.

Racket sessions are lazy. `:status`, `:ping`, `:help`, and the read-only offline
`library` scan do not start `slogd`. `open NAME` creates one database-backed
session and retains it by name; opening it again switches to the existing
session, preserving its in-memory extensions. A different database gets a
different session and daemon. `run` before an open creates a distinguished
scratch session. Every exit path closes all resident sessions and child
processes. Ctrl-C/Ctrl-D is an interrupting exit: it aborts an in-flight
request immediately, drops the kill-on-drop Racket child, and closes the pipes
owned by any attached daemon. Graceful shutdown also has a one-second deadline
before taking the same abort path, so a blocked request cannot keep the terminal
process alive.

The first live exploration commands are `current`, `resident` (`sessions` is
a compatibility alias), `tables`,
`state`, `count`, bounded `show`, and prefix-existence `query`. They compose
the existing `schema`, `sizes`, `pipeline`, `dump-tuples`, and `lookup` action
plugins; no daemon source changes are required. `run`, `add`, and `del` extend
the selected session; `rename` and `drop` expose the corresponding settled
session environment operations; and `mode readonly` provides a REPL-side
mutation guard.

Successful semantic responses carry a structured `change` object in addition
to their bounded human-readable lines. It records the operation and target,
settled status, the daemon's **update revision** and counts-valid state,
requested direct tuple edits, sorted before/after relation-size observations,
and structured route records. `update-revision` is deliberately not called a
boundary or `dbN`: rename/drop do not advance that fact-update counter, and
only N2/N3 can supply the real BoundaryKey-backed timeline. Likewise,
`requested` is not a claim that a tuple changed—normalization may make an add
or delete a no-op; the before/after relation observations are the settled
effect. Those observations are relation cardinalities, not a tuple diff or a
claim that support/provenance state was unchanged. They are bounded
presentation evidence; consumers must preserve the distinction in both labels
and logic.

Summary observations are best effort and can report unavailable/unknown; a
failed post-commit observation must never turn a successful session operation
into a command failure. A deterministic server-contract transcript harness
round-trips every result through the actual JSON framing and pins open,
add/delete, rename/drop, and shutdown against a golden. The Rust executable's
`--plain` path now drives that same sequence over the real loopback protocol
and byte-compares its stdout with the golden. Its `CommandResult` projection
is also the canvas's result decoder, while display-only canvas state stays out
of the compiler response.

Plain mode is deliberately line-oriented: one input line is one command, with
`run PATH` covering multiline Slog. EOF performs graceful shutdown; a response
with `close` stops consumption; command refusals remain transcript entries,
while transport loss is a failing process exit. `stage`/`flush` and `inject`
remain deferred until their ownership and anchoring rules are explicit:
whether a staged buffer follows or pins the selected session, what switching
or failure does to it, whether a flush is atomic, and which BoundaryKey an
anchored operation names. A temporary update counter must not masquerade as
that boundary.

### 4.1 Trusted-local co-author protocol

The Rust client also owns a second loopback listener. This listener is not the
private compiler protocol above: it is an intentionally unauthenticated
collaboration socket for other users and tools already trusted on the local
machine. Every REPL binds its own ephemeral `127.0.0.1` port, so simultaneous
sessions coexist without port configuration.

Discovery records are published as
`/tmp/slog-repl.<pid>.<port>.json` with mode `0644`. Protocol version, PID,
endpoint, project root, start time, and current database are sufficient for a
human or agent to choose among instances. Normal shutdown removes the record;
clients must treat a record whose PID no longer exists as stale. `:share`
prints the endpoint and exact discovery path inside the REPL.

Protocol version 1 is newline-delimited UTF-8, capped at 64 KiB per input
line. `/name NAME` supplies an advisory author label. A line beginning with
`;` is a shared transcript comment and never reaches Racket. Commands use two
visibility lanes:

1. `COMMAND` is shared, echoed once in compact dim form when execution begins,
   and broadcast with its result. Burst input waits outside the transcript so
   commands never appear detached from their eventual responses.
2. `/private COMMAND` is a targeted observation. Its command and response go
   only to the requesting socket and never enter the terminal transcript. A
   verb allowlist excludes mutations, save, mode changes, and shutdown. The
   envelope changes visibility only; the echoed action remains `COMMAND` with
   a `[private]` annotation.

Interactive state is changed with the same commands available at the prompt.
For the library these are `library select NAME`, `open NAME`, and `library
close`. Terminal arrows, paging keys, mouse selection, Enter, and Escape
compile to those commands and publish their dim generated-command form. A
future structured event may carry visibility, author, and presentation fields,
but must also carry a canonical command a terminal author could type; it may
not introduce event-only behavior.

On attachment, a peer receives a banner, a plain-text snapshot of the durable
transcript, and an explicit `◇ View` description. Mode transitions publish a
full inventory; selection changes publish concise focus details. Terminal
animation is reduced to stable progress-stage and completion events such as
`Loading database ... · waiting for the database runtime`. The TCP
representation is semantic rather than a terminal cell/keystroke mirror.

This establishes three distinct lifetimes for future REPL features: durable
shared transcript entries, temporary workflow rows, and replicated view state.
New menus and inspectors must define a canonical command, terminal rendering,
and a bounded co-author representation before they are considered complete.

Transient rows belong to Rust application state rather than the durable
transcript. Database loading uses an unmarked, indented temporary line. Its
animated dots occupy a fixed three-cell field (`.  `, `.. `, `...`) so the
following detail never moves horizontally. The detail advances through honest elapsed-time states: request
sent, waiting for the runtime, compressed replay may be active, and finally an
explicit statement that finer progress is unavailable. Plain co-authors receive
only those stable stage changes, never animation frames. The backend response
removes the row and commits either the green diamond result or an error.

Before `open`, the Rust client mirrors the Racket driver's read-only stale
runtime check. If a daemon header or C++ source is newer than `daemon/slogd`,
the row starts with `daemon sources changed; rebuilding the database runtime`.
This is especially important in a development checkout: `make-session` performs
that rebuild synchronously before it can load any database. The check predicts
the existing behavior; Rust neither builds nor modifies the daemon itself.

Relation and tuple progress requires a streamed backend event rather than a UI
guess. Its eventual semantic shape should identify the originating command and
carry `phase`, optional `relation`, `completed`, `total`, and `unit` fields.
The REPL may render `relation path · tuples 2,352/18,437` and a determinate bar
only when both counts are supplied; otherwise it renders an indeterminate stage.
The co-author representation receives a bounded event when the phase or
relation changes and rate-limited count checkpoints. Progress remains output
of the human-runnable `open NAME` command, never a separate hidden action.

This temporary/commit model is the general mechanism for future cancellable
progress, confirmations, and in-shell workflows.

## 5. Source and library boundaries

The Rust crate lives in `repl/`, parallel to `compiler/`:

```text
repl/Cargo.toml         dependency and binary definition
repl/Makefile           build and copy target
repl/src/main.rs        terminal lifecycle; the only module that draws
repl/src/app.rs         pure-ish application transitions and effects
repl/src/editor.rs      text/grapheme model, independent of Ratatui
repl/src/protocol.rs    typed framing and handshake
repl/src/backend.rs     Racket child and asynchronous request queue
repl/src/share.rs       trusted-local discovery and co-author line stream
repl/src/ui/            layout and presentation widgets
```

Keep these dependency rules:

1. `ui` may read `App` but never starts work or talks to the server.
2. `App` returns effects but never writes a terminal or socket.
3. `editor` has no terminal or protocol dependency.
4. `protocol` knows framing, not Racket processes or Slog commands.
5. `backend` owns the child and connection, not presentation.
6. only the main loop combines terminal events, backend events, effects, and
   redraws.

The shipped `present` module produces budgeted typed trees before Ratatui sees
them. The first R1 adapter maps bounded result lines plus structured semantic
change records into the live canvas; independent depth, node, item, and string
budgets leave expandable markers. Gestures and typed `expand`/`collapse`
commands use the same expansion paths, so there remains one semantic path. The
selected semantic node may also publish a contextual card: `o` and typed or
co-author `card POSITION` use the same client-owned reducer, and the card lists
canonical actions including `card close`. Requested edits remain explicitly
distinct from settled relation-size observations; neither is presented as a
tuple diff or provenance proof.

The terminal-independent `completion` model now owns token replacement,
candidate ordering, and selection. Tab completes the shipped verb grammar,
mode arguments, database names learned from structured resident/library
records, and valid positions in the live canvas. Unique candidates apply
directly; ambiguous candidates render in a bounded menu. It deliberately does
not derive relation or namespace names from runtime size observations or saved
relation directories. Those candidates require the selected boundary catalog
specified by repl.md §3. Rich schema/value/proof adapters, catalog and
embedded-Slog completion remain later slices.

Canvas search also stays inside `present`: a case-insensitive query is matched
against the currently rendered lines after all depth, node, item, and string
budgets. `/` opens an incremental preview, Enter publishes `search TEXT`, Esc
restores the prior selection/search, and n/N publish
`search-next`/`search-previous`; typed and co-author forms use the same reducer.
Collapsed descendants are not searched until their canonical expand action
makes them visible. Search changes no compiler result or plain projection.

Collection-item truncation is now a real client-buffered page boundary rather
than an expand-to-the-rest affordance. Each marker reports its exact remaining
or prior item count and current/total pages. Enter emits the absolute
`page POSITION NUMBER` command; typed and co-author forms use the same
client-owned reducer, and completion offers only visible paged collections and
in-range page numbers. Cards close when their node leaves the current page,
and search sees only that page.

This does not claim the Q1 continuation protocol. It only pages nodes already
present in the bounded compiler response—such as `show REL all` under its
existing 200-row safety cap, help lines, and structured relation observations.
Default `show REL` retains its honest `show REL all` continuation. Daemon-side
`query`/`query-page`/`query-cancel` now admit canonical exact-VersionKey
payloads, but `more` and cancellation remain unconnected here until the
friendly R2 parser/register is built over N3-B's truthful boundary identity.

The first schema-side adapter now consumes N3-B's structured current-boundary
catalog. `tables` retains a JSON-safe `relations` observation for the current
live session: name, daemon-reported kind and arity, schema detail, row count,
exact VersionKey, and selected BoundaryKey, plus filter/scope totals.
`present` maps that additive field to a budgeted relation tree and cards
offering `count`, `show`, and `state`; cards display the real identity pair
and say explicitly when a legacy environment event has left no committed
boundary selected. The completion inventory still waits for N4's persistent
historical/additive catalog. Plain mode continues to render only the existing
`lines`.

Structured tuple/value rendering remains deferred until the client can retain
evaluation, boundary-naming, and TypeDescriptor/value-handle context. Proof
trees remain downstream of provenance support. This avoids freezing an
accidental JSON encoding of daemon words or treating current names as durable
identity.

## 6. Build, demos, and gates

From the repository root:

```console
$ make -C repl
$ ./slog
```

The build copies `repl/target/debug/slog` to the ignored root `slog` path.
`make -C repl release` does the same with the release build. The current
server commands include `library`, `open`, `current`, `resident`, `mode`,
`tables`, `state`, `count`, `show`, `query`, `run`, `add`, `del`, `save`, the
raw `schema`/`pipeline` views, and the general `:help`/`:status`/`:ping`/`:quit`
set. Client-local commands include `:clear` and `:share`.

The minimum gates for changes are:

- Rust unit tests for editor/state/protocol helpers and Ratatui `TestBackend`
  rendering tests;
- the real Rust `--plain` executable driven through the semantic-session
  command stream, byte-identical to the server-contract golden;
- Racket frame, authentication/dispatch, and session tests;
- a PTY smoke test that boots the alternate screen, runs `:status`, starts the
  daemon with `pipeline`, and restores the terminal after `:quit`; and
- Linux and macOS CI once native REPL distribution begins.
