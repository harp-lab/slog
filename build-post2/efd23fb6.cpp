
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_constfa94099f784d91500e1b95df;
u64 v_const7b4b6d235bc6fbc8c9ba5801;
u64 v_const356829ca6c3df0a0d1117410;
u64 v_constd2c28e4f541b3051f713f2a3;
u64 v_consta221beeaebe583607e193be7;
u64 v_constab76c7d069d6f33dc950fb33;
u64 v_consteb8bf0d80db323992f6b634a;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constbf14e8e2740173c2e99e36a3;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("efd23fb6");
  if (s == nullptr) return;
  slog::Relation* r;
  v_constfa94099f784d91500e1b95df = db->encodeString("@status");
  v_const7b4b6d235bc6fbc8c9ba5801 = db->encodeString("smt_model_ans");
  v_const356829ca6c3df0a0d1117410 = db->encodeString("smt_core_ans");
  v_constd2c28e4f541b3051f713f2a3 = db->encodeString("smt.slog:106");
  v_consta221beeaebe583607e193be7 = db->encodeString("unsat");
  v_constab76c7d069d6f33dc950fb33 = db->encodeString("sat");
  v_consteb8bf0d80db323992f6b634a = db->encodeString("unknown");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constbf14e8e2740173c2e99e36a3 = db->encodeString("smt.slog:93");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord101({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord102({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord103({1, 2, 0});
    
    r->addIndex<3>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord104({0, 1, 2});
    
    r->addIndex<3>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_vcode");
  if (r == 0) db->addRelation("smt_vcode", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_vcode");
      std::vector<u16> ord105({0, 1});
    
    r->addIndex<2>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_vcode"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_unsat");
  if (r == 0) db->addRelation("smt_unsat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unsat");
      std::vector<u16> ord106({0});
    
    r->addIndex<1>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unsat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_unknown");
  if (r == 0) db->addRelation("smt_unknown", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unknown");
      std::vector<u16> ord107({0});
    
    r->addIndex<1>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unknown"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_sat");
  if (r == 0) db->addRelation("smt_sat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_sat");
      std::vector<u16> ord108({0});
    
    r->addIndex<1>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_sat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_qsat_ans");
  if (r == 0) db->addRelation("smt_qsat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord109({0, 1});
    
    r->addIndex<2>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qsat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qsat");
  if (r == 0) db->addStruct("smt_qsat", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat");
      std::vector<u16> ord110({1, 0});
    
    r->addIndex<2>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord111({0, 1});
    
    r->addIndex<2>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qsat"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qmodel_ans");
  if (r == 0) db->addRelation("smt_qmodel_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel_ans");
      std::vector<u16> ord112({0, 1});
    
    r->addIndex<2>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qmodel_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qmodel");
  if (r == 0) db->addStruct("smt_qmodel", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel");
      std::vector<u16> ord113({1, 0});
    
    r->addIndex<2>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord114({0, 1});
    
    r->addIndex<2>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qmodel"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qcore_ans");
  if (r == 0) db->addRelation("smt_qcore_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore_ans");
      std::vector<u16> ord115({0, 1});
    
    r->addIndex<2>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qcore_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qcore");
  if (r == 0) db->addStruct("smt_qcore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore");
      std::vector<u16> ord116({1, 0});
    
    r->addIndex<2>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord117({0, 1});
    
    r->addIndex<2>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qcore"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_model_ans");
  if (r == 0) db->addRelation("smt_model_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model_ans");
      std::vector<u16> ord118({0, 1, 2});
    
    r->addIndex<3>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_model_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_model");
  if (r == 0) db->addStruct("smt_model", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model");
      std::vector<u16> ord119({1, 0});
    
    r->addIndex<2>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord120({0, 1});
    
    r->addIndex<2>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_model"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_core_ans");
  if (r == 0) db->addRelation("smt_core_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core_ans");
      std::vector<u16> ord121({0, 1, 2});
    
    r->addIndex<3>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_core_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_core");
  if (r == 0) db->addStruct("smt_core", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core");
      std::vector<u16> ord122({1, 0});
    
    r->addIndex<2>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord123({0, 1});
    
    r->addIndex<2>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_core"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check_ans");
  if (r == 0) db->addRelation("smt_check_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check_ans");
      std::vector<u16> ord124({1, 0});
    
    r->addIndex<2>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_check_ans"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check");
  if (r == 0) db->addStruct("smt_check", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check");
      std::vector<u16> ord125({1, 0});
    
    r->addIndex<2>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord126({0, 1});
    
    r->addIndex<2>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_check"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord127({1, 2, 0});
    
    r->addIndex<3>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord128({0, 1, 2});
    
    r->addIndex<3>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord129({1, 2, 3, 0});
    
    r->addIndex<4>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord130({0, 1, 2, 3});
    
    r->addIndex<4>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord131({1, 2, 0});
    
    r->addIndex<3>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord132({0, 1, 2});
    
    r->addIndex<3>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord133({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord134({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord135({1, 2, 0});
    
    r->addIndex<3>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord136({0, 1, 2});
    
    r->addIndex<3>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord137({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord138({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lsub");
  if (r == 0) db->addStruct("lsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lsub");
      std::vector<u16> ord139({1, 2, 0});
    
    r->addIndex<3>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord140({0, 1, 2});
    
    r->addIndex<3>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lsub"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lor");
  if (r == 0) db->addStruct("lor", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lor");
      std::vector<u16> ord141({1, 2, 0});
    
    r->addIndex<3>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord142({0, 1, 2});
    
    r->addIndex<3>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lor"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lnot");
  if (r == 0) db->addStruct("lnot", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lnot");
      std::vector<u16> ord143({1, 0});
    
    r->addIndex<2>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord144({0, 1});
    
    r->addIndex<2>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lnot"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lne");
  if (r == 0) db->addStruct("lne", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lne");
      std::vector<u16> ord145({1, 2, 0});
    
    r->addIndex<3>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord146({0, 1, 2});
    
    r->addIndex<3>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lne"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lmul");
  if (r == 0) db->addStruct("lmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lmul");
      std::vector<u16> ord147({1, 2, 0});
    
    r->addIndex<3>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord148({0, 1, 2});
    
    r->addIndex<3>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lmul"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("llt");
  if (r == 0) db->addStruct("llt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("llt");
      std::vector<u16> ord149({1, 2, 0});
    
    r->addIndex<3>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord150({0, 1, 2});
    
    r->addIndex<3>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("llt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lle");
  if (r == 0) db->addStruct("lle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lle");
      std::vector<u16> ord151({1, 2, 0});
    
    r->addIndex<3>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord152({0, 1, 2});
    
    r->addIndex<3>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lle"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lite");
  if (r == 0) db->addStruct("lite", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lite");
      std::vector<u16> ord153({1, 2, 3, 0});
    
    r->addIndex<4>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord154({0, 1, 2, 3});
    
    r->addIndex<4>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("lite"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("limplies");
  if (r == 0) db->addStruct("limplies", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("limplies");
      std::vector<u16> ord155({1, 2, 0});
    
    r->addIndex<3>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord156({0, 1, 2});
    
    r->addIndex<3>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("limplies"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lgt");
  if (r == 0) db->addStruct("lgt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lgt");
      std::vector<u16> ord157({1, 2, 0});
    
    r->addIndex<3>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord158({0, 1, 2});
    
    r->addIndex<3>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lgt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lge");
  if (r == 0) db->addStruct("lge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lge");
      std::vector<u16> ord159({1, 2, 0});
    
    r->addIndex<3>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord160({0, 1, 2});
    
    r->addIndex<3>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lge"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("leq");
  if (r == 0) db->addStruct("leq", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leq");
      std::vector<u16> ord161({1, 2, 0});
    
    r->addIndex<3>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord162({0, 1, 2});
    
    r->addIndex<3>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("leq"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lany");
  if (r == 0) db->addStruct("lany", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lany");
      std::vector<u16> ord163({1, 0});
    
    r->addIndex<2>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord164({0, 1});
    
    r->addIndex<2>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lany"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("land");
  if (r == 0) db->addStruct("land", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("land");
      std::vector<u16> ord165({1, 2, 0});
    
    r->addIndex<3>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord166({0, 1, 2});
    
    r->addIndex<3>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("land"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lall");
  if (r == 0) db->addStruct("lall", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lall");
      std::vector<u16> ord167({1, 0});
    
    r->addIndex<2>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord168({0, 1});
    
    r->addIndex<2>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lall"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ladd");
  if (r == 0) db->addStruct("ladd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ladd");
      std::vector<u16> ord169({1, 2, 0});
    
    r->addIndex<3>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord170({0, 1, 2});
    
    r->addIndex<3>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ladd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("iv");
  if (r == 0) db->addStruct("iv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("iv");
      std::vector<u16> ord171({1, 0});
    
    r->addIndex<2>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord172({0, 1});
    
    r->addIndex<2>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("iv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord173({1, 2, 3, 0});
    
    r->addIndex<4>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord174({0, 1, 2, 3});
    
    r->addIndex<4>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ic");
  if (r == 0) db->addStruct("ic", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ic");
      std::vector<u16> ord175({1, 0});
    
    r->addIndex<2>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord176({0, 1});
    
    r->addIndex<2>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ic"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord177({0});
    
    r->addIndex<1>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord178({1, 2, 0});
    
    r->addIndex<3>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord179({0, 1, 2});
    
    r->addIndex<3>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("count");
  if (r == 0) db->addRelation("count", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("count");
      std::vector<u16> ord180({0});
    
    r->addIndex<1>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("count"), std::array<u16,1>{0}, b));
  r = db->getRelation("bv");
  if (r == 0) db->addStruct("bv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bv");
      std::vector<u16> ord181({1, 0});
    
    r->addIndex<2>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord182({0, 1});
    
    r->addIndex<2>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("bv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord183({1, 0});
    
    r->addIndex<2>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord184({0, 1});
    
    r->addIndex<2>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord185({1, 0});
    
    r->addIndex<2>(ord185, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst83RZ48 consta221beeaebe583607e193be7)) (probe _enum (1 0) 1 __tconst83RZ48 __t0mLG41) (body (join smt_check_ans (1 0) 1 __t0mLG41 __t2VqO42) (join smt_check (0 1) 1 __t2VqO42 F)) (head (emit smt_unsat (0) F)) smt.slog:78 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex0;  slog::Index** smt_checkindex1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_unsat");
      std::vector<u16> ord3({0});
      slog::Relation* readrel4 = db->getRelation("smt_unsat");
      head_index[0] = readrel4->getIndex(ord3, false);
      std::vector<u16> ord5({1, 0});
      slog::Relation* readrel6 = db->getRelation("_enum");
      driver_index = readrel6->getIndex(ord5, true);
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("smt_check_ans");
      smt_check_ansindex0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({0, 1});
      slog::Relation* readrel10 = db->getRelation("smt_check");
      smt_checkindex1 = readrel10->getIndex(ord9, false);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_consta221beeaebe583607e193be7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m11) {
        u64 v_c1 = m11[1];
        if (buckethash(v_c1) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m12) {
          u64 v_c2 = m12[1];
          slog::join_probe<2,1>(smt_checkindex1, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m13) {
            u64 v_c3 = m13[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:78", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask2* _cont = new ReadTask2(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2(db,b), true);
  // (crule (pre (let __tconst1Z9c57 consteb8bf0d80db323992f6b634a)) (probe _enum (1 0) 1 __tconst1Z9c57 __t0EW92) (body (join smt_check_ans (1 0) 1 __t0EW92 __t1pq73) (join smt_check (0 1) 1 __t1pq73 F)) (head (emit smt_unknown (0) F)) smt.slog:79 #f)
  class ReadTask16 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex14;  slog::Index** smt_checkindex15;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_unknown");
      std::vector<u16> ord17({0});
      slog::Relation* readrel18 = db->getRelation("smt_unknown");
      head_index[0] = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("_enum");
      driver_index = readrel20->getIndex(ord19, true);
      std::vector<u16> ord21({1, 0});
      slog::Relation* readrel22 = db->getRelation("smt_check_ans");
      smt_check_ansindex14 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({0, 1});
      slog::Relation* readrel24 = db->getRelation("smt_check");
      smt_checkindex15 = readrel24->getIndex(ord23, false);
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_consteb8bf0d80db323992f6b634a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c4, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m25) {
        u64 v_c5 = m25[1];
        if (buckethash(v_c5) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex14, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m26) {
          u64 v_c6 = m26[1];
          slog::join_probe<2,1>(smt_checkindex15, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m27) {
            u64 v_c3 = m27[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:79", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask16* _cont = new ReadTask16(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask16(db,b), true);
  // (crule (pre) (scan malformed_deduction __erre8zI5171 __errf7RPw172 __errf8ugj173 __errf08Io174 __errf5BUV175) (body) (head (emit error (0) __erre8zI5171)) <internal>:1 #f)
  class ReadTask28 : public slog::Task
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
      std::vector<u16> ord29({0});
      slog::Relation* readrel30 = db->getRelation("error");
      head_index[0] = readrel30->getIndex(ord29, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask28* _cont = new ReadTask28(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask28(db,b), false);
  // (crule (pre) (scan type_mismatch __erre4YDK193 __errf0xLM194 __errf0MdP195 __errf5rGV196 __errf1EJM197) (body) (head (emit error (0) __erre4YDK193)) <internal>:1 #f)
  class ReadTask31 : public slog::Task
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
      std::vector<u16> ord32({0});
      slog::Relation* readrel33 = db->getRelation("error");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask31(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c16 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask31* _cont = new ReadTask31(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask31(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre0Wn1203 __errf4pDL204 __errf6unP205) (body) (head (emit error (0) __erre0Wn1203)) <internal>:1 #f)
  class ReadTask34 : public slog::Task
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
      std::vector<u16> ord35({0});
      slog::Relation* readrel36 = db->getRelation("error");
      head_index[0] = readrel36->getIndex(ord35, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
        u64 v_c17 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c19 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c17}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre552z182 __errf70Rd183 __errf5GQP184 __errf8fIR185) (body) (head (emit error (0) __erre552z182)) <internal>:1 #f)
  class ReadTask37 : public slog::Task
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
      std::vector<u16> ord38({0});
      slog::Relation* readrel39 = db->getRelation("error");
      head_index[0] = readrel39->getIndex(ord38, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask37(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c23 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c20}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask37* _cont = new ReadTask37(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask37(db,b), false);
  // (crule (pre) (scan nan_result __erre9pUY186 __errf1TSE187 __errf7ySD188 __errf3DJs189) (body) (head (emit error (0) __erre9pUY186)) <internal>:1 #f)
  class ReadTask40 : public slog::Task
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
      std::vector<u16> ord41({0});
      slog::Relation* readrel42 = db->getRelation("error");
      head_index[0] = readrel42->getIndex(ord41, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask40(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c27 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask40* _cont = new ReadTask40(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask40(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre5Nm0198 __errf5eV9199 __errf8Kab200 __errf6k3y201 __errf9o9Y202) (body) (head (emit error (0) __erre5Nm0198)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c28 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c30 = _t[2];
        u64 v_c31 = _t[3];
        u64 v_c32 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c28}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre (let __tconst2XwF58 constab76c7d069d6f33dc950fb33)) (probe _enum (1 0) 1 __tconst2XwF58 __t2IQd19) (body (join smt_check_ans (1 0) 1 __t2IQd19 __t9Hf120) (join smt_check (0 1) 1 __t9Hf120 F)) (head (emit smt_sat (0) F)) smt.slog:77 #f)
  class ReadTask48 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** smt_check_ansindex46;  slog::Index** smt_checkindex47;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_sat");
      std::vector<u16> ord49({0});
      slog::Relation* readrel50 = db->getRelation("smt_sat");
      head_index[0] = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 0});
      slog::Relation* readrel52 = db->getRelation("_enum");
      driver_index = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({1, 0});
      slog::Relation* readrel54 = db->getRelation("smt_check_ans");
      smt_check_ansindex46 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("smt_check");
      smt_checkindex47 = readrel56->getIndex(ord55, false);
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_constab76c7d069d6f33dc950fb33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c33, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m57) {
        u64 v_c34 = m57[1];
        if (buckethash(v_c34) != bucket) return;
        slog::join_probe<2,1>(smt_check_ansindex46, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m58) {
          u64 v_c35 = m58[1];
          slog::join_probe<2,1>(smt_checkindex47, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m59) {
            u64 v_c3 = m59[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:77", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask48* _cont = new ReadTask48(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask48(db,b), true);
  // (crule (pre) (scan modulo_by_zero __erre6Exk179 __errf32zx180 __errf7HEM181) (body) (head (emit error (0) __erre6Exk179)) <internal>:1 #f)
  class ReadTask60 : public slog::Task
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
      std::vector<u16> ord61({0});
      slog::Relation* readrel62 = db->getRelation("error");
      head_index[0] = readrel62->getIndex(ord61, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask60(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c38 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c36}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask60* _cont = new ReadTask60(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask60(db,b), false);
  // (crule (pre (let __tconst2nUt24 constfa94099f784d91500e1b95df) (let __trid4J6q59 constbf14e8e2740173c2e99e36a3) (let __trel9Wzh60 const7b4b6d235bc6fbc8c9ba5801) (let __tcol3Orj61 constd4735e3a265e16eee03f5971)) (scan smt_vcode __t4W0d23 V) (body (join smt_qmodel_ans (0 1) 0 __t55fQ26 M0) (join smt_qmodel (0 1) 1 __t55fQ26 F) (join smt_model (1 0) 1 F __t74fx21) (letp chk5pjw206 (cget M0 __tconst2nUt24)) (eq __t4W0d23 chk5pjw206) (let __t6xs025 (cdel M0 __tconst2nUt24))) (head (tycheck __t6xs025 (accept cnode) __trid4J6q59 __trel9Wzh60 __tcol3Orj61 (1 2 3 4 0)) (emit smt_model_ans (0 1 2) __t74fx21 V __t6xs025)) smt.slog:93 #f)
  class ReadTask66 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_qmodel_ansindex63;  slog::Index** smt_qmodelindex64;  slog::Index** smt_modelindex65;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("smt_model_ans");
      std::vector<u16> ord67({0, 1, 2});
      slog::Relation* readrel68 = db->getRelation("smt_model_ans");
      head_index[1] = readrel68->getIndex(ord67, false);
      outer_rel = db->getRelation("smt_vcode");
      std::vector<u16> ord69({0, 1});
      slog::Relation* readrel70 = db->getRelation("smt_qmodel_ans");
      smt_qmodel_ansindex63 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({0, 1});
      slog::Relation* readrel72 = db->getRelation("smt_qmodel");
      smt_qmodelindex64 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 0});
      slog::Relation* readrel74 = db->getRelation("smt_model");
      smt_modelindex65 = readrel74->getIndex(ord73, false);
  
    }
    ReadTask66(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_constfa94099f784d91500e1b95df;
      u64 v_c40 = v_constbf14e8e2740173c2e99e36a3;
      u64 v_c41 = v_const7b4b6d235bc6fbc8c9ba5801;
      u64 v_c42 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c43 = _t[0];
        u64 v_c44 = _t[1];
        slog::join_all<2>(smt_qmodel_ansindex63, [&](const std::array<u64,2>& m75) {
          u64 v_c45 = m75[0]; u64 v_c46 = m75[1];
          slog::join_probe<2,1>(smt_qmodelindex64, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m76) {
            u64 v_c3 = m76[1];
            slog::join_probe<2,1>(smt_modelindex65, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m77) {
              u64 v_c47 = m77[1];
              bool ok78 = true;
              u64 v_c48 = _prim_cget(db, v_c46, v_c39, &ok78);
              if (!ok78) return;
              if (v_c43 != v_c48) return;
              u64 v_c49 = _prim_cdel(db, v_c46, v_c39);
              if (v_c49 == slog_error) { slog::emit_pending_error(db, "smt.slog:93"); return; }
              ++_fires;
              if (!(is_cnode(v_c49)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c40, v_c41, v_c42, v_c49}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c47, v_c44, v_c49}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt.slog:93", "all:smt_vcode", _fires);
  
      if (!_done)
      {
        ReadTask66* _cont = new ReadTask66(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask66(db,b), true);
  // (crule (pre (let __tconst0e5N16 constfa94099f784d91500e1b95df) (let __trid9YHr53 constd2c28e4f541b3051f713f2a3) (let __trel4jq154 const356829ca6c3df0a0d1117410) (let __tcol2tfy55 constd4735e3a265e16eee03f5971)) (scan smt_vcode __t6c6S15 V) (body (join smt_qcore_ans (0 1) 0 __t9G6o18 M0) (join smt_qcore (0 1) 1 __t9G6o18 F) (join smt_core (1 0) 1 F __t0C1R13) (letp chk07Vj207 (cget M0 __tconst0e5N16)) (eq __t6c6S15 chk07Vj207) (let __t2fRz17 (cdel M0 __tconst0e5N16))) (head (tycheck __t2fRz17 (accept cnode) __trid9YHr53 __trel4jq154 __tcol2tfy55 (1 2 3 4 0)) (emit smt_core_ans (0 1 2) __t0C1R13 V __t2fRz17)) smt.slog:106 #f)
  class ReadTask82 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_qcore_ansindex79;  slog::Index** smt_qcoreindex80;  slog::Index** smt_coreindex81;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("smt_core_ans");
      std::vector<u16> ord83({0, 1, 2});
      slog::Relation* readrel84 = db->getRelation("smt_core_ans");
      head_index[1] = readrel84->getIndex(ord83, false);
      outer_rel = db->getRelation("smt_vcode");
      std::vector<u16> ord85({0, 1});
      slog::Relation* readrel86 = db->getRelation("smt_qcore_ans");
      smt_qcore_ansindex79 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("smt_qcore");
      smt_qcoreindex80 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 0});
      slog::Relation* readrel90 = db->getRelation("smt_core");
      smt_coreindex81 = readrel90->getIndex(ord89, false);
  
    }
    ReadTask82(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c50 = v_constfa94099f784d91500e1b95df;
      u64 v_c51 = v_constd2c28e4f541b3051f713f2a3;
      u64 v_c52 = v_const356829ca6c3df0a0d1117410;
      u64 v_c53 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c54 = _t[0];
        u64 v_c44 = _t[1];
        slog::join_all<2>(smt_qcore_ansindex79, [&](const std::array<u64,2>& m91) {
          u64 v_c55 = m91[0]; u64 v_c46 = m91[1];
          slog::join_probe<2,1>(smt_qcoreindex80, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m92) {
            u64 v_c3 = m92[1];
            slog::join_probe<2,1>(smt_coreindex81, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m93) {
              u64 v_c56 = m93[1];
              bool ok94 = true;
              u64 v_c57 = _prim_cget(db, v_c46, v_c50, &ok94);
              if (!ok94) return;
              if (v_c54 != v_c57) return;
              u64 v_c58 = _prim_cdel(db, v_c46, v_c50);
              if (v_c58 == slog_error) { slog::emit_pending_error(db, "smt.slog:106"); return; }
              ++_fires;
              if (!(is_cnode(v_c58)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c51, v_c52, v_c53, v_c58}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c56, v_c44, v_c58}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt.slog:106", "all:smt_vcode", _fires);
  
      if (!_done)
      {
        ReadTask82* _cont = new ReadTask82(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask82(db,b), true);
  // (crule (pre) (scan div_by_zero __erre6Ygv176 __errf6pjA177 __errf43C5178) (body) (head (emit error (0) __erre6Ygv176)) <internal>:1 #f)
  class ReadTask95 : public slog::Task
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
      std::vector<u16> ord96({0});
      slog::Relation* readrel97 = db->getRelation("error");
      head_index[0] = readrel97->getIndex(ord96, false);
      outer_rel = db->getRelation("div_by_zero");
  
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
        u64 v_c59 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c61 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c59}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre) (scan toint_range __erre4x0o190 __errf32tc191 __errf2BhV192) (body) (head (emit error (0) __erre4x0o190)) <internal>:1 #f)
  class ReadTask98 : public slog::Task
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
      std::vector<u16> ord99({0});
      slog::Relation* readrel100 = db->getRelation("error");
      head_index[0] = readrel100->getIndex(ord99, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask98(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c62}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask98* _cont = new ReadTask98(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask98(db,b), false);
  s->addReadRel("_enum");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("smt_check");
  s->addReadRel("smt_check_ans");
  s->addReadRel("smt_core");
  s->addReadRel("smt_model");
  s->addReadRel("smt_qcore");
  s->addReadRel("smt_qcore_ans");
  s->addReadRel("smt_qmodel");
  s->addReadRel("smt_qmodel_ans");
  s->addReadRel("smt_vcode");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("smt_core_ans");
  s->addDynamicRel("smt_model_ans");
  s->addDynamicRel("smt_sat");
  s->addDynamicRel("smt_unknown");
  s->addDynamicRel("smt_unsat");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

