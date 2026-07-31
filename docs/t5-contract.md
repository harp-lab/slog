# T5 + R4 — the debugger contract (level-1 watches, the pre-commit gate, stepping)

*Drafted 2026-07-31 (W4′ entry; pending review).  Normative parents:
[execution-tiers.md](execution-tiers.md) §7 (the pre-commit gate, provenance,
and the §7.3 monotone-only decision), [repl-ux.md](repl-ux.md) §9 (watch UX,
four-port stepping, why/why-not), [t0-contract.md](t0-contract.md) (reserved
verb families, the uniform pause record), [pausing.md](pausing.md) (sliceable
reads, budgets).  This document pins admission, the settle/apply factoring,
the slice order, and the exit gates; the parents stay authoritative for
mechanism.*

## 0. Scope and standing pins

1. **Monotone only** (execution-tiers §7.3, a decision not a question):
   level-1 watches, read replay, and stepping ship restricted to monotone
   set-semantics flavors (normal, seeded, `_delta` forward evaluation).
   Counted and signed-maintenance epochs are non-watchable at level 1 and
   non-replayable; the refusal is a STRUCTURED error
   (`(refused level-1-unwatchable ...)` naming the epoch flavor), and the
   M4N/M7 exclusions make this enforceable by test — a counted database
   answers level-0 watches and queries exactly as gate S proved, and
   refuses level-1 honestly.
2. **One pause record.**  The pre-commit pause is the SAME uniform
   structured pause record ratified at T0 (arbitrary or for-cause with a
   watch citation); `RUN_READ_COMPLETE` adds a phase value, never a second
   record shape.  Level-0 watches keep their shipped semantics untouched.
3. **Settle/apply is one factoring, not two interners.**  `WatchSettle`
   performs only the `settle` half of the shared transition
   (`settle(master, candidates) -> accepted / no-change`;
   `apply(accepted) -> mutate`), for active watched keys only.  Plain
   tables settle by master-absence; struct heads settle by CONTENT against
   the shipped M5 intern-identity/membership split (M5 is landed, so the
   struct case is co-design with existing machinery, not a wait); lattice
   heads settle through M6L's contributor-reduce (staged rows never mutate
   the resident payload map); M7's repair extends only the apply side and
   is out of scope here.
4. **Interpreter-first, frozen core intact.**  Candidate capture, ports,
   and frames are interpreter observations over the existing cursor stack
   (execution-tiers §4.2); no new opcode, no VM arm, no cursor method on
   the frozen core.  A level-1 watch on an SCC forces that SCC
   interpreted; everything else may stay native (per-SCC `auto`/
   `interpreted` policy).  The native→interpreter flip happens only at a
   clean iteration boundary — the same swap-safe point T3a's upgrade path
   uses, ridden in reverse.
5. **Reserved verbs activate; no second grammar.**  `debug-on`/`debug-off`
   (policy), `resume`, `replay`, `why-not-add` leave t0-contract's
   reserved-verb parking through the T0 dispatcher only.  Client spellings
   stay repl-ux §9's (`watch r17`, `break REL [@k] [when ...]`, `step*`,
   `frames`, `up`/`down`, `why`, `whynot`, `commit`/`replay`/`abort` at
   the pre-commit prompt).

## 1. The pre-commit gate (daemon)

`RUN_READ_COMPLETE`: when a completed read has candidate hits for an
active level-1 watch, the barrier skips `finalizeAll` exactly as a
mid-read suspension does.  At that point the old delta still drives an
exact replay, candidate rows are complete in per-thread send shards, and
no master or sidecar has changed (execution-tiers §7.2).  `WatchSettle`
previews only watched keys; the gate correlates accepted changes with
captured candidate derivations and emits ONE pre-commit pause.  The
client may `commit` (run the ordinary finalize/write/intern continuation
exactly once), `replay` (discard send shards + debug records, rerun the
same read from its origin, normally with deeper budgets), or remain
paused and observe — paused-mode queries are already proven against
parked epochs (gate S item 3; the quiescent-master classes admit them).

## 2. Candidate provenance and rendering

The interpreter records, per emitted candidate, its rule variant and
premise tuples (bounded per execution-tiers §7.4 budgets).  `why FACT`
renders a bounded proof tree through the standard tree canvas; `whynot
FACT` renders the FIRST-ITERATION failure frontier (deeper chase = R5).
Both work at any boundary and in paused mode; both echo their budgets.
Frames print the join stack with SOURCE variable names via rule-meta.

## 3. Stepping (four ports over the cursor stack)

Ports: `drive`, `match`, `miss`, `guard`, `emit` (repl-ux §9.3), plus
iteration ports.  Granularities: `step`, `step match`, `step fire`,
`step tuple`, `step rule rN`, `step iter`, `finish`.  A step target is a
body position of a rule variant — the granularity the interpreter
already owns.  Stepping is a PAUSED-MODE modality entered from a watch
or break pause; the session driver's `session-pause-hook` (shipped at
gate S) is the client seam: R4 replaces the hook's auto-continue with an
interactive pause state in the REPL server, and the Rust client renders
it.

## 4. Slices

- **(a) Policy, registration, refusals.**  *(Ratified 2026-07-31 with
  the §6 answers; scope adjusted accordingly.)*  Level-1 watch
  registration piggybacked on the level-0 grammar (`(watch ... (level
  1))` additive field, echoed in `watch-added` only when 1); per-SCC
  `auto`/`interpreted` policy CLIENT-side (a level-1 watch pins the
  relation's writer strata; re-entry sends resolve the canonical plan —
  the flip; the daemon wire verbs stay parked); non-interpreted SCCs
  auto-flip rather than refuse; query watches refuse level 1 (client-side
  re-counts).  The `level-1-unwatchable` refusal and Stratum flavor
  retention MOVE to slice (b): under the ratified firing point
  (level-1-only continuations) their first consumer is the gate, and an
  unconsumed field is an inert scaffold.  Exit: protocol battery pins
  registration round-trip + level parse refusal with level-0 lines
  byte-identical; REPL battery pins the spelling, the pin, tiers'
  `· debug` column, and the flip end to end (native-registered strata,
  plan re-entry, exact recompute).
