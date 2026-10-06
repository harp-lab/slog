# Debugging demand relations: the design (2026-10-06)

Branch `studio/demand-debugger`. What it records, how a call finds its parent,
and why this is the lightest mechanism that is correct.

## The question

A demand call tree needs, for each call `D = (f args)`: who asked it (its
parent call, the rule), its answers and when each was found (stratum,
iteration), and which calls never got one. The transform
(`compiler/demand.rkt`) erases demands before planning: an ask is an emit
into the struct `f`, an answer an emit into `f_ans`, and a rule
`rule (f in.. out..) <-- body` becomes a main rule gated by
`(= _d0 (f in..))` plus ask rules (and `$sup`/temp carriers between them).

## Options considered

| Option | Verdict |
|---|---|
| Parents from the trace's rule fires | No: the trace has counts and 8 sampled rows per relation and iteration, not which row fired which. |
| Query-time reconstruction (re-run each ask rule's body as a query over the final DB) | Gets parent edges, but not *when* (stratum, iteration), needs the transformed rules at the REPL, and cannot see mid-run state at a held stop. |
| `why` / the provenance journal | Struct heads (asks) are not journallable (no id at emit), capped at 4096 records and 4 derivations per fact, and armed only through a level-1 watch that holds the gate. |
| A demand side table in the daemon (parent per demand) | Puts the compiler's naming convention (`f`, `f_ans`, `_d0`) into the daemon. |
| **Logpoints, read by the REPL** | Chosen. |

## The choice: logpoints, plus a reading of the log

The daemon gained one general mechanism: a break can be a **logpoint**
(`(log #t)`): at a matching port it records, instead of stopping, the row,
the rule's bindings, and the **labelled body** (driver and premise rows,
nominal order, with relation names -- the walk `why`'s capture makes),
stamped with stratum and iteration, into a bounded break log scoped like
the provenance journal (cleared at a prepared boundary; a replayed read
discards its own records). `(break-log (from SEQ))` reads it, rendering each
shown word once.

For a debug run the REPL (`calls on`, which Studio's Debug sends) arms one
logpoint on the program's demand relations -- `f`, `f_ans`, and the carrier
relations `$sup*`/`temp*` -- whose names it learns from the prepared
boundary's catalog (`session-prepare-hook`). `compiler/demand-debug.rkt`
reads the log into a call graph:

- **Parent of an ask** = the *gate* of the asking rule: the demand-struct
  row in its body that has **no answer row beside it**. A resumed subcall is
  always joined with its answer (`(= d (g ..)) (g_ans d ..)`); the gate's own
  answer is never in its body. Rules that read a carrier instead of the gate
  get it from the carrier's own record (matched by content, columns in any
  order: the emitted and the read layouts differ). No gate: a root.
- **The answered call** of an answer = its first column, named by the same
  gate row.
- Identity is the call's content: an ask's fields, a gate row's (id, fields).
  Interning makes this exact.

Cost: nothing unless armed (the sink's mask stays 0). Armed, one record per
demand event; mltt's whole run is 279 calls, read incrementally at each stop.

Why this is the lightest correct one: it adds no demand knowledge to the
daemon (logpoints, patterns and guards are general debugging features that
stand on their own), reuses the capture walk that already exists, gives
timing for free, and works at a held stop (the log is current to the
transition that stopped).

## Breakpoints and stepping on the same substrate

- **Structured patterns** (`ctor`, `seq`, strings by content, variables) are
  matched against the value at the port, so `break demand (infer _ (app _ _))`
  arms before any `app` exists. Struct-head emits (asks) became nameable.
- **Answer breaks** read `f_ans`'s row as the judgment (`(judgment #t)`).
- **Guards** `(OP a b)` over the pattern's and the rule's variables; **ignore**
  counts; **enable/disable**; **(match "R")** stops where a rule matches its
  body atom R. At a location, a pattern's variables are the rule's own, so a
  clause breakpoint stops at exactly that clause.
- **Stepping** is one temporary break: `over` = the answer of the asked call
  (a constructor pattern on `f_ans`'s first column, since the id is not
  minted at the ask); `into` = the next demand event whose body *uses* the
  call (`(uses (ctor f ...))`); `out` = the answer of the call the run is in.
  Other breakpoints still stop first, as in any debugger.

## Studio

Breakpoints are set in the editor (margin: the rule; a dot before a clause:
that clause), kept with the project, armed one `break` line each by Debug,
and re-armed in the background when edited while a session holds them.
Debug in compiled mode switches to debug mode (compiled strata have no
ports); fast mode is the interpreter, where breaks stop (only single-port
`step` is exact on one thread). A breakpoint that cannot stop says why.

## Limits and what is deferred

- A rule that enumerates demands in its body (`(eval (app ef ea))` bare)
  reads as gated by the demand it enumerates; for 0CFA's store rule that is
  the right call anyway.
- Joint gating (several judgment heads in one rule) attributes asks to the
  first gate.
- Guards are comparisons and pattern equality; atoms over relations in a
  condition are not supported (mid-run state is not queryable).
- `step into` an already-answered (memoized) call goes on in its caller.
- The demand stack at a *non-demand* stop (a rule-line break) is the latest
  demand event's stack, not the stopped rule's own gate.
