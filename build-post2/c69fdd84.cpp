
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_constcea17e0b05e3e6ace77ec2d1;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const76c777b0ce3c35ba97c6cbde;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("c69fdd84");
  if (s == nullptr) return;
  slog::Relation* r;
  v_constcea17e0b05e3e6ace77ec2d1 = db->encodeString("False");
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const76c777b0ce3c35ba97c6cbde = db->encodeString("True");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord124({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord125({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord126({1, 2, 0});
    
    r->addIndex<3>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord127({0, 1, 2});
    
    r->addIndex<3>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord128({1, 2, 0});
    
    r->addIndex<3>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord129({0, 1, 2});
    
    r->addIndex<3>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("outB");
  if (r == 0) db->addRelation("outB", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("outB");
      std::vector<u16> ord130({0});
    
    r->addIndex<1>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("outB"), std::array<u16,1>{0}, b));
  r = db->getRelation("outA");
  if (r == 0) db->addRelation("outA", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("outA");
      std::vector<u16> ord131({0});
    
    r->addIndex<1>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("outA"), std::array<u16,1>{0}, b));
  r = db->getRelation("normB_ans");
  if (r == 0) db->addRelation("normB_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normB_ans");
      std::vector<u16> ord132({0, 1});
    
    r->addIndex<2>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("normB_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("normB");
  if (r == 0) db->addStruct("normB", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normB");
      std::vector<u16> ord133({1, 0});
    
    r->addIndex<2>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord134({0, 1});
    
    r->addIndex<2>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("normB"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("normA_ans");
  if (r == 0) db->addRelation("normA_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normA_ans");
      std::vector<u16> ord135({0, 1});
    
    r->addIndex<2>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("normA_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("normA");
  if (r == 0) db->addStruct("normA", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normA");
      std::vector<u16> ord136({1, 0});
    
    r->addIndex<2>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord137({0, 1});
    
    r->addIndex<2>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("normA"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord138({1, 2, 3, 0});
    
    r->addIndex<4>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord139({0, 1, 2, 3});
    
    r->addIndex<4>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord140({1, 2, 0});
    
    r->addIndex<3>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord141({0, 1, 2});
    
    r->addIndex<3>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord142({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord143({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord144({1, 2, 0});
    
    r->addIndex<3>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord145({0, 1, 2});
    
    r->addIndex<3>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord146({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord147({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord148({1, 2, 3, 0});
    
    r->addIndex<4>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord149({0, 1, 2, 3});
    
    r->addIndex<4>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("fdat");
  if (r == 0) db->addRelation("fdat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fdat");
      std::vector<u16> ord150({0});
    
    r->addIndex<1>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("fdat"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord151({0});
    
    r->addIndex<1>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord152({1, 2, 0});
    
    r->addIndex<3>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord153({0, 1, 2});
    
    r->addIndex<3>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord154({1, 0});
    
    r->addIndex<2>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord155({0, 1});
    
    r->addIndex<2>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord156({1, 0});
    
    r->addIndex<2>(ord156, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("Wrap");
  if (r == 0) db->addStruct("Wrap", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Wrap");
      std::vector<u16> ord157({1, 0});
    
    r->addIndex<2>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord158({0, 1});
    
    r->addIndex<2>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("Wrap"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("DInt");
  if (r == 0) db->addStruct("DInt", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("DInt");
      std::vector<u16> ord159({1, 0});
    
    r->addIndex<2>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord160({0, 1});
    
    r->addIndex<2>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord161({1, 0});
    
    r->addIndex<2>(ord161, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("DInt"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("DBool");
  if (r == 0) db->addStruct("DBool", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("DBool");
      std::vector<u16> ord162({1, 0});
    
    r->addIndex<2>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord163({0, 1});
    
    r->addIndex<2>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("DBool"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup87077x26x0x0x0");
  if (r == 0) db->addRelation("$sup87077x26x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup87077x26x0x0x0");
      std::vector<u16> ord164({0, 1, 2});
    
    r->addIndex<3>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup87077x26x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  // (crule (pre (let __tconst6Tpj86 const76c777b0ce3c35ba97c6cbde)) (probe _enum (1 0) 1 __tconst6Tpj86 __t0vdg30) (body (join DBool (1 0) 1 __t0vdg30 __t0GJI31) (join Wrap (1 0) 1 __t0GJI31 __t4J3o32) (join normB (1 0) 1 __t4J3o32 __t4MR733) (join normB_ans (0 1) 1 __t4MR733 r)) (head (emit outB (0) r)) dem_neq_literal.slog:35 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** DBoolindex0;  slog::Index** Wrapindex1;  slog::Index** normBindex2;  slog::Index** normB_ansindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("outB");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("outB");
      head_index[0] = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("_enum");
      driver_index = readrel8->getIndex(ord7, true);
      std::vector<u16> ord9({1, 0});
      slog::Relation* readrel10 = db->getRelation("DBool");
      DBoolindex0 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({1, 0});
      slog::Relation* readrel12 = db->getRelation("Wrap");
      Wrapindex1 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({1, 0});
      slog::Relation* readrel14 = db->getRelation("normB");
      normBindex2 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("normB_ans");
      normB_ansindex3 = readrel16->getIndex(ord15, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m17) {
        u64 v_c1 = m17[1];
        if (buckethash(v_c1) != bucket) return;
        slog::join_probe<2,1>(DBoolindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m18) {
          u64 v_c2 = m18[1];
          slog::join_probe<2,1>(Wrapindex1, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m19) {
            u64 v_c3 = m19[1];
            slog::join_probe<2,1>(normBindex2, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m20) {
              u64 v_c4 = m20[1];
              slog::join_probe<2,1>(normB_ansindex3, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m21) {
                u64 v_c5 = m21[1];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:35", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask4* _cont = new ReadTask4(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask4(db,b), true);
  // (crule (pre (let __tconst6ZoB81 const76c777b0ce3c35ba97c6cbde)) (probe _enum (1 0) 1 __tconst6ZoB81 __t1EDd26) (body (join DBool (1 0) 1 __t1EDd26 __t9mJP27) (join Wrap (1 0) 1 __t9mJP27 __t66Fo28) (join normA (1 0) 1 __t66Fo28 __t2Mn329) (join normA_ans (0 1) 1 __t2Mn329 r)) (head (emit outA (0) r)) dem_neq_literal.slog:31 #f)
  class ReadTask26 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** DBoolindex22;  slog::Index** Wrapindex23;  slog::Index** normAindex24;  slog::Index** normA_ansindex25;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("outA");
      std::vector<u16> ord27({0});
      slog::Relation* readrel28 = db->getRelation("outA");
      head_index[0] = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 0});
      slog::Relation* readrel30 = db->getRelation("_enum");
      driver_index = readrel30->getIndex(ord29, true);
      std::vector<u16> ord31({1, 0});
      slog::Relation* readrel32 = db->getRelation("DBool");
      DBoolindex22 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("Wrap");
      Wrapindex23 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("normA");
      normAindex24 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("normA_ans");
      normA_ansindex25 = readrel38->getIndex(ord37, false);
  
    }
    ReadTask26(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c6, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m39) {
        u64 v_c7 = m39[1];
        if (buckethash(v_c7) != bucket) return;
        slog::join_probe<2,1>(DBoolindex22, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m40) {
          u64 v_c8 = m40[1];
          slog::join_probe<2,1>(Wrapindex23, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m41) {
            u64 v_c9 = m41[1];
            slog::join_probe<2,1>(normAindex24, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m42) {
              u64 v_c10 = m42[1];
              slog::join_probe<2,1>(normA_ansindex25, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m43) {
                u64 v_c5 = m43[1];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:31", "all:_enum", _fires);
  
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
  // (crule (pre (let __tconst5dNK72 constcea17e0b05e3e6ace77ec2d1)) (probe _enum (1 0) 1 __tconst5dNK72 __t5leX60) (body (join DBool (1 0) 1 __t5leX60 __t81Fc61) (join Wrap (1 0) 1 __t81Fc61 __t05q862) (join normA (1 0) 1 __t05q862 __t3D4S63) (join normA_ans (0 1) 1 __t3D4S63 r)) (head (emit outA (0) r)) dem_neq_literal.slog:33 #f)
  class ReadTask48 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** DBoolindex44;  slog::Index** Wrapindex45;  slog::Index** normAindex46;  slog::Index** normA_ansindex47;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("outA");
      std::vector<u16> ord49({0});
      slog::Relation* readrel50 = db->getRelation("outA");
      head_index[0] = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 0});
      slog::Relation* readrel52 = db->getRelation("_enum");
      driver_index = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({1, 0});
      slog::Relation* readrel54 = db->getRelation("DBool");
      DBoolindex44 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 0});
      slog::Relation* readrel56 = db->getRelation("Wrap");
      Wrapindex45 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 0});
      slog::Relation* readrel58 = db->getRelation("normA");
      normAindex46 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({0, 1});
      slog::Relation* readrel60 = db->getRelation("normA_ans");
      normA_ansindex47 = readrel60->getIndex(ord59, false);
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c11, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m61) {
        u64 v_c12 = m61[1];
        if (buckethash(v_c12) != bucket) return;
        slog::join_probe<2,1>(DBoolindex44, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m62) {
          u64 v_c13 = m62[1];
          slog::join_probe<2,1>(Wrapindex45, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m63) {
            u64 v_c14 = m63[1];
            slog::join_probe<2,1>(normAindex46, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m64) {
              u64 v_c15 = m64[1];
              slog::join_probe<2,1>(normA_ansindex47, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m65) {
                u64 v_c5 = m65[1];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:33", "all:_enum", _fires);
  
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
  // (crule (pre (let __tconst6K4G70 constcea17e0b05e3e6ace77ec2d1)) (probe _enum (1 0) 1 __tconst6K4G70 __t1ffw39) (body (join DBool (1 0) 1 __t1ffw39 __t6JEv40) (join Wrap (1 0) 1 __t6JEv40 __t0ugG41) (join normB (1 0) 1 __t0ugG41 __t69BE42) (join normB_ans (0 1) 1 __t69BE42 r)) (head (emit outB (0) r)) dem_neq_literal.slog:37 #f)
  class ReadTask70 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** DBoolindex66;  slog::Index** Wrapindex67;  slog::Index** normBindex68;  slog::Index** normB_ansindex69;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("outB");
      std::vector<u16> ord71({0});
      slog::Relation* readrel72 = db->getRelation("outB");
      head_index[0] = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 0});
      slog::Relation* readrel74 = db->getRelation("_enum");
      driver_index = readrel74->getIndex(ord73, true);
      std::vector<u16> ord75({1, 0});
      slog::Relation* readrel76 = db->getRelation("DBool");
      DBoolindex66 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 0});
      slog::Relation* readrel78 = db->getRelation("Wrap");
      Wrapindex67 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 0});
      slog::Relation* readrel80 = db->getRelation("normB");
      normBindex68 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({0, 1});
      slog::Relation* readrel82 = db->getRelation("normB_ans");
      normB_ansindex69 = readrel82->getIndex(ord81, false);
  
    }
    ReadTask70(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c16 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c16, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m83) {
        u64 v_c17 = m83[1];
        if (buckethash(v_c17) != bucket) return;
        slog::join_probe<2,1>(DBoolindex66, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m84) {
          u64 v_c18 = m84[1];
          slog::join_probe<2,1>(Wrapindex67, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m85) {
            u64 v_c19 = m85[1];
            slog::join_probe<2,1>(normBindex68, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m86) {
              u64 v_c20 = m86[1];
              slog::join_probe<2,1>(normB_ansindex69, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m87) {
                u64 v_c5 = m87[1];
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:37", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask70* _cont = new ReadTask70(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask70(db,b), true);
  // (crule (pre (let __tconst7thG22 const7902699be42c8a8e46fbbb45)) (probe DInt (1 0) 1 __tconst7thG22 __t5nH523) (body (join Wrap (1 0) 1 __t5nH523 __t3RCG24) (join normA (1 0) 1 __t3RCG24 __t47ch25) (join normA_ans (0 1) 1 __t47ch25 r)) (head (emit outA (0) r)) dem_neq_literal.slog:32 #f)
  class ReadTask91 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** Wrapindex88;  slog::Index** normAindex89;  slog::Index** normA_ansindex90;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("outA");
      std::vector<u16> ord92({0});
      slog::Relation* readrel93 = db->getRelation("outA");
      head_index[0] = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0});
      slog::Relation* readrel95 = db->getRelation("DInt");
      driver_index = readrel95->getIndex(ord94, true);
      std::vector<u16> ord96({1, 0});
      slog::Relation* readrel97 = db->getRelation("Wrap");
      Wrapindex88 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 0});
      slog::Relation* readrel99 = db->getRelation("normA");
      normAindex89 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({0, 1});
      slog::Relation* readrel101 = db->getRelation("normA_ans");
      normA_ansindex90 = readrel101->getIndex(ord100, false);
  
    }
    ReadTask91(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c21 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c21, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m102) {
        u64 v_c22 = m102[1];
        if (buckethash(v_c22) != bucket) return;
        slog::join_probe<2,1>(Wrapindex88, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m103) {
          u64 v_c23 = m103[1];
          slog::join_probe<2,1>(normAindex89, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m104) {
            u64 v_c24 = m104[1];
            slog::join_probe<2,1>(normA_ansindex90, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m105) {
              u64 v_c5 = m105[1];
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:32", "all:DInt", _fires);
  
      if (!_done)
      {
        ReadTask91* _cont = new ReadTask91(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask91(db,b), true);
  // (crule (pre (let __tconst29Ei18 const7902699be42c8a8e46fbbb45)) (probe DInt (1 0) 1 __tconst29Ei18 __t50zR19) (body (join Wrap (1 0) 1 __t50zR19 __t47GT20) (join normB (1 0) 1 __t47GT20 __t7i4W21) (join normB_ans (0 1) 1 __t7i4W21 r)) (head (emit outB (0) r)) dem_neq_literal.slog:36 #f)
  class ReadTask109 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** Wrapindex106;  slog::Index** normBindex107;  slog::Index** normB_ansindex108;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("outB");
      std::vector<u16> ord110({0});
      slog::Relation* readrel111 = db->getRelation("outB");
      head_index[0] = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 0});
      slog::Relation* readrel113 = db->getRelation("DInt");
      driver_index = readrel113->getIndex(ord112, true);
      std::vector<u16> ord114({1, 0});
      slog::Relation* readrel115 = db->getRelation("Wrap");
      Wrapindex106 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 0});
      slog::Relation* readrel117 = db->getRelation("normB");
      normBindex107 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({0, 1});
      slog::Relation* readrel119 = db->getRelation("normB_ans");
      normB_ansindex108 = readrel119->getIndex(ord118, false);
  
    }
    ReadTask109(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c25, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m120) {
        u64 v_c26 = m120[1];
        if (buckethash(v_c26) != bucket) return;
        slog::join_probe<2,1>(Wrapindex106, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m121) {
          u64 v_c27 = m121[1];
          slog::join_probe<2,1>(normBindex107, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m122) {
            u64 v_c28 = m122[1];
            slog::join_probe<2,1>(normB_ansindex108, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m123) {
              u64 v_c5 = m123[1];
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:36", "all:DInt", _fires);
  
      if (!_done)
      {
        ReadTask109* _cont = new ReadTask109(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask109(db,b), true);
  s->addReadRel("DBool");
  s->addReadRel("DInt");
  s->addReadRel("Wrap");
  s->addReadRel("_enum");
  s->addReadRel("normA");
  s->addReadRel("normA_ans");
  s->addReadRel("normB");
  s->addReadRel("normB_ans");
  s->addDynamicRel("outA");
  s->addDynamicRel("outB");
  d->push(s);
  d->continueRun();
}

