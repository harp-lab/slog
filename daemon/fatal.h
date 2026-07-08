
/** Slog Fatal error
 * 
 * Defines a fatal error function both static and dynamically linked code sees.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once



namespace slog
{
  inline void fatal(const std::string& msg)
  {
    std::cout << "Fatal Error" << std::endl << msg << std::endl;
    exit(1);
  }
}



