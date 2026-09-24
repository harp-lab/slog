# Sorted-run master: plan (2026-09-14)

**Status:** planning; measured by trace-driven simulation, nothing on the fixpoint path
changed yet.  Measurement knobs (`SLOG_ITER_TRACE`, `SLOG_DUMP_DELTA`) and the simulator
(`bench/master-sim/`) are in the tree, off by default.  Cost model background: stats.md §1.5.

## 1. Summary and decision

After the 2026-09 fixpoint arc a recursive closure spends ~85 % of its time in `intern`, one
btree descent per candidate (~100 ns) to answer "is this tuple new?".  Sorting a round's
candidates and merging them against sorted runs answers the same question at ~25–35 ns per
candidate on fat rounds -- but a pure run-set loses 1.3–3× on thin rounds, where thirty
candidates per bucket cannot amortise the per-round work and tiny runs are merged over and over.
Both are measured below on the real candidate streams of eight workloads, and so are three
hybrids, of which the third is the design.

**Decision: a hybrid master, in this exact shape.**  Keep today's per-bucket btree as the
*memtable* and add sorted *runs* beside it, disjoint from it.
- A round whose bucket receives fewer than **T ≈ 256** candidates takes the *thin path*: each
  candidate is checked against the runs (a Bloom filter per run answers the common "not there"
  in a few ns) and then inserted into the memtable exactly as today.
- A round at or above T takes the *fat path*: the memtable is first flushed into a run (one
  in-order walk), the candidates are radix-sorted and duplicate-collapsed, gallop-merged against
  every run, and the survivors become the new run.  The fat path never probes a tree.
- Runs compact geometrically (ratio 8, at most 6 runs; the policy is insensitive); a run's
  Bloom filter is built the first time a point probe needs it, so fat-only workloads never pay
  for one.
- Reads: point probes consult the memtable and the runs (filters first); an *order-free* range
  walk -- the plain join probe, which is nearly all of them -- concatenates each run's group and
  the memtable's, and only the order-dependent ternary cursor pays for a k-way merge.
Everything is per relation, gated as the frozen index is gated (plain set relations in semantic
to-fixpoint runs), and converts back to a plain btree on the first point mutation.

Measured effect on the intern phase (§2.4, one thread): transitive closure 2.86 → 0.92 s,
multi-source reachability 1.59 → 0.50 s, the denser closure 1.77 → 0.93 s, same-generation
0.24 → 0.10 s, a one-round arity-6 join 0.48 → 0.13 s; the chain closure and every relation of
the 0CFA program within ±5 % of today.  Order-free range walks run 2–14× faster over runs.

## 2. What the trace study measured

`SLOG_DUMP_DELTA=<dir>` appends every plain set relation's un-deduplicated candidate rows per
round to `<dir>/<rel>.bin`; `SLOG_ITER_TRACE=1` prints candidates / survivors / master size per
relation per round.  `bench/master-sim/sim.cpp` replays a dump through (A) today's master --
one `insertNew` per candidate into a per-bucket tlx btree -- (B) a pure run-set master -- radix
sort on the low 32 bits of each column (a comparison sort below 2048 rows or when the high
halves vary), adjacent-duplicate collapse, gallop-merge anti-join against every run, survivors
appended as a run, tiered compaction (merge the two newest runs while the newest is ≥ 1/R of
its predecessor or more than K runs exist) -- and (H) the hybrid of §1 with threshold T and
optional per-run Bloom filters.  It checks that all three agree on the survivors of every round
and on every read-side checksum, and times P = 0.25 point probes per candidate plus a capped
number of bound-prefix range walks against each.

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
| chain closure (2000 thin rounds) | 190 ms (95 ns) | **410 ms** (205 ns) | 2.2 | sort 37, anti-join 224, compact 148 |
| 0CFA ret (979 rounds) | 241 ms (67 ns) | 254 ms (70 ns) | 1.05 | |
| 0CFA kstore / store / eval | 45 / 18 / 10 ms (24–35 ns) | 82 / 42 / 30 ms | 1.8–3.0 | sort dominates |

