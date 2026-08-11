# T3b — selective tier policy

*Drafted 2026-08-09 (W5′, the runtime/transaction arc's carry-in slice).
**Status: T3b IS COMPLETE — all four slices SHIPPED 2026-08-09; §0.1 below is the ledger.**  Normative parents:
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

## 0.1 Completion ledger (2026-08-09)

All four slices shipped in one day on the `w5-runtime` branch; each §3
as-built owns its mechanism.

| slice | commit | exit gate |
|---|---|---|
| (1) default classification + zero-clang strata | d25d730 | `tier-classification` 10/10; plan-goldens 8/8 (bytes unmoved); unit shapes battery |
| (2) tier-profile sidecar | c40c752 | `tier-profile` 5/5 (warm profile + cold artifacts → zero clang, both escape hatches); 12 unit cases |
| (3) promotion + next-re-entry pickup | 4f829b9 | `tier-promotion` 4/4 (§12.12 self-rescue, budget refusal, session rung climb); session 782/782 + protocol 172/172 |
| (4) core-budget arbiter + priority queue | (this commit) | `tier-arbiter` 5/5 (o0-max capped, clang metric zero-on-warm); 7 unit cases (priority/boost, budget arithmetic) |

**Standing residues, all recorded in place:** the daemon's `-t` stays
outside the budget until daemon-side resizing exists (slice 4 as-built);
oracle-backend pools unbudgeted; per-SCC plan streaming untouched; slice
1's full-sweep gate (d) DISCHARGED at the 2026-08-10 arc-end full-suite
run (25/25 effective tiers; golden 168/168 under the classified default); the o0-max cap is
per-artifact, so mixed strata keep their O2 until per-kernel artifacts
(T4 §10's revisit note) make a finer unit.

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

#### Slice 2 as-built (2026-08-09)

`compiler/tier-profile.rkt` owns the store and the rule; the hooks are one
line each.

**The store is keyed by `KernelPlanKey`, and that choice is the slice.**  Job
hashes fold in the compiler-sources fingerprint and daemon headers, so every
compiler or header edit re-keys them and would wipe a hash-keyed profile at
exactly the moment it matters most — the post-edit cold suite run, the one
that costs 65 minutes.  Kernel keys are plan-layer identity: they survive
re-keys and transfer across programs sharing a kernel.  Observed live during
this slice's own development: the smoke fixture's stratum re-keyed
(`41afe073` → `dfd397eb`) under the slice's compiler edits while its kernel
key `74db1a79…` — and therefore its profile — carried straight across.

**Record** (`runslog.rkt`, the `drive-stratum!` fixpoint arm, tiered regime
only): one observation per stratum fixpoint — started rung (`tag`), whether a
better artifact attached mid-run (the poll loop's `loaded > 0`), iterations,
and the daemon-reported fixpoint wall ms — fanned out to every kernel key in
the stratum's `.tiers` sidecar.  `build/profile/<key>.profile`, newest first,
window 8, temp+rename atomic like the rest of the cache.  Explicit
`-O0`/`-O2`/`interp` modes record nothing: there is no race to observe, and
the golden suite (`SLOG_OPT=0`) leaves `build/` byte-stable.

**Consult** (`compile.rkt`, the cold tiered arm only, beside slice 1's
`stratum-fully-interpreted?`): skip the toolchain iff EVERY kernel's latest
interp-STARTED observation says interp sufficed — `upgraded #f` and
`ms ≤ SLOG_TIER_SKIP_MS` (default 2000).  Three deliberate asymmetries in the
rule: warm-native observations are evidence in *neither* direction (a run
that started at `o0` says nothing about whether interp would have been
enough); the *latest* interp observation decides rather than the best (a
stratum that outgrew its ceiling stops skipping at its next re-entry, and one
that shrank recovers); and the conjunction over kernels means one hot shared
kernel keeps every stratum that carries it compiling.  The ms ceiling also
guards the saturated-pool trap: an interp run that won the race only because
the pool was busy still records its true cost, and a slow one never grants a
skip.  Warm-artifact branches are untouched — if a `.so` exists, running it
is free and faster.

**Not cache-keyed, deliberately.**  `SLOG_TIER_PROFILE` and
`SLOG_TIER_SKIP_MS` decide whether builds are *scheduled*, never what is
emitted — TU text, plans, and the job hash are identical either way, so a
profile flip can never serve a wrong artifact, only a present or absent one.

**Gates run:** `tier-profile` 5/5 — the post-re-key scenario end to end
(cold race recorded → artifacts deleted, profile kept → **zero clang, output
byte-identical** → `SLOG_TIER_SKIP_MS=0` rebuilds → `SLOG_TIER_PROFILE=0`
rebuilds), reporting the miniature trends-to-zero metric
(`run1=1 run2=0 run3=1 run4=1` O0 jobs); `tier-profile-tests.rkt` 12/12 (every
rule arm pure, plus the store's fan-out, conjunction, window bound, and kill
switch against a scratch `build/`); full unit suite 442; `tiered-tests` 9/9
(the mechanism battery — recording under tiered mode perturbs neither the
regime differential, the swap drive, nor the O0-reuse/claim tests);
`tier-classification` 10/10; 10 targeted goldens 10/10; api battery at slice
end.

**Residues.**  (i) The suite-wide always-on clang-invocation *report* (§5.4's
"track this as a measured metric") is still the battery's miniature, not a
run-level counter; it lands naturally with slice 4's arbiter, which owns the
compile queue anyway.  (ii) A profile-skipped stratum that grows mid-run has
no rescue until slice 3's promotion — the self-correction is re-entry-grained,
bounded by the 2 s ceiling.  (iii) The REPL/session driver does not record
(its runs still *consult* via `compile-strata`); recording there wants the
session's tier-box seam and rides with slice 3's next-re-entry pickup, which
lives in the same code.  (iv) `ensure-delta-so` and the flavored artifact
families are out of scope: they compile lazily on first routing already.

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

#### Slice 3 as-built (2026-08-09)

Both halves ride seams that already existed; neither adds a driver loop.

**Promotion** is an upgrade closure (`make-promotion-upgrade`,
compile.rkt).  The profile-skip path used to hand the driver `#f` for its
upgrade; it now hands a closure that offers nothing while the interpreted
run is under budget (`SLOG_TIER_PROMOTE_MS`, default 4000), and past budget
launches the pooled `-O0` build plus the claimed detached `-O2` ONCE — the
TUs are already on disk — then behaves exactly like `make-native-upgrade`,
so the artifact attaches at the next safe boundary through the unchanged
T3a swap seam, in both drivers (the session's tier box narrates it as an
ordinary arrival).  A classification skip (slice 1's zero-clang verdict) is
a policy statement, not a guess, and deliberately gets no rescue closure.

Two timing truths the smoke run taught, both now encoded:

- **Polls only happen at pauses, and the default pause budget is 8 s**
  (`RunBudget.max_ms`).  A 6-second stratum under the default budget never
  pauses, so the closure credits one budget period up front — the first
  poll is itself proof the stratum has already interpreted `max_ms` of
  wall time.  Without the credit, promotion needed two budget periods and
  a sub-8s stratum could never promote at all.
- The gate drives with `SLOG_MAX_MS=500` — the daemon's own
  pathological-budget knob, the byte-identical suspend test's precedent —
  so boundary polls come every ~0.5 s and the battery finishes in seconds
  without weakening what it proves.

**Next-re-entry pickup** is one resolver change (`sinfo-artifact`,
session.rkt): `'auto` now means "the best artifact the cache holds"
(`.so` > `.O0.so` > registered) rather than "whatever the stratum
registered with".  Two rungs of one latent defect die there: the stratum
whose fixpoint beat clang stayed interpreted for its whole session
lifetime beside its own built-but-unused artifact (the R3 `tiers`
checkpoint recorded exactly this gap), and — found while reading the seam —
a stratum that DID swap mid-run still had the plan as its registered
`sinfo-so`, so any re-entry send silently flipped it back to the
interpreter.  Identity still uses `sinfo-so` everywhere; the tier box
advances at resolve time so `tiers` keeps telling the truth.  The
`'interpreted` policy pin (T5's debugger flip) is checked first and never
picks up.

**Sessions record the race now** (slice 2's residue (iii)):
`drive-to-fixpoint!` hands `(iterations, ms, loaded)` back from the
fixpoint line, and `push-sbuild!` feeds `profile-note-fixpoint!` under the
same tiered-regime scoping as the batch driver.  Re-entry and maintenance
drives deliberately do not record — they run flavored or replay work, not
the semantic first fixpoint.

**Cross-program profile transfer is real, and the batteries prove it the
hard way.**  The gate's 2500-chain closure kernel is byte-identical to
`reach`'s (T4's name-free sharing), so `reach`'s fast observations made the
chain's first cold run profile-skip — the exact stale-evidence scenario
promotion exists for — and later the chain's honest slow observation
un-skipped `reach`.  One battery fallout: a discovery run that skips queues
no builds, so waiting for its `-O2` deadlocks; both batteries' quiesce now
keys on the `.so.building` claim marker (fast-compile §13) instead of
assuming a build is in flight.

**Gates run:** `tier-promotion` 4/4, new tier in ALL — stale profile →
`[promoting …]` → attach before fixpoint → byte-identical CSVs; the
recorded outcome (`upgraded #t`) un-skips the stratum; a huge budget
refuses to promote and completes interpreted with zero clang; and the
session drive (via two additive `session-drive.rkt` ops, `tiers` +
`await-build`) shows the cold-started stratum interp-registered beside its
cached artifact, then climbing to `o0`/`o2` at `reenter` with the new
tuple's closure present and the push's observation recorded.
`tier-profile` 5/5 and `tier-classification` 10/10 re-run green after the
marker fix; unit 442; session battery + protocol battery at slice end.

**Residues.**  (i) The budget is a fixed wall-clock ceiling with a
first-poll credit, not yet "a small multiple of estimated O0 compile
cost" — recording per-kernel build times and deriving the estimate belongs
to slice 4's arbiter, which owns the compile queue.  (ii) Promotion
launches builds directly onto the pool; the "jumps the queue" phrasing
becomes real when slice 4 gives the pool priorities.  (iii) Re-entry
drives still do not record observations; with pickup live their evidence
is mostly redundant (the artifact attaches anyway), so this waits for a
demonstrated need.

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

#### Slice 4 as-built (2026-08-09)

**The budget** (`core-budget`, tools.rkt): §5.5's split applied to what the
driver process owns — the eager `-O0` pool at `max(floor(P/2)−1, 1)` and
the detached `-O2` batch at `max(ceil(pool/2), 1)`, both from the ONE
function, replacing a pool that defaulted to `P` and a batch at `P/2` ON
TOP of the daemon's `P−1` workers (~2.5 P of hard demand; on this 8-core
machine, 19 threads → 12, five of them nice'd).  `SLOG_CORES` overrides
the detected count; `SLOG_BUILD_JOBS` still pins the pool and wins.

**One deliberate deviation from §5.5, stated plainly:** the daemon's `-t`
stays at `P−1`.  It is launch-static — the daemon spawns before
compile-strata knows whether any build will be queued — and §5.5's
`ceil(P/2)` would tax every warm native fixpoint to relieve contention
that exists only while cold builds are in flight.  The compile side is
hard-capped and the O2 batch nice'd, so clang yields to the daemon rather
than racing it; the fully daemon-owned budget waits for daemon-side
resizing and stays this slice's residue.

**The priority queue**: `pooled-eager` is now a real queue — jobs carry a
priority (1 = current SCC, 2 = future) and a label (the stratum hash);
fixed workers pop lowest-priority-then-lowest-sequence, so pipeline order
holds within a class.  `pool-boost!` raises a pending label to priority 1;
both drivers call it just before blocking on a stratum's runnable, and the
promotion closure submits at priority 1 outright.  Detached O2 work never
enters the queue: "every O2 last" is enforced by budget share and
`nice -n 10`, not queue position — the batch must survive the driver's
exit (that is what detached means), so it cannot be a pool job.

**`o0-max` honored at last** (`stratum-wants-o2?`): a stratum earns an O2
claim only when some natively covered variant is `tiered`.  The unit of
enforcement is the artifact, so a MIXED stratum (an acyclic join sharing a
level with a recursive rule) rightly keeps its O2 — the gate's fixture had
to stratify its join above the closure to see the cap, which is the
per-kernel-vs-per-stratum distinction made concrete.  An o0-max stratum
gets no claim, no upgrade past `-O0`, and — the job hash being
policy-keyed — no stale `.so` can ever satisfy its warm branch.
Deliberate simplification: such a stratum also forgoes free-riding
cluster-mix upgrades from `.o`s that other programs' O2 builds share into
the cache; predictability over opportunism until a profile shows it
matters.

**The clang metric** (§5.4, "track this as a measured metric, not a
slogan"): compiles, links, and caused-O2-claims count at the three clang
funnels (`build-o` misses, `link-os`, `try-claim-o2!`), and the batch
driver prints `[clang: N compiles, M links, K o2 claims]` at run end.
Warm runs report exactly zero; a cold run's line may undercount work
still in flight at report time (T3a deliberately does not wait), which
the gate's assertions respect — warm is exact, cold is nonzero.

**The estimate closes the promotion loop**: every pooled O0 build is
timed (`timed-o0-build`) and recorded per kernel key (`(build-ms N)` in
the profile file, latest-wins beside the observations), and the promotion
budget becomes `max(default-floor, mult × estimated-O0-ms)` — §5.3's "a
small multiple of its estimated O0 compile cost" — with a pinned
`SLOG_TIER_PROMOTE_MS` staying a hard override in both directions
(`SLOG_TIER_PROMOTE_MULT` defaults to 2).

**Gates run:** `tier-arbiter` 5/5, new tier in ALL (o0-max capped with a
tiered control claiming in the same run; cold reports nonzero clang; warm
reports exactly zero); `tier-arbiter-tests.rkt` 7/7 (budget arithmetic
over P ∈ {2..32}, a one-worker pool proving priority-then-sequence order
and boost, error re-raise, estimate arithmetic, and the
build-ms/observation round-trip); unit 449; `tiered-tests` 9/9 (the swap
machinery over the rewritten pool); `tier-profile` 5/5,
`tier-classification` 10/10, `tier-promotion` 4/4 — the last after fixing
a state-dependence in its part 2 (the battery's own cold discovery run
recorded a fast observation and skipped the real run; discovery now runs
under `SLOG_TIER_PROFILE=0` and clears the fixture kernels' profiles,
proven by running the battery twice back to back); 10 targeted goldens;
api battery at slice end.

**Residues.**  (i) The daemon's thread width stays outside the budget
until daemon-side resizing exists (the §5.5 deviation above).  (ii)
Oracle backends (smt.md's racing pools) still size themselves; they join
the budget when a real workload shows the contention.  (iii) §5.5's
"compiler streams each sealed SCC plan as lowering finishes" is untouched
— emission remains per-program-batch ahead of the run.

## 4. What T3b hands the rest of the arc

The runtime/transaction arc's later slices (T0(c), T6, the private activation
spine) need one thing from T3b: **a tier decision that is per kernel and
re-decidable at a boundary.**  RF5-B activation rebuilds a private cone whose
kernels are mostly cold and mostly short-lived — precisely the population that
should never see clang — and T6's restart-under-a-different-executor stress
needs promotion and demotion to be things the daemon can actually be asked to
do.  Slice 3 is the one with a hard dependency in that direction; slices 1, 2,
and 4 are independently valuable and independently gated.
