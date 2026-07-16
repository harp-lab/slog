// Executable specification for the production interpreter core in
// daemon/interp.h (docs/interp-core-contract.md; extracted at T2-A1).  The
// core types -- tri-state pull cursors, the decoded Program, the five-state
// Machine with fast/observed policies, mask-gated post-transition events,
// and attempt-local candidate ownership -- are instantiated from the
// production header; this file keeps only test fixtures, the differential
// logical model, and the narrow test-side Plan -> seal -> bind -> task slice
// (seal/bind move to daemon/plan.h at T2-A2).
//
// It exercises: exact continuation copies at every VM quantum 1..31,
// intra-match cursor pauses, a 96-level cursor stack, all eight event ports
// with breakpoints, bounded proof capture, seal/bind rejections, and real
// Relation indices and emit sinks with dedup.
//
//   clang++ -O2 -Wall -std=c++20 -pthread -fopenmp -Idaemon tests/interp-operator-tests.cpp -o /tmp/interp-tests -lgmp
//   /tmp/interp-tests [--bench]

#include "interp.h"
#include "operators.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <variant>
#include <vector>

using namespace slog;
using namespace slog::interp;

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

// --------------------------------------------------------------------------
// Test-side Plan -> seal -> bind -> task pipeline.  This is intentionally a
// narrow, liftable slice rather than a second daemon: normal tables only;
// scan-delta and full-prefix-probe drivers; full-prefix body probes; neq;
// ordinary arity-2/3 emits.  The seal inserts `fire` exactly once between the
// body and all heads.  Unsupported vocabulary is absent rather than guessed.

struct RelationShape
{
  u16 arity;
  std::vector<std::vector<u16>> full_orders;
};

enum class DriverK : u8 { scan_delta, probe_full };

struct DriverPlan
{
  DriverK kind;
  u16 relation;
  std::vector<u16> order; // empty for nominal-order scan
  u16 bound = 0;
  std::vector<u16> regs;  // nominal for scan, index order for probe
};

struct ProbePlan
{
  u16 relation;
  std::vector<u16> order;
  u16 bound;
  std::vector<u16> regs; // index order: bound prefix, then fresh suffix
};

struct NeqPlan { u16 left, right; };
using BodyPlan = std::variant<ProbePlan, NeqPlan>;

struct EmitPlan
{
  u16 relation;
  std::vector<u16> order;
  std::vector<u16> regs; // values in head-index order
};

struct RulePlan
{
  u32 rule_id;
  u32 variant_ordinal; // D3 RuleVariant ordinal (dense; unique per variant)
  std::string variant; // display metadata only
  u16 nregs;
  std::vector<std::pair<u16, u64>> preloads;
  DriverPlan driver;
  std::vector<BodyPlan> body;
  std::vector<EmitPlan> heads;
};

struct SealError : std::runtime_error
{
  using std::runtime_error::runtime_error;
};

struct SealedRule
{
  Program program; // carries nregs, ops, driver_regs, preloads, identity
  DriverPlan driver;
  std::vector<ProbePlan> probes;
  std::vector<EmitPlan> heads;
  std::vector<RelationShape> relations;
  u16 max_depth = 0;
};

static void seal_check(bool ok, const std::string& message)
{
  if (!ok) throw SealError(message);
}

static void validate_reg(u16 reg, u16 nregs, const char* where)
{
  seal_check(reg < nregs, std::string(where) + ": register out of range");
}

static const RelationShape& relation_shape(
  const std::vector<RelationShape>& rels, u16 slot, const char* where)
{
  seal_check(slot < rels.size(), std::string(where) + ": relation slot out of range");
  return rels[slot];
}

