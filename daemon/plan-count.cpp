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

// Maintenance table head: signed kind-tagged support contribution
// (emit_maint) -- no probe, no dedup; MaintainTask's serial fold owns
// membership transitions.  Tuples arrive in head-index order.
template <u16 A>
class MaintSetSink final : public BoundSink
{
  Relation* relation;
  u8 kind;
  s8 sign;
  InsertBatch* batch = new InsertBatch();
  std::array<u16, A> order{};

public:
  MaintSetSink(Relation* rel, const std::vector<u16>& ord, u8 k, s8 s)
    : relation(rel), kind(k), sign(s)
  {
    std::copy(ord.begin(), ord.end(), order.begin());
  }

  ~MaintSetSink() override { delete batch; }

  void stage(TupleView tuple) override
  {
    if (tuple.size() != A) fatal("interpreted maint sink arity mismatch");
    std::array<u64, A> values{};
    std::copy(tuple.begin(), tuple.end(), values.begin());
    emit_maint<A>(relation, kind, sign, batch, values, order);
  }

  void flush() override
  {
    relation->sendBatch(batch);
    batch = new InsertBatch();
  }
};

// Maintenance lattice head: signed nominal-order contribution rows
// (emit_lattice_maint) for LatticeMaintainTask's contributor fold.
template <u16 A>
class LatticeMaintSink final : public BoundSink
{
  Relation* relation;
  u8 kind;
  s8 sign;
  InsertBatch* batch = new InsertBatch();

public:
  LatticeMaintSink(Relation* rel, u8 k, s8 s)
    : relation(rel), kind(k), sign(s) {}

  ~LatticeMaintSink() override { delete batch; }

  void stage(TupleView tuple) override
  {
    if (tuple.size() != A)
      fatal("interpreted lattice maint sink arity mismatch");
    std::array<u64, A> values{};
    std::copy(tuple.begin(), tuple.end(), values.begin());
    emit_lattice_maint<A>(relation, kind, sign, batch, values);
  }

  void flush() override
  {
    relation->sendBatch(batch);
    batch = new InsertBatch();
  }
};

// Maintenance struct head: signed construction with the 0-placeholder id
// (emit_struct_maint) -- the id CANNOT resolve at emit time (a positive may
// be the first derivation of fresh content; a negative may reference a row
// only the tombstone dictionary still knows); MaintainStructTask's serial
// fold owns resolution.  Fields arrive in master-content order.
template <u16 A>
class StructMaintSink final : public BoundSink
{
  Relation* relation;
  u8 kind;
  s8 sign;
  InsertBatch* batch = new InsertBatch();
  std::array<u16, A> order{};

public:
  StructMaintSink(Relation* rel, const std::vector<u16>& ord, u8 k, s8 s)
    : relation(rel), kind(k), sign(s)
  {
    std::copy(ord.begin(), ord.end(), order.begin());
  }

  ~StructMaintSink() override { delete batch; }

  void stage(TupleView tuple) override
  {
    if (tuple.size() != A - 1)
      fatal("interpreted struct maint sink arity mismatch");
    std::array<u64, A - 1> fields{};
    std::copy(tuple.begin(), tuple.end(), fields.begin());
    emit_struct_maint<A>(relation, kind, sign, batch, fields, order);
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
std::unique_ptr<BoundSink> maint_sink_ladder(
  u16 arity, Relation* relation, const std::vector<u16>& order,
  u8 kind, s8 sign)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)relation; (void)order; (void)kind; (void)sign;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<MaintSetSink<A>>(relation, order, kind, sign);
    return maint_sink_ladder<A - 1>(arity, relation, order, kind, sign);
  }
}

template <u16 A>
std::unique_ptr<BoundSink> lattice_maint_sink_ladder(
  u16 arity, Relation* relation, u8 kind, s8 sign)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)relation; (void)kind; (void)sign;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<LatticeMaintSink<A>>(relation, kind, sign);
    return lattice_maint_sink_ladder<A - 1>(arity, relation, kind, sign);
  }
}

