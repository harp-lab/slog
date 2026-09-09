# Cross-stratum index reuse (the boundary keep-set)

Status: **P1+P2 shipped 2026-09-07** (daemon-only, plan-byte-neutral).
**P3 decided 2026-09-08: NO as a compiler pass** — the measurement (§5)
refuted its premise and exposed the real residual, the SERIAL 0.B5
backfill of re-homed orderings; the follow-up is a deferred, bucket-parallel
backfill (daemon-only, §5).  P4 (virtual iteration-0 delta) is parked.

## 1. What the boundary used to do

In a batch pipeline run, every stratum fixpoint armed `needs_reload`, and
the next fresh install ran `reloadInsertBatches()`: dump EVERY relation's
rows into flat batches, `clearAllIndices()` on EVERY relation (erasing the
registrations too), then let iteration 0 of the incoming stratum re-intern
and re-insert every row into every requisitioned ordering, element-wise.
The only semantic payload was read-side: the dumped batches became the
incoming stratum's iteration-0 delta, which is how semi-naive evaluation
sees the inherited database as "new" exactly once.  For an ordering both
strata requisition, the destroyed tree was byte-identical to the rebuilt
one; for a relation the incoming stratum never mentions, the entire cycle
(plus the orphan-restore that re-materialized it) was pure waste.

## 2. The protocol as built

Three steps, replacing the eager dump-and-clear (daemon.h `boundary_pending`,
database.h `beginBoundaryInstall`/`boundarySweep`):

1. **Arm** — the fresh entry consumes `needs_reload` into requisition
   tracking on every relation (`Relation::beginRequisitionTracking`).
2. **Register live** — the incoming install's `addIndex`/`addMapIndex`
   calls record every ordering they requisition.  Idempotent
   re-registrations keep built trees; a genuinely new full ordering is
   populated by the existing 0.B5 backfill against the still-live
   database (the exact primitive hot swaps rely on).
3. **Reconcile at push** — after the stratum's tasks have bound their
   index arrays and its read manifest is installed, `boundarySweep`
   settles each relation:
   - **untouched** — the install requisitioned nothing for it (a relation
     outside the incoming program): content and registrations survive
     verbatim; `restoreOrphanRelations` skips it because its registrations
     are live.  (This includes the `$stat_*` tables, which the old
     boundary dumped, cleared, and orphan-restored every time.)
   - **keep-mode** (`Relation::keepEligible` — plain tables, arity > 0):
     `sweepToRequisitions(false)` — orderings the install did not
     requisition are dropped, everything else survives WITH content.  If
     the stratum READS the relation, its rows are dumped into
     `reloaded`-marked batches (`InsertBatch::reloaded`) forming the
     iteration-0 delta.
   - **rebuild-mode** (structs, lattices, arity-0) when READ:
     `sweepToRequisitions(true)` — same ghost-dropping sweep, but the
     surviving trees' CONTENTS are emptied (arrays kept, since tasks
     bound them), then the unmarked dump re-interns and re-writes
     everything at iteration 0 as the old boundary did.
   - **rebuild-eligible but unread**: no dump (its rows can reach no
     task), trees kept live, non-requisitioned orderings dropped.

   Ghost-dropping is load-bearing in BOTH modes: an ordering registered by
   an earlier stratum but not re-requisitioned has no WriteTask, and the
   shape-based selectors (`getAnyIndex`, the master/lookup memo
   recomputation, dumps, saves) could pick its empty/stale trees over a
   maintained sibling — the exact failure the first golden sweep caught on
   every struct-deconstruction program (`Could not find struct instance`).
   The old boundary erased ghosts implicitly by erasing every
   registration; the sweep does it explicitly.

   Second implementation lesson: the sweep fires at push **unconditionally
   on arming** — a maintenance-armed re-push (clear-and-rerun, replay,
   re-entry pickup) is still a FRESH install whose run needs its
   iteration-0 delta staged.  Gating the sweep on `semantic_instance`
   silently skipped the dump for every rerun/replay flow (the first
   full-battery sweep failed 8 session-machinery harnesses on exactly
   this); the pending flag's own scope — set at fresh entries, canceled by
   any interposing non-fresh entry — is the correct and only gate.

`SLOG_NO_INDEX_REUSE=1` (runtime-only; not in any cache key) forces every
declared relation onto the rebuild path — the faithful emulation of the
old boundary for A/B measurement and fault isolation.
`SLOG_BOUNDARY_DEBUG=1` emits one line per boundary:

```text
(boundary-sweep "name" (kept K) (rebuilt R) (untouched U) (dumped D)
                (ords (live L) (new N) (dropped X))
                (backfill (ords B) (rows RW) (ms M)) (ms S))
```

The first four counters are RELATIONS; `ords` counts the FULL orderings of
the swept relations — `live` re-requisitioned and kept, `new` created by
this install, `dropped` live before but not re-requisitioned — and
`backfill` is the 0.B5 copy that populated the creations from a live
sibling ordering (rows and ms).  NOTE that the backfill runs inside
`addIndex` on the install thread, serially, BEFORE the sweep: it is in
neither the `(fixpoint …)` ms nor the sweep's own `(ms S)`, only in wall
time.  `SLOG_BOUNDARY_DEBUG=2` adds per-relation stderr lines,
`[sweep] rel decl= keep= read=` and `[sweep-ord] rel live|new|drop [ord]`,
which attribute every re-homing to a relation and ordering.
`bench/boundary-study.sh` prints the summed backfill beside the sweep ms.

## 3. The two correctness cruxes

