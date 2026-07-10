/** Slog Bigints
 *
 * An immutable GMP bignum value for the mpz intern table (docs/primitives.md
 * §14).  An interned mpz_val NEVER lies in the s32 range [-2^31, 2^31) -- the
 * normalization keystone Database::encodeInt/encodeMpz enforces -- so a word
 * under mpz_intern_tag and an s32 prim word never denote the same integer and
 * raw-word equality remains value equality for the whole int type.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once


#include "types.h"
#include "intern.h"
#include <gmp.h>
#include <string>


namespace slog
{


class mpz_val
{
private:
  mpz_t z;

public:
  mpz_val(const mpz_val&) = delete;
  mpz_val& operator=(const mpz_val&) = delete;

  explicit mpz_val(mpz_srcptr src)
  {
    mpz_init_set(z, src);
  }

  explicit mpz_val(s64 v)
  {
    mpz_init_set_si(z, (long)v);
  }

  // Deserialize: nbytes LSB-first magnitude bytes + a sign (the canonical
  // serialization write_bytes produces; also the on-disk record body).
  mpz_val(const u8* bytes, u32 nbytes, bool neg)
  {
    mpz_init(z);
    mpz_import(z, nbytes, -1, 1, 0, 0, bytes);
    if (neg) mpz_neg(z, z);
  }

  ~mpz_val()
  {
    mpz_clear(z);
  }

  mpz_srcptr get() const
  {
    return z;
  }

  bool operator==(const mpz_val& o) const
  {
    return mpz_cmp(z, o.z) == 0;
  }

  bool negative() const
  {
    return mpz_sgn(z) < 0;
  }

  // Magnitude byte count (>= 1; an interned value is never zero).
  u32 byte_size() const
  {
    return (u32)((mpz_sizeinbase(z, 2) + 7) / 8);
  }

  // The i'th LSB-first magnitude byte, without materializing the buffer
  // (fasthash walks limbs directly).
  u8 byte_at(u32 i) const
  {
    const u32 per = (u32)sizeof(mp_limb_t);
    return (u8)(mpz_getlimbn(z, i / per) >> (8 * (i % per)));
  }

  // Canonical serialization: out[0] = sign (1 = negative), then byte_size()
  // LSB-first magnitude bytes.  Used verbatim as the value.mpz record body.
  void write_bytes(u8* out) const
  {
    out[0] = negative() ? 1 : 0;
    size_t count = 0;
    mpz_export(out + 1, &count, -1, 1, 0, 0, z);
    for (size_t i = count; i < byte_size(); ++i)
      out[1 + i] = 0;
  }

  // Approximate heap footprint for the whole-table byte cap: magnitude bytes
  // plus per-entry overhead (mpz_t header, table vector slot, allocator slop).
  u64 approx_bytes() const
  {
    return (u64)byte_size() + 48;
  }

  std::string dec_str() const
  {
    char* s = mpz_get_str(nullptr, 10, z);
    std::string r(s);
    void (*freefn)(void*, size_t);
    mp_get_memory_functions(nullptr, nullptr, &freefn);
    freefn(s, r.size() + 1);
    return r;
  }
};


// FNV-1a over the canonical serialization (sign byte + LSB-first magnitude
// bytes), matching write_bytes without materializing it.
template <>
inline u32 fasthash<slog::mpz_val>(const slog::mpz_val& v)
{
  u32 hash = 2166136261u;
  hash ^= (v.negative() ? 1 : 0);
  hash *= 16777619u;
  const u32 n = v.byte_size();
  for (u32 i = 0; i < n; ++i)
  {
    hash ^= v.byte_at(i);
    hash *= 16777619u;
  }
  return hash;
}


}  // namespace slog


// Exact tri-compare over int words in either representation, given the mpz
// table (the Database-free core Database::cmpInt wraps; the lattice joins
// below call it from contexts where Database is still an incomplete type).
// One-mpz case: the mpz's SIGN decides -- by the normalization invariant its
// magnitude exceeds every s32.
inline int cmp_int_words(slog::InternTable<slog::mpz_val>* mt, u64 x, u64 y)
{
  if (is_s32(x) && is_s32(y))
  {
    const s64 a = s32_decode(x), b = s32_decode(y);
    return a < b ? -1 : (a > b ? 1 : 0);
  }
  if (x == y) return 0;   // interned: word equality is value equality
  if (mt == nullptr)
    slog::fatal("Bignum word reached an int compare with no mpz table");
  if (is_s32(y)) return mt->lookup_value(decode_val(x))->negative() ? -1 : 1;
  if (is_s32(x)) return mt->lookup_value(decode_val(y))->negative() ? 1 : -1;
  return mpz_cmp(mt->lookup_value(decode_val(x))->get(),
                 mt->lookup_value(decode_val(y))->get());
}


// Scalar lattice joins (moved from types.h so the int arms can compare
// bignums exactly through the mpz table).  Numeric min/max on tagged words
// (homogeneous: the type system guarantees a lattice column is all-int or
// all-float -- but `any`-typed prim outputs can evade it, so a non-numeric
// word here fails loudly instead of silently float-decoding an interned id
// into garbage).
inline u64 lat_num_min(u64 a, u64 b, slog::InternTable<slog::mpz_val>* mt)
{
  if (is_int(a) && is_int(b)) return (cmp_int_words(mt, a, b) <= 0) ? a : b;
  if (is_float(a) && is_float(b))
  {
    // decoded ties (+0.0 vs -0.0) canonicalize by raw word, so the stored
    // value never depends on contribution order (the join must stay
    // commutative at the WORD level: canonical collections intern payload
    // words into content-addressed identity)
    const double da = float_decode(a), db = float_decode(b);
    if (da == db) return (a <= b) ? a : b;
    return (da < db) ? a : b;
  }
  slog::fatal("Non-numeric or mixed-type value in a min/max lattice column");
  return 0;
}
inline u64 lat_num_max(u64 a, u64 b, slog::InternTable<slog::mpz_val>* mt)
{
  if (is_int(a) && is_int(b)) return (cmp_int_words(mt, a, b) >= 0) ? a : b;
  if (is_float(a) && is_float(b))
  {
    const double da = float_decode(a), db = float_decode(b);
    if (da == db) return (a <= b) ? a : b;
    return (da > db) ? a : b;
  }
  slog::fatal("Non-numeric or mixed-type value in a min/max lattice column");
  return 0;
}

// The join: least upper bound of two present values (absence = bottom is
// handled by the caller -- a missing key simply takes the contribution).
// A kind this switch doesn't know must FAIL, not silently take the flat
// arm: flat equality-merge on collection payloads would escalate any two
// distinct sets to top instead of unioning them.
inline u64 lat_join(u32 kind, u64 a, u64 b, slog::InternTable<slog::mpz_val>* mt)
{
  switch (kind)
  {
  case LAT_MIN:   return lat_num_min(a, b, mt);
  case LAT_MAX:   return lat_num_max(a, b, mt);
  case LAT_COUNT: return lat_num_max(a, b, mt);
  case LAT_FLAT:  return (a == b) ? a : slog_lat_top;
  default:
    slog::fatal("lat_join: unknown or extern lattice kind reached the scalar join");
    return 0;
  }
}

// Clamp a contribution into the declared floor/ceiling (Trop+: the published
// convergence condition surfaced as syntax -- docs/lattices.md §6).  Applied
// before the join; clamp(join(a,b)) == join(clamp(a),clamp(b)) for min/max.
inline u64 lat_clamp(u32 kind, bool has_floor, u64 floorw,
                     bool has_ceil, u64 ceilw, u64 v,
                     slog::InternTable<slog::mpz_val>* mt)
{
  if (kind == LAT_MIN && has_floor) return lat_num_max(v, floorw, mt);
  if (kind == LAT_MAX && has_ceil)  return lat_num_min(v, ceilw, mt);
  return v;
}
