# Execution tiers: implementation decisions and prototyped mechanisms

2026-07-14. Companion to [execution-tiers.md](execution-tiers.md). Sections
1–6 are the design-phase record (decisions D1–D14, prototype results,
liftable code, change map); **section 0 tracks as-built execution status**
and is the place to resume from in a new session.

## 0. Execution status (updated 2026-07-14)

**T1 SHIPPED, working tree NOT yet committed.** The changed set:

```text
new       compiler/canonical-plan.rkt        the pass + serializer + KernelPlanKey
new       tests/unit/canonical-plan-tests.rkt  12-case battery (suite `unit` tier)
modified  compiler/ir-stack.rkt              kernel-plan? as Level 7
modified  compiler/operationalization.rkt    latchk gensym -> per-rule latchk_<n>
modified  compiler/compile.rkt               build/<hash>.plan sidecar, every flavor
```

Verified: quick tier 7/7 (unit, diag, **stats** — the exact-once audit
passing is the T1 gate that generated C++ is unchanged, arena, seq, counts,
wcoj3); 16/16 lattice goldens over the changed latchk path (`latchk_0`
confirmed in a real `.cprog`); cross-process plan-key determinism on a
3-stratum lattice program exercising the ground-value probe; 31 `.plan`
sidecars validate against `kernel-plan?`.

**Before committing:** run the full suite once (`tests/run-all.sh`) — the
new compiler source changes `compiler-sources-fingerprint`, so every cache
key misses and the first run rebuilds everything (~4.5 min tiered). No
golden refreshes are expected (generated C++ is byte-identical except
`latchk_<n>` names in ground-value-lattice strata, and goldens compare CSV
content, not C++).

**Deliberate deviation from execution-tiers.md T1.3 (recorded there too):**
`bumpFires` keeps its aggregated `(loc, base-tag)` key — emit-cpp documents
same-driver variants sharing a key as the exact-once audit's unit, and the
daemon cannot resolve RuleIds until T0's rule-meta registration.
Disaggregated RuleVariantId identity lives only in the `.plan` sidecar for
now. Also deferred: single-TU emission-order canonicalization (to T4 phase
B, with the slot rewrite), prim opcode numbering (to T2, when the daemon
dispatch table exists — plans carry a sorted prim name table).

**Next up (either order):**

- **T0** — protocol substrate: line-framed command dispatcher in
  `slogd.cpp` (dual-stack with bare-path lines), provisional builders,
  explicit entry modes (§9.1 of the main doc), catalog introspection, and
  level-0 watches (early REPL payoff; no interpreter needed).
- **T2** — the daemon interpreter: `daemon/interp.h` per §3.1/§3.2 shapes
  (validated), cursor/task factory ladders in slogd beside `makeIndex`,
  differential gates 12.1/12.2. T2 consumes the `.plan` sidecars T1 now
  writes; remember stale caches predate `.plan` — re-emit on miss.

Implementation gotchas already hit once (do not rediscover): the
`all:`/`delta:` tag prefix is dynamic-rels membership, so input-only
relations scan as `all:`; the cprog constants hash is keyed value→name;
`*_base.slog`/`*_lib.slog` files are multi-file-test helpers that fail
standalone by design — never glob them into `run-tests.sh` args.

Two working prototypes live in `/tmp/slog-tiers-proto/` (session artifacts;
the liftable parts are inlined here):

- `interp_proto.cpp` — the arity-erased cursor layer and a register-machine
  rule interpreter, compiled against the **real** daemon headers
  (`clang++ -O2 -Wall -std=c++20 -pthread -I daemon interp_proto.cpp -lgmp`,
  the same recipe as `tests/wcoj3-operator-tests.cpp`), raced against the
  exact fused loop shape `emit-cpp` generates, with differential checksums.
- `canon-proto.rkt` — the canonical KernelPlan pass run over **real** `cprog`s
  from the actual front half (the `tests/unit/wcoj3-tests.rkt` harness:
  `load-program-list` → typecheck → stratify → `plan-stratum` →
  `build-cprog`), serialized and verified byte-identical across separate
  Racket processes.

## 1. Measured results

### 1.1 Interpreter overhead (P1)

Workloads: copy rule (scan 20M rows, emit); one-level join
`edge(a,b), edge(b,c) → (a,b,c)` at fanout ~100 (~20M outputs); the same plus
a `neq` guard; a two-level join at fanout ~10 (~20M outputs). All variants
emit into identical batch vectors and must produce equal checksums (they do).