**The InternTask null-out.**  The iteration-0 intern nulls any staged row
already present in the master — with a KEPT master that would null the
entire dump and the stratum would fire on nothing.  Marked batches are
therefore skipped by InternTask entirely: they came from the surviving
master, so they are pre-deduped AND already present — neither nulled (they
must fire as the iteration-0 delta) nor re-inserted.  Ground facts staged
beside the dump are ordinary batches: one duplicating an inherited row
finds it in the kept master and nulls exactly as it would have against the
rebuilt master, preserving exact-once fire accounting.  Full-index
WriteTasks likewise skip marked rows (every surviving full ordering —
kept or backfilled — is already complete); delta-index writes and read
tasks consume them normally.

**Stale kept orderings.**  A kept ordering the incoming stratum did not
requisition has no WriteTask and would rot silently while the stratum
writes.  The sweep's keep-set is exactly the install's requisitions, so
this state cannot exist; seeded-only orderings keep their arrays (tasks
bind them) but empty their contents, as the old boundary left them.

## 4. Interactions preserved

- **Sessions**: resident delta/count/maintenance entries never reloaded and
  are untouched.  Re-pushes and clear-and-rerun re-registration are fresh
  entries and get the same keep-set win (composing with the §8B.4 oracle
  `pinned-rels`, which are subtracted from clear-sets before any of this).
- **Positional re-entry** (`bind-at P`) keeps the eager positional restage
  path unchanged.
- **Activation journal**: `boundary_pending` snapshots and restores beside
  `needs_reload`; a fresh install that dies before push is now
  NON-destructive (the old flow had already dumped and cleared), and any
  entry that interposes cancels the pending boundary by re-arming
  `needs_reload`.
- **Memory**: the boundary's double-buffer spike (flat dump + still-live
  trees) shrinks to the read-set; keep = requisitions-only, so no
  monotonic ordering growth.

## 5. Deferred

- **P3 — cross-stratum ordering alignment (compiler): DECIDED NO,
  2026-09-08.**  The premise was that table orderings re-home stratum to
  stratum as a *packer preference* that `pack-selections` `fixed` seeds
  could align.  Measured with the per-ordering counters above:

  *Golden corpus* (172 programs, interp, all passing): 164 programs with a
  boundary, 352 boundaries, 515 strata.  Full orderings at swept
  relations: 16 474 live, 1 188 new, 1 162 dropped (6.7 % churn, 71
  programs).  Backfill: 1 173 orderings, 11 972 rows, **3.8 ms against
  6 842 ms of summed fixpoint (0.06 %)** — negligible at golden scale.

  *Probe shape* (`bench/boundary-study.sh 500000 6`): every boundary after
  the first re-homes two 500k-row orderings; backfill 279 ms against
  264 ms of summed fixpoint (**105 %**, serial, invisible to both
  timers).  Index keeping saved 118 ms of iteration-0 rebuild on that
  shape and the serial backfill added 279 ms; the 1.7 → 1.4 s wall win
  came from P2's dump narrowing, not from keeping trees.  `chain`: zero.

  *Attribution* (`SLOG_BOUNDARY_DEBUG=2` on kcfa / schemecfa /
  seq_oracle / st_basic): 78–88 % of new orderings are on relations the
  incoming stratum READS — probe requirements, 2–3 orderings per reader
  (kcfa's `$sup` demand relations), which the writer's ONE free master
  could never have served; the reader's selection is hard (the probe
  shape needs r_i on column 1 → (1 0); only the writer's (0 1) was free).
  Orderings dropped by an untouched stratum were re-needed later 0–1
  times.  The remaining 12–22 % is **ping-pong**: the ABI-2 cohort
  declares EVERY program relation in every stratum (canonical-plan.rkt,
  "all storage declarations ride the cohort"; emit-cpp's manifest
  keep-alive decls likewise) with the default `(range arity)` when the
  stratum has no selections, so an untouched relation whose live ordering
  was non-default is dropped and re-homed to the default — 50 % of the
  probe shape's waste, but tiny relations on the analyzers (kcfa: 759
  rows over 286 backfills).

  Hence: seeding the packer cannot align anything (the reader side is
  fixed, the writer side is one ordering); a FORWARD alignment (writer
  materialises the readers' orderings) moves exactly the same inserts
  into the writer's parallel WriteTasks — i.e. its whole value is
  parallelism, which the daemon can provide without a plan-byte change.
- **P3-D — deferred, bucket-parallel backfill** (daemon-only, the
  follow-up): under requisition tracking, `addIndex` records a pending
  `ord ← src` instead of copying inline; `boundarySweep` runs per-bucket
  backfill tasks in phase 0 beside the dumps, and SKIPS the backfill for
  rebuild-mode survivors (today a re-homed struct/lattice ordering is
  backfilled and then emptied by the sweep).  Ghost hazard: `getAnyIndex`
  and the backfill `src` pick must skip pending orderings until they are
  filled.  The eager copy stays for non-tracking paths (hot-swap, delta
  re-push — 0.B5's original clients).  Expected on the probe shape:
  ≈ −240 ms of 1.4 s.  Ping-pong suppression (declaration-only relations
  requisition nothing when the relation already has live trees) is a
  compiler change worth at most 12–22 % of churn on the analyzers (the
  cohort declarations sit outside the kernel exec key, so it would be a
  plan-golden re-record, not a re-key); not scheduled.
- **P4 — virtual iteration-0 delta**: alias delta reads to the kept full
  trees at iteration 0, eliminating the dump/reorg/delta-build for read
  relations too.  Deep read-path surgery; parked.
- **Struct/lattice keep-mode**: needs the id-keyed intern + tombstone
  (M5) and payload-map audits before marked batches may skip their intern.
