# Sudoku in Slog

A Sudoku solver written as **pure monotone constraint propagation** — no
search, no backtracking, no negation, no counting. Just facts and rules run
to a fixpoint.

## Files

- `sudoku.slog` — the solver. Derives the board geometry (cell coordinates,
  peers) with arithmetic, then propagates two classic deduction techniques
  (naked singles and hidden singles) to a fixpoint. Reusable across puzzles.
- `easy1.slog`, `hid_a.slog`, `escargot.slog` — puzzles. Each `include`s
  `sudoku.slog` and adds its clues as `given` facts.

## Running

```
racket compiler/run.rkt --no-banner --sizes --debug-dir out/sudoku examples/sudoku/easy1.slog
```

The answer is one row per cell in `out/sudoku/solved.csv` (`cell digit`,
cells numbered 0..80 row-major). Render it:

```
sort -n out/sudoku/solved.csv | awk '{printf "%s%s",$2,(NR%9==0?"\n":"")}'
```

## What it can and cannot do

`solved` is seeded from the clues; a solved cell `blocks` its digit in every
peer and blocks every other digit in itself; a **naked single** (a cell with
8 of 9 digits blocked) and a **hidden single** (a digit blocked in 8 of a
unit's 9 cells) each force an assignment. Iterated to a fixpoint this solves
any puzzle completable by those two techniques — most "easy" and many
"medium" puzzles.

| puzzle | clues | result | solving iterations |
|--------|-------|--------|--------------------|
| `easy1` | 30 | solved (naked singles alone) | 12 |
| `hid_a` | 17 | solved (needs hidden singles) | 39 |
| `escargot` | 23 | **stalls at 24/81** | 5 |

Puzzles that require guessing (backtracking search) are beyond any
single-based propagation — `escargot` is the demonstration. Monotone,
aggregation-free Datalog cannot express the search efficiently (bottom-up
evaluation is breadth-first over *all* partial assignments, and the MRV
heuristic that tames real solvers needs counting). Expressing the two singles
techniques *at all* relies on the fixed 9-valued domain: "the sole surviving
candidate" becomes a bounded 8-fold conjunction rather than a negation or a
count, which is why each technique is nine near-identical rules.

## Note

`cellrc` identifies each 3×3 box by its band-row (`row/3`) and band-column
(`col/3`), and two cells share a box exactly when both agree — rather than
folding them into one box id `3*(row/3)+col/3`. Either form works; the split
just reads more directly ("same band-row **and** same band-column").

(Writing it this way originally also dodged a compiler bug: a primitive over
*two computed variables*, e.g. `(= B (+ (* (/ R 3) 3) (/ C 3)))`, raised
"Circular local-env alias". That bug — bidirectional overwrite of grounding
aliases in `type-system.rkt`'s polymorphic-argument linking — was fixed on
2026-07-03, so the box-id form now compiles too.)
