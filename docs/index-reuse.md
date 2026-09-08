# Cross-stratum index reuse (the boundary keep-set)

Status: **P1+P2 shipped 2026-09-07** (daemon-only, plan-byte-neutral).
P3 (compiler ordering alignment across strata — a plan-byte change) is a
measured decision recorded in §5; P4 (virtual iteration-0 delta) is parked.

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
`SLOG_BOUNDARY_DEBUG=1` emits one
`(boundary-sweep "name" (kept K) (rebuilt R) (untouched U) (dumped D) (ms M))`
line per boundary.

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

- **P3 — cross-stratum ordering alignment** (compiler): keep-mode only
  helps where orderings textually coincide; table masters re-home stratum
  to stratum (the T4 subset-chain re-pack residue), so feeding previous
  strata's choices into `pack-selections` as preferred `fixed` seeds would
  widen the win.  Plan-byte change: global re-key, plan-goldens re-record,
  abi2/tu-det/plan-det gates.  Decide from bench/boundary-study.sh numbers.
- **P4 — virtual iteration-0 delta**: alias delta reads to the kept full
  trees at iteration 0, eliminating the dump/reorg/delta-build for read
  relations too.  Deep read-path surgery; only if P3 still leaves meat.
- **Struct/lattice keep-mode**: needs the id-keyed intern + tombstone
  (M5) and payload-map audits before marked batches may skip their intern.