static void validate_order(const RelationShape& shape,
                           const std::vector<u16>& order,
                           const char* where)
{
  seal_check(order.size() == shape.arity,
             std::string(where) + ": ordering width mismatch");
  std::vector<bool> seen(shape.arity, false);
  for (u16 column : order)
  {
    seal_check(column < shape.arity,
               std::string(where) + ": ordering column out of range");
    seal_check(!seen[column], std::string(where) + ": ordering is not a permutation");
    seen[column] = true;
  }
  seal_check(std::find(shape.full_orders.begin(), shape.full_orders.end(), order)
               != shape.full_orders.end(),
             std::string(where) + ": ordering was not requisitioned");
}

// This is deliberately the same table the bind-time template ladder covers.
// Rejecting a syntactically valid but uninstantiated (A,K) at seal time keeps
// factory misses out of worker threads.
static bool supports_probe(u16 arity, u16 bound)
{
  return (arity == 2 || arity == 3) && bound >= 1 && bound <= arity;
}

static SealedRule seal_rule(const RulePlan& plan,
                            const std::vector<RelationShape>& relations)
{
  seal_check(plan.nregs != 0, "rule: empty register file");
  seal_check(!plan.heads.empty(), "rule: no head");
  seal_check(plan.heads.size() <= std::numeric_limits<u16>::max(),
             "rule: too many head sinks");

  SealedRule out;
  out.program.rule_id = plan.rule_id;
  out.program.variant_ordinal = plan.variant_ordinal;
  out.program.variant = plan.variant;
  out.program.nregs = plan.nregs;
  out.program.driver_regs = plan.driver.regs;
  out.program.preloads = plan.preloads;
  out.driver = plan.driver;
  out.heads = plan.heads;
  out.relations = relations;

  std::vector<bool> assigned(plan.nregs, false);
  for (const auto& [reg, _] : plan.preloads)
  {
    validate_reg(reg, plan.nregs, "preload");
    seal_check(!assigned[reg], "preload: register assigned twice");
    assigned[reg] = true;
  }

  const RelationShape& driver_rel =
    relation_shape(relations, plan.driver.relation, "driver");
  seal_check(plan.driver.regs.size() == driver_rel.arity,
             "driver: register width mismatch");
  if (plan.driver.kind == DriverK::scan_delta)
  {
    seal_check(plan.driver.order.empty(), "scan driver: unexpected ordering");
    seal_check(plan.driver.bound == 0, "scan driver: unexpected bound prefix");
    for (u16 reg : plan.driver.regs)
    {
      validate_reg(reg, plan.nregs, "scan driver");
      seal_check(!assigned[reg], "scan driver: output register already assigned");
      assigned[reg] = true;
    }
  }
  else
  {
    validate_order(driver_rel, plan.driver.order, "probe driver");
    seal_check(plan.driver.bound > 0 && plan.driver.bound <= driver_rel.arity,
               "probe driver: unsupported bound width");
    seal_check(supports_probe(driver_rel.arity, plan.driver.bound),
               "probe driver: no daemon factory capability");
    for (u16 i = 0; i < driver_rel.arity; ++i)
    {
      const u16 reg = plan.driver.regs[i];
      validate_reg(reg, plan.nregs, "probe driver");
      if (i < plan.driver.bound)
        seal_check(assigned[reg], "probe driver: unbound prefix register");
      else
      {
        seal_check(!assigned[reg], "probe driver: suffix register already assigned");
        assigned[reg] = true;
      }
    }
  }

  for (const BodyPlan& body : plan.body)
  {
    if (const auto* probe = std::get_if<ProbePlan>(&body))
    {
      const RelationShape& rel = relation_shape(relations, probe->relation, "probe");
      validate_order(rel, probe->order, "probe");
      seal_check(probe->regs.size() == rel.arity, "probe: register width mismatch");
      seal_check(probe->bound > 0 && probe->bound <= rel.arity,
                 "probe: unsupported bound width");
      seal_check(supports_probe(rel.arity, probe->bound),
                 "probe: no daemon cursor capability");
      for (u16 i = 0; i < rel.arity; ++i)
      {
        const u16 reg = probe->regs[i];
        validate_reg(reg, plan.nregs, "probe");
        if (i < probe->bound)
          seal_check(assigned[reg], "probe: unbound prefix register");
        else
        {
          seal_check(!assigned[reg], "probe: suffix register already assigned");
          assigned[reg] = true;
        }
      }
      const u16 cursor = out.probes.size();
      out.probes.push_back(*probe);
      out.program.ops.push_back({OpK::probe, cursor});
      ++out.max_depth;
    }
    else
    {
      const NeqPlan& neq = std::get<NeqPlan>(body);
      validate_reg(neq.left, plan.nregs, "neq");
      validate_reg(neq.right, plan.nregs, "neq");
      seal_check(assigned[neq.left] && assigned[neq.right],
                 "neq: read of unassigned register");
      out.program.ops.push_back({OpK::guard_neq, 0, neq.left, neq.right});
    }
  }

  // One instantiation counter per satisfying body, regardless of head count.
  out.program.ops.push_back({OpK::fire});
  for (size_t sink = 0; sink < plan.heads.size(); ++sink)
  {
    const EmitPlan& head = plan.heads[sink];
    const RelationShape& rel = relation_shape(relations, head.relation, "emit");
    validate_order(rel, head.order, "emit");
    seal_check(head.regs.size() == rel.arity, "emit: register width mismatch");
    seal_check(rel.arity == 2 || rel.arity == 3,
               "emit: prototype supports arity 2/3 only");
    for (u16 reg : head.regs)
    {
      validate_reg(reg, plan.nregs, "emit");
      seal_check(assigned[reg], "emit: read of unassigned register");
    }
    out.program.ops.push_back(
      {rel.arity == 2 ? OpK::emit2 : OpK::emit3, static_cast<u16>(sink),
       head.regs[0], head.regs[1], rel.arity == 3 ? head.regs[2] : u16{0}});
  }
  return out;
}

