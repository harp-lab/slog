# 11. Under the hood

You can use Slog without reading this chapter. But knowing roughly how
it runs makes performance predictable and the toolchain unsurprising.

## From your file to native code

A run proceeds in stages:

1. The **compiler** (Racket, under `compiler/`) parses your program,
   desugars the surface conveniences (brackets, braces, demand), type
   checks it, and splits it into **strata** — groups of rules that must
   reach their fixpoint before later groups start. (If your rules for
   `b` only read finished `a`, then `a` runs first and `b`'s rules
   never need to iterate over it.)
2. Each stratum is compiled to **specialized C++** and built into a
   native plugin (`build/<hash>.so`). The hash covers your program and
   the compiler itself, so plugins are **cached** — rerunning an
   unchanged program skips straight to execution, and editing one file
   of a multi-stage project recompiles only what changed.
3. The **daemon** (`daemon/slogd`, C++) loads the plugins in order and
   runs each to fixpoint with a pool of worker threads.

That's why a first run pauses (clang is compiling your rules) and later
runs start instantly.

## How the fixpoint engine avoids wasted work

The naive model — "keep applying all rules to all facts" — would
re-derive everything every round. The engine instead runs
**semi-naive**: each iteration, rules run only against the facts that
are *new* since the last iteration (the "delta"). New facts breed new
facts until an iteration produces nothing, and that's the fixpoint.
Inside an iteration, work is split across threads by hashing facts into
buckets; indices are B-trees chosen per rule so that every pattern
match is a lookup, not a scan.

Two practical consequences:

- **Derivation count matters more than rule count.** A program with a
  million small derivations costs a million index operations, however
  few rules it has.
- **Facts are deduplicated at the door.** Deriving the same fact twice
  is nearly free — which is why exhaustive-sounding rules ("every pair
  of…") are often fine.

Structured values are **interned**: each distinct value stored once, in
its own relation, and referenced by a single machine word. Nesting is
pointer-cheap, equality is instant, and printing a value walks the
structure back out.

## The file layout

| Path | What it is |
|---|---|
| `compiler/` | the Racket compiler, one file per pass |
| `daemon/` | the C++ runtime (`slogd`) and its headers |
| `lib/` | the standard library (`list`, `set`, `map`) |
| `build/` | cached compiled plugins — safe to delete anytime |
| `out/` | CSV output from `--debug-dir` |
| `data/` | saved databases from `--out-db` |
| `examples/`, `tests/` | worked examples and the golden test suite |

## Testing

The test suite is a set of small programs with checked-in expected
outputs ("goldens"):

```
$ ./tests/run-tests.sh                 # run everything (clears build/ first)
$ ./tests/run-tests.sh --keep-cache    # faster: reuse cached plugins
$ ./tests/run-tests.sh tests/reach.slog          # just one test
$ ./tests/run-tests.sh --update tests/new.slog   # snapshot a new golden
$ raco test tests/unit/                # compiler unit tests
```

If you change the compiler or the daemon headers, caches invalidate
automatically (the plugin hash covers them) — but run the full suite,
not `--keep-cache`, when in doubt.

## When something is slow

- **Slow first run, fast after** — that's clang compiling; normal. Big
  programs generate big C++; the cache means you pay once.
- **Huge inline blocks of ground rules** compile into the program
  itself. Load bulk data from a saved database instead (chapter 9).
- **`--sizes` is the first profiler.** A relation with wildly more rows
  than you expected usually points at the rule deriving too much —
  often a missing join variable.
- The daemon prints `(fixpoint <scc-id> "<name>" <iterations> <ms>)`
  per stratum: many iterations means long dependency chains; long
  milliseconds with few iterations means heavy joins.

## Cheat sheet

| Command / path | Meaning |
|---|---|
| `racket slog.rkt prog.slog` | compile (cached) and run |
| `--debug-dir DIR` | CSVs per non-empty relation |
| `--sizes` | row counts — the quick sanity check |
| `--out-db N` / `-d N` | save / load `data/N/` |
| `--no-banner`, `-v`, `--version` | quiet, verbose, version |
| `build/` | plugin cache; deleting it just forces recompiles |
| `(fixpoint id "name" n ms)` | daemon's per-stratum report: scc-id, name, iterations, time |
| `./tests/run-tests.sh [--keep-cache] [--update] [files]` | golden tests |
| `raco test tests/unit/` | compiler unit tests |