template <u16 A>
std::unique_ptr<BoundSink> struct_maint_sink_ladder(
  u16 arity, Relation* relation, const std::vector<u16>& order,
  u8 kind, s8 sign)
{
  if constexpr (A <= 1)
  {
    (void)arity; (void)relation; (void)order; (void)kind; (void)sign;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<StructMaintSink<A>>(relation, order, kind,
                                                  sign);
    return struct_maint_sink_ladder<A - 1>(arity, relation, order, kind,
                                           sign);
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
// The join-tomb cursor (negative maintenance struct resolution,
// docs/m4s-contract.md): probe the live master first; only on a complete
// live miss consult the bucket's tombstone dictionary -- a sweep round may
// tombstone the head arbitrarily many rounds before the last decrement
// referencing it, and no one-round FULL-union-delta view spans that gap.
// Never allocates, never resurrects; a double miss yields no row.
// ---------------------------------------------------------------------------

class TombProbeCursor final : public PrefixCursor
{
  Relation* relation;
  std::unique_ptr<PrefixCursor> live;
  std::vector<u16> regs_map; // index order: bound content prefix, id suffix
  u16 arity;
  enum class Phase : u8 { live, tomb, done } phase = Phase::done;
  bool live_matched = false;
  std::vector<u64> scratch; // master-ordered (content..., id) for proofs
  bool positioned = false;

public:
  TombProbeCursor(Relation* rel, std::unique_ptr<PrefixCursor> cursor,
                  std::vector<u16> regs, u16 a)
    : relation(rel), live(std::move(cursor)), regs_map(std::move(regs)),
      arity(a), scratch(a, 0) {}

  TombProbeCursor(const TombProbeCursor& other)
    : relation(other.relation), live(other.live->clone()),
      regs_map(other.regs_map), arity(other.arity), phase(other.phase),
      live_matched(other.live_matched), scratch(other.scratch),
      positioned(other.positioned) {}

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<TombProbeCursor>(*this);
  }

  void open(const u64* regs) override
  {
    phase = Phase::live;
    live_matched = false;
    positioned = false;
    for (u16 i = 0; i + 1 < arity; ++i)
      scratch[i] = regs[regs_map[i]];
    live->open(regs);
  }

  CursorResult next(u64* regs, WorkBudget& budget) override
  {
    positioned = false;
    if (phase == Phase::live)
    {
      const CursorResult result = live->next(regs, budget);
      if (result == CursorResult::match)
      {
        live_matched = true;
        return result;
      }
      if (result == CursorResult::paused) return result;
      // Exhausted: the dictionary is consulted only on a complete live
      // miss (a live match precludes it, exactly like join_probe_tomb).
      phase = live_matched ? Phase::done : Phase::tomb;
    }
    if (phase == Phase::tomb)
    {
      phase = Phase::done;
      if (!budget.tick()) { phase = Phase::tomb; return CursorResult::paused; }
      const std::vector<u16>& master = relation->getMasterIndex();
      std::vector<u64> row(arity, 0);
      for (u16 c = 0; c + 1 < arity; ++c) row[master[c]] = scratch[c];
      u64 id = 0;
      if (relation->peekTombstone(buckethash(scratch[0]), row.data(),
                                  master.data(), arity, id))
      {
        regs[regs_map[arity - 1]] = id;
        scratch[arity - 1] = id;
        positioned = true;
        return CursorResult::match;
      }
    }
    return CursorResult::exhausted;
  }

  TupleView current() const override
  {
    if (positioned)
      return TupleView{scratch.data(), arity};
    return live->current();
  }
};

// ---------------------------------------------------------------------------
// The absent-old cursor (M4N, docs/m4n-contract.md pin 4): absence at the
// epoch's PRE state over a FINAL stratum.  Because the negated stratum is
// final, a staged transition row's sign is recoverable from live membership,
// and the pre-state collapses to the symmetric difference
//
//     pre(B) = FULL xor staged-delta
//
// (a gained row is in both and was absent before; a lost row is in the
// delta alone and was present before).  The filter passes -- fires exactly
// once, binding nothing, exposing no premise -- iff no row matching the
// bound prefix lies in exactly one of the two indices.  One bound cursor
// owns the whole equation; a half-emitted plan cannot exist (route A,
// ratified 2026-07-19).
// ---------------------------------------------------------------------------

template <u16 A>
class AbsentPreCursor final : public PrefixCursor
{
  Index** full;
  Index** delta;
  std::vector<u16> regs_map; // bound prefix registers, index order
  u16 bound;
  std::array<u64, A> key{};
  bool allowed = false;
  bool fired = false;

  bool present_pre() const
  {
    const auto witness = [&](Index** primary, Index** other) {
      u16 first = 0, last = bucket_count;
      if (bound > 0)
      {
        first = buckethash(key[0]);
        last = static_cast<u16>(first + 1);
      }
      for (u16 b = first; b < last; ++b)
      {
        auto* tree = static_cast<BTreeIndex<A>*>(primary[b]);
        auto it = bound == 0 ? tree->begin() : tree->lower_bound(key);
        for (; it != tree->end(); ++it)
        {
          bool same = true;
          for (u16 c = 0; c < bound; ++c)
            if ((*it)[c] != key[c]) { same = false; break; }
          if (!same) break;
          if (!static_cast<BTreeIndex<A>*>(
                other[buckethash((*it)[0])])->contains(*it))
            return true;
        }
      }
      return false;
    };
    return witness(full, delta) || witness(delta, full);
  }

public:
  AbsentPreCursor(Index** full_index, Index** delta_index,
                  const std::vector<u16>& regs, u16 bound_width)
    : full(full_index), delta(delta_index), regs_map(regs),
      bound(bound_width) {}

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<AbsentPreCursor>(*this);
  }

  void open(const u64* regs) override
  {
    fired = false;
    for (u16 i = 0; i < bound; ++i) key[i] = regs[regs_map[i]];
    allowed = !present_pre();
  }

  CursorResult next(u64*, WorkBudget& budget) override
  {
    if (fired || !allowed) return CursorResult::exhausted;
    if (!budget.tick()) return CursorResult::paused;
    fired = true;
    return CursorResult::match;
  }

  TupleView current() const override { return {}; }
};

