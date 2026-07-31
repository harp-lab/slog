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

- **(a) Policy, registration, refusals.**  Per-SCC `auto`/`interpreted`
  policy verbs (`debug-on`/`debug-off`), observer ownership, the
  native→interp boundary flip, level-1 watch registration piggybacked on
  the level-0 grammar (`(watch ... (level 1))` additive field), and the
  two refusals: counted/maintenance epochs (`level-1-unwatchable`) and
  non-interpreted SCCs auto-flip rather than refuse.  Exit: protocol
  battery pins registration, flip, both refusals; level-0 batteries
  byte-unchanged.
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
