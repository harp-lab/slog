# Full scope at every stop: where it is, what is left

Branch `studio/full-scope`, off web-repl cb4b407.  The work is committed
as WORK IN PROGRESS: written, but not yet built or run.

## The gap
At reach `main.slog` line 74 (the `kstore` emit of the rule at 73–74),
frames showed only B and K, not X and V.  The cause is not frames:
compiler/join-planning.rkt `stage-rule` moves a head that uses an id the
same rule constructs, `(kstore (kaddr B) K)`, into a follow-up rule.
That follow-up is driven by a temp carrying only what it uses (B, K).
The stop is in the follow-up (port `delta:temp…x10`), whose registers
never held X or V.  Ports of an unstaged rule already report everything
bound (checked: match, fire, emit, drive, miss, exhausted on reach rules
72 and 73), so the gap is every port of a staged follow-up.

## The fix (runtime only, no plan change)
- daemon/database.h: `StagedEnv` store, with `recordStagedEnv`,
  `stagedEnv` and `clearStagedEnvs` (cleared with the break log; capped at
  2^20 rows).  `StepStop` gains `staged`, `staged_instantiations` and
  `several`.
- daemon/plan.h: `ProofSchema` gains `temp_heads`, `stages` and
  `driver_temp`.
  - `StepSink::staging` holds while breaks or a step are armed; the emit
    bit is then added to the mask.
  - An emit into a temp records the rule's `full_bindings`.
  - `full_bindings` = the recovered environment + the stage's own
    registers.  Stops, guards, logpoints and located patterns use it.
- daemon/slogd.cpp: frames emits
  `(staged (instantiations N) (several "X" ...))`.  N = 0 means nothing was
  recorded (armed after the stage before ran).
- compiler/repl.rkt:
  - `stop-scope` gains `staged`; `staged-note`.
  - `frames` renders the note and returns `'staged`; `p X` says when X
    differs among instantiations.
  - rackunit test: 0cfa.slog:50 and tests/dbg_staged.slog.
- studio/web/inspect.js: the Variables panel shows the note and a
  "1 of N" mark on differing variables.

## To do, in order
1. `nice -n 15 make -C daemon -j2 slogd`; fix any compile errors.
2. `raco make compiler/repl.rkt && nice -n 15 raco test compiler/repl.rkt`,
   then make the new test pass:
   - check the exact raw line `(staged (instantiations 1) (several))`;
   - is `frame-lines` given the right session object?
   - does `tests/dbg_staged.slog` actually stage?
   - is the bindings order X, Y?
3. Run the session and protocol suites niced (plan-goldens and m6l are
   known failures).
4. Studio: `make -C studio test-web`, then verify on reach line 74 in
   headless Chrome (scratchpad `dd/sx.mjs` style): the Variables tab
   should show V, K, X and B.  Take a screenshot.
5. Split into two commits: daemon + repl.rkt + test (master-suitable),
   and the Studio change.  Port the first to master as before.

## Open questions
- Rows merged in a temp stand for several instantiations.  The stop
  shows the first one's values and names the variables that differ.  The
  alternative is exact but costs a plan change: a debug flavor whose temps
  carry the full environment, as the count flavor does
  (join-planning.rkt `carried`).
- Is the interpreter double-free fix (another agent) landed?  mltt.slog
  needs it.
