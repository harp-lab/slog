
/** Slog String Prims
 *
 * MONOLITHIC (tag-0) string kernels only.  Rope-aware dispatch lives in
 * seq_prims.h (docs/sequences.md §6): substr and string-+ were reworked
 * there (_prim_substr / _prim_str_concat), leaving the mono size kernel.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once

#include "slogd.h"


inline u64 _prim_str_size_unsafe(slog::Database* db, u64 v)
{
  return s32_encode((str_decode(db,v))->size());
}
