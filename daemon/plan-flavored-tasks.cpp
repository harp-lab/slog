/** Thread-0 flavored registration ladders (counted-interp slices 1-3).
 *
 * The per-arity boilerplate the native flavored plugins carry -- index
 * requisitions and Write/Intern/Count/Maintain task construction -- driven
 * from a sealed plan's structural facts.  Registration is cold (once per
 * flavored stratum install), but instantiating the daemon's storage
 * templates across the full arity range is the dominant compile cost, so
 * this deliberately lives in its own translation unit built at -O0 (the
 * same optimization level every native flavored .so uses); plan-count.cpp
 * calls through the non-template entry points in plan-count.h.
 */

#include "plan-count.h"
#include "daemon.h"

namespace slog
{
namespace interp
{

namespace
{

template <u16 A>
std::array<u16, A> to_ordering_array(const std::vector<u16>& order)
{
  std::array<u16, A> out{};
  std::copy(order.begin(), order.end(), out.begin());
  return out;
}

template <u16 A>
void count_task_ladder(u16 arity, Database* db, Stratum* stratum,
                       Relation* relation, bool is_struct)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)db; (void)stratum; (void)relation; (void)is_struct;
    fatal("count install: counted-head task ladder miss");
  }
  else
  {
    if (arity == A)
    {
      for (u16 b = 0; b < bucket_count; ++b)
        stratum->addTask(phase_intern,
          is_struct
            ? static_cast<Task*>(new CountStructTask<A>(db, relation, b))
            : static_cast<Task*>(new CountTask<A>(db, relation, b)),
          false);
      return;
    }
    count_task_ladder<A - 1>(arity, db, stratum, relation, is_struct);
  }
}

template <u16 A>
void write_task_ladder(u16 arity, Database* db, Stratum* stratum,
                       Relation* relation, const std::vector<u16>& order,
                       bool delta, bool once_only)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)db; (void)stratum; (void)relation; (void)order;
    (void)delta; (void)once_only;
    fatal("maintenance install: write task ladder miss");
  }
  else
  {
    if (arity == A)
    {
      for (u16 b = 0; b < bucket_count; ++b)
        stratum->addTask(phase_write,
          new WriteTask<A>(db, relation, to_ordering_array<A>(order),
                           delta, b),
          once_only);
      return;
    }
    write_task_ladder<A - 1>(arity, db, stratum, relation, order, delta,
                             once_only);
  }
}

template <u16 A>
void seeded_write_task_ladder(u16 arity, Database* db, Stratum* stratum,
                              Relation* relation,
                              const std::vector<u16>& order, bool delta)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)db; (void)stratum; (void)relation; (void)order;
    (void)delta;
    fatal("normal install: seeded write task ladder miss");
  }
  else
  {
    if (arity == A)
    {
      for (u16 b = 0; b < bucket_count; ++b)
        stratum->addTaskSeeded(phase_write,
          new WriteTask<A>(db, relation, to_ordering_array<A>(order),
                           delta, b));
      return;
    }
    seeded_write_task_ladder<A - 1>(arity, db, stratum, relation, order,
                                     delta);
  }
}

template <u16 A>
void map_write_task_ladder(u16 arity, Database* db, Stratum* stratum,
                           Relation* relation,
                           const std::vector<u16>& order, Relation* decomp,
                           bool decomp_map, bool once_only)
{
  if constexpr (A <= 1)
  {
    (void)arity; (void)db; (void)stratum; (void)relation; (void)order;
    (void)decomp; (void)decomp_map; (void)once_only;
    fatal("normal install: map write task ladder miss");
  }
  else
  {
    if (arity == A)
    {
      for (u16 b = 0; b < bucket_count; ++b)
        stratum->addTask(phase_write,
          new MapWriteTask<A>(db, relation, to_ordering_array<A>(order), b,
                              decomp, decomp_map),
          once_only);
      return;
    }
    map_write_task_ladder<A - 1>(arity, db, stratum, relation, order,
                                  decomp, decomp_map, once_only);
  }
}

template <u16 A>
void intern_task_ladder(u16 arity, Database* db, Stratum* stratum,
                        Relation* relation, const std::vector<u16>& order,
                        bool is_struct)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)db; (void)stratum; (void)relation; (void)order;
    (void)is_struct;
    fatal("maintenance install: intern task ladder miss");
  }
  else
  {
    if (arity == A)
    {
      for (u16 b = 0; b < bucket_count; ++b)
        stratum->addTask(phase_intern,
          is_struct
            ? static_cast<Task*>(new InternStructTask<A>(
                db, relation, to_ordering_array<A>(order), b))
            : static_cast<Task*>(new InternTask<A>(
                db, relation, to_ordering_array<A>(order), b)),
          false);
      return;
    }
    intern_task_ladder<A - 1>(arity, db, stratum, relation, order,
                              is_struct);
  }
}

template <u16 A>
void lattice_intern_task_ladder(u16 arity, Database* db, Stratum* stratum,
                                Relation* relation,
                                const std::vector<u16>& order,
                                Relation* decomp, bool decomp_map)
{
  if constexpr (A <= 1)
  {
    (void)arity; (void)db; (void)stratum; (void)relation; (void)order;
    (void)decomp; (void)decomp_map;
    fatal("normal install: lattice intern task ladder miss");
  }
  else
  {
    if (arity == A)
    {
      for (u16 b = 0; b < bucket_count; ++b)
        stratum->addTask(phase_intern,
          new LatticeInternTask<A>(db, relation,
            to_ordering_array<A>(order), b, decomp, decomp_map), false);
      return;
    }
    lattice_intern_task_ladder<A - 1>(arity, db, stratum, relation, order,
                                       decomp, decomp_map);
  }
}

