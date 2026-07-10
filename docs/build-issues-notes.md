# Build & toolchain friction: notes from an intensive external-user session

*Written 2026-07 after ~a week of sessions building a real analyzer on top of
slog — a small-step m-CFA abstract interpreter for Chez Scheme's extracted core
IR (in `~/scheme-slog-compile`), plus abstract counting, a cons/null shape
domain, and an abstract-symbolic-execution layer over the SMT oracle. This is a
field report of the rough edges I hit as a heavy user who is **not** a slog
developer. Root causes marked "(inferred)" are my best guess from the outside;
everything else is a reproduced observable. The intent is to save the next
person time and to point maintainers at the highest-leverage fixes.*

The short version: slog's *ideas* held up beautifully under load — structured
values as columns, demand relations, lattices, the SMT oracle, persistent DBs.
The friction was almost entirely in the **build system** and in **diagnostics**:
several distinct mistakes surface as the *same* opaque internal error with no
source location, and the compile cost of one giant stratum dominates everything.

---

## 1. Running the toolchain: it must be `cd`'d to the slog root

The driver builds the daemon with `make -C daemon` and looks for `daemon/slogd`,
both **relative to CWD**. Running `racket slog.rkt <abs-path-to-my-file>` from
anywhere else fails with:

```
make: *** daemon: No such file or directory.  Stop.
Something went wrong compiling the daemon!
```

which reads like a corrupt install but just means "wrong directory." Analyzing a
project that lives elsewhere therefore means `cd /path/to/slog && racket
slog.rkt --debug-dir <out> /abs/path/to/project/file.slog`. Minor, but it cost
me a while at the start because the error doesn't say "run me from the repo
root."

**Include resolution has a silent failure mode.** An `include "x.slog"` resolves
relative to the *including file's* directory, then falls back to slog's `lib/`.
If neither exists, the include is **silently dropped** and its declarations
simply don't exist — so you get a cascade of "relation/struct X is not defined"
for things you clearly included. This bit me hard when writing scratch test
files *outside* the project directory: `include "syntax.slog"` found nothing and
was dropped, and I chased phantom "not defined" errors. A one-line "include
target not found, ignoring" warning would have saved an hour. (Workaround:
absolute include paths for out-of-tree files.)

---

## 2. `pkill` mid-compile corrupts the build cache — with a *very* misleading symptom

The single worst time-sink of the whole engagement. I killed a stuck run with
`pkill -f slogd` while a plugin was compiling. Afterward, **every** run — even
byte-identical known-good programs that had worked minutes earlier — failed with:

```
lower-all: broke its own contract
  promised: cprog?
  produced: (list 'cprog (set ... ))
  at: compiler/compile.rkt:66:18
```

I spent a long bisection assuming my *source* was at fault (reverting union
arms, rule changes, one at a time — all still broke), because the error is a
Racket contract violation deep in the compiler with no hint that it's
cache-related. The fix turned out to be:

```
rm -f build/*.cprog build/*.cpp build/*.so build/*.meta build/*.O0.so
```

i.e. a partially-written cache artifact from the interrupted build poisons
`lower-all` for all subsequent programs. Two asks: (a) make `lower-all`'s
contract failure name the offending relation / point at the stale artifact; (b)
if a cache entry can be left half-written, checksum it on read and re-emit
rather than feed a malformed `cprog` downstream. And for users: **let a run's
`timeout` fire; don't `pkill` the daemon.**

---

## 3. Tiered -O0/-O2 in practice: the giant stratum breaks the amortization

`docs/fast-compile.md` promises "run at -O0 immediately, hot-swap to -O2 under
the hood," and the artifacts confirm the mechanism works (both `<hash>.O0.so`
and `<hash>.so` appear; `SLOG_OPT` defaults to `tiered`). But for my analyzer it
did **not** deliver cheap iteration, and it's worth recording why.

My interpreter is one big mutually-recursive SCC (`step`/`reach`/`vstore`/
`lookup` all in one stratum), which lowers to a single ~50k-line C++ TU split
into 8 partitions of ~6–7k lines. Per the doc's own table that's the kcfa-scale
stratum: **~5 min at -O2, and even -O0 is not the 5.7s of the schemecfa
stratum.** Measured, cache "warm":

- A re-run of a *tiny* program over this analyzer (fixpoint = a few ms) still
  took **~43–65 s wall, essentially all compile.**
- Watching artifacts across three identical runs: the program hash is **stable**
  (same stratum ids each run), yet the big stratum's `.O0.so` is **rebuilt every
  run** (mtime changes), and its `.so` (-O2) **never exists** — the ~5-min O2
  compile outlives a short run, detaches, and is lost, so it's re-attempted (and
  the O0 re-emitted) next time.