template <u16 A>
std::unique_ptr<PrefixCursor> absent_pre_ladder(
  u16 arity, Index** full, Index** delta,
  const std::vector<u16>& regs, u16 bound)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)full; (void)delta; (void)regs; (void)bound;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<AbsentPreCursor<A>>(full, delta, regs, bound);
    return absent_pre_ladder<A - 1>(arity, full, delta, regs, bound);
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

std::unique_ptr<BoundSink> make_maint_sink(
  u16 arity, Relation* relation, const std::vector<u16>& order,
  u8 kind, s8 sign)
{
  if (arity == 0 || arity > max_daemon_arity || relation == nullptr
      || order.size() != arity
      || (kind != cnt_kind_nonrec && kind != cnt_kind_rec)
      || (sign != 1 && sign != -1))
    throw SealError(SealErrorK::factory,
                    "bind: maint sink factory capability miss");
  auto result = maint_sink_ladder<max_daemon_arity>(arity, relation, order,
                                                    kind, sign);
  if (!result)
    throw SealError(SealErrorK::factory, "bind: maint sink ladder miss");
  return result;
}

std::unique_ptr<BoundSink> make_lattice_maint_sink(
  u16 arity, Relation* relation, u8 kind, s8 sign)
{
  if (arity == 0 || arity > max_daemon_arity || relation == nullptr
      || (kind != cnt_kind_nonrec && kind != cnt_kind_rec)
      || (sign != 1 && sign != -1))
    throw SealError(SealErrorK::factory,
                    "bind: lattice maint sink factory capability miss");
  auto result = lattice_maint_sink_ladder<max_daemon_arity>(arity, relation,
                                                            kind, sign);
  if (!result)
    throw SealError(SealErrorK::factory,
                    "bind: lattice maint sink ladder miss");
  return result;
}

std::unique_ptr<BoundSink> make_struct_maint_sink(
  u16 arity, Relation* relation, const std::vector<u16>& order,
  u8 kind, s8 sign)
{
  if (arity < 2 || arity > max_daemon_arity || relation == nullptr
      || order.size() != arity
      || (kind != cnt_kind_nonrec && kind != cnt_kind_rec)
      || (sign != 1 && sign != -1))
    throw SealError(SealErrorK::factory,
                    "bind: struct maint sink factory capability miss");
  auto result = struct_maint_sink_ladder<max_daemon_arity>(arity, relation,
                                                           order, kind,
                                                           sign);
  if (!result)
    throw SealError(SealErrorK::factory,
                    "bind: struct maint sink ladder miss");
  return result;
}

