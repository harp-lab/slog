# Fully Incremental Slog: Insertion and Deletion of Input Facts

**Status:** design / pre-implementation. Revised 2026-07-08 against the current
codebase: the compiler now HAS SCC stratification (the 2026-07 rewrite), the
read phase is push-operator based, pausing and lattices L0+L1 are shipped, and
db-compression (recompute-on-load, `docs/db-compression.md`) is fully shipped
forward-incremental — §8A below pins the composition contract with it. Code
anchors throughout were re-verified 2026-07-08; M2's scope shrank accordingly
(§6.4, §9).
**Goal:** make slog programs incrementally maintainable in *both* directions — a stream
of insertions **and deletions** of EDB (input) facts is applied to a materialised
database and every derived relation/struct is updated to exactly the least-fixpoint it
would have had if the new input had been loaded from scratch, without recomputing from
scratch.

This document captures the full design worked out in discussion: the theory that
constrains it, the algorithm we chose (DRed^c), and — concretely — every change we
expect to make and where it lands in the codebase.

---

## 1. Why this is hard: pure counting is unsound for recursion

The tempting design is: give every tuple a *proof count* (number of derivations),
increment on insert, decrement on delete, and remove a tuple when its count hits 0.
This is finite and terminating in slog (we count *one-step* derivations from
currently-present facts, driven by semi-naïve iteration, **not** derivation trees — so
the count of a tuple in a cycle stays finite). And it is **sound and precise for
non-recursive programs**.

It is **not sound for recursive programs**, because a count tells you *how many* proofs
a tuple has, never *whether any of them is still grounded in surviving input*. Across a
recursive cycle, tuples keep each other's counts positive while collectively having lost
all external support — the **unfounded self-supporting cycle**.

### Canonical counterexample (Motik et al.)

```
R(y,x) :- R(x,y).          % symmetric closure; R is EDB + IDB
EDB: R(a,b)
```

After inserting `R(a,b)`: counts are `R(a,b)=2` (1 from the EDB fact, 1 derived from
`R(b,a)`), `R(b,a)=1`. Now **delete EDB `R(a,b)`**: decrement its EDB proof → `R(a,b)=1`,
still `>0`, so it survives; because it survives, `R(b,a)` keeps its derivation and stays
at 1. Final state `R(a,b)=1, R(b,a)=1` — **both wrongly retained**. They prop each other
up forever ("analogous to why reference counting is not a general GC strategy").

The same shape appears as `reachable(a),reachable(b)` in a two-cycle after the `source`
fact that founded them is deleted: the edge cycle survives and mutually supports the
pair even though nothing grounds it anymore.

### Why the naïve intuition (the TC/`path` case) *seemed* to work

Transitive closure over edges deletes correctly under pure counting **only because the
deleted EDB (`edge`) appears inside every recursive proof step**, so deleting an edge
drives all dependent counts to zero directly. The failure case is deleting a fact *below*
a cycle that stays structurally intact. General soundness therefore requires re-checking
**foundedness**, which counts alone cannot do.

### Theory backing this

- Counting a tuple's derivation trees over a cycle is *infinite*; incremental view
  maintenance by counting diverges for recursive views over cyclic data.
- Datalog over a semiring converges **iff the semiring is stable**; ℕ (bag / counting
  semantics) is **not stable**. A finite per-tuple derivation-tree count is not even
  well-defined for recursive Datalog over cycles.
- This is exactly the gap DRed (Delete and Re-derive) was invented to fill.

See §12 for citations.

---

## 2. The chosen algorithm: DRed^c

We adopt **DRed^c** (counting-augmented Delete/Re-derive): Hu, Motik, Horrocks,
*"Optimised Maintenance of Datalog Materialisations"*, AAAI 2018. It combines the
precision of counting on the easy (non-recursive) part with DRed's foundedness repair on
the recursive part, and — crucially for slog — **it does not require evaluating rules
"backwards"** (matching a head to a fact and running the partial body as a query). That
property is why it fits slog's forward, push-operator engine.

DRed^c gives us:

- **Full precision on non-recursive derivations** — counters decide membership exactly,
  no over-deletion, no re-derivation.
- **Sound recursion** — over-delete the suspect region, then re-derive what is still
  founded, restoring the least fixpoint (kills unfounded cycles).
- **A cheap re-derivation** — counters identify the re-foundable frontier without
  backward search.

### Alternatives considered (and why not, for now)

| Approach | Correctness | Fit to slog | Verdict |
|---|---|---|---|
| Pure counting | Unsound for recursion | Trivial | Rejected (see §1) |
| **DRed^c** | Sound | *Extends* current engine; no backward rules | **Chosen** |
| DBSP nested incremental circuits | Sound, O(change) | Codegen rewrite (integration/differentiation ops, nested recursive circuits) | Future |
| Differential dataflow (timestamp lattice) | Sound, O(change) even deep in recursion | Engine *replacement* (versioned traces, progress tracking); ~2–4× memory | Future |

---

## 3. Core concepts

### 3.1 Two counters per fact

Each fact carries two signed counters in its relation's master index:

- **`nonrec`** — number of derivations via rules whose body is entirely in *earlier
  strata* (including base/EDB rules). These are **foundation** proofs.
- **`rec`** — number of derivations via rules with a body predicate in the **same SCC**
  as the head. These are **circular-capable** proofs.

`present(t) := nonrec + rec > 0`. The classification of each *rule* as recursive vs
non-recursive is static (see §4.5), so each rule bumps exactly one of the two counters.

The two counters are the whole reason DRed^c beats plain DRed:

- `nonrec > 0` ⟹ the fact is grounded in an earlier stratum and is **provably still
  true** after any update within this stratum → it is a hard barrier that stops
  over-deletion.
- After the negative fixpoint, `rec > 0` on an over-deleted fact is an **O(1) certificate
  that a surviving derivation still exists** (support that did not route through the
  deleted region) → it can be re-founded in one step, with its count already correct,
  without re-firing its rules.

### 3.2 Two roles per tuple (the key mental model)

Two different things flow through evaluation; do not conflate them:

1. **Counter updates** happen when a tuple is produced (or loses a derivation) **as a
   consequence** of a join. This is the only place `(nonrec, rec)` mutate.
