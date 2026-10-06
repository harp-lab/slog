# Slog in Slog: slog-lint

*2026-10-06, branch `studio/slog-in-slog`.  A static analysis of Slog,
written in Slog, run by Slog on a lane of its own, giving Studio live
findings and semantic hover while the author edits.*

## 1. Pieces

| piece | where | what |
|---|---|---|
| reifier | `compiler/reify.rkt` | the compiler's parser + include resolution → facts over the schema; `FILE` (a Slog program), `--freeze NAME` (a database), `--serve` (JSON, unsaved texts as in `check.rkt`) |
| schema | `analysis/schema.slog` | the facts, as `table`/`struct`/`union` declarations, plus `finding` |
| analysis | `analysis/lint-{local,graph,deep}.slog`, `slog-lint.slog` | three tiers, each including the one before; `slog-lint.slog` = all of it + `include "facts.slog"` |
| tests | `analysis/test.rkt`, `analysis/tests/*.slog` | each test line marks the findings it must produce; self-check; `--corpus` |
| Studio | `studio/src/lint.rs`, `web/lint.js` | the runner, the Problems list, markers, hover, why?, graph |

## 2. Schema (what the reifier writes)

Nothing is desugared: facts describe the program as written.

- `loc(File Line Col)` struct; `source_file(F Path)`, `main_file`, `library_file`
  (from `lib/`), `includes(F G Loc)`, `missing_include`, `loads(F Kind Target Loc)`
  (`run`/`instantiate`, not followed).
