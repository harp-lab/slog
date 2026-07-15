
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("53c1705d");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord123({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord124({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("twice");
  if (r == 0) db->addRelation("twice", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("twice");
      std::vector<u16> ord125({0});
    
    r->addIndex<1>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("twice"), std::array<u16,1>{0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord126({1, 2, 0});
    
    r->addIndex<3>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord127({0, 1, 2});
    
    r->addIndex<3>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp9KgZ375");
  if (r == 0) db->addTempRelation("temp9KgZ375", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5R4B376");
  if (r == 0) db->addTempRelation("temp5R4B376", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3tpe377");
  if (r == 0) db->addTempRelation("temp3tpe377", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1vhf381");
  if (r == 0) db->addTempRelation("temp1vhf381", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord128({1, 2, 0});
    
    r->addIndex<3>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord129({0, 1, 2});
    
    r->addIndex<3>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("scaled");
  if (r == 0) db->addRelation("scaled", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("scaled");
      std::vector<u16> ord130({0});
    
    r->addIndex<1>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("scaled"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord131({1, 2, 3, 0});
    
    r->addIndex<4>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord132({0, 1, 2, 3});
    
    r->addIndex<4>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord133({1, 2, 0});
    
    r->addIndex<3>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord134({0, 1, 2});
    
    r->addIndex<3>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord135({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord136({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
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
  r = db->getRelation("map2_ans");
  if (r == 0) db->addRelation("map2_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map2_ans");
      std::vector<u16> ord139({0, 1});
    
    r->addIndex<2>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("map2_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("map2");
  if (r == 0) db->addStruct("map2", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map2");
      std::vector<u16> ord140({1, 2, 0});
    
    r->addIndex<3>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord141({0, 1, 2});
    
    r->addIndex<3>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord142({2, 0, 1});
    
    r->addIndex<3>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("map2"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord143({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord144({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("kv");
  if (r == 0) db->addRelation("kv", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("kv");
      std::vector<u16> ord145({0});
    
    r->addIndex<1>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("kv"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord146({1, 2, 3, 0});
    
    r->addIndex<4>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord147({0, 1, 2, 3});
    
    r->addIndex<4>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("input");
  if (r == 0) db->addRelation("input", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("input");
      std::vector<u16> ord148({0});
    
    r->addIndex<1>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("input"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord149({0});
    
    r->addIndex<1>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord150({1, 2, 0});
    
    r->addIndex<3>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord151({0, 1, 2});
    
    r->addIndex<3>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("compose_ans");
  if (r == 0) db->addRelation("compose_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("compose_ans");
      std::vector<u16> ord152({0, 1});
    
    r->addIndex<2>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("compose_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("compose");
  if (r == 0) db->addStruct("compose", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("compose");
      std::vector<u16> ord153({1, 2, 0});
    
    r->addIndex<3>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord154({0, 1, 2});
    
    r->addIndex<3>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("compose"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("apply1_ans");
  if (r == 0) db->addRelation("apply1_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply1_ans");
      std::vector<u16> ord155({0, 1});
    
    r->addIndex<2>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("apply1_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("apply1");
  if (r == 0) db->addStruct("apply1", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply1");
      std::vector<u16> ord156({1, 2, 0});
    
    r->addIndex<3>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord157({0, 1, 2});
    
    r->addIndex<3>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord158({2, 0, 1});
    
    r->addIndex<3>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("apply1"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_lam54764x22x18");
  if (r == 0) db->addStruct("_lam54764x22x18", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_lam54764x22x18");
      std::vector<u16> ord159({1, 2, 0});
    
    r->addIndex<3>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord160({0, 1, 2});
    
    r->addIndex<3>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("_lam54764x22x18"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_lam54764x18x33");
  if (r == 0) db->addStruct("_lam54764x18x33", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_lam54764x18x33");
      std::vector<u16> ord161({1, 0});
    
    r->addIndex<2>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord162({0, 1});
    
    r->addIndex<2>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_lam54764x18x33"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord163({1, 0});
    
    r->addIndex<2>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord164({0, 1});
    
    r->addIndex<2>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup54764x9x0x0x0");
  if (r == 0) db->addRelation("$sup54764x9x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup54764x9x0x0x0");
      std::vector<u16> ord165({2, 4, 0, 1, 3});
    
    r->addIndex<5>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 4, 0, 1, 3}, false, b), true);
      std::vector<u16> ord166({0, 3, 4, 1, 2});
    
    r->addIndex<5>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 3, 4, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup54764x9x0x0x0"), std::array<u16,5>{2, 4, 0, 1, 3}, b));
  r = db->getRelation("$sup54764x22x18x0x0");
  if (r == 0) db->addRelation("$sup54764x22x18x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup54764x22x18x0x0");
      std::vector<u16> ord167({0, 1, 2, 3});
    
    r->addIndex<4>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup54764x22x18x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord168({1, 0, 2});
    
    r->addIndex<3>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
      std::vector<u16> ord169({1, 0, 2});
    
    r->addIndex<3>(ord169, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{1, 0, 2}, b));
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
  // (crule (pre) (scan temp9KgZ375 __t3eCF12 __t7MFn15 __v0 __v1) (body (let __t4wdv13 (lpush __t3eCF12 __v0))) (head (emit-temp temp5R4B376 __t4wdv13 __t7MFn15 __v1)) dem_lambda.slog:10 #f)
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
      head_rel[0] = db->getRelation("temp5R4B376");
      outer_rel = db->getRelation("temp9KgZ375");
  
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
        u64 v_c3 = _t[3];
        u64 v_c4 = _prim_lpush(db, v_c0, v_c2);
        if (v_c4 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c4, v_c1, v_c3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:10", "delta:temp9KgZ375", _fires);
  
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
  // (crule (pre (let _00024sqc1ev651 const6b86b273ff34fce19d6b804e) (let _00024sqc1WHS52 const5feceb66ffc86f38d952786c) (let _00024sqc5ubW53 const6b86b273ff34fce19d6b804e) (let _00024sqc1mMQ54 const5feceb66ffc86f38d952786c) (let _00024sqo1C8F59 const5feceb66ffc86f38d952786c) (let __t3eCF12 (lempty))) (scan map2_ans __t7Zs017 __v1) (body (exists $seq_at (1 0 2) 1 _00024sqo1C8F59) (join map2 (0 1 2) 1 __t7Zs017 f xs) (exists map2 (1 2 0) 1 f) (exists apply1 (1 2 0) 1 f) (join $sup54764x9x0x0x0 (2 4 0 1 3) 2 f xs _00024seq0 __t7MFn15 x) (join map2 (1 2 0) 3 f _00024seq0 __t7MFn15) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo1C8F59 x _00024seq0) (join apply1 (1 2 0) 2 f x __t1dTY16) (join apply1_ans (0 1) 1 __t1dTY16 __v0) (letp _00024sql9SmE49 (aslst _00024seq0)) (let _00024sqn2ic850 (llen _00024sql9SmE49)) (cmp ge _00024sqn2ic850 _00024sqc1ev651) (letp chk0hxH378 (lref _00024sql9SmE49 _00024sqc1WHS52)) (eq x chk0hxH378) (let _00024sqp3dMm55 (_0002d _00024sqn2ic850 _00024sqc1mMQ54)) (let chk7Arp379 (lslice _00024sql9SmE49 _00024sqc5ubW53 _00024sqp3dMm55)) (eq xs chk7Arp379)) (head (emit-temp temp9KgZ375 __t3eCF12 __t7MFn15 __v0 __v1)) dem_lambda.slog:10 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex1;  slog::Index** map2index2;  slog::Index** map2index3;  slog::Index** apply1index4;  slog::Index** $sup54764x9x0x0x0index5;  slog::Index** map2index6;  slog::Index** $seq_atindex7;  slog::Index** apply1index8;  slog::Index** apply1_ansindex9;  slog::Index** $seq_atdelta10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9KgZ375");
      outer_rel = db->getRelation("map2_ans");
      std::vector<u16> ord12({1, 0, 2});
      slog::Relation* readrel13 = db->getRelation("$seq_at");
      $seq_atindex1 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({0, 1, 2});
      slog::Relation* readrel15 = db->getRelation("map2");
      map2index2 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 2, 0});
      slog::Relation* readrel17 = db->getRelation("map2");
      map2index3 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 2, 0});
      slog::Relation* readrel19 = db->getRelation("apply1");
      apply1index4 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({2, 4, 0, 1, 3});
      slog::Relation* readrel21 = db->getRelation("$sup54764x9x0x0x0");
      $sup54764x9x0x0x0index5 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 2, 0});
      slog::Relation* readrel23 = db->getRelation("map2");
      map2index6 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0, 2});
      slog::Relation* readrel25 = db->getRelation("$seq_at");
      $seq_atindex7 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 0, 2});
      slog::Relation* readrel27 = db->getRelation("$seq_at");
      $seq_atdelta10 = readrel27->getIndex(ord26, true);
      std::vector<u16> ord28({1, 2, 0});
      slog::Relation* readrel29 = db->getRelation("apply1");
      apply1index8 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1});
      slog::Relation* readrel31 = db->getRelation("apply1_ans");
      apply1_ansindex9 = readrel31->getIndex(ord30, false);
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_const5feceb66ffc86f38d952786c;
      u64 v_c0 = _prim_lempty(db);
      if (v_c0 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c10 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex1, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe<3,1>(map2index2, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m32) {
          u64 v_c11 = m32[1]; u64 v_c12 = m32[2];
          if (!slog::exists_probe<3,1>(map2index3, std::array<u64,3>{v_c11, 0, 0})) return;
          if (!slog::exists_probe<3,1>(apply1index4, std::array<u64,3>{v_c11, 0, 0})) return;
          slog::join_probe<5,2>($sup54764x9x0x0x0index5, std::array<u64,5>{v_c11, v_c12, 0, 0, 0}, [&](const std::array<u64,5>& m33) {
            u64 v_c13 = m33[2]; u64 v_c1 = m33[3]; u64 v_c14 = m33[4];
            slog::join_probe<3,3>(map2index6, std::array<u64,3>{v_c11, v_c13, v_c1}, [&](const std::array<u64,3>& m34) {
              slog::join_probe_old<3,3>($seq_atindex7, $seq_atdelta10, std::array<u64,3>{v_c9, v_c14, v_c13}, [&](const std::array<u64,3>& m35) {
                slog::join_probe<3,2>(apply1index8, std::array<u64,3>{v_c11, v_c14, 0}, [&](const std::array<u64,3>& m36) {
                  u64 v_c15 = m36[2];
                  slog::join_probe<2,1>(apply1_ansindex9, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m37) {
                    u64 v_c2 = m37[1];
                    bool ok38 = true;
                    u64 v_c16 = _prim_aslst(db, v_c13, &ok38);
                    if (!ok38) return;
                    u64 v_c17 = _prim_llen(db, v_c16);
                    if (v_c17 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
                    u64 v_c18 = _prim_ge(db, v_c17, v_c5);
                    if (v_c18 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
                    if (!v_c18) return;
                    bool ok40 = true;
                    u64 v_c19 = _prim_lref(db, v_c16, v_c6, &ok40);
                    if (!ok40) return;
                    if (v_c14 != v_c19) return;
                    u64 v_c20 = _prim__0002d(db, v_c17, v_c8);
                    if (v_c20 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
                    u64 v_c21 = _prim_lslice(db, v_c16, v_c7, v_c20);
                    if (v_c21 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
                    if (v_c12 != v_c21) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c3});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:10", "delta:map2_ans", _fires);
  
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
  // (crule (pre (let _00024sqc2pXS62 const5feceb66ffc86f38d952786c) (let __t58Kw10 (lempty))) (scan map2 __t3kFb11 f _00024seq0) (body (letp _00024sql1VpI60 (aslst _00024seq0)) (let chk67Vn382 (llen _00024sql1VpI60)) (eq _00024sqc2pXS62 chk67Vn382)) (head (emit-temp temp1vhf381 __t3kFb11 __t58Kw10)) dem_lambda.slog:9 #f)
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
      head_rel[0] = db->getRelation("temp1vhf381");
      outer_rel = db->getRelation("map2");
  
    }
    ReadTask41(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const5feceb66ffc86f38d952786c;
      u64 v_c23 = _prim_lempty(db);
      if (v_c23 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:9"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c24 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c13 = _t[2];
        bool ok42 = true;
        u64 v_c25 = _prim_aslst(db, v_c13, &ok42);
        if (!ok42) return;
        u64 v_c26 = _prim_llen(db, v_c25);
        if (v_c26 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:9"); return; }
        if (v_c22 != v_c26) return;
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c24, v_c23});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:9", "all:map2", _fires);
  
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
      s->addTask(phase_read, new ReadTask41(db,b), true);
  // (crule (pre) (scan mpz_table_overflow __erre1Y2o372 __errf5WL9373 __errf708y374) (body) (head (emit error (0) __erre1Y2o372)) <internal>:1 #f)
  class ReadTask43 : public slog::Task
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
      std::vector<u16> ord44({0});
      slog::Relation* readrel45 = db->getRelation("error");
      head_index[0] = readrel45->getIndex(ord44, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask43(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask43* _cont = new ReadTask43(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask43(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre9a2l348 __errf4HuI349 __errf05Kk350) (body) (head (emit error (0) __erre9a2l348)) <internal>:1 #f)
  class ReadTask46 : public slog::Task
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
      std::vector<u16> ord47({0});
      slog::Relation* readrel48 = db->getRelation("error");
      head_index[0] = readrel48->getIndex(ord47, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
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
        u64 v_c30 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c32 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c30}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
      s->addTask(phase_read, new ReadTask46(db,b), false);
  // (crule (pre) (scan temp1vhf381 __t3kFb11 __t58Kw10) (body) (head (emit map2_ans (0 1) __t3kFb11 __t58Kw10)) dem_lambda.slog:9 #f)
  class ReadTask49 : public slog::Task
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
      head_rel[0] = db->getRelation("map2_ans");
      std::vector<u16> ord50({0, 1});
      slog::Relation* readrel51 = db->getRelation("map2_ans");
      head_index[0] = readrel51->getIndex(ord50, false);
      outer_rel = db->getRelation("temp1vhf381");
  
    }
    ReadTask49(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c23}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:9", "delta:temp1vhf381", _fires);
  
      if (!_done)
      {
        ReadTask49* _cont = new ReadTask49(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask49(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre3YKn367 __errf2SNd368 __errf2GJE369 __errf3B9t370 __errf36j4371) (body) (head (emit error (0) __erre3YKn367)) <internal>:1 #f)
  class ReadTask52 : public slog::Task
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
      std::vector<u16> ord53({0});
      slog::Relation* readrel54 = db->getRelation("error");
      head_index[0] = readrel54->getIndex(ord53, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask52(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask52* _cont = new ReadTask52(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask52(db,b), false);
  // (crule (pre) (scan temp5R4B376 __t4wdv13 __t7MFn15 __v1) (body (let __t8Ft614 (lcat __t4wdv13 __v1))) (head (emit-temp temp3tpe377 __t7MFn15 __t8Ft614)) dem_lambda.slog:10 #f)
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
      head_rel[0] = db->getRelation("temp3tpe377");
      outer_rel = db->getRelation("temp5R4B376");
  
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
        u64 v_c4 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c38 = _prim_lcat(db, v_c4, v_c3);
        if (v_c38 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c38});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:10", "delta:temp5R4B376", _fires);
  
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
  // (crule (pre) (scan temp3tpe377 __t7MFn15 __t8Ft614) (body) (head (emit map2_ans (0 1) __t7MFn15 __t8Ft614)) dem_lambda.slog:10 #f)
  class ReadTask56 : public slog::Task
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
      head_rel[0] = db->getRelation("map2_ans");
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("map2_ans");
      head_index[0] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("temp3tpe377");
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[0];
        u64 v_c38 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c38}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:10", "delta:temp3tpe377", _fires);
  
      if (!_done)
      {
        ReadTask56* _cont = new ReadTask56(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask56(db,b), false);
  // (crule (pre) (scan div_by_zero __erre9ZCH345 __errf1ry7346 __errf46zT347) (body) (head (emit error (0) __erre9ZCH345)) <internal>:1 #f)
  class ReadTask59 : public slog::Task
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
      std::vector<u16> ord60({0});
      slog::Relation* readrel61 = db->getRelation("error");
      head_index[0] = readrel61->getIndex(ord60, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask59(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  // (crule (pre) (scan nan_result __erre0jkN355 __errf6CrK356 __errf3JAO357 __errf7O7S358) (body) (head (emit error (0) __erre0jkN355)) <internal>:1 #f)
  class ReadTask62 : public slog::Task
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
      std::vector<u16> ord63({0});
      slog::Relation* readrel64 = db->getRelation("error");
      head_index[0] = readrel64->getIndex(ord63, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask62(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[2];
        u64 v_c45 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c42}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask62* _cont = new ReadTask62(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask62(db,b), false);
  // (crule (pre (let _00024sqc1ev651 const6b86b273ff34fce19d6b804e) (let _00024sqc1WHS52 const5feceb66ffc86f38d952786c) (let _00024sqc5ubW53 const6b86b273ff34fce19d6b804e) (let _00024sqc1mMQ54 const5feceb66ffc86f38d952786c) (let _00024sqo1C8F59 const5feceb66ffc86f38d952786c) (let __t3eCF12 (lempty))) (probe $seq_at (1 0 2) 1 _00024sqo1C8F59 x _00024seq0) (body (letp _00024sql9SmE49 (aslst _00024seq0)) (let _00024sqn2ic850 (llen _00024sql9SmE49)) (cmp ge _00024sqn2ic850 _00024sqc1ev651) (let _00024sqp3dMm55 (_0002d _00024sqn2ic850 _00024sqc1mMQ54)) (let xs (lslice _00024sql9SmE49 _00024sqc5ubW53 _00024sqp3dMm55)) (exists map2 (2 0 1) 1 _00024seq0) (exists apply1 (2 0 1) 1 x) (exists map2 (2 0 1) 1 xs) (join $sup54764x9x0x0x0 (0 3 4 1 2) 3 _00024seq0 x xs __t7MFn15 f) (join map2 (1 2 0) 3 f _00024seq0 __t7MFn15) (exists map2 (1 2 0) 2 f xs) (join apply1 (1 2 0) 2 f x __t1dTY16) (exists apply1_ans (0 1) 1 __t1dTY16) (join map2 (1 2 0) 2 f xs __t7Zs017) (exists map2_ans (0 1) 1 __t7Zs017) (join apply1_ans (0 1) 1 __t1dTY16 __v0) (join map2_ans (0 1) 1 __t7Zs017 __v1) (letp chk63Eb380 (lref _00024sql9SmE49 _00024sqc1WHS52)) (eq x chk63Eb380)) (head (emit-temp temp9KgZ375 __t3eCF12 __t7MFn15 __v0 __v1)) dem_lambda.slog:10 #f)
  class ReadTask77 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** map2index65;  slog::Index** apply1index66;  slog::Index** map2index67;  slog::Index** $sup54764x9x0x0x0index68;  slog::Index** map2index69;  slog::Index** map2index70;  slog::Index** apply1index71;  slog::Index** apply1_ansindex72;  slog::Index** map2index73;  slog::Index** map2_ansindex74;  slog::Index** apply1_ansindex75;  slog::Index** map2_ansindex76;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9KgZ375");
      std::vector<u16> ord78({1, 0, 2});
      slog::Relation* readrel79 = db->getRelation("$seq_at");
      driver_index = readrel79->getIndex(ord78, true);
      std::vector<u16> ord80({2, 0, 1});
      slog::Relation* readrel81 = db->getRelation("map2");
      map2index65 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({2, 0, 1});
      slog::Relation* readrel83 = db->getRelation("apply1");
      apply1index66 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({2, 0, 1});
      slog::Relation* readrel85 = db->getRelation("map2");
      map2index67 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({0, 3, 4, 1, 2});
      slog::Relation* readrel87 = db->getRelation("$sup54764x9x0x0x0");
      $sup54764x9x0x0x0index68 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 2, 0});
      slog::Relation* readrel89 = db->getRelation("map2");
      map2index69 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 2, 0});
      slog::Relation* readrel91 = db->getRelation("map2");
      map2index70 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 2, 0});
      slog::Relation* readrel93 = db->getRelation("apply1");
      apply1index71 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({0, 1});
      slog::Relation* readrel95 = db->getRelation("apply1_ans");
      apply1_ansindex72 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 2, 0});
      slog::Relation* readrel97 = db->getRelation("map2");
      map2index73 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({0, 1});
      slog::Relation* readrel99 = db->getRelation("map2_ans");
      map2_ansindex74 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({0, 1});
      slog::Relation* readrel101 = db->getRelation("apply1_ans");
      apply1_ansindex75 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 1});
      slog::Relation* readrel103 = db->getRelation("map2_ans");
      map2_ansindex76 = readrel103->getIndex(ord102, false);
  
    }
    ReadTask77(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_const5feceb66ffc86f38d952786c;
      u64 v_c0 = _prim_lempty(db);
      if (v_c0 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c9, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m104) {
        u64 v_c14 = m104[1];
        u64 v_c13 = m104[2];
        if (buckethash(v_c14) != bucket) return;
        bool ok105 = true;
        u64 v_c16 = _prim_aslst(db, v_c13, &ok105);
        if (!ok105) return;
        u64 v_c17 = _prim_llen(db, v_c16);
        if (v_c17 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        u64 v_c46 = _prim_ge(db, v_c17, v_c5);
        if (v_c46 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        if (!v_c46) return;
        u64 v_c20 = _prim__0002d(db, v_c17, v_c8);
        if (v_c20 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        u64 v_c12 = _prim_lslice(db, v_c16, v_c7, v_c20);
        if (v_c12 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        if (!slog::exists_probe<3,1>(map2index65, std::array<u64,3>{v_c13, 0, 0})) return;
        if (!slog::exists_probe<3,1>(apply1index66, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(map2index67, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<5,3>($sup54764x9x0x0x0index68, std::array<u64,5>{v_c13, v_c14, v_c12, 0, 0}, [&](const std::array<u64,5>& m107) {
          u64 v_c1 = m107[3]; u64 v_c11 = m107[4];
          slog::join_probe<3,3>(map2index69, std::array<u64,3>{v_c11, v_c13, v_c1}, [&](const std::array<u64,3>& m108) {
            if (!slog::exists_probe<3,2>(map2index70, std::array<u64,3>{v_c11, v_c12, 0})) return;
            slog::join_probe<3,2>(apply1index71, std::array<u64,3>{v_c11, v_c14, 0}, [&](const std::array<u64,3>& m109) {
              u64 v_c15 = m109[2];
              if (!slog::exists_probe<2,1>(apply1_ansindex72, std::array<u64,2>{v_c15, 0})) return;
              slog::join_probe<3,2>(map2index73, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m110) {
                u64 v_c10 = m110[2];
                if (!slog::exists_probe<2,1>(map2_ansindex74, std::array<u64,2>{v_c10, 0})) return;
                slog::join_probe<2,1>(apply1_ansindex75, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m111) {
                  u64 v_c2 = m111[1];
                  slog::join_probe<2,1>(map2_ansindex76, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m112) {
                    u64 v_c3 = m112[1];
                    bool ok113 = true;
                    u64 v_c47 = _prim_lref(db, v_c16, v_c6, &ok113);
                    if (!ok113) return;
                    if (v_c14 != v_c47) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c3});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:10", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask77* _cont = new ReadTask77(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask77(db,b), false);
  // (crule (pre) (scan toint_range __erre1HB0359 __errf9eF1360 __errf6FDY361) (body) (head (emit error (0) __erre1HB0359)) <internal>:1 #f)
  class ReadTask114 : public slog::Task
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
      std::vector<u16> ord115({0});
      slog::Relation* readrel116 = db->getRelation("error");
      head_index[0] = readrel116->getIndex(ord115, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask114(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ReadTask114* _cont = new ReadTask114(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask114(db,b), false);
  // (crule (pre) (scan int_overflow __erre1c3x351 __errf1lrR352 __errf6T7v353 __errf5VS3354) (body) (head (emit error (0) __erre1c3x351)) <internal>:1 #f)
  class ReadTask117 : public slog::Task
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
      std::vector<u16> ord118({0});
      slog::Relation* readrel119 = db->getRelation("error");
      head_index[0] = readrel119->getIndex(ord118, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask117(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c51}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask117* _cont = new ReadTask117(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask117(db,b), false);
  // (crule (pre) (scan type_mismatch __erre97Qb362 __errf0cwB363 __errf3IyB364 __errf6YVz365 __errf07n3366) (body) (head (emit error (0) __erre97Qb362)) <internal>:1 #f)
  class ReadTask120 : public slog::Task
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
      std::vector<u16> ord121({0});
      slog::Relation* readrel122 = db->getRelation("error");
      head_index[0] = readrel122->getIndex(ord121, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask120(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c57 = _t[2];
        u64 v_c58 = _t[3];
        u64 v_c59 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c55}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask120* _cont = new ReadTask120(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask120(db,b), false);
  s->addReadRel("$seq_at");
  s->addReadRel("$sup54764x9x0x0x0");
  s->addReadRel("apply1");
  s->addReadRel("apply1_ans");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("map2");
  s->addReadRel("map2_ans");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp1vhf381");
  s->addReadRel("temp3tpe377");
  s->addReadRel("temp5R4B376");
  s->addReadRel("temp9KgZ375");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("map2_ans");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("temp1vhf381");
  s->addDynamicRel("temp3tpe377");
  s->addDynamicRel("temp5R4B376");
  s->addDynamicRel("temp9KgZ375");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("map2_ans");
  d->push(s);
  d->continueRun();
}

