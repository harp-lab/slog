# Local worst-case-optimal joins

*(Started 2026-07-14; updated after the first production implementation.  Slog
now has an automatically selected key-simple ternary cycle closer over its
existing sorted indices.  The later sections deliberately retain the roadmap
for batching, resumability, grouped expansion, and larger cyclic islands.  This
document does not claim a worst-case-optimality guarantee for every rule.)*

## 0. Current implementation status

The conservative `Expand3`/`join3` slice described in this document is now
implemented and enabled by default:

  - `compiler/join-actions.rkt` gives normalized positive occurrences stable
    rule-local IDs and represents occurrence views and physical join actions;
  - `compiler/join-planning.rkt` assigns DELTA/FULL/OLD/NEW from original
    dynamic-occurrence order, searches action schedules for compute-free bodies
    of at most eight occurrences, and enumerates legal drivers for small closed
    and seeded rules;
  - `compiler/operationalization.rkt` treats the two arms as one grounding
    transition, requisitions their prefix indices, preserves identical
    FULL/DELTA orders for OLD/NEW, and lowers one explicit `join3` C operation;
  - `compiler/emit-cpp.rkt` emits independently ordered/viewed arms; and
  - `daemon/operators.h` implements FULL, OLD difference, and NEW sorted-union
    prefix cursors plus a symmetric hybrid sequential/`lower_bound` leapfrog.

Automatic selection remains intentionally narrow.  Both arms must be ordinary
set tables with exactly one common free stored column and no other free/payload
column; each must have a non-empty bound prefix; the already-consumed positive
occurrence graph must certify a real cycle between distinct anchors; and an
ambiguous group of three or more eligible arms is left scalar.  A body compute
that remains after the constant pre-phase also keeps the current scalar plan.
Unsupported rules are not errors.  They follow the unchanged greedy pipeline.

This first implementation uses Slog's existing coarse-grained batch
parallelism: outer driver partitions are claimed by workers, every worker opens
read-only prefix cursors for its current environment, and matches flow directly
into its existing thread-local output batches.  There is not yet a separate
array of environment descriptors or a pause/resume point inside a single
`join3` call.  Explicit 64/128-environment batching and value-key continuation
state remain follow-up work; Section 12 and Section 13 are the design for that
work, not claims about the current runtime.  The fused callback can safely run
after an arbitrary scalar prefix because those locals remain on the generated
C++ stack; moving that prefix across a future batch/pause boundary will require
the live-environment descriptor described below.

The initial key-simple scope also does not need a new general `AccessNeed`
record yet.  Since an eligible arm has arity `K+1`, requiring its `K` bound
columns as an index prefix necessarily puts the sole remaining cycle column at
position `K`.  Lowering asserts that fact, and OLD/NEW reuse the existing
same-complete-order constraint.  The explicit ordered-next-column contract in
Section 8 is still required before grouped or multi-free-column operators.

The cache-keyed escape hatch is `SLOG_NO_WCOJ3=1`.  The bounded-search cap is
also part of the compiled artifact key.  Scalar differential runs remain the
correct first diagnostic for any suspected planner or maintenance issue.

### Production measurements

The checked-in `bench/wcoj-bench.sh` compares optimized scalar and `join3`
plans on identical data and diffs every result relation.  On the development
machine with eight workers, three-repetition medians were:

| workload | scalar ms | `join3` ms | speedup | result |
|---|---:|---:|---:|---|
| disjoint high-degree hub | 4,334.169 | 10.957 | 395.56x | identical |
| 500k-edge bipartite triangle | 318.212 | 92.708 | 3.43x | identical |
| 600k-edge Erdős-Rényi triangle | 404.614 | 326.356 | 1.24x | identical |
| 200k-edge Erdős-Rényi 4-cycle | 470.031 | 396.190 | 1.19x | identical |
| TinyCFA 0CFA control | 17.686 | 15.397 | 1.15x | identical; no rewrite |

The hub `join3` median at 1/2/4/8 workers was 18.511/18.840/12.947/9.933 ms.
At this small absolute runtime, process and fixed scheduling costs are visible;
the important result is that the operator participates in the existing outer
driver parallelism without a private scheduler.

## 1. Recommendation

Add worst-case-optimal join (WCOJ) support as a family of **local physical
operators**, not as a replacement for Slog's rule planner.  The first and most
valuable member should combine a ground outer binding with two relation
occurrences that share one unbound variable:

    tri(A, B, C) :- R(A, B), S(B, C), T(A, C).

After a driver row from `R` binds `A` and `B`, the operator opens the `C`
ranges of `S[B, *]` and `T[A, *]` and intersects them.  Call this operation
`Expand3` in the planner and `join3` in the first C IR/runtime implementation.
It consumes the two logical relation occurrences together and binds `C` only
for values present in both.

This is the right first cut because it:

  - removes the intermediate that hurts the realistic cyclic workload we have
    measured;
  - maps directly to Slog's immutable, lexicographically sorted B-tree indices;
  - preserves the existing outer-driver parallelism and fused downstream
    pipeline;
  - can be selected conservatively and fall back to the ordinary binary plan;
  - is the useful ternary primitive in the Lookup/Expand decomposition of
    Diamond Hardened Joins (DHJ), without requiring that we implement all of
    DHJ or generic trie join first.

The compiler should eventually find small cyclic *islands* inside a rule,
lower those islands to Lookup/Expand actions, and leave acyclic fringes,
computations, guards, lattices, and unsupported relation shapes on the current
path.  It should only claim that a selected local operator avoids a particular
binary intermediate.  It must not advertise the rule, stratum, or program as
globally worst-case optimal.

## 2. Why this is the next performance feature

