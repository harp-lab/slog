// Executable specification for the production interpreter core in
// daemon/interp.h (docs/interp-core-contract.md; extracted at T2-A1).  The
// core types -- tri-state pull cursors, the decoded Program, the five-state
// Machine with fast/observed policies, mask-gated post-transition events,
// and attempt-local candidate ownership -- are instantiated from the
// production header; this file keeps the core fixtures, the differential
// logical model, and the production Plan -> seal -> bind -> scheduler slice,
// including bound primitives, partial matches, and type-effect sinks.
//
// It exercises: exact continuation copies at every VM quantum 1..31,
// intra-match cursor pauses, a 96-level cursor stack, all eight event ports
// with breakpoints, bounded proof capture, seal/bind rejections, and real
// Relation indices and emit sinks with dedup.
//
//   clang++ -O0 -Wall -std=c++20 -pthread -fopenmp -Idaemon -c daemon/plan-flavored-tasks.cpp -o /tmp/pft.o
//   clang++ -O2 -Wall -std=c++20 -pthread -fopenmp -Idaemon tests/interp-operator-tests.cpp daemon/plan.cpp daemon/plan-count.cpp daemon/query.cpp daemon/sexp.cpp daemon/runtime.cpp /tmp/pft.o -o /tmp/interp-tests -lgmp
//   /tmp/interp-tests [--bench]

#include "plan.h"
#include "query.h"
#include "sexp.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <set>
#include <sys/wait.h>
#include <unistd.h>
#include <stdexcept>
#include <string>
#include <utility>
#include <variant>
#include <vector>

using namespace slog;
using namespace slog::interp;
namespace q = slog::query;

namespace {

// A test-only cursor whose next match takes several internal units of work.  This is
// the shape join3 needs: an intersection may have to seek repeatedly before
// producing a row, so bool next() cannot distinguish "yield" from "empty".
struct SlowCursor final : PrefixCursor
{
  std::vector<u64> values;
  std::vector<u64> costs;
  u16 outreg;
  size_t next_index = 0;
  u64 remaining = 0;
  bool positioned = false;

  SlowCursor(std::vector<u64> vs, std::vector<u64> cs, u16 out)
    : values(std::move(vs)), costs(std::move(cs)), outreg(out) {}

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<SlowCursor>(*this);
  }

  void open(const u64*) override
  {
    next_index = 0;
    remaining = costs.empty() ? 0 : costs[0];
    positioned = false;
  }

  CursorResult next(u64* regs, WorkBudget& budget) override
  {
    if (positioned)
    {
      ++next_index;
      positioned = false;
      remaining = next_index < costs.size() ? costs[next_index] : 0;
    }
    if (next_index == values.size()) return CursorResult::exhausted;
    while (remaining != 0)
    {
      if (!budget.tick()) return CursorResult::paused;
      --remaining;
    }
    regs[outreg] = values[next_index];
    positioned = true;
    return CursorResult::match;
  }

  TupleView current() const override
  {
    return positioned ? TupleView{&values[next_index], 1} : TupleView{};
  }
};

// Event::tuple is a non-owning view valid only for the observer callback's
// duration (interp.h lifetime doctrine), so a recording observer must
// materialize the payload during the callback.
struct OwnedEvent
{
  EventK kind;
  u32 rule_id;
  u32 variant_ordinal;
  size_t op_index;
  u16 port;
  std::vector<u64> tuple;

  explicit OwnedEvent(const Event& e)
    : kind(e.kind), rule_id(e.rule_id), variant_ordinal(e.variant_ordinal),
      op_index(e.op_index), port(e.port),
      tuple(e.tuple.begin(), e.tuple.end()) {}
};

struct RecordingDebug final : DebugSink
{
  bool record_events = false;
  std::optional<EventK> break_on;
  std::optional<std::array<u64, 2>> watched_emit;
  size_t proof_limit = std::numeric_limits<size_t>::max();
  size_t omitted_proofs = 0;
  std::vector<OwnedEvent> events;
  std::vector<Proof> proofs;

  DebugAction observe(const Event& e, const DebugView& view) override
  {
    if (record_events) events.emplace_back(e);
    if (watched_emit && e.kind == EventK::emit && e.tuple.size() == 2
        && e.tuple[0] == (*watched_emit)[0]
        && e.tuple[1] == (*watched_emit)[1])
    {
      if (proofs.size() < proof_limit) proofs.push_back(view.proof());
      else ++omitted_proofs;
    }
    return break_on && *break_on == e.kind
      ? DebugAction::pause : DebugAction::continue_;
  }
};

template <u16 A>
std::array<Index*, bucket_count> make_indices()
{
  std::array<Index*, bucket_count> out{};
  for (u16 b = 0; b < bucket_count; ++b) out[b] = new BTreeIndex<A>();
  return out;
}

void destroy_indices(std::array<Index*, bucket_count>& xs)
{
  for (Index* x : xs) delete x;
}

void insert(std::array<Index*, bucket_count>& xs, u64 a, u64 b)
{
  static_cast<BTreeIndex<2>*>(xs[buckethash(a)])->insert({a, b});
}

struct Fixture
{
  std::array<Index*, bucket_count> first = make_indices<2>();
  std::array<Index*, bucket_count> second = make_indices<2>();
  std::shared_ptr<const std::vector<std::vector<u64>>> drivers;
  Program program;

  Fixture()
  {
    // first(b,c)
    insert(first, 1, 100); insert(first, 1, 101);
    insert(first, 2, 100);
    // second(c,e).  e=10 deliberately fails neq(a,e) for driver a=10.
    insert(second, 100, 7); insert(second, 100, 8);
    insert(second, 100, 10); insert(second, 101, 8);
    drivers = std::make_shared<const std::vector<std::vector<u64>>>(
      std::vector<std::vector<u64>>{{10, 1}, {10, 2}, {20, 1}, {30, 9}});
    program.rule_id = 17;
    program.variant_ordinal = 3; // D3 ordinal; events must carry it verbatim
    program.variant = "all:first";
    program.nregs = 4;
    program.ops = {
      {OpK::probe, 0},                 // r1=b -> r2=c
      {OpK::probe, 1},                 // r2=c -> r3=e
      {OpK::guard_neq, 0, 0, 3},       // a != e
      {OpK::fire},
      {OpK::emit2, 0, 0, 3}            // emit(a,e), duplicates retained
    };
  }

  ~Fixture() { destroy_indices(first); destroy_indices(second); }

  std::vector<std::unique_ptr<PrefixCursor>> cursors()
  {
    std::vector<std::unique_ptr<PrefixCursor>> out;
    out.push_back(std::make_unique<ProbeCursor<2, 1>>(
      first.data(), std::array<u16, 1>{1}, std::array<u16, 1>{2}));
    out.push_back(std::make_unique<ProbeCursor<2, 1>>(
      second.data(), std::array<u16, 1>{2}, std::array<u16, 1>{3}));
    return out;
  }
};

bool fail(const std::string& what)
{
  std::cerr << "FAIL: " << what << '\n';
  return false;
}

#define CHECK(COND) do { if (!(COND)) return fail(#COND); } while (false)

u64 primitive_error_callbacks = 0;

void record_primitive_error(Database*, const char*)
{
  ++primitive_error_callbacks;
}

std::vector<std::vector<u64>> reference(const Fixture& f, u64& fires)
{
  std::vector<std::vector<u64>> out;
  fires = 0;
  for (const auto& d : *f.drivers)
  {
    const u64 a = d[0], b = d[1];
    auto* i1 = static_cast<BTreeIndex<2>*>(f.first[buckethash(b)]);
    for (auto x = i1->lower_bound({b, 0}); x != i1->end() && (*x)[0] == b; ++x)
    {
      const u64 c = (*x)[1];
      auto* i2 = static_cast<BTreeIndex<2>*>(f.second[buckethash(c)]);
      for (auto y = i2->lower_bound({c, 0}); y != i2->end() && (*y)[0] == c; ++y)
      {
        const u64 e = (*y)[1];
        if (a == e) continue;
        ++fires;
        out.push_back({a, e});
      }
    }
  }
  return out;
}

static std::vector<std::vector<u64>> nominal_delta_rows(Relation* rel)
{
  std::vector<std::vector<u64>> rows;
  for (InsertBatch* batch : rel->getDelta())
    for (u32 off = 0; off < batch->usage; off += rel->getArity())
      rows.emplace_back(batch->data + off,
                        batch->data + off + rel->getArity());
  std::sort(rows.begin(), rows.end());
  return rows;
}

static std::unique_ptr<Relation> make_relation(
  const std::string& name, u16 arity,
  const std::vector<std::vector<u16>>& orders)
{
  auto rel = std::make_unique<Relation>(name, arity, 0);
  rel->initShards(1);
  for (const auto& order : orders)
  {
    if (arity == 1) rel->addIndex<1>(order, false);
    else if (arity == 2) rel->addIndex<2>(order, false);
    else if (arity == 3) rel->addIndex<3>(order, false);
    else throw SealError("fixture: unsupported relation arity");
  }
  return rel;
}

static void load_delta(Relation* rel,
                       const std::vector<std::vector<u64>>& rows)
{
  InsertBatch* batch = new InsertBatch();
  for (const auto& row : rows)
  {
    seal_check(row.size() == rel->getArity(), "fixture: row width mismatch");
    for (u64 value : row) batch->data[batch->usage++] = value;
  }
  rel->getDelta().push_back(batch);
  rel->ensureReorgBuffers(1);
  rel->reorgDelta(0, 1);
}

static std::string replace_once(std::string text, const std::string& from,
                                const std::string& to)
{
  const size_t at = text.find(from);
  if (at == std::string::npos)
    throw std::runtime_error("fixture replacement did not match: " + from);
  text.replace(at, from.size(), to);
  return text;
}

bool test_uninterrupted_and_every_quantum()
{
  Fixture f;
  u64 wanted_fires = 0;
  const auto wanted = reference(f, wanted_fires);
  for (u64 quantum = 1; quantum <= 31; ++quantum)
  {
    // Micro-stepped observed loop (explicitly, since no observer is
    // attached and the production `run` would select the fast loop).
    auto m = std::make_unique<Machine>(f.program, f.drivers, f.cursors());
    while (!m->done())
    {
      const StopReason why = m->run_observed(quantum, 1000000);
      CHECK(why == StopReason::quantum || why == StopReason::complete);
      if (why == StopReason::quantum)
        m = m->continuation(); // exercise copy-for-resume at every VM boundary
    }
    CHECK(m->result().outputs == wanted);
    CHECK(m->result().fires == wanted_fires);

    auto fast = std::make_unique<Machine>(f.program, f.drivers, f.cursors());
    while (!fast->done())
    {
      const StopReason why = fast->run_fast(quantum, 1000000);
      CHECK(why == StopReason::quantum || why == StopReason::complete);
      if (why == StopReason::quantum) fast = fast->continuation();
    }
    CHECK(fast->result().outputs == wanted);
    CHECK(fast->result().fires == wanted_fires);
  }
  return true;
}

bool test_cursor_internal_pause_and_continuation_copy()
{
  Program p{23, 1, "synthetic-join3", 2,
            {{OpK::probe, 0}, {OpK::fire}, {OpK::emit2, 0, 0, 1}}};
  auto drivers = std::make_shared<const std::vector<std::vector<u64>>>(
    std::vector<std::vector<u64>>{{42}});
  std::vector<std::unique_ptr<PrefixCursor>> cursors;
  cursors.push_back(std::make_unique<SlowCursor>(
    std::vector<u64>{7, 8, 9}, std::vector<u64>{9, 1, 17}, 1));
  auto m = std::make_unique<Machine>(p, drivers, std::move(cursors));
  size_t cursor_pauses = 0;
  while (!m->done())
  {
    const StopReason why = m->run_observed(1000, 2);
    if (why == StopReason::cursor)
    {
      ++cursor_pauses;
      // Model Task's copy-for-resume path: discard the consumed task and run
      // a cloned continuation carrying live iterator/intersection state.
      m = m->continuation();
    }
    else CHECK(why == StopReason::complete);
  }
  CHECK(cursor_pauses >= 10);
  CHECK(m->result().fires == 3);
  CHECK(m->result().outputs ==
        (std::vector<std::vector<u64>>{{42, 7}, {42, 8}, {42, 9}}));

  std::vector<std::unique_ptr<PrefixCursor>> fast_cursors;
  fast_cursors.push_back(std::make_unique<SlowCursor>(
    std::vector<u64>{7, 8, 9}, std::vector<u64>{9, 1, 17}, 1));
  auto fast = std::make_unique<Machine>(
    p, drivers, std::move(fast_cursors));
  cursor_pauses = 0;
  while (!fast->done())
  {
    const StopReason why = fast->run_fast(1000, 2);
    if (why == StopReason::cursor)
    {
      ++cursor_pauses;
      fast = fast->continuation();
    }
    else CHECK(why == StopReason::complete);
  }
  CHECK(cursor_pauses >= 10);
  CHECK(fast->result().fires == 3);
  CHECK(fast->result().outputs ==
        (std::vector<std::vector<u64>>{{42, 7}, {42, 8}, {42, 9}}));
  return true;
}

static std::unique_ptr<Machine> machine_from_ephemeral_program()
{
  Program program{24, 1, "retired-plan", 2,
                  {{OpK::fire}, {OpK::emit2, 0, 0, 1}}};
  auto drivers = std::make_shared<const std::vector<std::vector<u64>>>(
    std::vector<std::vector<u64>>{{4, 5}});
  return std::make_unique<Machine>(
    program, std::move(drivers),
    std::vector<std::unique_ptr<PrefixCursor>>{});
}

bool test_parked_task_pins_immutable_program()
{
  auto task = machine_from_ephemeral_program();
  CHECK(task->run_observed(1, 1) == StopReason::quantum);
  task = task->continuation();
  while (!task->done())
  {
    const StopReason why = task->run_observed(1, 1);
    CHECK(why == StopReason::quantum || why == StopReason::complete);
    if (why == StopReason::quantum) task = task->continuation();
  }
  CHECK(task->result().fires == 1);
  CHECK(task->result().outputs ==
        (std::vector<std::vector<u64>>{{4, 5}}));
  return true;
}

bool test_plan_sized_deep_cursor_stack()
{
  // Real plans in the current cache reach 85 cursor levels and 251 regs.
  // Stay above that observed cursor depth so a fixed level_ip[8] (the design
  // sketch's illustrative array) cannot accidentally become implementation.
  constexpr u16 depth = 96;
  Program p;
  p.rule_id = 29;
  p.variant_ordinal = 2;
  p.variant = "deep-chain";
  p.nregs = depth + 1;
  std::vector<std::unique_ptr<PrefixCursor>> cursors;
  for (u16 i = 0; i < depth; ++i)
  {
    p.ops.push_back({OpK::probe, i});
    cursors.push_back(std::make_unique<SlowCursor>(
      std::vector<u64>{u64{1000} + i}, std::vector<u64>{0}, i + 1));
  }
  p.ops.push_back({OpK::fire});
  p.ops.push_back({OpK::emit2, 0, 0, depth});
  auto drivers = std::make_shared<const std::vector<std::vector<u64>>>(
    std::vector<std::vector<u64>>{{7}});
  Machine m(p, drivers, std::move(cursors));
  while (!m.done())
  {
    const StopReason why = m.run_observed(3, 11);
    CHECK(why == StopReason::quantum || why == StopReason::complete);
  }
  CHECK(m.result().fires == 1);
  CHECK(m.result().outputs ==
        (std::vector<std::vector<u64>>{{7, u64{1000} + depth - 1}}));
  return true;
}

bool test_breakpoints_are_post_transition_and_non_retriggering()
{
  Fixture f;
  u64 wanted_fires = 0;
  const auto wanted = reference(f, wanted_fires);
  for (EventK port : {EventK::driver, EventK::probe_match,
                      EventK::probe_miss, EventK::probe_exhausted,
                      EventK::guard_pass, EventK::guard_fail,
                      EventK::instantiation, EventK::emit})
  {
    RecordingDebug debug;
    debug.mask = event_bit(port);
    debug.break_on = port;
    auto m = std::make_unique<Machine>(
      f.program, f.drivers, f.cursors(), &debug);
    size_t breaks = 0;
    size_t prior_outputs = 0;
    while (!m->done())
    {
      const StopReason why = m->run(1000000, 1000000);
      if (why == StopReason::breakpoint)
      {
        ++breaks;
        // An emit breakpoint stops after exactly one newly committed sink.
        // Other selected ports can have arbitrary emits between their hits.
        if (port == EventK::emit)
          CHECK(m->result().outputs.size() == prior_outputs + 1);
        else
          CHECK(m->result().outputs.size() >= prior_outputs);
        prior_outputs = m->result().outputs.size();
        m = m->continuation();
      }
      else CHECK(why == StopReason::complete);
    }
    CHECK(breaks != 0);
    CHECK(m->result().outputs == wanted);
    CHECK(m->result().fires == wanted_fires);
  }
  return true;
}

bool test_selective_watch_proofs_and_failure_events()
{
  Fixture f;
  u64 wanted_fires = 0;
  const auto wanted = reference(f, wanted_fires);
  RecordingDebug debug;
  debug.mask = event_bit(EventK::emit) | event_bit(EventK::probe_miss)
             | event_bit(EventK::guard_fail);
  debug.record_events = true;
  debug.watched_emit = std::array<u64, 2>{10, 8};
  debug.proof_limit = 1;
  Machine m(f.program, f.drivers, f.cursors(), &debug);
  while (!m.done())
  {
    const StopReason why = m.run(7, 5);
    CHECK(why == StopReason::quantum || why == StopReason::cursor
          || why == StopReason::complete);
  }
  CHECK(m.result().outputs == wanted);
  CHECK(m.result().fires == wanted_fires);
  CHECK(debug.proofs.size() == 1);
  CHECK(debug.omitted_proofs >= 1); // distinct derivations of candidate (10,8)
  CHECK(debug.proofs[0].driver == (std::vector<u64>{10, 1}));
  CHECK(debug.proofs[0].premises.size() == 2);
  CHECK(debug.proofs[0].premises[0][0] == 1);
  CHECK(debug.proofs[0].premises[1][1] == 8);
  CHECK(std::any_of(debug.events.begin(), debug.events.end(),
                    [](const OwnedEvent& e) { return e.kind == EventK::probe_miss; }));
  CHECK(std::any_of(debug.events.begin(), debug.events.end(),
                    [](const OwnedEvent& e) { return e.kind == EventK::guard_fail; }));
  // Every event carries the decoded program's D3 variant ordinal verbatim
  // (contract lift obligation 1), and emit payloads were materialized from
  // the bounded view during the callback.
  CHECK(!debug.events.empty());
  CHECK(std::all_of(debug.events.begin(), debug.events.end(),
                    [&](const OwnedEvent& e) {
                      return e.rule_id == f.program.rule_id
                          && e.variant_ordinal == f.program.variant_ordinal;
                    }));
  CHECK(std::all_of(debug.events.begin(), debug.events.end(),
                    [](const OwnedEvent& e) {
                      return e.kind != EventK::emit || e.tuple.size() == 2;
                    }));
  return true;
}

bool test_zero_mask_observer_has_zero_callbacks()
{
  struct CountDebug final : DebugSink
  {
    u64 calls = 0;
    DebugAction observe(const Event&, const DebugView&) override
    { ++calls; return DebugAction::continue_; }
  } debug;
  Fixture f;
  u64 wanted_fires = 0;
  const auto wanted = reference(f, wanted_fires);
  // Production entry: a zero effective mask selects the fast loop, so an
  // attached observer with mask 0 receives zero callbacks.
  Machine m(f.program, f.drivers, f.cursors(), &debug);
  while (!m.done())
  {
    const StopReason why = m.run(1000000, 1000000);
    CHECK(why == StopReason::complete);
  }
  CHECK(debug.calls == 0);
  CHECK(m.result().outputs == wanted);
  // Mask gating also holds inside the observed loop itself: forcing the
  // micro-stepped policy with a zero mask still constructs no callbacks.
  Machine forced(f.program, f.drivers, f.cursors(), &debug);
  while (!forced.done())
  {
    const StopReason why = forced.run_observed(1000000, 1000000);
    CHECK(why == StopReason::complete);
  }
  CHECK(debug.calls == 0);
  CHECK(forced.result().outputs == wanted);
  return true;
}

static void insert_nominal(Relation* rel, std::initializer_list<u64> values)
{
  std::vector<u64> row(values);
  if (row.size() != rel->getArity()) throw SealError("fixture: row width mismatch");
  rel->insertTupleAllIndices(row.data());
}

static std::vector<std::vector<u64>> nominal_index_rows(
  Relation* rel, const std::vector<u16>& order);

static void add_delta_index_rows2(
  Relation* rel, const std::vector<u16>& order,
  const std::vector<std::array<u64, 2>>& rows)
{
  rel->addIndex<2>(order, true);
  Index** index = rel->getIndex(order, true);
  for (const auto& nominal : rows)
  {
    std::array<u64, 2> ordered{nominal[order[0]], nominal[order[1]]};
    static_cast<BTreeIndex<2>*>(index[buckethash(ordered[0])])->insert(ordered);
  }
}

static std::unique_ptr<Relation> make_lattice_relation(
  const std::string& name, u16 arity,
  const std::vector<std::vector<u16>>& orders)
{
  auto rel = std::make_unique<Relation>(name, arity, 0);
  rel->initShards(1);
  rel->setLattice(LAT_MIN, false, 0, false, 0, "min-int");
  for (const auto& order : orders)
  {
    if (arity == 2) rel->addMapIndex<2>(order);
    else if (arity == 3) rel->addMapIndex<3>(order);
    else throw SealError("fixture: unsupported lattice arity");
  }
  return rel;
}

static void insert_lattice2(Relation* rel, u64 key, u64 value)
{
  auto* map = static_cast<BTreeMapIndex<1>*>(
    rel->getIndex({0, 1}, false)[buckethash(key)]);
  bool changed = false;
  (void)map->merge({key}, value, changed);
}

static void insert_lattice3(
  Relation* rel, const std::vector<u16>& order,
  const std::array<u64, 3>& nominal)
{
  std::array<u64, 2> key{nominal[order[0]], nominal[order[1]]};
  auto* map = static_cast<BTreeMapIndex<2>*>(
    rel->getIndex(order, false)[buckethash(key[0])]);
  bool changed = false;
  (void)map->merge(key, nominal[order[2]], changed);
}

template <Join3View LV, Join3View RV>
static std::vector<u64> native_join3_values(
  Relation* left, Relation* right, u64 left_prefix, u64 right_prefix)
{
  const std::vector<u16> order{0, 1};
  Index** left_full = left->getIndex(order, false);
  Index** right_full = right->getIndex(order, false);
  Index** left_delta = LV == Join3View::full
    ? left_full : left->getIndex(order, true);
  Index** right_delta = RV == Join3View::full
    ? right_full : right->getIndex(order, true);
  std::vector<u64> values;
  join3<2, 1, LV, 2, 1, RV>(
    left_full, left_delta, {left_prefix, 0},
    right_full, right_delta, {right_prefix, 0},
    [&](u64 value) { values.push_back(value); });
  return values;
}

static std::vector<u64> native_join3_values(
  ProbePlan::View left, ProbePlan::View right,
  Relation* left_relation, Relation* right_relation,
  u64 left_prefix, u64 right_prefix)
{
  using View = ProbePlan::View;
  if (left == View::full && right == View::full)
    return native_join3_values<Join3View::full, Join3View::full>(
      left_relation, right_relation, left_prefix, right_prefix);
  if (left == View::full && right == View::old)
    return native_join3_values<Join3View::full, Join3View::old>(
      left_relation, right_relation, left_prefix, right_prefix);
  if (left == View::full && right == View::new_)
    return native_join3_values<Join3View::full, Join3View::new_>(
      left_relation, right_relation, left_prefix, right_prefix);
  if (left == View::old && right == View::full)
    return native_join3_values<Join3View::old, Join3View::full>(
      left_relation, right_relation, left_prefix, right_prefix);
  if (left == View::old && right == View::old)
    return native_join3_values<Join3View::old, Join3View::old>(
      left_relation, right_relation, left_prefix, right_prefix);
  if (left == View::old && right == View::new_)
    return native_join3_values<Join3View::old, Join3View::new_>(
      left_relation, right_relation, left_prefix, right_prefix);
  if (left == View::new_ && right == View::full)
    return native_join3_values<Join3View::new_, Join3View::full>(
      left_relation, right_relation, left_prefix, right_prefix);
  if (left == View::new_ && right == View::old)
    return native_join3_values<Join3View::new_, Join3View::old>(
      left_relation, right_relation, left_prefix, right_prefix);
  return native_join3_values<Join3View::new_, Join3View::new_>(
    left_relation, right_relation, left_prefix, right_prefix);
}

