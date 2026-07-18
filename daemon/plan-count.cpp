/** Thread-0 counted-interpreter extensions (counted-interp-contract.md
 * slice 1; interp-core-contract.md extension seams).
 *
 * Everything here extends the frozen core through its designed seams and
 * drives the identical shared machinery -- never a re-implementation:
 *
 *   - the count sinks call the native counting emitters (emit_count,
 *     emit_temp, emit_lattice_count, emit_struct_count in operators.h), so
 *     kind-tagged contribution batches reach the unchanged CountTask /
 *     CountStructTask folds (cnt_apply, daemon/counts.h);
 *   - the mkstruct resolution cursor wraps the ordinary erased probe and
 *     adds only the settled-fixpoint closure stance (zero-match exhaustion
 *     is a loud fatal, mirroring emit_struct_count);
 *   - the installer mirrors the native counted plugin's effect sequence
 *     byte for byte: relations/indices, counted-head task registration
 *     (rule head targets plus the declared prim-error arms), fire-once
 *     read scheduling, sorted read manifests, push + continueRun.
 *
 * No core opcode, VM arm, cursor method, or dispatch changed.
 */

#include "plan-count.h"
#include "daemon.h"

#include <cstdlib>
#include <set>

namespace slog
{
namespace interp
{

namespace
{

// ---------------------------------------------------------------------------
// Flavored sinks (thread-0 sink-factory region).
// ---------------------------------------------------------------------------

// Counted table head: closure CHECK against the master, kind-tagged batch
// (emit_count).  Tuples arrive in head-index order, exactly like SetSink.
template <u16 A>
class CountSetSink final : public BoundSink
{
  Relation* relation;
  Index** index;
  u8 kind;
  InsertBatch* batch = new InsertBatch();
  std::array<u16, A> order{};

public:
  CountSetSink(Relation* rel, Index** idx, const std::vector<u16>& ord, u8 k)
    : relation(rel), index(idx), kind(k)
  {
    std::copy(ord.begin(), ord.end(), order.begin());
  }

  ~CountSetSink() override { delete batch; }

  void stage(TupleView tuple) override
  {
    if (tuple.size() != A) fatal("interpreted count sink arity mismatch");
    std::array<u64, A> values{};
    std::copy(tuple.begin(), tuple.end(), values.begin());
    emit_count<A>(relation, index, kind, batch, values, order);
  }

  void flush() override
  {
    relation->sendBatch(batch);
    batch = new InsertBatch();
  }
};

// Temp head: nominal-order append with no dedup and no kind (emit_temp);
// temps carry no count tasks, so their batches stay set-semantics.
template <u16 A>
class TempSink final : public BoundSink
{
  Relation* relation;
  InsertBatch* batch = new InsertBatch();

public:
  explicit TempSink(Relation* rel) : relation(rel) {}

  ~TempSink() override { delete batch; }

  void stage(TupleView tuple) override
  {
    if (tuple.size() != A) fatal("interpreted temp sink arity mismatch");
    std::array<u64, A> values{};
    std::copy(tuple.begin(), tuple.end(), values.begin());
    emit_temp<A>(relation, batch, values);
  }

  void flush() override
  {
    relation->sendBatch(batch);
    batch = new InsertBatch();
  }
};

// Nominal-order kind-tagged contribution rows (emit_lattice_count): lattice
// heads preserve non-winning contributions, and mkstruct heads stage their
// full storage-order row here once the resolution cursor has bound the id.
template <u16 A>
class KindBatchSink final : public BoundSink
{
  Relation* relation;
  u8 kind;
  InsertBatch* batch = new InsertBatch();

public:
  KindBatchSink(Relation* rel, u8 k) : relation(rel), kind(k) {}

  ~KindBatchSink() override { delete batch; }

  void stage(TupleView tuple) override
  {
    if (tuple.size() != A) fatal("interpreted kind-batch sink arity mismatch");
    std::array<u64, A> values{};
    std::copy(tuple.begin(), tuple.end(), values.begin());
    emit_lattice_count<A>(relation, kind, batch, values);
  }

