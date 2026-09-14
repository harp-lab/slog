# Sorted-run master: plan (2026-09-14)

**Status:** planning; measured by trace-driven simulation, nothing on the fixpoint path
changed yet.  Measurement knobs (`SLOG_ITER_TRACE`, `SLOG_DUMP_DELTA`) and the simulator
(`bench/master-sim/`) are in the tree, off by default.  Cost model background: stats.md §1.5.

## 1. Summary and decision

After the 2026-09 fixpoint arc a recursive closure spends ~85 % of its time in `intern`, one
btree descent per candidate (~100 ns) to answer "is this tuple new?".  Sorting a round's
candidates and merging them against sorted runs answers the same question at ~25–35 ns per
candidate on fat rounds -- but at ~250 ns on thin rounds, where the per-round fixed costs of
sorting, galloping and compacting swamp thirty candidates per bucket.  Both are measured below
on the real candidate streams of eight workloads.

**Decision: a hybrid master.**  Keep today's per-bucket btree as the *memtable* and add
sorted *runs* beside it.  A round whose bucket receives fewer than a threshold of candidates
takes today's path unchanged; a round above it is radix-sorted, merge-anti-joined against the
runs and the memtable, and its survivors appended as a new run.  Runs compact geometrically;
the memtable flushes into a run when it grows past a bound.  Reads consult the runs and the
memtable.  Everything is per relation, gated as the frozen index is gated (plain set relations
in semantic to-fixpoint runs), and converts back to a plain btree on the first point mutation.

Expected effect (from the simulation, intern only): transitive closure 2.46 → 0.83 s, multi-
source reachability 1.51 → 0.46 s, same-generation 0.18 → 0.06 s, a one-round 5M-row join
0.47 → 0.12 s; thin-round workloads unchanged by construction.

## 2. What the trace study measured

`SLOG_DUMP_DELTA=<dir>` appends every plain set relation's un-deduplicated candidate rows per
round to `<dir>/<rel>.bin`; `SLOG_ITER_TRACE=1` prints candidates / survivors / master size per
relation per round.  `bench/master-sim/sim.cpp` replays a dump through (A) today's master --
one `insertNew` per candidate into a per-bucket tlx btree -- and (B) a run-set master -- radix
sort on the low 32 bits of each column (falling back to a comparison sort when the high halves
vary), adjacent-duplicate collapse, gallop-merge anti-join against every run, survivors
appended as a run, tiered compaction (merge the two newest runs while the newest is ≥ 1/R of
its predecessor or more than K runs exist).  It checks that both agree on the survivors of
every round, and times P = 0.25 point probes per candidate against each.

### 2.1 Round profiles

| workload | relation | rounds | candidates | new | duplicate share | median cand/round | rounds under 4096 cand |
|---|---|---|---|---|---|---|---|
| transitive closure, sparse random graph | path | 19 | 23.4M | 7.9M | 66 % | 107K | 4 |
| multi-source reachability | reach | 7 | 19.2M | 2.0M | 90 % | 204K | 2 |
| same-generation, tree | sg | 1 | 2.2M | 2.2M | 0 % | 2.2M | 0 |
| chain closure | path | 2000 | 2.0M | 2.0M | 0 % | 1,000 | 2000 |
| transitive closure, denser graph | path | 101 | 11.6M | 9.8M | 16 % | 40K | 23 |
| same-generation, random tree | sg | 16 | 2.8M | 2.8M | 0 % | 64K | 4 |
| 0CFA over a 2000-node term | ret | 979 | 3.6M | 2.1M | 42 % | 454 | 744 |
| 0CFA | kstore / store / eval | 828 / 549 / 949 | 1.5M / 0.75M / 0.29M | 74K / 19K / 88K | 95–97 % / 70 % | 107 / 66 / 37 | ~90 % of rounds |
| arity-6 join, one round | out | 1 | 5.0M | 5.0M | 0 % | 5.0M | 0 |

Two populations: **fat rounds** (10⁵–10⁷ candidates, the closures and one-shot joins) and
**thin rounds** (tens to hundreds of candidates per round over many rounds: chain closures,
CFA-shaped programs), with the denser closure mixing both.

### 2.2 Absorb cost, A vs B (one thread, sum over the fixpoint)