bool test_join3_cursor_all_views_native_differential()
{
  using View = ProbePlan::View;
  const std::vector<u16> order{0, 1};
  const std::vector<RelationShape> shapes{
    {2, {order}},
    {2, {order}, RelationK::plain, {order}},
    {2, {order}, RelationK::plain, {order}},
    {2, {order}}
  };
  auto driver = make_relation("join3-driver", 2, {order});
  auto left = make_relation("join3-left", 2, {order});
  auto right = make_relation("join3-right", 2, {order});
  auto output = make_relation("join3-output", 2, {order});

  load_delta(driver.get(), {{10, 20}});
  for (u64 value : {u64{0}, u64{2}, u64{4}, u64{8}, u64{20}})
    insert_nominal(left.get(), {10, value});
  for (u64 value : {u64{1}, u64{2}, u64{6}, u64{8}, u64{30}})
    insert_nominal(right.get(), {20, value});
  add_delta_index_rows2(left.get(), order,
                        {{10, 2}, {10, 6}, {10, 20}});
  add_delta_index_rows2(right.get(), order,
                        {{20, 2}, {20, 4}, {20, 6}, {20, 40}});

  struct JoinProofDebug final : DebugSink
  {
    std::vector<Proof> proofs;
    DebugAction observe(const Event& event, const DebugView& view) override
    {
      if (event.kind == EventK::emit) proofs.push_back(view.proof());
      return DebugAction::continue_;
    }
  };

  const std::array<View, 3> views{View::full, View::old, View::new_};
  size_t cursor_pauses = 0;
  for (View left_view : views)
  for (View right_view : views)
  {
    const auto delta_order = [&](View view) {
      return view == View::full ? std::vector<u16>{} : order;
    };
    Join3Plan join3_plan{
      2,
      {1, order, 1, {0, 2}, left_view, delta_order(left_view)},
      {2, order, 1, {1, 2}, right_view, delta_order(right_view)}
    };
    RulePlan plan{
      84, static_cast<u32>(left_view) * 3 + static_cast<u32>(right_view),
      "join3-all-views", 3, {},
      {DriverK::scan_delta, 0, {}, 0, {0, 1}},
      {join3_plan}, {EmitPlan{3, order, {0, 2}}}
    };
    BoundRule bound(seal_rule(plan, shapes),
                    {driver.get(), left.get(), right.get(), output.get()});
    JoinProofDebug debug;
    debug.mask = event_bit(EventK::emit);
    std::vector<std::vector<u64>> actual;
    u64 fires = 0;
    for (u16 bucket = 0; bucket < bound.task_count(); ++bucket)
    {
      auto task = bound.make_task(bucket, &debug);
      while (!task->done())
      {
        const StopReason why = task->run_observed(2, 1);
        CHECK(why == StopReason::quantum || why == StopReason::cursor
              || why == StopReason::complete);
        if (why == StopReason::cursor) ++cursor_pauses;
        if (why != StopReason::complete) task = task->continuation();
      }
      fires += task->result().fires;
      actual.insert(actual.end(), task->result().outputs.begin(),
                    task->result().outputs.end());
    }

    const std::vector<u64> native = native_join3_values(
      left_view, right_view, left.get(), right.get(), 10, 20);
    std::vector<std::vector<u64>> expected;
    for (u64 value : native) expected.push_back({10, value});
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());
    CHECK(actual == expected);
    CHECK(fires == native.size());
    CHECK(debug.proofs.size() == native.size());
    for (const Proof& proof : debug.proofs)
    {
      CHECK(proof.driver == (std::vector<u64>{10, 20}));
      CHECK(proof.premises.size() == 2);
      CHECK(proof.premises[0].size() == 2);
      CHECK(proof.premises[1].size() == 2);
      CHECK(proof.premises[0][0] == 10);
      CHECK(proof.premises[1][0] == 20);
      CHECK(proof.premises[0][1] == proof.premises[1][1]);
    }
  }
  CHECK(cursor_pauses != 0);
  return true;
}

bool test_join3_mixed_arm_arities()
{
  const std::vector<u16> order2{0, 1};
  const std::vector<u16> order3{0, 1, 2};
  const std::vector<RelationShape> shapes{
    {3, {order3}}, {3, {order3}}, {2, {order2}}, {2, {order2}}
  };
  auto driver = make_relation("join3-mixed-driver", 3, {order3});
  auto left = make_relation("join3-mixed-left", 3, {order3});
  auto right = make_relation("join3-mixed-right", 2, {order2});
  auto output = make_relation("join3-mixed-output", 2, {order2});
  load_delta(driver.get(), {{10, 11, 20}});
  for (u64 value : {u64{1}, u64{4}, u64{8}, u64{30}})
    insert_nominal(left.get(), {10, 11, value});
  insert_nominal(left.get(), {10, 99, 4});
  for (u64 value : {u64{0}, u64{4}, u64{8}, u64{40}})
    insert_nominal(right.get(), {20, value});

  RulePlan plan{
    86, 0, "join3-mixed-arities", 4, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1, 2}},
    {Join3Plan{3,
      {1, order3, 2, {0, 1, 3}, ProbePlan::View::full, {}},
      {2, order2, 1, {2, 3}, ProbePlan::View::full, {}}}},
    {EmitPlan{3, order2, {0, 3}}}
  };
  BoundRule bound(seal_rule(plan, shapes),
                  {driver.get(), left.get(), right.get(), output.get()});
  std::vector<std::vector<u64>> actual;
  u64 fires = 0;
  for (u16 bucket = 0; bucket < bound.task_count(); ++bucket)
  {
    auto task = bound.make_task(bucket);
    while (!task->done())
    {
      const StopReason why = task->run_fast(2, 1);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
      if (why != StopReason::complete) task = task->continuation();
    }
    fires += task->result().fires;
    actual.insert(actual.end(), task->result().outputs.begin(),
                  task->result().outputs.end());
  }

  std::vector<std::vector<u64>> expected;
  join3<3, 2, Join3View::full, 2, 1, Join3View::full>(
    left->getIndex(order3, false), left->getIndex(order3, false),
    {10, 11, 0},
    right->getIndex(order2, false), right->getIndex(order2, false),
    {20, 0}, [&](u64 value) { expected.push_back({10, value}); });
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  CHECK(actual == expected);
  CHECK(actual == (std::vector<std::vector<u64>>{{10, 4}, {10, 8}}));
  CHECK(fires == expected.size());
  return true;
}

bool test_parsed_join3_and_typed_refusals()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor normal) "
    "(relations "
      "(rel 0 (relation driver 2 (0 1))) "
      "(rel 1 (relation left 2 (0 1) (delta 0 1))) "
      "(rel 2 (relation right 2 (0 1) (delta 0 1))) "
      "(rel 3 (relation out 2 (0 1)))) "
    "(attachments) (constants) (prims) (dynamic out) "
    "(rules (rule-def (rid 85) (variant \"join3#0\") (nregs 3) "
      "(pre) (driver (scan (rel 0) (r 0) (r 1))) "
      "(body (join3 (r 2) "
        "(new (rel 1) (0 1) 1 (0 1) (r 0) (r 2)) "
        "(old (rel 2) (0 1) 1 (0 1) (r 1) (r 2)))) "
      "(head (emit (rel 3) (0 1) (r 0) (r 2))))) "
    "(meta (rule-meta (rid 85) (source \"join3.slog:1\"))))";

  const DecodedKernelPlan decoded = parse_kernel_plan(text);
  CHECK(decoded.rules.size() == 1);
  const auto& parsed = std::get<Join3Plan>(decoded.rules[0].plan.body[0]);
  CHECK(parsed.cycle == 2);
  CHECK(parsed.left.view == ProbePlan::View::new_);
  CHECK(parsed.right.view == ProbePlan::View::old);
  CHECK(parsed.left.regs == (std::vector<u16>{0, 2}));
  CHECK(parsed.right.regs == (std::vector<u16>{1, 2}));

  Database db(1);
  db.addRelation("driver", 2);
  db.addRelation("left", 2);
  db.addRelation("right", 2);
  db.addRelation("out", 2);
  Relation* driver = db.getRelation("driver");
  Relation* left = db.getRelation("left");
  Relation* right = db.getRelation("right");
  Relation* output = db.getRelation("out");
  for (Relation* rel : {driver, left, right, output})
    rel->addIndex<2>({0, 1}, false);
  load_delta(driver, {{10, 20}});
  for (u64 value : {u64{0}, u64{2}, u64{4}, u64{6}, u64{8}})
    insert_nominal(left, {10, value});
  for (u64 value : {u64{1}, u64{2}, u64{6}, u64{8}, u64{30}})
    insert_nominal(right, {20, value});
  add_delta_index_rows2(left, {0, 1}, {{10, 4}});
  add_delta_index_rows2(right, {0, 1}, {{20, 2}, {20, 6}});

  const SealedKernelPlan sealed = seal_kernel_plan(decoded);
  CHECK(sealed.rules[0].cursors.size() == 1);
  CHECK(std::holds_alternative<Join3Plan>(sealed.rules[0].cursors[0]));
  const auto rules = bind_kernel_plan(sealed, db);
  std::vector<std::vector<u64>> actual;
  u64 fires = 0;
  size_t cursor_pauses = 0;
  for (u16 bucket = 0; bucket < rules[0]->task_count(); ++bucket)
  {
    auto task = rules[0]->make_task(bucket);
    while (!task->done())
    {
      const StopReason why = task->run_fast(2, 1);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
      if (why == StopReason::cursor) ++cursor_pauses;
      if (why != StopReason::complete) task = task->continuation();
    }
    fires += task->result().fires;
    actual.insert(actual.end(), task->result().outputs.begin(),
                  task->result().outputs.end());
  }
  const std::vector<u64> native = native_join3_values(
    ProbePlan::View::new_, ProbePlan::View::old,
    left, right, 10, 20);
  std::vector<std::vector<u64>> expected;
  for (u64 value : native) expected.push_back({10, value});
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  CHECK(actual == expected);
  CHECK(fires == native.size());
  CHECK(cursor_pauses != 0);

  // The same parsed/bound rule must drive the real ordinary sink, not only
  // the test capture path used above.
  for (u16 bucket = 0; bucket < rules[0]->task_count(); ++bucket)
  {
    auto execution = rules[0]->make_execution(&db, bucket);
    while (!execution->machine->done())
    {
      const StopReason why = execution->machine->run_fast(3, 2);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
    }
    execution->flush();
  }
  output->finalizeBatches();
  CHECK(nominal_delta_rows(output) == expected);

  const auto rejects = [](SealErrorK kind, auto&& thunk) {
    try { thunk(); }
    catch (const SealError& error) { return error.kind() == kind; }
    return false;
  };
  const auto join3 = [](DecodedKernelPlan& plan) -> Join3Plan& {
    return std::get<Join3Plan>(plan.rules[0].plan.body[0]);
  };

  DecodedKernelPlan zero_prefix = decoded;
  join3(zero_prefix).left.bound = 0;
  CHECK(rejects(SealErrorK::factory,
    [&] { (void)seal_kernel_plan(zero_prefix); }));

  DecodedKernelPlan non_key_simple = decoded;
  join3(non_key_simple).left.bound = 2;
  CHECK(rejects(SealErrorK::factory,
    [&] { (void)seal_kernel_plan(non_key_simple); }));

  DecodedKernelPlan unknown_view = decoded;
  join3(unknown_view).left.view = static_cast<ProbePlan::View>(99);
  CHECK(rejects(SealErrorK::capability,
    [&] { (void)seal_kernel_plan(unknown_view); }));

  DecodedKernelPlan wrong_cycle = decoded;
  join3(wrong_cycle).left.regs.back() = 1;
  CHECK(rejects(SealErrorK::dataflow,
    [&] { (void)seal_kernel_plan(wrong_cycle); }));

  DecodedKernelPlan unbound_prefix = decoded;
  join3(unbound_prefix).left.regs[0] = 2;
  CHECK(rejects(SealErrorK::bound_prefix,
    [&] { (void)seal_kernel_plan(unbound_prefix); }));

  DecodedKernelPlan full_with_delta = decoded;
  join3(full_with_delta).left.view = ProbePlan::View::full;
  CHECK(rejects(SealErrorK::ordering,
    [&] { (void)seal_kernel_plan(full_with_delta); }));

  DecodedKernelPlan mismatched_delta = decoded;
  mismatched_delta.bindings[1].shape.delta_orders.push_back({1, 0});
  join3(mismatched_delta).left.delta_order = {1, 0};
  CHECK(rejects(SealErrorK::ordering,
    [&] { (void)seal_kernel_plan(mismatched_delta); }));

  DecodedKernelPlan missing_requisition = decoded;
  missing_requisition.bindings[1].shape.delta_orders.clear();
  CHECK(rejects(SealErrorK::index_requisition,
    [&] { (void)seal_kernel_plan(missing_requisition); }));

  Database missing_delta(1);
  for (const std::string& name : {"driver", "left", "right", "out"})
  {
    missing_delta.addRelation(name, 2);
    missing_delta.getRelation(name)->addIndex<2>({0, 1}, false);
  }
  CHECK(rejects(SealErrorK::binding,
    [&] { (void)bind_kernel_plan(sealed, missing_delta); }));

  const std::string short_arm = replace_once(
    text,
    "(new (rel 1) (0 1) 1 (0 1) (r 0) (r 2))",
    "(new (rel 1) (0 1) 1 (0 1))");
  CHECK([&] {
    try { (void)parse_kernel_plan(short_arm); }
    catch (const PlanParseError& error) {
      return error.kind() == ParseErrorK::syntax;
    }
    return false;
  }());
  return true;
}

bool test_map_cursor_k0_native_differential()
{
  const std::vector<u16> unary{0};
  const std::vector<u16> physical{1, 0, 2};
  const std::vector<u16> order3{0, 1, 2};
  const std::vector<RelationShape> shapes{
    {1, {unary}},
    {3, {physical}, RelationK::lattice},
    {3, {order3}}
  };
  auto driver = make_relation("map-driver", 1, {unary});
  auto lattice = make_lattice_relation("map-lattice", 3, {physical});
  auto output = make_relation("map-output", 3, {order3});
  load_delta(driver.get(), {{7}});
  insert_lattice3(lattice.get(), physical, {10, 100, 1000});
  insert_lattice3(lattice.get(), physical, {11, 100, 1100});
  insert_lattice3(lattice.get(), physical, {12, 200, 1200});

  RulePlan plan{
    87, 0, "join-lat-k0", 4, {},
    {DriverK::scan_delta, 0, {}, 0, {0}},
    {ProbePlan{1, physical, 0, {1, 2, 3},
               ProbePlan::View::full, {}, true}},
    {EmitPlan{2, order3, {1, 2, 3}}}
  };
  BoundRule bound(seal_rule(plan, shapes),
                  {driver.get(), lattice.get(), output.get()});
  struct MapDebug final : DebugSink
  {
    std::vector<Proof> proofs;
    DebugAction observe(const Event& event, const DebugView& view) override
    {
      if (event.kind == EventK::emit) proofs.push_back(view.proof());
      return DebugAction::continue_;
    }
  } debug;
  debug.mask = event_bit(EventK::emit);

  std::vector<std::vector<u64>> actual;
  u64 fires = 0;
  size_t pauses = 0;
  for (u16 bucket = 0; bucket < bound.task_count(); ++bucket)
  {
    auto task = bound.make_task(bucket, &debug);
    u64 cursor_budget = 0;
    while (!task->done())
    {
      const StopReason why = task->run_observed(3, cursor_budget);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
      if (why == StopReason::cursor)
      {
        ++pauses;
        cursor_budget = 1;
      }
      if (why != StopReason::complete) task = task->continuation();
    }
    fires += task->result().fires;
    actual.insert(actual.end(), task->result().outputs.begin(),
                  task->result().outputs.end());
  }

  std::vector<std::vector<u64>> expected;
  join_all_lat<2>(lattice->getIndex(physical, false),
    [&](const std::array<u64, 2>& key, u64 value) {
      expected.push_back({key[0], key[1], value});
    });
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  CHECK(actual == expected);
  CHECK(fires == expected.size() && fires == 3);
  CHECK(pauses != 0);
  CHECK(debug.proofs.size() == expected.size());
  for (const Proof& proof : debug.proofs)
  {
    CHECK(proof.premises.size() == 1);
    CHECK(proof.premises[0].size() == 3);
    CHECK(std::find(expected.begin(), expected.end(), proof.premises[0])
          != expected.end());
  }

  u64 regs[1]{0};
  auto nonempty = make_map_filter_cursor(
    3, lattice->getIndex(physical, false), {}, 0, FilterK::absent);
  nonempty->open(regs);
  WorkBudget one{1};
  CHECK(nonempty->next(regs, one) == CursorResult::exhausted);
  CHECK(!(absent_probe_lat<2, 0>(lattice->getIndex(physical, false), {})));

  auto empty = make_lattice_relation("empty-map", 3, {physical});
  auto absent = make_map_filter_cursor(
    3, empty->getIndex(physical, false), {}, 0, FilterK::absent);
  absent->open(regs);
  WorkBudget another{1};
  CHECK(absent->next(regs, another) == CursorResult::match);
  CHECK((absent_probe_lat<2, 0>(empty->getIndex(physical, false), {})));
  return true;
}

bool test_full_view_k0_cursor_native_differential()
{
  const std::vector<u16> unary{0};
  const std::vector<u16> reverse{1, 0};
  const std::vector<u16> nominal{0, 1};
  const std::vector<RelationShape> shapes{
    {1, {unary}}, {2, {reverse}}, {2, {nominal}}
  };
  auto driver = make_relation("k0-driver", 1, {unary});
  auto lookup = make_relation("k0-lookup", 2, {reverse});
  auto output = make_relation("k0-output", 2, {nominal});
  load_delta(driver.get(), {{100}, {200}});
  insert_nominal(lookup.get(), {1, 10});
  insert_nominal(lookup.get(), {2, 20});
  insert_nominal(lookup.get(), {3, 30});

  RulePlan plan{
    91, 0, "join-full-k0", 3, {},
    {DriverK::scan_delta, 0, {}, 0, {0}},
    {ProbePlan{1, reverse, 0, {1, 2}}},
    {EmitPlan{2, nominal, {2, 1}}}
  };
  BoundRule bound(seal_rule(plan, shapes),
                  {driver.get(), lookup.get(), output.get()});
  struct K0Debug final : DebugSink
  {
    std::vector<Proof> proofs;
    DebugAction observe(const Event& event, const DebugView& view) override
    {
      if (event.kind == EventK::emit) proofs.push_back(view.proof());
      return DebugAction::continue_;
    }
  } debug;
  debug.mask = event_bit(EventK::emit);

  std::vector<std::vector<u64>> actual;
  u64 fires = 0;
  size_t pauses = 0;
  for (u16 bucket = 0; bucket < bound.task_count(); ++bucket)
  {
    auto task = bound.make_task(bucket, &debug);
    u64 cursor_budget = 0;
    while (!task->done())
    {
      const StopReason why = task->run_observed(3, cursor_budget);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
      if (why == StopReason::cursor)
      {
        ++pauses;
        cursor_budget = 1;
      }
      if (why != StopReason::complete) task = task->continuation();
    }
    fires += task->result().fires;
    actual.insert(actual.end(), task->result().outputs.begin(),
                  task->result().outputs.end());
  }

  std::vector<std::vector<u64>> one_scan;
  join_all<2>(lookup->getIndex(reverse, false),
    [&](const std::array<u64, 2>& physical) {
      one_scan.push_back({physical[1], physical[0]});
    });
  std::vector<std::vector<u64>> expected = one_scan;
  expected.insert(expected.end(), one_scan.begin(), one_scan.end());
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  CHECK(actual == expected);
  CHECK(fires == expected.size() && fires == 6);
  CHECK(pauses != 0);
  CHECK(debug.proofs.size() == expected.size());
  CHECK(std::all_of(debug.proofs.begin(), debug.proofs.end(),
                    [](const Proof& proof) {
                      return proof.premises.size() == 1
                          && proof.premises[0].size() == 2;
                    }));
  return true;
}

bool test_parsed_map_probes_and_typed_refusals()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor normal) "
    "(relations "
      "(rel 0 (relation driver 1 (0))) "
      "(rel 1 (lattice best 2 (min int) #f (0 1))) "
      "(rel 2 (relation found 2 (0 1))) "
      "(rel 3 (relation missing 1 (0)))) "
    "(attachments) (constants) (prims) (dynamic found missing) "
    "(rules "
      "(rule-def (rid 88) (variant \"join-lat#0\") (nregs 2) (pre) "
        "(driver (scan (rel 0) (r 0))) "
        "(body (join-lat (rel 1) (0 1) 1 (r 0) (r 1))) "
        "(head (emit (rel 2) (0 1) (r 0) (r 1)))) "
      "(rule-def (rid 89) (variant \"absent-lat#1\") (nregs 1) (pre) "
        "(driver (scan (rel 0) (r 0))) "
        "(body (absent-lat (rel 1) (0 1) 1 (r 0))) "
        "(head (emit (rel 3) (0) (r 0)))) "
      "(rule-def (rid 90) (variant \"pre-absent-lat#2\") (nregs 1) "
        "(pre (absent-lat (rel 1) (0 1) 0)) "
        "(driver (scan (rel 0) (r 0))) (body) "
        "(head (emit (rel 3) (0) (r 0))))) "
    "(meta))";

  const DecodedKernelPlan decoded = parse_kernel_plan(text);
  CHECK(decoded.rules.size() == 3);
  const auto& join = std::get<ProbePlan>(decoded.rules[0].plan.body[0]);
  const auto& absent = std::get<FilterPlan>(decoded.rules[1].plan.body[0]);
  CHECK(join.lattice && join.bound == 1);
  CHECK(absent.lattice && absent.kind == FilterK::absent);
  CHECK(std::get<FilterPlan>(decoded.rules[2].plan.preops[0]).lattice);

  Database db(1);
  db.addRelation("driver", 1);
  db.addRelation("best", 2);
  db.addRelation("found", 2);
  db.addRelation("missing", 1);
  Relation* driver = db.getRelation("driver");
  Relation* lattice = db.getRelation("best");
  Relation* found = db.getRelation("found");
  Relation* missing = db.getRelation("missing");
  driver->addIndex<1>({0}, false);
  lattice->setLattice(LAT_MIN, false, 0, false, 0, "min-int");
  lattice->addMapIndex<2>({0, 1});
  found->addIndex<2>({0, 1}, false);
  missing->addIndex<1>({0}, false);
  load_delta(driver, {{1}, {2}, {3}});
  insert_lattice2(lattice, 1, 101);
  insert_lattice2(lattice, 2, 202);

  const SealedKernelPlan sealed = seal_kernel_plan(decoded);
  CHECK(sealed.rules.size() == 3);
  const auto rules = bind_kernel_plan(sealed, db);
  std::vector<std::vector<u64>> actual_found, actual_missing;
  std::array<u64, 3> fires{};
  size_t pauses = 0;
  for (size_t rule_index = 0; rule_index < rules.size(); ++rule_index)
  for (u16 bucket = 0; bucket < rules[rule_index]->task_count(); ++bucket)
  {
    auto task = rules[rule_index]->make_task(bucket);
    u64 cursor_budget = 0;
    while (!task->done())
    {
      const StopReason why = task->run_fast(3, cursor_budget);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
      if (why == StopReason::cursor)
      {
        ++pauses;
        cursor_budget = 1;
      }
      if (why != StopReason::complete) task = task->continuation();
    }
    fires[rule_index] += task->result().fires;
    auto& rows = rule_index == 0 ? actual_found : actual_missing;
    rows.insert(rows.end(), task->result().outputs.begin(),
                task->result().outputs.end());
  }

  std::vector<std::vector<u64>> native_found, native_missing;
  for (u64 key : {u64{1}, u64{2}, u64{3}})
  {
    join_probe_lat<1, 1>(lattice->getIndex({0, 1}, false), {key},
      [&](const std::array<u64, 1>& match, u64 value) {
        native_found.push_back({match[0], value});
      });
    if (absent_probe_lat<1, 1>(lattice->getIndex({0, 1}, false), {key}))
      native_missing.push_back({key});
  }
  std::sort(actual_found.begin(), actual_found.end());
  std::sort(actual_missing.begin(), actual_missing.end());
  CHECK(actual_found == native_found);
  CHECK(actual_missing == native_missing);
  CHECK(fires == (std::array<u64, 3>{2, 1, 0}));
  CHECK(pauses != 0);

  for (size_t rule_index = 0; rule_index < rules.size(); ++rule_index)
  for (u16 bucket = 0; bucket < rules[rule_index]->task_count(); ++bucket)
  {
    auto execution = rules[rule_index]->make_execution(&db, bucket);
    while (!execution->machine->done())
      (void)execution->machine->run_fast(3, 1);
    execution->flush();
  }
  found->finalizeBatches();
  missing->finalizeBatches();
  CHECK(nominal_delta_rows(found) == native_found);
  CHECK(nominal_delta_rows(missing) == native_missing);

  const auto rejects = [](SealErrorK kind, auto&& thunk) {
    try { thunk(); }
    catch (const SealError& error) { return error.kind() == kind; }
    return false;
  };
  const auto probe = [](DecodedKernelPlan& plan) -> ProbePlan& {
    return std::get<ProbePlan>(plan.rules[0].plan.body[0]);
  };
  const auto filter = [](DecodedKernelPlan& plan) -> FilterPlan& {
    return std::get<FilterPlan>(plan.rules[1].plan.body[0]);
  };

  DecodedKernelPlan plain_probe = decoded;
  plain_probe.bindings[1].shape.kind = RelationK::plain;
  CHECK(rejects(SealErrorK::relation_kind,
    [&] { (void)seal_kernel_plan(plain_probe); }));

  DecodedKernelPlan set_probe = decoded;
  probe(set_probe).lattice = false;
  CHECK(rejects(SealErrorK::relation_kind,
    [&] { (void)seal_kernel_plan(set_probe); }));

  DecodedKernelPlan payload_not_last = decoded;
  payload_not_last.bindings[1].shape.full_orders.push_back({1, 0});
  probe(payload_not_last).order = {1, 0};
  CHECK(rejects(SealErrorK::ordering,
    [&] { (void)seal_kernel_plan(payload_not_last); }));

  DecodedKernelPlan wide_prefix = decoded;
  probe(wide_prefix).bound = 2;
  CHECK(rejects(SealErrorK::factory,
    [&] { (void)seal_kernel_plan(wide_prefix); }));

  DecodedKernelPlan short_regs = decoded;
  probe(short_regs).regs.pop_back();
  CHECK(rejects(SealErrorK::relation_arity,
    [&] { (void)seal_kernel_plan(short_regs); }));

  DecodedKernelPlan unbound_prefix = decoded;
  probe(unbound_prefix).regs[0] = 1;
  CHECK(rejects(SealErrorK::bound_prefix,
    [&] { (void)seal_kernel_plan(unbound_prefix); }));

  DecodedKernelPlan assigned_payload = decoded;
  probe(assigned_payload).regs[1] = 0;
  CHECK(rejects(SealErrorK::dataflow,
    [&] { (void)seal_kernel_plan(assigned_payload); }));

  DecodedKernelPlan plain_filter = decoded;
  filter(plain_filter).relation = 0;
  CHECK(rejects(SealErrorK::relation_kind,
    [&] { (void)seal_kernel_plan(plain_filter); }));

  DecodedKernelPlan bad_filter_prefix = decoded;
  filter(bad_filter_prefix).bound = 2;
  filter(bad_filter_prefix).regs.push_back(0);
  CHECK(rejects(SealErrorK::factory,
    [&] { (void)seal_kernel_plan(bad_filter_prefix); }));

  Database missing_map(1);
  missing_map.addRelation("driver", 1);
  missing_map.addRelation("best", 2);
  missing_map.addRelation("found", 2);
  missing_map.addRelation("missing", 1);
  missing_map.getRelation("driver")->addIndex<1>({0}, false);
  missing_map.getRelation("best")->setLattice(
    LAT_MIN, false, 0, false, 0, "min-int");
  missing_map.getRelation("found")->addIndex<2>({0, 1}, false);
  missing_map.getRelation("missing")->addIndex<1>({0}, false);
  CHECK(rejects(SealErrorK::binding,
    [&] { (void)bind_kernel_plan(sealed, missing_map); }));

  Database wrong_map(1);
  wrong_map.addRelation("driver", 1);
  wrong_map.addRelation("best", 2);
  wrong_map.addRelation("found", 2);
  wrong_map.addRelation("missing", 1);
  wrong_map.getRelation("driver")->addIndex<1>({0}, false);
  wrong_map.getRelation("best")->setLattice(
    LAT_MIN, false, 0, false, 0, "min-int");
  wrong_map.getRelation("best")->addIndex<2>({0, 1}, false);
  wrong_map.getRelation("found")->addIndex<2>({0, 1}, false);
  wrong_map.getRelation("missing")->addIndex<1>({0}, false);
  CHECK(rejects(SealErrorK::binding,
    [&] { (void)bind_kernel_plan(sealed, wrong_map); }));

  const std::string short_join = replace_once(
    text, "(join-lat (rel 1) (0 1) 1 (r 0) (r 1))",
          "(join-lat (rel 1) (0 1) 1)");
  CHECK([&] {
    try { (void)parse_kernel_plan(short_join); }
    catch (const PlanParseError& error) {
      return error.kind() == ParseErrorK::syntax;
    }
    return false;
  }());
  return true;
}

