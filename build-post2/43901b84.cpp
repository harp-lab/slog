
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_conste7f6c011776e8db7cd330b54;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("43901b84");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_conste7f6c011776e8db7cd330b54 = s32_encode(6);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord256({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord257({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord258({1, 2, 0});
    
    r->addIndex<3>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord259({0, 1, 2});
    
    r->addIndex<3>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp7igP101");
  if (r == 0) db->addTempRelation("temp7igP101", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5uvn102");
  if (r == 0) db->addTempRelation("temp5uvn102", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1Wzv100");
  if (r == 0) db->addTempRelation("temp1Wzv100", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord260({1, 2, 0});
    
    r->addIndex<3>(ord260, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord261({0, 1, 2});
    
    r->addIndex<3>(ord261, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("shapes");
  if (r == 0) db->addRelation("shapes", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("shapes");
      std::vector<u16> ord262({0});
    
    r->addIndex<1>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("shapes"), std::array<u16,1>{0}, b));
  r = db->getRelation("rect");
  if (r == 0) db->addStruct("rect", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("rect");
      std::vector<u16> ord263({1, 2, 0});
    
    r->addIndex<3>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord264({0, 1, 2});
    
    r->addIndex<3>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord265({2, 0, 1});
    
    r->addIndex<3>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord266({1, 2, 0});
    
    r->addIndex<3>(ord266, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord267({2, 0, 1});
    
    r->addIndex<3>(ord267, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("rect"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("pt");
  if (r == 0) db->addStruct("pt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pt");
      std::vector<u16> ord268({1, 2, 0});
    
    r->addIndex<3>(ord268, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord269({0, 1, 2});
    
    r->addIndex<3>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord270({0, 1, 2});
    
    r->addIndex<3>(ord270, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord271({1, 0, 2});
    
    r->addIndex<3>(ord271, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("pt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord272({1, 2, 3, 0});
    
    r->addIndex<4>(ord272, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord273({0, 1, 2, 3});
    
    r->addIndex<4>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord274({1, 2, 0});
    
    r->addIndex<3>(ord274, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord275({0, 1, 2});
    
    r->addIndex<3>(ord275, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord276({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord276, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord277({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord278({1, 2, 0});
    
    r->addIndex<3>(ord278, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord279({0, 1, 2});
    
    r->addIndex<3>(ord279, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord280({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord281({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord282({1, 2, 3, 0});
    
    r->addIndex<4>(ord282, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord283({0, 1, 2, 3});
    
    r->addIndex<4>(ord283, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord284({0});
    
    r->addIndex<1>(ord284, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord285({1, 2, 0});
    
    r->addIndex<3>(ord285, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord286({0, 1, 2});
    
    r->addIndex<3>(ord286, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("circle");
  if (r == 0) db->addStruct("circle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("circle");
      std::vector<u16> ord287({1, 2, 0});
    
    r->addIndex<3>(ord287, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord288({0, 1, 2});
    
    r->addIndex<3>(ord288, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord289({2, 0, 1});
    
    r->addIndex<3>(ord289, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord290({1, 2, 0});
    
    r->addIndex<3>(ord290, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("circle"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("centery");
  if (r == 0) db->addRelation("centery", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("centery");
      std::vector<u16> ord291({0, 1});
    
    r->addIndex<2>(ord291, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("centery"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("centerx");
  if (r == 0) db->addRelation("centerx", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("centerx");
      std::vector<u16> ord292({0, 1, 2});
    
    r->addIndex<3>(ord292, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("centerx"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("center_ans");
  if (r == 0) db->addRelation("center_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("center_ans");
      std::vector<u16> ord293({0, 1});
    
    r->addIndex<2>(ord293, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("center_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("center");
  if (r == 0) db->addStruct("center", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("center");
      std::vector<u16> ord294({1, 0});
    
    r->addIndex<2>(ord294, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord295({0, 1});
    
    r->addIndex<2>(ord295, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord296({1, 0});
    
    r->addIndex<2>(ord296, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("center"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord297({1, 0});
    
    r->addIndex<2>(ord297, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord298({0, 1});
    
    r->addIndex<2>(ord298, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst8PFH17 const6b86b273ff34fce19d6b804e) (let __tconst7ikL19 constd4735e3a265e16eee03f5971) (let __tconst3JzW22 conste7f6c011776e8db7cd330b54) (let __tconst2yNa23 const4b227777d4dd1fc61c6f884f) (let __tconst2dvT26 const5feceb66ffc86f38d952786c)) (seeded) (body (join pt (1 2 0) 2 __tconst2yNa23 __tconst3JzW22 __t8toC24) (exists pt (1 2 0) 1 __tconst2dvT26) (join pt (1 2 0) 2 __tconst7ikL19 __tconst2yNa23 __t5hsY20) (join pt (1 2 0) 1 __tconst2dvT26 dup9uQJ104 __t7JfT27) (eq __tconst2dvT26 dup9uQJ104)) (head (mkstruct circle (1 2 0) __t1eeB21 __t5hsY20 __tconst8PFH17) (mkstruct rect (1 2 0) __t420d28 __t7JfT27 __t8toC24)) dem_alias.slog:18 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** ptindex0;  slog::Index** ptindex1;  slog::Index** ptindex2;  slog::Index** ptindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("circle");
      std::vector<u16> ord5({1, 2, 0});
      slog::Relation* readrel6 = db->getRelation("circle");
      head_index[0] = readrel6->getIndex(ord5, false);
      head_rel[1] = db->getRelation("rect");
      std::vector<u16> ord7({1, 2, 0});
      slog::Relation* readrel8 = db->getRelation("rect");
      head_index[1] = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({1, 2, 0});
      slog::Relation* readrel10 = db->getRelation("pt");
      ptindex0 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({1, 2, 0});
      slog::Relation* readrel12 = db->getRelation("pt");
      ptindex1 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({1, 2, 0});
      slog::Relation* readrel14 = db->getRelation("pt");
      ptindex2 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({1, 2, 0});
      slog::Relation* readrel16 = db->getRelation("pt");
      ptindex3 = readrel16->getIndex(ord15, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c3 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<3,2>(ptindex0, std::array<u64,3>{v_c3, v_c2, 0}, [&](const std::array<u64,3>& m17) {
        u64 v_c5 = m17[2];
        if (!slog::exists_probe<3,1>(ptindex1, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<3,2>(ptindex2, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m18) {
          u64 v_c6 = m18[2];
          slog::join_probe<3,1>(ptindex3, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m19) {
            u64 v_c7 = m19[1]; u64 v_c8 = m19[2];
            if (v_c4 != v_c7) return;
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c0}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c8, v_c5}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_alias.slog:18", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask4(db,b));
  // (crule (pre) (scan modulo_by_zero __erre30gU73 __errf1xeS74 __errf3qun75) (body) (head (emit error (0) __erre30gU73)) <internal>:1 #f)
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
      outer_rel = db->getRelation("modulo_by_zero");
  
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
        u64 v_c9 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
  // (crule (pre (let __tconst7ZpN6 constd4735e3a265e16eee03f5971)) (scan center __t8eiQ13 __t54o512) (body (join rect (0 1 2) 1 __t54o512 __t3N3A11 __t8qZV10) (join pt (0 1 2) 1 __t8qZV10 x1 y1) (join pt (0 1 2) 1 __t3N3A11 x0 y0) (let __t4LE84 (_0002b y0 y1)) (let __t43d97 (_0002b x0 x1))) (head (emit-temp temp1Wzv100 __t43d97 __t4LE84 __t8eiQ13)) dem_alias.slog:15 #f)
  class ReadTask26 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** rectindex23;  slog::Index** ptindex24;  slog::Index** ptindex25;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Wzv100");
      outer_rel = db->getRelation("center");
      std::vector<u16> ord27({0, 1, 2});
      slog::Relation* readrel28 = db->getRelation("rect");
      rectindex23 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({0, 1, 2});
      slog::Relation* readrel30 = db->getRelation("pt");
      ptindex24 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({0, 1, 2});
      slog::Relation* readrel32 = db->getRelation("pt");
      ptindex25 = readrel32->getIndex(ord31, false);
  
    }
    ReadTask26(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
  
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
        slog::join_probe<3,1>(rectindex23, std::array<u64,3>{v_c14, 0, 0}, [&](const std::array<u64,3>& m33) {
          u64 v_c15 = m33[1]; u64 v_c16 = m33[2];
          slog::join_probe<3,1>(ptindex24, std::array<u64,3>{v_c16, 0, 0}, [&](const std::array<u64,3>& m34) {
            u64 v_c17 = m34[1]; u64 v_c18 = m34[2];
            slog::join_probe<3,1>(ptindex25, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m35) {
              u64 v_c19 = m35[1]; u64 v_c20 = m35[2];
              u64 v_c21 = _prim__0002b(db, v_c20, v_c18);
              if (v_c21 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
              u64 v_c22 = _prim__0002b(db, v_c19, v_c17);
              if (v_c22 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
              ++_fires;
              slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c22, v_c21, v_c13});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:15", "delta:center", _fires);
  
      if (!_done)
      {
        ReadTask26* _cont = new ReadTask26(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask26(db,b), false);
  // (crule (pre) (scan nan_result __erre3uNX80 __errf6Wf481 __errf9URQ82 __errf5RiM83) (body) (head (emit error (0) __erre3uNX80)) <internal>:1 #f)
  class ReadTask36 : public slog::Task
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
      std::vector<u16> ord37({0});
      slog::Relation* readrel38 = db->getRelation("error");
      head_index[0] = readrel38->getIndex(ord37, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask36(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask36* _cont = new ReadTask36(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask36(db,b), false);
  // (crule (pre) (scan toint_range __erre4CRW84 __errf9HW585 __errf2LQS86) (body) (head (emit error (0) __erre4CRW84)) <internal>:1 #f)
  class ReadTask39 : public slog::Task
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
      std::vector<u16> ord40({0});
      slog::Relation* readrel41 = db->getRelation("error");
      head_index[0] = readrel41->getIndex(ord40, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask39(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre7VqG76 __errf39Xy77 __errf2fsX78 __errf1EgG79) (body) (head (emit error (0) __erre7VqG76)) <internal>:1 #f)
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
      outer_rel = db->getRelation("int_overflow");
  
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
        u64 v_c30 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c32 = _t[2];
        u64 v_c33 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c30}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
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
  // (crule (pre (let __tconst7ZpN6 constd4735e3a265e16eee03f5971)) (scan temp1Wzv100 __t43d97 __t4LE84 __t8eiQ13) (body (let __t0Mlo5 (_0002f __t4LE84 __tconst7ZpN6)) (let __t8U2s8 (_0002f __t43d97 __tconst7ZpN6))) (head (emit-temp temp7igP101 __t0Mlo5 __t8U2s8 __t8eiQ13)) dem_alias.slog:15 #f)
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
      head_rel[0] = db->getRelation("temp7igP101");
      outer_rel = db->getRelation("temp1Wzv100");
  
    }
    ReadTask45(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c34 = _prim__0002f(db, v_c21, v_c12);
        if (v_c34 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
        u64 v_c35 = _prim__0002f(db, v_c22, v_c12);
        if (v_c35 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c34, v_c35, v_c13});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:15", "delta:temp1Wzv100", _fires);
  
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
  // (crule (pre (let __tconst8PFH17 const6b86b273ff34fce19d6b804e) (let __tconst7ikL19 constd4735e3a265e16eee03f5971) (let __tconst3JzW22 conste7f6c011776e8db7cd330b54) (let __tconst2yNa23 const4b227777d4dd1fc61c6f884f) (let __tconst2dvT26 const5feceb66ffc86f38d952786c)) (seeded) (body (join pt (1 2 0) 2 __tconst2yNa23 __tconst3JzW22 __t8toC24) (exists circle (2 0 1) 1 __tconst8PFH17) (exists pt (1 2 0) 1 __tconst2dvT26) (exists rect (2 0 1) 1 __t8toC24) (join pt (1 2 0) 2 __tconst7ikL19 __tconst2yNa23 __t5hsY20) (join circle (1 2 0) 2 __t5hsY20 __tconst8PFH17 __t1eeB21) (join pt (1 2 0) 1 __tconst2dvT26 dup8V72106 __t7JfT27) (eq __tconst2dvT26 dup8V72106) (join rect (1 2 0) 2 __t7JfT27 __t8toC24 __t420d28)) (head (emit shapes (0) __t1eeB21) (emit shapes (0) __t420d28)) dem_alias.slog:18 #f)
  class ReadTask54 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** ptindex46;  slog::Index** circleindex47;  slog::Index** ptindex48;  slog::Index** rectindex49;  slog::Index** ptindex50;  slog::Index** circleindex51;  slog::Index** ptindex52;  slog::Index** rectindex53;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("shapes");
      std::vector<u16> ord55({0});
      slog::Relation* readrel56 = db->getRelation("shapes");
      head_index[0] = readrel56->getIndex(ord55, false);
      head_rel[1] = db->getRelation("shapes");
      std::vector<u16> ord57({0});
      slog::Relation* readrel58 = db->getRelation("shapes");
      head_index[1] = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("pt");
      ptindex46 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({2, 0, 1});
      slog::Relation* readrel62 = db->getRelation("circle");
      circleindex47 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 2, 0});
      slog::Relation* readrel64 = db->getRelation("pt");
      ptindex48 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({2, 0, 1});
      slog::Relation* readrel66 = db->getRelation("rect");
      rectindex49 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({1, 2, 0});
      slog::Relation* readrel68 = db->getRelation("pt");
      ptindex50 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 2, 0});
      slog::Relation* readrel70 = db->getRelation("circle");
      circleindex51 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({1, 2, 0});
      slog::Relation* readrel72 = db->getRelation("pt");
      ptindex52 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 2, 0});
      slog::Relation* readrel74 = db->getRelation("rect");
      rectindex53 = readrel74->getIndex(ord73, false);
  
    }
    ReadTask54(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c3 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<3,2>(ptindex46, std::array<u64,3>{v_c3, v_c2, 0}, [&](const std::array<u64,3>& m75) {
        u64 v_c5 = m75[2];
        if (!slog::exists_probe<3,1>(circleindex47, std::array<u64,3>{v_c0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ptindex48, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(rectindex49, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<3,2>(ptindex50, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m76) {
          u64 v_c6 = m76[2];
          slog::join_probe<3,2>(circleindex51, std::array<u64,3>{v_c6, v_c0, 0}, [&](const std::array<u64,3>& m77) {
            u64 v_c36 = m77[2];
            slog::join_probe<3,1>(ptindex52, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m78) {
              u64 v_c37 = m78[1]; u64 v_c8 = m78[2];
              if (v_c4 != v_c37) return;
              slog::join_probe<3,2>(rectindex53, std::array<u64,3>{v_c8, v_c5, 0}, [&](const std::array<u64,3>& m79) {
                u64 v_c38 = m79[2];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c36}, std::array<u16,1>{0});
                slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c38}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_alias.slog:18", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask54(db,b));
  // (crule (pre) (scan div_by_zero __erre4Hoo70 __errf7MV971 __errf0Q1E72) (body) (head (emit error (0) __erre4Hoo70)) <internal>:1 #f)
  class ReadTask80 : public slog::Task
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
      std::vector<u16> ord81({0});
      slog::Relation* readrel82 = db->getRelation("error");
      head_index[0] = readrel82->getIndex(ord81, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask80(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c41 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask80* _cont = new ReadTask80(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask80(db,b), false);
  // (crule (pre) (scan center __t8x5r31 __t7pXO30) (body (join circle (0 1 2) 1 __t7pXO30 __t9SVu29 ____2Se532) (join pt (0 1 2) 1 __t9SVu29 ____9PH033 ____8XjR34)) (head (emit center_ans (0 1) __t8x5r31 __t9SVu29)) dem_alias.slog:14 #f)
  class ReadTask85 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** circleindex83;  slog::Index** ptindex84;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("center_ans");
      std::vector<u16> ord86({0, 1});
      slog::Relation* readrel87 = db->getRelation("center_ans");
      head_index[0] = readrel87->getIndex(ord86, false);
      outer_rel = db->getRelation("center");
      std::vector<u16> ord88({0, 1, 2});
      slog::Relation* readrel89 = db->getRelation("circle");
      circleindex83 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({0, 1, 2});
      slog::Relation* readrel91 = db->getRelation("pt");
      ptindex84 = readrel91->getIndex(ord90, false);
  
    }
    ReadTask85(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c42 = _t[0];
        u64 v_c43 = _t[1];
        slog::join_probe<3,1>(circleindex83, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m92) {
          u64 v_c44 = m92[1]; u64 v_c45 = m92[2];
          slog::join_probe<3,1>(ptindex84, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m93) {
            u64 v_c46 = m93[1]; u64 v_c47 = m93[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c42, v_c44}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:14", "delta:center", _fires);
  
      if (!_done)
      {
        ReadTask85* _cont = new ReadTask85(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask85(db,b), false);
  // (crule (pre) (scan shapes s) (body) (head (mkstruct center (1 0) __7Zzc38 s)) dem_alias.slog:23 #f)
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
      head_rel[0] = db->getRelation("center");
      outer_rel = db->getRelation("shapes");
  
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
        u64 v_c48 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c48}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:23", "delta:shapes", _fires);
  
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
  // (crule (pre) (scan pt __t1ld11 ____9egH2 y) (body (join shapes (0) 0 s)) (head (mkstruct center (1 0) __2Klc39 s)) dem_alias.slog:27 #f)
  class ReadTask96 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** shapesindex95;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("center");
      outer_rel = db->getRelation("pt");
      std::vector<u16> ord97({0});
      slog::Relation* readrel98 = db->getRelation("shapes");
      shapesindex95 = readrel98->getIndex(ord97, false);
  
    }
    ReadTask96(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c51 = _t[2];
        slog::join_all<1>(shapesindex95, [&](const std::array<u64,1>& m99) {
          u64 v_c48 = m99[0];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c48}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:27", "delta:pt", _fires);
  
      if (!_done)
      {
        ReadTask96* _cont = new ReadTask96(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask96(db,b), false);
  // (crule (pre) (scan type_mismatch __erre4YbK87 __errf3x9z88 __errf4kz689 __errf3s2290 __errf2ajB91) (body) (head (emit error (0) __erre4YbK87)) <internal>:1 #f)
  class ReadTask100 : public slog::Task
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
      std::vector<u16> ord101({0});
      slog::Relation* readrel102 = db->getRelation("error");
      head_index[0] = readrel102->getIndex(ord101, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask100(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c54 = _t[2];
        u64 v_c55 = _t[3];
        u64 v_c56 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c52}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask100* _cont = new ReadTask100(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask100(db,b), false);
  // (crule (pre) (scan temp7igP101 __t0Mlo5 __t8U2s8 __t8eiQ13) (body) (head (emit-temp temp5uvn102 __t0Mlo5 __t8U2s8 __t8eiQ13) (mkstruct pt (1 2 0) __t8Tqd9 __t8U2s8 __t0Mlo5)) dem_alias.slog:15 #f)
  class ReadTask103 : public slog::Task
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
      head_rel[0] = db->getRelation("temp5uvn102");
      head_rel[1] = db->getRelation("pt");
      outer_rel = db->getRelation("temp7igP101");
  
    }
    ReadTask103(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c34 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c13 = _t[2];
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c34, v_c35, v_c13});
        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c35, v_c34}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_alias.slog:15", "delta:temp7igP101", _fires);
  
      if (!_done)
      {
        ReadTask103* _cont = new ReadTask103(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask103(db,b), false);
  // (crule (pre (let __tconst7ZpN6 constd4735e3a265e16eee03f5971)) (scan rect __t54o512 __t3N3A11 __t8qZV10) (body (join-old center (1 0) 1 (1 0) __t54o512 __t8eiQ13) (join pt (0 1 2) 1 __t8qZV10 x1 y1) (join pt (0 1 2) 1 __t3N3A11 x0 y0) (let __t4LE84 (_0002b y0 y1)) (let __t43d97 (_0002b x0 x1))) (head (emit-temp temp1Wzv100 __t43d97 __t4LE84 __t8eiQ13)) dem_alias.slog:15 #f)
  class ReadTask108 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** centerindex104;  slog::Index** ptindex105;  slog::Index** ptindex106;  slog::Index** centerdelta107;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Wzv100");
      outer_rel = db->getRelation("rect");
      std::vector<u16> ord109({1, 0});
      slog::Relation* readrel110 = db->getRelation("center");
      centerindex104 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 0});
      slog::Relation* readrel112 = db->getRelation("center");
      centerdelta107 = readrel112->getIndex(ord111, true);
      std::vector<u16> ord113({0, 1, 2});
      slog::Relation* readrel114 = db->getRelation("pt");
      ptindex105 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 1, 2});
      slog::Relation* readrel116 = db->getRelation("pt");
      ptindex106 = readrel116->getIndex(ord115, false);
  
    }
    ReadTask108(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c14 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c16 = _t[2];
        slog::join_probe_old<2,1>(centerindex104, centerdelta107, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m117) {
          u64 v_c13 = m117[1];
          slog::join_probe<3,1>(ptindex105, std::array<u64,3>{v_c16, 0, 0}, [&](const std::array<u64,3>& m118) {
            u64 v_c17 = m118[1]; u64 v_c18 = m118[2];
            slog::join_probe<3,1>(ptindex106, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m119) {
              u64 v_c19 = m119[1]; u64 v_c20 = m119[2];
              u64 v_c21 = _prim__0002b(db, v_c20, v_c18);
              if (v_c21 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
              u64 v_c22 = _prim__0002b(db, v_c19, v_c17);
              if (v_c22 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
              ++_fires;
              slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c22, v_c21, v_c13});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:15", "delta:rect", _fires);
  
      if (!_done)
      {
        ReadTask108* _cont = new ReadTask108(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask108(db,b), false);
  // (crule (pre (let __tconst8PFH17 const6b86b273ff34fce19d6b804e) (let __tconst7ikL19 constd4735e3a265e16eee03f5971) (let __tconst3JzW22 conste7f6c011776e8db7cd330b54) (let __tconst2yNa23 const4b227777d4dd1fc61c6f884f) (let __tconst2dvT26 const5feceb66ffc86f38d952786c)) (probe pt (1 0 2) 1 __tconst2dvT26 __t7JfT27 dup9Dn7103) (body (eq __tconst2dvT26 dup9Dn7103) (exists pt (1 2 0) 2 __tconst7ikL19 __tconst2yNa23) (join pt (1 2 0) 2 __tconst2yNa23 __tconst3JzW22 __t8toC24) (join pt (1 2 0) 2 __tconst7ikL19 __tconst2yNa23 __t5hsY20)) (head (mkstruct circle (1 2 0) __t1eeB21 __t5hsY20 __tconst8PFH17) (mkstruct rect (1 2 0) __t420d28 __t7JfT27 __t8toC24)) dem_alias.slog:18 #f)
  class ReadTask123 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** ptindex120;  slog::Index** ptindex121;  slog::Index** ptindex122;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("circle");
      head_rel[1] = db->getRelation("rect");
      std::vector<u16> ord124({1, 0, 2});
      slog::Relation* readrel125 = db->getRelation("pt");
      driver_index = readrel125->getIndex(ord124, true);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("pt");
      ptindex120 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("pt");
      ptindex121 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 2, 0});
      slog::Relation* readrel131 = db->getRelation("pt");
      ptindex122 = readrel131->getIndex(ord130, false);
  
    }
    ReadTask123(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c3 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c4, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m132) {
        u64 v_c8 = m132[1];
        u64 v_c57 = m132[2];
        if (buckethash(v_c8) != bucket) return;
        if (v_c4 != v_c57) return;
        if (!slog::exists_probe<3,2>(ptindex120, std::array<u64,3>{v_c1, v_c3, 0})) return;
        slog::join_probe<3,2>(ptindex121, std::array<u64,3>{v_c3, v_c2, 0}, [&](const std::array<u64,3>& m133) {
          u64 v_c5 = m133[2];
          slog::join_probe<3,2>(ptindex122, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m134) {
            u64 v_c6 = m134[2];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c6, v_c0}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c8, v_c5}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_alias.slog:18", "delta:pt", _fires);
  
      if (!_done)
      {
        ReadTask123* _cont = new ReadTask123(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask123(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre76Lw97 __errf5WnS98 __errf8Q7899) (body) (head (emit error (0) __erre76Lw97)) <internal>:1 #f)
  class ReadTask135 : public slog::Task
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
      std::vector<u16> ord136({0});
      slog::Relation* readrel137 = db->getRelation("error");
      head_index[0] = readrel137->getIndex(ord136, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask135(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c58}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask135* _cont = new ReadTask135(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask135(db,b), false);
  // (crule (pre) (scan shapes s) (body (join-old pt (0 1 2) 0 (0 1 2) __t1ld11 ____9egH2 y)) (head (mkstruct center (1 0) __2Klc39 s)) dem_alias.slog:27 #f)
  class ReadTask140 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ptindex138;  slog::Index** ptdelta139;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("center");
      outer_rel = db->getRelation("shapes");
      std::vector<u16> ord141({0, 1, 2});
      slog::Relation* readrel142 = db->getRelation("pt");
      ptindex138 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({0, 1, 2});
      slog::Relation* readrel144 = db->getRelation("pt");
      ptdelta139 = readrel144->getIndex(ord143, true);
  
    }
    ReadTask140(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_all_old<3>(ptindex138, ptdelta139, [&](const std::array<u64,3>& m145) {
          u64 v_c49 = m145[0]; u64 v_c50 = m145[1]; u64 v_c51 = m145[2];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c48}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:27", "delta:shapes", _fires);
  
      if (!_done)
      {
        ReadTask140* _cont = new ReadTask140(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask140(db,b), false);
  // (crule (pre (let __tconst7ZpN6 constd4735e3a265e16eee03f5971)) (scan pt __t8qZV10 x1 y1) (body (join-old rect (2 0 1) 1 (2 0 1) __t8qZV10 __t54o512 __t3N3A11) (join-old center (1 0) 1 (1 0) __t54o512 __t8eiQ13) (join-old pt (0 1 2) 1 (0 1 2) __t3N3A11 x0 y0) (let __t4LE84 (_0002b y0 y1)) (let __t43d97 (_0002b x0 x1))) (head (emit-temp temp1Wzv100 __t43d97 __t4LE84 __t8eiQ13)) dem_alias.slog:15 #f)
  class ReadTask152 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** rectindex146;  slog::Index** centerindex147;  slog::Index** ptindex148;  slog::Index** rectdelta149;  slog::Index** centerdelta150;  slog::Index** ptdelta151;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Wzv100");
      outer_rel = db->getRelation("pt");
      std::vector<u16> ord153({2, 0, 1});
      slog::Relation* readrel154 = db->getRelation("rect");
      rectindex146 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({2, 0, 1});
      slog::Relation* readrel156 = db->getRelation("rect");
      rectdelta149 = readrel156->getIndex(ord155, true);
      std::vector<u16> ord157({1, 0});
      slog::Relation* readrel158 = db->getRelation("center");
      centerindex147 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 0});
      slog::Relation* readrel160 = db->getRelation("center");
      centerdelta150 = readrel160->getIndex(ord159, true);
      std::vector<u16> ord161({0, 1, 2});
      slog::Relation* readrel162 = db->getRelation("pt");
      ptindex148 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({0, 1, 2});
      slog::Relation* readrel164 = db->getRelation("pt");
      ptdelta151 = readrel164->getIndex(ord163, true);
  
    }
    ReadTask152(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c16 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c18 = _t[2];
        slog::join_probe_old<3,1>(rectindex146, rectdelta149, std::array<u64,3>{v_c16, 0, 0}, [&](const std::array<u64,3>& m165) {
          u64 v_c14 = m165[1]; u64 v_c15 = m165[2];
          slog::join_probe_old<2,1>(centerindex147, centerdelta150, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m166) {
            u64 v_c13 = m166[1];
            slog::join_probe_old<3,1>(ptindex148, ptdelta151, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m167) {
              u64 v_c19 = m167[1]; u64 v_c20 = m167[2];
              u64 v_c21 = _prim__0002b(db, v_c20, v_c18);
              if (v_c21 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
              u64 v_c22 = _prim__0002b(db, v_c19, v_c17);
              if (v_c22 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
              ++_fires;
              slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c22, v_c21, v_c13});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:15", "delta:pt", _fires);
  
      if (!_done)
      {
        ReadTask152* _cont = new ReadTask152(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask152(db,b), false);
  // (crule (pre (let __tconst8PFH17 const6b86b273ff34fce19d6b804e) (let __tconst7ikL19 constd4735e3a265e16eee03f5971) (let __tconst3JzW22 conste7f6c011776e8db7cd330b54) (let __tconst2yNa23 const4b227777d4dd1fc61c6f884f) (let __tconst2dvT26 const5feceb66ffc86f38d952786c)) (scan rect __t420d28 __t7JfT27 __t8toC24) (body (join pt (0 1 2) 3 __t8toC24 __tconst2yNa23 __tconst3JzW22) (exists pt (1 2 0) 2 __tconst7ikL19 __tconst2yNa23) (exists circle (2 0 1) 1 __tconst8PFH17) (join pt (0 1 2) 2 __t7JfT27 __tconst2dvT26 dup8HWa105) (eq __tconst2dvT26 dup8HWa105) (join pt (1 2 0) 2 __tconst7ikL19 __tconst2yNa23 __t5hsY20) (join circle (1 2 0) 2 __t5hsY20 __tconst8PFH17 __t1eeB21)) (head (emit shapes (0) __t1eeB21) (emit shapes (0) __t420d28)) dem_alias.slog:18 #f)
  class ReadTask174 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ptindex168;  slog::Index** ptindex169;  slog::Index** circleindex170;  slog::Index** ptindex171;  slog::Index** ptindex172;  slog::Index** circleindex173;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("shapes");
      std::vector<u16> ord175({0});
      slog::Relation* readrel176 = db->getRelation("shapes");
      head_index[0] = readrel176->getIndex(ord175, false);
      head_rel[1] = db->getRelation("shapes");
      std::vector<u16> ord177({0});
      slog::Relation* readrel178 = db->getRelation("shapes");
      head_index[1] = readrel178->getIndex(ord177, false);
      outer_rel = db->getRelation("rect");
      std::vector<u16> ord179({0, 1, 2});
      slog::Relation* readrel180 = db->getRelation("pt");
      ptindex168 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("pt");
      ptindex169 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({2, 0, 1});
      slog::Relation* readrel184 = db->getRelation("circle");
      circleindex170 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({0, 1, 2});
      slog::Relation* readrel186 = db->getRelation("pt");
      ptindex171 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 2, 0});
      slog::Relation* readrel188 = db->getRelation("pt");
      ptindex172 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 2, 0});
      slog::Relation* readrel190 = db->getRelation("circle");
      circleindex173 = readrel190->getIndex(ord189, false);
  
    }
    ReadTask174(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c3 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe<3,3>(ptindex168, std::array<u64,3>{v_c5, v_c3, v_c2}, [&](const std::array<u64,3>& m191) {
          if (!slog::exists_probe<3,2>(ptindex169, std::array<u64,3>{v_c1, v_c3, 0})) return;
          if (!slog::exists_probe<3,1>(circleindex170, std::array<u64,3>{v_c0, 0, 0})) return;
          slog::join_probe<3,2>(ptindex171, std::array<u64,3>{v_c8, v_c4, 0}, [&](const std::array<u64,3>& m192) {
            u64 v_c61 = m192[2];
            if (v_c4 != v_c61) return;
            slog::join_probe<3,2>(ptindex172, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m193) {
              u64 v_c6 = m193[2];
              slog::join_probe<3,2>(circleindex173, std::array<u64,3>{v_c6, v_c0, 0}, [&](const std::array<u64,3>& m194) {
                u64 v_c36 = m194[2];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c36}, std::array<u16,1>{0});
                slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c38}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_alias.slog:18", "delta:rect", _fires);
  
      if (!_done)
      {
        ReadTask174* _cont = new ReadTask174(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask174(db,b), false);
  // (crule (pre (let __tconst7ZpN6 constd4735e3a265e16eee03f5971)) (scan pt __t3N3A11 x0 y0) (body (join-old rect (1 2 0) 1 (1 2 0) __t3N3A11 __t8qZV10 __t54o512) (join-old center (1 0) 1 (1 0) __t54o512 __t8eiQ13) (join pt (0 1 2) 1 __t8qZV10 x1 y1) (let __t4LE84 (_0002b y0 y1)) (let __t43d97 (_0002b x0 x1))) (head (emit-temp temp1Wzv100 __t43d97 __t4LE84 __t8eiQ13)) dem_alias.slog:15 #f)
  class ReadTask200 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** rectindex195;  slog::Index** centerindex196;  slog::Index** ptindex197;  slog::Index** rectdelta198;  slog::Index** centerdelta199;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Wzv100");
      outer_rel = db->getRelation("pt");
      std::vector<u16> ord201({1, 2, 0});
      slog::Relation* readrel202 = db->getRelation("rect");
      rectindex195 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({1, 2, 0});
      slog::Relation* readrel204 = db->getRelation("rect");
      rectdelta198 = readrel204->getIndex(ord203, true);
      std::vector<u16> ord205({1, 0});
      slog::Relation* readrel206 = db->getRelation("center");
      centerindex196 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 0});
      slog::Relation* readrel208 = db->getRelation("center");
      centerdelta199 = readrel208->getIndex(ord207, true);
      std::vector<u16> ord209({0, 1, 2});
      slog::Relation* readrel210 = db->getRelation("pt");
      ptindex197 = readrel210->getIndex(ord209, false);
  
    }
    ReadTask200(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c15 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c20 = _t[2];
        slog::join_probe_old<3,1>(rectindex195, rectdelta198, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m211) {
          u64 v_c16 = m211[1]; u64 v_c14 = m211[2];
          slog::join_probe_old<2,1>(centerindex196, centerdelta199, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m212) {
            u64 v_c13 = m212[1];
            slog::join_probe<3,1>(ptindex197, std::array<u64,3>{v_c16, 0, 0}, [&](const std::array<u64,3>& m213) {
              u64 v_c17 = m213[1]; u64 v_c18 = m213[2];
              u64 v_c21 = _prim__0002b(db, v_c20, v_c18);
              if (v_c21 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
              u64 v_c22 = _prim__0002b(db, v_c19, v_c17);
              if (v_c22 == slog_error) { slog::emit_pending_error(db, "dem_alias.slog:15"); return; }
              ++_fires;
              slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c22, v_c21, v_c13});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:15", "delta:pt", _fires);
  
      if (!_done)
      {
        ReadTask200* _cont = new ReadTask200(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask200(db,b), false);
  // (crule (pre) (scan circle __t7pXO30 __t9SVu29 ____2Se532) (body (join-old center (1 0) 1 (1 0) __t7pXO30 __t8x5r31) (join pt (0 1 2) 1 __t9SVu29 ____9PH033 ____8XjR34)) (head (emit center_ans (0 1) __t8x5r31 __t9SVu29)) dem_alias.slog:14 #f)
  class ReadTask217 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** centerindex214;  slog::Index** ptindex215;  slog::Index** centerdelta216;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("center_ans");
      std::vector<u16> ord218({0, 1});
      slog::Relation* readrel219 = db->getRelation("center_ans");
      head_index[0] = readrel219->getIndex(ord218, false);
      outer_rel = db->getRelation("circle");
      std::vector<u16> ord220({1, 0});
      slog::Relation* readrel221 = db->getRelation("center");
      centerindex214 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 0});
      slog::Relation* readrel223 = db->getRelation("center");
      centerdelta216 = readrel223->getIndex(ord222, true);
      std::vector<u16> ord224({0, 1, 2});
      slog::Relation* readrel225 = db->getRelation("pt");
      ptindex215 = readrel225->getIndex(ord224, false);
  
    }
    ReadTask217(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(centerindex214, centerdelta216, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m226) {
          u64 v_c42 = m226[1];
          slog::join_probe<3,1>(ptindex215, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m227) {
            u64 v_c46 = m227[1]; u64 v_c47 = m227[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c42, v_c44}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:14", "delta:circle", _fires);
  
      if (!_done)
      {
        ReadTask217* _cont = new ReadTask217(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask217(db,b), false);
  // (crule (pre) (scan pt __t9SVu29 ____9PH033 ____8XjR34) (body (join-old circle (1 2 0) 1 (1 2 0) __t9SVu29 ____2Se532 __t7pXO30) (join-old center (1 0) 1 (1 0) __t7pXO30 __t8x5r31)) (head (emit center_ans (0 1) __t8x5r31 __t9SVu29)) dem_alias.slog:14 #f)
  class ReadTask232 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** circleindex228;  slog::Index** centerindex229;  slog::Index** circledelta230;  slog::Index** centerdelta231;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("center_ans");
      std::vector<u16> ord233({0, 1});
      slog::Relation* readrel234 = db->getRelation("center_ans");
      head_index[0] = readrel234->getIndex(ord233, false);
      outer_rel = db->getRelation("pt");
      std::vector<u16> ord235({1, 2, 0});
      slog::Relation* readrel236 = db->getRelation("circle");
      circleindex228 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 0});
      slog::Relation* readrel238 = db->getRelation("circle");
      circledelta230 = readrel238->getIndex(ord237, true);
      std::vector<u16> ord239({1, 0});
      slog::Relation* readrel240 = db->getRelation("center");
      centerindex229 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({1, 0});
      slog::Relation* readrel242 = db->getRelation("center");
      centerdelta231 = readrel242->getIndex(ord241, true);
  
    }
    ReadTask232(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[0];
        u64 v_c46 = _t[1];
        u64 v_c47 = _t[2];
        slog::join_probe_old<3,1>(circleindex228, circledelta230, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m243) {
          u64 v_c45 = m243[1]; u64 v_c43 = m243[2];
          slog::join_probe_old<2,1>(centerindex229, centerdelta231, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m244) {
            u64 v_c42 = m244[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c42, v_c44}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:14", "delta:pt", _fires);
  
      if (!_done)
      {
        ReadTask232* _cont = new ReadTask232(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask232(db,b), false);
  // (crule (pre) (scan temp5uvn102 __t0Mlo5 __t8U2s8 __t8eiQ13) (body (join pt (1 2 0) 2 __t8U2s8 __t0Mlo5 __t8Tqd9)) (head (emit center_ans (0 1) __t8eiQ13 __t8Tqd9)) dem_alias.slog:15 #f)
  class ReadTask246 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ptindex245;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("center_ans");
      std::vector<u16> ord247({0, 1});
      slog::Relation* readrel248 = db->getRelation("center_ans");
      head_index[0] = readrel248->getIndex(ord247, false);
      outer_rel = db->getRelation("temp5uvn102");
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("pt");
      ptindex245 = readrel250->getIndex(ord249, false);
  
    }
    ReadTask246(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[2];
        slog::join_probe<3,2>(ptindex245, std::array<u64,3>{v_c35, v_c34, 0}, [&](const std::array<u64,3>& m251) {
          u64 v_c62 = m251[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c62}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_alias.slog:15", "delta:temp5uvn102", _fires);
  
      if (!_done)
      {
        ReadTask246* _cont = new ReadTask246(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask246(db,b), false);
  // (crule (pre (let __tconst8PFH17 const6b86b273ff34fce19d6b804e) (let __tconst7ikL19 constd4735e3a265e16eee03f5971) (let __tconst3JzW22 conste7f6c011776e8db7cd330b54) (let __tconst2yNa23 const4b227777d4dd1fc61c6f884f) (let __tconst2dvT26 const5feceb66ffc86f38d952786c)) (once) (body) (head (mkstruct pt (1 2 0) __t5hsY20 __tconst7ikL19 __tconst2yNa23) (mkstruct pt (1 2 0) __t8toC24 __tconst2yNa23 __tconst3JzW22) (mkstruct pt (1 2 0) __t7JfT27 __tconst2dvT26 __tconst2dvT26)) dem_alias.slog:18 #f)
  class ReadTask252 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("pt");
      head_rel[1] = db->getRelation("pt");
      head_rel[2] = db->getRelation("pt");
  
    }
    ReadTask252(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c3 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c3}, std::array<u16,3>{1, 2, 0});
      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c3, v_c2}, std::array<u16,3>{1, 2, 0});
      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c4}, std::array<u16,3>{1, 2, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("dem_alias.slog:18", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask252(db,b), true);
  // (crule (pre) (scan mpz_overflow __erre1Gln92 __errf2Fqb93 __errf1AjG94 __errf8hx695 __errf2cH296) (body) (head (emit error (0) __erre1Gln92)) <internal>:1 #f)
  class ReadTask253 : public slog::Task
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
      std::vector<u16> ord254({0});
      slog::Relation* readrel255 = db->getRelation("error");
      head_index[0] = readrel255->getIndex(ord254, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask253(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c65 = _t[2];
        u64 v_c66 = _t[3];
        u64 v_c67 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c63}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask253* _cont = new ReadTask253(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask253(db,b), false);
  s->addReadRel("center");
  s->addReadRel("circle");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("pt");
  s->addReadRel("rect");
  s->addReadRel("shapes");
  s->addReadRel("temp1Wzv100");
  s->addReadRel("temp5uvn102");
  s->addReadRel("temp7igP101");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("center");
  s->addDynamicRel("center_ans");
  s->addDynamicRel("circle");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("pt");
  s->addDynamicRel("rect");
  s->addDynamicRel("shapes");
  s->addDynamicRel("temp1Wzv100");
  s->addDynamicRel("temp5uvn102");
  s->addDynamicRel("temp7igP101");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("center_ans");
  s->addAccelRel("shapes");
  d->push(s);
  d->continueRun();
}

