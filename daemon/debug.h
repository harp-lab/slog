
/** Slog Debug
 * 
 * Defines a few debug related macros and settings.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once

#include "types.h"
#include <sstream>
#include <chrono>

// Debug macros (prints atomically for multithread debugging)

// A scoped constexpr, NOT `#define debug false`: an object-like lowercase macro
// textually rewrites every `debug` token in every TU that transitively includes
// this header (index.h already had to push_macro/#undef it to shield tlx).
inline constexpr bool debug = false;
#define DEBUG(x) {if(debug){std::stringstream strm; strm << x << std::endl; std::cout << strm.str();}}



inline u64 utime()
{
  using namespace std::chrono;
  return duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();
}