The current generated pipeline range-probes one relation at a time.  An
expanding probe enumerates all matches and invokes the rest of the pipeline for
each.  Semijoin existence filters can reject an outer binding before that
expansion, but they cannot help when both arms have some match and only their
sets of possible next values are incompatible.  Dense cyclic queries are the
important remaining case.

The most severe example found so far used two high-degree arms with disjoint
cycle keys.  The binary plan visits a quadratic candidate intermediate even
though it produces no output.  The production measurements in Section 0 show
that ordered-prefix intersection retains a roughly 396x win on that shape and
a 1.24x win on the ordinary 600,000-edge Erdős-Rényi graph, with identical
outputs.

The measurements establish two things:

  1. avoiding the cyclic intermediate is much higher leverage than tuning the
     existing nested callbacks; and
  2. the production kernel must use seeking/leapfrog behavior, not blindly
     merge both complete prefix ranges.  A skewed identifier assignment can
     make one range enormous and the other tiny or positioned near its end.

The semijoin benchmark `bench/tri_bipartite.slog` already records the boundary:
prefix-existence checks pass, while value-set intersection is what the query
needs.

## 3. Scope and explicit non-goals

### Initial scope

The first automatically selected operator should handle a **key-simple local
intersection**.  At a planning frontier with ground variables `G`, two pending
positive relation occurrences `L` and `R` are eligible when:

    C = (vars(L) intersection vars(R)) - G

has exactly one variable, and every variable in either occurrence is in
`G union C`.  In addition:

  - each arm has a non-empty ground prefix;
  - `C` is a direct stored column in both relations;
  - both arms use ordinary set/table indices;
  - neither arm is the outer driver;
  - all columns other than `C` in each arm are already ground;
  - the required FULL/DELTA/OLD/NEW cursor view is implemented; and
  - no computation is needed inside the lookup key.

Because each arm's complete tuple is determined by its bound prefix and `C`, a
set relation has at most one matching tuple per `C`.  This avoids duplicate-key
grouping and payload cross-products in the first kernel.

The common positive-maintenance triangle versions are then:

    driver DELTA R(A,B): intersect S_old[B,C] with T_old[A,C]
    driver DELTA S(B,C): intersect R_full[A,B] with T_old[A,C]
    driver DELTA T(A,C): intersect R_full[A,B] with S_full[B,C]

The words `full` and `old` above are logical occurrence views, not consequences
of physical action order.  Section 6 makes that distinction precise.

### Not promised

This project does **not** initially promise:

  - generic WCOJ (Generic Join/LFTJ) for arbitrary hypergraphs;
  - an AGM-bound guarantee for every rule;
  - an optimal variable order or an optimal whole-rule plan;
  - n-way intersection when three or more arms share the next variable;
  - factorized payload enumeration;
  - WCOJ over lattices, temporary relations, negation, structs, or computed
    lookup keys; or
  - distributed/HyperCube repartitioning.

Unsupported shapes retain the existing plan.  A rule may contain one `join3`
island and otherwise use normal scalar joins.  A complex cyclic rule may get no
WCOJ operator at all.  That is a sound and useful product boundary.

## 4. Current compiler contracts that the change must respect

The implementation cannot safely be a late peephole over emitted C operations.
Several logical facts are available, or still mutable, only in join planning.

### Scheduling today

`plan-rule-versions` in `compiler/join-planning.rkt`:

  1. normalizes repeated variables in one atom into fresh variables plus
     equality guards;
  2. chooses a driver for each semi-naive version;
  3. calls `schedule-body`, which greedily picks one pending join at a time;
  4. eagerly places newly enabled guards and demand-places computations; and
  5. wraps scheduled occurrences after the driver in `$oldjoin` or `$newjoin`
     when exact semi-naive maintenance requires it.

`compiler/operationalization.rkt` then walks that scalar schedule twice: once
to collect index selections and once to lower operations.  Semijoin filtering
also models join positions in that linear schedule.

### The invariants

Any WCOJ plan must retain these invariants:

  - The first relation access is the version's designated driver.  A dynamic
    version is driven by exactly its designated delta occurrence.
  - Every action's input variables are ground when it runs.
  - Guards run at the first safe opportunity.
  - A computation runs only when demanded by the next action, or during the
    fully matched flush.  Moving a partial/fallible computation ahead of a
    filtering action can change behavior.
  - Exact semi-naive view choice belongs to the **logical occurrence and
    version**, not to the occurrence's eventual position in a physical plan.
  - FULL and DELTA indices used to synthesize OLD or NEW have exactly the same
    complete column order.
  - Index requirements and lowering consume the same chosen physical plan.
    They must not independently rediscover a WCOJ opportunity.
  - The ordinary binary plan remains available for every rule and compiler
    flavor.

The occurrence/view issue is the most dangerous one.  Today `$oldjoin` and
`$newjoin` are wrappers recovered by numeric join position after scheduling.
That representation becomes fragile when one physical action consumes two
logical occurrences.

## 5. Give relation occurrences stable identities

Before adding an action planner, give each normalized positive body occurrence
a stable ID.  For each already-staged rule, IDs should be assigned in source
body order after repeated-variable normalization and survive version generation,
scheduling, WCOJ combination, index selection, lowering, diagnostics, and
tests.

An occurrence record needs at least:

    occurrence id
    source provenance
    relation name and kind
    normalized tuple variables in storage-column order
    original dynamic-occurrence ordinal, if any
    static/temp/lattice/struct classifications

For each rule version, attach a separate access view:

    DELTA    the designated dynamic driver
    FULL     a static occurrence or dynamic occurrence before the driver
    OLD      a positive dynamic occurrence after the driver
    NEW      a negative-maintenance dynamic occurrence after the driver

