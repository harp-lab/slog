# Tiered Compilation: Run at -O0 Immediately, Hot-Swap to -O2 Under the Hood

*Design + sprint plan, 2026-07-07. Status: **implemented** 2026-07-07.  All six
stages landed and are verified: the makeIndex-ladder removal + PCH + `-g`/opt
flags (tools.rkt, index.h, slogd.cpp, Makefile), the daemon hot-swap seams
(database.h, daemon.h), TU-splitting of large strata (emit-cpp.rkt) with the
header inline-ODR fixes, the tiered driver with a parallel build pool and the
mid-run -O0->-O2 swap (compile.rkt, runslog.rkt, actions.rkt), and the
parallel/`SLOG_OPT=0` test runner.  Trust tests in tests/tiered-tests.sh
(byte-identical across -O2/-O0/tiered; a deterministic mid-fixpoint swap) and
the existing pause/api/golden suites pass.  The description below is the design
as built; a few incidental notes on what changed during implementation are
inline.*

## 1. Goal and the measured problem

Fresh programs take minutes to start because every stratum `.so` is compiled
with `clang++ -O2 -g`, one at a time, before anything runs. Measured on the
current tree (8 cores):

| Unit | -O2 -g | -O0 |
|---|---|---|
| empty TU including daemon headers | 2.4s | — |
| median test-suite stratum (270-line .cpp) | 10.2s | ~2.5s |
| schemecfa big stratum (354 crules, 27.7k lines) | 164s | **5.7s (29x)** |
| kcfa big stratum (667 crules, 53k lines) | ~5min | — |

The Racket front end plus the daemon run is ~2–3s even for kcfa; the 65-minute
test suite is ~53 minutes of serial clang. Three structural taxes dominate:
every plugin TU instantiates `BTreeIndex<1..32>` **and** `BTreeMapIndex<1..32>`
via the `makeIndexRec`/`makeMapIndexRec` ladders (index.h, reached through
`Relation::ensureDefaultIndex`) — capping the ladder took the median stratum
10.2s→4.6s; header parsing (2.4s, →~0.5s with a PCH); and `-g` (~30%).
What remains for giant strata is the -O2 optimizer chewing the per-rule fused
operator chains (~0.4s/crule; -O1 saves only 14%). Crucially, **-O0 runtime is
indistinguishable at small-to-medium scale** (schemecfa's 109-iteration
fixpoint: 103ms at -O0 vs 80–105ms at -O2), and any long run amortizes an
upgrade. The rule counts themselves are healthy (semi-naive versioning ×~2.7 +
demand ×~2 — the same multiplicity Soufflé emits); this is a *build-system*
problem, not a codegen-volume bug.

## 2. The tiered model

**One generated `.cpp` (set) per stratum, compiled twice.** Both artifacts
come from the byte-identical source the cache hash already names:

- `build/<hash>.O0.so` — `-O0`, built eagerly, in parallel across strata.
  This is what runs first.
- `build/<hash>.so` — `-O2`, built by detached background jobs (`nice`,
  temp-file + atomic `mv` on success). This is the canonical cached artifact,
  exactly today's file.

Artifact selection when the driver needs stratum `<hash>`:

