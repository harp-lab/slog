
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (dump-rel error)
extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Relation* r = db->getRelation("error");
  size_t n = 0;
  if (r) slog::Database::forEachNominal(r, [&](const u64* row) {
    d->emit(std::string("(dumprow ") + db->writeValCSV(row[0]) + ")");
    ++n;
  });
  d->emit(std::string("(dumpdone ") + std::to_string(n) + ")");
}