```text
variant                ms         rows   factor     ns/row
copy/native         118.0     20000000    1.00x      5.90
copy/vm             153.6     20000000    1.30x      7.68
join/native         199.1     20195961    1.00x      9.86
join/virt           192.5     20195961    0.97x      9.53
join/fnptr          220.9     20195961    1.11x     10.94
join/vm             243.3     20195961    1.22x     12.05
joinG/native        198.3     20195741    1.00x      9.82
joinG/vm            260.3     20195741    1.31x     12.89
join2/native        414.3     19986967    1.00x     20.73
join2/vm            506.4     19986967    1.22x     25.34
```

Conclusions:

1. **The full register-machine interpreter costs 1.2–1.3× native on the read
   side**, across copy, shallow, guarded, and nested join shapes.
2. **Nesting depth does not amplify overhead** (1-level 1.22×, 2-level 1.22×):
   per-row BTree work grows with depth while dispatch amortizes.
3. **Cursor erasure is free.** A virtual-dispatch pull cursor alone runs at
   parity with the fused native loop (0.97×, i.e. noise): `lower_bound` and
   node traversal dominate; one indirect call per row vanishes under them.
   The "faster" function-pointer + inline-state variant is actually *slower*
   (1.11×) and more code.
4. Since write/intern phases are shared code under either executor, **whole-
   iteration interpreted slowdown will be under these read-side factors** —
   strongly supporting interp-only defaults for everything but proven-hot
   recursive kernels.

Caveats: single-threaded, warm cache, uniform random keys, batch emit stands
in for the real `sendBatch` path (identical for both sides), no OpenMP
contention. T2 must re-verify on `bench/` harnesses; these numbers size the
thresholds, they do not replace `bench/regress.sh`.

### 1.2 Canonicalization (P2)

The pass ran over real lowered plans for (a) the recursive triangle (which
lowers to three exact-semi-naive `join3` crules), (b) a compute/prims rule,
(c) a body-constant rule. Findings:

1. **Deterministic**: serialized plans are byte-identical across separate
   Racket processes (three runs compared).
2. The walker covering the full c-op grammar (registers, relation slots,
   constant slots, prim collection) is ~90 lines (section 3.3); the plan for
   a stratum is ~1–2 KB of text at these scales.
3. Two real identity findings and several mechanical ones — section 4.

## 2. Crystallized decisions

**D1. Cursor representation: virtual dispatch, state inline.** One abstract
`PrefixCursor { open(regs), next(regs) }`; concrete `Probe<A,K>` holds the
btree iterator pair and bound key inline and writes output registers itself.
Measured at parity with fused native; no function-pointer tables, no placement
new. `Join3PrefixCursor` gains the same erasure later (same shape: it is
already a cursor).

