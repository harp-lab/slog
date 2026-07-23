# Slog

The current development version is recorded once in [`.version`](.version);
bump and change-note conventions live in [`versions/`](versions/README.md).

Slog is a logic programming language for writing analyses over graphs,
programs, and other structured data. A program says what facts exist and how
new facts follow from them. Slog compiles those rules to native code and runs
them in parallel until no rule can add anything new.

Here is transitive closure over a graph:

```slog
table (edge int int)
table (path int int)

rule
(edge 1 2)
(edge 2 3)
(edge 3 4)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
```

The second rule is recursive. There is no loop or mutable `path` variable.
Slog keeps applying the rules until `path` contains every reachable pair.

Slog is a good fit when the problem is easier to state as relationships than
as a sequence of instructions. Its main features are:

- Parallel native execution. Each stratum becomes a cached C++ plugin run by
  a multithreaded fixpoint engine.
- First-class structured values. Trees, lists, sets, and maps can be nested,
  compared, and used as relation columns.
- Demand-driven functions. A recursive relation can be called like a
  memoized function and is evaluated only for inputs that are actually used.
- Checked lattice relations. Minimums, maximums, counts, sets, maps, and flat
  values support converging analyses such as shortest paths and constant
  propagation.
- Persistent databases. A run can save its facts, and a later program can
  load or extend them.
- An SMT library. Rules can ask Z3, cvc5, or the built-in ground evaluator for
  satisfiability, models, and unsat cores.

## Install and run

Run Slog from the repository root. It currently expects its `compiler/`,
`daemon/`, `lib/`, `build/`, and `data/` paths there.

The required tools and libraries are:

- Racket, including its `sha` package
- Rust and Cargo (to build the interactive `slog` frontend)
- GNU Make
- a C++20 Clang toolchain
- OpenMP for the same Clang toolchain
- Boost headers
- zlib development headers
- GMP development headers

On Debian or Ubuntu, the native packages are typically `racket`, `make`,
`clang`, `libomp-dev`, `libboost-dev`, `zlib1g-dev`, and `libgmp-dev`. If
Racket cannot load `sha`, install it with:

```console
$ raco pkg install sha
```

Slog builds the daemon and compiled rule plugins when they are needed. Put the
graph program above in `reach.slog`, then run:

```console
$ make -C repl
$ ./slog
```

This builds the native terminal frontend, copies it to the repository root,
and opens the interactive workbench. Type `:help` for the current server
commands, `library` to browse saved databases, or `:share` for trusted-local
co-author connection details.

For a one-shot batch run outside the REPL, use:

```console
$ racket compiler/run.rkt --no-banner --sizes --debug-dir out/reach reach.slog
(relation_size edge 3)
(relation_size path 6)
```

`--sizes` is a quick sanity check. `--debug-dir` writes one space-separated
`.csv` file per nonempty relation:

```console
$ sort -n out/reach/path.csv
1   2
1   3
1   4
2   3
2   4
3   4
```

The first run may spend time compiling. Compiled plugins are cached under
`build/`, so later runs of the same rules are much faster.

Slog normally uses `systemd-run` when it is available to enforce a hard memory
limit. Without it, Slog still has a graceful in-process memory limit, but not a
hard cgroup cap. Z3 and cvc5 are optional; the SMT library has a deterministic
`mock` backend for ground formulas.

## A little more than reachability

Structured values let rules describe a small language and reason about its
programs directly:

```slog
union (expr (num int)
            (add expr expr)
            (var str))

demand (contains_var expr) str
table (input expr)
table (found expr str)

rule (contains_var (var X) X)
rule (contains_var (add A B) X) <--
     (contains_var A X) | (contains_var B X)

rule (input (add (num 1) (var "count")))
rule (input E) (contains_var E X) --> (found E X)
```

`expr` is a tagged union. A value such as `(add (num 1) (var "count"))` is an
ordinary value, not an object with identity. Rules build and pattern-match it
by shape.

Demand declarations add function-like calls without leaving the logic:

```slog
demand (fib int) int

rule (fib 0 0)
rule (fib 1 1)
rule (> N 1)
     (= A (fib (- N 1)))
     (= B (fib (- N 2)))
  --> (fib N (+ A B))

table (answer int)
rule (= X (fib 20)) --> (answer X)
```

Only demanded `fib` inputs are computed, and answers are memoized as facts.

## Where to read next

The [four-part tutorial](docs/tutorial/01-getting-started.md) starts from a
first program, introduces the important language features, and ends with a
practical saved-database and follow-up-query workflow:

1. [Run a program](docs/tutorial/01-getting-started.md)
2. [Rules and data](docs/tutorial/02-rules-and-data.md)
3. [Functions, collections, and lattices](docs/tutorial/03-combining-features.md)
4. [Files, databases, and follow-up queries](docs/tutorial/04-projects-and-queries.md)

The [user documentation](docs/user/README.md) is the complete guide and
reference. Start there when you need exact syntax, every built-in operation,
the SMT library, command-line options, persistence, the Racket session API, or
guidance for extending Slog with a primitive or oracle.

The files directly under `docs/` are implementation notes and design records.
They are useful when changing the compiler or runtime, but they are not the
best place to learn the language.

## Repository map

```text
compiler/run.rkt       command-line entry point
compiler/repl.rkt      private local REPL session server
repl/          Rust terminal frontend; builds the root slog executable
compiler/      parser, type checker, planner, code generator, and drivers
daemon/        parallel runtime and persistent database implementation
lib/           Slog libraries, including lists, rule-based maps/sets, and SMT
examples/      larger Slog programs
tests/         golden, unit, integration, and runtime tests
docs/tutorial/ short course
docs/user/     user guide and reference
```

For a quick regression run, use `tests/run-tests.sh`. The full test entry point
is `tests/run-all.sh`; it also covers unit, integration, and focused
incremental stress suites.

See [License.md](License.md) for license information.
