
/** Slog Integer Prims
 *
 * Signed 32-bit integer kernels.  These are the "_unsafe" workers: they assume
 * their arguments are already known to be s32 (the dispatchers in prims.h do the
 * type check and choose int vs float).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once


// ---- arithmetic -----------------------------------------------------------

inline u64 _prim_s32__0002b_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (+ s32 s32)
  return s32_encode(s32_decode(x) + s32_decode(y));
}

inline u64 _prim_s32__0002d_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (- s32 s32)
  return s32_encode(s32_decode(x) - s32_decode(y));
}

inline u64 _prim_s32__0002f_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (/ s32 s32)
  return s32_encode(s32_decode(x) / s32_decode(y));
}

inline u64 _prim_s32__0002a_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (* s32 s32)
  return s32_encode(s32_decode(x) * s32_decode(y));
}

inline u64 _prim_s32__00025_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (% s32 s32)
  return s32_encode(s32_decode(x) % s32_decode(y));
}

inline u64 _prim_s32_neg_unsafe(slog::Database* db, u64 x)
{ //  (neg s32)
  return s32_encode(-s32_decode(x));
}

inline u64 _prim_s32_abs_unsafe(slog::Database* db, u64 x)
{ //  (abs s32)
  s32 v = s32_decode(x);
  return s32_encode(v < 0 ? -v : v);
}

inline u64 _prim_s32_min_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (min s32 s32)
  s32 a = s32_decode(x), b = s32_decode(y);
  return s32_encode(a < b ? a : b);
}

inline u64 _prim_s32_max_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (max s32 s32)
  s32 a = s32_decode(x), b = s32_decode(y);
  return s32_encode(a > b ? a : b);
}

inline u64 _prim_s32_pow_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (pow s32 s32) -- integer exponentiation; negative exponent -> 0
  s32 base = s32_decode(x), exp = s32_decode(y);
  if (exp < 0) return s32_encode(0);
  s32 acc = 1;
  while (exp-- > 0) acc *= base;
  return s32_encode(acc);
}


// ---- bitwise / shifts -----------------------------------------------------

inline u64 _prim_s32_band_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (band s32 s32)
  return s32_encode(s32_decode(x) & s32_decode(y));
}

inline u64 _prim_s32_bor_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (bor s32 s32)
  return s32_encode(s32_decode(x) | s32_decode(y));
}

inline u64 _prim_s32_bxor_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (bxor s32 s32)
  return s32_encode(s32_decode(x) ^ s32_decode(y));
}

inline u64 _prim_s32_bnot_unsafe(slog::Database* db, u64 x)
{ //  (bnot s32)
  return s32_encode(~s32_decode(x));
}

inline u64 _prim_s32_shl_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (shl s32 s32)
  return s32_encode(s32_decode(x) << (s32_decode(y) & 31));
}

inline u64 _prim_s32_shr_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (shr s32 s32) -- arithmetic (sign-propagating) right shift
  return s32_encode(s32_decode(x) >> (s32_decode(y) & 31));
}
