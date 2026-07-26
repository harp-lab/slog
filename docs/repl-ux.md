# The Slog REPL: interaction design and experience vision

2026-07-14. **Experience design, with a connected transport/UI slice as of
2026-07-15.** A Rust Ratatui/Crossterm client now drives the persistent Racket
session server over private loopback TCP; see
[repl-terminal.md](repl-terminal.md), now normative for process boundaries,
terminal-library choices, portability, repaint discipline, and R0/R1 gates.
This document is the
wide-angle companion to two normative designs it deliberately does not repeat:

- [repl.md](repl.md) remains the authority on names, handles, boundary
  catalogs, budgeted value printing, and the level-0 watch protocol; and
- [execution-tiers.md](execution-tiers.md) remains the authority on the
  interpreter, interpreted QueryPlans, level-1 provenance watches, why-not,
  and the S-expression command protocol.

Those documents answer "what are the mechanisms." This one asks **what should
sitting at the Slog prompt feel like** — what people actually do at a REPL,
which experiences are worth designing for, and how a small number of shared
mechanisms can carry all of them. It ends with a high-level client/server
implementation shape, a slice sequence, and an appendix (§15) inventorying
the substrate that already exists — which turns out to be most of the
semantic layer. It is intentionally a brainstorm: later passes will distill
it into a command reference and an implementation plan.

The stance throughout: **the REPL is the primary interactive mode of the whole
system.** Batch runs (`racket compiler/run.rkt foo.slog`) and external harnesses remain the
scripting surface; the REPL is how a person opens a database and starts
working. It should be as natural to reach for as `sqlite3 file.db` or `python`
— and it should exploit the two things Slog has that those tools do not: an
immutable, replayable session timeline, and (soon) an interpreter that can run
and observe any rule without a compiler in the loop.

## 1. What the REPL is

One sentence: **a shell over an anchored recipe, standing at the tip of an
immutable pipeline of databases, with cheap eyes everywhere.**

Everything a user types is one of exactly two kinds of thing, and the UX
should make the distinction impossible to miss:

- **Semantic events** advance the timeline: run a program, add/retract facts,
  rename/drop/link, import, save. Each one commits a new boundary and prints a
  new handle (`db8 = ...`). These are recipe events in the sense of
  incremental.md §0.2 — they are what replay reproduces.
- **Observations** never advance anything: queries, schema views, value
  expansion, diffs, history, stats, explain, watches, provenance. They are
  guaranteed non-mutating (execution-tiers decision 15) and can be aimed at
  *any* retained boundary, not just the tip.

This two-verb doctrine is the core mental model. The prompt shows where you
stand (`db7 ▸`); observations leave it alone; semantic events move it and say
so. A user who internalizes only this already understands the system: *my
session is a pipeline of immutable states; I stand at the tip; I can look
anywhere; only a handful of verbs create new state, and those are exactly the
ones that get saved.*

Two structural commitments follow:

1. **The REPL is a client.** All of its power flows through the same session
   driver and daemon command protocol that scripts use. There is no
   privileged in-process backdoor. This keeps the protocol honest, makes the
   REPL testable over a pipe, and means a future web UI, Jupyter kernel, or
   editor integration reuses everything below the terminal layer.
2. **Immutability makes courage cheap.** Because ancestors are never mutated,
   the REPL can encourage exploration: scratch rules that can be dropped
   wholesale, what-if edits that are previewed and discarded, old boundaries
   that remain queryable after the tip moves on. Fear of wrecking the
   database is the main thing that makes database shells timid; Slog's
   substrate removes the reason for the fear, and the UX should spend that
   freedom visibly.

## 2. Who sits at the prompt

Seven overlapping jobs. Each is a coverage checklist for the feature set; a
design that serves only two or three of these is a query tool, not the main
interactive mode.

1. **The explorer** opens a saved database cold. Wants: what is in here?
   Schema and sizes at a glance, sampling rows, drilling into big values,
   "where else does this value appear," counting, small joins. Success is
   measured in seconds-to-first-insight.
2. **The author** iterates on a program. Load, run, inspect, edit, rerun,
   diff. Wants the loop tight (interp-only ad-hoc rules mean no clang), wants
   yesterday's result comparable with today's, wants compiler errors to point
   into the line just typed.
3. **The operator** drives a live pipeline: feed additions and retractions at
   anchors, watch the change cone, save layers, ship them. Wants change
   summaries after every event, watches that survive across runs, and recipes
   that replay exactly.
4. **The debugger** has a wrong or missing fact. Wants why and why-not as
   navigable proof trees, watches and breakpoints on tuples and rules,
   stepping through rule evaluation with real variable names, and a paused
   world that can be queried like any other boundary.
5. **The tuner** has a slow fixpoint. Wants fire counts, per-stratum
   iterations and times, join plans with the semijoin/WCOJ decisions visible,
   which tier each SCC is running, and what the compile queue is doing.
6. **The curator** manages `data/`: list, tree, verify, freeze, gc, merge,
   link, prune. Wants the `slog db` surface available without leaving the
   prompt, plus lineage answers ("what does deleting this orphan?").
