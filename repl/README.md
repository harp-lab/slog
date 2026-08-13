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

For scripts, CI, redirected output, and golden transcripts, use the same
executable without terminal control:

```console
$ printf ':status\n:quit\n' | ./slog --plain
```

Plain mode reads one command per input line, sends semantic commands through
the same framed Racket backend, and writes the canonical transcript to stdout.
Server diagnostics use stderr. It starts no alternate screen, raw input,
mouse capture, or co-author listener. Redirecting stdout selects it
automatically; `--plain` makes the choice explicit. Use `run PATH` for
multiline Slog in this first line-oriented slice.

In the full-screen client, the newest successful result is a live canvas.
With an empty editor, Tab enters navigate mode; arrows or j/k select, Enter
toggles an expandable node, left/h/backspace collapses, right/l expands, and
Esc or q returns to the prompt. Semantic mutations keep the default transcript
to a short outcome such as `committed`, then expose a collapsed
`▸ Change details` tree built from their structured `change` record. Every
gesture echoes the client command it performs, such as
`expand it.change`; typing that command takes the identical path. Press o on
a semantic node to open its contextual card. The equivalent
`card POSITION` command works when typed or received from a co-author, and
`card close` closes the sidebar. Change cards distinguish requested edits
from observed settled cardinalities; they do not claim a tuple diff or
provenance proof. Press `/` in navigate mode to search the currently visible
canvas lines. Search is incremental and case-insensitive; Enter commits the
canonical `search TEXT` action, Esc cancels the preview, and n/N emit
`search-next`/`search-previous`. `search-clear` clears the active search.
Collapsed children become searchable only after expansion.

Collections already present in a result are paged by the same item budget.
A continuation marker reports the remaining item count and current/total
pages; selecting it with Enter emits an absolute command such as `page it 2`.
`page POSITION NUMBER` works identically when typed or received from a
co-author, and Tab completes only currently visible paged positions and valid
page numbers. Search covers only the current visible page. This is
client-buffered pagination, not the canonical Q1 daemon query cursor: the
current Rust/Racket frontend has not connected that exact-VersionKey surface,
so `show REL` still directs users to `show REL all` when more rows exist, and
`show REL all` remains hard-capped at 200.

`tables` preserves its original bounded lines and also publishes structured
current-session relation observations. The full-screen canvas adds a collapsed
`Live relation observations` tree; each relation expands to kind, arity, row
count, and schema detail, while its card offers `count`, `show`, and `state`.
These are current live names, not BoundaryKey/VersionKey catalog identities,
and the completer deliberately does not treat them as the future boundary
catalog.

With text in the editor, Tab completes command verbs, mode arguments,
structured resident/library database names, and positions in the current live
canvas. A unique match is applied immediately. Multiple matches open a bounded
menu: Tab or Down selects the next candidate, Shift-Tab or Up selects the
previous one, Enter accepts, and Esc closes the menu. Relation and namespace
names are intentionally not inferred from row-count observations or saved
relation directories; they join this same completion model when the selected
boundary catalog becomes a structured server contract.

The current vertical slice supports several databases resident in one shared
REPL. The
main commands are:

```text
library                  browse data/*
csv-import FOLDER        infer comma/whitespace files into a fresh binary database
csv-import FOLDER as N   use the explicit database name N (which must not exist)
open NAME                load NAME, or switch back to its resident copy
current                  describe the selected database
resident                 list databases currently held in memory
discard session          close the current in-memory session without saving
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
:help                    show the command reference
:tutorials               browse and run interactive tutorials
:status                  show REPL, database, and daemon state
:share                   show this REPL's co-author address and discovery file
:quit                    close the REPL

page POSITION NUMBER     select an absolute buffered-canvas page
```

## Interactive tutorials

`:tutorials` opens the terminal tutorial catalog. Tutorial definitions live
under `repl/tutorials/` as one versioned TOML file per tutorial. They contain
only ordinary comments, commands, checkpoints, and literal-answer challenges;
there is no second Slog evaluator or hidden shell-command lane. Generated
commands travel through the same serialized backend queue as typed commands,
and each step waits for the real response before continuing.

Starting a tutorial with resident in-memory workspaces asks for confirmation,
then replaces only this REPL's private Racket backend with a fresh one. Saved
databases on disk and the existing transcript are retained. Escape stops a
tutorial without closing its current session. During automatic typing, Space
pauses and Right Arrow finishes the current entry immediately. Tutorial
narration is committed to the shared transcript as semicolon comments; a blue
blinking prompt marks literal-answer challenges, and every attempted answer is
available through normal Up/Down command history.