Seeded and closed-relation versions use FULL as required by their existing
semantics.  Temp drivers retain their special path.

The view map must be computed from original dynamic-occurrence order **before
physical scheduling**.  Reordering actions can then never turn an OLD access
into FULL or vice versa.  This should replace `memq` identity and positional
`split-exact-marks` as the long-term source of truth.  During migration, the
compiler can translate occurrence annotations back into wrappers for scalar
actions, but new WCOJ code should not add another positional convention.

Stable occurrence IDs also solve three otherwise awkward cases:

  - two occurrences of the same relation (self-joins);
  - two textually equal clauses; and
  - a `join3` action that consumes two logical occurrences while semijoin and
    exact-view analyses still need to identify both.

## 6. Plan actions, not only a linear list of atoms

The planner's unit should become a physical **action**:

    ScalarJoin(occurrence)
        consumes one occurrence; may bind zero or more variables

    Expand3(left occurrence, right occurrence, cycle variable)
        consumes two occurrences; binds their one shared free variable

Later actions can include `Lookup`, `Expand`, and `IntersectN`, but the first
change does not need them in the emitted C IR.

For each version, planning should conceptually do this:

  1. choose or receive the driver occurrence;
  2. assign occurrence views from the logical dynamic order;
  3. seed the ground set from constants and the driver;
  4. drain safe guards;
  5. enumerate eligible scalar and `Expand3` actions;
  6. demand only computations needed for a selected action's input;
  7. emit the selected action and add its output variables to the ground set;
  8. remove all occurrence IDs consumed by the action; and
  9. repeat, then perform the existing fully matched compute/guard flush.

This makes WCOJ selection part of the same state transition that establishes
well-orderedness.  It also provides one obvious place to enforce conservative
eligibility.

### Exact initial eligibility test

At frontier `G`, for each unordered pair of pending occurrences `(L, R)`:

    shared-free = (vars(L) intersection vars(R)) - G
    left-free   = vars(L) - G
    right-free  = vars(R) - G
    left-bound  = vars(L) intersection G
    right-bound = vars(R) intersection G

Create an `Expand3` candidate only when:

    count(shared-free) = 1
    left-free = shared-free
    right-free = shared-free
    left-bound is non-empty
    right-bound is non-empty

and all relation/view restrictions in Section 3 pass.  The action binds the
sole member of `shared-free` and consumes both IDs atomically.

This definition intentionally allows ground columns that are not shared by the
two arms.  In the triangle, the left prefix is `B` and the right prefix is `A`.
It also allows the same relation name on both sides, because eligibility and
views attach to occurrences.

For the first automatic policy we should require that the driver plus the two
arms form a real cycle in the occurrence-variable incidence graph, or that a
planner flag explicitly opts into broader intersections.  The operator can
also improve acyclic shapes such as two arms sharing the same `(prefix, C)`, but
the cycle restriction gives us a narrow deployment and clearer performance
expectations.  Once cost evidence is available, local intersection can be
selected wherever it is cheaper, regardless of the whole query's cyclicity.

### Driver selection

Dynamic and temp versions already constrain their driver; retain that.

For a closed or seeded rule, choosing the current highest-scoring scalar atom
first can hide the only useful ternary action.  Do not permanently bolt a
constant `join3` bonus onto `best-join`.  The robust solution is to try each
legal driver, plan the small remainder, and compare complete candidate plans.
Rule bodies are normally small, so this enumeration is cheap and deterministic.
An initial implementation can use a look-ahead bonus, but it should be treated
as a migration step.

### Deterministic choice without statistics

Slog does not yet have the prefix cardinality statistics needed for a serious
cost model.  Initial planning should therefore use a structural cost vector,
not fabricated row estimates.  Among valid candidates, prefer in order:

  1. a certified key-simple cyclic `Expand3` over an expanding scalar join
     whose result would immediately be checked by the other arm;
  2. more bound columns across the two arms;
  3. fewer unsupported/private/payload columns (zero in the first scope);
  4. more newly enabled guards;
  5. fewer newly demanded computations; and
  6. stable occurrence IDs as the final tie-breaker.

The action score should be a separate type or lexicographic vector.  Folding it
into today's scalar integer score will make incomparable choices look precise
and will be difficult to evolve.

### More than two arms

If three pending occurrences share the same free variable, choosing an
arbitrary pair can materialize their pairwise intersection before the third
filters it.  That can still be useful, but is not a generic WCOJ solution.  The
initial planner should either:

  - decline the rewrite when a third eligible arm exists; or
  - select it under an explicitly documented heuristic and record a counter.

The preferred eventual solution is an `IntersectN`/generic leapfrog action.
Do not represent repeated pairwise `join3` actions as if they establish an
n-way worst-case bound.

## 7. From individual triangles to cyclic islands

The first pair test can live directly in the action scheduler.  Complex rules
need a slightly more deliberate planner so that a greedy scalar choice does not
destroy an available cycle closer.

### Find a local core

Build the normalized atom-variable incidence hypergraph for positive table
occurrences.  Constants and currently ground variables annotate the graph;
guards and computations remain dependencies outside it.

Use a GYO-style peel to identify acyclic fringe occurrences and a residual
cyclic core.  This is a planning aid, not a semantic partition:

  - fringe actions can continue through the existing scalar/SIP planner;
  - eligible pieces of the residual core can become Lookup/Expand actions;
  - unsupported core pieces fall back to scalar joins; and
  - guards fire whenever the combined action schedule grounds their inputs.

The core detector should work on occurrence IDs and normalized variables.  It
must not infer a cycle from relation names, source adjacency, or chosen index
orders.

