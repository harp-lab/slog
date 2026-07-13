# Persistent databases

A Slog run can save its relations in binary form and a later program can load
them. This supports a useful workflow:

1. run an expensive base analysis once;
2. save its result;
3. write small typed Slog programs as follow-up queries;
4. optionally save another layer derived from the first.

Database names refer to directories under `data/`. They are logical names,
not arbitrary filesystem paths on the command line.

## Exact saves

Write the complete final database:

```console
$ racket slog.rkt --no-banner --out-db callgraph analyze.slog
```

This creates `data/callgraph/`. Load it before another program:

```console
$ racket slog.rkt --no-banner -d callgraph --debug-dir out/query query.slog
```

An exact save contains the full materialized relations, interned strings and
structures, bignums, lists, maps, sets, and lattice state needed to reopen the
database. Daemon diagnostic `$stat_*` relations are excluded.

`--out-db` is the simplest choice when the result fits comfortably on disk and
fast predictable loading matters more than space.

## Query an existing database

The compiler discovers relation names and arities from the database, but your
query should redeclare every inherited relation it reads so the source has
real column types:

```slog
table (edge str str)
table (path str str)

table (in_cycle str)
rule (path X X) --> (in_cycle X)
```

Run it with:

```console
$ racket slog.rkt --no-banner -d callgraph --sizes \
    --debug-dir out/cycles cycles.slog
```

The declaration must match the stored arity. A lattice relation must also
match the stored lattice value specification. Struct declarations must match
their stored field arity. A mismatch is rejected rather than silently loading
rows under a different shape.

The query may add new relations and rules. Loaded facts enter the first
stratum as existing data and can drive recursion normally.

For repeated exploration, leave the base database unchanged and create a new
small `.slog` query for each question. This is Slog's practical ad hoc query
interface.

## Save a derived layer

An exact output loaded over an input is a fresh materialized copy:

```console
$ racket slog.rkt --no-banner -d callgraph \
    --out-db callgraph-with-cycles cycles.slog
```

A compressed output loaded over an input records a dependency on that input:

```console
$ racket slog.rkt --no-banner -d callgraph \
    --out-db-compressed callgraph-with-cycles cycles.slog
```

The second form makes a database DAG. Loading the child reconstitutes its
inputs in order and then its own layer.

## Compressed linked saves

Use:

```console
$ racket slog.rkt --no-banner --out-db-compressed analysis-small \
    analysis.slog
```

A from-scratch linked save normally produces:

```text
data/analysis-small.edb/   exact root containing input/ground facts
data/analysis-small/       derived layer, metadata, sources, and signature
```

The layer stores all or a deterministic sample of derived facts. It also
stores the source closure of the deriving program. On load, Slog:

1. opens the exact root and any ancestor inputs;
2. imports retained derived rows as seeds;
3. recompiles the stored program with the current compiler;
4. runs it to fixpoint to recover dropped rows;
5. compares the reconstructed derived content with the stored signature.

This is recompute-on-load compression. It trades disk space for compilation
and fixpoint work at load time.

The stored source closure makes replay independent of later edits or deletion
of the original `.slog` files. Source keys preserve their original paths for
include resolution and diagnostics.

### Retention fraction

Set the kept fraction with either a fraction or percent:

```console
$ racket slog.rkt --out-db-compressed small --per 0.25 analysis.slog
$ racket slog.rkt --out-db-compressed small --per 25 analysis.slog
```

Both retain 25 percent of sample-eligible derived rows. `--per 1` or
`--per 100` retains all of them. Sampling is deterministic for the stored
seed and row content.

If `--per` is omitted, the driver uses measured fixpoint time:

- a replay shorter than about 500 ms keeps roughly half;
- a more expensive replay keeps all derived rows.

This policy avoids saving a tiny disk layer that would make every later load
repeat an expensive analysis.

### Sampling bias and accelerator seeds

`--bias productivity` keeps a larger fraction from relations read by some
rule, up to twice the base retention rate. The default behavior is uniform
sampling.

Compressed saves can also carry small accelerator seed sidecars selected from
fixpoint history. They are performance hints used to reduce replay rounds, not
additional semantic inputs. The full stored signature still checks the result.

### Facts that are never sampled

Oracle answers, including SMT verdicts, models, cores, and malformed-formula
facts, are pinned and retained verbatim. Replay must not ask a different solver
and change an old database's meaning.

Other relation classes are partitioned from compiler manifests into exact
input facts and sample-eligible derived facts. Empty and metadata-only layer
directories are valid when all useful content lives in the root.

## Flattened saves

This command uses the compressed-save path but writes one self-contained exact
root:

```console
$ racket slog.rkt --out-db-compressed snapshot --flatten analysis.slog
```

The result has no linked EDB root, stored deriving program, or replay recipe.
Its managed metadata marks it as a flat database. Loading is an ordinary exact
open.

Flatten when you want to cut replay history, ship one materialized snapshot,
or remove a dependency on ancestor databases. `slog db freeze` performs the
same history-cutting operation on an existing chain.

## Database DAG and immutability

Managed database metadata records ordered input names and their content
stamps. These links form a DAG under `data/`.

A child depends on the exact stamped state of each parent. Slog therefore
refuses to overwrite or remove a referenced parent by default:

