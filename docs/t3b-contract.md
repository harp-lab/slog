# T3b — selective tier policy

*Drafted 2026-08-09 (W5′, the runtime/transaction arc's carry-in slice).
**Status: slice 1 SHIPPED 2026-08-09; slices 2–4 pending.**  Normative parents:
[execution-tiers.md](execution-tiers.md) §5.3 (rule execution classes), §5.4
(the goals stated as measurables), §5.5 (tier scheduling and CPU allocation),
§11's T3 items 2–3, §12 gates 12/14/15; [t4-contract.md](t4-contract.md)
(whose slice 4 shipped the per-rule emission MECHANISM this contract supplies
the POLICY for); [fast-compile.md](fast-compile.md) §5/§7/§13 (the existing
pool, detached O2 batch, and single-flight claim this must subsume rather
than duplicate).  This document pins the measurement, the slice order, and
the exit gates; the parents stay authoritative for mechanism.*

## 0. What T3b is for

One sentence: **decide which rules are worth compiling, and stop paying clang
for the ones that are not.**

T3a shipped cold start — install and seal the plan, interpret immediately,
attach the artifact when it lands.  What T3a did *not* do is decide anything:
every stratum still emits a full translation unit and still queues a build,
so the only tier question the tree can currently answer is "what does the
cache already hold".  T4 then made the emission unit a kernel and made
coverage per-rule (`SLOG_NATIVE_COVERAGE`), explicitly deferring hotness
policy here.  T3b is that policy.

## 1. The measurement (2026-08-09, warm suite cache)

Over the 499 stratum manifests in a warm `build/` from the golden suite —
2386 planned rules — applying §5.3's default classification exactly as
written (recursive → `tiered`; otherwise ≤1 dynamic relation atom in the body
→ `interp-only`; otherwise `o0-max`):

| class | rules | share |
|---|---|---|
| `interp-only` | 735 | 30.8% |
| `o0-max` | 131 | 5.5% |
| `tiered` | 1520 | 63.7% |

Aggregated to the artifact:

| stratum verdict | count | share |
|---|---|---|
| every rule `interp-only` → **needs no artifact at all** | 247 | **49.5%** |
| holds at least one `tiered` rule | 185 | 37.1% |
| MIXED classes → per-rule emission's payoff set | 181 | 36.3% |

**Half the suite's strata should never invoke clang, and today every one of
them does.**  Measured as generated text those 247 strata are 7.8 MB of 39.4 MB
(19.7%) — they are the small ones, as expected, so the honest claim for slice 1
is *half the compile jobs and a fifth of the C++ text*, not half the compile
time.  The remaining 63.7% of rules are recursive and genuinely want an
artifact; whether a given one arrives before its kernel reaches fixpoint is not
a static question, which is exactly why the profile sidecar (slice 2) is a
separate slice and not a refinement of slice 1.

Reproduce with `tests/tier-classification.sh` (slice 1) over any warm cache.

## 2. What T3b must be true of

1. **Classification is a property of a rule VARIANT, not a stratum.**  §5.3
   designates every `RuleVariantId`; a `once` driver and a delta driver over
   the same source rule can land in different classes.
2. **Coverage stays native ∪ interp-designated, by construction.**  The
   artifact covers a set of kernel rule ordinals; the daemon runs the exact
   complement interpreted.  T4 slice 4's descriptor already carries that set —
   T3b changes only which set is chosen, never how it is communicated.
3. **Plan bytes do not move.**  The canonical plan is a golden of record
   (rf1-contract slice 4).  A tier designation is a compile-time scheduling
   decision, not part of a kernel's semantics: it rides in the `.tiers`
   sidecar and in the descriptor's covered-ordinal list, never in the plan.
   A T3b change that re-records plan goldens is a bug in the change.
4. **Policy is cache-keyed.**  A partial-coverage artifact must never stand in
   for a full one, so the policy identity folds into the job hash exactly as
   `native-rule-coverage` already does.
5. **The default is a default.**  Classification is refined by promotion
   (slice 3) and by the profile sidecar (slice 2); neither may make a
   *semantic* difference, only a scheduling one.  `SLOG_TIER_POLICY=all`
   restores pre-T3b behavior and stays the escape hatch and differential
   control.
6. **Flavored variants keep full coverage.**  `_count`/`_maint*` artifacts are
   the differential's second executor; a partially covered one would compare
   nothing.  (They are interp-only by default already — this is about what
   happens when `SLOG_FLAVORED_NATIVE=1` asks for them.)

## 3. Slices

### Slice 1 — default classification, and strata that need no artifact

`compiler/tier-policy.rkt` classifies each planned rule variant per §5.3 and
feeds T4's `covered?` seam.  Two effects, one policy:

- **within an artifact**, `interp-only` variants are not emitted (the daemon
  interprets them);
- **for the artifact itself**, a stratum whose every variant is `interp-only`
  takes the interp rung directly — no TU, no clang, no `.so`, no upgrade
  closure — which is the 247-stratum result above.

Records `build/<proghash>.tiers` (per-kernel covered ordinals plus each
variant's designation and the reason for it), which slices 2–4 and the REPL's
`tiers`/`code` cards read.

**Exit gate.**  (a) a `tier-classification` battery asserting the designation
of each shape — ground/`once`, seeded, copy/projection/filter, acyclic join,
recursive — with a pre-fix demonstration that the shapes were previously all
covered; (b) an all-interp-only program builds zero `.so` and produces
byte-identical goldens; (c) `plan-determinism` and `plan-goldens` clean — plan
bytes unmoved; (d) one full golden sweep under the classified default.

#### Slice 1 as-built (2026-08-09)

`compiler/tier-policy.rkt` is the whole classifier and the only place the
three classes are decided.  It reads a crule — driver, `pre`, `body` — and
answers with a `(tier, reason)` pair: `runs-once` and `seeded-reentry` are
unconditional (nothing amortizes for a variant that fires once), then
`iterated` (the variant reads a relation its own stratum produces — the same
test `stratum-rule-metas` uses for its `rec` bit, so the manifest's recursion
bit and this classification cannot drift), then `no-join`, then
`acyclic-join`.  Semijoin filters (`exists`/`absent*`) deliberately do not
count as joins: §5.3 lists filter shapes among the interp-only defaults.

Three seams, all narrow:

- **emit-cpp** — T4's `covered?` predicate now calls
  `crule-natively-covered?`.  The even/odd/none knobs still win when set, and
  flavored TUs still pin full coverage; a `tier-summary-sink` parameter
  carries the designations back out without changing `write-cpp`'s return
  type, which several flavor paths share.
- **compile.rkt** — `(tier-policy)` folds into the job hash beside
  `(native-rule-coverage)`, so an artifact built under one policy can never
  stand in for the other; `write-tier-sidecar` records `build/<hash>.tiers`;
  and the emit branch consults `stratum-fully-interpreted?` and takes the
  interp rung when the answer is yes.
- **params.rkt** — `SLOG_TIER_POLICY=classified|all`.  Unset, the policy
  follows §5.3's own scoping: selective under the default tiered regime, off
  under the explicit `-O0`/`-O2` modes, which mean "compile it all" and stay
  a full-coverage differential control.  Set, it is a hard choice in every
  mode — which is what the gate and the golden suite (`SLOG_OPT=0`) use.

Measured on `reach`: the ground-fact stratum went from an artifact to none,
and the closure stratum covers 1 of 2 variants (the base rule
`(path X Y) :- (edge X Y)` is `no-join`, the recursive rule is `tiered`).
Over the targeted battery, 14 of 35 strata built no artifact at all.

**Gates run:** `tier-classification` 10/10 (designations, zero-clang,
`all`-covers-everything, and byte-identical output under both policies);
`tests/unit/tier-policy-tests.rkt` 11/11 (every shape, the knob precedence,
the flavored pin, the `all` pre-fix demonstration); `plan-goldens` 8/8 —
**plan bytes unmoved**, which was the one hard constraint; and 15 targeted
goldens with the policy pinned (reach, structs, lat_sssp, neg_reach,
dem_stlc, sdeep_recnest, n1_instances, n1_symmetric, seq_split,
wcoj3_recursive, strat_mutual, lst_ops, prim2_mixed, stat_selfjoin, hub),
15/15 — including the `$stat_fires` exact-once audit and both n1 sharing
programs.  Gate (d), the full sweep, is not yet run.

**Two residues.**  (i) The `o0-max` class is *classified* but not yet
*honored*: nothing stops an `o0-max` kernel from being queued for O2, because
the queue that would enforce it is slice 4's.  (ii) A stratum that skips the
toolchain still writes its `.cpp` text to `build/` as the debug artifact,
exactly as `SLOG_OPT=interp` leaves it — the emit is cheap and the plan comes
out of the same pass, but it means "no `.so`" rather than "no work".

### Slice 2 — the tier-profile sidecar

A small per-kernel profile keyed by `KernelPlanKey` beside the build cache:
iterations to fixpoint, interpreted ms, native ms, whether O0 arrived before
fixpoint, and the rung actually reached.  Later sessions consult it: kernels
that historically fixpoint before their artifact could attach skip compilation
entirely; known-hot kernels compile eagerly.  The profile is a cache — deleting
it costs rediscovery, never correctness.

**Exit gate.**  §12.12's middle clause: a tiny recursive kernel with a warm
profile sidecar runs zero clang; a warm-cache suite run reports its clang
invocation count and the number trends to zero.

### Slice 3 — promotion budget and next-re-entry pickup

Interpreted slice accounting gives exact per-SCC/per-rule cost.  An
interpreted SCC that exceeds a budget (a small multiple of its estimated O0
compile cost) without reaching fixpoint jumps the compile queue; the artifact
attaches at the next boundary.  Paired with the gap T3a made visible: a
stratum whose fixpoint beat clang currently stays on its starting rung for its
whole maintenance lifetime even though the artifact is sitting in the cache —
re-entry must pick it up.

**Exit gate.**  §12.12's first clause (a pathological interpreted acyclic join
triggers promotion and self-rescues) plus a test that a second re-entry runs
on the artifact built during the first.

### Slice 4 — core-budget arbiter and compile priority queue

One daemon-owned core budget from which interpreter workers, the native
OpenMP team, the compile pool, and oracle backends all draw, subsuming
fast-compile §5's `min(nproc, jobs)` pool rather than adding a second
uncoordinated one.  Compile priority is strict: O0 for the currently executing
SCC (including promotions), then O0 for future SCCs in topological order, then
every O2 job, still under single-flight claims and low OS priority.

**Exit gate.**  §12.14: no oversubscription on ordinary `P ≥ 3` machines, and
priority tests showing current-SCC O0 beating future O0 and all O2 work.
§12.15 stays green throughout: a warm cached O2 pays no interpreter setup
beyond the plan/manifest validation identity already needs.

## 4. What T3b hands the rest of the arc

The runtime/transaction arc's later slices (T0(c), T6, the private activation
spine) need one thing from T3b: **a tier decision that is per kernel and
re-decidable at a boundary.**  RF5-B activation rebuilds a private cone whose
kernels are mostly cold and mostly short-lived — precisely the population that
should never see clang — and T6's restart-under-a-different-executor stress
needs promotion and demotion to be things the daemon can actually be asked to
do.  Slice 3 is the one with a hard dependency in that direction; slices 1, 2,
and 4 are independently valuable and independently gated.
