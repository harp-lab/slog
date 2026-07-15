
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constafcf65f310629738af953774;
u64 v_const4716e54ebb7b93a657325b50;
u64 v_const4a59dbb9cb3129dfcc75170b;
u64 v_const90712a7e258f8f7102ad607b;
u64 v_const907792eebecaaeea2ef28196;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("5ce830b8");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constafcf65f310629738af953774 = db->encodeString("eval_ans");
  v_const4716e54ebb7b93a657325b50 = db->encodeString("0cfa-counting.slog:47");
  v_const4a59dbb9cb3129dfcc75170b = db->encodeString("eval");
  v_const90712a7e258f8f7102ad607b = db->encodeString("0cfa-counting.slog:45");
  v_const907792eebecaaeea2ef28196 = db->encodeString("0cfa-counting.slog:52");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord1117({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord1117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord1118({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord1118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord1119({1, 2, 0});
    
    r->addIndex<3>(ord1119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1120({0, 1, 2});
    
    r->addIndex<3>(ord1120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("store");
  if (r == 0) db->addRelation("store", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("store");
      std::vector<u16> ord1121({0, 1});
    
    r->addIndex<2>(ord1121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("store"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord1122({1, 2, 0});
    
    r->addIndex<3>(ord1122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1123({0, 1, 2});
    
    r->addIndex<3>(ord1123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("singleton");
  if (r == 0) db->addRelation("singleton", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("singleton");
      std::vector<u16> ord1124({0});
    
    r->addIndex<1>(ord1124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("singleton"), std::array<u16,1>{0}, b));
  r = db->getRelation("result");
  if (r == 0) db->addRelation("result", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("result");
      std::vector<u16> ord1125({0});
    
    r->addIndex<1>(ord1125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("result"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord1126({1, 0});
    
    r->addIndex<2>(ord1126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord1127({0, 1});
    
    r->addIndex<2>(ord1127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("program");
  if (r == 0) db->addRelation("program", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program");
      std::vector<u16> ord1128({0});
    
    r->addIndex<1>(ord1128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program"), std::array<u16,1>{0}, b));
  r = db->getRelation("polyvariant");
  if (r == 0) db->addRelation("polyvariant", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("polyvariant");
      std::vector<u16> ord1129({0});
    
    r->addIndex<1>(ord1129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("polyvariant"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord1130({1, 2, 3, 0});
    
    r->addIndex<4>(ord1130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord1131({0, 1, 2, 3});
    
    r->addIndex<4>(ord1131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mu");
  if (r == 0) db->addRelation("mu", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mu");
  r->setLattice(LAT_COUNT, false, 0, false, 0, "count", db->collections());
      std::vector<u16> ord1132({0, 1});
    
    r->addMapIndex<2>(ord1132);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<2>(db, r, std::array<u16,2>{0, 1}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<2>(db, db->getRelation("mu"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord1133({1, 2, 0});
    
    r->addIndex<3>(ord1133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1134({0, 1, 2});
    
    r->addIndex<3>(ord1134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord1135({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord1135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord1136({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord1136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord1137({1, 2, 0});
    
    r->addIndex<3>(ord1137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1138({0, 1, 2});
    
    r->addIndex<3>(ord1138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord1139({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord1139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord1140({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord1140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lambda");
  if (r == 0) db->addStruct("lambda", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lambda");
      std::vector<u16> ord1141({2, 1, 0});
    
    r->addIndex<3>(ord1141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord1142({0, 1, 2});
    
    r->addIndex<3>(ord1142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lambda"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord1143({1, 2, 3, 0});
    
    r->addIndex<4>(ord1143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord1144({0, 1, 2, 3});
    
    r->addIndex<4>(ord1144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("eval_ans");
  if (r == 0) db->addRelation("eval_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_ans");
      std::vector<u16> ord1145({0, 1});
    
    r->addIndex<2>(ord1145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord1146({1, 0});
    
    r->addIndex<2>(ord1146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord1147({0, 1});
    
    r->addIndex<2>(ord1147, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("eval");
  if (r == 0) db->addStruct("eval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval");
      std::vector<u16> ord1148({1, 0});
    
    r->addIndex<2>(ord1148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord1149({0, 1});
    
    r->addIndex<2>(ord1149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord1150({0, 1});
    
    r->addIndex<2>(ord1150, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord1151({1, 0});
    
    r->addIndex<2>(ord1151, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("eval"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord1152({0});
    
    r->addIndex<1>(ord1152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord1153({1, 2, 0});
    
    r->addIndex<3>(ord1153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1154({0, 1, 2});
    
    r->addIndex<3>(ord1154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("app");
  if (r == 0) db->addStruct("app", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("app");
      std::vector<u16> ord1155({1, 2, 0});
    
    r->addIndex<3>(ord1155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1156({0, 1, 2});
    
    r->addIndex<3>(ord1156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord1157({2, 0, 1});
    
    r->addIndex<3>(ord1157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("app"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord1158({1, 0});
    
    r->addIndex<2>(ord1158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord1159({0, 1});
    
    r->addIndex<2>(ord1159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup7183x51x0x0x0");
  if (r == 0) db->addRelation("$sup7183x51x0x0x0", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup7183x51x0x0x0");
      std::vector<u16> ord1160({0, 1});
    
    r->addIndex<2>(ord1160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord1161({1, 0});
    
    r->addIndex<2>(ord1161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord1162({0, 1});
    
    r->addIndex<2>(ord1162, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord1163({1, 0});
    
    r->addIndex<2>(ord1163, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("$sup7183x51x0x0x0"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("$sup7183x46x0x0x1");
  if (r == 0) db->addRelation("$sup7183x46x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup7183x46x0x0x1");
      std::vector<u16> ord1164({0, 3, 5, 1, 2, 4, 6, 7});
    
    r->addIndex<8>(ord1164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7}, false, b), true);
      std::vector<u16> ord1165({1, 5, 0, 2, 3, 4, 6, 7});
    
    r->addIndex<8>(ord1165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7}, false, b), false);
      std::vector<u16> ord1166({2, 3, 6, 0, 1, 4, 5, 7});
    
    r->addIndex<8>(ord1166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{2, 3, 6, 0, 1, 4, 5, 7}, false, b), false);
      std::vector<u16> ord1167({2, 6, 0, 1, 3, 4, 5, 7});
    
    r->addIndex<8>(ord1167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{2, 6, 0, 1, 3, 4, 5, 7}, false, b), false);
      std::vector<u16> ord1168({4, 7, 1, 0, 2, 3, 5, 6});
    
    r->addIndex<8>(ord1168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{4, 7, 1, 0, 2, 3, 5, 6}, false, b), false);
      std::vector<u16> ord1169({0, 3, 5, 1, 2, 4, 6, 7});
    
    r->addIndex<8>(ord1169, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7}, true, b), false);
      std::vector<u16> ord1170({2, 3, 6, 0, 1, 4, 5, 7});
    
    r->addIndex<8>(ord1170, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{2, 3, 6, 0, 1, 4, 5, 7}, true, b), false);
      std::vector<u16> ord1171({4, 7, 1, 0, 2, 3, 5, 6});
    
    r->addIndex<8>(ord1171, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{4, 7, 1, 0, 2, 3, 5, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup7183x46x0x0x1"), std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7}, b));
  r = db->getRelation("$sup7183x46x0x0x0");
  if (r == 0) db->addRelation("$sup7183x46x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup7183x46x0x0x0");
      std::vector<u16> ord1172({0, 1, 2});
    
    r->addIndex<3>(ord1172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord1173({1, 0, 2});
    
    r->addIndex<3>(ord1173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), false);
      std::vector<u16> ord1174({2, 0, 1});
    
    r->addIndex<3>(ord1174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord1175({0, 1, 2});
    
    r->addIndex<3>(ord1175, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord1176({2, 0, 1});
    
    r->addIndex<3>(ord1176, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup7183x46x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  // (crule (pre) (scan eval __8PL765 __t4x8R47) (body (join app (0 1 2) 1 __t4x8R47 ef ea)) (head (emit $sup7183x51x0x0x0 (0 1) ea ef)) 0cfa-counting.slog:52 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup7183x51x0x0x0");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("$sup7183x51x0x0x0");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord4({0, 1, 2});
      slog::Relation* readrel5 = db->getRelation("app");
      appindex0 = readrel5->getIndex(ord4, false);
  
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
        u64 v_c0 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe<3,1>(appindex0, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m6) {
          u64 v_c2 = m6[1]; u64 v_c3 = m6[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c3, v_c2}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:52", "delta:eval", _fires);
  
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
  // (crule (pre) (scan program e) (body) (head (mkstruct eval (1 0) __9uyK56 e)) 0cfa-counting.slog:55 #f)
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
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("program");
  
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
        u64 v_c4 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:55", "all:program", _fires);
  
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
      s->addTask(phase_read, new ReadTask7(db,b), true);
  // (crule (pre (let __trid28Cm75 const907792eebecaaeea2ef28196) (let __trel1Ehf76 const4a59dbb9cb3129dfcc75170b) (let __tcol6Xql77 const5feceb66ffc86f38d952786c)) (scan $sup7183x51x0x0x0 ea ef) (body) (head (tycheck ea (accept (struct app) (struct lambda) (struct ref)) __trid28Cm75 __trel1Ehf76 __tcol6Xql77 (1 2 3 4 0)) (mkstruct eval (1 0) __0Cy274 ea)) 0cfa-counting.slog:52 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid8;  u32 sid9;  u32 sid10;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup7183x51x0x0x0");
      sid8 = db->getRelation("app")->getStructId();
      sid9 = db->getRelation("lambda")->getStructId();
      sid10 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const907792eebecaaeea2ef28196;
      u64 v_c6 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        u64 v_c2 = _t[1];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid8 || decode_struct_id(v_c3) == sid9 || decode_struct_id(v_c3) == sid10))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c5, v_c6, v_c7, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:52", "delta:$sup7183x51x0x0x0", _fires);
  
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
  // (crule (pre (let __trid46ST71 const4716e54ebb7b93a657325b50) (let __trel4yNt72 const4a59dbb9cb3129dfcc75170b) (let __tcol3Wai73 const5feceb66ffc86f38d952786c)) (scan $sup7183x46x0x0x0 __d0 ea ef) (body) (head (tycheck ef (accept (struct app) (struct lambda) (struct ref)) __trid46ST71 __trel4yNt72 __tcol3Wai73 (1 2 3 4 0)) (mkstruct eval (1 0) __9Mpm70 ef)) 0cfa-counting.slog:47 #f)
  class ReadTask15 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid12;  u32 sid13;  u32 sid14;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup7183x46x0x0x0");
      sid12 = db->getRelation("app")->getStructId();
      sid13 = db->getRelation("lambda")->getStructId();
      sid14 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c8 = v_const4716e54ebb7b93a657325b50;
      u64 v_c9 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c10 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        ++_fires;
        if (!((is_struct(v_c2) && (decode_struct_id(v_c2) == sid12 || decode_struct_id(v_c2) == sid13 || decode_struct_id(v_c2) == sid14))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c8, v_c9, v_c10, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:$sup7183x46x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask15* _cont = new ReadTask15(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), false);
  // (crule (pre) (scan eval_ans __t2C9Q48 __t9RnS49) (body (join-old eval (0 1) 1 (0 1) __t2C9Q48 ef) (join $sup7183x46x0x0x0 (2 0 1) 1 ef __d0 ea) (join-old eval (1 0) 1 (1 0) ea __t0jk050) (join-old eval_ans (0 1) 1 (0 1) __t0jk050 va) (join lambda (0 1 2) 1 __t9RnS49 x eb)) (head (emit $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2C9Q48 __t0jk050 eb va x)) 0cfa-counting.slog:47 #f)
  class ReadTask24 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex16;  slog::Index** $sup7183x46x0x0x0index17;  slog::Index** evalindex18;  slog::Index** eval_ansindex19;  slog::Index** lambdaindex20;  slog::Index** evaldelta21;  slog::Index** evaldelta22;  slog::Index** eval_ansdelta23;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup7183x46x0x0x1");
      std::vector<u16> ord25({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel26 = db->getRelation("$sup7183x46x0x0x1");
      head_index[0] = readrel26->getIndex(ord25, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord27({0, 1});
      slog::Relation* readrel28 = db->getRelation("eval");
      evalindex16 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({0, 1});
      slog::Relation* readrel30 = db->getRelation("eval");
      evaldelta21 = readrel30->getIndex(ord29, true);
      std::vector<u16> ord31({2, 0, 1});
      slog::Relation* readrel32 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index17 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("eval");
      evalindex18 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("eval");
      evaldelta22 = readrel36->getIndex(ord35, true);
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("eval_ans");
      eval_ansindex19 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("eval_ans");
      eval_ansdelta23 = readrel40->getIndex(ord39, true);
      std::vector<u16> ord41({0, 1, 2});
      slog::Relation* readrel42 = db->getRelation("lambda");
      lambdaindex20 = readrel42->getIndex(ord41, false);
  
    }
    ReadTask24(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[0];
        u64 v_c13 = _t[1];
        slog::join_probe_old<2,1>(evalindex16, evaldelta21, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m43) {
          u64 v_c2 = m43[1];
          slog::join_probe<3,1>($sup7183x46x0x0x0index17, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m44) {
            u64 v_c11 = m44[1]; u64 v_c3 = m44[2];
            slog::join_probe_old<2,1>(evalindex18, evaldelta22, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m45) {
              u64 v_c14 = m45[1];
              slog::join_probe_old<2,1>(eval_ansindex19, eval_ansdelta23, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m46) {
                u64 v_c15 = m46[1];
                slog::join_probe<3,1>(lambdaindex20, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m47) {
                  u64 v_c16 = m47[1]; u64 v_c17 = m47[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c11, v_c3, v_c2, v_c12, v_c14, v_c17, v_c15, v_c16}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask24* _cont = new ReadTask24(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask24(db,b), false);
  // (crule (pre) (scan store x v) (body (join ref (1 0) 1 x __t8RU242) (join-old eval (1 0) 1 (1 0) __t8RU242 __t1h5443)) (head (emit eval_ans (0 1) __t1h5443 v)) 0cfa-counting.slog:46 #f)
  class ReadTask51 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex48;  slog::Index** evalindex49;  slog::Index** evaldelta50;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord52({0, 1});
      slog::Relation* readrel53 = db->getRelation("eval_ans");
      head_index[0] = readrel53->getIndex(ord52, false);
      outer_rel = db->getRelation("store");
      std::vector<u16> ord54({1, 0});
      slog::Relation* readrel55 = db->getRelation("ref");
      refindex48 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 0});
      slog::Relation* readrel57 = db->getRelation("eval");
      evalindex49 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 0});
      slog::Relation* readrel59 = db->getRelation("eval");
      evaldelta50 = readrel59->getIndex(ord58, true);
  
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
        u64 v_c16 = _t[0];
        u64 v_c18 = _t[1];
        slog::join_probe<2,1>(refindex48, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m60) {
          u64 v_c19 = m60[1];
          slog::join_probe_old<2,1>(evalindex49, evaldelta50, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m61) {
            u64 v_c20 = m61[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c20, v_c18}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:46", "delta:store", _fires);
  
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
  // (crule (pre) (scan eval_ans __t4JRN26 __t7eB027) (body (join-old eval (0 1) 1 (0 1) __t4JRN26 ef) (exists app (1 2 0) 1 ef) (join-old $sup7183x51x0x0x0 (1 0) 1 (1 0) ef ea) (exists eval (1 0) 1 ea) (join app (1 2 0) 2 ef ea __t2z5k25) (join eval (1 0) 1 __t2z5k25 __3RTs64) (join-old eval (1 0) 1 (1 0) ea __t9l7D28) (join-old eval_ans (0 1) 1 (0 1) __t9l7D28 va) (join lambda (0 1 2) 1 __t7eB027 x eb)) (head (emit store (0 1) x va)) 0cfa-counting.slog:52 #f)
  class ReadTask75 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex62;  slog::Index** appindex63;  slog::Index** $sup7183x51x0x0x0index64;  slog::Index** evalindex65;  slog::Index** appindex66;  slog::Index** evalindex67;  slog::Index** evalindex68;  slog::Index** eval_ansindex69;  slog::Index** lambdaindex70;  slog::Index** evaldelta71;  slog::Index** $sup7183x51x0x0x0delta72;  slog::Index** evaldelta73;  slog::Index** eval_ansdelta74;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord76({0, 1});
      slog::Relation* readrel77 = db->getRelation("store");
      head_index[0] = readrel77->getIndex(ord76, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("eval");
      evalindex62 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({0, 1});
      slog::Relation* readrel81 = db->getRelation("eval");
      evaldelta71 = readrel81->getIndex(ord80, true);
      std::vector<u16> ord82({1, 2, 0});
      slog::Relation* readrel83 = db->getRelation("app");
      appindex63 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 0});
      slog::Relation* readrel85 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0index64 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 0});
      slog::Relation* readrel87 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0delta72 = readrel87->getIndex(ord86, true);
      std::vector<u16> ord88({1, 0});
      slog::Relation* readrel89 = db->getRelation("eval");
      evalindex65 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 2, 0});
      slog::Relation* readrel91 = db->getRelation("app");
      appindex66 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 0});
      slog::Relation* readrel93 = db->getRelation("eval");
      evalindex67 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0});
      slog::Relation* readrel95 = db->getRelation("eval");
      evalindex68 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 0});
      slog::Relation* readrel97 = db->getRelation("eval");
      evaldelta73 = readrel97->getIndex(ord96, true);
      std::vector<u16> ord98({0, 1});
      slog::Relation* readrel99 = db->getRelation("eval_ans");
      eval_ansindex69 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({0, 1});
      slog::Relation* readrel101 = db->getRelation("eval_ans");
      eval_ansdelta74 = readrel101->getIndex(ord100, true);
      std::vector<u16> ord102({0, 1, 2});
      slog::Relation* readrel103 = db->getRelation("lambda");
      lambdaindex70 = readrel103->getIndex(ord102, false);
  
    }
    ReadTask75(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(evalindex62, evaldelta71, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m104) {
          u64 v_c2 = m104[1];
          if (!slog::exists_probe<3,1>(appindex63, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<2,1>($sup7183x51x0x0x0index64, $sup7183x51x0x0x0delta72, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m105) {
            u64 v_c3 = m105[1];
            if (!slog::exists_probe<2,1>(evalindex65, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe<3,2>(appindex66, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m106) {
              u64 v_c23 = m106[2];
              slog::join_probe<2,1>(evalindex67, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m107) {
                u64 v_c24 = m107[1];
                slog::join_probe_old<2,1>(evalindex68, evaldelta73, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m108) {
                  u64 v_c25 = m108[1];
                  slog::join_probe_old<2,1>(eval_ansindex69, eval_ansdelta74, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m109) {
                    u64 v_c15 = m109[1];
                    slog::join_probe<3,1>(lambdaindex70, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m110) {
                      u64 v_c16 = m110[1]; u64 v_c17 = m110[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c15}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:52", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask75* _cont = new ReadTask75(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask75(db,b), false);
  // (crule (pre) (scan eval __t84W231 ef) (body (exists $sup7183x46x0x0x0 (2 0 1) 1 ef) (exists $sup7183x46x0x0x1 (1 5 0 2 3 4 6 7) 2 __t84W231 ef) (exists app (1 2 0) 1 ef) (join eval_ans (0 1) 1 __t84W231 __t6lKC32) (join $sup7183x46x0x0x0 (2 0 1) 1 ef __t3I5X30 ea) (exists eval (1 0) 1 ea) (exists app (1 2 0) 2 ef ea) (join $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) 4 __t3I5X30 ea ef __t84W231 __t1bAv33 eb va x) (join lambda (2 1 0) 3 eb x __t6lKC32) (join eval_ans (0 1) 2 __t1bAv33 va) (join-old eval (0 1) 2 (0 1) __t1bAv33 ea) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t1ou629) (join eval (0 1) 2 __t3I5X30 __t1ou629) (join-old eval (1 0) 1 (1 0) eb __t4ga134) (join eval_ans (0 1) 1 __t4ga134 v)) (head (emit eval_ans (0 1) __t3I5X30 v)) 0cfa-counting.slog:47 #f)
  class ReadTask129 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x46x0x0x0index111;  slog::Index** $sup7183x46x0x0x1index112;  slog::Index** appindex113;  slog::Index** eval_ansindex114;  slog::Index** $sup7183x46x0x0x0index115;  slog::Index** evalindex116;  slog::Index** appindex117;  slog::Index** $sup7183x46x0x0x1index118;  slog::Index** lambdaindex119;  slog::Index** eval_ansindex120;  slog::Index** evalindex121;  slog::Index** evalindex122;  slog::Index** appindex123;  slog::Index** evalindex124;  slog::Index** evalindex125;  slog::Index** eval_ansindex126;  slog::Index** evaldelta127;  slog::Index** evaldelta128;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord130({0, 1});
      slog::Relation* readrel131 = db->getRelation("eval_ans");
      head_index[0] = readrel131->getIndex(ord130, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord132({2, 0, 1});
      slog::Relation* readrel133 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index111 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel135 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index112 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("app");
      appindex113 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({0, 1});
      slog::Relation* readrel139 = db->getRelation("eval_ans");
      eval_ansindex114 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({2, 0, 1});
      slog::Relation* readrel141 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index115 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 0});
      slog::Relation* readrel143 = db->getRelation("eval");
      evalindex116 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 2, 0});
      slog::Relation* readrel145 = db->getRelation("app");
      appindex117 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel147 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index118 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({2, 1, 0});
      slog::Relation* readrel149 = db->getRelation("lambda");
      lambdaindex119 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 1});
      slog::Relation* readrel151 = db->getRelation("eval_ans");
      eval_ansindex120 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({0, 1});
      slog::Relation* readrel153 = db->getRelation("eval");
      evalindex121 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({0, 1});
      slog::Relation* readrel155 = db->getRelation("eval");
      evaldelta127 = readrel155->getIndex(ord154, true);
      std::vector<u16> ord156({1, 0});
      slog::Relation* readrel157 = db->getRelation("eval");
      evalindex122 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 2, 0});
      slog::Relation* readrel159 = db->getRelation("app");
      appindex123 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0, 1});
      slog::Relation* readrel161 = db->getRelation("eval");
      evalindex124 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 0});
      slog::Relation* readrel163 = db->getRelation("eval");
      evalindex125 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 0});
      slog::Relation* readrel165 = db->getRelation("eval");
      evaldelta128 = readrel165->getIndex(ord164, true);
      std::vector<u16> ord166({0, 1});
      slog::Relation* readrel167 = db->getRelation("eval_ans");
      eval_ansindex126 = readrel167->getIndex(ord166, false);
  
    }
    ReadTask129(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<3,1>($sup7183x46x0x0x0index111, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<8,2>($sup7183x46x0x0x1index112, std::array<u64,8>{v_c26, v_c2, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex113, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex114, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m168) {
          u64 v_c27 = m168[1];
          slog::join_probe<3,1>($sup7183x46x0x0x0index115, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m169) {
            u64 v_c28 = m169[1]; u64 v_c3 = m169[2];
            if (!slog::exists_probe<2,1>(evalindex116, std::array<u64,2>{v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(appindex117, std::array<u64,3>{v_c2, v_c3, 0})) return;
            slog::join_probe<8,4>($sup7183x46x0x0x1index118, std::array<u64,8>{v_c28, v_c3, v_c2, v_c26, 0, 0, 0, 0}, [&](const std::array<u64,8>& m170) {
              u64 v_c29 = m170[4]; u64 v_c17 = m170[5]; u64 v_c15 = m170[6]; u64 v_c16 = m170[7];
              slog::join_probe<3,3>(lambdaindex119, std::array<u64,3>{v_c17, v_c16, v_c27}, [&](const std::array<u64,3>& m171) {
                slog::join_probe<2,2>(eval_ansindex120, std::array<u64,2>{v_c29, v_c15}, [&](const std::array<u64,2>& m172) {
                  slog::join_probe_old<2,2>(evalindex121, evaldelta127, std::array<u64,2>{v_c29, v_c3}, [&](const std::array<u64,2>& m173) {
                    if (!slog::exists_probe<2,1>(evalindex122, std::array<u64,2>{v_c17, 0})) return;
                    slog::join_probe<3,2>(appindex123, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m174) {
                      u64 v_c30 = m174[2];
                      slog::join_probe<2,2>(evalindex124, std::array<u64,2>{v_c28, v_c30}, [&](const std::array<u64,2>& m175) {
                        slog::join_probe_old<2,1>(evalindex125, evaldelta128, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m176) {
                          u64 v_c31 = m176[1];
                          slog::join_probe<2,1>(eval_ansindex126, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m177) {
                            u64 v_c18 = m177[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c18}, std::array<u16,2>{0, 1});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask129* _cont = new ReadTask129(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask129(db,b), false);
  // (crule (pre) (scan $sup7183x51x0x0x0 ea ef) (body (exists eval (1 0) 1 ef) (exists eval (1 0) 1 ea) (join app (1 2 0) 2 ef ea __t2z5k25) (join eval (1 0) 1 __t2z5k25 __3RTs64) (join-old eval (1 0) 1 (1 0) ef __t4JRN26) (join eval_ans (0 1) 1 __t4JRN26 __t7eB027) (join-old eval (1 0) 1 (1 0) ea __t9l7D28) (join eval_ans (0 1) 1 __t9l7D28 va) (join lambda (0 1 2) 1 __t7eB027 x eb)) (head (emit store (0 1) x va)) 0cfa-counting.slog:52 #f)
  class ReadTask189 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex178;  slog::Index** evalindex179;  slog::Index** appindex180;  slog::Index** evalindex181;  slog::Index** evalindex182;  slog::Index** eval_ansindex183;  slog::Index** evalindex184;  slog::Index** eval_ansindex185;  slog::Index** lambdaindex186;  slog::Index** evaldelta187;  slog::Index** evaldelta188;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("store");
      head_index[0] = readrel191->getIndex(ord190, false);
      outer_rel = db->getRelation("$sup7183x51x0x0x0");
      std::vector<u16> ord192({1, 0});
      slog::Relation* readrel193 = db->getRelation("eval");
      evalindex178 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 0});
      slog::Relation* readrel195 = db->getRelation("eval");
      evalindex179 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 0});
      slog::Relation* readrel197 = db->getRelation("app");
      appindex180 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({1, 0});
      slog::Relation* readrel199 = db->getRelation("eval");
      evalindex181 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 0});
      slog::Relation* readrel201 = db->getRelation("eval");
      evalindex182 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({1, 0});
      slog::Relation* readrel203 = db->getRelation("eval");
      evaldelta187 = readrel203->getIndex(ord202, true);
      std::vector<u16> ord204({0, 1});
      slog::Relation* readrel205 = db->getRelation("eval_ans");
      eval_ansindex183 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 0});
      slog::Relation* readrel207 = db->getRelation("eval");
      evalindex184 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 0});
      slog::Relation* readrel209 = db->getRelation("eval");
      evaldelta188 = readrel209->getIndex(ord208, true);
      std::vector<u16> ord210({0, 1});
      slog::Relation* readrel211 = db->getRelation("eval_ans");
      eval_ansindex185 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({0, 1, 2});
      slog::Relation* readrel213 = db->getRelation("lambda");
      lambdaindex186 = readrel213->getIndex(ord212, false);
  
    }
    ReadTask189(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<2,1>(evalindex178, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(evalindex179, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<3,2>(appindex180, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m214) {
          u64 v_c23 = m214[2];
          slog::join_probe<2,1>(evalindex181, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m215) {
            u64 v_c24 = m215[1];
            slog::join_probe_old<2,1>(evalindex182, evaldelta187, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m216) {
              u64 v_c21 = m216[1];
              slog::join_probe<2,1>(eval_ansindex183, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m217) {
                u64 v_c22 = m217[1];
                slog::join_probe_old<2,1>(evalindex184, evaldelta188, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m218) {
                  u64 v_c25 = m218[1];
                  slog::join_probe<2,1>(eval_ansindex185, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m219) {
                    u64 v_c15 = m219[1];
                    slog::join_probe<3,1>(lambdaindex186, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m220) {
                      u64 v_c16 = m220[1]; u64 v_c17 = m220[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c15}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:52", "delta:$sup7183x51x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask189* _cont = new ReadTask189(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask189(db,b), false);
  // (crule (pre) (scan eval __t0jk050 ea) (body (exists $sup7183x46x0x0x0 (1 0 2) 1 ea) (join eval_ans (0 1) 1 __t0jk050 va) (join $sup7183x46x0x0x0 (1 0 2) 1 ea __d0 ef) (join eval (1 0) 1 ef __t2C9Q48) (join eval_ans (0 1) 1 __t2C9Q48 __t9RnS49) (join lambda (0 1 2) 1 __t9RnS49 x eb)) (head (emit $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2C9Q48 __t0jk050 eb va x)) 0cfa-counting.slog:47 #f)
  class ReadTask227 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x46x0x0x0index221;  slog::Index** eval_ansindex222;  slog::Index** $sup7183x46x0x0x0index223;  slog::Index** evalindex224;  slog::Index** eval_ansindex225;  slog::Index** lambdaindex226;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup7183x46x0x0x1");
      std::vector<u16> ord228({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel229 = db->getRelation("$sup7183x46x0x0x1");
      head_index[0] = readrel229->getIndex(ord228, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord230({1, 0, 2});
      slog::Relation* readrel231 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index221 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 1});
      slog::Relation* readrel233 = db->getRelation("eval_ans");
      eval_ansindex222 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 0, 2});
      slog::Relation* readrel235 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index223 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 0});
      slog::Relation* readrel237 = db->getRelation("eval");
      evalindex224 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({0, 1});
      slog::Relation* readrel239 = db->getRelation("eval_ans");
      eval_ansindex225 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({0, 1, 2});
      slog::Relation* readrel241 = db->getRelation("lambda");
      lambdaindex226 = readrel241->getIndex(ord240, false);
  
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
        u64 v_c14 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<3,1>($sup7183x46x0x0x0index221, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex222, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m242) {
          u64 v_c15 = m242[1];
          slog::join_probe<3,1>($sup7183x46x0x0x0index223, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m243) {
            u64 v_c11 = m243[1]; u64 v_c2 = m243[2];
            slog::join_probe<2,1>(evalindex224, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m244) {
              u64 v_c12 = m244[1];
              slog::join_probe<2,1>(eval_ansindex225, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m245) {
                u64 v_c13 = m245[1];
                slog::join_probe<3,1>(lambdaindex226, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m246) {
                  u64 v_c16 = m246[1]; u64 v_c17 = m246[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c11, v_c3, v_c2, v_c12, v_c14, v_c17, v_c15, v_c16}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval", _fires);
  
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
  // (crule (pre) (scan eval __t1h5443 __t8RU242) (body (join ref (0 1) 1 __t8RU242 x) (join store (0 1) 1 x v)) (head (emit eval_ans (0 1) __t1h5443 v)) 0cfa-counting.slog:46 #f)
  class ReadTask249 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex247;  slog::Index** storeindex248;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord250({0, 1});
      slog::Relation* readrel251 = db->getRelation("eval_ans");
      head_index[0] = readrel251->getIndex(ord250, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord252({0, 1});
      slog::Relation* readrel253 = db->getRelation("ref");
      refindex247 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({0, 1});
      slog::Relation* readrel255 = db->getRelation("store");
      storeindex248 = readrel255->getIndex(ord254, false);
  
    }
    ReadTask249(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[0];
        u64 v_c19 = _t[1];
        slog::join_probe<2,1>(refindex247, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m256) {
          u64 v_c16 = m256[1];
          slog::join_probe<2,1>(storeindex248, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m257) {
            u64 v_c18 = m257[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c20, v_c18}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:46", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask249* _cont = new ReadTask249(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask249(db,b), false);
  // (crule (pre) (scan $sup7183x46x0x0x0 __t3I5X30 ea ef) (body (exists $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) 3 __t3I5X30 ea ef) (exists eval (1 0) 1 ef) (exists eval (1 0) 1 ea) (join app (1 2 0) 2 ef ea __t1ou629) (join-old eval (0 1) 2 (0 1) __t3I5X30 __t1ou629) (join-old $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) 3 (0 3 5 1 2 4 6 7) __t3I5X30 ea ef __t84W231 __t1bAv33 eb va x) (join eval_ans (0 1) 2 __t1bAv33 va) (join-old eval (0 1) 2 (0 1) __t84W231 ef) (join-old eval (0 1) 2 (0 1) __t1bAv33 ea) (exists eval_ans (0 1) 1 __t84W231) (exists eval (1 0) 1 eb) (join lambda (2 1 0) 2 eb x __t6lKC32) (join eval_ans (0 1) 2 __t84W231 __t6lKC32) (join-old eval (1 0) 1 (1 0) eb __t4ga134) (join eval_ans (0 1) 1 __t4ga134 v)) (head (emit eval_ans (0 1) __t3I5X30 v)) 0cfa-counting.slog:47 #f)
  class ReadTask278 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x46x0x0x1index258;  slog::Index** evalindex259;  slog::Index** evalindex260;  slog::Index** appindex261;  slog::Index** evalindex262;  slog::Index** $sup7183x46x0x0x1index263;  slog::Index** eval_ansindex264;  slog::Index** evalindex265;  slog::Index** evalindex266;  slog::Index** eval_ansindex267;  slog::Index** evalindex268;  slog::Index** lambdaindex269;  slog::Index** eval_ansindex270;  slog::Index** evalindex271;  slog::Index** eval_ansindex272;  slog::Index** evaldelta273;  slog::Index** $sup7183x46x0x0x1delta274;  slog::Index** evaldelta275;  slog::Index** evaldelta276;  slog::Index** evaldelta277;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord279({0, 1});
      slog::Relation* readrel280 = db->getRelation("eval_ans");
      head_index[0] = readrel280->getIndex(ord279, false);
      outer_rel = db->getRelation("$sup7183x46x0x0x0");
      std::vector<u16> ord281({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel282 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index258 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 0});
      slog::Relation* readrel284 = db->getRelation("eval");
      evalindex259 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({1, 0});
      slog::Relation* readrel286 = db->getRelation("eval");
      evalindex260 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 2, 0});
      slog::Relation* readrel288 = db->getRelation("app");
      appindex261 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1});
      slog::Relation* readrel290 = db->getRelation("eval");
      evalindex262 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({0, 1});
      slog::Relation* readrel292 = db->getRelation("eval");
      evaldelta273 = readrel292->getIndex(ord291, true);
      std::vector<u16> ord293({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel294 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index263 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel296 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1delta274 = readrel296->getIndex(ord295, true);
      std::vector<u16> ord297({0, 1});
      slog::Relation* readrel298 = db->getRelation("eval_ans");
      eval_ansindex264 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({0, 1});
      slog::Relation* readrel300 = db->getRelation("eval");
      evalindex265 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({0, 1});
      slog::Relation* readrel302 = db->getRelation("eval");
      evaldelta275 = readrel302->getIndex(ord301, true);
      std::vector<u16> ord303({0, 1});
      slog::Relation* readrel304 = db->getRelation("eval");
      evalindex266 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({0, 1});
      slog::Relation* readrel306 = db->getRelation("eval");
      evaldelta276 = readrel306->getIndex(ord305, true);
      std::vector<u16> ord307({0, 1});
      slog::Relation* readrel308 = db->getRelation("eval_ans");
      eval_ansindex267 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({1, 0});
      slog::Relation* readrel310 = db->getRelation("eval");
      evalindex268 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({2, 1, 0});
      slog::Relation* readrel312 = db->getRelation("lambda");
      lambdaindex269 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({0, 1});
      slog::Relation* readrel314 = db->getRelation("eval_ans");
      eval_ansindex270 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 0});
      slog::Relation* readrel316 = db->getRelation("eval");
      evalindex271 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 0});
      slog::Relation* readrel318 = db->getRelation("eval");
      evaldelta277 = readrel318->getIndex(ord317, true);
      std::vector<u16> ord319({0, 1});
      slog::Relation* readrel320 = db->getRelation("eval_ans");
      eval_ansindex272 = readrel320->getIndex(ord319, false);
  
    }
    ReadTask278(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<8,3>($sup7183x46x0x0x1index258, std::array<u64,8>{v_c28, v_c3, v_c2, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(evalindex259, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(evalindex260, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<3,2>(appindex261, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m321) {
          u64 v_c30 = m321[2];
          slog::join_probe_old<2,2>(evalindex262, evaldelta273, std::array<u64,2>{v_c28, v_c30}, [&](const std::array<u64,2>& m322) {
            slog::join_probe_old<8,3>($sup7183x46x0x0x1index263, $sup7183x46x0x0x1delta274, std::array<u64,8>{v_c28, v_c3, v_c2, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m323) {
              u64 v_c26 = m323[3]; u64 v_c29 = m323[4]; u64 v_c17 = m323[5]; u64 v_c15 = m323[6]; u64 v_c16 = m323[7];
              slog::join_probe<2,2>(eval_ansindex264, std::array<u64,2>{v_c29, v_c15}, [&](const std::array<u64,2>& m324) {
                slog::join_probe_old<2,2>(evalindex265, evaldelta275, std::array<u64,2>{v_c26, v_c2}, [&](const std::array<u64,2>& m325) {
                  slog::join_probe_old<2,2>(evalindex266, evaldelta276, std::array<u64,2>{v_c29, v_c3}, [&](const std::array<u64,2>& m326) {
                    if (!slog::exists_probe<2,1>(eval_ansindex267, std::array<u64,2>{v_c26, 0})) return;
                    if (!slog::exists_probe<2,1>(evalindex268, std::array<u64,2>{v_c17, 0})) return;
                    slog::join_probe<3,2>(lambdaindex269, std::array<u64,3>{v_c17, v_c16, 0}, [&](const std::array<u64,3>& m327) {
                      u64 v_c27 = m327[2];
                      slog::join_probe<2,2>(eval_ansindex270, std::array<u64,2>{v_c26, v_c27}, [&](const std::array<u64,2>& m328) {
                        slog::join_probe_old<2,1>(evalindex271, evaldelta277, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m329) {
                          u64 v_c31 = m329[1];
                          slog::join_probe<2,1>(eval_ansindex272, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m330) {
                            u64 v_c18 = m330[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c18}, std::array<u16,2>{0, 1});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:$sup7183x46x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask278* _cont = new ReadTask278(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask278(db,b), false);
  // (crule (pre) (scan eval_ans __t0jk050 va) (body (join-old eval (0 1) 1 (0 1) __t0jk050 ea) (join $sup7183x46x0x0x0 (1 0 2) 1 ea __d0 ef) (join-old eval (1 0) 1 (1 0) ef __t2C9Q48) (join eval_ans (0 1) 1 __t2C9Q48 __t9RnS49) (join lambda (0 1 2) 1 __t9RnS49 x eb)) (head (emit $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2C9Q48 __t0jk050 eb va x)) 0cfa-counting.slog:47 #f)
  class ReadTask338 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex331;  slog::Index** $sup7183x46x0x0x0index332;  slog::Index** evalindex333;  slog::Index** eval_ansindex334;  slog::Index** lambdaindex335;  slog::Index** evaldelta336;  slog::Index** evaldelta337;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup7183x46x0x0x1");
      std::vector<u16> ord339({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel340 = db->getRelation("$sup7183x46x0x0x1");
      head_index[0] = readrel340->getIndex(ord339, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord341({0, 1});
      slog::Relation* readrel342 = db->getRelation("eval");
      evalindex331 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({0, 1});
      slog::Relation* readrel344 = db->getRelation("eval");
      evaldelta336 = readrel344->getIndex(ord343, true);
      std::vector<u16> ord345({1, 0, 2});
      slog::Relation* readrel346 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index332 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 0});
      slog::Relation* readrel348 = db->getRelation("eval");
      evalindex333 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 0});
      slog::Relation* readrel350 = db->getRelation("eval");
      evaldelta337 = readrel350->getIndex(ord349, true);
      std::vector<u16> ord351({0, 1});
      slog::Relation* readrel352 = db->getRelation("eval_ans");
      eval_ansindex334 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({0, 1, 2});
      slog::Relation* readrel354 = db->getRelation("lambda");
      lambdaindex335 = readrel354->getIndex(ord353, false);
  
    }
    ReadTask338(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[0];
        u64 v_c15 = _t[1];
        slog::join_probe_old<2,1>(evalindex331, evaldelta336, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m355) {
          u64 v_c3 = m355[1];
          slog::join_probe<3,1>($sup7183x46x0x0x0index332, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m356) {
            u64 v_c11 = m356[1]; u64 v_c2 = m356[2];
            slog::join_probe_old<2,1>(evalindex333, evaldelta337, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m357) {
              u64 v_c12 = m357[1];
              slog::join_probe<2,1>(eval_ansindex334, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m358) {
                u64 v_c13 = m358[1];
                slog::join_probe<3,1>(lambdaindex335, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m359) {
                  u64 v_c16 = m359[1]; u64 v_c17 = m359[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c11, v_c3, v_c2, v_c12, v_c14, v_c17, v_c15, v_c16}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask338* _cont = new ReadTask338(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask338(db,b), false);
  // (crule (pre) (scan eval __t61wZ41 __t6jmb40) (body (join app (0 1 2) 1 __t6jmb40 ef ea)) (head (emit $sup7183x46x0x0x0 (0 1 2) __t61wZ41 ea ef)) 0cfa-counting.slog:47 #f)
  class ReadTask361 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex360;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup7183x46x0x0x0");
      std::vector<u16> ord362({0, 1, 2});
      slog::Relation* readrel363 = db->getRelation("$sup7183x46x0x0x0");
      head_index[0] = readrel363->getIndex(ord362, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord364({0, 1, 2});
      slog::Relation* readrel365 = db->getRelation("app");
      appindex360 = readrel365->getIndex(ord364, false);
  
    }
    ReadTask361(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[0];
        u64 v_c33 = _t[1];
        slog::join_probe<3,1>(appindex360, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m366) {
          u64 v_c2 = m366[1]; u64 v_c3 = m366[2];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c32, v_c3, v_c2}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask361* _cont = new ReadTask361(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask361(db,b), false);
  // (crule (pre (let __trid1PDX61 const90712a7e258f8f7102ad607b) (let __trel3bCc62 constafcf65f310629738af953774) (let __tcol2GgD63 const6b86b273ff34fce19d6b804e)) (scan eval __t3iY539 __t5noS38) (body (join lambda (0 1 2) 1 __t5noS38 x eb)) (head (tycheck __t5noS38 (accept (struct lambda)) __trid1PDX61 __trel3bCc62 __tcol2GgD63 (1 2 3 4 0)) (emit eval_ans (0 1) __t3iY539 __t5noS38)) 0cfa-counting.slog:45 #f)
  class ReadTask369 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex367;
    u32 sid368;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval_ans");
      std::vector<u16> ord370({0, 1});
      slog::Relation* readrel371 = db->getRelation("eval_ans");
      head_index[1] = readrel371->getIndex(ord370, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord372({0, 1, 2});
      slog::Relation* readrel373 = db->getRelation("lambda");
      lambdaindex367 = readrel373->getIndex(ord372, false);
      sid368 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask369(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const90712a7e258f8f7102ad607b;
      u64 v_c35 = v_constafcf65f310629738af953774;
      u64 v_c36 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c38 = _t[1];
        slog::join_probe<3,1>(lambdaindex367, std::array<u64,3>{v_c38, 0, 0}, [&](const std::array<u64,3>& m374) {
          u64 v_c16 = m374[1]; u64 v_c17 = m374[2];
          ++_fires;
          if (!((is_struct(v_c38) && (decode_struct_id(v_c38) == sid368))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c34, v_c35, v_c36, v_c38}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c37, v_c38}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:45", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask369* _cont = new ReadTask369(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask369(db,b), false);
  // (crule (pre) (scan eval_ans __t1bAv33 va) (body (exists $sup7183x46x0x0x1 (2 6 0 1 3 4 5 7) 2 __t1bAv33 va) (join-old eval (0 1) 1 (0 1) __t1bAv33 ea) (exists $sup7183x46x0x0x0 (1 0 2) 1 ea) (exists app (2 0 1) 1 ea) (join-old $sup7183x46x0x0x1 (2 3 6 0 1 4 5 7) 3 (2 3 6 0 1 4 5 7) __t1bAv33 ea va __t3I5X30 __t84W231 eb ef x) (join-old $sup7183x46x0x0x0 (0 1 2) 3 (0 1 2) __t3I5X30 ea ef) (join-old eval (0 1) 2 (0 1) __t84W231 ef) (exists lambda (2 1 0) 2 eb x) (exists eval_ans (0 1) 1 __t84W231) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t1ou629) (join-old eval (0 1) 2 (0 1) __t3I5X30 __t1ou629) (join lambda (2 1 0) 2 eb x __t6lKC32) (join eval_ans (0 1) 2 __t84W231 __t6lKC32) (join-old eval (1 0) 1 (1 0) eb __t4ga134) (join-old eval_ans (0 1) 1 (0 1) __t4ga134 v)) (head (emit eval_ans (0 1) __t3I5X30 v)) 0cfa-counting.slog:47 #f)
  class ReadTask398 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x46x0x0x1index375;  slog::Index** evalindex376;  slog::Index** $sup7183x46x0x0x0index377;  slog::Index** appindex378;  slog::Index** $sup7183x46x0x0x1index379;  slog::Index** $sup7183x46x0x0x0index380;  slog::Index** evalindex381;  slog::Index** lambdaindex382;  slog::Index** eval_ansindex383;  slog::Index** evalindex384;  slog::Index** appindex385;  slog::Index** evalindex386;  slog::Index** lambdaindex387;  slog::Index** eval_ansindex388;  slog::Index** evalindex389;  slog::Index** eval_ansindex390;  slog::Index** evaldelta391;  slog::Index** $sup7183x46x0x0x1delta392;  slog::Index** $sup7183x46x0x0x0delta393;  slog::Index** evaldelta394;  slog::Index** evaldelta395;  slog::Index** evaldelta396;  slog::Index** eval_ansdelta397;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord399({0, 1});
      slog::Relation* readrel400 = db->getRelation("eval_ans");
      head_index[0] = readrel400->getIndex(ord399, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord401({2, 6, 0, 1, 3, 4, 5, 7});
      slog::Relation* readrel402 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index375 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({0, 1});
      slog::Relation* readrel404 = db->getRelation("eval");
      evalindex376 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({0, 1});
      slog::Relation* readrel406 = db->getRelation("eval");
      evaldelta391 = readrel406->getIndex(ord405, true);
      std::vector<u16> ord407({1, 0, 2});
      slog::Relation* readrel408 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index377 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({2, 0, 1});
      slog::Relation* readrel410 = db->getRelation("app");
      appindex378 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({2, 3, 6, 0, 1, 4, 5, 7});
      slog::Relation* readrel412 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index379 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({2, 3, 6, 0, 1, 4, 5, 7});
      slog::Relation* readrel414 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1delta392 = readrel414->getIndex(ord413, true);
      std::vector<u16> ord415({0, 1, 2});
      slog::Relation* readrel416 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index380 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({0, 1, 2});
      slog::Relation* readrel418 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0delta393 = readrel418->getIndex(ord417, true);
      std::vector<u16> ord419({0, 1});
      slog::Relation* readrel420 = db->getRelation("eval");
      evalindex381 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({0, 1});
      slog::Relation* readrel422 = db->getRelation("eval");
      evaldelta394 = readrel422->getIndex(ord421, true);
      std::vector<u16> ord423({2, 1, 0});
      slog::Relation* readrel424 = db->getRelation("lambda");
      lambdaindex382 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({0, 1});
      slog::Relation* readrel426 = db->getRelation("eval_ans");
      eval_ansindex383 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({1, 0});
      slog::Relation* readrel428 = db->getRelation("eval");
      evalindex384 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({1, 2, 0});
      slog::Relation* readrel430 = db->getRelation("app");
      appindex385 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("eval");
      evalindex386 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({0, 1});
      slog::Relation* readrel434 = db->getRelation("eval");
      evaldelta395 = readrel434->getIndex(ord433, true);
      std::vector<u16> ord435({2, 1, 0});
      slog::Relation* readrel436 = db->getRelation("lambda");
      lambdaindex387 = readrel436->getIndex(ord435, false);
      std::vector<u16> ord437({0, 1});
      slog::Relation* readrel438 = db->getRelation("eval_ans");
      eval_ansindex388 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({1, 0});
      slog::Relation* readrel440 = db->getRelation("eval");
      evalindex389 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({1, 0});
      slog::Relation* readrel442 = db->getRelation("eval");
      evaldelta396 = readrel442->getIndex(ord441, true);
      std::vector<u16> ord443({0, 1});
      slog::Relation* readrel444 = db->getRelation("eval_ans");
      eval_ansindex390 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({0, 1});
      slog::Relation* readrel446 = db->getRelation("eval_ans");
      eval_ansdelta397 = readrel446->getIndex(ord445, true);
  
    }
    ReadTask398(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        if (!slog::exists_probe<8,2>($sup7183x46x0x0x1index375, std::array<u64,8>{v_c29, v_c15, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(evalindex376, evaldelta391, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m447) {
          u64 v_c3 = m447[1];
          if (!slog::exists_probe<3,1>($sup7183x46x0x0x0index377, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex378, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe_old<8,3>($sup7183x46x0x0x1index379, $sup7183x46x0x0x1delta392, std::array<u64,8>{v_c29, v_c3, v_c15, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m448) {
            u64 v_c28 = m448[3]; u64 v_c26 = m448[4]; u64 v_c17 = m448[5]; u64 v_c2 = m448[6]; u64 v_c16 = m448[7];
            slog::join_probe_old<3,3>($sup7183x46x0x0x0index380, $sup7183x46x0x0x0delta393, std::array<u64,3>{v_c28, v_c3, v_c2}, [&](const std::array<u64,3>& m449) {
              slog::join_probe_old<2,2>(evalindex381, evaldelta394, std::array<u64,2>{v_c26, v_c2}, [&](const std::array<u64,2>& m450) {
                if (!slog::exists_probe<3,2>(lambdaindex382, std::array<u64,3>{v_c17, v_c16, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex383, std::array<u64,2>{v_c26, 0})) return;
                if (!slog::exists_probe<2,1>(evalindex384, std::array<u64,2>{v_c17, 0})) return;
                slog::join_probe<3,2>(appindex385, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m451) {
                  u64 v_c30 = m451[2];
                  slog::join_probe_old<2,2>(evalindex386, evaldelta395, std::array<u64,2>{v_c28, v_c30}, [&](const std::array<u64,2>& m452) {
                    slog::join_probe<3,2>(lambdaindex387, std::array<u64,3>{v_c17, v_c16, 0}, [&](const std::array<u64,3>& m453) {
                      u64 v_c27 = m453[2];
                      slog::join_probe<2,2>(eval_ansindex388, std::array<u64,2>{v_c26, v_c27}, [&](const std::array<u64,2>& m454) {
                        slog::join_probe_old<2,1>(evalindex389, evaldelta396, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m455) {
                          u64 v_c31 = m455[1];
                          slog::join_probe_old<2,1>(eval_ansindex390, eval_ansdelta397, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m456) {
                            u64 v_c18 = m456[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c18}, std::array<u16,2>{0, 1});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask398* _cont = new ReadTask398(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask398(db,b), false);
  // (crule (pre) (scan eval __t3I5X30 __t1ou629) (body (exists $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) 1 __t3I5X30) (join $sup7183x46x0x0x0 (0 1 2) 1 __t3I5X30 ea ef) (join app (1 2 0) 3 ef ea __t1ou629) (exists eval (1 0) 1 ef) (exists eval (1 0) 1 ea) (join $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) 3 __t3I5X30 ea ef __t84W231 __t1bAv33 eb va x) (join eval_ans (0 1) 2 __t1bAv33 va) (join-old eval (0 1) 2 (0 1) __t84W231 ef) (join-old eval (0 1) 2 (0 1) __t1bAv33 ea) (exists eval_ans (0 1) 1 __t84W231) (exists eval (1 0) 1 eb) (join lambda (2 1 0) 2 eb x __t6lKC32) (join eval_ans (0 1) 2 __t84W231 __t6lKC32) (join-old eval (1 0) 1 (1 0) eb __t4ga134) (join eval_ans (0 1) 1 __t4ga134 v)) (head (emit eval_ans (0 1) __t3I5X30 v)) 0cfa-counting.slog:47 #f)
  class ReadTask475 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x46x0x0x1index457;  slog::Index** $sup7183x46x0x0x0index458;  slog::Index** appindex459;  slog::Index** evalindex460;  slog::Index** evalindex461;  slog::Index** $sup7183x46x0x0x1index462;  slog::Index** eval_ansindex463;  slog::Index** evalindex464;  slog::Index** evalindex465;  slog::Index** eval_ansindex466;  slog::Index** evalindex467;  slog::Index** lambdaindex468;  slog::Index** eval_ansindex469;  slog::Index** evalindex470;  slog::Index** eval_ansindex471;  slog::Index** evaldelta472;  slog::Index** evaldelta473;  slog::Index** evaldelta474;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord476({0, 1});
      slog::Relation* readrel477 = db->getRelation("eval_ans");
      head_index[0] = readrel477->getIndex(ord476, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord478({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel479 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index457 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({0, 1, 2});
      slog::Relation* readrel481 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index458 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 0});
      slog::Relation* readrel483 = db->getRelation("app");
      appindex459 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({1, 0});
      slog::Relation* readrel485 = db->getRelation("eval");
      evalindex460 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({1, 0});
      slog::Relation* readrel487 = db->getRelation("eval");
      evalindex461 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel489 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index462 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({0, 1});
      slog::Relation* readrel491 = db->getRelation("eval_ans");
      eval_ansindex463 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({0, 1});
      slog::Relation* readrel493 = db->getRelation("eval");
      evalindex464 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1});
      slog::Relation* readrel495 = db->getRelation("eval");
      evaldelta472 = readrel495->getIndex(ord494, true);
      std::vector<u16> ord496({0, 1});
      slog::Relation* readrel497 = db->getRelation("eval");
      evalindex465 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({0, 1});
      slog::Relation* readrel499 = db->getRelation("eval");
      evaldelta473 = readrel499->getIndex(ord498, true);
      std::vector<u16> ord500({0, 1});
      slog::Relation* readrel501 = db->getRelation("eval_ans");
      eval_ansindex466 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({1, 0});
      slog::Relation* readrel503 = db->getRelation("eval");
      evalindex467 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({2, 1, 0});
      slog::Relation* readrel505 = db->getRelation("lambda");
      lambdaindex468 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({0, 1});
      slog::Relation* readrel507 = db->getRelation("eval_ans");
      eval_ansindex469 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 0});
      slog::Relation* readrel509 = db->getRelation("eval");
      evalindex470 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 0});
      slog::Relation* readrel511 = db->getRelation("eval");
      evaldelta474 = readrel511->getIndex(ord510, true);
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("eval_ans");
      eval_ansindex471 = readrel513->getIndex(ord512, false);
  
    }
    ReadTask475(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c30 = _t[1];
        if (!slog::exists_probe<8,1>($sup7183x46x0x0x1index457, std::array<u64,8>{v_c28, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<3,1>($sup7183x46x0x0x0index458, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m514) {
          u64 v_c3 = m514[1]; u64 v_c2 = m514[2];
          slog::join_probe<3,3>(appindex459, std::array<u64,3>{v_c2, v_c3, v_c30}, [&](const std::array<u64,3>& m515) {
            if (!slog::exists_probe<2,1>(evalindex460, std::array<u64,2>{v_c2, 0})) return;
            if (!slog::exists_probe<2,1>(evalindex461, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe<8,3>($sup7183x46x0x0x1index462, std::array<u64,8>{v_c28, v_c3, v_c2, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m516) {
              u64 v_c26 = m516[3]; u64 v_c29 = m516[4]; u64 v_c17 = m516[5]; u64 v_c15 = m516[6]; u64 v_c16 = m516[7];
              slog::join_probe<2,2>(eval_ansindex463, std::array<u64,2>{v_c29, v_c15}, [&](const std::array<u64,2>& m517) {
                slog::join_probe_old<2,2>(evalindex464, evaldelta472, std::array<u64,2>{v_c26, v_c2}, [&](const std::array<u64,2>& m518) {
                  slog::join_probe_old<2,2>(evalindex465, evaldelta473, std::array<u64,2>{v_c29, v_c3}, [&](const std::array<u64,2>& m519) {
                    if (!slog::exists_probe<2,1>(eval_ansindex466, std::array<u64,2>{v_c26, 0})) return;
                    if (!slog::exists_probe<2,1>(evalindex467, std::array<u64,2>{v_c17, 0})) return;
                    slog::join_probe<3,2>(lambdaindex468, std::array<u64,3>{v_c17, v_c16, 0}, [&](const std::array<u64,3>& m520) {
                      u64 v_c27 = m520[2];
                      slog::join_probe<2,2>(eval_ansindex469, std::array<u64,2>{v_c26, v_c27}, [&](const std::array<u64,2>& m521) {
                        slog::join_probe_old<2,1>(evalindex470, evaldelta474, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m522) {
                          u64 v_c31 = m522[1];
                          slog::join_probe<2,1>(eval_ansindex471, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m523) {
                            u64 v_c18 = m523[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c18}, std::array<u16,2>{0, 1});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask475* _cont = new ReadTask475(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask475(db,b), false);
  // (crule (pre) (scan eval __t1bAv33 ea) (body (exists $sup7183x46x0x0x1 (2 3 6 0 1 4 5 7) 2 __t1bAv33 ea) (exists $sup7183x46x0x0x0 (1 0 2) 1 ea) (exists app (2 0 1) 1 ea) (join eval_ans (0 1) 1 __t1bAv33 va) (join $sup7183x46x0x0x1 (2 3 6 0 1 4 5 7) 3 __t1bAv33 ea va __t3I5X30 __t84W231 eb ef x) (join $sup7183x46x0x0x0 (0 1 2) 3 __t3I5X30 ea ef) (join eval (0 1) 2 __t84W231 ef) (exists lambda (2 1 0) 2 eb x) (exists eval_ans (0 1) 1 __t84W231) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t1ou629) (join eval (0 1) 2 __t3I5X30 __t1ou629) (join lambda (2 1 0) 2 eb x __t6lKC32) (join eval_ans (0 1) 2 __t84W231 __t6lKC32) (join-old eval (1 0) 1 (1 0) eb __t4ga134) (join eval_ans (0 1) 1 __t4ga134 v)) (head (emit eval_ans (0 1) __t3I5X30 v)) 0cfa-counting.slog:47 #f)
  class ReadTask541 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x46x0x0x1index524;  slog::Index** $sup7183x46x0x0x0index525;  slog::Index** appindex526;  slog::Index** eval_ansindex527;  slog::Index** $sup7183x46x0x0x1index528;  slog::Index** $sup7183x46x0x0x0index529;  slog::Index** evalindex530;  slog::Index** lambdaindex531;  slog::Index** eval_ansindex532;  slog::Index** evalindex533;  slog::Index** appindex534;  slog::Index** evalindex535;  slog::Index** lambdaindex536;  slog::Index** eval_ansindex537;  slog::Index** evalindex538;  slog::Index** eval_ansindex539;  slog::Index** evaldelta540;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord542({0, 1});
      slog::Relation* readrel543 = db->getRelation("eval_ans");
      head_index[0] = readrel543->getIndex(ord542, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord544({2, 3, 6, 0, 1, 4, 5, 7});
      slog::Relation* readrel545 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index524 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 0, 2});
      slog::Relation* readrel547 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index525 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({2, 0, 1});
      slog::Relation* readrel549 = db->getRelation("app");
      appindex526 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({0, 1});
      slog::Relation* readrel551 = db->getRelation("eval_ans");
      eval_ansindex527 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({2, 3, 6, 0, 1, 4, 5, 7});
      slog::Relation* readrel553 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index528 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({0, 1, 2});
      slog::Relation* readrel555 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index529 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({0, 1});
      slog::Relation* readrel557 = db->getRelation("eval");
      evalindex530 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({2, 1, 0});
      slog::Relation* readrel559 = db->getRelation("lambda");
      lambdaindex531 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({0, 1});
      slog::Relation* readrel561 = db->getRelation("eval_ans");
      eval_ansindex532 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 0});
      slog::Relation* readrel563 = db->getRelation("eval");
      evalindex533 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({1, 2, 0});
      slog::Relation* readrel565 = db->getRelation("app");
      appindex534 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({0, 1});
      slog::Relation* readrel567 = db->getRelation("eval");
      evalindex535 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({2, 1, 0});
      slog::Relation* readrel569 = db->getRelation("lambda");
      lambdaindex536 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({0, 1});
      slog::Relation* readrel571 = db->getRelation("eval_ans");
      eval_ansindex537 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 0});
      slog::Relation* readrel573 = db->getRelation("eval");
      evalindex538 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 0});
      slog::Relation* readrel575 = db->getRelation("eval");
      evaldelta540 = readrel575->getIndex(ord574, true);
      std::vector<u16> ord576({0, 1});
      slog::Relation* readrel577 = db->getRelation("eval_ans");
      eval_ansindex539 = readrel577->getIndex(ord576, false);
  
    }
    ReadTask541(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<8,2>($sup7183x46x0x0x1index524, std::array<u64,8>{v_c29, v_c3, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>($sup7183x46x0x0x0index525, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex526, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex527, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m578) {
          u64 v_c15 = m578[1];
          slog::join_probe<8,3>($sup7183x46x0x0x1index528, std::array<u64,8>{v_c29, v_c3, v_c15, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m579) {
            u64 v_c28 = m579[3]; u64 v_c26 = m579[4]; u64 v_c17 = m579[5]; u64 v_c2 = m579[6]; u64 v_c16 = m579[7];
            slog::join_probe<3,3>($sup7183x46x0x0x0index529, std::array<u64,3>{v_c28, v_c3, v_c2}, [&](const std::array<u64,3>& m580) {
              slog::join_probe<2,2>(evalindex530, std::array<u64,2>{v_c26, v_c2}, [&](const std::array<u64,2>& m581) {
                if (!slog::exists_probe<3,2>(lambdaindex531, std::array<u64,3>{v_c17, v_c16, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex532, std::array<u64,2>{v_c26, 0})) return;
                if (!slog::exists_probe<2,1>(evalindex533, std::array<u64,2>{v_c17, 0})) return;
                slog::join_probe<3,2>(appindex534, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m582) {
                  u64 v_c30 = m582[2];
                  slog::join_probe<2,2>(evalindex535, std::array<u64,2>{v_c28, v_c30}, [&](const std::array<u64,2>& m583) {
                    slog::join_probe<3,2>(lambdaindex536, std::array<u64,3>{v_c17, v_c16, 0}, [&](const std::array<u64,3>& m584) {
                      u64 v_c27 = m584[2];
                      slog::join_probe<2,2>(eval_ansindex537, std::array<u64,2>{v_c26, v_c27}, [&](const std::array<u64,2>& m585) {
                        slog::join_probe_old<2,1>(evalindex538, evaldelta540, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m586) {
                          u64 v_c31 = m586[1];
                          slog::join_probe<2,1>(eval_ansindex539, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m587) {
                            u64 v_c18 = m587[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c18}, std::array<u16,2>{0, 1});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask541* _cont = new ReadTask541(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask541(db,b), false);
  // (crule (pre) (scan $sup7183x46x0x0x1 __t3I5X30 __t84W231 __t1bAv33 ea eb ef va x) (body (join $sup7183x46x0x0x0 (0 1 2) 3 __t3I5X30 ea ef) (join eval_ans (0 1) 2 __t1bAv33 va) (join-old eval (0 1) 2 (0 1) __t84W231 ef) (join-old eval (0 1) 2 (0 1) __t1bAv33 ea) (exists lambda (2 1 0) 2 eb x) (exists eval_ans (0 1) 1 __t84W231) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t1ou629) (join-old eval (0 1) 2 (0 1) __t3I5X30 __t1ou629) (join lambda (2 1 0) 2 eb x __t6lKC32) (join eval_ans (0 1) 2 __t84W231 __t6lKC32) (join-old eval (1 0) 1 (1 0) eb __t4ga134) (join eval_ans (0 1) 1 __t4ga134 v)) (head (emit eval_ans (0 1) __t3I5X30 v)) 0cfa-counting.slog:47 #f)
  class ReadTask605 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x46x0x0x0index588;  slog::Index** eval_ansindex589;  slog::Index** evalindex590;  slog::Index** evalindex591;  slog::Index** lambdaindex592;  slog::Index** eval_ansindex593;  slog::Index** evalindex594;  slog::Index** appindex595;  slog::Index** evalindex596;  slog::Index** lambdaindex597;  slog::Index** eval_ansindex598;  slog::Index** evalindex599;  slog::Index** eval_ansindex600;  slog::Index** evaldelta601;  slog::Index** evaldelta602;  slog::Index** evaldelta603;  slog::Index** evaldelta604;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord606({0, 1});
      slog::Relation* readrel607 = db->getRelation("eval_ans");
      head_index[0] = readrel607->getIndex(ord606, false);
      outer_rel = db->getRelation("$sup7183x46x0x0x1");
      std::vector<u16> ord608({0, 1, 2});
      slog::Relation* readrel609 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index588 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({0, 1});
      slog::Relation* readrel611 = db->getRelation("eval_ans");
      eval_ansindex589 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({0, 1});
      slog::Relation* readrel613 = db->getRelation("eval");
      evalindex590 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({0, 1});
      slog::Relation* readrel615 = db->getRelation("eval");
      evaldelta601 = readrel615->getIndex(ord614, true);
      std::vector<u16> ord616({0, 1});
      slog::Relation* readrel617 = db->getRelation("eval");
      evalindex591 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({0, 1});
      slog::Relation* readrel619 = db->getRelation("eval");
      evaldelta602 = readrel619->getIndex(ord618, true);
      std::vector<u16> ord620({2, 1, 0});
      slog::Relation* readrel621 = db->getRelation("lambda");
      lambdaindex592 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({0, 1});
      slog::Relation* readrel623 = db->getRelation("eval_ans");
      eval_ansindex593 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 0});
      slog::Relation* readrel625 = db->getRelation("eval");
      evalindex594 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 2, 0});
      slog::Relation* readrel627 = db->getRelation("app");
      appindex595 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({0, 1});
      slog::Relation* readrel629 = db->getRelation("eval");
      evalindex596 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({0, 1});
      slog::Relation* readrel631 = db->getRelation("eval");
      evaldelta603 = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({2, 1, 0});
      slog::Relation* readrel633 = db->getRelation("lambda");
      lambdaindex597 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({0, 1});
      slog::Relation* readrel635 = db->getRelation("eval_ans");
      eval_ansindex598 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 0});
      slog::Relation* readrel637 = db->getRelation("eval");
      evalindex599 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 0});
      slog::Relation* readrel639 = db->getRelation("eval");
      evaldelta604 = readrel639->getIndex(ord638, true);
      std::vector<u16> ord640({0, 1});
      slog::Relation* readrel641 = db->getRelation("eval_ans");
      eval_ansindex600 = readrel641->getIndex(ord640, false);
  
    }
    ReadTask605(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c17 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c15 = _t[6];
        u64 v_c16 = _t[7];
        slog::join_probe<3,3>($sup7183x46x0x0x0index588, std::array<u64,3>{v_c28, v_c3, v_c2}, [&](const std::array<u64,3>& m642) {
          slog::join_probe<2,2>(eval_ansindex589, std::array<u64,2>{v_c29, v_c15}, [&](const std::array<u64,2>& m643) {
            slog::join_probe_old<2,2>(evalindex590, evaldelta601, std::array<u64,2>{v_c26, v_c2}, [&](const std::array<u64,2>& m644) {
              slog::join_probe_old<2,2>(evalindex591, evaldelta602, std::array<u64,2>{v_c29, v_c3}, [&](const std::array<u64,2>& m645) {
                if (!slog::exists_probe<3,2>(lambdaindex592, std::array<u64,3>{v_c17, v_c16, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex593, std::array<u64,2>{v_c26, 0})) return;
                if (!slog::exists_probe<2,1>(evalindex594, std::array<u64,2>{v_c17, 0})) return;
                slog::join_probe<3,2>(appindex595, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m646) {
                  u64 v_c30 = m646[2];
                  slog::join_probe_old<2,2>(evalindex596, evaldelta603, std::array<u64,2>{v_c28, v_c30}, [&](const std::array<u64,2>& m647) {
                    slog::join_probe<3,2>(lambdaindex597, std::array<u64,3>{v_c17, v_c16, 0}, [&](const std::array<u64,3>& m648) {
                      u64 v_c27 = m648[2];
                      slog::join_probe<2,2>(eval_ansindex598, std::array<u64,2>{v_c26, v_c27}, [&](const std::array<u64,2>& m649) {
                        slog::join_probe_old<2,1>(evalindex599, evaldelta604, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m650) {
                          u64 v_c31 = m650[1];
                          slog::join_probe<2,1>(eval_ansindex600, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m651) {
                            u64 v_c18 = m651[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c18}, std::array<u16,2>{0, 1});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:$sup7183x46x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask605* _cont = new ReadTask605(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask605(db,b), false);
  // (crule (pre (let __trid3zj453 const907792eebecaaeea2ef28196) (let __trel0ZVN54 const4a59dbb9cb3129dfcc75170b) (let __tcol9VVb55 const5feceb66ffc86f38d952786c)) (scan $sup7183x51x0x0x0 ea ef) (body) (head (tycheck ef (accept (struct app) (struct lambda) (struct ref)) __trid3zj453 __trel0ZVN54 __tcol9VVb55 (1 2 3 4 0)) (mkstruct eval (1 0) __8ZBN52 ef)) 0cfa-counting.slog:52 #f)
  class ReadTask655 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid652;  u32 sid653;  u32 sid654;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup7183x51x0x0x0");
      sid652 = db->getRelation("app")->getStructId();
      sid653 = db->getRelation("lambda")->getStructId();
      sid654 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask655(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_const907792eebecaaeea2ef28196;
      u64 v_c40 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        u64 v_c2 = _t[1];
        ++_fires;
        if (!((is_struct(v_c2) && (decode_struct_id(v_c2) == sid652 || decode_struct_id(v_c2) == sid653 || decode_struct_id(v_c2) == sid654))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c39, v_c40, v_c41, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:52", "delta:$sup7183x51x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask655* _cont = new ReadTask655(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask655(db,b), false);
  // (crule (pre) (scan eval __t4ga134 eb) (body (exists lambda (2 1 0) 1 eb) (exists $sup7183x46x0x0x1 (4 7 1 0 2 3 5 6) 1 eb) (join eval_ans (0 1) 1 __t4ga134 v) (join lambda (2 1 0) 1 eb x __t6lKC32) (exists $sup7183x46x0x0x1 (4 7 1 0 2 3 5 6) 2 eb x) (join eval_ans (1 0) 1 __t6lKC32 __t84W231) (join $sup7183x46x0x0x1 (4 7 1 0 2 3 5 6) 3 eb x __t84W231 __t3I5X30 __t1bAv33 ea ef va) (join $sup7183x46x0x0x0 (0 1 2) 3 __t3I5X30 ea ef) (join eval_ans (0 1) 2 __t1bAv33 va) (join eval (0 1) 2 __t84W231 ef) (join eval (0 1) 2 __t1bAv33 ea) (join app (1 2 0) 2 ef ea __t1ou629) (join eval (0 1) 2 __t3I5X30 __t1ou629)) (head (emit eval_ans (0 1) __t3I5X30 v)) 0cfa-counting.slog:47 #f)
  class ReadTask669 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex656;  slog::Index** $sup7183x46x0x0x1index657;  slog::Index** eval_ansindex658;  slog::Index** lambdaindex659;  slog::Index** $sup7183x46x0x0x1index660;  slog::Index** eval_ansindex661;  slog::Index** $sup7183x46x0x0x1index662;  slog::Index** $sup7183x46x0x0x0index663;  slog::Index** eval_ansindex664;  slog::Index** evalindex665;  slog::Index** evalindex666;  slog::Index** appindex667;  slog::Index** evalindex668;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord670({0, 1});
      slog::Relation* readrel671 = db->getRelation("eval_ans");
      head_index[0] = readrel671->getIndex(ord670, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord672({2, 1, 0});
      slog::Relation* readrel673 = db->getRelation("lambda");
      lambdaindex656 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel675 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index657 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({0, 1});
      slog::Relation* readrel677 = db->getRelation("eval_ans");
      eval_ansindex658 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({2, 1, 0});
      slog::Relation* readrel679 = db->getRelation("lambda");
      lambdaindex659 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel681 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index660 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 0});
      slog::Relation* readrel683 = db->getRelation("eval_ans");
      eval_ansindex661 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel685 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index662 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({0, 1, 2});
      slog::Relation* readrel687 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index663 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1});
      slog::Relation* readrel689 = db->getRelation("eval_ans");
      eval_ansindex664 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({0, 1});
      slog::Relation* readrel691 = db->getRelation("eval");
      evalindex665 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({0, 1});
      slog::Relation* readrel693 = db->getRelation("eval");
      evalindex666 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 2, 0});
      slog::Relation* readrel695 = db->getRelation("app");
      appindex667 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({0, 1});
      slog::Relation* readrel697 = db->getRelation("eval");
      evalindex668 = readrel697->getIndex(ord696, false);
  
    }
    ReadTask669(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        if (!slog::exists_probe<3,1>(lambdaindex656, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<8,1>($sup7183x46x0x0x1index657, std::array<u64,8>{v_c17, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex658, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m698) {
          u64 v_c18 = m698[1];
          slog::join_probe<3,1>(lambdaindex659, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m699) {
            u64 v_c16 = m699[1]; u64 v_c27 = m699[2];
            if (!slog::exists_probe<8,2>($sup7183x46x0x0x1index660, std::array<u64,8>{v_c17, v_c16, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<2,1>(eval_ansindex661, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m700) {
              u64 v_c26 = m700[1];
              slog::join_probe<8,3>($sup7183x46x0x0x1index662, std::array<u64,8>{v_c17, v_c16, v_c26, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m701) {
                u64 v_c28 = m701[3]; u64 v_c29 = m701[4]; u64 v_c3 = m701[5]; u64 v_c2 = m701[6]; u64 v_c15 = m701[7];
                slog::join_probe<3,3>($sup7183x46x0x0x0index663, std::array<u64,3>{v_c28, v_c3, v_c2}, [&](const std::array<u64,3>& m702) {
                  slog::join_probe<2,2>(eval_ansindex664, std::array<u64,2>{v_c29, v_c15}, [&](const std::array<u64,2>& m703) {
                    slog::join_probe<2,2>(evalindex665, std::array<u64,2>{v_c26, v_c2}, [&](const std::array<u64,2>& m704) {
                      slog::join_probe<2,2>(evalindex666, std::array<u64,2>{v_c29, v_c3}, [&](const std::array<u64,2>& m705) {
                        slog::join_probe<3,2>(appindex667, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m706) {
                          u64 v_c30 = m706[2];
                          slog::join_probe<2,2>(evalindex668, std::array<u64,2>{v_c28, v_c30}, [&](const std::array<u64,2>& m707) {
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c18}, std::array<u16,2>{0, 1});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask669* _cont = new ReadTask669(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask669(db,b), false);
  // (crule (pre) (scan $sup7183x46x0x0x0 __d0 ea ef) (body (exists eval (1 0) 1 ea) (join-old eval (1 0) 1 (1 0) ef __t2C9Q48) (join-old eval_ans (0 1) 1 (0 1) __t2C9Q48 __t9RnS49) (join-old eval (1 0) 1 (1 0) ea __t0jk050) (join-old eval_ans (0 1) 1 (0 1) __t0jk050 va) (join lambda (0 1 2) 1 __t9RnS49 x eb)) (head (emit $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2C9Q48 __t0jk050 eb va x)) 0cfa-counting.slog:47 #f)
  class ReadTask718 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex708;  slog::Index** evalindex709;  slog::Index** eval_ansindex710;  slog::Index** evalindex711;  slog::Index** eval_ansindex712;  slog::Index** lambdaindex713;  slog::Index** evaldelta714;  slog::Index** eval_ansdelta715;  slog::Index** evaldelta716;  slog::Index** eval_ansdelta717;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup7183x46x0x0x1");
      std::vector<u16> ord719({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel720 = db->getRelation("$sup7183x46x0x0x1");
      head_index[0] = readrel720->getIndex(ord719, false);
      outer_rel = db->getRelation("$sup7183x46x0x0x0");
      std::vector<u16> ord721({1, 0});
      slog::Relation* readrel722 = db->getRelation("eval");
      evalindex708 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({1, 0});
      slog::Relation* readrel724 = db->getRelation("eval");
      evalindex709 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({1, 0});
      slog::Relation* readrel726 = db->getRelation("eval");
      evaldelta714 = readrel726->getIndex(ord725, true);
      std::vector<u16> ord727({0, 1});
      slog::Relation* readrel728 = db->getRelation("eval_ans");
      eval_ansindex710 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({0, 1});
      slog::Relation* readrel730 = db->getRelation("eval_ans");
      eval_ansdelta715 = readrel730->getIndex(ord729, true);
      std::vector<u16> ord731({1, 0});
      slog::Relation* readrel732 = db->getRelation("eval");
      evalindex711 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({1, 0});
      slog::Relation* readrel734 = db->getRelation("eval");
      evaldelta716 = readrel734->getIndex(ord733, true);
      std::vector<u16> ord735({0, 1});
      slog::Relation* readrel736 = db->getRelation("eval_ans");
      eval_ansindex712 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({0, 1});
      slog::Relation* readrel738 = db->getRelation("eval_ans");
      eval_ansdelta717 = readrel738->getIndex(ord737, true);
      std::vector<u16> ord739({0, 1, 2});
      slog::Relation* readrel740 = db->getRelation("lambda");
      lambdaindex713 = readrel740->getIndex(ord739, false);
  
    }
    ReadTask718(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(evalindex708, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe_old<2,1>(evalindex709, evaldelta714, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m741) {
          u64 v_c12 = m741[1];
          slog::join_probe_old<2,1>(eval_ansindex710, eval_ansdelta715, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m742) {
            u64 v_c13 = m742[1];
            slog::join_probe_old<2,1>(evalindex711, evaldelta716, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m743) {
              u64 v_c14 = m743[1];
              slog::join_probe_old<2,1>(eval_ansindex712, eval_ansdelta717, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m744) {
                u64 v_c15 = m744[1];
                slog::join_probe<3,1>(lambdaindex713, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m745) {
                  u64 v_c16 = m745[1]; u64 v_c17 = m745[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c11, v_c3, v_c2, v_c12, v_c14, v_c17, v_c15, v_c16}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:$sup7183x46x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask718* _cont = new ReadTask718(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask718(db,b), false);
  // (crule (pre) (scan eval __t9l7D28 ea) (body (exists $sup7183x51x0x0x0 (0 1) 1 ea) (exists app (2 0 1) 1 ea) (join eval_ans (0 1) 1 __t9l7D28 va) (join $sup7183x51x0x0x0 (0 1) 1 ea ef) (exists eval (1 0) 1 ef) (join app (1 2 0) 2 ef ea __t2z5k25) (join eval (1 0) 1 __t2z5k25 __3RTs64) (join eval (1 0) 1 ef __t4JRN26) (join eval_ans (0 1) 1 __t4JRN26 __t7eB027) (join lambda (0 1 2) 1 __t7eB027 x eb)) (head (emit store (0 1) x va)) 0cfa-counting.slog:52 #f)
  class ReadTask756 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x51x0x0x0index746;  slog::Index** appindex747;  slog::Index** eval_ansindex748;  slog::Index** $sup7183x51x0x0x0index749;  slog::Index** evalindex750;  slog::Index** appindex751;  slog::Index** evalindex752;  slog::Index** evalindex753;  slog::Index** eval_ansindex754;  slog::Index** lambdaindex755;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord757({0, 1});
      slog::Relation* readrel758 = db->getRelation("store");
      head_index[0] = readrel758->getIndex(ord757, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord759({0, 1});
      slog::Relation* readrel760 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0index746 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({2, 0, 1});
      slog::Relation* readrel762 = db->getRelation("app");
      appindex747 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({0, 1});
      slog::Relation* readrel764 = db->getRelation("eval_ans");
      eval_ansindex748 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({0, 1});
      slog::Relation* readrel766 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0index749 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 0});
      slog::Relation* readrel768 = db->getRelation("eval");
      evalindex750 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 2, 0});
      slog::Relation* readrel770 = db->getRelation("app");
      appindex751 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({1, 0});
      slog::Relation* readrel772 = db->getRelation("eval");
      evalindex752 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 0});
      slog::Relation* readrel774 = db->getRelation("eval");
      evalindex753 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({0, 1});
      slog::Relation* readrel776 = db->getRelation("eval_ans");
      eval_ansindex754 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({0, 1, 2});
      slog::Relation* readrel778 = db->getRelation("lambda");
      lambdaindex755 = readrel778->getIndex(ord777, false);
  
    }
    ReadTask756(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<2,1>($sup7183x51x0x0x0index746, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(appindex747, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex748, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m779) {
          u64 v_c15 = m779[1];
          slog::join_probe<2,1>($sup7183x51x0x0x0index749, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m780) {
            u64 v_c2 = m780[1];
            if (!slog::exists_probe<2,1>(evalindex750, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<3,2>(appindex751, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m781) {
              u64 v_c23 = m781[2];
              slog::join_probe<2,1>(evalindex752, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m782) {
                u64 v_c24 = m782[1];
                slog::join_probe<2,1>(evalindex753, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m783) {
                  u64 v_c21 = m783[1];
                  slog::join_probe<2,1>(eval_ansindex754, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m784) {
                    u64 v_c22 = m784[1];
                    slog::join_probe<3,1>(lambdaindex755, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m785) {
                      u64 v_c16 = m785[1]; u64 v_c17 = m785[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c15}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:52", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask756* _cont = new ReadTask756(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask756(db,b), false);
  // (crule (pre) (scan program e) (body) (head (mkstruct eval (1 0) __5RNH51 e)) 0cfa-counting.slog:54 #f)
  class ReadTask786 : public slog::Task
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
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("program");
  
    }
    ReadTask786(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:54", "all:program", _fires);
  
      if (!_done)
      {
        ReadTask786* _cont = new ReadTask786(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask786(db,b), true);
  // (crule (pre) (scan eval __t2C9Q48 ef) (body (exists $sup7183x46x0x0x0 (2 0 1) 1 ef) (join eval_ans (0 1) 1 __t2C9Q48 __t9RnS49) (join $sup7183x46x0x0x0 (2 0 1) 1 ef __d0 ea) (join-old eval (1 0) 1 (1 0) ea __t0jk050) (join eval_ans (0 1) 1 __t0jk050 va) (join lambda (0 1 2) 1 __t9RnS49 x eb)) (head (emit $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2C9Q48 __t0jk050 eb va x)) 0cfa-counting.slog:47 #f)
  class ReadTask794 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x46x0x0x0index787;  slog::Index** eval_ansindex788;  slog::Index** $sup7183x46x0x0x0index789;  slog::Index** evalindex790;  slog::Index** eval_ansindex791;  slog::Index** lambdaindex792;  slog::Index** evaldelta793;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup7183x46x0x0x1");
      std::vector<u16> ord795({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel796 = db->getRelation("$sup7183x46x0x0x1");
      head_index[0] = readrel796->getIndex(ord795, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord797({2, 0, 1});
      slog::Relation* readrel798 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index787 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({0, 1});
      slog::Relation* readrel800 = db->getRelation("eval_ans");
      eval_ansindex788 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({2, 0, 1});
      slog::Relation* readrel802 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index789 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({1, 0});
      slog::Relation* readrel804 = db->getRelation("eval");
      evalindex790 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({1, 0});
      slog::Relation* readrel806 = db->getRelation("eval");
      evaldelta793 = readrel806->getIndex(ord805, true);
      std::vector<u16> ord807({0, 1});
      slog::Relation* readrel808 = db->getRelation("eval_ans");
      eval_ansindex791 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({0, 1, 2});
      slog::Relation* readrel810 = db->getRelation("lambda");
      lambdaindex792 = readrel810->getIndex(ord809, false);
  
    }
    ReadTask794(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[0];
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<3,1>($sup7183x46x0x0x0index787, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex788, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m811) {
          u64 v_c13 = m811[1];
          slog::join_probe<3,1>($sup7183x46x0x0x0index789, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m812) {
            u64 v_c11 = m812[1]; u64 v_c3 = m812[2];
            slog::join_probe_old<2,1>(evalindex790, evaldelta793, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m813) {
              u64 v_c14 = m813[1];
              slog::join_probe<2,1>(eval_ansindex791, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m814) {
                u64 v_c15 = m814[1];
                slog::join_probe<3,1>(lambdaindex792, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m815) {
                  u64 v_c16 = m815[1]; u64 v_c17 = m815[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c11, v_c3, v_c2, v_c12, v_c14, v_c17, v_c15, v_c16}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask794* _cont = new ReadTask794(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask794(db,b), false);
  // (crule (pre) (scan eval __t4JRN26 ef) (body (exists $sup7183x51x0x0x0 (1 0) 1 ef) (exists app (1 2 0) 1 ef) (join eval_ans (0 1) 1 __t4JRN26 __t7eB027) (join $sup7183x51x0x0x0 (1 0) 1 ef ea) (exists eval (1 0) 1 ea) (join app (1 2 0) 2 ef ea __t2z5k25) (join eval (1 0) 1 __t2z5k25 __3RTs64) (join-old eval (1 0) 1 (1 0) ea __t9l7D28) (join eval_ans (0 1) 1 __t9l7D28 va) (join lambda (0 1 2) 1 __t7eB027 x eb)) (head (emit store (0 1) x va)) 0cfa-counting.slog:52 #f)
  class ReadTask827 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x51x0x0x0index816;  slog::Index** appindex817;  slog::Index** eval_ansindex818;  slog::Index** $sup7183x51x0x0x0index819;  slog::Index** evalindex820;  slog::Index** appindex821;  slog::Index** evalindex822;  slog::Index** evalindex823;  slog::Index** eval_ansindex824;  slog::Index** lambdaindex825;  slog::Index** evaldelta826;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord828({0, 1});
      slog::Relation* readrel829 = db->getRelation("store");
      head_index[0] = readrel829->getIndex(ord828, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord830({1, 0});
      slog::Relation* readrel831 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0index816 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 0});
      slog::Relation* readrel833 = db->getRelation("app");
      appindex817 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({0, 1});
      slog::Relation* readrel835 = db->getRelation("eval_ans");
      eval_ansindex818 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({1, 0});
      slog::Relation* readrel837 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0index819 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 0});
      slog::Relation* readrel839 = db->getRelation("eval");
      evalindex820 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({1, 2, 0});
      slog::Relation* readrel841 = db->getRelation("app");
      appindex821 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 0});
      slog::Relation* readrel843 = db->getRelation("eval");
      evalindex822 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({1, 0});
      slog::Relation* readrel845 = db->getRelation("eval");
      evalindex823 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 0});
      slog::Relation* readrel847 = db->getRelation("eval");
      evaldelta826 = readrel847->getIndex(ord846, true);
      std::vector<u16> ord848({0, 1});
      slog::Relation* readrel849 = db->getRelation("eval_ans");
      eval_ansindex824 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({0, 1, 2});
      slog::Relation* readrel851 = db->getRelation("lambda");
      lambdaindex825 = readrel851->getIndex(ord850, false);
  
    }
    ReadTask827(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<2,1>($sup7183x51x0x0x0index816, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,1>(appindex817, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex818, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m852) {
          u64 v_c22 = m852[1];
          slog::join_probe<2,1>($sup7183x51x0x0x0index819, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m853) {
            u64 v_c3 = m853[1];
            if (!slog::exists_probe<2,1>(evalindex820, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe<3,2>(appindex821, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m854) {
              u64 v_c23 = m854[2];
              slog::join_probe<2,1>(evalindex822, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m855) {
                u64 v_c24 = m855[1];
                slog::join_probe_old<2,1>(evalindex823, evaldelta826, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m856) {
                  u64 v_c25 = m856[1];
                  slog::join_probe<2,1>(eval_ansindex824, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m857) {
                    u64 v_c15 = m857[1];
                    slog::join_probe<3,1>(lambdaindex825, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m858) {
                      u64 v_c16 = m858[1]; u64 v_c17 = m858[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c15}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:52", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask827* _cont = new ReadTask827(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask827(db,b), false);
  // (crule (pre (let __trid3tW358 const4716e54ebb7b93a657325b50) (let __trel08yY59 const4a59dbb9cb3129dfcc75170b) (let __tcol8EW760 const5feceb66ffc86f38d952786c)) (scan $sup7183x46x0x0x1 __d0 __d1 __d2 ea eb ef va x) (body) (head (tycheck eb (accept (struct app) (struct lambda) (struct ref)) __trid3tW358 __trel08yY59 __tcol8EW760 (1 2 3 4 0)) (mkstruct eval (1 0) __6jGQ57 eb)) 0cfa-counting.slog:47 #f)
  class ReadTask862 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid859;  u32 sid860;  u32 sid861;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup7183x46x0x0x1");
      sid859 = db->getRelation("app")->getStructId();
      sid860 = db->getRelation("lambda")->getStructId();
      sid861 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask862(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_const4716e54ebb7b93a657325b50;
      u64 v_c43 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c44 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c46 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c17 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c15 = _t[6];
        u64 v_c16 = _t[7];
        ++_fires;
        if (!((is_struct(v_c17) && (decode_struct_id(v_c17) == sid859 || decode_struct_id(v_c17) == sid860 || decode_struct_id(v_c17) == sid861))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c42, v_c43, v_c44, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:$sup7183x46x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask862* _cont = new ReadTask862(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask862(db,b), false);
  // (crule (pre) (scan eval __3RTs64 __t2z5k25) (body (join app (0 1 2) 1 __t2z5k25 ef ea) (join-old $sup7183x51x0x0x0 (0 1) 2 (0 1) ea ef) (exists eval (1 0) 1 ea) (join-old eval (1 0) 1 (1 0) ef __t4JRN26) (join-old eval_ans (0 1) 1 (0 1) __t4JRN26 __t7eB027) (join-old eval (1 0) 1 (1 0) ea __t9l7D28) (join-old eval_ans (0 1) 1 (0 1) __t9l7D28 va) (join lambda (0 1 2) 1 __t7eB027 x eb)) (head (emit store (0 1) x va)) 0cfa-counting.slog:52 #f)
  class ReadTask876 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex863;  slog::Index** $sup7183x51x0x0x0index864;  slog::Index** evalindex865;  slog::Index** evalindex866;  slog::Index** eval_ansindex867;  slog::Index** evalindex868;  slog::Index** eval_ansindex869;  slog::Index** lambdaindex870;  slog::Index** $sup7183x51x0x0x0delta871;  slog::Index** evaldelta872;  slog::Index** eval_ansdelta873;  slog::Index** evaldelta874;  slog::Index** eval_ansdelta875;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord877({0, 1});
      slog::Relation* readrel878 = db->getRelation("store");
      head_index[0] = readrel878->getIndex(ord877, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord879({0, 1, 2});
      slog::Relation* readrel880 = db->getRelation("app");
      appindex863 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({0, 1});
      slog::Relation* readrel882 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0index864 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({0, 1});
      slog::Relation* readrel884 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0delta871 = readrel884->getIndex(ord883, true);
      std::vector<u16> ord885({1, 0});
      slog::Relation* readrel886 = db->getRelation("eval");
      evalindex865 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 0});
      slog::Relation* readrel888 = db->getRelation("eval");
      evalindex866 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 0});
      slog::Relation* readrel890 = db->getRelation("eval");
      evaldelta872 = readrel890->getIndex(ord889, true);
      std::vector<u16> ord891({0, 1});
      slog::Relation* readrel892 = db->getRelation("eval_ans");
      eval_ansindex867 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({0, 1});
      slog::Relation* readrel894 = db->getRelation("eval_ans");
      eval_ansdelta873 = readrel894->getIndex(ord893, true);
      std::vector<u16> ord895({1, 0});
      slog::Relation* readrel896 = db->getRelation("eval");
      evalindex868 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({1, 0});
      slog::Relation* readrel898 = db->getRelation("eval");
      evaldelta874 = readrel898->getIndex(ord897, true);
      std::vector<u16> ord899({0, 1});
      slog::Relation* readrel900 = db->getRelation("eval_ans");
      eval_ansindex869 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({0, 1});
      slog::Relation* readrel902 = db->getRelation("eval_ans");
      eval_ansdelta875 = readrel902->getIndex(ord901, true);
      std::vector<u16> ord903({0, 1, 2});
      slog::Relation* readrel904 = db->getRelation("lambda");
      lambdaindex870 = readrel904->getIndex(ord903, false);
  
    }
    ReadTask876(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<3,1>(appindex863, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m905) {
          u64 v_c2 = m905[1]; u64 v_c3 = m905[2];
          slog::join_probe_old<2,2>($sup7183x51x0x0x0index864, $sup7183x51x0x0x0delta871, std::array<u64,2>{v_c3, v_c2}, [&](const std::array<u64,2>& m906) {
            if (!slog::exists_probe<2,1>(evalindex865, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe_old<2,1>(evalindex866, evaldelta872, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m907) {
              u64 v_c21 = m907[1];
              slog::join_probe_old<2,1>(eval_ansindex867, eval_ansdelta873, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m908) {
                u64 v_c22 = m908[1];
                slog::join_probe_old<2,1>(evalindex868, evaldelta874, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m909) {
                  u64 v_c25 = m909[1];
                  slog::join_probe_old<2,1>(eval_ansindex869, eval_ansdelta875, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m910) {
                    u64 v_c15 = m910[1];
                    slog::join_probe<3,1>(lambdaindex870, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m911) {
                      u64 v_c16 = m911[1]; u64 v_c17 = m911[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c15}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:52", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask876* _cont = new ReadTask876(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask876(db,b), false);
  // (crule (pre (let __trid6fnZ67 const4716e54ebb7b93a657325b50) (let __trel9MNn68 const4a59dbb9cb3129dfcc75170b) (let __tcol9fBk69 const5feceb66ffc86f38d952786c)) (scan $sup7183x46x0x0x0 __d0 ea ef) (body) (head (tycheck ea (accept (struct app) (struct lambda) (struct ref)) __trid6fnZ67 __trel9MNn68 __tcol9fBk69 (1 2 3 4 0)) (mkstruct eval (1 0) __9oNa66 ea)) 0cfa-counting.slog:47 #f)
  class ReadTask915 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid912;  u32 sid913;  u32 sid914;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup7183x46x0x0x0");
      sid912 = db->getRelation("app")->getStructId();
      sid913 = db->getRelation("lambda")->getStructId();
      sid914 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask915(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_const4716e54ebb7b93a657325b50;
      u64 v_c48 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid912 || decode_struct_id(v_c3) == sid913 || decode_struct_id(v_c3) == sid914))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c47, v_c48, v_c49, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:$sup7183x46x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask915* _cont = new ReadTask915(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask915(db,b), false);
  // (crule (pre) (scan eval_ans __t84W231 __t6lKC32) (body (exists $sup7183x46x0x0x1 (1 5 0 2 3 4 6 7) 1 __t84W231) (join-old eval (0 1) 1 (0 1) __t84W231 ef) (exists $sup7183x46x0x0x1 (1 5 0 2 3 4 6 7) 2 __t84W231 ef) (exists app (1 2 0) 1 ef) (join-old $sup7183x46x0x0x0 (2 0 1) 1 (2 0 1) ef __t3I5X30 ea) (exists eval (1 0) 1 ea) (exists app (1 2 0) 2 ef ea) (join-old $sup7183x46x0x0x1 (0 3 5 1 2 4 6 7) 4 (0 3 5 1 2 4 6 7) __t3I5X30 ea ef __t84W231 __t1bAv33 eb va x) (join lambda (2 1 0) 3 eb x __t6lKC32) (join-old eval_ans (0 1) 2 (0 1) __t1bAv33 va) (join-old eval (0 1) 2 (0 1) __t1bAv33 ea) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t1ou629) (join-old eval (0 1) 2 (0 1) __t3I5X30 __t1ou629) (join-old eval (1 0) 1 (1 0) eb __t4ga134) (join-old eval_ans (0 1) 1 (0 1) __t4ga134 v)) (head (emit eval_ans (0 1) __t3I5X30 v)) 0cfa-counting.slog:47 #f)
  class ReadTask940 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup7183x46x0x0x1index916;  slog::Index** evalindex917;  slog::Index** $sup7183x46x0x0x1index918;  slog::Index** appindex919;  slog::Index** $sup7183x46x0x0x0index920;  slog::Index** evalindex921;  slog::Index** appindex922;  slog::Index** $sup7183x46x0x0x1index923;  slog::Index** lambdaindex924;  slog::Index** eval_ansindex925;  slog::Index** evalindex926;  slog::Index** evalindex927;  slog::Index** appindex928;  slog::Index** evalindex929;  slog::Index** evalindex930;  slog::Index** eval_ansindex931;  slog::Index** evaldelta932;  slog::Index** $sup7183x46x0x0x0delta933;  slog::Index** $sup7183x46x0x0x1delta934;  slog::Index** eval_ansdelta935;  slog::Index** evaldelta936;  slog::Index** evaldelta937;  slog::Index** evaldelta938;  slog::Index** eval_ansdelta939;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord941({0, 1});
      slog::Relation* readrel942 = db->getRelation("eval_ans");
      head_index[0] = readrel942->getIndex(ord941, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord943({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel944 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index916 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({0, 1});
      slog::Relation* readrel946 = db->getRelation("eval");
      evalindex917 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({0, 1});
      slog::Relation* readrel948 = db->getRelation("eval");
      evaldelta932 = readrel948->getIndex(ord947, true);
      std::vector<u16> ord949({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel950 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index918 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({1, 2, 0});
      slog::Relation* readrel952 = db->getRelation("app");
      appindex919 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({2, 0, 1});
      slog::Relation* readrel954 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index920 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({2, 0, 1});
      slog::Relation* readrel956 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0delta933 = readrel956->getIndex(ord955, true);
      std::vector<u16> ord957({1, 0});
      slog::Relation* readrel958 = db->getRelation("eval");
      evalindex921 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({1, 2, 0});
      slog::Relation* readrel960 = db->getRelation("app");
      appindex922 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel962 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index923 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel964 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1delta934 = readrel964->getIndex(ord963, true);
      std::vector<u16> ord965({2, 1, 0});
      slog::Relation* readrel966 = db->getRelation("lambda");
      lambdaindex924 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({0, 1});
      slog::Relation* readrel968 = db->getRelation("eval_ans");
      eval_ansindex925 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({0, 1});
      slog::Relation* readrel970 = db->getRelation("eval_ans");
      eval_ansdelta935 = readrel970->getIndex(ord969, true);
      std::vector<u16> ord971({0, 1});
      slog::Relation* readrel972 = db->getRelation("eval");
      evalindex926 = readrel972->getIndex(ord971, false);
      std::vector<u16> ord973({0, 1});
      slog::Relation* readrel974 = db->getRelation("eval");
      evaldelta936 = readrel974->getIndex(ord973, true);
      std::vector<u16> ord975({1, 0});
      slog::Relation* readrel976 = db->getRelation("eval");
      evalindex927 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({1, 2, 0});
      slog::Relation* readrel978 = db->getRelation("app");
      appindex928 = readrel978->getIndex(ord977, false);
      std::vector<u16> ord979({0, 1});
      slog::Relation* readrel980 = db->getRelation("eval");
      evalindex929 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({0, 1});
      slog::Relation* readrel982 = db->getRelation("eval");
      evaldelta937 = readrel982->getIndex(ord981, true);
      std::vector<u16> ord983({1, 0});
      slog::Relation* readrel984 = db->getRelation("eval");
      evalindex930 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({1, 0});
      slog::Relation* readrel986 = db->getRelation("eval");
      evaldelta938 = readrel986->getIndex(ord985, true);
      std::vector<u16> ord987({0, 1});
      slog::Relation* readrel988 = db->getRelation("eval_ans");
      eval_ansindex931 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({0, 1});
      slog::Relation* readrel990 = db->getRelation("eval_ans");
      eval_ansdelta939 = readrel990->getIndex(ord989, true);
  
    }
    ReadTask940(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<8,1>($sup7183x46x0x0x1index916, std::array<u64,8>{v_c26, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(evalindex917, evaldelta932, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m991) {
          u64 v_c2 = m991[1];
          if (!slog::exists_probe<8,2>($sup7183x46x0x0x1index918, std::array<u64,8>{v_c26, v_c2, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex919, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<3,1>($sup7183x46x0x0x0index920, $sup7183x46x0x0x0delta933, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m992) {
            u64 v_c28 = m992[1]; u64 v_c3 = m992[2];
            if (!slog::exists_probe<2,1>(evalindex921, std::array<u64,2>{v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(appindex922, std::array<u64,3>{v_c2, v_c3, 0})) return;
            slog::join_probe_old<8,4>($sup7183x46x0x0x1index923, $sup7183x46x0x0x1delta934, std::array<u64,8>{v_c28, v_c3, v_c2, v_c26, 0, 0, 0, 0}, [&](const std::array<u64,8>& m993) {
              u64 v_c29 = m993[4]; u64 v_c17 = m993[5]; u64 v_c15 = m993[6]; u64 v_c16 = m993[7];
              slog::join_probe<3,3>(lambdaindex924, std::array<u64,3>{v_c17, v_c16, v_c27}, [&](const std::array<u64,3>& m994) {
                slog::join_probe_old<2,2>(eval_ansindex925, eval_ansdelta935, std::array<u64,2>{v_c29, v_c15}, [&](const std::array<u64,2>& m995) {
                  slog::join_probe_old<2,2>(evalindex926, evaldelta936, std::array<u64,2>{v_c29, v_c3}, [&](const std::array<u64,2>& m996) {
                    if (!slog::exists_probe<2,1>(evalindex927, std::array<u64,2>{v_c17, 0})) return;
                    slog::join_probe<3,2>(appindex928, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m997) {
                      u64 v_c30 = m997[2];
                      slog::join_probe_old<2,2>(evalindex929, evaldelta937, std::array<u64,2>{v_c28, v_c30}, [&](const std::array<u64,2>& m998) {
                        slog::join_probe_old<2,1>(evalindex930, evaldelta938, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m999) {
                          u64 v_c31 = m999[1];
                          slog::join_probe_old<2,1>(eval_ansindex931, eval_ansdelta939, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1000) {
                            u64 v_c18 = m1000[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c18}, std::array<u16,2>{0, 1});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask940* _cont = new ReadTask940(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask940(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre4ymS83 __errf06Tu84 __errf0hmZ85 __errf4Evo86 __errf3gLo87) (body) (head (emit error (0) __erre4ymS83)) <internal>:1 #f)
  class ReadTask1001 : public slog::Task
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
      std::vector<u16> ord1002({0});
      slog::Relation* readrel1003 = db->getRelation("error");
      head_index[0] = readrel1003->getIndex(ord1002, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask1001(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c50 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c52 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c54 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c50}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask1001* _cont = new ReadTask1001(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1001(db,b), false);
  // (crule (pre) (scan eval_ans __t4ga134 v) (body (join-old eval (0 1) 1 (0 1) __t4ga134 eb) (exists $sup7183x46x0x0x1 (4 7 1 0 2 3 5 6) 1 eb) (join lambda (2 1 0) 1 eb x __t6lKC32) (exists $sup7183x46x0x0x1 (4 7 1 0 2 3 5 6) 2 eb x) (join eval_ans (1 0) 1 __t6lKC32 __t84W231) (join-old $sup7183x46x0x0x1 (4 7 1 0 2 3 5 6) 3 (4 7 1 0 2 3 5 6) eb x __t84W231 __t3I5X30 __t1bAv33 ea ef va) (join-old $sup7183x46x0x0x0 (0 1 2) 3 (0 1 2) __t3I5X30 ea ef) (join eval_ans (0 1) 2 __t1bAv33 va) (join-old eval (0 1) 2 (0 1) __t84W231 ef) (join-old eval (0 1) 2 (0 1) __t1bAv33 ea) (join app (1 2 0) 2 ef ea __t1ou629) (join-old eval (0 1) 2 (0 1) __t3I5X30 __t1ou629)) (head (emit eval_ans (0 1) __t3I5X30 v)) 0cfa-counting.slog:47 #f)
  class ReadTask1022 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1004;  slog::Index** $sup7183x46x0x0x1index1005;  slog::Index** lambdaindex1006;  slog::Index** $sup7183x46x0x0x1index1007;  slog::Index** eval_ansindex1008;  slog::Index** $sup7183x46x0x0x1index1009;  slog::Index** $sup7183x46x0x0x0index1010;  slog::Index** eval_ansindex1011;  slog::Index** evalindex1012;  slog::Index** evalindex1013;  slog::Index** appindex1014;  slog::Index** evalindex1015;  slog::Index** evaldelta1016;  slog::Index** $sup7183x46x0x0x1delta1017;  slog::Index** $sup7183x46x0x0x0delta1018;  slog::Index** evaldelta1019;  slog::Index** evaldelta1020;  slog::Index** evaldelta1021;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1023({0, 1});
      slog::Relation* readrel1024 = db->getRelation("eval_ans");
      head_index[0] = readrel1024->getIndex(ord1023, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1025({0, 1});
      slog::Relation* readrel1026 = db->getRelation("eval");
      evalindex1004 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({0, 1});
      slog::Relation* readrel1028 = db->getRelation("eval");
      evaldelta1016 = readrel1028->getIndex(ord1027, true);
      std::vector<u16> ord1029({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel1030 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index1005 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({2, 1, 0});
      slog::Relation* readrel1032 = db->getRelation("lambda");
      lambdaindex1006 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel1034 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index1007 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 0});
      slog::Relation* readrel1036 = db->getRelation("eval_ans");
      eval_ansindex1008 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel1038 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1index1009 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel1040 = db->getRelation("$sup7183x46x0x0x1");
      $sup7183x46x0x0x1delta1017 = readrel1040->getIndex(ord1039, true);
      std::vector<u16> ord1041({0, 1, 2});
      slog::Relation* readrel1042 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0index1010 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({0, 1, 2});
      slog::Relation* readrel1044 = db->getRelation("$sup7183x46x0x0x0");
      $sup7183x46x0x0x0delta1018 = readrel1044->getIndex(ord1043, true);
      std::vector<u16> ord1045({0, 1});
      slog::Relation* readrel1046 = db->getRelation("eval_ans");
      eval_ansindex1011 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({0, 1});
      slog::Relation* readrel1048 = db->getRelation("eval");
      evalindex1012 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({0, 1});
      slog::Relation* readrel1050 = db->getRelation("eval");
      evaldelta1019 = readrel1050->getIndex(ord1049, true);
      std::vector<u16> ord1051({0, 1});
      slog::Relation* readrel1052 = db->getRelation("eval");
      evalindex1013 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({0, 1});
      slog::Relation* readrel1054 = db->getRelation("eval");
      evaldelta1020 = readrel1054->getIndex(ord1053, true);
      std::vector<u16> ord1055({1, 2, 0});
      slog::Relation* readrel1056 = db->getRelation("app");
      appindex1014 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({0, 1});
      slog::Relation* readrel1058 = db->getRelation("eval");
      evalindex1015 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({0, 1});
      slog::Relation* readrel1060 = db->getRelation("eval");
      evaldelta1021 = readrel1060->getIndex(ord1059, true);
  
    }
    ReadTask1022(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[1];
        slog::join_probe_old<2,1>(evalindex1004, evaldelta1016, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1061) {
          u64 v_c17 = m1061[1];
          if (!slog::exists_probe<8,1>($sup7183x46x0x0x1index1005, std::array<u64,8>{v_c17, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<3,1>(lambdaindex1006, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m1062) {
            u64 v_c16 = m1062[1]; u64 v_c27 = m1062[2];
            if (!slog::exists_probe<8,2>($sup7183x46x0x0x1index1007, std::array<u64,8>{v_c17, v_c16, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<2,1>(eval_ansindex1008, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1063) {
              u64 v_c26 = m1063[1];
              slog::join_probe_old<8,3>($sup7183x46x0x0x1index1009, $sup7183x46x0x0x1delta1017, std::array<u64,8>{v_c17, v_c16, v_c26, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m1064) {
                u64 v_c28 = m1064[3]; u64 v_c29 = m1064[4]; u64 v_c3 = m1064[5]; u64 v_c2 = m1064[6]; u64 v_c15 = m1064[7];
                slog::join_probe_old<3,3>($sup7183x46x0x0x0index1010, $sup7183x46x0x0x0delta1018, std::array<u64,3>{v_c28, v_c3, v_c2}, [&](const std::array<u64,3>& m1065) {
                  slog::join_probe<2,2>(eval_ansindex1011, std::array<u64,2>{v_c29, v_c15}, [&](const std::array<u64,2>& m1066) {
                    slog::join_probe_old<2,2>(evalindex1012, evaldelta1019, std::array<u64,2>{v_c26, v_c2}, [&](const std::array<u64,2>& m1067) {
                      slog::join_probe_old<2,2>(evalindex1013, evaldelta1020, std::array<u64,2>{v_c29, v_c3}, [&](const std::array<u64,2>& m1068) {
                        slog::join_probe<3,2>(appindex1014, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m1069) {
                          u64 v_c30 = m1069[2];
                          slog::join_probe_old<2,2>(evalindex1015, evaldelta1021, std::array<u64,2>{v_c28, v_c30}, [&](const std::array<u64,2>& m1070) {
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c18}, std::array<u16,2>{0, 1});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:47", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask1022* _cont = new ReadTask1022(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1022(db,b), false);
  // (crule (pre) (scan eval_ans __t9l7D28 va) (body (join-old eval (0 1) 1 (0 1) __t9l7D28 ea) (exists app (2 0 1) 1 ea) (join-old $sup7183x51x0x0x0 (0 1) 1 (0 1) ea ef) (exists eval (1 0) 1 ef) (join app (1 2 0) 2 ef ea __t2z5k25) (join eval (1 0) 1 __t2z5k25 __3RTs64) (join-old eval (1 0) 1 (1 0) ef __t4JRN26) (join eval_ans (0 1) 1 __t4JRN26 __t7eB027) (join lambda (0 1 2) 1 __t7eB027 x eb)) (head (emit store (0 1) x va)) 0cfa-counting.slog:52 #f)
  class ReadTask1083 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1071;  slog::Index** appindex1072;  slog::Index** $sup7183x51x0x0x0index1073;  slog::Index** evalindex1074;  slog::Index** appindex1075;  slog::Index** evalindex1076;  slog::Index** evalindex1077;  slog::Index** eval_ansindex1078;  slog::Index** lambdaindex1079;  slog::Index** evaldelta1080;  slog::Index** $sup7183x51x0x0x0delta1081;  slog::Index** evaldelta1082;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord1084({0, 1});
      slog::Relation* readrel1085 = db->getRelation("store");
      head_index[0] = readrel1085->getIndex(ord1084, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1086({0, 1});
      slog::Relation* readrel1087 = db->getRelation("eval");
      evalindex1071 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({0, 1});
      slog::Relation* readrel1089 = db->getRelation("eval");
      evaldelta1080 = readrel1089->getIndex(ord1088, true);
      std::vector<u16> ord1090({2, 0, 1});
      slog::Relation* readrel1091 = db->getRelation("app");
      appindex1072 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({0, 1});
      slog::Relation* readrel1093 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0index1073 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({0, 1});
      slog::Relation* readrel1095 = db->getRelation("$sup7183x51x0x0x0");
      $sup7183x51x0x0x0delta1081 = readrel1095->getIndex(ord1094, true);
      std::vector<u16> ord1096({1, 0});
      slog::Relation* readrel1097 = db->getRelation("eval");
      evalindex1074 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({1, 2, 0});
      slog::Relation* readrel1099 = db->getRelation("app");
      appindex1075 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 0});
      slog::Relation* readrel1101 = db->getRelation("eval");
      evalindex1076 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({1, 0});
      slog::Relation* readrel1103 = db->getRelation("eval");
      evalindex1077 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({1, 0});
      slog::Relation* readrel1105 = db->getRelation("eval");
      evaldelta1082 = readrel1105->getIndex(ord1104, true);
      std::vector<u16> ord1106({0, 1});
      slog::Relation* readrel1107 = db->getRelation("eval_ans");
      eval_ansindex1078 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({0, 1, 2});
      slog::Relation* readrel1109 = db->getRelation("lambda");
      lambdaindex1079 = readrel1109->getIndex(ord1108, false);
  
    }
    ReadTask1083(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[0];
        u64 v_c15 = _t[1];
        slog::join_probe_old<2,1>(evalindex1071, evaldelta1080, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1110) {
          u64 v_c3 = m1110[1];
          if (!slog::exists_probe<3,1>(appindex1072, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe_old<2,1>($sup7183x51x0x0x0index1073, $sup7183x51x0x0x0delta1081, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m1111) {
            u64 v_c2 = m1111[1];
            if (!slog::exists_probe<2,1>(evalindex1074, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<3,2>(appindex1075, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m1112) {
              u64 v_c23 = m1112[2];
              slog::join_probe<2,1>(evalindex1076, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m1113) {
                u64 v_c24 = m1113[1];
                slog::join_probe_old<2,1>(evalindex1077, evaldelta1082, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m1114) {
                  u64 v_c21 = m1114[1];
                  slog::join_probe<2,1>(eval_ansindex1078, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m1115) {
                    u64 v_c22 = m1115[1];
                    slog::join_probe<3,1>(lambdaindex1079, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m1116) {
                      u64 v_c16 = m1116[1]; u64 v_c17 = m1116[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c15}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:52", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask1083* _cont = new ReadTask1083(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1083(db,b), false);
  s->addReadRel("$sup7183x46x0x0x0");
  s->addReadRel("$sup7183x46x0x0x1");
  s->addReadRel("$sup7183x51x0x0x0");
  s->addReadRel("app");
  s->addReadRel("eval");
  s->addReadRel("eval_ans");
  s->addReadRel("lambda");
  s->addReadRel("malformed_deduction");
  s->addReadRel("program");
  s->addReadRel("ref");
  s->addReadRel("store");
  s->addDynamicRel("$sup7183x46x0x0x0");
  s->addDynamicRel("$sup7183x46x0x0x1");
  s->addDynamicRel("$sup7183x51x0x0x0");
  s->addDynamicRel("error");
  s->addDynamicRel("eval");
  s->addDynamicRel("eval_ans");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("store");
  s->addAccelRel("eval_ans");
  s->addAccelRel("store");
  d->push(s);
  d->continueRun();
}

