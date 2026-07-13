# 1. Run a Slog program

This tutorial assumes you have programmed in a language such as Java. In
Java, you usually describe a sequence of operations. In Slog, you describe
facts and rules, and the runtime finds all facts that follow.

We will start with a graph. Save this as `reach.slog` in the repository root:

```slog
table (edge str str)
table (path str str)

rule
(edge "a" "b")
(edge "b" "c")
(edge "c" "d")

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
```

`table` declares a relation. You can think of a relation as a named set of rows
with typed columns. `edge` and `path` each have two string columns.

The first `rule` has no conditions, so it states three facts. The next two
rules say:

- Every edge is a path.
- If there is a path from `X` to `Y` and an edge from that same `Y` to `Z`,
  there is a path from `X` to `Z`.

Names such as `X`, `Y`, and `Z` are variables. Repeating a variable means the
value must be the same in each place.

Run the program from the repository root:

```console
$ racket slog.rkt --no-banner --sizes --debug-dir out/reach reach.slog
(relation_size edge 3)
(relation_size path 6)
```

The first run compiles the rules to native code. Slog caches that code under
`build/`, so the next run is normally much faster.

`--sizes` prints the number of rows in each relation. This is often the first
sanity check to make. `--debug-dir` writes each nonempty relation:

```console
$ sort out/reach/path.csv
"a"   "b"
"a"   "c"
"a"   "d"
"b"   "c"
"b"   "d"
"c"   "d"
```

Relations are sets, so their rows have no meaningful order. Sorting is useful
when reading or comparing output.

## Read a rule

This rule is a join, much like a SQL join or two nested loops in Java:

```slog
rule (path X Y) (edge Y Z) --> (path X Z)
```

Slog tries every compatible pair of `path` and `edge` rows. The shared `Y`
must match. Each match produces a candidate `(path X Z)` row. Duplicate rows
collapse because a relation is a set.

The rule is also recursive because it reads and writes `path`. Slog does not
make just one pass. It keeps processing new rows until an iteration produces
nothing new. That stable state is called a fixpoint.

Recursion does not guarantee termination by itself. This example terminates
because it can only produce pairs of the four node names. A rule that keeps
creating larger integers or deeper structures may keep running until you stop
it or it reaches the memory limit.

## Make a small prediction

Add another edge:

```slog
rule (edge "d" "a")
```

Before running again, predict the size of `path`. The graph is now a cycle, so
every one of the four nodes can reach every node, including itself. The answer
should be 16. Checking a small result you can work out by hand is a good way to
test a rule before giving it a large data set.

## What to remember

- A relation is a set of typed rows.
- A body-less `rule` states facts.
- Clauses on the left of `-->` are conditions. Clauses on the right are
  conclusions.
- Repeated variables connect clauses.
- Slog runs recursive rules to a fixpoint.
- Use `--sizes` for row counts and `--debug-dir` to inspect relation contents.

Next: [rules and data](02-rules-and-data.md).
