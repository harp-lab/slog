/** Packed derivation-counter unit tests (docs/incremental.md §6.1/§8B, M0).
 *
 * Standalone binary; not part of the golden suite.  Build + run:
 *   clang++ -O2 -Wall -std=c++20 -pthread -Idaemon tests/counts-tests.cpp -o build/counts-tests -lgmp
 *   ./build/counts-tests
 *
 * Covers:
 *   - pack/unpack round-trips over the input|nonrec|rec fields, including
 *     both field maxima and the zero word;
 *   - cnt_add arithmetic: signed contributions, input-bit preservation,
 *     presence transitions (present <-> absent at exactly the §8B.5
 *     predicate);
 *   - under/overflow are LOUD FATALS (forked children; exit code checked)
 *     in the assertion-oriented primitive, while M1's signed try-fold reports
 *     the same failures recoverably without saturation;
 *   - the sidecar index shape: BTreeMapIndex<KA> driven directly (insert2 +
 *     cnt_add read-modify-write, the counting emit's access pattern),
 *     forEach materialisation of key+counter rows, per-bucket independence
 *     under the buckethash(key[0]) convention.
 */

#include <iostream>
#include <string>

// daemon.h establishes the daemon's internal include order (task/database/
// oracle interdependencies); counts.h and index.h ride in through it.
#include "daemon.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#include <vector>
#include <map>
#include <random>

using namespace slog;

// The arity ladders live out-of-line in slogd.cpp (fast-compile §7.1); this
// standalone binary provides its own, exactly as the daemon does.
namespace slog
{
Index* makeIndex(u16 arity)
{
  return makeIndexRec<max_daemon_arity>(arity);
}
Index* makeMapIndex(u16 keyarity, u32 kind, bool hf, u64 fw, bool hc, u64 cw,
                    const LatSpec* spec, CollectionArena* arena)
{
  return makeMapIndexRec<max_daemon_arity>(keyarity, kind, hf, fw, hc, cw,
                                           spec, arena);
}
}

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

// Run f in a forked child with stdout silenced; true iff it exited with
// code 1 (slog::fatal's exit path).
static bool dies_fatally(void (*f)())
{
  pid_t pid = fork();
  if (pid == 0)
  {
    int devnull = open("/dev/null", O_WRONLY);
    dup2(devnull, 1);
    f();
    _exit(0); // reached only if f did NOT fatal
  }
  int status = 0;
  waitpid(pid, &status, 0);
  return WIFEXITED(status) && WEXITSTATUS(status) == 1;
}

static void pack_tests()
{
  CHECK(cnt_pack(false, 0, 0) == 0, "zero word is all-zero");
  CHECK(!cnt_present(0), "zero word is absent");

  for (u64 nr : {(u64)0, (u64)1, (u64)7, cnt_nonrec_max})
    for (u64 rc : {(u64)0, (u64)1, (u64)9, cnt_rec_max})
      for (bool in : {false, true})
      {
        u64 w = cnt_pack(in, nr, rc);
        CHECK(cnt_input(w) == in, "input round-trip");
        CHECK(cnt_nonrec(w) == nr, "nonrec round-trip");
        CHECK(cnt_rec(w) == rc, "rec round-trip");
        CHECK(cnt_present(w) == (in || nr + rc > 0), "presence predicate");
      }

  u64 w = cnt_pack(false, 3, 5);
  CHECK(cnt_input(cnt_set_input(w)), "set_input sets");
  CHECK(cnt_nonrec(cnt_set_input(w)) == 3 && cnt_rec(cnt_set_input(w)) == 5,
        "set_input leaves counters");
  CHECK(!cnt_input(cnt_clear_input(cnt_set_input(w))), "clear_input clears");

  // The input bit alone is presence (§8B.5: direct root/API/import support
  // is input=1,(0,0)).
  CHECK(cnt_present(cnt_pack(true, 0, 0)), "input-only presence");
}