template <size_t N>
static std::array<u16, N> regs_array(const std::vector<u16>& regs, size_t off = 0)
{
  std::array<u16, N> out{};
  for (size_t i = 0; i < N; ++i) out[i] = regs[off + i];
  return out;
}

template <size_t N>
static std::array<u16, N> order_array(const std::vector<u16>& order)
{
  std::array<u16, N> out{};
  std::copy(order.begin(), order.end(), out.begin());
  return out;
}

class BoundRule
{
  SealedRule sealed;
  // The pinned immutable program generation, shared by every bucket task of
  // this variant (D11); parked continuations keep it alive past a retire.
  std::shared_ptr<const Program> pinned;
  std::vector<Relation*> frame;

  std::unique_ptr<PrefixCursor> make_probe(const ProbePlan& probe) const
  {
    Relation* rel = frame[probe.relation];
    Index** index = rel->getIndex(probe.order, false);
    const u16 arity = rel->getArity();
    if (arity == 2 && probe.bound == 1)
      return std::make_unique<ProbeCursor<2, 1>>(
        index, regs_array<1>(probe.regs), regs_array<1>(probe.regs, 1));
    if (arity == 2 && probe.bound == 2)
      return std::make_unique<ProbeCursor<2, 2>>(
        index, regs_array<2>(probe.regs), std::array<u16, 0>{});
    if (arity == 3 && probe.bound == 1)
      return std::make_unique<ProbeCursor<3, 1>>(
        index, regs_array<1>(probe.regs), regs_array<2>(probe.regs, 1));
    if (arity == 3 && probe.bound == 2)
      return std::make_unique<ProbeCursor<3, 2>>(
        index, regs_array<2>(probe.regs), regs_array<1>(probe.regs, 2));
    if (arity == 3 && probe.bound == 3)
      return std::make_unique<ProbeCursor<3, 3>>(
        index, regs_array<3>(probe.regs), std::array<u16, 0>{});
    throw SealError("bind: cursor factory ladder miss");
  }

  u64 preload(u16 reg) const
  {
    for (const auto& [r, value] : sealed.program.preloads)
      if (r == reg) return value;
    throw SealError("bind: probe-driver prefix is not a preload");
  }

