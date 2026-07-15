
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd01925b37634a1a9d24159d8;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("d021d08d");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd01925b37634a1a9d24159d8 = db->encodeString("mempty");
  r = db->getRelation("upd");
  if (r == 0) db->addRelation("upd", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("upd");
      std::vector<u16> ord174({0});
    
    r->addIndex<1>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("upd"), std::array<u16,1>{0}, b));
  r = db->getRelation("uni");
  if (r == 0) db->addRelation("uni", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("uni");
      std::vector<u16> ord175({0});
    
    r->addIndex<1>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("uni"), std::array<u16,1>{0}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord176({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord177({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord178({1, 2, 0});
    
    r->addIndex<3>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord179({0, 1, 2});
    
    r->addIndex<3>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp4l2u1221");
  if (r == 0) db->addTempRelation("temp4l2u1221", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord180({1, 2, 0});
    
    r->addIndex<3>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord181({0, 1, 2});
    
    r->addIndex<3>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord182({1, 2, 3, 0});
    
    r->addIndex<4>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord183({0, 1, 2, 3});
    
    r->addIndex<4>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord184({1, 2, 0});
    
    r->addIndex<3>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord185({0, 1, 2});
    
    r->addIndex<3>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord186({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord187({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_union_ans");
  if (r == 0) db->addRelation("mp_union_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union_ans");
      std::vector<u16> ord188({0, 1});
    
    r->addIndex<2>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_union_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_union");
  if (r == 0) db->addStruct("mp_union", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union");
      std::vector<u16> ord189({1, 2, 0});
    
    r->addIndex<3>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord190({0, 1, 2});
    
    r->addIndex<3>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_union"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_size_ans");
  if (r == 0) db->addRelation("mp_size_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size_ans");
      std::vector<u16> ord191({0, 1});
    
    r->addIndex<2>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord192({0, 1});
    
    r->addIndex<2>(ord192, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_size_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_size");
  if (r == 0) db->addStruct("mp_size", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size");
      std::vector<u16> ord193({1, 0});
    
    r->addIndex<2>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord194({0, 1});
    
    r->addIndex<2>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_size"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_put_soft_ans");
  if (r == 0) db->addRelation("mp_put_soft_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord195({0, 1});
    
    r->addIndex<2>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_soft_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put_soft");
  if (r == 0) db->addStruct("mp_put_soft", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft");
      std::vector<u16> ord196({1, 2, 3, 0});
    
    r->addIndex<4>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord197({0, 1, 2, 3});
    
    r->addIndex<4>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put_soft"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_put_ans");
  if (r == 0) db->addRelation("mp_put_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_ans");
      std::vector<u16> ord198({0, 1});
    
    r->addIndex<2>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put");
  if (r == 0) db->addStruct("mp_put", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put");
      std::vector<u16> ord199({1, 2, 3, 0});
    
    r->addIndex<4>(ord199, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord200({0, 1, 2, 3});
    
    r->addIndex<4>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_msk_ans");
  if (r == 0) db->addRelation("mp_msk_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk_ans");
      std::vector<u16> ord201({0, 1});
    
    r->addIndex<2>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_msk_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_msk");
  if (r == 0) db->addStruct("mp_msk", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk");
      std::vector<u16> ord202({1, 2, 0});
    
    r->addIndex<3>(ord202, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord203({0, 1, 2});
    
    r->addIndex<3>(ord203, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_msk"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_join_ans");
  if (r == 0) db->addRelation("mp_join_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join_ans");
      std::vector<u16> ord204({0, 1});
    
    r->addIndex<2>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_join_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_join");
  if (r == 0) db->addStruct("mp_join", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join");
      std::vector<u16> ord205({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord206({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_join"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_hsb_ans");
  if (r == 0) db->addRelation("mp_hsb_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord207({0, 1});
    
    r->addIndex<2>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_hsb_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_hsb");
  if (r == 0) db->addStruct("mp_hsb", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb");
      std::vector<u16> ord208({1, 0});
    
    r->addIndex<2>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord209({0, 1});
    
    r->addIndex<2>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_hsb"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_has0_ans");
  if (r == 0) db->addRelation("mp_has0_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0_ans");
      std::vector<u16> ord210({0, 1});
    
    r->addIndex<2>(ord210, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_has0_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_has0");
  if (r == 0) db->addStruct("mp_has0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0");
      std::vector<u16> ord211({1, 2, 0});
    
    r->addIndex<3>(ord211, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord212({0, 1, 2});
    
    r->addIndex<3>(ord212, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_has0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_get_ans");
  if (r == 0) db->addRelation("mp_get_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get_ans");
      std::vector<u16> ord213({0, 1});
    
    r->addIndex<2>(ord213, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_get_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_get");
  if (r == 0) db->addStruct("mp_get", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get");
      std::vector<u16> ord214({2, 1, 0});
    
    r->addIndex<3>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord215({0, 2, 1});
    
    r->addIndex<3>(ord215, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_get"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("mp_fromlist_ans");
  if (r == 0) db->addRelation("mp_fromlist_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord216({0, 1});
    
    r->addIndex<2>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_fromlist_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_fromlist");
  if (r == 0) db->addStruct("mp_fromlist", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist");
      std::vector<u16> ord217({1, 0});
    
    r->addIndex<2>(ord217, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord218({0, 1});
    
    r->addIndex<2>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_fromlist"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_del_ans");
  if (r == 0) db->addRelation("mp_del_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del_ans");
      std::vector<u16> ord219({0, 1});
    
    r->addIndex<2>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_del_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_del");
  if (r == 0) db->addStruct("mp_del", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del");
      std::vector<u16> ord220({1, 2, 0});
    
    r->addIndex<3>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord221({0, 1, 2});
    
    r->addIndex<3>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_del"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_bld_ans");
  if (r == 0) db->addRelation("mp_bld_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld_ans");
      std::vector<u16> ord222({0, 1});
    
    r->addIndex<2>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_bld_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_bld");
  if (r == 0) db->addStruct("mp_bld", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld");
      std::vector<u16> ord223({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord223, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord224({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord224, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_bld"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord225({1, 2, 0});
    
    r->addIndex<3>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord226({0, 1, 2});
    
    r->addIndex<3>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mleaf");
  if (r == 0) db->addStruct("mleaf", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mleaf");
      std::vector<u16> ord227({1, 2, 0});
    
    r->addIndex<3>(ord227, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord228({0, 1, 2});
    
    r->addIndex<3>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mleaf"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mbranch");
  if (r == 0) db->addStruct("mbranch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mbranch");
      std::vector<u16> ord229({3, 1, 2, 4, 0});
    
    r->addIndex<5>(ord229, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 1, 2, 4, 0}, false, b), true);
      std::vector<u16> ord230({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord230, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
      std::vector<u16> ord231({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord231, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mbranch"), std::array<u16,5>{3, 1, 2, 4, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord232({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord232, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord233({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord233, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord234({1, 2, 3, 0});
    
    r->addIndex<4>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord235({0, 1, 2, 3});
    
    r->addIndex<4>(ord235, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("has");
  if (r == 0) db->addRelation("has", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("has");
      std::vector<u16> ord236({0, 1});
    
    r->addIndex<2>(ord236, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("has"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("got");
  if (r == 0) db->addRelation("got", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("got");
      std::vector<u16> ord237({0, 1});
    
    r->addIndex<2>(ord237, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("got"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord238({0});
    
    r->addIndex<1>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord239({1, 2, 0});
    
    r->addIndex<3>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord240({0, 1, 2});
    
    r->addIndex<3>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("canon");
  if (r == 0) db->addRelation("canon", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("canon");
      std::vector<u16> ord241({0});
    
    r->addIndex<1>(ord241, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("canon"), std::array<u16,1>{0}, b));
  r = db->getRelation("afterdel");
  if (r == 0) db->addRelation("afterdel", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("afterdel");
      std::vector<u16> ord242({0});
    
    r->addIndex<1>(ord242, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("afterdel"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord243({1, 0});
    
    r->addIndex<2>(ord243, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord244({0, 1});
    
    r->addIndex<2>(ord244, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord245({1, 0});
    
    r->addIndex<2>(ord245, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup5638x98x0x0x1");
  if (r == 0) db->addRelation("$sup5638x98x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord246({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x98x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x98x0x0x0");
  if (r == 0) db->addRelation("$sup5638x98x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord247({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x98x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x95x0x0x1");
  if (r == 0) db->addRelation("$sup5638x95x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord248({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord248, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x95x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x95x0x0x0");
  if (r == 0) db->addRelation("$sup5638x95x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord249({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord249, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x95x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x93x0x0x0");
  if (r == 0) db->addRelation("$sup5638x93x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord250({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x93x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x84x0x0x0");
  if (r == 0) db->addRelation("$sup5638x84x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord251({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord251, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x84x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x82x0x0x0");
  if (r == 0) db->addRelation("$sup5638x82x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord252({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord252, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x82x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x81x0x0x0");
  if (r == 0) db->addRelation("$sup5638x81x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord253({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x81x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x68x0x0x0");
  if (r == 0) db->addRelation("$sup5638x68x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x68x0x0x0");
      std::vector<u16> ord254({0, 1, 2, 3});
    
    r->addIndex<4>(ord254, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x68x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x67x0x0x0");
  if (r == 0) db->addRelation("$sup5638x67x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x67x0x0x0");
      std::vector<u16> ord255({0, 1, 2, 3});
    
    r->addIndex<4>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x67x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x62x0x0x0");
  if (r == 0) db->addRelation("$sup5638x62x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord256({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x62x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x60x0x0x0");
  if (r == 0) db->addRelation("$sup5638x60x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord257({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x60x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x59x0x0x0");
  if (r == 0) db->addRelation("$sup5638x59x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord258({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x59x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x52x0x0x0");
  if (r == 0) db->addRelation("$sup5638x52x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x52x0x0x0");
      std::vector<u16> ord259({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x52x0x0x0"), std::array<u16,6>{1, 5, 0, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x51x0x0x0");
  if (r == 0) db->addRelation("$sup5638x51x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x51x0x0x0");
      std::vector<u16> ord260({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord260, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x51x0x0x0"), std::array<u16,6>{1, 2, 0, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x44x0x0x0");
  if (r == 0) db->addRelation("$sup5638x44x0x0x0", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord261({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord261, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x44x0x0x0"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x42x0x0x1");
  if (r == 0) db->addRelation("$sup5638x42x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord262({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x42x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x42x0x0x0");
  if (r == 0) db->addRelation("$sup5638x42x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord263({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x42x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x40x0x0x1");
  if (r == 0) db->addRelation("$sup5638x40x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord264({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x40x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x40x0x0x0");
  if (r == 0) db->addRelation("$sup5638x40x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord265({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x40x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x2");
  if (r == 0) db->addRelation("$sup5638x29x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord266({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord266, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x29x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x29x0x0x1");
  if (r == 0) db->addRelation("$sup5638x29x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord267({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord267, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x29x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x0");
  if (r == 0) db->addRelation("$sup5638x29x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord268({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord268, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x29x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x25x0x0x2");
  if (r == 0) db->addRelation("$sup5638x25x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord269({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x25x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x25x0x0x1");
  if (r == 0) db->addRelation("$sup5638x25x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord270({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord270, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x25x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x25x0x0x0");
  if (r == 0) db->addRelation("$sup5638x25x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord271({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord271, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x25x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x127x0x0x0");
  if (r == 0) db->addRelation("$sup5638x127x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x127x0x0x0");
      std::vector<u16> ord272({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord272, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x127x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x121x0x0x0");
  if (r == 0) db->addRelation("$sup5638x121x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x121x0x0x0");
      std::vector<u16> ord273({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, false, b), true);
      std::vector<u16> ord274({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord274, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x121x0x0x0"), std::array<u16,5>{1, 0, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x110x0x0x0");
  if (r == 0) db->addRelation("$sup5638x110x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord275({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord275, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x110x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x107x0x0x1");
  if (r == 0) db->addRelation("$sup5638x107x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord276({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord276, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x107x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x107x0x0x0");
  if (r == 0) db->addRelation("$sup5638x107x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord277({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x107x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x104x0x0x1");
  if (r == 0) db->addRelation("$sup5638x104x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord278({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord278, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x104x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x104x0x0x0");
  if (r == 0) db->addRelation("$sup5638x104x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord279({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord279, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x104x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x101x0x0x0");
  if (r == 0) db->addRelation("$sup5638x101x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord280({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x101x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord281({0, 1, 2});
    
    r->addIndex<3>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("mp_fromlist"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan div_by_zero __erre8Vyv1191 __errf5uKh1192 __errf7o2A1193) (body) (head (emit error (0) __erre8Vyv1191)) <internal>:1 #f)
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
  // (crule (pre) (scan mleaf __t31MV61 k v) (body (join mp_get (2 1 0) 2 k __t31MV61 __t4wUf62)) (head (emit mp_get_ans (0 1) __t4wUf62 v)) map.slog:51 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord5({0, 1});
      slog::Relation* readrel6 = db->getRelation("mp_get_ans");
      head_index[0] = readrel6->getIndex(ord5, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord7({2, 1, 0});
      slog::Relation* readrel8 = db->getRelation("mp_get");
      mp_getindex3 = readrel8->getIndex(ord7, false);
  
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
        u64 v_c3 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe<3,2>(mp_getindex3, std::array<u64,3>{v_c4, v_c3, 0}, [&](const std::array<u64,3>& m9) {
          u64 v_c6 = m9[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c5}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:51", "all:mleaf", _fires);
  
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
  // (crule (pre) (scan mpz_overflow __erre4wzz1213 __errf4JjN1214 __errf4LMf1215 __errf3lwc1216 __errf1LKx1217) (body) (head (emit error (0) __erre4wzz1213)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord11({0});
      slog::Relation* readrel12 = db->getRelation("error");
      head_index[0] = readrel12->getIndex(ord11, false);
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c7 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre) (scan toint_range __erre9PBF1205 __errf96sg1206 __errf1zC01207) (body) (head (emit error (0) __erre9PBF1205)) <internal>:1 #f)
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
      outer_rel = db->getRelation("toint_range");
  
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
        u64 v_c12 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c14 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
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
  // (crule (pre) (scan mpz_table_overflow __erre6LpY1218 __errf4Jo71219 __errf1eZw1220) (body) (head (emit error (0) __erre6LpY1218)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
        u64 v_c15 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c15}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre) (scan type_mismatch __erre9tVD1208 __errf0AAO1209 __errf1CEQ1210 __errf4nJz1211 __errf7wRU1212) (body) (head (emit error (0) __erre9tVD1208)) <internal>:1 #f)
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
      outer_rel = db->getRelation("type_mismatch");
  
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
        u64 v_c18 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c20 = _t[2];
        u64 v_c21 = _t[3];
        u64 v_c22 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
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
  // (crule (pre) (scan temp4l2u1221 __t1QLq268 __t1h84266) (body) (head (emit mp_size_ans (0 1) __t1QLq268 __t1h84266)) map.slog:122 #f)
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
      head_rel[0] = db->getRelation("mp_size_ans");
      std::vector<u16> ord23({0, 1});
      slog::Relation* readrel24 = db->getRelation("mp_size_ans");
      head_index[0] = readrel24->getIndex(ord23, false);
      outer_rel = db->getRelation("temp4l2u1221");
  
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
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c23, v_c24}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:122", "delta:temp4l2u1221", _fires);
  
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
  // (crule (pre) (scan mp_size_ans __t5ivu270 __v1) (body (join mp_size (0 1) 1 __t5ivu270 r) (exists mbranch (4 0 1 2 3) 1 r) (join $sup5638x121x0x0x0 (4 0 1 2 3) 1 r __t1QLq268 l m p) (exists mp_size (1 0) 1 l) (join mbranch (3 1 2 4 0) 4 l p m r __t5RVx267) (join mp_size (0 1) 2 __t1QLq268 __t5RVx267) (join mp_size (1 0) 1 l __t7mk7269) (join mp_size_ans (0 1) 1 __t7mk7269 __v0) (let __t1h84266 (_0002b __v0 __v1))) (head (emit-temp temp4l2u1221 __t1QLq268 __t1h84266)) map.slog:122 #f)
  class ReadTask33 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_sizeindex25;  slog::Index** mbranchindex26;  slog::Index** $sup5638x121x0x0x0index27;  slog::Index** mp_sizeindex28;  slog::Index** mbranchindex29;  slog::Index** mp_sizeindex30;  slog::Index** mp_sizeindex31;  slog::Index** mp_size_ansindex32;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4l2u1221");
      outer_rel = db->getRelation("mp_size_ans");
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("mp_size");
      mp_sizeindex25 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({4, 0, 1, 2, 3});
      slog::Relation* readrel37 = db->getRelation("mbranch");
      mbranchindex26 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({4, 0, 1, 2, 3});
      slog::Relation* readrel39 = db->getRelation("$sup5638x121x0x0x0");
      $sup5638x121x0x0x0index27 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 0});
      slog::Relation* readrel41 = db->getRelation("mp_size");
      mp_sizeindex28 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({3, 1, 2, 4, 0});
      slog::Relation* readrel43 = db->getRelation("mbranch");
      mbranchindex29 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("mp_size");
      mp_sizeindex30 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 0});
      slog::Relation* readrel47 = db->getRelation("mp_size");
      mp_sizeindex31 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({0, 1});
      slog::Relation* readrel49 = db->getRelation("mp_size_ans");
      mp_size_ansindex32 = readrel49->getIndex(ord48, false);
  
    }
    ReadTask33(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[0];
        u64 v_c26 = _t[1];
        slog::join_probe<2,1>(mp_sizeindex25, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m50) {
          u64 v_c27 = m50[1];
          if (!slog::exists_probe<5,1>(mbranchindex26, std::array<u64,5>{v_c27, 0, 0, 0, 0})) return;
          slog::join_probe<5,1>($sup5638x121x0x0x0index27, std::array<u64,5>{v_c27, 0, 0, 0, 0}, [&](const std::array<u64,5>& m51) {
            u64 v_c23 = m51[1]; u64 v_c28 = m51[2]; u64 v_c29 = m51[3]; u64 v_c30 = m51[4];
            if (!slog::exists_probe<2,1>(mp_sizeindex28, std::array<u64,2>{v_c28, 0})) return;
            slog::join_probe<5,4>(mbranchindex29, std::array<u64,5>{v_c28, v_c30, v_c29, v_c27, 0}, [&](const std::array<u64,5>& m52) {
              u64 v_c31 = m52[4];
              slog::join_probe<2,2>(mp_sizeindex30, std::array<u64,2>{v_c23, v_c31}, [&](const std::array<u64,2>& m53) {
                slog::join_probe<2,1>(mp_sizeindex31, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m54) {
                  u64 v_c32 = m54[1];
                  slog::join_probe<2,1>(mp_size_ansindex32, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m55) {
                    u64 v_c33 = m55[1];
                    u64 v_c24 = _prim__0002b(db, v_c33, v_c26);
                    if (v_c24 == slog_error) { slog::emit_pending_error(db, "map.slog:122"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c23, v_c24});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:122", "delta:mp_size_ans", _fires);
  
      if (!_done)
      {
        ReadTask33* _cont = new ReadTask33(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask33(db,b), false);
  // (crule (pre) (scan mp_size_ans __t7mk7269 __v0) (body (join mp_size (0 1) 1 __t7mk7269 l) (exists mbranch (3 1 2 4 0) 1 l) (join $sup5638x121x0x0x0 (1 0 2 3 4) 1 l __t1QLq268 m p r) (exists mp_size (1 0) 1 r) (join mbranch (3 1 2 4 0) 4 l p m r __t5RVx267) (join mp_size (0 1) 2 __t1QLq268 __t5RVx267) (join mp_size (1 0) 1 r __t5ivu270) (join-old mp_size_ans (0 1) 1 (0 1) __t5ivu270 __v1) (let __t1h84266 (_0002b __v0 __v1))) (head (emit-temp temp4l2u1221 __t1QLq268 __t1h84266)) map.slog:122 #f)
  class ReadTask65 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_sizeindex56;  slog::Index** mbranchindex57;  slog::Index** $sup5638x121x0x0x0index58;  slog::Index** mp_sizeindex59;  slog::Index** mbranchindex60;  slog::Index** mp_sizeindex61;  slog::Index** mp_sizeindex62;  slog::Index** mp_size_ansindex63;  slog::Index** mp_size_ansdelta64;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4l2u1221");
      outer_rel = db->getRelation("mp_size_ans");
      std::vector<u16> ord66({0, 1});
      slog::Relation* readrel67 = db->getRelation("mp_size");
      mp_sizeindex56 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({3, 1, 2, 4, 0});
      slog::Relation* readrel69 = db->getRelation("mbranch");
      mbranchindex57 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 0, 2, 3, 4});
      slog::Relation* readrel71 = db->getRelation("$sup5638x121x0x0x0");
      $sup5638x121x0x0x0index58 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 0});
      slog::Relation* readrel73 = db->getRelation("mp_size");
      mp_sizeindex59 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({3, 1, 2, 4, 0});
      slog::Relation* readrel75 = db->getRelation("mbranch");
      mbranchindex60 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({0, 1});
      slog::Relation* readrel77 = db->getRelation("mp_size");
      mp_sizeindex61 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 0});
      slog::Relation* readrel79 = db->getRelation("mp_size");
      mp_sizeindex62 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({0, 1});
      slog::Relation* readrel81 = db->getRelation("mp_size_ans");
      mp_size_ansindex63 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({0, 1});
      slog::Relation* readrel83 = db->getRelation("mp_size_ans");
      mp_size_ansdelta64 = readrel83->getIndex(ord82, true);
  
    }
    ReadTask65(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(mp_sizeindex56, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m84) {
          u64 v_c28 = m84[1];
          if (!slog::exists_probe<5,1>(mbranchindex57, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
          slog::join_probe<5,1>($sup5638x121x0x0x0index58, std::array<u64,5>{v_c28, 0, 0, 0, 0}, [&](const std::array<u64,5>& m85) {
            u64 v_c23 = m85[1]; u64 v_c29 = m85[2]; u64 v_c30 = m85[3]; u64 v_c27 = m85[4];
            if (!slog::exists_probe<2,1>(mp_sizeindex59, std::array<u64,2>{v_c27, 0})) return;
            slog::join_probe<5,4>(mbranchindex60, std::array<u64,5>{v_c28, v_c30, v_c29, v_c27, 0}, [&](const std::array<u64,5>& m86) {
              u64 v_c31 = m86[4];
              slog::join_probe<2,2>(mp_sizeindex61, std::array<u64,2>{v_c23, v_c31}, [&](const std::array<u64,2>& m87) {
                slog::join_probe<2,1>(mp_sizeindex62, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m88) {
                  u64 v_c25 = m88[1];
                  slog::join_probe_old<2,1>(mp_size_ansindex63, mp_size_ansdelta64, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m89) {
                    u64 v_c26 = m89[1];
                    u64 v_c24 = _prim__0002b(db, v_c33, v_c26);
                    if (v_c24 == slog_error) { slog::emit_pending_error(db, "map.slog:122"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c23, v_c24});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:122", "delta:mp_size_ans", _fires);
  
      if (!_done)
      {
        ReadTask65* _cont = new ReadTask65(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask65(db,b), false);
  // (crule (pre (let __tconst2zBs164 const6b86b273ff34fce19d6b804e)) (scan mp_size __t90Ny166 __t7fbm165) (body (join mleaf (0 1 2) 1 __t7fbm165 k v)) (head (emit mp_size_ans (0 1) __t90Ny166 __tconst2zBs164)) map.slog:121 #f)
  class ReadTask91 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex90;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_size_ans");
      std::vector<u16> ord92({0, 1});
      slog::Relation* readrel93 = db->getRelation("mp_size_ans");
      head_index[0] = readrel93->getIndex(ord92, false);
      outer_rel = db->getRelation("mp_size");
      std::vector<u16> ord94({0, 1, 2});
      slog::Relation* readrel95 = db->getRelation("mleaf");
      mleafindex90 = readrel95->getIndex(ord94, false);
  
    }
    ReadTask91(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
  
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
        slog::join_probe<3,1>(mleafindex90, std::array<u64,3>{v_c36, 0, 0}, [&](const std::array<u64,3>& m96) {
          u64 v_c4 = m96[1]; u64 v_c5 = m96[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c35, v_c34}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:121", "all:mp_size", _fires);
  
      if (!_done)
      {
        ReadTask91* _cont = new ReadTask91(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask91(db,b), true);
  // (crule (pre) (scan nan_result __erre2u831201 __errf5OPC1202 __errf2Okv1203 __errf0Anm1204) (body) (head (emit error (0) __erre2u831201)) <internal>:1 #f)
  class ReadTask97 : public slog::Task
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
      std::vector<u16> ord98({0});
      slog::Relation* readrel99 = db->getRelation("error");
      head_index[0] = readrel99->getIndex(ord98, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask97(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c39 = _t[2];
        u64 v_c40 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c37}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask97* _cont = new ReadTask97(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask97(db,b), false);
  // (crule (pre (let __tconst6lYS182 const6b86b273ff34fce19d6b804e)) (scan mp_get_ans __t6AoL184 v) (body (join mp_get (0 2 1) 1 __t6AoL184 k l) (exists mbranch (3 1 2 4 0) 1 l) (exists mp_get (2 1 0) 1 k) (join $sup5638x51x0x0x0 (1 2 0 3 4 5) 2 k l __t8hCR181 m p r) (exists mp_get (0 2 1) 2 __t8hCR181 k) (join mbranch (3 1 2 4 0) 4 l p m r __t2dYs180) (join mp_get (0 2 1) 3 __t8hCR181 k __t2dYs180) (let __t9TkT183 (band k m)) (cmp lt __t9TkT183 __tconst6lYS182)) (head (emit mp_get_ans (0 1) __t8hCR181 v)) map.slog:52 #f)
  class ReadTask107 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex100;  slog::Index** mbranchindex101;  slog::Index** mp_getindex102;  slog::Index** $sup5638x51x0x0x0index103;  slog::Index** mp_getindex104;  slog::Index** mbranchindex105;  slog::Index** mp_getindex106;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord108({0, 1});
      slog::Relation* readrel109 = db->getRelation("mp_get_ans");
      head_index[0] = readrel109->getIndex(ord108, false);
      outer_rel = db->getRelation("mp_get_ans");
      std::vector<u16> ord110({0, 2, 1});
      slog::Relation* readrel111 = db->getRelation("mp_get");
      mp_getindex100 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({3, 1, 2, 4, 0});
      slog::Relation* readrel113 = db->getRelation("mbranch");
      mbranchindex101 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({2, 1, 0});
      slog::Relation* readrel115 = db->getRelation("mp_get");
      mp_getindex102 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel117 = db->getRelation("$sup5638x51x0x0x0");
      $sup5638x51x0x0x0index103 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({0, 2, 1});
      slog::Relation* readrel119 = db->getRelation("mp_get");
      mp_getindex104 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({3, 1, 2, 4, 0});
      slog::Relation* readrel121 = db->getRelation("mbranch");
      mbranchindex105 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({0, 2, 1});
      slog::Relation* readrel123 = db->getRelation("mp_get");
      mp_getindex106 = readrel123->getIndex(ord122, false);
  
    }
    ReadTask107(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c42 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<3,1>(mp_getindex100, std::array<u64,3>{v_c42, 0, 0}, [&](const std::array<u64,3>& m124) {
          u64 v_c4 = m124[1]; u64 v_c28 = m124[2];
          if (!slog::exists_probe<5,1>(mbranchindex101, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_getindex102, std::array<u64,3>{v_c4, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x51x0x0x0index103, std::array<u64,6>{v_c4, v_c28, 0, 0, 0, 0}, [&](const std::array<u64,6>& m125) {
            u64 v_c43 = m125[2]; u64 v_c29 = m125[3]; u64 v_c30 = m125[4]; u64 v_c27 = m125[5];
            if (!slog::exists_probe<3,2>(mp_getindex104, std::array<u64,3>{v_c43, v_c4, 0})) return;
            slog::join_probe<5,4>(mbranchindex105, std::array<u64,5>{v_c28, v_c30, v_c29, v_c27, 0}, [&](const std::array<u64,5>& m126) {
              u64 v_c44 = m126[4];
              slog::join_probe<3,3>(mp_getindex106, std::array<u64,3>{v_c43, v_c4, v_c44}, [&](const std::array<u64,3>& m127) {
                u64 v_c45 = _prim_band(db, v_c4, v_c29);
                if (v_c45 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                u64 v_c46 = _prim_lt(db, v_c45, v_c41);
                if (v_c46 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                if (!v_c46) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c43, v_c5}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:52", "delta:mp_get_ans", _fires);
  
      if (!_done)
      {
        ReadTask107* _cont = new ReadTask107(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask107(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre08J01194 __errf7OcB1195 __errf1Jru1196) (body) (head (emit error (0) __erre08J01194)) <internal>:1 #f)
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
      outer_rel = db->getRelation("modulo_by_zero");
  
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
        u64 v_c47 = _t[0];
        u64 v_c48 = _t[1];
        u64 v_c49 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c47}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
  // (crule (pre (let __tconst4Tth206 const5feceb66ffc86f38d952786c)) (scan mp_get_ans __t9jdR208 v) (body (join mp_get (0 2 1) 1 __t9jdR208 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_get (2 1 0) 1 k) (join $sup5638x52x0x0x0 (1 5 0 2 3 4) 2 k r __t5tet205 l m p) (exists mp_get (0 2 1) 2 __t5tet205 k) (join mbranch (3 1 2 4 0) 4 l p m r __t8skS204) (join mp_get (0 2 1) 3 __t5tet205 k __t8skS204) (let __t0qxK207 (band k m)) (cmp gt __t0qxK207 __tconst4Tth206)) (head (emit mp_get_ans (0 1) __t5tet205 v)) map.slog:53 #f)
  class ReadTask139 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex132;  slog::Index** mbranchindex133;  slog::Index** mp_getindex134;  slog::Index** $sup5638x52x0x0x0index135;  slog::Index** mp_getindex136;  slog::Index** mbranchindex137;  slog::Index** mp_getindex138;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord140({0, 1});
      slog::Relation* readrel141 = db->getRelation("mp_get_ans");
      head_index[0] = readrel141->getIndex(ord140, false);
      outer_rel = db->getRelation("mp_get_ans");
      std::vector<u16> ord142({0, 2, 1});
      slog::Relation* readrel143 = db->getRelation("mp_get");
      mp_getindex132 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({4, 0, 1, 2, 3});
      slog::Relation* readrel145 = db->getRelation("mbranch");
      mbranchindex133 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({2, 1, 0});
      slog::Relation* readrel147 = db->getRelation("mp_get");
      mp_getindex134 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel149 = db->getRelation("$sup5638x52x0x0x0");
      $sup5638x52x0x0x0index135 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 2, 1});
      slog::Relation* readrel151 = db->getRelation("mp_get");
      mp_getindex136 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({3, 1, 2, 4, 0});
      slog::Relation* readrel153 = db->getRelation("mbranch");
      mbranchindex137 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({0, 2, 1});
      slog::Relation* readrel155 = db->getRelation("mp_get");
      mp_getindex138 = readrel155->getIndex(ord154, false);
  
    }
    ReadTask139(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c50 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c51 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<3,1>(mp_getindex132, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m156) {
          u64 v_c4 = m156[1]; u64 v_c27 = m156[2];
          if (!slog::exists_probe<5,1>(mbranchindex133, std::array<u64,5>{v_c27, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_getindex134, std::array<u64,3>{v_c4, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x52x0x0x0index135, std::array<u64,6>{v_c4, v_c27, 0, 0, 0, 0}, [&](const std::array<u64,6>& m157) {
            u64 v_c52 = m157[2]; u64 v_c28 = m157[3]; u64 v_c29 = m157[4]; u64 v_c30 = m157[5];
            if (!slog::exists_probe<3,2>(mp_getindex136, std::array<u64,3>{v_c52, v_c4, 0})) return;
            slog::join_probe<5,4>(mbranchindex137, std::array<u64,5>{v_c28, v_c30, v_c29, v_c27, 0}, [&](const std::array<u64,5>& m158) {
              u64 v_c53 = m158[4];
              slog::join_probe<3,3>(mp_getindex138, std::array<u64,3>{v_c52, v_c4, v_c53}, [&](const std::array<u64,3>& m159) {
                u64 v_c54 = _prim_band(db, v_c4, v_c29);
                if (v_c54 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                u64 v_c55 = _prim_gt(db, v_c54, v_c50);
                if (v_c55 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                if (!v_c55) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c52, v_c5}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:53", "delta:mp_get_ans", _fires);
  
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
  // (crule (pre (let __tconst9A45796 constd01925b37634a1a9d24159d8) (let __tconst9jbR125 const5feceb66ffc86f38d952786c)) (probe _enum (1 0) 1 __tconst9A45796 __t0unw126) (body (join mp_size (1 0) 1 __t0unw126 __t9a7s127)) (head (emit mp_size_ans (0 1) __t9a7s127 __tconst9jbR125)) map.slog:120 #f)
  class ReadTask162 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** mp_sizeindex161;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_size_ans");
      std::vector<u16> ord163({0, 1});
      slog::Relation* readrel164 = db->getRelation("mp_size_ans");
      head_index[0] = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 0});
      slog::Relation* readrel166 = db->getRelation("_enum");
      driver_index = readrel166->getIndex(ord165, true);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("mp_size");
      mp_sizeindex161 = readrel168->getIndex(ord167, false);
  
    }
    ReadTask162(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_constd01925b37634a1a9d24159d8;
      u64 v_c57 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c56, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m169) {
        u64 v_c58 = m169[1];
        if (buckethash(v_c58) != bucket) return;
        slog::join_probe<2,1>(mp_sizeindex161, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m170) {
          u64 v_c59 = m170[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c59, v_c57}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:120", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask162* _cont = new ReadTask162(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask162(db,b), true);
  // (crule (pre) (scan int_overflow __erre9QAO1197 __errf9gq31198 __errf0U6V1199 __errf81VH1200) (body) (head (emit error (0) __erre9QAO1197)) <internal>:1 #f)
  class ReadTask171 : public slog::Task
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
      std::vector<u16> ord172({0});
      slog::Relation* readrel173 = db->getRelation("error");
      head_index[0] = readrel173->getIndex(ord172, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask171(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c60 = _t[0];
        u64 v_c61 = _t[1];
        u64 v_c62 = _t[2];
        u64 v_c63 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c60}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask171* _cont = new ReadTask171(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask171(db,b), false);
  s->addReadRel("$sup5638x121x0x0x0");
  s->addReadRel("$sup5638x51x0x0x0");
  s->addReadRel("$sup5638x52x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("mbranch");
  s->addReadRel("mleaf");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mp_get");
  s->addReadRel("mp_get_ans");
  s->addReadRel("mp_size");
  s->addReadRel("mp_size_ans");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp4l2u1221");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mp_get_ans");
  s->addDynamicRel("mp_size_ans");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("temp4l2u1221");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("mp_get_ans");
  d->push(s);
  d->continueRun();
}

