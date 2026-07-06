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
#include <boost/functional/hash.hpp>
#include <boost/unordered_map.hpp>

#define bucket_bits 5
#define bucket_count (((u32)1) << bucket_bits)
#define phase_count 3
#define phase_write 0
#define phase_read 1
#define phase_intern 2
#define batch_size_max (4*1024-1)


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

  // Lattice (map) relation metadata (docs/lattices.md): LAT_NONE for plain
  // relations; the clamp words realize #:floor/#:ceiling.  lat_spec is the
  // canonical surface token ("min-int-floor-0", "count", "flat-value", ...)
  // -- carried opaquely into the on-disk directory name so `open` can
  // re-register the relation as a lattice with the right kind and clamps,
  // and so the compiler-side manifest scan can reconstruct the valuespec.
  u32 lattice_kind = LAT_NONE;
  bool lat_has_floor = false, lat_has_ceil = false;
  u64 lat_floor = 0, lat_ceil = 0;
  std::string lat_spec;
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

  // ---- lattice (map) relations: docs/lattices.md ----
  // A lattice relation's last storage column is the value; its non-delta
  // indices are payload maps (BTreeMapIndex) merged by the kind's join.
  void setLattice(u32 kind, bool has_floor, u64 floorw, bool has_ceil, u64 ceilw,
                  const std::string& spec)
  {
    lattice_kind = kind;
    lat_has_floor = has_floor;
    lat_floor = floorw;
    lat_has_ceil = has_ceil;
    lat_ceil = ceilw;
    lat_spec = spec;
  }
  u32 latticeKind() { return lattice_kind; }
  bool isLattice() { return lattice_kind != LAT_NONE; }
  const std::string& latticeSpec() { return lat_spec; }

  // Parse the canonical spec token back into kind + clamps (the inverse of
  // what the compiler emits into setLattice): "min-int[-floor-V]",
  // "max-float[-ceiling-V]", "count", "flat-<T>".  Used by the open path.
  static u32 latKindOfSpec(const std::string& s)
  {
    if (s.rfind("min", 0) == 0)   return LAT_MIN;
    if (s.rfind("max", 0) == 0)   return LAT_MAX;
    if (s.rfind("count", 0) == 0) return LAT_COUNT;
    if (s.rfind("flat", 0) == 0)  return LAT_FLAT;
    fatal("Unrecognized lattice spec token: " + s);
    return LAT_NONE;
  }
  static u64 latClampOfSpec(const std::string& s, const std::string& valstr)
  {
    const bool isfloat = s.find("-float") != std::string::npos;
    return isfloat ? float_encode(std::atof(valstr.c_str()))
                   : s32_encode(std::atoi(valstr.c_str()));
  }
  void setLatticeFromSpec(const std::string& s)
  {
    bool hf = false, hc = false;
    u64 fw = 0, cw = 0;
    const auto pf = s.find("-floor-");
    const auto pc = s.find("-ceiling-");
    if (pf != std::string::npos) { hf = true; fw = latClampOfSpec(s, s.substr(pf + 7)); }
    if (pc != std::string::npos) { hc = true; cw = latClampOfSpec(s, s.substr(pc + 9)); }
    setLattice(latKindOfSpec(s), hf, fw, hc, cw, s);
  }

  // Register a payload-map index (non-delta only).  `ord` is a FULL-length
  // ordering whose last entry is the value column (storage arity-1), so the
  // generic cold paths see arity-wide rows; A is the storage arity.  Call
  // setLattice first: the kind/clamp metadata is copied into each bucket.
  template <u16 A>
  void addMapIndex(const std::vector<u16>& ord)
  {
    indices[ord] = new Index*[bucket_count];
    auto& indices_ord = indices[ord];
    for (u32 i = 0; i < bucket_count; ++i)
    {
      auto* idx = new BTreeMapIndex<A - 1>();
      idx->lat_kind = lattice_kind;
      idx->lat_has_floor = lat_has_floor;
      idx->lat_floor = lat_floor;
      idx->lat_has_ceil = lat_has_ceil;
      idx->lat_ceil = lat_ceil;
      indices_ord[i] = idx;
    }
    if (!ord.empty())
    {
      u16 lead = ord[0];
      if (std::find(write_leadcols.begin(), write_leadcols.end(), lead)
	  == write_leadcols.end())
	write_leadcols.push_back(lead);
    }
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

  // Register the identity-ordering index if the relation has no index at
  // all, so the daemon can materialize data it loads itself (an opened or
  // refreshed database with no program yet).  Runtime-constructed via
  // makeIndex/makeMapIndex (index.h); a program's own indices arrive later
  // as usual.  A lattice relation gets a payload map so out-of-band
  // ingestion merges (setLattice must have been called first).
  void ensureDefaultIndex()
  {
    if (getAnyIndex())
      return;
    std::vector<u16> ord(arity);
    for (u16 c = 0; c < arity; ++c)
      ord[c] = c;
    Index** arr = new Index*[bucket_count];
    for (u32 b = 0; b < bucket_count; ++b)
      arr[b] = isLattice()
	? makeMapIndex(arity - 1, lattice_kind,
		       lat_has_floor, lat_floor, lat_has_ceil, lat_ceil)
	: makeIndex(arity);
    indices[ord] = arr;
    if (std::find(write_leadcols.begin(), write_leadcols.end(), (u16)0)
	== write_leadcols.end())
      write_leadcols.push_back(0);
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

  // The number of (distinct) tuples currently indexed.  Every non-delta
  // index holds exactly the relation's full tuple set and the underlying
  // btrees maintain their size, so this is a 32-bucket sum -- accurate at
  // any phase boundary, no separate counter to keep in sync.  0 for an
  // index-free relation (a temp, or mid-reload).
  u64 tupleCount()
  {
    auto ord = getAnyIndex();
    if (ord == 0) return 0;
    Index** rootnode = getIndex(*ord, false);
    u64 n = 0;
    for (u16 b = 0; b < bucket_count; ++b)
      n += rootnode[b]->size();
    return n;
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

  // Drop every tuple while KEEPING the index registrations (contrast
  // clearAllIndices, which removes the indices themselves): empties each
  // index bucket, the pending delta, and the send shards.  Used to refresh
  // a relation's contents from disk.
  void clearContents()
  {
    for (const auto& it : indices)
      for (u16 b = 0; b < bucket_count; ++b)
	it.second[b]->clear();
    for (const auto& it : deltaindices)
      for (u16 b = 0; b < bucket_count; ++b)
	it.second[b]->clear();
    for (InsertBatch* ib : *delta)
      delete ib;
    delta->clear();
    for (auto& shard : send_shards)
    {
      for (InsertBatch* ib : shard)
	delete ib;
      shard.clear();
    }
  }

  // Insert every (non-null) tuple of the current delta into all registered
  // indices, through the arity-generic Index::insertTuple cold path.  The
  // daemon cannot instantiate the templated WriteTask<A>s itself (those live
  // in generated code), so out-of-band ingestion -- refreshing a relation
  // from disk between runs -- goes through here instead of the write phase.
  void ingestDelta()
  {
    for (InsertBatch* batch : *delta)
      for (u32 j = 0; j < batch->usage; j += arity)
      {
	if (batch->data[j] == slog_null)
	  continue;
	const u64* t = batch->data + j;
	for (const auto& it : indices)
	  it.second[buckethash(t[it.first[0]])]->insertTuple(t, it.first.data());
      }
  }
};


// The object representation of one stratum of rules: the write/read/intern
// tasks the compiler generated for it, plus metadata.  Strata are pushed to
// the Daemon's pipeline by generated plugin .so's and stay resident after
// running (daemon.h); the Database also builds short-lived internal strata
// for its disk and reload work.  A Stratum owns its tasks.
class Stratum
{
public:
  std::string name;
  // once[phase] tasks run only in the stratum's first iteration (facts,
  // rules over closed relations, initial index ingestion); every[phase]
  // tasks run each iteration until fixpoint.
  std::vector<Task*> once[phase_count];
  std::vector<Task*> every[phase_count];
  // relations this stratum's rules grow -- the seam for incremental
  // recomputation later (push a delta into a stratum, replay downstream)
  std::vector<std::string> dynamic_rels;

  Stratum(const std::string& _name) : name(_name) {}

  ~Stratum()
  {
    for (u16 p = 0; p < phase_count; ++p)
    {
      for (Task* t : once[p]) delete t;
      for (Task* t : every[p]) delete t;
    }
  }

  void addTask(u16 phase, Task* task, bool once_only = false)
  {
    (once_only ? once[phase] : every[phase]).push_back(task);
  }

  void addDynamicRel(const std::string& r) { dynamic_rels.push_back(r); }
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
  // per-relation on-disk modification times, recorded at each load/write,
  // backing relationChangedOnDisk
  std::unordered_map<std::string, std::filesystem::file_time_type> disk_mtimes;
  // the stratum currently executing (its `every` tasks refill the queues)
  const Stratum* running = nullptr;
  // Work distribution: an atomic cursor per phase over the running stratum's
  // task vectors (once[phase] first -- iteration 0 only -- then every[phase]).
  // Workers claim tasks by fetch_add; the sentinel resets the cursor after
  // each phase's barrier for the next iteration.  This replaces a
  // fixed-capacity boost::lockfree::queue whose unchecked push() SILENTLY
  // DROPPED every task beyond its 8192 capacity -- large generated strata
  // (the Patricia set/map library exceeds 9000 read tasks) lost late-
  // registered rules entirely, converging to wrong fixpoints.
  std::atomic<u64> task_cursor[phase_count];
  std::atomic<bool> once_pending[phase_count];
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
  Database(u32 _thread_count)
  {
    thread_count = _thread_count;
    iteration_count = 0;
    struct_id_max = 1;
    string_table = new InternTable<utf8string>();
  }

  ~Database()
  {
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

  // All relations by name (iterate + Relation::tupleCount for statistics).
  const std::unordered_map<std::string, Relation*>& getRelations()
  {
    return relations;
  }

  // Distinct-tuple count of a relation; 0 if unknown or index-free.
  u64 relationSize(const std::string& name)
  {
    auto it = relations.find(name);
    return (it == relations.end()) ? 0 : it->second->tupleCount();
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

  // Reset phase `phase` for its next pass: only `every` tasks from here on
  // (the once tasks were consumed by the first pass), cursor back to zero.
  // Called single-threaded (sentinel, after the phase barrier); the cursor
  // is not read again until every thread passes the next iteration barrier.
  void reloadPhaseQueue(u32 phase)
  {
    once_pending[phase] = false;
    task_cursor[phase] = 0;
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
    const std::vector<Task*>& once = running->once[phase];
    const std::vector<Task*>& every = running->every[phase];
    const u64 n_once = once_pending[phase] ? once.size() : 0;
    const u64 total = n_once + every.size();
    for (;;)
    {
      const u64 i = task_cursor[phase].fetch_add(1);
      if (i >= total)
        break;
      (i < n_once ? once[i] : every[i - n_once])->work();
    }

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

  // Execute one stratum: run its tasks to fixpoint (or for a single pass).
  // The stratum owns its tasks and survives the run unchanged, so a resident
  // pipeline stratum can be re-run later (after re-binding -- see daemon.h).
  void runStratum(Stratum* s, bool tofixpoint = true)
  {
    running = s;
    for (u32 i = 0; i < phase_count; ++i)
    {
      once_pending[i] = true;   // first pass includes the once tasks
      task_cursor[i] = 0;
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

    // Nothing to drain: cursors are reset per stratum in the loop above.
    running = nullptr;
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
    else if (v == slog_lat_top)
      return "(top)";              // a flat lattice's top element
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
			const std::string& name,
			u32 lat_kind = LAT_NONE)
  {
    // rewrite_ord[i] = index-order position of storage column i.
    std::vector<u16> rewrite_ord(ord.size(), 0);
    for (u16 i = 0; i < ord.size(); ++i)
      rewrite_ord[ord[i]] = i;
    const u16 n = (u16)ord.size();

    node->forEach([&](const u64* t)  // t is the tuple in index order
    {
      // line[d] holds the value at index level d; index level d stores
      // storage column ord[d], so a struct's id column (storage 0) sits at
      // the level with ord[d]==0 and is rendered as the relation name.
      // (rewrite_ord[d]==0 is NOT equivalent unless ord is self-inverse --
      // a 3-cycle ordering used to scramble struct CSV rows here.)
      std::vector<std::string> line(n);
      for (u16 d = 0; d < n; ++d)
	line[d] = (is_struct && ord[d] == 0) ? name
	  // a count payload prints as its chain point, not a bare integer
	  : (lat_kind == LAT_COUNT && ord[d] == n - 1)
	    ? (s32_decode(t[d]) >= 2 ? "(inf)" : "(one)")
	    : writeValCSV(t[d]);

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

  // Write one relation's rows to <dir>/<name>.csv.
  void writeRelationCSV(const std::string& dir, const std::string& name)
  {
    Relation* rel = relations[name];
    if (rel == 0)
      fatal("Cannot write unknown relation " + name);
    std::string dir_path = dir;
    if (!dir_path.empty() && dir_path.back() != '/' && dir_path.back() != '\\')
      dir_path += "/";
    std::filesystem::create_directories(dir_path);

    const std::vector<u16>* ord = rel->getAnyIndex();
    if (ord)
    {
      std::ofstream os;
      os.open(dir_path + name + ".csv");
      Index** allbuckets = rel->getIndex(*ord, false);
      bool is_struct = (rel->getStructId() > 0);
      for (u16 b = 0; b < bucket_count; ++b)
	writeAllFactsCSV(os, allbuckets[b], *ord, is_struct, name,
			 rel->latticeKind());
      os.close();
    }
  }

  void writeDatabaseCSV(const std::string& db_dir)
  {
    std::filesystem::remove_all(db_dir);
    std::filesystem::create_directory(db_dir);

    for (auto& rel : relations)
      if (!rel.second->isEmpty())
	writeRelationCSV(db_dir, rel.first);

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

  // The on-disk directory for one relation under a database directory (in
  // binary format, structs/tables/lattices differ only in filename
  // metadata; a lattice's spec token rides along so open can re-register
  // its kind and clamps).
  std::string relationDirBIN(const std::string& db_dir,
			     const std::string& name, Relation* rel)
  {
    if (rel->getStructId() > 0)
      return db_dir + "struct." + name
	     + ".arity." + std::to_string(rel->getArity())
	     + ".id." + std::to_string(rel->getStructId()) + "/";
    if (rel->isLattice())
      return db_dir + "lat." + name
	     + ".arity." + std::to_string(rel->getArity())
	     + ".spec." + rel->latticeSpec() + "/";
    return db_dir + "table." + name
	   + ".arity." + std::to_string(rel->getArity()) + "/";
  }

private:
  // Newest write time across a directory's files (::min() if absent/empty).
  static std::filesystem::file_time_type dirMTime(const std::string& dir)
  {
    auto t = std::filesystem::file_time_type::min();
    if (std::filesystem::is_directory(dir))
      for (const auto& e : std::filesystem::directory_iterator(dir))
	t = std::max(t, std::filesystem::last_write_time(e.path()));
    return t;
  }

  // Stage per-bucket tasks writing one relation's .bin files into `s`,
  // replacing whatever the relation's directory held before.
  void stageRelationWriteBIN(Stratum& s, const std::string& db_dir,
			     const std::string& name, Relation* rel)
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

    std::string rel_dir = relationDirBIN(db_dir, name, rel);
    std::filesystem::remove_all(rel_dir);
    std::filesystem::create_directory(rel_dir);

    // Use any index to write the file out (permuted by its ordering)
    const std::vector<u16>* ord = rel->getAnyIndex();
    if (ord)
    {
      Index** allbuckets = rel->getIndex(*ord, false);
      for (u16 b = 0; b < bucket_count; ++b)
	s.addTask(0,
		  new WriteRel(this, rel_dir+std::format("{}",b)+db_out_ext,
			       allbuckets[b], ord),
		  true);
    }
  }

  // Stage tasks (re)writing the interned-strings table into `s`.  Strings
  // are append-only, so rewriting the full table is always safe; relation
  // rows reference strings by content-hashed intern ids, which re-reading
  // resolves identically.
  void stageStringsWrite(Stratum& s, const std::string& db_dir)
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

    std::filesystem::remove_all(db_dir + "value.strings/");
    std::filesystem::create_directory(db_dir + "value.strings/");
    for (u16 i = 0; i < string_table->getWritePartitions(); ++i)
      s.addTask(0,
		new WriteStrings(this, i,
				 db_dir + "value.strings/" + std::to_string(i) + db_out_ext),
		true);
  }

public:
  // Write one relation (plus the strings table its rows may reference)
  // under data/<db_name>/, leaving other relations' files untouched.
  void writeRelationBIN(const std::string& db_name, const std::string& relname)
  {
    Relation* rel = relations[relname];
    if (rel == 0)
      fatal("Cannot write unknown relation " + relname);
    std::string db_dir("data/" + db_name + "/");
    std::filesystem::create_directories(db_dir);

    Stratum s("write " + relname);
    stageRelationWriteBIN(s, db_dir, relname, rel);
    stageStringsWrite(s, db_dir);
    runStratum(&s, false);
    disk_mtimes[relname] = dirMTime(relationDirBIN(db_dir, relname, rel));
    DEBUG("Wrote relation " << relname << " to " << db_dir)
  }

  void writeDatabaseBIN(const std::string& db_name)
  {
    std::string db_dir("data/"+db_name+"/");
    std::filesystem::remove_all(db_dir);
    std::filesystem::create_directories(db_dir);

    Stratum s("write " + db_name);
    for (auto& rel : relations)
      if (!rel.second->isEmpty())
	stageRelationWriteBIN(s, db_dir, rel.first, rel.second);
    stageStringsWrite(s, db_dir);
    runStratum(&s, false);

    for (auto& rel : relations)
      if (!rel.second->isEmpty())
	disk_mtimes[rel.first] = dirMTime(relationDirBIN(db_dir, rel.first, rel.second));
    DEBUG("Wrote Database " << db_name)
  }

private:
  // (Re)read every interned-strings partition under db_dir.  Interning
  // deduplicates by content, so re-reading is idempotent: existing strings
  // keep their ids and genuinely new ones intern fresh.
  void loadStringsBIN(const std::string& db_dir)
  {
    if (!std::filesystem::is_directory(db_dir + "value.strings"))
      return;
    for (const auto& partfile : std::filesystem::directory_iterator(db_dir+"value.strings"))
    {
      std::string path(partfile.path());
      bool gz = path.find(".gz") != std::string::npos;
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
	  intern_string(new utf8string(str));
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
	  intern_string(new utf8string(str));
	}
      }
    }
  }

  // Read one relation directory's .bin/.gz files into the relation's send
  // shards (staged; not yet indexed).
  void readRelationFiles(Relation* rel, const std::string& rel_dir)
  {
    for (const auto& p : std::filesystem::directory_iterator(rel_dir))
    {
      std::string path(p.path());
      if (path.find(".gz") != std::string::npos)
	rel->readGzBIN(path);
      else if (path.find(".bin") != std::string::npos)
	rel->readBIN(path);
    }
  }

public:
  // Open a stored database: register its relations and stage their tuples
  // (the first stratum run ingests them as its iteration-zero delta).
  void loadDatabaseBIN(const std::string& db_dir)
  {
    loadStringsBIN(db_dir);

    for (const auto& entry : std::filesystem::directory_iterator(db_dir))
    {
      std::string path(entry.path());
      if (path.find("value.strings") != std::string::npos)
	continue;

      std::string name(path);
      bool isstruct = name.find("struct.") != std::string::npos;
      bool islat = name.find("/lat.") != std::string::npos;
      if (name.find("table.") != std::string::npos || isstruct || islat)
      {
	if (isstruct)
	  name = name.substr(name.find("struct.")+7);
	else if (islat)
	  name = name.substr(name.find("/lat.")+5);
	else
	  name = name.substr(name.find("table.")+6);

	std::string arity_ext = name.substr(name.find(".arity.")+7);
	std::string arity;
	std::string lat_spec;
	u32 struct_id = 0;
	if (isstruct)
	{
	  arity = arity_ext.substr(0, arity_ext.find(".id."));
	  std::string ext = arity_ext.substr(arity_ext.find(".id.")+4) + "/";
	  struct_id = std::atoi(ext.substr(0, ext.find("/")).c_str());
	}
	else if (islat)
	{
	  arity = arity_ext.substr(0, arity_ext.find(".spec."));
	  lat_spec = arity_ext.substr(arity_ext.find(".spec.")+6);
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

	Relation* rel = new Relation(name, std::atoi(arity.c_str()), struct_id);
	relations[name] = rel;
	rel->initShards(thread_count);
	// lattice metadata before ensureDefaultIndex, which keys on it to
	// build a payload map (so ingestDelta merges rather than inserts)
	if (islat)
	  rel->setLatticeFromSpec(lat_spec);
	readRelationFiles(rel, path);
	// materialize immediately (into a default index) so the database is
	// queryable/writable before any program arrives; a following stratum
	// re-ingests via the deferred reload (Daemon::open sets it)
	rel->ensureDefaultIndex();
	rel->finalizeBatches();
	rel->ingestDelta();
	disk_mtimes[name] = dirMTime(path + "/");
      }
    }

    DEBUG("Loaded Database at: " << db_dir);
  }

  // Replace one relation's contents from its files under data/<db_name>/,
  // keeping its index registrations (contents are re-ingested immediately
  // through the arity-generic index path, so no stratum run is needed).
  // The relation must already exist with the same arity; struct ids and
  // interned-string ids are only stable within the database directory that
  // wrote them, so refresh from the database this instance opened or wrote.
  void loadRelationBIN(const std::string& db_name, const std::string& relname)
  {
    Relation* rel = relations[relname];
    if (rel == 0)
      fatal("Cannot load unknown relation " + relname);
    std::string db_dir("data/" + db_name + "/");
    std::string rel_dir = relationDirBIN(db_dir, relname, rel);
    if (!std::filesystem::is_directory(rel_dir))
      fatal("No on-disk data for relation " + relname + " at " + rel_dir);

    // pick up any strings the on-disk data references (idempotent)
    loadStringsBIN(db_dir);

    rel->clearContents();
    readRelationFiles(rel, rel_dir);
    rel->ensureDefaultIndex();
    rel->finalizeBatches();
    rel->ingestDelta();
    disk_mtimes[relname] = dirMTime(rel_dir);
    DEBUG("Loaded relation " << relname << " from " << db_dir);
  }

  // Has the relation's on-disk data changed since this instance last read
  // or wrote it?  (True for never-synced relations that exist on disk.)
  bool relationChangedOnDisk(const std::string& db_name, const std::string& relname)
  {
    Relation* rel = relations[relname];
    if (rel == 0)
      return false;
    std::string rel_dir = relationDirBIN("data/" + db_name + "/", relname, rel);
    auto it = disk_mtimes.find(relname);
    if (it == disk_mtimes.end())
      return std::filesystem::is_directory(rel_dir);
    return dirMTime(rel_dir) != it->second;
  }

  // Refresh the relation from disk iff it changed; returns whether it did.
  bool refreshRelationBIN(const std::string& db_name, const std::string& relname)
  {
    if (!relationChangedOnDisk(db_name, relname))
      return false;
    loadRelationBIN(db_name, relname);
    return true;
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

    Stratum s("reload");
    for (auto& p : relations)
    {
      // Should be parallelized
      for (u16 b = 0; b < bucket_count; ++b)
	s.addTask(0, new ReloadBatches(p.second, b), true);
      s.addTask(1, new ClearAllIndices(p.second), true);
    }

    runStratum(&s, false);
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




