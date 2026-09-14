// Trace-driven simulation of the master index: replays a relation's per-round candidate stream
// (SLOG_DUMP_DELTA blocks: u64 iteration, u64 arity, u64 rows, rows*arity words) through
//   A. today's master: one tlx btree_set per bucket, one insertNew descent per candidate;
//   B. a run-set master: per bucket a list of sorted runs; a round's candidates are radix-sorted
//      (low 32 bits per column when the high halves are constant, else std::sort), duplicates
//      collapse by adjacency, a gallop-merge anti-join against every run drops the ones already
//      present, survivors become a new run; tiered compaction with ratio R and run cap K.
//   H. the hybrid: a btree memtable per bucket takes a round when the bucket receives fewer than
//      T candidates (each candidate first probed against the runs, so memtable and runs stay
//      disjoint); otherwise the memtable is flushed into a run and the round absorbed as in B.
//      The memtable also flushes when it exceeds M rows.  SIM_BLOOM=1 adds a blocked bloom filter
//      (8 bits/key) per run, consulted before any binary search into a run; SIM_BLOOM=lazy builds
//      each run's filter only when a point probe first needs it.
// All three must yield identical survivor counts per round.  Also times a synthetic read side
// after each round: P point probes with keys drawn from the round's candidates, and range walks
// (lower_bound on the first column, walk the group) against each model -- the run-set both as a
// k-way merge (what an order-dependent cursor needs) and as a concatenation of the runs' groups
// (what the plain join probe needs).
//   sim <rel.bin> [R=8] [K=6] [P=0.25] [T=4096] [M=65536]
#include <array>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <string>
#include "../../daemon/tlx/container/btree_set.hpp"
using u64 = uint64_t; using u32 = uint32_t;
static const u64 slog_null = ~0ull;
#define BUCKETS 32
static inline u32 bh(u64 x) { return (u32)(((x) * 0x9E3779B97F4A7C15ull) >> 59); }  // stand-in for the daemon's bucket hash
static double now_ms() { return std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now().time_since_epoch()).count(); }

