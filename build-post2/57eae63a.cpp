
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constf5ca38f748a1d6eaf726b8a4;
u64 v_constef2d127de37b942baad06145;
u64 v_const612d2f2691ec8624afedcf05;
u64 v_const1787782f5c8e05277c006bf6;
u64 v_consta221beeaebe583607e193be7;
u64 v_consteb8bf0d80db323992f6b634a;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4dfc9fee1f81489e4abdc99b;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constba2df4903a2c14e86dc3bcca;
u64 v_const683276d23a1fc1d255583994;
u64 v_constcf2159ef79c92288880f3bda;
u64 v_constee295786ce9f03797df76c26;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const95a8ad3372b357660caccad5;
u64 v_constcbb254813eb3d1fd6f3fddfd;
u64 v_constab76c7d069d6f33dc950fb33;
u64 v_const2835887d470b7bc39db04564;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("57eae63a");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constf5ca38f748a1d6eaf726b8a4 = s32_encode(20);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const612d2f2691ec8624afedcf05 = db->encodeString("must-not-appear");
  v_const1787782f5c8e05277c006bf6 = db->encodeString("vacuous");
  v_consta221beeaebe583607e193be7 = db->encodeString("unsat");
  v_consteb8bf0d80db323992f6b634a = db->encodeString("unknown");
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4dfc9fee1f81489e4abdc99b = db->encodeString("bad-sum-check");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constba2df4903a2c14e86dc3bcca = db->encodeString("x");
  v_const683276d23a1fc1d255583994 = db->encodeString("ltrue");
  v_constcf2159ef79c92288880f3bda = db->encodeString("bad-sum");
  v_constee295786ce9f03797df76c26 = db->encodeString("lfalse");
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const95a8ad3372b357660caccad5 = db->encodeString("nine-le-ten");
  v_constcbb254813eb3d1fd6f3fddfd = db->encodeString("true-conj");
  v_constab76c7d069d6f33dc950fb33 = db->encodeString("sat");
  v_const2835887d470b7bc39db04564 = db->encodeString("free-var");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord297({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord297, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord298({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord298, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord299({1, 2, 0});
    
    r->addIndex<3>(ord299, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord300({0, 1, 2});
    
    r->addIndex<3>(ord300, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_vcode");
  if (r == 0) db->addRelation("smt_vcode", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_vcode");
      std::vector<u16> ord301({0, 1});
    
    r->addIndex<2>(ord301, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_vcode"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_unsat");
  if (r == 0) db->addRelation("smt_unsat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unsat");
      std::vector<u16> ord302({0});
    
    r->addIndex<1>(ord302, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unsat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_unknown");
  if (r == 0) db->addRelation("smt_unknown", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unknown");
      std::vector<u16> ord303({0});
    
    r->addIndex<1>(ord303, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unknown"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_sat");
  if (r == 0) db->addRelation("smt_sat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_sat");
      std::vector<u16> ord304({0});
    
    r->addIndex<1>(ord304, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_sat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_qsat_ans");
  if (r == 0) db->addRelation("smt_qsat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord305({0, 1});
    
    r->addIndex<2>(ord305, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qsat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qsat");
  if (r == 0) db->addStruct("smt_qsat", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat");
      std::vector<u16> ord306({1, 0});
    
    r->addIndex<2>(ord306, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord307({0, 1});
    
    r->addIndex<2>(ord307, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qsat"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qmodel_ans");
  if (r == 0) db->addRelation("smt_qmodel_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel_ans");
      std::vector<u16> ord308({0, 1});
    
    r->addIndex<2>(ord308, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qmodel_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qmodel");
  if (r == 0) db->addStruct("smt_qmodel", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel");
      std::vector<u16> ord309({1, 0});
    
    r->addIndex<2>(ord309, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord310({0, 1});
    
    r->addIndex<2>(ord310, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qmodel"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qcore_ans");
  if (r == 0) db->addRelation("smt_qcore_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore_ans");
      std::vector<u16> ord311({0, 1});
    
    r->addIndex<2>(ord311, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qcore_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qcore");
  if (r == 0) db->addStruct("smt_qcore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore");
      std::vector<u16> ord312({1, 0});
    
    r->addIndex<2>(ord312, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord313({0, 1});
    
    r->addIndex<2>(ord313, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qcore"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_model_ans");
  if (r == 0) db->addRelation("smt_model_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model_ans");
      std::vector<u16> ord314({0, 1, 2});
    
    r->addIndex<3>(ord314, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_model_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_model");
  if (r == 0) db->addStruct("smt_model", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model");
      std::vector<u16> ord315({1, 0});
    
    r->addIndex<2>(ord315, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord316({0, 1});
    
    r->addIndex<2>(ord316, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_model"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_core_ans");
  if (r == 0) db->addRelation("smt_core_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core_ans");
      std::vector<u16> ord317({0, 1, 2});
    
    r->addIndex<3>(ord317, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_core_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_core");
  if (r == 0) db->addStruct("smt_core", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core");
      std::vector<u16> ord318({1, 0});
    
    r->addIndex<2>(ord318, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord319({0, 1});
    
    r->addIndex<2>(ord319, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_core"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check_ans");
  if (r == 0) db->addRelation("smt_check_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check_ans");
      std::vector<u16> ord320({0, 1});
    
    r->addIndex<2>(ord320, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord321({1, 0});
    
    r->addIndex<2>(ord321, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_check_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_check");
  if (r == 0) db->addStruct("smt_check", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check");
      std::vector<u16> ord322({1, 0});
    
    r->addIndex<2>(ord322, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord323({0, 1});
    
    r->addIndex<2>(ord323, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_check"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord324({1, 2, 0});
    
    r->addIndex<3>(ord324, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord325({0, 1, 2});
    
    r->addIndex<3>(ord325, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord326({0, 1});
    
    r->addIndex<2>(ord326, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("probe"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord327({1, 2, 3, 0});
    
    r->addIndex<4>(ord327, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord328({0, 1, 2, 3});
    
    r->addIndex<4>(ord328, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord329({1, 2, 0});
    
    r->addIndex<3>(ord329, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord330({0, 1, 2});
    
    r->addIndex<3>(ord330, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord331({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord331, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord332({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord332, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord333({1, 2, 0});
    
    r->addIndex<3>(ord333, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord334({0, 1, 2});
    
    r->addIndex<3>(ord334, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord335({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord335, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord336({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord336, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lsub");
  if (r == 0) db->addStruct("lsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lsub");
      std::vector<u16> ord337({1, 2, 0});
    
    r->addIndex<3>(ord337, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord338({0, 1, 2});
    
    r->addIndex<3>(ord338, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lsub"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lor");
  if (r == 0) db->addStruct("lor", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lor");
      std::vector<u16> ord339({1, 2, 0});
    
    r->addIndex<3>(ord339, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord340({0, 1, 2});
    
    r->addIndex<3>(ord340, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lor"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lnot");
  if (r == 0) db->addStruct("lnot", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lnot");
      std::vector<u16> ord341({1, 0});
    
    r->addIndex<2>(ord341, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord342({0, 1});
    
    r->addIndex<2>(ord342, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lnot"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lne");
  if (r == 0) db->addStruct("lne", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lne");
      std::vector<u16> ord343({1, 2, 0});
    
    r->addIndex<3>(ord343, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord344({0, 1, 2});
    
    r->addIndex<3>(ord344, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lne"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lmul");
  if (r == 0) db->addStruct("lmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lmul");
      std::vector<u16> ord345({1, 2, 0});
    
    r->addIndex<3>(ord345, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord346({0, 1, 2});
    
    r->addIndex<3>(ord346, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lmul"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("llt");
  if (r == 0) db->addStruct("llt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("llt");
      std::vector<u16> ord347({2, 1, 0});
    
    r->addIndex<3>(ord347, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord348({0, 1, 2});
    
    r->addIndex<3>(ord348, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("llt"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lle");
  if (r == 0) db->addStruct("lle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lle");
      std::vector<u16> ord349({2, 1, 0});
    
    r->addIndex<3>(ord349, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord350({0, 1, 2});
    
    r->addIndex<3>(ord350, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lle"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lite");
  if (r == 0) db->addStruct("lite", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lite");
      std::vector<u16> ord351({1, 2, 3, 0});
    
    r->addIndex<4>(ord351, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord352({0, 1, 2, 3});
    
    r->addIndex<4>(ord352, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("lite"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("limplies");
  if (r == 0) db->addStruct("limplies", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("limplies");
      std::vector<u16> ord353({2, 1, 0});
    
    r->addIndex<3>(ord353, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord354({0, 1, 2});
    
    r->addIndex<3>(ord354, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("limplies"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lgt");
  if (r == 0) db->addStruct("lgt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lgt");
      std::vector<u16> ord355({1, 2, 0});
    
    r->addIndex<3>(ord355, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord356({0, 1, 2});
    
    r->addIndex<3>(ord356, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lgt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lge");
  if (r == 0) db->addStruct("lge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lge");
      std::vector<u16> ord357({1, 2, 0});
    
    r->addIndex<3>(ord357, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord358({0, 1, 2});
    
    r->addIndex<3>(ord358, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lge"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("leq");
  if (r == 0) db->addStruct("leq", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leq");
      std::vector<u16> ord359({2, 1, 0});
    
    r->addIndex<3>(ord359, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord360({0, 2, 1});
    
    r->addIndex<3>(ord360, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("leq"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lany");
  if (r == 0) db->addStruct("lany", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lany");
      std::vector<u16> ord361({1, 0});
    
    r->addIndex<2>(ord361, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord362({0, 1});
    
    r->addIndex<2>(ord362, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lany"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("land");
  if (r == 0) db->addStruct("land", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("land");
      std::vector<u16> ord363({2, 1, 0});
    
    r->addIndex<3>(ord363, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord364({0, 1, 2});
    
    r->addIndex<3>(ord364, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("land"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lall");
  if (r == 0) db->addStruct("lall", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lall");
      std::vector<u16> ord365({1, 0});
    
    r->addIndex<2>(ord365, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord366({0, 1});
    
    r->addIndex<2>(ord366, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lall"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ladd");
  if (r == 0) db->addStruct("ladd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ladd");
      std::vector<u16> ord367({1, 2, 0});
    
    r->addIndex<3>(ord367, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord368({0, 1, 2});
    
    r->addIndex<3>(ord368, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ladd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("iv");
  if (r == 0) db->addStruct("iv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("iv");
      std::vector<u16> ord369({1, 0});
    
    r->addIndex<2>(ord369, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord370({0, 1});
    
    r->addIndex<2>(ord370, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("iv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord371({1, 2, 3, 0});
    
    r->addIndex<4>(ord371, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord372({0, 1, 2, 3});
    
    r->addIndex<4>(ord372, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ic");
  if (r == 0) db->addStruct("ic", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ic");
      std::vector<u16> ord373({1, 0});
    
    r->addIndex<2>(ord373, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord374({0, 1});
    
    r->addIndex<2>(ord374, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord375({1, 0});
    
    r->addIndex<2>(ord375, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ic"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord376({0});
    
    r->addIndex<1>(ord376, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("elidable");
  if (r == 0) db->addRelation("elidable", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("elidable");
      std::vector<u16> ord377({0});
    
    r->addIndex<1>(ord377, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("elidable"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord378({1, 2, 0});
    
    r->addIndex<3>(ord378, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord379({0, 1, 2});
    
    r->addIndex<3>(ord379, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bv");
  if (r == 0) db->addStruct("bv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bv");
      std::vector<u16> ord380({1, 0});
    
    r->addIndex<2>(ord380, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord381({0, 1});
    
    r->addIndex<2>(ord381, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("bv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord382({1, 0});
    
    r->addIndex<2>(ord382, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord383({0, 1});
    
    r->addIndex<2>(ord383, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord384({1, 0});
    
    r->addIndex<2>(ord384, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst8UOK172 consta221beeaebe583607e193be7) (let __tconst7vi17 constd4735e3a265e16eee03f5971) (let __tconst7Jbp3 constef2d127de37b942baad06145) (let __tconst2Has1 const4dfc9fee1f81489e4abdc99b)) (probe _enum (1 0) 1 __tconst8UOK172 __v0) (body (exists ic (1 0) 1 __tconst7vi17) (exists ic (1 0) 1 __tconst7Jbp3) (join smt_check_ans (1 0) 1 __v0 __t4o1A11) (join smt_check (0 1) 1 __t4o1A11 __t395z10) (join ic (1 0) 1 __tconst7vi17 __t1TGD6) (exists ladd (1 2 0) 1 __t1TGD6) (join ic (1 0) 1 __tconst7Jbp3 __t75394) (join leq (0 2 1) 2 __t395z10 __t75394 __t7H1c9) (join ladd (0 1 2) 2 __t7H1c9 __t1TGD6 dup6ZsK277) (eq __t1TGD6 dup6ZsK277)) (head (emit elidable (0) __tconst2Has1)) smt_basic.slog:21 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex0;  slog::Index** icindex1;  slog::Index** smt_check_ansindex2;  slog::Index** smt_checkindex3;  slog::Index** icindex4;  slog::Index** laddindex5;  slog::Index** icindex6;  slog::Index** leqindex7;  slog::Index** laddindex8;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("elidable");
      std::vector<u16> ord10({0});
      slog::Relation* readrel11 = db->getRelation("elidable");
      head_index[0] = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("_enum");
      driver_index = readrel13->getIndex(ord12, true);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("ic");
      icindex0 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("ic");
      icindex1 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 0});
      slog::Relation* readrel19 = db->getRelation("smt_check_ans");
      smt_check_ansindex2 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("smt_check");
      smt_checkindex3 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("ic");
      icindex4 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 2, 0});
      slog::Relation* readrel25 = db->getRelation("ladd");
      laddindex5 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 0});
      slog::Relation* readrel27 = db->getRelation("ic");
      icindex6 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 2, 1});
      slog::Relation* readrel29 = db->getRelation("leq");
      leqindex7 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1, 2});
      slog::Relation* readrel31 = db->getRelation("ladd");
      laddindex8 = readrel31->getIndex(ord30, false);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_consta221beeaebe583607e193be7;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_constef2d127de37b942baad06145;
      u64 v_c3 = v_const4dfc9fee1f81489e4abdc99b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m32) {
        u64 v_c4 = m32[1];
        if (buckethash(v_c4) != bucket) return;
        if (!slog::exists_probe<2,1>(icindex0, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(icindex1, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<2,1>(smt_check_ansindex2, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m33) {
          u64 v_c5 = m33[1];
          slog::join_probe<2,1>(smt_checkindex3, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m34) {
            u64 v_c6 = m34[1];
            slog::join_probe<2,1>(icindex4, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m35) {
              u64 v_c7 = m35[1];
              if (!slog::exists_probe<3,1>(laddindex5, std::array<u64,3>{v_c7, 0, 0})) return;
              slog::join_probe<2,1>(icindex6, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m36) {
                u64 v_c8 = m36[1];
                slog::join_probe<3,2>(leqindex7, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m37) {
                  u64 v_c9 = m37[2];
                  slog::join_probe<3,2>(laddindex8, std::array<u64,3>{v_c9, v_c7, 0}, [&](const std::array<u64,3>& m38) {
                    u64 v_c10 = m38[2];
                    if (v_c7 != v_c10) return;
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:21", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask9* _cont = new ReadTask9(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), true);
  // (crule (pre (let __tconst02j9168 constee295786ce9f03797df76c26) (let __tconst4awK99 constd4735e3a265e16eee03f5971) (let __tconst8gwQ101 const6b86b273ff34fce19d6b804e) (let __tconst6FKO96 constcbb254813eb3d1fd6f3fddfd)) (probe _enum (1 0) 1 __tconst02j9168 __t6tdG97) (body (exists ic (1 0) 1 __tconst4awK99) (exists ic (1 0) 1 __tconst8gwQ101) (join lnot (1 0) 1 __t6tdG97 __t1ROt98) (exists land (2 1 0) 1 __t1ROt98) (join ic (1 0) 1 __tconst4awK99 __t8JFR100) (exists llt (2 1 0) 1 __t8JFR100) (join ic (1 0) 1 __tconst8gwQ101 __t0ZZg102) (join llt (2 1 0) 2 __t8JFR100 __t0ZZg102 __t3aPe103) (join land (2 1 0) 2 __t1ROt98 __t3aPe103 __t4XYf104) (join smt_check (1 0) 1 __t4XYf104 __t3LhU105) (join smt_check_ans (0 1) 1 __t3LhU105 V)) (head (emit probe (0 1) __tconst6FKO96 V)) smt_basic.slog:8 #f)
  class ReadTask50 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex39;  slog::Index** icindex40;  slog::Index** lnotindex41;  slog::Index** landindex42;  slog::Index** icindex43;  slog::Index** lltindex44;  slog::Index** icindex45;  slog::Index** lltindex46;  slog::Index** landindex47;  slog::Index** smt_checkindex48;  slog::Index** smt_check_ansindex49;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("probe");
      head_index[0] = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 0});
      slog::Relation* readrel54 = db->getRelation("_enum");
      driver_index = readrel54->getIndex(ord53, true);
      std::vector<u16> ord55({1, 0});
      slog::Relation* readrel56 = db->getRelation("ic");
      icindex39 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 0});
      slog::Relation* readrel58 = db->getRelation("ic");
      icindex40 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 0});
      slog::Relation* readrel60 = db->getRelation("lnot");
      lnotindex41 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({2, 1, 0});
      slog::Relation* readrel62 = db->getRelation("land");
      landindex42 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 0});
      slog::Relation* readrel64 = db->getRelation("ic");
      icindex43 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({2, 1, 0});
      slog::Relation* readrel66 = db->getRelation("llt");
      lltindex44 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({1, 0});
      slog::Relation* readrel68 = db->getRelation("ic");
      icindex45 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({2, 1, 0});
      slog::Relation* readrel70 = db->getRelation("llt");
      lltindex46 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({2, 1, 0});
      slog::Relation* readrel72 = db->getRelation("land");
      landindex47 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 0});
      slog::Relation* readrel74 = db->getRelation("smt_check");
      smt_checkindex48 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("smt_check_ans");
      smt_check_ansindex49 = readrel76->getIndex(ord75, false);
  
    }
    ReadTask50(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_constee295786ce9f03797df76c26;
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constcbb254813eb3d1fd6f3fddfd;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c11, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m77) {
        u64 v_c15 = m77[1];
        if (buckethash(v_c15) != bucket) return;
        if (!slog::exists_probe<2,1>(icindex39, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(icindex40, std::array<u64,2>{v_c13, 0})) return;
        slog::join_probe<2,1>(lnotindex41, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m78) {
          u64 v_c16 = m78[1];
          if (!slog::exists_probe<3,1>(landindex42, std::array<u64,3>{v_c16, 0, 0})) return;
          slog::join_probe<2,1>(icindex43, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m79) {
            u64 v_c17 = m79[1];
            if (!slog::exists_probe<3,1>(lltindex44, std::array<u64,3>{v_c17, 0, 0})) return;
            slog::join_probe<2,1>(icindex45, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m80) {
              u64 v_c18 = m80[1];
              slog::join_probe<3,2>(lltindex46, std::array<u64,3>{v_c17, v_c18, 0}, [&](const std::array<u64,3>& m81) {
                u64 v_c19 = m81[2];
                slog::join_probe<3,2>(landindex47, std::array<u64,3>{v_c16, v_c19, 0}, [&](const std::array<u64,3>& m82) {
                  u64 v_c20 = m82[2];
                  slog::join_probe<2,1>(smt_checkindex48, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m83) {
                    u64 v_c21 = m83[1];
                    slog::join_probe<2,1>(smt_check_ansindex49, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m84) {
                      u64 v_c22 = m84[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c14, v_c22}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:8", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask50* _cont = new ReadTask50(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask50(db,b), true);
  // (crule (pre (let __tconst0Erz141 constd4735e3a265e16eee03f5971) (let __tconst3bw7137 constef2d127de37b942baad06145) (let __tconst7nJ4136 constcf2159ef79c92288880f3bda)) (probe ic (1 0) 1 __tconst0Erz141 __t1wFi140) (body (exists ladd (1 2 0) 1 __t1wFi140) (join ic (1 0) 1 __tconst3bw7137 __t6x02138) (exists leq (2 1 0) 1 __t6x02138) (join ladd (1 2 0) 1 __t1wFi140 dup2Udl278 __t5Zfy143) (eq __t1wFi140 dup2Udl278) (join leq (2 1 0) 2 __t6x02138 __t5Zfy143 __t6VcO144) (join smt_check (1 0) 1 __t6VcO144 __t6xEm145) (join smt_check_ans (0 1) 1 __t6xEm145 V)) (head (emit probe (0 1) __tconst7nJ4136 V)) smt_basic.slog:10 #f)
  class ReadTask92 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** laddindex85;  slog::Index** icindex86;  slog::Index** leqindex87;  slog::Index** laddindex88;  slog::Index** leqindex89;  slog::Index** smt_checkindex90;  slog::Index** smt_check_ansindex91;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord93({0, 1});
      slog::Relation* readrel94 = db->getRelation("probe");
      head_index[0] = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 0});
      slog::Relation* readrel96 = db->getRelation("ic");
      driver_index = readrel96->getIndex(ord95, true);
      std::vector<u16> ord97({1, 2, 0});
      slog::Relation* readrel98 = db->getRelation("ladd");
      laddindex85 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 0});
      slog::Relation* readrel100 = db->getRelation("ic");
      icindex86 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({2, 1, 0});
      slog::Relation* readrel102 = db->getRelation("leq");
      leqindex87 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 0});
      slog::Relation* readrel104 = db->getRelation("ladd");
      laddindex88 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({2, 1, 0});
      slog::Relation* readrel106 = db->getRelation("leq");
      leqindex89 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 0});
      slog::Relation* readrel108 = db->getRelation("smt_check");
      smt_checkindex90 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("smt_check_ans");
      smt_check_ansindex91 = readrel110->getIndex(ord109, false);
  
    }
    ReadTask92(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_constd4735e3a265e16eee03f5971;
      u64 v_c24 = v_constef2d127de37b942baad06145;
      u64 v_c25 = v_constcf2159ef79c92288880f3bda;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c23, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m111) {
        u64 v_c26 = m111[1];
        if (buckethash(v_c26) != bucket) return;
        if (!slog::exists_probe<3,1>(laddindex85, std::array<u64,3>{v_c26, 0, 0})) return;
        slog::join_probe<2,1>(icindex86, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m112) {
          u64 v_c27 = m112[1];
          if (!slog::exists_probe<3,1>(leqindex87, std::array<u64,3>{v_c27, 0, 0})) return;
          slog::join_probe<3,1>(laddindex88, std::array<u64,3>{v_c26, 0, 0}, [&](const std::array<u64,3>& m113) {
            u64 v_c28 = m113[1]; u64 v_c29 = m113[2];
            if (v_c26 != v_c28) return;
            slog::join_probe<3,2>(leqindex89, std::array<u64,3>{v_c27, v_c29, 0}, [&](const std::array<u64,3>& m114) {
              u64 v_c30 = m114[2];
              slog::join_probe<2,1>(smt_checkindex90, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m115) {
                u64 v_c31 = m115[1];
                slog::join_probe<2,1>(smt_check_ansindex91, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m116) {
                  u64 v_c22 = m116[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c25, v_c22}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:10", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask92* _cont = new ReadTask92(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask92(db,b), true);
  // (crule (pre (let __tconst2TS458 const4e07408562bedb8b60ce05c1) (let __tconst4OUY60 constba2df4903a2c14e86dc3bcca) (let __tconst6h2A57 const2835887d470b7bc39db04564)) (probe ic (1 0) 1 __tconst2TS458 __t3MWa59) (body (exists llt (2 1 0) 1 __t3MWa59) (join iv (1 0) 1 __tconst4OUY60 __t7ofA61) (join llt (2 1 0) 2 __t3MWa59 __t7ofA61 __t1TeU62) (join smt_check (1 0) 1 __t1TeU62 __t0saf63) (join smt_check_ans (0 1) 1 __t0saf63 V)) (head (emit probe (0 1) __tconst6h2A57 V)) smt_basic.slog:12 #f)
  class ReadTask122 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex117;  slog::Index** ivindex118;  slog::Index** lltindex119;  slog::Index** smt_checkindex120;  slog::Index** smt_check_ansindex121;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord123({0, 1});
      slog::Relation* readrel124 = db->getRelation("probe");
      head_index[0] = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({1, 0});
      slog::Relation* readrel126 = db->getRelation("ic");
      driver_index = readrel126->getIndex(ord125, true);
      std::vector<u16> ord127({2, 1, 0});
      slog::Relation* readrel128 = db->getRelation("llt");
      lltindex117 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({1, 0});
      slog::Relation* readrel130 = db->getRelation("iv");
      ivindex118 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({2, 1, 0});
      slog::Relation* readrel132 = db->getRelation("llt");
      lltindex119 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 0});
      slog::Relation* readrel134 = db->getRelation("smt_check");
      smt_checkindex120 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({0, 1});
      slog::Relation* readrel136 = db->getRelation("smt_check_ans");
      smt_check_ansindex121 = readrel136->getIndex(ord135, false);
  
    }
    ReadTask122(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c32 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c33 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c34 = v_const2835887d470b7bc39db04564;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c32, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m137) {
        u64 v_c35 = m137[1];
        if (buckethash(v_c35) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex117, std::array<u64,3>{v_c35, 0, 0})) return;
        slog::join_probe<2,1>(ivindex118, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m138) {
          u64 v_c36 = m138[1];
          slog::join_probe<3,2>(lltindex119, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m139) {
            u64 v_c37 = m139[2];
            slog::join_probe<2,1>(smt_checkindex120, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m140) {
              u64 v_c38 = m140[1];
              slog::join_probe<2,1>(smt_check_ansindex121, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m141) {
                u64 v_c22 = m141[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c34, v_c22}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:12", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask122* _cont = new ReadTask122(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask122(db,b), true);
  // (crule (pre (let __tconst0V6E169 consteb8bf0d80db323992f6b634a)) (probe _enum (1 0) 1 __tconst0V6E169 __t6zVT93) (body (join smt_check_ans (1 0) 1 __t6zVT93 __t03Qn94) (join smt_check (0 1) 1 __t03Qn94 F)) (head (emit smt_unknown (0) F)) smt.slog:79 #f)
  class ReadTask144 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex142;  slog::Index** smt_checkindex143;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_unknown");
      std::vector<u16> ord145({0});
      slog::Relation* readrel146 = db->getRelation("smt_unknown");
      head_index[0] = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({1, 0});
      slog::Relation* readrel148 = db->getRelation("_enum");
      driver_index = readrel148->getIndex(ord147, true);
      std::vector<u16> ord149({1, 0});
      slog::Relation* readrel150 = db->getRelation("smt_check_ans");
      smt_check_ansindex142 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({0, 1});
      slog::Relation* readrel152 = db->getRelation("smt_check");
      smt_checkindex143 = readrel152->getIndex(ord151, false);
  
    }
    ReadTask144(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_consteb8bf0d80db323992f6b634a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c39, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m153) {
        u64 v_c40 = m153[1];
        if (buckethash(v_c40) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex142, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m154) {
          u64 v_c41 = m154[1];
          slog::join_probe<2,1>(smt_checkindex143, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m155) {
            u64 v_c42 = m155[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c42}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:79", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask144* _cont = new ReadTask144(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask144(db,b), true);
  // (crule (pre (let __tconst0wOt163 const683276d23a1fc1d255583994) (let __tconst0A9W164 constee295786ce9f03797df76c26) (let __tconst68K969 const1787782f5c8e05277c006bf6)) (probe _enum (1 0) 1 __tconst0wOt163 __t0HIe70) (body (exists limplies (2 1 0) 1 __t0HIe70) (join _enum (1 0) 1 __tconst0A9W164 __t7gcx73) (exists lor (1 2 0) 1 __t7gcx73) (join limplies (2 1 0) 2 __t0HIe70 __t7gcx73 __t7RTu72) (join lor (1 2 0) 2 __t7gcx73 __t7RTu72 __t2dVd74) (join smt_check (1 0) 1 __t2dVd74 __t3Shg75) (join smt_check_ans (0 1) 1 __t3Shg75 V)) (head (emit probe (0 1) __tconst68K969 V)) smt_basic.slog:14 #f)
  class ReadTask163 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** limpliesindex156;  slog::Index** _enumindex157;  slog::Index** lorindex158;  slog::Index** limpliesindex159;  slog::Index** lorindex160;  slog::Index** smt_checkindex161;  slog::Index** smt_check_ansindex162;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("probe");
      head_index[0] = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({1, 0});
      slog::Relation* readrel167 = db->getRelation("_enum");
      driver_index = readrel167->getIndex(ord166, true);
      std::vector<u16> ord168({2, 1, 0});
      slog::Relation* readrel169 = db->getRelation("limplies");
      limpliesindex156 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 0});
      slog::Relation* readrel171 = db->getRelation("_enum");
      _enumindex157 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 2, 0});
      slog::Relation* readrel173 = db->getRelation("lor");
      lorindex158 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({2, 1, 0});
      slog::Relation* readrel175 = db->getRelation("limplies");
      limpliesindex159 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({1, 2, 0});
      slog::Relation* readrel177 = db->getRelation("lor");
      lorindex160 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 0});
      slog::Relation* readrel179 = db->getRelation("smt_check");
      smt_checkindex161 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({0, 1});
      slog::Relation* readrel181 = db->getRelation("smt_check_ans");
      smt_check_ansindex162 = readrel181->getIndex(ord180, false);
  
    }
    ReadTask163(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const683276d23a1fc1d255583994;
      u64 v_c44 = v_constee295786ce9f03797df76c26;
      u64 v_c45 = v_const1787782f5c8e05277c006bf6;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c43, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m182) {
        u64 v_c46 = m182[1];
        if (buckethash(v_c46) != bucket) return;
        if (!slog::exists_probe<3,1>(limpliesindex156, std::array<u64,3>{v_c46, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex157, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m183) {
          u64 v_c47 = m183[1];
          if (!slog::exists_probe<3,1>(lorindex158, std::array<u64,3>{v_c47, 0, 0})) return;
          slog::join_probe<3,2>(limpliesindex159, std::array<u64,3>{v_c46, v_c47, 0}, [&](const std::array<u64,3>& m184) {
            u64 v_c48 = m184[2];
            slog::join_probe<3,2>(lorindex160, std::array<u64,3>{v_c47, v_c48, 0}, [&](const std::array<u64,3>& m185) {
              u64 v_c49 = m185[2];
              slog::join_probe<2,1>(smt_checkindex161, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m186) {
                u64 v_c50 = m186[1];
                slog::join_probe<2,1>(smt_check_ansindex162, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m187) {
                  u64 v_c22 = m187[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c22}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:14", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask163* _cont = new ReadTask163(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask163(db,b), true);
  // (crule (pre (let __tconst9OcR159 consta221beeaebe583607e193be7) (let __tconst6e1S43 const4e07408562bedb8b60ce05c1) (let __tconst5VeH45 constba2df4903a2c14e86dc3bcca) (let __tconst9H7I41 const612d2f2691ec8624afedcf05)) (probe _enum (1 0) 1 __tconst9OcR159 __v0) (body (exists ic (1 0) 1 __tconst6e1S43) (exists iv (1 0) 1 __tconst5VeH45) (join smt_check_ans (1 0) 1 __v0 __t37jG48) (join ic (1 0) 1 __tconst6e1S43 __t7jb644) (exists llt (2 1 0) 1 __t7jb644) (join iv (1 0) 1 __tconst5VeH45 __t9zcg46) (join llt (2 1 0) 2 __t7jb644 __t9zcg46 __t5Emh47) (join smt_check (0 1) 2 __t37jG48 __t5Emh47)) (head (emit elidable (0) __tconst9H7I41)) smt_basic.slog:25 #f)
  class ReadTask196 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex188;  slog::Index** ivindex189;  slog::Index** smt_check_ansindex190;  slog::Index** icindex191;  slog::Index** lltindex192;  slog::Index** ivindex193;  slog::Index** lltindex194;  slog::Index** smt_checkindex195;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("elidable");
      std::vector<u16> ord197({0});
      slog::Relation* readrel198 = db->getRelation("elidable");
      head_index[0] = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 0});
      slog::Relation* readrel200 = db->getRelation("_enum");
      driver_index = readrel200->getIndex(ord199, true);
      std::vector<u16> ord201({1, 0});
      slog::Relation* readrel202 = db->getRelation("ic");
      icindex188 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({1, 0});
      slog::Relation* readrel204 = db->getRelation("iv");
      ivindex189 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 0});
      slog::Relation* readrel206 = db->getRelation("smt_check_ans");
      smt_check_ansindex190 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 0});
      slog::Relation* readrel208 = db->getRelation("ic");
      icindex191 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({2, 1, 0});
      slog::Relation* readrel210 = db->getRelation("llt");
      lltindex192 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 0});
      slog::Relation* readrel212 = db->getRelation("iv");
      ivindex193 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({2, 1, 0});
      slog::Relation* readrel214 = db->getRelation("llt");
      lltindex194 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({0, 1});
      slog::Relation* readrel216 = db->getRelation("smt_check");
      smt_checkindex195 = readrel216->getIndex(ord215, false);
  
    }
    ReadTask196(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c51 = v_consta221beeaebe583607e193be7;
      u64 v_c52 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c53 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c54 = v_const612d2f2691ec8624afedcf05;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c51, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m217) {
        u64 v_c4 = m217[1];
        if (buckethash(v_c4) != bucket) return;
        if (!slog::exists_probe<2,1>(icindex188, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex189, std::array<u64,2>{v_c53, 0})) return;
        slog::join_probe<2,1>(smt_check_ansindex190, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m218) {
          u64 v_c55 = m218[1];
          slog::join_probe<2,1>(icindex191, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m219) {
            u64 v_c56 = m219[1];
            if (!slog::exists_probe<3,1>(lltindex192, std::array<u64,3>{v_c56, 0, 0})) return;
            slog::join_probe<2,1>(ivindex193, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m220) {
              u64 v_c57 = m220[1];
              slog::join_probe<3,2>(lltindex194, std::array<u64,3>{v_c56, v_c57, 0}, [&](const std::array<u64,3>& m221) {
                u64 v_c58 = m221[2];
                slog::join_probe<2,2>(smt_checkindex195, std::array<u64,2>{v_c55, v_c58}, [&](const std::array<u64,2>& m222) {
                  ++_fires;
                  slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c54}, std::array<u16,1>{0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:25", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask196* _cont = new ReadTask196(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask196(db,b), true);
  // (crule (pre (let __tconst6gMq174 consta221beeaebe583607e193be7)) (probe _enum (1 0) 1 __tconst6gMq174 __t8FMS55) (body (join smt_check_ans (1 0) 1 __t8FMS55 __t4eXW56) (join smt_check (0 1) 1 __t4eXW56 F)) (head (emit smt_unsat (0) F)) smt.slog:78 #f)
  class ReadTask225 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex223;  slog::Index** smt_checkindex224;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_unsat");
      std::vector<u16> ord226({0});
      slog::Relation* readrel227 = db->getRelation("smt_unsat");
      head_index[0] = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 0});
      slog::Relation* readrel229 = db->getRelation("_enum");
      driver_index = readrel229->getIndex(ord228, true);
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("smt_check_ans");
      smt_check_ansindex223 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 1});
      slog::Relation* readrel233 = db->getRelation("smt_check");
      smt_checkindex224 = readrel233->getIndex(ord232, false);
  
    }
    ReadTask225(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c59 = v_consta221beeaebe583607e193be7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c59, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m234) {
        u64 v_c60 = m234[1];
        if (buckethash(v_c60) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex223, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m235) {
          u64 v_c61 = m235[1];
          slog::join_probe<2,1>(smt_checkindex224, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m236) {
            u64 v_c42 = m236[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c42}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:78", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask225* _cont = new ReadTask225(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask225(db,b), true);
  // (crule (pre (let __tconst7ObR120 const4e07408562bedb8b60ce05c1) (let __tconst5Bn5115 constf5ca38f748a1d6eaf726b8a4) (let __tconst33Ai113 const4a44dc15364204a80fe80e90) (let __tconst1aGD112 const95a8ad3372b357660caccad5)) (probe ic (1 0) 1 __tconst7ObR120 __t8hkX119) (body (exists ic (1 0) 1 __tconst33Ai113) (exists lmul (1 2 0) 1 __t8hkX119) (join ic (1 0) 1 __tconst5Bn5115 __t4pIp116) (exists lsub (1 2 0) 1 __t4pIp116) (join ic (1 0) 1 __tconst33Ai113 __t37is114) (join lsub (1 2 0) 2 __t4pIp116 __t37is114 __t7lAT117) (exists lle (2 1 0) 1 __t7lAT117) (join lmul (1 2 0) 1 __t8hkX119 dup7ns1276 __t3JV7122) (eq __t8hkX119 dup7ns1276) (join lle (2 1 0) 2 __t7lAT117 __t3JV7122 __t0OEK123) (join smt_check (1 0) 1 __t0OEK123 __t7gZL124) (join smt_check_ans (0 1) 1 __t7gZL124 V)) (head (emit probe (0 1) __tconst1aGD112 V)) smt_basic.slog:16 #f)
  class ReadTask248 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex237;  slog::Index** lmulindex238;  slog::Index** icindex239;  slog::Index** lsubindex240;  slog::Index** icindex241;  slog::Index** lsubindex242;  slog::Index** lleindex243;  slog::Index** lmulindex244;  slog::Index** lleindex245;  slog::Index** smt_checkindex246;  slog::Index** smt_check_ansindex247;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord249({0, 1});
      slog::Relation* readrel250 = db->getRelation("probe");
      head_index[0] = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 0});
      slog::Relation* readrel252 = db->getRelation("ic");
      driver_index = readrel252->getIndex(ord251, true);
      std::vector<u16> ord253({1, 0});
      slog::Relation* readrel254 = db->getRelation("ic");
      icindex237 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({1, 2, 0});
      slog::Relation* readrel256 = db->getRelation("lmul");
      lmulindex238 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 0});
      slog::Relation* readrel258 = db->getRelation("ic");
      icindex239 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("lsub");
      lsubindex240 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 0});
      slog::Relation* readrel262 = db->getRelation("ic");
      icindex241 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 2, 0});
      slog::Relation* readrel264 = db->getRelation("lsub");
      lsubindex242 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({2, 1, 0});
      slog::Relation* readrel266 = db->getRelation("lle");
      lleindex243 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 2, 0});
      slog::Relation* readrel268 = db->getRelation("lmul");
      lmulindex244 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({2, 1, 0});
      slog::Relation* readrel270 = db->getRelation("lle");
      lleindex245 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({1, 0});
      slog::Relation* readrel272 = db->getRelation("smt_check");
      smt_checkindex246 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({0, 1});
      slog::Relation* readrel274 = db->getRelation("smt_check_ans");
      smt_check_ansindex247 = readrel274->getIndex(ord273, false);
  
    }
    ReadTask248(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c63 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c64 = v_const4a44dc15364204a80fe80e90;
      u64 v_c65 = v_const95a8ad3372b357660caccad5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c62, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m275) {
        u64 v_c66 = m275[1];
        if (buckethash(v_c66) != bucket) return;
        if (!slog::exists_probe<2,1>(icindex237, std::array<u64,2>{v_c64, 0})) return;
        if (!slog::exists_probe<3,1>(lmulindex238, std::array<u64,3>{v_c66, 0, 0})) return;
        slog::join_probe<2,1>(icindex239, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m276) {
          u64 v_c67 = m276[1];
          if (!slog::exists_probe<3,1>(lsubindex240, std::array<u64,3>{v_c67, 0, 0})) return;
          slog::join_probe<2,1>(icindex241, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m277) {
            u64 v_c68 = m277[1];
            slog::join_probe<3,2>(lsubindex242, std::array<u64,3>{v_c67, v_c68, 0}, [&](const std::array<u64,3>& m278) {
              u64 v_c69 = m278[2];
              if (!slog::exists_probe<3,1>(lleindex243, std::array<u64,3>{v_c69, 0, 0})) return;
              slog::join_probe<3,1>(lmulindex244, std::array<u64,3>{v_c66, 0, 0}, [&](const std::array<u64,3>& m279) {
                u64 v_c70 = m279[1]; u64 v_c71 = m279[2];
                if (v_c66 != v_c70) return;
                slog::join_probe<3,2>(lleindex245, std::array<u64,3>{v_c69, v_c71, 0}, [&](const std::array<u64,3>& m280) {
                  u64 v_c72 = m280[2];
                  slog::join_probe<2,1>(smt_checkindex246, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m281) {
                    u64 v_c73 = m281[1];
                    slog::join_probe<2,1>(smt_check_ansindex247, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m282) {
                      u64 v_c22 = m282[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c65, v_c22}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_basic.slog:16", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask248* _cont = new ReadTask248(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask248(db,b), true);
  // (crule (pre (let __tconst1h6i150 constab76c7d069d6f33dc950fb33)) (probe _enum (1 0) 1 __tconst1h6i150 __t3D4j31) (body (join smt_check_ans (1 0) 1 __t3D4j31 __t6esP32) (join smt_check (0 1) 1 __t6esP32 F)) (head (emit smt_sat (0) F)) smt.slog:77 #f)
  class ReadTask285 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex283;  slog::Index** smt_checkindex284;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_sat");
      std::vector<u16> ord286({0});
      slog::Relation* readrel287 = db->getRelation("smt_sat");
      head_index[0] = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 0});
      slog::Relation* readrel289 = db->getRelation("_enum");
      driver_index = readrel289->getIndex(ord288, true);
      std::vector<u16> ord290({1, 0});
      slog::Relation* readrel291 = db->getRelation("smt_check_ans");
      smt_check_ansindex283 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({0, 1});
      slog::Relation* readrel293 = db->getRelation("smt_check");
      smt_checkindex284 = readrel293->getIndex(ord292, false);
  
    }
    ReadTask285(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c74 = v_constab76c7d069d6f33dc950fb33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c74, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m294) {
        u64 v_c75 = m294[1];
        if (buckethash(v_c75) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex283, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m295) {
          u64 v_c76 = m295[1];
          slog::join_probe<2,1>(smt_checkindex284, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m296) {
            u64 v_c42 = m296[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c42}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:77", "all:_enum", _fires);
  
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
  s->addReadRel("smt_check");
  s->addReadRel("smt_check_ans");
  s->addDynamicRel("elidable");
  s->addDynamicRel("probe");
  s->addDynamicRel("smt_sat");
  s->addDynamicRel("smt_unknown");
  s->addDynamicRel("smt_unsat");
  d->push(s);
  d->continueRun();
}

