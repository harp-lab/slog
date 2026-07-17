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
  // External oracles (docs/smt.md): built-in implementations register here;
  // the registry doubles as the Database's ExternalWork so a stratum's
  // fixpoint waits for outstanding answers.
  OracleRegistry* oracle_registry;
  std::vector<Stratum*> pipeline;
  size_t next_unrun = 0;
  // Recount and other observational maintenance strata execute through the
  // normal scheduler but are not semantic pipeline events.  They must not
  // advance positions, appear as writers, or perturb later VersionKeys.
  bool next_push_transient = false;
  Stratum* transient_run = nullptr;
  // Unlike a transient recount plugin, delta/replay maintenance retains its
  // legacy numeric pipeline position.  This flag keeps it out of semantic
  // writer ownership while preserving old position-addressed recipes.
  bool next_push_maintenance = false;
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
  // Pending positional re-entry (docs/incremental.md §0.5, 0.C): set by a
  // (bind-at P) action, consumed by the NEXT fresh beginStratum -- that
  // stratum restages and binds the P-environment instead of the latest;
  // push() resets the database's bind position after registration.
  s64 pending_bind_pos = -1;
  std::vector<std::pair<std::string, u64>> pending_bind_versions;

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
    oracle_registry = new OracleRegistry();
    oracle_registry->registerOracle("smt", new SmtOracle());
    oracle_registry->registerOracle("smtmodel", new SmtOracle(SMT_MODE_MODEL));
    oracle_registry->registerOracle("smtcore", new SmtOracle(SMT_MODE_CORE));
    database->setExternalWork(oracle_registry);
  }

  ~Daemon()
  {
    if (transient_run) delete transient_run;
    for (Stratum* s : pipeline)
      delete s;
    delete database;
    delete oracle_registry;
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
    // A flat/root open is semantic input.  Recipe/compressed derived layers
    // use importLayer/replay instead and therefore do not take this path.
    database->markLatestRelationsDirect();
    // A boundary event (docs/incremental.md §0.4/B0): the loaded relations
    // registered at the position just consumed; advancing here keeps a
    // following segment boundary's rebinds from shadowing them at the same
    // position (versioned addressing resolves last-binding-<=-P).
    database->advancePosition();
    needs_reload = true;
  }

  // Merge a stored database into the live one (docs/db-merge.md): tables
  // union, lattices join per key, structs dedup by content, collections
  // re-canonicalize.  The deferred reload then hands the next stratum the
  // UNION as its iteration-zero delta -- zero pipeline changes.
  void import(const std::string& db_name)
  {
    if (refuseIfSuspended("import")) return;
    database->importDatabaseBIN("data/" + db_name + "/", false, {}, -1, true);
    database->advancePosition();   // boundary event (§0.4/B0), as in open
    needs_reload = true;
  }
  // Merge a stored database by PATH (no data/ prefix): the driver links the
  // compiler's frozen ground-fact databases (build/frozen/<hash>) before
  // stratum 0; the deferred reload hands the next stratum their rows as its
  // iteration-zero delta.
  void importPath(const std::string& dir)
  {
    if (refuseIfSuspended("import")) return;
    database->importDatabaseBIN(dir + "/");
    database->advancePosition();   // boundary event (§0.4/B0), as in open
    needs_reload = true;
  }
  // Merge a compressed LAYER (docs/db-compression.md §4.2): like import, but its
  // heap was trimmed of structs the verbatim-opened root already holds, so
  // dangling same-lineage refs pass through to the dest instead of fataling.
  void importLayer(const std::string& db_name)
  {
    if (refuseIfSuspended("import")) return;
    database->importDatabaseBIN("data/" + db_name + "/", true);
    database->advancePosition();   // boundary event (§0.4/B0), as in open
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
    if (pending_bind_pos >= 0)
    {
      // Positional re-entry (0.C): restage the P-environment as the coming
      // stratum's iteration-0 delta and resolve its registrations there.
      // needs_reload stays armed -- the next NORMAL push still restages
      // the latest environment as usual.
      database->reloadInsertBatchesAt((u32)pending_bind_pos);
      database->setBindPosition(pending_bind_pos);
      database->setBindVersions(pending_bind_versions);
      pending_bind_pos = -1;
      pending_bind_versions.clear();
    }
    else if (needs_reload)
    {
      database->reloadInsertBatches();
      needs_reload = false;
    }
    return new Stratum(name);
  }

  // Arm the next fresh beginStratum to bind at pipeline position P
  // (docs/incremental.md §0.5, 0.C): the driver sends this immediately
  // before re-pushing a cached stratum .so of an earlier pipeline segment,
  // so its getRelation registrations resolve through P's environment.
  void bindAt(u32 pos)
  {
    if (refuseIfSuspended("bind-at")) return;
    pending_bind_pos = (s64)pos;
    pending_bind_versions.clear();
  }

  // Rebind one historical stratum instance by exact VersionId.  The numeric
  // position is retained only for compiler-local relations absent from the
  // recorded semantic read/write maps.
  void bindInstance(u32 pos,
                    const std::vector<std::pair<std::string, u64>>& bindings)
  {
    if (refuseIfSuspended("bind-instance")) return;
    pending_bind_pos = (s64)pos;
    pending_bind_versions = bindings;
  }

  void armTransientStratum()
  {
    if (refuseIfSuspended("transient-stratum")) return;
    if (transient_run != nullptr)
    {
      emit("(error \"a transient stratum is already active\")");
      return;
    }
    next_push_transient = true;
    emit("(transient-armed)");
  }

  void armMaintenanceStratum()
  {
    if (refuseIfSuspended("maintenance-stratum")) return;
    next_push_maintenance = true;
    emit("(maintenance-armed)");
  }

  // Delta-entry variant (docs/incremental.md §0.5 mode 3, 0.B5): NO reload
  // -- the staged batch (stageTuple) is the coming run's entire iteration-0
  // delta, and every live index (registrations AND contents) survives into
  // it; needs_reload stays armed for the next NORMAL push.  Same suspended
  // guardrail; no hot-swap interplay (the delta flavor is a distinct
  // stratum name, so an upgrade never matches it).
  Stratum* beginStratumDelta(const std::string& name)
  {
    if (database->isSuspended())
    {
      emit("(error suspended \"beginStratumDelta is refused while a stratum "
           "is suspended; continue to fixpoint first\")");
      return nullptr;
    }
    if (pending_bind_pos >= 0)
    {
      // Positional count round (docs/incremental.md §8B.2, M0.3): resolve
      // this plugin's registrations through P's environment WITHOUT the
      // positional reload beginStratum performs -- old versions keep their
      // indices resident, and a count round needs no iteration-0 delta.
      // push() returns resolution to the latest environment, exactly as
      // for a positional beginStratum.
      database->setBindPosition(pending_bind_pos);
      database->setBindVersions(pending_bind_versions);
      pending_bind_pos = -1;
      pending_bind_versions.clear();
    }
    return new Stratum(name);
  }

  // Stage one storage-order tuple as pending delta WITHOUT touching the
  // full indices (docs/incremental.md §0.3, 0.B5/B6): the tuple enters the
  // next run's iteration-0 delta EXACTLY ONCE, through the same send-shard
  // path rule emissions use; the delta run's write phase then integrates
  // it into every full index.  This is the exact-once staging discipline
  // Phase 1's counters inherit -- an insert-plus-restage would double it.
  void stageTuple(const std::string& rel, const std::vector<u64>& t)
  {
    if (refuseIfSuspended("stage-tuple")) return;
    slog::Relation* r = database->getRelation(rel);
    if (!r) { emit(std::string("(error \"stage-tuple: no relation ") + rel + "\")"); return; }
    InsertBatch* b = new InsertBatch();
    for (size_t i = 0; i < t.size(); ++i)
      b->data[i] = t[i];
    b->usage = (u32)t.size();
    r->sendBatch(b);
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
  // load), struct heap + interners whole.  `pinned` relations (docs/smt.md
  // §15: oracle-fed rows replay cannot re-derive) keep everything and seed
  // the heap-trimming roots.  Same suspended guard.
  void writeDatabaseSampledBIN(const std::string& db_name,
                               const std::unordered_set<std::string>& only,
                               double per, u64 seed,
                               const std::unordered_set<std::string>& boosted,
                               double boost,
                               const std::unordered_set<std::string>& pinned = {},
                               bool accel = false)
  {
    if (refuseIfSuspended("write-db")) return;
    database->writeDatabaseBIN(db_name, only, per, seed, boosted, boost, pinned,
                               accel);
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
  // Snapshot the current struct heap as the EDB boundary of a compressed save
  // (docs/db-compression.md §4.2): the following layer write will not re-store
  // these input structs.  Read-only; safe between strata.
  void captureEDBHeap() { database->captureEDBHeap(); }
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
    r->addInput(t.data());
    needs_reload = true;
  }
  // Retract one tuple out-of-band (docs/incremental.md §0.6, B2): the
  // "rebuild the anchored version minus retracted tuples" half of
  // clear-and-rerun -- the driver clears + re-runs the cone afterward.
  // Plain tables only: a lattice key has no tuple-retraction semantics
  // (values re-derive only by re-run) and struct rows are interned
  // derivations, not inputs.  Replies (deleted REL 0|1).
  void delTuple(const std::string& rel, const std::vector<u64>& t)
  {
    if (refuseIfSuspended("del-tuple")) return;
    slog::Relation* r = database->getRelation(rel);
    if (!r) { emit(std::string("(error \"del-tuple: no relation ") + rel + "\")"); return; }
    if (r->isLattice() || r->getStructId() > 0)
    {
      emit(std::string("(error \"del-tuple: ") + rel
           + " is a lattice/struct relation; retract inputs, not derivations\")");
      return;
    }
    Relation::InputOutcome o = r->classifyDeleteInput(t.data());
    if (o == Relation::INPUT_DERIVED_ONLY || o == Relation::INPUT_ABSENT)
    {
      emit(std::string("(error \"del-tuple: tuple in ") + rel
           + (o == Relation::INPUT_DERIVED_ONLY
                ? " is derived-only\")" : " is absent\")"));
      return;
    }
    r->deleteInput(t.data());
    const bool found = true;
    database->accelInvalidate(rel);   // §4.4.5: retracted rows must not reseed
    needs_reload = true;
    emit(std::string("(deleted ") + rel + " " + (found ? "1" : "0") + ")");
  }

  // Empty one relation's LATEST version -- contents only, registrations
  // persist (docs/incremental.md §0.5 mode 2 / B2): the driver clears each
  // cone-written relation before re-pushing the cone's strata, so the
  // re-run's iteration-0 reload stages base + batch without the stale
  // derivations.  A cleared struct relation keeps its intern dictionary as
  // tombstones, so re-derivation RESURRECTS the original ids (M5,
  // docs/m5-contract.md); intern allocators persist (monotone, never
  // reused), and only genuinely new content mints above them.
  void clearRelation(const std::string& rel)
  {
    if (refuseIfSuspended("clear-rel")) return;
    slog::Relation* r = database->getRelation(rel);
    if (!r) { emit(std::string("(error \"clear-rel: no relation ") + rel + "\")"); return; }
    r->clearContentsToTombstones();
    // Rule derivations are gone until the rerun, but the input baseline
    // (direct assertions, unmasked inheritance) is not a rule consequence
    // and must survive the clear (§0.6).
    r->rematerializeInputBaseline();
    database->accelInvalidate(rel);   // stale sidecar rows must not reseed
    needs_reload = true;
  }

  // Positional clear (0.C): empty the version of `rel` current at pipeline
  // position P -- the anchored clear-and-rerun's per-version clear.
  void clearRelationAt(const std::string& rel, u32 pos)
  {
    if (refuseIfSuspended("clear-rel-at")) return;
    slog::Relation* r = database->getRelationAt(rel, pos);
    if (!r) { emit(std::string("(error \"clear-rel-at: no version of ") + rel + "\")"); return; }
    r->clearContentsToTombstones();
    database->accelInvalidate(rel);   // stale sidecar rows must not reseed
  }

  // Re-materialise an inheritance boundary (0.C): version `ordinal` of
  // `rel` := a fresh copy of version ordinal-1 (contents + re-seeded
  // intern allocators).  Sent by the driver's anchored suffix walk for
  // each later binding of an affected relation, before re-running the
  // segment that wrote it.  Replies (refreshed-version REL ORD 0|1).
  void refreshVersion(const std::string& rel, u32 ordinal)
  {
    if (refuseIfSuspended("refresh-version")) return;
    const bool ok = database->refreshVersion(rel, ordinal);
    emit(std::string("(refreshed-version ") + rel + " " + std::to_string(ordinal)
         + " " + (ok ? "1" : "0") + ")");
  }

  // Batch applies (0.C, the C1 actions' backend).  `pos < 0` = the latest
  // version (tip batches); otherwise the version current at position P
  // (anchored batches -- apply-only: the driver owns propagation).
  // Plain tables only, as del-tuple: lattice keys have no tuple-retraction
  // semantics and struct rows are interned derivations, not inputs.
  void addBatchAt(const std::string& rel, s64 pos,
                  const std::vector<std::vector<u64>>& ts)
  {
    if (refuseIfSuspended("add-batch")) return;
    slog::Relation* r = (pos < 0) ? database->getRelation(rel)
                                  : database->getRelationAt(rel, (u32)pos);
    if (!r) { emit(std::string("(error \"add-batch: no relation ") + rel + "\")"); return; }
    if (r->isLattice() || r->getStructId() > 0)
    {
      emit(std::string("(error \"add-batch: ") + rel
           + " is a lattice/struct relation; batch inputs, not derivations\")");
      return;
    }
    for (const auto& t : ts)
      r->addInput(t.data());
    if (pos < 0)
      needs_reload = true;
    emit(std::string("(added ") + rel + " " + std::to_string(ts.size()) + ")");
  }

  void delBatchAt(const std::string& rel, s64 pos,
                  const std::vector<std::vector<u64>>& ts)
  {
    if (refuseIfSuspended("del-batch")) return;
    slog::Relation* r = (pos < 0) ? database->getRelation(rel)
                                  : database->getRelationAt(rel, (u32)pos);
    if (!r) { emit(std::string("(error \"del-batch: no relation ") + rel + "\")"); return; }
    if (r->isLattice() || r->getStructId() > 0)
    {
      emit(std::string("(error \"del-batch: ") + rel
           + " is a lattice/struct relation; batch inputs, not derivations\")");
      return;
    }
    // Preflight makes a mixed batch atomic with respect to input legality.
    for (const auto& t : ts)
    {
      Relation::InputOutcome o = r->classifyDeleteInput(t.data());
      if (o == Relation::INPUT_DERIVED_ONLY || o == Relation::INPUT_ABSENT)
      {
        emit(std::string("(error \"del-batch: tuple in ") + rel
             + (o == Relation::INPUT_DERIVED_ONLY
                  ? " is derived-only\")" : " is absent\")"));
        return;
      }
    }
    u32 found = 0;
    for (const auto& t : ts)
    {
      r->deleteInput(t.data());
      ++found;
    }
    database->accelInvalidate(rel);   // §4.4.5: retracted rows must not reseed
    if (pos < 0)
      needs_reload = true;
    emit(std::string("(deleted ") + rel + " " + std::to_string(found) + ")");
  }

  void emitInputStates(const std::string& rel, s64 pos,
                       const std::vector<std::vector<u64>>& ts)
  {
    Relation* r = (pos < 0) ? database->getRelation(rel)
                            : database->getRelationAt(rel, (u32)pos);
    if (!r)
    {
      emit(std::string("(error \"input-state: no relation ") + rel + "\")");
      return;
    }
    for (size_t i = 0; i < ts.size(); ++i)
    {
      const u64* t = ts[i].data();
      emit("(inputstate " + std::to_string(i) + " "
           + (r->isDirectInput(t) ? "1" : "0") + " "
           + (r->isInheritanceMasked(t) ? "1" : "0") + " "
           + (r->hasInheritedBaseline(t) ? "1" : "0") + " "
           + (r->hasLiveTuple(t) ? "1" : "0") + ")");
    }
    emit("(inputstate-done " + std::to_string(ts.size()) + ")");
  }

  void setOverlayAt(const std::string& rel, s64 pos,
                    const std::vector<std::pair<u8, std::vector<u64>>>& rows)
  {
    if (refuseIfSuspended("set-overlay")) return;
    Relation* r = (pos < 0) ? database->getRelation(rel)
                            : database->getRelationAt(rel, (u32)pos);
    if (!r)
    {
      emit(std::string("(error \"set-overlay: no relation ") + rel + "\")");
      return;
    }
    if (r->isLattice() || r->getStructId() > 0)
    {
      emit(std::string("(error \"set-overlay: ") + rel
           + " is a lattice/struct relation\")");
      return;
    }
    for (const auto& row : rows)
      r->setInputOverlay(row.second.data(), row.first);
    database->accelInvalidate(rel);
    if (pos < 0) needs_reload = true;
    emit("(overlay-set " + rel + " " + std::to_string(rows.size()) + ")");
  }

  // M1 certified positive edit: preserve the VersionId and its established
  // support sidecar, set direct input support, and journal a premise only
  // when membership actually crosses 0->1 (a derived-live row is support-only).
  void setOverlayPositive(const std::string& rel,
                          const std::vector<std::vector<u64>>& rows)
  {
    if (refuseIfSuspended("set-overlay-positive")) return;
    Relation* r = database->getRelation(rel);
    if (!r)
    {
      emit(std::string("(error \"set-overlay-positive: no relation ") + rel + "\")");
      return;
    }
    // M4S: routing refuses struct/lattice edit TARGETS by name; this guard
    // keeps a wrong-arity content tuple from ever reaching the overlay fold.
    if (r->isLattice() || r->getStructId() > 0)
    {
      emit(std::string("(error \"set-overlay-positive: ") + rel
           + " is a lattice/struct relation\")");
      return;
    }
    u32 applied = 0;
    for (const auto& row : rows)
      if (database->applyPositiveInput(r, row.data())) ++applied;
    database->accelInvalidate(rel);
    emit("(overlay-positive " + rel + " " + std::to_string(applied)
         + " " + std::to_string(rows.size()) + ")");
  }

  void setOverlayNegative(const std::string& rel,
                          const std::vector<std::vector<u64>>& rows)
  {
    if (refuseIfSuspended("set-overlay-negative")) return;
    Relation* r = database->getRelation(rel);
    if (!r)
    {
      emit(std::string("(error \"set-overlay-negative: no relation ") + rel + "\")");
      return;
    }
    if (r->isLattice() || r->getStructId() > 0)
    {
      emit(std::string("(error \"set-overlay-negative: ") + rel
           + " is a lattice/struct relation\")");
      return;
    }
    u32 applied = 0;
    for (const auto& row : rows)
      if (database->applyNegativeInput(r, row.data())) ++applied;
    database->accelInvalidate(rel);
    emit("(overlay-negative " + rel + " " + std::to_string(applied)
         + " " + std::to_string(rows.size()) + ")");
  }

  // M4T (docs/m4t-contract.md): foundation-aware retraction for relations
  // dynamic in a recursive stratum of the maintained cone.
  void setOverlayNegativeDred(const std::string& rel,
                              const std::vector<std::vector<u64>>& rows)
  {
    if (refuseIfSuspended("set-overlay-negative-dred")) return;
    Relation* r = database->getRelation(rel);
    if (!r)
    {
      emit(std::string("(error \"set-overlay-negative-dred: no relation ")
           + rel + "\")");
      return;
    }
    if (r->isLattice() || r->getStructId() > 0)
    {
      emit(std::string("(error \"set-overlay-negative-dred: ") + rel
           + " is a lattice/struct relation\")");
      return;
    }
    u32 applied = 0;
    for (const auto& row : rows)
      if (database->applyNegativeInputDred(r, row.data())) ++applied;
    database->accelInvalidate(rel);
    emit("(overlay-negative-dred " + rel + " " + std::to_string(applied)
         + " " + std::to_string(rows.size()) + ")");
  }

  void stageUpdateTransitions(const std::vector<std::string>& names, s8 sign = 1)
  {
    if (refuseIfSuspended("stage-update-transitions")) return;
    database->stageUpdateTransitions(names, sign);
    emit("(transitions-staged " + std::to_string((s32)sign) + " "
         + std::to_string(names.size()) + ")");
  }

  void stageLatticeReplacements(const std::vector<std::string>& names, s8 sign)
  {
    if (refuseIfSuspended("stage-lattice-replacements")) return;
    database->stageLatticeReplacements(names, sign);
    emit("(lattice-replacements-staged " + std::to_string((s32)sign) + " "
         + std::to_string(names.size()) + ")");
  }

  void dredReseed(const std::vector<std::string>& names)
  {
    if (refuseIfSuspended("dred-reseed")) return;
    u64 reseeded = 0, discarded = 0;
    database->dredReseedCandidates(names, reseeded, discarded);
    emit("(dred-reseeded " + std::to_string(reseeded) + " "
         + std::to_string(discarded) + ")");
  }

  void emitUpdateCountsValid()
  {
    emit(database->updateCountsValid() ? "(update-counts-valid 1)"
                                       : "(update-counts-valid 0)");
  }

  void beginUpdateEpoch(u64 expected)
  {
    if (refuseIfSuspended("begin-update")) return;
    std::string why;
    const bool ok = database->beginUpdateEpoch(expected, why);
    emit(ok ? ("(update-begun " + std::to_string(expected) + ")")
            : (std::string("(error \"begin-update: ") + why + "\")"));
  }

  void commitUpdateEpoch()
  {
    if (refuseIfSuspended("commit-update")) return;
    std::string why;
    const bool counts_ok = database->commitUpdateEpoch(why);
    if (!why.empty())
      emit(std::string("(error \"commit-update: ") + why + "\")");
    else
      emit("(update-committed "
           + std::to_string(database->getUpdateEpochId()) + " "
           + (counts_ok ? "counts-valid" : "counts-invalid") + ")");
  }

  void abortUpdateEpoch()
  {
    database->abortUpdateEpoch();
    emit("(update-aborted)");
  }

  void emitUpdateEpoch()
  {
    emit("(update-epoch " + std::to_string(database->getUpdateEpochId())
         + (database->updateActive() ? " active)" : " settled)"));
  }

  void exerciseSignedUnderflow()
  {
    emit(database->exerciseSignedUnderflow()
           ? "(signed-underflow-recovered)"
           : "(error \"signed underflow was accepted\")");
  }

  // Multi-tuple staging (0.C): the delta-entry flush's batch enters the
  // pending send-shards in one action -- same exact-once path as
  // stageTuple, one plugin instead of one per tuple.
  void stageBatch(const std::string& rel,
                  const std::vector<std::vector<u64>>& ts)
  {
    if (refuseIfSuspended("stage-batch")) return;
    slog::Relation* r = database->getRelation(rel);
    if (!r) { emit(std::string("(error \"stage-batch: no relation ") + rel + "\")"); return; }
    InsertBatch* b = new InsertBatch();
    for (const auto& t : ts)
    {
      if (b->usage + t.size() > batch_size_max)
      {
        r->sendBatch(b);
        b = new InsertBatch();
      }
      for (size_t i = 0; i < t.size(); ++i)
        b->data[b->usage + i] = t[i];
      b->usage += (u32)t.size();
    }
    r->sendBatch(b);
  }

  // Rename / drop as ENVIRONMENT operations (docs/incremental.md §0.7,
  // 0.D1): rebind or unbind the name in the current-position map -- never
  // a rekey of the physical registry, so old versions at old positions
  // keep resolving.  A rename's target must be unbound; machinery names
  // ($-prefixed: stats, sequence-occurrence, demand internals) are owned
  // by the daemon/compiler and refuse.  Replies (renamed R S 0|1) /
  // (dropped R 0|1); (schema) reflects the new environment for free.
  void renameRel(const std::string& from, const std::string& to)
  {
    if (refuseIfSuspended("rename-rel")) return;
    const bool ok = (from[0] != '$') && (to[0] != '$')
                    && database->renameRelation(from, to);
    if (ok) needs_reload = true;
    emit(std::string("(renamed ") + from + " " + to + " " + (ok ? "1" : "0") + ")");
  }

  void dropRel(const std::string& name)
  {
    if (refuseIfSuspended("drop-rel")) return;
    const bool ok = (name[0] != '$') && database->dropRelation(name);
    if (ok) needs_reload = true;
    emit(std::string("(dropped ") + name + " " + (ok ? "1" : "0") + ")");
  }

  // Import a mini bin-database as a bulk batch payload (0.C1, transport 2
  // of §0.3): importDatabaseBIN with an optional name-map -- the first
  // real caller of its rename parameter (the D4 seam).  `pos < 0` (the
  // default) merges into the LATEST versions and is a boundary event like
  // open; `pos >= 0` is an ANCHORED import (0.E0b): the payload lands in
  // the versions current at that position, apply-only -- the driver owns
  // propagation (the anchored walk), and no position is consumed (like
  // add-batch, it updates a version in place rather than opening one).
  void importDelta(const std::string& dir,
                   const std::unordered_map<std::string, std::string>& name_map,
                   s64 pos = -1)
  {
    if (refuseIfSuspended("import-delta")) return;
    database->importDatabaseBIN(dir + "/", false, name_map, pos, true);
    if (pos < 0)
    {
      database->advancePosition();   // boundary event (§0.4/B0), as in open
      needs_reload = true;
    }
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

  // Bind an extern demand relation to its oracle for one stratum (docs/
  // smt.md): the generated plugin calls this for every stratum that writes
  // the demand struct.  Registers the dispatch and harvest tasks; the
  // binding itself (answered set, completion queue) lives in the registry
  // and persists across strata and hot swaps.
  void bindOracle(Stratum* s, const std::string& oracle_name,
                  const std::string& demand_rel, const std::string& ans_rel)
  {
    Relation* drel = database->getRelation(demand_rel);
    Relation* arel = database->getRelation(ans_rel);
    if (drel == nullptr || arel == nullptr)
      fatal("bindOracle: relations " + demand_rel + " / " + ans_rel
            + " must be registered first");
    OracleBinding* b = oracle_registry->bind(oracle_name, demand_rel, ans_rel);
    s->addTask(phase_read, new OracleDispatchTask(database, oracle_registry, b, drel, arel));
    s->addTask(phase_read, new OracleHarvestTask(database, oracle_registry, b, arel));
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
    // Re-entry hygiene (docs/incremental.md 0.B3): a re-push of an
    // already-RUN stratum (same name = same content hash) supersedes it.
    // Free the dead predecessor's task objects now -- their index bindings
    // dangle at the next reload anyway and it never re-runs (next_unrun is
    // past it) -- leaving a cheap husk (name/scc_id/fixpoint_msg).  Task
    // destructors live in the retained .so (never dlclosed mid-run), so
    // deletion is safe: the hot-swap argument.  Long-lived sessions thus
    // hold live tasks only for each stratum's LATEST incarnation; the
    // pausing.md §12 bind()-reuse seam (no pipeline growth at all) stays
    // parked unless task re-construction ever shows up in profiles --
    // the reload, not registration, dominates re-entry (B5's target).
    for (size_t i = 0; i < next_unrun && i < pipeline.size(); ++i)
      if (pipeline[i]->name == s->name)
        pipeline[i]->clearTasksForHusk();
    s->semantic_instance = !next_push_transient && !next_push_maintenance;
    next_push_maintenance = false;
    // Capture the exact output instances BEFORE positional resolution is
    // reset.  Several strata may name the same version; aliases do not mint
    // another id.
    for (const std::string& name : s->read_rels)
    {
      Relation* r = database->getRelation(name);
      if (r != nullptr)
        s->read_versions.push_back({name, r->getVersionId()});
    }
    for (const std::string& name : s->dynamic_rels)
    {
      Relation* r = database->getRelation(name);
      if (r != nullptr)
      {
        s->write_versions.push_back({name, r->getVersionId()});
        s->addWriteVersionId(r->getVersionId());
      }
    }
    auto unique_bindings = [](auto& bindings)
    {
      std::sort(bindings.begin(), bindings.end());
      bindings.erase(std::unique(bindings.begin(), bindings.end()), bindings.end());
    };
    unique_bindings(s->read_versions);
    unique_bindings(s->write_versions);
    std::sort(s->write_version_ids.begin(), s->write_version_ids.end());
    s->write_version_ids.erase(
      std::unique(s->write_version_ids.begin(), s->write_version_ids.end()),
      s->write_version_ids.end());
    // Registration is over: resolution returns to the latest environment
    // (a positional bind-at covers exactly one beginStratum..push window).
    database->setBindPosition(-1);
    database->clearBindVersions();
    if (next_push_transient)
    {
      next_push_transient = false;
      s->scc_id = (u32)pipeline.size();
      s->pipeline_pos = database->currentPosition();
      transient_run = s;
      return;
    }
    s->scc_id = (u32)pipeline.size();
    // A fresh stratum is a boundary event (docs/incremental.md §0.4/B0): it
    // occupied the current version-environment position while registering
    // (its getRelation binds resolved there); record it and advance.  The
    // hot-swap re-push above never reaches here, so an upgrade neither moves
    // the counter nor rebinds positions.
    s->pipeline_pos = database->currentPosition();
    if (s->semantic_instance)
      for (u64 vid : s->write_version_ids)
      {
        Relation* r = database->getRelationByVersionId(vid);
        if (r != nullptr) r->addSemanticWriter(s->scc_id);
      }
    database->advancePosition();
    pipeline.push_back(s);
  }

  // Segment boundary (docs/incremental.md §0.4-§0.5, B0): the driver
  // announces the relation names the upcoming segment's rules write.  Each
  // already-bound written name is rebound to a NEW physical version (full
  // copy of its predecessor -- the implicit inheritance rule R@(k+1) ⊇ R@k);
  // untouched names keep (alias) their current version.  Old versions stay
  // registered and positionally addressable but leave every run/save/reload
  // path.  The boundary itself consumes one pipeline position, so queries at
  // the pre-boundary position still see the predecessors.
  void beginSegment(const std::vector<std::string>& writes)
  {
    std::vector<std::pair<std::string, std::string>> keyed;
    for (const std::string& name : writes) keyed.push_back({name, ""});
    beginSegment(keyed);
  }

  void beginSegment(const std::vector<std::pair<std::string, std::string>>& writes)
  {
    if (refuseIfSuspended("begin-segment")) return;
    u32 versioned = 0;
    for (const auto& write : writes)
    {
      const std::string& name = write.first;
      const std::string& key = write.second;
      if (database->getRelation(name) != nullptr)
      {
        if (database->newVersion(name, key) != nullptr) ++versioned;
      }
      else
        database->planVersionKey(name, key);
    }
    const u32 pos = database->currentPosition();
    database->advancePosition();
    // A boundary that versioned nothing is still an event (the driver
    // mirrors the position counter deterministically); re-staging is only
    // needed when a copy actually replaced a bound version.
    if (versioned > 0)
      needs_reload = true;
    emit("(segment " + std::to_string(pos) + " " + std::to_string(versioned) + ")");
  }

  // JIT event-time input injection: create a successor version at the current
  // tip without adding a rule writer.  Existing-slot edits continue to use
  // add/del-batch-at.  Historical insertion requires rebuilding a recipe
  // branch and is deliberately not faked by appending a tip binding.
  void injectVersion(const std::string& name, const std::string& version_key)
  {
    if (refuseIfSuspended("inject-version")) return;
    if (database->hasVersionKey(version_key))
    {
      emit(std::string("(error \"inject-version: duplicate VersionKey ")
           + version_key + "\")");
      return;
    }
    Relation* r = database->newVersion(name, version_key);
    if (r == nullptr)
    {
      emit(std::string("(error \"inject-version: no relation ") + name + "\")");
      return;
    }
    const u32 pos = database->currentPosition();
    database->advancePosition();
    needs_reload = true;
    emit("(injected " + name + " " + std::to_string(pos) + " "
         + std::to_string(r->getVersionId()) + ")");
  }

  // Emit the pipeline introspection line (docs/incremental.md §0.4):
  //   (pipeline (pos P) (strata (s SCC POS "NAME") ...)
  //             (rel NAME (v ORD POS SIZE) ...) ...)
  // strata carry their bind positions so a driver can compute which strata
  // sit at-or-after a version's boundary (the B1 cone filter) without
  // mirroring the event counter.
  void emitPipeline()
  {
    std::string s = "(pipeline (pos "
                  + std::to_string(database->currentPosition())
                  + ") (evaluation \"" + database->getEvaluationId()
                  + "\") (update-epoch "
                  + std::to_string(database->getUpdateEpochId())
                  + ") (strata";
    for (Stratum* st : pipeline)
    {
      s += " (s " + std::to_string(st->scc_id) + " "
         + std::to_string(st->pipeline_pos) + " \"" + st->name + "\" (kind "
         + (st->semantic_instance ? "semantic" : "maintenance") + ") (reads";
      for (const auto& binding : st->read_versions)
        s += " (" + binding.first + " " + std::to_string(binding.second) + ")";
      s += ") (write-map";
      for (const auto& binding : st->write_versions)
        s += " (" + binding.first + " " + std::to_string(binding.second) + ")";
      s += ") (writes";
      for (u64 vid : st->write_version_ids)
        s += " " + std::to_string(vid);
      s += "))";
    }
    s += ")" + database->versionIdsSexpr() + database->relChainsSexpr() + ")";
    emit(s);
  }

  void setEvaluationId(const std::string& id)
  {
    database->setEvaluationId(id);
    emit("(evaluation-set)");
  }

  void beginCountEpoch(const std::vector<u64>& vids)
  {
    if (refuseIfSuspended("begin-count-epoch")) return;
    std::string why;
    const bool ok = database->beginCountEpoch(vids, why);
    emit(ok ? "(count-epoch-begun)"
            : (std::string("(error \"count epoch: ") + why + "\")"));
  }

  void commitCountEpoch(const std::vector<u64>& vids)
  {
    if (refuseIfSuspended("commit-count-epoch")) return;
    std::string why;
    const bool ok = database->commitCountEpoch(vids, why);
    emit(ok ? "(count-epoch-committed)"
            : (std::string("(error \"count epoch: ") + why + "\")"));
  }

  void abortCountEpoch(const std::vector<u64>& vids)
  {
    database->abortCountEpoch(vids);
    emit("(count-epoch-aborted)");
  }

  void coverCountWriter(u32 scc)
  {
    if (refuseIfSuspended("cover-count-writer")) return;
    Stratum* found = nullptr;
    for (Stratum* st : pipeline)
      if (st != nullptr && st->scc_id == scc)
      {
        found = st;
        break;
      }
    if (found == nullptr || !found->semantic_instance)
    {
      emit(std::string("(error \"count writer ") + std::to_string(scc)
           + " is not a semantic stratum instance\")");
      return;
    }
    for (u64 vid : found->write_version_ids)
    {
      Relation* r = database->getRelationByVersionId(vid);
      if (r != nullptr) r->coverCountWriter(scc);
    }
    emit(std::string("(count-writer-covered ") + std::to_string(scc) + ")");
  }

  // Versioned sizes (§0.4 addressing): every relation resolved at position P
  // (last write at-or-before P; absent names simply don't appear).
  void emitSizesAt(u32 pos)
  {
    emit(database->sizesAt(pos));
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
    if (!suspended && transient_run == nullptr && next_unrun >= pipeline.size())
    {
      if (pipeline.empty()) emit("(idle)");
      else emit(pipeline.back()->fixpoint_msg);   // idempotent re-confirm
      return;
    }

    const bool transient = transient_run != nullptr;
    Stratum* s = transient ? transient_run : pipeline[next_unrun];
    const RunStatus st = database->continueStratum(s, b, !suspended, true);

    char buf[192];
    if (st.fixpoint)
    {
      if (!transient)
      {
        ++next_unrun;
        needs_reload = true;
        // runtime statistics (docs/stats.md): one $stat_fixpoint row and this
        // stratum's accumulated $stat_fires rows, materialized immediately so
        // output actions after the final stratum see them
        database->publishStratumStats(s->scc_id, s->name, st.iteration,
                                      st.ms_total);
      }
      std::snprintf(buf, sizeof(buf), "(fixpoint %u \"%s\" %u %.3f)",
                    s->scc_id, s->name.c_str(), st.iteration, st.ms_total);
      s->fixpoint_msg = buf;
      emit(s->fixpoint_msg);
      if (transient)
      {
        transient_run = nullptr;
        delete s;
      }
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
