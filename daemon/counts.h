/** Slog packed derivation counters (DRed^c sidecar values)
 *
 * The per-tuple counter word stored in a relation's count sidecar
 * (docs/incremental.md §6.1/§8B): input(1) | nonrec(31) | rec(32).
 *
 *   - `input` is the EDB set-semantics bit (§8B.5): the tuple was asserted
 *     as an input to this version (batch, import, link, ground fact, freeze
 *     root).  Inputs are sets, not counts -- re-adding is a no-op, so the
 *     bit never participates in arithmetic.
 *   - `nonrec`/`rec` count one-step derivations by rules tagged
 *     non-recursive/recursive for the head's stratum (§3.1).  Stored
 *     counters are never negative -- signs travel on delta records -- so an
 *     underflow is corruption, and saturation is a loud fatal rather than a
 *     silent wrap (widen the fields if a workload ever trips it).
 *
 * presence(t) := input | nonrec + rec > 0  (§8B.5).
 *
 * Counts are session-ephemeral cache: never persisted, recomputable at any
 * settled fixpoint by the count round (§8B).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

#include "types.h"
#include "fatal.h"

#include <string>

namespace slog
{

constexpr u64 cnt_input_bit = 1ull << 63;
constexpr u32 cnt_nonrec_shift = 32;
constexpr u64 cnt_rec_mask = 0x00000000ffffffffull;          // low 32
constexpr u64 cnt_nonrec_max = 0x7fffffffull;                // 31 bits
constexpr u64 cnt_rec_max = 0xffffffffull;                   // 32 bits

inline bool cnt_input(u64 w) { return (w & cnt_input_bit) != 0; }
inline u64 cnt_nonrec(u64 w) { return (w >> cnt_nonrec_shift) & cnt_nonrec_max; }
inline u64 cnt_rec(u64 w) { return w & cnt_rec_mask; }

inline u64 cnt_pack(bool input, u64 nonrec, u64 rec)
{
  if (nonrec > cnt_nonrec_max || rec > cnt_rec_max)
    fatal("count overflow in cnt_pack (nonrec " + std::to_string(nonrec)
          + ", rec " + std::to_string(rec) + ")");
  return (input ? cnt_input_bit : 0) | (nonrec << cnt_nonrec_shift) | rec;
}

inline u64 cnt_set_input(u64 w) { return w | cnt_input_bit; }
inline u64 cnt_clear_input(u64 w) { return w & ~cnt_input_bit; }

// Apply one signed contribution pair.  Underflow (a decrement below zero)
// means a +/- imbalance across the counted flavors -- corruption, not a
// recoverable state -- and overflow means a field saturated; both are loud
// fatals (§6.1).
inline u64 cnt_add(u64 w, s64 dnonrec, s64 drec)
{
  s64 nr = (s64)cnt_nonrec(w) + dnonrec;
  s64 rc = (s64)cnt_rec(w) + drec;
  if (nr < 0 || rc < 0)
    fatal("count underflow in cnt_add (nonrec " + std::to_string(nr)
          + ", rec " + std::to_string(rc) + "): +/- flavor imbalance");
  if ((u64)nr > cnt_nonrec_max || (u64)rc > cnt_rec_max)
    fatal("count overflow in cnt_add (nonrec " + std::to_string(nr)
          + ", rec " + std::to_string(rc) + ")");
  return (w & cnt_input_bit) | ((u64)nr << cnt_nonrec_shift) | (u64)rc;
}

inline bool cnt_present(u64 w)
{
  return cnt_input(w) || cnt_nonrec(w) + cnt_rec(w) > 0;
}

// Per-batch contribution kind (docs/incremental.md §8B.1): rows produced by
// the counted flavors travel through the ordinary send-shard/delta transport,
// tagged on their InsertBatch with the emitting rule's static classification
// (§6.4: recursive iff some body relation is in the rule's own stratum;
// body-less ground rules are inputs, §8B.5).  Batches are per-(task, head)
// so a batch is always kind-homogeneous; `none` marks ordinary set-semantics
// batches, which must never reach a counting task.
constexpr u8 cnt_kind_none = 0;
constexpr u8 cnt_kind_input = 1;
constexpr u8 cnt_kind_nonrec = 2;
constexpr u8 cnt_kind_rec = 3;

// Fold one contribution of `kind` into a stored counter word: inputs SET the
// bit (set semantics -- idempotent, never arithmetic, §8B.5); derivations
// bump their counter.
inline u64 cnt_apply(u64 w, u8 kind)
{
  switch (kind)
  {
    case cnt_kind_input: return cnt_set_input(w);
    case cnt_kind_nonrec: return cnt_add(w, 1, 0);
    case cnt_kind_rec: return cnt_add(w, 0, 1);
  }
  fatal("cnt_apply on a kind-less batch: a set-semantics row reached a "
        "counting task (flavor mix-up)");
  return w;
}

}
