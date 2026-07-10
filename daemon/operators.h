/** Slog Push-Based Rule Operators
 *
 * A small library of fused, push-based relational operators used by the
 * generated code for a rule's read-phase task.  Each operator is a templated
 * function that takes its downstream continuation as a forwarding reference
 * (`Cont&&`/`K&&`) -- never a std::function -- so the whole per-rule pipeline
 * fuses into one tight loop at -O2 (Neumann's data-centric / produce-consume
 * model; LB2's `Record => Unit` callbacks).  The bound-variable environment
 * flows as plain nested-scope locals in the generated continuation lambdas, so
 * register allocation is optimal and there is no register-file aliasing hazard.
 *
 * The runtime model (Relation/Index/BTreeIndex<A>/InsertBatch, the bucketized
 * delta views, the 3-phase fixpoint) is unchanged: these operators are exactly
 * the read-phase loops the string emitter used to inline by hand, refactored
 * into one tested place.
 *
 * Control-flow note: each operator's loop body is a single invocation of its
 * continuation, so a `return;` inside a continuation lambda is equivalent to a
 * `continue;` of the innermost enclosing loop in the old nested-loop codegen
 * (it abandons the current tuple and lets the parent operator's loop advance).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

#include "slogd.h"
#include <array>

namespace slog
{

// SOURCE (read_delta): drive the pipeline from this read-task's pre-bucketized
// delta partition (refs into `delta`, bucket `bucket`), across every worker
// thread's reorg buffers.  Refs already exclude null (deduped) tuples.  Calls
// k(const u64* tuple) once per tuple; the continuation reads its columns.
template <class K>
inline void read_delta(Relation* rel, u16 bucket, u32 nthreads, K&& k)
{
  for (u32 t = 0; t < nthreads; ++t)
  {
    RefVec& refs = rel->getReadBucket(t, bucket);
    const u32 n = (u32)refs.size();
    for (u32 i = 0; i < n; ++i)
      k(refs[i].batch->data + refs[i].offset);
  }
}

// SOURCE (read_delta), SLICEABLE (docs/pausing.md §3): like read_delta, but
// pausable at the outer-tuple granularity.  Resumes from (rt,ri) -- thread
// index rt, ref index ri within that thread's bucket -- and, every 128 outer
// tuples, consults `sc`: if the stop flag is set or the slice deadline has
// passed, it writes the NEXT unprocessed position back into (rt,ri) and
// returns false (paused); the caller flushes its partial batches and parks a
// continuation carrying (rt,ri).  Returns true once the whole partition is
// consumed.  Because indices are immutable across the read phase and the delta
// views stay valid until the (skipped-on-suspend) finalize, (rt,ri) is an
// exact resume point: no tuple is dropped or reprocessed across a pause.
template <class K>
inline bool read_delta_sliced(Relation* rel, u16 bucket, u32 nthreads,
                              const SliceCtx& sc, u32& rt, u32& ri, K&& k)
{
  u32 tick = 0;
  for (u32 t = rt; t < nthreads; ++t)
  {
    RefVec& refs = rel->getReadBucket(t, bucket);
    const u32 n = (u32)refs.size();
    for (u32 i = (t == rt ? ri : 0); i < n; ++i)
    {
      if (((++tick) & 127u) == 0
          && (sc.stop->load(std::memory_order_relaxed)
              || std::chrono::steady_clock::now() >= sc.deadline))
      {
        rt = t;
        ri = i;                       // resume exactly here next time
        return false;
      }
      k(refs[i].batch->data + refs[i].offset);
    }
  }
  return true;
}

// JOIN (bound prefix): the chosen index orders the join-key columns first, so
// this literal's already-bound vars are the first K columns of `key` (the
// remaining A-K slots are 0).  Probe the single bucket holding the lead value
// and range-scan while the first K columns still equal the bound prefix
// (lexicographically sorted, so once the prefix differs there are no more
// matches).  Calls k(const std::array<u64,A>&) per matched tuple; the
// continuation binds the free (suffix) columns.
template <u16 A, u16 K, class Cont>
inline void join_probe(Index** index, const std::array<u64, A>& key, Cont&& k)
{
  auto* idx = static_cast<BTreeIndex<A>*>(index[buckethash(key[0])]);
  for (auto it = idx->lower_bound(key); it != idx->end(); ++it)
  {
    const std::array<u64, A>& m = *it;
    for (u16 c = 0; c < K; ++c)
      if (m[c] != key[c]) return;       // prefix gone => done (sorted order)
    k(m);
  }
}

// JOIN DRIVER (bound prefix), SLICEABLE (docs/pausing.md §3): the probe-driver
// analogue of read_delta_sliced.  Like join_probe, but pausable at the
// outer-match granularity: resume from the saved match key `rkey` (when
// has_resume) instead of the prefix key; every 128 visited matches consult
// `sc`, and on a trip save the about-to-be-processed match into rkey (so it is
// reprocessed on resume, never skipped) and return false.  Returns true when
// the K-prefix range is exhausted.  Indices are immutable across the read
// phase and rkey is >= key within the same bucket (K>=1 for a probe driver),
// so lower_bound(rkey) is an exact resume point.
template <u16 A, u16 K, class Cont>
inline bool join_probe_sliced(Index** index, const std::array<u64, A>& key,
                              const SliceCtx& sc, std::array<u64, A>& rkey,
                              bool& has_resume, Cont&& k)
{
  auto* idx = static_cast<BTreeIndex<A>*>(index[buckethash(key[0])]);
  u32 tick = 0;
  for (auto it = idx->lower_bound(has_resume ? rkey : key); it != idx->end(); ++it)
  {
    const std::array<u64, A>& m = *it;
    for (u16 c = 0; c < K; ++c)
      if (m[c] != key[c]) return true;      // prefix gone => done (sorted order)
    if (((++tick) & 127u) == 0
        && (sc.stop->load(std::memory_order_relaxed)
            || std::chrono::steady_clock::now() >= sc.deadline))
    {
      rkey = m;
      has_resume = true;
      return false;                          // resume AT m (reprocess it)
    }
    k(m);
  }
  return true;
}

// FILTER (semijoin existence probe): does ANY tuple of the index match the
// K-column bound prefix?  One lower_bound + prefix compare, no iteration.
// Used to prune a partial join against a FUTURE clause's relation before an
// expanding join enumerates matches the future clause would only discard
// (Yannakakis-style lookahead; see operationalization.rkt "Semijoin
// filters").  Probes the same full-index snapshot the future join itself
// will read, so a pruned tuple could never have joined this iteration.
template <u16 A, u16 K>
inline bool exists_probe(Index** index, const std::array<u64, A>& key)
{
  auto* idx = static_cast<BTreeIndex<A>*>(index[buckethash(key[0])]);
  auto it = idx->lower_bound(key);
  if (it == idx->end())
    return false;
  const std::array<u64, A>& m = *it;
  for (u16 c = 0; c < K; ++c)
    if (m[c] != key[c])
      return false;
  return true;
}

// JOIN (no bound prefix == cartesian): this literal shares no variable with the
// grounded set.  Tuples are hash-partitioned by their lead column across all
// buckets, so a cartesian scan must visit every bucket and every tuple.  Calls
// k(const std::array<u64,A>&) per tuple; the continuation binds all A columns.
template <u16 A, class Cont>
inline void join_all(Index** index, Cont&& k)
{
  for (u16 b = 0; b < bucket_count; ++b)
  {
    auto* idx = static_cast<BTreeIndex<A>*>(index[b]);
    for (auto it = idx->begin(); it != idx->end(); ++it)
      k(*it);
  }
}

// JOIN over a lattice (payload-map) index, bound key prefix: like join_probe
// over the KA key columns, but each match additionally hands the continuation
// the key's current merged value -- k(const std::array<u64,KA>& keys, u64 val).
// Read-phase tasks only read the map (it is mutated in the write/intern
// phases), so this is safe alongside them.
template <u16 KA, u16 K, class Cont>
inline void join_probe_lat(Index** index, const std::array<u64, KA>& key, Cont&& k)
{
  auto* idx = static_cast<BTreeMapIndex<KA>*>(index[buckethash(key[0])]);
  for (auto it = idx->lower_bound(key); it != idx->end(); ++it)
  {
    const std::array<u64, KA>& m = it->first;
    for (u16 c = 0; c < K; ++c)
      if (m[c] != key[c]) return;       // prefix gone => done (sorted order)
    k(m, it->second);
  }
}

// JOIN over a lattice index with no bound prefix (cartesian).
template <u16 KA, class Cont>
inline void join_all_lat(Index** index, Cont&& k)
{
  for (u16 b = 0; b < bucket_count; ++b)
  {
    auto* idx = static_cast<BTreeMapIndex<KA>*>(index[b]);
    for (auto it = idx->begin(); it != idx->end(); ++it)
      k(it->first, it->second);
  }
}

// SINK (relation head): skip if this exact tuple already exists in the head
// relation (full composite-key lookup in its bucket), else scatter it into the
// per-head send batch and flush when full.  `zs` is the tuple in head-index
// order (so zs[0] is the lead column the head index is bucket-hashed/keyed on);
// head_ord[j] is the storage (nominal) position of index-order column j, so the
// batch holds tuples in storage order for the downstream write/intern phases.
// `nb` is reassigned on flush, hence the reference.
template <u16 A>
inline void emit(Relation* head_rel, Index** head_index, InsertBatch*& nb,
                 const std::array<u64, A>& zs, const std::array<u16, A>& head_ord)
{
  if (static_cast<BTreeIndex<A>*>(head_index[buckethash(zs[0])])->contains(zs))
    return;
  u64* d = nb->data + nb->usage;
  for (u16 j = 0; j < A; ++j)
    d[head_ord[j]] = zs[j];
  nb->usage += A;
  if (nb->usage + A >= batch_size_max)
  {
    head_rel->sendBatch(nb);
    nb = new InsertBatch();
  }
}

// SINK (temp head, no index): append in nominal order with no dedup check.
template <u16 A>
inline void emit_temp(Relation* rel, InsertBatch*& nb, const std::array<u64, A>& zs)
{
  u64* d = nb->data + nb->usage;
  for (u16 j = 0; j < A; ++j)
    d[j] = zs[j];
  nb->usage += A;
  if (nb->usage + A >= batch_size_max)
  {
    rel->sendBatch(nb);
    nb = new InsertBatch();
  }
}

// SINK (struct head): scatter the A-1 field values into their storage slots and
// write a 0 placeholder into the id column; InternStructTask owns dedup (content
// match on the master index) and id assignment (struct_encode), so this sink does
// NO emit-time dedup -- it just produces the not-yet-interned tuple.  `head_ord`
// is the master-index ordering: head_ord[A-1] is the id column's storage position
// (nominal 0) and head_ord[j<A-1] the storage position of field j.  0 is a safe
// placeholder since slog_null (which intern skips) is not 0.
template <u16 A>
inline void emit_struct(Relation* head_rel, InsertBatch*& nb,
                        const std::array<u64, A - 1>& fields,
                        const std::array<u16, A>& head_ord)
{
  u64* d = nb->data + nb->usage;
  d[head_ord[A - 1]] = 0;                              // id placeholder
  for (u16 j = 0; j < A - 1; ++j)
    d[head_ord[j]] = fields[j];
  nb->usage += A;
  if (nb->usage + A >= batch_size_max)
  {
    head_rel->sendBatch(nb);
    nb = new InsertBatch();
  }
}

// SINK (runtime-error struct): like emit_struct, but self-contained -- it owns a
// fresh batch and flushes it immediately.  Called from a rule body's
// runtime-error path (a fallible prim returned slog_error), which has no
// per-invocation batch slot of its own.  Errors are rare, so a batch per call is
// fine.  Thread-safe: sendBatch appends to the calling thread's send shard.
template <u16 A>
inline void emit_error_struct(Relation* rel,
                              const std::array<u64, A - 1>& fields,
                              const std::array<u16, A>& head_ord)
{
  InsertBatch* nb = new InsertBatch();
  emit_struct<A>(rel, nb, fields, head_ord);
  rel->sendBatch(nb);
}

// Turn the calling worker's pending runtime error (a fallible prim returned
// slog_error) into the matching (error_spec ...) arm struct, tagged with the
// reporting rule's `loc` (docs/type-errors.md).  The master ordering for an
// arity-A struct is {1..A-1, 0} (id column last).  If an arm relation is somehow
// absent (a producible-arm miss in compile.rkt), fail loudly rather than
// null-deref -- degrading to the pre-error-fact behavior.
inline void emit_pending_error(Database* db, const char* loc)
{
  const PendingError& pe = db->currentPendingError();
  const u64 vloc = str_encode(db, loc);
  auto rel = [&](const char* n) {
    Relation* r = db->getRelation(n);
    if (!r) fatal(std::string("runtime error in an unregistered arm relation: ") + n);
    return r;
  };
  switch (pe.kind)
  {
    case ERR_DIV0:
      emit_error_struct<3>(rel("div_by_zero"),    {vloc, pe.a}, {1, 2, 0}); break;
    case ERR_MOD0:
      emit_error_struct<3>(rel("modulo_by_zero"), {vloc, pe.a}, {1, 2, 0}); break;
    case ERR_INT_OVF:
      emit_error_struct<4>(rel("int_overflow"),   {vloc, pe.a, pe.b}, {1, 2, 3, 0}); break;
    case ERR_NAN:
      emit_error_struct<4>(rel("nan_result"),     {vloc, str_encode(db, pe.op), pe.a}, {1, 2, 3, 0}); break;
    case ERR_TOINT:
      emit_error_struct<3>(rel("toint_range"),    {vloc, pe.a}, {1, 2, 0}); break;
    case ERR_TYPE:
      emit_error_struct<5>(rel("type_mismatch"),  {vloc, str_encode(db, pe.op), pe.a, pe.b}, {1, 2, 3, 4, 0}); break;
    // The two bignum caps (docs/primitives.md §14.4): per-value overflow
    // carries the operands; the whole-table trip is near-global (location +
    // op only), so set semantics dedup a storm to a handful of facts.
    case ERR_MPZ_OVF:
      emit_error_struct<5>(rel("mpz_overflow"),   {vloc, str_encode(db, pe.op), pe.a, pe.b}, {1, 2, 3, 4, 0}); break;
    case ERR_MPZ_TABLE:
      emit_error_struct<3>(rel("mpz_table_overflow"), {vloc, str_encode(db, pe.op)}, {1, 2, 0}); break;
  }
}


// SINK (runtime arity): batch rows in nominal (storage) order into a
// relation's send shards, flushing at capacity -- the rows-into-shards
// publish path.  Rows pushed here ride the NORMAL write/intern pipeline next
// iteration (the one-iteration lag structs have), so semi-naive refire is
// native.  Shared by the M2.4 lattice-decomposition targets
// (MapWriteTask/LatticeInternTask below) and, later, sequence occurrence
// indexing (docs/sequences.md §5.3 SeqIndexTask).  Thread-safe like any
// sink: sendBatch appends to the calling worker's own shard.  A publisher
// constructed with rel == nullptr must simply never receive a row.
class RowPublisher
{
  Relation* rel;
  u16 arity;
  InsertBatch* nb;
public:
  RowPublisher(Relation* _rel, u16 _arity) : rel(_rel), arity(_arity), nb(nullptr) {}
  ~RowPublisher() { flush(); }
  void row(const u64* vals)
  {
    if (nb == nullptr) nb = new InsertBatch();
    u64* d = nb->data + nb->usage;
    for (u16 c = 0; c < arity; ++c)
      d[c] = vals[c];
    nb->usage += arity;
    if (nb->usage + arity >= batch_size_max)
      flush();
  }
  void flush()
  {
    if (nb)
    {
      rel->sendBatch(nb);   // deletes empty batches itself
      nb = nullptr;
    }
  }
};

// Emit the decomposition rows for one ascended collection-lattice key
// (docs/primitives.md §4.2, M2.4): every entry of `neww` not equal in `oldw`
// -- the foreach_added tree-diff, O(change) via shared-subtree pruning --
// becomes one row of the decomp target: (k̄, elem) for a set kind (R_has),
// (k̄, key, value-word) for a map kind (R_at).  `tuple` is the base row in
// STORAGE order (its key columns are 0..nkeys-1; the lattice value column is
// last by declaration).  A fresh key passes oldw = 0, translated here to the
// empty collection.
inline void emit_decomp_rows(CollectionArena* arena, RowPublisher& pub,
                             const u64* tuple, u16 nkeys, bool map_kind,
                             u64 oldw, u64 neww)
{
  u64 row[max_daemon_arity + 2];
  for (u16 c = 0; c < nkeys; ++c)
    row[c] = tuple[c];
  arena->foreach_added(oldw ? oldw : arena->empty(), neww, [&](u64 k, u64 v) {
    row[nkeys] = k;
    if (map_kind)
      row[nkeys + 1] = v;
    pub.row(row);
  });
}


// SEQ-INDEX (docs/sequences.md §5.3): maintain the inverted occurrence
// relations $seq_at (val pos list) / $seq_atr (val rpos list) for one fed
// relation -- a relation with sequence-typed columns.  Each iteration's
// delta is scanned (the round-robin read views, every row exactly once);
// an unseen sequence id walks its leaves once, publishing one row per
// element into the occurrence relations' send shards -- the normal
// write/intern pipeline, so rows land in the NEXT iteration's delta (the
// one-iteration lag structs and the M2.4 decomposition ride; semi-naive
// versions driven by the occurrence delta refire dependents, so nothing is
// lost to the lag).  At iteration 0 the delta IS the reloaded/imported
// base (beginStratum re-stages everything), so a fresh stratum's task
// re-publishes the whole resident content -- dedup'd downstream by the
// occurrence relation's own intern task, this is a no-op when already
// published, and exactly the re-derivation that heals an imported base.
// The published set is per-task (per stratum .so): re-walks across strata
// cost probes, not duplicate rows.  Runs as ONE task instance per fed
// relation (phase_write); the arena is re-entrant so leaf walks are safe
// alongside the other write tasks.
class SeqIndexTask : public Task
{
  Database* db;
  Relation* rel;
  std::vector<u16> cols;   // sequence-typed storage columns of rel
  Relation* at_rel;        // $seq_at, or null when this stratum lacks it
  Relation* atr_rel;       // $seq_atr, likewise
  std::unordered_set<u64> published;
public:
  SeqIndexTask(Database* _db, Relation* _rel, const std::vector<u16>& _cols,
               Relation* _at, Relation* _atr)
    : db(_db), rel(_rel), cols(_cols), at_rel(_at), atr_rel(_atr) {}
  bool work() override
  {
    if (rel == nullptr || (at_rel == nullptr && atr_rel == nullptr))
      return true;
    RowPublisher at_pub(at_rel, 3);
    RowPublisher atr_pub(atr_rel, 3);
    SequenceArena* ar = db->sequences();
    const u32 nthreads = db->getThreadCount();
    for (u16 b = 0; b < bucket_count; ++b)
      for (u32 t = 0; t < nthreads; ++t)
      {
        RefVec& refs = rel->getReadBucket(t, b);
        const u32 n = (u32)refs.size();
        for (u32 r = 0; r < n; ++r)
        {
          const u64* d = refs[r].batch->data + refs[r].offset;
          for (u16 ci = 0; ci < cols.size(); ++ci)
          {
            const u64 w = d[cols[ci]];
            if (!is_seq(w) || !published.insert(w).second)
              continue;
            const u64 len = ar->len(w);
            u64 row[3];
            row[2] = w;
            u64 pos = 0;
            ar->foreach(w, [&](u64 v)
            {
              row[0] = v;
              if (at_rel)
              {
                row[1] = s32_encode((s32)pos);
                at_pub.row(row);
              }
              if (atr_rel)
              {
                row[1] = s32_encode((s32)(len - 1 - pos));
                atr_pub.row(row);
              }
              ++pos;
            });
          }
        }
      }
    return true;
  }
};


// ---------------------------------------------------------------------------
// Write- and intern-phase tasks.  Unlike read-phase rules (each a bespoke
// operator chain), these are single-stage scan->sink, identical across every
// relation of a given arity -- so they are generic templated Tasks, instantiated
// once per arity and shared, rather than emitted per relation.  `ord` is the
// index column ordering (runtime: it is not on the per-tuple bottleneck, which
// is the btree op, so a runtime permutation costs nothing measurable and keeps
// instantiations per-arity instead of per-ordering).
// ---------------------------------------------------------------------------

// WRITE: insert this iteration's delta (the pre-bucketized write partition for
// `ord`'s lead column, across all worker threads) into one bucket of one index.
// Refs already exclude null (deduped) tuples.
template <u16 A>
class WriteTask : public Task
{
  Database* db;
  Relation* rel;
  u16 bucket;
  std::array<u16, A> ord;
  BTreeIndex<A>* root;
public:
  WriteTask(Database* _db, Relation* _rel, const std::array<u16, A>& _ord, bool delta, u16 _b)
    : db(_db), rel(_rel), bucket(_b), ord(_ord)
  {
    std::vector<u16> ordv(ord.begin(), ord.end());
    root = static_cast<BTreeIndex<A>*>(rel->getIndex(ordv, delta)[bucket]);
  }
  bool work() override
  {
    const u16 leadcol = ord[0];
    const u32 nthreads = db->getThreadCount();
    for (u32 t = 0; t < nthreads; ++t)
    {
      RefVec& refs = rel->getWriteBucket(t, leadcol, bucket);
      const u32 n = (u32)refs.size();
      for (u32 r = 0; r < n; ++r)
      {
        const u64* d = refs[r].batch->data + refs[r].offset;
        std::array<u64, A> key;
        for (u16 c = 0; c < A; ++c) key[c] = d[ord[c]];
        root->insert(key);
      }
    }
    return true;
  }
};

// INTERN (relation, set semantics): scan the new delta, drop (null out) tuples
// already present in the master index, else insert.  Each per-bucket task filters
// the whole delta by buckethash (the new delta is not yet reorg-bucketized -- the
// reorg that builds the bucket views runs after intern).  The null check must
// come after the bucket check (a null lead column must still be skipped).
template <u16 N>
class InternTask : public Task
{
  Database* db;
  Relation* rel;
  u16 bucket;
  std::array<u16, N> ord;
  BTreeIndex<N>* root;
public:
  InternTask(Database* _db, Relation* _rel, const std::array<u16, N>& _ord, u16 _b)
    : db(_db), rel(_rel), bucket(_b), ord(_ord)
  {
    std::vector<u16> ordv(ord.begin(), ord.end());
    root = static_cast<BTreeIndex<N>*>(rel->getIndex(ordv, false)[bucket]);
  }
  bool work() override
  {
    auto& delta = rel->getDelta();
    for (u32 i = 0; i < delta.size(); ++i)
    {
      InsertBatch* batch = delta[i];
      for (u32 j = 0; j < batch->usage; j += N)
      {
        if (buckethash(batch->data[j + ord[0]]) != bucket || batch->data[j] == slog_null)
          continue;
        std::array<u64, N> key;
        for (u16 c = 0; c < N; ++c) key[c] = batch->data[j + ord[c]];
        if (root->contains(key)) batch->data[j] = slog_null;
        else root->insert(key);
      }
    }
    return true;
  }
};

// WRITE (lattice): merge this iteration's delta into one bucket of one
// payload-map index.  Contributions are join-merged (never assigned), so the
// result is independent of row order within the delta -- values only ascend,
// so every map converges to the master's payload without reading it.  A is
// the storage arity; ord is the index's full ordering (value column last).
//
// The MASTER (once) instance may carry the M2.4 decomposition target
// (docs/primitives.md §4.2): at iteration 0 the map is rebuilt from empty, so
// every reloaded/imported entry diffs against bottom and the WHOLE base
// content re-emits into `decomp` -- dedup'd by its intern task against its
// own reloaded rows, this is a no-op for a decomposition that already ran,
// and exactly the re-derivation that makes an imported (or stale) base
// consistent on first use.  Ascents after iteration 0 are LatticeInternTask's.
template <u16 A>
class MapWriteTask : public Task
{
  Database* db;
  Relation* rel;
  u16 bucket;
  std::array<u16, A> ord;
  BTreeMapIndex<A - 1>* root;
  Relation* decomp;
  bool decomp_map;
public:
  MapWriteTask(Database* _db, Relation* _rel, const std::array<u16, A>& _ord, u16 _b,
               Relation* _decomp = nullptr, bool _decomp_map = false)
    : db(_db), rel(_rel), bucket(_b), ord(_ord),
      decomp(_decomp), decomp_map(_decomp_map)
  {
    std::vector<u16> ordv(ord.begin(), ord.end());
    root = static_cast<BTreeMapIndex<A - 1>*>(rel->getIndex(ordv, false)[bucket]);
  }
  bool work() override
  {
    const u16 leadcol = ord[0];
    const u32 nthreads = db->getThreadCount();
    RowPublisher pub(decomp, (u16)(A - 1 + (decomp_map ? 2 : 1)));
    for (u32 t = 0; t < nthreads; ++t)
    {
      RefVec& refs = rel->getWriteBucket(t, leadcol, bucket);
      const u32 n = (u32)refs.size();
      for (u32 r = 0; r < n; ++r)
      {
        const u64* d = refs[r].batch->data + refs[r].offset;
        std::array<u64, A - 1> key;
        for (u16 c = 0; c + 1 < A; ++c) key[c] = d[ord[c]];
        bool changed = false;
        u64 oldw = 0;
        const u64 merged = root->merge(key, d[ord[A - 1]], changed,
                                       decomp ? &oldw : nullptr);
        if (decomp && changed)
          emit_decomp_rows(root->lat_arena, pub, d, A - 1, decomp_map, oldw, merged);
      }
    }
    return true;
  }
};

// INTERN (lattice): the merge point (docs/lattices.md §4.2).  Interning with a
// twist: content-keyed lookup in the master map, then join instead of
// id-allocation.  A subsumed contribution (join produced no change) is nulled
// in place -- the lattice analogue of the dedup-skip, so it never propagates;
// an ascending one has its payload word REWRITTEN in place to the merged
// value, so downstream rules join against the post-merge value, never the raw
// contribution (the value-carrying delta).
//
// M2.4 decomposition (docs/primitives.md §4.2): when `decomp` is set (the
// base is a decomposed collection-lattice table), each ascent walks the
// (old, new) payload pair with foreach_added -- O(change) via shared-subtree
// pruning -- and publishes one decomp row per added entry: (k̄, elem) into
// R_has (set kind), (k̄, key, value-word) into R_at (map kind, its own
// LatticeInternTask merging per (k̄,key) by the child spec).  Rows ride the
// normal write/intern pipeline next iteration, so each element, once
// present, stays -- the monotone facts that make in-SCC membership and
// enumeration sound.
template <u16 N>
class LatticeInternTask : public Task
{
  Database* db;
  Relation* rel;
  u16 bucket;
  std::array<u16, N> ord;      // master ordering: key columns, value last
  BTreeMapIndex<N - 1>* root;
  Relation* decomp;
  bool decomp_map;
public:
  LatticeInternTask(Database* _db, Relation* _rel, const std::array<u16, N>& _ord, u16 _b,
                    Relation* _decomp = nullptr, bool _decomp_map = false)
    : db(_db), rel(_rel), bucket(_b), ord(_ord),
      decomp(_decomp), decomp_map(_decomp_map)
  {
    std::vector<u16> ordv(ord.begin(), ord.end());
    root = static_cast<BTreeMapIndex<N - 1>*>(rel->getIndex(ordv, false)[bucket]);
  }
  bool work() override
  {
    auto& delta = rel->getDelta();
    RowPublisher pub(decomp, (u16)(N - 1 + (decomp_map ? 2 : 1)));
    for (u32 i = 0; i < delta.size(); ++i)
    {
      InsertBatch* batch = delta[i];
      for (u32 j = 0; j < batch->usage; j += N)
      {
        if (buckethash(batch->data[j + ord[0]]) != bucket || batch->data[j] == slog_null)
          continue;
        std::array<u64, N - 1> key;
        for (u16 c = 0; c + 1 < N; ++c) key[c] = batch->data[j + ord[c]];
        bool changed = false;
        u64 oldw = 0;
        const u64 merged = root->merge(key, batch->data[j + ord[N - 1]], changed,
                                       decomp ? &oldw : nullptr);
        if (!changed)
          batch->data[j] = slog_null;             // subsumed: no propagation
        else
        {
          if (decomp)
            emit_decomp_rows(root->lat_arena, pub, batch->data + j, N - 1,
                             decomp_map, oldw, merged);
          batch->data[j + ord[N - 1]] = merged;   // value-carrying delta
        }
      }
    }
    return true;
  }
};

// INTERN (struct): dedup by content (the index orders content cols first and the
// id slot, ord[N-1]==0, last); on a fresh tuple assign a per-bucket id, write it
// into the id slot, and insert.  The content prefix is range-scanned via
// lower_bound with a 0 id slot (the minimum), then confirmed column by column.
template <u16 N>
class InternStructTask : public Task
{
  Database* db;
  Relation* rel;
  u16 bucket;
  std::array<u16, N> ord;
  BTreeIndex<N>* root;
  u64* intern_alloc;
  u32 struct_id;
public:
  InternStructTask(Database* _db, Relation* _rel, const std::array<u16, N>& _ord, u16 _b)
    : db(_db), rel(_rel), bucket(_b), ord(_ord)
  {
    std::vector<u16> ordv(ord.begin(), ord.end());
    root = static_cast<BTreeIndex<N>*>(rel->getIndex(ordv, false)[bucket]);
    intern_alloc = rel->getInternAlloc(bucket);
    struct_id = rel->getStructId();
  }
  bool work() override
  {
    auto& delta = rel->getDelta();
    for (u32 i = 0; i < delta.size(); ++i)
    {
      InsertBatch* batch = delta[i];
      for (u32 j = 0; j < batch->usage; j += N)
      {
        if (buckethash(batch->data[j + ord[0]]) != bucket || batch->data[j] == slog_null)
          continue;
        std::array<u64, N> low;
        for (u16 c = 0; c < N - 1; ++c) low[c] = batch->data[j + ord[c]];
        low[N - 1] = 0;
        auto it = root->lower_bound(low);
        bool dup = (it != root->end());
        if (dup)
          for (u16 c = 0; c < N - 1; ++c)
            if ((*it)[c] != batch->data[j + ord[c]]) dup = false;
        if (dup)
          batch->data[j] = slog_null;
        else
        {
          batch->data[j] = struct_encode(struct_id, (*intern_alloc << bucket_bits) | bucket);
          ++(*intern_alloc);
          std::array<u64, N> key;
          for (u16 c = 0; c < N; ++c) key[c] = batch->data[j + ord[c]];
          root->insert(key);
        }
      }
    }
    return true;
  }
};

}
