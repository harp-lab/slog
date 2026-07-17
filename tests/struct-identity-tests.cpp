/** M5 struct intern-identity unit tests (docs/m5-contract.md).
 *
 * Standalone binary; not part of the golden suite.  Build + run:
 *   clang++ -O2 -Wall -std=c++20 -pthread -Idaemon tests/struct-identity-tests.cpp -o build/struct-identity-tests -lgmp
 *   ./build/struct-identity-tests
 *
 * Covers the dictionary/membership split:
 *   - fresh interning assigns distinct ids and dedups repeats (baseline);
 *   - clearContentsToTombstones retains every mapping; re-interning
 *     resurrects the ORIGINAL ids without touching the allocators;
 *   - fresh content after a tombstone mints ABOVE the old ids (no recycle);
 *   - tombstoneStructRow removes the row from every registered ordering
 *     (master, lookup, secondary) while the mapping survives;
 *   - verbatim re-insert with the retained id reconciles (erases) the
 *     tombstone; a MISMATCHED id is identity drift and a LOUD FATAL
 *     (forked child; exit code checked);
 *   - dropTombstones severs: the same content then mints fresh;
 *   - copyTombstonesFrom carries the dictionary across a version copy.
 */

#include <iostream>
#include <string>

// daemon.h establishes the daemon's internal include order (task/database/
// oracle interdependencies); counts.h and index.h ride in through it.
// operators.h supplies the generated-code operator set, including the
// per-bucket InternStructTask this battery drives directly.
#include "daemon.h"
#include "operators.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#include <set>
#include <vector>

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
    dup2(devnull, 2);
    f();
    _exit(0); // reached only if f did NOT fatal
  }
  int status = 0;
  waitpid(pid, &status, 0);
  return WIFEXITED(status) && WEXITSTATUS(status) == 1;
}

// A 3-column struct relation (id + two content columns) with the codegen's
// standard orderings: master (1 2 0), id-led lookup (0 1 2), and one
// permuted secondary (2 1 0).
static Relation* make_pair_rel(const std::string& name = "pair")
{
  Relation* r = new Relation(name, 3, 1);
  r->initShards(1);
  r->addIndex<3>({1, 2, 0}, false);
  r->addIndex<3>({0, 1, 2}, false);
  r->addIndex<3>({2, 1, 0}, false);
  return r;
}

static const std::array<u16, 3> MASTER_ORD{1, 2, 0};

// Push (0-placeholder, a, b) rows through the real per-bucket intern tasks;
// returns the assigned id per input row (slog_null for deduped repeats).
// Rows are then materialized into every ordering, as the write phase would.
// The batch goes into the delta directly (sendBatch's memory accounting
// calls into the OpenMP runtime, which this standalone binary doesn't link).
static std::vector<u64> intern_rows(Database* db, Relation* r,
                                    const std::vector<std::pair<u64, u64>>& rows)
{
  for (InsertBatch* ib : r->getDelta())
    delete ib;
  r->getDelta().clear();
  InsertBatch* b = new InsertBatch();
  for (const auto& p : rows)
  {
    b->data[b->usage++] = 0;
    b->data[b->usage++] = p.first;
    b->data[b->usage++] = p.second;
  }
  r->getDelta().push_back(b);
  for (u16 bk = 0; bk < bucket_count; ++bk)
  {
    InternStructTask<3> t(db, r, MASTER_ORD, bk);
    t.work();
  }
  std::vector<u64> ids;
  for (InsertBatch* ib : r->getDelta())
    for (u32 j = 0; j < ib->usage; j += 3)
    {
      ids.push_back(ib->data[j]);
      if (ib->data[j] != slog_null)
        r->insertTupleAllIndicesPreservingCounts(ib->data + j);
    }
  return ids;
}

static u64 rows_in_ordering(Relation* r, const std::vector<u16>& ord)
{
  u64 n = 0;
  Index** buckets = r->getIndex(ord, false);
  for (u16 b = 0; b < bucket_count; ++b)
    buckets[b]->forEach([&](const u64*) { ++n; });
  return n;
}

static u64 alloc_sum(Relation* r)
{
  u64 s = 0;
  for (u16 b = 0; b < bucket_count; ++b) s += *r->getInternAlloc(b);
  return s;
}

