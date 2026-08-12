# The activation spine — the runtime arc's pre-join deliverable

*Drafted 2026-08-12 (W5′ runtime/transaction arc, after T3b, T0(c), T6,
and the N5/stats-4 identity unification closed).  **Status: contract
drafted; slice A1 next.**  Normative parents:
[roadmap.md](roadmap.md) §6 (the two-arc plan, the `ProgramChangeSet`
fixture, the ownership table); [rf5-contract.md](rf5-contract.md) §7
(prepare/heal/publish), §7.1 (the correctness-first route), §10.1 (the
parallel handoff and the fixture's field list), §10's RF5-B exit gate;
[incremental.md](incremental.md) (cones, routes, the clear-and-rerun
fallback); [t6-contract.md](t6-contract.md) (read consistency);
[t0-contract.md](t0-contract.md) slice (c) (durable identities).  This
document pins the fixture, the resolution, the route, and the gates; the
parents stay authoritative for meaning.*

## 0. What the spine is for

One sentence, from roadmap §6: **accept a fully specified synthetic
program change, build a private successor cone, recount and audit it,
preserve or replace the correct durable identities, and atomically
publish or abort it.**

This is the runtime arc's half of RF5-B.  The program arc owns deciding
what a new program MEANS (diffs, lineage, affected roots); this spine owns
changing a live recipe-bearing database SAFELY once that meaning is
handed over.  The handoff is the frozen `ProgramChangeSet`; golden
serialized change sets let this arc finish before the compiler producer
exists, and the first joint battery will run the same goldens through
both sides.

## 1. The inventory (what the spine composes, 2026-08-12)

Nearly everything is shipped machinery; the spine is COMPOSITION plus two
schemas:

| need (rf5 §7 step) | shipped mechanism |
|---|---|
| validate/seal against a base boundary | N3/N4 committed boundary chain + catalog; the session's boundary planner |
| plan the descendant recipe (fresh keys) | T0(c) c1's key construction (program/module/rule/scc); the session's layer/event minting |
| prepare privately | N3 `prepare-boundary` — the private execution lease T6's verbs already respect |
| heal (correctness-first) | the clear-and-rerun cone (`session-rerun!`'s machinery; incremental.md 0.B2), writers + downstream over surviving strata |
| replay transferable assertions | the anchored batch/overlay replay (0.C/0.E0) |
| recount/audit | `session-recount!` + the exact-once audit; count epochs invalidate on writer-set change |
| pause or publish | T5's pre-commit gate (inspect, `why`/`whynot`) + `commit-boundary`/`abort-boundary`; T6 restart for latest-following readers |
| identity of the change's fires | the c2 registry + the `(fires)` view |

What does NOT exist and is this contract's work: the **`ProgramChangeSet`
consumer** (parse + validate a golden fixture against the selected
boundary), the **`ActivationPlan`** resolution (successor keys, slot
lineage, mapped suffix, route selection, publication policy), and the
**one-transaction driver** that runs rf5 §7's six steps as a unit with the
abort path proven.

## 2. The `ProgramChangeSet` fixture (frozen interface)

Per rf5 §10.1, serialized as one s-expression datum; this contract pins
the concrete spelling the goldens use (the program arc reviews it at the
first joint battery — roadmap's ownership table marks the schema "frozen
interface; joint review"):

```text
(program-change-set
  (abi 1)
  (base (program P1KEY) (boundary B1KEY))
  (candidate (image SHA) (compiler FPRINT) (plan-abi 2)
             (sources ((path REL-PATH) (text "…")) …))
  (occurrences (replace (old M1KEY) (new-slot (S …)) (home (H …))) …)
  (rule-lineage ((old R1KEY|#f) (new-slot U.R)) …)
  (slot-lineage ((relation QNAME) (old V1KEY) (disposition carry|rebuild|retire)) …)
  (diffs (source N-CHANGED) (semantic (added N) (removed N) (moved N))
         (plan (kernels-changed N)))
  (writers (old (QNAME …)) (new (QNAME …)))
  (sccs (old ((slot LEVEL (members …)) …)) (new (…)))
  (affected (roots (QNAME …)) (cone (QNAME …)))
  (services (REQUIRED …))
  (refusals (TYPED-REFUSAL …)))
```

Three rules carried over verbatim from rf5: **no live `VersionId`s, no
maintenance routes, no publication decisions** inside the fixture — those
are the session's to allocate/choose; **no inferred lineage** — every
old/new correspondence is explicit or absent; **compiler-known refusals
ride along typed** so the consumer can refuse before touching live state.

## 3. The `ActivationPlan` (session-resolved, never serialized by the fixture)

The session validates a change set against the NAMED base boundary and
enriches it:

```text
ActivationPlan
  successor ProgramInstanceKey / ModuleInstanceKeys / RuleKeys / SccInstanceKeys   (minted, c1 machinery)
  successor VersionKeys for every affected writer                                  (fresh slots; carried slots verified)
  accepted slot lineage (carry/rebuild/retire, checked against the catalog)
  mapped recipe-suffix events (or the typed historical-program-replacement refusal)
  route: correctness-first (mandatory fallback; precise routes are RF5-C, out of scope)
  invalidated count epochs (writer-set change ⇒ affected epochs)
  publication policy: commit | hold-at-gate (T5 gate) — abort always available
```

Validation refusals are typed and fire BEFORE any live mutation:
`unknown-base-boundary`, `stale-base` (the boundary is not the tip),
`unknown-occurrence`, `slot-lineage-conflict`, `unsupported-service`,
`historical-program-replacement` (rf5 §8's deliberate v1 cut).

## 4. The transaction (rf5 §7, composed)

```text
activate(change-set):
  1 validate      parse; check base against the session catalog; surface
                  fixture refusals; resolve the ActivationPlan
  2 plan          mint successor keys (c1); allocate fresh VersionKeys for
                  the union old/new affected writer cone
  3 prepare       prepare-boundary — the private lease; install the
                  candidate program event (ordinary compile through the
                  boundary planner, c2 registration included)
  4 heal          correctness-first: clear the affected cone's successor
                  slots, rerun candidate strata + surviving writers from
                  the base input boundary; replay mapped suffix batches
  5 recount/audit hold at the T5 pre-commit gate; recount the affected
                  epochs; the exact-once audit + (fires) records against
                  the successor RuleKeys
  6 publish|abort commit-boundary installs image+bindings+counts+recipe
                  event atomically; abort-boundary discards them together;
                  a latest-following reader crossing publication restarts
                  (T6), a pinned reader stays pinned (N3)
```

## 5. Slices

- **A1 — the fixture and its consumer.**  `compiler/activation.rkt`:
  parse/validate a `ProgramChangeSet` datum; the golden corpus
  (`tests/activation/*.pcs`) with at least: a minimal one-module rule
  change; a two-instance program replacing ONE instance (the RF5-B gate's
  shape, n1-style); each validation refusal.  Resolution to an
  `ActivationPlan` record with minted successor keys — no daemon contact.
  Gate: a unit battery over the corpus (accept/refuse per case; plan
  contents pinned; determinism: same fixture → same plan modulo layer).
- **A2 — the transaction over a live session.**  `session-activate!`:
  steps 3–6 composed from the shipped verbs, correctness-first route
  only; the abort path proven (abort at the gate leaves the base
  boundary byte-identical — catalog, sizes, counts, fires).  Gate: a
  battery driving the minimal fixture end to end — activate, hold,
  inspect, abort once, activate again, commit; reload the save and
  replay.
- **A3 — the RF5-B gate shape.**  The two-instance case: replace ONE
  instance's rules; prove the other instance's and every outside-cone
  VersionKey is REUSED; removed support disappears; counts equal a fresh
  recount; `why`/`whynot` before/after on one gained and one lost fact
  (the roadmap capstone's runtime half, minus the program-arc diffs).
- **A4 — the joint fixture freeze.**  The golden corpus + consumer
  handed to the program arc as the test ABI; schema changes from here on
  are joint-review (the ownership table's rule).

## 6. Deliberate cuts (recorded, not silent)

Precise healing routes (RF5-C) are out of scope — the correctness-first
route is the permanent fallback and the v1 route.  Historical suffix
replacement refuses (rf5 §8).  The `stats.*` namespace migration and the
full golden rekey stay on the stats stream.  Derived watches and R5
`whatif` are the join's OTHER side.
