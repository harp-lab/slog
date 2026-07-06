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
#include "arena.h"
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
#include <unordered_set>
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
  // LAT_EXTERN (set/map) context: the parsed spec tree (owned) and the
  // database's collection arena, copied into every payload-map bucket at
  // registration (docs/primitives.md §6.1).
  LatSpec* lat_spec_tree = nullptr;
  CollectionArena* lat_arena = nullptr;
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
    delete lat_spec_tree;
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
  // For LAT_EXTERN (set/map specs) the token is parsed into a LatSpec tree
  // and the collection arena rides along to every payload-map bucket.
  void setLattice(u32 kind, bool has_floor, u64 floorw, bool has_ceil, u64 ceilw,
                  const std::string& spec, CollectionArena* arena = nullptr)
  {
    lattice_kind = kind;
    lat_has_floor = has_floor;
    lat_floor = floorw;
    lat_has_ceil = has_ceil;
    lat_ceil = ceilw;
    lat_spec = spec;
    lat_arena = arena;
    delete lat_spec_tree;
    lat_spec_tree = nullptr;
    if (kind == LAT_EXTERN)
    {
      if (arena == nullptr)
	fatal("Collection lattice " + name + " registered without an arena");
      lat_spec_tree = parseLatSpecToken(spec);
      if (lat_spec_tree == nullptr)
	fatal("Malformed collection lattice spec token: " + spec);
    }
  }
  u32 latticeKind() { return lattice_kind; }
  bool isLattice() { return lattice_kind != LAT_NONE; }
  const std::string& latticeSpec() { return lat_spec; }

  // Parse the canonical spec token back into kind + clamps (the inverse of
  // what the compiler emits into setLattice): "min-int[-floor-V]",
  // "max-float[-ceiling-V]", "count", "flat-<T>", "set-<T>",
  // "map-<K>-<spec>".  Used by the open path.
  static u32 latKindOfSpec(const std::string& s)
  {
    if (s.rfind("min", 0) == 0)   return LAT_MIN;
    if (s.rfind("max", 0) == 0)   return LAT_MAX;
    if (s.rfind("count", 0) == 0) return LAT_COUNT;
    if (s.rfind("flat", 0) == 0)  return LAT_FLAT;
    if (s.rfind("set-", 0) == 0 || s.rfind("map-", 0) == 0) return LAT_EXTERN;
    fatal("Unrecognized lattice spec token: " + s);
    return LAT_NONE;
  }
  static u64 latClampOfSpec(const std::string& s, const std::string& valstr)
  {
    const bool isfloat = s.find("-float") != std::string::npos;
    return isfloat ? float_encode(std::atof(valstr.c_str()))
                   : s32_encode(std::atoi(valstr.c_str()));
  }
  void setLatticeFromSpec(const std::string& s, CollectionArena* arena = nullptr)
  {
    const u32 kind = latKindOfSpec(s);
    bool hf = false, hc = false;
    u64 fw = 0, cw = 0;
    // clamps exist only on top-level scalar min/max specs; nested tokens
    // (inside a map value) are forbidden clamps by the compiler, so this
    // substring scan cannot false-fire for the kinds it runs on
    if (kind == LAT_MIN || kind == LAT_MAX)
    {
      const auto pf = s.find("-floor-");
      const auto pc = s.find("-ceiling-");
      if (pf != std::string::npos) { hf = true; fw = latClampOfSpec(s, s.substr(pf + 7)); }
      if (pc != std::string::npos) { hc = true; cw = latClampOfSpec(s, s.substr(pc + 9)); }
    }
    setLattice(kind, hf, fw, hc, cw, s, arena);
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
      idx->lat_spec_tree = lat_spec_tree;
      idx->lat_arena = lat_arena;
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
		       lat_has_floor, lat_floor, lat_has_ceil, lat_ceil,
		       lat_spec_tree, lat_arena)
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

  // Raise every bucket's intern allocator above the largest per-bucket
  // instance id seen in ONE just-read file.  ACCUMULATES via max: a
  // relation's rows arrive as one file per bucket, so overwriting here
  // would leave the allocators seeded by whichever file happened to be
  // read last -- a later fresh intern would then re-issue an id an
  // already-loaded instance owns (silent struct-id collision; db-merge
  // P0).  Monotone growth is always safe, merely id-space-lossy.
  void seedInternAllocators(u64 max_id_seen)
  {
    for (u32 b = 0; b < bucket_count; ++b)
      intern_allocators[b] = std::max(intern_allocators[b], max_id_seen+1);
  }

  // read a .bin file
  void readBIN(const std::string& path)
  {
    if (arity == 0)
      fatal("Cannot read a zero-arity relation file: " + path);
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

    if (file.gcount() != 0)
      fatal("BIN file has a truncated word: " + path);
    if (i % arity > 0)
      fatal("BIN file appears badly formatted!");

    this->sendBatch(batch);

    if (struct_id > 0 && i > 0)
      seedInternAllocators(max_id_seen);
  }

  // read a .gz file
  void readGzBIN(const std::string& path)
  {
    if (arity == 0)
      fatal("Cannot read a zero-arity relation file: " + path);
    GzReadFile file(path);
    u64 i = 0;
    InsertBatch* batch = new InsertBatch();
    u64 word;
    u64 max_id_seen = 0;
    while (true)
    {
      // read() returns a byte count: 1-7 trailing bytes are a truncated
      // word (corrupt file), not a value -- fatal rather than ingest it
      const u32 got = file.read((u8*)(void*)&word, 8);
      if (got == 0) break;
      if (got != 8)
	fatal("Gzipped BIN file has a truncated word: " + path);

      if (struct_id > 0 && i%arity == 0)
      {
	// This is an id for this struct, so we have to track max_id
	batch->data[batch->usage + 0] = word;
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
      fatal("Gzipped BIN file appears badly formatted!");

    this->sendBatch(batch);

    if (struct_id > 0 && i > 0)
      seedInternAllocators(max_id_seen);
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
	insertTupleAllIndices(t);
      }
  }

  // Insert ONE storage-order tuple into every registered (non-delta) index,
  // id-preservingly -- the single-row body of ingestDelta, used by the
  // database merge to materialize remapped rows (lattice payload maps merge
  // via BTreeMapIndex::insertTuple, plain btrees set-dedup).
  void insertTupleAllIndices(const u64* t)
  {
    for (const auto& it : indices)
      it.second[buckethash(t[it.first[0]])]->insertTuple(t, it.first.data());
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
  CollectionArena* cnode_arena;


public:
  Database(u32 _thread_count)
  {
    thread_count = _thread_count;
    iteration_count = 0;
    struct_id_max = 1;
    string_table = new InternTable<utf8string>();
    cnode_arena = new CollectionArena();
  }

  ~Database()
  {
    delete string_table;
    delete cnode_arena;
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

  CollectionArena* collections()
  {
    return cnode_arena;
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
    // is_struct (types.h) requires 0 < sid < 0x3fff; running past the
    // 14-bit field would silently encode garbage words
    if (struct_id_max >= 0x3fff)
      fatal("Struct type-id space exhausted (14-bit NaN-box field)");
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
    // Relations the coming stratum did NOT re-register (no program decl and
    // no compile-time manifest entry -- e.g. relations that exist only in a
    // database imported at RUNTIME) lost their indices to the reload's
    // ClearAllIndices; their dumped rows would be promoted to delta at
    // iteration 0, consumed by no task, and freed -- silent data loss.
    // Restore them the way loadDatabaseBIN materializes an opened database:
    // a default index + immediate ingestion.  The next reload dumps them
    // again, so they survive any number of strata.
    for (const auto& kv : relations)
      if (kv.second->getAnyIndex() == 0)
      {
	kv.second->ensureDefaultIndex();
	kv.second->finalizeBatches();
	kv.second->ingestDelta();
      }

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

  // Render a collection canonically as {k:v k:v ...}, entries in the trie's
  // in-order (ascending unsigned key-word) traversal -- deterministic because
  // the trie shape is a function of content alone.  A set is a map-to-unit,
  // so set entries print as k:1.  cdepth counts COLLECTION nesting (maps as
  // values of maps): the mutual recursion with writeValCSV is stack-bounded
  // only by nesting depth, so fail loudly rather than overflow.
  std::string writeCNodeCSV(u64 v, u32 cdepth)
  {
    if (cdepth > 256)
      fatal("Collection nesting too deep to render (> 256 levels)");
    std::string s = "{";
    bool first = true;
    cnode_arena->foreach(v, [&](u64 k, u64 val)
    {
      if (!first) s += " ";
      first = false;
      s += writeValCSV(k, cdepth+1) + ":" + writeValCSV(val, cdepth+1);
    });
    return s + "}";
  }

  std::string writeValCSV(u64 v, u32 cdepth = 0)
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
    else if (is_cnode(v))
      return writeCNodeCSV(v, cdepth);
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

  // Parse one relation-directory FILENAME (never a full path -- an ancestor
  // directory containing "table." must not misclassify) of the forms
  //   table.<name>.arity.<A>
  //   struct.<name>.arity.<A>.id.<SID>
  //   lat.<name>.arity.<A>.spec.<TOKEN>
  // Returns false for anything else (value.strings, value.nodes, stray
  // files).  Prefixes are anchored at position 0; the name/arity split is
  // on the LAST ".arity." so dotted relation names survive; numeric fields
  // must be all-digits (atoi's silent 0 turned corrupt names into arity-0
  // relations); arity is bounded by max_daemon_arity and struct ids by the
  // 14-bit NaN-box field.  Inverse of relationDirBIN.
  static bool parseRelationDirName(const std::string& fname,
				   std::string& kind, std::string& name,
				   u32& arity, u32& struct_id,
				   std::string& lat_spec)
  {
    const auto all_digits = [](const std::string& s)
    {
      if (s.empty()) return false;
      for (char c : s) if (c < '0' || c > '9') return false;
      return true;
    };

    std::string rest;
    if (fname.rfind("table.", 0) == 0)       { kind = "table";  rest = fname.substr(6); }
    else if (fname.rfind("struct.", 0) == 0) { kind = "struct"; rest = fname.substr(7); }
    else if (fname.rfind("lat.", 0) == 0)    { kind = "lat";    rest = fname.substr(4); }
    else return false;

    const size_t asplit = rest.rfind(".arity.");
    if (asplit == std::string::npos || asplit == 0) return false;
    name = rest.substr(0, asplit);
    std::string tail = rest.substr(asplit + 7);

    struct_id = 0;
    lat_spec = "";
    std::string aritystr;
    if (kind == "struct")
    {
      const size_t isplit = tail.find(".id.");
      if (isplit == std::string::npos) return false;
      aritystr = tail.substr(0, isplit);
      const std::string idstr = tail.substr(isplit + 4);
      if (!all_digits(idstr)) return false;
      struct_id = (u32)std::atoi(idstr.c_str());
      if (struct_id == 0 || struct_id >= 0x3fff) return false;  // is_struct's 14-bit field
      // a struct stores its id plus >= 1 content column (declarations
      // require a column, modules.rkt); an arity-1 struct dir is corrupt
      // and its empty content prefix would break content-keyed dedup
      if (kind == "struct" && std::atoi(std::string(tail.substr(0, isplit)).c_str()) < 2)
	return false;
    }
    else if (kind == "lat")
    {
      const size_t ssplit = tail.find(".spec.");
      if (ssplit == std::string::npos) return false;
      aritystr = tail.substr(0, ssplit);
      lat_spec = tail.substr(ssplit + 6);
      if (lat_spec.empty()) return false;
    }
    else
      aritystr = tail;

    if (!all_digits(aritystr)) return false;
    arity = (u32)std::atoi(aritystr.c_str());
    if (arity == 0 || arity > max_daemon_arity) return false;
    return true;
  }

  // Does this filename CLAIM to be a relation directory?  A claimed name
  // that then fails parseRelationDirName is a malformed/corrupt/out-of-
  // bounds entry and must fail LOUDLY -- silently skipping it would make
  // a whole relation vanish on open (the pre-P0 loader at least fataled
  // on such dirs when it tried to index them).
  static bool relationDirPrefixed(const std::string& fname)
  {
    return fname.rfind("table.", 0) == 0
	|| fname.rfind("struct.", 0) == 0
	|| fname.rfind("lat.", 0) == 0;
  }

  // Locate `relname`'s directory under db_dir by scanning and parsing
  // directory names.  The WRITE path constructs the name from in-memory
  // metadata (relationDirBIN); the READ path cannot, because struct type
  // ids and lattice spec tokens depend on this daemon's declaration order
  // -- a directory written by another session may carry a different id, so
  // reconstruction silently misses it.  Returns "" when absent; fatals on
  // a shape conflict with the in-memory relation or an ambiguous double
  // match (two dirs claiming one name).
  std::string findRelationDirBIN(const std::string& db_dir,
				 const std::string& relname, Relation* rel)
  {
    if (!std::filesystem::is_directory(db_dir))
      return "";
    std::string found;
    for (const auto& entry : std::filesystem::directory_iterator(db_dir))
    {
      if (!entry.is_directory()) continue;
      std::string fname(entry.path().filename());
      std::string kind, name, lat_spec;
      u32 arity = 0, struct_id = 0;
      if (!parseRelationDirName(fname, kind, name, arity, struct_id, lat_spec))
      {
	if (relationDirPrefixed(fname))
	  fatal("Malformed relation directory name: " + fname
		+ " under " + db_dir);
	continue;
      }
      if (name != relname)
	continue;
      if (!found.empty())
	fatal("Two on-disk directories claim relation " + relname
	      + " under " + db_dir);
      if (arity != rel->getArity())
	fatal("On-disk relation " + relname + " has arity "
	      + std::to_string(arity) + " but is registered at arity "
	      + std::to_string(rel->getArity()));
      if ((kind == "struct") != (rel->getStructId() > 0)
	  || (kind == "lat") != rel->isLattice())
	fatal("On-disk relation " + relname + " kind (" + kind
	      + ") conflicts with its in-memory registration");
      // A struct dir written under a DIFFERENT type id belongs to another
      // session's declaration order: its row words carry that foreign id
      // baked into the 14-bit NaN-box field, so loading them verbatim
      // would reference the wrong (or no) relation.  Refuse loudly until
      // import-time remapping exists (docs/db-merge.md P1).
      if (kind == "struct" && struct_id != rel->getStructId())
	fatal("On-disk struct " + relname + " has type id "
	      + std::to_string(struct_id) + " but is registered with id "
	      + std::to_string(rel->getStructId())
	      + "; cross-session struct refresh requires id remapping "
	      + "(docs/db-merge.md)");
      if (kind == "lat" && lat_spec != rel->latticeSpec())
	fatal("On-disk lattice " + relname + " spec (" + lat_spec
	      + ") conflicts with its registered spec ("
	      + rel->latticeSpec() + ")");
      found = std::string(entry.path()) + "/";
    }
    return found;
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

    // wider relations cannot be reopened (parseRelationDirName bounds
    // arity at max_daemon_arity) -- refuse to write what open must reject
    if (rel->getArity() > max_daemon_arity)
      fatal("Cannot persist relation " + name + " of arity "
	    + std::to_string(rel->getArity())
	    + " (max " + std::to_string(max_daemon_arity) + ")");
    std::string rel_dir = relationDirBIN(db_dir, name, rel);
    // a prior session may have stored this relation under a different
    // struct id or spec token; remove any such stale same-name dir so a
    // relation never has two on-disk homes (open would fatal on the dup)
    if (std::filesystem::is_directory(db_dir))
      for (const auto& entry : std::filesystem::directory_iterator(db_dir))
      {
	if (!entry.is_directory()) continue;
	std::string kind, n2, spec2;
	u32 a2 = 0, sid2 = 0;
	if (parseRelationDirName(entry.path().filename(), kind, n2, a2, sid2, spec2)
	    && n2 == name && std::string(entry.path()) + "/" != rel_dir)
	  std::filesystem::remove_all(entry.path());
      }
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

  // Stage tasks (re)writing the collection-node arena into `s`, mirroring
  // stageStringsWrite: one file per interner partition, each node as 4 raw
  // little-endian u64 words IN ITERATOR ORDER -- an intern id is a pure
  // function of content hash + collision-chain position, and a chain lives
  // wholly inside one partition file, so re-interning each file in order
  // reproduces every id exactly (child words inside node contents are hashed
  // without dereferencing, so the argument extends to trees inductively).
  // Like strings, the arena is append-only, so a full rewrite is always safe.
  void stageNodesWrite(Stratum& s, const std::string& db_dir)
  {
    class WriteNodes : public Task
    {
    public:
      Database* db; u32 i; std::string path;
      WriteNodes(Database* _db, u32 _i, const std::string& _path)
	: db(_db), i(_i), path(_path)
      {}
      virtual void work()
      {
	DBWriteFile file(path);
	auto table = db->cnode_arena->raw();
	for (auto it = table->begin(i); it != table->end(); ++it)
	  file.write((u8*)(*it).w, 32);
      }
    };

    std::filesystem::remove_all(db_dir + "value.nodes/");
    if (cnode_arena->freshCount() == 0)
      return;  // no collections: leave no (empty) arena dir behind
    std::filesystem::create_directory(db_dir + "value.nodes/");
    for (u16 i = 0; i < cnode_arena->raw()->getWritePartitions(); ++i)
      s.addTask(0,
		new WriteNodes(this, i,
			       db_dir + "value.nodes/" + std::to_string(i) + db_out_ext),
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
    stageNodesWrite(s, db_dir);
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
    stageNodesWrite(s, db_dir);
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
      bool gz = hasSuffix(std::string(partfile.path().filename()), ".gz");
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

  // (Re)read every collection-node partition under db_dir, re-interning each
  // 32-byte node record in file order (see stageNodesWrite for why this
  // reproduces ids).  Idempotent for the same reason loadStringsBIN is:
  // interning dedups by content.
  void loadNodesBIN(const std::string& db_dir)
  {
    if (!std::filesystem::is_directory(db_dir + "value.nodes"))
      return;
    for (const auto& partfile : std::filesystem::directory_iterator(db_dir+"value.nodes"))
    {
      std::string path(partfile.path());
      u64 w[4];
      if (hasSuffix(std::string(partfile.path().filename()), ".gz"))
      {
	GzReadFile file(path);
	while (true)
	{
	  const u32 got = file.read((u8*)w, 32);
	  if (got == 0) break;
	  if (got != 32)
	    fatal("Corrupt collection-node file (truncated record): " + path);
	  cnode_arena->intern4(w[0], w[1], w[2], w[3]);
	}
      }
      else
      {
	std::ifstream file(path, std::ios::binary);
	while (file.read(reinterpret_cast<char*>(w), 32))
	  cnode_arena->intern4(w[0], w[1], w[2], w[3]);
	if (file.gcount() != 0)
	  fatal("Corrupt collection-node file (truncated record): " + path);
      }
    }
  }

  // Read one relation directory's .bin/.gz files into the relation's send
  // shards (staged; not yet indexed).
  // Route a data file to the right reader by its FILENAME suffix (a ".gz"
  // substring anywhere in the path -- e.g. in the db name -- must not
  // reroute plain .bin files through the gzip reader).
  static bool hasSuffix(const std::string& s, const std::string& suf)
  {
    return s.size() >= suf.size()
	&& s.compare(s.size() - suf.size(), suf.size(), suf) == 0;
  }

  void readRelationFiles(Relation* rel, const std::string& rel_dir)
  {
    for (const auto& p : std::filesystem::directory_iterator(rel_dir))
    {
      std::string path(p.path());
      std::string fname(p.path().filename());
      if (hasSuffix(fname, ".gz"))
	rel->readGzBIN(path);
      else if (hasSuffix(fname, ".bin"))
	rel->readBIN(path);
    }
  }

public:
  // Open a stored database: register its relations and stage their tuples
  // (the first stratum run ingests them as its iteration-zero delta).
  void loadDatabaseBIN(const std::string& db_dir)
  {
    loadStringsBIN(db_dir);
    loadNodesBIN(db_dir);

    for (const auto& entry : std::filesystem::directory_iterator(db_dir))
    {
      // relation data lives only in directories parsing as relation dirs
      // (parseRelationDirName is filename-anchored and validating, so the
      // interner dirs, stray files, and corrupt names all skip cleanly)
      if (!entry.is_directory())
	continue;
      std::string path(entry.path());
      std::string fname(entry.path().filename());
      std::string kind, name, lat_spec;
      u32 arity = 0, struct_id = 0;
      if (!parseRelationDirName(fname, kind, name, arity, struct_id, lat_spec))
      {
	// a dir CLAIMING to be a relation but failing validation must not
	// silently vanish (a whole relation's facts would disappear)
	if (relationDirPrefixed(fname))
	  fatal("Malformed relation directory name: " + fname
		+ " under " + db_dir);
	continue;
      }

      struct_id_max = std::max(struct_id_max, struct_id+1);

      if (relations.find(name) != relations.end())
	fatal(name + " appears to be a duplicated relation");

      Relation* rel = new Relation(name, arity, struct_id);
      relations[name] = rel;
      rel->initShards(thread_count);
      // lattice metadata before ensureDefaultIndex, which keys on it to
      // build a payload map (so ingestDelta merges rather than inserts)
      if (kind == "lat")
	rel->setLatticeFromSpec(lat_spec, cnode_arena);
      readRelationFiles(rel, path);
      // materialize immediately (into a default index) so the database is
      // queryable/writable before any program arrives; a following stratum
      // re-ingests via the deferred reload (Daemon::open sets it)
      rel->ensureDefaultIndex();
      rel->finalizeBatches();
      rel->ingestDelta();
      disk_mtimes[name] = dirMTime(path + "/");
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
    // find(), not operator[] -- the latter would poison the relations map
    // with a null entry for an unknown name
    auto rit = relations.find(relname);
    Relation* rel = (rit == relations.end()) ? 0 : rit->second;
    if (rel == 0)
      fatal("Cannot load unknown relation " + relname);
    std::string db_dir("data/" + db_name + "/");
    // locate by name-scan, not reconstruction: the on-disk struct id /
    // spec token may differ from this daemon's declaration order
    std::string rel_dir = findRelationDirBIN(db_dir, relname, rel);
    if (rel_dir.empty())
      fatal("No on-disk data for relation " + relname + " under " + db_dir);

    // pick up any strings/collection-nodes the on-disk data references
    // (both idempotent)
    loadStringsBIN(db_dir);
    loadNodesBIN(db_dir);

    rel->clearContents();
    readRelationFiles(rel, rel_dir);
    rel->ensureDefaultIndex();
    rel->finalizeBatches();
    rel->ingestDelta();
    disk_mtimes[relname] = dirMTime(rel_dir);
    DEBUG("Loaded relation " << relname << " from " << db_dir);
  }

  // ---- database merge (docs/db-merge.md P1) --------------------------
  //
  // Merge a stored database into this one: tables union, lattices join per
  // key, struct instances dedup by content, collections re-canonicalize.
  // The A/B-hybrid design: load the source into a throwaway SCRATCH
  // Database (its fresh interners reproduce the source's ids exactly, and
  // its indices give field lookups), then rewrite every source word through
  // one old-word -> dest-word memo built in dependency order, and ingest
  // the rewritten rows id-preservingly.
  //
  // Four database-local id spaces are remapped (docs/db-merge.md §2):
  // strings re-intern by content; struct TYPE ids map by relation name;
  // struct INSTANCES walk children-first through a content-dedup against
  // the dest (one iterative post-order worklist -- deep cons lists/ASTs
  // must not recurse natively); collection nodes REBUILD via the dest
  // arena's kernels, because a Patricia trie's shape is a function of its
  // key words and field-wise remap of interned keys would be structurally
  // wrong.  Ints/floats/null/top self-encode and pass through.
  //
  // Contract: merge-then-run is a monotone over-approximation (§7.2) --
  // derived facts from either side persist even if their grounding is
  // absent in the union.  Schema validation completes before any dest
  // mutation, so a rejected import leaves this database untouched.
  void importDatabaseBIN(const std::string& src_dir)
  {
    if (!std::filesystem::is_directory(src_dir))
      fatal("Import: no database directory at " + src_dir);

    // ---- load the source into a scratch database ----
    Database scratch(1);
    scratch.loadDatabaseBIN(src_dir);

    // ---- schema reconciliation: validate everything, then create ----
    for (const auto& kv : scratch.relations)
    {
      auto dit = relations.find(kv.first);
      if (dit == relations.end())
	continue;
      Relation* src = kv.second;
      Relation* dst = dit->second;
      if (src->getArity() != dst->getArity())
	fatal("Import: relation " + kv.first + " has arity "
	      + std::to_string(src->getArity()) + " in the source but "
	      + std::to_string(dst->getArity()) + " here");
      if ((src->getStructId() > 0) != (dst->getStructId() > 0)
	  || src->isLattice() != dst->isLattice())
	fatal("Import: relation " + kv.first
	      + " kind (table/struct/lattice) conflicts with the source");
      if (src->isLattice() && src->latticeSpec() != dst->latticeSpec())
	fatal("Import: lattice " + kv.first + " spec ("
	      + src->latticeSpec() + ") conflicts with the registered spec ("
	      + dst->latticeSpec() + ")");
    }
    for (const auto& kv : scratch.relations)
    {
      if (relations.find(kv.first) != relations.end())
	continue;
      Relation* src = kv.second;
      if (src->getStructId() > 0)
	addStruct(kv.first, src->getArity());
      else
	addRelation(kv.first, src->getArity());
      Relation* dst = relations[kv.first];
      if (src->isLattice())
	dst->setLatticeFromSpec(src->latticeSpec(), cnode_arena);
      dst->ensureDefaultIndex();
    }

    // ---- source-side lookups: struct sid -> dest relation, and per-
    // instance fields (one forEach pass per struct relation; Index has no
    // point lookup, so a memo beats per-id scans) ----
    std::unordered_map<u32, Relation*> src_sid_to_dst;
    std::unordered_map<u32, std::string> src_sid_name;
    std::unordered_map<u64, std::vector<u64>> src_fields;  // id word -> nominal row
    for (const auto& kv : scratch.relations)
    {
      Relation* src = kv.second;
      if (src->getStructId() == 0)
	continue;
      src_sid_to_dst[src->getStructId()] = relations[kv.first];
      src_sid_name[src->getStructId()] = kv.first;
      forEachNominal(src, [&](const u64* row)
      {
	src_fields.emplace(row[0], std::vector<u64>(row, row + src->getArity()));
      });
    }

    // ---- dest-side content-dedup maps per struct relation: the same
    // content-columns key InternStructTask's master scan dedups by, so
    // import-time dedup and future rule interns agree ----
    std::unordered_map<Relation*,
      std::unordered_map<std::vector<u64>, u64,
			 boost::hash<std::vector<u64>>>> dst_content;
    for (const auto& kv : scratch.relations)
    {
      Relation* dst = relations[kv.first];
      if (dst->getStructId() == 0 || dst_content.count(dst))
	continue;
      auto& cm = dst_content[dst];
      forEachNominal(dst, [&](const u64* row)
      {
	cm.emplace(std::vector<u64>(row + 1, row + dst->getArity()), row[0]);
      });
    }

    // Intern one struct instance into the dest by content (dedup against
    // the map above; fresh ids route by buckethash(first content column) --
    // InternStructTask's routing -- and draw from that bucket's allocator).
    const auto internStructTuple =
      [&](Relation* dst, const std::vector<u64>& fields) -> u64
    {
      auto& cm = dst_content[dst];
      auto hit = cm.find(fields);
      if (hit != cm.end())
	return hit->second;
      const u16 bucket = buckethash(fields[0]);
      u64* alloc = dst->getInternAlloc(bucket);
      const u64 idw = struct_encode(dst->getStructId(),
				    (*alloc << bucket_bits) | bucket);
      ++(*alloc);
      u64 row[max_daemon_arity + 1];
      row[0] = idw;
      for (size_t c = 0; c < fields.size(); ++c)
	row[c + 1] = fields[c];
      dst->insertTupleAllIndices(row);
      cm.emplace(fields, idw);
      return idw;
    };

    // ---- the word remap: one iterative children-first worklist over the
    // struct-instance/collection-node DAG, memoized in `remap` ----
    std::unordered_map<u64, u64> remap;
    std::unordered_set<u64> open;  // cycle guard (corrupt input)
    const auto self_encoding = [](u64 w)
    {
      return is_s32(w) || is_float(w) || w == slog_null || w == slog_lat_top;
    };
    const auto importWord = [&](u64 w0) -> u64
    {
      if (self_encoding(w0))
	return w0;
      std::vector<u64> stack{w0};
      while (!stack.empty())
      {
	const u64 w = stack.back();
	if (self_encoding(w) || remap.count(w))
	{
	  stack.pop_back();
	  open.erase(w);
	  continue;
	}
	if (is_str(w))
	{
	  utf8string* s = scratch.lookup_string(decode_val(w));
	  if (s == nullptr)
	    fatal("Import: dangling string id in " + src_dir);
	  remap[w] = intern_encode(str_intern_tag,
				   intern_string(new utf8string(s->c_str(),
								s->byte_size())));
	  stack.pop_back();
	  continue;
	}
	if (is_struct(w))
	{
	  const auto fit = src_fields.find(w);
	  if (fit == src_fields.end())
	    fatal("Import: dangling struct instance id in " + src_dir);
	  const std::vector<u64>& row = fit->second;
	  bool ready = true;
	  for (size_t c = 1; c < row.size(); ++c)
	    if (!self_encoding(row[c]) && !remap.count(row[c]))
	    {
	      if (open.count(row[c]))
		fatal("Import: cyclic struct/collection reference in " + src_dir);
	      stack.push_back(row[c]);
	      ready = false;
	    }
	  if (!ready)
	  {
	    open.insert(w);
	    continue;
	  }
	  const auto dit = src_sid_to_dst.find(decode_struct_id(w));
	  if (dit == src_sid_to_dst.end())
	    fatal("Import: struct word carries a type id no source relation "
		  "declares (corrupt database?) in " + src_dir);
	  Relation* dst = dit->second;
	  std::vector<u64> fields(row.size() - 1);
	  for (size_t c = 1; c < row.size(); ++c)
	    fields[c - 1] = self_encoding(row[c]) ? row[c] : remap[row[c]];
	  remap[w] = internStructTuple(dst, fields);
	  stack.pop_back();
	  open.erase(w);
	  continue;
	}
	if (is_cnode(w))
	{
	  std::vector<std::pair<u64, u64>> entries;
	  scratch.collections()->foreach(w, [&](u64 k, u64 v)
	  {
	    entries.push_back({k, v});
	  });
	  bool ready = true;
	  for (const auto& e : entries)
	    for (const u64 dep : {e.first, e.second})
	      if (!self_encoding(dep) && !remap.count(dep))
	      {
		if (open.count(dep))
		  fatal("Import: cyclic struct/collection reference in " + src_dir);
		stack.push_back(dep);
		ready = false;
	      }
	  if (!ready)
	  {
	    open.insert(w);
	    continue;
	  }
	  // REBUILD (never field-wise remap): remapped keys change the
	  // trie's canonical shape, so fold the remapped entries into the
	  // dest arena from empty -- content-dedup then unifies equal
	  // collections across the two databases for free
	  u64 t = cnode_arena->empty();
	  for (const auto& e : entries)
	  {
	    const u64 k = self_encoding(e.first) ? e.first : remap[e.first];
	    const u64 v = self_encoding(e.second) ? e.second : remap[e.second];
	    t = cnode_arena->put(t, k, v);
	  }
	  remap[w] = t;
	  stack.pop_back();
	  open.erase(w);
	  continue;
	}
	fatal("Import: unsupported interned value class (word tag) in " + src_dir);
      }
      return remap[w0];
    };

    // ---- drive: intern every source struct instance (children first) ----
    for (const auto& kv : scratch.relations)
      if (kv.second->getStructId() > 0)
	forEachNominal(kv.second, [&](const u64* row)
	{
	  importWord(row[0]);
	});

    // ---- rewrite + ingest table and lattice rows (struct relations were
    // fully materialized above); lattice payload maps merge per key via
    // insertTuple, including LAT_EXTERN collection joins ----
    for (const auto& kv : scratch.relations)
    {
      Relation* src = kv.second;
      if (src->getStructId() > 0)
	continue;
      Relation* dst = relations[kv.first];
      const u16 A = src->getArity();
      u64 row[max_daemon_arity + 1];
      forEachNominal(src, [&](const u64* srow)
      {
	for (u16 c = 0; c < A; ++c)
	  row[c] = importWord(srow[c]);
	dst->insertTupleAllIndices(row);
      });
    }

    DEBUG("Imported database " << src_dir);
  }

  // Iterate one relation's tuples in NOMINAL (storage) column order,
  // whatever ordering its indices use.
  static void forEachNominal(Relation* rel,
			     const std::function<void(const u64*)>& f)
  {
    const std::vector<u16>* ordp = rel->getAnyIndex();
    if (ordp == nullptr)
      return;
    const std::vector<u16>& ord = *ordp;
    std::vector<u16> rewrite_ord(ord.size(), 0);
    for (u16 i = 0; i < ord.size(); ++i)
      rewrite_ord[ord[i]] = i;
    Index** buckets = rel->getIndex(ord, false);
    u64 row[max_daemon_arity + 1];
    for (u16 b = 0; b < bucket_count; ++b)
      buckets[b]->forEach([&](const u64* t)
      {
	for (u16 c = 0; c < ord.size(); ++c)
	  row[c] = t[rewrite_ord[c]];
	f(row);
      });
  }

  // Has the relation's on-disk data changed since this instance last read
  // or wrote it?  (True for never-synced relations that exist on disk.)
  bool relationChangedOnDisk(const std::string& db_name, const std::string& relname)
  {
    // find(), not operator[]: this path returns and keeps running, so a
    // null entry inserted for an unknown name would poison later iteration
    // over the relations map
    auto rit = relations.find(relname);
    Relation* rel = (rit == relations.end()) ? 0 : rit->second;
    if (rel == 0)
      return false;
    std::string rel_dir = findRelationDirBIN("data/" + db_name + "/", relname, rel);
    auto it = disk_mtimes.find(relname);
    if (it == disk_mtimes.end())
      return !rel_dir.empty();
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




