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
(session-edit-batch! s sign relation tuple #:at [anchor 'tip])
```

The two names are aliases. `session-edit-batch!` emphasizes that this edits
the overlay of the selected existing VersionInstance; it does not allocate a
new relation version.

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

- A positive edit whose entire cone is made of capability-certified,
  positive-arity plain tables lazily establishes support counts and enters
  the `_maint1` path. Presence transitions chain through recursive SCCs and
  multiple downstream strata; support contributions are retained even for
  heads that were already present.
- An unsupported single-stratum positive update may use the legacy set-only
  delta plugin. Other monotone cones re-enter their strata in order.
- A direct or inherited deletion whose entire cone is counted, acyclic, and
  made of positive-arity plain tables enters the `_maint3neg` path. It
  propagates only true-to-false presence changes. A mixed flush runs this
  negative phase before its `_maint1` positive phase and commits once.
- A tip-local deletion whose counted plain-table cone contains recursive
  SCCs enters the `_maint4neg` sweep (docs/m4t-contract.md): candidates are
  over-deleted on foundation loss, reseeded when recursive support through
  live premises survives the negative fixpoint, and relearned by the
  positive phase otherwise. Edits that target a recursive head relation
  itself, and cones with version inheritance, are not admitted.
- An acyclic positive plain-table producer may write a root lattice. The M6L
  route retains losing `(key, payload)` contributors, repairs the visible
  joined value after signed edits, and propagates its coalesced old/final pair
  through acyclic positive plain-table consumers. Direct lattice edits,
  recursive consumers, negation, and downstream lattice writers are not
  admitted.
- A deletion through recursion, negation, structs, nullary relations,
  unsupported lattice topology, or other unsupported topology clears
  affected derived relations and reruns the cone.
- A back-anchored update walks versioned suffixes at their recorded positions.

Every nonempty flush is serialized as one optimistic update epoch. The daemon
refuses a stale expected revision before applying any mutation and advances
the revision when the set result settles. If count establishment or support
arithmetic cannot be certified, the permanent set-semantics fallback remains
available; count caches never override relation content.

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
(pipeline
  (pos 2)
  (evaluation "eval-...")
  (update-epoch 3)
  (strata (s 0 1 "..." (kind semantic)
             (reads (edge 12)) (write-map (path 18)) (writes 18)))
  (version-ids
    (vid edge 0 12 0 "v1:..." (schema 2 0 set))
    (vid path 1 18 4 "v1:..." (schema 2 0 set)))
  (rel edge (v 0 1 3))
  (rel path (v 0 1 6) (v 1 4 10)))
```

The current protocol also includes an evaluation ID, global update epoch,
exact stratum read/write VersionId maps, persistent VersionKeys, predecessor
VersionIds, and schemas. Each `(rel NAME (v ORD POS SIZE) ...)` group describes
one name's physical versions. A severed binding from a drop or rename is
marked in the full protocol. Recipe serialization resolves raw anchors to
persistent VersionKeys (while retaining legacy ordinal compatibility),
because compiler changes may shift absolute pipeline positions.

An anchor before a relation's first binding is an error. An update aimed at a
name that has been dropped or renamed away at that position is also refused.

### Edit versus inject

Editing and injecting are deliberately distinct JIT operations:

```racket
;; Existing slot: VersionId and VersionKey stay fixed; flush advances only the
;; settled update revision.
(session-edit-batch! s '+ 'edge '(4 5))
(session-flush! s)

;; New input-only successor: returns position, runtime VersionId, VersionKey.
(define-values (pos vid key)
  (session-inject-version! s 'edge #:key "editor-edge-2"))
```

Plain injection inherits the current tip into a distinct input-only successor.
It never retargets historical program writers, so queued edits on that slot
settle as anchored input changes until an explicit program event reopens the
pipeline. `session-inject-batch!` is a convenience that injects and applies an
input batch but retains those input-only semantics.

Use the explicit topology helper when the new input version should feed a new
program segment:

```racket
(session-inject-and-reopen!
 s 'edge "graph-rules.slog" '((4 5)) '()
 #:key "editor-edge-3"
 #:output-policy 'inherit)
```

The helper first settles the input-only successor and its additions/deletions,
then runs a new semantic program event. New output slots have stable
VersionKeys, explicit semantic writer maps, and the shipped `'inherit` policy.
A later positive edit can use `_maint1` through this version edge. Fresh,
history-free output policy is intentionally not inferred and is not yet
accepted by the helper.

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
positive support maintenance is available on the certified M1 surface, and
precise deletion is available on M3's counted acyclic plain-table surface,
M4T's recursive plain-table surface for tip-local edits, and
M6L's acyclic root lattice plus stratified plain-table-consumer surface.
Recursive or negated lattice cones, downstream lattice writers, structs,
nullary relations, edits targeting recursive heads, historical edits, and
other unsupported deletion cones
still use clear-and-rerun as their correctness path.

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
VersionKey. Legacy ordinal recipes remain readable for compatibility.

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
- `#:rel`: request relation-scoped establishment; the current
  correctness-first implementation closes the containing pipeline prefix.
- `#:at`: count the environment at a pipeline position.
- `#:force? #t`: build and atomically replace even an already-closed count
  epoch.

Positive `_maint1`, acyclic negative `_maint3neg`, and recursive negative
`_maint4neg` flushes invoke this
establishment lazily. Committed count state is stamped with the settled update
revision. Overflow, underflow, or coverage failure invalidates the cache while
preserving the authoritative set result; a later recount can rebuild it.
Retractions outside the certified plain-table surfaces still route to
clear-and-rerun.

Low-level `dump-counts`, `count-state`, and related actions expose the result
for tests. M6L lattice maintenance uses the same packed support word for
full `(key..., payload)` contributors, but reports certification separately as
`(lattice-contributor-state (lcnt NAME ORD 0|1) ...)`; legacy `count-state`
remains table/struct-only. Client applications should not yet treat either
sidecar layout as a stable public data model.

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
