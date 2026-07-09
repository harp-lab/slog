/** Sequence-arena unit tests (docs/sequences.md §10).
 *
 * Standalone binary; not part of the golden suite.  Build + run:
 *   clang++ -O2 -Wall -std=c++20 -pthread -Idaemon tests/seq-tests.cpp -o build/seq-tests
 *   ./build/seq-tests
 *
 * Covers, against a std::vector reference model with deterministic seeds:
 *   - differential correctness of build/ref/set/ins/del/cat/slice/rev/cmp/
 *     find/foreach over randomized op sequences;
 *   - CANONICITY: the incremental result of every edit op must intern to the
 *     IDENTICAL root word as a from-scratch build of the model vector (the
 *     exact-id oracle content-addressing gives us), plus N random build
 *     paths (whole-build, chatted splits, element-at-a-time inserts) to the
 *     same content yielding ONE id, cat associativity, slice/cat identities;
 *   - edit locality: fresh-intern delta per point edit bounded by c·log n
 *     on random content;
 *   - degenerate content: all-equal elements and tiny-alphabet streams
 *     (graceful, correct, dedup'd -- probe work, not memory);
 *   - concurrency: threads interning the same and overlapping content agree
 *     on every root word;
 *   - reload: re-interning the arena's partition dumps in order into a fresh
 *     arena reproduces every id (the value.seq persistence argument).
 */

#include <iostream>
#include <string>

#include "fatal.h"
#include "types.h"
#include "debug.h"
#include "utf8string.h"
#include "intern.h"
#include "seqparams.h"
#include "seq.h"

#include <vector>
#include <random>
#include <algorithm>
#include <thread>

using namespace slog;

static int checks = 0;
static int failures = 0;

#define CHECK(cond, msg)                                                  \
  do {                                                                    \
    ++checks;                                                             \
    if (!(cond)) {                                                        \
      ++failures;                                                         \
      std::cout << "FAIL(" << __LINE__ << "): " << msg << std::endl;      \
    }                                                                     \
  } while (0)

static u64 build_of(SequenceArena& A, const std::vector<u64>& v)
{
  return A.build(v.data(), v.size());
}

static std::vector<u64> contents(SequenceArena& A, u64 t)
{
  std::vector<u64> out;
  A.to_vector(t, out);
  return out;
}

static bool agrees(SequenceArena& A, u64 t, const std::vector<u64>& model)
{
  return A.len(t) == model.size() && contents(A, t) == model;
}

// A word generator mixing full-entropy values with a tiny alphabet (chunking
// stress: low-entropy streams have few distinct gear values).
static u64 word(std::mt19937_64& rng, bool tiny = false)
{
  if (tiny) return rng() % 4;
  return (rng() % 3 == 0) ? (rng() % 1000) : rng();
}

static void basics(SequenceArena& A)
{
  CHECK(A.empty() == A.empty(), "empty not canonical");
  CHECK(A.len(A.empty()) == 0, "empty length");
  CHECK(is_seq(A.empty()), "empty not seq-tagged");

  // tiny sequences: root IS the leaf; build is deterministic
  std::vector<u64> v{10, 20, 30};
  const u64 t = build_of(A, v);
  CHECK(t == build_of(A, v), "rebuild of equal content changed id");
  CHECK(agrees(A, t, v), "3-element content mismatch");
  CHECK(A.ref(t, 0) == 10 && A.ref(t, 1) == 20 && A.ref(t, 2) == 30, "ref");

  const u64 one = A.build(v.data(), 1);
  CHECK(A.len(one) == 1 && A.ref(one, 0) == 10, "singleton");
  CHECK(A.cat(A.empty(), t) == t && A.cat(t, A.empty()) == t, "cat empty identity");
  CHECK(A.slice(t, 1, 1) == A.empty(), "empty slice");
  CHECK(A.slice(t, 0, 3) == t, "full slice identity");
}

