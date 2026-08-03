/** Slog Index
 *
 * Storage for one bucket of one relation index.  `Index` is an arity-agnostic
 * interface so the daemon (database.h) can manage and iterate indices without
 * knowing arity; `BTreeIndex<A>` is the arity-specialized concrete storage,
 * created and driven on the hot path by the generated code (which knows A).
 *
 * Tuples are stored as std::array<u64, A> in the index's column ordering, so a
 * tlx::btree_set keeps them sorted lexicographically by that ordering -- making
 * point lookups (dedup), full-key existence (head check), and especially join
 * probes (prefix range-scans) cache-friendly.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

#include "types.h"
#include "arena.h"   // LatSpec + CollectionArena, for LAT_EXTERN payload joins

// slog's headers (debug.h) define a `debug` object-like macro, which collides
// with tlx's `static const bool debug` members.  Shield the tlx include from it.
#pragma push_macro("debug")
#undef debug
#include "tlx/container/btree_set.hpp"
#include "tlx/container/btree_map.hpp"
#pragma pop_macro("debug")

#include <array>
#include <functional>


namespace slog
{

// Arity-agnostic interface for the generic (cold-path) operations the daemon
// performs: emptiness, clearing the delta, and iterating every tuple (for
// CSV/BIN output).  forEach hands back a pointer to the tuple's A u64 columns
// (in index-ordering); the caller knows the arity.
class Index
{
public:
  virtual ~Index() = default;
  virtual bool empty() const = 0;
  virtual u64 size() const = 0;
  virtual void clear() = 0;
  virtual void forEach(const std::function<void(const u64*)>& f) const = 0;
  // Insert a tuple given in STORAGE order, permuted by this index's column
  // ordering `ord` (which must have this index's arity).  A cold-path,
  // arity-generic escape hatch for the daemon itself (out-of-band ingestion);
  // generated code uses the typed insert below.
  virtual void insertTuple(const u64* t, const u16* ord) = 0;
  virtual bool removeTuple(const u64* t, const u16* ord) = 0;
  // Payload-map cold path used by transactional count foundation seeding and
  // coverage audits.  Plain set indices return false/refuse; BTreeMapIndex
  // interprets `key` in its own (identity for count sidecars) key order.
  virtual bool getPayload(const u64*, u16, u64&) const { return false; }
  virtual bool setPayload(const u64*, u16, u64) { return false; }
};


// Arity-specialized concrete storage.  The generated code holds the static type
// (it knows A) and calls the non-virtual hot-path methods directly -- no virtual
// dispatch in inner loops.  The daemon holds Index* and uses the virtuals above.
template <u16 A>
class BTreeIndex : public Index
{
public:
  using Key = std::array<u64, A>;   // tuple columns in this index's ordering
  using Tree = tlx::btree_set<Key>; // default std::less<Key> = lexicographic
  using iterator = typename Tree::iterator;

  Tree tree;

  // ---- hot path (typed; called from generated code) ----
  void insert(const Key& k) { tree.insert(k); }
  bool contains(const Key& k) const { return tree.exists(k); }
  iterator lower_bound(const Key& k) { return tree.lower_bound(k); }
  iterator begin() { return tree.begin(); }
  iterator end() { return tree.end(); }

  // ---- cold path (virtual; used by the daemon) ----
  bool empty() const override { return tree.empty(); }
  u64 size() const override { return tree.size(); }
  void clear() override { tree.clear(); }
  void forEach(const std::function<void(const u64*)>& f) const override
  {
    for (const Key& k : tree) f(k.data());
  }
  void insertTuple(const u64* t, const u16* ord) override
  {
    Key k;
    for (u16 c = 0; c < A; ++c)
      k[c] = t[ord[c]];
    tree.insert(k);
  }
  bool removeTuple(const u64* t, const u16* ord) override
  {
    Key k;
    for (u16 c = 0; c < A; ++c) k[c] = t[ord[c]];
    if (tree.find(k) == tree.end()) return false;
    tree.erase(k);
    return true;
  }
};


// Payload-carrying index for lattice (map) relations (docs/lattices.md §4.1):
// a btree_map from the KA key columns to the merged value word.  Registered
// under a FULL-length ordering whose last entry is the value column, so every
// generic cold path (forEach-driven CSV/BIN/reload dump, insertTuple-driven
// ingestion) sees ordinary arity-wide rows -- forEach materializes key+payload
// as one row, insertTuple merges (never blind-inserts, so out-of-band
// re-ingestion reproduces values exactly).  The owning relation's lattice
// metadata is copied in at registration (database.h addMapIndex).
template <u16 KA>
class BTreeMapIndex : public Index
{
public:
  using Key = std::array<u64, KA>;
  using Tree = tlx::btree_map<Key, u64>;
  using iterator = typename Tree::iterator;

  Tree tree;
  u32 lat_kind = LAT_NONE;
  bool lat_has_floor = false, lat_has_ceil = false;
  u64 lat_floor = 0, lat_ceil = 0;
  // LAT_EXTERN context (set/map valuespecs): the owning relation's parsed
  // spec tree and the database's collection arena, copied in at registration
  // like the kind/clamp words.
  const LatSpec* lat_spec_tree = nullptr;
  CollectionArena* lat_arena = nullptr;

  // ---- hot path (typed; called from generated code and the merge tasks) ----
  iterator lower_bound(const Key& k) { return tree.lower_bound(k); }
  iterator begin() { return tree.begin(); }
  iterator end() { return tree.end(); }

  // Clamp and join one contribution; returns the stored (merged) value and
  // sets `changed` iff the payload ascended (fresh key or strict growth).
  // When `oldw` is given it receives the PRE-merge payload word, or 0 for a
  // fresh key (0 is never a stored payload word) -- the (old, new) pair the
  // M2.4 decomposition's foreach_added tree-diff walks (docs/primitives.md
  // §4.2/§8.5).
  u64 merge(const Key& k, u64 v, bool& changed, u64* oldw = nullptr)
  {
    // lat_arena is the owning Database's collection arena for EVERY lattice
    // relation (setLattice callers all pass it); it carries the mpz table
    // the int-exact compare needs for bignum payloads.
    slog::InternTable<slog::mpz_val>* mt = lat_arena ? lat_arena->mpzTable()
                                                     : nullptr;
    v = lat_clamp(lat_kind, lat_has_floor, lat_floor, lat_has_ceil, lat_ceil,
                  v, mt);
    auto r = tree.insert2(k, v);
    if (r.second)
    {
      if (oldw) *oldw = 0;
      changed = true;
      return v;
    }
    if (oldw) *oldw = r.first->second;
    u64 n = (lat_kind == LAT_EXTERN)
          ? lat_arena->merge_spec(r.first->second, v, lat_spec_tree)
          : lat_join(lat_kind, r.first->second, v, mt);
    changed = (n != r.first->second);
    r.first->second = n;
    return n;
  }

  // T5 slice (d4): the SETTLE half of `merge` (t5-contract §0.3) -- would
  // this contribution move the payload? -- with no mutation of the map.  The
  // same clamp and the same join, but a LOOKUP where merge inserts: the
  // pre-commit gate previews, and the intern task still owns the apply.
  // (A LAT_EXTERN preview interns its merged collection in the arena exactly
  // as the apply would; that is a content-addressed value allocation, not a
  // relation change, and it is what makes the preview exact.)
  bool wouldChange(const Key& k, u64 v)
  {
    slog::InternTable<slog::mpz_val>* mt = lat_arena ? lat_arena->mpzTable()
                                                     : nullptr;
    v = lat_clamp(lat_kind, lat_has_floor, lat_floor, lat_has_ceil, lat_ceil,
                  v, mt);
    auto it = tree.lower_bound(k);
    if (it == tree.end() || !(it->first == k)) return true;  // a fresh key
    const u64 n = (lat_kind == LAT_EXTERN)
                ? lat_arena->merge_spec(it->second, v, lat_spec_tree)
                : lat_join(lat_kind, it->second, v, mt);
    return n != it->second;
  }

  // ---- cold path (virtual; used by the daemon) ----
  bool empty() const override { return tree.empty(); }
  u64 size() const override { return tree.size(); }   // = number of keys
  void clear() override { tree.clear(); }
  void forEach(const std::function<void(const u64*)>& f) const override
  {
    u64 row[KA + 1];
    for (auto it = tree.begin(); it != tree.end(); ++it)
    {
      for (u16 c = 0; c < KA; ++c)
        row[c] = it->first[c];
      row[KA] = it->second;
      f(row);
    }
  }
  void insertTuple(const u64* t, const u16* ord) override
  {
    Key k;
    for (u16 c = 0; c < KA; ++c)
      k[c] = t[ord[c]];
    bool changed = false;
    merge(k, t[ord[KA]], changed);
  }
  bool removeTuple(const u64* t, const u16* ord) override
  {
    Key k;
    for (u16 c = 0; c < KA; ++c) k[c] = t[ord[c]];
    if (tree.find(k) == tree.end()) return false;
    tree.erase(k);
    return true;
  }
  bool getPayload(const u64* key, u16 n, u64& value) const override
  {
    if (n != KA) return false;
    Key k;
    for (u16 c = 0; c < KA; ++c) k[c] = key[c];
    auto it = tree.find(k);
    if (it == tree.end()) return false;
    value = it->second;
    return true;
  }
  bool setPayload(const u64* key, u16 n, u64 value) override
  {
    if (n != KA) return false;
    Key k;
    for (u16 c = 0; c < KA; ++c) k[c] = key[c];
    auto r = tree.insert2(k, value);
    r.first->second = value;
    return true;
  }
};


// Runtime index construction for the daemon itself.  Generated code knows
// its arities statically and instantiates BTreeIndex<A> directly; the
// daemon (opening a stored database with no program loaded, say) does not,
// so it dispatches over a bounded set of pre-instantiated arities.
constexpr u16 max_daemon_arity = 64;

template <u16 A>
inline Index* makeIndexRec(u16 arity)
{
  if constexpr (A == 0)
  {
    (void)arity;
    return nullptr;
  }
  else
    return (arity == A) ? static_cast<Index*>(new BTreeIndex<A>())
                        : makeIndexRec<A - 1>(arity);
}

// Defined out-of-line in runtime.cpp (not inline here) so the full arity ladder
// is instantiated ONCE in the daemon binary rather than in every generated
// plugin .so.  Plugins reach it through the daemon's exported symbols (slogd is
// linked -rdynamic); generated code instantiates only the specific arities it
// uses via Relation::addIndex<A>.  Measured: this alone cut a median stratum's
// clang -O2 from ~10s to ~4.6s (docs/fast-compile.md §7.1).
Index* makeIndex(u16 arity);

// Runtime payload-map construction (lattice relations opened from disk with
// no program loaded): keyarity = storage arity - 1, plus the lattice
// metadata the merge needs.
template <u16 KA>
inline Index* makeMapIndexRec(u16 keyarity, u32 kind,
                              bool hf, u64 fw, bool hc, u64 cw,
                              const LatSpec* spec, CollectionArena* arena)
{
  if constexpr (KA == 0)
  {
    (void)keyarity;
    return nullptr;
  }
  else if (keyarity == KA)
  {
    auto* idx = new BTreeMapIndex<KA>();
    idx->lat_kind = kind;
    idx->lat_has_floor = hf;
    idx->lat_floor = fw;
    idx->lat_has_ceil = hc;
    idx->lat_ceil = cw;
    idx->lat_spec_tree = spec;
    idx->lat_arena = arena;
    return idx;
  }
  else
    return makeMapIndexRec<KA - 1>(keyarity, kind, hf, fw, hc, cw, spec, arena);
}

// Out-of-line in slogd.cpp (see makeIndex above): the payload-map arity ladder
// is instantiated once in the daemon, not in every plugin.
Index* makeMapIndex(u16 keyarity, u32 kind,
                    bool hf, u64 fw, bool hc, u64 cw,
                    const LatSpec* spec = nullptr,
                    CollectionArena* arena = nullptr);

}
