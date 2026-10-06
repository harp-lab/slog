
/** Slog Fatal error
 * 
 * Defines a fatal error function both static and dynamically linked code sees.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

namespace slog
{
  // stdout is the daemon's protocol channel, so the message leaves as one
  // (error ...) record, which every driver raises with its text; bare lines
  // there were echoed or dropped, and a client saw only the EOF.  stderr gets
  // a copy for anyone running slogd by hand.
  //
  // fatal() can run on an OpenMP worker -- a barrier completion, a read
  // task -- while the rest of the team is live.  exit() would run atexit
  // handlers and static destructors underneath those threads, so flush and
  // leave with _Exit instead.
  inline void fatal(const std::string& msg)
  {
    std::string quoted;
    for (char c : msg)
    {
      if (c == '"' || c == '\\') quoted += '\\';
      quoted += c == '\n' ? ' ' : c;
    }
    std::cerr << "Fatal Error: " << msg << std::endl;
    std::cout << "(error \"fatal: " << quoted << "\")" << std::endl;
    std::fflush(nullptr);
    std::_Exit(1);
  }
}



