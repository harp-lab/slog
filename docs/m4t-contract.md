# M4T recursive plain-table deletion contract

**Status:** implemented contract for the M4T vertical slices (slice 1
2026-07-13, slice 2 2026-07-14). `incremental.md` §4.5–§4.7 remains
normative; this file pins the admission, candidate lifecycle, and round
discipline needed to implement recursive deletion without weakening
fallback. The convention follows `m6l-contract.md`: everything not
explicitly admitted stays on clear-and-rerun.

As built, the sweep is the `_maint4neg` flavor (M3's negative partition
with the maintenance interner in DRed mode), the reseed is the
`dred-reseed` daemon action reporting `(dred-reseeded R D)`, and the
rebuild is the unmodified M1 positive walk. Slice 2 adds the
foundation-aware overlay verb `set-overlay-negative-dred` (reply
`(overlay-negative-dred R n n)`) for edits whose target relation is
dynamic in a recursive stratum, and admits multi-version chains on the
tip route.

Implementation exposed two latent substrate bugs this contract now
depends on having fixed:

1. maintained point mutations must cover every registered non-seeded full
   ordering, not only the running flavor's master, or another flavor's
   ordering silently goes stale and the sweep's all-orderings removal (or
   any later reader) sees partial content; and
2. clear-and-rerun must re-materialize the cleared relations' input
   baseline (direct assertions and unmasked inheritance) — the baseline
   is input, not a rule consequence, and re-derivation alone silently
   drops direct assertions on derived relations (§0.6's normalized
   overlay promise; `Relation::rematerializeInputBaseline`).

## Semantic state

The sweep introduces no new persistent structure. For one update epoch, a
**candidate** is a tuple that lost its foundation (`direct or nonrec > 0`)
during the negative phase. Its identity and state live in machinery the
epoch already owns:

- membership in the epoch's VersionId-keyed **negative transition journal**
  records that the tuple was over-deleted and marks it entered-at-most-once;
- its packed `input | nonrec | rec` **sidecar entry is retained** while any
  support remains, even though the row is absent from every live index, so
  later rounds can decrement its recursive support;
- a journal row whose sidecar entry is gone (or reaches zero) is a dead
  candidate with no surviving recursive support.

The live master indices, not the count sum, define membership during the
sweep: a candidate holds `rec > 0` while join-invisible. This intentionally
suspends, for the duration of the update epoch only, the invariant that a
sidecar entry implies a live row; the reseed phase restores it before the
epoch's commit-time coverage audit runs. Journals stay under the existing
epoch mutex and the update-valid flag stays atomic.

## Candidate lifecycle

Each tuple enters candidacy at most once per epoch:

```text
live
  --(negative fold leaves no foundation)--> over-deleted   (intern phase)
over-deleted: removed from master + all secondaries, journaled -1,
              retained as the next round's DeltaMinus witness,
              sidecar entry kept while support > 0
  --(later rounds may decrement rec; no re-staging, no invalidation)-->
at negative fixpoint:
  rec > 0  --(reseed)--> reinserted into all live indices, journaled +1
  rec = 0  --(discard)--> stays absent; sidecar key erased (zero has one
                          representation)
relearned during the positive rebuild: an ordinary M1 insert of a newly
  derived absent head, journaled +1
```

The **staging condition** is §4.5's: any lost support while
`not foundation(t)`, deliberately independent of `rec` and of a
count-derived presence transition. Support-only decrements (foundation
survives) touch the sidecar and do not stage — unchanged from M3.

The fold-policy differences from M3's `MaintainTask`, and nothing else:

1. the removal/journal/retain transition fires on **foundation loss**
   rather than presence loss (foundation loss implies presence loss when
   `rec = 0`, so acyclic heads inside a swept stratum degenerate to the M3
   behavior);
2. a contribution row that is **absent from live indices but has a sidecar
   entry** is a dead candidate: fold the decrement, keep or erase the entry
   by the resulting sum, do not journal, do not invalidate. An absent row
   with no entry still underflows loudly;
3. sidecar entries of over-deleted rows are **kept** while their sum is
   positive instead of being erased at presence loss.

## Round discipline and views

