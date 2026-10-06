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

## Views are bound to their state

Every view of rows was read at a state, and stays there
(`studio/state-scoped`):

- A result set records the state its query ran at. While the session is
  still at that state, and its database unchanged, the set pages from the
  main lane as before. Otherwise its rows, past what is cached, are read on
  a *past lane*: a session server holding that state, re-derived and
  read-only (`states.rs` `Pasts`; two lanes, the least recently used is
  re-derived for another state, so paging costs one replay, not one per
  page). A set's kept relation (`r1`) and any it names are defined there
  first, from the definition the set kept.
- A refinement of such a set runs at its state, as a new set of that
  state. Queries at an explored state open sets of that state too.
- "Show at t8" (`{t: "show-now", set}`) runs the set's query at the
  session's state, as a new set.
- The states (with their names) and the result sets are kept in the
  project's store (`states`, `results`), so they come back after a studio
  restart. The session does not, so a reopened studio starts at a new
  `studio restarted` state; every older set is then read at its own state.
- A state can be named (`{t: "name-state", id, name}`): double-click any
  stamp.

In the page, `web/stamp.js` renders a name with its state as a superscript
(`r2`ᵗ¹, or `r2`^baseline), tinted when the state is past, and gives every
stamp a hover card (what made the state, its time, strata and size changes,
where it came from, what was asked there, its sets) and the rename. It
stamps result-set tabs, transcript set links and rows/relations titles,
queries that name a set, the Execution view's relations, and completion
details (as text, `at t1`).

## What is not done

- A replay replays what made the state, not Studio's own work: a later
  change line naming a kept relation (`r1`) fails to replay (reads define
  what they name; replays do not). A Debug run's breaks and trace arming
  are not replayed.
- A kept relation is a rule: `?(r1 …)` at t8 is r1's query at t8, not
  r1's rows at t1. Its superscript names where the set was read.
- The live preview of a query being typed, and the REPL assistant, read the
  main session even while a past state is explored.
- A server crash shows as a `restart` state at the next command.
- Sorted sets are not kept across a restart (their order is Studio's own).
- Past lanes are extra session servers; server mode's lane limit does not
  count them.
