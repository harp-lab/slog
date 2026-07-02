# Slog

Slog is a logic programming language in the Datalog family, with
s-expression syntax, first-class structured values, and a parallel
engine underneath. You don't write step-by-step instructions; you write
*facts* (things that are true) and *rules* (ways to derive new facts
from old ones), and Slog computes everything derivable — no more, no
less. This Readme is a short tutorial: four tiny programs, each run for
real at the command line, ending with a control-flow analyzer in six
rules.

To follow along you'll need Racket (with the `graph` and `sha`
packages), a `clang++` with OpenMP (`libomp-dev`), boost headers, and
zlib. Run everything from the repository root.

## 1. Facts, rules, and reachability

The "hello world" of Datalog is graph reachability. Put this in
`reach.slog`:

```
table (edge int int)
table (path int int)

facts
(edge 1 2)
(edge 2 3)
(edge 3 4)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
```

Reading it top to bottom: `table` declares a relation and the types of
its columns — `edge` and `path` each relate two integers. The `facts`
block asserts three edges: a little chain 1 → 2 → 3 → 4.

Then the rules. A rule says: *whenever everything on the left of the
arrow holds, the thing on the right holds too*. Capitalized-or-not,
names like `X` and `Y` in a rule are variables; the same variable in two
places must be the same value. So the first rule says every edge is a
path. The second says: if there's a path from `X` to `Y`, and an edge
from `Y` to `Z`, then there's a path from `X` to `Z`. That's transitive
closure in two lines. Notice there's no loop and no "visited" set — the
engine keeps applying rules until nothing new can be derived (a
*fixpoint*), and the second rule feeding itself is not just fine, it's
the point.

Run it:

```
racket slog.rkt --debug-dir out/reach reach.slog
```

This compiles the program (to native code, cached under `build/`), runs
it to fixpoint, and writes one CSV per non-empty relation into
`out/reach/`. Sanity-check the result:

```
$ sort out/reach/path.csv
1   2
1   3
1   4
2   3
2   4
3   4
```

Six paths — every ordered pair reachable along the chain. (Row order
out of the engine isn't meaningful, so pipe through `sort` when
eyeballing; `wc -l` is a quick size check.)

## 2. Arithmetic and guards: shortest paths

Now weighted edges. Put this in `sssp.slog`:

```
table (edge int int int)     ;; from, to, weight
table (dist int int)         ;; node, cost of some path from the source

facts
(edge 1 2 4)
(edge 1 3 1)
(edge 3 2 2)
(edge 2 4 5)
(edge 4 1 1)

facts (dist 1 0)
rule (dist X C) (edge X Y W) (= C2 (+ C W)) (< C2 12) --> (dist Y C2)
```

Node 1 is our source, at distance 0. The rule reads: if we can reach
`X` at cost `C`, and there's an edge to `Y` of weight `W`, then we can
reach `Y` at cost `C2 = C + W`. Two new ingredients: `(= C2 (+ C W))`
binds a variable to a computed value, and `(< C2 12)` is a *guard* — a
filter that must hold for the rule to fire.

Why the guard? This graph has a cycle (4 loops back to 1), and Datalog
derives *every* derivable fact — including the cost of going around the
loop once, twice, three times, forever. The bound keeps the set finite.
(A proper `min`-lattice, so `dist` keeps only the smallest cost per
node and cycles converge on their own, is where the language is headed
— see `docs/lattices.md` — but bounded enumeration is the honest pure-
Datalog version.)

```
$ racket slog.rkt --debug-dir out/sssp sssp.slog
$ sort -k1,1n -k2,2n out/sssp/dist.csv
1   0
1   9
1   10
2   3
2   4
3   1
3   10
3   11
4   8
4   9
```

Each node's *shortest* distance is its first row: node 2 at cost 3 (via
3, since 1+2 < 4), node 4 at cost 8. The other rows are real too —
longer routes, and trips around the cycle that stayed under the bound.

## 3. Functions on demand

Here's where Slog stops looking like classic Datalog. Rules run
"forward" — from facts to consequences — which is awkward for things
that are naturally *functions*: you don't want every Fibonacci number,
you want `fib(10)`, and whatever that call needs. The `demand` form
gives you exactly that. Put this in `fib.slog`:

```
demand (fib int) int

rule (fib n n) <-- (< n 2)
rule (fib n (+ (fib (- n 1)) (fib (- n 2)))) <-- (< 1 n)

table (answer int)
rule (= r (fib 10)) --> (answer r)
```

`demand (fib int) int` declares that `fib` takes one integer *input*
and relates it to integer *answers* — and, crucially, that it's
computed on demand: nothing is evaluated until someone asks.

The rules are written conclusion-first this time (`head <-- body`, the
flip of `-->` — use whichever reads better). The first says a demanded
`(fib n)` with `n < 2` answers `n`. The second is the whole recursion
in one line: nested occurrences like `(fib (- n 1))` are *calls*
denoting the answer, exactly like `(+ ...)` denotes a sum, so the rule
says `fib n` answers `fib(n-1) + fib(n-2)` — direct, non-tail recursion,
in a Datalog. The last rule asks: `(= r (fib 10))` calls `fib` and binds
the answer.

Under the hood this is still just facts and rules. A demand like
`(fib 10)` is itself a first-class fact (asking *is* asserting), the
compiler splits your rules so the recursive calls are asked exactly when
needed, and answers land in a generated `fib_ans` relation keyed by the
demand. Because demands are stored values, each distinct call is
computed once — memoization for free:

```
$ racket slog.rkt --debug-dir out/fib fib.slog
$ cat out/fib/answer.csv
55
$ sort out/fib/fib_ans.csv | head -3
(fib 0)   0
(fib 10)   55
(fib 1)   1
```

