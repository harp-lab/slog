
/** Slog Integer Prims
 * 
 * Includes all integer prims
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once


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







