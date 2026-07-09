/** Collection-arena unit tests (docs/primitives.md M2.1).
 *
 * Standalone binary; not part of the golden suite.  Build + run:
 *   clang++ -O2 -Wall -std=c++20 -pthread -Idaemon tests/arena-tests.cpp -o build/arena-tests
 *   ./build/arena-tests
 *
 * Covers, against a std::map reference model with deterministic seeds:
 *   - differential correctness of put/put_soft/del/merge/diff/find/size/foreach
 *     over adversarial key distributions (dense ints, tagged words, random
 *     64-bit, single-bit deltas, top-bit keys);
 *   - canonicity: shuffled insertion orders and disjoint-partition merges
 *     intern to ONE word; physical-equality short-circuits (no-op ops return
 *     the same word);
 *   - algebraic identities (merge idempotence/absorption, diff self/empty,
 *     put-del round trip, left-bias);
 *   - concurrency: many threads interning the same and overlapping content
 *     agree on every root word;
 *   - reload: re-interning the arena's partition dumps in order into a fresh
 *     arena reproduces every id (the value.nodes persistence argument).
 */

#include <iostream>
#include <string>

#include "fatal.h"
#include "types.h"
#include "debug.h"
#include "utf8string.h"
#include "intern.h"
#include "arena.h"

#include <map>
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

// Enumerate a trie into a sorted-by-unsigned-key vector (the model's order).
static std::vector<std::pair<u64,u64>> entries(CollectionArena& A, u64 t)
{
  std::vector<std::pair<u64,u64>> out;
  A.foreach(t, [&](u64 k, u64 v) { out.push_back({k, v}); });
  return out;
}

static bool agrees(CollectionArena& A, u64 t, const std::map<u64,u64>& model)
{
  auto es = entries(A, t);
  if (es.size() != model.size()) return false;
  size_t i = 0;
  for (auto& [k, v] : model)
    if (es[i].first != k || es[i].second != v) return false;
    else ++i;
  if (A.size(t) != model.size()) return false;
  return true;
}

// Build a trie from a model by inserting in a given key order.
static u64 build(CollectionArena& A, const std::map<u64,u64>& model,
                 std::vector<u64> order)
{
  u64 t = A.empty();
  for (u64 k : order)
    t = A.put(t, k, model.at(k));
  return t;
}

// A key from one of several adversarial distributions.
static u64 gen_key(std::mt19937_64& rng)
{
  switch (rng() % 6)
  {
  case 0: return rng() % 64;                        // dense small
  case 1: return s32_encode((s32)(rng() % 1000));   // tagged ints
  case 2: return rng();                             // raw 64-bit
  case 3: return ((u64)1 << 63) | (rng() % 16);     // top bit set
  case 4: return intern_encode(0, rng() % 100000);  // fake string words
  case 5: default: return (rng() % 4) ^ ((rng() % 2) << 62);  // near-collisions
  }
}

static void differential(CollectionArena& A, u64 seed, u32 rounds)
{
  std::mt19937_64 rng(seed);
  const int SLOTS = 8;
  std::vector<u64> word(SLOTS, A.empty());
  std::vector<std::map<u64,u64>> model(SLOTS);

  for (u32 i = 0; i < rounds; ++i)
  {
    const int s = rng() % SLOTS;
    const int s2 = rng() % SLOTS;
    const u64 k = gen_key(rng);
    const u64 v = s32_encode((s32)(rng() % 100));
    switch (rng() % 6)
    {
    case 0:  // put (replace)
      word[s] = A.put(word[s], k, v);
      model[s][k] = v;
      break;
    case 1:  // put_soft (insert-if-absent)
      word[s] = A.put_soft(word[s], k, v);
      model[s].emplace(k, v);
      break;
    case 2:  // del
      word[s] = A.del(word[s], k);
      model[s].erase(k);
      break;
    case 3:  // merge (left-biased): s wins collisions
    {
      word[s] = A.merge(word[s], word[s2]);
      auto m = model[s2];
      for (auto& [mk, mv] : model[s]) m[mk] = mv;
      model[s] = m;
      break;
    }
    case 4:  // diff
    {
      word[s] = A.diff(word[s], word[s2]);
      if (s == s2)
        model[s].clear();
      else
        for (auto& [mk, mv] : model[s2]) model[s].erase(mk);
      break;
    }
    case 5:  // probe present + absent
    {
      u64 out = 0;
      const bool got = A.find(word[s], k, &out);
      const bool exp = model[s].count(k) > 0;
      CHECK(got == exp, "find presence disagrees with model");
      if (got && exp) CHECK(out == model[s][k], "find value disagrees");
      break;
    }
    }
    CHECK(agrees(A, word[s], model[s]), "content disagrees after op " << i);
  }

  // canonicity: rebuild each slot in two shuffled orders -> same word
  for (int s = 0; s < SLOTS; ++s)
  {
    std::vector<u64> keys;
    for (auto& [k, v] : model[s]) keys.push_back(k);
    std::shuffle(keys.begin(), keys.end(), rng);
    const u64 w1 = build(A, model[s], keys);
    std::shuffle(keys.begin(), keys.end(), rng);
    const u64 w2 = build(A, model[s], keys);
    CHECK(w1 == word[s] && w2 == word[s], "shuffled rebuilds differ");

    // ... and via a merge of a random disjoint partition
    std::map<u64,u64> part1, part2;
    for (auto& [k, v] : model[s])
      (rng() % 2 ? part1 : part2)[k] = v;
    std::vector<u64> ks1, ks2;
    for (auto& [k, v] : part1) ks1.push_back(k);
    for (auto& [k, v] : part2) ks2.push_back(k);
    const u64 wm = A.merge(build(A, part1, ks1), build(A, part2, ks2));
    CHECK(wm == word[s], "partition merge differs");
  }
}