1. `<hash>.so` exists → use it (a re-run of a previously compiled program is
   pure -O2, exactly today's behavior; nothing else happens).
2. else `<hash>.O0.so` exists → use it now, (re)spawn the background -O2 job.
3. else → emit `.cpp`/`.cprog`/`.meta`, build -O0 now (parallel with the other
   strata's -O0 builds), use it, spawn the background -O2 job.

While a stratum is running from an O0 plugin and its `<hash>.so` materializes,
the driver **hot-swaps** it mid-fixpoint (§3–§5). On process exit the driver
does not wait for background -O2 jobs — they detach and land in the cache for
next time; a crashed/killed job just leaves no `<hash>.so` and is retried on
the next run (temp+rename means no torn artifacts, and concurrent runs racing
on the same hash are benign).

The opt level is deliberately **not** in the program hash — identical logical
strata at the two levels must share the name, because name-identity is what
makes the swap sound and what lets the O2 artifact satisfy the same cache slot.

Knobs (`SLOG_OPT`): `tiered` (default), `0` (O0 only — the test suite; no
background jobs), `2` (block for -O2, run only -O2 — benchmarking, today's
behavior). `-g` moves behind `SLOG_DEBUG=1` (both tiers). Both tiers compile
with `-ffp-contract=off` (§7, trap 5).

## 3. Why the hot swap is sound

The pausing sprint (docs/pausing.md) built exactly the substrate this needs:

- **The protocol is request-response.** The daemon is idle when it reads a
  path; `continueRun` does one bounded unit and returns. The swap happens
  between units, never under a running worker.
- **All fixpoint state lives in `Database`/`RunState`, none in tasks.**
  Canonical tasks are immutable and start-from-origin every iteration; the
  data (master indices, staged delta, bucket views, allocators, arenas) is
  daemon-side. At a **boundary suspend** (`RUN_AT_BOUNDARY`) the paused
  continuation queues are empty and no cursor points into a task vector
  mid-claim — the Stratum's task vectors are replaceable wholesale.
- **Both `.so`s are the same generated source**, so the replacement plugin
  re-declares the same relations, requisitions the same index ords, and
  registers the same task list in the same order. The swap changes machine
  code, not the program.
- **`rs.stratum` points at the Stratum object, not its tasks** — clearing and
  refilling the same object's vectors keeps every RunState invariant intact.
  `once_pending` is only reset when `starting`, so re-registered `once` tasks
  do not re-run mid-fixpoint (and even if they did, `emit` dedup makes a
  re-run idempotent — waste, not unsoundness).
- **The old `.so` stays `dlopen`ed forever** (slogd already retains handles
  until after `delete daemon`) — indices the O0 plugin created keep valid
  vtables; the O2 code reaches them through the same non-virtual hot paths it
  always inlines locally.

A **mid-read** suspend is *not* a swap point (parked continuation copies are
old-code objects holding exact resume positions; the delta isn't finalized).
Rather than teach the swap about that state, the driver first asks the daemon
to run to the next clean boundary (§4), which the default budgets make cheap.

## 4. Daemon changes (all small, all in daemon/)

1. **`Relation::addIndex<A>` idempotence** (database.h:405): currently
   `tbl[ord] = new Index*[...]` — a re-registration would *clobber the live
   master index* (leak + data loss). Guard: if `ord` is already present,
   return. Required for the swap; fixes a latent double-add hazard anyway.
2. **`RunBudget.stop_at_boundary`** (default false) + one clause in
   `EndIterCompletion::operator()` (database.h:2605): if set and not at
   fixpoint, choose `ACT_BOUNDARY_SUSPEND`. Time budget infinite, memory cap
   still active (a `memory` pause mid-read still wins — the abort policy is
   unchanged).
3. **`(continue ...)` action grows a `boundary` variant** (actions.rkt +
   the daemon's literal special-case): `continueRun` with the
   `stop_at_boundary` budget.
4. **`Daemon::beginStratum` upgrade path**: if `database->isSuspended()` AND
   the suspended stratum's name equals the requested name AND its position is
   `RUN_AT_BOUNDARY` → this is a hot-swap: `s->clearForUpgrade()` (delete all
   tasks, clear the six task vectors and `dynamic_rels`; assert the paused
   queues are empty), do **not** touch `needs_reload`, return the existing
   `Stratum*`. Every other suspended case keeps today's refusal. Non-suspended
   name collisions keep today's fresh-Stratum semantics (a console re-running
   a resident program must still re-run, not swap).
5. **`Daemon::push` idempotence**: pointer already in `pipeline` → no-op
   (keeps `scc_id`, keeps `next_unrun`).

Optional hygiene: after re-registration, compare new task counts per phase
against the pre-clear counts and `fatal` on mismatch — a cheap guard that the
two artifacts really are twins.

Nothing else changes. The upgrade plugin **is** the ordinary generated -O2
`.so`: `beginStratum` hands it the live Stratum, `addRelation` checks already
guard existence (generated code), `addIndex` no-ops, constants re-intern
idempotently, `addTask`/`addDynamicRel` refill, `push` no-ops, and its
trailing `continueRun()` resumes the fixpoint from the boundary — emitting the
usual one `(paused ...)`/`(fixpoint ...)` line, so the protocol shape is
untouched.

## 5. Driver changes (runslog.rkt + tools.rkt + compile.rkt)

**Compile scheduling.** Replace the future chain (which blocks on its first
I/O anyway) with: run all Racket passes up front (~1–2s total), then a bounded
subprocess pool (`min(nproc, jobs)`) building every needed `.O0.so`
concurrently; strata are *sent* strictly in pipeline order as each becomes
ready. Background -O2 jobs go into the same pool at `nice -n 10`, O0 jobs
always first (they gate progress; -O2 only gates nothing).

**The poll loop** (`drive-stratum!`) gains one branch. On `(paused ...)` for a
stratum launched from an O0 artifact whose `<hash>.so` now exists (one
`file-exists?` per pause):

```
(paused ... read ...)  → send (continue boundary) action     ; finish the iter
(paused ... iter ...)  → send build/<hash>.so                ; the swap itself
                          print "upgraded <hash> to -O2"; mark upgraded
(fixpoint ...)         → too late, no swap; proceed          ; O2 is cached for next run
```

plus one robustness tweak: match `(fixpoint ...)` lines against the *expected
stratum name* (the driver knows the hash it sent) and treat any other fixpoint
line as a stale idempotent re-confirm to print and skip. That makes the loop
insensitive to extra lines under any interleaving.

Everything else — memory-pause abort, error abort, terminal actions — is
unchanged. `slogd.rkt` (console) can adopt the same branch later; nothing
breaks if it doesn't (it just never upgrades mid-run).

**Exit.** Detached -O2 jobs (`setsid`, output to a log under `out/`) survive
the driver; print one dim note when leaving stragglers behind.

## 6. Splitting giant strata into parallel TUs

One stratum = one `.so` stays true; it is just *linked* from several `.o`s.
When a stratum exceeds ~48 crules, `write-cpp` returns a list of TUs instead
of one string:

- **Spine** (`<hash>.p0.cpp`): includes, the constant *definitions*
  (`u64 v_...;`), `slog_plugin` — beginStratum, constant init, relation/index
  decls, `slog_rules_<hash>_1(d,db,s); ...;` calls, `addDynamicRel`s,
  `push`, `continueRun`.
- **Parts** (`<hash>.pK.cpp`): `extern u64 v_...;` declarations plus
  `void slog_rules_<hash>_K(slog::Daemon*, slog::Database*, slog::Stratum*)`
  containing ~32–48 crules' local ReadTask classes and registrations —
  exactly the text emitted today, wrapped in a function instead of inline in
  `slog_plugin`.

`build-so` compiles TUs to `.o` in parallel (same pool, PCH shared) and links
`-shared`. Both tiers use the same chunking (they must — twin artifacts).
Registration order is preserved by the ordered part calls, so the O0/O2 task
lists match exactly. Expected effect at -O2: kcfa's 5-minute stratum →
~45–60s wall; at -O0 the giants drop to ~2s/chunk.

## 7. Substrate fixes folded in (from the 2026-07-07 measurements)

1. **Kill the arity ladder in plugins**: make `makeIndex`/`makeMapIndex`
   non-inline, defined once in slogd (declaration in index.h, definition in
   slogd.cpp), link slogd with `-rdynamic` so plugins resolve them at dlopen.
   Median stratum 10.2s→4.6s; also shrinks every `.so` (~7MB today, mostly
   these instantiations plus `-g`).
2. **PCH** for `daemon.h`+`operators.h`, one per (headers-fingerprint ×
   opt-level × flag-set), built lazily into `build/` (1.3s each), keyed by the
   fingerprint already in the cache hash. →~0.5s header cost.
3. **`-g` behind `SLOG_DEBUG`** (~30%).
4. **Parallel everything** (§5 pool).
5. **`-ffp-contract=off` on both tiers.** clang's default contraction can fuse
   `a*b+c` differently at -O0 vs -O2, so float prims could produce different
   bits across a swap — the one place "same semantics" could leak. Joins
   don't care about the lost FMA.
6. **`run-tests.sh -jN` + `SLOG_OPT=0`**: tests are independent (own out
   dirs, own slogd); the shared `build/` is safe under temp+rename.

## 8. Traps (and how the design dodges them)

1. **`addIndex` clobbering the master index on re-registration** — the guard
   in §4.1 is *the* prerequisite; without it the swap destroys data.
2. **Mid-read swap** — parked continuations are old-code objects and the
   delta is unfinalized; never swap there. The `boundary` continue makes the
   clean state reachable on demand; the daemon refuses otherwise.
3. **Stale upgrades** — only the poll loop sends upgrade paths, only while
   its stratum is suspended; the name-matched fixpoint parse (§5) makes the
   loop robust to any leftover idempotent lines regardless.
4. **Re-run-same-program sessions** — upgrade semantics trigger only when the
   name matches the *currently suspended* stratum; a resident console
   re-push still gets a fresh Stratum and today's re-run behavior.
5. **FP contraction divergence** — §7.5.
6. **once-task re-execution after swap** — `once_pending` stays false on
   resume; and `emit` dedup would make even a re-run harmless.
7. **dlclose discipline** — unchanged: handles retained until after
   `delete daemon` (slogd.cpp already does this); the O0 `.so` simply stays
   mapped for the process lifetime.
8. **Torn artifacts / cache races** — temp + atomic rename everywhere; a
   half-written `.so` never carries the canonical name.

## 9. Tests

- **The trust test (byte-identical)**: a long-running program (the
  pause-tests chain/fan-out pair, plus a float-arithmetic one) run three
  ways — pure -O2, pure -O0, and tiered under a pathological budget with the
  upgrade forced at the first boundary — all three produce byte-identical
  sorted CSVs.
- **api-tests additions**: scripted session exercising
  `(paused read)` → `(continue boundary)` → `(paused iter)` → upgrade `.so` →
  `(fixpoint)`; upgrade attempt while a *different* stratum is suspended
  refused; `addIndex` re-registration no-op (unit-level, via a doubled decl
  plugin); push idempotence.
- **Golden suite** green under `SLOG_OPT=0`, `SLOG_OPT=2`, and tiered with a
  tiny `SLOG_MAX_MS` so most tests actually exercise a swap.
- **Task-count twin check** firing (deliberately mismatched plugin → fatal).

## 10. Sprint order

1. Substrate (§7.1–7.5): ladder fix + `-rdynamic`, PCH, `-g` gate,
   `-ffp-contract=off`, parallel pool + atomic rename in tools.rkt.
   *Independent payoff: suite → ~15–20min serial, single-digit with -j.*
2. TU splitting (§6) in emit-cpp/tools.rkt. *Payoff: giant strata parallel.*
3. Tiered artifacts + driver scheduling (§2, §5 minus the upgrade branch).
   *Payoff: time-to-first-result ≈ seconds; -O2 fills the cache behind.*
4. Daemon swap seams (§4) + the poll-loop upgrade branch (§5) + tests (§9).
   *Payoff: long runs converge to -O2 speed mid-flight.*
5. `run-tests.sh` `-jN` + `SLOG_OPT=0`; re-baseline the suite time.

## 11. Expected end state (from measured numbers)

- **Fresh program, time to first tuples**: minutes → **~5–8s** (Racket ~2s +
  the largest O0 chunk; schemecfa/kcfa included).
- **Long analyses**: start at O0 speed (≈parity at small scale, plausibly
  2–5x slower on index-heavy hot loops), upgraded to full -O2 within a couple
  of minutes, automatically.
- **Re-runs of cached programs**: unchanged — pure -O2 from the cache.
- **Test suite**: 65min → **~2–4min** (`SLOG_OPT=0`, ladder+PCH, `-j8`).
- **Benchmarks**: `SLOG_OPT=2` preserves today's exact behavior.

## 12. As-shipped: measured results and post-ship refinements

Measured on the 8-core dev box:
- **Test suite: ~65min → 4m28s** (108/0), `SLOG_OPT=0` + `-j6`.
- **schemecfa cold: ~4min → ~23s** at -O0 (time to first results); 1m41s for a
  full -O2 build (8 parallel part-TUs); a warm re-run is pure -O2.
- **Plugin `.so`: ~7MB → ~160KB** (arity ladder + `-g` removed).
- Hot swap verified byte-identical end-to-end, including a LAT_EXTERN
  recursive-lattice stratum (tests/tiered-tests.sh).

**Adversarial review hardening** (five confirmed defects, all fixed): (a) a
collection-lattice swap freed the `LatSpec` tree under live payload-map buckets
— `setLattice` is now idempotent on same-spec re-registration; (b) the PCH was
keyed by header *content* but clang validates by *mtime*, so a content-identical
mtime bump wedged compiles — the PCH is rebuilt when older than any daemon
header; (c) background -O2 builds are batched into one bounded (`cores/2`)
detached driver instead of unbounded per-stratum processes; (d) `.cpp/.cprog/
.meta` are written atomically (temp+rename); (e) `ensure-slogd-exists` rebuilds
when any daemon source is newer than the binary (not only when absent), and no
longer SIGPIPEs the compile by closing its pipes early.

**DB-load overlap**: the driver launches slogd and issues `(open <db>)` *before*
`compile-strata`, so the single-threaded `loadDatabaseBIN` overlaps the front
end, codegen, and all clang builds; the `(continue)`/`(continue-boundary)`
action plugins are built lazily so a never-pausing program skips them; and the
run is wrapped so any error force-kills the daemon rather than orphaning it.
`loadDatabaseBIN` itself is still serial — parallelizing it is the next lever
for large-input-DB latency, and belongs with the runtime engine work (the index
data-structure migration), not compilation, which is now at a polished plateau.

## 13. Cached-O0 reuse, single-flight -O2, durable detach (2026-07-10)

Three incremental hardenings closing gaps in the §2 model as originally shipped.
All are **tiered-mode only** (`SLOG_OPT=0`/`2` are unchanged).

**Cached -O0 is now actually reused.** §2's artifact-selection step 2 ("`<hash>.O0.so`
exists → use it now, respawn the -O2") was implemented only for `SLOG_OPT=0`;
tiered mode always fell through to re-emit the `.cpp` and rebuild -O0 from
scratch even when a warm `<hash>.O0.so` sat in the cache. So a run that exited
before its background -O2 landed paid the full -O0 recompile next time (and
re-queued the -O2). `compile-strata` now has a tiered branch: `<hash>.O0.so`
present and `<hash>.so` absent → run the cached -O0 immediately (no re-emit, no
rebuild) and queue only the -O2. The generated `.cpp` TUs persist in `build/`
(nothing deletes them), so the -O2 command reads them back via
`stratum-tu-paths` (spine `<hash>.cpp` + parts `<hash>.pK.cpp`); a fresh emit is
the fallback if they were removed.

**Single-flight -O2 via a claim marker.** Nothing recorded that a background -O2
for a hash was already in flight, so two runs of the same program (or
`run-tests.sh -jN`) that both miss `<hash>.so` each spawned the expensive -O2 —
`temp+rename` kept them from corrupting each other, but it was Nx wasted clang.
Now a background -O2 is queued only if `try-claim-o2!` wins an atomic `O_EXCL`
create of a sidecar marker `build/<hash>.so.building`. The marker is
**deliberately a separate file** from the canonical `<hash>.so`: an empty file
at the canonical name would be `dlopen`'d by the hot swap and would satisfy the
"-O2 cached" branch — both crashes. A marker older than the reclaim window (or
unreadable) is presumed abandoned by a dead builder (crash / kill / reboot),
reclaimed, and rebuilt; the residual reclaim race only ever costs a duplicate
build, never correctness (temp+rename). The build command removes the marker on
both success and failure, and a `timeout` bounds a wedged clang so it can't hold
the slot until the marker goes stale. The reclaim window / build timeout is the
`o2_reclaim_secs` config setting (`SLOG_O2_RECLAIM_SECS`, default **900s** = 15
min, ~9x the largest observed full -O2 build).

**Durable detach.** The background batch (`spawn-detached-o2-batch`) is now
launched under `setsid` (when present) so it leads its own session — a terminal
SIGHUP after `slog` returns (closing the window) can no longer take it down, so
the -O2 builds reliably outlive the driver and land in the cache, up to their
per-build `timeout`. (The prior code relied on a Racket subprocess merely not
being killed by its parent, which does not survive a session HUP.)

## 14. Content-addressed per-cluster `.o` cache (P2, 2026-07-10)

The tiered work amortizes *re-runs* of an identical program; this makes
*iterative edits and per-config sweeps* incremental for large strata, so one big
mutually-recursive SCC no longer fully recompiles on every change. Three layers:

**Byte-reproducible codegen (the prerequisite).** For a cluster's `.o` to be
content-addressed and reused, its generated `.cpp` must be a pure function of its
rules — identical across runs. Three sources of run-to-run noise were removed:
(a) interned-constant global names are derived from the constant *value*
(`operationalization.rkt` `const-global-name`), not a gensym — they are the only
value symbols shared across TUs, so they must be stable; (b) emit-local names
(index orderings, ReadTask classes, temps) come from a per-TU monotonic counter
(`emit-cpp.rkt` `elocal`), not gensym; (c) every value reference `v_<name>` is
renamed to positional `v_c<k>` (`canonicalize-vrefs`), constants excepted. The
result is byte-identical modulo full-line `//` debug comments, which do not
affect the object and are stripped before hashing.

**Stable bucketed clusters.** A large stratum's crules are partitioned by
`sha(crule's own canonicalized text) mod N`, `N` a power-of-2 ≈ `crules/48`. This
is stable under unrelated edits: a changed rule moves only between its old and
new bucket (`N` shifts only at power-of-2 boundaries). Each cluster's function is
named `slog_rules_c<H>` where `H` hashes the cluster body, so an unchanged
cluster keeps its identity across stratum versions / configs. Each cluster
`extern`s only the constants **it** uses (not all), so editing one constant does
not perturb every cluster.

**Per-`.o` content cache + relink.** `compile-one` compiles each TU `.cpp` to a
`.o` in `build/o/`, keyed by comment-stripped content + opt + daemon-header
fingerprint; a cache hit skips clang. The `.o`s are linked into the stratum
`.so` (one `ld`, few dlopens — loading stays coarse). On an edit the stratum
`.so` cache misses (its hash changed) but most cluster `.o`s hit, so only the 1–2
touched clusters recompile and the (cheap) spine relinks. Measured: editing one
rule in a 200-rule split stratum recompiled 5 of 17 `.o`s (the edited rule's
old+new bucket + the two strata's spines); the rest were cache hits.

Applies to the eager `-O0`/foreground paths (`compile-one`); the detached
background `-O2` batch still compiles `.cpp`→`.so` directly (a follow-up could
route it through the same `.o` cache). The `build/o/` cache is not yet GC'd —
`rm -rf build/o` to reclaim; content-addressing makes stale entries inert.
