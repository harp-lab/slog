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

The current vertical slice supports `help`, `status`, `ping`, `run PATH`,
`open NAME`, `schema`, `pipeline`, `save NAME`, and `quit`. The daemon starts
lazily on the first command that needs a live session.

Frontend-only forcing-function demos exercise the widget boundaries:

```text
:demo colors
:demo layout
:demo unicode
:demo off
```

Source boundaries:

- `app.rs`: state and event reduction; no terminal output or TCP;
- `editor.rs`: grapheme-aware editable command buffer;
- `protocol.rs`: Content-Length-framed JSON over TCP;
- `backend.rs`: Racket child lifecycle and session request queue;
- `ui/`: pure-ish Ratatui rendering and Slog-specific widgets;
- `main.rs`: the single terminal owner and asynchronous event loop.

The UI is intentionally a full-screen workbench in this first demo so the
fixed header, right inspector, multiline editor, colors, wide characters,
gauges, and tables are all exercised. PageUp and PageDown revisit the session
transcript without moving the editor cursor. The same app model can support
an inline-scrollback frontend later without changing the server protocol.