### Lookup/Expand representation

DHJ's most useful architectural idea for Slog is to split a binary join into:

  - **Lookup**: use currently ground values to obtain a handle/cursor over a
    relation prefix; and
  - **Expand**: enumerate values from a handle when a variable must become
    ground.

Keeping lookups delayed exposes the moment at which two handles constrain the
same next variable.  That moment can use `Expand3` rather than expand one handle
and point-probe the other.  A diamond-shaped rule illustrates the local nature:

    Q(A, C) :- R(A, B), S(B, C), T(A, D), U(D, C).

One path may bind `A,C` through ordinary actions; the two remaining lookups
`T[A,D]` and `U[C,D]` (the latter using a selected `(C,D)` physical order) can
then be expanded together over `D`.  The whole rule need not become a
monolithic generic join.

We should use this abstraction in the planned IR even if the first emitted C IR
has a direct `join3`.  It leaves room for:

  - sharing an existence lookup with a later expansion;
  - selecting a different expansion order after inspecting a batch;
  - n-way leapfrog; and
  - factorized groups when an arm has payload columns.

### Bounded search for a small core

For a small residual core, memoize plans over a state containing:

    consumed occurrence IDs
    currently ground variables
    available delayed lookup handles
    occurrence view annotations
    unresolved guard/compute dependencies

Candidate transitions are scalar expansion, filtering lookup, and `Expand3`.
A bounded dynamic program (for example, at most 8 core occurrences, with the
exact cap measured before committing it) is preferable to a large set of
greedy special cases.  Larger cores use deterministic greedy planning or the
ordinary planner.

Until real statistics exist, compare plans with a robust vector such as:

    unsupported/unbounded-intermediate risk
    number of scalar expanding actions
    number of ordered seeks
    estimated enabled-prefix fanout, when known
    extra index-order requirements
    generated code size

Later, relation and prefix statistics can refine this vector.  They should not
be prerequisites for the first triangle operator.

### Query classes we should deliberately leave alone

The local binary/ternary action vocabulary is broad for graph-like joins, but
not complete for arbitrary hypergraphs.  Loomis-Whitney shapes, several arms
sharing a variable, relations with multiple free shared variables, and queries
that require factorized payload products need a generic island or `IntersectN`.
The core planner must be allowed to return “no rewrite.”

## 8. Index planning needs an ordered access contract

Today's `selection-needs` says only that a **set** of bound columns must form an
index prefix.  That is insufficient for `join3`.

For an arm with bound column set `B` and cycle column `c`, the index must have:

    every column in B first, in any usable order
    c immediately after that prefix
    remaining columns afterward

Equivalently, if `ord` is a storage-column permutation and `K = |B|`:

    set(take(ord, K)) = B
    ord[K] = c

Simply requesting `B union {c}` does not express this: the current prefix-chain
packer may put `c` inside `B`, or pack the requests in a way that does not leave
`c` as the next cursor component.

Add an explicit ordered access requirement, conceptually:

    AccessNeed(relation, view-family, bound-set, next-columns, occurrence-id)

For the first operator, `next-columns` contains only `c`.  This can also be
viewed as a required prefix chain `(B, B union {c})` with the boundary retained.
Index assignment should reuse an existing ordering if it satisfies the exact
contract, and otherwise synthesize one ordering that does.  Compatible scalar
and semijoin needs should still share it.

When a view is OLD or NEW, the complete FULL and DELTA ordering must be
identical, as it is for exact scalar probes today.  The selected order ID must
be part of the explicit physical action handed to lowering; lowering must not
perform a fresh `find-index` using only `B` and accidentally choose a different
valid prefix order.

This extension is useful beyond WCOJ.  It is the first time the compiler states
that a particular free column must be the next sorted dimension, which future
merge, range, and grouped operators will also need.

## 9. Planned IR and C IR

There must be one explicit selected artifact shared by:

  - well-order/ground-variable checks;
  - semijoin-filter placement;
  - index requirement collection;
  - exact-view validation;
  - lowering; and
  - diagnostics/tests.

An illustrative planned node is:

    Expand3(
      output-var: C,
      left:  Access(occ-S, OLD, S(B,C), bound={B}, next=C),
      right: Access(occ-T, OLD, T(A,C), bound={A}, next=C))

The exact Racket representation can remain s-expression based, but fields
should be named by constructors/accessors rather than repeatedly pattern
matched as positional magic.  A transparent internal struct may be less error
prone than adding deeply nested surface-like `syn` forms.

After index choice, the first C IR can be direct:

    (join3 C
      (arm S full-order delta-order old K tuple-in-index-order)
      (arm T full-order delta-order old K tuple-in-index-order))

`join3` must encode both logical occurrence views and both exact chosen
orderings.  The emitter should not infer a view from operation position.

Longer term, the C IR can expose `(lookup handle ...)` and
`(expand3 handle handle ...)`.  We should not require that refactor before
measuring the first kernel, but the planned IR should not prevent it.

## 10. Interaction with semijoin filters

The current semijoin pass counts scalar join positions.  It must be converted
to occurrence IDs/actions before an automatic WCOJ rewrite ships.

For the first version:

  - `Expand3` consumes two logical occurrences atomically;
  - both occurrences' variables become available according to the action's
    declared output (only `C` in key-simple mode);
  - filters before and after the island remain legal;
  - do not emit an existence probe immediately followed by a WCOJ lookup of
    the same occurrence and prefix; and
  - do not attach separate semijoin filters *between* the two arms, because
    there is no such physical point.

A later Lookup/Expand IR can reuse an existing lookup handle for existence and
expansion.  The first implementation can simply suppress the redundant filter.