**D2. Rule executor: register machine with explicit level stack.** Register
file of plain `u64` (16 default, sized from the plan's `nregs`); ops in a
`std::vector<Op>`; switch dispatch; probe levels push their op index onto a
level stack so backtracking and mid-nest pausing are array operations. The
complete backtracking loop is ~60 lines (section 3.1) and was validated
differentially. Deadline polling: every 128 driver tuples (the
`read_delta_sliced` cadence) plus inside long cursor loops.

**D3. VariantTag must include a version ordinal — the doc's §2.1 as written
is insufficient.** Prototyped fact: the recursive triangle lowers to *three*
crules whose driver-derived tag is identically `delta:edge`, differing only in
view assignment (full/full, old/old, full/old). Today's stat label
`(loc, "delta:edge")` deliberately *aggregates* them — fine for `$stat_fires`,
fatal for slot mapping and executor replacement. Fix: the canonical pass
numbers same-source-rule crules in canonical order and the tag becomes e.g.
`delta:edge#0..#2` (flavor kind suffixed as today). RuleVariantId uniqueness
becomes a seal-time validation error, not an assumption.

**D4. Canonical rule order: sort crules by their canonical serialization.**
Today's order is `(set->list planned-rules)` (`operationalization.rkt:134`) —
deterministic for fixed content in one Racket version, but *edit-unstable*
(any rule addition can reorder every hash bucket). Sorting by serialized
canonical text is edit-stable, which is what RuleId stability across program
edits (and golden plan files) actually needs. RuleIds are assigned in that
order.

**D5. Slot tables.** Relation slots: decls sorted canonically, slot = index
(the prototype's `(rel N ...)` table). Constant slots: **the cprog constants
hash is keyed value→global-name** (verified; not name→value) — the pass
inverts it and emits `(k slot name value)` entries sorted by name. Primitive
opcodes: two-phase — collect prim symbols during the walk, freeze a sorted
table, rewrite on a second pass (the prototype keeps names to stay readable;
the real pass emits opcodes).

**D6. Plan transport: one `write`-printed form per line over the existing
line framing.** A kernel plan serializes to a single S-expression; `write`
produces one line; the dispatcher already reads lines. No length-prefixed
framing until a measured need exists. `pretty-write` is for humans and
goldens; both `read` the same.

**D7. Probe-only interning has a rope-sized hole.** Short strings
(≤ `SEQ_BLEAF_MAX`) need only a non-allocating `InternTable` lookup beside
`intern_string` (`database.h:2552`) — straightforward. But
`encodeString` for longer content **builds rope nodes in the sequence arena**
(`database.h:2610-2616`, `seq_arena->build_bytes`), which is an allocation a
read-only query must not perform. The content-defined chunking is a pure
function of the bytes, so a `probeString` can compute would-be node keys in
scratch memory and look them up without inserting — but that is a real
`seq.h` work item. **v1 queries reject string literals longer than
`SEQ_BLEAF_MAX` with a structured error** rather than blocking on it; same
policy for collection literals pending an arena dry-run probe.

**D8. QueryContext: a second, smaller RunState-shaped context.** Owns its own
task cursor, budget/deadline, and output pages; never touches
`RunState::paused_tasks` or phase cursors. Admission: daemon idle,
`RUN_AT_BOUNDARY`, mid-read suspension, or `RUN_READ_COMPLETE` — all states
where master indices are quiescent (the read phase never mutates master).
v1 runs one query at a time on the main thread (the shipped suspend already
guarantees the worker region has exited; pausing.md §8 made the same
observation for read-only plugins).

**D9. Per-attempt fire stats become an array — and get cheaper than today.**
`bumpFires` currently locks a `std::map<pair<string,string>, u64>`
(`database.h:3942-3960`). Dense RuleVariant ordinals (D3/D4) turn this into a
plain per-attempt `std::vector<u64>` indexed by ordinal, merged into the
durable table at read commit. This simultaneously provides the
`ReadAttempt` discard semantics (drop the vector) and removes a string-keyed
map from the hot path. Do this in T1/T2, not T6 — it is a prerequisite
made cheap, not a rider.

**D10. One `installStratum(entry_mode)` replaces the beginStratum /
beginStratumDelta pair.** `fresh` performs the deferred
`reloadInsertBatches` ordering exactly as `beginStratum`
(`daemon.h:200-244`); `resident-delta` / `resident-count` perform the
positional bind with no reload exactly as `beginStratumDelta`
(`daemon.h:293-315`); the hot-swap twin-registration path becomes an explicit
`upgrade` attachment rather than a name-match side effect. Validation refuses
tier swaps/restarts against `resident-count` (execution-tiers.md §9.1).

**D11. Interpreter task integration.** `InterpReadTask : Task`, one instance
per (rule variant, bucket), constructed at plan install; owns its VM,
register file, and bound cursor table; `bind()` resolves `Relation*`/index
pointers exactly where native tasks do it today. Parking reuses
`pushPaused`/`paused_tasks` unchanged: a parked interpreter continuation
carries live btree iterators, which is safe for exactly the same reason the
native `(rt, ri)` park is safe — indices are immutable until the finalize
that a suspension skips — and must be discarded at any finalize, which the
existing copy-for-resume ownership rule already enforces.

**D12. Adapter/factory ladders live in the daemon, once.** The precedent is
already shipped and measured: moving the `makeIndex` arity ladder out-of-line
into slogd cut a median stratum's clang -O2 from ~10s to ~4.6s
(`index.h:244-250`, fast-compile.md §7.1). The cursor factories (per (A,K)),
task factories (write/intern/lattice/count per arity), and prim tables follow
the same pattern: instantiated once in `slogd.cpp`, reached through the
daemon's exported symbols.

**D13. Head sinks erase the existing emit family.** The interpreter calls the
same `emit`/`emit_temp`/`emit_struct`/`emit_lat` templates
(`operators.h:520-616`) through a bound sink table built like the cursors —
no second emit implementation, so send-shard formatting, error structs, and
struct-id placeholder behavior are shared by construction.

**D14. VM ops carry pre-resolved operands, not names.** Bound at install:
cursor index, register numbers, constant slot values already materialized
into a constant register bank at frame setup (so `(pre (let r k))` becomes a
register preload executed once per task, not per tuple).

## 3. Liftable code

### 3.1 The VM inner loop (validated shape for `daemon/interp.h`)

```cpp
enum class OpK : u8 { probe, guard_neq, /*...,*/ emit };
struct Op { OpK k; u8 cursor; u16 a, b, c; };

// One driver tuple through the rule body: nested-loop backtracking over an
// explicit stack of open cursor levels. level_ip[d] = op index of level d.
inline void run_driver_tuple(Batch& out)
{
  int level_ip[8]; int depth = 0; size_t ip = 0;
  for (;;)
  {
    if (ip == ops.size())                      // one full instantiation done
    {
      if (depth == 0) return;
      ip = level_ip[depth - 1]; goto advance;  // resume deepest level
    }
    switch (ops[ip].k)
    {
      case OpK::probe:
      {
        PrefixCursor& cur = *cursors[ops[ip].cursor];
        if (cur.open(regs) && cur.next(regs)) { level_ip[depth++] = ip; ++ip; continue; }
        if (depth == 0) return;                // empty probe: backtrack
        ip = level_ip[depth - 1]; goto advance;
      }
      case OpK::guard_neq:
        if (regs[ops[ip].a] != regs[ops[ip].b]) { ++ip; continue; }
        if (depth == 0) return;
        ip = level_ip[depth - 1]; goto advance;
      case OpK::emit: /* bound sink */ ++ip; continue;
    }
  advance:
    for (;;)                                   // advance deepest open cursor
    {
      PrefixCursor& cur = *cursors[ops[ip].cursor];
      if (cur.next(regs)) { ++ip; break; }
      if (--depth == 0) return;
      ip = level_ip[depth - 1];
    }
  }
}
```

Pausing mid-nest = park (`ip`, `depth`, `level_ip[]`, cursors, regs) — all
plain state, no C++ stack capture. `letp` failure and `tycheck` failure are
the `guard` arm's backtrack (row abandon); `absent` is a probe arm that
*fails* on `open()` success.

### 3.2 The cursor (validated shape)

```cpp
struct PrefixCursor
{
  virtual ~PrefixCursor() = default;
  virtual bool open(u64* regs) = 0;   // build key from key-regs, lower_bound
  virtual bool next(u64* regs) = 0;   // prefix-check, write out-regs, advance
};

template <u16 A, u16 K>
struct Probe final : PrefixCursor
{
  Index** index; u16 keyreg[K]; u16 outreg[A - K];
  typename BTreeIndex<A>::iterator it, end;
  std::array<u64, A> key{};
  bool open(u64* regs) override
  {
    for (u16 i = 0; i < K; ++i) key[i] = regs[keyreg[i]];
    for (u16 i = K; i < A; ++i) key[i] = 0;
    auto* idx = static_cast<BTreeIndex<A>*>(index[buckethash(key[0])]);
    it = idx->lower_bound(key); end = idx->end();
    return it != end;
  }
  bool next(u64* regs) override
  {
    while (it != end)
    {
      const std::array<u64, A>& m = *it;
      for (u16 c = 0; c < K; ++c) if (m[c] != key[c]) return false;
      for (u16 i = K; i < A; ++i) regs[outreg[i - K]] = m[i];
      ++it; return true;
    }
    return false;
  }
};
```

Variants needed beyond `Probe<A,K>`: full-scan (K=0 all-bucket, for `scan-full`
and K=0 negation), delta-scan driver (wrapping `getReadBucket` RefVecs),
old/new exclusion probes (the `join-old`/`join-new` dord logic),
map-index probe (`BTreeMapIndex<KA>`, binds payload last), absence probes
(open-only), and the `Join3PrefixCursor` erasure. All are `(A, K)`-laddered
factories in slogd (D12).

### 3.3 The canonicalization walker (validated shape for
`compiler/canonical-plan.rkt`)

The essential move — one `reg!` resolver distinguishing constants from
variables, one clause per c-op form:

```racket
(define regs (make-hash))
(define (reg! v)
  (cond [(const-slot v) => (lambda (k) `(k ,k))]
        [else `(r ,(hash-ref! regs v (lambda () (hash-count regs))))]))
(define (op->canon op)
  (match op
    [`(join ,rel ,ord ,K ,xs ...) `(join ,(rel! rel) ,ord ,K ,@(map reg! xs))]
    [`(join3 ,cycle ,arms ...)
     `(join3 ,(reg! cycle)
             ,@(for/list ([arm arms])
                 (match-define `(,view ,rel ,ord ,K ,dind ,ys ...) arm)
                 `(,view ,(rel! rel) ,ord ,K ,dind ,@(map reg! ys))))]
    [`(let ,x (,f ,ys ...)) `(let ,(reg! x) (prim ,(prim! f) ,@(map reg! ys)))]
    ;; ... one clause per remaining c-op/hop/driver form (grammar:
    ;; ir-stack.rkt:239-441); the prototype covers all of them in ~90 lines
    ))
```