static void add_tests()
{
  u64 w = 0;
  w = cnt_add(w, 1, 0);
  w = cnt_add(w, 1, 0);
  w = cnt_add(w, 0, 3);
  CHECK(cnt_nonrec(w) == 2 && cnt_rec(w) == 3, "increments accumulate");
  w = cnt_add(w, -2, -2);
  CHECK(cnt_nonrec(w) == 0 && cnt_rec(w) == 1, "decrements apply");
  CHECK(cnt_present(w), "still present at (0,1)");
  w = cnt_add(w, 0, -1);
  CHECK(!cnt_present(w), "absent at (0,0) without input");

  // The input bit rides through arithmetic untouched, both values.
  u64 wi = cnt_add(cnt_pack(true, 1, 1), -1, -1);
  CHECK(cnt_input(wi) && cnt_present(wi), "input bit preserved; input-only present");
  u64 wn = cnt_add(cnt_pack(false, 1, 1), 1, 1);
  CHECK(!cnt_input(wn), "clear input bit stays clear");

  // Field maxima are storable and exactly representable.
  u64 wm = cnt_add(cnt_pack(false, cnt_nonrec_max - 1, cnt_rec_max - 1), 1, 1);
  CHECK(cnt_nonrec(wm) == cnt_nonrec_max && cnt_rec(wm) == cnt_rec_max,
        "counters reach field maxima");

  // cnt_apply (the counting tasks' fold, M0.2): inputs SET the bit --
  // idempotent set semantics, never arithmetic (§8B.5) -- and the
  // derivation kinds bump exactly their own counter.
  u64 wa = cnt_apply(0, cnt_kind_input);
  CHECK(cnt_input(wa) && cnt_nonrec(wa) == 0 && cnt_rec(wa) == 0,
        "apply input sets the bit only");
  CHECK(cnt_apply(wa, cnt_kind_input) == wa, "re-applying input is a no-op");
  wa = cnt_apply(cnt_apply(wa, cnt_kind_nonrec), cnt_kind_rec);
  CHECK(cnt_input(wa) && cnt_nonrec(wa) == 1 && cnt_rec(wa) == 1,
        "apply nonrec/rec bump their counters");
  // a kind-less (set-semantics) batch reaching a counting task is a
  // flavor mix-up: loud fatal
  CHECK(dies_fatally([]() { (void)cnt_apply(0, cnt_kind_none); }),
        "apply on a kind-less batch is fatal");
}

// M1's maintenance fold is recoverable: signed arithmetic reports failure
// without publishing a wrapped/saturated word.  The driver can then preserve
// authoritative set content, invalidate the count cache, and recount.
static void signed_try_tests()
{
  u64 out = 99;
  CHECK(cnt_try_apply_signed(0, cnt_kind_input, 1, out)
        && cnt_input(out), "signed input addition sets direct support");
  CHECK(cnt_try_apply_signed(cnt_pack(true, 2, 3), cnt_kind_input, -1, out)
        && !cnt_input(out) && cnt_nonrec(out) == 2 && cnt_rec(out) == 3,
        "signed input removal preserves rule support");

  CHECK(cnt_try_apply_signed(cnt_pack(false, 2, 3), cnt_kind_nonrec, 1, out)
        && cnt_nonrec(out) == 3 && cnt_rec(out) == 3,
        "signed nonrec addition changes only nonrec");
  CHECK(cnt_try_apply_signed(cnt_pack(false, 2, 3), cnt_kind_rec, 1, out)
        && cnt_nonrec(out) == 2 && cnt_rec(out) == 4,
        "signed rec addition changes only rec");
  CHECK(cnt_try_apply_signed(cnt_pack(false, 2, 3), cnt_kind_nonrec, -1, out)
        && cnt_nonrec(out) == 1 && cnt_rec(out) == 3,
        "signed nonrec decrement succeeds in range");
  CHECK(cnt_try_apply_signed(cnt_pack(false, 2, 3), cnt_kind_rec, -1, out)
        && cnt_nonrec(out) == 2 && cnt_rec(out) == 2,
        "signed rec decrement succeeds in range");

  CHECK(!cnt_try_apply_signed(0, cnt_kind_nonrec, -1, out),
        "recoverable nonrec underflow is refused");
  CHECK(!cnt_try_apply_signed(0, cnt_kind_rec, -1, out),
        "recoverable rec underflow is refused");
  CHECK(!cnt_try_apply_signed(cnt_pack(false, cnt_nonrec_max, 0),
                              cnt_kind_nonrec, 1, out),
        "recoverable nonrec overflow is refused");
  CHECK(!cnt_try_apply_signed(cnt_pack(false, 0, cnt_rec_max),
                              cnt_kind_rec, 1, out),
        "recoverable rec overflow is refused");
  CHECK(!cnt_try_apply_signed(0, cnt_kind_rec, 0, out),
        "zero sign is refused");
  CHECK(!cnt_try_apply_signed(0, cnt_kind_premise, 1, out),
        "premise rows are not support contributions");
  CHECK(!cnt_try_apply_signed(0, cnt_kind_none, 1, out),
        "kind-less rows are not support contributions");
}