template <int A> struct Sim {
  using Key = std::array<u64, A>;
  // ---- A: btree master
  std::vector<tlx::btree_set<Key>> trees{BUCKETS};
  // ---- B: run-set master
  struct Bucket { std::vector<std::vector<Key>> runs; std::vector<std::vector<u64>> blooms; u64 copies = 0; u64 max_runs = 0; };
  // SIM_BLOOM=1: a filter is built whenever a run is created or merged.  SIM_BLOOM=lazy: a run gets
  // its filter the first time a point probe needs it (a fat-only workload never builds one).
  static bool bloomOn() { static const bool v = std::getenv("SIM_BLOOM") != nullptr; return v; }
  static bool bloomLazy() { static const bool v = std::getenv("SIM_BLOOM") && std::strcmp(std::getenv("SIM_BLOOM"), "lazy") == 0; return v; }
  static u64 mix(const Key& k) { u64 h = 0x9E3779B97F4A7C15ull; for (int c = 0; c < A; ++c) { h ^= k[c]; h *= 0xBF58476D1CE4E5B9ull; h ^= h >> 31; } return h; }
  // blocked bloom: 8 bits per key, two probes into one 64-bit word chosen by the high hash bits
  static std::vector<u64> buildBloom(const std::vector<Key>& run) {
    size_t words = 1; while (words * 8 < run.size()) words <<= 1;   // 64 bits per word / 8 bits per key = 8 keys per word
    std::vector<u64> b(words, 0);
    for (const Key& k : run) { const u64 h = mix(k); u64& w = b[(h >> 20) & (words - 1)]; w |= (1ull << (h & 63)) | (1ull << ((h >> 6) & 63)); }
    return b;
  }
  static bool bloomMaybe(const std::vector<u64>& b, const Key& k) {
    const u64 h = mix(k); const u64 w = b[(h >> 20) & (b.size() - 1)]; const u64 m = (1ull << (h & 63)) | (1ull << ((h >> 6) & 63)); return (w & m) == m;
  }
  static void pushRun(Bucket& b, std::vector<Key>&& run) {
    if (bloomOn()) b.blooms.push_back(bloomLazy() ? std::vector<u64>() : buildBloom(run));
    b.runs.push_back(std::move(run));
  }
  std::vector<Bucket> bk{BUCKETS};
  // ---- H: hybrid = memtable btree + runs
  struct HBucket { Bucket rb; tlx::btree_set<Key> mem; u64 thin_rounds = 0, fat_rounds = 0, flushes = 0; };
  std::vector<HBucket> hb{BUCKETS};
  u64 R, K, T, M; double P;
  double tA = 0, tB_sort = 0, tB_join = 0, tB_compact = 0, tA_probe = 0, tB_probe = 0, tH_probe = 0;
  double tH_thin = 0, tH_fat = 0, tH_flush = 0, tA_range = 0, tB_range = 0, tC_range = 0, tH_range = 0;
  mutable u64 lazy_builds = 0; u64 range_rows_total = 0, cand_total = 0, newA = 0, newB = 0, newH = 0, probes = 0, ranges = 0, range_rows = 0, mismatch = 0, radix_fallbacks = 0, sorts = 0;
  std::vector<Key> scratch, tmp, out;

  static bool narrow(const std::vector<Key>& v) {   // do all high halves agree per column?
    for (int c = 0; c < A; ++c) { u64 hi = v[0][c] >> 32; for (const Key& k : v) if ((k[c] >> 32) != hi) return false; }
    return true;
  }
  void radix_low32(std::vector<Key>& v) {
    tmp.resize(v.size());
    for (int c = A - 1; c >= 0; --c) for (int shift = 0; shift < 32; shift += 11) {
      size_t cnt[2049]; std::memset(cnt, 0, sizeof cnt);
      for (const Key& k : v) ++cnt[((k[c] >> shift) & 2047) + 1];
      for (int i = 1; i <= 2048; ++i) cnt[i] += cnt[i - 1];
      for (const Key& k : v) tmp[cnt[(k[c] >> shift) & 2047]++] = k;
      v.swap(tmp);
    }
  }
  // survivors of `cand` (sorted unique) not present in `run` (sorted)
  static void antijoin(const std::vector<Key>& cand, const std::vector<Key>& run, std::vector<Key>& out) {
    out.clear(); const Key* r = run.data(); const Key* re = r + run.size();
    for (const Key& c : cand) {
      if (r < re && *r < c) { size_t step = 1; const Key* lo = r; const Key* hi = r + 1;
        while (hi < re && *hi < c) { lo = hi; step <<= 1; hi = (size_t)(re - hi) > step ? hi + step : re; }
        r = std::lower_bound(lo, hi, c); }
      if (r == re || *r != c) out.push_back(c);
    }
  }
  void sort_unique(std::vector<Key>& v) {
    ++sorts;
    if (v.size() >= 2048 && narrow(v)) radix_low32(v); else { std::sort(v.begin(), v.end()); if (v.size() >= 2048) ++radix_fallbacks; }
    v.erase(std::unique(v.begin(), v.end()), v.end());
  }
  void compact(Bucket& b) {
    // tiered: while the newest run is at least 1/R of its predecessor, or there are more than K runs, merge the two newest
    while (b.runs.size() >= 2) {
      auto& newest = b.runs.back(); auto& prev = b.runs[b.runs.size() - 2];
      if (!(newest.size() * R >= prev.size() || b.runs.size() > K)) break;
      std::vector<Key> merged; merged.reserve(prev.size() + newest.size());
      std::merge(prev.begin(), prev.end(), newest.begin(), newest.end(), std::back_inserter(merged));
      b.copies += merged.size();
      b.runs.pop_back(); b.runs.back().swap(merged);
      if (bloomOn()) { b.blooms.pop_back(); b.blooms.back() = bloomLazy() ? std::vector<u64>() : buildBloom(b.runs.back()); }
    }
    b.max_runs = std::max<u64>(b.max_runs, b.runs.size());
  }
  bool containsB(Bucket& b, const Key& k) const {
    if (bloomOn()) { for (size_t i = b.runs.size(); i-- > 0;) { if (b.blooms[i].empty()) { b.blooms[i] = buildBloom(b.runs[i]); ++lazy_builds; }
                       if (bloomMaybe(b.blooms[i], k) && std::binary_search(b.runs[i].begin(), b.runs[i].end(), k)) return true; } return false; }
    for (auto it = b.runs.rbegin(); it != b.runs.rend(); ++it) if (std::binary_search(it->begin(), it->end(), k)) return true;
    return false;
  }
  bool containsH(HBucket& h, const Key& k) const { return h.mem.exists(k) || containsB(h.rb, k); }
  // hybrid absorb of one bucket's candidates; returns the survivor count
  u64 roundH(HBucket& h, std::vector<Key>& cand) {
    if (cand.size() < T) {           // thin: today's path, plus a probe of each run (the memtable and the runs stay disjoint)
      double t = now_ms(); u64 n = 0;
      if (h.rb.runs.empty()) for (const Key& k : cand) n += h.mem.insert(k).second;
      else for (const Key& k : cand) if (!containsB(h.rb, k)) n += h.mem.insert(k).second;
      tH_thin += now_ms() - t; ++h.thin_rounds;
      if (h.mem.size() > M) flushH(h);
      return n;
    }
    if (!h.mem.empty()) flushH(h);   // fat: the memtable becomes a run first, so the anti-join below sees everything as sorted runs
    double t = now_ms();
    sort_unique(cand);
    for (auto& run : h.rb.runs) { antijoin(cand, run, out); cand.swap(out); }
    const u64 n = cand.size();
    if (n) { pushRun(h.rb, std::vector<Key>(cand)); compact(h.rb); }
    tH_fat += now_ms() - t; ++h.fat_rounds;
    return n;
  }
  void flushH(HBucket& h) {          // memtable -> one sorted run (already sorted, disjoint from the runs by the invariant)
    double t = now_ms();
    std::vector<Key> run(h.mem.begin(), h.mem.end()); h.mem.clear();
    pushRun(h.rb, std::move(run)); compact(h.rb); ++h.flushes;
    tH_flush += now_ms() - t;
  }
  // range walk: every tuple whose first column equals k[0] (a bound-prefix probe), summed for a checksum
  u64 rangeA(const Key& k) {
    const auto& tr = trees[bh(k[0])]; Key lo = k; for (int c = 1; c < A; ++c) lo[c] = 0;
    u64 h = 0; for (auto it = tr.lower_bound(lo); it != tr.end() && (*it)[0] == k[0]; ++it) { h += (*it)[A - 1]; ++range_rows; } return h;
  }
  u64 rangeRuns(const Bucket& b, const Key& k) {
    Key lo = k; for (int c = 1; c < A; ++c) lo[c] = 0; u64 h = 0;
    // k-way: collect the cursor of each run, then pop the minimum each step (k <= K+1 so a linear scan of the heads)
    struct Cur { const Key* p; const Key* e; }; Cur cur[16]; int n = 0;
    for (auto& r : b.runs) { const Key* p = std::lower_bound(r.data(), r.data() + r.size(), lo); if (p != r.data() + r.size() && (*p)[0] == k[0]) cur[n++] = { p, r.data() + r.size() }; }
    while (n) { int m = 0; for (int i = 1; i < n; ++i) if (*cur[i].p < *cur[m].p) m = i;
      h += (*cur[m].p)[A - 1]; ++range_rows; ++cur[m].p;
      if (cur[m].p == cur[m].e || (*cur[m].p)[0] != k[0]) cur[m] = cur[--n]; }
    return h;
  }
  // the same walk without the merge: each run's group in turn (what an order-free consumer would do)
  u64 rangeRunsConcat(const Bucket& b, const Key& k) {
    Key lo = k; for (int c = 1; c < A; ++c) lo[c] = 0; u64 h = 0;
    for (auto& r : b.runs) { const Key* e = r.data() + r.size();
      for (const Key* p = std::lower_bound(r.data(), e, lo); p != e && (*p)[0] == k[0]; ++p) h += (*p)[A - 1]; }
    return h;
  }
  u64 rangeH(const HBucket& hbk, const Key& k) {
    u64 h = rangeRuns(hbk.rb, k);     // order is not needed for a checksum; the daemon would merge the memtable cursor in as one more head
    Key lo = k; for (int c = 1; c < A; ++c) lo[c] = 0;
    for (auto it = hbk.mem.lower_bound(lo); it != hbk.mem.end() && (*it)[0] == k[0]; ++it) h += (*it)[A - 1];
    return h;
  }
  void round(const std::vector<Key>& rows) {
    cand_total += rows.size();
    // partition once (both models get the same per-bucket streams)
    std::vector<std::vector<Key>> per(BUCKETS);
    for (const Key& k : rows) per[bh(k[0])].push_back(k);
    // A
    double t = now_ms(); u64 na = 0;
    for (u32 b = 0; b < BUCKETS; ++b) for (const Key& k : per[b]) na += trees[b].insert(k).second;
    tA += now_ms() - t; newA += na;
    // B
    u64 nb = 0;
    for (u32 b = 0; b < BUCKETS; ++b) {
      if (per[b].empty()) continue;
      scratch = per[b];
      t = now_ms();
      sort_unique(scratch);
      tB_sort += now_ms() - t; t = now_ms();
      for (auto& run : bk[b].runs) { antijoin(scratch, run, out); scratch.swap(out); }
      tB_join += now_ms() - t; t = now_ms();
      nb += scratch.size();
      if (!scratch.empty()) { pushRun(bk[b], std::vector<Key>(scratch)); compact(bk[b]); }
      tB_compact += now_ms() - t;
    }
    newB += nb;
    // H
    u64 nh = 0;
    for (u32 b = 0; b < BUCKETS; ++b) if (!per[b].empty()) nh += roundH(hb[b], per[b]);
    newH += nh;
    if (na != nb || na != nh) ++mismatch;
    // read side: probe P * |rows| keys drawn from this round's candidates against both models
    const size_t np = (size_t)(P * rows.size());
    if (np) {
      t = now_ms(); u64 h = 0;
      for (size_t i = 0; i < np; ++i) { const Key& k = rows[(i * 7919) % rows.size()]; h += trees[bh(k[0])].exists(k); }
      tA_probe += now_ms() - t; t = now_ms(); u64 h2 = 0;
      for (size_t i = 0; i < np; ++i) { const Key& k = rows[(i * 7919) % rows.size()]; h2 += containsB(bk[bh(k[0])], k); }
      tB_probe += now_ms() - t; t = now_ms(); u64 h3 = 0;
      for (size_t i = 0; i < np; ++i) { const Key& k = rows[(i * 7919) % rows.size()]; h3 += containsH(hb[bh(k[0])], k); }
      tH_probe += now_ms() - t; probes += np; if (h != h2 || h != h3) ++mismatch;
      // range walks on the first column (bound-prefix probes), capped per round so the read test does not
      // evict the masters between rounds and distort the intern timings
      size_t nr = std::min<size_t>(np, 500);
      t = now_ms(); u64 r1 = 0; range_rows = 0;
      { size_t i = 0; for (; i < nr && range_rows < 50000; ++i) r1 += rangeA(rows[(i * 104729) % rows.size()]); nr = i; }
      const u64 rr = range_rows; tA_range += now_ms() - t; t = now_ms(); u64 r2 = 0; range_rows = 0;
      for (size_t i = 0; i < nr; ++i) r2 += rangeRuns(bk[bh(rows[(i * 104729) % rows.size()][0])], rows[(i * 104729) % rows.size()]);
      tB_range += now_ms() - t; t = now_ms(); u64 r4 = 0;
      for (size_t i = 0; i < nr; ++i) r4 += rangeRunsConcat(bk[bh(rows[(i * 104729) % rows.size()][0])], rows[(i * 104729) % rows.size()]);
      tC_range += now_ms() - t; t = now_ms(); u64 r3 = 0;
      for (size_t i = 0; i < nr; ++i) r3 += rangeH(hb[bh(rows[(i * 104729) % rows.size()][0])], rows[(i * 104729) % rows.size()]);
      tH_range += now_ms() - t; ranges += nr; range_rows = rr; range_rows_total += rr;
      if (r1 != r2 || r1 != r3 || r1 != r4) ++mismatch;
    }
  }
  void report(const char* name, u64 rounds) {
    u64 copies = 0, maxr = 0, runs_now = 0, tuples = 0;
    for (auto& b : bk) { copies += b.copies; maxr = std::max(maxr, b.max_runs); runs_now += b.runs.size(); for (auto& r : b.runs) tuples += r.size(); }
    printf("%s: arity %d rounds %llu candidates %llu new %llu (A %llu, B %llu, mismatched rounds %llu)\n", name, A,
           (unsigned long long)rounds, (unsigned long long)cand_total, (unsigned long long)newB, (unsigned long long)newA, (unsigned long long)newB, (unsigned long long)mismatch);
    printf("  A btree intern      %8.1f ms  (%5.1f ns/cand)\n", tA, tA * 1e6 / cand_total);
    printf("  B run-set absorb    %8.1f ms  (%5.1f ns/cand)  = sort %.1f + antijoin %.1f + compact %.1f;  merge copies %.2fx tuples, max runs/bucket %llu, runs now %.1f/bucket\n",
           tB_sort + tB_join + tB_compact, (tB_sort + tB_join + tB_compact) * 1e6 / cand_total, tB_sort, tB_join, tB_compact,
           tuples ? (double)copies / tuples : 0.0, (unsigned long long)maxr, runs_now / (double)BUCKETS);
    u64 thin = 0, fat = 0, fl = 0, hruns = 0, mem = 0;
    for (auto& h : hb) { thin += h.thin_rounds; fat += h.fat_rounds; fl += h.flushes; hruns += h.rb.runs.size(); mem += h.mem.size(); }
    printf("  H hybrid (T=%llu M=%llu) %8.1f ms  (%5.1f ns/cand)  = thin %.1f + fat %.1f + flush %.1f;  bucket-rounds thin %llu fat %llu, flushes %llu, runs now %.1f/bucket, memtable %.0f rows/bucket\n",
           (unsigned long long)T, (unsigned long long)M, tH_thin + tH_fat + tH_flush, (tH_thin + tH_fat + tH_flush) * 1e6 / cand_total, tH_thin, tH_fat, tH_flush,
           (unsigned long long)thin, (unsigned long long)fat, (unsigned long long)fl, hruns / (double)BUCKETS, mem / (double)BUCKETS);
    if (sorts) printf("  sorts %llu, comparison fallbacks among >=2048-row batches %llu%s, lazy bloom builds %llu\n", (unsigned long long)sorts, (unsigned long long)radix_fallbacks,
                      bloomOn() ? (bloomLazy() ? ", bloom lazy" : ", bloom eager") : "", (unsigned long long)lazy_builds);
    if (probes) printf("  probes %llu: A %.1f ms (%.0f ns) vs B %.1f ms (%.0f ns) vs H %.1f ms (%.0f ns)  B/A %.2fx H/A %.2fx\n", (unsigned long long)probes,
                       tA_probe, tA_probe * 1e6 / probes, tB_probe, tB_probe * 1e6 / probes, tH_probe, tH_probe * 1e6 / probes, tB_probe / tA_probe, tH_probe / tA_probe);
    if (ranges) printf("  ranges %llu (%.1f rows each): A %.1f ms (%.0f ns) vs B merged %.1f ms (%.0f ns) vs B concat %.1f ms (%.0f ns) vs H %.1f ms (%.0f ns)  B/A %.2fx Bconcat/A %.2fx H/A %.2fx\n", (unsigned long long)ranges,
                       range_rows_total / (double)ranges, tA_range, tA_range * 1e6 / ranges, tB_range, tB_range * 1e6 / ranges, tC_range, tC_range * 1e6 / ranges, tH_range, tH_range * 1e6 / ranges,
                       tB_range / tA_range, tC_range / tA_range, tH_range / tA_range);
  }
};