| workload | A btree intern | B run-set absorb (R=8, K=6) | B ÷ A | B breakdown |
|---|---|---|---|---|
| transitive closure | 2459 ms (105 ns/cand) | **825 ms** (35 ns) | 0.34 | sort 507, anti-join 211, compact 108 |
| reachability | 1509 ms (78 ns) | **462 ms** (24 ns) | 0.31 | sort 423, anti-join 23, compact 17 |
| same-generation tree | 181 ms (82 ns) | **59 ms** (27 ns) | 0.33 | sort 42, compact 17 |
| arity-6 join | 472 ms (94 ns) | **118 ms** (24 ns) | 0.25 | sort 91, compact 26 |
| same-generation random tree | 256 ms (93 ns) | **97 ms** (35 ns) | 0.38 | sort 52, anti-join 14, compact 30 |
| denser closure (101 rounds) | 1909 ms (165 ns) | 1029 ms (89 ns) | 0.54 | sort 247, anti-join 482, compact 300 |
| chain closure (2000 thin rounds) | 190 ms (95 ns) | **499 ms** (249 ns) | 2.6 | sort 244, anti-join 130, compact 126 |
| 0CFA ret (979 rounds) | 241 ms (67 ns) | 254 ms (70 ns) | 1.05 | |
| 0CFA kstore / store / eval | 45 / 18 / 10 ms (24–35 ns) | 82 / 42 / 30 ms | 1.8–3.0 | sort dominates |

The compaction policy barely matters (R ∈ {4, 8, 16}, K ∈ {4, 6, 8} change fat-round totals
by < 3 %; runs per bucket settle at 2–5).  The thin-round loss is structural: with thirty
candidates per bucket the radix passes, the gallop into every run and the repeated merging of
tiny runs (13–27 copies per tuple on the chain) cost more than thirty cheap descents into a
tree that is itself hot in cache (the btree runs at 24–35 ns per candidate on the CFA relations).

### 2.3 Read side

Point probes drawn from each round's candidates, B (binary search per run, 2–5 runs) versus
A (btree): ratio 0.46–1.17, below 1.0 on eleven of fourteen relations.  Dense sorted arrays
probe no slower than the tree here even without the frozen index's lead directory, which would
apply per run.  Range walks across several runs (a k-way merge) were not simulated; see §6.

## 3. Design

### 3.1 Representation (per bucket of a plain set relation's ordering)
- `memtable`: today's `BTreeIndex<A>::tree`, unchanged.
- `runs`: a vector of sorted, duplicate-free `std::vector<Key>`, newest last, each with the
  frozen form's lead directory (`lead`/`off`) built when the run is created.  A *frozen* index
  is exactly this structure with one run and an empty memtable -- the two mechanisms unify.
- Invariant: the relation's content is the disjoint union of the memtable and the runs.

### 3.2 Absorbing a round (the intern phase, per bucket)
1. The partition step already gathers the bucket's candidate rows with their lead-cell
   addresses.  If the count is below `absorb_min_rows` (initial value 4096, tuned by the
   simulator), take today's path: `insertNew` into the memtable, null duplicates.
2. Otherwise: radix-sort the candidates on the low 32 bits of each column, last column first
   (NaN-boxed small ints and interned ids vary only there; if any column's high halves differ
   across the batch, fall back to `std::sort`); collapse adjacent duplicates, nulling the later
   copies; gallop-merge against every run and probe the memtable for the remainder, nulling the
   ones found; the survivors are the round's delta and become a new run.
3. Compaction: merge the two newest runs while the newest is ≥ 1/8 of its predecessor or more
   than 6 runs exist (both parameters knobs).  When the memtable exceeds `memtable_max_rows`
   (say 64K) flush it in one sorted pass into a new run and clear it.

### 3.3 Reading
- `lower_bound(k)` / `begin()` / `end()`: an iterator mode that merges the runs' ranges and the
  memtable's range (k-way with k ≤ 7; a run's range comes from its lead directory).
- `contains(k)`: memtable, then runs newest first.
- Semi-naive views: FULL = all; DELTA = the round's survivors, which is the newest run when the
  absorb path ran -- so the OLD view of the ternary cursors becomes "all runs but the newest"
  and the per-tuple `delta->contains` check disappears for absorbed rounds.
- Secondary orderings: the write phase already sorts the bucket's rows; for a run-set relation
  it appends them as a run in that ordering instead of point-inserting.

### 3.4 Eligibility and conversion
- Eligible: plain set relations (no struct id, not lattice, not counted) written by a semantic
  to-fixpoint stratum -- the gate `planStaticFreeze` already computes, applied at stratum
  entry to the relations the stratum writes.
- Any point mutation from outside the phase pipeline (`insertTuple`, `removeTuple`, session
  edits, the DRed^c sidecars, reloads) first *thaws*: merge every run into the memtable's tree
  (one bulk load) and drop the runs.  This is the frozen index's thaw generalised; correctness
  never depends on which representation is live.
- Persistence, the binary format, boundary dumps and the reload path see rows only and do not
  change.

### 3.5 Sorting
Radix on the low 32 bits with 11-bit digits (three passes per column) after a one-pass check
that every column's high 32 bits are constant within the batch; otherwise `std::sort`.
Interned strings, structs and sequences are ids in the low 35 bits and pass the check; floats
and mixed-type columns fall back.  For batches below ~2K rows use `std::sort` regardless (the
counting arrays dominate).

## 4. Codebase impact