This change must preserve the existing rule that a computation is not pulled
ahead of a filtering action merely because `Expand3` will eventually ground its
output.

## 11. Sorted cursor kernel

Use the existing B-tree orderings first.  Specialized tries, compressed column
layouts, and hash/CoCo variants are follow-up storage work, not prerequisites.

### Prefix cursor

Add a cursor abstraction over one logical relation view:

    PrefixCursor<arity, prefix-length, view>
        first()
        key()              // the next column after the fixed prefix
        seek(c)            // lower_bound(prefix ++ c ++ minima)
        next_distinct()
        at_end_of_prefix()

The non-empty prefix determines the existing physical index bucket, so the
cursor reads one immutable `BTreeIndex`.  Prefix termination must compare all
fixed prefix columns, not rely on bucket membership.

The key-simple kernel does not need `next_distinct` grouping in normal set
relations, but using a cursor contract that supports it prevents a rewrite
when payloads arrive.

### Leapfrog intersection

For cursors `a` and `b`:

  1. open both prefix ranges;
  2. set the target to the larger current key;
  3. seek the lagging cursor to the target;
  4. repeat until keys match or either prefix ends;
  5. on equality, emit the key and advance; and
  6. continue from the new maximum.

This uses `lower_bound` to jump over gaps.  It does not merge-scan an enormous
range merely because its first key is small, and it does not require a range
cardinality estimate.  A later adaptive kernel can scan a sampled-short arm
and point-seek the other when that reduces tree traversals.

Be precise about emitted bindings: index tuples are in selected physical order,
but the generated local for `C` is the logical cycle value.  Existing tuple
reordering helpers should produce arm prefix arrays; the runtime operator
should not know source variable names.

### Logical view adapters

The cursor layer needs sorted logical streams for:

  - `FULL`: one full-index cursor;
  - `DELTA`: one delta-index cursor;
  - `OLD = FULL - DELTA`: advance the full cursor and skip exact keys found in
    the same-order delta index; and
  - `NEW = FULL union DELTA`: merge the same-order sorted cursors and deduplicate
    defensively.

The current scalar NEW operator can visit its two physical ranges separately;
`join3` cannot, because intersection requires globally sorted logical keys.
The merge adapter is therefore real new work.  The compiler must decline a
rewrite for any view whose cursor adapter is not available.

Recommended implementation order:

  1. FULL and DELTA cursor fuzz tests;
  2. FULL-only manually selected `join3` for kernel measurement;
  3. OLD difference cursor and positive exact versions;
  4. NEW union cursor and negative maintenance; and
  5. automatic planning only after every enabled compiler flavor either has a
     correct adapter or explicitly falls back.

## 12. Batch-parallel execution that fits Slog

Do not begin with a global HyperCube exchange.  Slog already has the right
coarse-grained ownership model for this local operator: immutable read-phase
indices, an outer driver divided into read tasks, workers dynamically claiming
tasks through the shared phase cursor, and thread-local buffered writes.

The recommended execution shape is:

    outer driver partitions
             |
             v
    small batch of bound environments
             |
             v
    open two prefix cursors per environment
             |
             v
    bounded Expand3/leapfrog morsels
             |
             v
    existing fused downstream callbacks and local output buffers

### Batch contents

A descriptor contains only the values needed to reconstruct the two prefixes,
the currently ground generated environment needed downstream, and cursor
resume state when active.  Start with 64 or 128 descriptors and tune by
measurement.  Preserve input order initially; sorting a batch by
`(relation/order, bucket, prefix)` for cache locality is a later experiment.

Batching is useful for bounded scheduling and locality, not because pointer-heavy
B-tree seeks are automatically SIMD.  Avoid a large vectorized framework until
profiles show that cursor dispatch, rather than tree/cache behavior, is the
bottleneck.

### Parallel ownership

Shard primarily by outer driver rows.  Each worker opens read-only cursors and
writes through the existing local batches.  No locks are needed in the
intersection kernel.  Keep morsels small enough that a skewed prefix cannot
hold a worker indefinitely.

The current physical `bucket_count` is 32 and read rows are round-robin split
through those 32 slots.  Physical index buckets and schedulable read partitions
should eventually be separate concepts, for example targeting several morsels
per worker.  That refactor benefits all read tasks and should not be entangled
with first-kernel correctness unless thread-scaling experiments demonstrate
that 32 partitions are the limiting factor.

A single outer prefix can still dominate.  If this occurs in realistic
measurements, split its cycle-key domain into `[lo, hi)` sub-morsels.  That
requires a cheap way to choose pivots or sampled cursor keys; do not invent it
before the skew benchmark proves it necessary.

### Where to put the batch boundary

There are two implementation choices:

  - **Restricted first version:** select `Expand3` only as the first expanding
    action after the driver (allowing filters, guards, and safe scalar checks
    before it).  The driver row is enough to reconstruct its environment.
  - **General version:** let an arbitrary scalar prefix fill a batch of complete
    ground environments, then run `Expand3` as a small pipeline breaker.

The restricted version covers triangles and makes exact pause/resume much
simpler.  The planned action IR should support the general version, but the
automatic eligibility gate should start restricted unless we implement an
explicit environment descriptor from day one.

## 13. Pausing and continuation state

Current read tasks pause at outer scan/probe granularity.  A large intersection
or high-output prefix must not become an uninterruptible inner loop.

`join3` should be a bounded/resumable operator.  After a fixed number of seeks
or emitted matches (and at the normal stop check), it flushes output and stores:

    current batch lane / environment descriptor
    fixed left and right prefixes, or the values that rebuild them
    each logical cursor's next seek key
    whether a saved key is inclusive or already emitted
    downstream/batch position needed to avoid duplicate output

