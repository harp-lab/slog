/** Slog Sequence-Arena Format Constants
 *
 * The chunking parameters of the canonical sequence representation
 * (docs/sequences.md §1.2/§8.2).  These are FORMAT: chunk boundaries are a
 * pure function of content and of these compiled-in constants, and every
 * canonical sequence id on disk depends on them.  Changing ANY value here
 * changes every sequence id in every saved database -- bump
 * SEQ_FORMAT_VERSION and rely on rebuild-on-load / replay-from-origin
 * (docs/db-compression.md) if that ever has to happen.
 *
 * FROZEN at the D3 values (benched 2026-07-08, 1M random u64 elements,
 * -O2): word leaves target 16 elements (4-bit boundary mask) in [4,64];
 * branches target fanout 16 in [4,64]; byte leaves (S2 rope strings)
 * target 64 bytes (6-bit mask) in [16,256].  At these constants: build
 * 21.5M elems/s, 0.057 nodes/elem (mean leaf fill 18.6), point edit
 * 18us / ~6 fresh nodes, cat of 1M+1M = 25us / 6 fresh nodes, slice 1M
 * of 2M = 24us / 10 fresh nodes.  The 5-bit-mask alternative (target 32)
 * builds ~20% faster with ~40% fewer nodes but HALVES the sharing/dedup
 * granularity (bigger chunks share and deduplicate more coarsely, on
 * disk and in memory) -- 16 keeps the finer granularity the IO-dedup
 * story wants at negligible runtime cost.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once

#include "types.h"


// Version byte written into value.seq/ (first record of partition 0); a
// loader seeing a different value must fatal loudly (docs/sequences.md §8.2).
#define SEQ_FORMAT_VERSION ((u8)1)

// Word leaves (element sequences): boundary after element i when
// (h & SEQ_WLEAF_MASK) == 0, h the rolling gear hash, subject to run-length
// bounds [SEQ_WLEAF_MIN, SEQ_WLEAF_MAX].
#define SEQ_WLEAF_MASK ((u64)0xf)
#define SEQ_WLEAF_MIN  ((u32)4)
#define SEQ_WLEAF_MAX  ((u32)64)

// Branch nodes (all levels above the leaves, both word and byte trees):
// the same predicate over the child-id word stream.
#define SEQ_BRANCH_MASK ((u64)0xf)
#define SEQ_BRANCH_MIN  ((u32)4)
#define SEQ_BRANCH_MAX  ((u32)64)

// Byte leaves (rope strings, docs/sequences.md §6).  Boundaries snap
// forward to the next UTF-8 codepoint start after the mask fires (still a
// pure function of content; at most 3 bytes of slack, so leaves reach
// SEQ_BLEAF_MAX + 3).  SEQ_BLEAF_MAX doubles as the string-representation
// threshold: content <= this many bytes stays a monolithic tag-0 intern
// (Database::encodeString, the normalization keystone).
#define SEQ_BLEAF_MASK ((u64)0x3f)
#define SEQ_BLEAF_MIN  ((u32)16)
#define SEQ_BLEAF_MAX  ((u32)256)

// The rolling-hash window: h = (h << 1) + gear(w) over u64 accumulators, so
// a word's influence is shifted out after 64 steps.  This is NOT tunable --
// it is the accumulator width -- but it is named because the edit-rechunk
// and resynchronization logic (daemon/seq.h) depends on it.
#define SEQ_HASH_WINDOW ((u32)64)


namespace slog
{

// gear(w): the per-word mixing function feeding the rolling hash.  A fixed,
// compiled-in splitmix64 (no per-run seed -- the hash is part of the
// canonical form; docs/sequences.md §1.2).
inline u64 seq_gear(u64 x)
{
  x += 0x9e3779b97f4a7c15ull;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ull;
  x = (x ^ (x >> 27)) * 0x94d049bb133111ebull;
  return x ^ (x >> 31);
}

} // namespace slog