First-use order is: `pre` ops, driver, body, head — note that `pre` runs
*before* the driver (constants load there for probe drivers), so registers 0..
are not necessarily the driver's columns.

### 3.4 A real serialized plan (prototype output, recursive triangle)

```text
(kernel-plan
 (stratum 0)
 (relations
  (rel 0 (relation edge 2 (0 1) (1 0) (delta 0 1) (delta 1 0)))
  (rel 1 (relation error 1 (0)))
  (rel 5 (struct malformed_deduction 5 (1 2 3 4 0) (0 1 2 3 4)))
  ...)                     ; every stratum also declares the error structs
 (constants) (prims) (dynamic edge)
 (rules
  (rule-def (id 0)
   (variant delta:edge (nregs 3) (pre)
    (driver (scan (rel 0) (r 0) (r 1)))
    (body (join3 (r 2) (full (rel 0) (0 1) 1 () (r 0) (r 2))
                        (full (rel 0) (0 1) 1 () (r 1) (r 2))))
    (head (emit (rel 0) (0 1) (r 2) (r 0)))))
  (rule-def (id 1)
   (variant delta:edge (nregs 3) (pre)   ; <-- SAME tag: needs #ordinal (D3)
    (driver (scan (rel 0) (r 0) (r 1)))
    (body (join3 (r 2) (old (rel 0) (1 0) 1 (1 0) (r 1) (r 2))
                        (old (rel 0) (0 1) 1 (0 1) (r 0) (r 2))))
    (head (emit (rel 0) (0 1) (r 1) (r 0)))))
  ...))
```

