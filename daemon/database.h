/** Slog Databases
 * 
 * Defines a Database as a set of named indices with some dynamically known arity
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once


#include "slogd.h"
#include "intern.h"
#include "gzfile.h"
#include "index.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <format>
#include <filesystem>
#include <algorithm>
#include <thread>
#include <atomic>
#include <barrier>
#include <omp.h>
#include <unordered_map>
#include <boost/lockfree/queue.hpp>
#include <boost/functional/hash.hpp>
#include <boost/unordered_map.hpp>

#define bucket_bits 5
#define bucket_count (((u32)1) << bucket_bits)
#define phase_count 3
#define phase_write 0
#define phase_read 1
#define phase_intern 2
#define batch_size_max (4*1024-1)

#define big_capacity boost::lockfree::capacity<8*1024>

#define buckethash(x) \
  ((((((x) % 90909) * 16777619u) ^ (((x) >> 16)&0x3ffff)) * 16777619u) % bucket_count)


namespace slog
{

  
class Database;

  
class Task
{
public:
  virtual void work() = 0;
  virtual ~Task() = default;
};

  
class alignas(8) InsertBatch
{
public:
  u64 usage;
  u64 data[batch_size_max];
  InsertBatch() : usage(0) { }
};

// A lightweight reference to a single tuple inside a delta batch: the batch and
// the offset of the tuple's first column.  Used by the Stage-B bucketized views
// of the delta so consumers iterate only their bucket instead of rescanning.
struct TupleRef
{
  InsertBatch* batch;
  u32 offset;
};

// One bucket of tuple references.
using RefVec = std::vector<TupleRef>;

  
class Relation
{
private:
  std::string name;
  u16 arity;
  u32 struct_id;
  std::unordered_map<std::vector<u16>, Index**, boost::hash<std::vector<u16>>> indices;
  std::unordered_map<std::vector<u16>, Index**, boost::hash<std::vector<u16>>> deltaindices;
  std::vector<u16> struct_master_index;
  std::vector<u16> struct_lookup_index;
  // The delta consumed (read-only) by this iteration's tasks.
  std::vector<InsertBatch*>* delta;
  // Per-thread send buffers: thread t appends only to send_shards[t], so there
  // are no inter-thread races and nothing to overflow.  After the read phase
  // these are unioned into `delta` for the next iteration (see finalizeBatches).
  std::vector<std::vector<InsertBatch*>> send_shards;
  u64 intern_allocators[bucket_count];

  // Stage B: bucketized views of `delta`, rebuilt once per iteration (reorg).
  // write_leadcols holds the distinct index leading columns we hash-bucket by;
  // leadcol_slot maps a column to its slot in write_leadcols (-1 if unused).
  // write_buckets[slot][bucket] and read_buckets[bucket] hold refs into delta:
  //   - write_buckets[slot][b] = tuples whose buckethash(leadcol) == b
  //     (consumed by WriteTask of indices keyed on that column),
  //   - read_buckets[b] = an even round-robin split (consumed by ReadTask).
  std::vector<u16> write_leadcols;
  std::vector<s16> leadcol_slot;
  u32 last_slot_leadcols = 0;  // write_leadcols.size() when leadcol_slot was last built
  // Per-thread, so the reorg runs in parallel with no races; consumers read
  // across threads (0..thread_count).
  std::vector<std::vector<std::vector<RefVec>>> write_buckets;  // [tid][slot][bucket]
  std::vector<std::vector<RefVec>> read_buckets;                // [tid][bucket]

public:

  Relation(std::string _name, u16 _arity, u32 _struct_id)
    : name(_name), arity(_arity),
      struct_id(_struct_id), indices(), deltaindices(),
      struct_master_index(0), struct_lookup_index(0),
      delta(new std::vector<InsertBatch*>()),
      // Zero the per-bucket struct-id allocators.  These are a plain C array, so
      // without this they hold garbage heap memory; InternStructTask packs the
      // allocator value into the low 38 bits of a struct id, and a garbage value
      // spills into the struct-type-id field (bits 38..51), producing tuples with
      // corrupt (unresolvable) struct ids.  It presented as a flaky crash because
      // fresh heap pages are usually zeroed by the OS -- only heap churn (e.g.
      // more worker threads) lands a Relation on dirty memory and triggers it.
      intern_allocators{}
  {
  }

  ~Relation()
  {
    clearAllIndices();
    if (delta)
    {
      for (InsertBatch* ib : *delta)
	delete ib;
      delete delta;
    }
    for (auto& shard : send_shards)
      for (InsertBatch* ib : shard)
	delete ib;
  }

  // Size the per-thread send buffers; called once thread_count is known.
  void initShards(u32 nthreads)
  {
    if (send_shards.size() < nthreads)
      send_shards.resize(nthreads);
  }

  void clearAllIndices()
  {
    for (const auto& it : indices)
    {
      for (u16 i = 0; i < bucket_count; ++i)
	delete it.second[i];          // virtual ~Index frees the btree
      delete [] it.second;
    }
    indices.clear();

    for (const auto& it : deltaindices)
    {
      for (u16 i = 0; i < bucket_count; ++i)
	delete it.second[i];
      delete [] it.second;
    }
    deltaindices.clear();
  }

  u16 getArity()
  {
    return arity;
  }

  const std::string& getName()
  {
    return name;
  }

  u32 getStructId()
  {
    return struct_id;
  }

  const std::vector<u16>& getMasterIndex()
  {
    if (struct_master_index.size() > 0)
      return struct_master_index;

    for (const auto& kv : indices)
      if (kv.first.size() > 0
	  && kv.first[kv.first.size()-1] == 0)
	struct_master_index = kv.first;

    if (struct_master_index.size() == 0) 
      fatal("Could not find master index.");
    return struct_master_index;
  }

  const std::vector<u16>& getLookupIndex()
  {
    if (struct_lookup_index.size() > 0)
      return struct_lookup_index;

    for (const auto& kv : indices)
      if (kv.first.size() > 0
	  && kv.first[0] == 0)
	struct_lookup_index = kv.first;

    if (struct_lookup_index.size() == 0) 
      fatal("Could not find lookup index.");
    return struct_lookup_index;
  }

  u64* getInternAlloc(u16 b)
  {
    return &(intern_allocators[b]);
  }

  // Templated on arity A (known by the generated code that calls it) so each
  // bucket gets an arity-specialized BTreeIndex<A>, held behind the generic
  // Index* interface.
  template <u16 A>
  void addIndex(const std::vector<u16>& ord, bool delta)
  {
    auto& tbl = delta ? deltaindices : indices;
    tbl[ord] = new Index*[bucket_count];
    auto& indices_ord = tbl[ord];
    for (u32 i = 0; i < bucket_count; ++i)
      indices_ord[i] = new BTreeIndex<A>();

    // Record this index's leading column so reorg hash-buckets the delta by it.
    // WriteTask (delta or not) partitions tuples by buckethash(data[ord[0]]).
    if (!ord.empty())
    {
      u16 lead = ord[0];
      if (std::find(write_leadcols.begin(), write_leadcols.end(), lead)
	  == write_leadcols.end())
	write_leadcols.push_back(lead);
    }
  }

  const std::vector<u16>* getAnyIndex()
  {
    // for writing, reloading (cannot be a delta)
    for (const auto& it : indices)
      return &(it.first);
    return 0;
  }

  bool isEmpty()
  {
    auto ord = getAnyIndex();
    if (ord == 0) return true;
    Index** rootnode = getIndex(*ord, false);
    for (u16 b = 0; b < bucket_count; ++b)
      if (!rootnode[b]->empty())
	return false;
    return true;
  }

  Index**& getIndex(const std::vector<u16>& ord, bool delta)
  {
    if (delta)
    {
      if (!deltaindices.contains(ord))
	fatal("Index does not exist.");
      return deltaindices[ord];
    }
    else
    {
      if (!indices.contains(ord))
	fatal("Index does not exist.");
      return indices[ord];
    }
  }

  std::vector<InsertBatch*>& getDelta()
  {
    return *delta;
  }

  // Size the per-thread bucket buffers; call once (single-threaded) per run,
  // after all indices are registered, before the parallel reorg.
  void ensureReorgBuffers(u32 nthreads)
  {
    const u32 nlead = write_leadcols.size();
    // Rebuild the column->slot map whenever it is stale.  `write_leadcols` grows
    // as programs register indices, and a later program (after a reload) can add
    // a new leading column on a persistent relation -- leaving a previously-built
    // leadcol_slot that maps the new column to -1, which getWriteBucket would then
    // index out of bounds.  Keying the guard on arity alone is unsound because
    // arity is constant across reloads; key it on the leadcol count instead.
    if (leadcol_slot.size() != arity || last_slot_leadcols != nlead)
    {
      leadcol_slot.assign(arity, -1);
      for (u32 s = 0; s < nlead; ++s)
	leadcol_slot[write_leadcols[s]] = (s16)s;
      last_slot_leadcols = nlead;
    }
    write_buckets.assign(nthreads,
	std::vector<std::vector<RefVec>>(nlead, std::vector<RefVec>(bucket_count)));
    read_buckets.assign(nthreads, std::vector<RefVec>(bucket_count));
  }

  // Rebuild thread `tid`'s share of the bucketized views of `delta`.  Thread tid
  // scans the batch slice {tid, tid+nthreads, ...} and routes each non-null
  // tuple into ITS OWN buffers (write_buckets[tid][slot][buckethash(leadcol)]
  // and read_buckets[tid][round-robin]) -- so all threads reorg in parallel with
  // no races.  Consumers read across threads (getWriteBucket/getReadBucket over
  // 0..thread_count).  Called between the intern and iteration barriers; refs
  // stay valid until `delta` is replaced (next finalize).
  void reorgDelta(u32 tid, u32 nthreads)
  {
    // A relation that physically stores tuples must have nonzero arity, or the
    // per-tuple stride below (j += arity) cannot advance -- that turns this into
    // an unbounded-allocation infinite loop (it once OOM-killed the whole login
    // session when a temp was mis-declared with arity 0 while holding width-N
    // tuples).  A genuinely 0-arity (propositional) relation carries no column
    // data to bucketize, so there is nothing to do here either way.
    if (arity == 0)
      return;

    const u32 nlead = write_leadcols.size();
    auto& wb = write_buckets[tid];
    auto& rb = read_buckets[tid];

    for (auto& slot : wb)
      for (auto& bkt : slot)
	bkt.clear();
    for (auto& bkt : rb)
      bkt.clear();

    u32 tup = 0;
    for (u32 i = tid; i < delta->size(); i += nthreads)
    {
      InsertBatch* batch = (*delta)[i];
      for (u32 j = 0; j < batch->usage; j += arity)
      {
	if (batch->data[j] == slog_null)
	  continue;
	TupleRef ref{batch, j};
	for (u32 s = 0; s < nlead; ++s)
	  wb[s][buckethash(batch->data[j + write_leadcols[s]])].push_back(ref);
	rb[(tup / 4) % bucket_count].push_back(ref);
	++tup;
      }
    }
  }

  // Thread `tid`'s refs for the index keyed on `leadcol`, hash-bucket `bucket`.
  RefVec& getWriteBucket(u32 tid, u16 leadcol, u16 bucket)
  {
    return write_buckets[tid][leadcol_slot[leadcol]][bucket];
  }

  // Thread `tid`'s refs for read-phase work partition `bucket`.
  RefVec& getReadBucket(u32 tid, u16 bucket)
  {
    return read_buckets[tid][bucket];
  }

  // Free the consumed delta, then union the per-thread send buffers into the
  // new delta for the next iteration.  Called once (single-threaded, in a
  // barrier completion) after all producers for the phase have finished.
  // Returns whether any new tuples were produced.
  bool finalizeBatches()
  {
    for (InsertBatch* ib : *delta)
      delete ib;
    delta->clear();

    for (auto& shard : send_shards)
    {
      for (InsertBatch* ib : shard)
	delta->push_back(ib);
      shard.clear();
    }

    // Clear delta indices (they hold only the previous iteration's delta).
    for (const auto& it : deltaindices)
      for (u16 i = 0; i < bucket_count; ++i)
	it.second[i]->clear();

    return !delta->empty();
  }

  // Append a produced batch to the calling thread's own shard (no locking;
  // each worker owns one shard).  Empty batches (the generated code flushes a
  // trailing one) are discarded.  Runs inside the OpenMP parallel region, so
  // omp_get_thread_num() yields this worker's stable 0..thread_count-1 index.
  void sendBatch(InsertBatch* b)
  {
    if (b->usage > 0)
      send_shards[omp_get_thread_num()].push_back(b);
    else
      delete b;
  }

  // read a .bin file
  void readBIN(const std::string& path)
  {
    std::ifstream file(path);
    u64 i = 0;
    InsertBatch* batch = new InsertBatch();
    u64 word;
    u64 max_id_seen = 0;
    while (file.read((char*)(void*)&word, 8))
    {
      if (struct_id > 0 && i%arity == 0)
      {
	// This is an id for this struct, so we have to track max_id 
	batch->data[batch->usage + 0] = word;
	// Decode just the per-bucket id and accumulate into max_id_seen
	max_id_seen = std::max(decode_struct_perbucketid(word, bucket_bits), max_id_seen);
      }
      else
	batch->data[batch->usage+(i%arity)] = word;

      // Advance position
      ++i;

      // Also advance position in the batch if i%arity==0
      if (i%arity == 0)
      {
	batch->usage += arity;
	if (batch->usage + arity > batch_size_max)
	{
	  this->sendBatch(batch);
	  batch = new InsertBatch();
	}
      }
    }
    
    if (i % arity > 0)
      fatal("BIN file appears badly formatted!");

    this->sendBatch(batch);

    for (u32 i = 0; i < bucket_count; ++i)
      intern_allocators[i] = max_id_seen+1;
  }

  // read a .gz file
  void readGzBIN(const std::string& path)
  {
    GzReadFile file(path);
    u64 i = 0;
    InsertBatch* batch = new InsertBatch();
    u64 word;
    u64 max_id_seen = 0;
    while (file.read((u8*)(void*)&word, 8))
    {
      if (struct_id > 0 && i%arity == 0)
      {
	// This is an id for this struct, so we have to track max_id 
	batch->data[batch->usage + 0] = word;
	max_id_seen = std::max(word >> 28, max_id_seen);
      }
      else
	batch->data[batch->usage+(i%arity)] = word;

      // Advance position
      ++i;

      // Also advance position in the batch if i%arity==0
      if (i%arity == 0)
      {
	batch->usage += arity;
	if (batch->usage + arity > batch_size_max)
	{
	  this->sendBatch(batch);
	  batch = new InsertBatch();
	}
      }
    }
    
    if (i % arity > 0)
      fatal("Gzipped BIN file appears badly formatted!");

    this->sendBatch(batch);

    for (u32 i = 0; i < bucket_count; ++i)
      intern_allocators[i] = max_id_seen+1;
  }

  // Emit every tuple in `node` into insert batches, in nominal (storage) order.
  // The btree stores tuples in index order; rewrite_ord[i] is the index-order
  // position of storage column i, so t[rewrite_ord[i]] is storage column i.
  InsertBatch* writeAllFacts(InsertBatch* batch,
		     Index* node,
		     const std::vector<u16>& rewrite_ord)
  {
    node->forEach([&](const u64* t)
    {
      for (u16 i = 0; i < arity; ++i)
	batch->data[batch->usage+i] = t[rewrite_ord[i]];
      batch->usage += arity;
      if (batch->usage + arity > batch_size_max)
      {
	this->sendBatch(batch);
	batch = new InsertBatch();
      }
    });
    return batch;
  }

  void reloadInsertBatches(u16 b)
  {
    auto ordptr = getAnyIndex();
    if (ordptr)
    {
      Index* node = getIndex(*ordptr, false)[b];
      std::vector<u16> rewrite_ord(ordptr->size(), 0);
      for (u16 i = 0; i < ordptr->size(); ++i)
	rewrite_ord[ordptr->operator[](i)] = i;
      this->sendBatch(writeAllFacts(new InsertBatch(), node, rewrite_ord));
    }
  }
};


// std::barrier completion functors (run once, by the last arriving thread,
// after all threads arrive and before any are released).  Bodies are defined
// out-of-line below, once Database is complete.  operator() must be noexcept
// to satisfy std::barrier's requirements.
struct IterCompletion { Database* db; void operator()() noexcept; };
struct ReadCompletion { Database* db; bool tofixpoint; void operator()() noexcept; };
struct NoopCompletion { void operator()() noexcept {} };

class Database
{
private:
  friend struct ReadCompletion;

  std::unordered_map<std::string, Relation*> relations;
  std::unordered_map<u32, Relation*> structs_by_id;
  std::vector<Task*> program[phase_count];
  std::vector<Task*> program0[phase_count];
  boost::lockfree::queue<Task*, big_capacity> task_queues[phase_count];
  // Cyclic barriers used to synchronize the worker threads each iteration.
  // Allocated in runProgram once thread_count and tofixpoint are known.
  std::barrier<IterCompletion>* iter_barrier = nullptr;   // resets latest_any_rec
  std::barrier<ReadCompletion>* read_barrier = nullptr;   // finalizes phase_read
  std::barrier<NoopCompletion>* phase_barrier[phase_count] = {};
  std::atomic<bool> latest_any_rec;
  u32 thread_count;
  u32 struct_id_max;
  u32 iteration_count;
  InternTable<utf8string>* string_table;

  
public:
  Database(const std::string& db_name, u32 _thread_count)
  {
    thread_count = _thread_count;
    iteration_count = 0;
    struct_id_max = 1;
    string_table = new InternTable<utf8string>();
    
    loadDatabaseBIN("data/" + db_name + "/");
  }

  Database(u32 _thread_count)
  {
    thread_count = _thread_count;
    iteration_count = 0;
    struct_id_max = 1;
    string_table = new InternTable<utf8string>();
  }

  ~Database()
  {
    clearTasks();
    delete string_table;
    for (auto it : relations)
      delete it.second;
  }
  
  u64 intern_string(utf8string* s)
  {
    return string_table->intern_value(s);
  }
  
  utf8string* lookup_string(u64 v)
  {
    return string_table->lookup_value(v);
  }

  void registerLatestAnyRec(bool _any)
  {
    if (_any) latest_any_rec = _any;
  }

  u32 getIterationCount()
  {
    return iteration_count;
  }

  u32 getThreadCount()
  {
    return thread_count;
  }

  bool getLatestAnyRec()
  {
    return latest_any_rec.load();
  }

  void setLatestAnyRec(bool _any)
  {
    latest_any_rec = _any;
  }

  void addRelation(const std::string& name, u16 arity)
  {
    // Client code must check that relation does not already exist!
    relations[name] = new Relation(name, arity, 0);
    relations[name]->initShards(thread_count);
  }

  void addStruct(const std::string& name, u16 arity)
  {
    // Client code must check that struct does not already exist!
    relations[name] = new Relation(name, arity, struct_id_max++);
    relations[name]->initShards(thread_count);
  }

  Relation* getRelation(const std::string& name)
  {
    return relations[name];
  }

  Relation* getStructById(u32 struct_id)
  {
    if (struct_id > 0 && !structs_by_id.contains(struct_id))
    {
      for (auto& it : relations) 
	if (it.second->getStructId() == struct_id)
	  return structs_by_id[struct_id] = it.second;
    }
    else if (struct_id > 0)
      return structs_by_id[struct_id];

    fatal("Could not find struct by id.");
    return 0;
  }

  void addTask(u16 phase, Task* task, bool isstatic = false)
  {
    if (isstatic)
      program0[phase].push_back(task);
    else
      program[phase].push_back(task);
  }

  void clearTasks()
  {
    for (u16 phase = 0; phase < phase_count; ++phase)
    {
      Task* task;
      while (task_queues[phase].pop(task))
	;
      for (u32 i = 0; i < program[phase].size(); ++i)
	delete program[phase][i];
      for (u32 i = 0; i < program0[phase].size(); ++i)
	delete program0[phase][i];
      program0[phase].clear();
      program[phase].clear();
    }
  }

  void reloadPhaseQueue(u32 phase)
  {
    for (u32 i = 0; i < program[phase].size(); ++i)
      task_queues[phase].push(program[phase][i]);
  }
  // Union every relation's per-thread send buffers into its delta for the next
  // iteration.  Single-threaded: called from a barrier completion (or before
  // the workers start), once all producers for the phase have finished.
  void finalizeAll()
  {
    for (const auto& kv : relations)
      registerLatestAnyRec(kv.second->finalizeBatches());
  }

  // Rebuild every relation's bucketized delta views (Stage B).  Single-threaded
  // runs after intern (delta finalized + deduped) and before the next write
  // phase, so the write/read tasks read their bucket instead of rescanning.
  // Each thread reorgs its own slice into its own buffers (parallel, race-free).
  void reorgAll(u32 tid, u32 nthreads)
  {
    for (const auto& kv : relations)
      kv.second->reorgDelta(tid, nthreads);
  }

  // Size every relation's per-thread bucket buffers (single-threaded).
  void ensureReorgBuffers()
  {
    for (const auto& kv : relations)
      kv.second->ensureReorgBuffers(thread_count);
  }

  void runPhase(u32 phase, bool tofixpoint, bool sentinel)
  {
    Task* task;
    while (task_queues[phase].pop(task))
      task->work();

    // Workers write to their own shards, so there is no draining to do; the
    // read phase's barrier completion unions the shards into the new delta.
    if (phase == phase_read)
      read_barrier->arrive_and_wait();
    else
      phase_barrier[phase]->arrive_and_wait();

    if (sentinel)
      reloadPhaseQueue(phase);
  }

  static void runLoop(Database* db, bool tofixpoint, u32 tid)
  {
    const bool sentinel = (tid == 0);
    const u32 nthreads = db->thread_count;

    // Promote the initial db (e.g. facts loaded by open:) into the delta, then
    // bucketize it for the first write/read phase.  Done by the sentinel alone
    // (nthreads=1 → all batches land in thread 0's buffers; the other threads'
    // buffers are empty, which consumers handle by reading across all threads).
    if (sentinel) { db->finalizeAll(); db->reorgAll(0, 1); }

    db->setLatestAnyRec(true);
    for (db->iteration_count = 0;
         db->getLatestAnyRec(); )
    {
      // Rendezvous to start the iteration; the completion resets the
      // latest-any-received flag for everyone before they proceed.
      db->iter_barrier->arrive_and_wait();

      for (u32 i = 0; i < phase_count; ++i)
        db->runPhase(i, tofixpoint, sentinel);

      if (!tofixpoint) break;
      if (sentinel) ++db->iteration_count;

      // Bucketize the freshly-produced (and interned) delta for the next
      // iteration's write/read.  All threads reorg their own slice in parallel,
      // in the slack between the intern barrier (end of the phase loop) and the
      // next iteration's iter_barrier, which is the rendezvous guaranteeing it
      // completes before the next write phase.  Skipped at the fixpoint (the
      // flag, set during this iteration's read, agrees across all threads).
      if (db->getLatestAnyRec())
        db->reorgAll(tid, nthreads);
    }
  }

  void runProgram(bool tofixpoint = true)
  {
    for (u32 i = 0; i < phase_count; ++i)
    {
      for (u32 j = 0; j < program0[i].size(); ++j)
        task_queues[i].push(program0[i][j]);
      reloadPhaseQueue(i);
    }

    // Make sure every relation has a send buffer per worker thread, and a
    // per-thread set of reorg bucket buffers.
    for (const auto& kv : relations)
    {
      kv.second->initShards(thread_count);
      kv.second->ensureReorgBuffers(thread_count);
    }

    // Allocate the cyclic barriers for this run.
    iter_barrier = new std::barrier<IterCompletion>(thread_count, IterCompletion{this});
    read_barrier = new std::barrier<ReadCompletion>(thread_count, ReadCompletion{this, tofixpoint});
    for (u32 i = 0; i < phase_count; ++i)
      phase_barrier[i] = new std::barrier<NoopCompletion>(thread_count, NoopCompletion{});

    // Spin up the worker threads coarsely around the fixpoint loop.  Each
    // OpenMP thread has a stable id 0..thread_count-1; id 0 is the sentinel.
    #pragma omp parallel num_threads(thread_count)
    {
      runLoop(this, tofixpoint, (u32)omp_get_thread_num());
    }

    delete iter_barrier; iter_barrier = nullptr;
    delete read_barrier; read_barrier = nullptr;
    for (u32 i = 0; i < phase_count; ++i)
    {
      delete phase_barrier[i];
      phase_barrier[i] = nullptr;
    }
    clearTasks();
  }

  std::string writeStructCSV(u64 v)
  {
    // We use std::string because we don't care about codepoints here and need mutability
    u64 struct_id = decode_struct_id(v);
    Relation* rel = getStructById(struct_id);
    std::string tupstr = "(" + rel->getName() + " ";
    const std::vector<u16>& ord = rel->getLookupIndex();
    std::vector<u16> rewrite_ord(ord.size(), 0);
    for (u16 i = 0; i < ord.size(); ++i)
      rewrite_ord[ord[i]] = i;
    Index* node = rel->getIndex(ord, false)[buckethash(v)];
    u64 tuple[256] = {0};

    // The lookup index leads with the id column (ord[0]==0); find the tuple
    // whose id == v (unique) and copy its columns (in index order).
    node->forEach([&](const u64* t)
    {
      if (t[0] == v)
	for (u16 i = 0; i < rewrite_ord.size(); ++i)
	  tuple[i] = t[i];
    });

    // Write tuple out in nominal order
    for (u16 i = 1; i < rewrite_ord.size(); ++i)
      tupstr += writeValCSV(tuple[rewrite_ord[i]]) + " ";

    tupstr[tupstr.size()-1] = ')';
    return tupstr;
  }

  std::string writeValCSV(u64 v)
  {
    if (is_s32(v))
      return std::to_string(s32_decode(v));
    else if (is_str(v))
      return std::string("\"") + str_decode(this,v)->cpp_str() + "\"";
    else if (is_float(v))
    {
      // Shortest round-trippable form, but keep floats visually distinct from
      // ints: an integer-valued double ("2") gets a ".0" suffix.
      std::string s = std::format("{}", float_decode(v));
      if (s.find_first_of(".eEnN") == std::string::npos) s += ".0";
      return s;
    }
    else if (is_struct(v))
      return writeStructCSV(v);
    else
    {
      std::cout << "Top 12 bits : " << std::format("{:b}", v >> 52) << std::endl;
      std::cout << "Next 14 bits : " << std::format("{:b}", 0x3fff&(v >> 38)) << std::endl;
      std::cout << "Next 3 bits : " << std::format("{:b}", 7&(v >> 35)) << std::endl;
      std::cout << "Bottom 35 : " << std::format("{:b}", v&0x7ffffffff) << std::endl;
      fatal("Unrecognized basic value:\n" +std::format("{:b}",v));
      return "";
    }
  }
  
  void writeAllFactsCSV(std::ostream& os,
			Index* node,
			const std::vector<u16>& ord,
			bool is_struct,
			const std::string& name)
  {
    // rewrite_ord[i] = index-order position of storage column i.
    std::vector<u16> rewrite_ord(ord.size(), 0);
    for (u16 i = 0; i < ord.size(); ++i)
      rewrite_ord[ord[i]] = i;
    const u16 n = (u16)ord.size();

    node->forEach([&](const u64* t)  // t is the tuple in index order
    {
      // line[d] holds the value at index level d (a struct's id column, whose
      // index position is 0, is rendered as the relation name).
      std::vector<std::string> line(n);
      for (u16 d = 0; d < n; ++d)
	line[d] = (is_struct && rewrite_ord[d] == 0) ? name : writeValCSV(t[d]);

      if (is_struct)
      {
	u16 len = 0;
	for (u16 i = 0; i < n; ++i) len += line[i].size() + 1;
	std::string sep = (len > 40) ? "\n " : " ";
	os << "(";
	for (u16 i = 0; i < n; ++i)
	  os << line[rewrite_ord[i]] << (i + 1 == n ? "" : sep);
	os << ")" << std::endl;
      }
      else
      {
	for (u16 i = 0; i < n; ++i)
	  os << line[rewrite_ord[i]] << "   ";
	os << std::endl;
      }
    });
  }

  void writeDatabaseCSV(const std::string& db_dir)
  {
    std::filesystem::remove_all(db_dir);
    std::filesystem::create_directory(db_dir);
    
    // Ensure directory path ends with separator
    std::string dir_path = db_dir;
    if (!dir_path.empty() && dir_path.back() != '/' && dir_path.back() != '\\') {
      dir_path += "/";
    }
    
    for (auto& rel : relations)
      if (!rel.second->isEmpty())
      {
	std::ofstream os;
	os.open(dir_path + rel.first + ".csv");
	
	// Use any index to write to disk:
	const std::vector<u16>* ord = rel.second->getAnyIndex();
	if (ord)
        {
	  Index** allbuckets = rel.second->getIndex(*ord, false);
	  bool is_struct = (rel.second->getStructId() > 0);
	  for (u16 b = 0; b < bucket_count; ++b)
	    writeAllFactsCSV(os, allbuckets[b], *ord, is_struct, rel.first);
	  os.close();
	}
      }
  
    DEBUG("Wrote CSV output to " << db_dir)
  }

  // Emit every tuple in nominal (storage) order as little-endian u64 words.
  void writeAllFactsBIN(DBWriteFile& file,
			Index* node,
			const std::vector<u16>& ord)
  {
    const u16 n = (u16)ord.size();
    std::vector<u16> rewrite_ord(n, 0);     // rewrite_ord[i] = index pos of storage col i
    for (u16 i = 0; i < n; ++i)
      rewrite_ord[ord[i]] = i;

    u64 wordbuf[1280];
    u32 pos = 0;
    node->forEach([&](const u64* t)         // t in index order
    {
      for (u16 i = 0; i < n; ++i)
	wordbuf[pos + i] = t[rewrite_ord[i]];
      pos += n;
      if (pos + n > 1280)
      {
	file.write((u8*)(void*)wordbuf, pos << 3);
	pos = 0;
      }
    });
    if (pos > 0)
      file.write((u8*)(void*)wordbuf, pos << 3);
  }

  void writeDatabaseBIN(const std::string& db_name)
  {
    // Loads a parallel program of tasks that writes the DB
    std::string db_dir("data/"+db_name+"/");
    std::filesystem::remove_all(db_dir);
    std::filesystem::create_directory(db_dir);
    for (auto& rel : relations)
      if (!rel.second->isEmpty())
      {
	std::string rel_dir(db_dir);
	// In binary format, structs and relations only differ
	// in their filename meta info
	if (rel.second->getStructId() > 0)
	  rel_dir += "struct." + rel.first
		  + ".arity." + std::to_string(rel.second->getArity())
		  + ".id." + std::to_string(rel.second->getStructId()) + "/";
	else
	  rel_dir += "table." + rel.first
		  + ".arity." + std::to_string(rel.second->getArity()) + "/";

        std::filesystem::create_directory(rel_dir);

	// Use any index to write the file out (permuted by its ordering) 
	const std::vector<u16>* ord = rel.second->getAnyIndex();
	if (ord)
	{
	  class WriteRel : public Task
	  {
	  public:
	    Database* db; std::string path; Index* node;
	    const std::vector<u16>* ord;
	    WriteRel(Database* _db, const std::string& _path, Index* _node,
		      const std::vector<u16>* _ord)
	      : db(_db), path(_path), node(_node), ord(_ord)
	    {}
	    virtual void work()
	    {
	      DBWriteFile file(path);
	      db->writeAllFactsBIN(file, node, *ord);
	    }
	  };
	  
	  Index** allbuckets = rel.second->getIndex(*ord, false);
	  for (u16 b = 0; b < bucket_count; ++b)
	    addTask(0,
		    new WriteRel(this, rel_dir+std::format("{}",b)+db_out_ext, allbuckets[b], ord),
		    true);
	}
      }

    // Save strings table
    {
      class WriteStrings : public Task
      {
      public:
	Database* db; u32 i; std::string path;
	WriteStrings(Database* _db, u32 _i, const std::string& _path)
	  : db(_db), i(_i), path(_path)
	{}
	virtual void work()
	{
	  DBWriteFile file(path);
	  for (auto it = db->string_table->begin(i); it != db->string_table->end(); ++it)
	  {
	    // By saving it *in order* according to the iterator
	    // these strings will end up with the same intern ids
	    // if loaded again in this order exactly
	    file.write((u8*)(*it).c_str(), (*it).size()+1);
	  }
	}
      };
      
      std::filesystem::create_directory(db_dir + "value.strings/");
      for (u16 i = 0; i < string_table->getWritePartitions(); ++i)
	addTask(0,
		new WriteStrings(this, i, db_dir + "value.strings/" + std::to_string(i) + db_out_ext),
		true);
    }
    
    runProgram(false);
    DEBUG("Wrote Database " << db_name)
  }

  void loadDatabaseBIN(const std::string& db_dir)
  {
    class ReadStrings : public Task
    {
    public:
      Database* db; std::string path; bool gz;
      ReadStrings(Database* _db, const std::string& _path, bool iscompressed)
	: db(_db), path(_path), gz(iscompressed)
      {}
      virtual void work()
      {
	if (gz)
	{
	  GzReadFile file(path);
	  u8 byte = 0;
	  while (file.read(&byte, 1))
	  {
	    std::string str;
	    if (byte) str += (char)byte;
	    while(file.read(&byte, 1)
		&& byte > 0)
	      str += (char)byte;
	    db->intern_string(new utf8string(str));
	  }
	}
	else
	{
	  std::ifstream file(path, std::ios::binary);
	  u8 byte = 0;
	  while (file.read(reinterpret_cast<char*>(&byte), 1))
	  {
	    std::string str;
	    if (byte) str += (char)byte;
	    while(file.read(reinterpret_cast<char*>(&byte), 1)
		  && byte > 0)
	      str += (char)byte;
	    db->intern_string(new utf8string(str));
	  }
	}
      }
    };

    class ReadTable : public Task
    {
    public:
      Relation* rel; std::string path; bool gz;
      ReadTable(Relation* _rel, const std::string& _path, bool iscompressed)
	: rel(_rel), path(_path), gz(iscompressed)
      {}
      virtual void work()
      {
	if (gz) rel->readGzBIN(path);
	else rel->readBIN(path);
      }
    };
    
    // Find the intern tables files and load these first:
    for (const auto& entry : std::filesystem::directory_iterator(db_dir))
    {
      std::string path(entry.path());
      if (path.find("value.strings") != std::string::npos)
      {
	for (const auto& partfile : std::filesystem::directory_iterator(db_dir+"value.strings"))
	{
	  if (std::string(partfile.path()).find(".gz") != std::string::npos)
	    addTask(0, new ReadStrings(this, partfile.path(), true), true);
	  else
	    addTask(0, new ReadStrings(this, partfile.path(), false), true);
	}
      }
      else
      {
	std::string name(path);
	bool isstruct = name.find("struct.") != std::string::npos;
	if (name.find("table.") != std::string::npos || isstruct)
	{
	  if (isstruct)
	    name = name.substr(name.find("struct.")+7);
	  else
	    name = name.substr(name.find("table.")+6);
	  
	  std::string arity_ext = name.substr(name.find(".arity.")+7);
	  std::string arity;
	  u32 struct_id = 0;
	  if (isstruct)
	  {
	    arity = arity_ext.substr(0, arity_ext.find(".id."));
	    std::string ext = arity_ext.substr(arity_ext.find(".id.")+4) + "/";
	    struct_id = std::atoi(ext.substr(0, ext.find("/")).c_str());
	  }
	  else
	  {
	    arity_ext += "/";
	    arity = arity_ext.substr(0, arity_ext.find("/"));
	  }
	  struct_id_max = std::max(struct_id_max, struct_id+1);
	
	  name = name.substr(0, name.find(".arity."));
	  if (relations.find(name) != relations.end())
	    fatal(name + " appears to be a duplicated relation");
	  
	  relations[name] = new Relation(name, std::atoi(arity.c_str()), struct_id);
	  for (const auto& p : std::filesystem::directory_iterator(path))
	  {
	    std::string path(p.path());
	    if (path.find(".gz") != std::string::npos)
	      addTask(0, new ReadTable(relations[name], path, true), true);
	    else if (path.find(".bin") != std::string::npos)
	      addTask(0, new ReadTable(relations[name], path, false), true);
	  }
	}
      }
    }

    runProgram(false);
    
    DEBUG("Loaded Database at: " << db_dir);
  }
  
  void reloadInsertBatches()
  {
    class ReloadBatches : public Task
    {
    public:
      Relation* rel; u16 b;
      ReloadBatches(Relation* _rel, u16 _b)
	: rel(_rel), b(_b)
      {}
      virtual void work()
      {
	rel->reloadInsertBatches(b);
      }
    };
    
    class ClearAllIndices : public Task
    {
    public:
      Relation* rel;
      ClearAllIndices(Relation* _rel)
	: rel(_rel)
      {}
      virtual void work()
      {
	rel->clearAllIndices();
      }
    };
    
    for (auto& p : relations)
    {
      // Should be parallelized
      for (u16 b = 0; b < bucket_count; ++b)
	addTask(0, new ReloadBatches(p.second, b), true);
      addTask(1, new ClearAllIndices(p.second), true);
    }
    
    runProgram(false);
  }
};


// Barrier completion bodies (Database is now complete).
inline void IterCompletion::operator()() noexcept
{
  db->setLatestAnyRec(false);
}

inline void ReadCompletion::operator()() noexcept
{
  if (tofixpoint) db->finalizeAll();
}


}; // namespace slog




