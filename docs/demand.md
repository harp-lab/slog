# Demand-moded relations

Status: implemented, including value-position calls, lambdas, and
first-class call dispatch (2026-07). Surface form `demand`, transform in
`compiler/demand.rkt`, declarations in `compiler/modules.rkt`, tests in
`tests/dem_*.slog` plus unit tests in `demand.rkt`'s test submodule, and
`examples/tinycfa/0cfa-demand.slog`.

Origin: revisiting the `!`/`?` clause annotations from the Slog paper
(*Higher-Order, Data-Parallel Structured Deduction*, arXiv:2211.11573)
against this compiler. The follow-up paper (*Datalog with First-Class
Facts*, arXiv:2411.14330) dropped `!`/`?` and kept only fact identity and
subfact closure — evidence the durable core was the semantics, and the
sigils were separable surface.

## 1. Background: what `!` and `?` did

In the 2022 paper, `?` and `!` were per-occurrence *polarity flips* over
subfact-closed terms: `?(f args)` in head position was a premise written
inline in the conclusion (a body clause in a head), and `!(f args)` in
body position was a conclusion written inline in a premise — the rule
split into a subrule deriving the `!`-fact plus a continuation rule
joining a generated midpoint relation against the eventually-derived
result. Together they encode demand-driven evaluation: `!` is a call
(demand assertion + suspension), `?` a definition head (demand match),
the midpoint a defunctionalized continuation. That is what let the paper
write big-step interpreters and type checkers — direct, non-tail
recursion, promoted to relations.

The critique: they encode a *global* protocol with *local* sigils. The
reader reconstructs split points by dataflow analysis; `!`'s meaning
depends on its enclosing clause's polarity; midpoint relations leak into
the model unnamed. This compiler replaces the sigils with a relation-level
mode declaration and lets rules read as plain logic.

## 2. The declaration

```
demand (parse str int) int
```

reads: `parse` is computed on demand; a demand is the interned struct
`(parse str int)`; each demand relates to zero or more `int` answers.
Exactly two ordinary relations back it:

- **`parse`** — `struct (parse str int)`, the demand itself. There is no
  separate call relation: *asking is constructing*; the struct's extent
  is the set of all demands. Seeding is a fact: `facts (parse "E" 0)`.
- **`parse_ans`** — `table (parse_ans parse int)`: answers keyed by the
  demand (the key column's type is the demand struct itself).

Multiple answer columns are allowed (`demand (f w x) y z`). These are
**relations, not functions**: a demand may have zero answers (failure is
absence — no error machinery), one, or many (ambiguous parses, abstract
values). Hence `demand`, not `fun`.

Restrictions: at least one input column and at least one answer column
(zero answer columns would collide bare with full arity; encode checking
judgments with a unit/bool answer meanwhile).

## 3. Occurrences: one relation, four readings

For `demand (f in ...) out ...` with n inputs:

| occurrence | reading |
|---|---|
| `(f in... out...)` as a whole clause | **judgment**: in a head, answers demands (gated); in a body, needs answers (ask + resume) |
| `(f in...)` as a whole head clause / fact | **ask**, fire-and-forget |
| `(f in...)` as a whole body clause | **enumeration** of existing demands |
| `(f in...)` nested in an argument | **call**: denotes the answer (single-answer judgments only) |

plus the backing relations by name: `(f_ans d out...)` scans answers, and
`f_ans` keyed by a demand written in place — `(f_ans (f in...) out...)` —
is a content join (that key column's type is the demand struct, so the
nested occurrence there is never read as a call).

**Calls** are the value-position sugar. They compose anywhere a term
does — `=` bindings (exactly like primitive computations), guard
arguments, constructor arguments, other calls' demand arguments, and the
answer position of a judgment's own head. Non-tail recursion becomes one
line per case:

```
demand (fib int) int
rule (fib n n) <-- (< n 2)
rule (fib n (+ (fib (- n 1)) (fib (- n 2)))) <-- (< 1 n)

demand (ack int int) int
facts (ack 0 n (+ n 1))
rule (ack m 0 (ack (- m 1) 1)) <-- (< 0 m)
rule (ack m n (ack (- m 1) (ack m (- n 1)))) <-- (< 0 m) (< 0 n)
```

Memoization is interning: each distinct demand is one fact, computed
once, shared by every asker. Base cases of judgments are naturally facts
with pattern variables — the gate binds them: `facts (map2 f (nil) (nil))`.

## 4. Lambdas and first-class calls

A form whose head is a **bound variable** rather than a declared name is
a first-class value being invoked. Nested, `(g x)` denotes the answer;
as a whole clause, `(g x r)` reads judgment-style (last argument the
answer). Both dispatch to a synthesized global judgment per call arity:

```
demand (applyN clo any ... any) any      -- synthesized on first use
```

with `clo` a synthesized union of closure constructors. This is untyped
defunctionalization — `any` columns, one apply per arity, no annotations
(typed per-arrow applies remain expressible by hand, as in
`tests/dem_map.slog`, and would be the target of a future typed-lambda
design). Users can extend `clo` with their own constructors (union
declarations merge) and add their own `applyN` rules for hand-rolled
closures.

`(lambda (x ...) body)` — when `lambda` is not itself a declared relation,
which keeps object languages like tinycfa's intact — lifts to a closure
constructor capturing the body's free variables (a struct, or an enum
constant when nothing is captured), joins `clo`, and generates one
answering rule `(applyN (lamK captured...) x... body)`. The body is a
term: calls, primitives, constructors, and further lambdas compose inside
it. Closure names come from the source position (file-hash x line x
column), so they are deterministic. Closures are ordinary interned
values: they sit in data structures, return from judgments, and print in
query results.