static void fatal_tests()
{
  CHECK(dies_fatally(+[]() { (void)cnt_add(cnt_pack(false, 0, 5), -1, 0); }),
        "nonrec underflow fatals");
  CHECK(dies_fatally(+[]() { (void)cnt_add(cnt_pack(false, 5, 0), 0, -1); }),
        "rec underflow fatals");
  CHECK(dies_fatally(+[]() { (void)cnt_add(cnt_pack(false, cnt_nonrec_max, 0), 1, 0); }),
        "nonrec overflow fatals");
  CHECK(dies_fatally(+[]() { (void)cnt_add(cnt_pack(false, 0, cnt_rec_max), 0, 1); }),
        "rec overflow fatals");
  CHECK(dies_fatally(+[]() { (void)cnt_pack(false, cnt_nonrec_max + 1, 0); }),
        "cnt_pack overflow fatals");
  CHECK(!dies_fatally(+[]() { (void)cnt_add(cnt_pack(true, 1, 1), -1, -1); }),
        "legal decrement does not fatal");
}

// The counting emit's access pattern against the sidecar shape: a
// BTreeMapIndex<KA> per bucket, keys routed by buckethash(key[0]), packed
// counter words maintained by insert2 + cnt_add read-modify-write.
// Differential against a std::map reference.
static void sidecar_tests()
{
  constexpr u16 KA = 3;
  std::vector<BTreeMapIndex<KA>*> buckets;
  for (u32 b = 0; b < bucket_count; ++b)
    buckets.push_back(new BTreeMapIndex<KA>());

  std::map<std::array<u64, KA>, u64> ref;
  std::mt19937_64 rng(20260712);
  auto contribute = [&](const std::array<u64, KA>& k, s64 dn, s64 dr)
  {
    auto* idx = buckets[buckethash(k[0])];
    auto r = idx->tree.insert2(k, cnt_pack(false, 0, 0));
    r.first->second = cnt_add(r.first->second, dn, dr);
    u64& rw = ref.try_emplace(k, 0).first->second;
    rw = cnt_add(rw, dn, dr);
  };

  // Random positive contributions over a keyspace that spans buckets, then
  // exact negation of a random half (the +/- cancellation DRed^c leans on).
  std::vector<std::array<u64, KA>> keys;
  for (u64 i = 0; i < 512; ++i)
    keys.push_back({rng() % 97, rng() % 13, rng()});
  std::map<std::array<u64, KA>, std::pair<s64, s64>> given;
  for (u64 i = 0; i < 4096; ++i)
  {
    auto& k = keys[rng() % keys.size()];
    s64 dn = (s64)(rng() % 3), dr = (s64)(rng() % 3);
    contribute(k, dn, dr);
    auto& g = given.try_emplace(k, std::make_pair(0, 0)).first->second;
    g.first += dn;
    g.second += dr;
  }
  for (auto& [k, g] : given)
    if (rng() % 2 == 0)
      contribute(k, -g.first, -g.second);

  // Differential: every stored word matches the reference model.
  u64 stored = 0;
  bool all_match = true, buckets_right = true;
  for (u32 b = 0; b < bucket_count; ++b)
    for (auto it = buckets[b]->tree.begin(); it != buckets[b]->tree.end(); ++it)
    {
      ++stored;
      if (buckethash(it->first[0]) != b) buckets_right = false;
      auto rit = ref.find(it->first);
      if (rit == ref.end() || rit->second != it->second) all_match = false;
    }
  CHECK(stored == ref.size(), "sidecar covers exactly the contributed keys");
  CHECK(all_match, "every packed word matches the reference model");
  CHECK(buckets_right, "keys land in buckethash(key[0])'s bucket");

  // forEach materialises key + counter word as one KA+1-wide row (the
  // BTreeMapIndex cold-path contract) -- what a future count oracle dump
  // would read.
  u64 seen = 0;
  bool rows_match = true;
  for (u32 b = 0; b < bucket_count; ++b)
    buckets[b]->forEach([&](const u64* row)
    {
      ++seen;
      std::array<u64, KA> k = {row[0], row[1], row[2]};
      auto rit = ref.find(k);
      if (rit == ref.end() || rit->second != row[KA]) rows_match = false;
    });
  CHECK(seen == ref.size(), "forEach visits every counted key once");
  CHECK(rows_match, "forEach rows carry the counter word last");

  // Structs key counts by id alone (§6.1): the KA=1 shape.
  BTreeMapIndex<1> ids;
  std::array<u64, 1> id = {intern_encode(3, 42)};
  auto r = ids.tree.insert2(id, cnt_pack(false, 0, 0));
  r.first->second = cnt_add(r.first->second, 1, 2);
  r = ids.tree.insert2(id, cnt_pack(false, 0, 0));
  CHECK(!r.second && cnt_nonrec(r.first->second) == 1 && cnt_rec(r.first->second) == 2,
        "id-keyed sidecar: same id, one entry, counters intact");

  for (auto* b : buckets)
    delete b;
}

