
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_conste433800a79f2d3be41014577;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("2614b0c3");
  if (s == nullptr) return;
  slog::Relation* r;
  v_conste433800a79f2d3be41014577 = db->encodeString("halt");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord153({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord154({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord155({1, 2, 0});
    
    r->addIndex<3>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord156({0, 1, 2});
    
    r->addIndex<3>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp9hnc63");
  if (r == 0) db->addTempRelation("temp9hnc63", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6bVx62");
  if (r == 0) db->addTempRelation("temp6bVx62", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4LLY64");
  if (r == 0) db->addTempRelation("temp4LLY64", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("store");
  if (r == 0) db->addRelation("store", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("store");
      std::vector<u16> ord157({0, 1});
    
    r->addIndex<2>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("store"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord158({1, 2, 0});
    
    r->addIndex<3>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord159({0, 1, 2});
    
    r->addIndex<3>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ret");
  if (r == 0) db->addRelation("ret", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ret");
      std::vector<u16> ord160({1, 0});
    
    r->addIndex<2>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ret"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("result");
  if (r == 0) db->addRelation("result", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("result");
      std::vector<u16> ord161({0});
    
    r->addIndex<1>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("result"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord162({1, 0});
    
    r->addIndex<2>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord163({0, 1});
    
    r->addIndex<2>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("program");
  if (r == 0) db->addRelation("program", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program");
      std::vector<u16> ord164({0});
    
    r->addIndex<1>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord165({1, 2, 3, 0});
    
    r->addIndex<4>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord166({0, 1, 2, 3});
    
    r->addIndex<4>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord167({1, 2, 0});
    
    r->addIndex<3>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord168({0, 1, 2});
    
    r->addIndex<3>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord169({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord170({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord171({1, 2, 0});
    
    r->addIndex<3>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord172({0, 1, 2});
    
    r->addIndex<3>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord173({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord174({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lambda");
  if (r == 0) db->addStruct("lambda", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lambda");
      std::vector<u16> ord175({1, 2, 0});
    
    r->addIndex<3>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord176({0, 1, 2});
    
    r->addIndex<3>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lambda"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("kstore");
  if (r == 0) db->addRelation("kstore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("kstore");
      std::vector<u16> ord177({0, 1});
    
    r->addIndex<2>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord178({0, 1});
    
    r->addIndex<2>(ord178, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("kstore"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("kaddr");
  if (r == 0) db->addStruct("kaddr", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("kaddr");
      std::vector<u16> ord179({1, 0});
    
    r->addIndex<2>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord180({0, 1});
    
    r->addIndex<2>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord181({0, 1});
    
    r->addIndex<2>(ord181, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("kaddr"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord182({1, 2, 3, 0});
    
    r->addIndex<4>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord183({0, 1, 2, 3});
    
    r->addIndex<4>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("fn");
  if (r == 0) db->addStruct("fn", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fn");
      std::vector<u16> ord184({1, 2, 0});
    
    r->addIndex<3>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord185({0, 1, 2});
    
    r->addIndex<3>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord186({0, 1, 2});
    
    r->addIndex<3>(ord186, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("fn"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("eval");
  if (r == 0) db->addRelation("eval", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("eval");
      std::vector<u16> ord187({0, 1});
    
    r->addIndex<2>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord188({0, 1});
    
    r->addIndex<2>(ord188, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("eval"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord189({0});
    
    r->addIndex<1>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord190({1, 2, 0});
    
    r->addIndex<3>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord191({0, 1, 2});
    
    r->addIndex<3>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ar");
  if (r == 0) db->addStruct("ar", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ar");
      std::vector<u16> ord192({1, 2, 0});
    
    r->addIndex<3>(ord192, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord193({0, 1, 2});
    
    r->addIndex<3>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord194({0, 1, 2});
    
    r->addIndex<3>(ord194, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ar"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("app");
  if (r == 0) db->addStruct("app", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("app");
      std::vector<u16> ord195({1, 2, 0});
    
    r->addIndex<3>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord196({0, 1, 2});
    
    r->addIndex<3>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("app"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord197({1, 0});
    
    r->addIndex<2>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord198({0, 1});
    
    r->addIndex<2>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord199({1, 0});
    
    r->addIndex<2>(ord199, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("freevar");
  if (r == 0) db->addRelation("freevar", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("freevar");
      std::vector<u16> ord200({0, 1});
    
    r->addIndex<2>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("freevar"), std::array<u16,2>{0, 1}, b));
  // (crule (pre) (scan kstore __t95Ou41 k) (body (join ret (1 0) 1 __t95Ou41 v) (join-old kaddr (0 1) 1 (0 1) __t95Ou41 eb)) (head (emit ret (1 0) k v)) 0cfa.slog:58 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** retindex0;  slog::Index** kaddrindex1;  slog::Index** kaddrdelta2;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ret");
      std::vector<u16> ord4({1, 0});
      slog::Relation* readrel5 = db->getRelation("ret");
      head_index[0] = readrel5->getIndex(ord4, false);
      outer_rel = db->getRelation("kstore");
      std::vector<u16> ord6({1, 0});
      slog::Relation* readrel7 = db->getRelation("ret");
      retindex0 = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("kaddr");
      kaddrindex1 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("kaddr");
      kaddrdelta2 = readrel11->getIndex(ord10, true);
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(retindex0, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m12) {
          u64 v_c2 = m12[1];
          slog::join_probe_old<2,1>(kaddrindex1, kaddrdelta2, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m13) {
            u64 v_c3 = m13[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa.slog:58", "delta:kstore", _fires);
  
      if (!_done)
      {
        ReadTask3* _cont = new ReadTask3(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3(db,b), false);
  // (crule (pre) (scan ret v __t312Q34) (body (join-old ar (0 1 2) 1 (0 1 2) __t312Q34 ea k)) (head (emit-temp temp6bVx62 ea k v) (mkstruct fn (1 2 0) __t3IKj33 v k)) 0cfa.slog:46 #f)
  class ReadTask16 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** arindex14;  slog::Index** ardelta15;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bVx62");
      head_rel[1] = db->getRelation("fn");
      outer_rel = db->getRelation("ret");
      std::vector<u16> ord17({0, 1, 2});
      slog::Relation* readrel18 = db->getRelation("ar");
      arindex14 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({0, 1, 2});
      slog::Relation* readrel20 = db->getRelation("ar");
      ardelta15 = readrel20->getIndex(ord19, true);
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[0];
        u64 v_c4 = _t[1];
        slog::join_probe_old<3,1>(arindex14, ardelta15, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m21) {
          u64 v_c5 = m21[1]; u64 v_c1 = m21[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c5, v_c1, v_c2});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c2, v_c1}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa.slog:46", "delta:ret", _fires);
  
      if (!_done)
      {
        ReadTask16* _cont = new ReadTask16(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask16(db,b), false);
  // (crule (pre) (scan kaddr __t95Ou41 eb) (body (exists kstore (0 1) 1 __t95Ou41) (join ret (1 0) 1 __t95Ou41 v) (join kstore (0 1) 1 __t95Ou41 k)) (head (emit ret (1 0) k v)) 0cfa.slog:58 #f)
  class ReadTask25 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** kstoreindex22;  slog::Index** retindex23;  slog::Index** kstoreindex24;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ret");
      std::vector<u16> ord26({1, 0});
      slog::Relation* readrel27 = db->getRelation("ret");
      head_index[0] = readrel27->getIndex(ord26, false);
      outer_rel = db->getRelation("kaddr");
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("kstore");
      kstoreindex22 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 0});
      slog::Relation* readrel31 = db->getRelation("ret");
      retindex23 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1});
      slog::Relation* readrel33 = db->getRelation("kstore");
      kstoreindex24 = readrel33->getIndex(ord32, false);
  
    }
    ReadTask25(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<2,1>(kstoreindex22, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(retindex23, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m34) {
          u64 v_c2 = m34[1];
          slog::join_probe<2,1>(kstoreindex24, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m35) {
            u64 v_c1 = m35[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa.slog:58", "delta:kaddr", _fires);
  
      if (!_done)
      {
        ReadTask25* _cont = new ReadTask25(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask25(db,b), false);
  // (crule (pre) (scan eval __t3KEm28 k) (body (join ref (0 1) 1 __t3KEm28 x) (join store (0 1) 1 x v)) (head (emit ret (1 0) k v)) 0cfa.slog:30 #f)
  class ReadTask38 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex36;  slog::Index** storeindex37;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ret");
      std::vector<u16> ord39({1, 0});
      slog::Relation* readrel40 = db->getRelation("ret");
      head_index[0] = readrel40->getIndex(ord39, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord41({0, 1});
      slog::Relation* readrel42 = db->getRelation("ref");
      refindex36 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 1});
      slog::Relation* readrel44 = db->getRelation("store");
      storeindex37 = readrel44->getIndex(ord43, false);
  
    }
    ReadTask38(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe<2,1>(refindex36, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m45) {
          u64 v_c7 = m45[1];
          slog::join_probe<2,1>(storeindex37, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m46) {
            u64 v_c2 = m46[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa.slog:30", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask38* _cont = new ReadTask38(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask38(db,b), false);
  // (crule (pre) (scan temp6bVx62 ea k v) (body (join fn (1 2 0) 2 v k __t3IKj33)) (head (emit eval (0 1) ea __t3IKj33)) 0cfa.slog:46 #f)
  class ReadTask48 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** fnindex47;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("eval");
      head_index[0] = readrel50->getIndex(ord49, false);
      outer_rel = db->getRelation("temp6bVx62");
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("fn");
      fnindex47 = readrel52->getIndex(ord51, false);
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<3,2>(fnindex47, std::array<u64,3>{v_c2, v_c1, 0}, [&](const std::array<u64,3>& m53) {
          u64 v_c8 = m53[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c8}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa.slog:46", "delta:temp6bVx62", _fires);
  
      if (!_done)
      {
        ReadTask48* _cont = new ReadTask48(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask48(db,b), false);
  // (crule (pre) (scan store x v) (body (join ref (1 0) 1 x __t3KEm28) (join-old eval (0 1) 1 (0 1) __t3KEm28 k)) (head (emit ret (1 0) k v)) 0cfa.slog:30 #f)
  class ReadTask57 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex54;  slog::Index** evalindex55;  slog::Index** evaldelta56;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ret");
      std::vector<u16> ord58({1, 0});
      slog::Relation* readrel59 = db->getRelation("ret");
      head_index[0] = readrel59->getIndex(ord58, false);
      outer_rel = db->getRelation("store");
      std::vector<u16> ord60({1, 0});
      slog::Relation* readrel61 = db->getRelation("ref");
      refindex54 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("eval");
      evalindex55 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({0, 1});
      slog::Relation* readrel65 = db->getRelation("eval");
      evaldelta56 = readrel65->getIndex(ord64, true);
  
    }
    ReadTask57(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        slog::join_probe<2,1>(refindex54, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m66) {
          u64 v_c6 = m66[1];
          slog::join_probe_old<2,1>(evalindex55, evaldelta56, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m67) {
            u64 v_c1 = m67[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa.slog:30", "delta:store", _fires);
  
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
  // (crule (pre) (scan eval __t9Hya32 k) (body (join lambda (0 1 2) 1 __t9Hya32 x eb)) (head (emit ret (1 0) k __t9Hya32)) 0cfa.slog:41 #f)
  class ReadTask69 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex68;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ret");
      std::vector<u16> ord70({1, 0});
      slog::Relation* readrel71 = db->getRelation("ret");
      head_index[0] = readrel71->getIndex(ord70, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord72({0, 1, 2});
      slog::Relation* readrel73 = db->getRelation("lambda");
      lambdaindex68 = readrel73->getIndex(ord72, false);
  
    }
    ReadTask69(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe<3,1>(lambdaindex68, std::array<u64,3>{v_c9, 0, 0}, [&](const std::array<u64,3>& m74) {
          u64 v_c7 = m74[1]; u64 v_c3 = m74[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c9}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa.slog:41", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask69* _cont = new ReadTask69(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask69(db,b), false);
  // (crule (pre) (scan temp4LLY64 ea ef k) (body (join ar (1 2 0) 2 ea k __t1Mh929)) (head (emit eval (0 1) ef __t1Mh929)) 0cfa.slog:36 #f)
  class ReadTask76 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** arindex75;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      std::vector<u16> ord77({0, 1});
      slog::Relation* readrel78 = db->getRelation("eval");
      head_index[0] = readrel78->getIndex(ord77, false);
      outer_rel = db->getRelation("temp4LLY64");
      std::vector<u16> ord79({1, 2, 0});
      slog::Relation* readrel80 = db->getRelation("ar");
      arindex75 = readrel80->getIndex(ord79, false);
  
    }
    ReadTask76(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<3,2>(arindex75, std::array<u64,3>{v_c5, v_c1, 0}, [&](const std::array<u64,3>& m81) {
          u64 v_c11 = m81[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c11}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa.slog:36", "delta:temp4LLY64", _fires);
  
      if (!_done)
      {
        ReadTask76* _cont = new ReadTask76(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask76(db,b), false);
  // (crule (pre) (scan ar __t312Q34 ea k) (body (join ret (1 0) 1 __t312Q34 v)) (head (emit-temp temp6bVx62 ea k v) (mkstruct fn (1 2 0) __t3IKj33 v k)) 0cfa.slog:46 #f)
  class ReadTask83 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** retindex82;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bVx62");
      head_rel[1] = db->getRelation("fn");
      outer_rel = db->getRelation("ar");
      std::vector<u16> ord84({1, 0});
      slog::Relation* readrel85 = db->getRelation("ret");
      retindex82 = readrel85->getIndex(ord84, false);
  
    }
    ReadTask83(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<2,1>(retindex82, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m86) {
          u64 v_c2 = m86[1];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c5, v_c1, v_c2});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c2, v_c1}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa.slog:46", "delta:ar", _fires);
  
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
  // (crule (pre) (scan temp9hnc63 eb k) (body (join kaddr (1 0) 1 eb __t47I037)) (head (emit eval (0 1) eb __t47I037) (emit kstore (0 1) __t47I037 k)) 0cfa.slog:51 #f)
  class ReadTask88 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** kaddrindex87;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("eval");
      head_index[0] = readrel90->getIndex(ord89, false);
      head_rel[1] = db->getRelation("kstore");
      std::vector<u16> ord91({0, 1});
      slog::Relation* readrel92 = db->getRelation("kstore");
      head_index[1] = readrel92->getIndex(ord91, false);
      outer_rel = db->getRelation("temp9hnc63");
      std::vector<u16> ord93({1, 0});
      slog::Relation* readrel94 = db->getRelation("kaddr");
      kaddrindex87 = readrel94->getIndex(ord93, false);
  
    }
    ReadTask88(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe<2,1>(kaddrindex87, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m95) {
          u64 v_c12 = m95[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c3, v_c12}, std::array<u16,2>{0, 1});
          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c12, v_c1}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa.slog:51", "delta:temp9hnc63", _fires);
  
      if (!_done)
      {
        ReadTask88* _cont = new ReadTask88(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask88(db,b), false);
  // (crule (pre (let __tconst1EJh42 conste433800a79f2d3be41014577)) (probe _enum (1 0) 1 __tconst1EJh42 __t8jUN35) (body (join program (0) 0 e)) (head (emit eval (0 1) e __t8jUN35)) 0cfa.slog:25 #f)
  class ReadTask97 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** programindex96;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      std::vector<u16> ord98({0, 1});
      slog::Relation* readrel99 = db->getRelation("eval");
      head_index[0] = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 0});
      slog::Relation* readrel101 = db->getRelation("_enum");
      driver_index = readrel101->getIndex(ord100, true);
      std::vector<u16> ord102({0});
      slog::Relation* readrel103 = db->getRelation("program");
      programindex96 = readrel103->getIndex(ord102, false);
  
    }
    ReadTask97(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_conste433800a79f2d3be41014577;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c13, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m104) {
        u64 v_c14 = m104[1];
        if (buckethash(v_c14) != bucket) return;
        slog::join_all<1>(programindex96, [&](const std::array<u64,1>& m105) {
          u64 v_c15 = m105[0];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c15, v_c14}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa.slog:25", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask97* _cont = new ReadTask97(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask97(db,b), true);
  // (crule (pre) (scan ret v __t95Ou41) (body (join-old kstore (0 1) 1 (0 1) __t95Ou41 k) (join-old kaddr (0 1) 1 (0 1) __t95Ou41 eb)) (head (emit ret (1 0) k v)) 0cfa.slog:58 #f)
  class ReadTask110 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** kstoreindex106;  slog::Index** kaddrindex107;  slog::Index** kstoredelta108;  slog::Index** kaddrdelta109;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ret");
      std::vector<u16> ord111({1, 0});
      slog::Relation* readrel112 = db->getRelation("ret");
      head_index[0] = readrel112->getIndex(ord111, false);
      outer_rel = db->getRelation("ret");
      std::vector<u16> ord113({0, 1});
      slog::Relation* readrel114 = db->getRelation("kstore");
      kstoreindex106 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 1});
      slog::Relation* readrel116 = db->getRelation("kstore");
      kstoredelta108 = readrel116->getIndex(ord115, true);
      std::vector<u16> ord117({0, 1});
      slog::Relation* readrel118 = db->getRelation("kaddr");
      kaddrindex107 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({0, 1});
      slog::Relation* readrel120 = db->getRelation("kaddr");
      kaddrdelta109 = readrel120->getIndex(ord119, true);
  
    }
    ReadTask110(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c0 = _t[1];
        slog::join_probe_old<2,1>(kstoreindex106, kstoredelta108, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m121) {
          u64 v_c1 = m121[1];
          slog::join_probe_old<2,1>(kaddrindex107, kaddrdelta109, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m122) {
            u64 v_c3 = m122[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("0cfa.slog:58", "delta:ret", _fires);
  
      if (!_done)
      {
        ReadTask110* _cont = new ReadTask110(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask110(db,b), false);
  // (crule (pre) (scan eval __t2qxJ30 k) (body (join app (0 1 2) 1 __t2qxJ30 ef ea)) (head (emit-temp temp4LLY64 ea ef k) (mkstruct ar (1 2 0) __t1Mh929 ea k)) 0cfa.slog:36 #f)
  class ReadTask124 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex123;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4LLY64");
      head_rel[1] = db->getRelation("ar");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord125({0, 1, 2});
      slog::Relation* readrel126 = db->getRelation("app");
      appindex123 = readrel126->getIndex(ord125, false);
  
    }
    ReadTask124(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe<3,1>(appindex123, std::array<u64,3>{v_c16, 0, 0}, [&](const std::array<u64,3>& m127) {
          u64 v_c10 = m127[1]; u64 v_c5 = m127[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c5, v_c10, v_c1});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c5, v_c1}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("0cfa.slog:36", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask124* _cont = new ReadTask124(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask124(db,b), false);
  // (crule (pre) (scan ret v __t1wWC39) (body (join-old fn (0 1 2) 1 (0 1 2) __t1wWC39 __t1jAv38 k) (join lambda (0 1 2) 1 __t1jAv38 x eb)) (head (emit-temp temp9hnc63 eb k) (emit store (0 1) x v) (mkstruct kaddr (1 0) __t47I037 eb)) 0cfa.slog:51 #f)
  class ReadTask131 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** fnindex128;  slog::Index** lambdaindex129;  slog::Index** fndelta130;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9hnc63");
      head_rel[1] = db->getRelation("store");
      std::vector<u16> ord132({0, 1});
      slog::Relation* readrel133 = db->getRelation("store");
      head_index[1] = readrel133->getIndex(ord132, false);
      head_rel[2] = db->getRelation("kaddr");
      outer_rel = db->getRelation("ret");
      std::vector<u16> ord134({0, 1, 2});
      slog::Relation* readrel135 = db->getRelation("fn");
      fnindex128 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({0, 1, 2});
      slog::Relation* readrel137 = db->getRelation("fn");
      fndelta130 = readrel137->getIndex(ord136, true);
      std::vector<u16> ord138({0, 1, 2});
      slog::Relation* readrel139 = db->getRelation("lambda");
      lambdaindex129 = readrel139->getIndex(ord138, false);
  
    }
    ReadTask131(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
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
        u64 v_c2 = _t[0];
        u64 v_c17 = _t[1];
        slog::join_probe_old<3,1>(fnindex128, fndelta130, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m140) {
          u64 v_c18 = m140[1]; u64 v_c1 = m140[2];
          slog::join_probe<3,1>(lambdaindex129, std::array<u64,3>{v_c18, 0, 0}, [&](const std::array<u64,3>& m141) {
            u64 v_c7 = m141[1]; u64 v_c3 = m141[2];
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c1});
            slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c7, v_c2}, std::array<u16,2>{0, 1});
            slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("0cfa.slog:51", "delta:ret", _fires);
  
      if (!_done)
      {
        ReadTask131* _cont = new ReadTask131(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask131(db,b), false);
  // (crule (pre) (scan fn __t1wWC39 __t1jAv38 k) (body (join ret (1 0) 1 __t1wWC39 v) (join lambda (0 1 2) 1 __t1jAv38 x eb)) (head (emit-temp temp9hnc63 eb k) (emit store (0 1) x v) (mkstruct kaddr (1 0) __t47I037 eb)) 0cfa.slog:51 #f)
  class ReadTask144 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** retindex142;  slog::Index** lambdaindex143;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9hnc63");
      head_rel[1] = db->getRelation("store");
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("store");
      head_index[1] = readrel146->getIndex(ord145, false);
      head_rel[2] = db->getRelation("kaddr");
      outer_rel = db->getRelation("fn");
      std::vector<u16> ord147({1, 0});
      slog::Relation* readrel148 = db->getRelation("ret");
      retindex142 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 1, 2});
      slog::Relation* readrel150 = db->getRelation("lambda");
      lambdaindex143 = readrel150->getIndex(ord149, false);
  
    }
    ReadTask144(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
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
        u64 v_c17 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<2,1>(retindex142, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m151) {
          u64 v_c2 = m151[1];
          slog::join_probe<3,1>(lambdaindex143, std::array<u64,3>{v_c18, 0, 0}, [&](const std::array<u64,3>& m152) {
            u64 v_c7 = m152[1]; u64 v_c3 = m152[2];
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c1});
            slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c7, v_c2}, std::array<u16,2>{0, 1});
            slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("0cfa.slog:51", "delta:fn", _fires);
  
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
  s->addReadRel("_enum");
  s->addReadRel("app");
  s->addReadRel("ar");
  s->addReadRel("eval");
  s->addReadRel("fn");
  s->addReadRel("kaddr");
  s->addReadRel("kstore");
  s->addReadRel("lambda");
  s->addReadRel("program");
  s->addReadRel("ref");
  s->addReadRel("ret");
  s->addReadRel("store");
  s->addReadRel("temp4LLY64");
  s->addReadRel("temp6bVx62");
  s->addReadRel("temp9hnc63");
  s->addDynamicRel("ar");
  s->addDynamicRel("eval");
  s->addDynamicRel("fn");
  s->addDynamicRel("kaddr");
  s->addDynamicRel("kstore");
  s->addDynamicRel("ret");
  s->addDynamicRel("store");
  s->addDynamicRel("temp4LLY64");
  s->addDynamicRel("temp6bVx62");
  s->addDynamicRel("temp9hnc63");
  s->addAccelRel("eval");
  s->addAccelRel("kstore");
  s->addAccelRel("ret");
  s->addAccelRel("store");
  d->push(s);
  d->continueRun();
}