bool test_catalog_query_payload_parse_seal_bind()
{
  std::ifstream input("tests/data/q1-catalog-query.plan", std::ios::binary);
  CHECK(input.good());
  const std::string payload{
    std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>()};

  const q::DecodedPlan decoded = q::parse_plan(payload);
  CHECK(decoded.abi == 1);
  CHECK(decoded.boundary_key == "boundary/7" && decoded.generation == 42);
  CHECK(decoded.bindings.size() == 1);
  CHECK(decoded.bindings[0].name == "edge");
  CHECK(decoded.bindings[0].version_key == "version/edge");
  CHECK(decoded.bindings[0].tuple_count == 6);
  CHECK(decoded.bindings[0].shape.arity == 2);
  CHECK(decoded.bindings[0].shape.full_orders ==
        (std::vector<std::vector<u16>>{{0, 1}, {1, 0}}));
  CHECK(decoded.plan.nregs == 3 && decoded.plan.literals.size() == 1);
  CHECK(decoded.plan.driver.relation == 0);
  CHECK(decoded.plan.driver.order.empty());
  CHECK(decoded.plan.driver.regs == (std::vector<u16>{0, 2}));
  CHECK(decoded.plan.body.size() == 1);
  CHECK(std::get<EqPlan>(decoded.plan.body[0]).left == 2);
  CHECK(decoded.plan.project == (std::vector<u16>{0}));

  const q::SealedRequest sealed = q::seal(decoded);
  CHECK(sealed.boundary_key == decoded.boundary_key);
  CHECK(sealed.generation == decoded.generation);

  Database db(1);
  db.planVersionKey("edge", "version/edge");
  db.addRelation("edge", 2);
  Relation* edge = db.getRelation("edge");
  edge->addIndex<2>({0, 1}, false);
  edge->addIndex<2>({1, 0}, false);
  for (const std::array<u64, 2>& row : {
         std::array<u64, 2>{s32_encode(1), s32_encode(2)},
         {s32_encode(2), s32_encode(2)},
         {s32_encode(3), s32_encode(4)},
         {s32_encode(4), s32_encode(2)},
         {s32_encode(5), s32_encode(7)},
         {s32_encode(6), s32_encode(2)}})
    edge->insertTupleAllIndices(row.data());

  auto bound = q::bind(sealed, db);
  q::Context context(db, bound);
  std::vector<std::vector<u64>> actual;
  while (context.status() != q::Status::complete)
  {
    const q::Page page = context.next(2, 4, 2);
    actual.insert(actual.end(), page.rows.begin(), page.rows.end());
  }
  std::sort(actual.begin(), actual.end());
  CHECK(actual ==
        (std::vector<std::vector<u64>>{
          {s32_encode(1)}, {s32_encode(2)},
          {s32_encode(4)}, {s32_encode(6)}}));

  const auto rejects = [](q::ErrorK kind, auto&& thunk) {
    try { thunk(); }
    catch (const q::Error& error) { return error.kind() == kind; }
    return false;
  };
  CHECK(rejects(q::ErrorK::parse, [&] {
    (void)q::parse_plan(replace_once(payload, "(rel 0", "(rel 1"));
  }));
  CHECK(rejects(q::ErrorK::plan, [&] {
    (void)q::seal(q::parse_plan(
      replace_once(payload, "(abi 1)", "(abi 2)")));
  }));

  // The typed builder resolves only VersionKey. A same-named runtime relation
  // with another identity cannot satisfy the serialized catalog binding.
  Database wrong_version(1);
  wrong_version.addRelation("edge", 2);
  wrong_version.getRelation("edge")->addIndex<2>({0, 1}, false);
  wrong_version.getRelation("edge")->addIndex<2>({1, 0}, false);
  CHECK(rejects(q::ErrorK::binding,
                [&] { (void)q::bind(sealed, wrong_version); }));
  return true;
}

bool test_query_context_r2_modes_pagination_and_hygiene()
{
  const std::vector<u16> order{0, 1};
  const std::vector<RelationShape> shapes{{2, {order}}, {2, {order}}};
  Database db(1);
  db.addRelation("edge", 2);
  db.addRelation("label", 2);
  Relation* edge = db.getRelation("edge");
  Relation* label = db.getRelation("label");
  edge->addIndex<2>(order, false);
  label->addIndex<2>(order, false);

  for (const auto& row : std::vector<std::array<u64, 2>>{
         {1, 2}, {2, 3}, {2, 4}, {3, 5}, {4, 5}, {8, 9}})
    edge->insertTupleAllIndices(row.data());
  const u64 known = db.encodeString("known");
  const u64 other = db.encodeString("other");
  const u64 known_big = db.encodeIntLiteral("2147483648");
  const std::array<u64, 2> sequence_values{s32_encode(7), s32_encode(8)};
  const u64 known_sequence = db.sequences()->build(
    sequence_values.data(), sequence_values.size());
  for (const auto& row : std::vector<std::array<u64, 2>>{
         {1, known}, {2, other}, {3, known}, {4, known_big},
         {5, known_sequence}, {6, s32_encode(3)}})
    label->insertTupleAllIndices(row.data());

  const auto heap_before = db.queryHeapState();
  const PendingError pending_before = db.currentPendingError();
  const auto edge_before = nominal_index_rows(edge, order);
  const auto label_before = nominal_index_rows(label, order);

  q::Plan rows;
  rows.nregs = 3;
  rows.driver = {0, order, {0, 1}};
  rows.body.push_back(ProbePlan{0, order, 1, {1, 2}});
  rows.project = {0, 2};
  rows.mode = q::Mode::rows;
  const q::SealedPlan sealed_rows = q::seal(rows, shapes);
  auto bound_rows = q::bind(sealed_rows, db, {edge, label});
  CHECK(bound_rows->explain().find("(mode rows)") != std::string::npos);
  CHECK(bound_rows->explain().find("driver scan-full") != std::string::npos);
  CHECK(bound_rows->explain().find("(sink yield)") != std::string::npos);
  CHECK(bound_rows->explain().find("(degraded no)") != std::string::npos);

  std::vector<std::vector<u64>> actual;
  q::Context context(db, bound_rows, q::Admission::idle);
  // A zero cursor budget and tiny transition slice must park without losing
  // the driver or first probe position.
  q::Page first = context.next(2, 2, 0);
  CHECK(first.status == q::Status::paused);
  actual.insert(actual.end(), first.rows.begin(), first.rows.end());
  u64 pages = 0;
  for (u64 guard = 0; context.status() != q::Status::complete && guard < 1000;
       ++guard)
  {
    q::Page page = context.next(1, 3, 1);
    CHECK(page.status == q::Status::page
          || page.status == q::Status::paused
          || page.status == q::Status::complete);
    CHECK(page.rows.size() <= 1);
    if (page.status == q::Status::page) ++pages;
    actual.insert(actual.end(), page.rows.begin(), page.rows.end());
  }
  CHECK(context.status() == q::Status::complete);
  CHECK(pages != 0);
  std::sort(actual.begin(), actual.end());
  const std::vector<std::vector<u64>> expected{
    {1, 3}, {1, 4}, {2, 5}, {2, 5}};
  CHECK(actual == expected);

  const auto collect_query_rows = [&](const auto& bound) {
    q::Context query(db, bound);
    std::vector<std::vector<u64>> result;
    for (u64 guard = 0;
         query.status() != q::Status::complete && guard < 1000; ++guard)
    {
      q::Page page = query.next(2, 5, 2);
      result.insert(result.end(), page.rows.begin(), page.rows.end());
    }
    std::sort(result.begin(), result.end());
    return result;
  };

  // Q1's audited compute table binds checked, storage-neutral adapters. A
  // numeric comparison may guard rows, an immediate conversion may project a
  // value, and a partial sequence cast quietly rejects non-sequence rows.
  q::Plan guarded;
  guarded.nregs = 3;
  guarded.preloads.push_back({2, s32_encode(4)});
  guarded.driver = {1, order, {0, 1}};
  guarded.body.push_back(PrimPlan{PrimK::guard, "lt", 0, {1, 2}});
  guarded.project = {0, 1};
  auto bound_guarded = q::bind(q::seal(guarded, shapes), db, {edge, label});
  CHECK(bound_guarded->explain().find("(safe-computes 1)")
        != std::string::npos);
  CHECK(collect_query_rows(bound_guarded) ==
        (std::vector<std::vector<u64>>{{6, s32_encode(3)}}));

  q::Plan converted;
  converted.nregs = 3;
  converted.driver = {1, order, {0, 1}};
  converted.body.push_back(
    PrimPlan{PrimK::total, "tofloat", 2, {1}});
  converted.project = {0, 2};
  auto converted_rows = collect_query_rows(
    q::bind(q::seal(converted, shapes), db, {edge, label}));
  std::vector<std::vector<u64>> expected_converted{
    {4, float_encode(2147483648.0)}, {6, float_encode(3.0)}};
  std::sort(expected_converted.begin(), expected_converted.end());
  CHECK(converted_rows == expected_converted);

  q::Plan sequence_cast;
  sequence_cast.nregs = 3;
  sequence_cast.driver = {1, order, {0, 1}};
  sequence_cast.body.push_back(
    PrimPlan{PrimK::partial, "aslst", 2, {1}});
  sequence_cast.project = {0, 2};
  CHECK(collect_query_rows(
          q::bind(q::seal(sequence_cast, shapes), db, {edge, label})) ==
        (std::vector<std::vector<u64>>{{5, known_sequence}}));

  // A K=0 ordinary body probe walks every bucket of an already-materialized
  // full index. The following equality is the planner's scan-plus-filter
  // lowering when no positive prefix exists in the selected order.
  q::Plan body_scan;
  body_scan.nregs = 4;
  body_scan.driver = {1, order, {0, 1}};
  body_scan.body.push_back(ProbePlan{0, order, 0, {2, 3}});
  body_scan.body.push_back(EqPlan{3, 0});
  body_scan.project = {2, 1};
  auto bound_body_scan = q::bind(
    q::seal(body_scan, shapes), db, {edge, label});
  CHECK(bound_body_scan->explain().find("(degraded scan-plus-filter)")
        != std::string::npos);
  std::vector<std::vector<u64>> expected_body_scan{
    {1, other}, {2, known}, {2, known_big},
    {3, known_sequence}, {4, known_sequence}};
  std::sort(expected_body_scan.begin(), expected_body_scan.end());
  CHECK(collect_query_rows(bound_body_scan) == expected_body_scan);

  auto compute_cancelled = std::make_unique<q::Context>(db, bound_guarded);
  CHECK(compute_cancelled->next(1, 0, 0).status == q::Status::paused);
  compute_cancelled->cancel();
  CHECK(compute_cancelled->status() == q::Status::cancelled);

  q::Plan count = rows;
  count.mode = q::Mode::count;
  count.project.clear();
  auto bound_count = q::bind(q::seal(count, shapes), db, {edge, label});
  q::Context count_context(db, bound_count, q::Admission::boundary);
  q::Page count_page;
  do { count_page = count_context.next(0, 5, 2); }
  while (count_page.status != q::Status::complete);
  CHECK(count_page.rows.empty());
  CHECK(count_page.matched == expected.size());

  q::Plan exists = count;
  exists.mode = q::Mode::exists;
  auto bound_exists = q::bind(q::seal(exists, shapes), db, {edge, label});
  q::Context exists_context(db, bound_exists, q::Admission::mid_read);
  q::Page exists_page;
  do { exists_page = exists_context.next(0, 2, 1); }
  while (exists_page.status != q::Status::complete);
  CHECK(exists_page.rows.empty() && exists_page.matched == 1);

  // One active cursor per database. Cancellation drops only query-local VM,
  // page, and admission state, after which another query may start.
  auto cancelled = std::make_unique<q::Context>(
    db, bound_rows, q::Admission::read_complete);
  CHECK([&] {
    try { q::Context second(db, bound_rows); }
    catch (const q::Error& error) {
      return error.kind() == q::ErrorK::admission;
    }
    return false;
  }());
  cancelled->cancel();
  CHECK(cancelled->next(1, 1, 1).status == q::Status::cancelled);

  // R2 string literals resolve through the non-allocating probe. A missing
  // literal closes the query empty and remains absent from the heap.
  q::Plan labels;
  labels.nregs = 3;
  labels.literals.push_back({2, q::LiteralK::string, "known"});
  labels.driver = {1, order, {0, 1}};
  labels.body.push_back(EqPlan{1, 2});
  labels.project = {0};
  auto bound_labels = q::bind(q::seal(labels, shapes), db, {edge, label});
  q::Context label_context(db, bound_labels);
  std::vector<std::vector<u64>> label_rows;
  while (label_context.status() != q::Status::complete)
  {
    q::Page page = label_context.next(1, 5, 2);
    label_rows.insert(label_rows.end(), page.rows.begin(), page.rows.end());
  }
  std::sort(label_rows.begin(), label_rows.end());
  CHECK(label_rows == (std::vector<std::vector<u64>>{{1}, {3}}));

  u64 missing_word = 0;
  CHECK(!db.probeString("missing", missing_word));
  q::Plan missing = labels;
  missing.literals[0].text = "missing";
  auto bound_missing = q::bind(q::seal(missing, shapes), db, {edge, label});
  CHECK(!bound_missing->has_matches_possible());
  q::Context missing_context(db, bound_missing);
  CHECK(missing_context.status() == q::Status::complete);
  CHECK(missing_context.next(1, 10, 10).rows.empty());
  CHECK(!db.probeString("missing", missing_word));

  q::Plan big = labels;
  big.literals[0] = {2, q::LiteralK::integer, "2147483648"};
  auto bound_big = q::bind(q::seal(big, shapes), db, {edge, label});
  q::Context big_context(db, bound_big);
  std::vector<std::vector<u64>> big_rows;
  while (big_context.status() != q::Status::complete)
  {
    q::Page page = big_context.next(1, 5, 2);
    big_rows.insert(big_rows.end(), page.rows.begin(), page.rows.end());
  }
  CHECK(big_rows == (std::vector<std::vector<u64>>{{4}}));

  q::Plan missing_big = big;
  missing_big.literals[0].text = "2147483649";
  auto bound_missing_big = q::bind(
    q::seal(missing_big, shapes), db, {edge, label});
  CHECK(!bound_missing_big->has_matches_possible());
  q::Context missing_big_context(db, bound_missing_big);
  CHECK(missing_big_context.status() == q::Status::complete);

  const auto query_rejects = [](q::ErrorK kind, auto&& thunk) {
    try { thunk(); }
    catch (const q::Error& error) {
      if (error.kind() != kind)
        std::cerr << "unexpected query error " << q::error_class(error.kind())
                  << ": " << error.what() << '\n';
      return error.kind() == kind;
    }
    return false;
  };
  q::Plan long_literal = labels;
  long_literal.literals[0].text.assign(SEQ_BLEAF_MAX + 1, 'x');
  CHECK(query_rejects(q::ErrorK::literal,
    [&] { (void)q::seal(long_literal, shapes); }));

  q::Plan malformed_integer = big;
  malformed_integer.literals[0].text = "12nope";
  CHECK(query_rejects(q::ErrorK::literal, [&] {
    (void)q::bind(q::seal(malformed_integer, shapes), db, {edge, label});
  }));

  q::Plan unsafe = rows;
  unsafe.nregs = 4;
  // Integer/string addition can allocate an mpz or rope, so it remains
  // outside the storage-neutral query whitelist.
  unsafe.body.push_back(
    PrimPlan{PrimK::total, "_0002b", 3, {0, 1}});
  CHECK(!q::admits_primitive(std::get<PrimPlan>(unsafe.body.back())));
  CHECK(query_rejects(q::ErrorK::unsafe_compute,
    [&] { (void)q::seal(unsafe, shapes); }));
  q::Plan wrong_role = guarded;
  std::get<PrimPlan>(wrong_role.body[0]).kind = PrimK::total;
  CHECK(query_rejects(q::ErrorK::unsafe_compute,
    [&] { (void)q::seal(wrong_role, shapes); }));

  CHECK(query_rejects(q::ErrorK::admission, [&] {
    q::Context refused(db, bound_rows, q::Admission::write_or_intern);
  }));

  // A paging error is terminal for that context and must release the
  // database lease before propagating, so a fresh query can start at once.
  auto failed_page = std::make_unique<q::Context>(db, bound_rows);
  CHECK(query_rejects(q::ErrorK::pagination,
    [&] { (void)failed_page->next(0, 1, 1); }));
  CHECK(failed_page->status() == q::Status::cancelled);
  q::Context after_failed_page(db, bound_rows);
  after_failed_page.cancel();

  // A catalog may claim an order at seal, but binding still proves it is an
  // already-materialized concrete index; Q1 never builds it on demand.
  const std::vector<u16> reverse{1, 0};
  std::vector<RelationShape> claimed = shapes;
  claimed[0].full_orders.push_back(reverse);
  q::Plan unavailable = rows;
  unavailable.driver.order = reverse;
  CHECK(query_rejects(q::ErrorK::binding, [&] {
    (void)q::bind(q::seal(unavailable, claimed), db, {edge, label});
  }));

  // Empty driver order is the explicit planner request for scan-plus-filter.
  // Binding deterministically chooses an already-existing catalog order and
  // remaps its physical tuple back onto nominal query registers.
  Database fallback_db(1);
  fallback_db.addRelation("reverse-only", 2);
  Relation* reverse_only = fallback_db.getRelation("reverse-only");
  reverse_only->addIndex<2>(reverse, false);
  for (const std::array<u64, 2>& row :
       {std::array<u64, 2>{1, 10}, {2, 20}, {2, 21}, {3, 30}})
    reverse_only->insertTupleAllIndices(row.data());
  const std::vector<RelationShape> fallback_shapes{{2, {reverse}}};
  const auto fallback_rows_before = nominal_index_rows(reverse_only, reverse);
  const auto fallback_heap_before = fallback_db.queryHeapState();
  const PendingError fallback_pending_before =
    fallback_db.currentPendingError();

  q::Plan fallback;
  fallback.nregs = 3;
  fallback.preloads.push_back({2, 2});
  fallback.driver = {0, {}, {0, 1}};
  fallback.body.push_back(EqPlan{0, 2});
  fallback.project = {1};
  auto bound_fallback = q::bind(
    q::seal(fallback, fallback_shapes), fallback_db, {reverse_only});
  CHECK(bound_fallback->explain().find("(order 1 0)")
        != std::string::npos);
  CHECK(bound_fallback->explain().find("(degraded scan-plus-filter)")
        != std::string::npos);

  q::Context fallback_context(fallback_db, bound_fallback);
  std::vector<std::vector<u64>> fallback_rows;
  u64 fallback_pages = 0;
  while (fallback_context.status() != q::Status::complete)
  {
    q::Page page = fallback_context.next(1, 2, 1);
    if (page.status == q::Status::page) ++fallback_pages;
    fallback_rows.insert(
      fallback_rows.end(), page.rows.begin(), page.rows.end());
  }
  std::sort(fallback_rows.begin(), fallback_rows.end());
  CHECK(fallback_rows == (std::vector<std::vector<u64>>{{20}, {21}}));
  CHECK(fallback_pages != 0);

  q::Context fallback_cancel(fallback_db, bound_fallback);
  CHECK(fallback_cancel.next(1, 0, 0).status == q::Status::paused);
  fallback_cancel.cancel();
  CHECK(nominal_index_rows(reverse_only, reverse) == fallback_rows_before);
  CHECK(fallback_db.queryHeapState() == fallback_heap_before);
  const PendingError fallback_pending_after =
    fallback_db.currentPendingError();
  CHECK(fallback_pending_after.kind == fallback_pending_before.kind
        && fallback_pending_after.op == fallback_pending_before.op
        && fallback_pending_after.a == fallback_pending_before.a
        && fallback_pending_after.b == fallback_pending_before.b);

  // The Q1 gate: success, pagination, zero-budget pause, count/exists,
  // cancellation, missing literals, and refused queries leave every master
  // row and every interner heap exactly unchanged.
  CHECK(nominal_index_rows(edge, order) == edge_before);
  CHECK(nominal_index_rows(label, order) == label_before);
  CHECK(db.queryHeapState() == heap_before);
  const PendingError pending_after = db.currentPendingError();
  CHECK(pending_after.kind == pending_before.kind
        && pending_after.op == pending_before.op
        && pending_after.a == pending_before.a
        && pending_after.b == pending_before.b);
  return true;
}

