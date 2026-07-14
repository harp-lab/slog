# REPL names, boundaries, and historical values

2026-07-13. **Design proposal; no REPL exists yet.** The REPL should present
the compiler/session's database model, not daemon implementation strings.

## 1. Two kinds of reference

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

The REPL should always be able to show or copy the underlying opaque key. A
friendly `Y.Const@analysis0` rendering is useful, but it is presentation, not
durable identity. Pipeline ordinals and names may change when a program is
prepended or a namespace is renamed; the key does not.

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

The first interface should support four queries even if their final command
spelling changes:

1. inspect a QName at a boundary;
2. inspect an absolute VersionKey;
3. show the predecessor/name history of a version; and
4. show the catalog and namespace-binding delta between two boundaries.

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
Bookmarks and scripts store a VersionKey, optionally plus the last friendly
QName.

## 5. Printing nominal values

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
   `<type t4>` rather than borrowing the type's latest name.

This handles rename aliases, dropped constructors, and historical versions
without lying. The same value can appropriately print as `X.Const(...)` at
`db3`, `Y.Const(...)` at `db8`, and `<type t4>(...)` at a boundary where the
type has no public binding.

The current daemon's `structs_by_id` cache follows the latest `Relation*` and
can discover uncached SIDs only by scanning current names. Modules must replace
that with a descriptor that survives rename/drop before historical value
inspection is reliable.

## 6. Compiler/session/daemon interface

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
- recipe persistence.

The daemon provides:

- `(EvaluationId, VersionKey) -> VersionId/Relation*` resolution;
- SID/TypeKey descriptors and value decoding;
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

## 7. First implementation slice

After the module/catalog substrate exists:

1. add a `repl` mode to `slog.rkt` that owns one session and labels every
   committed BoundaryKey;
2. implement completion and lookup over the session catalog;
3. add daemon lookup by VersionKey and TypeKey/SID registry inspection;
4. show history and bindings with both friendly names and stable keys;
5. make save/reload preserve those keys while allowing runtime VersionIds and
   SIDs to change; and
6. retain every referenced boundary conservatively until explicit session
   close. Branching, history GC, and SID compaction remain later features.

This gives a simple user rule: use `dbN.path.to.rel` while exploring; ask for
or store the VersionKey when a reference must survive changes to names or
pipeline layout.
