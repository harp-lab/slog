
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const1cd2976e4f4400f31114fe53;
u64 v_constafcf65f310629738af953774;
u64 v_const4a59dbb9cb3129dfcc75170b;
u64 v_const895fb44435658e0cef51ef58;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constc40db22dfb3712d9bcc7a93e;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("35999f2e");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const1cd2976e4f4400f31114fe53 = db->encodeString("0cfa-demand.slog:34");
  v_constafcf65f310629738af953774 = db->encodeString("eval_ans");
  v_const4a59dbb9cb3129dfcc75170b = db->encodeString("eval");
  v_const895fb44435658e0cef51ef58 = db->encodeString("0cfa-demand.slog:20");
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constc40db22dfb3712d9bcc7a93e = db->encodeString("0cfa-demand.slog:26");
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
  r = db->getRelation("result");
  if (r == 0) db->addRelation("result", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("result");
      std::vector<u16> ord1124({0});
    
    r->addIndex<1>(ord1124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("result"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord1125({1, 0});
    
    r->addIndex<2>(ord1125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord1126({0, 1});
    
    r->addIndex<2>(ord1126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("program");
  if (r == 0) db->addRelation("program", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program");
      std::vector<u16> ord1127({0});
    
    r->addIndex<1>(ord1127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord1128({1, 2, 3, 0});
    
    r->addIndex<4>(ord1128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord1129({0, 1, 2, 3});
    
    r->addIndex<4>(ord1129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord1130({1, 2, 0});
    
    r->addIndex<3>(ord1130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1131({0, 1, 2});
    
    r->addIndex<3>(ord1131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord1132({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord1132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord1133({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord1133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord1134({1, 2, 0});
    
    r->addIndex<3>(ord1134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1135({0, 1, 2});
    
    r->addIndex<3>(ord1135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord1136({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord1136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord1137({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord1137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lambda");
  if (r == 0) db->addStruct("lambda", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lambda");
      std::vector<u16> ord1138({2, 1, 0});
    
    r->addIndex<3>(ord1138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord1139({0, 1, 2});
    
    r->addIndex<3>(ord1139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lambda"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord1140({1, 2, 3, 0});
    
    r->addIndex<4>(ord1140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord1141({0, 1, 2, 3});
    
    r->addIndex<4>(ord1141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("eval_ans");
  if (r == 0) db->addRelation("eval_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_ans");
      std::vector<u16> ord1142({0, 1});
    
    r->addIndex<2>(ord1142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord1143({1, 0});
    
    r->addIndex<2>(ord1143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord1144({0, 1});
    
    r->addIndex<2>(ord1144, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("eval");
  if (r == 0) db->addStruct("eval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval");
      std::vector<u16> ord1145({1, 0});
    
    r->addIndex<2>(ord1145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord1146({0, 1});
    
    r->addIndex<2>(ord1146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord1147({0, 1});
    
    r->addIndex<2>(ord1147, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord1148({1, 0});
    
    r->addIndex<2>(ord1148, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("eval"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord1149({0});
    
    r->addIndex<1>(ord1149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord1150({1, 2, 0});
    
    r->addIndex<3>(ord1150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1151({0, 1, 2});
    
    r->addIndex<3>(ord1151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("app");
  if (r == 0) db->addStruct("app", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("app");
      std::vector<u16> ord1152({1, 2, 0});
    
    r->addIndex<3>(ord1152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord1153({0, 1, 2});
    
    r->addIndex<3>(ord1153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord1154({2, 0, 1});
    
    r->addIndex<3>(ord1154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("app"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord1155({1, 0});
    
    r->addIndex<2>(ord1155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord1156({0, 1});
    
    r->addIndex<2>(ord1156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup15869x33x0x0x0");
  if (r == 0) db->addRelation("$sup15869x33x0x0x0", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup15869x33x0x0x0");
      std::vector<u16> ord1157({0, 1});
    
    r->addIndex<2>(ord1157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord1158({1, 0});
    
    r->addIndex<2>(ord1158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord1159({0, 1});
    
    r->addIndex<2>(ord1159, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord1160({1, 0});
    
    r->addIndex<2>(ord1160, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("$sup15869x33x0x0x0"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("$sup15869x25x0x0x1");
  if (r == 0) db->addRelation("$sup15869x25x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup15869x25x0x0x1");
      std::vector<u16> ord1161({0, 3, 5, 1, 2, 4, 6, 7});
    
    r->addIndex<8>(ord1161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7}, false, b), true);
      std::vector<u16> ord1162({1, 5, 0, 2, 3, 4, 6, 7});
    
    r->addIndex<8>(ord1162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7}, false, b), false);
      std::vector<u16> ord1163({2, 3, 6, 0, 1, 4, 5, 7});
    
    r->addIndex<8>(ord1163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{2, 3, 6, 0, 1, 4, 5, 7}, false, b), false);
      std::vector<u16> ord1164({2, 6, 0, 1, 3, 4, 5, 7});
    
    r->addIndex<8>(ord1164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{2, 6, 0, 1, 3, 4, 5, 7}, false, b), false);
      std::vector<u16> ord1165({4, 7, 1, 0, 2, 3, 5, 6});
    
    r->addIndex<8>(ord1165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{4, 7, 1, 0, 2, 3, 5, 6}, false, b), false);
      std::vector<u16> ord1166({0, 3, 5, 1, 2, 4, 6, 7});
    
    r->addIndex<8>(ord1166, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7}, true, b), false);
      std::vector<u16> ord1167({2, 3, 6, 0, 1, 4, 5, 7});
    
    r->addIndex<8>(ord1167, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{2, 3, 6, 0, 1, 4, 5, 7}, true, b), false);
      std::vector<u16> ord1168({4, 7, 1, 0, 2, 3, 5, 6});
    
    r->addIndex<8>(ord1168, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{4, 7, 1, 0, 2, 3, 5, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup15869x25x0x0x1"), std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7}, b));
  r = db->getRelation("$sup15869x25x0x0x0");
  if (r == 0) db->addRelation("$sup15869x25x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup15869x25x0x0x0");
      std::vector<u16> ord1169({0, 1, 2});
    
    r->addIndex<3>(ord1169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord1170({1, 0, 2});
    
    r->addIndex<3>(ord1170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), false);
      std::vector<u16> ord1171({2, 0, 1});
    
    r->addIndex<3>(ord1171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord1172({0, 1, 2});
    
    r->addIndex<3>(ord1172, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord1173({2, 0, 1});
    
    r->addIndex<3>(ord1173, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup15869x25x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  // (crule (pre) (scan eval __38jS68 __t0QBk41) (body (join app (0 1 2) 1 __t0QBk41 ef ea)) (head (emit $sup15869x33x0x0x0 (0 1) ea ef)) 0cfa-demand.slog:34 #f)
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
      head_rel[0] = db->getRelation("$sup15869x33x0x0x0");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("$sup15869x33x0x0x0");
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:34", "delta:eval", _fires);
  
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
  // (crule (pre (let __trid1G1W65 constc40db22dfb3712d9bcc7a93e) (let __trel01t866 const4a59dbb9cb3129dfcc75170b) (let __tcol2diU67 const5feceb66ffc86f38d952786c)) (scan $sup15869x25x0x0x0 __d0 ea ef) (body) (head (tycheck ea (accept (struct app) (struct lambda) (struct ref)) __trid1G1W65 __trel01t866 __tcol2diU67 (1 2 3 4 0)) (mkstruct eval (1 0) __6ZI964 ea)) 0cfa-demand.slog:26 #f)
  class ReadTask10 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid7;  u32 sid8;  u32 sid9;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup15869x25x0x0x0");
      sid7 = db->getRelation("app")->getStructId();
      sid8 = db->getRelation("lambda")->getStructId();
      sid9 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask10(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_constc40db22dfb3712d9bcc7a93e;
      u64 v_c5 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c7 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid7 || decode_struct_id(v_c3) == sid8 || decode_struct_id(v_c3) == sid9))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c4, v_c5, v_c6, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:$sup15869x25x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask10* _cont = new ReadTask10(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask10(db,b), false);
  // (crule (pre) (scan eval_ans __t94No27 va) (body (exists $sup15869x25x0x0x1 (2 6 0 1 3 4 5 7) 2 __t94No27 va) (join-old eval (0 1) 1 (0 1) __t94No27 ea) (exists $sup15869x25x0x0x0 (1 0 2) 1 ea) (exists app (2 0 1) 1 ea) (join-old $sup15869x25x0x0x1 (2 3 6 0 1 4 5 7) 3 (2 3 6 0 1 4 5 7) __t94No27 ea va __t21aQ24 __t3z1j25 eb ef x) (join-old $sup15869x25x0x0x0 (0 1 2) 3 (0 1 2) __t21aQ24 ea ef) (join-old eval (0 1) 2 (0 1) __t3z1j25 ef) (exists lambda (2 1 0) 2 eb x) (exists eval_ans (0 1) 1 __t3z1j25) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t53Ss23) (join-old eval (0 1) 2 (0 1) __t21aQ24 __t53Ss23) (join lambda (2 1 0) 2 eb x __t4NYz26) (join eval_ans (0 1) 2 __t3z1j25 __t4NYz26) (join-old eval (1 0) 1 (1 0) eb __t65yE28) (join-old eval_ans (0 1) 1 (0 1) __t65yE28 v)) (head (emit eval_ans (0 1) __t21aQ24 v)) 0cfa-demand.slog:26 #f)
  class ReadTask34 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x25x0x0x1index11;  slog::Index** evalindex12;  slog::Index** $sup15869x25x0x0x0index13;  slog::Index** appindex14;  slog::Index** $sup15869x25x0x0x1index15;  slog::Index** $sup15869x25x0x0x0index16;  slog::Index** evalindex17;  slog::Index** lambdaindex18;  slog::Index** eval_ansindex19;  slog::Index** evalindex20;  slog::Index** appindex21;  slog::Index** evalindex22;  slog::Index** lambdaindex23;  slog::Index** eval_ansindex24;  slog::Index** evalindex25;  slog::Index** eval_ansindex26;  slog::Index** evaldelta27;  slog::Index** $sup15869x25x0x0x1delta28;  slog::Index** $sup15869x25x0x0x0delta29;  slog::Index** evaldelta30;  slog::Index** evaldelta31;  slog::Index** evaldelta32;  slog::Index** eval_ansdelta33;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("eval_ans");
      head_index[0] = readrel36->getIndex(ord35, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord37({2, 6, 0, 1, 3, 4, 5, 7});
      slog::Relation* readrel38 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index11 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("eval");
      evalindex12 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0, 1});
      slog::Relation* readrel42 = db->getRelation("eval");
      evaldelta27 = readrel42->getIndex(ord41, true);
      std::vector<u16> ord43({1, 0, 2});
      slog::Relation* readrel44 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index13 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({2, 0, 1});
      slog::Relation* readrel46 = db->getRelation("app");
      appindex14 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({2, 3, 6, 0, 1, 4, 5, 7});
      slog::Relation* readrel48 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index15 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({2, 3, 6, 0, 1, 4, 5, 7});
      slog::Relation* readrel50 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1delta28 = readrel50->getIndex(ord49, true);
      std::vector<u16> ord51({0, 1, 2});
      slog::Relation* readrel52 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index16 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({0, 1, 2});
      slog::Relation* readrel54 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0delta29 = readrel54->getIndex(ord53, true);
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("eval");
      evalindex17 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("eval");
      evaldelta30 = readrel58->getIndex(ord57, true);
      std::vector<u16> ord59({2, 1, 0});
      slog::Relation* readrel60 = db->getRelation("lambda");
      lambdaindex18 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({0, 1});
      slog::Relation* readrel62 = db->getRelation("eval_ans");
      eval_ansindex19 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 0});
      slog::Relation* readrel64 = db->getRelation("eval");
      evalindex20 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({1, 2, 0});
      slog::Relation* readrel66 = db->getRelation("app");
      appindex21 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({0, 1});
      slog::Relation* readrel68 = db->getRelation("eval");
      evalindex22 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({0, 1});
      slog::Relation* readrel70 = db->getRelation("eval");
      evaldelta31 = readrel70->getIndex(ord69, true);
      std::vector<u16> ord71({2, 1, 0});
      slog::Relation* readrel72 = db->getRelation("lambda");
      lambdaindex23 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("eval_ans");
      eval_ansindex24 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 0});
      slog::Relation* readrel76 = db->getRelation("eval");
      evalindex25 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 0});
      slog::Relation* readrel78 = db->getRelation("eval");
      evaldelta32 = readrel78->getIndex(ord77, true);
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("eval_ans");
      eval_ansindex26 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({0, 1});
      slog::Relation* readrel82 = db->getRelation("eval_ans");
      eval_ansdelta33 = readrel82->getIndex(ord81, true);
  
    }
    ReadTask34(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<8,2>($sup15869x25x0x0x1index11, std::array<u64,8>{v_c8, v_c9, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(evalindex12, evaldelta27, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m83) {
          u64 v_c3 = m83[1];
          if (!slog::exists_probe<3,1>($sup15869x25x0x0x0index13, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex14, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe_old<8,3>($sup15869x25x0x0x1index15, $sup15869x25x0x0x1delta28, std::array<u64,8>{v_c8, v_c3, v_c9, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m84) {
            u64 v_c10 = m84[3]; u64 v_c11 = m84[4]; u64 v_c12 = m84[5]; u64 v_c2 = m84[6]; u64 v_c13 = m84[7];
            slog::join_probe_old<3,3>($sup15869x25x0x0x0index16, $sup15869x25x0x0x0delta29, std::array<u64,3>{v_c10, v_c3, v_c2}, [&](const std::array<u64,3>& m85) {
              slog::join_probe_old<2,2>(evalindex17, evaldelta30, std::array<u64,2>{v_c11, v_c2}, [&](const std::array<u64,2>& m86) {
                if (!slog::exists_probe<3,2>(lambdaindex18, std::array<u64,3>{v_c12, v_c13, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex19, std::array<u64,2>{v_c11, 0})) return;
                if (!slog::exists_probe<2,1>(evalindex20, std::array<u64,2>{v_c12, 0})) return;
                slog::join_probe<3,2>(appindex21, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m87) {
                  u64 v_c14 = m87[2];
                  slog::join_probe_old<2,2>(evalindex22, evaldelta31, std::array<u64,2>{v_c10, v_c14}, [&](const std::array<u64,2>& m88) {
                    slog::join_probe<3,2>(lambdaindex23, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m89) {
                      u64 v_c15 = m89[2];
                      slog::join_probe<2,2>(eval_ansindex24, std::array<u64,2>{v_c11, v_c15}, [&](const std::array<u64,2>& m90) {
                        slog::join_probe_old<2,1>(evalindex25, evaldelta32, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m91) {
                          u64 v_c16 = m91[1];
                          slog::join_probe_old<2,1>(eval_ansindex26, eval_ansdelta33, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m92) {
                            u64 v_c17 = m92[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask34* _cont = new ReadTask34(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask34(db,b), false);
  // (crule (pre) (scan eval_ans __t2MpD42 __t1L7f43) (body (join-old eval (0 1) 1 (0 1) __t2MpD42 ef) (join $sup15869x25x0x0x0 (2 0 1) 1 ef __d0 ea) (join-old eval (1 0) 1 (1 0) ea __t2CtC44) (join-old eval_ans (0 1) 1 (0 1) __t2CtC44 va) (join lambda (0 1 2) 1 __t1L7f43 x eb)) (head (emit $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2MpD42 __t2CtC44 eb va x)) 0cfa-demand.slog:26 #f)
  class ReadTask101 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex93;  slog::Index** $sup15869x25x0x0x0index94;  slog::Index** evalindex95;  slog::Index** eval_ansindex96;  slog::Index** lambdaindex97;  slog::Index** evaldelta98;  slog::Index** evaldelta99;  slog::Index** eval_ansdelta100;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup15869x25x0x0x1");
      std::vector<u16> ord102({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel103 = db->getRelation("$sup15869x25x0x0x1");
      head_index[0] = readrel103->getIndex(ord102, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord104({0, 1});
      slog::Relation* readrel105 = db->getRelation("eval");
      evalindex93 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({0, 1});
      slog::Relation* readrel107 = db->getRelation("eval");
      evaldelta98 = readrel107->getIndex(ord106, true);
      std::vector<u16> ord108({2, 0, 1});
      slog::Relation* readrel109 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index94 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 0});
      slog::Relation* readrel111 = db->getRelation("eval");
      evalindex95 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 0});
      slog::Relation* readrel113 = db->getRelation("eval");
      evaldelta99 = readrel113->getIndex(ord112, true);
      std::vector<u16> ord114({0, 1});
      slog::Relation* readrel115 = db->getRelation("eval_ans");
      eval_ansindex96 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({0, 1});
      slog::Relation* readrel117 = db->getRelation("eval_ans");
      eval_ansdelta100 = readrel117->getIndex(ord116, true);
      std::vector<u16> ord118({0, 1, 2});
      slog::Relation* readrel119 = db->getRelation("lambda");
      lambdaindex97 = readrel119->getIndex(ord118, false);
  
    }
    ReadTask101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(evalindex93, evaldelta98, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m120) {
          u64 v_c2 = m120[1];
          slog::join_probe<3,1>($sup15869x25x0x0x0index94, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m121) {
            u64 v_c7 = m121[1]; u64 v_c3 = m121[2];
            slog::join_probe_old<2,1>(evalindex95, evaldelta99, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m122) {
              u64 v_c20 = m122[1];
              slog::join_probe_old<2,1>(eval_ansindex96, eval_ansdelta100, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m123) {
                u64 v_c9 = m123[1];
                slog::join_probe<3,1>(lambdaindex97, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m124) {
                  u64 v_c13 = m124[1]; u64 v_c12 = m124[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c7, v_c3, v_c2, v_c18, v_c20, v_c12, v_c9, v_c13}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask101* _cont = new ReadTask101(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask101(db,b), false);
  // (crule (pre) (scan eval __t65yE28 eb) (body (exists lambda (2 1 0) 1 eb) (exists $sup15869x25x0x0x1 (4 7 1 0 2 3 5 6) 1 eb) (join eval_ans (0 1) 1 __t65yE28 v) (join lambda (2 1 0) 1 eb x __t4NYz26) (exists $sup15869x25x0x0x1 (4 7 1 0 2 3 5 6) 2 eb x) (join eval_ans (1 0) 1 __t4NYz26 __t3z1j25) (join $sup15869x25x0x0x1 (4 7 1 0 2 3 5 6) 3 eb x __t3z1j25 __t21aQ24 __t94No27 ea ef va) (join $sup15869x25x0x0x0 (0 1 2) 3 __t21aQ24 ea ef) (join eval_ans (0 1) 2 __t94No27 va) (join eval (0 1) 2 __t3z1j25 ef) (join eval (0 1) 2 __t94No27 ea) (join app (1 2 0) 2 ef ea __t53Ss23) (join eval (0 1) 2 __t21aQ24 __t53Ss23)) (head (emit eval_ans (0 1) __t21aQ24 v)) 0cfa-demand.slog:26 #f)
  class ReadTask138 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex125;  slog::Index** $sup15869x25x0x0x1index126;  slog::Index** eval_ansindex127;  slog::Index** lambdaindex128;  slog::Index** $sup15869x25x0x0x1index129;  slog::Index** eval_ansindex130;  slog::Index** $sup15869x25x0x0x1index131;  slog::Index** $sup15869x25x0x0x0index132;  slog::Index** eval_ansindex133;  slog::Index** evalindex134;  slog::Index** evalindex135;  slog::Index** appindex136;  slog::Index** evalindex137;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord139({0, 1});
      slog::Relation* readrel140 = db->getRelation("eval_ans");
      head_index[0] = readrel140->getIndex(ord139, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord141({2, 1, 0});
      slog::Relation* readrel142 = db->getRelation("lambda");
      lambdaindex125 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel144 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index126 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("eval_ans");
      eval_ansindex127 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({2, 1, 0});
      slog::Relation* readrel148 = db->getRelation("lambda");
      lambdaindex128 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel150 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index129 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 0});
      slog::Relation* readrel152 = db->getRelation("eval_ans");
      eval_ansindex130 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel154 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index131 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({0, 1, 2});
      slog::Relation* readrel156 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index132 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({0, 1});
      slog::Relation* readrel158 = db->getRelation("eval_ans");
      eval_ansindex133 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({0, 1});
      slog::Relation* readrel160 = db->getRelation("eval");
      evalindex134 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({0, 1});
      slog::Relation* readrel162 = db->getRelation("eval");
      evalindex135 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 0});
      slog::Relation* readrel164 = db->getRelation("app");
      appindex136 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({0, 1});
      slog::Relation* readrel166 = db->getRelation("eval");
      evalindex137 = readrel166->getIndex(ord165, false);
  
    }
    ReadTask138(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        if (!slog::exists_probe<3,1>(lambdaindex125, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<8,1>($sup15869x25x0x0x1index126, std::array<u64,8>{v_c12, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex127, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m167) {
          u64 v_c17 = m167[1];
          slog::join_probe<3,1>(lambdaindex128, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m168) {
            u64 v_c13 = m168[1]; u64 v_c15 = m168[2];
            if (!slog::exists_probe<8,2>($sup15869x25x0x0x1index129, std::array<u64,8>{v_c12, v_c13, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<2,1>(eval_ansindex130, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m169) {
              u64 v_c11 = m169[1];
              slog::join_probe<8,3>($sup15869x25x0x0x1index131, std::array<u64,8>{v_c12, v_c13, v_c11, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m170) {
                u64 v_c10 = m170[3]; u64 v_c8 = m170[4]; u64 v_c3 = m170[5]; u64 v_c2 = m170[6]; u64 v_c9 = m170[7];
                slog::join_probe<3,3>($sup15869x25x0x0x0index132, std::array<u64,3>{v_c10, v_c3, v_c2}, [&](const std::array<u64,3>& m171) {
                  slog::join_probe<2,2>(eval_ansindex133, std::array<u64,2>{v_c8, v_c9}, [&](const std::array<u64,2>& m172) {
                    slog::join_probe<2,2>(evalindex134, std::array<u64,2>{v_c11, v_c2}, [&](const std::array<u64,2>& m173) {
                      slog::join_probe<2,2>(evalindex135, std::array<u64,2>{v_c8, v_c3}, [&](const std::array<u64,2>& m174) {
                        slog::join_probe<3,2>(appindex136, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m175) {
                          u64 v_c14 = m175[2];
                          slog::join_probe<2,2>(evalindex137, std::array<u64,2>{v_c10, v_c14}, [&](const std::array<u64,2>& m176) {
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask138* _cont = new ReadTask138(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask138(db,b), false);
  // (crule (pre) (scan eval __t7NXF35 __t2Ncr34) (body (join ref (0 1) 1 __t2Ncr34 x) (join store (0 1) 1 x v)) (head (emit eval_ans (0 1) __t7NXF35 v)) 0cfa-demand.slog:23 #f)
  class ReadTask179 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex177;  slog::Index** storeindex178;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord180({0, 1});
      slog::Relation* readrel181 = db->getRelation("eval_ans");
      head_index[0] = readrel181->getIndex(ord180, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord182({0, 1});
      slog::Relation* readrel183 = db->getRelation("ref");
      refindex177 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({0, 1});
      slog::Relation* readrel185 = db->getRelation("store");
      storeindex178 = readrel185->getIndex(ord184, false);
  
    }
    ReadTask179(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(refindex177, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m186) {
          u64 v_c13 = m186[1];
          slog::join_probe<2,1>(storeindex178, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m187) {
            u64 v_c17 = m187[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c17}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:23", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask179* _cont = new ReadTask179(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask179(db,b), false);
  // (crule (pre) (scan $sup15869x25x0x0x0 __t21aQ24 ea ef) (body (exists $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) 3 __t21aQ24 ea ef) (exists eval (1 0) 1 ef) (exists eval (1 0) 1 ea) (join app (1 2 0) 2 ef ea __t53Ss23) (join-old eval (0 1) 2 (0 1) __t21aQ24 __t53Ss23) (join-old $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) 3 (0 3 5 1 2 4 6 7) __t21aQ24 ea ef __t3z1j25 __t94No27 eb va x) (join eval_ans (0 1) 2 __t94No27 va) (join-old eval (0 1) 2 (0 1) __t3z1j25 ef) (join-old eval (0 1) 2 (0 1) __t94No27 ea) (exists eval_ans (0 1) 1 __t3z1j25) (exists eval (1 0) 1 eb) (join lambda (2 1 0) 2 eb x __t4NYz26) (join eval_ans (0 1) 2 __t3z1j25 __t4NYz26) (join-old eval (1 0) 1 (1 0) eb __t65yE28) (join eval_ans (0 1) 1 __t65yE28 v)) (head (emit eval_ans (0 1) __t21aQ24 v)) 0cfa-demand.slog:26 #f)
  class ReadTask208 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x25x0x0x1index188;  slog::Index** evalindex189;  slog::Index** evalindex190;  slog::Index** appindex191;  slog::Index** evalindex192;  slog::Index** $sup15869x25x0x0x1index193;  slog::Index** eval_ansindex194;  slog::Index** evalindex195;  slog::Index** evalindex196;  slog::Index** eval_ansindex197;  slog::Index** evalindex198;  slog::Index** lambdaindex199;  slog::Index** eval_ansindex200;  slog::Index** evalindex201;  slog::Index** eval_ansindex202;  slog::Index** evaldelta203;  slog::Index** $sup15869x25x0x0x1delta204;  slog::Index** evaldelta205;  slog::Index** evaldelta206;  slog::Index** evaldelta207;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord209({0, 1});
      slog::Relation* readrel210 = db->getRelation("eval_ans");
      head_index[0] = readrel210->getIndex(ord209, false);
      outer_rel = db->getRelation("$sup15869x25x0x0x0");
      std::vector<u16> ord211({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel212 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index188 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 0});
      slog::Relation* readrel214 = db->getRelation("eval");
      evalindex189 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 0});
      slog::Relation* readrel216 = db->getRelation("eval");
      evalindex190 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 0});
      slog::Relation* readrel218 = db->getRelation("app");
      appindex191 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({0, 1});
      slog::Relation* readrel220 = db->getRelation("eval");
      evalindex192 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({0, 1});
      slog::Relation* readrel222 = db->getRelation("eval");
      evaldelta203 = readrel222->getIndex(ord221, true);
      std::vector<u16> ord223({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel224 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index193 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel226 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1delta204 = readrel226->getIndex(ord225, true);
      std::vector<u16> ord227({0, 1});
      slog::Relation* readrel228 = db->getRelation("eval_ans");
      eval_ansindex194 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({0, 1});
      slog::Relation* readrel230 = db->getRelation("eval");
      evalindex195 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 1});
      slog::Relation* readrel232 = db->getRelation("eval");
      evaldelta205 = readrel232->getIndex(ord231, true);
      std::vector<u16> ord233({0, 1});
      slog::Relation* readrel234 = db->getRelation("eval");
      evalindex196 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 1});
      slog::Relation* readrel236 = db->getRelation("eval");
      evaldelta206 = readrel236->getIndex(ord235, true);
      std::vector<u16> ord237({0, 1});
      slog::Relation* readrel238 = db->getRelation("eval_ans");
      eval_ansindex197 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 0});
      slog::Relation* readrel240 = db->getRelation("eval");
      evalindex198 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({2, 1, 0});
      slog::Relation* readrel242 = db->getRelation("lambda");
      lambdaindex199 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({0, 1});
      slog::Relation* readrel244 = db->getRelation("eval_ans");
      eval_ansindex200 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 0});
      slog::Relation* readrel246 = db->getRelation("eval");
      evalindex201 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 0});
      slog::Relation* readrel248 = db->getRelation("eval");
      evaldelta207 = readrel248->getIndex(ord247, true);
      std::vector<u16> ord249({0, 1});
      slog::Relation* readrel250 = db->getRelation("eval_ans");
      eval_ansindex202 = readrel250->getIndex(ord249, false);
  
    }
    ReadTask208(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<8,3>($sup15869x25x0x0x1index188, std::array<u64,8>{v_c10, v_c3, v_c2, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(evalindex189, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(evalindex190, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<3,2>(appindex191, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m251) {
          u64 v_c14 = m251[2];
          slog::join_probe_old<2,2>(evalindex192, evaldelta203, std::array<u64,2>{v_c10, v_c14}, [&](const std::array<u64,2>& m252) {
            slog::join_probe_old<8,3>($sup15869x25x0x0x1index193, $sup15869x25x0x0x1delta204, std::array<u64,8>{v_c10, v_c3, v_c2, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m253) {
              u64 v_c11 = m253[3]; u64 v_c8 = m253[4]; u64 v_c12 = m253[5]; u64 v_c9 = m253[6]; u64 v_c13 = m253[7];
              slog::join_probe<2,2>(eval_ansindex194, std::array<u64,2>{v_c8, v_c9}, [&](const std::array<u64,2>& m254) {
                slog::join_probe_old<2,2>(evalindex195, evaldelta205, std::array<u64,2>{v_c11, v_c2}, [&](const std::array<u64,2>& m255) {
                  slog::join_probe_old<2,2>(evalindex196, evaldelta206, std::array<u64,2>{v_c8, v_c3}, [&](const std::array<u64,2>& m256) {
                    if (!slog::exists_probe<2,1>(eval_ansindex197, std::array<u64,2>{v_c11, 0})) return;
                    if (!slog::exists_probe<2,1>(evalindex198, std::array<u64,2>{v_c12, 0})) return;
                    slog::join_probe<3,2>(lambdaindex199, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m257) {
                      u64 v_c15 = m257[2];
                      slog::join_probe<2,2>(eval_ansindex200, std::array<u64,2>{v_c11, v_c15}, [&](const std::array<u64,2>& m258) {
                        slog::join_probe_old<2,1>(evalindex201, evaldelta207, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m259) {
                          u64 v_c16 = m259[1];
                          slog::join_probe<2,1>(eval_ansindex202, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m260) {
                            u64 v_c17 = m260[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:$sup15869x25x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask208* _cont = new ReadTask208(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask208(db,b), false);
  // (crule (pre) (scan eval __t4UpS37 __t6eAN36) (body (join app (0 1 2) 1 __t6eAN36 ef ea)) (head (emit $sup15869x25x0x0x0 (0 1 2) __t4UpS37 ea ef)) 0cfa-demand.slog:26 #f)
  class ReadTask262 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex261;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup15869x25x0x0x0");
      std::vector<u16> ord263({0, 1, 2});
      slog::Relation* readrel264 = db->getRelation("$sup15869x25x0x0x0");
      head_index[0] = readrel264->getIndex(ord263, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord265({0, 1, 2});
      slog::Relation* readrel266 = db->getRelation("app");
      appindex261 = readrel266->getIndex(ord265, false);
  
    }
    ReadTask262(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<3,1>(appindex261, std::array<u64,3>{v_c24, 0, 0}, [&](const std::array<u64,3>& m267) {
          u64 v_c2 = m267[1]; u64 v_c3 = m267[2];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c23, v_c3, v_c2}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask262* _cont = new ReadTask262(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask262(db,b), false);
  // (crule (pre) (scan eval __6Yjj70 __t5UcN30) (body (join app (0 1 2) 1 __t5UcN30 ef ea) (join-old $sup15869x33x0x0x0 (0 1) 2 (0 1) ea ef) (exists eval (1 0) 1 ea) (join-old eval (1 0) 1 (1 0) ef __t1miS31) (join-old eval_ans (0 1) 1 (0 1) __t1miS31 __t2kGk32) (join-old eval (1 0) 1 (1 0) ea __t5Tar33) (join-old eval_ans (0 1) 1 (0 1) __t5Tar33 va) (join lambda (0 1 2) 1 __t2kGk32 x eb)) (head (emit store (0 1) x va)) 0cfa-demand.slog:34 #f)
  class ReadTask281 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex268;  slog::Index** $sup15869x33x0x0x0index269;  slog::Index** evalindex270;  slog::Index** evalindex271;  slog::Index** eval_ansindex272;  slog::Index** evalindex273;  slog::Index** eval_ansindex274;  slog::Index** lambdaindex275;  slog::Index** $sup15869x33x0x0x0delta276;  slog::Index** evaldelta277;  slog::Index** eval_ansdelta278;  slog::Index** evaldelta279;  slog::Index** eval_ansdelta280;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord282({0, 1});
      slog::Relation* readrel283 = db->getRelation("store");
      head_index[0] = readrel283->getIndex(ord282, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord284({0, 1, 2});
      slog::Relation* readrel285 = db->getRelation("app");
      appindex268 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({0, 1});
      slog::Relation* readrel287 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0index269 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({0, 1});
      slog::Relation* readrel289 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0delta276 = readrel289->getIndex(ord288, true);
      std::vector<u16> ord290({1, 0});
      slog::Relation* readrel291 = db->getRelation("eval");
      evalindex270 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 0});
      slog::Relation* readrel293 = db->getRelation("eval");
      evalindex271 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 0});
      slog::Relation* readrel295 = db->getRelation("eval");
      evaldelta277 = readrel295->getIndex(ord294, true);
      std::vector<u16> ord296({0, 1});
      slog::Relation* readrel297 = db->getRelation("eval_ans");
      eval_ansindex272 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({0, 1});
      slog::Relation* readrel299 = db->getRelation("eval_ans");
      eval_ansdelta278 = readrel299->getIndex(ord298, true);
      std::vector<u16> ord300({1, 0});
      slog::Relation* readrel301 = db->getRelation("eval");
      evalindex273 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 0});
      slog::Relation* readrel303 = db->getRelation("eval");
      evaldelta279 = readrel303->getIndex(ord302, true);
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("eval_ans");
      eval_ansindex274 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("eval_ans");
      eval_ansdelta280 = readrel307->getIndex(ord306, true);
      std::vector<u16> ord308({0, 1, 2});
      slog::Relation* readrel309 = db->getRelation("lambda");
      lambdaindex275 = readrel309->getIndex(ord308, false);
  
    }
    ReadTask281(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[1];
        slog::join_probe<3,1>(appindex268, std::array<u64,3>{v_c26, 0, 0}, [&](const std::array<u64,3>& m310) {
          u64 v_c2 = m310[1]; u64 v_c3 = m310[2];
          slog::join_probe_old<2,2>($sup15869x33x0x0x0index269, $sup15869x33x0x0x0delta276, std::array<u64,2>{v_c3, v_c2}, [&](const std::array<u64,2>& m311) {
            if (!slog::exists_probe<2,1>(evalindex270, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe_old<2,1>(evalindex271, evaldelta277, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m312) {
              u64 v_c27 = m312[1];
              slog::join_probe_old<2,1>(eval_ansindex272, eval_ansdelta278, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m313) {
                u64 v_c28 = m313[1];
                slog::join_probe_old<2,1>(evalindex273, evaldelta279, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m314) {
                  u64 v_c29 = m314[1];
                  slog::join_probe_old<2,1>(eval_ansindex274, eval_ansdelta280, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m315) {
                    u64 v_c9 = m315[1];
                    slog::join_probe<3,1>(lambdaindex275, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m316) {
                      u64 v_c13 = m316[1]; u64 v_c12 = m316[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c9}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:34", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask281* _cont = new ReadTask281(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask281(db,b), false);
  // (crule (pre) (scan program e) (body) (head (mkstruct eval (1 0) __7yWq71 e)) 0cfa-demand.slog:36 #f)
  class ReadTask317 : public slog::Task
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
    ReadTask317(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c30}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:36", "all:program", _fires);
  
      if (!_done)
      {
        ReadTask317* _cont = new ReadTask317(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask317(db,b), true);
  // (crule (pre) (scan eval_ans __t2CtC44 va) (body (join-old eval (0 1) 1 (0 1) __t2CtC44 ea) (join $sup15869x25x0x0x0 (1 0 2) 1 ea __d0 ef) (join-old eval (1 0) 1 (1 0) ef __t2MpD42) (join eval_ans (0 1) 1 __t2MpD42 __t1L7f43) (join lambda (0 1 2) 1 __t1L7f43 x eb)) (head (emit $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2MpD42 __t2CtC44 eb va x)) 0cfa-demand.slog:26 #f)
  class ReadTask325 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex318;  slog::Index** $sup15869x25x0x0x0index319;  slog::Index** evalindex320;  slog::Index** eval_ansindex321;  slog::Index** lambdaindex322;  slog::Index** evaldelta323;  slog::Index** evaldelta324;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup15869x25x0x0x1");
      std::vector<u16> ord326({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel327 = db->getRelation("$sup15869x25x0x0x1");
      head_index[0] = readrel327->getIndex(ord326, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord328({0, 1});
      slog::Relation* readrel329 = db->getRelation("eval");
      evalindex318 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({0, 1});
      slog::Relation* readrel331 = db->getRelation("eval");
      evaldelta323 = readrel331->getIndex(ord330, true);
      std::vector<u16> ord332({1, 0, 2});
      slog::Relation* readrel333 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index319 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 0});
      slog::Relation* readrel335 = db->getRelation("eval");
      evalindex320 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 0});
      slog::Relation* readrel337 = db->getRelation("eval");
      evaldelta324 = readrel337->getIndex(ord336, true);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("eval_ans");
      eval_ansindex321 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({0, 1, 2});
      slog::Relation* readrel341 = db->getRelation("lambda");
      lambdaindex322 = readrel341->getIndex(ord340, false);
  
    }
    ReadTask325(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        slog::join_probe_old<2,1>(evalindex318, evaldelta323, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m342) {
          u64 v_c3 = m342[1];
          slog::join_probe<3,1>($sup15869x25x0x0x0index319, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m343) {
            u64 v_c7 = m343[1]; u64 v_c2 = m343[2];
            slog::join_probe_old<2,1>(evalindex320, evaldelta324, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m344) {
              u64 v_c18 = m344[1];
              slog::join_probe<2,1>(eval_ansindex321, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m345) {
                u64 v_c19 = m345[1];
                slog::join_probe<3,1>(lambdaindex322, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m346) {
                  u64 v_c13 = m346[1]; u64 v_c12 = m346[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c7, v_c3, v_c2, v_c18, v_c20, v_c12, v_c9, v_c13}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask325* _cont = new ReadTask325(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask325(db,b), false);
  // (crule (pre) (scan eval __t5Tar33 ea) (body (exists $sup15869x33x0x0x0 (0 1) 1 ea) (exists app (2 0 1) 1 ea) (join eval_ans (0 1) 1 __t5Tar33 va) (join $sup15869x33x0x0x0 (0 1) 1 ea ef) (exists eval (1 0) 1 ef) (join app (1 2 0) 2 ef ea __t5UcN30) (join eval (1 0) 1 __t5UcN30 __6Yjj70) (join eval (1 0) 1 ef __t1miS31) (join eval_ans (0 1) 1 __t1miS31 __t2kGk32) (join lambda (0 1 2) 1 __t2kGk32 x eb)) (head (emit store (0 1) x va)) 0cfa-demand.slog:34 #f)
  class ReadTask357 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x33x0x0x0index347;  slog::Index** appindex348;  slog::Index** eval_ansindex349;  slog::Index** $sup15869x33x0x0x0index350;  slog::Index** evalindex351;  slog::Index** appindex352;  slog::Index** evalindex353;  slog::Index** evalindex354;  slog::Index** eval_ansindex355;  slog::Index** lambdaindex356;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord358({0, 1});
      slog::Relation* readrel359 = db->getRelation("store");
      head_index[0] = readrel359->getIndex(ord358, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord360({0, 1});
      slog::Relation* readrel361 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0index347 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({2, 0, 1});
      slog::Relation* readrel363 = db->getRelation("app");
      appindex348 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({0, 1});
      slog::Relation* readrel365 = db->getRelation("eval_ans");
      eval_ansindex349 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({0, 1});
      slog::Relation* readrel367 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0index350 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({1, 0});
      slog::Relation* readrel369 = db->getRelation("eval");
      evalindex351 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({1, 2, 0});
      slog::Relation* readrel371 = db->getRelation("app");
      appindex352 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 0});
      slog::Relation* readrel373 = db->getRelation("eval");
      evalindex353 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 0});
      slog::Relation* readrel375 = db->getRelation("eval");
      evalindex354 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({0, 1});
      slog::Relation* readrel377 = db->getRelation("eval_ans");
      eval_ansindex355 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 1, 2});
      slog::Relation* readrel379 = db->getRelation("lambda");
      lambdaindex356 = readrel379->getIndex(ord378, false);
  
    }
    ReadTask357(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<2,1>($sup15869x33x0x0x0index347, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(appindex348, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex349, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m380) {
          u64 v_c9 = m380[1];
          slog::join_probe<2,1>($sup15869x33x0x0x0index350, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m381) {
            u64 v_c2 = m381[1];
            if (!slog::exists_probe<2,1>(evalindex351, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<3,2>(appindex352, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m382) {
              u64 v_c26 = m382[2];
              slog::join_probe<2,1>(evalindex353, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m383) {
                u64 v_c25 = m383[1];
                slog::join_probe<2,1>(evalindex354, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m384) {
                  u64 v_c27 = m384[1];
                  slog::join_probe<2,1>(eval_ansindex355, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m385) {
                    u64 v_c28 = m385[1];
                    slog::join_probe<3,1>(lambdaindex356, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m386) {
                      u64 v_c13 = m386[1]; u64 v_c12 = m386[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c9}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:34", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask357* _cont = new ReadTask357(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask357(db,b), false);
  // (crule (pre) (scan eval_ans __t5Tar33 va) (body (join-old eval (0 1) 1 (0 1) __t5Tar33 ea) (exists app (2 0 1) 1 ea) (join-old $sup15869x33x0x0x0 (0 1) 1 (0 1) ea ef) (exists eval (1 0) 1 ef) (join app (1 2 0) 2 ef ea __t5UcN30) (join eval (1 0) 1 __t5UcN30 __6Yjj70) (join-old eval (1 0) 1 (1 0) ef __t1miS31) (join eval_ans (0 1) 1 __t1miS31 __t2kGk32) (join lambda (0 1 2) 1 __t2kGk32 x eb)) (head (emit store (0 1) x va)) 0cfa-demand.slog:34 #f)
  class ReadTask399 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex387;  slog::Index** appindex388;  slog::Index** $sup15869x33x0x0x0index389;  slog::Index** evalindex390;  slog::Index** appindex391;  slog::Index** evalindex392;  slog::Index** evalindex393;  slog::Index** eval_ansindex394;  slog::Index** lambdaindex395;  slog::Index** evaldelta396;  slog::Index** $sup15869x33x0x0x0delta397;  slog::Index** evaldelta398;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord400({0, 1});
      slog::Relation* readrel401 = db->getRelation("store");
      head_index[0] = readrel401->getIndex(ord400, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("eval");
      evalindex387 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("eval");
      evaldelta396 = readrel405->getIndex(ord404, true);
      std::vector<u16> ord406({2, 0, 1});
      slog::Relation* readrel407 = db->getRelation("app");
      appindex388 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({0, 1});
      slog::Relation* readrel409 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0index389 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 1});
      slog::Relation* readrel411 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0delta397 = readrel411->getIndex(ord410, true);
      std::vector<u16> ord412({1, 0});
      slog::Relation* readrel413 = db->getRelation("eval");
      evalindex390 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 2, 0});
      slog::Relation* readrel415 = db->getRelation("app");
      appindex391 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 0});
      slog::Relation* readrel417 = db->getRelation("eval");
      evalindex392 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 0});
      slog::Relation* readrel419 = db->getRelation("eval");
      evalindex393 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 0});
      slog::Relation* readrel421 = db->getRelation("eval");
      evaldelta398 = readrel421->getIndex(ord420, true);
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("eval_ans");
      eval_ansindex394 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({0, 1, 2});
      slog::Relation* readrel425 = db->getRelation("lambda");
      lambdaindex395 = readrel425->getIndex(ord424, false);
  
    }
    ReadTask399(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        slog::join_probe_old<2,1>(evalindex387, evaldelta396, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m426) {
          u64 v_c3 = m426[1];
          if (!slog::exists_probe<3,1>(appindex388, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe_old<2,1>($sup15869x33x0x0x0index389, $sup15869x33x0x0x0delta397, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m427) {
            u64 v_c2 = m427[1];
            if (!slog::exists_probe<2,1>(evalindex390, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<3,2>(appindex391, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m428) {
              u64 v_c26 = m428[2];
              slog::join_probe<2,1>(evalindex392, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m429) {
                u64 v_c25 = m429[1];
                slog::join_probe_old<2,1>(evalindex393, evaldelta398, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m430) {
                  u64 v_c27 = m430[1];
                  slog::join_probe<2,1>(eval_ansindex394, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m431) {
                    u64 v_c28 = m431[1];
                    slog::join_probe<3,1>(lambdaindex395, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m432) {
                      u64 v_c13 = m432[1]; u64 v_c12 = m432[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c9}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:34", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask399* _cont = new ReadTask399(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask399(db,b), false);
  // (crule (pre) (scan $sup15869x25x0x0x0 __d0 ea ef) (body (exists eval (1 0) 1 ea) (join-old eval (1 0) 1 (1 0) ef __t2MpD42) (join-old eval_ans (0 1) 1 (0 1) __t2MpD42 __t1L7f43) (join-old eval (1 0) 1 (1 0) ea __t2CtC44) (join-old eval_ans (0 1) 1 (0 1) __t2CtC44 va) (join lambda (0 1 2) 1 __t1L7f43 x eb)) (head (emit $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2MpD42 __t2CtC44 eb va x)) 0cfa-demand.slog:26 #f)
  class ReadTask443 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex433;  slog::Index** evalindex434;  slog::Index** eval_ansindex435;  slog::Index** evalindex436;  slog::Index** eval_ansindex437;  slog::Index** lambdaindex438;  slog::Index** evaldelta439;  slog::Index** eval_ansdelta440;  slog::Index** evaldelta441;  slog::Index** eval_ansdelta442;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup15869x25x0x0x1");
      std::vector<u16> ord444({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel445 = db->getRelation("$sup15869x25x0x0x1");
      head_index[0] = readrel445->getIndex(ord444, false);
      outer_rel = db->getRelation("$sup15869x25x0x0x0");
      std::vector<u16> ord446({1, 0});
      slog::Relation* readrel447 = db->getRelation("eval");
      evalindex433 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({1, 0});
      slog::Relation* readrel449 = db->getRelation("eval");
      evalindex434 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({1, 0});
      slog::Relation* readrel451 = db->getRelation("eval");
      evaldelta439 = readrel451->getIndex(ord450, true);
      std::vector<u16> ord452({0, 1});
      slog::Relation* readrel453 = db->getRelation("eval_ans");
      eval_ansindex435 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({0, 1});
      slog::Relation* readrel455 = db->getRelation("eval_ans");
      eval_ansdelta440 = readrel455->getIndex(ord454, true);
      std::vector<u16> ord456({1, 0});
      slog::Relation* readrel457 = db->getRelation("eval");
      evalindex436 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 0});
      slog::Relation* readrel459 = db->getRelation("eval");
      evaldelta441 = readrel459->getIndex(ord458, true);
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("eval_ans");
      eval_ansindex437 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({0, 1});
      slog::Relation* readrel463 = db->getRelation("eval_ans");
      eval_ansdelta442 = readrel463->getIndex(ord462, true);
      std::vector<u16> ord464({0, 1, 2});
      slog::Relation* readrel465 = db->getRelation("lambda");
      lambdaindex438 = readrel465->getIndex(ord464, false);
  
    }
    ReadTask443(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(evalindex433, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe_old<2,1>(evalindex434, evaldelta439, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m466) {
          u64 v_c18 = m466[1];
          slog::join_probe_old<2,1>(eval_ansindex435, eval_ansdelta440, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m467) {
            u64 v_c19 = m467[1];
            slog::join_probe_old<2,1>(evalindex436, evaldelta441, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m468) {
              u64 v_c20 = m468[1];
              slog::join_probe_old<2,1>(eval_ansindex437, eval_ansdelta442, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m469) {
                u64 v_c9 = m469[1];
                slog::join_probe<3,1>(lambdaindex438, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m470) {
                  u64 v_c13 = m470[1]; u64 v_c12 = m470[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c7, v_c3, v_c2, v_c18, v_c20, v_c12, v_c9, v_c13}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:$sup15869x25x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask443* _cont = new ReadTask443(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask443(db,b), false);
  // (crule (pre) (scan eval __t21aQ24 __t53Ss23) (body (exists $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) 1 __t21aQ24) (join $sup15869x25x0x0x0 (0 1 2) 1 __t21aQ24 ea ef) (join app (1 2 0) 3 ef ea __t53Ss23) (exists eval (1 0) 1 ef) (exists eval (1 0) 1 ea) (join $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) 3 __t21aQ24 ea ef __t3z1j25 __t94No27 eb va x) (join eval_ans (0 1) 2 __t94No27 va) (join-old eval (0 1) 2 (0 1) __t3z1j25 ef) (join-old eval (0 1) 2 (0 1) __t94No27 ea) (exists eval_ans (0 1) 1 __t3z1j25) (exists eval (1 0) 1 eb) (join lambda (2 1 0) 2 eb x __t4NYz26) (join eval_ans (0 1) 2 __t3z1j25 __t4NYz26) (join-old eval (1 0) 1 (1 0) eb __t65yE28) (join eval_ans (0 1) 1 __t65yE28 v)) (head (emit eval_ans (0 1) __t21aQ24 v)) 0cfa-demand.slog:26 #f)
  class ReadTask489 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x25x0x0x1index471;  slog::Index** $sup15869x25x0x0x0index472;  slog::Index** appindex473;  slog::Index** evalindex474;  slog::Index** evalindex475;  slog::Index** $sup15869x25x0x0x1index476;  slog::Index** eval_ansindex477;  slog::Index** evalindex478;  slog::Index** evalindex479;  slog::Index** eval_ansindex480;  slog::Index** evalindex481;  slog::Index** lambdaindex482;  slog::Index** eval_ansindex483;  slog::Index** evalindex484;  slog::Index** eval_ansindex485;  slog::Index** evaldelta486;  slog::Index** evaldelta487;  slog::Index** evaldelta488;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord490({0, 1});
      slog::Relation* readrel491 = db->getRelation("eval_ans");
      head_index[0] = readrel491->getIndex(ord490, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord492({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel493 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index471 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1, 2});
      slog::Relation* readrel495 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index472 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({1, 2, 0});
      slog::Relation* readrel497 = db->getRelation("app");
      appindex473 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({1, 0});
      slog::Relation* readrel499 = db->getRelation("eval");
      evalindex474 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({1, 0});
      slog::Relation* readrel501 = db->getRelation("eval");
      evalindex475 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel503 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index476 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({0, 1});
      slog::Relation* readrel505 = db->getRelation("eval_ans");
      eval_ansindex477 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({0, 1});
      slog::Relation* readrel507 = db->getRelation("eval");
      evalindex478 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({0, 1});
      slog::Relation* readrel509 = db->getRelation("eval");
      evaldelta486 = readrel509->getIndex(ord508, true);
      std::vector<u16> ord510({0, 1});
      slog::Relation* readrel511 = db->getRelation("eval");
      evalindex479 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("eval");
      evaldelta487 = readrel513->getIndex(ord512, true);
      std::vector<u16> ord514({0, 1});
      slog::Relation* readrel515 = db->getRelation("eval_ans");
      eval_ansindex480 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 0});
      slog::Relation* readrel517 = db->getRelation("eval");
      evalindex481 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({2, 1, 0});
      slog::Relation* readrel519 = db->getRelation("lambda");
      lambdaindex482 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({0, 1});
      slog::Relation* readrel521 = db->getRelation("eval_ans");
      eval_ansindex483 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({1, 0});
      slog::Relation* readrel523 = db->getRelation("eval");
      evalindex484 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({1, 0});
      slog::Relation* readrel525 = db->getRelation("eval");
      evaldelta488 = readrel525->getIndex(ord524, true);
      std::vector<u16> ord526({0, 1});
      slog::Relation* readrel527 = db->getRelation("eval_ans");
      eval_ansindex485 = readrel527->getIndex(ord526, false);
  
    }
    ReadTask489(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[0];
        u64 v_c14 = _t[1];
        if (!slog::exists_probe<8,1>($sup15869x25x0x0x1index471, std::array<u64,8>{v_c10, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<3,1>($sup15869x25x0x0x0index472, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m528) {
          u64 v_c3 = m528[1]; u64 v_c2 = m528[2];
          slog::join_probe<3,3>(appindex473, std::array<u64,3>{v_c2, v_c3, v_c14}, [&](const std::array<u64,3>& m529) {
            if (!slog::exists_probe<2,1>(evalindex474, std::array<u64,2>{v_c2, 0})) return;
            if (!slog::exists_probe<2,1>(evalindex475, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe<8,3>($sup15869x25x0x0x1index476, std::array<u64,8>{v_c10, v_c3, v_c2, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m530) {
              u64 v_c11 = m530[3]; u64 v_c8 = m530[4]; u64 v_c12 = m530[5]; u64 v_c9 = m530[6]; u64 v_c13 = m530[7];
              slog::join_probe<2,2>(eval_ansindex477, std::array<u64,2>{v_c8, v_c9}, [&](const std::array<u64,2>& m531) {
                slog::join_probe_old<2,2>(evalindex478, evaldelta486, std::array<u64,2>{v_c11, v_c2}, [&](const std::array<u64,2>& m532) {
                  slog::join_probe_old<2,2>(evalindex479, evaldelta487, std::array<u64,2>{v_c8, v_c3}, [&](const std::array<u64,2>& m533) {
                    if (!slog::exists_probe<2,1>(eval_ansindex480, std::array<u64,2>{v_c11, 0})) return;
                    if (!slog::exists_probe<2,1>(evalindex481, std::array<u64,2>{v_c12, 0})) return;
                    slog::join_probe<3,2>(lambdaindex482, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m534) {
                      u64 v_c15 = m534[2];
                      slog::join_probe<2,2>(eval_ansindex483, std::array<u64,2>{v_c11, v_c15}, [&](const std::array<u64,2>& m535) {
                        slog::join_probe_old<2,1>(evalindex484, evaldelta488, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m536) {
                          u64 v_c16 = m536[1];
                          slog::join_probe<2,1>(eval_ansindex485, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m537) {
                            u64 v_c17 = m537[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask489* _cont = new ReadTask489(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask489(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre1flm93 __errf8eTw94 __errf0sJh95 __errf5UdG96 __errf6QAe97) (body) (head (emit error (0) __erre1flm93)) <internal>:1 #f)
  class ReadTask538 : public slog::Task
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
      std::vector<u16> ord539({0});
      slog::Relation* readrel540 = db->getRelation("error");
      head_index[0] = readrel540->getIndex(ord539, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask538(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c35 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c31}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask538* _cont = new ReadTask538(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask538(db,b), false);
  // (crule (pre) (scan program e) (body) (head (mkstruct eval (1 0) __18Db69 e)) 0cfa-demand.slog:37 #f)
  class ReadTask541 : public slog::Task
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
        u64 v_c30 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c30}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:37", "all:program", _fires);
  
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
      s->addTask(phase_read, new ReadTask541(db,b), true);
  // (crule (pre (let __trid7kPt53 const895fb44435658e0cef51ef58) (let __trel8C1l54 constafcf65f310629738af953774) (let __tcol0bPF55 const6b86b273ff34fce19d6b804e)) (scan eval __t14SX40 __t1hJP39) (body (join lambda (0 1 2) 1 __t1hJP39 x eb)) (head (tycheck __t1hJP39 (accept (struct lambda)) __trid7kPt53 __trel8C1l54 __tcol0bPF55 (1 2 3 4 0)) (emit eval_ans (0 1) __t14SX40 __t1hJP39)) 0cfa-demand.slog:20 #f)
  class ReadTask544 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex542;
    u32 sid543;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval_ans");
      std::vector<u16> ord545({0, 1});
      slog::Relation* readrel546 = db->getRelation("eval_ans");
      head_index[1] = readrel546->getIndex(ord545, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord547({0, 1, 2});
      slog::Relation* readrel548 = db->getRelation("lambda");
      lambdaindex542 = readrel548->getIndex(ord547, false);
      sid543 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask544(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const895fb44435658e0cef51ef58;
      u64 v_c37 = v_constafcf65f310629738af953774;
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c39 = _t[0];
        u64 v_c40 = _t[1];
        slog::join_probe<3,1>(lambdaindex542, std::array<u64,3>{v_c40, 0, 0}, [&](const std::array<u64,3>& m549) {
          u64 v_c13 = m549[1]; u64 v_c12 = m549[2];
          ++_fires;
          if (!((is_struct(v_c40) && (decode_struct_id(v_c40) == sid543))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c36, v_c37, v_c38, v_c40}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c39, v_c40}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:20", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask544* _cont = new ReadTask544(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask544(db,b), false);
  // (crule (pre) (scan eval __t2MpD42 ef) (body (exists $sup15869x25x0x0x0 (2 0 1) 1 ef) (join eval_ans (0 1) 1 __t2MpD42 __t1L7f43) (join $sup15869x25x0x0x0 (2 0 1) 1 ef __d0 ea) (join-old eval (1 0) 1 (1 0) ea __t2CtC44) (join eval_ans (0 1) 1 __t2CtC44 va) (join lambda (0 1 2) 1 __t1L7f43 x eb)) (head (emit $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2MpD42 __t2CtC44 eb va x)) 0cfa-demand.slog:26 #f)
  class ReadTask557 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x25x0x0x0index550;  slog::Index** eval_ansindex551;  slog::Index** $sup15869x25x0x0x0index552;  slog::Index** evalindex553;  slog::Index** eval_ansindex554;  slog::Index** lambdaindex555;  slog::Index** evaldelta556;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup15869x25x0x0x1");
      std::vector<u16> ord558({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel559 = db->getRelation("$sup15869x25x0x0x1");
      head_index[0] = readrel559->getIndex(ord558, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord560({2, 0, 1});
      slog::Relation* readrel561 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index550 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({0, 1});
      slog::Relation* readrel563 = db->getRelation("eval_ans");
      eval_ansindex551 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({2, 0, 1});
      slog::Relation* readrel565 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index552 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({1, 0});
      slog::Relation* readrel567 = db->getRelation("eval");
      evalindex553 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 0});
      slog::Relation* readrel569 = db->getRelation("eval");
      evaldelta556 = readrel569->getIndex(ord568, true);
      std::vector<u16> ord570({0, 1});
      slog::Relation* readrel571 = db->getRelation("eval_ans");
      eval_ansindex554 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({0, 1, 2});
      slog::Relation* readrel573 = db->getRelation("lambda");
      lambdaindex555 = readrel573->getIndex(ord572, false);
  
    }
    ReadTask557(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<3,1>($sup15869x25x0x0x0index550, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex551, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m574) {
          u64 v_c19 = m574[1];
          slog::join_probe<3,1>($sup15869x25x0x0x0index552, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m575) {
            u64 v_c7 = m575[1]; u64 v_c3 = m575[2];
            slog::join_probe_old<2,1>(evalindex553, evaldelta556, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m576) {
              u64 v_c20 = m576[1];
              slog::join_probe<2,1>(eval_ansindex554, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m577) {
                u64 v_c9 = m577[1];
                slog::join_probe<3,1>(lambdaindex555, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m578) {
                  u64 v_c13 = m578[1]; u64 v_c12 = m578[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c7, v_c3, v_c2, v_c18, v_c20, v_c12, v_c9, v_c13}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask557* _cont = new ReadTask557(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask557(db,b), false);
  // (crule (pre) (scan $sup15869x25x0x0x1 __t21aQ24 __t3z1j25 __t94No27 ea eb ef va x) (body (join $sup15869x25x0x0x0 (0 1 2) 3 __t21aQ24 ea ef) (join eval_ans (0 1) 2 __t94No27 va) (join-old eval (0 1) 2 (0 1) __t3z1j25 ef) (join-old eval (0 1) 2 (0 1) __t94No27 ea) (exists lambda (2 1 0) 2 eb x) (exists eval_ans (0 1) 1 __t3z1j25) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t53Ss23) (join-old eval (0 1) 2 (0 1) __t21aQ24 __t53Ss23) (join lambda (2 1 0) 2 eb x __t4NYz26) (join eval_ans (0 1) 2 __t3z1j25 __t4NYz26) (join-old eval (1 0) 1 (1 0) eb __t65yE28) (join eval_ans (0 1) 1 __t65yE28 v)) (head (emit eval_ans (0 1) __t21aQ24 v)) 0cfa-demand.slog:26 #f)
  class ReadTask596 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x25x0x0x0index579;  slog::Index** eval_ansindex580;  slog::Index** evalindex581;  slog::Index** evalindex582;  slog::Index** lambdaindex583;  slog::Index** eval_ansindex584;  slog::Index** evalindex585;  slog::Index** appindex586;  slog::Index** evalindex587;  slog::Index** lambdaindex588;  slog::Index** eval_ansindex589;  slog::Index** evalindex590;  slog::Index** eval_ansindex591;  slog::Index** evaldelta592;  slog::Index** evaldelta593;  slog::Index** evaldelta594;  slog::Index** evaldelta595;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord597({0, 1});
      slog::Relation* readrel598 = db->getRelation("eval_ans");
      head_index[0] = readrel598->getIndex(ord597, false);
      outer_rel = db->getRelation("$sup15869x25x0x0x1");
      std::vector<u16> ord599({0, 1, 2});
      slog::Relation* readrel600 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index579 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({0, 1});
      slog::Relation* readrel602 = db->getRelation("eval_ans");
      eval_ansindex580 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({0, 1});
      slog::Relation* readrel604 = db->getRelation("eval");
      evalindex581 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({0, 1});
      slog::Relation* readrel606 = db->getRelation("eval");
      evaldelta592 = readrel606->getIndex(ord605, true);
      std::vector<u16> ord607({0, 1});
      slog::Relation* readrel608 = db->getRelation("eval");
      evalindex582 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({0, 1});
      slog::Relation* readrel610 = db->getRelation("eval");
      evaldelta593 = readrel610->getIndex(ord609, true);
      std::vector<u16> ord611({2, 1, 0});
      slog::Relation* readrel612 = db->getRelation("lambda");
      lambdaindex583 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({0, 1});
      slog::Relation* readrel614 = db->getRelation("eval_ans");
      eval_ansindex584 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 0});
      slog::Relation* readrel616 = db->getRelation("eval");
      evalindex585 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 2, 0});
      slog::Relation* readrel618 = db->getRelation("app");
      appindex586 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({0, 1});
      slog::Relation* readrel620 = db->getRelation("eval");
      evalindex587 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({0, 1});
      slog::Relation* readrel622 = db->getRelation("eval");
      evaldelta594 = readrel622->getIndex(ord621, true);
      std::vector<u16> ord623({2, 1, 0});
      slog::Relation* readrel624 = db->getRelation("lambda");
      lambdaindex588 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({0, 1});
      slog::Relation* readrel626 = db->getRelation("eval_ans");
      eval_ansindex589 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 0});
      slog::Relation* readrel628 = db->getRelation("eval");
      evalindex590 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({1, 0});
      slog::Relation* readrel630 = db->getRelation("eval");
      evaldelta595 = readrel630->getIndex(ord629, true);
      std::vector<u16> ord631({0, 1});
      slog::Relation* readrel632 = db->getRelation("eval_ans");
      eval_ansindex591 = readrel632->getIndex(ord631, false);
  
    }
    ReadTask596(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c8 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c12 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c9 = _t[6];
        u64 v_c13 = _t[7];
        slog::join_probe<3,3>($sup15869x25x0x0x0index579, std::array<u64,3>{v_c10, v_c3, v_c2}, [&](const std::array<u64,3>& m633) {
          slog::join_probe<2,2>(eval_ansindex580, std::array<u64,2>{v_c8, v_c9}, [&](const std::array<u64,2>& m634) {
            slog::join_probe_old<2,2>(evalindex581, evaldelta592, std::array<u64,2>{v_c11, v_c2}, [&](const std::array<u64,2>& m635) {
              slog::join_probe_old<2,2>(evalindex582, evaldelta593, std::array<u64,2>{v_c8, v_c3}, [&](const std::array<u64,2>& m636) {
                if (!slog::exists_probe<3,2>(lambdaindex583, std::array<u64,3>{v_c12, v_c13, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex584, std::array<u64,2>{v_c11, 0})) return;
                if (!slog::exists_probe<2,1>(evalindex585, std::array<u64,2>{v_c12, 0})) return;
                slog::join_probe<3,2>(appindex586, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m637) {
                  u64 v_c14 = m637[2];
                  slog::join_probe_old<2,2>(evalindex587, evaldelta594, std::array<u64,2>{v_c10, v_c14}, [&](const std::array<u64,2>& m638) {
                    slog::join_probe<3,2>(lambdaindex588, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m639) {
                      u64 v_c15 = m639[2];
                      slog::join_probe<2,2>(eval_ansindex589, std::array<u64,2>{v_c11, v_c15}, [&](const std::array<u64,2>& m640) {
                        slog::join_probe_old<2,1>(evalindex590, evaldelta595, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m641) {
                          u64 v_c16 = m641[1];
                          slog::join_probe<2,1>(eval_ansindex591, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m642) {
                            u64 v_c17 = m642[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:$sup15869x25x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask596* _cont = new ReadTask596(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask596(db,b), false);
  // (crule (pre) (scan eval __t2CtC44 ea) (body (exists $sup15869x25x0x0x0 (1 0 2) 1 ea) (join eval_ans (0 1) 1 __t2CtC44 va) (join $sup15869x25x0x0x0 (1 0 2) 1 ea __d0 ef) (join eval (1 0) 1 ef __t2MpD42) (join eval_ans (0 1) 1 __t2MpD42 __t1L7f43) (join lambda (0 1 2) 1 __t1L7f43 x eb)) (head (emit $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) __d0 ea ef __t2MpD42 __t2CtC44 eb va x)) 0cfa-demand.slog:26 #f)
  class ReadTask649 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x25x0x0x0index643;  slog::Index** eval_ansindex644;  slog::Index** $sup15869x25x0x0x0index645;  slog::Index** evalindex646;  slog::Index** eval_ansindex647;  slog::Index** lambdaindex648;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup15869x25x0x0x1");
      std::vector<u16> ord650({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel651 = db->getRelation("$sup15869x25x0x0x1");
      head_index[0] = readrel651->getIndex(ord650, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord652({1, 0, 2});
      slog::Relation* readrel653 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index643 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({0, 1});
      slog::Relation* readrel655 = db->getRelation("eval_ans");
      eval_ansindex644 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 0, 2});
      slog::Relation* readrel657 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index645 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 0});
      slog::Relation* readrel659 = db->getRelation("eval");
      evalindex646 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({0, 1});
      slog::Relation* readrel661 = db->getRelation("eval_ans");
      eval_ansindex647 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({0, 1, 2});
      slog::Relation* readrel663 = db->getRelation("lambda");
      lambdaindex648 = readrel663->getIndex(ord662, false);
  
    }
    ReadTask649(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<3,1>($sup15869x25x0x0x0index643, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex644, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m664) {
          u64 v_c9 = m664[1];
          slog::join_probe<3,1>($sup15869x25x0x0x0index645, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m665) {
            u64 v_c7 = m665[1]; u64 v_c2 = m665[2];
            slog::join_probe<2,1>(evalindex646, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m666) {
              u64 v_c18 = m666[1];
              slog::join_probe<2,1>(eval_ansindex647, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m667) {
                u64 v_c19 = m667[1];
                slog::join_probe<3,1>(lambdaindex648, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m668) {
                  u64 v_c13 = m668[1]; u64 v_c12 = m668[2];
                  ++_fires;
                  slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c7, v_c3, v_c2, v_c18, v_c20, v_c12, v_c9, v_c13}, std::array<u16,8>{0, 3, 5, 1, 2, 4, 6, 7});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask649* _cont = new ReadTask649(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask649(db,b), false);
  // (crule (pre (let __trid5a3R46 const1cd2976e4f4400f31114fe53) (let __trel9eIn47 const4a59dbb9cb3129dfcc75170b) (let __tcol792J48 const5feceb66ffc86f38d952786c)) (scan $sup15869x33x0x0x0 ea ef) (body) (head (tycheck ef (accept (struct app) (struct lambda) (struct ref)) __trid5a3R46 __trel9eIn47 __tcol792J48 (1 2 3 4 0)) (mkstruct eval (1 0) __9hLe45 ef)) 0cfa-demand.slog:34 #f)
  class ReadTask672 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid669;  u32 sid670;  u32 sid671;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup15869x33x0x0x0");
      sid669 = db->getRelation("app")->getStructId();
      sid670 = db->getRelation("lambda")->getStructId();
      sid671 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask672(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const1cd2976e4f4400f31114fe53;
      u64 v_c42 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c43 = v_const5feceb66ffc86f38d952786c;
  
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
        if (!((is_struct(v_c2) && (decode_struct_id(v_c2) == sid669 || decode_struct_id(v_c2) == sid670 || decode_struct_id(v_c2) == sid671))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c41, v_c42, v_c43, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:34", "delta:$sup15869x33x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask672* _cont = new ReadTask672(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask672(db,b), false);
  // (crule (pre) (scan eval_ans __t3z1j25 __t4NYz26) (body (exists $sup15869x25x0x0x1 (1 5 0 2 3 4 6 7) 1 __t3z1j25) (join-old eval (0 1) 1 (0 1) __t3z1j25 ef) (exists $sup15869x25x0x0x1 (1 5 0 2 3 4 6 7) 2 __t3z1j25 ef) (exists app (1 2 0) 1 ef) (join-old $sup15869x25x0x0x0 (2 0 1) 1 (2 0 1) ef __t21aQ24 ea) (exists eval (1 0) 1 ea) (exists app (1 2 0) 2 ef ea) (join-old $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) 4 (0 3 5 1 2 4 6 7) __t21aQ24 ea ef __t3z1j25 __t94No27 eb va x) (join lambda (2 1 0) 3 eb x __t4NYz26) (join-old eval_ans (0 1) 2 (0 1) __t94No27 va) (join-old eval (0 1) 2 (0 1) __t94No27 ea) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t53Ss23) (join-old eval (0 1) 2 (0 1) __t21aQ24 __t53Ss23) (join-old eval (1 0) 1 (1 0) eb __t65yE28) (join-old eval_ans (0 1) 1 (0 1) __t65yE28 v)) (head (emit eval_ans (0 1) __t21aQ24 v)) 0cfa-demand.slog:26 #f)
  class ReadTask697 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x25x0x0x1index673;  slog::Index** evalindex674;  slog::Index** $sup15869x25x0x0x1index675;  slog::Index** appindex676;  slog::Index** $sup15869x25x0x0x0index677;  slog::Index** evalindex678;  slog::Index** appindex679;  slog::Index** $sup15869x25x0x0x1index680;  slog::Index** lambdaindex681;  slog::Index** eval_ansindex682;  slog::Index** evalindex683;  slog::Index** evalindex684;  slog::Index** appindex685;  slog::Index** evalindex686;  slog::Index** evalindex687;  slog::Index** eval_ansindex688;  slog::Index** evaldelta689;  slog::Index** $sup15869x25x0x0x0delta690;  slog::Index** $sup15869x25x0x0x1delta691;  slog::Index** eval_ansdelta692;  slog::Index** evaldelta693;  slog::Index** evaldelta694;  slog::Index** evaldelta695;  slog::Index** eval_ansdelta696;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord698({0, 1});
      slog::Relation* readrel699 = db->getRelation("eval_ans");
      head_index[0] = readrel699->getIndex(ord698, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord700({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel701 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index673 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({0, 1});
      slog::Relation* readrel703 = db->getRelation("eval");
      evalindex674 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({0, 1});
      slog::Relation* readrel705 = db->getRelation("eval");
      evaldelta689 = readrel705->getIndex(ord704, true);
      std::vector<u16> ord706({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel707 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index675 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({1, 2, 0});
      slog::Relation* readrel709 = db->getRelation("app");
      appindex676 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({2, 0, 1});
      slog::Relation* readrel711 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index677 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({2, 0, 1});
      slog::Relation* readrel713 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0delta690 = readrel713->getIndex(ord712, true);
      std::vector<u16> ord714({1, 0});
      slog::Relation* readrel715 = db->getRelation("eval");
      evalindex678 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 2, 0});
      slog::Relation* readrel717 = db->getRelation("app");
      appindex679 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel719 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index680 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel721 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1delta691 = readrel721->getIndex(ord720, true);
      std::vector<u16> ord722({2, 1, 0});
      slog::Relation* readrel723 = db->getRelation("lambda");
      lambdaindex681 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({0, 1});
      slog::Relation* readrel725 = db->getRelation("eval_ans");
      eval_ansindex682 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({0, 1});
      slog::Relation* readrel727 = db->getRelation("eval_ans");
      eval_ansdelta692 = readrel727->getIndex(ord726, true);
      std::vector<u16> ord728({0, 1});
      slog::Relation* readrel729 = db->getRelation("eval");
      evalindex683 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({0, 1});
      slog::Relation* readrel731 = db->getRelation("eval");
      evaldelta693 = readrel731->getIndex(ord730, true);
      std::vector<u16> ord732({1, 0});
      slog::Relation* readrel733 = db->getRelation("eval");
      evalindex684 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({1, 2, 0});
      slog::Relation* readrel735 = db->getRelation("app");
      appindex685 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({0, 1});
      slog::Relation* readrel737 = db->getRelation("eval");
      evalindex686 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({0, 1});
      slog::Relation* readrel739 = db->getRelation("eval");
      evaldelta694 = readrel739->getIndex(ord738, true);
      std::vector<u16> ord740({1, 0});
      slog::Relation* readrel741 = db->getRelation("eval");
      evalindex687 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 0});
      slog::Relation* readrel743 = db->getRelation("eval");
      evaldelta695 = readrel743->getIndex(ord742, true);
      std::vector<u16> ord744({0, 1});
      slog::Relation* readrel745 = db->getRelation("eval_ans");
      eval_ansindex688 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({0, 1});
      slog::Relation* readrel747 = db->getRelation("eval_ans");
      eval_ansdelta696 = readrel747->getIndex(ord746, true);
  
    }
    ReadTask697(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[1];
        if (!slog::exists_probe<8,1>($sup15869x25x0x0x1index673, std::array<u64,8>{v_c11, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(evalindex674, evaldelta689, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m748) {
          u64 v_c2 = m748[1];
          if (!slog::exists_probe<8,2>($sup15869x25x0x0x1index675, std::array<u64,8>{v_c11, v_c2, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex676, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<3,1>($sup15869x25x0x0x0index677, $sup15869x25x0x0x0delta690, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m749) {
            u64 v_c10 = m749[1]; u64 v_c3 = m749[2];
            if (!slog::exists_probe<2,1>(evalindex678, std::array<u64,2>{v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(appindex679, std::array<u64,3>{v_c2, v_c3, 0})) return;
            slog::join_probe_old<8,4>($sup15869x25x0x0x1index680, $sup15869x25x0x0x1delta691, std::array<u64,8>{v_c10, v_c3, v_c2, v_c11, 0, 0, 0, 0}, [&](const std::array<u64,8>& m750) {
              u64 v_c8 = m750[4]; u64 v_c12 = m750[5]; u64 v_c9 = m750[6]; u64 v_c13 = m750[7];
              slog::join_probe<3,3>(lambdaindex681, std::array<u64,3>{v_c12, v_c13, v_c15}, [&](const std::array<u64,3>& m751) {
                slog::join_probe_old<2,2>(eval_ansindex682, eval_ansdelta692, std::array<u64,2>{v_c8, v_c9}, [&](const std::array<u64,2>& m752) {
                  slog::join_probe_old<2,2>(evalindex683, evaldelta693, std::array<u64,2>{v_c8, v_c3}, [&](const std::array<u64,2>& m753) {
                    if (!slog::exists_probe<2,1>(evalindex684, std::array<u64,2>{v_c12, 0})) return;
                    slog::join_probe<3,2>(appindex685, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m754) {
                      u64 v_c14 = m754[2];
                      slog::join_probe_old<2,2>(evalindex686, evaldelta694, std::array<u64,2>{v_c10, v_c14}, [&](const std::array<u64,2>& m755) {
                        slog::join_probe_old<2,1>(evalindex687, evaldelta695, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m756) {
                          u64 v_c16 = m756[1];
                          slog::join_probe_old<2,1>(eval_ansindex688, eval_ansdelta696, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m757) {
                            u64 v_c17 = m757[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask697* _cont = new ReadTask697(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask697(db,b), false);
  // (crule (pre (let __trid9N5A50 constc40db22dfb3712d9bcc7a93e) (let __trel2s9g51 const4a59dbb9cb3129dfcc75170b) (let __tcol81Vg52 const5feceb66ffc86f38d952786c)) (scan $sup15869x25x0x0x0 __d0 ea ef) (body) (head (tycheck ef (accept (struct app) (struct lambda) (struct ref)) __trid9N5A50 __trel2s9g51 __tcol81Vg52 (1 2 3 4 0)) (mkstruct eval (1 0) __88Cr49 ef)) 0cfa-demand.slog:26 #f)
  class ReadTask761 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid758;  u32 sid759;  u32 sid760;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup15869x25x0x0x0");
      sid758 = db->getRelation("app")->getStructId();
      sid759 = db->getRelation("lambda")->getStructId();
      sid760 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask761(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_constc40db22dfb3712d9bcc7a93e;
      u64 v_c45 = v_const4a59dbb9cb3129dfcc75170b;
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
        u64 v_c7 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        ++_fires;
        if (!((is_struct(v_c2) && (decode_struct_id(v_c2) == sid758 || decode_struct_id(v_c2) == sid759 || decode_struct_id(v_c2) == sid760))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c44, v_c45, v_c46, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:$sup15869x25x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask761* _cont = new ReadTask761(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask761(db,b), false);
  // (crule (pre (let __trid3cNF61 const1cd2976e4f4400f31114fe53) (let __trel695h62 const4a59dbb9cb3129dfcc75170b) (let __tcol3kHI63 const5feceb66ffc86f38d952786c)) (scan $sup15869x33x0x0x0 ea ef) (body) (head (tycheck ea (accept (struct app) (struct lambda) (struct ref)) __trid3cNF61 __trel695h62 __tcol3kHI63 (1 2 3 4 0)) (mkstruct eval (1 0) __6Xew60 ea)) 0cfa-demand.slog:34 #f)
  class ReadTask765 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid762;  u32 sid763;  u32 sid764;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup15869x33x0x0x0");
      sid762 = db->getRelation("app")->getStructId();
      sid763 = db->getRelation("lambda")->getStructId();
      sid764 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask765(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_const1cd2976e4f4400f31114fe53;
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
        u64 v_c3 = _t[0];
        u64 v_c2 = _t[1];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid762 || decode_struct_id(v_c3) == sid763 || decode_struct_id(v_c3) == sid764))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c47, v_c48, v_c49, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:34", "delta:$sup15869x33x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask765* _cont = new ReadTask765(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask765(db,b), false);
  // (crule (pre) (scan eval_ans __t65yE28 v) (body (join-old eval (0 1) 1 (0 1) __t65yE28 eb) (exists $sup15869x25x0x0x1 (4 7 1 0 2 3 5 6) 1 eb) (join lambda (2 1 0) 1 eb x __t4NYz26) (exists $sup15869x25x0x0x1 (4 7 1 0 2 3 5 6) 2 eb x) (join eval_ans (1 0) 1 __t4NYz26 __t3z1j25) (join-old $sup15869x25x0x0x1 (4 7 1 0 2 3 5 6) 3 (4 7 1 0 2 3 5 6) eb x __t3z1j25 __t21aQ24 __t94No27 ea ef va) (join-old $sup15869x25x0x0x0 (0 1 2) 3 (0 1 2) __t21aQ24 ea ef) (join eval_ans (0 1) 2 __t94No27 va) (join-old eval (0 1) 2 (0 1) __t3z1j25 ef) (join-old eval (0 1) 2 (0 1) __t94No27 ea) (join app (1 2 0) 2 ef ea __t53Ss23) (join-old eval (0 1) 2 (0 1) __t21aQ24 __t53Ss23)) (head (emit eval_ans (0 1) __t21aQ24 v)) 0cfa-demand.slog:26 #f)
  class ReadTask784 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex766;  slog::Index** $sup15869x25x0x0x1index767;  slog::Index** lambdaindex768;  slog::Index** $sup15869x25x0x0x1index769;  slog::Index** eval_ansindex770;  slog::Index** $sup15869x25x0x0x1index771;  slog::Index** $sup15869x25x0x0x0index772;  slog::Index** eval_ansindex773;  slog::Index** evalindex774;  slog::Index** evalindex775;  slog::Index** appindex776;  slog::Index** evalindex777;  slog::Index** evaldelta778;  slog::Index** $sup15869x25x0x0x1delta779;  slog::Index** $sup15869x25x0x0x0delta780;  slog::Index** evaldelta781;  slog::Index** evaldelta782;  slog::Index** evaldelta783;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord785({0, 1});
      slog::Relation* readrel786 = db->getRelation("eval_ans");
      head_index[0] = readrel786->getIndex(ord785, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord787({0, 1});
      slog::Relation* readrel788 = db->getRelation("eval");
      evalindex766 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({0, 1});
      slog::Relation* readrel790 = db->getRelation("eval");
      evaldelta778 = readrel790->getIndex(ord789, true);
      std::vector<u16> ord791({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel792 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index767 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({2, 1, 0});
      slog::Relation* readrel794 = db->getRelation("lambda");
      lambdaindex768 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel796 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index769 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({1, 0});
      slog::Relation* readrel798 = db->getRelation("eval_ans");
      eval_ansindex770 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel800 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index771 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({4, 7, 1, 0, 2, 3, 5, 6});
      slog::Relation* readrel802 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1delta779 = readrel802->getIndex(ord801, true);
      std::vector<u16> ord803({0, 1, 2});
      slog::Relation* readrel804 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index772 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({0, 1, 2});
      slog::Relation* readrel806 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0delta780 = readrel806->getIndex(ord805, true);
      std::vector<u16> ord807({0, 1});
      slog::Relation* readrel808 = db->getRelation("eval_ans");
      eval_ansindex773 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({0, 1});
      slog::Relation* readrel810 = db->getRelation("eval");
      evalindex774 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({0, 1});
      slog::Relation* readrel812 = db->getRelation("eval");
      evaldelta781 = readrel812->getIndex(ord811, true);
      std::vector<u16> ord813({0, 1});
      slog::Relation* readrel814 = db->getRelation("eval");
      evalindex775 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({0, 1});
      slog::Relation* readrel816 = db->getRelation("eval");
      evaldelta782 = readrel816->getIndex(ord815, true);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("app");
      appindex776 = readrel818->getIndex(ord817, false);
      std::vector<u16> ord819({0, 1});
      slog::Relation* readrel820 = db->getRelation("eval");
      evalindex777 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({0, 1});
      slog::Relation* readrel822 = db->getRelation("eval");
      evaldelta783 = readrel822->getIndex(ord821, true);
  
    }
    ReadTask784(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        slog::join_probe_old<2,1>(evalindex766, evaldelta778, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m823) {
          u64 v_c12 = m823[1];
          if (!slog::exists_probe<8,1>($sup15869x25x0x0x1index767, std::array<u64,8>{v_c12, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<3,1>(lambdaindex768, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m824) {
            u64 v_c13 = m824[1]; u64 v_c15 = m824[2];
            if (!slog::exists_probe<8,2>($sup15869x25x0x0x1index769, std::array<u64,8>{v_c12, v_c13, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<2,1>(eval_ansindex770, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m825) {
              u64 v_c11 = m825[1];
              slog::join_probe_old<8,3>($sup15869x25x0x0x1index771, $sup15869x25x0x0x1delta779, std::array<u64,8>{v_c12, v_c13, v_c11, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m826) {
                u64 v_c10 = m826[3]; u64 v_c8 = m826[4]; u64 v_c3 = m826[5]; u64 v_c2 = m826[6]; u64 v_c9 = m826[7];
                slog::join_probe_old<3,3>($sup15869x25x0x0x0index772, $sup15869x25x0x0x0delta780, std::array<u64,3>{v_c10, v_c3, v_c2}, [&](const std::array<u64,3>& m827) {
                  slog::join_probe<2,2>(eval_ansindex773, std::array<u64,2>{v_c8, v_c9}, [&](const std::array<u64,2>& m828) {
                    slog::join_probe_old<2,2>(evalindex774, evaldelta781, std::array<u64,2>{v_c11, v_c2}, [&](const std::array<u64,2>& m829) {
                      slog::join_probe_old<2,2>(evalindex775, evaldelta782, std::array<u64,2>{v_c8, v_c3}, [&](const std::array<u64,2>& m830) {
                        slog::join_probe<3,2>(appindex776, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m831) {
                          u64 v_c14 = m831[2];
                          slog::join_probe_old<2,2>(evalindex777, evaldelta783, std::array<u64,2>{v_c10, v_c14}, [&](const std::array<u64,2>& m832) {
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask784* _cont = new ReadTask784(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask784(db,b), false);
  // (crule (pre) (scan eval_ans __t1miS31 __t2kGk32) (body (join-old eval (0 1) 1 (0 1) __t1miS31 ef) (exists app (1 2 0) 1 ef) (join-old $sup15869x33x0x0x0 (1 0) 1 (1 0) ef ea) (exists eval (1 0) 1 ea) (join app (1 2 0) 2 ef ea __t5UcN30) (join eval (1 0) 1 __t5UcN30 __6Yjj70) (join-old eval (1 0) 1 (1 0) ea __t5Tar33) (join-old eval_ans (0 1) 1 (0 1) __t5Tar33 va) (join lambda (0 1 2) 1 __t2kGk32 x eb)) (head (emit store (0 1) x va)) 0cfa-demand.slog:34 #f)
  class ReadTask846 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex833;  slog::Index** appindex834;  slog::Index** $sup15869x33x0x0x0index835;  slog::Index** evalindex836;  slog::Index** appindex837;  slog::Index** evalindex838;  slog::Index** evalindex839;  slog::Index** eval_ansindex840;  slog::Index** lambdaindex841;  slog::Index** evaldelta842;  slog::Index** $sup15869x33x0x0x0delta843;  slog::Index** evaldelta844;  slog::Index** eval_ansdelta845;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord847({0, 1});
      slog::Relation* readrel848 = db->getRelation("store");
      head_index[0] = readrel848->getIndex(ord847, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord849({0, 1});
      slog::Relation* readrel850 = db->getRelation("eval");
      evalindex833 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({0, 1});
      slog::Relation* readrel852 = db->getRelation("eval");
      evaldelta842 = readrel852->getIndex(ord851, true);
      std::vector<u16> ord853({1, 2, 0});
      slog::Relation* readrel854 = db->getRelation("app");
      appindex834 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 0});
      slog::Relation* readrel856 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0index835 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 0});
      slog::Relation* readrel858 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0delta843 = readrel858->getIndex(ord857, true);
      std::vector<u16> ord859({1, 0});
      slog::Relation* readrel860 = db->getRelation("eval");
      evalindex836 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 2, 0});
      slog::Relation* readrel862 = db->getRelation("app");
      appindex837 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({1, 0});
      slog::Relation* readrel864 = db->getRelation("eval");
      evalindex838 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({1, 0});
      slog::Relation* readrel866 = db->getRelation("eval");
      evalindex839 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({1, 0});
      slog::Relation* readrel868 = db->getRelation("eval");
      evaldelta844 = readrel868->getIndex(ord867, true);
      std::vector<u16> ord869({0, 1});
      slog::Relation* readrel870 = db->getRelation("eval_ans");
      eval_ansindex840 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({0, 1});
      slog::Relation* readrel872 = db->getRelation("eval_ans");
      eval_ansdelta845 = readrel872->getIndex(ord871, true);
      std::vector<u16> ord873({0, 1, 2});
      slog::Relation* readrel874 = db->getRelation("lambda");
      lambdaindex841 = readrel874->getIndex(ord873, false);
  
    }
    ReadTask846(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(evalindex833, evaldelta842, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m875) {
          u64 v_c2 = m875[1];
          if (!slog::exists_probe<3,1>(appindex834, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<2,1>($sup15869x33x0x0x0index835, $sup15869x33x0x0x0delta843, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m876) {
            u64 v_c3 = m876[1];
            if (!slog::exists_probe<2,1>(evalindex836, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe<3,2>(appindex837, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m877) {
              u64 v_c26 = m877[2];
              slog::join_probe<2,1>(evalindex838, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m878) {
                u64 v_c25 = m878[1];
                slog::join_probe_old<2,1>(evalindex839, evaldelta844, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m879) {
                  u64 v_c29 = m879[1];
                  slog::join_probe_old<2,1>(eval_ansindex840, eval_ansdelta845, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m880) {
                    u64 v_c9 = m880[1];
                    slog::join_probe<3,1>(lambdaindex841, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m881) {
                      u64 v_c13 = m881[1]; u64 v_c12 = m881[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c9}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:34", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask846* _cont = new ReadTask846(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask846(db,b), false);
  // (crule (pre) (scan eval __t3z1j25 ef) (body (exists $sup15869x25x0x0x0 (2 0 1) 1 ef) (exists $sup15869x25x0x0x1 (1 5 0 2 3 4 6 7) 2 __t3z1j25 ef) (exists app (1 2 0) 1 ef) (join eval_ans (0 1) 1 __t3z1j25 __t4NYz26) (join $sup15869x25x0x0x0 (2 0 1) 1 ef __t21aQ24 ea) (exists eval (1 0) 1 ea) (exists app (1 2 0) 2 ef ea) (join $sup15869x25x0x0x1 (0 3 5 1 2 4 6 7) 4 __t21aQ24 ea ef __t3z1j25 __t94No27 eb va x) (join lambda (2 1 0) 3 eb x __t4NYz26) (join eval_ans (0 1) 2 __t94No27 va) (join-old eval (0 1) 2 (0 1) __t94No27 ea) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t53Ss23) (join eval (0 1) 2 __t21aQ24 __t53Ss23) (join-old eval (1 0) 1 (1 0) eb __t65yE28) (join eval_ans (0 1) 1 __t65yE28 v)) (head (emit eval_ans (0 1) __t21aQ24 v)) 0cfa-demand.slog:26 #f)
  class ReadTask900 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x25x0x0x0index882;  slog::Index** $sup15869x25x0x0x1index883;  slog::Index** appindex884;  slog::Index** eval_ansindex885;  slog::Index** $sup15869x25x0x0x0index886;  slog::Index** evalindex887;  slog::Index** appindex888;  slog::Index** $sup15869x25x0x0x1index889;  slog::Index** lambdaindex890;  slog::Index** eval_ansindex891;  slog::Index** evalindex892;  slog::Index** evalindex893;  slog::Index** appindex894;  slog::Index** evalindex895;  slog::Index** evalindex896;  slog::Index** eval_ansindex897;  slog::Index** evaldelta898;  slog::Index** evaldelta899;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord901({0, 1});
      slog::Relation* readrel902 = db->getRelation("eval_ans");
      head_index[0] = readrel902->getIndex(ord901, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord903({2, 0, 1});
      slog::Relation* readrel904 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index882 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel906 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index883 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({1, 2, 0});
      slog::Relation* readrel908 = db->getRelation("app");
      appindex884 = readrel908->getIndex(ord907, false);
      std::vector<u16> ord909({0, 1});
      slog::Relation* readrel910 = db->getRelation("eval_ans");
      eval_ansindex885 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({2, 0, 1});
      slog::Relation* readrel912 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index886 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({1, 0});
      slog::Relation* readrel914 = db->getRelation("eval");
      evalindex887 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({1, 2, 0});
      slog::Relation* readrel916 = db->getRelation("app");
      appindex888 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({0, 3, 5, 1, 2, 4, 6, 7});
      slog::Relation* readrel918 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index889 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({2, 1, 0});
      slog::Relation* readrel920 = db->getRelation("lambda");
      lambdaindex890 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({0, 1});
      slog::Relation* readrel922 = db->getRelation("eval_ans");
      eval_ansindex891 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({0, 1});
      slog::Relation* readrel924 = db->getRelation("eval");
      evalindex892 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({0, 1});
      slog::Relation* readrel926 = db->getRelation("eval");
      evaldelta898 = readrel926->getIndex(ord925, true);
      std::vector<u16> ord927({1, 0});
      slog::Relation* readrel928 = db->getRelation("eval");
      evalindex893 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({1, 2, 0});
      slog::Relation* readrel930 = db->getRelation("app");
      appindex894 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({0, 1});
      slog::Relation* readrel932 = db->getRelation("eval");
      evalindex895 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({1, 0});
      slog::Relation* readrel934 = db->getRelation("eval");
      evalindex896 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({1, 0});
      slog::Relation* readrel936 = db->getRelation("eval");
      evaldelta899 = readrel936->getIndex(ord935, true);
      std::vector<u16> ord937({0, 1});
      slog::Relation* readrel938 = db->getRelation("eval_ans");
      eval_ansindex897 = readrel938->getIndex(ord937, false);
  
    }
    ReadTask900(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<3,1>($sup15869x25x0x0x0index882, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<8,2>($sup15869x25x0x0x1index883, std::array<u64,8>{v_c11, v_c2, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex884, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex885, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m939) {
          u64 v_c15 = m939[1];
          slog::join_probe<3,1>($sup15869x25x0x0x0index886, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m940) {
            u64 v_c10 = m940[1]; u64 v_c3 = m940[2];
            if (!slog::exists_probe<2,1>(evalindex887, std::array<u64,2>{v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(appindex888, std::array<u64,3>{v_c2, v_c3, 0})) return;
            slog::join_probe<8,4>($sup15869x25x0x0x1index889, std::array<u64,8>{v_c10, v_c3, v_c2, v_c11, 0, 0, 0, 0}, [&](const std::array<u64,8>& m941) {
              u64 v_c8 = m941[4]; u64 v_c12 = m941[5]; u64 v_c9 = m941[6]; u64 v_c13 = m941[7];
              slog::join_probe<3,3>(lambdaindex890, std::array<u64,3>{v_c12, v_c13, v_c15}, [&](const std::array<u64,3>& m942) {
                slog::join_probe<2,2>(eval_ansindex891, std::array<u64,2>{v_c8, v_c9}, [&](const std::array<u64,2>& m943) {
                  slog::join_probe_old<2,2>(evalindex892, evaldelta898, std::array<u64,2>{v_c8, v_c3}, [&](const std::array<u64,2>& m944) {
                    if (!slog::exists_probe<2,1>(evalindex893, std::array<u64,2>{v_c12, 0})) return;
                    slog::join_probe<3,2>(appindex894, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m945) {
                      u64 v_c14 = m945[2];
                      slog::join_probe<2,2>(evalindex895, std::array<u64,2>{v_c10, v_c14}, [&](const std::array<u64,2>& m946) {
                        slog::join_probe_old<2,1>(evalindex896, evaldelta899, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m947) {
                          u64 v_c16 = m947[1];
                          slog::join_probe<2,1>(eval_ansindex897, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m948) {
                            u64 v_c17 = m948[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask900* _cont = new ReadTask900(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask900(db,b), false);
  // (crule (pre (let __trid2tkt57 constc40db22dfb3712d9bcc7a93e) (let __trel6S3p58 const4a59dbb9cb3129dfcc75170b) (let __tcol0QTn59 const5feceb66ffc86f38d952786c)) (scan $sup15869x25x0x0x1 __d0 __d1 __d2 ea eb ef va x) (body) (head (tycheck eb (accept (struct app) (struct lambda) (struct ref)) __trid2tkt57 __trel6S3p58 __tcol0QTn59 (1 2 3 4 0)) (mkstruct eval (1 0) __3aFP56 eb)) 0cfa-demand.slog:26 #f)
  class ReadTask952 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid949;  u32 sid950;  u32 sid951;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup15869x25x0x0x1");
      sid949 = db->getRelation("app")->getStructId();
      sid950 = db->getRelation("lambda")->getStructId();
      sid951 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask952(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c50 = v_constc40db22dfb3712d9bcc7a93e;
      u64 v_c51 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c52 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c7 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c54 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c12 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c9 = _t[6];
        u64 v_c13 = _t[7];
        ++_fires;
        if (!((is_struct(v_c12) && (decode_struct_id(v_c12) == sid949 || decode_struct_id(v_c12) == sid950 || decode_struct_id(v_c12) == sid951))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c50, v_c51, v_c52, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:$sup15869x25x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask952* _cont = new ReadTask952(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask952(db,b), false);
  // (crule (pre) (scan store x v) (body (join ref (1 0) 1 x __t2Ncr34) (join-old eval (1 0) 1 (1 0) __t2Ncr34 __t7NXF35)) (head (emit eval_ans (0 1) __t7NXF35 v)) 0cfa-demand.slog:23 #f)
  class ReadTask956 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex953;  slog::Index** evalindex954;  slog::Index** evaldelta955;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord957({0, 1});
      slog::Relation* readrel958 = db->getRelation("eval_ans");
      head_index[0] = readrel958->getIndex(ord957, false);
      outer_rel = db->getRelation("store");
      std::vector<u16> ord959({1, 0});
      slog::Relation* readrel960 = db->getRelation("ref");
      refindex953 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 0});
      slog::Relation* readrel962 = db->getRelation("eval");
      evalindex954 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 0});
      slog::Relation* readrel964 = db->getRelation("eval");
      evaldelta955 = readrel964->getIndex(ord963, true);
  
    }
    ReadTask956(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[0];
        u64 v_c17 = _t[1];
        slog::join_probe<2,1>(refindex953, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m965) {
          u64 v_c22 = m965[1];
          slog::join_probe_old<2,1>(evalindex954, evaldelta955, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m966) {
            u64 v_c21 = m966[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c17}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:23", "delta:store", _fires);
  
      if (!_done)
      {
        ReadTask956* _cont = new ReadTask956(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask956(db,b), false);
  // (crule (pre) (scan eval __t94No27 ea) (body (exists $sup15869x25x0x0x1 (2 3 6 0 1 4 5 7) 2 __t94No27 ea) (exists $sup15869x25x0x0x0 (1 0 2) 1 ea) (exists app (2 0 1) 1 ea) (join eval_ans (0 1) 1 __t94No27 va) (join $sup15869x25x0x0x1 (2 3 6 0 1 4 5 7) 3 __t94No27 ea va __t21aQ24 __t3z1j25 eb ef x) (join $sup15869x25x0x0x0 (0 1 2) 3 __t21aQ24 ea ef) (join eval (0 1) 2 __t3z1j25 ef) (exists lambda (2 1 0) 2 eb x) (exists eval_ans (0 1) 1 __t3z1j25) (exists eval (1 0) 1 eb) (join app (1 2 0) 2 ef ea __t53Ss23) (join eval (0 1) 2 __t21aQ24 __t53Ss23) (join lambda (2 1 0) 2 eb x __t4NYz26) (join eval_ans (0 1) 2 __t3z1j25 __t4NYz26) (join-old eval (1 0) 1 (1 0) eb __t65yE28) (join eval_ans (0 1) 1 __t65yE28 v)) (head (emit eval_ans (0 1) __t21aQ24 v)) 0cfa-demand.slog:26 #f)
  class ReadTask984 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x25x0x0x1index967;  slog::Index** $sup15869x25x0x0x0index968;  slog::Index** appindex969;  slog::Index** eval_ansindex970;  slog::Index** $sup15869x25x0x0x1index971;  slog::Index** $sup15869x25x0x0x0index972;  slog::Index** evalindex973;  slog::Index** lambdaindex974;  slog::Index** eval_ansindex975;  slog::Index** evalindex976;  slog::Index** appindex977;  slog::Index** evalindex978;  slog::Index** lambdaindex979;  slog::Index** eval_ansindex980;  slog::Index** evalindex981;  slog::Index** eval_ansindex982;  slog::Index** evaldelta983;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord985({0, 1});
      slog::Relation* readrel986 = db->getRelation("eval_ans");
      head_index[0] = readrel986->getIndex(ord985, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord987({2, 3, 6, 0, 1, 4, 5, 7});
      slog::Relation* readrel988 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index967 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({1, 0, 2});
      slog::Relation* readrel990 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index968 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({2, 0, 1});
      slog::Relation* readrel992 = db->getRelation("app");
      appindex969 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({0, 1});
      slog::Relation* readrel994 = db->getRelation("eval_ans");
      eval_ansindex970 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({2, 3, 6, 0, 1, 4, 5, 7});
      slog::Relation* readrel996 = db->getRelation("$sup15869x25x0x0x1");
      $sup15869x25x0x0x1index971 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({0, 1, 2});
      slog::Relation* readrel998 = db->getRelation("$sup15869x25x0x0x0");
      $sup15869x25x0x0x0index972 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({0, 1});
      slog::Relation* readrel1000 = db->getRelation("eval");
      evalindex973 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({2, 1, 0});
      slog::Relation* readrel1002 = db->getRelation("lambda");
      lambdaindex974 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({0, 1});
      slog::Relation* readrel1004 = db->getRelation("eval_ans");
      eval_ansindex975 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({1, 0});
      slog::Relation* readrel1006 = db->getRelation("eval");
      evalindex976 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({1, 2, 0});
      slog::Relation* readrel1008 = db->getRelation("app");
      appindex977 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({0, 1});
      slog::Relation* readrel1010 = db->getRelation("eval");
      evalindex978 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({2, 1, 0});
      slog::Relation* readrel1012 = db->getRelation("lambda");
      lambdaindex979 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({0, 1});
      slog::Relation* readrel1014 = db->getRelation("eval_ans");
      eval_ansindex980 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({1, 0});
      slog::Relation* readrel1016 = db->getRelation("eval");
      evalindex981 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({1, 0});
      slog::Relation* readrel1018 = db->getRelation("eval");
      evaldelta983 = readrel1018->getIndex(ord1017, true);
      std::vector<u16> ord1019({0, 1});
      slog::Relation* readrel1020 = db->getRelation("eval_ans");
      eval_ansindex982 = readrel1020->getIndex(ord1019, false);
  
    }
    ReadTask984(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<8,2>($sup15869x25x0x0x1index967, std::array<u64,8>{v_c8, v_c3, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>($sup15869x25x0x0x0index968, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex969, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex970, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m1021) {
          u64 v_c9 = m1021[1];
          slog::join_probe<8,3>($sup15869x25x0x0x1index971, std::array<u64,8>{v_c8, v_c3, v_c9, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m1022) {
            u64 v_c10 = m1022[3]; u64 v_c11 = m1022[4]; u64 v_c12 = m1022[5]; u64 v_c2 = m1022[6]; u64 v_c13 = m1022[7];
            slog::join_probe<3,3>($sup15869x25x0x0x0index972, std::array<u64,3>{v_c10, v_c3, v_c2}, [&](const std::array<u64,3>& m1023) {
              slog::join_probe<2,2>(evalindex973, std::array<u64,2>{v_c11, v_c2}, [&](const std::array<u64,2>& m1024) {
                if (!slog::exists_probe<3,2>(lambdaindex974, std::array<u64,3>{v_c12, v_c13, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex975, std::array<u64,2>{v_c11, 0})) return;
                if (!slog::exists_probe<2,1>(evalindex976, std::array<u64,2>{v_c12, 0})) return;
                slog::join_probe<3,2>(appindex977, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m1025) {
                  u64 v_c14 = m1025[2];
                  slog::join_probe<2,2>(evalindex978, std::array<u64,2>{v_c10, v_c14}, [&](const std::array<u64,2>& m1026) {
                    slog::join_probe<3,2>(lambdaindex979, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m1027) {
                      u64 v_c15 = m1027[2];
                      slog::join_probe<2,2>(eval_ansindex980, std::array<u64,2>{v_c11, v_c15}, [&](const std::array<u64,2>& m1028) {
                        slog::join_probe_old<2,1>(evalindex981, evaldelta983, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m1029) {
                          u64 v_c16 = m1029[1];
                          slog::join_probe<2,1>(eval_ansindex982, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m1030) {
                            u64 v_c17 = m1030[1];
                            ++_fires;
                            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("0cfa-demand.slog:26", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask984* _cont = new ReadTask984(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask984(db,b), false);
  // (crule (pre) (scan $sup15869x33x0x0x0 ea ef) (body (exists eval (1 0) 1 ef) (exists eval (1 0) 1 ea) (join app (1 2 0) 2 ef ea __t5UcN30) (join eval (1 0) 1 __t5UcN30 __6Yjj70) (join-old eval (1 0) 1 (1 0) ef __t1miS31) (join eval_ans (0 1) 1 __t1miS31 __t2kGk32) (join-old eval (1 0) 1 (1 0) ea __t5Tar33) (join eval_ans (0 1) 1 __t5Tar33 va) (join lambda (0 1 2) 1 __t2kGk32 x eb)) (head (emit store (0 1) x va)) 0cfa-demand.slog:34 #f)
  class ReadTask1042 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1031;  slog::Index** evalindex1032;  slog::Index** appindex1033;  slog::Index** evalindex1034;  slog::Index** evalindex1035;  slog::Index** eval_ansindex1036;  slog::Index** evalindex1037;  slog::Index** eval_ansindex1038;  slog::Index** lambdaindex1039;  slog::Index** evaldelta1040;  slog::Index** evaldelta1041;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord1043({0, 1});
      slog::Relation* readrel1044 = db->getRelation("store");
      head_index[0] = readrel1044->getIndex(ord1043, false);
      outer_rel = db->getRelation("$sup15869x33x0x0x0");
      std::vector<u16> ord1045({1, 0});
      slog::Relation* readrel1046 = db->getRelation("eval");
      evalindex1031 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({1, 0});
      slog::Relation* readrel1048 = db->getRelation("eval");
      evalindex1032 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({1, 2, 0});
      slog::Relation* readrel1050 = db->getRelation("app");
      appindex1033 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({1, 0});
      slog::Relation* readrel1052 = db->getRelation("eval");
      evalindex1034 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({1, 0});
      slog::Relation* readrel1054 = db->getRelation("eval");
      evalindex1035 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({1, 0});
      slog::Relation* readrel1056 = db->getRelation("eval");
      evaldelta1040 = readrel1056->getIndex(ord1055, true);
      std::vector<u16> ord1057({0, 1});
      slog::Relation* readrel1058 = db->getRelation("eval_ans");
      eval_ansindex1036 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({1, 0});
      slog::Relation* readrel1060 = db->getRelation("eval");
      evalindex1037 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({1, 0});
      slog::Relation* readrel1062 = db->getRelation("eval");
      evaldelta1041 = readrel1062->getIndex(ord1061, true);
      std::vector<u16> ord1063({0, 1});
      slog::Relation* readrel1064 = db->getRelation("eval_ans");
      eval_ansindex1038 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({0, 1, 2});
      slog::Relation* readrel1066 = db->getRelation("lambda");
      lambdaindex1039 = readrel1066->getIndex(ord1065, false);
  
    }
    ReadTask1042(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<2,1>(evalindex1031, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(evalindex1032, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<3,2>(appindex1033, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m1067) {
          u64 v_c26 = m1067[2];
          slog::join_probe<2,1>(evalindex1034, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m1068) {
            u64 v_c25 = m1068[1];
            slog::join_probe_old<2,1>(evalindex1035, evaldelta1040, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m1069) {
              u64 v_c27 = m1069[1];
              slog::join_probe<2,1>(eval_ansindex1036, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1070) {
                u64 v_c28 = m1070[1];
                slog::join_probe_old<2,1>(evalindex1037, evaldelta1041, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m1071) {
                  u64 v_c29 = m1071[1];
                  slog::join_probe<2,1>(eval_ansindex1038, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m1072) {
                    u64 v_c9 = m1072[1];
                    slog::join_probe<3,1>(lambdaindex1039, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m1073) {
                      u64 v_c13 = m1073[1]; u64 v_c12 = m1073[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c9}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:34", "delta:$sup15869x33x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1042* _cont = new ReadTask1042(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1042(db,b), false);
  // (crule (pre) (scan eval __t1miS31 ef) (body (exists $sup15869x33x0x0x0 (1 0) 1 ef) (exists app (1 2 0) 1 ef) (join eval_ans (0 1) 1 __t1miS31 __t2kGk32) (join $sup15869x33x0x0x0 (1 0) 1 ef ea) (exists eval (1 0) 1 ea) (join app (1 2 0) 2 ef ea __t5UcN30) (join eval (1 0) 1 __t5UcN30 __6Yjj70) (join-old eval (1 0) 1 (1 0) ea __t5Tar33) (join eval_ans (0 1) 1 __t5Tar33 va) (join lambda (0 1 2) 1 __t2kGk32 x eb)) (head (emit store (0 1) x va)) 0cfa-demand.slog:34 #f)
  class ReadTask1085 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup15869x33x0x0x0index1074;  slog::Index** appindex1075;  slog::Index** eval_ansindex1076;  slog::Index** $sup15869x33x0x0x0index1077;  slog::Index** evalindex1078;  slog::Index** appindex1079;  slog::Index** evalindex1080;  slog::Index** evalindex1081;  slog::Index** eval_ansindex1082;  slog::Index** lambdaindex1083;  slog::Index** evaldelta1084;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord1086({0, 1});
      slog::Relation* readrel1087 = db->getRelation("store");
      head_index[0] = readrel1087->getIndex(ord1086, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1088({1, 0});
      slog::Relation* readrel1089 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0index1074 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({1, 2, 0});
      slog::Relation* readrel1091 = db->getRelation("app");
      appindex1075 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({0, 1});
      slog::Relation* readrel1093 = db->getRelation("eval_ans");
      eval_ansindex1076 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({1, 0});
      slog::Relation* readrel1095 = db->getRelation("$sup15869x33x0x0x0");
      $sup15869x33x0x0x0index1077 = readrel1095->getIndex(ord1094, false);
      std::vector<u16> ord1096({1, 0});
      slog::Relation* readrel1097 = db->getRelation("eval");
      evalindex1078 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({1, 2, 0});
      slog::Relation* readrel1099 = db->getRelation("app");
      appindex1079 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 0});
      slog::Relation* readrel1101 = db->getRelation("eval");
      evalindex1080 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({1, 0});
      slog::Relation* readrel1103 = db->getRelation("eval");
      evalindex1081 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({1, 0});
      slog::Relation* readrel1105 = db->getRelation("eval");
      evaldelta1084 = readrel1105->getIndex(ord1104, true);
      std::vector<u16> ord1106({0, 1});
      slog::Relation* readrel1107 = db->getRelation("eval_ans");
      eval_ansindex1082 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({0, 1, 2});
      slog::Relation* readrel1109 = db->getRelation("lambda");
      lambdaindex1083 = readrel1109->getIndex(ord1108, false);
  
    }
    ReadTask1085(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<2,1>($sup15869x33x0x0x0index1074, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1075, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex1076, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1110) {
          u64 v_c28 = m1110[1];
          slog::join_probe<2,1>($sup15869x33x0x0x0index1077, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m1111) {
            u64 v_c3 = m1111[1];
            if (!slog::exists_probe<2,1>(evalindex1078, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe<3,2>(appindex1079, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m1112) {
              u64 v_c26 = m1112[2];
              slog::join_probe<2,1>(evalindex1080, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m1113) {
                u64 v_c25 = m1113[1];
                slog::join_probe_old<2,1>(evalindex1081, evaldelta1084, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m1114) {
                  u64 v_c29 = m1114[1];
                  slog::join_probe<2,1>(eval_ansindex1082, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m1115) {
                    u64 v_c9 = m1115[1];
                    slog::join_probe<3,1>(lambdaindex1083, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m1116) {
                      u64 v_c13 = m1116[1]; u64 v_c12 = m1116[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c9}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-demand.slog:34", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1085* _cont = new ReadTask1085(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1085(db,b), false);
  s->addReadRel("$sup15869x25x0x0x0");
  s->addReadRel("$sup15869x25x0x0x1");
  s->addReadRel("$sup15869x33x0x0x0");
  s->addReadRel("app");
  s->addReadRel("eval");
  s->addReadRel("eval_ans");
  s->addReadRel("lambda");
  s->addReadRel("malformed_deduction");
  s->addReadRel("program");
  s->addReadRel("ref");
  s->addReadRel("store");
  s->addDynamicRel("$sup15869x25x0x0x0");
  s->addDynamicRel("$sup15869x25x0x0x1");
  s->addDynamicRel("$sup15869x33x0x0x0");
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

