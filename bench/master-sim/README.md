# master-sim: trace-driven simulation of the master index

`sim.cpp` replays a relation's per-round candidate stream -- recorded by a daemon run with
`SLOG_DUMP_DELTA=<dir>` (docs/knobs.md) -- through two master designs and reports their costs:

- **A.** today's master: one btree per bucket, one `insertNew` descent per candidate;
- **B.** a run-set master: per bucket a list of sorted runs; a round's candidates are radix-sorted
  on the low 32 bits of each column (falling back to a comparison sort when the high halves
  vary), duplicates collapse by adjacency, a gallop-merge anti-join against every run drops the
  ones already present, the survivors become a new run, and tiered compaction (ratio `R`, run cap
  `K`) merges the two newest runs while the newest is at least 1/R of its predecessor.

- **H.** the hybrid: a btree memtable per bucket takes a round of fewer than `T` candidates (each
  first checked against the runs, so memtable and runs stay disjoint); otherwise the memtable is
  flushed into a run and the round absorbed as in B.  `M` bounds the memtable (optional).
  `SIM_BLOOM=1` gives every run a blocked Bloom filter (8 bits/key) consulted before any binary
  search into it; `SIM_BLOOM=lazy` builds a run's filter only when a point probe first needs it.

All models must agree on the number of new tuples per round and on every read-side checksum
(the report counts mismatched rounds).  The read side is approximated by point probes drawn from
each round's candidates (`P` = probes per candidate) and by bound-prefix range walks (a
lower_bound on the first column, then the group) -- over the runs both as a k-way merge, which an
order-dependent cursor needs, and as a concatenation of each run's group, which the plain join
probe needs.

    g++ -O2 -std=c++20 -I ../../daemon -o sim sim.cpp
    SLOG_DUMP_DELTA=/tmp/d SLOG_THREADS=1 racket compiler/run.rkt -d <db> <prog>.slog
    ./sim /tmp/d/<relation>.bin [R=8] [K=6] [P=0.25] [T=4096] [M=65536]
    SIM_BLOOM=lazy ./sim /tmp/d/<relation>.bin 8 6 0.25 256

The daemon's bucket hash is stood in for by a multiplicative hash; only the per-bucket sizes
matter for the costs measured here.  Compare timings within one invocation only: the read-side
tests between rounds evict the masters and inflate every model's absorb figure relative to an
absorb-only run.  Results and the design they informed: docs/run-master.md.
