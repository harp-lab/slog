/** Slog Daemon Object
 *
 * The daemon's entire client protocol is: one .so path per line.  Each .so
 * is dlopen'd and its
 *
 *     extern "C" void slog_plugin(slog::Daemon*)
 *
 * entry point called with this object -- the API through which plugins do
 * everything: build and push strata of rules, run the pipeline, read and
 * write the database on disk, inspect relations, and send results back to
 * the client (Daemon::emit).
 *
 * A Stratum is the object representation of one stratum of rules: the
 * write/read/intern tasks the compiler generated for it, plus metadata (its
 * name and the relations it grows).  The compiler collapses a program's SCC
 * DAG into a linear sequence of (merged) strata; each stratum's .so pushes
 * its Stratum here, so the Daemon accumulates the whole pipeline in memory
 * as state.  Daemon::run() advances a cursor over the pipeline, running
 * each not-yet-run stratum to fixpoint and reloading the database between
 * strata (so each stratum re-ingests the whole database as its
 * iteration-zero delta).  Strata stay resident after running -- the
 * intended seam for incremental recomputation later: push a delta into
 * some stratum and replay the pipeline from there.  (Not built yet; note
 * that a retained stratum's tasks bind index arrays that a later reload
 * clears, so re-running an old stratum requires re-binding -- index
 * *registrations* survive, their contents do not.)
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

#include "slogd.h"

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <string>
#include <vector>

namespace slog
{

class Daemon
{
public:
  using Emit = std::function<void(const std::string&)>;

private:
  Database* database;
  Emit out;
  std::vector<Stratum*> pipeline;
  size_t next_unrun = 0;
  // Set after each run; consumed by beginStratum.  The reload (dump every
  // relation to insert batches, CLEAR all indices) must happen before the
  // next stratum registers its indices and binds its tasks to them -- so it
  // is deferred to beginStratum rather than performed after a run, which
  // also leaves the indices intact for any statistics/output plugins that
  // arrive after the final stratum.
  bool needs_reload = false;
  // Default budget a no-argument continueRun() uses -- both the first unit of
  // work each stratum plugin requests and any bare (continue) action poll.
  // Overridable via env (SLOG_MAX_MS / SLOG_SLICE_MS / SLOG_MEM_BYTES) so a
  // whole run can be driven under a pathological budget (the byte-identical
  // suspend test) without recompiling any plugin.
  RunBudget default_budget;

  static u64 envU64(const char* name, u64 fallback)
  {
    const char* v = std::getenv(name);
    if (v == nullptr || v[0] == '\0') return fallback;
    return (u64)std::strtoull(v, nullptr, 10);
  }

public:
  Daemon(u32 thread_count, Emit _out)
    : database(new Database(thread_count)), out(std::move(_out))
  {
    default_budget.max_ms    = envU64("SLOG_MAX_MS", default_budget.max_ms);
    default_budget.slice_ms  = envU64("SLOG_SLICE_MS", default_budget.slice_ms);
    default_budget.mem_bytes = envU64("SLOG_MEM_BYTES", default_budget.mem_bytes);
  }

  ~Daemon()
  {
    for (Stratum* s : pipeline)
      delete s;
    delete database;
  }

  // The database, exposing the full storage/disk API to plugins.
  Database* db() { return database; }

  // Send one message (conventionally an s-expression) back to the client.
  void emit(const std::string& msg) { out(msg); }

  // While a stratum is suspended (docs/pausing.md §4), any action that would
  // reload or clear indices -- destroying the parked tasks' index bindings and
  // the staged delta -- is refused; the client must continue to fixpoint
  // first.  Read-only actions (sizes, lookup, CSV dumps) remain allowed.
  bool refuseIfSuspended(const char* what)
  {
    if (database->isSuspended())
    {
      emit(std::string("(error suspended \"") + what
           + " is refused while a stratum is suspended; continue to fixpoint first\")");
      return true;
    }
    return false;
  }

  // Open a stored database.  Its relations materialize into default indices
  // immediately (queryable/writable by actions before any program runs);
  // the deferred reload then hands the next stratum everything as its
  // iteration-zero delta, exactly as if that stratum had just run.
  void open(const std::string& db_name)
  {
    if (refuseIfSuspended("open")) return;
    database->loadDatabaseBIN("data/" + db_name + "/");
    needs_reload = true;
  }

  // Merge a stored database into the live one (docs/db-merge.md): tables
  // union, lattices join per key, structs dedup by content, collections
  // re-canonicalize.  The deferred reload then hands the next stratum the
  // UNION as its iteration-zero delta -- zero pipeline changes.
  void import(const std::string& db_name)
  {
    if (refuseIfSuspended("import")) return;
    database->importDatabaseBIN("data/" + db_name + "/");
    needs_reload = true;
  }

  // Start building a stratum.  If a stratum has run since the last reload,
  // the database reloads NOW -- before the caller registers this stratum's
  // indices and binds tasks to them -- re-staging every relation's contents
  // as insert batches for the coming run's iteration zero.  Refused while a
  // stratum is suspended (the reload would dangle every parked task's bindings
  // and destroy the staged delta).
  Stratum* beginStratum(const std::string& name)
  {
    if (database->isSuspended())
    {
      // Hot-swap upgrade (docs/fast-compile.md §4): a freshly-compiled plugin
      // for the SAME stratum, arriving while that stratum is parked at a clean
      // iteration boundary, replaces the currently-running (e.g. -O0) one.  Hand
      // back the LIVE Stratum with its task lists emptied; the caller then
      // re-registers the identical relations (addRelation guarded), indices
      // (addIndex idempotent), and tasks, and its trailing continueRun resumes
      // the fixpoint with the new code.  No reload happens -- the staged delta
      // and every index stay live, and the replacement's tasks bind() to them.
      const Stratum* susp = database->suspendedStratum();
      if (susp && susp->name == name
          && database->suspendPosition() == RUN_AT_BOUNDARY)
      {
        Stratum* s = const_cast<Stratum*>(susp);
        s->clearForUpgrade();
        return s;
      }
      // Any other suspended state -- a different stratum, or a mid-read park
      // whose continuations point into the old .so -- is not swappable.
      emit("(error suspended \"beginStratum is refused while a stratum is "
           "suspended; continue to fixpoint first\")");
      return nullptr;
    }
    if (needs_reload)
    {
      database->reloadInsertBatches();
      needs_reload = false;
    }
    return new Stratum(name);
  }

  // Persist the database / one relation to disk.  These run an internal
  // stratum (the parallel BIN writers) that reuses the single RunState, so
  // they are refused while a user stratum is suspended (§4; continue to
  // fixpoint first).  CSV writes and (sizes)/(lookup) take no such lock and
  // stay allowed against the consistent suspended snapshot.
  void writeDatabaseBIN(const std::string& db_name)
  {
    if (refuseIfSuspended("write-db")) return;
    database->writeDatabaseBIN(db_name);
  }
  // Write only the named relations (docs/db-compression.md P0.5): an EDB-root
  // snapshot or an IDB-layer save.  Same suspended guard as the full write.
  void writeDatabaseSubsetBIN(const std::string& db_name,
                              const std::unordered_set<std::string>& only)
  {
    if (refuseIfSuspended("write-db")) return;
    database->writeDatabaseBIN(db_name, only);
  }
  // Sampled IDB-layer write (docs/db-compression.md P1.2): keep only a
  // per-fraction of each named relation's tuples (dropped ones recomputed on
  // load), struct heap + interners whole.  Same suspended guard.
  void writeDatabaseSampledBIN(const std::string& db_name,
                               const std::unordered_set<std::string>& only,
                               double per, u64 seed,
                               const std::unordered_set<std::string>& boosted,
                               double boost)
  {
    if (refuseIfSuspended("write-db")) return;
    database->writeDatabaseBIN(db_name, only, per, seed, boosted, boost);
  }
  void writeRelationBIN(const std::string& db_name, const std::string& rel)
  {
    if (refuseIfSuspended("write-rel")) return;
    database->writeRelationBIN(db_name, rel);
  }
  // Checkpoint the current (possibly parked) database to data/<name>/ serially
  // (docs/db-compression.md §P2.3).  NOT guarded by refuseIfSuspended: the
  // serial writer uses no RunState, so it is safe to snapshot a fixpoint parked
  // at a memory pause.  Emits (checkpointed NAME) so the driver can wait for it.
  void checkpointBIN(const std::string& db_name)
  {
    database->writeDatabaseSerialBIN(db_name);
    emit(std::string("(checkpointed ") + db_name + ")");
  }
  // Insert one tuple into a relation out-of-band (docs/db-compression.md §12,
  // edit-and-propagate): the storage-order words `t` are added to every index,
  // and needs_reload is set so the next stratum re-dumps it as delta -- a
  // forward-incremental edit to an input-leaf relation that replay propagates
  // downstream.  Refused while suspended (it would corrupt a parked delta).
  void addTuple(const std::string& rel, const std::vector<u64>& t)
  {
    if (refuseIfSuspended("add-tuple")) return;
    slog::Relation* r = database->getRelation(rel);
    if (!r) { emit(std::string("(error \"add-tuple: no relation ") + rel + "\")"); return; }
    r->insertTupleAllIndices(t.data());
    needs_reload = true;
  }
  // Replace / refresh a relation from disk -- mutates its indices in place, so
  // also refused while suspended (it would corrupt a parked stratum's delta).
  void loadRelation(const std::string& db_name, const std::string& rel)
  {
    if (refuseIfSuspended("load-rel")) return;
    database->loadRelationBIN(db_name, rel);
  }
  void refreshRelation(const std::string& db_name, const std::string& rel)
  {
    if (refuseIfSuspended("refresh-rel")) return;
    const bool changed = database->refreshRelationBIN(db_name, rel);
    emit(std::string("(refreshed ") + rel + " " + (changed ? "1" : "0") + ")");
  }

  // Append a stratum to the pipeline (it runs on the next continueRun),
  // assigning its SCC id = pipeline position (§6).  A null stratum (a plugin
  // whose beginStratum was refused while suspended) is ignored.
  void push(Stratum* s)
  {
    if (s == nullptr) return;
    // Idempotent: a hot-swap upgrade plugin re-pushes the SAME Stratum object
    // beginStratum handed back (docs/fast-compile.md §4).  Re-adding it would
    // duplicate it in the pipeline and churn scc_id / next_unrun; skip.
    for (Stratum* p : pipeline) if (p == s) return;
    s->scc_id = (u32)pipeline.size();
    pipeline.push_back(s);
  }

  // The pipeline so far (run and unrun), in order.
  const std::vector<Stratum*>& strata() const { return pipeline; }

  // Perform ONE bounded unit of work (docs/pausing.md §5): start or resume the
  // frontmost not-yet-fixpointed stratum for at most one budget's worth, then
  // emit exactly one of
  //   (fixpoint <scc-id> <name> <iters> <ms-total>)
  //   (paused <scc-id> <name> <iter> <phase> <new-tuples> <ms-call> <ms-total> <reason>)
  // <phase> is `iter` (clean boundary) or `read` (mid read-phase suspend).
  // Idempotent (§5): with nothing unrun and nothing suspended, re-emit the
  // last stratum's (fixpoint ...) verbatim, or (idle) for an empty pipeline --
  // so a client's "continue until fixpoint" loop terminates cleanly.
  //
  // The no-argument form uses the (env-configurable) default budget, so both
  // the first unit a plugin requests and a bare (continue) poll respect it.
  void continueRun() { continueRun(default_budget); }

  // Continue, but force a suspend at the next clean iteration boundary (the only
  // hot-swap-safe stop point) regardless of the time budget -- docs/fast-compile
  // §4.  The tiered-compilation driver polls this (via a (continue-boundary)
  // action) to bring a mid-read-paused stratum to RUN_AT_BOUNDARY before sending
  // the -O2 replacement .so.  Uses the default (env-configurable) budget so a
  // memory trip still wins and aborts as usual.
  void continueToBoundary()
  {
    RunBudget b = default_budget;
    b.stop_at_boundary = true;
    continueRun(b);
  }

  void continueRun(RunBudget b)
  {
    const bool suspended = database->isSuspended();
    if (!suspended && next_unrun >= pipeline.size())
    {
      if (pipeline.empty()) emit("(idle)");
      else emit(pipeline.back()->fixpoint_msg);   // idempotent re-confirm
      return;
    }

    Stratum* s = pipeline[next_unrun];             // suspended one or next unrun
    const RunStatus st = database->continueStratum(s, b, !suspended, true);

    char buf[192];
    if (st.fixpoint)
    {
      ++next_unrun;
      needs_reload = true;
      std::snprintf(buf, sizeof(buf), "(fixpoint %u \"%s\" %u %.3f)",
                    s->scc_id, s->name.c_str(), st.iteration, st.ms_total);
      s->fixpoint_msg = buf;
      emit(s->fixpoint_msg);
    }
    else
    {
      std::snprintf(buf, sizeof(buf),
                    "(paused %u \"%s\" %u %s %llu %.3f %.3f %s)",
                    s->scc_id, s->name.c_str(), st.iteration,
                    st.where == RUN_MID_READ ? "read" : "iter",
                    (unsigned long long)st.new_tuples,
                    st.ms_call, st.ms_total, st.reason);
      emit(buf);
    }
  }

  // The legacy blocking loop: continue every not-yet-run stratum to fixpoint,
  // unbudgeted, emitting one (fixpoint ...) each.  Generated plugins now drive
  // via continueRun; kept for internal use / compatibility.
  void run()
  {
    RunBudget unbounded;
    unbounded.max_ms = UINT64_MAX;
    unbounded.mem_bytes = UINT64_MAX;
    while (database->isSuspended() || next_unrun < pipeline.size())
      continueRun(unbounded);
  }
};

}
