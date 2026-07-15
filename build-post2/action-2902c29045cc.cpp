
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (begin-segment div_by_zero error int_overflow modulo_by_zero mpz_overflow mpz_table_overflow nan_result r toint_range type_mismatch)
extern "C" void slog_plugin(slog::Daemon* d)
{
  d->beginSegment(std::vector<std::string>{"div_by_zero", "error", "int_overflow", "modulo_by_zero", "mpz_overflow", "mpz_table_overflow", "nan_result", "r", "toint_range", "type_mismatch"});
}
