
/** Slog Types
 * 
 * Some type related declarations.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2025
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once

#include <cstdint>
#include <bit>
#include <string>

namespace slog { void fatal(const std::string& msg); }  // defined in fatal.h


// C++ types
 
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef int64_t s64;
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;


// Slog types

// Primitive type tags are 3 bits and non-zero.  Only tag 1 (s32) is in use;
// tags 2-7 are free for future prim types (35-bit payloads each).  The s32
// payload uses 32 of the 35 bits; tag-1 payloads >= 2^32 are RESERVED
// INTERNAL SPACE (excluded from is_s32 by the high-bit mask) -- the three
// sentinel words below live at the very top of that region.
#define s32_prim_tag 1

// Intern-value type tags are 3 bits
#define str_intern_tag 0
#define mpz_intern_tag 1
#define cnode_intern_tag 2
// Sequence nodes (docs/sequences.md §1.3): tag 3 = a canonical chunked-Merkle
// sequence node (root or interior) in the sequence arena (daemon/seq.h).
// Tag 4 is RESERVED for S2 rope-string roots (a rope's INTERIOR nodes are
// ordinary tag-3 words; only a string value's root is tagged 4, keeping
// is_str a pure bit test over tags {0,4}).
#define seq_intern_tag 3
#define strrope_intern_tag 4

// The top bit determines if its a struct or not when the value is a NaN
#define NaNflags     0x7ff0000000000000
#define internflags  0x7fffffc000000000
#define structflags  0xfff0000000000000
#define typetopmask  0xffffffc000000000
// The three sentinels are tag-1 (s32) prim words with payload >= 2^32 --
// inside the reserved internal region the is_s32 mask excludes, at its top.
// (Encoding version 2; they lived at the top of prim tag 7 in version 1.)
#define slog_null    0x7ff0000fffffffff
// Reserved sentinel a fallible prim returns instead of aborting the daemon: the
// generated code checks for it right after the call and, if seen, records an
// (error (error_spec ...)) fact and abandons the deduction (docs/type-errors.md).
// Distinct from slog_null ("drop this delta record") and slog_lat_top.
#define slog_error   0x7ff0000ffffffffd


// We use a NaN-based IEEE-754 Binary64 encoding of non-float values
// Interned Values:  0 11111111111 111..14b..1111 XXX YYYY....[35bit intern-id]....YYYYYY
// Primitive Values: 0 11111111111 000..14b..0000 XXX YYYY....[35bit prim-value]...YYYYYY
#define intern_encode(t,id) (((u64)(t) << 35) | ((u64)(id)) | internflags)
#define prim_encode(t,v) (((u64)(t) << 35) | ((u64)(v)) | NaNflags)
#define decode_type(x) (((u64)(x) >> 35) & 7)
#define decode_val(x) ((u64)(x) & 0x00000007ffffffff)
#define is_prim(x) (((x) & typetopmask) == NaNflags && (7 & ((x) >> 35)) > 0)
#define is_intern(x) (((x) & typetopmask) == internflags)

// str -- TWO representations, one type (docs/sequences.md §6): strings of
// <= SEQ_BLEAF_MAX bytes are monolithic tag-0 interns (the utf8string
// table); longer strings are tag-4 ROPES (roots of byte trees in the
// sequence arena; interior nodes are ordinary tag-3 words).  The split is
// a pure function of content length, so canonicity holds across it --
// PROVIDED every producer normalizes (Database::encodeString) and every
// consumer dispatches (Database::decodeString / the rope-aware kernels).
// is_str stays a pure bit test over tags {0, 4}.
#define is_mono_str(x) (is_intern(x) && decode_type(x) == str_intern_tag)
#define is_rope(x) (is_intern(x) && decode_type(x) == strrope_intern_tag)
#define is_str(x) (is_mono_str(x) || is_rope(x))
// MONOLITHIC strings only -- rope words would alias an unrelated table
// slot; sites that can see arbitrary strings use Database::decodeString.
#define str_decode(db,x) ((db)->lookup_string(decode_val(x)))
// Short internal constants only (op names, "file:line" locations) -- can
// never exceed the threshold; arbitrary content uses Database::encodeString.
#define str_encode(db,x) (intern_encode(str_intern_tag,(db)->intern_string(new slog::utf8string(x))))

// cnode -- a collection value: the intern word of a canonical Patricia-trie
// node in the collection arena (daemon/arena.h).  Equal collections are one
// word, so raw-word equality/joins/dedup are value semantics for these.
#define is_cnode(x) (is_intern(x) && decode_type(x) == cnode_intern_tag)

// seq -- a sequence value: the intern word of a canonical content-defined-
// chunked Merkle-tree node in the sequence arena (daemon/seq.h).  Chunking is
// a pure function of content, so equal sequences are one word: raw-word
// equality/joins/dedup are value semantics for these too (docs/sequences.md).
#define is_seq(x) (is_intern(x) && decode_type(x) == seq_intern_tag)

// s32 -- the payload high-bit mask excludes the reserved internal region
// (tag-1 payloads >= 2^32: the sentinels and future internal words)
#define is_s32(x) (is_prim(x) && decode_type(x) == s32_prim_tag \
                   && (((x) & 0x0000000700000000) == 0))

// mpz -- an exact integer OUTSIDE the s32 range: the intern word of a
// canonical GMP bignum (daemon/mpz.h).  The int TYPE spans both
// representations (docs/primitives.md §14): a value in [-2^31, 2^31) is
// ALWAYS the s32 prim word, anything else ALWAYS an interned mpz --
// PROVIDED every producer normalizes through Database::encodeInt/encodeMpz.
#define is_mpz(x) (is_intern(x) && decode_type(x) == mpz_intern_tag)
#define is_int(x) (is_s32(x) || is_mpz(x))
#define s32_encode(v) (prim_encode(s32_prim_tag, (v) & 0xffffffff))
#define s32_decode(v) ((s32)(u32)(decode_val(v) & 0xffffffff))

// float
#define is_float(x) ((((x) & NaNflags) != NaNflags) || (0 == ((x) & 0x000fffffffffffff)))
// The NaN-box reuses the IEEE NaN space for tagged (interned/struct/prim)
// values, so a genuine NaN result is unrepresentable: it fails is_float and a
// negative NaN even reads as a struct id, aborting CSV export.  Reject it at the
// point of production (sqrt(neg), 0.0/0.0, fmod(x,0), ...) with a clean
// diagnostic rather than storing a corrupt word.  (+-inf is fine: mantissa 0.)
inline u64 float_encode(double x)
{
  // NaN is unrepresentable in the NaN-box; return the reserved sentinel so the
  // calling prim dispatcher records an ERR_NAN (error_spec ...) and abandons the
  // deduction (prims.h) rather than storing a corrupt word.  (+-inf is fine.)
  if (x != x) return slog_error;
  return std::bit_cast<u64>(x);
}
#define float_decode(x) (std::bit_cast<double>(x))


// Struct IDs: 1 11111111111 [14bit struct-id]  [38bit interned struct id (with buckets at bot)]
#define is_struct(x) ((((x) & 0xfff0000000000000) == 0xfff0000000000000) \
		      && 0 < (0x3fff & ((x) >> 38)) && (0x3fff & ((x) >> 38)) < 0x3fff)
#define struct_encode(sid,id) ((u64)(id) | ((u64)(sid) << 38) | structflags)
#define decode_struct_id(x) (((u64)x >> 38) & 0x3fff)
#define decode_struct_perbucketid(x, bucketbits) (((x) & 0x3fffffffff) >> bucketbits)


// Lattice payloads (docs/lattices.md §4).  A lattice (map) relation's value
// column carries one u64 word merged by the lattice's join:
//   min/max int|float -- the ordinary tagged word, joined by numeric min/max;
//   count             -- the {0,1,inf} chain as tagged s32 words 1 and 2
//                        (0 = absence, never stored), joined by max;
//   flat T            -- the underlying value word, plus the reserved top
//                        pattern below (join of two distinct values).
// slog_lat_top is a distinct reserved word, NOT slog_null: null means "drop
// this delta record" to reorg/intern, top is a real stored value.

#define slog_lat_top 0x7ff0000ffffffffe

#define LAT_NONE   0
#define LAT_MIN    1
#define LAT_MAX    2
#define LAT_COUNT  3
#define LAT_FLAT   4
// Composed collection join (set / map valuespecs): dispatched through the
// relation's parsed LatSpec tree + CollectionArena (daemon/arena.h), never
// through the scalar lat_join below.
#define LAT_EXTERN 5

// The scalar lattice joins (lat_num_min/max, lat_join, lat_clamp) live in
// mpz.h: their int arms compare bignums exactly through the mpz intern table,
// which is not a complete type here.




