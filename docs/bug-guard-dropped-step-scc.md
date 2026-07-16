# BUG: rule guards silently dropped for `step`-SCC rules over the occurrence-indexed `Appl` relation

> **Status: FIXED 2026-07-12** in `compiler/demand.rkt` (the demand transform's
> ask scheduler). Both M1 and M2 verified gone end-to-end through the real
> interpreter (`repro_interp2.slog`): `(null? (cons 1 2))` now evaluates to
> `False` with **no** `PrimResult` and **no** `BUG2-FIRED` opaque value. The
> `interp.slog:~300` `/=` workaround has been reverted to the intended
> `(shape_prims sp) (lst_absent sp name 1)` gate, and the M2 blocker on modeling
> 2-argument primitives is lifted. See **Root cause & fix** below.
>
> Found 2026-07-12 from the scheme-slog-compile AAM analysis. Not a crash — a
> *silent precision (soundness-of-approximation) bug*: a rule's head sub-term is
> constructed (with its store side effect) even though the rule's body guard is
> unsatisfied, on valid well-typed programs.

> **⚠️ The original diagnosis below (occurrence-indexed sequence columns) was a
> confound.** The sequence column is *not* required — see **Root cause & fix**.
> The investigation notes are kept verbatim as history.

## Root cause & fix

The trigger is **not** the sequence column, occurrence indexing, or the SCC. It
is the demand transform's **ask scheduler** (`compiler/demand.rkt`,
`schedule-asks`) mishandling a demand-call that sits in a rule **head**, when the
body carries a **demand-moded guard**. A self-contained repro with *no* sequence
column at all reproduces it (`store` ends up holding `777` from a rule that must
never fire):

```
demand (mk int) int
rule (mk v v) (store v)              ;; demanding mk has a STORE side effect
demand (okq int) int
rule (okq n 1) <-- (okt n)           ;; a demand-moded guard
...
rule (step (Ap op k) (Done (mk 777))) <-- (okq op 1)   ;; head builds (mk 777)
```

Chain of events:

1. `extract-calls` lifts the head sub-term `(mk 777)` (interp: `(construct …)`)
   out of the head into a **body judgment occurrence** `(mk 777 _v)`, so its
   answer can flow into the head. It is now indistinguishable from a body query.
2. `schedule-asks` emits an **ask** for every body judgment, scheduled by
   *groundness* and deliberately **over-approximating** (docs/demand.md "Ask
   tightness": asks "fire at least whenever the rule could complete"). The
   `(mk 777)` ask and the `(okq op)` guard ask are both ready at the same stage,
   so they hang off the same supplementary relation **in parallel** — the `mk`
   ask is *not* gated by `okq`'s answer.
3. Over-approximating a demand is sound **only for a pure relation** (extra
   answers no rule reads are invisible). But `construct`/`mk` has a
   side-effecting **co-head** (`(vstore v v)` / `(store v)`): demanding it
   *materialises a value*. So the over-approximation writes the store even when
   the guard fails.

Why a **table** guard (e.g. `(shape_prims sp)`, `/=` checks) gated correctly all
along: a non-judgment clause stays in the ask prefix, so the ask *does* wait for
it. Only **demand-moded** guards were split into a separate ask + resume, and the
resume was absent from the head-call's ask prefix. That asymmetry — table guards
gate, demand guards don't — is the whole bug. (`[p]` "worked" only because the
car/cdr constructs' arguments *data-depend* on their `lookup p` guard, so that
guard was already forced into the ask; the M2 `[ka la]` construct's argument is
ground, so nothing forced the `lookup fd` guard in.)

**The fix.** A head-derived ("output") occurrence — its answer flows only into
the head — must be demanded *exactly when the rule fires*, i.e. gated by every
body guard, never over-approximated. `extract-calls` now returns the set of
head-extracted answer variables; `rewrite-alternative` marks the corresponding
judgments as outputs; and `schedule-asks` **defers** output asks until all guard
judgments are scheduled, so an output rides a prefix that already carries the
guards' resumes. This is deadlock-free: a guard never depends on an output's
answer (it flows only to the head), so a held-back output never blocks a guard.
Genuine body-query occurrences and pure recursive head-calls (e.g. `dem_fib`'s
`(+ (fib …) (fib …))`, gated only by `<` checks) are unaffected — with no
demand-moded guard to wait on, no deferral happens and the emitted rules are
byte-identical.

## Summary

