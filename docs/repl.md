# REPL names, boundaries, and historical values

2026-07-13. **Design proposal; no REPL exists yet.** The REPL should present
the compiler/session's database model, not daemon implementation strings.

*2026-07-14: [execution-tiers.md](execution-tiers.md) adopts §6 verbatim as
"level-0 observation watches" and layers a pre-commit provenance gate above
it; it also adds the ad-hoc read-only query design (interpreted QueryPlans,
not compiled action plugins) that this document's REPL will drive. The
names/handles/printing/catalog sections here remain the authority.*

## 1. Names and four short handle classes

A completed root or pipeline event receives a session-local handle such as
`db0`, `db1`, and so on. The handle names
`(EvaluationId, BoundaryKey)`; the stable logical boundary has the state:

```text
Catalog.decls   QName -> DeclarationDescriptor
Catalog.members set (member-QName, union-or-enum-QName)
Catalog.nominal struct-QName -> TypeKey
Environment     QName -> VersionKey
```

Thus `db7.model.edge` means “resolve `model.edge` in the environment at
boundary `db7`.” Namespace paths may nest arbitrarily. `db7` is not part of
the compiled QName, and the handle need not copy any tuples.

This is the friendly, point-relative reference. The stable logical-slot
reference is a `VersionKey`. Within one session it is unambiguous; across
descendant recipe evaluations, materialized contents are identified by
`(EvaluationId, VersionKey)`. The same QName can resolve to successive
versions, and a rename can give one version different names at different
boundaries:

```text
db3.X.Const -> v17
db8.Y.Const -> v17       ; namespace rename, no data movement
db9.Y.Const -> v18       ; a later writer created a successor
```

Users should not have to type serialized persistent keys. The REPL assigns
short, typed aliases:

| spelling | denotes | backing identity |
|---|---|---|
| `db7` | committed database boundary | `(EvaluationId, BoundaryKey)` |
| `@v12` | logical relation version | `VersionKey` in the selected evaluation |
| `@t4` | nominal struct type | `TypeKey` in the selected evaluation |
| `#328` | one concrete runtime value | checked entry in the REPL value-handle table |

`inspect db7.X.Const` can therefore report `@v12` and `@t4`; `history @v12`
does not require the user to paste a long `(LayerId,event,slot)` value. A
command such as `key @v12` exposes the persistent serialized key for a recipe,
script, or debugger bookmark. Short aliases are session conveniences and are
never stored as durable identity.

A friendly `Y.Const@analysis0` rendering can still be useful prose, but it is
not another reference syntax. Pipeline ordinals and names may change when a
program is prepended or a namespace is renamed; the backing keys do not.

## 2. Handles and running programs

An unnamed `run` uses the selected handle's current home as both input and
output and returns a new handle. `run ... as p` uses child home `p`; `with`
bindings connect formal namespaces to compatible actual namespaces in the
selected catalog.

```text
db1 = run "frontend.slog" at db0 with output = syn
db2 = run "analyze.slog" as a0 at db1
      with syntax = syn, output = model
```

The home alias `a0` names data, not a unique execution. Two temporal runs may
intentionally advance `a0.*`; their `ProgramInstanceKey`s, BoundaryKeys, and
result handles distinguish them.

A binding is shown as program-instance metadata:

```text
a0.syntax -> syn
```

It does not create a second public `a0.syntax.*` alias in the database.
Completion at `db2` shows the actual `syn.*` paths and the unbound/private
members under `a0.*`.

The first REPL can remain linear: a run appends after the selected tip.
Branching an old handle into several simultaneously live descendants requires
an explicit recipe-branch feature and separate daemon evaluations; it should
not happen accidentally because the user retained `db1`.

A running or paused program has a provisional boundary, not a `dbN` database
handle. The UI may show `run0` with progress and permit resume/cancel, but
completion, ordinary latest lookup, and later `run` commands continue to see
the last committed handle. Fixpoint commits the prepared boundary; cancellation
aborts it. This prevents half-added schemas or half-written successor versions
from becoming interactive state.

## 3. Completion and additive schemas

Completion comes from the boundary catalog, not from nonempty daemon
relations. It therefore includes empty members and compiler-known types:

```text
db2.model.<tab>
  edge
  entry
  node
  value
```

Running a program whose bound formal schema adds compatible missing members
creates them atomically and returns a boundary whose completion includes
them. Old handles retain the earlier catalog:

```text
db2.X.<tab>  -> a, b
db3.X.<tab>  -> a, b, c, d, e
```