- Declarations: `relation(Name Kind Arity Loc)` (table/demand/extern),
  `column(Rel I Type)`, `demand_inputs(Rel N)`, `type_decl(Name Kind Loc)`
  (struct/union/enum/lattice; inline ones like `(kaddr expr)` in a column
  or `(min int)` too), `constructor(Name Arity Loc)`, `field(C I Type)`,
  `union_member(Type Member)`, `lattice_spec`, `primitive(Name)` (the
  compiler's `prim-fun-env`).
- Rules: `rule_at(R BodySize Loc)`; `head(R I Rel Args Loc)`, `body(...)`,
  `negated(...)`, `binds(R I A B Loc)` for `=`, `guard(R I Op A B Loc)`,
  `clause_other`.  A body with `|` alternatives is one rule per alternative,
  all at the rule's location (as the compiler expands it).
- Terms (`union term`): `var(Name Loc)`, `wild(Loc)`, `int_lit/float_lit/str_lit/bool_lit(V Loc)`,
  `call(Name [term] Loc)` (constructor, primitive, demand call or closure),
  `lst([term])`, `splice(term)`, `lam([str] term)`, `other(Text Loc)`.
  Variables and literals carry their own location: a bare symbol has no
  token of its own in the parse tree, so the reifier finds it among its
  parent's tokens, left to right.

## 3. Findings

`finding(Severity File Line Col Code Message)`, at the exact atom, variable
or literal.  Findings in `lib/` files are dropped.

| tier | code | severity | what |
|---|---|---|---|
| 0 | `singleton` | warning | variable used once in a rule (names starting `_` exempt) |
| 0 | `unbound` | error | head variable, or one under `~`/guard/computation, that no positive clause binds |
| 0 | `bare-constructor` | error/warning | `red` where the enum member `(red)` was meant |
| 0 | `arity` | error | atom, constructor or demand call with the wrong count (a lattice negated by its key is fine) |
| 0 | `type` | error | literal of the wrong base type; constructor not of the column's type |
| 0 | `missing-include` | warning | an include the compiler would skip |
| 1 | `negation-cycle` | error | `~R` in a rule writing something `R` depends on (held to the stratifier by `test.rkt --corpus`) |
| 1 | `ascending-lattice` | warning | a lattice's growing value copied into a plain table that feeds back |
| 1 | `never-written` | info | read, never written: an input |
| 1 | `unused` | info | table declared, never used (not reported in declaration-only files) |
| 1 | `dead-rule` | warning | a body atom over a relation that can never hold a row (e.g. recursion with no base case) |
| 2 | `unanswered` | warning | a demand asked where no rule answers it |
| 2 | `never-asked` | info | a demand nobody asks |
| 2 | `never-built` | warning | a constructor matched but never built (nor arriving in an input's values) |
| 2 | `unused` | info | a constructor never mentioned |

Binding is a small fixpoint (`pattern`/`bound`/`known`): `(= A B)` matches
one side once the other is known; a constructor on one side enumerates.
Demand-answering heads bind their inputs.  "Can hold a row" (`inhabited`)
is an optimistic least fixpoint walking each body in order
(`fires_upto`); inputs count as inhabited.

Relations for the editor: `writer(Rel File Line)`, `reader(Rel File Line Sign)`,
`dep(From To Sign)`, `recursive`, `component_of`, `inhabited`,
`never_fires(File Line)`, `demand_calls(F G)`, `recursive_demand`, `flows(Rel I C)`.

## 4. Run model

Per job (an edit after a debounce, a save, the main file changing):

1. `reify.rkt --serve` (one long-lived process in the repository root)
   reifies the project's **working texts** (unsaved buffers as sources) and
   freezes the facts to `data/slog-lint-<project>`.
2. On the **analysis lane** (its own `repl.rkt`, never the author's):
   `discard session` · `open slog-lint-<project>` · `run lint-local.slog`,
   dump `finding`/`writer`/`reader` → publish tier 0; then the same with
   `lint-graph.slog` (tier 1) and `lint-deep.slog` (tier 2).
3. An edit while a tier runs interrupts the lane and starts again from tier 0.

Why a database: including the facts in the program made every edit
recompile them, and the compile cost was dominated by the cache key
(`compile.rkt` prints the program, *tokens included*, and sha256s it once
per stratum: 51 MB of progstr for arithm's facts, ~1.2 s).  Opening a frozen
database and running the analysis compiles only the analysis.

Why a fresh session per tier: layering a second program onto a session
whose first program had rules crashes the daemon (`plan install failed ...
relation arity mismatch for temp6x1`: compiler temp relations are named by
stratum index and collide across programs).  Once fixed, tier k+1 could run
as a layer over tier k's results instead of recomputing them.

## 5. Laziness and stability

Tiers publish as they finish; the summary strip says "deeper results
coming" until tier 2 is in.  Each finding carries the text of the
top-level form it is in and that form's line, so the editor re-anchors it
on the current text by form: unchanged forms keep their markers while the
author types, findings of changed forms wait for the next run.  Until a
tier reruns, the previous run's findings of that tier stay, marked stale.

## 6. Editor

- Markers owner `slog-lint`, distinct from the check's `check` errors:
  lint error → Monaco Warning, warning → Info, info → Hint.
- A Problems list in the summary strip; a click jumps.  "why?" reruns the
  analysis on the analysis lane with `watch finding level 1 why` armed
  (after `run schema.slog`, so `finding` is live before the run) and shows
  `why (finding ...)`: the derivation through the analysis's own rules and
  facts.  The daemon's proof budget (4096 records per event) is too small
  for findings at the end of long chains; `SLOG_PROOF_RECORDS` (new) raises
  it for the analysis lane.
- "related": the dependency neighbourhood of the finding's relation, laid
  out by `graph.js`'s `layout` in the change-graph panel.
- Hover, agreed with static-check: no shared endpoint; this analysis
  registers its own Monaco hover provider for `slog` after the check's, and
  Monaco merges the parts in order.  Keyed by the word under the cursor;
  answered from the cached view only: who writes and reads it (lines),
  recursive (and its component), read under negation, demand (who asks it,
  recursion), whether it can hold a row, last Run's row count, and on a
  rule's line whether it can fire.  Inlay hints: own provider, off by
  default (deferred).

## 7. Dogfooding

"Edit the analysis" (palette) writes the current program's facts to
`analysis/facts.slog` (gitignored) and opens `analysis/` as a linked
project whose main file is `slog-lint.slog`: Run, breakpoints, demand
calls, Execution and result tables work on it as on any program.  Edits to
the analysis project's files reach every other project's linter at once
(its working texts are written to a scratch copy the lane runs from), so
the target's findings update live.  The analysis analyzes itself cleanly
(`test.rkt` checks that).

## 8. Performance (interpreter; end to end in Studio)

Measured in headless Chrome on a real studio, three edits each, with the
machine's load average at 40-55 on 10 cores (other agents' builds), so
absolute numbers are inflated.  "First findings" is from the keystroke,
including the 400 ms debounce.

| program | reify + freeze | tier 1 (rules) | tier 2 (graph) | tier 3 (deep) | first findings | everything |
|---|---|---|---|---|---|---|
| arithm.slog (501 lines) | 245-280 ms | 0.9-1.5 s | 1.4-2.2 s | 1.5-2.5 s | 1.9-2.4 s | 4.7-6.8 s |
| examples/kcfa (5 files) | 265-310 ms | 0.9-1.1 s | 1.3-1.7 s | 1.3-1.8 s | 1.7-2.0 s | 4.3-5.4 s |

Each tier recompiles the analysis's front end (~0.5 s CPU: the cache key
prints the program and sha256s it per stratum) and recomputes the tiers
before it.  Both go once `fix/layering-and-key` lands: flip `LAYERED` in
lint.rs and tier k+1 runs only its own rules over tier k's session.

## 9. Status of the pieces around it

- `compiler/check.rkt` landed on web-repl while this was built.  The
  reifier does not go through its front end: it needs the program as
  written, before demand and pattern desugaring, which `load-program-list`
  has already done.  It shares the parser, `resolve-include`, the source
  override and the `--serve` request shape, so one process could answer
  both kinds of request later.
- The check's `symbols`/`refs` are not consumed yet; the reifier already
  locates every atom, so the writer/reader relations come from the facts.