2. **Delta records** `(tuple, sign)` are **propagation signals** — "this tuple changed
   presence; use it as a **premise** to drive the next round of joins." The `sign`
   (+1 appeared / −1 disappeared) tells the downstream aggregate whether joins *through*
   this premise should add to or subtract from **its consequences'** counters.

A delta record therefore carries **no `(Δnonrec, Δrec)` for the tuple itself** — that
tuple's counters were already finalised when it was produced as a consequence. Every
tuple plays both roles: as a consequence its counters are updated; as a premise it is a
signed signal driving further joins.

### 3.3 Presence ≠ counts during an update

Between phases a fact can be **over-deleted** (removed from the live set) while `rec > 0`.
So membership cannot be read off the counters during an update. We track over-deleted
facts explicitly in a transient **candidate set `C`** (§3.4).

### 3.4 The candidate set `C`

`C` is the per-update set of **over-deleted** (speculatively removed) facts. It is
required because counters alone cannot encode "removed but rec>0". It is **not a new
kind of structure**: it is an instance of the existing delta/index machinery
(`BTreeIndex<A>` / the `deltaindices` handles) given a different *lifecycle* —
"accumulate until reseed" instead of "merge into the main index." One handle per
relation, populated only in the negative phase.

---

## 4. The algorithm

Process the program's strata in **topological order** (lowest first). Within a stratum,
run three phases in sequence. Topological order is what makes it a single sweep with no
mutual iteration: when stratum *k* is processed, every earlier stratum is final, so each
fact's `nonrec` counter (which counts only earlier-stratum support) is **stable**
throughout — that stability is what makes the `nonrec>0` barrier sound.

```
for each stratum S in topological order:
    1. NEGATIVE fixpoint   (apply − input deltas to S; over-delete; accumulate C)
    2. RESEED scan         (adjudicate C: rec>0 → re-found; rec==0 → delete)
    3. POSITIVE fixpoint   (apply + deltas: reseeds + genuine inserts; rebuild)
    // facts that truly died escape S as − input deltas to later strata
    // facts newly true escape S as + input deltas to later strata
```

### 4.1 Negative fixpoint (over-deletion)

Drive `Δ⁻` through the **same** compiled join pipeline as forward evaluation. The
aggregate step decrements consequence counters:

```
over-delete(h):                      # when a consequence h loses presence and nonrec==0
    if h not in C:
        C.insert(h)                  # explicit candidate set
        push (h, -1) onto Δ⁻         # propagation signal → decrement h's consequences
    # h stays physically in the main index for now; its counters remain
```

Propagation rule (in the generic aggregate, selected by polarity):

- Decrement the appropriate counter of every consequence reached.
- If a consequence has `nonrec > 0` → **protected**: record the decrement, **do not
  propagate** (stop).
- If a consequence has `nonrec == 0` and its presence drops → **over-delete** it (add to
  `C`, push `−1`), regardless of remaining `rec`.
- A fact is over-deleted at most once per update (the `not in C` guard); later reaches
  only decrement its counters further.

After this fixpoint settles, for every fact `rec` equals the number of its derivations
through **surviving** (non-over-deleted, non-deleted) facts — because over-deleting a
supporter decremented it. Hence `rec > 0` ⟺ re-foundable from a surviving fact.

### 4.2 Reseed scan (between phases)

Iterate **`C`** (not the relation — `O(|over-deleted|)`):

```
reseed():
    for t in C:
        if t.rec > 0:
            push (t, +1) onto Δ⁺      # presence signal to rebuild t's cone; counters already correct
            C.erase(t)                # t survives
        else:
            delete t from the main index   # (0,0): truly gone for now; may be re-derived below
```