  std::shared_ptr<const std::vector<std::vector<u64>>>
  driver_rows(u16 bucket) const
  {
    auto rows = std::make_shared<std::vector<std::vector<u64>>>();
    Relation* rel = frame[sealed.driver.relation];
    const u16 arity = rel->getArity();
    if (sealed.driver.kind == DriverK::scan_delta)
    {
      RefVec& refs = rel->getReadBucket(0, bucket);
      for (const TupleRef& ref : refs)
      {
        const u64* row = ref.batch->data + ref.offset;
        rows->emplace_back(row, row + arity);
      }
    }
    else if (arity == 2 && sealed.driver.bound == 2)
    {
      Index** index = rel->getIndex(sealed.driver.order, false);
      const u64 k0 = preload(sealed.driver.regs[0]);
      const u64 k1 = preload(sealed.driver.regs[1]);
      join_probe<2, 2>(index, {k0, k1}, [&](const auto& row) {
        rows->emplace_back(row.begin(), row.end());
      });
    }
    else if (arity == 2 && sealed.driver.bound == 1)
    {
      Index** index = rel->getIndex(sealed.driver.order, false);
      const u64 k0 = preload(sealed.driver.regs[0]);
      join_probe<2, 1>(index, {k0, 0}, [&](const auto& row) {
        if (buckethash(row[1]) == bucket)
          rows->emplace_back(row.begin(), row.end());
      });
    }
    else if (arity == 3 && sealed.driver.bound == 1)
    {
      Index** index = rel->getIndex(sealed.driver.order, false);
      const u64 k0 = preload(sealed.driver.regs[0]);
      join_probe<3, 1>(index, {k0, 0, 0}, [&](const auto& row) {
        if (buckethash(row[1]) == bucket)
          rows->emplace_back(row.begin(), row.end());
      });
    }
    else if (arity == 3 && sealed.driver.bound == 2)
    {
      Index** index = rel->getIndex(sealed.driver.order, false);
      const u64 k0 = preload(sealed.driver.regs[0]);
      const u64 k1 = preload(sealed.driver.regs[1]);
      join_probe<3, 2>(index, {k0, k1, 0}, [&](const auto& row) {
        if (buckethash(row[2]) == bucket)
          rows->emplace_back(row.begin(), row.end());
      });
    }
    else if (arity == 3 && sealed.driver.bound == 3)
    {
      Index** index = rel->getIndex(sealed.driver.order, false);
      const u64 k0 = preload(sealed.driver.regs[0]);
      const u64 k1 = preload(sealed.driver.regs[1]);
      const u64 k2 = preload(sealed.driver.regs[2]);
      join_probe<3, 3>(index, {k0, k1, k2}, [&](const auto& row) {
        rows->emplace_back(row.begin(), row.end());
      });
    }
    else
      throw SealError("bind: driver factory ladder miss");
    return std::const_pointer_cast<const std::vector<std::vector<u64>>>(rows);
  }

  static void emit_rows(Relation* rel, const EmitPlan& head,
                        const std::vector<std::vector<u64>>& rows)
  {
    InsertBatch* batch = new InsertBatch();
    if (rel->getArity() == 2)
    {
      Index** index = rel->getIndex(head.order, false);
      const auto ord = order_array<2>(head.order);
      for (const auto& row : rows)
        emit<2>(rel, index, batch, {row[0], row[1]}, ord);
    }
    else
    {
      Index** index = rel->getIndex(head.order, false);
      const auto ord = order_array<3>(head.order);
      for (const auto& row : rows)
        emit<3>(rel, index, batch, {row[0], row[1], row[2]}, ord);
    }
    // Standalone-test analogue of the generated task's trailing sendBatch.
    // Workloads stay below batch_size_max, so emit itself never flushes.
    if (batch->usage != 0) rel->getDelta().push_back(batch);
    else delete batch;
  }

public:
  BoundRule(SealedRule rule, std::vector<Relation*> binding)
    : sealed(std::move(rule)),
      pinned(std::make_shared<const Program>(sealed.program)),
      frame(std::move(binding))
  {
    seal_check(frame.size() == sealed.relations.size(),
               "bind: relation frame width mismatch");
    for (size_t i = 0; i < frame.size(); ++i)
      seal_check(frame[i] != nullptr
                   && frame[i]->getArity() == sealed.relations[i].arity,
                 "bind: relation arity mismatch");
  }

