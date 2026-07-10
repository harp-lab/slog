
/** Slog Integer Prims
 *
 * Exact-integer kernels over BOTH int representations (docs/primitives.md
 * §14): the dispatchers in prims.h guarantee is_int() arguments (s32 prim or
 * interned mpz).  Both-s32 fast paths compute in s64 and re-canonicalize
 * through Database::encodeInt -- arithmetic never wraps: results outside
 * [-2^31, 2^31) promote to interned GMP bignums, and bignum results that
 * shrink re-contract to the s32 word.  The bignum caps (§14.4) surface as
 * mpz_overflow / mpz_table_overflow error facts via slog_error.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once

#include "mpz.h"


// View an int word as a GMP value: an s32 materializes into `tmp` (an
// initialized mpz_t the caller owns), an mpz word aliases the interned value.
static inline mpz_srcptr slog_int_view(slog::Database* db, u64 w, mpz_ptr tmp)
{
  if (is_s32(w))
  {
    mpz_set_si(tmp, (long)s32_decode(w));
    return tmp;
  }
  return db->lookup_mpz(decode_val(w))->get();
}

// Binary GMP path: view both args, apply, re-canonicalize.
#define SLOG_MPZ_BIN(GMPOP, OPSTR)                                \
  mpz_t ta, tb, r;                                                \
  mpz_inits(ta, tb, r, NULL);                                     \
  GMPOP(r, slog_int_view(db, x, ta), slog_int_view(db, y, tb));   \
  const u64 w = db->encodeMpz(r, OPSTR, x, y);                    \
  mpz_clears(ta, tb, r, NULL);                                    \
  return w

// Unary GMP path.
#define SLOG_MPZ_UN(GMPOP, OPSTR)                                 \
  mpz_t r;                                                        \
  mpz_init(r);                                                    \
  GMPOP(r, db->lookup_mpz(decode_val(x))->get());                 \
  const u64 w = db->encodeMpz(r, OPSTR, x, slog_null);            \
  mpz_clear(r);                                                   \
  return w


// ---- arithmetic -----------------------------------------------------------

inline u64 _prim_int__0002b_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (+ int int)
  if (is_s32(x) && is_s32(y))
    return db->encodeInt((s64)s32_decode(x) + (s64)s32_decode(y), "+", x, y);
  SLOG_MPZ_BIN(mpz_add, "+");
}

inline u64 _prim_int__0002d_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (- int int)
  if (is_s32(x) && is_s32(y))
    return db->encodeInt((s64)s32_decode(x) - (s64)s32_decode(y), "-", x, y);
  SLOG_MPZ_BIN(mpz_sub, "-");
}

inline u64 _prim_int__0002a_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (* int int) -- an s32 product always fits s64
  if (is_s32(x) && is_s32(y))
    return db->encodeInt((s64)s32_decode(x) * (s64)s32_decode(y), "*", x, y);
  SLOG_MPZ_BIN(mpz_mul, "*");
}

inline u64 _prim_int__0002f_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (/ int int) -- truncated (C) division; INT_MIN/-1 now simply promotes
  // A data-derived zero divisor would SIGFPE-kill the whole (shared) daemon:
  // record an (error_spec ...) and abandon the deduction instead.
  if (is_s32(x) && is_s32(y))
  {
    const s64 a = s32_decode(x), b = s32_decode(y);
    if (b == 0)
    { db->setPendingError(slog::ERR_DIV0, "/", x, y); return slog_error; }
    return db->encodeInt(a / b, "/", x, y);
  }
  mpz_t ta, tb, r;
  mpz_inits(ta, tb, r, NULL);
  mpz_srcptr vb = slog_int_view(db, y, tb);
  if (mpz_sgn(vb) == 0)
  {
    mpz_clears(ta, tb, r, NULL);
    db->setPendingError(slog::ERR_DIV0, "/", x, y);
    return slog_error;
  }
  mpz_tdiv_q(r, slog_int_view(db, x, ta), vb);
  const u64 w = db->encodeMpz(r, "/", x, y);
  mpz_clears(ta, tb, r, NULL);
  return w;
}

inline u64 _prim_int__00025_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (% int int) -- sign follows the dividend (C truncated semantics)
  if (is_s32(x) && is_s32(y))
  {
    const s64 a = s32_decode(x), b = s32_decode(y);
    if (b == 0)
    { db->setPendingError(slog::ERR_MOD0, "%", x, y); return slog_error; }
    return db->encodeInt(a % b, "%", x, y);
  }
  mpz_t ta, tb, r;
  mpz_inits(ta, tb, r, NULL);
  mpz_srcptr vb = slog_int_view(db, y, tb);
  if (mpz_sgn(vb) == 0)
  {
    mpz_clears(ta, tb, r, NULL);
    db->setPendingError(slog::ERR_MOD0, "%", x, y);
    return slog_error;
  }
  mpz_tdiv_r(r, slog_int_view(db, x, ta), vb);
  const u64 w = db->encodeMpz(r, "%", x, y);
  mpz_clears(ta, tb, r, NULL);
  return w;
}

inline u64 _prim_int_neg_unsafe(slog::Database* db, u64 x)
{ //  (neg int) -- -INT_MIN promotes
  if (is_s32(x)) return db->encodeInt(-(s64)s32_decode(x), "neg", x, slog_null);
  SLOG_MPZ_UN(mpz_neg, "neg");
}

inline u64 _prim_int_abs_unsafe(slog::Database* db, u64 x)
{ //  (abs int)
  if (is_s32(x))
  {
    const s64 v = s32_decode(x);
    return db->encodeInt(v < 0 ? -v : v, "abs", x, slog_null);
  }
  SLOG_MPZ_UN(mpz_abs, "abs");
}

inline u64 _prim_int_min_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (min int int) -- canonical words: return an argument, nothing to encode
  return db->cmpInt(x, y) <= 0 ? x : y;
}

inline u64 _prim_int_max_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (max int int)
  return db->cmpInt(x, y) >= 0 ? x : y;
}

inline u64 _prim_int_pow_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (pow int int) -- exact; negative exponent -> 0 (integer semantics)
  // An mpz exponent has magnitude >= 2^31: negative -> 0; positive is only
  // representable for base in {-1, 0, 1}.
  if (is_mpz(y))
  {
    slog::mpz_val* e = db->lookup_mpz(decode_val(y));
    if (e->negative()) return s32_encode(0);
    if (is_s32(x))
    {
      const s32 b = s32_decode(x);
      if (b == 0) return s32_encode(0);
      if (b == 1) return s32_encode(1);
      if (b == -1) return s32_encode(mpz_even_p(e->get()) ? 1 : -1);
    }
    db->setPendingError(slog::ERR_MPZ_OVF, "pow", x, y);
    return slog_error;
  }
  const s32 e = s32_decode(y);
  if (e < 0) return s32_encode(0);
  mpz_t tb;
  mpz_init(tb);
  mpz_srcptr vb = slog_int_view(db, x, tb);
  // {-1, 0, 1} never grow; otherwise precheck the result size so a huge
  // value is never allocated just to be rejected by the cap
  if (mpz_cmpabs_ui(vb, 1) <= 0)
  {
    mpz_clear(tb);
    if (mpz_sgn(vb) == 0) return s32_encode(e == 0 ? 1 : 0);
    if (mpz_sgn(vb) > 0) return s32_encode(1);
    return s32_encode((e & 1) ? -1 : 1);
  }
  if (mpz_sizeinbase(vb, 2) * (u64)e > db->mpzMaxBits())
  {
    mpz_clear(tb);
    db->setPendingError(slog::ERR_MPZ_OVF, "pow", x, y);
    return slog_error;
  }
  mpz_t r;
  mpz_init(r);
  mpz_pow_ui(r, vb, (unsigned long)e);
  const u64 w = db->encodeMpz(r, "pow", x, y);
  mpz_clears(tb, r, NULL);
  return w;
}


// ---- bitwise / shifts (true-math view, docs/primitives.md §14.3) ----------
// and/or/xor/not extend to bignums via GMP's two's-complement semantics; a
// both-s32 case can never leave the s32 range (sign-extension agrees).

inline u64 _prim_int_band_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (band int int)
  if (is_s32(x) && is_s32(y))
    return s32_encode(s32_decode(x) & s32_decode(y));
  SLOG_MPZ_BIN(mpz_and, "band");
}

inline u64 _prim_int_bor_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (bor int int)
  if (is_s32(x) && is_s32(y))
    return s32_encode(s32_decode(x) | s32_decode(y));
  SLOG_MPZ_BIN(mpz_ior, "bor");
}

inline u64 _prim_int_bxor_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (bxor int int)
  if (is_s32(x) && is_s32(y))
    return s32_encode(s32_decode(x) ^ s32_decode(y));
  SLOG_MPZ_BIN(mpz_xor, "bxor");
}

inline u64 _prim_int_bnot_unsafe(slog::Database* db, u64 x)
{ //  (bnot int) -- ~v = -v-1 stays in range for every s32
  if (is_s32(x)) return s32_encode(~s32_decode(x));
  SLOG_MPZ_UN(mpz_com, "bnot");
}

inline u64 _prim_int_shl_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (shl int int) -- exact x * 2^y (the old &31 truncation is gone);
  //  a negative count is a type error, an oversized result trips the cap
  if (is_mpz(y))
  {
    if (db->lookup_mpz(decode_val(y))->negative())
    { db->setPendingError(slog::ERR_TYPE, "shl", x, y); return slog_error; }
    if (is_s32(x) && s32_decode(x) == 0) return s32_encode(0);
    db->setPendingError(slog::ERR_MPZ_OVF, "shl", x, y);
    return slog_error;
  }
  const s32 k = s32_decode(y);
  if (k < 0)
  { db->setPendingError(slog::ERR_TYPE, "shl", x, y); return slog_error; }
  if (is_s32(x) && k <= 30)
    return db->encodeInt(((s64)s32_decode(x)) << k, "shl", x, y);
  mpz_t tb, r;
  mpz_inits(tb, r, NULL);
  mpz_srcptr vx = slog_int_view(db, x, tb);
  if (mpz_sizeinbase(vx, 2) + (u64)k > db->mpzMaxBits())
  {
    mpz_clears(tb, r, NULL);
    db->setPendingError(slog::ERR_MPZ_OVF, "shl", x, y);
    return slog_error;
  }
  mpz_mul_2exp(r, vx, (unsigned long)k);
  const u64 w = db->encodeMpz(r, "shl", x, y);
  mpz_clears(tb, r, NULL);
  return w;
}

inline u64 _prim_int_shr_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (shr int int) -- arithmetic (floor) shift: floor(x / 2^y)
  const bool xneg = is_s32(x) ? (s32_decode(x) < 0)
                              : db->lookup_mpz(decode_val(x))->negative();
  if (is_mpz(y))
  {
    if (db->lookup_mpz(decode_val(y))->negative())
    { db->setPendingError(slog::ERR_TYPE, "shr", x, y); return slog_error; }
    // every bit shifts out: floor is 0 or -1 by sign
    return s32_encode(xneg ? -1 : 0);
  }
  const s32 k = s32_decode(y);
  if (k < 0)
  { db->setPendingError(slog::ERR_TYPE, "shr", x, y); return slog_error; }
  if (is_s32(x))
    return s32_encode(s32_decode(x) >> (k > 31 ? 31 : k));
  mpz_t r;
  mpz_init(r);
  mpz_fdiv_q_2exp(r, db->lookup_mpz(decode_val(x))->get(), (unsigned long)k);
  const u64 w = db->encodeMpz(r, "shr", x, y);
  mpz_clear(r);
  return w;
}


#undef SLOG_MPZ_BIN
#undef SLOG_MPZ_UN