bool test_view_and_filter_cursor_registrations()
{
  const std::vector<u16> order{0, 1};
  const RelationShape driver_shape{2, {order}};
  const RelationShape view_shape{
    2, {order}, RelationK::plain, {order}};
  const RelationShape unary_shape{1, {{0}}};
  const RelationShape output_shape{2, {order}};
  const std::vector<RelationShape> shapes{
    driver_shape, view_shape, view_shape, unary_shape,
    output_shape, output_shape, output_shape, output_shape};

  auto driver = make_relation("view-driver", 2, {order});
  auto old_view = make_relation("old-view", 2, {order});
  auto new_view = make_relation("new-view", 2, {order});
  auto allowed = std::make_unique<Relation>("allowed", 1, 0);
  allowed->initShards(1);
  allowed->addIndex<1>({0}, false);
  auto old_out = make_relation("old-out", 2, {order});
  auto new_out = make_relation("new-out", 2, {order});
  auto exists_out = make_relation("exists-out", 2, {order});
  auto absent_out = make_relation("absent-out", 2, {order});

  load_delta(driver.get(), {{100, 7}, {200, 8}});
  insert_nominal(old_view.get(), {7, 10});
  insert_nominal(old_view.get(), {7, 11});
  insert_nominal(old_view.get(), {8, 20});
  add_delta_index_rows2(old_view.get(), order, {{7, 11}});
  insert_nominal(new_view.get(), {7, 30});
  insert_nominal(new_view.get(), {7, 31});
  insert_nominal(new_view.get(), {8, 40});
  add_delta_index_rows2(new_view.get(), order, {{7, 31}, {7, 32}});
  insert_nominal(allowed.get(), {7});

  auto run = [&](RulePlan plan, Relation* output) {
    BoundRule bound(seal_rule(plan, shapes),
      {driver.get(), old_view.get(), new_view.get(), allowed.get(),
       old_out.get(), new_out.get(), exists_out.get(), absent_out.get()});
    u64 fires = 0;
    for (u16 bucket = 0; bucket < bound.task_count(); ++bucket)
    {
      auto task = bound.make_task(bucket);
      while (!task->done())
      {
        const StopReason why = task->run_fast(2, 1);
        seal_check(why == StopReason::quantum || why == StopReason::cursor
                     || why == StopReason::complete,
                   "fixture: unexpected interpreter stop");
        if (why != StopReason::complete) task = task->continuation();
      }
      fires += task->result().fires;
      bound.apply(task->result());
    }
    output->finalizeBatches();
    return fires;
  };

  const u64 old_fires = run(RulePlan{
    80, 0, "view-old#0", 3, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{1, order, 1, {1, 2}, ProbePlan::View::old, order}},
    {EmitPlan{4, order, {0, 2}}}}, old_out.get());
  const u64 new_fires = run(RulePlan{
    81, 1, "view-new#1", 3, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{2, order, 1, {1, 2}, ProbePlan::View::new_, order}},
    {EmitPlan{5, order, {0, 2}}}}, new_out.get());
  const u64 exists_fires = run(RulePlan{
    82, 2, "exists#2", 2, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {FilterPlan{FilterK::exists, 3, {0}, 1, {1}}},
    {EmitPlan{6, order, {0, 1}}}}, exists_out.get());
  const u64 absent_fires = run(RulePlan{
    83, 3, "absent#3", 2, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {FilterPlan{FilterK::absent, 3, {0}, 1, {1}}},
    {EmitPlan{7, order, {0, 1}}}}, absent_out.get());

  CHECK(old_fires == 2);
  CHECK(new_fires == 4);
  CHECK(exists_fires == 1);
  CHECK(absent_fires == 1);
  CHECK(nominal_delta_rows(old_out.get()) ==
        (std::vector<std::vector<u64>>{{100, 10}, {200, 20}}));
  CHECK(nominal_delta_rows(new_out.get()) ==
        (std::vector<std::vector<u64>>{{100, 30}, {100, 31}, {100, 32},
                                       {200, 40}}));
  CHECK(nominal_delta_rows(exists_out.get()) ==
        (std::vector<std::vector<u64>>{{100, 7}}));
  CHECK(nominal_delta_rows(absent_out.get()) ==
        (std::vector<std::vector<u64>>{{200, 8}}));

  // Differential against the generated/native helpers for this read
  // iteration, including fire multiplicity rather than final-set equality.
  std::vector<std::vector<u64>> native_old, native_new;
  join_probe_old<2, 1>(old_view->getIndex(order, false),
                       old_view->getIndex(order, true), {7, 0},
    [&](const auto& row) { native_old.push_back({100, row[1]}); });
  join_probe_new<2, 1>(new_view->getIndex(order, false),
                       new_view->getIndex(order, true), {7, 0},
    [&](const auto& row) { native_new.push_back({100, row[1]}); });
  join_probe_old<2, 1>(old_view->getIndex(order, false),
                       old_view->getIndex(order, true), {8, 0},
    [&](const auto& row) { native_old.push_back({200, row[1]}); });
  join_probe_new<2, 1>(new_view->getIndex(order, false),
                       new_view->getIndex(order, true), {8, 0},
    [&](const auto& row) { native_new.push_back({200, row[1]}); });
  std::sort(native_old.begin(), native_old.end());
  std::sort(native_new.begin(), native_new.end());
  CHECK(native_old == nominal_delta_rows(old_out.get()));
  CHECK(native_new == nominal_delta_rows(new_out.get()));
  CHECK(old_fires == native_old.size());
  CHECK(new_fires == native_new.size());
  CHECK((exists_probe<1, 1>(allowed->getIndex({0}, false), {7})));
  CHECK((absent_probe<1, 1>(allowed->getIndex({0}, false), {8})));

  // K=0 view scans and absence are part of these registrations even though
  // ordinary full-view K=0 joins remain a later roadmap group.
  auto old_all = make_set_view_cursor(
    2, old_view->getIndex(order, false), old_view->getIndex(order, true),
    {0, 1}, 0, ProbePlan::View::old);
  u64 regs[2]{0, 0};
  old_all->open(regs);
  std::vector<std::vector<u64>> all_rows;
  for (;;)
  {
    WorkBudget budget{1};
    const CursorResult result = old_all->next(regs, budget);
    if (result == CursorResult::paused) continue;
    if (result == CursorResult::exhausted) break;
    all_rows.push_back({regs[0], regs[1]});
  }
  std::sort(all_rows.begin(), all_rows.end());
  CHECK(all_rows == (std::vector<std::vector<u64>>{{7, 10}, {8, 20}}));
  auto absent_all = make_set_filter_cursor(
    1, allowed->getIndex({0}, false), {}, 0, FilterK::absent);
  absent_all->open(regs);
  WorkBudget one{1};
  CHECK(absent_all->next(regs, one) == CursorResult::exhausted);
  auto empty = std::make_unique<Relation>("empty", 1, 0);
  empty->initShards(1);
  empty->addIndex<1>({0}, false);
  auto absent_empty = make_set_filter_cursor(
    1, empty->getIndex({0}, false), {}, 0, FilterK::absent);
  absent_empty->open(regs);
  WorkBudget another{1};
  CHECK(absent_empty->next(regs, another) == CursorResult::match);
  return true;
}

static std::vector<std::vector<u64>> nominal_index_rows(
  Relation* rel, const std::vector<u16>& order)
{
  std::vector<u16> inverse(order.size(), 0);
  for (u16 i = 0; i < order.size(); ++i) inverse[order[i]] = i;
  std::vector<std::vector<u64>> rows;
  Index** index = rel->getIndex(order, false);
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
    index[bucket]->forEach([&](const u64* tuple) {
      std::vector<u64> nominal(order.size());
      for (u16 column = 0; column < order.size(); ++column)
        nominal[column] = tuple[inverse[column]];
      rows.push_back(std::move(nominal));
    });
  std::sort(rows.begin(), rows.end());
  return rows;
}

bool test_parsed_view_and_filter_forms()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor normal) "
    "(relations "
      "(rel 0 (relation driver 2 (0 1))) "
      "(rel 1 (relation view 2 (0 1) (delta 0 1))) "
      "(rel 2 (relation keys 1 (0))) "
      "(rel 3 (relation out 2 (0 1)))) "
    "(attachments) (constants) (prims) (dynamic out) "
    "(rules "
      "(rule-def (rid 10) (variant \"old#0\") (nregs 3) (pre) "
        "(driver (scan (rel 0) (r 0) (r 1))) "
        "(body (join-old (rel 1) (0 1) 1 (0 1) (r 1) (r 2))) "
        "(head (emit (rel 3) (0 1) (r 0) (r 2)))) "
      "(rule-def (rid 11) (variant \"new#1\") (nregs 3) (pre) "
        "(driver (scan (rel 0) (r 0) (r 1))) "
        "(body (join-new (rel 1) (0 1) 1 (0 1) (r 1) (r 2))) "
        "(head (emit (rel 3) (0 1) (r 0) (r 2)))) "
      "(rule-def (rid 12) (variant \"exists#2\") (nregs 2) (pre) "
        "(driver (scan (rel 0) (r 0) (r 1))) "
        "(body (exists (rel 2) (0) 1 (r 1))) "
        "(head (emit (rel 3) (0 1) (r 0) (r 1)))) "
      "(rule-def (rid 13) (variant \"absent#3\") (nregs 2) "
        "(pre (absent (rel 2) (0) 0)) "
        "(driver (scan (rel 0) (r 0) (r 1))) "
        "(body (absent (rel 2) (0) 1 (r 1))) "
        "(head (emit (rel 3) (0 1) (r 0) (r 1))))) "
    "(meta))";

  const DecodedKernelPlan decoded = parse_kernel_plan(text);
  CHECK(decoded.bindings[1].shape.delta_orders ==
        (std::vector<std::vector<u16>>{{0, 1}}));
  CHECK(decoded.rules.size() == 4);
  const auto& old = std::get<ProbePlan>(decoded.rules[0].plan.body[0]);
  const auto& next = std::get<ProbePlan>(decoded.rules[1].plan.body[0]);
  CHECK(old.view == ProbePlan::View::old && old.delta_order ==
        (std::vector<u16>{0, 1}));
  CHECK(next.view == ProbePlan::View::new_);
  CHECK(std::get<FilterPlan>(decoded.rules[2].plan.body[0]).kind
        == FilterK::exists);
  CHECK(decoded.rules[3].plan.prefilters.size() == 1);
  CHECK(std::get<FilterPlan>(decoded.rules[3].plan.body[0]).kind
        == FilterK::absent);
  const SealedKernelPlan sealed = seal_kernel_plan(decoded);
  CHECK(sealed.rules.size() == 4);
  CHECK(sealed.rules[0].cursors.size() == 1);
  CHECK(sealed.rules[3].prefilters.size() == 1);
  return true;
}

bool test_parsed_primitives_letp_tycheck_native_differential()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor normal) "
    "(relations "
      "(rel 0 (relation driver 7 (0 1 2 3 4 5 6))) "
      "(rel 1 (relation out 2 (0 1))) "
      "(rel 2 (struct malformed_deduction 5 "
        "(1 2 3 4 0) (0 1 2 3 4)))) "
    "(attachments) "
    "(constants (k 0 one 1) (k 1 two 2)) "
    "(prims _0002b cget gt) (dynamic out malformed_deduction) "
    "(rules "
      "(rule-def (rid 90) (variant \"delta:driver#0\") (nregs 14) "
        "(pre "
          "(let (r 10) (k 0)) "
          "(let (r 11) (k 1)) "
          "(let (r 12) (prim _0002b (r 10) (r 11))) "
          "(cmp gt (r 12) (r 11))) "
        "(driver (scan (rel 0) (r 0) (r 1) (r 2) (r 3) "
                                  "(r 4) (r 5) (r 6))) "
        "(body "
          "(let (r 7) (prim _0002b (r 0) (r 1))) "
          "(cmp gt (r 7) (r 0)) "
          "(letp (r 8) (prim cget (r 2) (r 3))) "
          "(let (r 13) (r 7)) "
          "(eq (r 13) (r 7))) "
        "(head "
          "(tycheck (r 8) (accept int) (r 4) (r 5) (r 6) "
                   "(1 2 3 4 0)) "
          "(let (r 9) (prim _0002b (r 13) (r 8))) "
          "(emit (rel 1) (0 1) (r 0) (r 9))))) "
    "(meta (rule-meta (rid 90) (source \"t2b-prims.slog:1\"))))";

  const DecodedKernelPlan decoded = parse_kernel_plan(text);
  CHECK(decoded.primitives ==
        (std::vector<std::string>{"_0002b", "cget", "gt"}));
  CHECK(decoded.rules[0].plan.preops.size() == 2);
  CHECK(std::holds_alternative<PrimPlan>(decoded.rules[0].plan.preops[0]));
  CHECK(decoded.rules[0].plan.body.size() == 5);
  CHECK(std::get<PrimPlan>(decoded.rules[0].plan.body[2]).kind
        == PrimK::partial);
  CHECK(decoded.rules[0].plan.head_prefix.size() == 2);
  CHECK(std::holds_alternative<TycheckPlan>(
          decoded.rules[0].plan.head_prefix[0]));

  Database db(1);
  db.addRelation("driver", 7);
  db.addRelation("out", 2);
  db.addStruct("malformed_deduction", 5);
  Relation* driver = db.getRelation("driver");
  Relation* output = db.getRelation("out");
  Relation* malformed = db.getRelation("malformed_deduction");
  driver->addIndex<7>({0, 1, 2, 3, 4, 5, 6}, false);
  output->addIndex<2>({0, 1}, false);
  malformed->addIndex<5>({1, 2, 3, 4, 0}, false);
  malformed->addIndex<5>({0, 1, 2, 3, 4}, false);

  const u64 key = s32_encode(7);
  const u64 empty = _prim_cmap(&db);
  const u64 int_map = _prim_cput(&db, empty, key, s32_encode(5));
  const u64 bad_value = db.encodeString("not-an-int");
  const u64 string_map = _prim_cput(&db, empty, key, bad_value);
  const std::vector<std::vector<u64>> driver_rows{
    {s32_encode(10), s32_encode(2), int_map, key,
     s32_encode(90), s32_encode(3), s32_encode(1)},
    {s32_encode(20), s32_encode(3), empty, key,
     s32_encode(90), s32_encode(3), s32_encode(1)},
    {s32_encode(30), s32_encode(4), string_map, key,
     s32_encode(90), s32_encode(3), s32_encode(1)}
  };
  load_delta(driver, driver_rows);

  // The reference path is the native emitter's straight-line control flow,
  // calling the exact same shared primitive functions and applying its
  // fire-before-tycheck ordering.
  u64 native_fires = 0;
  std::vector<std::vector<u64>> native_out;
  std::vector<std::vector<u64>> native_malformed;
  const u64 pre_sum = _prim__0002b(&db, s32_encode(1), s32_encode(2));
  CHECK(_prim_gt(&db, pre_sum, s32_encode(2)) != 0);
  for (const auto& row : driver_rows)
  {
    const u64 sum = _prim__0002b(&db, row[0], row[1]);
    if (_prim_gt(&db, sum, row[0]) == 0) continue;
    bool ok = true;
    const u64 found = _prim_cget(&db, row[2], row[3], &ok);
    if (!ok) continue;
    ++native_fires;
    if (!is_int(found))
    {
      native_malformed.push_back({row[4], row[5], row[6], found});
      continue;
    }
    native_out.push_back({row[0], _prim__0002b(&db, sum, found)});
  }

  const SealedKernelPlan sealed = seal_kernel_plan(decoded, &db);
  CHECK(sealed.rules[0].program.source == "t2b-prims.slog:1");
  CHECK(sealed.rules[0].program.ops.size() == 9);
  CHECK(sealed.rules[0].program.ops[0].kind == OpK::prim);
  CHECK(sealed.rules[0].program.ops[1].kind == OpK::guard_cmp);
  CHECK(sealed.rules[0].program.ops[2].kind == OpK::prim_partial);
  CHECK(sealed.rules[0].program.ops[5].kind == OpK::fire);
  CHECK(sealed.rules[0].program.ops[6].kind == OpK::tycheck);
  CHECK(sealed.rules[0].effects.size() == 1);
  const auto rules = bind_kernel_plan(sealed, db);
  CHECK(rules.size() == 1);

  u64 interp_fires = 0;
  std::vector<std::vector<u64>> interp_out;
  std::vector<std::vector<u64>> interp_malformed;
  for (u16 bucket = 0; bucket < rules[0]->task_count(); ++bucket)
  {
    auto task = rules[0]->make_task(bucket);
    while (!task->done())
    {
      const StopReason why = task->run_fast(2, 1);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
      if (why != StopReason::complete) task = task->continuation();
    }
    interp_fires += task->result().fires;
    for (size_t i = 0; i < task->result().outputs.size(); ++i)
    {
      if (task->result().output_sinks[i] == 0)
        interp_out.push_back(task->result().outputs[i]);
      else if (task->result().output_sinks[i] == 1)
        interp_malformed.push_back(task->result().outputs[i]);
      else
        return fail("unexpected T2-B sink port");
    }
  }
  std::sort(native_out.begin(), native_out.end());
  std::sort(native_malformed.begin(), native_malformed.end());
  std::sort(interp_out.begin(), interp_out.end());
  std::sort(interp_malformed.begin(), interp_malformed.end());
  CHECK(interp_fires == native_fires && native_fires == 2);
  CHECK(interp_out == native_out && interp_out.size() == 1);
  CHECK(interp_malformed == native_malformed
        && interp_malformed.size() == 1);

  // Exercise the production ordinary + struct sinks, not only captured
  // candidates. A failed letp produces neither sink; a failed tycheck emits
  // only the malformed struct fields while retaining its fire.
  for (u16 bucket = 0; bucket < rules[0]->task_count(); ++bucket)
  {
    auto execution = rules[0]->make_execution(&db, bucket);
    while (!execution->machine->done())
      (void)execution->machine->run_fast(3, 2);
    execution->flush();
  }
  output->finalizeBatches();
  malformed->finalizeBatches();
  CHECK(nominal_delta_rows(output) == native_out);
  CHECK(nominal_delta_rows(malformed) ==
        (std::vector<std::vector<u64>>{
          {0, driver_rows[2][4], driver_rows[2][5],
           driver_rows[2][6], bad_value}}));

  const auto rejects_kind = [](SealErrorK kind, auto&& thunk) {
    try { thunk(); }
    catch (const SealError& error) { return error.kind() == kind; }
    return false;
  };

  DecodedKernelPlan bad_arity = decoded;
  std::get<PrimPlan>(bad_arity.rules[0].plan.body[0]).args.pop_back();
  CHECK(rejects_kind(SealErrorK::capability,
    [&] { (void)seal_kernel_plan(bad_arity, &db); }));

  DecodedKernelPlan bad_partial = decoded;
  std::get<PrimPlan>(bad_partial.rules[0].plan.body[2]).kind = PrimK::total;
  CHECK(rejects_kind(SealErrorK::capability,
    [&] { (void)seal_kernel_plan(bad_partial, &db); }));

  DecodedKernelPlan bad_comparison = decoded;
  std::get<PrimPlan>(bad_comparison.rules[0].plan.body[1]).name = "_0002b";
  CHECK(rejects_kind(SealErrorK::capability,
    [&] { (void)seal_kernel_plan(bad_comparison, &db); }));

  DecodedKernelPlan undeclared = decoded;
  undeclared.primitives.pop_back();
  CHECK(rejects_kind(SealErrorK::capability,
    [&] { (void)seal_kernel_plan(undeclared, &db); }));

  DecodedKernelPlan unknown = decoded;
  unknown.primitives.push_back("zzz");
  CHECK(rejects_kind(SealErrorK::capability,
    [&] { (void)seal_kernel_plan(unknown, &db); }));

  DecodedKernelPlan bad_accept = decoded;
  std::get<TycheckPlan>(bad_accept.rules[0].plan.head_prefix[0])
    .accepts[0].name = "bool";
  CHECK(rejects_kind(SealErrorK::capability,
    [&] { (void)seal_kernel_plan(bad_accept, &db); }));

  DecodedKernelPlan missing_malformed = decoded;
  missing_malformed.bindings[2].name = "not_malformed_deduction";
  CHECK(rejects_kind(SealErrorK::relation_slot,
    [&] { (void)seal_kernel_plan(missing_malformed, &db); }));

  DecodedKernelPlan missing_struct = decoded;
  std::get<TycheckPlan>(missing_struct.rules[0].plan.head_prefix[0])
    .accepts.push_back({TypeK::struct_, "not_a_runtime_struct"});
  const SealedKernelPlan missing_struct_sealed =
    seal_kernel_plan(missing_struct, &db);
  CHECK(rejects_kind(SealErrorK::binding,
    [&] { (void)bind_kernel_plan(missing_struct_sealed, db); }));

  // Fallible total primitives abandon only the bad row and invoke the bound
  // native error channel. This isolates the control-flow contract from the
  // error struct transport (emit_pending_error itself is shared native code).
  auto error_program = std::make_shared<Program>();
  error_program->rule_id = 91;
  error_program->variant = "primitive-error#0";
  error_program->nregs = 3;
  error_program->driver_regs = {0, 1};
  error_program->operands = {0, 1};
  error_program->source = "t2b-prims.slog:99";
  error_program->ops = {
    {OpK::prim, 0, 2, 0, 2},
    {OpK::fire},
    {OpK::emit2, 0, 0, 2}
  };
  auto error_rows =
    std::make_shared<const std::vector<std::vector<u64>>>(
      std::vector<std::vector<u64>>{
        {s32_encode(8), s32_encode(2)},
        {s32_encode(8), s32_encode(0)}});
  primitive_error_callbacks = 0;
  auto error_machine = std::make_unique<Machine>(
    error_program, std::make_unique<VectorDriverCursor>(error_rows),
    std::vector<std::unique_ptr<PrefixCursor>>{},
    std::vector<BoundSink*>{}, nullptr, true, &db,
    std::vector<BoundPrim>{resolve_primitive("_0002f")},
    std::vector<BoundTycheck>{}, &record_primitive_error);
  while (!error_machine->done())
  {
    const StopReason why = error_machine->run_observed(1, 1);
    CHECK(why == StopReason::quantum || why == StopReason::complete);
    if (why != StopReason::complete)
      error_machine = error_machine->continuation();
  }
  CHECK(error_machine->result().fires == 1);
  CHECK(error_machine->result().outputs ==
        (std::vector<std::vector<u64>>{{s32_encode(8), s32_encode(4)}}));
  CHECK(primitive_error_callbacks == 1);
  return true;
}

bool test_parsed_sidecar_scheduler_admission()
{
  // This fixture is byte-for-byte compiler/canonical-plan.rkt output from
  // bulk.slog.  In particular it contains the standard service-struct prelude;
  // only edge and node are present in this deliberately narrow runtime frame.
  const DecodedKernelPlan decoded =
    parse_kernel_plan_file("tests/data/t0-normal-set.plan");
  CHECK(decoded.abi == 1);
  CHECK(decoded.flavor == "normal");
  CHECK(decoded.bindings.size() == 14);
  CHECK(decoded.bindings[0].name == "edge");
  CHECK(decoded.bindings[2].name == "node");
  CHECK(decoded.bindings[3].shape.kind == RelationK::struct_);
  CHECK(decoded.rules.size() == 1);
  CHECK(decoded.rules[0].plan.variant == "all:edge");
  CHECK(decoded.sources.at(0) == "bulk.slog:9");

  Database db(2);
  db.addRelation("edge", 2);
  db.addRelation("node", 1);
  Relation* edge = db.getRelation("edge");
  Relation* node = db.getRelation("node");
  edge->addIndex<2>({0, 1}, false);
  node->addIndex<1>({0}, false);

  InsertBatch* input = new InsertBatch();
  for (const std::array<u64, 2>& row :
       {std::array<u64, 2>{10, 11}, {20, 21}, {10, 99}})
  {
    input->data[input->usage++] = row[0];
    input->data[input->usage++] = row[1];
  }
  edge->sendBatch(input);

  const SealedKernelPlan sealed = seal_kernel_plan(decoded, &db);
  const auto rules = bind_kernel_plan(sealed, db);
  CHECK(rules.size() == 1);

  Stratum stratum("parsed-sidecar-admission");
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
  {
    stratum.addTask(phase_write,
      new WriteTask<2>(&db, edge, {0, 1}, false, bucket));
    stratum.addTask(phase_write,
      new WriteTask<1>(&db, node, {0}, false, bucket));
    stratum.addTask(phase_intern,
      new InternTask<2>(&db, edge, {0, 1}, bucket));
    stratum.addTask(phase_intern,
      new InternTask<1>(&db, node, {0}, bucket));
  }
  rules[0]->attach(&db, &stratum);

  RunBudget budget;
  budget.max_ms = 10000;
  budget.mem_bytes = UINT64_MAX;
  budget.stop_at_boundary = true;
  RunStatus status = db.continueStratum(&stratum, budget, true, true);
  while (!status.fixpoint)
  {
    CHECK(status.where == RUN_AT_BOUNDARY);
    status = db.continueStratum(&stratum, budget, false, true);
  }
  CHECK(nominal_index_rows(node, {0}) ==
        (std::vector<std::vector<u64>>{{10}, {20}}));
  CHECK(db.fire_counts[std::make_pair(std::string("<interp-rule:0:variant:0>"),
                                      std::string("all:edge"))] == 3);
  return true;
}

bool test_shared_sexp_reader_contract()
{
  const sexp::Limits limits{1024, 32, 8};
  const sexp::SExp form = sexp::read_one(
    "(command |two words| \"line\\nvalue\" ; ignored\n (nested 7))",
    limits);
  CHECK(form.kind == sexp::SExp::K::list);
  CHECK(form.children.size() == 4);
  CHECK(form.children[0].text == "command");
  CHECK(form.children[1].text == "two words");
  CHECK(form.children[2].kind == sexp::SExp::K::string);
  CHECK(form.children[2].text == "line\nvalue");
  CHECK(form.children[3].children[0].text == "nested");

  const auto rejects = [](sexp::ReaderErrorK wanted, std::string_view text,
                          sexp::Limits reader_limits) {
    try { (void)sexp::read_one(text, reader_limits); }
    catch (const sexp::ReaderError& error) {
      return error.kind() == wanted && error.offset() <= text.size();
    }
    return false;
  };
  CHECK(rejects(sexp::ReaderErrorK::syntax, "(one) (two)", limits));
  CHECK(rejects(sexp::ReaderErrorK::limit, "(one)", {4, 32, 8}));
  CHECK(rejects(sexp::ReaderErrorK::limit, "(((x)))", {1024, 32, 1}));
  return true;
}