static void build_paths(SequenceArena& A, u32 seed, u32 n)
{
  // N random build paths to the same content must yield ONE id (§1.2's
  // canonical-form proof obligation, tested).
  std::mt19937_64 rng(seed);
  std::vector<u64> v(n);
  for (auto& x : v) x = word(rng);
  const u64 whole = build_of(A, v);
  CHECK(agrees(A, whole, v), "whole-build content");

  // path 2: cat of random splits (recursive halves at random pivots)
  for (int round = 0; round < 4; ++round)
  {
    std::vector<u64> pieces_stack;
    // split into k pieces at random cut points, build each, cat left-to-right
    u32 k = 2 + rng() % 6;
    std::vector<u32> cuts{0, n};
    for (u32 i = 0; i + 1 < k; ++i) cuts.push_back(rng() % (n + 1));
    std::sort(cuts.begin(), cuts.end());
    u64 acc = A.empty();
    for (u32 i = 0; i + 1 < cuts.size(); ++i)
    {
      std::vector<u64> piece(v.begin() + cuts[i], v.begin() + cuts[i + 1]);
      acc = A.cat(acc, build_of(A, piece));
    }
    CHECK(acc == whole, "cat-of-splits diverged from whole build (round "
                            << round << ")");
  }

  // path 3: element-at-a-time appends
  u64 acc = A.empty();
  for (u32 i = 0; i < n; ++i) acc = A.ins(acc, i, v[i]);
  CHECK(acc == whole, "append-at-a-time diverged from whole build");

  // path 4: element-at-a-time PREPENDS of the reverse
  acc = A.empty();
  for (u32 i = n; i-- > 0;) acc = A.ins(acc, 0, v[i]);
  CHECK(acc == whole, "prepend-at-a-time diverged from whole build");

  // cat associativity
  std::vector<u64> a(v.begin(), v.begin() + n / 3);
  std::vector<u64> b(v.begin() + n / 3, v.begin() + (2 * n) / 3);
  std::vector<u64> c(v.begin() + (2 * n) / 3, v.end());
  const u64 ta = build_of(A, a), tb = build_of(A, b), tc = build_of(A, c);
  CHECK(A.cat(A.cat(ta, tb), tc) == A.cat(ta, A.cat(tb, tc)),
        "cat not associative on ids");
  CHECK(A.cat(A.cat(ta, tb), tc) == whole, "3-way cat diverged from whole");

  // slice/cat identities
  const u64 i = rng() % (n + 1);
  CHECK(A.cat(A.slice(whole, 0, i), A.slice(whole, i, n)) == whole,
        "slice/cat split-rejoin identity");
  CHECK(A.slice(A.cat(ta, tb), 0, a.size()) == ta, "slice of cat != left piece");
  CHECK(A.slice(A.cat(ta, tb), a.size(), a.size() + b.size()) == tb,
        "slice of cat != right piece");
}