```
demand (map2 clo list) list
facts (map2 f (nil) (nil))
facts (map2 f (cons x xs) (cons (f x) (map2 f xs)))

demand (compose clo clo) clo
facts (compose f g (lambda (x) (f (g x))))

rule (kv k) (input l) (= r (map2 (lambda (n) (* n k)) l)) --> (scaled r)
```

`map2` is two facts. (`tests/dem_lambda.slog`, verified end-to-end.)

One type-system accommodation was needed: the polymorphic-primitive link
check now resolves `any`-vs-concrete to the concrete side (matching
`type-match?`'s existing treatment of `any`), so `(+ n 1)` typechecks
when `n` flows from an `any` column.

## 5. The transform (`compiler/demand.rkt`)

Runs after module resolution (declarations known, arrows normalized),
before simplification; output is plain slog and no later pass knows
demands exist. Four phases per program:

- **V. var calls** — bound-variable heads dispatch to `applyN`
  (synthesizing it on first use).
- **L. lambdas** — lift to closure constructions plus generated apply
  rules; generated rules go back through the transform (their judgment
  heads need gates).
- **C. calls** — nested demand-arity occurrences (and `(= x (f a...))`
  bindings) extract to fresh variables plus full-arity body occurrences.
  Only single-answer judgments may be called.
- **MAIN** — judgment occurrences: a head occurrence gets a body gate
  `(= d (f in...))` and becomes `(f_ans d out...)`; a body occurrence
  gets an ask rule plus an in-place resume join
  `(= d (f in...)) (f_ans d out...)`.

Ask scheduling is a groundness fixpoint in stages: non-judgment clauses
run as soon as their inputs are ground; every body judgment whose demand
arguments are ground asks, with all clauses scheduled so far as its rule
body (the most restrictive prefix available, minimizing spurious
demands); its answers extend the ground set. Judgments ready in the same
stage ask in parallel — the paper's nonblocking-`!`, recovered as a
scheduling fact. A demand argument that can never ground is a **mode
error** naming the unbound variables.

Deliberate behaviors:

- **Resume by replay.** Live variables are recovered from the demand
  structs by content (interning makes reconstruction a lookup), so no
  continuation relation is generated; suspended state is first-class and
  queryable. Factoring shared prefixes through continuation structs is a
  future planner optimization.
- **Self-ask elision** (the left-recursion case): an ask identical to one
  of the rule's own gates is dropped; static unification later collapses
  the equal-content matches.
- **Joint gating.** A multi-head rule keeps one body; all gates live
  there (gates can bind variables other heads use). Write separate rules
  for independently-derivable conclusions.
- **`|` alternatives split first**, so each alternative grounds its own
  variables — and a call inside one alternative does not constrain the
  others.
- **Determinism.** The transform runs before the `.so` cache key is
  computed over module rules (`program->jobs`), so it uses no gensym:
  demand-id and call variables are `_d0/_v0, ...` with deterministic
  prefix extension on collision; closure names come from source
  positions. Rules the transform does not touch pass through
  byte-identical.

Errors: wrong arity; full-arity value position; a judgment occurrence
bound to an id; wildcards in a body occurrence's demand arguments;
`&`/`|`/`=` inside judgment occurrences; multi-answer judgments called in
value position; nullary clause-position closure calls; unmoded
(ungroundable) asks.

## 6. Showcases (all verified end-to-end)

**A grammar is a parser** (`tests/dem_parse.slog`): grammar rules written
naively yield an Earley-style algorithm — the demand relation comes out
as exactly the reachable prediction set, completions flow back as
answers, left recursion is a fixpoint, and only demanded positions are
explored. `tests/dem_sppf.slog` adds a tree answer column to an
ambiguous grammar: multiple answers per demand, and interning shares
subtrees — a packed parse forest with parse failure as plain absence.

**Natural deduction** (`tests/dem_stlc.slog`): an STLC checker whose
rules are the textbook inference rules —

```
demand (ck tenv tm) ty
facts (ck env (num i) (tint))
facts (ck env (var x) (lookup env x))
facts (ck env (lam x t1 e) (arrow t1 (ck (ext env x t1) e)))
rule (ck env (app e1 e2) t2) <-- (ck env e1 (arrow t1 t2)) (ck env e2 t1)
```

T-Var and T-Abs are single facts with calls in answer position; T-App
destructures one answer and equality-joins the other. The full
derivation tree is queryable in `ck_ans`; the ill-typed program simply
has no row.

**0CFA in five rules** (`examples/tinycfa/0cfa-demand.slog`): the
demand-driven rewrite of `0cfa.slog` needs none of the hand-built
machinery — no `ar`/`fn` continuation structs, no `kaddr`/`kstore`, no
eval/ret protocol — and its `result` and `store` relations come out
**identical** to the original's goldens on the shared test program
(which diverges concretely; the analysis terminates because finitely
many demands are reachable):

```
demand (eval expr) val
facts (eval (lambda x eb) (lambda x eb))
rule (eval (ref x) v) <-- (store x v)
rule (eval (app ef ea) v) <-- (eval ef (lambda x eb)) (eval ea va) (eval eb v)
rule (eval (app ef ea)) (eval ef (lambda x eb)) (eval ea va) --> (store x va)
rule (program e) --> (eval e)
```

Note the store rule: a bare-arity *enumeration* of demands drives a side
effect that must land before the body can answer — the escape-hatch
readings compose with judgments.

**Higher-order, memoized, classic** — `dem_lambda` (map over closures,
compose returning a lambda), `dem_fib`/`dem_value` (one-rule fib),
`dem_ack` (Ackermann: a call nested in another call's demand argument
chains the asks; ack(3,3)=61), `dem_map` (hand-typed defunctionalization,
the contrast to the synthesized untyped apply).

## 7. Semantics, caveats, future work

- **Stratification.** A judgment's struct and answer table are mutually
  recursive with their callers' asks and resumes; SCCs group
  mutually-calling judgments into one stratum.
- **Termination.** Interning = memoization: evaluation terminates iff
  finitely many demands are reachable. Abstract the value domain
  (CFA-style) for guaranteed termination of interpreters.
- **Ask tightness.** An ask's prefix is every clause groundable at that
  stage — asks over-approximate (fire at least whenever the rule could
  complete), never produce wrong facts, and keep the asymptotics.
  Tightening via planner-chosen prefixes or continuation-struct factoring
  is future work.
- **Incrementality.** Demands, answers, closures, and suspended state are
  ordinary facts; DRed^c (docs/incremental.md) will apply uniformly —
  e.g. incremental reparsing after a token edit.
- **Future**: typed lambdas / per-arrow applies (needs type-directed
  desugaring or annotations); zero-answer checking judgments (needs a
  design for the bare/full arity collision); exhaustiveness checking of
  demand patterns against union scrutinees; demand-argument subsumption.

## 8. Implementation map

- `compiler/parser.rkt` — `demand` top-level form.
- `compiler/modules.rkt` — declaration extraction (backing struct +
  `_ans` table), per-program demand-registry merge, transform invocation
  after env merging, and merging of transform-synthesized declarations
  (closure structs/enums, `clo` union, `applyN` backing relations) with
  the usual conflict checking.
- `compiler/demand.rkt` — phases V/L/C/MAIN, validation, groundness
  scheduling; unit tests in the test submodule.
- `compiler/simplification.rkt` — `split-or-clauses` lifted and exported.
- `compiler/type-system.rkt` — polymorphic-primitive links resolve
  `any`-vs-concrete to the concrete side.
- Everything from simplification down is untouched.
- Tests: `dem_chain`, `dem_fib`, `dem_parse`, `dem_sppf`, `dem_map`,
  `dem_multi`, `dem_escape`, `dem_enum`, `dem_multihead`, `dem_or`,
  `dem_value`, `dem_ack`, `dem_lambda`, `dem_stlc`, and
  `examples/tinycfa/0cfa-demand.slog` (in the default suite).