  void flush() override
  {
    relation->sendBatch(batch);
    batch = new InsertBatch();
  }
};

// Counted struct sink over content fields (the tycheck diversion): resolve
// the interned id by master probe -- fatal on a miss -- and batch the full
// storage-order row with the rule's kind (emit_struct_count).
template <u16 A>
class StructCountSink final : public BoundSink
{
  Relation* relation;
  Index** master;
  u8 kind;
  InsertBatch* batch = new InsertBatch();
  std::array<u16, A> order{};

public:
  StructCountSink(Relation* rel, Index** idx, const std::vector<u16>& ord,
                  u8 k)
    : relation(rel), master(idx), kind(k)
  {
    std::copy(ord.begin(), ord.end(), order.begin());
  }

  ~StructCountSink() override { delete batch; }

  void stage(TupleView tuple) override
  {
    if (tuple.size() != A - 1)
      fatal("interpreted struct count sink arity mismatch");
    std::array<u64, A - 1> fields{};
    std::copy(tuple.begin(), tuple.end(), fields.begin());
    emit_struct_count<A>(relation, master, kind, batch, fields, order);
  }

  void flush() override
  {
    relation->sendBatch(batch);
    batch = new InsertBatch();
  }
};

// ---------------------------------------------------------------------------
// Arity ladders (the same out-of-line pattern as plan.cpp's core factories:
// one instantiation per arity, capability miss = typed install-time error).
// ---------------------------------------------------------------------------

template <u16 A>
std::unique_ptr<BoundSink> count_sink_ladder(
  u16 arity, Relation* relation, Index** index,
  const std::vector<u16>& order, u8 kind)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)relation; (void)index; (void)order; (void)kind;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<CountSetSink<A>>(relation, index, order, kind);
    return count_sink_ladder<A - 1>(arity, relation, index, order, kind);
  }
}

template <u16 A>
std::unique_ptr<BoundSink> temp_sink_ladder(u16 arity, Relation* relation)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)relation;
    return nullptr;
  }
  else
  {
    if (arity == A) return std::make_unique<TempSink<A>>(relation);
    return temp_sink_ladder<A - 1>(arity, relation);
  }
}

template <u16 A>
std::unique_ptr<BoundSink> kind_batch_sink_ladder(
  u16 arity, Relation* relation, u8 kind)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)relation; (void)kind;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<KindBatchSink<A>>(relation, kind);
    return kind_batch_sink_ladder<A - 1>(arity, relation, kind);
  }
}

template <u16 A>
std::unique_ptr<BoundSink> struct_count_sink_ladder(
  u16 arity, Relation* relation, Index** master,
  const std::vector<u16>& order, u8 kind)
{
  if constexpr (A <= 1)
  {
    (void)arity; (void)relation; (void)master; (void)order; (void)kind;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<StructCountSink<A>>(relation, master, order,
                                                  kind);
    return struct_count_sink_ladder<A - 1>(arity, relation, master, order,
                                           kind);
  }
}

// ---------------------------------------------------------------------------
// The mkstruct resolution cursor: delegate to the ordinary erased probe and
// add the settled-fixpoint closure stance.  A count-flavor construction can
// only reference content the original run interned, so exhausting without a
// single match is corruption, not emptiness (docs/incremental.md 8B.1).
// ---------------------------------------------------------------------------

class StructResolveCursor final : public PrefixCursor
{
  std::unique_ptr<PrefixCursor> inner;
  std::string relation_name;
  bool matched = false;

public:
  StructResolveCursor(std::unique_ptr<PrefixCursor> cursor, std::string name)
    : inner(std::move(cursor)), relation_name(std::move(name)) {}