static void differential(SequenceArena& A, u32 seed, u32 rounds, bool tiny)
{
  // Randomized op sequence against std::vector, with the exact-id oracle:
  // after EVERY op the incremental root must equal build(model).
  std::mt19937_64 rng(seed);
  std::vector<u64> model;
  const u32 n0 = 50 + rng() % 400;
  for (u32 i = 0; i < n0; ++i) model.push_back(word(rng, tiny));
  u64 t = build_of(A, model);

  for (u32 r = 0; r < rounds; ++r)
  {
    switch (rng() % 8)
    {
    case 0:  // set
      if (!model.empty())
      {
        const u64 i = rng() % model.size();
        const u64 v = word(rng, tiny);
        model[i] = v;
        t = A.set(t, i, v);
      }
      break;
    case 1:  // ins (any position 0..len)
    {
      const u64 i = rng() % (model.size() + 1);
      const u64 v = word(rng, tiny);
      model.insert(model.begin() + i, v);
      t = A.ins(t, i, v);
      break;
    }
    case 2:  // del
      if (!model.empty())
      {
        const u64 i = rng() % model.size();
        model.erase(model.begin() + i);
        t = A.del(t, i);
      }
      break;
    case 3:  // cat a fresh tail
    {
      const u32 m = rng() % 200;
      std::vector<u64> tail(m);
      for (auto& x : tail) x = word(rng, tiny);
      t = A.cat(t, build_of(A, tail));
      model.insert(model.end(), tail.begin(), tail.end());
      break;
    }
    case 4:  // slice
      if (!model.empty())
      {
        u64 i = rng() % model.size(), j = rng() % (model.size() + 1);
        if (i > j) std::swap(i, j);
        model = std::vector<u64>(model.begin() + i, model.begin() + j);
        t = A.slice(t, i, j);
      }
      break;
    case 5:  // rev
      std::reverse(model.begin(), model.end());
      t = A.rev(t);
      break;
    case 6:  // ref spot checks
      for (u32 k = 0; k < 5 && !model.empty(); ++k)
      {
        const u64 i = rng() % model.size();
        CHECK(A.ref(t, i) == model[i], "ref mismatch at " << i);
      }
      break;
    case 7:  // find: existing element and absent probe
      if (!model.empty())
      {
        const u64 from = rng() % model.size();
        const u64 needle = model[rng() % model.size()];
        u64 expect = SEQ_NPOS;
        for (u64 i = from; i < model.size(); ++i)
          if (model[i] == needle) { expect = i; break; }
        CHECK(A.find(t, &needle, 1, from) == expect, "find(1) mismatch");
        // a length-3 run actually present
        if (model.size() >= 3)
        {
          const u64 p = rng() % (model.size() - 2);
          u64 run[3] = {model[p], model[p + 1], model[p + 2]};
          const u64 got = A.find(t, run, 3, 0);
          CHECK(got != SEQ_NPOS && got <= p, "find(3) missed a present run");
          if (got != SEQ_NPOS)
            for (u32 k = 0; k < 3; ++k)
              CHECK(A.ref(t, got + k) == run[k], "find(3) bogus position");
        }
      }
      break;
    }
    CHECK(t == build_of(A, model),
          "op " << r << " diverged from from-scratch build (canonicity!)");
    if (r % 16 == 0)
      CHECK(agrees(A, t, model), "content mismatch at round " << r);
  }
}

static void compare_test(SequenceArena& A, u32 seed)
{
  std::mt19937_64 rng(seed);
  for (u32 r = 0; r < 300; ++r)
  {
    const u32 n = rng() % 60, m = rng() % 60;
    std::vector<u64> a(n), b(m);
    for (auto& x : a) x = word(rng, true);
    for (auto& x : b) x = word(rng, true);
    if (r % 4 == 0 && n > 0) { b = a; if (r % 8 == 0) b.resize(m % (n + 1)); }
    const u64 ta = build_of(A, a), tb = build_of(A, b);
    const int expect = a < b ? -1 : (b < a ? 1 : 0);   // u64 lexicographic
    CHECK(A.cmp(ta, tb) == expect, "cmp mismatch (n=" << n << ",m=" << m << ")");
    CHECK(A.cmp(ta, ta) == 0, "cmp self");
  }
}

static void locality(SequenceArena& A, u32 seed)
{
  // Point edits on a large random sequence must intern O(log n) fresh nodes
  // (the §1.4 contract).  Bound is generous: c·(window/target)·height.
  std::mt19937_64 rng(seed);
  const u32 n = 200000;
  std::vector<u64> v(n);
  for (auto& x : v) x = rng();
  u64 t = build_of(A, v);
  CHECK(A.len(t) == n, "big build length");

  // height ≈ log_16(n/16); bound fresh interns per edit
  u32 height = 1;
  for (u64 m = n; m > SEQ_WLEAF_MAX; m /= 16) ++height;
  const u64 bound = 64 + 48 * (u64)height;

  u64 worst = 0, total = 0;
  const u32 edits = 60;
  for (u32 k = 0; k < edits; ++k)
  {
    const u64 before = A.freshCount();
    const u64 i = rng() % A.len(t);
    switch (k % 3)
    {
    case 0: t = A.set(t, i, rng()); break;
    case 1: t = A.ins(t, i, rng()); break;
    case 2: t = A.del(t, i); break;
    }
    const u64 d = A.freshCount() - before;
    worst = std::max(worst, d);
    total += d;
  }
  CHECK(worst <= bound, "edit locality: worst edit interned " << worst
                            << " fresh nodes (bound " << bound << ")");
  std::cout << "  locality: " << edits << " point edits on n=" << n
            << ": avg " << (total / edits) << " fresh nodes, worst " << worst
            << " (bound " << bound << ", height " << height << ")" << std::endl;

  // cat locality: joining two large sequences is seam work, not O(n)
  std::vector<u64> w(n);
  for (auto& x : w) x = rng();
  const u64 t2 = build_of(A, w);
  const u64 before = A.freshCount();
  const u64 joined = A.cat(t, t2);
  const u64 d = A.freshCount() - before;
  CHECK(A.len(joined) == A.len(t) + n, "cat length");
  CHECK(d <= bound, "cat locality: " << d << " fresh nodes (bound " << bound << ")");
}

