
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_constd01925b37634a1a9d24159d8;
u64 v_constf7d5dda68c5473f68197d2e7;
u64 v_const6e5ee07e63cdbc3ea07dd8a9;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("c129da3c");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_constd01925b37634a1a9d24159d8 = db->encodeString("mempty");
  v_constf7d5dda68c5473f68197d2e7 = db->encodeString("mp_size");
  v_const6e5ee07e63cdbc3ea07dd8a9 = db->encodeString("map.slog:122");
  r = db->getRelation("unique_closure");
  if (r == 0) db->addRelation("unique_closure", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("unique_closure");
      std::vector<u16> ord97({0});
    
    r->addIndex<1>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("unique_closure"), std::array<u16,1>{0}, b));
  r = db->getRelation("unique_binding");
  if (r == 0) db->addRelation("unique_binding", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("unique_binding");
      std::vector<u16> ord98({0, 1});
    
    r->addIndex<2>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("unique_binding"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord99({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord100({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord101({1, 2, 0});
    
    r->addIndex<3>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord102({0, 1, 2});
    
    r->addIndex<3>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("tick_ans");
  if (r == 0) db->addRelation("tick_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tick_ans");
      std::vector<u16> ord103({0, 1});
    
    r->addIndex<2>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("tick_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("tick");
  if (r == 0) db->addStruct("tick", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tick");
      std::vector<u16> ord104({1, 2, 0});
    
    r->addIndex<3>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord105({0, 1, 2});
    
    r->addIndex<3>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("tick"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp3tRZ2146");
  if (r == 0) db->addTempRelation("temp3tRZ2146", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp29Jt2147");
  if (r == 0) db->addTempRelation("temp29Jt2147", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("symval");
  if (r == 0) db->addStruct("symval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("symval");
      std::vector<u16> ord106({1, 0});
    
    r->addIndex<2>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord107({0, 1});
    
    r->addIndex<2>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("symval"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("sym");
  if (r == 0) db->addStruct("sym", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("sym");
      std::vector<u16> ord108({1, 0});
    
    r->addIndex<2>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord109({0, 1});
    
    r->addIndex<2>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("sym"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("summarized_closure");
  if (r == 0) db->addRelation("summarized_closure", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("summarized_closure");
      std::vector<u16> ord110({0});
    
    r->addIndex<1>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("summarized_closure"), std::array<u16,1>{0}, b));
  r = db->getRelation("summarized_binding");
  if (r == 0) db->addRelation("summarized_binding", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("summarized_binding");
      std::vector<u16> ord111({0, 1});
    
    r->addIndex<2>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("summarized_binding"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("store");
  if (r == 0) db->addRelation("store", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("store");
      std::vector<u16> ord112({0, 1, 2});
    
    r->addIndex<3>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("store"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord113({1, 2, 0});
    
    r->addIndex<3>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord114({0, 1, 2});
    
    r->addIndex<3>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("singleton_flow");
  if (r == 0) db->addRelation("singleton_flow", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("singleton_flow");
      std::vector<u16> ord115({0, 1});
    
    r->addIndex<2>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("singleton_flow"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("select_branch_ans");
  if (r == 0) db->addRelation("select_branch_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("select_branch_ans");
      std::vector<u16> ord116({0, 1});
    
    r->addIndex<2>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("select_branch_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("select_branch");
  if (r == 0) db->addStruct("select_branch", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("select_branch");
      std::vector<u16> ord117({1, 2, 3, 0});
    
    r->addIndex<4>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord118({0, 1, 2, 3});
    
    r->addIndex<4>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("select_branch"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("scheme_false");
  if (r == 0) db->addRelation("scheme_false", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("scheme_false");
      std::vector<u16> ord119({0});
    
    r->addIndex<1>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("scheme_false"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord120({1, 0});
    
    r->addIndex<2>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord121({0, 1});
    
    r->addIndex<2>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("reachable_expr");
  if (r == 0) db->addRelation("reachable_expr", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("reachable_expr");
      std::vector<u16> ord122({0});
    
    r->addIndex<1>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("reachable_expr"), std::array<u16,1>{0}, b));
  r = db->getRelation("program_result");
  if (r == 0) db->addRelation("program_result", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program_result");
      std::vector<u16> ord123({0});
    
    r->addIndex<1>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program_result"), std::array<u16,1>{0}, b));
  r = db->getRelation("program");
  if (r == 0) db->addRelation("program", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program");
      std::vector<u16> ord124({0});
    
    r->addIndex<1>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program"), std::array<u16,1>{0}, b));
  r = db->getRelation("primref");
  if (r == 0) db->addStruct("primref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("primref");
      std::vector<u16> ord125({1, 0});
    
    r->addIndex<2>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord126({0, 1});
    
    r->addIndex<2>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("primref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("primitive");
  if (r == 0) db->addRelation("primitive", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("primitive");
      std::vector<u16> ord127({0});
    
    r->addIndex<1>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("primitive"), std::array<u16,1>{0}, b));
  r = db->getRelation("prim");
  if (r == 0) db->addStruct("prim", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("prim");
      std::vector<u16> ord128({1, 0});
    
    r->addIndex<2>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord129({0, 1});
    
    r->addIndex<2>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("prim"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("polyvariant_flow");
  if (r == 0) db->addRelation("polyvariant_flow", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("polyvariant_flow");
      std::vector<u16> ord130({0, 1});
    
    r->addIndex<2>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("polyvariant_flow"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("num");
  if (r == 0) db->addStruct("num", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("num");
      std::vector<u16> ord131({1, 0});
    
    r->addIndex<2>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord132({0, 1});
    
    r->addIndex<2>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("num"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord133({1, 2, 3, 0});
    
    r->addIndex<4>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord134({0, 1, 2, 3});
    
    r->addIndex<4>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("must_value");
  if (r == 0) db->addRelation("must_value", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("must_value");
      std::vector<u16> ord135({0, 1, 2});
    
    r->addIndex<3>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("must_value"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord136({1, 2, 0});
    
    r->addIndex<3>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord137({0, 1, 2});
    
    r->addIndex<3>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord138({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord139({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_union_ans");
  if (r == 0) db->addRelation("mp_union_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union_ans");
      std::vector<u16> ord140({0, 1});
    
    r->addIndex<2>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_union_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_union");
  if (r == 0) db->addStruct("mp_union", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union");
      std::vector<u16> ord141({1, 2, 0});
    
    r->addIndex<3>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord142({0, 1, 2});
    
    r->addIndex<3>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_union"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_size_ans");
  if (r == 0) db->addRelation("mp_size_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size_ans");
      std::vector<u16> ord143({0, 1});
    
    r->addIndex<2>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_size_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_size");
  if (r == 0) db->addStruct("mp_size", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size");
      std::vector<u16> ord144({1, 0});
    
    r->addIndex<2>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord145({0, 1});
    
    r->addIndex<2>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_size"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_put_soft_ans");
  if (r == 0) db->addRelation("mp_put_soft_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord146({0, 1});
    
    r->addIndex<2>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_soft_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put_soft");
  if (r == 0) db->addStruct("mp_put_soft", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft");
      std::vector<u16> ord147({1, 2, 3, 0});
    
    r->addIndex<4>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord148({0, 1, 2, 3});
    
    r->addIndex<4>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put_soft"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_put_ans");
  if (r == 0) db->addRelation("mp_put_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_ans");
      std::vector<u16> ord149({0, 1});
    
    r->addIndex<2>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put");
  if (r == 0) db->addStruct("mp_put", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put");
      std::vector<u16> ord150({1, 2, 3, 0});
    
    r->addIndex<4>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord151({0, 1, 2, 3});
    
    r->addIndex<4>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_msk_ans");
  if (r == 0) db->addRelation("mp_msk_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk_ans");
      std::vector<u16> ord152({0, 1});
    
    r->addIndex<2>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_msk_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_msk");
  if (r == 0) db->addStruct("mp_msk", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk");
      std::vector<u16> ord153({1, 2, 0});
    
    r->addIndex<3>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord154({0, 1, 2});
    
    r->addIndex<3>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_msk"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_join_ans");
  if (r == 0) db->addRelation("mp_join_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join_ans");
      std::vector<u16> ord155({0, 1});
    
    r->addIndex<2>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_join_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_join");
  if (r == 0) db->addStruct("mp_join", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join");
      std::vector<u16> ord156({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord157({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_join"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_hsb_ans");
  if (r == 0) db->addRelation("mp_hsb_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord158({0, 1});
    
    r->addIndex<2>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_hsb_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_hsb");
  if (r == 0) db->addStruct("mp_hsb", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb");
      std::vector<u16> ord159({1, 0});
    
    r->addIndex<2>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord160({0, 1});
    
    r->addIndex<2>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_hsb"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_has0_ans");
  if (r == 0) db->addRelation("mp_has0_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0_ans");
      std::vector<u16> ord161({0, 1});
    
    r->addIndex<2>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_has0_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_has0");
  if (r == 0) db->addStruct("mp_has0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0");
      std::vector<u16> ord162({1, 2, 0});
    
    r->addIndex<3>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord163({0, 1, 2});
    
    r->addIndex<3>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_has0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_get_ans");
  if (r == 0) db->addRelation("mp_get_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get_ans");
      std::vector<u16> ord164({0, 1});
    
    r->addIndex<2>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_get_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_get");
  if (r == 0) db->addStruct("mp_get", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get");
      std::vector<u16> ord165({1, 2, 0});
    
    r->addIndex<3>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord166({0, 1, 2});
    
    r->addIndex<3>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_get"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_fromlist_ans");
  if (r == 0) db->addRelation("mp_fromlist_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord167({0, 1});
    
    r->addIndex<2>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_fromlist_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_fromlist");
  if (r == 0) db->addStruct("mp_fromlist", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist");
      std::vector<u16> ord168({1, 0});
    
    r->addIndex<2>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord169({0, 1});
    
    r->addIndex<2>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_fromlist"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_del_ans");
  if (r == 0) db->addRelation("mp_del_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del_ans");
      std::vector<u16> ord170({0, 1});
    
    r->addIndex<2>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_del_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_del");
  if (r == 0) db->addStruct("mp_del", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del");
      std::vector<u16> ord171({1, 2, 0});
    
    r->addIndex<3>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord172({0, 1, 2});
    
    r->addIndex<3>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_del"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_bld_ans");
  if (r == 0) db->addRelation("mp_bld_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld_ans");
      std::vector<u16> ord173({0, 1});
    
    r->addIndex<2>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_bld_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_bld");
  if (r == 0) db->addStruct("mp_bld", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld");
      std::vector<u16> ord174({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord175({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_bld"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord176({1, 2, 0});
    
    r->addIndex<3>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord177({0, 1, 2});
    
    r->addIndex<3>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mleaf");
  if (r == 0) db->addStruct("mleaf", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mleaf");
      std::vector<u16> ord178({1, 2, 0});
    
    r->addIndex<3>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord179({0, 1, 2});
    
    r->addIndex<3>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mleaf"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mbranch");
  if (r == 0) db->addStruct("mbranch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mbranch");
      std::vector<u16> ord180({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord181({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mbranch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("many_frames");
  if (r == 0) db->addRelation("many_frames", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("many_frames");
      std::vector<u16> ord182({0});
    
    r->addIndex<1>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("many_frames"), std::array<u16,1>{0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord183({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord184({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lst_take_ans");
  if (r == 0) db->addRelation("lst_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take_ans");
      std::vector<u16> ord185({0, 1});
    
    r->addIndex<2>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_take");
  if (r == 0) db->addStruct("lst_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take");
      std::vector<u16> ord186({1, 2, 0});
    
    r->addIndex<3>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord187({0, 1, 2});
    
    r->addIndex<3>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev_ans");
  if (r == 0) db->addRelation("lst_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_ans");
      std::vector<u16> ord188({0, 1});
    
    r->addIndex<2>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc_ans");
  if (r == 0) db->addRelation("lst_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc_ans");
      std::vector<u16> ord189({0, 1});
    
    r->addIndex<2>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc");
  if (r == 0) db->addStruct("lst_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc");
      std::vector<u16> ord190({1, 2, 0});
    
    r->addIndex<3>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord191({0, 1, 2});
    
    r->addIndex<3>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev");
  if (r == 0) db->addStruct("lst_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev");
      std::vector<u16> ord192({1, 0});
    
    r->addIndex<2>(ord192, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord193({0, 1});
    
    r->addIndex<2>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_ref_ans");
  if (r == 0) db->addRelation("lst_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref_ans");
      std::vector<u16> ord194({0, 1});
    
    r->addIndex<2>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_ref");
  if (r == 0) db->addStruct("lst_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref");
      std::vector<u16> ord195({1, 2, 0});
    
    r->addIndex<3>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord196({0, 1, 2});
    
    r->addIndex<3>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_member_ans");
  if (r == 0) db->addRelation("lst_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member_ans");
      std::vector<u16> ord197({0, 1});
    
    r->addIndex<2>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_member");
  if (r == 0) db->addStruct("lst_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member");
      std::vector<u16> ord198({1, 2, 0});
    
    r->addIndex<3>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord199({0, 1, 2});
    
    r->addIndex<3>(ord199, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_len_ans");
  if (r == 0) db->addRelation("lst_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len_ans");
      std::vector<u16> ord200({0, 1});
    
    r->addIndex<2>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_len");
  if (r == 0) db->addStruct("lst_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len");
      std::vector<u16> ord201({1, 0});
    
    r->addIndex<2>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord202({0, 1});
    
    r->addIndex<2>(ord202, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_append_ans");
  if (r == 0) db->addRelation("lst_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append_ans");
      std::vector<u16> ord203({0, 1});
    
    r->addIndex<2>(ord203, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_append");
  if (r == 0) db->addStruct("lst_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append");
      std::vector<u16> ord204({1, 2, 0});
    
    r->addIndex<3>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord205({0, 1, 2});
    
    r->addIndex<3>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_absent_ans");
  if (r == 0) db->addRelation("lst_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent_ans");
      std::vector<u16> ord206({0, 1});
    
    r->addIndex<2>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_absent");
  if (r == 0) db->addStruct("lst_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent");
      std::vector<u16> ord207({1, 2, 0});
    
    r->addIndex<3>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord208({0, 1, 2});
    
    r->addIndex<3>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lookup_ans");
  if (r == 0) db->addRelation("lookup_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lookup_ans");
      std::vector<u16> ord209({0, 1});
    
    r->addIndex<2>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lookup_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lookup");
  if (r == 0) db->addStruct("lookup", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lookup");
      std::vector<u16> ord210({1, 2, 0});
    
    r->addIndex<3>(ord210, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord211({0, 1, 2});
    
    r->addIndex<3>(ord211, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lookup"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("letrec");
  if (r == 0) db->addStruct("letrec", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("letrec");
      std::vector<u16> ord212({1, 2, 3, 0});
    
    r->addIndex<4>(ord212, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord213({0, 1, 2, 3});
    
    r->addIndex<4>(ord213, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("letrec"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("let");
  if (r == 0) db->addStruct("let", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("let");
      std::vector<u16> ord214({1, 2, 3, 0});
    
    r->addIndex<4>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord215({0, 1, 2, 3});
    
    r->addIndex<4>(ord215, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("let"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("lambda");
  if (r == 0) db->addStruct("lambda", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lambda");
      std::vector<u16> ord216({1, 2, 0});
    
    r->addIndex<3>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord217({0, 1, 2});
    
    r->addIndex<3>(ord217, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lambda"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("klimit");
  if (r == 0) db->addRelation("klimit", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("klimit");
      std::vector<u16> ord218({0});
    
    r->addIndex<1>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("klimit"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord219({1, 2, 3, 0});
    
    r->addIndex<4>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord220({0, 1, 2, 3});
    
    r->addIndex<4>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("if");
  if (r == 0) db->addStruct("if", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("if");
      std::vector<u16> ord221({1, 2, 3, 0});
    
    r->addIndex<4>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord222({0, 1, 2, 3});
    
    r->addIndex<4>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("if"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("frame_count");
  if (r == 0) db->addRelation("frame_count", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("frame_count");
  r->setLattice(LAT_COUNT, false, 0, false, 0, "count", db->collections());
      std::vector<u16> ord223({0, 1});
    
    r->addMapIndex<2>(ord223);
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
      std::vector<u16> ord224({0, 1, 2});
    
    r->addMapIndex<3>(ord224);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<3>(db, db->getRelation("flow_count"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("extend_env_ans");
  if (r == 0) db->addRelation("extend_env_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("extend_env_ans");
      std::vector<u16> ord225({0, 1});
    
    r->addIndex<2>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("extend_env_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("extend_env");
  if (r == 0) db->addStruct("extend_env", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("extend_env");
      std::vector<u16> ord226({1, 2, 3, 0});
    
    r->addIndex<4>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord227({0, 1, 2, 3});
    
    r->addIndex<4>(ord227, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("extend_env"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("eval_args_ans");
  if (r == 0) db->addRelation("eval_args_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_args_ans");
      std::vector<u16> ord228({0, 1});
    
    r->addIndex<2>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval_args_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("eval_args");
  if (r == 0) db->addStruct("eval_args", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_args");
      std::vector<u16> ord229({1, 2, 3, 0});
    
    r->addIndex<4>(ord229, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord230({0, 1, 2, 3});
    
    r->addIndex<4>(ord230, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("eval_args"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("eval_ans");
  if (r == 0) db->addRelation("eval_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_ans");
      std::vector<u16> ord231({0, 1});
    
    r->addIndex<2>(ord231, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("eval");
  if (r == 0) db->addStruct("eval", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval");
      std::vector<u16> ord232({2, 1, 3, 0});
    
    r->addIndex<4>(ord232, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 1, 3, 0}, false, b), true);
      std::vector<u16> ord233({0, 1, 2, 3});
    
    r->addIndex<4>(ord233, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("eval"), std::array<u16,4>{2, 1, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord234({0});
    
    r->addIndex<1>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord235({1, 2, 0});
    
    r->addIndex<3>(ord235, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord236({0, 1, 2});
    
    r->addIndex<3>(ord236, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("delta_ans");
  if (r == 0) db->addRelation("delta_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("delta_ans");
      std::vector<u16> ord237({0, 1});
    
    r->addIndex<2>(ord237, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("delta_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("delta");
  if (r == 0) db->addStruct("delta", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("delta");
      std::vector<u16> ord238({1, 2, 0});
    
    r->addIndex<3>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord239({0, 1, 2});
    
    r->addIndex<3>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("delta"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("comparison_op");
  if (r == 0) db->addRelation("comparison_op", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("comparison_op");
      std::vector<u16> ord240({0});
    
    r->addIndex<1>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("comparison_op"), std::array<u16,1>{0}, b));
  r = db->getRelation("closure_count");
  if (r == 0) db->addRelation("closure_count", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("closure_count");
  r->setLattice(LAT_COUNT, false, 0, false, 0, "count", db->collections());
      std::vector<u16> ord241({0, 1});
    
    r->addMapIndex<2>(ord241);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<2>(db, r, std::array<u16,2>{0, 1}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<2>(db, db->getRelation("closure_count"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("closure_birth");
  if (r == 0) db->addRelation("closure_birth", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("closure_birth");
      std::vector<u16> ord242({0, 1});
    
    r->addIndex<2>(ord242, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("closure_birth"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("closure");
  if (r == 0) db->addStruct("closure", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("closure");
      std::vector<u16> ord243({1, 2, 0});
    
    r->addIndex<3>(ord243, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord244({0, 1, 2});
    
    r->addIndex<3>(ord244, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("closure"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("call_event");
  if (r == 0) db->addRelation("call_event", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("call_event");
      std::vector<u16> ord245({0, 1});
    
    r->addIndex<2>(ord245, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord246({1, 0});
    
    r->addIndex<2>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("call_event"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("boolval");
  if (r == 0) db->addStruct("boolval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("boolval");
      std::vector<u16> ord247({1, 0});
    
    r->addIndex<2>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord248({0, 1});
    
    r->addIndex<2>(ord248, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("boolval"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("boolean");
  if (r == 0) db->addStruct("boolean", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("boolean");
      std::vector<u16> ord249({1, 0});
    
    r->addIndex<2>(ord249, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord250({0, 1});
    
    r->addIndex<2>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("boolean"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("binding_event");
  if (r == 0) db->addRelation("binding_event", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("binding_event");
      std::vector<u16> ord251({0, 1, 2});
    
    r->addIndex<3>(ord251, false);
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
      std::vector<u16> ord252({0, 1, 2});
    
    r->addMapIndex<3>(ord252);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<3>(db, db->getRelation("binding_count"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("bind_store");
  if (r == 0) db->addRelation("bind_store", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bind_store");
      std::vector<u16> ord253({0, 1, 2, 3});
    
    r->addIndex<4>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("bind_store"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("arithmetic_op");
  if (r == 0) db->addRelation("arithmetic_op", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("arithmetic_op");
      std::vector<u16> ord254({0});
    
    r->addIndex<1>(ord254, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("arithmetic_op"), std::array<u16,1>{0}, b));
  r = db->getRelation("app");
  if (r == 0) db->addStruct("app", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("app");
      std::vector<u16> ord255({1, 2, 0});
    
    r->addIndex<3>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord256({0, 1, 2});
    
    r->addIndex<3>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("app"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("any_bool");
  if (r == 0) db->addRelation("any_bool", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("any_bool");
      std::vector<u16> ord257({0});
    
    r->addIndex<1>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("any_bool"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord258({1, 0});
    
    r->addIndex<2>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord259({0, 1});
    
    r->addIndex<2>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord260({1, 0});
    
    r->addIndex<2>(ord260, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup70016x95x0x0x1");
  if (r == 0) db->addRelation("$sup70016x95x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x95x0x0x1");
      std::vector<u16> ord261({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord261, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup70016x95x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup70016x95x0x0x0");
  if (r == 0) db->addRelation("$sup70016x95x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x95x0x0x0");
      std::vector<u16> ord262({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x95x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x92x0x0x1");
  if (r == 0) db->addRelation("$sup70016x92x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x92x0x0x1");
      std::vector<u16> ord263({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup70016x92x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup70016x92x0x0x0");
  if (r == 0) db->addRelation("$sup70016x92x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x92x0x0x0");
      std::vector<u16> ord264({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x92x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x87x0x0x0");
  if (r == 0) db->addRelation("$sup70016x87x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x87x0x0x0");
      std::vector<u16> ord265({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x87x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x75x0x0x0");
  if (r == 0) db->addRelation("$sup70016x75x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x75x0x0x0");
      std::vector<u16> ord266({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord266, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup70016x75x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup70016x51x0x0x1");
  if (r == 0) db->addRelation("$sup70016x51x0x0x1", 13);
  else if (r->getArity() != 13)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord267({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    
    r->addIndex<13>(ord267, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<13>(db, r, std::array<u16,13>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<13>(db, db->getRelation("$sup70016x51x0x0x1"), std::array<u16,13>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, b));
  r = db->getRelation("$sup70016x51x0x0x0");
  if (r == 0) db->addRelation("$sup70016x51x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x51x0x0x0");
      std::vector<u16> ord268({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord268, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup70016x51x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup70016x47x0x0x0");
  if (r == 0) db->addRelation("$sup70016x47x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x47x0x0x0");
      std::vector<u16> ord269({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x47x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x43x0x0x0");
  if (r == 0) db->addRelation("$sup70016x43x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x43x0x0x0");
      std::vector<u16> ord270({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord270, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x43x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x33x0x0x0");
  if (r == 0) db->addRelation("$sup70016x33x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x33x0x0x0");
      std::vector<u16> ord271({0, 1, 2, 3});
    
    r->addIndex<4>(ord271, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup70016x33x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x98x0x0x1");
  if (r == 0) db->addRelation("$sup5638x98x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord272({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord272, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x98x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x98x0x0x0");
  if (r == 0) db->addRelation("$sup5638x98x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord273({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x98x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x95x0x0x1");
  if (r == 0) db->addRelation("$sup5638x95x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord274({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord274, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x95x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x95x0x0x0");
  if (r == 0) db->addRelation("$sup5638x95x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord275({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord275, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x95x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x93x0x0x0");
  if (r == 0) db->addRelation("$sup5638x93x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord276({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord276, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x93x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x84x0x0x0");
  if (r == 0) db->addRelation("$sup5638x84x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord277({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x84x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x82x0x0x0");
  if (r == 0) db->addRelation("$sup5638x82x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord278({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord278, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x82x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x81x0x0x0");
  if (r == 0) db->addRelation("$sup5638x81x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord279({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord279, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x81x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x68x0x0x0");
  if (r == 0) db->addRelation("$sup5638x68x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x68x0x0x0");
      std::vector<u16> ord280({0, 1, 2, 3});
    
    r->addIndex<4>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x68x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x67x0x0x0");
  if (r == 0) db->addRelation("$sup5638x67x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x67x0x0x0");
      std::vector<u16> ord281({0, 1, 2, 3});
    
    r->addIndex<4>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x67x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x62x0x0x0");
  if (r == 0) db->addRelation("$sup5638x62x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord282({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord282, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x62x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x60x0x0x0");
  if (r == 0) db->addRelation("$sup5638x60x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord283({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord283, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x60x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x59x0x0x0");
  if (r == 0) db->addRelation("$sup5638x59x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord284({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord284, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x59x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x52x0x0x0");
  if (r == 0) db->addRelation("$sup5638x52x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x52x0x0x0");
      std::vector<u16> ord285({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord285, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x52x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x51x0x0x0");
  if (r == 0) db->addRelation("$sup5638x51x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x51x0x0x0");
      std::vector<u16> ord286({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord286, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x51x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x44x0x0x0");
  if (r == 0) db->addRelation("$sup5638x44x0x0x0", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord287({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord287, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x44x0x0x0"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x42x0x0x1");
  if (r == 0) db->addRelation("$sup5638x42x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord288({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord288, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x42x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x42x0x0x0");
  if (r == 0) db->addRelation("$sup5638x42x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord289({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord289, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x42x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x40x0x0x1");
  if (r == 0) db->addRelation("$sup5638x40x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord290({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord290, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x40x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x40x0x0x0");
  if (r == 0) db->addRelation("$sup5638x40x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord291({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord291, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x40x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x2");
  if (r == 0) db->addRelation("$sup5638x29x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord292({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord292, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x29x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x29x0x0x1");
  if (r == 0) db->addRelation("$sup5638x29x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord293({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord293, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x29x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x0");
  if (r == 0) db->addRelation("$sup5638x29x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord294({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord294, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x29x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x25x0x0x2");
  if (r == 0) db->addRelation("$sup5638x25x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord295({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord295, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x25x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x25x0x0x1");
  if (r == 0) db->addRelation("$sup5638x25x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord296({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord296, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x25x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x25x0x0x0");
  if (r == 0) db->addRelation("$sup5638x25x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord297({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord297, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x25x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x127x0x0x0");
  if (r == 0) db->addRelation("$sup5638x127x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x127x0x0x0");
      std::vector<u16> ord298({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord298, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x127x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x121x0x0x0");
  if (r == 0) db->addRelation("$sup5638x121x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x121x0x0x0");
      std::vector<u16> ord299({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord299, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x121x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x110x0x0x0");
  if (r == 0) db->addRelation("$sup5638x110x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord300({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord300, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x110x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x107x0x0x1");
  if (r == 0) db->addRelation("$sup5638x107x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord301({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord301, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x107x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x107x0x0x0");
  if (r == 0) db->addRelation("$sup5638x107x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord302({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord302, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x107x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x104x0x0x1");
  if (r == 0) db->addRelation("$sup5638x104x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord303({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord303, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x104x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x104x0x0x0");
  if (r == 0) db->addRelation("$sup5638x104x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord304({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord304, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x104x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x101x0x0x0");
  if (r == 0) db->addRelation("$sup5638x101x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord305({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord305, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x101x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$seq_atr");
  if (r == 0) db->addRelation("$seq_atr", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_atr");
      std::vector<u16> ord306({0, 1, 2});
    
    r->addIndex<3>(ord306, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_atr"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord307({0, 1, 2});
    
    r->addIndex<3>(ord307, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("app"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0, 1, 2, 3});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("bind_store"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
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
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("closure_birth"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("delta"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({3});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("eval"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1, 3});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("eval_args"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("eval_args_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2, 3});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("extend_env"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lambda"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
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
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("mp_fromlist"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
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
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("store"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
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
  // (crule (pre) (scan temp3tRZ2146 __t5fSv237 t x) (body) (head (emit-lat flow_count x t __t5fSv237)) counting.slog:28 #f)
  class ReadTask0 : public slog::Task
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
      head_rel[0] = db->getRelation("flow_count");
      outer_rel = db->getRelation("temp3tRZ2146");
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c0 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c2, v_c1, v_c0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:28", "delta:temp3tRZ2146", _fires);
  
      if (!_done)
      {
        ReadTask0* _cont = new ReadTask0(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre7ms42115 __errf3lIh2116 __errf8y4P2117) (body) (head (emit error (0) __erre7ms42115)) <internal>:1 #f)
  class ReadTask1 : public slog::Task
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
      std::vector<u16> ord2({0});
      slog::Relation* readrel3 = db->getRelation("error");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask1* _cont = new ReadTask1(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1(db,b), false);
  // (crule (pre) (scan many_frames c) (body (join call_event (1 0) 1 c t2)) (head (emit many_frames (0) t2)) counting.slog:11 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** call_eventindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("many_frames");
      std::vector<u16> ord6({0});
      slog::Relation* readrel7 = db->getRelation("many_frames");
      head_index[0] = readrel7->getIndex(ord6, false);
      outer_rel = db->getRelation("many_frames");
      std::vector<u16> ord8({1, 0});
      slog::Relation* readrel9 = db->getRelation("call_event");
      call_eventindex4 = readrel9->getIndex(ord8, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(call_eventindex4, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m10) {
          u64 v_c7 = m10[1];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:11", "delta:many_frames", _fires);
  
      if (!_done)
      {
        ReadTask5* _cont = new ReadTask5(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre9CUD2139 __errf3dWs2140 __errf5u1d2141) (body) (head (emit error (0) __erre9CUD2139)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
        u64 v_c8 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c10 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre (let __t5f8D122 (one))) (scan store x t v) (body) (head (emit-temp temp29Jt2147 __t5f8D122 t x)) counting.slog:27 #f)
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
      head_rel[0] = db->getRelation("temp29Jt2147");
      outer_rel = db->getRelation("store");
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = _prim_one(db);
      if (v_c11 == slog_error) { slog::emit_pending_error(db, "counting.slog:27"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c2 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c12 = _t[2];
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c11, v_c1, v_c2});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:27", "all:store", _fires);
  
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
      s->addTask(phase_read, new ReadTask14(db,b), true);
  // (crule (pre (let __t5fSv237 (inf))) (scan store x t v2) (body (join store (0 1 2) 2 x t v1) (neq v1 v2)) (head (emit-temp temp3tRZ2146 __t5fSv237 t x)) counting.slog:28 #f)
  class ReadTask16 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** storeindex15;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3tRZ2146");
      outer_rel = db->getRelation("store");
      std::vector<u16> ord17({0, 1, 2});
      slog::Relation* readrel18 = db->getRelation("store");
      storeindex15 = readrel18->getIndex(ord17, false);
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = _prim_inf(db);
      if (v_c0 == slog_error) { slog::emit_pending_error(db, "counting.slog:28"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c2 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c13 = _t[2];
        slog::join_probe<3,2>(storeindex15, std::array<u64,3>{v_c2, v_c1, 0}, [&](const std::array<u64,3>& m19) {
          u64 v_c14 = m19[2];
          if (v_c14 == v_c13) return;
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c0, v_c1, v_c2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:28", "all:store", _fires);
  
      if (!_done)
      {
        ReadTask16* _cont = new ReadTask16(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask16(db,b), true);
  // (crule (pre) (scan toint_range __erre0oVf2126 __errf5iTo2127 __errf0FO12128) (body) (head (emit error (0) __erre0oVf2126)) <internal>:1 #f)
  class ReadTask20 : public slog::Task
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
      std::vector<u16> ord21({0});
      slog::Relation* readrel22 = db->getRelation("error");
      head_index[0] = readrel22->getIndex(ord21, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask20* _cont = new ReadTask20(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask20(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre8IW52134 __errf10Ag2135 __errf2qrL2136 __errf4DGt2137 __errf2lLQ2138) (body) (head (emit error (0) __erre8IW52134)) <internal>:1 #f)
  class ReadTask23 : public slog::Task
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
      std::vector<u16> ord24({0});
      slog::Relation* readrel25 = db->getRelation("error");
      head_index[0] = readrel25->getIndex(ord24, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask23(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c20 = _t[2];
        u64 v_c21 = _t[3];
        u64 v_c22 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask23* _cont = new ReadTask23(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask23(db,b), false);
  // (crule (pre (let __trid5WLj1414 const6e5ee07e63cdbc3ea07dd8a9) (let __trel17Uy1415 constf7d5dda68c5473f68197d2e7) (let __tcol236P1416 const5feceb66ffc86f38d952786c)) (scan $sup5638x121x0x0x0 __d0 l m p r) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid5WLj1414 __trel17Uy1415 __tcol236P1416 (1 2 3 4 0)) (mkstruct mp_size (1 0) __4TTr1413 r)) map.slog:122 #f)
  class ReadTask29 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid27;  u32 sid26;  u32 sid28;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_size");
      outer_rel = db->getRelation("$sup5638x121x0x0x0");
      sid27 = db->getRelation("_enum")->getStructId();
      sid26 = db->getRelation("mbranch")->getStructId();
      sid28 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask29(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_const6e5ee07e63cdbc3ea07dd8a9;
      u64 v_c24 = v_constf7d5dda68c5473f68197d2e7;
      u64 v_c25 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c26 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        ++_fires;
        if (!((is_struct(v_c30) && (decode_struct_id(v_c30) == sid26 || decode_struct_id(v_c30) == sid27 || decode_struct_id(v_c30) == sid28))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c23, v_c24, v_c25, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c30}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:122", "delta:$sup5638x121x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask29* _cont = new ReadTask29(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask29(db,b), false);
  // (crule (pre) (scan nan_result __erre8er52122 __errf1VkL2123 __errf5l6g2124 __errf0rU32125) (body) (head (emit error (0) __erre8er52122)) <internal>:1 #f)
  class ReadTask30 : public slog::Task
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
      std::vector<u16> ord31({0});
      slog::Relation* readrel32 = db->getRelation("error");
      head_index[0] = readrel32->getIndex(ord31, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask30(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c31 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c33 = _t[2];
        u64 v_c34 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c31}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask30* _cont = new ReadTask30(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask30(db,b), false);
  // (crule (pre) (scan type_mismatch __erre421p2129 __errf66DD2130 __errf7UWR2131 __errf4J9S2132 __errf2tb82133) (body) (head (emit error (0) __erre421p2129)) <internal>:1 #f)
  class ReadTask33 : public slog::Task
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
      std::vector<u16> ord34({0});
      slog::Relation* readrel35 = db->getRelation("error");
      head_index[0] = readrel35->getIndex(ord34, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask33(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c35 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c37 = _t[2];
        u64 v_c38 = _t[3];
        u64 v_c39 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c35}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask33* _cont = new ReadTask33(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask33(db,b), false);
  // (crule (pre (let __trid4xrr1240 const6e5ee07e63cdbc3ea07dd8a9) (let __trel6qjW1241 constf7d5dda68c5473f68197d2e7) (let __tcol4W8y1242 const5feceb66ffc86f38d952786c)) (scan $sup5638x121x0x0x0 __d0 l m p r) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid4xrr1240 __trel6qjW1241 __tcol4W8y1242 (1 2 3 4 0)) (mkstruct mp_size (1 0) __8oOp1239 l)) map.slog:122 #f)
  class ReadTask39 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid37;  u32 sid36;  u32 sid38;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_size");
      outer_rel = db->getRelation("$sup5638x121x0x0x0");
      sid37 = db->getRelation("_enum")->getStructId();
      sid36 = db->getRelation("mbranch")->getStructId();
      sid38 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask39(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const6e5ee07e63cdbc3ea07dd8a9;
      u64 v_c41 = v_constf7d5dda68c5473f68197d2e7;
      u64 v_c42 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c26 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        ++_fires;
        if (!((is_struct(v_c27) && (decode_struct_id(v_c27) == sid36 || decode_struct_id(v_c27) == sid37 || decode_struct_id(v_c27) == sid38))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c40, v_c41, v_c42, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c27}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:122", "delta:$sup5638x121x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask39* _cont = new ReadTask39(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask39(db,b), false);
  // (crule (pre) (scan temp29Jt2147 __t5f8D122 t x) (body) (head (emit-lat flow_count x t __t5f8D122)) counting.slog:27 #f)
  class ReadTask40 : public slog::Task
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
      head_rel[0] = db->getRelation("flow_count");
      outer_rel = db->getRelation("temp29Jt2147");
  
    }
    ReadTask40(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c2, v_c1, v_c11});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:27", "delta:temp29Jt2147", _fires);
  
      if (!_done)
      {
        ReadTask40* _cont = new ReadTask40(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask40(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre3Gkn2107 __errf1TDu2108 __errf8ImJ2109 __errf5Znw2110 __errf3G9B2111) (body) (head (emit error (0) __erre3Gkn2107)) <internal>:1 #f)
  class ReadTask41 : public slog::Task
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
      std::vector<u16> ord42({0});
      slog::Relation* readrel43 = db->getRelation("error");
      head_index[0] = readrel43->getIndex(ord42, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask41(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c45 = _t[2];
        u64 v_c46 = _t[3];
        u64 v_c47 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c43}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask41* _cont = new ReadTask41(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask41(db,b), false);
  // (crule (pre) (scan eval_ans __t1gaN700 vc) (body (join eval (0 1 2 3) 1 __t1gaN700 __t79CI699 rho t) (join lambda (0 1 2) 1 __t79CI699 xs eb)) (head (emit closure_birth (0 1) vc t)) counting.slog:52 #f)
  class ReadTask46 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex44;  slog::Index** lambdaindex45;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("closure_birth");
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("closure_birth");
      head_index[0] = readrel48->getIndex(ord47, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord49({0, 1, 2, 3});
      slog::Relation* readrel50 = db->getRelation("eval");
      evalindex44 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 1, 2});
      slog::Relation* readrel52 = db->getRelation("lambda");
      lambdaindex45 = readrel52->getIndex(ord51, false);
  
    }
    ReadTask46(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<4,1>(evalindex44, std::array<u64,4>{v_c48, 0, 0, 0}, [&](const std::array<u64,4>& m53) {
          u64 v_c50 = m53[1]; u64 v_c51 = m53[2]; u64 v_c1 = m53[3];
          slog::join_probe<3,1>(lambdaindex45, std::array<u64,3>{v_c50, 0, 0}, [&](const std::array<u64,3>& m54) {
            u64 v_c52 = m54[1]; u64 v_c53 = m54[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c1}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:52", "all:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask46* _cont = new ReadTask46(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask46(db,b), true);
  // (crule (pre (let __tconst1WD31320 constd01925b37634a1a9d24159d8) (let _00024sqc99C01004 const5feceb66ffc86f38d952786c)) (probe _enum (1 0) 1 __tconst1WD31320 __t6DI4585) (body (join eval (2 1 3 0) 1 __t6DI4585 e _00024seq0 __t4uah586) (join program (0) 1 e) (join eval_ans (0 1) 1 __t4uah586 v) (letp _00024sql6HRK1002 (aslst _00024seq0)) (let chk8VZ22142 (llen _00024sql6HRK1002)) (eq _00024sqc99C01004 chk8VZ22142)) (head (emit program_result (0) v)) interp.slog:134 #f)
  class ReadTask58 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** evalindex55;  slog::Index** programindex56;  slog::Index** eval_ansindex57;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program_result");
      std::vector<u16> ord59({0});
      slog::Relation* readrel60 = db->getRelation("program_result");
      head_index[0] = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 0});
      slog::Relation* readrel62 = db->getRelation("_enum");
      driver_index = readrel62->getIndex(ord61, true);
      std::vector<u16> ord63({2, 1, 3, 0});
      slog::Relation* readrel64 = db->getRelation("eval");
      evalindex55 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({0});
      slog::Relation* readrel66 = db->getRelation("program");
      programindex56 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({0, 1});
      slog::Relation* readrel68 = db->getRelation("eval_ans");
      eval_ansindex57 = readrel68->getIndex(ord67, false);
  
    }
    ReadTask58(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_constd01925b37634a1a9d24159d8;
      u64 v_c55 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c54, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m69) {
        u64 v_c56 = m69[1];
        if (buckethash(v_c56) != bucket) return;
        slog::join_probe<4,1>(evalindex55, std::array<u64,4>{v_c56, 0, 0, 0}, [&](const std::array<u64,4>& m70) {
          u64 v_c57 = m70[1]; u64 v_c58 = m70[2]; u64 v_c59 = m70[3];
          slog::join_probe<1,1>(programindex56, std::array<u64,1>{v_c57}, [&](const std::array<u64,1>& m71) {
            slog::join_probe<2,1>(eval_ansindex57, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m72) {
              u64 v_c12 = m72[1];
              bool ok73 = true;
              u64 v_c60 = _prim_aslst(db, v_c58, &ok73);
              if (!ok73) return;
              u64 v_c61 = _prim_llen(db, v_c60);
              if (v_c61 == slog_error) { slog::emit_pending_error(db, "interp.slog:134"); return; }
              if (v_c55 != v_c61) return;
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:134", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask58* _cont = new ReadTask58(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask58(db,b), true);
  // (crule (pre) (scan eval __8Rfb1107 e rho t) (body) (head (emit reachable_expr (0) e)) interp.slog:135 #f)
  class ReadTask74 : public slog::Task
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
      head_rel[0] = db->getRelation("reachable_expr");
      std::vector<u16> ord75({0});
      slog::Relation* readrel76 = db->getRelation("reachable_expr");
      head_index[0] = readrel76->getIndex(ord75, false);
      outer_rel = db->getRelation("eval");
  
    }
    ReadTask74(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c62 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c1 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:135", "all:eval", _fires);
  
      if (!_done)
      {
        ReadTask74* _cont = new ReadTask74(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask74(db,b), true);
  // (crule (pre) (scan mp_size __t3nZ3335 __t0BYm334) (body (join mbranch (0 1 2 3 4) 1 __t0BYm334 p m l r)) (head (emit $sup5638x121x0x0x0 (0 1 2 3 4) __t3nZ3335 l m p r)) map.slog:122 #f)
  class ReadTask78 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex77;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x121x0x0x0");
      std::vector<u16> ord79({0, 1, 2, 3, 4});
      slog::Relation* readrel80 = db->getRelation("$sup5638x121x0x0x0");
      head_index[0] = readrel80->getIndex(ord79, false);
      outer_rel = db->getRelation("mp_size");
      std::vector<u16> ord81({0, 1, 2, 3, 4});
      slog::Relation* readrel82 = db->getRelation("mbranch");
      mbranchindex77 = readrel82->getIndex(ord81, false);
  
    }
    ReadTask78(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[0];
        u64 v_c64 = _t[1];
        slog::join_probe<5,1>(mbranchindex77, std::array<u64,5>{v_c64, 0, 0, 0, 0}, [&](const std::array<u64,5>& m83) {
          u64 v_c29 = m83[1]; u64 v_c28 = m83[2]; u64 v_c27 = m83[3]; u64 v_c30 = m83[4];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c63, v_c27, v_c28, v_c29, v_c30}, std::array<u16,5>{0, 1, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:122", "delta:mp_size", _fires);
  
      if (!_done)
      {
        ReadTask78* _cont = new ReadTask78(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask78(db,b), false);
  // (crule (pre) (scan div_by_zero __erre3qdy2112 __errf69w72113 __errf3GGF2114) (body) (head (emit error (0) __erre3qdy2112)) <internal>:1 #f)
  class ReadTask84 : public slog::Task
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
      std::vector<u16> ord85({0});
      slog::Relation* readrel86 = db->getRelation("error");
      head_index[0] = readrel86->getIndex(ord85, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask84(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c65 = _t[0];
        u64 v_c66 = _t[1];
        u64 v_c67 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c65}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask84* _cont = new ReadTask84(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask84(db,b), false);
  // (crule (pre) (scan call_event t2 c2) (body (join call_event (0 1) 1 t2 c1) (neq c1 c2)) (head (emit many_frames (0) t2)) counting.slog:10 #f)
  class ReadTask88 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** call_eventindex87;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("many_frames");
      std::vector<u16> ord89({0});
      slog::Relation* readrel90 = db->getRelation("many_frames");
      head_index[0] = readrel90->getIndex(ord89, false);
      outer_rel = db->getRelation("call_event");
      std::vector<u16> ord91({0, 1});
      slog::Relation* readrel92 = db->getRelation("call_event");
      call_eventindex87 = readrel92->getIndex(ord91, false);
  
    }
    ReadTask88(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[0];
        u64 v_c68 = _t[1];
        slog::join_probe<2,1>(call_eventindex87, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m93) {
          u64 v_c69 = m93[1];
          if (v_c69 == v_c68) return;
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("counting.slog:10", "all:call_event", _fires);
  
      if (!_done)
      {
        ReadTask88* _cont = new ReadTask88(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask88(db,b), true);
  // (crule (pre) (scan int_overflow __erre8WKB2118 __errf4bE92119 __errf2Cgv2120 __errf45IA2121) (body) (head (emit error (0) __erre8WKB2118)) <internal>:1 #f)
  class ReadTask94 : public slog::Task
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
      std::vector<u16> ord95({0});
      slog::Relation* readrel96 = db->getRelation("error");
      head_index[0] = readrel96->getIndex(ord95, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask94(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c70 = _t[0];
        u64 v_c71 = _t[1];
        u64 v_c72 = _t[2];
        u64 v_c73 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c70}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask94* _cont = new ReadTask94(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask94(db,b), false);
  s->addReadRel("$sup5638x121x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("call_event");
  s->addReadRel("div_by_zero");
  s->addReadRel("eval");
  s->addReadRel("eval_ans");
  s->addReadRel("int_overflow");
  s->addReadRel("lambda");
  s->addReadRel("malformed_deduction");
  s->addReadRel("many_frames");
  s->addReadRel("mbranch");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mp_size");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("program");
  s->addReadRel("store");
  s->addReadRel("temp29Jt2147");
  s->addReadRel("temp3tRZ2146");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$seq_atr");
  s->addDynamicRel("$sup5638x121x0x0x0");
  s->addDynamicRel("closure_birth");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("flow_count");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("many_frames");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mp_size");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("program_result");
  s->addDynamicRel("reachable_expr");
  s->addDynamicRel("temp29Jt2147");
  s->addDynamicRel("temp3tRZ2146");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("many_frames");
  d->push(s);
  d->continueRun();
}

