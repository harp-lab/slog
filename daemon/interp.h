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
 * bind land in daemon/plan.h at T2-A2; the (A,K) cursor/sink factory ladders
 * land out-of-line in slogd.cpp beside makeIndex (D12).  The only daemon
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
// sink-factory registration tables when they land in slogd.cpp at T2-A2
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
  fire,                   // one instantiation counter per satisfying body
  emit2,                  // arity-2 candidate to bound sink port Op::cursor
  emit3,                  // arity-3 candidate to bound sink port Op::cursor
};

inline constexpr u16 opk_core_used = static_cast<u16>(OpK::emit3) + 1;
static_assert(opk_core_used <= opk_core_end,
              "core opcodes overflow the reserved core range");

// Fixed small-struct op in a flat vector, switch-dispatched (D14).  Operands
// are pre-resolved at decode/bind time: `cursor` is a bound cursor index for
// probes and a bound SINK PORT for emits (D13); a/b/c are register numbers.
struct Op
{
  OpK kind;
  u16 cursor = 0;
  u16 a = 0, b = 0, c = 0;
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
// empty view when unpositioned.  Debug capture reads it lazily, so the
// unobserved path never copies a premise.
struct PrefixCursor
{
  virtual ~PrefixCursor() = default;
  virtual std::unique_ptr<PrefixCursor> clone() const = 0;
  virtual void open(const u64* regs) = 0;
  virtual CursorResult next(u64* regs, WorkBudget& budget) = 0;
  virtual TupleView current() const = 0;
};

// Real daemon BTreeIndex prefix probe.  The iterator remains ON the current
// match; the following next() advances first (positioned-until-next-call).
// A pause is returned BEFORE the output registers are written: a paused
// cursor has committed nothing.
//
// Further (A, K) variants -- full-scan K=0, delta-scan drivers, old/new dord
// exclusion, map-index payload probes, absence probes, and the real
// Join3PrefixCursor erasure -- arrive as T2-B cursor-factory registrations
// (contract: extension seams), instantiated out-of-line in slogd.cpp (D12).
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
      const TupleView row = cursors[ops[ip].cursor]->current();
      p.premises.emplace_back(row.begin(), row.end());
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
  std::shared_ptr<const std::vector<std::vector<u64>>> drivers;
  std::vector<std::unique_ptr<PrefixCursor>> cursors;
  std::shared_ptr<Attempt> attempt;
  std::vector<u64> regs;
  std::vector<u64> driver_row;
  std::vector<size_t> levels;
  size_t driver_index = 0;
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
      std::copy(driver_row.begin(), driver_row.end(), regs.begin());
    else
      for (size_t i = 0; i < driver_row.size(); ++i)
        regs[dr[i]] = driver_row[i];
  }

  bool debug_event(const Event& e)
  {
    if (debug == nullptr || (debug->mask & event_bit(e.kind)) == 0)
      return false;
    DebugView view{driver_row, levels, program->ops, cursors};
    return debug->observe(e, view) == DebugAction::pause;
  }

  // Shared semantic helper for both policies: stage the candidate into the
  // attempt's scratch, fold the checksum, and retain the candidate with its
  // bound sink port.  Returns the emit arity (scratch[0..arity) is live).
  u16 commit_emit(const Op& op)
  {
    const u16 arity = op.kind == OpK::emit2 ? 2 : 3;
    u64* scratch = attempt->emit_scratch.data();
    scratch[0] = regs[op.a];
    scratch[1] = regs[op.b];
    if (arity == 3) scratch[2] = regs[op.c];
    ++attempt->output_count;
    for (u16 i = 0; i < arity; ++i)
      attempt->checksum = attempt->checksum * checksum_prime + scratch[i];
    if (attempt->capture_outputs)
    {
      attempt->outputs.emplace_back(scratch, scratch + arity);
      attempt->output_sinks.push_back(op.cursor);
    }
    return arity;
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
    size_t next_driver_local = driver_index;
    size_t pc_local = ip;
    std::vector<size_t> stack_local;
    if constexpr (!Policy::observed) stack_local = levels;
    MachineState& st = Policy::observed ? state : st_local;
    size_t& next_driver = Policy::observed ? driver_index : next_driver_local;
    size_t& pc = Policy::observed ? ip : pc_local;
    std::vector<size_t>& stack = Policy::observed ? levels : stack_local;

    const auto save = [&](StopReason why) {
      if constexpr (!Policy::observed)
      {
        state = st;
        driver_index = next_driver;
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
          if (next_driver == drivers->size())
          {
            st = MachineState::done;
            return save(StopReason::complete);
          }
          driver_row = (*drivers)[next_driver++];
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

            case OpK::fire:
              if constexpr (Policy::observed) { ek = EventK::instantiation; eip = pc; }
              ++pc;
              ++attempt->fires;
              committed = true;
              break;

            case OpK::emit2:
            case OpK::emit3:
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
          std::shared_ptr<const std::vector<std::vector<u64>>> ds,
          std::vector<std::unique_ptr<PrefixCursor>> cs,
          DebugSink* d = nullptr, bool capture_outputs = true)
    : program(std::move(p)), drivers(std::move(ds)), cursors(std::move(cs)),
      attempt(std::make_shared<Attempt>()), regs(program->nregs), debug(d)
  {
    attempt->capture_outputs = capture_outputs;
    if (!program->driver_regs.empty() && !drivers->empty()
        && program->driver_regs.size() != drivers->front().size())
      std::abort();
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
    }
    attempt->emit_scratch.assign(max_emit, 0);
  }

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
    : program(other.program), drivers(other.drivers), attempt(other.attempt),
      regs(other.regs), driver_row(other.driver_row), levels(other.levels),
      driver_index(other.driver_index), ip(other.ip), state(other.state),
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