bool test_parsed_sidecar_refusal_classes()
{
  const std::string base =
    "(kernel-plan (abi 1) (flavor normal) "
    "(relations (rel 0 (relation in 2 (0 1))) "
    "(rel 1 (relation out 2 (0 1)))) "
    "(attachments) (constants) (prims) (dynamic out) "
    "(rules (rule-def (rid 4) (variant \"all:in#3\") (nregs 2) "
    "(pre) (driver (scan (rel 0) (r 0) (r 1))) (body) "
    "(head (emit (rel 1) (0 1) (r 0) (r 1))))) "
    "(meta (rule-meta (rid 4) (source \"fixture.slog:1\"))))";

  const auto parse_rejects = [](ParseErrorK wanted, const std::string& text) {
    try { (void)parse_kernel_plan(text); }
    catch (const PlanParseError& error) { return error.kind() == wanted; }
    return false;
  };
  const auto seal_rejects = [](SealErrorK wanted, const std::string& text,
                               Database* db = nullptr) {
    try { (void)seal_kernel_plan(parse_kernel_plan(text), db); }
    catch (const SealError& error) { return error.kind() == wanted; }
    return false;
  };
  const auto seal_accepts = [](const std::string& text) {
    try { (void)seal_kernel_plan(parse_kernel_plan(text)); }
    catch (...) { return false; }
    return true;
  };

  CHECK(parse_rejects(ParseErrorK::syntax, base.substr(0, base.size() - 1)));
  CHECK(parse_rejects(ParseErrorK::syntax,
        replace_once(base, "(rel 1", "(rel 7")));
  CHECK(parse_rejects(ParseErrorK::limit,
        std::string(258, '(') + "x" + std::string(258, ')')));
  CHECK([&] {
    try { (void)parse_kernel_plan_file("tests/data/no-such-sidecar.plan"); }
    catch (const PlanParseError& error) {
      return error.kind() == ParseErrorK::io;
    }
    return false;
  }());
  CHECK(seal_rejects(SealErrorK::abi,
        replace_once(base, "(abi 1)", "(abi 2)")));
  // Slices 1-3 of counted-interp-contract.md admit count and the three
  // maintenance flavors; an unknown flavor stays a typed refusal, and a
  // flavored rule without a "/<kind>" variant suffix is a typed identity
  // refusal.
  CHECK(seal_rejects(SealErrorK::flavor,
        replace_once(base, "(flavor normal)", "(flavor maint9)")));
  CHECK(seal_rejects(SealErrorK::variant_identity,
        replace_once(base, "(flavor normal)", "(flavor maint1)")));
  CHECK(seal_rejects(SealErrorK::variant_identity,
        replace_once(base, "(flavor normal)", "(flavor maint3neg)")));
  CHECK(seal_rejects(SealErrorK::variant_identity,
        replace_once(base, "(flavor normal)", "(flavor maint4neg)")));
  CHECK(seal_rejects(SealErrorK::variant_identity,
        replace_once(base, "(flavor normal)", "(flavor count)")));
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(base,
          "(driver (scan (rel 0) (r 0) (r 1)))", "(driver (seeded))")));
  CHECK(seal_rejects(SealErrorK::relation_slot,
        replace_once(base, "(emit (rel 1)", "(emit (rel 9)")));
  CHECK(seal_rejects(SealErrorK::relation_arity,
        replace_once(base, "(relation out 2 (0 1))",
                            "(relation out 65 (0 1))")));
  CHECK(seal_rejects(SealErrorK::ordering,
        replace_once(base, "(emit (rel 1) (0 1)",
                                  "(emit (rel 1) (0 0)")));
  CHECK(seal_rejects(SealErrorK::index_requisition,
        replace_once(base, "(emit (rel 1) (0 1)",
                                  "(emit (rel 1) (1 0)")));
  CHECK(seal_rejects(SealErrorK::register_bounds,
        replace_once(base, "(r 0) (r 1)))))", "(r 0) (r 9)))))")));
  CHECK(seal_rejects(SealErrorK::dataflow,
        replace_once(replace_once(base, "(nregs 2)", "(nregs 3)"),
                     "(r 0) (r 1)))))", "(r 0) (r 2)))))")));
  CHECK(seal_rejects(SealErrorK::head_coverage,
        replace_once(base,
          "(head (emit (rel 1) (0 1) (r 0) (r 1)))", "(head)")));
  CHECK(seal_rejects(SealErrorK::bound_prefix,
        replace_once(replace_once(base, "(nregs 2)", "(nregs 4)"),
          "(body)", "(body (join (rel 0) (0 1) 1 (r 2) (r 3)))")));
  CHECK(seal_accepts(
        replace_once(replace_once(base, "(nregs 2)", "(nregs 4)"),
          "(body)", "(body (join (rel 0) (0 1) 0 (r 2) (r 3)))")));
  CHECK(seal_rejects(SealErrorK::relation_kind,
        replace_once(base,
          "(rel 1 (relation out 2 (0 1)))",
          "(rel 1 (struct out 2 (0 1)))")));
  CHECK(seal_rejects(SealErrorK::constant_slot,
        replace_once(base, "(pre)", "(pre (let (r 0) (k 9)))")));

  DecodedKernelPlan duplicate = parse_kernel_plan(base);
  duplicate.rules.push_back(duplicate.rules[0]);
  CHECK([&] {
    try { (void)seal_kernel_plan(duplicate); }
    catch (const SealError& error) {
      return error.kind() == SealErrorK::variant_identity;
    }
    return false;
  }());
  duplicate.rules[1].plan.variant = "all:in#4";
  duplicate.rules[1].plan.variant_ordinal = 4;
  CHECK(seal_kernel_plan(duplicate).rules.size() == 2);

  Database constant_db(1);
  const std::string constant_plan = replace_once(
    replace_once(
      replace_once(base, "(constants)",
                   "(constants (k 0 seven 7) (k 1 label \"ok\"))"),
      "(pre)", "(pre (let (r 0) (k 0)))"),
    "(driver (scan (rel 0) (r 0) (r 1)))",
    "(driver (probe (rel 0) (0 1) 1 (r 0) (r 1)))");
  const DecodedKernelPlan decoded = parse_kernel_plan(constant_plan);
  CHECK(decoded.constants.size() == 2);
  CHECK(decoded.constants[0].kind == ConstantK::integer);
  CHECK(decoded.constants[1].kind == ConstantK::string);
  CHECK(decoded.rules[0].plan.variant_ordinal == 3);
  const SealedKernelPlan sealed = seal_kernel_plan(decoded, &constant_db);
  CHECK(sealed.rules[0].program.preloads ==
        (std::vector<std::pair<u16, u64>>{{0, s32_encode(7)}}));

  Database missing(1);
  CHECK([&] {
    try { (void)bind_kernel_plan(seal_kernel_plan(parse_kernel_plan(base)), missing); }
    catch (const SealError& error) { return error.kind() == SealErrorK::binding; }
    return false;
  }());
  return true;
}

bool test_real_interp_read_task_recursive_admission()
{
  class NativeBaseTask final : public Task
  {
    Database* db;
    Relation* edge;
    Relation* path;
    Index** path_index;
    u16 bucket;
  public:
    NativeBaseTask(Database* d, Relation* e, Relation* p, u16 b)
      : db(d), edge(e), path(p), path_index(p->getIndex({0, 1}, false)),
        bucket(b) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      read_delta(edge, bucket, db->getThreadCount(), [&](const u64* row) {
        ++fires;
        emit<2>(path, path_index, batch, {row[0], row[1]}, {0, 1});
      });
      path->sendBatch(batch);
      if (fires) db->bumpFires("<native>", "delta:admit_edge#0", fires);
      return true;
    }
  };

  class NativeRecursiveTask final : public Task
  {
    Database* db;
    Relation* path;
    Index** edge_index;
    Index** path_index;
    u16 bucket;
  public:
    NativeRecursiveTask(Database* d, Relation* e, Relation* p, u16 b)
      : db(d), path(p), edge_index(e->getIndex({0, 1}, false)),
        path_index(p->getIndex({0, 1}, false)), bucket(b) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      read_delta(path, bucket, db->getThreadCount(), [&](const u64* row) {
        join_probe<2, 1>(edge_index, {row[1], 0}, [&](const auto& match) {
          ++fires;
          emit<2>(path, path_index, batch, {row[0], match[1]}, {0, 1});
        });
      });
      path->sendBatch(batch);
      if (fires) db->bumpFires("<native>", "delta:admit_path#0", fires);
      return true;
    }
  };

  Database db(2);
  db.addRelation("admit_edge", 2);
  db.addRelation("admit_path", 2);
  Relation* edge = db.getRelation("admit_edge");
  Relation* path = db.getRelation("admit_path");
  const std::vector<u16> order{0, 1};
  edge->addIndex<2>(order, false);
  path->addIndex<2>(order, false);

  InsertBatch* input = new InsertBatch();
  for (const std::array<u64, 2>& row :
       {std::array<u64, 2>{1, 2}, {2, 3}, {3, 4}})
  {
    input->data[input->usage++] = row[0];
    input->data[input->usage++] = row[1];
  }
  edge->sendBatch(input);

  Stratum stratum("interp-admission");
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
  {
    stratum.addTask(phase_write,
      new WriteTask<2>(&db, edge, {0, 1}, false, bucket));
    stratum.addTask(phase_write,
      new WriteTask<2>(&db, path, {0, 1}, false, bucket));
    stratum.addTask(phase_intern,
      new InternTask<2>(&db, edge, {0, 1}, bucket));
    stratum.addTask(phase_intern,
      new InternTask<2>(&db, path, {0, 1}, bucket));
  }

  const std::vector<RelationShape> shapes{
    {2, {{0, 1}}}, {2, {{0, 1}}}
  };
  BoundRule base(seal_rule(RulePlan{
      70, 0, "delta:admit_edge#0", 2, {},
      {DriverK::scan_delta, 0, {}, 0, {0, 1}}, {},
      {EmitPlan{1, {0, 1}, {0, 1}}}}, shapes),
    {edge, path});
  BoundRule recursive(seal_rule(RulePlan{
      71, 0, "delta:admit_path#0", 3, {},
      {DriverK::scan_delta, 1, {}, 0, {0, 1}},
      {ProbePlan{0, {0, 1}, 1, {1, 2}}},
      {EmitPlan{1, {0, 1}, {0, 2}}}}, shapes),
    {edge, path});
  base.attach(&db, &stratum);
  recursive.attach(&db, &stratum);

  RunBudget budget;
  budget.max_ms = 10000;
  budget.mem_bytes = UINT64_MAX;
  budget.stop_at_boundary = true;

  std::vector<std::vector<std::vector<u64>>> deltas;
  RunStatus status = db.continueStratum(&stratum, budget, true, true);
  while (!status.fixpoint)
  {
    CHECK(status.where == RUN_AT_BOUNDARY);
    deltas.push_back(nominal_delta_rows(path));
    status = db.continueStratum(&stratum, budget, false, true);
  }

  const std::vector<std::vector<std::vector<u64>>> native_deltas{
    {{1, 2}, {2, 3}, {3, 4}},
    {{1, 3}, {2, 4}},
    {{1, 4}}
  };
  CHECK(deltas == native_deltas);
  CHECK(nominal_index_rows(path, order) ==
        (std::vector<std::vector<u64>>{{1, 2}, {1, 3}, {1, 4},
                                       {2, 3}, {2, 4}, {3, 4}}));
  CHECK(db.fire_counts[std::make_pair(std::string("<interp-rule:70:variant:0>"),
                                      std::string("delta:admit_edge#0"))] == 3);
  CHECK(db.fire_counts[std::make_pair(std::string("<interp-rule:71:variant:0>"),
                                      std::string("delta:admit_path#0"))] == 3);

  // Run the same recursive normal-set kernel through the fused native
  // operators and the same scheduler/barriers.  This is the admission
  // differential: per-iteration deltas and disaggregated variant fires must
  // match, not merely the final set.
  Database native_db(2);
  native_db.addRelation("admit_edge", 2);
  native_db.addRelation("admit_path", 2);
  Relation* native_edge = native_db.getRelation("admit_edge");
  Relation* native_path = native_db.getRelation("admit_path");
  native_edge->addIndex<2>(order, false);
  native_path->addIndex<2>(order, false);
  InsertBatch* native_input = new InsertBatch();
  for (const std::array<u64, 2>& row :
       {std::array<u64, 2>{1, 2}, {2, 3}, {3, 4}})
  {
    native_input->data[native_input->usage++] = row[0];
    native_input->data[native_input->usage++] = row[1];
  }
  native_edge->sendBatch(native_input);
  Stratum native_stratum("native-admission");
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
  {
    native_stratum.addTask(phase_write,
      new WriteTask<2>(&native_db, native_edge, {0, 1}, false, bucket));
    native_stratum.addTask(phase_write,
      new WriteTask<2>(&native_db, native_path, {0, 1}, false, bucket));
    native_stratum.addTask(phase_read,
      new NativeBaseTask(&native_db, native_edge, native_path, bucket));
    native_stratum.addTask(phase_read,
      new NativeRecursiveTask(&native_db, native_edge, native_path, bucket));
    native_stratum.addTask(phase_intern,
      new InternTask<2>(&native_db, native_edge, {0, 1}, bucket));
    native_stratum.addTask(phase_intern,
      new InternTask<2>(&native_db, native_path, {0, 1}, bucket));
  }
  std::vector<std::vector<std::vector<u64>>> native_observed_deltas;
  RunStatus native_status = native_db.continueStratum(
    &native_stratum, budget, true, true);
  while (!native_status.fixpoint)
  {
    CHECK(native_status.where == RUN_AT_BOUNDARY);
    native_observed_deltas.push_back(nominal_delta_rows(native_path));
    native_status = native_db.continueStratum(
      &native_stratum, budget, false, true);
  }
  CHECK(deltas == native_observed_deltas);
  CHECK(nominal_index_rows(path, order) ==
        nominal_index_rows(native_path, order));
  CHECK(native_db.fire_counts[std::make_pair(std::string("<native>"),
         std::string("delta:admit_edge#0"))] == 3);
  CHECK(native_db.fire_counts[std::make_pair(std::string("<native>"),
         std::string("delta:admit_path#0"))] == 3);
  return true;
}

// ===========================================================================
// Counted differential harness (counted-interp-contract.md slice 1).
//
// Each case runs the same settled database through the sealed/bound VM and
// through hand-written native counting tasks -- the identical CountTask /
// CountStructTask folds registered on both sides -- and requires
// byte-identical count-sidecar words, disaggregated fire equality, and
// untouched master content (count sinks never insert).
// ===========================================================================

template <u16 KA>
static std::map<std::vector<u64>, u64> sidecar_words(Relation* rel)
{
  std::map<std::vector<u64>, u64> out;
  Index** side = rel->getCountSidecar();
  if (side == nullptr) return out;
  for (u16 b = 0; b < bucket_count; ++b)
  {
    auto* index = static_cast<BTreeMapIndex<KA>*>(side[b]);
    for (auto it = index->begin(); it != index->end(); ++it)
      out.emplace(std::vector<u64>(it->first.begin(), it->first.end()),
                  it->second);
  }
  return out;
}

static void dump_words(const char* label,
                       const std::map<std::vector<u64>, u64>& words)
{
  std::cout << label << ":\n";
  for (const auto& [key, word] : words)
  {
    std::cout << "  (";
    for (u64 value : key) std::cout << value << " ";
    std::cout << ") in=" << cnt_input(word) << " nr=" << cnt_nonrec(word)
              << " rc=" << cnt_rec(word) << "\n";
  }
}

static bool drive_stratum_to_fixpoint(Database& db, Stratum& stratum)
{
  RunBudget budget;
  budget.max_ms = 10000;
  budget.mem_bytes = UINT64_MAX;
  budget.stop_at_boundary = true;
  RunStatus status = db.continueStratum(&stratum, budget, true, true);
  while (!status.fixpoint)
  {
    if (status.where != RUN_AT_BOUNDARY) return false;
    status = db.continueStratum(&stratum, budget, false, true);
  }
  return true;
}

static void attach_counted_rules(Database& db, Stratum& stratum,
                                 const SealedKernelPlan& sealed)
{
  // The installer's fire-once rule: once/seeded dispatch and scans over
  // NON-dynamic relations run first-iteration-only; dynamic scans chase
  // the ripple every iteration.
  const std::set<std::string> dynamic(sealed.dynamic_names.begin(),
                                      sealed.dynamic_names.end());
  const auto rules = bind_kernel_plan(sealed, db);
  for (const auto& rule : rules)
  {
    const DriverPlan& driver = rule->definition().driver;
    bool fire_once = driver.kind == DriverK::once
                  || driver.kind == DriverK::seeded;
    if (driver.kind == DriverK::scan_delta)
      fire_once =
        dynamic.count(sealed.bindings[driver.relation].name) == 0;
    rule->attach(&db, &stratum, fire_once);
  }
}

// Recursive two-kind case (the fuzz-2-base shape): seeded/nonrec and
// seeded/rec variants over a settled transitive closure, checking the
// nonrec/rec decomposition of every sidecar word against the native
// counting tasks and a hand-pinned expectation.
bool test_counted_recursive_seeded_differential()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor count) "
    "(relations "
      "(rel 0 (relation cnt_edge 2 (0 1))) "
      "(rel 1 (relation cnt_path 2 (1 0)))) "
    "(attachments) (constants) (prims) (dynamic cnt_path) "
    "(rules "
      "(rule-def (rid 0) (variant \"seeded/nonrec\") (nregs 2) (pre) "
        "(driver (seeded)) "
        "(body (join (rel 0) (0 1) 0 (r 0) (r 1))) "
        "(head (emit (rel 1) (1 0) (r 1) (r 0)))) "
      "(rule-def (rid 1) (variant \"seeded/rec\") (nregs 3) (pre) "
        "(driver (seeded)) "
        "(body (join (rel 0) (0 1) 0 (r 0) (r 1)) "
              "(join (rel 1) (1 0) 1 (r 0) (r 2))) "
        "(head (emit (rel 1) (1 0) (r 1) (r 2))))) "
    "(meta (rule-meta (rid 0) (source \"cnt.slog:1\")) "
          "(rule-meta (rid 1) (source \"cnt.slog:2\"))))";
  const DecodedKernelPlan decoded = parse_kernel_plan(text);
  CHECK(decoded.flavor == "count");
  CHECK(decoded.dynamic_names == (std::vector<std::string>{"cnt_path"}));

  const auto load = [](Database& db) {
    db.addRelation("cnt_edge", 2);
    db.addRelation("cnt_path", 2);
    Relation* edge = db.getRelation("cnt_edge");
    Relation* path = db.getRelation("cnt_path");
    edge->addIndex<2>({0, 1}, false);
    path->addIndex<2>({1, 0}, false);
    // Settled closure of: path(X,Y) :- edge(X,Y).
    //                     path(X,Z) :- edge(Y,Z), path(X,Y).
    for (const std::array<u64, 2>& row :
         {std::array<u64, 2>{1, 2}, {2, 3}})
      insert_nominal(edge, {row[0], row[1]});
    for (const std::array<u64, 2>& row :
         {std::array<u64, 2>{1, 2}, {2, 3}, {1, 3}})
      insert_nominal(path, {row[0], row[1]});
  };

  Database db(2);
  load(db);
  Relation* path = db.getRelation("cnt_path");
  const auto master_before = nominal_index_rows(path, {1, 0});
  Stratum stratum("counted-interp");
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
    stratum.addTask(phase_intern, new CountTask<2>(&db, path, bucket), false);
  const SealedKernelPlan sealed = seal_kernel_plan(decoded);
  CHECK(sealed.rules[0].counted && sealed.rules[1].counted);
  CHECK(sealed.rules[0].fold_kind == cnt_kind_nonrec);
  CHECK(sealed.rules[1].fold_kind == cnt_kind_rec);
  attach_counted_rules(db, stratum, sealed);
  CHECK(drive_stratum_to_fixpoint(db, stratum));

  // Native second executor: the generated counted TU's exact shape.
  Database native_db(2);
  load(native_db);
  Relation* native_edge = native_db.getRelation("cnt_edge");
  Relation* native_path = native_db.getRelation("cnt_path");
  class NativeBase final : public Task
  {
    Database* db;
    Relation* path;
    Index** edge_index;
    Index** path_index;
  public:
    NativeBase(Database* d, Relation* e, Relation* p)
      : db(d), path(p), edge_index(e->getIndex({0, 1}, false)),
        path_index(p->getIndex({1, 0}, false)) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      join_all<2>(edge_index, [&](const std::array<u64, 2>& m) {
        ++fires;
        emit_count<2>(path, path_index, cnt_kind_nonrec, batch,
                      {m[1], m[0]}, {1, 0});
      });
      path->sendBatch(batch);
      if (fires) db->bumpFires("cnt.slog:1", "seeded", fires);
      return true;
    }
  };
  class NativeRec final : public Task
  {
    Database* db;
    Relation* path;
    Index** edge_index;
    Index** path_index;
  public:
    NativeRec(Database* d, Relation* e, Relation* p)
      : db(d), path(p), edge_index(e->getIndex({0, 1}, false)),
        path_index(p->getIndex({1, 0}, false)) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      join_all<2>(edge_index, [&](const std::array<u64, 2>& m) {
        join_probe<2, 1>(path_index, {m[0], 0},
                         [&](const std::array<u64, 2>& p) {
          ++fires;
          emit_count<2>(path, path_index, cnt_kind_rec, batch,
                        {m[1], p[1]}, {1, 0});
        });
      });
      path->sendBatch(batch);
      if (fires) db->bumpFires("cnt.slog:2", "seeded", fires);
      return true;
    }
  };
  Stratum native_stratum("counted-native");
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
    native_stratum.addTask(phase_intern,
      new CountTask<2>(&native_db, native_path, bucket), false);
  native_stratum.addTask(phase_read,
    new NativeBase(&native_db, native_edge, native_path), true);
  native_stratum.addTask(phase_read,
    new NativeRec(&native_db, native_edge, native_path), true);
  CHECK(drive_stratum_to_fixpoint(native_db, native_stratum));

  // Byte-identical sidecar words, on both executors and hand-pinned.
  const auto interp_words = sidecar_words<2>(path);
  const auto native_words = sidecar_words<2>(native_path);
  CHECK(interp_words == native_words);
  const std::map<std::vector<u64>, u64> expected{
    {{1, 2}, cnt_pack(false, 1, 0)},
    {{2, 3}, cnt_pack(false, 1, 0)},
    {{1, 3}, cnt_pack(false, 0, 1)}};
  CHECK(interp_words == expected);
  CHECK(db.getRelation("cnt_edge")->getCountSidecar() == nullptr);

  // Count sinks never insert: master content is untouched.
  CHECK(nominal_index_rows(path, {1, 0}) == master_before);
  CHECK(nominal_index_rows(native_path, {1, 0}) == master_before);

  // Disaggregated fires, and the native $stat_fires identity (source
  // location plus base driver tag, no "/<kind>" suffix).
  const auto fires = [](Database& which, const char* loc) {
    return which.fire_counts[{std::string(loc), std::string("seeded")}];
  };
  CHECK(fires(db, "cnt.slog:1") == 2 && fires(native_db, "cnt.slog:1") == 2);
  CHECK(fires(db, "cnt.slog:2") == 1 && fires(native_db, "cnt.slog:2") == 1);
  return true;
}