So the "-O0 to first result" path is tens of seconds, not the 3:45 my first
naive `/usr/bin/time` reported (that wrapped the whole process including the
abortive O2), but it is still ~40 s of recompile on *every* fresh invocation,
because (inferred) the O0 cache isn't being reused for the split stratum and the
O2 artifact never caches. The upshot for anyone doing per-configuration sweeps
(I was varying `m` and toggling analysis modules): each run pays the giant
stratum again. Two things would change the game: **(a) fix O0 cache reuse for
partitioned strata** (stable hash + present `.O0.so` should be a cache hit); and
**(b) either shrink the big-stratum codegen or make the O2 artifact survive a
short run** so it amortizes as designed. The deeper fix is on the *analysis*
side — break the one big SCC into smaller strata — which is squarely my problem,
but the build system currently offers no relief when a user does have one large
SCC.

For clean *solve-time* measurements I ended up using `SLOG_OPT=0` (O0 only, no
background O2) to remove the O2 noise, and `SLOG_OPT=2` when I wanted the O2
artifact forced and cached. Documenting that as the "benchmarking knobs" recipe
would help.

---

## 4. The SMT oracle at scale: works standalone, breaks the build on a large program

The oracle is genuinely nice and the shipped `examples/verify/demo.slog` runs
cleanly. But layering `smt.slog` on top of my *full* analyzer failed to build
the oracle's **action** plugin. It surfaced as:

```
open-input-file: cannot open input file
  path: build/602143d306be-so<digits>.tmp.log
  system error: No such file or directory
```

i.e. an action-plugin build failed and the driver then tried to read that
build's log to report the failure — but the log was already gone, so the *real*
error is masked by a secondary file-not-found. No OOM (18 GB free), and the same
program's non-oracle strata built fine, so (inferred) it's the action-plugin
codegen at scale, and/or a tempfile race with the detached O2 jobs (the missing
file is a `-so<n>.tmp.log` build log). `SLOG_OPT=0` (no background O2) got the
full symbolic analysis to build and run end-to-end — which both supports the
"O2-background race" theory and gives a workaround. Ask: don't delete the build
log before the failure path reads it, and surface the clang stderr directly.

---

## 5. Distinct user errors that all surface as the *same* opaque internal error

This is the diagnostics theme, and probably the highest-leverage area. Four
unrelated mistakes I made each produced a cryptic internal failure with **no
source location**, so each required a bisection to localize:

