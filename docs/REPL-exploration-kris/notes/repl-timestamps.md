# Logical timestamps and explorable session history

2026-10-06, branch `studio/repl-timestamps`. What Studio's REPL prompt
shows (`t7 ⟵ t6`), what a state is, and why going back to one re-derives it
rather than querying the daemon at an old boundary.

## States

A *state* is the session's database after a committed change. Studio
numbers them per studio, `t0, t1, …` (`studio/src/states.rs`):

| made by | kind | predecessor |
|---|---|---|
| nothing yet | `start` (t0) | none |
| Run (`run FILE` succeeded, not held) | `run` | the current state |
| a prompt line whose answer has `change.update-revision` (`add`, `del`, `flush`, a scratch rule, `rename`, `drop`, …) | `change` | the current state |
| a held run committed from the prompt (`continue`, …) | `run` | the current state |
| the session server restarted | `start` ("restart") | the current state |
| "branch from tN" | `branch` | tN |

Each state keeps the line that made it, the program version (`versions.rs`)
of its Run, and the session server's `update-revision` and `boundary-key`
when its answers reported them. The text versions and the states are two
different histories, linked by that `version`: a Run happens at a text
version, and every state derived from that Run carries it.

Queries make no state. Every other prompt line is a *prompt* of the state
it ran at (the newest 50 per state are kept), so the tree shows where
each question was asked.

Wire:
- every transcript entry carries `state: {id, pred}`, plus `exploring: true`
  when it was answered at an explored state;
- result-set views carry `state: {id, pred}` too: the state their query ran
  at (for `studio/relation-explorer`'s inline tables and pinned cells);
- `{t: "states", states, current, exploring}` is broadcast on every change,
  and the init snapshot has `states`;
- requests: `{t: "explore", id}` (`id: null` returns) and
  `{t: "branch-state", id}`.

## Going back: why re-derive

The daemon keeps every committed boundary of an evaluation
(`BoundarySnapshot`, `daemon/database.h:3297`; never pruned, docs/modules.md
§12), and Q1 can bind a query through an old boundary
(`query.cpp:1004-1029`; `tests/protocol-tests.sh` `nd-q1-old-boundary-old-name-binds`).
But that is *naming*, not *contents*: an update epoch (`add`, `del`,
`flush`) maintains the bound relations in place, and there is no MVCC
snapshot (docs/incremental.md:404-405). An old boundary resolves its old
version keys, and a key that was maintained since holds today's rows. And
`compiler/repl.rkt` always queries the current head
(`query-boundary-snapshot`, repl.rkt:1351). Binding the prompt to an old
boundary would therefore have been wrong exactly where it matters: after an
`add`/`del`. So nothing in the runtime changed.

What gets back to a state is replay: the state's Run, at the program
version it evaluated (written to a temporary directory from the version
store), then the lines of each change since, oldest first, each after the
`stage`/`unstage` lines it committed (a `flush` replays its staging). A branch replays
the state it branched from; a restart starts from nothing. Replays are
cheap for REPL-sized programs (about 1 s for the demo, mostly the `run`).

- **Explore tN** re-derives tN on a lane of its own (another session
  server, like the preview lane), then sends `mode readonly`. While it is
  explored, the prompt's lines go to that lane: queries answer at tN, and
  changes are refused by the server ("current database is read-only"). The
  session itself stays at its current state; "return to t7" stops that lane.
  A Run while exploring ends it.
- **Branch from tN** re-derives tN in a fresh session on the main lane
  (`discard session`, run, replay, `tables`) as a new state whose
  predecessor is tN. Further `add`/`del`/Run continue from there, and the
  tree has a branch.

Considered and not taken:
- *`save`/`open` a database per state*: a copy of the database per change.
- *`whatif`*: read-only by construction; it previews a cone and mutates
  nothing, so there is nothing to explore.
- *Q1 at an old boundary*: wrong contents after `add`/`del`, as above. It
  would be right for states that differ only by a Run or by renames, and
  could serve as a fast path once the daemon has versioned contents.

## What is not done

- A replay replays what made the state, not Studio's own work: a query's
  kept relation (`r1`, …) is not re-defined, so a later line naming one
  fails to replay. A Debug run's breaks and trace arming are not replayed.
- The live preview of a query being typed, and the REPL assistant, read the
  main session even while a past state is explored.
- The states are the studio process's: a restarted studio starts at t0. A
  server crash shows as a `restart` state at the next command.
- Explored answers show inline in the transcript; they open no result set
  (a set pages from the main lane).