Body-constant rules produce exactly the doc's `pre` shape:
`(pre (let (r 0) (k 0))) (driver (probe (rel 0) (1 0) 1 (r 0) (r 1)))`.

## 4. Nonobvious findings to carry into the refactor

1. **VariantTag collision** (D3): same-source-rule semi-naive versions share
   the driver tag; identity needs the ordinal. Corollary: today's exact-once
   fires audit *aggregates* those versions per `(loc, label)`; the cross-tier
   instantiation-multiset gate must compare at the disaggregated
   RuleVariantId level, then aggregate for the existing goldens.
2. **The constants hash is keyed value→name**, not name→value
   (`globalize-constants`); the canonical pass inverts it. Constant globals
   are already content-derived symbols, so slot values are stable.
3. **Every stratum's decl list includes the side-channel error structs**
   (`error`, `malformed_deduction`, `div_by_zero`, ...). Binding frames
   therefore always contain those slots, and the two-class side-channel
   doctrine (incremental.md) shows up in every plan — the plan validator
   should treat them as a fixed prelude rather than per-program surprise.
4. **Rope strings break naive probe-only interning** (D7): long-string
   literals in queries need an arena dry-run probe or a v1 rejection.
5. **Parked interpreter continuations hold live btree iterators** — safe
   across mid-read suspension for the same reason native `(rt,ri)` parks are
   safe, invalid after any finalize; the existing copy-for-resume ownership
   rule covers this with no new mechanism (D11).
6. **Source-location strings must be module-relative** in `rule-meta`: the
   prototype's temp-file paths leaked into the plan and broke cross-run
   diffs until normalized. Golden plan files require repo-relative paths
   (RuleKey construction should never embed absolute paths).
7. **`pre` ops run before the driver** — a VM that assumes "driver binds
   regs 0..n first" mis-executes probe-driver rules (D14 removes the trap by
   preloading constants at frame setup).
8. **The `(paused ...)`/`(fixpoint ...)` message contract is load-bearing**:
   `runslog.rkt`'s driver loop and `tests/pause-tests.sh` parse the exact
   8-field shape (`daemon.h:1120-1132`). Protocol work must keep those
   replies byte-compatible until the driver migrates (dual-stack).
9. **Edit-stability, not run-stability, is the real canonicalization
   requirement** (D4): `set->list` order is already reproducible for
   identical input on one Racket build; what it lacks is stability under
   program *edits*, which is what durable RuleIds and plan goldens need.

## 5. File-by-file change map