  StructResolveCursor(const StructResolveCursor& other)
    : inner(other.inner->clone()), relation_name(other.relation_name),
      matched(other.matched) {}

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<StructResolveCursor>(*this);
  }

  void open(const u64* regs) override
  {
    matched = false;
    inner->open(regs);
  }

  CursorResult next(u64* regs, WorkBudget& budget) override
  {
    const CursorResult result = inner->next(regs, budget);
    if (result == CursorResult::match)
      matched = true;
    else if (result == CursorResult::exhausted && !matched)
      fatal("count round derived an uninterned " + relation_name
            + " instance -- the fixpoint is not settled "
              "(docs/incremental.md 8B.1)");
    return result;
  }

  TupleView current() const override { return inner->current(); }
  u16 premise_count() const override { return inner->premise_count(); }
  TupleView premise(u16 index) const override { return inner->premise(index); }
};

// ---------------------------------------------------------------------------
// Runtime task-registration ladders (the native flavored plugin's per-arity
// CountTask/CountStructTask boilerplate, driven from the sealed plan).
// ---------------------------------------------------------------------------

template <u16 A>
void count_task_ladder(u16 arity, Database* db, Stratum* stratum,
                       Relation* relation, bool is_struct)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)db; (void)stratum; (void)relation; (void)is_struct;
    fatal("count install: counted-head task ladder miss");
  }
  else
  {
    if (arity == A)
    {
      for (u16 b = 0; b < bucket_count; ++b)
        stratum->addTask(phase_intern,
          is_struct
            ? static_cast<Task*>(new CountStructTask<A>(db, relation, b))
            : static_cast<Task*>(new CountTask<A>(db, relation, b)),
          false);
      return;
    }
    count_task_ladder<A - 1>(arity, db, stratum, relation, is_struct);
  }
}

template <u16 A>
void add_index_ladder(u16 arity, Relation* relation,
                      const std::vector<u16>& order, bool map)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)relation; (void)order; (void)map;
    fatal("count install: index ladder miss");
  }
  else
  {
    if (arity == A)
    {
      if (map) relation->addMapIndex<A>(order);
      else relation->addIndex<A>(order, false);
      return;
    }
    add_index_ladder<A - 1>(arity, relation, order, map);
  }
}

const char* const prim_error_arm_names[] = {
  "div_by_zero", "modulo_by_zero", "int_overflow", "nan_result",
  "toint_range", "type_mismatch", "mpz_overflow", "mpz_table_overflow"};

} // namespace

// ---------------------------------------------------------------------------
// Exported thread-0 factories (declared in plan.h beside the core ones).
// ---------------------------------------------------------------------------

std::unique_ptr<BoundSink> make_count_sink(
  u16 arity, Relation* relation, Index** index,
  const std::vector<u16>& order, u8 kind)
{
  if (arity == 0 || arity > max_daemon_arity || relation == nullptr
      || order.size() != arity
      || (kind != cnt_kind_nonrec && kind != cnt_kind_rec))
    throw SealError(SealErrorK::factory,
                    "bind: count sink factory capability miss");
  auto result = count_sink_ladder<max_daemon_arity>(arity, relation, index,
                                                    order, kind);
  if (!result)
    throw SealError(SealErrorK::factory, "bind: count sink ladder miss");
  return result;
}

std::unique_ptr<BoundSink> make_temp_sink(u16 arity, Relation* relation)
{
  if (arity == 0 || arity > max_daemon_arity || relation == nullptr)
    throw SealError(SealErrorK::factory,
                    "bind: temp sink factory capability miss");
  auto result = temp_sink_ladder<max_daemon_arity>(arity, relation);
  if (!result)
    throw SealError(SealErrorK::factory, "bind: temp sink ladder miss");
  return result;
}

std::unique_ptr<BoundSink> make_kind_batch_sink(
  u16 arity, Relation* relation, u8 kind)
{
  if (arity == 0 || arity > max_daemon_arity || relation == nullptr
      || (kind != cnt_kind_nonrec && kind != cnt_kind_rec))
    throw SealError(SealErrorK::factory,
                    "bind: kind-batch sink factory capability miss");
  auto result = kind_batch_sink_ladder<max_daemon_arity>(arity, relation,
                                                         kind);
  if (!result)
    throw SealError(SealErrorK::factory, "bind: kind-batch sink ladder miss");
  return result;
}