// Temp chain + struct construction (the counts_struct shape): a seeded
// parent stages a wide temp and a counted struct head; the delta-driven
// follow-up resolves content->id through an ordinary struct-master probe.
bool test_counted_temp_struct_chain_differential()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor count) "
    "(relations "
      "(rel 0 (relation cs_e 2 (0 1))) "
      "(rel 1 (struct cs_h 2 (1 0) (0 1))) "
      "(rel 2 (relation cs_g 1 (0))) "
      "(rel 3 (temp cs_tmp 2))) "
    "(attachments) (constants) (prims) (dynamic cs_g cs_h cs_tmp) "
    "(rules "
      "(rule-def (rid 0) (variant \"seeded/nonrec\") (nregs 3) (pre) "
        "(driver (seeded)) "
        "(body (join (rel 0) (0 1) 0 (r 0) (r 1))) "
        "(head (emit-temp (rel 3) (r 0) (r 1)) "
              "(mkstruct (rel 1) (1 0) (r 2) (r 1)))) "
      "(rule-def (rid 0) (variant \"delta:cs_tmp/nonrec\") (nregs 3) (pre) "
        "(driver (scan (rel 3) (r 0) (r 1))) "
        "(body (join (rel 1) (1 0) 1 (r 1) (r 2))) "
        "(head (emit (rel 2) (0) (r 2))))) "
    "(meta (rule-meta (rid 0) (source \"cs.slog:19\"))))";
  const DecodedKernelPlan decoded = parse_kernel_plan(text);
  CHECK(decoded.bindings[3].shape.temp);
  CHECK(decoded.rules[0].plan.heads[0].head_kind == HeadK::temp);
  CHECK(decoded.rules[0].plan.heads[1].head_kind == HeadK::struct_);

  const auto load = [](Database& db) {
    db.addRelation("cs_e", 2);
    db.addStruct("cs_h", 2);
    db.addRelation("cs_g", 1);
    db.addTempRelation("cs_tmp", 2);
    Relation* e = db.getRelation("cs_e");
    Relation* h = db.getRelation("cs_h");
    Relation* g = db.getRelation("cs_g");
    e->addIndex<2>({0, 1}, false);
    h->addIndex<2>({1, 0}, false);
    h->addIndex<2>({0, 1}, false);
    g->addIndex<1>({0}, false);
    for (const std::array<u64, 2>& row :
         {std::array<u64, 2>{10, 1}, {10, 2}, {20, 2}})
      insert_nominal(e, {row[0], row[1]});
    // Interned instances (id, content) and the settled follow-up rows.
    insert_nominal(h, {1001, 1});
    insert_nominal(h, {1002, 2});
    insert_nominal(g, {1001});
    insert_nominal(g, {1002});
  };

  Database db(2);
  load(db);
  Relation* h = db.getRelation("cs_h");
  Relation* g = db.getRelation("cs_g");
  Stratum stratum("counted-chain-interp");
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
  {
    stratum.addTask(phase_intern,
                    new CountStructTask<2>(&db, h, bucket), false);
    stratum.addTask(phase_intern, new CountTask<1>(&db, g, bucket), false);
  }
  const SealedKernelPlan sealed = seal_kernel_plan(decoded);
  // The mkstruct head lowered to a pre-fire resolution cursor.
  CHECK(sealed.rules[0].cursors.size() == 2);
  const auto* resolve =
    std::get_if<ProbePlan>(&sealed.rules[0].cursors[1]);
  CHECK(resolve != nullptr && resolve->resolve && resolve->struct_);
  attach_counted_rules(db, stratum, sealed);
  CHECK(drive_stratum_to_fixpoint(db, stratum));

  Database native_db(2);
  load(native_db);
  Relation* native_e = native_db.getRelation("cs_e");
  Relation* native_h = native_db.getRelation("cs_h");
  Relation* native_g = native_db.getRelation("cs_g");
  Relation* native_tmp = native_db.getRelation("cs_tmp");
  class NativeSeeded final : public Task
  {
    Database* db;
    Relation* tmp;
    Relation* h;
    Index** e_index;
    Index** h_master;
  public:
    NativeSeeded(Database* d, Relation* e, Relation* h_rel, Relation* t)
      : db(d), tmp(t), h(h_rel), e_index(e->getIndex({0, 1}, false)),
        h_master(h_rel->getIndex({1, 0}, false)) {}
    bool work() override
    {
      InsertBatch* tmp_batch = new InsertBatch();
      InsertBatch* h_batch = new InsertBatch();
      u64 fires = 0;
      join_all<2>(e_index, [&](const std::array<u64, 2>& m) {
        ++fires;
        emit_temp<2>(tmp, tmp_batch, {m[0], m[1]});
        emit_struct_count<2>(h, h_master, cnt_kind_nonrec, h_batch,
                             {m[1]}, {1, 0});
      });
      tmp->sendBatch(tmp_batch);
      h->sendBatch(h_batch);
      if (fires) db->bumpFires("cs.slog:19", "seeded", fires);
      return true;
    }
  };
  class NativeFollowup final : public Task
  {
    Database* db;
    Relation* tmp;
    Relation* g;
    Index** h_master;
    Index** g_index;
    u16 bucket;
  public:
    NativeFollowup(Database* d, Relation* t, Relation* h_rel,
                   Relation* g_rel, u16 b)
      : db(d), tmp(t), g(g_rel), h_master(h_rel->getIndex({1, 0}, false)),
        g_index(g_rel->getIndex({0}, false)), bucket(b) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      read_delta(tmp, bucket, db->getThreadCount(), [&](const u64* row) {
        join_probe<2, 1>(h_master, {row[1], 0},
                         [&](const std::array<u64, 2>& m) {
          ++fires;
          emit_count<1>(g, g_index, cnt_kind_nonrec, batch, {m[1]}, {0});
        });
      });
      g->sendBatch(batch);
      if (fires) db->bumpFires("cs.slog:19", "delta:cs_tmp", fires);
      return true;
    }
  };
  Stratum native_stratum("counted-chain-native");
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
  {
    native_stratum.addTask(phase_intern,
      new CountStructTask<2>(&native_db, native_h, bucket), false);
    native_stratum.addTask(phase_intern,
      new CountTask<1>(&native_db, native_g, bucket), false);
    native_stratum.addTask(phase_read,
      new NativeFollowup(&native_db, native_tmp, native_h, native_g,
                         bucket), false);
  }
  native_stratum.addTask(phase_read,
    new NativeSeeded(&native_db, native_e, native_h, native_tmp), true);
  CHECK(drive_stratum_to_fixpoint(native_db, native_stratum));

  // Struct sidecars key by the id column; table sidecars by the full row.
  const auto interp_h = sidecar_words<1>(h);
  const auto interp_g = sidecar_words<1>(g);
  CHECK(interp_h == sidecar_words<1>(native_h));
  CHECK(interp_g == sidecar_words<1>(native_g));
  const std::map<std::vector<u64>, u64> expected_h{
    {{1001}, cnt_pack(false, 1, 0)},
    {{1002}, cnt_pack(false, 2, 0)}};
  const std::map<std::vector<u64>, u64> expected_g{
    {{1001}, cnt_pack(false, 1, 0)},
    {{1002}, cnt_pack(false, 2, 0)}};
  CHECK(interp_h == expected_h);
  CHECK(interp_g == expected_g);
  CHECK(db.getRelation("cs_tmp")->getCountSidecar() == nullptr);
  CHECK(nominal_index_rows(h, {1, 0}) ==
        nominal_index_rows(native_h, {1, 0}));
  CHECK(nominal_index_rows(g, {0}) == nominal_index_rows(native_g, {0}));

  // Same-source rule, two variants: fires aggregate per (loc, base tag)
  // exactly like the native TU's bumpFires.
  const auto fires = [](Database& which, const char* tag) {
    return which.fire_counts[{std::string("cs.slog:19"), std::string(tag)}];
  };
  CHECK(fires(db, "seeded") == 3 && fires(native_db, "seeded") == 3);
  CHECK(fires(db, "delta:cs_tmp") == 3
        && fires(native_db, "delta:cs_tmp") == 3);
  return true;
}

namespace counted_chain
{

const char* chained_plan_text =
  "(kernel-plan (abi 1) (flavor count) "
  "(relations "
    "(rel 0 (relation ch_e 1 (0))) "
    "(rel 1 (struct ch_s1 2 (1 0) (0 1))) "
    "(rel 2 (struct ch_s2 2 (1 0) (0 1)))) "
  "(attachments) (constants) (prims) (dynamic ch_s1 ch_s2) "
  "(rules "
    "(rule-def (rid 0) (variant \"seeded/nonrec\") (nregs 3) (pre) "
      "(driver (seeded)) "
      "(body (join (rel 0) (0) 0 (r 0))) "
      "(head (mkstruct (rel 1) (1 0) (r 1) (r 0)) "
            "(mkstruct (rel 2) (1 0) (r 2) (r 1))))) "
  "(meta (rule-meta (rid 0) (source \"ch.slog:1\"))))";

// Shared setup: `settled` controls whether the outer construction ch_s2 is
// interned -- when it is not, the fixpoint is not settled and the
// resolution cursor must die loudly.
void run(bool settled)
{
  Database db(2);
  db.addRelation("ch_e", 1);
  db.addStruct("ch_s1", 2);
  db.addStruct("ch_s2", 2);
  Relation* e = db.getRelation("ch_e");
  Relation* s1 = db.getRelation("ch_s1");
  Relation* s2 = db.getRelation("ch_s2");
  e->addIndex<1>({0}, false);
  for (Relation* rel : {s1, s2})
  {
    rel->addIndex<2>({1, 0}, false);
    rel->addIndex<2>({0, 1}, false);
  }
  insert_nominal(e, {5});
  insert_nominal(s1, {2001, 5});
  if (settled) insert_nominal(s2, {3001, 2001});
  Stratum stratum("counted-chained");
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
  {
    stratum.addTask(phase_intern,
                    new CountStructTask<2>(&db, s1, bucket), false);
    stratum.addTask(phase_intern,
                    new CountStructTask<2>(&db, s2, bucket), false);
  }
  const SealedKernelPlan sealed =
    seal_kernel_plan(parse_kernel_plan(chained_plan_text));
  attach_counted_rules(db, stratum, sealed);
  if (!drive_stratum_to_fixpoint(db, stratum))
    throw std::runtime_error("counted chained stratum did not settle");
  if (sidecar_words<1>(s1)
      != std::map<std::vector<u64>, u64>{{{2001}, cnt_pack(false, 1, 0)}})
    throw std::runtime_error("counted chained s1 sidecar mismatch");
  if (sidecar_words<1>(s2)
      != std::map<std::vector<u64>, u64>{{{3001}, cnt_pack(false, 1, 0)}})
    throw std::runtime_error("counted chained s2 sidecar mismatch");
  if (db.fire_counts[{std::string("ch.slog:1"), std::string("seeded")}] != 1)
    throw std::runtime_error("counted chained fires mismatch");
}

} // namespace counted_chain

// Chained construction: the inner mkstruct's resolved id is the outer
// construction's content register; on unsettled content the resolution
// cursor's zero-match exhaustion is a loud fatal (forked child).
// Fatal-expected probe bodies run in a RE-EXECED child (`main` dispatches
// on the flag): plain fork() from this threaded process can inherit a
// locked malloc/OpenMP futex and deadlock before reaching the fatal --
// observed as a 22h hang -- while exec resets the address space.  alarm()
// is belt-and-braces: a wedged child dies signaled and CHECK fails loudly
// instead of hanging waitpid forever.
[[noreturn]] static void probe_child_closure_fatal()
{
  alarm(20);
  const int devnull = open("/dev/null", O_WRONLY);
  dup2(devnull, 1);
  dup2(devnull, 2);
  counted_chain::run(false);
  _exit(0); // reached only if the resolve cursor did NOT fatal
}

static bool run_reexec_probe(const char* flag)
{
  const pid_t pid = fork();
  if (pid == 0)
  {
    execl("/proc/self/exe", "interp-operator-tests", flag, (char*)nullptr);
    _exit(97); // exec failed
  }
  int status = 0;
  waitpid(pid, &status, 0);
  return WIFEXITED(status) && WEXITSTATUS(status) == 1;
}

bool test_counted_chained_mkstruct_and_closure_fatal()
{
  counted_chain::run(true);
  CHECK(run_reexec_probe("--probe-closure-fatal"));
  return true;
}

// A counted rule's primitive fault contributes a kind-tagged error-arm row
// (emit_pending_error_count), never a set-semantics insert: a kind-less
// batch at finalize would invalidate and FREE the count sidecars the
// registered CountStructTasks hold (the slice-1 use-after-free this test
// pins).  The arm instance pre-exists at the settled fixpoint, so the
// counted error sink's closure probe resolves it and the sidecar gains
// exactly one nonrec contribution.
bool test_counted_prim_fault_arm_contribution()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor count) "
    "(relations "
      "(rel 0 (relation arm_d 1 (0))) "
      "(rel 1 (relation arm_bad 1 (0))) "
      "(rel 2 (struct div_by_zero 3 (1 2 0) (0 1 2)))) "
    "(attachments) (constants (k 0 c100 100)) (prims _0002f) "
    "(dynamic arm_bad div_by_zero) "
    "(rules "
      "(rule-def (rid 5) (variant \"seeded/nonrec\") (nregs 3) "
        "(pre (let (r 0) (k 0))) (driver (seeded)) "
        "(body (join (rel 0) (0) 0 (r 1)) "
              "(let (r 2) (prim _0002f (r 0) (r 1)))) "
        "(head (emit (rel 1) (0) (r 2))))) "
    "(meta (rule-meta (rid 5) (source \"arm.slog:5\"))))";

  Database db(2);
  db.addRelation("arm_d", 1);
  db.addRelation("arm_bad", 1);
  db.addStruct("div_by_zero", 3);
  Relation* d = db.getRelation("arm_d");
  Relation* bad = db.getRelation("arm_bad");
  Relation* dz = db.getRelation("div_by_zero");
  d->addIndex<1>({0}, false);
  bad->addIndex<1>({0}, false);
  dz->addIndex<3>({1, 2, 0}, false);
  dz->addIndex<3>({0, 1, 2}, false);
  // Settled content: 100/0 faulted (the interned arm instance), 100/4 fired.
  insert_nominal(d, {s32_encode(0)});
  insert_nominal(d, {s32_encode(4)});
  insert_nominal(bad, {s32_encode(25)});
  const u64 vloc = db.encodeString("arm.slog:5");
  insert_nominal(dz, {9001, vloc, s32_encode(100)});

  Stratum stratum("counted-arm");
  for (u16 bucket = 0; bucket < bucket_count; ++bucket)
  {
    stratum.addTask(phase_intern, new CountTask<1>(&db, bad, bucket), false);
    stratum.addTask(phase_intern,
                    new CountStructTask<3>(&db, dz, bucket), false);
  }
  const SealedKernelPlan sealed = seal_kernel_plan(parse_kernel_plan(text),
                                                   &db);
  attach_counted_rules(db, stratum, sealed);
  CHECK(drive_stratum_to_fixpoint(db, stratum));

  // The sidecars survived (no kind-less invalidation freed them) and carry
  // exactly the native words: one nonrec fire contribution to the head, one
  // nonrec fault contribution to the arm.
  CHECK(dz->getCountSidecar() != nullptr);
  CHECK(bad->getCountSidecar() != nullptr);
  CHECK(sidecar_words<1>(dz)
        == (std::map<std::vector<u64>, u64>{{{9001}, cnt_pack(false, 1, 0)}}));
  CHECK(sidecar_words<1>(bad)
        == (std::map<std::vector<u64>, u64>{{{s32_encode(25)},
                                             cnt_pack(false, 1, 0)}}));
  // The faulting row abandons before its fire: one fire for X=4 only.
  CHECK((db.fire_counts[{std::string("arm.slog:5"), std::string("seeded")}])
        == 1);
  return true;
}

// ===========================================================================
// Maintenance differential harness (counted-interp-contract.md slices 2-3).
// Each case builds a settled counted database, stages the signed premise
// transitions exactly like stageUpdateTransitions, and runs the epoch
// through the sealed/bound VM and through hand-written native maintenance
// tasks -- the identical Maintain*Task folds registered on both sides.
// ===========================================================================

static void load_signed_delta(Relation* rel,
                              const std::vector<std::vector<u64>>& rows,
                              u8 kind, s8 sign)
{
  // Exactly stageUpdateTransitions' staging: a kind/sign-tagged batch SENT
  // into the shards, so the run's entry finalize turns it into the
  // iteration-0 delta that drives the epoch's scans.
  InsertBatch* batch = new InsertBatch();
  batch->kind = kind;
  batch->sign = sign;
  for (const auto& row : rows)
  {
    seal_check(row.size() == rel->getArity(), "fixture: row width mismatch");
    for (u64 value : row) batch->data[batch->usage++] = value;
  }
  rel->sendBatch(batch);
}

// Registration shared by both executors of a maintenance fixture: the
// native TU's write/intern machinery around the maintained head.
static void register_maint_machinery(
  Database& db, Stratum& stratum, Relation* input, Relation* head,
  const std::vector<u16>& head_order)
{
  const std::vector<u16> input_order{0, 1};
  for (u16 b = 0; b < bucket_count; ++b)
  {
    if (input != nullptr)
    {
      if (input->getArity() == 2)
      {
        stratum.addTask(phase_write,
          new WriteTask<2>(&db, input, {0, 1}, false, b), true);
        stratum.addTask(phase_intern,
          new InternTask<2>(&db, input, {0, 1}, b));
      }
      else
      {
        stratum.addTask(phase_write,
          new WriteTask<1>(&db, input, {0}, false, b), true);
        stratum.addTask(phase_intern,
          new InternTask<1>(&db, input, {0}, b));
      }
    }
    std::array<u16, 2> head_ord2{};
    std::copy(head_order.begin(), head_order.end(), head_ord2.begin());
    stratum.addTask(phase_write,
      new WriteTask<2>(&db, head, head_ord2, false, b), true);
    stratum.addTask(phase_write,
      new WriteTask<2>(&db, head, head_ord2, true, b), false);
  }
  std::array<u16, 2> head_ord2{};
  std::copy(head_order.begin(), head_order.end(), head_ord2.begin());
  stratum.addTask(phase_intern,
    new MaintainTask<2>(&db, head, head_ord2, 0, false));
}

// Positive maintenance (maint1): the transitive-closure edge addition,
// with the occurrence-partitioned rule versions of the real _maint1 plan
// -- all:edge/nonrec, all:edge/rec over the R_old exclusion view, and the
// delta:path/rec ripple -- healed counts pinned by hand and against the
// native tasks.
bool test_maint1_positive_differential()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor maint1) "
    "(relations "
      "(rel 0 (relation mt_edge 2 (0 1))) "
      "(rel 1 (relation mt_path 2 (1 0) (delta 1 0)))) "
    "(attachments) (constants) (prims) (dynamic mt_path) "
    "(rules "
      "(rule-def (rid 0) (variant \"all:mt_edge/nonrec\") (nregs 2) (pre) "
        "(driver (scan (rel 0) (r 0) (r 1))) (body) "
        "(head (emit (rel 1) (1 0) (r 1) (r 0)))) "
      "(rule-def (rid 1) (variant \"all:mt_edge/rec\") (nregs 3) (pre) "
        "(driver (scan (rel 0) (r 0) (r 1))) "
        "(body (join-old (rel 1) (1 0) 1 (1 0) (r 0) (r 2))) "
        "(head (emit (rel 1) (1 0) (r 1) (r 2)))) "
      "(rule-def (rid 1) (variant \"delta:mt_path/rec\") (nregs 3) (pre) "
        "(driver (scan (rel 1) (r 0) (r 1))) "
        "(body (join (rel 0) (0 1) 1 (r 1) (r 2))) "
        "(head (emit (rel 1) (1 0) (r 2) (r 0))))) "
    "(meta (rule-meta (rid 0) (source \"mt.slog:4\")) "
          "(rule-meta (rid 1) (source \"mt.slog:9\"))))";
  const DecodedKernelPlan decoded = parse_kernel_plan(text);

  // Settled pre-state with established counts, then one positive edit:
  // insert edge (0,1) into the live indices (set-overlay-positive) and
  // stage its premise transition as iteration-0 delta.
  const auto load = [](Database& db) {
    db.addRelation("mt_edge", 2);
    db.addRelation("mt_path", 2);
    Relation* edge = db.getRelation("mt_edge");
    Relation* path = db.getRelation("mt_path");
    edge->addIndex<2>({0, 1}, false);
    path->addIndex<2>({1, 0}, false);
    path->addIndex<2>({1, 0}, true);
    for (const std::array<u64, 2>& row :
         {std::array<u64, 2>{1, 2}, {2, 3}})
      insert_nominal(edge, {row[0], row[1]});
    for (const std::array<u64, 2>& row :
         {std::array<u64, 2>{1, 2}, {2, 3}, {1, 3}})
      insert_nominal(path, {row[0], row[1]});
    // Established sidecar (the recount-ready gate): nonrec for the copies,
    // rec for the two-hop row.
    Index** side = path->ensureCountSidecar();
    const auto put = [&](u64 a, u64 b, u64 word) {
      auto* index = static_cast<BTreeMapIndex<2>*>(side[buckethash(a)]);
      index->tree.insert2({a, b}, word);
    };
    put(1, 2, cnt_pack(false, 1, 0));
    put(2, 3, cnt_pack(false, 1, 0));
    put(1, 3, cnt_pack(false, 0, 1));
    db.markCounted({"mt_path"});
    insert_nominal(edge, {0, 1});
    load_signed_delta(edge, {{0, 1}}, cnt_kind_premise, 1);
  };

  Database db(2);
  load(db);
  Relation* path = db.getRelation("mt_path");
  Stratum stratum("maint1-interp");
  register_maint_machinery(db, stratum, db.getRelation("mt_edge"), path,
                           {1, 0});
  const SealedKernelPlan sealed = seal_kernel_plan(decoded);
  CHECK(sealed.rules[0].maint && sealed.rules[0].sign == 1);
  CHECK(sealed.rules[0].fold_kind == cnt_kind_nonrec);
  CHECK(sealed.rules[1].fold_kind == cnt_kind_rec);
  attach_counted_rules(db, stratum, sealed);
  CHECK(drive_stratum_to_fixpoint(db, stratum));

  Database native_db(2);
  load(native_db);
  Relation* native_edge = native_db.getRelation("mt_edge");
  Relation* native_path = native_db.getRelation("mt_path");
  class NativeBase final : public Task
  {
    Database* db;
    Relation* edge;
    Relation* path;
    Index** path_index;
    u16 bucket;
  public:
    NativeBase(Database* d, Relation* e, Relation* p, u16 b)
      : db(d), edge(e), path(p),
        path_index(p->getIndex({1, 0}, false)), bucket(b) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      read_delta(edge, bucket, db->getThreadCount(), [&](const u64* row) {
        ++fires;
        emit_maint<2>(path, cnt_kind_nonrec, 1, batch,
                      {row[1], row[0]}, {1, 0});
      });
      path->sendBatch(batch);
      if (fires) db->bumpFires("mt.slog:4", "all:mt_edge", fires);
      return true;
    }
  };
  class NativeEdgeRec final : public Task
  {
    Database* db;
    Relation* edge;
    Relation* path;
    Index** path_full;
    Index** path_delta;
    u16 bucket;
  public:
    NativeEdgeRec(Database* d, Relation* e, Relation* p, u16 b)
      : db(d), edge(e), path(p), path_full(p->getIndex({1, 0}, false)),
        path_delta(p->getIndex({1, 0}, true)), bucket(b) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      read_delta(edge, bucket, db->getThreadCount(), [&](const u64* row) {
        join_probe_old<2, 1>(path_full, path_delta, {row[0], 0},
                             [&](const std::array<u64, 2>& m) {
          ++fires;
          emit_maint<2>(path, cnt_kind_rec, 1, batch,
                        {row[1], m[1]}, {1, 0});
        });
      });
      path->sendBatch(batch);
      if (fires) db->bumpFires("mt.slog:9", "all:mt_edge", fires);
      return true;
    }
  };
  class NativePathRec final : public Task
  {
    Database* db;
    Relation* path;
    Index** edge_index;
    u16 bucket;
  public:
    NativePathRec(Database* d, Relation* e, Relation* p, u16 b)
      : db(d), path(p), edge_index(e->getIndex({0, 1}, false)), bucket(b) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      read_delta(path, bucket, db->getThreadCount(), [&](const u64* row) {
        join_probe<2, 1>(edge_index, {row[1], 0},
                         [&](const std::array<u64, 2>& m) {
          ++fires;
          emit_maint<2>(path, cnt_kind_rec, 1, batch,
                        {m[1], row[0]}, {1, 0});
        });
      });
      path->sendBatch(batch);
      if (fires) db->bumpFires("mt.slog:9", "delta:mt_path", fires);
      return true;
    }
  };
  Stratum native_stratum("maint1-native");
  register_maint_machinery(native_db, native_stratum, native_edge,
                           native_path, {1, 0});
  for (u16 b = 0; b < bucket_count; ++b)
  {
    native_stratum.addTask(phase_read,
      new NativeBase(&native_db, native_edge, native_path, b), true);
    native_stratum.addTask(phase_read,
      new NativeEdgeRec(&native_db, native_edge, native_path, b), true);
    native_stratum.addTask(phase_read,
      new NativePathRec(&native_db, native_edge, native_path, b), false);
  }
  CHECK(drive_stratum_to_fixpoint(native_db, native_stratum));

  // Healed content and byte-identical maintained sidecars, on both
  // executors and hand-pinned.
  const auto interp_words = sidecar_words<2>(path);
  CHECK(interp_words == sidecar_words<2>(native_path));
  const std::map<std::vector<u64>, u64> expected{
    {{1, 2}, cnt_pack(false, 1, 0)},
    {{2, 3}, cnt_pack(false, 1, 0)},
    {{1, 3}, cnt_pack(false, 0, 1)},
    {{0, 1}, cnt_pack(false, 1, 0)},
    {{0, 2}, cnt_pack(false, 0, 1)},
    {{0, 3}, cnt_pack(false, 0, 1)}};
  if (interp_words != expected)
  {
    dump_words("maint1 interp", interp_words);
    dump_words("maint1 expected", expected);
    dump_words("maint1 native", sidecar_words<2>(native_path));
    std::cout << "maint1 path rows interp="
              << nominal_index_rows(path, {1, 0}).size() << " native="
              << nominal_index_rows(native_path, {1, 0}).size() << "\n";
  }
  CHECK(interp_words == expected);
  CHECK(nominal_index_rows(path, {1, 0})
        == nominal_index_rows(native_path, {1, 0}));
  CHECK(nominal_index_rows(path, {1, 0}).size() == 6);
  const auto fires = [](Database& which, const char* loc, const char* tag) {
    return which.fire_counts[{std::string(loc), std::string(tag)}];
  };
  CHECK(fires(db, "mt.slog:4", "all:mt_edge") == 1
        && fires(native_db, "mt.slog:4", "all:mt_edge") == 1);
  CHECK(fires(db, "mt.slog:9", "all:mt_edge")
        == fires(native_db, "mt.slog:9", "all:mt_edge"));
  CHECK(fires(db, "mt.slog:9", "delta:mt_path") == 2
        && fires(native_db, "mt.slog:9", "delta:mt_path") == 2);
  return true;
}

