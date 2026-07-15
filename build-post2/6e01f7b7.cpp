
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const19581e27de7ced00ff1ce50b;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("6e01f7b7");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const19581e27de7ced00ff1ce50b = s32_encode(9);
  r = db->getRelation("want");
  if (r == 0) db->addRelation("want", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("want");
      std::vector<u16> ord198({0});
    
    r->addIndex<1>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("want"), std::array<u16,1>{0}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord199({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord199, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord200({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord201({1, 2, 0});
    
    r->addIndex<3>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord202({0, 1, 2});
    
    r->addIndex<3>(ord202, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("third3");
  if (r == 0) db->addRelation("third3", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("third3");
      std::vector<u16> ord203({0});
    
    r->addIndex<1>(ord203, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("third3"), std::array<u16,1>{0}, b));
  r = db->getRelation("startw");
  if (r == 0) db->addRelation("startw", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("startw");
      std::vector<u16> ord204({0});
    
    r->addIndex<1>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("startw"), std::array<u16,1>{0}, b));
  r = db->getRelation("starts7");
  if (r == 0) db->addRelation("starts7", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("starts7");
      std::vector<u16> ord205({0});
    
    r->addIndex<1>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("starts7"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord206({1, 2, 0});
    
    r->addIndex<3>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord207({0, 1, 2});
    
    r->addIndex<3>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("pair79");
  if (r == 0) db->addRelation("pair79", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pair79");
      std::vector<u16> ord208({0});
    
    r->addIndex<1>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pair79"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord209({1, 2, 3, 0});
    
    r->addIndex<4>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord210({0, 1, 2, 3});
    
    r->addIndex<4>(ord210, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord211({1, 2, 0});
    
    r->addIndex<3>(ord211, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord212({0, 1, 2});
    
    r->addIndex<3>(ord212, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord213({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord213, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord214({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord215({1, 2, 0});
    
    r->addIndex<3>(ord215, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord216({0, 1, 2});
    
    r->addIndex<3>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord217({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord217, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord218({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord219({1, 2, 3, 0});
    
    r->addIndex<4>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord220({0, 1, 2, 3});
    
    r->addIndex<4>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord221({0});
    
    r->addIndex<1>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("ends9");
  if (r == 0) db->addRelation("ends9", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ends9");
      std::vector<u16> ord222({0});
    
    r->addIndex<1>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("ends9"), std::array<u16,1>{0}, b));
  r = db->getRelation("doc");
  if (r == 0) db->addRelation("doc", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("doc");
      std::vector<u16> ord223({0});
    
    r->addIndex<1>(ord223, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("doc"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord224({1, 2, 0});
    
    r->addIndex<3>(ord224, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord225({0, 1, 2});
    
    r->addIndex<3>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord226({1, 0});
    
    r->addIndex<2>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord227({0, 1});
    
    r->addIndex<2>(ord227, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$seq_atr");
  if (r == 0) db->addRelation("$seq_atr", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_atr");
      std::vector<u16> ord228({0, 1, 2});
    
    r->addIndex<3>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord229({0, 1, 2});
    
    r->addIndex<3>(ord229, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_atr"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord230({0, 1, 2});
    
    r->addIndex<3>(ord230, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord231({0, 1, 2});
    
    r->addIndex<3>(ord231, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord232({1, 0, 2});
    
    r->addIndex<3>(ord232, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("doc"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("ends9"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("pair79"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("starts7"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("startw"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("third3"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre (let _00024sqc6smA61 const4e07408562bedb8b60ce05c1) (let _00024sqc8kxX62 const6b86b273ff34fce19d6b804e) (let _00024sqc6bw063 const7902699be42c8a8e46fbbb45) (let _00024sqc7oBS64 constd4735e3a265e16eee03f5971) (let _00024sqc3A3V65 const19581e27de7ced00ff1ce50b) (let _00024sqo7K0i67 const7902699be42c8a8e46fbbb45) (let _00024sqo5sCW66 const6b86b273ff34fce19d6b804e) (let _00024sqo3R0b69 const19581e27de7ced00ff1ce50b) (let _00024sqo8kPx68 constd4735e3a265e16eee03f5971) (let _00024sqo6GkO71 const7902699be42c8a8e46fbbb45) (let _00024sqo7x6f70 const6b86b273ff34fce19d6b804e) (let _00024sqo2bg573 const19581e27de7ced00ff1ce50b) (let _00024sqo3wTa72 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo2bg573 _00024sqo3wTa72 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo7K0i67 _00024sqo5sCW66 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3R0b69 _00024sqo8kPx68 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo6GkO71 _00024sqo7x6f70 _00024seq0) (join doc (0) 1 _00024seq0) (letp _00024sql6at159 (aslst _00024seq0)) (let chk1b3t219 (llen _00024sql6at159)) (eq _00024sqc6smA61 chk1b3t219) (letp chk11lj220 (lref _00024sql6at159 _00024sqc8kxX62)) (eq _00024sqc6bw063 chk11lj220) (letp chk65k3221 (lref _00024sql6at159 _00024sqc7oBS64)) (eq _00024sqc3A3V65 chk65k3221)) (head (emit pair79 (0) _00024seq0)) seq_join.slog:27 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex0;  slog::Index** $seq_atindex1;  slog::Index** $seq_atrindex2;  slog::Index** docindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("pair79");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("pair79");
      head_index[0] = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({0, 1, 2});
      slog::Relation* readrel8 = db->getRelation("$seq_atr");
      driver_index = readrel8->getIndex(ord7, true);
      std::vector<u16> ord9({0, 1, 2});
      slog::Relation* readrel10 = db->getRelation("$seq_at");
      $seq_atindex0 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({0, 1, 2});
      slog::Relation* readrel12 = db->getRelation("$seq_at");
      $seq_atindex1 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({0, 1, 2});
      slog::Relation* readrel14 = db->getRelation("$seq_atr");
      $seq_atrindex2 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({0});
      slog::Relation* readrel16 = db->getRelation("doc");
      docindex3 = readrel16->getIndex(ord15, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c5 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c8 = v_constd4735e3a265e16eee03f5971;
      u64 v_c9 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c11, v_c12, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m17) {
        u64 v_c13 = m17[2];
        if (buckethash(v_c13) != bucket) return;
        slog::join_probe<3,3>($seq_atindex0, std::array<u64,3>{v_c5, v_c6, v_c13}, [&](const std::array<u64,3>& m18) {
          slog::join_probe<3,3>($seq_atindex1, std::array<u64,3>{v_c7, v_c8, v_c13}, [&](const std::array<u64,3>& m19) {
            slog::join_probe<3,3>($seq_atrindex2, std::array<u64,3>{v_c9, v_c10, v_c13}, [&](const std::array<u64,3>& m20) {
              slog::join_probe<1,1>(docindex3, std::array<u64,1>{v_c13}, [&](const std::array<u64,1>& m21) {
                bool ok22 = true;
                u64 v_c14 = _prim_aslst(db, v_c13, &ok22);
                if (!ok22) return;
                u64 v_c15 = _prim_llen(db, v_c14);
                if (v_c15 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:27"); return; }
                if (v_c0 != v_c15) return;
                bool ok23 = true;
                u64 v_c16 = _prim_lref(db, v_c14, v_c1, &ok23);
                if (!ok23) return;
                if (v_c2 != v_c16) return;
                bool ok24 = true;
                u64 v_c17 = _prim_lref(db, v_c14, v_c3, &ok24);
                if (!ok24) return;
                if (v_c4 != v_c17) return;
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_join.slog:27", "delta:$seq_atr", _fires);
  
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
      s->addTask(phase_read, new ReadTask4(db,b), false);
  // (crule (pre (let _00024sqc6smA61 const4e07408562bedb8b60ce05c1) (let _00024sqc8kxX62 const6b86b273ff34fce19d6b804e) (let _00024sqc6bw063 const7902699be42c8a8e46fbbb45) (let _00024sqc7oBS64 constd4735e3a265e16eee03f5971) (let _00024sqc3A3V65 const19581e27de7ced00ff1ce50b) (let _00024sqo7K0i67 const7902699be42c8a8e46fbbb45) (let _00024sqo5sCW66 const6b86b273ff34fce19d6b804e) (let _00024sqo3R0b69 const19581e27de7ced00ff1ce50b) (let _00024sqo8kPx68 constd4735e3a265e16eee03f5971) (let _00024sqo6GkO71 const7902699be42c8a8e46fbbb45) (let _00024sqo7x6f70 const6b86b273ff34fce19d6b804e) (let _00024sqo2bg573 const19581e27de7ced00ff1ce50b) (let _00024sqo3wTa72 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo6GkO71 _00024sqo7x6f70 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo7K0i67 _00024sqo5sCW66 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3R0b69 _00024sqo8kPx68 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2bg573 _00024sqo3wTa72 _00024seq0) (join doc (0) 1 _00024seq0) (letp _00024sql6at159 (aslst _00024seq0)) (let chk9Gpa216 (llen _00024sql6at159)) (eq _00024sqc6smA61 chk9Gpa216) (letp chk6kCh217 (lref _00024sql6at159 _00024sqc8kxX62)) (eq _00024sqc6bw063 chk6kCh217) (letp chk3IAW218 (lref _00024sql6at159 _00024sqc7oBS64)) (eq _00024sqc3A3V65 chk3IAW218)) (head (emit pair79 (0) _00024seq0)) seq_join.slog:27 #f)
  class ReadTask30 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex25;  slog::Index** $seq_atindex26;  slog::Index** $seq_atrindex27;  slog::Index** docindex28;  slog::Index** $seq_atrdelta29;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("pair79");
      std::vector<u16> ord31({0});
      slog::Relation* readrel32 = db->getRelation("pair79");
      head_index[0] = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({0, 1, 2});
      slog::Relation* readrel34 = db->getRelation("$seq_atr");
      driver_index = readrel34->getIndex(ord33, true);
      std::vector<u16> ord35({0, 1, 2});
      slog::Relation* readrel36 = db->getRelation("$seq_at");
      $seq_atindex25 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({0, 1, 2});
      slog::Relation* readrel38 = db->getRelation("$seq_at");
      $seq_atindex26 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 1, 2});
      slog::Relation* readrel40 = db->getRelation("$seq_atr");
      $seq_atrindex27 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0, 1, 2});
      slog::Relation* readrel42 = db->getRelation("$seq_atr");
      $seq_atrdelta29 = readrel42->getIndex(ord41, true);
      std::vector<u16> ord43({0});
      slog::Relation* readrel44 = db->getRelation("doc");
      docindex28 = readrel44->getIndex(ord43, false);
  
    }
    ReadTask30(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c5 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c8 = v_constd4735e3a265e16eee03f5971;
      u64 v_c9 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c9, v_c10, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m45) {
        u64 v_c13 = m45[2];
        if (buckethash(v_c13) != bucket) return;
        slog::join_probe<3,3>($seq_atindex25, std::array<u64,3>{v_c5, v_c6, v_c13}, [&](const std::array<u64,3>& m46) {
          slog::join_probe<3,3>($seq_atindex26, std::array<u64,3>{v_c7, v_c8, v_c13}, [&](const std::array<u64,3>& m47) {
            slog::join_probe_old<3,3>($seq_atrindex27, $seq_atrdelta29, std::array<u64,3>{v_c11, v_c12, v_c13}, [&](const std::array<u64,3>& m48) {
              slog::join_probe<1,1>(docindex28, std::array<u64,1>{v_c13}, [&](const std::array<u64,1>& m49) {
                bool ok50 = true;
                u64 v_c14 = _prim_aslst(db, v_c13, &ok50);
                if (!ok50) return;
                u64 v_c18 = _prim_llen(db, v_c14);
                if (v_c18 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:27"); return; }
                if (v_c0 != v_c18) return;
                bool ok51 = true;
                u64 v_c19 = _prim_lref(db, v_c14, v_c1, &ok51);
                if (!ok51) return;
                if (v_c2 != v_c19) return;
                bool ok52 = true;
                u64 v_c20 = _prim_lref(db, v_c14, v_c3, &ok52);
                if (!ok52) return;
                if (v_c4 != v_c20) return;
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_join.slog:27", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask30* _cont = new ReadTask30(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask30(db,b), false);
  // (crule (pre (let _00024sqc6smA61 const4e07408562bedb8b60ce05c1) (let _00024sqc8kxX62 const6b86b273ff34fce19d6b804e) (let _00024sqc6bw063 const7902699be42c8a8e46fbbb45) (let _00024sqc7oBS64 constd4735e3a265e16eee03f5971) (let _00024sqc3A3V65 const19581e27de7ced00ff1ce50b) (let _00024sqo7K0i67 const7902699be42c8a8e46fbbb45) (let _00024sqo5sCW66 const6b86b273ff34fce19d6b804e) (let _00024sqo3R0b69 const19581e27de7ced00ff1ce50b) (let _00024sqo8kPx68 constd4735e3a265e16eee03f5971) (let _00024sqo6GkO71 const7902699be42c8a8e46fbbb45) (let _00024sqo7x6f70 const6b86b273ff34fce19d6b804e) (let _00024sqo2bg573 const19581e27de7ced00ff1ce50b) (let _00024sqo3wTa72 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo3R0b69 _00024sqo8kPx68 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo7K0i67 _00024sqo5sCW66 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo6GkO71 _00024sqo7x6f70 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2bg573 _00024sqo3wTa72 _00024seq0) (join doc (0) 1 _00024seq0) (letp _00024sql6at159 (aslst _00024seq0)) (let chk9U4U213 (llen _00024sql6at159)) (eq _00024sqc6smA61 chk9U4U213) (letp chk4Uqe214 (lref _00024sql6at159 _00024sqc8kxX62)) (eq _00024sqc6bw063 chk4Uqe214) (letp chk442z215 (lref _00024sql6at159 _00024sqc7oBS64)) (eq _00024sqc3A3V65 chk442z215)) (head (emit pair79 (0) _00024seq0)) seq_join.slog:27 #f)
  class ReadTask59 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex53;  slog::Index** $seq_atrindex54;  slog::Index** $seq_atrindex55;  slog::Index** docindex56;  slog::Index** $seq_atrdelta57;  slog::Index** $seq_atrdelta58;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("pair79");
      std::vector<u16> ord60({0});
      slog::Relation* readrel61 = db->getRelation("pair79");
      head_index[0] = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({0, 1, 2});
      slog::Relation* readrel63 = db->getRelation("$seq_at");
      driver_index = readrel63->getIndex(ord62, true);
      std::vector<u16> ord64({0, 1, 2});
      slog::Relation* readrel65 = db->getRelation("$seq_at");
      $seq_atindex53 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({0, 1, 2});
      slog::Relation* readrel67 = db->getRelation("$seq_atr");
      $seq_atrindex54 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({0, 1, 2});
      slog::Relation* readrel69 = db->getRelation("$seq_atr");
      $seq_atrdelta57 = readrel69->getIndex(ord68, true);
      std::vector<u16> ord70({0, 1, 2});
      slog::Relation* readrel71 = db->getRelation("$seq_atr");
      $seq_atrindex55 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({0, 1, 2});
      slog::Relation* readrel73 = db->getRelation("$seq_atr");
      $seq_atrdelta58 = readrel73->getIndex(ord72, true);
      std::vector<u16> ord74({0});
      slog::Relation* readrel75 = db->getRelation("doc");
      docindex56 = readrel75->getIndex(ord74, false);
  
    }
    ReadTask59(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c5 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c8 = v_constd4735e3a265e16eee03f5971;
      u64 v_c9 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c7, v_c8, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m76) {
        u64 v_c13 = m76[2];
        if (buckethash(v_c13) != bucket) return;
        slog::join_probe<3,3>($seq_atindex53, std::array<u64,3>{v_c5, v_c6, v_c13}, [&](const std::array<u64,3>& m77) {
          slog::join_probe_old<3,3>($seq_atrindex54, $seq_atrdelta57, std::array<u64,3>{v_c9, v_c10, v_c13}, [&](const std::array<u64,3>& m78) {
            slog::join_probe_old<3,3>($seq_atrindex55, $seq_atrdelta58, std::array<u64,3>{v_c11, v_c12, v_c13}, [&](const std::array<u64,3>& m79) {
              slog::join_probe<1,1>(docindex56, std::array<u64,1>{v_c13}, [&](const std::array<u64,1>& m80) {
                bool ok81 = true;
                u64 v_c14 = _prim_aslst(db, v_c13, &ok81);
                if (!ok81) return;
                u64 v_c21 = _prim_llen(db, v_c14);
                if (v_c21 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:27"); return; }
                if (v_c0 != v_c21) return;
                bool ok82 = true;
                u64 v_c22 = _prim_lref(db, v_c14, v_c1, &ok82);
                if (!ok82) return;
                if (v_c2 != v_c22) return;
                bool ok83 = true;
                u64 v_c23 = _prim_lref(db, v_c14, v_c3, &ok83);
                if (!ok83) return;
                if (v_c4 != v_c23) return;
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_join.slog:27", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask59* _cont = new ReadTask59(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask59(db,b), false);
  // (crule (pre (let _00024sqc6smA61 const4e07408562bedb8b60ce05c1) (let _00024sqc8kxX62 const6b86b273ff34fce19d6b804e) (let _00024sqc6bw063 const7902699be42c8a8e46fbbb45) (let _00024sqc7oBS64 constd4735e3a265e16eee03f5971) (let _00024sqc3A3V65 const19581e27de7ced00ff1ce50b) (let _00024sqo7K0i67 const7902699be42c8a8e46fbbb45) (let _00024sqo5sCW66 const6b86b273ff34fce19d6b804e) (let _00024sqo3R0b69 const19581e27de7ced00ff1ce50b) (let _00024sqo8kPx68 constd4735e3a265e16eee03f5971) (let _00024sqo6GkO71 const7902699be42c8a8e46fbbb45) (let _00024sqo7x6f70 const6b86b273ff34fce19d6b804e) (let _00024sqo2bg573 const19581e27de7ced00ff1ce50b) (let _00024sqo3wTa72 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo7K0i67 _00024sqo5sCW66 _00024seq0) (body (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo3R0b69 _00024sqo8kPx68 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo6GkO71 _00024sqo7x6f70 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2bg573 _00024sqo3wTa72 _00024seq0) (join doc (0) 1 _00024seq0) (letp _00024sql6at159 (aslst _00024seq0)) (let chk39kB210 (llen _00024sql6at159)) (eq _00024sqc6smA61 chk39kB210) (letp chk9rPk211 (lref _00024sql6at159 _00024sqc8kxX62)) (eq _00024sqc6bw063 chk9rPk211) (letp chk7Xzi212 (lref _00024sql6at159 _00024sqc7oBS64)) (eq _00024sqc3A3V65 chk7Xzi212)) (head (emit pair79 (0) _00024seq0)) seq_join.slog:27 #f)
  class ReadTask91 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex84;  slog::Index** $seq_atrindex85;  slog::Index** $seq_atrindex86;  slog::Index** docindex87;  slog::Index** $seq_atdelta88;  slog::Index** $seq_atrdelta89;  slog::Index** $seq_atrdelta90;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("pair79");
      std::vector<u16> ord92({0});
      slog::Relation* readrel93 = db->getRelation("pair79");
      head_index[0] = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({0, 1, 2});
      slog::Relation* readrel95 = db->getRelation("$seq_at");
      driver_index = readrel95->getIndex(ord94, true);
      std::vector<u16> ord96({0, 1, 2});
      slog::Relation* readrel97 = db->getRelation("$seq_at");
      $seq_atindex84 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({0, 1, 2});
      slog::Relation* readrel99 = db->getRelation("$seq_at");
      $seq_atdelta88 = readrel99->getIndex(ord98, true);
      std::vector<u16> ord100({0, 1, 2});
      slog::Relation* readrel101 = db->getRelation("$seq_atr");
      $seq_atrindex85 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 1, 2});
      slog::Relation* readrel103 = db->getRelation("$seq_atr");
      $seq_atrdelta89 = readrel103->getIndex(ord102, true);
      std::vector<u16> ord104({0, 1, 2});
      slog::Relation* readrel105 = db->getRelation("$seq_atr");
      $seq_atrindex86 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({0, 1, 2});
      slog::Relation* readrel107 = db->getRelation("$seq_atr");
      $seq_atrdelta90 = readrel107->getIndex(ord106, true);
      std::vector<u16> ord108({0});
      slog::Relation* readrel109 = db->getRelation("doc");
      docindex87 = readrel109->getIndex(ord108, false);
  
    }
    ReadTask91(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c5 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c8 = v_constd4735e3a265e16eee03f5971;
      u64 v_c9 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c5, v_c6, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m110) {
        u64 v_c13 = m110[2];
        if (buckethash(v_c13) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex84, $seq_atdelta88, std::array<u64,3>{v_c7, v_c8, v_c13}, [&](const std::array<u64,3>& m111) {
          slog::join_probe_old<3,3>($seq_atrindex85, $seq_atrdelta89, std::array<u64,3>{v_c9, v_c10, v_c13}, [&](const std::array<u64,3>& m112) {
            slog::join_probe_old<3,3>($seq_atrindex86, $seq_atrdelta90, std::array<u64,3>{v_c11, v_c12, v_c13}, [&](const std::array<u64,3>& m113) {
              slog::join_probe<1,1>(docindex87, std::array<u64,1>{v_c13}, [&](const std::array<u64,1>& m114) {
                bool ok115 = true;
                u64 v_c14 = _prim_aslst(db, v_c13, &ok115);
                if (!ok115) return;
                u64 v_c24 = _prim_llen(db, v_c14);
                if (v_c24 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:27"); return; }
                if (v_c0 != v_c24) return;
                bool ok116 = true;
                u64 v_c25 = _prim_lref(db, v_c14, v_c1, &ok116);
                if (!ok116) return;
                if (v_c2 != v_c25) return;
                bool ok117 = true;
                u64 v_c26 = _prim_lref(db, v_c14, v_c3, &ok117);
                if (!ok117) return;
                if (v_c4 != v_c26) return;
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_join.slog:27", "delta:$seq_at", _fires);
  
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
      s->addTask(phase_read, new ReadTask91(db,b), false);
  // (crule (pre (let _00024sqc5iLV49 const6b86b273ff34fce19d6b804e) (let _00024sqc2kfB50 const5feceb66ffc86f38d952786c) (let _00024sqo8TO651 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo8TO651 v _00024seq0) (body (join want (0) 1 v) (join doc (0) 1 _00024seq0) (letp _00024sql5JyY47 (aslst _00024seq0)) (let _00024sqn7iHW48 (llen _00024sql5JyY47)) (cmp ge _00024sqn7iHW48 _00024sqc5iLV49) (letp chk9Ngd208 (lref _00024sql5JyY47 _00024sqc2kfB50)) (eq v chk9Ngd208)) (head (emit startw (0) _00024seq0)) seq_join.slog:23 #f)
  class ReadTask120 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** wantindex118;  slog::Index** docindex119;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("startw");
      std::vector<u16> ord121({0});
      slog::Relation* readrel122 = db->getRelation("startw");
      head_index[0] = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 0, 2});
      slog::Relation* readrel124 = db->getRelation("$seq_at");
      driver_index = readrel124->getIndex(ord123, true);
      std::vector<u16> ord125({0});
      slog::Relation* readrel126 = db->getRelation("want");
      wantindex118 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({0});
      slog::Relation* readrel128 = db->getRelation("doc");
      docindex119 = readrel128->getIndex(ord127, false);
  
    }
    ReadTask120(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c29, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m129) {
        u64 v_c30 = m129[1];
        u64 v_c13 = m129[2];
        if (buckethash(v_c30) != bucket) return;
        slog::join_probe<1,1>(wantindex118, std::array<u64,1>{v_c30}, [&](const std::array<u64,1>& m130) {
          slog::join_probe<1,1>(docindex119, std::array<u64,1>{v_c13}, [&](const std::array<u64,1>& m131) {
            bool ok132 = true;
            u64 v_c31 = _prim_aslst(db, v_c13, &ok132);
            if (!ok132) return;
            u64 v_c32 = _prim_llen(db, v_c31);
            if (v_c32 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:23"); return; }
            u64 v_c33 = _prim_ge(db, v_c32, v_c27);
            if (v_c33 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:23"); return; }
            if (!v_c33) return;
            bool ok134 = true;
            u64 v_c34 = _prim_lref(db, v_c31, v_c28, &ok134);
            if (!ok134) return;
            if (v_c30 != v_c34) return;
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_join.slog:23", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask120* _cont = new ReadTask120(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask120(db,b), false);
  // (crule (pre) (scan nan_result __erre8ydV186 __errf08TH187 __errf3T2n188 __errf922Q189) (body) (head (emit error (0) __erre8ydV186)) <internal>:1 #f)
  class ReadTask135 : public slog::Task
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
      std::vector<u16> ord136({0});
      slog::Relation* readrel137 = db->getRelation("error");
      head_index[0] = readrel137->getIndex(ord136, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask135(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c35 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c37 = _t[2];
        u64 v_c38 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c35}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask135* _cont = new ReadTask135(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask135(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre9u1i203 __errf6tqQ204 __errf8xDc205) (body) (head (emit error (0) __erre9u1i203)) <internal>:1 #f)
  class ReadTask138 : public slog::Task
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
      std::vector<u16> ord139({0});
      slog::Relation* readrel140 = db->getRelation("error");
      head_index[0] = readrel140->getIndex(ord139, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask138(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c41 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask138* _cont = new ReadTask138(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask138(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre2lVQ179 __errf2R3y180 __errf4kvY181) (body) (head (emit error (0) __erre2lVQ179)) <internal>:1 #f)
  class ReadTask141 : public slog::Task
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
      std::vector<u16> ord142({0});
      slog::Relation* readrel143 = db->getRelation("error");
      head_index[0] = readrel143->getIndex(ord142, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask141(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c42}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask141* _cont = new ReadTask141(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask141(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre6g5B198 __errf4Ifc199 __errf6Eq8200 __errf8Tnc201 __errf86l6202) (body) (head (emit error (0) __erre6g5B198)) <internal>:1 #f)
  class ReadTask144 : public slog::Task
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
      std::vector<u16> ord145({0});
      slog::Relation* readrel146 = db->getRelation("error");
      head_index[0] = readrel146->getIndex(ord145, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask144(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  // (crule (pre) (scan toint_range __erre5Fn5190 __errf3tTu191 __errf3hu2192) (body) (head (emit error (0) __erre5Fn5190)) <internal>:1 #f)
  class ReadTask147 : public slog::Task
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
      std::vector<u16> ord148({0});
      slog::Relation* readrel149 = db->getRelation("error");
      head_index[0] = readrel149->getIndex(ord148, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask147(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ReadTask147* _cont = new ReadTask147(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask147(db,b), false);
  // (crule (pre) (scan div_by_zero __erre2xDF176 __errf9Ond177 __errf0UOH178) (body) (head (emit error (0) __erre2xDF176)) <internal>:1 #f)
  class ReadTask150 : public slog::Task
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
      std::vector<u16> ord151({0});
      slog::Relation* readrel152 = db->getRelation("error");
      head_index[0] = readrel152->getIndex(ord151, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask150(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask150* _cont = new ReadTask150(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask150(db,b), false);
  // (crule (pre (let _00024sqc1RlX76 const4e07408562bedb8b60ce05c1) (let _00024sqc2QDC77 constd4735e3a265e16eee03f5971) (let _00024sqc698C78 const4e07408562bedb8b60ce05c1) (let _00024sqo4MRy80 const4e07408562bedb8b60ce05c1) (let _00024sqo1tjo79 constd4735e3a265e16eee03f5971)) (probe $seq_at (0 1 2) 2 _00024sqo4MRy80 _00024sqo1tjo79 _00024seq0) (body (join doc (0) 1 _00024seq0) (letp _00024sql5HvB74 (aslst _00024seq0)) (let _00024sqn7Xgn75 (llen _00024sql5HvB74)) (cmp ge _00024sqn7Xgn75 _00024sqc1RlX76) (letp chk3jci209 (lref _00024sql5HvB74 _00024sqc2QDC77)) (eq _00024sqc698C78 chk3jci209)) (head (emit third3 (0) _00024seq0)) seq_join.slog:17 #f)
  class ReadTask154 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** docindex153;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("third3");
      std::vector<u16> ord155({0});
      slog::Relation* readrel156 = db->getRelation("third3");
      head_index[0] = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({0, 1, 2});
      slog::Relation* readrel158 = db->getRelation("$seq_at");
      driver_index = readrel158->getIndex(ord157, true);
      std::vector<u16> ord159({0});
      slog::Relation* readrel160 = db->getRelation("doc");
      docindex153 = readrel160->getIndex(ord159, false);
  
    }
    ReadTask154(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c57 = v_constd4735e3a265e16eee03f5971;
      u64 v_c58 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c59 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c60 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c59, v_c60, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m161) {
        u64 v_c13 = m161[2];
        if (buckethash(v_c13) != bucket) return;
        slog::join_probe<1,1>(docindex153, std::array<u64,1>{v_c13}, [&](const std::array<u64,1>& m162) {
          bool ok163 = true;
          u64 v_c61 = _prim_aslst(db, v_c13, &ok163);
          if (!ok163) return;
          u64 v_c62 = _prim_llen(db, v_c61);
          if (v_c62 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:17"); return; }
          u64 v_c63 = _prim_ge(db, v_c62, v_c56);
          if (v_c63 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:17"); return; }
          if (!v_c63) return;
          bool ok165 = true;
          u64 v_c64 = _prim_lref(db, v_c61, v_c57, &ok165);
          if (!ok165) return;
          if (v_c58 != v_c64) return;
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_join.slog:17", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask154* _cont = new ReadTask154(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask154(db,b), false);
  // (crule (pre (let _00024sqc42rC54 const6b86b273ff34fce19d6b804e) (let _00024sqc0THW55 const5feceb66ffc86f38d952786c) (let _00024sqc3xFE56 const7902699be42c8a8e46fbbb45) (let _00024sqo3C2k58 const7902699be42c8a8e46fbbb45) (let _00024sqo76AU57 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo3C2k58 _00024sqo76AU57 _00024seq0) (body (join doc (0) 1 _00024seq0) (letp _00024sql381L52 (aslst _00024seq0)) (let _00024sqn8sgR53 (llen _00024sql381L52)) (cmp ge _00024sqn8sgR53 _00024sqc42rC54) (letp chk2nRs206 (lref _00024sql381L52 _00024sqc0THW55)) (eq _00024sqc3xFE56 chk2nRs206)) (head (emit starts7 (0) _00024seq0)) seq_join.slog:15 #f)
  class ReadTask167 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** docindex166;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("starts7");
      std::vector<u16> ord168({0});
      slog::Relation* readrel169 = db->getRelation("starts7");
      head_index[0] = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({0, 1, 2});
      slog::Relation* readrel171 = db->getRelation("$seq_at");
      driver_index = readrel171->getIndex(ord170, true);
      std::vector<u16> ord172({0});
      slog::Relation* readrel173 = db->getRelation("doc");
      docindex166 = readrel173->getIndex(ord172, false);
  
    }
    ReadTask167(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
      u64 v_c67 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c68 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c69 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c68, v_c69, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m174) {
        u64 v_c13 = m174[2];
        if (buckethash(v_c13) != bucket) return;
        slog::join_probe<1,1>(docindex166, std::array<u64,1>{v_c13}, [&](const std::array<u64,1>& m175) {
          bool ok176 = true;
          u64 v_c70 = _prim_aslst(db, v_c13, &ok176);
          if (!ok176) return;
          u64 v_c71 = _prim_llen(db, v_c70);
          if (v_c71 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:15"); return; }
          u64 v_c72 = _prim_ge(db, v_c71, v_c65);
          if (v_c72 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:15"); return; }
          if (!v_c72) return;
          bool ok178 = true;
          u64 v_c73 = _prim_lref(db, v_c70, v_c66, &ok178);
          if (!ok178) return;
          if (v_c67 != v_c73) return;
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_join.slog:15", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask167* _cont = new ReadTask167(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask167(db,b), false);
  // (crule (pre (let _00024sqc81GS41 const6b86b273ff34fce19d6b804e) (let _00024sqc0fwB42 const6b86b273ff34fce19d6b804e) (let _00024sqc5APJ44 const19581e27de7ced00ff1ce50b) (let _00024sqo1G6d46 const19581e27de7ced00ff1ce50b) (let _00024sqo6yoO45 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo1G6d46 _00024sqo6yoO45 _00024seq0) (body (join doc (0) 1 _00024seq0) (letp _00024sql2AfL39 (aslst _00024seq0)) (let _00024sqn8zEy40 (llen _00024sql2AfL39)) (cmp ge _00024sqn8zEy40 _00024sqc81GS41) (let _00024sqp773K43 (_0002d _00024sqn8zEy40 _00024sqc0fwB42)) (letp chk7eWn207 (lref _00024sql2AfL39 _00024sqp773K43)) (eq _00024sqc5APJ44 chk7eWn207)) (head (emit ends9 (0) _00024seq0)) seq_join.slog:16 #f)
  class ReadTask180 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** docindex179;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ends9");
      std::vector<u16> ord181({0});
      slog::Relation* readrel182 = db->getRelation("ends9");
      head_index[0] = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({0, 1, 2});
      slog::Relation* readrel184 = db->getRelation("$seq_atr");
      driver_index = readrel184->getIndex(ord183, true);
      std::vector<u16> ord185({0});
      slog::Relation* readrel186 = db->getRelation("doc");
      docindex179 = readrel186->getIndex(ord185, false);
  
    }
    ReadTask180(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c75 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c76 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c77 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c78 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c77, v_c78, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m187) {
        u64 v_c13 = m187[2];
        if (buckethash(v_c13) != bucket) return;
        slog::join_probe<1,1>(docindex179, std::array<u64,1>{v_c13}, [&](const std::array<u64,1>& m188) {
          bool ok189 = true;
          u64 v_c79 = _prim_aslst(db, v_c13, &ok189);
          if (!ok189) return;
          u64 v_c80 = _prim_llen(db, v_c79);
          if (v_c80 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:16"); return; }
          u64 v_c81 = _prim_ge(db, v_c80, v_c74);
          if (v_c81 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:16"); return; }
          if (!v_c81) return;
          u64 v_c82 = _prim__0002d(db, v_c80, v_c75);
          if (v_c82 == slog_error) { slog::emit_pending_error(db, "seq_join.slog:16"); return; }
          bool ok191 = true;
          u64 v_c83 = _prim_lref(db, v_c79, v_c82, &ok191);
          if (!ok191) return;
          if (v_c76 != v_c83) return;
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_join.slog:16", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask180* _cont = new ReadTask180(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask180(db,b), false);
  // (crule (pre) (scan int_overflow __erre90p0182 __errf1xiH183 __errf8Fgu184 __errf1FUe185) (body) (head (emit error (0) __erre90p0182)) <internal>:1 #f)
  class ReadTask192 : public slog::Task
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
      std::vector<u16> ord193({0});
      slog::Relation* readrel194 = db->getRelation("error");
      head_index[0] = readrel194->getIndex(ord193, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask192(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c84 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c86 = _t[2];
        u64 v_c87 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c84}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask192* _cont = new ReadTask192(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask192(db,b), false);
  // (crule (pre) (scan type_mismatch __erre5uVo193 __errf1B7h194 __errf3Em4195 __errf29nY196 __errf3883197) (body) (head (emit error (0) __erre5uVo193)) <internal>:1 #f)
  class ReadTask195 : public slog::Task
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
      std::vector<u16> ord196({0});
      slog::Relation* readrel197 = db->getRelation("error");
      head_index[0] = readrel197->getIndex(ord196, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask195(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c88 = _t[0];
        u64 v_c89 = _t[1];
        u64 v_c90 = _t[2];
        u64 v_c91 = _t[3];
        u64 v_c92 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c88}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask195* _cont = new ReadTask195(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask195(db,b), false);
  s->addReadRel("$seq_at");
  s->addReadRel("$seq_atr");
  s->addReadRel("div_by_zero");
  s->addReadRel("doc");
  s->addReadRel("int_overflow");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addReadRel("want");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$seq_atr");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("ends9");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("pair79");
  s->addDynamicRel("starts7");
  s->addDynamicRel("startw");
  s->addDynamicRel("third3");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