static void degenerate(SequenceArena& A)
{
  // All-equal elements: no content entropy.  min/max keep chunking sane,
  // hash-consing collapses the storage (identical leaves = one node), edits
  // stay correct (exact-id oracle) even though resynchronization may never
  // trigger -- the pathology costs probes, not memory (§1.5).
  const u32 n = 100000;
  std::vector<u64> v(n, 42);
  const u64 before = A.freshCount();
  u64 t = build_of(A, v);
  const u64 d = A.freshCount() - before;
  CHECK(A.len(t) == n, "all-equal length");
  // storage collapse: identical chunks intern once; the whole 100k-element
  // tree should cost far fewer fresh nodes than leaves-if-distinct
  CHECK(d < 2000, "all-equal build interned " << d << " nodes (dedup broken?)");

  v.insert(v.begin() + n / 2, 7);
  t = A.ins(t, n / 2, 7);
  CHECK(t == build_of(A, v), "all-equal mid-insert diverged (canonicity)");
  v.erase(v.begin() + n / 2);
  t = A.del(t, n / 2);
  CHECK(t == build_of(A, v), "all-equal mid-delete diverged");

  // an ascending ramp (every word distinct, low gear correlation) round trip
  std::vector<u64> ramp(5000);
  for (u32 i = 0; i < ramp.size(); ++i) ramp[i] = i;
  const u64 tr = build_of(A, ramp);
  CHECK(agrees(A, tr, ramp), "ramp content");
  CHECK(A.rev(A.rev(tr)) == tr, "rev involution");
}

static void concurrency(SequenceArena& A)
{
  // Threads interning identical and overlapping content agree on every id.
  const u32 nthreads = 8;
  std::vector<u64> shared(20000);
  std::mt19937_64 rng(1234);
  for (auto& x : shared) x = rng();

  std::vector<u64> roots(nthreads, 0);
  std::vector<u64> edited(nthreads, 0);
  std::vector<std::thread> ts;
  for (u32 th = 0; th < nthreads; ++th)
    ts.emplace_back([&, th]()
    {
      const u64 r = A.build(shared.data(), shared.size());
      roots[th] = r;
      // overlapping work: everyone performs the SAME edit sequence
      u64 t = r;
      t = A.ins(t, 500, 77);
      t = A.set(t, 1000, 88);
      t = A.del(t, 1500);
      t = A.cat(t, A.slice(r, 0, 300));
      edited[th] = t;
    });
  for (auto& th : ts) th.join();
  for (u32 th = 1; th < nthreads; ++th)
  {
    CHECK(roots[th] == roots[0], "thread " << th << " built a different root");
    CHECK(edited[th] == edited[0], "thread " << th << " edited to a different root");
  }
}

static void reload(SequenceArena& A)
{
  // Simulate value.seq: dump per-partition in iterator order, re-intern in
  // that order into a fresh arena, and require every id to reproduce.
  SequenceArena B;
  auto table = A.raw();
  u64 count = 0;
  for (u16 p = 0; p < table->getWritePartitions(); ++p)
    for (auto it = table->begin(p); it != table->end(); ++it)
    {
      const seqnode& nd = *it;
      B.intern_node(new seqnode(nd.kind, nd.n, nd.w));
      ++count;
    }
  u32 mismatches = 0;
  for (u16 p = 0; p < table->getWritePartitions(); ++p)
    for (auto it = table->begin(p); it != table->end(); ++it)
    {
      const seqnode& nd = *it;
      const u64 ida = A.intern_node(new seqnode(nd.kind, nd.n, nd.w));  // dup
      const u64 idb = B.intern_node(new seqnode(nd.kind, nd.n, nd.w));  // dup
      if (ida != idb) ++mismatches;
    }
  CHECK(mismatches == 0, mismatches << " node ids failed to reproduce on reload");
  CHECK(B.freshCount() == count, "reload interned a different node count");
}

