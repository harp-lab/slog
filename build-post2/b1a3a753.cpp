
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const25e7b0e6bcacc29ff436fea9;
u64 v_conste593eb62d5b2b78aac29610d;
u64 v_const019f836fc5ed4942d15bf125;
u64 v_const99071cf3586be89134ffc1b3;
u64 v_const5feceb66ffc86f38d952786c;
u64 v_constd20c23bad354bda74806a4f5;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("b1a3a753");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const25e7b0e6bcacc29ff436fea9 = db->encodeString("apply1");
  v_conste593eb62d5b2b78aac29610d = db->encodeString("_lam54764x26x19");
  v_const019f836fc5ed4942d15bf125 = db->encodeString("dem_lambda.slog:10");
  v_const99071cf3586be89134ffc1b3 = db->encodeString("_lam54764x26x40");
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_constd20c23bad354bda74806a4f5 = db->encodeString("dem_lambda.slog:23");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord399({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord399, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord400({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord400, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("twice");
  if (r == 0) db->addRelation("twice", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("twice");
      std::vector<u16> ord401({0});
    
    r->addIndex<1>(ord401, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("twice"), std::array<u16,1>{0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord402({1, 2, 0});
    
    r->addIndex<3>(ord402, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord403({0, 1, 2});
    
    r->addIndex<3>(ord403, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp687o314");
  if (r == 0) db->addTempRelation("temp687o314", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp0r94312");
  if (r == 0) db->addTempRelation("temp0r94312", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp0G00313");
  if (r == 0) db->addTempRelation("temp0G00313", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord404({1, 2, 0});
    
    r->addIndex<3>(ord404, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord405({0, 1, 2});
    
    r->addIndex<3>(ord405, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("scaled");
  if (r == 0) db->addRelation("scaled", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("scaled");
      std::vector<u16> ord406({0});
    
    r->addIndex<1>(ord406, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("scaled"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord407({1, 2, 3, 0});
    
    r->addIndex<4>(ord407, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord408({0, 1, 2, 3});
    
    r->addIndex<4>(ord408, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord409({1, 2, 0});
    
    r->addIndex<3>(ord409, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord410({0, 1, 2});
    
    r->addIndex<3>(ord410, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord411({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord411, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord412({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord412, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord413({1, 2, 0});
    
    r->addIndex<3>(ord413, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord414({0, 1, 2});
    
    r->addIndex<3>(ord414, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("map2_ans");
  if (r == 0) db->addRelation("map2_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map2_ans");
      std::vector<u16> ord415({0, 1});
    
    r->addIndex<2>(ord415, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("map2_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("map2");
  if (r == 0) db->addStruct("map2", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map2");
      std::vector<u16> ord416({1, 2, 0});
    
    r->addIndex<3>(ord416, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord417({0, 1, 2});
    
    r->addIndex<3>(ord417, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("map2"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord418({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord418, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord419({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord419, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("kv");
  if (r == 0) db->addRelation("kv", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("kv");
      std::vector<u16> ord420({0});
    
    r->addIndex<1>(ord420, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("kv"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord421({1, 2, 3, 0});
    
    r->addIndex<4>(ord421, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord422({0, 1, 2, 3});
    
    r->addIndex<4>(ord422, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("input");
  if (r == 0) db->addRelation("input", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("input");
      std::vector<u16> ord423({0});
    
    r->addIndex<1>(ord423, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("input"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord424({0});
    
    r->addIndex<1>(ord424, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord425({1, 2, 0});
    
    r->addIndex<3>(ord425, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord426({0, 1, 2});
    
    r->addIndex<3>(ord426, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("compose_ans");
  if (r == 0) db->addRelation("compose_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("compose_ans");
      std::vector<u16> ord427({0, 1});
    
    r->addIndex<2>(ord427, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("compose_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("compose");
  if (r == 0) db->addStruct("compose", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("compose");
      std::vector<u16> ord428({1, 2, 0});
    
    r->addIndex<3>(ord428, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord429({0, 1, 2});
    
    r->addIndex<3>(ord429, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("compose"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("apply1_ans");
  if (r == 0) db->addRelation("apply1_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply1_ans");
      std::vector<u16> ord430({0, 1});
    
    r->addIndex<2>(ord430, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord431({1, 0});
    
    r->addIndex<2>(ord431, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord432({0, 1});
    
    r->addIndex<2>(ord432, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("apply1_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("apply1");
  if (r == 0) db->addStruct("apply1", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply1");
      std::vector<u16> ord433({1, 2, 0});
    
    r->addIndex<3>(ord433, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord434({0, 1, 2});
    
    r->addIndex<3>(ord434, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord435({2, 0, 1});
    
    r->addIndex<3>(ord435, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord436({0, 1, 2});
    
    r->addIndex<3>(ord436, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord437({1, 2, 0});
    
    r->addIndex<3>(ord437, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("apply1"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_lam54764x22x18");
  if (r == 0) db->addStruct("_lam54764x22x18", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_lam54764x22x18");
      std::vector<u16> ord438({1, 2, 0});
    
    r->addIndex<3>(ord438, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord439({0, 1, 2});
    
    r->addIndex<3>(ord439, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord440({2, 0, 1});
    
    r->addIndex<3>(ord440, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("_lam54764x22x18"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_lam54764x18x33");
  if (r == 0) db->addStruct("_lam54764x18x33", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_lam54764x18x33");
      std::vector<u16> ord441({1, 0});
    
    r->addIndex<2>(ord441, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord442({0, 1});
    
    r->addIndex<2>(ord442, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_lam54764x18x33"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord443({1, 0});
    
    r->addIndex<2>(ord443, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord444({0, 1});
    
    r->addIndex<2>(ord444, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup54764x9x0x0x0");
  if (r == 0) db->addRelation("$sup54764x9x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup54764x9x0x0x0");
      std::vector<u16> ord445({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord445, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup54764x9x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup54764x22x18x0x0");
  if (r == 0) db->addRelation("$sup54764x22x18x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup54764x22x18x0x0");
      std::vector<u16> ord446({1, 2, 3, 0});
    
    r->addIndex<4>(ord446, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord447({0, 3, 1, 2});
    
    r->addIndex<4>(ord447, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 3, 1, 2}, false, b), false);
      std::vector<u16> ord448({2, 3, 0, 1});
    
    r->addIndex<4>(ord448, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), false);
      std::vector<u16> ord449({1, 2, 3, 0});
    
    r->addIndex<4>(ord449, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, true, b), false);
      std::vector<u16> ord450({2, 3, 0, 1});
    
    r->addIndex<4>(ord450, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup54764x22x18x0x0"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord451({0, 1, 2});
    
    r->addIndex<3>(ord451, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("input"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("map2"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("map2_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("scaled"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("twice"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre (let __tconst3REr73 conste593eb62d5b2b78aac29610d) (let __tconst5m6f34 const6b86b273ff34fce19d6b804e)) (scan apply1 __t8w5b37 __t0XnK36 n) (body (join _enum (0 1) 2 __t0XnK36 __tconst3REr73) (let __t5ZXC35 (_0002b n __tconst5m6f34))) (head (emit-temp temp687o314 __t5ZXC35 __t8w5b37)) dem_lambda.slog:27 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp687o314");
      outer_rel = db->getRelation("apply1");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("_enum");
      _enumindex0 = readrel3->getIndex(ord2, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_conste593eb62d5b2b78aac29610d;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c2 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe<2,2>(_enumindex0, std::array<u64,2>{v_c3, v_c0}, [&](const std::array<u64,2>& m4) {
          u64 v_c5 = _prim__0002b(db, v_c4, v_c1);
          if (v_c5 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:27"); return; }
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:27", "delta:apply1", _fires);
  
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
  // (crule (pre (let __trid5HaP85 constd20c23bad354bda74806a4f5) (let __trel5FD086 const25e7b0e6bcacc29ff436fea9) (let __tcol70Dy87 const5feceb66ffc86f38d952786c)) (scan apply1 __t8SMm18 g x) (body (exists apply1_ans (0 1) 1 __t8SMm18) (join $sup54764x22x18x0x0 (2 3 0 1) 2 g x __d0 f) (join apply1_ans (0 1) 1 __t8SMm18 __v0)) (head (tycheck f (accept (struct _lam54764x18x33) (struct _lam54764x22x18) (struct _enum)) __trid5HaP85 __trel5FD086 __tcol70Dy87 (1 2 3 4 0)) (mkstruct apply1 (1 2 0) __1iTE84 f __v0)) dem_lambda.slog:23 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** apply1_ansindex5;  slog::Index** $sup54764x22x18x0x0index6;  slog::Index** apply1_ansindex7;
    u32 sid10;  u32 sid8;  u32 sid9;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("apply1");
      outer_rel = db->getRelation("apply1");
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("apply1_ans");
      apply1_ansindex5 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({2, 3, 0, 1});
      slog::Relation* readrel15 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index6 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({0, 1});
      slog::Relation* readrel17 = db->getRelation("apply1_ans");
      apply1_ansindex7 = readrel17->getIndex(ord16, false);
      sid10 = db->getRelation("_enum")->getStructId();
      sid8 = db->getRelation("_lam54764x18x33")->getStructId();
      sid9 = db->getRelation("_lam54764x22x18")->getStructId();
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constd20c23bad354bda74806a4f5;
      u64 v_c7 = v_const25e7b0e6bcacc29ff436fea9;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        if (!slog::exists_probe<2,1>(apply1_ansindex5, std::array<u64,2>{v_c9, 0})) return;
        slog::join_probe<4,2>($sup54764x22x18x0x0index6, std::array<u64,4>{v_c10, v_c11, 0, 0}, [&](const std::array<u64,4>& m18) {
          u64 v_c12 = m18[2]; u64 v_c13 = m18[3];
          slog::join_probe<2,1>(apply1_ansindex7, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m19) {
            u64 v_c14 = m19[1];
            ++_fires;
            if (!((is_struct(v_c13) && (decode_struct_id(v_c13) == sid8 || decode_struct_id(v_c13) == sid9 || decode_struct_id(v_c13) == sid10))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c6, v_c7, v_c8, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c13, v_c14}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:apply1", _fires);
  
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
  // (crule (pre) (scan mpz_table_overflow __erre0Pwu309 __errf8gBw310 __errf7jjc311) (body) (head (emit error (0) __erre0Pwu309)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre (let __trid5HaP85 constd20c23bad354bda74806a4f5) (let __trel5FD086 const25e7b0e6bcacc29ff436fea9) (let __tcol70Dy87 const5feceb66ffc86f38d952786c)) (scan apply1_ans __t8SMm18 __v0) (body (join-old apply1 (0 1 2) 1 (0 1 2) __t8SMm18 g x) (join $sup54764x22x18x0x0 (2 3 0 1) 2 g x __d0 f)) (head (tycheck f (accept (struct _lam54764x18x33) (struct _lam54764x22x18) (struct _enum)) __trid5HaP85 __trel5FD086 __tcol70Dy87 (1 2 3 4 0)) (mkstruct apply1 (1 2 0) __1iTE84 f __v0)) dem_lambda.slog:23 #f)
  class ReadTask29 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** apply1index23;  slog::Index** $sup54764x22x18x0x0index24;  slog::Index** apply1delta25;
    u32 sid28;  u32 sid26;  u32 sid27;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("apply1");
      outer_rel = db->getRelation("apply1_ans");
      std::vector<u16> ord30({0, 1, 2});
      slog::Relation* readrel31 = db->getRelation("apply1");
      apply1index23 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1, 2});
      slog::Relation* readrel33 = db->getRelation("apply1");
      apply1delta25 = readrel33->getIndex(ord32, true);
      std::vector<u16> ord34({2, 3, 0, 1});
      slog::Relation* readrel35 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index24 = readrel35->getIndex(ord34, false);
      sid28 = db->getRelation("_enum")->getStructId();
      sid26 = db->getRelation("_lam54764x18x33")->getStructId();
      sid27 = db->getRelation("_lam54764x22x18")->getStructId();
  
    }
    ReadTask29(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constd20c23bad354bda74806a4f5;
      u64 v_c7 = v_const25e7b0e6bcacc29ff436fea9;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        u64 v_c14 = _t[1];
        slog::join_probe_old<3,1>(apply1index23, apply1delta25, std::array<u64,3>{v_c9, 0, 0}, [&](const std::array<u64,3>& m36) {
          u64 v_c10 = m36[1]; u64 v_c11 = m36[2];
          slog::join_probe<4,2>($sup54764x22x18x0x0index24, std::array<u64,4>{v_c10, v_c11, 0, 0}, [&](const std::array<u64,4>& m37) {
            u64 v_c12 = m37[2]; u64 v_c13 = m37[3];
            ++_fires;
            if (!((is_struct(v_c13) && (decode_struct_id(v_c13) == sid26 || decode_struct_id(v_c13) == sid27 || decode_struct_id(v_c13) == sid28))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c6, v_c7, v_c8, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c13, v_c14}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:apply1_ans", _fires);
  
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
  // (crule (pre) (scan temp687o314 __t5ZXC35 __t8w5b37) (body) (head (emit apply1_ans (0 1) __t8w5b37 __t5ZXC35)) dem_lambda.slog:27 #f)
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
      head_rel[0] = db->getRelation("apply1_ans");
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("apply1_ans");
      head_index[0] = readrel40->getIndex(ord39, false);
      outer_rel = db->getRelation("temp687o314");
  
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
        u64 v_c5 = _t[0];
        u64 v_c2 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c2, v_c5}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:27", "delta:temp687o314", _fires);
  
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
  // (crule (pre) (scan nan_result __erre4Yj1292 __errf3T3y293 __errf9q9d294 __errf4rlg295) (body) (head (emit error (0) __erre4Yj1292)) <internal>:1 #f)
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
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c18 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c20 = _t[2];
        u64 v_c21 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre) (scan malformed_deduction __erre64cN277 __errf1Nwt278 __errf0oGI279 __errf5xL9280 __errf2yJC281) (body) (head (emit error (0) __erre64cN277)) <internal>:1 #f)
  class ReadTask44 : public slog::Task
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
      std::vector<u16> ord45({0});
      slog::Relation* readrel46 = db->getRelation("error");
      head_index[0] = readrel46->getIndex(ord45, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask44(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c25 = _t[3];
        u64 v_c26 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c22}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask44* _cont = new ReadTask44(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask44(db,b), false);
  // (crule (pre) (scan div_by_zero __erre2oy5282 __errf1Vqh283 __errf8Qbr284) (body) (head (emit error (0) __erre2oy5282)) <internal>:1 #f)
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
      outer_rel = db->getRelation("div_by_zero");
  
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
        u64 v_c27 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre) (scan mpz_overflow __erre9eec304 __errf1lR2305 __errf0pwC306 __errf1clL307 __errf9cQR308) (body) (head (emit error (0) __erre9eec304)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c30 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c32 = _t[2];
        u64 v_c33 = _t[3];
        u64 v_c34 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c30}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre) (scan apply1 __t5Lm522 __t3Dcq21 x) (body (join _lam54764x22x18 (0 1 2) 1 __t3Dcq21 f g)) (head (emit $sup54764x22x18x0x0 (1 2 3 0) f g x __t5Lm522)) dem_lambda.slog:23 #f)
  class ReadTask54 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _lam54764x22x18index53;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup54764x22x18x0x0");
      std::vector<u16> ord55({1, 2, 3, 0});
      slog::Relation* readrel56 = db->getRelation("$sup54764x22x18x0x0");
      head_index[0] = readrel56->getIndex(ord55, false);
      outer_rel = db->getRelation("apply1");
      std::vector<u16> ord57({0, 1, 2});
      slog::Relation* readrel58 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index53 = readrel58->getIndex(ord57, false);
  
    }
    ReadTask54(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[2];
        slog::join_probe<3,1>(_lam54764x22x18index53, std::array<u64,3>{v_c36, 0, 0}, [&](const std::array<u64,3>& m59) {
          u64 v_c13 = m59[1]; u64 v_c10 = m59[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c13, v_c10, v_c11, v_c35}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:apply1", _fires);
  
      if (!_done)
      {
        ReadTask54* _cont = new ReadTask54(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask54(db,b), false);
  // (crule (pre (let __trid60wp75 const019f836fc5ed4942d15bf125) (let __trel7cF176 const25e7b0e6bcacc29ff436fea9) (let __tcol2j1x77 const5feceb66ffc86f38d952786c)) (scan $sup54764x9x0x0x0 _00024seq0 __d0 f x xs) (body) (head (tycheck f (accept (struct _lam54764x18x33) (struct _lam54764x22x18) (struct _enum)) __trid60wp75 __trel7cF176 __tcol2j1x77 (1 2 3 4 0)) (mkstruct apply1 (1 2 0) __8fuM74 f x)) dem_lambda.slog:10 #f)
  class ReadTask63 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid62;  u32 sid60;  u32 sid61;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("apply1");
      outer_rel = db->getRelation("$sup54764x9x0x0x0");
      sid62 = db->getRelation("_enum")->getStructId();
      sid60 = db->getRelation("_lam54764x18x33")->getStructId();
      sid61 = db->getRelation("_lam54764x22x18")->getStructId();
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_const019f836fc5ed4942d15bf125;
      u64 v_c38 = v_const25e7b0e6bcacc29ff436fea9;
      u64 v_c39 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c41 = _t[4];
        ++_fires;
        if (!((is_struct(v_c13) && (decode_struct_id(v_c13) == sid60 || decode_struct_id(v_c13) == sid61 || decode_struct_id(v_c13) == sid62))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c37, v_c38, v_c39, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c13, v_c11}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:10", "all:$sup54764x9x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask63* _cont = new ReadTask63(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask63(db,b), true);
  // (crule (pre) (scan apply1 __t68lH41 f __v0) (body (exists apply1_ans (0 1) 1 __t68lH41) (exists _lam54764x22x18 (1 2 0) 1 f) (exists $sup54764x22x18x0x0 (1 2 3 0) 1 f) (join apply1_ans (1 0) 1 __v0 __t5wmm40) (join apply1_ans (0 1) 1 __t68lH41 __v1) (join _lam54764x22x18 (1 2 0) 1 f g __t515s38) (exists $sup54764x22x18x0x0 (1 2 3 0) 2 f g) (exists apply1 (1 2 0) 1 __t515s38) (join apply1 (0 1 2) 2 __t5wmm40 g x) (exists apply1 (1 2 0) 2 __t515s38 x) (join $sup54764x22x18x0x0 (1 2 3 0) 3 f g x __t288X39) (join apply1 (0 1 2) 3 __t288X39 __t515s38 x)) (head (emit apply1_ans (0 1) __t288X39 __v1)) dem_lambda.slog:23 #f)
  class ReadTask76 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** apply1_ansindex64;  slog::Index** _lam54764x22x18index65;  slog::Index** $sup54764x22x18x0x0index66;  slog::Index** apply1_ansindex67;  slog::Index** apply1_ansindex68;  slog::Index** _lam54764x22x18index69;  slog::Index** $sup54764x22x18x0x0index70;  slog::Index** apply1index71;  slog::Index** apply1index72;  slog::Index** apply1index73;  slog::Index** $sup54764x22x18x0x0index74;  slog::Index** apply1index75;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("apply1_ans");
      std::vector<u16> ord77({0, 1});
      slog::Relation* readrel78 = db->getRelation("apply1_ans");
      head_index[0] = readrel78->getIndex(ord77, false);
      outer_rel = db->getRelation("apply1");
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("apply1_ans");
      apply1_ansindex64 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({1, 2, 0});
      slog::Relation* readrel82 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index65 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 3, 0});
      slog::Relation* readrel84 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index66 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({1, 0});
      slog::Relation* readrel86 = db->getRelation("apply1_ans");
      apply1_ansindex67 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("apply1_ans");
      apply1_ansindex68 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 2, 0});
      slog::Relation* readrel90 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index69 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({1, 2, 3, 0});
      slog::Relation* readrel92 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index70 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 2, 0});
      slog::Relation* readrel94 = db->getRelation("apply1");
      apply1index71 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({0, 1, 2});
      slog::Relation* readrel96 = db->getRelation("apply1");
      apply1index72 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 2, 0});
      slog::Relation* readrel98 = db->getRelation("apply1");
      apply1index73 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 3, 0});
      slog::Relation* readrel100 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index74 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({0, 1, 2});
      slog::Relation* readrel102 = db->getRelation("apply1");
      apply1index75 = readrel102->getIndex(ord101, false);
  
    }
    ReadTask76(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<2,1>(apply1_ansindex64, std::array<u64,2>{v_c42, 0})) return;
        if (!slog::exists_probe<3,1>(_lam54764x22x18index65, std::array<u64,3>{v_c13, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup54764x22x18x0x0index66, std::array<u64,4>{v_c13, 0, 0, 0})) return;
        slog::join_probe<2,1>(apply1_ansindex67, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m103) {
          u64 v_c43 = m103[1];
          slog::join_probe<2,1>(apply1_ansindex68, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m104) {
            u64 v_c44 = m104[1];
            slog::join_probe<3,1>(_lam54764x22x18index69, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m105) {
              u64 v_c10 = m105[1]; u64 v_c45 = m105[2];
              if (!slog::exists_probe<4,2>($sup54764x22x18x0x0index70, std::array<u64,4>{v_c13, v_c10, 0, 0})) return;
              if (!slog::exists_probe<3,1>(apply1index71, std::array<u64,3>{v_c45, 0, 0})) return;
              slog::join_probe<3,2>(apply1index72, std::array<u64,3>{v_c43, v_c10, 0}, [&](const std::array<u64,3>& m106) {
                u64 v_c11 = m106[2];
                if (!slog::exists_probe<3,2>(apply1index73, std::array<u64,3>{v_c45, v_c11, 0})) return;
                slog::join_probe<4,3>($sup54764x22x18x0x0index74, std::array<u64,4>{v_c13, v_c10, v_c11, 0}, [&](const std::array<u64,4>& m107) {
                  u64 v_c46 = m107[3];
                  slog::join_probe<3,3>(apply1index75, std::array<u64,3>{v_c46, v_c45, v_c11}, [&](const std::array<u64,3>& m108) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c46, v_c44}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:apply1", _fires);
  
      if (!_done)
      {
        ReadTask76* _cont = new ReadTask76(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask76(db,b), false);
  // (crule (pre) (scan $sup54764x22x18x0x0 __t288X39 f g x) (body (exists apply1 (2 0 1) 2 x __t288X39) (exists apply1 (1 2 0) 2 g x) (exists apply1 (1 2 0) 1 f) (join _lam54764x22x18 (1 2 0) 2 f g __t515s38) (join-old apply1 (0 1 2) 3 (0 1 2) __t288X39 __t515s38 x) (join-old apply1 (1 2 0) 2 (1 2 0) g x __t5wmm40) (join apply1_ans (0 1) 1 __t5wmm40 __v0) (join-old apply1 (1 2 0) 2 (1 2 0) f __v0 __t68lH41) (join apply1_ans (0 1) 1 __t68lH41 __v1)) (head (emit apply1_ans (0 1) __t288X39 __v1)) dem_lambda.slog:23 #f)
  class ReadTask121 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** apply1index109;  slog::Index** apply1index110;  slog::Index** apply1index111;  slog::Index** _lam54764x22x18index112;  slog::Index** apply1index113;  slog::Index** apply1index114;  slog::Index** apply1_ansindex115;  slog::Index** apply1index116;  slog::Index** apply1_ansindex117;  slog::Index** apply1delta118;  slog::Index** apply1delta119;  slog::Index** apply1delta120;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("apply1_ans");
      std::vector<u16> ord122({0, 1});
      slog::Relation* readrel123 = db->getRelation("apply1_ans");
      head_index[0] = readrel123->getIndex(ord122, false);
      outer_rel = db->getRelation("$sup54764x22x18x0x0");
      std::vector<u16> ord124({2, 0, 1});
      slog::Relation* readrel125 = db->getRelation("apply1");
      apply1index109 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("apply1");
      apply1index110 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("apply1");
      apply1index111 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 2, 0});
      slog::Relation* readrel131 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index112 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({0, 1, 2});
      slog::Relation* readrel133 = db->getRelation("apply1");
      apply1index113 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({0, 1, 2});
      slog::Relation* readrel135 = db->getRelation("apply1");
      apply1delta118 = readrel135->getIndex(ord134, true);
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("apply1");
      apply1index114 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("apply1");
      apply1delta119 = readrel139->getIndex(ord138, true);
      std::vector<u16> ord140({0, 1});
      slog::Relation* readrel141 = db->getRelation("apply1_ans");
      apply1_ansindex115 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0});
      slog::Relation* readrel143 = db->getRelation("apply1");
      apply1index116 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 2, 0});
      slog::Relation* readrel145 = db->getRelation("apply1");
      apply1delta120 = readrel145->getIndex(ord144, true);
      std::vector<u16> ord146({0, 1});
      slog::Relation* readrel147 = db->getRelation("apply1_ans");
      apply1_ansindex117 = readrel147->getIndex(ord146, false);
  
    }
    ReadTask121(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        if (!slog::exists_probe<3,2>(apply1index109, std::array<u64,3>{v_c11, v_c46, 0})) return;
        if (!slog::exists_probe<3,2>(apply1index110, std::array<u64,3>{v_c10, v_c11, 0})) return;
        if (!slog::exists_probe<3,1>(apply1index111, std::array<u64,3>{v_c13, 0, 0})) return;
        slog::join_probe<3,2>(_lam54764x22x18index112, std::array<u64,3>{v_c13, v_c10, 0}, [&](const std::array<u64,3>& m148) {
          u64 v_c45 = m148[2];
          slog::join_probe_old<3,3>(apply1index113, apply1delta118, std::array<u64,3>{v_c46, v_c45, v_c11}, [&](const std::array<u64,3>& m149) {
            slog::join_probe_old<3,2>(apply1index114, apply1delta119, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m150) {
              u64 v_c43 = m150[2];
              slog::join_probe<2,1>(apply1_ansindex115, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m151) {
                u64 v_c14 = m151[1];
                slog::join_probe_old<3,2>(apply1index116, apply1delta120, std::array<u64,3>{v_c13, v_c14, 0}, [&](const std::array<u64,3>& m152) {
                  u64 v_c42 = m152[2];
                  slog::join_probe<2,1>(apply1_ansindex117, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m153) {
                    u64 v_c44 = m153[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c46, v_c44}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:$sup54764x22x18x0x0", _fires);
  
      if (!_done)
      {
        ReadTask121* _cont = new ReadTask121(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask121(db,b), false);
  // (crule (pre (let __trid5HaP85 constd20c23bad354bda74806a4f5) (let __trel5FD086 const25e7b0e6bcacc29ff436fea9) (let __tcol70Dy87 const5feceb66ffc86f38d952786c)) (scan $sup54764x22x18x0x0 __d0 f g x) (body (join-old apply1 (1 2 0) 2 (1 2 0) g x __t8SMm18) (join-old apply1_ans (0 1) 1 (0 1) __t8SMm18 __v0)) (head (tycheck f (accept (struct _lam54764x18x33) (struct _lam54764x22x18) (struct _enum)) __trid5HaP85 __trel5FD086 __tcol70Dy87 (1 2 3 4 0)) (mkstruct apply1 (1 2 0) __1iTE84 f __v0)) dem_lambda.slog:23 #f)
  class ReadTask161 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** apply1index154;  slog::Index** apply1_ansindex155;  slog::Index** apply1delta156;  slog::Index** apply1_ansdelta157;
    u32 sid160;  u32 sid158;  u32 sid159;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("apply1");
      outer_rel = db->getRelation("$sup54764x22x18x0x0");
      std::vector<u16> ord162({1, 2, 0});
      slog::Relation* readrel163 = db->getRelation("apply1");
      apply1index154 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 2, 0});
      slog::Relation* readrel165 = db->getRelation("apply1");
      apply1delta156 = readrel165->getIndex(ord164, true);
      std::vector<u16> ord166({0, 1});
      slog::Relation* readrel167 = db->getRelation("apply1_ans");
      apply1_ansindex155 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({0, 1});
      slog::Relation* readrel169 = db->getRelation("apply1_ans");
      apply1_ansdelta157 = readrel169->getIndex(ord168, true);
      sid160 = db->getRelation("_enum")->getStructId();
      sid158 = db->getRelation("_lam54764x18x33")->getStructId();
      sid159 = db->getRelation("_lam54764x22x18")->getStructId();
  
    }
    ReadTask161(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constd20c23bad354bda74806a4f5;
      u64 v_c7 = v_const25e7b0e6bcacc29ff436fea9;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c12 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        slog::join_probe_old<3,2>(apply1index154, apply1delta156, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m170) {
          u64 v_c9 = m170[2];
          slog::join_probe_old<2,1>(apply1_ansindex155, apply1_ansdelta157, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m171) {
            u64 v_c14 = m171[1];
            ++_fires;
            if (!((is_struct(v_c13) && (decode_struct_id(v_c13) == sid158 || decode_struct_id(v_c13) == sid159 || decode_struct_id(v_c13) == sid160))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c6, v_c7, v_c8, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c13, v_c14}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:$sup54764x22x18x0x0", _fires);
  
      if (!_done)
      {
        ReadTask161* _cont = new ReadTask161(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask161(db,b), false);
  // (crule (pre) (scan apply1 __t5wmm40 g x) (body (exists _lam54764x22x18 (2 0 1) 1 g) (exists apply1 (2 0 1) 1 x) (exists apply1_ans (0 1) 1 __t5wmm40) (join $sup54764x22x18x0x0 (2 3 0 1) 2 g x __t288X39 f) (exists apply1 (2 0 1) 2 x __t288X39) (exists apply1 (1 2 0) 1 f) (join _lam54764x22x18 (1 2 0) 2 f g __t515s38) (join apply1 (0 1 2) 3 __t288X39 __t515s38 x) (join apply1_ans (0 1) 1 __t5wmm40 __v0) (join-old apply1 (1 2 0) 2 (1 2 0) f __v0 __t68lH41) (join apply1_ans (0 1) 1 __t68lH41 __v1)) (head (emit apply1_ans (0 1) __t288X39 __v1)) dem_lambda.slog:23 #f)
  class ReadTask184 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _lam54764x22x18index172;  slog::Index** apply1index173;  slog::Index** apply1_ansindex174;  slog::Index** $sup54764x22x18x0x0index175;  slog::Index** apply1index176;  slog::Index** apply1index177;  slog::Index** _lam54764x22x18index178;  slog::Index** apply1index179;  slog::Index** apply1_ansindex180;  slog::Index** apply1index181;  slog::Index** apply1_ansindex182;  slog::Index** apply1delta183;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("apply1_ans");
      std::vector<u16> ord185({0, 1});
      slog::Relation* readrel186 = db->getRelation("apply1_ans");
      head_index[0] = readrel186->getIndex(ord185, false);
      outer_rel = db->getRelation("apply1");
      std::vector<u16> ord187({2, 0, 1});
      slog::Relation* readrel188 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index172 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({2, 0, 1});
      slog::Relation* readrel190 = db->getRelation("apply1");
      apply1index173 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({0, 1});
      slog::Relation* readrel192 = db->getRelation("apply1_ans");
      apply1_ansindex174 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({2, 3, 0, 1});
      slog::Relation* readrel194 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index175 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({2, 0, 1});
      slog::Relation* readrel196 = db->getRelation("apply1");
      apply1index176 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 2, 0});
      slog::Relation* readrel198 = db->getRelation("apply1");
      apply1index177 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 2, 0});
      slog::Relation* readrel200 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index178 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({0, 1, 2});
      slog::Relation* readrel202 = db->getRelation("apply1");
      apply1index179 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1});
      slog::Relation* readrel204 = db->getRelation("apply1_ans");
      apply1_ansindex180 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 2, 0});
      slog::Relation* readrel206 = db->getRelation("apply1");
      apply1index181 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 2, 0});
      slog::Relation* readrel208 = db->getRelation("apply1");
      apply1delta183 = readrel208->getIndex(ord207, true);
      std::vector<u16> ord209({0, 1});
      slog::Relation* readrel210 = db->getRelation("apply1_ans");
      apply1_ansindex182 = readrel210->getIndex(ord209, false);
  
    }
    ReadTask184(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        if (!slog::exists_probe<3,1>(_lam54764x22x18index172, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<3,1>(apply1index173, std::array<u64,3>{v_c11, 0, 0})) return;
        if (!slog::exists_probe<2,1>(apply1_ansindex174, std::array<u64,2>{v_c43, 0})) return;
        slog::join_probe<4,2>($sup54764x22x18x0x0index175, std::array<u64,4>{v_c10, v_c11, 0, 0}, [&](const std::array<u64,4>& m211) {
          u64 v_c46 = m211[2]; u64 v_c13 = m211[3];
          if (!slog::exists_probe<3,2>(apply1index176, std::array<u64,3>{v_c11, v_c46, 0})) return;
          if (!slog::exists_probe<3,1>(apply1index177, std::array<u64,3>{v_c13, 0, 0})) return;
          slog::join_probe<3,2>(_lam54764x22x18index178, std::array<u64,3>{v_c13, v_c10, 0}, [&](const std::array<u64,3>& m212) {
            u64 v_c45 = m212[2];
            slog::join_probe<3,3>(apply1index179, std::array<u64,3>{v_c46, v_c45, v_c11}, [&](const std::array<u64,3>& m213) {
              slog::join_probe<2,1>(apply1_ansindex180, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m214) {
                u64 v_c14 = m214[1];
                slog::join_probe_old<3,2>(apply1index181, apply1delta183, std::array<u64,3>{v_c13, v_c14, 0}, [&](const std::array<u64,3>& m215) {
                  u64 v_c42 = m215[2];
                  slog::join_probe<2,1>(apply1_ansindex182, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m216) {
                    u64 v_c44 = m216[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c46, v_c44}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:apply1", _fires);
  
      if (!_done)
      {
        ReadTask184* _cont = new ReadTask184(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask184(db,b), false);
  // (crule (pre) (scan apply1 __t288X39 __t515s38 x) (body (exists apply1 (2 0 1) 1 x) (join $sup54764x22x18x0x0 (0 3 1 2) 2 __t288X39 x f g) (join _lam54764x22x18 (1 2 0) 3 f g __t515s38) (exists apply1 (1 2 0) 1 f) (join-old apply1 (1 2 0) 2 (1 2 0) g x __t5wmm40) (join apply1_ans (0 1) 1 __t5wmm40 __v0) (join-old apply1 (1 2 0) 2 (1 2 0) f __v0 __t68lH41) (join apply1_ans (0 1) 1 __t68lH41 __v1)) (head (emit apply1_ans (0 1) __t288X39 __v1)) dem_lambda.slog:23 #f)
  class ReadTask227 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** apply1index217;  slog::Index** $sup54764x22x18x0x0index218;  slog::Index** _lam54764x22x18index219;  slog::Index** apply1index220;  slog::Index** apply1index221;  slog::Index** apply1_ansindex222;  slog::Index** apply1index223;  slog::Index** apply1_ansindex224;  slog::Index** apply1delta225;  slog::Index** apply1delta226;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("apply1_ans");
      std::vector<u16> ord228({0, 1});
      slog::Relation* readrel229 = db->getRelation("apply1_ans");
      head_index[0] = readrel229->getIndex(ord228, false);
      outer_rel = db->getRelation("apply1");
      std::vector<u16> ord230({2, 0, 1});
      slog::Relation* readrel231 = db->getRelation("apply1");
      apply1index217 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 3, 1, 2});
      slog::Relation* readrel233 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index218 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 0});
      slog::Relation* readrel235 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index219 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 2, 0});
      slog::Relation* readrel237 = db->getRelation("apply1");
      apply1index220 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 0});
      slog::Relation* readrel239 = db->getRelation("apply1");
      apply1index221 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 2, 0});
      slog::Relation* readrel241 = db->getRelation("apply1");
      apply1delta225 = readrel241->getIndex(ord240, true);
      std::vector<u16> ord242({0, 1});
      slog::Relation* readrel243 = db->getRelation("apply1_ans");
      apply1_ansindex222 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({1, 2, 0});
      slog::Relation* readrel245 = db->getRelation("apply1");
      apply1index223 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 2, 0});
      slog::Relation* readrel247 = db->getRelation("apply1");
      apply1delta226 = readrel247->getIndex(ord246, true);
      std::vector<u16> ord248({0, 1});
      slog::Relation* readrel249 = db->getRelation("apply1_ans");
      apply1_ansindex224 = readrel249->getIndex(ord248, false);
  
    }
    ReadTask227(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c11 = _t[2];
        if (!slog::exists_probe<3,1>(apply1index217, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<4,2>($sup54764x22x18x0x0index218, std::array<u64,4>{v_c46, v_c11, 0, 0}, [&](const std::array<u64,4>& m250) {
          u64 v_c13 = m250[2]; u64 v_c10 = m250[3];
          slog::join_probe<3,3>(_lam54764x22x18index219, std::array<u64,3>{v_c13, v_c10, v_c45}, [&](const std::array<u64,3>& m251) {
            if (!slog::exists_probe<3,1>(apply1index220, std::array<u64,3>{v_c13, 0, 0})) return;
            slog::join_probe_old<3,2>(apply1index221, apply1delta225, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m252) {
              u64 v_c43 = m252[2];
              slog::join_probe<2,1>(apply1_ansindex222, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m253) {
                u64 v_c14 = m253[1];
                slog::join_probe_old<3,2>(apply1index223, apply1delta226, std::array<u64,3>{v_c13, v_c14, 0}, [&](const std::array<u64,3>& m254) {
                  u64 v_c42 = m254[2];
                  slog::join_probe<2,1>(apply1_ansindex224, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m255) {
                    u64 v_c44 = m255[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c46, v_c44}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:apply1", _fires);
  
      if (!_done)
      {
        ReadTask227* _cont = new ReadTask227(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask227(db,b), false);
  // (crule (pre (let __tconst2E4V101 const99071cf3586be89134ffc1b3)) (scan apply1 __t12sZ44 __t0PEU43 n) (body (join _enum (0 1) 2 __t0PEU43 __tconst2E4V101) (let __t7bkw42 (_0002b n n))) (head (emit-temp temp0G00313 __t12sZ44 __t7bkw42)) dem_lambda.slog:27 #f)
  class ReadTask257 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex256;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0G00313");
      outer_rel = db->getRelation("apply1");
      std::vector<u16> ord258({0, 1});
      slog::Relation* readrel259 = db->getRelation("_enum");
      _enumindex256 = readrel259->getIndex(ord258, false);
  
    }
    ReadTask257(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_const99071cf3586be89134ffc1b3;
  
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
        u64 v_c4 = _t[2];
        slog::join_probe<2,2>(_enumindex256, std::array<u64,2>{v_c49, v_c47}, [&](const std::array<u64,2>& m260) {
          u64 v_c50 = _prim__0002b(db, v_c4, v_c4);
          if (v_c50 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:27"); return; }
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c48, v_c50});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:27", "delta:apply1", _fires);
  
      if (!_done)
      {
        ReadTask257* _cont = new ReadTask257(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask257(db,b), false);
  // (crule (pre) (scan apply1_ans __t5wmm40 __v0) (body (exists apply1 (2 0 1) 1 __v0) (join-old apply1 (0 1 2) 1 (0 1 2) __t5wmm40 g x) (exists _lam54764x22x18 (2 0 1) 1 g) (exists apply1 (2 0 1) 1 x) (join-old $sup54764x22x18x0x0 (2 3 0 1) 2 (2 3 0 1) g x __t288X39 f) (exists apply1 (2 0 1) 2 x __t288X39) (exists apply1 (1 2 0) 2 f __v0) (join _lam54764x22x18 (1 2 0) 2 f g __t515s38) (join-old apply1 (0 1 2) 3 (0 1 2) __t288X39 __t515s38 x) (join-old apply1 (1 2 0) 2 (1 2 0) f __v0 __t68lH41) (join-old apply1_ans (0 1) 1 (0 1) __t68lH41 __v1)) (head (emit apply1_ans (0 1) __t288X39 __v1)) dem_lambda.slog:23 #f)
  class ReadTask277 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** apply1index261;  slog::Index** apply1index262;  slog::Index** _lam54764x22x18index263;  slog::Index** apply1index264;  slog::Index** $sup54764x22x18x0x0index265;  slog::Index** apply1index266;  slog::Index** apply1index267;  slog::Index** _lam54764x22x18index268;  slog::Index** apply1index269;  slog::Index** apply1index270;  slog::Index** apply1_ansindex271;  slog::Index** apply1delta272;  slog::Index** $sup54764x22x18x0x0delta273;  slog::Index** apply1delta274;  slog::Index** apply1delta275;  slog::Index** apply1_ansdelta276;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("apply1_ans");
      std::vector<u16> ord278({0, 1});
      slog::Relation* readrel279 = db->getRelation("apply1_ans");
      head_index[0] = readrel279->getIndex(ord278, false);
      outer_rel = db->getRelation("apply1_ans");
      std::vector<u16> ord280({2, 0, 1});
      slog::Relation* readrel281 = db->getRelation("apply1");
      apply1index261 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({0, 1, 2});
      slog::Relation* readrel283 = db->getRelation("apply1");
      apply1index262 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({0, 1, 2});
      slog::Relation* readrel285 = db->getRelation("apply1");
      apply1delta272 = readrel285->getIndex(ord284, true);
      std::vector<u16> ord286({2, 0, 1});
      slog::Relation* readrel287 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index263 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({2, 0, 1});
      slog::Relation* readrel289 = db->getRelation("apply1");
      apply1index264 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({2, 3, 0, 1});
      slog::Relation* readrel291 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index265 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({2, 3, 0, 1});
      slog::Relation* readrel293 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0delta273 = readrel293->getIndex(ord292, true);
      std::vector<u16> ord294({2, 0, 1});
      slog::Relation* readrel295 = db->getRelation("apply1");
      apply1index266 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 2, 0});
      slog::Relation* readrel297 = db->getRelation("apply1");
      apply1index267 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 2, 0});
      slog::Relation* readrel299 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index268 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({0, 1, 2});
      slog::Relation* readrel301 = db->getRelation("apply1");
      apply1index269 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({0, 1, 2});
      slog::Relation* readrel303 = db->getRelation("apply1");
      apply1delta274 = readrel303->getIndex(ord302, true);
      std::vector<u16> ord304({1, 2, 0});
      slog::Relation* readrel305 = db->getRelation("apply1");
      apply1index270 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({1, 2, 0});
      slog::Relation* readrel307 = db->getRelation("apply1");
      apply1delta275 = readrel307->getIndex(ord306, true);
      std::vector<u16> ord308({0, 1});
      slog::Relation* readrel309 = db->getRelation("apply1_ans");
      apply1_ansindex271 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("apply1_ans");
      apply1_ansdelta276 = readrel311->getIndex(ord310, true);
  
    }
    ReadTask277(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[1];
        if (!slog::exists_probe<3,1>(apply1index261, std::array<u64,3>{v_c14, 0, 0})) return;
        slog::join_probe_old<3,1>(apply1index262, apply1delta272, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m312) {
          u64 v_c10 = m312[1]; u64 v_c11 = m312[2];
          if (!slog::exists_probe<3,1>(_lam54764x22x18index263, std::array<u64,3>{v_c10, 0, 0})) return;
          if (!slog::exists_probe<3,1>(apply1index264, std::array<u64,3>{v_c11, 0, 0})) return;
          slog::join_probe_old<4,2>($sup54764x22x18x0x0index265, $sup54764x22x18x0x0delta273, std::array<u64,4>{v_c10, v_c11, 0, 0}, [&](const std::array<u64,4>& m313) {
            u64 v_c46 = m313[2]; u64 v_c13 = m313[3];
            if (!slog::exists_probe<3,2>(apply1index266, std::array<u64,3>{v_c11, v_c46, 0})) return;
            if (!slog::exists_probe<3,2>(apply1index267, std::array<u64,3>{v_c13, v_c14, 0})) return;
            slog::join_probe<3,2>(_lam54764x22x18index268, std::array<u64,3>{v_c13, v_c10, 0}, [&](const std::array<u64,3>& m314) {
              u64 v_c45 = m314[2];
              slog::join_probe_old<3,3>(apply1index269, apply1delta274, std::array<u64,3>{v_c46, v_c45, v_c11}, [&](const std::array<u64,3>& m315) {
                slog::join_probe_old<3,2>(apply1index270, apply1delta275, std::array<u64,3>{v_c13, v_c14, 0}, [&](const std::array<u64,3>& m316) {
                  u64 v_c42 = m316[2];
                  slog::join_probe_old<2,1>(apply1_ansindex271, apply1_ansdelta276, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m317) {
                    u64 v_c44 = m317[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c46, v_c44}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:apply1_ans", _fires);
  
      if (!_done)
      {
        ReadTask277* _cont = new ReadTask277(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask277(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre9OqC285 __errf7eXC286 __errf5LzS287) (body) (head (emit error (0) __erre9OqC285)) <internal>:1 #f)
  class ReadTask318 : public slog::Task
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
      std::vector<u16> ord319({0});
      slog::Relation* readrel320 = db->getRelation("error");
      head_index[0] = readrel320->getIndex(ord319, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask318(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c51 = _t[0];
        u64 v_c52 = _t[1];
        u64 v_c53 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c51}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask318* _cont = new ReadTask318(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask318(db,b), false);
  // (crule (pre) (scan temp0G00313 __t12sZ44 __t7bkw42) (body) (head (emit apply1_ans (0 1) __t12sZ44 __t7bkw42)) dem_lambda.slog:27 #f)
  class ReadTask321 : public slog::Task
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
      head_rel[0] = db->getRelation("apply1_ans");
      std::vector<u16> ord322({0, 1});
      slog::Relation* readrel323 = db->getRelation("apply1_ans");
      head_index[0] = readrel323->getIndex(ord322, false);
      outer_rel = db->getRelation("temp0G00313");
  
    }
    ReadTask321(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c50 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c48, v_c50}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:27", "delta:temp0G00313", _fires);
  
      if (!_done)
      {
        ReadTask321* _cont = new ReadTask321(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask321(db,b), false);
  // (crule (pre) (scan type_mismatch __erre0DsV299 __errf7HDk300 __errf44ls301 __errf4hBX302 __errf55Gg303) (body) (head (emit error (0) __erre0DsV299)) <internal>:1 #f)
  class ReadTask324 : public slog::Task
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
      std::vector<u16> ord325({0});
      slog::Relation* readrel326 = db->getRelation("error");
      head_index[0] = readrel326->getIndex(ord325, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask324(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[0];
        u64 v_c55 = _t[1];
        u64 v_c56 = _t[2];
        u64 v_c57 = _t[3];
        u64 v_c58 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c54}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask324* _cont = new ReadTask324(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask324(db,b), false);
  // (crule (pre) (scan apply1 __t8ML628 __t4Oei27 n) (body (join _lam54764x18x33 (0 1) 1 __t4Oei27 k) (let __t4uOj26 (_0002a n k))) (head (emit-temp temp0r94312 __t4uOj26 __t8ML628)) dem_lambda.slog:19 #f)
  class ReadTask328 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _lam54764x18x33index327;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0r94312");
      outer_rel = db->getRelation("apply1");
      std::vector<u16> ord329({0, 1});
      slog::Relation* readrel330 = db->getRelation("_lam54764x18x33");
      _lam54764x18x33index327 = readrel330->getIndex(ord329, false);
  
    }
    ReadTask328(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe<2,1>(_lam54764x18x33index327, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m331) {
          u64 v_c61 = m331[1];
          u64 v_c62 = _prim__0002a(db, v_c4, v_c61);
          if (v_c62 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:19"); return; }
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c62, v_c59});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:19", "delta:apply1", _fires);
  
      if (!_done)
      {
        ReadTask328* _cont = new ReadTask328(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask328(db,b), false);
  // (crule (pre) (scan apply1_ans __t68lH41 __v1) (body (join-old apply1 (0 1 2) 1 (0 1 2) __t68lH41 f __v0) (exists _lam54764x22x18 (1 2 0) 1 f) (exists $sup54764x22x18x0x0 (1 2 3 0) 1 f) (join apply1_ans (1 0) 1 __v0 __t5wmm40) (join _lam54764x22x18 (1 2 0) 1 f g __t515s38) (exists $sup54764x22x18x0x0 (1 2 3 0) 2 f g) (exists apply1 (1 2 0) 1 __t515s38) (join-old apply1 (0 1 2) 2 (0 1 2) __t5wmm40 g x) (exists apply1 (1 2 0) 2 __t515s38 x) (join-old $sup54764x22x18x0x0 (1 2 3 0) 3 (1 2 3 0) f g x __t288X39) (join-old apply1 (0 1 2) 3 (0 1 2) __t288X39 __t515s38 x)) (head (emit apply1_ans (0 1) __t288X39 __v1)) dem_lambda.slog:23 #f)
  class ReadTask347 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** apply1index332;  slog::Index** _lam54764x22x18index333;  slog::Index** $sup54764x22x18x0x0index334;  slog::Index** apply1_ansindex335;  slog::Index** _lam54764x22x18index336;  slog::Index** $sup54764x22x18x0x0index337;  slog::Index** apply1index338;  slog::Index** apply1index339;  slog::Index** apply1index340;  slog::Index** $sup54764x22x18x0x0index341;  slog::Index** apply1index342;  slog::Index** apply1delta343;  slog::Index** apply1delta344;  slog::Index** $sup54764x22x18x0x0delta345;  slog::Index** apply1delta346;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("apply1_ans");
      std::vector<u16> ord348({0, 1});
      slog::Relation* readrel349 = db->getRelation("apply1_ans");
      head_index[0] = readrel349->getIndex(ord348, false);
      outer_rel = db->getRelation("apply1_ans");
      std::vector<u16> ord350({0, 1, 2});
      slog::Relation* readrel351 = db->getRelation("apply1");
      apply1index332 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({0, 1, 2});
      slog::Relation* readrel353 = db->getRelation("apply1");
      apply1delta343 = readrel353->getIndex(ord352, true);
      std::vector<u16> ord354({1, 2, 0});
      slog::Relation* readrel355 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index333 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({1, 2, 3, 0});
      slog::Relation* readrel357 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index334 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({1, 0});
      slog::Relation* readrel359 = db->getRelation("apply1_ans");
      apply1_ansindex335 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({1, 2, 0});
      slog::Relation* readrel361 = db->getRelation("_lam54764x22x18");
      _lam54764x22x18index336 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({1, 2, 3, 0});
      slog::Relation* readrel363 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index337 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({1, 2, 0});
      slog::Relation* readrel365 = db->getRelation("apply1");
      apply1index338 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({0, 1, 2});
      slog::Relation* readrel367 = db->getRelation("apply1");
      apply1index339 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({0, 1, 2});
      slog::Relation* readrel369 = db->getRelation("apply1");
      apply1delta344 = readrel369->getIndex(ord368, true);
      std::vector<u16> ord370({1, 2, 0});
      slog::Relation* readrel371 = db->getRelation("apply1");
      apply1index340 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 2, 3, 0});
      slog::Relation* readrel373 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0index341 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 2, 3, 0});
      slog::Relation* readrel375 = db->getRelation("$sup54764x22x18x0x0");
      $sup54764x22x18x0x0delta345 = readrel375->getIndex(ord374, true);
      std::vector<u16> ord376({0, 1, 2});
      slog::Relation* readrel377 = db->getRelation("apply1");
      apply1index342 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 1, 2});
      slog::Relation* readrel379 = db->getRelation("apply1");
      apply1delta346 = readrel379->getIndex(ord378, true);
  
    }
    ReadTask347(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[1];
        slog::join_probe_old<3,1>(apply1index332, apply1delta343, std::array<u64,3>{v_c42, 0, 0}, [&](const std::array<u64,3>& m380) {
          u64 v_c13 = m380[1]; u64 v_c14 = m380[2];
          if (!slog::exists_probe<3,1>(_lam54764x22x18index333, std::array<u64,3>{v_c13, 0, 0})) return;
          if (!slog::exists_probe<4,1>($sup54764x22x18x0x0index334, std::array<u64,4>{v_c13, 0, 0, 0})) return;
          slog::join_probe<2,1>(apply1_ansindex335, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m381) {
            u64 v_c43 = m381[1];
            slog::join_probe<3,1>(_lam54764x22x18index336, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m382) {
              u64 v_c10 = m382[1]; u64 v_c45 = m382[2];
              if (!slog::exists_probe<4,2>($sup54764x22x18x0x0index337, std::array<u64,4>{v_c13, v_c10, 0, 0})) return;
              if (!slog::exists_probe<3,1>(apply1index338, std::array<u64,3>{v_c45, 0, 0})) return;
              slog::join_probe_old<3,2>(apply1index339, apply1delta344, std::array<u64,3>{v_c43, v_c10, 0}, [&](const std::array<u64,3>& m383) {
                u64 v_c11 = m383[2];
                if (!slog::exists_probe<3,2>(apply1index340, std::array<u64,3>{v_c45, v_c11, 0})) return;
                slog::join_probe_old<4,3>($sup54764x22x18x0x0index341, $sup54764x22x18x0x0delta345, std::array<u64,4>{v_c13, v_c10, v_c11, 0}, [&](const std::array<u64,4>& m384) {
                  u64 v_c46 = m384[3];
                  slog::join_probe_old<3,3>(apply1index342, apply1delta346, std::array<u64,3>{v_c46, v_c45, v_c11}, [&](const std::array<u64,3>& m385) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c46, v_c44}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:apply1_ans", _fires);
  
      if (!_done)
      {
        ReadTask347* _cont = new ReadTask347(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask347(db,b), false);
  // (crule (pre) (scan temp0r94312 __t4uOj26 __t8ML628) (body) (head (emit apply1_ans (0 1) __t8ML628 __t4uOj26)) dem_lambda.slog:19 #f)
  class ReadTask386 : public slog::Task
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
      head_rel[0] = db->getRelation("apply1_ans");
      std::vector<u16> ord387({0, 1});
      slog::Relation* readrel388 = db->getRelation("apply1_ans");
      head_index[0] = readrel388->getIndex(ord387, false);
      outer_rel = db->getRelation("temp0r94312");
  
    }
    ReadTask386(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c59, v_c62}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:19", "delta:temp0r94312", _fires);
  
      if (!_done)
      {
        ReadTask386* _cont = new ReadTask386(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask386(db,b), false);
  // (crule (pre (let __trid8IXr97 constd20c23bad354bda74806a4f5) (let __trel6nKb98 const25e7b0e6bcacc29ff436fea9) (let __tcol0DjC99 const5feceb66ffc86f38d952786c)) (scan $sup54764x22x18x0x0 __d0 f g x) (body) (head (tycheck g (accept (struct _lam54764x18x33) (struct _lam54764x22x18) (struct _enum)) __trid8IXr97 __trel6nKb98 __tcol0DjC99 (1 2 3 4 0)) (mkstruct apply1 (1 2 0) __2lm196 g x)) dem_lambda.slog:23 #f)
  class ReadTask392 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid391;  u32 sid389;  u32 sid390;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("apply1");
      outer_rel = db->getRelation("$sup54764x22x18x0x0");
      sid391 = db->getRelation("_enum")->getStructId();
      sid389 = db->getRelation("_lam54764x18x33")->getStructId();
      sid390 = db->getRelation("_lam54764x22x18")->getStructId();
  
    }
    ReadTask392(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c63 = v_constd20c23bad354bda74806a4f5;
      u64 v_c64 = v_const25e7b0e6bcacc29ff436fea9;
      u64 v_c65 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c12 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        ++_fires;
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid389 || decode_struct_id(v_c10) == sid390 || decode_struct_id(v_c10) == sid391))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c63, v_c64, v_c65, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:23", "delta:$sup54764x22x18x0x0", _fires);
  
      if (!_done)
      {
        ReadTask392* _cont = new ReadTask392(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask392(db,b), false);
  // (crule (pre) (scan toint_range __erre0Tuh296 __errf2EAJ297 __errf9H0z298) (body) (head (emit error (0) __erre0Tuh296)) <internal>:1 #f)
  class ReadTask393 : public slog::Task
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
      std::vector<u16> ord394({0});
      slog::Relation* readrel395 = db->getRelation("error");
      head_index[0] = readrel395->getIndex(ord394, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask393(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask393* _cont = new ReadTask393(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask393(db,b), false);
  // (crule (pre) (scan int_overflow __erre7SIx288 __errf9ad5289 __errf4hkx290 __errf6ssl291) (body) (head (emit error (0) __erre7SIx288)) <internal>:1 #f)
  class ReadTask396 : public slog::Task
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
      std::vector<u16> ord397({0});
      slog::Relation* readrel398 = db->getRelation("error");
      head_index[0] = readrel398->getIndex(ord397, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask396(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c69 = _t[0];
        u64 v_c70 = _t[1];
        u64 v_c71 = _t[2];
        u64 v_c72 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c69}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask396* _cont = new ReadTask396(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask396(db,b), false);
  s->addReadRel("$sup54764x22x18x0x0");
  s->addReadRel("$sup54764x9x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("_lam54764x18x33");
  s->addReadRel("_lam54764x22x18");
  s->addReadRel("apply1");
  s->addReadRel("apply1_ans");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp0G00313");
  s->addReadRel("temp0r94312");
  s->addReadRel("temp687o314");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$sup54764x22x18x0x0");
  s->addDynamicRel("apply1");
  s->addDynamicRel("apply1_ans");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("temp0G00313");
  s->addDynamicRel("temp0r94312");
  s->addDynamicRel("temp687o314");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("apply1_ans");
  d->push(s);
  d->continueRun();
}

