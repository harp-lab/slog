# Residual dynamic type checks

*(2026-07-05; implemented in type-system.rkt "Residual dynamic type
checks", lowered by operationalization.rkt to `(tycheck ...)` head ops,
emitted by emit-cpp.rkt as tag-test guards ahead of a rule's sinks; the
`malformed_deduction` struct and `error` table are builtins seeded in
modules.rkt; the per-stratum wrap rule is injected in compile.rkt.)*

## 1. The problem

The type checker is static and deliberately permissive in exactly two
places (`type-match?`):

- **`any` is an escape hatch in both directions.**  A variable bound from
  an `any`-typed column passes into any concretely-typed column.
- **Union overlap suffices.**  A variable whose inferred type *intersects*
  the column's accepted set passes.  With `union (val lam)` and
  `union (expr lam app ref)`, an `expr`-typed variable flows into a `val`
  column because `lam` is common to both — but at runtime the value may be
  an `app`.

Both cases used to write the wrong-typed value into the column silently.
Rejecting them statically would be wrong too: the program may be perfectly
type-safe along every path that actually fires (this is the usual cost of
a subtyping-free surface type system meeting union types and `any`).

## 2. What we do: residualize the check into the compiled rule

At head-clause checking, when the emitted variable's ground member set is
**not a subset** of the column's (i.e. the static pass was only by `any`
or partial overlap), the type checker attaches a residual check to the
rule — a new head-position clause placed before the emissions:

    (tycheck y (accept t ...) rid rel col)

`rid`/`rel`/`col` are const-bound reporting variables: the rule's source
location as a string (`"file.slog:12"` -- basename and 1-based line, so
error facts don't vary with the checkout location), the target relation's
name, and the 0-based column.  The accepted types are the column's ground
members (unions expanded); operationalization lowers them to what a
runtime tag test can name — `int`/`float`/`str`, or an interned struct's
id (`is_struct(v) && decode_struct_id(v) == sid`, looked up once at task
construction).  Codegen renders the check as a guard ahead of **every**
sink of the rule:

    if (!(is_struct(v_e) && decode_struct_id(v_e) == sid_lam))
    {
      slog::emit_struct<5>(err_rel, err_batch,
          {v_rid, v_rel, v_col, v_e}, /*master ord*/ {1,2,3,4,0});
      return;   // abandon the deduction; no head fires
    }

A failing check **kills the whole deduction** (all heads of the rule for
that binding) and interns a

    (malformed_deduction rid rel col badval)     -- struct str str int any

in its place.  Struct interning dedups by content, so a hot rule failing
the same way a million times yields one row.  Checks run at the *end* of
the body, after every join and guard — a value that a later clause would
have rejected anyway is never reported (no false positives from partial
bindings).

Provably-safe emissions — the common case — get no check and no cost.
Constructed ids never need one (their type is the exact struct name).

## 3. The error table

Every stratum whose rules carry checks also receives a synthesized rule

    rule (= e (malformed_deduction r s c v)) --> (error e)

with `error` a builtin `(table any)`.  `malformed_deduction` is marked
dynamic in that stratum, so the wrap rule is delta-driven *within the same
fixpoint*: an `(error e)` fact appears one iteration after the failing
deduction.  This is the client-facing surface — a frontend can watch
`error` and warn, or kill the run, while the fixpoint is still going (not
built yet; today the facts are simply in the output database), and user
rules may read `(error e)` to react in-language.

Both names are reserved; declaring them is a compile error.

## 4. Stratification: why the checks are invisible

`stratify.rkt` makes all head relations of a rule mutually dependent (a
rule fires as a unit).  If `malformed_deduction` were a real head of every
checked rule, every checked rule's heads across the program would collapse
into one SCC — one mega-stratum.  So tycheck clauses contribute **no
edges**: the stratifier skips them, and the failure-path write is a side
channel.  This is sound because nothing feeds back — `malformed_deduction`
flows only into `error`, and the wrap rule is injected per stratum, after
stratification.  The daemon needs no cooperation beyond what exists: any
relation's non-empty delta (including `malformed_deduction`'s) already
extends the fixpoint, and the builtins are declared in every stratum so
their write/intern tasks are always in place.

## 4b. Runtime primitive errors (the `error_spec` family)

The head residual check above catches a *type* that flows to the wrong
column.  A second class of error is a **prim that hits bad data** at
runtime — the same escape hatch (`any`, union overlap) plus data-derived
conditions the type system can't see:

