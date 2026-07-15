
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const0ea2ceb300766ec4d1be3dd0;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const8360e676291c5126c9176df7;
u64 v_conste79b501f6a169fb2f1065207;
u64 v_constecc9f619e1266e45b3382092;
u64 v_const1e18fc9f66815327677b4358;
u64 v_constc7eb065ad9e8f6183632be32;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("cd83cdc2");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const0ea2ceb300766ec4d1be3dd0 = db->encodeString("adjkey");
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const8360e676291c5126c9176df7 = db->encodeString("pairs");
  v_conste79b501f6a169fb2f1065207 = db->encodeString("adj7");
  v_constecc9f619e1266e45b3382092 = db->encodeString("seq_run.slog:15");
  v_const1e18fc9f66815327677b4358 = db->encodeString("seq_run.slog:29");
  v_constc7eb065ad9e8f6183632be32 = db->encodeString("seq_run.slog:23");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord142({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord143({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord144({1, 2, 0});
    
    r->addIndex<3>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord145({0, 1, 2});
    
    r->addIndex<3>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord146({1, 2, 0});
    
    r->addIndex<3>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord147({0, 1, 2});
    
    r->addIndex<3>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("pairs");
  if (r == 0) db->addRelation("pairs", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pairs");
      std::vector<u16> ord148({0, 1});
    
    r->addIndex<2>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("pairs"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord149({1, 2, 3, 0});
    
    r->addIndex<4>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord150({0, 1, 2, 3});
    
    r->addIndex<4>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord151({1, 2, 0});
    
    r->addIndex<3>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord152({0, 1, 2});
    
    r->addIndex<3>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord153({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord154({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord155({1, 2, 0});
    
    r->addIndex<3>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord156({0, 1, 2});
    
    r->addIndex<3>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mid");
  if (r == 0) db->addRelation("mid", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mid");
      std::vector<u16> ord157({0});
    
    r->addIndex<1>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("mid"), std::array<u16,1>{0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord158({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord159({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("key");
  if (r == 0) db->addRelation("key", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("key");
      std::vector<u16> ord160({0});
    
    r->addIndex<1>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("key"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord161({1, 2, 3, 0});
    
    r->addIndex<4>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord162({0, 1, 2, 3});
    
    r->addIndex<4>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord163({0});
    
    r->addIndex<1>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("doc");
  if (r == 0) db->addRelation("doc", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("doc");
      std::vector<u16> ord164({0});
    
    r->addIndex<1>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("doc"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord165({1, 2, 0});
    
    r->addIndex<3>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord166({0, 1, 2});
    
    r->addIndex<3>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("contains5");
  if (r == 0) db->addRelation("contains5", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("contains5");
      std::vector<u16> ord167({0});
    
    r->addIndex<1>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("contains5"), std::array<u16,1>{0}, b));
  r = db->getRelation("after12");
  if (r == 0) db->addRelation("after12", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("after12");
      std::vector<u16> ord168({0});
    
    r->addIndex<1>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("after12"), std::array<u16,1>{0}, b));
  r = db->getRelation("adjkey");
  if (r == 0) db->addRelation("adjkey", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("adjkey");
      std::vector<u16> ord169({0, 1});
    
    r->addIndex<2>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("adjkey"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("adj7");
  if (r == 0) db->addRelation("adj7", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("adj7");
      std::vector<u16> ord170({0});
    
    r->addIndex<1>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("adj7"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord171({1, 0});
    
    r->addIndex<2>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord172({0, 1});
    
    r->addIndex<2>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$seq_posdem");
  if (r == 0) db->addRelation("$seq_posdem", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_posdem");
      std::vector<u16> ord173({0, 1});
    
    r->addIndex<2>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("$seq_posdem"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("$seq_pos");
  if (r == 0) db->addRelation("$seq_pos", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_pos");
      std::vector<u16> ord174({1, 0, 2});
    
    r->addIndex<3>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
      std::vector<u16> ord175({1, 0, 2});
    
    r->addIndex<3>(ord175, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_pos"), std::array<u16,3>{1, 0, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord176({0, 2, 1});
    
    r->addIndex<3>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), true);
      std::vector<u16> ord177({0, 2, 1});
    
    r->addIndex<3>(ord177, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 2, 1}, b));
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("after12"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("contains5"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("doc"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("mid"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan div_by_zero __erre3qGm370 __errf8ms7371 __errf9BnR372) (body) (head (emit error (0) __erre3qGm370)) <internal>:1 #f)
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
  // (crule (pre (let _00024sqc74Cy97 constd4735e3a265e16eee03f5971) (let _00024sqc75V798 constd4735e3a265e16eee03f5971) (let _00024sqc0pL9101 const5feceb66ffc86f38d952786c) (let _00024sqc0gNY103 const7902699be42c8a8e46fbbb45) (let _00024sqc6lzG104 const6b86b273ff34fce19d6b804e) (let _00024sqo6bgO108 const7902699be42c8a8e46fbbb45) (let _00024sqc1qPq107 const5feceb66ffc86f38d952786c) (let _00024sqc2gfX109 const5feceb66ffc86f38d952786c) (let __trid7PAz140 constc7eb065ad9e8f6183632be32) (let __trel8K42141 conste79b501f6a169fb2f1065207) (let __tcol5o2O142 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 2 1) 1 _00024sqo6bgO108 _00024seq0 _00024sqo3P5P106) (body (join doc (0) 1 _00024seq0) (letp _00024sql30MI95 (aslst _00024seq0)) (let _00024sqp6S8199 (_0002d _00024sqo3P5P106 _00024sqc1qPq107)) (join $seq_pos (1 0 2) 3 _00024sqc75V798 _00024sql30MI95 _00024sqp6S8199) (let _00024sqn9zJ296 (llen _00024sql30MI95)) (cmp ge _00024sqn9zJ296 _00024sqc74Cy97) (let _00024sqp9uLe100 (_0002b _00024sqp6S8199 _00024sqc75V798)) (let _00024sqp45Uf110 (_0002d _00024sqn9zJ296 _00024sqc2gfX109)) (cmp le _00024sqp9uLe100 _00024sqp45Uf110) (let _00024sqp3qk2102 (_0002b _00024sqp6S8199 _00024sqc0pL9101)) (letp chk7lAC406 (lref _00024sql30MI95 _00024sqp3qk2102)) (eq _00024sqc0gNY103 chk7lAC406) (let _00024sqp2XKX105 (_0002b _00024sqp6S8199 _00024sqc6lzG104)) (letp y (lref _00024sql30MI95 _00024sqp2XKX105))) (head (tycheck y (accept int) __trid7PAz140 __trel8K42141 __tcol5o2O142 (1 2 3 4 0)) (emit adj7 (0) y)) seq_run.slog:23 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** docindex3;  slog::Index** $seq_posindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("adj7");
      std::vector<u16> ord6({0});
      slog::Relation* readrel7 = db->getRelation("adj7");
      head_index[1] = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({0, 2, 1});
      slog::Relation* readrel9 = db->getRelation("$seq_at");
      driver_index = readrel9->getIndex(ord8, true);
      std::vector<u16> ord10({0});
      slog::Relation* readrel11 = db->getRelation("doc");
      docindex3 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0, 2});
      slog::Relation* readrel13 = db->getRelation("$seq_pos");
      $seq_posindex4 = readrel13->getIndex(ord12, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c9 = v_const5feceb66ffc86f38d952786c;
      u64 v_c10 = v_const5feceb66ffc86f38d952786c;
      u64 v_c11 = v_constc7eb065ad9e8f6183632be32;
      u64 v_c12 = v_conste79b501f6a169fb2f1065207;
      u64 v_c13 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c8, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m14) {
        u64 v_c14 = m14[1];
        u64 v_c15 = m14[2];
        if (buckethash(v_c14) != bucket) return;
        slog::join_probe<1,1>(docindex3, std::array<u64,1>{v_c14}, [&](const std::array<u64,1>& m15) {
          bool ok16 = true;
          u64 v_c16 = _prim_aslst(db, v_c14, &ok16);
          if (!ok16) return;
          u64 v_c17 = _prim__0002d(db, v_c15, v_c9);
          if (v_c17 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:23"); return; }
          slog::join_probe<3,3>($seq_posindex4, std::array<u64,3>{v_c4, v_c16, v_c17}, [&](const std::array<u64,3>& m17) {
            u64 v_c18 = _prim_llen(db, v_c16);
            if (v_c18 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:23"); return; }
            u64 v_c19 = _prim_ge(db, v_c18, v_c3);
            if (v_c19 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:23"); return; }
            if (!v_c19) return;
            u64 v_c20 = _prim__0002b(db, v_c17, v_c4);
            if (v_c20 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:23"); return; }
            u64 v_c21 = _prim__0002d(db, v_c18, v_c10);
            if (v_c21 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:23"); return; }
            u64 v_c22 = _prim_le(db, v_c20, v_c21);
            if (v_c22 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:23"); return; }
            if (!v_c22) return;
            u64 v_c23 = _prim__0002b(db, v_c17, v_c5);
            if (v_c23 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:23"); return; }
            bool ok20 = true;
            u64 v_c24 = _prim_lref(db, v_c16, v_c23, &ok20);
            if (!ok20) return;
            if (v_c6 != v_c24) return;
            u64 v_c25 = _prim__0002b(db, v_c17, v_c7);
            if (v_c25 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:23"); return; }
            bool ok21 = true;
            u64 v_c26 = _prim_lref(db, v_c16, v_c25, &ok21);
            if (!ok21) return;
            ++_fires;
            if (!(is_int(v_c26)))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c11, v_c12, v_c13, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c26}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_run.slog:23", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask5* _cont = new ReadTask5(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre8QOk373 __errf8uEf374 __errf5w0A375) (body) (head (emit error (0) __erre8QOk373)) <internal>:1 #f)
  class ReadTask22 : public slog::Task
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
      std::vector<u16> ord23({0});
      slog::Relation* readrel24 = db->getRelation("error");
      head_index[0] = readrel24->getIndex(ord23, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask22(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask22* _cont = new ReadTask22(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask22(db,b), false);
  // (crule (pre) (scan int_overflow __erre3mNu376 __errf8fvD377 __errf9UFA378 __errf6Inp379) (body) (head (emit error (0) __erre3mNu376)) <internal>:1 #f)
  class ReadTask25 : public slog::Task
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
      std::vector<u16> ord26({0});
      slog::Relation* readrel27 = db->getRelation("error");
      head_index[0] = readrel27->getIndex(ord26, false);
      outer_rel = db->getRelation("int_overflow");
  
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
        u64 v_c30 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c32 = _t[2];
        u64 v_c33 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c30}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
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
  // (crule (pre) (scan type_mismatch __erre9aQU387 __errf7ZU7388 __errf1s9o389 __errf2TCj390 __errf6Mso391) (body) (head (emit error (0) __erre9aQU387)) <internal>:1 #f)
  class ReadTask28 : public slog::Task
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
      std::vector<u16> ord29({0});
      slog::Relation* readrel30 = db->getRelation("error");
      head_index[0] = readrel30->getIndex(ord29, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c38 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c34}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask28* _cont = new ReadTask28(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask28(db,b), false);
  // (crule (pre (let _00024sqc4uib69 constd4735e3a265e16eee03f5971) (let _00024sqc6SeU70 constd4735e3a265e16eee03f5971) (let _00024sqc7FuH73 const5feceb66ffc86f38d952786c) (let _00024sqc6BEz75 const6b86b273ff34fce19d6b804e) (let _00024sqc73W078 const5feceb66ffc86f38d952786c) (let _00024sqc2pb179 const5feceb66ffc86f38d952786c) (let __trid5zgX130 const1e18fc9f66815327677b4358) (let __trel5rvj131 const0ea2ceb300766ec4d1be3dd0) (let __tcol9cGc132 const5feceb66ffc86f38d952786c) (let __trel8IjY133 const0ea2ceb300766ec4d1be3dd0) (let __tcol4wm0134 const6b86b273ff34fce19d6b804e)) (scan $seq_at k _00024sqo2urv77 _00024seq0) (body (join key (0) 1 k) (join doc (0) 1 _00024seq0) (letp _00024sql1YF067 (aslst _00024seq0)) (let _00024sqp9Pv271 (_0002d _00024sqo2urv77 _00024sqc73W078)) (join $seq_pos (1 0 2) 3 _00024sqc6SeU70 _00024sql1YF067 _00024sqp9Pv271) (let _00024sqn0GiN68 (llen _00024sql1YF067)) (cmp ge _00024sqn0GiN68 _00024sqc4uib69) (let _00024sqp9kFX72 (_0002b _00024sqp9Pv271 _00024sqc6SeU70)) (let _00024sqp9OlP80 (_0002d _00024sqn0GiN68 _00024sqc2pb179)) (cmp le _00024sqp9kFX72 _00024sqp9OlP80) (let _00024sqp5TtQ74 (_0002b _00024sqp9Pv271 _00024sqc7FuH73)) (letp chk75AK408 (lref _00024sql1YF067 _00024sqp5TtQ74)) (eq k chk75AK408) (let _00024sqp1eg976 (_0002b _00024sqp9Pv271 _00024sqc6BEz75)) (letp y (lref _00024sql1YF067 _00024sqp1eg976))) (head (tycheck k (accept int) __trid5zgX130 __trel5rvj131 __tcol9cGc132 (1 2 3 4 0)) (tycheck y (accept int) __trid5zgX130 __trel8IjY133 __tcol4wm0134 (1 2 3 4 0)) (emit adjkey (0 1) k y)) seq_run.slog:29 #f)
  class ReadTask34 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** keyindex31;  slog::Index** docindex32;  slog::Index** $seq_posindex33;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("adjkey");
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("adjkey");
      head_index[2] = readrel36->getIndex(ord35, false);
      outer_rel = db->getRelation("$seq_at");
      std::vector<u16> ord37({0});
      slog::Relation* readrel38 = db->getRelation("key");
      keyindex31 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0});
      slog::Relation* readrel40 = db->getRelation("doc");
      docindex32 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 0, 2});
      slog::Relation* readrel42 = db->getRelation("$seq_pos");
      $seq_posindex33 = readrel42->getIndex(ord41, false);
  
    }
    ReadTask34(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_constd4735e3a265e16eee03f5971;
      u64 v_c40 = v_constd4735e3a265e16eee03f5971;
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
      u64 v_c42 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c43 = v_const5feceb66ffc86f38d952786c;
      u64 v_c44 = v_const5feceb66ffc86f38d952786c;
      u64 v_c45 = v_const1e18fc9f66815327677b4358;
      u64 v_c46 = v_const0ea2ceb300766ec4d1be3dd0;
      u64 v_c47 = v_const5feceb66ffc86f38d952786c;
      u64 v_c48 = v_const0ea2ceb300766ec4d1be3dd0;
      u64 v_c49 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c50 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c14 = _t[2];
        slog::join_probe<1,1>(keyindex31, std::array<u64,1>{v_c50}, [&](const std::array<u64,1>& m43) {
          slog::join_probe<1,1>(docindex32, std::array<u64,1>{v_c14}, [&](const std::array<u64,1>& m44) {
            bool ok45 = true;
            u64 v_c52 = _prim_aslst(db, v_c14, &ok45);
            if (!ok45) return;
            u64 v_c53 = _prim__0002d(db, v_c51, v_c43);
            if (v_c53 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:29"); return; }
            slog::join_probe<3,3>($seq_posindex33, std::array<u64,3>{v_c40, v_c52, v_c53}, [&](const std::array<u64,3>& m46) {
              u64 v_c54 = _prim_llen(db, v_c52);
              if (v_c54 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:29"); return; }
              u64 v_c55 = _prim_ge(db, v_c54, v_c39);
              if (v_c55 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:29"); return; }
              if (!v_c55) return;
              u64 v_c56 = _prim__0002b(db, v_c53, v_c40);
              if (v_c56 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:29"); return; }
              u64 v_c57 = _prim__0002d(db, v_c54, v_c44);
              if (v_c57 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:29"); return; }
              u64 v_c58 = _prim_le(db, v_c56, v_c57);
              if (v_c58 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:29"); return; }
              if (!v_c58) return;
              u64 v_c59 = _prim__0002b(db, v_c53, v_c41);
              if (v_c59 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:29"); return; }
              bool ok49 = true;
              u64 v_c60 = _prim_lref(db, v_c52, v_c59, &ok49);
              if (!ok49) return;
              if (v_c50 != v_c60) return;
              u64 v_c61 = _prim__0002b(db, v_c53, v_c42);
              if (v_c61 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:29"); return; }
              bool ok50 = true;
              u64 v_c26 = _prim_lref(db, v_c52, v_c61, &ok50);
              if (!ok50) return;
              ++_fires;
              if (!(is_int(v_c50)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c45, v_c46, v_c47, v_c50}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              if (!(is_int(v_c26)))
              {
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c45, v_c48, v_c49, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c50, v_c26}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("seq_run.slog:29", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask34* _cont = new ReadTask34(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask34(db,b), false);
  // (crule (pre (let _00024sqc1keP84 constd4735e3a265e16eee03f5971) (let _00024sqc3fTm85 constd4735e3a265e16eee03f5971) (let _00024sqc2dsp88 const5feceb66ffc86f38d952786c) (let _00024sqc4PJn90 const6b86b273ff34fce19d6b804e) (let _00024sqc0Pbd92 const5feceb66ffc86f38d952786c) (let __trid786T135 constecc9f619e1266e45b3382092) (let __trel9dTb136 const8360e676291c5126c9176df7) (let __tcol0r4F137 const5feceb66ffc86f38d952786c) (let __trel7V9Y138 const8360e676291c5126c9176df7) (let __tcol7jSq139 const6b86b273ff34fce19d6b804e)) (probe $seq_pos (1 0 2) 1 _00024sqc3fTm85 _00024sql8eNF82 _00024sqp0oj086) (body (join doc (0) 0 _00024seq0) (letp chk3vo5407 (aslst _00024seq0)) (eq _00024sql8eNF82 chk3vo5407) (let _00024sqn6Eeu83 (llen _00024sql8eNF82)) (cmp ge _00024sqn6Eeu83 _00024sqc1keP84) (let _00024sqp5j0z87 (_0002b _00024sqp0oj086 _00024sqc3fTm85)) (let _00024sqp9ZTh93 (_0002d _00024sqn6Eeu83 _00024sqc0Pbd92)) (cmp le _00024sqp5j0z87 _00024sqp9ZTh93) (let _00024sqp8TIR89 (_0002b _00024sqp0oj086 _00024sqc2dsp88)) (letp x (lref _00024sql8eNF82 _00024sqp8TIR89)) (let _00024sqp46BD91 (_0002b _00024sqp0oj086 _00024sqc4PJn90)) (letp y (lref _00024sql8eNF82 _00024sqp46BD91))) (head (tycheck x (accept int) __trid786T135 __trel9dTb136 __tcol0r4F137 (1 2 3 4 0)) (tycheck y (accept int) __trid786T135 __trel7V9Y138 __tcol7jSq139 (1 2 3 4 0)) (emit pairs (0 1) x y)) seq_run.slog:15 #f)
  class ReadTask52 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** docindex51;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("pairs");
      std::vector<u16> ord53({0, 1});
      slog::Relation* readrel54 = db->getRelation("pairs");
      head_index[2] = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 0, 2});
      slog::Relation* readrel56 = db->getRelation("$seq_pos");
      driver_index = readrel56->getIndex(ord55, true);
      std::vector<u16> ord57({0});
      slog::Relation* readrel58 = db->getRelation("doc");
      docindex51 = readrel58->getIndex(ord57, false);
  
    }
    ReadTask52(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd4735e3a265e16eee03f5971;
      u64 v_c64 = v_const5feceb66ffc86f38d952786c;
      u64 v_c65 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
      u64 v_c67 = v_constecc9f619e1266e45b3382092;
      u64 v_c68 = v_const8360e676291c5126c9176df7;
      u64 v_c69 = v_const5feceb66ffc86f38d952786c;
      u64 v_c70 = v_const8360e676291c5126c9176df7;
      u64 v_c71 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c63, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m59) {
        u64 v_c72 = m59[1];
        u64 v_c73 = m59[2];
        if (buckethash(v_c72) != bucket) return;
        slog::join_all<1>(docindex51, [&](const std::array<u64,1>& m60) {
          u64 v_c14 = m60[0];
          bool ok61 = true;
          u64 v_c74 = _prim_aslst(db, v_c14, &ok61);
          if (!ok61) return;
          if (v_c72 != v_c74) return;
          u64 v_c75 = _prim_llen(db, v_c72);
          if (v_c75 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:15"); return; }
          u64 v_c76 = _prim_ge(db, v_c75, v_c62);
          if (v_c76 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:15"); return; }
          if (!v_c76) return;
          u64 v_c77 = _prim__0002b(db, v_c73, v_c63);
          if (v_c77 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:15"); return; }
          u64 v_c78 = _prim__0002d(db, v_c75, v_c66);
          if (v_c78 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:15"); return; }
          u64 v_c79 = _prim_le(db, v_c77, v_c78);
          if (v_c79 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:15"); return; }
          if (!v_c79) return;
          u64 v_c80 = _prim__0002b(db, v_c73, v_c64);
          if (v_c80 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:15"); return; }
          bool ok64 = true;
          u64 v_c81 = _prim_lref(db, v_c72, v_c80, &ok64);
          if (!ok64) return;
          u64 v_c82 = _prim__0002b(db, v_c73, v_c65);
          if (v_c82 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:15"); return; }
          bool ok65 = true;
          u64 v_c26 = _prim_lref(db, v_c72, v_c82, &ok65);
          if (!ok65) return;
          ++_fires;
          if (!(is_int(v_c81)))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c67, v_c68, v_c69, v_c81}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          if (!(is_int(v_c26)))
          {
            slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c67, v_c70, v_c71, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c81, v_c26}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("seq_run.slog:15", "all:$seq_pos", _fires);
  
      if (!_done)
      {
        ReadTask52* _cont = new ReadTask52(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask52(db,b), true);
  // (crule (pre) (scan mpz_overflow __erre7XeT392 __errf9BgC393 __errf5DYf394 __errf6HzG395 __errf28SF396) (body) (head (emit error (0) __erre7XeT392)) <internal>:1 #f)
  class ReadTask66 : public slog::Task
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
      std::vector<u16> ord67({0});
      slog::Relation* readrel68 = db->getRelation("error");
      head_index[0] = readrel68->getIndex(ord67, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask66(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c83 = _t[0];
        u64 v_c84 = _t[1];
        u64 v_c85 = _t[2];
        u64 v_c86 = _t[3];
        u64 v_c87 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c83}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask66* _cont = new ReadTask66(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask66(db,b), false);
  // (crule (pre (let _00024sqc1tye43 constd4735e3a265e16eee03f5971) (let _00024sqc35ey44 constd4735e3a265e16eee03f5971) (let _00024sqc94Jt47 const5feceb66ffc86f38d952786c) (let _00024sqc3qZm49 const6b86b273ff34fce19d6b804e) (let _00024sqc2NV050 const6b86b273ff34fce19d6b804e) (let _00024sqc4Uki52 constd4735e3a265e16eee03f5971) (let _00024sqo4qMW55 const6b86b273ff34fce19d6b804e) (let _00024sqc8Htd54 const5feceb66ffc86f38d952786c) (let _00024sqo8tRD58 constd4735e3a265e16eee03f5971) (let _00024sqc0bKO57 const6b86b273ff34fce19d6b804e) (let _00024sqc3qzZ59 const5feceb66ffc86f38d952786c) (let _00024sqc3iJW61 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 2 1) 1 _00024sqo8tRD58 _00024seq0 _00024sqo3I3L56) (body (exists doc (0) 1 _00024seq0) (exists $seq_pos (1 0 2) 1 _00024sqc35ey44) (join $seq_at (0 2 1) 2 _00024sqo4qMW55 _00024seq0 _00024sqo8kBF53) (join doc (0) 1 _00024seq0) (letp _00024sql60uF41 (aslst _00024seq0)) (let _00024sqp8W1W45 (_0002d _00024sqo8kBF53 _00024sqc8Htd54)) (join $seq_pos (1 0 2) 3 _00024sqc35ey44 _00024sql60uF41 _00024sqp8W1W45) (let _00024sqn6PFF42 (llen _00024sql60uF41)) (cmp ge _00024sqn6PFF42 _00024sqc1tye43) (let _00024sqp15bl46 (_0002b _00024sqp8W1W45 _00024sqc35ey44)) (let _00024sqp2rtf60 (_0002d _00024sqn6PFF42 _00024sqc3qzZ59)) (cmp le _00024sqp15bl46 _00024sqp2rtf60) (let _00024sqp47hV48 (_0002b _00024sqp8W1W45 _00024sqc94Jt47)) (letp chk2FCo403 (lref _00024sql60uF41 _00024sqp47hV48)) (eq _00024sqc3qZm49 chk2FCo403) (let _00024sqp7yuZ51 (_0002b _00024sqp8W1W45 _00024sqc2NV050)) (letp chk2EAs404 (lref _00024sql60uF41 _00024sqp7yuZ51)) (eq _00024sqc4Uki52 chk2EAs404) (let chk2c0D405 (_0002d _00024sqo3I3L56 _00024sqc0bKO57)) (eq _00024sqp8W1W45 chk2c0D405) (let _00024sqp58GE62 (_0002d _00024sqn6PFF42 _00024sqc3iJW61)) (let ys (lslice _00024sql60uF41 _00024sqp15bl46 _00024sqp58GE62))) (head (emit after12 (0) ys)) seq_run.slog:16 #f)
  class ReadTask74 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** docindex69;  slog::Index** $seq_posindex70;  slog::Index** $seq_atindex71;  slog::Index** docindex72;  slog::Index** $seq_posindex73;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("after12");
      std::vector<u16> ord75({0});
      slog::Relation* readrel76 = db->getRelation("after12");
      head_index[0] = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({0, 2, 1});
      slog::Relation* readrel78 = db->getRelation("$seq_at");
      driver_index = readrel78->getIndex(ord77, true);
      std::vector<u16> ord79({0});
      slog::Relation* readrel80 = db->getRelation("doc");
      docindex69 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({1, 0, 2});
      slog::Relation* readrel82 = db->getRelation("$seq_pos");
      $seq_posindex70 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({0, 2, 1});
      slog::Relation* readrel84 = db->getRelation("$seq_at");
      $seq_atindex71 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0});
      slog::Relation* readrel86 = db->getRelation("doc");
      docindex72 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 0, 2});
      slog::Relation* readrel88 = db->getRelation("$seq_pos");
      $seq_posindex73 = readrel88->getIndex(ord87, false);
  
    }
    ReadTask74(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_constd4735e3a265e16eee03f5971;
      u64 v_c89 = v_constd4735e3a265e16eee03f5971;
      u64 v_c90 = v_const5feceb66ffc86f38d952786c;
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c92 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c93 = v_constd4735e3a265e16eee03f5971;
      u64 v_c94 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
      u64 v_c96 = v_constd4735e3a265e16eee03f5971;
      u64 v_c97 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
      u64 v_c99 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c96, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m89) {
        u64 v_c14 = m89[1];
        u64 v_c100 = m89[2];
        if (buckethash(v_c14) != bucket) return;
        if (!slog::exists_probe<1,1>(docindex69, std::array<u64,1>{v_c14})) return;
        if (!slog::exists_probe<3,1>($seq_posindex70, std::array<u64,3>{v_c89, 0, 0})) return;
        slog::join_probe<3,2>($seq_atindex71, std::array<u64,3>{v_c94, v_c14, 0}, [&](const std::array<u64,3>& m90) {
          u64 v_c101 = m90[2];
          slog::join_probe<1,1>(docindex72, std::array<u64,1>{v_c14}, [&](const std::array<u64,1>& m91) {
            bool ok92 = true;
            u64 v_c102 = _prim_aslst(db, v_c14, &ok92);
            if (!ok92) return;
            u64 v_c103 = _prim__0002d(db, v_c101, v_c95);
            if (v_c103 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
            slog::join_probe<3,3>($seq_posindex73, std::array<u64,3>{v_c89, v_c102, v_c103}, [&](const std::array<u64,3>& m93) {
              u64 v_c104 = _prim_llen(db, v_c102);
              if (v_c104 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              u64 v_c105 = _prim_ge(db, v_c104, v_c88);
              if (v_c105 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              if (!v_c105) return;
              u64 v_c106 = _prim__0002b(db, v_c103, v_c89);
              if (v_c106 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              u64 v_c107 = _prim__0002d(db, v_c104, v_c98);
              if (v_c107 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              u64 v_c108 = _prim_le(db, v_c106, v_c107);
              if (v_c108 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              if (!v_c108) return;
              u64 v_c109 = _prim__0002b(db, v_c103, v_c90);
              if (v_c109 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              bool ok96 = true;
              u64 v_c110 = _prim_lref(db, v_c102, v_c109, &ok96);
              if (!ok96) return;
              if (v_c91 != v_c110) return;
              u64 v_c111 = _prim__0002b(db, v_c103, v_c92);
              if (v_c111 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              bool ok97 = true;
              u64 v_c112 = _prim_lref(db, v_c102, v_c111, &ok97);
              if (!ok97) return;
              if (v_c93 != v_c112) return;
              u64 v_c113 = _prim__0002d(db, v_c100, v_c97);
              if (v_c113 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              if (v_c103 != v_c113) return;
              u64 v_c114 = _prim__0002d(db, v_c104, v_c99);
              if (v_c114 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              u64 v_c115 = _prim_lslice(db, v_c102, v_c106, v_c114);
              if (v_c115 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c115}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_run.slog:16", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask74* _cont = new ReadTask74(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask74(db,b), false);
  // (crule (pre (let _00024sqc1tye43 constd4735e3a265e16eee03f5971) (let _00024sqc35ey44 constd4735e3a265e16eee03f5971) (let _00024sqc94Jt47 const5feceb66ffc86f38d952786c) (let _00024sqc3qZm49 const6b86b273ff34fce19d6b804e) (let _00024sqc2NV050 const6b86b273ff34fce19d6b804e) (let _00024sqc4Uki52 constd4735e3a265e16eee03f5971) (let _00024sqo4qMW55 const6b86b273ff34fce19d6b804e) (let _00024sqc8Htd54 const5feceb66ffc86f38d952786c) (let _00024sqo8tRD58 constd4735e3a265e16eee03f5971) (let _00024sqc0bKO57 const6b86b273ff34fce19d6b804e) (let _00024sqc3qzZ59 const5feceb66ffc86f38d952786c) (let _00024sqc3iJW61 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 2 1) 1 _00024sqo4qMW55 _00024seq0 _00024sqo8kBF53) (body (exists doc (0) 1 _00024seq0) (exists $seq_pos (1 0 2) 1 _00024sqc35ey44) (join-old $seq_at (0 2 1) 2 (0 2 1) _00024sqo8tRD58 _00024seq0 _00024sqo3I3L56) (join doc (0) 1 _00024seq0) (letp _00024sql60uF41 (aslst _00024seq0)) (let _00024sqp8W1W45 (_0002d _00024sqo8kBF53 _00024sqc8Htd54)) (join $seq_pos (1 0 2) 3 _00024sqc35ey44 _00024sql60uF41 _00024sqp8W1W45) (let _00024sqn6PFF42 (llen _00024sql60uF41)) (cmp ge _00024sqn6PFF42 _00024sqc1tye43) (let _00024sqp15bl46 (_0002b _00024sqp8W1W45 _00024sqc35ey44)) (let _00024sqp2rtf60 (_0002d _00024sqn6PFF42 _00024sqc3qzZ59)) (cmp le _00024sqp15bl46 _00024sqp2rtf60) (let _00024sqp47hV48 (_0002b _00024sqp8W1W45 _00024sqc94Jt47)) (letp chk3VOx400 (lref _00024sql60uF41 _00024sqp47hV48)) (eq _00024sqc3qZm49 chk3VOx400) (let _00024sqp7yuZ51 (_0002b _00024sqp8W1W45 _00024sqc2NV050)) (letp chk1nI3401 (lref _00024sql60uF41 _00024sqp7yuZ51)) (eq _00024sqc4Uki52 chk1nI3401) (let chk2pKQ402 (_0002d _00024sqo3I3L56 _00024sqc0bKO57)) (eq _00024sqp8W1W45 chk2pKQ402) (let _00024sqp58GE62 (_0002d _00024sqn6PFF42 _00024sqc3iJW61)) (let ys (lslice _00024sql60uF41 _00024sqp15bl46 _00024sqp58GE62))) (head (emit after12 (0) ys)) seq_run.slog:16 #f)
  class ReadTask104 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** docindex98;  slog::Index** $seq_posindex99;  slog::Index** $seq_atindex100;  slog::Index** docindex101;  slog::Index** $seq_posindex102;  slog::Index** $seq_atdelta103;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("after12");
      std::vector<u16> ord105({0});
      slog::Relation* readrel106 = db->getRelation("after12");
      head_index[0] = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 2, 1});
      slog::Relation* readrel108 = db->getRelation("$seq_at");
      driver_index = readrel108->getIndex(ord107, true);
      std::vector<u16> ord109({0});
      slog::Relation* readrel110 = db->getRelation("doc");
      docindex98 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 0, 2});
      slog::Relation* readrel112 = db->getRelation("$seq_pos");
      $seq_posindex99 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({0, 2, 1});
      slog::Relation* readrel114 = db->getRelation("$seq_at");
      $seq_atindex100 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 2, 1});
      slog::Relation* readrel116 = db->getRelation("$seq_at");
      $seq_atdelta103 = readrel116->getIndex(ord115, true);
      std::vector<u16> ord117({0});
      slog::Relation* readrel118 = db->getRelation("doc");
      docindex101 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({1, 0, 2});
      slog::Relation* readrel120 = db->getRelation("$seq_pos");
      $seq_posindex102 = readrel120->getIndex(ord119, false);
  
    }
    ReadTask104(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_constd4735e3a265e16eee03f5971;
      u64 v_c89 = v_constd4735e3a265e16eee03f5971;
      u64 v_c90 = v_const5feceb66ffc86f38d952786c;
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c92 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c93 = v_constd4735e3a265e16eee03f5971;
      u64 v_c94 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
      u64 v_c96 = v_constd4735e3a265e16eee03f5971;
      u64 v_c97 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
      u64 v_c99 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c94, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m121) {
        u64 v_c14 = m121[1];
        u64 v_c101 = m121[2];
        if (buckethash(v_c14) != bucket) return;
        if (!slog::exists_probe<1,1>(docindex98, std::array<u64,1>{v_c14})) return;
        if (!slog::exists_probe<3,1>($seq_posindex99, std::array<u64,3>{v_c89, 0, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex100, $seq_atdelta103, std::array<u64,3>{v_c96, v_c14, 0}, [&](const std::array<u64,3>& m122) {
          u64 v_c100 = m122[2];
          slog::join_probe<1,1>(docindex101, std::array<u64,1>{v_c14}, [&](const std::array<u64,1>& m123) {
            bool ok124 = true;
            u64 v_c102 = _prim_aslst(db, v_c14, &ok124);
            if (!ok124) return;
            u64 v_c103 = _prim__0002d(db, v_c101, v_c95);
            if (v_c103 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
            slog::join_probe<3,3>($seq_posindex102, std::array<u64,3>{v_c89, v_c102, v_c103}, [&](const std::array<u64,3>& m125) {
              u64 v_c104 = _prim_llen(db, v_c102);
              if (v_c104 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              u64 v_c116 = _prim_ge(db, v_c104, v_c88);
              if (v_c116 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              if (!v_c116) return;
              u64 v_c106 = _prim__0002b(db, v_c103, v_c89);
              if (v_c106 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              u64 v_c107 = _prim__0002d(db, v_c104, v_c98);
              if (v_c107 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              u64 v_c117 = _prim_le(db, v_c106, v_c107);
              if (v_c117 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              if (!v_c117) return;
              u64 v_c109 = _prim__0002b(db, v_c103, v_c90);
              if (v_c109 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              bool ok128 = true;
              u64 v_c118 = _prim_lref(db, v_c102, v_c109, &ok128);
              if (!ok128) return;
              if (v_c91 != v_c118) return;
              u64 v_c111 = _prim__0002b(db, v_c103, v_c92);
              if (v_c111 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              bool ok129 = true;
              u64 v_c119 = _prim_lref(db, v_c102, v_c111, &ok129);
              if (!ok129) return;
              if (v_c93 != v_c119) return;
              u64 v_c120 = _prim__0002d(db, v_c100, v_c97);
              if (v_c120 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              if (v_c103 != v_c120) return;
              u64 v_c114 = _prim__0002d(db, v_c104, v_c99);
              if (v_c114 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              u64 v_c115 = _prim_lslice(db, v_c102, v_c106, v_c114);
              if (v_c115 == slog_error) { slog::emit_pending_error(db, "seq_run.slog:16"); return; }
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c115}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_run.slog:16", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask104* _cont = new ReadTask104(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask104(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre2ARv397 __errf0an9398 __errf3HyP399) (body) (head (emit error (0) __erre2ARv397)) <internal>:1 #f)
  class ReadTask130 : public slog::Task
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
      std::vector<u16> ord131({0});
      slog::Relation* readrel132 = db->getRelation("error");
      head_index[0] = readrel132->getIndex(ord131, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask130(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c121 = _t[0];
        u64 v_c122 = _t[1];
        u64 v_c123 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c121}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask130* _cont = new ReadTask130(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask130(db,b), false);
  // (crule (pre) (scan nan_result __erre6QS9380 __errf4aXl381 __errf42lI382 __errf1w7v383) (body) (head (emit error (0) __erre6QS9380)) <internal>:1 #f)
  class ReadTask133 : public slog::Task
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
      std::vector<u16> ord134({0});
      slog::Relation* readrel135 = db->getRelation("error");
      head_index[0] = readrel135->getIndex(ord134, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask133(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c124 = _t[0];
        u64 v_c125 = _t[1];
        u64 v_c126 = _t[2];
        u64 v_c127 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c124}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask133* _cont = new ReadTask133(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask133(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre6pGc365 __errf6B5J366 __errf2jGa367 __errf9XyI368 __errf38SB369) (body) (head (emit error (0) __erre6pGc365)) <internal>:1 #f)
  class ReadTask136 : public slog::Task
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
      std::vector<u16> ord137({0});
      slog::Relation* readrel138 = db->getRelation("error");
      head_index[0] = readrel138->getIndex(ord137, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask136(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c128 = _t[0];
        u64 v_c129 = _t[1];
        u64 v_c130 = _t[2];
        u64 v_c131 = _t[3];
        u64 v_c132 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c128}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask136* _cont = new ReadTask136(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask136(db,b), false);
  // (crule (pre) (scan toint_range __erre9Nj3384 __errf2MKM385 __errf3UOQ386) (body) (head (emit error (0) __erre9Nj3384)) <internal>:1 #f)
  class ReadTask139 : public slog::Task
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
      std::vector<u16> ord140({0});
      slog::Relation* readrel141 = db->getRelation("error");
      head_index[0] = readrel141->getIndex(ord140, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask139(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c133 = _t[0];
        u64 v_c134 = _t[1];
        u64 v_c135 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c133}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask139* _cont = new ReadTask139(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask139(db,b), false);
  s->addReadRel("$seq_at");
  s->addReadRel("$seq_pos");
  s->addReadRel("div_by_zero");
  s->addReadRel("doc");
  s->addReadRel("int_overflow");
  s->addReadRel("key");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("adj7");
  s->addDynamicRel("adjkey");
  s->addDynamicRel("after12");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("pairs");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