template <u16 A>
void maintain_task_ladder(u16 arity, Database* db, Stratum* stratum,
                          Relation* relation,
                          const std::vector<u16>& order, bool is_struct,
                          bool dred)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)db; (void)stratum; (void)relation; (void)order;
    (void)is_struct; (void)dred;
    fatal("maintenance install: maintain task ladder miss");
  }
  else
  {
    if (arity == A)
    {
      // One serial fold per maintained relation (never per-bucket): it
      // owns membership transitions and, for structs, id resolution.
      Task* task = nullptr;
      if (is_struct)
      {
        if constexpr (A >= 2)
          task = new MaintainStructTask<A>(
            db, relation, to_ordering_array<A>(order), 0, dred);
        else
          fatal("maintenance install: struct head arity below 2");
      }
      else
        task = new MaintainTask<A>(
          db, relation, to_ordering_array<A>(order), 0, dred);
      stratum->addTask(phase_intern, task, false);
      return;
    }
    maintain_task_ladder<A - 1>(arity, db, stratum, relation, order,
                                is_struct, dred);
  }
}

template <u16 A>
void lattice_maintain_task_ladder(u16 arity, Database* db, Stratum* stratum,
                                  Relation* relation, bool dred,
                                  bool recursive)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)db; (void)stratum; (void)relation;
    (void)dred; (void)recursive;
    fatal("maintenance install: lattice maintain ladder miss");
  }
  else
  {
    if (arity == A)
    {
      if constexpr (A >= 2)
      {
        stratum->addTask(phase_intern,
                         new LatticeMaintainTask<A>(db, relation, dred,
                                                    recursive), false);
        return;
      }
      else
        fatal("maintenance install: lattice arity below 2");
    }
    lattice_maintain_task_ladder<A - 1>(arity, db, stratum, relation, dred,
                                        recursive);
  }
}

template <u16 A>
void add_index_ladder(u16 arity, Relation* relation,
                      const std::vector<u16>& order, bool map, bool delta,
                      bool seeded_only)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)relation; (void)order; (void)map; (void)delta;
    (void)seeded_only;
    fatal("flavored install: index ladder miss");
  }
  else
  {
    if (arity == A)
    {
      if (map) relation->addMapIndex<A>(order);
      else relation->addIndex<A>(order, delta, seeded_only);
      return;
    }
    add_index_ladder<A - 1>(arity, relation, order, map, delta,
                             seeded_only);
  }
}

} // namespace

void add_flavored_index(u16 arity, Relation* relation,
                        const std::vector<u16>& order, bool map, bool delta,
                        bool seeded_only)
{
  add_index_ladder<max_daemon_arity>(arity, relation, order, map, delta,
                                      seeded_only);
}

void add_flavored_count_task(u16 arity, Database* db, Stratum* stratum,
                             Relation* relation, bool is_struct)
{
  count_task_ladder<max_daemon_arity>(arity, db, stratum, relation,
                                      is_struct);
}

void add_flavored_write_task(u16 arity, Database* db, Stratum* stratum,
                             Relation* relation,
                             const std::vector<u16>& order, bool delta,
                             bool once_only)
{
  write_task_ladder<max_daemon_arity>(arity, db, stratum, relation, order,
                                      delta, once_only);
}

void add_flavored_seeded_write_task(
  u16 arity, Database* db, Stratum* stratum, Relation* relation,
  const std::vector<u16>& order, bool delta)
{
  seeded_write_task_ladder<max_daemon_arity>(
    arity, db, stratum, relation, order, delta);
}

void add_flavored_map_write_task(
  u16 arity, Database* db, Stratum* stratum, Relation* relation,
  const std::vector<u16>& order, Relation* decomp, bool decomp_map,
  bool once_only)
{
  map_write_task_ladder<max_daemon_arity>(
    arity, db, stratum, relation, order, decomp, decomp_map, once_only);
}

void add_flavored_intern_task(u16 arity, Database* db, Stratum* stratum,
                              Relation* relation,
                              const std::vector<u16>& order, bool is_struct)
{
  intern_task_ladder<max_daemon_arity>(arity, db, stratum, relation, order,
                                       is_struct);
}

void add_flavored_lattice_intern_task(
  u16 arity, Database* db, Stratum* stratum, Relation* relation,
  const std::vector<u16>& order, Relation* decomp, bool decomp_map)
{
  lattice_intern_task_ladder<max_daemon_arity>(
    arity, db, stratum, relation, order, decomp, decomp_map);
}

void add_flavored_maintain_task(u16 arity, Database* db, Stratum* stratum,
                                Relation* relation,
                                const std::vector<u16>& order,
                                bool is_struct, bool dred)
{
  maintain_task_ladder<max_daemon_arity>(arity, db, stratum, relation,
                                         order, is_struct, dred);
}

void add_flavored_lattice_maintain_task(u16 arity, Database* db,
                                        Stratum* stratum,
                                        Relation* relation, bool dred,
                                        bool recursive)
{
  lattice_maintain_task_ladder<max_daemon_arity>(arity, db, stratum,
                                                 relation, dred, recursive);
}

} // namespace interp
} // namespace slog