std::unique_ptr<BoundSink> make_struct_count_sink(
  u16 arity, Relation* relation, Index** master,
  const std::vector<u16>& order, u8 kind)
{
  if (arity < 2 || arity > max_daemon_arity || relation == nullptr
      || order.size() != arity
      || (kind != cnt_kind_nonrec && kind != cnt_kind_rec))
    throw SealError(SealErrorK::factory,
                    "bind: struct count sink factory capability miss");
  auto result = struct_count_sink_ladder<max_daemon_arity>(arity, relation,
                                                           master, order,
                                                           kind);
  if (!result)
    throw SealError(SealErrorK::factory,
                    "bind: struct count sink ladder miss");
  return result;
}

std::unique_ptr<PrefixCursor> make_struct_resolve_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs, u16 bound,
  const std::string& relation_name)
{
  if (arity < 2 || bound + 1 != arity)
    throw SealError(SealErrorK::factory,
                    "bind: struct resolve factory capability miss");
  return std::make_unique<StructResolveCursor>(
    make_set_probe_cursor(arity, index, regs, bound), relation_name);
}

void emit_pending_error_count_nonrec(Database* db, const char* loc)
{
  emit_pending_error_count(db, loc, cnt_kind_nonrec);
}

void emit_pending_error_count_rec(Database* db, const char* loc)
{
  emit_pending_error_count(db, loc, cnt_kind_rec);
}

// ---------------------------------------------------------------------------
// The installer: one sealed counted plan -> one resident count-round stratum,
// mirroring the native flavored plugin's slog_plugin effect for effect.
// ---------------------------------------------------------------------------