Store value keys, not C++ iterators.  Continuations can migrate between workers,
and value keys also make checkpoint/debug reasoning explicit.  Define one
inclusive/exclusive resume convention and fuzz it at every boundary, including
`0` and `UINT64_MAX`; do not synthesize a successor by unchecked integer
increment.

Reprocessing the whole outer driver row is not correct after the operator has
already emitted some matches: it can duplicate deductions and support counts.
This is the strongest reason either to restrict the first placement to a
driver-reconstructible position or to introduce batch environment continuations
as part of the same change.

Work and time limits should count cursor seeks/visited keys as well as outer
rows.  A “batch of 128 driver rows” is not a bound when one row owns millions of
matches.

## 14. Payloads, duplicate cycle keys, and later generalization

Key-simple mode deliberately excludes an arm with free columns besides `C`.
When payload columns are admitted, a cycle key denotes a **group** of tuples.
Correct output may require:

  - intersecting distinct `C` keys;
  - materializing or streaming the left and right groups for a matching `C`;
  - emitting their cross-product; and
  - preserving exact relation-set and support-count semantics.

That is an `Expand3Grouped` operator, not a small tweak to key-simple `join3`.
It needs its own output-bound and pause state.  Projection can also collapse
distinct payload combinations in the head, but Slog's support/count modes may
still require every logical rule instantiation.  Do not discard payloads based
only on head projection.

Repeated variables normalized into generated equality guards are another
reason to stay conservative.  The first planner should reject an arm whose
cycle semantics depend on a post-access generated equality guard.  Later the
normalizer can expose equivalence classes deliberately.

## 15. Relation kinds and maintenance flavors

The initial support matrix should be explicit rather than accidental:

| Feature | First automatic version | Later |
|---|---:|---:|
| ordinary table/set relation | yes | yes |
| FULL arm view | yes | yes |
| DELTA outer driver | yes; never an intersection arm | yes |
| positive OLD arm view | yes, difference cursor | yes |
| negative NEW arm view | yes, sorted-union cursor | yes |
| same-relation/self-join occurrences | yes, with occurrence IDs | yes |
| static occurrence as an arm | yes | yes |
| seeded FULL version | yes | yes |
| temp relation | no | possible specialized path |
| lattice/map relation | no | grouped/map operator |
| struct relation | no | after storage-contract review |
| negated occurrence | no | remains a guard/filter |
| computed key column | no | after dependency-aware Lookup |
| grouped payload columns | no | `Expand3Grouped` |
| count/signed maintenance | yes; shares explicit occurrence views | yes |

“No” means the planner retains scalar operations, not that the rule is
rejected.