static void identities(CollectionArena& A, u64 seed)
{
  std::mt19937_64 rng(seed);
  const u64 e = A.empty();
  for (int i = 0; i < 200; ++i)
  {
    std::map<u64,u64> m;
    const int n = rng() % 20;
    for (int j = 0; j < n; ++j) m[gen_key(rng)] = s32_encode((s32)(rng() % 9));
    std::vector<u64> ks;
    for (auto& [k, v] : m) ks.push_back(k);
    const u64 a = build(A, m, ks);

    CHECK(A.merge(a, a) == a, "merge not idempotent");
    CHECK(A.merge(a, e) == a && A.merge(e, a) == a, "empty not a unit");
    CHECK(A.diff(a, a) == e, "diff(a,a) != empty");
    CHECK(A.diff(a, e) == a && A.diff(e, a) == e, "diff empty laws");

    u64 k = gen_key(rng);
    while (m.count(k)) k = gen_key(rng);
    const u64 v = s32_encode(7);
    CHECK(A.del(A.put(a, k, v), k) == a, "put-del round trip differs");
    CHECK(A.del(a, k) == a, "del of absent key rebuilt the trie");
    if (n > 0)
    {
      const u64 k0 = ks[rng() % ks.size()];
      CHECK(A.put(a, k0, m[k0]) == a, "no-op put rebuilt the trie");
      CHECK(A.put_soft(a, k0, s32_encode(88)) == a, "put_soft replaced");
      // left bias: a's value survives a merge with a conflicting singleton
      const u64 b = A.put(e, k0, s32_encode(99));
      u64 out = 0;
      CHECK(A.find(A.merge(a, b), k0, &out) && out == m[k0],
            "merge not left-biased");
      CHECK(A.find(A.merge(b, a), k0, &out) && out == s32_encode(99),
            "merge not left-biased (flipped)");
    }
  }
}

static void concurrency(CollectionArena& A)
{
  // All threads build the same maps (plus thread-salted overlapping noise)
  // and must agree on every root word.
  const int T = 8, MAPS = 40;
  std::vector<std::vector<u64>> roots(T, std::vector<u64>(MAPS, 0));
  std::vector<std::thread> threads;
  for (int t = 0; t < T; ++t)
    threads.emplace_back([&, t]()
    {
      for (int i = 0; i < MAPS; ++i)
      {
        std::mt19937_64 rng(1000 + i);  // same content for every thread
        std::map<u64,u64> m;
        const int n = 1 + (rng() % 64);
        for (int j = 0; j < n; ++j) m[gen_key(rng)] = s32_encode((s32)(rng() % 9));
        std::vector<u64> ks;
        for (auto& [k, v] : m) ks.push_back(k);
        // thread-dependent insertion order: canonicity must erase it
        std::mt19937_64 shuf(7777 * (t + 1) + i);
        std::shuffle(ks.begin(), ks.end(), shuf);
        roots[t][i] = build(A, m, ks);
        // uncoordinated extra interning traffic on shared buckets
        u64 noise = A.empty();
        for (int j = 0; j < 32; ++j) noise = A.put(noise, shuf() % 512, s32_encode(1));
      }
    });
  for (auto& th : threads) th.join();
  for (int i = 0; i < MAPS; ++i)
    for (int t = 1; t < T; ++t)
      CHECK(roots[t][i] == roots[0][i], "threads disagree on root word");
}