The compaction policy barely matters (R ∈ {4, 8, 16}, K ∈ {4, 6, 8} change fat-round totals
by < 3 %; runs per bucket settle at 2–5).  The thin-round loss is structural: with thirty
candidates per bucket (the chain: 1000 candidates a round over 32 buckets) a binary search into
each of 4–5 cold runs per candidate and the repeated merging of tiny runs (18 copies per tuple)
cost more than thirty descents into a tree that is itself hot in cache (the btree runs at 24–35
ns per candidate on the CFA relations).  Sorting is *not* the problem once batches under 2048
rows use a comparison sort: 19 ns per candidate on the chain.

Timings are for comparison within one simulator run only: the read-side tests between rounds
evict the masters, which alone moves the btree's chain figure from 190 ms (an absorb-only run) to
300–340 ms (the runs of §2.4).

### 2.3 Read side

Point probes drawn from each round's candidates, runs (binary search per run, 2–5 runs) versus
btree: ratio 0.46–1.17, below 1.0 on eleven of fourteen relations; with Bloom filters 0.9–1.3.
Dense sorted arrays probe no slower than the tree even without the frozen index's lead
directory, which would apply per run.

Bound-prefix range walks (lower_bound on the first column, walk the group) are the join's read
pattern, and they split by whether the consumer needs the rows *in order*:

| relation | rows per walk | btree | runs, k-way merged | runs, groups concatenated |
|---|---|---|---|---|
| transitive closure `path` (10M) | 351 | 3.0 µs | 0.56× | **0.10×** |
| denser closure `path` (9.8M) | 592 | 5.3 µs | 0.53× | **0.08×** |
| reachability `reach` (2.0M) | 287 | 1.4 µs | 0.50× | **0.13×** |
| chain closure `path` (2.0M) | 484 | 6.1 µs | 0.44× | **0.07×** |
| same-generation tree / random tree, arity-6 join | 21 / 162 / 11 | 0.9–1.2 µs | 0.47–0.54× | 0.18–0.31× |
| 0CFA `ret` (2.1M) | 2731 | 9.1 µs | 1.26× | **0.13×** |
| 0CFA `eval` / `kstore` / `store` / `temp1x2` (small, hot) | 80–1127 | 0.1–1.3 µs | **1.9–3.2×** | 0.3–0.6× |

The btree walk costs 1–13 ns per row depending on whether the relation is cache-resident; a
sequential walk of a run's group costs 0.3–1 ns per row, and a k-way merge across 2–5 runs
3–6 ns per row.  So order-free consumers win everywhere, by 2–14×, and order-dependent ones win
on large relations but lose 2–3× on small hot ones with several runs.  In the daemon the plain
join probe (`join_probe`, `join_all`) is order-free -- it only feeds each match to the rule's
continuation -- and only the ternary prefix cursors of the WCOJ arms need the sorted union.

### 2.4 The hybrid, three iterations

Each iteration was run on all fourteen relations; intern totals in ms, one thread, T is the
per-bucket-per-round candidate threshold, runs of one simulator invocation each.

1. **Memtable probed per survivor.**  Thin rounds insert into the memtable; fat rounds anti-join
   the runs and then probe the memtable for every survivor.  *Loses:* on the denser closure
   (1250 candidates per bucket per round, 84 % new) every survivor pays a tree descent again --
   1110–2090 ms against the pure run-set's 913 and the btree's 1731 -- and the threshold could
   not fix it (T=16384 routed everything to the memtable and landed *above* the btree).  Also
   uncovered the invariant: the thin path must probe the runs before inserting, or survivors
   over-count (33 rounds disagreed on the 0CFA `eval` relation until fixed).
