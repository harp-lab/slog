# Demand functions and lattices

Demand and lattice declarations solve different problems.

- A demand says, “compute answers only for these requested inputs, and remember
  them.”
- A lattice says, “many rules may propose values for this key; keep their
  monotone summary.”

Both remain relational. They participate in dependency analysis, fixpoints,
persistence, and ordinary joins.

## Demand functions

### Declaration and full relational form

A demand signature places inputs inside its name form and answer types after
it:

```slog
demand (parse str int) int
```

This declares two input columns, `str` and `int`, and one integer answer. Its
rules use the full relational shape `(parse input1 input2 answer)`:

```slog
rule (parse "zero" 10 0)
rule (parse Text 10 N) <-- (= N (s2i Text))
```

Every demand needs at least one input and at least one answer. A demand can
have zero, one, or several answer rows for one input. It is function-like but
does not promise mathematical single-valuedness.

### Asking for an answer

For one answer column, call the demand where a value is expected:

```slog
table (source str)
table (number int)

rule (source S) (= N (parse S 10)) --> (number N)
```

The call creates a request for `(parse S 10)` and suspends the surrounding
logic until an answer exists. If the demand has several answers, the rule
resumes once for each one.

The full-arity body form asks too:

```slog
rule (source S) (parse S 10 N) --> (number N)
```

Use it when the relational reading is clearer.

### Multiple answer columns

Declare more answer types after the input signature:

```slog
demand (quotient_remainder int int) int int

rule (quotient_remainder N D Q R) <--
     (= Q (/ N D))
     (= R (% N D))
```

A multi-answer demand has no single value-position result. Ask in full form:

```slog
rule (quotient_remainder 17 5 Q R) --> (result Q R)
```

It may produce several `(Q, R)` pairs if its rules are nondeterministic.

### Direct recursion

Demand rules can look like ordinary recursive functions:

```slog
demand (ack int int) int

rule (ack 0 N (+ N 1))
rule (ack M 0 (ack (- M 1) 1)) <-- (> M 0)
rule (ack M N (ack (- M 1) (ack M (- N 1)))) <-- (> M 0) (> N 0)

table (answer int)
rule (= X (ack 3 4)) --> (answer X)
```

Nested calls create demands for their inputs. Answers are memoized as facts,
so repeated subcalls share work.

Demand does not make unbounded recursion safe. Ackermann grows quickly; this
example is deliberately small. A demand that keeps discovering fresh inputs
can consume unbounded time or memory.

### Partial and nondeterministic answers

No matching demand rule means no answer. That is useful for parsing and
lookups:

```slog
demand (even_half int) int
rule (even_half N (/ N 2)) <-- (= 0 (% N 2))
```

A caller of `(even_half 7)` simply does not resume.

Several rules may answer one input:

```slog
demand (neighbor str) str
table (edge str str)
rule (edge X Y) --> (neighbor X Y)
rule (edge Y X) --> (neighbor X Y)
```

Calling `(neighbor "a")` resumes once per distinct neighbor. Do not assume
single-valuedness just because value-call syntax is available.

### The generated request and answer relations

For a demand named `f`, the compiler creates:

- a structured request value `(f inputs...)`;
- an answer table `f_ans` keyed by that request.

Conceptually, `demand (f A B) C` has an answer table shaped like:

```slog
table (f_ans f C)
```

The generated ask and resume rules make ordinary calls convenient. The
backing table is also a deliberate escape hatch:

```slog
rule (f_ans (f A B) C) --> (observed_answer A B C)
```

This enumerates answers for requests that some call already made. Reading
`f_ans` does not itself request new inputs. That difference matters for
post-hoc views such as `smt_sat`.

Backing names are part of the current generated interface and appear in
debug output and saved databases. Prefer normal calls except when you need to
enumerate all already-demanded answers.

### Calls inside values and heads

Calls may appear inside constructed values:

```slog
demand (sum (list int)) int
rule (sum [] 0)
rule (sum [X XS ...] (+ X (sum XS)))
```

They may also fill a struct field or list element. The compiler separates the
request from the eventual head emission so the head is not produced before
the answer exists.

When debugging a complicated nested call, expand it into equality clauses:

```slog
rule (input XS)
     (= TailSum (sum XS))
     (= Result (+ 1 TailSum))
  --> (output Result)
```

The expanded form makes data dependencies and partial failures easier to see.

### Lambdas and closures

A lambda has parameter names and a value expression:

```slog
(lambda (X) (* X 2))
```

It becomes a `clo` value. Free variables are captured from the rule match that
creates it. A closure variable can be called in value position:

```slog
demand (map2 clo list) list
rule (map2 F [] [])
rule (map2 F [X XS ...] [(F X) (map2 F XS) ...])

table (factor int)
table (scaled list)

rule (factor K)
     (= R (map2 (lambda (N) (* N K)) [1 2 3]))
  --> (scaled R)
```

For `K = 10`, the result is `[10 20 30]`.

A demand may return a closure:

```slog
demand (compose clo clo) clo
rule (compose F G (lambda (X) (F (G X))))
```

Closures are interned values and can be stored in relations. They are best
used for small higher-order combinators. A named demand gives clearer output
and simpler error locations for central program logic.

### Demand performance model

Demand transformation works backward from calls. It avoids computing answers
for inputs nobody asks about, which can be a large win for interpreters,
parsers, and graph searches with a narrow query set.

The tradeoffs are:

- Each distinct request and answer is stored as data.
- Generated ask, answer, and resume rules add joins and may cross iterations.
- A broad call can still demand the whole input space.
- A demand answer is a set. Accidental nondeterminism increases both work and
  caller results.

Inspect the generated `f` and `f_ans` relation sizes with `--sizes` or
`--debug-dir` when demand behavior is surprising. Runtime `$stat_fires.csv`
can show which generated variants are doing the work.

A recursive demand over list suffixes may also trigger the compiler's warning
about a growing sequence relation with occurrence indexing. The warning is
literal: indexing every suffix can store work proportional to the number of
suffixes times their lengths. That is fine for short lists, but worth measuring
before using the same shape on large sequences.

## Lattices

### Why a normal table is sometimes wrong

This ordinary table keeps every proposed distance:

```slog
table (distance str str int)
```

If rules derive distances `10`, `7`, and `12` for the same node pair, all three
rows remain. A minimum lattice instead treats the earlier columns as a key and
joins all last-column proposals with `min`:

```slog
lattice (cost (min int #:floor 0))
table (distance str str cost)
```

The visible value for that key settles at `7`.

### Table shape

A lattice name is a type for the last column of a table:

```slog
lattice (score (max int))
table (best str score)
```

`str` is the key and `score` is the lattice value. A lattice table needs at
least one key column; only the last column may be lattice-valued. Each key has
at most one current joined value.

The absence of a row is the lattice bottom. Proposals move the value upward in
the lattice's information order until a fixpoint.

### Minimum and maximum

Declarations are:

```slog
lattice (low_int (min int))
lattice (bounded_low (min int #:floor 0))
lattice (high_float (max float))
lattice (bounded_high (max float #:ceiling 1.0))
```

`min` accepts `int` or `float` and keeps the numerically smallest proposal.
Its information order views smaller values as later, better information.
`#:floor` gives a lower bound: Slog clamps any smaller proposal to the floor.

`max` keeps the numerically largest proposal. `#:ceiling` gives an upper
bound and clamps larger proposals to it.

For integers, a finite floor or ceiling gives a finite range of improving
values. Without one, an integer lattice can keep improving forever. Bounds
do not settle the rest of the program for you: a rule can still keep creating
new table keys or other unbounded values. Floating-point bounds clamp values
too, but do not promise a small number of improvement steps.

Shortest path with nonnegative edge weights is the standard example:

```slog
lattice (cost (min int #:floor 0))
table (edge str str int)
table (dist str str cost)

rule (edge X Y W) --> (dist X Y W)
rule (dist X Y A) (dist Y Z B) --> (dist X Z (+ A B))
```

### Count

The count lattice distinguishes no evidence, exactly one contribution, and
two or more contributions:

```text
absence < one < inf
```

Declare and populate it with count values:

```slog
lattice (cardinality (count))
table (definitions str cardinality)
table (defines str str)

rule (defines Site Name) --> (definitions Name (one))
```

Independent proposals join idempotently: repeated derivation of the same fact
does not increase a count. To combine counts along a rule, use `cplus`:

```slog
rule (left X A) (right X B) --> (combined X (cplus A B))
```

`(one)` represents exactly one and `(inf)` represents two or more. This is an
abstract cardinality lattice, not an exact bag count.

### Flat values

A flat lattice represents no value, one known value, or conflict:

```text
absence < each concrete T value < top
```

Different concrete proposals join to `(top)`:

```slog
union (constant (ci int) (cs str))
lattice (known_constant (flat constant))
table (value_at str known_constant)
table (literal str int)

rule (literal Site N) --> (value_at Site (ci N))
```

If two different constants reach a site, its value becomes `(top)`. Matching
or copying a flat value while it is still changing would be unsound, so the
compiler restricts same-fixpoint uses and normally schedules inspection after
closure.

### Set lattices

A set lattice joins proposals by union:

