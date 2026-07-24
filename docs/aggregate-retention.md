# Aggregate retention spectrum: agg trees, heaps, and truncated top-k

**Status:** exploratory design note (2026-07-23). **Not on the near-term
roadmap** — nothing here gates M7, and no milestone implements it yet.
[m7-contract.md](m7-contract.md) ships full contributor retention; this file
pins the vocabulary, the correctness discipline, and the seams so a truncated
variant can be built later as a bounded experiment behind the same repair
seam, per the contract's revisit clause and `incremental.md` §7A.3.

## The retention spectrum

Repairing a lattice regression means answering "what is the best surviving
contribution for this key?" The design space is a spectrum in how much
retained state backs that answer:

- **Full retention (M7's ratified choice).** Every distinct `(key, payload)`
  contributor row is retained with its support word. Repair is a lookup over
  retained state; memory is O(distinct contributions).
- **Localized recompute.** No retained losers; repair re-derives the affected
  key's feeding region. Memory-free, but in a recursive cone the feeding
  region can approach the whole SCC, and bounding it exactly is new
  machinery.
- **Truncated retention (this note).** Retain the k best contributors per key
  plus a watermark; repair is a lookup while headroom lasts and a region
  recompute (a *refill*) when it runs out. This interpolates the two poles:
  roughly k contributor deaths of precise-repair headroom per key before the
  worst case reappears.

Vocabulary note: our "k" is the *buffer* size — Yi et al.'s k_max/headroom.
Their k is the answer arity the view must serve, and a min/max lattice value
is their k = 1 special case (one visible value per key). If a future lattice
payload is itself a top-k list (a k-bounded-merge over collections), the
buffer becomes answer-k plus headroom; the discipline is unchanged.

## Monoid taxonomy: who needs which structure

The aggregation-tree observation sorts fold shapes into four classes; the
right structure differs per class.

1. **Group-like folds** (integer SUM/COUNT, AVG as a (sum,count) pair):
   inverses exist, so deletion subtracts from the running value. No
   contributor retention is needed at all. These are M6A shapes, not
   lattices, and are already excluded from M7.
2. **Selective joins** (min, max, argmin and lexicographic variants — the
   "conservative"/"absorptive" case: the join of two elements *is* one of
   them; "selective" is the standard algebra term, as in selective
   semirings). An aggregation tree's internal partial aggregates are all
   copies of leaves, so the tree is spatially redundant; a heap collapses it
   by letting the raw elements structurally serve as the aggregates of their
   own subtrees. In our runtime this collapse is already physically present:
   the M6L contributor sidecar is an ordered index keyed by the full
   `(key..., payload)` row, so the boundary live row of a key range *is* the
   value and the next live row *is* the repair answer. (Today's
   `reduceLatticeContributorKey` re-folds all live contributors per key; a
   boundary-row fast path is a local optimization inside the same seam, not
   a design change.) Full retention therefore already has the collapsed-heap
   *time* bound — truncation is purely a *memory* play, and it is exactly
   this class it applies to.
3. **Idempotent non-selective joins** (set, map): the value is not one input,
   so no heap collapse — but contributor rows with support words already
   make repair an exact re-fold over live contributors, with no watermark
   subtlety (idempotence means nothing discarded can ever matter more than
   what is retained... unless rows are discarded, so truncation does NOT
   apply). An aggregation tree could speed the re-fold; it adds no
   correctness machinery.
4. **Non-invertible, non-selective, non-idempotent folds** (floating-point
   sums where subtraction is numerically unsafe, products with zero
   divisors): the only sublinear repair is a genuine aggregation tree of
   partial aggregates with O(log n) refold. All such shapes are M6A
   territory; if M6A ever ships them, the agg tree belongs there. Truncation
   does not apply — every input matters.

Summary: aggregation trees are the class-4 tool (future M6A); heaps/ordered
indexes are the class-2 structure and we already have them; truncated top-k
is the class-2 memory optimization.

## Truncated top-k needs a watermark

Retain per key the k best live contributor rows and a watermark `h` — the
best payload evicted or discarded since the last refill.

- **Insert:** if the payload beats the k-th retained row — or there is room
  *and* it beats `h` — retain it, folding any evictee into `h`. Otherwise
  fold it into `h` and drop it.
- **Delete:** kill retained rows through their support words as usual.
- **Repair:** if the best surviving retained payload is at least `h` in the
  join order, it is the exact value. Otherwise — or if nothing retained
  survives — refill.
- **Refill:** recompute the key's true contributor set via the fallback
  route (in a recursive cone, the cone recompute), retain the top k, and
  reset `h` to the best value *not* retained (bottom if fewer than k exist).

The watermark is not optional. Counterexample (max, k=2): insert 10, 8 →
retained {10, 8}; insert 7 → discarded; delete 8 → retained {10}; insert 6 →
there is room, so naive truncation admits it → {10, 6}; delete 10 → naive
answer 6, true answer 7. With `h = 7` the 6 is never certified and the
second deletion triggers a refill instead. The counterexample pins two
rules: never certify a retained row below `h`, and `h` only rises between
refills.

A simpler equivalent discipline (Yi et al., see lineage): never backfill at
all — let the retained set shrink on deletions and admit only payloads that
beat the *current retained minimum*, which is then non-decreasing between
refills and acts as an implicit watermark. That variant needs no stored `h`
(one fewer sidecar scalar) at the cost of ignoring payloads in `(h, min)`
that our rule would retain. Both are sound; pick at implementation time.
Yi et al. also note the refill can run *eagerly* — triggered at low
headroom rather than at exhaustion — so the cone recompute happens off the
critical path while precise answers continue from the remaining rows; that
composes naturally with our background-upgrade patterns.

**Headroom and storms.** Headroom is ~k contributor *deaths* per key between
refills — in a recursive cone one input deletion can cascade into many
contributor deaths at once (DRed candidates kill derived contributors), so
headroom is measured in contributor transitions, not user edits. A hub
deletion can push many keys below watermark in one epoch (a refill storm),
but the refill route is the cone recompute we already amortize like a
rebuild, and it resets headroom for every key it touches.

**Conservatism in an SCC.** A discarded contributor may itself have died
since discard; `h` is then stale-high and can force a refill for a value
that no longer exists. That is safe, mildly wasteful, and self-corrects at
refill.

**Persistence.** A truncated cache cannot be re-established "from the exact
historical writers" without replay; its load-time re-establishment *is* a
refill. That matches the standing rule — caches are recomputable, loads
either re-establish exactly or fall back — with refill as the
re-establishment route.

## Where rank sits

The M7 rank witness is already the opposite pole: it stores top-1 (the best
surviving rank) and repairs by localized recompute over the candidate cone's
live contributors (a recursive min of neighbor ranks). Truncation should
target value contributors first; extending it to rank (retain k best depths
per tuple) is possible but rank changes propagate along derivation chains
even when membership doesn't, so refill rate likely dominates the savings.
Measure values before touching rank.

## What M7 slice 1 must preserve (the only near-term obligation)

- Repair consults contributors only through the next-surviving-value/rank
  seam; no caller assumes contributor-set completeness as an ambient fact.
- Retention class is a *certified property* of the sidecar — `complete`
  today; `truncated (k, h)` later — reported through
  `(lattice-contributor-state ...)` beside the existing certification bits.
- The replacement-transition logic stays agnostic to whether the new value
  came from a lookup or a refill.

Given those, the later experiment is bounded, not a redesign: an eviction
arm in the existing contributor fold, one watermark scalar per key (a
sidecar kind), one admission check in repair, the refill route aliased to
the existing fallback, an env knob for k (the `SLOG_ACCEL_*` pattern), and
the existing differential + fuzz + sidecar-memory gates as the rig.

## Cost model sketch (when to bother)

Memory win ≈ (distinct contributions per key − k) rows; the regression cost
is refill_rate × cone-recompute. Truncation wins when contributor sets are
wide (dense in-degree under min/max) and per-key regressions between refills
are rarer than k. M7's sidecar-memory exit gate produces exactly the numbers
needed to decide whether this experiment is ever worth running.

The buffer-sizing theory exists (Yi et al. 2003, random-walk hitting-time
analysis of exactly this headroom scheme): with balanced insert/delete
pressure on a key, headroom n = N^(1/2+ε) over N contributions makes the
expected refill interval exceed N updates with high probability — e.g. their
table shows 0.45% of a million-row domain buys a >10^6-update refill
interval at 99.98% — and with insert-dominant pressure (the common Datalog
case: facts mostly accrete) n = O(log N) suffices. The converse is the
admission caveat: under *deletion-dominant* pressure the walk is absorbing
and no sublinear buffer helps (they need n = Θ(N)), so the future experiment
should consult observed insert/delete ratios (the `$stat_fires` tables)
before enabling truncation on a cone, and prefer full retention there. One
transferable nuance: their refill is an O(N) base-table scan, while ours is
a cone recompute that can cost far more — their analysis bounds refill
*frequency*, which is precisely the quantity our heavier refill makes
matter; it argues for generous k and eager refill on our side. Their §7
runtime procedure for adapting k_max to the observed workload without prior
knowledge is the shape a per-relation auto-tuned k would take here.

## Research delta over the 2003 result

Yi et al. live in a flat, stored, non-recursive world: one base table,
values updated in place, truth re-readable by scan. If this experiment ever
graduates to a publication, the claimable delta is:

1. **Soundness where truth is derived, not stored** — truncated retention
   with certified exactness under least-fixpoint semantics, where "live" is
   foundedness, retained rows die via cascades, and the watermark is
   conservatively stale. The warehouse literature never left stratified SQL.
2. **Correlated-cascade buffer sizing** — their memoryless independent-walk
   model misses that one input deletion kills contributors across many keys
   at once, and that one key's regression drives deaths at downstream keys
   (coupled walks), under batched epochs rather than tuple-at-a-time.
3. **Rank unification** — foundedness rank as a recursive-min instance, so
   the buffer doubles as *scheduling state* for the deletion algorithm
   (rank-unchanged corpse-fire exclusion), with exactness extended to
   DRed^c counts, not just view content.
4. **Systems** — per-key headroom under a global sidecar-memory budget from
   always-on stats (their §7 adapts a single view), shared refills (one cone
   recompute resets headroom for every key it touches), eager refill under
   pause/budget machinery, differential-oracle validation.

Before claiming novelty, sweep: IncA's incremental lattice analyses,
differential dataflow / DBSP (full input collections retained for
reductions), Materialize's hierarchical reduction trees (the class-4
agg-tree choice, forced because streaming systems cannot refill — no base
to re-scan; we CAN refill via the cone recompute, which is what makes
truncation available to us at all), and F-IVM-style factorized aggregate
maintenance. Current read: streaming keeps full state, warehouses truncate
only over stored flat tables — recursive + truncated + certified-exact
appears unclaimed. Timing: after M7 ships full retention and the memory
gate produces the motivating numbers.

