
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("bcc03fd9");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord123({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord124({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord125({1, 2, 0});
    
    r->addIndex<3>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord126({0, 1, 2});
    
    r->addIndex<3>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp9mlh341");
  if (r == 0) db->addTempRelation("temp9mlh341", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3USn342");
  if (r == 0) db->addTempRelation("temp3USn342", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1otF343");
  if (r == 0) db->addTempRelation("temp1otF343", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1SxD339");
  if (r == 0) db->addTempRelation("temp1SxD339", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord127({1, 2, 0});
    
    r->addIndex<3>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord128({0, 1, 2});
    
    r->addIndex<3>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord129({1, 2, 3, 0});
    
    r->addIndex<4>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord130({0, 1, 2, 3});
    
    r->addIndex<4>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord131({1, 2, 0});
    
    r->addIndex<3>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord132({0, 1, 2});
    
    r->addIndex<3>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord133({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord134({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord135({1, 2, 0});
    
    r->addIndex<3>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord136({0, 1, 2});
    
    r->addIndex<3>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("map_ans");
  if (r == 0) db->addRelation("map_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map_ans");
      std::vector<u16> ord137({0, 1});
    
    r->addIndex<2>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("map_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("map");
  if (r == 0) db->addStruct("map", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map");
      std::vector<u16> ord138({1, 2, 0});
    
    r->addIndex<3>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord139({0, 1, 2});
    
    r->addIndex<3>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord140({2, 0, 1});
    
    r->addIndex<3>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("map"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord141({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord142({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord143({1, 2, 3, 0});
    
    r->addIndex<4>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord144({0, 1, 2, 3});
    
    r->addIndex<4>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("input");
  if (r == 0) db->addRelation("input", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("input");
      std::vector<u16> ord145({0});
    
    r->addIndex<1>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("input"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord146({0});
    
    r->addIndex<1>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("doubled");
  if (r == 0) db->addRelation("doubled", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("doubled");
      std::vector<u16> ord147({0});
    
    r->addIndex<1>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("doubled"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord148({1, 2, 0});
    
    r->addIndex<3>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord149({0, 1, 2});
    
    r->addIndex<3>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bumped");
  if (r == 0) db->addRelation("bumped", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bumped");
      std::vector<u16> ord150({0});
    
    r->addIndex<1>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("bumped"), std::array<u16,1>{0}, b));
  r = db->getRelation("apply_ans");
  if (r == 0) db->addRelation("apply_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply_ans");
      std::vector<u16> ord151({0, 1});
    
    r->addIndex<2>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("apply_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("apply");
  if (r == 0) db->addStruct("apply", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply");
      std::vector<u16> ord152({1, 2, 0});
    
    r->addIndex<3>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord153({0, 1, 2});
    
    r->addIndex<3>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord154({2, 0, 1});
    
    r->addIndex<3>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("apply"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("addk");
  if (r == 0) db->addStruct("addk", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("addk");
      std::vector<u16> ord155({1, 0});
    
    r->addIndex<2>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord156({0, 1});
    
    r->addIndex<2>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("addk"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord157({1, 0});
    
    r->addIndex<2>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord158({0, 1});
    
    r->addIndex<2>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup94786x12x0x0x0");
  if (r == 0) db->addRelation("$sup94786x12x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup94786x12x0x0x0");
      std::vector<u16> ord159({2, 4, 0, 1, 3});
    
    r->addIndex<5>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 4, 0, 1, 3}, false, b), true);
      std::vector<u16> ord160({0, 3, 4, 1, 2});
    
    r->addIndex<5>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 3, 4, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup94786x12x0x0x0"), std::array<u16,5>{2, 4, 0, 1, 3}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord161({1, 0, 2});
    
    r->addIndex<3>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
      std::vector<u16> ord162({1, 0, 2});
    
    r->addIndex<3>(ord162, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{1, 0, 2}, b));
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("bumped"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("doubled"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("input"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("map"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("map_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan temp9mlh341 __t22v01 __t9nRP4 y ys) (body (let __t1oIm2 (lpush __t22v01 y))) (head (emit-temp temp3USn342 __t1oIm2 __t9nRP4 ys)) dem_brackets.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp3USn342");
      outer_rel = db->getRelation("temp9mlh341");
  
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
        u64 v_c3 = _t[3];
        u64 v_c4 = _prim_lpush(db, v_c0, v_c2);
        if (v_c4 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c4, v_c1, v_c3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_brackets.slog:13", "delta:temp9mlh341", _fires);
  
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
  // (crule (pre) (scan type_mismatch __erre2pbE326 __errf2EuC327 __errf26DS328 __errf1fF5329 __errf3p5Y330) (body) (head (emit error (0) __erre2pbE326)) <internal>:1 #f)
  class ReadTask1 : public slog::Task
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
      std::vector<u16> ord2({0});
      slog::Relation* readrel3 = db->getRelation("error");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask1* _cont = new ReadTask1(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1(db,b), false);
  // (crule (pre (let _00024sqc34Ys43 const5feceb66ffc86f38d952786c) (let __t18ST17 (lempty))) (scan map __t4azW18 f _00024seq0) (body (letp _00024sql25js41 (aslst _00024seq0)) (let chk9uhZ340 (llen _00024sql25js41)) (eq _00024sqc34Ys43 chk9uhZ340)) (head (emit-temp temp1SxD339 __t18ST17 __t4azW18)) dem_brackets.slog:12 #f)
  class ReadTask4 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1SxD339");
      outer_rel = db->getRelation("map");
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_const5feceb66ffc86f38d952786c;
      u64 v_c11 = _prim_lempty(db);
      if (v_c11 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:12"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c12 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c14 = _t[2];
        bool ok5 = true;
        u64 v_c15 = _prim_aslst(db, v_c14, &ok5);
        if (!ok5) return;
        u64 v_c16 = _prim_llen(db, v_c15);
        if (v_c16 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:12"); return; }
        if (v_c10 != v_c16) return;
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c12});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_brackets.slog:12", "all:map", _fires);
  
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
  // (crule (pre) (scan temp3USn342 __t1oIm2 __t9nRP4 ys) (body (let __t6q863 (lcat __t1oIm2 ys))) (head (emit-temp temp1otF343 __t6q863 __t9nRP4)) dem_brackets.slog:13 #f)
  class ReadTask6 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1otF343");
      outer_rel = db->getRelation("temp3USn342");
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c17 = _prim_lcat(db, v_c4, v_c3);
        if (v_c17 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c17, v_c1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_brackets.slog:13", "delta:temp3USn342", _fires);
  
      if (!_done)
      {
        ReadTask6* _cont = new ReadTask6(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask6(db,b), false);
  // (crule (pre) (scan temp1otF343 __t6q863 __t9nRP4) (body) (head (emit map_ans (0 1) __t9nRP4 __t6q863)) dem_brackets.slog:13 #f)
  class ReadTask7 : public slog::Task
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
      head_rel[0] = db->getRelation("map_ans");
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("map_ans");
      head_index[0] = readrel9->getIndex(ord8, false);
      outer_rel = db->getRelation("temp1otF343");
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[0];
        u64 v_c1 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c17}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_brackets.slog:13", "delta:temp1otF343", _fires);
  
      if (!_done)
      {
        ReadTask7* _cont = new ReadTask7(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask7(db,b), false);
  // (crule (pre) (scan temp1SxD339 __t18ST17 __t4azW18) (body) (head (emit map_ans (0 1) __t4azW18 __t18ST17)) dem_brackets.slog:12 #f)
  class ReadTask10 : public slog::Task
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
      head_rel[0] = db->getRelation("map_ans");
      std::vector<u16> ord11({0, 1});
      slog::Relation* readrel12 = db->getRelation("map_ans");
      head_index[0] = readrel12->getIndex(ord11, false);
      outer_rel = db->getRelation("temp1SxD339");
  
    }
    ReadTask10(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c11}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_brackets.slog:12", "delta:temp1SxD339", _fires);
  
      if (!_done)
      {
        ReadTask10* _cont = new ReadTask10(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask10(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre53vm336 __errf9yea337 __errf5EBV338) (body) (head (emit error (0) __erre53vm336)) <internal>:1 #f)
  class ReadTask13 : public slog::Task
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
      std::vector<u16> ord14({0});
      slog::Relation* readrel15 = db->getRelation("error");
      head_index[0] = readrel15->getIndex(ord14, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask13(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c20 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask13* _cont = new ReadTask13(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask13(db,b), false);
  // (crule (pre) (scan div_by_zero __erre9lWx309 __errf5QUg310 __errf0yDq311) (body) (head (emit error (0) __erre9lWx309)) <internal>:1 #f)
  class ReadTask16 : public slog::Task
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
      std::vector<u16> ord17({0});
      slog::Relation* readrel18 = db->getRelation("error");
      head_index[0] = readrel18->getIndex(ord17, false);
      outer_rel = db->getRelation("div_by_zero");
  
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
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c23 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre69Tw312 __errf3Z62313 __errf0GNl314) (body) (head (emit error (0) __erre69Tw312)) <internal>:1 #f)
  class ReadTask19 : public slog::Task
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
      std::vector<u16> ord20({0});
      slog::Relation* readrel21 = db->getRelation("error");
      head_index[0] = readrel21->getIndex(ord20, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask19(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c24 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c26 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask19* _cont = new ReadTask19(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask19(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre1KR7331 __errf7LdJ332 __errf8BOh333 __errf3tqH334 __errf5VLj335) (body) (head (emit error (0) __erre1KR7331)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c30 = _t[3];
        u64 v_c31 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre6528315 __errf8n2w316 __errf99sU317 __errf8JnI318) (body) (head (emit error (0) __erre6528315)) <internal>:1 #f)
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
        u64 v_c32 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c35 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c32}, std::array<u16,1>{0});
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
  // (crule (pre) (scan nan_result __erre9iB0319 __errf7rya320 __errf8Vnt321 __errf7fwp322) (body) (head (emit error (0) __erre9iB0319)) <internal>:1 #f)
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
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c36 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c38 = _t[2];
        u64 v_c39 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c36}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre) (scan toint_range __erre5w9I323 __errf5TyS324 __errf917u325) (body) (head (emit error (0) __erre5w9I323)) <internal>:1 #f)
  class ReadTask31 : public slog::Task
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
      std::vector<u16> ord32({0});
      slog::Relation* readrel33 = db->getRelation("error");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask31(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c40 = _t[0];
        u64 v_c41 = _t[1];
        u64 v_c42 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c40}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask31* _cont = new ReadTask31(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask31(db,b), false);
  // (crule (pre (let _00024sqc5ANZ46 const6b86b273ff34fce19d6b804e) (let _00024sqc9K0e47 const5feceb66ffc86f38d952786c) (let _00024sqc2wUx48 const6b86b273ff34fce19d6b804e) (let _00024sqc43TV49 const5feceb66ffc86f38d952786c) (let _00024sqo0ApU54 const5feceb66ffc86f38d952786c) (let __t22v01 (lempty))) (scan map_ans __t8ERN6 ys) (body (exists $seq_at (1 0 2) 1 _00024sqo0ApU54) (join map (0 1 2) 1 __t8ERN6 f xs) (exists map (1 2 0) 1 f) (exists apply (1 2 0) 1 f) (join $sup94786x12x0x0x0 (2 4 0 1 3) 2 f xs _00024seq0 __t9nRP4 x) (join map (1 2 0) 3 f _00024seq0 __t9nRP4) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo0ApU54 x _00024seq0) (join apply (1 2 0) 2 f x __t3SBR5) (join apply_ans (0 1) 1 __t3SBR5 y) (letp _00024sql9Uwq44 (aslst _00024seq0)) (let _00024sqn7PIv45 (llen _00024sql9Uwq44)) (cmp ge _00024sqn7PIv45 _00024sqc5ANZ46) (letp chk1Vo4344 (lref _00024sql9Uwq44 _00024sqc9K0e47)) (eq x chk1Vo4344) (let _00024sqp4MVy50 (_0002d _00024sqn7PIv45 _00024sqc43TV49)) (let chk0ZXN345 (lslice _00024sql9Uwq44 _00024sqc2wUx48 _00024sqp4MVy50)) (eq xs chk0ZXN345)) (head (emit-temp temp9mlh341 __t22v01 __t9nRP4 y ys)) dem_brackets.slog:13 #f)
  class ReadTask44 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex34;  slog::Index** mapindex35;  slog::Index** mapindex36;  slog::Index** applyindex37;  slog::Index** $sup94786x12x0x0x0index38;  slog::Index** mapindex39;  slog::Index** $seq_atindex40;  slog::Index** applyindex41;  slog::Index** apply_ansindex42;  slog::Index** $seq_atdelta43;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9mlh341");
      outer_rel = db->getRelation("map_ans");
      std::vector<u16> ord45({1, 0, 2});
      slog::Relation* readrel46 = db->getRelation("$seq_at");
      $seq_atindex34 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({0, 1, 2});
      slog::Relation* readrel48 = db->getRelation("map");
      mapindex35 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 2, 0});
      slog::Relation* readrel50 = db->getRelation("map");
      mapindex36 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("apply");
      applyindex37 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({2, 4, 0, 1, 3});
      slog::Relation* readrel54 = db->getRelation("$sup94786x12x0x0x0");
      $sup94786x12x0x0x0index38 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 0});
      slog::Relation* readrel56 = db->getRelation("map");
      mapindex39 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 0, 2});
      slog::Relation* readrel58 = db->getRelation("$seq_at");
      $seq_atindex40 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 0, 2});
      slog::Relation* readrel60 = db->getRelation("$seq_at");
      $seq_atdelta43 = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("apply");
      applyindex41 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("apply_ans");
      apply_ansindex42 = readrel64->getIndex(ord63, false);
  
    }
    ReadTask44(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c44 = v_const5feceb66ffc86f38d952786c;
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c46 = v_const5feceb66ffc86f38d952786c;
      u64 v_c47 = v_const5feceb66ffc86f38d952786c;
      u64 v_c0 = _prim_lempty(db);
      if (v_c0 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c48 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex34, std::array<u64,3>{v_c47, 0, 0})) return;
        slog::join_probe<3,1>(mapindex35, std::array<u64,3>{v_c48, 0, 0}, [&](const std::array<u64,3>& m65) {
          u64 v_c13 = m65[1]; u64 v_c49 = m65[2];
          if (!slog::exists_probe<3,1>(mapindex36, std::array<u64,3>{v_c13, 0, 0})) return;
          if (!slog::exists_probe<3,1>(applyindex37, std::array<u64,3>{v_c13, 0, 0})) return;
          slog::join_probe<5,2>($sup94786x12x0x0x0index38, std::array<u64,5>{v_c13, v_c49, 0, 0, 0}, [&](const std::array<u64,5>& m66) {
            u64 v_c14 = m66[2]; u64 v_c1 = m66[3]; u64 v_c50 = m66[4];
            slog::join_probe<3,3>(mapindex39, std::array<u64,3>{v_c13, v_c14, v_c1}, [&](const std::array<u64,3>& m67) {
              slog::join_probe_old<3,3>($seq_atindex40, $seq_atdelta43, std::array<u64,3>{v_c47, v_c50, v_c14}, [&](const std::array<u64,3>& m68) {
                slog::join_probe<3,2>(applyindex41, std::array<u64,3>{v_c13, v_c50, 0}, [&](const std::array<u64,3>& m69) {
                  u64 v_c51 = m69[2];
                  slog::join_probe<2,1>(apply_ansindex42, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m70) {
                    u64 v_c2 = m70[1];
                    bool ok71 = true;
                    u64 v_c52 = _prim_aslst(db, v_c14, &ok71);
                    if (!ok71) return;
                    u64 v_c53 = _prim_llen(db, v_c52);
                    if (v_c53 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
                    u64 v_c54 = _prim_ge(db, v_c53, v_c43);
                    if (v_c54 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
                    if (!v_c54) return;
                    bool ok73 = true;
                    u64 v_c55 = _prim_lref(db, v_c52, v_c44, &ok73);
                    if (!ok73) return;
                    if (v_c50 != v_c55) return;
                    u64 v_c56 = _prim__0002d(db, v_c53, v_c46);
                    if (v_c56 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
                    u64 v_c57 = _prim_lslice(db, v_c52, v_c45, v_c56);
                    if (v_c57 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
                    if (v_c49 != v_c57) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c3});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_brackets.slog:13", "delta:map_ans", _fires);
  
      if (!_done)
      {
        ReadTask44* _cont = new ReadTask44(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask44(db,b), false);
  // (crule (pre (let _00024sqc5ANZ46 const6b86b273ff34fce19d6b804e) (let _00024sqc9K0e47 const5feceb66ffc86f38d952786c) (let _00024sqc2wUx48 const6b86b273ff34fce19d6b804e) (let _00024sqc43TV49 const5feceb66ffc86f38d952786c) (let _00024sqo0ApU54 const5feceb66ffc86f38d952786c) (let __t22v01 (lempty))) (probe $seq_at (1 0 2) 1 _00024sqo0ApU54 x _00024seq0) (body (letp _00024sql9Uwq44 (aslst _00024seq0)) (let _00024sqn7PIv45 (llen _00024sql9Uwq44)) (cmp ge _00024sqn7PIv45 _00024sqc5ANZ46) (let _00024sqp4MVy50 (_0002d _00024sqn7PIv45 _00024sqc43TV49)) (let xs (lslice _00024sql9Uwq44 _00024sqc2wUx48 _00024sqp4MVy50)) (exists map (2 0 1) 1 _00024seq0) (exists apply (2 0 1) 1 x) (exists map (2 0 1) 1 xs) (join $sup94786x12x0x0x0 (0 3 4 1 2) 3 _00024seq0 x xs __t9nRP4 f) (join map (1 2 0) 3 f _00024seq0 __t9nRP4) (exists map (1 2 0) 2 f xs) (join apply (1 2 0) 2 f x __t3SBR5) (exists apply_ans (0 1) 1 __t3SBR5) (join map (1 2 0) 2 f xs __t8ERN6) (exists map_ans (0 1) 1 __t8ERN6) (join apply_ans (0 1) 1 __t3SBR5 y) (join map_ans (0 1) 1 __t8ERN6 ys) (letp chk0Lmk346 (lref _00024sql9Uwq44 _00024sqc9K0e47)) (eq x chk0Lmk346)) (head (emit-temp temp9mlh341 __t22v01 __t9nRP4 y ys)) dem_brackets.slog:13 #f)
  class ReadTask86 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** mapindex74;  slog::Index** applyindex75;  slog::Index** mapindex76;  slog::Index** $sup94786x12x0x0x0index77;  slog::Index** mapindex78;  slog::Index** mapindex79;  slog::Index** applyindex80;  slog::Index** apply_ansindex81;  slog::Index** mapindex82;  slog::Index** map_ansindex83;  slog::Index** apply_ansindex84;  slog::Index** map_ansindex85;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9mlh341");
      std::vector<u16> ord87({1, 0, 2});
      slog::Relation* readrel88 = db->getRelation("$seq_at");
      driver_index = readrel88->getIndex(ord87, true);
      std::vector<u16> ord89({2, 0, 1});
      slog::Relation* readrel90 = db->getRelation("map");
      mapindex74 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({2, 0, 1});
      slog::Relation* readrel92 = db->getRelation("apply");
      applyindex75 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({2, 0, 1});
      slog::Relation* readrel94 = db->getRelation("map");
      mapindex76 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({0, 3, 4, 1, 2});
      slog::Relation* readrel96 = db->getRelation("$sup94786x12x0x0x0");
      $sup94786x12x0x0x0index77 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 2, 0});
      slog::Relation* readrel98 = db->getRelation("map");
      mapindex78 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 0});
      slog::Relation* readrel100 = db->getRelation("map");
      mapindex79 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 2, 0});
      slog::Relation* readrel102 = db->getRelation("apply");
      applyindex80 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({0, 1});
      slog::Relation* readrel104 = db->getRelation("apply_ans");
      apply_ansindex81 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 2, 0});
      slog::Relation* readrel106 = db->getRelation("map");
      mapindex82 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("map_ans");
      map_ansindex83 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("apply_ans");
      apply_ansindex84 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 1});
      slog::Relation* readrel112 = db->getRelation("map_ans");
      map_ansindex85 = readrel112->getIndex(ord111, false);
  
    }
    ReadTask86(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c44 = v_const5feceb66ffc86f38d952786c;
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c46 = v_const5feceb66ffc86f38d952786c;
      u64 v_c47 = v_const5feceb66ffc86f38d952786c;
      u64 v_c0 = _prim_lempty(db);
      if (v_c0 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c47, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m113) {
        u64 v_c50 = m113[1];
        u64 v_c14 = m113[2];
        if (buckethash(v_c50) != bucket) return;
        bool ok114 = true;
        u64 v_c52 = _prim_aslst(db, v_c14, &ok114);
        if (!ok114) return;
        u64 v_c53 = _prim_llen(db, v_c52);
        if (v_c53 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
        u64 v_c58 = _prim_ge(db, v_c53, v_c43);
        if (v_c58 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
        if (!v_c58) return;
        u64 v_c56 = _prim__0002d(db, v_c53, v_c46);
        if (v_c56 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
        u64 v_c49 = _prim_lslice(db, v_c52, v_c45, v_c56);
        if (v_c49 == slog_error) { slog::emit_pending_error(db, "dem_brackets.slog:13"); return; }
        if (!slog::exists_probe<3,1>(mapindex74, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(applyindex75, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mapindex76, std::array<u64,3>{v_c49, 0, 0})) return;
        slog::join_probe<5,3>($sup94786x12x0x0x0index77, std::array<u64,5>{v_c14, v_c50, v_c49, 0, 0}, [&](const std::array<u64,5>& m116) {
          u64 v_c1 = m116[3]; u64 v_c13 = m116[4];
          slog::join_probe<3,3>(mapindex78, std::array<u64,3>{v_c13, v_c14, v_c1}, [&](const std::array<u64,3>& m117) {
            if (!slog::exists_probe<3,2>(mapindex79, std::array<u64,3>{v_c13, v_c49, 0})) return;
            slog::join_probe<3,2>(applyindex80, std::array<u64,3>{v_c13, v_c50, 0}, [&](const std::array<u64,3>& m118) {
              u64 v_c51 = m118[2];
              if (!slog::exists_probe<2,1>(apply_ansindex81, std::array<u64,2>{v_c51, 0})) return;
              slog::join_probe<3,2>(mapindex82, std::array<u64,3>{v_c13, v_c49, 0}, [&](const std::array<u64,3>& m119) {
                u64 v_c48 = m119[2];
                if (!slog::exists_probe<2,1>(map_ansindex83, std::array<u64,2>{v_c48, 0})) return;
                slog::join_probe<2,1>(apply_ansindex84, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m120) {
                  u64 v_c2 = m120[1];
                  slog::join_probe<2,1>(map_ansindex85, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m121) {
                    u64 v_c3 = m121[1];
                    bool ok122 = true;
                    u64 v_c59 = _prim_lref(db, v_c52, v_c44, &ok122);
                    if (!ok122) return;
                    if (v_c50 != v_c59) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c3});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_brackets.slog:13", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask86* _cont = new ReadTask86(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask86(db,b), false);
  s->addReadRel("$seq_at");
  s->addReadRel("$sup94786x12x0x0x0");
  s->addReadRel("apply");
  s->addReadRel("apply_ans");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("map");
  s->addReadRel("map_ans");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp1SxD339");
  s->addReadRel("temp1otF343");
  s->addReadRel("temp3USn342");
  s->addReadRel("temp9mlh341");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("map_ans");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("temp1SxD339");
  s->addDynamicRel("temp1otF343");
  s->addDynamicRel("temp3USn342");
  s->addDynamicRel("temp9mlh341");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("map_ans");
  d->push(s);
  d->continueRun();
}

