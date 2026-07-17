// Out-of-line runtime storage factories shared by slogd and standalone
// production-engine tests.  Keeping the full arity ladders in one translation
// unit prevents generated plugins (and every plan consumer) from re-instantiating
// them.  slogd exports these symbols via -rdynamic.

#include "daemon.h"

namespace slog
{

Index* makeIndex(u16 arity)
{
  if (arity == 0 || arity > max_daemon_arity)
    fatal("Relation arity beyond daemon-side index support ("
          + std::to_string(arity) + ")");
  return makeIndexRec<max_daemon_arity>(arity);
}

Index* makeMapIndex(u16 keyarity, u32 kind,
                    bool hf, u64 fw, bool hc, u64 cw,
                    const LatSpec* spec, CollectionArena* arena)
{
  if (keyarity == 0 || keyarity > max_daemon_arity)
    fatal("Lattice key arity beyond daemon-side index support ("
          + std::to_string(keyarity) + ")");
  return makeMapIndexRec<max_daemon_arity>(keyarity, kind, hf, fw, hc, cw,
                                           spec, arena);
}

} // namespace slog