// merge_spec (docs/primitives.md M2.2): the composed lattice join.
// Differential against reference models for set-union, pointwise min-map,
// and nested map-of-min-map; plus algebraic laws and leq_spec.
static void merge_spec_tests(CollectionArena& A, u64 seed)
{
  std::mt19937_64 rng(seed);
  LatSpec set_spec(LATSPEC_SET);
  LatSpec min_leaf(LAT_MIN);
  LatSpec minmap_spec(LATSPEC_MAP, new LatSpec(LAT_MIN));
  // (map K (map K2 (min int))) -- nested pointwise
  LatSpec nested_spec(LATSPEC_MAP, new LatSpec(LATSPEC_MAP, new LatSpec(LAT_MIN)));

  for (int round = 0; round < 200; ++round)
  {
    // set union vs model
    std::map<u64,u64> ma, mb;
    u64 wa = A.empty(), wb = A.empty();
    const int n = rng() % 24;
    for (int j = 0; j < n; ++j)
    {
      const u64 k = rng() % 64;
      if (rng() % 2) { ma[k] = s32_encode(1); wa = A.put(wa, k, s32_encode(1)); }
      else           { mb[k] = s32_encode(1); wb = A.put(wb, k, s32_encode(1)); }
    }
    const u64 wu = A.merge_spec(wa, wb, &set_spec);
    std::map<u64,u64> mu = ma;
    for (auto& [k, v] : mb) mu.emplace(k, v);
    CHECK(agrees(A, wu, mu), "set-union merge_spec disagrees with model");
    CHECK(A.merge_spec(wb, wa, &set_spec) == wu, "set-union not commutative");
    CHECK(A.merge_spec(wu, wu, &set_spec) == wu, "set-union not idempotent");
    CHECK(A.leq_spec(wa, wu, &set_spec) && A.leq_spec(wb, wu, &set_spec),
          "leq_spec: operands not below their union");

    // pointwise min-map vs model
    std::map<u64,u64> pa, pb;
    for (int j = 0; j < n; ++j)
    {
      const u64 k = rng() % 16;
      const u64 v = s32_encode((s32)(rng() % 100));
      auto& target = (rng() % 2) ? pa : pb;
      auto it = target.emplace(k, v);
      if (!it.second && s32_decode(v) < s32_decode(it.first->second))
        it.first->second = v;
    }
    // build each side by merging singletons, so min applies inside a side too
    u64 va = A.empty(), vb = A.empty();
    for (auto& [k, v] : pa) va = A.merge_spec(va, A.put(A.empty(), k, v), &minmap_spec);
    for (auto& [k, v] : pb) vb = A.merge_spec(vb, A.put(A.empty(), k, v), &minmap_spec);
    const u64 vm = A.merge_spec(va, vb, &minmap_spec);
    std::map<u64,u64> pm = pa;
    for (auto& [k, v] : pb)
    {
      auto it = pm.emplace(k, v);
      if (!it.second && s32_decode(v) < s32_decode(it.first->second))
        it.first->second = v;
    }
    CHECK(agrees(A, vm, pm), "min-map merge_spec disagrees with model");
    CHECK(A.merge_spec(vb, va, &minmap_spec) == vm, "min-map not commutative");
    CHECK(A.leq_spec(va, vm, &minmap_spec), "leq_spec: operand not below min-map join");

    // scalar leaf dispatch
    const u64 x = s32_encode((s32)(rng() % 50)), y = s32_encode((s32)(rng() % 50));
    CHECK(A.merge_spec(x, y, &min_leaf)
            == (s32_decode(x) <= s32_decode(y) ? x : y),
          "scalar min leaf join wrong");

    // nested: {outer: {inner: min}} joins two levels down
    const u64 in1 = A.put(A.empty(), 3, s32_encode(9));
    const u64 in2 = A.put(A.empty(), 3, s32_encode(4));
    const u64 o1 = A.put(A.empty(), 7, in1);
    const u64 o2 = A.put(A.empty(), 7, in2);
    const u64 om = A.merge_spec(o1, o2, &nested_spec);
    u64 inner_out = 0, leaf_out = 0;
    CHECK(A.find(om, 7, &inner_out) && A.find(inner_out, 3, &leaf_out)
            && leaf_out == s32_encode(4),
          "nested map join did not min at the leaf");
  }
}

// foreach_added (docs/primitives.md §8.5, the M2.4 decomposition walk):
// differential against the model definition -- every entry of `new` whose
// (key, value) pair is not in `old` -- over adversarial key pairs, both
// arbitrary trie pairs and the monotone old-then-grown pairs the lattice
// merge point actually produces.
static std::vector<std::pair<u64,u64>> added_of(CollectionArena& A, u64 o, u64 n)
{
  std::vector<std::pair<u64,u64>> out;
  A.foreach_added(o, n, [&](u64 k, u64 v) { out.push_back({k, v}); });
  std::sort(out.begin(), out.end());
  return out;
}

