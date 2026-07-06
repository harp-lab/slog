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
  concurrency(A);
  reload(A);

  std::cout << (failures ? "FAILED " : "ok ") << checks << " checks, "
            << failures << " failures, " << A.freshCount()
            << " arena nodes" << std::endl;
  return failures ? 1 : 0;
}
