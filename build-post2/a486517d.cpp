
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_consta8648fdb04f7c50b03dd675e;
u64 v_const57ba71c4b2fba1fd2fbcd814;
u64 v_const1ef5dd96b7ac876a994a9ca1;
u64 v_const0122baa3ac55f1b433944eb1;
u64 v_constb9e118781cea1f9fa01462e0;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const53a56174f3826669a422fc54;
u64 v_consted725292f5f32d61535958c1;
u64 v_const7297d2085ea0adffc396d546;
u64 v_const90fb9068eda6f2d68bb61c33;
u64 v_const0933fb667296882d8c45abca;
u64 v_constcd2a69ce5ca278db1d6da969;
u64 v_constd01925b37634a1a9d24159d8;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("a486517d");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_consta8648fdb04f7c50b03dd675e = db->encodeString("mp_fromlist");
  v_const57ba71c4b2fba1fd2fbcd814 = db->encodeString("<=");
  v_const1ef5dd96b7ac876a994a9ca1 = db->encodeString("map.slog:128");
  v_const0122baa3ac55f1b433944eb1 = db->encodeString("tt");
  v_constb9e118781cea1f9fa01462e0 = db->encodeString("ff");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const53a56174f3826669a422fc54 = db->encodeString("<");
  v_consted725292f5f32d61535958c1 = db->encodeString("*");
  v_const7297d2085ea0adffc396d546 = db->encodeString("+");
  v_const90fb9068eda6f2d68bb61c33 = db->encodeString("=");
  v_const0933fb667296882d8c45abca = db->encodeString("-");
  v_constcd2a69ce5ca278db1d6da969 = db->encodeString("numval");
  v_constd01925b37634a1a9d24159d8 = db->encodeString("mempty");
  r = db->getRelation("unique_closure");
  if (r == 0) db->addRelation("unique_closure", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("unique_closure");
      std::vector<u16> ord58({0});
    
    r->addIndex<1>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("unique_closure"), std::array<u16,1>{0}, b));
  r = db->getRelation("unique_binding");
  if (r == 0) db->addRelation("unique_binding", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("unique_binding");
      std::vector<u16> ord59({0, 1});
    
    r->addIndex<2>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("unique_binding"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord60({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord61({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord62({1, 2, 0});
    
    r->addIndex<3>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord63({0, 1, 2});
    
    r->addIndex<3>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("tick_ans");
  if (r == 0) db->addRelation("tick_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tick_ans");
      std::vector<u16> ord64({0, 1});
    
    r->addIndex<2>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("tick_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("tick");
  if (r == 0) db->addStruct("tick", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tick");
      std::vector<u16> ord65({1, 2, 0});
    
    r->addIndex<3>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord66({0, 1, 2});
    
    r->addIndex<3>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("tick"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("symval");
  if (r == 0) db->addStruct("symval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("symval");
      std::vector<u16> ord67({1, 0});
    
    r->addIndex<2>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord68({0, 1});
    
    r->addIndex<2>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("symval"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("sym");
  if (r == 0) db->addStruct("sym", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("sym");
      std::vector<u16> ord69({1, 0});
    
    r->addIndex<2>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord70({0, 1});
    
    r->addIndex<2>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("sym"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("summarized_closure");
  if (r == 0) db->addRelation("summarized_closure", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("summarized_closure");
      std::vector<u16> ord71({0});
    
    r->addIndex<1>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("summarized_closure"), std::array<u16,1>{0}, b));
  r = db->getRelation("summarized_binding");
  if (r == 0) db->addRelation("summarized_binding", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("summarized_binding");
      std::vector<u16> ord72({0, 1});
    
    r->addIndex<2>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("summarized_binding"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("store");
  if (r == 0) db->addRelation("store", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("store");
      std::vector<u16> ord73({0, 1, 2});
    
    r->addIndex<3>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("store"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord74({1, 2, 0});
    
    r->addIndex<3>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord75({0, 1, 2});
    
    r->addIndex<3>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("singleton_flow");
  if (r == 0) db->addRelation("singleton_flow", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("singleton_flow");
      std::vector<u16> ord76({0, 1});
    
    r->addIndex<2>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("singleton_flow"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("select_branch_ans");
  if (r == 0) db->addRelation("select_branch_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("select_branch_ans");
      std::vector<u16> ord77({0, 1});
    
    r->addIndex<2>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("select_branch_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("select_branch");
  if (r == 0) db->addStruct("select_branch", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("select_branch");
      std::vector<u16> ord78({1, 2, 3, 0});
    
    r->addIndex<4>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord79({0, 1, 2, 3});
    
    r->addIndex<4>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("select_branch"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("scheme_false");
  if (r == 0) db->addRelation("scheme_false", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("scheme_false");
      std::vector<u16> ord80({0});
    
    r->addIndex<1>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("scheme_false"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord81({1, 0});
    
    r->addIndex<2>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord82({0, 1});
    
    r->addIndex<2>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("reachable_expr");
  if (r == 0) db->addRelation("reachable_expr", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("reachable_expr");
      std::vector<u16> ord83({0});
    
    r->addIndex<1>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("reachable_expr"), std::array<u16,1>{0}, b));
  r = db->getRelation("program_result");
  if (r == 0) db->addRelation("program_result", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program_result");
      std::vector<u16> ord84({0});
    
    r->addIndex<1>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program_result"), std::array<u16,1>{0}, b));
  r = db->getRelation("program");
  if (r == 0) db->addRelation("program", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program");
      std::vector<u16> ord85({0});
    
    r->addIndex<1>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program"), std::array<u16,1>{0}, b));
  r = db->getRelation("primref");
  if (r == 0) db->addStruct("primref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("primref");
      std::vector<u16> ord86({1, 0});
    
    r->addIndex<2>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord87({0, 1});
    
    r->addIndex<2>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("primref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("primitive");
  if (r == 0) db->addRelation("primitive", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("primitive");
      std::vector<u16> ord88({0});
    
    r->addIndex<1>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("primitive"), std::array<u16,1>{0}, b));
  r = db->getRelation("prim");
  if (r == 0) db->addStruct("prim", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("prim");
      std::vector<u16> ord89({1, 0});
    
    r->addIndex<2>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord90({0, 1});
    
    r->addIndex<2>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("prim"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("polyvariant_flow");
  if (r == 0) db->addRelation("polyvariant_flow", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("polyvariant_flow");
      std::vector<u16> ord91({0, 1});
    
    r->addIndex<2>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("polyvariant_flow"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("num");
  if (r == 0) db->addStruct("num", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("num");
      std::vector<u16> ord92({1, 0});
    
    r->addIndex<2>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord93({0, 1});
    
    r->addIndex<2>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("num"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord94({1, 2, 3, 0});
    
    r->addIndex<4>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord95({0, 1, 2, 3});
    
    r->addIndex<4>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("must_value");
  if (r == 0) db->addRelation("must_value", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("must_value");
      std::vector<u16> ord96({0, 1, 2});
    
    r->addIndex<3>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("must_value"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord97({1, 2, 0});
    
    r->addIndex<3>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord98({0, 1, 2});
    
    r->addIndex<3>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord99({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord100({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_union_ans");
  if (r == 0) db->addRelation("mp_union_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union_ans");
      std::vector<u16> ord101({0, 1});
    
    r->addIndex<2>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_union_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_union");
  if (r == 0) db->addStruct("mp_union", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union");
      std::vector<u16> ord102({1, 2, 0});
    
    r->addIndex<3>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord103({0, 1, 2});
    
    r->addIndex<3>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_union"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_size_ans");
  if (r == 0) db->addRelation("mp_size_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size_ans");
      std::vector<u16> ord104({0, 1});
    
    r->addIndex<2>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_size_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_size");
  if (r == 0) db->addStruct("mp_size", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size");
      std::vector<u16> ord105({1, 0});
    
    r->addIndex<2>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord106({0, 1});
    
    r->addIndex<2>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_size"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_put_soft_ans");
  if (r == 0) db->addRelation("mp_put_soft_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord107({0, 1});
    
    r->addIndex<2>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_soft_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put_soft");
  if (r == 0) db->addStruct("mp_put_soft", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft");
      std::vector<u16> ord108({1, 2, 3, 0});
    
    r->addIndex<4>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord109({0, 1, 2, 3});
    
    r->addIndex<4>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put_soft"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_put_ans");
  if (r == 0) db->addRelation("mp_put_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_ans");
      std::vector<u16> ord110({0, 1});
    
    r->addIndex<2>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put");
  if (r == 0) db->addStruct("mp_put", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put");
      std::vector<u16> ord111({1, 2, 3, 0});
    
    r->addIndex<4>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord112({0, 1, 2, 3});
    
    r->addIndex<4>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_msk_ans");
  if (r == 0) db->addRelation("mp_msk_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk_ans");
      std::vector<u16> ord113({0, 1});
    
    r->addIndex<2>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_msk_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_msk");
  if (r == 0) db->addStruct("mp_msk", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk");
      std::vector<u16> ord114({1, 2, 0});
    
    r->addIndex<3>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord115({0, 1, 2});
    
    r->addIndex<3>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_msk"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_join_ans");
  if (r == 0) db->addRelation("mp_join_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join_ans");
      std::vector<u16> ord116({0, 1});
    
    r->addIndex<2>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_join_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_join");
  if (r == 0) db->addStruct("mp_join", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join");
      std::vector<u16> ord117({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord118({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_join"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_hsb_ans");
  if (r == 0) db->addRelation("mp_hsb_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord119({0, 1});
    
    r->addIndex<2>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_hsb_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_hsb");
  if (r == 0) db->addStruct("mp_hsb", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb");
      std::vector<u16> ord120({1, 0});
    
    r->addIndex<2>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord121({0, 1});
    
    r->addIndex<2>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_hsb"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_has0_ans");
  if (r == 0) db->addRelation("mp_has0_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0_ans");
      std::vector<u16> ord122({0, 1});
    
    r->addIndex<2>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_has0_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_has0");
  if (r == 0) db->addStruct("mp_has0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0");
      std::vector<u16> ord123({1, 2, 0});
    
    r->addIndex<3>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord124({0, 1, 2});
    
    r->addIndex<3>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_has0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_get_ans");
  if (r == 0) db->addRelation("mp_get_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get_ans");
      std::vector<u16> ord125({0, 1});
    
    r->addIndex<2>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_get_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_get");
  if (r == 0) db->addStruct("mp_get", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get");
      std::vector<u16> ord126({1, 2, 0});
    
    r->addIndex<3>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord127({0, 1, 2});
    
    r->addIndex<3>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_get"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_fromlist_ans");
  if (r == 0) db->addRelation("mp_fromlist_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord128({0, 1});
    
    r->addIndex<2>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_fromlist_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_fromlist");
  if (r == 0) db->addStruct("mp_fromlist", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist");
      std::vector<u16> ord129({1, 0});
    
    r->addIndex<2>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord130({0, 1});
    
    r->addIndex<2>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_fromlist"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_del_ans");
  if (r == 0) db->addRelation("mp_del_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del_ans");
      std::vector<u16> ord131({0, 1});
    
    r->addIndex<2>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_del_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_del");
  if (r == 0) db->addStruct("mp_del", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del");
      std::vector<u16> ord132({1, 2, 0});
    
    r->addIndex<3>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord133({0, 1, 2});
    
    r->addIndex<3>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_del"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_bld_ans");
  if (r == 0) db->addRelation("mp_bld_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld_ans");
      std::vector<u16> ord134({0, 1});
    
    r->addIndex<2>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_bld_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_bld");
  if (r == 0) db->addStruct("mp_bld", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld");
      std::vector<u16> ord135({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord136({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_bld"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord137({1, 2, 0});
    
    r->addIndex<3>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord138({0, 1, 2});
    
    r->addIndex<3>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mleaf");
  if (r == 0) db->addStruct("mleaf", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mleaf");
      std::vector<u16> ord139({1, 2, 0});
    
    r->addIndex<3>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord140({0, 1, 2});
    
    r->addIndex<3>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mleaf"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mbranch");
  if (r == 0) db->addStruct("mbranch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mbranch");
      std::vector<u16> ord141({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord142({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mbranch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("many_frames");
  if (r == 0) db->addRelation("many_frames", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("many_frames");
      std::vector<u16> ord143({0});
    
    r->addIndex<1>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("many_frames"), std::array<u16,1>{0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord144({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord145({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lst_take_ans");
  if (r == 0) db->addRelation("lst_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take_ans");
      std::vector<u16> ord146({0, 1});
    
    r->addIndex<2>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_take");
  if (r == 0) db->addStruct("lst_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take");
      std::vector<u16> ord147({1, 2, 0});
    
    r->addIndex<3>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord148({0, 1, 2});
    
    r->addIndex<3>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev_ans");
  if (r == 0) db->addRelation("lst_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_ans");
      std::vector<u16> ord149({0, 1});
    
    r->addIndex<2>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc_ans");
  if (r == 0) db->addRelation("lst_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc_ans");
      std::vector<u16> ord150({0, 1});
    
    r->addIndex<2>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc");
  if (r == 0) db->addStruct("lst_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc");
      std::vector<u16> ord151({1, 2, 0});
    
    r->addIndex<3>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord152({0, 1, 2});
    
    r->addIndex<3>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev");
  if (r == 0) db->addStruct("lst_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev");
      std::vector<u16> ord153({1, 0});
    
    r->addIndex<2>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord154({0, 1});
    
    r->addIndex<2>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_ref_ans");
  if (r == 0) db->addRelation("lst_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref_ans");
      std::vector<u16> ord155({0, 1});
    
    r->addIndex<2>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_ref");
  if (r == 0) db->addStruct("lst_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref");
      std::vector<u16> ord156({1, 2, 0});
    
    r->addIndex<3>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord157({0, 1, 2});
    
    r->addIndex<3>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_member_ans");
  if (r == 0) db->addRelation("lst_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member_ans");
      std::vector<u16> ord158({0, 1});
    
    r->addIndex<2>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_member");
  if (r == 0) db->addStruct("lst_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member");
      std::vector<u16> ord159({1, 2, 0});
    
    r->addIndex<3>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord160({0, 1, 2});
    
    r->addIndex<3>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_len_ans");
  if (r == 0) db->addRelation("lst_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len_ans");
      std::vector<u16> ord161({0, 1});
    
    r->addIndex<2>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_len");
  if (r == 0) db->addStruct("lst_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len");
      std::vector<u16> ord162({1, 0});
    
    r->addIndex<2>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord163({0, 1});
    
    r->addIndex<2>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_append_ans");
  if (r == 0) db->addRelation("lst_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append_ans");
      std::vector<u16> ord164({0, 1});
    
    r->addIndex<2>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_append");
  if (r == 0) db->addStruct("lst_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append");
      std::vector<u16> ord165({1, 2, 0});
    
    r->addIndex<3>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord166({0, 1, 2});
    
    r->addIndex<3>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_absent_ans");
  if (r == 0) db->addRelation("lst_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent_ans");
      std::vector<u16> ord167({0, 1});
    
    r->addIndex<2>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_absent");
  if (r == 0) db->addStruct("lst_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent");
      std::vector<u16> ord168({1, 2, 0});
    
    r->addIndex<3>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord169({0, 1, 2});
    
    r->addIndex<3>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lookup_ans");
  if (r == 0) db->addRelation("lookup_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lookup_ans");
      std::vector<u16> ord170({0, 1});
    
    r->addIndex<2>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lookup_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lookup");
  if (r == 0) db->addStruct("lookup", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lookup");
      std::vector<u16> ord171({1, 2, 0});
    
    r->addIndex<3>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord172({0, 1, 2});
    
    r->addIndex<3>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lookup"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("letrec");
  if (r == 0) db->addStruct("letrec", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("letrec");
      std::vector<u16> ord173({1, 2, 3, 0});
    
    r->addIndex<4>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord174({0, 1, 2, 3});
    
    r->addIndex<4>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("letrec"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("let");
  if (r == 0) db->addStruct("let", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("let");
      std::vector<u16> ord175({1, 2, 3, 0});
    
    r->addIndex<4>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord176({0, 1, 2, 3});
    
    r->addIndex<4>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("let"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("lambda");
  if (r == 0) db->addStruct("lambda", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lambda");
      std::vector<u16> ord177({1, 2, 0});
    
    r->addIndex<3>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord178({0, 1, 2});
    
    r->addIndex<3>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lambda"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("klimit");
  if (r == 0) db->addRelation("klimit", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("klimit");
      std::vector<u16> ord179({0});
    
    r->addIndex<1>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("klimit"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord180({1, 2, 3, 0});
    
    r->addIndex<4>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord181({0, 1, 2, 3});
    
    r->addIndex<4>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("if");
  if (r == 0) db->addStruct("if", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("if");
      std::vector<u16> ord182({1, 2, 3, 0});
    
    r->addIndex<4>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord183({0, 1, 2, 3});
    
    r->addIndex<4>(ord183, false);
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
      std::vector<u16> ord184({0, 1});
    
    r->addMapIndex<2>(ord184);
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
      std::vector<u16> ord185({0, 1, 2});
    
    r->addMapIndex<3>(ord185);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<3>(db, db->getRelation("flow_count"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("extend_env_ans");
  if (r == 0) db->addRelation("extend_env_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("extend_env_ans");
      std::vector<u16> ord186({0, 1});
    
    r->addIndex<2>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("extend_env_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("extend_env");
  if (r == 0) db->addStruct("extend_env", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("extend_env");
      std::vector<u16> ord187({1, 2, 3, 0});
    
    r->addIndex<4>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord188({0, 1, 2, 3});
    
    r->addIndex<4>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("extend_env"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("eval_args_ans");
  if (r == 0) db->addRelation("eval_args_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_args_ans");
      std::vector<u16> ord189({0, 1});
    
    r->addIndex<2>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval_args_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("eval_args");
  if (r == 0) db->addStruct("eval_args", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_args");
      std::vector<u16> ord190({1, 2, 3, 0});
    
    r->addIndex<4>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord191({0, 1, 2, 3});
    
    r->addIndex<4>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("eval_args"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("eval_ans");
  if (r == 0) db->addRelation("eval_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_ans");
      std::vector<u16> ord192({0, 1});
    
    r->addIndex<2>(ord192, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("eval");
  if (r == 0) db->addStruct("eval", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval");
      std::vector<u16> ord193({1, 2, 3, 0});
    
    r->addIndex<4>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord194({0, 1, 2, 3});
    
    r->addIndex<4>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("eval"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord195({0});
    
    r->addIndex<1>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord196({1, 2, 0});
    
    r->addIndex<3>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord197({0, 1, 2});
    
    r->addIndex<3>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("delta_ans");
  if (r == 0) db->addRelation("delta_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("delta_ans");
      std::vector<u16> ord198({0, 1});
    
    r->addIndex<2>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("delta_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("delta");
  if (r == 0) db->addStruct("delta", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("delta");
      std::vector<u16> ord199({1, 2, 0});
    
    r->addIndex<3>(ord199, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord200({0, 1, 2});
    
    r->addIndex<3>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("delta"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("comparison_op");
  if (r == 0) db->addRelation("comparison_op", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("comparison_op");
      std::vector<u16> ord201({0});
    
    r->addIndex<1>(ord201, false);
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
      std::vector<u16> ord202({0, 1});
    
    r->addMapIndex<2>(ord202);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<2>(db, r, std::array<u16,2>{0, 1}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<2>(db, db->getRelation("closure_count"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("closure_birth");
  if (r == 0) db->addRelation("closure_birth", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("closure_birth");
      std::vector<u16> ord203({0, 1});
    
    r->addIndex<2>(ord203, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("closure_birth"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("closure");
  if (r == 0) db->addStruct("closure", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("closure");
      std::vector<u16> ord204({1, 2, 0});
    
    r->addIndex<3>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord205({0, 1, 2});
    
    r->addIndex<3>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("closure"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("call_event");
  if (r == 0) db->addRelation("call_event", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("call_event");
      std::vector<u16> ord206({0, 1});
    
    r->addIndex<2>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("call_event"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("boolval");
  if (r == 0) db->addStruct("boolval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("boolval");
      std::vector<u16> ord207({1, 0});
    
    r->addIndex<2>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord208({0, 1});
    
    r->addIndex<2>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("boolval"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("boolean");
  if (r == 0) db->addStruct("boolean", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("boolean");
      std::vector<u16> ord209({1, 0});
    
    r->addIndex<2>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord210({0, 1});
    
    r->addIndex<2>(ord210, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("boolean"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("binding_event");
  if (r == 0) db->addRelation("binding_event", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("binding_event");
      std::vector<u16> ord211({0, 1, 2});
    
    r->addIndex<3>(ord211, false);
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
      std::vector<u16> ord212({0, 1, 2});
    
    r->addMapIndex<3>(ord212);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<3>(db, db->getRelation("binding_count"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("bind_store");
  if (r == 0) db->addRelation("bind_store", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bind_store");
      std::vector<u16> ord213({0, 1, 2, 3});
    
    r->addIndex<4>(ord213, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("bind_store"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("arithmetic_op");
  if (r == 0) db->addRelation("arithmetic_op", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("arithmetic_op");
      std::vector<u16> ord214({0});
    
    r->addIndex<1>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("arithmetic_op"), std::array<u16,1>{0}, b));
  r = db->getRelation("app");
  if (r == 0) db->addStruct("app", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("app");
      std::vector<u16> ord215({1, 2, 0});
    
    r->addIndex<3>(ord215, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord216({0, 1, 2});
    
    r->addIndex<3>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("app"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("any_bool");
  if (r == 0) db->addRelation("any_bool", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("any_bool");
      std::vector<u16> ord217({0});
    
    r->addIndex<1>(ord217, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("any_bool"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord218({1, 0});
    
    r->addIndex<2>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord219({0, 1});
    
    r->addIndex<2>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup70016x95x0x0x1");
  if (r == 0) db->addRelation("$sup70016x95x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x95x0x0x1");
      std::vector<u16> ord220({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup70016x95x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup70016x95x0x0x0");
  if (r == 0) db->addRelation("$sup70016x95x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x95x0x0x0");
      std::vector<u16> ord221({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x95x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x92x0x0x1");
  if (r == 0) db->addRelation("$sup70016x92x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x92x0x0x1");
      std::vector<u16> ord222({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup70016x92x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup70016x92x0x0x0");
  if (r == 0) db->addRelation("$sup70016x92x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x92x0x0x0");
      std::vector<u16> ord223({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord223, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x92x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x87x0x0x0");
  if (r == 0) db->addRelation("$sup70016x87x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x87x0x0x0");
      std::vector<u16> ord224({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord224, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x87x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x75x0x0x0");
  if (r == 0) db->addRelation("$sup70016x75x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x75x0x0x0");
      std::vector<u16> ord225({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup70016x75x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup70016x51x0x0x1");
  if (r == 0) db->addRelation("$sup70016x51x0x0x1", 13);
  else if (r->getArity() != 13)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord226({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    
    r->addIndex<13>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<13>(db, r, std::array<u16,13>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<13>(db, db->getRelation("$sup70016x51x0x0x1"), std::array<u16,13>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, b));
  r = db->getRelation("$sup70016x51x0x0x0");
  if (r == 0) db->addRelation("$sup70016x51x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x51x0x0x0");
      std::vector<u16> ord227({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord227, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup70016x51x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup70016x47x0x0x0");
  if (r == 0) db->addRelation("$sup70016x47x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x47x0x0x0");
      std::vector<u16> ord228({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x47x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x43x0x0x0");
  if (r == 0) db->addRelation("$sup70016x43x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x43x0x0x0");
      std::vector<u16> ord229({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord229, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup70016x43x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup70016x33x0x0x0");
  if (r == 0) db->addRelation("$sup70016x33x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup70016x33x0x0x0");
      std::vector<u16> ord230({0, 1, 2, 3});
    
    r->addIndex<4>(ord230, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup70016x33x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x98x0x0x1");
  if (r == 0) db->addRelation("$sup5638x98x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord231({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord231, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x98x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x98x0x0x0");
  if (r == 0) db->addRelation("$sup5638x98x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord232({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord232, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x98x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x95x0x0x1");
  if (r == 0) db->addRelation("$sup5638x95x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord233({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord233, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x95x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x95x0x0x0");
  if (r == 0) db->addRelation("$sup5638x95x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord234({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x95x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x93x0x0x0");
  if (r == 0) db->addRelation("$sup5638x93x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord235({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord235, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x93x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x84x0x0x0");
  if (r == 0) db->addRelation("$sup5638x84x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord236({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord236, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x84x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x82x0x0x0");
  if (r == 0) db->addRelation("$sup5638x82x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord237({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord237, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x82x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x81x0x0x0");
  if (r == 0) db->addRelation("$sup5638x81x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord238({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x81x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x68x0x0x0");
  if (r == 0) db->addRelation("$sup5638x68x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x68x0x0x0");
      std::vector<u16> ord239({0, 1, 2, 3});
    
    r->addIndex<4>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x68x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x67x0x0x0");
  if (r == 0) db->addRelation("$sup5638x67x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x67x0x0x0");
      std::vector<u16> ord240({0, 1, 2, 3});
    
    r->addIndex<4>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x67x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x62x0x0x0");
  if (r == 0) db->addRelation("$sup5638x62x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord241({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord241, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x62x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x60x0x0x0");
  if (r == 0) db->addRelation("$sup5638x60x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord242({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord242, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x60x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x59x0x0x0");
  if (r == 0) db->addRelation("$sup5638x59x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord243({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord243, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x59x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x52x0x0x0");
  if (r == 0) db->addRelation("$sup5638x52x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x52x0x0x0");
      std::vector<u16> ord244({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord244, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x52x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x51x0x0x0");
  if (r == 0) db->addRelation("$sup5638x51x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x51x0x0x0");
      std::vector<u16> ord245({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord245, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x51x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x44x0x0x0");
  if (r == 0) db->addRelation("$sup5638x44x0x0x0", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord246({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x44x0x0x0"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x42x0x0x1");
  if (r == 0) db->addRelation("$sup5638x42x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord247({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x42x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x42x0x0x0");
  if (r == 0) db->addRelation("$sup5638x42x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord248({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord248, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x42x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x40x0x0x1");
  if (r == 0) db->addRelation("$sup5638x40x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord249({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord249, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x40x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x40x0x0x0");
  if (r == 0) db->addRelation("$sup5638x40x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord250({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x40x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x2");
  if (r == 0) db->addRelation("$sup5638x29x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord251({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord251, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x29x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x29x0x0x1");
  if (r == 0) db->addRelation("$sup5638x29x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord252({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord252, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x29x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x0");
  if (r == 0) db->addRelation("$sup5638x29x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord253({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x29x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x25x0x0x2");
  if (r == 0) db->addRelation("$sup5638x25x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord254({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord254, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x25x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x25x0x0x1");
  if (r == 0) db->addRelation("$sup5638x25x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord255({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x25x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x25x0x0x0");
  if (r == 0) db->addRelation("$sup5638x25x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord256({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x25x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x127x0x0x0");
  if (r == 0) db->addRelation("$sup5638x127x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x127x0x0x0");
      std::vector<u16> ord257({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x127x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x121x0x0x0");
  if (r == 0) db->addRelation("$sup5638x121x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x121x0x0x0");
      std::vector<u16> ord258({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x121x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x110x0x0x0");
  if (r == 0) db->addRelation("$sup5638x110x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord259({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x110x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x107x0x0x1");
  if (r == 0) db->addRelation("$sup5638x107x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord260({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord260, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x107x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x107x0x0x0");
  if (r == 0) db->addRelation("$sup5638x107x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord261({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord261, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x107x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x104x0x0x1");
  if (r == 0) db->addRelation("$sup5638x104x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord262({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x104x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x104x0x0x0");
  if (r == 0) db->addRelation("$sup5638x104x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord263({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x104x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x101x0x0x0");
  if (r == 0) db->addRelation("$sup5638x101x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord264({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x101x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$seq_atr");
  if (r == 0) db->addRelation("$seq_atr", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_atr");
      std::vector<u16> ord265({0, 1, 2});
    
    r->addIndex<3>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_atr"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord266({0, 1, 2});
    
    r->addIndex<3>(ord266, false);
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
  // (crule (pre) (scan toint_range __erre02BL1623 __errf3IL21624 __errf9NrW1625) (body) (head (emit error (0) __erre02BL1623)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord1({0});
      slog::Relation* readrel2 = db->getRelation("error");
      head_index[0] = readrel2->getIndex(ord1, false);
      outer_rel = db->getRelation("toint_range");
  
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
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre0sHD1609 __errf3nJS1610 __errf3DTd1611) (body) (head (emit error (0) __erre0sHD1609)) <internal>:1 #f)
  class ReadTask3 : public slog::Task
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
      std::vector<u16> ord4({0});
      slog::Relation* readrel5 = db->getRelation("error");
      head_index[0] = readrel5->getIndex(ord4, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask3* _cont = new ReadTask3(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3(db,b), false);
  // (crule (pre (let _00024sqc7BGQ925 constd4735e3a265e16eee03f5971) (let _00024sqc57bk926 const5feceb66ffc86f38d952786c) (let _00024sqc9rCW927 const6b86b273ff34fce19d6b804e) (let _00024sqc1hAR930 const6b86b273ff34fce19d6b804e) (let _00024sqc3pqm931 const5feceb66ffc86f38d952786c) (let _00024sqc4iDu932 const6b86b273ff34fce19d6b804e) (let _00024sqc50sK933 const5feceb66ffc86f38d952786c)) (scan mp_fromlist __t3kVS414 _00024seq1) (body (letp _00024sql8R6l928 (aslst _00024seq1)) (let _00024sqn4lSW929 (llen _00024sql8R6l928)) (cmp ge _00024sqn4lSW929 _00024sqc1hAR930) (letp _00024seq0 (lref _00024sql8R6l928 _00024sqc3pqm931)) (letp _00024sql2z87923 (aslst _00024seq0)) (let chk4Ukh1639 (llen _00024sql2z87923)) (eq _00024sqc7BGQ925 chk4Ukh1639) (letp k (lref _00024sql2z87923 _00024sqc57bk926)) (letp v (lref _00024sql2z87923 _00024sqc9rCW927)) (let _00024sqp0GFu934 (_0002d _00024sqn4lSW929 _00024sqc50sK933)) (let xs (lslice _00024sql8R6l928 _00024sqc4iDu932 _00024sqp0GFu934))) (head (emit $sup5638x127x0x0x0 (0 1 2 3 4 5) _00024seq0 _00024seq1 __t3kVS414 k v xs)) map.slog:128 #f)
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
      head_rel[0] = db->getRelation("$sup5638x127x0x0x0");
      std::vector<u16> ord7({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel8 = db->getRelation("$sup5638x127x0x0x0");
      head_index[0] = readrel8->getIndex(ord7, false);
      outer_rel = db->getRelation("mp_fromlist");
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constd4735e3a265e16eee03f5971;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
      u64 v_c8 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c9 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c10 = v_const5feceb66ffc86f38d952786c;
      u64 v_c11 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c13 = _t[0];
        u64 v_c14 = _t[1];
        bool ok9 = true;
        u64 v_c15 = _prim_aslst(db, v_c14, &ok9);
        if (!ok9) return;
        u64 v_c16 = _prim_llen(db, v_c15);
        if (v_c16 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        u64 v_c17 = _prim_ge(db, v_c16, v_c9);
        if (v_c17 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        if (!v_c17) return;
        bool ok11 = true;
        u64 v_c18 = _prim_lref(db, v_c15, v_c10, &ok11);
        if (!ok11) return;
        bool ok12 = true;
        u64 v_c19 = _prim_aslst(db, v_c18, &ok12);
        if (!ok12) return;
        u64 v_c20 = _prim_llen(db, v_c19);
        if (v_c20 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        if (v_c6 != v_c20) return;
        bool ok13 = true;
        u64 v_c21 = _prim_lref(db, v_c19, v_c7, &ok13);
        if (!ok13) return;
        bool ok14 = true;
        u64 v_c22 = _prim_lref(db, v_c19, v_c8, &ok14);
        if (!ok14) return;
        u64 v_c23 = _prim__0002d(db, v_c16, v_c12);
        if (v_c23 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        u64 v_c24 = _prim_lslice(db, v_c15, v_c11, v_c23);
        if (v_c24 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        ++_fires;
        slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c18, v_c14, v_c13, v_c21, v_c22, v_c24}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_fromlist", _fires);
  
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
  // (crule (pre (let __tconst2WFL632 const6b86b273ff34fce19d6b804e)) (once) (body) (head (emit klimit (0) __tconst2WFL632)) kcfa.slog:8 #f)
  class ReadTask15 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("klimit");
      std::vector<u16> ord16({0});
      slog::Relation* readrel17 = db->getRelation("klimit");
      head_index[0] = readrel17->getIndex(ord16, false);
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:8", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), true);
  // (crule (pre) (scan nan_result __erre0spm1619 __errf1rLv1620 __errf8H9H1621 __errf20td1622) (body) (head (emit error (0) __erre0spm1619)) <internal>:1 #f)
  class ReadTask18 : public slog::Task
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
      std::vector<u16> ord19({0});
      slog::Relation* readrel20 = db->getRelation("error");
      head_index[0] = readrel20->getIndex(ord19, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c26}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
      s->addTask(phase_read, new ReadTask18(db,b), false);
  // (crule (pre (let __tconst1X2v1563 constb9e118781cea1f9fa01462e0)) (once) (body) (head (mkstruct _enum (1 0) __9fVo1564 __tconst1X2v1563)) <internal>:1 #f)
  class ReadTask21 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("_enum");
  
    }
    ReadTask21(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c30}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask21(db,b), true);
  // (crule (pre (let __tconst6tIJ16 consted725292f5f32d61535958c1) (let __tconst6PEa15 const0933fb667296882d8c45abca) (let __tconst0ASa14 const7297d2085ea0adffc396d546)) (once) (body) (head (emit arithmetic_op (0) __tconst6tIJ16) (emit arithmetic_op (0) __tconst6PEa15) (emit arithmetic_op (0) __tconst0ASa14)) interp.slog:109 #f)
  class ReadTask22 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("arithmetic_op");
      std::vector<u16> ord23({0});
      slog::Relation* readrel24 = db->getRelation("arithmetic_op");
      head_index[0] = readrel24->getIndex(ord23, false);
      head_rel[1] = db->getRelation("arithmetic_op");
      std::vector<u16> ord25({0});
      slog::Relation* readrel26 = db->getRelation("arithmetic_op");
      head_index[1] = readrel26->getIndex(ord25, false);
      head_rel[2] = db->getRelation("arithmetic_op");
      std::vector<u16> ord27({0});
      slog::Relation* readrel28 = db->getRelation("arithmetic_op");
      head_index[2] = readrel28->getIndex(ord27, false);
  
    }
    ReadTask22(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_consted725292f5f32d61535958c1;
      u64 v_c32 = v_const0933fb667296882d8c45abca;
      u64 v_c33 = v_const7297d2085ea0adffc396d546;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c31}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c32}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c33}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:109", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask22(db,b), true);
  // (crule (pre) (scan malformed_deduction __erre8UXR1604 __errf7ldI1605 __errf4zob1606 __errf0qAJ1607 __errf5QHm1608) (body) (head (emit error (0) __erre8UXR1604)) <internal>:1 #f)
  class ReadTask29 : public slog::Task
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
      std::vector<u16> ord30({0});
      slog::Relation* readrel31 = db->getRelation("error");
      head_index[0] = readrel31->getIndex(ord30, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask29(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c34 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c37 = _t[3];
        u64 v_c38 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c34}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
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
  // (crule (pre (let __tconst5hSg1567 constd01925b37634a1a9d24159d8)) (once) (body) (head (mkstruct _enum (1 0) __60RO1568 __tconst5hSg1567)) <internal>:1 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("_enum");
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask32(db,b), true);
  // (crule (pre (let __tconst0yKk589 const90fb9068eda6f2d68bb61c33) (let __tconst4Edh588 const57ba71c4b2fba1fd2fbcd814) (let __tconst46NP587 const53a56174f3826669a422fc54)) (once) (body) (head (emit comparison_op (0) __tconst0yKk589) (emit comparison_op (0) __tconst4Edh588) (emit comparison_op (0) __tconst46NP587)) interp.slog:110 #f)
  class ReadTask33 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("comparison_op");
      std::vector<u16> ord34({0});
      slog::Relation* readrel35 = db->getRelation("comparison_op");
      head_index[0] = readrel35->getIndex(ord34, false);
      head_rel[1] = db->getRelation("comparison_op");
      std::vector<u16> ord36({0});
      slog::Relation* readrel37 = db->getRelation("comparison_op");
      head_index[1] = readrel37->getIndex(ord36, false);
      head_rel[2] = db->getRelation("comparison_op");
      std::vector<u16> ord38({0});
      slog::Relation* readrel39 = db->getRelation("comparison_op");
      head_index[2] = readrel39->getIndex(ord38, false);
  
    }
    ReadTask33(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const90fb9068eda6f2d68bb61c33;
      u64 v_c41 = v_const57ba71c4b2fba1fd2fbcd814;
      u64 v_c42 = v_const53a56174f3826669a422fc54;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c40}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c41}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c42}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:110", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask33(db,b), true);
  // (crule (pre (let __tconst3Ee91565 constcd2a69ce5ca278db1d6da969)) (once) (body) (head (mkstruct _enum (1 0) __93cQ1566 __tconst3Ee91565)) <internal>:1 #f)
  class ReadTask40 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("_enum");
  
    }
    ReadTask40(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_constcd2a69ce5ca278db1d6da969;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c43}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask40(db,b), true);
  // (crule (pre (let __trid9vZa1121 const1ef5dd96b7ac876a994a9ca1) (let __trel4jtG1122 consta8648fdb04f7c50b03dd675e) (let __tcol3Dqo1123 const5feceb66ffc86f38d952786c)) (scan $sup5638x127x0x0x0 _00024seq0 _00024seq1 __d0 k v xs) (body) (head (tycheck xs (accept seq) __trid9vZa1121 __trel4jtG1122 __tcol3Dqo1123 (1 2 3 4 0)) (mkstruct mp_fromlist (1 0) __5Cay1120 xs)) map.slog:128 #f)
  class ReadTask41 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_fromlist");
      outer_rel = db->getRelation("$sup5638x127x0x0x0");
  
    }
    ReadTask41(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_const1ef5dd96b7ac876a994a9ca1;
      u64 v_c45 = v_consta8648fdb04f7c50b03dd675e;
      u64 v_c46 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c18 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c47 = _t[2];
        u64 v_c21 = _t[3];
        u64 v_c22 = _t[4];
        u64 v_c24 = _t[5];
        ++_fires;
        if (!(is_seq(v_c24)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c44, v_c45, v_c46, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:$sup5638x127x0x0x0", _fires);
  
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
  // (crule (pre) (scan mpz_overflow __erre71SJ1631 __errf6JaJ1632 __errf1Unc1633 __errf9OSW1634 __errf54G21635) (body) (head (emit error (0) __erre71SJ1631)) <internal>:1 #f)
  class ReadTask42 : public slog::Task
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
      std::vector<u16> ord43({0});
      slog::Relation* readrel44 = db->getRelation("error");
      head_index[0] = readrel44->getIndex(ord43, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask42(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c51 = _t[3];
        u64 v_c52 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c48}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask42* _cont = new ReadTask42(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask42(db,b), false);
  // (crule (pre) (scan type_mismatch __erre2dnL1626 __errf6ZkK1627 __errf5dEn1628 __errf2MA91629 __errf8UrR1630) (body) (head (emit error (0) __erre2dnL1626)) <internal>:1 #f)
  class ReadTask45 : public slog::Task
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
      std::vector<u16> ord46({0});
      slog::Relation* readrel47 = db->getRelation("error");
      head_index[0] = readrel47->getIndex(ord46, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask45(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c53 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c55 = _t[2];
        u64 v_c56 = _t[3];
        u64 v_c57 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask45* _cont = new ReadTask45(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask45(db,b), false);
  // (crule (pre) (scan int_overflow __erre3Hnp1615 __errf1mFh1616 __errf620w1617 __errf5prP1618) (body) (head (emit error (0) __erre3Hnp1615)) <internal>:1 #f)
  class ReadTask48 : public slog::Task
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
      std::vector<u16> ord49({0});
      slog::Relation* readrel50 = db->getRelation("error");
      head_index[0] = readrel50->getIndex(ord49, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c58 = _t[0];
        u64 v_c59 = _t[1];
        u64 v_c60 = _t[2];
        u64 v_c61 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c58}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask48* _cont = new ReadTask48(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask48(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre0VAN1612 __errf2B711613 __errf51wj1614) (body) (head (emit error (0) __erre0VAN1612)) <internal>:1 #f)
  class ReadTask51 : public slog::Task
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
      std::vector<u16> ord52({0});
      slog::Relation* readrel53 = db->getRelation("error");
      head_index[0] = readrel53->getIndex(ord52, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask51(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c62}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask51* _cont = new ReadTask51(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask51(db,b), false);
  // (crule (pre (let __tconst2zOS1561 const0122baa3ac55f1b433944eb1)) (once) (body) (head (mkstruct _enum (1 0) __8np51562 __tconst2zOS1561)) <internal>:1 #f)
  class ReadTask54 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("_enum");
  
    }
    ReadTask54(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c65}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask54(db,b), true);
  // (crule (pre) (scan mpz_table_overflow __erre6jmj1636 __errf1Bgn1637 __errf4kbZ1638) (body) (head (emit error (0) __erre6jmj1636)) <internal>:1 #f)
  class ReadTask55 : public slog::Task
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
      std::vector<u16> ord56({0});
      slog::Relation* readrel57 = db->getRelation("error");
      head_index[0] = readrel57->getIndex(ord56, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask55(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c66 = _t[0];
        u64 v_c67 = _t[1];
        u64 v_c68 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c66}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask55* _cont = new ReadTask55(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask55(db,b), false);
  s->addReadRel("$sup5638x127x0x0x0");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mp_fromlist");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$seq_atr");
  s->addDynamicRel("$sup5638x127x0x0x0");
  s->addDynamicRel("_enum");
  s->addDynamicRel("arithmetic_op");
  s->addDynamicRel("comparison_op");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("klimit");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mp_fromlist");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

