# Static join decomposition & WCOJ chaining (bowtie case study)

**Status — CASE STUDY + PROPOSED DIRECTION (2026-08-15). Study executed;
improvements proposed, not implemented.** Companion to
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
   - **the compute cliff** — ONE surviving body computation (the everyday
     `(= W (+ X U))` "derive a value from the match" shape) disables the
     search for the WHOLE rule: every join3 lost, spelling-sensitivity back;
   - **the cap cliff** — bodies with more than `wcoj3-search-cap` (= 8)
     join occurrences skip the search entirely; the greedy fallback can
     never emit a join3, so a 9-join rule silently loses ALL wcoj;
   - **the arm cliff** — lattice/struct/temp occurrences, 3+ eligible arms
     on one key, payload columns: each falls back per-shape.
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

## Proposed static improvements (ranked)

- **S1 — lift the compute cliff (planner-local, small, likely the
  biggest win-per-line).** Run the search over the join-only body and
  splice surviving computes/guards back at their earliest fire point
  (the greedy loop's `fire-specials` logic already knows how), instead of
  refusing to search at all (`join-planning.rkt:1201`). A compute whose
  inputs bind late loses nothing by firing late; one that could fire
  early still can. Every "match a cyclic pattern, derive a value" rule —
  a very common shape — keeps its join3s and its spelling-insensitivity.
  Verify the gate's original motivation before building; the unit test
  battery (`wcoj3-tests.rkt`) pins current behavior.
- **S1b — break expand-count ties by position, not blindly
  (planner-local, tiny; the `trip` rule is the pinned regression).**
  `candidate-better?` compares expand COUNT only; the trip rule's two
  1-expand drivers tied and the structural score picked the pendant —
  a ~46 s casualty on the big graph. Secondary criterion: prefer the
  candidate whose expands come *earlier* in the schedule (WCOJ-first
  bounds the scalar expansions by intersection). This is the static
  stopgap; the full fix is cardinality (J0/runtime selection).
- **S2 — degrade the cap cliff gracefully (planner-local, small).**
  Above `wcoj3-search-cap`, don't abandon join3 wholesale: run the greedy
  scheduler and, at each frontier, apply the *local* expand3 test
  (2-arm group + `incidence-connected?` — linear work, no search) and
  emit a join3 opportunistically. Big bodies then degrade to
  "greedy with local closers" instead of "no wcoj at all". Alternatively
  or additionally: raise the cap (the search is memoized on
  `(pending, ground)`, `:1117-1120`; measure whether 10–12 is affordable).
- **S3 — subpattern factoring (the decomposition pass; medium; gated).**
  New pass in the `expand-seq-patterns` slot: canonicalize body fragments
  (alpha-normalized, `rule-sort-key`-style), detect repeats, factor into a
  synthesized indexed relation with deterministic content-derived naming,
  contribute stratification edges, apply uniformly across flavors.

  *Detection sketch.* Candidate fragments are not arbitrary subsets
  (exponential): enumerate **connected atom-subsets of bounded size**
  (start: exactly the 3-atom cycle cores the wcoj machinery already
  certifies via `incidence-connected?`), alpha-normalize each into a
  canonical fragment key (`rule-sort-key` gives the recipe: strip prov,
  canonical variable numbering, sorted atoms), and count embeddings in a
  table keyed by that hash — within one body first (the bowtie's two
  triangles are atom-disjoint and share only M; both normalize to the
  same key), across the rule set second (the `bowtie_multi` case). A
  fragment must not cross a negation, aggregation, or lattice boundary,
  and its interface (the variables shared with the residue) becomes the
  factored relation's columns.

  **Trigger policy is the crux — factor on structural win conditions,
  not taste:**
  (a) the fragment has ≥2 embeddings *across the rule set* — the measured
  win case: N edge-scans + N wedge taxes collapse to 1 (`bowtie_multi`);
  (b) extraction rescues wcoj that a cliff forfeited — the residual core
  becomes compute-free (S1's case until S1 lands) or drops under the cap
  (the measured compute-cliff A/B);
  (c) explicit user opt-in while confidence builds.
  Notably **absent** from the trigger list: the single-rule shared-apex
  bowtie itself — measured, factoring *loses* there (the chained-join3
  mono plan needs one driver scan and no materialization; the factored
  form pays a second stratum + intern for nothing). Materialization is
  NOT free (a fragment relation can be superlinear on dense inputs — the
  same data-blindness caveat as `join-planning-assessment.md`), so
  (a)/(b) — size-free, purely structural wins — come first, and a
  cardinality-gated version waits for the runtime-selection track's size
  machinery.
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