// ---------------------------------------------------------------------
// Byte trees (S2 rope strings): differential vs std::string with the same
// exact-id oracle (build_bytes(reference) must equal every incremental
// result), UTF-8 snap invariants, and codepoint indexing.

static void utf8_append(std::string& s, u32 cp)
{
  if (cp < 0x80) s += (char)cp;
  else if (cp < 0x800)
  {
    s += (char)(0xC0 | (cp >> 6));
    s += (char)(0x80 | (cp & 0x3F));
  }
  else if (cp < 0x10000)
  {
    s += (char)(0xE0 | (cp >> 12));
    s += (char)(0x80 | ((cp >> 6) & 0x3F));
    s += (char)(0x80 | (cp & 0x3F));
  }
  else
  {
    s += (char)(0xF0 | (cp >> 18));
    s += (char)(0x80 | ((cp >> 12) & 0x3F));
    s += (char)(0x80 | ((cp >> 6) & 0x3F));
    s += (char)(0x80 | (cp & 0x3F));
  }
}

static std::string rand_utf8(std::mt19937_64& rng, u32 ncps)
{
  std::string s;
  for (u32 i = 0; i < ncps; ++i)
    switch (rng() % 8)
    {
    case 0:  utf8_append(s, 0x80 + rng() % 0x700); break;         // 2-byte
    case 1:  utf8_append(s, 0x800 + rng() % 0xF000); break;       // 3-byte
    case 2:  utf8_append(s, 0x10000 + rng() % 0x10000); break;    // 4-byte
    default: s += (char)('a' + rng() % 26);                       // ascii
    }
  return s;
}

static std::vector<u64> cp_starts(const std::string& s)
{
  std::vector<u64> st;
  for (u64 i = 0; i < s.size(); ++i)
    if (SEQ_CP_START((u8)s[i])) st.push_back(i);
  st.push_back(s.size());
  return st;
}

static u64 bbuild(SequenceArena& A, const std::string& s)
{
  return A.build_bytes((const u8*)s.data(), s.size());
}

static void byte_leaf_invariants(SequenceArena& A, u64 t, int line)
{
  // every leaf begins at a codepoint start (the snap rule), decodes
  // independently, and respects the (max + snap slack) bound
  struct W {
    SequenceArena* A; int line;
    void go(u64 t) {
      const seqnode* nd = A->node(t);
      if (nd->branch()) { for (u32 i = 0; i < nd->n; ++i) go(nd->child(i)); return; }
      CHECK(nd->kind == SEQ_LEAF_BYTES, "word leaf inside a byte tree (from line " << line << ")");
      CHECK(nd->n >= 1 && nd->n <= SEQ_BLEAF_MAX + 3,
            "byte leaf size " << nd->n << " out of bounds (from line " << line << ")");
      CHECK(SEQ_CP_START(nd->byte_at(0)),
            "byte leaf starts mid-codepoint (from line " << line << ")");
    } } w{&A, line};
  w.go(t);
}

