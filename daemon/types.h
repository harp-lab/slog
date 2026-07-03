
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

// Primitive type tags are 3 bits and non-zero
#define s32_prim_tag 1
#define enum_prim_tag 2

// Intern-value type tags are 3 bits 
#define str_intern_tag 0
#define mpz_intern_tag 1

// The top bit determines if its a struct or not when the value is a NaN
#define NaNflags     0x7ff0000000000000
#define internflags  0x7fffffc000000000 
#define structflags  0xfff0000000000000
#define typetopmask  0xffffffc000000000
#define slog_null    0x7ff0003fffffffff


// We use a NaN-based IEEE-754 Binary64 encoding of non-float values
// Interned Values:  0 11111111111 111..14b..1111 XXX YYYY....[35bit intern-id]....YYYYYY
// Primitive Values: 0 11111111111 000..14b..0000 XXX YYYY....[35bit prim-value]...YYYYYY
#define intern_encode(t,id) (((u64)(t) << 35) | ((u64)(id)) | internflags)
#define prim_encode(t,v) (((u64)(t) << 35) | ((u64)(v)) | NaNflags)
#define decode_type(x) (((u64)(x) >> 35) & 7)
#define decode_val(x) ((u64)(x) & 0x00000007ffffffff)
#define is_prim(x) (((x) & typetopmask) == NaNflags && (7 & ((x) >> 35)) > 0)
#define is_intern(x) (((x) & typetopmask) == internflags)

// str
#define is_str(x) (is_intern(x) && decode_type(x) == str_intern_tag)
#define str_decode(db,x) ((db)->lookup_string(decode_val(x)))
#define str_encode(db,x) (intern_encode(str_intern_tag,(db)->intern_string(new slog::utf8string(x))))

// s32 
#define is_s32(x) (is_prim(x) && decode_type(x) == s32_prim_tag)
#define s32_encode(v) (prim_encode(s32_prim_tag, (v) & 0xffffffff))
#define s32_decode(v) ((s32)(u32)(decode_val(v) & 0xffffffff))

// float
#define is_float(x) ((((x) & NaNflags) != NaNflags) || (0 == ((x) & 0x000fffffffffffff)))
#define float_encode(x) (std::bit_cast<u64>(x))
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

#define slog_lat_top 0x7ff0003ffffffffe

#define LAT_NONE  0
#define LAT_MIN   1
#define LAT_MAX   2
#define LAT_COUNT 3
#define LAT_FLAT  4

// Numeric min/max on tagged words (homogeneous: the type system guarantees a
// lattice column is all-s32 or all-float).
inline u64 lat_num_min(u64 a, u64 b)
{
  if (is_s32(a) && is_s32(b)) return (s32_decode(a) <= s32_decode(b)) ? a : b;
  return (float_decode(a) <= float_decode(b)) ? a : b;
}
inline u64 lat_num_max(u64 a, u64 b)
{
  if (is_s32(a) && is_s32(b)) return (s32_decode(a) >= s32_decode(b)) ? a : b;
  return (float_decode(a) >= float_decode(b)) ? a : b;
}

// The join: least upper bound of two present values (absence = bottom is
// handled by the caller -- a missing key simply takes the contribution).
inline u64 lat_join(u32 kind, u64 a, u64 b)
{
  switch (kind)
  {
  case LAT_MIN:   return lat_num_min(a, b);
  case LAT_MAX:   return lat_num_max(a, b);
  case LAT_COUNT: return lat_num_max(a, b);
  case LAT_FLAT:  default: return (a == b) ? a : slog_lat_top;
  }
}

// Clamp a contribution into the declared floor/ceiling (Trop+: the published
// convergence condition surfaced as syntax -- docs/lattices.md §6).  Applied
// before the join; clamp(join(a,b)) == join(clamp(a),clamp(b)) for min/max.
inline u64 lat_clamp(u32 kind, bool has_floor, u64 floorw,
                     bool has_ceil, u64 ceilw, u64 v)
{
  if (kind == LAT_MIN && has_floor) return lat_num_max(v, floorw);
  if (kind == LAT_MAX && has_ceil)  return lat_num_min(v, ceilw);
  return v;
}




