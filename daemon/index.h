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

#include <algorithm>
#include <array>
#include <vector>
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
  // Insert MANY storage-order tuples at once (the bulk form of insertTuple,
  // used by out-of-band ingestion): a set index sorts them and bulk-loads
  // an empty tree or inserts in key order; a payload map merges row by row.
  virtual void insertTuples(const std::vector<const u64*>& ts, const u16* ord)
  {
    for (const u64* t : ts) insertTuple(t, ord);
  }
  virtual bool removeTuple(const u64* t, const u16* ord) = 0;
  // Membership of a storage-order tuple (permuted by `ord`, as insertTuple).
  virtual bool containsTuple(const u64* t, const u16* ord) const = 0;
  // Payload-map cold path used by transactional count foundation seeding and
  // coverage audits.  Plain set indices return false/refuse; BTreeMapIndex
  // interprets `key` in its own (identity for count sidecars) key order.
  virtual bool getPayload(const u64*, u16, u64&) const { return false; }
  virtual bool setPayload(const u64*, u16, u64) { return false; }
  // Static (frozen) representation for indices that will only be READ for a
  // while: a set index copies its keys into one sorted contiguous array and
  // drops the tree, so probes are a binary search and range walks are
  // pointer bumps over packed keys.  Any mutation thaws it back into a tree.
  // Payload maps have no frozen form (no-op).
  virtual void freeze() {}
  virtual bool isFrozen() const { return false; }
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

  // Two representations behind one interface.  Normally the keys live in the
  // tree.  A FROZEN index (Index::freeze, applied to the indices a stratum
  // only reads -- inputs and earlier strata's outputs) holds the same keys
  // in `flat`, one sorted contiguous array, and the tree is empty: probes
  // are a binary search, range walks are pointer bumps over packed 16-byte
  // keys with no node overhead, and the index is ~30% smaller.  Any mutating
  // entry point thaws first (one bulk load back into the tree), so callers
  // never see the distinction.
  Tree tree;
  std::vector<Key> flat;
  bool frozen = false;
  // Directory over `flat` (frozen only, A >= 2): the bucket's distinct lead-
  // column values in order and, for each, where its group of keys starts
  // (`off` has one extra entry = flat.size()).  A probe binary-searches the
  // directory -- a few thousand values that stay in cache -- and then only
  // the matching group, instead of the whole array: the array of a large
  // relation does not fit in cache and a plain binary search over it misses
  // on most of its steps, which is why a flat array alone probed no faster
  // than the tree.
  std::vector<u64> lead;
  std::vector<u32> off;

  // Iterator over either representation.  Every consumer uses only
  // lower_bound/begin/end, !=, ++ and *, so a mode flag checked per step
  // (perfectly predictable inside one probe) is all it costs.
  class iterator
  {
    typename Tree::iterator it;
    const Key* p = nullptr;
    bool is_flat = false;
  public:
    iterator() = default;
    explicit iterator(typename Tree::iterator i) : it(i) {}
    explicit iterator(const Key* q) : p(q), is_flat(true) {}
    const Key& operator*() const { return is_flat ? *p : *it; }
    const Key* operator->() const { return is_flat ? p : &*it; }
    iterator& operator++() { if (is_flat) ++p; else ++it; return *this; }
    iterator operator++(int) { iterator copy = *this; ++*this; return copy; }
    bool operator==(const iterator& o) const { return is_flat ? p == o.p : it == o.it; }
    bool operator!=(const iterator& o) const { return !(*this == o); }
    const Key* flatPos() const { return is_flat ? p : nullptr; }
  };

  void thaw()
  {
    if (!frozen) return;
    tree.bulk_load(flat.begin(), flat.end());
    std::vector<Key>().swap(flat);
    std::vector<u64>().swap(lead);
    std::vector<u32>().swap(off);
    frozen = false;
  }
  // Freeze only when the frozen form's two searches stay cache-resident.  A
  // probe is a binary search over the bucket's DIRECTORY (its distinct lead
  // values) and then over one lead GROUP; both must be small.  A directory
  // of a few hundred leads (a random graph with a few thousand nodes) is
  // one or two KB and beats the tree descent by 1.2-1.3x on the join-shaped
  // workloads, but a directory of 80K leads (a 5M-edge input over 2.5M
  // nodes) is a 640 KB binary search whose deeper steps all miss, where the
  // tree's shared upper levels stay hot: measured 0.75x.  Likewise a group
  // of thousands of keys.  Such buckets stay trees.  SLOG_STATIC_MAX_LEADS
  // (per bucket, default 8192) and SLOG_STATIC_MAX_GROUP (keys per lead,
  // default 256) override the bounds (measurement).
  static u64 maxLeads()
  {
    static const u64 v = [] { const char* e = std::getenv("SLOG_STATIC_MAX_LEADS");
                              return e ? (u64)std::strtoull(e, nullptr, 10) : (u64)8192; }();
    return v;
  }
  static u64 maxGroupKeys()
  {
    static const u64 v = [] { const char* e = std::getenv("SLOG_STATIC_MAX_GROUP");
                              return e ? (u64)std::strtoull(e, nullptr, 10) : (u64)256; }();
    return v;
  }
  void freeze() override
  {
    if (frozen || tree.empty()) return;
    if constexpr (A >= 2)
    {
      u64 leads = 0; bool first = true; u64 prev = 0;
      for (const Key& k : tree)
      {
        if (first || k[0] != prev) { ++leads; prev = k[0]; first = false; }
      }
      if (leads == 0 || leads > maxLeads() || tree.size() / leads > maxGroupKeys()) return;
    }
    else if (tree.size() > maxLeads()) return;
    flat.assign(tree.begin(), tree.end());
    tree.clear();
    if constexpr (A >= 2)
    {
      lead.clear(); off.clear();
      for (size_t i = 0; i < flat.size(); ++i)
        if (i == 0 || flat[i][0] != flat[i - 1][0]) { lead.push_back(flat[i][0]); off.push_back((u32)i); }
      off.push_back((u32)flat.size());
    }
    frozen = true;
  }
  // Frozen lower_bound: directory first, then the lead value's group.
  const Key* flatLowerBound(const Key& k) const
  {
    if constexpr (A >= 2)
    {
      const auto li = std::lower_bound(lead.begin(), lead.end(), k[0]);
      if (li == lead.end()) return flat.data() + flat.size();
      const size_t g = li - lead.begin();
      const Key* lo = flat.data() + off[g];
      if (*li != k[0]) return lo;                       // k[0] absent: first key of the next group
      return std::lower_bound(lo, flat.data() + off[g + 1], k);
    }
    else
      return std::lower_bound(flat.data(), flat.data() + flat.size(), k);
  }
  bool isFrozen() const override { return frozen; }

  // ---- hot path (typed; called from generated code) ----
  void insert(const Key& k) { thaw(); tree.insert(k); }
  // Insert and report whether the key was new: dedup and insert in ONE
  // descent (the intern phase's per-candidate operation).
  bool insertNew(const Key& k) { thaw(); return tree.insert(k).second; }
  // Build an EMPTY tree bottom-up from a sorted, duplicate-free range: leaves
  // are filled sequentially and the inner levels constructed above them, so
  // a fresh index costs one sort plus a linear pass instead of one random
  // descent per row.  (A populated index takes the keys one by one.)
  template <class It> void bulkLoad(It first, It last)
  {
    thaw();
    if (tree.empty()) tree.bulk_load(first, last);
    else for (It i = first; i != last; ++i) tree.insert(*i);
  }
  bool contains(const Key& k) const
  {
    if (!frozen) return tree.exists(k);
    const Key* p = flatLowerBound(k);
    return p != flat.data() + flat.size() && *p == k;
  }
  iterator lower_bound(const Key& k)
  {
    if (frozen) return iterator(flatLowerBound(k));
    return iterator(tree.lower_bound(k));
  }
  // lower_bound(k) for a k known to lie at or after `hint` (a cursor seeking
  // forward).  Frozen: gallop from the hint -- doubling strides, then a
  // binary search inside the bracket -- so a short hop costs a few
  // comparisons on the keys already in cache instead of a full descent.
  // Tree: a plain lower_bound.
  iterator lower_bound_from(const iterator& hint, const Key& k)
  {
    if (!frozen || !hint.flatPos()) return lower_bound(k);
    const Key* p = hint.flatPos();
    const Key* e = flat.data() + flat.size();
    if (p == e || !(*p < k)) return iterator(p);
    if constexpr (A >= 2)
    {
      // A prefix cursor seeks inside one lead-column group; bound the gallop
      // by that group's end (a seek past it lands on the next group's first
      // key, which is >= k) and take the directory path when the hint sits
      // in another group -- galloping across a large array would miss on
      // every doubling step, costing more than the tree descent it replaces.
      if ((*p)[0] != k[0]) return iterator(flatLowerBound(k));
      const size_t g = std::lower_bound(lead.begin(), lead.end(), k[0]) - lead.begin();
      e = flat.data() + off[g + 1];
      if (p >= e) return iterator(e);
    }
    size_t step = 1;
    const Key* lo = p;
    const Key* hi = p + 1;
    while (hi < e && *hi < k) { lo = hi; step <<= 1; hi = (size_t)(e - hi) > step ? hi + step : e; }
    return iterator(std::lower_bound(lo, hi, k));
  }
  iterator begin() { return frozen ? iterator(flat.data()) : iterator(tree.begin()); }
  iterator end() { return frozen ? iterator(flat.data() + flat.size()) : iterator(tree.end()); }

  // ---- cold path (virtual; used by the daemon) ----
  bool empty() const override { return frozen ? flat.empty() : tree.empty(); }
  u64 size() const override { return frozen ? flat.size() : tree.size(); }
  void clear() override
  {
    tree.clear(); std::vector<Key>().swap(flat);
    std::vector<u64>().swap(lead); std::vector<u32>().swap(off);
    frozen = false;
  }
  void forEach(const std::function<void(const u64*)>& f) const override
  {
    if (frozen) { for (const Key& k : flat) f(k.data()); return; }
    for (const Key& k : tree) f(k.data());
  }
  void insertTuple(const u64* t, const u16* ord) override
  {
    Key k;
    for (u16 c = 0; c < A; ++c)
      k[c] = t[ord[c]];
    thaw();
    tree.insert(k);
  }
  bool containsTuple(const u64* t, const u16* ord) const override
  {
    Key k;
    for (u16 c = 0; c < A; ++c)
      k[c] = t[ord[c]];
    return contains(k);
  }
  void insertTuples(const std::vector<const u64*>& ts, const u16* ord) override
  {
    thaw();
    std::vector<Key> keys;
    keys.reserve(ts.size());
    for (const u64* t : ts)
    {
      Key k;
      for (u16 c = 0; c < A; ++c) k[c] = t[ord[c]];
      keys.push_back(k);
    }
    std::sort(keys.begin(), keys.end());
    keys.erase(std::unique(keys.begin(), keys.end()), keys.end());
    if (tree.empty()) tree.bulk_load(keys.begin(), keys.end());
    else for (const Key& k : keys) tree.insert(k);
  }
  bool removeTuple(const u64* t, const u16* ord) override
  {
    thaw();
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
  bool containsTuple(const u64* t, const u16* ord) const override
  {
    Key k;
    for (u16 c = 0; c < KA; ++c) k[c] = t[ord[c]];
    return tree.exists(k);
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
