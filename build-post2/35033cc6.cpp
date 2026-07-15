
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const2de92c8721196a7a472d40b9;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const33dffa18ca3f56970d9625f0;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const97812a371f0b154056f7af1a;
u64 v_const933b575c961e931c43e84b05;
u64 v_const9ac63e4426dab2edcc97bcf7;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("35033cc6");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const2de92c8721196a7a472d40b9 = db->encodeString("apply");
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const33dffa18ca3f56970d9625f0 = db->encodeString("map");
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const97812a371f0b154056f7af1a = db->encodeString("dem_map.slog:19");
  v_const933b575c961e931c43e84b05 = db->encodeString("dbl");
  v_const9ac63e4426dab2edcc97bcf7 = db->encodeString("cnil");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord554({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord554, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord555({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord555, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord556({1, 2, 0});
    
    r->addIndex<3>(ord556, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord557({0, 1, 2});
    
    r->addIndex<3>(ord557, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp8PY9125");
  if (r == 0) db->addTempRelation("temp8PY9125", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp19Ou126");
  if (r == 0) db->addTempRelation("temp19Ou126", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord558({1, 2, 0});
    
    r->addIndex<3>(ord558, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord559({0, 1, 2});
    
    r->addIndex<3>(ord559, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord560({1, 2, 3, 0});
    
    r->addIndex<4>(ord560, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord561({0, 1, 2, 3});
    
    r->addIndex<4>(ord561, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord562({1, 2, 0});
    
    r->addIndex<3>(ord562, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord563({0, 1, 2});
    
    r->addIndex<3>(ord563, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord564({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord564, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord565({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord565, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord566({1, 2, 0});
    
    r->addIndex<3>(ord566, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord567({0, 1, 2});
    
    r->addIndex<3>(ord567, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("map_ans");
  if (r == 0) db->addRelation("map_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map_ans");
      std::vector<u16> ord568({0, 1});
    
    r->addIndex<2>(ord568, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord569({0, 1});
    
    r->addIndex<2>(ord569, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("map_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("map");
  if (r == 0) db->addStruct("map", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map");
      std::vector<u16> ord570({1, 2, 0});
    
    r->addIndex<3>(ord570, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord571({0, 1, 2});
    
    r->addIndex<3>(ord571, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord572({2, 0, 1});
    
    r->addIndex<3>(ord572, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord573({0, 1, 2});
    
    r->addIndex<3>(ord573, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord574({1, 2, 0});
    
    r->addIndex<3>(ord574, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord575({2, 0, 1});
    
    r->addIndex<3>(ord575, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("map"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord576({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord576, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord577({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord577, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord578({1, 2, 3, 0});
    
    r->addIndex<4>(ord578, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord579({0, 1, 2, 3});
    
    r->addIndex<4>(ord579, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("input");
  if (r == 0) db->addRelation("input", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("input");
      std::vector<u16> ord580({0});
    
    r->addIndex<1>(ord580, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("input"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord581({0});
    
    r->addIndex<1>(ord581, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("doubled");
  if (r == 0) db->addRelation("doubled", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("doubled");
      std::vector<u16> ord582({0});
    
    r->addIndex<1>(ord582, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("doubled"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord583({1, 2, 0});
    
    r->addIndex<3>(ord583, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord584({0, 1, 2});
    
    r->addIndex<3>(ord584, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ccons");
  if (r == 0) db->addStruct("ccons", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ccons");
      std::vector<u16> ord585({1, 2, 0});
    
    r->addIndex<3>(ord585, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord586({0, 1, 2});
    
    r->addIndex<3>(ord586, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord587({2, 0, 1});
    
    r->addIndex<3>(ord587, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord588({1, 2, 0});
    
    r->addIndex<3>(ord588, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ccons"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bumped");
  if (r == 0) db->addRelation("bumped", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bumped");
      std::vector<u16> ord589({0});
    
    r->addIndex<1>(ord589, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("bumped"), std::array<u16,1>{0}, b));
  r = db->getRelation("apply_ans");
  if (r == 0) db->addRelation("apply_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply_ans");
      std::vector<u16> ord590({0, 1});
    
    r->addIndex<2>(ord590, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("apply_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("apply");
  if (r == 0) db->addStruct("apply", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply");
      std::vector<u16> ord591({1, 2, 0});
    
    r->addIndex<3>(ord591, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord592({0, 1, 2});
    
    r->addIndex<3>(ord592, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord593({2, 0, 1});
    
    r->addIndex<3>(ord593, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord594({0, 1, 2});
    
    r->addIndex<3>(ord594, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord595({1, 2, 0});
    
    r->addIndex<3>(ord595, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("apply"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("addk");
  if (r == 0) db->addStruct("addk", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("addk");
      std::vector<u16> ord596({1, 0});
    
    r->addIndex<2>(ord596, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord597({0, 1});
    
    r->addIndex<2>(ord597, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("addk"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord598({1, 0});
    
    r->addIndex<2>(ord598, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord599({0, 1});
    
    r->addIndex<2>(ord599, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord600({1, 0});
    
    r->addIndex<2>(ord600, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup80907x18x0x0x0");
  if (r == 0) db->addRelation("$sup80907x18x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup80907x18x0x0x0");
      std::vector<u16> ord601({0, 1, 2, 3});
    
    r->addIndex<4>(ord601, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
      std::vector<u16> ord602({1, 2, 0, 3});
    
    r->addIndex<4>(ord602, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 0, 3}, false, b), false);
      std::vector<u16> ord603({1, 3, 0, 2});
    
    r->addIndex<4>(ord603, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 0, 2}, false, b), false);
      std::vector<u16> ord604({2, 3, 0, 1});
    
    r->addIndex<4>(ord604, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), false);
      std::vector<u16> ord605({1, 2, 0, 3});
    
    r->addIndex<4>(ord605, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 0, 3}, true, b), false);
      std::vector<u16> ord606({1, 3, 0, 2});
    
    r->addIndex<4>(ord606, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup80907x18x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  // (crule (pre (let __trid9LQ645 const97812a371f0b154056f7af1a) (let __trel1Aw346 const2de92c8721196a7a472d40b9) (let __tcol9hxE47 const5feceb66ffc86f38d952786c) (let __trel6Lag48 const2de92c8721196a7a472d40b9) (let __tcol7Yww49 const6b86b273ff34fce19d6b804e)) (scan $sup80907x18x0x0x0 __d0 f x xs) (body) (head (tycheck f (accept (struct addk) (struct _enum)) __trid9LQ645 __trel1Aw346 __tcol9hxE47 (1 2 3 4 0)) (tycheck x (accept int) __trid9LQ645 __trel6Lag48 __tcol7Yww49 (1 2 3 4 0)) (mkstruct apply (1 2 0) __7fzk44 f x)) dem_map.slog:19 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1;  u32 sid0;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("apply");
      outer_rel = db->getRelation("$sup80907x18x0x0x0");
      sid1 = db->getRelation("_enum")->getStructId();
      sid0 = db->getRelation("addk")->getStructId();
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const97812a371f0b154056f7af1a;
      u64 v_c1 = v_const2de92c8721196a7a472d40b9;
      u64 v_c2 = v_const5feceb66ffc86f38d952786c;
      u64 v_c3 = v_const2de92c8721196a7a472d40b9;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        ++_fires;
        if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid0 || decode_struct_id(v_c6) == sid1))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c7)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c0, v_c3, v_c4, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c7}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:$sup80907x18x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask2* _cont = new ReadTask2(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2(db,b), false);
  // (crule (pre) (scan temp19Ou126 __t4Z5K3 y ys) (body (join ccons (1 2 0) 2 y ys __t92ia1)) (head (emit map_ans (0 1) __t4Z5K3 __t92ia1)) dem_map.slog:19 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("map_ans");
      std::vector<u16> ord5({0, 1});
      slog::Relation* readrel6 = db->getRelation("map_ans");
      head_index[0] = readrel6->getIndex(ord5, false);
      outer_rel = db->getRelation("temp19Ou126");
      std::vector<u16> ord7({1, 2, 0});
      slog::Relation* readrel8 = db->getRelation("ccons");
      cconsindex3 = readrel8->getIndex(ord7, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<3,2>(cconsindex3, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m9) {
          u64 v_c12 = m9[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c9, v_c12}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:temp19Ou126", _fires);
  
      if (!_done)
      {
        ReadTask4* _cont = new ReadTask4(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask4(db,b), false);
  // (crule (pre (let __tconst0E1z28 const6b86b273ff34fce19d6b804e) (let __tconst6vOH26 constd4735e3a265e16eee03f5971) (let __tconst5eH624 const4e07408562bedb8b60ce05c1) (let __tconst0UaC33 const9ac63e4426dab2edcc97bcf7)) (probe ccons (1 2 0) 1 __tconst0E1z28 __t27yb27 __t4hla29) (body (exists ccons (1 2 0) 1 __tconst5eH624) (exists _enum (1 0) 1 __tconst0UaC33) (join ccons (0 1 2) 2 __t27yb27 __tconst6vOH26 __t2qiY25) (join ccons (0 1 2) 2 __t2qiY25 __tconst5eH624 __t5CBi23) (join _enum (0 1) 2 __t5CBi23 __tconst0UaC33)) (head (emit input (0) __t4hla29)) dem_map.slog:24 #f)
  class ReadTask15 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** cconsindex10;  slog::Index** _enumindex11;  slog::Index** cconsindex12;  slog::Index** cconsindex13;  slog::Index** _enumindex14;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("input");
      std::vector<u16> ord16({0});
      slog::Relation* readrel17 = db->getRelation("input");
      head_index[0] = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 2, 0});
      slog::Relation* readrel19 = db->getRelation("ccons");
      driver_index = readrel19->getIndex(ord18, true);
      std::vector<u16> ord20({1, 2, 0});
      slog::Relation* readrel21 = db->getRelation("ccons");
      cconsindex10 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("_enum");
      _enumindex11 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({0, 1, 2});
      slog::Relation* readrel25 = db->getRelation("ccons");
      cconsindex12 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({0, 1, 2});
      slog::Relation* readrel27 = db->getRelation("ccons");
      cconsindex13 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("_enum");
      _enumindex14 = readrel29->getIndex(ord28, false);
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c13, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m30) {
        u64 v_c17 = m30[1];
        u64 v_c18 = m30[2];
        if (buckethash(v_c17) != bucket) return;
        if (!slog::exists_probe<3,1>(cconsindex10, std::array<u64,3>{v_c15, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex11, std::array<u64,2>{v_c16, 0})) return;
        slog::join_probe<3,2>(cconsindex12, std::array<u64,3>{v_c17, v_c14, 0}, [&](const std::array<u64,3>& m31) {
          u64 v_c19 = m31[2];
          slog::join_probe<3,2>(cconsindex13, std::array<u64,3>{v_c19, v_c15, 0}, [&](const std::array<u64,3>& m32) {
            u64 v_c20 = m32[2];
            slog::join_probe<2,2>(_enumindex14, std::array<u64,2>{v_c20, v_c16}, [&](const std::array<u64,2>& m33) {
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:24", "delta:ccons", _fires);
  
      if (!_done)
      {
        ReadTask15* _cont = new ReadTask15(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), false);
  // (crule (pre) (scan addk __t8mEP12 k) (body (join-old apply (1 2 0) 1 (1 2 0) __t8mEP12 n __t6S8413) (let __t30Ae14 (_0002b n k))) (head (emit apply_ans (0 1) __t6S8413 __t30Ae14)) dem_map.slog:14 #f)
  class ReadTask36 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** applyindex34;  slog::Index** applydelta35;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("apply_ans");
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("apply_ans");
      head_index[0] = readrel38->getIndex(ord37, false);
      outer_rel = db->getRelation("addk");
      std::vector<u16> ord39({1, 2, 0});
      slog::Relation* readrel40 = db->getRelation("apply");
      applyindex34 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("apply");
      applydelta35 = readrel42->getIndex(ord41, true);
  
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
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_probe_old<3,1>(applyindex34, applydelta35, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m43) {
          u64 v_c23 = m43[1]; u64 v_c24 = m43[2];
          u64 v_c25 = _prim__0002b(db, v_c23, v_c22);
          if (v_c25 == slog_error) { slog::emit_pending_error(db, "dem_map.slog:14"); return; }
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c25}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:14", "delta:addk", _fires);
  
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
  // (crule (pre) (scan $sup80907x18x0x0x0 __t4Z5K3 f x xs) (body (exists map (0 1 2) 2 __t4Z5K3 f) (exists apply (1 2 0) 2 f x) (exists map (1 2 0) 2 f xs) (join-old ccons (1 2 0) 2 (1 2 0) x xs __t7M342) (join-old map (0 1 2) 3 (0 1 2) __t4Z5K3 f __t7M342) (join-old apply (1 2 0) 2 (1 2 0) f x __t0IeY4) (exists apply_ans (0 1) 1 __t0IeY4) (join-old map (1 2 0) 2 (1 2 0) f xs __t0ipb5) (exists map_ans (0 1) 1 __t0ipb5) (join apply_ans (0 1) 1 __t0IeY4 y) (join map_ans (0 1) 1 __t0ipb5 ys)) (head (emit-temp temp19Ou126 __t4Z5K3 y ys) (mkstruct ccons (1 2 0) __t92ia1 y ys)) dem_map.slog:19 #f)
  class ReadTask59 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mapindex44;  slog::Index** applyindex45;  slog::Index** mapindex46;  slog::Index** cconsindex47;  slog::Index** mapindex48;  slog::Index** applyindex49;  slog::Index** apply_ansindex50;  slog::Index** mapindex51;  slog::Index** map_ansindex52;  slog::Index** apply_ansindex53;  slog::Index** map_ansindex54;  slog::Index** cconsdelta55;  slog::Index** mapdelta56;  slog::Index** applydelta57;  slog::Index** mapdelta58;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp19Ou126");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("$sup80907x18x0x0x0");
      std::vector<u16> ord60({0, 1, 2});
      slog::Relation* readrel61 = db->getRelation("map");
      mapindex44 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({1, 2, 0});
      slog::Relation* readrel63 = db->getRelation("apply");
      applyindex45 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 2, 0});
      slog::Relation* readrel65 = db->getRelation("map");
      mapindex46 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 2, 0});
      slog::Relation* readrel67 = db->getRelation("ccons");
      cconsindex47 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 2, 0});
      slog::Relation* readrel69 = db->getRelation("ccons");
      cconsdelta55 = readrel69->getIndex(ord68, true);
      std::vector<u16> ord70({0, 1, 2});
      slog::Relation* readrel71 = db->getRelation("map");
      mapindex48 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({0, 1, 2});
      slog::Relation* readrel73 = db->getRelation("map");
      mapdelta56 = readrel73->getIndex(ord72, true);
      std::vector<u16> ord74({1, 2, 0});
      slog::Relation* readrel75 = db->getRelation("apply");
      applyindex49 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 2, 0});
      slog::Relation* readrel77 = db->getRelation("apply");
      applydelta57 = readrel77->getIndex(ord76, true);
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("apply_ans");
      apply_ansindex50 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 2, 0});
      slog::Relation* readrel81 = db->getRelation("map");
      mapindex51 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 2, 0});
      slog::Relation* readrel83 = db->getRelation("map");
      mapdelta58 = readrel83->getIndex(ord82, true);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("map_ans");
      map_ansindex52 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({0, 1});
      slog::Relation* readrel87 = db->getRelation("apply_ans");
      apply_ansindex53 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({0, 1});
      slog::Relation* readrel89 = db->getRelation("map_ans");
      map_ansindex54 = readrel89->getIndex(ord88, false);
  
    }
    ReadTask59(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        if (!slog::exists_probe<3,2>(mapindex44, std::array<u64,3>{v_c9, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(applyindex45, std::array<u64,3>{v_c6, v_c7, 0})) return;
        if (!slog::exists_probe<3,2>(mapindex46, std::array<u64,3>{v_c6, v_c8, 0})) return;
        slog::join_probe_old<3,2>(cconsindex47, cconsdelta55, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m90) {
          u64 v_c26 = m90[2];
          slog::join_probe_old<3,3>(mapindex48, mapdelta56, std::array<u64,3>{v_c9, v_c6, v_c26}, [&](const std::array<u64,3>& m91) {
            slog::join_probe_old<3,2>(applyindex49, applydelta57, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m92) {
              u64 v_c27 = m92[2];
              if (!slog::exists_probe<2,1>(apply_ansindex50, std::array<u64,2>{v_c27, 0})) return;
              slog::join_probe_old<3,2>(mapindex51, mapdelta58, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m93) {
                u64 v_c28 = m93[2];
                if (!slog::exists_probe<2,1>(map_ansindex52, std::array<u64,2>{v_c28, 0})) return;
                slog::join_probe<2,1>(apply_ansindex53, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m94) {
                  u64 v_c10 = m94[1];
                  slog::join_probe<2,1>(map_ansindex54, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m95) {
                    u64 v_c11 = m95[1];
                    ++_fires;
                    slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c9, v_c10, v_c11});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:$sup80907x18x0x0x0", _fires);
  
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
      s->addTask(phase_read, new ReadTask59(db,b), false);
  // (crule (pre) (scan ccons __t7M342 x xs) (body (exists map (2 0 1) 1 __t7M342) (exists apply (2 0 1) 1 x) (exists map (2 0 1) 1 xs) (join $sup80907x18x0x0x0 (2 3 0 1) 2 x xs __t4Z5K3 f) (join-old map (0 1 2) 3 (0 1 2) __t4Z5K3 f __t7M342) (exists map (1 2 0) 2 f xs) (join-old apply (1 2 0) 2 (1 2 0) f x __t0IeY4) (exists apply_ans (0 1) 1 __t0IeY4) (join-old map (1 2 0) 2 (1 2 0) f xs __t0ipb5) (exists map_ans (0 1) 1 __t0ipb5) (join apply_ans (0 1) 1 __t0IeY4 y) (join map_ans (0 1) 1 __t0ipb5 ys)) (head (emit-temp temp19Ou126 __t4Z5K3 y ys) (mkstruct ccons (1 2 0) __t92ia1 y ys)) dem_map.slog:19 #f)
  class ReadTask111 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mapindex96;  slog::Index** applyindex97;  slog::Index** mapindex98;  slog::Index** $sup80907x18x0x0x0index99;  slog::Index** mapindex100;  slog::Index** mapindex101;  slog::Index** applyindex102;  slog::Index** apply_ansindex103;  slog::Index** mapindex104;  slog::Index** map_ansindex105;  slog::Index** apply_ansindex106;  slog::Index** map_ansindex107;  slog::Index** mapdelta108;  slog::Index** applydelta109;  slog::Index** mapdelta110;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp19Ou126");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ccons");
      std::vector<u16> ord112({2, 0, 1});
      slog::Relation* readrel113 = db->getRelation("map");
      mapindex96 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({2, 0, 1});
      slog::Relation* readrel115 = db->getRelation("apply");
      applyindex97 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({2, 0, 1});
      slog::Relation* readrel117 = db->getRelation("map");
      mapindex98 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({2, 3, 0, 1});
      slog::Relation* readrel119 = db->getRelation("$sup80907x18x0x0x0");
      $sup80907x18x0x0x0index99 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({0, 1, 2});
      slog::Relation* readrel121 = db->getRelation("map");
      mapindex100 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({0, 1, 2});
      slog::Relation* readrel123 = db->getRelation("map");
      mapdelta108 = readrel123->getIndex(ord122, true);
      std::vector<u16> ord124({1, 2, 0});
      slog::Relation* readrel125 = db->getRelation("map");
      mapindex101 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("apply");
      applyindex102 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("apply");
      applydelta109 = readrel129->getIndex(ord128, true);
      std::vector<u16> ord130({0, 1});
      slog::Relation* readrel131 = db->getRelation("apply_ans");
      apply_ansindex103 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("map");
      mapindex104 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 2, 0});
      slog::Relation* readrel135 = db->getRelation("map");
      mapdelta110 = readrel135->getIndex(ord134, true);
      std::vector<u16> ord136({0, 1});
      slog::Relation* readrel137 = db->getRelation("map_ans");
      map_ansindex105 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({0, 1});
      slog::Relation* readrel139 = db->getRelation("apply_ans");
      apply_ansindex106 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({0, 1});
      slog::Relation* readrel141 = db->getRelation("map_ans");
      map_ansindex107 = readrel141->getIndex(ord140, false);
  
    }
    ReadTask111(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<3,1>(mapindex96, std::array<u64,3>{v_c26, 0, 0})) return;
        if (!slog::exists_probe<3,1>(applyindex97, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mapindex98, std::array<u64,3>{v_c8, 0, 0})) return;
        slog::join_probe<4,2>($sup80907x18x0x0x0index99, std::array<u64,4>{v_c7, v_c8, 0, 0}, [&](const std::array<u64,4>& m142) {
          u64 v_c9 = m142[2]; u64 v_c6 = m142[3];
          slog::join_probe_old<3,3>(mapindex100, mapdelta108, std::array<u64,3>{v_c9, v_c6, v_c26}, [&](const std::array<u64,3>& m143) {
            if (!slog::exists_probe<3,2>(mapindex101, std::array<u64,3>{v_c6, v_c8, 0})) return;
            slog::join_probe_old<3,2>(applyindex102, applydelta109, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m144) {
              u64 v_c27 = m144[2];
              if (!slog::exists_probe<2,1>(apply_ansindex103, std::array<u64,2>{v_c27, 0})) return;
              slog::join_probe_old<3,2>(mapindex104, mapdelta110, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m145) {
                u64 v_c28 = m145[2];
                if (!slog::exists_probe<2,1>(map_ansindex105, std::array<u64,2>{v_c28, 0})) return;
                slog::join_probe<2,1>(apply_ansindex106, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m146) {
                  u64 v_c10 = m146[1];
                  slog::join_probe<2,1>(map_ansindex107, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m147) {
                    u64 v_c11 = m147[1];
                    ++_fires;
                    slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c9, v_c10, v_c11});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:ccons", _fires);
  
      if (!_done)
      {
        ReadTask111* _cont = new ReadTask111(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask111(db,b), false);
  // (crule (pre (let __tconst0UaC33 const9ac63e4426dab2edcc97bcf7) (let __tconst0E1z28 const6b86b273ff34fce19d6b804e) (let __tconst6vOH26 constd4735e3a265e16eee03f5971) (let __tconst5eH624 const4e07408562bedb8b60ce05c1)) (probe _enum (1 0) 1 __tconst0UaC33 __t5CBi23) (body) (head (mkstruct ccons (1 2 0) __t2qiY25 __tconst5eH624 __t5CBi23)) dem_map.slog:24 #f)
  class ReadTask148 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ccons");
      std::vector<u16> ord149({1, 0});
      slog::Relation* readrel150 = db->getRelation("_enum");
      driver_index = readrel150->getIndex(ord149, true);
  
    }
    ReadTask148(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c16 = v_const9ac63e4426dab2edcc97bcf7;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c16, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m151) {
        u64 v_c20 = m151[1];
        if (buckethash(v_c20) != bucket) return;
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c20}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:24", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask148* _cont = new ReadTask148(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask148(db,b), true);
  // (crule (pre) (scan map_ans __t0ipb5 ys) (body (join-old map (0 1 2) 1 (0 1 2) __t0ipb5 f xs) (exists ccons (2 0 1) 1 xs) (exists map (1 2 0) 1 f) (exists apply (1 2 0) 1 f) (join-old $sup80907x18x0x0x0 (1 3 0 2) 2 (1 3 0 2) f xs __t4Z5K3 x) (exists map (0 1 2) 2 __t4Z5K3 f) (exists apply (1 2 0) 2 f x) (join-old ccons (1 2 0) 2 (1 2 0) x xs __t7M342) (join-old map (0 1 2) 3 (0 1 2) __t4Z5K3 f __t7M342) (join-old apply (1 2 0) 2 (1 2 0) f x __t0IeY4) (join apply_ans (0 1) 1 __t0IeY4 y)) (head (emit-temp temp19Ou126 __t4Z5K3 y ys) (mkstruct ccons (1 2 0) __t92ia1 y ys)) dem_map.slog:19 #f)
  class ReadTask168 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mapindex152;  slog::Index** cconsindex153;  slog::Index** mapindex154;  slog::Index** applyindex155;  slog::Index** $sup80907x18x0x0x0index156;  slog::Index** mapindex157;  slog::Index** applyindex158;  slog::Index** cconsindex159;  slog::Index** mapindex160;  slog::Index** applyindex161;  slog::Index** apply_ansindex162;  slog::Index** mapdelta163;  slog::Index** $sup80907x18x0x0x0delta164;  slog::Index** cconsdelta165;  slog::Index** mapdelta166;  slog::Index** applydelta167;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp19Ou126");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("map_ans");
      std::vector<u16> ord169({0, 1, 2});
      slog::Relation* readrel170 = db->getRelation("map");
      mapindex152 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1, 2});
      slog::Relation* readrel172 = db->getRelation("map");
      mapdelta163 = readrel172->getIndex(ord171, true);
      std::vector<u16> ord173({2, 0, 1});
      slog::Relation* readrel174 = db->getRelation("ccons");
      cconsindex153 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 2, 0});
      slog::Relation* readrel176 = db->getRelation("map");
      mapindex154 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("apply");
      applyindex155 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 3, 0, 2});
      slog::Relation* readrel180 = db->getRelation("$sup80907x18x0x0x0");
      $sup80907x18x0x0x0index156 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 3, 0, 2});
      slog::Relation* readrel182 = db->getRelation("$sup80907x18x0x0x0");
      $sup80907x18x0x0x0delta164 = readrel182->getIndex(ord181, true);
      std::vector<u16> ord183({0, 1, 2});
      slog::Relation* readrel184 = db->getRelation("map");
      mapindex157 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 2, 0});
      slog::Relation* readrel186 = db->getRelation("apply");
      applyindex158 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 2, 0});
      slog::Relation* readrel188 = db->getRelation("ccons");
      cconsindex159 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 2, 0});
      slog::Relation* readrel190 = db->getRelation("ccons");
      cconsdelta165 = readrel190->getIndex(ord189, true);
      std::vector<u16> ord191({0, 1, 2});
      slog::Relation* readrel192 = db->getRelation("map");
      mapindex160 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({0, 1, 2});
      slog::Relation* readrel194 = db->getRelation("map");
      mapdelta166 = readrel194->getIndex(ord193, true);
      std::vector<u16> ord195({1, 2, 0});
      slog::Relation* readrel196 = db->getRelation("apply");
      applyindex161 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 2, 0});
      slog::Relation* readrel198 = db->getRelation("apply");
      applydelta167 = readrel198->getIndex(ord197, true);
      std::vector<u16> ord199({0, 1});
      slog::Relation* readrel200 = db->getRelation("apply_ans");
      apply_ansindex162 = readrel200->getIndex(ord199, false);
  
    }
    ReadTask168(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_probe_old<3,1>(mapindex152, mapdelta163, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m201) {
          u64 v_c6 = m201[1]; u64 v_c8 = m201[2];
          if (!slog::exists_probe<3,1>(cconsindex153, std::array<u64,3>{v_c8, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mapindex154, std::array<u64,3>{v_c6, 0, 0})) return;
          if (!slog::exists_probe<3,1>(applyindex155, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe_old<4,2>($sup80907x18x0x0x0index156, $sup80907x18x0x0x0delta164, std::array<u64,4>{v_c6, v_c8, 0, 0}, [&](const std::array<u64,4>& m202) {
            u64 v_c9 = m202[2]; u64 v_c7 = m202[3];
            if (!slog::exists_probe<3,2>(mapindex157, std::array<u64,3>{v_c9, v_c6, 0})) return;
            if (!slog::exists_probe<3,2>(applyindex158, std::array<u64,3>{v_c6, v_c7, 0})) return;
            slog::join_probe_old<3,2>(cconsindex159, cconsdelta165, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m203) {
              u64 v_c26 = m203[2];
              slog::join_probe_old<3,3>(mapindex160, mapdelta166, std::array<u64,3>{v_c9, v_c6, v_c26}, [&](const std::array<u64,3>& m204) {
                slog::join_probe_old<3,2>(applyindex161, applydelta167, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m205) {
                  u64 v_c27 = m205[2];
                  slog::join_probe<2,1>(apply_ansindex162, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m206) {
                    u64 v_c10 = m206[1];
                    ++_fires;
                    slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c9, v_c10, v_c11});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:map_ans", _fires);
  
      if (!_done)
      {
        ReadTask168* _cont = new ReadTask168(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask168(db,b), false);
  // (crule (pre) (scan type_mismatch __erre2XI3112 __errf1PWO113 __errf6rl6114 __errf01QG115 __errf5bdY116) (body) (head (emit error (0) __erre2XI3112)) <internal>:1 #f)
  class ReadTask207 : public slog::Task
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
      std::vector<u16> ord208({0});
      slog::Relation* readrel209 = db->getRelation("error");
      head_index[0] = readrel209->getIndex(ord208, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask207(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c29 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c31 = _t[2];
        u64 v_c32 = _t[3];
        u64 v_c33 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c29}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask207* _cont = new ReadTask207(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask207(db,b), false);
  // (crule (pre (let __tconst7ohR41 const9ac63e4426dab2edcc97bcf7)) (scan map __t37yS11 f __t1TdY10) (body (join _enum (0 1) 2 __t1TdY10 __tconst7ohR41)) (head (emit map_ans (0 1) __t37yS11 __t1TdY10)) dem_map.slog:18 #f)
  class ReadTask211 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex210;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("map_ans");
      std::vector<u16> ord212({0, 1});
      slog::Relation* readrel213 = db->getRelation("map_ans");
      head_index[0] = readrel213->getIndex(ord212, false);
      outer_rel = db->getRelation("map");
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("_enum");
      _enumindex210 = readrel215->getIndex(ord214, false);
  
    }
    ReadTask211(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c35 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c36 = _t[2];
        slog::join_probe<2,2>(_enumindex210, std::array<u64,2>{v_c36, v_c34}, [&](const std::array<u64,2>& m216) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c35, v_c36}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:18", "delta:map", _fires);
  
      if (!_done)
      {
        ReadTask211* _cont = new ReadTask211(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask211(db,b), false);
  // (crule (pre (let __tconst0E1z28 const6b86b273ff34fce19d6b804e) (let __tconst6vOH26 constd4735e3a265e16eee03f5971) (let __tconst5eH624 const4e07408562bedb8b60ce05c1) (let __tconst0UaC33 const9ac63e4426dab2edcc97bcf7)) (probe ccons (1 2 0) 1 __tconst6vOH26 __t2qiY25 __t27yb27) (body (exists _enum (1 0) 1 __tconst0UaC33) (join ccons (0 1 2) 2 __t2qiY25 __tconst5eH624 __t5CBi23) (join _enum (0 1) 2 __t5CBi23 __tconst0UaC33)) (head (mkstruct ccons (1 2 0) __t4hla29 __tconst0E1z28 __t27yb27)) dem_map.slog:24 #f)
  class ReadTask220 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex217;  slog::Index** cconsindex218;  slog::Index** _enumindex219;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ccons");
      std::vector<u16> ord221({1, 2, 0});
      slog::Relation* readrel222 = db->getRelation("ccons");
      driver_index = readrel222->getIndex(ord221, true);
      std::vector<u16> ord223({1, 0});
      slog::Relation* readrel224 = db->getRelation("_enum");
      _enumindex217 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({0, 1, 2});
      slog::Relation* readrel226 = db->getRelation("ccons");
      cconsindex218 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({0, 1});
      slog::Relation* readrel228 = db->getRelation("_enum");
      _enumindex219 = readrel228->getIndex(ord227, false);
  
    }
    ReadTask220(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c14, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m229) {
        u64 v_c19 = m229[1];
        u64 v_c17 = m229[2];
        if (buckethash(v_c19) != bucket) return;
        if (!slog::exists_probe<2,1>(_enumindex217, std::array<u64,2>{v_c16, 0})) return;
        slog::join_probe<3,2>(cconsindex218, std::array<u64,3>{v_c19, v_c15, 0}, [&](const std::array<u64,3>& m230) {
          u64 v_c20 = m230[2];
          slog::join_probe<2,2>(_enumindex219, std::array<u64,2>{v_c20, v_c16}, [&](const std::array<u64,2>& m231) {
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c13, v_c17}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:24", "delta:ccons", _fires);
  
      if (!_done)
      {
        ReadTask220* _cont = new ReadTask220(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask220(db,b), false);
  // (crule (pre) (scan nan_result __erre529a105 __errf7Tnr106 __errf33MK107 __errf4Jqx108) (body) (head (emit error (0) __erre529a105)) <internal>:1 #f)
  class ReadTask232 : public slog::Task
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
      std::vector<u16> ord233({0});
      slog::Relation* readrel234 = db->getRelation("error");
      head_index[0] = readrel234->getIndex(ord233, false);
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c37 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c39 = _t[2];
        u64 v_c40 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c37}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre) (scan map __t7Y7z31 f __t18rm30) (body (join ccons (0 1 2) 1 __t18rm30 x xs)) (head (emit $sup80907x18x0x0x0 (0 1 2 3) __t7Y7z31 f x xs)) dem_map.slog:19 #f)
  class ReadTask236 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex235;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup80907x18x0x0x0");
      std::vector<u16> ord237({0, 1, 2, 3});
      slog::Relation* readrel238 = db->getRelation("$sup80907x18x0x0x0");
      head_index[0] = readrel238->getIndex(ord237, false);
      outer_rel = db->getRelation("map");
      std::vector<u16> ord239({0, 1, 2});
      slog::Relation* readrel240 = db->getRelation("ccons");
      cconsindex235 = readrel240->getIndex(ord239, false);
  
    }
    ReadTask236(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c42 = _t[2];
        slog::join_probe<3,1>(cconsindex235, std::array<u64,3>{v_c42, 0, 0}, [&](const std::array<u64,3>& m241) {
          u64 v_c7 = m241[1]; u64 v_c8 = m241[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c41, v_c6, v_c7, v_c8}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:map", _fires);
  
      if (!_done)
      {
        ReadTask236* _cont = new ReadTask236(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask236(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre9Xgp122 __errf10rj123 __errf3yQY124) (body) (head (emit error (0) __erre9Xgp122)) <internal>:1 #f)
  class ReadTask242 : public slog::Task
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
      std::vector<u16> ord243({0});
      slog::Relation* readrel244 = db->getRelation("error");
      head_index[0] = readrel244->getIndex(ord243, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask242(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c43}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask242* _cont = new ReadTask242(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask242(db,b), false);
  // (crule (pre (let __tconst9UvB18 const4a44dc15364204a80fe80e90)) (scan temp8PY9125 l) (body (join addk (1 0) 1 __tconst9UvB18 __t0QoC19)) (head (mkstruct map (1 2 0) __3Dif32 __t0QoC19 l)) dem_map.slog:26 #f)
  class ReadTask246 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** addkindex245;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("map");
      outer_rel = db->getRelation("temp8PY9125");
      std::vector<u16> ord247({1, 0});
      slog::Relation* readrel248 = db->getRelation("addk");
      addkindex245 = readrel248->getIndex(ord247, false);
  
    }
    ReadTask246(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c46 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c47 = _t[0];
        slog::join_probe<2,1>(addkindex245, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m249) {
          u64 v_c48 = m249[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c48, v_c47}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:26", "delta:temp8PY9125", _fires);
  
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
  // (crule (pre (let __tconst0E1z28 const6b86b273ff34fce19d6b804e) (let __tconst6vOH26 constd4735e3a265e16eee03f5971) (let __tconst5eH624 const4e07408562bedb8b60ce05c1) (let __tconst0UaC33 const9ac63e4426dab2edcc97bcf7)) (seeded) (body (join _enum (1 0) 1 __tconst0UaC33 __t5CBi23) (exists ccons (1 2 0) 1 __tconst6vOH26) (join ccons (1 2 0) 2 __tconst5eH624 __t5CBi23 __t2qiY25) (join ccons (1 2 0) 2 __tconst6vOH26 __t2qiY25 __t27yb27)) (head (mkstruct ccons (1 2 0) __t4hla29 __tconst0E1z28 __t27yb27)) dem_map.slog:24 #f)
  class ReadTask254 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex250;  slog::Index** cconsindex251;  slog::Index** cconsindex252;  slog::Index** cconsindex253;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ccons");
      std::vector<u16> ord255({1, 2, 0});
      slog::Relation* readrel256 = db->getRelation("ccons");
      head_index[0] = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 0});
      slog::Relation* readrel258 = db->getRelation("_enum");
      _enumindex250 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("ccons");
      cconsindex251 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 2, 0});
      slog::Relation* readrel262 = db->getRelation("ccons");
      cconsindex252 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 2, 0});
      slog::Relation* readrel264 = db->getRelation("ccons");
      cconsindex253 = readrel264->getIndex(ord263, false);
  
    }
    ReadTask254(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex250, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m265) {
        u64 v_c20 = m265[1];
        if (!slog::exists_probe<3,1>(cconsindex251, std::array<u64,3>{v_c14, 0, 0})) return;
        slog::join_probe<3,2>(cconsindex252, std::array<u64,3>{v_c15, v_c20, 0}, [&](const std::array<u64,3>& m266) {
          u64 v_c19 = m266[2];
          slog::join_probe<3,2>(cconsindex253, std::array<u64,3>{v_c14, v_c19, 0}, [&](const std::array<u64,3>& m267) {
            u64 v_c17 = m267[2];
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c17}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:24", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask254(db,b));
  // (crule (pre) (scan apply __t6S8413 __t8mEP12 n) (body (join addk (0 1) 1 __t8mEP12 k) (let __t30Ae14 (_0002b n k))) (head (emit apply_ans (0 1) __t6S8413 __t30Ae14)) dem_map.slog:14 #f)
  class ReadTask269 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** addkindex268;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("apply_ans");
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("apply_ans");
      head_index[0] = readrel271->getIndex(ord270, false);
      outer_rel = db->getRelation("apply");
      std::vector<u16> ord272({0, 1});
      slog::Relation* readrel273 = db->getRelation("addk");
      addkindex268 = readrel273->getIndex(ord272, false);
  
    }
    ReadTask269(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c24 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe<2,1>(addkindex268, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m274) {
          u64 v_c22 = m274[1];
          u64 v_c25 = _prim__0002b(db, v_c23, v_c22);
          if (v_c25 == slog_error) { slog::emit_pending_error(db, "dem_map.slog:14"); return; }
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c25}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:14", "delta:apply", _fires);
  
      if (!_done)
      {
        ReadTask269* _cont = new ReadTask269(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask269(db,b), false);
  // (crule (pre) (scan div_by_zero __erre6NQr95 __errf67wM96 __errf8q0t97) (body) (head (emit error (0) __erre6NQr95)) <internal>:1 #f)
  class ReadTask275 : public slog::Task
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
      std::vector<u16> ord276({0});
      slog::Relation* readrel277 = db->getRelation("error");
      head_index[0] = readrel277->getIndex(ord276, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask275(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c49}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask275* _cont = new ReadTask275(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask275(db,b), false);
  // (crule (pre (let __tconst0E1z28 const6b86b273ff34fce19d6b804e) (let __tconst6vOH26 constd4735e3a265e16eee03f5971) (let __tconst5eH624 const4e07408562bedb8b60ce05c1) (let __tconst0UaC33 const9ac63e4426dab2edcc97bcf7)) (seeded) (body (join _enum (1 0) 1 __tconst0UaC33 __t5CBi23) (exists ccons (1 2 0) 1 __tconst6vOH26) (exists ccons (1 2 0) 1 __tconst0E1z28) (join ccons (1 2 0) 2 __tconst5eH624 __t5CBi23 __t2qiY25) (join ccons (1 2 0) 2 __tconst6vOH26 __t2qiY25 __t27yb27) (join ccons (1 2 0) 2 __tconst0E1z28 __t27yb27 __t4hla29)) (head (emit input (0) __t4hla29)) dem_map.slog:24 #f)
  class ReadTask284 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex278;  slog::Index** cconsindex279;  slog::Index** cconsindex280;  slog::Index** cconsindex281;  slog::Index** cconsindex282;  slog::Index** cconsindex283;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("input");
      std::vector<u16> ord285({0});
      slog::Relation* readrel286 = db->getRelation("input");
      head_index[0] = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 0});
      slog::Relation* readrel288 = db->getRelation("_enum");
      _enumindex278 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 2, 0});
      slog::Relation* readrel290 = db->getRelation("ccons");
      cconsindex279 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 2, 0});
      slog::Relation* readrel292 = db->getRelation("ccons");
      cconsindex280 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 2, 0});
      slog::Relation* readrel294 = db->getRelation("ccons");
      cconsindex281 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({1, 2, 0});
      slog::Relation* readrel296 = db->getRelation("ccons");
      cconsindex282 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 2, 0});
      slog::Relation* readrel298 = db->getRelation("ccons");
      cconsindex283 = readrel298->getIndex(ord297, false);
  
    }
    ReadTask284(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex278, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m299) {
        u64 v_c20 = m299[1];
        if (!slog::exists_probe<3,1>(cconsindex279, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(cconsindex280, std::array<u64,3>{v_c13, 0, 0})) return;
        slog::join_probe<3,2>(cconsindex281, std::array<u64,3>{v_c15, v_c20, 0}, [&](const std::array<u64,3>& m300) {
          u64 v_c19 = m300[2];
          slog::join_probe<3,2>(cconsindex282, std::array<u64,3>{v_c14, v_c19, 0}, [&](const std::array<u64,3>& m301) {
            u64 v_c17 = m301[2];
            slog::join_probe<3,2>(cconsindex283, std::array<u64,3>{v_c13, v_c17, 0}, [&](const std::array<u64,3>& m302) {
              u64 v_c18 = m302[2];
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:24", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask284(db,b));
  // (crule (pre (let __tconst4NQC43 const933b575c961e931c43e84b05)) (scan input l) (body (join _enum (1 0) 1 __tconst4NQC43 __t6O0x8)) (head (mkstruct map (1 2 0) __0ivL42 __t6O0x8 l)) dem_map.slog:27 #f)
  class ReadTask304 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex303;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("map");
      outer_rel = db->getRelation("input");
      std::vector<u16> ord305({1, 0});
      slog::Relation* readrel306 = db->getRelation("_enum");
      _enumindex303 = readrel306->getIndex(ord305, false);
  
    }
    ReadTask304(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c52 = v_const933b575c961e931c43e84b05;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c47 = _t[0];
        slog::join_probe<2,1>(_enumindex303, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m307) {
          u64 v_c53 = m307[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c53, v_c47}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:27", "delta:input", _fires);
  
      if (!_done)
      {
        ReadTask304* _cont = new ReadTask304(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask304(db,b), false);
  // (crule (pre (let __tconst9jvH50 const933b575c961e931c43e84b05)) (scan apply __t2YZH21 __t5LR320 n) (body (join _enum (0 1) 2 __t5LR320 __tconst9jvH50) (let __t36b622 (_0002b n n))) (head (emit apply_ans (0 1) __t2YZH21 __t36b622)) dem_map.slog:15 #f)
  class ReadTask309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("apply_ans");
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("apply_ans");
      head_index[0] = readrel311->getIndex(ord310, false);
      outer_rel = db->getRelation("apply");
      std::vector<u16> ord312({0, 1});
      slog::Relation* readrel313 = db->getRelation("_enum");
      _enumindex308 = readrel313->getIndex(ord312, false);
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_const933b575c961e931c43e84b05;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c55 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe<2,2>(_enumindex308, std::array<u64,2>{v_c56, v_c54}, [&](const std::array<u64,2>& m314) {
          u64 v_c57 = _prim__0002b(db, v_c23, v_c23);
          if (v_c57 == slog_error) { slog::emit_pending_error(db, "dem_map.slog:15"); return; }
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c55, v_c57}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:15", "delta:apply", _fires);
  
      if (!_done)
      {
        ReadTask309* _cont = new ReadTask309(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask309(db,b), false);
  // (crule (pre) (scan toint_range __erre4jU7109 __errf0nsv110 __errf8tpJ111) (body) (head (emit error (0) __erre4jU7109)) <internal>:1 #f)
  class ReadTask315 : public slog::Task
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
      std::vector<u16> ord316({0});
      slog::Relation* readrel317 = db->getRelation("error");
      head_index[0] = readrel317->getIndex(ord316, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask315(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask315* _cont = new ReadTask315(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask315(db,b), false);
  // (crule (pre) (scan apply_ans __t0IeY4 y) (body (join-old apply (0 1 2) 1 (0 1 2) __t0IeY4 f x) (exists ccons (1 2 0) 1 x) (exists map (1 2 0) 1 f) (join-old $sup80907x18x0x0x0 (1 2 0 3) 2 (1 2 0 3) f x __t4Z5K3 xs) (exists map (0 1 2) 2 __t4Z5K3 f) (exists map (1 2 0) 2 f xs) (join-old ccons (1 2 0) 2 (1 2 0) x xs __t7M342) (join-old map (0 1 2) 3 (0 1 2) __t4Z5K3 f __t7M342) (join-old map (1 2 0) 2 (1 2 0) f xs __t0ipb5) (join-old map_ans (0 1) 1 (0 1) __t0ipb5 ys)) (head (emit-temp temp19Ou126 __t4Z5K3 y ys) (mkstruct ccons (1 2 0) __t92ia1 y ys)) dem_map.slog:19 #f)
  class ReadTask334 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** applyindex318;  slog::Index** cconsindex319;  slog::Index** mapindex320;  slog::Index** $sup80907x18x0x0x0index321;  slog::Index** mapindex322;  slog::Index** mapindex323;  slog::Index** cconsindex324;  slog::Index** mapindex325;  slog::Index** mapindex326;  slog::Index** map_ansindex327;  slog::Index** applydelta328;  slog::Index** $sup80907x18x0x0x0delta329;  slog::Index** cconsdelta330;  slog::Index** mapdelta331;  slog::Index** mapdelta332;  slog::Index** map_ansdelta333;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp19Ou126");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("apply_ans");
      std::vector<u16> ord335({0, 1, 2});
      slog::Relation* readrel336 = db->getRelation("apply");
      applyindex318 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({0, 1, 2});
      slog::Relation* readrel338 = db->getRelation("apply");
      applydelta328 = readrel338->getIndex(ord337, true);
      std::vector<u16> ord339({1, 2, 0});
      slog::Relation* readrel340 = db->getRelation("ccons");
      cconsindex319 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 2, 0});
      slog::Relation* readrel342 = db->getRelation("map");
      mapindex320 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 0, 3});
      slog::Relation* readrel344 = db->getRelation("$sup80907x18x0x0x0");
      $sup80907x18x0x0x0index321 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 2, 0, 3});
      slog::Relation* readrel346 = db->getRelation("$sup80907x18x0x0x0");
      $sup80907x18x0x0x0delta329 = readrel346->getIndex(ord345, true);
      std::vector<u16> ord347({0, 1, 2});
      slog::Relation* readrel348 = db->getRelation("map");
      mapindex322 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 2, 0});
      slog::Relation* readrel350 = db->getRelation("map");
      mapindex323 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("ccons");
      cconsindex324 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 0});
      slog::Relation* readrel354 = db->getRelation("ccons");
      cconsdelta330 = readrel354->getIndex(ord353, true);
      std::vector<u16> ord355({0, 1, 2});
      slog::Relation* readrel356 = db->getRelation("map");
      mapindex325 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({0, 1, 2});
      slog::Relation* readrel358 = db->getRelation("map");
      mapdelta331 = readrel358->getIndex(ord357, true);
      std::vector<u16> ord359({1, 2, 0});
      slog::Relation* readrel360 = db->getRelation("map");
      mapindex326 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 2, 0});
      slog::Relation* readrel362 = db->getRelation("map");
      mapdelta332 = readrel362->getIndex(ord361, true);
      std::vector<u16> ord363({0, 1});
      slog::Relation* readrel364 = db->getRelation("map_ans");
      map_ansindex327 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({0, 1});
      slog::Relation* readrel366 = db->getRelation("map_ans");
      map_ansdelta333 = readrel366->getIndex(ord365, true);
  
    }
    ReadTask334(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,1>(applyindex318, applydelta328, std::array<u64,3>{v_c27, 0, 0}, [&](const std::array<u64,3>& m367) {
          u64 v_c6 = m367[1]; u64 v_c7 = m367[2];
          if (!slog::exists_probe<3,1>(cconsindex319, std::array<u64,3>{v_c7, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mapindex320, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe_old<4,2>($sup80907x18x0x0x0index321, $sup80907x18x0x0x0delta329, std::array<u64,4>{v_c6, v_c7, 0, 0}, [&](const std::array<u64,4>& m368) {
            u64 v_c9 = m368[2]; u64 v_c8 = m368[3];
            if (!slog::exists_probe<3,2>(mapindex322, std::array<u64,3>{v_c9, v_c6, 0})) return;
            if (!slog::exists_probe<3,2>(mapindex323, std::array<u64,3>{v_c6, v_c8, 0})) return;
            slog::join_probe_old<3,2>(cconsindex324, cconsdelta330, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m369) {
              u64 v_c26 = m369[2];
              slog::join_probe_old<3,3>(mapindex325, mapdelta331, std::array<u64,3>{v_c9, v_c6, v_c26}, [&](const std::array<u64,3>& m370) {
                slog::join_probe_old<3,2>(mapindex326, mapdelta332, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m371) {
                  u64 v_c28 = m371[2];
                  slog::join_probe_old<2,1>(map_ansindex327, map_ansdelta333, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m372) {
                    u64 v_c11 = m372[1];
                    ++_fires;
                    slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c9, v_c10, v_c11});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:apply_ans", _fires);
  
      if (!_done)
      {
        ReadTask334* _cont = new ReadTask334(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask334(db,b), false);
  // (crule (pre (let __tconst9UvB18 const4a44dc15364204a80fe80e90)) (scan input l) (body) (head (emit-temp temp8PY9125 l) (mkstruct addk (1 0) __t0QoC19 __tconst9UvB18)) dem_map.slog:26 #f)
  class ReadTask373 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8PY9125");
      head_rel[1] = db->getRelation("addk");
      outer_rel = db->getRelation("input");
  
    }
    ReadTask373(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c46 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c47 = _t[0];
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c47});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c46}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_map.slog:26", "delta:input", _fires);
  
      if (!_done)
      {
        ReadTask373* _cont = new ReadTask373(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask373(db,b), false);
  // (crule (pre) (scan ccons __t18rm30 x xs) (body (join-old map (2 0 1) 1 (2 0 1) __t18rm30 __t7Y7z31 f)) (head (emit $sup80907x18x0x0x0 (0 1 2 3) __t7Y7z31 f x xs)) dem_map.slog:19 #f)
  class ReadTask376 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mapindex374;  slog::Index** mapdelta375;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup80907x18x0x0x0");
      std::vector<u16> ord377({0, 1, 2, 3});
      slog::Relation* readrel378 = db->getRelation("$sup80907x18x0x0x0");
      head_index[0] = readrel378->getIndex(ord377, false);
      outer_rel = db->getRelation("ccons");
      std::vector<u16> ord379({2, 0, 1});
      slog::Relation* readrel380 = db->getRelation("map");
      mapindex374 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({2, 0, 1});
      slog::Relation* readrel382 = db->getRelation("map");
      mapdelta375 = readrel382->getIndex(ord381, true);
  
    }
    ReadTask376(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        slog::join_probe_old<3,1>(mapindex374, mapdelta375, std::array<u64,3>{v_c42, 0, 0}, [&](const std::array<u64,3>& m383) {
          u64 v_c41 = m383[1]; u64 v_c6 = m383[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c41, v_c6, v_c7, v_c8}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:ccons", _fires);
  
      if (!_done)
      {
        ReadTask376* _cont = new ReadTask376(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask376(db,b), false);
  // (crule (pre (let __trid1Hre35 const97812a371f0b154056f7af1a) (let __trel3XoE36 const33dffa18ca3f56970d9625f0) (let __tcol9jJN37 const5feceb66ffc86f38d952786c) (let __trel77zb38 const33dffa18ca3f56970d9625f0) (let __tcol3Sd739 const6b86b273ff34fce19d6b804e)) (scan $sup80907x18x0x0x0 __d0 f x xs) (body) (head (tycheck f (accept (struct addk) (struct _enum)) __trid1Hre35 __trel3XoE36 __tcol9jJN37 (1 2 3 4 0)) (tycheck xs (accept (struct ccons) (struct _enum)) __trid1Hre35 __trel77zb38 __tcol3Sd739 (1 2 3 4 0)) (mkstruct map (1 2 0) __7jys34 f xs)) dem_map.slog:19 #f)
  class ReadTask387 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid385;  u32 sid384;  u32 sid386;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("map");
      outer_rel = db->getRelation("$sup80907x18x0x0x0");
      sid385 = db->getRelation("_enum")->getStructId();
      sid384 = db->getRelation("addk")->getStructId();
      sid386 = db->getRelation("ccons")->getStructId();
  
    }
    ReadTask387(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_const97812a371f0b154056f7af1a;
      u64 v_c62 = v_const33dffa18ca3f56970d9625f0;
      u64 v_c63 = v_const5feceb66ffc86f38d952786c;
      u64 v_c64 = v_const33dffa18ca3f56970d9625f0;
      u64 v_c65 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        ++_fires;
        if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid384 || decode_struct_id(v_c6) == sid385))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c61, v_c62, v_c63, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid386 || decode_struct_id(v_c8) == sid385))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c61, v_c64, v_c65, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c8}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:$sup80907x18x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask387* _cont = new ReadTask387(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask387(db,b), false);
  // (crule (pre) (scan apply __t0IeY4 f x) (body (exists ccons (1 2 0) 1 x) (exists map (1 2 0) 1 f) (exists apply_ans (0 1) 1 __t0IeY4) (join $sup80907x18x0x0x0 (1 2 0 3) 2 f x __t4Z5K3 xs) (exists map (0 1 2) 2 __t4Z5K3 f) (exists map (1 2 0) 2 f xs) (join ccons (1 2 0) 2 x xs __t7M342) (join map (0 1 2) 3 __t4Z5K3 f __t7M342) (join-old map (1 2 0) 2 (1 2 0) f xs __t0ipb5) (exists map_ans (0 1) 1 __t0ipb5) (join apply_ans (0 1) 1 __t0IeY4 y) (join map_ans (0 1) 1 __t0ipb5 ys)) (head (emit-temp temp19Ou126 __t4Z5K3 y ys) (mkstruct ccons (1 2 0) __t92ia1 y ys)) dem_map.slog:19 #f)
  class ReadTask401 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex388;  slog::Index** mapindex389;  slog::Index** apply_ansindex390;  slog::Index** $sup80907x18x0x0x0index391;  slog::Index** mapindex392;  slog::Index** mapindex393;  slog::Index** cconsindex394;  slog::Index** mapindex395;  slog::Index** mapindex396;  slog::Index** map_ansindex397;  slog::Index** apply_ansindex398;  slog::Index** map_ansindex399;  slog::Index** mapdelta400;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp19Ou126");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("apply");
      std::vector<u16> ord402({1, 2, 0});
      slog::Relation* readrel403 = db->getRelation("ccons");
      cconsindex388 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 2, 0});
      slog::Relation* readrel405 = db->getRelation("map");
      mapindex389 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({0, 1});
      slog::Relation* readrel407 = db->getRelation("apply_ans");
      apply_ansindex390 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 2, 0, 3});
      slog::Relation* readrel409 = db->getRelation("$sup80907x18x0x0x0");
      $sup80907x18x0x0x0index391 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 1, 2});
      slog::Relation* readrel411 = db->getRelation("map");
      mapindex392 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 2, 0});
      slog::Relation* readrel413 = db->getRelation("map");
      mapindex393 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 2, 0});
      slog::Relation* readrel415 = db->getRelation("ccons");
      cconsindex394 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({0, 1, 2});
      slog::Relation* readrel417 = db->getRelation("map");
      mapindex395 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 2, 0});
      slog::Relation* readrel419 = db->getRelation("map");
      mapindex396 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 2, 0});
      slog::Relation* readrel421 = db->getRelation("map");
      mapdelta400 = readrel421->getIndex(ord420, true);
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("map_ans");
      map_ansindex397 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({0, 1});
      slog::Relation* readrel425 = db->getRelation("apply_ans");
      apply_ansindex398 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({0, 1});
      slog::Relation* readrel427 = db->getRelation("map_ans");
      map_ansindex399 = readrel427->getIndex(ord426, false);
  
    }
    ReadTask401(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<3,1>(cconsindex388, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mapindex389, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(apply_ansindex390, std::array<u64,2>{v_c27, 0})) return;
        slog::join_probe<4,2>($sup80907x18x0x0x0index391, std::array<u64,4>{v_c6, v_c7, 0, 0}, [&](const std::array<u64,4>& m428) {
          u64 v_c9 = m428[2]; u64 v_c8 = m428[3];
          if (!slog::exists_probe<3,2>(mapindex392, std::array<u64,3>{v_c9, v_c6, 0})) return;
          if (!slog::exists_probe<3,2>(mapindex393, std::array<u64,3>{v_c6, v_c8, 0})) return;
          slog::join_probe<3,2>(cconsindex394, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m429) {
            u64 v_c26 = m429[2];
            slog::join_probe<3,3>(mapindex395, std::array<u64,3>{v_c9, v_c6, v_c26}, [&](const std::array<u64,3>& m430) {
              slog::join_probe_old<3,2>(mapindex396, mapdelta400, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m431) {
                u64 v_c28 = m431[2];
                if (!slog::exists_probe<2,1>(map_ansindex397, std::array<u64,2>{v_c28, 0})) return;
                slog::join_probe<2,1>(apply_ansindex398, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m432) {
                  u64 v_c10 = m432[1];
                  slog::join_probe<2,1>(map_ansindex399, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m433) {
                    u64 v_c11 = m433[1];
                    ++_fires;
                    slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c9, v_c10, v_c11});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:apply", _fires);
  
      if (!_done)
      {
        ReadTask401* _cont = new ReadTask401(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask401(db,b), false);
  // (crule (pre (let __tconst0E1z28 const6b86b273ff34fce19d6b804e) (let __tconst6vOH26 constd4735e3a265e16eee03f5971) (let __tconst5eH624 const4e07408562bedb8b60ce05c1) (let __tconst0UaC33 const9ac63e4426dab2edcc97bcf7)) (probe ccons (1 2 0) 1 __tconst5eH624 __t5CBi23 __t2qiY25) (body (join _enum (0 1) 2 __t5CBi23 __tconst0UaC33)) (head (mkstruct ccons (1 2 0) __t27yb27 __tconst6vOH26 __t2qiY25)) dem_map.slog:24 #f)
  class ReadTask435 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex434;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ccons");
      std::vector<u16> ord436({1, 2, 0});
      slog::Relation* readrel437 = db->getRelation("ccons");
      driver_index = readrel437->getIndex(ord436, true);
      std::vector<u16> ord438({0, 1});
      slog::Relation* readrel439 = db->getRelation("_enum");
      _enumindex434 = readrel439->getIndex(ord438, false);
  
    }
    ReadTask435(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c15, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m440) {
        u64 v_c20 = m440[1];
        u64 v_c19 = m440[2];
        if (buckethash(v_c20) != bucket) return;
        slog::join_probe<2,2>(_enumindex434, std::array<u64,2>{v_c20, v_c16}, [&](const std::array<u64,2>& m441) {
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c14, v_c19}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:24", "delta:ccons", _fires);
  
      if (!_done)
      {
        ReadTask435* _cont = new ReadTask435(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask435(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre2oSU117 __errf3keq118 __errf1HkU119 __errf23s9120 __errf7Eq3121) (body) (head (emit error (0) __erre2oSU117)) <internal>:1 #f)
  class ReadTask442 : public slog::Task
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
      std::vector<u16> ord443({0});
      slog::Relation* readrel444 = db->getRelation("error");
      head_index[0] = readrel444->getIndex(ord443, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask442(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c69 = _t[3];
        u64 v_c70 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c66}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask442* _cont = new ReadTask442(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask442(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre9loS90 __errf0u9H91 __errf4AHy92 __errf5yk693 __errf6taU94) (body) (head (emit error (0) __erre9loS90)) <internal>:1 #f)
  class ReadTask445 : public slog::Task
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
      std::vector<u16> ord446({0});
      slog::Relation* readrel447 = db->getRelation("error");
      head_index[0] = readrel447->getIndex(ord446, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask445(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c71 = _t[0];
        u64 v_c72 = _t[1];
        u64 v_c73 = _t[2];
        u64 v_c74 = _t[3];
        u64 v_c75 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c71}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask445* _cont = new ReadTask445(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask445(db,b), false);
  // (crule (pre) (scan map __t4Z5K3 f __t7M342) (body (exists apply (1 2 0) 1 f) (exists map (1 2 0) 1 f) (join $sup80907x18x0x0x0 (0 1 2 3) 2 __t4Z5K3 f x xs) (join ccons (0 1 2) 3 __t7M342 x xs) (exists map (1 2 0) 2 f xs) (join-old apply (1 2 0) 2 (1 2 0) f x __t0IeY4) (exists apply_ans (0 1) 1 __t0IeY4) (join-old map (1 2 0) 2 (1 2 0) f xs __t0ipb5) (exists map_ans (0 1) 1 __t0ipb5) (join apply_ans (0 1) 1 __t0IeY4 y) (join map_ans (0 1) 1 __t0ipb5 ys)) (head (emit-temp temp19Ou126 __t4Z5K3 y ys) (mkstruct ccons (1 2 0) __t92ia1 y ys)) dem_map.slog:19 #f)
  class ReadTask461 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** applyindex448;  slog::Index** mapindex449;  slog::Index** $sup80907x18x0x0x0index450;  slog::Index** cconsindex451;  slog::Index** mapindex452;  slog::Index** applyindex453;  slog::Index** apply_ansindex454;  slog::Index** mapindex455;  slog::Index** map_ansindex456;  slog::Index** apply_ansindex457;  slog::Index** map_ansindex458;  slog::Index** applydelta459;  slog::Index** mapdelta460;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp19Ou126");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("map");
      std::vector<u16> ord462({1, 2, 0});
      slog::Relation* readrel463 = db->getRelation("apply");
      applyindex448 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 0});
      slog::Relation* readrel465 = db->getRelation("map");
      mapindex449 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1, 2, 3});
      slog::Relation* readrel467 = db->getRelation("$sup80907x18x0x0x0");
      $sup80907x18x0x0x0index450 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({0, 1, 2});
      slog::Relation* readrel469 = db->getRelation("ccons");
      cconsindex451 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 2, 0});
      slog::Relation* readrel471 = db->getRelation("map");
      mapindex452 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 2, 0});
      slog::Relation* readrel473 = db->getRelation("apply");
      applyindex453 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("apply");
      applydelta459 = readrel475->getIndex(ord474, true);
      std::vector<u16> ord476({0, 1});
      slog::Relation* readrel477 = db->getRelation("apply_ans");
      apply_ansindex454 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 2, 0});
      slog::Relation* readrel479 = db->getRelation("map");
      mapindex455 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 2, 0});
      slog::Relation* readrel481 = db->getRelation("map");
      mapdelta460 = readrel481->getIndex(ord480, true);
      std::vector<u16> ord482({0, 1});
      slog::Relation* readrel483 = db->getRelation("map_ans");
      map_ansindex456 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({0, 1});
      slog::Relation* readrel485 = db->getRelation("apply_ans");
      apply_ansindex457 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({0, 1});
      slog::Relation* readrel487 = db->getRelation("map_ans");
      map_ansindex458 = readrel487->getIndex(ord486, false);
  
    }
    ReadTask461(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c26 = _t[2];
        if (!slog::exists_probe<3,1>(applyindex448, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mapindex449, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<4,2>($sup80907x18x0x0x0index450, std::array<u64,4>{v_c9, v_c6, 0, 0}, [&](const std::array<u64,4>& m488) {
          u64 v_c7 = m488[2]; u64 v_c8 = m488[3];
          slog::join_probe<3,3>(cconsindex451, std::array<u64,3>{v_c26, v_c7, v_c8}, [&](const std::array<u64,3>& m489) {
            if (!slog::exists_probe<3,2>(mapindex452, std::array<u64,3>{v_c6, v_c8, 0})) return;
            slog::join_probe_old<3,2>(applyindex453, applydelta459, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m490) {
              u64 v_c27 = m490[2];
              if (!slog::exists_probe<2,1>(apply_ansindex454, std::array<u64,2>{v_c27, 0})) return;
              slog::join_probe_old<3,2>(mapindex455, mapdelta460, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m491) {
                u64 v_c28 = m491[2];
                if (!slog::exists_probe<2,1>(map_ansindex456, std::array<u64,2>{v_c28, 0})) return;
                slog::join_probe<2,1>(apply_ansindex457, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m492) {
                  u64 v_c10 = m492[1];
                  slog::join_probe<2,1>(map_ansindex458, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m493) {
                    u64 v_c11 = m493[1];
                    ++_fires;
                    slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c9, v_c10, v_c11});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:map", _fires);
  
      if (!_done)
      {
        ReadTask461* _cont = new ReadTask461(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask461(db,b), false);
  // (crule (pre) (scan map __t0ipb5 f xs) (body (exists ccons (2 0 1) 1 xs) (exists map (1 2 0) 1 f) (exists apply (1 2 0) 1 f) (exists map_ans (0 1) 1 __t0ipb5) (join $sup80907x18x0x0x0 (1 3 0 2) 2 f xs __t4Z5K3 x) (exists map (0 1 2) 2 __t4Z5K3 f) (exists apply (1 2 0) 2 f x) (join ccons (1 2 0) 2 x xs __t7M342) (join map (0 1 2) 3 __t4Z5K3 f __t7M342) (join apply (1 2 0) 2 f x __t0IeY4) (join apply_ans (0 1) 1 __t0IeY4 y) (join map_ans (0 1) 1 __t0ipb5 ys)) (head (emit-temp temp19Ou126 __t4Z5K3 y ys) (mkstruct ccons (1 2 0) __t92ia1 y ys)) dem_map.slog:19 #f)
  class ReadTask506 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex494;  slog::Index** mapindex495;  slog::Index** applyindex496;  slog::Index** map_ansindex497;  slog::Index** $sup80907x18x0x0x0index498;  slog::Index** mapindex499;  slog::Index** applyindex500;  slog::Index** cconsindex501;  slog::Index** mapindex502;  slog::Index** applyindex503;  slog::Index** apply_ansindex504;  slog::Index** map_ansindex505;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp19Ou126");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("map");
      std::vector<u16> ord507({2, 0, 1});
      slog::Relation* readrel508 = db->getRelation("ccons");
      cconsindex494 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 2, 0});
      slog::Relation* readrel510 = db->getRelation("map");
      mapindex495 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({1, 2, 0});
      slog::Relation* readrel512 = db->getRelation("apply");
      applyindex496 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({0, 1});
      slog::Relation* readrel514 = db->getRelation("map_ans");
      map_ansindex497 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({1, 3, 0, 2});
      slog::Relation* readrel516 = db->getRelation("$sup80907x18x0x0x0");
      $sup80907x18x0x0x0index498 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({0, 1, 2});
      slog::Relation* readrel518 = db->getRelation("map");
      mapindex499 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 2, 0});
      slog::Relation* readrel520 = db->getRelation("apply");
      applyindex500 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 2, 0});
      slog::Relation* readrel522 = db->getRelation("ccons");
      cconsindex501 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({0, 1, 2});
      slog::Relation* readrel524 = db->getRelation("map");
      mapindex502 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 2, 0});
      slog::Relation* readrel526 = db->getRelation("apply");
      applyindex503 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({0, 1});
      slog::Relation* readrel528 = db->getRelation("apply_ans");
      apply_ansindex504 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({0, 1});
      slog::Relation* readrel530 = db->getRelation("map_ans");
      map_ansindex505 = readrel530->getIndex(ord529, false);
  
    }
    ReadTask506(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<3,1>(cconsindex494, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mapindex495, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(applyindex496, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(map_ansindex497, std::array<u64,2>{v_c28, 0})) return;
        slog::join_probe<4,2>($sup80907x18x0x0x0index498, std::array<u64,4>{v_c6, v_c8, 0, 0}, [&](const std::array<u64,4>& m531) {
          u64 v_c9 = m531[2]; u64 v_c7 = m531[3];
          if (!slog::exists_probe<3,2>(mapindex499, std::array<u64,3>{v_c9, v_c6, 0})) return;
          if (!slog::exists_probe<3,2>(applyindex500, std::array<u64,3>{v_c6, v_c7, 0})) return;
          slog::join_probe<3,2>(cconsindex501, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m532) {
            u64 v_c26 = m532[2];
            slog::join_probe<3,3>(mapindex502, std::array<u64,3>{v_c9, v_c6, v_c26}, [&](const std::array<u64,3>& m533) {
              slog::join_probe<3,2>(applyindex503, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m534) {
                u64 v_c27 = m534[2];
                slog::join_probe<2,1>(apply_ansindex504, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m535) {
                  u64 v_c10 = m535[1];
                  slog::join_probe<2,1>(map_ansindex505, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m536) {
                    u64 v_c11 = m536[1];
                    ++_fires;
                    slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c9, v_c10, v_c11});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_map.slog:19", "delta:map", _fires);
  
      if (!_done)
      {
        ReadTask506* _cont = new ReadTask506(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask506(db,b), false);
  // (crule (pre) (scan int_overflow __erre0DnJ101 __errf04WT102 __errf8MmF103 __errf1JwH104) (body) (head (emit error (0) __erre0DnJ101)) <internal>:1 #f)
  class ReadTask537 : public slog::Task
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
      std::vector<u16> ord538({0});
      slog::Relation* readrel539 = db->getRelation("error");
      head_index[0] = readrel539->getIndex(ord538, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask537(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c76 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c78 = _t[2];
        u64 v_c79 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c76}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask537* _cont = new ReadTask537(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask537(db,b), false);
  // (crule (pre (let __tconst0E1z28 const6b86b273ff34fce19d6b804e) (let __tconst6vOH26 constd4735e3a265e16eee03f5971) (let __tconst5eH624 const4e07408562bedb8b60ce05c1) (let __tconst0UaC33 const9ac63e4426dab2edcc97bcf7)) (seeded) (body (join _enum (1 0) 1 __tconst0UaC33 __t5CBi23) (join ccons (1 2 0) 2 __tconst5eH624 __t5CBi23 __t2qiY25)) (head (mkstruct ccons (1 2 0) __t27yb27 __tconst6vOH26 __t2qiY25)) dem_map.slog:24 #f)
  class ReadTask542 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex540;  slog::Index** cconsindex541;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ccons");
      std::vector<u16> ord543({1, 2, 0});
      slog::Relation* readrel544 = db->getRelation("ccons");
      head_index[0] = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 0});
      slog::Relation* readrel546 = db->getRelation("_enum");
      _enumindex540 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 2, 0});
      slog::Relation* readrel548 = db->getRelation("ccons");
      cconsindex541 = readrel548->getIndex(ord547, false);
  
    }
    ReadTask542(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex540, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m549) {
        u64 v_c20 = m549[1];
        slog::join_probe<3,2>(cconsindex541, std::array<u64,3>{v_c15, v_c20, 0}, [&](const std::array<u64,3>& m550) {
          u64 v_c19 = m550[2];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c14, v_c19}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_map.slog:24", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask542(db,b));
  // (crule (pre) (scan modulo_by_zero __erre6hOW98 __errf6dkN99 __errf2jVz100) (body) (head (emit error (0) __erre6hOW98)) <internal>:1 #f)
  class ReadTask551 : public slog::Task
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
      std::vector<u16> ord552({0});
      slog::Relation* readrel553 = db->getRelation("error");
      head_index[0] = readrel553->getIndex(ord552, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask551(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c80 = _t[0];
        u64 v_c81 = _t[1];
        u64 v_c82 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c80}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask551* _cont = new ReadTask551(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask551(db,b), false);
  s->addReadRel("$sup80907x18x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("addk");
  s->addReadRel("apply");
  s->addReadRel("apply_ans");
  s->addReadRel("ccons");
  s->addReadRel("div_by_zero");
  s->addReadRel("input");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("map");
  s->addReadRel("map_ans");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp19Ou126");
  s->addReadRel("temp8PY9125");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$sup80907x18x0x0x0");
  s->addDynamicRel("addk");
  s->addDynamicRel("apply");
  s->addDynamicRel("apply_ans");
  s->addDynamicRel("ccons");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("input");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("map");
  s->addDynamicRel("map_ans");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("temp19Ou126");
  s->addDynamicRel("temp8PY9125");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("apply_ans");
  s->addAccelRel("input");
  s->addAccelRel("map_ans");
  d->push(s);
  d->continueRun();
}