| area | change |
|---|---|
| `daemon/index.h` | `BTreeIndex<A>` gains `runs` (generalising `flat`/`lead`/`off`), `absorbSorted(...)`, `flushMemtable()`, `compact()`, the k-way iterator mode; `thaw()` folds runs into the tree |
| `daemon/operators.h` | `InternTask` partition path branches on `absorb_min_rows`; `WriteTask` appends a run for run-set relations |
| `daemon/database.h` | eligibility at stratum entry (beside `planStaticFreeze`), thaw before every out-of-pipeline mutation, memory accounting for runs |
| generated code, interpreter, `plan.cpp` | none -- the iterator wrapper absorbs the third mode as it did the second |
| sessions / DRed^c / structs / lattices | untouched: they keep the plain btree by the gate |
| knobs | `SLOG_MASTER=btree|runs` (default btree until §7 phase 4), `SLOG_ABSORB_MIN_ROWS`, `SLOG_RUN_RATIO`, `SLOG_RUN_MAX` |

## 5. Testing plan

1. **Differential by knob.**  Every golden program and every bench program run twice, with
   `SLOG_MASTER=btree` and `=runs`; relation sizes, CSV content and `$stat_fires` must match.
   The exact-once fire audit is the sharpest oracle: the absorb nulls duplicate copies in the
   delta batches through the same lead pointers the partition path uses today, and a miscount
   there shows up as excess support in the counted flavors.
2. **The simulator as oracle.**  For each dump, the daemon's per-round survivor counts
   (`SLOG_ITER_TRACE`) must equal the simulator's; any divergence is a dedup bug, not a
   performance question.
3. **Batteries.**  Golden suite, session battery (the conversion paths: a session edit on a
   run-set relation must thaw and proceed), the M3/M4/M7 fuzzers, `incremental-stress`, and
   the tier-promotion harness (its fixture's speed assumptions may move again).
4. **Memory.**  Runs plus memtable must stay under today's footprint (dense arrays are smaller
   than tree nodes) except transiently during a merge; test under `SLOG_MEM_BYTES` caps so a
   compaction never trips the run where the btree did not.
5. **Benchmarks.**  The reference closures at 1 and 6 threads, the thin-round set (chain
   closure, 0CFA) which must be unchanged, and the one-round joins.

## 6. Risks and open questions

- **k-way range iteration** was not simulated.  A rule that probes a recursive relation with a
  bound prefix and walks the range pays a merge step per element while the bucket has several
  runs.  On the reference set only the 0CFA program probes recursive relations (every closure
  probes the static edge relation), and its relations are thin-round, so they stay in the
  memtable.  Measure on a non-linear closure (`path(X,Z) :- path(X,Y), path(Y,Z)`) before
  phase 4.
- **Compaction bursts** land in one bucket's task while others wait at the barrier; a few ms on
  10M-tuple relations, but visible on the phases line.
- **Threshold choice.**  `absorb_min_rows` decides which path a round takes; the simulator can
  sweep it per dump, and the daemon can log the chosen path per round under `SLOG_ITER_TRACE`.
- **Radix fallbacks.**  Floats and mixed columns sort by comparison; the win shrinks toward the
  btree cost on wide or float-keyed relations.  The simulator reports the fallback rate.
- **Struct relations** are excluded and the 0CFA workload spends half its time interning
  structs by content; extending runs to `InternStructTask` (content rows carrying the id) is a
  later phase.
- **What does not change:** the join algorithm, barrier structure, load path, incremental
  maintenance, persistence.

## 7. Rollout, each step behind a knob and reversible

0. *(done)* Measurement knobs and the simulator; the round profiles and the A/B numbers above.
1. `runs` inside `BTreeIndex<A>` with the k-way iterator, used first only to *replace the frozen
   form* (one run, empty memtable): no behaviour change, the code path exercised by every
   static relation.  Gate: golden + session batteries, the static-index benchmark unchanged.
2. The absorb path in `InternTask` behind `SLOG_MASTER=runs`, default off; differential runs
   (§5.1–5.2) over the golden set and the benches.  Gate: identical content and fires; intern
   on the fat closures within 20 % of the simulator's prediction.
3. Secondary orderings as runs in `WriteTask`; the OLD-view simplification in the ternary
   cursors.  Gate: cyclic-join benches unchanged or better.
4. Threshold and policy tuning from `SLOG_ITER_TRACE` on the bench set; then default on for
   eligible relations, `SLOG_MASTER=btree` retained as the escape hatch.
5. *(optional)* Content-run interning for struct relations.

## 8. Decision log

- 2026-09-14: sorted-run master adopted as the plan, **hybrid with the existing btree as
  memtable**, because the trace study showed a pure run-set losing 2–3× on thin rounds while
  winning 3–4× on fat ones; compaction policy left at R=8, K=6 (insensitive); frozen index to be
  re-expressed as a one-run instance of the same structure.