Deleting the `rec==0` candidates here (rather than leaving them "absent but physically
present") keeps the positive phase's full-index joins correct **without a per-tuple
liveness branch on the hot path** — after reseed, the index holds only live tuples.

The `(t, +1)` pushed for a re-founded fact is a **propagation signal only**. `t`'s own
`(nonrec, rec)` are already correct; the increments it triggers land on **`t`'s
consequences** (the downstream cone the negative phase wrongly tore down).

### 4.3 Positive fixpoint (insertion / rebuild)

Drive `Δ⁺` (reseeds **plus** genuinely new inserted facts) through the same join
pipeline. The aggregate step increments consequence counters; a consequence whose
presence rises `0 → +` is pushed onto the output delta and (if it was a `rec==0`
candidate deleted at reseed) re-inserted fresh. This rebuilds the torn-down cone and
relearns any fact that is genuinely re-foundable — including facts that dropped to
`(0,0)` mid-update but come back once their founding route is re-established.

### 4.4 The uniform aggregate

The single place counters mutate; identical in both phases except for the propagation
predicate, which is chosen by a polarity flag:

```
aggregate(c, incoming signed derivations, polarity):
    was = present(c)
    c.nonrec += Σ(nonrec-tagged signs)     # "local contributor count" for this iteration
    c.rec    += Σ(rec-tagged signs)
    now = present(c)
    if was != now:
        if polarity == NEGATIVE and now == false and c.nonrec == 0:
            over-delete(c)                 # add to C, push (c,-1)
        elif polarity == NEGATIVE and now == false and c.nonrec > 0:
            pass                           # protected: decremented but not propagated
        else:  # POSITIVE, presence 0 -> +
            push (c, +1) onto Δ⁺
    # counters mutate here (c as consequence); the pushed record is a premise-signal
```

Note the "was == now" case (count changed, presence didn't): **do not propagate**. This
is the finiteness property — re-derivations of an already-present tuple bump its count
but never re-enter the delta, so counts stay finite and each fixpoint terminates.

---

## 5. Worked examples

### 5.1 Unfounded cycle stays deleted (Motik)

```
R(y,x) :- R(x,y).   EDB: R(a,b)
init:  R(a,b) = (nonrec 1, rec 1)     R(b,a) = (nonrec 0, rec 1)
delete EDB R(a,b):
  negative: R(a,b).nonrec 1→0; presence still true (rec 1) but nonrec==0 →
            over-delete R(a,b), push −1 → decrements R(b,a).rec 1→0 →
            over-delete R(b,a), push −1 → decrements R(a,b).rec 1→0.  C = {R(a,b),R(b,a)}
  reseed:   both have rec==0 → delete from index. No Δ⁺ seeds.
  positive: nothing to propagate.
  result:   both gone.  Correct.
```

### 5.2 Over-delete then one-step re-found, and a (0,0) relearn (diamond + chain)

```
path(x,y) :- edge(x,y).             % nonrecursive → nonrec
path(x,z) :- path(x,y), edge(y,z).  % recursive    → rec
EDB edges: a→b, a→e, e→b, b→c        % a reaches b directly AND via a→e→b

init:  path(a,b)=(1,1)   path(a,c)=(0,1)   path(a,e)=(1,0)  path(e,b)=(1,0)  path(b,c)=(1,0)

delete edge a→b:
  negative: path(a,b).nonrec 1→0; nonrec==0 → over-delete path(a,b), push −1
            → path(a,b),edge(b,c) decrements path(a,c).rec 1→0 → (0,0) →
              over-delete path(a,c).           C = {path(a,b)@(0,1), path(a,c)@(0,0)}
  reseed:   path(a,b).rec = 1 (from path(a,e),edge(e,b), both surviving) → push (path(a,b),+1); keep.
            path(a,c).rec = 0 → delete from index.
  positive: path(a,b) drives path(a,b),edge(b,c) → re-derive path(a,c): rec 0→1, re-inserted.
  result:   path(a,b)=(0,1), path(a,c)=(0,1).  Correct (a→e→b→c keeps both).
```

`path(a,b)` was re-founded cheaply in the **reseed** (its own `rec` survived).
`path(a,c)` genuinely hit `(0,0)` and was **relearned only in the positive fixpoint**,
once `path(a,b)` re-propagated.

---

## 6. Where every change lands

Two layers, and the split is what preserves "compile each rule once":

- **Per-rule compiled code** — the `ReadTask` join pipeline emitted inline by
  `emit-cpp.rkt`. Direction-agnostic: reads a delta, probes indices, hands
  presence-transition records to the aggregate. **The sign is data**, not code — so this
  is compiled **once per rule** and shared across the negative and positive phases.
- **Generic per-arity machinery** — `WriteTask<A>`, `InternTask<N>`, `InternStructTask<N>`
  in `operators.h`, instantiated per relation/bucket. **Every asymmetry between the
  phases lives here or in the driver**, never in per-rule code.

### 6.1 Data structures — `daemon/index.h`, `daemon/database.h`

*(anchors 2026-07-08: `BTreeIndex<A>` over `tlx::btree_set<array<u64,A>>` is
index.h:61; the map-valued `BTreeMapIndex<KA>` over `tlx::btree_map<array<u64,KA>,
u64>` ALREADY EXISTS at index.h:104 — built for lattices, it is the working
precedent for a value-carrying master index and for §7A.7's "extensible
index-value slot". A relation's index arrays live in `Relation::indices`
(database.h:128) with a parallel `deltaindices` table (database.h:129), selected
by `getIndex(ord, delta)` (database.h:506); per-bucket
`intern_allocators`/`getInternAlloc`/`getStructId` at database.h:138/298/263.)*

- Master index value changes from a set element to a mapped value:
  - relations: `btree_map<std::array<u64,A>, Count>` where `struct Count { s64 nonrec; s64 rec; };`
    — mechanically, a `BTreeMapIndex`-style index with a struct value instead of
    the lattice's single `u64` payload word.
  - structs: value `struct SCount { u64 id; s64 nonrec; s64 rec; };` — **`id` stays in
    the value so it survives over-delete/reseed** (see §7).
  - Counters live in the **value**, never in the key (else the same tuple at two counts
    becomes two keys and dedup/probe ordering breaks). Use **signed** `s64`: negative
    weights must exist *in transit* during propagation.
- Delta/probe indices that don't need counts can stay sets.
- Add, per relation, a handle for the transient candidate set `C` (§3.4) — reuse the
  existing `deltaindices` machinery; populated only in the negative phase.
- Relation gains: stratum id and, per index, the rule-derived rec/nonrec tag needed by
  the aggregate.

### 6.2 Operators — `daemon/operators.h`

*(re-anchored 2026-07-08 to the push-operator refactor; the read phase is now a
family of fused template operators with pausable `_sliced` variants, and the
lattice path already ships a value-carrying merge task — both work in our
favour.)*

- Read phase — **unchanged, sign-agnostic**: `read_delta` (l.40) /
  `read_delta_sliced` (l.62, pausing), `join_probe` (l.94) / `join_probe_sliced`
  (l.116), `exists_probe` (l.148, semijoin filter), `join_all` (l.166),
  `join_probe_lat` (l.182), `join_all_lat` (l.196). The `_sliced` variants are
  where pausing lives — and ONLY here, which is what keeps §6.5's
  pausing-composes-for-free claim true.
- `emit` (l.214): today it **dedup-skips at emit time** (`head_index->contains`)
  — replace with a **counting, signed** producer that records `(tuple, sign)`
  tagged with the rule's static rec/nonrec bit into the batch — **no emit-time
  dedup-skip** (we must count re-derivations of existing tuples). Removing this
  skip is also why the exact-once delta convention becomes load-bearing (§8/§8A:
  a double-fired instantiation was harmless under set semantics, it corrupts
  counts).
- `emit_temp` (l.232): temps are stratum-transient plumbing (no persistence) —
  sign-agnostic, likely unchanged.
- `emit_struct` (l.253): same signed treatment, but the id slot stays a 0
  placeholder — `InternStructTask` owns dedup + id (already true today, by
  design comment at l.248-251).
- `InternTask` (l.371) → **counting aggregator** implementing §4.4: sum per-tuple signed
  contributions, update `(nonrec, rec)`, apply the polarity-selected propagation
  predicate (over-delete + `C` on negative; push Δ⁺ on positive).
- `InternStructTask` (l.497): same aggregation, preserving `id`; presence 0→+ allocates
  id only for genuinely new content (content-dedup via `lower_bound` on content
  columns, l.525-532; id mint at l.537); presence →0 tombstones (does not
  recycle id).
- Lattice tasks `MapWriteTask` (l.411) and `LatticeInternTask` (l.454) already
  implement value-carrying merge with change-splitting (subsumed contributions
  nulled, ascending values rewritten in place and propagated) — the §7A.7
  "value-carrying delta" hook is half-built; DRed_L (docs/lattices.md) slots in
  at M7.
- **New generic task: `ReseedTask<A>`** — §4.2 scan of `C`.
- `WriteTask` (l.331): learn to *remove* index entries (reseed's `rec==0` deletes and the
  final sweep), not only insert.

### 6.3 Codegen — `compiler/emit-cpp.rkt`

- Emit `emit` → the counting/signed producer, parameterised by the rule's static
  `IS_REC` bit and a phase-supplied sign.
- Instantiate the new generic tasks (`ReseedTask<A>`, counting `InternTask`) per relation/
  bucket alongside the existing `WriteTask`/`InternTask`/`InternStructTask`
  registration (the `addTask`/`addIndex` wiring; read tasks register at
  emit-cpp.rkt:667 with the `static?` once-only flag from :447).
- No per-rule deletion variant is emitted — the negative phase reuses the same
  per-position semi-naïve delta-join variants already generated for insertion
  (join-planning.rkt picks the delta-driven clause per version; the planner is
  the 2026-07 staging/scheduling/versions rewrite).

### 6.4 Compiler pass — `compiler/stratify.rkt` (mostly built) + tagging (net-new)

**Current state (baseline — REWRITTEN 2026-07-08; the earlier version of this
section predated the 2026-07 compiler rewrite and described a compiler with no
stratification at all).** The compiler now HAS genuine SCC stratification:

- `compiler/stratify.rkt`: `stratify-rules` builds the rule dependency graph
  (body→head edges, plus all-pairs among a rule's own heads so co-heads land in
  one SCC), runs Tarjan (`tarjan-scc-ids`, :68), condenses, and assigns
  `scc-level = 1 + max(pred levels)` (:145). Rules are grouped into **one
  stratum per DAG level** — independent same-level SCCs are merged (:163).
  `rule-head-rels` / `rule-body-rels` (:53/:57) expose per-rule relation sets.
- `compiler/compile.rkt`: `compile-strata` (:345) drives it — **one stratum →
  one `.so`**, run in topological order by the driver with a daemon reload
  between strata (`beginStratum`/`needs_reload`, daemon.h:153/:64). A
  `#:split-facts?` mode pulls iteration-0 (body-less) rules into a level-0
  facts stratum (db-compression P0.5). `jobs->db-partition` (:299) already
  computes the per-run `idb-rels`/`edb-rels`/`mixed-rels`/`strata-range`/
  `productive-rels` partition.
- Per-stratum, `dynamic-rels` = the union of the stratum's own head relations
  (operationalization.rkt:84 → join-planning.rkt `dynamic?` :102 →
  emit-cpp.rkt `static?` :447): a read task whose driver clause reads only
  lower-stratum relations is registered once-only; others iterate.

**The useful structural fact:** because an inter-SCC dependency edge forces a
strictly greater level, two SCCs merged into one stratum are mutually
unreachable — so *a rule's body relation lies in the same stratum iff it lies in
the same SCC*. Hence the DRed^c classification needs no new analysis:

> a rule is **recursive** (bumps `rec`) iff some body relation ∈ its stratum's
> `dynamic-rels`; else **non-recursive** (bumps `nonrec`). Body-less/facts
> rules and EDB ingestion are `nonrec` by definition.

What remains for M2 is therefore **tagging and threading, not analysis**:

- Expose the per-rule rec/nonrec bit (and, for §7A's monotonicity checks, the
  per-body-clause same-SCC bit) as an explicit IR attribute — today the
  information exists only implicitly via `dynamic-rels` membership at emit time.
- Thread the bit into `emit`'s counter choice and the aggregate's barrier
  (§6.2), and into the stratum manifest the driver consumes.
- The daemon still has no SCC/stratum concept of its own beyond the resident
  stratum pipeline; the `Stratum::dynamic_rels` seam comment
  (database.h:877-879) and the daemon.h header note (:22-26, "re-running an old
  stratum requires re-binding") mark exactly where the three-phase driver (§4,
  §6.5) attaches. That re-binding work is shared with db-compression's
  edit-and-propagate ambition (db-compression.md §12) — build it once.

### 6.5 Driver — `daemon/database.h` fixpoint loop

*(re-anchored 2026-07-08: the per-stratum fixpoint is `runLoop` (database.h:1348)
with `runPhase` per phase (:1329) — write → read (suspendable) → intern →
`reorgAll` per iteration; the budgeted outer entry is `continueStratum` (:1437),
driven by `Daemon::continueRun` (daemon.h:291); `reorgDelta` is Relation-level
at :557; termination is `latest_any_rec` (:1062), set by `finalizeAll` on any
non-empty fresh delta and consumed by `EndIterCompletion` (:3037) → ACT_FIXPOINT
when nothing new; deferred reloads run through `reloadInsertBatches` (:2957) /
`beginStratum` (daemon.h:153).)*

- Generalise the phase loop to carry a **polarity** and run the three-phase, per-stratum
  schedule of §4.
- Between negative-phase iterations, accumulate the delta into `C` instead of merging
  into the main index; between positive-phase iterations, merge as today
  (`finalizeAll`/`reorgAll`).
- **Termination keys on presence transitions, not count changes** — the invariant
  maps directly onto `latest_any_rec`: `finalizeAll` must register only tuples
  whose PRESENCE changed (the §4.4 aggregate already pushes only those into the
  outgoing delta, so the existing "non-empty new delta" test keeps working) —
  otherwise a re-derivation that only bumps a count spins the loop. Revisit the
  arity-0 / `reorgDelta` guard from the earlier OOM fix under this new invariant.
- **Pausing (`docs/pausing.md`, now shipped) composes for free.** Pausing lives
  entirely in the read (delta-producing) phase — precisely the `_sliced`
  operators of §6.2 plus `ReadCompletion`'s mid-read suspend (:3013) — and is
  *exact* (park a continuation at the outer-loop position, resume there — no
  redo), while the counting aggregate (where `(nonrec,rec)` and `C` mutate) runs
  to completion. So a pause only ever leaves un-consumed delta records and never
  touches the counters — keep it that way (any counting phase that needs pausing
  must be resumable by an exact cursor, not by discard-and-rerun, since the
  counters are not idempotent). One NEW caveat since checkpoint-on-pause
  shipped: `writeDatabaseSerialBIN` (:2377) checkpoints a paused PARTIAL
  database; a partial fixpoint's counters are not reconstructible from its
  tuples, so once counting lands a checkpoint must either persist the counters
  or be treated as witness-only on resume (replay from EDB re-establishes
  counts) — see §8A.

### 6.6 Input protocol — `daemon/slogd.cpp` + `compiler/actions.rkt`

*(re-anchored 2026-07-08: the daemon protocol is one plugin path per line —
`run_stdin` (slogd.cpp:137) / `run_tcp` (:170); every verb beyond
`continue`/`continue-boundary`/`close` is a compiled action plugin from
`actions.rkt`. A positive single-fact path ALREADY exists: the `add-tuple`
action (actions.rkt:77) → `Daemon::addTuple` (daemon.h:240) →
`insertTupleAllIndices` + `needs_reload`, built for db-compression's
edit-and-propagate.)*

- Extend the `add-tuple` action family with a **sign** (`del-tuple`, or a signed
  batch action) feeding per-thread delta shards rather than direct index
  insertion — the existing action-plugin path is the natural transport; no new
  wire protocol is needed.
- Batch a set of changes and run one three-phase sweep per batch.
- db-compression's `edits` files (`(add-tuple REL v…)`, applied at layer
  boundaries on load) become the persistent face of the same mechanism: once
  DRed^c exists, `(del REL v…)` edits stop requiring full downstream re-replay
  (db-compression.md §12) and instead drive a negative sweep through the
  resident strata.

---

## 7. Structs: specific concerns

- Structs are derived (via `emit_struct`) and interned (`InternStructTask`), mapping
  content → id. With counting the master index maps content → `(id, nonrec, rec)`.
- **Id stability across over-delete/reseed is mandatory.** Other tuples embed a struct's
  id; if reseed/rederivation hands out a fresh id, every referent dangles. Keep `id` in
  the value, **tombstone at presence 0, never recycle** an id until a foundedness-safe
  reclamation pass proves no live referent remains (initially: never reclaim).
- Per-bucket id allocators (`operators.h` intern allocators) must not treat a tombstoned
  slot as free.

---

## 7A. Aggregation, rank, and lattice-valued recursion (plan-ahead)

> **See also `docs/lattices.md`** — the full batch-first design for
> lattice-valued relations (declarations, monotone-use calculus, runtime,
> milestones), written to slot into this section's M6/M7. It sharpens one
> point here: value-change deltas should travel as replacement *pairs*
> `(key, old, new)` so ⊑-increasing changes route through the monotone phase
> (IncA/DRed_L "change splitting") instead of the negative fixpoint.
> *2026-07-08: lattices L0+L1 are now SHIPPED* — `BTreeMapIndex` (index.h:104),
> `LatticeInternTask`/`MapWriteTask` (operators.h:454/:411), and the batch
> change-splitting behaviour (subsumed contributions nulled, ascending values
> rewritten in place and propagated) exist in the runtime, as do the extern
> set/map collection lattices (arena.h `merge_spec`). The §7A.7 "extensible
> index-value slot" and "value-carrying delta" hooks are therefore half-built
> already; M6/M7 extend working machinery rather than introducing it.

Aggregation is deferred past the first incremental milestones (M0–M4 do plain recursion),
but the substrate must **anticipate** it, because the mechanism that makes recursive
aggregation work is the *same* mechanism that makes recursive deletion precise. Get the
value slot, the delta format, and the rel-env right now and aggregation slots in without a
rewrite.

### 7A.1 An aggregate is a semiring fold — so it inherits stability exactly

An aggregate is a `⊕`-fold over a group. Putting one inside recursion therefore converges
**iff its semiring is *stable*** — the same condition from §1 (Abo Khamis et al., PODS
2022). Concretely:

- **tropical `(min,+)` is stable** → recursive `MIN`/`MAX` converges (shortest path,
  min-label connected components). Safe recursively.
- **`ℕ (+,×)` is not stable** → recursive `SUM`/`COUNT` diverges over cycles — the *exact*
  same failure as plain derivation counting in §1. Not safe recursively.

So recursive aggregation is not impossible; it is possible **precisely for the stable
(monotonic) aggregates**. The escape hatch and its practical test have names:
**monotonic aggregation** (Ross & Sagiv, PODS 1992 / JCSS 1997) and **pre-mappability
(PreM)** (Zaniolo, Yang, Das, Shkapsky, Condie, Interlandi, TPLP 2017; DeALS/BigDatalog),
which says exactly when `min`/`max` (and constrained `count`/`sum`) may be pushed inside a
fixpoint while preserving the least-fixpoint answer.

### 7A.2 Two kinds of per-fact state — keep them separate

Do not conflate foundedness with the aggregate value; they are orthogonal and both needed.

1. **Foundedness state** of the aggregate *result* tuple `agg(group,value)` — tracked with
   the same `(nonrec, rec)` / rank machinery as any derived tuple.
2. **Aggregate value state** — function-specific auxiliary state:

   | Aggregate | State per group | Deletion |
   |---|---|---|
   | `COUNT` | contributor count | trivial (−1; retract at 0) |
   | `SUM` / `AVG` | running sum + count | trivial (subtract; count says when empty) |
   | `MIN` / `MAX` | **whole contributor multiset** (sorted `BTreeIndex` by `(group,value)`) | *hard*: deleting the current extreme needs the next one |

   (Mumick/Quass/Mumick, SIGMOD 1997 — COUNT is kept precisely *so deletion works*;
   Palpanas et al., VLDB 2002 — the MIN/MAX auxiliary structure.)

Two rules that make this fit our framework:

- **Aggregate over the *set* of founded contributors, each once — not weighted by
  derivation count.** A contributor's `rec/nonrec` count governs *its* membership; while
  present it contributes once. The aggregate value is driven by contributors' **presence
  transitions** (the `±1` signals from §3.2/§4.4), never by raw counts.
- **A value change is `retract-old + insert-new`.** `agg(g,5) → agg(g,7)` emits
  `−agg(g,5), +agg(g,7)` — ordinary signed deltas, no new downstream mechanism.

### 7A.3 Rank *is* a recursive-min aggregate (the unification)

The `rank` from §"count+rank" (minimum derivation depth) is itself a recursive `MIN`
aggregate over the tropical semiring: `rank(t) = 1 + min over derivations of max(premise
ranks)`. So **foundedness-rank maintenance and recursive `MIN`/`MAX` aggregation are the
same computation**, and their hard case is the same: deleting the input that supplied the
current best = **decremental shortest path** = recompute the value from survivors and
propagate the regression. Build rank repair for foundedness and you have recursive
monotonic aggregation for free (and vice-versa).

### 7A.4 Rank-rebuilding vs. the `rec/nonrec` algorithm — same shape, finer grain

`(nonrec, rec)` is a **coarse, membership-only, 2-bucket approximation of rank**:
`nonrec>0` ≈ "grounded below this stratum" (a low, bounded rank); `rec`-only ≈ "rank
determined inside the SCC." DRed^c resolves the in-SCC part **bluntly** — over-delete the
region, rebuild from the boundary. Rank-rebuilding is the **fine-grained generalization**:

| | DRed^c `(nonrec,rec)` | rank-rebuilding (tropical) |
|---|---|---|
| per fact | 2 integer counters | 1 lattice value (+ how to find next-best) |
| resolves foundedness by | over-delete region + forward rederive | recompute value from survivors, propagate *regressions* only |
| over-work | can tear down + rebuild a whole region | touches only facts whose value actually changes |
| deletion style | invalidate-then-rebuild | Ramalingam–Reps decremental-SSSP |
| also gives you | membership | membership **and** the aggregate value |

Both share the skeleton — *localized recomputation triggered by deletion, bounded by a
well-foundedness/stability property* — and both face the same memory/compute trade: to
find the next-best derivation *without* re-running rules you must store per-derivation
info (heavy); DRed^c and forward-rebuild avoid that by re-deriving from the boundary.
`(nonrec,rec)` is simply the degenerate case of rank; rank is the version that also does
aggregation.

### 7A.5 The dovetail: user-declared stable semiring / semilattice

The crisp payoff — **one mechanism, parameterised by a semiring.** Let a relation declare
the lattice/semiring it aggregates over: a domain, `⊕` (combine — associative,
commutative; idempotent for a semilattice), `⊥`, and the order. The engine maintains the
lattice value incrementally with the shared rank-rebuild machinery. Built-in instances:

- **Boolean present-lattice** → plain membership (the DRed^c default).
- **tropical depth** → foundedness rank (internal, for recursive relations).
- **user lattices** → `min`/`max`/shortest-path/custom monotonic aggregates.

**Stability is the compile-time admissibility check:** a stable/monotone semiring may be
used *recursively* (Tier 2 below); a non-stable one (`SUM`/`COUNT`) is allowed only
*stratified* (Tier 1) or **rejected** with a clear error — the ℕ-not-stable boundary made
into a diagnostic. (Lattice-typed relations echo Bloom^L: Conway, Marczak, Alvaro,
Hellerstein, Maier, SoCC 2012.)

### 7A.6 Implementation tiers

1. **Tier 1 — Stratified aggregation (safe baseline; covers ~all practical use).** Require
   the group relation in a *strictly lower stratum* (M2 gives this; enforce + reject
   same-SCC here). Keep `(count,sum)` per group for `COUNT`/`SUM`/`AVG`; a sorted
   `BTreeIndex` multiset per group for `MIN`/`MAX`. Contributor presence-transitions drive
   it; value changes emit `retract-old + insert-new`. **Deletion is fully precise — no
   over-delete/rederive** (non-recursive w.r.t. its input). Drops straight into the
   three-phase driver as a higher-stratum relation.
2. **Tier 2 — Recursive monotonic aggregation (stable semiring).** Allow same-SCC
   `MIN`/`MAX`/user-lattice when PreM/monotonicity passes. Value = lattice element per
   group; lattice-semi-naïve for insertion (monotone, easy); deletion = the rank-repair
   path, **shared with foundedness**.
3. **Tier 3 — Reject recursive non-stable aggregation** (`SUM`/`COUNT` over cycles) unless
   acyclic grounding / a PreM certificate is proven.

### 7A.7 Forward-compatibility hooks to build during M0–M4

Even though aggregation ships later, these choices in the early milestones avoid a rewrite:

- **Extensible index-value slot.** Do not hardcode `struct Count { s64 nonrec, rec; }` as
  the only shape — make the per-relation value a configurable type so a relation can later
  carry a rank / lattice accumulator (or a `(count,sum)` / multiset handle) instead of
  bare counters.
- **Value-carrying delta records.** Allow a delta record to carry a payload, not only a
  sign, so `retract-old + insert-new` value changes and lattice deltas fit the same
  transport (§3.2 already separates the premise-signal from the counter update — extend
  the signal to optionally carry a value).
- **A semiring/lattice annotation slot in the rel-env / manifest**, default =
  support-counting (membership). This is where a user later declares `min`/`max`/custom.
- **M2 must also expose, per rule, the same-SCC bit per body predicate** — needed to
  classify recursive-vs-stratified aggregation and to run the monotonicity/PreM check.
- **Anticipate an aggregate rule form in the IR** (group-by vars + combine op) even if
  unimplemented, so `operationalization.rkt` doesn't need reshaping later.

## 8. Known caveats to design in now

- **Semi-naïve delta convention — now load-bearing in BOTH directions.** Negative
  propagation must respect the standard "delta-in-one-position against the
  pre-deletion state" convention, or two deleted supporters of one derivation
  double-decrement the consequence. slog already generates the per-position
  delta-join variants for insertion; the negative phase reuses them, but the
  **driver must sequence old/new state consistently.** The positive direction has
  the same requirement once counting lands: **iteration 0 (delta = the whole
  reloaded database) must fire each rule instantiation EXACTLY once.** Under set
  semantics a double-fire was absorbed by dedup and invisible; under counting it
  permanently corrupts counters. This is the headline M0 test (§10) — verify the
  2026-07 join planner's per-position versions partition instantiations exactly
  at the reload/iteration-0 boundary, not just mid-run.
- **Termination invariant** (§6.5): presence transitions, not count changes.
- **Struct id stability** (§7).
- **`C` lifecycle correctness:** after the positive phase, any candidate still at `(0,0)`
  that was not rebuilt is physically removed; anything rebuilt has a positive count and
  stays. (In the reseed formulation of §4.2, `rec==0` candidates are removed at reseed
  and only re-inserted if the positive phase re-derives them — equivalent.)

---

## 8A. Composition contract with db-compression (added 2026-07-08)

`docs/db-compression.md` shipped (2026-07-07) with loading defined as
**always-replay-from-origin**, and its layers may drop derived tuples from disk.
This section pins how that composes with DRed^c — the constraints are real but
all favourable.

### 8A.1 Dropped tuples on disk do NOT thwart incrementality

`(nonrec, rec)` are a deterministic function of `(EDB + edits, program)`: the
least fixpoint is deterministic, and the counters count one-step derivations
from it, which semi-naïve enumerates exactly once. So **any load path that
replays to fixpoint under a counting engine ends with exact counters**, no
matter how much was dropped on disk. Compression drops tuples, never
information — "load, replay, counts established, fully incremental from there"
is the operating model. Deletion **edits** compose the same way: today they are
sound via full re-replay (db-compression.md §12); under DRed^c they become the
negative input batches of §4.

### 8A.2 The one soundness trap: never ingest the kept sample as counted presence

A compressed load imports each layer's kept sample before replaying. Under
counting, a kept tuple ingested with any positive count is corrupted forever —
replay re-derives it and adds the true counts *on top*. Worse than imprecise: a
spurious `nonrec > 0` makes the fact **permanently undeletable** (the §4.1
barrier protects it from every future negative sweep). The contract:

- kept **table/lattice tuples** are ingested as *witness only* — they do not
  enter the live set with counts; replay re-derives and counts them. (Their
  seeding value was always marginal — db-compression.md §13: seeds never reduce
  join work, only rounds.)
- kept **struct-heap rows** are ingested as **tombstones** — id preserved,
  counters zero, absent-until-rederived. This is *exactly* the §7 tombstone
  shape DRed^c needs anyway: `InternStructTask` content-matches the tombstone,
  reuses its id, and bumps its counters — id stability and count correctness
  from one mechanism.

### 8A.3 `per = 100 %` loads come out incremental-ready for free

The `per=100%` "immediate fixpoint self-check" fires every rule once over the
full database and derives nothing new — under counting, **that single round IS
the count computation** (one-step derivations from the fixpoint). Expensive
layers kept whole therefore pay nothing extra to become DRed^c-ready. Corollary:
a `--trust` load that skips the check would leave counters at zero — trust-mode
and incremental-readiness are mutually exclusive unless counters are persisted
(defer; if ever done, gate on `compiler-stamp` match, since counters are
invalidated by any semantic compiler change even when the tuple set is not).

### 8A.4 Checkpoints need a count story

`writeDatabaseSerialBIN` checkpoints a paused PARTIAL database
(db-compression.md P2.3). Partial-fixpoint counters are not reconstructible from
the tuple set, so when counting lands either (a) the checkpoint format persists
counters, or (b) a resumed checkpoint is treated as witness/tombstones per §8A.2
and the replay restarts from the EDB (monotonicity makes any subset a sound
seed; only the count-establishing work is repeated). Decide at M0.

### 8A.5 Mutual payoffs

- **DRed^c gives the compression DAG O(change) edits:** edit-and-propagate stops
  re-replaying dependent layers and instead drives one three-phase sweep through
  the resident strata. The "re-firing an old resident stratum needs index
  re-binding" caveat (db-compression.md §12) is exactly the §6.5 driver work —
  build it once.
- **Compression gives DRed^c its struct-id reclamation pass:** §7 says
  tombstoned ids are never recycled online; a compressed save+reload compacts
  them for free (count-zero tombstones are not saved; replay re-mints densely).
- **The compression harness gives the count oracle:** `tests/compression/run.sh`
  already content-diffs a compressed load against a from-scratch run; extending
  it to also diff *counters* tests the whole §8A contract in one shot (§10).

---

## 9. Phased implementation plan

Each milestone is independently testable and delivers value before the next.

1. **M0 — Signed-count substrate.** `Count`/`SCount` index values; signed deltas;
   counting `emit`/`InternTask` with presence-transition propagation. Insertion still
   monotone, but now counter-based. Verify identical results to today plus correct
   counts — headline tests: **iteration-0 exact-once firing** (§8) and the
   **compressed-load count oracle** (§8A.5, §10). The §8A.2 witness/tombstone
   ingestion rule for compressed loads and the §8A.4 checkpoint decision land
   here too — they define what "load a saved db under counting" means.
2. **M1 — Bidirectional input protocol.** Signed variants of the existing
   `add-tuple` action (§6.6) feeding delta shards. Deltas can be negative.
3. **M2 — rec/nonrec tagging (stratification EXISTS since the 2026-07 rewrite).**
   Expose the per-rule bit (body relation ∈ stratum's `dynamic-rels` ⟺ same-SCC,
   §6.4) and the per-body-clause same-SCC bit as IR attributes; thread into
   `emit`'s counter choice and the manifest. No behaviour change yet for
   insertion. *Was "build SCC + topological stratification from scratch"; now
   tagging + threading only.*
4. **M3 — Non-recursive deletion.** For acyclic strata, signed counting is sound and
   complete both directions. Ship full incrementality for non-recursive programs. Big,
   safe milestone.
5. **M4 — Recursive deletion (DRed^c).** Candidate set `C`, negative fixpoint with the
   `nonrec>0` barrier, `ReseedTask`, three-phase driver (incl. the resident-stratum
   index re-binding shared with db-compression edit-and-propagate, §8A.5). This is
   the hard milestone.
6. **M5 — Struct GC discipline.** Tombstoning, id stability, (optional) safe
   reclamation — noting §8A.5: a compressed save+reload already compacts
   tombstoned ids, so online reclamation can stay "never".
7. **M6 — Stratified aggregation** (§7A Tier 1). `COUNT`/`SUM`/`AVG` via `(count,sum)`;
   `MIN`/`MAX` via a per-group sorted multiset; value changes as `retract-old+insert-new`.
   Fully precise deletion; no new recursion machinery. Requires only the M2 strata + the
   §7A.7 hooks.
8. **M7 — Recursive monotonic aggregation** (§7A Tier 2). User-declared stable
   semiring/semilattice; lattice-valued relations; rank-precise foundedness sharing the
   same rank-rebuild path. This is where `(nonrec,rec)` optionally generalises to a full
   tropical rank (§7A.4). Tier 3 rejection of non-stable recursive aggregates lands here
   too, as a compile-time diagnostic.

The M0–M4 substrate should already carry the §7A.7 forward-compatibility hooks so M6/M7
are additive, not a rewrite.

---

## 10. Testing strategy

The literature's counterexamples are the test suite. Each must match a from-scratch batch
recompute after a randomised insert/delete sequence:

- `R(y,x):-R(x,y)` symmetric closure — insert then delete the seed (unfounded cycle).
- `reachable` with `source` deletion leaving a live edge-cycle (unfounded cycle archetype).
- TC over cyclic graphs, deleting edges (must *stay* correct — the case pure counting
  handled).
- Diamond + chain (§5.2): over-delete then one-step re-found, plus a `(0,0)` relearn.
- SCC collapse: delete the single edge bridging two strongly-connected blobs.
- **Iteration-0 exact-once (M0 headline, §8):** run a program whose rules have
  multiple same-relation body clauses through a save → load → reload cycle
  (delta = whole db at reload) and assert every tuple's counts equal the
  from-scratch run's counts — a double-fired instantiation shows up as an
  inflated count even though the tuple SET matches.
- **Compressed-load count oracle (§8A.5):** extend `tests/compression/run.sh` to
  diff per-tuple counts (not just content) between a compressed load at each
  `per` and the from-scratch oracle — this exercises the §8A.2 witness/tombstone
  ingestion rule, id-preserving tombstone resurrection, and count regeneration
  in one harness.
- **Differential fuzzing:** random `±tuple` streams vs. full recompute, across programs
  with structs and multiple strata.

---

## 11. Future directions (not in scope)

- **DBSP nested incremental circuits** for O(change) recursion without over-deletion
  waste — a codegen project atop `emit-cpp.rkt` (integration/differentiation operators,
  nested recursive circuits).
- **Differential dataflow** (timestamp lattice, versioned traces) for O(change) even deep
  in recursion — an engine replacement with ~2–4× memory and a progress-tracking
  subsystem. Reach for it only if deep-recursion incremental performance demands it.

---

## 12. References

- A. Gupta, I. S. Mumick, V. S. Subrahmanian. *Maintaining Views Incrementally.* SIGMOD
  1993. (Counting algorithm and DRed; counting fails on recursion.)
- P. Hu, B. Motik, I. Horrocks. *Optimised Maintenance of Datalog Materialisations.*
  AAAI 2018. arXiv:1711.03987. (**DRed^c**: nonrec/rec split counters, three phases, no
  backward evaluation.)
- B. Motik, Y. Nenov, R. Piro, I. Horrocks. *Incremental Update of Datalog Materialisation:
  The Backward/Forward Algorithm.* AAAI 2015. (Foundedness via backward proof search.)
- B. Motik, Y. Nenov, R. Piro, I. Horrocks. *Maintenance of Datalog Materialisations
  Revisited.* Artificial Intelligence 269 (2019). (FBF; unifies DRed / B/F / counting.)
- M. Budiu, T. Chajed, F. McSherry, L. Ryzhyk, V. Tannen. *DBSP: Automatic Incremental
  View Maintenance for Rich Query Languages.* VLDB 2023. (Z-sets; recursion via nested
  circuits with `distinct`; least-fixpoint recomputation, not derivation counts.)
- F. McSherry, D. Murray, R. Isaacs, M. Isard. *Differential Dataflow.* CIDR 2013.
  L. Ryzhyk, M. Budiu. *Differential Datalog.* Datalog 2.0, 2019. (Signed multiplicities
  over a timestamp lattice.)
- T. Green, G. Karvounarakis, V. Tannen. *Provenance Semirings.* PODS 2007.
  M. Abo Khamis, H. Ngo, R. Pichler, D. Suciu, Y. Wang. *Convergence of Datalog over
  (Pre-)Semirings.* PODS 2022 / JACM 2024. (ℕ is not stable → counting diverges on
  recursion; stable semirings converge — the aggregation admissibility condition.)

### Aggregation

- K. Ross, Y. Sagiv. *Monotonic Aggregation in Deductive Databases.* PODS 1992 / JCSS
  54(1) 1997. (Aggregation monotone over a lattice composes with recursion.)
- C. Zaniolo, M. Yang, A. Das, A. Shkapsky, T. Condie, M. Interlandi. *Fixpoint Semantics
  and Optimization of Recursive Datalog Programs with Aggregates.* TPLP 2017. (**PreM** —
  when min/max/count/sum are safe inside a fixpoint; DeALS/BigDatalog.)
- I. Mumick, D. Quass, B. Mumick. *Maintenance of Data Cubes and Summary Tables in a
  Warehouse.* SIGMOD 1997. (Self-maintainable aggregates; COUNT retained for deletion.)
- T. Palpanas, R. Sidle, R. Cochrane, H. Pirahesh. *Incremental Maintenance for
  Non-Distributive Aggregate Functions.* VLDB 2002. (MIN/MAX auxiliary structures.)
- N. Conway, W. Marczak, P. Alvaro, J. Hellerstein, D. Maier. *Logic and Lattices for
  Distributed Programming* (Bloom^L). SoCC 2012. (Lattice-typed, monotone-composable
  relations.)
