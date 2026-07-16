# BUG: daemon dies (EOF mid-stratum) on `car`/`cdr` over a quoted datum or opaque value

> **RESOLVED 2026-07-11 — the root cause is a codegen name-mangling bug, and it
> is program-INDEPENDENT; the `car`/shape/quoted-`Datum` narrowing below was a
> red herring.** `canonicalize-vrefs` (`compiler/emit-cpp.rkt`) textually renames
> every `v_<name>` token to a per-TU `v_c<k>` (for reproducible, content-hashable
> translation units). Its regex `\bv_[A-Za-z0-9_]+` also matched **relation-name
> string literals** beginning with `v_` — here `prims.slog`'s `v_nil` / `v_pair` /
> `v_maybelist` tables — and the numbering restarts per TU. When a stratum is big
> enough to SPLIT into multiple TUs (> `chunk-size` = 48 crules; the reach/step
> SCC), the spine TU `addRelation`'d the relation under one `v_cN` name while a
> cluster TU `getRelation`'d it under a different one. `getRelation` returns null
> for the unknown name (`database.h`), and `null->getIndex(...)` segfaults in
> `ReadTask::bind` at stratum load — the "EOF mid-stratum" the client sees. The
> crash is at load time, before any rule fires, so it cannot depend on the
> argument's shape.
>
> **On the shape-dependence observed below:** the true trigger is "the stratum
> splits AND references a `v_`-prefixed relation." Because the demand transform
> prunes rules a given program can't reach, the argument's shape changes which
> `prims.slog` rules survive into the reach SCC, hence its crule count, hence
> whether it crosses the 48-crule split threshold. That is why it *looked* like a
> quoted-`Datum`-vs-live-`cons` distinction. In direct testing on the pre-fix
> tree, `car` of `'()`, of a quoted pair `'(1 2)`, AND of `(cons 1 2)` all crashed
> identically (each split into ≥2 TUs).
>
> **Fix:** `canonicalize-vrefs` now keeps every daemon-registered name
> (relations/structs/lattices/temps, from the cprog `decls` + manifest) verbatim,
> so a `v_`-prefixed name is the same string in every TU. Provably a no-op for
> programs with no `v_`-prefixed name (the regex only matches `v_` tokens, and
> non-`v_` keep entries are never consulted). Regression:
> `tests/split_vprefix.slog` (a 52-relation cycle + a `v_x` table forces the
> split; segfaults if the fix is reverted). After the fix, all three `car`
> variants above run to fixpoint. The narrowing below is the ORIGINAL, superseded
> diagnosis, kept for the record.

*Filed 2026-07-10 from the scheme-slog-compile analysis work; sharpened after
narrowing. Reproduced on the pb build, `SLOG_OPT=0`. The daemon CRASHES (does
not error gracefully) on a valid, well-typed program — including a SAFE
operation that should simply return a value — so this is a slog toolchain
robustness bug, not a user-program error.*