2. **Flush before fat.**  A fat round first walks the memtable into a run; the fat path then
   never touches a tree.  Matches the pure run-set on every fat workload (transitive closure 858
   vs 864, reachability 476 vs 453, denser closure 907 vs 905, same-generation 94 vs 91) and the
   btree on the chain (308 vs 330).  *Residual:* thin rounds that follow fat ones probe cold
   runs per candidate -- the 0CFA relations ran 5–30 % over the btree (`ret` 318 vs 246 at
   T=1024, `kstore` 52 vs 40).
3. **Lazily built Bloom filters (8 bits per key, blocked, two probes) per run.**  A filter is
   built the first time a point probe needs it -- the fat path, which reads runs only by
   merging, never builds one; eager filters had taxed the fat path 12–20 %.  Final numbers:

| workload | btree (A) | pure run-set (B) | hybrid, T=256, lazy filters | H ÷ A |
|---|---|---|---|---|
| transitive closure | 2857 | 937 | **916** | 0.32 |
| multi-source reachability | 1586 | 478 | **498** | 0.31 |
| denser closure (101 rounds) | 1769 | 941 | **934** | 0.53 |
| same-generation, random tree | 240 | 95 | **98** | 0.41 |
| same-generation, tree (1 round) | 164 | 54 | **56**¹ | 0.34 |
| arity-6 join (1 round) | 484 | 124 | **126**¹ | 0.26 |
| chain closure (2000 thin rounds) | 340 | 429 | **322** | 0.95 |
| 0CFA `ret` | 246 | 228 | **220** | 0.89 |
| 0CFA `kstore` | 41.0 | 43.1 | 43.0 | 1.05 |
| 0CFA `store` | 16.8 | 17.1 | 16.8 | 1.00 |
| 0CFA `temp1x2` | 59.4 | 57.6 | 59.8 | 1.01 |
| 0CFA `eval` | 9.5 | 10.2 | 8.8 | 0.93 |
| 0CFA `temp1x1` / `temp1x0` | 8.9 / 0.5 | 13.7 / 1.2 | 8.8 / 0.5 | 0.99 |

¹ iteration 2 figures; a one-round workload has no thin path and no filter to build.

T=256 beat T=1024 wherever they differed (`ret` 220 vs 248, `temp1x2` 60 vs 65, denser closure
934 vs 969): once the fat path flushes first and the thin path has filters, sort-merge already
wins at a few hundred candidates per bucket.  The threshold is a knob, not a cliff.

### 2.5 What the memtable is for

On the chain closure the hybrid never creates a run: the memtable *is* the relation and the path
is today's (`runs now 0.0/bucket`).  On the closures the memtable holds the thin tail rounds
after the last fat one and is never flushed again.  On the 0CFA relations it absorbs 80–95 % of
the bucket-rounds and is flushed 100–2000 times over a run -- cheaply, since it is small each
time.  A size bound M on the memtable never triggered on the reference set and stays an
optional knob.

## 3. Design

### 3.1 Representation (per bucket of a plain set relation's ordering)
- `memtable`: today's `BTreeIndex<A>::tree`, unchanged.
- `runs`: a vector of sorted, duplicate-free `std::vector<Key>`, newest last, each with the
  frozen form's lead directory (`lead`/`off`) built when the run is created, and a lazily built
  blocked Bloom filter (8 bits per key; one byte per tuple against 16–48 bytes of key).  A
  *frozen* index is exactly this structure with one run and an empty memtable -- the two
  mechanisms unify.
- Invariant: the relation's content is the disjoint union of the memtable and the runs.  The
  thin path maintains it by probing the runs before inserting; the fat path by flushing the
  memtable before absorbing.  Breaking it over-counts survivors (§2.4 item 1).

### 3.2 Absorbing a round (the intern phase, per bucket)
1. The partition step already gathers the bucket's candidate rows with their lead-cell
   addresses.  If the count is below `absorb_min_rows` (initial value 256, knob), take the
   *thin path*: for each candidate, test the runs' Bloom filters newest-first, binary-search
   only a run whose filter says "maybe" (its lead directory bounds the search), and if absent
   from every run `insertNew` into the memtable; null duplicates as today.
