# Slog roadmap (live)

This file indexes what is OPEN, stream by stream, plus the audited
open-work ledger and the parked list.  Each stream's own document remains
normative for content; this file only points.  The fork-era coordination
roadmap (2026-07-14 → 2026-08-15: trunk, thread fork, sync gate, W4′/W5′)
is frozen verbatim at [history/roadmap-fork-era.md](history/roadmap-fork-era.md).

Last full-consistency audit: 2026-09-05/07 (five-auditor sweep; the ledger
below is its consolidation, updated through the index-reuse arc).

## Streams

| stream | authority | status 2026-09-07 |
|---|---|---|
| incremental / DRed^c | [incremental.md](incremental.md), [incremental-status.md](incremental-status.md) | **M-spine complete** (Phase 0, M0–M7 incl. counted-interp); oracle-answer §8B.4 enforcement shipped 09-06 (smt.md §16) |
| execution tiers / runtime | [execution-tiers.md](execution-tiers.md), t0/t3b/t4/t5/t6-contracts | **T0–T6 + Q1 complete**; residues live in each contract's ledger |
| join planning | [join-planning-assessment.md](join-planning-assessment.md), [static-join-decomposition.md](static-join-decomposition.md), [wcoj.md](wcoj.md) | **runtime-selection arc complete 08-24** (V0–V4, J1–J3, join3 arms); S1–S3 shipped; the static SHAPE cliff stands |
| index reuse | [index-reuse.md](index-reuse.md) | **P1+P2 shipped 09-07** (boundary keep-set; ~1.7× fixpoint on boundary-bound pipelines); P3 measure-gated, P4 parked |
| reflection | [slog-reflection.md](slog-reflection.md), [rf5-contract.md](rf5-contract.md), [activation-contract.md](activation-contract.md) | RF0–RF5-B complete + deep-vetted (08-14); **RF5-C precise healing and RF5-D historical replacement open** |
| modules / namespaces | [modules.md](modules.md), [n4-contract.md](n4-contract.md) | N0–N4 complete; N5 item 1 shipped scoped, item 3 substantially shipped; **items 2 + 4 open** |
| REPL | [repl-ux.md](repl-ux.md) (living), [repl.md](repl.md), [repl-terminal.md](repl-terminal.md) | R0–R5 spine + W4′ debugger complete; handle economy, history verbs, R4 client half open; Ctrl-C pause doctrine unbuilt |
| stats | [stats.md](stats.md) | `$stat_*` + `$stat_work` + RuleKey `(fires)` shipped; **target-model migration open** (rides the stat-rekey train) |
| SMT / oracles | [smt.md](smt.md) | Phases 1–2c + §16 session enforcement complete; theories, `--refresh-oracle`, pinned-only replay import open |
| compression / merge | [db-compression.md](db-compression.md), [db-merge.md](db-merge.md) | P0–P3 shipped; **offline merge verb (P2) never built**; §19 accel gaps |
| type system | [type-system.md](type-system.md), [type-errors.md](type-errors.md) | errors v1 shipped; **stages 0–4 entirely unstarted** (the plan remains valid) |

## The open-work ledger

**Identity / stats (the rekey train).**  The (RuleId,VariantTag) stat
rekey is a sanctioned golden-changing event with queued consumers:
mixed-executor per-key fires (t6), per-attempt stats records, the
source-loc column fix (two rules on one line collide), and META's
plan-shaping env list (dbmeta).  Stats steps 5–7 + `$stat_*`/`$seq_*`
namespace migration (N5) ride with it or after.

**Reflection / activation.**  RF5-C capability-by-capability healing;
RF5-D descendant-branch replacement; sever-closure widening to the
resident∪candidate union; `retire` disposition (refuses today); §11 open
decisions (preview dry-run vs diff, retirement syntax); activation
residues (candidate sources under out/, recount-at before a severing
boundary walks empty instead of refusing typed).

**Join track.**  Flavored arms (needs the deletion-cone skew bench) and
seeded-rule arms are the next arc; parked: byte-aware index budgets, lazy
declare-then-materialize lifecycle, probe hysteresis, cross-run
advisories, K>2 re-trips, probe-driver/static-variant native rescue.
Static: fragment shapes beyond binary-triangle, size-gated factoring,
factoring-strips-semijoin cost modeling, the shape cliff itself
(lattice/struct/temp occurrences, payload columns, 3+ arms).

**Index reuse.**  P3 compiler ordering alignment — decide from
`SLOG_BOUNDARY_DEBUG=1` kept/rebuilt splits on real workloads (plan-byte
re-key if taken).  P4 virtual iteration-0 delta.  Struct/lattice
keep-mode after the id-keyed-intern/M5-tombstone and payload-map audits.

**Incremental.**  join-pre XOR view + derived×recursive readers (M4N
unlocks); per-derivation rank folds; negation×lattices fallback; M7
refresh scoping; non-selective joins × recursive repair (7A.2);
truncated retention (aggregate-retention.md); M6A aggregates.

**Tiers / daemon.**  Counted-sidecar preview/apply (lifts the monotone
watch restriction); whole-fixpoint why-not; daemon `-t` in the core
budget; per-SCC plan streaming; small-kernel `.so` re-merge (cold-compile
lever); re-entry profile observations; greedy-packer subset-chain
re-pack + lattice-master re-homing (also P3's substrate).

**REPL.**  dbN/@vN/@tN handle economy; history/time verbs; `inject` +
anchored stage; unsolicited server events; R4 proof-tree canvas + whynot
chase; `frames` source variable names (needs the rule-meta register map —
plan-byte, rides the rekey); Rust query-canvas adapters; relation
fast-path dump; extended-layer clear recipe; Ctrl-C stage 1 (busy guard)
then stage 2 (control channel — the genuinely missing piece).

**SMT / compression / merge.**  Theories (reals/BV/arrays/UF),
quantifiers, verdict lattices; `--refresh-oracle` (designed, never
built); `db verify --replay` pinned-only import; offline `merge-db` verb
+ scratch-then-swap online import; content-addressed struct ids;
DRed^c-accelerated replay; accel §19 gaps; `--bias` retirement decision.

**Types / demand / sequences / lattices.**  Type stages 0–4; demand typed
lambdas, zero-answer judgments, exhaustiveness; sequences lbuild c-op,
fan-out enumerator, per-τ occurrence tables, cross-save segment sharing
(unverified whether picked up); lattices L2/L3 (`ps`/interval/lift2,
registerLattice), the uncalled leq_spec audit; primitives M2.5 `(ps E)`.

**Testing / infra.**  N4 daemon fault injection (corrupt-nested-value,
exhausted-SID proven only at unit level); csv2db coverage; XFAIL
generality beyond card-study; loadDatabaseBIN still serial; oracle
action-plugin build at scale.

## Parked — do not start

Portable cursor handoff (tiers §8.3); whole-fixpoint why-not as a
default-on feature; counted-sidecar preview/apply (post-M7, if ever);
direct plan editing; the automatic outer meta-fixpoint; self-hosted
compiler passes; session branching/fork; module type parameters;
privacy/export lists; lifecycle monitors.  Each is recorded in its stream
document; none blocks anything above.
