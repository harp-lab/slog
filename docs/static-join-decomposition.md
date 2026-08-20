# Static join decomposition & WCOJ chaining (bowtie case study)

**Status — CASE STUDY EXECUTED (2026-08-15); S1 + S1b + S2 + S3 ALL
SHIPPED (2026-08-19), measured below.** Companion to
`docs/join-planning-assessment.md` (the runtime-selection track): that doc
moves *cardinality* decisions to run time; this one asks what the compiler
can do better **purely statically** — decomposing complex rules so
identical subfragments are computed once, and understanding exactly where
the 3-way WCOJ operator (`join3`) does and does not reach.

## TL;DR

1. **The premise "join3 must start a query / cannot chain with itself" is
   false — in the good direction.** `join3` can never be the *driver* (each
   arm needs a non-empty bound prefix; a triangle always costs one
   driver/scalar step + one join3), but the plan search chains them freely:
   the 6-atom bowtie compiles TODAY to `driver → join3 → scalar → join3`,
   both triangles WCOJ-closed, and closed-rule driver enumeration makes the
   plan **spelling-insensitive** (both the natural and the adversarial
   clause orders emit byte-identical plans).
2. **But three cliffs bound that happy region**, and they, not the bowtie
   itself, are where static work should go:
   - **the compute cliff** *(FIXED by S1, 2026-08-19)* — ONE surviving
     body computation (the everyday `(= W (+ X U))` "derive a value from
     the match" shape) disabled the search for the WHOLE rule: every
     join3 lost, spelling-sensitivity back;
   - **the cap cliff** *(DEGRADED by S2, 2026-08-19)* — bodies with more
     than `wcoj3-search-cap` (= 8) join occurrences skip the search; the
     greedy fallback could never emit a join3, so a 9-join rule silently
     lost ALL wcoj (now: greedy-local closers);
   - **the arm cliff** *(remains)* — lattice/struct/temp occurrences, 3+
     eligible arms on one key, payload columns: each falls back per-shape.
3. **No factoring/CSE exists anywhere in the compiler**, and the staging
   temp mechanism *cannot* express it (temps are index-free and can never
   be probed — `tri(X,Y,M), tri(M,U,V)` needs two probeable occurrences).
   A factored fragment must be a real relation introduced **before
   stratification**; the `seq-expand` pass is the proven template (rewrite
   bodies + declare relations mid-pipeline + contribute stratification
   edges).
4. **Factoring is legitimized by existing doctrine** (incremental.md §8B.3:
   a semantic source transform may change derivation counts if applied
   uniformly across all flavors) — but it must contribute stratification
   edges (it *drops* source atoms, the exact case seq-expand.rkt:212-225
   names as requiring edges), and it changes `$stat_fires` keys and plan
   goldens.
5. **Measured on the planted 5.1M-edge gadget graph (O2):** the
   single-rule bowtie needs NO help (mono with chained join3s beats the
   hand-factored form 1 020 vs 1 215 ms); the compute cliff costs
   **8.7×** (9 914 vs 1 142 ms factored); the tri stratum shows join3
   worth **7.9×** (9 399 → 958 ms); cross-rule redundancy is worth
   **30×** (48.7 s → 1.6 s) and unbounded with wcoj off (>900 s timeout
   → 10.3 s). Two surprises: factoring *strips semijoin filter context*
   (the bare tri rule pays a 2G-probe tax the monolithic rule's filters
   prune — 9.4× against factoring in the scalar world), and an
   expand-count TIE inside the wcoj world was broken data-blind onto a
   catastrophic driver (~46 s of the 48.7). Improvements ranked in
   §"Proposed static improvements": S1 lift the compute cliff, S1b
   positional tie-break, S2 cap-cliff degradation, S3 factoring gated on
   structural wins (cross-rule sharing, cliff rescue) — explicitly NOT
   on single-rule aesthetics.
6. **S1 + S1b + S2 + S3 all shipped 2026-08-19** (as-built shapes in
   §"Proposed static improvements", post-fix reruns in §"Results"): the
   compute cliff is gone (9 914 → 870 ms, parity with compute-free), the
   tie casualty is fixed (48 676 → 2 653 ms), the cap cliff degrades to
   greedy-local closers, and cross-rule shared triangles now factor
   AUTOMATICALLY into `$frag` relations (the unfactored 3-rule program
   compiles to the hand-factored shape and matches its performance) —
   all with zero plan-golden churn. Point 3 below is historical: the
   compiler now has exactly the factoring pass it describes as missing.

## The machinery as verified (join3 ground truth)

All anchors verified 2026-08-15.

- **One producer.** `expand3-action` is created only inside the bounded
  plan search: `expand3-candidates` (`join-planning.rkt:1040`) ←
  `search-action-tail` (`:1113`) ← `schedule-body-actions` (`:1203`). The
  greedy fallback loop (`:1210-1230`) can never emit one.
- **Arm eligibility** (`:1047-1056`): ordinary tables only; FULL/OLD/NEW
  views; **exactly one free variable**, ≥1 bound column, arity = bound+1
  (key-simple), no payload columns. Arms are grouped by their free
  variable and a group qualifies only with **exactly two** arms
  (`:1068`); the cycle must be certified through already-consumed
  occurrences (`incidence-connected?`, `:1023-1032`).
- **Never the driver, chains freely.** The driver is scheduled before the
  search runs (`:1189-1192`) and the daemon has no join3 driver kind
  (`plan.h:60`, `:188-191`). Inside the search, expand3 and scalar
  branches interleave at every depth (`:1138-1171`), and
  `better-searched-plan` (`:1100-1107`) **maximizes** the expand count —
  so two join3s in one body is not just possible, it is preferred.
  Delta versions of recursive rules get join3 too, with exact view
  signatures (`tests/unit/wcoj3-tests.rkt:190-214`).
- **Closed-rule spelling-insensitivity.** For closed/seeded rules the
  planner tries every legal driver (`enumerate-drivers?`, `:756-759`) and
  keeps the candidate with the most expands (`candidate-better?`,
  `:828-844`). Verified empirically: `bowtie_mono.slog` and
  `bowtie_mono_adv.slog` (adversarially reordered) emit **byte-identical
  plans** — driver = the closing edge of triangle 2, then
  `exists → join3(U) → scalar(X→M) → join3(Y)`.
- **The compute cliff** (`:1198-1204`): the search runs only when
  `computes1` is null — any surviving body computation drops the whole
  rule to the greedy scalar schedule (`tests/unit/wcoj3-tests.rkt:156-163`).
  Comparison guards are fine (guards are tracked separately); it is
  value-*producing* computes that kill it. Verified in the emitted plans:
  the compute variant's driver reverts to the first-written clause —
  spelling-sensitivity returns with the cliff.
- **One mitigating grace: the greedy score closes eagerly.** A
  fully-bound closure check scores `bound·100 = 200` vs `65+enables` for
  an expanding join (`join-score:991`), so the greedy fallback still
  fires triangle checks as soon as their variables ground — the deep
  "expand the whole path, check at the end" blowup cannot be forced by
  spelling alone. The greedy failure modes are driver choice and
  expansion *ties* (the 100–260× path/star cases of
  `join-planning-assessment.md`), not delayed closures.
- **The cap cliff** (`:1202`): `(length joins) > (wcoj3-search-cap)` — 8
  by default (`params.rkt:148`), counting ALL join occurrences including
  the driver — skips the search. Since only the search emits join3, a
  9-join body loses every wcoj opportunity silently.
- **Runtime shape**: leapfrog intersection over two sorted B-tree prefix
  cursors (`operators.h:264-286`), hybrid seek (8 local steps then
  `lower_bound`); OLD = FULL minus delta-contains, NEW = merged
  FULL ∪ delta. The interp mirrors it byte-for-byte with budget ticks
  inside the loop (`plan.cpp:2067-2270`). OLD/NEW arms pin the delta
  index to the full index's ordering (`operationalization.rkt:523`,
  seal check `plan.h:958-969`) — the one extra-index cost join3 imposes.