2. Otherwise the *fat path*: if the memtable is non-empty, walk it in order into a new run and
   clear it (it is disjoint from the runs, so no merge is needed).  Radix-sort the candidates on
   the low 32 bits of each column, last column first (NaN-boxed small ints and interned ids vary
   only there; if any column's high halves differ across the batch, or the batch is under 2048
   rows, use `std::sort`); collapse adjacent duplicates, nulling the later copies; gallop-merge
   against every run, nulling the ones found; the survivors are the round's delta and become a
   new run.
3. Compaction: merge the two newest runs while the newest is ≥ 1/8 of its predecessor or more
   than 6 runs exist (both parameters knobs).  A merged run drops its filter; the next point
   probe rebuilds it.  Optionally flush the memtable when it exceeds `memtable_max_rows`.
4. At the end of the fixpoint, compact to one run and (if the relation is read by a later
   stratum) build its lead directory: this *is* the frozen index of today.

### 3.3 Reading
- `contains(k)`: memtable, then runs newest first behind their filters.
- Order-free walks (`join_probe`, `join_all`, the semijoin probes): for each run, lower_bound via
  the lead directory and walk the group; then the memtable's group.  No merge.  The iterator
  wrapper gains a third mode that steps run by run.
- Order-dependent walks (the ternary prefix cursors of the WCOJ arms): k-way merge of the runs'
  groups and the memtable's group, k ≤ 7.
- Semi-naive views: FULL = all; DELTA = the round's survivors, which is the newest run when the
  fat path ran -- the OLD view of the ternary cursors becomes "all runs but the newest" and the
  per-tuple `delta->contains` check disappears for absorbed rounds.
