# master-sim: trace-driven simulation of the master index

`sim.cpp` replays a relation's per-round candidate stream -- recorded by a daemon run with
`SLOG_DUMP_DELTA=<dir>` (docs/knobs.md) -- through two master designs and reports their costs:

- **A.** today's master: one btree per bucket, one `insertNew` descent per candidate;
- **B.** a run-set master: per bucket a list of sorted runs; a round's candidates are radix-sorted
  on the low 32 bits of each column (falling back to a comparison sort when the high halves
  vary), duplicates collapse by adjacency, a gallop-merge anti-join against every run drops the
  ones already present, the survivors become a new run, and tiered compaction (ratio `R`, run cap
  `K`) merges the two newest runs while the newest is at least 1/R of its predecessor.

Both models must agree on the number of new tuples per round (the report says so).  The read
side is approximated by point probes drawn from each round's candidates (`P` = probes per
candidate) against both models.

    g++ -O2 -std=c++20 -I ../../daemon -o sim sim.cpp
    SLOG_DUMP_DELTA=/tmp/d SLOG_THREADS=1 racket compiler/run.rkt -d <db> <prog>.slog
    ./sim /tmp/d/<relation>.bin [R=8] [K=6] [P=0.25]

The daemon's bucket hash is stood in for by a multiplicative hash; only the per-bucket sizes
matter for the costs measured here.  Results and the design they informed: docs/run-master.md.
