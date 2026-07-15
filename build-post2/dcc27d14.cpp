
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const51f9fd68d7e9c802b42378d7;
u64 v_const99ee50221221864d50c60bae;
u64 v_constb6579dd3e29d8cc73668c256;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("dcc27d14");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const51f9fd68d7e9c802b42378d7 = db->encodeString("okq");
  v_const99ee50221221864d50c60bae = s32_encode(700);
  v_constb6579dd3e29d8cc73668c256 = db->encodeString("dem_head_guarded.slog:36");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord639({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord639, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord640({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord640, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord641({1, 2, 0});
    
    r->addIndex<3>(ord641, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord642({0, 1, 2});
    
    r->addIndex<3>(ord642, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp8lsc110");
  if (r == 0) db->addTempRelation("temp8lsc110", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8P5b111");
  if (r == 0) db->addTempRelation("temp8P5b111", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("store");
  if (r == 0) db->addRelation("store", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("store");
      std::vector<u16> ord643({0});
    
    r->addIndex<1>(ord643, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("store"), std::array<u16,1>{0}, b));
  r = db->getRelation("step_ans");
  if (r == 0) db->addRelation("step_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("step_ans");
      std::vector<u16> ord644({0, 1});
    
    r->addIndex<2>(ord644, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord645({0, 1});
    
    r->addIndex<2>(ord645, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("step_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("step");
  if (r == 0) db->addStruct("step", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("step");
      std::vector<u16> ord646({1, 0});
    
    r->addIndex<2>(ord646, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord647({0, 1});
    
    r->addIndex<2>(ord647, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord648({0, 1});
    
    r->addIndex<2>(ord648, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord649({1, 0});
    
    r->addIndex<2>(ord649, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("step"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord650({1, 2, 0});
    
    r->addIndex<3>(ord650, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord651({0, 1, 2});
    
    r->addIndex<3>(ord651, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("reach");
  if (r == 0) db->addRelation("reach", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("reach");
      std::vector<u16> ord652({0});
    
    r->addIndex<1>(ord652, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("reach"), std::array<u16,1>{0}, b));
  r = db->getRelation("okt");
  if (r == 0) db->addRelation("okt", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("okt");
      std::vector<u16> ord653({0});
    
    r->addIndex<1>(ord653, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("okt"), std::array<u16,1>{0}, b));
  r = db->getRelation("okq_ans");
  if (r == 0) db->addRelation("okq_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("okq_ans");
      std::vector<u16> ord654({1, 0});
    
    r->addIndex<2>(ord654, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord655({1, 0});
    
    r->addIndex<2>(ord655, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("okq_ans"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("okq");
  if (r == 0) db->addStruct("okq", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("okq");
      std::vector<u16> ord656({1, 0});
    
    r->addIndex<2>(ord656, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord657({0, 1});
    
    r->addIndex<2>(ord657, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord658({0, 1});
    
    r->addIndex<2>(ord658, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("okq"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord659({1, 2, 3, 0});
    
    r->addIndex<4>(ord659, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord660({0, 1, 2, 3});
    
    r->addIndex<4>(ord660, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord661({1, 2, 0});
    
    r->addIndex<3>(ord661, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord662({0, 1, 2});
    
    r->addIndex<3>(ord662, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord663({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord663, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord664({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord664, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord665({1, 2, 0});
    
    r->addIndex<3>(ord665, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord666({0, 1, 2});
    
    r->addIndex<3>(ord666, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mk_ans");
  if (r == 0) db->addRelation("mk_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mk_ans");
      std::vector<u16> ord667({0, 1});
    
    r->addIndex<2>(ord667, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord668({0, 1});
    
    r->addIndex<2>(ord668, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mk_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mk");
  if (r == 0) db->addStruct("mk", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mk");
      std::vector<u16> ord669({1, 0});
    
    r->addIndex<2>(ord669, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord670({0, 1});
    
    r->addIndex<2>(ord670, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord671({0, 1});
    
    r->addIndex<2>(ord671, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mk"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord672({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord672, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord673({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord673, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord674({1, 2, 3, 0});
    
    r->addIndex<4>(ord674, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord675({0, 1, 2, 3});
    
    r->addIndex<4>(ord675, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord676({0});
    
    r->addIndex<1>(ord676, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord677({1, 2, 0});
    
    r->addIndex<3>(ord677, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord678({0, 1, 2});
    
    r->addIndex<3>(ord678, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord679({1, 0});
    
    r->addIndex<2>(ord679, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord680({0, 1});
    
    r->addIndex<2>(ord680, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("Start");
  if (r == 0) db->addStruct("Start", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Start");
      std::vector<u16> ord681({1, 0});
    
    r->addIndex<2>(ord681, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord682({0, 1});
    
    r->addIndex<2>(ord682, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord683({1, 0});
    
    r->addIndex<2>(ord683, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("Start"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("Done");
  if (r == 0) db->addStruct("Done", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Done");
      std::vector<u16> ord684({1, 0});
    
    r->addIndex<2>(ord684, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord685({0, 1});
    
    r->addIndex<2>(ord685, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("Done"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("Ap");
  if (r == 0) db->addStruct("Ap", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Ap");
      std::vector<u16> ord686({1, 2, 0});
    
    r->addIndex<3>(ord686, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord687({0, 1, 2});
    
    r->addIndex<3>(ord687, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord688({1, 2, 0});
    
    r->addIndex<3>(ord688, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("Ap"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("$sup5130x35x0x0x1");
  if (r == 0) db->addRelation("$sup5130x35x0x0x1", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5130x35x0x0x1");
      std::vector<u16> ord689({0, 1, 2, 3});
    
    r->addIndex<4>(ord689, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
      std::vector<u16> ord690({1, 3, 0, 2});
    
    r->addIndex<4>(ord690, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 0, 2}, false, b), false);
      std::vector<u16> ord691({2, 3, 0, 1});
    
    r->addIndex<4>(ord691, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), false);
      std::vector<u16> ord692({1, 3, 0, 2});
    
    r->addIndex<4>(ord692, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 0, 2}, true, b), false);
      std::vector<u16> ord693({2, 3, 0, 1});
    
    r->addIndex<4>(ord693, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5130x35x0x0x1"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5130x35x0x0x0");
  if (r == 0) db->addRelation("$sup5130x35x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5130x35x0x0x0");
      std::vector<u16> ord694({0, 1, 2});
    
    r->addIndex<3>(ord694, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord695({2, 1, 0});
    
    r->addIndex<3>(ord695, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), false);
      std::vector<u16> ord696({2, 1, 0});
    
    r->addIndex<3>(ord696, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup5130x35x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  // (crule (pre (let __tconst0rYx8 const6b86b273ff34fce19d6b804e) (let __tconst70tI9 const99ee50221221864d50c60bae)) (scan $sup5130x35x0x0x1 __t2jdr6 __t6bDk7 k op) (body (join $sup5130x35x0x0x0 (2 1 0) 3 op k __t2jdr6) (join okq_ans (1 0) 2 __tconst0rYx8 __t6bDk7) (join-old okq (0 1) 2 (0 1) __t6bDk7 op) (join-old Ap (1 2 0) 2 (1 2 0) op k __t0lCH5) (join-old step (0 1) 2 (0 1) __t2jdr6 __t0lCH5) (join mk_ans (0 1) 0 __t6KNu11 __v0) (let __t4XhT10 (_0002b op __tconst70tI9)) (join-old mk (0 1) 2 (0 1) __t6KNu11 __t4XhT10)) (head (emit-temp temp8P5b111 __t2jdr6 __v0) (mkstruct Done (1 0) __t3NKT4 __v0)) dem_head_guarded.slog:36 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5130x35x0x0x0index0;  slog::Index** okq_ansindex1;  slog::Index** okqindex2;  slog::Index** Apindex3;  slog::Index** stepindex4;  slog::Index** mk_ansindex5;  slog::Index** mkindex6;  slog::Index** okqdelta7;  slog::Index** Apdelta8;  slog::Index** stepdelta9;  slog::Index** mkdelta10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8P5b111");
      head_rel[1] = db->getRelation("Done");
      outer_rel = db->getRelation("$sup5130x35x0x0x1");
      std::vector<u16> ord12({2, 1, 0});
      slog::Relation* readrel13 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index0 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("okq_ans");
      okq_ansindex1 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({0, 1});
      slog::Relation* readrel17 = db->getRelation("okq");
      okqindex2 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({0, 1});
      slog::Relation* readrel19 = db->getRelation("okq");
      okqdelta7 = readrel19->getIndex(ord18, true);
      std::vector<u16> ord20({1, 2, 0});
      slog::Relation* readrel21 = db->getRelation("Ap");
      Apindex3 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 2, 0});
      slog::Relation* readrel23 = db->getRelation("Ap");
      Apdelta8 = readrel23->getIndex(ord22, true);
      std::vector<u16> ord24({0, 1});
      slog::Relation* readrel25 = db->getRelation("step");
      stepindex4 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({0, 1});
      slog::Relation* readrel27 = db->getRelation("step");
      stepdelta9 = readrel27->getIndex(ord26, true);
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("mk_ans");
      mk_ansindex5 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1});
      slog::Relation* readrel31 = db->getRelation("mk");
      mkindex6 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1});
      slog::Relation* readrel33 = db->getRelation("mk");
      mkdelta10 = readrel33->getIndex(ord32, true);
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const99ee50221221864d50c60bae;
  
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
        u64 v_c3 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c5 = _t[3];
        slog::join_probe<3,3>($sup5130x35x0x0x0index0, std::array<u64,3>{v_c5, v_c4, v_c2}, [&](const std::array<u64,3>& m34) {
          slog::join_probe<2,2>(okq_ansindex1, std::array<u64,2>{v_c0, v_c3}, [&](const std::array<u64,2>& m35) {
            slog::join_probe_old<2,2>(okqindex2, okqdelta7, std::array<u64,2>{v_c3, v_c5}, [&](const std::array<u64,2>& m36) {
              slog::join_probe_old<3,2>(Apindex3, Apdelta8, std::array<u64,3>{v_c5, v_c4, 0}, [&](const std::array<u64,3>& m37) {
                u64 v_c6 = m37[2];
                slog::join_probe_old<2,2>(stepindex4, stepdelta9, std::array<u64,2>{v_c2, v_c6}, [&](const std::array<u64,2>& m38) {
                  slog::join_all<2>(mk_ansindex5, [&](const std::array<u64,2>& m39) {
                    u64 v_c7 = m39[0]; u64 v_c8 = m39[1];
                    u64 v_c9 = _prim__0002b(db, v_c5, v_c1);
                    if (v_c9 == slog_error) { slog::emit_pending_error(db, "dem_head_guarded.slog:36"); return; }
                    slog::join_probe_old<2,2>(mkindex6, mkdelta10, std::array<u64,2>{v_c7, v_c9}, [&](const std::array<u64,2>& m40) {
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c8});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:$sup5130x35x0x0x1", _fires);
  
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
  // (crule (pre) (scan step __t2lU12 __t4Z0S1) (body (join Ap (0 1 2) 1 __t4Z0S1 op k)) (head (emit $sup5130x35x0x0x0 (0 1 2) __t2lU12 k op)) dem_head_guarded.slog:36 #f)
  class ReadTask42 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Apindex41;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5130x35x0x0x0");
      std::vector<u16> ord43({0, 1, 2});
      slog::Relation* readrel44 = db->getRelation("$sup5130x35x0x0x0");
      head_index[0] = readrel44->getIndex(ord43, false);
      outer_rel = db->getRelation("step");
      std::vector<u16> ord45({0, 1, 2});
      slog::Relation* readrel46 = db->getRelation("Ap");
      Apindex41 = readrel46->getIndex(ord45, false);
  
    }
    ReadTask42(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<3,1>(Apindex41, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m47) {
          u64 v_c5 = m47[1]; u64 v_c4 = m47[2];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c10, v_c4, v_c5}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:step", _fires);
  
      if (!_done)
      {
        ReadTask42* _cont = new ReadTask42(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask42(db,b), false);
  // (crule (pre (let __tconst0HcW29 const5feceb66ffc86f38d952786c) (let __tconst6kRe27 const6b86b273ff34fce19d6b804e)) (seeded) (body (join Ap (1 2 0) 2 __tconst6kRe27 __tconst0HcW29 __t8myT28) (join Start (1 0) 1 __tconst0HcW29 __t9msl30) (join step (1 0) 1 __t9msl30 __t2Hcv31)) (head (emit step_ans (0 1) __t2Hcv31 __t8myT28)) dem_head_guarded.slog:30 #f)
  class ReadTask51 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** Apindex48;  slog::Index** Startindex49;  slog::Index** stepindex50;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("step_ans");
      std::vector<u16> ord52({0, 1});
      slog::Relation* readrel53 = db->getRelation("step_ans");
      head_index[0] = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 2, 0});
      slog::Relation* readrel55 = db->getRelation("Ap");
      Apindex48 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 0});
      slog::Relation* readrel57 = db->getRelation("Start");
      Startindex49 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 0});
      slog::Relation* readrel59 = db->getRelation("step");
      stepindex50 = readrel59->getIndex(ord58, false);
  
    }
    ReadTask51(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<3,2>(Apindex48, std::array<u64,3>{v_c13, v_c12, 0}, [&](const std::array<u64,3>& m60) {
        u64 v_c14 = m60[2];
        slog::join_probe<2,1>(Startindex49, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m61) {
          u64 v_c15 = m61[1];
          slog::join_probe<2,1>(stepindex50, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m62) {
            u64 v_c16 = m62[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c14}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:30", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask51(db,b));
  // (crule (pre) (scan Ap __t4Z0S1 op k) (body (join-old step (1 0) 1 (1 0) __t4Z0S1 __t2lU12)) (head (emit $sup5130x35x0x0x0 (0 1 2) __t2lU12 k op)) dem_head_guarded.slog:36 #f)
  class ReadTask65 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** stepindex63;  slog::Index** stepdelta64;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5130x35x0x0x0");
      std::vector<u16> ord66({0, 1, 2});
      slog::Relation* readrel67 = db->getRelation("$sup5130x35x0x0x0");
      head_index[0] = readrel67->getIndex(ord66, false);
      outer_rel = db->getRelation("Ap");
      std::vector<u16> ord68({1, 0});
      slog::Relation* readrel69 = db->getRelation("step");
      stepindex63 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 0});
      slog::Relation* readrel71 = db->getRelation("step");
      stepdelta64 = readrel71->getIndex(ord70, true);
  
    }
    ReadTask65(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe_old<2,1>(stepindex63, stepdelta64, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m72) {
          u64 v_c10 = m72[1];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c10, v_c4, v_c5}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:Ap", _fires);
  
      if (!_done)
      {
        ReadTask65* _cont = new ReadTask65(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask65(db,b), false);
  // (crule (pre (let __tconst0HcW29 const5feceb66ffc86f38d952786c) (let __tconst6kRe27 const6b86b273ff34fce19d6b804e)) (probe Start (1 0) 1 __tconst0HcW29 __t9msl30) (body (join-old step (1 0) 1 (1 0) __t9msl30 __t2Hcv31)) (head (mkstruct Ap (1 2 0) __t8myT28 __tconst6kRe27 __tconst0HcW29)) dem_head_guarded.slog:30 #f)
  class ReadTask75 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** stepindex73;  slog::Index** stepdelta74;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Ap");
      std::vector<u16> ord76({1, 0});
      slog::Relation* readrel77 = db->getRelation("Start");
      driver_index = readrel77->getIndex(ord76, true);
      std::vector<u16> ord78({1, 0});
      slog::Relation* readrel79 = db->getRelation("step");
      stepindex73 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 0});
      slog::Relation* readrel81 = db->getRelation("step");
      stepdelta74 = readrel81->getIndex(ord80, true);
  
    }
    ReadTask75(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c12, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m82) {
        u64 v_c15 = m82[1];
        if (buckethash(v_c15) != bucket) return;
        slog::join_probe_old<2,1>(stepindex73, stepdelta74, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m83) {
          u64 v_c16 = m83[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c13, v_c12}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:30", "delta:Start", _fires);
  
      if (!_done)
      {
        ReadTask75* _cont = new ReadTask75(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask75(db,b), false);
  // (crule (pre (let __tconst0rYx8 const6b86b273ff34fce19d6b804e) (let __tconst70tI9 const99ee50221221864d50c60bae)) (scan mk_ans __t6KNu11 __v0) (body (join okq_ans (1 0) 1 __tconst0rYx8 __t6bDk7) (exists $sup5130x35x0x0x1 (1 3 0 2) 1 __t6bDk7) (join-old okq (0 1) 1 (0 1) __t6bDk7 op) (exists $sup5130x35x0x0x0 (2 1 0) 1 op) (exists Ap (1 2 0) 1 op) (join-old $sup5130x35x0x0x1 (1 3 0 2) 2 (1 3 0 2) __t6bDk7 op __t2jdr6 k) (join-old $sup5130x35x0x0x0 (2 1 0) 3 (2 1 0) op k __t2jdr6) (join-old Ap (1 2 0) 2 (1 2 0) op k __t0lCH5) (join-old step (0 1) 2 (0 1) __t2jdr6 __t0lCH5) (let __t4XhT10 (_0002b op __tconst70tI9)) (join-old mk (0 1) 2 (0 1) __t6KNu11 __t4XhT10)) (head (emit-temp temp8P5b111 __t2jdr6 __v0) (mkstruct Done (1 0) __t3NKT4 __v0)) dem_head_guarded.slog:36 #f)
  class ReadTask100 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** okq_ansindex84;  slog::Index** $sup5130x35x0x0x1index85;  slog::Index** okqindex86;  slog::Index** $sup5130x35x0x0x0index87;  slog::Index** Apindex88;  slog::Index** $sup5130x35x0x0x1index89;  slog::Index** $sup5130x35x0x0x0index90;  slog::Index** Apindex91;  slog::Index** stepindex92;  slog::Index** mkindex93;  slog::Index** okqdelta94;  slog::Index** $sup5130x35x0x0x1delta95;  slog::Index** $sup5130x35x0x0x0delta96;  slog::Index** Apdelta97;  slog::Index** stepdelta98;  slog::Index** mkdelta99;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8P5b111");
      head_rel[1] = db->getRelation("Done");
      outer_rel = db->getRelation("mk_ans");
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("okq_ans");
      okq_ansindex84 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 3, 0, 2});
      slog::Relation* readrel104 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index85 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("okq");
      okqindex86 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("okq");
      okqdelta94 = readrel108->getIndex(ord107, true);
      std::vector<u16> ord109({2, 1, 0});
      slog::Relation* readrel110 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index87 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 2, 0});
      slog::Relation* readrel112 = db->getRelation("Ap");
      Apindex88 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 3, 0, 2});
      slog::Relation* readrel114 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index89 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 3, 0, 2});
      slog::Relation* readrel116 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1delta95 = readrel116->getIndex(ord115, true);
      std::vector<u16> ord117({2, 1, 0});
      slog::Relation* readrel118 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index90 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({2, 1, 0});
      slog::Relation* readrel120 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0delta96 = readrel120->getIndex(ord119, true);
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("Ap");
      Apindex91 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 0});
      slog::Relation* readrel124 = db->getRelation("Ap");
      Apdelta97 = readrel124->getIndex(ord123, true);
      std::vector<u16> ord125({0, 1});
      slog::Relation* readrel126 = db->getRelation("step");
      stepindex92 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({0, 1});
      slog::Relation* readrel128 = db->getRelation("step");
      stepdelta98 = readrel128->getIndex(ord127, true);
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("mk");
      mkindex93 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("mk");
      mkdelta99 = readrel132->getIndex(ord131, true);
  
    }
    ReadTask100(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const99ee50221221864d50c60bae;
  
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
        u64 v_c8 = _t[1];
        slog::join_probe<2,1>(okq_ansindex84, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m133) {
          u64 v_c3 = m133[1];
          if (!slog::exists_probe<4,1>($sup5130x35x0x0x1index85, std::array<u64,4>{v_c3, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(okqindex86, okqdelta94, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m134) {
            u64 v_c5 = m134[1];
            if (!slog::exists_probe<3,1>($sup5130x35x0x0x0index87, std::array<u64,3>{v_c5, 0, 0})) return;
            if (!slog::exists_probe<3,1>(Apindex88, std::array<u64,3>{v_c5, 0, 0})) return;
            slog::join_probe_old<4,2>($sup5130x35x0x0x1index89, $sup5130x35x0x0x1delta95, std::array<u64,4>{v_c3, v_c5, 0, 0}, [&](const std::array<u64,4>& m135) {
              u64 v_c2 = m135[2]; u64 v_c4 = m135[3];
              slog::join_probe_old<3,3>($sup5130x35x0x0x0index90, $sup5130x35x0x0x0delta96, std::array<u64,3>{v_c5, v_c4, v_c2}, [&](const std::array<u64,3>& m136) {
                slog::join_probe_old<3,2>(Apindex91, Apdelta97, std::array<u64,3>{v_c5, v_c4, 0}, [&](const std::array<u64,3>& m137) {
                  u64 v_c6 = m137[2];
                  slog::join_probe_old<2,2>(stepindex92, stepdelta98, std::array<u64,2>{v_c2, v_c6}, [&](const std::array<u64,2>& m138) {
                    u64 v_c9 = _prim__0002b(db, v_c5, v_c1);
                    if (v_c9 == slog_error) { slog::emit_pending_error(db, "dem_head_guarded.slog:36"); return; }
                    slog::join_probe_old<2,2>(mkindex93, mkdelta99, std::array<u64,2>{v_c7, v_c9}, [&](const std::array<u64,2>& m139) {
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c8});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:mk_ans", _fires);
  
      if (!_done)
      {
        ReadTask100* _cont = new ReadTask100(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask100(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre31K583 __errf31Zm84 __errf26n185) (body) (head (emit error (0) __erre31K583)) <internal>:1 #f)
  class ReadTask140 : public slog::Task
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
      std::vector<u16> ord141({0});
      slog::Relation* readrel142 = db->getRelation("error");
      head_index[0] = readrel142->getIndex(ord141, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask140(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask140* _cont = new ReadTask140(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask140(db,b), false);
  // (crule (pre (let __tconst0HcW29 const5feceb66ffc86f38d952786c) (let __tconst6kRe27 const6b86b273ff34fce19d6b804e)) (scan step __t2Hcv31 __t9msl30) (body (join Start (0 1) 2 __t9msl30 __tconst0HcW29)) (head (mkstruct Ap (1 2 0) __t8myT28 __tconst6kRe27 __tconst0HcW29)) dem_head_guarded.slog:30 #f)
  class ReadTask144 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Startindex143;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Ap");
      outer_rel = db->getRelation("step");
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("Start");
      Startindex143 = readrel146->getIndex(ord145, false);
  
    }
    ReadTask144(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c16 = _t[0];
        u64 v_c15 = _t[1];
        slog::join_probe<2,2>(Startindex143, std::array<u64,2>{v_c15, v_c12}, [&](const std::array<u64,2>& m147) {
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c13, v_c12}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:30", "delta:step", _fires);
  
      if (!_done)
      {
        ReadTask144* _cont = new ReadTask144(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask144(db,b), false);
  // (crule (pre (let __tconst3Fxs32 const99ee50221221864d50c60bae)) (scan $sup5130x35x0x0x1 __d0 __d1 k op) (body (let __t0R0d33 (_0002b op __tconst3Fxs32))) (head (emit-temp temp8lsc110 __t0R0d33)) dem_head_guarded.slog:36 #f)
  class ReadTask148 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8lsc110");
      outer_rel = db->getRelation("$sup5130x35x0x0x1");
  
    }
    ReadTask148(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const99ee50221221864d50c60bae;
  
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
        u64 v_c4 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c23 = _prim__0002b(db, v_c5, v_c20);
        if (v_c23 == slog_error) { slog::emit_pending_error(db, "dem_head_guarded.slog:36"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:$sup5130x35x0x0x1", _fires);
  
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
  // (crule (pre) (scan type_mismatch __erre1XcK97 __errf3BBz98 __errf2UdY99 __errf7bi3100 __errf0W8w101) (body) (head (emit error (0) __erre1XcK97)) <internal>:1 #f)
  class ReadTask149 : public slog::Task
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
      std::vector<u16> ord150({0});
      slog::Relation* readrel151 = db->getRelation("error");
      head_index[0] = readrel151->getIndex(ord150, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask149(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask149* _cont = new ReadTask149(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask149(db,b), false);
  // (crule (pre) (scan temp8lsc110 __t0R0d33) (body) (head (mkstruct mk (1 0) __5kDq39 __t0R0d33)) dem_head_guarded.slog:36 #f)
  class ReadTask152 : public slog::Task
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
      head_rel[0] = db->getRelation("mk");
      outer_rel = db->getRelation("temp8lsc110");
  
    }
    ReadTask152(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:temp8lsc110", _fires);
  
      if (!_done)
      {
        ReadTask152* _cont = new ReadTask152(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask152(db,b), false);
  // (crule (pre (let __tconst0rYx8 const6b86b273ff34fce19d6b804e) (let __tconst70tI9 const99ee50221221864d50c60bae)) (scan mk __t6KNu11 __t4XhT10) (body (exists mk_ans (0 1) 1 __t6KNu11) (join okq_ans (1 0) 1 __tconst0rYx8 __t6bDk7) (exists $sup5130x35x0x0x1 (1 3 0 2) 1 __t6bDk7) (join mk_ans (0 1) 1 __t6KNu11 __v0) (join okq (0 1) 1 __t6bDk7 op) (exists $sup5130x35x0x0x0 (2 1 0) 1 op) (exists Ap (1 2 0) 1 op) (join $sup5130x35x0x0x1 (1 3 0 2) 2 __t6bDk7 op __t2jdr6 k) (join $sup5130x35x0x0x0 (2 1 0) 3 op k __t2jdr6) (join Ap (1 2 0) 2 op k __t0lCH5) (join step (0 1) 2 __t2jdr6 __t0lCH5) (let chk1TAx112 (_0002b op __tconst70tI9)) (eq __t4XhT10 chk1TAx112)) (head (emit-temp temp8P5b111 __t2jdr6 __v0) (mkstruct Done (1 0) __t3NKT4 __v0)) dem_head_guarded.slog:36 #f)
  class ReadTask164 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mk_ansindex153;  slog::Index** okq_ansindex154;  slog::Index** $sup5130x35x0x0x1index155;  slog::Index** mk_ansindex156;  slog::Index** okqindex157;  slog::Index** $sup5130x35x0x0x0index158;  slog::Index** Apindex159;  slog::Index** $sup5130x35x0x0x1index160;  slog::Index** $sup5130x35x0x0x0index161;  slog::Index** Apindex162;  slog::Index** stepindex163;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8P5b111");
      head_rel[1] = db->getRelation("Done");
      outer_rel = db->getRelation("mk");
      std::vector<u16> ord165({0, 1});
      slog::Relation* readrel166 = db->getRelation("mk_ans");
      mk_ansindex153 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("okq_ans");
      okq_ansindex154 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 3, 0, 2});
      slog::Relation* readrel170 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index155 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("mk_ans");
      mk_ansindex156 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("okq");
      okqindex157 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({2, 1, 0});
      slog::Relation* readrel176 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index158 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("Ap");
      Apindex159 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 3, 0, 2});
      slog::Relation* readrel180 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index160 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({2, 1, 0});
      slog::Relation* readrel182 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index161 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 2, 0});
      slog::Relation* readrel184 = db->getRelation("Ap");
      Apindex162 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({0, 1});
      slog::Relation* readrel186 = db->getRelation("step");
      stepindex163 = readrel186->getIndex(ord185, false);
  
    }
    ReadTask164(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const99ee50221221864d50c60bae;
  
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
        u64 v_c9 = _t[1];
        if (!slog::exists_probe<2,1>(mk_ansindex153, std::array<u64,2>{v_c7, 0})) return;
        slog::join_probe<2,1>(okq_ansindex154, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m187) {
          u64 v_c3 = m187[1];
          if (!slog::exists_probe<4,1>($sup5130x35x0x0x1index155, std::array<u64,4>{v_c3, 0, 0, 0})) return;
          slog::join_probe<2,1>(mk_ansindex156, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m188) {
            u64 v_c8 = m188[1];
            slog::join_probe<2,1>(okqindex157, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m189) {
              u64 v_c5 = m189[1];
              if (!slog::exists_probe<3,1>($sup5130x35x0x0x0index158, std::array<u64,3>{v_c5, 0, 0})) return;
              if (!slog::exists_probe<3,1>(Apindex159, std::array<u64,3>{v_c5, 0, 0})) return;
              slog::join_probe<4,2>($sup5130x35x0x0x1index160, std::array<u64,4>{v_c3, v_c5, 0, 0}, [&](const std::array<u64,4>& m190) {
                u64 v_c2 = m190[2]; u64 v_c4 = m190[3];
                slog::join_probe<3,3>($sup5130x35x0x0x0index161, std::array<u64,3>{v_c5, v_c4, v_c2}, [&](const std::array<u64,3>& m191) {
                  slog::join_probe<3,2>(Apindex162, std::array<u64,3>{v_c5, v_c4, 0}, [&](const std::array<u64,3>& m192) {
                    u64 v_c6 = m192[2];
                    slog::join_probe<2,2>(stepindex163, std::array<u64,2>{v_c2, v_c6}, [&](const std::array<u64,2>& m193) {
                      u64 v_c29 = _prim__0002b(db, v_c5, v_c1);
                      if (v_c29 == slog_error) { slog::emit_pending_error(db, "dem_head_guarded.slog:36"); return; }
                      if (v_c9 != v_c29) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c8});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:mk", _fires);
  
      if (!_done)
      {
        ReadTask164* _cont = new ReadTask164(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask164(db,b), false);
  // (crule (pre (let __tconst7jOM18 const5feceb66ffc86f38d952786c) (let __tconst7yxw16 constd4735e3a265e16eee03f5971)) (probe Start (1 0) 1 __tconst7jOM18 __t8LH219) (body (join-old step (1 0) 1 (1 0) __t8LH219 __t4qfT20)) (head (mkstruct Ap (1 2 0) __t9hkM17 __tconst7yxw16 __tconst7jOM18)) dem_head_guarded.slog:31 #f)
  class ReadTask196 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** stepindex194;  slog::Index** stepdelta195;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Ap");
      std::vector<u16> ord197({1, 0});
      slog::Relation* readrel198 = db->getRelation("Start");
      driver_index = readrel198->getIndex(ord197, true);
      std::vector<u16> ord199({1, 0});
      slog::Relation* readrel200 = db->getRelation("step");
      stepindex194 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 0});
      slog::Relation* readrel202 = db->getRelation("step");
      stepdelta195 = readrel202->getIndex(ord201, true);
  
    }
    ReadTask196(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c30, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m203) {
        u64 v_c32 = m203[1];
        if (buckethash(v_c32) != bucket) return;
        slog::join_probe_old<2,1>(stepindex194, stepdelta195, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m204) {
          u64 v_c33 = m204[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c31, v_c30}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:31", "delta:Start", _fires);
  
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
      s->addTask(phase_read, new ReadTask196(db,b), false);
  // (crule (pre (let __tconst4wQg24 const6b86b273ff34fce19d6b804e)) (scan okq __t2hg825 n) (body (join okt (0) 1 n)) (head (emit okq_ans (1 0) __tconst4wQg24 __t2hg825)) dem_head_guarded.slog:22 #f)
  class ReadTask206 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** oktindex205;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("okq_ans");
      std::vector<u16> ord207({1, 0});
      slog::Relation* readrel208 = db->getRelation("okq_ans");
      head_index[0] = readrel208->getIndex(ord207, false);
      outer_rel = db->getRelation("okq");
      std::vector<u16> ord209({0});
      slog::Relation* readrel210 = db->getRelation("okt");
      oktindex205 = readrel210->getIndex(ord209, false);
  
    }
    ReadTask206(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c35 = _t[0];
        u64 v_c36 = _t[1];
        slog::join_probe<1,1>(oktindex205, std::array<u64,1>{v_c36}, [&](const std::array<u64,1>& m211) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c34, v_c35}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:22", "delta:okq", _fires);
  
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
  // (crule (pre (let __tconst7jOM18 const5feceb66ffc86f38d952786c) (let __tconst7yxw16 constd4735e3a265e16eee03f5971)) (seeded) (body (join Ap (1 2 0) 2 __tconst7yxw16 __tconst7jOM18 __t9hkM17) (join Start (1 0) 1 __tconst7jOM18 __t8LH219) (join step (1 0) 1 __t8LH219 __t4qfT20)) (head (emit step_ans (0 1) __t4qfT20 __t9hkM17)) dem_head_guarded.slog:31 #f)
  class ReadTask215 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** Apindex212;  slog::Index** Startindex213;  slog::Index** stepindex214;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("step_ans");
      std::vector<u16> ord216({0, 1});
      slog::Relation* readrel217 = db->getRelation("step_ans");
      head_index[0] = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("Ap");
      Apindex212 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 0});
      slog::Relation* readrel221 = db->getRelation("Start");
      Startindex213 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 0});
      slog::Relation* readrel223 = db->getRelation("step");
      stepindex214 = readrel223->getIndex(ord222, false);
  
    }
    ReadTask215(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<3,2>(Apindex212, std::array<u64,3>{v_c31, v_c30, 0}, [&](const std::array<u64,3>& m224) {
        u64 v_c37 = m224[2];
        slog::join_probe<2,1>(Startindex213, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m225) {
          u64 v_c32 = m225[1];
          slog::join_probe<2,1>(stepindex214, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m226) {
            u64 v_c33 = m226[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c33, v_c37}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:31", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask215(db,b));
  // (crule (pre (let __tconst38yN22 const5feceb66ffc86f38d952786c)) (once) (body) (head (mkstruct Start (1 0) __t5jZE23 __tconst38yN22)) dem_head_guarded.slog:26 #f)
  class ReadTask227 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Start");
  
    }
    ReadTask227(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c38}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:26", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask227(db,b), true);
  // (crule (pre (let __tconst0rYx8 const6b86b273ff34fce19d6b804e) (let __tconst70tI9 const99ee50221221864d50c60bae)) (probe okq_ans (1 0) 1 __tconst0rYx8 __t6bDk7) (body (exists $sup5130x35x0x0x1 (1 3 0 2) 1 __t6bDk7) (join-old okq (0 1) 1 (0 1) __t6bDk7 op) (exists $sup5130x35x0x0x0 (2 1 0) 1 op) (exists Ap (1 2 0) 1 op) (join-old $sup5130x35x0x0x1 (1 3 0 2) 2 (1 3 0 2) __t6bDk7 op __t2jdr6 k) (join-old $sup5130x35x0x0x0 (2 1 0) 3 (2 1 0) op k __t2jdr6) (join-old Ap (1 2 0) 2 (1 2 0) op k __t0lCH5) (join-old step (0 1) 2 (0 1) __t2jdr6 __t0lCH5) (join-old mk_ans (0 1) 0 (0 1) __t6KNu11 __v0) (let __t4XhT10 (_0002b op __tconst70tI9)) (join-old mk (0 1) 2 (0 1) __t6KNu11 __t4XhT10)) (head (emit-temp temp8P5b111 __t2jdr6 __v0) (mkstruct Done (1 0) __t3NKT4 __v0)) dem_head_guarded.slog:36 #f)
  class ReadTask245 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** $sup5130x35x0x0x1index228;  slog::Index** okqindex229;  slog::Index** $sup5130x35x0x0x0index230;  slog::Index** Apindex231;  slog::Index** $sup5130x35x0x0x1index232;  slog::Index** $sup5130x35x0x0x0index233;  slog::Index** Apindex234;  slog::Index** stepindex235;  slog::Index** mk_ansindex236;  slog::Index** mkindex237;  slog::Index** okqdelta238;  slog::Index** $sup5130x35x0x0x1delta239;  slog::Index** $sup5130x35x0x0x0delta240;  slog::Index** Apdelta241;  slog::Index** stepdelta242;  slog::Index** mk_ansdelta243;  slog::Index** mkdelta244;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8P5b111");
      head_rel[1] = db->getRelation("Done");
      std::vector<u16> ord246({1, 0});
      slog::Relation* readrel247 = db->getRelation("okq_ans");
      driver_index = readrel247->getIndex(ord246, true);
      std::vector<u16> ord248({1, 3, 0, 2});
      slog::Relation* readrel249 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index228 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 1});
      slog::Relation* readrel251 = db->getRelation("okq");
      okqindex229 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({0, 1});
      slog::Relation* readrel253 = db->getRelation("okq");
      okqdelta238 = readrel253->getIndex(ord252, true);
      std::vector<u16> ord254({2, 1, 0});
      slog::Relation* readrel255 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index230 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 2, 0});
      slog::Relation* readrel257 = db->getRelation("Ap");
      Apindex231 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 3, 0, 2});
      slog::Relation* readrel259 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index232 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 3, 0, 2});
      slog::Relation* readrel261 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1delta239 = readrel261->getIndex(ord260, true);
      std::vector<u16> ord262({2, 1, 0});
      slog::Relation* readrel263 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index233 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({2, 1, 0});
      slog::Relation* readrel265 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0delta240 = readrel265->getIndex(ord264, true);
      std::vector<u16> ord266({1, 2, 0});
      slog::Relation* readrel267 = db->getRelation("Ap");
      Apindex234 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 2, 0});
      slog::Relation* readrel269 = db->getRelation("Ap");
      Apdelta241 = readrel269->getIndex(ord268, true);
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("step");
      stepindex235 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({0, 1});
      slog::Relation* readrel273 = db->getRelation("step");
      stepdelta242 = readrel273->getIndex(ord272, true);
      std::vector<u16> ord274({0, 1});
      slog::Relation* readrel275 = db->getRelation("mk_ans");
      mk_ansindex236 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({0, 1});
      slog::Relation* readrel277 = db->getRelation("mk_ans");
      mk_ansdelta243 = readrel277->getIndex(ord276, true);
      std::vector<u16> ord278({0, 1});
      slog::Relation* readrel279 = db->getRelation("mk");
      mkindex237 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({0, 1});
      slog::Relation* readrel281 = db->getRelation("mk");
      mkdelta244 = readrel281->getIndex(ord280, true);
  
    }
    ReadTask245(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const99ee50221221864d50c60bae;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m282) {
        u64 v_c3 = m282[1];
        if (buckethash(v_c3) != bucket) return;
        if (!slog::exists_probe<4,1>($sup5130x35x0x0x1index228, std::array<u64,4>{v_c3, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(okqindex229, okqdelta238, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m283) {
          u64 v_c5 = m283[1];
          if (!slog::exists_probe<3,1>($sup5130x35x0x0x0index230, std::array<u64,3>{v_c5, 0, 0})) return;
          if (!slog::exists_probe<3,1>(Apindex231, std::array<u64,3>{v_c5, 0, 0})) return;
          slog::join_probe_old<4,2>($sup5130x35x0x0x1index232, $sup5130x35x0x0x1delta239, std::array<u64,4>{v_c3, v_c5, 0, 0}, [&](const std::array<u64,4>& m284) {
            u64 v_c2 = m284[2]; u64 v_c4 = m284[3];
            slog::join_probe_old<3,3>($sup5130x35x0x0x0index233, $sup5130x35x0x0x0delta240, std::array<u64,3>{v_c5, v_c4, v_c2}, [&](const std::array<u64,3>& m285) {
              slog::join_probe_old<3,2>(Apindex234, Apdelta241, std::array<u64,3>{v_c5, v_c4, 0}, [&](const std::array<u64,3>& m286) {
                u64 v_c6 = m286[2];
                slog::join_probe_old<2,2>(stepindex235, stepdelta242, std::array<u64,2>{v_c2, v_c6}, [&](const std::array<u64,2>& m287) {
                  slog::join_all_old<2>(mk_ansindex236, mk_ansdelta243, [&](const std::array<u64,2>& m288) {
                    u64 v_c7 = m288[0]; u64 v_c8 = m288[1];
                    u64 v_c9 = _prim__0002b(db, v_c5, v_c1);
                    if (v_c9 == slog_error) { slog::emit_pending_error(db, "dem_head_guarded.slog:36"); return; }
                    slog::join_probe_old<2,2>(mkindex237, mkdelta244, std::array<u64,2>{v_c7, v_c9}, [&](const std::array<u64,2>& m289) {
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c8});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:okq_ans", _fires);
  
      if (!_done)
      {
        ReadTask245* _cont = new ReadTask245(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask245(db,b), false);
  // (crule (pre (let __tconst1G9T13 const6b86b273ff34fce19d6b804e)) (probe okq_ans (1 0) 1 __tconst1G9T13 __t6NE412) (body (join-old okq (0 1) 1 (0 1) __t6NE412 op) (join $sup5130x35x0x0x0 (2 1 0) 1 op k __d0)) (head (emit $sup5130x35x0x0x1 (0 1 2 3) __d0 __t6NE412 k op)) dem_head_guarded.slog:36 #f)
  class ReadTask293 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** okqindex290;  slog::Index** $sup5130x35x0x0x0index291;  slog::Index** okqdelta292;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5130x35x0x0x1");
      std::vector<u16> ord294({0, 1, 2, 3});
      slog::Relation* readrel295 = db->getRelation("$sup5130x35x0x0x1");
      head_index[0] = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 0});
      slog::Relation* readrel297 = db->getRelation("okq_ans");
      driver_index = readrel297->getIndex(ord296, true);
      std::vector<u16> ord298({0, 1});
      slog::Relation* readrel299 = db->getRelation("okq");
      okqindex290 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({0, 1});
      slog::Relation* readrel301 = db->getRelation("okq");
      okqdelta292 = readrel301->getIndex(ord300, true);
      std::vector<u16> ord302({2, 1, 0});
      slog::Relation* readrel303 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index291 = readrel303->getIndex(ord302, false);
  
    }
    ReadTask293(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c39, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m304) {
        u64 v_c40 = m304[1];
        if (buckethash(v_c40) != bucket) return;
        slog::join_probe_old<2,1>(okqindex290, okqdelta292, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m305) {
          u64 v_c5 = m305[1];
          slog::join_probe<3,1>($sup5130x35x0x0x0index291, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m306) {
            u64 v_c4 = m306[1]; u64 v_c21 = m306[2];
            ++_fires;
            slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c21, v_c40, v_c4, v_c5}, std::array<u16,4>{0, 1, 2, 3});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:okq_ans", _fires);
  
      if (!_done)
      {
        ReadTask293* _cont = new ReadTask293(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask293(db,b), false);
  // (crule (pre (let __tconst0HcW29 const5feceb66ffc86f38d952786c) (let __tconst6kRe27 const6b86b273ff34fce19d6b804e)) (probe Ap (1 2 0) 2 __tconst6kRe27 __tconst0HcW29 __t8myT28) (body (join Start (1 0) 1 __tconst0HcW29 __t9msl30) (join step (1 0) 1 __t9msl30 __t2Hcv31)) (head (emit step_ans (0 1) __t2Hcv31 __t8myT28)) dem_head_guarded.slog:30 #f)
  class ReadTask309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** Startindex307;  slog::Index** stepindex308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("step_ans");
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("step_ans");
      head_index[0] = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 0});
      slog::Relation* readrel313 = db->getRelation("Ap");
      driver_index = readrel313->getIndex(ord312, true);
      std::vector<u16> ord314({1, 0});
      slog::Relation* readrel315 = db->getRelation("Start");
      Startindex307 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 0});
      slog::Relation* readrel317 = db->getRelation("step");
      stepindex308 = readrel317->getIndex(ord316, false);
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c13, v_c12, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m318) {
        u64 v_c14 = m318[2];
        if (buckethash(v_c14) != bucket) return;
        slog::join_probe<2,1>(Startindex307, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m319) {
          u64 v_c15 = m319[1];
          slog::join_probe<2,1>(stepindex308, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m320) {
            u64 v_c16 = m320[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c14}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:30", "delta:Ap", _fires);
  
      if (!_done)
      {
        ReadTask309* _cont = new ReadTask309(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask309(db,b), false);
  // (crule (pre (let __tconst38yN22 const5feceb66ffc86f38d952786c)) (probe Start (1 0) 1 __tconst38yN22 __t5jZE23) (body) (head (emit reach (0) __t5jZE23)) dem_head_guarded.slog:26 #f)
  class ReadTask321 : public slog::Task
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
      head_rel[0] = db->getRelation("reach");
      std::vector<u16> ord322({0});
      slog::Relation* readrel323 = db->getRelation("reach");
      head_index[0] = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 0});
      slog::Relation* readrel325 = db->getRelation("Start");
      driver_index = readrel325->getIndex(ord324, true);
  
    }
    ReadTask321(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c38, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m326) {
        u64 v_c41 = m326[1];
        if (buckethash(v_c41) != bucket) return;
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c41}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:26", "delta:Start", _fires);
  
      if (!_done)
      {
        ReadTask321* _cont = new ReadTask321(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask321(db,b), false);
  // (crule (pre) (scan step __t2Dgj21 s) (body (join reach (0) 1 s) (join step_ans (0 1) 1 __t2Dgj21 s_00027)) (head (emit reach (0) s_00027)) dem_head_guarded.slog:27 #f)
  class ReadTask329 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** reachindex327;  slog::Index** step_ansindex328;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      std::vector<u16> ord330({0});
      slog::Relation* readrel331 = db->getRelation("reach");
      head_index[0] = readrel331->getIndex(ord330, false);
      outer_rel = db->getRelation("step");
      std::vector<u16> ord332({0});
      slog::Relation* readrel333 = db->getRelation("reach");
      reachindex327 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({0, 1});
      slog::Relation* readrel335 = db->getRelation("step_ans");
      step_ansindex328 = readrel335->getIndex(ord334, false);
  
    }
    ReadTask329(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c42 = _t[0];
        u64 v_c43 = _t[1];
        slog::join_probe<1,1>(reachindex327, std::array<u64,1>{v_c43}, [&](const std::array<u64,1>& m336) {
          slog::join_probe<2,1>(step_ansindex328, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m337) {
            u64 v_c44 = m337[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c44}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:27", "delta:step", _fires);
  
      if (!_done)
      {
        ReadTask329* _cont = new ReadTask329(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask329(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre33K6102 __errf3Ypx103 __errf5f2w104 __errf3Ee6105 __errf0PJX106) (body) (head (emit error (0) __erre33K6102)) <internal>:1 #f)
  class ReadTask338 : public slog::Task
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
      std::vector<u16> ord339({0});
      slog::Relation* readrel340 = db->getRelation("error");
      head_index[0] = readrel340->getIndex(ord339, false);
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c45 = _t[0];
        u64 v_c46 = _t[1];
        u64 v_c47 = _t[2];
        u64 v_c48 = _t[3];
        u64 v_c49 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c45}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre) (scan toint_range __erre9hix94 __errf8DIJ95 __errf16bM96) (body) (head (emit error (0) __erre9hix94)) <internal>:1 #f)
  class ReadTask341 : public slog::Task
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
      std::vector<u16> ord342({0});
      slog::Relation* readrel343 = db->getRelation("error");
      head_index[0] = readrel343->getIndex(ord342, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask341(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c50}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask341* _cont = new ReadTask341(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask341(db,b), false);
  // (crule (pre) (scan reach s) (body (join-old step (1 0) 1 (1 0) s __t2Dgj21) (join-old step_ans (0 1) 1 (0 1) __t2Dgj21 s_00027)) (head (emit reach (0) s_00027)) dem_head_guarded.slog:27 #f)
  class ReadTask348 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** stepindex344;  slog::Index** step_ansindex345;  slog::Index** stepdelta346;  slog::Index** step_ansdelta347;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      std::vector<u16> ord349({0});
      slog::Relation* readrel350 = db->getRelation("reach");
      head_index[0] = readrel350->getIndex(ord349, false);
      outer_rel = db->getRelation("reach");
      std::vector<u16> ord351({1, 0});
      slog::Relation* readrel352 = db->getRelation("step");
      stepindex344 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 0});
      slog::Relation* readrel354 = db->getRelation("step");
      stepdelta346 = readrel354->getIndex(ord353, true);
      std::vector<u16> ord355({0, 1});
      slog::Relation* readrel356 = db->getRelation("step_ans");
      step_ansindex345 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("step_ans");
      step_ansdelta347 = readrel358->getIndex(ord357, true);
  
    }
    ReadTask348(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(stepindex344, stepdelta346, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m359) {
          u64 v_c42 = m359[1];
          slog::join_probe_old<2,1>(step_ansindex345, step_ansdelta347, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m360) {
            u64 v_c44 = m360[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c44}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:27", "delta:reach", _fires);
  
      if (!_done)
      {
        ReadTask348* _cont = new ReadTask348(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask348(db,b), false);
  // (crule (pre (let __tconst7jOM18 const5feceb66ffc86f38d952786c) (let __tconst7yxw16 constd4735e3a265e16eee03f5971)) (scan step __t4qfT20 __t8LH219) (body (join Start (0 1) 2 __t8LH219 __tconst7jOM18)) (head (mkstruct Ap (1 2 0) __t9hkM17 __tconst7yxw16 __tconst7jOM18)) dem_head_guarded.slog:31 #f)
  class ReadTask362 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Startindex361;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Ap");
      outer_rel = db->getRelation("step");
      std::vector<u16> ord363({0, 1});
      slog::Relation* readrel364 = db->getRelation("Start");
      Startindex361 = readrel364->getIndex(ord363, false);
  
    }
    ReadTask362(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c33 = _t[0];
        u64 v_c32 = _t[1];
        slog::join_probe<2,2>(Startindex361, std::array<u64,2>{v_c32, v_c30}, [&](const std::array<u64,2>& m365) {
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c31, v_c30}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:31", "delta:step", _fires);
  
      if (!_done)
      {
        ReadTask362* _cont = new ReadTask362(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask362(db,b), false);
  // (crule (pre (let __tconst0rYx8 const6b86b273ff34fce19d6b804e) (let __tconst70tI9 const99ee50221221864d50c60bae)) (scan $sup5130x35x0x0x0 __t2jdr6 k op) (body (exists okq_ans (1 0) 1 __tconst0rYx8) (exists okq (1 0) 1 op) (exists Ap (1 2 0) 2 op k) (join-old $sup5130x35x0x0x1 (2 3 0 1) 3 (2 3 0 1) k op __t2jdr6 __t6bDk7) (join okq_ans (1 0) 2 __tconst0rYx8 __t6bDk7) (join-old okq (0 1) 2 (0 1) __t6bDk7 op) (join-old Ap (1 2 0) 2 (1 2 0) op k __t0lCH5) (join-old step (0 1) 2 (0 1) __t2jdr6 __t0lCH5) (join mk_ans (0 1) 0 __t6KNu11 __v0) (let __t4XhT10 (_0002b op __tconst70tI9)) (join-old mk (0 1) 2 (0 1) __t6KNu11 __t4XhT10)) (head (emit-temp temp8P5b111 __t2jdr6 __v0) (mkstruct Done (1 0) __t3NKT4 __v0)) dem_head_guarded.slog:36 #f)
  class ReadTask381 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** okq_ansindex366;  slog::Index** okqindex367;  slog::Index** Apindex368;  slog::Index** $sup5130x35x0x0x1index369;  slog::Index** okq_ansindex370;  slog::Index** okqindex371;  slog::Index** Apindex372;  slog::Index** stepindex373;  slog::Index** mk_ansindex374;  slog::Index** mkindex375;  slog::Index** $sup5130x35x0x0x1delta376;  slog::Index** okqdelta377;  slog::Index** Apdelta378;  slog::Index** stepdelta379;  slog::Index** mkdelta380;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8P5b111");
      head_rel[1] = db->getRelation("Done");
      outer_rel = db->getRelation("$sup5130x35x0x0x0");
      std::vector<u16> ord382({1, 0});
      slog::Relation* readrel383 = db->getRelation("okq_ans");
      okq_ansindex366 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 0});
      slog::Relation* readrel385 = db->getRelation("okq");
      okqindex367 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 2, 0});
      slog::Relation* readrel387 = db->getRelation("Ap");
      Apindex368 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({2, 3, 0, 1});
      slog::Relation* readrel389 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index369 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({2, 3, 0, 1});
      slog::Relation* readrel391 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1delta376 = readrel391->getIndex(ord390, true);
      std::vector<u16> ord392({1, 0});
      slog::Relation* readrel393 = db->getRelation("okq_ans");
      okq_ansindex370 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({0, 1});
      slog::Relation* readrel395 = db->getRelation("okq");
      okqindex371 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1});
      slog::Relation* readrel397 = db->getRelation("okq");
      okqdelta377 = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({1, 2, 0});
      slog::Relation* readrel399 = db->getRelation("Ap");
      Apindex372 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 2, 0});
      slog::Relation* readrel401 = db->getRelation("Ap");
      Apdelta378 = readrel401->getIndex(ord400, true);
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("step");
      stepindex373 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("step");
      stepdelta379 = readrel405->getIndex(ord404, true);
      std::vector<u16> ord406({0, 1});
      slog::Relation* readrel407 = db->getRelation("mk_ans");
      mk_ansindex374 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({0, 1});
      slog::Relation* readrel409 = db->getRelation("mk");
      mkindex375 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 1});
      slog::Relation* readrel411 = db->getRelation("mk");
      mkdelta380 = readrel411->getIndex(ord410, true);
  
    }
    ReadTask381(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const99ee50221221864d50c60bae;
  
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
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<2,1>(okq_ansindex366, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(okqindex367, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<3,2>(Apindex368, std::array<u64,3>{v_c5, v_c4, 0})) return;
        slog::join_probe_old<4,3>($sup5130x35x0x0x1index369, $sup5130x35x0x0x1delta376, std::array<u64,4>{v_c4, v_c5, v_c2, 0}, [&](const std::array<u64,4>& m412) {
          u64 v_c3 = m412[3];
          slog::join_probe<2,2>(okq_ansindex370, std::array<u64,2>{v_c0, v_c3}, [&](const std::array<u64,2>& m413) {
            slog::join_probe_old<2,2>(okqindex371, okqdelta377, std::array<u64,2>{v_c3, v_c5}, [&](const std::array<u64,2>& m414) {
              slog::join_probe_old<3,2>(Apindex372, Apdelta378, std::array<u64,3>{v_c5, v_c4, 0}, [&](const std::array<u64,3>& m415) {
                u64 v_c6 = m415[2];
                slog::join_probe_old<2,2>(stepindex373, stepdelta379, std::array<u64,2>{v_c2, v_c6}, [&](const std::array<u64,2>& m416) {
                  slog::join_all<2>(mk_ansindex374, [&](const std::array<u64,2>& m417) {
                    u64 v_c7 = m417[0]; u64 v_c8 = m417[1];
                    u64 v_c9 = _prim__0002b(db, v_c5, v_c1);
                    if (v_c9 == slog_error) { slog::emit_pending_error(db, "dem_head_guarded.slog:36"); return; }
                    slog::join_probe_old<2,2>(mkindex375, mkdelta380, std::array<u64,2>{v_c7, v_c9}, [&](const std::array<u64,2>& m418) {
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c8});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:$sup5130x35x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask381* _cont = new ReadTask381(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask381(db,b), false);
  // (crule (pre) (scan int_overflow __erre6USv86 __errf1Zdp87 __errf9O5k88 __errf5kjD89) (body) (head (emit error (0) __erre6USv86)) <internal>:1 #f)
  class ReadTask419 : public slog::Task
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
      std::vector<u16> ord420({0});
      slog::Relation* readrel421 = db->getRelation("error");
      head_index[0] = readrel421->getIndex(ord420, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask419(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c53 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c55 = _t[2];
        u64 v_c56 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask419* _cont = new ReadTask419(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask419(db,b), false);
  // (crule (pre) (scan step_ans __t2Dgj21 s_00027) (body (join-old step (0 1) 1 (0 1) __t2Dgj21 s) (join reach (0) 1 s)) (head (emit reach (0) s_00027)) dem_head_guarded.slog:27 #f)
  class ReadTask425 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** stepindex422;  slog::Index** reachindex423;  slog::Index** stepdelta424;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      std::vector<u16> ord426({0});
      slog::Relation* readrel427 = db->getRelation("reach");
      head_index[0] = readrel427->getIndex(ord426, false);
      outer_rel = db->getRelation("step_ans");
      std::vector<u16> ord428({0, 1});
      slog::Relation* readrel429 = db->getRelation("step");
      stepindex422 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 1});
      slog::Relation* readrel431 = db->getRelation("step");
      stepdelta424 = readrel431->getIndex(ord430, true);
      std::vector<u16> ord432({0});
      slog::Relation* readrel433 = db->getRelation("reach");
      reachindex423 = readrel433->getIndex(ord432, false);
  
    }
    ReadTask425(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c42 = _t[0];
        u64 v_c44 = _t[1];
        slog::join_probe_old<2,1>(stepindex422, stepdelta424, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m434) {
          u64 v_c43 = m434[1];
          slog::join_probe<1,1>(reachindex423, std::array<u64,1>{v_c43}, [&](const std::array<u64,1>& m435) {
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c44}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:27", "delta:step_ans", _fires);
  
      if (!_done)
      {
        ReadTask425* _cont = new ReadTask425(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask425(db,b), false);
  // (crule (pre) (scan div_by_zero __erre4iNB80 __errf6Ey381 __errf9fe282) (body) (head (emit error (0) __erre4iNB80)) <internal>:1 #f)
  class ReadTask436 : public slog::Task
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
      std::vector<u16> ord437({0});
      slog::Relation* readrel438 = db->getRelation("error");
      head_index[0] = readrel438->getIndex(ord437, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask436(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c59 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask436* _cont = new ReadTask436(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask436(db,b), false);
  // (crule (pre) (scan nan_result __erre2ULd90 __errf6FMm91 __errf8kPf92 __errf9NJY93) (body) (head (emit error (0) __erre2ULd90)) <internal>:1 #f)
  class ReadTask439 : public slog::Task
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
      std::vector<u16> ord440({0});
      slog::Relation* readrel441 = db->getRelation("error");
      head_index[0] = readrel441->getIndex(ord440, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask439(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c60}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask439* _cont = new ReadTask439(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask439(db,b), false);
  // (crule (pre (let __tconst7jOM18 const5feceb66ffc86f38d952786c) (let __tconst7yxw16 constd4735e3a265e16eee03f5971)) (probe Ap (1 2 0) 2 __tconst7yxw16 __tconst7jOM18 __t9hkM17) (body (join Start (1 0) 1 __tconst7jOM18 __t8LH219) (join step (1 0) 1 __t8LH219 __t4qfT20)) (head (emit step_ans (0 1) __t4qfT20 __t9hkM17)) dem_head_guarded.slog:31 #f)
  class ReadTask444 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** Startindex442;  slog::Index** stepindex443;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("step_ans");
      std::vector<u16> ord445({0, 1});
      slog::Relation* readrel446 = db->getRelation("step_ans");
      head_index[0] = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 2, 0});
      slog::Relation* readrel448 = db->getRelation("Ap");
      driver_index = readrel448->getIndex(ord447, true);
      std::vector<u16> ord449({1, 0});
      slog::Relation* readrel450 = db->getRelation("Start");
      Startindex442 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({1, 0});
      slog::Relation* readrel452 = db->getRelation("step");
      stepindex443 = readrel452->getIndex(ord451, false);
  
    }
    ReadTask444(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c31, v_c30, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m453) {
        u64 v_c37 = m453[2];
        if (buckethash(v_c37) != bucket) return;
        slog::join_probe<2,1>(Startindex442, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m454) {
          u64 v_c32 = m454[1];
          slog::join_probe<2,1>(stepindex443, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m455) {
            u64 v_c33 = m455[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c33, v_c37}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:31", "delta:Ap", _fires);
  
      if (!_done)
      {
        ReadTask444* _cont = new ReadTask444(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask444(db,b), false);
  // (crule (pre (let __tconst0rYx8 const6b86b273ff34fce19d6b804e) (let __tconst70tI9 const99ee50221221864d50c60bae)) (scan okq __t6bDk7 op) (body (join okq_ans (1 0) 2 __tconst0rYx8 __t6bDk7) (exists $sup5130x35x0x0x0 (2 1 0) 1 op) (exists Ap (1 2 0) 1 op) (join $sup5130x35x0x0x1 (1 3 0 2) 2 __t6bDk7 op __t2jdr6 k) (join $sup5130x35x0x0x0 (2 1 0) 3 op k __t2jdr6) (join Ap (1 2 0) 2 op k __t0lCH5) (join step (0 1) 2 __t2jdr6 __t0lCH5) (join mk_ans (0 1) 0 __t6KNu11 __v0) (let __t4XhT10 (_0002b op __tconst70tI9)) (join-old mk (0 1) 2 (0 1) __t6KNu11 __t4XhT10)) (head (emit-temp temp8P5b111 __t2jdr6 __v0) (mkstruct Done (1 0) __t3NKT4 __v0)) dem_head_guarded.slog:36 #f)
  class ReadTask466 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** okq_ansindex456;  slog::Index** $sup5130x35x0x0x0index457;  slog::Index** Apindex458;  slog::Index** $sup5130x35x0x0x1index459;  slog::Index** $sup5130x35x0x0x0index460;  slog::Index** Apindex461;  slog::Index** stepindex462;  slog::Index** mk_ansindex463;  slog::Index** mkindex464;  slog::Index** mkdelta465;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8P5b111");
      head_rel[1] = db->getRelation("Done");
      outer_rel = db->getRelation("okq");
      std::vector<u16> ord467({1, 0});
      slog::Relation* readrel468 = db->getRelation("okq_ans");
      okq_ansindex456 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({2, 1, 0});
      slog::Relation* readrel470 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index457 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 2, 0});
      slog::Relation* readrel472 = db->getRelation("Ap");
      Apindex458 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 3, 0, 2});
      slog::Relation* readrel474 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index459 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({2, 1, 0});
      slog::Relation* readrel476 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index460 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 2, 0});
      slog::Relation* readrel478 = db->getRelation("Ap");
      Apindex461 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({0, 1});
      slog::Relation* readrel480 = db->getRelation("step");
      stepindex462 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({0, 1});
      slog::Relation* readrel482 = db->getRelation("mk_ans");
      mk_ansindex463 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({0, 1});
      slog::Relation* readrel484 = db->getRelation("mk");
      mkindex464 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({0, 1});
      slog::Relation* readrel486 = db->getRelation("mk");
      mkdelta465 = readrel486->getIndex(ord485, true);
  
    }
    ReadTask466(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const99ee50221221864d50c60bae;
  
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
        u64 v_c5 = _t[1];
        slog::join_probe<2,2>(okq_ansindex456, std::array<u64,2>{v_c0, v_c3}, [&](const std::array<u64,2>& m487) {
          if (!slog::exists_probe<3,1>($sup5130x35x0x0x0index457, std::array<u64,3>{v_c5, 0, 0})) return;
          if (!slog::exists_probe<3,1>(Apindex458, std::array<u64,3>{v_c5, 0, 0})) return;
          slog::join_probe<4,2>($sup5130x35x0x0x1index459, std::array<u64,4>{v_c3, v_c5, 0, 0}, [&](const std::array<u64,4>& m488) {
            u64 v_c2 = m488[2]; u64 v_c4 = m488[3];
            slog::join_probe<3,3>($sup5130x35x0x0x0index460, std::array<u64,3>{v_c5, v_c4, v_c2}, [&](const std::array<u64,3>& m489) {
              slog::join_probe<3,2>(Apindex461, std::array<u64,3>{v_c5, v_c4, 0}, [&](const std::array<u64,3>& m490) {
                u64 v_c6 = m490[2];
                slog::join_probe<2,2>(stepindex462, std::array<u64,2>{v_c2, v_c6}, [&](const std::array<u64,2>& m491) {
                  slog::join_all<2>(mk_ansindex463, [&](const std::array<u64,2>& m492) {
                    u64 v_c7 = m492[0]; u64 v_c8 = m492[1];
                    u64 v_c9 = _prim__0002b(db, v_c5, v_c1);
                    if (v_c9 == slog_error) { slog::emit_pending_error(db, "dem_head_guarded.slog:36"); return; }
                    slog::join_probe_old<2,2>(mkindex464, mkdelta465, std::array<u64,2>{v_c7, v_c9}, [&](const std::array<u64,2>& m493) {
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c8});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:okq", _fires);
  
      if (!_done)
      {
        ReadTask466* _cont = new ReadTask466(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask466(db,b), false);
  // (crule (pre (let __tconst0rYx8 const6b86b273ff34fce19d6b804e) (let __tconst70tI9 const99ee50221221864d50c60bae)) (scan Ap __t0lCH5 op k) (body (exists $sup5130x35x0x0x1 (2 3 0 1) 2 k op) (exists okq_ans (1 0) 1 __tconst0rYx8) (exists step (1 0) 1 __t0lCH5) (exists okq (1 0) 1 op) (join $sup5130x35x0x0x0 (2 1 0) 2 op k __t2jdr6) (exists step (0 1) 2 __t2jdr6 __t0lCH5) (join $sup5130x35x0x0x1 (2 3 0 1) 3 k op __t2jdr6 __t6bDk7) (join okq_ans (1 0) 2 __tconst0rYx8 __t6bDk7) (join-old step (0 1) 2 (0 1) __t2jdr6 __t0lCH5) (join-old okq (0 1) 2 (0 1) __t6bDk7 op) (join mk_ans (0 1) 0 __t6KNu11 __v0) (let __t4XhT10 (_0002b op __tconst70tI9)) (join-old mk (0 1) 2 (0 1) __t6KNu11 __t4XhT10)) (head (emit-temp temp8P5b111 __t2jdr6 __v0) (mkstruct Done (1 0) __t3NKT4 __v0)) dem_head_guarded.slog:36 #f)
  class ReadTask509 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5130x35x0x0x1index494;  slog::Index** okq_ansindex495;  slog::Index** stepindex496;  slog::Index** okqindex497;  slog::Index** $sup5130x35x0x0x0index498;  slog::Index** stepindex499;  slog::Index** $sup5130x35x0x0x1index500;  slog::Index** okq_ansindex501;  slog::Index** stepindex502;  slog::Index** okqindex503;  slog::Index** mk_ansindex504;  slog::Index** mkindex505;  slog::Index** stepdelta506;  slog::Index** okqdelta507;  slog::Index** mkdelta508;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8P5b111");
      head_rel[1] = db->getRelation("Done");
      outer_rel = db->getRelation("Ap");
      std::vector<u16> ord510({2, 3, 0, 1});
      slog::Relation* readrel511 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index494 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({1, 0});
      slog::Relation* readrel513 = db->getRelation("okq_ans");
      okq_ansindex495 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({1, 0});
      slog::Relation* readrel515 = db->getRelation("step");
      stepindex496 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 0});
      slog::Relation* readrel517 = db->getRelation("okq");
      okqindex497 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({2, 1, 0});
      slog::Relation* readrel519 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index498 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({0, 1});
      slog::Relation* readrel521 = db->getRelation("step");
      stepindex499 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({2, 3, 0, 1});
      slog::Relation* readrel523 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index500 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({1, 0});
      slog::Relation* readrel525 = db->getRelation("okq_ans");
      okq_ansindex501 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({0, 1});
      slog::Relation* readrel527 = db->getRelation("step");
      stepindex502 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({0, 1});
      slog::Relation* readrel529 = db->getRelation("step");
      stepdelta506 = readrel529->getIndex(ord528, true);
      std::vector<u16> ord530({0, 1});
      slog::Relation* readrel531 = db->getRelation("okq");
      okqindex503 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({0, 1});
      slog::Relation* readrel533 = db->getRelation("okq");
      okqdelta507 = readrel533->getIndex(ord532, true);
      std::vector<u16> ord534({0, 1});
      slog::Relation* readrel535 = db->getRelation("mk_ans");
      mk_ansindex504 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("mk");
      mkindex505 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({0, 1});
      slog::Relation* readrel539 = db->getRelation("mk");
      mkdelta508 = readrel539->getIndex(ord538, true);
  
    }
    ReadTask509(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const99ee50221221864d50c60bae;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<4,2>($sup5130x35x0x0x1index494, std::array<u64,4>{v_c4, v_c5, 0, 0})) return;
        if (!slog::exists_probe<2,1>(okq_ansindex495, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(stepindex496, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(okqindex497, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<3,2>($sup5130x35x0x0x0index498, std::array<u64,3>{v_c5, v_c4, 0}, [&](const std::array<u64,3>& m540) {
          u64 v_c2 = m540[2];
          if (!slog::exists_probe<2,2>(stepindex499, std::array<u64,2>{v_c2, v_c6})) return;
          slog::join_probe<4,3>($sup5130x35x0x0x1index500, std::array<u64,4>{v_c4, v_c5, v_c2, 0}, [&](const std::array<u64,4>& m541) {
            u64 v_c3 = m541[3];
            slog::join_probe<2,2>(okq_ansindex501, std::array<u64,2>{v_c0, v_c3}, [&](const std::array<u64,2>& m542) {
              slog::join_probe_old<2,2>(stepindex502, stepdelta506, std::array<u64,2>{v_c2, v_c6}, [&](const std::array<u64,2>& m543) {
                slog::join_probe_old<2,2>(okqindex503, okqdelta507, std::array<u64,2>{v_c3, v_c5}, [&](const std::array<u64,2>& m544) {
                  slog::join_all<2>(mk_ansindex504, [&](const std::array<u64,2>& m545) {
                    u64 v_c7 = m545[0]; u64 v_c8 = m545[1];
                    u64 v_c9 = _prim__0002b(db, v_c5, v_c1);
                    if (v_c9 == slog_error) { slog::emit_pending_error(db, "dem_head_guarded.slog:36"); return; }
                    slog::join_probe_old<2,2>(mkindex505, mkdelta508, std::array<u64,2>{v_c7, v_c9}, [&](const std::array<u64,2>& m546) {
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c8});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:Ap", _fires);
  
      if (!_done)
      {
        ReadTask509* _cont = new ReadTask509(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask509(db,b), false);
  // (crule (pre (let __tconst0rYx8 const6b86b273ff34fce19d6b804e) (let __tconst70tI9 const99ee50221221864d50c60bae)) (scan step __t2jdr6 __t0lCH5) (body (exists $sup5130x35x0x0x1 (0 1 2 3) 1 __t2jdr6) (exists $sup5130x35x0x0x0 (0 1 2) 1 __t2jdr6) (join okq_ans (1 0) 1 __tconst0rYx8 __t6bDk7) (join $sup5130x35x0x0x1 (0 1 2 3) 2 __t2jdr6 __t6bDk7 k op) (join $sup5130x35x0x0x0 (2 1 0) 3 op k __t2jdr6) (join Ap (1 2 0) 3 op k __t0lCH5) (join-old okq (0 1) 2 (0 1) __t6bDk7 op) (join mk_ans (0 1) 0 __t6KNu11 __v0) (let __t4XhT10 (_0002b op __tconst70tI9)) (join-old mk (0 1) 2 (0 1) __t6KNu11 __t4XhT10)) (head (emit-temp temp8P5b111 __t2jdr6 __v0) (mkstruct Done (1 0) __t3NKT4 __v0)) dem_head_guarded.slog:36 #f)
  class ReadTask558 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5130x35x0x0x1index547;  slog::Index** $sup5130x35x0x0x0index548;  slog::Index** okq_ansindex549;  slog::Index** $sup5130x35x0x0x1index550;  slog::Index** $sup5130x35x0x0x0index551;  slog::Index** Apindex552;  slog::Index** okqindex553;  slog::Index** mk_ansindex554;  slog::Index** mkindex555;  slog::Index** okqdelta556;  slog::Index** mkdelta557;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8P5b111");
      head_rel[1] = db->getRelation("Done");
      outer_rel = db->getRelation("step");
      std::vector<u16> ord559({0, 1, 2, 3});
      slog::Relation* readrel560 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index547 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({0, 1, 2});
      slog::Relation* readrel562 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index548 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 0});
      slog::Relation* readrel564 = db->getRelation("okq_ans");
      okq_ansindex549 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({0, 1, 2, 3});
      slog::Relation* readrel566 = db->getRelation("$sup5130x35x0x0x1");
      $sup5130x35x0x0x1index550 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({2, 1, 0});
      slog::Relation* readrel568 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index551 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({1, 2, 0});
      slog::Relation* readrel570 = db->getRelation("Ap");
      Apindex552 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({0, 1});
      slog::Relation* readrel572 = db->getRelation("okq");
      okqindex553 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({0, 1});
      slog::Relation* readrel574 = db->getRelation("okq");
      okqdelta556 = readrel574->getIndex(ord573, true);
      std::vector<u16> ord575({0, 1});
      slog::Relation* readrel576 = db->getRelation("mk_ans");
      mk_ansindex554 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({0, 1});
      slog::Relation* readrel578 = db->getRelation("mk");
      mkindex555 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({0, 1});
      slog::Relation* readrel580 = db->getRelation("mk");
      mkdelta557 = readrel580->getIndex(ord579, true);
  
    }
    ReadTask558(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const99ee50221221864d50c60bae;
  
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
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<4,1>($sup5130x35x0x0x1index547, std::array<u64,4>{v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>($sup5130x35x0x0x0index548, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(okq_ansindex549, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m581) {
          u64 v_c3 = m581[1];
          slog::join_probe<4,2>($sup5130x35x0x0x1index550, std::array<u64,4>{v_c2, v_c3, 0, 0}, [&](const std::array<u64,4>& m582) {
            u64 v_c4 = m582[2]; u64 v_c5 = m582[3];
            slog::join_probe<3,3>($sup5130x35x0x0x0index551, std::array<u64,3>{v_c5, v_c4, v_c2}, [&](const std::array<u64,3>& m583) {
              slog::join_probe<3,3>(Apindex552, std::array<u64,3>{v_c5, v_c4, v_c6}, [&](const std::array<u64,3>& m584) {
                slog::join_probe_old<2,2>(okqindex553, okqdelta556, std::array<u64,2>{v_c3, v_c5}, [&](const std::array<u64,2>& m585) {
                  slog::join_all<2>(mk_ansindex554, [&](const std::array<u64,2>& m586) {
                    u64 v_c7 = m586[0]; u64 v_c8 = m586[1];
                    u64 v_c9 = _prim__0002b(db, v_c5, v_c1);
                    if (v_c9 == slog_error) { slog::emit_pending_error(db, "dem_head_guarded.slog:36"); return; }
                    slog::join_probe_old<2,2>(mkindex555, mkdelta557, std::array<u64,2>{v_c7, v_c9}, [&](const std::array<u64,2>& m587) {
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c8});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:step", _fires);
  
      if (!_done)
      {
        ReadTask558* _cont = new ReadTask558(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask558(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre3buI75 __errf3fHJ76 __errf3wKr77 __errf4GHa78 __errf1xXW79) (body) (head (emit error (0) __erre3buI75)) <internal>:1 #f)
  class ReadTask588 : public slog::Task
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
      std::vector<u16> ord589({0});
      slog::Relation* readrel590 = db->getRelation("error");
      head_index[0] = readrel590->getIndex(ord589, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask588(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c64 = _t[0];
        u64 v_c65 = _t[1];
        u64 v_c66 = _t[2];
        u64 v_c67 = _t[3];
        u64 v_c68 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c64}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask588* _cont = new ReadTask588(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask588(db,b), false);
  // (crule (pre) (scan temp8P5b111 __t2jdr6 __v0) (body (join Done (1 0) 1 __v0 __t3NKT4)) (head (emit step_ans (0 1) __t2jdr6 __t3NKT4)) dem_head_guarded.slog:36 #f)
  class ReadTask592 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Doneindex591;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("step_ans");
      std::vector<u16> ord593({0, 1});
      slog::Relation* readrel594 = db->getRelation("step_ans");
      head_index[0] = readrel594->getIndex(ord593, false);
      outer_rel = db->getRelation("temp8P5b111");
      std::vector<u16> ord595({1, 0});
      slog::Relation* readrel596 = db->getRelation("Done");
      Doneindex591 = readrel596->getIndex(ord595, false);
  
    }
    ReadTask592(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[0];
        u64 v_c8 = _t[1];
        slog::join_probe<2,1>(Doneindex591, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m597) {
          u64 v_c69 = m597[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c2, v_c69}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:temp8P5b111", _fires);
  
      if (!_done)
      {
        ReadTask592* _cont = new ReadTask592(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask592(db,b), false);
  // (crule (pre (let __tconst1G9T13 const6b86b273ff34fce19d6b804e)) (scan $sup5130x35x0x0x0 __d0 k op) (body (exists okq (1 0) 1 op) (join-old okq_ans (1 0) 1 (1 0) __tconst1G9T13 __t6NE412) (join-old okq (0 1) 2 (0 1) __t6NE412 op)) (head (emit $sup5130x35x0x0x1 (0 1 2 3) __d0 __t6NE412 k op)) dem_head_guarded.slog:36 #f)
  class ReadTask603 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** okqindex598;  slog::Index** okq_ansindex599;  slog::Index** okqindex600;  slog::Index** okq_ansdelta601;  slog::Index** okqdelta602;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5130x35x0x0x1");
      std::vector<u16> ord604({0, 1, 2, 3});
      slog::Relation* readrel605 = db->getRelation("$sup5130x35x0x0x1");
      head_index[0] = readrel605->getIndex(ord604, false);
      outer_rel = db->getRelation("$sup5130x35x0x0x0");
      std::vector<u16> ord606({1, 0});
      slog::Relation* readrel607 = db->getRelation("okq");
      okqindex598 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({1, 0});
      slog::Relation* readrel609 = db->getRelation("okq_ans");
      okq_ansindex599 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 0});
      slog::Relation* readrel611 = db->getRelation("okq_ans");
      okq_ansdelta601 = readrel611->getIndex(ord610, true);
      std::vector<u16> ord612({0, 1});
      slog::Relation* readrel613 = db->getRelation("okq");
      okqindex600 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({0, 1});
      slog::Relation* readrel615 = db->getRelation("okq");
      okqdelta602 = readrel615->getIndex(ord614, true);
  
    }
    ReadTask603(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<2,1>(okqindex598, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe_old<2,1>(okq_ansindex599, okq_ansdelta601, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m616) {
          u64 v_c40 = m616[1];
          slog::join_probe_old<2,2>(okqindex600, okqdelta602, std::array<u64,2>{v_c40, v_c5}, [&](const std::array<u64,2>& m617) {
            ++_fires;
            slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c21, v_c40, v_c4, v_c5}, std::array<u16,4>{0, 1, 2, 3});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:$sup5130x35x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask603* _cont = new ReadTask603(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask603(db,b), false);
  // (crule (pre (let __tconst1G9T13 const6b86b273ff34fce19d6b804e)) (scan okq __t6NE412 op) (body (join okq_ans (1 0) 2 __tconst1G9T13 __t6NE412) (join $sup5130x35x0x0x0 (2 1 0) 1 op k __d0)) (head (emit $sup5130x35x0x0x1 (0 1 2 3) __d0 __t6NE412 k op)) dem_head_guarded.slog:36 #f)
  class ReadTask620 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** okq_ansindex618;  slog::Index** $sup5130x35x0x0x0index619;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5130x35x0x0x1");
      std::vector<u16> ord621({0, 1, 2, 3});
      slog::Relation* readrel622 = db->getRelation("$sup5130x35x0x0x1");
      head_index[0] = readrel622->getIndex(ord621, false);
      outer_rel = db->getRelation("okq");
      std::vector<u16> ord623({1, 0});
      slog::Relation* readrel624 = db->getRelation("okq_ans");
      okq_ansindex618 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({2, 1, 0});
      slog::Relation* readrel626 = db->getRelation("$sup5130x35x0x0x0");
      $sup5130x35x0x0x0index619 = readrel626->getIndex(ord625, false);
  
    }
    ReadTask620(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<2,2>(okq_ansindex618, std::array<u64,2>{v_c39, v_c40}, [&](const std::array<u64,2>& m627) {
          slog::join_probe<3,1>($sup5130x35x0x0x0index619, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m628) {
            u64 v_c4 = m628[1]; u64 v_c21 = m628[2];
            ++_fires;
            slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c21, v_c40, v_c4, v_c5}, std::array<u16,4>{0, 1, 2, 3});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:okq", _fires);
  
      if (!_done)
      {
        ReadTask620* _cont = new ReadTask620(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask620(db,b), false);
  // (crule (pre) (scan mk __t7Y3M14 v) (body) (head (emit mk_ans (0 1) __t7Y3M14 v) (emit store (0) v)) dem_head_guarded.slog:15 #f)
  class ReadTask629 : public slog::Task
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
      head_rel[0] = db->getRelation("mk_ans");
      std::vector<u16> ord630({0, 1});
      slog::Relation* readrel631 = db->getRelation("mk_ans");
      head_index[0] = readrel631->getIndex(ord630, false);
      head_rel[1] = db->getRelation("store");
      std::vector<u16> ord632({0});
      slog::Relation* readrel633 = db->getRelation("store");
      head_index[1] = readrel633->getIndex(ord632, false);
      outer_rel = db->getRelation("mk");
  
    }
    ReadTask629(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c70 = _t[0];
        u64 v_c71 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c70, v_c71}, std::array<u16,2>{0, 1});
        slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:15", "delta:mk", _fires);
  
      if (!_done)
      {
        ReadTask629* _cont = new ReadTask629(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask629(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre5DUM107 __errf97hn108 __errf7uYp109) (body) (head (emit error (0) __erre5DUM107)) <internal>:1 #f)
  class ReadTask634 : public slog::Task
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
      std::vector<u16> ord635({0});
      slog::Relation* readrel636 = db->getRelation("error");
      head_index[0] = readrel636->getIndex(ord635, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask634(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c72 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c74 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c72}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre) (scan reach s) (body) (head (mkstruct step (1 0) __7xP838 s)) dem_head_guarded.slog:27 #f)
  class ReadTask637 : public slog::Task
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
      head_rel[0] = db->getRelation("step");
      outer_rel = db->getRelation("reach");
  
    }
    ReadTask637(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c43}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:27", "delta:reach", _fires);
  
      if (!_done)
      {
        ReadTask637* _cont = new ReadTask637(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask637(db,b), false);
  // (crule (pre (let __trid7IzR35 constb6579dd3e29d8cc73668c256) (let __trel34l336 const51f9fd68d7e9c802b42378d7) (let __tcol3S7Q37 const5feceb66ffc86f38d952786c)) (scan $sup5130x35x0x0x0 __d0 k op) (body) (head (tycheck op (accept int) __trid7IzR35 __trel34l336 __tcol3S7Q37 (1 2 3 4 0)) (mkstruct okq (1 0) __9EgW34 op)) dem_head_guarded.slog:36 #f)
  class ReadTask638 : public slog::Task
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
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("okq");
      outer_rel = db->getRelation("$sup5130x35x0x0x0");
  
    }
    ReadTask638(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c75 = v_constb6579dd3e29d8cc73668c256;
      u64 v_c76 = v_const51f9fd68d7e9c802b42378d7;
      u64 v_c77 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        ++_fires;
        if (!(is_int(v_c5)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c75, v_c76, v_c77, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c5}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_head_guarded.slog:36", "delta:$sup5130x35x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask638* _cont = new ReadTask638(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask638(db,b), false);
  s->addReadRel("$sup5130x35x0x0x0");
  s->addReadRel("$sup5130x35x0x0x1");
  s->addReadRel("Ap");
  s->addReadRel("Done");
  s->addReadRel("Start");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("mk");
  s->addReadRel("mk_ans");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("okq");
  s->addReadRel("okq_ans");
  s->addReadRel("okt");
  s->addReadRel("reach");
  s->addReadRel("step");
  s->addReadRel("step_ans");
  s->addReadRel("temp8P5b111");
  s->addReadRel("temp8lsc110");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$sup5130x35x0x0x0");
  s->addDynamicRel("$sup5130x35x0x0x1");
  s->addDynamicRel("Ap");
  s->addDynamicRel("Done");
  s->addDynamicRel("Start");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("mk");
  s->addDynamicRel("mk_ans");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("okq");
  s->addDynamicRel("okq_ans");
  s->addDynamicRel("reach");
  s->addDynamicRel("step");
  s->addDynamicRel("step_ans");
  s->addDynamicRel("store");
  s->addDynamicRel("temp8P5b111");
  s->addDynamicRel("temp8lsc110");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("mk_ans");
  s->addAccelRel("okq_ans");
  s->addAccelRel("reach");
  s->addAccelRel("step_ans");
  s->addAccelRel("store");
  d->push(s);
  d->continueRun();
}

