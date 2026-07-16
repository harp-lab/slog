# Native REPL implementation and terminal plan

2026-07-15. **Normative for the REPL process split, terminal substrate, and
Linux/macOS interaction envelope.** [repl.md](repl.md) remains authoritative
for Slog identities and session behavior; [repl-ux.md](repl-ux.md) describes
the intended experience.

The first connected vertical slice now exists. Running the copied `./slog`
binary starts a Rust terminal application, which launches the sole Racket
REPL entry point, `compiler/repl.rkt`. Racket owns compilation, the persistent
`compiler/session.rkt` object, and the C++ daemon. Rust owns terminal input,
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
   └── backend.rs
          │ authenticated Content-Length JSON, loopback TCP
          ▼
compiler/repl.rkt      command dispatch and one lazy compiler session
   └── session.rkt     compilation, recipe/session state, daemon ownership
          ▼
       slogd
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
a fixed top header, fixed bottom editor, right sidebar, and independently
scrollable transcript. It does not impose an application architecture: our
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

- a fixed three-line header and fixed multiline editor/footer;
- a right-side session/status column when the terminal is wide enough;
- a transcript that follows new output and can be revisited with PageUp and
  PageDown;
- true color, modifiers, gauges, tables, box drawing, wide characters,
  combining graphemes, and emoji clusters;
- grapheme-aware cursor movement and deletion in the editor;
- bracketed paste through Crossterm and terminal resize redraws; and
- a single writer, so daemon responses can never corrupt the edit buffer.

The full-screen choice uses the alternate screen, so normal shell scrollback
is not the session history. The application transcript is the durable UI
surface during a session. If field use shows that shell-native scrollback is
more valuable, add an inline renderer over the same `App`, backend, protocol,
and presentation model; do not weaken the server boundary to obtain it.

The supported release targets are modern Linux and macOS terminals, locally
or through SSH. WSL, VMs, and other VT-compatible environments may work but
are not initial release gates. Narrow terminals omit the sidebar. A later
plain/non-TTY frontend should consume the same structured responses; terminal
capability must never affect Slog semantics.

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

The Racket session is lazy. `status`, `ping`, and `help` do not start `slogd`;
`run`, `open`, `schema`, `pipeline`, or `save` create one session and retain
it until `quit`, EOF, client failure, or process shutdown. Every exit path
closes that session and the child process.

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

Future `present` and command-language modules should produce typed trees and
command ASTs before adding rich schema/value/proof widgets. Gestures must
produce the same command AST as typed input so there remains one semantic
path.

## 6. Build, demos, and gates

From the repository root:

```console
$ make -C repl
$ ./slog
```

The build copies `repl/target/debug/slog` to the ignored root `slog` path.
`make -C repl release` does the same with the release build. The current
server commands are `help`, `status`, `ping`, `run PATH`, `open NAME`,
`schema`, `pipeline`, `save NAME`, and `quit`. Client-only forcing-function
demos are `:demo colors`, `:demo layout`, `:demo unicode`, and `:demo off`.

The minimum gates for changes are:

- Rust unit tests for editor/state/protocol helpers and Ratatui `TestBackend`
  rendering tests;
- Racket frame, authentication/dispatch, and session tests;
- a PTY smoke test that boots the alternate screen, runs `status`, starts the
  daemon with `pipeline`, and restores the terminal after `quit`; and
- Linux and macOS CI once native REPL distribution begins.
