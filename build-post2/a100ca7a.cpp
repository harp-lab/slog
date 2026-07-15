
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_consta2d9ef0aa4d7e7afc5887b92;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constef2d127de37b942baad06145;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_consta221beeaebe583607e193be7;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constba2df4903a2c14e86dc3bcca;
u64 v_constb691e6cf801b704585f5c3f0;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constf5ca38f748a1d6eaf726b8a4;
u64 v_constf401a2e0aa4c55a3068789bc;
u64 v_const429204a7a42b64cca2fe65e8;
u64 v_consta0e50277a57951e84b9bf792;
u64 v_const0ed9def6df14b5b9cfd95c1f;
u64 v_constab76c7d069d6f33dc950fb33;
u64 v_constab34826fd044c12689e8fac9;
u64 v_constb69f26da5a485bf54a0c6dc6;
u64 v_consteb8bf0d80db323992f6b634a;
u64 v_const358d07a56cdbf5fbaf27ab0c;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("a100ca7a");
  if (s == nullptr) return;
  slog::Relation* r;
  v_consta2d9ef0aa4d7e7afc5887b92 = db->encodeString("ite-then");
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_consta221beeaebe583607e193be7 = db->encodeString("unsat");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constba2df4903a2c14e86dc3bcca = db->encodeString("x");
  v_constb691e6cf801b704585f5c3f0 = db->encodeString("any-true");
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constf5ca38f748a1d6eaf726b8a4 = s32_encode(20);
  v_constf401a2e0aa4c55a3068789bc = db->encodeString("true-and-sym");
  v_const429204a7a42b64cca2fe65e8 = db->encodeString("false-and-sym");
  v_consta0e50277a57951e84b9bf792 = db->encodeString("empty-any");
  v_const0ed9def6df14b5b9cfd95c1f = db->encodeString("empty-all");
  v_constab76c7d069d6f33dc950fb33 = db->encodeString("sat");
  v_constab34826fd044c12689e8fac9 = db->encodeString("one-false");
  v_constb69f26da5a485bf54a0c6dc6 = db->encodeString("distinct");
  v_consteb8bf0d80db323992f6b634a = db->encodeString("unknown");
  v_const358d07a56cdbf5fbaf27ab0c = db->encodeString("all-true");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord388({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord388, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord389({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord389, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord390({1, 2, 0});
    
    r->addIndex<3>(ord390, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord391({0, 1, 2});
    
    r->addIndex<3>(ord391, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_vcode");
  if (r == 0) db->addRelation("smt_vcode", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_vcode");
      std::vector<u16> ord392({0, 1});
    
    r->addIndex<2>(ord392, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_vcode"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_unsat");
  if (r == 0) db->addRelation("smt_unsat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unsat");
      std::vector<u16> ord393({0});
    
    r->addIndex<1>(ord393, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unsat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_unknown");
  if (r == 0) db->addRelation("smt_unknown", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unknown");
      std::vector<u16> ord394({0});
    
    r->addIndex<1>(ord394, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unknown"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_sat");
  if (r == 0) db->addRelation("smt_sat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_sat");
      std::vector<u16> ord395({0});
    
    r->addIndex<1>(ord395, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_sat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_qsat_ans");
  if (r == 0) db->addRelation("smt_qsat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord396({0, 1});
    
    r->addIndex<2>(ord396, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qsat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qsat");
  if (r == 0) db->addStruct("smt_qsat", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat");
      std::vector<u16> ord397({1, 0});
    
    r->addIndex<2>(ord397, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord398({0, 1});
    
    r->addIndex<2>(ord398, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qsat"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qmodel_ans");
  if (r == 0) db->addRelation("smt_qmodel_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel_ans");
      std::vector<u16> ord399({0, 1});
    
    r->addIndex<2>(ord399, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qmodel_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qmodel");
  if (r == 0) db->addStruct("smt_qmodel", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel");
      std::vector<u16> ord400({1, 0});
    
    r->addIndex<2>(ord400, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord401({0, 1});
    
    r->addIndex<2>(ord401, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qmodel"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qcore_ans");
  if (r == 0) db->addRelation("smt_qcore_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore_ans");
      std::vector<u16> ord402({0, 1});
    
    r->addIndex<2>(ord402, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qcore_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qcore");
  if (r == 0) db->addStruct("smt_qcore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore");
      std::vector<u16> ord403({1, 0});
    
    r->addIndex<2>(ord403, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord404({0, 1});
    
    r->addIndex<2>(ord404, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qcore"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_model_ans");
  if (r == 0) db->addRelation("smt_model_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model_ans");
      std::vector<u16> ord405({0, 1, 2});
    
    r->addIndex<3>(ord405, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_model_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_model");
  if (r == 0) db->addStruct("smt_model", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model");
      std::vector<u16> ord406({1, 0});
    
    r->addIndex<2>(ord406, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord407({0, 1});
    
    r->addIndex<2>(ord407, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_model"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_core_ans");
  if (r == 0) db->addRelation("smt_core_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core_ans");
      std::vector<u16> ord408({0, 1, 2});
    
    r->addIndex<3>(ord408, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_core_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_core");
  if (r == 0) db->addStruct("smt_core", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core");
      std::vector<u16> ord409({1, 0});
    
    r->addIndex<2>(ord409, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord410({0, 1});
    
    r->addIndex<2>(ord410, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_core"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check_ans");
  if (r == 0) db->addRelation("smt_check_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check_ans");
      std::vector<u16> ord411({0, 1});
    
    r->addIndex<2>(ord411, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord412({1, 0});
    
    r->addIndex<2>(ord412, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_check_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_check");
  if (r == 0) db->addStruct("smt_check", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check");
      std::vector<u16> ord413({1, 0});
    
    r->addIndex<2>(ord413, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord414({0, 1});
    
    r->addIndex<2>(ord414, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_check"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord415({1, 2, 0});
    
    r->addIndex<3>(ord415, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord416({0, 1, 2});
    
    r->addIndex<3>(ord416, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("same");
  if (r == 0) db->addRelation("same", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("same");
      std::vector<u16> ord417({0, 1});
    
    r->addIndex<2>(ord417, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("same"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord418({0, 1});
    
    r->addIndex<2>(ord418, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("probe"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord419({1, 2, 3, 0});
    
    r->addIndex<4>(ord419, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord420({0, 1, 2, 3});
    
    r->addIndex<4>(ord420, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord421({1, 2, 0});
    
    r->addIndex<3>(ord421, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord422({0, 1, 2});
    
    r->addIndex<3>(ord422, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord423({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord423, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord424({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord424, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord425({1, 2, 0});
    
    r->addIndex<3>(ord425, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord426({0, 1, 2});
    
    r->addIndex<3>(ord426, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord427({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord427, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord428({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord428, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lsub");
  if (r == 0) db->addStruct("lsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lsub");
      std::vector<u16> ord429({1, 2, 0});
    
    r->addIndex<3>(ord429, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord430({0, 1, 2});
    
    r->addIndex<3>(ord430, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lsub"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lor");
  if (r == 0) db->addStruct("lor", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lor");
      std::vector<u16> ord431({1, 2, 0});
    
    r->addIndex<3>(ord431, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord432({0, 1, 2});
    
    r->addIndex<3>(ord432, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lor"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lnot");
  if (r == 0) db->addStruct("lnot", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lnot");
      std::vector<u16> ord433({1, 0});
    
    r->addIndex<2>(ord433, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord434({0, 1});
    
    r->addIndex<2>(ord434, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lnot"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lne");
  if (r == 0) db->addStruct("lne", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lne");
      std::vector<u16> ord435({2, 1, 0});
    
    r->addIndex<3>(ord435, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord436({0, 1, 2});
    
    r->addIndex<3>(ord436, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lne"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lmul");
  if (r == 0) db->addStruct("lmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lmul");
      std::vector<u16> ord437({1, 2, 0});
    
    r->addIndex<3>(ord437, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord438({0, 1, 2});
    
    r->addIndex<3>(ord438, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lmul"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("llt");
  if (r == 0) db->addStruct("llt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("llt");
      std::vector<u16> ord439({1, 2, 0});
    
    r->addIndex<3>(ord439, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord440({0, 1, 2});
    
    r->addIndex<3>(ord440, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord441({2, 0, 1});
    
    r->addIndex<3>(ord441, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("llt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lle");
  if (r == 0) db->addStruct("lle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lle");
      std::vector<u16> ord442({1, 2, 0});
    
    r->addIndex<3>(ord442, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord443({0, 1, 2});
    
    r->addIndex<3>(ord443, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lle"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lite");
  if (r == 0) db->addStruct("lite", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lite");
      std::vector<u16> ord444({1, 3, 2, 0});
    
    r->addIndex<4>(ord444, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 2, 0}, false, b), true);
      std::vector<u16> ord445({0, 1, 2, 3});
    
    r->addIndex<4>(ord445, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("lite"), std::array<u16,4>{1, 3, 2, 0}, b));
  r = db->getRelation("limplies");
  if (r == 0) db->addStruct("limplies", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("limplies");
      std::vector<u16> ord446({1, 2, 0});
    
    r->addIndex<3>(ord446, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord447({0, 1, 2});
    
    r->addIndex<3>(ord447, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("limplies"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lgt");
  if (r == 0) db->addStruct("lgt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lgt");
      std::vector<u16> ord448({1, 2, 0});
    
    r->addIndex<3>(ord448, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord449({0, 1, 2});
    
    r->addIndex<3>(ord449, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord450({2, 0, 1});
    
    r->addIndex<3>(ord450, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lgt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lge");
  if (r == 0) db->addStruct("lge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lge");
      std::vector<u16> ord451({1, 2, 0});
    
    r->addIndex<3>(ord451, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord452({0, 1, 2});
    
    r->addIndex<3>(ord452, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lge"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("leq");
  if (r == 0) db->addStruct("leq", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leq");
      std::vector<u16> ord453({1, 2, 0});
    
    r->addIndex<3>(ord453, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord454({0, 1, 2});
    
    r->addIndex<3>(ord454, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("leq"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lany");
  if (r == 0) db->addStruct("lany", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lany");
      std::vector<u16> ord455({1, 0});
    
    r->addIndex<2>(ord455, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord456({0, 1});
    
    r->addIndex<2>(ord456, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lany"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("land");
  if (r == 0) db->addStruct("land", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("land");
      std::vector<u16> ord457({1, 2, 0});
    
    r->addIndex<3>(ord457, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord458({0, 1, 2});
    
    r->addIndex<3>(ord458, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("land"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lall");
  if (r == 0) db->addStruct("lall", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lall");
      std::vector<u16> ord459({1, 0});
    
    r->addIndex<2>(ord459, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord460({0, 1});
    
    r->addIndex<2>(ord460, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lall"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ladd");
  if (r == 0) db->addStruct("ladd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ladd");
      std::vector<u16> ord461({1, 2, 0});
    
    r->addIndex<3>(ord461, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord462({0, 1, 2});
    
    r->addIndex<3>(ord462, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ladd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("iv");
  if (r == 0) db->addStruct("iv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("iv");
      std::vector<u16> ord463({1, 0});
    
    r->addIndex<2>(ord463, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord464({0, 1});
    
    r->addIndex<2>(ord464, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("iv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord465({1, 2, 3, 0});
    
    r->addIndex<4>(ord465, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord466({0, 1, 2, 3});
    
    r->addIndex<4>(ord466, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ic");
  if (r == 0) db->addStruct("ic", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ic");
      std::vector<u16> ord467({1, 0});
    
    r->addIndex<2>(ord467, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord468({0, 1});
    
    r->addIndex<2>(ord468, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord469({1, 0});
    
    r->addIndex<2>(ord469, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ic"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord470({0});
    
    r->addIndex<1>(ord470, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord471({1, 2, 0});
    
    r->addIndex<3>(ord471, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord472({0, 1, 2});
    
    r->addIndex<3>(ord472, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bv");
  if (r == 0) db->addStruct("bv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bv");
      std::vector<u16> ord473({1, 0});
    
    r->addIndex<2>(ord473, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord474({0, 1});
    
    r->addIndex<2>(ord474, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("bv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord475({1, 0});
    
    r->addIndex<2>(ord475, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord476({0, 1});
    
    r->addIndex<2>(ord476, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord477({1, 0});
    
    r->addIndex<2>(ord477, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst9hs5197 constd4735e3a265e16eee03f5971) (let __tconst7kHZ199 const6b86b273ff34fce19d6b804e) (let __tconst5lVs202 const4e07408562bedb8b60ce05c1) (let __tconst2GwQ204 constba2df4903a2c14e86dc3bcca) (let __tconst6YLt196 const429204a7a42b64cca2fe65e8) (let __t5ndf207 (cmap))) (probe ic (1 0) 1 __tconst9hs5197 __t38DW198) (body (exists lgt (2 0 1) 1 __t38DW198) (exists ic (1 0) 1 __tconst5lVs202) (exists iv (1 0) 1 __tconst2GwQ204) (join ic (1 0) 1 __tconst7kHZ199 __t4UXo200) (join lgt (1 2 0) 2 __t4UXo200 __t38DW198 __t5jFB201) (join ic (1 0) 1 __tconst5lVs202 __t3VaN203) (exists llt (2 0 1) 1 __t3VaN203) (join iv (1 0) 1 __tconst2GwQ204 __t22Rg205) (join llt (1 2 0) 2 __t22Rg205 __t3VaN203 __t2I89206) (join smt_check_ans (0 1) 0 __t4jh6211 V) (join smt_check (0 1) 1 __t4jh6211 __t7Jq0210) (let __t4hae208 (cins __t5ndf207 __t2I89206)) (let __t3icF209 (cins __t4hae208 __t5jFB201)) (join lall (0 1) 2 __t7Jq0210 __t3icF209)) (head (emit probe (0 1) __tconst6YLt196 V)) smt_sets.slog:15 #f)
  class ReadTask12 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lgtindex0;  slog::Index** icindex1;  slog::Index** ivindex2;  slog::Index** icindex3;  slog::Index** lgtindex4;  slog::Index** icindex5;  slog::Index** lltindex6;  slog::Index** ivindex7;  slog::Index** lltindex8;  slog::Index** smt_check_ansindex9;  slog::Index** smt_checkindex10;  slog::Index** lallindex11;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord13({0, 1});
      slog::Relation* readrel14 = db->getRelation("probe");
      head_index[0] = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({1, 0});
      slog::Relation* readrel16 = db->getRelation("ic");
      driver_index = readrel16->getIndex(ord15, true);
      std::vector<u16> ord17({2, 0, 1});
      slog::Relation* readrel18 = db->getRelation("lgt");
      lgtindex0 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("ic");
      icindex1 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 0});
      slog::Relation* readrel22 = db->getRelation("iv");
      ivindex2 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 0});
      slog::Relation* readrel24 = db->getRelation("ic");
      icindex3 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 2, 0});
      slog::Relation* readrel26 = db->getRelation("lgt");
      lgtindex4 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 0});
      slog::Relation* readrel28 = db->getRelation("ic");
      icindex5 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({2, 0, 1});
      slog::Relation* readrel30 = db->getRelation("llt");
      lltindex6 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 0});
      slog::Relation* readrel32 = db->getRelation("iv");
      ivindex7 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0});
      slog::Relation* readrel34 = db->getRelation("llt");
      lltindex8 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("smt_check_ans");
      smt_check_ansindex9 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("smt_check");
      smt_checkindex10 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("lall");
      lallindex11 = readrel40->getIndex(ord39, false);
  
    }
    ReadTask12(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constd4735e3a265e16eee03f5971;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c3 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c4 = v_const429204a7a42b64cca2fe65e8;
      u64 v_c5 = _prim_cmap(db);
      if (v_c5 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:15"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m41) {
        u64 v_c6 = m41[1];
        if (buckethash(v_c6) != bucket) return;
        if (!slog::exists_probe<3,1>(lgtindex0, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(icindex1, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex2, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(icindex3, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m42) {
          u64 v_c7 = m42[1];
          slog::join_probe<3,2>(lgtindex4, std::array<u64,3>{v_c7, v_c6, 0}, [&](const std::array<u64,3>& m43) {
            u64 v_c8 = m43[2];
            slog::join_probe<2,1>(icindex5, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m44) {
              u64 v_c9 = m44[1];
              if (!slog::exists_probe<3,1>(lltindex6, std::array<u64,3>{v_c9, 0, 0})) return;
              slog::join_probe<2,1>(ivindex7, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m45) {
                u64 v_c10 = m45[1];
                slog::join_probe<3,2>(lltindex8, std::array<u64,3>{v_c10, v_c9, 0}, [&](const std::array<u64,3>& m46) {
                  u64 v_c11 = m46[2];
                  slog::join_all<2>(smt_check_ansindex9, [&](const std::array<u64,2>& m47) {
                    u64 v_c12 = m47[0]; u64 v_c13 = m47[1];
                    slog::join_probe<2,1>(smt_checkindex10, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m48) {
                      u64 v_c14 = m48[1];
                      u64 v_c15 = _prim_cins(db, v_c5, v_c11);
                      if (v_c15 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:15"); return; }
                      u64 v_c16 = _prim_cins(db, v_c15, v_c8);
                      if (v_c16 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:15"); return; }
                      slog::join_probe<2,2>(lallindex11, std::array<u64,2>{v_c14, v_c16}, [&](const std::array<u64,2>& m49) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c13}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("smt_sets.slog:15", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask12* _cont = new ReadTask12(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask12(db,b), true);
  // (crule (pre (let __tconst15gc99 consta0e50277a57951e84b9bf792) (let __t9KLI100 (cmap))) (scan smt_check_ans __t9Luf102 V) (body (join lany (1 0) 1 __t9KLI100 __t7saw101) (join smt_check (0 1) 2 __t9Luf102 __t7saw101)) (head (emit probe (0 1) __tconst15gc99 V)) smt_sets.slog:22 #f)
  class ReadTask52 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lanyindex50;  slog::Index** smt_checkindex51;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord53({0, 1});
      slog::Relation* readrel54 = db->getRelation("probe");
      head_index[0] = readrel54->getIndex(ord53, false);
      outer_rel = db->getRelation("smt_check_ans");
      std::vector<u16> ord55({1, 0});
      slog::Relation* readrel56 = db->getRelation("lany");
      lanyindex50 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("smt_check");
      smt_checkindex51 = readrel58->getIndex(ord57, false);
  
    }
    ReadTask52(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_consta0e50277a57951e84b9bf792;
      u64 v_c18 = _prim_cmap(db);
      if (v_c18 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:22"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c19 = _t[0];
        u64 v_c13 = _t[1];
        slog::join_probe<2,1>(lanyindex50, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m59) {
          u64 v_c20 = m59[1];
          slog::join_probe<2,2>(smt_checkindex51, std::array<u64,2>{v_c19, v_c20}, [&](const std::array<u64,2>& m60) {
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c17, v_c13}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:22", "all:smt_check_ans", _fires);
  
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
      s->addTask(phase_read, new ReadTask52(db,b), true);
  // (crule (pre (let __tconst7uQM61 const0ed9def6df14b5b9cfd95c1f) (let __t5Vxz62 (cmap))) (scan smt_check_ans __t29at64 V) (body (join lall (1 0) 1 __t5Vxz62 __t6XjA63) (join smt_check (0 1) 2 __t29at64 __t6XjA63)) (head (emit probe (0 1) __tconst7uQM61 V)) smt_sets.slog:21 #f)
  class ReadTask63 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex61;  slog::Index** smt_checkindex62;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord64({0, 1});
      slog::Relation* readrel65 = db->getRelation("probe");
      head_index[0] = readrel65->getIndex(ord64, false);
      outer_rel = db->getRelation("smt_check_ans");
      std::vector<u16> ord66({1, 0});
      slog::Relation* readrel67 = db->getRelation("lall");
      lallindex61 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({0, 1});
      slog::Relation* readrel69 = db->getRelation("smt_check");
      smt_checkindex62 = readrel69->getIndex(ord68, false);
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c21 = v_const0ed9def6df14b5b9cfd95c1f;
      u64 v_c22 = _prim_cmap(db);
      if (v_c22 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:21"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c23 = _t[0];
        u64 v_c13 = _t[1];
        slog::join_probe<2,1>(lallindex61, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m70) {
          u64 v_c24 = m70[1];
          slog::join_probe<2,2>(smt_checkindex62, std::array<u64,2>{v_c23, v_c24}, [&](const std::array<u64,2>& m71) {
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c13}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:21", "all:smt_check_ans", _fires);
  
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
  // (crule (pre (let __tconst13Rl35 constef2d127de37b942baad06145) (let __tconst1IKg33 const4e07408562bedb8b60ce05c1) (let __tconst98L631 const4a44dc15364204a80fe80e90) (let __tconst6gly29 constf5ca38f748a1d6eaf726b8a4) (let __tconst1QpO26 consta2d9ef0aa4d7e7afc5887b92)) (probe ic (1 0) 1 __tconst13Rl35 __t740C36) (body (exists lgt (1 2 0) 1 __t740C36) (exists ic (1 0) 1 __tconst6gly29) (exists ic (1 0) 1 __tconst98L631) (join ic (1 0) 1 __tconst1IKg33 __t2H6534) (join lgt (1 2 0) 2 __t740C36 __t2H6534 __t2VkE37) (exists lite (1 3 2 0) 1 __t2VkE37) (join ic (1 0) 1 __tconst6gly29 __t8D0S30) (join lite (1 3 2 0) 2 __t2VkE37 __t8D0S30 __t1Grl28 __t5Bv538) (join ic (0 1) 2 __t1Grl28 __tconst98L631) (join leq (1 2 0) 2 __t5Bv538 __t1Grl28 __t3dBi39) (join smt_check (1 0) 1 __t3dBi39 __t235i40) (join smt_check_ans (0 1) 1 __t235i40 V)) (head (emit probe (0 1) __tconst1QpO26 V)) smt_sets.slog:23 #f)
  class ReadTask84 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lgtindex72;  slog::Index** icindex73;  slog::Index** icindex74;  slog::Index** icindex75;  slog::Index** lgtindex76;  slog::Index** liteindex77;  slog::Index** icindex78;  slog::Index** liteindex79;  slog::Index** icindex80;  slog::Index** leqindex81;  slog::Index** smt_checkindex82;  slog::Index** smt_check_ansindex83;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord85({0, 1});
      slog::Relation* readrel86 = db->getRelation("probe");
      head_index[0] = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 0});
      slog::Relation* readrel88 = db->getRelation("ic");
      driver_index = readrel88->getIndex(ord87, true);
      std::vector<u16> ord89({1, 2, 0});
      slog::Relation* readrel90 = db->getRelation("lgt");
      lgtindex72 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({1, 0});
      slog::Relation* readrel92 = db->getRelation("ic");
      icindex73 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 0});
      slog::Relation* readrel94 = db->getRelation("ic");
      icindex74 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 0});
      slog::Relation* readrel96 = db->getRelation("ic");
      icindex75 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 2, 0});
      slog::Relation* readrel98 = db->getRelation("lgt");
      lgtindex76 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 3, 2, 0});
      slog::Relation* readrel100 = db->getRelation("lite");
      liteindex77 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("ic");
      icindex78 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 3, 2, 0});
      slog::Relation* readrel104 = db->getRelation("lite");
      liteindex79 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("ic");
      icindex80 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 2, 0});
      slog::Relation* readrel108 = db->getRelation("leq");
      leqindex81 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 0});
      slog::Relation* readrel110 = db->getRelation("smt_check");
      smt_checkindex82 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 1});
      slog::Relation* readrel112 = db->getRelation("smt_check_ans");
      smt_check_ansindex83 = readrel112->getIndex(ord111, false);
  
    }
    ReadTask84(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_constef2d127de37b942baad06145;
      u64 v_c26 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c27 = v_const4a44dc15364204a80fe80e90;
      u64 v_c28 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c29 = v_consta2d9ef0aa4d7e7afc5887b92;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c25, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m113) {
        u64 v_c30 = m113[1];
        if (buckethash(v_c30) != bucket) return;
        if (!slog::exists_probe<3,1>(lgtindex72, std::array<u64,3>{v_c30, 0, 0})) return;
        if (!slog::exists_probe<2,1>(icindex73, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(icindex74, std::array<u64,2>{v_c27, 0})) return;
        slog::join_probe<2,1>(icindex75, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m114) {
          u64 v_c31 = m114[1];
          slog::join_probe<3,2>(lgtindex76, std::array<u64,3>{v_c30, v_c31, 0}, [&](const std::array<u64,3>& m115) {
            u64 v_c32 = m115[2];
            if (!slog::exists_probe<4,1>(liteindex77, std::array<u64,4>{v_c32, 0, 0, 0})) return;
            slog::join_probe<2,1>(icindex78, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m116) {
              u64 v_c33 = m116[1];
              slog::join_probe<4,2>(liteindex79, std::array<u64,4>{v_c32, v_c33, 0, 0}, [&](const std::array<u64,4>& m117) {
                u64 v_c34 = m117[2]; u64 v_c35 = m117[3];
                slog::join_probe<2,2>(icindex80, std::array<u64,2>{v_c34, v_c27}, [&](const std::array<u64,2>& m118) {
                  slog::join_probe<3,2>(leqindex81, std::array<u64,3>{v_c35, v_c34, 0}, [&](const std::array<u64,3>& m119) {
                    u64 v_c36 = m119[2];
                    slog::join_probe<2,1>(smt_checkindex82, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m120) {
                      u64 v_c37 = m120[1];
                      slog::join_probe<2,1>(smt_check_ansindex83, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m121) {
                        u64 v_c13 = m121[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c13}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("smt_sets.slog:23", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask84* _cont = new ReadTask84(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask84(db,b), true);
  // (crule (pre (let __tconst2WS5175 constd4735e3a265e16eee03f5971) (let __tconst1Sw6170 const6b86b273ff34fce19d6b804e) (let __tconst1UMI167 const358d07a56cdbf5fbaf27ab0c) (let __t4yJz178 (cmap))) (probe ic (1 0) 1 __tconst1Sw6170 __t529P171) (body (exists llt (1 2 0) 1 __t529P171) (join ic (1 0) 1 __tconst2WS5175 __t73cy169) (exists lle (1 2 0) 1 __t73cy169) (join llt (1 2 0) 2 __t529P171 __t73cy169 __t2rF7172) (join lle (1 2 0) 1 __t73cy169 dup7Pcy546 __t7kAm177) (eq __t73cy169 dup7Pcy546) (join smt_check_ans (0 1) 0 __t37EQ182 V) (join smt_check (0 1) 1 __t37EQ182 __t0s0W181) (let __t0aea179 (cins __t4yJz178 __t7kAm177)) (let __t3Mel180 (cins __t0aea179 __t2rF7172)) (join lall (0 1) 2 __t0s0W181 __t3Mel180)) (head (emit probe (0 1) __tconst1UMI167 V)) smt_sets.slog:11 #f)
  class ReadTask130 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex122;  slog::Index** icindex123;  slog::Index** lleindex124;  slog::Index** lltindex125;  slog::Index** lleindex126;  slog::Index** smt_check_ansindex127;  slog::Index** smt_checkindex128;  slog::Index** lallindex129;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("probe");
      head_index[0] = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 0});
      slog::Relation* readrel134 = db->getRelation("ic");
      driver_index = readrel134->getIndex(ord133, true);
      std::vector<u16> ord135({1, 2, 0});
      slog::Relation* readrel136 = db->getRelation("llt");
      lltindex122 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 0});
      slog::Relation* readrel138 = db->getRelation("ic");
      icindex123 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 2, 0});
      slog::Relation* readrel140 = db->getRelation("lle");
      lleindex124 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 2, 0});
      slog::Relation* readrel142 = db->getRelation("llt");
      lltindex125 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 2, 0});
      slog::Relation* readrel144 = db->getRelation("lle");
      lleindex126 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("smt_check_ans");
      smt_check_ansindex127 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({0, 1});
      slog::Relation* readrel148 = db->getRelation("smt_check");
      smt_checkindex128 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("lall");
      lallindex129 = readrel150->getIndex(ord149, false);
  
    }
    ReadTask130(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_constd4735e3a265e16eee03f5971;
      u64 v_c39 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c40 = v_const358d07a56cdbf5fbaf27ab0c;
      u64 v_c41 = _prim_cmap(db);
      if (v_c41 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:11"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c39, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m151) {
        u64 v_c42 = m151[1];
        if (buckethash(v_c42) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex122, std::array<u64,3>{v_c42, 0, 0})) return;
        slog::join_probe<2,1>(icindex123, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m152) {
          u64 v_c43 = m152[1];
          if (!slog::exists_probe<3,1>(lleindex124, std::array<u64,3>{v_c43, 0, 0})) return;
          slog::join_probe<3,2>(lltindex125, std::array<u64,3>{v_c42, v_c43, 0}, [&](const std::array<u64,3>& m153) {
            u64 v_c44 = m153[2];
            slog::join_probe<3,1>(lleindex126, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m154) {
              u64 v_c45 = m154[1]; u64 v_c46 = m154[2];
              if (v_c43 != v_c45) return;
              slog::join_all<2>(smt_check_ansindex127, [&](const std::array<u64,2>& m155) {
                u64 v_c47 = m155[0]; u64 v_c13 = m155[1];
                slog::join_probe<2,1>(smt_checkindex128, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m156) {
                  u64 v_c48 = m156[1];
                  u64 v_c49 = _prim_cins(db, v_c41, v_c46);
                  if (v_c49 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:11"); return; }
                  u64 v_c50 = _prim_cins(db, v_c49, v_c44);
                  if (v_c50 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:11"); return; }
                  slog::join_probe<2,2>(lallindex129, std::array<u64,2>{v_c48, v_c50}, [&](const std::array<u64,2>& m157) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c40, v_c13}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:11", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask130* _cont = new ReadTask130(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask130(db,b), true);
  // (crule (pre (let __tconst4DXM213 constd4735e3a265e16eee03f5971) (let __tconst3TF7215 const6b86b273ff34fce19d6b804e) (let __tconst8jgD218 const4e07408562bedb8b60ce05c1) (let __tconst9Q8n220 constba2df4903a2c14e86dc3bcca) (let __tconst9qld212 constb691e6cf801b704585f5c3f0) (let __t6kwB223 (cmap))) (probe ic (1 0) 1 __tconst4DXM213 __t54cr214) (body (exists llt (2 0 1) 1 __t54cr214) (exists ic (1 0) 1 __tconst8jgD218) (exists iv (1 0) 1 __tconst9Q8n220) (join ic (1 0) 1 __tconst3TF7215 __t4qrO216) (join llt (1 2 0) 2 __t4qrO216 __t54cr214 __t5gAW217) (join ic (1 0) 1 __tconst8jgD218 __t2ZyL219) (exists llt (2 0 1) 1 __t2ZyL219) (join iv (1 0) 1 __tconst9Q8n220 __t2yU7221) (join llt (1 2 0) 2 __t2yU7221 __t2ZyL219 __t43EA222) (join smt_check_ans (0 1) 0 __t4y3s227 V) (join smt_check (0 1) 1 __t4y3s227 __t8Mb5226) (let __t4jvF224 (cins __t6kwB223 __t43EA222)) (let __t7e0v225 (cins __t4jvF224 __t5gAW217)) (join lany (0 1) 2 __t8Mb5226 __t7e0v225)) (head (emit probe (0 1) __tconst9qld212 V)) smt_sets.slog:19 #f)
  class ReadTask170 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex158;  slog::Index** icindex159;  slog::Index** ivindex160;  slog::Index** icindex161;  slog::Index** lltindex162;  slog::Index** icindex163;  slog::Index** lltindex164;  slog::Index** ivindex165;  slog::Index** lltindex166;  slog::Index** smt_check_ansindex167;  slog::Index** smt_checkindex168;  slog::Index** lanyindex169;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("probe");
      head_index[0] = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 0});
      slog::Relation* readrel174 = db->getRelation("ic");
      driver_index = readrel174->getIndex(ord173, true);
      std::vector<u16> ord175({2, 0, 1});
      slog::Relation* readrel176 = db->getRelation("llt");
      lltindex158 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 0});
      slog::Relation* readrel178 = db->getRelation("ic");
      icindex159 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 0});
      slog::Relation* readrel180 = db->getRelation("iv");
      ivindex160 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 0});
      slog::Relation* readrel182 = db->getRelation("ic");
      icindex161 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 2, 0});
      slog::Relation* readrel184 = db->getRelation("llt");
      lltindex162 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 0});
      slog::Relation* readrel186 = db->getRelation("ic");
      icindex163 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({2, 0, 1});
      slog::Relation* readrel188 = db->getRelation("llt");
      lltindex164 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 0});
      slog::Relation* readrel190 = db->getRelation("iv");
      ivindex165 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 2, 0});
      slog::Relation* readrel192 = db->getRelation("llt");
      lltindex166 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({0, 1});
      slog::Relation* readrel194 = db->getRelation("smt_check_ans");
      smt_check_ansindex167 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({0, 1});
      slog::Relation* readrel196 = db->getRelation("smt_check");
      smt_checkindex168 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("lany");
      lanyindex169 = readrel198->getIndex(ord197, false);
  
    }
    ReadTask170(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c51 = v_constd4735e3a265e16eee03f5971;
      u64 v_c52 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c53 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c54 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c55 = v_constb691e6cf801b704585f5c3f0;
      u64 v_c56 = _prim_cmap(db);
      if (v_c56 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:19"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c51, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m199) {
        u64 v_c57 = m199[1];
        if (buckethash(v_c57) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex158, std::array<u64,3>{v_c57, 0, 0})) return;
        if (!slog::exists_probe<2,1>(icindex159, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex160, std::array<u64,2>{v_c54, 0})) return;
        slog::join_probe<2,1>(icindex161, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m200) {
          u64 v_c58 = m200[1];
          slog::join_probe<3,2>(lltindex162, std::array<u64,3>{v_c58, v_c57, 0}, [&](const std::array<u64,3>& m201) {
            u64 v_c59 = m201[2];
            slog::join_probe<2,1>(icindex163, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m202) {
              u64 v_c60 = m202[1];
              if (!slog::exists_probe<3,1>(lltindex164, std::array<u64,3>{v_c60, 0, 0})) return;
              slog::join_probe<2,1>(ivindex165, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m203) {
                u64 v_c61 = m203[1];
                slog::join_probe<3,2>(lltindex166, std::array<u64,3>{v_c61, v_c60, 0}, [&](const std::array<u64,3>& m204) {
                  u64 v_c62 = m204[2];
                  slog::join_all<2>(smt_check_ansindex167, [&](const std::array<u64,2>& m205) {
                    u64 v_c63 = m205[0]; u64 v_c13 = m205[1];
                    slog::join_probe<2,1>(smt_checkindex168, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m206) {
                      u64 v_c64 = m206[1];
                      u64 v_c65 = _prim_cins(db, v_c56, v_c62);
                      if (v_c65 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:19"); return; }
                      u64 v_c66 = _prim_cins(db, v_c65, v_c59);
                      if (v_c66 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:19"); return; }
                      slog::join_probe<2,2>(lanyindex169, std::array<u64,2>{v_c64, v_c66}, [&](const std::array<u64,2>& m207) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c55, v_c13}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("smt_sets.slog:19", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask170* _cont = new ReadTask170(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask170(db,b), true);
  // (crule (pre (let __tconst1nn8265 constab76c7d069d6f33dc950fb33)) (probe _enum (1 0) 1 __tconst1nn8265 __t1Z5x72) (body (join smt_check_ans (1 0) 1 __t1Z5x72 __t383v73) (join smt_check (0 1) 1 __t383v73 F)) (head (emit smt_sat (0) F)) smt.slog:77 #f)
  class ReadTask210 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex208;  slog::Index** smt_checkindex209;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_sat");
      std::vector<u16> ord211({0});
      slog::Relation* readrel212 = db->getRelation("smt_sat");
      head_index[0] = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 0});
      slog::Relation* readrel214 = db->getRelation("_enum");
      driver_index = readrel214->getIndex(ord213, true);
      std::vector<u16> ord215({1, 0});
      slog::Relation* readrel216 = db->getRelation("smt_check_ans");
      smt_check_ansindex208 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({0, 1});
      slog::Relation* readrel218 = db->getRelation("smt_check");
      smt_checkindex209 = readrel218->getIndex(ord217, false);
  
    }
    ReadTask210(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c67 = v_constab76c7d069d6f33dc950fb33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c67, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m219) {
        u64 v_c68 = m219[1];
        if (buckethash(v_c68) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex208, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m220) {
          u64 v_c69 = m220[1];
          slog::join_probe<2,1>(smt_checkindex209, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m221) {
            u64 v_c70 = m221[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c70}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:77", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask210* _cont = new ReadTask210(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask210(db,b), true);
  // (crule (pre (let __tconst1ygj66 const4b227777d4dd1fc61c6f884f) (let __tconst6Lkt68 const4e07408562bedb8b60ce05c1) (let __tconst4VPS65 constb69f26da5a485bf54a0c6dc6)) (probe ic (1 0) 1 __tconst1ygj66 __t8TB567) (body (exists lne (2 1 0) 1 __t8TB567) (join ic (1 0) 1 __tconst6Lkt68 __t2O2e69) (join lne (2 1 0) 2 __t8TB567 __t2O2e69 __t1oXF70) (join smt_check (1 0) 1 __t1oXF70 __t4LFp71) (join smt_check_ans (0 1) 1 __t4LFp71 V)) (head (emit probe (0 1) __tconst4VPS65 V)) smt_sets.slog:25 #f)
  class ReadTask227 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lneindex222;  slog::Index** icindex223;  slog::Index** lneindex224;  slog::Index** smt_checkindex225;  slog::Index** smt_check_ansindex226;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord228({0, 1});
      slog::Relation* readrel229 = db->getRelation("probe");
      head_index[0] = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("ic");
      driver_index = readrel231->getIndex(ord230, true);
      std::vector<u16> ord232({2, 1, 0});
      slog::Relation* readrel233 = db->getRelation("lne");
      lneindex222 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 0});
      slog::Relation* readrel235 = db->getRelation("ic");
      icindex223 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({2, 1, 0});
      slog::Relation* readrel237 = db->getRelation("lne");
      lneindex224 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 0});
      slog::Relation* readrel239 = db->getRelation("smt_check");
      smt_checkindex225 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({0, 1});
      slog::Relation* readrel241 = db->getRelation("smt_check_ans");
      smt_check_ansindex226 = readrel241->getIndex(ord240, false);
  
    }
    ReadTask227(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c71 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c72 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c73 = v_constb69f26da5a485bf54a0c6dc6;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c71, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m242) {
        u64 v_c74 = m242[1];
        if (buckethash(v_c74) != bucket) return;
        if (!slog::exists_probe<3,1>(lneindex222, std::array<u64,3>{v_c74, 0, 0})) return;
        slog::join_probe<2,1>(icindex223, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m243) {
          u64 v_c75 = m243[1];
          slog::join_probe<3,2>(lneindex224, std::array<u64,3>{v_c74, v_c75, 0}, [&](const std::array<u64,3>& m244) {
            u64 v_c76 = m244[2];
            slog::join_probe<2,1>(smt_checkindex225, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m245) {
              u64 v_c77 = m245[1];
              slog::join_probe<2,1>(smt_check_ansindex226, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m246) {
                u64 v_c13 = m246[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c73, v_c13}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:25", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask227* _cont = new ReadTask227(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask227(db,b), true);
  // (crule (pre (let __tconst3tkU263 consteb8bf0d80db323992f6b634a)) (probe _enum (1 0) 1 __tconst3tkU263 __t2P2s104) (body (join smt_check_ans (1 0) 1 __t2P2s104 __t1Upu105) (join smt_check (0 1) 1 __t1Upu105 F)) (head (emit smt_unknown (0) F)) smt.slog:79 #f)
  class ReadTask249 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex247;  slog::Index** smt_checkindex248;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_unknown");
      std::vector<u16> ord250({0});
      slog::Relation* readrel251 = db->getRelation("smt_unknown");
      head_index[0] = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 0});
      slog::Relation* readrel253 = db->getRelation("_enum");
      driver_index = readrel253->getIndex(ord252, true);
      std::vector<u16> ord254({1, 0});
      slog::Relation* readrel255 = db->getRelation("smt_check_ans");
      smt_check_ansindex247 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({0, 1});
      slog::Relation* readrel257 = db->getRelation("smt_check");
      smt_checkindex248 = readrel257->getIndex(ord256, false);
  
    }
    ReadTask249(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c78 = v_consteb8bf0d80db323992f6b634a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c78, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m258) {
        u64 v_c79 = m258[1];
        if (buckethash(v_c79) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex247, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m259) {
          u64 v_c80 = m259[1];
          slog::join_probe<2,1>(smt_checkindex248, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m260) {
            u64 v_c70 = m260[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c70}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:79", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask249* _cont = new ReadTask249(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask249(db,b), true);
  // (crule (pre) (scan modulo_by_zero __erre54Rn519 __errf5vlH520 __errf4RPg521) (body) (head (emit error (0) __erre54Rn519)) <internal>:1 #f)
  class ReadTask261 : public slog::Task
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
      std::vector<u16> ord262({0});
      slog::Relation* readrel263 = db->getRelation("error");
      head_index[0] = readrel263->getIndex(ord262, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask261(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c81 = _t[0];
        u64 v_c82 = _t[1];
        u64 v_c83 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c81}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask261* _cont = new ReadTask261(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask261(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre4BA0538 __errf5Fmn539 __errf0mzW540 __errf9xqX541 __errf3MXb542) (body) (head (emit error (0) __erre4BA0538)) <internal>:1 #f)
  class ReadTask264 : public slog::Task
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
      std::vector<u16> ord265({0});
      slog::Relation* readrel266 = db->getRelation("error");
      head_index[0] = readrel266->getIndex(ord265, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask264(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c84 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c86 = _t[2];
        u64 v_c87 = _t[3];
        u64 v_c88 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c84}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask264* _cont = new ReadTask264(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask264(db,b), false);
  // (crule (pre) (scan nan_result __erre6bNS526 __errf1zWU527 __errf9bPa528 __errf6zZ7529) (body) (head (emit error (0) __erre6bNS526)) <internal>:1 #f)
  class ReadTask267 : public slog::Task
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
      std::vector<u16> ord268({0});
      slog::Relation* readrel269 = db->getRelation("error");
      head_index[0] = readrel269->getIndex(ord268, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c89 = _t[0];
        u64 v_c90 = _t[1];
        u64 v_c91 = _t[2];
        u64 v_c92 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c89}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask267* _cont = new ReadTask267(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask267(db,b), false);
  // (crule (pre) (scan div_by_zero __erre3N2A516 __errf91jT517 __errf5nQx518) (body) (head (emit error (0) __erre3N2A516)) <internal>:1 #f)
  class ReadTask270 : public slog::Task
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
      std::vector<u16> ord271({0});
      slog::Relation* readrel272 = db->getRelation("error");
      head_index[0] = readrel272->getIndex(ord271, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask270(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c93 = _t[0];
        u64 v_c94 = _t[1];
        u64 v_c95 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c93}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask270* _cont = new ReadTask270(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask270(db,b), false);
  // (crule (pre) (scan toint_range __erre3P2W530 __errf6u0h531 __errf9xkD532) (body) (head (emit error (0) __erre3P2W530)) <internal>:1 #f)
  class ReadTask273 : public slog::Task
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
      std::vector<u16> ord274({0});
      slog::Relation* readrel275 = db->getRelation("error");
      head_index[0] = readrel275->getIndex(ord274, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask273(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c96 = _t[0];
        u64 v_c97 = _t[1];
        u64 v_c98 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c96}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask273* _cont = new ReadTask273(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask273(db,b), false);
  // (crule (pre (let __tconst5o6E129 const6b86b273ff34fce19d6b804e) (let __tconst3pDB127 constd4735e3a265e16eee03f5971) (let __tconst89TJ121 constab34826fd044c12689e8fac9) (let __t44zu132 (cmap))) (probe ic (1 0) 1 __tconst5o6E129 __t30bD125) (body (exists lgt (1 2 0) 1 __t30bD125) (exists llt (1 2 0) 1 __t30bD125) (join ic (1 0) 1 __tconst3pDB127 __t1TrD123) (exists llt (1 2 0) 2 __t30bD125 __t1TrD123) (join lgt (1 2 0) 2 __t30bD125 __t1TrD123 __t7edN131) (join llt (1 2 0) 2 __t30bD125 __t1TrD123 __t5buW126) (join smt_check_ans (0 1) 0 __t0LO7136 V) (join smt_check (0 1) 1 __t0LO7136 __t9D3P135) (let __t927X133 (cins __t44zu132 __t7edN131)) (let __t5yZs134 (cins __t927X133 __t5buW126)) (join lall (0 1) 2 __t9D3P135 __t5yZs134)) (head (emit probe (0 1) __tconst89TJ121 V)) smt_sets.slog:13 #f)
  class ReadTask285 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lgtindex276;  slog::Index** lltindex277;  slog::Index** icindex278;  slog::Index** lltindex279;  slog::Index** lgtindex280;  slog::Index** lltindex281;  slog::Index** smt_check_ansindex282;  slog::Index** smt_checkindex283;  slog::Index** lallindex284;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord286({0, 1});
      slog::Relation* readrel287 = db->getRelation("probe");
      head_index[0] = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 0});
      slog::Relation* readrel289 = db->getRelation("ic");
      driver_index = readrel289->getIndex(ord288, true);
      std::vector<u16> ord290({1, 2, 0});
      slog::Relation* readrel291 = db->getRelation("lgt");
      lgtindex276 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 2, 0});
      slog::Relation* readrel293 = db->getRelation("llt");
      lltindex277 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 0});
      slog::Relation* readrel295 = db->getRelation("ic");
      icindex278 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 2, 0});
      slog::Relation* readrel297 = db->getRelation("llt");
      lltindex279 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 2, 0});
      slog::Relation* readrel299 = db->getRelation("lgt");
      lgtindex280 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 2, 0});
      slog::Relation* readrel301 = db->getRelation("llt");
      lltindex281 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({0, 1});
      slog::Relation* readrel303 = db->getRelation("smt_check_ans");
      smt_check_ansindex282 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("smt_check");
      smt_checkindex283 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("lall");
      lallindex284 = readrel307->getIndex(ord306, false);
  
    }
    ReadTask285(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c100 = v_constd4735e3a265e16eee03f5971;
      u64 v_c101 = v_constab34826fd044c12689e8fac9;
      u64 v_c102 = _prim_cmap(db);
      if (v_c102 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:13"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c99, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m308) {
        u64 v_c103 = m308[1];
        if (buckethash(v_c103) != bucket) return;
        if (!slog::exists_probe<3,1>(lgtindex276, std::array<u64,3>{v_c103, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lltindex277, std::array<u64,3>{v_c103, 0, 0})) return;
        slog::join_probe<2,1>(icindex278, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m309) {
          u64 v_c104 = m309[1];
          if (!slog::exists_probe<3,2>(lltindex279, std::array<u64,3>{v_c103, v_c104, 0})) return;
          slog::join_probe<3,2>(lgtindex280, std::array<u64,3>{v_c103, v_c104, 0}, [&](const std::array<u64,3>& m310) {
            u64 v_c105 = m310[2];
            slog::join_probe<3,2>(lltindex281, std::array<u64,3>{v_c103, v_c104, 0}, [&](const std::array<u64,3>& m311) {
              u64 v_c106 = m311[2];
              slog::join_all<2>(smt_check_ansindex282, [&](const std::array<u64,2>& m312) {
                u64 v_c107 = m312[0]; u64 v_c13 = m312[1];
                slog::join_probe<2,1>(smt_checkindex283, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m313) {
                  u64 v_c108 = m313[1];
                  u64 v_c109 = _prim_cins(db, v_c102, v_c105);
                  if (v_c109 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:13"); return; }
                  u64 v_c110 = _prim_cins(db, v_c109, v_c106);
                  if (v_c110 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:13"); return; }
                  slog::join_probe<2,2>(lallindex284, std::array<u64,2>{v_c108, v_c110}, [&](const std::array<u64,2>& m314) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c101, v_c13}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:13", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask285* _cont = new ReadTask285(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask285(db,b), true);
  // (crule (pre) (scan mpz_table_overflow __erre1Q7Z543 __errf623e544 __errf9vWd545) (body) (head (emit error (0) __erre1Q7Z543)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
        u64 v_c111 = _t[0];
        u64 v_c112 = _t[1];
        u64 v_c113 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c111}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre (let __tconst0kpd152 constd4735e3a265e16eee03f5971) (let __tconst86Tv154 const6b86b273ff34fce19d6b804e) (let __tconst6oUR157 const4e07408562bedb8b60ce05c1) (let __tconst98EU159 constba2df4903a2c14e86dc3bcca) (let __tconst9T4p151 constf401a2e0aa4c55a3068789bc) (let __t4pCv162 (cmap))) (probe ic (1 0) 1 __tconst0kpd152 __t0JLY153) (body (exists llt (2 0 1) 1 __t0JLY153) (exists ic (1 0) 1 __tconst6oUR157) (exists iv (1 0) 1 __tconst98EU159) (join ic (1 0) 1 __tconst86Tv154 __t1LDg155) (join llt (1 2 0) 2 __t1LDg155 __t0JLY153 __t0xCD156) (join ic (1 0) 1 __tconst6oUR157 __t29zL158) (exists llt (2 0 1) 1 __t29zL158) (join iv (1 0) 1 __tconst98EU159 __t5Cqz160) (join llt (1 2 0) 2 __t5Cqz160 __t29zL158 __t2tuN161) (join smt_check_ans (0 1) 0 __t4xOb166 V) (join smt_check (0 1) 1 __t4xOb166 __t8J2Z165) (let __t9LSi163 (cins __t4pCv162 __t2tuN161)) (let __t2y49164 (cins __t9LSi163 __t0xCD156)) (join lall (0 1) 2 __t8J2Z165 __t2y49164)) (head (emit probe (0 1) __tconst9T4p151 V)) smt_sets.slog:17 #f)
  class ReadTask330 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex318;  slog::Index** icindex319;  slog::Index** ivindex320;  slog::Index** icindex321;  slog::Index** lltindex322;  slog::Index** icindex323;  slog::Index** lltindex324;  slog::Index** ivindex325;  slog::Index** lltindex326;  slog::Index** smt_check_ansindex327;  slog::Index** smt_checkindex328;  slog::Index** lallindex329;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord331({0, 1});
      slog::Relation* readrel332 = db->getRelation("probe");
      head_index[0] = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 0});
      slog::Relation* readrel334 = db->getRelation("ic");
      driver_index = readrel334->getIndex(ord333, true);
      std::vector<u16> ord335({2, 0, 1});
      slog::Relation* readrel336 = db->getRelation("llt");
      lltindex318 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({1, 0});
      slog::Relation* readrel338 = db->getRelation("ic");
      icindex319 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 0});
      slog::Relation* readrel340 = db->getRelation("iv");
      ivindex320 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 0});
      slog::Relation* readrel342 = db->getRelation("ic");
      icindex321 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 0});
      slog::Relation* readrel344 = db->getRelation("llt");
      lltindex322 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 0});
      slog::Relation* readrel346 = db->getRelation("ic");
      icindex323 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({2, 0, 1});
      slog::Relation* readrel348 = db->getRelation("llt");
      lltindex324 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 0});
      slog::Relation* readrel350 = db->getRelation("iv");
      ivindex325 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("llt");
      lltindex326 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({0, 1});
      slog::Relation* readrel354 = db->getRelation("smt_check_ans");
      smt_check_ansindex327 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({0, 1});
      slog::Relation* readrel356 = db->getRelation("smt_check");
      smt_checkindex328 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("lall");
      lallindex329 = readrel358->getIndex(ord357, false);
  
    }
    ReadTask330(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_constd4735e3a265e16eee03f5971;
      u64 v_c115 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c116 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c117 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c118 = v_constf401a2e0aa4c55a3068789bc;
      u64 v_c119 = _prim_cmap(db);
      if (v_c119 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:17"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c114, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m359) {
        u64 v_c120 = m359[1];
        if (buckethash(v_c120) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex318, std::array<u64,3>{v_c120, 0, 0})) return;
        if (!slog::exists_probe<2,1>(icindex319, std::array<u64,2>{v_c116, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex320, std::array<u64,2>{v_c117, 0})) return;
        slog::join_probe<2,1>(icindex321, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m360) {
          u64 v_c121 = m360[1];
          slog::join_probe<3,2>(lltindex322, std::array<u64,3>{v_c121, v_c120, 0}, [&](const std::array<u64,3>& m361) {
            u64 v_c122 = m361[2];
            slog::join_probe<2,1>(icindex323, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m362) {
              u64 v_c123 = m362[1];
              if (!slog::exists_probe<3,1>(lltindex324, std::array<u64,3>{v_c123, 0, 0})) return;
              slog::join_probe<2,1>(ivindex325, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m363) {
                u64 v_c124 = m363[1];
                slog::join_probe<3,2>(lltindex326, std::array<u64,3>{v_c124, v_c123, 0}, [&](const std::array<u64,3>& m364) {
                  u64 v_c125 = m364[2];
                  slog::join_all<2>(smt_check_ansindex327, [&](const std::array<u64,2>& m365) {
                    u64 v_c126 = m365[0]; u64 v_c13 = m365[1];
                    slog::join_probe<2,1>(smt_checkindex328, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m366) {
                      u64 v_c127 = m366[1];
                      u64 v_c128 = _prim_cins(db, v_c119, v_c125);
                      if (v_c128 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:17"); return; }
                      u64 v_c129 = _prim_cins(db, v_c128, v_c122);
                      if (v_c129 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:17"); return; }
                      slog::join_probe<2,2>(lallindex329, std::array<u64,2>{v_c127, v_c129}, [&](const std::array<u64,2>& m367) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c118, v_c13}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("smt_sets.slog:17", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask330* _cont = new ReadTask330(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask330(db,b), true);
  // (crule (pre) (scan type_mismatch __erre8VKJ533 __errf4eXc534 __errf7t2g535 __errf2kJs536 __errf8Cxt537) (body) (head (emit error (0) __erre8VKJ533)) <internal>:1 #f)
  class ReadTask368 : public slog::Task
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
      std::vector<u16> ord369({0});
      slog::Relation* readrel370 = db->getRelation("error");
      head_index[0] = readrel370->getIndex(ord369, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask368(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c130 = _t[0];
        u64 v_c131 = _t[1];
        u64 v_c132 = _t[2];
        u64 v_c133 = _t[3];
        u64 v_c134 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c130}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask368* _cont = new ReadTask368(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask368(db,b), false);
  // (crule (pre (let __tconst5baB275 consta221beeaebe583607e193be7)) (probe _enum (1 0) 1 __tconst5baB275 __t4wOW228) (body (join smt_check_ans (1 0) 1 __t4wOW228 __t44sM229) (join smt_check (0 1) 1 __t44sM229 F)) (head (emit smt_unsat (0) F)) smt.slog:78 #f)
  class ReadTask373 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex371;  slog::Index** smt_checkindex372;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_unsat");
      std::vector<u16> ord374({0});
      slog::Relation* readrel375 = db->getRelation("smt_unsat");
      head_index[0] = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 0});
      slog::Relation* readrel377 = db->getRelation("_enum");
      driver_index = readrel377->getIndex(ord376, true);
      std::vector<u16> ord378({1, 0});
      slog::Relation* readrel379 = db->getRelation("smt_check_ans");
      smt_check_ansindex371 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({0, 1});
      slog::Relation* readrel381 = db->getRelation("smt_check");
      smt_checkindex372 = readrel381->getIndex(ord380, false);
  
    }
    ReadTask373(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c135 = v_consta221beeaebe583607e193be7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c135, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m382) {
        u64 v_c136 = m382[1];
        if (buckethash(v_c136) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex371, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m383) {
          u64 v_c137 = m383[1];
          slog::join_probe<2,1>(smt_checkindex372, std::array<u64,2>{v_c137, 0}, [&](const std::array<u64,2>& m384) {
            u64 v_c70 = m384[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c70}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:78", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask373* _cont = new ReadTask373(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask373(db,b), true);
  // (crule (pre) (scan int_overflow __erre85ma522 __errf4Wv8523 __errf9SWL524 __errf6KjK525) (body) (head (emit error (0) __erre85ma522)) <internal>:1 #f)
  class ReadTask385 : public slog::Task
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
      std::vector<u16> ord386({0});
      slog::Relation* readrel387 = db->getRelation("error");
      head_index[0] = readrel387->getIndex(ord386, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask385(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c138 = _t[0];
        u64 v_c139 = _t[1];
        u64 v_c140 = _t[2];
        u64 v_c141 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c138}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask385* _cont = new ReadTask385(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask385(db,b), false);
  s->addReadRel("_enum");
  s->addReadRel("div_by_zero");
  s->addReadRel("ic");
  s->addReadRel("int_overflow");
  s->addReadRel("iv");
  s->addReadRel("lall");
  s->addReadRel("lany");
  s->addReadRel("leq");
  s->addReadRel("lgt");
  s->addReadRel("lite");
  s->addReadRel("lle");
  s->addReadRel("llt");
  s->addReadRel("lne");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("smt_check");
  s->addReadRel("smt_check_ans");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("probe");
  s->addDynamicRel("smt_sat");
  s->addDynamicRel("smt_unknown");
  s->addDynamicRel("smt_unsat");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

