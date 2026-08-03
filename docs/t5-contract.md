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
- **(b) The gate.**  *(Shipped 2026-07-31; two additions the
  choreography forced, both flagged for review.)*  `RUN_READ_COMPLETE`
  parks at `ReadCompletion` before the deferred finalize (a third state —
  `read_suspended` definitionally requires unfinished work); the resume
  finalizes single-threaded in `continueStratum` before the parallel
  region and enters at intern — plain `(continue)` is the commit, the
  t0-ratified spelling.  Plain-table `WatchSettle`
  (`hasAcceptedCandidate`: send-shard scan + any-full-ordering absence
  probe through a `makeIndexRec`-style contains ladder); `gate_hits`
  kept apart from `watch_hits` so level-0 park triggers and dedup stay
  byte-identical; gate-settled watches are `gate_owned` for one
  iteration so nothing reports twice.  `Stratum` retains its install
  flavor (exact from sealed plans; arming-derived for native installs —
  a NORMAL artifact re-entered under maintenance arming is stamped
  "maint", its epoch's truth).  FORCED ADDITION 1: **prepare-time watch
  registration** (the R2 leftover) — a semantic run writes successor
  instances, so without it the gate is unreachable; `session-prepare-
  hook` + the REPL's level-1 rebind bind the prepared key, resolved
  through the private overlay (`watchTarget`), with `watch`/`unwatch`
  exempt from the boundary lease (session debugging state).  FORCED
  ADDITION 2: **gate-park lease reads** — `query`/`query-page`/
  `query-cancel`/`catalog` are admitted under the lease ONLY while
  parked at `RUN_READ_COMPLETE`; both the catalog snapshot and the bound
  keys are committed truth, which is §7.2's "remain paused and inspect"
  made concrete.  The `level-1-unwatchable` refusal moves to slice (c)
  with `replay`/stepping — the ratified firing point (level-1-only
  continuations) has no reachable surface before them; meanwhile the
  §7.3 downgrade is behavioral: maintenance epochs never engage the gate
  and level-1 hits stay at iteration barriers (battery-pinned).  Exit
  (met): REPL battery drives run → prepare-rebind → gate park (phase
  read + watch cause, iteration 0) → paused `?count` answering
  committed masters → commit; committed content byte-equal to an
  unwatched run; level-0 and maintenance controls; protocol pins for
  lease registration + still-refused catalog outside the park.
- **(c) Replay + stepping.**  `replay` (shard/debug-record disposal,
  same-read rerun), the interactive pause state in the REPL server over
  `session-pause-hook`, `step*`/`finish`/`frames`/`up`/`down`.  Exit:
  replay-then-commit content equality; a stepping golden over a 3-rule
  fixture (the teaching transcript repl-ux §2.7 wants).  Shipped in parts;
  stepping is still open:
  - **(c1) the rerun and the refusal** *(2026-07-31)*.  `replay` leaves
    reserved-verb parking through the T0 dispatcher.  At a gate park
    `Database::replayReadPhase` discards every relation's send shards
    (`discardSendShards` -- no finalize, and struct ids are minted in the
    INTERN phase, so a discarded read leaks no identity), rolls the
    iteration's `$stat_fires` tallies back to the snapshot `IterCompletion`
    takes while a level-1 watch is armed, re-arms `once_pending[phase_read]`
    (runPhase's completed-read tail had already cleared it -- without this
    the rerun would be a SMALLER read), and re-enters at `RUN_MID_READ`,
    which is exactly "the read phase again, without the iteration barrier or
    the write phase".  The old delta and its indices are untouched, so the
    rerun is exact and parks with an indistinguishable record.
    `replayObstacle` orders the refusals FLAVOR FIRST: a counted or
    maintenance epoch answers `level-1-unwatchable` naming that epoch's
    retained flavor (§0.1's ratified firing point -- replay is a
    level-1-only continuation, and this is its first reachable surface);
    any other park answers `replay-unavailable` with the position; and
    outstanding oracle work refuses rather than promising an
    unreproducible rerun.  The client seam is the pause hook's RETURN value
    (`'replay`); a refusal the driver meets is echoed, committed past, and
    rendered in the change summary (`refused: ...`) rather than swallowed.
  - **(c2) the gate as a place** *(2026-07-31)*.  A session with a level-1
    watch armed -- and no embedding hook of its own, which then owns the
    pause -- runs its commands on a HELD thread: at a gate park the REPL
    answers with the pause record instead of a change summary, ordinary
    commands then observe the parked epoch, and `commit` / `replay` /
    `abort` resolve it.  `commit` returns the held command's own summary
    (the held continuation still owns the prepared boundary, the remaining
    strata, and the rendering); `abort` raises an `exn:fail` subtype into
    the held thread so the session's existing abort-boundary unwind -- and
    the daemon's forced settle of a parked gate epoch -- discards the change
    with no second path.  A dropped connection resolves a held run rather
    than stranding it.  repl-ux §9.2's "the pause is simply a place" made
    literal.
  - **(c3) stepping** *(2026-08-01)*.  The interpreter already owned the
    mechanism -- interp.h's eight D15 ports, `DebugSink` with a per-event
    mask, `DebugAction::pause` (post-transition, so a resumed continuation
    never retriggers), `DebugView`'s cursor stack with a lazy `proof()`,
    `StopReason::breakpoint` -- so this slice is the translation layer, not
    a new machine.  `StepSink` (plan.h, because interp.h includes
    database.h) maps the operator's granularity to an event mask and
    materializes the stop; Database holds the granularity, the filter and
    the stop as PLAIN state.  The cost is honest: a disarmed session's mask
    is 0, which selects the machine's separately compiled fast loop, so
    `InterpReadTask` switching from `run_fast` to `run` changes nothing for
    an ordinary run.  A stop parks the continuation exactly as a budget
    pause does and asks the run to suspend, so `ReadCompletion`'s
    `stopped && work_left` test produces an ordinary `RUN_MID_READ` park
    carrying a `breakpoint` cause -- no new pause shape.  Wire verbs:
    `(step [match|fire|emit|tuple] | step rule N)` and `(frames)`, refusing
    flavor-first exactly as replay does.  From a GATE park a step replays
    the completed read (slice (c1)) and stops at the first matching port --
    walking the very read that produced the candidate; from a step stop it
    carries on.  The lease widens by exactly one park: queries and catalog
    are admitted at a mid-read STEP STOP, the same quiescent-master state
    one transition earlier.  At the prompt: `step`, `step iter`/`finish`
    (to the next clean boundary, held by a one-shot flag since that pause
    carries no debugger cause), `frames`, beside commit/replay/abort.
    A granularity with no matching port in the rule at hand simply runs on
    -- a single-body-position rule's one position IS its driver, so it has
    no `match` port, which is the ports being honest about the plan rather
    than a hole.  Determinism note: the first observer to claim a stop
    wins, so a step is a determinate place only under `SLOG_THREADS=1`,
    which is how the battery pins it.  Exit, met: the REPL battery walks
    the 3-rule fixture end to end --
    gate park, `step tuple` to the driver port, `frames` (stable across
    repeats, and the read still uncommitted), `step emit` re-arming a
    PARKED continuation at a new granularity, `finish` back to the gate,
    then one commit landing the change exactly once.  Pinned by ASSERTION
    rather than a byte-golden on purpose: a step record names the
    content-addressed stratum and the rule position, so a transcript
    golden would gate unrelated compiler churn on debugger output -- the
    same lesson as "gate on .plan diffs, not TU text".
    - STILL OPEN, deliberately: (i) `frames` prints the join stack
      STRUCTURALLY (port, rule position, driver row, premise rows).  Source
      VARIABLE NAMES need the canonical plan's `rule-meta` -- today only
      `(rid source)` -- to carry a register-to-name map, and every byte of
      that plan text is the KernelPlanKey, so widening it moves every
      artifact hash: its own change, with the plan-determinism goldens.
      (ii) `up`/`down` are a cursor over a stack the server already prints
      whole -- the interactive canvas's job, with the Rust client work.
- **(d) Proof surfaces + non-plain settles.**  Sub-sliced in this document
  (one certification gate remains: the slice, not its parts).
  - **(d1) Provenance capture and `why`.**  *(Shipped 2026-08-01.)*
    The interpreter's `emit` port
    plus `DebugView::proof()` are the whole mechanism; what (d1) adds is a
    place to put the answer and a way to ask.  Capture is OPT-IN PER WATCH
    -- `(watch ... (level 1) (provenance #t))`, additive and echoed only
    when true -- because an armed gate alone leaves the mask at 0 and takes
    the fast loop, and paying the observed loop for every gate run to
    answer a question nobody asked is the cost dishonesty §7.4 warns
    against.  The journal is RUN-SCOPED and bounded (records per run,
    derivations per fact, §7.4's first-N-plus-omitted-count), keyed by
    (relation, tuple) in NOMINAL column order -- cursors expose physical
    index rows, so capture inverts each ordering at the callback, where the
    schema is known; a replayed read discards its own records first, so an
    exact rerun stays indistinguishable here too.  Set heads only: a
    `mkstruct` head stages content without its id (the id is minted in the
    intern phase), so a struct head's candidate has no key until (d4).
    Because capture spans every iteration of the armed run, a proof TREE is
    real within that run: premises resolve against the journal and expand,
    and a premise the journal does not hold renders as a leaf naming its
    relation -- EDB, pre-arming, or over budget, stated rather than
    implied.  `why` at a gate park with no argument explains the candidates
    that tripped the gate (the gate's settle now retains them, bounded --
    contract §1's "correlates accepted changes with captured derivations"),
    which is also the only spelling that can name a candidate that is not
    yet committed truth; `why FACT` resolves its ground terms through
    `query::resolve_literal`, the same probe-only encoder R2's `uses`
    already shares.  Determinism: workers emit concurrently, so which
    derivations survive a per-fact cap is pinned only under
    `SLOG_THREADS=1`, exactly as a step stop is.
    - AS SHIPPED, four things the choreography settled.  (i) The DRIVING row
      is a premise node, not a field of the derivation: a rule whose only
      body position is its driver would otherwise have a proof with no
      premises at all, and a delta-driven recursive rule's chain would break
      at every step.  (ii) Monotone-only is enforced at the PLAN, not the
      epoch: `sealed.counted || sealed.maint` leaves the schema
      uncapturable, because a flavored set head stages a signed kind-tagged
      contribution and journalling that would call a deletion's bookkeeping
      a proof.  (iii) "One semantic event" needed BOTH event doors --
      `prepareBoundary` and `beginUpdateEpoch` -- since an `add` prepares no
      boundary and would otherwise answer with the previous event's tree
      while calling it this one's.  (iv) The two silences are different and
      the refusal says which: nothing armed, versus armed over an epoch
      capture does not cover.
    - Exit (met): protocol 160 (the provenance field's echo, refusals at
      level 0 and on a non-boolean; `why`'s four refusal classes, with
      `reserved-verb` proven gone), REPL 207 (the spelling and its rebinds,
      the gate candidate's tree with its driver premise as a `base` leaf, a
      recursive 12-node tree over reach.slog cut honestly at `depth 1`, an
      unrecorded fact, a variable refused, and both silences), pause 18,
      joint 21, unit 406, interp, Rust 29+44+3.  Pinned by ASSERTION like
      the stepping battery: a proof cites content-addressed rule positions.
  - **(d3) `break` — the pre-run entry path.**  *(Shipped 2026-08-02.)*
    Stepping ships an entry
    only from a gate park, so until a rule breakpoint can be armed BEFORE
    a run, every port (c3) built needs a relation watch to trip the gate
    first.  A break is a STANDING arm where a step is one-shot: it
    materializes the same `StepStop` (so `frames`, `why` and `step` at the
    stop need no new machinery), suppresses itself until the resume rather
    than disarming, and re-arms for the next hit.  Three filters, each
    reading state the earlier slices already produce: a HEAD RELATION
    (`break path`, matched at the emit port through (d1)'s `ProofSchema`
    head names — and the client pins that relation's writer strata to the
    interpreter exactly as a level-1 watch does, so the ports exist),
    a RULE (`break r3`, matched at the `fire` port -- an instantiation is
    "the rule fired"), and a BODY POSITION (`break r3@1`, matched at the
    probe port whose cursor slot is 1; the sink reads the slot from
    `ops[op_index].cursor`, and slots are body positions in plan order).
    repl-ux §9.1's `when` clause lands as a HEAD PATTERN
    (`break path when (path 99 _)`) rather than a binding predicate:
    conditions over `X` need source variable names, and those are the
    rule-meta item inside the KernelPlanKey that also blocks frames --
    a pattern says the same thing about the fact being produced without
    inventing a second name table.  Monotone-only, enforced at the plan
    like (d1)'s capture.  A session with a break armed holds its commands
    on the (c2) thread exactly as a level-1 watch does; without that the
    pause hook drives past the stop and nobody is sitting at it.
  - **(d2) `whynot` — the failure frontier.**  *(Shipped 2026-08-02.)*
    DEVIATION FROM §7.5,
    deliberate and recorded here: the frontier is computed by a
    PLAN-DIRECTED PROBE over committed state at the current boundary, not
    by recording misses during a captured iteration.  §7.5's scope needs
    the target known while the read runs, which means either replaying
    every read speculatively or asking before the fact you are curious
    about exists -- and the operator's question ("why is this not here?")
    is asked afterwards, usually with nothing armed.  The probe answers it
    with no daemon change at all: the canonical `.plan` the client already
    reads for `code` IS the rule set (`rule-def` with a `driver`, a `body`
    of `join`/`exists`/`absent`/guards, and an `emit` head, every value a
    register or a constant slot), so `whynot FACT` unifies the target with
    each head that can produce its relation, walks that rule's atoms in
    plan order substituting bound registers, and probes prefixes through
    the ordinary `?count` spine until one is empty.  The report is the
    frontier: the first unsatisfiable atom, with the count of candidate
    bindings that reached it.  Honest edges, each stated in the output
    rather than papered over: a head shape that cannot unify with the
    target is reported as such (no probe run); an `absent` atom probes as
    a negated atom; a computed position (`let`/`letp`/`cjoin`) ENDS the
    analysis for that rule, because a prefix past it is not expressible as
    a query; delta views (`join-old`/`join-new`) probe as full views,
    since the question is about the state that exists now.  Chasing a
    frontier line (why the row it wanted is itself missing) is the next
    `whynot`, by hand in (d2) and a card action later -- the recursive
    memoized version stays execution-tiers §11's later layer.
    - AS SHIPPED: the probe checks the QUESTION'S PREMISE first -- a fact
      that is present is answered as present, with a pointer to `why` --
      and one representative variant per rule is walked, since the delta
      variants of a rule share its atom set and differ only in which
      position drives.  `eq` between two registers is realized by aliasing
      before any text is built rather than as a guard -- atoms, guards and
      the unified environment are all rewritten through the alias map, so
      two registers a rule equates become ONE query variable instead of an
      independent join that would answer optimistically; `neq` and
      spellable comparisons ride the final prefix.  Rendering names the rule, its
      source position and its variant tag, then each atom with the count
      that reached it.
    - Exit (met, both slices): protocol 170 (break's shape, duplicate id,
      filterless arm, a position without a rule, the listing round trip),
      REPL 234 (a break armed with nothing parked stops the very next
      command at the emit port, frames/queries work there, the hit is
      counted, the break survives it, a pattern narrows it, `unbreak` at
      the stop is admitted; and whynot's frontier over reach.slog -- three
      ways then a dead edge, both rules dying at position one, a present
      fact, an unwritten relation, a variable refused), pause 18, joint 21,
      unit 406, interp, Rust 29+44+3, session 782/782.
  - **(d4) Non-plain settles.**  *(Shipped 2026-08-02.)*  The gate's
    question -- does this change genuinely appear? -- is the same for every
    storage kind, but the IDENTITY that answers it is not, and §0.3's
    settle/apply factoring is what makes each one a preview rather than a
    second interner.  A STRUCT head stages content with a 0 id placeholder
    (the id is minted in the intern phase), so its settle is M5's
    intern-identity question asked of the content: the master ordering is
    content-first precisely so that probe is a PREFIX, and a construction
    whose content is already interned resolves to the existing instance and
    changes nothing.  A LATTICE contribution settles through M6L's
    contributor-reduce: `BTreeMapIndex::wouldChange` is `merge` with a
    lookup where merge inserts -- same clamp, same join, no mutation -- so
    a contribution the resident payload already subsumes is not a change,
    however new the row looks.  (A LAT_EXTERN preview interns its merged
    collection in the arena exactly as the apply would; that is a
    content-addressed value allocation, not a relation change, and it is
    what makes the preview exact.)
    - THE BUG THIS SLICE ALMOST SHIPPED: `getAnyIndex()` is the right
      ordering for a plain table (absence is absence) and the WRONG one for
      the other two.  A struct carries an id-first ordering beside its
      content-first master, and probing the id-first one reads the 0
      placeholder, which never matches -- so every construction, new or
      not, would have looked like a change.  `settleOrder()` now selects by
      kind: the ordering ending in column 0 for a struct, the one ending in
      the payload column for a lattice.  Caught by asserting the settle in
      BOTH directions; a settle that only ever says yes is not a settle,
      it is a park on every write.
    - With every kind settling, the last silent downgrade goes too:
      registration reports `(settleable #f)` when a level-1 binding has no
      full index to preview against, so the operator learns it at the
      prompt instead of wondering why the gate never engages.  An empty
      declared table still settles -- it carries a full index from the
      moment it exists -- so the field names a genuinely index-free
      binding, the safety net rather than the norm.
    - Not extended: (d1)'s CAPTURE still covers set and temp heads only.  A
      struct candidate has no journal key until its id exists, and a
      lattice contribution's key would be the pre-merge value rather than
      the payload that lands, so `why` on such a candidate says it captured
      nothing rather than keying on a fact that never appears.
  - **(d5) Hygiene + exit audit** (M4N slice-4 shape).  *(Shipped
    2026-08-02.)*  The MONOTONE-ENFORCEMENT MATRIX is the artifact:
    `tests/joint/t5-monotone-matrix.rkt`, in the joint tier, crosses §0.1's
    standing pin in one run instead of leaving it as five scattered
    per-slice controls.  Over a counted maintenance epoch it asserts that
    the gate never engages while the level-0 report still arrives, that
    `replay` and `step` both refuse `level-1-unwatchable` naming the
    epoch's own flavor, that a refused continuation still commits its
    change, that capture stays empty and `why` says which silence that is,
    and that a standing break never fires -- then, in the SAME session over
    a monotone epoch, that every one of those does happen.  Plus the full
    suite and the `SLOG_OPT=interp` union sweep.

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
