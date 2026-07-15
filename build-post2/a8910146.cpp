
#include "../daemon/daemon.h"
#include "../daemon/operators.h"




extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("a8910146");
  if (s == nullptr) return;
  slog::Relation* r;
  r = db->getRelation("unique_closure");
  if (r == 0) db->addRelation("unique_closure", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("unique_closure");
      std::vector<u16> ord76({0});
    
    r->addIndex<1>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("unique_closure"), std::array<u16,1>{0}, b));
  r = db->getRelation("unique_binding");
  if (r == 0) db->addRelation("unique_binding", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("unique_binding");
      std::vector<u16> ord77({0, 1});
    
    r->addIndex<2>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("unique_binding"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord78({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord79({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord80({1, 2, 0});
    
    r->addIndex<3>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord81({0, 1, 2});
    
    r->addIndex<3>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("tick_ans");
  if (r == 0) db->addRelation("tick_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tick_ans");
      std::vector<u16> ord82({0, 1});
    
    r->addIndex<2>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("tick_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("tick");
  if (r == 0) db->addStruct("tick", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tick");
      std::vector<u16> ord83({1, 2, 0});
    
    r->addIndex<3>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord84({0, 1, 2});
    
    r->addIndex<3>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("tick"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp8IBL1233");
  if (r == 0) db->addTempRelation("temp8IBL1233", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6Qm11234");
  if (r == 0) db->addTempRelation("temp6Qm11234", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("target_count");
  if (r == 0) db->addRelation("target_count", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("target_count");
  r->setLattice(LAT_COUNT, false, 0, false, 0, "count", db->collections());
      std::vector<u16> ord85({0, 1});
    
    r->addMapIndex<2>(ord85);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<2>(db, r, std::array<u16,2>{0, 1}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<2>(db, db->getRelation("target_count"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("symval");
  if (r == 0) db->addStruct("symval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("symval");
      std::vector<u16> ord86({1, 0});
    
    r->addIndex<2>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord87({0, 1});
    
    r->addIndex<2>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("symval"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("sym");
  if (r == 0) db->addStruct("sym", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("sym");
      std::vector<u16> ord88({1, 0});
    
    r->addIndex<2>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord89({0, 1});
    
    r->addIndex<2>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("sym"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("summarized_closure");
  if (r == 0) db->addRelation("summarized_closure", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("summarized_closure");
      std::vector<u16> ord90({0});
    
    r->addIndex<1>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("summarized_closure"), std::array<u16,1>{0}, b));
  r = db->getRelation("summarized_binding");
  if (r == 0) db->addRelation("summarized_binding", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("summarized_binding");
      std::vector<u16> ord91({0, 1});
    
    r->addIndex<2>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("summarized_binding"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord92({1, 2, 0});
    
    r->addIndex<3>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord93({0, 1, 2});
    
    r->addIndex<3>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("site_targets");
  if (r == 0) db->addRelation("site_targets", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("site_targets");
      std::vector<u16> ord94({0, 1});
    
    r->addIndex<2>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("site_targets"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("singleton_flow");
  if (r == 0) db->addRelation("singleton_flow", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("singleton_flow");
      std::vector<u16> ord95({0, 1});
    
    r->addIndex<2>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("singleton_flow"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("select_branch_ans");
  if (r == 0) db->addRelation("select_branch_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("select_branch_ans");
      std::vector<u16> ord96({0, 1});
    
    r->addIndex<2>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("select_branch_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("select_branch");
  if (r == 0) db->addStruct("select_branch", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("select_branch");
      std::vector<u16> ord97({1, 2, 3, 0});
    
    r->addIndex<4>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord98({0, 1, 2, 3});
    
    r->addIndex<4>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("select_branch"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("scheme_false");
  if (r == 0) db->addRelation("scheme_false", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("scheme_false");
      std::vector<u16> ord99({0});
    
    r->addIndex<1>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("scheme_false"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord100({1, 0});
    
    r->addIndex<2>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord101({0, 1});
    
    r->addIndex<2>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("reachable_expr");
  if (r == 0) db->addRelation("reachable_expr", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("reachable_expr");
      std::vector<u16> ord102({0});
    
    r->addIndex<1>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("reachable_expr"), std::array<u16,1>{0}, b));
  r = db->getRelation("program_result");
  if (r == 0) db->addRelation("program_result", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program_result");
      std::vector<u16> ord103({0});
    
    r->addIndex<1>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program_result"), std::array<u16,1>{0}, b));
  r = db->getRelation("program");
  if (r == 0) db->addRelation("program", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program");
      std::vector<u16> ord104({0});
    
    r->addIndex<1>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program"), std::array<u16,1>{0}, b));
  r = db->getRelation("primitive_site");
  if (r == 0) db->addRelation("primitive_site", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("primitive_site");
      std::vector<u16> ord105({0, 1});
    
    r->addIndex<2>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("primitive_site"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("primitive");
  if (r == 0) db->addRelation("primitive", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("primitive");
      std::vector<u16> ord106({0});
    
    r->addIndex<1>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("primitive"), std::array<u16,1>{0}, b));
  r = db->getRelation("prim");
  if (r == 0) db->addStruct("prim", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("prim");
      std::vector<u16> ord107({1, 0});
    
    r->addIndex<2>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord108({0, 1});
    
    r->addIndex<2>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("prim"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("polyvariant_flow");
  if (r == 0) db->addRelation("polyvariant_flow", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("polyvariant_flow");
      std::vector<u16> ord109({0, 1});
    
    r->addIndex<2>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("polyvariant_flow"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("polymorphic_site");
  if (r == 0) db->addRelation("polymorphic_site", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("polymorphic_site");
      std::vector<u16> ord110({0});
    
    r->addIndex<1>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("polymorphic_site"), std::array<u16,1>{0}, b));
  r = db->getRelation("num");
  if (r == 0) db->addStruct("num", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("num");
      std::vector<u16> ord111({1, 0});
    
    r->addIndex<2>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord112({0, 1});
    
    r->addIndex<2>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("num"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord113({1, 2, 3, 0});
    
    r->addIndex<4>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord114({0, 1, 2, 3});
    
    r->addIndex<4>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("must_value");
  if (r == 0) db->addRelation("must_value", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("must_value");
      std::vector<u16> ord115({0, 1, 2});
    
    r->addIndex<3>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("must_value"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord116({1, 2, 0});
    
    r->addIndex<3>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord117({0, 1, 2});
    
    r->addIndex<3>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord118({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord119({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("monomorphic_site");
  if (r == 0) db->addRelation("monomorphic_site", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("monomorphic_site");
      std::vector<u16> ord120({0});
    
    r->addIndex<1>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("monomorphic_site"), std::array<u16,1>{0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord121({1, 2, 0});
    
    r->addIndex<3>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord122({0, 1, 2});
    
    r->addIndex<3>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mlimit");
  if (r == 0) db->addRelation("mlimit", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mlimit");
      std::vector<u16> ord123({0});
    
    r->addIndex<1>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("mlimit"), std::array<u16,1>{0}, b));
  r = db->getRelation("many_frames");
  if (r == 0) db->addRelation("many_frames", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("many_frames");
      std::vector<u16> ord124({0});
    
    r->addIndex<1>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("many_frames"), std::array<u16,1>{0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord125({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord126({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lst_take_ans");
  if (r == 0) db->addRelation("lst_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take_ans");
      std::vector<u16> ord127({0, 1});
    
    r->addIndex<2>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_take");
  if (r == 0) db->addStruct("lst_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take");
      std::vector<u16> ord128({1, 2, 0});
    
    r->addIndex<3>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord129({0, 1, 2});
    
    r->addIndex<3>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev_ans");
  if (r == 0) db->addRelation("lst_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_ans");
      std::vector<u16> ord130({0, 1});
    
    r->addIndex<2>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc_ans");
  if (r == 0) db->addRelation("lst_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc_ans");
      std::vector<u16> ord131({0, 1});
    
    r->addIndex<2>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc");
  if (r == 0) db->addStruct("lst_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc");
      std::vector<u16> ord132({1, 2, 0});
    
    r->addIndex<3>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord133({0, 1, 2});
    
    r->addIndex<3>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev");
  if (r == 0) db->addStruct("lst_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev");
      std::vector<u16> ord134({1, 0});
    
    r->addIndex<2>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord135({0, 1});
    
    r->addIndex<2>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_ref_ans");
  if (r == 0) db->addRelation("lst_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref_ans");
      std::vector<u16> ord136({0, 1});
    
    r->addIndex<2>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_ref");
  if (r == 0) db->addStruct("lst_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref");
      std::vector<u16> ord137({1, 2, 0});
    
    r->addIndex<3>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord138({0, 1, 2});
    
    r->addIndex<3>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_member_ans");
  if (r == 0) db->addRelation("lst_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member_ans");
      std::vector<u16> ord139({0, 1});
    
    r->addIndex<2>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_member");
  if (r == 0) db->addStruct("lst_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member");
      std::vector<u16> ord140({1, 2, 0});
    
    r->addIndex<3>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord141({0, 1, 2});
    
    r->addIndex<3>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_len_ans");
  if (r == 0) db->addRelation("lst_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len_ans");
      std::vector<u16> ord142({0, 1});
    
    r->addIndex<2>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_len");
  if (r == 0) db->addStruct("lst_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len");
      std::vector<u16> ord143({1, 0});
    
    r->addIndex<2>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord144({0, 1});
    
    r->addIndex<2>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_append_ans");
  if (r == 0) db->addRelation("lst_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append_ans");
      std::vector<u16> ord145({0, 1});
    
    r->addIndex<2>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_append");
  if (r == 0) db->addStruct("lst_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append");
      std::vector<u16> ord146({1, 2, 0});
    
    r->addIndex<3>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord147({0, 1, 2});
    
    r->addIndex<3>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_absent_ans");
  if (r == 0) db->addRelation("lst_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent_ans");
      std::vector<u16> ord148({0, 1});
    
    r->addIndex<2>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_absent");
  if (r == 0) db->addStruct("lst_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent");
      std::vector<u16> ord149({1, 2, 0});
    
    r->addIndex<3>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord150({0, 1, 2});
    
    r->addIndex<3>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lookup_ans");
  if (r == 0) db->addRelation("lookup_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lookup_ans");
      std::vector<u16> ord151({0, 1});
    
    r->addIndex<2>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lookup_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lookup");
  if (r == 0) db->addStruct("lookup", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lookup");
      std::vector<u16> ord152({1, 2, 0});
    
    r->addIndex<3>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord153({0, 1, 2});
    
    r->addIndex<3>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lookup"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("letrec");
  if (r == 0) db->addStruct("letrec", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("letrec");
      std::vector<u16> ord154({1, 2, 3, 0});
    
    r->addIndex<4>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord155({0, 1, 2, 3});
    
    r->addIndex<4>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("letrec"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("let");
  if (r == 0) db->addStruct("let", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("let");
      std::vector<u16> ord156({1, 2, 3, 0});
    
    r->addIndex<4>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord157({0, 1, 2, 3});
    
    r->addIndex<4>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("let"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("lambda");
  if (r == 0) db->addStruct("lambda", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lambda");
      std::vector<u16> ord158({1, 2, 0});
    
    r->addIndex<3>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord159({0, 1, 2});
    
    r->addIndex<3>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lambda"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord160({1, 2, 3, 0});
    
    r->addIndex<4>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord161({0, 1, 2, 3});
    
    r->addIndex<4>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("inlinable_call");
  if (r == 0) db->addRelation("inlinable_call", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("inlinable_call");
      std::vector<u16> ord162({0, 1});
    
    r->addIndex<2>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("inlinable_call"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("if");
  if (r == 0) db->addStruct("if", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("if");
      std::vector<u16> ord163({1, 2, 3, 0});
    
    r->addIndex<4>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord164({0, 1, 2, 3});
    
    r->addIndex<4>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("if"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("freevar_in_args");
  if (r == 0) db->addRelation("freevar_in_args", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("freevar_in_args");
      std::vector<u16> ord165({0, 1});
    
    r->addIndex<2>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("freevar_in_args"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("freevar");
  if (r == 0) db->addRelation("freevar", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("freevar");
      std::vector<u16> ord166({0, 1});
    
    r->addIndex<2>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("freevar"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("frame_count");
  if (r == 0) db->addRelation("frame_count", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("frame_count");
  r->setLattice(LAT_COUNT, false, 0, false, 0, "count", db->collections());
      std::vector<u16> ord167({0, 1});
    
    r->addMapIndex<2>(ord167);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<2>(db, r, std::array<u16,2>{0, 1}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<2>(db, db->getRelation("frame_count"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("flow_count");
  if (r == 0) db->addRelation("flow_count", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("flow_count");
  r->setLattice(LAT_COUNT, false, 0, false, 0, "count", db->collections());
      std::vector<u16> ord168({0, 1, 2});
    
    r->addMapIndex<3>(ord168);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<3>(db, db->getRelation("flow_count"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("eval_args_ans");
  if (r == 0) db->addRelation("eval_args_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_args_ans");
      std::vector<u16> ord169({0, 1});
    
    r->addIndex<2>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval_args_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("eval_args");
  if (r == 0) db->addStruct("eval_args", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_args");
      std::vector<u16> ord170({1, 2, 0});
    
    r->addIndex<3>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord171({0, 1, 2});
    
    r->addIndex<3>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("eval_args"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("eval_ans");
  if (r == 0) db->addRelation("eval_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_ans");
      std::vector<u16> ord172({0, 1});
    
    r->addIndex<2>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("eval");
  if (r == 0) db->addStruct("eval", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval");
      std::vector<u16> ord173({1, 2, 0});
    
    r->addIndex<3>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord174({0, 2, 1});
    
    r->addIndex<3>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("eval"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord175({0});
    
    r->addIndex<1>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord176({1, 2, 0});
    
    r->addIndex<3>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord177({0, 1, 2});
    
    r->addIndex<3>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("delta_ans");
  if (r == 0) db->addRelation("delta_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("delta_ans");
      std::vector<u16> ord178({0, 1});
    
    r->addIndex<2>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("delta_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("delta");
  if (r == 0) db->addStruct("delta", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("delta");
      std::vector<u16> ord179({1, 2, 0});
    
    r->addIndex<3>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord180({0, 1, 2});
    
    r->addIndex<3>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("delta"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("comparison_op");
  if (r == 0) db->addRelation("comparison_op", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("comparison_op");
      std::vector<u16> ord181({0});
    
    r->addIndex<1>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("comparison_op"), std::array<u16,1>{0}, b));
  r = db->getRelation("closure");
  if (r == 0) db->addStruct("closure", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("closure");
      std::vector<u16> ord182({1, 2, 0});
    
    r->addIndex<3>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord183({0, 1, 2});
    
    r->addIndex<3>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("closure"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("call_target");
  if (r == 0) db->addRelation("call_target", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("call_target");
      std::vector<u16> ord184({0, 1, 2, 3});
    
    r->addIndex<4>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("call_target"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("call_event");
  if (r == 0) db->addRelation("call_event", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("call_event");
      std::vector<u16> ord185({0, 1});
    
    r->addIndex<2>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("call_event"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("boolval");
  if (r == 0) db->addStruct("boolval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("boolval");
      std::vector<u16> ord186({1, 0});
    
    r->addIndex<2>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord187({0, 1});
    
    r->addIndex<2>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("boolval"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("boolean");
  if (r == 0) db->addStruct("boolean", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("boolean");
      std::vector<u16> ord188({1, 0});
    
    r->addIndex<2>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord189({0, 1});
    
    r->addIndex<2>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("boolean"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("binding_event");
  if (r == 0) db->addRelation("binding_event", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("binding_event");
      std::vector<u16> ord190({0, 1, 2});
    
    r->addIndex<3>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("binding_event"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("binding_count");
  if (r == 0) db->addRelation("binding_count", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("binding_count");
  r->setLattice(LAT_COUNT, false, 0, false, 0, "count", db->collections());
      std::vector<u16> ord191({0, 1, 2});
    
    r->addMapIndex<3>(ord191);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, b), true);
      std::vector<u16> ord192({2, 0, 1});
    
    r->addIndex<3>(ord192, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<3>(db, db->getRelation("binding_count"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("binding");
  if (r == 0) db->addRelation("binding", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("binding");
      std::vector<u16> ord193({0, 1, 2});
    
    r->addIndex<3>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("binding"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("bind_params");
  if (r == 0) db->addRelation("bind_params", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bind_params");
      std::vector<u16> ord194({0, 1, 2, 3});
    
    r->addIndex<4>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("bind_params"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("arithmetic_op");
  if (r == 0) db->addRelation("arithmetic_op", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("arithmetic_op");
      std::vector<u16> ord195({0});
    
    r->addIndex<1>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("arithmetic_op"), std::array<u16,1>{0}, b));
  r = db->getRelation("argument_list");
  if (r == 0) db->addRelation("argument_list", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("argument_list");
      std::vector<u16> ord196({0});
    
    r->addIndex<1>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("argument_list"), std::array<u16,1>{0}, b));
  r = db->getRelation("app");
  if (r == 0) db->addStruct("app", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("app");
      std::vector<u16> ord197({1, 2, 0});
    
    r->addIndex<3>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord198({0, 1, 2});
    
    r->addIndex<3>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("app"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("any_bool");
  if (r == 0) db->addRelation("any_bool", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("any_bool");
      std::vector<u16> ord199({0});
    
    r->addIndex<1>(ord199, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("any_bool"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord200({1, 0});
    
    r->addIndex<2>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord201({0, 1});
    
    r->addIndex<2>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup56712x93x0x0x0");
  if (r == 0) db->addRelation("$sup56712x93x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup56712x93x0x0x0");
      std::vector<u16> ord202({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord202, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup56712x93x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup56712x91x0x0x0");
  if (r == 0) db->addRelation("$sup56712x91x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup56712x91x0x0x0");
      std::vector<u16> ord203({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord203, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup56712x91x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup56712x86x0x0x0");
  if (r == 0) db->addRelation("$sup56712x86x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord204({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup56712x86x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup56712x74x0x0x0");
  if (r == 0) db->addRelation("$sup56712x74x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup56712x74x0x0x0");
      std::vector<u16> ord205({0, 1, 2, 3});
    
    r->addIndex<4>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup56712x74x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup56712x41x0x0x0");
  if (r == 0) db->addRelation("$sup56712x41x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup56712x41x0x0x0");
      std::vector<u16> ord206({0, 1, 2, 3});
    
    r->addIndex<4>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup56712x41x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup56712x37x0x0x0");
  if (r == 0) db->addRelation("$sup56712x37x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup56712x37x0x0x0");
      std::vector<u16> ord207({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup56712x37x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$seq_atr");
  if (r == 0) db->addRelation("$seq_atr", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_atr");
      std::vector<u16> ord208({0, 1, 2});
    
    r->addIndex<3>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_atr"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord209({0, 1, 2});
    
    r->addIndex<3>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("app"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("argument_list"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0, 1, 2, 3});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("bind_params"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("binding"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1, 2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("binding_event"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0, 1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("call_event"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1, 3});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("call_target"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("closure"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("delta"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("eval"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1, 2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("eval_args"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("eval_args_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("freevar_in_args"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lambda"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lookup"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_absent"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1, 2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_append"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_append_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_len"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_member"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_ref"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_rev"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1, 2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_rev_acc"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_rev_acc_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_rev_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_take"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_take_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("many_frames"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("must_value"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("polyvariant_flow"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("singleton_flow"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("summarized_binding"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("tick"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("tick_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("unique_binding"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre (let __t5ZC163 (inf))) (probe binding_count (2 0 1) 1 __t5ZC163 x l) (body) (head (emit summarized_binding (0 1) x l)) counting.slog:35 #f)
  class ReadTask0 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("summarized_binding");
      std::vector<u16> ord1({0, 1});
      slog::Relation* readrel2 = db->getRelation("summarized_binding");
      head_index[0] = readrel2->getIndex(ord1, false);
      std::vector<u16> ord3({2, 0, 1});
      slog::Relation* readrel4 = db->getRelation("binding_count");
      driver_index = readrel4->getIndex(ord3, true);
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = _prim_inf(db);
      if (v_c0 == slog_error) { slog::emit_pending_error(db, "counting.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c0, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m5) {
        u64 v_c1 = m5[1];
        u64 v_c2 = m5[2];
        if (buckethash(v_c1) != bucket) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:35", "all:binding_count", _fires);
  
      if (!_done)
      {
        ReadTask0* _cont = new ReadTask0(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  // (crule (pre) (scan temp8IBL1233 __t1EbX382 site) (body) (head (emit-lat target_count site __t1EbX382)) analysis.slog:25 #f)
  class ReadTask6 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("target_count");
      outer_rel = db->getRelation("temp8IBL1233");
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        u64 v_c4 = _t[1];
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:25", "delta:temp8IBL1233", _fires);
  
      if (!_done)
      {
        ReadTask6* _cont = new ReadTask6(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask6(db,b), false);
  // (crule (pre) (scan temp6Qm11234 __t5iRc62 site) (body) (head (emit-lat target_count site __t5iRc62)) analysis.slog:24 #f)
  class ReadTask7 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("target_count");
      outer_rel = db->getRelation("temp6Qm11234");
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c4 = _t[1];
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c5});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:24", "delta:temp6Qm11234", _fires);
  
      if (!_done)
      {
        ReadTask7* _cont = new ReadTask7(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask7(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre0ss81225 __errf5PwW1226 __errf0J8f1227 __errf6T8H1228 __errf7btN1229) (body) (head (emit error (0) __erre0ss81225)) <internal>:1 #f)
  class ReadTask8 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord9({0});
      slog::Relation* readrel10 = db->getRelation("error");
      head_index[0] = readrel10->getIndex(ord9, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c9 = _t[3];
        u64 v_c10 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c6}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask8* _cont = new ReadTask8(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask8(db,b), false);
  // (crule (pre) (scan int_overflow __erre7faE1209 __errf3ADV1210 __errf1K101211 __errf5Rbc1212) (body) (head (emit error (0) __erre7faE1209)) <internal>:1 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord12({0});
      slog::Relation* readrel13 = db->getRelation("error");
      head_index[0] = readrel13->getIndex(ord12, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c11}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask11* _cont = new ReadTask11(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask11(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre3GN21230 __errf6wlH1231 __errf3PGQ1232) (body) (head (emit error (0) __erre3GN21230)) <internal>:1 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord15({0});
      slog::Relation* readrel16 = db->getRelation("error");
      head_index[0] = readrel16->getIndex(ord15, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c15 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c15}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask14* _cont = new ReadTask14(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask14(db,b), false);
  // (crule (pre (let __t1EbX382 (inf))) (scan site_targets site lam2) (body (join site_targets (0 1) 1 site lam1) (neq lam1 lam2)) (head (emit-temp temp8IBL1233 __t1EbX382 site)) analysis.slog:25 #f)
  class ReadTask18 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** site_targetsindex17;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8IBL1233");
      outer_rel = db->getRelation("site_targets");
      std::vector<u16> ord19({0, 1});
      slog::Relation* readrel20 = db->getRelation("site_targets");
      site_targetsindex17 = readrel20->getIndex(ord19, false);
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = _prim_inf(db);
      if (v_c3 == slog_error) { slog::emit_pending_error(db, "analysis.slog:25"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c4 = _t[0];
        u64 v_c18 = _t[1];
        slog::join_probe<2,1>(site_targetsindex17, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m21) {
          u64 v_c19 = m21[1];
          if (v_c19 == v_c18) return;
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:25", "all:site_targets", _fires);
  
      if (!_done)
      {
        ReadTask18* _cont = new ReadTask18(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask18(db,b), true);
  // (crule (pre (let __t4yPM54 (one))) (scan eval_ans __t6VfU53 vc) (body (join-lat frame_count (0 1) 0 c latchk_0) (eq __t4yPM54 latchk_0) (join eval (0 2 1) 2 __t6VfU53 c __t4VrF52) (join lambda (0 1 2) 1 __t4VrF52 xs eb)) (head (emit unique_closure (0) vc)) counting.slog:50 #f)
  class ReadTask25 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** frame_countindex22;  slog::Index** evalindex23;  slog::Index** lambdaindex24;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("unique_closure");
      std::vector<u16> ord26({0});
      slog::Relation* readrel27 = db->getRelation("unique_closure");
      head_index[0] = readrel27->getIndex(ord26, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("frame_count");
      frame_countindex22 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 2, 1});
      slog::Relation* readrel31 = db->getRelation("eval");
      evalindex23 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1, 2});
      slog::Relation* readrel33 = db->getRelation("lambda");
      lambdaindex24 = readrel33->getIndex(ord32, false);
  
    }
    ReadTask25(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = _prim_one(db);
      if (v_c20 == slog_error) { slog::emit_pending_error(db, "counting.slog:50"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_all_lat<1>(frame_countindex22, [&](const std::array<u64,1>& m34, u64 val35) {
          u64 v_c23 = m34[0]; u64 v_c24 = val35;
          if (v_c20 != v_c24) return;
          slog::join_probe<3,2>(evalindex23, std::array<u64,3>{v_c21, v_c23, 0}, [&](const std::array<u64,3>& m36) {
            u64 v_c25 = m36[2];
            slog::join_probe<3,1>(lambdaindex24, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m37) {
              u64 v_c26 = m37[1]; u64 v_c27 = m37[2];
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c22}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:50", "all:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask25* _cont = new ReadTask25(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask25(db,b), true);
  // (crule (pre) (scan nan_result __erre9jsq1213 __errf8mB81214 __errf2WVZ1215 __errf3iWF1216) (body) (head (emit error (0) __erre9jsq1213)) <internal>:1 #f)
  class ReadTask38 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord39({0});
      slog::Relation* readrel40 = db->getRelation("error");
      head_index[0] = readrel40->getIndex(ord39, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask38(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c28 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c30 = _t[2];
        u64 v_c31 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c28}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask38* _cont = new ReadTask38(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask38(db,b), false);
  // (crule (pre (let __t1pNF211 (one))) (probe binding_count (2 0 1) 1 __t1pNF211 x l) (body) (head (emit unique_binding (0 1) x l)) counting.slog:34 #f)
  class ReadTask41 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("unique_binding");
      std::vector<u16> ord42({0, 1});
      slog::Relation* readrel43 = db->getRelation("unique_binding");
      head_index[0] = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({2, 0, 1});
      slog::Relation* readrel45 = db->getRelation("binding_count");
      driver_index = readrel45->getIndex(ord44, true);
  
    }
    ReadTask41(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c32 = _prim_one(db);
      if (v_c32 == slog_error) { slog::emit_pending_error(db, "counting.slog:34"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c32, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m46) {
        u64 v_c1 = m46[1];
        u64 v_c2 = m46[2];
        if (buckethash(v_c1) != bucket) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:34", "all:binding_count", _fires);
  
      if (!_done)
      {
        ReadTask41* _cont = new ReadTask41(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask41(db,b), true);
  // (crule (pre) (scan type_mismatch __erre1wP41220 __errf6tQw1221 __errf4O1x1222 __errf0Kxx1223 __errf1Pof1224) (body) (head (emit error (0) __erre1wP41220)) <internal>:1 #f)
  class ReadTask47 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord48({0});
      slog::Relation* readrel49 = db->getRelation("error");
      head_index[0] = readrel49->getIndex(ord48, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask47(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c33 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c35 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c37 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c33}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask47* _cont = new ReadTask47(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask47(db,b), false);
  // (crule (pre) (scan div_by_zero __erre13GM1203 __errf6DUN1204 __errf81Mo1205) (body) (head (emit error (0) __erre13GM1203)) <internal>:1 #f)
  class ReadTask50 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord51({0});
      slog::Relation* readrel52 = db->getRelation("error");
      head_index[0] = readrel52->getIndex(ord51, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask50(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c39 = _t[1];
        u64 v_c40 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c38}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask50* _cont = new ReadTask50(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask50(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre0fdh1206 __errf0p201207 __errf1z5a1208) (body) (head (emit error (0) __erre0fdh1206)) <internal>:1 #f)
  class ReadTask53 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord54({0});
      slog::Relation* readrel55 = db->getRelation("error");
      head_index[0] = readrel55->getIndex(ord54, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask53(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c41 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c43 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c41}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask53* _cont = new ReadTask53(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask53(db,b), false);
  // (crule (pre (let __t5vIt298 (inf))) (scan eval_ans __t1ekA297 vc) (body (join-lat frame_count (0 1) 0 c latchk_0) (eq __t5vIt298 latchk_0) (join eval (0 2 1) 2 __t1ekA297 c __t7EL1296) (join lambda (0 1 2) 1 __t7EL1296 xs eb)) (head (emit summarized_closure (0) vc)) counting.slog:51 #f)
  class ReadTask59 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** frame_countindex56;  slog::Index** evalindex57;  slog::Index** lambdaindex58;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("summarized_closure");
      std::vector<u16> ord60({0});
      slog::Relation* readrel61 = db->getRelation("summarized_closure");
      head_index[0] = readrel61->getIndex(ord60, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("frame_count");
      frame_countindex56 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({0, 2, 1});
      slog::Relation* readrel65 = db->getRelation("eval");
      evalindex57 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({0, 1, 2});
      slog::Relation* readrel67 = db->getRelation("lambda");
      lambdaindex58 = readrel67->getIndex(ord66, false);
  
    }
    ReadTask59(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = _prim_inf(db);
      if (v_c44 == slog_error) { slog::emit_pending_error(db, "counting.slog:51"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c45 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_all_lat<1>(frame_countindex56, [&](const std::array<u64,1>& m68, u64 val69) {
          u64 v_c23 = m68[0]; u64 v_c24 = val69;
          if (v_c44 != v_c24) return;
          slog::join_probe<3,2>(evalindex57, std::array<u64,3>{v_c45, v_c23, 0}, [&](const std::array<u64,3>& m70) {
            u64 v_c46 = m70[2];
            slog::join_probe<3,1>(lambdaindex58, std::array<u64,3>{v_c46, 0, 0}, [&](const std::array<u64,3>& m71) {
              u64 v_c26 = m71[1]; u64 v_c27 = m71[2];
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c22}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:51", "all:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask59* _cont = new ReadTask59(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask59(db,b), true);
  // (crule (pre (let __t5iRc62 (one))) (scan site_targets site lam) (body) (head (emit-temp temp6Qm11234 __t5iRc62 site)) analysis.slog:24 #f)
  class ReadTask72 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6Qm11234");
      outer_rel = db->getRelation("site_targets");
  
    }
    ReadTask72(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = _prim_one(db);
      if (v_c5 == slog_error) { slog::emit_pending_error(db, "analysis.slog:24"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c4 = _t[0];
        u64 v_c47 = _t[1];
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:24", "all:site_targets", _fires);
  
      if (!_done)
      {
        ReadTask72* _cont = new ReadTask72(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask72(db,b), true);
  // (crule (pre) (scan toint_range __erre9AP41217 __errf69UN1218 __errf3gKN1219) (body) (head (emit error (0) __erre9AP41217)) <internal>:1 #f)
  class ReadTask73 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord74({0});
      slog::Relation* readrel75 = db->getRelation("error");
      head_index[0] = readrel75->getIndex(ord74, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask73(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c48 = _t[0];
        u64 v_c49 = _t[1];
        u64 v_c50 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c48}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask73* _cont = new ReadTask73(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask73(db,b), false);
  s->addReadRel("binding_count");
  s->addReadRel("div_by_zero");
  s->addReadRel("eval");
  s->addReadRel("eval_ans");
  s->addReadRel("frame_count");
  s->addReadRel("int_overflow");
  s->addReadRel("lambda");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("site_targets");
  s->addReadRel("temp6Qm11234");
  s->addReadRel("temp8IBL1233");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$seq_atr");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("summarized_binding");
  s->addDynamicRel("summarized_closure");
  s->addDynamicRel("target_count");
  s->addDynamicRel("temp6Qm11234");
  s->addDynamicRel("temp8IBL1233");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addDynamicRel("unique_binding");
  s->addDynamicRel("unique_closure");
  d->push(s);
  d->continueRun();
}