## Lineage (citations verified 2026-07-23)

- D. Quass, A. Gupta, I. S. Mumick, J. Widom, **"Making Views
  Self-Maintainable for Data Warehousing,"** PDIS 1996, pp. 158–169. The
  self-maintainability concept: augment a materialized view with auxiliary
  views so maintenance never re-queries the sources. The auxiliary-data
  idea our contributor sidecar instantiates.
- K. Yi, H. Yu, J. Yang, G. Xia, Y. Chen, **"Efficient Maintenance of
  Materialized Top-k Views,"** ICDE 2003 (Duke). Exactly the truncated
  scheme above: maintain a top-k′ view with k′ floating in [k, k_max],
  shrink on deletions, refill only when k′ < k, with a random-walk model
  giving the buffer-sizing and amortized-O(1)-refill results quoted in the
  cost sketch, plus a runtime procedure for choosing k_max adaptively.
- Context, optional: I. S. Mumick, D. Quass, B. S. Mumick, "Maintenance of
  Data Cubes and Summary Tables in a Warehouse," SIGMOD 1997 (summary-delta
  maintenance of aggregates; MIN/MAX deletions recompute affected groups);
  T. Palpanas, R. Sidle, R. Cochrane, H. Pirahesh, "Incremental Maintenance
  for Non-Distributive Aggregate Functions," VLDB 2002 (the "work areas"
  scheme — the same headroom idea, developed independently of Yi et al.,
  without the sizing analysis).

"Selective" for joins returning one of their arguments is standard semiring
vocabulary; tournament trees and heaps as collapsed aggregation trees are
classical.
