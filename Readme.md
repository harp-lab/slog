# Slog

Slog is a declarative (logic) programming language. You do not write instructions
for the computer to follow — you write *facts* (things that are true) and
*rules* (ways new facts follow from old ones), and Slog computes
everything that follows. No loops, no assignment, no call stack. This is
transitive closure over a graph, in its entirety:

```
rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
```

The second rule feeds itself: the engine applies rules until nothing new can be
derived, and recursion is just a rule that mentions its own conclusion.

A few things distinguish Slog within this family of languages:

- **Programs JIT compile to parallel native code.** Each program becomes a
  specialized C++ plugin, cached, and run by a multithreaded fixpoint
  engine.
- **Structured values are first-class.** Trees, lists, sets, and maps
  are ordinary column values — nested freely, stored once, compared in
  constant time.
- **Functions on demand.** Recursive functions — direct, non-tail,
  memoized — live naturally inside the logic, computed only for the
  inputs actually asked about.
- **Lattice-valued relations.** Shortest paths, dataflow analyses, and
  abstract interpreters converge instead of enumerating, with the
  soundness discipline checked by the compiler.
- **Persistent databases.** Programs chain: one run's results are the
  next run's inputs.

## First steps

You need Racket (with the `sha` package), `clang++` with
OpenMP (`libomp-dev`), boost headers, and zlib. From the repository
root, put this in `reach.slog`:

```
table (edge int int)
table (path int int)

rule
(edge 1 2)
(edge 2 3)
(edge 3 4)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
```

Run it:

```
$ racket slog.rkt --debug-dir out/reach reach.slog
$ sort out/reach/path.csv
1   2
1   3
1   4
2   3
2   4
3   4
```

Six paths — every pair reachable along the chain `1 → 2 → 3 → 4`. The
first run compiles the program (cached under `build/`); afterwards it
starts instantly.

## A taste of something bigger

Here is a complete control-flow analyzer for a small functional
language — an abstract machine, written as data and eight rules. First,
programs and machine states are just structured values:

```
union (expr (lambda str expr) (app expr expr) (ref str))
union (val lambda)
union (stack (halt) kaddr (ar expr stack) (fn val stack))

struct (kaddr expr)
table (program expr)
table (store str val)
table (kstore kaddr stack)
table (eval expr stack)
table (ret val stack)
table (result val)

rule (program (app (lambda "id" (ref "id")) (lambda "y" (ref "y"))))
```

Then the machine — each rule is one transition:

```
rule (program e)                        --> (eval e (halt))
rule (eval (ref x) k) (store x v)       --> (ret v k)
rule (eval (lambda x eb) k)             --> (ret (lambda x eb) k)
rule (eval (app ef ea) k)               --> (eval ef (ar ea k))
rule (ret v (ar ea k))                  --> (eval ea (fn v k))
rule (ret v (fn (lambda x eb) k))       --> (eval eb (kaddr eb))
                                            (store x v)
                                            (kstore (kaddr eb) k)
rule (ret v (kaddr eb)) (kstore (kaddr eb) k) --> (ret v k)
rule (ret v (halt))                     --> (result v)
```

```
$ racket slog.rkt --debug-dir out/cfa cfa.slog
$ cat out/cfa/result.csv
(lambda "y" (ref "y"))
```

Worth noticing, in plain terms:

- `(lambda "id" (ref "id"))` is a **structured value** — a program as
  data. Values nest freely and each distinct one is stored exactly once,
  so using whole program fragments as keys costs nothing.
- The `stack` union makes **continuations data too**: `(ar e k)` is "an
  argument still to evaluate, then continue as k". Pattern-matching a
  rule against `(ret v (ar ea k))` *is* the machine's transition
  relation.
- `store` is a plain relation, so a variable maps to a **set** of
  values — which is exactly the over-approximation that makes the
  analysis terminate on programs that loop forever. Nothing had to be
  said to arrange this; sets are what relations are.

This is the classic "abstracted abstract machine" construction, and it
is the kind of program Slog is built for: the whole analyzer fits on a
slide, and the engine makes it parallel and fast.

## The tutorial

A guided course, from first facts to program analysis. Each chapter
ends with a cheat sheet.

1. [Getting started](docs/tutorial/01-getting-started.md) — your first
   program, and how to run it
2. [Rules and recursion](docs/tutorial/02-rules-and-recursion.md) — how
   new facts come from old ones
3. [Numbers, strings, and guards](docs/tutorial/03-numbers-strings-and-guards.md)
   — computing values and filtering
4. [Structured data](docs/tutorial/04-structured-data.md) — trees,
   tagged unions, and pattern matching
5. [Lists](docs/tutorial/05-lists.md) — `[1 2 3]` and friends
6. [Functions on demand](docs/tutorial/06-functions-on-demand.md) —
   recursive functions inside the logic
7. [Sets and maps](docs/tutorial/07-sets-and-maps.md) — `{1 2 3}` and
   `{k:v}` as first-class values
8. [Lattices](docs/tutorial/08-lattices.md) — shortest paths and
   dataflow, with checked soundness
9. [Programs and databases](docs/tutorial/09-programs-and-databases.md)
   — multiple files, persistence, pipelines
10. [Analyzing programs](docs/tutorial/10-analyzing-programs.md) — the
    payoff: program analysis in a page
11. [Under the hood](docs/tutorial/11-under-the-hood.md) — how Slog
    runs, and how to test it

See `License.md` for license information.
