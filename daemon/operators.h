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
#include <algorithm>
#include <array>
#include <set>
#include <vector>

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

// TERNARY KEY-SIMPLE CYCLE CLOSER (docs/wcoj.md).  A logical prefix cursor
// exposes the sole free column K of an A=K+1 table access as a sorted stream.
// FULL reads one index, OLD reads FULL-current-delta, and NEW reads the sorted
// union of post-delete FULL and the deleted delta.  FULL and DELTA use the same
// complete ordering for OLD/NEW.
enum class Join3View : u8 { full, old, new_ };

template <u16 A, u16 K, Join3View V>
class Join3PrefixCursor
{
  static_assert(K > 0, "join3 needs a non-empty bound prefix");
  static_assert(K + 1 == A, "join3 is key-simple (one free column)");

  using Key = std::array<u64, A>;
  using Tree = BTreeIndex<A>;
  using Iter = typename Tree::iterator;

  Tree* full;
  Tree* delta;
  Key prefix;
  Iter fit;
  Iter dit;
  bool fok = true;
  bool dok = true;

  bool same_prefix(const Key& row) const
  {
    for (u16 c = 0; c < K; ++c)
      if (row[c] != prefix[c]) return false;
    return true;
  }

  void normalize_full()
  {
    while (fit != full->end())
    {
      if (!same_prefix(*fit)) { fok = false; return; }
      if constexpr (V == Join3View::old)
      {
        if (delta->contains(*fit)) { ++fit; continue; }
      }
      fok = true;
      return;
    }
    fok = false;
  }

  void normalize_delta()
  {
    if constexpr (V == Join3View::new_)
    {
      if (dit != delta->end() && same_prefix(*dit)) dok = true;
      else dok = false;
    }
    else
      dok = false;
  }

public:
  // FULL passes its full-index array in both slots to keep the generated ABI
  // uniform; the delta iterator is never opened for FULL or OLD.
  Join3PrefixCursor(Index** full_indices, Index** delta_indices,
                    const Key& key)
    : full(static_cast<Tree*>(full_indices[buckethash(key[0])])),
      delta(static_cast<Tree*>(delta_indices[buckethash(key[0])])),
      prefix(key), fit(full->lower_bound(key)), dit(delta->end())
  {
    if constexpr (V == Join3View::new_) dit = delta->lower_bound(key);
    normalize_full();
    normalize_delta();
  }

  bool valid() const
  {
    if constexpr (V == Join3View::new_) return fok || dok;
    return fok;
  }

  u64 value() const
  {
    if constexpr (V == Join3View::new_)
    {
      if (!fok) return (*dit)[K];
      if (!dok) return (*fit)[K];
      return std::min((*fit)[K], (*dit)[K]);
    }
    return (*fit)[K];
  }

  // The physical premise row currently representing value().  NEW may have
  // the same logical row in FULL and DELTA; choose FULL deterministically on
  // overlap, matching the branch preference implicit in value().  This view
  // remains valid until seek()/advance_past() mutates the cursor.
  const Key& current() const
  {
    if constexpr (V == Join3View::new_)
    {
      if (!fok) return *dit;
      if (!dok) return *fit;
      return (*fit)[K] <= (*dit)[K] ? *fit : *dit;
    }
    return *fit;
  }

  void advance_past(u64 current)
  {
    if (fok && (*fit)[K] == current)
    {
      ++fit;
      normalize_full();
    }
    if constexpr (V == Join3View::new_)
    {
      // Advancing both branches on equality deduplicates FULL/DELTA overlap.
      if (dok && (*dit)[K] == current)
      {
        ++dit;
        normalize_delta();
      }
    }
  }

  void seek(u64 target)
  {
    // Nearby values are cheaper to visit on the current immutable B-tree leaf;
    // real gaps use lower_bound.  Eight local steps was neutral-to-positive on
    // dense ER inputs while preserving the hub/skew wins (docs/wcoj.md).
    for (u16 step = 0; step < 8 && valid() && value() < target; ++step)
    {
      const u64 current = value();
      advance_past(current);
    }
    if (!valid() || value() >= target) return;

    Key key = prefix;
    key[K] = target;
    if (fok && (*fit)[K] < target)
    {
      fit = full->lower_bound(key);
      normalize_full();
    }
    if constexpr (V == Join3View::new_)
    {
      if (dok && (*dit)[K] < target)
      {
        dit = delta->lower_bound(key);
        normalize_delta();
      }
    }
  }
};

// Symmetric seek/leapfrog intersection.  Each arm can use an independently
// ordered and independently prefixed relation view; the shared suffix key is
// produced once for every value present in both logical streams.
template <u16 LA, u16 LK, Join3View LV,
          u16 RA, u16 RK, Join3View RV, class Cont>