```slog
lattice (values (set int))
table (possible str values)
table (seed str int)

rule (seed Name N)
     (= Singleton (cins (cmap) N))
  --> (possible Name Singleton)
```

It is often useful for dataflow facts, possible targets, free variables, or
reachable states. The element type can be any Slog type.

Safe same-fixpoint operations include inserting into the set, unioning sets,
and passing the set through a known collection join. Operations that observe
absence, exact size, or equality generally need a closed value.

### Map lattices

A map lattice joins pointwise. Its value specification gives a key type and a
child lattice:

```slog
lattice (environment (map str (flat int)))
lattice (best_costs (map str (min int)))
lattice (nested (map str (map int (set str))))
```

If two proposals bind the same map key, their child values join by the child
specification. Keys present in only one proposal are retained.

The current compiler does not allow `#:floor` or `#:ceiling` inside a map
value specification. Those bounds are available only on top-level scalar
`min` and `max` lattices.

`cput` builds a proposal. `cjoin` joins two maps with the enclosing lattice
specification:

```slog
lattice (best_costs (map str (min int)))
table (summary str best_costs)
table (measurement str str int)

rule (measurement Group Name Cost)
     (= OneName (cput (cmap) Name Cost))
  --> (summary Group OneName)
```

Do not use left-biased `cmerge` as if it were a map lattice join. The result of
a collision would depend on argument order.

### Collection lattice views

For a table `R` with a collection lattice in its last column, Slog synthesizes
decomposition relations.

For a set:

```slog
lattice (strset (set str))
table (members str strset)

;; synthesized shape:
;; table (members_has str str)
```

`(members_has Group Item)` holds for each element in the settled or safely
ascending set.

For a map:

```slog
lattice (counts (map str (max int)))
table (totals str counts)

;; totals_at columns:
;; table key `str`, map key `str`, child lattice `(max int)`
```

`R_at` adds the map key and child value after the table's key columns. Nested
map specifications can be decomposed one level at a time.

These views are compiler-generated relations. Do not declare a conflicting
`R_has` or `R_at` yourself.

### The soundness check

A lattice value may change during its producing strongly connected component.
A rule that turns a temporary value into an ordinary permanent fact could make
that fact stale after the lattice improves. Slog rejects such a rule unless it
can prove the use is monotone.

For example, this is not safe inside the same recursive component:

```slog
;; Conceptual bad shape: a temporary minimum is copied into a plain table.
rule (best X D) --> (reported X D)
```

If `D` changes from `10` to `7`, the plain `reported X 10` row cannot be
retracted. If `reported` depends only on a completed `best` stratum, the rule
is fine and the compiler schedules it later.

The current same-component whitelist is intentionally small:

- `min` and `max`: direct propagation, `min`, `max`, addition, subtraction
  when only the minuend is changing, and multiplication by a known
  nonnegative literal in the accepted direction.
- `count`: `cplus`.
- `flat`: no value-transforming transfer before closure.
- `set`: `cins` in its collection argument, `cmerge`, and `cjoin`.
- `map`: `cput` in its collection argument, `cget` to descend into its child
  lattice, and `cjoin`.

Upward-closed numeric guards can also be accepted when their direction agrees
with the lattice order. Exact equality, arbitrary comparison, use as a plain
table value, use as a relation key, or insertion into a struct generally waits
for closure.

The checker follows taint through expressions. If a rule uses two lattice
values, each argument position must be monotone. A transfer not on the
whitelist is rejected even if it happens to be sound for your data. Split the
program into a settled stage or extend the checker with a justified transfer
rule rather than hiding the value behind `any`.

### Termination and finite height

Lattice syntax gives a join, not a universal termination proof.

- A finite set lattice terminates if the element universe is finite.
- A flat lattice changes at most twice: absent to a value, then possibly top.
- The count lattice changes at most twice.
- A min or max lattice over unbounded integers can change forever.
- A map lattice terminates only if its key universe and child ascents are
  finite for the run.

Think about what fresh keys or values a recursive rule can create. Resource
budgets stop a runaway process, but they do not turn its partial result into a
completed fixpoint.

## Choosing between a demand and a lattice

Use a demand when inputs naturally identify a reusable computation and only a
subset of possible inputs should be evaluated. Recursive evaluators, parsers,
and syntax queries are good examples.

Use a lattice when many derivations contribute to one keyed summary and the
summary has a monotone join. Shortest distances, possible-value sets,
cardinality abstractions, and constant propagation are good examples.

They combine well. A demanded evaluator can return lattice-backed facts, and a
lattice rule can call a demand for a transfer function. Keep an eye on both
spaces: which demand inputs become reachable, and how many times each lattice
key can ascend.
