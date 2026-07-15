
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const7902699be42c8a8e46fbbb45;

void slog_rules_c69fb02da1bd38644(slog::Database* db, slog::Stratum* s);
void slog_rules_c5b0f4d316c25764e(slog::Database* db, slog::Stratum* s);


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("aa47f68f");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  r = db->getRelation("v_x");
  if (r == 0) db->addRelation("v_x", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("v_x");
      std::vector<u16> ord0({0});
    
    r->addIndex<1>(ord0, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("v_x"), std::array<u16,1>{0}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord1({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord1, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord2({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord2, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord3({1, 2, 0});
    
    r->addIndex<3>(ord3, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord4({0, 1, 2});
    
    r->addIndex<3>(ord4, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord5({1, 2, 0});
    
    r->addIndex<3>(ord5, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord6({0, 1, 2});
    
    r->addIndex<3>(ord6, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord7({1, 2, 3, 0});
    
    r->addIndex<4>(ord7, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord8({0, 1, 2, 3});
    
    r->addIndex<4>(ord8, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord9({1, 2, 0});
    
    r->addIndex<3>(ord9, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord10({0, 1, 2});
    
    r->addIndex<3>(ord10, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord11({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord11, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord12({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord12, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord13({1, 2, 0});
    
    r->addIndex<3>(ord13, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord14({0, 1, 2});
    
    r->addIndex<3>(ord14, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord15({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord15, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord16({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord16, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord17({1, 2, 3, 0});
    
    r->addIndex<4>(ord17, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord18({0, 1, 2, 3});
    
    r->addIndex<4>(ord18, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord19({0});
    
    r->addIndex<1>(ord19, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord20({1, 2, 0});
    
    r->addIndex<3>(ord20, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord21({0, 1, 2});
    
    r->addIndex<3>(ord21, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("a9");
  if (r == 0) db->addRelation("a9", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a9");
      std::vector<u16> ord22({0});
    
    r->addIndex<1>(ord22, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a9"), std::array<u16,1>{0}, b));
  r = db->getRelation("a8");
  if (r == 0) db->addRelation("a8", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a8");
      std::vector<u16> ord23({0});
    
    r->addIndex<1>(ord23, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a8"), std::array<u16,1>{0}, b));
  r = db->getRelation("a7");
  if (r == 0) db->addRelation("a7", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a7");
      std::vector<u16> ord24({0});
    
    r->addIndex<1>(ord24, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a7"), std::array<u16,1>{0}, b));
  r = db->getRelation("a6");
  if (r == 0) db->addRelation("a6", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a6");
      std::vector<u16> ord25({0});
    
    r->addIndex<1>(ord25, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a6"), std::array<u16,1>{0}, b));
  r = db->getRelation("a50");
  if (r == 0) db->addRelation("a50", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a50");
      std::vector<u16> ord26({0});
    
    r->addIndex<1>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a50"), std::array<u16,1>{0}, b));
  r = db->getRelation("a5");
  if (r == 0) db->addRelation("a5", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a5");
      std::vector<u16> ord27({0});
    
    r->addIndex<1>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a5"), std::array<u16,1>{0}, b));
  r = db->getRelation("a49");
  if (r == 0) db->addRelation("a49", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a49");
      std::vector<u16> ord28({0});
    
    r->addIndex<1>(ord28, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a49"), std::array<u16,1>{0}, b));
  r = db->getRelation("a48");
  if (r == 0) db->addRelation("a48", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a48");
      std::vector<u16> ord29({0});
    
    r->addIndex<1>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a48"), std::array<u16,1>{0}, b));
  r = db->getRelation("a47");
  if (r == 0) db->addRelation("a47", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a47");
      std::vector<u16> ord30({0});
    
    r->addIndex<1>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a47"), std::array<u16,1>{0}, b));
  r = db->getRelation("a46");
  if (r == 0) db->addRelation("a46", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a46");
      std::vector<u16> ord31({0});
    
    r->addIndex<1>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a46"), std::array<u16,1>{0}, b));
  r = db->getRelation("a45");
  if (r == 0) db->addRelation("a45", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a45");
      std::vector<u16> ord32({0});
    
    r->addIndex<1>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a45"), std::array<u16,1>{0}, b));
  r = db->getRelation("a44");
  if (r == 0) db->addRelation("a44", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a44");
      std::vector<u16> ord33({0});
    
    r->addIndex<1>(ord33, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a44"), std::array<u16,1>{0}, b));
  r = db->getRelation("a43");
  if (r == 0) db->addRelation("a43", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a43");
      std::vector<u16> ord34({0});
    
    r->addIndex<1>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a43"), std::array<u16,1>{0}, b));
  r = db->getRelation("a42");
  if (r == 0) db->addRelation("a42", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a42");
      std::vector<u16> ord35({0});
    
    r->addIndex<1>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a42"), std::array<u16,1>{0}, b));
  r = db->getRelation("a41");
  if (r == 0) db->addRelation("a41", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a41");
      std::vector<u16> ord36({0});
    
    r->addIndex<1>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a41"), std::array<u16,1>{0}, b));
  r = db->getRelation("a40");
  if (r == 0) db->addRelation("a40", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a40");
      std::vector<u16> ord37({0});
    
    r->addIndex<1>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a40"), std::array<u16,1>{0}, b));
  r = db->getRelation("a4");
  if (r == 0) db->addRelation("a4", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a4");
      std::vector<u16> ord38({0});
    
    r->addIndex<1>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a4"), std::array<u16,1>{0}, b));
  r = db->getRelation("a39");
  if (r == 0) db->addRelation("a39", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a39");
      std::vector<u16> ord39({0});
    
    r->addIndex<1>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a39"), std::array<u16,1>{0}, b));
  r = db->getRelation("a38");
  if (r == 0) db->addRelation("a38", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a38");
      std::vector<u16> ord40({0});
    
    r->addIndex<1>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a38"), std::array<u16,1>{0}, b));
  r = db->getRelation("a37");
  if (r == 0) db->addRelation("a37", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a37");
      std::vector<u16> ord41({0});
    
    r->addIndex<1>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a37"), std::array<u16,1>{0}, b));
  r = db->getRelation("a36");
  if (r == 0) db->addRelation("a36", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a36");
      std::vector<u16> ord42({0});
    
    r->addIndex<1>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a36"), std::array<u16,1>{0}, b));
  r = db->getRelation("a35");
  if (r == 0) db->addRelation("a35", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a35");
      std::vector<u16> ord43({0});
    
    r->addIndex<1>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a35"), std::array<u16,1>{0}, b));
  r = db->getRelation("a34");
  if (r == 0) db->addRelation("a34", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a34");
      std::vector<u16> ord44({0});
    
    r->addIndex<1>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a34"), std::array<u16,1>{0}, b));
  r = db->getRelation("a33");
  if (r == 0) db->addRelation("a33", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a33");
      std::vector<u16> ord45({0});
    
    r->addIndex<1>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a33"), std::array<u16,1>{0}, b));
  r = db->getRelation("a32");
  if (r == 0) db->addRelation("a32", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a32");
      std::vector<u16> ord46({0});
    
    r->addIndex<1>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a32"), std::array<u16,1>{0}, b));
  r = db->getRelation("a31");
  if (r == 0) db->addRelation("a31", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a31");
      std::vector<u16> ord47({0});
    
    r->addIndex<1>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a31"), std::array<u16,1>{0}, b));
  r = db->getRelation("a30");
  if (r == 0) db->addRelation("a30", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a30");
      std::vector<u16> ord48({0});
    
    r->addIndex<1>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a30"), std::array<u16,1>{0}, b));
  r = db->getRelation("a3");
  if (r == 0) db->addRelation("a3", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a3");
      std::vector<u16> ord49({0});
    
    r->addIndex<1>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a3"), std::array<u16,1>{0}, b));
  r = db->getRelation("a29");
  if (r == 0) db->addRelation("a29", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a29");
      std::vector<u16> ord50({0});
    
    r->addIndex<1>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a29"), std::array<u16,1>{0}, b));
  r = db->getRelation("a28");
  if (r == 0) db->addRelation("a28", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a28");
      std::vector<u16> ord51({0});
    
    r->addIndex<1>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a28"), std::array<u16,1>{0}, b));
  r = db->getRelation("a27");
  if (r == 0) db->addRelation("a27", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a27");
      std::vector<u16> ord52({0});
    
    r->addIndex<1>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a27"), std::array<u16,1>{0}, b));
  r = db->getRelation("a26");
  if (r == 0) db->addRelation("a26", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a26");
      std::vector<u16> ord53({0});
    
    r->addIndex<1>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a26"), std::array<u16,1>{0}, b));
  r = db->getRelation("a25");
  if (r == 0) db->addRelation("a25", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a25");
      std::vector<u16> ord54({0});
    
    r->addIndex<1>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a25"), std::array<u16,1>{0}, b));
  r = db->getRelation("a24");
  if (r == 0) db->addRelation("a24", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a24");
      std::vector<u16> ord55({0});
    
    r->addIndex<1>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a24"), std::array<u16,1>{0}, b));
  r = db->getRelation("a23");
  if (r == 0) db->addRelation("a23", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a23");
      std::vector<u16> ord56({0});
    
    r->addIndex<1>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a23"), std::array<u16,1>{0}, b));
  r = db->getRelation("a22");
  if (r == 0) db->addRelation("a22", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a22");
      std::vector<u16> ord57({0});
    
    r->addIndex<1>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a22"), std::array<u16,1>{0}, b));
  r = db->getRelation("a21");
  if (r == 0) db->addRelation("a21", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a21");
      std::vector<u16> ord58({0});
    
    r->addIndex<1>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a21"), std::array<u16,1>{0}, b));
  r = db->getRelation("a20");
  if (r == 0) db->addRelation("a20", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a20");
      std::vector<u16> ord59({0});
    
    r->addIndex<1>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a20"), std::array<u16,1>{0}, b));
  r = db->getRelation("a2");
  if (r == 0) db->addRelation("a2", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a2");
      std::vector<u16> ord60({0});
    
    r->addIndex<1>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a2"), std::array<u16,1>{0}, b));
  r = db->getRelation("a19");
  if (r == 0) db->addRelation("a19", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a19");
      std::vector<u16> ord61({0});
    
    r->addIndex<1>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a19"), std::array<u16,1>{0}, b));
  r = db->getRelation("a18");
  if (r == 0) db->addRelation("a18", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a18");
      std::vector<u16> ord62({0});
    
    r->addIndex<1>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a18"), std::array<u16,1>{0}, b));
  r = db->getRelation("a17");
  if (r == 0) db->addRelation("a17", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a17");
      std::vector<u16> ord63({0});
    
    r->addIndex<1>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a17"), std::array<u16,1>{0}, b));
  r = db->getRelation("a16");
  if (r == 0) db->addRelation("a16", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a16");
      std::vector<u16> ord64({0});
    
    r->addIndex<1>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a16"), std::array<u16,1>{0}, b));
  r = db->getRelation("a15");
  if (r == 0) db->addRelation("a15", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a15");
      std::vector<u16> ord65({0});
    
    r->addIndex<1>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a15"), std::array<u16,1>{0}, b));
  r = db->getRelation("a14");
  if (r == 0) db->addRelation("a14", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a14");
      std::vector<u16> ord66({0});
    
    r->addIndex<1>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a14"), std::array<u16,1>{0}, b));
  r = db->getRelation("a13");
  if (r == 0) db->addRelation("a13", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a13");
      std::vector<u16> ord67({0});
    
    r->addIndex<1>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a13"), std::array<u16,1>{0}, b));
  r = db->getRelation("a12");
  if (r == 0) db->addRelation("a12", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a12");
      std::vector<u16> ord68({0});
    
    r->addIndex<1>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a12"), std::array<u16,1>{0}, b));
  r = db->getRelation("a11");
  if (r == 0) db->addRelation("a11", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a11");
      std::vector<u16> ord69({0});
    
    r->addIndex<1>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a11"), std::array<u16,1>{0}, b));
  r = db->getRelation("a10");
  if (r == 0) db->addRelation("a10", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a10");
      std::vector<u16> ord70({0});
    
    r->addIndex<1>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a10"), std::array<u16,1>{0}, b));
  r = db->getRelation("a1");
  if (r == 0) db->addRelation("a1", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a1");
      std::vector<u16> ord71({0});
    
    r->addIndex<1>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a1"), std::array<u16,1>{0}, b));
  r = db->getRelation("a0");
  if (r == 0) db->addRelation("a0", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("a0");
      std::vector<u16> ord72({0});
    
    r->addIndex<1>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("a0"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord73({1, 0});
    
    r->addIndex<2>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord74({0, 1});
    
    r->addIndex<2>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  slog_rules_c69fb02da1bd38644(db, s);
  slog_rules_c5b0f4d316c25764e(db, s);
  s->addReadRel("a0");
  s->addReadRel("a1");
  s->addReadRel("a10");
  s->addReadRel("a11");
  s->addReadRel("a12");
  s->addReadRel("a13");
  s->addReadRel("a14");
  s->addReadRel("a15");
  s->addReadRel("a16");
  s->addReadRel("a17");
  s->addReadRel("a18");
  s->addReadRel("a19");
  s->addReadRel("a2");
  s->addReadRel("a20");
  s->addReadRel("a21");
  s->addReadRel("a22");
  s->addReadRel("a23");
  s->addReadRel("a24");
  s->addReadRel("a25");
  s->addReadRel("a26");
  s->addReadRel("a27");
  s->addReadRel("a28");
  s->addReadRel("a29");
  s->addReadRel("a3");
  s->addReadRel("a30");
  s->addReadRel("a31");
  s->addReadRel("a32");
  s->addReadRel("a33");
  s->addReadRel("a34");
  s->addReadRel("a35");
  s->addReadRel("a36");
  s->addReadRel("a37");
  s->addReadRel("a38");
  s->addReadRel("a39");
  s->addReadRel("a4");
  s->addReadRel("a40");
  s->addReadRel("a41");
  s->addReadRel("a42");
  s->addReadRel("a43");
  s->addReadRel("a44");
  s->addReadRel("a45");
  s->addReadRel("a46");
  s->addReadRel("a47");
  s->addReadRel("a48");
  s->addReadRel("a49");
  s->addReadRel("a5");
  s->addReadRel("a50");
  s->addReadRel("a6");
  s->addReadRel("a7");
  s->addReadRel("a8");
  s->addReadRel("a9");
  s->addReadRel("v_x");
  s->addDynamicRel("a0");
  s->addDynamicRel("a1");
  s->addDynamicRel("a10");
  s->addDynamicRel("a11");
  s->addDynamicRel("a12");
  s->addDynamicRel("a13");
  s->addDynamicRel("a14");
  s->addDynamicRel("a15");
  s->addDynamicRel("a16");
  s->addDynamicRel("a17");
  s->addDynamicRel("a18");
  s->addDynamicRel("a19");
  s->addDynamicRel("a2");
  s->addDynamicRel("a20");
  s->addDynamicRel("a21");
  s->addDynamicRel("a22");
  s->addDynamicRel("a23");
  s->addDynamicRel("a24");
  s->addDynamicRel("a25");
  s->addDynamicRel("a26");
  s->addDynamicRel("a27");
  s->addDynamicRel("a28");
  s->addDynamicRel("a29");
  s->addDynamicRel("a3");
  s->addDynamicRel("a30");
  s->addDynamicRel("a31");
  s->addDynamicRel("a32");
  s->addDynamicRel("a33");
  s->addDynamicRel("a34");
  s->addDynamicRel("a35");
  s->addDynamicRel("a36");
  s->addDynamicRel("a37");
  s->addDynamicRel("a38");
  s->addDynamicRel("a39");
  s->addDynamicRel("a4");
  s->addDynamicRel("a40");
  s->addDynamicRel("a41");
  s->addDynamicRel("a42");
  s->addDynamicRel("a43");
  s->addDynamicRel("a44");
  s->addDynamicRel("a45");
  s->addDynamicRel("a46");
  s->addDynamicRel("a47");
  s->addDynamicRel("a48");
  s->addDynamicRel("a49");
  s->addDynamicRel("a5");
  s->addDynamicRel("a50");
  s->addDynamicRel("a6");
  s->addDynamicRel("a7");
  s->addDynamicRel("a8");
  s->addDynamicRel("a9");
  s->addDynamicRel("v_x");
  s->addAccelRel("a0");
  s->addAccelRel("a1");
  s->addAccelRel("a10");
  s->addAccelRel("a11");
  s->addAccelRel("a12");
  s->addAccelRel("a13");
  s->addAccelRel("a14");
  s->addAccelRel("a15");
  s->addAccelRel("a16");
  s->addAccelRel("a17");
  s->addAccelRel("a18");
  s->addAccelRel("a19");
  s->addAccelRel("a2");
  s->addAccelRel("a20");
  s->addAccelRel("a21");
  s->addAccelRel("a22");
  s->addAccelRel("a23");
  s->addAccelRel("a24");
  s->addAccelRel("a25");
  s->addAccelRel("a26");
  s->addAccelRel("a27");
  s->addAccelRel("a28");
  s->addAccelRel("a29");
  s->addAccelRel("a3");
  s->addAccelRel("a30");
  s->addAccelRel("a31");
  s->addAccelRel("a32");
  s->addAccelRel("a33");
  s->addAccelRel("a34");
  s->addAccelRel("a35");
  s->addAccelRel("a36");
  s->addAccelRel("a37");
  s->addAccelRel("a38");
  s->addAccelRel("a39");
  s->addAccelRel("a4");
  s->addAccelRel("a40");
  s->addAccelRel("a41");
  s->addAccelRel("a42");
  s->addAccelRel("a43");
  s->addAccelRel("a44");
  s->addAccelRel("a45");
  s->addAccelRel("a46");
  s->addAccelRel("a47");
  s->addAccelRel("a48");
  s->addAccelRel("a49");
  s->addAccelRel("a5");
  s->addAccelRel("a50");
  s->addAccelRel("a6");
  s->addAccelRel("a7");
  s->addAccelRel("a8");
  s->addAccelRel("a9");
  s->addAccelRel("v_x");
  d->push(s);
  d->continueRun();
}