static void resurrection_tests()
{
  Database db(1);
  Relation* r = make_pair_rel();

  // Baseline: fresh interning assigns distinct type-1 ids; repeats dedup.
  auto ids = intern_rows(&db, r, {{1, 2}, {2, 3}, {3, 4}});
  std::set<u64> idset(ids.begin(), ids.end());
  CHECK(ids.size() == 3 && idset.size() == 3, "three distinct fresh ids");
  for (u64 id : ids)
    CHECK(is_struct(id) && decode_struct_id(id) == 1, "type-1 struct encoding");
  const u64 allocs0 = alloc_sum(r);
  CHECK(allocs0 == 3, "three allocations");

  auto dup = intern_rows(&db, r, {{1, 2}});
  CHECK(dup.size() == 1 && dup[0] == slog_null, "live repeat dedups to null");
  CHECK(alloc_sum(r) == allocs0, "dedup allocates nothing");

  // Re-derivation clear: mappings survive as tombstones; membership empties.
  r->clearContentsToTombstones();
  CHECK(r->tombstoneCount() == 3, "all three mappings retained");
  CHECK(rows_in_ordering(r, {1, 2, 0}) == 0, "master emptied");
  CHECK(rows_in_ordering(r, {0, 1, 2}) == 0, "lookup emptied");

  // Resurrection: identical content returns the ORIGINAL ids, in any
  // arrival order, without allocating.
  auto ids2 = intern_rows(&db, r, {{3, 4}, {1, 2}, {2, 3}});
  std::set<u64> idset2(ids2.begin(), ids2.end());
  CHECK(idset2 == idset, "resurrected ids equal the originals");
  CHECK(r->tombstoneCount() == 0, "all tombstones consumed");
  CHECK(alloc_sum(r) == allocs0, "resurrection allocates nothing");

  // No recycle: fresh content after the tombstone cycle mints a NEW id.
  auto fresh = intern_rows(&db, r, {{7, 8}});
  CHECK(fresh.size() == 1 && !idset.count(fresh[0]), "fresh content mints fresh");
  CHECK(alloc_sum(r) == allocs0 + 1, "fresh mint allocates once");

  delete r;
}

static void point_removal_tests()
{
  Database db(1);
  Relation* r = make_pair_rel();
  auto ids = intern_rows(&db, r, {{1, 2}, {2, 3}});

  // Point removal drops the row from EVERY ordering and retains the mapping.
  u64 row[3] = {ids[0], 1, 2};
  CHECK(r->tombstoneStructRow(row), "point removal succeeds");
  CHECK(r->tombstoneCount() == 1, "one mapping retained");
  CHECK(rows_in_ordering(r, {1, 2, 0}) == 1
        && rows_in_ordering(r, {0, 1, 2}) == 1
        && rows_in_ordering(r, {2, 1, 0}) == 1,
        "dead row left master, lookup, and secondary");

  // Reappearance through the intern path resurrects the id.
  auto back = intern_rows(&db, r, {{1, 2}});
  CHECK(back.size() == 1 && back[0] == ids[0], "intern resurrects the id");
  CHECK(r->tombstoneCount() == 0, "tombstone consumed");

  // Verbatim re-insert with the retained id reconciles the tombstone.
  CHECK(r->tombstoneStructRow(row), "re-tombstone for the verbatim case");
  r->insertTupleAllIndices(row);
  CHECK(r->tombstoneCount() == 0, "verbatim same-id insert reconciles");
  CHECK(rows_in_ordering(r, {2, 1, 0}) == 2, "row live again everywhere");

  // Severance: dropping the dictionary makes the same content mint fresh.
  u64 row2[3] = {ids[1], 2, 3};
  CHECK(r->tombstoneStructRow(row2), "tombstone before severance");
  r->dropTombstones();
  CHECK(r->tombstoneCount() == 0, "severance empties the store");
  auto reminted = intern_rows(&db, r, {{2, 3}});
  CHECK(reminted.size() == 1 && reminted[0] != slog_null
        && reminted[0] != ids[1], "severed content remints");

  delete r;
}

static void version_copy_tests()
{
  Database db(1);
  Relation* r = make_pair_rel();
  auto ids = intern_rows(&db, r, {{1, 2}, {2, 3}});
  u64 row[3] = {ids[0], 1, 2};
  CHECK(r->tombstoneStructRow(row), "tombstone in the predecessor");

  // A successor copy carries the dictionary (allocators are covered by
  // copyInternAllocatorsFrom, as in Database::newVersion).
  Relation* nv = make_pair_rel();
  nv->copyInternAllocatorsFrom(*r);
  nv->copyTombstonesFrom(*r);
  Database::forEachNominal(r, [&](const u64* t)
  {
    nv->insertTupleAllIndices(t);
  });
  CHECK(nv->tombstoneCount() == 1, "copy carried the tombstone");
  auto back = intern_rows(&db, nv, {{1, 2}});
  CHECK(back.size() == 1 && back[0] == ids[0],
        "successor resurrects the predecessor's id");

  delete nv;
  delete r;
}

