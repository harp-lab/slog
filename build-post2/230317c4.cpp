
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constef2d127de37b942baad06145;
u64 v_const27badc983df1780b60c2b3fa;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const983bd614bb5afece5ab3b602;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constad57366865126e55649ecb23;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("230317c4");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const27badc983df1780b60c2b3fa = s32_encode(200);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const983bd614bb5afece5ab3b602 = s32_encode(300);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constad57366865126e55649ecb23 = s32_encode(100);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord29({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord30({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord31({1, 2, 0});
    
    r->addIndex<3>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord32({0, 1, 2});
    
    r->addIndex<3>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord33({1, 2, 0});
    
    r->addIndex<3>(ord33, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord34({0, 1, 2});
    
    r->addIndex<3>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("q");
  if (r == 0) db->addRelation("q", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("q");
      std::vector<u16> ord35({0});
    
    r->addIndex<1>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("q"), std::array<u16,1>{0}, b));
  r = db->getRelation("p");
  if (r == 0) db->addRelation("p", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("p");
      std::vector<u16> ord36({0});
    
    r->addIndex<1>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("p"), std::array<u16,1>{0}, b));
  r = db->getRelation("o3");
  if (r == 0) db->addRelation("o3", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("o3");
      std::vector<u16> ord37({0, 1});
    
    r->addIndex<2>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("o3"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("o2");
  if (r == 0) db->addRelation("o2", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("o2");
      std::vector<u16> ord38({0});
    
    r->addIndex<1>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("o2"), std::array<u16,1>{0}, b));
  r = db->getRelation("o1");
  if (r == 0) db->addRelation("o1", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("o1");
      std::vector<u16> ord39({0});
    
    r->addIndex<1>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("o1"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord40({1, 2, 3, 0});
    
    r->addIndex<4>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord41({0, 1, 2, 3});
    
    r->addIndex<4>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord42({1, 2, 0});
    
    r->addIndex<3>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord43({0, 1, 2});
    
    r->addIndex<3>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord44({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord45({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord46({1, 2, 0});
    
    r->addIndex<3>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord47({0, 1, 2});
    
    r->addIndex<3>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord48({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord49({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord50({1, 2, 3, 0});
    
    r->addIndex<4>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord51({0, 1, 2, 3});
    
    r->addIndex<4>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("h");
  if (r == 0) db->addRelation("h", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("h");
      std::vector<u16> ord52({0});
    
    r->addIndex<1>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("h"), std::array<u16,1>{0}, b));
  r = db->getRelation("g");
  if (r == 0) db->addRelation("g", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("g");
      std::vector<u16> ord53({0});
    
    r->addIndex<1>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("g"), std::array<u16,1>{0}, b));
  r = db->getRelation("f");
  if (r == 0) db->addRelation("f", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("f");
      std::vector<u16> ord54({0});
    
    r->addIndex<1>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("f"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord55({0});
    
    r->addIndex<1>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("e");
  if (r == 0) db->addRelation("e", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("e");
      std::vector<u16> ord56({0, 1});
    
    r->addIndex<2>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("e"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord57({1, 2, 0});
    
    r->addIndex<3>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord58({0, 1, 2});
    
    r->addIndex<3>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("d");
  if (r == 0) db->addRelation("d", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("d");
      std::vector<u16> ord59({0});
    
    r->addIndex<1>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("d"), std::array<u16,1>{0}, b));
  r = db->getRelation("c");
  if (r == 0) db->addRelation("c", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("c");
      std::vector<u16> ord60({0});
    
    r->addIndex<1>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("c"), std::array<u16,1>{0}, b));
  r = db->getRelation("b");
  if (r == 0) db->addRelation("b", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("b");
      std::vector<u16> ord61({0});
    
    r->addIndex<1>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("b"), std::array<u16,1>{0}, b));
  r = db->getRelation("a");
  if (r == 0) db->addRelation("a", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a");
      std::vector<u16> ord62({0});
    
    r->addIndex<1>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord63({1, 0});
    
    r->addIndex<2>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord64({0, 1});
    
    r->addIndex<2>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst3Pwm6 const4a44dc15364204a80fe80e90) (let __tconst5kKV8 const4b227777d4dd1fc61c6f884f) (let __tconst27NR9 constad57366865126e55649ecb23) (let __tconst38Ku11 const27badc983df1780b60c2b3fa) (let __tconst3wY813 const983bd614bb5afece5ab3b602) (let __tconst0o9316 constd4735e3a265e16eee03f5971) (let __tconst0hAe17 const6b86b273ff34fce19d6b804e) (let __tconst8JN918 const4e07408562bedb8b60ce05c1) (let __tconst0j3o19 constef2d127de37b942baad06145)) (once) (body) (head (emit a (0) __tconst0hAe17) (emit a (0) __tconst3Pwm6) (emit b (0) __tconst0o9316) (emit b (0) __tconst3Pwm6) (emit c (0) __tconst8JN918) (emit d (0) __tconst5kKV8) (emit e (0 1) __tconst0hAe17 __tconst27NR9) (emit e (0 1) __tconst0o9316 __tconst38Ku11) (emit e (0 1) __tconst8JN918 __tconst3wY813) (emit f (0) __tconst0hAe17) (emit g (0) __tconst0o9316) (emit p (0) __tconst0hAe17) (emit p (0) __tconst8JN918) (emit p (0) __tconst0j3o19)) shape_or.slog:30 #f)
  class ReadTask0 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[14];
    slog::Index** head_index[14];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("a");
      std::vector<u16> ord1({0});
      slog::Relation* readrel2 = db->getRelation("a");
      head_index[0] = readrel2->getIndex(ord1, false);
      head_rel[1] = db->getRelation("a");
      std::vector<u16> ord3({0});
      slog::Relation* readrel4 = db->getRelation("a");
      head_index[1] = readrel4->getIndex(ord3, false);
      head_rel[2] = db->getRelation("b");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("b");
      head_index[2] = readrel6->getIndex(ord5, false);
      head_rel[3] = db->getRelation("b");
      std::vector<u16> ord7({0});
      slog::Relation* readrel8 = db->getRelation("b");
      head_index[3] = readrel8->getIndex(ord7, false);
      head_rel[4] = db->getRelation("c");
      std::vector<u16> ord9({0});
      slog::Relation* readrel10 = db->getRelation("c");
      head_index[4] = readrel10->getIndex(ord9, false);
      head_rel[5] = db->getRelation("d");
      std::vector<u16> ord11({0});
      slog::Relation* readrel12 = db->getRelation("d");
      head_index[5] = readrel12->getIndex(ord11, false);
      head_rel[6] = db->getRelation("e");
      std::vector<u16> ord13({0, 1});
      slog::Relation* readrel14 = db->getRelation("e");
      head_index[6] = readrel14->getIndex(ord13, false);
      head_rel[7] = db->getRelation("e");
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("e");
      head_index[7] = readrel16->getIndex(ord15, false);
      head_rel[8] = db->getRelation("e");
      std::vector<u16> ord17({0, 1});
      slog::Relation* readrel18 = db->getRelation("e");
      head_index[8] = readrel18->getIndex(ord17, false);
      head_rel[9] = db->getRelation("f");
      std::vector<u16> ord19({0});
      slog::Relation* readrel20 = db->getRelation("f");
      head_index[9] = readrel20->getIndex(ord19, false);
      head_rel[10] = db->getRelation("g");
      std::vector<u16> ord21({0});
      slog::Relation* readrel22 = db->getRelation("g");
      head_index[10] = readrel22->getIndex(ord21, false);
      head_rel[11] = db->getRelation("p");
      std::vector<u16> ord23({0});
      slog::Relation* readrel24 = db->getRelation("p");
      head_index[11] = readrel24->getIndex(ord23, false);
      head_rel[12] = db->getRelation("p");
      std::vector<u16> ord25({0});
      slog::Relation* readrel26 = db->getRelation("p");
      head_index[12] = readrel26->getIndex(ord25, false);
      head_rel[13] = db->getRelation("p");
      std::vector<u16> ord27({0});
      slog::Relation* readrel28 = db->getRelation("p");
      head_index[13] = readrel28->getIndex(ord27, false);
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4a44dc15364204a80fe80e90;
      u64 v_c1 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_constad57366865126e55649ecb23;
      u64 v_c3 = v_const27badc983df1780b60c2b3fa;
      u64 v_c4 = v_const983bd614bb5afece5ab3b602;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c8 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[14];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
      newbatch[8] = new slog::InsertBatch();
      newbatch[9] = new slog::InsertBatch();
      newbatch[10] = new slog::InsertBatch();
      newbatch[11] = new slog::InsertBatch();
      newbatch[12] = new slog::InsertBatch();
      newbatch[13] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c6}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c0}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[3], head_index[3], newbatch[3], std::array<u64,1>{v_c0}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[4], head_index[4], newbatch[4], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[5], head_index[5], newbatch[5], std::array<u64,1>{v_c1}, std::array<u16,1>{0});
      slog::emit<2>(head_rel[6], head_index[6], newbatch[6], std::array<u64,2>{v_c6, v_c2}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[7], head_index[7], newbatch[7], std::array<u64,2>{v_c5, v_c3}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[8], head_index[8], newbatch[8], std::array<u64,2>{v_c7, v_c4}, std::array<u16,2>{0, 1});
      slog::emit<1>(head_rel[9], head_index[9], newbatch[9], std::array<u64,1>{v_c6}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[10], head_index[10], newbatch[10], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[11], head_index[11], newbatch[11], std::array<u64,1>{v_c6}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[12], head_index[12], newbatch[12], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[13], head_index[13], newbatch[13], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
        head_rel[8]->sendBatch(newbatch[8]);
        head_rel[9]->sendBatch(newbatch[9]);
        head_rel[10]->sendBatch(newbatch[10]);
        head_rel[11]->sendBatch(newbatch[11]);
        head_rel[12]->sendBatch(newbatch[12]);
        head_rel[13]->sendBatch(newbatch[13]);
  
      if (_fires) db->bumpFires("shape_or.slog:30", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  s->addDynamicRel("a");
  s->addDynamicRel("b");
  s->addDynamicRel("c");
  s->addDynamicRel("d");
  s->addDynamicRel("e");
  s->addDynamicRel("f");
  s->addDynamicRel("g");
  s->addDynamicRel("p");
  d->push(s);
  d->continueRun();
}