- **(b) The gate.**  `RUN_READ_COMPLETE`, candidate capture, plain-table
  `WatchSettle`, the pre-commit pause record, `commit` and paused
  observation (no replay yet).  Exit: a REPL transcript drives add →
  level-1 watch hit → pre-commit pause → paused `?` queries →
  commit; differential: committed content byte-equal to an unwatched
  run; pause/protocol batteries extended.
- **(c) Replay + stepping.**  `replay` (shard/debug-record disposal,
  same-read rerun), the interactive pause state in the REPL server over
  `session-pause-hook`, `step*`/`finish`/`frames`/`up`/`down`.  Exit:
  replay-then-commit content equality; a stepping golden over a 3-rule
  fixture (the teaching transcript repl-ux §2.7 wants).
- **(d) Proof surfaces + non-plain settles.**  `why`/`whynot` trees,
  struct settle (M5 co-design), lattice settle (M6L contributor-reduce),
  hygiene + exit audit (M4N slice-4 shape): full suite, interp-union
  sweep, monotone-enforcement matrix vs the M4N/M7 exclusions.

## 5. Exclusions

Counted-sidecar preview/apply (lifting §7.3) — post-M7 milestone, not a
rider.  `whatif` cones and branching — R5.  T6 transactional mid-read
replacement — after T5.  Derived/parameterized watches — W5′.

## 6. Substrate notes (survey 2026-07-31; file:line as of db6b57f)

What exists, what is missing, and the review questions the gaps raise.

- **`(level 1)` is genuinely additive**: watch registration parses
  through a strict allow-list (`collect_fields`, slogd.cpp:1861 — one
  token to add), `WatchSpec` lives on Database (database.h:2674) with a
  positional brace-init in `addWatch` (database.h:4284 — append the
  field there too or it silently zero-inits).  Level-0 test lines stay
  byte-identical.
- **No daemon-side epoch flavor survives install.**
  `SealedKernelPlan::flavor` (plan.h:319) is dropped after
  `install_*_stratum`; `Stratum` retains only
  `semantic_instance`/`transient_instance` booleans
  (database.h:2321,2324).  The `level-1-unwatchable` refusal therefore
  has nothing to read today ⇒ slice (a) RETAINS the install flavor on
  `Stratum` (the daemon already re-derives it from the artifact stem,
  plan-count.cpp:1548).
- **The native→interp flip already works and nothing refuses it**: the
  upgrade entry path is executor-blind (`beginStratum` name+position
  match, daemon.h:641; `clearForUpgrade` database.h:2377; idempotent
  push).  A `.plan` re-sent for a native stratum parked at
  `RUN_AT_BOUNDARY` installs through `maybe_interp_plan_plugin`
  (slogd.cpp:106) — T3a's swap ridden in reverse, confirmed.  Caveat: a
  stratum already at fixpoint falls through to `fresh` (a NEW pipeline
  entry, not a flip) — the flip must catch the SCC parked.
- **The daemon has no per-SCC executor/policy state** — the tier lives
  only in the client's `sinfo` box.  REVIEW QUESTION 1: the `auto`/
  `interpreted` policy's home.  Proposed: CLIENT-side (the session
  already owns artifact choice and drives every re-entry; `debug-on`
  marks the sinfo so future re-entries send the `.plan`, and flips a
  parked native SCC immediately) — the daemon-side `debug-on`/`debug-off`
  wire verbs then stay PARKED until slice (b) needs a daemon-side
  capture toggle, which may be a plan-install argument instead.
- **REVIEW QUESTION 2: the refusal's firing point.**  Registration is
  VersionKey-bound while epochs are temporal, so
  `level-1-unwatchable` cannot fire at registration in general.
  Proposed: a `(level 1)` spec is accepted; during non-monotone strata
  (flavor ≠ normal/delta, or transient) its hits report exactly as
  level 0 and the pre-commit gate never engages; the STRUCTURED refusal
  fires when a level-1-only continuation is requested against such an
  epoch (replay/step at a maintenance pause).  Alternative: refuse
  registration when the bound relation `isCounted()` — rejected as too
  strong (counted relations still run monotone epochs).
- **Legacy-protocol sessions cannot express a level-1 pause** — the
  frozen 8-field positional record has no cause slot (daemon.h:1654).
  Level-1 is command-protocol-only; the legacy path keeps level-0
  semantics untouched.
- **Slice (b)'s site is `ReadCompletion`** (database.h:8300, where
  `finalizeAll()` runs at :8318) — NOT `EndIterCompletion`
  (database.h:8331), whose watch evaluation runs inside a `noexcept`
  barrier functor after delta finalization; a settle preview there
  would be too late for cheap replay and could not throw.
- **Watch verbs are not `refuseIfSuspended`-guarded** (that is why gate
  S could register at a parked barrier); a level-1 registration that
  must flip an SCC is the first watch-family command needing a
  park-position check.
- `watch_barrier_seq` is per-Database and monotone across all strata
  (database.h:4314) — it cannot identify which epoch a hit belongs to;
  slice (b)'s correlation needs the suspended stratum's identity, which
  `suspendedStratum()` provides.
