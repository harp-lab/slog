// Trace-driven simulation of the master index: replays a relation's per-round candidate stream
// (SLOG_DUMP_DELTA blocks: u64 iteration, u64 arity, u64 rows, rows*arity words) through
//   A. today's master: one tlx btree_set per bucket, one insertNew descent per candidate;
//   B. a run-set master: per bucket a list of sorted runs; a round's candidates are radix-sorted
//      (low 32 bits per column when the high halves are constant, else std::sort), duplicates
//      collapse by adjacency, a gallop-merge anti-join against every run drops the ones already
//      present, survivors become a new run; tiered compaction with ratio R and run cap K.
// Both must yield identical survivor counts per round.  Also times a synthetic read side after
// each round: P point probes with keys drawn from the round's candidates against each model.
//   sim <rel.bin> [R=8] [K=6] [P=0.25]
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
  struct Bucket { std::vector<std::vector<Key>> runs; u64 copies = 0; u64 max_runs = 0; };
  std::vector<Bucket> bk{BUCKETS};
  u64 R, K; double P;
  double tA = 0, tB_sort = 0, tB_join = 0, tB_compact = 0, tA_probe = 0, tB_probe = 0;
  u64 cand_total = 0, newA = 0, newB = 0, probes = 0, mismatch = 0;
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
  void compact(Bucket& b) {
    // tiered: while the newest run is at least 1/R of its predecessor, or there are more than K runs, merge the two newest
    while (b.runs.size() >= 2) {
      auto& newest = b.runs.back(); auto& prev = b.runs[b.runs.size() - 2];
      if (!(newest.size() * R >= prev.size() || b.runs.size() > K)) break;
      std::vector<Key> merged; merged.reserve(prev.size() + newest.size());
      std::merge(prev.begin(), prev.end(), newest.begin(), newest.end(), std::back_inserter(merged));
      b.copies += merged.size();
      b.runs.pop_back(); b.runs.back().swap(merged);
    }
    b.max_runs = std::max<u64>(b.max_runs, b.runs.size());
  }
  bool containsB(const Bucket& b, const Key& k) const {
    for (auto it = b.runs.rbegin(); it != b.runs.rend(); ++it) if (std::binary_search(it->begin(), it->end(), k)) return true;
    return false;
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
      if (narrow(scratch)) radix_low32(scratch); else std::sort(scratch.begin(), scratch.end());
      scratch.erase(std::unique(scratch.begin(), scratch.end()), scratch.end());
      tB_sort += now_ms() - t; t = now_ms();
      for (auto& run : bk[b].runs) { antijoin(scratch, run, out); scratch.swap(out); }
      tB_join += now_ms() - t; t = now_ms();
      nb += scratch.size();
      if (!scratch.empty()) { bk[b].runs.push_back(scratch); compact(bk[b]); }
      tB_compact += now_ms() - t;
    }
    newB += nb;
    if (na != nb) ++mismatch;
    // read side: probe P * |rows| keys drawn from this round's candidates against both models
    const size_t np = (size_t)(P * rows.size());
    if (np) {
      t = now_ms(); u64 h = 0;
      for (size_t i = 0; i < np; ++i) { const Key& k = rows[(i * 7919) % rows.size()]; h += trees[bh(k[0])].exists(k); }
      tA_probe += now_ms() - t; t = now_ms(); u64 h2 = 0;
      for (size_t i = 0; i < np; ++i) { const Key& k = rows[(i * 7919) % rows.size()]; h2 += containsB(bk[bh(k[0])], k); }
      tB_probe += now_ms() - t; probes += np; if (h != h2) ++mismatch;
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
    if (probes) printf("  probes %llu: A %.1f ms (%.0f ns) vs B %.1f ms (%.0f ns)  ratio %.2fx\n", (unsigned long long)probes, tA_probe, tA_probe * 1e6 / probes, tB_probe, tB_probe * 1e6 / probes, tB_probe / tA_probe);
  }
};

template <int A> void run(FILE* f, const char* name, u64 R, u64 K, double P) {
  Sim<A> s; s.R = R; s.K = K; s.P = P; u64 rounds = 0;
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
  if (argc < 2) { std::fprintf(stderr, "usage: sim <rel.bin> [R=8] [K=6] [P=0.25]\n"); return 2; }
  u64 R = argc > 2 ? std::strtoull(argv[2], nullptr, 10) : 8, K = argc > 3 ? std::strtoull(argv[3], nullptr, 10) : 6;
  double P = argc > 4 ? std::atof(argv[4]) : 0.25;
  FILE* f = std::fopen(argv[1], "rb"); if (!f) { std::perror(argv[1]); return 1; }
  u64 hdr[3]; if (std::fread(hdr, sizeof(u64), 3, f) != 3) return 1;
  switch (hdr[1]) { case 1: run<1>(f, argv[1], R, K, P); break; case 2: run<2>(f, argv[1], R, K, P); break; case 3: run<3>(f, argv[1], R, K, P); break;
                    case 4: run<4>(f, argv[1], R, K, P); break; case 5: run<5>(f, argv[1], R, K, P); break; case 6: run<6>(f, argv[1], R, K, P); break;
                    default: std::fprintf(stderr, "arity %llu unsupported\n", (unsigned long long)hdr[1]); return 1; }
  return 0;
}
