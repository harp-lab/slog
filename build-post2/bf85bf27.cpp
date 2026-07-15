
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_constebbe2dfbb019b8256cb73d30;
u64 v_const2d53b3c21fa5cc786ac46d72;
u64 v_constd1a4dc8b61ef51fa5f72b229;
u64 v_const7265b875feb0d1730ead43d3;
u64 v_const20c400557af0eddc0be4d9e0;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("bf85bf27");
  if (s == nullptr) return;
  slog::Relation* r;
  v_constebbe2dfbb019b8256cb73d30 = db->encodeString("dummy");
  v_const2d53b3c21fa5cc786ac46d72 = db->encodeString("id");
  v_constd1a4dc8b61ef51fa5f72b229 = db->encodeString("v");
  v_const7265b875feb0d1730ead43d3 = db->encodeString("w");
  v_const20c400557af0eddc0be4d9e0 = db->encodeString("z");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord822({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord822, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord823({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord823, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord824({1, 2, 0});
    
    r->addIndex<3>(ord824, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord825({0, 1, 2});
    
    r->addIndex<3>(ord825, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("store");
  if (r == 0) db->addRelation("store", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("store");
      std::vector<u16> ord826({0, 1});
    
    r->addIndex<2>(ord826, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("store"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord827({1, 2, 0});
    
    r->addIndex<3>(ord827, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord828({0, 1, 2});
    
    r->addIndex<3>(ord828, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("singleton");
  if (r == 0) db->addRelation("singleton", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("singleton");
      std::vector<u16> ord829({0});
    
    r->addIndex<1>(ord829, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("singleton"), std::array<u16,1>{0}, b));
  r = db->getRelation("result");
  if (r == 0) db->addRelation("result", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("result");
      std::vector<u16> ord830({0});
    
    r->addIndex<1>(ord830, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("result"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord831({1, 0});
    
    r->addIndex<2>(ord831, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord832({0, 1});
    
    r->addIndex<2>(ord832, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord833({1, 0});
    
    r->addIndex<2>(ord833, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("program");
  if (r == 0) db->addRelation("program", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program");
      std::vector<u16> ord834({0});
    
    r->addIndex<1>(ord834, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program"), std::array<u16,1>{0}, b));
  r = db->getRelation("polyvariant");
  if (r == 0) db->addRelation("polyvariant", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("polyvariant");
      std::vector<u16> ord835({0});
    
    r->addIndex<1>(ord835, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("polyvariant"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord836({1, 2, 3, 0});
    
    r->addIndex<4>(ord836, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord837({0, 1, 2, 3});
    
    r->addIndex<4>(ord837, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mu");
  if (r == 0) db->addRelation("mu", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mu");
  r->setLattice(LAT_COUNT, false, 0, false, 0, "count", db->collections());
      std::vector<u16> ord838({0, 1});
    
    r->addMapIndex<2>(ord838);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<2>(db, r, std::array<u16,2>{0, 1}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<2>(db, db->getRelation("mu"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord839({1, 2, 0});
    
    r->addIndex<3>(ord839, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord840({0, 1, 2});
    
    r->addIndex<3>(ord840, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord841({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord841, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord842({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord842, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord843({1, 2, 0});
    
    r->addIndex<3>(ord843, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord844({0, 1, 2});
    
    r->addIndex<3>(ord844, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord845({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord845, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord846({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord846, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lambda");
  if (r == 0) db->addStruct("lambda", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lambda");
      std::vector<u16> ord847({1, 2, 0});
    
    r->addIndex<3>(ord847, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord848({0, 1, 2});
    
    r->addIndex<3>(ord848, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord849({1, 0, 2});
    
    r->addIndex<3>(ord849, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lambda"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord850({1, 2, 3, 0});
    
    r->addIndex<4>(ord850, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord851({0, 1, 2, 3});
    
    r->addIndex<4>(ord851, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("eval_ans");
  if (r == 0) db->addRelation("eval_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval_ans");
      std::vector<u16> ord852({0, 1});
    
    r->addIndex<2>(ord852, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("eval");
  if (r == 0) db->addStruct("eval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval");
      std::vector<u16> ord853({1, 0});
    
    r->addIndex<2>(ord853, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord854({0, 1});
    
    r->addIndex<2>(ord854, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("eval"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord855({0});
    
    r->addIndex<1>(ord855, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord856({1, 2, 0});
    
    r->addIndex<3>(ord856, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord857({0, 1, 2});
    
    r->addIndex<3>(ord857, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("app");
  if (r == 0) db->addStruct("app", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("app");
      std::vector<u16> ord858({1, 2, 0});
    
    r->addIndex<3>(ord858, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord859({0, 1, 2});
    
    r->addIndex<3>(ord859, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord860({2, 0, 1});
    
    r->addIndex<3>(ord860, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("app"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord861({1, 0});
    
    r->addIndex<2>(ord861, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord862({0, 1});
    
    r->addIndex<2>(ord862, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup7183x51x0x0x0");
  if (r == 0) db->addRelation("$sup7183x51x0x0x0", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup7183x51x0x0x0");
      std::vector<u16> ord863({0, 1});
    
    r->addIndex<2>(ord863, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("$sup7183x51x0x0x0"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("$sup7183x46x0x0x1");
  if (r == 0) db->addRelation("$sup7183x46x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup7183x46x0x0x1");
      std::vector<u16> ord864({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord864, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup7183x46x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup7183x46x0x0x0");
  if (r == 0) db->addRelation("$sup7183x46x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup7183x46x0x0x0");
      std::vector<u16> ord865({0, 1, 2});
    
    r->addIndex<3>(ord865, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup7183x46x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229)) (scan app __t5tyC24 __t0x9n23 __t42Ov4) (body (exists ref (1 0) 1 __tconst7J8s3) (exists lambda (0 1 2) 2 __t0x9n23 __tconst7VEl22) (exists ref (1 0) 1 __tconst7VEl22) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst5ulH19) (exists lambda (1 2 0) 1 __tconst5bLs14) (exists ref (1 0) 1 __tconst5bLs14) (join lambda (0 1 2) 2 __t42Ov4 __tconst7J8s3 __t4qH72) (join ref (0 1) 2 __t4qH72 __tconst7J8s3) (join lambda (0 1 2) 2 __t0x9n23 __tconst7VEl22 __t7ta721) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (exists app (1 2 0) 1 __t9TqL10) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join app (1 2 0) 2 __t9TqL10 __t92Rs8 __t8l1u11) (join app (2 0 1) 2 __t8l1u11 __t7ta721 __t3mzq20) (join lambda (0 1 2) 2 __t3mzq20 __tconst5ulH19 __t0Sfq18) (join app (0 1 2) 2 __t0Sfq18 __t9TqL10 __t9d0g15) (join lambda (0 1 2) 2 __t9d0g15 __tconst5bLs14 __t69od13) (join ref (0 1) 2 __t69od13 __tconst5bLs14)) (head (emit program (0) __t5tyC24)) 0cfa-counting.slog:68 #f)
  class ReadTask21 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex0;  slog::Index** lambdaindex1;  slog::Index** refindex2;  slog::Index** refindex3;  slog::Index** lambdaindex4;  slog::Index** lambdaindex5;  slog::Index** lambdaindex6;  slog::Index** refindex7;  slog::Index** lambdaindex8;  slog::Index** refindex9;  slog::Index** lambdaindex10;  slog::Index** refindex11;  slog::Index** appindex12;  slog::Index** refindex13;  slog::Index** lambdaindex14;  slog::Index** appindex15;  slog::Index** appindex16;  slog::Index** lambdaindex17;  slog::Index** appindex18;  slog::Index** lambdaindex19;  slog::Index** refindex20;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord22({0});
      slog::Relation* readrel23 = db->getRelation("program");
      head_index[0] = readrel23->getIndex(ord22, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord24({1, 0});
      slog::Relation* readrel25 = db->getRelation("ref");
      refindex0 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({0, 1, 2});
      slog::Relation* readrel27 = db->getRelation("lambda");
      lambdaindex1 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 0});
      slog::Relation* readrel29 = db->getRelation("ref");
      refindex2 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 0});
      slog::Relation* readrel31 = db->getRelation("ref");
      refindex3 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 2, 0});
      slog::Relation* readrel33 = db->getRelation("lambda");
      lambdaindex4 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 2, 0});
      slog::Relation* readrel35 = db->getRelation("lambda");
      lambdaindex5 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 2, 0});
      slog::Relation* readrel37 = db->getRelation("lambda");
      lambdaindex6 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 0});
      slog::Relation* readrel39 = db->getRelation("ref");
      refindex7 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({0, 1, 2});
      slog::Relation* readrel41 = db->getRelation("lambda");
      lambdaindex8 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({0, 1});
      slog::Relation* readrel43 = db->getRelation("ref");
      refindex9 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({0, 1, 2});
      slog::Relation* readrel45 = db->getRelation("lambda");
      lambdaindex10 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 0});
      slog::Relation* readrel47 = db->getRelation("ref");
      refindex11 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 2, 0});
      slog::Relation* readrel49 = db->getRelation("app");
      appindex12 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("ref");
      refindex13 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 2, 0});
      slog::Relation* readrel53 = db->getRelation("lambda");
      lambdaindex14 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 2, 0});
      slog::Relation* readrel55 = db->getRelation("app");
      appindex15 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({2, 0, 1});
      slog::Relation* readrel57 = db->getRelation("app");
      appindex16 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({0, 1, 2});
      slog::Relation* readrel59 = db->getRelation("lambda");
      lambdaindex17 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({0, 1, 2});
      slog::Relation* readrel61 = db->getRelation("app");
      appindex18 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({0, 1, 2});
      slog::Relation* readrel63 = db->getRelation("lambda");
      lambdaindex19 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({0, 1});
      slog::Relation* readrel65 = db->getRelation("ref");
      refindex20 = readrel65->getIndex(ord64, false);
  
    }
    ReadTask21(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<2,1>(refindex0, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,2>(lambdaindex1, std::array<u64,3>{v_c6, v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex3, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex4, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex5, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex6, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex7, std::array<u64,2>{v_c4, 0})) return;
        slog::join_probe<3,2>(lambdaindex8, std::array<u64,3>{v_c7, v_c1, 0}, [&](const std::array<u64,3>& m66) {
          u64 v_c8 = m66[2];
          slog::join_probe<2,2>(refindex9, std::array<u64,2>{v_c8, v_c1}, [&](const std::array<u64,2>& m67) {
            slog::join_probe<3,2>(lambdaindex10, std::array<u64,3>{v_c6, v_c0, 0}, [&](const std::array<u64,3>& m68) {
              u64 v_c9 = m68[2];
              slog::join_probe<2,1>(refindex11, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m69) {
                u64 v_c10 = m69[1];
                if (!slog::exists_probe<3,1>(appindex12, std::array<u64,3>{v_c10, 0, 0})) return;
                slog::join_probe<2,1>(refindex13, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m70) {
                  u64 v_c11 = m70[1];
                  slog::join_probe<3,2>(lambdaindex14, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m71) {
                    u64 v_c12 = m71[2];
                    slog::join_probe<3,2>(appindex15, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m72) {
                      u64 v_c13 = m72[2];
                      slog::join_probe<3,2>(appindex16, std::array<u64,3>{v_c13, v_c9, 0}, [&](const std::array<u64,3>& m73) {
                        u64 v_c14 = m73[2];
                        slog::join_probe<3,2>(lambdaindex17, std::array<u64,3>{v_c14, v_c2, 0}, [&](const std::array<u64,3>& m74) {
                          u64 v_c15 = m74[2];
                          slog::join_probe<3,2>(appindex18, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m75) {
                            u64 v_c16 = m75[2];
                            slog::join_probe<3,2>(lambdaindex19, std::array<u64,3>{v_c16, v_c4, 0}, [&](const std::array<u64,3>& m76) {
                              u64 v_c17 = m76[2];
                              slog::join_probe<2,2>(refindex20, std::array<u64,2>{v_c17, v_c4}, [&](const std::array<u64,2>& m77) {
                                ++_fires;
                                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
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
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask21* _cont = new ReadTask21(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask21(db,b), false);
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229)) (seeded) (body (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (exists ref (1 0) 1 __tconst7VEl22) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists ref (1 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5ulH19) (exists lambda (1 2 0) 1 __tconst7VEl22) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (exists app (1 2 0) 1 __t9TqL10) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join app (1 2 0) 2 __t9TqL10 __t92Rs8 __t8l1u11) (exists app (2 0 1) 1 __t8l1u11) (join ref (1 0) 1 __tconst5bLs14 __t69od13) (join lambda (1 2 0) 2 __tconst5bLs14 __t69od13 __t9d0g15) (join app (1 2 0) 2 __t9TqL10 __t9d0g15 __t0Sfq18) (join lambda (1 2 0) 2 __tconst5ulH19 __t0Sfq18 __t3mzq20) (join app (1 2 0) 2 __t3mzq20 __t8l1u11 __t7ta721) (join lambda (1 2 0) 2 __tconst7VEl22 __t7ta721 __t0x9n23)) (head (mkstruct app (1 2 0) __t5tyC24 __t0x9n23 __t42Ov4)) 0cfa-counting.slog:68 #f)
  class ReadTask99 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex78;  slog::Index** refindex79;  slog::Index** refindex80;  slog::Index** lambdaindex81;  slog::Index** refindex82;  slog::Index** lambdaindex83;  slog::Index** lambdaindex84;  slog::Index** lambdaindex85;  slog::Index** lambdaindex86;  slog::Index** refindex87;  slog::Index** appindex88;  slog::Index** refindex89;  slog::Index** lambdaindex90;  slog::Index** appindex91;  slog::Index** appindex92;  slog::Index** refindex93;  slog::Index** lambdaindex94;  slog::Index** appindex95;  slog::Index** lambdaindex96;  slog::Index** appindex97;  slog::Index** lambdaindex98;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord100({1, 2, 0});
      slog::Relation* readrel101 = db->getRelation("app");
      head_index[0] = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 0});
      slog::Relation* readrel103 = db->getRelation("ref");
      refindex78 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 0});
      slog::Relation* readrel105 = db->getRelation("ref");
      refindex79 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 0});
      slog::Relation* readrel107 = db->getRelation("ref");
      refindex80 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 0});
      slog::Relation* readrel109 = db->getRelation("lambda");
      lambdaindex81 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 0});
      slog::Relation* readrel111 = db->getRelation("ref");
      refindex82 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 2, 0});
      slog::Relation* readrel113 = db->getRelation("lambda");
      lambdaindex83 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({1, 2, 0});
      slog::Relation* readrel115 = db->getRelation("lambda");
      lambdaindex84 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 0});
      slog::Relation* readrel117 = db->getRelation("lambda");
      lambdaindex85 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 2, 0});
      slog::Relation* readrel119 = db->getRelation("lambda");
      lambdaindex86 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 0});
      slog::Relation* readrel121 = db->getRelation("ref");
      refindex87 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 2, 0});
      slog::Relation* readrel123 = db->getRelation("app");
      appindex88 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 0});
      slog::Relation* readrel125 = db->getRelation("ref");
      refindex89 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("lambda");
      lambdaindex90 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("app");
      appindex91 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({2, 0, 1});
      slog::Relation* readrel131 = db->getRelation("app");
      appindex92 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("ref");
      refindex93 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 2, 0});
      slog::Relation* readrel135 = db->getRelation("lambda");
      lambdaindex94 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("app");
      appindex95 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("lambda");
      lambdaindex96 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 0});
      slog::Relation* readrel141 = db->getRelation("app");
      appindex97 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0});
      slog::Relation* readrel143 = db->getRelation("lambda");
      lambdaindex98 = readrel143->getIndex(ord142, false);
  
    }
    ReadTask99(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex78, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m144) {
        u64 v_c8 = m144[1];
        if (!slog::exists_probe<2,1>(refindex79, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex80, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex81, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex82, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex83, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex84, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex85, std::array<u64,3>{v_c0, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex86, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m145) {
          u64 v_c7 = m145[2];
          slog::join_probe<2,1>(refindex87, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m146) {
            u64 v_c10 = m146[1];
            if (!slog::exists_probe<3,1>(appindex88, std::array<u64,3>{v_c10, 0, 0})) return;
            slog::join_probe<2,1>(refindex89, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m147) {
              u64 v_c11 = m147[1];
              slog::join_probe<3,2>(lambdaindex90, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m148) {
                u64 v_c12 = m148[2];
                slog::join_probe<3,2>(appindex91, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m149) {
                  u64 v_c13 = m149[2];
                  if (!slog::exists_probe<3,1>(appindex92, std::array<u64,3>{v_c13, 0, 0})) return;
                  slog::join_probe<2,1>(refindex93, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m150) {
                    u64 v_c17 = m150[1];
                    slog::join_probe<3,2>(lambdaindex94, std::array<u64,3>{v_c4, v_c17, 0}, [&](const std::array<u64,3>& m151) {
                      u64 v_c16 = m151[2];
                      slog::join_probe<3,2>(appindex95, std::array<u64,3>{v_c10, v_c16, 0}, [&](const std::array<u64,3>& m152) {
                        u64 v_c15 = m152[2];
                        slog::join_probe<3,2>(lambdaindex96, std::array<u64,3>{v_c2, v_c15, 0}, [&](const std::array<u64,3>& m153) {
                          u64 v_c14 = m153[2];
                          slog::join_probe<3,2>(appindex97, std::array<u64,3>{v_c14, v_c13, 0}, [&](const std::array<u64,3>& m154) {
                            u64 v_c9 = m154[2];
                            slog::join_probe<3,2>(lambdaindex98, std::array<u64,3>{v_c0, v_c9, 0}, [&](const std::array<u64,3>& m155) {
                              u64 v_c6 = m155[2];
                              ++_fires;
                              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c7}, std::array<u16,3>{1, 2, 0});
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask99(db,b));
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229)) (scan app __t7ta721 __t3mzq20 __t8l1u11) (body (exists ref (1 0) 1 __tconst7VEl22) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst5bLs14) (exists ref (1 0) 1 __tconst5bLs14) (exists ref (1 0) 1 __tconst7J8s3) (exists lambda (1 2 0) 1 __tconst7J8s3) (join lambda (0 1 2) 2 __t3mzq20 __tconst5ulH19 __t0Sfq18) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (exists app (0 1 2) 2 __t0Sfq18 __t9TqL10) (join app (0 1 2) 2 __t8l1u11 __t9TqL10 __t92Rs8) (join lambda (0 1 2) 2 __t92Rs8 __tconst6HRD7 __t6qhP6) (join ref (0 1) 2 __t6qhP6 __tconst6HRD7) (join app (0 1 2) 2 __t0Sfq18 __t9TqL10 __t9d0g15) (join lambda (0 1 2) 2 __t9d0g15 __tconst5bLs14 __t69od13) (join ref (0 1) 2 __t69od13 __tconst5bLs14) (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4)) (head (mkstruct lambda (1 2 0) __t0x9n23 __tconst7VEl22 __t7ta721)) 0cfa-counting.slog:68 #f)
  class ReadTask174 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex156;  slog::Index** lambdaindex157;  slog::Index** refindex158;  slog::Index** lambdaindex159;  slog::Index** refindex160;  slog::Index** refindex161;  slog::Index** lambdaindex162;  slog::Index** lambdaindex163;  slog::Index** refindex164;  slog::Index** appindex165;  slog::Index** appindex166;  slog::Index** lambdaindex167;  slog::Index** refindex168;  slog::Index** appindex169;  slog::Index** lambdaindex170;  slog::Index** refindex171;  slog::Index** refindex172;  slog::Index** lambdaindex173;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord175({1, 0});
      slog::Relation* readrel176 = db->getRelation("ref");
      refindex156 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("lambda");
      lambdaindex157 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 0});
      slog::Relation* readrel180 = db->getRelation("ref");
      refindex158 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("lambda");
      lambdaindex159 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 0});
      slog::Relation* readrel184 = db->getRelation("ref");
      refindex160 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 0});
      slog::Relation* readrel186 = db->getRelation("ref");
      refindex161 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 2, 0});
      slog::Relation* readrel188 = db->getRelation("lambda");
      lambdaindex162 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({0, 1, 2});
      slog::Relation* readrel190 = db->getRelation("lambda");
      lambdaindex163 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 0});
      slog::Relation* readrel192 = db->getRelation("ref");
      refindex164 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({0, 1, 2});
      slog::Relation* readrel194 = db->getRelation("app");
      appindex165 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({0, 1, 2});
      slog::Relation* readrel196 = db->getRelation("app");
      appindex166 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({0, 1, 2});
      slog::Relation* readrel198 = db->getRelation("lambda");
      lambdaindex167 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({0, 1});
      slog::Relation* readrel200 = db->getRelation("ref");
      refindex168 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({0, 1, 2});
      slog::Relation* readrel202 = db->getRelation("app");
      appindex169 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1, 2});
      slog::Relation* readrel204 = db->getRelation("lambda");
      lambdaindex170 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({0, 1});
      slog::Relation* readrel206 = db->getRelation("ref");
      refindex171 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 0});
      slog::Relation* readrel208 = db->getRelation("ref");
      refindex172 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 0});
      slog::Relation* readrel210 = db->getRelation("lambda");
      lambdaindex173 = readrel210->getIndex(ord209, false);
  
    }
    ReadTask174(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c13 = _t[2];
        if (!slog::exists_probe<2,1>(refindex156, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex157, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex158, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex159, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex160, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(refindex161, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex162, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex163, std::array<u64,3>{v_c14, v_c2, 0}, [&](const std::array<u64,3>& m211) {
          u64 v_c15 = m211[2];
          slog::join_probe<2,1>(refindex164, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m212) {
            u64 v_c10 = m212[1];
            if (!slog::exists_probe<3,2>(appindex165, std::array<u64,3>{v_c15, v_c10, 0})) return;
            slog::join_probe<3,2>(appindex166, std::array<u64,3>{v_c13, v_c10, 0}, [&](const std::array<u64,3>& m213) {
              u64 v_c12 = m213[2];
              slog::join_probe<3,2>(lambdaindex167, std::array<u64,3>{v_c12, v_c3, 0}, [&](const std::array<u64,3>& m214) {
                u64 v_c11 = m214[2];
                slog::join_probe<2,2>(refindex168, std::array<u64,2>{v_c11, v_c3}, [&](const std::array<u64,2>& m215) {
                  slog::join_probe<3,2>(appindex169, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m216) {
                    u64 v_c16 = m216[2];
                    slog::join_probe<3,2>(lambdaindex170, std::array<u64,3>{v_c16, v_c4, 0}, [&](const std::array<u64,3>& m217) {
                      u64 v_c17 = m217[2];
                      slog::join_probe<2,2>(refindex171, std::array<u64,2>{v_c17, v_c4}, [&](const std::array<u64,2>& m218) {
                        slog::join_probe<2,1>(refindex172, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m219) {
                          u64 v_c8 = m219[1];
                          slog::join_probe<3,2>(lambdaindex173, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m220) {
                            u64 v_c7 = m220[2];
                            ++_fires;
                            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c0, v_c9}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask174* _cont = new ReadTask174(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask174(db,b), false);
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0)) (once) (body) (head (mkstruct ref (1 0) __t69od13 __tconst5bLs14) (mkstruct ref (1 0) __t9TqL10 __tconst7VEl22) (mkstruct ref (1 0) __t6qhP6 __tconst6HRD7) (mkstruct ref (1 0) __t4qH72 __tconst7J8s3)) 0cfa-counting.slog:68 #f)
  class ReadTask221 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ref");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
  
    }
    ReadTask221(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask221(db,b), true);
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0)) (probe ref (1 0) 1 __tconst7J8s3 __t4qH72) (body (exists ref (1 0) 1 __tconst7VEl22) (exists ref (1 0) 1 __tconst5bLs14) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (join ref (1 0) 1 __tconst5bLs14 __t69od13)) (head (mkstruct lambda (1 2 0) __t9d0g15 __tconst5bLs14 __t69od13) (mkstruct lambda (1 2 0) __t92Rs8 __tconst6HRD7 __t6qhP6) (mkstruct lambda (1 2 0) __t42Ov4 __tconst7J8s3 __t4qH72)) 0cfa-counting.slog:68 #f)
  class ReadTask227 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex222;  slog::Index** refindex223;  slog::Index** refindex224;  slog::Index** refindex225;  slog::Index** refindex226;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord228({1, 0});
      slog::Relation* readrel229 = db->getRelation("ref");
      driver_index = readrel229->getIndex(ord228, true);
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("ref");
      refindex222 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("ref");
      refindex223 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 0});
      slog::Relation* readrel235 = db->getRelation("ref");
      refindex224 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 0});
      slog::Relation* readrel237 = db->getRelation("ref");
      refindex225 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 0});
      slog::Relation* readrel239 = db->getRelation("ref");
      refindex226 = readrel239->getIndex(ord238, false);
  
    }
    ReadTask227(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c1, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m240) {
        u64 v_c8 = m240[1];
        if (buckethash(v_c8) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex222, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex223, std::array<u64,2>{v_c4, 0})) return;
        slog::join_probe<2,1>(refindex224, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m241) {
          u64 v_c11 = m241[1];
          slog::join_probe<2,1>(refindex225, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m242) {
            u64 v_c10 = m242[1];
            slog::join_probe<2,1>(refindex226, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m243) {
              u64 v_c17 = m243[1];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c17}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c3, v_c11}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c8}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "delta:ref", _fires);
  
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
      s->addTask(phase_read, new ReadTask227(db,b), false);
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0)) (scan app __t8l1u11 __t9TqL10 __t92Rs8) (body (join ref (0 1) 2 __t9TqL10 __tconst7VEl22) (exists ref (1 0) 1 __tconst6HRD7) (exists ref (1 0) 1 __tconst7J8s3) (exists lambda (1 2 0) 1 __tconst7J8s3) (exists ref (1 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5bLs14) (exists app (1 2 0) 1 __t9TqL10) (join lambda (0 1 2) 2 __t92Rs8 __tconst6HRD7 __t6qhP6) (join ref (0 1) 2 __t6qhP6 __tconst6HRD7) (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4) (join ref (1 0) 1 __tconst5bLs14 __t69od13) (join lambda (1 2 0) 2 __tconst5bLs14 __t69od13 __t9d0g15) (join app (1 2 0) 2 __t9TqL10 __t9d0g15 __t0Sfq18)) (head (mkstruct lambda (1 2 0) __t3mzq20 __tconst5ulH19 __t0Sfq18)) 0cfa-counting.slog:68 #f)
  class ReadTask258 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex244;  slog::Index** refindex245;  slog::Index** refindex246;  slog::Index** lambdaindex247;  slog::Index** refindex248;  slog::Index** lambdaindex249;  slog::Index** appindex250;  slog::Index** lambdaindex251;  slog::Index** refindex252;  slog::Index** refindex253;  slog::Index** lambdaindex254;  slog::Index** refindex255;  slog::Index** lambdaindex256;  slog::Index** appindex257;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord259({0, 1});
      slog::Relation* readrel260 = db->getRelation("ref");
      refindex244 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 0});
      slog::Relation* readrel262 = db->getRelation("ref");
      refindex245 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 0});
      slog::Relation* readrel264 = db->getRelation("ref");
      refindex246 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({1, 2, 0});
      slog::Relation* readrel266 = db->getRelation("lambda");
      lambdaindex247 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 0});
      slog::Relation* readrel268 = db->getRelation("ref");
      refindex248 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({1, 2, 0});
      slog::Relation* readrel270 = db->getRelation("lambda");
      lambdaindex249 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({1, 2, 0});
      slog::Relation* readrel272 = db->getRelation("app");
      appindex250 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({0, 1, 2});
      slog::Relation* readrel274 = db->getRelation("lambda");
      lambdaindex251 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({0, 1});
      slog::Relation* readrel276 = db->getRelation("ref");
      refindex252 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 0});
      slog::Relation* readrel278 = db->getRelation("ref");
      refindex253 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({1, 2, 0});
      slog::Relation* readrel280 = db->getRelation("lambda");
      lambdaindex254 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 0});
      slog::Relation* readrel282 = db->getRelation("ref");
      refindex255 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 2, 0});
      slog::Relation* readrel284 = db->getRelation("lambda");
      lambdaindex256 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({1, 2, 0});
      slog::Relation* readrel286 = db->getRelation("app");
      appindex257 = readrel286->getIndex(ord285, false);
  
    }
    ReadTask258(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c13 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe<2,2>(refindex244, std::array<u64,2>{v_c10, v_c0}, [&](const std::array<u64,2>& m287) {
          if (!slog::exists_probe<2,1>(refindex245, std::array<u64,2>{v_c3, 0})) return;
          if (!slog::exists_probe<2,1>(refindex246, std::array<u64,2>{v_c1, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex247, std::array<u64,3>{v_c1, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex248, std::array<u64,2>{v_c4, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex249, std::array<u64,3>{v_c4, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex250, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe<3,2>(lambdaindex251, std::array<u64,3>{v_c12, v_c3, 0}, [&](const std::array<u64,3>& m288) {
            u64 v_c11 = m288[2];
            slog::join_probe<2,2>(refindex252, std::array<u64,2>{v_c11, v_c3}, [&](const std::array<u64,2>& m289) {
              slog::join_probe<2,1>(refindex253, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m290) {
                u64 v_c8 = m290[1];
                slog::join_probe<3,2>(lambdaindex254, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m291) {
                  u64 v_c7 = m291[2];
                  slog::join_probe<2,1>(refindex255, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m292) {
                    u64 v_c17 = m292[1];
                    slog::join_probe<3,2>(lambdaindex256, std::array<u64,3>{v_c4, v_c17, 0}, [&](const std::array<u64,3>& m293) {
                      u64 v_c16 = m293[2];
                      slog::join_probe<3,2>(appindex257, std::array<u64,3>{v_c10, v_c16, 0}, [&](const std::array<u64,3>& m294) {
                        u64 v_c15 = m294[2];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c15}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask258* _cont = new ReadTask258(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask258(db,b), false);
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229)) (probe lambda (1 0 2) 1 __tconst7VEl22 __t0x9n23 __t7ta721) (body (exists lambda (1 2 0) 1 __tconst7J8s3) (exists ref (1 0) 1 __tconst7VEl22) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst5ulH19) (exists lambda (1 2 0) 1 __tconst5bLs14) (exists ref (1 0) 1 __tconst5bLs14) (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (exists app (1 2 0) 1 __t9TqL10) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join app (1 2 0) 2 __t9TqL10 __t92Rs8 __t8l1u11) (join app (2 0 1) 2 __t8l1u11 __t7ta721 __t3mzq20) (join lambda (0 1 2) 2 __t3mzq20 __tconst5ulH19 __t0Sfq18) (join app (0 1 2) 2 __t0Sfq18 __t9TqL10 __t9d0g15) (join lambda (0 1 2) 2 __t9d0g15 __tconst5bLs14 __t69od13) (join ref (0 1) 2 __t69od13 __tconst5bLs14)) (head (mkstruct app (1 2 0) __t5tyC24 __t0x9n23 __t42Ov4)) 0cfa-counting.slog:68 #f)
  class ReadTask314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex295;  slog::Index** refindex296;  slog::Index** refindex297;  slog::Index** lambdaindex298;  slog::Index** lambdaindex299;  slog::Index** lambdaindex300;  slog::Index** refindex301;  slog::Index** refindex302;  slog::Index** lambdaindex303;  slog::Index** refindex304;  slog::Index** appindex305;  slog::Index** refindex306;  slog::Index** lambdaindex307;  slog::Index** appindex308;  slog::Index** appindex309;  slog::Index** lambdaindex310;  slog::Index** appindex311;  slog::Index** lambdaindex312;  slog::Index** refindex313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord315({1, 0, 2});
      slog::Relation* readrel316 = db->getRelation("lambda");
      driver_index = readrel316->getIndex(ord315, true);
      std::vector<u16> ord317({1, 2, 0});
      slog::Relation* readrel318 = db->getRelation("lambda");
      lambdaindex295 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 0});
      slog::Relation* readrel320 = db->getRelation("ref");
      refindex296 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({1, 0});
      slog::Relation* readrel322 = db->getRelation("ref");
      refindex297 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({1, 2, 0});
      slog::Relation* readrel324 = db->getRelation("lambda");
      lambdaindex298 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 0});
      slog::Relation* readrel326 = db->getRelation("lambda");
      lambdaindex299 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 2, 0});
      slog::Relation* readrel328 = db->getRelation("lambda");
      lambdaindex300 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 0});
      slog::Relation* readrel330 = db->getRelation("ref");
      refindex301 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 0});
      slog::Relation* readrel332 = db->getRelation("ref");
      refindex302 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 2, 0});
      slog::Relation* readrel334 = db->getRelation("lambda");
      lambdaindex303 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 0});
      slog::Relation* readrel336 = db->getRelation("ref");
      refindex304 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({1, 2, 0});
      slog::Relation* readrel338 = db->getRelation("app");
      appindex305 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 0});
      slog::Relation* readrel340 = db->getRelation("ref");
      refindex306 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 2, 0});
      slog::Relation* readrel342 = db->getRelation("lambda");
      lambdaindex307 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 0});
      slog::Relation* readrel344 = db->getRelation("app");
      appindex308 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({2, 0, 1});
      slog::Relation* readrel346 = db->getRelation("app");
      appindex309 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({0, 1, 2});
      slog::Relation* readrel348 = db->getRelation("lambda");
      lambdaindex310 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({0, 1, 2});
      slog::Relation* readrel350 = db->getRelation("app");
      appindex311 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({0, 1, 2});
      slog::Relation* readrel352 = db->getRelation("lambda");
      lambdaindex312 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({0, 1});
      slog::Relation* readrel354 = db->getRelation("ref");
      refindex313 = readrel354->getIndex(ord353, false);
  
    }
    ReadTask314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c0, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m355) {
        u64 v_c6 = m355[1];
        u64 v_c9 = m355[2];
        if (buckethash(v_c6) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex295, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex296, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex297, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex298, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex299, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex300, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex301, std::array<u64,2>{v_c4, 0})) return;
        slog::join_probe<2,1>(refindex302, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m356) {
          u64 v_c8 = m356[1];
          slog::join_probe<3,2>(lambdaindex303, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m357) {
            u64 v_c7 = m357[2];
            slog::join_probe<2,1>(refindex304, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m358) {
              u64 v_c10 = m358[1];
              if (!slog::exists_probe<3,1>(appindex305, std::array<u64,3>{v_c10, 0, 0})) return;
              slog::join_probe<2,1>(refindex306, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m359) {
                u64 v_c11 = m359[1];
                slog::join_probe<3,2>(lambdaindex307, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m360) {
                  u64 v_c12 = m360[2];
                  slog::join_probe<3,2>(appindex308, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m361) {
                    u64 v_c13 = m361[2];
                    slog::join_probe<3,2>(appindex309, std::array<u64,3>{v_c13, v_c9, 0}, [&](const std::array<u64,3>& m362) {
                      u64 v_c14 = m362[2];
                      slog::join_probe<3,2>(lambdaindex310, std::array<u64,3>{v_c14, v_c2, 0}, [&](const std::array<u64,3>& m363) {
                        u64 v_c15 = m363[2];
                        slog::join_probe<3,2>(appindex311, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m364) {
                          u64 v_c16 = m364[2];
                          slog::join_probe<3,2>(lambdaindex312, std::array<u64,3>{v_c16, v_c4, 0}, [&](const std::array<u64,3>& m365) {
                            u64 v_c17 = m365[2];
                            slog::join_probe<2,2>(refindex313, std::array<u64,2>{v_c17, v_c4}, [&](const std::array<u64,2>& m366) {
                              ++_fires;
                              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c6, v_c7}, std::array<u16,3>{1, 2, 0});
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask314* _cont = new ReadTask314(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask314(db,b), false);
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0)) (seeded) (body (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (exists ref (1 0) 1 __tconst7VEl22) (exists ref (1 0) 1 __tconst5bLs14) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (join ref (1 0) 1 __tconst5bLs14 __t69od13)) (head (mkstruct lambda (1 2 0) __t9d0g15 __tconst5bLs14 __t69od13) (mkstruct lambda (1 2 0) __t92Rs8 __tconst6HRD7 __t6qhP6) (mkstruct lambda (1 2 0) __t42Ov4 __tconst7J8s3 __t4qH72)) 0cfa-counting.slog:68 #f)
  class ReadTask373 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex367;  slog::Index** refindex368;  slog::Index** refindex369;  slog::Index** refindex370;  slog::Index** refindex371;  slog::Index** refindex372;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord374({1, 2, 0});
      slog::Relation* readrel375 = db->getRelation("lambda");
      head_index[0] = readrel375->getIndex(ord374, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord376({1, 2, 0});
      slog::Relation* readrel377 = db->getRelation("lambda");
      head_index[1] = readrel377->getIndex(ord376, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord378({1, 2, 0});
      slog::Relation* readrel379 = db->getRelation("lambda");
      head_index[2] = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 0});
      slog::Relation* readrel381 = db->getRelation("ref");
      refindex367 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 0});
      slog::Relation* readrel383 = db->getRelation("ref");
      refindex368 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 0});
      slog::Relation* readrel385 = db->getRelation("ref");
      refindex369 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 0});
      slog::Relation* readrel387 = db->getRelation("ref");
      refindex370 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 0});
      slog::Relation* readrel389 = db->getRelation("ref");
      refindex371 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 0});
      slog::Relation* readrel391 = db->getRelation("ref");
      refindex372 = readrel391->getIndex(ord390, false);
  
    }
    ReadTask373(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex367, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m392) {
        u64 v_c8 = m392[1];
        if (!slog::exists_probe<2,1>(refindex368, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex369, std::array<u64,2>{v_c4, 0})) return;
        slog::join_probe<2,1>(refindex370, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m393) {
          u64 v_c11 = m393[1];
          slog::join_probe<2,1>(refindex371, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m394) {
            u64 v_c10 = m394[1];
            slog::join_probe<2,1>(refindex372, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m395) {
              u64 v_c17 = m395[1];
              ++_fires;
              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c17}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c3, v_c11}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c1, v_c8}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask373(db,b));
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0)) (probe lambda (1 0 2) 1 __tconst7J8s3 __t42Ov4 __t4qH72) (body (join ref (0 1) 2 __t4qH72 __tconst7J8s3) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists ref (1 0) 1 __tconst7VEl22) (exists ref (1 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5bLs14) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (join ref (1 0) 1 __tconst5bLs14 __t69od13) (join lambda (1 2 0) 2 __tconst5bLs14 __t69od13 __t9d0g15)) (head (mkstruct app (1 2 0) __t0Sfq18 __t9TqL10 __t9d0g15) (mkstruct app (1 2 0) __t8l1u11 __t9TqL10 __t92Rs8)) 0cfa-counting.slog:68 #f)
  class ReadTask406 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex396;  slog::Index** lambdaindex397;  slog::Index** refindex398;  slog::Index** refindex399;  slog::Index** lambdaindex400;  slog::Index** refindex401;  slog::Index** lambdaindex402;  slog::Index** refindex403;  slog::Index** refindex404;  slog::Index** lambdaindex405;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord407({1, 0, 2});
      slog::Relation* readrel408 = db->getRelation("lambda");
      driver_index = readrel408->getIndex(ord407, true);
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("ref");
      refindex396 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 2, 0});
      slog::Relation* readrel412 = db->getRelation("lambda");
      lambdaindex397 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({1, 0});
      slog::Relation* readrel414 = db->getRelation("ref");
      refindex398 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({1, 0});
      slog::Relation* readrel416 = db->getRelation("ref");
      refindex399 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 2, 0});
      slog::Relation* readrel418 = db->getRelation("lambda");
      lambdaindex400 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({1, 0});
      slog::Relation* readrel420 = db->getRelation("ref");
      refindex401 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({1, 2, 0});
      slog::Relation* readrel422 = db->getRelation("lambda");
      lambdaindex402 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({1, 0});
      slog::Relation* readrel424 = db->getRelation("ref");
      refindex403 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({1, 0});
      slog::Relation* readrel426 = db->getRelation("ref");
      refindex404 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({1, 2, 0});
      slog::Relation* readrel428 = db->getRelation("lambda");
      lambdaindex405 = readrel428->getIndex(ord427, false);
  
    }
    ReadTask406(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c1, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m429) {
        u64 v_c7 = m429[1];
        u64 v_c8 = m429[2];
        if (buckethash(v_c7) != bucket) return;
        slog::join_probe<2,2>(refindex396, std::array<u64,2>{v_c8, v_c1}, [&](const std::array<u64,2>& m430) {
          if (!slog::exists_probe<3,1>(lambdaindex397, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex398, std::array<u64,2>{v_c0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex399, std::array<u64,2>{v_c4, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex400, std::array<u64,3>{v_c4, 0, 0})) return;
          slog::join_probe<2,1>(refindex401, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m431) {
            u64 v_c11 = m431[1];
            slog::join_probe<3,2>(lambdaindex402, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m432) {
              u64 v_c12 = m432[2];
              slog::join_probe<2,1>(refindex403, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m433) {
                u64 v_c10 = m433[1];
                slog::join_probe<2,1>(refindex404, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m434) {
                  u64 v_c17 = m434[1];
                  slog::join_probe<3,2>(lambdaindex405, std::array<u64,3>{v_c4, v_c17, 0}, [&](const std::array<u64,3>& m435) {
                    u64 v_c16 = m435[2];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c16}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c12}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask406* _cont = new ReadTask406(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask406(db,b), false);
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0)) (seeded) (body (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (exists lambda (1 2 0) 1 __tconst7J8s3) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists app (1 2 0) 1 __t9TqL10) (exists ref (1 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5bLs14) (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join app (1 2 0) 2 __t9TqL10 __t92Rs8 __t8l1u11) (join ref (1 0) 1 __tconst5bLs14 __t69od13) (join lambda (1 2 0) 2 __tconst5bLs14 __t69od13 __t9d0g15) (join app (1 2 0) 2 __t9TqL10 __t9d0g15 __t0Sfq18)) (head (mkstruct lambda (1 2 0) __t3mzq20 __tconst5ulH19 __t0Sfq18)) 0cfa-counting.slog:68 #f)
  class ReadTask451 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex436;  slog::Index** lambdaindex437;  slog::Index** refindex438;  slog::Index** lambdaindex439;  slog::Index** appindex440;  slog::Index** refindex441;  slog::Index** lambdaindex442;  slog::Index** refindex443;  slog::Index** lambdaindex444;  slog::Index** refindex445;  slog::Index** lambdaindex446;  slog::Index** appindex447;  slog::Index** refindex448;  slog::Index** lambdaindex449;  slog::Index** appindex450;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord452({1, 2, 0});
      slog::Relation* readrel453 = db->getRelation("lambda");
      head_index[0] = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 0});
      slog::Relation* readrel455 = db->getRelation("ref");
      refindex436 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 2, 0});
      slog::Relation* readrel457 = db->getRelation("lambda");
      lambdaindex437 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 0});
      slog::Relation* readrel459 = db->getRelation("ref");
      refindex438 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({1, 2, 0});
      slog::Relation* readrel461 = db->getRelation("lambda");
      lambdaindex439 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 2, 0});
      slog::Relation* readrel463 = db->getRelation("app");
      appindex440 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 0});
      slog::Relation* readrel465 = db->getRelation("ref");
      refindex441 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("lambda");
      lambdaindex442 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 0});
      slog::Relation* readrel469 = db->getRelation("ref");
      refindex443 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 2, 0});
      slog::Relation* readrel471 = db->getRelation("lambda");
      lambdaindex444 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0});
      slog::Relation* readrel473 = db->getRelation("ref");
      refindex445 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("lambda");
      lambdaindex446 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("app");
      appindex447 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 0});
      slog::Relation* readrel479 = db->getRelation("ref");
      refindex448 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 2, 0});
      slog::Relation* readrel481 = db->getRelation("lambda");
      lambdaindex449 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 0});
      slog::Relation* readrel483 = db->getRelation("app");
      appindex450 = readrel483->getIndex(ord482, false);
  
    }
    ReadTask451(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex436, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m484) {
        u64 v_c10 = m484[1];
        if (!slog::exists_probe<3,1>(lambdaindex437, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex438, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex439, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex440, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex441, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex442, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(refindex443, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m485) {
          u64 v_c8 = m485[1];
          slog::join_probe<3,2>(lambdaindex444, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m486) {
            u64 v_c7 = m486[2];
            slog::join_probe<2,1>(refindex445, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m487) {
              u64 v_c11 = m487[1];
              slog::join_probe<3,2>(lambdaindex446, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m488) {
                u64 v_c12 = m488[2];
                slog::join_probe<3,2>(appindex447, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m489) {
                  u64 v_c13 = m489[2];
                  slog::join_probe<2,1>(refindex448, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m490) {
                    u64 v_c17 = m490[1];
                    slog::join_probe<3,2>(lambdaindex449, std::array<u64,3>{v_c4, v_c17, 0}, [&](const std::array<u64,3>& m491) {
                      u64 v_c16 = m491[2];
                      slog::join_probe<3,2>(appindex450, std::array<u64,3>{v_c10, v_c16, 0}, [&](const std::array<u64,3>& m492) {
                        u64 v_c15 = m492[2];
                        ++_fires;
                        slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c2, v_c15}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask451(db,b));
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0)) (seeded) (body (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists ref (1 0) 1 __tconst7VEl22) (exists ref (1 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5bLs14) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (join ref (1 0) 1 __tconst5bLs14 __t69od13) (join lambda (1 2 0) 2 __tconst5bLs14 __t69od13 __t9d0g15)) (head (mkstruct app (1 2 0) __t0Sfq18 __t9TqL10 __t9d0g15) (mkstruct app (1 2 0) __t8l1u11 __t9TqL10 __t92Rs8)) 0cfa-counting.slog:68 #f)
  class ReadTask505 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** refindex493;  slog::Index** refindex494;  slog::Index** lambdaindex495;  slog::Index** refindex496;  slog::Index** refindex497;  slog::Index** lambdaindex498;  slog::Index** lambdaindex499;  slog::Index** refindex500;  slog::Index** lambdaindex501;  slog::Index** refindex502;  slog::Index** refindex503;  slog::Index** lambdaindex504;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord506({1, 2, 0});
      slog::Relation* readrel507 = db->getRelation("app");
      head_index[0] = readrel507->getIndex(ord506, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("app");
      head_index[1] = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 0});
      slog::Relation* readrel511 = db->getRelation("ref");
      refindex493 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({1, 0});
      slog::Relation* readrel513 = db->getRelation("ref");
      refindex494 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({1, 2, 0});
      slog::Relation* readrel515 = db->getRelation("lambda");
      lambdaindex495 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 0});
      slog::Relation* readrel517 = db->getRelation("ref");
      refindex496 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 0});
      slog::Relation* readrel519 = db->getRelation("ref");
      refindex497 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({1, 2, 0});
      slog::Relation* readrel521 = db->getRelation("lambda");
      lambdaindex498 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({1, 2, 0});
      slog::Relation* readrel523 = db->getRelation("lambda");
      lambdaindex499 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({1, 0});
      slog::Relation* readrel525 = db->getRelation("ref");
      refindex500 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({1, 2, 0});
      slog::Relation* readrel527 = db->getRelation("lambda");
      lambdaindex501 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({1, 0});
      slog::Relation* readrel529 = db->getRelation("ref");
      refindex502 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 0});
      slog::Relation* readrel531 = db->getRelation("ref");
      refindex503 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 2, 0});
      slog::Relation* readrel533 = db->getRelation("lambda");
      lambdaindex504 = readrel533->getIndex(ord532, false);
  
    }
    ReadTask505(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex493, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m534) {
        u64 v_c8 = m534[1];
        if (!slog::exists_probe<2,1>(refindex494, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex495, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex496, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex497, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex498, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex499, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m535) {
          u64 v_c7 = m535[2];
          slog::join_probe<2,1>(refindex500, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m536) {
            u64 v_c11 = m536[1];
            slog::join_probe<3,2>(lambdaindex501, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m537) {
              u64 v_c12 = m537[2];
              slog::join_probe<2,1>(refindex502, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m538) {
                u64 v_c10 = m538[1];
                slog::join_probe<2,1>(refindex503, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m539) {
                  u64 v_c17 = m539[1];
                  slog::join_probe<3,2>(lambdaindex504, std::array<u64,3>{v_c4, v_c17, 0}, [&](const std::array<u64,3>& m540) {
                    u64 v_c16 = m540[2];
                    ++_fires;
                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c16}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c10, v_c12}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask505(db,b));
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229)) (seeded) (body (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (exists lambda (1 2 0) 1 __tconst7J8s3) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists app (1 2 0) 1 __t9TqL10) (exists ref (1 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5ulH19) (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join app (1 2 0) 2 __t9TqL10 __t92Rs8 __t8l1u11) (exists app (2 0 1) 1 __t8l1u11) (join ref (1 0) 1 __tconst5bLs14 __t69od13) (join lambda (1 2 0) 2 __tconst5bLs14 __t69od13 __t9d0g15) (join app (1 2 0) 2 __t9TqL10 __t9d0g15 __t0Sfq18) (join lambda (1 2 0) 2 __tconst5ulH19 __t0Sfq18 __t3mzq20) (join app (1 2 0) 2 __t3mzq20 __t8l1u11 __t7ta721)) (head (mkstruct lambda (1 2 0) __t0x9n23 __tconst7VEl22 __t7ta721)) 0cfa-counting.slog:68 #f)
  class ReadTask560 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex541;  slog::Index** lambdaindex542;  slog::Index** refindex543;  slog::Index** lambdaindex544;  slog::Index** appindex545;  slog::Index** refindex546;  slog::Index** lambdaindex547;  slog::Index** lambdaindex548;  slog::Index** refindex549;  slog::Index** lambdaindex550;  slog::Index** refindex551;  slog::Index** lambdaindex552;  slog::Index** appindex553;  slog::Index** appindex554;  slog::Index** refindex555;  slog::Index** lambdaindex556;  slog::Index** appindex557;  slog::Index** lambdaindex558;  slog::Index** appindex559;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord561({1, 2, 0});
      slog::Relation* readrel562 = db->getRelation("lambda");
      head_index[0] = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 0});
      slog::Relation* readrel564 = db->getRelation("ref");
      refindex541 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({1, 2, 0});
      slog::Relation* readrel566 = db->getRelation("lambda");
      lambdaindex542 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 0});
      slog::Relation* readrel568 = db->getRelation("ref");
      refindex543 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({1, 2, 0});
      slog::Relation* readrel570 = db->getRelation("lambda");
      lambdaindex544 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 2, 0});
      slog::Relation* readrel572 = db->getRelation("app");
      appindex545 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 0});
      slog::Relation* readrel574 = db->getRelation("ref");
      refindex546 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 0});
      slog::Relation* readrel576 = db->getRelation("lambda");
      lambdaindex547 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 2, 0});
      slog::Relation* readrel578 = db->getRelation("lambda");
      lambdaindex548 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 0});
      slog::Relation* readrel580 = db->getRelation("ref");
      refindex549 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 2, 0});
      slog::Relation* readrel582 = db->getRelation("lambda");
      lambdaindex550 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 0});
      slog::Relation* readrel584 = db->getRelation("ref");
      refindex551 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({1, 2, 0});
      slog::Relation* readrel586 = db->getRelation("lambda");
      lambdaindex552 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({1, 2, 0});
      slog::Relation* readrel588 = db->getRelation("app");
      appindex553 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({2, 0, 1});
      slog::Relation* readrel590 = db->getRelation("app");
      appindex554 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 0});
      slog::Relation* readrel592 = db->getRelation("ref");
      refindex555 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({1, 2, 0});
      slog::Relation* readrel594 = db->getRelation("lambda");
      lambdaindex556 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({1, 2, 0});
      slog::Relation* readrel596 = db->getRelation("app");
      appindex557 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 2, 0});
      slog::Relation* readrel598 = db->getRelation("lambda");
      lambdaindex558 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({1, 2, 0});
      slog::Relation* readrel600 = db->getRelation("app");
      appindex559 = readrel600->getIndex(ord599, false);
  
    }
    ReadTask560(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex541, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m601) {
        u64 v_c10 = m601[1];
        if (!slog::exists_probe<3,1>(lambdaindex542, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex543, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex544, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex545, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex546, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex547, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex548, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(refindex549, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m602) {
          u64 v_c8 = m602[1];
          slog::join_probe<3,2>(lambdaindex550, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m603) {
            u64 v_c7 = m603[2];
            slog::join_probe<2,1>(refindex551, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m604) {
              u64 v_c11 = m604[1];
              slog::join_probe<3,2>(lambdaindex552, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m605) {
                u64 v_c12 = m605[2];
                slog::join_probe<3,2>(appindex553, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m606) {
                  u64 v_c13 = m606[2];
                  if (!slog::exists_probe<3,1>(appindex554, std::array<u64,3>{v_c13, 0, 0})) return;
                  slog::join_probe<2,1>(refindex555, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m607) {
                    u64 v_c17 = m607[1];
                    slog::join_probe<3,2>(lambdaindex556, std::array<u64,3>{v_c4, v_c17, 0}, [&](const std::array<u64,3>& m608) {
                      u64 v_c16 = m608[2];
                      slog::join_probe<3,2>(appindex557, std::array<u64,3>{v_c10, v_c16, 0}, [&](const std::array<u64,3>& m609) {
                        u64 v_c15 = m609[2];
                        slog::join_probe<3,2>(lambdaindex558, std::array<u64,3>{v_c2, v_c15, 0}, [&](const std::array<u64,3>& m610) {
                          u64 v_c14 = m610[2];
                          slog::join_probe<3,2>(appindex559, std::array<u64,3>{v_c14, v_c13, 0}, [&](const std::array<u64,3>& m611) {
                            u64 v_c9 = m611[2];
                            ++_fires;
                            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c9}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask560(db,b));
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst6HRD7 const7265b875feb0d1730ead43d3) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229)) (seeded) (body (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (exists ref (1 0) 1 __tconst7VEl22) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists ref (1 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5ulH19) (exists lambda (1 2 0) 1 __tconst7VEl22) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4) (exists app (2 0 1) 1 __t42Ov4) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (exists app (1 2 0) 1 __t9TqL10) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join app (1 2 0) 2 __t9TqL10 __t92Rs8 __t8l1u11) (exists app (2 0 1) 1 __t8l1u11) (join ref (1 0) 1 __tconst5bLs14 __t69od13) (join lambda (1 2 0) 2 __tconst5bLs14 __t69od13 __t9d0g15) (join app (1 2 0) 2 __t9TqL10 __t9d0g15 __t0Sfq18) (join lambda (1 2 0) 2 __tconst5ulH19 __t0Sfq18 __t3mzq20) (join app (1 2 0) 2 __t3mzq20 __t8l1u11 __t7ta721) (join lambda (1 2 0) 2 __tconst7VEl22 __t7ta721 __t0x9n23) (join app (1 2 0) 2 __t0x9n23 __t42Ov4 __t5tyC24)) (head (emit program (0) __t5tyC24)) 0cfa-counting.slog:68 #f)
  class ReadTask635 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex612;  slog::Index** refindex613;  slog::Index** refindex614;  slog::Index** lambdaindex615;  slog::Index** refindex616;  slog::Index** lambdaindex617;  slog::Index** lambdaindex618;  slog::Index** lambdaindex619;  slog::Index** lambdaindex620;  slog::Index** appindex621;  slog::Index** refindex622;  slog::Index** appindex623;  slog::Index** refindex624;  slog::Index** lambdaindex625;  slog::Index** appindex626;  slog::Index** appindex627;  slog::Index** refindex628;  slog::Index** lambdaindex629;  slog::Index** appindex630;  slog::Index** lambdaindex631;  slog::Index** appindex632;  slog::Index** lambdaindex633;  slog::Index** appindex634;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord636({0});
      slog::Relation* readrel637 = db->getRelation("program");
      head_index[0] = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 0});
      slog::Relation* readrel639 = db->getRelation("ref");
      refindex612 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 0});
      slog::Relation* readrel641 = db->getRelation("ref");
      refindex613 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 0});
      slog::Relation* readrel643 = db->getRelation("ref");
      refindex614 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 2, 0});
      slog::Relation* readrel645 = db->getRelation("lambda");
      lambdaindex615 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 0});
      slog::Relation* readrel647 = db->getRelation("ref");
      refindex616 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 2, 0});
      slog::Relation* readrel649 = db->getRelation("lambda");
      lambdaindex617 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({1, 2, 0});
      slog::Relation* readrel651 = db->getRelation("lambda");
      lambdaindex618 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({1, 2, 0});
      slog::Relation* readrel653 = db->getRelation("lambda");
      lambdaindex619 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 2, 0});
      slog::Relation* readrel655 = db->getRelation("lambda");
      lambdaindex620 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({2, 0, 1});
      slog::Relation* readrel657 = db->getRelation("app");
      appindex621 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 0});
      slog::Relation* readrel659 = db->getRelation("ref");
      refindex622 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 2, 0});
      slog::Relation* readrel661 = db->getRelation("app");
      appindex623 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 0});
      slog::Relation* readrel663 = db->getRelation("ref");
      refindex624 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 2, 0});
      slog::Relation* readrel665 = db->getRelation("lambda");
      lambdaindex625 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 0});
      slog::Relation* readrel667 = db->getRelation("app");
      appindex626 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({2, 0, 1});
      slog::Relation* readrel669 = db->getRelation("app");
      appindex627 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({1, 0});
      slog::Relation* readrel671 = db->getRelation("ref");
      refindex628 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 2, 0});
      slog::Relation* readrel673 = db->getRelation("lambda");
      lambdaindex629 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 2, 0});
      slog::Relation* readrel675 = db->getRelation("app");
      appindex630 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 2, 0});
      slog::Relation* readrel677 = db->getRelation("lambda");
      lambdaindex631 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({1, 2, 0});
      slog::Relation* readrel679 = db->getRelation("app");
      appindex632 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 2, 0});
      slog::Relation* readrel681 = db->getRelation("lambda");
      lambdaindex633 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 2, 0});
      slog::Relation* readrel683 = db->getRelation("app");
      appindex634 = readrel683->getIndex(ord682, false);
  
    }
    ReadTask635(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex612, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m684) {
        u64 v_c8 = m684[1];
        if (!slog::exists_probe<2,1>(refindex613, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex614, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex615, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex616, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex617, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex618, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex619, std::array<u64,3>{v_c0, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex620, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m685) {
          u64 v_c7 = m685[2];
          if (!slog::exists_probe<3,1>(appindex621, std::array<u64,3>{v_c7, 0, 0})) return;
          slog::join_probe<2,1>(refindex622, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m686) {
            u64 v_c10 = m686[1];
            if (!slog::exists_probe<3,1>(appindex623, std::array<u64,3>{v_c10, 0, 0})) return;
            slog::join_probe<2,1>(refindex624, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m687) {
              u64 v_c11 = m687[1];
              slog::join_probe<3,2>(lambdaindex625, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m688) {
                u64 v_c12 = m688[2];
                slog::join_probe<3,2>(appindex626, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m689) {
                  u64 v_c13 = m689[2];
                  if (!slog::exists_probe<3,1>(appindex627, std::array<u64,3>{v_c13, 0, 0})) return;
                  slog::join_probe<2,1>(refindex628, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m690) {
                    u64 v_c17 = m690[1];
                    slog::join_probe<3,2>(lambdaindex629, std::array<u64,3>{v_c4, v_c17, 0}, [&](const std::array<u64,3>& m691) {
                      u64 v_c16 = m691[2];
                      slog::join_probe<3,2>(appindex630, std::array<u64,3>{v_c10, v_c16, 0}, [&](const std::array<u64,3>& m692) {
                        u64 v_c15 = m692[2];
                        slog::join_probe<3,2>(lambdaindex631, std::array<u64,3>{v_c2, v_c15, 0}, [&](const std::array<u64,3>& m693) {
                          u64 v_c14 = m693[2];
                          slog::join_probe<3,2>(appindex632, std::array<u64,3>{v_c14, v_c13, 0}, [&](const std::array<u64,3>& m694) {
                            u64 v_c9 = m694[2];
                            slog::join_probe<3,2>(lambdaindex633, std::array<u64,3>{v_c0, v_c9, 0}, [&](const std::array<u64,3>& m695) {
                              u64 v_c6 = m695[2];
                              slog::join_probe<3,2>(appindex634, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m696) {
                                u64 v_c5 = m696[2];
                                ++_fires;
                                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
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
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask635(db,b));
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229) (let __tconst6HRD7 const7265b875feb0d1730ead43d3)) (probe lambda (1 0 2) 1 __tconst5ulH19 __t3mzq20 __t0Sfq18) (body (exists lambda (1 2 0) 1 __tconst5bLs14) (exists ref (1 0) 1 __tconst5bLs14) (exists ref (1 0) 1 __tconst7J8s3) (exists lambda (1 2 0) 1 __tconst7J8s3) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst6HRD7) (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (exists app (1 2 0) 1 __t9TqL10) (join app (0 1 2) 2 __t0Sfq18 __t9TqL10 __t9d0g15) (join lambda (0 1 2) 2 __t9d0g15 __tconst5bLs14 __t69od13) (join ref (0 1) 2 __t69od13 __tconst5bLs14) (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join app (1 2 0) 2 __t9TqL10 __t92Rs8 __t8l1u11)) (head (mkstruct app (1 2 0) __t7ta721 __t3mzq20 __t8l1u11)) 0cfa-counting.slog:68 #f)
  class ReadTask713 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex697;  slog::Index** refindex698;  slog::Index** refindex699;  slog::Index** lambdaindex700;  slog::Index** refindex701;  slog::Index** lambdaindex702;  slog::Index** refindex703;  slog::Index** appindex704;  slog::Index** appindex705;  slog::Index** lambdaindex706;  slog::Index** refindex707;  slog::Index** refindex708;  slog::Index** lambdaindex709;  slog::Index** refindex710;  slog::Index** lambdaindex711;  slog::Index** appindex712;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord714({1, 0, 2});
      slog::Relation* readrel715 = db->getRelation("lambda");
      driver_index = readrel715->getIndex(ord714, true);
      std::vector<u16> ord716({1, 2, 0});
      slog::Relation* readrel717 = db->getRelation("lambda");
      lambdaindex697 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({1, 0});
      slog::Relation* readrel719 = db->getRelation("ref");
      refindex698 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({1, 0});
      slog::Relation* readrel721 = db->getRelation("ref");
      refindex699 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({1, 2, 0});
      slog::Relation* readrel723 = db->getRelation("lambda");
      lambdaindex700 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 0});
      slog::Relation* readrel725 = db->getRelation("ref");
      refindex701 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({1, 2, 0});
      slog::Relation* readrel727 = db->getRelation("lambda");
      lambdaindex702 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({1, 0});
      slog::Relation* readrel729 = db->getRelation("ref");
      refindex703 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({1, 2, 0});
      slog::Relation* readrel731 = db->getRelation("app");
      appindex704 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({0, 1, 2});
      slog::Relation* readrel733 = db->getRelation("app");
      appindex705 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({0, 1, 2});
      slog::Relation* readrel735 = db->getRelation("lambda");
      lambdaindex706 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({0, 1});
      slog::Relation* readrel737 = db->getRelation("ref");
      refindex707 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({1, 0});
      slog::Relation* readrel739 = db->getRelation("ref");
      refindex708 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({1, 2, 0});
      slog::Relation* readrel741 = db->getRelation("lambda");
      lambdaindex709 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 0});
      slog::Relation* readrel743 = db->getRelation("ref");
      refindex710 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({1, 2, 0});
      slog::Relation* readrel745 = db->getRelation("lambda");
      lambdaindex711 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({1, 2, 0});
      slog::Relation* readrel747 = db->getRelation("app");
      appindex712 = readrel747->getIndex(ord746, false);
  
    }
    ReadTask713(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c2, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m748) {
        u64 v_c14 = m748[1];
        u64 v_c15 = m748[2];
        if (buckethash(v_c14) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex697, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex698, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(refindex699, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex700, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex701, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex702, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(refindex703, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m749) {
          u64 v_c10 = m749[1];
          if (!slog::exists_probe<3,1>(appindex704, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe<3,2>(appindex705, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m750) {
            u64 v_c16 = m750[2];
            slog::join_probe<3,2>(lambdaindex706, std::array<u64,3>{v_c16, v_c4, 0}, [&](const std::array<u64,3>& m751) {
              u64 v_c17 = m751[2];
              slog::join_probe<2,2>(refindex707, std::array<u64,2>{v_c17, v_c4}, [&](const std::array<u64,2>& m752) {
                slog::join_probe<2,1>(refindex708, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m753) {
                  u64 v_c8 = m753[1];
                  slog::join_probe<3,2>(lambdaindex709, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m754) {
                    u64 v_c7 = m754[2];
                    slog::join_probe<2,1>(refindex710, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m755) {
                      u64 v_c11 = m755[1];
                      slog::join_probe<3,2>(lambdaindex711, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m756) {
                        u64 v_c12 = m756[2];
                        slog::join_probe<3,2>(appindex712, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m757) {
                          u64 v_c13 = m757[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c14, v_c13}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask713* _cont = new ReadTask713(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask713(db,b), false);
  // (crule (pre (let __tconst7VEl22 const2d53b3c21fa5cc786ac46d72) (let __tconst5ulH19 constebbe2dfbb019b8256cb73d30) (let __tconst7J8s3 const20c400557af0eddc0be4d9e0) (let __tconst5bLs14 constd1a4dc8b61ef51fa5f72b229) (let __tconst6HRD7 const7265b875feb0d1730ead43d3)) (seeded) (body (join ref (1 0) 1 __tconst7VEl22 __t9TqL10) (exists lambda (1 2 0) 1 __tconst7J8s3) (exists ref (1 0) 1 __tconst6HRD7) (exists lambda (1 2 0) 1 __tconst6HRD7) (exists app (1 2 0) 1 __t9TqL10) (exists ref (1 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5bLs14) (exists lambda (1 2 0) 1 __tconst5ulH19) (join ref (1 0) 1 __tconst7J8s3 __t4qH72) (join lambda (1 2 0) 2 __tconst7J8s3 __t4qH72 __t42Ov4) (join ref (1 0) 1 __tconst6HRD7 __t6qhP6) (join lambda (1 2 0) 2 __tconst6HRD7 __t6qhP6 __t92Rs8) (join app (1 2 0) 2 __t9TqL10 __t92Rs8 __t8l1u11) (join ref (1 0) 1 __tconst5bLs14 __t69od13) (join lambda (1 2 0) 2 __tconst5bLs14 __t69od13 __t9d0g15) (join app (1 2 0) 2 __t9TqL10 __t9d0g15 __t0Sfq18) (join lambda (1 2 0) 2 __tconst5ulH19 __t0Sfq18 __t3mzq20)) (head (mkstruct app (1 2 0) __t7ta721 __t3mzq20 __t8l1u11)) 0cfa-counting.slog:68 #f)
  class ReadTask775 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex758;  slog::Index** lambdaindex759;  slog::Index** refindex760;  slog::Index** lambdaindex761;  slog::Index** appindex762;  slog::Index** refindex763;  slog::Index** lambdaindex764;  slog::Index** lambdaindex765;  slog::Index** refindex766;  slog::Index** lambdaindex767;  slog::Index** refindex768;  slog::Index** lambdaindex769;  slog::Index** appindex770;  slog::Index** refindex771;  slog::Index** lambdaindex772;  slog::Index** appindex773;  slog::Index** lambdaindex774;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord776({1, 2, 0});
      slog::Relation* readrel777 = db->getRelation("app");
      head_index[0] = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({1, 0});
      slog::Relation* readrel779 = db->getRelation("ref");
      refindex758 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({1, 2, 0});
      slog::Relation* readrel781 = db->getRelation("lambda");
      lambdaindex759 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({1, 0});
      slog::Relation* readrel783 = db->getRelation("ref");
      refindex760 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({1, 2, 0});
      slog::Relation* readrel785 = db->getRelation("lambda");
      lambdaindex761 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({1, 2, 0});
      slog::Relation* readrel787 = db->getRelation("app");
      appindex762 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({1, 0});
      slog::Relation* readrel789 = db->getRelation("ref");
      refindex763 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 2, 0});
      slog::Relation* readrel791 = db->getRelation("lambda");
      lambdaindex764 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({1, 2, 0});
      slog::Relation* readrel793 = db->getRelation("lambda");
      lambdaindex765 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({1, 0});
      slog::Relation* readrel795 = db->getRelation("ref");
      refindex766 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 0});
      slog::Relation* readrel797 = db->getRelation("lambda");
      lambdaindex767 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 0});
      slog::Relation* readrel799 = db->getRelation("ref");
      refindex768 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 2, 0});
      slog::Relation* readrel801 = db->getRelation("lambda");
      lambdaindex769 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({1, 2, 0});
      slog::Relation* readrel803 = db->getRelation("app");
      appindex770 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 0});
      slog::Relation* readrel805 = db->getRelation("ref");
      refindex771 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 2, 0});
      slog::Relation* readrel807 = db->getRelation("lambda");
      lambdaindex772 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 2, 0});
      slog::Relation* readrel809 = db->getRelation("app");
      appindex773 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({1, 2, 0});
      slog::Relation* readrel811 = db->getRelation("lambda");
      lambdaindex774 = readrel811->getIndex(ord810, false);
  
    }
    ReadTask775(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c2 = v_constebbe2dfbb019b8256cb73d30;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c4 = v_constd1a4dc8b61ef51fa5f72b229;
      u64 v_c3 = v_const7265b875feb0d1730ead43d3;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex758, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m812) {
        u64 v_c10 = m812[1];
        if (!slog::exists_probe<3,1>(lambdaindex759, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex760, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex761, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex762, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex763, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex764, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex765, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(refindex766, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m813) {
          u64 v_c8 = m813[1];
          slog::join_probe<3,2>(lambdaindex767, std::array<u64,3>{v_c1, v_c8, 0}, [&](const std::array<u64,3>& m814) {
            u64 v_c7 = m814[2];
            slog::join_probe<2,1>(refindex768, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m815) {
              u64 v_c11 = m815[1];
              slog::join_probe<3,2>(lambdaindex769, std::array<u64,3>{v_c3, v_c11, 0}, [&](const std::array<u64,3>& m816) {
                u64 v_c12 = m816[2];
                slog::join_probe<3,2>(appindex770, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m817) {
                  u64 v_c13 = m817[2];
                  slog::join_probe<2,1>(refindex771, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m818) {
                    u64 v_c17 = m818[1];
                    slog::join_probe<3,2>(lambdaindex772, std::array<u64,3>{v_c4, v_c17, 0}, [&](const std::array<u64,3>& m819) {
                      u64 v_c16 = m819[2];
                      slog::join_probe<3,2>(appindex773, std::array<u64,3>{v_c10, v_c16, 0}, [&](const std::array<u64,3>& m820) {
                        u64 v_c15 = m820[2];
                        slog::join_probe<3,2>(lambdaindex774, std::array<u64,3>{v_c2, v_c15, 0}, [&](const std::array<u64,3>& m821) {
                          u64 v_c14 = m821[2];
                          ++_fires;
                          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c14, v_c13}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("0cfa-counting.slog:68", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask775(db,b));
  s->addReadRel("app");
  s->addReadRel("lambda");
  s->addReadRel("ref");
  s->addDynamicRel("app");
  s->addDynamicRel("lambda");
  s->addDynamicRel("program");
  s->addDynamicRel("ref");
  d->push(s);
  d->continueRun();
}