**Narrowed trigger:** the shape analysis's `car`/`cdr` rules crash the daemon
whenever their argument's shape comes from a **quoted `Datum`** (`(Quote _
(DPair …))` or `(DNil)`) or an **opaque "maybe-list"** — i.e., every `car`/`cdr`
path EXCEPT projecting a freshly-`cons`'d live `Pair`. It is **not** about
safety (`(car '(1 2))` is a valid car that should return `1`, and crashes) and
**not** about scale (a 2-element quoted list crashes exactly like a 400-element
one). The one `car` program that does NOT crash cars a live `(cons …)` Pair.

## Symptom

```
Slog execution failed: daemon output ended (EOF) mid-stratum -- the daemon died or went silent
```

Exit code 2. It happens AFTER `(fixpoint 0 ...)` completes, while running the
next stratum (the large recursive `reach`/`step` SCC of the analysis): the log
shows the stratum's `<hash>.O0.so` line and then the daemon goes silent — no
`(fixpoint 1 ...)` line, no error from the daemon, just EOF. The daemon
**recovers between runs** (a subsequent, unrelated program compiles and runs
fine), so it is a per-computation crash (likely a segfault/abort in the compiled
stratum), not persistent state corruption.

## Minimal reproduction

The analysis lives in `~/scheme-slog-compile` (interp.slog / prims.slog — a
small-step abstract interpreter with a cons/car/cdr shape domain). The sharpest
minimal repro is a **safe** car of a quoted pair — it should return `1`:

Source (`qpair.ss`):
```scheme
(display (car (quote (1 2))))
```

Extracted + analyzed (`car` of a quoted `DPair`):
```
;; qpair_ana.slog
include "/home/tom/scheme-slog-compile/prims.slog"
rule (program
 (App (Pr "qpair.ss" 1 1 1 29) (Prim (NoPr) 2 "display")
   [(App (Pr "qpair.ss" 1 10 1 28) (Prim (NoPr) 2 "car")
      [(Quote (NoPr) (DPair (DInt 1) (DPair (DInt 2) (DNil))))])]))
```
```
cd ~/slog && SLOG_OPT=0 racket compiler/run.rkt --debug-dir /tmp/out qpair_ana.slog
```
→ crashes as above (EOF mid-stratum, after fixpoint 0).

Confirmed variants, all crashing identically: `(car (quote ()))` (quoted `DNil`),
`(car (cdr (read)))` (opaque maybe-list), and a 400-element quoted list. The
**only** `car` that does NOT crash is a live cons: `(car (cons 1 2))`. So the
trigger is `car`/`cdr` over a quoted-datum or maybe-list shape, independent of
safety or size.

## What the analysis is doing at that point (likely-relevant context)

The distinguishing feature of the crashing `car`/`cdr` rules (vs the safe
live-`Pair` one, which returns a `CarAddr`/`CdrAddr` address) is that they
**match against, and/or construct, a quoted `Datum`**. The safe live case:

```
rule (step (Appl e fd [p] ctx k) (Ret k [(CarAddr cs cc)])) <-- (lookup fd (PrimOp "car")) (lookup p (Pair cs cc))
```
never crashes. The quoted-datum projection, which crashes even for a valid pair:
```
rule (step (Appl e fd [p] ctx k) (Ret k [(construct (Constant (Quote (NoPr) da)))]))
 <-- (lookup fd (PrimOp "car")) (lookup p (Constant (Quote _ (DPair da dd))))
```
and the maybe-list case (constructs a `PrimResult`) also crashes. All of the
crashing paths run inside the big recursive `reach` SCC, which carries
**sequence columns** (the `[D]` argument lists — the run emits the usual
"relation … carries a sequence column and grows recursively" warnings) and a
`(count)` lattice (`car_shape`). The crash is in the compiled stratum (C++ side)
and needs maintainer investigation there — likely in how a `(Quote _ Datum)`
sub-term (or the empty-sequence `[]`) is handled during the reach fixpoint. A
minimal *standalone* slog repro (without the analysis files) has not yet been
distilled — the trigger is entangled with the reach-SCC + quoted-`Datum` +
sequence-column combination above; the `qpair.ss` case is the smallest so far.

## Impact

Blocks the shape-safety analysis on essentially all realistic list-processing
code: any program that `car`/`cdr`s a quoted list or an opaque list (i.e. almost
everything except code that only touches freshly-`cons`'d cells) crashes the
daemon. With the freeze fix landed, this is now the #1 blocker for running the
analysis on real programs (e.g. the Sudoku solver freezes fine, then dies here). The
analysis logic itself is fine — it is the daemon that dies.

## Suggested triage

Run the minimal repro under a debug daemon build (asserts on, ASan if available)
to catch where it dies in the reach-SCC stratum — suspects, in order: (1)
occurrence/sequence indexing on the empty-sequence (`DNil` / `[]`) argument;
(2) a stuck-state interaction in the reach fixpoint; (3) the `(count)` lattice
merge feeding off a stuck state.
