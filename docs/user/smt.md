# SMT library

`lib/smt.slog` represents solver formulas as ordinary Slog values and exposes
three demand queries:

- `smt_check` returns `sat`, `unsat`, or `unknown`.
- `smt_model` also returns one satisfying assignment when the formula is sat.
- `smt_core` also returns an unsat core when the formula is unsat.

The daemon can use Z3, cvc5, a timed fallback chain, or a deterministic
built-in evaluator for ground formulas. Answers become ordinary facts and are
memoized and persisted with the database.

## Include the library

Put the include before declarations and rules:

```slog
include "smt.slog"
```

The module loader falls back to the repository `lib/` directory, so this works
from a source file anywhere in the project tree.

No external solver is required for the default configuration. The default
`mock` backend decides supported ground formulas and returns `unknown` for
symbolic ones.

## Formula vocabulary

SMT integer expressions have type `iexpr`:

| Constructor | Meaning |
|---|---|
| `(iv Name)` | integer variable named by string `Name` |
| `(ic N)` | integer constant |
| `(ladd A B)` | `A + B` |
| `(lsub A B)` | `A - B` |
| `(lmul A B)` | `A * B` |
| `(lite C Then Else)` | integer if-then-else controlled by formula `C` |

Boolean formulas have type `formula`:

| Constructor | Meaning |
|---|---|
| `(bv Name)` | Boolean variable named by string `Name` |
| `(ltrue)` | true |
| `(lfalse)` | false |
| `(llt A B)` | integer `<` |
| `(lle A B)` | integer `<=` |
| `(lgt A B)` | integer `>` |
| `(lge A B)` | integer `>=` |
| `(leq A B)` | integer equality |
| `(lne A B)` | integer disequality |
| `(land P Q)` | conjunction |
| `(lor P Q)` | disjunction |
| `(lnot P)` | negation |
| `(limplies P Q)` | implication |
| `(lall S)` | conjunction of the formulas in native set `S` |
| `(lany S)` | disjunction of the formulas in native set `S` |

The serializer selects SMT-LIB logic `QF_LIA` unless it sees a multiplication
of two nonconstant terms, in which case it selects `QF_NIA`. Multiplication by
a constant stays in linear integer arithmetic. Nonlinear formulas depend more
heavily on solver capability and timeout.

The formula language has integers and Booleans only. There are currently no
real, bit-vector, array, quantifier, or uninterpreted-function constructors.

`(lall (cmap))` is true and `(lany (cmap))` is false. Formula sets must be
native `cset` values whose members are formulas. Their canonicity makes a path
condition independent of accumulation order.

## Check satisfiability

The verdict type is an enum:

```slog
enum (verdict sat unsat unknown)
```

Call `smt_check` in value position:

```slog
include "smt.slog"

table (probe str verdict)

rule (= V (smt_check (land (llt (iv "x") (ic 3))
                           (lgt (iv "x") (ic 5)))))
  --> (probe "contradiction" V)
```

With Z3 or cvc5, the result is `(unsat)`. With the default mock backend it is
`(unknown)` because the formula has a variable.

The most useful pattern matches only a proof you can act on:

```slog
table (error_path str formula)
table (check_elidable str)

rule (error_path Site F)
     (= (unsat) (smt_check F))
  --> (check_elidable Site)
```

If the solver times out, crashes, rejects the query, or returns unknown, this
rule does not fire. The conservative result is to keep the dynamic check.

Likewise, match `(sat)` only when a satisfiability witness is enough for the
conclusion. Do not treat `unknown` as either sat or unsat.

## Build canonical path conditions

Nested conjunctions depend on construction order:

```slog
(land A (land B C))
(land C (land A B))
```

They mean the same thing but are different Slog values and therefore different
memoization keys. A native set removes order and duplicates:

```slog
lattice (formulas (set formula))
table (path_condition str formulas)

rule (entry Block) (= Empty (cmap)) --> (path_condition Block Empty)

rule (path_condition From S) (guard From To G)
     (= S2 (cins S G))
  --> (path_condition To S2)

table (feasible str)
rule (path_condition Block S)
     (= (sat) (smt_check (lall S)))
  --> (feasible Block)
```

The set lattice unions all proposed guards for a block. Whether union is the
right path abstraction depends on the analysis: joining path alternatives
usually needs disjunction or separate path states, not simply putting every
guard in one conjunction. The point is that one semantic conjunction should
have one canonical set value.

## Models

`smt_model` has two answer columns, so use its full relational form:

```slog
table (model_value str verdict cmap)

rule (smt_model (land (lge (iv "x") (ic 5))
                      (lle (iv "x") (ic 5)))
                V M)
  --> (model_value "x-is-five" V M)
```

When the verdict is `(sat)`, `M` maps original variable-name strings to one
satisfying value:

- integer variables map to Slog integers, including bignums;
- Boolean variables map to integer `1` or `0`.

Use ordinary map operations:

```slog
table (x_value int)
rule (smt_model F (sat) M)
     (= 1 (chas M "x"))
     (= X (cget M "x"))
  --> (x_value X)
```

The map is empty for unsat or unknown. A variable-free sat formula also has an
empty model because there is nothing to assign.

A satisfying model is generally not unique. The chosen values can change
with solver, version, seed, or query encoding. Use a model as a witness, not as
a canonical result. If integer and Boolean variables reuse the same original
name, their map keys collide; give variables unique names across sorts when
requesting models.

The mock backend returns an empty model for a ground sat formula and unknown
for symbolic formulas.

## Unsat cores

`smt_core` also uses full relational form:

```slog
table (core_result verdict cset)

rule (= S {(llt (iv "x") (ic 3))
           (lgt (iv "x") (ic 5))
           (bv "p")})
     (smt_core (lall S) V Core)
  --> (core_result V Core)
```

On `(unsat)`, `Core` is a subset of `S` that the solver reports as jointly
unsatisfiable. On sat or unknown it is empty. For a root that is not `lall`, an
unsat core is the singleton set containing that root.

Solver cores are sound but need not be minimal. Different solvers may blame
different valid subsets. The mock backend blames each ground-false conjunct;
it is intended for deterministic tests rather than minimal explanations.

Membership uses `cmem`:

```slog
rule (smt_core (lall S) (unsat) Core)
     (= 1 (cmem Core ImportantClause))
  --> (clause_was_used ImportantClause)
```

## Post-hoc verdict views

The library defines these tables:

```slog
table (smt_sat formula)
table (smt_unsat formula)
table (smt_unknown formula)
```

They enumerate formulas that were already answered through `smt_check`:

```slog
rule (smt_unsat F) --> (proved_impossible F)
```

Reading one of these relations does not ask the solver. Some other rule must
call `smt_check F`. This is a direct use of the generated
`smt_check_ans` answer table.

Models and cores do not have equivalent enumeration views in the library; use
their full demand forms or their backing answer relations when necessary.

## Solver configuration

Set `SLOG_SMT_SOLVERS` to a comma-separated chain. Each round has a timeout in
milliseconds:

```console
$ SLOG_SMT_SOLVERS='z3:500,cvc5:2000' racket slog.rkt program.slog
```

The first definitive `sat` or `unsat` answer wins. A timeout, solver `unknown`,
process failure, or malformed response falls through to the next round. If the
chain is exhausted, the verdict is unknown.

Use `|` to race solvers in one round:

```console
$ SLOG_SMT_SOLVERS='z3|cvc5:500,z3:5000' racket slog.rkt program.slog
```

This races Z3 and cvc5 for 500 ms, then gives Z3 a five-second fallback. The
default timeout for an entry without `:milliseconds` is 2000 ms.

The recognized persistent-process command lines are:

- `z3 -in -smt2`
- `cvc5 --lang smt2 --incremental`

An entry may also be a path ending in `z3` or `cvc5`. Other command names use
the generic one-shot path.

Set the oracle worker pool with `SLOG_ORACLE_PROCS`; the default is 4 and zero
is normalized to 1:

```console
$ SLOG_ORACLE_PROCS=8 SLOG_SMT_SOLVERS='z3:1000' \
    racket slog.rkt program.slog
```

The same settings can come from local Slog configuration:

```slog
include "default-config.slog"
rule (override_str "smt_solvers" "z3:500,cvc5:2000")
rule (override_int "oracle_procs" 4)
```

See [running Slog](running.md#configuration) for config precedence.

## The mock backend

Use the built-in backend explicitly with:

```console
$ SLOG_SMT_SOLVERS=mock racket slog.rkt program.slog
```

It evaluates supported ground formulas in-process and deterministically.
Variables, bignums outside its small evaluator, and unsupported evaluation
cases produce unknown. It is useful for:

- testing formula construction and demand flow without installing a solver;
- golden tests whose answers must not depend on process timing;
- constant conditions that can be decided directly.

It is not a symbolic solver. A formula such as `(llt (iv "x") (ic 3))` is
unknown under mock even though it is plainly satisfiable to a human.

## Errors

The library is statically typed, but `any`, raw collections, or malformed
persisted data can still reach the serializer. A bad formula produces both:

- an `(unknown)`-shaped answer for the requested query;
- an `(error (smt_bad_formula Reason Formula))` fact.

You can react in-language:

```slog
table (bad_formula str any)
rule (error (smt_bad_formula Reason F)) --> (bad_formula Reason F)
```

Examples of serialization errors include a non-formula member in `lall`, an
unknown constructor that arrived through `any`, or a sort mismatch in a term.
The daemon warns once per distinct serialization reason as well.

A solver timeout or a normal solver `unknown` is not a malformed formula and
does not produce `smt_bad_formula`.

## Memoization and persistence

An SMT request is an external demand. Each distinct requested formula has one
recorded answer in a database lineage. Repeating the call in another rule or
stratum reuses the answer.

Exact database saves keep the answer relations. Compressed saves pin oracle
answers and `smt_bad_formula` values instead of sampling them, because replay
must not ask a different solver and silently change a result. Loading a saved
lineage therefore reuses recorded sat, unsat, unknown, model, and core answers.

This gives stable replay, not universal solver reproducibility. In particular:

- An unknown answer is not automatically upgraded when a later run has a
  stronger solver policy.
- Model and core choices remain the values selected when the answer was first
  recorded.
- Moving facts into an unrelated database does not create a cross-database
  solver cache.

When current solver behavior is the subject of an experiment, run from a
fresh database rather than assuming old recorded answers will refresh.

## Cost and fixpoint behavior

Oracle dispatch scans newly demanded formulas. Serialization happens on a
normal stratum worker, then solver work runs in a separate pool. Completed
answers are harvested as ordinary answer-table facts.

A stratum cannot declare fixpoint while oracle work is outstanding. It can
continue independent rule evaluation while solvers run, then waits for a
completion when only oracle work remains. Run time and memory budgets still
apply to the surrounding execution.

Keep formulas canonical and avoid asking speculative queries that no result
uses. `lall` over canonical sets, named demand boundaries, and `--sizes` on
`smt_qsat`, `smt_check_ans`, and related generated relations help explain query
volume.
