# Racket APIs

Slog's command line starts a fresh daemon for one load/compile/run/save cycle.
The Racket session API keeps one daemon alive while a client runs program
segments, applies input changes, propagates them, reads versions, and saves a
replayable session layer.

This API is useful for an editor, analysis server, test harness, or data
pipeline written in Racket. It is still close to the compiler and daemon. It
does not yet have the compatibility guarantees of a small installed client
library.

The relevant modules are:

```racket
(require "compiler/session.rkt")
(require "compiler/actions.rkt") ; only for low-level action work
```

Paths in these examples assume the Racket client file is in the repository
root and is run from there.

## A complete small session

Suppose `graph.slog` declares `edge` and its transitive `path`. This client
runs it, inserts one edge, propagates the addition, probes the result, and
saves the live state:

```racket
#lang racket

(require "compiler/session.rkt")

(define s (make-session #:echo displayln))

(dynamic-wind
  void
  (lambda ()
    (session-run! s "graph.slog")

    ;; Queue a signed input tuple and propagate it.
    (session-batch! s '+ 'edge '(4 5))
    (session-flush! s)

    ;; `lookup` emits exactly one response line.
    (session-action!
     s
     '(lookup path 1 5)
     (lambda (out)
       (displayln (read-line out))))

    (session-save! s "graph-live"))
  (lambda ()
    (session-close! s)))
```

The lookup response is `(found path 1)` when any stored row begins with the
given values. The saved layer appears under `data/graph-live/` and contains a
materialization plus the session recipe and captured source.

Always close a session. `dynamic-wind` makes cleanup happen when compilation,
the daemon, or client code raises an exception.

## Creating and closing sessions

```racket
(make-session #:echo [echo displayln])
```

This ensures the daemon is built, starts it with normal thread/memory
configuration, drains its stderr on a helper thread, and returns a session.
`echo` receives driver status lines. Pass `void` for a quiet client or a logger
function to collect them.

```racket
(session-close! session) ; -> subprocess exit status, normally 0
```

Closing ends daemon input, drains remaining output, joins the stderr thread,
and waits for a subprocess owned by the session.

`make-session-over` wraps existing daemon ports:

```racket
(make-session-over input-port output-port #:echo [echo displayln])
```

The one-shot load driver uses this internally when a database chain contains a
saved session recipe. The facade does not own or close the underlying daemon
process. Most clients should use `make-session`.

## Open a database

```racket
(session-open! s "database-name")
```

The method validates the stored value-encoding version and executes the full
load plan. Plain databases open directly. Compressed program layers replay
stored programs. Session layers replay their recorded runs, batches, imports,
links, renames, and drops through the same live API.

Open a base before running new program segments:

```racket
(define s (make-session))
(session-open! s "base-analysis")
(session-run! s "query.slog")
```

The session remembers the base for compilation manifests and for the saved
recipe's database dependency.

## Run program segments

```racket
(session-run! s "segment.slog")
```

The segment compiles against the live daemon schema, including prior segments,
imports, renames, and drops. Each program in its `run` tree creates a version
boundary for relations it writes. The session then drives every stratum to a
fixpoint and records enough manifest data to find affected downstream cones
later.

If a second segment writes `path`, the old physical `path` version remains
addressable by pipeline position while the current name points to a copied new
version. This is how back-anchored updates and saved recipes retain their
meaning across a sequence of program changes.

Source text is captured during live runs. `session-save!` stores that closure
so later replay does not depend on the current filesystem contents.

## Queue and flush changes

```racket
(session-batch! s sign relation tuple #:at [anchor 'tip])
```

- `sign` is `'+` or `'-`.
- `relation` is normally a symbol.
- `tuple` is a Racket list of storage-order values.
- `anchor` is `'tip` or a numeric pipeline position.

Supported tuple literals in inline actions are Racket strings, symbols,
integers including bignums, and real numbers. Symbols encode as Slog strings.
Structured Slog values are not accepted by this literal encoder; use a binary
delta database or derive them in a Slog segment.

