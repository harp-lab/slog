# 4. Files, databases, and follow-up queries

This chapter turns the small examples into a practical workflow: split a
program into files, save its results, check them, and run a new query without
changing the original analysis.

## Share declarations with `include`

Suppose `graph-types.slog` contains:

```slog
table (edge str str)
table (path str str)
```

Another file can include it:

```slog
include "graph-types.slog"

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
```

An include is textual in spirit: it adds declarations and rules to the same
program. Relative paths are resolved from the file containing the include.
If that path does not exist, Slog also looks in the repository's `lib/`
directory. Put leading `include` forms before declarations and rules.

## Run one program before another

`run` creates a pipeline boundary. The named program reaches its fixpoint
first, and the current program sees its relations:

```slog
run "build-paths.slog"

table (cycle str)
rule (path X X) --> (cycle X)
```

Use `include` for pieces of one program. Use `run` when the second part should
read a settled result from the first part, especially for negation or an
operation that needs a closed lattice value.

## Save a database

Run an analysis and save all of its relations under `data/graph-db/`:

```console
$ racket compiler/run.rkt --no-banner --out-db graph-db --sizes build-paths.slog
```

The database is binary, not CSV. Load it into a later run with `-d`:

```console
$ racket compiler/run.rkt --no-banner -d graph-db --debug-dir out/cycles find-cycles.slog
```

The later program must declare the inherited relations it reads. This keeps
type checking explicit. It can add new declarations and rules normally.

Saved databases are useful for expensive base analyses. Compute once, then
try many small queries against the same result.

## Write a follow-up query

Assume `graph-db` contains `edge` and `path`. Save this as `query.slog`:

```slog
table (edge str str)
table (path str str)

table (mutually_reachable str str)
table (sink str)
table (node str)
table (has_outgoing str)

rule (edge X Y) --> (node X) (node Y) (has_outgoing X)
rule (path X Y) (path Y X) (/= X Y) --> (mutually_reachable X Y)
rule (node X) ~(has_outgoing X) --> (sink X)
```

Run it over the saved facts:

```console
$ racket compiler/run.rkt --no-banner -d graph-db --sizes --debug-dir out/query query.slog
$ sort out/query/mutually_reachable.csv
$ sort out/query/sink.csv
```

This is the closest everyday equivalent to an ad hoc database query: a small,
typed Slog program loaded over an existing result. It can use recursion,
structured patterns, demands, lattices, and SMT checks, not just select rows.

## Check results without trusting row order

A useful routine is:

1. Run with `--sizes` and check rough relation sizes.
2. Export with `--debug-dir` and inspect a few expected rows.
3. Sort output before diffing it; relation order is unspecified.
4. Add a tiny `bad` relation for an invariant that should never hold.
5. Query a saved database rather than editing an expensive base analysis.

For example, a graph claimed to be acyclic can check itself:

```slog
table (bad str)
rule (path X X) --> (bad X)
```

`bad.csv` should be empty. For automated regression tests, the repository's
golden suite uses the same idea with expected relation output.

## Exact and compressed saves

`--out-db NAME` writes an exact standalone database.

`--out-db-compressed NAME` writes a linked database that can retain only a
sample of derived facts and replay stored program sources to recover the full
result on load. It can be much smaller, but loading does compilation and work.
Use `--per` to set the retained fraction, or let Slog choose. Use `--flatten`
with a compressed save to write a self-contained exact root instead.

Database names form an immutable dependency graph. Slog refuses to overwrite
a database that another saved database references unless you pass `--force`.
Use `racket compiler/run.rkt db tree` and `racket compiler/run.rkt db verify NAME --replay` to
inspect and check that graph.

The [database guide](../user/databases.md) explains compression, replay,
editing, verification, and database commands.

## Continue from here

You now have the basic working model:

- facts and recursive rules build relations;
- structured values and collections carry rich data;
- demands give on-request memoized computations;
- lattices keep converging summaries;
- `include`, `run`, and saved databases organize larger work;
- a small loaded program makes a good follow-up query.

The [user documentation](../user/README.md) is the next stop. It gives the
complete language and built-in reference, then covers libraries, the command
line, databases, APIs, runtime design, and extension work.
