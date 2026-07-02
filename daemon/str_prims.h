
/** Slog String Prims
 * 
 * Includes all string prims
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once

#include "slogd.h"


u64 _prim_str_size_unsafe(slog::Database* db, u64 v)
{
  return s32_encode((str_decode(db,v))->size());
}



//  (substr s start end) -- the characters in [start, end), clamped
u64 _prim_substr(slog::Database* db, u64 s, u64 i, u64 e)
{
  if (is_str(s) && is_s32(i) && is_s32(e))
  {
    s32 start = s32_decode(i);
    s32 end = s32_decode(e);
    if (start < 0) start = 0;
    if (end < start) end = start;
    return str_encode(db, str_decode(db,s)->substr(start, end - start));
  }

  slog::fatal("Substr invoked on bad inputs.");
  return 0;
}


inline u64 _prim_str__0002b_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (+ str str)
  return str_encode(db, *str_decode(db, x) + *str_decode(db, y));
}