- Secondary orderings: the write phase already sorts the bucket's rows; for a run-set relation
  it appends them as a run in that ordering instead of point-inserting into a non-empty tree
  (today's sorted write only bulk-loads an *empty* index).

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
and mixed-type columns fall back.  For batches below 2048 rows use `std::sort` regardless (the
counting arrays dominate; this alone took the pure run-set's chain-closure sort from 232 to
37 ms).  The simulator reports the fallback rate: 13–24 batches of ~7600 on the 0CFA relations,
none elsewhere.

## 4. Codebase impact

| area | change |
|---|---|
| `daemon/index.h` | `BTreeIndex<A>` gains `runs` (generalising `flat`/`lead`/`off`) with per-run filters, `absorbSorted(...)`, `flushMemtable()`, `compact()`, a run-stepping iterator mode and a k-way merged one; `thaw()` folds runs into the tree |
| `daemon/operators.h` | `InternTask` partition path branches on `absorb_min_rows` (thin: filters + `insertNew`; fat: flush, sort, gallop); `join_probe`/`join_all` take the run-stepping iterator, the ternary cursors the merged one; `WriteTask` appends a run for run-set relations |
| `daemon/database.h` | eligibility at stratum entry (beside `planStaticFreeze`), thaw before every out-of-pipeline mutation, memory accounting for runs |
| generated code, interpreter, `plan.cpp` | none -- the iterator wrapper absorbs the third mode as it did the second |
| sessions / DRed^c / structs / lattices | untouched: they keep the plain btree by the gate |
| knobs | `SLOG_MASTER=btree|runs` (default btree until §7 phase 4), `SLOG_ABSORB_MIN_ROWS` (256), `SLOG_RUN_RATIO` (8), `SLOG_RUN_MAX` (6), `SLOG_RUN_FILTERS=0` to disable the Bloom filters |

## 5. Testing plan

1. **Differential by knob.**  Every golden program and every bench program run twice, with
   `SLOG_MASTER=btree` and `=runs`; relation sizes, CSV content and `$stat_fires` must match.
   The exact-once fire audit is the sharpest oracle: the absorb nulls duplicate copies in the
   delta batches through the same lead pointers the partition path uses today, and a miscount
   there shows up as excess support in the counted flavors.
2. **The simulator as oracle.**  For each dump, the daemon's per-round survivor counts
   (`SLOG_ITER_TRACE`) must equal the simulator's; any divergence is a dedup bug, not a
   performance question.  The disjointness invariant of §3.1 is the one to watch: the
   simulator caught its violation as a survivor over-count within one workload (§2.4), and the
   daemon's audit would see it as excess `$stat_fires`.  A debug assertion that no memtable key
   is present in a run (checked on flush, O(n) with the sorted walk) belongs in the ASan build.
3. **Batteries.**  Golden suite, session battery (the conversion paths: a session edit on a
   run-set relation must thaw and proceed), the M3/M4/M7 fuzzers, `incremental-stress`, and
   the tier-promotion harness (its fixture's speed assumptions may move again).
4. **Memory.**  Runs plus memtable must stay under today's footprint (dense arrays are smaller
   than tree nodes) except transiently during a merge; test under `SLOG_MEM_BYTES` caps so a
   compaction never trips the run where the btree did not.
5. **Benchmarks.**  The reference closures at 1 and 6 threads, the thin-round set (chain
   closure, 0CFA) which must be unchanged, and the one-round joins.

## 6. Risks and open questions

- **Order-dependent range walks** over several runs cost 2–3× the tree walk on small, hot
  relations (§2.3).  Only the ternary prefix cursors of the WCOJ arms need them; on the
  reference set those arms fire on cyclic joins over *static* relations, which end the fixpoint
  as one run.  Mitigations if a recursive relation is both hot and leapfrogged: the memtable
  already holds thin relations; compact to one run at fixpoint end; a lower run cap for
  relations the planner marks as cursor-read.  Measure on a non-linear closure
  (`path(X,Z) :- path(X,Y), path(Y,Z)` under an arm) before phase 4.
- **Filter false positives** cost a binary search each; at 8 bits per key and two probes the
  rate is ~5 %, and the sim's thin-path figures include it.
- **Compaction bursts** land in one bucket's task while others wait at the barrier; a few ms on
  10M-tuple relations, but visible on the phases line.
- **Threshold choice.**  `absorb_min_rows` decides which path a round takes; 256 won or tied
  everywhere on the reference set, and the cost curves cross gently (§2.4).  The daemon should
  log the chosen path per round under `SLOG_ITER_TRACE` so a regression can be read off.
- **Radix fallbacks.**  Floats and mixed columns sort by comparison; the win shrinks toward the
  btree cost on wide or float-keyed relations.  The simulator reports the fallback rate.
- **Struct relations** are excluded and the 0CFA workload spends half its time interning
  structs by content; extending runs to `InternStructTask` (content rows carrying the id) is a
  later phase.
- **What does not change:** the join algorithm, barrier structure, load path, incremental
  maintenance, persistence.

## 7. Rollout, each step behind a knob and reversible

Two facts about the code shape the order.  First, *every* range read in the daemon goes
through one iterator type -- the generated operators in `operators.h`, the interpreter's
cursors in `plan.cpp` and `plan-count.cpp`, the query engine and the count tasks all use only
`lower_bound`/`begin`/`end`, `!=`, `++`, `*` (and the ternary cursors `lower_bound_from`) --
so a representation change is one class, and the compiler emits no index call of its own.
Second, a relation's FULL index is range-read *during* its own fixpoint whenever a rule has
it in the body with full access (non-linear rules, the two-dynamic-clause `_old`/`_new`
variants, the ternary cursors' OLD/NEW views), so reads over "memtable plus several runs" must
be correct before any round is absorbed into a run.  Hence: representation, then reads, then
the absorb, then the write phase, then defaults.

0. *(done, 09-14)* Measurement knobs `SLOG_ITER_TRACE`, `SLOG_DUMP_DELTA`; the simulator;
   the round profiles, the A/B/H numbers and the read-side study above.

1. **Runs inside the index class** *(09-23)*.  `BTreeIndex<A>` holds a `tree`
   (the memtable) and `std::vector<Run> runs`, a `Run` being the sorted array plus its lead
   directory; the static form is one run and an empty tree; `thaw` folds any number of runs
   back (bulk load for one run into an empty tree, merge otherwise).  No behaviour change: the
   range reads still assume the static invariant and every mutator thaws.  The static run's
   bounds are cached in two pointers because every range-walk loop re-evaluates `end()` per
   step: reached through the run vector it cost a 200-row walk 40 % (150 → 212 ns in a
   header-only A/B); cached, old and new forms are at parity on contains, walks and the
   gallop.  *Gate:* operator unit tests, golden subset, quick semantics, session battery, full
   golden suite; the static-index benchmark (tri_er, bowtie_tri, tc_er at 1 and 6 threads,
   `SLOG_STATIC_INDEX=1` vs `0`) keeps its ratios.  A lesson for phase 2: `begin()`/`end()`
   are on the per-row path of every consumer and must stay a load and a branch in every mode.

2. **Reads over memtable + runs.**  Two iterator forms behind the same class:
   - *merged*: a third iterator mode holding one cursor per source (tree iterator plus up to
     `SLOG_RUN_MAX`+1 run pointers), `*` = the minimum, `++` advances it, `==end` = all
     exhausted; `lower_bound_from` gallops per source.  Correct for every consumer, including
     the ternary cursors and the interpreter's, with no consumer change.
   - *run-stepping*: for the order-free consumers -- `join_probe`, `join_probe_sliced`,
     `join_all`, `exists_probe`, the `_old`/`_new` probes -- a `forPrefix<K>(key, cont)` on
     the index walks the tree's group, then each run's group (lower bound via the directory,
     end via the prefix), no merge.  The operators call it when runs are present; the
     interpreter's plain probe cursor can follow later.
   - `contains` already consults every source (phase 1).
   *Testing without an absorb:* a test-only knob `SLOG_STATIC_SPLIT=N` freezes a static index
   into N runs instead of one and leaves every N-th key in the memtable, so every static
   relation in the golden suite exercises the general read path against the single-run form.
   *Gate:* golden suite and session battery identical under the split knob; the static-index
   benchmark unchanged with the knob off; a bound-prefix microbenchmark of merged vs stepping
   vs tree on the dumped relations agreeing with §2.3.

3. **The absorb, behind `SLOG_MASTER=runs` (default `btree`).**  Eligibility at stratum entry
   beside `planStaticFreeze`: plain set relations (no struct id, not lattice, not counted)
   written by a semantic to-fixpoint stratum, master ordering the identity.  In `InternTask`'s
   partition path, per bucket per round: below `SLOG_ABSORB_MIN_ROWS` (256) the thin path --
   `insertNew` becomes "absent from every run (filters first), then tree insert", no thaw;
   at or above it the fat path -- `flushMemtable()`, radix sort with the comparison fallback,
   adjacent dedup nulling the later copies through the lead pointers the partition already
   carries, gallop-merge anti-join nulling the found, survivors appended as a run, tiered
   compaction (`SLOG_RUN_RATIO` 8, `SLOG_RUN_MAX` 6), filters built lazily on first probe
   (`SLOG_RUN_FILTERS=0` disables).  At fixpoint end compact to one run and build the
   directory: that is the frozen form the next stratum reads.  Every out-of-pipeline mutator
   keeps thawing.  Secondary orderings stay trees in this phase (each `BTreeIndex` is
   independent, so mixed representations per relation are fine).  *Gate:* the differential of
   §5.1 (`SLOG_MASTER=btree` vs `runs`: sizes, CSV content, `$stat_fires`) over the golden set,
   the session programs and the benches; per-round survivor counts equal to the simulator's
   (§5.2); the ASan build with the disjointness assertion on flush; intern on the fat closures
   within 20 % of §2.4, the chain closure and the 0CFA program within 5 % of `btree`; memory
   under `SLOG_MEM_BYTES` caps no worse than `btree`.

4. **Write phase and views.**  `WriteTask` appends the round's sorted rows as a run for a
   run-set relation's secondary orderings instead of inserting them one by one into a
   non-empty tree; the ternary cursors' OLD view becomes "all runs but the newest" when the
   delta is the newest run, dropping the per-tuple `delta->contains`; the interpreter's probe
   cursor takes the run-stepping form.  *Gate:* the write phase on the closures down; the
   cyclic-join benches unchanged or better; goldens identical.

5. **Tuning, then default on.**  Sweep `SLOG_ABSORB_MIN_ROWS` (128–1024), ratio and cap, and
   filter bits with `SLOG_ITER_TRACE` reporting the path taken per round; then
   `SLOG_MASTER=runs` becomes the default for eligible relations with `btree` kept as the
   escape hatch.  *Gate:* the full suite, the M3/M4/M7 fuzzers, `incremental-stress`, the
   tier-promotion harness, the memory-cap tests, and a full benchmark pass at 1 and 6 threads.

6. *(optional)* Struct relations: `InternStructTask` interns by content and is excluded above;
   content rows carrying the id could be absorbed the same way.  Half of the 0CFA program's
   time sits there.

Each phase is one or two commits and reverts cleanly; phases 3–5 are off by default until 5.

### 7.1 Open decisions to settle before phase 3

- **Where the memtable is flushed.**  The plan flushes it at the start of a fat round and
  never on size (no M).  The alternative -- also flushing when it exceeds M rows -- bounds the
  tree's size for readers but never triggered on the reference set; proposed: keep M as an
  optional knob, default off.
- **Filter geometry.**  8 bits per key, two probes in one 64-bit block, lazily built: ~5 %
  false positives, one byte per tuple.  Eager building taxed fat rounds 12–20 %; proposed lazy.
- **Threshold semantics.**  256 candidates per bucket per round, absolute.  The crossover
  depends weakly on the master's size (a small hot tree is cheaper), so a later refinement
  could scale T with the bucket's tree size; proposed: absolute, tune in phase 5.
- **Secondary orderings in phase 3 or 4.**  Leaving them as trees in phase 3 keeps that phase
  to the intern path; the closures have one ordering so they lose nothing.  Proposed: 4.
- **Run-stepping for the interpreter.**  The interpreter tier runs first under tiers, so
  order-free probes there matter for short programs; proposed in phase 4 after the compiled
  operators prove the form.
- **The delta as a run.**  The round's survivors are a sorted run *and* the delta; today the
  delta orderings are rebuilt each round by bulk load from the batches.  Sharing the array
  (zero-copy delta index) is a later saving, not in this plan.

## 8. Decision log

- 2026-09-14: sorted-run master adopted as the plan, **hybrid with the existing btree as
  memtable**, because the trace study showed a pure run-set losing 2–3× on thin rounds while
  winning 3–4× on fat ones; compaction policy left at R=8, K=6 (insensitive); frozen index to be
  re-expressed as a one-run instance of the same structure.
- 2026-09-14 (later): hybrid **iteration 1 rejected** (fat path probing the memtable per
  survivor re-pays the tree descent; denser closure 1110–2090 ms vs the run-set's 913);
  **flush-before-fat adopted** (matches the run-set on fat workloads); **lazily built per-run
  Bloom filters adopted** for the thin path (0CFA relations within ±5 % of the btree, fat path
  untaxed); **threshold 256 candidates per bucket per round** (beat 1024 wherever they
  differed); **order-free range walks concatenate the runs' groups** (2–14× faster than the
  tree walk), k-way merge reserved for the ternary cursors.