The pending log collapses duplicate work:

- the same sign and tuple is idempotent;
- an add and delete of the same tuple at the same anchor cancel before flush.

Apply and propagate all queued groups with:

```racket
(session-flush! s)
```

Flush chooses a route from compiler manifests:

- A small all-add update with a single monotone downstream stratum can enter
  through a generated delta plugin.
- A larger monotone cone re-enters its strata in order.
- A deletion, negation dependency, lattice-sensitive edge, or other
  non-monotone case clears affected derived relations and reruns the cone.
- A back-anchored update walks versioned suffixes at their recorded positions.

The goal is result equivalence with rerunning the affected program history,
not mutation of arbitrary derived rows in place.

Each anchor/relation group is limited by `inline-batch-max`, normally 2048:

```racket
inline-batch-max
```

Set `SLOG_INLINE_MAX` before loading the module to change it. For a bigger
payload, write a small binary database and use `session-import-delta!`.

## Immediate tuple actions

```racket
(session-add-tuple! s 'edge '(4 5))
(session-del-tuple! s 'edge '(2 3))
```

These apply immediately to the current relation version and record the change
in the session log. They do not choose and execute downstream propagation by
themselves. Use them with an explicit `session-reenter!` or `session-rerun!`
when writing a low-level tool.

For normal clients, `session-batch!` followed by `session-flush!` is safer
because it chooses the route from dependency metadata.

## Anchors and versions

`'tip` means the latest version of a relation. A numeric anchor means the
version current at or before that pipeline position.

Inspect version chains with the low-level pipeline action, which emits one
line:

```racket
(session-action!
 s
 '(pipeline)
 (lambda (out) (displayln (read-line out))))
```

A response has this general form:

```text
(pipeline (pos 2)
  (rel edge (v 0 0 3) (v 1 1 4))
  (rel path (v 0 0 6) (v 1 1 10)))
```

Each `(v ORD POS SIZE)` is one physical version. A severed binding from a drop
or rename is marked in the full protocol. Recipe serialization converts raw
anchors to stable per-relation version ordinals, because compiler changes may
shift absolute pipeline positions.

An anchor before a relation's first binding is an error. An update aimed at a
name that has been dropped or renamed away at that position is also refused.

## Link and import data

Import a binary mini-database by filesystem path:

```racket
(session-import-delta! s "out/delta-db")
(session-import-delta! s "out/delta-db" '((old-edge edge)))
(session-import-delta! s "out/delta-db" '() #:at 3)
```

The optional rename list contains `(source destination)` pairs. The import
lands in the target relation versions and propagates through the affected
cones. A saved session externalizes payload directories into its own layer so
the recipe remains replayable.

Hot-link a managed database by logical name:

```racket
(session-link! s "facts")
(session-link! s "facts" '((input source)))
```

A link records a database DAG edge instead of copying the payload into the
session layer. The target's relation directories must contain its full
materialization. A chained/compressed target is therefore refused; freeze it
to a flat database first or open it as the session's base.

## Rename and drop

```racket
(session-rename! s 'old-name 'new-name)
(session-drop! s 'temporary)
```

These change the versioned name environment without moving row data. Rename
records the position so affected-cone walks can translate names across the
boundary. A later segment compiles against the live schema and will fail if it
still expects a dropped name.

## Direct re-entry tools

```racket
(session-reenter! s 'edge)
```

This replays the downstream cone without clearing it. It refuses a cone with a
negation or lattice/non-monotone dependency.

```racket
(session-rerun! s 'edge)
```

This clears relations exclusively written by the cone, then reruns its strata.
It handles deletion and non-monotone dependencies, subject to version rebound
guards.

These methods exist mainly for tests and specialized tools. `session-flush!`
is the policy entry point.

A deleted row that a rerun can independently derive will reappear. Precise
support counting and deletion without recomputation is not the current session
model; clear-and-rerun is the correctness path.

## Save and inspect a recipe

```racket
(session-log s)
```