// Negative maintenance (maint3neg): the dual exact occurrence partition of
// a self-join under deletion -- one version probes post-state FULL, the
// other the pre-state union view (join-new) -- decrementing each deleted
// pair exactly once, with membership crossings applied by MaintainTask.
bool test_maint3neg_negative_differential()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor maint3neg) "
    "(relations "
      "(rel 0 (relation mn_a 1 (0) (delta 0))) "
      "(rel 1 (relation mn_pair 2 (0 1) (delta 0 1)))) "
    "(attachments) (constants) (prims) (dynamic mn_pair) "
    "(rules "
      "(rule-def (rid 2) (variant \"all:mn_a/nonrec#0\") (nregs 2) (pre) "
        "(driver (scan (rel 0) (r 0))) "
        "(body (join (rel 0) (0) 0 (r 1))) "
        "(head (emit (rel 1) (0 1) (r 0) (r 1)))) "
      "(rule-def (rid 2) (variant \"all:mn_a/nonrec#1\") (nregs 2) (pre) "
        "(driver (scan (rel 0) (r 0))) "
        "(body (join-new (rel 0) (0) 0 (0) (r 1))) "
        "(head (emit (rel 1) (0 1) (r 1) (r 0))))) "
    "(meta (rule-meta (rid 2) (source \"mn.slog:9\"))))";
  const DecodedKernelPlan decoded = parse_kernel_plan(text);

  // pair(X,Y) :- a(Y), a(X) over a={1,2}, established counts, then the
  // deletion of a(2): remove it from the live indices (the set-overlay)
  // and stage the -1 premise transition.
  const auto load = [](Database& db) {
    db.addRelation("mn_a", 1);
    db.addRelation("mn_pair", 2);
    Relation* a = db.getRelation("mn_a");
    Relation* pair = db.getRelation("mn_pair");
    a->addIndex<1>({0}, false);
    a->addIndex<1>({0}, true);
    pair->addIndex<2>({0, 1}, false);
    pair->addIndex<2>({0, 1}, true);
    insert_nominal(a, {1});
    insert_nominal(a, {2});
    for (const std::array<u64, 2>& row :
         {std::array<u64, 2>{1, 1}, {1, 2}, {2, 1}, {2, 2}})
      insert_nominal(pair, {row[0], row[1]});
    Index** side = pair->ensureCountSidecar();
    const auto put = [&](u64 x, u64 y) {
      auto* index = static_cast<BTreeMapIndex<2>*>(side[buckethash(x)]);
      index->tree.insert2({x, y}, cnt_pack(false, 1, 0));
    };
    put(1, 1); put(1, 2); put(2, 1); put(2, 2);
    db.markCounted({"mn_pair"});
    const u64 deleted[1] = {2};
    seal_check(a->removeTupleAllIndicesPreservingCounts(deleted),
               "fixture: negative overlay removal failed");
    load_signed_delta(a, {{2}}, cnt_kind_premise, -1);
  };

  Database db(2);
  load(db);
  Relation* pair = db.getRelation("mn_pair");
  Stratum stratum("maint3neg-interp");
  register_maint_machinery(db, stratum, nullptr, pair, {0, 1});
  {
    // The edited input's native machinery: the full-index writer skips
    // negative-sign batches, and the DELTA-index writer installs the
    // removed rows the pre-state union view (join-new) reads.
    Relation* a = db.getRelation("mn_a");
    for (u16 b = 0; b < bucket_count; ++b)
    {
      stratum.addTask(phase_write,
        new WriteTask<1>(&db, a, {0}, false, b), true);
      stratum.addTask(phase_write,
        new WriteTask<1>(&db, a, {0}, true, b), false);
      stratum.addTask(phase_intern, new InternTask<1>(&db, a, {0}, b));
    }
  }
  const SealedKernelPlan sealed = seal_kernel_plan(decoded);
  CHECK(sealed.rules[0].maint && sealed.rules[0].sign == -1);
  attach_counted_rules(db, stratum, sealed);
  CHECK(drive_stratum_to_fixpoint(db, stratum));

  Database native_db(2);
  load(native_db);
  Relation* native_a = native_db.getRelation("mn_a");
  Relation* native_pair = native_db.getRelation("mn_pair");
  class NativePost final : public Task
  {
    Database* db;
    Relation* a;
    Relation* pair;
    Index** a_full;
    u16 bucket;
  public:
    NativePost(Database* d, Relation* rel_a, Relation* rel_pair, u16 b)
      : db(d), a(rel_a), pair(rel_pair),
        a_full(rel_a->getIndex({0}, false)), bucket(b) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      read_delta(a, bucket, db->getThreadCount(), [&](const u64* row) {
        join_all<1>(a_full, [&](const std::array<u64, 1>& m) {
          ++fires;
          emit_maint<2>(pair, cnt_kind_nonrec, -1, batch,
                        {row[0], m[0]}, {0, 1});
        });
      });
      pair->sendBatch(batch);
      if (fires) db->bumpFires("mn.slog:9", "all:mn_a", fires);
      return true;
    }
  };
  class NativePre final : public Task
  {
    Database* db;
    Relation* a;
    Relation* pair;
    Index** a_full;
    Index** a_delta;
    u16 bucket;
  public:
    NativePre(Database* d, Relation* rel_a, Relation* rel_pair, u16 b)
      : db(d), a(rel_a), pair(rel_pair),
        a_full(rel_a->getIndex({0}, false)),
        a_delta(rel_a->getIndex({0}, true)), bucket(b) {}
    bool work() override
    {
      InsertBatch* batch = new InsertBatch();
      u64 fires = 0;
      read_delta(a, bucket, db->getThreadCount(), [&](const u64* row) {
        join_all_new<1>(a_full, a_delta, [&](const std::array<u64, 1>& m) {
          ++fires;
          emit_maint<2>(pair, cnt_kind_nonrec, -1, batch,
                        {m[0], row[0]}, {0, 1});
        });
      });
      pair->sendBatch(batch);
      if (fires) db->bumpFires("mn.slog:9", "all:mn_a", fires);
      return true;
    }
  };
  Stratum native_stratum("maint3neg-native");
  register_maint_machinery(native_db, native_stratum, nullptr, native_pair,
                           {0, 1});
  for (u16 b = 0; b < bucket_count; ++b)
  {
    native_stratum.addTask(phase_write,
      new WriteTask<1>(&native_db, native_a, {0}, false, b), true);
    native_stratum.addTask(phase_write,
      new WriteTask<1>(&native_db, native_a, {0}, true, b), false);
    native_stratum.addTask(phase_intern,
      new InternTask<1>(&native_db, native_a, {0}, b));
    native_stratum.addTask(phase_read,
      new NativePost(&native_db, native_a, native_pair, b), true);
    native_stratum.addTask(phase_read,
      new NativePre(&native_db, native_a, native_pair, b), true);
  }
  CHECK(drive_stratum_to_fixpoint(native_db, native_stratum));

  // The three deleted pairs are gone with their sidecar entries erased;
  // the survivor keeps its word.  Deleted-pair fires: exactly one
  // decrement each (the dual partition never double-counts).
  const auto interp_words = sidecar_words<2>(pair);
  CHECK(interp_words == sidecar_words<2>(native_pair));
  const std::map<std::vector<u64>, u64> expected{
    {{1, 1}, cnt_pack(false, 1, 0)}};
  if (interp_words != expected)
  {
    dump_words("maint3neg interp", interp_words);
    dump_words("maint3neg expected", expected);
    std::cout << "maint3neg pair rows="
              << nominal_index_rows(pair, {0, 1}).size() << "\n";
  }
  CHECK(interp_words == expected);
  CHECK(nominal_index_rows(pair, {0, 1})
        == (std::vector<std::vector<u64>>{{1, 1}}));
  CHECK(nominal_index_rows(native_pair, {0, 1})
        == (std::vector<std::vector<u64>>{{1, 1}}));
  CHECK((db.fire_counts[{std::string("mn.slog:9"),
                         std::string("all:mn_a")}]) == 3);
  CHECK((native_db.fire_counts[{std::string("mn.slog:9"),
                                std::string("all:mn_a")}]) == 3);
  return true;
}

// The join-tomb cursor (maint4neg): live-master resolution first, the
// tombstone dictionary only on a complete live miss, and no row on a
// double miss -- differentially against native join_probe_tomb.
bool test_maint4neg_tomb_resolution()
{
  Database db(2);
  db.addStruct("tb_s", 2);
  db.addRelation("tb_d", 1);
  db.addRelation("tb_out", 1);
  Relation* s = db.getRelation("tb_s");
  Relation* d = db.getRelation("tb_d");
  Relation* out = db.getRelation("tb_out");
  s->addIndex<2>({1, 0}, false);
  s->addIndex<2>({0, 1}, false);
  d->addIndex<1>({0}, false);
  out->addIndex<1>({0}, false);
  // Live instance (2001, 5); tombstoned instance (3001, 7); content 9 was
  // never interned.  The maintained head holds both resolutions with
  // established nonrec support, so the sweep's decrements legally remove
  // them under the DRed fold.
  insert_nominal(s, {2001, 5});
  insert_nominal(s, {3001, 7});
  {
    const u64 dead[2] = {3001, 7};
    seal_check(s->tombstoneStructRow(dead), "fixture: tombstone failed");
  }
  insert_nominal(d, {5});
  insert_nominal(d, {7});
  insert_nominal(d, {9});
  insert_nominal(out, {2001});
  insert_nominal(out, {3001});
  {
    Index** side = out->ensureCountSidecar();
    for (u64 id : {u64{2001}, u64{3001}})
      static_cast<BTreeMapIndex<1>*>(side[buckethash(id)])
        ->tree.insert2({id}, cnt_pack(false, 1, 0));
    db.markCounted({"tb_out"});
  }
  load_signed_delta(d, {{5}, {7}, {9}}, cnt_kind_premise, -1);

  const std::string text =
    "(kernel-plan (abi 1) (flavor maint4neg) "
    "(relations "
      "(rel 0 (relation tb_d 1 (0))) "
      "(rel 1 (struct tb_s 2 (1 0) (0 1))) "
      "(rel 2 (relation tb_out 1 (0)))) "
    "(attachments) (constants) (prims) (dynamic tb_out) "
    "(rules "
      "(rule-def (rid 0) (variant \"all:tb_d/nonrec\") (nregs 2) (pre) "
        "(driver (scan (rel 0) (r 0))) "
        "(body (join-tomb (rel 1) (1 0) 1 (r 0) (r 1))) "
        "(head (emit (rel 2) (0) (r 1))))) "
    "(meta (rule-meta (rid 0) (source \"tb.slog:3\"))))";
  const SealedKernelPlan sealed = seal_kernel_plan(parse_kernel_plan(text));
  CHECK(sealed.rules[0].maint && sealed.rules[0].sign == -1);
  const auto* tomb = std::get_if<ProbePlan>(&sealed.rules[0].cursors[0]);
  CHECK(tomb != nullptr && tomb->tomb && tomb->struct_);

  Stratum stratum("maint4neg-tomb");
  // The arity-1 maintained head, with the DRed fold.
  {
    Relation* out2 = db.getRelation("tb_out");
    for (u16 b = 0; b < bucket_count; ++b)
      stratum.addTask(phase_write,
        new WriteTask<1>(&db, out2, {0}, false, b), true);
    stratum.addTask(phase_intern,
                    new MaintainTask<1>(&db, out2, {0}, 0, true));
  }
  attach_counted_rules(db, stratum, sealed);
  CHECK(drive_stratum_to_fixpoint(db, stratum));

  // Native reference over the same inputs.
  std::vector<u64> native_hits;
  Index** master = s->getIndex({1, 0}, false);
  for (u64 content : {u64{5}, u64{7}, u64{9}})
    join_probe_tomb<2>(s, master, {content, 0},
                       [&](const std::array<u64, 2>& m) {
      native_hits.push_back(m[1]);
    });
  std::sort(native_hits.begin(), native_hits.end());
  CHECK(native_hits == (std::vector<u64>{2001, 3001}));
  // The VM saw the same two resolutions: the live id and the tombstoned id;
  // content 9 double-missed and produced no row.  Both decrements landed:
  // the maintained head is empty with its sidecar entries erased.
  if ((db.fire_counts[{std::string("tb.slog:3"),
                       std::string("all:tb_d")}]) != 2)
  {
    std::cout << "tomb fires="
              << db.fire_counts[{std::string("tb.slog:3"),
                                 std::string("all:tb_d")}]
              << " out rows=" << nominal_index_rows(out, {0}).size()
              << "\n";
    dump_words("tomb out sidecar", sidecar_words<1>(out));
  }
  CHECK((db.fire_counts[{std::string("tb.slog:3"),
                         std::string("all:tb_d")}]) == 2);
  CHECK(nominal_index_rows(out, {0}).empty());
  CHECK(sidecar_words<1>(out).empty());
  return true;
}

// ===========================================================================
// M4N slice 1 substrate (docs/m4n-contract.md pins 3-4): the absent-old
// cursor's symmetric-difference equation, the view-only staged kind's two
// guards (never drives, never reaches a fold), and the typed refusals.
// ===========================================================================

namespace m4n_substrate
{

// Shared fixture: H(x) :- A(x), ~B(x) as its maint3neg lost-A version --
// drive A's staged deletions, test ~B at PRE state, decrement H.
// B is FINAL: live = {1}, staged delta = {1 (gained: in both), 2 (lost:
// delta only)}; 3 was never present.  pre(B) = FULL xor delta = {2}, so
// absence-at-pre holds for 1 and 3, not 2.
void run()
{
  const std::string text =
    "(kernel-plan (abi 1) (flavor maint3neg) "
    "(relations "
      "(rel 0 (relation na_a 1 (0))) "
      "(rel 1 (relation na_b 1 (0) (delta 0))) "
      "(rel 2 (relation na_h 1 (0) (delta 0)))) "
    "(attachments) (constants) (prims) (dynamic na_h) "
    "(rules "
      "(rule-def (rid 0) (variant \"all:na_a/nonrec\") (nregs 1) (pre) "
        "(driver (scan (rel 0) (r 0))) "
        "(body (absent-old (rel 1) (0) 1 (0) (r 0))) "
        "(head (emit (rel 2) (0) (r 0))))) "
    "(meta (rule-meta (rid 0) (source \"na.slog:3\"))))";
  const DecodedKernelPlan decoded = parse_kernel_plan(text);
  const auto& filter =
    std::get<FilterPlan>(decoded.rules[0].plan.body[0]);
  if (filter.view != AbsentView::pre || filter.delta_order.empty())
    throw std::runtime_error("m4n: absent-old decode shape");

  Database db(2);
  db.addRelation("na_a", 1);
  db.addRelation("na_b", 1);
  db.addRelation("na_h", 1);
  Relation* a = db.getRelation("na_a");
  Relation* b = db.getRelation("na_b");
  Relation* h = db.getRelation("na_h");
  a->addIndex<1>({0}, false);
  b->addIndex<1>({0}, false);
  b->addIndex<1>({0}, true);
  h->addIndex<1>({0}, false);
  h->addIndex<1>({0}, true);
  for (u64 x : {u64{1}, u64{2}, u64{3}}) insert_nominal(a, {x});
  insert_nominal(b, {1});
  // B's staged transitions ride the genuine path: view-kind batches whose
  // rows the delta-index WriteTask installs during the write phase (the
  // full-index writer skips the negative-sign row; the positive one dedups
  // against the live master).  Direct delta-index insertion would be wiped
  // by the run's entry finalize.
  load_signed_delta(b, {{1}}, cnt_kind_view, 1);
  load_signed_delta(b, {{2}}, cnt_kind_view, -1);
  for (u64 x : {u64{1}, u64{2}, u64{3}}) insert_nominal(h, {x});
  {
    Index** side = h->ensureCountSidecar();
    for (u64 x : {u64{1}, u64{2}, u64{3}})
      static_cast<BTreeMapIndex<1>*>(side[buckethash(x)])
        ->tree.insert2({x}, cnt_pack(false, 1, 0));
    db.markCounted({"na_h"});
  }
  // The drive: A's staged deletions {1,2,3}; plus one view-kind row that
  // the driver must SKIP (a drive from it would decrement H(9) -> counts
  // invalidation the assertions below would catch).
  load_signed_delta(a, {{1}, {2}, {3}}, cnt_kind_premise, -1);
  load_signed_delta(a, {{9}}, cnt_kind_view, -1);

  Stratum stratum("m4n-substrate");
  for (u16 bkt = 0; bkt < bucket_count; ++bkt)
  {
    stratum.addTask(phase_write,
      new WriteTask<1>(&db, b, {0}, false, bkt), true);
    stratum.addTask(phase_write,
      new WriteTask<1>(&db, b, {0}, true, bkt), false);
    stratum.addTask(phase_write,
      new WriteTask<1>(&db, h, {0}, false, bkt), true);
    stratum.addTask(phase_write,
      new WriteTask<1>(&db, h, {0}, true, bkt), false);
  }
  stratum.addTask(phase_intern, new MaintainTask<1>(&db, h, {0}, 0, false));
  const SealedKernelPlan sealed = seal_kernel_plan(decoded);
  attach_counted_rules(db, stratum, sealed);
  if (!drive_stratum_to_fixpoint(db, stratum))
    throw std::runtime_error("m4n: stratum did not settle");

  // Absence-at-pre held for 1 and 3: both retract; 2 survives with its
  // word; the view row 9 never drove.
  if (nominal_index_rows(h, {0})
      != (std::vector<std::vector<u64>>{{2}}))
  {
    std::cerr << "m4n h rows:";
    for (const auto& row : nominal_index_rows(h, {0}))
      std::cerr << " " << row[0];
    std::cerr << " | sidecar:";
    for (const auto& [key, word] : sidecar_words<1>(h))
      std::cerr << " " << key[0] << "=nr" << cnt_nonrec(word);
    std::cerr << " | fires: "
              << db.fire_counts[{std::string("na.slog:3"),
                                 std::string("all:na_a")}] << std::endl;
    throw std::runtime_error("m4n: healed content mismatch");
  }
  if (sidecar_words<1>(h)
      != (std::map<std::vector<u64>, u64>{{{2}, cnt_pack(false, 1, 0)}}))
    throw std::runtime_error("m4n: healed sidecar mismatch");
  if ((db.fire_counts[{std::string("na.slog:3"),
                       std::string("all:na_a")}]) != 2)
    throw std::runtime_error("m4n: fire count mismatch");
}

} // namespace m4n_substrate

bool test_m4n_absent_pre_and_view_kind()
{
  m4n_substrate::run();

  // A view-kind row reaching a maintenance fold dies loudly.  Entry-staged
  // batches retire at the first finalize before any intern runs, so the
  // guard is exercised by driving the fold directly -- in a re-execed
  // child (see probe_child_closure_fatal's rationale).
  CHECK(run_reexec_probe("--probe-view-fold-fatal"));

  // Typed refusals: pre/post absence views are maintenance-only, and the
  // delta ordering must be requisitioned and identical.
  const auto seal_rejects = [](SealErrorK kind, const std::string& text) {
    try { (void)seal_kernel_plan(parse_kernel_plan(text)); }
    catch (const SealError& error) { return error.kind() == kind; }
    catch (...) { return false; }
    return false;
  };
  const std::string base =
    "(kernel-plan (abi 1) (flavor maint3neg) "
    "(relations "
      "(rel 0 (relation nb_a 1 (0))) "
      "(rel 1 (relation nb_b 1 (0) (delta 0))) "
      "(rel 2 (relation nb_h 1 (0) (delta 0)))) "
    "(attachments) (constants) (prims) (dynamic nb_h) "
    "(rules "
      "(rule-def (rid 0) (variant \"all:nb_a/nonrec\") (nregs 1) (pre) "
        "(driver (scan (rel 0) (r 0))) "
        "(body (absent-old (rel 1) (0) 1 (0) (r 0))) "
        "(head (emit (rel 2) (0) (r 0))))) "
    "(meta (rule-meta (rid 0) (source \"nb.slog:3\"))))";
  CHECK(seal_kernel_plan(parse_kernel_plan(base)).rules[0].maint);
  CHECK(!seal_rejects(SealErrorK::capability,
        replace_once(base, "absent-old", "absent-new")));
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(
          replace_once(base, "(flavor maint3neg)", "(flavor count)"),
          "(driver (scan (rel 0) (r 0)))", "(driver (seeded))")));
  CHECK(seal_rejects(SealErrorK::index_requisition,
        replace_once(base, "(relation nb_b 1 (0) (delta 0))",
                     "(relation nb_b 1 (0))")));
  return true;
}

// Typed refusals for the counted vocabulary: the plan-attribute seal CHECK
// (no semijoin exists in counted plans), counted-only head forms in normal
// plans, struct probes in normal plans, and malformed fold kinds.
bool test_counted_plan_refusals()
{
  const auto seal_rejects = [](SealErrorK kind, const std::string& text) {
    try { (void)seal_kernel_plan(parse_kernel_plan(text)); }
    catch (const SealError& error) { return error.kind() == kind; }
    catch (...) { return false; }
    return false;
  };
  const std::string counted_base =
    "(kernel-plan (abi 1) (flavor count) "
    "(relations "
      "(rel 0 (relation cr_a 2 (0 1))) "
      "(rel 1 (relation cr_b 2 (0 1))) "
      "(rel 2 (struct cr_s 2 (1 0) (0 1)))) "
    "(attachments) (constants) (prims) (dynamic cr_b) "
    "(rules "
      "(rule-def (rid 0) (variant \"seeded/nonrec\") (nregs 2) (pre) "
        "(driver (seeded)) "
        "(body (join (rel 0) (0 1) 0 (r 0) (r 1))) "
        "(head (emit (rel 1) (0 1) (r 0) (r 1))))) "
    "(meta (rule-meta (rid 0) (source \"cr.slog:1\"))))";
  // The base counted plan seals.
  CHECK(seal_kernel_plan(parse_kernel_plan(counted_base)).rules[0].counted);
  // Plan-attribute 1: a semijoin exists filter inside a counted plan is a
  // typed seal refusal (body and pre positions).
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(counted_base,
          "(body (join (rel 0) (0 1) 0 (r 0) (r 1)))",
          "(body (join (rel 0) (0 1) 0 (r 0) (r 1)) "
                "(exists (rel 1) (0 1) 1 (r 0)))")));
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(counted_base, "(pre)",
                     "(pre (exists (rel 1) (0 1) 0))")));
  // Absence stays admitted (negation under ~ is not a semijoin filter).
  CHECK(!seal_rejects(SealErrorK::capability,
        replace_once(counted_base,
          "(body (join (rel 0) (0 1) 0 (r 0) (r 1)))",
          "(body (join (rel 0) (0 1) 0 (r 0) (r 1)) "
                "(absent (rel 1) (0 1) 1 (r 0)))")));
  // A counted rule variant without a fold kind, or with an unknown one.
  CHECK(seal_rejects(SealErrorK::variant_identity,
        replace_once(counted_base, "seeded/nonrec", "seeded")));
  CHECK(seal_rejects(SealErrorK::variant_identity,
        replace_once(counted_base, "seeded/nonrec", "seeded/banana")));
  // Counted-only forms refuse in normal plans: once/seeded drivers,
  // temp/lattice/mkstruct heads, struct probes.
  const std::string normal_base = replace_once(
    replace_once(counted_base, "(flavor count)", "(flavor normal)"),
    "seeded/nonrec", "seeded");
  CHECK(seal_rejects(SealErrorK::capability, normal_base));
  const std::string normal_scan = replace_once(normal_base,
    "(driver (seeded))", "(driver (scan (rel 0) (r 0) (r 1)))");
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(
          replace_once(normal_scan, "(body (join (rel 0) (0 1) 0 (r 0) (r 1)))",
                       "(body)"),
          "(head (emit (rel 1) (0 1) (r 0) (r 1)))",
          "(head (emit-temp (rel 1) (r 0) (r 1)))")));
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(
          replace_once(normal_scan, "(body (join (rel 0) (0 1) 0 (r 0) (r 1)))",
                       "(body)"),
          "(head (emit (rel 1) (0 1) (r 0) (r 1)))",
          "(head (emit (rel 1) (0 1) (r 0) (r 1)) "
                "(mkstruct (rel 2) (1 0) (r 2) (r 0)))")));
  CHECK(seal_rejects(SealErrorK::relation_kind,
        replace_once(
          replace_once(normal_scan, "(body (join (rel 0) (0 1) 0 (r 0) (r 1)))",
                       "(body (join (rel 2) (1 0) 1 (r 0) (r 2)))"),
          "(nregs 2)", "(nregs 3)")));
  // Struct probes admit no old/new views in counted plans (the maintenance
  // flavors' union-view resolutions do).
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(
          replace_once(counted_base,
            "(body (join (rel 0) (0 1) 0 (r 0) (r 1)))",
            "(body (join (rel 0) (0 1) 0 (r 0) (r 1)) "
                  "(join-old (rel 2) (1 0) 1 (1 0) (r 0) (r 2)))"),
          "(nregs 2)", "(nregs 3)")));
  // join-tomb belongs to the negative maintenance flavors alone.
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(
          replace_once(counted_base,
            "(body (join (rel 0) (0 1) 0 (r 0) (r 1)))",
            "(body (join (rel 0) (0 1) 0 (r 0) (r 1)) "
                  "(join-tomb (rel 2) (1 0) 1 (r 0) (r 2)))"),
          "(nregs 2)", "(nregs 3)")));
  // The maintenance-flavor policies, over a scan-driver base: join-tomb
  // refuses in the positive flavor; the negative flavors carry no semijoin
  // filters (seal CHECK); maint1 keeps semijoin lookahead admitted and
  // executes any exists verbatim.
  const std::string maint_base =
    "(kernel-plan (abi 1) (flavor maint1) "
    "(relations "
      "(rel 0 (relation cr_a 2 (0 1))) "
      "(rel 1 (relation cr_b 2 (0 1))) "
      "(rel 2 (struct cr_s 2 (1 0) (0 1)))) "
    "(attachments) (constants) (prims) (dynamic cr_b) "
    "(rules "
      "(rule-def (rid 0) (variant \"all:cr_a/nonrec\") (nregs 3) (pre) "
        "(driver (scan (rel 0) (r 0) (r 1))) (body) "
        "(head (emit (rel 1) (0 1) (r 0) (r 1))))) "
    "(meta (rule-meta (rid 0) (source \"cr.slog:1\"))))";
  CHECK(seal_kernel_plan(parse_kernel_plan(maint_base)).rules[0].maint);
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(maint_base, "(body)",
          "(body (join-tomb (rel 2) (1 0) 1 (r 0) (r 2)))")));
  CHECK(!seal_rejects(SealErrorK::capability,
        replace_once(
          replace_once(maint_base, "(flavor maint1)", "(flavor maint3neg)"),
          "(body)",
          "(body (join-tomb (rel 2) (1 0) 1 (r 0) (r 2)))")));
  CHECK(seal_rejects(SealErrorK::capability,
        replace_once(
          replace_once(maint_base, "(flavor maint1)", "(flavor maint3neg)"),
          "(body)", "(body (exists (rel 1) (0 1) 1 (r 0)))")));
  CHECK(!seal_rejects(SealErrorK::capability,
        replace_once(maint_base, "(body)",
                     "(body (exists (rel 1) (0 1) 1 (r 0)))")));
  return true;
}

