# T6 — transactional mid-read restart

*Drafted 2026-08-11 (W5′ runtime/transaction arc, after T3b and T0(c)
closed).  **Status: slices (a)+(b) SHIPPED 2026-08-11 (as-builts below); (c)+(d) pending.**  Normative parents:
[execution-tiers.md](execution-tiers.md) §8.1 (the seven-step restart, the
ReadAttempt record), §8.2 (the side-effect audit, by name), §11's T6 item
list, §12 gates 7/13; [t5-contract.md](t5-contract.md) (whose replay/gate
machinery is the shipped precursor); [t0-contract.md](t0-contract.md)
slice (c) (whose fire vectors are the accounting substrate).  This
document pins the inventory, the slice order, and the exit gates; the
parents stay authoritative for mechanism.*

## 0. What T6 is for

One sentence: **make an in-flight read attempt abortable and restartable —
under a different executor — with every side effect accounted for.**

A read phase reads immutable indices and writes only fresh output; §8.1's
observation is that this makes restart *smaller than it looks*.  T6 is the
last runtime piece the W5′ activation spine needs: a reader pinned to an
old boundary stays pinned, a latest-following read crossing a publication
restarts, and RF5-B's private cone rebuild gets its one read-consistency
mechanism instead of inventing a second.

## 1. The inventory (what already exists, 2026-08-11)

§8.1's step 1 — bring workers to a read suspension — shipped with pausing.
Steps 2–5 have a shipped PRECURSOR in T5's `replayReadPhase`
(database.h): discard send shards, roll back fire tallies, discard the
read's captured proofs, reset `once_pending`/`task_cursor`, clear the
paused-continuation queue, re-enter at `RUN_MID_READ`.  Three gaps make it
a replay primitive rather than a transactional abort:

1. **It is gated to `RUN_READ_COMPLETE`** — the pre-commit gate, where no
   in-flight continuations exist.  A true mid-read abort must also accept
   `RUN_MID_READ`, where parked continuations must be dropped
   (`clearPausedPhase` already handles exactly this and is documented safe
   at suspension).
2. **Fire rollback rides an armed-only snapshot.**
   `restoreIterationFires` restores a copy taken at the iteration barrier
   *only while a level-1 watch is armed* — reachable-when-armed is an
   invariant, not an accounting model, and T6 restarts arrive without
   watches.  T0(c) c3 built the dense fire vector; §8.2's demand is the
   missing half: per-ReadAttempt staging merged at read commit.
3. **The error scratch is not cleared** (`pending_errors` per-thread prim
   state), and nothing names or bumps an attempt identity.

Everything else §8.2 names is already in the tolerated/discardable
columns: emitted error facts and harvested oracle answers ride send shards
(discarded with them); string/collection interning is append-only and
tolerated exactly as suspend already tolerates it; struct ids are assigned
at intern, never during read, so no identity leaks from an aborted
attempt.

## 2. What T6 must be true of

1. **§12.7, the equivalence gate.**  Aborting a read attempt leaves master
   indices, deltas, counts, oracle answers, error facts, stats, and output
   batches equivalent to a fresh read — proven by comparison against an
   undisturbed run, not by inspection.
