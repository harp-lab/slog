/** Slog External Oracles (docs/smt.md)
 *
 * Generic infrastructure for oracle-backed demand relations: a demand
 * relation declared `extern <oracle> (f in) int` has NO in-language answer
 * rules -- a daemon-side Oracle computes each answer.  The compiler desugars
 * the declaration exactly like `demand` (the interned demand struct `f` plus
 * the answer table `f_ans`), and the generated stratum plugin calls
 * Daemon::bindOracle for every stratum that writes the demand struct, which
 * registers two read-phase tasks:
 *
 *   OracleDispatchTask -- scans the demand relation's delta (ids are final:
 *     InternStructTask assigned them in the PREVIOUS iteration's intern
 *     phase, and read-phase indices are immutable, so decoding the payload
 *     value here is race-free).  Each not-yet-answered demand is serialized
 *     into a self-contained request and submitted to the worker pool (or
 *     answered eagerly, e.g. the mock SMT backend).  The `answered` set is
 *     re-seeded from the answer table's delta each call, so iteration-0
 *     reloads and persisted answers are never re-solved.
 *
 *   OracleHarvestTask -- drains completed answers and emits (demand-id,
 *     s32-code) rows into the answer table through the ordinary
 *     sendBatch -> finalize -> InternTask path, exactly like a rule head.
 *     Answers are ordinary facts: they persist, reload, and replay like
 *     inputs discovered during evaluation.
 *
 * Fixpoint integration (database.h): the registry implements ExternalWork;
 * EndIterCompletion refuses ACT_FIXPOINT while requests are outstanding,
 * instead blocking (bounded by the run budget) for the next completion and
 * continuing the iteration loop so the harvest task can emit it.  Solver
 * work overlaps rule evaluation; an empty waiting iteration costs only the
 * barriers.
 *
 * Threading contract: dispatch and harvest are single Task objects (each
 * claimed by one worker per phase), and both run in phase_read; `answered`
 * is touched only by dispatch, per-binding `done` queues are mutex-guarded,
 * and the shared counters are atomics.  Oracle::solve runs on detached
 * worker threads and must not touch the Database -- everything it needs is
 * baked into the request string at dispatch time.
 *
 * Copyright (C) Thomas Gilray, et al., 2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

#include "database.h"

#include <condition_variable>
#include <deque>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace slog
{

class OracleRegistry;
struct OracleBinding;

// What an oracle answers with: a plain int code word, or a string->int map
// (docs/smt.md §13: solver models).  A result is a RECIPE, not a value --
// pool threads must not touch the Database, so string interning and arena
// puts happen in the harvest task (read phase, both interners are
// thread-safe there; prims intern strings/cnodes mid-read already).
struct OracleResult
{
  s32 code = 0;                                        // the code word
  bool is_map = false;                                 // materialize as cmap
  // String-keyed payload; values are canonical decimal strings so solver
  // bignums survive to encodeIntLiteral intact (docs/primitives.md §14.7)
  std::vector<std::pair<std::string, std::string>> entries;
  // Raw-WORD-keyed payload (unsat cores: the member formulas' struct refs,
  // valid within this run's database; carried through the request text and
  // back, never dereferenced off the stratum).
  std::vector<std::pair<u64, s64>> word_entries;
};

// One external answerer.  serialize() runs on a stratum worker inside the
// read phase (Database reads are safe); solve() runs on a pool thread with
// NO Database access; solveEager() lets a backend answer at dispatch time
// (the deterministic mock solver), still flowing through the done-queue and
// harvest so the full fact path is exercised.
class Oracle
{
public:
  virtual ~Oracle() = default;
  // Serialize the demand's payload value into a self-contained request.
  // False + err when the value is unserializable; the dispatcher then
  // records an (error (smt_bad_formula ...)) fact and answers unknownResult.
  virtual bool serialize(Database* db, u64 value, std::string& out, std::string& err) = 0;
  // Answer now, on the stratum worker (cheap, deterministic backends only).
  virtual bool solveEager(Database* db, u64 value, OracleResult& out)
  { (void)db; (void)value; (void)out; return false; }
  // Answer a serialized request on a pool thread.
  virtual OracleResult solve(const std::string& request) = 0;
  // The shape of "no answer" for this oracle (map-shaped oracles must
  // answer a map even on failure, so lib wrappers can destructure).
  virtual OracleResult unknownResult() { return OracleResult{}; }
};

// The binding of one extern demand relation to its oracle: the dispatch-side
// answered set and the completion queue the harvest task drains.
struct OracleBinding
{
  std::string oracle_name;
  std::string demand_rel;
  std::string ans_rel;
  Oracle* oracle = nullptr;

  // Demand ids answered, in flight, or seen in the answer table's delta.
  // Dispatch-task-only (one task, one phase at a time): no lock.
  std::unordered_set<u64> answered;

  // Completed (id, result) answers awaiting harvest.
  std::mutex done_mu;
  std::vector<std::pair<u64, OracleResult>> done;

  // Warn once per distinct serialize-failure reason (then answer unknown).
  std::unordered_set<std::string> warned;

  void pushDone(u64 id, OracleResult r)
  {
    std::lock_guard<std::mutex> lk(done_mu);
    done.emplace_back(id, std::move(r));
  }
  void drainInto(std::vector<std::pair<u64, OracleResult>>& out)
  {
    std::lock_guard<std::mutex> lk(done_mu);
    out.swap(done);
    done.clear();
  }
};

// One submitted request.
struct OracleJob
{
  OracleBinding* binding;
  u64 id;
  std::string request;
};

// The daemon-wide oracle registry: named Oracle implementations, per-relation
// bindings, the job queue + worker pool, and the ExternalWork face the
// fixpoint machinery consults (database.h EndIterCompletion).
class OracleRegistry : public ExternalWork
{
  std::unordered_map<std::string, Oracle*> oracles;
  std::unordered_map<std::string, OracleBinding*> bindings;  // by demand rel

  std::mutex mu;                       // guards jobs + worker spawn + shutdown
  std::condition_variable job_cv;      // workers wait for jobs
  std::condition_variable done_cv;     // the fixpoint wait (waitHarvestable)
  std::deque<OracleJob> jobs;
  std::vector<std::thread> workers;
  bool shutdown_flag = false;

  // outstanding: submitted (or eagerly completed) and not yet HARVESTED into
  // facts -- gates fixpoint.  undrained: completed and not yet harvested --
  // gates the end-of-iteration wait.
  std::atomic<u64> outstanding_{0};
  std::atomic<u64> undrained_{0};

  u32 pool_size;

  static u64 envU64(const char* name, u64 fallback)
  {
    const char* v = std::getenv(name);
    if (v == nullptr || v[0] == '\0') return fallback;
    return (u64)std::strtoull(v, nullptr, 10);
  }

  // Lazily spawn the pool on first submit (callers hold `mu`).
  void ensureWorkers()
  {
    if (!workers.empty()) return;
    for (u32 i = 0; i < pool_size; ++i)
      workers.emplace_back([this]() { workerLoop(); });
  }

  void workerLoop()
  {
    for (;;)
    {
      OracleJob job;
      {
        std::unique_lock<std::mutex> lk(mu);
        job_cv.wait(lk, [this]() { return shutdown_flag || !jobs.empty(); });
        if (shutdown_flag) return;
        job = std::move(jobs.front());
        jobs.pop_front();
      }
      OracleResult res;
      // An escaping exception in a std::thread terminates the process;
      // a failing backend must degrade to unknown instead.
      try { res = job.binding->oracle->solve(job.request); }
      catch (...) { res = job.binding->oracle->unknownResult(); }
      job.binding->pushDone(job.id, std::move(res));
      undrained_.fetch_add(1);
      done_cv.notify_all();
    }
  }

public:
  OracleRegistry()
  {
    pool_size = (u32)envU64("SLOG_ORACLE_PROCS", 4);
    if (pool_size == 0) pool_size = 1;
  }

  ~OracleRegistry() override
  {
    {
      std::lock_guard<std::mutex> lk(mu);
      shutdown_flag = true;
    }
    job_cv.notify_all();
    for (std::thread& w : workers)
      if (w.joinable()) w.join();
    for (auto& kv : bindings) delete kv.second;
    for (auto& kv : oracles) delete kv.second;
  }

  // Register a named oracle implementation (Daemon ctor).  Takes ownership.
  void registerOracle(const std::string& name, Oracle* o)
  {
    if (oracles.count(name)) fatal("Oracle registered twice: " + name);
    oracles[name] = o;
  }

  // Find-or-create the binding for an extern demand relation.  Called from
  // every stratum plugin that writes the demand struct; the binding (and its
  // answered set) persists across strata and hot swaps.
  OracleBinding* bind(const std::string& oracle_name,
                      const std::string& demand_rel,
                      const std::string& ans_rel)
  {
    auto it = bindings.find(demand_rel);
    if (it != bindings.end())
    {
      if (it->second->oracle_name != oracle_name || it->second->ans_rel != ans_rel)
        fatal("Oracle relation " + demand_rel + " re-bound inconsistently");
      return it->second;
    }
    auto oit = oracles.find(oracle_name);
    if (oit == oracles.end())
      fatal("Unknown oracle \"" + oracle_name + "\" for extern relation " + demand_rel);
    OracleBinding* b = new OracleBinding();
    b->oracle_name = oracle_name;
    b->demand_rel = demand_rel;
    b->ans_rel = ans_rel;
    b->oracle = oit->second;
    bindings[demand_rel] = b;
    return b;
  }

  // Submit a serialized request to the pool (dispatch task, read phase).
  void submit(OracleBinding* b, u64 id, std::string request)
  {
    outstanding_.fetch_add(1);
    {
      std::lock_guard<std::mutex> lk(mu);
      ensureWorkers();
      jobs.push_back(OracleJob{b, id, std::move(request)});
    }
    job_cv.notify_one();
  }

  // Complete at dispatch time (eager/mock backends and serialize failures):
  // same done-queue path, no pool round trip.
  void completeLocal(OracleBinding* b, u64 id, OracleResult r)
  {
    outstanding_.fetch_add(1);
    b->pushDone(id, std::move(r));
    undrained_.fetch_add(1);
    done_cv.notify_all();
  }

  // The harvest task emitted `n` answers as facts.
  void harvested(u64 n)
  {
    outstanding_.fetch_sub(n);
    undrained_.fetch_sub(n);
  }

  // ---- ExternalWork (the fixpoint's view; database.h) ----
  u64 outstanding() override { return outstanding_.load(); }

  // Block until at least one completed answer awaits harvest, the budget
  // deadline passes, or the run's stop flag trips.  Runs single-threaded in
  // EndIterCompletion while every stratum worker is parked at the barrier;
  // only pool threads make progress, so waiting here deadlocks nothing.
  bool waitHarvestable(std::chrono::steady_clock::time_point deadline,
                       const std::atomic<bool>& stop) noexcept override
  {
    try
    {
      std::unique_lock<std::mutex> lk(mu);
      while (undrained_.load() == 0)
      {
        if (stop.load(std::memory_order_relaxed)) return false;
        const auto now = std::chrono::steady_clock::now();
        if (now >= deadline) return false;
        const auto until = std::min(deadline, now + std::chrono::milliseconds(20));
        done_cv.wait_until(lk, until);
      }
      return true;
    }
    catch (...) { return false; }
  }
};

// Scan the demand relation's delta and submit each not-yet-answered demand.
// Registered in phase_read (indices are immutable there, so decoding the
// payload's struct DAG through lookup indices is race-free).
class OracleDispatchTask : public Task
{
  Database* db;
  OracleRegistry* reg;
  OracleBinding* b;
  Relation* drel;   // the demand struct relation: storage (id, payload)
  Relation* arel;   // the answer table: storage (id, code)
public:
  OracleDispatchTask(Database* _db, OracleRegistry* _reg, OracleBinding* _b,
                     Relation* _drel, Relation* _arel)
    : db(_db), reg(_reg), b(_b), drel(_drel), arel(_arel) {}

  bool work() override
  {
    const u32 nthreads = db->getThreadCount();
    // Answered-set upkeep from the answer table's delta: iteration 0 carries
    // the whole reloaded extent (persisted answers), later iterations the
    // harvest's own emissions.  Idempotent inserts.
    for (u32 t = 0; t < nthreads; ++t)
      for (u16 bkt = 0; bkt < bucket_count; ++bkt)
      {
        RefVec& refs = arel->getReadBucket(t, bkt);
        const u32 n = (u32)refs.size();
        for (u32 i = 0; i < n; ++i)
          b->answered.insert((refs[i].batch->data + refs[i].offset)[0]);
      }
    // New demands: delta rows are (id, payload) in storage order.
    for (u32 t = 0; t < nthreads; ++t)
      for (u16 bkt = 0; bkt < bucket_count; ++bkt)
      {
        RefVec& refs = drel->getReadBucket(t, bkt);
        const u32 n = (u32)refs.size();
        for (u32 i = 0; i < n; ++i)
        {
          const u64* d = refs[i].batch->data + refs[i].offset;
          const u64 id = d[0];
          if (!b->answered.insert(id).second)
            continue;                      // answered or already in flight
          const u64 payload = d[1];
          // Serialize FIRST (even for eager/mock backends): it doubles as
          // vocabulary validation, so malformed formulas surface as error
          // facts deterministically under every backend.
          std::string request, err;
          if (!b->oracle->serialize(db, payload, request, err))
          {
            emitBadFormula(err, payload);
            if (b->warned.insert(err).second)
              std::cerr << "[slog oracle " << b->oracle_name << "] "
                        << "unserializable demand in " << b->demand_rel
                        << " (answering unknown): " << err << std::endl;
            reg->completeLocal(b, id, b->oracle->unknownResult());
            continue;
          }
          OracleResult eager;
          if (b->oracle->solveEager(db, payload, eager))
          {
            reg->completeLocal(b, id, std::move(eager));
            continue;
          }
          reg->submit(b, id, std::move(request));
        }
      }
    return true;
  }

private:
  // Record an (error (smt_bad_formula reason formula)) fact, the fallible-
  // prims pattern (docs/type-errors.md): compile.rkt registers the arm and
  // its wrap rule in every oracle stratum.  Storage order (id-placeholder,
  // reason, formula); InternStructTask assigns the id.  sendBatch appends to
  // this worker's shard -- read-phase-safe, exactly like emit_error_struct.
  void emitBadFormula(const std::string& reason, u64 payload)
  {
    Relation* arm = db->getRelation("smt_bad_formula");
    if (arm == nullptr) return;            // stratum without the arm wired
    InsertBatch* nb = new InsertBatch();
    nb->data[0] = 0;                       // id placeholder (intern assigns)
    nb->data[1] = str_encode(db, reason);
    nb->data[2] = payload;
    nb->usage = 3;
    arm->sendBatch(nb);
  }
};

// Drain completed answers into the answer table, MATERIALIZING each result
// here (read phase, Database in hand): an int result becomes its s32 word, a
// map result becomes a canonical cmap of interned-string keys to s32 values
// with the code word under "@status" (lib wrappers destructure it).  Rows
// flow through sendBatch like any rule emission and dedup in the intern
// phase (set semantics), so re-emission after a reload is harmless.
class OracleHarvestTask : public Task
{
  Database* db;
  OracleRegistry* reg;
  OracleBinding* b;
  Relation* arel;
public:
  OracleHarvestTask(Database* _db, OracleRegistry* _reg, OracleBinding* _b,
                    Relation* _arel)
    : db(_db), reg(_reg), b(_b), arel(_arel) {}

  u64 materialize(const OracleResult& r)
  {
    if (!r.is_map)
      return s32_encode(r.code);
    CollectionArena* arena = db->collections();
    u64 m = arena->put(arena->empty(), str_encode(db, "@status"),
                       s32_encode(r.code));
    for (const auto& e : r.entries)
    {
      // exact: a solver bignum interns via the normalization keystone
      // (an s32-range value stays the s32 word); a cap trip or malformed
      // numeral must not put slog_error INTO the map -- skip the entry
      const u64 w = db->encodeIntLiteral(e.second, "smtmodel");
      if (w == slog_error) continue;
      m = arena->put(m, str_encode(db, e.first), w);
    }
    for (const auto& e : r.word_entries)
      m = arena->put(m, e.first, s32_encode((s32)e.second));
    return m;
  }

  bool work() override
  {
    std::vector<std::pair<u64, OracleResult>> got;
    b->drainInto(got);
    if (got.empty()) return true;
    InsertBatch* nb = new InsertBatch();
    for (const auto& a : got)
    {
      nb->data[nb->usage] = a.first;
      nb->data[nb->usage + 1] = materialize(a.second);
      nb->usage += 2;
      if (nb->usage + 2 >= batch_size_max)
      {
        arel->sendBatch(nb);
        nb = new InsertBatch();
      }
    }
    arel->sendBatch(nb);
    reg->harvested(got.size());
    return true;
  }
};

}