void install_count_stratum(Daemon* daemon, const std::string& name,
                           const SealedKernelPlan& plan)
{
  seal_check(plan.flavor == "count", SealErrorK::flavor,
             "install: not a counted plan");
  Database* db = daemon->db();
  Stratum* stratum = daemon->beginStratumDelta(name);
  if (stratum == nullptr) return;

  // Relations and indices: getRelation-or-add with the native arity fatal;
  // full orderings only (delta/seeded-only are never requisitioned by
  // counted plans).  A missing lattice cannot be re-declared from the plan's
  // structural shape alone -- and a resident count round always finds it.
  for (const RelationBinding& binding : plan.bindings)
  {
    Relation* relation = db->getRelation(binding.name);
    if (relation == nullptr)
    {
      if (binding.shape.temp)
        db->addTempRelation(binding.name, binding.shape.arity);
      else if (binding.shape.kind == RelationK::struct_)
        db->addStruct(binding.name, binding.shape.arity);
      else if (binding.shape.kind == RelationK::plain)
        db->addRelation(binding.name, binding.shape.arity);
      else
        fatal("count install: lattice relation is absent: " + binding.name);
      relation = db->getRelation(binding.name);
    }
    if (relation->getArity() != binding.shape.arity)
      fatal("Relation already exists at incorrect arity.");
    for (const std::vector<u16>& order : binding.shape.full_orders)
      add_index_ladder<max_daemon_arity>(
        binding.shape.arity, relation, order,
        binding.shape.kind == RelationK::lattice);
  }

  // Counted-head classification (mirrors emit-cpp's counted-heads): every
  // rule sink target -- emit / mkstruct / emit-lat heads and the tycheck
  // diversion's malformed_deduction -- plus the declared prim-error arms.
  // Temps are staging, never counted.
  std::set<u16> counted_slots;
  for (const SealedRule& rule : plan.rules)
  {
    for (const EmitPlan& head : rule.heads)
      if (head.head_kind != HeadK::temp)
        counted_slots.insert(head.relation);
    for (const EmitPlan& effect : rule.effects)
      counted_slots.insert(effect.relation);
  }
  for (const RelationBinding& binding : plan.bindings)
    for (const char* arm : prim_error_arm_names)
      if (binding.name == arm)
        counted_slots.insert(binding.slot);
  for (const u16 slot : counted_slots)
  {
    const RelationBinding& binding = plan.bindings[slot];
    Relation* relation = db->getRelation(binding.name);
    count_task_ladder<max_daemon_arity>(
      binding.shape.arity, db, stratum, relation,
      binding.shape.kind == RelationK::struct_);
  }

  // Bind through the pending count-round environment beginStratumDelta set
  // up, then schedule the reads: once/seeded rules are the fire-once shape
  // (one task, first iteration only), temp-driven scans run per bucket
  // every iteration -- the native counted plugin's exact scheduling.
  const auto rules = bind_kernel_plan(plan, *db);
  for (const auto& rule : rules)
  {
    const DriverK kind = rule->definition().driver.kind;
    const bool fire_once = kind == DriverK::once || kind == DriverK::seeded;
    rule->attach(db, stratum, fire_once);
  }

  // Read manifest: driver and body/pre probe relations (resolve cursors are
  // lowered head constructions, not reads), sorted by name like the native
  // emission; dynamic manifest verbatim from the plan.
  std::set<std::string> read_rels;
  for (const SealedRule& rule : plan.rules)
  {
    if (rule.driver.kind == DriverK::scan_delta
        || rule.driver.kind == DriverK::probe_full)
      read_rels.insert(plan.bindings[rule.driver.relation].name);
    for (const StraightPlan& op : rule.preops)
      if (const auto* filter = std::get_if<FilterPlan>(&op))
        read_rels.insert(plan.bindings[filter->relation].name);
    for (const CursorPlan& cursor : rule.cursors)
    {
      if (const auto* probe = std::get_if<ProbePlan>(&cursor))
      {
        if (!probe->resolve)
          read_rels.insert(plan.bindings[probe->relation].name);
      }
      else if (const auto* filter = std::get_if<FilterPlan>(&cursor))
        read_rels.insert(plan.bindings[filter->relation].name);
      else
      {
        const Join3Plan& join3 = std::get<Join3Plan>(cursor);
        read_rels.insert(plan.bindings[join3.left.relation].name);
        read_rels.insert(plan.bindings[join3.right.relation].name);
      }
    }
  }
  for (const std::string& relation : read_rels)
    stratum->addReadRel(relation);
  for (const std::string& relation : plan.dynamic_names)
    stratum->addDynamicRel(relation);

  daemon->push(stratum);
  daemon->continueRun();
}

bool maybe_interp_count_plugin(Daemon* daemon, const std::string& path)
{
  static const bool enabled = [] {
    const char* value = std::getenv("SLOG_COUNT_INTERP");
    return value != nullptr && *value != '\0'
        && std::string_view(value) != "0";
  }();
  if (!enabled) return false;
  const size_t slash = path.rfind('/');
  const std::string file =
    slash == std::string::npos ? path : path.substr(slash + 1);
  const size_t tag = file.find("_count.");
  if (tag == std::string::npos || file.size() < 3
      || file.compare(file.size() - 3, 3, ".so") != 0)
    return false;
  const std::string stem = file.substr(0, tag) + "_count";
  const std::string plan_path =
    (slash == std::string::npos ? std::string() : path.substr(0, slash + 1))
    + stem + ".plan";
  try
  {
    const DecodedKernelPlan decoded = parse_kernel_plan_file(plan_path);
    const SealedKernelPlan sealed = seal_kernel_plan(decoded, daemon->db());
    install_count_stratum(daemon, stem, sealed);
  }
  catch (const std::exception& error)
  {
    fatal("SLOG_COUNT_INTERP: counted plan install failed for " + plan_path
          + ": " + error.what());
  }
  return true;
}

} // namespace interp
} // namespace slog