Count and signed-maintenance plugins use the same occurrence-view assignment.
Planner/lowering tests assert count FULL, positive OLD, and negative NEW action
shapes and identical FULL/DELTA orderings; the cursor oracle covers every pair
of logical views, including union overlap and deduplication.  The full session
and stress suites also pass with the feature enabled and continue to gate
exact-once fire counts, maintained-vs-recount equality, cyclic deletion,
self-joins, and reload.  A dedicated incremental Datalog regression now
exists (`tests/session-tests.sh`, the `wcoj-tri-*`/`wcoj-rec-*` block over
`tests/session/wcoj_tri.slog` and `wcoj_tri_rec.slog`): it forces a `join3`
into the normal, `_count`, `_maint1`, and `_maint3neg`/`_maint4neg` plans
(asserted against the run's own `.plan` sidecars), and gates maintained
support sidecars against a forced fresh recount across positive maintenance,
acyclic deletion, the recursive DRed sweep behind the foundation-aware
overlay verb, and relearning.  Set output equality alone is not sufficient.

## 16. Observability and feature control

Add a compile-time/environment escape hatch such as:

    SLOG_NO_WCOJ3=1

Like `SLOG_NO_SEMIJOIN`, its value must participate in the compiled `.so` cache
key.  Maintenance/delta/count artifact flavors that re-plan independently must
receive the same setting.

At least in debug or benchmark builds, expose per-operator counters:

    outer environments
    prefix cursors opened
    lower_bound/seek calls
    cycle keys visited
    matched cycle keys
    downstream rows emitted
    pauses/resumes
    fallback reason / rejected candidate category

Planner diagnostics should print occurrence IDs, views, bound prefixes, cycle
columns, and chosen orders.  These counters make it possible to distinguish a
bad planner choice from a slow cursor or an output-size-limited query.

## 17. Correctness tests

### Planner tests

Build small compiler tests that assert selected actions and index order
contracts for:

  - every permutation of triangle atom source order;
  - every dynamic driver version;
  - FULL/FULL, FULL/OLD, OLD/OLD, and eventually NEW combinations;
  - static arms and seeded versions;
  - relation self-joins with distinct occurrence IDs;
  - constants and multiple already-ground prefix columns;
  - repeated variables/equality guards (initially rejected where required);
  - a triangle with an intervening safe guard;
  - a demanded or fallible compute that must not move early;
  - three arms sharing one free variable;
  - two shared free variables;
  - an acyclic lookalike;
  - lattice, temp, struct, negation, and payload exclusions;
  - a needed `(bound..., C, ...)` ordering that the old set-only packer could
    choose incorrectly; and
  - identical FULL/DELTA complete orders for OLD/NEW.

Assert deterministic plans across repeated compilation.  Include textual
diagnostics for a declined rewrite so future changes do not silently broaden
the support matrix.

### Cursor/operator tests

Fuzz `PrefixCursor` and `join3` against a simple set oracle across:

  - empty, singleton, disjoint, equal, and partially overlapping ranges;
  - long gaps and adversarial identifier order;
  - one tiny and one huge range in either orientation;
  - all physical index buckets;
  - FULL, DELTA, OLD difference, and NEW union streams;
  - full/delta overlap and deduplication defenses;
  - `0` and maximum key values; and
  - a forced pause before/after every seek and every emitted match.

The oracle should compare both result rows and multiplicity/fire counts where
the compiler flavor exposes them.

### End-to-end tests

Compare WCOJ on/off for:

  - nonrecursive triangle derivation;
  - recursive use across several fixpoint iterations;
  - seeded/reloaded data;
  - positive incremental insertion;
  - negative deletion/NEW views;
  - self-joins;
  - support counts and signed maintenance; and
  - memory/time pausing with repeated continuation.

Run existing session, incremental, pausing, lattice, and count suites with the
feature both enabled and disabled.  A planner-only compiler change is not
sufficient evidence because exact-view mistakes often preserve final set
output while changing per-iteration fire multiplicity.

## 18. Performance evaluation

Keep at least these benchmark families:

  - **disjoint high-degree hub:** the measured catastrophic case;
  - **hub with a small closing set:** verifies output as well as pruning;
  - **dense bipartite triangle:** semijoin filters pass but intersection wins;
  - **Erdős-Rényi:** detects overhead on an ordinary mixed workload;
  - **cliques and skewed power-law graphs:** tests many matches and imbalance;
  - **diamond/4-cycle:** exercises a local closer inside a larger plan;
  - **recursive cyclic rule:** repeats the choice over changing deltas; and
  - **acyclic/path control:** must retain the scalar plan and its performance.

Record input/output sizes, logical candidate counts, seeks, cursor matches,
fixpoint iterations, wall time, peak memory, and thread scaling.  Sweep batch
size and threads.  Use identical inputs and diff outputs/support counts.

Initial acceptance targets should be stated before implementation.  A sensible
starting proposal is:

  - reduce the disjoint-hub candidate metric from the binary cross-product to
    work proportional to outer rows plus cursor seeks;
  - retain a very large wall-time win on that workload (the prototype's 594x
    leaves ample margin);
  - no material regression on the ER and acyclic controls, with a provisional
    10% median threshold investigated rather than silently accepted;
  - bounded pause latency inside a large single-prefix intersection; and
  - positive scaling until outer partitions or memory bandwidth become the
    measured limit.

The first three performance classes and outer-driver scaling have been
measured.  Inner-prefix pause latency is still an explicit open acceptance
item; current pausing remains at the outer driver boundary, as it is for the
existing nested scalar pipeline.

## 19. Staged implementation plan

Status as of the first production slice: stable occurrences, explicit
`Expand3`, exact logical views, bounded small-body search, driver enumeration,
physical lowering/emission, and the FULL/OLD/NEW leapfrog kernel are complete.
The general ordered access record, inner-operator continuation, explicit
environment batches, observability counters, GYO core extraction, delayed
Lookup handles, `IntersectN`, and grouped payload expansion remain planned.

### Phase 0: lock down representations

  1. Add stable occurrence IDs and per-version view annotations.
  2. Define planned action structs and access-need structs.
  3. Convert scalar wrappers/position consumers incrementally, with golden
     tests proving unchanged plans.
  4. Decide and document the exact resume-key convention.

This phase should produce no WCOJ runtime behavior.

### Phase 1: kernel and explicit index contracts

  1. Extend index requisition with `(bound prefix, next column)` needs.
  2. Add FULL/DELTA prefix cursors and a key-simple leapfrog kernel.
  3. Add a direct physical `join3` C IR node and emitter support behind a
     disabled-by-default/manual planner hook.
  4. Make a single-environment kernel bounded and exactly resumable before it
     is used by automatic plans.
  5. Fuzz the kernel and reproduce the hub/ER prototype measurements.

### Phase 2: exact semi-naive support

  1. Implement OLD difference cursors over same-order FULL/DELTA indices.
  2. Implement sorted NEW union cursors.
  3. Test all driver/view permutations and count/maintenance flavors.
  4. Make every unsupported flavor fall back visibly.

### Phase 3: conservative automatic planning

  1. Add the exact key-simple pair eligibility test to the action scheduler.
  2. Start with placement immediately after a reconstructible driver prefix.
  3. Teach semijoin filtering and lowering to consume the explicit action.
  4. Add the cache-keyed off switch and counters.
  5. Enable by default only after end-to-end and performance gates pass.

### Phase 4: batching and generalized placement

  1. Process bounded descriptor batches/morsels.
  2. Extend the already exact single-environment continuation to batch lanes.
  3. Count work in seeks/matches, not just driver rows.
  4. Measure whether read partitions must be decoupled from 32 physical index
     buckets.
  5. Use live-variable environment descriptors to allow placement after a
     general scalar prefix when measurements justify the pipeline boundary.

### Phase 5: cyclic-island planner

  1. Add GYO-style fringe/core analysis.
  2. Introduce explicit delayed Lookup/Expand actions.
  3. Use bounded DP for small cores and deterministic fallback for larger ones.
  4. Add diamond and mixed cyclic/acyclic plan tests.
  5. Add `IntersectN` or grouped expansion only from measured workloads.

### Phase 6: storage specialization, if justified

Compare the B-tree cursor against compact trie/CoCo/hash alternatives, prefix
histograms, adaptive scan-vs-seek, and batch prefix sorting.  HoneyComb-style
parallel WCOJ and shared trie layouts are relevant here, but only after the
local operator's counters show where B-tree seeks and task partitioning fall
short.

## 20. Decision record and remaining design gates

The following list began as the pre-implementation design gate.  Items resolved
by the first slice use the recommended choice in the implementation; items
about batching, continuation state, general ordered access, and broader cyclic
islands remain gates for the next slice.

1. **Occurrence representation and lifetime.**  Are IDs structs embedded at
   normalization or side-table keys?  (Embedded stable IDs, with provenance.)
2. **View annotation point.**  Can every flavor assign DELTA/FULL/OLD/NEW before
   scheduling?  (Yes; make this mandatory.)
3. **Planned action representation.**  Transparent Racket structs or new `syn`
   grammar?  (Small structs with constructors/accessors, serialized only for
   diagnostics.)
4. **Initial eligibility.**  Is key-simple exactly `free(L)=free(R)={C}` with
   non-empty prefixes?  (Yes.)
5. **Cycle restriction.**  Require a certified three-occurrence cycle at first,
   or optimize any two-list intersection?  (Require the cycle for automatic
   enablement; expose broader mode to benchmarks.)
6. **Placement restriction.**  Must the first operator immediately follow the
   driver/check prefix?  (The fused v1 may follow a scalar prefix because its
   locals stay on the callback stack.  A future batch/pause boundary must either
   restrict placement or carry the live environment.)
7. **Access-need representation.**  How does index packing retain “C is next”
   and same FULL/DELTA order?  (For v1, arity `K+1` makes C the only possible
   suffix and lowering asserts it; add explicit bound-set plus ordered
   next-columns before any broader arm shape.)
8. **Intersection algorithm.**  Merge, shorter-side probes, or leapfrog seek?
   (Symmetric seek/leapfrog first; instrument it.)
9. **Logical views.**  Which of OLD/NEW is required before default enablement?
   (Both for all compiler flavors that can invoke the planner; otherwise a
   tested per-version fallback.)
10. **NEW union semantics.**  Can FULL and deleted DELTA overlap in every
    maintenance state, and where is deduplication required?  (Specify and
    defensively deduplicate the sorted cursor.)
11. **Pause ABI.**  Inclusive or exclusive saved keys, and where is the stop
    check relative to emission?  (Save the exact next unprocessed key/state;
    fuzz every boundary.)
12. **Batch descriptor ABI.**  Which generated locals must survive a pipeline
    boundary?  (Derive from the action's downstream live-variable set.)
13. **Batch and work limits.**  Fixed descriptor size and seek/match quantum?
    (Start 64/128 and tune; bound both seeks and emissions.)
14. **Three-or-more arms.**  Reject, choose a pair, or add `IntersectN`?
    (Reject ambiguous automatic rewrites initially.)
15. **Payload/group semantics.**  Are extra free columns excluded or grouped?
    (Exclude; design a separate grouped operator.)
16. **Relation support matrix.**  Tables only, and what about structs/statics?
    (Ordinary table arms first; statics allowed; all special storage explicit.)
17. **Driver selection for closed/seeded rules.**  Look-ahead heuristic or
    complete small enumeration?  (Enumerate legal drivers and compare plans.)
18. **Core search cap and fallback.**  What bounded-DP threshold avoids compiler
    blowup?  (Benchmark around 6--10 occurrences; always retain greedy/binary.)
19. **Statistics.**  Can current relation stats inform prefix fanout, and are
    they stable at compile time?  (Do not block v1; define a future stats
    interface instead of querying runtime state ad hoc.)
20. **Semijoin interaction.**  Which filters are redundant with lookup handles?
    (Suppress exact same-occurrence/same-prefix checks; preserve other filters.)
21. **Feature/cache identity.**  What toggle, planner version, and build hash
    fields prevent stale plugins?  (`SLOG_NO_WCOJ3`, action-planner version,
    normal code fingerprints.)
22. **Maintenance correctness oracle.**  Which tests compare instantiation
    multiplicity rather than only final tuples?  (Counts and signed-maintenance
    differential tests are release blockers.)
23. **Read partitioning.**  Is the fixed 32-way split enough on target machines?
    (Measure first; decouple schedulable partitions if scaling flattens.)
24. **Default-enable gates.**  What correctness suites and benchmark thresholds
    must pass?  (Write them down before switching the parameter default.)

Resolving items 1--12 is necessary before the first production implementation.
The remaining items may be staged, but each must have an explicit fallback so
the planner never silently overstates its support.

## 21. Research anchors

The design should be checked against these primary references while the planner
IR is finalized:

  - Birler et al., *Diamond Hardened Joins*, PVLDB 17(11), 2024:
    <https://www.vldb.org/pvldb/vol17/p3215-birler.pdf>
  - Veldhuizen, *Leapfrog Triejoin: A Simple, Worst-Case Optimal Join
    Algorithm*, 2012: <https://arxiv.org/abs/1210.0481>
  - Ngo, Porat, Ré, and Rudra, *Worst-case Optimal Join Algorithms*, 2012:
    <https://arxiv.org/abs/1203.1952>
  - Kankanamge et al., *Free Join*, 2023:
    <https://arxiv.org/abs/2301.10841>
  - Freitag et al., *Adopting Worst-Case Optimal Joins in Relational Database
    Systems*, PVLDB 13(12), 2020:
    <https://www.vldb.org/pvldb/vol13/p1891-freitag.pdf>
  - *HoneyComb: A Parallel Worst-Case Optimal Join on Multicores*, 2025:
    <https://arxiv.org/abs/2502.06715>
  - *Adaptive Factorization Using TreeTracker*, CIDR 2025:
    <https://www.vldb.org/cidrdb/papers/2025/p21-gro.pdf>

The lesson to carry into Slog is not “replace every join with one generic
algorithm.”  It is to expose lookup and expansion choices in the physical plan,
insert a hardened ternary expansion at certified cyclic boundaries, and retain
the mature fused binary path everywhere else.
