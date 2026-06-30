
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



u64 _prim_substr(slog::Database* db, u64 s, u64 i, u64 l)
{
  if (is_str(s) && is_s32(i) && is_s32(l))
    return str_encode(db, str_decode(db,s)->substr(s32_decode(i), s32_decode(l)));

  slog::fatal("Substr invoked on bad inputs.");
  return 0;
}


inline u64 _prim_str__0002b_unsafe(slog::Database* db, u64 x, u64 y)
{ //  (+ str str)
  return str_encode(db, *str_decode(db, x) + *str_decode(db, y));
}