bool test_seal_bind_scan_multihead_and_real_emit()
{
  const std::vector<RelationShape> shapes{
    {2, {{0, 1}}}, // 0 driving edge delta
    {2, {{0, 1}}}, // 1 full lookup
    {2, {{0, 1}}}, // 2 ordinary output
    {2, {{1, 0}}}  // 3 output whose physical order differs from storage
  };
  auto edge = make_relation("edge", 2, shapes[0].full_orders);
  auto lookup = make_relation("lookup", 2, shapes[1].full_orders);
  auto output = make_relation("output", 2, shapes[2].full_orders);
  auto mirror = make_relation("mirror", 2, shapes[3].full_orders);

  load_delta(edge.get(), {{1, 2}, {2, 3}, {1, 4}});
  insert_nominal(lookup.get(), {2, 8});
  insert_nominal(lookup.get(), {2, 1}); // fails neq(a,c) for driver (1,2)
  insert_nominal(lookup.get(), {3, 9});
  insert_nominal(lookup.get(), {4, 10});
  insert_nominal(output.get(), {1, 8}); // real emit must dedup this candidate

  RulePlan plan{
    41, 1, "scan-bound", 3, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{1, {0, 1}, 1, {1, 2}}, NeqPlan{0, 2}},
    {EmitPlan{2, {0, 1}, {0, 2}},
     EmitPlan{3, {1, 0}, {2, 0}}}
  };
  SealedRule sealed = seal_rule(plan, shapes);
  CHECK(sealed.max_depth == 1);
  CHECK(sealed.program.ops.size() == 5);
  CHECK(sealed.program.ops[2].kind == OpK::fire);
  BoundRule bound(std::move(sealed),
                  {edge.get(), lookup.get(), output.get(), mirror.get()});

  u64 fires = 0;
  std::array<u64, 2> candidates_by_sink{};
  for (u16 bucket = 0; bucket < bound.task_count(); ++bucket)
  {
    auto task = bound.make_task(bucket);
    while (!task->done())
    {
      const StopReason why = task->run_fast(1 + bucket % 5, 3);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
      if (why != StopReason::complete) task = task->continuation();
    }
    fires += task->result().fires;
    for (u16 sink : task->result().output_sinks)
    {
      CHECK(sink < candidates_by_sink.size());
      ++candidates_by_sink[sink];
    }
    bound.apply(task->result());
  }

  output->finalizeBatches();
  mirror->finalizeBatches();
  CHECK(fires == 3); // multi-head still counts each satisfying body once
  CHECK(candidates_by_sink == (std::array<u64, 2>{3, 3}));
  CHECK(nominal_delta_rows(output.get()) ==
        (std::vector<std::vector<u64>>{{1, 10}, {2, 9}}));
  CHECK(nominal_delta_rows(mirror.get()) ==
        (std::vector<std::vector<u64>>{{1, 8}, {1, 10}, {2, 9}}));
  return true;
}

bool test_seal_bind_probe_driver_and_task_partition()
{
  const std::vector<RelationShape> shapes{
    {2, {{0, 1}}}, {2, {{0, 1}}}
  };
  auto source = make_relation("source", 2, shapes[0].full_orders);
  auto output = make_relation("selected", 2, shapes[1].full_orders);
  insert_nominal(source.get(), {7, 11});
  insert_nominal(source.get(), {7, 12});
  insert_nominal(source.get(), {8, 99});

  RulePlan plan{
    42, 2, "probe-bound", 3, {{0, 7}, {2, 11}},
    {DriverK::probe_full, 0, {0, 1}, 1, {0, 1}},
    {NeqPlan{1, 2}},
    {EmitPlan{1, {0, 1}, {0, 1}}}
  };
  BoundRule bound(seal_rule(plan, shapes), {source.get(), output.get()});
  CHECK(bound.task_count() == bucket_count);
  u64 fires = 0;
  for (u16 bucket = 0; bucket < bound.task_count(); ++bucket)
  {
    auto task = bound.make_task(bucket);
    while (!task->done())
    {
      const StopReason why = task->run_fast(2, 2);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
      if (why != StopReason::complete) task = task->continuation();
    }
    fires += task->result().fires;
    bound.apply(task->result());
  }
  output->finalizeBatches();
  CHECK(fires == 1);
  CHECK(nominal_delta_rows(output.get()) ==
        (std::vector<std::vector<u64>>{{7, 12}}));

  // A fully-bound probe is one atomic task, not 32 duplicate bucket tasks.
  auto exact_out = make_relation("exact", 2, shapes[1].full_orders);
  RulePlan exact{
    43, 3, "probe-exact", 2, {{0, 7}, {1, 12}},
    {DriverK::probe_full, 0, {0, 1}, 2, {0, 1}},
    {ProbePlan{0, {0, 1}, 2, {0, 1}}},
    {EmitPlan{1, {0, 1}, {0, 1}}}
  };
  BoundRule exact_bound(seal_rule(exact, shapes),
                        {source.get(), exact_out.get()});
  CHECK(exact_bound.task_count() == 1);
  auto task = exact_bound.make_task(0);
  while (!task->done())
  {
    const StopReason why = task->run_fast(1, 1);
    CHECK(why == StopReason::quantum || why == StopReason::cursor
          || why == StopReason::complete);
    if (why != StopReason::complete) task = task->continuation();
  }
  exact_bound.apply(task->result());
  exact_out->finalizeBatches();
  CHECK(task->result().fires == 1);
  CHECK(nominal_delta_rows(exact_out.get()) ==
        (std::vector<std::vector<u64>>{{7, 12}}));
  return true;
}

bool test_bound_nested_ternary_probes_debug_and_sink_order()
{
  const std::vector<RelationShape> shapes{
    {2, {{0, 1}}},       // driver(a,k)
    {3, {{0, 1, 2}}},    // p(k,x,y), K=1
    {3, {{0, 1, 2}}},    // q(x,y,z), K=2
    {3, {{2, 0, 1}}}     // out(a,x,z), physically (z,a,x)
  };
  auto driver = make_relation("driver3", 2, shapes[0].full_orders);
  auto p = make_relation("p3", 3, shapes[1].full_orders);
  auto q = make_relation("q3", 3, shapes[2].full_orders);
  auto out = make_relation("out3", 3, shapes[3].full_orders);

  load_delta(driver.get(), {{50, 7}, {60, 8}});
  insert_nominal(p.get(), {7, 5, 6});
  insert_nominal(p.get(), {7, 5, 9});
  insert_nominal(p.get(), {8, 2, 3});
  insert_nominal(q.get(), {5, 6, 100});
  insert_nominal(q.get(), {5, 6, 101});
  insert_nominal(q.get(), {5, 9, 102});
  insert_nominal(q.get(), {2, 3, 200});

  RulePlan plan{
    46, 6, "nested-ternary", 5, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{1, {0, 1, 2}, 1, {1, 2, 3}},
     ProbePlan{2, {0, 1, 2}, 2, {2, 3, 4}}},
    {EmitPlan{3, {2, 0, 1}, {4, 0, 2}}}
  };
  BoundRule bound(seal_rule(plan, shapes),
                  {driver.get(), p.get(), q.get(), out.get()});

  struct BoundDebug final : DebugSink
  {
    std::vector<OwnedEvent> events;
    std::vector<Proof> proofs;
    DebugAction observe(const Event& event, const DebugView& view) override
    {
      events.emplace_back(event);
      if (event.kind == EventK::emit)
      {
        proofs.push_back(view.proof());
        return DebugAction::pause;
      }
      return DebugAction::continue_;
    }
  } debug;
  debug.mask = event_bit(EventK::probe_match) | event_bit(EventK::emit);

  // Model the specified first observed/native mid-read takeover: an emit has
  // committed into the read attempt (so a post-transition breakpoint sees
  // it), but the attempt has not touched relation state.  Dropping it and
  // rebuilding the bucket task from the immutable delta is exact replay.
  std::unique_ptr<Machine> abandoned;
  StopReason abandoned_stop = StopReason::complete;
  for (u16 bucket = 0; bucket < bound.task_count(); ++bucket)
  {
    abandoned = bound.make_task(bucket, &debug);
    abandoned_stop = abandoned->run(1000000, 1000000);
    if (abandoned_stop == StopReason::breakpoint) break;
  }
  CHECK(abandoned_stop == StopReason::breakpoint);
  CHECK(abandoned->result().outputs.size() == 1);
  CHECK(abandoned->result().output_sinks == (std::vector<u16>{0}));
  CHECK(nominal_delta_rows(out.get()).empty());
  abandoned.reset();

  u64 fires = 0;
  size_t breaks = 1;
  for (u16 bucket = 0; bucket < bound.task_count(); ++bucket)
  {
    auto task = bound.make_task(bucket, &debug);
    while (!task->done())
    {
      const StopReason why = task->run(2, 1);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::breakpoint || why == StopReason::complete);
      if (why == StopReason::breakpoint) ++breaks;
      if (why != StopReason::complete) task = task->continuation();
    }
    CHECK(std::all_of(task->result().output_sinks.begin(),
                      task->result().output_sinks.end(),
                      [](u16 sink) { return sink == 0; }));
    fires += task->result().fires;
    bound.apply(task->result());
  }
  out->finalizeBatches();

  CHECK(fires == 4);
  CHECK(breaks == 5);
  CHECK(debug.proofs.size() == 5);
  CHECK(std::all_of(debug.proofs.begin(), debug.proofs.end(),
                    [](const Proof& proof) {
                      return proof.driver.size() == 2
                          && proof.premises.size() == 2
                          && proof.premises[0].size() == 3
                          && proof.premises[1].size() == 3;
                    }));
  CHECK(std::all_of(debug.events.begin(), debug.events.end(),
                    [](const OwnedEvent& event) {
                      return event.kind != EventK::emit || event.port == 0;
                    }));
  // Bound-path identity: the D3 ordinal flows plan -> seal -> decoded
  // program -> every event; emit payloads carry the full head arity.
  CHECK(std::all_of(debug.events.begin(), debug.events.end(),
                    [](const OwnedEvent& event) {
                      return event.rule_id == 46 && event.variant_ordinal == 6;
                    }));
  CHECK(std::all_of(debug.events.begin(), debug.events.end(),
                    [](const OwnedEvent& event) {
                      return event.kind != EventK::emit
                          || event.tuple.size() == 3;
                    }));
  CHECK(nominal_delta_rows(out.get()) ==
        (std::vector<std::vector<u64>>{{50, 5, 100}, {50, 5, 101},
                                       {50, 5, 102}, {60, 2, 200}}));
  return true;
}

bool test_seal_and_binding_rejections()
{
  const std::vector<RelationShape> shapes{
    {2, {{0, 1}}}, {2, {{0, 1}}}
  };
  const RulePlan valid{
    44, 4, "validation", 3, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{0, {0, 1}, 1, {1, 2}}},
    {EmitPlan{1, {0, 1}, {0, 2}}}
  };
  const auto rejects = [](auto&& thunk) {
    try { thunk(); }
    catch (const SealError&) { return true; }
    return false;
  };
  const auto rejects_kind = [](SealErrorK kind, auto&& thunk) {
    try { thunk(); }
    catch (const SealError& error) { return error.kind() == kind; }
    return false;
  };

  RulePlan bad = valid;
  std::get<ProbePlan>(bad.body[0]).relation = 9;
  CHECK(rejects([&] { (void)seal_rule(bad, shapes); }));

  bad = valid;
  std::get<ProbePlan>(bad.body[0]).order = {1, 0};
  CHECK(rejects([&] { (void)seal_rule(bad, shapes); }));

  bad = valid;
  std::get<ProbePlan>(bad.body[0]).regs = {2, 1}; // r2 is unbound prefix
  CHECK(rejects([&] { (void)seal_rule(bad, shapes); }));

  bad = valid;
  bad.heads[0].regs[1] = 9;
  CHECK(rejects([&] { (void)seal_rule(bad, shapes); }));

  CHECK(rejects([&] {
    (void)seal_rules(std::vector<RulePlan>{valid, valid}, shapes);
  }));

  RulePlan bad_driver{
    45, 5, "bad-driver", 2, {},
    {DriverK::probe_full, 0, {0, 1}, 1, {0, 1}}, {},
    {EmitPlan{1, {0, 1}, {0, 1}}}
  };
  CHECK(rejects([&] { (void)seal_rule(bad_driver, shapes); }));

  const std::vector<RelationShape> view_shapes{
    {2, {{0, 1}}},
    {2, {{0, 1}}, RelationK::plain, {{0, 1}}},
    {2, {{0, 1}}}
  };
  const RulePlan valid_view{
    50, 10, "view-validation#10", 3, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{1, {0, 1}, 1, {1, 2}, ProbePlan::View::old, {0, 1}}},
    {EmitPlan{2, {0, 1}, {0, 2}}}
  };
  auto missing_delta_shape = view_shapes;
  missing_delta_shape[1].delta_orders.clear();
  CHECK(rejects_kind(SealErrorK::index_requisition, [&] {
    (void)seal_rule(valid_view, missing_delta_shape);
  }));

  RulePlan mismatched_view = valid_view;
  auto& mismatched_probe = std::get<ProbePlan>(mismatched_view.body[0]);
  mismatched_probe.delta_order = {1, 0};
  auto mismatch_shapes = view_shapes;
  mismatch_shapes[1].delta_orders.push_back({1, 0});
  CHECK(rejects_kind(SealErrorK::ordering, [&] {
    (void)seal_rule(mismatched_view, mismatch_shapes);
  }));

  RulePlan exists_zero = valid;
  exists_zero.body = {FilterPlan{FilterK::exists, 0, {0, 1}, 0, {}}};
  CHECK(rejects_kind(SealErrorK::factory, [&] {
    (void)seal_rule(exists_zero, shapes);
  }));

  auto view_driver = make_relation("view-reject-driver", 2, {{0, 1}});
  auto view_lookup = make_relation("view-reject-lookup", 2, {{0, 1}});
  auto view_output = make_relation("view-reject-output", 2, {{0, 1}});
  const SealedRule sealed_view = seal_rule(valid_view, view_shapes);
  CHECK(rejects_kind(SealErrorK::binding, [&] {
    BoundRule bound(sealed_view,
      {view_driver.get(), view_lookup.get(), view_output.get()});
    (void)bound;
  }));

  const std::vector<RelationShape> wide_shapes{
    {2, {{0, 1}}}, {4, {{0, 1, 2, 3}}}, {2, {{0, 1}}}
  };
  RulePlan wide_probe{
    47, 7, "no-factory", 5, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{1, {0, 1, 2, 3}, 1, {1, 2, 3, 4}}},
    {EmitPlan{2, {0, 1}, {0, 2}}}
  };
  SealedRule wide = seal_rule(wide_probe, wide_shapes);
  CHECK(wide.cursors.size() == 1); // full daemon arity capability, not 2/3-only

  RulePlan wide_head{
    48, 8, "wide-head", 5, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{1, {0, 1, 2, 3}, 1, {1, 2, 3, 4}}},
    {EmitPlan{1, {0, 1, 2, 3}, {1, 2, 3, 4}}}
  };
  SealedRule wide_emit = seal_rule(wide_head, wide_shapes);
  CHECK(wide_emit.program.ops.back().kind == OpK::emitn);
  CHECK(wide_emit.program.operands == (std::vector<u16>{1, 2, 3, 4}));

  const std::vector<RelationShape> wide_runtime_shapes{
    {2, {{0, 1}}}, {4, {{0, 1, 2, 3}}}, {4, {{0, 1, 2, 3}}}
  };
  auto wide_driver = make_relation("wide-driver", 2, {{0, 1}});
  auto wide_lookup = std::make_unique<Relation>("wide-lookup", 4, 0);
  auto wide_output = std::make_unique<Relation>("wide-output", 4, 0);
  wide_lookup->initShards(1);
  wide_output->initShards(1);
  wide_lookup->addIndex<4>({0, 1, 2, 3}, false);
  wide_output->addIndex<4>({0, 1, 2, 3}, false);
  load_delta(wide_driver.get(), {{50, 7}});
  const u64 wide_row[4]{7, 8, 9, 10};
  wide_lookup->insertTupleAllIndices(wide_row);
  RulePlan wide_runtime{
    49, 9, "wide-runtime", 5, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{1, {0, 1, 2, 3}, 1, {1, 2, 3, 4}}},
    {EmitPlan{2, {0, 1, 2, 3}, {1, 2, 3, 4}}}
  };
  BoundRule wide_bound(seal_rule(wide_runtime, wide_runtime_shapes),
    {wide_driver.get(), wide_lookup.get(), wide_output.get()});
  for (u16 bucket = 0; bucket < wide_bound.task_count(); ++bucket)
  {
    auto task = wide_bound.make_task(bucket);
    while (!task->done())
    {
      const StopReason why = task->run_fast(3, 2);
      CHECK(why == StopReason::quantum || why == StopReason::cursor
            || why == StopReason::complete);
    }
    wide_bound.apply(task->result());
  }
  wide_output->finalizeBatches();
  CHECK(nominal_delta_rows(wide_output.get()) ==
        (std::vector<std::vector<u64>>{{7, 8, 9, 10}}));

  auto r0 = make_relation("r0", 2, shapes[0].full_orders);
  auto wrong = make_relation("wrong", 3, {{0, 1, 2}});
  SealedRule sealed = seal_rule(valid, shapes);
  CHECK(rejects([&] {
    BoundRule bound(sealed, {r0.get(), wrong.get()});
    (void)bound;
  }));
  return true;
}

void benchmark_debug_masks()
{
  static volatile u64 bench_sink = 0;
  Fixture f;
  auto many = std::make_shared<std::vector<std::vector<u64>>>();
  many->reserve(200000);
  for (u64 i = 0; i < 200000; ++i) many->push_back({1000 + i, 1});
  auto drivers = std::const_pointer_cast<const std::vector<std::vector<u64>>>(many);

  struct MissWatch final : DebugSink
  {
    u64 calls = 0;
    DebugAction observe(const Event&, const DebugView&) override
    { ++calls; return DebugAction::continue_; }
  } masked, emit_watch;
  masked.mask = 0;
  emit_watch.mask = event_bit(EventK::emit);

  // Explicitly the micro-stepped observed policy: with a null or mask-0
  // sink the production `run` would select the fast loop, and this
  // benchmark's whole point is to price the observed loop and mask gating.
  auto one = [&](DebugSink* debug) {
    const auto t0 = std::chrono::steady_clock::now();
    Machine m(f.program, drivers, f.cursors(), debug, false);
    while (!m.done()) m.run_observed(std::numeric_limits<u64>::max(),
                                     std::numeric_limits<u64>::max());
    bench_sink = m.result().checksum;
    const double ms = std::chrono::duration<double, std::milli>(
      std::chrono::steady_clock::now() - t0).count();
    return std::pair<double, u64>{ms, m.result().output_count};
  };

  auto one_fast = [&] {
    const auto t0 = std::chrono::steady_clock::now();
    Machine m(f.program, drivers, f.cursors(), nullptr, false);
    while (!m.done()) m.run_fast(std::numeric_limits<u64>::max(),
                                 std::numeric_limits<u64>::max());
    bench_sink = m.result().checksum;
    const double ms = std::chrono::duration<double, std::milli>(
      std::chrono::steady_clock::now() - t0).count();
    return std::pair<double, u64>{ms, m.result().output_count};
  };

  auto native_one = [&] {
    const auto t0 = std::chrono::steady_clock::now();
    u64 count = 0, checksum = 0;
    for (const auto& d : *drivers)
    {
      const u64 a = d[0], b = d[1];
      join_probe<2, 1>(f.first.data(), {b, 0}, [&](const auto& m1) {
        const u64 c = m1[1];
        join_probe<2, 1>(f.second.data(), {c, 0}, [&](const auto& m2) {
          const u64 e = m2[1];
          if (a == e) return;
          ++count;
          checksum = (checksum * 1099511628211ull + a)
                   * 1099511628211ull + e;
        });
      });
    }
    bench_sink = checksum;
    const double ms = std::chrono::duration<double, std::milli>(
      std::chrono::steady_clock::now() - t0).count();
    return std::pair<double, u64>{ms, count};
  };

  (void)one(nullptr); // warm indices, allocator, and instruction cache
  auto best = [&](DebugSink* debug) {
    std::pair<double, u64> result{std::numeric_limits<double>::max(), 0};
    for (int i = 0; i < 7; ++i)
    {
      const auto current = one(debug);
      if (current.first < result.first) result = current;
    }
    return result;
  };
  auto best_native = [&] {
    std::pair<double, u64> result{std::numeric_limits<double>::max(), 0};
    for (int i = 0; i < 7; ++i)
    {
      const auto current = native_one();
      if (current.first < result.first) result = current;
    }
    return result;
  };
  auto best_fast = [&] {
    std::pair<double, u64> result{std::numeric_limits<double>::max(), 0};
    for (int i = 0; i < 7; ++i)
    {
      const auto current = one_fast();
      if (current.first < result.first) result = current;
    }
    return result;
  };
  const auto native = best_native();
  const auto fast = best_fast();
  const auto base = best(nullptr);
  const auto mask0 = best(&masked);
  const auto watched = best(&emit_watch);
  std::cout << "debug microbench (" << base.second << " candidates): native="
            << native.first << "ms vm-fast=" << fast.first << "ms ("
            << fast.first / native.first << "x) vm-micro=" << base.first
            << "ms (" << base.first / native.first << "x) mask0=" << mask0.first
            << "ms emit-callback=" << watched.first << "ms callbacks="
            << emit_watch.calls << " checksum=" << bench_sink << '\n';
}

} // namespace

[[noreturn]] static void probe_child_view_fold_fatal()
{
  alarm(20);
  const int devnull = open("/dev/null", O_WRONLY);
  dup2(devnull, 1);
  dup2(devnull, 2);
  Database db(1);
  db.addRelation("nv_h", 1);
  Relation* h = db.getRelation("nv_h");
  h->addIndex<1>({0}, false);
  InsertBatch* batch = new InsertBatch();
  batch->kind = cnt_kind_view;
  batch->sign = -1;
  batch->data[batch->usage++] = 7;
  h->getDelta().push_back(batch);
  MaintainTask<1> fold(&db, h, {0}, 0, false);
  fold.work();
  _exit(0); // reached only if the fold did NOT fatal
}

int main(int argc, char** argv)
{
  if (argc > 1 && std::string(argv[1]) == "--probe-closure-fatal")
    probe_child_closure_fatal();
  if (argc > 1 && std::string(argv[1]) == "--probe-view-fold-fatal")
    probe_child_view_fold_fatal();
  bool ok = true;
  ok &= test_uninterrupted_and_every_quantum();
  ok &= test_cursor_internal_pause_and_continuation_copy();
  ok &= test_parked_task_pins_immutable_program();
  ok &= test_plan_sized_deep_cursor_stack();
  ok &= test_breakpoints_are_post_transition_and_non_retriggering();
  ok &= test_selective_watch_proofs_and_failure_events();
  ok &= test_zero_mask_observer_has_zero_callbacks();
  ok &= test_join3_cursor_all_views_native_differential();
  ok &= test_join3_mixed_arm_arities();
  ok &= test_parsed_join3_and_typed_refusals();
  ok &= test_map_cursor_k0_native_differential();
  ok &= test_full_view_k0_cursor_native_differential();
  ok &= test_parsed_map_probes_and_typed_refusals();
  ok &= test_catalog_query_payload_parse_seal_bind();
  ok &= test_query_context_r2_modes_pagination_and_hygiene();
  ok &= test_view_and_filter_cursor_registrations();
  ok &= test_shared_sexp_reader_contract();
  ok &= test_parsed_view_and_filter_forms();
  ok &= test_parsed_primitives_letp_tycheck_native_differential();
  ok &= test_parsed_sidecar_scheduler_admission();
  ok &= test_parsed_sidecar_refusal_classes();
  ok &= test_real_interp_read_task_recursive_admission();
  ok &= test_counted_recursive_seeded_differential();
  ok &= test_counted_temp_struct_chain_differential();
  ok &= test_counted_chained_mkstruct_and_closure_fatal();
  ok &= test_counted_prim_fault_arm_contribution();
  ok &= test_maint1_positive_differential();
  ok &= test_maint3neg_negative_differential();
  ok &= test_maint4neg_tomb_resolution();
  ok &= test_m4n_absent_pre_and_view_kind();
  ok &= test_counted_plan_refusals();
  ok &= test_seal_bind_scan_multihead_and_real_emit();
  ok &= test_seal_bind_probe_driver_and_task_partition();
  ok &= test_bound_nested_ternary_probes_debug_and_sink_order();
  ok &= test_seal_and_binding_rejections();
  if (!ok) return 1;
  std::cout << "interpreter debug/operator tests passed\n";
  if (argc == 2 && std::string(argv[1]) == "--bench") benchmark_debug_masks();
  return 0;
}
