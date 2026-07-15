
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("387bf773");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord339({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord339, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord340({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord340, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord341({1, 2, 0});
    
    r->addIndex<3>(ord341, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord342({0, 1, 2});
    
    r->addIndex<3>(ord342, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_vcode");
  if (r == 0) db->addRelation("smt_vcode", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_vcode");
      std::vector<u16> ord343({0, 1});
    
    r->addIndex<2>(ord343, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_vcode"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_unsat");
  if (r == 0) db->addRelation("smt_unsat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unsat");
      std::vector<u16> ord344({0});
    
    r->addIndex<1>(ord344, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unsat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_unknown");
  if (r == 0) db->addRelation("smt_unknown", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unknown");
      std::vector<u16> ord345({0});
    
    r->addIndex<1>(ord345, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unknown"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_sat");
  if (r == 0) db->addRelation("smt_sat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_sat");
      std::vector<u16> ord346({0});
    
    r->addIndex<1>(ord346, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_sat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_qsat_ans");
  if (r == 0) db->addRelation("smt_qsat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord347({0, 1});
    
    r->addIndex<2>(ord347, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qsat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qsat");
  if (r == 0) db->addStruct("smt_qsat", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat");
      std::vector<u16> ord348({1, 0});
    
    r->addIndex<2>(ord348, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord349({0, 1});
    
    r->addIndex<2>(ord349, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord350({0, 1});
    
    r->addIndex<2>(ord350, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord351({1, 0});
    
    r->addIndex<2>(ord351, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qsat"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qmodel_ans");
  if (r == 0) db->addRelation("smt_qmodel_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel_ans");
      std::vector<u16> ord352({0, 1});
    
    r->addIndex<2>(ord352, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qmodel_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qmodel");
  if (r == 0) db->addStruct("smt_qmodel", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel");
      std::vector<u16> ord353({1, 0});
    
    r->addIndex<2>(ord353, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord354({0, 1});
    
    r->addIndex<2>(ord354, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qmodel"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qcore_ans");
  if (r == 0) db->addRelation("smt_qcore_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore_ans");
      std::vector<u16> ord355({0, 1});
    
    r->addIndex<2>(ord355, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qcore_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qcore");
  if (r == 0) db->addStruct("smt_qcore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore");
      std::vector<u16> ord356({1, 0});
    
    r->addIndex<2>(ord356, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord357({0, 1});
    
    r->addIndex<2>(ord357, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qcore"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_model_ans");
  if (r == 0) db->addRelation("smt_model_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model_ans");
      std::vector<u16> ord358({0, 1, 2});
    
    r->addIndex<3>(ord358, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_model_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_model");
  if (r == 0) db->addStruct("smt_model", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model");
      std::vector<u16> ord359({1, 0});
    
    r->addIndex<2>(ord359, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord360({0, 1});
    
    r->addIndex<2>(ord360, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_model"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_core_ans");
  if (r == 0) db->addRelation("smt_core_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core_ans");
      std::vector<u16> ord361({0, 1, 2});
    
    r->addIndex<3>(ord361, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_core_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_core");
  if (r == 0) db->addStruct("smt_core", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core");
      std::vector<u16> ord362({1, 0});
    
    r->addIndex<2>(ord362, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord363({0, 1});
    
    r->addIndex<2>(ord363, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_core"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check_ans");
  if (r == 0) db->addRelation("smt_check_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check_ans");
      std::vector<u16> ord364({0, 1});
    
    r->addIndex<2>(ord364, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_check_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_check");
  if (r == 0) db->addStruct("smt_check", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check");
      std::vector<u16> ord365({1, 0});
    
    r->addIndex<2>(ord365, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord366({0, 1});
    
    r->addIndex<2>(ord366, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord367({0, 1});
    
    r->addIndex<2>(ord367, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord368({1, 0});
    
    r->addIndex<2>(ord368, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_check"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord369({1, 2, 0});
    
    r->addIndex<3>(ord369, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord370({0, 1, 2});
    
    r->addIndex<3>(ord370, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord371({1, 2, 3, 0});
    
    r->addIndex<4>(ord371, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord372({0, 1, 2, 3});
    
    r->addIndex<4>(ord372, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord373({1, 2, 0});
    
    r->addIndex<3>(ord373, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord374({0, 1, 2});
    
    r->addIndex<3>(ord374, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord375({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord375, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord376({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord376, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord377({1, 2, 0});
    
    r->addIndex<3>(ord377, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord378({0, 1, 2});
    
    r->addIndex<3>(ord378, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord379({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord379, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord380({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord380, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lsub");
  if (r == 0) db->addStruct("lsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lsub");
      std::vector<u16> ord381({1, 2, 0});
    
    r->addIndex<3>(ord381, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord382({0, 1, 2});
    
    r->addIndex<3>(ord382, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lsub"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lor");
  if (r == 0) db->addStruct("lor", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lor");
      std::vector<u16> ord383({1, 2, 0});
    
    r->addIndex<3>(ord383, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord384({0, 1, 2});
    
    r->addIndex<3>(ord384, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lor"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lnot");
  if (r == 0) db->addStruct("lnot", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lnot");
      std::vector<u16> ord385({1, 0});
    
    r->addIndex<2>(ord385, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord386({0, 1});
    
    r->addIndex<2>(ord386, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lnot"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lne");
  if (r == 0) db->addStruct("lne", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lne");
      std::vector<u16> ord387({1, 2, 0});
    
    r->addIndex<3>(ord387, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord388({0, 1, 2});
    
    r->addIndex<3>(ord388, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lne"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lmul");
  if (r == 0) db->addStruct("lmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lmul");
      std::vector<u16> ord389({1, 2, 0});
    
    r->addIndex<3>(ord389, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord390({0, 1, 2});
    
    r->addIndex<3>(ord390, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lmul"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("llt");
  if (r == 0) db->addStruct("llt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("llt");
      std::vector<u16> ord391({1, 2, 0});
    
    r->addIndex<3>(ord391, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord392({0, 2, 1});
    
    r->addIndex<3>(ord392, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord393({2, 0, 1});
    
    r->addIndex<3>(ord393, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord394({1, 2, 0});
    
    r->addIndex<3>(ord394, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("llt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lle");
  if (r == 0) db->addStruct("lle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lle");
      std::vector<u16> ord395({1, 2, 0});
    
    r->addIndex<3>(ord395, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord396({0, 1, 2});
    
    r->addIndex<3>(ord396, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lle"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lite");
  if (r == 0) db->addStruct("lite", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lite");
      std::vector<u16> ord397({1, 2, 3, 0});
    
    r->addIndex<4>(ord397, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord398({0, 1, 2, 3});
    
    r->addIndex<4>(ord398, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("lite"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("limplies");
  if (r == 0) db->addStruct("limplies", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("limplies");
      std::vector<u16> ord399({1, 2, 0});
    
    r->addIndex<3>(ord399, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord400({0, 1, 2});
    
    r->addIndex<3>(ord400, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("limplies"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lgt");
  if (r == 0) db->addStruct("lgt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lgt");
      std::vector<u16> ord401({1, 2, 0});
    
    r->addIndex<3>(ord401, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord402({0, 1, 2});
    
    r->addIndex<3>(ord402, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lgt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lge");
  if (r == 0) db->addStruct("lge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lge");
      std::vector<u16> ord403({1, 2, 0});
    
    r->addIndex<3>(ord403, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord404({0, 1, 2});
    
    r->addIndex<3>(ord404, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lge"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("leq");
  if (r == 0) db->addStruct("leq", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leq");
      std::vector<u16> ord405({1, 2, 0});
    
    r->addIndex<3>(ord405, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord406({0, 1, 2});
    
    r->addIndex<3>(ord406, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("leq"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("layer2");
  if (r == 0) db->addRelation("layer2", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("layer2");
      std::vector<u16> ord407({0, 1});
    
    r->addIndex<2>(ord407, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("layer2"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("layer1");
  if (r == 0) db->addRelation("layer1", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("layer1");
      std::vector<u16> ord408({0});
    
    r->addIndex<1>(ord408, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("layer1"), std::array<u16,1>{0}, b));
  r = db->getRelation("lany");
  if (r == 0) db->addStruct("lany", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lany");
      std::vector<u16> ord409({1, 0});
    
    r->addIndex<2>(ord409, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord410({0, 1});
    
    r->addIndex<2>(ord410, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lany"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("land");
  if (r == 0) db->addStruct("land", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("land");
      std::vector<u16> ord411({1, 2, 0});
    
    r->addIndex<3>(ord411, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord412({0, 1, 2});
    
    r->addIndex<3>(ord412, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("land"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lall");
  if (r == 0) db->addStruct("lall", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lall");
      std::vector<u16> ord413({1, 0});
    
    r->addIndex<2>(ord413, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord414({0, 1});
    
    r->addIndex<2>(ord414, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lall"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ladd");
  if (r == 0) db->addStruct("ladd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ladd");
      std::vector<u16> ord415({1, 2, 0});
    
    r->addIndex<3>(ord415, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord416({0, 1, 2});
    
    r->addIndex<3>(ord416, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ladd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("iv");
  if (r == 0) db->addStruct("iv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("iv");
      std::vector<u16> ord417({1, 0});
    
    r->addIndex<2>(ord417, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord418({0, 1});
    
    r->addIndex<2>(ord418, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("iv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord419({1, 2, 3, 0});
    
    r->addIndex<4>(ord419, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord420({0, 1, 2, 3});
    
    r->addIndex<4>(ord420, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ic");
  if (r == 0) db->addStruct("ic", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ic");
      std::vector<u16> ord421({1, 0});
    
    r->addIndex<2>(ord421, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord422({0, 1});
    
    r->addIndex<2>(ord422, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord423({1, 0});
    
    r->addIndex<2>(ord423, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ic"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord424({0});
    
    r->addIndex<1>(ord424, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord425({1, 2, 0});
    
    r->addIndex<3>(ord425, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord426({0, 1, 2});
    
    r->addIndex<3>(ord426, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bv");
  if (r == 0) db->addStruct("bv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bv");
      std::vector<u16> ord427({1, 0});
    
    r->addIndex<2>(ord427, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord428({0, 1});
    
    r->addIndex<2>(ord428, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("bv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord429({1, 0});
    
    r->addIndex<2>(ord429, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord430({0, 1});
    
    r->addIndex<2>(ord430, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  d->bindOracle(s, "smtcore", "smt_qcore", "smt_qcore_ans");
  d->bindOracle(s, "smtmodel", "smt_qmodel", "smt_qmodel_ans");
  d->bindOracle(s, "smt", "smt_qsat", "smt_qsat_ans");
  // (crule (pre) (scan smt_qsat_ans __t7hbr7 C) (body (join smt_vcode (0 1) 1 C V) (join-old smt_qsat (0 1) 1 (0 1) __t7hbr7 F) (join-old smt_check (1 0) 1 (1 0) F __t0kNU6)) (head (emit smt_check_ans (0 1) __t0kNU6 V)) smt.slog:69 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_vcodeindex0;  slog::Index** smt_qsatindex1;  slog::Index** smt_checkindex2;  slog::Index** smt_qsatdelta3;  slog::Index** smt_checkdelta4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check_ans");
      std::vector<u16> ord6({0, 1});
      slog::Relation* readrel7 = db->getRelation("smt_check_ans");
      head_index[0] = readrel7->getIndex(ord6, false);
      outer_rel = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("smt_vcode");
      smt_vcodeindex0 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("smt_qsat");
      smt_qsatindex1 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("smt_qsat");
      smt_qsatdelta3 = readrel13->getIndex(ord12, true);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("smt_check");
      smt_checkindex2 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("smt_check");
      smt_checkdelta4 = readrel17->getIndex(ord16, true);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(smt_vcodeindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m18) {
          u64 v_c2 = m18[1];
          slog::join_probe_old<2,1>(smt_qsatindex1, smt_qsatdelta3, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m19) {
            u64 v_c3 = m19[1];
            slog::join_probe_old<2,1>(smt_checkindex2, smt_checkdelta4, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m20) {
              u64 v_c4 = m20[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c2}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_qsat_ans", _fires);
  
      if (!_done)
      {
        ReadTask5* _cont = new ReadTask5(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), false);
  // (crule (pre (let __tconst08Aw25 const6b86b273ff34fce19d6b804e) (let __tconst33vO27 constd4735e3a265e16eee03f5971)) (scan smt_check __t8lTF30 __t67Tf29) (body (exists ic (1 0) 1 __tconst08Aw25) (exists ic (1 0) 1 __tconst33vO27) (join smt_check_ans (0 1) 1 __t8lTF30 V) (join ic (1 0) 1 __tconst08Aw25 __t4bFs26) (join llt (0 2 1) 2 __t67Tf29 __t4bFs26 __t5WsI28) (join ic (0 1) 2 __t5WsI28 __tconst33vO27)) (head (emit layer1 (0) V)) smt_multi.slog:8 #f)
  class ReadTask27 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex21;  slog::Index** icindex22;  slog::Index** smt_check_ansindex23;  slog::Index** icindex24;  slog::Index** lltindex25;  slog::Index** icindex26;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("layer1");
      std::vector<u16> ord28({0});
      slog::Relation* readrel29 = db->getRelation("layer1");
      head_index[0] = readrel29->getIndex(ord28, false);
      outer_rel = db->getRelation("smt_check");
      std::vector<u16> ord30({1, 0});
      slog::Relation* readrel31 = db->getRelation("ic");
      icindex21 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("ic");
      icindex22 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("smt_check_ans");
      smt_check_ansindex23 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 0});
      slog::Relation* readrel37 = db->getRelation("ic");
      icindex24 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({0, 2, 1});
      slog::Relation* readrel39 = db->getRelation("llt");
      lltindex25 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({0, 1});
      slog::Relation* readrel41 = db->getRelation("ic");
      icindex26 = readrel41->getIndex(ord40, false);
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constd4735e3a265e16eee03f5971;
  
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
        if (!slog::exists_probe<2,1>(icindex21, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(icindex22, std::array<u64,2>{v_c6, 0})) return;
        slog::join_probe<2,1>(smt_check_ansindex23, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m42) {
          u64 v_c2 = m42[1];
          slog::join_probe<2,1>(icindex24, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m43) {
            u64 v_c9 = m43[1];
            slog::join_probe<3,2>(lltindex25, std::array<u64,3>{v_c8, v_c9, 0}, [&](const std::array<u64,3>& m44) {
              u64 v_c10 = m44[2];
              slog::join_probe<2,2>(icindex26, std::array<u64,2>{v_c10, v_c6}, [&](const std::array<u64,2>& m45) {
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "delta:smt_check", _fires);
  
      if (!_done)
      {
        ReadTask27* _cont = new ReadTask27(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask27(db,b), false);
  // (crule (pre (let __tconst0JOY62 constd4735e3a265e16eee03f5971)) (scan lle __t5jOZ64 __t9gtf61 dup7wJr95) (body (eq __t9gtf61 dup7wJr95) (join ic (0 1) 2 __t9gtf61 __tconst0JOY62)) (head (mkstruct smt_check (1 0) __8yBk78 __t5jOZ64)) smt_multi.slog:12 #f)
  class ReadTask47 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex46;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("lle");
      std::vector<u16> ord48({0, 1});
      slog::Relation* readrel49 = db->getRelation("ic");
      icindex46 = readrel49->getIndex(ord48, false);
  
    }
    ReadTask47(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_constd4735e3a265e16eee03f5971;
  
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
        if (v_c13 != v_c14) return;
        slog::join_probe<2,2>(icindex46, std::array<u64,2>{v_c13, v_c11}, [&](const std::array<u64,2>& m50) {
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:12", "delta:lle", _fires);
  
      if (!_done)
      {
        ReadTask47* _cont = new ReadTask47(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask47(db,b), false);
  // (crule (pre (let __tconst5kEe10 constd4735e3a265e16eee03f5971) (let __tconst84Vz8 const6b86b273ff34fce19d6b804e)) (once) (body) (head (mkstruct ic (1 0) __t2tb111 __tconst5kEe10) (mkstruct ic (1 0) __t30Op9 __tconst84Vz8)) smt_multi.slog:8 #f)
  class ReadTask51 : public slog::Task
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
    ReadTask51(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c15}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask51(db,b), true);
  // (crule (pre) (scan smt_check __t0kNU6 F) (body (join-old smt_qsat (1 0) 1 (1 0) F __t7hbr7) (join smt_qsat_ans (0 1) 1 __t7hbr7 C) (join smt_vcode (0 1) 1 C V)) (head (emit smt_check_ans (0 1) __t0kNU6 V)) smt.slog:69 #f)
  class ReadTask56 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_qsatindex52;  slog::Index** smt_qsat_ansindex53;  slog::Index** smt_vcodeindex54;  slog::Index** smt_qsatdelta55;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check_ans");
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("smt_check_ans");
      head_index[0] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("smt_check");
      std::vector<u16> ord59({1, 0});
      slog::Relation* readrel60 = db->getRelation("smt_qsat");
      smt_qsatindex52 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 0});
      slog::Relation* readrel62 = db->getRelation("smt_qsat");
      smt_qsatdelta55 = readrel62->getIndex(ord61, true);
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("smt_qsat_ans");
      smt_qsat_ansindex53 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("smt_vcode");
      smt_vcodeindex54 = readrel66->getIndex(ord65, false);
  
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
        u64 v_c4 = _t[0];
        u64 v_c3 = _t[1];
        slog::join_probe_old<2,1>(smt_qsatindex52, smt_qsatdelta55, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m67) {
          u64 v_c0 = m67[1];
          slog::join_probe<2,1>(smt_qsat_ansindex53, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m68) {
            u64 v_c1 = m68[1];
            slog::join_probe<2,1>(smt_vcodeindex54, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m69) {
              u64 v_c2 = m69[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c2}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_check", _fires);
  
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
  // (crule (pre (let __tconst5kEe10 constd4735e3a265e16eee03f5971) (let __tconst84Vz8 const6b86b273ff34fce19d6b804e)) (scan llt __t4oe712 __t2tb111 __t30Op9) (body (join ic (0 1) 2 __t30Op9 __tconst84Vz8) (join ic (0 1) 2 __t2tb111 __tconst5kEe10)) (head (mkstruct smt_check (1 0) __67R275 __t4oe712)) smt_multi.slog:8 #f)
  class ReadTask72 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex70;  slog::Index** icindex71;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("llt");
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("ic");
      icindex70 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("ic");
      icindex71 = readrel76->getIndex(ord75, false);
  
    }
    ReadTask72(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
  
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
        slog::join_probe<2,2>(icindex70, std::array<u64,2>{v_c19, v_c16}, [&](const std::array<u64,2>& m77) {
          slog::join_probe<2,2>(icindex71, std::array<u64,2>{v_c18, v_c15}, [&](const std::array<u64,2>& m78) {
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "delta:llt", _fires);
  
      if (!_done)
      {
        ReadTask72* _cont = new ReadTask72(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask72(db,b), false);
  // (crule (pre (let __tconst0JOY62 constd4735e3a265e16eee03f5971)) (seeded) (body (join ic (1 0) 1 __tconst0JOY62 __t9gtf61) (join lle (1 2 0) 1 __t9gtf61 dup4HtR96 __t5jOZ64) (eq __t9gtf61 dup4HtR96)) (head (mkstruct smt_check (1 0) __8yBk78 __t5jOZ64)) smt_multi.slog:12 #f)
  class ReadTask81 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex79;  slog::Index** lleindex80;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord82({1, 0});
      slog::Relation* readrel83 = db->getRelation("smt_check");
      head_index[0] = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 0});
      slog::Relation* readrel85 = db->getRelation("ic");
      icindex79 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 0});
      slog::Relation* readrel87 = db->getRelation("lle");
      lleindex80 = readrel87->getIndex(ord86, false);
  
    }
    ReadTask81(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex79, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m88) {
        u64 v_c13 = m88[1];
        slog::join_probe<3,1>(lleindex80, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m89) {
          u64 v_c20 = m89[1]; u64 v_c12 = m89[2];
          if (v_c13 != v_c20) return;
          ++_fires;
          slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:12", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask81(db,b));
  // (crule (pre (let __tconst5kEe10 constd4735e3a265e16eee03f5971) (let __tconst84Vz8 const6b86b273ff34fce19d6b804e)) (seeded) (body (join ic (1 0) 1 __tconst84Vz8 __t30Op9) (join ic (1 0) 1 __tconst5kEe10 __t2tb111)) (head (mkstruct llt (1 2 0) __t4oe712 __t2tb111 __t30Op9)) smt_multi.slog:8 #f)
  class ReadTask92 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex90;  slog::Index** icindex91;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord93({1, 2, 0});
      slog::Relation* readrel94 = db->getRelation("llt");
      head_index[0] = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 0});
      slog::Relation* readrel96 = db->getRelation("ic");
      icindex90 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 0});
      slog::Relation* readrel98 = db->getRelation("ic");
      icindex91 = readrel98->getIndex(ord97, false);
  
    }
    ReadTask92(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex90, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m99) {
        u64 v_c19 = m99[1];
        slog::join_probe<2,1>(icindex91, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m100) {
          u64 v_c18 = m100[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c18, v_c19}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask92(db,b));
  // (crule (pre (let __tconst0Z2o3 constd4735e3a265e16eee03f5971) (let __tconst7vzq1 const6b86b273ff34fce19d6b804e)) (seeded) (body (join ic (1 0) 1 __tconst7vzq1 __t14LP2) (join ic (1 0) 1 __tconst0Z2o3 __t9IHI4)) (head (mkstruct llt (1 2 0) __t7Xyl5 __t9IHI4 __t14LP2)) smt_multi.slog:11 #f)
  class ReadTask103 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex101;  slog::Index** icindex102;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord104({1, 2, 0});
      slog::Relation* readrel105 = db->getRelation("llt");
      head_index[0] = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 0});
      slog::Relation* readrel107 = db->getRelation("ic");
      icindex101 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 0});
      slog::Relation* readrel109 = db->getRelation("ic");
      icindex102 = readrel109->getIndex(ord108, false);
  
    }
    ReadTask103(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c21 = v_constd4735e3a265e16eee03f5971;
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex101, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m110) {
        u64 v_c23 = m110[1];
        slog::join_probe<2,1>(icindex102, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m111) {
          u64 v_c24 = m111[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c23}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:11", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask103(db,b));
  // (crule (pre (let __tconst0JOY62 constd4735e3a265e16eee03f5971)) (scan layer1 V) (body) (head (mkstruct ic (1 0) __t9gtf61 __tconst0JOY62)) smt_multi.slog:12 #f)
  class ReadTask112 : public slog::Task
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
      head_rel[0] = db->getRelation("ic");
      outer_rel = db->getRelation("layer1");
  
    }
    ReadTask112(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c2 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:12", "delta:layer1", _fires);
  
      if (!_done)
      {
        ReadTask112* _cont = new ReadTask112(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask112(db,b), false);
  // (crule (pre (let __tconst08Aw25 const6b86b273ff34fce19d6b804e) (let __tconst33vO27 constd4735e3a265e16eee03f5971)) (scan smt_check_ans __t8lTF30 V) (body (exists ic (1 0) 1 __tconst33vO27) (join-old ic (1 0) 1 (1 0) __tconst08Aw25 __t4bFs26) (exists llt (2 0 1) 1 __t4bFs26) (join-old ic (1 0) 1 (1 0) __tconst33vO27 __t5WsI28) (join-old llt (1 2 0) 2 (1 2 0) __t5WsI28 __t4bFs26 __t67Tf29) (join-old smt_check (0 1) 2 (0 1) __t8lTF30 __t67Tf29)) (head (emit layer1 (0) V)) smt_multi.slog:8 #f)
  class ReadTask123 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex113;  slog::Index** icindex114;  slog::Index** lltindex115;  slog::Index** icindex116;  slog::Index** lltindex117;  slog::Index** smt_checkindex118;  slog::Index** icdelta119;  slog::Index** icdelta120;  slog::Index** lltdelta121;  slog::Index** smt_checkdelta122;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("layer1");
      std::vector<u16> ord124({0});
      slog::Relation* readrel125 = db->getRelation("layer1");
      head_index[0] = readrel125->getIndex(ord124, false);
      outer_rel = db->getRelation("smt_check_ans");
      std::vector<u16> ord126({1, 0});
      slog::Relation* readrel127 = db->getRelation("ic");
      icindex113 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 0});
      slog::Relation* readrel129 = db->getRelation("ic");
      icindex114 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("ic");
      icdelta119 = readrel131->getIndex(ord130, true);
      std::vector<u16> ord132({2, 0, 1});
      slog::Relation* readrel133 = db->getRelation("llt");
      lltindex115 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("ic");
      icindex116 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0});
      slog::Relation* readrel137 = db->getRelation("ic");
      icdelta120 = readrel137->getIndex(ord136, true);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("llt");
      lltindex117 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 0});
      slog::Relation* readrel141 = db->getRelation("llt");
      lltdelta121 = readrel141->getIndex(ord140, true);
      std::vector<u16> ord142({0, 1});
      slog::Relation* readrel143 = db->getRelation("smt_check");
      smt_checkindex118 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({0, 1});
      slog::Relation* readrel145 = db->getRelation("smt_check");
      smt_checkdelta122 = readrel145->getIndex(ord144, true);
  
    }
    ReadTask123(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c7 = _t[0];
        u64 v_c2 = _t[1];
        if (!slog::exists_probe<2,1>(icindex113, std::array<u64,2>{v_c6, 0})) return;
        slog::join_probe_old<2,1>(icindex114, icdelta119, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m146) {
          u64 v_c9 = m146[1];
          if (!slog::exists_probe<3,1>(lltindex115, std::array<u64,3>{v_c9, 0, 0})) return;
          slog::join_probe_old<2,1>(icindex116, icdelta120, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m147) {
            u64 v_c10 = m147[1];
            slog::join_probe_old<3,2>(lltindex117, lltdelta121, std::array<u64,3>{v_c10, v_c9, 0}, [&](const std::array<u64,3>& m148) {
              u64 v_c8 = m148[2];
              slog::join_probe_old<2,2>(smt_checkindex118, smt_checkdelta122, std::array<u64,2>{v_c7, v_c8}, [&](const std::array<u64,2>& m149) {
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "delta:smt_check_ans", _fires);
  
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
  // (crule (pre (let __tconst0Z2o3 constd4735e3a265e16eee03f5971) (let __tconst7vzq1 const6b86b273ff34fce19d6b804e)) (scan layer1 V) (body) (head (mkstruct ic (1 0) __t9IHI4 __tconst0Z2o3) (mkstruct ic (1 0) __t14LP2 __tconst7vzq1)) smt_multi.slog:11 #f)
  class ReadTask150 : public slog::Task
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
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("ic");
      outer_rel = db->getRelation("layer1");
  
    }
    ReadTask150(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c21 = v_constd4735e3a265e16eee03f5971;
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c2 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_multi.slog:11", "delta:layer1", _fires);
  
      if (!_done)
      {
        ReadTask150* _cont = new ReadTask150(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask150(db,b), false);
  // (crule (pre (let __tconst0Z2o3 constd4735e3a265e16eee03f5971) (let __tconst7vzq1 const6b86b273ff34fce19d6b804e)) (seeded) (body (join ic (1 0) 1 __tconst7vzq1 __t14LP2) (exists llt (2 0 1) 1 __t14LP2) (join ic (1 0) 1 __tconst0Z2o3 __t9IHI4) (join llt (1 2 0) 2 __t9IHI4 __t14LP2 __t7Xyl5)) (head (mkstruct smt_check (1 0) __9WRI79 __t7Xyl5)) smt_multi.slog:11 #f)
  class ReadTask155 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex151;  slog::Index** lltindex152;  slog::Index** icindex153;  slog::Index** lltindex154;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord156({1, 0});
      slog::Relation* readrel157 = db->getRelation("smt_check");
      head_index[0] = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 0});
      slog::Relation* readrel159 = db->getRelation("ic");
      icindex151 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({2, 0, 1});
      slog::Relation* readrel161 = db->getRelation("llt");
      lltindex152 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 0});
      slog::Relation* readrel163 = db->getRelation("ic");
      icindex153 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 2, 0});
      slog::Relation* readrel165 = db->getRelation("llt");
      lltindex154 = readrel165->getIndex(ord164, false);
  
    }
    ReadTask155(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c21 = v_constd4735e3a265e16eee03f5971;
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex151, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m166) {
        u64 v_c23 = m166[1];
        if (!slog::exists_probe<3,1>(lltindex152, std::array<u64,3>{v_c23, 0, 0})) return;
        slog::join_probe<2,1>(icindex153, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m167) {
          u64 v_c24 = m167[1];
          slog::join_probe<3,2>(lltindex154, std::array<u64,3>{v_c24, v_c23, 0}, [&](const std::array<u64,3>& m168) {
            u64 v_c25 = m168[2];
            ++_fires;
            slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:11", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask155(db,b));
  // (crule (pre) (scan smt_vcode C V) (body (join smt_core (0 1) 0 __t9VQn23 F)) (head (mkstruct smt_qcore (1 0) __471a77 F)) smt.slog:106 #f)
  class ReadTask170 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_coreindex169;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_qcore");
      outer_rel = db->getRelation("smt_vcode");
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("smt_core");
      smt_coreindex169 = readrel172->getIndex(ord171, false);
  
    }
    ReadTask170(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        slog::join_all<2>(smt_coreindex169, [&](const std::array<u64,2>& m173) {
          u64 v_c26 = m173[0]; u64 v_c3 = m173[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:106", "all:smt_vcode", _fires);
  
      if (!_done)
      {
        ReadTask170* _cont = new ReadTask170(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask170(db,b), true);
  // (crule (pre (let __tconst08Aw25 const6b86b273ff34fce19d6b804e) (let __tconst33vO27 constd4735e3a265e16eee03f5971)) (scan llt __t67Tf29 __t5WsI28 __t4bFs26) (body (join ic (0 1) 2 __t4bFs26 __tconst08Aw25) (join ic (0 1) 2 __t5WsI28 __tconst33vO27) (join-old smt_check (1 0) 1 (1 0) __t67Tf29 __t8lTF30) (join smt_check_ans (0 1) 1 __t8lTF30 V)) (head (emit layer1 (0) V)) smt_multi.slog:8 #f)
  class ReadTask179 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex174;  slog::Index** icindex175;  slog::Index** smt_checkindex176;  slog::Index** smt_check_ansindex177;  slog::Index** smt_checkdelta178;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("layer1");
      std::vector<u16> ord180({0});
      slog::Relation* readrel181 = db->getRelation("layer1");
      head_index[0] = readrel181->getIndex(ord180, false);
      outer_rel = db->getRelation("llt");
      std::vector<u16> ord182({0, 1});
      slog::Relation* readrel183 = db->getRelation("ic");
      icindex174 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({0, 1});
      slog::Relation* readrel185 = db->getRelation("ic");
      icindex175 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 0});
      slog::Relation* readrel187 = db->getRelation("smt_check");
      smt_checkindex176 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 0});
      slog::Relation* readrel189 = db->getRelation("smt_check");
      smt_checkdelta178 = readrel189->getIndex(ord188, true);
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("smt_check_ans");
      smt_check_ansindex177 = readrel191->getIndex(ord190, false);
  
    }
    ReadTask179(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c8 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c9 = _t[2];
        slog::join_probe<2,2>(icindex174, std::array<u64,2>{v_c9, v_c5}, [&](const std::array<u64,2>& m192) {
          slog::join_probe<2,2>(icindex175, std::array<u64,2>{v_c10, v_c6}, [&](const std::array<u64,2>& m193) {
            slog::join_probe_old<2,1>(smt_checkindex176, smt_checkdelta178, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m194) {
              u64 v_c7 = m194[1];
              slog::join_probe<2,1>(smt_check_ansindex177, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m195) {
                u64 v_c2 = m195[1];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "delta:llt", _fires);
  
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
  // (crule (pre (let __tconst08Aw25 const6b86b273ff34fce19d6b804e) (let __tconst33vO27 constd4735e3a265e16eee03f5971)) (probe ic (1 0) 1 __tconst33vO27 __t5WsI28) (body (exists llt (1 2 0) 1 __t5WsI28) (join ic (1 0) 1 __tconst08Aw25 __t4bFs26) (join-old llt (1 2 0) 2 (1 2 0) __t5WsI28 __t4bFs26 __t67Tf29) (join-old smt_check (1 0) 1 (1 0) __t67Tf29 __t8lTF30) (join smt_check_ans (0 1) 1 __t8lTF30 V)) (head (emit layer1 (0) V)) smt_multi.slog:8 #f)
  class ReadTask203 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex196;  slog::Index** icindex197;  slog::Index** lltindex198;  slog::Index** smt_checkindex199;  slog::Index** smt_check_ansindex200;  slog::Index** lltdelta201;  slog::Index** smt_checkdelta202;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("layer1");
      std::vector<u16> ord204({0});
      slog::Relation* readrel205 = db->getRelation("layer1");
      head_index[0] = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 0});
      slog::Relation* readrel207 = db->getRelation("ic");
      driver_index = readrel207->getIndex(ord206, true);
      std::vector<u16> ord208({1, 2, 0});
      slog::Relation* readrel209 = db->getRelation("llt");
      lltindex196 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 0});
      slog::Relation* readrel211 = db->getRelation("ic");
      icindex197 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 0});
      slog::Relation* readrel213 = db->getRelation("llt");
      lltindex198 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 2, 0});
      slog::Relation* readrel215 = db->getRelation("llt");
      lltdelta201 = readrel215->getIndex(ord214, true);
      std::vector<u16> ord216({1, 0});
      slog::Relation* readrel217 = db->getRelation("smt_check");
      smt_checkindex199 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 0});
      slog::Relation* readrel219 = db->getRelation("smt_check");
      smt_checkdelta202 = readrel219->getIndex(ord218, true);
      std::vector<u16> ord220({0, 1});
      slog::Relation* readrel221 = db->getRelation("smt_check_ans");
      smt_check_ansindex200 = readrel221->getIndex(ord220, false);
  
    }
    ReadTask203(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c6, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m222) {
        u64 v_c10 = m222[1];
        if (buckethash(v_c10) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex196, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<2,1>(icindex197, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m223) {
          u64 v_c9 = m223[1];
          slog::join_probe_old<3,2>(lltindex198, lltdelta201, std::array<u64,3>{v_c10, v_c9, 0}, [&](const std::array<u64,3>& m224) {
            u64 v_c8 = m224[2];
            slog::join_probe_old<2,1>(smt_checkindex199, smt_checkdelta202, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m225) {
              u64 v_c7 = m225[1];
              slog::join_probe<2,1>(smt_check_ansindex200, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m226) {
                u64 v_c2 = m226[1];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask203* _cont = new ReadTask203(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask203(db,b), false);
  // (crule (pre) (scan smt_bad_formula __erre82sY92 __errf2lyR93 __errf9YWE94) (body) (head (emit error (0) __erre82sY92)) <internal>:1 #f)
  class ReadTask227 : public slog::Task
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
      std::vector<u16> ord228({0});
      slog::Relation* readrel229 = db->getRelation("error");
      head_index[0] = readrel229->getIndex(ord228, false);
      outer_rel = db->getRelation("smt_bad_formula");
  
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
        u64 v_c27 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:smt_bad_formula", _fires);
  
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
  // (crule (pre (let __tconst0Z2o3 constd4735e3a265e16eee03f5971) (let __tconst7vzq1 const6b86b273ff34fce19d6b804e)) (probe ic (1 0) 1 __tconst7vzq1 __t14LP2) (body (join ic (1 0) 1 __tconst0Z2o3 __t9IHI4)) (head (mkstruct llt (1 2 0) __t7Xyl5 __t9IHI4 __t14LP2)) smt_multi.slog:11 #f)
  class ReadTask231 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex230;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("ic");
      driver_index = readrel233->getIndex(ord232, true);
      std::vector<u16> ord234({1, 0});
      slog::Relation* readrel235 = db->getRelation("ic");
      icindex230 = readrel235->getIndex(ord234, false);
  
    }
    ReadTask231(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c21 = v_constd4735e3a265e16eee03f5971;
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c22, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m236) {
        u64 v_c23 = m236[1];
        if (buckethash(v_c23) != bucket) return;
        slog::join_probe<2,1>(icindex230, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m237) {
          u64 v_c24 = m237[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c24, v_c23}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:11", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask231* _cont = new ReadTask231(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask231(db,b), false);
  // (crule (pre) (scan smt_qsat __t7hbr7 F) (body (exists smt_check (1 0) 1 F) (join smt_qsat_ans (0 1) 1 __t7hbr7 C) (join smt_vcode (0 1) 1 C V) (join smt_check (1 0) 1 F __t0kNU6)) (head (emit smt_check_ans (0 1) __t0kNU6 V)) smt.slog:69 #f)
  class ReadTask242 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_checkindex238;  slog::Index** smt_qsat_ansindex239;  slog::Index** smt_vcodeindex240;  slog::Index** smt_checkindex241;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check_ans");
      std::vector<u16> ord243({0, 1});
      slog::Relation* readrel244 = db->getRelation("smt_check_ans");
      head_index[0] = readrel244->getIndex(ord243, false);
      outer_rel = db->getRelation("smt_qsat");
      std::vector<u16> ord245({1, 0});
      slog::Relation* readrel246 = db->getRelation("smt_check");
      smt_checkindex238 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({0, 1});
      slog::Relation* readrel248 = db->getRelation("smt_qsat_ans");
      smt_qsat_ansindex239 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({0, 1});
      slog::Relation* readrel250 = db->getRelation("smt_vcode");
      smt_vcodeindex240 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 0});
      slog::Relation* readrel252 = db->getRelation("smt_check");
      smt_checkindex241 = readrel252->getIndex(ord251, false);
  
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
        u64 v_c0 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<2,1>(smt_checkindex238, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(smt_qsat_ansindex239, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m253) {
          u64 v_c1 = m253[1];
          slog::join_probe<2,1>(smt_vcodeindex240, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m254) {
            u64 v_c2 = m254[1];
            slog::join_probe<2,1>(smt_checkindex241, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m255) {
              u64 v_c4 = m255[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c2}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_qsat", _fires);
  
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
  // (crule (pre (let __tconst5kEe10 constd4735e3a265e16eee03f5971) (let __tconst84Vz8 const6b86b273ff34fce19d6b804e)) (probe ic (1 0) 1 __tconst84Vz8 __t30Op9) (body (join ic (1 0) 1 __tconst5kEe10 __t2tb111)) (head (mkstruct llt (1 2 0) __t4oe712 __t2tb111 __t30Op9)) smt_multi.slog:8 #f)
  class ReadTask257 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex256;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("llt");
      std::vector<u16> ord258({1, 0});
      slog::Relation* readrel259 = db->getRelation("ic");
      driver_index = readrel259->getIndex(ord258, true);
      std::vector<u16> ord260({1, 0});
      slog::Relation* readrel261 = db->getRelation("ic");
      icindex256 = readrel261->getIndex(ord260, false);
  
    }
    ReadTask257(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c16, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m262) {
        u64 v_c19 = m262[1];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<2,1>(icindex256, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m263) {
          u64 v_c18 = m263[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c18, v_c19}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask257* _cont = new ReadTask257(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask257(db,b), false);
  // (crule (pre (let __tconst0Z2o3 constd4735e3a265e16eee03f5971) (let __tconst7vzq1 const6b86b273ff34fce19d6b804e)) (scan llt __t7Xyl5 __t9IHI4 __t14LP2) (body (join ic (0 1) 2 __t14LP2 __tconst7vzq1) (join ic (0 1) 2 __t9IHI4 __tconst0Z2o3)) (head (mkstruct smt_check (1 0) __9WRI79 __t7Xyl5)) smt_multi.slog:11 #f)
  class ReadTask266 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex264;  slog::Index** icindex265;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("llt");
      std::vector<u16> ord267({0, 1});
      slog::Relation* readrel268 = db->getRelation("ic");
      icindex264 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({0, 1});
      slog::Relation* readrel270 = db->getRelation("ic");
      icindex265 = readrel270->getIndex(ord269, false);
  
    }
    ReadTask266(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c21 = v_constd4735e3a265e16eee03f5971;
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c25 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe<2,2>(icindex264, std::array<u64,2>{v_c23, v_c22}, [&](const std::array<u64,2>& m271) {
          slog::join_probe<2,2>(icindex265, std::array<u64,2>{v_c24, v_c21}, [&](const std::array<u64,2>& m272) {
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:11", "delta:llt", _fires);
  
      if (!_done)
      {
        ReadTask266* _cont = new ReadTask266(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask266(db,b), false);
  // (crule (pre (let __tconst08Aw25 const6b86b273ff34fce19d6b804e) (let __tconst33vO27 constd4735e3a265e16eee03f5971)) (probe ic (1 0) 1 __tconst08Aw25 __t4bFs26) (body (exists llt (2 0 1) 1 __t4bFs26) (join-old ic (1 0) 1 (1 0) __tconst33vO27 __t5WsI28) (join-old llt (1 2 0) 2 (1 2 0) __t5WsI28 __t4bFs26 __t67Tf29) (join-old smt_check (1 0) 1 (1 0) __t67Tf29 __t8lTF30) (join smt_check_ans (0 1) 1 __t8lTF30 V)) (head (emit layer1 (0) V)) smt_multi.slog:8 #f)
  class ReadTask281 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex273;  slog::Index** icindex274;  slog::Index** lltindex275;  slog::Index** smt_checkindex276;  slog::Index** smt_check_ansindex277;  slog::Index** icdelta278;  slog::Index** lltdelta279;  slog::Index** smt_checkdelta280;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("layer1");
      std::vector<u16> ord282({0});
      slog::Relation* readrel283 = db->getRelation("layer1");
      head_index[0] = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({1, 0});
      slog::Relation* readrel285 = db->getRelation("ic");
      driver_index = readrel285->getIndex(ord284, true);
      std::vector<u16> ord286({2, 0, 1});
      slog::Relation* readrel287 = db->getRelation("llt");
      lltindex273 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 0});
      slog::Relation* readrel289 = db->getRelation("ic");
      icindex274 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 0});
      slog::Relation* readrel291 = db->getRelation("ic");
      icdelta278 = readrel291->getIndex(ord290, true);
      std::vector<u16> ord292({1, 2, 0});
      slog::Relation* readrel293 = db->getRelation("llt");
      lltindex275 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 2, 0});
      slog::Relation* readrel295 = db->getRelation("llt");
      lltdelta279 = readrel295->getIndex(ord294, true);
      std::vector<u16> ord296({1, 0});
      slog::Relation* readrel297 = db->getRelation("smt_check");
      smt_checkindex276 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 0});
      slog::Relation* readrel299 = db->getRelation("smt_check");
      smt_checkdelta280 = readrel299->getIndex(ord298, true);
      std::vector<u16> ord300({0, 1});
      slog::Relation* readrel301 = db->getRelation("smt_check_ans");
      smt_check_ansindex277 = readrel301->getIndex(ord300, false);
  
    }
    ReadTask281(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c5, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m302) {
        u64 v_c9 = m302[1];
        if (buckethash(v_c9) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex273, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe_old<2,1>(icindex274, icdelta278, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m303) {
          u64 v_c10 = m303[1];
          slog::join_probe_old<3,2>(lltindex275, lltdelta279, std::array<u64,3>{v_c10, v_c9, 0}, [&](const std::array<u64,3>& m304) {
            u64 v_c8 = m304[2];
            slog::join_probe_old<2,1>(smt_checkindex276, smt_checkdelta280, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m305) {
              u64 v_c7 = m305[1];
              slog::join_probe<2,1>(smt_check_ansindex277, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m306) {
                u64 v_c2 = m306[1];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask281* _cont = new ReadTask281(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask281(db,b), false);
  // (crule (pre) (scan smt_check __t4xvy20 F) (body (join smt_vcode (0 1) 0 C V)) (head (mkstruct smt_qsat (1 0) __612H73 F)) smt.slog:69 #f)
  class ReadTask308 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_vcodeindex307;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_qsat");
      outer_rel = db->getRelation("smt_check");
      std::vector<u16> ord309({0, 1});
      slog::Relation* readrel310 = db->getRelation("smt_vcode");
      smt_vcodeindex307 = readrel310->getIndex(ord309, false);
  
    }
    ReadTask308(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        slog::join_all<2>(smt_vcodeindex307, [&](const std::array<u64,2>& m311) {
          u64 v_c1 = m311[0]; u64 v_c2 = m311[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_check", _fires);
  
      if (!_done)
      {
        ReadTask308* _cont = new ReadTask308(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask308(db,b), false);
  // (crule (pre) (scan smt_vcode C V) (body (join smt_model (0 1) 0 __t7sIn24 F)) (head (mkstruct smt_qmodel (1 0) __5khA72 F)) smt.slog:93 #f)
  class ReadTask313 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_modelindex312;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_qmodel");
      outer_rel = db->getRelation("smt_vcode");
      std::vector<u16> ord314({0, 1});
      slog::Relation* readrel315 = db->getRelation("smt_model");
      smt_modelindex312 = readrel315->getIndex(ord314, false);
  
    }
    ReadTask313(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        slog::join_all<2>(smt_modelindex312, [&](const std::array<u64,2>& m316) {
          u64 v_c31 = m316[0]; u64 v_c3 = m316[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:93", "all:smt_vcode", _fires);
  
      if (!_done)
      {
        ReadTask313* _cont = new ReadTask313(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask313(db,b), true);
  // (crule (pre (let __tconst5kEe10 constd4735e3a265e16eee03f5971) (let __tconst84Vz8 const6b86b273ff34fce19d6b804e)) (seeded) (body (join ic (1 0) 1 __tconst84Vz8 __t30Op9) (exists llt (2 0 1) 1 __t30Op9) (join ic (1 0) 1 __tconst5kEe10 __t2tb111) (join llt (1 2 0) 2 __t2tb111 __t30Op9 __t4oe712)) (head (mkstruct smt_check (1 0) __67R275 __t4oe712)) smt_multi.slog:8 #f)
  class ReadTask321 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex317;  slog::Index** lltindex318;  slog::Index** icindex319;  slog::Index** lltindex320;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord322({1, 0});
      slog::Relation* readrel323 = db->getRelation("smt_check");
      head_index[0] = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 0});
      slog::Relation* readrel325 = db->getRelation("ic");
      icindex317 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({2, 0, 1});
      slog::Relation* readrel327 = db->getRelation("llt");
      lltindex318 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 0});
      slog::Relation* readrel329 = db->getRelation("ic");
      icindex319 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 0});
      slog::Relation* readrel331 = db->getRelation("llt");
      lltindex320 = readrel331->getIndex(ord330, false);
  
    }
    ReadTask321(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex317, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m332) {
        u64 v_c19 = m332[1];
        if (!slog::exists_probe<3,1>(lltindex318, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe<2,1>(icindex319, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m333) {
          u64 v_c18 = m333[1];
          slog::join_probe<3,2>(lltindex320, std::array<u64,3>{v_c18, v_c19, 0}, [&](const std::array<u64,3>& m334) {
            u64 v_c17 = m334[2];
            ++_fires;
            slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:8", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask321(db,b));
  // (crule (pre (let __tconst0JOY62 constd4735e3a265e16eee03f5971)) (probe ic (1 0) 1 __tconst0JOY62 __t9gtf61) (body) (head (mkstruct lle (1 2 0) __t5jOZ64 __t9gtf61 __t9gtf61)) smt_multi.slog:12 #f)
  class ReadTask335 : public slog::Task
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
      head_rel[0] = db->getRelation("lle");
      std::vector<u16> ord336({1, 0});
      slog::Relation* readrel337 = db->getRelation("ic");
      driver_index = readrel337->getIndex(ord336, true);
  
    }
    ReadTask335(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c11, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m338) {
        u64 v_c13 = m338[1];
        if (buckethash(v_c13) != bucket) return;
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c13, v_c13}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_multi.slog:12", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask335* _cont = new ReadTask335(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask335(db,b), false);
  s->addReadRel("ic");
  s->addReadRel("layer1");
  s->addReadRel("lle");
  s->addReadRel("llt");
  s->addReadRel("smt_bad_formula");
  s->addReadRel("smt_check");
  s->addReadRel("smt_check_ans");
  s->addReadRel("smt_core");
  s->addReadRel("smt_model");
  s->addReadRel("smt_qsat");
  s->addReadRel("smt_qsat_ans");
  s->addReadRel("smt_vcode");
  s->addDynamicRel("error");
  s->addDynamicRel("ic");
  s->addDynamicRel("layer1");
  s->addDynamicRel("lle");
  s->addDynamicRel("llt");
  s->addDynamicRel("smt_bad_formula");
  s->addDynamicRel("smt_check");
  s->addDynamicRel("smt_check_ans");
  s->addDynamicRel("smt_qcore");
  s->addDynamicRel("smt_qcore_ans");
  s->addDynamicRel("smt_qmodel");
  s->addDynamicRel("smt_qmodel_ans");
  s->addDynamicRel("smt_qsat");
  s->addDynamicRel("smt_qsat_ans");
  s->addAccelRel("layer1");
  s->addAccelRel("smt_check_ans");
  d->push(s);
  d->continueRun();
}