// M4S slice 3 (docs/m4s-contract.md "the chain is the sidecar"): tombstones
// never persist; a load reconstructs each version's dead half from the
// chain -- dict(v) = (live(pred) ∪ dict(pred)) − live(v).  Simulate the
// load by dropping every dictionary from a real registered chain, then
// reconstruct and check the restored mapping carries the ancestor id, the
// pass is idempotent, and a tip re-derivation resurrects rather than mints.
static void chain_reconstruction_tests()
{
  Database db(1);
  Relation* v0 = make_pair_rel("chain");
  db.registerRelation("chain", v0);
  auto ids = intern_rows(&db, v0, {{1, 2}, {3, 4}});
  CHECK(ids.size() == 2 && ids[0] != slog_null && ids[1] != slog_null,
        "chain root interned two rows");

  // segment boundary: the successor copies content, dictionary, allocators
  Relation* v1 = db.newVersion("chain", "v1:test-layer:0:0");
  CHECK(v1 != nullptr && v1 != v0, "newVersion returns a successor");
  // the successor starts with the identity default only; register the
  // canonical master as the next segment's program would
  v1->addIndex<3>({1, 2, 0}, false);

  // tip deletion: (3,4) leaves live membership, identity retained
  u64 row[3] = {ids[1], 3, 4};
  CHECK(v1->tombstoneStructRow(row), "tip point removal");
  CHECK(v1->tombstoneCount() == 1, "tip holds the mapping in-session");

  // simulate a save/load boundary: the dead half is dropped everywhere
  v0->dropTombstones();
  v1->dropTombstones();
  CHECK(v1->tombstoneCount() == 0, "simulated load starts empty");

  // dict(v1) = (live(v0) ∪ dict(v0)) − live(v1) = { (3,4) -> ids[1] }
  const u64 installed = db.reconstructStructTombstones();
  CHECK(installed == 1, "one mapping reconstructed");
  CHECK(v0->tombstoneCount() == 0, "the root needs no dictionary");
  CHECK(v1->tombstoneCount() == 1, "tip mapping restored");
  u64 idw = 0;
  u64 probe[3] = {0, 3, 4};
  CHECK(v1->peekTombstone(buckethash((u64)3), probe, MASTER_ORD.data(), 3, idw)
            && idw == ids[1],
        "reconstructed mapping carries the ancestor id");

  // idempotent over an already-populated dictionary
  CHECK(db.reconstructStructTombstones() == 0, "reconstruction is idempotent");

  // a post-load tip re-derivation resurrects the ancestor id, never mints
  auto back = intern_rows(&db, v1, {{3, 4}});
  CHECK(back.size() == 1 && back[0] == ids[1],
        "post-load re-derivation resurrects the ancestor id");
  CHECK(v1->tombstoneCount() == 0, "resurrection consumed the mapping");
}

// Identity drift must be a loud fatal, not a silent dangling reference:
// verbatim ingestion of retained content under a DIFFERENT id.
static void drift_scenario()
{
  Database db(1);
  Relation* r = make_pair_rel();
  auto ids = intern_rows(&db, r, {{1, 2}});
  u64 row[3] = {ids[0], 1, 2};
  r->tombstoneStructRow(row);
  u64 forged[3] = {struct_encode(1, (77 << bucket_bits) | buckethash((u64)1)), 1, 2};
  r->insertTupleAllIndices(forged);   // must fatal
}

// Two ids for one content inside the store itself is likewise drift.
static void double_install_scenario()
{
  Relation* r = make_pair_rel();
  r->installTombstone({1, 2}, struct_encode(1, 5));
  r->installTombstone({1, 2}, struct_encode(1, 6));   // must fatal
}

int main()
{
  resurrection_tests();
  point_removal_tests();
  version_copy_tests();
  chain_reconstruction_tests();

  CHECK(dies_fatally(drift_scenario), "mismatched-id verbatim insert fatals");
  CHECK(dies_fatally(double_install_scenario), "double-id install fatals");

  std::cout << checks << " checks, " << failures << " failures" << std::endl;
  return failures == 0 ? 0 : 1;
}
