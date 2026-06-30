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
  void work() override
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
  void work() override
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
  void work() override
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
  }
};

}
