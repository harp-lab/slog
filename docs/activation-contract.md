# The activation spine — the runtime arc's pre-join deliverable

*Drafted 2026-08-12 (W5′ runtime/transaction arc, after T3b, T0(c), T6,
and the N5/stats-4 identity unification closed).  **Status: A1–A4 ALL
SHIPPED 2026-08-12 (as-built in §5); **the RF5-B join is COMPLETE
2026-08-13** — the first joint battery (tier `rf5-join`) runs the
producer's regenerated fixtures through this consumer, the suffix replays
live, and the §10 cases are pinned (tier `rf5-gate`); the original plan
(the first joint
battery, §6).**  Normative parents:
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

**FROZEN 2026-08-12 (slice A4).**  Per rf5 §10.1, serialized as one
s-expression datum; this contract pins the concrete spelling the goldens
use.  From this date the schema and the golden corpus are JOINT-REVIEW
(roadmap's ownership table): any change to the grammar below, to
`compiler/activation.rkt`'s acceptance behavior, or to a corpus file is a
sanctioned two-arc event, re-recorded via
`tests/activation-freeze.sh --record` as part of that review — never
unilaterally.  §6 is the handoff: what the program arc's producer gates
on.

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
  4 heal          correctness-first: the affected cone's successor slots
                  are SEVERED from inheritance (fresh-empty, the plan's
                  `sever` predecessor token) and the candidate strata
                  recompute them from the base's carried inputs; replay
                  mapped suffix batches
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
  *As built (2026-08-12): `compiler/activation.rkt` + five fixtures +
  `activation-tests.rkt` 12/12.  The plan allocates version rows for
  every union writer PLUS every slot-lineage relation, so a carried
  non-writer — the untouched instance's slots — gets an explicit reuse
  row: the RF5-B outside-cone claim is checkable in the plan itself,
  before any daemon exists.  All eight refusal types driven; resolution
  proven pure; parse failures typed at parse, never at resolve.*
- **A2 — the transaction over a live session.**  `session-activate!`:
  steps 3–6 composed from the shipped verbs, correctness-first route
  only; the abort path proven (abort at the gate leaves the base
  boundary byte-identical — catalog, sizes, counts, fires).  Gate: a
  battery driving the minimal fixture end to end — activate, hold,
  inspect, abort once, activate again, commit; reload the save and
  replay.
  *As built (2026-08-12): `session-activate!` in `compiler/session.rkt`
  builds the base-env from the head boundary plan's catalog, resolves via
  A1's consumer (every refusal surfaces pre-mutation), writes candidate
  sources under `out/activation/`, and runs the candidate as an ordinary
  boundary-planned event under two parameterizations: the prepare hook
  (fault injection for the abort gate) and **severed inheritance** — the
  activation's REBUILT relations pass `#:sever` to the boundary planner,
  which records the literal predecessor token `sever` in the plan datum.
  The daemon materializes a severed slot fresh-empty instead of cloning
  the latest binding (the correctness-first heal: removed support cannot
  survive because nothing is inherited), while the old version stays
  addressable history; replay re-derives the sever from the persisted
  datum, and the boundary bundle records the severed slot's lineage as
  `#f` — version-graph truth.  Retired strata (pre-strata whose heads
  are all rebuilt) drop from the resident set post-commit; a retire
  stratum that also heads a carry refuses as `activation-unsupported`
  *(superseded by A3: retirement is now plan-derived inside the run and
  the closure handles mixed strata — see the A3 as-built below)*.
  Two latent pre-A2 bugs were exposed and fixed by the abort gate:
  (1) `abortPreparedBoundary` nulls registry slots that six daemon loops
  (`finalizeAll`/`reorgAll`/`ensureReorgBuffers`/`initShards`/`bindRun`)
  iterated unguarded — abort-then-run segfaulted; (2) the recipe step
  recorded BEFORE the boundary transaction, so a survivable abort left a
  phantom `run` step that replay would re-execute (minting a program
  record the bundle never stored) — the group abort handler now restores
  the pre-run step snapshot, while the burned event reservation stays
  burned.  Gate: `tests/activation-live.sh` 8/8 — abort atomicity (base
  byte-identical), commit with removed support gone (path 6→3) and the
  carried relation intact, plan/minter key agreement, and save→reload
  replay convergence through the severed boundary.*
- **A3 — the RF5-B gate shape.**  The two-instance case: replace ONE
  instance's rules; prove the other instance's and every outside-cone
  VersionKey is REUSED; removed support disappears; counts equal a fresh
  recount; `why`/`whynot` before/after on one gained and one lost fact
  (the roadmap capstone's runtime half, minus the program-arc diffs).
  *As built (2026-08-12): the activation now restricts the event's WRITE
  SET to the affected cone at **stratum granularity** — the sever set
  closed over cohabitation, since strata cluster SCCs by level and a
  rebuilt relation can share its stratum with a carried one.  Everything
  outside the closure is simply not written by the event, so the planner
  ALIASES its version: outside-cone VersionKey reuse holds by
  construction, not by comparison.  Three plan-derived mechanisms make
  this replay-honest (the create actions of a severing plan ARE the
  cone): `replay-boundary-plan` narrows the group's write set to the
  datum's creates; the run pushes only cone strata; and after a severing
  commit every pre-event stratum heading into the cone retires from
  liveness (a survivor re-entered at the tip would bind the replaced
  image's rules to the severed successor).  Versions superseded at a
  severing boundary leave the count domain (the plan's "invalidated
  count epochs"; exact-or-absent: absent) — the recount walk excludes
  them by matching the plan's created VersionKeys, so post-activation
  counts equal a fresh recount, gated.  A cohabitant that must rebind
  (an inherited clone) is narrated as `carried-rebound`, distinct from
  both `rebuilt` (severed) and `carried` (aliased); a resident stratum
  PARTIALLY inside the closure refuses typed as
  `activation-unsupported` before any recipe record or daemon mutation
  (this supersedes A2's per-rebuild retirement and its torn-stratum
  refusal).  The debugging leg drives REPL `why`/`whynot` and the
  session verbs against ONE session (`ensure-session!` joined the test
  surface): `whynot` is the pure frontier over committed state and
  works on both sides unaided; `why` follows the T5 capture workflow —
  arm `watch REL level 1 why`, re-derive monotonically
  (`session-rerun!`), ask — and the post-activation watch re-arms at
  the severed successor's fresh version.  Gate:
  `tests/activation-a3.sh` 17/17 (reuse both ways, narration pinned at
  2 rebuilt / 3 carried / 1 rebound / 2 retired, removed and gained
  support, carried instance row-identical, count equality around
  `recount-force`, plan/minter agreement, replay convergence, six
  why/whynot legs).  Residues, recorded: candidate sources persist
  under `out/activation/` and a reload replays from those paths — an
  `out/` wipe orphans the recipe; `recount-at` positions preceding a
  severing boundary walk empty version sets rather than refusing
  typed.*
- **A4 — the joint fixture freeze.**  The golden corpus + consumer
  handed to the program arc as the test ABI; schema changes from here on
  are joint-review (the ownership table's rule).
  *As built (2026-08-12): `tests/api/pcs-check.rkt` — the standalone
  conformance checker (§7) with NO session or daemon dependency — plus
  the corpus manifest `tests/activation/CORPUS.sha256` and the
  `activation-freeze` tier (9 checks in ALL): manifest of record,
  pinned accept/refuse verdicts per corpus file, and verdict
  determinism.  The corpus at freeze: seven fixtures — minimal,
  two-instance (the RF5-B shape), suffix-batch, and the two LIVE
  templated forms driven end to end by the A2/A3 batteries, plus the
  two refusal carriers (fixture-refusal,
  historical-program-replacement).*

## 6. The handoff (what the program arc's producer gates on)

The producer's conformance surface is ONE tool and ONE battery, neither
of which touches a session or a daemon:

```text
racket tests/api/pcs-check.rkt FIXTURE.pcs
  -> (accepted (program K) (rebuild N) (carry N) (retire N) (suffix N))   exit 0
  -> (refused TYPE DETAIL ...)                                            exit 1
bash tests/activation-freeze.sh          # corpus manifest + pinned verdicts
```

`pcs-check` substitutes the templated placeholders against the SYNTHETIC
base identity (`p1:layer-base:0` / `b1:layer-base:0`; `@V:rel@` mints
`v1:layer-base:0:N` per distinct relation) and builds the base
environment from the fixture's own slot-lineage rows — exactly what a
live catalog would answer — then resolves with A1's `resolve-activation`
at `layer-new`/event 1.  The determinism claim (same fixture → same
plan) makes its verdicts comparable across harnesses: a fixture the
producer emits is CONFORMANT iff pcs-check accepts it, and the typed
refusal it prints is the same refusal `session-activate!` would surface
live.  The three fixture rules (§2) remain the producer's contract: no
live VersionIds/routes/decisions, no inferred lineage, typed refusals
ride along.

The first joint battery (the RF5-B join's opening move) runs the exact
golden corpus through BOTH sides — the producer regenerating each
fixture from its diffs, this consumer resolving them — so the fixture
cannot drift into a parallel informal ABI (roadmap §6's rule).  The live
templated forms (`minimal-live.pcs`, `two-instance-live.pcs`) are the
join's executable examples: the A2/A3 batteries drive them through the
full transaction, and the placeholder convention (`@BASE-PROGRAM@`,
`@BASE-BOUNDARY@`, `@V:rel@`) is how a fixture written before a layer
exists names that layer's keys.

## 7. Deliberate cuts (recorded, not silent)

Precise healing routes (RF5-C) are out of scope — the correctness-first
route is the permanent fallback and the v1 route.  Historical suffix
replacement refuses (rf5 §8).  The `stats.*` namespace migration and the
full golden rekey stay on the stats stream.  Derived watches and R5
`whatif` are the join's OTHER side.
