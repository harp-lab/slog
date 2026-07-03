# Slog

Slog is a logic programming language in the Datalog family, with
s-expression syntax, first-class structured values, lattice-valued
relations, and a parallel engine underneath. You don't write
step-by-step instructions; you write *facts* (things that are true) and
*rules* (ways to derive new facts from old ones), and Slog computes
everything derivable — no more, no less. This Readme is a short
tutorial: a handful of tiny programs, each run for real at the command
line, including shortest paths that converge on cyclic graphs, a
control-flow analyzer in six rules, and a constant-propagation pass
whose soundness discipline is enforced by the compiler.

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
That's the honest pure-Datalog version; the proper version is one
declaration away (below).

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

### The lattice version

The bound is a hack, and it computes the wrong relation — we wanted
*the* shortest distance, not "every cost under 12". Declare the cost
column as a `min`-lattice and both problems disappear. Replace
`sssp.slog` with:

```
lattice (cost (min int #:floor 0))
table (edge int int int)
table (dist int cost)          ;; now a MAP: node ⟼ least cost

facts
(edge 1 2 4)
(edge 1 3 1)
(edge 3 2 2)
(edge 2 4 5)
(edge 4 1 1)

facts (dist 1 0)
rule (dist X C) (edge X Y W) --> (dist Y (+ C W))
```

`lattice` declares a value *type* equipped with a merge — here integers
merged by `min`. Any relation with a lattice-typed column is
automatically a *map* from its other columns to a single merged value:
deriving `(dist Y 9)` doesn't insert a row, it *contributes* 9, and the
stored value only ever improves. Absence means "no path found yet", the
guard and the `(= C2 ...)` scaffolding are gone, and the cycle
converges on its own because a trip around the loop is never an
improvement:

```
$ racket slog.rkt --debug-dir out/sssp sssp.slog
$ sort -k1,1n out/sssp/dist.csv
1   0
2   3
3   1
4   8
```

One row per node, each the true shortest distance — Dijkstra's answer
from a two-line program that never says "visited" or "priority queue".

Two details worth noticing. `#:floor 0` clamps costs below at zero:
that's what makes termination a *guarantee* rather than your problem
(with negative-weight cycles, costs would otherwise improve forever;
leave the floor off and the compiler warns you that termination is on
you). And inside `dist`'s own recursion, the compiler only admits uses
of `C` that stay correct while the value is still improving —
contributing it onward through monotone arithmetic, bounding it above
with `<`, or ignoring it. Try to smuggle a still-improving cost into an
ordinary relation, use it as a lookup key, or test it with `>`, and you
get a compile error naming the offense. After `dist`'s fixpoint, later
rules can do anything with the final values.

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

## 5. Lattices over structured values: constant propagation

Section 2's lattice merged numbers. Lattices also merge *structured*
values, and that turns set-of-facts analyses into classic dataflow
analyses. Constant propagation asks, for every program point and
register: does it hold one known constant, or has it been overwritten
by conflicting values? That's a three-level answer — *nothing yet*,
*this exact value*, or *more than one* — which is precisely the `flat`
lattice: `(flat T)` lifts any type `T` so that equal contributions
stay themselves and any two different ones collapse to `(top)`. Put
this in `constprop.slog`:

```
union (value (vnum int) (vstr str))
lattice (fv (flat value))

table (assign int int value)   ;; label, register, constant assigned there
table (flow int int)           ;; control-flow edge
table (regval int int fv)      ;; MAP: (label, register) ⟼ known value
table (constat int int value)
table (nonconst int int)

facts
(assign 1 10 (vnum 5))
(assign 2 11 (vnum 1))
(assign 3 11 (vstr "two"))
(flow 1 2) (flow 1 3) (flow 2 4) (flow 3 4)

rule (assign L R K) --> (regval L R K)
rule (flow L L2) (regval L R V) --> (regval L2 R V)

rule (regval L R V) (= V (vnum N)) --> (constat L R (vnum N))
rule (regval L R V) (= V (top))   --> (nonconst L R)
```

The control-flow graph is a diamond: label 1 branches to 2 and 3, which
rejoin at 4. Register 10 is set once, before the branch; register 11 is
set to *different* constants on the two arms. The analysis is the two
rules in the middle — an assignment contributes its constant, and flow
edges propagate whatever is known. Note what's being merged: `(vnum 5)`
and `(vstr "two")` are interned structured values, ordinary column
data, and `flat`'s merge only needs equality — so this works unchanged
over your own IR's terms, ASTs, types, whatever you've declared.

```
$ racket slog.rkt --debug-dir out/constprop constprop.slog
$ sort -k1,1n -k2,2n out/constprop/regval.csv
1   10   (vnum 5)
2   10   (vnum 5)
2   11   (vnum 1)
3   10   (vnum 5)
3   11   (vstr "two")
4   10   (vnum 5)
4   11   (top)
```

Register 10 survives the join as a constant; register 11's two arms
collide and label 4 sees `(top)` — one row per (label, register), the
textbook result. The extraction rules then report both readings:

```
$ cat out/constprop/nonconst.csv
4   11
$ sort -k1,1n out/constprop/constat.csv | tail -2
3   10   (vnum 5)
4   10   (vnum 5)
```

The interesting part is what the compiler let those last two rules do,
and where. Asking `(= V (top))` — "is it already conflicting?" — is
safe at any time: once true, more merging can't make it false. Asking
`(= V (vnum N))` — "is it (still) this constant?" — is the classic
dataflow soundness trap: a conclusion drawn mid-analysis can be
overturned when another branch merges in. Slog's rule is simple:
inside the strongly-connected component that's still growing `regval`,
downward-closed tests like that are compile errors; in a later stratum
(these two rules only *read* `regval`, so they run after its fixpoint)
they're unrestricted. The bug you'd normally document in a comment is
a type error here.

The same machinery covers more exotic measures — `(count)` is the
abstract-counting chain 0 < 1 < ∞ used to justify strong updates in
higher-order analyses: `examples/tinycfa/0cfa-counting.slog` bolts it
onto section 4's analyzer and certifies which variables are must-alias
singletons. And lattice types compose with `demand` so a recursive
function's memoized answers merge instead of accumulate:
`tests/lat_demand.slog` computes min-cost paths as a one-line recursive
function. `docs/lattices.md` has the full design.

## 6. Keeping a database around

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
`dem_sppf` builds shared parse forests), and the `lat_*` family does
the same for lattices (shortest paths with and without negative cycles,
the constant propagator above, abstract counting, lattice-valued demand
answers). Design notes live in `docs/` (`demand.md` for sections 3–4,
`lattices.md` for sections 2 and 5 — including the monotone-use rules
and what's still to come, like powerset and interval lattices — and
`incremental.md` for where things are going next). The compiler is
Racket under `compiler/` (`ir-stack.rkt` maps the passes), and the
runtime is a parallel C++ fixpoint engine under `daemon/`; each stratum
of your program JIT-compiles to a native plugin, cached in `build/` so
unchanged programs restart instantly.

To run the test suite:

```
./tests/run-tests.sh            # golden-output tests (clears build/ first)
./tests/run-tests.sh --update   # re-snapshot goldens
```

See `License.md` for license information.
