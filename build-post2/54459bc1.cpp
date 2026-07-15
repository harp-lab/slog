
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const387ccbac691f72049eabce09;
u64 v_consta221beeaebe583607e193be7;
u64 v_constab76c7d069d6f33dc950fb33;
u64 v_consteb8bf0d80db323992f6b634a;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const744f9b8e5b636a30ad112686;
u64 v_const7b46e63d74de2f1954f46ee5;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constba2df4903a2c14e86dc3bcca;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("54459bc1");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const387ccbac691f72049eabce09 = db->encodeString("symbolic");
  v_consta221beeaebe583607e193be7 = db->encodeString("unsat");
  v_constab76c7d069d6f33dc950fb33 = db->encodeString("sat");
  v_consteb8bf0d80db323992f6b634a = db->encodeString("unknown");
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const744f9b8e5b636a30ad112686 = db->encodeString("ground-sat");
  v_const7b46e63d74de2f1954f46ee5 = db->encodeString("ground-unsat");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constba2df4903a2c14e86dc3bcca = db->encodeString("x");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord117({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord118({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord119({1, 2, 0});
    
    r->addIndex<3>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord120({0, 1, 2});
    
    r->addIndex<3>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_vcode");
  if (r == 0) db->addRelation("smt_vcode", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_vcode");
      std::vector<u16> ord121({0, 1});
    
    r->addIndex<2>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_vcode"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_unsat");
  if (r == 0) db->addRelation("smt_unsat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unsat");
      std::vector<u16> ord122({0});
    
    r->addIndex<1>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unsat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_unknown");
  if (r == 0) db->addRelation("smt_unknown", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unknown");
      std::vector<u16> ord123({0});
    
    r->addIndex<1>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unknown"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_sat");
  if (r == 0) db->addRelation("smt_sat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_sat");
      std::vector<u16> ord124({0});
    
    r->addIndex<1>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_sat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_qsat_ans");
  if (r == 0) db->addRelation("smt_qsat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord125({0, 1});
    
    r->addIndex<2>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qsat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qsat");
  if (r == 0) db->addStruct("smt_qsat", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat");
      std::vector<u16> ord126({1, 0});
    
    r->addIndex<2>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord127({0, 1});
    
    r->addIndex<2>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qsat"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qmodel_ans");
  if (r == 0) db->addRelation("smt_qmodel_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel_ans");
      std::vector<u16> ord128({0, 1});
    
    r->addIndex<2>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qmodel_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qmodel");
  if (r == 0) db->addStruct("smt_qmodel", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel");
      std::vector<u16> ord129({1, 0});
    
    r->addIndex<2>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord130({0, 1});
    
    r->addIndex<2>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qmodel"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qcore_ans");
  if (r == 0) db->addRelation("smt_qcore_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore_ans");
      std::vector<u16> ord131({0, 1});
    
    r->addIndex<2>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qcore_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qcore");
  if (r == 0) db->addStruct("smt_qcore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore");
      std::vector<u16> ord132({1, 0});
    
    r->addIndex<2>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord133({0, 1});
    
    r->addIndex<2>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qcore"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_model_ans");
  if (r == 0) db->addRelation("smt_model_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model_ans");
      std::vector<u16> ord134({0, 1, 2});
    
    r->addIndex<3>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_model_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_model");
  if (r == 0) db->addStruct("smt_model", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model");
      std::vector<u16> ord135({1, 0});
    
    r->addIndex<2>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord136({0, 1});
    
    r->addIndex<2>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_model"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_core_ans");
  if (r == 0) db->addRelation("smt_core_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core_ans");
      std::vector<u16> ord137({0, 1, 2});
    
    r->addIndex<3>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_core_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_core");
  if (r == 0) db->addStruct("smt_core", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core");
      std::vector<u16> ord138({1, 0});
    
    r->addIndex<2>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord139({0, 1});
    
    r->addIndex<2>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_core"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check_ans");
  if (r == 0) db->addRelation("smt_check_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check_ans");
      std::vector<u16> ord140({1, 0});
    
    r->addIndex<2>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_check_ans"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check");
  if (r == 0) db->addStruct("smt_check", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check");
      std::vector<u16> ord141({1, 0});
    
    r->addIndex<2>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord142({0, 1});
    
    r->addIndex<2>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_check"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord143({1, 2, 0});
    
    r->addIndex<3>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord144({0, 1, 2});
    
    r->addIndex<3>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord145({0, 1, 2});
    
    r->addIndex<3>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("probe"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord146({1, 2, 3, 0});
    
    r->addIndex<4>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord147({0, 1, 2, 3});
    
    r->addIndex<4>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord148({1, 2, 0});
    
    r->addIndex<3>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord149({0, 1, 2});
    
    r->addIndex<3>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord150({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord151({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord152({1, 2, 0});
    
    r->addIndex<3>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord153({0, 1, 2});
    
    r->addIndex<3>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord154({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord155({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lsub");
  if (r == 0) db->addStruct("lsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lsub");
      std::vector<u16> ord156({1, 2, 0});
    
    r->addIndex<3>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord157({0, 1, 2});
    
    r->addIndex<3>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lsub"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lor");
  if (r == 0) db->addStruct("lor", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lor");
      std::vector<u16> ord158({1, 2, 0});
    
    r->addIndex<3>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord159({0, 1, 2});
    
    r->addIndex<3>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lor"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lnot");
  if (r == 0) db->addStruct("lnot", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lnot");
      std::vector<u16> ord160({1, 0});
    
    r->addIndex<2>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord161({0, 1});
    
    r->addIndex<2>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lnot"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lne");
  if (r == 0) db->addStruct("lne", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lne");
      std::vector<u16> ord162({1, 2, 0});
    
    r->addIndex<3>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord163({0, 1, 2});
    
    r->addIndex<3>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lne"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lmul");
  if (r == 0) db->addStruct("lmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lmul");
      std::vector<u16> ord164({1, 2, 0});
    
    r->addIndex<3>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord165({0, 1, 2});
    
    r->addIndex<3>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lmul"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("llt");
  if (r == 0) db->addStruct("llt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("llt");
      std::vector<u16> ord166({2, 1, 0});
    
    r->addIndex<3>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord167({0, 1, 2});
    
    r->addIndex<3>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("llt"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lle");
  if (r == 0) db->addStruct("lle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lle");
      std::vector<u16> ord168({1, 2, 0});
    
    r->addIndex<3>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord169({0, 1, 2});
    
    r->addIndex<3>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lle"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lite");
  if (r == 0) db->addStruct("lite", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lite");
      std::vector<u16> ord170({1, 2, 3, 0});
    
    r->addIndex<4>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord171({0, 1, 2, 3});
    
    r->addIndex<4>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("lite"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("limplies");
  if (r == 0) db->addStruct("limplies", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("limplies");
      std::vector<u16> ord172({1, 2, 0});
    
    r->addIndex<3>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord173({0, 1, 2});
    
    r->addIndex<3>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("limplies"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lgt");
  if (r == 0) db->addStruct("lgt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lgt");
      std::vector<u16> ord174({2, 1, 0});
    
    r->addIndex<3>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord175({0, 1, 2});
    
    r->addIndex<3>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lgt"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lge");
  if (r == 0) db->addStruct("lge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lge");
      std::vector<u16> ord176({1, 2, 0});
    
    r->addIndex<3>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord177({0, 1, 2});
    
    r->addIndex<3>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lge"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("leq");
  if (r == 0) db->addStruct("leq", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leq");
      std::vector<u16> ord178({1, 2, 0});
    
    r->addIndex<3>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord179({0, 1, 2});
    
    r->addIndex<3>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("leq"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lany");
  if (r == 0) db->addStruct("lany", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lany");
      std::vector<u16> ord180({1, 0});
    
    r->addIndex<2>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord181({0, 1});
    
    r->addIndex<2>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lany"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("land");
  if (r == 0) db->addStruct("land", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("land");
      std::vector<u16> ord182({1, 2, 0});
    
    r->addIndex<3>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord183({0, 1, 2});
    
    r->addIndex<3>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("land"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lall");
  if (r == 0) db->addStruct("lall", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lall");
      std::vector<u16> ord184({1, 0});
    
    r->addIndex<2>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord185({0, 1});
    
    r->addIndex<2>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lall"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ladd");
  if (r == 0) db->addStruct("ladd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ladd");
      std::vector<u16> ord186({1, 2, 0});
    
    r->addIndex<3>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord187({0, 1, 2});
    
    r->addIndex<3>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ladd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("iv");
  if (r == 0) db->addStruct("iv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("iv");
      std::vector<u16> ord188({1, 0});
    
    r->addIndex<2>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord189({0, 1});
    
    r->addIndex<2>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("iv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord190({1, 2, 3, 0});
    
    r->addIndex<4>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord191({0, 1, 2, 3});
    
    r->addIndex<4>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ic");
  if (r == 0) db->addStruct("ic", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ic");
      std::vector<u16> ord192({1, 0});
    
    r->addIndex<2>(ord192, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord193({0, 1});
    
    r->addIndex<2>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord194({1, 0});
    
    r->addIndex<2>(ord194, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ic"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord195({0});
    
    r->addIndex<1>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord196({1, 2, 0});
    
    r->addIndex<3>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord197({0, 1, 2});
    
    r->addIndex<3>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bv");
  if (r == 0) db->addStruct("bv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bv");
      std::vector<u16> ord198({1, 0});
    
    r->addIndex<2>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord199({0, 1});
    
    r->addIndex<2>(ord199, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("bv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord200({1, 0});
    
    r->addIndex<2>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord201({0, 1});
    
    r->addIndex<2>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord202({1, 0});
    
    r->addIndex<2>(ord202, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst3iYZ59 constd4735e3a265e16eee03f5971) (let __tconst8YcR61 const6b86b273ff34fce19d6b804e) (let __tconst82C258 const7b46e63d74de2f1954f46ee5)) (probe ic (1 0) 1 __tconst3iYZ59 __t5xkU60) (body (exists lgt (2 1 0) 1 __t5xkU60) (join ic (1 0) 1 __tconst8YcR61 __t3Vtd62) (join lgt (2 1 0) 2 __t5xkU60 __t3Vtd62 __t79Ci63) (join smt_model (1 0) 1 __t79Ci63 __t596b64) (join smt_model_ans (0 1 2) 1 __t596b64 V M)) (head (emit probe (0 1 2) __tconst82C258 V M)) smt_model.slog:10 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lgtindex0;  slog::Index** icindex1;  slog::Index** lgtindex2;  slog::Index** smt_modelindex3;  slog::Index** smt_model_ansindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord6({0, 1, 2});
      slog::Relation* readrel7 = db->getRelation("probe");
      head_index[0] = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({1, 0});
      slog::Relation* readrel9 = db->getRelation("ic");
      driver_index = readrel9->getIndex(ord8, true);
      std::vector<u16> ord10({2, 1, 0});
      slog::Relation* readrel11 = db->getRelation("lgt");
      lgtindex0 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("ic");
      icindex1 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({2, 1, 0});
      slog::Relation* readrel15 = db->getRelation("lgt");
      lgtindex2 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("smt_model");
      smt_modelindex3 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({0, 1, 2});
      slog::Relation* readrel19 = db->getRelation("smt_model_ans");
      smt_model_ansindex4 = readrel19->getIndex(ord18, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constd4735e3a265e16eee03f5971;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_const7b46e63d74de2f1954f46ee5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m20) {
        u64 v_c3 = m20[1];
        if (buckethash(v_c3) != bucket) return;
        if (!slog::exists_probe<3,1>(lgtindex0, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(icindex1, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m21) {
          u64 v_c4 = m21[1];
          slog::join_probe<3,2>(lgtindex2, std::array<u64,3>{v_c3, v_c4, 0}, [&](const std::array<u64,3>& m22) {
            u64 v_c5 = m22[2];
            slog::join_probe<2,1>(smt_modelindex3, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m23) {
              u64 v_c6 = m23[1];
              slog::join_probe<3,1>(smt_model_ansindex4, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m24) {
                u64 v_c7 = m24[1]; u64 v_c8 = m24[2];
                ++_fires;
                slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c2, v_c7, v_c8}, std::array<u16,3>{0, 1, 2});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_model.slog:10", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask5* _cont = new ReadTask5(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), true);
  // (crule (pre (let __tconst1J3q83 consteb8bf0d80db323992f6b634a)) (probe _enum (1 0) 1 __tconst1J3q83 __t3Org22) (body (join smt_check_ans (1 0) 1 __t3Org22 __t3t5x23) (join smt_check (0 1) 1 __t3t5x23 F)) (head (emit smt_unknown (0) F)) smt.slog:79 #f)
  class ReadTask27 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex25;  slog::Index** smt_checkindex26;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_unknown");
      std::vector<u16> ord28({0});
      slog::Relation* readrel29 = db->getRelation("smt_unknown");
      head_index[0] = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 0});
      slog::Relation* readrel31 = db->getRelation("_enum");
      driver_index = readrel31->getIndex(ord30, true);
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("smt_check_ans");
      smt_check_ansindex25 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("smt_check");
      smt_checkindex26 = readrel35->getIndex(ord34, false);
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_consteb8bf0d80db323992f6b634a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c9, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m36) {
        u64 v_c10 = m36[1];
        if (buckethash(v_c10) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex25, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m37) {
          u64 v_c11 = m37[1];
          slog::join_probe<2,1>(smt_checkindex26, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m38) {
            u64 v_c12 = m38[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:79", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask27* _cont = new ReadTask27(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask27(db,b), true);
  // (crule (pre (let __tconst2GJl47 const4e07408562bedb8b60ce05c1) (let __tconst9YNT49 constba2df4903a2c14e86dc3bcca) (let __tconst9Bto46 const387ccbac691f72049eabce09)) (probe ic (1 0) 1 __tconst2GJl47 __t7HKY48) (body (exists llt (2 1 0) 1 __t7HKY48) (join iv (1 0) 1 __tconst9YNT49 __t7qnp50) (join llt (2 1 0) 2 __t7HKY48 __t7qnp50 __t3baK51) (join smt_model (1 0) 1 __t3baK51 __t8ZuP52) (join smt_model_ans (0 1 2) 1 __t8ZuP52 V M)) (head (emit probe (0 1 2) __tconst9Bto46 V M)) smt_model.slog:11 #f)
  class ReadTask44 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex39;  slog::Index** ivindex40;  slog::Index** lltindex41;  slog::Index** smt_modelindex42;  slog::Index** smt_model_ansindex43;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord45({0, 1, 2});
      slog::Relation* readrel46 = db->getRelation("probe");
      head_index[0] = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 0});
      slog::Relation* readrel48 = db->getRelation("ic");
      driver_index = readrel48->getIndex(ord47, true);
      std::vector<u16> ord49({2, 1, 0});
      slog::Relation* readrel50 = db->getRelation("llt");
      lltindex39 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 0});
      slog::Relation* readrel52 = db->getRelation("iv");
      ivindex40 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({2, 1, 0});
      slog::Relation* readrel54 = db->getRelation("llt");
      lltindex41 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 0});
      slog::Relation* readrel56 = db->getRelation("smt_model");
      smt_modelindex42 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1, 2});
      slog::Relation* readrel58 = db->getRelation("smt_model_ans");
      smt_model_ansindex43 = readrel58->getIndex(ord57, false);
  
    }
    ReadTask44(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c14 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c15 = v_const387ccbac691f72049eabce09;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c13, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m59) {
        u64 v_c16 = m59[1];
        if (buckethash(v_c16) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex39, std::array<u64,3>{v_c16, 0, 0})) return;
        slog::join_probe<2,1>(ivindex40, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m60) {
          u64 v_c17 = m60[1];
          slog::join_probe<3,2>(lltindex41, std::array<u64,3>{v_c16, v_c17, 0}, [&](const std::array<u64,3>& m61) {
            u64 v_c18 = m61[2];
            slog::join_probe<2,1>(smt_modelindex42, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m62) {
              u64 v_c19 = m62[1];
              slog::join_probe<3,1>(smt_model_ansindex43, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m63) {
                u64 v_c7 = m63[1]; u64 v_c8 = m63[2];
                ++_fires;
                slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c15, v_c7, v_c8}, std::array<u16,3>{0, 1, 2});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_model.slog:11", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask44* _cont = new ReadTask44(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask44(db,b), true);
  // (crule (pre (let __tconst7o4278 constab76c7d069d6f33dc950fb33)) (probe _enum (1 0) 1 __tconst7o4278 __t5EM619) (body (join smt_check_ans (1 0) 1 __t5EM619 __t35KE20) (join smt_check (0 1) 1 __t35KE20 F)) (head (emit smt_sat (0) F)) smt.slog:77 #f)
  class ReadTask66 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex64;  slog::Index** smt_checkindex65;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_sat");
      std::vector<u16> ord67({0});
      slog::Relation* readrel68 = db->getRelation("smt_sat");
      head_index[0] = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 0});
      slog::Relation* readrel70 = db->getRelation("_enum");
      driver_index = readrel70->getIndex(ord69, true);
      std::vector<u16> ord71({1, 0});
      slog::Relation* readrel72 = db->getRelation("smt_check_ans");
      smt_check_ansindex64 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("smt_check");
      smt_checkindex65 = readrel74->getIndex(ord73, false);
  
    }
    ReadTask66(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_constab76c7d069d6f33dc950fb33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c20, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m75) {
        u64 v_c21 = m75[1];
        if (buckethash(v_c21) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex64, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m76) {
          u64 v_c22 = m76[1];
          slog::join_probe<2,1>(smt_checkindex65, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m77) {
            u64 v_c12 = m77[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:77", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask66* _cont = new ReadTask66(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask66(db,b), true);
  // (crule (pre (let __tconst38xx13 constd4735e3a265e16eee03f5971) (let __tconst1e1S15 const6b86b273ff34fce19d6b804e) (let __tconst1TmJ12 const744f9b8e5b636a30ad112686)) (probe ic (1 0) 1 __tconst38xx13 __t8xhA14) (body (exists llt (2 1 0) 1 __t8xhA14) (join ic (1 0) 1 __tconst1e1S15 __t2S7L16) (join llt (2 1 0) 2 __t8xhA14 __t2S7L16 __t33n417) (join smt_model (1 0) 1 __t33n417 __t8rR618) (join smt_model_ans (0 1 2) 1 __t8rR618 V M)) (head (emit probe (0 1 2) __tconst1TmJ12 V M)) smt_model.slog:9 #f)
  class ReadTask83 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex78;  slog::Index** icindex79;  slog::Index** lltindex80;  slog::Index** smt_modelindex81;  slog::Index** smt_model_ansindex82;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord84({0, 1, 2});
      slog::Relation* readrel85 = db->getRelation("probe");
      head_index[0] = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 0});
      slog::Relation* readrel87 = db->getRelation("ic");
      driver_index = readrel87->getIndex(ord86, true);
      std::vector<u16> ord88({2, 1, 0});
      slog::Relation* readrel89 = db->getRelation("llt");
      lltindex78 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 0});
      slog::Relation* readrel91 = db->getRelation("ic");
      icindex79 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({2, 1, 0});
      slog::Relation* readrel93 = db->getRelation("llt");
      lltindex80 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0});
      slog::Relation* readrel95 = db->getRelation("smt_model");
      smt_modelindex81 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({0, 1, 2});
      slog::Relation* readrel97 = db->getRelation("smt_model_ans");
      smt_model_ansindex82 = readrel97->getIndex(ord96, false);
  
    }
    ReadTask83(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_constd4735e3a265e16eee03f5971;
      u64 v_c24 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c25 = v_const744f9b8e5b636a30ad112686;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c23, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m98) {
        u64 v_c26 = m98[1];
        if (buckethash(v_c26) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex78, std::array<u64,3>{v_c26, 0, 0})) return;
        slog::join_probe<2,1>(icindex79, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m99) {
          u64 v_c27 = m99[1];
          slog::join_probe<3,2>(lltindex80, std::array<u64,3>{v_c26, v_c27, 0}, [&](const std::array<u64,3>& m100) {
            u64 v_c28 = m100[2];
            slog::join_probe<2,1>(smt_modelindex81, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m101) {
              u64 v_c29 = m101[1];
              slog::join_probe<3,1>(smt_model_ansindex82, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m102) {
                u64 v_c7 = m102[1]; u64 v_c8 = m102[2];
                ++_fires;
                slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c25, v_c7, v_c8}, std::array<u16,3>{0, 1, 2});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_model.slog:9", "all:ic", _fires);
  
      if (!_done)
      {
        ReadTask83* _cont = new ReadTask83(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask83(db,b), true);
  // (crule (pre (let __tconst4CZX82 consta221beeaebe583607e193be7)) (probe _enum (1 0) 1 __tconst4CZX82 __t7wLc44) (body (join smt_check_ans (1 0) 1 __t7wLc44 __t0Mkv45) (join smt_check (0 1) 1 __t0Mkv45 F)) (head (emit smt_unsat (0) F)) smt.slog:78 #f)
  class ReadTask105 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex103;  slog::Index** smt_checkindex104;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_unsat");
      std::vector<u16> ord106({0});
      slog::Relation* readrel107 = db->getRelation("smt_unsat");
      head_index[0] = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 0});
      slog::Relation* readrel109 = db->getRelation("_enum");
      driver_index = readrel109->getIndex(ord108, true);
      std::vector<u16> ord110({1, 0});
      slog::Relation* readrel111 = db->getRelation("smt_check_ans");
      smt_check_ansindex103 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({0, 1});
      slog::Relation* readrel113 = db->getRelation("smt_check");
      smt_checkindex104 = readrel113->getIndex(ord112, false);
  
    }
    ReadTask105(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_consta221beeaebe583607e193be7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c30, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m114) {
        u64 v_c31 = m114[1];
        if (buckethash(v_c31) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex103, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m115) {
          u64 v_c32 = m115[1];
          slog::join_probe<2,1>(smt_checkindex104, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m116) {
            u64 v_c12 = m116[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:78", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask105* _cont = new ReadTask105(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask105(db,b), true);
  s->addReadRel("_enum");
  s->addReadRel("ic");
  s->addReadRel("iv");
  s->addReadRel("lgt");
  s->addReadRel("llt");
  s->addReadRel("smt_check");
  s->addReadRel("smt_check_ans");
  s->addReadRel("smt_model");
  s->addReadRel("smt_model_ans");
  s->addDynamicRel("probe");
  s->addDynamicRel("smt_sat");
  s->addDynamicRel("smt_unknown");
  s->addDynamicRel("smt_unsat");
  d->push(s);
  d->continueRun();
}