2. **Monotone flavors only** (§8.1 decision 6): counted and
   signed-maintenance reads refuse restart at validation, with a typed
   refusal and a test driving it (§12.13's restart clause).
3. **Abort is not undo.**  Read-attempt abort is cheap because masters are
   unchanged; post-intern iteration undo needs undo logs and is explicitly
   NOT this feature.  The daemon never promises the second when the first
   suffices.
4. **The accounting is always on.**  Per-attempt staging must not be a
   mode: the fold-at-commit model replaces the armed-only snapshot
   outright, at the cost of one vector fold per read barrier.
5. **T5's surfaces stay byte-stable.**  `replay` keeps its narrower gate
   (`RUN_READ_COMPLETE` only — replay is a debugger continuation, not a
   scheduling tool); its fire semantics ride the new staging with no
   observable change (the protocol and session batteries are the proof).

## 3. Slices

### Slice (a) — ReadAttempt accounting

The staging model, always on:

- `fire_pending_vec` beside the committed vector, same slot table.  Bumps
  land in PENDING; `finalizeAll` (the read commit) folds pending into
  committed and zeroes it; abort/replay zeroes it; publication drains
  committed plus any unfolded pending (a safety fold for round shapes that
  publish without a final barrier).  The armed-only
  `snapshotIterationFires`/`restoreIterationFires` pair and its
  `fires_at_iteration` copy are DELETED — T5 replay's rollback becomes
  "zero the pending vector", which is exactly what it meant.
- `pending_errors` cleared on abort (the scratch is per-thread transient
  state; emitted error facts were already in the discarded shards).
- `read_attempt_gen`: a per-database attempt counter, bumped on every
  abort, exposed for the restart verb's reply and the eventual per-attempt
  stats records.

**Exit gate.**  A C++ battery case pinning the staging arms directly
(bump→discard→zero; bump→fold→discard→committed survives); stats battery
11/11 goldens unchanged; protocol + pause batteries green (T5 replay over
the new substrate, byte-stable).

#### Slice (a) as-built (2026-08-11)

Exactly the model above, in database.h: `fire_pending_vec` beside the
committed vector on one slot table; `bumpFiresSlot` stages,
`commitAttemptFires` folds at `finalizeAll` (the same single-threaded
point that turns shards into the next delta), `discardAttemptFires`
zeroes; publication drains committed + unfolded pending; the `firesFor`
probe sums both so callers see one truth throughout.  The armed-only
snapshot pair and `fires_at_iteration` are DELETED — `IterCompletion`
keeps only the proof-journal mark, and `replayReadPhase`'s rollback became
"discard the pending vector", which is what it always meant.
`clearPendingErrors` resets the per-thread prim scratch on abort;
`read_attempt_gen` counts aborts.  Gates: `test_read_attempt_fire_staging`
green in the interp battery; stats 11/11 goldens unchanged; pause 18/18;
protocol 172/172.

### Slice (b) — the abort primitive and its verb

`abortReadAttempt()` generalizes `replayReadPhase` to
`RUN_MID_READ ∪ RUN_READ_COMPLETE`: the same disposal plus dropped parked
continuations, cleared step stops, cleared error scratch, and the
generation bump; `replayReadPhase` delegates to it behind its narrower
gate.  The command verb:

```text
(abort-read)      -> (read-aborted (generation N))
                  -> (refused read-abort-admission ...)   not suspended at
                                                          an abortable park
                  -> (refused read-abort-flavor ...)      counted/maintenance
                                                          round resident
```

admitted while suspended exactly as the parked-debug verbs are.  A
successful abort leaves the run at `RUN_MID_READ` with cursors at origin;
`(continue)` reruns the read over the same immutable delta.

**Exit gate.**  §12.7 driven end to end: park a run mid-read under a
pathological budget, abort, continue to fixpoint; final relations AND
`$stat_fires` byte-equal an undisturbed run's.  Both refusal classes
driven by tests.

#### Slice (b) as-built (2026-08-11)

`abortReadAttempt` (database.h) is `replayReadPhase`'s body widened to
`RUN_MID_READ` — parked continuations dropped via `clearPausedPhase`
(documented safe exactly at a suspension), step stops cleared, error
scratch reset, generation bumped — and `replayReadPhase` now delegates to
it behind its original gate, so T5's replay semantics are one primitive
deep.  `abortObstacle` is `replayObstacle` widened by the one position,
inheriting the `external` (oracle-pending) refusal deliberately until
slice (d) verifies the answered-set idempotence.  The `(abort-read)` verb
joins the parked-debug admission class (a prepared boundary's lease must
admit it: RF5-B aborts reads inside boundaries).  Gate battery
`t6-restart` 5/5, new tier in ALL: abort at a genuine mid-read park with
**equivalence including `$stat_fires`** (the sharp edge — a double-count
would show), the admission refusal, the bare-form parse refusal, and the
§12.13 flavor refusal via a transient-armed round that then completes
normally.  One measurement recorded in the battery: a one-shot fan-out
join (250k pairs) completes its whole read inside a single budget unit
and parks only at `iter` — mid-read parks need the recursive 63k-path
chain, whose scan driver iterates far past the slice check.

### Slice (c) — restart under a different executor

The §8.1 payoff: abort at a park, re-register the stratum's tasks from a
DIFFERENT artifact through the shipped upgrade entry (the T3a/T5 swap
seam), continue — the read reruns under the new executor.  Both
directions stressed at sub-second budgets: interpreter → O0/O2 (a
promotion landing mid-read) and native → interpreter (level-1 debugging
enabled mid-SCC).  This slice owns wiring the promotion closure's
mid-read case (today it attaches at the next boundary; with (c) it may
restart the read) — policy stays conservative until measured.

**Exit gate.**  §12.7 under both flip directions at `SLOG_MAX_MS`-scale
budgets, plus §12 gate 8's resume-inside-nested-joins property preserved
(the interpreter side) — the existing interp battery already pins it.

### Slice (d) — the oracle-dispatch audit

§8.2's remaining name: `OracleDispatchTask` mutates the registry's
`answered` set while submitting to external backends during the read.
Verify and STATE the idempotence (the answered set suppresses
re-submission across abort/replay; harvested answers are shard-borne and
append-only-materialized), or stage dispatch to read commit if
verification fails.  Either way the outcome is a documented invariant
plus a battery case: abort a read with oracle asks in flight, replay,
compare answers and submission counts against an undisturbed run (the
mock backend makes both deterministic).

**Exit gate.**  The oracle abort/replay equivalence case green under
`SLOG_SMT_SOLVERS=mock`; the invariant stated in smt.md with a pointer
here.

## 4. What T6 hands the arc

RF5-B's activation (`prepare privately → heal → recount → pause or
publish`) needs exactly one read-consistency rule: pinned readers stay
pinned, latest-followers crossing publication restart.  T6 supplies the
restart half; N3's committed boundaries already supply pinning.  The
per-attempt stats records (`(RuleId, VariantTag)` keyed) are the deferred
T0(c) rekey's consumer — when (a)'s generation and staging meet the
rule-meta registry, the rekey has a reason to exist.