Rounds are the daemon's ordinary read → intern iteration, exactly as M3
already drives them: the intern-phase owner removes over-deleted rows and
retains them as the next iteration's negative delta, so round r's
DeltaMinus is precisely the candidates staged during round r−1.

The leftmost-deleted-occurrence partition is reused unchanged:

- `N` before the driver = plain FULL, which excludes the current drivers
  (removed at the previous intern) and all earlier candidates;
- `O` after the driver = `FULL ∪ DeltaMinus` (`join_probe_new`), which
  restores exactly the current drivers;
- candidates from earlier rounds appear in neither view, so no derivation
  is decremented twice across rounds.

These are §4.1's normative logical views. §4.5's prose describes the dual
physical layout (drivers stay in FULL through their round, with an
exclusion view for `N`); the shipped layout removes at intern time instead,
and §4.1 explicitly permits either physicalization. Removal happens in the
serial intern phase after the round's parallel reads complete, so no read
races its own round's deletions.

The sweep terminates when a round stages no new candidate. Checked signed
arithmetic is M3's; underflow or a liveness/support disagreement outside
rule 2 above invalidates the epoch.

## Foundation barrier

Strata are processed in topological order, so every lower-stratum relation
is settled before a sweep begins. Non-recursive rules read only settled
relations; all nonrec loss enters through the initially staged
upstream/direct transitions, and later rounds move only `rec`. Direct input
removal and inheritance masking happen through the normalized overlay
before the sweep, exactly as in M3.

## Phase schedule, reseed, and rebuild

The epoch keeps M3's two-phase cone schedule with one new step between the
phases:

1. **Negative walk** (cone-wide, topological): each acyclic stratum runs
   `_maint3neg`; each certified recursive stratum runs the sweep flavor.
   Downstream strata stage their premise DeltaMinus from the journals while
   every journaled row — including rows that reseed will later restore — is
   genuinely absent from FULL. This ordering is load-bearing: staging a row
   as DeltaMinus while it is live in FULL breaks the exact partition
   (a self-join instantiation pairing it with a dead driver would be
   decremented at two occurrences).
2. **Reseed** (per swept stratum, after the whole negative walk): scan the
   stratum's journaled rows; reinsert every survivor with `rec > 0` into
   all live indices and journal it +1; erase the sidecar keys of the rest.
   Reseed adds no support contribution — surviving counts are already
   correct.
3. **Positive walk** (cone-wide, topological): the existing M1 `_maint1`
   fixpoint, driven by the reseeded transitions plus the epoch's positive
   edits through the exact rightmost-new-occurrence partition. The
   simultaneous reseed batch restores cross-candidate derivations exactly
   once: at negative fixpoint each survivor's `rec` counts only
   live-premise derivations, and the partition adds back precisely the
   instantiations through reseeded premises. Discarded tuples rederived
   from a reseeded premise are relearned by M1's ordinary
   insert-and-journal behavior. The positive walk runs whenever reseed
   restored anything, even for a negative-only user batch.

A tuple that was over-deleted and then reseeded or relearned therefore
reaches downstream strata in both journals — an exact cancelling cascade:
the downstream negative pass decrements through it while it is absent, and
the positive pass restores exactly those instantiations. Net-transition
filtering (dropping such rows from both journals) is a later optimization
and is only sound for rows already restored before downstream negative
staging; it is out of scope for this slice.

## Admission ladder

Slices 1+2 admit:

1. a counted, positive-arity, positive-only plain-table cone whose strata
   are each either certified acyclic (M3 machinery) or a certified
   recursive plain-table SCC (this contract), in any topological mix;
2. reached by a tip-local edit. Multi-version chains are admissible:
   `cone-of`'s rebound guard diverts any cone containing a mid-cone
   version edge (a relation rebound after a cone stratum) to the anchored
   walk, so on the tip route every inherited contribution is a stable
   nonrec barrier owned by a settled predecessor — it can leave only
   through an explicit mask edit, never through the sweep;
