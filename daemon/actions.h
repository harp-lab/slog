/** Client actions on the command layer.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2026
 * Some rights reserved. See License.md for details.
 ******************************/

#pragma once

#include <string>

#include "sexp.h"

namespace slog
{
class Daemon;

namespace actions
{

// Handle one client action -- the database verbs a driver sends besides
// strata (open, write-db, add-batch, dump-counts, ...): true when `verb`
// names one (its reply, or a parse refusal, has been emitted), false to
// leave the line to the rest of the command dispatcher.
bool dispatch(Daemon* d, const sexp::SExp& form, const std::string& verb);

} // namespace actions
} // namespace slog
