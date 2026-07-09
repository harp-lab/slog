/** Slog Sequence Arena
 *
 * A content-addressed, lock-free node store for canonical sequence values
 * ([T] lists now, rope strings in S2; docs/sequences.md).  A sequence is a
 * content-defined-chunked Merkle tree ("prolly tree" / hash-splitting rope):
 * leaves hold runs of element words, the stream of leaf ids is chunked again
 * into branch nodes, recursively, until one node remains -- the root.  Chunk
 * boundaries are decided by a rolling gear hash over a bounded window of the
 * entry stream (daemon/seqparams.h), so the node DAG is a deterministic
 * function of content alone: equal content interns to ONE root id regardless
 * of build path, which is what makes raw-word equality/joins/keys value
 * semantics for sequences (the same canonicity gate Patricia tries pass for
 * sets/maps, docs/primitives.md §2).
 *
 * Nodes are hash-consed in an InternTable<seqnode> -- the same lock-free CAS
 * structure that interns strings and cnodes -- so interning is re-entrant
 * from any thread in any phase, and reloading node records in
 * partition-iterator order reproduces ids exactly (child references are full
 * tagged intern words, so records hash without dereferencing; the cnode
 * argument extended inductively to trees).
 *
 * Edits (set/ins/del/cat/slice) rechunk only a bounded window around the
 * change per level: because a word's influence leaves the rolling hash after
 * SEQ_HASH_WINDOW steps, recomputed boundaries RESYNCHRONIZE with the old
 * ones, and the rebuild core splices the untouched old subtrees back in --
 * expected O(log n) fresh nodes per edit.  Degenerate content (forced-max
 * runs with no natural boundaries) may never resync; the rebuild then feeds
 * to the end of the stream, and hash-consing turns the pathology into probe
 * work, not memory (docs/sequences.md §1.5).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once

#include "types.h"
#include "utf8string.h"
#include "intern.h"
#include "seqparams.h"
#include <atomic>
#include <cstring>
#include <vector>
#include <algorithm>


namespace slog
{


// Node kinds (also the on-disk record kind byte, docs/sequences.md §8.1).
#define SEQ_LEAF_WORDS   ((u8)0)
#define SEQ_LEAF_BYTES   ((u8)1)   // rope-string leaves (S2)
#define SEQ_BRANCH       ((u8)2)   // word-tree branch: (child, count) pairs
#define SEQ_BRANCH_BYTES ((u8)3)   // byte-tree branch: (child, bytes, cps)

#define SEQ_NPOS (~(u64)0)

// UTF-8: a byte starts a codepoint unless it is a continuation (10xxxxxx).
#define SEQ_CP_START(b) (((b) & 0xC0) != 0x80)


// One arena node.  Payload layout by kind:
//   leaf-words:   n element words (full NaN-boxed u64s -- struct ids, string
//                 ids, floats, nested collection/sequence words are all legal)
//   leaf-bytes:   ceil(n/8) words of packed bytes (byte i in word i>>3, lane
//                 i&7; zero-padded) + 1 word holding the codepoint count
//   branch:       n (child-id word, subtree element count) pairs
//   branch-bytes: n (child-id word, subtree BYTE count, subtree CODEPOINT
//                 count) triples
// Per-child counts, not cumulative; children are full tagged intern words.
// `total` (primary units: elements for word trees, BYTES for byte trees --
// the unit the level-0 stream is chunked in) and `total2` (codepoints; 0
// for word trees) are DERIVED and excluded from equality and hashing:
// identity is (kind, n, payload) alone, the on-disk record content.
class seqnode
{
public:
  u8 kind;
  u16 n;
  u64 total;
  u64 total2;
  u64* w;

  static u32 payload_words(u8 k, u16 nn)
  {
    switch (k)
    {
    case SEQ_LEAF_WORDS:   return nn;
    case SEQ_LEAF_BYTES:   return (u32)((nn + 7) / 8) + 1;
    case SEQ_BRANCH_BYTES: return (u32)3 * nn;
    default:               return (u32)2 * nn;
    }
  }

  seqnode(u8 k, u16 nn, const u64* payload)
    : kind(k), n(nn), total(0), total2(0), w(0)
  {
    const u32 m = payload_words(k, nn);
    w = new u64[m];
    if (m) std::memcpy(w, payload, m * sizeof(u64));
    switch (k)
    {
    case SEQ_LEAF_WORDS:
      total = nn;
      break;
    case SEQ_LEAF_BYTES:
      total = nn;                     // bytes
      total2 = m ? w[m - 1] : 0;      // codepoints
      break;
    case SEQ_BRANCH_BYTES:
      for (u16 i = 0; i < nn; ++i)
      {
        total += w[3 * i + 1];
        total2 += w[3 * i + 2];
      }
      break;
    default:
      for (u16 i = 0; i < nn; ++i)
        total += w[2 * i + 1];
    }
  }

  ~seqnode() { delete[] w; }

  seqnode(const seqnode&) = delete;
  seqnode& operator=(const seqnode&) = delete;

  bool branch() const
  {
    return kind == SEQ_BRANCH || kind == SEQ_BRANCH_BYTES;
  }

  // branches only: the i'th child word / its primary-unit subtree count
  u64 child(u16 i) const
  {
    return kind == SEQ_BRANCH ? w[2 * i] : w[3 * i];
  }
  u64 child_primary(u16 i) const
  {
    return kind == SEQ_BRANCH ? w[2 * i + 1] : w[3 * i + 1];
  }

  // leaf-bytes only: the i'th payload byte
  u8 byte_at(u16 i) const
  {
    return (u8)(w[i >> 3] >> (8 * (i & 7)));
  }

  bool operator==(const seqnode& other) const
  {
    if (kind != other.kind || n != other.n) return false;
    const u32 m = payload_words(kind, n);
    return m == 0 || 0 == std::memcmp(w, other.w, m * sizeof(u64));
  }
};

template <>
inline u32 fasthash<seqnode>(const seqnode& nd)
{
  // FNV-1a over the record bytes: kind, count (LE), payload words (the cnode
  // scheme, arena.h) -- a pure function of record content, so reload-in-order
  // reproduces ids.
  u32 hash = 2166136261u;
  hash ^= nd.kind;             hash *= 16777619u;
  hash ^= (u8)(nd.n & 0xff);   hash *= 16777619u;
  hash ^= (u8)(nd.n >> 8);     hash *= 16777619u;
  const u32 m = seqnode::payload_words(nd.kind, nd.n);
  const u8* bytes = (const u8*)nd.w;
  for (u32 i = 0; i < m * 8; ++i)
  {
    hash ^= bytes[i];
    hash *= 16777619u;
  }
  return hash;
}


class SequenceArena
{
private:
  InternTable<seqnode>* table;
  std::atomic<u64> empty_cache;   // the interned zero-length leaf (0 = not yet)
  std::atomic<u64> fresh_count;   // nodes actually inserted (not dup hits)

  // One entry of some level's stream.  `w` is what the gear hash sees and
  // what a chunk stores (an element word / a byte value / a child id);
  // `cnt` is the entry's PRIMARY-unit weight (elements for word trees,
  // bytes for byte trees -- always 1 at level 0); `cnt2` is its codepoint
  // weight (byte trees only: 1 on a codepoint-start byte, else 0).
  struct Entry { u64 w; u64 cnt; u64 cnt2; };

  // A root-to-target path indexed by LEVEL: path[0] = (leaf word, element
  // offset), path[L] = (level-L node word, index of the on-path child).
  // Leaves are level 0; the tree is uniform-depth by construction.
  typedef std::vector<std::pair<u64,u32>> Path;

public:
  SequenceArena()
    : empty_cache(0), fresh_count(0)
  {
    table = new InternTable<seqnode>();
  }

  ~SequenceArena()
  {
    delete table;
  }

  // The underlying interner, for persistence staging (iteration only).
  InternTable<seqnode>* raw() { return table; }

  u64 freshCount() { return fresh_count.load(); }

  // Intern a node record; returns the seq-tagged intern word.  Content dedup
  // means equal records always yield one id; the candidate is freed on a
  // duplicate hit (the table owns the stored copy).
  u64 intern_node(seqnode* nd)
  {
    const u64 id = table->intern_value(nd);
    if (id >> 35)
      fatal("Sequence arena: intern id overflows the 35-bit budget "
            "(collision chain too long)");
    if (table->lookup_value(id) != nd)
      delete nd;  // duplicate content: an equal node already owns this id
    else
      fresh_count++;
    return intern_encode(seq_intern_tag, id);
  }

  // Resolve a seq word to its node (fatal on a dangling id -- only possible
  // via a corrupt on-disk arena).
  const seqnode* node(u64 word)
  {
    const seqnode* nd = table->lookup_value(decode_val(word));
    if (nd == 0)
      fatal("Sequence arena: dangling sequence-node id");
    return nd;
  }

  // The canonical empty sequence: one distinguished zero-length leaf (races
  // are benign; content-addressing makes every contender produce one word).
  u64 empty()
  {
    u64 e = empty_cache.load(std::memory_order_relaxed);
    if (e) return e;
    e = intern_node(new seqnode(SEQ_LEAF_WORDS, 0, 0));
    empty_cache.store(e, std::memory_order_relaxed);
    return e;
  }

  // Element count: O(1) from the root record.
  u64 len(u64 t) { return node(t)->total; }

private:
  static Entry entry_of(const seqnode* nd, u32 i)
  {
    switch (nd->kind)
    {
    case SEQ_LEAF_WORDS:
      return {nd->w[i], 1, 0};
    case SEQ_LEAF_BYTES:
    {
      const u8 b = nd->byte_at((u16)i);
      return {b, 1, SEQ_CP_START(b) ? (u64)1 : 0};
    }
    case SEQ_BRANCH:
      return {nd->w[2 * i], nd->w[2 * i + 1], 0};
    default:   // SEQ_BRANCH_BYTES
      return {nd->w[3 * i], nd->w[3 * i + 1], nd->w[3 * i + 2]};
    }
  }

  // Intern a run of entries as one node at the given level/mode.
  Entry intern_entries(u32 lvl, bool bmode, const std::vector<Entry>& es)
  {
    if (lvl == 0 && bmode)
    {
      // byte leaf: pack bytes (byte i -> word i>>3, lane i&7) + cp count
      if (es.size() > SEQ_BLEAF_MAX + 3)
        fatal("Sequence arena: byte chunk exceeds the leaf bound");
      const u16 n = (u16)es.size();
      const u32 m = seqnode::payload_words(SEQ_LEAF_BYTES, n);
      u64 tmp[64] = {0};
      u64 cps = 0;
      for (u32 i = 0; i < n; ++i)
      {
        tmp[i >> 3] |= (es[i].w & 0xff) << (8 * (i & 7));
        cps += es[i].cnt2;
      }
      tmp[m - 1] = cps;
      return {intern_node(new seqnode(SEQ_LEAF_BYTES, n, tmp)), n, cps};
    }
    if (es.size() > 64)
      fatal("Sequence arena: chunk exceeds the 64-entry node bound");
    u64 tmp[192];
    if (lvl == 0)
    {
      for (u32 i = 0; i < es.size(); ++i) tmp[i] = es[i].w;
      return {intern_node(new seqnode(SEQ_LEAF_WORDS, (u16)es.size(), tmp)),
              (u64)es.size(), 0};
    }
    u64 cnt = 0, cnt2 = 0;
    if (!bmode)
    {
      for (u32 i = 0; i < es.size(); ++i)
      {
        tmp[2 * i] = es[i].w;
        tmp[2 * i + 1] = es[i].cnt;
        cnt += es[i].cnt;
      }
      return {intern_node(new seqnode(SEQ_BRANCH, (u16)es.size(), tmp)),
              cnt, 0};
    }
    for (u32 i = 0; i < es.size(); ++i)
    {
      tmp[3 * i] = es[i].w;
      tmp[3 * i + 1] = es[i].cnt;
      tmp[3 * i + 2] = es[i].cnt2;
      cnt += es[i].cnt;
      cnt2 += es[i].cnt2;
    }
    return {intern_node(new seqnode(SEQ_BRANCH_BYTES, (u16)es.size(), tmp)),
            cnt, cnt2};
  }

  // The content-defined chunker for one level's entry stream (seqparams.h).
  // h rolls continuously over the stream (NEVER reset at boundaries -- the
  // bounded window is what makes boundaries resynchronize after an edit);
  // run counts entries since the last boundary for the min/max bounds.
  // prime() replays pre-stream context into h without emitting.
  //
  // Byte-leaf mode (bmode && level 0) defers a fired boundary until the
  // next codepoint-START byte arrives ("snap forward", docs/sequences.md
  // §1.2) so a leaf never splits a codepoint; the deferral is capped at 3
  // extra bytes (the longest legal continuation run -- invalid UTF-8 cuts
  // anyway, deterministically).  A pending cut is resolved by the NEXT
  // byte, so the seam-resynchronization test is "is the buffer empty here"
  // (at_boundary), with feed_right peeking one byte across node seams to
  // resolve a pending cut exactly as the byte's own push would.
  struct Chunker
  {
    SequenceArena* ar;
    u32 lvl;
    bool bmode;
    u64 mask;
    u32 minn, maxn;
    u64 h;
    u32 run;
    bool pending;
    u32 pend_extra;
    std::vector<Entry> buf;
    std::vector<Entry> out;

    Chunker(SequenceArena* a, u32 level, bool bytes)
      : ar(a), lvl(level), bmode(bytes),
        mask(level > 0 ? SEQ_BRANCH_MASK : (bytes ? SEQ_BLEAF_MASK
                                                  : SEQ_WLEAF_MASK)),
        minn(level > 0 ? SEQ_BRANCH_MIN : (bytes ? SEQ_BLEAF_MIN
                                                 : SEQ_WLEAF_MIN)),
        maxn(level > 0 ? SEQ_BRANCH_MAX : (bytes ? SEQ_BLEAF_MAX
                                                 : SEQ_WLEAF_MAX)),
        h(0), run(0), pending(false), pend_extra(0)
    {}

    bool byteleaf() const { return bmode && lvl == 0; }

    void prime(u64 w) { h = (h << 1) + seq_gear(w); }

    void emit()
    {
      out.push_back(ar->intern_entries(lvl, bmode, buf));
      buf.clear();
      run = 0;
    }

    // Resolve a deferred byte-leaf cut against the next incoming byte:
    // cut when it starts a codepoint (or the snap cap trips).
    void resolve_pending(u64 nextb)
    {
      if (!pending) return;
      if (SEQ_CP_START(nextb) || pend_extra >= 3)
      {
        emit();
        pending = false;
        pend_extra = 0;
      }
    }

    void push(Entry e)
    {
      if (byteleaf()) resolve_pending(e.w);
      buf.push_back(e);
      h = (h << 1) + seq_gear(e.w);
      ++run;
      if (pending)
      {
        ++pend_extra;
        return;
      }
      if (run >= maxn || (run >= minn && (h & mask) == 0))
      {
        if (byteleaf())
        {
          pending = true;
          pend_extra = 0;
        }
        else
          emit();
      }
    }

    // A cut sits exactly at the current position (nothing buffered since).
    bool at_boundary() const { return buf.empty(); }

    void flush()
    {
      if (!buf.empty()) emit();
      pending = false;
      pend_extra = 0;
    }
  };

  // Path to PRIMARY-unit position pos in [0, total(t)] (elements for word
  // trees, bytes for byte trees); an end cut clamps into the rightmost
  // spine (leaf offset == leaf->n).
  Path path_to(u64 t, u64 pos)
  {
    std::vector<std::pair<u64,u32>> down;
    u64 cur = t;
    while (true)
    {
      const seqnode* nd = node(cur);
      if (!nd->branch())
      {
        down.push_back({cur, (u32)pos});
        break;
      }
      u32 i = 0;
      for (; i + 1 < nd->n; ++i)
      {
        const u64 c = nd->child_primary(i);
        if (pos < c) break;
        pos -= c;
      }
      down.push_back({cur, i});
      cur = nd->child(i);
    }
    std::reverse(down.begin(), down.end());
    return down;   // level-indexed: [0] = leaf
  }

  // Gather (reverse stream order) the last ≤need level-`lvl` entries of the
  // subtree rooted at t (a node at level tlvl ≥ lvl).
  void tail_entries_rev(u64 t, u32 tlvl, u32 lvl, u32 need,
                        std::vector<Entry>& rev)
  {
    if (rev.size() >= need) return;
    const seqnode* nd = node(t);
    if (tlvl == lvl)
    {
      for (u32 i = nd->n; i-- > 0 && rev.size() < need;)
        rev.push_back(entry_of(nd, i));
      return;
    }
    for (u32 i = nd->n; i-- > 0 && rev.size() < need;)
      tail_entries_rev(nd->child((u16)i), tlvl - 1, lvl, need, rev);
  }

  // The last ≤W level-lvl entries strictly before the path's level-lvl node:
  // the chunker context that reproduces the old rolling-hash state at that
  // node's start (an old chunk boundary, still a boundary in the new stream
  // because boundary decisions only look backward).
  std::vector<Entry> prime_entries(const Path& p, u32 lvl, u32 W)
  {
    std::vector<Entry> rev;
    for (u32 A = lvl + 1; A < p.size() && rev.size() < W; ++A)
    {
      const seqnode* nA = node(p[A].first);
      for (u32 i = p[A].second; i-- > 0 && rev.size() < W;)
        tail_entries_rev(nA->child((u16)i), A - 1, lvl, W, rev);
    }
    std::reverse(rev.begin(), rev.end());
    return rev;
  }

  // Forward cursor over the right-hand tree's per-level node streams.
  struct RCursor
  {
    SequenceArena* ar;
    Path p;
    bool done;

    // Advance to the next level-lvl node (leftmost descent); false at end.
    bool advance(u32 lvl)
    {
      u32 A = lvl + 1;
      while (A < p.size())
      {
        const seqnode* nA = ar->node(p[A].first);
        if (p[A].second + 1 < nA->n) break;
        ++A;
      }
      if (A >= p.size())
      {
        done = true;
        return false;
      }
      p[A].second++;
      while (A > lvl)
      {
        const seqnode* nA = ar->node(p[A].first);
        const u64 child = nA->child((u16)p[A].second);
        --A;
        p[A] = {child, 0};
      }
      return true;
    }
  };

  // Feed the right stream at one level, node by node, until resync or end.
  // Resync fires when a chunk boundary lands EXACTLY on an old node seam
  // after ≥SEQ_HASH_WINDOW right-fed entries: from a shared boundary with an
  // identical hash window and identical remaining content, every downstream
  // boundary decision coincides with the old ones, so the remaining old
  // nodes are the new nodes -- reuse them verbatim.  A byte-leaf chunker's
  // deferred (snap) cut is resolved by PEEKING the next node's first byte
  // -- exactly what that byte's own push would do -- so seam alignment is
  // still a pure function of the byte stream.  Returns true on resync
  // (cursor parked AT the first reused node); false when the stream was
  // consumed to its end (cursor done).
  bool feed_right(RCursor& rc, u32 lvl, Chunker& C)
  {
    u64 fed = 0;
    while (true)
    {
      const seqnode* nd = node(rc.p[lvl].first);
      for (u32 i = rc.p[lvl].second; i < nd->n; ++i)
      {
        C.push(entry_of(nd, i));
        ++fed;
      }
      rc.p[lvl].second = nd->n;
      if (!rc.advance(lvl)) return false;
      if (fed >= SEQ_HASH_WINDOW)
      {
        if (C.byteleaf() && C.pending)
          C.resolve_pending(entry_of(node(rc.p[lvl].first), 0).w);
        if (C.at_boundary()) return true;
      }
    }
  }

  // The splice core: canonical tree for
  //   left[0, cl) ++ mid[0, nmid) ++ right[cr, total(right))
  // over PRIMARY-unit positions (elements / bytes; byte-mode cuts must sit
  // on codepoint starts, which every caller guarantees).  Reuses untouched
  // old nodes on both sides: the left prefix is reused by path surgery
  // (truncation never disturbs earlier boundaries), the right suffix by
  // boundary resynchronization (feed_right).  Every emitted node comes
  // from the same Chunker discipline as build(), so the result is
  // canonical by construction.
  u64 rebuild(u64 left, u64 cl, const u64* mid, u32 nmid, u64 right, u64 cr,
              bool bmode = false)
  {
    const u64 e = empty();
    bool hasL = (left != e) && (cl > 0);
    const bool hasR = (right != e) && (cr < node(right)->total);

    Path lp;
    if (hasL) lp = path_to(left, cl);
    RCursor rc{this, {}, true};
    if (hasR)
    {
      rc.p = path_to(right, cr);
      rc.done = false;
    }

    std::vector<Entry> midv;
    midv.reserve(nmid);
    for (u32 i = 0; i < nmid; ++i) midv.push_back({mid[i], 1, 0});

    u32 lvl = 0;
    while (true)
    {
      const bool lHere = hasL && lvl < lp.size();
      const bool rHere = !rc.done && lvl < rc.p.size();
      if (!lHere && !rHere)
      {
        // Nothing old left to weave: reduce the pending entries to one root.
        if (midv.empty()) return e;
        if (midv.size() == 1 && lvl > 0) return midv[0].w;
        Chunker C(this, lvl, bmode);
        for (u32 i = 0; i < midv.size(); ++i) C.push(midv[i]);
        C.flush();
        midv = std::move(C.out);
        ++lvl;
        continue;
      }

      Chunker C(this, lvl, bmode);
      if (lHere)
      {
        const std::vector<Entry> pre = prime_entries(lp, lvl, SEQ_HASH_WINDOW);
        if (pre.empty() && !rHere)
        {
          // No entries precede this level's cut node (every ancestor sits at
          // index 0) and there is no right side: the left feed ++ midv IS the
          // entire remaining stream.  Reduce it through the termination path
          // -- force-chunking a 1-entry stream here would wrap a unary
          // branch no from-scratch build ever makes (canonicity).
          const seqnode* nd = node(lp[lvl].first);
          std::vector<Entry> stream;
          stream.reserve(lp[lvl].second + midv.size());
          for (u32 i = 0; i < lp[lvl].second; ++i)
            stream.push_back(entry_of(nd, i));
          for (u32 i = 0; i < midv.size(); ++i) stream.push_back(midv[i]);
          midv = std::move(stream);
          hasL = false;
          continue;
        }
        for (u32 i = 0; i < pre.size(); ++i) C.prime(pre[i].w);
        const seqnode* nd = node(lp[lvl].first);
        for (u32 i = 0; i < lp[lvl].second; ++i) C.push(entry_of(nd, i));
      }
      for (u32 i = 0; i < midv.size(); ++i) C.push(midv[i]);
      bool resync = false;
      if (rHere) resync = feed_right(rc, lvl, C);
      if (!resync) C.flush();
      midv = std::move(C.out);
      ++lvl;
    }
  }

public:
  // Chunk an element stream once: O(n).  Literal lowering, rev/sort, and
  // cross-DB re-canonicalization all land here.
  u64 build(const u64* xs, u64 n)
  {
    if (n == 0) return empty();
    Chunker C(this, 0, false);
    for (u64 i = 0; i < n; ++i) C.push({xs[i], 1, 0});
    C.flush();
    std::vector<Entry> level = std::move(C.out);
    u32 lvl = 1;
    while (level.size() > 1)
    {
      Chunker B(this, lvl, false);
      for (u32 i = 0; i < level.size(); ++i) B.push(level[i]);
      B.flush();
      level = std::move(B.out);
      ++lvl;
    }
    return level[0].w;
  }

  // Point read: O(log n) descent by counts.  Caller checks i < len.
  u64 ref(u64 t, u64 i)
  {
    const seqnode* nd = node(t);
    while (nd->kind == SEQ_BRANCH)
    {
      u32 c = 0;
      for (; c + 1 < nd->n; ++c)
      {
        const u64 cc = nd->w[2 * c + 1];
        if (i < cc) break;
        i -= cc;
      }
      nd = node(nd->w[2 * c]);
    }
    return nd->w[i];
  }

  // Point and bulk edits -- all expected O(log n) via the splice core.
  // Callers enforce bounds (the prims layer's partial/clamp semantics).
  u64 set(u64 t, u64 i, u64 v)
  {
    if (ref(t, i) == v) return t;
    return rebuild(t, i, &v, 1, t, i + 1);
  }

  u64 ins(u64 t, u64 i, u64 v) { return rebuild(t, i, &v, 1, t, i); }

  u64 del(u64 t, u64 i) { return rebuild(t, i, 0, 0, t, i + 1); }

  u64 cat(u64 a, u64 b)
  {
    if (a == empty()) return b;
    if (b == empty()) return a;
    return rebuild(a, len(a), 0, 0, b, 0);
  }

  // slice(t, i, j) = elements [i, j), bounds pre-clamped by the caller.
  // drop resynchronizes into the old suffix; take is pure path surgery
  // (truncation never disturbs earlier boundaries).
  u64 drop(u64 t, u64 i)
  {
    if (i == 0) return t;
    if (i >= len(t)) return empty();
    return rebuild(empty(), 0, 0, 0, t, i);
  }

  u64 take(u64 t, u64 j)
  {
    if (j == 0) return empty();
    if (j >= len(t)) return t;
    return rebuild(t, j, 0, 0, empty(), 0);
  }

  u64 slice(u64 t, u64 i, u64 j)
  {
    if (i >= j) return empty();
    return take(drop(t, i), j - i);
  }

  // In-order visit of every element word.
  template <typename F>
  void foreach(u64 t, F f)
  {
    const seqnode* nd = node(t);
    if (nd->kind == SEQ_BRANCH)
      for (u32 i = 0; i < nd->n; ++i)
        foreach(nd->w[2 * i], f);
    else if (nd->kind == SEQ_LEAF_WORDS)
      for (u32 i = 0; i < nd->n; ++i)
        f(nd->w[i]);
  }

  void to_vector(u64 t, std::vector<u64>& out)
  {
    out.reserve(out.size() + len(t));
    foreach(t, [&](u64 w) { out.push_back(w); });
  }

  // O(n) by necessity (reversal is not chunk-local).
  u64 rev(u64 t)
  {
    std::vector<u64> xs;
    to_vector(t, xs);
    std::reverse(xs.begin(), xs.end());
    return build(xs.data(), xs.size());
  }

private:
  // In-order visit skipping the first `skip` elements; F returns false to stop.
  template <typename F>
  bool walk_from(u64 t, u64 skip, F& f)
  {
    const seqnode* nd = node(t);
    if (nd->kind == SEQ_BRANCH)
    {
      for (u32 i = 0; i < nd->n; ++i)
      {
        const u64 c = nd->w[2 * i + 1];
        if (skip >= c)
        {
          skip -= c;
          continue;
        }
        if (!walk_from(nd->w[2 * i], skip, f)) return false;
        skip = 0;
      }
      return true;
    }
    for (u32 i = (u32)skip; i < nd->n; ++i)
      if (!f(nd->w[i])) return false;
    return true;
  }

  // A leaf-granular in-order iterator (cmp's lockstep walk).
  struct LeafIter
  {
    SequenceArena* ar;
    std::vector<std::pair<u64,u32>> st;   // (branch word, next child index)
    u64 leaf;                             // current leaf word (0 = exhausted)
    const seqnode* nd;
    u32 off;

    void descend(u64 t)
    {
      const seqnode* d = ar->node(t);
      while (d->kind == SEQ_BRANCH)
      {
        st.push_back({t, 1});
        t = d->w[0];
        d = ar->node(t);
      }
      leaf = t;
      nd = d;
      off = 0;
      if (nd->n == 0) next_leaf();   // only the empty root
    }

    void next_leaf()
    {
      while (!st.empty())
      {
        const seqnode* b = ar->node(st.back().first);
        if (st.back().second < b->n)
        {
          const u64 child = b->w[2 * st.back().second++];
          descend(child);
          return;
        }
        st.pop_back();
      }
      leaf = 0;
    }

    bool at_end() const { return leaf == 0; }

    u64 word() const { return nd->w[off]; }

    void step()
    {
      if (++off >= nd->n) next_leaf();
    }
  };

public:
  // Lexicographic compare by raw unsigned word, shorter-prefix-first; -1/0/1.
  // Physical equality short-circuits, both whole-tree and per-aligned-leaf
  // (canonical interning: equal runs chunk to equal leaves).
  s32 cmp(u64 a, u64 b)
  {
    if (a == b) return 0;
    LeafIter ia{this}, ib{this};
    ia.descend(a);
    ib.descend(b);
    while (!ia.at_end() && !ib.at_end())
    {
      if (ia.off == 0 && ib.off == 0 && ia.leaf == ib.leaf)
      {
        // aligned identical leaves: skip the whole run
        ia.off = ia.nd->n;
        ia.next_leaf();
        ib.off = ib.nd->n;
        ib.next_leaf();
        continue;
      }
      const u64 x = ia.word(), y = ib.word();
      if (x != y) return (x < y) ? -1 : 1;
      ia.step();
      ib.step();
    }
    if (ia.at_end() && ib.at_end()) return 0;
    return ia.at_end() ? -1 : 1;
  }

  // First position ≥ from where elements [pos, pos+j) equal run[0, j);
  // SEQ_NPOS if none.  The kernel under lidx and the §5.2 demand enumerators.
  u64 find(u64 t, const u64* run, u32 j, u64 from)
  {
    const u64 n = len(t);
    if (j == 0) return (from <= n) ? from : SEQ_NPOS;
    if (from + j > n) return SEQ_NPOS;
    std::vector<u64> ring(j);
    u64 q = from;        // stream position of the incoming word
    u64 found = SEQ_NPOS;
    auto f = [&](u64 w) -> bool
    {
      ring[q % j] = w;
      if (q + 1 >= from + j)
      {
        const u64 p = q + 1 - j;
        u32 k = 0;
        for (; k < j; ++k)
          if (ring[(p + k) % j] != run[k]) break;
        if (k == j)
        {
          found = p;
          return false;
        }
      }
      ++q;
      return true;
    };
    walk_from(t, from, f);
    return found;
  }

  // -----------------------------------------------------------------------
  // Byte trees (S2 rope strings, docs/sequences.md §6): the same engine
  // over byte leaves and (child, bytes, cps) branches.  Positions are
  // BYTES at the engine level; codepoint indexing converts via cp2byte
  // (leaf boundaries sit on codepoint starts by the snap rule, so every
  // codepoint's bytes live in one leaf).  Callers (seq_prims.h) enforce
  // the small-string threshold: byte trees with <= SEQ_BLEAF_MAX bytes are
  // never built (such strings stay monolithic tag-0 interns).

  // Chunk a byte stream once: O(n).  n >= 1 by contract (empty strings are
  // monolithic tag-0 interns; encodeString never builds a rope for them).
  u64 build_bytes(const u8* s, u64 n)
  {
    if (n == 0)
      fatal("Sequence arena: build_bytes on an empty stream "
            "(the caller must normalize)");
    Chunker C(this, 0, true);
    for (u64 i = 0; i < n; ++i)
      C.push({s[i], 1, SEQ_CP_START(s[i]) ? (u64)1 : 0});
    C.flush();
    std::vector<Entry> level = std::move(C.out);
    u32 lvl = 1;
    while (level.size() > 1)
    {
      Chunker B(this, lvl, true);
      for (u32 i = 0; i < level.size(); ++i) B.push(level[i]);
      B.flush();
      level = std::move(B.out);
      ++lvl;
    }
    return level[0].w;
  }

  u64 byte_len(u64 t) { return node(t)->total; }
  u64 cp_len(u64 t) { return node(t)->total2; }

  // The byte offset where codepoint cp starts (cp == cp_len -> byte_len).
  u64 cp2byte(u64 t, u64 cp)
  {
    u64 bytes = 0;
    const seqnode* nd = node(t);
    while (nd->branch())
    {
      u32 i = 0;
      for (; i + 1 < nd->n; ++i)
      {
        const u64 c2 = nd->w[3 * i + 2];
        if (cp < c2) break;
        cp -= c2;
        bytes += nd->w[3 * i + 1];
      }
      nd = node(nd->child((u16)i));
    }
    u32 i = 0;
    while (cp > 0 && i < nd->n)
    {
      ++i;
      while (i < nd->n && !SEQ_CP_START(nd->byte_at((u16)i))) ++i;
      --cp;
    }
    return bytes + i;
  }

  // O(log n) seam concatenation of two byte trees.
  u64 cat_bytes(u64 a, u64 b)
  {
    return rebuild(a, byte_len(a), 0, 0, b, 0, true);
  }

  // Byte-position take/drop (positions are codepoint starts by contract);
  // slice by CODEPOINT indices, pre-clamped by the caller.
  u64 take_bytes(u64 t, u64 j)
  {
    if (j >= byte_len(t)) return t;
    return rebuild(t, j, 0, 0, empty(), 0, true);
  }

  u64 drop_bytes(u64 t, u64 i)
  {
    if (i == 0) return t;
    return rebuild(empty(), 0, 0, 0, t, i, true);
  }

  // Byte tree of codepoints [cpi, cpj); nonempty by contract (the caller
  // materializes small/empty results as monolithic strings anyway).
  u64 slice_cp(u64 t, u64 cpi, u64 cpj)
  {
    return take_bytes(drop_bytes(t, cp2byte(t, cpi)),
                      cp2byte(t, cpj) - cp2byte(t, cpi));
  }

  // Append the tree's bytes to out (output boundaries: CSV, prims that
  // materialize small results).
  void materialize(u64 t, std::string& out)
  {
    const seqnode* nd = node(t);
    if (nd->branch())
      for (u32 i = 0; i < nd->n; ++i)
        materialize(nd->child((u16)i), out);
    else
      for (u32 i = 0; i < nd->n; ++i)
        out += (char)nd->byte_at((u16)i);
  }

  // The bytes of codepoint i (1-4 written into out); returns the count.
  u32 ref_cp(u64 t, u64 i, u8* out)
  {
    const u64 b0 = cp2byte(t, i);
    const u64 b1 = cp2byte(t, i + 1);
    for (u64 b = b0; b < b1; ++b)
      out[b - b0] = byte_ref(t, b);
    return (u32)(b1 - b0);
  }

  u8 byte_ref(u64 t, u64 i)
  {
    const seqnode* nd = node(t);
    while (nd->branch())
    {
      u32 c = 0;
      for (; c + 1 < nd->n; ++c)
      {
        const u64 cc = nd->child_primary(c);
        if (i < cc) break;
        i -= cc;
      }
      nd = node(nd->child((u16)c));
    }
    return nd->byte_at((u16)i);
  }

  // First occurrence of pat (m >= 1 bytes) at a codepoint start, searching
  // the whole tree; on a hit, *cp_at gets the codepoint index of the match
  // start.  Returns the byte position, or SEQ_NPOS.
  u64 find_bytes(u64 t, const u8* pat, u32 m, u64* cp_at)
  {
    const u64 n = byte_len(t);
    if (m > n) return SEQ_NPOS;
    std::vector<u8> ring(m);
    std::vector<u8> start(m);   // codepoint-start flag per ring slot
    u64 q = 0, cps = 0, found = SEQ_NPOS, found_cp = 0;
    auto f = [&](u8 b) -> bool
    {
      ring[q % m] = b;
      start[q % m] = SEQ_CP_START(b) ? 1 : 0;
      if (SEQ_CP_START(b)) ++cps;
      if (q + 1 >= m)
      {
        const u64 p = q + 1 - m;
        if (start[p % m])
        {
          u32 k = 0;
          for (; k < m; ++k)
            if (ring[(p + k) % m] != pat[k]) break;
          if (k == m)
          {
            // cps counts starts in [0, q]; starts within the match after
            // its first byte must not count toward the match's cp index
            u64 inside = 0;
            for (u32 kk = 1; kk < m; ++kk)
              if (start[(p + kk) % m]) ++inside;
            found = p;
            found_cp = cps - inside - 1;
            return false;
          }
        }
      }
      ++q;
      return true;
    };
    walk_bytes(t, f);
    if (found != SEQ_NPOS && cp_at) *cp_at = found_cp;
    return found;
  }

private:
  template <typename F>
  bool walk_bytes(u64 t, F& f)
  {
    const seqnode* nd = node(t);
    if (nd->branch())
    {
      for (u32 i = 0; i < nd->n; ++i)
        if (!walk_bytes(nd->child((u16)i), f)) return false;
      return true;
    }
    for (u32 i = 0; i < nd->n; ++i)
      if (!f(nd->byte_at((u16)i))) return false;
    return true;
  }
};


} // namespace slog
