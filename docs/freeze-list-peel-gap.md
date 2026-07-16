# Freeze doesn't fire for ground facts containing sequence literals

*Investigation 2026-07-10 (scheme-slog-compile analysis work).*

> **RESOLVED 2026-07-10** — implemented in `compiler/freeze.rkt` (the
> classifier+emitter fix described under "Proposed fix" below). `seq-ctor?`
> recognizes a ground `lempty`/`lpush`/`lcat` chain in `peelable-heads`, and
> `seq->elem-strings` renders it back to the `[e …]` stream form in
> `term->string`. Validated: the struct-only golden (`tests/frozen_fact.slog`)
> still freezes; a list-bearing program AST (`stress`, 10 fns + a 40-elt list
> literal) now freezes and reconstructs **bit-identically** (same analysis
> output as the rule path: reach=224, mono_site=11, poly_site=0); and a program
> that previously spun in the front-end for minutes now gets through it in
> seconds. No daemon/C++ change was needed. The analysis below is the original
> diagnosis.

## The observation

A whole extracted program is one head-only ground fact `(program <Exp>)`. For a
large program (e.g. a Sudoku solver, ~27 merged top-level forms) this fact never
reaches the fixpoint: the run sits in the Racket front-end (parse/organize/plan/
emit) for minutes with **0 fixpoints and 0 clang invocations**, then either times
out or dies in codegen. `docs/freeze.md §1` describes exactly this failure mode —
"a large [ground fact] compiled as a rule … the emitted read phases nest one
brace scope per join, which overflows clang's own stack around 400–500 deep … a
~500-node tree in one fact is fatal" — and freeze exists precisely to avoid it.

**But freeze never fires for these program facts.** Evidence: after a session of
analyzing many extracted programs, the only entry in `build/frozen/` is the
golden `frozen_fact.slog` payload — a 512-node tree of `Nd`/`Lf` **structs, no
sequences**. No extracted program AST (all of which are far over the 512-node
`SLOG_FREEZE_MIN`) ever produced a frozen DB.

## Why: the peel classifier bails on desugared sequence literals

1. `(program <Exp>)` is head-only and ground → looks peelable.
2. But `<Exp>` is full of bracket-list literals: `[Clause]`, `[Ref]`, `[Exp]`,
   `[Datum]`, argument lists, etc.
3. In head/construction position a bracket lowers **in place to a nested
   `lempty`/`lpush`/`lcat` prim chain** — `compiler/collections.rkt:93-94`
   (`desugar-collections-mods`) — and this desugar runs **before** peel
   (`desugar` is pre-demand-transform; `peel-ground-facts` is called at
   `compiler/compile.rkt:98`, post-demand-transform).
4. So `peelable-heads` (`compiler/freeze.rkt:45`) walks the head term and hits
   `(syn _ lpush …)`. Its `term!` (line 51) only accepts `const`, a
   `bracket-sym?` `[]`, a declared `struct`, or an `enum`; **any other symbol
   `bail #f`s** (line 65). `lpush`/`lcat`/`lempty` are prims, not
   structs/enums → the whole fact is classified **non-peelable**.
5. Non-peelable ⇒ stays on the rule path ⇒ compiled as a giant rule ⇒ hits the
   400–500-node clang nesting ceiling. Small ASTs (e.g. a 10-function program)
   squeak under the ceiling and run; big/recursive ones do not.

Note the classifier and the emitter already *support* the `[]` bracket form
(`bracket-sym?` recursion at `freeze.rkt:57`; `term->string` renders
`(syn _ [] …)` → `[…]` at `freeze.rkt:109`), and the `.facts` stream format
accepts `[term …]` (`docs/freeze.md §3`). The gap is only that by peel time the
bracket has already become an `lpush` chain, which neither recognizes.

## Proposed fix (classifier + emitter side; not yet done)

Teach the peel pass to treat a **ground** `lempty`/`lpush`/`lcat` chain as a
sequence literal:

- `peelable-heads`/`term!` (`freeze.rkt`): when it sees `(syn _ lpush s e)` /
  `(syn _ lcat a b)` / `(syn _ lempty)` with all subterms ground-peelable,
  accept it (recurse into the element terms) instead of bailing.
- `term->string` (`freeze.rkt`): render that same chain back to the `[e …]`
  stream form (flatten `lpush`/`lcat` over `lempty`). The freezer already
  ingests `[…]`, so no C++/daemon change is needed.

This is the classifier-side fix the extractor's `KNOWN UPSTREAM GAP` note
anticipated. It would let whole-program AST facts freeze to a static DB (the
`docs/freeze.md` "16,383-node tree freezes and runs in seconds" path), removing
the front-end/codegen wall that currently blocks analyzing realistic programs.

Alternatively, `docs/freeze.md §5` already lists "ground *subterms* of variable
rules (peel the subtree, content-join the residual)" as deferred — the same
subterm-peeling machinery would subsume this if it recognized sequence chains.

## Repro

```
# in the analysis project:
scheme --script chez-extract.ss -o sudoku.slog tests/sudoku.ss
printf 'include "prims.slog"\n' > drv.slog; sed -n '/^rule (program/,$p' sudoku.slog >> drv.slog
cd ~/slog && SLOG_OPT=0 racket compiler/run.rkt --debug-dir /tmp/out /path/to/drv.slog
# -> front-end spins for minutes, 0 fixpoints; build/frozen/ gets no new entry.
```
A struct-only ground fact of comparable size (like `tests/frozen_fact.slog`)
freezes and runs in seconds — the difference is purely the sequence literals.
