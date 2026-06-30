
/** Slog Runtime Prims
 * 
 * Includes all runtime prims ('_prim_X' functions) for Slog.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once

#include "slogd.h"
#include "str_prims.h"
#include "int_prims.h"

#include <format>

namespace {
  const char* get_type_name(u64 v) {
    if (is_s32(v)) return "s32 (32-bit integer)";
    if (is_str(v)) return "str (string)"; 
    if (is_float(v)) return "float (floating point)";
    if (is_struct(v)) return "struct (structure)";
    return "unknown type";
  }
}

inline u64 _prim_size(slog::Database* db, u64 v)
{
  if (is_str(v))
    return _prim_str_size_unsafe(db, v);
  
  slog::fatal(std::format("Function 'size' does not support type: {}. Supported types: str", get_type_name(v)));
  return 0;
}


//  (+ x y)
inline u64 _prim__0002b(slog::Database* db, u64 x, u64 y)
{
  if (is_s32(x) && is_s32(y))
    return _prim_s32__0002b_unsafe(db, x, y);
  else if (is_str(x) && is_str(y))
    return _prim_str__0002b_unsafe(db, x, y);

  DEBUG(std::format("{:b}",x));
  DEBUG(std::format("{:b}",y));
  slog::fatal(std::format("Function '+' does not support types: {} and {}. Supported combinations: s32+s32, str+str", 
                          get_type_name(x), get_type_name(y)));
  return 0;
}


//  (- x y)
inline u64 _prim__0002d(slog::Database* db, u64 x, u64 y)
{
  if (is_s32(x) && is_s32(y))
    return _prim_s32__0002d_unsafe(db, x, y);

  slog::fatal(std::format("Function '-' does not support types: {} and {}. Supported combinations: s32-s32", 
                          get_type_name(x), get_type_name(y)));
  return 0;
}


//  (/ x y)
inline u64 _prim__0002f(slog::Database* db, u64 x, u64 y)
{
  if (is_s32(x) && is_s32(y))
    return _prim_s32__0002f_unsafe(db, x, y);

  slog::fatal(std::format("Function '/' does not support types: {} and {}. Supported combinations: s32/s32", 
                          get_type_name(x), get_type_name(y)));
  return 0;
}


//  (* x y)
inline u64 _prim__0002a(slog::Database* db, u64 x, u64 y)
{
  if (is_s32(x) && is_s32(y))
    return _prim_s32__0002a_unsafe(db, x, y);

  slog::fatal(std::format("Function '*' does not support types: {} and {}. Supported combinations: s32*s32", 
                          get_type_name(x), get_type_name(y)));
  return 0;
}


//  (% x y)
inline u64 _prim__00025(slog::Database* db, u64 x, u64 y)
{
  if (is_s32(x) && is_s32(y))
    return _prim_s32__00025_unsafe(db, x, y);

  slog::fatal(std::format("Function '%' does not support types: {} and {}. Supported combinations: s32%s32", 
                          get_type_name(x), get_type_name(y)));
  return 0;
}