```text
base
└─ derived
   └─ report
```

Changing `base` behind those links would make both descendants stale. `--force`
allows an overwrite, but it deliberately marks that responsibility as yours;
dependent metadata will report a changed input.

Prefer a new database name for a new result. Treat a saved managed database as
immutable once descendants exist.

## Inspect databases

All database management commands begin with:

```console
$ racket slog.rkt db SUBCOMMAND
```

### List

```console
$ racket slog.rkt db ls
```

The table shows name, kind, retained percentage, relation-directory count,
disk size, and staleness. Databases written by plain `--out-db` have no managed
`META` and appear as kind `plain`. Managed kinds are `root`, `compressed`, and
`flat`.

### Dependency tree

```console
$ racket slog.rkt db tree
$ racket slog.rkt db tree analysis-small report
```

With no names, `tree` starts from databases that no other database references.
With names, it prints those roots and recursively shows their inputs.

### Verify metadata

```console
$ racket slog.rkt db verify
$ racket slog.rkt db verify analysis-small
```

The static check verifies readable managed metadata, present inputs, matching
stamps, and absence of dependency cycles. A plain database reports that it has
no managed metadata.

### Verify by full replay

```console
$ racket slog.rkt db verify analysis-small --replay
```

This is the strong check for a compressed layer. It skips the retained sample,
replays from exact inputs, and compares the complete result with the save-time
signature. That can find a row that a seeded monotone replay would preserve
even though the current compiler no longer derives it.

Replay verification can be expensive. It compiles and runs stored programs.
Model and unsat-core values are pinned solver choices, so verification uses
the recorded answers rather than expecting a new solver to make the same
choice.

## Remove and collect

Remove unreferenced databases:

```console
$ racket slog.rkt db rm old-result another-result
```

If a database has dependents, removal is refused. Remove it and every
transitive dependent with:

```console
$ racket slog.rkt db rm base --cascade
```

This is destructive. Check `db tree base` first.

Deleting a compressed layer can leave its automatically named `.edb` root
unreferenced. Collect such roots with:

```console
$ racket slog.rkt db gc
```

Remove every database directory under `data/` with:

```console
$ racket slog.rkt db clear
```

`clear` is intentionally broad and does not preserve selected names.

## Record edits

Database edits are append-only recipe operations. They do not rewrite binary
relation files immediately. A later load applies the edit at that layer's
boundary and replays dependent programs so the change propagates.

### Add a tuple

```console
$ racket slog.rkt db edit base add-tuple edge a b
$ racket slog.rkt db edit base add-tuple weight a b 17
```

Each value is parsed as a number when possible; otherwise it becomes a string
value through the action encoder. Quote shell arguments containing spaces.
The command does not read source declarations, so give exactly the stored
relation arity and compatible values.

### Delete a tuple

```console
$ racket slog.rkt db edit base del-tuple edge a b
```

A negative edit makes later program layers replay without their old retained
samples, preventing a sampled derived row from resurrecting a retracted input.

A stored program's own ground fact will be derived again when that program
replays. Deletion sticks for data-fed input; it is not a way to override a fact
that the stored source itself asserts.

### Rename or drop a relation

```console
$ racket slog.rkt db edit layer rename-rel old_name new_name
$ racket slog.rkt db edit layer drop-rel scratch
```

These are version-environment operations applied during load. A follow-up
program must use the resulting name and shape.

After a new edit, the original save-time signature no longer describes the
intentionally changed result. The first successful edited-chain load stores a
new signature baseline keyed by the full edit recipe; later loads resume drift
checking against it.

## Freeze a chain

Materialize a managed chain as a standalone flat database:

```console
$ racket slog.rkt db freeze report --as report-flat
```

Or replace it in place:

```console
$ racket slog.rkt db freeze report
```

An in-place freeze changes the database stamp and is refused while dependents
reference it. `--force` overrides that check and makes those dependents stale.
For a named copy that already exists, `--force` permits replacement.

Freeze loads and replays the complete chain, writes the materialized result,
and removes program, recipe, edit, signature, and delta history from the
target. The flat result cannot replay or propagate edits through the old
history because that history is gone.

## Drift and compiler changes

Compressed replay stores a signature of every complete derived relation before
sampling. On load, Slog compares current reconstructed content to that
signature.

- With the same compiler stamp, drift suggests nondeterminism, a compression
  bug, or changed external state that should have been pinned.
- With a newer compiler stamp, drift may be an intentional semantic change,
  but it is still reported.
- `--strict` turns the warning into a failing run.

Database values also have an encoding version. Slog refuses to open an
incompatible encoding rather than interpreting stored words with the wrong
layout. The binary format is an internal persistence format, not a stable
cross-version interchange standard. Use source facts, CSV for inspection, or
an explicit migration for long-lived external data.

## Merge behavior

The daemon can import more than one database in a live session. Imports merge:

- plain tables by set union;
- lattice tables by their per-key join;
- strings and structures by content interning;
- native lists and collections by canonical reconstruction.

The ordinary one-shot CLI exposes one `-d` input. Multi-input merges are
available through linked database manifests and the
[session API](api.md#link-and-import-data). The low-level action API also has
`import`, but it leaves schema and version management to the caller.