Omission in a later source file is not deletion. An explicit drop removes a
name from the next boundary while old handles continue resolving it.

## 4. Looking up history

The first interface should support these direct queries:

```text
inspect db7.X.edge
inspect @v12
history @v12
diff db6 db7
key @v12
key @t4
```

An inspection result should include:

```text
visible QName(s)
BoundaryKey and VersionKey
predecessor VersionKey
declaration descriptor
creating ProgramInstanceKey and source location
runtime VersionId and pipeline position, when materialized
tuple count and indexes
TypeKey and SID, for a struct relation
```

Numeric pipeline position remains useful for ordering and performance
diagnostics, but the REPL never serializes it as the identity of a bookmark.
Bookmarks and scripts store the key behind `@v12`, optionally plus the last
friendly QName.

## 5. Printing values with expandable `#N` leaves

The daemon can decode a struct word only by its evaluation-local SID. The
target registry is:

```text
SID -> TypeDescriptor(TypeKey, arity, canonical lookup)
```

The REPL then chooses a name using the selected boundary catalog:

1. decode SID to TypeKey;
2. find QNames at that boundary whose declaration has that TypeKey;
3. prefer the QName through which the inspected relation/value was reached;
4. otherwise print the unique visible name; and
5. if none is visible, print an explicit historical form such as
   `<type @t4>` rather than borrowing the type's latest name.

This handles rename aliases, dropped constructors, and historical versions
without lying. The same value can appropriately print as `X.Const(...)` at
`db3`, `Y.Const(...)` at `db8`, and `<type @t4>(...)` at a boundary where the
type has no public binding.

Large values should print under independent depth, node-count, collection-item,
and string-length budgets. Whenever expansion stops, the printer allocates a
value handle and leaves it in the output:

```text
(syn.App
  (syn.Ref "map")
  [(syn.Ref "f") #328:(syn.App ...) #329:(syn.Lambda ...) ...])
```

Every composite value may receive a handle internally, but only repeated or
truncated values need display it. The default heuristic should fully expand
small values, stop at a modest depth, cap wide collections and long strings,
and obey one total-node budget so a shallow-but-enormous DAG cannot flood the
terminal. A bare handle is shorthand for printing it again, and `show`
controls the same small set of budgets:

```text
#328
show #328 depth 8
show #328 nodes 500 items 100
show #328 at db8
show #328 raw
```

`at db8` changes boundary-relative constructor spelling, not the value.
`raw` exposes the encoded tag/SID/intern ID for daemon debugging. Ordinary
printing never mistakes those runtime numbers for stable keys.

A `#N` is deliberately not the struct word's 38-bit intern ID. It indexes a
REPL-owned entry containing at least the EvaluationId, raw value word, selected
boundary/naming context, and value kind. The same mechanism can retain a
struct, sequence, collection, large string, or other interned value. This lets
the REPL generation-check handles, pin any required daemon storage, and reject
a stale handle after evaluation close/reload instead of accidentally showing a
new value that reused the same numeric SID or intern slot.

Struct and canonical collection values are DAGs, so the printer should also
recognize repeated nodes and reuse one `#N` rather than expand shared subtrees
again. Relation lookup uses the same printer, making large rows browsable
without a second value-inspection facility.

The current daemon's `structs_by_id` cache follows the latest `Relation*` and
can discover uncached SIDs only by scanning current names. Modules must replace
that with a descriptor that survives rename/drop before historical value
inspection is reliable.

## 6. A small daemon debugging protocol

Watches and breakpoints should be capabilities of the REPL/socket API, not
facts or rules inserted into the Slog program. They deliberately observe the
evaluation from outside its dependency graph—the relational equivalent of a
debugger or `printf`, without changing the program being debugged.

The first daemon protocol only needs four concepts:

```text
subscribe event-kind*
watch WatchSpec
unwatch WatchId
continue | abort
```

Useful initial event kinds are:

- program boundary prepared or ready to commit;
- stratum started or reached fixpoint;
- iteration completed;
- evaluation paused for a watch, user request, or resource limit.

The first `WatchSpec`s should remain intentionally small:

- report a relation's size and per-iteration added/removed counts;
- report when one exact tuple appears or disappears; and
- observe selected iteration, stratum, or program events.

Every hit has the same daemon meaning: stop at the coherent barrier and return
an ordinary pause reply with extra watch information, for example:

```text
(paused
  (reason watch)
  (run run0)
  (at iteration 6)
  (hits
    (watch w2 (size model.value 1083921) (added 83921) (removed 0))
    (watch w5 (appeared model.error (...)))))
```