std::unique_ptr<PrefixCursor> make_tomb_probe_cursor(
  u16 arity, Relation* relation, Index** master,
  const std::vector<u16>& order, const std::vector<u16>& regs, u16 bound)
{
  (void)order;
  if (arity < 2 || bound + 1 != arity || relation == nullptr)
    throw SealError(SealErrorK::factory,
                    "bind: tomb probe factory capability miss");
  return std::make_unique<TombProbeCursor>(
    relation, make_set_probe_cursor(arity, master, regs, bound), regs,
    arity);
}

std::unique_ptr<PrefixCursor> make_absent_pre_cursor(
  u16 arity, Index** full, Index** delta,
  const std::vector<u16>& regs, u16 bound)
{
  if (arity == 0 || arity > max_daemon_arity || bound > arity
      || regs.size() != bound)
    throw SealError(SealErrorK::factory,
                    "bind: absent-pre factory capability miss");
  auto result = absent_pre_ladder<max_daemon_arity>(arity, full, delta,
                                                    regs, bound);
  if (!result)
    throw SealError(SealErrorK::factory, "bind: absent-pre ladder miss");
  return result;
}

void emit_pending_error_count_nonrec(Database* db, const char* loc)
{
  emit_pending_error_count(db, loc, cnt_kind_nonrec);
}

void emit_pending_error_count_rec(Database* db, const char* loc)
{
  emit_pending_error_count(db, loc, cnt_kind_rec);
}

namespace
{

// Fire-once scheduling shared by every flavored installer: once/seeded
// dispatch and scans over NON-dynamic relations (staged input transitions
// exist only in the entry delta) run first-iteration-only; scans over
// dynamic relations chase the ripple every iteration -- the native
// plugins' exact once_only flags.
void attach_flavored_rules(Database* db, Stratum* stratum,
                           const SealedKernelPlan& plan)
{
  const std::set<std::string> dynamic(plan.dynamic_names.begin(),
                                      plan.dynamic_names.end());
  const auto rules = bind_kernel_plan(plan, *db);
  for (const auto& rule : rules)
  {
    const DriverPlan& driver = rule->definition().driver;
    bool fire_once = driver.kind == DriverK::once
                  || driver.kind == DriverK::seeded;
    if (driver.kind == DriverK::scan_delta)
      fire_once = dynamic.count(plan.bindings[driver.relation].name) == 0;
    rule->attach(db, stratum, fire_once);
  }
}

// The sorted read manifest: driver and body/pre probe relations (resolve
// cursors are lowered head constructions, not reads).
void add_read_manifest(Stratum* stratum, const SealedKernelPlan& plan)
{
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
}

Relation* ensure_flavored_relation(Database* db,
                                   const RelationBinding& binding)
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
      fatal("flavored install: lattice relation is absent: " + binding.name);
    relation = db->getRelation(binding.name);
  }
  if (relation->getArity() != binding.shape.arity)
    fatal("Relation already exists at incorrect arity.");
  return relation;
}

} // namespace

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
    Relation* relation = ensure_flavored_relation(db, binding);
    for (const std::vector<u16>& order : binding.shape.full_orders)
      add_flavored_index(binding.shape.arity, relation, order,
                         binding.shape.kind == RelationK::lattice, false);
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
    add_flavored_count_task(binding.shape.arity, db, stratum, relation,
                            binding.shape.kind == RelationK::struct_);
  }

  // Bind through the pending count-round environment beginStratumDelta set
  // up, then schedule the reads with the native once_only flags and the
  // sorted read manifests.
  attach_flavored_rules(db, stratum, plan);
  add_read_manifest(stratum, plan);

  daemon->push(stratum);
  daemon->continueRun();
}