template <int A> void run(FILE* f, const char* name, u64 R, u64 K, double P, u64 T, u64 M) {
  Sim<A> s; s.R = R; s.K = K; s.P = P; s.T = T; s.M = M; u64 rounds = 0;
  std::fseek(f, 0, SEEK_SET);
  u64 hdr[3];
  while (std::fread(hdr, sizeof(u64), 3, f) == 3) {
    if (hdr[1] != (u64)A) { std::fprintf(stderr, "arity changed mid-file\n"); return; }
    std::vector<std::array<u64, A>> rows(hdr[2]);
    if (std::fread(rows.data(), sizeof(u64) * A, hdr[2], f) != hdr[2]) break;
    s.round(rows); ++rounds;
  }
  s.report(name, rounds);
}
int main(int argc, char** argv) {
  if (argc < 2) { std::fprintf(stderr, "usage: sim <rel.bin> [R=8] [K=6] [P=0.25] [T=4096] [M=65536]\n"); return 2; }
  u64 R = argc > 2 ? std::strtoull(argv[2], nullptr, 10) : 8, K = argc > 3 ? std::strtoull(argv[3], nullptr, 10) : 6;
  double P = argc > 4 ? std::atof(argv[4]) : 0.25;
  u64 T = argc > 5 ? std::strtoull(argv[5], nullptr, 10) : 4096, M = argc > 6 ? std::strtoull(argv[6], nullptr, 10) : 65536;
  FILE* f = std::fopen(argv[1], "rb"); if (!f) { std::perror(argv[1]); return 1; }
  u64 hdr[3]; if (std::fread(hdr, sizeof(u64), 3, f) != 3) return 1;
  switch (hdr[1]) { case 1: run<1>(f, argv[1], R, K, P, T, M); break; case 2: run<2>(f, argv[1], R, K, P, T, M); break; case 3: run<3>(f, argv[1], R, K, P, T, M); break;
                    case 4: run<4>(f, argv[1], R, K, P, T, M); break; case 5: run<5>(f, argv[1], R, K, P, T, M); break; case 6: run<6>(f, argv[1], R, K, P, T, M); break;
                    default: std::fprintf(stderr, "arity %llu unsupported\n", (unsigned long long)hdr[1]); return 1; }
  return 0;
}