| arm | prim(s) | trigger |
|-----|---------|---------|
| `(div_by_zero loc x)`        | `/`                | integer divide by zero |
| `(modulo_by_zero loc x)`     | `%`                | integer modulo by zero |
| `(int_overflow loc x y)`     | `/` `%`            | `INT_MIN / -1` (signed-overflow UB) |
| `(nan_result loc op x)`      | float ops (`sqrt`, `/`, …) | result is NaN (unrepresentable in the NaN-box) |
| `(toint_range loc x)`        | `toint`            | argument is `±inf` / out of s32 range |
| `(type_mismatch loc op x y)` | any arith/cmp/etc. | an `any`-typed operand of the wrong kind |

These, together with `malformed_deduction`, are the arms of a reserved
`union error_spec` (modules.rkt), and all surface through the same
`error` table:

    rule (error (div_by_zero L X))     --> ...     ;; react in-language
    rule (error (nan_result L Op X))   --> ...

**Mechanism.**  A fallible prim no longer `fatal`s the (shared) daemon.
On bad data it records the kind + operands via
`Database::setPendingError` and returns the reserved `slog_error`
sentinel (daemon/types.h).  The generated code checks for the sentinel
right after each prim call/guard and, if seen, calls
`slog::emit_pending_error(db, "file:line")` — which interns the matching
`error_spec` arm (tagged with the rule's basename:line) via the
per-thread `emit_error_struct` path (operators.h) — then abandons the
deduction (`return`, exactly like a failed `tycheck`).  A per-stratum
wrap rule per producible arm (`(= e (arm …)) --> (error e)`,
compile.rkt) lifts it into `error`, delta-driven within the same
fixpoint.  A stratum wires these only if it uses a fallible prim
(`rule-has-fallible-prims?`); a pure-Datalog stratum pays nothing.

Because the arms are content-interned structs, a hot rule failing the
same way a million times yields one row.

**Driver policy (compiler/runslog.rkt).**  The default `compiler/run.rkt` run drives
every stratum to fixpoint and only ever hard-stops on the memory cap (a
`(paused … memory)` becomes a graceful out-of-memory abort); a time/slice
pause just continues.  As each stratum reaches fixpoint the driver dumps the
`error` relation (a read-only `(dump-rel error)` action) and prints a
`WARNING: runtime error surfaced …` line to stdout for every error fact not
seen before (deduped by content across strata, since `error` persists and is
reloaded between strata).  So the default is **warn-and-continue**: errors are
surfaced but never stop the run short of the resource cap.  A program can still
react in-language by reading `(error …)`; a future client can make the policy
configurable (e.g. stop-on-first-error) since the facts are delta-driven and
visible mid-run.

**When a check is added.**  A residual check guards a head emission whose
variable's *inferred* type is not provably a subset of the column's accepted
set (only `any`, or a partial union overlap).  A variable's type comes from its
source — a body relation column, a constant, or a prim result — **not** from the
head column it is emitted into: a head column/field is a sink, so a value
computed as `any`/union and emitted into a concrete column is checked rather
than silently retyped to the column (compiler/type-system.rkt add-to-local
seeds body clauses as sources and skips sink-seeding for head columns).

## 5. Limits (v1)

- **Surface-level only.**  The guard tests the value's tag — primitive
  kind or struct id — not its contents.  A well-tagged struct with a
  malformed field was caught (or diverted) when *it* was interned.
- **`type_mismatch` is coarse.**  It fires from any prim on an
  any-typed operand of the wrong kind; it names the op and operands but
  not the expected type.  `nan_result` reports one representative
  operand (`op`, `x`), not both for a binary op.  Deep struct-render
  overflow and internal-invariant violations (BIN import corruption,
  unknown lattice kind) remain hard `fatal`s — they are bugs/corruption,
  not user data errors, and the render path is outside the fixpoint.
- **Enum members are indistinct.**  All enum constants share the `_enum`
  struct, so a column typed by an enum checks "is some enum constant",
  not which one.
- **Inexpressible column types are skipped.**  A column whose ground
  member set is empty under the tag alphabet (e.g. a `count` lattice
  value column) gets no check rather than an always-failing one.
- **First failure wins.**  A rule with several checks reports the first
  failing column of a binding, then abandons it.