This returns the session's own collapsed applied batches, sorted by version
position and relation. Replayed ancestor batches are not duplicated.

```racket
(session-recipe s)
```

This returns an s-expression beginning with `slog-recipe`. It contains ordered
open/run/import/link/rename/drop steps plus signed batches anchored by stable
version ordinal.

Save a managed layer:

```racket
(session-save! s "name")
```

The method first flushes pending batches, then writes:

- the full current materialization;
- the session recipe;
- large externalized delta payloads;
- captured program sources;
- signatures for relations touched by this session;
- managed metadata linking the base and hot-link dependencies.

Session saves currently keep 100 percent of their materialized rows. On load,
the recipe is the semantic history and the materialization/signature is a
witness and fast state. Overwriting a database that has dependents is refused.

## Count sidecars

The session runtime can build per-version derivation count sidecars:

```racket
(session-recount! s)
(session-recount! s #:rel 'path)
(session-recount! s #:at 3)
(session-recount! s #:force? #t)
```

This is incremental-engine infrastructure, not the language's `(count)`
lattice. It runs count-flavored rule plugins over settled content without
changing relation rows.

- No keyword: count the whole current pipeline.
- `#:rel`: count the target's relevant writer/downstream cone.
- `#:at`: count the environment at a pipeline position.
- `#:force? #t`: clear existing count state before rebuilding.

Low-level `dump-counts`, `count-state`, and related actions expose the result
for tests. Client applications should not yet treat the sidecar layout as a
stable public data model.

## Low-level actions

`compiler/actions.rkt` exports:

```racket
(action-so spec) ; -> path to a cached compiled plugin
```

The daemon protocol is one shared-object path per input line. Loading the
plugin calls its `slog_plugin(Daemon*)` entry point. Values in an action spec
are baked into generated C++, so a new literal query can require a new small
compile. Repeated identical actions reuse a content-addressed plugin.

Within a session:

```racket
(session-action! s spec [reader])
```

The optional reader receives the daemon output port and must consume exactly
the response lines produced by that action. Silent actions need no reader.
Reading too few lines misaligns every later response; reading too many blocks
or consumes another action's result.

Useful read-only actions include:

| Spec | Response |
|---|---|
| `(lookup REL value ...)` | one `(found REL 0|1)` line; values form a row prefix |
| `(lookup-at REL POS value ...)` | one `(found-at REL POS 0|1)` line |
| `(pipeline)` | one version-chain line |
| `(sizes-at POS)` | one line of versioned sizes |
| `(dump-rel REL)` | zero or more `dumprow` lines, then `dumpdone` |
| `(dump-rel REL POS)` | versioned dump with the same sentinel |
| `(schema)` | `schema-rel` lines, then `schema-end` |
| `(signature REL ...)` | `sig` lines, then `sig-end` |
| `(sizes)` | one line per indexed relation, with no sentinel |

Useful state-changing actions include `open`, `import`, `write-db`,
`write-csv`, `write-rel`, `write-rel-csv`, `load-rel`, `refresh-rel`,
`add-tuple`, `del-tuple`, and `continue`. Session methods should be preferred
when they exist because they also maintain manifests, version chains, cone
routing, logs, and recipes.

Several more action forms are internal pieces of session replay, compression,
pausing, and counting. They are matched in `compiler/actions.rkt`, but sending
one directly can leave the driver's model out of sync with the daemon.

## Raw daemon clients

The test helper `tests/api/send-actions.rkt` shows the minimal standalone
pattern:

1. call `ensure-slogd-exists`;
2. start `daemon/slogd` using `slogd-argv`;
3. compile action specs with `action-so`;
4. write each plugin path and a newline to daemon stdin;
5. read s-expression responses from stdout;
6. drain stderr concurrently;
7. close stdin and wait for the subprocess.

The protocol is intentionally tiny but not self-describing. A production
client should build a response grammar around each action and preserve strict
request/response ordering. Use the session API unless the raw protocol itself
is what you are testing.