All watches hit at one barrier are aggregated into one pause. Each watch is
edge/event-triggered and records that it has handled this barrier, so
`continue` cannot immediately return the identical pause again.

“Notification” versus “breakpoint” is entirely client policy. For a notifying
watch, the REPL prints or records the hit and immediately sends `continue`.
For a breaking watch, it returns control to the user while leaving `run0`
paused. The daemon needs no second event-delivery mechanism and no knowledge
of interactive policy.

The daemon always receives an exact VersionKey/VersionId. `db7.model.value` or
`@v12` therefore watches one historical slot. For the common “watch
`model.value` through the next run” workflow, the REPL retains a follow-QName
intent and resolves it to the successor VersionKey when the session prepares
that boundary. The daemon never performs basename search or silently follows
latest names. The client retains the QName, boundary, and printer context;
event replies carry stable keys and runtime IDs, and tuple payloads render
with ordinary `#N` value handles.

Watch evaluation occurs at coherent barriers, initially iteration and
stratum/program completion. It must not add a callback to every parallel tuple
insertion or expose an index while workers are mutating it. An exact-tuple
watch can probe the finalized added/removed delta at the barrier; relation
growth is already known there. A watch at the terminal program barrier pauses
before publishing the completed boundary; `continue` performs the normal
commit. Thus a breaking watch leaves the program's prepared boundary paused as
`runN`, not committed as `dbN`, until the client continues or aborts it.

Watches belong to the live debugging session. They are not part of the
program's type environment, compile hash, database catalog, or replay recipe,
and they cannot write into the active evaluation. A later design may add
pattern watches, targeted provenance, user observer code, asynchronous event
streams, or persistent debugger configurations, but none is required to make
relation/tuple watches and safe breakpoints useful.

Implementation can reuse the existing action/session seams. Watch/unwatch
actions register daemon-side specs; the database checks them where iteration
deltas and fixpoint state are already finalized; and the existing paused reply
gains a structured watch-reason payload. The session's normal
continue-until-paused/fixpoint loop either auto-continues or yields according to
its local WatchId policy. This requires no unsolicited socket messages and no
new compiler IR.

## 7. Compiler/session/daemon interface

The compiler provides:

- structured QNames and declaration descriptors;
- module occurrence trees and `ModuleInstanceKey`s;
- qualified rule/source provenance; and
- formal-to-actual binding maps.

The session driver in `compiler/session.rkt` and `slog.rkt` provides:

- stable BoundaryKeys and `dbN` labels;
- boundary catalog/environment deltas;
- ProgramInstanceKey, VersionKey, and TypeKey descriptors;
- name/history resolution and completion; and
- short `dbN`, `@vN`, and `@tN` alias tables plus the checked `#N` value table;
- watch registration, WatchId ownership, and event rendering;
- recipe persistence.

The daemon provides:

- `(EvaluationId, VersionKey) -> VersionId/Relation*` resolution;
- SID/TypeKey descriptors and value decoding;
- safe-point watch evaluation and watch-reason pause/resume;
- materialized version/index statistics; and
- execution-local pipeline ordering.

The wire protocol should return structured records or encoded QName component
lists. The REPL must not split mangled strings, search the latest relation map
to reconstruct history, or treat a SID as durable.

The existing `(pipeline)` response is a useful starting point, but its
name/ordinal chains should gain BoundaryKeys and direct VersionKey lookup.
The existing `(schema)` action describes nonempty materialization and is not a
catalog API. Add explicit catalog/type-registry introspection rather than
changing the REPL to guess what empty declarations once existed.

## 8. First implementation slice

After the module/catalog substrate exists:

1. add a `repl` mode to `slog.rkt` that owns one session and labels every
   committed BoundaryKey;
2. implement completion and lookup over the session catalog;
3. add daemon lookup by VersionKey and TypeKey/SID registry inspection;
4. show history and bindings with both friendly names and stable keys;
5. add budgeted value printing and generation-checked `#N` expansion handles;
6. add iteration/stratum/boundary events, exact relation/tuple watches, and
   barrier-safe breakpoints to the socket API;
7. make save/reload preserve persistent keys while allowing short handles,
   runtime VersionIds, and SIDs to change; and
8. retain every referenced boundary and value conservatively until its handle
   is released or the session closes. Branching and history GC remain later
   features.

This gives a simple user rule: use `dbN.path.to.rel` for database state,
`@vN`/`@tN` for history and types, and `#N` to keep drilling into values. Use
`key` only when a reference must leave the current REPL session.