- **A `_` wildcard in a *head* position.** `rule (siexpr (Constant (Quote _
  (DInt n))) (ic n)) <-- ...` — the `_` in the head is an unbound fresh var.
  Symptom: `hash-ref: no value found for key: '__41gu939` (a gensym'd wildcard).
  A parse/check-time "wildcard in head is unbound; name it" would be instant.

- **`col=pattern` binding with wildcards inside**, e.g. `(pc a=(Eval _ _ _) S)`
  in a body. Same symptom (`hash-ref … '__gensym`). I use `e=(App _ ...)` freely
  in *heads* and it works; the same form in a body with interior `_` does not.
  Whatever the rule is, the error should say it.

- **Extending a `union` across files.** `docs/demand.md` says union declarations
  merge, and they do for the demand transform's synthesized `clo`. But a *user*
  adding an arm to a union declared in an included module
  (`union (Val (Pair Exp Ctx))` where `Val` came from the include) trips
  **`lower-all: broke its own contract`** — the same symptom as the corrupt
  cache in §2, which is doubly confusing. Workaround: declare every arm in one
  place (I moved my shape-domain arms into the core's `Val`/`D` unions). Ask:
  either support cross-file union extension or reject it at declaration time with
  "union `Val` already declared in <file>; extension not supported."

- **A demand relation with zero input columns.** `demand (shape_prims) [str]`
  (I wanted a nullary "constant list") errors `Demand relation shape_prims must
  have at least one input column`. This one *is* a clear message — the
  contrast shows how much the others could improve. (Fix was to make it a
  `table`.)

The pattern: `hash-ref: no value found for '__<gensym>` and `lower-all: broke
its own contract` are each produced by several different root causes and carry
no rule/line context. Even just echoing the source span of the rule being
lowered when these fire would turn multi-step bisections into one-glance fixes.

---

## 6. The scariest one: a guard that silently does nothing

`/=` against a **constructed structured literal** inside a *recursive demand
SCC* silently never fires — **no error at all**, the rule just produces nothing:

```
;; inside the recursive `step` fixpoint — silently dead:
rule (... (Eval e1 ...)) <-- (lookup d (Constant (Quote _ dat))) (/= dat (DBool (False)))
```

It works in a non-recursive stratum and in isolation tests, which made it
maddening — my `if`-branch-pruning produced empty results with no diagnostic.
The fix (learned from `examples/schemecfa`'s `scheme_false`) is to bind the
comparison value from a ground fact and compare against the *variable*:

```
table (false_datum Datum)
rule (false_datum (DBool (False)))
rule (... (Eval e1 ...)) <-- (lookup d (Constant (Quote _ dat))) (false_datum fd) (/= dat fd)
```

A silently-dead guard is worse than a crash. If literal-vs-variable in a
recursive SCC is a known limitation, a compile-time warning ("`/=` against a
constant literal in a recursive stratum may not fire; bind it first") would be
enormously valuable — this is the kind of thing that erodes trust in an
otherwise-sound engine.

---

## 7. What worked, and the ask

None of the above is about the *language* or the *semantics* — those were a
pleasure. Structured values as columns made the AST-as-data and continuations-as-
data patterns effortless; demand relations gave me memoized big-step judgments
for free; lattices (`count`, `(set any)`) let me express abstract counting and
path-condition merging with no aggregation plumbing; the SMT oracle let a
downstream module verify infeasible error paths with z3 and *zero* changes to
the core interpreter; and the persistent-DB model is exactly the substrate an
incremental, per-function-`m` refinement loop wants. That's a remarkable amount
of leverage.

Ranked by how much time they'd have saved me:

1. **Source locations on internal errors** (`lower-all`/`hash-ref`) — turn
   bisections into one-liners.
2. **The silent `/=`-literal-in-recursive-SCC failure** — make it work or warn.
3. **O0 cache reuse for split strata** + a way for the big-stratum O2 to
   amortize — the difference between "iterate in seconds" and "40 s per run."
4. **Don't mask the real build error** behind the missing-`.tmp.log` read; and
   checksum cache artifacts so an interrupted build can't poison `lower-all`.
5. **Parse-time rejection of head wildcards / interior-wildcard `col=pattern`**,
   and a decision on cross-file `union` extension (support or reject clearly).
6. **A silent-include warning.**

All of these are diagnostics/build-system polish, not deep engine work — which
is a good place for a young system to be.

---

## Maintainer status (2026-07-10)

Re-assessed against the current tree; reproduced on `~/scheme-slog-compile`.

- **§3 O0 reuse for split strata + O2 amortization — FIXED** (docs/fast-compile.md
  §13). Tiered mode now reuses a cached `<hash>.O0.so` instead of re-emitting +
  rebuilding it, background `-O2` builds are single-flighted via a
  `<hash>.so.building` claim marker and detached under `setsid` (so a 5-min O2
  survives a short run and lands in the cache for next time), and each is
  `timeout`-bounded. Measured on `bench1.slog` (the 16-TU, 12.5 MB kcfa-scale
  stratum): a warm re-run went 77 s → 21 s with the giant `.O0.so` **reused, not
  rebuilt**, while its `-O2` finished in the background and cached. This was the
  #3 ask.
- **§1 silent include — FIXED.** `compiler/modules.rkt` now warns
  `include "X" not found (searched … and lib/); ignoring it` (and the same for
  `run` targets). The #6 ask.
- **§5 head wildcard — FIXED.** A `_` in a head/conclusion (including nested in a
  constructed term) is now rejected at simplify time with the offending rule's
  location, instead of surfacing as `hash-ref '__gNNN`. The other §5 items:
  interior-wildcard `col=pattern` in a body no longer reproduces (works in the
  current tree); cross-file `union` extension and the general "source location on
  every `lower-all` contract failure" are still open (see below).
- **§2 pkill cache poisoning — mechanism closed.** `.cpp/.cprog/.meta` are now
  written via temp+atomic-rename and `.so` via temp+rename (2026-07-07), so an
  interrupted build can no longer leave a half-written artifact. The residual is
  the *diagnostic*: a malformed `cprog` (from a genuine compiler/frontend issue)
  still fails the coarse `cprog?` contract with no rule context — same root as §5.
- **§4 masked build error — masking resolved.** `compile-one` reads the build log
  *before* deleting it and `build-so` raises with the clang stderr, so the real
  error is surfaced (no more secondary missing-`.tmp.log`). The underlying
  "oracle *action* plugin fails to build at scale" is unverified here (needs the
  full symbolic analyzer + z3) and remains open.

Still open / needs discussion: **§5 general source-location on internal contract
failures** (a diagnostics pass threading rule spans, plus a few more parse-time
checks), **§6 the silent `/=` failure** (does NOT reproduce as a plain
"/= in a recursive SCC" — a single-level constructed literal filters correctly
in both recursive and non-recursive strata; the analyzer's case is narrower —
a *demand* SCC comparing against a *nested nullary-constructor* literal — and
needs a faithful minimal repro extracted from `interp.slog`), and the deeper
**large-SCC / large-workflow** story (one giant mutually-recursive stratum still
costs a full O0 build the first time and a ~5-min O2; the real lever is helping
users split SCCs and/or shrinking big-stratum codegen).
