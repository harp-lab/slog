/** Slog execution trace (docs/pausing.md §15)
 *
 * A session-scoped record of what each stratum's fixpoint did, taken at the
 * single-threaded end-of-iteration barrier (EndIterCompletion), where every
 * relation's delta is finalized and interned.  The barrier is the same for
 * both executors and every epoch flavor, so the trace is too.  This header
 * holds the recording's policy -- configuration, sample selection, and the
 * bounded store the `trace-read` verb drains; Database owns the barrier
 * walk that fills it (it alone can render values).
 *
 * Like watches, the trace is debugging state: never saved, never hashed,
 * and delivered only on request (the daemon sends nothing unsolicited,
 * repl.md §6).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

#include "types.h"

#include <algorithm>
#include <deque>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace slog
{

// Defaults for analysis-scale programs (many relations, many iterations,
// large deltas): every relation's counts every iteration, and a small
// coordinated sample of its rows -- larger for the relations under focus.
// Samples are what the caps bound; counts are never dropped.
constexpr u32 trace_default_sample = 8;           // rows per relation, per sign
constexpr u32 trace_focus_sample = 64;
constexpr u32 trace_iteration_sample_cap = 256;   // rows per iteration, all relations
constexpr u64 trace_byte_cap = 16ull << 20;       // retained, unreleased records
// Sample rows preview values three levels deep (writeValCSVAtBoundary's
// render budget): deep analysis values would otherwise dominate the bytes.
constexpr u32 trace_render_depth = 3;

struct TraceConfig
{
  u32 sample = trace_default_sample;   // 0: counts only, no samples at all
  std::set<std::string> focus;
  bool rules = false;                  // per-iteration fire tallies

  u32 sampleFor(const std::string& relation) const
  {
    if (sample == 0) return 0;
    return focus.count(relation) ? std::max(sample, trace_focus_sample)
                                 : sample;
  }
};

// The coordinated-sample hash.  A sample is the k rows with the smallest
// hash, so the hash must be a function of the row's VALUES alone: then the
// same tuple is chosen in every iteration, run and thread count, and can be
// followed across them.  Heap words (strings, bignums, structs,
// collections, sequences) are intern ids, which differ with thread count
// and history, so a heap value contributes a hash of its canonical
// rendering instead (the id-free signature's choice, Database::signatureOf);
// an immediate (int, float) is its own canonical word.  Columns fold through
// the splitmix64 finalizer, which also spreads the result uniformly.
inline u64 traceMix(u64 x)
{
  x += 0x9e3779b97f4a7c15ull;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ull;
  x = (x ^ (x >> 27)) * 0x94d049bb133111ebull;
  return x ^ (x >> 31);
}

inline u64 traceTextHash(const std::string& text)
{
  u64 h = 1469598103934665603ull;            // FNV-1a, 64-bit
  for (unsigned char c : text) { h ^= c; h *= 1099511628211ull; }
  return h;
}

// Bottom-k selection: one comparison per offered row once full.  Ties order
// by kind, so two copies of one row (a counted epoch's separate
// contributions) are interchangeable whichever arrives first.
class TraceSampler
{
public:
  struct Pick { u64 hash; u8 kind; const u64* row; };

  explicit TraceSampler(u32 k) : k(k) {}

  void offer(u64 hash, u8 kind, const u64* row)
  {
    if (picks.size() < k)
    {
      picks.push_back({hash, kind, row});
      std::push_heap(picks.begin(), picks.end(), before);
    }
    else if (k > 0 && before(Pick{hash, kind, row}, picks.front()))
    {
      std::pop_heap(picks.begin(), picks.end(), before);
      picks.back() = {hash, kind, row};
      std::push_heap(picks.begin(), picks.end(), before);
    }
  }

  // The selection, smallest hash first: every prefix is itself a bottom-k.
  std::vector<Pick> take()
  {
    std::sort_heap(picks.begin(), picks.end(), before);
    return std::move(picks);
  }

private:
  static bool before(const Pick& a, const Pick& b)
  {
    return a.hash != b.hash ? a.hash < b.hash : a.kind < b.kind;
  }
  u32 k;
  std::vector<Pick> picks;   // a max-heap until take()
};

// One relation's entry in a trace-iter record: its counts, pre-rendered,
// and its sample rows, which the byte cap may later drop.
struct TraceRel
{
  std::string counts;               // "\"path\" (vid 3) (plus 4) ..."
  std::vector<std::string> sample;  // ("4 5" + rec) ...
  u64 omitted = 0;                  // live rows not in `sample`
};

struct TraceRecord
{
  u64 seq = 0;
  std::string kind;                 // trace-stratum, trace-iter, ...
  std::string fields;               // " (scc 2) (iteration 1)"
  std::vector<TraceRel> rels;       // trace-iter only
  u64 evicted = 0;                  // sample rows the byte cap dropped

  u64 bytes() const
  {
    u64 n = kind.size() + fields.size();
    for (const TraceRel& r : rels)
    {
      n += r.counts.size();
      for (const std::string& s : r.sample) n += s.size();
    }
    return n;
  }

  std::string render() const
  {
    std::string out = "(" + kind + " (seq " + std::to_string(seq) + ")" + fields;
    for (const TraceRel& r : rels)
    {
      out += " (rel " + r.counts + " (sample";
      for (const std::string& s : r.sample) out += " " + s;
      out += ") (sample-omitted " + std::to_string(r.omitted) + "))";
    }
    return out + ")";
  }
};

// The store `trace-read` drains.  Sequence numbers are monotone for the
// daemon's life.  A read from SEQ releases every record before SEQ (the
// client has them), so what is retained is one client's unread span --
// in practice one event, since the session reads after each.  Over the byte
// cap, the oldest retained records lose their samples first; counts stay.
class ExecutionTrace
{
public:
  bool armed() const { return on; }
  const TraceConfig& config() const { return cfg; }
  u64 nextSeq() const { return next_seq; }

  // Arming again replaces the configuration and keeps the records.
  void arm(TraceConfig c) { cfg = std::move(c); on = true; }

  void disarm()
  {
    on = false;
    records.clear();
    bytes = 0;
  }

  void append(TraceRecord r)
  {
    r.seq = next_seq++;
    bytes += r.bytes();
    records.push_back(std::move(r));
    while (bytes > trace_byte_cap && evict_seq < next_seq)
    {
      evict_seq = std::max(evict_seq, records.front().seq);
      TraceRecord& oldest = records[evict_seq++ - records.front().seq];
      for (TraceRel& rel : oldest.rels)
      {
        for (const std::string& s : rel.sample) bytes -= s.size();
        oldest.evicted += rel.sample.size();
        rel.omitted += rel.sample.size();
        rel.sample.clear();
      }
    }
  }

  // Emit every retained record from `from` on, after releasing those
  // before it.  Returns how many sample rows the cap dropped from them.
  template <typename Emit>
  u64 read(u64 from, Emit emit)
  {
    while (!records.empty() && records.front().seq < from)
    {
      bytes -= records.front().bytes();
      records.pop_front();
    }
    u64 dropped = 0;
    for (const TraceRecord& r : records)
    {
      emit(r.render());
      dropped += r.evicted;
    }
    return dropped;
  }

private:
  bool on = false;
  TraceConfig cfg;
  std::deque<TraceRecord> records;
  u64 next_seq = 0;
  u64 bytes = 0;
  u64 evict_seq = 0;   // records before this have no samples left
};

}