3. edits may target a relation dynamic in a recursive stratum: the apply
   uses the foundation-aware verb, whose fold is exactly the sweep's —
   support-only decrement while another foundation survives; candidacy
   (row leaves live indices, journaled −1, sidecar entry retained) on
   foundation loss with `rec > 0`; ordinary presence loss at zero. Edit
   candidates enter the epoch's journal before the walk begins, so
   staging, dead-candidate absorption, reseed, and relearn treat them
   like any sweep-staged candidate;
4. with no lattice relation, negation edge, struct relation, nullary
   relation, diagnostic/fallible head, or unsupported side-channel kind
   anywhere in the cone.

Fully acyclic cones keep the M3 route; the recursive route is preferred
only when the cone contains at least one recursive stratum. Everything
else falls back by name:

- structs (M5/M4S), lattices anywhere in the cone (M6L/M7 own their
  shapes), negation (M4N), nullary relations;
- mid-cone version edges (rebound guard → anchored walk) and
  historical/back-anchored edits (anchored walk);
- uncounted or capability-uncertified cones;
- arithmetic, coverage, or writer failure mid-epoch, which invalidates the
  cache and completes through the normalized-overlay clear-and-rerun path
  before the epoch commits.

## Required fixtures

Executable deterministic cases, first landed asserting fallback
correctness and route reporting, then flipped to the precise route:

- `tests/session/m4t_symmetric_cycle.slog` — §5.2: `r(y,x) :- r(x,y)` over
  a copy rule; retracting the direct input must delete both tuples even
  though each retains positive `rec` in pure proof counting.
- `tests/session/m4t_diamond.slog` — §5.3: transitive closure over a
  diamond with a tail; deleting one foundation route over-deletes
  `path(1,4)` (rec 2 → 1, foundation 0), which drags `path(1,5)` to zero;
  reseed restores the first, relearn restores the second.
- `tests/session/m4t_bridge.slog` — two recursive SCC strata joined by an
  acyclic bridge: the cancelling cascade crosses both boundaries and the
  downstream SCC runs its own sweep from staged transitions.
- `tests/session/m4t_selfjoin.slog` — closure by self-join
  (`r(x,z) :- r(x,y), r(y,z)`) over a data cycle: repeated occurrences of
  the swept relation exercise the round-indexed partition, and a
  rec-founded survivor (`r(2,1)` after the cycle is cut) is over-deleted
  and reseeded from surviving recursive support.
- slice 2, head edits: a zero-rec direct deletion degenerating to plain
  presence loss inside the sweep epoch; a direct deletion of a
  derived-and-asserted row (candidacy at apply, reseed from surviving
  recursive support, downstream relearn); and the unfounded pair fed by a
  direct head assertion, which presence semantics would strand;
- slice 2, inheritance: masking an inherited input tuple at a reopened
  tip (successor sweep runs; every inherited row is a support-only
  barrier; nothing reseeds); masking an inherited row of the recursive
  head itself (candidacy, reseed from successor-local recursive support,
  mask persists while presence returns through derivation); and the
  clear-and-rerun input-baseline regression;
- named fallback fixtures: lattice in the cone, negation over an SCC
  member, a mid-cone version edge (rebound guard → anchored walk), and a
  historical anchor.

Every case compares settled content and every support component with a
fresh recomputation plus forced recount, per §10's two oracles and the
cross-flavor check.

## Concurrency and observability

The journals and sidecars keep the M1/M3 locking rules; the sweep adds no
new shared state. Route messages distinguish the phases:
`(route maintain-recursive-negative N)` for the sweep walk, a reseed report
naming restored and discarded counts per stratum, and the existing
`(route maintain-positive N)` for the rebuild; fallback stays named.
Capability reporting is unchanged — plain-table recount capability is a
local mechanism, and cone admission remains the driver's topology
certificate, reported through the route.

Randomized hardening mirrors M3/M6L: warm maintained sessions over cyclic
graphs for ten epochs against independent fresh recount oracles under one,
two, and eight workers, with forced pauses attributed to the sweep and
rebuild phases and at least one case crossing the runtime split-batch
boundary. Since slice 2 the stream also toggles one direct assertion on
the recursive head per flush (only rows the stream asserted are ever
retracted), and the forced-pause epoch mixes head-row and edge deletions
in a single sweep.
