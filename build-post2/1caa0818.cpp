
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constf5ca38f748a1d6eaf726b8a4;
u64 v_constef2d127de37b942baad06145;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_consta221beeaebe583607e193be7;
u64 v_constab76c7d069d6f33dc950fb33;
u64 v_consteb8bf0d80db323992f6b634a;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constba2df4903a2c14e86dc3bcca;
u64 v_const683276d23a1fc1d255583994;
u64 v_constee295786ce9f03797df76c26;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("1caa0818");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constf5ca38f748a1d6eaf726b8a4 = s32_encode(20);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_consta221beeaebe583607e193be7 = db->encodeString("unsat");
  v_constab76c7d069d6f33dc950fb33 = db->encodeString("sat");
  v_consteb8bf0d80db323992f6b634a = db->encodeString("unknown");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constba2df4903a2c14e86dc3bcca = db->encodeString("x");
  v_const683276d23a1fc1d255583994 = db->encodeString("ltrue");
  v_constee295786ce9f03797df76c26 = db->encodeString("lfalse");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord651({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord651, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord652({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord652, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord653({1, 2, 0});
    
    r->addIndex<3>(ord653, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord654({0, 1, 2});
    
    r->addIndex<3>(ord654, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_vcode");
  if (r == 0) db->addRelation("smt_vcode", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_vcode");
      std::vector<u16> ord655({0, 1});
    
    r->addIndex<2>(ord655, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_vcode"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_unsat");
  if (r == 0) db->addRelation("smt_unsat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unsat");
      std::vector<u16> ord656({0});
    
    r->addIndex<1>(ord656, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unsat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_unknown");
  if (r == 0) db->addRelation("smt_unknown", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unknown");
      std::vector<u16> ord657({0});
    
    r->addIndex<1>(ord657, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unknown"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_sat");
  if (r == 0) db->addRelation("smt_sat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_sat");
      std::vector<u16> ord658({0});
    
    r->addIndex<1>(ord658, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_sat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_qsat_ans");
  if (r == 0) db->addRelation("smt_qsat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord659({0, 1});
    
    r->addIndex<2>(ord659, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qsat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qsat");
  if (r == 0) db->addStruct("smt_qsat", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat");
      std::vector<u16> ord660({1, 0});
    
    r->addIndex<2>(ord660, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord661({0, 1});
    
    r->addIndex<2>(ord661, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qsat"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qmodel_ans");
  if (r == 0) db->addRelation("smt_qmodel_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel_ans");
      std::vector<u16> ord662({0, 1});
    
    r->addIndex<2>(ord662, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qmodel_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qmodel");
  if (r == 0) db->addStruct("smt_qmodel", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel");
      std::vector<u16> ord663({1, 0});
    
    r->addIndex<2>(ord663, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord664({0, 1});
    
    r->addIndex<2>(ord664, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qmodel"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qcore_ans");
  if (r == 0) db->addRelation("smt_qcore_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore_ans");
      std::vector<u16> ord665({0, 1});
    
    r->addIndex<2>(ord665, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qcore_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qcore");
  if (r == 0) db->addStruct("smt_qcore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore");
      std::vector<u16> ord666({1, 0});
    
    r->addIndex<2>(ord666, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord667({0, 1});
    
    r->addIndex<2>(ord667, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qcore"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_model_ans");
  if (r == 0) db->addRelation("smt_model_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model_ans");
      std::vector<u16> ord668({0, 1, 2});
    
    r->addIndex<3>(ord668, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_model_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_model");
  if (r == 0) db->addStruct("smt_model", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model");
      std::vector<u16> ord669({1, 0});
    
    r->addIndex<2>(ord669, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord670({0, 1});
    
    r->addIndex<2>(ord670, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_model"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_core_ans");
  if (r == 0) db->addRelation("smt_core_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core_ans");
      std::vector<u16> ord671({0, 1, 2});
    
    r->addIndex<3>(ord671, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_core_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_core");
  if (r == 0) db->addStruct("smt_core", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core");
      std::vector<u16> ord672({1, 0});
    
    r->addIndex<2>(ord672, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord673({0, 1});
    
    r->addIndex<2>(ord673, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_core"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check_ans");
  if (r == 0) db->addRelation("smt_check_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check_ans");
      std::vector<u16> ord674({0, 1});
    
    r->addIndex<2>(ord674, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_check_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_check");
  if (r == 0) db->addStruct("smt_check", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check");
      std::vector<u16> ord675({1, 0});
    
    r->addIndex<2>(ord675, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord676({0, 1});
    
    r->addIndex<2>(ord676, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_check"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord677({1, 2, 0});
    
    r->addIndex<3>(ord677, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord678({0, 1, 2});
    
    r->addIndex<3>(ord678, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord679({0, 1});
    
    r->addIndex<2>(ord679, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("probe"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord680({1, 2, 3, 0});
    
    r->addIndex<4>(ord680, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord681({0, 1, 2, 3});
    
    r->addIndex<4>(ord681, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord682({1, 2, 0});
    
    r->addIndex<3>(ord682, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord683({0, 1, 2});
    
    r->addIndex<3>(ord683, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord684({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord684, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord685({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord685, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord686({1, 2, 0});
    
    r->addIndex<3>(ord686, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord687({0, 1, 2});
    
    r->addIndex<3>(ord687, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord688({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord688, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord689({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord689, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lsub");
  if (r == 0) db->addStruct("lsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lsub");
      std::vector<u16> ord690({2, 1, 0});
    
    r->addIndex<3>(ord690, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord691({0, 2, 1});
    
    r->addIndex<3>(ord691, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lsub"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lor");
  if (r == 0) db->addStruct("lor", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lor");
      std::vector<u16> ord692({1, 2, 0});
    
    r->addIndex<3>(ord692, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord693({0, 1, 2});
    
    r->addIndex<3>(ord693, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lor"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lnot");
  if (r == 0) db->addStruct("lnot", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lnot");
      std::vector<u16> ord694({1, 0});
    
    r->addIndex<2>(ord694, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord695({0, 1});
    
    r->addIndex<2>(ord695, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lnot"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lne");
  if (r == 0) db->addStruct("lne", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lne");
      std::vector<u16> ord696({1, 2, 0});
    
    r->addIndex<3>(ord696, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord697({0, 1, 2});
    
    r->addIndex<3>(ord697, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lne"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lmul");
  if (r == 0) db->addStruct("lmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lmul");
      std::vector<u16> ord698({1, 2, 0});
    
    r->addIndex<3>(ord698, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord699({0, 1, 2});
    
    r->addIndex<3>(ord699, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lmul"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("llt");
  if (r == 0) db->addStruct("llt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("llt");
      std::vector<u16> ord700({2, 1, 0});
    
    r->addIndex<3>(ord700, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord701({0, 2, 1});
    
    r->addIndex<3>(ord701, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("llt"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lle");
  if (r == 0) db->addStruct("lle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lle");
      std::vector<u16> ord702({2, 1, 0});
    
    r->addIndex<3>(ord702, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord703({0, 1, 2});
    
    r->addIndex<3>(ord703, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lle"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lite");
  if (r == 0) db->addStruct("lite", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lite");
      std::vector<u16> ord704({1, 2, 3, 0});
    
    r->addIndex<4>(ord704, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord705({0, 1, 2, 3});
    
    r->addIndex<4>(ord705, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("lite"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("limplies");
  if (r == 0) db->addStruct("limplies", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("limplies");
      std::vector<u16> ord706({1, 2, 0});
    
    r->addIndex<3>(ord706, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord707({0, 1, 2});
    
    r->addIndex<3>(ord707, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord708({2, 0, 1});
    
    r->addIndex<3>(ord708, false, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTaskSeeded(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b));
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("limplies"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lgt");
  if (r == 0) db->addStruct("lgt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lgt");
      std::vector<u16> ord709({1, 2, 0});
    
    r->addIndex<3>(ord709, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord710({0, 1, 2});
    
    r->addIndex<3>(ord710, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lgt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lge");
  if (r == 0) db->addStruct("lge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lge");
      std::vector<u16> ord711({1, 2, 0});
    
    r->addIndex<3>(ord711, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord712({0, 1, 2});
    
    r->addIndex<3>(ord712, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lge"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("leq");
  if (r == 0) db->addStruct("leq", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leq");
      std::vector<u16> ord713({2, 1, 0});
    
    r->addIndex<3>(ord713, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord714({0, 1, 2});
    
    r->addIndex<3>(ord714, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("leq"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lany");
  if (r == 0) db->addStruct("lany", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lany");
      std::vector<u16> ord715({1, 0});
    
    r->addIndex<2>(ord715, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord716({0, 1});
    
    r->addIndex<2>(ord716, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lany"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("land");
  if (r == 0) db->addStruct("land", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("land");
      std::vector<u16> ord717({1, 2, 0});
    
    r->addIndex<3>(ord717, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord718({0, 1, 2});
    
    r->addIndex<3>(ord718, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("land"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lall");
  if (r == 0) db->addStruct("lall", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lall");
      std::vector<u16> ord719({1, 0});
    
    r->addIndex<2>(ord719, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord720({0, 1});
    
    r->addIndex<2>(ord720, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lall"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ladd");
  if (r == 0) db->addStruct("ladd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ladd");
      std::vector<u16> ord721({1, 2, 0});
    
    r->addIndex<3>(ord721, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord722({0, 1, 2});
    
    r->addIndex<3>(ord722, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ladd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("iv");
  if (r == 0) db->addStruct("iv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("iv");
      std::vector<u16> ord723({1, 0});
    
    r->addIndex<2>(ord723, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord724({0, 1});
    
    r->addIndex<2>(ord724, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("iv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord725({1, 2, 3, 0});
    
    r->addIndex<4>(ord725, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord726({0, 1, 2, 3});
    
    r->addIndex<4>(ord726, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ic");
  if (r == 0) db->addStruct("ic", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ic");
      std::vector<u16> ord727({1, 0});
    
    r->addIndex<2>(ord727, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord728({0, 1});
    
    r->addIndex<2>(ord728, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord729({1, 0});
    
    r->addIndex<2>(ord729, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ic"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord730({0});
    
    r->addIndex<1>(ord730, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("elidable");
  if (r == 0) db->addRelation("elidable", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("elidable");
      std::vector<u16> ord731({0});
    
    r->addIndex<1>(ord731, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("elidable"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord732({1, 2, 0});
    
    r->addIndex<3>(ord732, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord733({0, 1, 2});
    
    r->addIndex<3>(ord733, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bv");
  if (r == 0) db->addStruct("bv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bv");
      std::vector<u16> ord734({1, 0});
    
    r->addIndex<2>(ord734, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord735({0, 1});
    
    r->addIndex<2>(ord735, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("bv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord736({1, 0});
    
    r->addIndex<2>(ord736, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord737({0, 1});
    
    r->addIndex<2>(ord737, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord738({1, 0});
    
    r->addIndex<2>(ord738, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst8EPI88 const6b86b273ff34fce19d6b804e) (let __tconst6cbw86 constd4735e3a265e16eee03f5971) (let __tconst41fh171 constee295786ce9f03797df76c26)) (seeded) (body (join ic (1 0) 1 __tconst6cbw86 __t8kmG87) (exists llt (2 1 0) 1 __t8kmG87) (exists _enum (1 0) 1 __tconst41fh171) (join ic (1 0) 1 __tconst8EPI88 __t1FpX89) (join llt (2 1 0) 2 __t8kmG87 __t1FpX89 __t996G90) (join _enum (1 0) 1 __tconst41fh171 __t8YNr84) (join lnot (1 0) 1 __t8YNr84 __t3Zrq85)) (head (mkstruct land (1 2 0) __t3IQi91 __t996G90 __t3Zrq85)) smt_basic.slog:8 #f)
  class ReadTask7 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex0;  slog::Index** lltindex1;  slog::Index** _enumindex2;  slog::Index** icindex3;  slog::Index** lltindex4;  slog::Index** _enumindex5;  slog::Index** lnotindex6;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("land");
      std::vector<u16> ord8({1, 2, 0});
      slog::Relation* readrel9 = db->getRelation("land");
      head_index[0] = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 0});
      slog::Relation* readrel11 = db->getRelation("ic");
      icindex0 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({2, 1, 0});
      slog::Relation* readrel13 = db->getRelation("llt");
      lltindex1 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("_enum");
      _enumindex2 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("ic");
      icindex3 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({2, 1, 0});
      slog::Relation* readrel19 = db->getRelation("llt");
      lltindex4 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 0});
      slog::Relation* readrel21 = db->getRelation("_enum");
      _enumindex5 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("lnot");
      lnotindex6 = readrel23->getIndex(ord22, false);
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_constee295786ce9f03797df76c26;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m24) {
        u64 v_c3 = m24[1];
        if (!slog::exists_probe<3,1>(lltindex1, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex2, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<2,1>(icindex3, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m25) {
          u64 v_c4 = m25[1];
          slog::join_probe<3,2>(lltindex4, std::array<u64,3>{v_c3, v_c4, 0}, [&](const std::array<u64,3>& m26) {
            u64 v_c5 = m26[2];
            slog::join_probe<2,1>(_enumindex5, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m27) {
              u64 v_c6 = m27[1];
              slog::join_probe<2,1>(lnotindex6, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m28) {
                u64 v_c7 = m28[1];
                ++_fires;
                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c7}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:8", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask7(db,b));
  // (crule (pre (let __tconst1Iia76 constef2d127de37b942baad06145) (let __tconst2drD80 constd4735e3a265e16eee03f5971)) (seeded) (body (join ic (1 0) 1 __tconst1Iia76 __t1a6n77) (exists leq (2 1 0) 1 __t1a6n77) (join ic (1 0) 1 __tconst2drD80 __t74zv79) (join ladd (1 2 0) 1 __t74zv79 dup5Nne189 __t6zo982) (eq __t74zv79 dup5Nne189) (join leq (2 1 0) 2 __t1a6n77 __t6zo982 __t75M183)) (head (mkstruct smt_check (1 0) __9k7v155 __t75M183)) smt_basic.slog:10 #f)
  class ReadTask34 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex29;  slog::Index** leqindex30;  slog::Index** icindex31;  slog::Index** laddindex32;  slog::Index** leqindex33;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("smt_check");
      head_index[0] = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 0});
      slog::Relation* readrel38 = db->getRelation("ic");
      icindex29 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({2, 1, 0});
      slog::Relation* readrel40 = db->getRelation("leq");
      leqindex30 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 0});
      slog::Relation* readrel42 = db->getRelation("ic");
      icindex31 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("ladd");
      laddindex32 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({2, 1, 0});
      slog::Relation* readrel46 = db->getRelation("leq");
      leqindex33 = readrel46->getIndex(ord45, false);
  
    }
    ReadTask34(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c8 = v_constef2d127de37b942baad06145;
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex29, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m47) {
        u64 v_c10 = m47[1];
        if (!slog::exists_probe<3,1>(leqindex30, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<2,1>(icindex31, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m48) {
          u64 v_c11 = m48[1];
          slog::join_probe<3,1>(laddindex32, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m49) {
            u64 v_c12 = m49[1]; u64 v_c13 = m49[2];
            if (v_c11 != v_c12) return;
            slog::join_probe<3,2>(leqindex33, std::array<u64,3>{v_c10, v_c13, 0}, [&](const std::array<u64,3>& m50) {
              u64 v_c14 = m50[2];
              ++_fires;
              slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:10", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask34(db,b));
  // (crule (pre (let __tconst0X1L27 const4e07408562bedb8b60ce05c1) (let __tconst04Cq22 constf5ca38f748a1d6eaf726b8a4) (let __tconst0b4S20 const4a44dc15364204a80fe80e90)) (scan lsub __t4ZiJ24 __t1cqm23 __t87vP21) (body (join ic (0 1) 2 __t87vP21 __tconst0b4S20) (join ic (0 1) 2 __t1cqm23 __tconst04Cq22) (join ic (1 0) 1 __tconst0X1L27 __t0xP526) (join lmul (1 2 0) 1 __t0xP526 dup13tP190 __t58Cx29) (eq __t0xP526 dup13tP190)) (head (mkstruct lle (2 1 0) __t74uX30 __t4ZiJ24 __t58Cx29)) smt_basic.slog:16 #f)
  class ReadTask55 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex51;  slog::Index** icindex52;  slog::Index** icindex53;  slog::Index** lmulindex54;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lle");
      outer_rel = db->getRelation("lsub");
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("ic");
      icindex51 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({0, 1});
      slog::Relation* readrel59 = db->getRelation("ic");
      icindex52 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 0});
      slog::Relation* readrel61 = db->getRelation("ic");
      icindex53 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({1, 2, 0});
      slog::Relation* readrel63 = db->getRelation("lmul");
      lmulindex54 = readrel63->getIndex(ord62, false);
  
    }
    ReadTask55(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c17 = v_const4a44dc15364204a80fe80e90;
  
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
        slog::join_probe<2,2>(icindex51, std::array<u64,2>{v_c20, v_c17}, [&](const std::array<u64,2>& m64) {
          slog::join_probe<2,2>(icindex52, std::array<u64,2>{v_c19, v_c16}, [&](const std::array<u64,2>& m65) {
            slog::join_probe<2,1>(icindex53, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m66) {
              u64 v_c21 = m66[1];
              slog::join_probe<3,1>(lmulindex54, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m67) {
                u64 v_c22 = m67[1]; u64 v_c23 = m67[2];
                if (v_c21 != v_c22) return;
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c18, v_c23}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:16", "delta:lsub", _fires);
  
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
  // (crule (pre (let __tconst1W3y66 constba2df4903a2c14e86dc3bcca) (let __tconst00QZ64 const4e07408562bedb8b60ce05c1)) (probe ic (1 0) 1 __tconst00QZ64 __t5QTY65) (body (join iv (1 0) 1 __tconst1W3y66 __t1Wob67)) (head (mkstruct llt (2 1 0) __t4aF868 __t5QTY65 __t1Wob67)) smt_basic.slog:25 #f)
  class ReadTask69 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ivindex68;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord70({1, 0});
      slog::Relation* readrel71 = db->getRelation("ic");
      driver_index = readrel71->getIndex(ord70, true);
      std::vector<u16> ord72({1, 0});
      slog::Relation* readrel73 = db->getRelation("iv");
      ivindex68 = readrel73->getIndex(ord72, false);
  
    }
    ReadTask69(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c25 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c25, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m74) {
        u64 v_c26 = m74[1];
        if (buckethash(v_c26) != bucket) return;
        slog::join_probe<2,1>(ivindex68, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m75) {
          u64 v_c27 = m75[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c26, v_c27}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:25", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask69* _cont = new ReadTask69(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask69(db,b), false);
  // (crule (pre (let __tconst2drD80 constd4735e3a265e16eee03f5971) (let __tconst1Iia76 constef2d127de37b942baad06145)) (seeded) (body (join ic (1 0) 1 __tconst1Iia76 __t1a6n77) (join ic (1 0) 1 __tconst2drD80 __t74zv79) (join ladd (1 2 0) 1 __t74zv79 dup04ie187 __t6zo982) (eq __t74zv79 dup04ie187)) (head (mkstruct leq (2 1 0) __t75M183 __t1a6n77 __t6zo982)) smt_basic.slog:10 #f)
  class ReadTask79 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex76;  slog::Index** icindex77;  slog::Index** laddindex78;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("leq");
      std::vector<u16> ord80({2, 1, 0});
      slog::Relation* readrel81 = db->getRelation("leq");
      head_index[0] = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 0});
      slog::Relation* readrel83 = db->getRelation("ic");
      icindex76 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 0});
      slog::Relation* readrel85 = db->getRelation("ic");
      icindex77 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 0});
      slog::Relation* readrel87 = db->getRelation("ladd");
      laddindex78 = readrel87->getIndex(ord86, false);
  
    }
    ReadTask79(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex76, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m88) {
        u64 v_c10 = m88[1];
        slog::join_probe<2,1>(icindex77, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m89) {
          u64 v_c11 = m89[1];
          slog::join_probe<3,1>(laddindex78, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m90) {
            u64 v_c28 = m90[1]; u64 v_c13 = m90[2];
            if (v_c11 != v_c28) return;
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c13}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:10", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask79(db,b));
  // (crule (pre (let __tconst0X1L27 const4e07408562bedb8b60ce05c1) (let __tconst04Cq22 constf5ca38f748a1d6eaf726b8a4) (let __tconst0b4S20 const4a44dc15364204a80fe80e90)) (probe ic (1 0) 1 __tconst0b4S20 __t87vP21) (body (exists ic (1 0) 1 __tconst0X1L27) (join ic (1 0) 1 __tconst04Cq22 __t1cqm23) (join ic (1 0) 1 __tconst0X1L27 __t0xP526)) (head (mkstruct lmul (1 2 0) __t58Cx29 __t0xP526 __t0xP526) (mkstruct lsub (2 1 0) __t4ZiJ24 __t87vP21 __t1cqm23)) smt_basic.slog:16 #f)
  class ReadTask94 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex91;  slog::Index** icindex92;  slog::Index** icindex93;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lmul");
      head_rel[1] = db->getRelation("lsub");
      std::vector<u16> ord95({1, 0});
      slog::Relation* readrel96 = db->getRelation("ic");
      driver_index = readrel96->getIndex(ord95, true);
      std::vector<u16> ord97({1, 0});
      slog::Relation* readrel98 = db->getRelation("ic");
      icindex91 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 0});
      slog::Relation* readrel100 = db->getRelation("ic");
      icindex92 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("ic");
      icindex93 = readrel102->getIndex(ord101, false);
  
    }
    ReadTask94(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c17 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c17, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m103) {
        u64 v_c20 = m103[1];
        if (buckethash(v_c20) != bucket) return;
        if (!slog::exists_probe<2,1>(icindex91, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<2,1>(icindex92, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m104) {
          u64 v_c19 = m104[1];
          slog::join_probe<2,1>(icindex93, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m105) {
            u64 v_c21 = m105[1];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c21, v_c21}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c20, v_c19}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_basic.slog:16", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask94* _cont = new ReadTask94(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask94(db,b), false);
  // (crule (pre (let __tconst9yI933 constef2d127de37b942baad06145) (let __tconst529i37 constd4735e3a265e16eee03f5971)) (seeded) (body (join ic (1 0) 1 __tconst9yI933 __t6kCx34) (exists leq (2 1 0) 1 __t6kCx34) (join ic (1 0) 1 __tconst529i37 __t0K9T36) (join ladd (1 2 0) 1 __t0K9T36 dup82dw197 __t0WxP39) (eq __t0K9T36 dup82dw197) (join leq (2 1 0) 2 __t6kCx34 __t0WxP39 __t6kVM40)) (head (mkstruct smt_check (1 0) __0VVz160 __t6kVM40)) smt_basic.slog:21 #f)
  class ReadTask111 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex106;  slog::Index** leqindex107;  slog::Index** icindex108;  slog::Index** laddindex109;  slog::Index** leqindex110;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord112({1, 0});
      slog::Relation* readrel113 = db->getRelation("smt_check");
      head_index[0] = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({1, 0});
      slog::Relation* readrel115 = db->getRelation("ic");
      icindex106 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({2, 1, 0});
      slog::Relation* readrel117 = db->getRelation("leq");
      leqindex107 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 0});
      slog::Relation* readrel119 = db->getRelation("ic");
      icindex108 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 2, 0});
      slog::Relation* readrel121 = db->getRelation("ladd");
      laddindex109 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({2, 1, 0});
      slog::Relation* readrel123 = db->getRelation("leq");
      leqindex110 = readrel123->getIndex(ord122, false);
  
    }
    ReadTask111(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_constef2d127de37b942baad06145;
      u64 v_c30 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex106, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m124) {
        u64 v_c31 = m124[1];
        if (!slog::exists_probe<3,1>(leqindex107, std::array<u64,3>{v_c31, 0, 0})) return;
        slog::join_probe<2,1>(icindex108, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m125) {
          u64 v_c32 = m125[1];
          slog::join_probe<3,1>(laddindex109, std::array<u64,3>{v_c32, 0, 0}, [&](const std::array<u64,3>& m126) {
            u64 v_c33 = m126[1]; u64 v_c34 = m126[2];
            if (v_c32 != v_c33) return;
            slog::join_probe<3,2>(leqindex110, std::array<u64,3>{v_c31, v_c34, 0}, [&](const std::array<u64,3>& m127) {
              u64 v_c35 = m127[2];
              ++_fires;
              slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c35}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:21", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask111(db,b));
  // (crule (pre (let __tconst8EPI88 const6b86b273ff34fce19d6b804e) (let __tconst6cbw86 constd4735e3a265e16eee03f5971) (let __tconst41fh171 constee295786ce9f03797df76c26)) (scan land __t3IQi91 __t996G90 __t3Zrq85) (body (exists _enum (1 0) 1 __tconst41fh171) (exists ic (1 0) 1 __tconst6cbw86) (exists ic (1 0) 1 __tconst8EPI88) (join lnot (0 1) 1 __t3Zrq85 __t8YNr84) (join _enum (0 1) 2 __t8YNr84 __tconst41fh171) (join ic (1 0) 1 __tconst6cbw86 __t8kmG87) (join llt (0 2 1) 2 __t996G90 __t8kmG87 __t1FpX89) (join ic (0 1) 2 __t1FpX89 __tconst8EPI88)) (head (mkstruct smt_check (1 0) __2kIP170 __t3IQi91)) smt_basic.slog:8 #f)
  class ReadTask136 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex128;  slog::Index** icindex129;  slog::Index** icindex130;  slog::Index** lnotindex131;  slog::Index** _enumindex132;  slog::Index** icindex133;  slog::Index** lltindex134;  slog::Index** icindex135;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("land");
      std::vector<u16> ord137({1, 0});
      slog::Relation* readrel138 = db->getRelation("_enum");
      _enumindex128 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 0});
      slog::Relation* readrel140 = db->getRelation("ic");
      icindex129 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 0});
      slog::Relation* readrel142 = db->getRelation("ic");
      icindex130 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({0, 1});
      slog::Relation* readrel144 = db->getRelation("lnot");
      lnotindex131 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("_enum");
      _enumindex132 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({1, 0});
      slog::Relation* readrel148 = db->getRelation("ic");
      icindex133 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 2, 1});
      slog::Relation* readrel150 = db->getRelation("llt");
      lltindex134 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({0, 1});
      slog::Relation* readrel152 = db->getRelation("ic");
      icindex135 = readrel152->getIndex(ord151, false);
  
    }
    ReadTask136(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_constee295786ce9f03797df76c26;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c36 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<2,1>(_enumindex128, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(icindex129, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(icindex130, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(lnotindex131, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m153) {
          u64 v_c6 = m153[1];
          slog::join_probe<2,2>(_enumindex132, std::array<u64,2>{v_c6, v_c2}, [&](const std::array<u64,2>& m154) {
            slog::join_probe<2,1>(icindex133, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m155) {
              u64 v_c3 = m155[1];
              slog::join_probe<3,2>(lltindex134, std::array<u64,3>{v_c5, v_c3, 0}, [&](const std::array<u64,3>& m156) {
                u64 v_c4 = m156[2];
                slog::join_probe<2,2>(icindex135, std::array<u64,2>{v_c4, v_c0}, [&](const std::array<u64,2>& m157) {
                  ++_fires;
                  slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c36}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:8", "delta:land", _fires);
  
      if (!_done)
      {
        ReadTask136* _cont = new ReadTask136(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask136(db,b), false);
  // (crule (pre (let __tconst41fh171 constee295786ce9f03797df76c26) (let __tconst8EPI88 const6b86b273ff34fce19d6b804e) (let __tconst6cbw86 constd4735e3a265e16eee03f5971)) (probe _enum (1 0) 1 __tconst41fh171 __t8YNr84) (body) (head (mkstruct ic (1 0) __t1FpX89 __tconst8EPI88) (mkstruct ic (1 0) __t8kmG87 __tconst6cbw86) (mkstruct lnot (1 0) __t3Zrq85 __t8YNr84)) smt_basic.slog:8 #f)
  class ReadTask158 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("lnot");
      std::vector<u16> ord159({1, 0});
      slog::Relation* readrel160 = db->getRelation("_enum");
      driver_index = readrel160->getIndex(ord159, true);
  
    }
    ReadTask158(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_constee295786ce9f03797df76c26;
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c2, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m161) {
        u64 v_c6 = m161[1];
        if (buckethash(v_c6) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c6}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_basic.slog:8", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask158* _cont = new ReadTask158(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask158(db,b), true);
  // (crule (pre (let __tconst1W3y66 constba2df4903a2c14e86dc3bcca) (let __tconst00QZ64 const4e07408562bedb8b60ce05c1)) (seeded) (body (join ic (1 0) 1 __tconst00QZ64 __t5QTY65) (join iv (1 0) 1 __tconst1W3y66 __t1Wob67)) (head (mkstruct llt (2 1 0) __t4aF868 __t5QTY65 __t1Wob67)) smt_basic.slog:25 #f)
  class ReadTask164 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex162;  slog::Index** ivindex163;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord165({2, 1, 0});
      slog::Relation* readrel166 = db->getRelation("llt");
      head_index[0] = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("ic");
      icindex162 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 0});
      slog::Relation* readrel170 = db->getRelation("iv");
      ivindex163 = readrel170->getIndex(ord169, false);
  
    }
    ReadTask164(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c25 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex162, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m171) {
        u64 v_c26 = m171[1];
        slog::join_probe<2,1>(ivindex163, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m172) {
          u64 v_c27 = m172[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c26, v_c27}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:25", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask164(db,b));
  // (crule (pre (let __tconst43Cs157 const683276d23a1fc1d255583994) (let __tconst7Vau158 constee295786ce9f03797df76c26)) (probe _enum (1 0) 1 __tconst43Cs157 __t1L9C131) (body (join _enum (1 0) 1 __tconst7Vau158 __t2bXS134)) (head (mkstruct limplies (1 2 0) __t9Lqo133 __t2bXS134 __t1L9C131)) smt_basic.slog:14 #f)
  class ReadTask174 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex173;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("limplies");
      std::vector<u16> ord175({1, 0});
      slog::Relation* readrel176 = db->getRelation("_enum");
      driver_index = readrel176->getIndex(ord175, true);
      std::vector<u16> ord177({1, 0});
      slog::Relation* readrel178 = db->getRelation("_enum");
      _enumindex173 = readrel178->getIndex(ord177, false);
  
    }
    ReadTask174(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_const683276d23a1fc1d255583994;
      u64 v_c38 = v_constee295786ce9f03797df76c26;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c37, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m179) {
        u64 v_c39 = m179[1];
        if (buckethash(v_c39) != bucket) return;
        slog::join_probe<2,1>(_enumindex173, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m180) {
          u64 v_c40 = m180[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c40, v_c39}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:14", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask174* _cont = new ReadTask174(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask174(db,b), true);
  // (crule (pre (let __tconst2drD80 constd4735e3a265e16eee03f5971) (let __tconst1Iia76 constef2d127de37b942baad06145)) (seeded) (body (join ic (1 0) 1 __tconst1Iia76 __t1a6n77) (join ic (1 0) 1 __tconst2drD80 __t74zv79)) (head (mkstruct ladd (1 2 0) __t6zo982 __t74zv79 __t74zv79)) smt_basic.slog:10 #f)
  class ReadTask183 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex181;  slog::Index** icindex182;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ladd");
      std::vector<u16> ord184({1, 2, 0});
      slog::Relation* readrel185 = db->getRelation("ladd");
      head_index[0] = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 0});
      slog::Relation* readrel187 = db->getRelation("ic");
      icindex181 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 0});
      slog::Relation* readrel189 = db->getRelation("ic");
      icindex182 = readrel189->getIndex(ord188, false);
  
    }
    ReadTask183(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex181, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m190) {
        u64 v_c10 = m190[1];
        slog::join_probe<2,1>(icindex182, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m191) {
          u64 v_c11 = m191[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c11, v_c11}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:10", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask183(db,b));
  // (crule (pre (let __tconst0X1L27 const4e07408562bedb8b60ce05c1) (let __tconst04Cq22 constf5ca38f748a1d6eaf726b8a4) (let __tconst0b4S20 const4a44dc15364204a80fe80e90)) (scan lle __t74uX30 __t58Cx29 __t4ZiJ24) (body (exists ic (1 0) 1 __tconst04Cq22) (exists ic (1 0) 1 __tconst0X1L27) (join ic (1 0) 1 __tconst0b4S20 __t87vP21) (join lsub (0 2 1) 2 __t4ZiJ24 __t87vP21 __t1cqm23) (join ic (0 1) 2 __t1cqm23 __tconst04Cq22) (join ic (1 0) 1 __tconst0X1L27 __t0xP526) (join lmul (0 1 2) 2 __t58Cx29 __t0xP526 dup39fG192) (eq __t0xP526 dup39fG192)) (head (mkstruct smt_check (1 0) __4Zsv161 __t74uX30)) smt_basic.slog:16 #f)
  class ReadTask199 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex192;  slog::Index** icindex193;  slog::Index** icindex194;  slog::Index** lsubindex195;  slog::Index** icindex196;  slog::Index** icindex197;  slog::Index** lmulindex198;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("lle");
      std::vector<u16> ord200({1, 0});
      slog::Relation* readrel201 = db->getRelation("ic");
      icindex192 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({1, 0});
      slog::Relation* readrel203 = db->getRelation("ic");
      icindex193 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 0});
      slog::Relation* readrel205 = db->getRelation("ic");
      icindex194 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({0, 2, 1});
      slog::Relation* readrel207 = db->getRelation("lsub");
      lsubindex195 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({0, 1});
      slog::Relation* readrel209 = db->getRelation("ic");
      icindex196 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 0});
      slog::Relation* readrel211 = db->getRelation("ic");
      icindex197 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({0, 1, 2});
      slog::Relation* readrel213 = db->getRelation("lmul");
      lmulindex198 = readrel213->getIndex(ord212, false);
  
    }
    ReadTask199(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c17 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c41 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c18 = _t[2];
        if (!slog::exists_probe<2,1>(icindex192, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(icindex193, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<2,1>(icindex194, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m214) {
          u64 v_c20 = m214[1];
          slog::join_probe<3,2>(lsubindex195, std::array<u64,3>{v_c18, v_c20, 0}, [&](const std::array<u64,3>& m215) {
            u64 v_c19 = m215[2];
            slog::join_probe<2,2>(icindex196, std::array<u64,2>{v_c19, v_c16}, [&](const std::array<u64,2>& m216) {
              slog::join_probe<2,1>(icindex197, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m217) {
                u64 v_c21 = m217[1];
                slog::join_probe<3,2>(lmulindex198, std::array<u64,3>{v_c23, v_c21, 0}, [&](const std::array<u64,3>& m218) {
                  u64 v_c42 = m218[2];
                  if (v_c21 != v_c42) return;
                  ++_fires;
                  slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c41}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:16", "delta:lle", _fires);
  
      if (!_done)
      {
        ReadTask199* _cont = new ReadTask199(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask199(db,b), false);
  // (crule (pre (let __tconst529i37 constd4735e3a265e16eee03f5971) (let __tconst9yI933 constef2d127de37b942baad06145)) (once) (body) (head (mkstruct ic (1 0) __t0K9T36 __tconst529i37) (mkstruct ic (1 0) __t6kCx34 __tconst9yI933)) smt_basic.slog:21 #f)
  class ReadTask219 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("ic");
  
    }
    ReadTask219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constd4735e3a265e16eee03f5971;
      u64 v_c29 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c30}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c29}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_basic.slog:21", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask219(db,b), true);
  // (crule (pre (let __tconst8Xej165 consta221beeaebe583607e193be7) (let __tconst9gHQ166 constab76c7d069d6f33dc950fb33) (let __tconst5ojV167 consteb8bf0d80db323992f6b634a) (let __tconst5Un8130 constd4735e3a265e16eee03f5971) (let __tconst0wSo128 const6b86b273ff34fce19d6b804e) (let __tconst6lic126 const5feceb66ffc86f38d952786c)) (probe _enum (1 0) 1 __tconst8Xej165 __t8SyK129) (body (exists _enum (1 0) 1 __tconst5ojV167) (join _enum (1 0) 1 __tconst9gHQ166 __t2I1Y127) (join _enum (1 0) 1 __tconst5ojV167 __t0OW9125)) (head (emit smt_vcode (0 1) __tconst5Un8130 __t8SyK129) (emit smt_vcode (0 1) __tconst0wSo128 __t2I1Y127) (emit smt_vcode (0 1) __tconst6lic126 __t0OW9125)) smt.slog:68 #f)
  class ReadTask223 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex220;  slog::Index** _enumindex221;  slog::Index** _enumindex222;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_vcode");
      std::vector<u16> ord224({0, 1});
      slog::Relation* readrel225 = db->getRelation("smt_vcode");
      head_index[0] = readrel225->getIndex(ord224, false);
      head_rel[1] = db->getRelation("smt_vcode");
      std::vector<u16> ord226({0, 1});
      slog::Relation* readrel227 = db->getRelation("smt_vcode");
      head_index[1] = readrel227->getIndex(ord226, false);
      head_rel[2] = db->getRelation("smt_vcode");
      std::vector<u16> ord228({0, 1});
      slog::Relation* readrel229 = db->getRelation("smt_vcode");
      head_index[2] = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("_enum");
      driver_index = readrel231->getIndex(ord230, true);
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("_enum");
      _enumindex220 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 0});
      slog::Relation* readrel235 = db->getRelation("_enum");
      _enumindex221 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 0});
      slog::Relation* readrel237 = db->getRelation("_enum");
      _enumindex222 = readrel237->getIndex(ord236, false);
  
    }
    ReadTask223(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_consta221beeaebe583607e193be7;
      u64 v_c44 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c45 = v_consteb8bf0d80db323992f6b634a;
      u64 v_c46 = v_constd4735e3a265e16eee03f5971;
      u64 v_c47 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c48 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c43, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m238) {
        u64 v_c49 = m238[1];
        if (buckethash(v_c49) != bucket) return;
        if (!slog::exists_probe<2,1>(_enumindex220, std::array<u64,2>{v_c45, 0})) return;
        slog::join_probe<2,1>(_enumindex221, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m239) {
          u64 v_c50 = m239[1];
          slog::join_probe<2,1>(_enumindex222, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m240) {
            u64 v_c51 = m240[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c46, v_c49}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c47, v_c50}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c48, v_c51}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt.slog:68", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask223* _cont = new ReadTask223(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask223(db,b), true);
  // (crule (pre (let __tconst0X1L27 const4e07408562bedb8b60ce05c1) (let __tconst04Cq22 constf5ca38f748a1d6eaf726b8a4) (let __tconst0b4S20 const4a44dc15364204a80fe80e90)) (seeded) (body (join ic (1 0) 1 __tconst0b4S20 __t87vP21) (exists ic (1 0) 1 __tconst0X1L27) (join ic (1 0) 1 __tconst04Cq22 __t1cqm23) (join ic (1 0) 1 __tconst0X1L27 __t0xP526)) (head (mkstruct lmul (1 2 0) __t58Cx29 __t0xP526 __t0xP526) (mkstruct lsub (2 1 0) __t4ZiJ24 __t87vP21 __t1cqm23)) smt_basic.slog:16 #f)
  class ReadTask245 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** icindex241;  slog::Index** icindex242;  slog::Index** icindex243;  slog::Index** icindex244;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lmul");
      std::vector<u16> ord246({1, 2, 0});
      slog::Relation* readrel247 = db->getRelation("lmul");
      head_index[0] = readrel247->getIndex(ord246, false);
      head_rel[1] = db->getRelation("lsub");
      std::vector<u16> ord248({2, 1, 0});
      slog::Relation* readrel249 = db->getRelation("lsub");
      head_index[1] = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 0});
      slog::Relation* readrel251 = db->getRelation("ic");
      icindex241 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 0});
      slog::Relation* readrel253 = db->getRelation("ic");
      icindex242 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 0});
      slog::Relation* readrel255 = db->getRelation("ic");
      icindex243 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 0});
      slog::Relation* readrel257 = db->getRelation("ic");
      icindex244 = readrel257->getIndex(ord256, false);
  
    }
    ReadTask245(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c17 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex241, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m258) {
        u64 v_c20 = m258[1];
        if (!slog::exists_probe<2,1>(icindex242, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<2,1>(icindex243, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m259) {
          u64 v_c19 = m259[1];
          slog::join_probe<2,1>(icindex244, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m260) {
            u64 v_c21 = m260[1];
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c21}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c20, v_c19}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_basic.slog:16", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask245(db,b));
  // (crule (pre (let __tconst7Vau158 constee295786ce9f03797df76c26) (let __tconst43Cs157 const683276d23a1fc1d255583994)) (seeded) (body (join _enum (1 0) 1 __tconst7Vau158 __t2bXS134) (exists limplies (1 2 0) 1 __t2bXS134) (exists lor (1 2 0) 1 __t2bXS134) (join _enum (1 0) 1 __tconst43Cs157 __t1L9C131) (join limplies (1 2 0) 2 __t2bXS134 __t1L9C131 __t9Lqo133) (join lor (1 2 0) 2 __t2bXS134 __t9Lqo133 __t1yeE135)) (head (mkstruct smt_check (1 0) __7SQc156 __t1yeE135)) smt_basic.slog:14 #f)
  class ReadTask267 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex261;  slog::Index** limpliesindex262;  slog::Index** lorindex263;  slog::Index** _enumindex264;  slog::Index** limpliesindex265;  slog::Index** lorindex266;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord268({1, 0});
      slog::Relation* readrel269 = db->getRelation("smt_check");
      head_index[0] = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 0});
      slog::Relation* readrel271 = db->getRelation("_enum");
      _enumindex261 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 2, 0});
      slog::Relation* readrel273 = db->getRelation("limplies");
      limpliesindex262 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({1, 2, 0});
      slog::Relation* readrel275 = db->getRelation("lor");
      lorindex263 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 0});
      slog::Relation* readrel277 = db->getRelation("_enum");
      _enumindex264 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({1, 2, 0});
      slog::Relation* readrel279 = db->getRelation("limplies");
      limpliesindex265 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({1, 2, 0});
      slog::Relation* readrel281 = db->getRelation("lor");
      lorindex266 = readrel281->getIndex(ord280, false);
  
    }
    ReadTask267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_constee295786ce9f03797df76c26;
      u64 v_c37 = v_const683276d23a1fc1d255583994;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex261, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m282) {
        u64 v_c40 = m282[1];
        if (!slog::exists_probe<3,1>(limpliesindex262, std::array<u64,3>{v_c40, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lorindex263, std::array<u64,3>{v_c40, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex264, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m283) {
          u64 v_c39 = m283[1];
          slog::join_probe<3,2>(limpliesindex265, std::array<u64,3>{v_c40, v_c39, 0}, [&](const std::array<u64,3>& m284) {
            u64 v_c52 = m284[2];
            slog::join_probe<3,2>(lorindex266, std::array<u64,3>{v_c40, v_c52, 0}, [&](const std::array<u64,3>& m285) {
              u64 v_c53 = m285[2];
              ++_fires;
              slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:14", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask267(db,b));
  // (crule (pre (let __tconst8EPI88 const6b86b273ff34fce19d6b804e) (let __tconst6cbw86 constd4735e3a265e16eee03f5971) (let __tconst41fh171 constee295786ce9f03797df76c26)) (seeded) (body (join _enum (1 0) 1 __tconst41fh171 __t8YNr84) (exists ic (1 0) 1 __tconst6cbw86) (exists ic (1 0) 1 __tconst8EPI88) (join lnot (1 0) 1 __t8YNr84 __t3Zrq85) (join ic (1 0) 1 __tconst6cbw86 __t8kmG87) (join ic (1 0) 1 __tconst8EPI88 __t1FpX89)) (head (mkstruct llt (2 1 0) __t996G90 __t8kmG87 __t1FpX89)) smt_basic.slog:8 #f)
  class ReadTask292 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex286;  slog::Index** icindex287;  slog::Index** icindex288;  slog::Index** lnotindex289;  slog::Index** icindex290;  slog::Index** icindex291;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord293({2, 1, 0});
      slog::Relation* readrel294 = db->getRelation("llt");
      head_index[0] = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({1, 0});
      slog::Relation* readrel296 = db->getRelation("_enum");
      _enumindex286 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 0});
      slog::Relation* readrel298 = db->getRelation("ic");
      icindex287 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({1, 0});
      slog::Relation* readrel300 = db->getRelation("ic");
      icindex288 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 0});
      slog::Relation* readrel302 = db->getRelation("lnot");
      lnotindex289 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({1, 0});
      slog::Relation* readrel304 = db->getRelation("ic");
      icindex290 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({1, 0});
      slog::Relation* readrel306 = db->getRelation("ic");
      icindex291 = readrel306->getIndex(ord305, false);
  
    }
    ReadTask292(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_constee295786ce9f03797df76c26;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex286, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m307) {
        u64 v_c6 = m307[1];
        if (!slog::exists_probe<2,1>(icindex287, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(icindex288, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(lnotindex289, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m308) {
          u64 v_c7 = m308[1];
          slog::join_probe<2,1>(icindex290, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m309) {
            u64 v_c3 = m309[1];
            slog::join_probe<2,1>(icindex291, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m310) {
              u64 v_c4 = m310[1];
              ++_fires;
              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c3, v_c4}, std::array<u16,3>{2, 1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:8", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask292(db,b));
  // (crule (pre (let __tconst7Vau158 constee295786ce9f03797df76c26) (let __tconst43Cs157 const683276d23a1fc1d255583994)) (scan lor __t1yeE135 __t2bXS134 __t9Lqo133) (body (join _enum (0 1) 2 __t2bXS134 __tconst7Vau158) (exists _enum (1 0) 1 __tconst43Cs157) (join limplies (0 1 2) 2 __t9Lqo133 __t2bXS134 __t1L9C131) (join _enum (0 1) 2 __t1L9C131 __tconst43Cs157)) (head (mkstruct smt_check (1 0) __7SQc156 __t1yeE135)) smt_basic.slog:14 #f)
  class ReadTask315 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex311;  slog::Index** _enumindex312;  slog::Index** limpliesindex313;  slog::Index** _enumindex314;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("lor");
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("_enum");
      _enumindex311 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 0});
      slog::Relation* readrel319 = db->getRelation("_enum");
      _enumindex312 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 1, 2});
      slog::Relation* readrel321 = db->getRelation("limplies");
      limpliesindex313 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({0, 1});
      slog::Relation* readrel323 = db->getRelation("_enum");
      _enumindex314 = readrel323->getIndex(ord322, false);
  
    }
    ReadTask315(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_constee295786ce9f03797df76c26;
      u64 v_c37 = v_const683276d23a1fc1d255583994;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c53 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c52 = _t[2];
        slog::join_probe<2,2>(_enumindex311, std::array<u64,2>{v_c40, v_c38}, [&](const std::array<u64,2>& m324) {
          if (!slog::exists_probe<2,1>(_enumindex312, std::array<u64,2>{v_c37, 0})) return;
          slog::join_probe<3,2>(limpliesindex313, std::array<u64,3>{v_c52, v_c40, 0}, [&](const std::array<u64,3>& m325) {
            u64 v_c39 = m325[2];
            slog::join_probe<2,2>(_enumindex314, std::array<u64,2>{v_c39, v_c37}, [&](const std::array<u64,2>& m326) {
              ++_fires;
              slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:14", "delta:lor", _fires);
  
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
  // (crule (pre (let __tconst0X1L27 const4e07408562bedb8b60ce05c1) (let __tconst04Cq22 constf5ca38f748a1d6eaf726b8a4) (let __tconst0b4S20 const4a44dc15364204a80fe80e90)) (seeded) (body (join ic (1 0) 1 __tconst0b4S20 __t87vP21) (exists lsub (2 1 0) 1 __t87vP21) (exists ic (1 0) 1 __tconst0X1L27) (join ic (1 0) 1 __tconst04Cq22 __t1cqm23) (join lsub (2 1 0) 2 __t87vP21 __t1cqm23 __t4ZiJ24) (exists lle (2 1 0) 1 __t4ZiJ24) (join ic (1 0) 1 __tconst0X1L27 __t0xP526) (join lmul (1 2 0) 1 __t0xP526 dup27ps193 __t58Cx29) (eq __t0xP526 dup27ps193) (join lle (2 1 0) 2 __t4ZiJ24 __t58Cx29 __t74uX30)) (head (mkstruct smt_check (1 0) __4Zsv161 __t74uX30)) smt_basic.slog:16 #f)
  class ReadTask336 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex327;  slog::Index** lsubindex328;  slog::Index** icindex329;  slog::Index** icindex330;  slog::Index** lsubindex331;  slog::Index** lleindex332;  slog::Index** icindex333;  slog::Index** lmulindex334;  slog::Index** lleindex335;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord337({1, 0});
      slog::Relation* readrel338 = db->getRelation("smt_check");
      head_index[0] = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 0});
      slog::Relation* readrel340 = db->getRelation("ic");
      icindex327 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({2, 1, 0});
      slog::Relation* readrel342 = db->getRelation("lsub");
      lsubindex328 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 0});
      slog::Relation* readrel344 = db->getRelation("ic");
      icindex329 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 0});
      slog::Relation* readrel346 = db->getRelation("ic");
      icindex330 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({2, 1, 0});
      slog::Relation* readrel348 = db->getRelation("lsub");
      lsubindex331 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({2, 1, 0});
      slog::Relation* readrel350 = db->getRelation("lle");
      lleindex332 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 0});
      slog::Relation* readrel352 = db->getRelation("ic");
      icindex333 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 0});
      slog::Relation* readrel354 = db->getRelation("lmul");
      lmulindex334 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({2, 1, 0});
      slog::Relation* readrel356 = db->getRelation("lle");
      lleindex335 = readrel356->getIndex(ord355, false);
  
    }
    ReadTask336(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c17 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex327, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m357) {
        u64 v_c20 = m357[1];
        if (!slog::exists_probe<3,1>(lsubindex328, std::array<u64,3>{v_c20, 0, 0})) return;
        if (!slog::exists_probe<2,1>(icindex329, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<2,1>(icindex330, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m358) {
          u64 v_c19 = m358[1];
          slog::join_probe<3,2>(lsubindex331, std::array<u64,3>{v_c20, v_c19, 0}, [&](const std::array<u64,3>& m359) {
            u64 v_c18 = m359[2];
            if (!slog::exists_probe<3,1>(lleindex332, std::array<u64,3>{v_c18, 0, 0})) return;
            slog::join_probe<2,1>(icindex333, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m360) {
              u64 v_c21 = m360[1];
              slog::join_probe<3,1>(lmulindex334, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m361) {
                u64 v_c54 = m361[1]; u64 v_c23 = m361[2];
                if (v_c21 != v_c54) return;
                slog::join_probe<3,2>(lleindex335, std::array<u64,3>{v_c18, v_c23, 0}, [&](const std::array<u64,3>& m362) {
                  u64 v_c41 = m362[2];
                  ++_fires;
                  slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c41}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:16", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask336(db,b));
  // (crule (pre (let __tconst8EPI88 const6b86b273ff34fce19d6b804e) (let __tconst6cbw86 constd4735e3a265e16eee03f5971) (let __tconst41fh171 constee295786ce9f03797df76c26)) (scan lnot __t3Zrq85 __t8YNr84) (body (join _enum (0 1) 2 __t8YNr84 __tconst41fh171) (exists ic (1 0) 1 __tconst8EPI88) (join ic (1 0) 1 __tconst6cbw86 __t8kmG87) (join ic (1 0) 1 __tconst8EPI88 __t1FpX89)) (head (mkstruct llt (2 1 0) __t996G90 __t8kmG87 __t1FpX89)) smt_basic.slog:8 #f)
  class ReadTask367 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex363;  slog::Index** icindex364;  slog::Index** icindex365;  slog::Index** icindex366;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      outer_rel = db->getRelation("lnot");
      std::vector<u16> ord368({0, 1});
      slog::Relation* readrel369 = db->getRelation("_enum");
      _enumindex363 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({1, 0});
      slog::Relation* readrel371 = db->getRelation("ic");
      icindex364 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 0});
      slog::Relation* readrel373 = db->getRelation("ic");
      icindex365 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 0});
      slog::Relation* readrel375 = db->getRelation("ic");
      icindex366 = readrel375->getIndex(ord374, false);
  
    }
    ReadTask367(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_constee295786ce9f03797df76c26;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c7 = _t[0];
        u64 v_c6 = _t[1];
        slog::join_probe<2,2>(_enumindex363, std::array<u64,2>{v_c6, v_c2}, [&](const std::array<u64,2>& m376) {
          if (!slog::exists_probe<2,1>(icindex364, std::array<u64,2>{v_c0, 0})) return;
          slog::join_probe<2,1>(icindex365, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m377) {
            u64 v_c3 = m377[1];
            slog::join_probe<2,1>(icindex366, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m378) {
              u64 v_c4 = m378[1];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c4}, std::array<u16,3>{2, 1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:8", "delta:lnot", _fires);
  
      if (!_done)
      {
        ReadTask367* _cont = new ReadTask367(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask367(db,b), false);
  // (crule (pre (let __tconst8EPI88 const6b86b273ff34fce19d6b804e) (let __tconst6cbw86 constd4735e3a265e16eee03f5971) (let __tconst41fh171 constee295786ce9f03797df76c26)) (scan llt __t996G90 __t1FpX89 __t8kmG87) (body (join ic (0 1) 2 __t8kmG87 __tconst6cbw86) (join ic (0 1) 2 __t1FpX89 __tconst8EPI88) (join _enum (1 0) 1 __tconst41fh171 __t8YNr84) (join lnot (1 0) 1 __t8YNr84 __t3Zrq85)) (head (mkstruct land (1 2 0) __t3IQi91 __t996G90 __t3Zrq85)) smt_basic.slog:8 #f)
  class ReadTask383 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex379;  slog::Index** icindex380;  slog::Index** _enumindex381;  slog::Index** lnotindex382;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("land");
      outer_rel = db->getRelation("llt");
      std::vector<u16> ord384({0, 1});
      slog::Relation* readrel385 = db->getRelation("ic");
      icindex379 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({0, 1});
      slog::Relation* readrel387 = db->getRelation("ic");
      icindex380 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 0});
      slog::Relation* readrel389 = db->getRelation("_enum");
      _enumindex381 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 0});
      slog::Relation* readrel391 = db->getRelation("lnot");
      lnotindex382 = readrel391->getIndex(ord390, false);
  
    }
    ReadTask383(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_constee295786ce9f03797df76c26;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        slog::join_probe<2,2>(icindex379, std::array<u64,2>{v_c3, v_c1}, [&](const std::array<u64,2>& m392) {
          slog::join_probe<2,2>(icindex380, std::array<u64,2>{v_c4, v_c0}, [&](const std::array<u64,2>& m393) {
            slog::join_probe<2,1>(_enumindex381, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m394) {
              u64 v_c6 = m394[1];
              slog::join_probe<2,1>(lnotindex382, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m395) {
                u64 v_c7 = m395[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c7}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:8", "delta:llt", _fires);
  
      if (!_done)
      {
        ReadTask383* _cont = new ReadTask383(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask383(db,b), false);
  // (crule (pre (let __tconst0X1L27 const4e07408562bedb8b60ce05c1) (let __tconst04Cq22 constf5ca38f748a1d6eaf726b8a4) (let __tconst0b4S20 const4a44dc15364204a80fe80e90)) (once) (body) (head (mkstruct ic (1 0) __t0xP526 __tconst0X1L27) (mkstruct ic (1 0) __t1cqm23 __tconst04Cq22) (mkstruct ic (1 0) __t87vP21 __tconst0b4S20)) smt_basic.slog:16 #f)
  class ReadTask396 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
  
    }
    ReadTask396(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c17 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c15}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_basic.slog:16", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask396(db,b), true);
  // (crule (pre (let __tconst9yI933 constef2d127de37b942baad06145) (let __tconst529i37 constd4735e3a265e16eee03f5971)) (scan leq __t6kVM40 __t0WxP39 __t6kCx34) (body (join ic (0 1) 2 __t6kCx34 __tconst9yI933) (join ic (1 0) 1 __tconst529i37 __t0K9T36) (join ladd (0 1 2) 2 __t0WxP39 __t0K9T36 dup3gAZ196) (eq __t0K9T36 dup3gAZ196)) (head (mkstruct smt_check (1 0) __0VVz160 __t6kVM40)) smt_basic.slog:21 #f)
  class ReadTask400 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex397;  slog::Index** icindex398;  slog::Index** laddindex399;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("leq");
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("ic");
      icindex397 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 0});
      slog::Relation* readrel404 = db->getRelation("ic");
      icindex398 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({0, 1, 2});
      slog::Relation* readrel406 = db->getRelation("ladd");
      laddindex399 = readrel406->getIndex(ord405, false);
  
    }
    ReadTask400(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_constef2d127de37b942baad06145;
      u64 v_c30 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c35 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c31 = _t[2];
        slog::join_probe<2,2>(icindex397, std::array<u64,2>{v_c31, v_c29}, [&](const std::array<u64,2>& m407) {
          slog::join_probe<2,1>(icindex398, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m408) {
            u64 v_c32 = m408[1];
            slog::join_probe<3,2>(laddindex399, std::array<u64,3>{v_c34, v_c32, 0}, [&](const std::array<u64,3>& m409) {
              u64 v_c55 = m409[2];
              if (v_c32 != v_c55) return;
              ++_fires;
              slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c35}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:21", "delta:leq", _fires);
  
      if (!_done)
      {
        ReadTask400* _cont = new ReadTask400(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask400(db,b), false);
  // (crule (pre (let __tconst1Iia76 constef2d127de37b942baad06145) (let __tconst2drD80 constd4735e3a265e16eee03f5971)) (scan leq __t75M183 __t6zo982 __t1a6n77) (body (join ic (0 1) 2 __t1a6n77 __tconst1Iia76) (join ic (1 0) 1 __tconst2drD80 __t74zv79) (join ladd (0 1 2) 2 __t6zo982 __t74zv79 dup7RBI188) (eq __t74zv79 dup7RBI188)) (head (mkstruct smt_check (1 0) __9k7v155 __t75M183)) smt_basic.slog:10 #f)
  class ReadTask413 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex410;  slog::Index** icindex411;  slog::Index** laddindex412;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("leq");
      std::vector<u16> ord414({0, 1});
      slog::Relation* readrel415 = db->getRelation("ic");
      icindex410 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 0});
      slog::Relation* readrel417 = db->getRelation("ic");
      icindex411 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({0, 1, 2});
      slog::Relation* readrel419 = db->getRelation("ladd");
      laddindex412 = readrel419->getIndex(ord418, false);
  
    }
    ReadTask413(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c8 = v_constef2d127de37b942baad06145;
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c14 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c10 = _t[2];
        slog::join_probe<2,2>(icindex410, std::array<u64,2>{v_c10, v_c8}, [&](const std::array<u64,2>& m420) {
          slog::join_probe<2,1>(icindex411, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m421) {
            u64 v_c11 = m421[1];
            slog::join_probe<3,2>(laddindex412, std::array<u64,3>{v_c13, v_c11, 0}, [&](const std::array<u64,3>& m422) {
              u64 v_c56 = m422[2];
              if (v_c11 != v_c56) return;
              ++_fires;
              slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:10", "delta:leq", _fires);
  
      if (!_done)
      {
        ReadTask413* _cont = new ReadTask413(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask413(db,b), false);
  // (crule (pre (let __tconst1W3y66 constba2df4903a2c14e86dc3bcca) (let __tconst00QZ64 const4e07408562bedb8b60ce05c1)) (once) (body) (head (mkstruct iv (1 0) __t1Wob67 __tconst1W3y66) (mkstruct ic (1 0) __t5QTY65 __tconst00QZ64)) smt_basic.slog:25 #f)
  class ReadTask423 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("iv");
      head_rel[1] = db->getRelation("ic");
  
    }
    ReadTask423(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c25 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c25}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_basic.slog:25", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask423(db,b), true);
  // (crule (pre (let __tconst1W3y66 constba2df4903a2c14e86dc3bcca) (let __tconst00QZ64 const4e07408562bedb8b60ce05c1)) (scan llt __t4aF868 __t1Wob67 __t5QTY65) (body (join ic (0 1) 2 __t5QTY65 __tconst00QZ64) (join iv (0 1) 2 __t1Wob67 __tconst1W3y66)) (head (mkstruct smt_check (1 0) __2YwB162 __t4aF868)) smt_basic.slog:25 #f)
  class ReadTask426 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex424;  slog::Index** ivindex425;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("llt");
      std::vector<u16> ord427({0, 1});
      slog::Relation* readrel428 = db->getRelation("ic");
      icindex424 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({0, 1});
      slog::Relation* readrel430 = db->getRelation("iv");
      ivindex425 = readrel430->getIndex(ord429, false);
  
    }
    ReadTask426(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c25 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c57 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c26 = _t[2];
        slog::join_probe<2,2>(icindex424, std::array<u64,2>{v_c26, v_c25}, [&](const std::array<u64,2>& m431) {
          slog::join_probe<2,2>(ivindex425, std::array<u64,2>{v_c27, v_c24}, [&](const std::array<u64,2>& m432) {
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:25", "delta:llt", _fires);
  
      if (!_done)
      {
        ReadTask426* _cont = new ReadTask426(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask426(db,b), false);
  // (crule (pre (let __tconst0zRk108 constba2df4903a2c14e86dc3bcca) (let __tconst0t5V106 const4e07408562bedb8b60ce05c1)) (seeded) (body (join ic (1 0) 1 __tconst0t5V106 __t2oHn107) (exists llt (2 1 0) 1 __t2oHn107) (join iv (1 0) 1 __tconst0zRk108 __t0r3v109) (join llt (2 1 0) 2 __t2oHn107 __t0r3v109 __t4Ac9110)) (head (mkstruct smt_check (1 0) __5AfT173 __t4Ac9110)) smt_basic.slog:12 #f)
  class ReadTask437 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex433;  slog::Index** lltindex434;  slog::Index** ivindex435;  slog::Index** lltindex436;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord438({1, 0});
      slog::Relation* readrel439 = db->getRelation("smt_check");
      head_index[0] = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({1, 0});
      slog::Relation* readrel441 = db->getRelation("ic");
      icindex433 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({2, 1, 0});
      slog::Relation* readrel443 = db->getRelation("llt");
      lltindex434 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({1, 0});
      slog::Relation* readrel445 = db->getRelation("iv");
      ivindex435 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({2, 1, 0});
      slog::Relation* readrel447 = db->getRelation("llt");
      lltindex436 = readrel447->getIndex(ord446, false);
  
    }
    ReadTask437(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c59 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex433, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m448) {
        u64 v_c60 = m448[1];
        if (!slog::exists_probe<3,1>(lltindex434, std::array<u64,3>{v_c60, 0, 0})) return;
        slog::join_probe<2,1>(ivindex435, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m449) {
          u64 v_c61 = m449[1];
          slog::join_probe<3,2>(lltindex436, std::array<u64,3>{v_c60, v_c61, 0}, [&](const std::array<u64,3>& m450) {
            u64 v_c62 = m450[2];
            ++_fires;
            slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c62}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:12", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask437(db,b));
  // (crule (pre (let __tconst529i37 constd4735e3a265e16eee03f5971) (let __tconst9yI933 constef2d127de37b942baad06145)) (seeded) (body (join ic (1 0) 1 __tconst9yI933 __t6kCx34) (join ic (1 0) 1 __tconst529i37 __t0K9T36)) (head (mkstruct ladd (1 2 0) __t0WxP39 __t0K9T36 __t0K9T36)) smt_basic.slog:21 #f)
  class ReadTask453 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex451;  slog::Index** icindex452;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ladd");
      std::vector<u16> ord454({1, 2, 0});
      slog::Relation* readrel455 = db->getRelation("ladd");
      head_index[0] = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 0});
      slog::Relation* readrel457 = db->getRelation("ic");
      icindex451 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 0});
      slog::Relation* readrel459 = db->getRelation("ic");
      icindex452 = readrel459->getIndex(ord458, false);
  
    }
    ReadTask453(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constd4735e3a265e16eee03f5971;
      u64 v_c29 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex451, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m460) {
        u64 v_c31 = m460[1];
        slog::join_probe<2,1>(icindex452, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m461) {
          u64 v_c32 = m461[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c32, v_c32}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:21", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask453(db,b));
  // (crule (pre (let __tconst43Cs157 const683276d23a1fc1d255583994) (let __tconst7Vau158 constee295786ce9f03797df76c26)) (seeded) (body (join _enum (1 0) 1 __tconst43Cs157 __t1L9C131) (exists limplies (2 0 1) 1 __t1L9C131) (join _enum (1 0) 1 __tconst7Vau158 __t2bXS134) (join limplies (1 2 0) 2 __t2bXS134 __t1L9C131 __t9Lqo133)) (head (mkstruct lor (1 2 0) __t1yeE135 __t2bXS134 __t9Lqo133)) smt_basic.slog:14 #f)
  class ReadTask466 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex462;  slog::Index** limpliesindex463;  slog::Index** _enumindex464;  slog::Index** limpliesindex465;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lor");
      std::vector<u16> ord467({1, 2, 0});
      slog::Relation* readrel468 = db->getRelation("lor");
      head_index[0] = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({1, 0});
      slog::Relation* readrel470 = db->getRelation("_enum");
      _enumindex462 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({2, 0, 1});
      slog::Relation* readrel472 = db->getRelation("limplies");
      limpliesindex463 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 0});
      slog::Relation* readrel474 = db->getRelation("_enum");
      _enumindex464 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({1, 2, 0});
      slog::Relation* readrel476 = db->getRelation("limplies");
      limpliesindex465 = readrel476->getIndex(ord475, false);
  
    }
    ReadTask466(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_const683276d23a1fc1d255583994;
      u64 v_c38 = v_constee295786ce9f03797df76c26;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex462, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m477) {
        u64 v_c39 = m477[1];
        if (!slog::exists_probe<3,1>(limpliesindex463, std::array<u64,3>{v_c39, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex464, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m478) {
          u64 v_c40 = m478[1];
          slog::join_probe<3,2>(limpliesindex465, std::array<u64,3>{v_c40, v_c39, 0}, [&](const std::array<u64,3>& m479) {
            u64 v_c52 = m479[2];
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c40, v_c52}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:14", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask466(db,b));
  // (crule (pre (let __tconst529i37 constd4735e3a265e16eee03f5971) (let __tconst9yI933 constef2d127de37b942baad06145)) (seeded) (body (join ic (1 0) 1 __tconst9yI933 __t6kCx34) (join ic (1 0) 1 __tconst529i37 __t0K9T36) (join ladd (1 2 0) 1 __t0K9T36 dup48pf195 __t0WxP39) (eq __t0K9T36 dup48pf195)) (head (mkstruct leq (2 1 0) __t6kVM40 __t6kCx34 __t0WxP39)) smt_basic.slog:21 #f)
  class ReadTask483 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex480;  slog::Index** icindex481;  slog::Index** laddindex482;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("leq");
      std::vector<u16> ord484({2, 1, 0});
      slog::Relation* readrel485 = db->getRelation("leq");
      head_index[0] = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({1, 0});
      slog::Relation* readrel487 = db->getRelation("ic");
      icindex480 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({1, 0});
      slog::Relation* readrel489 = db->getRelation("ic");
      icindex481 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 2, 0});
      slog::Relation* readrel491 = db->getRelation("ladd");
      laddindex482 = readrel491->getIndex(ord490, false);
  
    }
    ReadTask483(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constd4735e3a265e16eee03f5971;
      u64 v_c29 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex480, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m492) {
        u64 v_c31 = m492[1];
        slog::join_probe<2,1>(icindex481, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m493) {
          u64 v_c32 = m493[1];
          slog::join_probe<3,1>(laddindex482, std::array<u64,3>{v_c32, 0, 0}, [&](const std::array<u64,3>& m494) {
            u64 v_c63 = m494[1]; u64 v_c34 = m494[2];
            if (v_c32 != v_c63) return;
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c31, v_c34}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:21", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask483(db,b));
  // (crule (pre (let __tconst0zRk108 constba2df4903a2c14e86dc3bcca) (let __tconst0t5V106 const4e07408562bedb8b60ce05c1)) (seeded) (body (join ic (1 0) 1 __tconst0t5V106 __t2oHn107) (join iv (1 0) 1 __tconst0zRk108 __t0r3v109)) (head (mkstruct llt (2 1 0) __t4Ac9110 __t2oHn107 __t0r3v109)) smt_basic.slog:12 #f)
  class ReadTask497 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex495;  slog::Index** ivindex496;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord498({2, 1, 0});
      slog::Relation* readrel499 = db->getRelation("llt");
      head_index[0] = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({1, 0});
      slog::Relation* readrel501 = db->getRelation("ic");
      icindex495 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({1, 0});
      slog::Relation* readrel503 = db->getRelation("iv");
      ivindex496 = readrel503->getIndex(ord502, false);
  
    }
    ReadTask497(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c59 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex495, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m504) {
        u64 v_c60 = m504[1];
        slog::join_probe<2,1>(ivindex496, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m505) {
          u64 v_c61 = m505[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c60, v_c61}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:12", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask497(db,b));
  // (crule (pre (let __tconst43Cs157 const683276d23a1fc1d255583994) (let __tconst7Vau158 constee295786ce9f03797df76c26)) (scan limplies __t9Lqo133 __t2bXS134 __t1L9C131) (body (join _enum (0 1) 2 __t1L9C131 __tconst43Cs157) (join _enum (0 1) 2 __t2bXS134 __tconst7Vau158)) (head (mkstruct lor (1 2 0) __t1yeE135 __t2bXS134 __t9Lqo133)) smt_basic.slog:14 #f)
  class ReadTask508 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex506;  slog::Index** _enumindex507;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lor");
      outer_rel = db->getRelation("limplies");
      std::vector<u16> ord509({0, 1});
      slog::Relation* readrel510 = db->getRelation("_enum");
      _enumindex506 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({0, 1});
      slog::Relation* readrel512 = db->getRelation("_enum");
      _enumindex507 = readrel512->getIndex(ord511, false);
  
    }
    ReadTask508(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_const683276d23a1fc1d255583994;
      u64 v_c38 = v_constee295786ce9f03797df76c26;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c52 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c39 = _t[2];
        slog::join_probe<2,2>(_enumindex506, std::array<u64,2>{v_c39, v_c37}, [&](const std::array<u64,2>& m513) {
          slog::join_probe<2,2>(_enumindex507, std::array<u64,2>{v_c40, v_c38}, [&](const std::array<u64,2>& m514) {
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c40, v_c52}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:14", "delta:limplies", _fires);
  
      if (!_done)
      {
        ReadTask508* _cont = new ReadTask508(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask508(db,b), false);
  // (crule (pre (let __tconst529i37 constd4735e3a265e16eee03f5971) (let __tconst9yI933 constef2d127de37b942baad06145)) (probe ic (1 0) 1 __tconst9yI933 __t6kCx34) (body (join ic (1 0) 1 __tconst529i37 __t0K9T36)) (head (mkstruct ladd (1 2 0) __t0WxP39 __t0K9T36 __t0K9T36)) smt_basic.slog:21 #f)
  class ReadTask516 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex515;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ladd");
      std::vector<u16> ord517({1, 0});
      slog::Relation* readrel518 = db->getRelation("ic");
      driver_index = readrel518->getIndex(ord517, true);
      std::vector<u16> ord519({1, 0});
      slog::Relation* readrel520 = db->getRelation("ic");
      icindex515 = readrel520->getIndex(ord519, false);
  
    }
    ReadTask516(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constd4735e3a265e16eee03f5971;
      u64 v_c29 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c29, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m521) {
        u64 v_c31 = m521[1];
        if (buckethash(v_c31) != bucket) return;
        slog::join_probe<2,1>(icindex515, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m522) {
          u64 v_c32 = m522[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c32, v_c32}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:21", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask516* _cont = new ReadTask516(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask516(db,b), false);
  // (crule (pre (let __tconst1W3y66 constba2df4903a2c14e86dc3bcca) (let __tconst00QZ64 const4e07408562bedb8b60ce05c1)) (seeded) (body (join ic (1 0) 1 __tconst00QZ64 __t5QTY65) (exists llt (2 1 0) 1 __t5QTY65) (join iv (1 0) 1 __tconst1W3y66 __t1Wob67) (join llt (2 1 0) 2 __t5QTY65 __t1Wob67 __t4aF868)) (head (mkstruct smt_check (1 0) __2YwB162 __t4aF868)) smt_basic.slog:25 #f)
  class ReadTask527 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex523;  slog::Index** lltindex524;  slog::Index** ivindex525;  slog::Index** lltindex526;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord528({1, 0});
      slog::Relation* readrel529 = db->getRelation("smt_check");
      head_index[0] = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 0});
      slog::Relation* readrel531 = db->getRelation("ic");
      icindex523 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({2, 1, 0});
      slog::Relation* readrel533 = db->getRelation("llt");
      lltindex524 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 0});
      slog::Relation* readrel535 = db->getRelation("iv");
      ivindex525 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({2, 1, 0});
      slog::Relation* readrel537 = db->getRelation("llt");
      lltindex526 = readrel537->getIndex(ord536, false);
  
    }
    ReadTask527(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c25 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex523, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m538) {
        u64 v_c26 = m538[1];
        if (!slog::exists_probe<3,1>(lltindex524, std::array<u64,3>{v_c26, 0, 0})) return;
        slog::join_probe<2,1>(ivindex525, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m539) {
          u64 v_c27 = m539[1];
          slog::join_probe<3,2>(lltindex526, std::array<u64,3>{v_c26, v_c27, 0}, [&](const std::array<u64,3>& m540) {
            u64 v_c57 = m540[2];
            ++_fires;
            slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:25", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask527(db,b));
  // (crule (pre (let __tconst2drD80 constd4735e3a265e16eee03f5971) (let __tconst1Iia76 constef2d127de37b942baad06145)) (once) (body) (head (mkstruct ic (1 0) __t74zv79 __tconst2drD80) (mkstruct ic (1 0) __t1a6n77 __tconst1Iia76)) smt_basic.slog:10 #f)
  class ReadTask541 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("ic");
  
    }
    ReadTask541(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_basic.slog:10", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask541(db,b), true);
  // (crule (pre (let __tconst0zRk108 constba2df4903a2c14e86dc3bcca) (let __tconst0t5V106 const4e07408562bedb8b60ce05c1)) (probe ic (1 0) 1 __tconst0t5V106 __t2oHn107) (body (join iv (1 0) 1 __tconst0zRk108 __t0r3v109)) (head (mkstruct llt (2 1 0) __t4Ac9110 __t2oHn107 __t0r3v109)) smt_basic.slog:12 #f)
  class ReadTask543 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ivindex542;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord544({1, 0});
      slog::Relation* readrel545 = db->getRelation("ic");
      driver_index = readrel545->getIndex(ord544, true);
      std::vector<u16> ord546({1, 0});
      slog::Relation* readrel547 = db->getRelation("iv");
      ivindex542 = readrel547->getIndex(ord546, false);
  
    }
    ReadTask543(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c59 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c59, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m548) {
        u64 v_c60 = m548[1];
        if (buckethash(v_c60) != bucket) return;
        slog::join_probe<2,1>(ivindex542, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m549) {
          u64 v_c61 = m549[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c60, v_c61}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:12", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask543* _cont = new ReadTask543(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask543(db,b), false);
  // (crule (pre (let __tconst0X1L27 const4e07408562bedb8b60ce05c1) (let __tconst04Cq22 constf5ca38f748a1d6eaf726b8a4) (let __tconst0b4S20 const4a44dc15364204a80fe80e90)) (seeded) (body (join ic (1 0) 1 __tconst0b4S20 __t87vP21) (exists lsub (2 1 0) 1 __t87vP21) (exists ic (1 0) 1 __tconst0X1L27) (join ic (1 0) 1 __tconst04Cq22 __t1cqm23) (join lsub (2 1 0) 2 __t87vP21 __t1cqm23 __t4ZiJ24) (join ic (1 0) 1 __tconst0X1L27 __t0xP526) (join lmul (1 2 0) 1 __t0xP526 dup4pgC191 __t58Cx29) (eq __t0xP526 dup4pgC191)) (head (mkstruct lle (2 1 0) __t74uX30 __t4ZiJ24 __t58Cx29)) smt_basic.slog:16 #f)
  class ReadTask557 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex550;  slog::Index** lsubindex551;  slog::Index** icindex552;  slog::Index** icindex553;  slog::Index** lsubindex554;  slog::Index** icindex555;  slog::Index** lmulindex556;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lle");
      std::vector<u16> ord558({2, 1, 0});
      slog::Relation* readrel559 = db->getRelation("lle");
      head_index[0] = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 0});
      slog::Relation* readrel561 = db->getRelation("ic");
      icindex550 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({2, 1, 0});
      slog::Relation* readrel563 = db->getRelation("lsub");
      lsubindex551 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({1, 0});
      slog::Relation* readrel565 = db->getRelation("ic");
      icindex552 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({1, 0});
      slog::Relation* readrel567 = db->getRelation("ic");
      icindex553 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({2, 1, 0});
      slog::Relation* readrel569 = db->getRelation("lsub");
      lsubindex554 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 0});
      slog::Relation* readrel571 = db->getRelation("ic");
      icindex555 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 2, 0});
      slog::Relation* readrel573 = db->getRelation("lmul");
      lmulindex556 = readrel573->getIndex(ord572, false);
  
    }
    ReadTask557(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c16 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c17 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex550, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m574) {
        u64 v_c20 = m574[1];
        if (!slog::exists_probe<3,1>(lsubindex551, std::array<u64,3>{v_c20, 0, 0})) return;
        if (!slog::exists_probe<2,1>(icindex552, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<2,1>(icindex553, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m575) {
          u64 v_c19 = m575[1];
          slog::join_probe<3,2>(lsubindex554, std::array<u64,3>{v_c20, v_c19, 0}, [&](const std::array<u64,3>& m576) {
            u64 v_c18 = m576[2];
            slog::join_probe<2,1>(icindex555, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m577) {
              u64 v_c21 = m577[1];
              slog::join_probe<3,1>(lmulindex556, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m578) {
                u64 v_c64 = m578[1]; u64 v_c23 = m578[2];
                if (v_c21 != v_c64) return;
                ++_fires;
                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c18, v_c23}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:16", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask557(db,b));
  // (crule (pre (let __tconst0zRk108 constba2df4903a2c14e86dc3bcca) (let __tconst0t5V106 const4e07408562bedb8b60ce05c1)) (scan llt __t4Ac9110 __t0r3v109 __t2oHn107) (body (join ic (0 1) 2 __t2oHn107 __tconst0t5V106) (join iv (0 1) 2 __t0r3v109 __tconst0zRk108)) (head (mkstruct smt_check (1 0) __5AfT173 __t4Ac9110)) smt_basic.slog:12 #f)
  class ReadTask581 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex579;  slog::Index** ivindex580;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("llt");
      std::vector<u16> ord582({0, 1});
      slog::Relation* readrel583 = db->getRelation("ic");
      icindex579 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({0, 1});
      slog::Relation* readrel585 = db->getRelation("iv");
      ivindex580 = readrel585->getIndex(ord584, false);
  
    }
    ReadTask581(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c59 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c62 = _t[0];
        u64 v_c61 = _t[1];
        u64 v_c60 = _t[2];
        slog::join_probe<2,2>(icindex579, std::array<u64,2>{v_c60, v_c59}, [&](const std::array<u64,2>& m586) {
          slog::join_probe<2,2>(ivindex580, std::array<u64,2>{v_c61, v_c58}, [&](const std::array<u64,2>& m587) {
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c62}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:12", "delta:llt", _fires);
  
      if (!_done)
      {
        ReadTask581* _cont = new ReadTask581(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask581(db,b), false);
  // (crule (pre (let __tconst8EPI88 const6b86b273ff34fce19d6b804e) (let __tconst6cbw86 constd4735e3a265e16eee03f5971) (let __tconst41fh171 constee295786ce9f03797df76c26)) (seeded) (body (join ic (1 0) 1 __tconst6cbw86 __t8kmG87) (exists llt (2 1 0) 1 __t8kmG87) (exists _enum (1 0) 1 __tconst41fh171) (join ic (1 0) 1 __tconst8EPI88 __t1FpX89) (join llt (2 1 0) 2 __t8kmG87 __t1FpX89 __t996G90) (exists land (1 2 0) 1 __t996G90) (join _enum (1 0) 1 __tconst41fh171 __t8YNr84) (join lnot (1 0) 1 __t8YNr84 __t3Zrq85) (join land (1 2 0) 2 __t996G90 __t3Zrq85 __t3IQi91)) (head (mkstruct smt_check (1 0) __2kIP170 __t3IQi91)) smt_basic.slog:8 #f)
  class ReadTask597 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex588;  slog::Index** lltindex589;  slog::Index** _enumindex590;  slog::Index** icindex591;  slog::Index** lltindex592;  slog::Index** landindex593;  slog::Index** _enumindex594;  slog::Index** lnotindex595;  slog::Index** landindex596;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord598({1, 0});
      slog::Relation* readrel599 = db->getRelation("smt_check");
      head_index[0] = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({1, 0});
      slog::Relation* readrel601 = db->getRelation("ic");
      icindex588 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({2, 1, 0});
      slog::Relation* readrel603 = db->getRelation("llt");
      lltindex589 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({1, 0});
      slog::Relation* readrel605 = db->getRelation("_enum");
      _enumindex590 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({1, 0});
      slog::Relation* readrel607 = db->getRelation("ic");
      icindex591 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({2, 1, 0});
      slog::Relation* readrel609 = db->getRelation("llt");
      lltindex592 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 2, 0});
      slog::Relation* readrel611 = db->getRelation("land");
      landindex593 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({1, 0});
      slog::Relation* readrel613 = db->getRelation("_enum");
      _enumindex594 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({1, 0});
      slog::Relation* readrel615 = db->getRelation("lnot");
      lnotindex595 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 2, 0});
      slog::Relation* readrel617 = db->getRelation("land");
      landindex596 = readrel617->getIndex(ord616, false);
  
    }
    ReadTask597(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_constee295786ce9f03797df76c26;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex588, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m618) {
        u64 v_c3 = m618[1];
        if (!slog::exists_probe<3,1>(lltindex589, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex590, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<2,1>(icindex591, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m619) {
          u64 v_c4 = m619[1];
          slog::join_probe<3,2>(lltindex592, std::array<u64,3>{v_c3, v_c4, 0}, [&](const std::array<u64,3>& m620) {
            u64 v_c5 = m620[2];
            if (!slog::exists_probe<3,1>(landindex593, std::array<u64,3>{v_c5, 0, 0})) return;
            slog::join_probe<2,1>(_enumindex594, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m621) {
              u64 v_c6 = m621[1];
              slog::join_probe<2,1>(lnotindex595, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m622) {
                u64 v_c7 = m622[1];
                slog::join_probe<3,2>(landindex596, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m623) {
                  u64 v_c36 = m623[2];
                  ++_fires;
                  slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c36}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:8", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask597(db,b));
  // (crule (pre (let __tconst2drD80 constd4735e3a265e16eee03f5971) (let __tconst1Iia76 constef2d127de37b942baad06145)) (probe ic (1 0) 1 __tconst1Iia76 __t1a6n77) (body (join ic (1 0) 1 __tconst2drD80 __t74zv79)) (head (mkstruct ladd (1 2 0) __t6zo982 __t74zv79 __t74zv79)) smt_basic.slog:10 #f)
  class ReadTask625 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex624;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ladd");
      std::vector<u16> ord626({1, 0});
      slog::Relation* readrel627 = db->getRelation("ic");
      driver_index = readrel627->getIndex(ord626, true);
      std::vector<u16> ord628({1, 0});
      slog::Relation* readrel629 = db->getRelation("ic");
      icindex624 = readrel629->getIndex(ord628, false);
  
    }
    ReadTask625(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c8, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m630) {
        u64 v_c10 = m630[1];
        if (buckethash(v_c10) != bucket) return;
        slog::join_probe<2,1>(icindex624, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m631) {
          u64 v_c11 = m631[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c11}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:10", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask625* _cont = new ReadTask625(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask625(db,b), false);
  // (crule (pre (let __tconst529i37 constd4735e3a265e16eee03f5971) (let __tconst9yI933 constef2d127de37b942baad06145)) (scan ladd __t0WxP39 __t0K9T36 dup5Y9d194) (body (eq __t0K9T36 dup5Y9d194) (join ic (0 1) 2 __t0K9T36 __tconst529i37) (join ic (1 0) 1 __tconst9yI933 __t6kCx34)) (head (mkstruct leq (2 1 0) __t6kVM40 __t6kCx34 __t0WxP39)) smt_basic.slog:21 #f)
  class ReadTask634 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex632;  slog::Index** icindex633;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("leq");
      outer_rel = db->getRelation("ladd");
      std::vector<u16> ord635({0, 1});
      slog::Relation* readrel636 = db->getRelation("ic");
      icindex632 = readrel636->getIndex(ord635, false);
      std::vector<u16> ord637({1, 0});
      slog::Relation* readrel638 = db->getRelation("ic");
      icindex633 = readrel638->getIndex(ord637, false);
  
    }
    ReadTask634(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constd4735e3a265e16eee03f5971;
      u64 v_c29 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c34 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c65 = _t[2];
        if (v_c32 != v_c65) return;
        slog::join_probe<2,2>(icindex632, std::array<u64,2>{v_c32, v_c30}, [&](const std::array<u64,2>& m639) {
          slog::join_probe<2,1>(icindex633, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m640) {
            u64 v_c31 = m640[1];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c31, v_c34}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:21", "delta:ladd", _fires);
  
      if (!_done)
      {
        ReadTask634* _cont = new ReadTask634(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask634(db,b), false);
  // (crule (pre (let __tconst2drD80 constd4735e3a265e16eee03f5971) (let __tconst1Iia76 constef2d127de37b942baad06145)) (scan ladd __t6zo982 __t74zv79 dup3Hf9186) (body (eq __t74zv79 dup3Hf9186) (join ic (0 1) 2 __t74zv79 __tconst2drD80) (join ic (1 0) 1 __tconst1Iia76 __t1a6n77)) (head (mkstruct leq (2 1 0) __t75M183 __t1a6n77 __t6zo982)) smt_basic.slog:10 #f)
  class ReadTask643 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex641;  slog::Index** icindex642;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("leq");
      outer_rel = db->getRelation("ladd");
      std::vector<u16> ord644({0, 1});
      slog::Relation* readrel645 = db->getRelation("ic");
      icindex641 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 0});
      slog::Relation* readrel647 = db->getRelation("ic");
      icindex642 = readrel647->getIndex(ord646, false);
  
    }
    ReadTask643(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c13 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c66 = _t[2];
        if (v_c11 != v_c66) return;
        slog::join_probe<2,2>(icindex641, std::array<u64,2>{v_c11, v_c9}, [&](const std::array<u64,2>& m648) {
          slog::join_probe<2,1>(icindex642, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m649) {
            u64 v_c10 = m649[1];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c13}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:10", "delta:ladd", _fires);
  
      if (!_done)
      {
        ReadTask643* _cont = new ReadTask643(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask643(db,b), false);
  // (crule (pre (let __tconst0zRk108 constba2df4903a2c14e86dc3bcca) (let __tconst0t5V106 const4e07408562bedb8b60ce05c1)) (once) (body) (head (mkstruct iv (1 0) __t0r3v109 __tconst0zRk108) (mkstruct ic (1 0) __t2oHn107 __tconst0t5V106)) smt_basic.slog:12 #f)
  class ReadTask650 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("iv");
      head_rel[1] = db->getRelation("ic");
  
    }
    ReadTask650(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c59 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c58}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c59}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_basic.slog:12", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask650(db,b), true);
  s->addReadRel("_enum");
  s->addReadRel("ic");
  s->addReadRel("iv");
  s->addReadRel("ladd");
  s->addReadRel("land");
  s->addReadRel("leq");
  s->addReadRel("limplies");
  s->addReadRel("lle");
  s->addReadRel("llt");
  s->addReadRel("lmul");
  s->addReadRel("lnot");
  s->addReadRel("lor");
  s->addReadRel("lsub");
  s->addDynamicRel("ic");
  s->addDynamicRel("iv");
  s->addDynamicRel("ladd");
  s->addDynamicRel("land");
  s->addDynamicRel("leq");
  s->addDynamicRel("limplies");
  s->addDynamicRel("lle");
  s->addDynamicRel("llt");
  s->addDynamicRel("lmul");
  s->addDynamicRel("lnot");
  s->addDynamicRel("lor");
  s->addDynamicRel("lsub");
  s->addDynamicRel("smt_check");
  s->addDynamicRel("smt_vcode");
  d->push(s);
  d->continueRun();
}