That `(fib 0)` in the first column is a structured value printed
readably — the demand fact itself, with its answer beside it. Exactly
the eleven demands `fib 0` through `fib 10` exist: nothing you didn't
ask for was computed. And it's a *relation*, not a function: a demand
may have one answer, many (nondeterminism), or none — failure is just
absence, no error machinery.

## 4. The payoff: 0CFA in six rules

Let's analyze programs with all of this. A *control-flow analysis*
answers "which functions can end up where?" for a language with
first-class functions. First we need programs as data. Put this in
`cfa.slog`:

```
union (expr (lambda str expr) (app expr expr) (ref str))
union (val lambda)
table (program expr)
table (store str val)
table (result val)

facts (program (app (lambda "id" (ref "id")) (lambda "y" (ref "y"))))
```

`union` declares a type as a choice of *constructors*: an expression is
a lambda, an application, or a variable reference. Constructed values
like `(lambda "id" (ref "id"))` are interned structured facts — nested
freely, stored once, usable as column values. Our test subject is the
program `(λid. id) (λy. y)`.

Now the analyzer itself — a demand-driven evaluator:

```
demand (eval expr) val

facts (eval (lambda x eb) (lambda x eb))
rule (eval (ref x) v) <-- (store x v)
rule (eval (app ef ea) v) <-- (eval ef (lambda x eb)) (eval ea va) (eval eb v)
rule (eval (app ef ea)) (eval ef (lambda x eb)) (eval ea va) --> (store x va)

rule (program e) --> (eval e)
rule (program e) (eval e v) --> (result v)
```

Walk through it. A lambda evaluates to itself — note that's a `facts`
line with variables in it: it answers *any* demanded lambda, binding
`x` and `eb` from the demand. A reference evaluates to whatever the
store says its variable can hold. An application evaluates its function
and argument (in parallel, as it happens — they don't depend on each
other), and once the callee is known, the body; the body's value is the
application's value. The fourth rule flows the argument into the
parameter's store entry as soon as callee and argument are known —
written as a separate rule because the body can't produce an answer
*until* that binding lands. Finally: demand the whole program, and
collect what comes back.

```
$ racket slog.rkt --debug-dir out/cfa cfa.slog
$ cat out/cfa/result.csv
(lambda "y" (ref "y"))
$ cat out/cfa/store.csv
"id"   (lambda "y" (ref "y"))
```

The program evaluates to `λy. y`, and the analysis additionally tells
us everything `id` could ever be bound to. This is a real (monovariant,
"0CFA") analysis: on programs that diverge it still terminates, because
there are only finitely many subexpressions to demand. A comparison
worth making: `examples/tinycfa/0cfa.slog` is the same analysis written
the traditional way, with hand-built continuation structs and an
eval/ret protocol — and `examples/tinycfa/0cfa-demand.slog` is this
six-rule version, producing identical results. The plumbing you didn't
write is what `demand` compiles away.

One more toy in the box: lambdas. Slog programs can contain their own
`(lambda (x) ...)` terms — they become interned closure values
dispatched through a generated `apply` relation, so you can write
`(map2 (lambda (n) (* n 10)) l)` and pass functions around as values.
See `tests/dem_lambda.slog` and `tests/dem_stlc.slog` (a type checker
whose rules are the textbook inference rules) for where that leads.

## 5. Keeping a database around

Everything so far ran facts-to-CSVs in one shot. You can also persist
the database and build on it across runs. Split the reachability
example in two — `graph.slog` holding only the data:

```
table (edge int int)

facts
(edge 1 2)
(edge 2 3)
(edge 3 4)
```

and `reach2.slog` holding only the logic (it declares `edge` but
asserts nothing):

```
table (edge int int)
table (path int int)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
```

Load the data once, saving the database under a name; then run the
logic against it:

```
$ racket slog.rkt --out-db tutorial graph.slog
$ ls data/tutorial
table.edge.arity.2  value.strings

$ racket slog.rkt -d tutorial --debug-dir out/reach2 --sizes reach2.slog
...
(relation_size edge 3)
(relation_size path 6)
```

(among a `(fixpoint ...)` line per compiled stratum and a size line for
`_enum`, an internal bookkeeping relation).

`--out-db NAME` writes the final database (binary, one file per
relation) under `data/NAME/`; `-d NAME` starts a later run from it.
`--sizes` prints tuple counts — the quickest sanity check of all: three
edges in, six paths out, exactly as in section 1. Chain `--out-db` onto
that run too and you've got a pipeline. (Within a single program,
`include "file.slog"` splices another file in, and `run "file.slog"`
runs a prerequisite program to fixpoint first on the same database —
that's how the tinycfa example loads its test programs.)

## Where to go next

The `tests/` directory is a corpus of small worked examples — the
`dem_*` family covers the demand feature from every angle (`dem_parse`
turns a grammar into an Earley-style parser; `dem_ack` is Ackermann;
`dem_sppf` builds shared parse forests). Design notes live in `docs/`
(`demand.md` for everything in sections 3–4, `incremental.md` and
`lattices.md` for where things are going). The compiler is Racket under
`compiler/` (`ir-stack.rkt` maps the passes), and the runtime is a
parallel C++ fixpoint engine under `daemon/`; each stratum of your
program JIT-compiles to a native plugin, cached in `build/` so
unchanged programs restart instantly.

To run the test suite:

```
./tests/run-tests.sh            # golden-output tests (clears build/ first)
./tests/run-tests.sh --update   # re-snapshot goldens
```

See `License.md` for license information.