7. **The learner** is figuring out Slog itself. Wants a `tour`, wants
   single-stepping a three-rule program iteration by iteration to *see*
   semi-naive evaluation, wants every printed thing to be askable ("what is
   this?"). The REPL is the teaching instrument the language currently lacks.

## 3. Design principles

Eight principles that carry the whole design. Everything in later sections is
an instance of one of these.

**P1 — Two verbs.** Observations never mutate; semantic events always commit
and announce. No third category. (Debugger actions like `commit`/`replay` at a
pause resolve a *pending* event; they do not create a new category.)

**P2 — The screen is a view of commands.** Every interactive gesture (arrow
expansion, fact card, page turn) is sugar for a typed command, and performing
the gesture **echoes** the command it ran, dimmed, into the transcript.
Consequences: transcripts are replayable scripts; the interactive layer can be
switched off (`--plain`) with zero loss of capability; and users learn the
command language by using the arrows. This is the single highest-leverage UX
decision in the document.

The same rule applies within the shared collaboration lane: input from a local
co-author is a compact dimmed generated command, while `;` introduces a shared
transcript comment that never changes Slog state. A private lane may perform
non-mutating observations without painting them into the terminal; private
mutation is forbidden. Privacy is metadata around the canonical command, not a
separate command language. Replicated menus likewise use ordinary commands
(`library select NAME`, `open NAME`, `library close`); a future structured
event must include the exact command a person could have typed and cannot add
event-only behavior. Long actions may append temporary rows at the
transcript tip and repaint them in place; only their success or failure is
committed to durable history. Plain clients receive fixed progress events and
semantic `◇ View` descriptions rather than animation or terminal cells. Until
the backend streams measured load progress, the loading row labels its
elapsed-time stage and explicitly says when relation/tuple progress is
unavailable; it must never synthesize a percentage from elapsed time. Animated
dots reserve a fixed-width field, and the temporary line has no status glyph;
the green diamond appears only when the result commits.

**P3 — One tree to render them all.** Values, facts, proof trees, why-not
frontiers, schemas, module/program structure, query plans, pipeline history,
and diffs are all budgeted, expandable trees. One presentation engine, one
navigation mode, one set of budgets, one handle mechanism. A user who has
expanded a value already knows how to expand a proof.

**P4 — References degrade gracefully.** The ways to refer to a thing form a
ladder, and the REPL always prefers the lowest rung that works:

```text
positional      it, it.3, .3 (row 3 of the last result), it.3.args.1
short handle    #42, @v12, @t4, db7, r17, w2   (session-local, reclaimable)
pinned name     pin #42 as cex; pin db3 as baseline
persistent key  key @v12       (only when a reference must leave the session)
```

Most drilling should never mint a handle at all; most handles should never
need pinning; keys appear only in scripts and bug reports.

**P5 — Touch to name.** Printing allocates nothing. Handles are minted when
the user *interacts* — expands, pins, or references a position — or when the
printer must mark a genuinely shared DAG node. Dumping ten thousand rows to
the screen allocates zero handles; the `[..]` markers in live output are
positions in the presentation buffer, not registry entries. This single rule
is what keeps handle numbers small (§7).

**P6 — Everything is budgeted, paged, and cancellable.** No command may flood
the terminal or hang it. Large results print one page plus an honest count
and a continuation affordance; long queries show progress and die cleanly on
Ctrl-C; runs slice at the daemon's existing 500 ms granularity, so the prompt
is never more than a beat away.

**P7 — Never lie about history.** Adopted from repl.md §5: values render with
the names visible at the boundary they are viewed from; a type with no
visible name prints as `<type @t4>(...)`, not a borrowed later name; stale
handles fail with an explanation, never silently show a reused slot.

**P8 — Output is input.** Wherever possible, printed facts and values re-parse
as Slog literals, so a row copied out of a result pastes directly into an
`add`, a query, or a test file. Handles (`#N`) are the escape hatch for values
that cannot round-trip textually (huge terms, opaque interned state) — and
handles themselves are accepted anywhere a literal is (§7.4).

## 4. A dream session

An annotated transcript, compressed but honest about what each moment
requires. `▸` marks truncation points the user can navigate to; dim text is
the gesture echo of P2.

```text
$ slog repl -d callgraph
db0 = load callgraph        (compressed chain: base ◂ callgraph · replayed 2 layers · 3.1s)
      42 relations · 18.3M facts · saved 2026-07-12 by analyze.slog     (`rels`, `log`)

db0 ▸ rels model.*
      model.value    1,083,921
      model.edge       410,552
      model.error            0
      ...and 4 more                                            (rels model.* all)

db0 ▸ schema model.value
      model.value : table (str  model.Value)      @v12   (versions @v7 ◂ @v9 ◂ @v12)
      written by analyze.slog r17 r21 · read by 4 rules · indices (0 1) (1 0)
      1,083,921 tuples · counted ✓

db0 ▸ ?(model.value "main" V)
      3 rows
      1  (model.value "main" (model.Clo (syn.Lambda ["x"] ▸[..]) ▸[..]))
      2  (model.value "main" (model.NumTop))
      3  (model.value "main" (model.StrTop))
```

The user taps into navigate mode, arrows to the first `▸[..]`, presses enter;
the subtree expands in place and the equivalent command echoes:

```text
      1  (model.value "main" (model.Clo (syn.Lambda ["x"]
            (syn.App (syn.Ref "f") [(syn.Ref "x") #12:(syn.App ...)]))
            ▸[..]))
      ‹expand it.1.2.1.body›

db0 ▸ #12
      (syn.App (syn.Ref "g") [(syn.Num 3)])
db0 ▸ uses #12
      syn.App: 1 row · flow.calls: 2 rows · model.value: 14 rows        (uses #12 all)
```

Now some work. A new program runs interpreted, instantly, and the timeline
advances with a change summary:

```text
db0 ▸ run cycles.slog
      stratum 2/2 ······ fixpoint
db1 = run cycles.slog at db0      (+path 1,204,332 · +in_cycle 212 · 2 strata · 840ms · interp)

db1 ▸ add (edge "z" "a")
db2 = add 1 fact at db1           (edge +1 ⇒ path +3,201 · in_cycle +7 · 122ms)

db2 ▸ diff db1 db2 in_cycle
      +7 rows
      1  (in_cycle "z")
      2  (in_cycle "a")
      ...
```

Something is missing. Why-not chases the failure frontier; each frontier line
is itself expandable (P3 — it is just another tree):

```text
db2 ▸ whynot (in_cycle "q")
      no derivation at db2. producing rules and nearest failures:
      r4  (path X X) --> (in_cycle X)          cycles.slog:9
          needs (path "q" "q") — absent        ▸ chase
      ‹enter on "chase" runs: whynot (path "q" "q")›
```

Debugging with a breakpoint. The prompt itself changes shape while a run is
paused — the paused world is a boundary you can query:

```text
db2 ▸ break (model.error _)
w1 = break on first (model.error _)
db2 ▸ run analyze2.slog
      stratum 3/5 · iter 6 ⏸  w1 hit: (model.error (div_by_zero ▸[..]))
run0 ⏸ ▸ why .1
      1 derivation:
      r17 analyze2.slog:83   (flow.div L X Y) ∧ (model.value Y (model.Num 0)) ∧ ...
          ▸ premises
run0 ⏸ ▸ ?(flow.div L X Y)         ; ordinary query against the paused snapshot
      ...
run0 ⏸ ▸ abort
db2 ▸                               ; timeline unchanged: the run never committed
```

And leaving: the session reminds rather than nags.

```text
db2 ▸ exit
      tip is 2 events past the last save.  `save as callgraph-jul14` to keep it;
      `exit!` to discard.  (recipe transcript kept at .slog-repl/last-session)
```

Every capability shown above maps to a shipped or designed mechanism: the
load/replay chain (db-compression), the boundary handles and catalogs
(repl.md §1–4), interpreted run-without-clang (execution-tiers §5), the
anchored batch (incremental §0.3), level-0 break (repl.md §6), why/why-not and
paused queries (execution-tiers §6–7). The REPL's job is to make them feel
like one instrument.

## 5. The REPL language

### 5.1 Three syntactic registers

A line at the prompt is one of three things, disambiguated by its first token:

1. **A REPL verb** — a bare word (`rels`, `run`, `diff`, `watch`, ...).
   Verbs are reserved only in line-head position.
2. **A query** — the `?` sigil followed by Slog body syntax:
   `?(edge "a" X)` as one-atom sugar; full conjunctive form
   `? (path X Y) (label Y L) (=/= L "skip") -> (X L)` with an optional
   projection head. `?count`, `?exists` avoid materializing rows.
3. **Slog itself** — a line starting with `rule`, `table`, `lat`, etc. is a
   *scratch definition* (§5.3). Bare facts are deliberately **not** accepted
   as input — `(edge a b)` alone is ambiguous between add and query, so it is
   an error with a two-way hint (`add (edge a b)` / `?(edge a b)`).

The query register reuses the Slog parser and type checker wholesale: same
atom syntax, same primitives, same error messages with spans into the typed
line. There is no second expression language to learn — a strong reason to
keep queries in Slog-body form rather than inventing a pipe DSL.

Multi-line input continues while parens are unbalanced, exactly as a Slog file
would read. `edit` opens `$EDITOR` on the current scratch program (psql's
`\e`); `run !` reruns the last program event.

### 5.2 Verb inventory (working set)

Grouped by the two-verb doctrine plus session management. Names are
provisional; the *groups* are the design.

```text
observe    ?  ?count  ?exists          queries (Q1 machinery)
           rels  schema  types  show  inspect  uses  sample  count
           diff  history  log  key  at  checkout
           progs  rules  explain  code  hot  stats  tiers
           why  whynot
           handles  watches  dbs  status

semantic   run  add  del  stage  flush  inject  rename  drop  link  import
           save  load  freeze  recount
           rule/table/... (scratch definitions)   clear scratch   keep scratch

debug      watch  break  unwatch
           step  continue  finish  frames  up  down
           commit  replay  abort

session    pin  release  format  dump  transcript  edit
           help  tour  exit
db-admin   db ls | tree | verify | rm | gc | ...   (the dbtool verbs, hosted)
```

Three deliberate reuses: `inspect`/`history`/`key`/`diff` are exactly repl.md
§4's surface; the `db *` family is the existing dbtool suite mounted behind
the prompt so the curator never shells out; and the semantic row is a thin
skin over `session.rkt`'s existing verbs (§15) — the REPL invents almost no
new semantics there.

### 5.2.1 Staged batches: the git index for facts

The session substrate already distinguishes *queuing* input changes
(`session-batch!`, which collapses duplicates and cancels `+`/`−` pairs)
from *committing* them as one propagated epoch (`session-flush!`). The REPL
should surface that as deliberately git-shaped staging:

```text
add (edge "z" "a")                  ; sugar: stage + flush = one boundary
stage +(edge "a" "b") -(edge "c" "d")
stage -(weight "x" 3) at @v9        ; anchored edits: change history's inputs
status                              ; pending staged changes, by anchor
flush                               ; one semantic event, one change summary
inject edge                         ; new input-only successor version (a new
                                    ; time-travel anchor), then stage into it
```

Bare `add`/`del` auto-flush so the casual path stays one keystroke-thought;
`stage`/`flush` exist so a related group of edits commits as *one* boundary
with one summary, which is also how the recipe should record it. `at @vN`
edits an existing slot's overlay; `inject` allocates a successor version —
the edit-vs-inject distinction of incremental.md §0.3, surfaced with two
different words because they answer two different user intents ("fix this
input" vs "open a new input era"). Bulk data never goes through the terminal:
`import dir/` rides `session-import-delta!`, and staged inline batches warn
as they approach the inline cap.

### 5.3 The scratch layer: ad-hoc rules without fear

The tension: queries must never mutate, but real exploration wants *views* —
helper relations defined mid-session. The resolution is a distinguished
**scratch layer** at the tip:

- Typing `table`/`rule` forms appends to the scratch program. By default each
  complete rule set runs immediately (interp-only, so this is instant for
  typical view-sized rules) and prints an ordinary change summary.
- `scratch` shows the accumulated program; `clear scratch` drops the whole
  layer — this is real, bounded retraction, riding the incremental
  substrate's clear-and-rerun fallback rather than a from-scratch reload.
- `keep scratch as views.slog` exports it to a file and/or promotes it to an
  ordinary named program event in the recipe. Until kept, `save` asks whether
  scratch should be included or stripped.

Scratch is what makes the REPL a *workbench* rather than a viewer, and it is a
capability most Datalog shells cannot offer because they lack retractable
layers. Recursion is fully allowed in scratch (it is an ordinary program
event); the `?` register stays non-recursive by construction, and the hint for
a recursive query is one line: "make it a scratch rule."

### 5.4 Change summaries: the operator's heartbeat

Every semantic event prints one compact, skimmable line-or-three: direct
inputs, then the derived cone's top relations by |delta|, then cost:

```text
db3 = add 2 facts at db2    (edge +2 ⇒ path +3,201 · in_cycle +7 · 122ms)
db4 = run enrich.slog at db3 (+flow.calls 88k · +flow.ret 61k · ~model.value +2,114 −0
                              · 4 strata · 2.1s · interp, O0 arrived stratum 3)
```

Sources: the version-environment delta (which relations gained versions),
relation size deltas, `$stat_fixpoint` iterations/time, and tier events. The
long form is `stats db4` / `stats run0`; `diff db3 db4 [rel]` drills into
content. A truncated summary always says so: `...and 12 more (diff db3 db4)`.

This is the answer to "feed in incremental changes and look at stats of what
changed" — it should be *ambient*, not a report the user must request.

## 6. The interactive canvas

### 6.1 Rendering

Everything renders through one budgeted tree engine (P3) with independent
budgets — depth, total nodes, collection items, string length — per repl.md
§5. Defaults: fully expand small values; stop at modest depth; cap wide
collections; one global node budget so a shallow-but-enormous DAG cannot
flood the screen. Truncation points render as `▸[..]`; shared DAG nodes
render once and show `#N` at reoccurrences (one of the two legitimate
print-time handle mints, P5).

Row-shaped results (queries, diffs, samples) print with dim ordinals `1 2 3`
— those ordinals are positional references (`.3`, `it.3`) usable in the very
next command: `why .3`, `pin .3 as bug1`, `show .3 depth 9`.

### 6.2 Navigate mode

One keypress (Tab, or Esc-v; pick one and never overload it) shifts focus
from the prompt into the **last result's canvas**:

- arrows / hjkl move a cursor across markers, rows, and expandable nodes;
- **enter** expands the marker in place, re-rendering the subtree with a
  fresh budget and echoing the equivalent `expand` command (P2); backspace
  re-collapses;
- expansion that hits a *deeper* budget shows new `▸[..]` markers — walk in as
  far as patience allows; nodes cut off beyond the canvas's practical reach
  print `#N` handles, which can be expanded in place or typed later at the
  prompt (the user's great-grandchildren case);
- **y** yanks the node under the cursor as a handle (mints `#N`, echoes it);
- **o** opens the *card* for the node: for a fact row — relation and version,
  derivation status (input? derived? count if counted), actions
  (`why`, `watch`, `pin`); for a value — type, boundary-relative name,
  occurrence summary (`uses`); for a rule — source, plan, fire counts;
- **/** incremental search within the expanded tree; **n** next match;
- **q**/Esc returns to the prompt; the canvas remains printed as plain text.

**Checkpoint 2026-07-23 (R1 presentation/navigation foundation).** The
terminal-independent `present` model now owns depth, total-node,
collection-item, and string budgets plus stable positional expansion paths.
The newest successful result becomes the one live canvas; structured mutation
records contribute a collapsed `it.change` tree without parsing their bounded
human-readable lines. Tab enters navigation, arrows/hjkl select or
expand/collapse, and every successful gesture appends the same generated
`expand POSITION`/`collapse POSITION` command accepted as typed input.
Previous result entries retain their last rendered text, while `--plain`
continues to render the server projection byte-for-byte.

**Checkpoint 2026-07-23 (semantic change cards).** Pressing **o** on a
card-capable node opens a contextual sidebar; typing or receiving
`card POSITION` applies the identical client-side action, and `card close`
closes it. The initial adapter covers the structured mutation summary,
requested tuple edits, observed relation sizes, and affected routes. It labels
requests as requests whose settled effect depends on normalization and labels
sizes as cardinality evidence rather than tuple diffs or provenance. Cards
publish the same typed expand/collapse/close actions gestures perform. Narrow
terminals omit the sidebar without losing card state, and plain output remains
byte-identical.

**Checkpoint 2026-07-23 (command completion foundation).** With editor text,
Tab completes canonical verbs, `mode` and `library` subcommands, structured
resident/library database names, and action-valid paths in the newest live
canvas. A unique candidate replaces its token immediately. Ambiguous
candidates open a bounded panel; Tab/Down and Shift-Tab/Up cycle, Enter
accepts, Esc dismisses, and the mouse wheel follows the same selection state.
Acceptance only edits the command buffer—the resulting command is ordinary
typed input and no hidden transcript action occurs.

The completer explicitly returns no relation or namespace candidates yet.
Runtime cardinality observations are not a catalog, and saved relation
directories omit declarations the catalog may know. The pure candidate model
has an inventory seam for the selected boundary catalog from repl.md §3;
catalog/embedded-Slog completion, search, arbitrary value/proof adapters, and
pagination remain open R1 slices.

**Checkpoint 2026-07-23 (visible canvas search).** Navigate-mode `/` opens a
single-line incremental search over the rendered canvas. Matches are
case-insensitive and remain bounded by the same depth, total-node,
collection-item, and string budgets as presentation; collapsed descendants do
not leak into results. All visible matches are highlighted and the current
match plus total are reported. Enter commits and echoes `search TEXT`, Esc
restores the prior search and selection without an echo, and n/N echo
`search-next`/`search-previous`. `search-clear` is the canonical reset.
Typed and co-author commands run through the identical client reducer without
reaching Racket, and plain transcript bytes remain unchanged. Catalog and
embedded-Slog completion, richer value/proof adapters, and pagination remain
open R1 slices.

**Checkpoint 2026-07-25 (N3-B relation identity adapter).** The server's
`tables` pass now consumes the structured daemon catalog and retains additive
JSON-safe records for visible current-session relations: name, kind, arity,
schema detail, row count, exact VersionKey, and selected BoundaryKey, with
filter/scope totals. The canvas renders those records as a budgeted
`it.relations` tree. Relation cards expose `count`, `show`, and `state`
actions and display the real BoundaryKey/VersionKey pair; a legacy environment
event is labelled as having no committed boundary selected.

The original human `lines` and plain transcript remain byte-identical. This
observation is intentionally not fed to completion: N4 must persist the
additive historical boundary catalog from repl.md §3. Tuple values
also remain unstructured until evaluation/boundary TypeDescriptor and
value-handle ownership are fixed, while proof trees remain gated by
provenance. Pagination and those value/proof adapters remain open.

**Checkpoint 2026-07-23 (buffered canvas pagination).** Collection item
budgets now render one page rather than expanding every buffered remainder.
Continuation markers state the exact remaining/prior count and current/total
pages. Enter on a marker echoes an absolute `page POSITION NUMBER` command;
typed and co-author forms take the identical client reducer, and completion
offers only visible page targets and in-range page numbers. Search and cards
remain honest to the current page—off-page nodes are neither matches nor open
cards.

This slice is intentionally client-buffered. It pages only nodes already in a
bounded compiler result, including `show REL all` under the existing 200-row
safety cap. It does not name that state a query cursor and does not implement
the future Q1 `more`: default `show REL` keeps its explicit `show REL all`
continuation. The daemon's canonical `query`/`query-page`/`query-cancel`
dispatcher landed after this checkpoint, but Rust `more` still waits for the
N2/N3 boundary-catalog and friendly query adapter rather than manufacturing
identity from the live-name observation.

Only the most recent result is a live canvas; older results decay to plain
transcript text (bounded terminal state, and P2 means nothing is lost — the
echoes reproduce any expansion). Older results can be re-summoned: `it~1`,
`it~2`, or rerun the command.

`--plain` (and any non-tty stdout) disables client-owned canvas operations and
prints the compiler's bounded semantic projection. Database capabilities
remain ordinary server commands; full-screen canvas actions are replayable
client commands. All golden tests run in plain mode, so presentation paging
cannot change Slog semantics or transcript bytes.

### 6.3 Pagination and floods

A query with a large result prints one page and an honest header:

```text
1,204,332 rows — showing 1–20.   more · dump path to out/path.csv · ?count
```

`more` continues the daemon-side query cursor (the Q1 pagination protocol);
`dump` streams to a file without ever materializing in the terminal or the
handle registry. Relations too: `show model.value` is implicitly
`sample model.value 20` with the same header. Nothing in the REPL ever prints
an unbounded result by default.

### 6.4 Completion and discovery

Tab completion is catalog-driven (repl.md §3): namespaces and relations
(including empty ones — the catalog knows), verbs, handle names, `data/`
database names after `load`/`-d`-style verbs, file paths after `run`,
rule ids after `explain`/`break`. Completion works *inside* Slog fragments —
completing `?(mo⇥` to `?(model.` — because the completer shares the parser's
token stream. Unknown-name errors always suggest near matches.

Discovery affordances: opening anything prints its card with next-step hints
(`rels`, `log`); `help <verb>` and a ten-minute `tour` that walks a bundled
example database. Every card ends with the commands it is summarizing —
teaching by echo again.

## 7. The handle economy

The problem statement, from experience with every tool that prints object
ids: if ids are minted eagerly and never reclaimed, users end up typing
`#48291733`, and the feature has failed. The design goal is that **a handle
the user actually types is almost always one or two digits.**

### 7.1 Namespaces

Session-local, typed, small:

```text
db0 db1 ...   committed boundaries            (EvaluationId, BoundaryKey)
run0 ...      in-flight/paused provisional boundaries
@v12  @t4     relation versions, struct types  (repl.md §1)
#42           values and facts                 (checked registry entry)
r17           rules                            (RuleId; stable per evaluation)
w3            watches/breaks
q2            open query cursors (rarely user-visible)
```

`dbN`, `runN`, `@vN`, `@tN` follow repl.md §1 unchanged. `#N` covers both
interned values and *facts* (a fact handle records relation version + tuple,
so `why #N` and `watch #N` are well-defined).

### 7.2 Allocation: touch to name

Restating P5 as rules the implementation can follow:

1. Printing a result allocates **zero** handles. Truncation markers are
   positions in the live presentation buffer.
2. A handle is minted only by: user interaction (expand beyond the canvas,
   yank, pin, positional reference like `why .3` — the echo then shows the
   minted `#N` so the transcript stays replayable); printer marking of a
   shared DAG node; or an explicit `with-handles` dump.
3. Ids come from a free-list, smallest first. After heavy use and release,
   the next handle is `#3`, not `#48292`.

### 7.3 Release and reclamation

- Every unpinned handle carries the *turn generation* at which it was last
  touched. Handles untouched for G turns (default ~16) are auto-released;
  their ids return to the free-list.
- Release keeps a **tombstone**: the one-line rendering plus the echo command
  that produced the handle. Using a stale or reused id from scrollback fails
  safely — the registry entry is generation-checked (repl.md §5's checked
  table) — and helpfully: `#12 was released (was: (syn.App ...), from
  ‹expand it.1.2›); rerun that command to recover it.`
- `pin #12 as cex` exempts a handle and gives it a name usable anywhere;
  `handles` lists live and pinned entries with age; `release #12 | all`
  is manual control. Pins can outlive the values' boundaries only as far as
  the retention rule allows (next point).
- `dbN` retention is the expensive case (a retained boundary pins daemon
  state, repl.md §8): policy is *tip + pinned + last K* (K small), with
  `dbs` showing what is retained and release printing what it freed. A
  released boundary's label is never reused within a session — `db3` stays
  `db3` in the transcript record even after release — only `#N` values
  recycle numbers, because only they are minted in bulk.

### 7.4 Handles are values

A handle is accepted anywhere a literal is: `?(model.value X cex)`,
`add (blessed #42)`, `diff db2 db3 @v12`. The registry entry carries the raw
word and evaluation, so query planning binds it as an exact constant
(probe-only, per execution-tiers §6.2). This is the escape hatch that makes
P8 (output is input) total: what cannot round-trip as text round-trips as a
handle.

## 8. Time: history, diff, viewing, what-if

- `log` is `git log` for the session: boundaries with their creating events,
  ages, and — below the session — the saved lineage of the loaded chain
  (`db tree` folded in). The vocabulary is deliberately git-shaped
  (log/diff/checkout/tag≈pin) because that timeline intuition is already
  installed in every user we care about.
- `diff dbA dbB` summarizes by relation; `diff dbA dbB rel` pages actual
  added/removed rows through the standard renderer. Version-aware:
  `diff @v9 @v12` compares two versions of one slot directly.
- `at db3 <observation>` runs any single observation against an older
  boundary. `checkout db3` makes it sticky — the prompt becomes
  `db7 ⌗db3 ▸` (standing at db7, viewing db3) — and a semantic event while
  viewing history is an error with the honest hint that branching is a
  future feature (repl.md §2's linear-session rule, surfaced kindly).
- `history @v12` / `history model.value` show a slot's version chain with
  creating events (repl.md §4).
- **What-if (aspirational, worth designing toward):** `whatif del (edge a b)`
  computes the deletion cone — relations affected, counts, sample casualties
  — then discards it; `whatif add ...` likewise for the growth cone. The
  maintenance machinery (M3/M4T) and the pre-commit pause are most of the
  mechanism; the missing piece is a "compute, summarize, never commit" driver
  mode. For the operator persona this is the killer feature: *what would this
  retraction break?* answered in seconds, with nothing mutated.

## 9. Debugging at the prompt

The mechanisms are execution-tiers §7 (levels 0/1, pre-commit gate, why-not)
and repl.md §6 (watch protocol). The UX layered on them:

### 9.1 Watches and breaks

```text
watch model.error                    level 0: notify on appearance
watch model.value sizes              level 0: per-iteration growth line
break (model.error _)                level 0: pause on first appearance
watch (path "a" X) when (> X 100)    level 1: pattern watch (interpreted SCC)
break r17                            level 1: pause when r17 fires
break r17@2                          level 1: pause at body position 2
break r17 when (= X "main")          level 1: conditional on bindings
watch ?(?count (path X _))           client-side: re-run query at barriers,
                                     print only when the result changes
```

Notification watches print dim event lines above the prompt as runs progress
(the daemon's slice cadence makes this natural); breaking watches drop into
paused mode. `watches` lists them with hit counts; watches follow a QName
across successor versions by client-side re-resolution (repl.md §6), shown
explicitly in the listing so nobody is surprised.

Level-0 watches are nearly free and ship first; installing any level-1 watch
prints the tier consequence honestly: `note: scc5 will run interpreted while
w4 is set (was O2)` — the cost model is part of the UX, not hidden.

### 9.2 Paused mode

A pause (breakpoint, watch, memory, Ctrl-C) changes the prompt to
`run0 ⏸ ▸` and unlocks a mode where the paused snapshot is simply *a place*:

- ordinary observations work against it (queries run in the quiescent-master
  states execution-tiers §6.3 defines), so "poke around while stopped" needs
  zero new machinery;
- `peek` shows this iteration's pending delta by relation — what is about to
  commit;
- `commit` / `replay [with deeper budgets]` / `abort` resolve a pre-commit
  watch pause (execution-tiers §7.2); `continue` resumes an ordinary one;
- **Ctrl-C during any run means pause, never kill.** The first Ctrl-C brings
  the run to its next slice boundary and opens paused mode; `abort` is the
  explicit destructive verb. This single choice removes the classic terror of
  long fixpoints.

### 9.3 Stepping: the semi-naive four-port

Prolog's tracer taught a generation what resolution *does*; Slog's stepping
model should do the same for semi-naive evaluation. The interpreter's
explicit cursor stack (execution-tiers §4.2) is already the debugger's frame
stack; the ports of one rule attempt are:

```text
drive   the driver cursor yields a delta tuple        (outermost "call")
match   a join level's cursor finds a row             (per body position)
miss    a join level exhausts — fail, with the partial binding shown
guard   a comparison/primitive passes or cuts
emit    head produced: new | duplicate               (dup resolved at settle)
```

plus iteration-level ports (`iter begin/end`, `fixpoint`). Step granularities
compose with them: `step` (one port), `step match`, `step fire` (next emit),
`step tuple` (next driver tuple), `step rule r17` (until r17 next fires),
`step iter`, `finish` (to iteration end). `frames` prints the join stack with
**source variable names** (via rule-meta) and current bindings; `up`/`down`
walk it; the tuple at each frame is an ordinary expandable value. This is
"checkpoints within rules": a breakpoint or step target is a body position of
a rule variant, and the interpreter owns exactly that granularity.

### 9.4 Why and why-not

`why <fact>` renders bounded proof trees (execution-tiers §7.4) through the
standard tree canvas: premises expand like any subtree, shared subproofs
dedup with `#N`, and each premise's card offers `why` again — provenance
browsing *is* tree browsing. `whynot <fact>` renders the failure frontier the
same way, with each frontier line offering a chase (§4's transcript). Both
verbs work at any boundary and in paused mode; both echo their budgets so a
deeper look is one recall-and-edit away.

### 9.5 The tuner's bench

- `hot [run0|dbN]` — top rules by fires (from `$stat_fires`), with `r17`
  handles ready for `explain`;
- `explain r17` — the canonical plan: driver, join order, index orderings,
  semijoin filters, WCOJ3 arms, tier designation and current attachment
  (interp/O0/O2, CodeId, `.so` path) — the "examine compiled rules" surface;
- `explain ?(...)` — the query plan with the degradation notes Q1 specifies
  (scan-plus-filter fallbacks called out);
- `tiers` — per-SCC executor policy, what the compile queue is doing, which
  artifacts are cache hits (the cached-`.so` visibility the vision asks for);
- `stats` — per-stratum iterations and times from `$stat_fixpoint`.

### 9.6 Errors are facts, so errors are browsable

After any event that produced `(error ...)` facts, the change summary ends
with `⚠ 3 error facts (show errors)`, and `show errors` is a normal result —
rows with cards, `why .1` chases the derivation to its source location. The
runtime-error story (running.md) becomes an interactive one for free.

## 10. Programs, rules, and compiled code

The introspection surface for "what is loaded and what is it compiled to":

```text
progs                     program events in the recipe: name, instance key,
                          boundary, binding map (a0.syntax -> syn, repl.md §2)
rules [prog|scc5|rel]     rules with r-handles, source locations, fire counts
show r17                  source text + provenance (rule-meta)
explain r17               canonical plan + variants + tier + attachment
code scc5                 kernel plan key, attachments (tier, CodeId, path,
                          shard count), profile sidecar summary
types [ns.*]              struct/union catalog; show @t4 for one type's card
```

All of it reads the identity model of execution-tiers §2 — RuleId/VariantTag,
KernelPlanKey, AttachmentId — which exists precisely so these questions have
non-string answers. The REPL never parses mangled names back apart (repl.md
§7's contract).

## 11. Wilder ideas — the parking lot

Recorded so they shape interfaces without blocking slices:

- **Query-result watches as dashboards.** `top` — a live, redrawing pane of
  relation sizes / iteration counts during a long run (htop for fixpoints).
  The slice cadence and level-0 size watches make this nearly free.
- **Provenance export.** `why ... > proof.dot` / `.html` — hand a colleague a
  browsable proof.
- **Session branching.** `fork db3 as b1` — two live tips over one daemon;
  repl.md deliberately defers this, but the UX should reserve the vocabulary
  (checkout/fork) so linear-session errors read as "not yet" rather than
  "never."
- **Detach/attach.** A long fixpoint survives the terminal: `detach`, later
  `slog repl --attach <session>`; the daemon side already outlives clients,
  and a TCP transport (`run_tcp` in slogd) already exists for the wire.
- **Notebook/web front-end.** The client stack below the terminal layer (§12)
  serves a Jupyter kernel or a web canvas; presentations map to collapsible
  DOM naturally. The `#N`/pin economy is identical.
- **`suggest`/lint.** Surface the compiler's warnings (unkeyed recursive
  scans, Cartesian risks) against scratch rules as they are typed.
- **Counterexample-driven test capture.** `keep .3 as-test` — write a small
  `.slog` test asserting the presence/absence of a browsed fact, seeded from
  the session (the author persona's loop-closer).
- **Value search.** `find "main"` — probe the string interner, then walk
  occurrence/column indices for the relations containing it; budgeted scans
  where indices are missing. The explorer's "grep for my database."
- **Watch on rule fire-rate.** `watch r17 rate` — per-iteration fire deltas
  as a notification stream (needs per-iteration fire flush or interpreted
  instrumentation; cheap once level-1 exists).

## 12. Implementation shape (native client + Racket control plane)

Six layers, dependencies strictly downward; the top two are the only ones
that know a terminal exists.

```text
Rust term      Crossterm events/raw-mode and one Ratatui terminal owner
Rust canvas    cell layouts, transcript viewport, marker maps, gestures
Rust present   planned value/proof/plan/schema/diff presentation trees and
               handle registry; pure data in, pure data out
Rust lang      planned verb grammar, command AST, completion, embedded-source
               readiness; commands cross the wire as structured requests
Racket session compiler/repl.rkt + compiler/session.rkt: compilation, recipe,
               boundaries, catalogs, alias/retention policy, daemon lifecycle
Racket wire    session-action! and the daemon protocol, migrating verb by verb
               to structured catalog/query/watch/pause operations
```

The concrete source mapping, terminal substrate, and platform gates are fixed
in [repl-terminal.md](repl-terminal.md). The Rust binary is the only terminal
frontend; `compiler/repl.rkt` is the only Racket REPL server. The current
full-screen client keeps session history in its own PageUp/PageDown and
mouse-wheel transcript.
A future plain or inline client can reuse the same app/presentation and wire
models.

Points worth fixing early:

- **`present` is the reuse jackpot.** Every feature section above renders
  through it; building it as pure tree-in/lines-out (no tty knowledge) is
  what makes the canvas, plain mode, golden tests, and a future web frontend
  the same code.
- **The echo discipline is architectural, not cosmetic.** Gestures construct
  command ASTs and feed them through the same dispatcher as typed lines; the
  echo is the printed AST. There is exactly one code path that does things.
- **Handle registry state is tiny and central**: id → (kind, evaluation,
  raw word or key, boundary context, generation, pin, tombstone). Everything
  in §7 is operations on this one table.
- **Terminal portability** stays contained in Crossterm and the Rust `ui`
  module; unicode markers (`▸`, `⏸`, `◂`) have ASCII fallbacks. One event loop
  owns every Ratatui draw, so asynchronous watch notifications cannot splice
  themselves into the editor.
- **Nothing here blocks on the interpreter.** `session` + `wire` + `present`
  with lookup-sugar queries and level-0 watches is a useful REPL against the
  daemon as it exists after T0.

## 13. Sequencing sketch

Slices, mapped to the T/Q phases (execution-tiers §11):

- **R0 — the shell** (needs T0; large parts need only what ships today):
  `slog repl` mode owning one session; dbN/@vN/@tN/#N tables;
  run/add/del/stage/flush/inject/save/load/rename/drop; rels/schema/types/
  inspect/history/diff/log; change summaries; lookup-sugar queries; level-0
  watch/break with paused-mode queries via existing pause machinery; plain
  rendering with budgets + `show #N`; dbtool verbs mounted. The semantic row
  is a skin over existing `session-*!` calls and the observation row over
  existing read-only actions (§15), so R0 is mostly `lang` + `present` +
  alias tables — already the best interface the system has ever had, with
  zero interpreter.
- **R1 — the canvas**: navigate mode, in-place expansion, cards, pagination,
  completion, gesture echo. Pure client work; can overlap anything.
- **R2 — the query REPL** (needs Q1): the `?` register, explain, dump,
  `?count`/`?exists`, query watches, `uses`/`find`.
- **R3 — the workbench** (needs T2/T3): scratch layer with instant
  interpreted views, `keep scratch`, tier visibility (`tiers`, `code`,
  arrival notes in summaries).
- **R4 — the debugger** (needs T5): level-1 watches, break r17[@k][when],
  stepping/frames, why/whynot trees, pre-commit commit/replay.
- **R5 — the operator's edge** (needs the relevant M milestones): whatif
  cones, richer counted-status in cards, branching/fork if and when the
  session model grows it.

## 14. Open questions

1. **Scratch commit granularity.** Run each completed scratch rule
   immediately (live feel, more boundary churn) or stage until a `go`?
   Leaning immediate-with-coalescing (rules typed within one paste commit
   together).
2. **Handle splice syntax in Slog fragments.** `#42` inside a query body must
   not collide with future Slog lexing; reserve the token in the REPL reader
   only, or claim it in the language grammar?
3. **Pin persistence.** Do pinned names survive REPL restart via a session
   sidecar (`.slog-repl/`), given values may not survive daemon restart?
   Tombstone-on-load seems right; needs a decision.
4. **`runN` visibility for background work.** v1 is synchronous-with-pause;
   if detach ships, how much of the run protocol becomes user-visible state
   (`runs`, `attach run0`)?
5. **Where `db edit` meets the session.** dbtool's offline edit verbs vs the
   live `add/del` at the tip — one vocabulary or two? (Ideally the offline
   verbs are described as "the same events, applied at load.")
6. **Result-history depth.** How many prior results stay re-summonable
   (`it~k`) and does that interact with handle generations?
7. **Auto-flush coalescing.** Bare `add` auto-flushes (§5.2.1); should
   consecutive `add` lines typed within one paste coalesce into one boundary
   the way scratch rules do, or is one-line-one-boundary the less surprising
   rule?

The former terminal questions are resolved by repl-terminal.md: Rust owns the
whole-screen cell buffer through Ratatui/Crossterm; Linux and macOS VT
terminals are the release envelope; the current client uses an alternate
screen and an application-owned scrollable transcript; and one UI writer
redraws after terminal, backend, or resize events. Navigate mode remains an R1
interaction decision rather than a terminal-substrate question.

## 15. Appendix: the substrate as of 2026-07-14

An inventory of what already exists, because it determines how thin each
slice really is. (Surveyed from `compiler/session.rkt`, `compiler/dbtool.rkt`,
`compiler/actions.rkt`, `compiler/runslog.rkt`, `daemon/slogd.cpp`.)

**Semantic verbs — essentially complete in `session.rkt`.**
`session-open!` (plain/compressed/recipe-chain loads), `session-run!`
(compile a segment against the live schema, per-run version boundaries),
`session-batch!`/`session-flush!` (queued, normalizing, anchored signed
batches committed as one optimistic update epoch — §5.2.1's staging model is
already the implementation's shape), `session-inject-version!`/
`session-inject-batch!`/`session-inject-and-reopen!` (the inject verb),
`session-import-delta!` (bulk binary payloads), `session-link!`,
`session-rename!`/`session-drop!`, `session-recount!`, `session-save!`,
`session-log`/`session-recipe` (the transcript's semantic spine), and
`session-action!` as the low-level escape hatch. The REPL's semantic register
is a naming-and-summarizing layer over these.

**Observation verbs — a useful read-only set exists as action plugins.**
`(pipeline)` (version chains, strata, VersionIds — the raw material for
`log`/`history`/`dbs`), `(schema)` (nonempty materialization — a stopgap
until the boundary-catalog verbs of repl.md §7 exist), `(sizes)`,
`(lookup rel v...)`, `(dump-rel)`/`(dump-tuples)` (paged dumps),
`(signature)`. What is missing before the dream: real queries (Q1),
catalog/type-registry introspection (T0), and structured record replies
keyed by VersionKey rather than name strings (repl.md §7).

**Interactivity seams — present but latent.** The driver's stratum loop is
already a synchronous request/reply console (one bounded work unit per
`(continue)`, structured `(paused ...)`/`(fixpoint ...)` replies); the daemon
accepts the two literal non-plugin lines `(continue)`/`(continue-boundary)`
precisely so a console can resume without a clang build; read-only actions
are admitted against a suspended snapshot while mutating ones are refused —
which is exactly paused-mode observation (§9.2) waiting for a prompt to live
in. The driver's post-stratum auto-dump of new `error` facts is §9.6's
mechanism in embryonic form. A `run_tcp` transport exists beside stdin.

**What has no precursor at all** — the things this document exists to
design: the terminal canvas and navigate mode, the presentation engine and
handle registry, the REPL reader, completion, change summaries, the scratch
layer, and every debugging affordance past level-0 pause/continue.