inline void join3(Index** left_full, Index** left_delta,
                  const std::array<u64, LA>& left_key,
                  Index** right_full, Index** right_delta,
                  const std::array<u64, RA>& right_key, Cont&& k)
{
  Join3PrefixCursor<LA, LK, LV> left(left_full, left_delta, left_key);
  Join3PrefixCursor<RA, RK, RV> right(right_full, right_delta, right_key);
  while (left.valid() && right.valid())
  {
    const u64 l = left.value();
    const u64 r = right.value();
    if (l < r) left.seek(r);
    else if (r < l) right.seek(l);
    else
    {
      k(l);
      left.advance_past(l);
      right.advance_past(r);
    }
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

// FILTER (negated atom, docs/incremental.md §0.8): does NO tuple of the index
// match the K-column bound prefix?  The negation of exists_probe -- except
// K == 0 (an all-wildcard negation = emptiness test), where the bound prefix
// names no bucket: tuples are hash-partitioned by their lead column, so
// emptiness must consult every bucket.  Always probes a FULL index of a
// CLOSED (strictly-lower-stratum) relation -- never a delta, never sliced --
// so the answer is stable across the reading stratum's iterations.
template <u16 A, u16 K>
inline bool absent_probe(Index** index, const std::array<u64, A>& key)
{
  if constexpr (K == 0)
  {
    for (u16 b = 0; b < bucket_count; ++b)
    {
      auto* idx = static_cast<BTreeIndex<A>*>(index[b]);
      if (idx->begin() != idx->end())
        return false;
    }
    return true;
  }
  else
    return !exists_probe<A, K>(index, key);
}

// FILTER (negation over lattice keys, §0.8): does the payload map hold NO
// entry under the K-bound key prefix ("no value at key k")?  K == 0 asks
// whether the map is empty.  Same closed-relation/full-index contract as
// absent_probe; KA is the map's key width (the ordering's trailing value
// column is not part of the key array).
template <u16 KA, u16 K>
inline bool absent_probe_lat(Index** index, const std::array<u64, KA>& key)
{
  if constexpr (K == 0)
  {
    for (u16 b = 0; b < bucket_count; ++b)
    {
      auto* idx = static_cast<BTreeMapIndex<KA>*>(index[b]);
      if (idx->begin() != idx->end())
        return false;
    }
    return true;
  }
  else
  {
    auto* idx = static_cast<BTreeMapIndex<KA>*>(index[buckethash(key[0])]);
    auto it = idx->lower_bound(key);
    if (it == idx->end())
      return true;
    const std::array<u64, KA>& m = it->first;
    for (u16 c = 0; c < K; ++c)
      if (m[c] != key[c])
        return true;
    return false;
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

// JOIN against R_old = FULL - current delta (docs/incremental.md §6/§8: exact
// semi-naive).  For a dynamic body clause ordered AFTER the delta driver, a
// plain full-index probe double-fires any assignment whose premises are ALL
// new this round (it fires once per new premise, once per driving variant).
// The fix: probe the full index exactly like join_probe, but skip every match
// that is also in the relation's CURRENT delta -- so each assignment fires in
// exactly one variant (the one driving its last-in-order new clause).  `delta`
// is a delta index of the SAME ordering as `full`, so a full-index match `m`
// (whose lead column equals the bound key's) tests directly, in the same
// bucket.  At iteration 0 (reload: delta = whole DB) R_old is empty, so only
// the no-old variant fires -- the reload double-count collapses to exact too.
template <u16 A, u16 K, class Cont>
inline void join_probe_old(Index** full, Index** delta,
                           const std::array<u64, A>& key, Cont&& k)
{
  auto* fidx = static_cast<BTreeIndex<A>*>(full[buckethash(key[0])]);
  auto* didx = static_cast<BTreeIndex<A>*>(delta[buckethash(key[0])]);
  for (auto it = fidx->lower_bound(key); it != fidx->end(); ++it)
  {
    const std::array<u64, A>& m = *it;
    for (u16 c = 0; c < K; ++c)
      if (m[c] != key[c]) return;         // prefix gone => done (sorted order)
    if (didx->contains(m)) continue;      // in the current delta => not R_old
    k(m);
  }
}

// JOIN (cartesian, no bound prefix) against R_old: join_all's every-bucket scan
// with the same current-delta exclusion (a variable-disjoint dynamic clause
// ordered after the driver).
template <u16 A, class Cont>
inline void join_all_old(Index** full, Index** delta, Cont&& k)
{
  for (u16 b = 0; b < bucket_count; ++b)
  {
    auto* fidx = static_cast<BTreeIndex<A>*>(full[b]);
    for (auto it = fidx->begin(); it != fidx->end(); ++it)
    {
      const std::array<u64, A>& m = *it;
      if (static_cast<BTreeIndex<A>*>(delta[buckethash(m[0])])->contains(m))
        continue;
      k(m);
    }
  }
}

// Negative exact partition pre-state view O = N union DeltaMinus.  FULL is
// the post-deletion N view; the delta index retains the removed witnesses.
template <u16 A, u16 K, class Cont>
inline void join_probe_new(Index** full, Index** delta,
                           const std::array<u64, A>& key, Cont&& k)
{
  auto* fidx = static_cast<BTreeIndex<A>*>(full[buckethash(key[0])]);
  auto* didx = static_cast<BTreeIndex<A>*>(delta[buckethash(key[0])]);
  for (auto it = fidx->lower_bound(key); it != fidx->end(); ++it)
  {
    const std::array<u64, A>& m = *it;
    bool match = true;
    for (u16 c = 0; c < K; ++c) if (m[c] != key[c]) { match = false; break; }
    if (!match) break;
    k(m);
  }
  for (auto it = didx->lower_bound(key); it != didx->end(); ++it)
  {
    const std::array<u64, A>& m = *it;
    bool match = true;
    for (u16 c = 0; c < K; ++c) if (m[c] != key[c]) { match = false; break; }
    if (!match) break;
    if (!fidx->contains(m)) k(m);
  }
}

template <u16 A, class Cont>
inline void join_all_new(Index** full, Index** delta, Cont&& k)
{
  for (u16 b = 0; b < bucket_count; ++b)
  {
    auto* fidx = static_cast<BTreeIndex<A>*>(full[b]);
    auto* didx = static_cast<BTreeIndex<A>*>(delta[b]);
    for (auto it = fidx->begin(); it != fidx->end(); ++it) k(*it);
    for (auto it = didx->begin(); it != didx->end(); ++it)
      if (!fidx->contains(*it)) k(*it);
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

// SINK (seeded-task struct): like emit_struct, but probe the master
// (content-ordered) index first and SKIP instances the database already
// holds.  A seeded re-entry task (the staging-replay fix) re-evaluates its
// whole join every iteration; without this check its re-emissions of known
// structs would count as fresh delta at every finalize and hold the
// stratum's fixpoint open forever.  (Table `emit` sinks already dedup
// against their head index; temps never appear in seeded heads -- a
// reest-driven stage binds only re-establishable values, so its residue
// carries nothing -- and lattice-headed rules are excluded from seeded
// planning.)  `fields` arrive in master-content order, so the probe key is
// fields plus a zero id slot.
template <u16 A>
inline void emit_struct_checked(Relation* head_rel, Index** master,
                                InsertBatch*& nb,
                                const std::array<u64, A - 1>& fields,
                                const std::array<u16, A>& head_ord)
{
  std::array<u64, A> key;
  for (u16 j = 0; j < A - 1; ++j)
    key[j] = fields[j];
  key[A - 1] = 0;
  if (exists_probe<A, A - 1>(master, key))
    return;
  emit_struct<A>(head_rel, nb, fields, head_ord);
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


// ---------------------------------------------------------------------------
// Counting sinks (docs/incremental.md §8B.1/§6.2, the `_count` flavor).
//
// The count round fires each rule exactly once over FULL indices at a
// SETTLED fixpoint, so every emission is a re-derivation of a tuple the
// database already holds: these sinks do NO dedup-skip (each instantiation
// is one contribution) and never insert -- rows ride the ordinary
// send-shard/delta transport, tagged with the rule's contribution kind on
// the batch, and the CountTask/CountStructTask write phase folds them into
// the relation's count sidecar (database.h).  An emission ABSENT from the
// master index means the fixpoint was not settled (or a §5.3 nondeterminism
// escape) -- counting it would corrupt the sidecar, so it is a loud fatal,
// the same corruption-detector stance as cnt_add's underflow.
// ---------------------------------------------------------------------------

// M1 signed support contribution.  Unlike emit_count this deliberately does
// not probe or skip the live index: a head that is already present still gains
// one support, while an absent head becomes a presence transition only after
// MaintainTask folds the contribution.
template <u16 A>
inline void emit_maint(Relation* head_rel, u8 kind, s8 sign,
                       InsertBatch*& nb, const std::array<u64, A>& zs,
                       const std::array<u16, A>& head_ord)
{
  (void)head_rel;
  nb->kind = kind;
  nb->sign = sign;
  u64* d = nb->data + nb->usage;
  for (u16 j = 0; j < A; ++j) d[head_ord[j]] = zs[j];
  nb->usage += A;
  if (nb->usage + A >= batch_size_max)
  {
    head_rel->sendBatch(nb);
    nb = new InsertBatch();
    nb->kind = kind;
    nb->sign = sign;
  }
}

// SINK (counted relation head): like emit, but a closure CHECK instead of a
// dedup SKIP, and the batch carries `kind`.
template <u16 A>
inline void emit_count(Relation* head_rel, Index** head_index, u8 kind,
                       InsertBatch*& nb, const std::array<u64, A>& zs,
                       const std::array<u16, A>& head_ord)
{
  if (!static_cast<BTreeIndex<A>*>(head_index[buckethash(zs[0])])->contains(zs))
    fatal("count round derived a tuple absent from " + head_rel->getName()
          + " -- the fixpoint is not settled (docs/incremental.md 8B.1)");
  nb->kind = kind;
  u64* d = nb->data + nb->usage;
  for (u16 j = 0; j < A; ++j)
    d[head_ord[j]] = zs[j];
  nb->usage += A;
  if (nb->usage + A >= batch_size_max)
  {
    head_rel->sendBatch(nb);
    nb = new InsertBatch();
    nb->kind = kind;
  }
}

// M6L lattice contributor sinks.  A lattice's visible map contains only the
// joined payload, so a non-winning contribution is normally absent from that
// map and cannot pass emit_count's closure check.  Count and maintenance
// flavors instead preserve every emitted (key..., payload) row in nominal
// storage order; CountTask/LatticeMaintainTask fold its support separately.
template <u16 A>
inline void emit_lattice_count(Relation* head_rel, u8 kind,
                               InsertBatch*& nb,
                               const std::array<u64, A>& zs)
{
  nb->kind = kind;
  u64* d = nb->data + nb->usage;
  for (u16 j = 0; j < A; ++j) d[j] = zs[j];
  nb->usage += A;
  if (nb->usage + A >= batch_size_max)
  {
    head_rel->sendBatch(nb);
    nb = new InsertBatch();
    nb->kind = kind;
  }
}

template <u16 A>
inline void emit_lattice_maint(Relation* head_rel, u8 kind, s8 sign,
                               InsertBatch*& nb,
                               const std::array<u64, A>& zs)
{
  nb->kind = kind;
  nb->sign = sign;
  u64* d = nb->data + nb->usage;
  for (u16 j = 0; j < A; ++j) d[j] = zs[j];
  nb->usage += A;
  if (nb->usage + A >= batch_size_max)
  {
    head_rel->sendBatch(nb);
    nb = new InsertBatch();
    nb->kind = kind;
    nb->sign = sign;
  }
}

// SINK (counted struct head): at a settled fixpoint the instance is already
// interned, so resolve its id NOW by content (the read phase never mutates
// indices, so this probe is safe) and emit the full storage-order row --
// id in place, not the 0 placeholder -- letting CountStructTask bucket by
// the id, the struct sidecar's key (§6.1).  `fields` arrive in
// master-content order exactly as for emit_struct_checked.
template <u16 A>
inline void emit_struct_count(Relation* head_rel, Index** master, u8 kind,
                              InsertBatch*& nb,
                              const std::array<u64, A - 1>& fields,
                              const std::array<u16, A>& head_ord)
{
  // Nullary constructions never lower to mkstruct sites (they intern as
  // plugin-load constants), and an empty content prefix would probe the
  // wrong bucket here -- keep that assumption loud.
  static_assert(A >= 2, "emit_struct_count: nullary struct head");
  std::array<u64, A> key;
  for (u16 j = 0; j < A - 1; ++j)
    key[j] = fields[j];
  key[A - 1] = 0;
  u64 id = 0;
  bool found = false;
  join_probe<A, A - 1>(master, key, [&](const std::array<u64, A>& m)
  {
    id = m[A - 1];
    found = true;
  });
  if (!found)
    fatal("count round derived an uninterned " + head_rel->getName()
          + " instance -- the fixpoint is not settled (docs/incremental.md 8B.1)");
  nb->kind = kind;
  u64* d = nb->data + nb->usage;
  d[head_ord[A - 1]] = id;
  for (u16 j = 0; j < A - 1; ++j)
    d[head_ord[j]] = fields[j];
  nb->usage += A;
  if (nb->usage + A >= batch_size_max)
  {
    head_rel->sendBatch(nb);
    nb = new InsertBatch();
    nb->kind = kind;
  }
}

// M4S struct RESOLUTION probe (docs/m4s-contract.md "Negative-phase
// mkstruct is probe-only"): resolve a constructed head's id by content
// against the live MASTER first, then the bucket's tombstone dictionary --
// a sweep round may tombstone the head arbitrarily many rounds before the
// last follow-up decrement referencing it, and the retained delta witness
// lives only one round, so no FULL∪delta view can span the gap.  Never
// allocates, never resurrects; a miss in both yields NO row (the co-emitted
// mkstruct decrement already invalidated the epoch on the same miss).  The
// key is the full content prefix in master order (K = A-1); the
// continuation receives the master-ordered row (content..., id).
template <u16 A, class K>
inline void join_probe_tomb(Relation* rel, Index** master,
                            const std::array<u64, A>& key, K&& k)
{
  static_assert(A >= 2, "join_probe_tomb: nullary struct");
  bool found = false;
  join_probe<A, A - 1>(master, key, [&](const std::array<u64, A>& m)
  {
    found = true;
    k(m);
  });
  if (found) return;
  const std::vector<u16>& ord = rel->getMasterIndex();
  u64 row[A];
  row[0] = 0;
  for (u16 c = 0; c + 1 < A; ++c) row[ord[c]] = key[c];
  u64 idw = 0;
  if (rel->peekTombstone(buckethash(key[0]), row, ord.data(), A, idw))
  {
    std::array<u64, A> m;
    for (u16 c = 0; c + 1 < A; ++c) m[c] = key[c];
    m[A - 1] = idw;
    k(m);
  }
}

// M4S signed struct support contribution (docs/m4s-contract.md).  Content
// fields ride in master order with the 0 id placeholder, exactly like
// emit_struct: the id CANNOT be resolved at emit time -- a positive
// contribution may be the first derivation of fresh content (the intern
// path runs in MaintainStructTask's serial fold), and a negative one may
// reference a row an earlier fold already tombstoned (whose id only the
// dictionary still knows).
template <u16 A>
inline void emit_struct_maint(Relation* head_rel, u8 kind, s8 sign,
                              InsertBatch*& nb,
                              const std::array<u64, A - 1>& fields,
                              const std::array<u16, A>& head_ord)
{
  static_assert(A >= 2, "emit_struct_maint: nullary struct head");
  nb->kind = kind;
  nb->sign = sign;
  u64* d = nb->data + nb->usage;
  d[head_ord[A - 1]] = 0;
  for (u16 j = 0; j < A - 1; ++j)
    d[head_ord[j]] = fields[j];
  nb->usage += A;
  if (nb->usage + A >= batch_size_max)
  {
    head_rel->sendBatch(nb);
    nb = new InsertBatch();
    nb->kind = kind;
    nb->sign = sign;
  }
}

// SINK (counted runtime-error struct): §8B.4 -- a guard fault is a
// deterministic function of the instantiation, so error rows count like any
// derivation.  Self-contained batch like emit_error_struct.
template <u16 A>
inline void emit_error_struct_count(Relation* rel, u8 kind,
                                    const std::array<u64, A - 1>& fields,
                                    const std::array<u16, A>& head_ord)
{
  InsertBatch* nb = new InsertBatch();
  emit_struct_count<A>(rel, rel->getIndex(rel->getMasterIndex(), false),
                       kind, nb, fields, head_ord);
  rel->sendBatch(nb);
}

// The counted flavor's emit_pending_error: same arm dispatch, counting sinks.
inline void emit_pending_error_count(Database* db, const char* loc, u8 kind)
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
      emit_error_struct_count<3>(rel("div_by_zero"),    kind, {vloc, pe.a}, {1, 2, 0}); break;
    case ERR_MOD0:
      emit_error_struct_count<3>(rel("modulo_by_zero"), kind, {vloc, pe.a}, {1, 2, 0}); break;
    case ERR_INT_OVF:
      emit_error_struct_count<4>(rel("int_overflow"),   kind, {vloc, pe.a, pe.b}, {1, 2, 3, 0}); break;
    case ERR_NAN:
      emit_error_struct_count<4>(rel("nan_result"),     kind, {vloc, str_encode(db, pe.op), pe.a}, {1, 2, 3, 0}); break;
    case ERR_TOINT:
      emit_error_struct_count<3>(rel("toint_range"),    kind, {vloc, pe.a}, {1, 2, 0}); break;
    case ERR_TYPE:
      emit_error_struct_count<5>(rel("type_mismatch"),  kind, {vloc, str_encode(db, pe.op), pe.a, pe.b}, {1, 2, 3, 4, 0}); break;
    case ERR_MPZ_OVF:
      emit_error_struct_count<5>(rel("mpz_overflow"),   kind, {vloc, str_encode(db, pe.op), pe.a, pe.b}, {1, 2, 3, 4, 0}); break;
    case ERR_MPZ_TABLE:
      emit_error_struct_count<3>(rel("mpz_table_overflow"), kind, {vloc, str_encode(db, pe.op)}, {1, 2, 0}); break;
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
  bool is_delta;
public:
  WriteTask(Database* _db, Relation* _rel, const std::array<u16, A>& _ord, bool delta, u16 _b)
    : db(_db), rel(_rel), bucket(_b), ord(_ord), is_delta(delta)
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
        if (!is_delta && refs[r].batch->sign < 0) continue;
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
          // M5 (docs/m5-contract.md): a live-master miss may still be a
          // dictionary hit -- dead content retains its id as a tombstone
          // and reappearance resurrects it instead of minting.
          u64 idw;
          if (!rel->takeTombstone(bucket, batch->data + j, ord.data(), N, idw))
          {
            idw = struct_encode(struct_id, (*intern_alloc << bucket_bits) | bucket);
            ++(*intern_alloc);
          }
          batch->data[j] = idw;
          std::array<u64, N> key;
          for (u16 c = 0; c < N; ++c) key[c] = batch->data[j + ord[c]];
          root->insert(key);
        }
      }
    }
    return true;
  }
};

// COUNT (table, docs/incremental.md §8B.1/§6.1): fold this iteration's delta
// -- kind-tagged contribution rows from the counting sinks, never nulled
// (the _count flavor registers no intern task for counted heads) -- into one
// bucket of the relation's count sidecar.  The sidecar keys tables by the
// FULL tuple in storage order, bucketed by buckethash(storage column 0), so
// each per-bucket task owns its map exclusively (no races).  Registered
// every iteration at phase_intern: contributions emitted by iteration k's
// read phase are finalized into the delta phase_intern consumes in the same
// iteration, so each is folded exactly once.  A kind-less batch reaching a
// counted head is a flavor mix-up and fatals in cnt_apply.
template <u16 A>
class CountTask : public Task
{
  Database* db;
  Relation* rel;
  u16 bucket;
  BTreeMapIndex<A>* side;
public:
  CountTask(Database* _db, Relation* _rel, u16 _b)
    : db(_db), rel(_rel), bucket(_b)
  {
    side = static_cast<BTreeMapIndex<A>*>(rel->ensureCountSidecar()[_b]);
  }
  bool work() override
  {
    // Already counted (a previous walk, closed by markCounted): folding
    // this round's re-derivations would double every counter, so the
    // exact contributions are DROPPED.  The flag only flips at the end
    // of a whole walk, never mid-round (§8B.2, M0.3).
    if (rel->isCounted() && !rel->isCountEpochActive())
      return true;
    auto& delta = rel->getDelta();
    for (u32 i = 0; i < delta.size(); ++i)
    {
      InsertBatch* batch = delta[i];
      for (u32 j = 0; j < batch->usage; j += A)
      {
        if (buckethash(batch->data[j]) != bucket || batch->data[j] == slog_null)
          continue;
        std::array<u64, A> key;
        for (u16 c = 0; c < A; ++c) key[c] = batch->data[j + c];
        auto r = side->tree.insert2(key, 0);
        u64 next = 0;
        if (!rel->tryApplyCount(r.first->second, batch->kind, next))
          rel->invalidateCountEpoch();
        else
          r.first->second = next;
      }
    }
    return true;
  }
};

// M1 positive maintenance interner.  Contribution multiplicity is folded
// into the sidecar, but the ordinary delta retained for the next iteration
// contains exactly one row iff membership crossed in the batch's direction.
// A single task per relation owns the sidecar and all master buckets; signed
// maintenance is latency-oriented and this avoids cross-ordering index races
// while keeping the read phase fully parallel.
//
// With `dred` set (the M4T sweep, docs/m4t-contract.md) the negative fold
// policy changes in exactly two ways: a live row is over-deleted on
// FOUNDATION loss rather than presence loss (its sidecar entry survives
// while rec > 0), and a row absent from the live indices that still owns a
// sidecar entry is a dead candidate that legally absorbs further decrements
// without re-staging or invalidating.
template <u16 A>
class MaintainTask : public Task
{
  Database* db;
  Relation* rel;
  std::array<u16, A> ord;
  Index** roots;
  Index** side;
  bool dred;
public:
  MaintainTask(Database* _db, Relation* _rel,
               const std::array<u16, A>& _ord, u16, bool _dred = false)
    : db(_db), rel(_rel), ord(_ord), dred(_dred)
  {
    std::vector<u16> ordv(ord.begin(), ord.end());
    roots = rel->getIndex(ordv, false);
    side = rel->ensureCountSidecar();
  }
  bool work() override
  {
    auto& delta = rel->getDelta();
    for (InsertBatch* batch : delta)
      for (u32 j = 0; j < batch->usage; j += A)
      {
        u64* row = batch->data + j;
        if (row[0] == slog_null) continue;
        if (batch->kind == cnt_kind_premise)
        {
          // The premise already drove this iteration and was installed in
          // the live index before the maintenance plugin began.
          row[0] = slog_null;
          continue;
        }
        if (batch->kind == cnt_kind_view)
          fatal("view-only staged row reached a maintenance fold on "
                + rel->getName() + " (docs/m4n-contract.md pin 3): "
                  "mis-staged polarity");
        std::array<u64, A> key;
        for (u16 c = 0; c < A; ++c) key[c] = row[ord[c]];
        BTreeIndex<A>* root = static_cast<BTreeIndex<A>*>(
          roots[buckethash(key[0])]);
        const bool was_live = root->contains(key);

        u64 word = 0;
        const u16 cb = buckethash(row[0]);
        side[cb]->getPayload(row, A, word);
        u64 next = word;
        const bool ok = rel->isCounted()
                     && rel->tryApplyCountSigned(word, batch->kind,
                                                 batch->sign, next);
        if (ok && cnt_present(next))
          side[cb]->setPayload(row, A, next);
        else if (ok)
        {
          std::array<u64, A> countkey;
          for (u16 c = 0; c < A; ++c) countkey[c] = row[c];
          static_cast<BTreeMapIndex<A>*>(side[cb])->tree.erase(countkey);
        }
        else
          db->invalidateUpdateCounts();

        if (batch->sign < 0)
        {
          if (!ok)
            row[0] = slog_null;
          else if (dred && !was_live)
          {
            // Dead candidate: over-deleted earlier this epoch with its
            // sidecar entry retained.  The fold above already absorbed the
            // decrement (a missing entry underflows into !ok instead).  It
            // never re-stages -- each tuple enters candidacy at most once.
            row[0] = slog_null;
          }
          else if (!was_live || cnt_present(word) != was_live)
          {
            db->invalidateUpdateCounts();
            row[0] = slog_null;
          }
          else if (dred ? cnt_foundation(next) : cnt_present(next))
            row[0] = slog_null;       // support-only loss
          else
          {
            if (!rel->removeTupleAllIndicesPreservingCounts(row))
            {
              db->invalidateUpdateCounts();
              row[0] = slog_null;
            }
            else
            {
              db->recordUpdateTransition(rel, row, -1);
              // Retain exactly one false-transition row as next iteration's
              // negative delta.  Full WriteTasks skip negative batches.
            }
          }
        }
        else if (was_live)
          row[0] = slog_null;
        else
        {
          // Every registered non-seeded ordering, not just this flavor's
          // master: other flavors' orderings must stay authoritative
          // (matching removeTupleAllIndicesPreservingCounts on the way out).
          rel->insertTupleAllIndicesPreservingCounts(row);
          db->recordUpdateTransition(rel, row, 1);
        }
      }
    return true;
  }
};

// M6L lattice repair.  The support sidecar is keyed by the complete
// emitted contribution, while the resident lattice map is keyed by all but
// the payload.  Fold all signed support changes first, then reduce each
// affected key once and replace/remove its visible joined payload atomically
// across every registered map ordering.  Contribution rows are private to
// this sink and never become ordinary lattice delta.
template <u16 A>
class LatticeMaintainTask : public Task
{
  static_assert(A >= 2, "lattice relation must have a key and payload");
  Database* db;
  Relation* rel;
  Index** side;
public:
  LatticeMaintainTask(Database* _db, Relation* _rel)
    : db(_db), rel(_rel), side(_rel->ensureCountSidecar()) {}

  bool work() override
  {
    std::set<std::vector<u64>> affected;
    auto& delta = rel->getDelta();
    for (InsertBatch* batch : delta)
      for (u32 j = 0; j < batch->usage; j += A)
      {
        u64* row = batch->data + j;
        if (row[0] == slog_null) continue;
        if (batch->kind == cnt_kind_premise)
        {
          row[0] = slog_null;
          continue;
        }
        if (batch->kind == cnt_kind_view)
          fatal("view-only staged row reached a lattice maintenance fold on "
                + rel->getName() + " (docs/m4n-contract.md pin 3): "
                  "mis-staged polarity");

        const u16 bucket = buckethash(row[0]);
        u64 word = 0;
        side[bucket]->getPayload(row, A, word);
        u64 next = word;
        const bool ok = rel->isCounted()
                     && rel->tryApplyCountSigned(word, batch->kind,
                                                 batch->sign, next);
        if (ok && cnt_present(next))
          side[bucket]->setPayload(row, A, next);
        else if (ok)
        {
          std::array<u64, A> contribution;
          for (u16 c = 0; c < A; ++c) contribution[c] = row[c];
          static_cast<BTreeMapIndex<A>*>(side[bucket])->tree.erase(contribution);
        }
        else
          db->invalidateUpdateCounts();

        if (ok)
          affected.insert(std::vector<u64>(row, row + A - 1));
        row[0] = slog_null;
      }

    for (const std::vector<u64>& key : affected)
    {
      u64 old_value = 0, new_value = 0;
      const bool old_present = rel->getLatticePayloadForKey(key, old_value);
      const bool new_present = rel->reduceLatticeContributorKey(side, key,
                                                                 new_value);
      if (old_present == new_present
          && (!old_present || old_value == new_value))
        continue;

      u64 row[A];
      for (u16 c = 0; c + 1 < A; ++c) row[c] = key[c];
      if (!rel->setLatticePayloadForKey(key, new_present, new_value))
      {
        db->invalidateUpdateCounts();
        continue;
      }
      if (old_present)
      {
        row[A - 1] = old_value;
        db->recordUpdateTransition(rel, row, -1);
      }
      if (new_present)
      {
        row[A - 1] = new_value;
        db->recordUpdateTransition(rel, row, 1);
      }
      db->recordLatticeReplacement(rel, key, old_present, old_value,
                                   new_present, new_value);
    }
    return true;
  }
};

// COUNT (struct): as CountTask, but the sidecar keys structs by the id
// column alone (§6.1) -- the counting sink resolved each row's id at emit
// time (emit_struct_count), so storage column 0 carries the real id and
// bucketing by it matches the sidecar's convention.  `A` is the storage
// arity (row stride); the key is 1-wide.
template <u16 A>
class CountStructTask : public Task
{
  Database* db;
  Relation* rel;
  u16 bucket;
  BTreeMapIndex<1>* side;
public:
  CountStructTask(Database* _db, Relation* _rel, u16 _b)
    : db(_db), rel(_rel), bucket(_b)
  {
    side = static_cast<BTreeMapIndex<1>*>(rel->ensureCountSidecar()[_b]);
  }
  bool work() override
  {
    if (rel->isCounted() && !rel->isCountEpochActive())
      return true;
    auto& delta = rel->getDelta();
    for (u32 i = 0; i < delta.size(); ++i)
    {
      InsertBatch* batch = delta[i];
      for (u32 j = 0; j < batch->usage; j += A)
      {
        if (buckethash(batch->data[j]) != bucket || batch->data[j] == slog_null)
          continue;
        std::array<u64, 1> key = { batch->data[j] };
        auto r = side->tree.insert2(key, 0);
        u64 next = 0;
        if (!rel->tryApplyCount(r.first->second, batch->kind, next))
          rel->invalidateCountEpoch();
        else
          r.first->second = next;
      }
    }
    return true;
  }
};

// M4S struct maintenance fold (docs/m4s-contract.md): MaintainTask's fold
// policy over the M5 identity substrate.  One task per relation owns the
// master, every secondary ordering, the tombstone dictionary, the intern
// allocators, and the id-keyed sidecar (§6.1), so the serial intern phase
// resolves ids and mutates membership without cross-ordering races.
//
// Id resolution is sign-directed.  A POSITIVE contribution takes the
// ordinary intern path -- live-master dedup, tombstone resurrection, fresh
// allocation, in that order -- so a relearned or re-added head reuses its
// original id (M5) and a genuinely new head mints above the monotone
// allocator.  A NEGATIVE contribution resolves by PROBE ONLY: the live
// master first, then the bucket's tombstones (dead-candidate absorption);
// a miss in both means the claimed lost instantiation could never have
// fired -- an epoch-invalidating fold error, never an allocation or a
// resurrection.  Membership transitions go through tombstoneStructRow /
// insertTupleAllIndicesPreservingCounts, so every registered non-seeded
// ordering stays authoritative and dead content keeps its id.
template <u16 A>
class MaintainStructTask : public Task
{
  static_assert(A >= 2, "struct relation must have content and an id column");
  Database* db;
  Relation* rel;
  std::array<u16, A> ord;      // canonical master: content columns, id last
  Index** roots;
  Index** side;                // id-keyed count sidecar (width-1 entries)
  u32 struct_id;
  bool dred;
public:
  MaintainStructTask(Database* _db, Relation* _rel,
                     const std::array<u16, A>& _ord, u16, bool _dred = false)
    : db(_db), rel(_rel), ord(_ord), dred(_dred)
  {
    std::vector<u16> ordv(ord.begin(), ord.end());
    roots = rel->getIndex(ordv, false);
    side = rel->ensureCountSidecar();
    struct_id = rel->getStructId();
  }
  bool work() override
  {
    auto& delta = rel->getDelta();
    for (InsertBatch* batch : delta)
      for (u32 j = 0; j < batch->usage; j += A)
      {
        u64* row = batch->data + j;
        if (row[0] == slog_null) continue;
        if (batch->kind == cnt_kind_premise)
        {
          // Staged journal rows drove this iteration's reads; they carry
          // real ids and are not support contributions.
          row[0] = slog_null;
          continue;
        }
        if (batch->kind == cnt_kind_view)
          fatal("view-only staged row reached a struct maintenance fold on "
                + rel->getName() + " (docs/m4n-contract.md pin 3): "
                  "mis-staged polarity");

        // Resolve the id (row[0] holds emit_struct_maint's 0 placeholder).
        // Live-master dedup exactly as InternStructTask: range-probe the
        // content prefix, confirm column by column.
        const u16 b = buckethash(row[ord[0]]);
        BTreeIndex<A>* root = static_cast<BTreeIndex<A>*>(roots[b]);
        std::array<u64, A> low;
        for (u16 c = 0; c + 1 < A; ++c) low[c] = row[ord[c]];
        low[A - 1] = 0;
        auto it = root->lower_bound(low);
        bool was_live = (it != root->end());
        if (was_live)
          for (u16 c = 0; c + 1 < A; ++c)
            if ((*it)[c] != row[ord[c]]) was_live = false;
        if (was_live)
          row[0] = (*it)[A - 1];
        else if (batch->sign > 0)
        {
          u64 idw;
          if (!rel->takeTombstone(b, row, ord.data(), A, idw))
          {
            u64* alloc = rel->getInternAlloc(b);
            idw = struct_encode(struct_id, (*alloc << bucket_bits) | b);
            ++(*alloc);
          }
          row[0] = idw;
        }
        else if (!rel->peekTombstone(b, row, ord.data(), A, row[0]))
        {
          db->invalidateUpdateCounts();
          row[0] = slog_null;
          continue;
        }

        // Fold into the id-keyed sidecar (bucketed by the id, matching
        // CountStructTask and the coverage audits).
        u64 word = 0;
        const u16 cb = buckethash(row[0]);
        side[cb]->getPayload(row, 1, word);
        u64 next = word;
        const bool ok = rel->isCounted()
                     && rel->tryApplyCountSigned(word, batch->kind,
                                                 batch->sign, next);
        if (ok && cnt_present(next))
          side[cb]->setPayload(row, 1, next);
        else if (ok)
        {
          std::array<u64, 1> countkey = { row[0] };
          static_cast<BTreeMapIndex<1>*>(side[cb])->tree.erase(countkey);
        }
        else
          db->invalidateUpdateCounts();

        if (batch->sign < 0)
        {
          if (!ok)
            row[0] = slog_null;
          else if (dred && !was_live)
          {
            // Dead candidate (resolved through the retained tombstone):
            // the fold above absorbed the decrement; never re-stages.
            row[0] = slog_null;
          }
          else if (!was_live || cnt_present(word) != was_live)
          {
            db->invalidateUpdateCounts();
            row[0] = slog_null;
          }
          else if (dred ? cnt_foundation(next) : cnt_present(next))
            row[0] = slog_null;       // support-only loss
          else
          {
            if (!rel->tombstoneStructRow(row))
            {
              db->invalidateUpdateCounts();
              row[0] = slog_null;
            }
            else
            {
              db->recordUpdateTransition(rel, row, -1);
              // Retain exactly one false-transition row (real id in place)
              // as next iteration's negative delta.  Full WriteTasks skip
              // negative batches; delta WriteTasks stage the DeltaMinus
              // view downstream reads probe.
            }
          }
        }
        else if (was_live)
          row[0] = slog_null;         // support-only gain
        else
        {
          // Resurrection or fresh mint: the membership transition.
          rel->insertTupleAllIndicesPreservingCounts(row);
          db->recordUpdateTransition(rel, row, 1);
        }
      }
    return true;
  }
};

}
