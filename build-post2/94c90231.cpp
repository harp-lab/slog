
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("94c90231");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord135({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord136({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord137({1, 2, 0});
    
    r->addIndex<3>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord138({0, 1, 2});
    
    r->addIndex<3>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("subject");
  if (r == 0) db->addRelation("subject", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("subject");
      std::vector<u16> ord139({0});
    
    r->addIndex<1>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("subject"), std::array<u16,1>{0}, b));
  r = db->getRelation("state");
  if (r == 0) db->addRelation("state", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("state");
      std::vector<u16> ord140({0});
    
    r->addIndex<1>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("state"), std::array<u16,1>{0}, b));
  r = db->getRelation("star");
  if (r == 0) db->addStruct("star", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("star");
      std::vector<u16> ord141({1, 0});
    
    r->addIndex<2>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord142({0, 1});
    
    r->addIndex<2>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("star"), std::array<u16,2>{1, 0}, b));
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
  r = db->getRelation("run_ans");
  if (r == 0) db->addRelation("run_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("run_ans");
      std::vector<u16> ord145({0, 1});
    
    r->addIndex<2>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("run_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("run");
  if (r == 0) db->addStruct("run", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("run");
      std::vector<u16> ord146({1, 2, 0});
    
    r->addIndex<3>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord147({0, 1, 2});
    
    r->addIndex<3>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord148({2, 0, 1});
    
    r->addIndex<3>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("run"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("query");
  if (r == 0) db->addRelation("query", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("query");
      std::vector<u16> ord149({0, 1});
    
    r->addIndex<2>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("query"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nullable_ans");
  if (r == 0) db->addRelation("nullable_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nullable_ans");
      std::vector<u16> ord150({0, 1});
    
    r->addIndex<2>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("nullable_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nullable");
  if (r == 0) db->addStruct("nullable", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nullable");
      std::vector<u16> ord151({1, 0});
    
    r->addIndex<2>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord152({0, 1});
    
    r->addIndex<2>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("nullable"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("nfa");
  if (r == 0) db->addRelation("nfa", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nfa");
      std::vector<u16> ord153({0, 1, 2});
    
    r->addIndex<3>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("nfa"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord154({1, 2, 3, 0});
    
    r->addIndex<4>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord155({0, 1, 2, 3});
    
    r->addIndex<4>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord156({1, 2, 0});
    
    r->addIndex<3>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord157({0, 1, 2});
    
    r->addIndex<3>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord158({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord159({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord160({1, 2, 0});
    
    r->addIndex<3>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord161({0, 1, 2});
    
    r->addIndex<3>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mkcat_ans");
  if (r == 0) db->addRelation("mkcat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mkcat_ans");
      std::vector<u16> ord162({0, 1});
    
    r->addIndex<2>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mkcat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mkcat");
  if (r == 0) db->addStruct("mkcat", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mkcat");
      std::vector<u16> ord163({1, 2, 0});
    
    r->addIndex<3>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord164({0, 1, 2});
    
    r->addIndex<3>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mkcat"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("match");
  if (r == 0) db->addRelation("match", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("match");
      std::vector<u16> ord165({0, 1});
    
    r->addIndex<2>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("match"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord166({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord167({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord168({1, 2, 3, 0});
    
    r->addIndex<4>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord169({0, 1, 2, 3});
    
    r->addIndex<4>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("frag");
  if (r == 0) db->addRelation("frag", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("frag");
      std::vector<u16> ord170({0});
    
    r->addIndex<1>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("frag"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord171({0});
    
    r->addIndex<1>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord172({1, 2, 0});
    
    r->addIndex<3>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord173({0, 1, 2});
    
    r->addIndex<3>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("deriv_ans");
  if (r == 0) db->addRelation("deriv_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("deriv_ans");
      std::vector<u16> ord174({0, 1});
    
    r->addIndex<2>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord175({1, 0});
    
    r->addIndex<2>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("deriv_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("deriv");
  if (r == 0) db->addStruct("deriv", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("deriv");
      std::vector<u16> ord176({2, 1, 0});
    
    r->addIndex<3>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord177({0, 1, 2});
    
    r->addIndex<3>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("deriv"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("chr");
  if (r == 0) db->addStruct("chr", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("chr");
      std::vector<u16> ord178({1, 0});
    
    r->addIndex<2>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord179({0, 1});
    
    r->addIndex<2>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("chr"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("cat");
  if (r == 0) db->addStruct("cat", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("cat");
      std::vector<u16> ord180({1, 2, 0});
    
    r->addIndex<3>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord181({0, 1, 2});
    
    r->addIndex<3>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("cat"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("alt");
  if (r == 0) db->addStruct("alt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("alt");
      std::vector<u16> ord182({1, 2, 0});
    
    r->addIndex<3>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord183({0, 1, 2});
    
    r->addIndex<3>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("alt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("alpha");
  if (r == 0) db->addRelation("alpha", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("alpha");
      std::vector<u16> ord184({0});
    
    r->addIndex<1>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("alpha"), std::array<u16,1>{0}, b));
  r = db->getRelation("accepting");
  if (r == 0) db->addRelation("accepting", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("accepting");
      std::vector<u16> ord185({0});
    
    r->addIndex<1>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("accepting"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord186({1, 0});
    
    r->addIndex<2>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord187({0, 1});
    
    r->addIndex<2>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup14449x83x0x0x0");
  if (r == 0) db->addRelation("$sup14449x83x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x83x0x0x0");
      std::vector<u16> ord188({3, 0, 2, 1, 4});
    
    r->addIndex<5>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 0, 2, 1, 4}, false, b), true);
      std::vector<u16> ord189({2, 3, 4, 0, 1});
    
    r->addIndex<5>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 3, 4, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup14449x83x0x0x0"), std::array<u16,5>{3, 0, 2, 1, 4}, b));
  r = db->getRelation("$sup14449x71x0x0x1");
  if (r == 0) db->addRelation("$sup14449x71x0x0x1", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x71x0x0x1");
      std::vector<u16> ord190({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup14449x71x0x0x1"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup14449x71x0x0x0");
  if (r == 0) db->addRelation("$sup14449x71x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x71x0x0x0");
      std::vector<u16> ord191({0, 1, 2, 3});
    
    r->addIndex<4>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup14449x71x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup14449x70x0x0x0");
  if (r == 0) db->addRelation("$sup14449x70x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x70x0x0x0");
      std::vector<u16> ord192({0, 1, 2, 3});
    
    r->addIndex<4>(ord192, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup14449x70x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup14449x69x0x0x0");
  if (r == 0) db->addRelation("$sup14449x69x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x69x0x0x0");
      std::vector<u16> ord193({0, 1, 2, 3});
    
    r->addIndex<4>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup14449x69x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup14449x68x0x0x0");
  if (r == 0) db->addRelation("$sup14449x68x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x68x0x0x0");
      std::vector<u16> ord194({0, 1, 2, 3});
    
    r->addIndex<4>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup14449x68x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup14449x46x0x0x0");
  if (r == 0) db->addRelation("$sup14449x46x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x46x0x0x0");
      std::vector<u16> ord195({0, 1, 2});
    
    r->addIndex<3>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup14449x46x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup14449x45x0x0x0");
  if (r == 0) db->addRelation("$sup14449x45x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x45x0x0x0");
      std::vector<u16> ord196({0, 1, 2});
    
    r->addIndex<3>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup14449x45x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord197({1, 0, 2});
    
    r->addIndex<3>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
      std::vector<u16> ord198({1, 0, 2});
    
    r->addIndex<3>(ord198, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{1, 0, 2}, b));
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("run"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan div_by_zero __erre70u9359 __errf07pP360 __errf8tCN361) (body) (head (emit error (0) __erre70u9359)) <internal>:1 #f)
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
      outer_rel = db->getRelation("div_by_zero");
  
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre (let _00024sqc0BMh151 const6b86b273ff34fce19d6b804e) (let _00024sqc84j8152 const5feceb66ffc86f38d952786c) (let _00024sqc3Nc1153 const6b86b273ff34fce19d6b804e) (let _00024sqc3yfR154 const5feceb66ffc86f38d952786c) (let _00024sqo4hCB159 const5feceb66ffc86f38d952786c)) (scan run_ans __t1EoI40 __v1) (body (exists $seq_at (1 0 2) 1 _00024sqo4hCB159) (join run (0 1 2) 1 __t1EoI40 __v0 cs) (exists $sup14449x83x0x0x0 (3 0 2 1 4) 1 cs) (join deriv_ans (1 0) 1 __v0 __t64Hw39) (join deriv (0 1 2) 1 __t64Hw39 r c) (exists run (1 2 0) 1 r) (exists $seq_at (1 0 2) 2 _00024sqo4hCB159 c) (join $sup14449x83x0x0x0 (2 3 4 0 1) 3 c cs r _00024seq0 __t56Ql38) (join run (1 2 0) 3 r _00024seq0 __t56Ql38) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo4hCB159 c _00024seq0) (letp _00024sql5Fed149 (aslst _00024seq0)) (let _00024sqn5Wub150 (llen _00024sql5Fed149)) (cmp ge _00024sqn5Wub150 _00024sqc0BMh151) (letp chk3ZyV389 (lref _00024sql5Fed149 _00024sqc84j8152)) (eq c chk3ZyV389) (let _00024sqp9FT9155 (_0002d _00024sqn5Wub150 _00024sqc3yfR154)) (let chk98DZ390 (lslice _00024sql5Fed149 _00024sqc3Nc1153 _00024sqp9FT9155)) (eq cs chk98DZ390)) (head (emit run_ans (0 1) __t56Ql38 __v1)) antimirov.slog:84 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex3;  slog::Index** runindex4;  slog::Index** $sup14449x83x0x0x0index5;  slog::Index** deriv_ansindex6;  slog::Index** derivindex7;  slog::Index** runindex8;  slog::Index** $seq_atindex9;  slog::Index** $sup14449x83x0x0x0index10;  slog::Index** runindex11;  slog::Index** $seq_atindex12;  slog::Index** $seq_atdelta13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("run_ans");
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("run_ans");
      head_index[0] = readrel16->getIndex(ord15, false);
      outer_rel = db->getRelation("run_ans");
      std::vector<u16> ord17({1, 0, 2});
      slog::Relation* readrel18 = db->getRelation("$seq_at");
      $seq_atindex3 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({0, 1, 2});
      slog::Relation* readrel20 = db->getRelation("run");
      runindex4 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({3, 0, 2, 1, 4});
      slog::Relation* readrel22 = db->getRelation("$sup14449x83x0x0x0");
      $sup14449x83x0x0x0index5 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 0});
      slog::Relation* readrel24 = db->getRelation("deriv_ans");
      deriv_ansindex6 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 1, 2});
      slog::Relation* readrel26 = db->getRelation("deriv");
      derivindex7 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 2, 0});
      slog::Relation* readrel28 = db->getRelation("run");
      runindex8 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 0, 2});
      slog::Relation* readrel30 = db->getRelation("$seq_at");
      $seq_atindex9 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({2, 3, 4, 0, 1});
      slog::Relation* readrel32 = db->getRelation("$sup14449x83x0x0x0");
      $sup14449x83x0x0x0index10 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0});
      slog::Relation* readrel34 = db->getRelation("run");
      runindex11 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0, 2});
      slog::Relation* readrel36 = db->getRelation("$seq_at");
      $seq_atindex12 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 0, 2});
      slog::Relation* readrel38 = db->getRelation("$seq_at");
      $seq_atdelta13 = readrel38->getIndex(ord37, true);
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c8 = _t[0];
        u64 v_c9 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex3, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<3,1>(runindex4, std::array<u64,3>{v_c8, 0, 0}, [&](const std::array<u64,3>& m39) {
          u64 v_c10 = m39[1]; u64 v_c11 = m39[2];
          if (!slog::exists_probe<5,1>($sup14449x83x0x0x0index5, std::array<u64,5>{v_c11, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(deriv_ansindex6, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m40) {
            u64 v_c12 = m40[1];
            slog::join_probe<3,1>(derivindex7, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m41) {
              u64 v_c13 = m41[1]; u64 v_c14 = m41[2];
              if (!slog::exists_probe<3,1>(runindex8, std::array<u64,3>{v_c13, 0, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atindex9, std::array<u64,3>{v_c7, v_c14, 0})) return;
              slog::join_probe<5,3>($sup14449x83x0x0x0index10, std::array<u64,5>{v_c14, v_c11, v_c13, 0, 0}, [&](const std::array<u64,5>& m42) {
                u64 v_c15 = m42[3]; u64 v_c16 = m42[4];
                slog::join_probe<3,3>(runindex11, std::array<u64,3>{v_c13, v_c15, v_c16}, [&](const std::array<u64,3>& m43) {
                  slog::join_probe_old<3,3>($seq_atindex12, $seq_atdelta13, std::array<u64,3>{v_c7, v_c14, v_c15}, [&](const std::array<u64,3>& m44) {
                    bool ok45 = true;
                    u64 v_c17 = _prim_aslst(db, v_c15, &ok45);
                    if (!ok45) return;
                    u64 v_c18 = _prim_llen(db, v_c17);
                    if (v_c18 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
                    u64 v_c19 = _prim_ge(db, v_c18, v_c3);
                    if (v_c19 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
                    if (!v_c19) return;
                    bool ok47 = true;
                    u64 v_c20 = _prim_lref(db, v_c17, v_c4, &ok47);
                    if (!ok47) return;
                    if (v_c14 != v_c20) return;
                    u64 v_c21 = _prim__0002d(db, v_c18, v_c6);
                    if (v_c21 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
                    u64 v_c22 = _prim_lslice(db, v_c17, v_c5, v_c21);
                    if (v_c22 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
                    if (v_c11 != v_c22) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c9}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:84", "delta:run_ans", _fires);
  
      if (!_done)
      {
        ReadTask14* _cont = new ReadTask14(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask14(db,b), false);
  // (crule (pre) (scan nan_result __erre30Wi369 __errf6gZu370 __errf0X9V371 __errf1Gof372) (body) (head (emit error (0) __erre30Wi369)) <internal>:1 #f)
  class ReadTask48 : public slog::Task
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
      std::vector<u16> ord49({0});
      slog::Relation* readrel50 = db->getRelation("error");
      head_index[0] = readrel50->getIndex(ord49, false);
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre) (scan type_mismatch __erre3WR0376 __errf0zDM377 __errf8c4r378 __errf4ev2379 __errf2h6d380) (body) (head (emit error (0) __erre3WR0376)) <internal>:1 #f)
  class ReadTask51 : public slog::Task
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
      std::vector<u16> ord52({0});
      slog::Relation* readrel53 = db->getRelation("error");
      head_index[0] = readrel53->getIndex(ord52, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask51(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c30 = _t[3];
        u64 v_c31 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask51* _cont = new ReadTask51(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask51(db,b), false);
  // (crule (pre (let _00024sqc0BMh151 const6b86b273ff34fce19d6b804e) (let _00024sqc84j8152 const5feceb66ffc86f38d952786c) (let _00024sqc3Nc1153 const6b86b273ff34fce19d6b804e) (let _00024sqc3yfR154 const5feceb66ffc86f38d952786c) (let _00024sqo4hCB159 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo4hCB159 c _00024seq0) (body (letp _00024sql5Fed149 (aslst _00024seq0)) (let _00024sqn5Wub150 (llen _00024sql5Fed149)) (cmp ge _00024sqn5Wub150 _00024sqc0BMh151) (let _00024sqp9FT9155 (_0002d _00024sqn5Wub150 _00024sqc3yfR154)) (let cs (lslice _00024sql5Fed149 _00024sqc3Nc1153 _00024sqp9FT9155)) (exists run (2 0 1) 1 _00024seq0) (exists deriv (2 1 0) 1 c) (exists run (2 0 1) 1 cs) (join $sup14449x83x0x0x0 (3 0 2 1 4) 3 cs _00024seq0 c __t56Ql38 r) (join run (1 2 0) 3 r _00024seq0 __t56Ql38) (join deriv (2 1 0) 2 c r __t64Hw39) (join deriv_ans (0 1) 1 __t64Hw39 __v0) (join run (1 2 0) 2 __v0 cs __t1EoI40) (join run_ans (0 1) 1 __t1EoI40 __v1) (letp chk3BZA391 (lref _00024sql5Fed149 _00024sqc84j8152)) (eq c chk3BZA391)) (head (emit run_ans (0 1) __t56Ql38 __v1)) antimirov.slog:84 #f)
  class ReadTask63 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** runindex54;  slog::Index** derivindex55;  slog::Index** runindex56;  slog::Index** $sup14449x83x0x0x0index57;  slog::Index** runindex58;  slog::Index** derivindex59;  slog::Index** deriv_ansindex60;  slog::Index** runindex61;  slog::Index** run_ansindex62;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("run_ans");
      std::vector<u16> ord64({0, 1});
      slog::Relation* readrel65 = db->getRelation("run_ans");
      head_index[0] = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 0, 2});
      slog::Relation* readrel67 = db->getRelation("$seq_at");
      driver_index = readrel67->getIndex(ord66, true);
      std::vector<u16> ord68({2, 0, 1});
      slog::Relation* readrel69 = db->getRelation("run");
      runindex54 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({2, 1, 0});
      slog::Relation* readrel71 = db->getRelation("deriv");
      derivindex55 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({2, 0, 1});
      slog::Relation* readrel73 = db->getRelation("run");
      runindex56 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({3, 0, 2, 1, 4});
      slog::Relation* readrel75 = db->getRelation("$sup14449x83x0x0x0");
      $sup14449x83x0x0x0index57 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 2, 0});
      slog::Relation* readrel77 = db->getRelation("run");
      runindex58 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({2, 1, 0});
      slog::Relation* readrel79 = db->getRelation("deriv");
      derivindex59 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({0, 1});
      slog::Relation* readrel81 = db->getRelation("deriv_ans");
      deriv_ansindex60 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 2, 0});
      slog::Relation* readrel83 = db->getRelation("run");
      runindex61 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("run_ans");
      run_ansindex62 = readrel85->getIndex(ord84, false);
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c7, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m86) {
        u64 v_c14 = m86[1];
        u64 v_c15 = m86[2];
        if (buckethash(v_c14) != bucket) return;
        bool ok87 = true;
        u64 v_c17 = _prim_aslst(db, v_c15, &ok87);
        if (!ok87) return;
        u64 v_c18 = _prim_llen(db, v_c17);
        if (v_c18 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
        u64 v_c32 = _prim_ge(db, v_c18, v_c3);
        if (v_c32 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
        if (!v_c32) return;
        u64 v_c21 = _prim__0002d(db, v_c18, v_c6);
        if (v_c21 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
        u64 v_c11 = _prim_lslice(db, v_c17, v_c5, v_c21);
        if (v_c11 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:84"); return; }
        if (!slog::exists_probe<3,1>(runindex54, std::array<u64,3>{v_c15, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex55, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(runindex56, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<5,3>($sup14449x83x0x0x0index57, std::array<u64,5>{v_c11, v_c15, v_c14, 0, 0}, [&](const std::array<u64,5>& m89) {
          u64 v_c16 = m89[3]; u64 v_c13 = m89[4];
          slog::join_probe<3,3>(runindex58, std::array<u64,3>{v_c13, v_c15, v_c16}, [&](const std::array<u64,3>& m90) {
            slog::join_probe<3,2>(derivindex59, std::array<u64,3>{v_c14, v_c13, 0}, [&](const std::array<u64,3>& m91) {
              u64 v_c12 = m91[2];
              slog::join_probe<2,1>(deriv_ansindex60, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m92) {
                u64 v_c10 = m92[1];
                slog::join_probe<3,2>(runindex61, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m93) {
                  u64 v_c8 = m93[2];
                  slog::join_probe<2,1>(run_ansindex62, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m94) {
                    u64 v_c9 = m94[1];
                    bool ok95 = true;
                    u64 v_c33 = _prim_lref(db, v_c17, v_c4, &ok95);
                    if (!ok95) return;
                    if (v_c14 != v_c33) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c9}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:84", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask63* _cont = new ReadTask63(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask63(db,b), false);
  // (crule (pre) (scan int_overflow __erre3HQB365 __errf52HD366 __errf70P2367 __errf1xw4368) (body) (head (emit error (0) __erre3HQB365)) <internal>:1 #f)
  class ReadTask96 : public slog::Task
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
      std::vector<u16> ord97({0});
      slog::Relation* readrel98 = db->getRelation("error");
      head_index[0] = readrel98->getIndex(ord97, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask96(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c34 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c37 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c34}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask96* _cont = new ReadTask96(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask96(db,b), false);
  // (crule (pre) (scan toint_range __erre62wX373 __errf2wX8374 __errf0kwj375) (body) (head (emit error (0) __erre62wX373)) <internal>:1 #f)
  class ReadTask99 : public slog::Task
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
      std::vector<u16> ord100({0});
      slog::Relation* readrel101 = db->getRelation("error");
      head_index[0] = readrel101->getIndex(ord100, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask99(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c38 = _t[0];
        u64 v_c39 = _t[1];
        u64 v_c40 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c38}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask99* _cont = new ReadTask99(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask99(db,b), false);
  // (crule (pre (let __tconst8dpy105 const5feceb66ffc86f38d952786c)) (scan state r) (body (join nullable (1 0) 1 r __t2Rlf106) (join nullable_ans (0 1) 1 __t2Rlf106 n) (cmp lt __tconst8dpy105 n)) (head (emit accepting (0) r)) antimirov.slog:116 #f)
  class ReadTask104 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex102;  slog::Index** nullable_ansindex103;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("accepting");
      std::vector<u16> ord105({0});
      slog::Relation* readrel106 = db->getRelation("accepting");
      head_index[0] = readrel106->getIndex(ord105, false);
      outer_rel = db->getRelation("state");
      std::vector<u16> ord107({1, 0});
      slog::Relation* readrel108 = db->getRelation("nullable");
      nullableindex102 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("nullable_ans");
      nullable_ansindex103 = readrel110->getIndex(ord109, false);
  
    }
    ReadTask104(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c13 = _t[0];
        slog::join_probe<2,1>(nullableindex102, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m111) {
          u64 v_c42 = m111[1];
          slog::join_probe<2,1>(nullable_ansindex103, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m112) {
            u64 v_c43 = m112[1];
            u64 v_c44 = _prim_lt(db, v_c41, v_c43);
            if (v_c44 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:116"); return; }
            if (!v_c44) return;
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:116", "all:state", _fires);
  
      if (!_done)
      {
        ReadTask104* _cont = new ReadTask104(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask104(db,b), true);
  // (crule (pre (let _00024sqc8xRx138 const5feceb66ffc86f38d952786c)) (scan nullable_ans __t7L2Q79 __v0) (body (join nullable (0 1) 1 __t7L2Q79 r) (join run (1 2 0) 1 r _00024seq0 __t33xv78) (letp _00024sql8ocV136 (aslst _00024seq0)) (let chk8X5t392 (llen _00024sql8ocV136)) (eq _00024sqc8xRx138 chk8X5t392)) (head (emit run_ans (0 1) __t33xv78 __v0)) antimirov.slog:83 #f)
  class ReadTask116 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex114;  slog::Index** runindex115;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("run_ans");
      std::vector<u16> ord117({0, 1});
      slog::Relation* readrel118 = db->getRelation("run_ans");
      head_index[0] = readrel118->getIndex(ord117, false);
      outer_rel = db->getRelation("nullable_ans");
      std::vector<u16> ord119({0, 1});
      slog::Relation* readrel120 = db->getRelation("nullable");
      nullableindex114 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("run");
      runindex115 = readrel122->getIndex(ord121, false);
  
    }
    ReadTask116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c46 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe<2,1>(nullableindex114, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m123) {
          u64 v_c13 = m123[1];
          slog::join_probe<3,1>(runindex115, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m124) {
            u64 v_c15 = m124[1]; u64 v_c47 = m124[2];
            bool ok125 = true;
            u64 v_c48 = _prim_aslst(db, v_c15, &ok125);
            if (!ok125) return;
            u64 v_c49 = _prim_llen(db, v_c48);
            if (v_c49 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:83"); return; }
            if (v_c45 != v_c49) return;
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c47, v_c10}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:83", "all:nullable_ans", _fires);
  
      if (!_done)
      {
        ReadTask116* _cont = new ReadTask116(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask116(db,b), true);
  // (crule (pre) (scan mpz_table_overflow __erre6Bsy386 __errf4kR6387 __errf72IC388) (body) (head (emit error (0) __erre6Bsy386)) <internal>:1 #f)
  class ReadTask126 : public slog::Task
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
      std::vector<u16> ord127({0});
      slog::Relation* readrel128 = db->getRelation("error");
      head_index[0] = readrel128->getIndex(ord127, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask126(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask126* _cont = new ReadTask126(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask126(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre7TYs381 __errf4Tqh382 __errf3c8q383 __errf6fqy384 __errf2vix385) (body) (head (emit error (0) __erre7TYs381)) <internal>:1 #f)
  class ReadTask129 : public slog::Task
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
      std::vector<u16> ord130({0});
      slog::Relation* readrel131 = db->getRelation("error");
      head_index[0] = readrel131->getIndex(ord130, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask129(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask129* _cont = new ReadTask129(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask129(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre78NY362 __errf8lgg363 __errf3BGj364) (body) (head (emit error (0) __erre78NY362)) <internal>:1 #f)
  class ReadTask132 : public slog::Task
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
      std::vector<u16> ord133({0});
      slog::Relation* readrel134 = db->getRelation("error");
      head_index[0] = readrel134->getIndex(ord133, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask132(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c58 = _t[0];
        u64 v_c59 = _t[1];
        u64 v_c60 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c58}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask132* _cont = new ReadTask132(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask132(db,b), false);
  s->addReadRel("$seq_at");
  s->addReadRel("$sup14449x83x0x0x0");
  s->addReadRel("deriv");
  s->addReadRel("deriv_ans");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("nullable");
  s->addReadRel("nullable_ans");
  s->addReadRel("run");
  s->addReadRel("run_ans");
  s->addReadRel("state");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("accepting");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("run_ans");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("run_ans");
  d->push(s);
  d->continueRun();
}