## Factoring: what exists (nothing) and what it must be

Survey result (anchors verified 2026-08-15):

- **No subpattern detection anywhere.** The only sharing machinery:
  RHS hash-consing of `=` bindings within one rule
  (`simplification.rkt:60-76`), `$sup` prefix sharing within one demand
  rule alternative (`demand.rkt:714-741` — keyed on source position,
  never shared across rules), whole-rule dedup via the rules set
  (`compile.rkt:370-374`). `rule-sort-key` (`join-planning.rkt:126-166`)
  alpha-normalizes *whole rules* for determinism — the closest existing
  fragment canonicalizer, never used for sharing.
- **Staging temps cannot express a self-join.** `stage-rule`
  (`join-planning.rkt:374-563`) splits on exactly one trigger — a head
  clause consuming a value another head clause produces (intern-phase
  ordering, `:8-15`) — never on body size or shape. Its temps are
  index-free appends (`operators.h:554-566`), can only ever DRIVE
  (`:770-772`), and are never shared between rules. `tri(X,Y,M),
  tri(M,U,V)` needs two occurrences of one relation, at most one of which
  drives — structurally impossible for a temp. **A factored fragment must
  be a real, indexed, stratified relation.**
- **Where the pass lives**: the `expand-seq-patterns` slot
  (`compile.rkt:290-291`) — post-simplification (bodies flat, wildcards
  gensym'd), pre-typecheck, pre-stratify. `seq-expand.rkt:151-225` is the
  template: rewrite bodies across the rule set, declare new relations
  into the type env (`:194-212`), and return extra stratification edges
  (`compile.rkt:296-300`). Naming must be deterministic-from-content
  (gensym-free; the pass precedes the cache key) — the alpha-normalized
  canonical fragment text is the natural name seed.
- **Stratification edges are mandatory, not optional.**
  `seq-expand.rkt:212-225` documents the boundary precisely: `$seq_at`
  contributes no edges ONLY because its probes are *additive* (the source
  atom stays in the body). "A future lowering that DROPS the source atom
  must reintroduce the edges." Factoring drops the source atoms — so the
  synthesized relation joins the dependency graph, and if `edge` is
  recursively derived, the fragment relation joins that SCC (the rewrite
  can change stratum shapes; this is correct, not a bug, but golden- and
  schedule-visible).
- **Multiplicity doctrine already covers it.** `incremental.md:1176-1186`
  (§8B.3): the counting unit is fixed *after semantic source transforms
  (or-splits, demand rules, construction staging) but before physical
  planning* — physical decomposition must be instantiation-bijective;
  semantic transforms may legitimately change counts. Factoring done as a
  pre-stratify source transform is the latter — **permitted**, provided
  it is uniform across `_count`/`_maint*` flavors
  (`incremental.md:886-890`: "temp decomposition, guards, errors,
  or-splits, and projection must not collapse a derivation in only one
  flavor"). The cross-flavor gate already names "self-joins" and
  "multiple occurrences of one relation" as required test axes
  (`incremental.md:1189-1196`).
- **Fire identity / goldens**: the synthesized rule is a genuinely new
  rule-def with no natural source `loc` — `$stat_fires` keys and plan
  goldens change (re-record sanctioned); the exact-once audit is
  unaffected because each rule-def still fires exactly once per
  instantiation.

## The case study

### The graph (`bench/gen.py bowtie_graph`)

Planted gadget classes over one directed `edge` relation, disjoint node
ranges so each cost is attributable; triangle = the transitive shape
`a→b, b→c, a→c`; a bowtie = two triangles sharing their apex M (tri1 has
M as sink, tri2 as source).

| gadget | small (260k edges) | big (5.125M edges) | what it taxes |
|---|---|---|---|
| ER background | 50k nodes / 100k edges | 1M / 2M | volume, few organic triangles |
| wedge hubs (closures absent) | 8 × deg 1500 → 18M 2-paths | 20 × deg 10000 → 2G 2-paths | any unbound scalar triangle scan; join3 avoids it |
| near-bowties (tri + 20 open wedges at M) | 2 500 | 50 000 | re-deriving the second triangle at every candidate apex |
| bowties (the answers) | 500 | 10 000 | — |
| bridges + near-bridges | 250 / 1 000 | 5 000 / 20 000 | the 1-hop-bridge variant |

Sizing lesson from round 1 (hubs 600 × deg 300 = 54M): the tax must
**dwarf |E| × c** to separate plans — every plan pays a ~|E|-row driver
scan (~1s at O2 on 5M edges) and the aggregate btree probe rate is
~0.4G/s, so a 54M-probe tax vanished into the baseline and every variant
measured ~1s. Round 2's 2G tax separates cleanly.

### The variants (`bench/bowtie_*.slog`, harness `bench/bowtie-study.sh`)

- `bowtie_mono` / `bowtie_mono_adv` — one 6-atom rule, natural vs
  adversarial clause order.
- `bowtie_tri` — hand-factored: `tri/3` materialized once, bowtie =
  self-join on the apex. Same output by construction.
- `bowtie_mono_compute` / `bowtie_tri_compute` — the same pair plus one
  arithmetic body compute consumed by the head: the compute-cliff A/B.
- `bowtie_bridge_mono` / `bowtie_bridge_tri` — 7-atom 1-hop-bridge shape
  (still under the cap of 8).
- `bowtie_multi_mono` / `bowtie_multi_tri` — the cross-rule case: three
  queries (bowtie, triangle+pendant `trip`, bridged bowtie) each inlining
  the triangle pattern, vs the same three sharing one materialized `tri`.

### Results

Summed per-stratum fixpoint ms (`bench/bowtie-study.sh`, 2026-08-15;
single run each — separations are 4×–30×+, far beyond run noise). All
variant outputs verified identical, per config and per pairing.

| program | small interp on | small interp off | big O2 on | big O2 off |
|---|---:|---:|---:|---:|
| bowtie_mono | 52 | 84 | 1 020 | 1 025 |
| bowtie_mono_adv | 49 | — | — | — |
| bowtie_tri | 71 | 249 | 1 215 | 9 639 |
| bowtie_mono_compute | 203 | — | 9 914 | — |
| bowtie_tri_compute | 59 | — | 1 142 | — |
| bowtie_bridge_mono | — | — | 1 014 | — |
| bowtie_bridge_tri | — | — | 1 287 | — |
| bowtie_multi_mono | 579 | — | 48 676 | **TIMEOUT (>900 s)** |
| bowtie_multi_tri | 100 | — | 1 610 | 10 285 |

Per-stratum attribution for the factored variants (big, O2):
`bowtie_tri` on = 958 (tri materialization) + 257 (self-join);
off = 9 399 + 240. `bowtie_multi_tri` on = 1 030 (tri) + 581 (all three
consumers). `bowtie_tri_compute` on = 936 + 206.

**Post-S1/S1b rerun (2026-08-19, same harness; only the changed rows):**

| program | small interp on | big O2 on |
|---|---:|---:|
| bowtie_mono_compute | 203 → **34** | 9 914 → **870** |
| bowtie_multi_mono | 579 → **96** | 48 676 → **2 653** |

All other rows within run noise of the table above; outputs identical
throughout; all four plan goldens byte-identical. The compute cliff is
gone (finding 3 is historical), and finding 6's tie is fixed — which
retro-decomposes the original 30×: ~46 s of it was the tie casualty, and
the *redundancy proper* is the remaining multi_mono 2 653 vs multi_tri
1 461 ms (~1.8× at this scale, three |E|-row scans vs one) — plus the
(then-)unchanged wcoj-off story (multi_mono still >900 s vs factored
10.3 s).

**Post-S3 rerun (2026-08-19, the factoring pass live):**

| program | small interp on | big O2 on | big O2 off |
|---|---:|---:|---:|
| bowtie_multi_mono (now AUTO-factored) | 87 | 1 210 | **1 397** |
| bowtie_multi_tri (hand-factored) | 103 | 1 581 | 10 718 |

The unfactored three-rule program now compiles to the factored shape by
itself (one `$frag` relation, two strata) and runs at parity or better
with the hand-factored twin in every configuration; the full 168-golden
correctness battery passes with the pass live, and all nine
cross-variant output checks are identical. The wcoj-off TIMEOUT row is
gone (>900 s → 1 397 ms) — and it lands 7.7× BELOW the hand-factored
twin's 10.7 s there, a final data-blindness lesson: the synthesized
rule's *canonical* atom order happens to greedy-plan into a hub-pruning
driver on this graph while the hand-written `tri` spelling does not.
Spelling-dependence persists in the scalar world; that is
J0/runtime-selection's job, not S3's.

### Reading of the results

Six findings, each verified against the emitted `.plan` bytes:

1. **The single-rule bowtie is already handled well — factoring LOSES
   there.** Mono with its two chained join3s: 1 020 ms. Factored: 1 215 ms
   (one extra stratum, 100k-row materialization + intern, a self-join that
   buys nothing the chained plan didn't already have). The premise "the
   monolithic rule re-derives the triangle expensively" does not hold:
   the planner drives from tri2's closing edge and closes both triangles
   from bound variables.
2. **Factoring strips semijoin context — a real, measured cost of
   decomposition.** Mono-scalar ≈ mono-wcoj (1 025 vs 1 020) because the
   bowtie's *other* atoms make the exists-filters effective: the filter
   `∃?→M` kills every wedge-hub driver row at cost 1 (hub in-spokes have
   no in-edges). The bare 3-atom `tri` rule has no such context — its
   prefix-existence checks pass at hubs by construction (the wcoj_hub
   property) — so it eats the full 2G-probe tax: 9 639 ms, **9.4× worse
   than the monolithic scalar plan it was factored from.** A factoring
   pass must expect this: the fragment loses the residue's pruning power.
3. **The compute cliff is the big practical hazard: 8.7× at scale.** One
   `(= W (+ X U))` drops the whole rule to greedy scalar: 9 914 ms vs
   1 020 for the compute-free mono (9.7× self-inflicted) and vs 1 142 for
   the factored twin that quarantines the compute in the outer rule. The
   emitted plan confirms the driver reverts to the first-written clause —
   spelling fragility returns exactly here.
4. **join3 inside the pipeline is worth 7.9×** where the tax is real:
   the tri materialization stratum alone is 9 399 ms scalar → 958 ms with
   join3.
5. **Cross-rule redundancy is where factoring wins big — 30× with wcoj
   on, unbounded without.** multi_mono 48.7 s vs multi_tri 1.6 s; with
   wcoj off, multi_mono exceeds the 900 s timeout while multi_tri holds
   at 10.3 s (one tax paid once). The 48.7 s decomposes into (i) the
   redundancy proper (three |E|-row scans + three taxes vs one), and —
   the sharper part —
6. **a data-blind tie INSIDE the wcoj-covered world.** The `trip`
   (triangle+pendant) rule has two 1-expand driver candidates:
   drive the cycle then attach the pendant, or drive the pendant then
   rebuild the cycle. Expand counts tie; `join-score` broke the tie onto
   the **pendant** — so every hub out-edge `(h,b)` became a driver row
   streaming `{X : X→h}` = 10k scalar candidates before the join3
   (verified in the plan: driver `(M,W)`, scalar `{X:X→M}`, then
   join3(Y)) — ~2G probes, ~46 s of the 48.7. The same
   cardinality-blindness documented in `join-planning-assessment.md`
   reappears *between wcoj plans*, which strengthens both that doc's J0
   tie-break work and runtime plan selection: expand-count ties among
   drivers should be broken by size, or at least by expand *position*
   (see S2b).

## Arc-end verification (2026-08-19/20)

Full sweep at `bd23002`: **33 of 34 harnesses green**, the one failure being
the then-unrecorded golden for the new `frag_multi` program (recorded
since; the golden battery is green at 170 with the two new programs).
Beyond the sweep, three checks were added specifically for the risky
seams a golden cannot see:

- **Factored ≡ unfactored, per program.** `tests/frag_multi.slog` and
  `tests/frag_rec.slog` each run twice, with and without
  `SLOG_NO_FRAGMENT_FACTOR=1`; every relation is identical, and no `$frag`
  relation exists when the switch is off. Outputs also match the
  hand-computed values written into each program's header.
- **Factoring inside a recursive SCC** (`tests/frag_rec.slog`): the shared
  triangle is over the recursive `path`, and one consumer writes *back*
  into `path`, so `$frag` both reads and feeds its own base. Stratify
  merges it into that SCC from the synthesized rule's own edges (no manual
  edges), semi-naive converges (5 iterations), and the fixpoint is
  identical to the unfactored program. This was the riskiest untested
  path for S3.
- **Counted flavor, against an independent oracle**
  (`tests/session/frag_counts.slog`): a factored program under `_count`
  with a double `(recount)`, cross-checked against
  `tests/api/count-ir-oracle.rkt`, which shares no runtime count
  machinery. The daemon's per-row support words match the oracle exactly,
  and the counts equal the unfactored program's — the instantiation-
  bijectivity claim, verified rather than argued.

**Pre-existing blind spot found (not introduced here, worth its own
fix):** `count-ir-oracle.rkt` has no `join3` support and fails loudly on
it, so the independent count oracle cannot cover ANY wcoj-containing
program — the check above had to run under `SLOG_NO_WCOJ3=1` (counts are
operator-independent, so this still validates the factoring). Teaching
the oracle `join3` would extend counted-flavor oracle coverage to the
whole wcoj surface, `sj_tri` included.

## Proposed static improvements (ranked)

- **S1 — lift the compute cliff. SHIPPED 2026-08-19.** As built: the
  gate's real motivation is the speculative-compute doctrine
  (`fire-specials`' header — a prim fired before a later filtering join
  can fault on rows that join would reject), so the relaxation is exactly
  the case where timing cannot differ: when **no join consumes any
  compute's output**, the greedy order fires every compute in the
  post-join flush anyway, so the search runs around them and the same
  flush is spliced after the searched schedule (never speculative,
  identical firing point). Guards over compute outputs are withheld from
  the search (its leaf demands every guard discharged) and flushed with
  the computes — the flush-mode feeder preference that lets a guard
  protect a faultable compute is preserved. A compute output consumed by
  a join keeps the greedy path (on-demand firing / ==-check interplay).
  **Measured:** big O2 compute bowtie 9 914 → 870 ms (11.4×, parity with
  the compute-free mono); small interp 203 → 34 ms. Unit battery grew
  head-only-compute / guard-over-compute / join-consumed-compute pins.
- **S1b — break expand-count ties by schedule profile. SHIPPED
  2026-08-19, after one instructive failure.** The naive version —
  compare Expand3 *positions* right after expand count — shipped a
  worse plan: for the bridged bowtie it preferred a schedule that
  closed tri1, ran a **K=0 Cartesian scan** of all edges as `(M2,V)`,
  closed tri2, and checked the bridge last (positions (1,3) beating the
  sane plan's (1,4)). Two lessons became the design:
  (i) **the summed schedule score cannot arbitrate complete schedules —
  it is order-insensitive by linearity** (each variable is free at
  exactly one step of any complete schedule, so bound/free totals are
  fixed by the atom set: a −70 Cartesian plus a +200 terminal check sums
  identically to two 65-point probes), which is why within-driver ties
  silently fell to candidate enumeration order all along;
  (ii) the real discriminator is the **lexicographic per-step
  free-variable-count sequence** (selective-early wins; an avoidable
  Cartesian step loses outright), applied BOTH within the search
  (`better-searched-plan`, via a new `frees` field) and across driver
  candidates — but ranked **below the driver's structural score**: the
  first cut ranked it above and flipped a demand rule's driver from the
  const-prefixed `$sup` probe to a full `_enum` scan (caught by the
  dem_lambda plan golden). Final order: expand count → driver score →
  free sequence → expand positions → occurrence id. Plan goldens:
  zero churn (all four byte-identical). **Measured:** multi_mono big O2
  48 676 → 2 653 ms (18.4×); small interp 579 → ~100 ms. The remaining
  gap to the factored twin (1 461 ms) is the honest three-scans-vs-one
  redundancy. The full fix for such ties remains cardinality
  (J0/runtime selection).
- **S2 — degrade the cap cliff gracefully. SHIPPED 2026-08-19.** As
  built: the greedy loop runs the same *local* 2-arm frontier test the
  search uses (`expand3-candidates` — linear, no lookahead) and takes the
  best closer, with two policy guards: (a) a fully-bound scalar check
  fires first (it only prunes — the same order the search's free-sequence
  doctrine picks), and (b) a closer whose cycle variable is a pending
  compute's output is skipped (compute-then-probe is O(1)/row; the closer
  pays an intersection). Searched bodies are unaffected by construction —
  a greedy-local closer implies a ≥1-expand schedule the search finds and
  prefers — so plans change only for over-cap and join-consumed-compute
  bodies, exactly the target set. Pleasant surprise: closed-rule driver
  enumeration now maximizes greedy-local closers too, so a
  join-consumed-compute rule picks the driver that *grounds* the compute
  output and closes the remaining cycles by intersection (pinned in the
  unit battery). Plan goldens: zero churn.
- **S3 — subpattern factoring. SHIPPED 2026-08-19
  (`compiler/fragment-factor.rkt`).** As built: a pass in the
  `expand-seq-patterns` slot (post-simplify, pre-typecheck), v1 fragment
  shape = three positive binary-table atoms forming a variable triangle.
  Canonical class key = lexicographically-least rendering over the six
  atom orderings with first-occurrence variable numbering (resolves
  automorphisms deterministically); name = `$frag` + sha256 of the key;
  the synthesized relation projects ALL THREE variables, so fragment rows
  are in bijection with fragment instantiations and the rewritten rule's
  instantiations are in bijection with the original's — tuple output AND
  derivation counts preserved exactly, stronger than §8B.3 requires.
  **Trigger: ≥2 distinct rules share the class** — the case study's
  verdict encoded (single-rule repeats like the bare bowtie do NOT
  trigger; they measurably lose). Exclusions: lattice relations
  (order-sensitive merges), structs, `$`-internal relations,
  repeated-var atoms, embeddings touching const-bound variables (the
  fragment would compute the unconstrained pattern and post-filter).
  No manual stratification edges needed — the synthesized rule is an
  ordinary rule, so stratify derives base→fragment from it (the
  `$seq_at` manual-edge case was for a relation with no defining rule);
  a recursive base pulls the fragment into its SCC by design. The
  `SLOG_NO_FRAGMENT_FACTOR` switch is cache-keyed beside the
  semijoin/wcoj switches; `$frag*` joins `$stat_*`/`$sup*` in the test
  harness's internal-relation skip. Unit battery: trigger,
  canonicalization across renaming/reordering, determinism, single-rule
  and const-bound non-triggers, distinct classes stay distinct, kill
  switch.

  *What v1 leaves open, deliberately:* larger/acyclic fragment shapes
  (the enumerator generalizes to connected bounded-size subsets);
  cliff-rescue triggers beyond cross-rule sharing (S1/S2 shrank that
  need); and any size-gated trigger — materialization is not free (a
  fragment relation can be superlinear on dense inputs, the same
  data-blindness caveat as `join-planning-assessment.md`), which is why
  v1's trigger is purely structural and single-rule repeats stay
  unfactored, and why a cardinality-gated version waits for the
  runtime-selection track's size machinery.
- **S4 — cross-links.** The J0 tie-break/FD work
  (`join-planning-assessment.md`) extends spelling-insensitivity to the
  greedy/scalar world the cliffs currently drop rules into. The missing
  **per-rule work counter** (probes/scans; `$stat_fires` counts only
  successful instantiations) is a shared need of this study's cost
  attribution and that doc's J4 measured-adaptation phase — one
  diagnostics feature serves both.

## Files

- Study: `bench/gen.py` (`bowtie_graph`), `bench/bowtie_*.slog`,
  `bench/bowtie-study.sh`; data `data/bench_bowtie{,_small}`.
- join3: `compiler/join-planning.rkt` (`expand3-candidates:1040`,
  `search-action-tail:1113`, gates `:1198-1204`, arm eligibility
  `:1047-1056`, group rule `:1068`); `compiler/params.rkt:148` (cap),
  `:50-51` (toggle); `compiler/operationalization.rkt:503-526`, `:1079`;
  `daemon/operators.h:109-286`; `daemon/plan.cpp:2067-2270`;
  `docs/wcoj.md` (design; §support matrix).
- Factoring context: `compiler/join-planning.rkt:374-563` (`stage-rule`),
  `compiler/seq-expand.rkt:151-225` (pass template + additive-edges
  doctrine), `compiler/demand.rkt:714-754` (`$sup`),
  `docs/incremental.md:1176-1196` (§8B.3 multiplicity),
  `docs/db-compression.md:1346-1391` (staging×replay).
