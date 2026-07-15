#include "operators.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace slog;

template <u16 A>
static std::array<Index*, bucket_count> make_indices()
{
  std::array<Index*, bucket_count> out{};
  for (u16 b = 0; b < bucket_count; ++b) out[b] = new BTreeIndex<A>();
  return out;
}

static void destroy_indices(std::array<Index*, bucket_count>& xs)
{
  for (Index* x : xs) delete x;
}

static void insert(std::array<Index*, bucket_count>& xs, u64 prefix, u64 value)
{
  static_cast<BTreeIndex<2>*>(xs[buckethash(prefix)])->insert({prefix, value});
}

template <Join3View LV, Join3View RV>
static std::vector<u64> run(std::array<Index*, bucket_count>& lf,
                            std::array<Index*, bucket_count>& ld, u64 lp,
                            std::array<Index*, bucket_count>& rf,
                            std::array<Index*, bucket_count>& rd, u64 rp)
{
  std::vector<u64> out;
  join3<2, 1, LV, 2, 1, RV>(lf.data(), ld.data(), {lp, 0},
                             rf.data(), rd.data(), {rp, 0},
                             [&](u64 cycle) { out.push_back(cycle); });
  return out;
}

static std::set<u64> logical_view(Join3View view, const std::set<u64>& full,
                                  const std::set<u64>& delta)
{
  std::set<u64> out;
  if (view == Join3View::old)
    std::set_difference(full.begin(), full.end(), delta.begin(), delta.end(),
                        std::inserter(out, out.end()));
  else if (view == Join3View::new_)
    std::set_union(full.begin(), full.end(), delta.begin(), delta.end(),
                   std::inserter(out, out.end()));
  else
    out = full;
  return out;
}

template <Join3View LV, Join3View RV>
static bool check_pair(const char* label,
                       std::array<Index*, bucket_count>& lf,
                       std::array<Index*, bucket_count>& ld, u64 lp,
                       std::array<Index*, bucket_count>& rf,
                       std::array<Index*, bucket_count>& rd, u64 rp,
                       const std::set<u64>& lfull,
                       const std::set<u64>& ldelta,
                       const std::set<u64>& rfull,
                       const std::set<u64>& rdelta)
{
  const std::set<u64> left = logical_view(LV, lfull, ldelta);
  const std::set<u64> right = logical_view(RV, rfull, rdelta);
  std::vector<u64> wanted;
  std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                        std::back_inserter(wanted));
  const std::vector<u64> got = run<LV, RV>(lf, ld, lp, rf, rd, rp);
  if (got == wanted) return true;
  std::cerr << label << ": got";
  for (u64 x : got) std::cerr << ' ' << x;
  std::cerr << ", wanted";
  for (u64 x : wanted) std::cerr << ' ' << x;
  std::cerr << '\n';
  return false;
}

static bool fuzz_round(std::mt19937_64& random, u64 lp, u64 rp, u32 round)
{
  auto lf = make_indices<2>();
  auto ld = make_indices<2>();
  auto rf = make_indices<2>();
  auto rd = make_indices<2>();
  std::set<u64> lfull, ldelta, rfull, rdelta;

  std::vector<u64> universe{0, 1, 2, 7, 63, 64, 127,
                            std::numeric_limits<u64>::max()};
  for (u16 i = 0; i < 80; ++i) universe.push_back(random() & 0xffffu);
  std::sort(universe.begin(), universe.end());
  universe.erase(std::unique(universe.begin(), universe.end()), universe.end());

  for (u64 value : universe)
  {
    if ((random() & 3u) == 0) { lfull.insert(value); insert(lf, lp, value); }
    if ((random() & 3u) == 0) { ldelta.insert(value); insert(ld, lp, value); }
    if ((random() & 3u) == 0) { rfull.insert(value); insert(rf, rp, value); }
    if ((random() & 3u) == 0) { rdelta.insert(value); insert(rd, rp, value); }
  }

  // Rows adjacent in sort order but outside the selected prefixes exercise
  // both range termination and bucket collisions.
  for (u64 value : {u64{0}, u64{9}, std::numeric_limits<u64>::max()})
  {
    insert(lf, lp + 1, value);
    insert(ld, lp + 1, value);
    insert(rf, rp + 1, value);
    insert(rd, rp + 1, value);
  }

  const std::string tag = "fuzz round " + std::to_string(round);
  bool ok = true;
  ok &= check_pair<Join3View::full, Join3View::full>(tag.c_str(), lf, ld, lp, rf, rd, rp, lfull, ldelta, rfull, rdelta);
  ok &= check_pair<Join3View::full, Join3View::old>(tag.c_str(), lf, ld, lp, rf, rd, rp, lfull, ldelta, rfull, rdelta);
  ok &= check_pair<Join3View::full, Join3View::new_>(tag.c_str(), lf, ld, lp, rf, rd, rp, lfull, ldelta, rfull, rdelta);
  ok &= check_pair<Join3View::old, Join3View::full>(tag.c_str(), lf, ld, lp, rf, rd, rp, lfull, ldelta, rfull, rdelta);
  ok &= check_pair<Join3View::old, Join3View::old>(tag.c_str(), lf, ld, lp, rf, rd, rp, lfull, ldelta, rfull, rdelta);
  ok &= check_pair<Join3View::old, Join3View::new_>(tag.c_str(), lf, ld, lp, rf, rd, rp, lfull, ldelta, rfull, rdelta);
  ok &= check_pair<Join3View::new_, Join3View::full>(tag.c_str(), lf, ld, lp, rf, rd, rp, lfull, ldelta, rfull, rdelta);
  ok &= check_pair<Join3View::new_, Join3View::old>(tag.c_str(), lf, ld, lp, rf, rd, rp, lfull, ldelta, rfull, rdelta);
  ok &= check_pair<Join3View::new_, Join3View::new_>(tag.c_str(), lf, ld, lp, rf, rd, rp, lfull, ldelta, rfull, rdelta);

  destroy_indices(lf); destroy_indices(ld);
  destroy_indices(rf); destroy_indices(rd);
  return ok;
}

int main()
{
  std::mt19937_64 random(0x5b10'c0de'3ULL);
  bool ok = true;

  // Cover every physical bucket as a selected left prefix, then exercise
  // randomized sparse/dense overlap and all nine logical view pairs.
  std::array<bool, bucket_count> seen{};
  u16 covered = 0;
  for (u64 prefix = 0; covered < bucket_count; ++prefix)
  {
    const u16 bucket = buckethash(prefix);
    if (seen[bucket]) continue;
    seen[bucket] = true;
    ++covered;
    ok &= fuzz_round(random, prefix, prefix + 100000, covered);
  }
  for (u32 round = covered; round < 250 && ok; ++round)
    ok &= fuzz_round(random, random(), random(), round);

  // Adversarial gap: the hybrid cursor must seek rather than walk ten
  // thousand keys to discover that the opposite side starts at one million.
  auto gf = make_indices<2>();
  auto gd = make_indices<2>();
  auto hf = make_indices<2>();
  auto hd = make_indices<2>();
  for (u64 value = 0; value < 10000; ++value) insert(gf, 30, value);
  insert(hf, 40, 1000000);
  ok &= run<Join3View::full, Join3View::full>(gf, gd, 30, hf, hd, 40).empty();
  destroy_indices(gf); destroy_indices(gd);
  destroy_indices(hf); destroy_indices(hd);

  if (!ok) return 1;
  std::cout << "wcoj3 operator tests passed\n";
  return 0;
}
