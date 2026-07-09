# Bug: `stage-rule` infinite-loops on circular head lets/constructions

Status: **open** (diagnosed 2026-07-08, not yet fixed)

## Symptom

`raco test tests/unit/` hangs. The offending file is
`tests/unit/planner-tests.rkt`, specifically test case 7,
**"circular head lets raise"** (lines 211-216). The whole suite wedges
there because `check-exn` never returns.

An instrumented copy, `tests/unit/planner-probe.rkt` (untracked, adds a
`displayln` banner before each case), prints banners through test 7 but
never reaches test 8 — confirming the hang is inside test 7's body, which
only calls `plan-stratum` on this rule:

```racket
(R (list (S 'e7 'x))
   (list (S 'let 'a (S '+ 'b 'x))     ; a = b + x
         (S 'let 'b (S '+ 'a 'x))     ; b = a + x   <- mutually recursive
         (S 'out7 'a 'b)))
```

The test asserts `(check-exn #rx"circular" ...)`, i.e. it expects
`plan-stratum` to *raise* a circular-dependency error. Instead it loops
forever. **The test's expectation is correct; the compiler has the bug.**

## Root cause

The infinite loop is in `compiler/join-planning.rkt`, `stage-rule`
(lines 124-201) — it is deterministic and unrelated to any concurrent
filesystem activity in the directory.

`stage-rule` peels off head clauses that are `immediate?` (their inputs do
not depend on a fresh id this rule produces, `new-ids`) and recurses on the
`residual`. For the two mutually-recursive head lets:

- `new-ids = {a, b}` (both let outputs — `compute-cl?` clauses count as
  constructions for staging; `construction-id` = the let's output var).
- `(let a (+ b x))`: `head-in-vars = {b, x}` ∩ `new-ids` = `{b}` → residual.
- `(let b (+ a x))`: `head-in-vars = {a, x}` ∩ `new-ids` = `{a}` → residual.

So `immediate` is empty and `residual` is the whole head. `immediate?`
depends only on the heads, and the follow-up rule keeps the same heads
(`residual`), just carrying `x` forward through a **fresh temp** each pass
(`temp -> temp2 -> temp3 -> ...`). `residual` never shrinks → unbounded
recursion. Control never reaches `schedule-body`.

## Why the body case works but the head case doesn't

Circular *body* lets are caught by `schedule-body`'s cycle detector
(join-planning.rkt ~line 443), which raises `"circular let dependencies"`.
This is exactly test case 6 ("circular body lets raise"), which passes.

Head lets are staged by `stage-rule`, which runs *before*
`plan-rule-versions`/`schedule-body`. A head-let cycle makes `stage-rule`
diverge before the body scheduler ever sees the clauses, so the existing
detector never fires.

Empirical confirmation (isolated repro under a watchdog):

```
test7 (circular head lets) => HANG (no result in 8s)
test8 (already-ground let) => TERMINATED ok
test6 (circular body lets) => RAISED: plan-stratum: circular let dependencies ...
```

## Impact

A user who writes mutually-recursive head lets or mutually-referential
head constructions (deliberately, or via a typo) hangs the compiler
instead of getting the "circular" error the analogous body case already
produces. Low-frequency in practice, but it wedges `raco test tests/unit/`
today and is a bad failure mode (silent hang vs. clear error).

## Suggested fix

In `stage-rule`'s `else` branch (around line 149), detect non-progress
before recursing: if `immediate` is empty while `residual` is non-empty,
no progress can ever be made (the follow-up would have identical heads), so
raise an error whose message contains "circular" — mirroring
`schedule-body`'s message and satisfying test 7's `#rx"circular"`.

That condition is a sound *and* complete non-progress detector: `immediate`
empty ⟺ every head clause depends on a fresh id ⟺ a dependency cycle among
head constructions/computes, and it guarantees the next recursion is
identical.

## Pointers

- Bug: `compiler/join-planning.rkt`, `stage-rule` lines 124-201 (peel/recurse),
  fix around line 149.
- Working detector to mirror: `schedule-body` ~line 443.
- Test that documents intended behavior: `tests/unit/planner-tests.rkt`
  test 7, lines 211-216.
- Bisection aid: `tests/unit/planner-probe.rkt` (untracked, per-case banners).
