
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_conste593eb62d5b2b78aac29610d;
u64 v_const99071cf3586be89134ffc1b3;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("c9d3eb95");
  if (s == nullptr) return;
  slog::Relation* r;
  v_conste593eb62d5b2b78aac29610d = db->encodeString("_lam54764x26x19");
  v_const99071cf3586be89134ffc1b3 = db->encodeString("_lam54764x26x40");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord52({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord53({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("twice");
  if (r == 0) db->addRelation("twice", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("twice");
      std::vector<u16> ord54({0});
    
    r->addIndex<1>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("twice"), std::array<u16,1>{0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord55({1, 2, 0});
    
    r->addIndex<3>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord56({0, 1, 2});
    
    r->addIndex<3>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord57({1, 2, 0});
    
    r->addIndex<3>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord58({0, 1, 2});
    
    r->addIndex<3>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("scaled");
  if (r == 0) db->addRelation("scaled", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("scaled");
      std::vector<u16> ord59({0});
    
    r->addIndex<1>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("scaled"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord60({1, 2, 3, 0});
    
    r->addIndex<4>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord61({0, 1, 2, 3});
    
    r->addIndex<4>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord62({1, 2, 0});
    
    r->addIndex<3>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord63({0, 1, 2});
    
    r->addIndex<3>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord64({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord65({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord66({1, 2, 0});
    
    r->addIndex<3>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord67({0, 1, 2});
    
    r->addIndex<3>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("map2_ans");
  if (r == 0) db->addRelation("map2_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map2_ans");
      std::vector<u16> ord68({0, 1});
    
    r->addIndex<2>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("map2_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("map2");
  if (r == 0) db->addStruct("map2", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map2");
      std::vector<u16> ord69({1, 2, 0});
    
    r->addIndex<3>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord70({0, 1, 2});
    
    r->addIndex<3>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("map2"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord71({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord72({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("kv");
  if (r == 0) db->addRelation("kv", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("kv");
      std::vector<u16> ord73({0});
    
    r->addIndex<1>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("kv"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord74({1, 2, 3, 0});
    
    r->addIndex<4>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord75({0, 1, 2, 3});
    
    r->addIndex<4>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("input");
  if (r == 0) db->addRelation("input", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("input");
      std::vector<u16> ord76({0});
    
    r->addIndex<1>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("input"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord77({0});
    
    r->addIndex<1>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord78({1, 2, 0});
    
    r->addIndex<3>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord79({0, 1, 2});
    
    r->addIndex<3>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("compose_ans");
  if (r == 0) db->addRelation("compose_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("compose_ans");
      std::vector<u16> ord80({0, 1});
    
    r->addIndex<2>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("compose_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("compose");
  if (r == 0) db->addStruct("compose", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("compose");
      std::vector<u16> ord81({2, 1, 0});
    
    r->addIndex<3>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord82({0, 1, 2});
    
    r->addIndex<3>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("compose"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("apply1_ans");
  if (r == 0) db->addRelation("apply1_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply1_ans");
      std::vector<u16> ord83({0, 1});
    
    r->addIndex<2>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("apply1_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("apply1");
  if (r == 0) db->addStruct("apply1", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply1");
      std::vector<u16> ord84({1, 2, 0});
    
    r->addIndex<3>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord85({0, 1, 2});
    
    r->addIndex<3>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("apply1"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_lam54764x22x18");
  if (r == 0) db->addStruct("_lam54764x22x18", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_lam54764x22x18");
      std::vector<u16> ord86({1, 2, 0});
    
    r->addIndex<3>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord87({0, 1, 2});
    
    r->addIndex<3>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("_lam54764x22x18"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_lam54764x18x33");
  if (r == 0) db->addStruct("_lam54764x18x33", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_lam54764x18x33");
      std::vector<u16> ord88({1, 0});
    
    r->addIndex<2>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord89({0, 1});
    
    r->addIndex<2>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_lam54764x18x33"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord90({1, 0});
    
    r->addIndex<2>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord91({0, 1});
    
    r->addIndex<2>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord92({1, 0});
    
    r->addIndex<2>(ord92, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup54764x9x0x0x0");
  if (r == 0) db->addRelation("$sup54764x9x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup54764x9x0x0x0");
      std::vector<u16> ord93({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup54764x9x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup54764x22x18x0x0");
  if (r == 0) db->addRelation("$sup54764x22x18x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup54764x22x18x0x0");
      std::vector<u16> ord94({0, 1, 2, 3});
    
    r->addIndex<4>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup54764x22x18x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord95({0, 1, 2});
    
    r->addIndex<3>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("input"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("map2"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("map2_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("scaled"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("twice"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan kv k) (body (join _lam54764x18x33 (1 0) 1 k __t2f7Q8) (join map2 (1 2 0) 1 __t2f7Q8 l __t4tCI9) (join input (0) 1 l) (join map2_ans (0 1) 1 __t4tCI9 r)) (head (emit scaled (0) r)) dem_lambda.slog:19 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _lam54764x18x33index0;  slog::Index** map2index1;  slog::Index** inputindex2;  slog::Index** map2_ansindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("scaled");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("scaled");
      head_index[0] = readrel6->getIndex(ord5, false);
      outer_rel = db->getRelation("kv");
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("_lam54764x18x33");
      _lam54764x18x33index0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({1, 2, 0});
      slog::Relation* readrel10 = db->getRelation("map2");
      map2index1 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({0});
      slog::Relation* readrel12 = db->getRelation("input");
      inputindex2 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({0, 1});
      slog::Relation* readrel14 = db->getRelation("map2_ans");
      map2_ansindex3 = readrel14->getIndex(ord13, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(_lam54764x18x33index0, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m15) {
          u64 v_c1 = m15[1];
          slog::join_probe<3,1>(map2index1, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m16) {
            u64 v_c2 = m16[1]; u64 v_c3 = m16[2];
            slog::join_probe<1,1>(inputindex2, std::array<u64,1>{v_c2}, [&](const std::array<u64,1>& m17) {
              slog::join_probe<2,1>(map2_ansindex3, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m18) {
                u64 v_c4 = m18[1];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:19", "all:kv", _fires);
  
      if (!_done)
      {
        ReadTask4* _cont = new ReadTask4(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask4(db,b), true);
  // (crule (pre (let __tconst0Adj94 const99071cf3586be89134ffc1b3) (let __tconst85t295 conste593eb62d5b2b78aac29610d)) (probe _enum (1 0) 1 __tconst0Adj94 __t38On29) (body (exists compose (2 1 0) 1 __t38On29) (join _enum (1 0) 1 __tconst85t295 __t6HRH30) (join compose (2 1 0) 2 __t38On29 __t6HRH30 __t1XJf31) (join compose_ans (0 1) 1 __t1XJf31 h) (join map2 (1 2 0) 1 h l __t8guI32) (join input (0) 1 l) (join map2_ans (0 1) 1 __t8guI32 r)) (head (emit twice (0) r)) dem_lambda.slog:26 #f)
  class ReadTask26 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** composeindex19;  slog::Index** _enumindex20;  slog::Index** composeindex21;  slog::Index** compose_ansindex22;  slog::Index** map2index23;  slog::Index** inputindex24;  slog::Index** map2_ansindex25;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("twice");
      std::vector<u16> ord27({0});
      slog::Relation* readrel28 = db->getRelation("twice");
      head_index[0] = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 0});
      slog::Relation* readrel30 = db->getRelation("_enum");
      driver_index = readrel30->getIndex(ord29, true);
      std::vector<u16> ord31({2, 1, 0});
      slog::Relation* readrel32 = db->getRelation("compose");
      composeindex19 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("_enum");
      _enumindex20 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({2, 1, 0});
      slog::Relation* readrel36 = db->getRelation("compose");
      composeindex21 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("compose_ans");
      compose_ansindex22 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 2, 0});
      slog::Relation* readrel40 = db->getRelation("map2");
      map2index23 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0});
      slog::Relation* readrel42 = db->getRelation("input");
      inputindex24 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 1});
      slog::Relation* readrel44 = db->getRelation("map2_ans");
      map2_ansindex25 = readrel44->getIndex(ord43, false);
  
    }
    ReadTask26(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const99071cf3586be89134ffc1b3;
      u64 v_c6 = v_conste593eb62d5b2b78aac29610d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c5, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m45) {
        u64 v_c7 = m45[1];
        if (buckethash(v_c7) != bucket) return;
        if (!slog::exists_probe<3,1>(composeindex19, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex20, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m46) {
          u64 v_c8 = m46[1];
          slog::join_probe<3,2>(composeindex21, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m47) {
            u64 v_c9 = m47[2];
            slog::join_probe<2,1>(compose_ansindex22, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m48) {
              u64 v_c10 = m48[1];
              slog::join_probe<3,1>(map2index23, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m49) {
                u64 v_c2 = m49[1]; u64 v_c11 = m49[2];
                slog::join_probe<1,1>(inputindex24, std::array<u64,1>{v_c2}, [&](const std::array<u64,1>& m50) {
                  slog::join_probe<2,1>(map2_ansindex25, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m51) {
                    u64 v_c4 = m51[1];
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:26", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask26* _cont = new ReadTask26(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask26(db,b), true);
  s->addReadRel("_enum");
  s->addReadRel("_lam54764x18x33");
  s->addReadRel("compose");
  s->addReadRel("compose_ans");
  s->addReadRel("input");
  s->addReadRel("kv");
  s->addReadRel("map2");
  s->addReadRel("map2_ans");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("scaled");
  s->addDynamicRel("twice");
  d->push(s);
  d->continueRun();
}

