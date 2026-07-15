
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constab76c7d069d6f33dc950fb33;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("1e3dd4b0");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constab76c7d069d6f33dc950fb33 = db->encodeString("sat");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord367({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord367, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord368({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord368, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord369({1, 2, 0});
    
    r->addIndex<3>(ord369, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord370({0, 1, 2});
    
    r->addIndex<3>(ord370, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp5QcX135");
  if (r == 0) db->addTempRelation("temp5QcX135", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp43NC134");
  if (r == 0) db->addTempRelation("temp43NC134", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_vcode");
  if (r == 0) db->addRelation("smt_vcode", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_vcode");
      std::vector<u16> ord371({0, 1});
    
    r->addIndex<2>(ord371, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_vcode"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_unsat");
  if (r == 0) db->addRelation("smt_unsat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unsat");
      std::vector<u16> ord372({0});
    
    r->addIndex<1>(ord372, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unsat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_unknown");
  if (r == 0) db->addRelation("smt_unknown", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unknown");
      std::vector<u16> ord373({0});
    
    r->addIndex<1>(ord373, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unknown"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_sat");
  if (r == 0) db->addRelation("smt_sat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_sat");
      std::vector<u16> ord374({0});
    
    r->addIndex<1>(ord374, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_sat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_qsat_ans");
  if (r == 0) db->addRelation("smt_qsat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord375({0, 1});
    
    r->addIndex<2>(ord375, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qsat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qsat");
  if (r == 0) db->addStruct("smt_qsat", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat");
      std::vector<u16> ord376({1, 0});
    
    r->addIndex<2>(ord376, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord377({0, 1});
    
    r->addIndex<2>(ord377, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord378({0, 1});
    
    r->addIndex<2>(ord378, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord379({1, 0});
    
    r->addIndex<2>(ord379, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qsat"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qmodel_ans");
  if (r == 0) db->addRelation("smt_qmodel_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel_ans");
      std::vector<u16> ord380({0, 1});
    
    r->addIndex<2>(ord380, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qmodel_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qmodel");
  if (r == 0) db->addStruct("smt_qmodel", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel");
      std::vector<u16> ord381({1, 0});
    
    r->addIndex<2>(ord381, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord382({0, 1});
    
    r->addIndex<2>(ord382, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qmodel"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qcore_ans");
  if (r == 0) db->addRelation("smt_qcore_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore_ans");
      std::vector<u16> ord383({0, 1});
    
    r->addIndex<2>(ord383, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qcore_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qcore");
  if (r == 0) db->addStruct("smt_qcore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore");
      std::vector<u16> ord384({1, 0});
    
    r->addIndex<2>(ord384, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord385({0, 1});
    
    r->addIndex<2>(ord385, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qcore"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_model_ans");
  if (r == 0) db->addRelation("smt_model_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model_ans");
      std::vector<u16> ord386({0, 1, 2});
    
    r->addIndex<3>(ord386, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_model_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_model");
  if (r == 0) db->addStruct("smt_model", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model");
      std::vector<u16> ord387({1, 0});
    
    r->addIndex<2>(ord387, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord388({0, 1});
    
    r->addIndex<2>(ord388, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_model"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_core_ans");
  if (r == 0) db->addRelation("smt_core_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core_ans");
      std::vector<u16> ord389({0, 1, 2});
    
    r->addIndex<3>(ord389, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_core_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_core");
  if (r == 0) db->addStruct("smt_core", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core");
      std::vector<u16> ord390({1, 0});
    
    r->addIndex<2>(ord390, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord391({0, 1});
    
    r->addIndex<2>(ord391, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_core"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check_ans");
  if (r == 0) db->addRelation("smt_check_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check_ans");
      std::vector<u16> ord392({0, 1});
    
    r->addIndex<2>(ord392, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord393({1, 0});
    
    r->addIndex<2>(ord393, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord394({1, 0});
    
    r->addIndex<2>(ord394, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_check_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_check");
  if (r == 0) db->addStruct("smt_check", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check");
      std::vector<u16> ord395({1, 0});
    
    r->addIndex<2>(ord395, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord396({0, 1});
    
    r->addIndex<2>(ord396, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord397({0, 1});
    
    r->addIndex<2>(ord397, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord398({1, 0});
    
    r->addIndex<2>(ord398, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_check"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord399({1, 2, 0});
    
    r->addIndex<3>(ord399, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord400({0, 1, 2});
    
    r->addIndex<3>(ord400, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord401({1, 2, 3, 0});
    
    r->addIndex<4>(ord401, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord402({0, 1, 2, 3});
    
    r->addIndex<4>(ord402, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord403({1, 2, 0});
    
    r->addIndex<3>(ord403, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord404({0, 1, 2});
    
    r->addIndex<3>(ord404, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord405({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord405, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord406({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord406, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord407({1, 2, 0});
    
    r->addIndex<3>(ord407, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord408({0, 1, 2});
    
    r->addIndex<3>(ord408, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord409({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord409, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord410({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord410, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lsub");
  if (r == 0) db->addStruct("lsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lsub");
      std::vector<u16> ord411({1, 2, 0});
    
    r->addIndex<3>(ord411, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord412({0, 1, 2});
    
    r->addIndex<3>(ord412, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lsub"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lor");
  if (r == 0) db->addStruct("lor", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lor");
      std::vector<u16> ord413({1, 2, 0});
    
    r->addIndex<3>(ord413, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord414({0, 1, 2});
    
    r->addIndex<3>(ord414, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lor"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lnot");
  if (r == 0) db->addStruct("lnot", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lnot");
      std::vector<u16> ord415({1, 0});
    
    r->addIndex<2>(ord415, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord416({0, 1});
    
    r->addIndex<2>(ord416, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lnot"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lne");
  if (r == 0) db->addStruct("lne", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lne");
      std::vector<u16> ord417({1, 2, 0});
    
    r->addIndex<3>(ord417, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord418({0, 1, 2});
    
    r->addIndex<3>(ord418, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lne"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lmul");
  if (r == 0) db->addStruct("lmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lmul");
      std::vector<u16> ord419({1, 2, 0});
    
    r->addIndex<3>(ord419, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord420({0, 1, 2});
    
    r->addIndex<3>(ord420, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lmul"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("llt");
  if (r == 0) db->addStruct("llt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("llt");
      std::vector<u16> ord421({1, 2, 0});
    
    r->addIndex<3>(ord421, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord422({0, 2, 1});
    
    r->addIndex<3>(ord422, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord423({2, 0, 1});
    
    r->addIndex<3>(ord423, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord424({0, 2, 1});
    
    r->addIndex<3>(ord424, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
      std::vector<u16> ord425({1, 2, 0});
    
    r->addIndex<3>(ord425, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("llt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lle");
  if (r == 0) db->addStruct("lle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lle");
      std::vector<u16> ord426({1, 2, 0});
    
    r->addIndex<3>(ord426, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord427({0, 1, 2});
    
    r->addIndex<3>(ord427, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lle"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lite");
  if (r == 0) db->addStruct("lite", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lite");
      std::vector<u16> ord428({1, 2, 3, 0});
    
    r->addIndex<4>(ord428, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord429({0, 1, 2, 3});
    
    r->addIndex<4>(ord429, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("lite"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("limplies");
  if (r == 0) db->addStruct("limplies", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("limplies");
      std::vector<u16> ord430({1, 2, 0});
    
    r->addIndex<3>(ord430, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord431({0, 1, 2});
    
    r->addIndex<3>(ord431, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("limplies"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lgt");
  if (r == 0) db->addStruct("lgt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lgt");
      std::vector<u16> ord432({1, 2, 0});
    
    r->addIndex<3>(ord432, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord433({0, 1, 2});
    
    r->addIndex<3>(ord433, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lgt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lge");
  if (r == 0) db->addStruct("lge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lge");
      std::vector<u16> ord434({1, 2, 0});
    
    r->addIndex<3>(ord434, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord435({0, 1, 2});
    
    r->addIndex<3>(ord435, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lge"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("leq");
  if (r == 0) db->addStruct("leq", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leq");
      std::vector<u16> ord436({1, 2, 0});
    
    r->addIndex<3>(ord436, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord437({0, 1, 2});
    
    r->addIndex<3>(ord437, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("leq"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lany");
  if (r == 0) db->addStruct("lany", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lany");
      std::vector<u16> ord438({1, 0});
    
    r->addIndex<2>(ord438, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord439({0, 1});
    
    r->addIndex<2>(ord439, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lany"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("land");
  if (r == 0) db->addStruct("land", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("land");
      std::vector<u16> ord440({1, 2, 0});
    
    r->addIndex<3>(ord440, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord441({0, 1, 2});
    
    r->addIndex<3>(ord441, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("land"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lall");
  if (r == 0) db->addStruct("lall", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lall");
      std::vector<u16> ord442({1, 0});
    
    r->addIndex<2>(ord442, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord443({0, 1});
    
    r->addIndex<2>(ord443, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lall"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ladd");
  if (r == 0) db->addStruct("ladd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ladd");
      std::vector<u16> ord444({1, 2, 0});
    
    r->addIndex<3>(ord444, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord445({0, 1, 2});
    
    r->addIndex<3>(ord445, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ladd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("iv");
  if (r == 0) db->addStruct("iv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("iv");
      std::vector<u16> ord446({1, 0});
    
    r->addIndex<2>(ord446, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord447({0, 1});
    
    r->addIndex<2>(ord447, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("iv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord448({1, 2, 3, 0});
    
    r->addIndex<4>(ord448, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord449({0, 1, 2, 3});
    
    r->addIndex<4>(ord449, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ic");
  if (r == 0) db->addStruct("ic", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ic");
      std::vector<u16> ord450({1, 0});
    
    r->addIndex<2>(ord450, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord451({0, 1});
    
    r->addIndex<2>(ord451, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord452({0, 1});
    
    r->addIndex<2>(ord452, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord453({1, 0});
    
    r->addIndex<2>(ord453, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ic"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord454({0});
    
    r->addIndex<1>(ord454, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord455({1, 2, 0});
    
    r->addIndex<3>(ord455, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord456({0, 1, 2});
    
    r->addIndex<3>(ord456, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("count");
  if (r == 0) db->addRelation("count", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("count");
      std::vector<u16> ord457({0});
    
    r->addIndex<1>(ord457, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("count"), std::array<u16,1>{0}, b));
  r = db->getRelation("bv");
  if (r == 0) db->addStruct("bv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bv");
      std::vector<u16> ord458({1, 0});
    
    r->addIndex<2>(ord458, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord459({0, 1});
    
    r->addIndex<2>(ord459, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("bv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord460({1, 0});
    
    r->addIndex<2>(ord460, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord461({0, 1});
    
    r->addIndex<2>(ord461, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  d->bindOracle(s, "smtcore", "smt_qcore", "smt_qcore_ans");
  d->bindOracle(s, "smtmodel", "smt_qmodel", "smt_qmodel_ans");
  d->bindOracle(s, "smt", "smt_qsat", "smt_qsat_ans");
  // (crule (pre) (scan modulo_by_zero __erre0kpy104 __errf6qDw105 __errf18v2106) (body) (head (emit error (0) __erre0kpy104)) <internal>:1 #f)
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
      outer_rel = db->getRelation("modulo_by_zero");
  
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
  // (crule (pre) (scan smt_qsat_ans __t4qM312 C) (body (join smt_vcode (0 1) 1 C V) (join-old smt_qsat (0 1) 1 (0 1) __t4qM312 F) (join-old smt_check (1 0) 1 (1 0) F __t2rRK11)) (head (emit smt_check_ans (0 1) __t2rRK11 V)) smt.slog:69 #f)
  class ReadTask8 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_vcodeindex3;  slog::Index** smt_qsatindex4;  slog::Index** smt_checkindex5;  slog::Index** smt_qsatdelta6;  slog::Index** smt_checkdelta7;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check_ans");
      std::vector<u16> ord9({0, 1});
      slog::Relation* readrel10 = db->getRelation("smt_check_ans");
      head_index[0] = readrel10->getIndex(ord9, false);
      outer_rel = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord11({0, 1});
      slog::Relation* readrel12 = db->getRelation("smt_vcode");
      smt_vcodeindex3 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({0, 1});
      slog::Relation* readrel14 = db->getRelation("smt_qsat");
      smt_qsatindex4 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("smt_qsat");
      smt_qsatdelta6 = readrel16->getIndex(ord15, true);
      std::vector<u16> ord17({1, 0});
      slog::Relation* readrel18 = db->getRelation("smt_check");
      smt_checkindex5 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("smt_check");
      smt_checkdelta7 = readrel20->getIndex(ord19, true);
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[1];
        slog::join_probe<2,1>(smt_vcodeindex3, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m21) {
          u64 v_c5 = m21[1];
          slog::join_probe_old<2,1>(smt_qsatindex4, smt_qsatdelta6, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m22) {
            u64 v_c6 = m22[1];
            slog::join_probe_old<2,1>(smt_checkindex5, smt_checkdelta7, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m23) {
              u64 v_c7 = m23[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c5}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_qsat_ans", _fires);
  
      if (!_done)
      {
        ReadTask8* _cont = new ReadTask8(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask8(db,b), false);
  // (crule (pre (let __tconst3xYQ35 const4b227777d4dd1fc61c6f884f)) (scan temp5QcX135 __t5ytA37) (body (exists llt (1 2 0) 1 __t5ytA37) (join ic (1 0) 1 __tconst3xYQ35 __t3XrF36) (join llt (1 2 0) 2 __t5ytA37 __t3XrF36 __t3x9h38)) (head (mkstruct smt_check (1 0) __5Dsw46 __t3x9h38)) smt_rec.slog:10 #f)
  class ReadTask27 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lltindex24;  slog::Index** icindex25;  slog::Index** lltindex26;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("temp5QcX135");
      std::vector<u16> ord28({1, 2, 0});
      slog::Relation* readrel29 = db->getRelation("llt");
      lltindex24 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 0});
      slog::Relation* readrel31 = db->getRelation("ic");
      icindex25 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 2, 0});
      slog::Relation* readrel33 = db->getRelation("llt");
      lltindex26 = readrel33->getIndex(ord32, false);
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c8 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        if (!slog::exists_probe<3,1>(lltindex24, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe<2,1>(icindex25, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m34) {
          u64 v_c10 = m34[1];
          slog::join_probe<3,2>(lltindex26, std::array<u64,3>{v_c9, v_c10, 0}, [&](const std::array<u64,3>& m35) {
            u64 v_c11 = m35[2];
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rec.slog:10", "delta:temp5QcX135", _fires);
  
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
  // (crule (pre (let __tconst9e7052 constab76c7d069d6f33dc950fb33) (let __tconst3Smn28 const6b86b273ff34fce19d6b804e) (let __tconst8C3E30 const4b227777d4dd1fc61c6f884f)) (probe ic (1 0) 1 __tconst8C3E30 __t9cXH31) (body (exists llt (2 0 1) 1 __t9cXH31) (join _enum (1 0) 1 __tconst9e7052 __v0) (join smt_check_ans (1 0) 1 __v0 __t3jiB34) (join-old smt_check (0 1) 1 (0 1) __t3jiB34 __t9ZeF33) (join-old llt (0 2 1) 2 (0 2 1) __t9ZeF33 __t9cXH31 __t6wBA32) (join-old ic (0 1) 1 (0 1) __t6wBA32 N) (join count (0) 1 N) (let __t1YkO29 (_0002b N __tconst3Smn28))) (head (emit count (0) __t1YkO29)) smt_rec.slog:10 #f)
  class ReadTask46 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex36;  slog::Index** _enumindex37;  slog::Index** smt_check_ansindex38;  slog::Index** smt_checkindex39;  slog::Index** lltindex40;  slog::Index** icindex41;  slog::Index** countindex42;  slog::Index** smt_checkdelta43;  slog::Index** lltdelta44;  slog::Index** icdelta45;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("count");
      std::vector<u16> ord47({0});
      slog::Relation* readrel48 = db->getRelation("count");
      head_index[0] = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 0});
      slog::Relation* readrel50 = db->getRelation("ic");
      driver_index = readrel50->getIndex(ord49, true);
      std::vector<u16> ord51({2, 0, 1});
      slog::Relation* readrel52 = db->getRelation("llt");
      lltindex36 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 0});
      slog::Relation* readrel54 = db->getRelation("_enum");
      _enumindex37 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 0});
      slog::Relation* readrel56 = db->getRelation("smt_check_ans");
      smt_check_ansindex38 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("smt_check");
      smt_checkindex39 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({0, 1});
      slog::Relation* readrel60 = db->getRelation("smt_check");
      smt_checkdelta43 = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({0, 2, 1});
      slog::Relation* readrel62 = db->getRelation("llt");
      lltindex40 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({0, 2, 1});
      slog::Relation* readrel64 = db->getRelation("llt");
      lltdelta44 = readrel64->getIndex(ord63, true);
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("ic");
      icindex41 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({0, 1});
      slog::Relation* readrel68 = db->getRelation("ic");
      icdelta45 = readrel68->getIndex(ord67, true);
      std::vector<u16> ord69({0});
      slog::Relation* readrel70 = db->getRelation("count");
      countindex42 = readrel70->getIndex(ord69, false);
  
    }
    ReadTask46(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c14, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m71) {
        u64 v_c15 = m71[1];
        if (buckethash(v_c15) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex36, std::array<u64,3>{v_c15, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex37, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m72) {
          u64 v_c16 = m72[1];
          slog::join_probe<2,1>(smt_check_ansindex38, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m73) {
            u64 v_c17 = m73[1];
            slog::join_probe_old<2,1>(smt_checkindex39, smt_checkdelta43, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m74) {
              u64 v_c18 = m74[1];
              slog::join_probe_old<3,2>(lltindex40, lltdelta44, std::array<u64,3>{v_c18, v_c15, 0}, [&](const std::array<u64,3>& m75) {
                u64 v_c19 = m75[2];
                slog::join_probe_old<2,1>(icindex41, icdelta45, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m76) {
                  u64 v_c20 = m76[1];
                  slog::join_probe<1,1>(countindex42, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m77) {
                    u64 v_c21 = _prim__0002b(db, v_c20, v_c13);
                    if (v_c21 == slog_error) { slog::emit_pending_error(db, "smt_rec.slog:10"); return; }
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rec.slog:10", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask46* _cont = new ReadTask46(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask46(db,b), false);
  // (crule (pre) (scan smt_check __t1QFP1 F) (body (join smt_vcode (0 1) 0 C V)) (head (mkstruct smt_qsat (1 0) __6CuH47 F)) smt.slog:69 #f)
  class ReadTask79 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_vcodeindex78;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_qsat");
      outer_rel = db->getRelation("smt_check");
      std::vector<u16> ord80({0, 1});
      slog::Relation* readrel81 = db->getRelation("smt_vcode");
      smt_vcodeindex78 = readrel81->getIndex(ord80, false);
  
    }
    ReadTask79(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[0];
        u64 v_c6 = _t[1];
        slog::join_all<2>(smt_vcodeindex78, [&](const std::array<u64,2>& m82) {
          u64 v_c4 = m82[0]; u64 v_c5 = m82[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c6}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_check", _fires);
  
      if (!_done)
      {
        ReadTask79* _cont = new ReadTask79(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask79(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre2g5U123 __errf2SUi124 __errf1oEh125 __errf05uH126 __errf4tXV127) (body) (head (emit error (0) __erre2g5U123)) <internal>:1 #f)
  class ReadTask83 : public slog::Task
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
      std::vector<u16> ord84({0});
      slog::Relation* readrel85 = db->getRelation("error");
      head_index[0] = readrel85->getIndex(ord84, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask83(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c27 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask83* _cont = new ReadTask83(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask83(db,b), false);
  // (crule (pre (let __tconst5llD39 const6b86b273ff34fce19d6b804e) (let __tconst3xYQ35 const4b227777d4dd1fc61c6f884f)) (scan count N) (body (let __t3hoI40 (_0002b N __tconst5llD39))) (head (emit-temp temp43NC134 N) (mkstruct ic (1 0) __t3XrF36 __tconst3xYQ35) (mkstruct ic (1 0) __t5ytA37 N)) smt_rec.slog:10 #f)
  class ReadTask86 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp43NC134");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
      outer_rel = db->getRelation("count");
  
    }
    ReadTask86(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c28 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        u64 v_c29 = _prim__0002b(db, v_c20, v_c28);
        if (v_c29 == slog_error) { slog::emit_pending_error(db, "smt_rec.slog:10"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c20});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_rec.slog:10", "delta:count", _fires);
  
      if (!_done)
      {
        ReadTask86* _cont = new ReadTask86(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask86(db,b), false);
  // (crule (pre) (scan toint_range __erre6xLt115 __errf0g15116 __errf954i117) (body) (head (emit error (0) __erre6xLt115)) <internal>:1 #f)
  class ReadTask87 : public slog::Task
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
      std::vector<u16> ord88({0});
      slog::Relation* readrel89 = db->getRelation("error");
      head_index[0] = readrel89->getIndex(ord88, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask87(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask87* _cont = new ReadTask87(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask87(db,b), false);
  // (crule (pre (let __tconst9e7052 constab76c7d069d6f33dc950fb33) (let __tconst3Smn28 const6b86b273ff34fce19d6b804e) (let __tconst8C3E30 const4b227777d4dd1fc61c6f884f)) (scan smt_check __t3jiB34 __t9ZeF33) (body (exists smt_check_ans (0 1) 1 __t3jiB34) (exists ic (1 0) 1 __tconst8C3E30) (join _enum (1 0) 1 __tconst9e7052 __v0) (join smt_check_ans (0 1) 2 __t3jiB34 __v0) (join ic (1 0) 1 __tconst8C3E30 __t9cXH31) (join llt (0 2 1) 2 __t9ZeF33 __t9cXH31 __t6wBA32) (join ic (0 1) 1 __t6wBA32 N) (join count (0) 1 N) (let __t1YkO29 (_0002b N __tconst3Smn28))) (head (emit count (0) __t1YkO29)) smt_rec.slog:10 #f)
  class ReadTask98 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_check_ansindex90;  slog::Index** icindex91;  slog::Index** _enumindex92;  slog::Index** smt_check_ansindex93;  slog::Index** icindex94;  slog::Index** lltindex95;  slog::Index** icindex96;  slog::Index** countindex97;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("count");
      std::vector<u16> ord99({0});
      slog::Relation* readrel100 = db->getRelation("count");
      head_index[0] = readrel100->getIndex(ord99, false);
      outer_rel = db->getRelation("smt_check");
      std::vector<u16> ord101({0, 1});
      slog::Relation* readrel102 = db->getRelation("smt_check_ans");
      smt_check_ansindex90 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 0});
      slog::Relation* readrel104 = db->getRelation("ic");
      icindex91 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 0});
      slog::Relation* readrel106 = db->getRelation("_enum");
      _enumindex92 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("smt_check_ans");
      smt_check_ansindex93 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 0});
      slog::Relation* readrel110 = db->getRelation("ic");
      icindex94 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 2, 1});
      slog::Relation* readrel112 = db->getRelation("llt");
      lltindex95 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({0, 1});
      slog::Relation* readrel114 = db->getRelation("ic");
      icindex96 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0});
      slog::Relation* readrel116 = db->getRelation("count");
      countindex97 = readrel116->getIndex(ord115, false);
  
    }
    ReadTask98(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_const4b227777d4dd1fc61c6f884f;
  
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
        if (!slog::exists_probe<2,1>(smt_check_ansindex90, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(icindex91, std::array<u64,2>{v_c14, 0})) return;
        slog::join_probe<2,1>(_enumindex92, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m117) {
          u64 v_c16 = m117[1];
          slog::join_probe<2,2>(smt_check_ansindex93, std::array<u64,2>{v_c17, v_c16}, [&](const std::array<u64,2>& m118) {
            slog::join_probe<2,1>(icindex94, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m119) {
              u64 v_c15 = m119[1];
              slog::join_probe<3,2>(lltindex95, std::array<u64,3>{v_c18, v_c15, 0}, [&](const std::array<u64,3>& m120) {
                u64 v_c19 = m120[2];
                slog::join_probe<2,1>(icindex96, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m121) {
                  u64 v_c20 = m121[1];
                  slog::join_probe<1,1>(countindex97, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m122) {
                    u64 v_c21 = _prim__0002b(db, v_c20, v_c13);
                    if (v_c21 == slog_error) { slog::emit_pending_error(db, "smt_rec.slog:10"); return; }
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rec.slog:10", "delta:smt_check", _fires);
  
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
  // (crule (pre) (scan nan_result __erre4eV4111 __errf6Lu8112 __errf8Lvc113 __errf6SB3114) (body) (head (emit error (0) __erre4eV4111)) <internal>:1 #f)
  class ReadTask123 : public slog::Task
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
      std::vector<u16> ord124({0});
      slog::Relation* readrel125 = db->getRelation("error");
      head_index[0] = readrel125->getIndex(ord124, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask123(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c33}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre (let __tconst9e7052 constab76c7d069d6f33dc950fb33) (let __tconst3Smn28 const6b86b273ff34fce19d6b804e) (let __tconst8C3E30 const4b227777d4dd1fc61c6f884f)) (scan llt __t9ZeF33 __t6wBA32 __t9cXH31) (body (join ic (0 1) 2 __t9cXH31 __tconst8C3E30) (exists smt_check (1 0) 1 __t9ZeF33) (join _enum (1 0) 1 __tconst9e7052 __v0) (join smt_check_ans (1 0) 1 __v0 __t3jiB34) (join-old smt_check (0 1) 2 (0 1) __t3jiB34 __t9ZeF33) (join ic (0 1) 1 __t6wBA32 N) (join count (0) 1 N) (let __t1YkO29 (_0002b N __tconst3Smn28))) (head (emit count (0) __t1YkO29)) smt_rec.slog:10 #f)
  class ReadTask134 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex126;  slog::Index** smt_checkindex127;  slog::Index** _enumindex128;  slog::Index** smt_check_ansindex129;  slog::Index** smt_checkindex130;  slog::Index** icindex131;  slog::Index** countindex132;  slog::Index** smt_checkdelta133;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("count");
      std::vector<u16> ord135({0});
      slog::Relation* readrel136 = db->getRelation("count");
      head_index[0] = readrel136->getIndex(ord135, false);
      outer_rel = db->getRelation("llt");
      std::vector<u16> ord137({0, 1});
      slog::Relation* readrel138 = db->getRelation("ic");
      icindex126 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 0});
      slog::Relation* readrel140 = db->getRelation("smt_check");
      smt_checkindex127 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 0});
      slog::Relation* readrel142 = db->getRelation("_enum");
      _enumindex128 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 0});
      slog::Relation* readrel144 = db->getRelation("smt_check_ans");
      smt_check_ansindex129 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("smt_check");
      smt_checkindex130 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({0, 1});
      slog::Relation* readrel148 = db->getRelation("smt_check");
      smt_checkdelta133 = readrel148->getIndex(ord147, true);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("ic");
      icindex131 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({0});
      slog::Relation* readrel152 = db->getRelation("count");
      countindex132 = readrel152->getIndex(ord151, false);
  
    }
    ReadTask134(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_const4b227777d4dd1fc61c6f884f;
  
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
        u64 v_c15 = _t[2];
        slog::join_probe<2,2>(icindex126, std::array<u64,2>{v_c15, v_c14}, [&](const std::array<u64,2>& m153) {
          if (!slog::exists_probe<2,1>(smt_checkindex127, std::array<u64,2>{v_c18, 0})) return;
          slog::join_probe<2,1>(_enumindex128, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m154) {
            u64 v_c16 = m154[1];
            slog::join_probe<2,1>(smt_check_ansindex129, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m155) {
              u64 v_c17 = m155[1];
              slog::join_probe_old<2,2>(smt_checkindex130, smt_checkdelta133, std::array<u64,2>{v_c17, v_c18}, [&](const std::array<u64,2>& m156) {
                slog::join_probe<2,1>(icindex131, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m157) {
                  u64 v_c20 = m157[1];
                  slog::join_probe<1,1>(countindex132, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m158) {
                    u64 v_c21 = _prim__0002b(db, v_c20, v_c13);
                    if (v_c21 == slog_error) { slog::emit_pending_error(db, "smt_rec.slog:10"); return; }
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rec.slog:10", "delta:llt", _fires);
  
      if (!_done)
      {
        ReadTask134* _cont = new ReadTask134(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask134(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre9uCc128 __errf3gd1129 __errf10UX130) (body) (head (emit error (0) __erre9uCc128)) <internal>:1 #f)
  class ReadTask159 : public slog::Task
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
      std::vector<u16> ord160({0});
      slog::Relation* readrel161 = db->getRelation("error");
      head_index[0] = readrel161->getIndex(ord160, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask159(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c39 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c37}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask159* _cont = new ReadTask159(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask159(db,b), false);
  // (crule (pre (let __tconst2wBY43 const5feceb66ffc86f38d952786c)) (once) (body) (head (emit count (0) __tconst2wBY43)) smt_rec.slog:9 #f)
  class ReadTask162 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("count");
      std::vector<u16> ord163({0});
      slog::Relation* readrel164 = db->getRelation("count");
      head_index[0] = readrel164->getIndex(ord163, false);
  
    }
    ReadTask162(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c40}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rec.slog:9", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask162(db,b), true);
  // (crule (pre) (scan smt_bad_formula __erre8Mmx131 __errf0sDL132 __errf40yI133) (body) (head (emit error (0) __erre8Mmx131)) <internal>:1 #f)
  class ReadTask165 : public slog::Task
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
      std::vector<u16> ord166({0});
      slog::Relation* readrel167 = db->getRelation("error");
      head_index[0] = readrel167->getIndex(ord166, false);
      outer_rel = db->getRelation("smt_bad_formula");
  
    }
    ReadTask165(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c43 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c41}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:smt_bad_formula", _fires);
  
      if (!_done)
      {
        ReadTask165* _cont = new ReadTask165(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask165(db,b), false);
  // (crule (pre (let __tconst9e7052 constab76c7d069d6f33dc950fb33) (let __tconst3Smn28 const6b86b273ff34fce19d6b804e) (let __tconst8C3E30 const4b227777d4dd1fc61c6f884f)) (scan smt_check_ans __t3jiB34 __v0) (body (join _enum (0 1) 2 __v0 __tconst9e7052) (join-old ic (1 0) 1 (1 0) __tconst8C3E30 __t9cXH31) (exists llt (2 0 1) 1 __t9cXH31) (join-old smt_check (0 1) 1 (0 1) __t3jiB34 __t9ZeF33) (join-old llt (0 2 1) 2 (0 2 1) __t9ZeF33 __t9cXH31 __t6wBA32) (join-old ic (0 1) 1 (0 1) __t6wBA32 N) (join count (0) 1 N) (let __t1YkO29 (_0002b N __tconst3Smn28))) (head (emit count (0) __t1YkO29)) smt_rec.slog:10 #f)
  class ReadTask179 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex168;  slog::Index** icindex169;  slog::Index** lltindex170;  slog::Index** smt_checkindex171;  slog::Index** lltindex172;  slog::Index** icindex173;  slog::Index** countindex174;  slog::Index** icdelta175;  slog::Index** smt_checkdelta176;  slog::Index** lltdelta177;  slog::Index** icdelta178;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("count");
      std::vector<u16> ord180({0});
      slog::Relation* readrel181 = db->getRelation("count");
      head_index[0] = readrel181->getIndex(ord180, false);
      outer_rel = db->getRelation("smt_check_ans");
      std::vector<u16> ord182({0, 1});
      slog::Relation* readrel183 = db->getRelation("_enum");
      _enumindex168 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 0});
      slog::Relation* readrel185 = db->getRelation("ic");
      icindex169 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 0});
      slog::Relation* readrel187 = db->getRelation("ic");
      icdelta175 = readrel187->getIndex(ord186, true);
      std::vector<u16> ord188({2, 0, 1});
      slog::Relation* readrel189 = db->getRelation("llt");
      lltindex170 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("smt_check");
      smt_checkindex171 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("smt_check");
      smt_checkdelta176 = readrel193->getIndex(ord192, true);
      std::vector<u16> ord194({0, 2, 1});
      slog::Relation* readrel195 = db->getRelation("llt");
      lltindex172 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({0, 2, 1});
      slog::Relation* readrel197 = db->getRelation("llt");
      lltdelta177 = readrel197->getIndex(ord196, true);
      std::vector<u16> ord198({0, 1});
      slog::Relation* readrel199 = db->getRelation("ic");
      icindex173 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({0, 1});
      slog::Relation* readrel201 = db->getRelation("ic");
      icdelta178 = readrel201->getIndex(ord200, true);
      std::vector<u16> ord202({0});
      slog::Relation* readrel203 = db->getRelation("count");
      countindex174 = readrel203->getIndex(ord202, false);
  
    }
    ReadTask179(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c17 = _t[0];
        u64 v_c16 = _t[1];
        slog::join_probe<2,2>(_enumindex168, std::array<u64,2>{v_c16, v_c12}, [&](const std::array<u64,2>& m204) {
          slog::join_probe_old<2,1>(icindex169, icdelta175, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m205) {
            u64 v_c15 = m205[1];
            if (!slog::exists_probe<3,1>(lltindex170, std::array<u64,3>{v_c15, 0, 0})) return;
            slog::join_probe_old<2,1>(smt_checkindex171, smt_checkdelta176, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m206) {
              u64 v_c18 = m206[1];
              slog::join_probe_old<3,2>(lltindex172, lltdelta177, std::array<u64,3>{v_c18, v_c15, 0}, [&](const std::array<u64,3>& m207) {
                u64 v_c19 = m207[2];
                slog::join_probe_old<2,1>(icindex173, icdelta178, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m208) {
                  u64 v_c20 = m208[1];
                  slog::join_probe<1,1>(countindex174, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m209) {
                    u64 v_c21 = _prim__0002b(db, v_c20, v_c13);
                    if (v_c21 == slog_error) { slog::emit_pending_error(db, "smt_rec.slog:10"); return; }
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rec.slog:10", "delta:smt_check_ans", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre0EXr101 __errf3H2v102 __errf7SbY103) (body) (head (emit error (0) __erre0EXr101)) <internal>:1 #f)
  class ReadTask210 : public slog::Task
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
      std::vector<u16> ord211({0});
      slog::Relation* readrel212 = db->getRelation("error");
      head_index[0] = readrel212->getIndex(ord211, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask210(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c46 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c44}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask210* _cont = new ReadTask210(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask210(db,b), false);
  // (crule (pre) (scan int_overflow __erre2RtS107 __errf7GC5108 __errf42Az109 __errf3edu110) (body) (head (emit error (0) __erre2RtS107)) <internal>:1 #f)
  class ReadTask213 : public slog::Task
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
      std::vector<u16> ord214({0});
      slog::Relation* readrel215 = db->getRelation("error");
      head_index[0] = readrel215->getIndex(ord214, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask213(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c47 = _t[0];
        u64 v_c48 = _t[1];
        u64 v_c49 = _t[2];
        u64 v_c50 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c47}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask213* _cont = new ReadTask213(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask213(db,b), false);
  // (crule (pre (let __tconst9e7052 constab76c7d069d6f33dc950fb33) (let __tconst3Smn28 const6b86b273ff34fce19d6b804e) (let __tconst8C3E30 const4b227777d4dd1fc61c6f884f)) (scan ic __t6wBA32 N) (body (join count (0) 1 N) (exists ic (1 0) 1 __tconst8C3E30) (exists llt (1 2 0) 1 __t6wBA32) (join _enum (1 0) 1 __tconst9e7052 __v0) (join smt_check_ans (1 0) 1 __v0 __t3jiB34) (join ic (1 0) 1 __tconst8C3E30 __t9cXH31) (join-old llt (1 2 0) 2 (1 2 0) __t6wBA32 __t9cXH31 __t9ZeF33) (join-old smt_check (0 1) 2 (0 1) __t3jiB34 __t9ZeF33) (let __t1YkO29 (_0002b N __tconst3Smn28))) (head (emit count (0) __t1YkO29)) smt_rec.slog:10 #f)
  class ReadTask226 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** countindex216;  slog::Index** icindex217;  slog::Index** lltindex218;  slog::Index** _enumindex219;  slog::Index** smt_check_ansindex220;  slog::Index** icindex221;  slog::Index** lltindex222;  slog::Index** smt_checkindex223;  slog::Index** lltdelta224;  slog::Index** smt_checkdelta225;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("count");
      std::vector<u16> ord227({0});
      slog::Relation* readrel228 = db->getRelation("count");
      head_index[0] = readrel228->getIndex(ord227, false);
      outer_rel = db->getRelation("ic");
      std::vector<u16> ord229({0});
      slog::Relation* readrel230 = db->getRelation("count");
      countindex216 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 0});
      slog::Relation* readrel232 = db->getRelation("ic");
      icindex217 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 2, 0});
      slog::Relation* readrel234 = db->getRelation("llt");
      lltindex218 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 0});
      slog::Relation* readrel236 = db->getRelation("_enum");
      _enumindex219 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 0});
      slog::Relation* readrel238 = db->getRelation("smt_check_ans");
      smt_check_ansindex220 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 0});
      slog::Relation* readrel240 = db->getRelation("ic");
      icindex221 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({1, 2, 0});
      slog::Relation* readrel242 = db->getRelation("llt");
      lltindex222 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 2, 0});
      slog::Relation* readrel244 = db->getRelation("llt");
      lltdelta224 = readrel244->getIndex(ord243, true);
      std::vector<u16> ord245({0, 1});
      slog::Relation* readrel246 = db->getRelation("smt_check");
      smt_checkindex223 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({0, 1});
      slog::Relation* readrel248 = db->getRelation("smt_check");
      smt_checkdelta225 = readrel248->getIndex(ord247, true);
  
    }
    ReadTask226(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_const4b227777d4dd1fc61c6f884f;
  
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
        slog::join_probe<1,1>(countindex216, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m249) {
          if (!slog::exists_probe<2,1>(icindex217, std::array<u64,2>{v_c14, 0})) return;
          if (!slog::exists_probe<3,1>(lltindex218, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe<2,1>(_enumindex219, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m250) {
            u64 v_c16 = m250[1];
            slog::join_probe<2,1>(smt_check_ansindex220, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m251) {
              u64 v_c17 = m251[1];
              slog::join_probe<2,1>(icindex221, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m252) {
                u64 v_c15 = m252[1];
                slog::join_probe_old<3,2>(lltindex222, lltdelta224, std::array<u64,3>{v_c19, v_c15, 0}, [&](const std::array<u64,3>& m253) {
                  u64 v_c18 = m253[2];
                  slog::join_probe_old<2,2>(smt_checkindex223, smt_checkdelta225, std::array<u64,2>{v_c17, v_c18}, [&](const std::array<u64,2>& m254) {
                    u64 v_c21 = _prim__0002b(db, v_c20, v_c13);
                    if (v_c21 == slog_error) { slog::emit_pending_error(db, "smt_rec.slog:10"); return; }
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rec.slog:10", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask226* _cont = new ReadTask226(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask226(db,b), false);
  // (crule (pre) (scan smt_check __t2rRK11 F) (body (join-old smt_qsat (1 0) 1 (1 0) F __t4qM312) (join smt_qsat_ans (0 1) 1 __t4qM312 C) (join smt_vcode (0 1) 1 C V)) (head (emit smt_check_ans (0 1) __t2rRK11 V)) smt.slog:69 #f)
  class ReadTask259 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_qsatindex255;  slog::Index** smt_qsat_ansindex256;  slog::Index** smt_vcodeindex257;  slog::Index** smt_qsatdelta258;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check_ans");
      std::vector<u16> ord260({0, 1});
      slog::Relation* readrel261 = db->getRelation("smt_check_ans");
      head_index[0] = readrel261->getIndex(ord260, false);
      outer_rel = db->getRelation("smt_check");
      std::vector<u16> ord262({1, 0});
      slog::Relation* readrel263 = db->getRelation("smt_qsat");
      smt_qsatindex255 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 0});
      slog::Relation* readrel265 = db->getRelation("smt_qsat");
      smt_qsatdelta258 = readrel265->getIndex(ord264, true);
      std::vector<u16> ord266({0, 1});
      slog::Relation* readrel267 = db->getRelation("smt_qsat_ans");
      smt_qsat_ansindex256 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({0, 1});
      slog::Relation* readrel269 = db->getRelation("smt_vcode");
      smt_vcodeindex257 = readrel269->getIndex(ord268, false);
  
    }
    ReadTask259(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        slog::join_probe_old<2,1>(smt_qsatindex255, smt_qsatdelta258, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m270) {
          u64 v_c3 = m270[1];
          slog::join_probe<2,1>(smt_qsat_ansindex256, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m271) {
            u64 v_c4 = m271[1];
            slog::join_probe<2,1>(smt_vcodeindex257, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m272) {
              u64 v_c5 = m272[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c5}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_check", _fires);
  
      if (!_done)
      {
        ReadTask259* _cont = new ReadTask259(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask259(db,b), false);
  // (crule (pre) (scan smt_qsat __t4qM312 F) (body (exists smt_check (1 0) 1 F) (join smt_qsat_ans (0 1) 1 __t4qM312 C) (join smt_vcode (0 1) 1 C V) (join smt_check (1 0) 1 F __t2rRK11)) (head (emit smt_check_ans (0 1) __t2rRK11 V)) smt.slog:69 #f)
  class ReadTask277 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_checkindex273;  slog::Index** smt_qsat_ansindex274;  slog::Index** smt_vcodeindex275;  slog::Index** smt_checkindex276;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check_ans");
      std::vector<u16> ord278({0, 1});
      slog::Relation* readrel279 = db->getRelation("smt_check_ans");
      head_index[0] = readrel279->getIndex(ord278, false);
      outer_rel = db->getRelation("smt_qsat");
      std::vector<u16> ord280({1, 0});
      slog::Relation* readrel281 = db->getRelation("smt_check");
      smt_checkindex273 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({0, 1});
      slog::Relation* readrel283 = db->getRelation("smt_qsat_ans");
      smt_qsat_ansindex274 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({0, 1});
      slog::Relation* readrel285 = db->getRelation("smt_vcode");
      smt_vcodeindex275 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 0});
      slog::Relation* readrel287 = db->getRelation("smt_check");
      smt_checkindex276 = readrel287->getIndex(ord286, false);
  
    }
    ReadTask277(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<2,1>(smt_checkindex273, std::array<u64,2>{v_c6, 0})) return;
        slog::join_probe<2,1>(smt_qsat_ansindex274, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m288) {
          u64 v_c4 = m288[1];
          slog::join_probe<2,1>(smt_vcodeindex275, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m289) {
            u64 v_c5 = m289[1];
            slog::join_probe<2,1>(smt_checkindex276, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m290) {
              u64 v_c7 = m290[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c5}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_qsat", _fires);
  
      if (!_done)
      {
        ReadTask277* _cont = new ReadTask277(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask277(db,b), false);
  // (crule (pre (let __tconst9e7052 constab76c7d069d6f33dc950fb33) (let __tconst3Smn28 const6b86b273ff34fce19d6b804e) (let __tconst8C3E30 const4b227777d4dd1fc61c6f884f)) (scan count N) (body (exists ic (1 0) 1 __tconst8C3E30) (exists ic (1 0) 1 N) (join _enum (1 0) 1 __tconst9e7052 __v0) (join-old smt_check_ans (1 0) 1 (1 0) __v0 __t3jiB34) (join-old ic (1 0) 1 (1 0) __tconst8C3E30 __t9cXH31) (exists llt (2 0 1) 1 __t9cXH31) (join-old ic (1 0) 1 (1 0) N __t6wBA32) (join-old llt (1 2 0) 2 (1 2 0) __t6wBA32 __t9cXH31 __t9ZeF33) (join-old smt_check (0 1) 2 (0 1) __t3jiB34 __t9ZeF33) (let __t1YkO29 (_0002b N __tconst3Smn28))) (head (emit count (0) __t1YkO29)) smt_rec.slog:10 #f)
  class ReadTask305 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex291;  slog::Index** icindex292;  slog::Index** _enumindex293;  slog::Index** smt_check_ansindex294;  slog::Index** icindex295;  slog::Index** lltindex296;  slog::Index** icindex297;  slog::Index** lltindex298;  slog::Index** smt_checkindex299;  slog::Index** smt_check_ansdelta300;  slog::Index** icdelta301;  slog::Index** icdelta302;  slog::Index** lltdelta303;  slog::Index** smt_checkdelta304;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("count");
      std::vector<u16> ord306({0});
      slog::Relation* readrel307 = db->getRelation("count");
      head_index[0] = readrel307->getIndex(ord306, false);
      outer_rel = db->getRelation("count");
      std::vector<u16> ord308({1, 0});
      slog::Relation* readrel309 = db->getRelation("ic");
      icindex291 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 0});
      slog::Relation* readrel311 = db->getRelation("ic");
      icindex292 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 0});
      slog::Relation* readrel313 = db->getRelation("_enum");
      _enumindex293 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 0});
      slog::Relation* readrel315 = db->getRelation("smt_check_ans");
      smt_check_ansindex294 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 0});
      slog::Relation* readrel317 = db->getRelation("smt_check_ans");
      smt_check_ansdelta300 = readrel317->getIndex(ord316, true);
      std::vector<u16> ord318({1, 0});
      slog::Relation* readrel319 = db->getRelation("ic");
      icindex295 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({1, 0});
      slog::Relation* readrel321 = db->getRelation("ic");
      icdelta301 = readrel321->getIndex(ord320, true);
      std::vector<u16> ord322({2, 0, 1});
      slog::Relation* readrel323 = db->getRelation("llt");
      lltindex296 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 0});
      slog::Relation* readrel325 = db->getRelation("ic");
      icindex297 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 0});
      slog::Relation* readrel327 = db->getRelation("ic");
      icdelta302 = readrel327->getIndex(ord326, true);
      std::vector<u16> ord328({1, 2, 0});
      slog::Relation* readrel329 = db->getRelation("llt");
      lltindex298 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 0});
      slog::Relation* readrel331 = db->getRelation("llt");
      lltdelta303 = readrel331->getIndex(ord330, true);
      std::vector<u16> ord332({0, 1});
      slog::Relation* readrel333 = db->getRelation("smt_check");
      smt_checkindex299 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({0, 1});
      slog::Relation* readrel335 = db->getRelation("smt_check");
      smt_checkdelta304 = readrel335->getIndex(ord334, true);
  
    }
    ReadTask305(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        if (!slog::exists_probe<2,1>(icindex291, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(icindex292, std::array<u64,2>{v_c20, 0})) return;
        slog::join_probe<2,1>(_enumindex293, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m336) {
          u64 v_c16 = m336[1];
          slog::join_probe_old<2,1>(smt_check_ansindex294, smt_check_ansdelta300, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m337) {
            u64 v_c17 = m337[1];
            slog::join_probe_old<2,1>(icindex295, icdelta301, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m338) {
              u64 v_c15 = m338[1];
              if (!slog::exists_probe<3,1>(lltindex296, std::array<u64,3>{v_c15, 0, 0})) return;
              slog::join_probe_old<2,1>(icindex297, icdelta302, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m339) {
                u64 v_c19 = m339[1];
                slog::join_probe_old<3,2>(lltindex298, lltdelta303, std::array<u64,3>{v_c19, v_c15, 0}, [&](const std::array<u64,3>& m340) {
                  u64 v_c18 = m340[2];
                  slog::join_probe_old<2,2>(smt_checkindex299, smt_checkdelta304, std::array<u64,2>{v_c17, v_c18}, [&](const std::array<u64,2>& m341) {
                    u64 v_c21 = _prim__0002b(db, v_c20, v_c13);
                    if (v_c21 == slog_error) { slog::emit_pending_error(db, "smt_rec.slog:10"); return; }
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rec.slog:10", "delta:count", _fires);
  
      if (!_done)
      {
        ReadTask305* _cont = new ReadTask305(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask305(db,b), false);
  // (crule (pre) (scan type_mismatch __erre7uWk118 __errf9QjG119 __errf5ekn120 __errf4jvr121 __errf0CVr122) (body) (head (emit error (0) __erre7uWk118)) <internal>:1 #f)
  class ReadTask342 : public slog::Task
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
      std::vector<u16> ord343({0});
      slog::Relation* readrel344 = db->getRelation("error");
      head_index[0] = readrel344->getIndex(ord343, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask342(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c51}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask342* _cont = new ReadTask342(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask342(db,b), false);
  // (crule (pre) (scan smt_vcode C V) (body (join smt_core (0 1) 0 __t4dw34 F)) (head (mkstruct smt_qcore (1 0) __7bBb56 F)) smt.slog:106 #f)
  class ReadTask346 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_coreindex345;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_qcore");
      outer_rel = db->getRelation("smt_vcode");
      std::vector<u16> ord347({0, 1});
      slog::Relation* readrel348 = db->getRelation("smt_core");
      smt_coreindex345 = readrel348->getIndex(ord347, false);
  
    }
    ReadTask346(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        slog::join_all<2>(smt_coreindex345, [&](const std::array<u64,2>& m349) {
          u64 v_c56 = m349[0]; u64 v_c6 = m349[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c6}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:106", "all:smt_vcode", _fires);
  
      if (!_done)
      {
        ReadTask346* _cont = new ReadTask346(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask346(db,b), true);
  // (crule (pre) (scan smt_vcode C V) (body (join smt_model (0 1) 0 __t3Jln44 F)) (head (mkstruct smt_qmodel (1 0) __2OSt45 F)) smt.slog:93 #f)
  class ReadTask351 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_modelindex350;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_qmodel");
      outer_rel = db->getRelation("smt_vcode");
      std::vector<u16> ord352({0, 1});
      slog::Relation* readrel353 = db->getRelation("smt_model");
      smt_modelindex350 = readrel353->getIndex(ord352, false);
  
    }
    ReadTask351(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        slog::join_all<2>(smt_modelindex350, [&](const std::array<u64,2>& m354) {
          u64 v_c57 = m354[0]; u64 v_c6 = m354[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c6}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:93", "all:smt_vcode", _fires);
  
      if (!_done)
      {
        ReadTask351* _cont = new ReadTask351(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask351(db,b), true);
  // (crule (pre (let __tconst3xYQ35 const4b227777d4dd1fc61c6f884f)) (scan temp43NC134 N) (body (exists ic (1 0) 1 __tconst3xYQ35) (join ic (1 0) 1 N __t5ytA37) (join ic (1 0) 1 __tconst3xYQ35 __t3XrF36)) (head (emit-temp temp5QcX135 __t5ytA37) (mkstruct llt (1 2 0) __t3x9h38 __t5ytA37 __t3XrF36)) smt_rec.slog:10 #f)
  class ReadTask358 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex355;  slog::Index** icindex356;  slog::Index** icindex357;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5QcX135");
      head_rel[1] = db->getRelation("llt");
      outer_rel = db->getRelation("temp43NC134");
      std::vector<u16> ord359({1, 0});
      slog::Relation* readrel360 = db->getRelation("ic");
      icindex355 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 0});
      slog::Relation* readrel362 = db->getRelation("ic");
      icindex356 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({1, 0});
      slog::Relation* readrel364 = db->getRelation("ic");
      icindex357 = readrel364->getIndex(ord363, false);
  
    }
    ReadTask358(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c8 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        if (!slog::exists_probe<2,1>(icindex355, std::array<u64,2>{v_c8, 0})) return;
        slog::join_probe<2,1>(icindex356, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m365) {
          u64 v_c9 = m365[1];
          slog::join_probe<2,1>(icindex357, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m366) {
            u64 v_c10 = m366[1];
            ++_fires;
            slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c9});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c9, v_c10}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_rec.slog:10", "delta:temp43NC134", _fires);
  
      if (!_done)
      {
        ReadTask358* _cont = new ReadTask358(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask358(db,b), false);
  s->addReadRel("_enum");
  s->addReadRel("count");
  s->addReadRel("div_by_zero");
  s->addReadRel("ic");
  s->addReadRel("int_overflow");
  s->addReadRel("llt");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("smt_bad_formula");
  s->addReadRel("smt_check");
  s->addReadRel("smt_check_ans");
  s->addReadRel("smt_core");
  s->addReadRel("smt_model");
  s->addReadRel("smt_qsat");
  s->addReadRel("smt_qsat_ans");
  s->addReadRel("smt_vcode");
  s->addReadRel("temp43NC134");
  s->addReadRel("temp5QcX135");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("count");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("ic");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("llt");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("smt_bad_formula");
  s->addDynamicRel("smt_check");
  s->addDynamicRel("smt_check_ans");
  s->addDynamicRel("smt_qcore");
  s->addDynamicRel("smt_qcore_ans");
  s->addDynamicRel("smt_qmodel");
  s->addDynamicRel("smt_qmodel_ans");
  s->addDynamicRel("smt_qsat");
  s->addDynamicRel("smt_qsat_ans");
  s->addDynamicRel("temp43NC134");
  s->addDynamicRel("temp5QcX135");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("count");
  s->addAccelRel("smt_check_ans");
  d->push(s);
  d->continueRun();
}