When a rule lives in the recursive `step`/`reach` SCC and matches the `Appl`
state relation — which carries a `[D]` argument list (a **sequence column**) and
"grows recursively (stratum 1) while occurrence indexing is active" (the
compiler's own warning) — a **non-scalar guard on that rule is silently
dropped**. The head then fires on every match of its *head pattern*, regardless
of the guard.

Two manifestations, both reproduced (single self-contained file below):

- **M1 — a `lst_absent` (sequence-column demand) guard is dropped.**
  The generic "unmodeled primitive → opaque result" rule is gated to *skip* the
  shape-primitives with `(shape_prims sp) (lst_absent sp name 1)`. That guard is
  dropped, so `cons`/`null?`/`pair?` each also get a spurious opaque
  `(PrimResult …)` companion value.

- **M2 — a `lookup` guard is dropped when the head matches a 2-element arg-list
  pattern `[ka la]`.**
  A rule `… (Appl e fd [ka la] ctx k) … <-- (lookup fd (PrimOp "assoc")) …` fires
  on *every* 2-argument application, even ones whose operator is a plain closure
  and where no `(PrimOp "assoc")` value exists anywhere.

The single unaffected case is a **fixed 1-element arg pattern** `[p]` (the
`car`/`cdr` rules) — those gate correctly.

## Why it matters

The client is an abstracted-abstract-machine interpreter for Chez `Lsrc`
(`scheme-slog-compile/interp.slog` + `prims.slog`). The dropped guards mean:

- Every `cons`-built list is contaminated with a spurious `maybelist`/opaque
  element, and every `null?` test spuriously forks — the shape analysis loses
  precision it should have (e.g. `(car x)` sites conservatively "unsafe").
- Any attempt to model a 2-argument primitive precisely (`assoc`, `hash-ref`,
  `list-ref`, …) misfires, so 2-arg prims can't be given a richer domain at all.

It is a *precision* bug, not unsoundness in the usual direction (results are
over-approximate), and it is silent — the program runs to fixpoint and returns a
wrong (too-coarse) answer.

## Reproduction — self-contained, through the interpreter

`docs/bug-guard-dropped-repros/repro_interp2.slog` (needs `scheme-slog-compile`'s
`prims.slog`, which chains `interp.slog` → `syntax.slog` → `lib/list.slog`):

```
include "/home/tom/scheme-slog-compile/prims.slog"

;; M2 PROBE: a step-SCC rule matching Appl with a 2-element arg list [ka la] and
;; a lookup guard for the "assoc" primitive.  The program below never calls
;; assoc and no (PrimOp "assoc") value is ever created, so this must NEVER fire.
rule (step (Appl e fd [ka la] ctx k) (Ret k [(construct (Opaque (Pr "BUG2-FIRED" 1 1 1 1)))]))
 <-- (lookup fd (PrimOp "assoc"))

;; Program:  (null? (cons 1 2))   -- null?/cons are shape_prims, handled by
;; prims.slog; NEITHER should yield an opaque (PrimResult ...) value.
rule (program
  (App (Pr "t" 1 1 1 20) (Prim (NoPr) 2 "null?")
    [(App (Pr "t" 1 1 1 15) (Prim (NoPr) 2 "cons")
       [(Quote (NoPr) (DInt 1)) (Quote (NoPr) (DInt 2))])]))
```

Run (with the generic-opaque rule gated by `lst_absent`, i.e. the pre-workaround
`interp.slog:~300`):

```
racket compiler/run.rkt --debug-dir OUT repro_interp2.slog     # SLOG_OPT=0
```

Observed (`OUT/vstore.csv`):

```
BUG 1:  (PrimResult "null?" ...)   x2      <- shape prim, should be 0
        (PrimResult "cons"  ...)   x2      <- shape prim, should be 0
BUG 2:  (Opaque (Pr "BUG2-FIRED" ...))     <- assoc-guarded rule fired, no assoc present
```

Correct output would contain **no** `PrimResult` at all (both prims are modeled
by `prims.slog`) and **no** `BUG2-FIRED` value.

The extraction-based repro `docs/bug-guard-dropped-repros/nulltest.ss`
(`(define (f x) (null? x)) (define (g a b) (cons a b)) (display (f (g 1 2)))`)
shows the same thing end-to-end.

## Key diagnostic — the guard works *downstream* but is dropped *in the SCC*

The guard bodies are correct in isolation; they are dropped only when they gate a
`step`-SCC head over `Appl`.

- **M1.** A debug relation with the generic rule's *exact* body,
  `(reach (Appl _ fd _ _ _)) (lookup fd (PrimOp name)) (shape_prims sp) (lst_absent sp name 1)`,
  answers **only `display`** (the one genuinely-opaque prim) — i.e. downstream,
  `lst_absent` correctly excludes `null?`/`cons`. Yet the step-SCC head produced
  `PrimResult "null?"`/`"cons"`.
- **M2.** As a downstream table rule, `(reach (Appl e fd [ka la] …)) (lookup fd (PrimOp "assoc"))`
  matches **zero** `Appl`s, and no `(PrimOp "assoc")` value exists
  (`dbg_all_primop` = {`display`,`cons`,`null?`}); yet the step-SCC head with the
  same guard produced `PrimResult "assoc"`.
- `lst_absent`/`lmem` are themselves fine: standalone,
  `lst_absent(["cons" … "pair?"], "null?")` correctly has *no* answer and
  `lmem` returns correct counts.

## Ruled out

- **Not stale cache.** Reproduced in a fresh, isolated `build/` (run from a
  scratch dir — `build/` is CWD-relative via `fullpath`=`path->complete-path`;
  seed the dir with the daemon PCH + a `daemon/` symlink so `make -C daemon` is
  skipped).
- **Not a small recursive SCC.** Minimal hand-built repros do **NOT** reproduce
  (they behave correctly): `docs/bug-guard-dropped-repros/repro_absent.slog`
  (a recursive `reach`/`step` with a `lst_absent` guard) and `repro_listpat.slog`
  (a 2-element list-pattern rule with a demand guard). So the trigger needs the
  *full* structure — occurrence indexing active on a large, recursively-growing
  `Appl` relation carrying a sequence column — not merely "recursion + a
  sequence-column guard" or "a 2-element pattern".

## Suspected mechanism

Occurrence indexing on `Appl`'s `[D]` sequence column (stratum 1, per the
`docs/sequences.md §5.3` warning "relation `Appl` carries a sequence column and
grows recursively … while occurrence indexing is active"). The join that should
apply the guard appears to be planned/indexed so that the guard is dropped for
anything other than a fixed single-element arg pattern. Evidence that it is the
*multi-element / non-scalar* aspect, not the guard's truth value:

| rule shape | guard | result |
|---|---|---|
| `Appl … [p] …` (car/cdr, `prims.slog`) | `(lookup fd (PrimOp "car"))` | correct |
| `Appl … argds …` (generic, variable list) | `(lst_absent sp name 1)` | **guard dropped** |
| `Appl … [ka la] …` (assoc model) | `(lookup fd (PrimOp "assoc"))` | **guard dropped** |
| `Appl … argds …` (generic) | scalar `(/= name "cons") …` | correct (workaround) |

## Workaround (M1 only, verified)

Replace the sequence-column `lst_absent` gate with scalar `/=` checks — scalar
builtins are not dropped:

```diff
 rule (step (Appl e=(App prov _ _) fd argds ctx k)
            (Ret k [(construct (PrimResult name prov ctx))]))
- <-- (lookup fd (PrimOp name)) (shape_prims sp) (lst_absent sp name 1)
+ <-- (lookup fd (PrimOp name))
+     (/= name "cons") (/= name "car") (/= name "cdr") (/= name "null?") (/= name "pair?")
```

Verified: spurious `null?`/`cons`/`pair?` `PrimResult`s gone (repro above +
sudoku); genuinely-opaque prims (`+`, `assoc`, `member`, …) still opaque; the
sudoku car-safety verdicts are unchanged (so on that program the spurious opacity
happened not to change the measured cars, but it is removed generally).

**No workaround for M2**: modeling a 2-argument primitive inherently needs a
`[ka la]`-style head, which is exactly what triggers the drop. This blocks giving
`assoc`/`hash-ref`/etc. a precise domain until the compiler bug is fixed.

## Pointers for a fix

- `docs/sequences.md §5.3` (occurrence indexing on recursively-growing sequence
  columns) — the affected relations are `Appl`/`App`/`Ret` etc. in the client's
  `step`/`reach` SCC.
- The unaffected control is the fixed 1-element `[p]` pattern (`prims.slog`
  `car`/`cdr` rules), which suggests the indexing handles the trivial arg-list
  shape but drops guards when the arg list is variable-length or ≥2 elements.
- Repro files: `docs/bug-guard-dropped-repros/` (`repro_interp2.slog`,
  `nulltest.ss`, plus the two non-reproducing minimal attempts `repro_absent.slog`
  / `repro_listpat.slog` that bound the trigger).

*Reproduced on the pb build with `SLOG_OPT=0`. A concurrent `daemon/database.h`
change during testing forced a PCH rebuild (unrelated PCH-staleness) — re-running
after the tree settled reproduces cleanly.*
