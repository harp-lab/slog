
/** Slog Runtime Prims
 *
 * Type-dispatching entry points ('_prim_X' functions) for Slog primitives.
 * Each dispatcher inspects the NaN-boxed tags of its arguments and forwards to
 * the concrete kernel (int_prims.h / float_prims.h / str_prims.h), or issues a
 * fatal on an unsupported combination.
 *
 * Numeric arithmetic is polymorphic: (op s32 s32) stays integer; if either
 * operand is a float (and both are numeric) the operation promotes to double.
 * Ordering comparisons (_prim_lt/le/gt/ge) return 1/0 and back the language's
 * body guards (< <= > >=).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once

#include "slogd.h"
#include "str_prims.h"
#include "int_prims.h"
#include "float_prims.h"

#include <format>
#include <cmath>

namespace {
  const char* get_type_name(u64 v) {
    if (is_s32(v)) return "int (32-bit integer)";
    if (is_mpz(v)) return "int (big integer)";
    if (is_str(v)) return "str (string)";
    if (is_float(v)) return "float (floating point)";
    if (is_struct(v)) return "struct (structure)";
    if (is_cnode(v)) return "cmap (collection)";
    if (is_seq(v)) return "cseq (sequence)";
    return "unknown type";
  }
}

// A numeric value is an int (s32 or interned mpz) or a NaN-boxed double.
static inline bool is_num(u64 v) { return is_int(v) || is_float(v); }
// Decode any numeric value to double (promoting ints; a bignum rounds --
// same loss as any int->float conversion, docs/primitives.md §14.3).
static inline double to_double(slog::Database* db, u64 v)
{
  if (is_s32(v)) return (double)s32_decode(v);
  if (is_mpz(v)) return mpz_get_d(db->lookup_mpz(decode_val(v))->get());
  return float_decode(v);
}

// Sequence and rope-string prims (docs/sequences.md): canonical [T] lists
// and tag-4 rope strings in the per-Database sequence arena (daemon/seq.h).
// Included here (before the dispatchers) so + and size can route to the
// representation-aware kernels.
#include "seq_prims.h"


// The prim dispatchers below flag a runtime error (docs/type-errors.md) instead
// of aborting the daemon: on bad data they call db->setPendingError(...) and
// return slog_error, which the generated code turns into an (error (error_spec
// ...)) fact and uses to abandon the deduction.  ERR_NAN is detected by the
// float kernels returning slog_error (float_encode of a NaN, types.h); ERR_TYPE
// covers an `any`-typed operand of the wrong kind.

// Binary numeric op: exact int kernel when both int, else promote to double.
#define SLOG_ARITH(NAME, INTK, FLTK, OPSTR)                                     \
  inline u64 NAME(slog::Database* db, u64 x, u64 y) {                           \
    if (is_int(x) && is_int(y)) return INTK(db, x, y);                          \
    if (is_num(x) && is_num(y)) { u64 r = FLTK(to_double(db, x), to_double(db, y)); \
      if (r == slog_error) db->setPendingError(slog::ERR_NAN, OPSTR, x, y);     \
      return r; }                                                              \
    db->setPendingError(slog::ERR_TYPE, OPSTR, x, y); return slog_error; }

// Binary integer-only op (bitwise / shifts).
#define SLOG_INT2(NAME, INTK, OPSTR)                                            \
  inline u64 NAME(slog::Database* db, u64 x, u64 y) {                           \
    if (is_int(x) && is_int(y)) return INTK(db, x, y);                          \
    db->setPendingError(slog::ERR_TYPE, OPSTR, x, y); return slog_error; }

// Unary integer-only op.
#define SLOG_INT1(NAME, INTK, OPSTR)                                            \
  inline u64 NAME(slog::Database* db, u64 x) {                                  \
    if (is_int(x)) return INTK(db, x);                                          \
    db->setPendingError(slog::ERR_TYPE, OPSTR, x, 0); return slog_error; }

// Unary numeric op with distinct int/float kernels.
#define SLOG_NUM1(NAME, INTK, FLTK, OPSTR)                                      \
  inline u64 NAME(slog::Database* db, u64 x) {                                  \
    if (is_int(x)) return INTK(db, x);                                          \
    if (is_float(x)) return FLTK(float_decode(x));                             \
    db->setPendingError(slog::ERR_TYPE, OPSTR, x, 0); return slog_error; }

// Unary float-math op (any numeric arg promoted to double).
#define SLOG_FMATH(NAME, FLTK, OPSTR)                                           \
  inline u64 NAME(slog::Database* db, u64 x) {                                  \
    if (is_num(x)) { u64 r = FLTK(to_double(db, x));                            \
      if (r == slog_error) db->setPendingError(slog::ERR_NAN, OPSTR, x, 0);     \
      return r; }                                                              \
    db->setPendingError(slog::ERR_TYPE, OPSTR, x, 0); return slog_error; }

// Ordering comparison (returns 1/0): exact over ints (either representation,
// Database::cmpInt); an int/float mix compares exactly too (mpz_cmp_d -- no
// 2^53 loss), and float/float falls back to double.
#define SLOG_CMP(NAME, OP, OPSTR)                                               \
  inline u64 NAME(slog::Database* db, u64 x, u64 y) {                           \
    if (is_int(x) && is_int(y)) return (db->cmpInt(x, y) OP 0) ? 1 : 0;         \
    if (is_num(x) && is_num(y)) {                                               \
      if (is_mpz(x)) return (mpz_cmp_d(db->lookup_mpz(decode_val(x))->get(),    \
                                       float_decode(y)) OP 0) ? 1 : 0;          \
      if (is_mpz(y)) return (0 OP mpz_cmp_d(db->lookup_mpz(decode_val(y))->get(), \
                                            float_decode(x))) ? 1 : 0;          \
      return (to_double(db, x) OP to_double(db, y)) ? 1 : 0; }                  \
    db->setPendingError(slog::ERR_TYPE, OPSTR, x, y); return slog_error; }


//  (+ x y) -- int, float, or string concatenation (mono or rope)
inline u64 _prim__0002b(slog::Database* db, u64 x, u64 y)
{
  if (is_int(x) && is_int(y)) return _prim_int__0002b_unsafe(db, x, y);
  if (is_str(x) && is_str(y)) return _prim_str_concat(db, x, y);
  if (is_num(x) && is_num(y))
  {
    u64 r = _prim_float__0002b_unsafe(to_double(db, x), to_double(db, y));
    if (r == slog_error) db->setPendingError(slog::ERR_NAN, "+", x, y);
    return r;
  }
  db->setPendingError(slog::ERR_TYPE, "+", x, y);
  return slog_error;
}

SLOG_ARITH(_prim__0002d, _prim_int__0002d_unsafe, _prim_float__0002d_unsafe, "-")
SLOG_ARITH(_prim__0002a, _prim_int__0002a_unsafe, _prim_float__0002a_unsafe, "*")
SLOG_ARITH(_prim__0002f, _prim_int__0002f_unsafe, _prim_float__0002f_unsafe, "/")
SLOG_ARITH(_prim__00025, _prim_int__00025_unsafe, _prim_float__00025_unsafe, "%")
SLOG_ARITH(_prim_min,    _prim_int_min_unsafe,    _prim_float_min_unsafe,    "min")
SLOG_ARITH(_prim_max,    _prim_int_max_unsafe,    _prim_float_max_unsafe,    "max")
SLOG_ARITH(_prim_pow,    _prim_int_pow_unsafe,    _prim_float_pow_unsafe,    "pow")

SLOG_NUM1(_prim_neg, _prim_int_neg_unsafe, _prim_float_neg_unsafe, "neg")
SLOG_NUM1(_prim_abs, _prim_int_abs_unsafe, _prim_float_abs_unsafe, "abs")

SLOG_INT2(_prim_band, _prim_int_band_unsafe, "band")
SLOG_INT2(_prim_bor,  _prim_int_bor_unsafe,  "bor")
SLOG_INT2(_prim_bxor, _prim_int_bxor_unsafe, "bxor")
SLOG_INT2(_prim_shl,  _prim_int_shl_unsafe,  "shl")
SLOG_INT2(_prim_shr,  _prim_int_shr_unsafe,  "shr")
SLOG_INT1(_prim_bnot, _prim_int_bnot_unsafe, "bnot")

SLOG_FMATH(_prim_sqrt,  _prim_float_sqrt_unsafe,  "sqrt")
SLOG_FMATH(_prim_sin,   _prim_float_sin_unsafe,   "sin")
SLOG_FMATH(_prim_cos,   _prim_float_cos_unsafe,   "cos")
SLOG_FMATH(_prim_tan,   _prim_float_tan_unsafe,   "tan")
SLOG_FMATH(_prim_exp,   _prim_float_exp_unsafe,   "exp")
SLOG_FMATH(_prim_log,   _prim_float_log_unsafe,   "log")
SLOG_FMATH(_prim_floor, _prim_float_floor_unsafe, "floor")
SLOG_FMATH(_prim_ceil,  _prim_float_ceil_unsafe,  "ceil")
SLOG_FMATH(_prim_round, _prim_float_round_unsafe, "round")

SLOG_CMP(_prim_lt, <,  "<")
SLOG_CMP(_prim_le, <=, "<=")
SLOG_CMP(_prim_gt, >,  ">")
SLOG_CMP(_prim_ge, >=, ">=")


//  (tofloat x) -- int->float (or float identity; a bignum rounds)
inline u64 _prim_tofloat(slog::Database* db, u64 x)
{
  if (is_num(x)) return float_encode(to_double(db, x));
  db->setPendingError(slog::ERR_TYPE, "tofloat", x, 0);
  return slog_error;
}

//  (toint x) -- float->int (truncating) (or int identity).  An out-of-s32-
//  range integral double now promotes to a bignum (docs/primitives.md §14.3);
//  ERR_TOINT remains only for non-finite (+-inf) inputs.
inline u64 _prim_toint(slog::Database* db, u64 x)
{
  if (is_int(x)) return x;
  if (is_float(x))
  {
    double d = float_decode(x);
    if (!std::isfinite(d))
    { db->setPendingError(slog::ERR_TOINT, "toint", x, 0); return slog_error; }
    if (d >= -2147483648.0 && d <= 2147483647.0)
      return s32_encode((s32)d);
    mpz_t z;
    mpz_init(z);
    mpz_set_d(z, d);   // truncates toward zero, exact for |d| >= 2^53
    const u64 w = db->encodeMpz(z, "toint", x, slog_null);
    mpz_clear(z);
    return w;
  }
  db->setPendingError(slog::ERR_TYPE, "toint", x, 0);
  return slog_error;
}


//  (size x) -- length of a string (codepoints, either representation) or
//  a sequence (elements)
inline u64 _prim_size(slog::Database* db, u64 v)
{
  if (is_mono_str(v)) return _prim_str_size_unsafe(db, v);
  if (is_rope(v)) return s32_encode((s32)db->sequences()->cp_len(v));
  if (is_seq(v)) return s32_encode((s32)db->sequences()->len(v));
  db->setPendingError(slog::ERR_TYPE, "size", v, 0);
  return slog_error;
}


// Collection prims (docs/primitives.md M2.1): canonical finite maps/sets as
// interned Patricia tries in the per-Database collection arena (arena.h).
// A collection value is one NaN-boxed word (is_cnode); keys and values are
// arbitrary slog words.  A set is a map-to-unit: cins/cmem are cput/chas
// with value 1.  cmerge is LEFT-biased (the first argument's value wins on
// key collision), mirroring lib/map.slog's mp_union.

#define SLOG_CNODE_ARG(v, OPSTR)                                                \
  if (!is_cnode(v))                                                             \
    slog::fatal(std::format("Function '" OPSTR "' requires a collection, got: {}", \
                            get_type_name(v)));

//  (cmap) -- the empty map/set
inline u64 _prim_cmap(slog::Database* db)
{
  return db->collections()->empty();
}

//  (cput m k v) -- m with k mapped to v (replaces on collision)
inline u64 _prim_cput(slog::Database* db, u64 m, u64 k, u64 v)
{
  SLOG_CNODE_ARG(m, "cput");
  return db->collections()->put(m, k, v);
}

//  (cget m k) -- the value at k.  PARTIAL (compiler/primitives.rkt
//  prim-partial?): an absent key is missing *data*, not a bug -- set *ok =
//  false and the generated letp check abandons the row (a failed match
//  against a virtual relation; no chas guard needed).  A non-collection m
//  STAYS fatal: partiality is for absent data, not for type errors.
inline u64 _prim_cget(slog::Database* db, u64 m, u64 k, bool* ok)
{
  SLOG_CNODE_ARG(m, "cget");
  u64 out = 0;
  if (!db->collections()->find(m, k, &out))
  {
    *ok = false;
    return 0;
  }
  return out;
}

//  (chas m k) -- 1 if k present, else 0
inline u64 _prim_chas(slog::Database* db, u64 m, u64 k)
{
  SLOG_CNODE_ARG(m, "chas");
  return s32_encode(db->collections()->find(m, k, 0) ? 1 : 0);
}

//  (cmerge a b) -- left-biased union
inline u64 _prim_cmerge(slog::Database* db, u64 a, u64 b)
{
  SLOG_CNODE_ARG(a, "cmerge");
  SLOG_CNODE_ARG(b, "cmerge");
  return db->collections()->merge(a, b);
}

//  (cdel m k) -- m without k
inline u64 _prim_cdel(slog::Database* db, u64 m, u64 k)
{
  SLOG_CNODE_ARG(m, "cdel");
  return db->collections()->del(m, k);
}

//  (cdiff a b) -- entries of a whose keys are not in b
inline u64 _prim_cdiff(slog::Database* db, u64 a, u64 b)
{
  SLOG_CNODE_ARG(a, "cdiff");
  SLOG_CNODE_ARG(b, "cdiff");
  return db->collections()->diff(a, b);
}

//  (csize m) -- number of entries
inline u64 _prim_csize(slog::Database* db, u64 m)
{
  SLOG_CNODE_ARG(m, "csize");
  return s32_encode((s32)db->collections()->size(m));
}

//  (cins s k) -- set insert: (cput s k 1)
inline u64 _prim_cins(slog::Database* db, u64 s, u64 k)
{
  SLOG_CNODE_ARG(s, "cins");
  return db->collections()->put(s, k, s32_encode(1));
}

//  (cmem s k) -- set membership: (chas s k)
inline u64 _prim_cmem(slog::Database* db, u64 s, u64 k)
{
  SLOG_CNODE_ARG(s, "cmem");
  return s32_encode(db->collections()->find(s, k, 0) ? 1 : 0);
}

#undef SLOG_CNODE_ARG


// Lattice constants and transfers (docs/lattices.md).  The count lattice is
// the chain 0 < 1 < inf with 0 = absence (never stored), carried as tagged
// s32 words 1 and 2; its merge is max (idempotent).  cplus is the abstract
// increment (1 (+) 1 = inf): non-idempotent but monotone in both arguments --
// the evolution operator, distinct from the merge.  (top) is flat's top.
inline u64 _prim_one(slog::Database* db) { (void)db; return s32_encode(1); }
inline u64 _prim_inf(slog::Database* db) { (void)db; return s32_encode(2); }
inline u64 _prim_top(slog::Database* db) { (void)db; return slog_lat_top; }
inline u64 _prim_cplus(slog::Database* db, u64 x, u64 y)
{
  if (is_s32(x) && is_s32(y))
  {
    const s32 n = s32_decode(x) + s32_decode(y);
    return s32_encode(n >= 2 ? 2 : n);
  }
  slog::fatal(std::format("Function 'cplus' requires count values, got: {} and {}",
                          get_type_name(x), get_type_name(y)));
  return 0;
}

#undef SLOG_ARITH
#undef SLOG_INT2
#undef SLOG_INT1
#undef SLOG_NUM1
#undef SLOG_FMATH
#undef SLOG_CMP