Compiler (all under `compiler/`):

- **NEW `canonical-plan.rkt`** — the T1 pass: canonical crule sort, RuleId/
  VariantTag(+ordinal) assignment, register/slot allocation, deterministic
  serializer, plan goldens support. Prototype: `canon-proto.rkt`.
- **`ir-stack.rkt`** — add the kernel-plan grammar predicates beside the
  cprog ones (`ir-stack.rkt:239-441` is the source grammar the walker
  mirrors); no changes to existing levels.
- **`operationalization.rkt`** — intern the one residual `gensymb`
  (`latchk`, `operationalization.rkt:954`) deterministically; otherwise
  untouched (the pass consumes its output).
- **`compile.rkt`** — invoke the canonical pass per job after `build-cprog`;
  write/streams plans; the tier-designation classifier (§5.3 defaults) and
  tier-profile sidecar read/write; retire the text-hash manifest
  (`compile.rkt:210-234`) once RuleIds flow.
- **`emit-cpp.rkt`** — phase A (with T1): consume RuleId/VariantTag for
  `bumpFires` keys (`emit-cpp.rkt:912-922`) while still walking crules;
  phase B (with T4): consume the canonical plan's slots (relation strings
  out of generated code, `emit-cpp.rkt:201-408` and the `readrel` block
  `emit-cpp.rkt:1305-1322`); shard bucketing moves from emitted-text hash
  (`emit-cpp.rkt:1415-1432`) to canonical-variant hash.
- **`runslog.rkt` / `actions.rkt` / `session.rkt`** — dual-stack driver:
  send plan installs before artifacts; retire compiled action verbs one at a
  time against protocol equivalents; keep the `(paused ...)` parse compatible
  throughout (finding 8).

Daemon (all under `daemon/`):

- **`slogd.cpp`** — dispatcher: lines beginning `(` route to the command
  parser; bare lines stay plugin paths (`slogd.cpp:144-157` and the TCP twin);
  the pre-instantiated cursor/task factory ladders live here beside
  `makeIndex` (D12).
- **NEW `plan.h`** — S-expression plan parser, seal-time validation
  (slot/ABI/coverage/capability/entry-mode), the provisional builders.
- **NEW `interp.h`** — `PrefixCursor` family, `InterpReadTask`, the VM
  (section 3.1/3.2), bound sink tables (D13).
- **NEW `query.h`** — `QueryContext`, `scan-full` driver, `yield` pagination,
  probe-only intern entry points' consumer (D7/D8).
- **`daemon.h`** — `installStratum(entry_mode)` unifying
  `beginStratum`/`beginStratumDelta`/upgrade (`daemon.h:200-315`, D10);
  attachment/load verbs; PauseToken/UpdateEpoch unification.
- **`database.h`** — `RUN_READ_COMPLETE` in the position enum
  (`database.h:1977-1981`) and the `ReadCompletion` gate branch
  (`database.h:6003-6024`); per-attempt fire vectors replacing the
  string-keyed map (`database.h:3942-3960`, D9); probe-only
  `probeString`/collection lookups beside `intern_string`/`encodeString`
  (`database.h:2552, 2610`).
- **`operators.h`** — unchanged semantics; the cursor layer wraps the same
  probe logic (`join_probe` `operators.h:97`, `Join3PrefixCursor`
  `operators.h:117`); head sinks reused as-is (`operators.h:520-616`).

Tests:

- `tests/unit/` canonical-plan battery: determinism (two-process diff), plan
  goldens for representative programs, VariantTag-ordinal uniqueness.
- C++ interpreter operator tests following the `wcoj3-operator-tests.cpp`
  pattern (standalone build, differential vs a logical model), plus the
  prototype's native-vs-VM differential as a permanent fixture.
- The `SLOG_OPT=interp` full-suite run (execution-tiers.md gate 12.3) and the
  disaggregated fires comparison (gate 12.2, finding 1).

## 6. Threshold hypotheses for the tier policy (to verify in T2/T3)

From section 1.1, pending `bench/` validation:

- interp-only defaults are safe wherever read cost ≤ ~1.3× matters less than
  seconds of clang — i.e. everything in §5.3's default list, with margin;
- promotion: compile when projected remaining interpreted time for the SCC
  exceeds ~3× the estimated O0 build cost (estimate from cluster count ×
  measured per-cluster O0 cost, both already tracked by the build cache);
- demotion: a kernel whose profile shows fixpoint reached before O0 would
  have attached in each of the last N sessions skips compilation.