  u16 task_count() const
  {
    if (sealed.driver.kind == DriverK::scan_delta) return bucket_count;
    const u16 arity = frame[sealed.driver.relation]->getArity();
    return sealed.driver.bound == arity ? 1 : bucket_count;
  }

  std::unique_ptr<Machine> make_task(u16 bucket, DebugSink* debug = nullptr,
                                     bool capture_outputs = true) const
  {
    std::vector<std::unique_ptr<PrefixCursor>> cursors;
    for (const ProbePlan& probe : sealed.probes)
      cursors.push_back(make_probe(probe));
    return std::make_unique<Machine>(
      pinned, driver_rows(bucket), std::move(cursors), debug,
      capture_outputs);
  }

  void apply(const Attempt& attempt) const
  {
    std::vector<std::vector<std::vector<u64>>> per_head(sealed.heads.size());
    seal_check(attempt.outputs.size() == attempt.output_sinks.size(),
               "commit: candidate/sink count mismatch");
    for (size_t i = 0; i < attempt.outputs.size(); ++i)
    {
      const u16 sink = attempt.output_sinks[i];
      seal_check(sink < sealed.heads.size(), "commit: sink port out of range");
      per_head[sink].push_back(attempt.outputs[i]);
    }
    for (size_t i = 0; i < sealed.heads.size(); ++i)
      emit_rows(frame[sealed.heads[i].relation], sealed.heads[i], per_head[i]);
  }

  const SealedRule& definition() const { return sealed; }
};

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
    if (arity == 2) rel->addIndex<2>(order, false);
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

  RulePlan bad_driver{
    45, 5, "bad-driver", 2, {},
    {DriverK::probe_full, 0, {0, 1}, 1, {0, 1}}, {},
    {EmitPlan{1, {0, 1}, {0, 1}}}
  };
  CHECK(rejects([&] { (void)seal_rule(bad_driver, shapes); }));

  const std::vector<RelationShape> wide_shapes{
    {2, {{0, 1}}}, {4, {{0, 1, 2, 3}}}, {2, {{0, 1}}}
  };
  RulePlan no_factory{
    47, 7, "no-factory", 5, {},
    {DriverK::scan_delta, 0, {}, 0, {0, 1}},
    {ProbePlan{1, {0, 1, 2, 3}, 1, {1, 2, 3, 4}}},
    {EmitPlan{2, {0, 1}, {0, 2}}}
  };
  CHECK(rejects([&] { (void)seal_rule(no_factory, wide_shapes); }));

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

int main(int argc, char** argv)
{
  bool ok = true;
  ok &= test_uninterrupted_and_every_quantum();
  ok &= test_cursor_internal_pause_and_continuation_copy();
  ok &= test_parked_task_pins_immutable_program();
  ok &= test_plan_sized_deep_cursor_stack();
  ok &= test_breakpoints_are_post_transition_and_non_retriggering();
  ok &= test_selective_watch_proofs_and_failure_events();
  ok &= test_zero_mask_observer_has_zero_callbacks();
  ok &= test_seal_bind_scan_multihead_and_real_emit();
  ok &= test_seal_bind_probe_driver_and_task_partition();
  ok &= test_bound_nested_ternary_probes_debug_and_sink_order();
  ok &= test_seal_and_binding_rejections();
  if (!ok) return 1;
  std::cout << "interpreter debug/operator tests passed\n";
  if (argc == 2 && std::string(argv[1]) == "--bench") benchmark_debug_masks();
  return 0;
}