The first shipped lesson imports `repl/tutorials/data/edge-csv/edge.csv`,
establishes its automatically inferred logical input declaration, and builds
transitive closure through ordinary scratch definitions. The sequel imports
weighted edges and builds a bounded, demand-driven path search whose answers
carry both readable routes and summed costs. The third lesson uses string
built-ins and first-class lists and sets to reshape a small message stream. The
fourth builds a demand-driven k-CFA for the unary lambda calculus, including
closure environments held in first-class maps and a bounded call-string store.
`csv-import` derives a database name from the folder and adds a numeric suffix
when needed, so repeating either import lesson never replaces an existing
database. An explicit `as NAME` refuses to overwrite as well.

The first file format is:

```toml
format = 1
id = "example"
title = "Example tutorial"
summary = "What the tutorial demonstrates."
session = "fresh"
typing_wpm = [147, 173]
effects = ["discard-session"]

[[steps]]
type = "comment"
text = "Narration is typed as a shared comment."

[[steps]]
type = "command"
text = ":status"
speed = 140 # optional percentage for mechanically dull text such as paths
# typing = "code" types multiline code at about 8× speed without pauses

[[steps]]
type = "challenge"
prompt = "Type a status command:"
answers = [":status", "status"]
fallback = ":status"
attempts = 1
```

`speed` is an optional percentage on any step (100 is the tutorial's base
cadence). Narration may use `{{database}}` to name the database most recently
reported by the real session, including an automatically chosen numeric
suffix. Multiline command steps can set `typing = "code"` to emit code at
roughly eight times natural speed with no word or punctuation pauses.

Challenges use token-equivalent matching by default, so irrelevant spacing is
accepted. A rule challenge may set `match = "slog-rule"`; that additionally
accepts consistent variable renaming, reordered body clauses, and either
`<--` or reversed `-->` direction. Other challenge shapes should normally use
one attempt until they have an equally honest structural matcher.

An unrecognized challenge answer is not executed. After its attempt budget is
used, the runner types a comment and demonstrates the declared fallback. TOML
files reject unknown fields, unsupported format versions, invalid typing
ranges, duplicate IDs, and fallbacks not present in their answer list.

`schema` and `pipeline` retain the raw daemon-facing views, and `:ping` tests
the private backend connection. Daemons start lazily. Opening a
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
  `query`; mutation, save, mode changes, and `:quit` are rejected.

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

- `lib.rs`: presentation-neutral REPL model exported independently of the
  terminal binary;
- `command.rs`: canonical shell input, origin/visibility, and shallow
  `: / ? / ! / source / ;` classification;
- `completion.rs`: pure command/argument candidate selection over structured
  client inventory; no terminal or compiler dependency;
- `transcript.rs`: durable shell events and their plain co-author projection;
- `operation.rs`: generic temporary workflow lifecycle; animation remains a
  terminal rendering choice;
- `present.rs`: budgeted presentation trees, expansion paths, live-canvas
  navigation state, and contextual card actions;
- `response.rs`: the shared structured-result projection consumed by plain
  mode and the canvas;
- `workspace.rs`: revision-safe Slog drafts and compiler
  pending/accepted/rejected state;
- `app.rs`: terminal application state and event reduction; no terminal output
  or TCP;
- `editor.rs`: grapheme-aware editable command buffer;
- `protocol.rs`: Content-Length-framed JSON over TCP;
- `backend.rs`: Racket child lifecycle and session request queue;
- `runtime.rs`: typed semantic-change observations and per-session projections;
- `share.rs`: trusted-local discovery, line protocol, and transcript fan-out;
- `ui/`: pure-ish Ratatui rendering and Slog-specific widgets;
- `main.rs`: the single terminal owner and asynchronous event loop.

The new core types intentionally stop at the current backend boundary. Rust
classifies interaction intent but does not parse Slog or infer successful
compilation. A draft only becomes accepted when a future compiler/session
response returns the exact submitted revision; stale replies are rejected.
Likewise, runtime tables are projections of structured response fields, never
scraped from human-readable transcript lines. This lets catalog, diagnostic,
preview, and boundary-key contracts land additively when the backend work is
ready.

The UI is intentionally a full-screen workbench in this first demo so the
contextual inspector, lightweight multiline editor, colors, and wide characters
are all exercised. PageUp/PageDown or the mouse wheel revisit the session
transcript without moving the editor cursor. Alt+Enter inserts an editor newline;
Ctrl+J is a portable fallback. `--plain` is the non-TTY rendering of the same
command/result model; a future inline-scrollback frontend can likewise reuse
it without changing the server protocol.
