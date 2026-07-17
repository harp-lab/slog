/** Slog Interpreter Core (T2-A1)
 *
 * The production-neutral decoded-rule interpreter: immutable decoded
 * programs, tri-state pausable prefix cursors, a five-state register-machine
 * VM with an explicit level stack, mask-gated post-transition observation,
 * and attempt-local candidate/fire ownership.
 *
 * docs/interp-core-contract.md is the governing contract (freeze list,
 * extension seams, reservation ranges); docs/execution-tiers-impl.md D1-D18
 * records the ratified decisions; tests/interp-operator-tests.cpp is the
 * authoritative executable specification and instantiates exactly this core.
 *
 * Scope (deliberate): this header integrates NO Task/scheduler, protocol
 * parsing, SCC policy, or hot-swap machinery (contract non-goals).  Seal and
 * bind live in daemon/plan.h at T2-A2; the cursor/sink factory ladders live
 * out-of-line in plan.cpp beside the shared runtime factories (D12).  The only daemon
 * coupling is the storage layer the cursors probe (database.h/index.h).
 *
 * Frozen properties honored here (see the contract for fixture citations):
 *   - CursorResult { match | exhausted | paused }: tri-state next (D1); a
 *     pause is returned BEFORE output registers are written.
 *   - Positioned-until-next-call: a match stays positioned on the underlying
 *     iterator until the following next() advances it, so observation reads
 *     the current premise lazily with no copy on the unobserved path.
 *   - Ops carry pre-resolved operands, never names; constants preload into
 *     the register file once at frame setup (D14).  `pre` ops run before the
 *     driver, so driver columns map through Program::driver_regs.
 *   - Plan-sized register file and growable level stack (real plans reach
 *     85 levels / 251 registers); backtracking is an array operation.
 *   - A cursor pause commits nothing; every committed semantic transition
 *     completes before any debug stop (post-transition breakpoints, D15).
 *   - Every emit op carries an explicit bound sink port and every
 *     attempt-local candidate retains it (D13); head selection is never
 *     reconstructed from candidate order.
 *   - Ordinary execution and rich observation are separately compiled loops;
 *     a zero effective event mask selects the fast loop (impl section 1.3).
 *   - A parked continuation pins the immutable decoded program generation
 *     (shared_ptr<const Program>) and clones registers, levels, and cursors
 *     with live iterator state (D11).  Parked cursors hold live btree
 *     iterators: valid across mid-read suspension, discarded at any finalize
 *     (the existing copy-for-resume ownership rule).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

// The daemon's umbrella header (its headers must be entered through it --
// database.h/oracle.h have an include-order dependency on slogd.h).  What the
// core actually consumes is only the storage layer: BTreeIndex/Index and the
// bucket hash (index.h/database.h).
#include "slogd.h"

#include <algorithm>
#include <array>
#include <cstdlib>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace slog
{
namespace interp
{

// ---------------------------------------------------------------------------
// Opcode-space reservation (interp-core-contract.md, "Opcode and
// registration-table reservations").  Three disjoint contiguous ranges so
// thread-0/thread-1 registrations can never collide with the frozen core:
//
//   core monotone      [0, 96)     frozen at the trigger; joint review after
//   thread 0 flavored  [96, 160)   counted/maintenance ops (EMPTY this slice)
//   thread 1 query     [160, 192)  scan-full / yield / probe-only (EMPTY)
//
// The same three-region doctrine applies to the cursor-factory and
// sink-factory registration tables implemented out of line at T2-A2
// (D12): core region frozen, each thread registering only in its own range;
// a registration outside one's own range, or a collision, is an install-time
// fatal, never a silent overwrite.

inline constexpr u16 opk_core_begin = 0;
inline constexpr u16 opk_core_end = 96;
inline constexpr u16 opk_flavored_begin = 96;   // thread 0: counted/maintenance
inline constexpr u16 opk_flavored_end = 160;
inline constexpr u16 opk_query_begin = 160;     // thread 1: read-only queries
inline constexpr u16 opk_query_end = 192;

static_assert(opk_core_begin < opk_core_end
                && opk_core_end == opk_flavored_begin
                && opk_flavored_begin < opk_flavored_end
                && opk_flavored_end == opk_query_begin
                && opk_query_begin < opk_query_end
                && opk_query_end <= 256,
              "opcode reservation ranges must be disjoint, contiguous, and u8-sized");

// The core monotone vocabulary.  Numeric values live in the core range; they
// are NOT themselves frozen (contract: "the numeric values of OpK members are
// not frozen -- see the reservation section").  Thread-0 flavored ops and
// thread-1 query ops arrive as new enumerators (or sibling enums) numbered
// from opk_flavored_begin / opk_query_begin respectively.
enum class OpK : u8
{
  probe = opk_core_begin, // open cursor Op::cursor over the current registers
  guard_neq,              // abandon the row unless regs[a] != regs[b]
  guard_eq,               // abandon the row unless regs[a] == regs[b]
  copy,                   // regs[a] = regs[b]
  prim,                   // total primitive: regs[a] = prim(operands[b..])
  prim_partial,           // partial primitive; false abandons the row
  guard_cmp,              // primitive-backed truth guard
  tycheck,                // accepted-tag guard with failure effect sink
  fire,                   // one instantiation counter per satisfying body
  emit2,                  // arity-2 candidate to bound sink port Op::cursor
  emit3,                  // arity-3 candidate to bound sink port Op::cursor
  emitn,                  // operand-bank candidate (all other daemon arities)
};

inline constexpr u16 opk_core_used = static_cast<u16>(OpK::emitn) + 1;
static_assert(opk_core_used <= opk_core_end,
              "core opcodes overflow the reserved core range");

// Fixed small-struct op in a flat vector, switch-dispatched (D14).  Operands
// are pre-resolved at decode/bind time: `cursor` is a bound cursor index for
// probes and a bound SINK PORT for emits (D13).  emit2/emit3 carry register
// numbers in a/b/c.  emitn carries (operand-bank offset, width) in (a,b), so
// the production path covers the daemon's full arity range without inflating
// every Op to max_daemon_arity words.
struct Op
{
  OpK kind;
  u16 cursor = 0;
  u16 a = 0, b = 0, c = 0;
};

using PrimInvoke = u64 (*)(Database*, const u64*, bool*);

struct BoundPrim
{
  PrimInvoke invoke = nullptr;
  u16 arity = 0;
  bool partial = false;
  bool comparison = false;
};

inline constexpr u32 type_accept_int = 1u << 0;
inline constexpr u32 type_accept_float = 1u << 1;
inline constexpr u32 type_accept_str = 1u << 2;
inline constexpr u32 type_accept_cnode = 1u << 3;
inline constexpr u32 type_accept_seq = 1u << 4;

struct BoundTycheck
{
  u32 primitive_mask = 0;
  std::vector<u32> struct_ids;

  bool accepts(u64 value) const
  {
    if ((primitive_mask & type_accept_int) && is_int(value)) return true;
    if ((primitive_mask & type_accept_float) && is_float(value)) return true;
    if ((primitive_mask & type_accept_str) && is_str(value)) return true;
    if ((primitive_mask & type_accept_cnode) && is_cnode(value)) return true;
    if ((primitive_mask & type_accept_seq) && is_seq(value)) return true;
    return is_struct(value)
        && std::find(struct_ids.begin(), struct_ids.end(),
                     static_cast<u32>(decode_struct_id(value)))
             != struct_ids.end();
  }
};

// ---------------------------------------------------------------------------
// Non-owning bounded tuple view (impl section 3.2; contract lift obligation
// 2/3).  Used for the cursor's current-match accessor and for Event payloads.
// A TupleView never owns storage: the producer documents its lifetime at each
// use site (positioned-until-next-call for cursors; observer-callback
// duration for events).
struct TupleView
{
  const u64* values = nullptr;
  u16 arity = 0;

  constexpr u16 size() const { return arity; }
  constexpr bool empty() const { return arity == 0; }
  constexpr const u64* begin() const { return values; }
  constexpr const u64* end() const { return values + arity; }
  constexpr u64 operator[](u16 i) const { return values[i]; }
};

// Tri-state cursor pull result (D1).  A boolean is insufficient: a join3
// intersection can exhaust a work slice before either finding a match or
// proving exhaustion.
enum class CursorResult : u8 { match, exhausted, paused };

// Counted work budget.  Cursors consume ticks inside their search loops and
// return `paused` on expiry.  Correctness holds at EVERY budget (the fixture
// proves quanta 1..31); the production deadline cadence (D2: poll every 128
// driver tuples plus inside long cursor loops) is a performance choice
// inside this correctness-guaranteed family, not a semantic constant.
struct WorkBudget
{
  u64 left;
  bool tick()
  {
    if (left == 0) return false;
    --left;
    return true;
  }
};

// The frozen cursor interface.  clone() copies live iterator state (parked
// continuations depend on it); open() builds the key from the registers and
// positions the underlying search; next() is the tri-state pull; current()
// is the non-owning view of the current match -- valid only while the cursor
// is positioned (i.e. until the following next()/open() call), returning an
// empty view when unpositioned. premise_count()/premise() expose the physical
// proof rows represented by that logical match (one by default, two for
// join3). Debug capture reads them lazily, so the unobserved path never copies
// a premise. Seek/leapfrog operations deliberately remain private cursor
// implementation details rather than part of this general pull interface.
struct PrefixCursor
{
  virtual ~PrefixCursor() = default;
  virtual std::unique_ptr<PrefixCursor> clone() const = 0;
  virtual void open(const u64* regs) = 0;
  virtual CursorResult next(u64* regs, WorkBudget& budget) = 0;
  virtual TupleView current() const = 0;

  // Most cursor levels represent one logical premise. A join3 intersection
  // represents two simultaneously positioned premises; these defaults keep
  // every ordinary cursor source-compatible while allowing proof capture to
  // retain both arms without exposing seek/advance on the public interface.
  virtual u16 premise_count() const { return current().empty() ? 0 : 1; }
  virtual TupleView premise(u16 index) const
  {
    return index == 0 ? current() : TupleView{};
  }
};

// Production probe cursor: arity remains a compile-time storage fact, while
// the bound-prefix width is decoded data.  This gives complete (A,K)
// capability for every 0 <= K <= A with one instantiation per supported
// arity rather than a quadratic template ladder.  Seal still validates the
// exact (operator,A,K,view) capability before a worker can see the plan.
// K=0 walks every hash bucket and is the ordinary cartesian/body-full-scan
// path; K>0 retains the single-bucket prefix probe.
template <u16 A>
struct DynamicProbeCursor final : PrefixCursor
{
  Index** index;
  std::vector<u16> keyreg;
  std::vector<u16> outreg;
  typename BTreeIndex<A>::iterator it, end;
  std::array<u64, A> key{};
  u16 first_bucket = 0, last_bucket = 0, bucket = 0;
  bool positioned = false;

  void open_bucket()
  {
    auto* tree = static_cast<BTreeIndex<A>*>(index[bucket]);
    it = keyreg.empty() ? tree->begin() : tree->lower_bound(key);
    end = tree->end();
  }

  DynamicProbeCursor(Index** i, std::vector<u16> key_regs,
                     std::vector<u16> out_regs)
    : index(i), keyreg(std::move(key_regs)), outreg(std::move(out_regs)) {}

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<DynamicProbeCursor>(*this);
  }

  void open(const u64* regs) override
  {
    const u16 k = static_cast<u16>(keyreg.size());
    for (u16 i = 0; i < k; ++i) key[i] = regs[keyreg[i]];
    for (u16 i = k; i < A; ++i) key[i] = 0;
    first_bucket = k == 0 ? 0 : buckethash(key[0]);
    last_bucket = k == 0 ? bucket_count : first_bucket + 1;
    bucket = first_bucket;
    open_bucket();
    positioned = false;
  }

  CursorResult next(u64* regs, WorkBudget& budget) override
  {
    if (positioned)
    {
      ++it;
      positioned = false;
    }
    while (it == end)
    {
      ++bucket;
      if (bucket == last_bucket) return CursorResult::exhausted;
      open_bucket();
    }
    const u16 k = static_cast<u16>(keyreg.size());
    for (u16 c = 0; c < k; ++c)
      if ((*it)[c] != key[c]) return CursorResult::exhausted;
    if (!budget.tick()) return CursorResult::paused;
    for (u16 i = k; i < A; ++i) regs[outreg[i - k]] = (*it)[i];
    positioned = true;
    return CursorResult::match;
  }

  TupleView current() const override
  {
    return positioned ? TupleView{it->data(), A} : TupleView{};
  }
};

// Erased outer-driver cursor.  Unlike body cursors, advancing a driver is one
// semantic transition; the scheduler polls time every fixed number of VM
// transitions, while expensive body cursors retain the tri-state work budget.
// clone() preserves the exact live scan/probe position for a continuation.
struct DriverCursor
{
  virtual ~DriverCursor() = default;
  virtual std::unique_ptr<DriverCursor> clone() const = 0;
  virtual bool next(std::vector<u64>& row) = 0;
};

// Compatibility/test driver over immutable materialized rows.  Production
// binding supplies storage-backed cursors from plan.cpp, so no driver relation
// is copied into vector<vector<u64>> on the hot path.
struct VectorDriverCursor final : DriverCursor
{
  std::shared_ptr<const std::vector<std::vector<u64>>> rows;
  size_t next_row = 0;

  explicit VectorDriverCursor(
    std::shared_ptr<const std::vector<std::vector<u64>>> r)
    : rows(std::move(r)) {}

  std::unique_ptr<DriverCursor> clone() const override
  {
    return std::make_unique<VectorDriverCursor>(*this);
  }

  bool next(std::vector<u64>& row) override
  {
    if (next_row == rows->size()) return false;
    row = (*rows)[next_row++];
    return true;
  }
};

// Real daemon BTreeIndex prefix probe.  The iterator remains ON the current
// match; the following next() advances first (positioned-until-next-call).
// A pause is returned BEFORE the output registers are written: a paused
// cursor has committed nothing.
//
// Further (A, K) variants arrive as T2-B cursor-factory registrations
// (contract: extension seams). Old/new dord exclusion, existence/absence,
// and the real Join3PrefixCursor erasure live out-of-line in plan.cpp;
// production uses DynamicProbeCursor above for full-view K=0..A, while this
// fixed-K template remains a narrow compatibility/test implementation.
template <u16 A, u16 K>
struct ProbeCursor final : PrefixCursor
{
  Index** index;
  std::array<u16, K> keyreg;
  std::array<u16, A - K> outreg;
  typename BTreeIndex<A>::iterator it, end;
  std::array<u64, A> key{};
  bool positioned = false;

  ProbeCursor(Index** i, std::array<u16, K> kr, std::array<u16, A - K> out)
    : index(i), keyreg(kr), outreg(out) {}

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<ProbeCursor>(*this);
  }

  void open(const u64* regs) override
  {
    for (u16 i = 0; i < K; ++i) key[i] = regs[keyreg[i]];
    for (u16 i = K; i < A; ++i) key[i] = 0;
    auto* tree = static_cast<BTreeIndex<A>*>(index[buckethash(key[0])]);
    it = tree->lower_bound(key);
    end = tree->end();
    positioned = false;
  }

  CursorResult next(u64* regs, WorkBudget& budget) override
  {
    if (positioned)
    {
      ++it;
      positioned = false;
    }
    if (it == end) return CursorResult::exhausted;
    for (u16 c = 0; c < K; ++c)
      if ((*it)[c] != key[c]) return CursorResult::exhausted;
    if (!budget.tick()) return CursorResult::paused;
    for (u16 i = K; i < A; ++i) regs[outreg[i - K]] = (*it)[i];
    positioned = true;
    return CursorResult::match;
  }

  TupleView current() const override
  {
    if (!positioned) return {};
    return TupleView{it->data(), A};
  }
};

// ---------------------------------------------------------------------------
// The immutable decoded program.  One per rule variant; shared by every
// bucket task of that variant and pinned (shared_ptr<const Program>) by any
// parked continuation, so an install-side retire can never invalidate a
// running task (D11).
struct Program
{
  u32 rule_id = 0;
  // D3 RuleVariant ordinal: dense, unique per rule variant (semi-naive
  // versions of one source rule get distinct ordinals).  This is the
  // identity that events and disaggregated fire counts key on; uniqueness is
  // a seal-time validation error, not an assumption.
  u32 variant_ordinal = 0;
  // Display metadata only (e.g. "delta:edge#1"); never used for identity.
  std::string variant;
  u16 nregs = 0;
  std::vector<Op> ops;
  // Driver spec at the VM level: driver column i binds register
  // driver_regs[i].  Empty means the nominal mapping (column i -> register
  // i).  `pre` ops run BEFORE the driver (impl finding 7), so driver columns
  // are not assumed to be registers 0..n.
  std::vector<u16> driver_regs;
  // Constant preloads, applied to the register file once at frame setup
  // (D14) -- never per tuple.
  std::vector<std::pair<u16, u64>> preloads;
  // Register operands for variable-width ops.  emitn references one
  // contiguous slice; the bank is immutable and validated at seal time.
  // Kept last so the T2-A1 aggregate fixture remains source-compatible.
  std::vector<u16> operands;
  // Display/error metadata used by fallible primitive effects.
  std::string source;
};

// ---------------------------------------------------------------------------
// Observation (D15).  The eight stable event ports, mask-gated per event.
enum class EventK : u8
{
  driver,
  probe_match,
  probe_miss,
  probe_exhausted,
  guard_pass,
  guard_fail,
  instantiation,
  emit
};

constexpr u64 event_bit(EventK k) { return u64{1} << static_cast<u8>(k); }

// A post-transition debug event.  Carries rule identity (rule_id + the D3
// variant ordinal), the source op index, the bound cursor/sink port, and --
// for emits -- the candidate tuple as a bounded non-owning view.
//
// LIFETIME: `tuple` views attempt-owned staging storage (Attempt::
// emit_scratch) and is valid only for the duration of the observer callback;
// the next committed transition overwrites it.  An observer that records
// events must materialize the payload during the callback.
struct Event
{
  EventK kind;
  u32 rule_id;
  u32 variant_ordinal;
  size_t op_index;
  u16 port = 0; // bound cursor/sink port; op_index remains the source position
  TupleView tuple{};
};

// A materialized proof: the driver row plus one premise row per open cursor
// level.  Built only on observer request (DebugView::proof).
struct Proof
{
  std::vector<u64> driver;
  std::vector<std::vector<u64>> premises;
};

// Lazy proof view handed to observers.  Nothing is copied until proof() is
// called; premises read the positioned cursors' current() views (no copy on
// the unobserved path).  Valid only for the duration of the callback.
struct DebugView
{
  const std::vector<u64>& driver;
  const std::vector<size_t>& levels;
  const std::vector<Op>& ops;
  const std::vector<std::unique_ptr<PrefixCursor>>& cursors;

  Proof proof() const
  {
    Proof p;
    p.driver = driver;
    for (size_t ip : levels)
    {
      const PrefixCursor& cursor = *cursors[ops[ip].cursor];
      for (u16 i = 0; i < cursor.premise_count(); ++i)
      {
        const TupleView row = cursor.premise(i);
        p.premises.emplace_back(row.begin(), row.end());
      }
    }
    return p;
  }
};

enum class DebugAction : u8 { continue_, pause };

// Observer interface.  `mask` is the effective event mask: events whose bit
// is unset are never constructed for this sink, and a mask of zero selects
// the machine's separately compiled fast loop.  Returning `pause` from
// observe() is a breakpoint: the machine stops AFTER the transition that
// produced the event has committed, so resume never retriggers it.
struct DebugSink
{
  u64 mask = 0;
  virtual ~DebugSink() = default;
  virtual DebugAction observe(const Event&, const DebugView&) = 0;
};

// Bound output port used by production execution.  The VM addresses these by
// the explicit sink port carried in each emit op; tests may omit them and use
// Attempt::outputs instead.  Batch ownership and flush/commit policy remain
// outside the opcode loop, which is the T5/T6 settle/discard seam.
struct BoundSink
{
  virtual ~BoundSink() = default;
  virtual void stage(TupleView tuple) = 0;
  virtual void flush() = 0;
};

// ---------------------------------------------------------------------------
// Attempt-local ownership (D18): candidates, sink ports, batches-to-be, and
// fire counters belong to the read attempt -- discardable and replayable
// from immutable input, which is T6's takeover substrate.  A continuation
// clone SHARES its ancestor's attempt (the attempt outlives any particular
// machine copy of the same logical task).
struct Attempt
{
  bool capture_outputs = true;
  std::vector<std::vector<u64>> outputs;
  std::vector<u16> output_sinks; // parallel to outputs: bound sink port (D13)
  u64 output_count = 0;
  u64 checksum = 0;
  u64 fires = 0;
  // Emit staging, sized once to the program's widest emit.  Event::tuple
  // views this storage (see Event lifetime note).
  std::vector<u64> emit_scratch;
};

// ---------------------------------------------------------------------------
// The five-state VM (D2) and its explicit stop protocol.
enum class MachineState : u8
{
  need_driver,
  dispatch,
  first_cursor_match,
  advance,
  done
};

enum class StopReason : u8 { complete, quantum, cursor, breakpoint };

class Machine
{
  std::shared_ptr<const Program> program;
  std::unique_ptr<DriverCursor> driver;
  std::vector<std::unique_ptr<PrefixCursor>> cursors;
  std::vector<BoundSink*> sinks;
  Database* database = nullptr;
  std::vector<BoundPrim> prims;
  std::vector<BoundTycheck> tychecks;
  void (*error_emit)(Database*, const char*) = nullptr;
  std::shared_ptr<Attempt> attempt;
  std::vector<u64> regs;
  std::vector<u64> driver_row;
  std::vector<size_t> levels;
  size_t ip = 0;
  MachineState state = MachineState::need_driver;
  DebugSink* debug = nullptr;

  static constexpr u64 checksum_prime = 1099511628211ull;

  // Separately compiled execution policies (impl section 1.3, frozen split):
  // the fast policy runs on locals and saves live state only on expiry; the
  // observed policy runs directly on the members the post-transition
  // DebugView reads and pays for event construction and breakpoints.
  struct FastPolicy { static constexpr bool observed = false; };
  struct ObservedPolicy { static constexpr bool observed = true; };

  u64 effective_event_mask() const { return debug == nullptr ? 0 : debug->mask; }

  void load_driver_regs()
  {
    const std::vector<u16>& dr = program->driver_regs;
    if (dr.empty())
    {
      if (driver_row.size() > regs.size()) std::abort();
      std::copy(driver_row.begin(), driver_row.end(), regs.begin());
    }
    else
    {
      if (driver_row.size() != dr.size()) std::abort();
      for (size_t i = 0; i < driver_row.size(); ++i)
        regs[dr[i]] = driver_row[i];
    }
  }

  bool debug_event(const Event& e)
  {
    if (debug == nullptr || (debug->mask & event_bit(e.kind)) == 0)
      return false;
    DebugView view{driver_row, levels, program->ops, cursors};
    return debug->observe(e, view) == DebugAction::pause;
  }

  void commit_candidate(u16 port, const u64* values, u16 arity)
  {
    u64* scratch = attempt->emit_scratch.data();
    std::copy(values, values + arity, scratch);
    ++attempt->output_count;
    for (u16 i = 0; i < arity; ++i)
      attempt->checksum = attempt->checksum * checksum_prime + scratch[i];
    if (attempt->capture_outputs)
    {
      attempt->outputs.emplace_back(scratch, scratch + arity);
      attempt->output_sinks.push_back(port);
    }
    if (!sinks.empty()) sinks[port]->stage(TupleView{scratch, arity});
  }

  // Shared semantic helper for both policies: stage the candidate into the
  // attempt's scratch, fold the checksum, and retain the candidate with its
  // bound sink port. Returns the emit arity (scratch[0..arity) is live).
  u16 commit_emit(const Op& op)
  {
    const u16 arity = op.kind == OpK::emit2 ? 2
                    : op.kind == OpK::emit3 ? 3 : op.b;
    std::array<u64, max_daemon_arity> values{};
    if (op.kind == OpK::emitn)
    {
      for (u16 i = 0; i < arity; ++i)
        values[i] = regs[program->operands[op.a + i]];
    }
    else
    {
      values[0] = regs[op.a];
      values[1] = regs[op.b];
      if (arity == 3) values[2] = regs[op.c];
    }
    commit_candidate(op.cursor, values.data(), arity);
    return arity;
  }

  u64 invoke_primitive(const Op& op, bool& ok)
  {
    if (op.cursor >= prims.size() || prims[op.cursor].invoke == nullptr
        || prims[op.cursor].arity != op.c || database == nullptr)
      std::abort();
    std::array<u64, max_daemon_arity> args{};
    for (u16 i = 0; i < op.c; ++i)
      args[i] = regs[program->operands[op.b + i]];
    ok = true;
    return prims[op.cursor].invoke(database, args.data(), &ok);
  }

  // One loop, two instantiations.  Every committed semantic transition
  // (driver load, probe match/miss/exhaustion, guard, fire, emit) counts
  // against `transition_budget`; a cursor pause commits nothing and stops
  // with the resume point exactly where the cursor call will be retried.
  // Under ObservedPolicy each committed transition constructs its event
  // AFTER the state update (post-transition doctrine), and a breakpoint
  // returns with the members already holding the committed state, so a
  // continuation cloned at the stop resumes without retriggering.
  template <class Policy>
  StopReason run_loop(u64 transition_budget, u64 cursor_work_budget)
  {
    WorkBudget work{cursor_work_budget};
    u64 transitions = 0;

    MachineState st_local = state;
    size_t pc_local = ip;
    std::vector<size_t> stack_local;
    if constexpr (!Policy::observed) stack_local = levels;
    MachineState& st = Policy::observed ? state : st_local;
    size_t& pc = Policy::observed ? ip : pc_local;
    std::vector<size_t>& stack = Policy::observed ? levels : stack_local;

    const auto save = [&](StopReason why) {
      if constexpr (!Policy::observed)
      {
        state = st;
        ip = pc;
        levels = std::move(stack);
      }
      return why;
    };
    const auto backtrack = [&] {
      if (stack.empty()) st = MachineState::need_driver;
      else
      {
        pc = stack.back();
        st = MachineState::advance;
      }
    };

    for (;;)
    {
      bool committed = false;
      [[maybe_unused]] EventK ek{};
      [[maybe_unused]] size_t eip = 0;
      [[maybe_unused]] u16 eport = 0;
      [[maybe_unused]] TupleView etuple{};

      switch (st)
      {
        case MachineState::need_driver:
          if (!driver->next(driver_row))
          {
            st = MachineState::done;
            return save(StopReason::complete);
          }
          load_driver_regs();
          stack.clear();
          pc = 0;
          st = MachineState::dispatch;
          committed = true;
          if constexpr (Policy::observed) { ek = EventK::driver; eip = 0; }
          break;

        case MachineState::first_cursor_match:
        {
          const Op& op = program->ops[pc];
          const CursorResult r = cursors[op.cursor]->next(regs.data(), work);
          if (r == CursorResult::paused) return save(StopReason::cursor);
          if (r == CursorResult::match)
          {
            if constexpr (Policy::observed) { ek = EventK::probe_match; eip = pc; }
            stack.push_back(pc++);
            st = MachineState::dispatch;
          }
          else
          {
            if constexpr (Policy::observed) { ek = EventK::probe_miss; eip = pc; }
            backtrack();
          }
          committed = true;
          break;
        }

        case MachineState::advance:
        {
          const Op& op = program->ops[pc];
          const CursorResult r = cursors[op.cursor]->next(regs.data(), work);
          if (r == CursorResult::paused) return save(StopReason::cursor);
          if (r == CursorResult::match)
          {
            if constexpr (Policy::observed) { ek = EventK::probe_match; eip = pc; }
            ++pc;
            st = MachineState::dispatch;
          }
          else
          {
            stack.pop_back();
            if constexpr (Policy::observed) { ek = EventK::probe_exhausted; eip = pc; }
            backtrack();
          }
          committed = true;
          break;
        }

        case MachineState::dispatch:
          if (pc == program->ops.size())
          {
            backtrack(); // one full instantiation finished: not itself a transition
            break;
          }
          switch (const Op& op = program->ops[pc]; op.kind)
          {
            case OpK::probe:
              cursors[op.cursor]->open(regs.data());
              st = MachineState::first_cursor_match;
              break; // opening commits nothing; the first next() does

            case OpK::guard_neq:
            {
              const bool pass = regs[op.a] != regs[op.b];
              if constexpr (Policy::observed)
              {
                ek = pass ? EventK::guard_pass : EventK::guard_fail;
                eip = pc;
              }
              if (pass) ++pc;
              else backtrack();
              committed = true;
              break;
            }

            case OpK::guard_eq:
            {
              const bool pass = regs[op.a] == regs[op.b];
              if constexpr (Policy::observed)
              {
                ek = pass ? EventK::guard_pass : EventK::guard_fail;
                eip = pc;
              }
              if (pass) ++pc;
              else backtrack();
              committed = true;
              break;
            }

            case OpK::copy:
              regs[op.a] = regs[op.b];
              ++pc;
              break;

            case OpK::prim:
            case OpK::prim_partial:
            case OpK::guard_cmp:
            {
              const size_t op_index = pc;
              bool ok = true;
              const u64 value = invoke_primitive(op, ok);
              const bool error = value == slog_error;
              bool pass = !error && ok;
              if (op.kind == OpK::guard_cmp) pass = pass && value != 0;
              if (error)
              {
                if (error_emit == nullptr) std::abort();
                const char* source = program->source.empty()
                  ? "<interpreted>" : program->source.c_str();
                error_emit(database, source);
              }
              if (pass)
              {
                if (op.kind != OpK::guard_cmp) regs[op.a] = value;
                ++pc;
              }
              else
                backtrack();

              // Total primitive success and register copies are deliberately
              // straight-line: only row-abandoning outcomes/guards are event
              // ports. A fallible total primitive's error is a failed guard.
              if (op.kind != OpK::prim || !pass)
              {
                if constexpr (Policy::observed)
                {
                  ek = pass ? EventK::guard_pass : EventK::guard_fail;
                  eip = op_index;
                }
                committed = true;
              }
              break;
            }

            case OpK::tycheck:
            {
              if (op.cursor >= tychecks.size()) std::abort();
              const bool pass = tychecks[op.cursor].accepts(regs[op.a]);
              if constexpr (Policy::observed)
              {
                ek = pass ? EventK::guard_pass : EventK::guard_fail;
                eip = pc;
              }
              if (pass)
                ++pc;
              else
              {
                if (static_cast<size_t>(op.b) + 3
                      > program->operands.size())
                  std::abort();
                const std::array<u64, 4> fields{
                  regs[program->operands[op.b]],
                  regs[program->operands[op.b + 1]],
                  regs[program->operands[op.b + 2]],
                  regs[op.a]
                };
                commit_candidate(op.c, fields.data(), 4);
                backtrack();
              }
              committed = true;
              break;
            }

            case OpK::fire:
              if constexpr (Policy::observed) { ek = EventK::instantiation; eip = pc; }
              ++pc;
              ++attempt->fires;
              committed = true;
              break;

            case OpK::emit2:
            case OpK::emit3:
            case OpK::emitn:
            {
              if constexpr (Policy::observed) { eip = pc; }
              ++pc;
              const u16 arity = commit_emit(op);
              if constexpr (Policy::observed)
              {
                ek = EventK::emit;
                eport = op.cursor;
                etuple = TupleView{attempt->emit_scratch.data(), arity};
              }
              else
                (void)arity;
              committed = true;
              break;
            }
          }
          break;

        case MachineState::done:
          return save(StopReason::complete);
      }

      if constexpr (Policy::observed)
      {
        if (committed)
        {
          const Event e{ek, program->rule_id, program->variant_ordinal,
                        eip, eport, etuple};
          if (debug_event(e)) return StopReason::breakpoint;
        }
      }
      if (committed && ++transitions == transition_budget)
        return save(StopReason::quantum);
    }
  }

public:
  // Primary constructor: the decoded program arrives as a pinned immutable
  // generation shared across the variant's bucket tasks (D11).  Constant
  // preloads execute here, once at frame setup (D14).
  Machine(std::shared_ptr<const Program> p,
          std::unique_ptr<DriverCursor> dr,
          std::vector<std::unique_ptr<PrefixCursor>> cs,
          std::vector<BoundSink*> bound_sinks = {},
          DebugSink* d = nullptr, bool capture_outputs = true,
          Database* db = nullptr,
          std::vector<BoundPrim> bound_prims = {},
          std::vector<BoundTycheck> bound_tychecks = {},
          void (*emit_error)(Database*, const char*) = nullptr,
          std::vector<u64> initial_regs = {})
    : program(std::move(p)), driver(std::move(dr)), cursors(std::move(cs)),
      sinks(std::move(bound_sinks)),
      database(db), prims(std::move(bound_prims)),
      tychecks(std::move(bound_tychecks)), error_emit(emit_error),
      attempt(std::make_shared<Attempt>()), regs(program->nregs), debug(d)
  {
    attempt->capture_outputs = capture_outputs;
    if (!driver) std::abort();
    if (!initial_regs.empty())
    {
      if (initial_regs.size() != program->nregs) std::abort();
      regs = std::move(initial_regs);
    }
    for (const auto& [reg, value] : program->preloads)
    {
      if (reg >= program->nregs) std::abort();
      regs[reg] = value;
    }
    u16 max_emit = 0;
    for (const Op& op : program->ops)
    {
      if (op.kind == OpK::emit2) max_emit = std::max<u16>(max_emit, 2);
      else if (op.kind == OpK::emit3) max_emit = std::max<u16>(max_emit, 3);
      else if (op.kind == OpK::emitn) max_emit = std::max(max_emit, op.b);
      else if (op.kind == OpK::tycheck) max_emit = std::max<u16>(max_emit, 4);
    }
    if (!sinks.empty())
    {
      for (const Op& op : program->ops)
        if ((op.kind == OpK::emit2 || op.kind == OpK::emit3
             || op.kind == OpK::emitn) && op.cursor >= sinks.size())
          std::abort();
        else if (op.kind == OpK::tycheck && op.c >= sinks.size())
          std::abort();
    }
    attempt->emit_scratch.assign(max_emit, 0);
  }

  Machine(std::shared_ptr<const Program> p,
          std::shared_ptr<const std::vector<std::vector<u64>>> ds,
          std::vector<std::unique_ptr<PrefixCursor>> cs,
          DebugSink* d = nullptr, bool capture_outputs = true)
    : Machine(std::move(p), std::make_unique<VectorDriverCursor>(std::move(ds)),
              std::move(cs), {}, d, capture_outputs) {}

  // Convenience: copy an ephemeral decoded program into its own pinned
  // generation (used by tests and one-shot callers).
  Machine(const Program& p,
          std::shared_ptr<const std::vector<std::vector<u64>>> ds,
          std::vector<std::unique_ptr<PrefixCursor>> cs,
          DebugSink* d = nullptr, bool capture_outputs = true)
    : Machine(std::make_shared<const Program>(p), std::move(ds), std::move(cs),
              d, capture_outputs) {}

  // Continuation copy: shares the pinned program, the immutable driver rows,
  // and the logical attempt; clones registers, levels, and cursors WITH live
  // iterator state.
  Machine(const Machine& other)
    : program(other.program), driver(other.driver->clone()),
      sinks(other.sinks), database(other.database), prims(other.prims),
      tychecks(other.tychecks), error_emit(other.error_emit),
      attempt(other.attempt),
      regs(other.regs), driver_row(other.driver_row), levels(other.levels),
      ip(other.ip), state(other.state),
      debug(other.debug)
  {
    for (const auto& cursor : other.cursors) cursors.push_back(cursor->clone());
  }

  std::unique_ptr<Machine> continuation() const
  {
    return std::make_unique<Machine>(*this);
  }

  // Production entry: a zero effective event mask selects the separately
  // compiled fast loop (frozen doctrine); otherwise the micro-stepped
  // observed loop runs with post-transition events and breakpoints.
  StopReason run(u64 transition_budget, u64 cursor_work_budget)
  {
    if (effective_event_mask() == 0)
      return run_loop<FastPolicy>(transition_budget, cursor_work_budget);
    return run_loop<ObservedPolicy>(transition_budget, cursor_work_budget);
  }

  // Explicit policy entries.  run_fast is the ordinary-execution loop: no
  // per-transition event construction, live state saved only on expiry.
  // run_observed is the micro-stepped loop regardless of mask (observation
  // stays mask-gated inside it): the T5 watch/settle substrate, and the
  // benchmark's way to measure the observed loop without an active watch.
  StopReason run_fast(u64 transition_budget, u64 cursor_work_budget)
  {
    return run_loop<FastPolicy>(transition_budget, cursor_work_budget);
  }

  StopReason run_observed(u64 transition_budget, u64 cursor_work_budget)
  {
    return run_loop<ObservedPolicy>(transition_budget, cursor_work_budget);
  }

  bool done() const { return state == MachineState::done; }
  const Attempt& result() const { return *attempt; }
};

} // namespace interp
} // namespace slog
