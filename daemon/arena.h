/** Slog Collection Arena
 *
 * A content-addressed, lock-free node store for canonical collection values
 * (finite maps/sets; docs/primitives.md M2.1).  Collections are big-endian
 * Patricia tries (Okasaki-Gill, "Fast Mergeable Integer Maps") over the full
 * 64-bit NaN-boxed key word; a set is a map-to-unit (value s32 1).  Nodes are
 * hash-consed in an InternTable<cnode> -- the same lock-free CAS structure
 * that interns strings -- so equal collections are one interned id, interning
 * is re-entrant from any thread in any phase, and reloading node contents in
 * partition-iterator order reproduces ids exactly (the value.strings
 * argument: an id is a pure function of content hash + collision-chain
 * position, and a chain lives wholly inside one partition file).
 *
 * A collection value in a tuple is the intern word of its root node
 * (intern_encode(cnode_intern_tag, id)); the empty map is the interned
 * all-zero node, so emptiness is one word comparison.  Because tries are
 * canonical by construction (shape is a function of the key set alone) and
 * interning dedups by content, equal subtrees are ALWAYS the same word --
 * the kernels lean on this for physical-equality short-circuits, and it is
 * what makes raw-word equality (joins, dedup, flat-lattice payloads) correct
 * on collection values.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once

#include "types.h"
#include "utf8string.h"
#include "intern.h"
#include <bit>
#include <atomic>


namespace slog
{


// One arena node: 4 raw words.
//   branch: {prefix, mask, left-word, right-word}   mask = the branching bit
//           (a single set bit); prefix = the keys' shared bits strictly above
//           mask (mask and below cleared); left holds keys with the mask bit 0.
//   leaf:   {key, 0, val, 1}
//   empty:  {0, 0, 0, 0}
// Children are full cnode-tagged intern words (internflags set), never 0 or 1,
// so w[1]!=0 identifies a branch and w[3] splits leaf (1) from empty (0) for
// every possible key/val bit pattern (including float 0.0 keys).
class cnode
{
public:
  u64 w[4];

  bool operator==(const cnode& other) const
  {
    return w[0] == other.w[0] && w[1] == other.w[1]
        && w[2] == other.w[2] && w[3] == other.w[3];
  }
};

template <>
u32 fasthash<cnode>(const cnode& n)
{
  // FNV-1a over the 32 raw bytes (the scheme fasthash<utf8string> uses)
  u32 hash = 2166136261u;
  const u8* bytes = (const u8*)n.w;
  for (u32 i = 0; i < 32; ++i)
  {
    hash ^= bytes[i];
    hash *= 16777619u;
  }
  return hash;
}


class CollectionArena
{
private:
  InternTable<cnode>* table;
  std::atomic<u64> empty_cache;   // the interned {0,0,0,0} word (0 = not yet)
  std::atomic<u64> fresh_count;   // nodes actually inserted (not dup hits)

  // ---- bit helpers (big-endian Patricia over unsigned 64-bit words) ----
  static u64 mask_up(u64 k, u64 m) { return k & ~(m | (m - 1)); }
  static bool zero_bit(u64 k, u64 m) { return (k & m) == 0; }
  static u64 branch_bit(u64 p0, u64 p1)  // highest differing bit; p0 != p1
  { return ((u64)1) << (63 - std::countl_zero(p0 ^ p1)); }

public:
  CollectionArena()
    : empty_cache(0), fresh_count(0)
  {
    table = new InternTable<cnode>();
  }

  ~CollectionArena()
  {
    delete table;
  }

  // The underlying interner, for persistence staging (iteration only).
  InternTable<cnode>* raw() { return table; }

  u64 freshCount() { return fresh_count.load(); }

  // Intern a node's 4 words; returns the cnode-tagged intern word.  Content
  // dedup means equal nodes always yield one id; the candidate is freed on a
  // duplicate hit (the table owns the stored copy).
  u64 intern4(u64 a, u64 b, u64 c, u64 d)
  {
    cnode* n = new cnode{{a, b, c, d}};
    const u64 id = table->intern_value(n);
    if (id >> 35)
      fatal("Collection arena: intern id overflows the 35-bit budget "
            "(collision chain too long)");
    if (table->lookup_value(id) != n)
      delete n;  // duplicate content: an equal node already owns this id
    else
      fresh_count++;
    return intern_encode(cnode_intern_tag, id);
  }

  // Resolve a cnode word to its node (fatal on a dangling id -- only
  // possible via a corrupt on-disk arena).
  const cnode* node(u64 word)
  {
    const cnode* n = table->lookup_value(decode_val(word));
    if (n == 0)
      fatal("Collection arena: dangling collection-node id");
    return n;
  }

  // The canonical empty collection (interned once; races are benign since
  // content-addressing makes every contender produce the same word).
  u64 empty()
  {
    u64 e = empty_cache.load(std::memory_order_relaxed);
    if (e) return e;
    e = intern4(0, 0, 0, 0);
    empty_cache.store(e, std::memory_order_relaxed);
    return e;
  }

private:
  u64 make_leaf(u64 k, u64 v) { return intern4(k, 0, v, 1); }

  // Combine two tries whose prefixes p0/p1 disagree: branch on the highest
  // differing bit, zero side left.
  u64 join(u64 p0, u64 t0, u64 p1, u64 t1)
  {
    const u64 m = branch_bit(p0, p1);
    const u64 p = mask_up(p0, m);
    return zero_bit(p0, m) ? intern4(p, m, t0, t1) : intern4(p, m, t1, t0);
  }

  // Rebuild a branch whose children may have emptied (delete/difference);
  // collapsing the empty side keeps the trie canonical.
  u64 smart_branch(u64 p, u64 m, u64 l, u64 r)
  {
    const u64 e = empty();
    if (l == e) return r;
    if (r == e) return l;
    return intern4(p, m, l, r);
  }

  u64 put_impl(u64 t, u64 k, u64 v, bool replace)
  {
    if (t == empty()) return make_leaf(k, v);
    const cnode* n = node(t);
    if (n->w[1] == 0)  // leaf {j, 0, w, 1}
    {
      const u64 j = n->w[0];
      if (j == k)
      {
        if (!replace || n->w[2] == v) return t;
        return make_leaf(k, v);
      }
      return join(k, make_leaf(k, v), j, t);
    }
    const u64 p = n->w[0], m = n->w[1], l = n->w[2], r = n->w[3];
    if (mask_up(k, m) != p)
      return join(k, make_leaf(k, v), p, t);
    if (zero_bit(k, m))
    {
      const u64 l2 = put_impl(l, k, v, replace);
      return (l2 == l) ? t : intern4(p, m, l2, r);
    }
    else
    {
      const u64 r2 = put_impl(r, k, v, replace);
      return (r2 == r) ? t : intern4(p, m, l, r2);
    }
  }

public:
  // Insert/replace and insert-if-absent.
  u64 put(u64 t, u64 k, u64 v)      { return put_impl(t, k, v, true); }
  u64 put_soft(u64 t, u64 k, u64 v) { return put_impl(t, k, v, false); }

  // Point lookup: true iff k is present (writing the value through out).
  bool find(u64 t, u64 k, u64* out)
  {
    if (t == empty()) return false;
    const cnode* n = node(t);
    while (n->w[1] != 0)
    {
      const u64 p = n->w[0], m = n->w[1];
      if (mask_up(k, m) != p) return false;
      n = node(zero_bit(k, m) ? n->w[2] : n->w[3]);
    }
    if (n->w[0] == k)
    {
      if (out) *out = n->w[2];
      return true;
    }
    return false;
  }

  // Left-biased union: on key collision the LEFT argument's value wins
  // (mirrors lib/map.slog mp_union).  Physical-equality short-circuits
  // return shared subtrees untouched, so merging near-equal tries is
  // near-O(difference).
  u64 merge(u64 a, u64 b)
  {
    const u64 e = empty();
    if (a == b || b == e) return a;
    if (a == e) return b;
    const cnode* na = node(a);
    const cnode* nb = node(b);
    if (na->w[1] == 0) return put(b, na->w[0], na->w[2]);       // a's value wins
    if (nb->w[1] == 0) return put_soft(a, nb->w[0], nb->w[2]);  // keep a's value
    const u64 p = na->w[0], m = na->w[1], l = na->w[2], r = na->w[3];
    const u64 q = nb->w[0], n = nb->w[1], u = nb->w[2], w = nb->w[3];
    if (m == n && p == q)
    {
      const u64 l2 = merge(l, u), r2 = merge(r, w);
      if (l2 == l && r2 == r) return a;
      if (l2 == u && r2 == w) return b;
      return intern4(p, m, l2, r2);
    }
    if (m > n)
    {
      if (mask_up(q, m) != p) return join(p, a, q, b);
      if (zero_bit(q, m))
      {
        const u64 l2 = merge(l, b);
        return (l2 == l) ? a : intern4(p, m, l2, r);
      }
      const u64 r2 = merge(r, b);
      return (r2 == r) ? a : intern4(p, m, l, r2);
    }
    if (m < n)
    {
      if (mask_up(p, n) != q) return join(p, a, q, b);
      if (zero_bit(p, n))
      {
        const u64 u2 = merge(a, u);
        return (u2 == u) ? b : intern4(q, n, u2, w);
      }
      const u64 w2 = merge(a, w);
      return (w2 == w) ? b : intern4(q, n, u, w2);
    }
    return join(p, a, q, b);  // m == n, p != q: disjoint ranges
  }

  // Delete a key, collapsing single-child branches (keeps canonicity).
  u64 del(u64 t, u64 k)
  {
    const u64 e = empty();
    if (t == e) return t;
    const cnode* n = node(t);
    if (n->w[1] == 0) return (n->w[0] == k) ? e : t;
    const u64 p = n->w[0], m = n->w[1], l = n->w[2], r = n->w[3];
    if (mask_up(k, m) != p) return t;
    if (zero_bit(k, m))
    {
      const u64 l2 = del(l, k);
      return (l2 == l) ? t : smart_branch(p, m, l2, r);
    }
    const u64 r2 = del(r, k);
    return (r2 == r) ? t : smart_branch(p, m, l, r2);
  }

  // Difference: the entries of a whose keys are NOT in b (values from a).
  u64 diff(u64 a, u64 b)
  {
    const u64 e = empty();
    if (a == e || a == b) return e;
    if (b == e) return a;
    const cnode* na = node(a);
    const cnode* nb = node(b);
    if (na->w[1] == 0) return find(b, na->w[0], 0) ? e : a;
    if (nb->w[1] == 0) return del(a, nb->w[0]);
    const u64 p = na->w[0], m = na->w[1], l = na->w[2], r = na->w[3];
    const u64 q = nb->w[0], n = nb->w[1], u = nb->w[2], w = nb->w[3];
    if (m == n)
    {
      if (p != q) return a;  // disjoint ranges
      const u64 l2 = diff(l, u), r2 = diff(r, w);
      if (l2 == l && r2 == r) return a;
      return smart_branch(p, m, l2, r2);
    }
    if (m > n)
    {
      if (mask_up(q, m) != p) return a;
      if (zero_bit(q, m))
      {
        const u64 l2 = diff(l, b);
        return (l2 == l) ? a : smart_branch(p, m, l2, r);
      }
      const u64 r2 = diff(r, b);
      return (r2 == r) ? a : smart_branch(p, m, l, r2);
    }
    // m < n: only b's side covering a's range can hit
    if (mask_up(p, n) != q) return a;
    return zero_bit(p, n) ? diff(a, u) : diff(a, w);
  }

  // Number of entries.
  u64 size(u64 t)
  {
    if (t == empty()) return 0;
    const cnode* n = node(t);
    if (n->w[1] == 0) return 1;
    return size(n->w[2]) + size(n->w[3]);
  }

  // In-order (ascending unsigned key) visit of every entry: f(key, val).
  template <typename F>
  void foreach(u64 t, F f)
  {
    if (t == empty()) return;
    const cnode* n = node(t);
    if (n->w[1] == 0)
    {
      f(n->w[0], n->w[2]);
      return;
    }
    foreach(n->w[2], f);
    foreach(n->w[3], f);
  }
};


} // namespace slog
