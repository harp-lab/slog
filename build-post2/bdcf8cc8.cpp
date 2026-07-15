
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constef2d127de37b942baad06145;
u64 v_consta221beeaebe583607e193be7;
u64 v_constab76c7d069d6f33dc950fb33;
u64 v_consteb8bf0d80db323992f6b634a;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constba2df4903a2c14e86dc3bcca;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("bdcf8cc8");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_consta221beeaebe583607e193be7 = db->encodeString("unsat");
  v_constab76c7d069d6f33dc950fb33 = db->encodeString("sat");
  v_consteb8bf0d80db323992f6b634a = db->encodeString("unknown");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constba2df4903a2c14e86dc3bcca = db->encodeString("x");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord245({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord245, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord246({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord247({1, 2, 0});
    
    r->addIndex<3>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord248({0, 1, 2});
    
    r->addIndex<3>(ord248, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp90IM201");
  if (r == 0) db->addTempRelation("temp90IM201", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8yp4199");
  if (r == 0) db->addTempRelation("temp8yp4199", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp808U196");
  if (r == 0) db->addTempRelation("temp808U196", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7m9a205");
  if (r == 0) db->addTempRelation("temp7m9a205", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6cMZ198");
  if (r == 0) db->addTempRelation("temp6cMZ198", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6ELz197");
  if (r == 0) db->addTempRelation("temp6ELz197", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp69SI193");
  if (r == 0) db->addTempRelation("temp69SI193", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp51A0202");
  if (r == 0) db->addTempRelation("temp51A0202", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2qZE200");
  if (r == 0) db->addTempRelation("temp2qZE200", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp25QL203");
  if (r == 0) db->addTempRelation("temp25QL203", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1rZt206");
  if (r == 0) db->addTempRelation("temp1rZt206", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp0vJ7195");
  if (r == 0) db->addTempRelation("temp0vJ7195", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp0Hqi204");
  if (r == 0) db->addTempRelation("temp0Hqi204", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp04Kd194");
  if (r == 0) db->addTempRelation("temp04Kd194", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_vcode");
  if (r == 0) db->addRelation("smt_vcode", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_vcode");
      std::vector<u16> ord249({0, 1});
    
    r->addIndex<2>(ord249, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_vcode"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_unsat");
  if (r == 0) db->addRelation("smt_unsat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unsat");
      std::vector<u16> ord250({0});
    
    r->addIndex<1>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unsat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_unknown");
  if (r == 0) db->addRelation("smt_unknown", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unknown");
      std::vector<u16> ord251({0});
    
    r->addIndex<1>(ord251, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unknown"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_sat");
  if (r == 0) db->addRelation("smt_sat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_sat");
      std::vector<u16> ord252({0});
    
    r->addIndex<1>(ord252, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_sat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_qsat_ans");
  if (r == 0) db->addRelation("smt_qsat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord253({0, 1});
    
    r->addIndex<2>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qsat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qsat");
  if (r == 0) db->addStruct("smt_qsat", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat");
      std::vector<u16> ord254({1, 0});
    
    r->addIndex<2>(ord254, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord255({0, 1});
    
    r->addIndex<2>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qsat"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qmodel_ans");
  if (r == 0) db->addRelation("smt_qmodel_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel_ans");
      std::vector<u16> ord256({0, 1});
    
    r->addIndex<2>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qmodel_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qmodel");
  if (r == 0) db->addStruct("smt_qmodel", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel");
      std::vector<u16> ord257({1, 0});
    
    r->addIndex<2>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord258({0, 1});
    
    r->addIndex<2>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qmodel"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qcore_ans");
  if (r == 0) db->addRelation("smt_qcore_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore_ans");
      std::vector<u16> ord259({0, 1});
    
    r->addIndex<2>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qcore_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qcore");
  if (r == 0) db->addStruct("smt_qcore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore");
      std::vector<u16> ord260({1, 0});
    
    r->addIndex<2>(ord260, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord261({0, 1});
    
    r->addIndex<2>(ord261, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qcore"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_model_ans");
  if (r == 0) db->addRelation("smt_model_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model_ans");
      std::vector<u16> ord262({0, 1, 2});
    
    r->addIndex<3>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_model_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_model");
  if (r == 0) db->addStruct("smt_model", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model");
      std::vector<u16> ord263({1, 0});
    
    r->addIndex<2>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord264({0, 1});
    
    r->addIndex<2>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_model"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_core_ans");
  if (r == 0) db->addRelation("smt_core_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core_ans");
      std::vector<u16> ord265({0, 1, 2});
    
    r->addIndex<3>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_core_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_core");
  if (r == 0) db->addStruct("smt_core", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core");
      std::vector<u16> ord266({1, 0});
    
    r->addIndex<2>(ord266, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord267({0, 1});
    
    r->addIndex<2>(ord267, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_core"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check_ans");
  if (r == 0) db->addRelation("smt_check_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check_ans");
      std::vector<u16> ord268({0, 1});
    
    r->addIndex<2>(ord268, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_check_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_check");
  if (r == 0) db->addStruct("smt_check", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check");
      std::vector<u16> ord269({1, 0});
    
    r->addIndex<2>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord270({0, 1});
    
    r->addIndex<2>(ord270, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_check"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord271({1, 2, 0});
    
    r->addIndex<3>(ord271, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord272({0, 1, 2});
    
    r->addIndex<3>(ord272, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord273({0, 1, 2});
    
    r->addIndex<3>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("probe"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord274({1, 2, 3, 0});
    
    r->addIndex<4>(ord274, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord275({0, 1, 2, 3});
    
    r->addIndex<4>(ord275, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord276({1, 2, 0});
    
    r->addIndex<3>(ord276, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord277({0, 1, 2});
    
    r->addIndex<3>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord278({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord278, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord279({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord279, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord280({1, 2, 0});
    
    r->addIndex<3>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord281({0, 1, 2});
    
    r->addIndex<3>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord282({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord282, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord283({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord283, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lsub");
  if (r == 0) db->addStruct("lsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lsub");
      std::vector<u16> ord284({1, 2, 0});
    
    r->addIndex<3>(ord284, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord285({0, 1, 2});
    
    r->addIndex<3>(ord285, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lsub"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lor");
  if (r == 0) db->addStruct("lor", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lor");
      std::vector<u16> ord286({1, 2, 0});
    
    r->addIndex<3>(ord286, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord287({0, 1, 2});
    
    r->addIndex<3>(ord287, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lor"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lnot");
  if (r == 0) db->addStruct("lnot", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lnot");
      std::vector<u16> ord288({1, 0});
    
    r->addIndex<2>(ord288, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord289({0, 1});
    
    r->addIndex<2>(ord289, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lnot"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lne");
  if (r == 0) db->addStruct("lne", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lne");
      std::vector<u16> ord290({1, 2, 0});
    
    r->addIndex<3>(ord290, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord291({0, 1, 2});
    
    r->addIndex<3>(ord291, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lne"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lmul");
  if (r == 0) db->addStruct("lmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lmul");
      std::vector<u16> ord292({1, 2, 0});
    
    r->addIndex<3>(ord292, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord293({0, 1, 2});
    
    r->addIndex<3>(ord293, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lmul"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("llt");
  if (r == 0) db->addStruct("llt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("llt");
      std::vector<u16> ord294({2, 1, 0});
    
    r->addIndex<3>(ord294, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord295({0, 1, 2});
    
    r->addIndex<3>(ord295, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("llt"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lle");
  if (r == 0) db->addStruct("lle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lle");
      std::vector<u16> ord296({1, 2, 0});
    
    r->addIndex<3>(ord296, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord297({0, 1, 2});
    
    r->addIndex<3>(ord297, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lle"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lite");
  if (r == 0) db->addStruct("lite", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lite");
      std::vector<u16> ord298({1, 2, 3, 0});
    
    r->addIndex<4>(ord298, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord299({0, 1, 2, 3});
    
    r->addIndex<4>(ord299, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("lite"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("limplies");
  if (r == 0) db->addStruct("limplies", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("limplies");
      std::vector<u16> ord300({1, 2, 0});
    
    r->addIndex<3>(ord300, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord301({0, 1, 2});
    
    r->addIndex<3>(ord301, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("limplies"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lgt");
  if (r == 0) db->addStruct("lgt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lgt");
      std::vector<u16> ord302({2, 1, 0});
    
    r->addIndex<3>(ord302, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord303({0, 1, 2});
    
    r->addIndex<3>(ord303, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lgt"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lge");
  if (r == 0) db->addStruct("lge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lge");
      std::vector<u16> ord304({1, 2, 0});
    
    r->addIndex<3>(ord304, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord305({0, 1, 2});
    
    r->addIndex<3>(ord305, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lge"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("leq");
  if (r == 0) db->addStruct("leq", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leq");
      std::vector<u16> ord306({1, 2, 0});
    
    r->addIndex<3>(ord306, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord307({0, 1, 2});
    
    r->addIndex<3>(ord307, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("leq"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lany");
  if (r == 0) db->addStruct("lany", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lany");
      std::vector<u16> ord308({1, 0});
    
    r->addIndex<2>(ord308, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord309({0, 1});
    
    r->addIndex<2>(ord309, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lany"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("land");
  if (r == 0) db->addStruct("land", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("land");
      std::vector<u16> ord310({1, 2, 0});
    
    r->addIndex<3>(ord310, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord311({0, 1, 2});
    
    r->addIndex<3>(ord311, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("land"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lall");
  if (r == 0) db->addStruct("lall", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lall");
      std::vector<u16> ord312({1, 0});
    
    r->addIndex<2>(ord312, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord313({0, 1});
    
    r->addIndex<2>(ord313, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lall"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ladd");
  if (r == 0) db->addStruct("ladd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ladd");
      std::vector<u16> ord314({1, 2, 0});
    
    r->addIndex<3>(ord314, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord315({0, 1, 2});
    
    r->addIndex<3>(ord315, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ladd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("iv");
  if (r == 0) db->addStruct("iv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("iv");
      std::vector<u16> ord316({1, 0});
    
    r->addIndex<2>(ord316, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord317({0, 1});
    
    r->addIndex<2>(ord317, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("iv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord318({1, 2, 3, 0});
    
    r->addIndex<4>(ord318, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord319({0, 1, 2, 3});
    
    r->addIndex<4>(ord319, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ic");
  if (r == 0) db->addStruct("ic", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ic");
      std::vector<u16> ord320({1, 0});
    
    r->addIndex<2>(ord320, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord321({0, 1});
    
    r->addIndex<2>(ord321, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ic"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord322({0});
    
    r->addIndex<1>(ord322, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord323({1, 2, 0});
    
    r->addIndex<3>(ord323, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord324({0, 1, 2});
    
    r->addIndex<3>(ord324, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bv");
  if (r == 0) db->addStruct("bv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bv");
      std::vector<u16> ord325({1, 0});
    
    r->addIndex<2>(ord325, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord326({0, 1});
    
    r->addIndex<2>(ord326, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("bv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("blame_count");
  if (r == 0) db->addRelation("blame_count", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("blame_count");
      std::vector<u16> ord327({0, 1});
    
    r->addIndex<2>(ord327, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("blame_count"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord328({1, 0});
    
    r->addIndex<2>(ord328, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord329({0, 1});
    
    r->addIndex<2>(ord329, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre) (scan mpz_table_overflow __erre3Nww190 __errf1UfS191 __errf3mA1192) (body) (head (emit error (0) __erre3Nww190)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre (let __tconst37ds62 const6b86b273ff34fce19d6b804e) (let __tconst1lad60 constd4735e3a265e16eee03f5971) (let __tconst9FTs52 constef2d127de37b942baad06145) (let __tconst9SWw50 const4e07408562bedb8b60ce05c1)) (scan temp8yp4199 __t5HsE66) (body (exists ic (1 0) 1 __tconst9FTs52) (exists ic (1 0) 1 __tconst1lad60) (exists ic (1 0) 1 __tconst37ds62) (join ic (1 0) 1 __tconst9SWw50 __t5h2l51) (exists llt (2 1 0) 1 __t5h2l51) (join ic (1 0) 1 __tconst9FTs52 __t5ypn53) (join llt (2 1 0) 2 __t5h2l51 __t5ypn53 __t9imX54) (join ic (1 0) 1 __tconst1lad60 __t41HY56) (exists lgt (2 1 0) 1 __t41HY56) (join ic (1 0) 1 __tconst37ds62 __t69Uy58) (join lgt (2 1 0) 2 __t41HY56 __t69Uy58 __t7Goe59) (let __t2i1z67 (cins __t5HsE66 __t7Goe59))) (head (emit-temp temp2qZE200 __t2i1z67)) smt_core.slog:9 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex3;  slog::Index** icindex4;  slog::Index** icindex5;  slog::Index** icindex6;  slog::Index** lltindex7;  slog::Index** icindex8;  slog::Index** lltindex9;  slog::Index** icindex10;  slog::Index** lgtindex11;  slog::Index** icindex12;  slog::Index** lgtindex13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2qZE200");
      outer_rel = db->getRelation("temp8yp4199");
      std::vector<u16> ord15({1, 0});
      slog::Relation* readrel16 = db->getRelation("ic");
      icindex3 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 0});
      slog::Relation* readrel18 = db->getRelation("ic");
      icindex4 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("ic");
      icindex5 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 0});
      slog::Relation* readrel22 = db->getRelation("ic");
      icindex6 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({2, 1, 0});
      slog::Relation* readrel24 = db->getRelation("llt");
      lltindex7 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 0});
      slog::Relation* readrel26 = db->getRelation("ic");
      icindex8 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({2, 1, 0});
      slog::Relation* readrel28 = db->getRelation("llt");
      lltindex9 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 0});
      slog::Relation* readrel30 = db->getRelation("ic");
      icindex10 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({2, 1, 0});
      slog::Relation* readrel32 = db->getRelation("lgt");
      lgtindex11 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("ic");
      icindex12 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({2, 1, 0});
      slog::Relation* readrel36 = db->getRelation("lgt");
      lgtindex13 = readrel36->getIndex(ord35, false);
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c7 = _t[0];
        if (!slog::exists_probe<2,1>(icindex3, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(icindex4, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(icindex5, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(icindex6, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m37) {
          u64 v_c8 = m37[1];
          if (!slog::exists_probe<3,1>(lltindex7, std::array<u64,3>{v_c8, 0, 0})) return;
          slog::join_probe<2,1>(icindex8, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m38) {
            u64 v_c9 = m38[1];
            slog::join_probe<3,2>(lltindex9, std::array<u64,3>{v_c8, v_c9, 0}, [&](const std::array<u64,3>& m39) {
              u64 v_c10 = m39[2];
              slog::join_probe<2,1>(icindex10, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m40) {
                u64 v_c11 = m40[1];
                if (!slog::exists_probe<3,1>(lgtindex11, std::array<u64,3>{v_c11, 0, 0})) return;
                slog::join_probe<2,1>(icindex12, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m41) {
                  u64 v_c12 = m41[1];
                  slog::join_probe<3,2>(lgtindex13, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m42) {
                    u64 v_c13 = m42[2];
                    u64 v_c14 = _prim_cins(db, v_c7, v_c13);
                    if (v_c14 == slog_error) { slog::emit_pending_error(db, "smt_core.slog:9"); return; }
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c14});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_core.slog:9", "delta:temp8yp4199", _fires);
  
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
  // (crule (pre (let __tconst37ds62 const6b86b273ff34fce19d6b804e) (let __tconst1lad60 constd4735e3a265e16eee03f5971) (let __tconst9FTs52 constef2d127de37b942baad06145) (let __tconst9SWw50 const4e07408562bedb8b60ce05c1)) (scan temp6cMZ198 __t2FqK65) (body (exists ic (1 0) 1 __tconst9FTs52) (exists ic (1 0) 1 __tconst1lad60) (exists ic (1 0) 1 __tconst37ds62) (join ic (1 0) 1 __tconst9SWw50 __t5h2l51) (exists llt (2 1 0) 1 __t5h2l51) (join ic (1 0) 1 __tconst9FTs52 __t5ypn53) (join llt (2 1 0) 2 __t5h2l51 __t5ypn53 __t9imX54) (join ic (1 0) 1 __tconst1lad60 __t41HY56) (exists lgt (2 1 0) 1 __t41HY56) (exists llt (2 1 0) 1 __t41HY56) (join ic (1 0) 1 __tconst37ds62 __t69Uy58) (exists llt (2 1 0) 2 __t41HY56 __t69Uy58) (join lgt (2 1 0) 2 __t41HY56 __t69Uy58 __t7Goe59) (join llt (2 1 0) 2 __t41HY56 __t69Uy58 __t3vWI64) (let __t5HsE66 (cins __t2FqK65 __t3vWI64))) (head (emit-temp temp8yp4199 __t5HsE66)) smt_core.slog:9 #f)
  class ReadTask57 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex43;  slog::Index** icindex44;  slog::Index** icindex45;  slog::Index** icindex46;  slog::Index** lltindex47;  slog::Index** icindex48;  slog::Index** lltindex49;  slog::Index** icindex50;  slog::Index** lgtindex51;  slog::Index** lltindex52;  slog::Index** icindex53;  slog::Index** lltindex54;  slog::Index** lgtindex55;  slog::Index** lltindex56;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8yp4199");
      outer_rel = db->getRelation("temp6cMZ198");
      std::vector<u16> ord58({1, 0});
      slog::Relation* readrel59 = db->getRelation("ic");
      icindex43 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 0});
      slog::Relation* readrel61 = db->getRelation("ic");
      icindex44 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({1, 0});
      slog::Relation* readrel63 = db->getRelation("ic");
      icindex45 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 0});
      slog::Relation* readrel65 = db->getRelation("ic");
      icindex46 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({2, 1, 0});
      slog::Relation* readrel67 = db->getRelation("llt");
      lltindex47 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 0});
      slog::Relation* readrel69 = db->getRelation("ic");
      icindex48 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({2, 1, 0});
      slog::Relation* readrel71 = db->getRelation("llt");
      lltindex49 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 0});
      slog::Relation* readrel73 = db->getRelation("ic");
      icindex50 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({2, 1, 0});
      slog::Relation* readrel75 = db->getRelation("lgt");
      lgtindex51 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({2, 1, 0});
      slog::Relation* readrel77 = db->getRelation("llt");
      lltindex52 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 0});
      slog::Relation* readrel79 = db->getRelation("ic");
      icindex53 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({2, 1, 0});
      slog::Relation* readrel81 = db->getRelation("llt");
      lltindex54 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({2, 1, 0});
      slog::Relation* readrel83 = db->getRelation("lgt");
      lgtindex55 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({2, 1, 0});
      slog::Relation* readrel85 = db->getRelation("llt");
      lltindex56 = readrel85->getIndex(ord84, false);
  
    }
    ReadTask57(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c15 = _t[0];
        if (!slog::exists_probe<2,1>(icindex43, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(icindex44, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(icindex45, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(icindex46, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m86) {
          u64 v_c8 = m86[1];
          if (!slog::exists_probe<3,1>(lltindex47, std::array<u64,3>{v_c8, 0, 0})) return;
          slog::join_probe<2,1>(icindex48, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m87) {
            u64 v_c9 = m87[1];
            slog::join_probe<3,2>(lltindex49, std::array<u64,3>{v_c8, v_c9, 0}, [&](const std::array<u64,3>& m88) {
              u64 v_c10 = m88[2];
              slog::join_probe<2,1>(icindex50, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m89) {
                u64 v_c11 = m89[1];
                if (!slog::exists_probe<3,1>(lgtindex51, std::array<u64,3>{v_c11, 0, 0})) return;
                if (!slog::exists_probe<3,1>(lltindex52, std::array<u64,3>{v_c11, 0, 0})) return;
                slog::join_probe<2,1>(icindex53, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m90) {
                  u64 v_c12 = m90[1];
                  if (!slog::exists_probe<3,2>(lltindex54, std::array<u64,3>{v_c11, v_c12, 0})) return;
                  slog::join_probe<3,2>(lgtindex55, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m91) {
                    u64 v_c13 = m91[2];
                    slog::join_probe<3,2>(lltindex56, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m92) {
                      u64 v_c16 = m92[2];
                      u64 v_c7 = _prim_cins(db, v_c15, v_c16);
                      if (v_c7 == slog_error) { slog::emit_pending_error(db, "smt_core.slog:9"); return; }
                      ++_fires;
                      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c7});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_core.slog:9", "delta:temp6cMZ198", _fires);
  
      if (!_done)
      {
        ReadTask57* _cont = new ReadTask57(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask57(db,b), false);
  // (crule (pre) (scan temp0vJ7195 __t2ED884) (body) (head (emit-temp temp808U196 __t2ED884) (mkstruct lall (1 0) __t8q7V85 __t2ED884)) smt_core.slog:13 #f)
  class ReadTask93 : public slog::Task
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
      head_rel[0] = db->getRelation("temp808U196");
      head_rel[1] = db->getRelation("lall");
      outer_rel = db->getRelation("temp0vJ7195");
  
    }
    ReadTask93(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[0];
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c17});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_core.slog:13", "delta:temp0vJ7195", _fires);
  
      if (!_done)
      {
        ReadTask93* _cont = new ReadTask93(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask93(db,b), false);
  // (crule (pre) (scan temp808U196 __t2ED884) (body (join lall (1 0) 1 __t2ED884 __t8q7V85)) (head (mkstruct smt_core (1 0) __6K4n114 __t8q7V85)) smt_core.slog:13 #f)
  class ReadTask95 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex94;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_core");
      outer_rel = db->getRelation("temp808U196");
      std::vector<u16> ord96({1, 0});
      slog::Relation* readrel97 = db->getRelation("lall");
      lallindex94 = readrel97->getIndex(ord96, false);
  
    }
    ReadTask95(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[0];
        slog::join_probe<2,1>(lallindex94, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m98) {
          u64 v_c18 = m98[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_core.slog:13", "delta:temp808U196", _fires);
  
      if (!_done)
      {
        ReadTask95* _cont = new ReadTask95(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask95(db,b), false);
  // (crule (pre) (scan div_by_zero __erre43wk163 __errf2vxw164 __errf1uqs165) (body) (head (emit error (0) __erre43wk163)) <internal>:1 #f)
  class ReadTask99 : public slog::Task
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
      std::vector<u16> ord100({0});
      slog::Relation* readrel101 = db->getRelation("error");
      head_index[0] = readrel101->getIndex(ord100, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask99(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c21 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask99* _cont = new ReadTask99(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask99(db,b), false);
  // (crule (pre (let __tconst2liH131 consteb8bf0d80db323992f6b634a)) (once) (body) (head (mkstruct _enum (1 0) __69QA132 __tconst2liH131)) <internal>:1 #f)
  class ReadTask102 : public slog::Task
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
    ReadTask102(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_consteb8bf0d80db323992f6b634a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask102(db,b), true);
  // (crule (pre (let __tconst9FTs52 constef2d127de37b942baad06145) (let __tconst9SWw50 const4e07408562bedb8b60ce05c1)) (scan temp2qZE200 __t2i1z67) (body (exists ic (1 0) 1 __tconst9FTs52) (join ic (1 0) 1 __tconst9SWw50 __t5h2l51) (exists llt (2 1 0) 1 __t5h2l51) (join ic (1 0) 1 __tconst9FTs52 __t5ypn53) (join llt (2 1 0) 2 __t5h2l51 __t5ypn53 __t9imX54) (let __t2HNG68 (cins __t2i1z67 __t9imX54))) (head (emit-temp temp90IM201 __t2HNG68)) smt_core.slog:9 #f)
  class ReadTask108 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex103;  slog::Index** icindex104;  slog::Index** lltindex105;  slog::Index** icindex106;  slog::Index** lltindex107;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp90IM201");
      outer_rel = db->getRelation("temp2qZE200");
      std::vector<u16> ord109({1, 0});
      slog::Relation* readrel110 = db->getRelation("ic");
      icindex103 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 0});
      slog::Relation* readrel112 = db->getRelation("ic");
      icindex104 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({2, 1, 0});
      slog::Relation* readrel114 = db->getRelation("llt");
      lltindex105 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 0});
      slog::Relation* readrel116 = db->getRelation("ic");
      icindex106 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({2, 1, 0});
      slog::Relation* readrel118 = db->getRelation("llt");
      lltindex107 = readrel118->getIndex(ord117, false);
  
    }
    ReadTask108(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c14 = _t[0];
        if (!slog::exists_probe<2,1>(icindex103, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<2,1>(icindex104, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m119) {
          u64 v_c8 = m119[1];
          if (!slog::exists_probe<3,1>(lltindex105, std::array<u64,3>{v_c8, 0, 0})) return;
          slog::join_probe<2,1>(icindex106, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m120) {
            u64 v_c9 = m120[1];
            slog::join_probe<3,2>(lltindex107, std::array<u64,3>{v_c8, v_c9, 0}, [&](const std::array<u64,3>& m121) {
              u64 v_c10 = m121[2];
              u64 v_c23 = _prim_cins(db, v_c14, v_c10);
              if (v_c23 == slog_error) { slog::emit_pending_error(db, "smt_core.slog:9"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_core.slog:9", "delta:temp2qZE200", _fires);
  
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
  // (crule (pre (let __tconst0jqI72 const6b86b273ff34fce19d6b804e) (let __tconst5uoX70 constd4735e3a265e16eee03f5971) (let __t6Ug775 (cmap))) (once) (body) (head (emit-temp temp25QL203 __t6Ug775) (mkstruct ic (1 0) __t41yE73 __tconst0jqI72) (mkstruct ic (1 0) __t0FW171 __tconst5uoX70)) smt_core.slog:11 #f)
  class ReadTask122 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp25QL203");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
  
    }
    ReadTask122(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c25 = v_constd4735e3a265e16eee03f5971;
      u64 v_c26 = _prim_cmap(db);
      if (v_c26 == slog_error) { slog::emit_pending_error(db, "smt_core.slog:11"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c26});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c25}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_core.slog:11", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask122(db,b), true);
  // (crule (pre) (scan temp7m9a205 __t0NBk76) (body) (head (emit-temp temp1rZt206 __t0NBk76) (mkstruct lall (1 0) __t1LuY77 __t0NBk76)) smt_core.slog:11 #f)
  class ReadTask123 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1rZt206");
      head_rel[1] = db->getRelation("lall");
      outer_rel = db->getRelation("temp7m9a205");
  
    }
    ReadTask123(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c27});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c27}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_core.slog:11", "delta:temp7m9a205", _fires);
  
      if (!_done)
      {
        ReadTask123* _cont = new ReadTask123(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask123(db,b), false);
  // (crule (pre (let __tconst1bjT129 constab76c7d069d6f33dc950fb33)) (once) (body) (head (mkstruct _enum (1 0) __3pOg130 __tconst1bjT129)) <internal>:1 #f)
  class ReadTask124 : public slog::Task
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
    ReadTask124(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c28 = v_constab76c7d069d6f33dc950fb33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c28}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask124(db,b), true);
  // (crule (pre (let __tconst6ebC80 constba2df4903a2c14e86dc3bcca) (let __tconst8s8S78 const4e07408562bedb8b60ce05c1) (let __t1Ykx83 (cmap))) (once) (body) (head (emit-temp temp69SI193 __t1Ykx83) (mkstruct iv (1 0) __t1IHi81 __tconst6ebC80) (mkstruct ic (1 0) __t7nqn79 __tconst8s8S78)) smt_core.slog:13 #f)
  class ReadTask125 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp69SI193");
      head_rel[1] = db->getRelation("iv");
      head_rel[2] = db->getRelation("ic");
  
    }
    ReadTask125(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c30 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c31 = _prim_cmap(db);
      if (v_c31 == slog_error) { slog::emit_pending_error(db, "smt_core.slog:13"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c31});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c29}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c30}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_core.slog:13", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask125(db,b), true);
  // (crule (pre (let __tconst0jqI72 const6b86b273ff34fce19d6b804e) (let __tconst5uoX70 constd4735e3a265e16eee03f5971)) (scan temp25QL203 __t6Ug775) (body (exists ic (1 0) 1 __tconst0jqI72) (join ic (1 0) 1 __tconst5uoX70 __t0FW171) (join ic (1 0) 1 __tconst0jqI72 __t41yE73)) (head (emit-temp temp0Hqi204 __t6Ug775) (mkstruct llt (2 1 0) __t6Eiy74 __t0FW171 __t41yE73)) smt_core.slog:11 #f)
  class ReadTask129 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex126;  slog::Index** icindex127;  slog::Index** icindex128;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Hqi204");
      head_rel[1] = db->getRelation("llt");
      outer_rel = db->getRelation("temp25QL203");
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("ic");
      icindex126 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("ic");
      icindex127 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("ic");
      icindex128 = readrel135->getIndex(ord134, false);
  
    }
    ReadTask129(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c25 = v_constd4735e3a265e16eee03f5971;
  
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
        if (!slog::exists_probe<2,1>(icindex126, std::array<u64,2>{v_c24, 0})) return;
        slog::join_probe<2,1>(icindex127, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m136) {
          u64 v_c32 = m136[1];
          slog::join_probe<2,1>(icindex128, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m137) {
            u64 v_c33 = m137[1];
            ++_fires;
            slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c26});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c32, v_c33}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_core.slog:11", "delta:temp25QL203", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre6ffX169 __errf59nb170 __errf8H49171 __errf8MwX172) (body) (head (emit error (0) __erre6ffX169)) <internal>:1 #f)
  class ReadTask138 : public slog::Task
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
      std::vector<u16> ord139({0});
      slog::Relation* readrel140 = db->getRelation("error");
      head_index[0] = readrel140->getIndex(ord139, false);
      outer_rel = db->getRelation("int_overflow");
  
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
        u64 v_c34 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c37 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c34}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
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
  // (crule (pre (let __tconst37ds62 const6b86b273ff34fce19d6b804e) (let __tconst1lad60 constd4735e3a265e16eee03f5971) (let __tconst9FTs52 constef2d127de37b942baad06145) (let __tconst9SWw50 const4e07408562bedb8b60ce05c1)) (scan temp6ELz197 __t2FqK65) (body (exists ic (1 0) 1 __tconst9FTs52) (exists ic (1 0) 1 __tconst1lad60) (exists ic (1 0) 1 __tconst37ds62) (join ic (1 0) 1 __tconst9SWw50 __t5h2l51) (join ic (1 0) 1 __tconst9FTs52 __t5ypn53) (join ic (1 0) 1 __tconst1lad60 __t41HY56) (join ic (1 0) 1 __tconst37ds62 __t69Uy58)) (head (emit-temp temp6cMZ198 __t2FqK65) (mkstruct llt (2 1 0) __t3vWI64 __t41HY56 __t69Uy58) (mkstruct lgt (2 1 0) __t7Goe59 __t41HY56 __t69Uy58) (mkstruct llt (2 1 0) __t9imX54 __t5h2l51 __t5ypn53)) smt_core.slog:9 #f)
  class ReadTask148 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex141;  slog::Index** icindex142;  slog::Index** icindex143;  slog::Index** icindex144;  slog::Index** icindex145;  slog::Index** icindex146;  slog::Index** icindex147;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6cMZ198");
      head_rel[1] = db->getRelation("llt");
      head_rel[2] = db->getRelation("lgt");
      head_rel[3] = db->getRelation("llt");
      outer_rel = db->getRelation("temp6ELz197");
      std::vector<u16> ord149({1, 0});
      slog::Relation* readrel150 = db->getRelation("ic");
      icindex141 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 0});
      slog::Relation* readrel152 = db->getRelation("ic");
      icindex142 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 0});
      slog::Relation* readrel154 = db->getRelation("ic");
      icindex143 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 0});
      slog::Relation* readrel156 = db->getRelation("ic");
      icindex144 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 0});
      slog::Relation* readrel158 = db->getRelation("ic");
      icindex145 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 0});
      slog::Relation* readrel160 = db->getRelation("ic");
      icindex146 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 0});
      slog::Relation* readrel162 = db->getRelation("ic");
      icindex147 = readrel162->getIndex(ord161, false);
  
    }
    ReadTask148(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c15 = _t[0];
        if (!slog::exists_probe<2,1>(icindex141, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(icindex142, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(icindex143, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(icindex144, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m163) {
          u64 v_c8 = m163[1];
          slog::join_probe<2,1>(icindex145, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m164) {
            u64 v_c9 = m164[1];
            slog::join_probe<2,1>(icindex146, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m165) {
              u64 v_c11 = m165[1];
              slog::join_probe<2,1>(icindex147, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m166) {
                u64 v_c12 = m166[1];
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c15});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c11, v_c12}, std::array<u16,3>{2, 1, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c11, v_c12}, std::array<u16,3>{2, 1, 0});
                slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c8, v_c9}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("smt_core.slog:9", "delta:temp6ELz197", _fires);
  
      if (!_done)
      {
        ReadTask148* _cont = new ReadTask148(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask148(db,b), false);
  // (crule (pre (let __tconst37ds62 const6b86b273ff34fce19d6b804e) (let __tconst1lad60 constd4735e3a265e16eee03f5971) (let __tconst9FTs52 constef2d127de37b942baad06145) (let __tconst9SWw50 const4e07408562bedb8b60ce05c1) (let __t2FqK65 (cmap))) (once) (body) (head (emit-temp temp6ELz197 __t2FqK65) (mkstruct ic (1 0) __t69Uy58 __tconst37ds62) (mkstruct ic (1 0) __t41HY56 __tconst1lad60) (mkstruct ic (1 0) __t5ypn53 __tconst9FTs52) (mkstruct ic (1 0) __t5h2l51 __tconst9SWw50)) smt_core.slog:9 #f)
  class ReadTask167 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6ELz197");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
      head_rel[3] = db->getRelation("ic");
      head_rel[4] = db->getRelation("ic");
  
    }
    ReadTask167(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c15 = _prim_cmap(db);
      if (v_c15 == slog_error) { slog::emit_pending_error(db, "smt_core.slog:9"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c15});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c5}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c6}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("smt_core.slog:9", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask167(db,b), true);
  // (crule (pre) (scan type_mismatch __erre3Z1V180 __errf2JQC181 __errf8zl2182 __errf0ThK183 __errf9Hpq184) (body) (head (emit error (0) __erre3Z1V180)) <internal>:1 #f)
  class ReadTask168 : public slog::Task
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
      std::vector<u16> ord169({0});
      slog::Relation* readrel170 = db->getRelation("error");
      head_index[0] = readrel170->getIndex(ord169, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask168(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[3];
        u64 v_c42 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c38}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre9Ros166 __errf91qU167 __errf88bi168) (body) (head (emit error (0) __erre9Ros166)) <internal>:1 #f)
  class ReadTask171 : public slog::Task
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
      std::vector<u16> ord172({0});
      slog::Relation* readrel173 = db->getRelation("error");
      head_index[0] = readrel173->getIndex(ord172, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask171(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask171* _cont = new ReadTask171(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask171(db,b), false);
  // (crule (pre) (scan temp51A0202 __t2HNG68) (body (join lall (1 0) 1 __t2HNG68 __t6Dh469)) (head (mkstruct smt_core (1 0) __9pdx121 __t6Dh469)) smt_core.slog:9 #f)
  class ReadTask175 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex174;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_core");
      outer_rel = db->getRelation("temp51A0202");
      std::vector<u16> ord176({1, 0});
      slog::Relation* readrel177 = db->getRelation("lall");
      lallindex174 = readrel177->getIndex(ord176, false);
  
    }
    ReadTask175(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(lallindex174, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m178) {
          u64 v_c46 = m178[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c46}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_core.slog:9", "delta:temp51A0202", _fires);
  
      if (!_done)
      {
        ReadTask175* _cont = new ReadTask175(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask175(db,b), false);
  // (crule (pre) (scan temp1rZt206 __t0NBk76) (body (join lall (1 0) 1 __t0NBk76 __t1LuY77)) (head (mkstruct smt_core (1 0) __8EUJ119 __t1LuY77)) smt_core.slog:11 #f)
  class ReadTask180 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex179;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_core");
      outer_rel = db->getRelation("temp1rZt206");
      std::vector<u16> ord181({1, 0});
      slog::Relation* readrel182 = db->getRelation("lall");
      lallindex179 = readrel182->getIndex(ord181, false);
  
    }
    ReadTask180(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(lallindex179, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m183) {
          u64 v_c47 = m183[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c47}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_core.slog:11", "delta:temp1rZt206", _fires);
  
      if (!_done)
      {
        ReadTask180* _cont = new ReadTask180(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask180(db,b), false);
  // (crule (pre (let __tconst0jqI72 const6b86b273ff34fce19d6b804e) (let __tconst5uoX70 constd4735e3a265e16eee03f5971)) (scan temp0Hqi204 __t6Ug775) (body (exists ic (1 0) 1 __tconst0jqI72) (join ic (1 0) 1 __tconst5uoX70 __t0FW171) (exists llt (2 1 0) 1 __t0FW171) (join ic (1 0) 1 __tconst0jqI72 __t41yE73) (join llt (2 1 0) 2 __t0FW171 __t41yE73 __t6Eiy74) (let __t0NBk76 (cins __t6Ug775 __t6Eiy74))) (head (emit-temp temp7m9a205 __t0NBk76)) smt_core.slog:11 #f)
  class ReadTask189 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex184;  slog::Index** icindex185;  slog::Index** lltindex186;  slog::Index** icindex187;  slog::Index** lltindex188;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7m9a205");
      outer_rel = db->getRelation("temp0Hqi204");
      std::vector<u16> ord190({1, 0});
      slog::Relation* readrel191 = db->getRelation("ic");
      icindex184 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({1, 0});
      slog::Relation* readrel193 = db->getRelation("ic");
      icindex185 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({2, 1, 0});
      slog::Relation* readrel195 = db->getRelation("llt");
      lltindex186 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 0});
      slog::Relation* readrel197 = db->getRelation("ic");
      icindex187 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({2, 1, 0});
      slog::Relation* readrel199 = db->getRelation("llt");
      lltindex188 = readrel199->getIndex(ord198, false);
  
    }
    ReadTask189(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c25 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c26 = _t[0];
        if (!slog::exists_probe<2,1>(icindex184, std::array<u64,2>{v_c24, 0})) return;
        slog::join_probe<2,1>(icindex185, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m200) {
          u64 v_c32 = m200[1];
          if (!slog::exists_probe<3,1>(lltindex186, std::array<u64,3>{v_c32, 0, 0})) return;
          slog::join_probe<2,1>(icindex187, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m201) {
            u64 v_c33 = m201[1];
            slog::join_probe<3,2>(lltindex188, std::array<u64,3>{v_c32, v_c33, 0}, [&](const std::array<u64,3>& m202) {
              u64 v_c48 = m202[2];
              u64 v_c27 = _prim_cins(db, v_c26, v_c48);
              if (v_c27 == slog_error) { slog::emit_pending_error(db, "smt_core.slog:11"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c27});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_core.slog:11", "delta:temp0Hqi204", _fires);
  
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
  // (crule (pre) (scan mpz_overflow __erre5ByF185 __errf5UZD186 __errf7cmu187 __errf4pkp188 __errf640q189) (body) (head (emit error (0) __erre5ByF185)) <internal>:1 #f)
  class ReadTask203 : public slog::Task
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
      std::vector<u16> ord204({0});
      slog::Relation* readrel205 = db->getRelation("error");
      head_index[0] = readrel205->getIndex(ord204, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask203(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[3];
        u64 v_c53 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c49}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask203* _cont = new ReadTask203(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask203(db,b), false);
  // (crule (pre) (scan nan_result __erre3p10173 __errf6XZW174 __errf8C4q175 __errf29JM176) (body) (head (emit error (0) __erre3p10173)) <internal>:1 #f)
  class ReadTask206 : public slog::Task
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
      std::vector<u16> ord207({0});
      slog::Relation* readrel208 = db->getRelation("error");
      head_index[0] = readrel208->getIndex(ord207, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask206(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c54}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask206* _cont = new ReadTask206(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask206(db,b), false);
  // (crule (pre (let __tconst6ebC80 constba2df4903a2c14e86dc3bcca) (let __tconst8s8S78 const4e07408562bedb8b60ce05c1)) (scan temp69SI193 __t1Ykx83) (body (exists iv (1 0) 1 __tconst6ebC80) (join ic (1 0) 1 __tconst8s8S78 __t7nqn79) (join iv (1 0) 1 __tconst6ebC80 __t1IHi81)) (head (emit-temp temp04Kd194 __t1Ykx83) (mkstruct llt (2 1 0) __t0IGF82 __t7nqn79 __t1IHi81)) smt_core.slog:13 #f)
  class ReadTask212 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ivindex209;  slog::Index** icindex210;  slog::Index** ivindex211;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp04Kd194");
      head_rel[1] = db->getRelation("llt");
      outer_rel = db->getRelation("temp69SI193");
      std::vector<u16> ord213({1, 0});
      slog::Relation* readrel214 = db->getRelation("iv");
      ivindex209 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 0});
      slog::Relation* readrel216 = db->getRelation("ic");
      icindex210 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 0});
      slog::Relation* readrel218 = db->getRelation("iv");
      ivindex211 = readrel218->getIndex(ord217, false);
  
    }
    ReadTask212(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c30 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c31 = _t[0];
        if (!slog::exists_probe<2,1>(ivindex209, std::array<u64,2>{v_c29, 0})) return;
        slog::join_probe<2,1>(icindex210, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m219) {
          u64 v_c58 = m219[1];
          slog::join_probe<2,1>(ivindex211, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m220) {
            u64 v_c59 = m220[1];
            ++_fires;
            slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c31});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c58, v_c59}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_core.slog:13", "delta:temp69SI193", _fires);
  
      if (!_done)
      {
        ReadTask212* _cont = new ReadTask212(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask212(db,b), false);
  // (crule (pre) (scan temp90IM201 __t2HNG68) (body) (head (emit-temp temp51A0202 __t2HNG68) (mkstruct lall (1 0) __t6Dh469 __t2HNG68)) smt_core.slog:9 #f)
  class ReadTask221 : public slog::Task
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
      head_rel[0] = db->getRelation("temp51A0202");
      head_rel[1] = db->getRelation("lall");
      outer_rel = db->getRelation("temp90IM201");
  
    }
    ReadTask221(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[0];
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_core.slog:9", "delta:temp90IM201", _fires);
  
      if (!_done)
      {
        ReadTask221* _cont = new ReadTask221(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask221(db,b), false);
  // (crule (pre) (scan toint_range __erre9oV8177 __errf7WlE178 __errf4Sb8179) (body) (head (emit error (0) __erre9oV8177)) <internal>:1 #f)
  class ReadTask222 : public slog::Task
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
      std::vector<u16> ord223({0});
      slog::Relation* readrel224 = db->getRelation("error");
      head_index[0] = readrel224->getIndex(ord223, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask222(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c60 = _t[0];
        u64 v_c61 = _t[1];
        u64 v_c62 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c60}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask222* _cont = new ReadTask222(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask222(db,b), false);
  // (crule (pre (let __tconst6ebC80 constba2df4903a2c14e86dc3bcca) (let __tconst8s8S78 const4e07408562bedb8b60ce05c1)) (scan temp04Kd194 __t1Ykx83) (body (exists iv (1 0) 1 __tconst6ebC80) (join ic (1 0) 1 __tconst8s8S78 __t7nqn79) (exists llt (2 1 0) 1 __t7nqn79) (join iv (1 0) 1 __tconst6ebC80 __t1IHi81) (join llt (2 1 0) 2 __t7nqn79 __t1IHi81 __t0IGF82) (let __t2ED884 (cins __t1Ykx83 __t0IGF82))) (head (emit-temp temp0vJ7195 __t2ED884)) smt_core.slog:13 #f)
  class ReadTask230 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ivindex225;  slog::Index** icindex226;  slog::Index** lltindex227;  slog::Index** ivindex228;  slog::Index** lltindex229;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0vJ7195");
      outer_rel = db->getRelation("temp04Kd194");
      std::vector<u16> ord231({1, 0});
      slog::Relation* readrel232 = db->getRelation("iv");
      ivindex225 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 0});
      slog::Relation* readrel234 = db->getRelation("ic");
      icindex226 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({2, 1, 0});
      slog::Relation* readrel236 = db->getRelation("llt");
      lltindex227 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 0});
      slog::Relation* readrel238 = db->getRelation("iv");
      ivindex228 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({2, 1, 0});
      slog::Relation* readrel240 = db->getRelation("llt");
      lltindex229 = readrel240->getIndex(ord239, false);
  
    }
    ReadTask230(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c30 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c31 = _t[0];
        if (!slog::exists_probe<2,1>(ivindex225, std::array<u64,2>{v_c29, 0})) return;
        slog::join_probe<2,1>(icindex226, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m241) {
          u64 v_c58 = m241[1];
          if (!slog::exists_probe<3,1>(lltindex227, std::array<u64,3>{v_c58, 0, 0})) return;
          slog::join_probe<2,1>(ivindex228, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m242) {
            u64 v_c59 = m242[1];
            slog::join_probe<3,2>(lltindex229, std::array<u64,3>{v_c58, v_c59, 0}, [&](const std::array<u64,3>& m243) {
              u64 v_c63 = m243[2];
              u64 v_c17 = _prim_cins(db, v_c31, v_c63);
              if (v_c17 == slog_error) { slog::emit_pending_error(db, "smt_core.slog:13"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c17});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_core.slog:13", "delta:temp04Kd194", _fires);
  
      if (!_done)
      {
        ReadTask230* _cont = new ReadTask230(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask230(db,b), false);
  // (crule (pre (let __tconst6gPA127 consta221beeaebe583607e193be7)) (once) (body) (head (mkstruct _enum (1 0) __9UlS128 __tconst6gPA127)) <internal>:1 #f)
  class ReadTask244 : public slog::Task
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
    ReadTask244(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c64 = v_consta221beeaebe583607e193be7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c64}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask244(db,b), true);
  s->addReadRel("div_by_zero");
  s->addReadRel("ic");
  s->addReadRel("int_overflow");
  s->addReadRel("iv");
  s->addReadRel("lall");
  s->addReadRel("lgt");
  s->addReadRel("llt");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp04Kd194");
  s->addReadRel("temp0Hqi204");
  s->addReadRel("temp0vJ7195");
  s->addReadRel("temp1rZt206");
  s->addReadRel("temp25QL203");
  s->addReadRel("temp2qZE200");
  s->addReadRel("temp51A0202");
  s->addReadRel("temp69SI193");
  s->addReadRel("temp6ELz197");
  s->addReadRel("temp6cMZ198");
  s->addReadRel("temp7m9a205");
  s->addReadRel("temp808U196");
  s->addReadRel("temp8yp4199");
  s->addReadRel("temp90IM201");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("_enum");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("ic");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("iv");
  s->addDynamicRel("lall");
  s->addDynamicRel("lgt");
  s->addDynamicRel("llt");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("smt_core");
  s->addDynamicRel("temp04Kd194");
  s->addDynamicRel("temp0Hqi204");
  s->addDynamicRel("temp0vJ7195");
  s->addDynamicRel("temp1rZt206");
  s->addDynamicRel("temp25QL203");
  s->addDynamicRel("temp2qZE200");
  s->addDynamicRel("temp51A0202");
  s->addDynamicRel("temp69SI193");
  s->addDynamicRel("temp6ELz197");
  s->addDynamicRel("temp6cMZ198");
  s->addDynamicRel("temp7m9a205");
  s->addDynamicRel("temp808U196");
  s->addDynamicRel("temp8yp4199");
  s->addDynamicRel("temp90IM201");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