void install_maint_stratum(Daemon* daemon, const std::string& name,
                           const SealedKernelPlan& plan)
{
  seal_check(plan.flavor == "maint1" || plan.flavor == "maint3neg"
               || plan.flavor == "maint4neg",
             SealErrorK::flavor, "install: not a maintenance plan");
  const bool dred = plan.flavor == "maint4neg";
  Database* db = daemon->db();
  Stratum* stratum = daemon->beginStratumDelta(name);
  if (stratum == nullptr) return;

  // Maintained heads (rule sink targets: emit / mkstruct / emit-lat and
  // the tycheck diversion) get the serial Maintain*Task folds; everything
  // else -- inputs, error arms, service structs -- keeps the full ordinary
  // write/intern machinery.  Temps are staging: no indices, no tasks.
  std::set<u16> maintained;
  for (const SealedRule& rule : plan.rules)
  {
    for (const EmitPlan& head : rule.heads)
      if (head.head_kind != HeadK::temp)
        maintained.insert(head.relation);
    for (const EmitPlan& effect : rule.effects)
      maintained.insert(effect.relation);
  }

  for (const RelationBinding& binding : plan.bindings)
  {
    Relation* relation = ensure_flavored_relation(db, binding);
    const bool is_head = maintained.count(binding.slot) != 0;
    if (binding.shape.temp) continue;
    if (binding.shape.kind == RelationK::lattice)
    {
      // Resident payload maps stay registered; no merge/write machinery
      // runs in a maintenance epoch (the LatticeMaintainTask fold owns
      // contributor repair for maintained heads).
      for (const std::vector<u16>& order : binding.shape.full_orders)
        add_flavored_index(binding.shape.arity, relation, order, true,
                           false);
      if (is_head)
        add_flavored_lattice_maintain_task(binding.shape.arity, db, stratum,
                                           relation);
      continue;
    }
    seal_check(!binding.shape.full_orders.empty(), SealErrorK::binding,
               "maintenance install: relation carries no full ordering: "
                 + binding.name);
    for (size_t i = 0; i < binding.shape.full_orders.size(); ++i)
    {
      const std::vector<u16>& order = binding.shape.full_orders[i];
      add_flavored_index(binding.shape.arity, relation, order, false, false);
      add_flavored_write_task(binding.shape.arity, db, stratum, relation,
                              order, false, i == 0);
    }
    for (const std::vector<u16>& order : binding.shape.delta_orders)
    {
      add_flavored_index(binding.shape.arity, relation, order, false, true);
      add_flavored_write_task(binding.shape.arity, db, stratum, relation,
                              order, true, false);
    }
    const std::vector<u16>& master = binding.shape.full_orders.front();
    const bool is_struct = binding.shape.kind == RelationK::struct_;
    if (is_head)
      add_flavored_maintain_task(binding.shape.arity, db, stratum, relation,
                                 master, is_struct, dred);
    else
      add_flavored_intern_task(binding.shape.arity, db, stratum, relation,
                               master, is_struct);
  }

  attach_flavored_rules(db, stratum, plan);
  add_read_manifest(stratum, plan);

  daemon->push(stratum);
  daemon->continueRun();
}

bool maybe_interp_count_plugin(Daemon* daemon, const std::string& path)
{
  // Slice 4 (counted-interp-contract.md): flavored variants are interp-only
  // by default -- every `_count`/`_maint*` plugin path installs its sealed
  // sidecar plan.  SLOG_FLAVORED_NATIVE restores dlopen of the native
  // artifact, the differential's second executor.
  static const bool native = [] {
    const char* value = std::getenv("SLOG_FLAVORED_NATIVE");
    return value != nullptr && *value != '\0'
        && std::string_view(value) != "0";
  }();
  if (native) return false;
  const size_t slash = path.rfind('/');
  const std::string file =
    slash == std::string::npos ? path : path.substr(slash + 1);
  if (file.size() < 3 || file.compare(file.size() - 3, 3, ".so") != 0)
    return false;
  static const char* const flavored_tags[] = {"_count.", "_maint1.",
                                              "_maint3neg.", "_maint4neg."};
  size_t tag = std::string::npos;
  size_t tag_length = 0;
  for (const char* candidate : flavored_tags)
  {
    tag = file.find(candidate);
    if (tag != std::string::npos)
    {
      tag_length = std::string_view(candidate).size() - 1;
      break;
    }
  }
  if (tag == std::string::npos) return false;
  const std::string stem = file.substr(0, tag + tag_length);
  const std::string plan_path =
    (slash == std::string::npos ? std::string() : path.substr(0, slash + 1))
    + stem + ".plan";
  try
  {
    const DecodedKernelPlan decoded = parse_kernel_plan_file(plan_path);
    const SealedKernelPlan sealed = seal_kernel_plan(decoded, daemon->db());
    if (sealed.flavor == "count")
      install_count_stratum(daemon, stem, sealed);
    else
      install_maint_stratum(daemon, stem, sealed);
  }
  catch (const std::exception& error)
  {
    fatal("flavored interp routing: plan install failed for " + plan_path
          + ": " + error.what());
  }
  return true;
}

} // namespace interp
} // namespace slog
