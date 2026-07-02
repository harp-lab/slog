# Slog

The Slog programming language, compiler, and runtime: a Datalog with
s-expression syntax, interned first-class structures, and a parallel
semi-naive fixpoint engine.

```
table (edge int int)
table (path int int)

facts
(edge 1 2)
(edge 2 3)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
```

Run a program (from the repository root):

```
racket slog.rkt --debug-dir out/reach tests/reach.slog
```

which compiles it, executes it to fixpoint, and writes one CSV per
non-empty relation into `out/reach/`.

## Language

- `table (name type ...)` declares a relation; `struct (name type ...)`
  declares an interned record with identity (usable as a value in other
  relations); `union (u member ...)` declares a type union whose nullary
  members like `(halt)` are enum constants; `enum (color red green blue)`
  declares an enumeration usable as a column type.
- `facts` introduces ground atoms; `rule body ... --> head ...` (or
  `head <-- body`) introduces rules. Bodies may use nested patterns
  (`(out (pair X Y))`), infix bindings (`id = (lambda x eb)`), guards
  (`(< X Y)`, `(/= X Y)`), primitive computations (`(= R (+ X 1))`),
  `|` alternatives, and `_` wildcards.
- `include "file.slog"` merges a file; `run "file.slog"` runs a
  prerequisite program to fixpoint first, on the same database.
- Primitives: `+ - * / % min max pow neg abs`, bitwise
  `band bor bxor bnot shl shr`, float math
  `sqrt sin cos tan exp log floor ceil round`, conversions
  `tofloat toint`, strings `size` / `substr` / `+` (concatenation).
  Comparisons `< <= > >=` are body guards. There is no negation.

## Architecture

- `compiler/` — the Racket compiler. `ir-stack.rkt` documents the stack of
  intermediate languages, one per pass; `compile.rkt` is the pipeline.
  Programs are stratified into a DAG of SCCs (Tarjan, `stratify.rkt`);
  each stratum's rules are planned (`join-planning.rkt`), lowered
  (`operationalization.rkt`), and emitted (`emit-cpp.rkt`) as one C++
  shared object, cached in `build/` by content hash.
- `daemon/` — `slogd`, the C++ runtime: a three-phase (write/read/intern)
  parallel semi-naive fixpoint over per-bucket B+-tree indices, with
  generated rule pipelines built from the push operators in `operators.h`.
- The daemon's entire protocol is one plugin `.so` path per line; each
  plugin's `slog_plugin(slog::Daemon*)` acts through the daemon API
  (`daemon.h`): stratum plugins push object representations of their rules
  onto the daemon's resident pipeline and run it forward (the database
  reloads between strata); small generated *action* plugins
  (`compiler/actions.rkt`) open a stored database, write it (whole or per
  relation, binary or CSV), refresh a relation whose files changed on disk,
  or report statistics back over the connection (e.g.
  `(relation_size path 6)`).
- The driver (`compiler/runslog.rkt`) streams those paths: an open action,
  the stratum plugins in topological order, then whatever output/statistics
  actions the client asked for.

## Tests

```
./tests/run-tests.sh            # golden-output tests (clears build/ first)
./tests/run-tests.sh --update   # re-snapshot goldens
raco test tests/unit/           # compiler unit tests
```

Dependencies: Racket (packages `graph`, `sha`), clang++ with OpenMP
(`libomp-dev`), boost headers, zlib.

See `License.md` for license information.
