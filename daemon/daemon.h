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
#include <cstdio>
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

public:
  Daemon(u32 thread_count, Emit _out)
    : database(new Database(thread_count)), out(std::move(_out))
  {
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

  // Open a stored database.  Its relations materialize into default indices
  // immediately (queryable/writable by actions before any program runs);
  // the deferred reload then hands the next stratum everything as its
  // iteration-zero delta, exactly as if that stratum had just run.
  void open(const std::string& db_name)
  {
    database->loadDatabaseBIN("data/" + db_name + "/");
    needs_reload = true;
  }

  // Merge a stored database into the live one (docs/db-merge.md): tables
  // union, lattices join per key, structs dedup by content, collections
  // re-canonicalize.  The deferred reload then hands the next stratum the
  // UNION as its iteration-zero delta -- zero pipeline changes.
  void import(const std::string& db_name)
  {
    database->importDatabaseBIN("data/" + db_name + "/");
    needs_reload = true;
  }

  // Start building a stratum.  If a stratum has run since the last reload,
  // the database reloads NOW -- before the caller registers this stratum's
  // indices and binds tasks to them -- re-staging every relation's contents
  // as insert batches for the coming run's iteration zero.
  Stratum* beginStratum(const std::string& name)
  {
    if (needs_reload)
    {
      database->reloadInsertBatches();
      needs_reload = false;
    }
    return new Stratum(name);
  }

  // Append a stratum to the pipeline (it runs on the next run()).
  void push(Stratum* s) { pipeline.push_back(s); }

  // The pipeline so far (run and unrun), in order.
  const std::vector<Stratum*>& strata() const { return pipeline; }

  // Run every not-yet-run stratum, in order, each to fixpoint.  A stratum
  // plugin is expected to beginStratum/register/push/run as one unit, so
  // each pending stratum's indices were registered against the freshly
  // reloaded database.  Each fixpoint reports its iteration count and wall
  // time -- nothing parses this message; it is for humans and benchmarks.
  void run()
  {
    for (; next_unrun < pipeline.size(); ++next_unrun)
    {
      const auto t0 = std::chrono::steady_clock::now();
      database->runStratum(pipeline[next_unrun]);
      const double ms =
        std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::steady_clock::now() - t0).count() / 1000.0;
      needs_reload = true;
      char stats[64];
      std::snprintf(stats, sizeof(stats), " %u %.3f)",
                    database->getIterationCount(), ms);
      emit("(fixpoint " + pipeline[next_unrun]->name + stats);
    }
  }
};

}
