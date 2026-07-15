
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const1ef5dd96b7ac876a994a9ca1;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const624b60c58c9d8bfb6ff1886c;
u64 v_constff5a1ae012afa5d4c889c50a;
u64 v_constd01925b37634a1a9d24159d8;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_consta8648fdb04f7c50b03dd675e;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("809b643d");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const1ef5dd96b7ac876a994a9ca1 = db->encodeString("map.slog:128");
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const624b60c58c9d8bfb6ff1886c = s32_encode(30);
  v_constff5a1ae012afa5d4c889c50a = s32_encode(70);
  v_constd01925b37634a1a9d24159d8 = db->encodeString("mempty");
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_consta8648fdb04f7c50b03dd675e = db->encodeString("mp_fromlist");
  r = db->getRelation("upd");
  if (r == 0) db->addRelation("upd", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("upd");
      std::vector<u16> ord40({0});
    
    r->addIndex<1>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("upd"), std::array<u16,1>{0}, b));
  r = db->getRelation("uni");
  if (r == 0) db->addRelation("uni", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("uni");
      std::vector<u16> ord41({0});
    
    r->addIndex<1>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("uni"), std::array<u16,1>{0}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord42({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord43({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord44({1, 2, 0});
    
    r->addIndex<3>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord45({0, 1, 2});
    
    r->addIndex<3>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord46({1, 2, 0});
    
    r->addIndex<3>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord47({0, 1, 2});
    
    r->addIndex<3>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord48({1, 2, 3, 0});
    
    r->addIndex<4>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord49({0, 1, 2, 3});
    
    r->addIndex<4>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord50({1, 2, 0});
    
    r->addIndex<3>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord51({0, 1, 2});
    
    r->addIndex<3>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord52({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord53({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_union_ans");
  if (r == 0) db->addRelation("mp_union_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union_ans");
      std::vector<u16> ord54({0, 1});
    
    r->addIndex<2>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_union_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_union");
  if (r == 0) db->addStruct("mp_union", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union");
      std::vector<u16> ord55({1, 2, 0});
    
    r->addIndex<3>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord56({0, 1, 2});
    
    r->addIndex<3>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_union"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_size_ans");
  if (r == 0) db->addRelation("mp_size_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size_ans");
      std::vector<u16> ord57({0, 1});
    
    r->addIndex<2>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_size_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_size");
  if (r == 0) db->addStruct("mp_size", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size");
      std::vector<u16> ord58({1, 0});
    
    r->addIndex<2>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord59({0, 1});
    
    r->addIndex<2>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_size"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_put_soft_ans");
  if (r == 0) db->addRelation("mp_put_soft_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord60({0, 1});
    
    r->addIndex<2>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_soft_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put_soft");
  if (r == 0) db->addStruct("mp_put_soft", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft");
      std::vector<u16> ord61({1, 2, 3, 0});
    
    r->addIndex<4>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord62({0, 1, 2, 3});
    
    r->addIndex<4>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put_soft"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_put_ans");
  if (r == 0) db->addRelation("mp_put_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_ans");
      std::vector<u16> ord63({0, 1});
    
    r->addIndex<2>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put");
  if (r == 0) db->addStruct("mp_put", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put");
      std::vector<u16> ord64({1, 2, 3, 0});
    
    r->addIndex<4>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord65({0, 1, 2, 3});
    
    r->addIndex<4>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_msk_ans");
  if (r == 0) db->addRelation("mp_msk_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk_ans");
      std::vector<u16> ord66({0, 1});
    
    r->addIndex<2>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_msk_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_msk");
  if (r == 0) db->addStruct("mp_msk", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk");
      std::vector<u16> ord67({1, 2, 0});
    
    r->addIndex<3>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord68({0, 1, 2});
    
    r->addIndex<3>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_msk"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_join_ans");
  if (r == 0) db->addRelation("mp_join_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join_ans");
      std::vector<u16> ord69({0, 1});
    
    r->addIndex<2>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_join_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_join");
  if (r == 0) db->addStruct("mp_join", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join");
      std::vector<u16> ord70({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord71({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_join"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_hsb_ans");
  if (r == 0) db->addRelation("mp_hsb_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord72({0, 1});
    
    r->addIndex<2>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_hsb_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_hsb");
  if (r == 0) db->addStruct("mp_hsb", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb");
      std::vector<u16> ord73({1, 0});
    
    r->addIndex<2>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord74({0, 1});
    
    r->addIndex<2>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_hsb"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_has0_ans");
  if (r == 0) db->addRelation("mp_has0_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0_ans");
      std::vector<u16> ord75({0, 1});
    
    r->addIndex<2>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_has0_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_has0");
  if (r == 0) db->addStruct("mp_has0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0");
      std::vector<u16> ord76({1, 2, 0});
    
    r->addIndex<3>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord77({0, 1, 2});
    
    r->addIndex<3>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_has0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_get_ans");
  if (r == 0) db->addRelation("mp_get_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get_ans");
      std::vector<u16> ord78({0, 1});
    
    r->addIndex<2>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_get_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_get");
  if (r == 0) db->addStruct("mp_get", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get");
      std::vector<u16> ord79({1, 2, 0});
    
    r->addIndex<3>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord80({0, 1, 2});
    
    r->addIndex<3>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_get"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_fromlist_ans");
  if (r == 0) db->addRelation("mp_fromlist_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord81({0, 1});
    
    r->addIndex<2>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_fromlist_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_fromlist");
  if (r == 0) db->addStruct("mp_fromlist", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist");
      std::vector<u16> ord82({1, 0});
    
    r->addIndex<2>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord83({0, 1});
    
    r->addIndex<2>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_fromlist"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_del_ans");
  if (r == 0) db->addRelation("mp_del_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del_ans");
      std::vector<u16> ord84({0, 1});
    
    r->addIndex<2>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_del_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_del");
  if (r == 0) db->addStruct("mp_del", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del");
      std::vector<u16> ord85({1, 2, 0});
    
    r->addIndex<3>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord86({0, 1, 2});
    
    r->addIndex<3>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_del"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_bld_ans");
  if (r == 0) db->addRelation("mp_bld_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld_ans");
      std::vector<u16> ord87({0, 1});
    
    r->addIndex<2>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_bld_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_bld");
  if (r == 0) db->addStruct("mp_bld", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld");
      std::vector<u16> ord88({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord89({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_bld"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord90({1, 2, 0});
    
    r->addIndex<3>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord91({0, 1, 2});
    
    r->addIndex<3>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mleaf");
  if (r == 0) db->addStruct("mleaf", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mleaf");
      std::vector<u16> ord92({1, 2, 0});
    
    r->addIndex<3>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord93({0, 1, 2});
    
    r->addIndex<3>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mleaf"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mbranch");
  if (r == 0) db->addStruct("mbranch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mbranch");
      std::vector<u16> ord94({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord95({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mbranch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord96({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord97({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord98({1, 2, 3, 0});
    
    r->addIndex<4>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord99({0, 1, 2, 3});
    
    r->addIndex<4>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("has");
  if (r == 0) db->addRelation("has", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("has");
      std::vector<u16> ord100({0, 1});
    
    r->addIndex<2>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("has"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("got");
  if (r == 0) db->addRelation("got", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("got");
      std::vector<u16> ord101({0, 1});
    
    r->addIndex<2>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("got"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord102({0});
    
    r->addIndex<1>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord103({1, 2, 0});
    
    r->addIndex<3>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord104({0, 1, 2});
    
    r->addIndex<3>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("canon");
  if (r == 0) db->addRelation("canon", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("canon");
      std::vector<u16> ord105({0});
    
    r->addIndex<1>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("canon"), std::array<u16,1>{0}, b));
  r = db->getRelation("afterdel");
  if (r == 0) db->addRelation("afterdel", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("afterdel");
      std::vector<u16> ord106({0});
    
    r->addIndex<1>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("afterdel"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord107({1, 0});
    
    r->addIndex<2>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord108({0, 1});
    
    r->addIndex<2>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup5638x98x0x0x1");
  if (r == 0) db->addRelation("$sup5638x98x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord109({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x98x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x98x0x0x0");
  if (r == 0) db->addRelation("$sup5638x98x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord110({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x98x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x95x0x0x1");
  if (r == 0) db->addRelation("$sup5638x95x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord111({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x95x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x95x0x0x0");
  if (r == 0) db->addRelation("$sup5638x95x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord112({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x95x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x93x0x0x0");
  if (r == 0) db->addRelation("$sup5638x93x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord113({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x93x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x84x0x0x0");
  if (r == 0) db->addRelation("$sup5638x84x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord114({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x84x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x82x0x0x0");
  if (r == 0) db->addRelation("$sup5638x82x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord115({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x82x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x81x0x0x0");
  if (r == 0) db->addRelation("$sup5638x81x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord116({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x81x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x68x0x0x0");
  if (r == 0) db->addRelation("$sup5638x68x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x68x0x0x0");
      std::vector<u16> ord117({0, 1, 2, 3});
    
    r->addIndex<4>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x68x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x67x0x0x0");
  if (r == 0) db->addRelation("$sup5638x67x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x67x0x0x0");
      std::vector<u16> ord118({0, 1, 2, 3});
    
    r->addIndex<4>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x67x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup5638x62x0x0x0");
  if (r == 0) db->addRelation("$sup5638x62x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord119({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x62x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x60x0x0x0");
  if (r == 0) db->addRelation("$sup5638x60x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord120({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x60x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x59x0x0x0");
  if (r == 0) db->addRelation("$sup5638x59x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord121({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x59x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x52x0x0x0");
  if (r == 0) db->addRelation("$sup5638x52x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x52x0x0x0");
      std::vector<u16> ord122({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x52x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x51x0x0x0");
  if (r == 0) db->addRelation("$sup5638x51x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x51x0x0x0");
      std::vector<u16> ord123({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x51x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x44x0x0x0");
  if (r == 0) db->addRelation("$sup5638x44x0x0x0", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord124({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x44x0x0x0"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x42x0x0x1");
  if (r == 0) db->addRelation("$sup5638x42x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord125({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x42x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x42x0x0x0");
  if (r == 0) db->addRelation("$sup5638x42x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord126({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x42x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x40x0x0x1");
  if (r == 0) db->addRelation("$sup5638x40x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord127({0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<8>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x40x0x0x1"), std::array<u16,8>{0, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x40x0x0x0");
  if (r == 0) db->addRelation("$sup5638x40x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord128({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x40x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x2");
  if (r == 0) db->addRelation("$sup5638x29x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord129({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x29x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x29x0x0x1");
  if (r == 0) db->addRelation("$sup5638x29x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord130({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x29x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x0");
  if (r == 0) db->addRelation("$sup5638x29x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord131({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x29x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x25x0x0x2");
  if (r == 0) db->addRelation("$sup5638x25x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord132({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x25x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x25x0x0x1");
  if (r == 0) db->addRelation("$sup5638x25x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord133({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x25x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x25x0x0x0");
  if (r == 0) db->addRelation("$sup5638x25x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord134({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x25x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x127x0x0x0");
  if (r == 0) db->addRelation("$sup5638x127x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x127x0x0x0");
      std::vector<u16> ord135({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x127x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x121x0x0x0");
  if (r == 0) db->addRelation("$sup5638x121x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x121x0x0x0");
      std::vector<u16> ord136({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x121x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x110x0x0x0");
  if (r == 0) db->addRelation("$sup5638x110x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord137({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x110x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x107x0x0x1");
  if (r == 0) db->addRelation("$sup5638x107x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord138({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x107x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x107x0x0x0");
  if (r == 0) db->addRelation("$sup5638x107x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord139({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x107x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x104x0x0x1");
  if (r == 0) db->addRelation("$sup5638x104x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord140({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x104x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x104x0x0x0");
  if (r == 0) db->addRelation("$sup5638x104x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord141({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x104x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x101x0x0x0");
  if (r == 0) db->addRelation("$sup5638x101x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord142({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x101x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord143({0, 1, 2});
    
    r->addIndex<3>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("mp_fromlist"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan div_by_zero __erre5TBR916 __errf3cAk917 __errf8rZq918) (body) (head (emit error (0) __erre5TBR916)) <internal>:1 #f)
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
  // (crule (pre) (scan modulo_by_zero __erre7NYo919 __errf8xPp920 __errf9Mcj921) (body) (head (emit error (0) __erre7NYo919)) <internal>:1 #f)
  class ReadTask3 : public slog::Task
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
      std::vector<u16> ord4({0});
      slog::Relation* readrel5 = db->getRelation("error");
      head_index[0] = readrel5->getIndex(ord4, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask3* _cont = new ReadTask3(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3(db,b), false);
  // (crule (pre (let _00024sqc9HTA487 const6b86b273ff34fce19d6b804e) (let _00024sqc2nUG488 const4a44dc15364204a80fe80e90) (let _00024sqc5NiJ491 const7902699be42c8a8e46fbbb45) (let _00024sqc0GS1492 constff5a1ae012afa5d4c889c50a) (let _00024sqc0ru9495 const4e07408562bedb8b60ce05c1) (let _00024sqc9Ew4496 const624b60c58c9d8bfb6ff1886c) (let _00024sqb0D14482 (lempty)) (let _00024sqb8Kj1485 (lempty)) (let _00024sqb3AEH486 (lpush _00024sqb8Kj1485 _00024sqc9HTA487)) (let _00024seq2 (lpush _00024sqb3AEH486 _00024sqc2nUG488)) (let _00024sqb8g9r489 (lempty)) (let _00024sqb34Gf490 (lpush _00024sqb8g9r489 _00024sqc5NiJ491)) (let _00024seq1 (lpush _00024sqb34Gf490 _00024sqc0GS1492)) (let _00024sqb9pdk493 (lempty)) (let _00024sqb3xry494 (lpush _00024sqb9pdk493 _00024sqc0ru9495)) (let _00024seq0 (lpush _00024sqb3xry494 _00024sqc9Ew4496)) (let _00024sqb7ws1483 (lpush _00024sqb0D14482 _00024seq0)) (let _00024sqb3uC1484 (lpush _00024sqb7ws1483 _00024seq1)) (let _00024seq3 (lpush _00024sqb3uC1484 _00024seq2))) (once) (body) (head (mkstruct mp_fromlist (1 0) __73tm775 _00024seq3)) mp_basic.slog:16 #f)
  class ReadTask6 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist");
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const4a44dc15364204a80fe80e90;
      u64 v_c8 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c9 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c10 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c11 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c12 = _prim_lempty(db);
      if (v_c12 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c13 = _prim_lempty(db);
      if (v_c13 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c14 = _prim_lpush(db, v_c13, v_c6);
      if (v_c14 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c15 = _prim_lpush(db, v_c14, v_c7);
      if (v_c15 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c16 = _prim_lempty(db);
      if (v_c16 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c17 = _prim_lpush(db, v_c16, v_c8);
      if (v_c17 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c18 = _prim_lpush(db, v_c17, v_c9);
      if (v_c18 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c19 = _prim_lempty(db);
      if (v_c19 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c20 = _prim_lpush(db, v_c19, v_c10);
      if (v_c20 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c21 = _prim_lpush(db, v_c20, v_c11);
      if (v_c21 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c22 = _prim_lpush(db, v_c12, v_c21);
      if (v_c22 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c23 = _prim_lpush(db, v_c22, v_c18);
      if (v_c23 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
      u64 v_c24 = _prim_lpush(db, v_c23, v_c15);
      if (v_c24 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:16"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:16", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask6(db,b), true);
  // (crule (pre (let _00024sqc006w517 const4e07408562bedb8b60ce05c1) (let _00024sqc9Tu0518 const624b60c58c9d8bfb6ff1886c) (let _00024sqc1Tat521 const6b86b273ff34fce19d6b804e) (let _00024sqc9Gs5522 const4a44dc15364204a80fe80e90) (let _00024sqc8DGb525 const7902699be42c8a8e46fbbb45) (let _00024sqc7g3Q526 constff5a1ae012afa5d4c889c50a) (let _00024sqb4yht512 (lempty)) (let _00024sqb5PXY515 (lempty)) (let _00024sqb5fus516 (lpush _00024sqb5PXY515 _00024sqc006w517)) (let _00024seq2 (lpush _00024sqb5fus516 _00024sqc9Tu0518)) (let _00024sqb4WTR519 (lempty)) (let _00024sqb4e03520 (lpush _00024sqb4WTR519 _00024sqc1Tat521)) (let _00024seq1 (lpush _00024sqb4e03520 _00024sqc9Gs5522)) (let _00024sqb2zil523 (lempty)) (let _00024sqb0UaJ524 (lpush _00024sqb2zil523 _00024sqc8DGb525)) (let _00024seq0 (lpush _00024sqb0UaJ524 _00024sqc7g3Q526)) (let _00024sqb2bYQ513 (lpush _00024sqb4yht512 _00024seq0)) (let _00024sqb2Iuh514 (lpush _00024sqb2bYQ513 _00024seq1)) (let _00024seq3 (lpush _00024sqb2Iuh514 _00024seq2))) (once) (body) (head (mkstruct mp_fromlist (1 0) __669H567 _00024seq3)) mp_basic.slog:15 #f)
  class ReadTask7 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist");
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c26 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c28 = v_const4a44dc15364204a80fe80e90;
      u64 v_c29 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c30 = v_constff5a1ae012afa5d4c889c50a;
      u64 v_c31 = _prim_lempty(db);
      if (v_c31 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c32 = _prim_lempty(db);
      if (v_c32 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c33 = _prim_lpush(db, v_c32, v_c25);
      if (v_c33 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c15 = _prim_lpush(db, v_c33, v_c26);
      if (v_c15 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c34 = _prim_lempty(db);
      if (v_c34 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c35 = _prim_lpush(db, v_c34, v_c27);
      if (v_c35 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c18 = _prim_lpush(db, v_c35, v_c28);
      if (v_c18 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c36 = _prim_lempty(db);
      if (v_c36 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c37 = _prim_lpush(db, v_c36, v_c29);
      if (v_c37 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c21 = _prim_lpush(db, v_c37, v_c30);
      if (v_c21 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c38 = _prim_lpush(db, v_c31, v_c21);
      if (v_c38 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c39 = _prim_lpush(db, v_c38, v_c18);
      if (v_c39 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
      u64 v_c24 = _prim_lpush(db, v_c39, v_c15);
      if (v_c24 == slog_error) { slog::emit_pending_error(db, "mp_basic.slog:15"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mp_basic.slog:15", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask7(db,b), true);
  // (crule (pre (let __tconst3zEO874 constd01925b37634a1a9d24159d8)) (once) (body) (head (mkstruct _enum (1 0) __6aKQ875 __tconst3zEO874)) <internal>:1 #f)
  class ReadTask8 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("_enum");
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c40}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask8(db,b), true);
  // (crule (pre) (scan int_overflow __erre1CX5922 __errf88ij923 __errf9WdC924 __errf7sze925) (body) (head (emit error (0) __erre1CX5922)) <internal>:1 #f)
  class ReadTask9 : public slog::Task
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
      std::vector<u16> ord10({0});
      slog::Relation* readrel11 = db->getRelation("error");
      head_index[0] = readrel11->getIndex(ord10, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c43 = _t[2];
        u64 v_c44 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c41}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask9* _cont = new ReadTask9(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre3is0943 __errf9lhS944 __errf2nvi945) (body) (head (emit error (0) __erre3is0943)) <internal>:1 #f)
  class ReadTask12 : public slog::Task
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
      std::vector<u16> ord13({0});
      slog::Relation* readrel14 = db->getRelation("error");
      head_index[0] = readrel14->getIndex(ord13, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask12(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c45}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask12* _cont = new ReadTask12(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask12(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre9HTN938 __errf4Uay939 __errf9OC4940 __errf7HVa941 __errf0g7Y942) (body) (head (emit error (0) __erre9HTN938)) <internal>:1 #f)
  class ReadTask15 : public slog::Task
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
      std::vector<u16> ord16({0});
      slog::Relation* readrel17 = db->getRelation("error");
      head_index[0] = readrel17->getIndex(ord16, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c48 = _t[0];
        u64 v_c49 = _t[1];
        u64 v_c50 = _t[2];
        u64 v_c51 = _t[3];
        u64 v_c52 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c48}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask15* _cont = new ReadTask15(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), false);
  // (crule (pre) (scan type_mismatch __erre4Bke933 __errf8hMV934 __errf7AC5935 __errf0VeO936 __errf1vjA937) (body) (head (emit error (0) __erre4Bke933)) <internal>:1 #f)
  class ReadTask18 : public slog::Task
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
      std::vector<u16> ord19({0});
      slog::Relation* readrel20 = db->getRelation("error");
      head_index[0] = readrel20->getIndex(ord19, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask18* _cont = new ReadTask18(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask18(db,b), false);
  // (crule (pre) (scan toint_range __erre0iSV930 __errf6pC2931 __errf3iup932) (body) (head (emit error (0) __erre0iSV930)) <internal>:1 #f)
  class ReadTask21 : public slog::Task
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
      std::vector<u16> ord22({0});
      slog::Relation* readrel23 = db->getRelation("error");
      head_index[0] = readrel23->getIndex(ord22, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask21(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask21* _cont = new ReadTask21(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask21(db,b), false);
  // (crule (pre (let __trid5B9n569 const1ef5dd96b7ac876a994a9ca1) (let __trel665J570 consta8648fdb04f7c50b03dd675e) (let __tcol7ioc571 const5feceb66ffc86f38d952786c)) (scan $sup5638x127x0x0x0 _00024seq0 _00024seq1 __d0 k v xs) (body) (head (tycheck xs (accept seq) __trid5B9n569 __trel665J570 __tcol7ioc571 (1 2 3 4 0)) (mkstruct mp_fromlist (1 0) __0Mwz568 xs)) map.slog:128 #f)
  class ReadTask24 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_fromlist");
      outer_rel = db->getRelation("$sup5638x127x0x0x0");
  
    }
    ReadTask24(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_const1ef5dd96b7ac876a994a9ca1;
      u64 v_c62 = v_consta8648fdb04f7c50b03dd675e;
      u64 v_c63 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c64 = _t[2];
        u64 v_c65 = _t[3];
        u64 v_c66 = _t[4];
        u64 v_c67 = _t[5];
        ++_fires;
        if (!(is_seq(v_c67)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c61, v_c62, v_c63, v_c67}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c67}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:$sup5638x127x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask24* _cont = new ReadTask24(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask24(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre9uqM911 __errf3Pfp912 __errf9x3q913 __errf3Izg914 __errf4wsb915) (body) (head (emit error (0) __erre9uqM911)) <internal>:1 #f)
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
      outer_rel = db->getRelation("malformed_deduction");
  
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
        u64 v_c68 = _t[0];
        u64 v_c69 = _t[1];
        u64 v_c70 = _t[2];
        u64 v_c71 = _t[3];
        u64 v_c72 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c68}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
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
  // (crule (pre) (scan nan_result __erre0daf926 __errf31Qi927 __errf71mP928 __errf5DsL929) (body) (head (emit error (0) __erre0daf926)) <internal>:1 #f)
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
        u64 v_c73 = _t[0];
        u64 v_c74 = _t[1];
        u64 v_c75 = _t[2];
        u64 v_c76 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c73}, std::array<u16,1>{0});
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
  // (crule (pre (let _00024sqc7WBK499 constd4735e3a265e16eee03f5971) (let _00024sqc7Wqb500 const5feceb66ffc86f38d952786c) (let _00024sqc4DXV501 const6b86b273ff34fce19d6b804e) (let _00024sqc4rh8504 const6b86b273ff34fce19d6b804e) (let _00024sqc8YZ4505 const5feceb66ffc86f38d952786c) (let _00024sqc4twO506 const6b86b273ff34fce19d6b804e) (let _00024sqc9Tps507 const5feceb66ffc86f38d952786c)) (scan mp_fromlist __t1OZm234 _00024seq1) (body (letp _00024sql9A4h502 (aslst _00024seq1)) (let _00024sqn7O9N503 (llen _00024sql9A4h502)) (cmp ge _00024sqn7O9N503 _00024sqc4rh8504) (letp _00024seq0 (lref _00024sql9A4h502 _00024sqc8YZ4505)) (letp _00024sql2Ed3497 (aslst _00024seq0)) (let chk8zxu946 (llen _00024sql2Ed3497)) (eq _00024sqc7WBK499 chk8zxu946) (letp k (lref _00024sql2Ed3497 _00024sqc7Wqb500)) (letp v (lref _00024sql2Ed3497 _00024sqc4DXV501)) (let _00024sqp4nyU508 (_0002d _00024sqn7O9N503 _00024sqc9Tps507)) (let xs (lslice _00024sql9A4h502 _00024sqc4twO506 _00024sqp4nyU508))) (head (emit $sup5638x127x0x0x0 (0 1 2 3 4 5) _00024seq0 _00024seq1 __t1OZm234 k v xs)) map.slog:128 #f)
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
      head_rel[0] = db->getRelation("$sup5638x127x0x0x0");
      std::vector<u16> ord32({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel33 = db->getRelation("$sup5638x127x0x0x0");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("mp_fromlist");
  
    }
    ReadTask31(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c77 = v_constd4735e3a265e16eee03f5971;
      u64 v_c78 = v_const5feceb66ffc86f38d952786c;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c81 = v_const5feceb66ffc86f38d952786c;
      u64 v_c82 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c83 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c84 = _t[0];
        u64 v_c18 = _t[1];
        bool ok34 = true;
        u64 v_c85 = _prim_aslst(db, v_c18, &ok34);
        if (!ok34) return;
        u64 v_c86 = _prim_llen(db, v_c85);
        if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        u64 v_c87 = _prim_ge(db, v_c86, v_c80);
        if (v_c87 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        if (!v_c87) return;
        bool ok36 = true;
        u64 v_c21 = _prim_lref(db, v_c85, v_c81, &ok36);
        if (!ok36) return;
        bool ok37 = true;
        u64 v_c88 = _prim_aslst(db, v_c21, &ok37);
        if (!ok37) return;
        u64 v_c89 = _prim_llen(db, v_c88);
        if (v_c89 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        if (v_c77 != v_c89) return;
        bool ok38 = true;
        u64 v_c65 = _prim_lref(db, v_c88, v_c78, &ok38);
        if (!ok38) return;
        bool ok39 = true;
        u64 v_c66 = _prim_lref(db, v_c88, v_c79, &ok39);
        if (!ok39) return;
        u64 v_c90 = _prim__0002d(db, v_c86, v_c83);
        if (v_c90 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        u64 v_c67 = _prim_lslice(db, v_c85, v_c82, v_c90);
        if (v_c67 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
        ++_fires;
        slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c21, v_c18, v_c84, v_c65, v_c66, v_c67}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_fromlist", _fires);
  
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
  s->addReadRel("$sup5638x127x0x0x0");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mp_fromlist");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$sup5638x127x0x0x0");
  s->addDynamicRel("_enum");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mp_fromlist");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