static void byte_trees(SequenceArena& A, u32 seed)
{
  std::mt19937_64 rng(seed);

  // build + materialize + counts + canonicity across split-cat build paths
  for (u32 round = 0; round < 30; ++round)
  {
    const std::string s = rand_utf8(rng, 60 + rng() % 4000);
    const std::vector<u64> st = cp_starts(s);
    const u64 t = bbuild(A, s);
    CHECK(A.byte_len(t) == s.size(), "byte_len");
    CHECK(A.cp_len(t) == st.size() - 1, "cp_len");
    std::string back;
    A.materialize(t, back);
    CHECK(back == s, "materialize round trip");
    byte_leaf_invariants(A, t, __LINE__);

    // N split points; cat of the pieces must re-intern to the SAME root
    for (u32 k = 0; k < 3; ++k)
    {
      const u64 cut = st[rng() % st.size()];
      if (cut == 0 || cut == s.size()) continue;
      const u64 a = bbuild(A, s.substr(0, cut));
      const u64 b = bbuild(A, s.substr(cut));
      CHECK(A.cat_bytes(a, b) == t, "cat-of-split diverged (canonicity)");
    }

    // slice_cp against the reference, and the exact-id oracle
    for (u32 k = 0; k < 5; ++k)
    {
      u64 i = rng() % (st.size() - 1), j = rng() % st.size();
      if (i > j) std::swap(i, j);
      if (i == j) continue;
      const std::string ref = s.substr(st[i], st[j] - st[i]);
      const u64 sl = A.slice_cp(t, i, j);
      CHECK(sl == bbuild(A, ref), "slice_cp diverged from build (canonicity)");
      std::string got;
      A.materialize(sl, got);
      CHECK(got == ref, "slice_cp content");
    }

    // ref_cp: each extracted codepoint matches the reference bytes
    for (u32 k = 0; k < 5; ++k)
    {
      const u64 i = rng() % (st.size() - 1);
      u8 buf[4];
      const u32 nb = A.ref_cp(t, i, buf);
      CHECK(nb == st[i + 1] - st[i], "ref_cp width");
      CHECK(0 == memcmp(buf, s.data() + st[i], nb), "ref_cp bytes");
    }

    // find_bytes: a present substring is found at its first occurrence,
    // with the right codepoint index
    if (st.size() > 4)
    {
      const u64 i = rng() % (st.size() - 2);
      const u64 j = i + 1 + rng() % (st.size() - 1 - i);
      const std::string pat = s.substr(st[i], st[j] - st[i]);
      u64 cp = SEQ_NPOS;
      const u64 got = A.find_bytes(t, (const u8*)pat.data(), (u32)pat.size(),
                                   &cp);
      const u64 expect = s.find(pat);   // may be earlier than st[i]
      CHECK(got == expect, "find_bytes position");
      if (got != SEQ_NPOS)
      {
        u64 expect_cp = 0;
        for (u64 b = 0; b < got; ++b)
          if (SEQ_CP_START((u8)s[b])) ++expect_cp;
        CHECK(cp == expect_cp, "find_bytes codepoint index");
      }
      u8 absent[4] = {0xFF, 0xFF, 0xFF, 0xFF};   // invalid utf8: never present
      CHECK(A.find_bytes(t, absent, 4, nullptr) == SEQ_NPOS, "find_bytes absent");
    }
  }

  // cat locality: joining two large ropes is seam work
  const std::string x = rand_utf8(rng, 200000), y = rand_utf8(rng, 200000);
  const u64 tx = bbuild(A, x), ty = bbuild(A, y);
  const u64 before = A.freshCount();
  const u64 joined = A.cat_bytes(tx, ty);
  const u64 d = A.freshCount() - before;
  CHECK(A.byte_len(joined) == x.size() + y.size(), "big cat length");
  CHECK(d <= 600, "byte cat locality: " << d << " fresh nodes");
  byte_leaf_invariants(A, joined, __LINE__);

  // degenerate content: a long run of one ascii byte (max-forced leaves)
  std::string mono(100000, 'x');
  const u64 tm = bbuild(A, mono);
  CHECK(A.byte_len(tm) == 100000 && A.cp_len(tm) == 100000, "mono counts");
  std::string mono_back;
  A.materialize(tm, mono_back);
  CHECK(mono_back == mono, "mono round trip");
}

int main()
{
  SequenceArena A;

  basics(A);
  build_paths(A, 11, 3000);
  build_paths(A, 22, 700);
  build_paths(A, 33, 65);   // around one-leaf/two-leaf scale
  differential(A, 101, 300, false);
  differential(A, 202, 300, true);    // tiny alphabet
  differential(A, 303, 200, false);
  compare_test(A, 404);
  locality(A, 505);
  degenerate(A);
  byte_trees(A, 606);
  concurrency(A);
  reload(A);   // covers byte-kind records too (byte_trees ran first)

  std::cout << checks << " checks, " << failures << " failures" << std::endl;
  return failures ? 1 : 0;
}
