
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (write-csv "out/test-sdeep_dedup")
extern "C" void slog_plugin(slog::Daemon* d)
{
  d->db()->writeDatabaseCSV("out/test-sdeep_dedup");
}