static void foreach_added_tests(CollectionArena& A, u64 seed, int rounds)
{
  std::mt19937_64 rng(seed);
  for (int i = 0; i < rounds; ++i)
  {
    // an arbitrary base and an arbitrary (overlapping) second trie
    std::map<u64,u64> om, nm;
    const int n0 = rng() % 24, n1 = rng() % 24;
    for (int j = 0; j < n0; ++j) om[gen_key(rng)] = s32_encode((s32)(rng() % 5));
    // new = a mutation of old: some shared keys (same and changed values),
    // some fresh -- the shared prefix exercises the subtree pruning
    nm = om;
    for (int j = 0; j < n1; ++j)
    {
      const u64 k = (rng() % 2 && !om.empty())
                      ? std::next(om.begin(), rng() % om.size())->first
                      : gen_key(rng);
      switch (rng() % 3)
      {
      case 0: nm[k] = s32_encode((s32)(rng() % 5)); break;   // set/replace
      case 1: nm.erase(k); break;                            // drop (non-monotone)
      case 2: nm[k] = s32_encode(7); break;
      }
    }
    std::vector<u64> oks, nks;
    for (auto& [k, v] : om) oks.push_back(k);
    for (auto& [k, v] : nm) nks.push_back(k);
    const u64 ot = build(A, om, oks);
    const u64 nt = build(A, nm, nks);

    std::vector<std::pair<u64,u64>> expect;
    for (auto& [k, v] : nm)
    {
      auto it = om.find(k);
      if (it == om.end() || it->second != v) expect.push_back({k, v});
    }
    std::sort(expect.begin(), expect.end());
    CHECK(added_of(A, ot, nt) == expect, "foreach_added disagrees with model");

    // identities: no self-diff, everything from empty, nothing into empty
    CHECK(added_of(A, nt, nt).empty(), "foreach_added(t,t) not empty");
    CHECK(added_of(A, A.empty(), nt).size() == nm.size(),
          "foreach_added(empty,t) misses entries");
    CHECK(added_of(A, ot, A.empty()).empty(), "foreach_added(t,empty) not empty");

    // the monotone pair the merge point produces: new = old (+) delta
    LatSpec set_spec(LATSPEC_SET);
    const u64 grown = A.merge_spec(ot, nt, &set_spec);
    std::map<u64,u64> gm = nm;
    for (auto& [k, v] : om)
    {
      auto it = gm.find(k);
      if (it == gm.end()) gm[k] = v;
      else it->second = std::max(it->second, v);   // set-kind leaf join: raw max
    }
    std::vector<std::pair<u64,u64>> gexpect;
    for (auto& [k, v] : gm)
    {
      auto it = om.find(k);
      if (it == om.end() || it->second != v) gexpect.push_back({k, v});
    }
    std::sort(gexpect.begin(), gexpect.end());
    CHECK(added_of(A, ot, grown) == gexpect, "foreach_added wrong on merge ascent");
  }
}

static void reload(CollectionArena& A)
{
  // Simulate value.nodes: dump per-partition in iterator order, re-intern in
  // that order into a fresh arena, and require every id to reproduce.
  CollectionArena B;
  auto table = A.raw();
  std::vector<cnode> all;
  for (u16 p = 0; p < table->getWritePartitions(); ++p)
    for (auto it = table->begin(p); it != table->end(); ++it)
    {
      const cnode& n = *it;
      B.intern4(n.w[0], n.w[1], n.w[2], n.w[3]);
      all.push_back(n);
    }
  u32 mismatches = 0;
  for (auto& n : all)
  {
    const u64 ida = A.intern4(n.w[0], n.w[1], n.w[2], n.w[3]);  // dup: existing id
    const u64 idb = B.intern4(n.w[0], n.w[1], n.w[2], n.w[3]);
    if (ida != idb) ++mismatches;
  }
  CHECK(mismatches == 0, mismatches << " node ids failed to reproduce on reload");
  CHECK(B.freshCount() == all.size(), "reload interned a different node count");
}

int main()
{
  CollectionArena A;

  CHECK(A.empty() == A.empty(), "empty not canonical");
  CHECK(A.size(A.empty()) == 0, "empty not size 0");

  for (u64 seed = 1; seed <= 5; ++seed)
    differential(A, seed, 600);
  identities(A, 42);
  merge_spec_tests(A, 77);
  foreach_added_tests(A, 123, 400);
  concurrency(A);
  reload(A);

  std::cout << (failures ? "FAILED " : "ok ") << checks << " checks, "
            << failures << " failures, " << A.freshCount()
            << " arena nodes" << std::endl;
  return failures ? 1 : 0;
}
