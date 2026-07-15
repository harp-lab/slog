
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const1bbd189cbe7b0e1338ec0ae5;
u64 v_const3f91f2c205f6fee203b3a41a;
u64 v_constcea17e0b05e3e6ace77ec2d1;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const76c777b0ce3c35ba97c6cbde;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("83530787");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const1bbd189cbe7b0e1338ec0ae5 = db->encodeString("dem_neq_literal.slog:27");
  v_const3f91f2c205f6fee203b3a41a = db->encodeString("normB");
  v_constcea17e0b05e3e6ace77ec2d1 = db->encodeString("False");
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const76c777b0ce3c35ba97c6cbde = db->encodeString("True");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord314({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord314, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord315({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord315, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord316({1, 2, 0});
    
    r->addIndex<3>(ord316, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord317({0, 1, 2});
    
    r->addIndex<3>(ord317, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord318({1, 2, 0});
    
    r->addIndex<3>(ord318, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord319({0, 1, 2});
    
    r->addIndex<3>(ord319, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("outB");
  if (r == 0) db->addRelation("outB", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("outB");
      std::vector<u16> ord320({0});
    
    r->addIndex<1>(ord320, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("outB"), std::array<u16,1>{0}, b));
  r = db->getRelation("outA");
  if (r == 0) db->addRelation("outA", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("outA");
      std::vector<u16> ord321({0});
    
    r->addIndex<1>(ord321, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("outA"), std::array<u16,1>{0}, b));
  r = db->getRelation("normB_ans");
  if (r == 0) db->addRelation("normB_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normB_ans");
      std::vector<u16> ord322({0, 1});
    
    r->addIndex<2>(ord322, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("normB_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("normB");
  if (r == 0) db->addStruct("normB", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normB");
      std::vector<u16> ord323({1, 0});
    
    r->addIndex<2>(ord323, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord324({0, 1});
    
    r->addIndex<2>(ord324, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord325({1, 0});
    
    r->addIndex<2>(ord325, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("normB"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("normA_ans");
  if (r == 0) db->addRelation("normA_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normA_ans");
      std::vector<u16> ord326({0, 1});
    
    r->addIndex<2>(ord326, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("normA_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("normA");
  if (r == 0) db->addStruct("normA", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normA");
      std::vector<u16> ord327({1, 0});
    
    r->addIndex<2>(ord327, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord328({0, 1});
    
    r->addIndex<2>(ord328, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord329({1, 0});
    
    r->addIndex<2>(ord329, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("normA"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord330({1, 2, 3, 0});
    
    r->addIndex<4>(ord330, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord331({0, 1, 2, 3});
    
    r->addIndex<4>(ord331, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord332({1, 2, 0});
    
    r->addIndex<3>(ord332, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord333({0, 1, 2});
    
    r->addIndex<3>(ord333, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord334({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord334, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord335({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord335, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord336({1, 2, 0});
    
    r->addIndex<3>(ord336, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord337({0, 1, 2});
    
    r->addIndex<3>(ord337, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord338({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord338, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord339({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord339, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord340({1, 2, 3, 0});
    
    r->addIndex<4>(ord340, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord341({0, 1, 2, 3});
    
    r->addIndex<4>(ord341, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("fdat");
  if (r == 0) db->addRelation("fdat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fdat");
      std::vector<u16> ord342({0});
    
    r->addIndex<1>(ord342, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("fdat"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord343({0});
    
    r->addIndex<1>(ord343, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord344({1, 2, 0});
    
    r->addIndex<3>(ord344, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord345({0, 1, 2});
    
    r->addIndex<3>(ord345, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord346({1, 0});
    
    r->addIndex<2>(ord346, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord347({0, 1});
    
    r->addIndex<2>(ord347, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord348({1, 0});
    
    r->addIndex<2>(ord348, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("Wrap");
  if (r == 0) db->addStruct("Wrap", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Wrap");
      std::vector<u16> ord349({1, 0});
    
    r->addIndex<2>(ord349, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord350({0, 1});
    
    r->addIndex<2>(ord350, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord351({0, 1});
    
    r->addIndex<2>(ord351, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("Wrap"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("DInt");
  if (r == 0) db->addStruct("DInt", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("DInt");
      std::vector<u16> ord352({1, 0});
    
    r->addIndex<2>(ord352, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord353({0, 1});
    
    r->addIndex<2>(ord353, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord354({1, 0});
    
    r->addIndex<2>(ord354, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("DInt"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("DBool");
  if (r == 0) db->addStruct("DBool", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("DBool");
      std::vector<u16> ord355({1, 0});
    
    r->addIndex<2>(ord355, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord356({0, 1});
    
    r->addIndex<2>(ord356, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("DBool"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup87077x26x0x0x0");
  if (r == 0) db->addRelation("$sup87077x26x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup87077x26x0x0x0");
      std::vector<u16> ord357({0, 1, 2});
    
    r->addIndex<3>(ord357, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup87077x26x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  // (crule (pre (let __tconst0JFG64 const7902699be42c8a8e46fbbb45)) (probe DInt (1 0) 1 __tconst0JFG64 __t9DSZ65) (body) (head (mkstruct Wrap (1 0) __t6HIa66 __t9DSZ65)) dem_neq_literal.slog:36 #f)
  class ReadTask0 : public slog::Task
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
      head_rel[0] = db->getRelation("Wrap");
      std::vector<u16> ord1({1, 0});
      slog::Relation* readrel2 = db->getRelation("DInt");
      driver_index = readrel2->getIndex(ord1, true);
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m3) {
        u64 v_c1 = m3[1];
        if (buckethash(v_c1) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:36", "delta:DInt", _fires);
  
      if (!_done)
      {
        ReadTask0* _cont = new ReadTask0(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), false);
  // (crule (pre (let __tconst5u1S74 const76c777b0ce3c35ba97c6cbde)) (seeded) (body (join _enum (1 0) 1 __tconst5u1S74 __t7h7g43) (join DBool (1 0) 1 __t7h7g43 __t2BbG44)) (head (mkstruct Wrap (1 0) __t2uix45 __t2BbG44)) dem_neq_literal.slog:31 #f)
  class ReadTask6 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex4;  slog::Index** DBoolindex5;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Wrap");
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("Wrap");
      head_index[0] = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({1, 0});
      slog::Relation* readrel10 = db->getRelation("_enum");
      _enumindex4 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({1, 0});
      slog::Relation* readrel12 = db->getRelation("DBool");
      DBoolindex5 = readrel12->getIndex(ord11, false);
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex4, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m13) {
        u64 v_c3 = m13[1];
        slog::join_probe<2,1>(DBoolindex5, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m14) {
          u64 v_c4 = m14[1];
          ++_fires;
          slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:31", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask6(db,b));
  // (crule (pre) (scan normA __t9cYb53 __t5VM452) (body (join Wrap (0 1) 1 __t5VM452 d)) (head (mkstruct normA (1 0) __3BGD87 d)) dem_neq_literal.slog:18 #f)
  class ReadTask16 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Wrapindex15;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA");
      outer_rel = db->getRelation("normA");
      std::vector<u16> ord17({0, 1});
      slog::Relation* readrel18 = db->getRelation("Wrap");
      Wrapindex15 = readrel18->getIndex(ord17, false);
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        slog::join_probe<2,1>(Wrapindex15, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m19) {
          u64 v_c7 = m19[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:18", "delta:normA", _fires);
  
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
  // (crule (pre) (scan malformed_deduction __erre9Tsw99 __errf62Lu100 __errf1Brz101 __errf1MxQ102 __errf3d1O103) (body) (head (emit error (0) __erre9Tsw99)) <internal>:1 #f)
  class ReadTask20 : public slog::Task
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
      std::vector<u16> ord21({0});
      slog::Relation* readrel22 = db->getRelation("error");
      head_index[0] = readrel22->getIndex(ord21, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c12 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask20* _cont = new ReadTask20(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask20(db,b), false);
  // (crule (pre (let __tconst0HhO89 constcea17e0b05e3e6ace77ec2d1)) (probe _enum (1 0) 1 __tconst0HhO89 __t5qfH46) (body) (head (mkstruct DBool (1 0) __t8cRC47 __t5qfH46)) dem_neq_literal.slog:37 #f)
  class ReadTask23 : public slog::Task
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
      head_rel[0] = db->getRelation("DBool");
      std::vector<u16> ord24({1, 0});
      slog::Relation* readrel25 = db->getRelation("_enum");
      driver_index = readrel25->getIndex(ord24, true);
  
    }
    ReadTask23(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c13, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m26) {
        u64 v_c14 = m26[1];
        if (buckethash(v_c14) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:37", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask23* _cont = new ReadTask23(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask23(db,b), true);
  // (crule (pre (let __tconst8g2w80 const76c777b0ce3c35ba97c6cbde)) (probe _enum (1 0) 1 __tconst8g2w80 __t5slS7) (body) (head (mkstruct DBool (1 0) __t10ZZ8 __t5slS7)) dem_neq_literal.slog:35 #f)
  class ReadTask27 : public slog::Task
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
      head_rel[0] = db->getRelation("DBool");
      std::vector<u16> ord28({1, 0});
      slog::Relation* readrel29 = db->getRelation("_enum");
      driver_index = readrel29->getIndex(ord28, true);
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c15, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m30) {
        u64 v_c16 = m30[1];
        if (buckethash(v_c16) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:35", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask27* _cont = new ReadTask27(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask27(db,b), true);
  // (crule (pre (let __tconst9T9W15 const7902699be42c8a8e46fbbb45)) (seeded) (body (join DInt (1 0) 1 __tconst9T9W15 __t91BP16) (join Wrap (1 0) 1 __t91BP16 __t8WhE17)) (head (mkstruct normA (1 0) __8bNW69 __t8WhE17)) dem_neq_literal.slog:32 #f)
  class ReadTask33 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** DIntindex31;  slog::Index** Wrapindex32;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA");
      std::vector<u16> ord34({1, 0});
      slog::Relation* readrel35 = db->getRelation("normA");
      head_index[0] = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 0});
      slog::Relation* readrel37 = db->getRelation("DInt");
      DIntindex31 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 0});
      slog::Relation* readrel39 = db->getRelation("Wrap");
      Wrapindex32 = readrel39->getIndex(ord38, false);
  
    }
    ReadTask33(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(DIntindex31, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m40) {
        u64 v_c18 = m40[1];
        slog::join_probe<2,1>(Wrapindex32, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m41) {
          u64 v_c19 = m41[1];
          ++_fires;
          slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:32", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask33(db,b));
  // (crule (pre (let __tconst8g2w80 const76c777b0ce3c35ba97c6cbde)) (seeded) (body (join _enum (1 0) 1 __tconst8g2w80 __t5slS7) (join DBool (1 0) 1 __t5slS7 __t10ZZ8)) (head (mkstruct Wrap (1 0) __t7iDF9 __t10ZZ8)) dem_neq_literal.slog:35 #f)
  class ReadTask44 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex42;  slog::Index** DBoolindex43;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Wrap");
      std::vector<u16> ord45({1, 0});
      slog::Relation* readrel46 = db->getRelation("Wrap");
      head_index[0] = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 0});
      slog::Relation* readrel48 = db->getRelation("_enum");
      _enumindex42 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 0});
      slog::Relation* readrel50 = db->getRelation("DBool");
      DBoolindex43 = readrel50->getIndex(ord49, false);
  
    }
    ReadTask44(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex42, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m51) {
        u64 v_c16 = m51[1];
        slog::join_probe<2,1>(DBoolindex43, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m52) {
          u64 v_c20 = m52[1];
          ++_fires;
          slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:35", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask44(db,b));
  // (crule (pre (let __tconst8g2w80 const76c777b0ce3c35ba97c6cbde)) (scan DBool __t10ZZ8 __t5slS7) (body (join _enum (0 1) 2 __t5slS7 __tconst8g2w80)) (head (mkstruct Wrap (1 0) __t7iDF9 __t10ZZ8)) dem_neq_literal.slog:35 #f)
  class ReadTask54 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex53;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Wrap");
      outer_rel = db->getRelation("DBool");
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("_enum");
      _enumindex53 = readrel56->getIndex(ord55, false);
  
    }
    ReadTask54(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        u64 v_c16 = _t[1];
        slog::join_probe<2,2>(_enumindex53, std::array<u64,2>{v_c16, v_c15}, [&](const std::array<u64,2>& m57) {
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:35", "delta:DBool", _fires);
  
      if (!_done)
      {
        ReadTask54* _cont = new ReadTask54(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask54(db,b), false);
  // (crule (pre (let __tconst0HhO89 constcea17e0b05e3e6ace77ec2d1)) (seeded) (body (join _enum (1 0) 1 __tconst0HhO89 __t5qfH46) (join DBool (1 0) 1 __t5qfH46 __t8cRC47) (join Wrap (1 0) 1 __t8cRC47 __t3vMC48)) (head (mkstruct normB (1 0) __9qpr88 __t3vMC48)) dem_neq_literal.slog:37 #f)
  class ReadTask61 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex58;  slog::Index** DBoolindex59;  slog::Index** Wrapindex60;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normB");
      std::vector<u16> ord62({1, 0});
      slog::Relation* readrel63 = db->getRelation("normB");
      head_index[0] = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 0});
      slog::Relation* readrel65 = db->getRelation("_enum");
      _enumindex58 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 0});
      slog::Relation* readrel67 = db->getRelation("DBool");
      DBoolindex59 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 0});
      slog::Relation* readrel69 = db->getRelation("Wrap");
      Wrapindex60 = readrel69->getIndex(ord68, false);
  
    }
    ReadTask61(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex58, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m70) {
        u64 v_c14 = m70[1];
        slog::join_probe<2,1>(DBoolindex59, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m71) {
          u64 v_c21 = m71[1];
          slog::join_probe<2,1>(Wrapindex60, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m72) {
            u64 v_c22 = m72[1];
            ++_fires;
            slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:37", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask61(db,b));
  // (crule (pre (let __tconst4Tmq78 constcea17e0b05e3e6ace77ec2d1)) (probe _enum (1 0) 1 __tconst4Tmq78 __t3TAP4) (body) (head (mkstruct DBool (1 0) __t6cJv5 __t3TAP4)) dem_neq_literal.slog:33 #f)
  class ReadTask73 : public slog::Task
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
      head_rel[0] = db->getRelation("DBool");
      std::vector<u16> ord74({1, 0});
      slog::Relation* readrel75 = db->getRelation("_enum");
      driver_index = readrel75->getIndex(ord74, true);
  
    }
    ReadTask73(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c23, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m76) {
        u64 v_c24 = m76[1];
        if (buckethash(v_c24) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:33", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask73* _cont = new ReadTask73(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask73(db,b), true);
  // (crule (pre (let __tconst4Tmq78 constcea17e0b05e3e6ace77ec2d1)) (scan Wrap __t8hcw6 __t6cJv5) (body (exists _enum (1 0) 1 __tconst4Tmq78) (join DBool (0 1) 1 __t6cJv5 __t3TAP4) (join _enum (0 1) 2 __t3TAP4 __tconst4Tmq78)) (head (mkstruct normA (1 0) __1dfE77 __t8hcw6)) dem_neq_literal.slog:33 #f)
  class ReadTask80 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex77;  slog::Index** DBoolindex78;  slog::Index** _enumindex79;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA");
      outer_rel = db->getRelation("Wrap");
      std::vector<u16> ord81({1, 0});
      slog::Relation* readrel82 = db->getRelation("_enum");
      _enumindex77 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({0, 1});
      slog::Relation* readrel84 = db->getRelation("DBool");
      DBoolindex78 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 1});
      slog::Relation* readrel86 = db->getRelation("_enum");
      _enumindex79 = readrel86->getIndex(ord85, false);
  
    }
    ReadTask80(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c25 = _t[0];
        u64 v_c26 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex77, std::array<u64,2>{v_c23, 0})) return;
        slog::join_probe<2,1>(DBoolindex78, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m87) {
          u64 v_c24 = m87[1];
          slog::join_probe<2,2>(_enumindex79, std::array<u64,2>{v_c24, v_c23}, [&](const std::array<u64,2>& m88) {
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:33", "delta:Wrap", _fires);
  
      if (!_done)
      {
        ReadTask80* _cont = new ReadTask80(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask80(db,b), false);
  // (crule (pre (let __tconst5u1S74 const76c777b0ce3c35ba97c6cbde)) (scan DBool __t2BbG44 __t7h7g43) (body (join _enum (0 1) 2 __t7h7g43 __tconst5u1S74)) (head (mkstruct Wrap (1 0) __t2uix45 __t2BbG44)) dem_neq_literal.slog:31 #f)
  class ReadTask90 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex89;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Wrap");
      outer_rel = db->getRelation("DBool");
      std::vector<u16> ord91({0, 1});
      slog::Relation* readrel92 = db->getRelation("_enum");
      _enumindex89 = readrel92->getIndex(ord91, false);
  
    }
    ReadTask90(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const76c777b0ce3c35ba97c6cbde;
  
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
        slog::join_probe<2,2>(_enumindex89, std::array<u64,2>{v_c3, v_c2}, [&](const std::array<u64,2>& m93) {
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:31", "delta:DBool", _fires);
  
      if (!_done)
      {
        ReadTask90* _cont = new ReadTask90(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask90(db,b), false);
  // (crule (pre (let __tconst8ksF71 constcea17e0b05e3e6ace77ec2d1)) (probe _enum (1 0) 1 __tconst8ksF71 __t6ajx67) (body) (head (mkstruct DBool (1 0) __t4O0o68 __t6ajx67)) dem_neq_literal.slog:23 #f)
  class ReadTask94 : public slog::Task
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
      head_rel[0] = db->getRelation("DBool");
      std::vector<u16> ord95({1, 0});
      slog::Relation* readrel96 = db->getRelation("_enum");
      driver_index = readrel96->getIndex(ord95, true);
  
    }
    ReadTask94(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c27, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m97) {
        u64 v_c28 = m97[1];
        if (buckethash(v_c28) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c28}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:23", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask94* _cont = new ReadTask94(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask94(db,b), true);
  // (crule (pre (let __tconst8ksF71 constcea17e0b05e3e6ace77ec2d1)) (seeded) (body (join _enum (1 0) 1 __tconst8ksF71 __t6ajx67) (join DBool (1 0) 1 __t6ajx67 __t4O0o68)) (head (emit fdat (0) __t4O0o68)) dem_neq_literal.slog:23 #f)
  class ReadTask100 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex98;  slog::Index** DBoolindex99;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("fdat");
      std::vector<u16> ord101({0});
      slog::Relation* readrel102 = db->getRelation("fdat");
      head_index[0] = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 0});
      slog::Relation* readrel104 = db->getRelation("_enum");
      _enumindex98 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 0});
      slog::Relation* readrel106 = db->getRelation("DBool");
      DBoolindex99 = readrel106->getIndex(ord105, false);
  
    }
    ReadTask100(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex98, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m107) {
        u64 v_c28 = m107[1];
        slog::join_probe<2,1>(DBoolindex99, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m108) {
          u64 v_c29 = m108[1];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c29}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:23", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask100(db,b));
  // (crule (pre) (scan normB __t44h138 __t3lfE37) (body (join Wrap (0 1) 1 __t3lfE37 d) (join fdat (0) 0 fd)) (head (emit $sup87077x26x0x0x0 (0 1 2) __t44h138 d fd)) dem_neq_literal.slog:27 #f)
  class ReadTask111 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Wrapindex109;  slog::Index** fdatindex110;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup87077x26x0x0x0");
      std::vector<u16> ord112({0, 1, 2});
      slog::Relation* readrel113 = db->getRelation("$sup87077x26x0x0x0");
      head_index[0] = readrel113->getIndex(ord112, false);
      outer_rel = db->getRelation("normB");
      std::vector<u16> ord114({0, 1});
      slog::Relation* readrel115 = db->getRelation("Wrap");
      Wrapindex109 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({0});
      slog::Relation* readrel117 = db->getRelation("fdat");
      fdatindex110 = readrel117->getIndex(ord116, false);
  
    }
    ReadTask111(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(Wrapindex109, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m118) {
          u64 v_c7 = m118[1];
          slog::join_all<1>(fdatindex110, [&](const std::array<u64,1>& m119) {
            u64 v_c32 = m119[0];
            ++_fires;
            slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c30, v_c7, v_c32}, std::array<u16,3>{0, 1, 2});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:27", "delta:normB", _fires);
  
      if (!_done)
      {
        ReadTask111* _cont = new ReadTask111(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask111(db,b), false);
  // (crule (pre (let __tconst8ksF71 constcea17e0b05e3e6ace77ec2d1)) (scan DBool __t4O0o68 __t6ajx67) (body (join _enum (0 1) 2 __t6ajx67 __tconst8ksF71)) (head (emit fdat (0) __t4O0o68)) dem_neq_literal.slog:23 #f)
  class ReadTask121 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex120;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("fdat");
      std::vector<u16> ord122({0});
      slog::Relation* readrel123 = db->getRelation("fdat");
      head_index[0] = readrel123->getIndex(ord122, false);
      outer_rel = db->getRelation("DBool");
      std::vector<u16> ord124({0, 1});
      slog::Relation* readrel125 = db->getRelation("_enum");
      _enumindex120 = readrel125->getIndex(ord124, false);
  
    }
    ReadTask121(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c29 = _t[0];
        u64 v_c28 = _t[1];
        slog::join_probe<2,2>(_enumindex120, std::array<u64,2>{v_c28, v_c27}, [&](const std::array<u64,2>& m126) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c29}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:23", "delta:DBool", _fires);
  
      if (!_done)
      {
        ReadTask121* _cont = new ReadTask121(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask121(db,b), false);
  // (crule (pre (let __tconst4Tmq78 constcea17e0b05e3e6ace77ec2d1)) (scan DBool __t6cJv5 __t3TAP4) (body (join _enum (0 1) 2 __t3TAP4 __tconst4Tmq78)) (head (mkstruct Wrap (1 0) __t8hcw6 __t6cJv5)) dem_neq_literal.slog:33 #f)
  class ReadTask128 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex127;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Wrap");
      outer_rel = db->getRelation("DBool");
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("_enum");
      _enumindex127 = readrel130->getIndex(ord129, false);
  
    }
    ReadTask128(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c26 = _t[0];
        u64 v_c24 = _t[1];
        slog::join_probe<2,2>(_enumindex127, std::array<u64,2>{v_c24, v_c23}, [&](const std::array<u64,2>& m131) {
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c26}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:33", "delta:DBool", _fires);
  
      if (!_done)
      {
        ReadTask128* _cont = new ReadTask128(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask128(db,b), false);
  // (crule (pre (let __tconst0JFG64 const7902699be42c8a8e46fbbb45)) (seeded) (body (join DInt (1 0) 1 __tconst0JFG64 __t9DSZ65) (join Wrap (1 0) 1 __t9DSZ65 __t6HIa66)) (head (mkstruct normB (1 0) __2Bdt76 __t6HIa66)) dem_neq_literal.slog:36 #f)
  class ReadTask134 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** DIntindex132;  slog::Index** Wrapindex133;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normB");
      std::vector<u16> ord135({1, 0});
      slog::Relation* readrel136 = db->getRelation("normB");
      head_index[0] = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 0});
      slog::Relation* readrel138 = db->getRelation("DInt");
      DIntindex132 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 0});
      slog::Relation* readrel140 = db->getRelation("Wrap");
      Wrapindex133 = readrel140->getIndex(ord139, false);
  
    }
    ReadTask134(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(DIntindex132, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m141) {
        u64 v_c1 = m141[1];
        slog::join_probe<2,1>(Wrapindex133, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m142) {
          u64 v_c33 = m142[1];
          ++_fires;
          slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c33}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:36", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask134(db,b));
  // (crule (pre (let __trid057o83 const1bbd189cbe7b0e1338ec0ae5) (let __trel9nTS84 const3f91f2c205f6fee203b3a41a) (let __tcol0q0b85 const5feceb66ffc86f38d952786c)) (scan $sup87077x26x0x0x0 __d0 d fd) (body) (head (tycheck d (accept (struct DBool) (struct DInt) (struct Wrap)) __trid057o83 __trel9nTS84 __tcol0q0b85 (1 2 3 4 0)) (mkstruct normB (1 0) __6KKs82 d)) dem_neq_literal.slog:27 #f)
  class ReadTask146 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid143;  u32 sid144;  u32 sid145;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("normB");
      outer_rel = db->getRelation("$sup87077x26x0x0x0");
      sid143 = db->getRelation("DBool")->getStructId();
      sid144 = db->getRelation("DInt")->getStructId();
      sid145 = db->getRelation("Wrap")->getStructId();
  
    }
    ReadTask146(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const1bbd189cbe7b0e1338ec0ae5;
      u64 v_c35 = v_const3f91f2c205f6fee203b3a41a;
      u64 v_c36 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c32 = _t[2];
        ++_fires;
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid143 || decode_struct_id(v_c7) == sid144 || decode_struct_id(v_c7) == sid145))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c34, v_c35, v_c36, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c7}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:27", "delta:$sup87077x26x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask146* _cont = new ReadTask146(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask146(db,b), false);
  // (crule (pre (let __tconst4Tmq78 constcea17e0b05e3e6ace77ec2d1)) (seeded) (body (join _enum (1 0) 1 __tconst4Tmq78 __t3TAP4) (join DBool (1 0) 1 __t3TAP4 __t6cJv5)) (head (mkstruct Wrap (1 0) __t8hcw6 __t6cJv5)) dem_neq_literal.slog:33 #f)
  class ReadTask149 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex147;  slog::Index** DBoolindex148;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Wrap");
      std::vector<u16> ord150({1, 0});
      slog::Relation* readrel151 = db->getRelation("Wrap");
      head_index[0] = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({1, 0});
      slog::Relation* readrel153 = db->getRelation("_enum");
      _enumindex147 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 0});
      slog::Relation* readrel155 = db->getRelation("DBool");
      DBoolindex148 = readrel155->getIndex(ord154, false);
  
    }
    ReadTask149(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex147, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m156) {
        u64 v_c24 = m156[1];
        slog::join_probe<2,1>(DBoolindex148, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m157) {
          u64 v_c26 = m157[1];
          ++_fires;
          slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c26}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:33", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask149(db,b));
  // (crule (pre (let __tconst5u1S74 const76c777b0ce3c35ba97c6cbde)) (probe _enum (1 0) 1 __tconst5u1S74 __t7h7g43) (body) (head (mkstruct DBool (1 0) __t2BbG44 __t7h7g43)) dem_neq_literal.slog:31 #f)
  class ReadTask158 : public slog::Task
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
      head_rel[0] = db->getRelation("DBool");
      std::vector<u16> ord159({1, 0});
      slog::Relation* readrel160 = db->getRelation("_enum");
      driver_index = readrel160->getIndex(ord159, true);
  
    }
    ReadTask158(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c2, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m161) {
        u64 v_c3 = m161[1];
        if (buckethash(v_c3) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:31", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask158* _cont = new ReadTask158(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask158(db,b), true);
  // (crule (pre) (scan fdat fd) (body (join-old Wrap (0 1) 0 (0 1) __t3lfE37 d) (join-old normB (1 0) 1 (1 0) __t3lfE37 __t44h138)) (head (emit $sup87077x26x0x0x0 (0 1 2) __t44h138 d fd)) dem_neq_literal.slog:27 #f)
  class ReadTask166 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Wrapindex162;  slog::Index** normBindex163;  slog::Index** Wrapdelta164;  slog::Index** normBdelta165;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup87077x26x0x0x0");
      std::vector<u16> ord167({0, 1, 2});
      slog::Relation* readrel168 = db->getRelation("$sup87077x26x0x0x0");
      head_index[0] = readrel168->getIndex(ord167, false);
      outer_rel = db->getRelation("fdat");
      std::vector<u16> ord169({0, 1});
      slog::Relation* readrel170 = db->getRelation("Wrap");
      Wrapindex162 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("Wrap");
      Wrapdelta164 = readrel172->getIndex(ord171, true);
      std::vector<u16> ord173({1, 0});
      slog::Relation* readrel174 = db->getRelation("normB");
      normBindex163 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 0});
      slog::Relation* readrel176 = db->getRelation("normB");
      normBdelta165 = readrel176->getIndex(ord175, true);
  
    }
    ReadTask166(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[0];
        slog::join_all_old<2>(Wrapindex162, Wrapdelta164, [&](const std::array<u64,2>& m177) {
          u64 v_c31 = m177[0]; u64 v_c7 = m177[1];
          slog::join_probe_old<2,1>(normBindex163, normBdelta165, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m178) {
            u64 v_c30 = m178[1];
            ++_fires;
            slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c30, v_c7, v_c32}, std::array<u16,3>{0, 1, 2});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:27", "delta:fdat", _fires);
  
      if (!_done)
      {
        ReadTask166* _cont = new ReadTask166(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask166(db,b), false);
  // (crule (pre (let __tconst0JFG64 const7902699be42c8a8e46fbbb45)) (once) (body) (head (mkstruct DInt (1 0) __t9DSZ65 __tconst0JFG64)) dem_neq_literal.slog:36 #f)
  class ReadTask179 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("DInt");
  
    }
    ReadTask179(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:36", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask179(db,b), true);
  // (crule (pre (let __tconst5u1S74 const76c777b0ce3c35ba97c6cbde)) (scan Wrap __t2uix45 __t2BbG44) (body (exists _enum (1 0) 1 __tconst5u1S74) (join DBool (0 1) 1 __t2BbG44 __t7h7g43) (join _enum (0 1) 2 __t7h7g43 __tconst5u1S74)) (head (mkstruct normA (1 0) __5vr173 __t2uix45)) dem_neq_literal.slog:31 #f)
  class ReadTask183 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex180;  slog::Index** DBoolindex181;  slog::Index** _enumindex182;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA");
      outer_rel = db->getRelation("Wrap");
      std::vector<u16> ord184({1, 0});
      slog::Relation* readrel185 = db->getRelation("_enum");
      _enumindex180 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({0, 1});
      slog::Relation* readrel187 = db->getRelation("DBool");
      DBoolindex181 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("_enum");
      _enumindex182 = readrel189->getIndex(ord188, false);
  
    }
    ReadTask183(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c4 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex180, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<2,1>(DBoolindex181, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m190) {
          u64 v_c3 = m190[1];
          slog::join_probe<2,2>(_enumindex182, std::array<u64,2>{v_c3, v_c2}, [&](const std::array<u64,2>& m191) {
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c38}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:31", "delta:Wrap", _fires);
  
      if (!_done)
      {
        ReadTask183* _cont = new ReadTask183(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask183(db,b), false);
  // (crule (pre) (scan Wrap __t5VM452 d) (body (join-old normA (1 0) 1 (1 0) __t5VM452 __t9cYb53)) (head (mkstruct normA (1 0) __3BGD87 d)) dem_neq_literal.slog:18 #f)
  class ReadTask194 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** normAindex192;  slog::Index** normAdelta193;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA");
      outer_rel = db->getRelation("Wrap");
      std::vector<u16> ord195({1, 0});
      slog::Relation* readrel196 = db->getRelation("normA");
      normAindex192 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 0});
      slog::Relation* readrel198 = db->getRelation("normA");
      normAdelta193 = readrel198->getIndex(ord197, true);
  
    }
    ReadTask194(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[1];
        slog::join_probe_old<2,1>(normAindex192, normAdelta193, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m199) {
          u64 v_c5 = m199[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:18", "delta:Wrap", _fires);
  
      if (!_done)
      {
        ReadTask194* _cont = new ReadTask194(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask194(db,b), false);
  // (crule (pre (let __tconst0HhO89 constcea17e0b05e3e6ace77ec2d1)) (scan DBool __t8cRC47 __t5qfH46) (body (join _enum (0 1) 2 __t5qfH46 __tconst0HhO89)) (head (mkstruct Wrap (1 0) __t3vMC48 __t8cRC47)) dem_neq_literal.slog:37 #f)
  class ReadTask201 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex200;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Wrap");
      outer_rel = db->getRelation("DBool");
      std::vector<u16> ord202({0, 1});
      slog::Relation* readrel203 = db->getRelation("_enum");
      _enumindex200 = readrel203->getIndex(ord202, false);
  
    }
    ReadTask201(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c14 = _t[1];
        slog::join_probe<2,2>(_enumindex200, std::array<u64,2>{v_c14, v_c13}, [&](const std::array<u64,2>& m204) {
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:37", "delta:DBool", _fires);
  
      if (!_done)
      {
        ReadTask201* _cont = new ReadTask201(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask201(db,b), false);
  // (crule (pre (let __tconst9T9W15 const7902699be42c8a8e46fbbb45)) (probe DInt (1 0) 1 __tconst9T9W15 __t91BP16) (body) (head (mkstruct Wrap (1 0) __t8WhE17 __t91BP16)) dem_neq_literal.slog:32 #f)
  class ReadTask205 : public slog::Task
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
      head_rel[0] = db->getRelation("Wrap");
      std::vector<u16> ord206({1, 0});
      slog::Relation* readrel207 = db->getRelation("DInt");
      driver_index = readrel207->getIndex(ord206, true);
  
    }
    ReadTask205(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c17, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m208) {
        u64 v_c18 = m208[1];
        if (buckethash(v_c18) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:32", "delta:DInt", _fires);
  
      if (!_done)
      {
        ReadTask205* _cont = new ReadTask205(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask205(db,b), false);
  // (crule (pre (let __tconst9T9W15 const7902699be42c8a8e46fbbb45)) (once) (body) (head (mkstruct DInt (1 0) __t91BP16 __tconst9T9W15)) dem_neq_literal.slog:32 #f)
  class ReadTask209 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("DInt");
  
    }
    ReadTask209(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:32", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask209(db,b), true);
  // (crule (pre (let __tconst8g2w80 const76c777b0ce3c35ba97c6cbde)) (scan Wrap __t7iDF9 __t10ZZ8) (body (exists _enum (1 0) 1 __tconst8g2w80) (join DBool (0 1) 1 __t10ZZ8 __t5slS7) (join _enum (0 1) 2 __t5slS7 __tconst8g2w80)) (head (mkstruct normB (1 0) __7Biu79 __t7iDF9)) dem_neq_literal.slog:35 #f)
  class ReadTask213 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex210;  slog::Index** DBoolindex211;  slog::Index** _enumindex212;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normB");
      outer_rel = db->getRelation("Wrap");
      std::vector<u16> ord214({1, 0});
      slog::Relation* readrel215 = db->getRelation("_enum");
      _enumindex210 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({0, 1});
      slog::Relation* readrel217 = db->getRelation("DBool");
      DBoolindex211 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0, 1});
      slog::Relation* readrel219 = db->getRelation("_enum");
      _enumindex212 = readrel219->getIndex(ord218, false);
  
    }
    ReadTask213(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c39 = _t[0];
        u64 v_c20 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex210, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<2,1>(DBoolindex211, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m220) {
          u64 v_c16 = m220[1];
          slog::join_probe<2,2>(_enumindex212, std::array<u64,2>{v_c16, v_c15}, [&](const std::array<u64,2>& m221) {
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:35", "delta:Wrap", _fires);
  
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
  // (crule (pre (let __tconst9T9W15 const7902699be42c8a8e46fbbb45)) (scan Wrap __t8WhE17 __t91BP16) (body (join DInt (0 1) 2 __t91BP16 __tconst9T9W15)) (head (mkstruct normA (1 0) __8bNW69 __t8WhE17)) dem_neq_literal.slog:32 #f)
  class ReadTask223 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** DIntindex222;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA");
      outer_rel = db->getRelation("Wrap");
      std::vector<u16> ord224({0, 1});
      slog::Relation* readrel225 = db->getRelation("DInt");
      DIntindex222 = readrel225->getIndex(ord224, false);
  
    }
    ReadTask223(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c19 = _t[0];
        u64 v_c18 = _t[1];
        slog::join_probe<2,2>(DIntindex222, std::array<u64,2>{v_c18, v_c17}, [&](const std::array<u64,2>& m226) {
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:32", "delta:Wrap", _fires);
  
      if (!_done)
      {
        ReadTask223* _cont = new ReadTask223(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask223(db,b), false);
  // (crule (pre (let __tconst4Tmq78 constcea17e0b05e3e6ace77ec2d1)) (seeded) (body (join _enum (1 0) 1 __tconst4Tmq78 __t3TAP4) (join DBool (1 0) 1 __t3TAP4 __t6cJv5) (join Wrap (1 0) 1 __t6cJv5 __t8hcw6)) (head (mkstruct normA (1 0) __1dfE77 __t8hcw6)) dem_neq_literal.slog:33 #f)
  class ReadTask230 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex227;  slog::Index** DBoolindex228;  slog::Index** Wrapindex229;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA");
      std::vector<u16> ord231({1, 0});
      slog::Relation* readrel232 = db->getRelation("normA");
      head_index[0] = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 0});
      slog::Relation* readrel234 = db->getRelation("_enum");
      _enumindex227 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 0});
      slog::Relation* readrel236 = db->getRelation("DBool");
      DBoolindex228 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 0});
      slog::Relation* readrel238 = db->getRelation("Wrap");
      Wrapindex229 = readrel238->getIndex(ord237, false);
  
    }
    ReadTask230(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex227, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m239) {
        u64 v_c24 = m239[1];
        slog::join_probe<2,1>(DBoolindex228, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m240) {
          u64 v_c26 = m240[1];
          slog::join_probe<2,1>(Wrapindex229, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m241) {
            u64 v_c25 = m241[1];
            ++_fires;
            slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:33", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask230(db,b));
  // (crule (pre (let __tconst0HhO89 constcea17e0b05e3e6ace77ec2d1)) (seeded) (body (join _enum (1 0) 1 __tconst0HhO89 __t5qfH46) (join DBool (1 0) 1 __t5qfH46 __t8cRC47)) (head (mkstruct Wrap (1 0) __t3vMC48 __t8cRC47)) dem_neq_literal.slog:37 #f)
  class ReadTask244 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex242;  slog::Index** DBoolindex243;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Wrap");
      std::vector<u16> ord245({1, 0});
      slog::Relation* readrel246 = db->getRelation("Wrap");
      head_index[0] = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 0});
      slog::Relation* readrel248 = db->getRelation("_enum");
      _enumindex242 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 0});
      slog::Relation* readrel250 = db->getRelation("DBool");
      DBoolindex243 = readrel250->getIndex(ord249, false);
  
    }
    ReadTask244(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex242, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m251) {
        u64 v_c14 = m251[1];
        slog::join_probe<2,1>(DBoolindex243, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m252) {
          u64 v_c21 = m252[1];
          ++_fires;
          slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:37", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask244(db,b));
  // (crule (pre) (scan Wrap __t3lfE37 d) (body (join-old normB (1 0) 1 (1 0) __t3lfE37 __t44h138) (join fdat (0) 0 fd)) (head (emit $sup87077x26x0x0x0 (0 1 2) __t44h138 d fd)) dem_neq_literal.slog:27 #f)
  class ReadTask256 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** normBindex253;  slog::Index** fdatindex254;  slog::Index** normBdelta255;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup87077x26x0x0x0");
      std::vector<u16> ord257({0, 1, 2});
      slog::Relation* readrel258 = db->getRelation("$sup87077x26x0x0x0");
      head_index[0] = readrel258->getIndex(ord257, false);
      outer_rel = db->getRelation("Wrap");
      std::vector<u16> ord259({1, 0});
      slog::Relation* readrel260 = db->getRelation("normB");
      normBindex253 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 0});
      slog::Relation* readrel262 = db->getRelation("normB");
      normBdelta255 = readrel262->getIndex(ord261, true);
      std::vector<u16> ord263({0});
      slog::Relation* readrel264 = db->getRelation("fdat");
      fdatindex254 = readrel264->getIndex(ord263, false);
  
    }
    ReadTask256(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c31 = _t[0];
        u64 v_c7 = _t[1];
        slog::join_probe_old<2,1>(normBindex253, normBdelta255, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m265) {
          u64 v_c30 = m265[1];
          slog::join_all<1>(fdatindex254, [&](const std::array<u64,1>& m266) {
            u64 v_c32 = m266[0];
            ++_fires;
            slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c30, v_c7, v_c32}, std::array<u16,3>{0, 1, 2});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:27", "delta:Wrap", _fires);
  
      if (!_done)
      {
        ReadTask256* _cont = new ReadTask256(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask256(db,b), false);
  // (crule (pre (let __tconst0HhO89 constcea17e0b05e3e6ace77ec2d1)) (scan Wrap __t3vMC48 __t8cRC47) (body (exists _enum (1 0) 1 __tconst0HhO89) (join DBool (0 1) 1 __t8cRC47 __t5qfH46) (join _enum (0 1) 2 __t5qfH46 __tconst0HhO89)) (head (mkstruct normB (1 0) __9qpr88 __t3vMC48)) dem_neq_literal.slog:37 #f)
  class ReadTask270 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex267;  slog::Index** DBoolindex268;  slog::Index** _enumindex269;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normB");
      outer_rel = db->getRelation("Wrap");
      std::vector<u16> ord271({1, 0});
      slog::Relation* readrel272 = db->getRelation("_enum");
      _enumindex267 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({0, 1});
      slog::Relation* readrel274 = db->getRelation("DBool");
      DBoolindex268 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({0, 1});
      slog::Relation* readrel276 = db->getRelation("_enum");
      _enumindex269 = readrel276->getIndex(ord275, false);
  
    }
    ReadTask270(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        u64 v_c21 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex267, std::array<u64,2>{v_c13, 0})) return;
        slog::join_probe<2,1>(DBoolindex268, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m277) {
          u64 v_c14 = m277[1];
          slog::join_probe<2,2>(_enumindex269, std::array<u64,2>{v_c14, v_c13}, [&](const std::array<u64,2>& m278) {
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:37", "delta:Wrap", _fires);
  
      if (!_done)
      {
        ReadTask270* _cont = new ReadTask270(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask270(db,b), false);
  // (crule (pre (let __tconst0JFG64 const7902699be42c8a8e46fbbb45)) (scan Wrap __t6HIa66 __t9DSZ65) (body (join DInt (0 1) 2 __t9DSZ65 __tconst0JFG64)) (head (mkstruct normB (1 0) __2Bdt76 __t6HIa66)) dem_neq_literal.slog:36 #f)
  class ReadTask280 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** DIntindex279;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normB");
      outer_rel = db->getRelation("Wrap");
      std::vector<u16> ord281({0, 1});
      slog::Relation* readrel282 = db->getRelation("DInt");
      DIntindex279 = readrel282->getIndex(ord281, false);
  
    }
    ReadTask280(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c33 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe<2,2>(DIntindex279, std::array<u64,2>{v_c1, v_c0}, [&](const std::array<u64,2>& m283) {
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c33}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:36", "delta:Wrap", _fires);
  
      if (!_done)
      {
        ReadTask280* _cont = new ReadTask280(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask280(db,b), false);
  // (crule (pre (let __tconst8g2w80 const76c777b0ce3c35ba97c6cbde)) (seeded) (body (join _enum (1 0) 1 __tconst8g2w80 __t5slS7) (join DBool (1 0) 1 __t5slS7 __t10ZZ8) (join Wrap (1 0) 1 __t10ZZ8 __t7iDF9)) (head (mkstruct normB (1 0) __7Biu79 __t7iDF9)) dem_neq_literal.slog:35 #f)
  class ReadTask287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex284;  slog::Index** DBoolindex285;  slog::Index** Wrapindex286;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normB");
      std::vector<u16> ord288({1, 0});
      slog::Relation* readrel289 = db->getRelation("normB");
      head_index[0] = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 0});
      slog::Relation* readrel291 = db->getRelation("_enum");
      _enumindex284 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 0});
      slog::Relation* readrel293 = db->getRelation("DBool");
      DBoolindex285 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 0});
      slog::Relation* readrel295 = db->getRelation("Wrap");
      Wrapindex286 = readrel295->getIndex(ord294, false);
  
    }
    ReadTask287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex284, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m296) {
        u64 v_c16 = m296[1];
        slog::join_probe<2,1>(DBoolindex285, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m297) {
          u64 v_c20 = m297[1];
          slog::join_probe<2,1>(Wrapindex286, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m298) {
            u64 v_c39 = m298[1];
            ++_fires;
            slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:35", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask287(db,b));
  // (crule (pre (let __tconst5u1S74 const76c777b0ce3c35ba97c6cbde)) (seeded) (body (join _enum (1 0) 1 __tconst5u1S74 __t7h7g43) (join DBool (1 0) 1 __t7h7g43 __t2BbG44) (join Wrap (1 0) 1 __t2BbG44 __t2uix45)) (head (mkstruct normA (1 0) __5vr173 __t2uix45)) dem_neq_literal.slog:31 #f)
  class ReadTask302 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex299;  slog::Index** DBoolindex300;  slog::Index** Wrapindex301;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA");
      std::vector<u16> ord303({1, 0});
      slog::Relation* readrel304 = db->getRelation("normA");
      head_index[0] = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({1, 0});
      slog::Relation* readrel306 = db->getRelation("_enum");
      _enumindex299 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({1, 0});
      slog::Relation* readrel308 = db->getRelation("DBool");
      DBoolindex300 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({1, 0});
      slog::Relation* readrel310 = db->getRelation("Wrap");
      Wrapindex301 = readrel310->getIndex(ord309, false);
  
    }
    ReadTask302(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const76c777b0ce3c35ba97c6cbde;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex299, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m311) {
        u64 v_c3 = m311[1];
        slog::join_probe<2,1>(DBoolindex300, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m312) {
          u64 v_c4 = m312[1];
          slog::join_probe<2,1>(Wrapindex301, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m313) {
            u64 v_c38 = m313[1];
            ++_fires;
            slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c38}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:31", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask302(db,b));
  s->addReadRel("$sup87077x26x0x0x0");
  s->addReadRel("DBool");
  s->addReadRel("DInt");
  s->addReadRel("Wrap");
  s->addReadRel("_enum");
  s->addReadRel("fdat");
  s->addReadRel("malformed_deduction");
  s->addReadRel("normA");
  s->addReadRel("normB");
  s->addDynamicRel("$sup87077x26x0x0x0");
  s->addDynamicRel("DBool");
  s->addDynamicRel("DInt");
  s->addDynamicRel("Wrap");
  s->addDynamicRel("error");
  s->addDynamicRel("fdat");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("normA");
  s->addDynamicRel("normB");
  s->addAccelRel("fdat");
  d->push(s);
  d->continueRun();
}

