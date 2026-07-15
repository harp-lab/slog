
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (begin-segment big div_by_zero error grow int_overflow modulo_by_zero mpz_overflow mpz_table_overflow nan_result toint_range type_mismatch)
extern "C" void slog_plugin(slog::Daemon* d)
{
  d->beginSegment(std::vector<std::string>{"big", "div_by_zero", "error", "grow", "int_overflow", "modulo_by_zero", "mpz_overflow", "mpz_table_overflow", "nan_result", "toint_range", "type_mismatch"});
}