// The Relation-level sidecar API (database.h): lazy + idempotent
// materialisation, the key-arity rule, and the "contents gone => counts
// gone" invariant (§6.1: a count map covers exactly its live tuples).
static void relation_tests()
{
  Relation r("cnt_probe", 3, 0);
  CHECK(r.countKeyArity() == 3, "tables key counts by the full tuple");
  CHECK(!r.isCounted() && r.getCountSidecar() == nullptr,
        "born uncounted with no sidecar");

  Index** sc = r.ensureCountSidecar();
  CHECK(sc != nullptr, "ensure materialises");
  CHECK(r.ensureCountSidecar() == sc, "ensure is idempotent");

  // Drive it exactly as the counting emit will: typed access into the
  // buckethash(key[0]) bucket.
  std::array<u64, 3> k = {7, 8, 9};
  auto* idx = static_cast<BTreeMapIndex<3>*>(sc[buckethash(k[0])]);
  auto ins = idx->tree.insert2(k, cnt_pack(false, 0, 0));
  ins.first->second = cnt_add(ins.first->second, 1, 0);
  r.setCounted(true);
  CHECK(r.isCounted(), "counted state sticks");

  // clearContents drops count state with the tuples.
  r.clearContents();
  CHECK(!r.isCounted() && r.getCountSidecar() == nullptr,
        "clearContents drops sidecar and counted state");

  Relation s("cnt_struct_probe", 4, 7);
  CHECK(s.countKeyArity() == 1, "structs key counts by id alone");
}

int main()
{
  pack_tests();
  add_tests();
  signed_try_tests();
  fatal_tests();
  sidecar_tests();
  relation_tests();

  std::cout << "counts-tests: " << (checks - failures) << "/" << checks
            << " checks passed" << std::endl;
  return failures == 0 ? 0 : 1;
}
