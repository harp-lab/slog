
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constef2d127de37b942baad06145;
u64 v_conste7f6c011776e8db7cd330b54;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_constd59eced1ded07f84c145592f;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const624b60c58c9d8bfb6ff1886c;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constf5ca38f748a1d6eaf726b8a4;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("f3ac4a39");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_conste7f6c011776e8db7cd330b54 = s32_encode(6);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_constd59eced1ded07f84c145592f = s32_encode(40);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const624b60c58c9d8bfb6ff1886c = s32_encode(30);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constf5ca38f748a1d6eaf726b8a4 = s32_encode(20);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord2289({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord2289, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord2290({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord2290, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord2291({1, 2, 0});
    
    r->addIndex<3>(ord2291, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2292({0, 1, 2});
    
    r->addIndex<3>(ord2292, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("third");
  if (r == 0) db->addRelation("third", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("third");
      std::vector<u16> ord2293({0});
    
    r->addIndex<1>(ord2293, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("third"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord2294({1, 2, 0});
    
    r->addIndex<3>(ord2294, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2295({0, 1, 2});
    
    r->addIndex<3>(ord2295, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("reversed");
  if (r == 0) db->addRelation("reversed", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("reversed");
      std::vector<u16> ord2296({0});
    
    r->addIndex<1>(ord2296, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("reversed"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord2297({1, 2, 3, 0});
    
    r->addIndex<4>(ord2297, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord2298({0, 1, 2, 3});
    
    r->addIndex<4>(ord2298, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("n");
  if (r == 0) db->addRelation("n", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("n");
      std::vector<u16> ord2299({0});
    
    r->addIndex<1>(ord2299, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("n"), std::array<u16,1>{0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord2300({1, 2, 0});
    
    r->addIndex<3>(ord2300, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2301({0, 1, 2});
    
    r->addIndex<3>(ord2301, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord2302({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord2302, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord2303({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord2303, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord2304({1, 2, 0});
    
    r->addIndex<3>(ord2304, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2305({0, 1, 2});
    
    r->addIndex<3>(ord2305, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord2306({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord2306, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord2307({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord2307, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lst_take_ans");
  if (r == 0) db->addRelation("lst_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take_ans");
      std::vector<u16> ord2308({0, 1});
    
    r->addIndex<2>(ord2308, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_take");
  if (r == 0) db->addStruct("lst_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take");
      std::vector<u16> ord2309({1, 2, 0});
    
    r->addIndex<3>(ord2309, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2310({0, 1, 2});
    
    r->addIndex<3>(ord2310, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev_ans");
  if (r == 0) db->addRelation("lst_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_ans");
      std::vector<u16> ord2311({0, 1});
    
    r->addIndex<2>(ord2311, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc_ans");
  if (r == 0) db->addRelation("lst_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc_ans");
      std::vector<u16> ord2312({0, 1});
    
    r->addIndex<2>(ord2312, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc");
  if (r == 0) db->addStruct("lst_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc");
      std::vector<u16> ord2313({1, 2, 0});
    
    r->addIndex<3>(ord2313, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2314({0, 1, 2});
    
    r->addIndex<3>(ord2314, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev");
  if (r == 0) db->addStruct("lst_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev");
      std::vector<u16> ord2315({1, 0});
    
    r->addIndex<2>(ord2315, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord2316({0, 1});
    
    r->addIndex<2>(ord2316, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_ref_ans");
  if (r == 0) db->addRelation("lst_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref_ans");
      std::vector<u16> ord2317({0, 1});
    
    r->addIndex<2>(ord2317, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_ref");
  if (r == 0) db->addStruct("lst_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref");
      std::vector<u16> ord2318({1, 2, 0});
    
    r->addIndex<3>(ord2318, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2319({0, 1, 2});
    
    r->addIndex<3>(ord2319, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_member_ans");
  if (r == 0) db->addRelation("lst_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member_ans");
      std::vector<u16> ord2320({0, 1});
    
    r->addIndex<2>(ord2320, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_member");
  if (r == 0) db->addStruct("lst_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member");
      std::vector<u16> ord2321({1, 2, 0});
    
    r->addIndex<3>(ord2321, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2322({0, 1, 2});
    
    r->addIndex<3>(ord2322, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_len_ans");
  if (r == 0) db->addRelation("lst_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len_ans");
      std::vector<u16> ord2323({0, 1});
    
    r->addIndex<2>(ord2323, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_len");
  if (r == 0) db->addStruct("lst_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len");
      std::vector<u16> ord2324({1, 0});
    
    r->addIndex<2>(ord2324, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord2325({0, 1});
    
    r->addIndex<2>(ord2325, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_append_ans");
  if (r == 0) db->addRelation("lst_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append_ans");
      std::vector<u16> ord2326({0, 1});
    
    r->addIndex<2>(ord2326, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_append");
  if (r == 0) db->addStruct("lst_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append");
      std::vector<u16> ord2327({1, 2, 0});
    
    r->addIndex<3>(ord2327, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2328({0, 1, 2});
    
    r->addIndex<3>(ord2328, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord2329({2, 0, 1});
    
    r->addIndex<3>(ord2329, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_absent_ans");
  if (r == 0) db->addRelation("lst_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent_ans");
      std::vector<u16> ord2330({0, 1});
    
    r->addIndex<2>(ord2330, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_absent");
  if (r == 0) db->addStruct("lst_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent");
      std::vector<u16> ord2331({1, 2, 0});
    
    r->addIndex<3>(ord2331, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2332({0, 1, 2});
    
    r->addIndex<3>(ord2332, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord2333({1, 2, 3, 0});
    
    r->addIndex<4>(ord2333, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord2334({0, 1, 2, 3});
    
    r->addIndex<4>(ord2334, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("has7");
  if (r == 0) db->addRelation("has7", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("has7");
      std::vector<u16> ord2335({0});
    
    r->addIndex<1>(ord2335, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("has7"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord2336({0});
    
    r->addIndex<1>(ord2336, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord2337({1, 2, 0});
    
    r->addIndex<3>(ord2337, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord2338({0, 1, 2});
    
    r->addIndex<3>(ord2338, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("appended");
  if (r == 0) db->addRelation("appended", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("appended");
      std::vector<u16> ord2339({0});
    
    r->addIndex<1>(ord2339, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("appended"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord2340({1, 0});
    
    r->addIndex<2>(ord2340, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord2341({0, 1});
    
    r->addIndex<2>(ord2341, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$seq_atr");
  if (r == 0) db->addRelation("$seq_atr", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_atr");
      std::vector<u16> ord2342({0, 1, 2});
    
    r->addIndex<3>(ord2342, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord2343({0, 1, 2});
    
    r->addIndex<3>(ord2343, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_atr"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord2344({0, 1, 2});
    
    r->addIndex<3>(ord2344, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord2345({0, 1, 2});
    
    r->addIndex<3>(ord2345, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("appended"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_absent"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1, 2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_append"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_append_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_len"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_member"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_ref"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_rev"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1, 2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_rev_acc"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_rev_acc_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_rev_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_take"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("lst_take_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("reversed"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre (let _00024sqc5EFT159 const4e07408562bedb8b60ce05c1) (let _00024sqc5bxU160 const5feceb66ffc86f38d952786c) (let _00024sqc3UTe161 const6b86b273ff34fce19d6b804e) (let _00024sqc5qfs162 const6b86b273ff34fce19d6b804e) (let _00024sqc6UGY163 constd4735e3a265e16eee03f5971) (let _00024sqc4r9A164 constd4735e3a265e16eee03f5971) (let _00024sqc2CcG165 const4e07408562bedb8b60ce05c1) (let _00024sqo8L4F167 const6b86b273ff34fce19d6b804e) (let _00024sqo6G1P166 const5feceb66ffc86f38d952786c) (let _00024sqo2Nvm169 constd4735e3a265e16eee03f5971) (let _00024sqo669y168 const6b86b273ff34fce19d6b804e) (let _00024sqo1fa8171 const4e07408562bedb8b60ce05c1) (let _00024sqo8rnZ170 constd4735e3a265e16eee03f5971) (let _00024sqo7ulb173 const6b86b273ff34fce19d6b804e) (let _00024sqo0YXk172 constd4735e3a265e16eee03f5971) (let _00024sqo02S4175 constd4735e3a265e16eee03f5971) (let _00024sqo81tB174 const6b86b273ff34fce19d6b804e) (let _00024sqo5Ac4177 const4e07408562bedb8b60ce05c1) (let _00024sqo1MJI176 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo5Ac4177 _00024sqo1MJI176 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8L4F167 _00024sqo6G1P166 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo2Nvm169 _00024sqo669y168 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1fa8171 _00024sqo8rnZ170 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo7ulb173 _00024sqo0YXk172 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo02S4175 _00024sqo81tB174 _00024seq0) (join lst_rev (1 0) 1 _00024seq0 __t4lMv28) (join lst_rev_ans (0 1) 1 __t4lMv28 r) (letp _00024sql9jSN157 (aslst _00024seq0)) (let chk4WqR454 (llen _00024sql9jSN157)) (eq _00024sqc5EFT159 chk4WqR454) (letp chk3UdH455 (lref _00024sql9jSN157 _00024sqc5bxU160)) (eq _00024sqc3UTe161 chk3UdH455) (letp chk7vEP456 (lref _00024sql9jSN157 _00024sqc5qfs162)) (eq _00024sqc6UGY163 chk7vEP456) (letp chk1MDt457 (lref _00024sql9jSN157 _00024sqc4r9A164)) (eq _00024sqc2CcG165 chk1MDt457)) (head (emit reversed (0) r)) lst_ops.slog:16 #f)
  class ReadTask7 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex0;  slog::Index** $seq_atindex1;  slog::Index** $seq_atindex2;  slog::Index** $seq_atrindex3;  slog::Index** $seq_atrindex4;  slog::Index** lst_revindex5;  slog::Index** lst_rev_ansindex6;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reversed");
      std::vector<u16> ord8({0});
      slog::Relation* readrel9 = db->getRelation("reversed");
      head_index[0] = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({0, 1, 2});
      slog::Relation* readrel11 = db->getRelation("$seq_atr");
      driver_index = readrel11->getIndex(ord10, true);
      std::vector<u16> ord12({0, 1, 2});
      slog::Relation* readrel13 = db->getRelation("$seq_at");
      $seq_atindex0 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({0, 1, 2});
      slog::Relation* readrel15 = db->getRelation("$seq_at");
      $seq_atindex1 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({0, 1, 2});
      slog::Relation* readrel17 = db->getRelation("$seq_at");
      $seq_atindex2 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({0, 1, 2});
      slog::Relation* readrel19 = db->getRelation("$seq_atr");
      $seq_atrindex3 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 1, 2});
      slog::Relation* readrel21 = db->getRelation("$seq_atr");
      $seq_atrindex4 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("lst_rev");
      lst_revindex5 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({0, 1});
      slog::Relation* readrel25 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex6 = readrel25->getIndex(ord24, false);
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c17 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c17, v_c18, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m26) {
        u64 v_c19 = m26[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex0, std::array<u64,3>{v_c7, v_c8, v_c19}, [&](const std::array<u64,3>& m27) {
          slog::join_probe<3,3>($seq_atindex1, std::array<u64,3>{v_c9, v_c10, v_c19}, [&](const std::array<u64,3>& m28) {
            slog::join_probe<3,3>($seq_atindex2, std::array<u64,3>{v_c11, v_c12, v_c19}, [&](const std::array<u64,3>& m29) {
              slog::join_probe<3,3>($seq_atrindex3, std::array<u64,3>{v_c13, v_c14, v_c19}, [&](const std::array<u64,3>& m30) {
                slog::join_probe<3,3>($seq_atrindex4, std::array<u64,3>{v_c15, v_c16, v_c19}, [&](const std::array<u64,3>& m31) {
                  slog::join_probe<2,1>(lst_revindex5, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m32) {
                    u64 v_c20 = m32[1];
                    slog::join_probe<2,1>(lst_rev_ansindex6, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m33) {
                      u64 v_c21 = m33[1];
                      bool ok34 = true;
                      u64 v_c22 = _prim_aslst(db, v_c19, &ok34);
                      if (!ok34) return;
                      u64 v_c23 = _prim_llen(db, v_c22);
                      if (v_c23 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:16"); return; }
                      if (v_c0 != v_c23) return;
                      bool ok35 = true;
                      u64 v_c24 = _prim_lref(db, v_c22, v_c1, &ok35);
                      if (!ok35) return;
                      if (v_c2 != v_c24) return;
                      bool ok36 = true;
                      u64 v_c25 = _prim_lref(db, v_c22, v_c3, &ok36);
                      if (!ok36) return;
                      if (v_c4 != v_c25) return;
                      bool ok37 = true;
                      u64 v_c26 = _prim_lref(db, v_c22, v_c5, &ok37);
                      if (!ok37) return;
                      if (v_c6 != v_c26) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:16", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask7* _cont = new ReadTask7(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask7(db,b), false);
  // (crule (pre (let _00024sqc5EFT159 const4e07408562bedb8b60ce05c1) (let _00024sqc5bxU160 const5feceb66ffc86f38d952786c) (let _00024sqc3UTe161 const6b86b273ff34fce19d6b804e) (let _00024sqc5qfs162 const6b86b273ff34fce19d6b804e) (let _00024sqc6UGY163 constd4735e3a265e16eee03f5971) (let _00024sqc4r9A164 constd4735e3a265e16eee03f5971) (let _00024sqc2CcG165 const4e07408562bedb8b60ce05c1) (let _00024sqo8L4F167 const6b86b273ff34fce19d6b804e) (let _00024sqo6G1P166 const5feceb66ffc86f38d952786c) (let _00024sqo2Nvm169 constd4735e3a265e16eee03f5971) (let _00024sqo669y168 const6b86b273ff34fce19d6b804e) (let _00024sqo1fa8171 const4e07408562bedb8b60ce05c1) (let _00024sqo8rnZ170 constd4735e3a265e16eee03f5971) (let _00024sqo7ulb173 const6b86b273ff34fce19d6b804e) (let _00024sqo0YXk172 constd4735e3a265e16eee03f5971) (let _00024sqo02S4175 constd4735e3a265e16eee03f5971) (let _00024sqo81tB174 const6b86b273ff34fce19d6b804e) (let _00024sqo5Ac4177 const4e07408562bedb8b60ce05c1) (let _00024sqo1MJI176 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo02S4175 _00024sqo81tB174 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8L4F167 _00024sqo6G1P166 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo2Nvm169 _00024sqo669y168 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1fa8171 _00024sqo8rnZ170 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo7ulb173 _00024sqo0YXk172 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5Ac4177 _00024sqo1MJI176 _00024seq0) (join lst_rev (1 0) 1 _00024seq0 __t4lMv28) (join lst_rev_ans (0 1) 1 __t4lMv28 r) (letp _00024sql9jSN157 (aslst _00024seq0)) (let chk7Bmt450 (llen _00024sql9jSN157)) (eq _00024sqc5EFT159 chk7Bmt450) (letp chk2qhG451 (lref _00024sql9jSN157 _00024sqc5bxU160)) (eq _00024sqc3UTe161 chk2qhG451) (letp chk6XwB452 (lref _00024sql9jSN157 _00024sqc5qfs162)) (eq _00024sqc6UGY163 chk6XwB452) (letp chk7WjJ453 (lref _00024sql9jSN157 _00024sqc4r9A164)) (eq _00024sqc2CcG165 chk7WjJ453)) (head (emit reversed (0) r)) lst_ops.slog:16 #f)
  class ReadTask46 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex38;  slog::Index** $seq_atindex39;  slog::Index** $seq_atindex40;  slog::Index** $seq_atrindex41;  slog::Index** $seq_atrindex42;  slog::Index** lst_revindex43;  slog::Index** lst_rev_ansindex44;  slog::Index** $seq_atrdelta45;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reversed");
      std::vector<u16> ord47({0});
      slog::Relation* readrel48 = db->getRelation("reversed");
      head_index[0] = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 1, 2});
      slog::Relation* readrel50 = db->getRelation("$seq_atr");
      driver_index = readrel50->getIndex(ord49, true);
      std::vector<u16> ord51({0, 1, 2});
      slog::Relation* readrel52 = db->getRelation("$seq_at");
      $seq_atindex38 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({0, 1, 2});
      slog::Relation* readrel54 = db->getRelation("$seq_at");
      $seq_atindex39 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({0, 1, 2});
      slog::Relation* readrel56 = db->getRelation("$seq_at");
      $seq_atindex40 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1, 2});
      slog::Relation* readrel58 = db->getRelation("$seq_atr");
      $seq_atrindex41 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({0, 1, 2});
      slog::Relation* readrel60 = db->getRelation("$seq_atr");
      $seq_atrindex42 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({0, 1, 2});
      slog::Relation* readrel62 = db->getRelation("$seq_atr");
      $seq_atrdelta45 = readrel62->getIndex(ord61, true);
      std::vector<u16> ord63({1, 0});
      slog::Relation* readrel64 = db->getRelation("lst_rev");
      lst_revindex43 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex44 = readrel66->getIndex(ord65, false);
  
    }
    ReadTask46(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c17 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c15, v_c16, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m67) {
        u64 v_c19 = m67[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex38, std::array<u64,3>{v_c7, v_c8, v_c19}, [&](const std::array<u64,3>& m68) {
          slog::join_probe<3,3>($seq_atindex39, std::array<u64,3>{v_c9, v_c10, v_c19}, [&](const std::array<u64,3>& m69) {
            slog::join_probe<3,3>($seq_atindex40, std::array<u64,3>{v_c11, v_c12, v_c19}, [&](const std::array<u64,3>& m70) {
              slog::join_probe<3,3>($seq_atrindex41, std::array<u64,3>{v_c13, v_c14, v_c19}, [&](const std::array<u64,3>& m71) {
                slog::join_probe_old<3,3>($seq_atrindex42, $seq_atrdelta45, std::array<u64,3>{v_c17, v_c18, v_c19}, [&](const std::array<u64,3>& m72) {
                  slog::join_probe<2,1>(lst_revindex43, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m73) {
                    u64 v_c20 = m73[1];
                    slog::join_probe<2,1>(lst_rev_ansindex44, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m74) {
                      u64 v_c21 = m74[1];
                      bool ok75 = true;
                      u64 v_c22 = _prim_aslst(db, v_c19, &ok75);
                      if (!ok75) return;
                      u64 v_c27 = _prim_llen(db, v_c22);
                      if (v_c27 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:16"); return; }
                      if (v_c0 != v_c27) return;
                      bool ok76 = true;
                      u64 v_c28 = _prim_lref(db, v_c22, v_c1, &ok76);
                      if (!ok76) return;
                      if (v_c2 != v_c28) return;
                      bool ok77 = true;
                      u64 v_c29 = _prim_lref(db, v_c22, v_c3, &ok77);
                      if (!ok77) return;
                      if (v_c4 != v_c29) return;
                      bool ok78 = true;
                      u64 v_c30 = _prim_lref(db, v_c22, v_c5, &ok78);
                      if (!ok78) return;
                      if (v_c6 != v_c30) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:16", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask46* _cont = new ReadTask46(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask46(db,b), false);
  // (crule (pre (let _00024sqc5EFT159 const4e07408562bedb8b60ce05c1) (let _00024sqc5bxU160 const5feceb66ffc86f38d952786c) (let _00024sqc3UTe161 const6b86b273ff34fce19d6b804e) (let _00024sqc5qfs162 const6b86b273ff34fce19d6b804e) (let _00024sqc6UGY163 constd4735e3a265e16eee03f5971) (let _00024sqc4r9A164 constd4735e3a265e16eee03f5971) (let _00024sqc2CcG165 const4e07408562bedb8b60ce05c1) (let _00024sqo8L4F167 const6b86b273ff34fce19d6b804e) (let _00024sqo6G1P166 const5feceb66ffc86f38d952786c) (let _00024sqo2Nvm169 constd4735e3a265e16eee03f5971) (let _00024sqo669y168 const6b86b273ff34fce19d6b804e) (let _00024sqo1fa8171 const4e07408562bedb8b60ce05c1) (let _00024sqo8rnZ170 constd4735e3a265e16eee03f5971) (let _00024sqo7ulb173 const6b86b273ff34fce19d6b804e) (let _00024sqo0YXk172 constd4735e3a265e16eee03f5971) (let _00024sqo02S4175 constd4735e3a265e16eee03f5971) (let _00024sqo81tB174 const6b86b273ff34fce19d6b804e) (let _00024sqo5Ac4177 const4e07408562bedb8b60ce05c1) (let _00024sqo1MJI176 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo7ulb173 _00024sqo0YXk172 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8L4F167 _00024sqo6G1P166 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo2Nvm169 _00024sqo669y168 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1fa8171 _00024sqo8rnZ170 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo02S4175 _00024sqo81tB174 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5Ac4177 _00024sqo1MJI176 _00024seq0) (join lst_rev (1 0) 1 _00024seq0 __t4lMv28) (join lst_rev_ans (0 1) 1 __t4lMv28 r) (letp _00024sql9jSN157 (aslst _00024seq0)) (let chk1smY446 (llen _00024sql9jSN157)) (eq _00024sqc5EFT159 chk1smY446) (letp chk7Ufh447 (lref _00024sql9jSN157 _00024sqc5bxU160)) (eq _00024sqc3UTe161 chk7Ufh447) (letp chk0AEc448 (lref _00024sql9jSN157 _00024sqc5qfs162)) (eq _00024sqc6UGY163 chk0AEc448) (letp chk7a1b449 (lref _00024sql9jSN157 _00024sqc4r9A164)) (eq _00024sqc2CcG165 chk7a1b449)) (head (emit reversed (0) r)) lst_ops.slog:16 #f)
  class ReadTask88 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex79;  slog::Index** $seq_atindex80;  slog::Index** $seq_atindex81;  slog::Index** $seq_atrindex82;  slog::Index** $seq_atrindex83;  slog::Index** lst_revindex84;  slog::Index** lst_rev_ansindex85;  slog::Index** $seq_atrdelta86;  slog::Index** $seq_atrdelta87;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reversed");
      std::vector<u16> ord89({0});
      slog::Relation* readrel90 = db->getRelation("reversed");
      head_index[0] = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({0, 1, 2});
      slog::Relation* readrel92 = db->getRelation("$seq_atr");
      driver_index = readrel92->getIndex(ord91, true);
      std::vector<u16> ord93({0, 1, 2});
      slog::Relation* readrel94 = db->getRelation("$seq_at");
      $seq_atindex79 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({0, 1, 2});
      slog::Relation* readrel96 = db->getRelation("$seq_at");
      $seq_atindex80 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({0, 1, 2});
      slog::Relation* readrel98 = db->getRelation("$seq_at");
      $seq_atindex81 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({0, 1, 2});
      slog::Relation* readrel100 = db->getRelation("$seq_atr");
      $seq_atrindex82 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({0, 1, 2});
      slog::Relation* readrel102 = db->getRelation("$seq_atr");
      $seq_atrdelta86 = readrel102->getIndex(ord101, true);
      std::vector<u16> ord103({0, 1, 2});
      slog::Relation* readrel104 = db->getRelation("$seq_atr");
      $seq_atrindex83 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1, 2});
      slog::Relation* readrel106 = db->getRelation("$seq_atr");
      $seq_atrdelta87 = readrel106->getIndex(ord105, true);
      std::vector<u16> ord107({1, 0});
      slog::Relation* readrel108 = db->getRelation("lst_rev");
      lst_revindex84 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex85 = readrel110->getIndex(ord109, false);
  
    }
    ReadTask88(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c17 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c13, v_c14, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m111) {
        u64 v_c19 = m111[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex79, std::array<u64,3>{v_c7, v_c8, v_c19}, [&](const std::array<u64,3>& m112) {
          slog::join_probe<3,3>($seq_atindex80, std::array<u64,3>{v_c9, v_c10, v_c19}, [&](const std::array<u64,3>& m113) {
            slog::join_probe<3,3>($seq_atindex81, std::array<u64,3>{v_c11, v_c12, v_c19}, [&](const std::array<u64,3>& m114) {
              slog::join_probe_old<3,3>($seq_atrindex82, $seq_atrdelta86, std::array<u64,3>{v_c15, v_c16, v_c19}, [&](const std::array<u64,3>& m115) {
                slog::join_probe_old<3,3>($seq_atrindex83, $seq_atrdelta87, std::array<u64,3>{v_c17, v_c18, v_c19}, [&](const std::array<u64,3>& m116) {
                  slog::join_probe<2,1>(lst_revindex84, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m117) {
                    u64 v_c20 = m117[1];
                    slog::join_probe<2,1>(lst_rev_ansindex85, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m118) {
                      u64 v_c21 = m118[1];
                      bool ok119 = true;
                      u64 v_c22 = _prim_aslst(db, v_c19, &ok119);
                      if (!ok119) return;
                      u64 v_c31 = _prim_llen(db, v_c22);
                      if (v_c31 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:16"); return; }
                      if (v_c0 != v_c31) return;
                      bool ok120 = true;
                      u64 v_c32 = _prim_lref(db, v_c22, v_c1, &ok120);
                      if (!ok120) return;
                      if (v_c2 != v_c32) return;
                      bool ok121 = true;
                      u64 v_c33 = _prim_lref(db, v_c22, v_c3, &ok121);
                      if (!ok121) return;
                      if (v_c4 != v_c33) return;
                      bool ok122 = true;
                      u64 v_c34 = _prim_lref(db, v_c22, v_c5, &ok122);
                      if (!ok122) return;
                      if (v_c6 != v_c34) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:16", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask88* _cont = new ReadTask88(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask88(db,b), false);
  // (crule (pre (let _00024sqc5EFT159 const4e07408562bedb8b60ce05c1) (let _00024sqc5bxU160 const5feceb66ffc86f38d952786c) (let _00024sqc3UTe161 const6b86b273ff34fce19d6b804e) (let _00024sqc5qfs162 const6b86b273ff34fce19d6b804e) (let _00024sqc6UGY163 constd4735e3a265e16eee03f5971) (let _00024sqc4r9A164 constd4735e3a265e16eee03f5971) (let _00024sqc2CcG165 const4e07408562bedb8b60ce05c1) (let _00024sqo8L4F167 const6b86b273ff34fce19d6b804e) (let _00024sqo6G1P166 const5feceb66ffc86f38d952786c) (let _00024sqo2Nvm169 constd4735e3a265e16eee03f5971) (let _00024sqo669y168 const6b86b273ff34fce19d6b804e) (let _00024sqo1fa8171 const4e07408562bedb8b60ce05c1) (let _00024sqo8rnZ170 constd4735e3a265e16eee03f5971) (let _00024sqo7ulb173 const6b86b273ff34fce19d6b804e) (let _00024sqo0YXk172 constd4735e3a265e16eee03f5971) (let _00024sqo02S4175 constd4735e3a265e16eee03f5971) (let _00024sqo81tB174 const6b86b273ff34fce19d6b804e) (let _00024sqo5Ac4177 const4e07408562bedb8b60ce05c1) (let _00024sqo1MJI176 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo1fa8171 _00024sqo8rnZ170 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8L4F167 _00024sqo6G1P166 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo2Nvm169 _00024sqo669y168 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo7ulb173 _00024sqo0YXk172 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo02S4175 _00024sqo81tB174 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5Ac4177 _00024sqo1MJI176 _00024seq0) (join lst_rev (1 0) 1 _00024seq0 __t4lMv28) (join lst_rev_ans (0 1) 1 __t4lMv28 r) (letp _00024sql9jSN157 (aslst _00024seq0)) (let chk33UE442 (llen _00024sql9jSN157)) (eq _00024sqc5EFT159 chk33UE442) (letp chk23Xn443 (lref _00024sql9jSN157 _00024sqc5bxU160)) (eq _00024sqc3UTe161 chk23Xn443) (letp chk3kuR444 (lref _00024sql9jSN157 _00024sqc5qfs162)) (eq _00024sqc6UGY163 chk3kuR444) (letp chk0HcT445 (lref _00024sql9jSN157 _00024sqc4r9A164)) (eq _00024sqc2CcG165 chk0HcT445)) (head (emit reversed (0) r)) lst_ops.slog:16 #f)
  class ReadTask133 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex123;  slog::Index** $seq_atindex124;  slog::Index** $seq_atrindex125;  slog::Index** $seq_atrindex126;  slog::Index** $seq_atrindex127;  slog::Index** lst_revindex128;  slog::Index** lst_rev_ansindex129;  slog::Index** $seq_atrdelta130;  slog::Index** $seq_atrdelta131;  slog::Index** $seq_atrdelta132;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reversed");
      std::vector<u16> ord134({0});
      slog::Relation* readrel135 = db->getRelation("reversed");
      head_index[0] = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({0, 1, 2});
      slog::Relation* readrel137 = db->getRelation("$seq_at");
      driver_index = readrel137->getIndex(ord136, true);
      std::vector<u16> ord138({0, 1, 2});
      slog::Relation* readrel139 = db->getRelation("$seq_at");
      $seq_atindex123 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({0, 1, 2});
      slog::Relation* readrel141 = db->getRelation("$seq_at");
      $seq_atindex124 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({0, 1, 2});
      slog::Relation* readrel143 = db->getRelation("$seq_atr");
      $seq_atrindex125 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({0, 1, 2});
      slog::Relation* readrel145 = db->getRelation("$seq_atr");
      $seq_atrdelta130 = readrel145->getIndex(ord144, true);
      std::vector<u16> ord146({0, 1, 2});
      slog::Relation* readrel147 = db->getRelation("$seq_atr");
      $seq_atrindex126 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0, 1, 2});
      slog::Relation* readrel149 = db->getRelation("$seq_atr");
      $seq_atrdelta131 = readrel149->getIndex(ord148, true);
      std::vector<u16> ord150({0, 1, 2});
      slog::Relation* readrel151 = db->getRelation("$seq_atr");
      $seq_atrindex127 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({0, 1, 2});
      slog::Relation* readrel153 = db->getRelation("$seq_atr");
      $seq_atrdelta132 = readrel153->getIndex(ord152, true);
      std::vector<u16> ord154({1, 0});
      slog::Relation* readrel155 = db->getRelation("lst_rev");
      lst_revindex128 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({0, 1});
      slog::Relation* readrel157 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex129 = readrel157->getIndex(ord156, false);
  
    }
    ReadTask133(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c17 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c11, v_c12, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m158) {
        u64 v_c19 = m158[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex123, std::array<u64,3>{v_c7, v_c8, v_c19}, [&](const std::array<u64,3>& m159) {
          slog::join_probe<3,3>($seq_atindex124, std::array<u64,3>{v_c9, v_c10, v_c19}, [&](const std::array<u64,3>& m160) {
            slog::join_probe_old<3,3>($seq_atrindex125, $seq_atrdelta130, std::array<u64,3>{v_c13, v_c14, v_c19}, [&](const std::array<u64,3>& m161) {
              slog::join_probe_old<3,3>($seq_atrindex126, $seq_atrdelta131, std::array<u64,3>{v_c15, v_c16, v_c19}, [&](const std::array<u64,3>& m162) {
                slog::join_probe_old<3,3>($seq_atrindex127, $seq_atrdelta132, std::array<u64,3>{v_c17, v_c18, v_c19}, [&](const std::array<u64,3>& m163) {
                  slog::join_probe<2,1>(lst_revindex128, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m164) {
                    u64 v_c20 = m164[1];
                    slog::join_probe<2,1>(lst_rev_ansindex129, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m165) {
                      u64 v_c21 = m165[1];
                      bool ok166 = true;
                      u64 v_c22 = _prim_aslst(db, v_c19, &ok166);
                      if (!ok166) return;
                      u64 v_c35 = _prim_llen(db, v_c22);
                      if (v_c35 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:16"); return; }
                      if (v_c0 != v_c35) return;
                      bool ok167 = true;
                      u64 v_c36 = _prim_lref(db, v_c22, v_c1, &ok167);
                      if (!ok167) return;
                      if (v_c2 != v_c36) return;
                      bool ok168 = true;
                      u64 v_c37 = _prim_lref(db, v_c22, v_c3, &ok168);
                      if (!ok168) return;
                      if (v_c4 != v_c37) return;
                      bool ok169 = true;
                      u64 v_c38 = _prim_lref(db, v_c22, v_c5, &ok169);
                      if (!ok169) return;
                      if (v_c6 != v_c38) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:16", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask133* _cont = new ReadTask133(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask133(db,b), false);
  // (crule (pre (let _00024sqc5EFT159 const4e07408562bedb8b60ce05c1) (let _00024sqc5bxU160 const5feceb66ffc86f38d952786c) (let _00024sqc3UTe161 const6b86b273ff34fce19d6b804e) (let _00024sqc5qfs162 const6b86b273ff34fce19d6b804e) (let _00024sqc6UGY163 constd4735e3a265e16eee03f5971) (let _00024sqc4r9A164 constd4735e3a265e16eee03f5971) (let _00024sqc2CcG165 const4e07408562bedb8b60ce05c1) (let _00024sqo8L4F167 const6b86b273ff34fce19d6b804e) (let _00024sqo6G1P166 const5feceb66ffc86f38d952786c) (let _00024sqo2Nvm169 constd4735e3a265e16eee03f5971) (let _00024sqo669y168 const6b86b273ff34fce19d6b804e) (let _00024sqo1fa8171 const4e07408562bedb8b60ce05c1) (let _00024sqo8rnZ170 constd4735e3a265e16eee03f5971) (let _00024sqo7ulb173 const6b86b273ff34fce19d6b804e) (let _00024sqo0YXk172 constd4735e3a265e16eee03f5971) (let _00024sqo02S4175 constd4735e3a265e16eee03f5971) (let _00024sqo81tB174 const6b86b273ff34fce19d6b804e) (let _00024sqo5Ac4177 const4e07408562bedb8b60ce05c1) (let _00024sqo1MJI176 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo2Nvm169 _00024sqo669y168 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8L4F167 _00024sqo6G1P166 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo1fa8171 _00024sqo8rnZ170 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo7ulb173 _00024sqo0YXk172 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo02S4175 _00024sqo81tB174 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5Ac4177 _00024sqo1MJI176 _00024seq0) (join lst_rev (1 0) 1 _00024seq0 __t4lMv28) (join lst_rev_ans (0 1) 1 __t4lMv28 r) (letp _00024sql9jSN157 (aslst _00024seq0)) (let chk8gqg438 (llen _00024sql9jSN157)) (eq _00024sqc5EFT159 chk8gqg438) (letp chk4Voc439 (lref _00024sql9jSN157 _00024sqc5bxU160)) (eq _00024sqc3UTe161 chk4Voc439) (letp chk6Lgw440 (lref _00024sql9jSN157 _00024sqc5qfs162)) (eq _00024sqc6UGY163 chk6Lgw440) (letp chk25CL441 (lref _00024sql9jSN157 _00024sqc4r9A164)) (eq _00024sqc2CcG165 chk25CL441)) (head (emit reversed (0) r)) lst_ops.slog:16 #f)
  class ReadTask181 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex170;  slog::Index** $seq_atindex171;  slog::Index** $seq_atrindex172;  slog::Index** $seq_atrindex173;  slog::Index** $seq_atrindex174;  slog::Index** lst_revindex175;  slog::Index** lst_rev_ansindex176;  slog::Index** $seq_atdelta177;  slog::Index** $seq_atrdelta178;  slog::Index** $seq_atrdelta179;  slog::Index** $seq_atrdelta180;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reversed");
      std::vector<u16> ord182({0});
      slog::Relation* readrel183 = db->getRelation("reversed");
      head_index[0] = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({0, 1, 2});
      slog::Relation* readrel185 = db->getRelation("$seq_at");
      driver_index = readrel185->getIndex(ord184, true);
      std::vector<u16> ord186({0, 1, 2});
      slog::Relation* readrel187 = db->getRelation("$seq_at");
      $seq_atindex170 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({0, 1, 2});
      slog::Relation* readrel189 = db->getRelation("$seq_at");
      $seq_atindex171 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({0, 1, 2});
      slog::Relation* readrel191 = db->getRelation("$seq_at");
      $seq_atdelta177 = readrel191->getIndex(ord190, true);
      std::vector<u16> ord192({0, 1, 2});
      slog::Relation* readrel193 = db->getRelation("$seq_atr");
      $seq_atrindex172 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 1, 2});
      slog::Relation* readrel195 = db->getRelation("$seq_atr");
      $seq_atrdelta178 = readrel195->getIndex(ord194, true);
      std::vector<u16> ord196({0, 1, 2});
      slog::Relation* readrel197 = db->getRelation("$seq_atr");
      $seq_atrindex173 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({0, 1, 2});
      slog::Relation* readrel199 = db->getRelation("$seq_atr");
      $seq_atrdelta179 = readrel199->getIndex(ord198, true);
      std::vector<u16> ord200({0, 1, 2});
      slog::Relation* readrel201 = db->getRelation("$seq_atr");
      $seq_atrindex174 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({0, 1, 2});
      slog::Relation* readrel203 = db->getRelation("$seq_atr");
      $seq_atrdelta180 = readrel203->getIndex(ord202, true);
      std::vector<u16> ord204({1, 0});
      slog::Relation* readrel205 = db->getRelation("lst_rev");
      lst_revindex175 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({0, 1});
      slog::Relation* readrel207 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex176 = readrel207->getIndex(ord206, false);
  
    }
    ReadTask181(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c17 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c9, v_c10, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m208) {
        u64 v_c19 = m208[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex170, std::array<u64,3>{v_c7, v_c8, v_c19}, [&](const std::array<u64,3>& m209) {
          slog::join_probe_old<3,3>($seq_atindex171, $seq_atdelta177, std::array<u64,3>{v_c11, v_c12, v_c19}, [&](const std::array<u64,3>& m210) {
            slog::join_probe_old<3,3>($seq_atrindex172, $seq_atrdelta178, std::array<u64,3>{v_c13, v_c14, v_c19}, [&](const std::array<u64,3>& m211) {
              slog::join_probe_old<3,3>($seq_atrindex173, $seq_atrdelta179, std::array<u64,3>{v_c15, v_c16, v_c19}, [&](const std::array<u64,3>& m212) {
                slog::join_probe_old<3,3>($seq_atrindex174, $seq_atrdelta180, std::array<u64,3>{v_c17, v_c18, v_c19}, [&](const std::array<u64,3>& m213) {
                  slog::join_probe<2,1>(lst_revindex175, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m214) {
                    u64 v_c20 = m214[1];
                    slog::join_probe<2,1>(lst_rev_ansindex176, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m215) {
                      u64 v_c21 = m215[1];
                      bool ok216 = true;
                      u64 v_c22 = _prim_aslst(db, v_c19, &ok216);
                      if (!ok216) return;
                      u64 v_c39 = _prim_llen(db, v_c22);
                      if (v_c39 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:16"); return; }
                      if (v_c0 != v_c39) return;
                      bool ok217 = true;
                      u64 v_c40 = _prim_lref(db, v_c22, v_c1, &ok217);
                      if (!ok217) return;
                      if (v_c2 != v_c40) return;
                      bool ok218 = true;
                      u64 v_c41 = _prim_lref(db, v_c22, v_c3, &ok218);
                      if (!ok218) return;
                      if (v_c4 != v_c41) return;
                      bool ok219 = true;
                      u64 v_c42 = _prim_lref(db, v_c22, v_c5, &ok219);
                      if (!ok219) return;
                      if (v_c6 != v_c42) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:16", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask181* _cont = new ReadTask181(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask181(db,b), false);
  // (crule (pre (let _00024sqc5EFT159 const4e07408562bedb8b60ce05c1) (let _00024sqc5bxU160 const5feceb66ffc86f38d952786c) (let _00024sqc3UTe161 const6b86b273ff34fce19d6b804e) (let _00024sqc5qfs162 const6b86b273ff34fce19d6b804e) (let _00024sqc6UGY163 constd4735e3a265e16eee03f5971) (let _00024sqc4r9A164 constd4735e3a265e16eee03f5971) (let _00024sqc2CcG165 const4e07408562bedb8b60ce05c1) (let _00024sqo8L4F167 const6b86b273ff34fce19d6b804e) (let _00024sqo6G1P166 const5feceb66ffc86f38d952786c) (let _00024sqo2Nvm169 constd4735e3a265e16eee03f5971) (let _00024sqo669y168 const6b86b273ff34fce19d6b804e) (let _00024sqo1fa8171 const4e07408562bedb8b60ce05c1) (let _00024sqo8rnZ170 constd4735e3a265e16eee03f5971) (let _00024sqo7ulb173 const6b86b273ff34fce19d6b804e) (let _00024sqo0YXk172 constd4735e3a265e16eee03f5971) (let _00024sqo02S4175 constd4735e3a265e16eee03f5971) (let _00024sqo81tB174 const6b86b273ff34fce19d6b804e) (let _00024sqo5Ac4177 const4e07408562bedb8b60ce05c1) (let _00024sqo1MJI176 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo8L4F167 _00024sqo6G1P166 _00024seq0) (body (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo2Nvm169 _00024sqo669y168 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo1fa8171 _00024sqo8rnZ170 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo7ulb173 _00024sqo0YXk172 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo02S4175 _00024sqo81tB174 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5Ac4177 _00024sqo1MJI176 _00024seq0) (join lst_rev (1 0) 1 _00024seq0 __t4lMv28) (join lst_rev_ans (0 1) 1 __t4lMv28 r) (letp _00024sql9jSN157 (aslst _00024seq0)) (let chk4olk434 (llen _00024sql9jSN157)) (eq _00024sqc5EFT159 chk4olk434) (letp chk3fQJ435 (lref _00024sql9jSN157 _00024sqc5bxU160)) (eq _00024sqc3UTe161 chk3fQJ435) (letp chk1PYC436 (lref _00024sql9jSN157 _00024sqc5qfs162)) (eq _00024sqc6UGY163 chk1PYC436) (letp chk5BdE437 (lref _00024sql9jSN157 _00024sqc4r9A164)) (eq _00024sqc2CcG165 chk5BdE437)) (head (emit reversed (0) r)) lst_ops.slog:16 #f)
  class ReadTask232 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex220;  slog::Index** $seq_atindex221;  slog::Index** $seq_atrindex222;  slog::Index** $seq_atrindex223;  slog::Index** $seq_atrindex224;  slog::Index** lst_revindex225;  slog::Index** lst_rev_ansindex226;  slog::Index** $seq_atdelta227;  slog::Index** $seq_atdelta228;  slog::Index** $seq_atrdelta229;  slog::Index** $seq_atrdelta230;  slog::Index** $seq_atrdelta231;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reversed");
      std::vector<u16> ord233({0});
      slog::Relation* readrel234 = db->getRelation("reversed");
      head_index[0] = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 1, 2});
      slog::Relation* readrel236 = db->getRelation("$seq_at");
      driver_index = readrel236->getIndex(ord235, true);
      std::vector<u16> ord237({0, 1, 2});
      slog::Relation* readrel238 = db->getRelation("$seq_at");
      $seq_atindex220 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({0, 1, 2});
      slog::Relation* readrel240 = db->getRelation("$seq_at");
      $seq_atdelta227 = readrel240->getIndex(ord239, true);
      std::vector<u16> ord241({0, 1, 2});
      slog::Relation* readrel242 = db->getRelation("$seq_at");
      $seq_atindex221 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({0, 1, 2});
      slog::Relation* readrel244 = db->getRelation("$seq_at");
      $seq_atdelta228 = readrel244->getIndex(ord243, true);
      std::vector<u16> ord245({0, 1, 2});
      slog::Relation* readrel246 = db->getRelation("$seq_atr");
      $seq_atrindex222 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({0, 1, 2});
      slog::Relation* readrel248 = db->getRelation("$seq_atr");
      $seq_atrdelta229 = readrel248->getIndex(ord247, true);
      std::vector<u16> ord249({0, 1, 2});
      slog::Relation* readrel250 = db->getRelation("$seq_atr");
      $seq_atrindex223 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({0, 1, 2});
      slog::Relation* readrel252 = db->getRelation("$seq_atr");
      $seq_atrdelta230 = readrel252->getIndex(ord251, true);
      std::vector<u16> ord253({0, 1, 2});
      slog::Relation* readrel254 = db->getRelation("$seq_atr");
      $seq_atrindex224 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({0, 1, 2});
      slog::Relation* readrel256 = db->getRelation("$seq_atr");
      $seq_atrdelta231 = readrel256->getIndex(ord255, true);
      std::vector<u16> ord257({1, 0});
      slog::Relation* readrel258 = db->getRelation("lst_rev");
      lst_revindex225 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({0, 1});
      slog::Relation* readrel260 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex226 = readrel260->getIndex(ord259, false);
  
    }
    ReadTask232(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_constd4735e3a265e16eee03f5971;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c17 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c7, v_c8, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m261) {
        u64 v_c19 = m261[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex220, $seq_atdelta227, std::array<u64,3>{v_c9, v_c10, v_c19}, [&](const std::array<u64,3>& m262) {
          slog::join_probe_old<3,3>($seq_atindex221, $seq_atdelta228, std::array<u64,3>{v_c11, v_c12, v_c19}, [&](const std::array<u64,3>& m263) {
            slog::join_probe_old<3,3>($seq_atrindex222, $seq_atrdelta229, std::array<u64,3>{v_c13, v_c14, v_c19}, [&](const std::array<u64,3>& m264) {
              slog::join_probe_old<3,3>($seq_atrindex223, $seq_atrdelta230, std::array<u64,3>{v_c15, v_c16, v_c19}, [&](const std::array<u64,3>& m265) {
                slog::join_probe_old<3,3>($seq_atrindex224, $seq_atrdelta231, std::array<u64,3>{v_c17, v_c18, v_c19}, [&](const std::array<u64,3>& m266) {
                  slog::join_probe<2,1>(lst_revindex225, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m267) {
                    u64 v_c20 = m267[1];
                    slog::join_probe<2,1>(lst_rev_ansindex226, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m268) {
                      u64 v_c21 = m268[1];
                      bool ok269 = true;
                      u64 v_c22 = _prim_aslst(db, v_c19, &ok269);
                      if (!ok269) return;
                      u64 v_c43 = _prim_llen(db, v_c22);
                      if (v_c43 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:16"); return; }
                      if (v_c0 != v_c43) return;
                      bool ok270 = true;
                      u64 v_c44 = _prim_lref(db, v_c22, v_c1, &ok270);
                      if (!ok270) return;
                      if (v_c2 != v_c44) return;
                      bool ok271 = true;
                      u64 v_c45 = _prim_lref(db, v_c22, v_c3, &ok271);
                      if (!ok271) return;
                      if (v_c4 != v_c45) return;
                      bool ok272 = true;
                      u64 v_c46 = _prim_lref(db, v_c22, v_c5, &ok272);
                      if (!ok272) return;
                      if (v_c6 != v_c46) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:16", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask232* _cont = new ReadTask232(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask232(db,b), false);
  // (crule (pre (let __tconst4tMq12 constd4735e3a265e16eee03f5971) (let _00024sqc7CLq75 const4b227777d4dd1fc61c6f884f) (let _00024sqc2BUf76 const5feceb66ffc86f38d952786c) (let _00024sqc9cGl77 const4a44dc15364204a80fe80e90) (let _00024sqc5J0l78 const6b86b273ff34fce19d6b804e) (let _00024sqc8mlt79 constf5ca38f748a1d6eaf726b8a4) (let _00024sqc3TWC80 constd4735e3a265e16eee03f5971) (let _00024sqc0vYG81 const624b60c58c9d8bfb6ff1886c) (let _00024sqc14Mu82 const4e07408562bedb8b60ce05c1) (let _00024sqc3HuO83 constd59eced1ded07f84c145592f) (let _00024sqo0lYp85 const4a44dc15364204a80fe80e90) (let _00024sqo9LAW84 const5feceb66ffc86f38d952786c) (let _00024sqo5UlO87 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo2Pn786 const6b86b273ff34fce19d6b804e) (let _00024sqo116y89 const624b60c58c9d8bfb6ff1886c) (let _00024sqo8IQh88 constd4735e3a265e16eee03f5971) (let _00024sqo7RbK91 constd59eced1ded07f84c145592f) (let _00024sqo36U490 const4e07408562bedb8b60ce05c1) (let _00024sqo5saO93 const4a44dc15364204a80fe80e90) (let _00024sqo1aiI92 const4e07408562bedb8b60ce05c1) (let _00024sqo1ciC95 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo7rIE94 constd4735e3a265e16eee03f5971) (let _00024sqo0SAK97 const624b60c58c9d8bfb6ff1886c) (let _00024sqo1Nma96 const6b86b273ff34fce19d6b804e) (let _00024sqo2rtj99 constd59eced1ded07f84c145592f) (let _00024sqo2fAT98 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo2rtj99 _00024sqo2fAT98 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0lYp85 _00024sqo9LAW84 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo5UlO87 _00024sqo2Pn786 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo116y89 _00024sqo8IQh88 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo7RbK91 _00024sqo36U490 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5saO93 _00024sqo1aiI92 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo1ciC95 _00024sqo7rIE94 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo0SAK97 _00024sqo1Nma96 _00024seq0) (join lst_ref (1 2 0) 2 _00024seq0 __tconst4tMq12 __t0saG13) (join lst_ref_ans (0 1) 1 __t0saG13 r) (letp _00024sql3t1j73 (aslst _00024seq0)) (let chk5jE9429 (llen _00024sql3t1j73)) (eq _00024sqc7CLq75 chk5jE9429) (letp chk5ypR430 (lref _00024sql3t1j73 _00024sqc2BUf76)) (eq _00024sqc9cGl77 chk5ypR430) (letp chk8N2c431 (lref _00024sql3t1j73 _00024sqc5J0l78)) (eq _00024sqc8mlt79 chk8N2c431) (letp chk9LsB432 (lref _00024sql3t1j73 _00024sqc3TWC80)) (eq _00024sqc0vYG81 chk9LsB432) (letp chk69kj433 (lref _00024sql3t1j73 _00024sqc14Mu82)) (eq _00024sqc3HuO83 chk69kj433)) (head (emit third (0) r)) lst_ops.slog:13 #f)
  class ReadTask282 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex273;  slog::Index** $seq_atindex274;  slog::Index** $seq_atindex275;  slog::Index** $seq_atindex276;  slog::Index** $seq_atrindex277;  slog::Index** $seq_atrindex278;  slog::Index** $seq_atrindex279;  slog::Index** lst_refindex280;  slog::Index** lst_ref_ansindex281;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("third");
      std::vector<u16> ord283({0});
      slog::Relation* readrel284 = db->getRelation("third");
      head_index[0] = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1, 2});
      slog::Relation* readrel286 = db->getRelation("$seq_atr");
      driver_index = readrel286->getIndex(ord285, true);
      std::vector<u16> ord287({0, 1, 2});
      slog::Relation* readrel288 = db->getRelation("$seq_at");
      $seq_atindex273 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1, 2});
      slog::Relation* readrel290 = db->getRelation("$seq_at");
      $seq_atindex274 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({0, 1, 2});
      slog::Relation* readrel292 = db->getRelation("$seq_at");
      $seq_atindex275 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 1, 2});
      slog::Relation* readrel294 = db->getRelation("$seq_at");
      $seq_atindex276 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({0, 1, 2});
      slog::Relation* readrel296 = db->getRelation("$seq_atr");
      $seq_atrindex277 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({0, 1, 2});
      slog::Relation* readrel298 = db->getRelation("$seq_atr");
      $seq_atrindex278 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({0, 1, 2});
      slog::Relation* readrel300 = db->getRelation("$seq_atr");
      $seq_atrindex279 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 2, 0});
      slog::Relation* readrel302 = db->getRelation("lst_ref");
      lst_refindex280 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({0, 1});
      slog::Relation* readrel304 = db->getRelation("lst_ref_ans");
      lst_ref_ansindex281 = readrel304->getIndex(ord303, false);
  
    }
    ReadTask282(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constd4735e3a265e16eee03f5971;
      u64 v_c48 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const4a44dc15364204a80fe80e90;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c53 = v_constd4735e3a265e16eee03f5971;
      u64 v_c54 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c55 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c56 = v_constd59eced1ded07f84c145592f;
      u64 v_c57 = v_const4a44dc15364204a80fe80e90;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd59eced1ded07f84c145592f;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const4a44dc15364204a80fe80e90;
      u64 v_c66 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c67 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_constd59eced1ded07f84c145592f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c71, v_c72, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m305) {
        u64 v_c19 = m305[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex273, std::array<u64,3>{v_c57, v_c58, v_c19}, [&](const std::array<u64,3>& m306) {
          slog::join_probe<3,3>($seq_atindex274, std::array<u64,3>{v_c59, v_c60, v_c19}, [&](const std::array<u64,3>& m307) {
            slog::join_probe<3,3>($seq_atindex275, std::array<u64,3>{v_c61, v_c62, v_c19}, [&](const std::array<u64,3>& m308) {
              slog::join_probe<3,3>($seq_atindex276, std::array<u64,3>{v_c63, v_c64, v_c19}, [&](const std::array<u64,3>& m309) {
                slog::join_probe<3,3>($seq_atrindex277, std::array<u64,3>{v_c65, v_c66, v_c19}, [&](const std::array<u64,3>& m310) {
                  slog::join_probe<3,3>($seq_atrindex278, std::array<u64,3>{v_c67, v_c68, v_c19}, [&](const std::array<u64,3>& m311) {
                    slog::join_probe<3,3>($seq_atrindex279, std::array<u64,3>{v_c69, v_c70, v_c19}, [&](const std::array<u64,3>& m312) {
                      slog::join_probe<3,2>(lst_refindex280, std::array<u64,3>{v_c19, v_c47, 0}, [&](const std::array<u64,3>& m313) {
                        u64 v_c73 = m313[2];
                        slog::join_probe<2,1>(lst_ref_ansindex281, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m314) {
                          u64 v_c21 = m314[1];
                          bool ok315 = true;
                          u64 v_c74 = _prim_aslst(db, v_c19, &ok315);
                          if (!ok315) return;
                          u64 v_c75 = _prim_llen(db, v_c74);
                          if (v_c75 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:13"); return; }
                          if (v_c48 != v_c75) return;
                          bool ok316 = true;
                          u64 v_c76 = _prim_lref(db, v_c74, v_c49, &ok316);
                          if (!ok316) return;
                          if (v_c50 != v_c76) return;
                          bool ok317 = true;
                          u64 v_c77 = _prim_lref(db, v_c74, v_c51, &ok317);
                          if (!ok317) return;
                          if (v_c52 != v_c77) return;
                          bool ok318 = true;
                          u64 v_c78 = _prim_lref(db, v_c74, v_c53, &ok318);
                          if (!ok318) return;
                          if (v_c54 != v_c78) return;
                          bool ok319 = true;
                          u64 v_c79 = _prim_lref(db, v_c74, v_c55, &ok319);
                          if (!ok319) return;
                          if (v_c56 != v_c79) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:13", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask282* _cont = new ReadTask282(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask282(db,b), false);
  // (crule (pre (let __tconst4tMq12 constd4735e3a265e16eee03f5971) (let _00024sqc7CLq75 const4b227777d4dd1fc61c6f884f) (let _00024sqc2BUf76 const5feceb66ffc86f38d952786c) (let _00024sqc9cGl77 const4a44dc15364204a80fe80e90) (let _00024sqc5J0l78 const6b86b273ff34fce19d6b804e) (let _00024sqc8mlt79 constf5ca38f748a1d6eaf726b8a4) (let _00024sqc3TWC80 constd4735e3a265e16eee03f5971) (let _00024sqc0vYG81 const624b60c58c9d8bfb6ff1886c) (let _00024sqc14Mu82 const4e07408562bedb8b60ce05c1) (let _00024sqc3HuO83 constd59eced1ded07f84c145592f) (let _00024sqo0lYp85 const4a44dc15364204a80fe80e90) (let _00024sqo9LAW84 const5feceb66ffc86f38d952786c) (let _00024sqo5UlO87 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo2Pn786 const6b86b273ff34fce19d6b804e) (let _00024sqo116y89 const624b60c58c9d8bfb6ff1886c) (let _00024sqo8IQh88 constd4735e3a265e16eee03f5971) (let _00024sqo7RbK91 constd59eced1ded07f84c145592f) (let _00024sqo36U490 const4e07408562bedb8b60ce05c1) (let _00024sqo5saO93 const4a44dc15364204a80fe80e90) (let _00024sqo1aiI92 const4e07408562bedb8b60ce05c1) (let _00024sqo1ciC95 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo7rIE94 constd4735e3a265e16eee03f5971) (let _00024sqo0SAK97 const624b60c58c9d8bfb6ff1886c) (let _00024sqo1Nma96 const6b86b273ff34fce19d6b804e) (let _00024sqo2rtj99 constd59eced1ded07f84c145592f) (let _00024sqo2fAT98 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo0SAK97 _00024sqo1Nma96 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0lYp85 _00024sqo9LAW84 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo5UlO87 _00024sqo2Pn786 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo116y89 _00024sqo8IQh88 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo7RbK91 _00024sqo36U490 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5saO93 _00024sqo1aiI92 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo1ciC95 _00024sqo7rIE94 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2rtj99 _00024sqo2fAT98 _00024seq0) (join lst_ref (1 2 0) 2 _00024seq0 __tconst4tMq12 __t0saG13) (join lst_ref_ans (0 1) 1 __t0saG13 r) (letp _00024sql3t1j73 (aslst _00024seq0)) (let chk0Ul0424 (llen _00024sql3t1j73)) (eq _00024sqc7CLq75 chk0Ul0424) (letp chk4NPe425 (lref _00024sql3t1j73 _00024sqc2BUf76)) (eq _00024sqc9cGl77 chk4NPe425) (letp chk8z9Y426 (lref _00024sql3t1j73 _00024sqc5J0l78)) (eq _00024sqc8mlt79 chk8z9Y426) (letp chk7ymZ427 (lref _00024sql3t1j73 _00024sqc3TWC80)) (eq _00024sqc0vYG81 chk7ymZ427) (letp chk0NFT428 (lref _00024sql3t1j73 _00024sqc14Mu82)) (eq _00024sqc3HuO83 chk0NFT428)) (head (emit third (0) r)) lst_ops.slog:13 #f)
  class ReadTask330 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex320;  slog::Index** $seq_atindex321;  slog::Index** $seq_atindex322;  slog::Index** $seq_atindex323;  slog::Index** $seq_atrindex324;  slog::Index** $seq_atrindex325;  slog::Index** $seq_atrindex326;  slog::Index** lst_refindex327;  slog::Index** lst_ref_ansindex328;  slog::Index** $seq_atrdelta329;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("third");
      std::vector<u16> ord331({0});
      slog::Relation* readrel332 = db->getRelation("third");
      head_index[0] = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({0, 1, 2});
      slog::Relation* readrel334 = db->getRelation("$seq_atr");
      driver_index = readrel334->getIndex(ord333, true);
      std::vector<u16> ord335({0, 1, 2});
      slog::Relation* readrel336 = db->getRelation("$seq_at");
      $seq_atindex320 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({0, 1, 2});
      slog::Relation* readrel338 = db->getRelation("$seq_at");
      $seq_atindex321 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({0, 1, 2});
      slog::Relation* readrel340 = db->getRelation("$seq_at");
      $seq_atindex322 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({0, 1, 2});
      slog::Relation* readrel342 = db->getRelation("$seq_at");
      $seq_atindex323 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({0, 1, 2});
      slog::Relation* readrel344 = db->getRelation("$seq_atr");
      $seq_atrindex324 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({0, 1, 2});
      slog::Relation* readrel346 = db->getRelation("$seq_atr");
      $seq_atrindex325 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({0, 1, 2});
      slog::Relation* readrel348 = db->getRelation("$seq_atr");
      $seq_atrindex326 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({0, 1, 2});
      slog::Relation* readrel350 = db->getRelation("$seq_atr");
      $seq_atrdelta329 = readrel350->getIndex(ord349, true);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("lst_ref");
      lst_refindex327 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({0, 1});
      slog::Relation* readrel354 = db->getRelation("lst_ref_ans");
      lst_ref_ansindex328 = readrel354->getIndex(ord353, false);
  
    }
    ReadTask330(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constd4735e3a265e16eee03f5971;
      u64 v_c48 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const4a44dc15364204a80fe80e90;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c53 = v_constd4735e3a265e16eee03f5971;
      u64 v_c54 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c55 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c56 = v_constd59eced1ded07f84c145592f;
      u64 v_c57 = v_const4a44dc15364204a80fe80e90;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd59eced1ded07f84c145592f;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const4a44dc15364204a80fe80e90;
      u64 v_c66 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c67 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_constd59eced1ded07f84c145592f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c69, v_c70, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m355) {
        u64 v_c19 = m355[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex320, std::array<u64,3>{v_c57, v_c58, v_c19}, [&](const std::array<u64,3>& m356) {
          slog::join_probe<3,3>($seq_atindex321, std::array<u64,3>{v_c59, v_c60, v_c19}, [&](const std::array<u64,3>& m357) {
            slog::join_probe<3,3>($seq_atindex322, std::array<u64,3>{v_c61, v_c62, v_c19}, [&](const std::array<u64,3>& m358) {
              slog::join_probe<3,3>($seq_atindex323, std::array<u64,3>{v_c63, v_c64, v_c19}, [&](const std::array<u64,3>& m359) {
                slog::join_probe<3,3>($seq_atrindex324, std::array<u64,3>{v_c65, v_c66, v_c19}, [&](const std::array<u64,3>& m360) {
                  slog::join_probe<3,3>($seq_atrindex325, std::array<u64,3>{v_c67, v_c68, v_c19}, [&](const std::array<u64,3>& m361) {
                    slog::join_probe_old<3,3>($seq_atrindex326, $seq_atrdelta329, std::array<u64,3>{v_c71, v_c72, v_c19}, [&](const std::array<u64,3>& m362) {
                      slog::join_probe<3,2>(lst_refindex327, std::array<u64,3>{v_c19, v_c47, 0}, [&](const std::array<u64,3>& m363) {
                        u64 v_c73 = m363[2];
                        slog::join_probe<2,1>(lst_ref_ansindex328, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m364) {
                          u64 v_c21 = m364[1];
                          bool ok365 = true;
                          u64 v_c74 = _prim_aslst(db, v_c19, &ok365);
                          if (!ok365) return;
                          u64 v_c80 = _prim_llen(db, v_c74);
                          if (v_c80 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:13"); return; }
                          if (v_c48 != v_c80) return;
                          bool ok366 = true;
                          u64 v_c81 = _prim_lref(db, v_c74, v_c49, &ok366);
                          if (!ok366) return;
                          if (v_c50 != v_c81) return;
                          bool ok367 = true;
                          u64 v_c82 = _prim_lref(db, v_c74, v_c51, &ok367);
                          if (!ok367) return;
                          if (v_c52 != v_c82) return;
                          bool ok368 = true;
                          u64 v_c83 = _prim_lref(db, v_c74, v_c53, &ok368);
                          if (!ok368) return;
                          if (v_c54 != v_c83) return;
                          bool ok369 = true;
                          u64 v_c84 = _prim_lref(db, v_c74, v_c55, &ok369);
                          if (!ok369) return;
                          if (v_c56 != v_c84) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:13", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask330* _cont = new ReadTask330(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask330(db,b), false);
  // (crule (pre (let __tconst4tMq12 constd4735e3a265e16eee03f5971) (let _00024sqc7CLq75 const4b227777d4dd1fc61c6f884f) (let _00024sqc2BUf76 const5feceb66ffc86f38d952786c) (let _00024sqc9cGl77 const4a44dc15364204a80fe80e90) (let _00024sqc5J0l78 const6b86b273ff34fce19d6b804e) (let _00024sqc8mlt79 constf5ca38f748a1d6eaf726b8a4) (let _00024sqc3TWC80 constd4735e3a265e16eee03f5971) (let _00024sqc0vYG81 const624b60c58c9d8bfb6ff1886c) (let _00024sqc14Mu82 const4e07408562bedb8b60ce05c1) (let _00024sqc3HuO83 constd59eced1ded07f84c145592f) (let _00024sqo0lYp85 const4a44dc15364204a80fe80e90) (let _00024sqo9LAW84 const5feceb66ffc86f38d952786c) (let _00024sqo5UlO87 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo2Pn786 const6b86b273ff34fce19d6b804e) (let _00024sqo116y89 const624b60c58c9d8bfb6ff1886c) (let _00024sqo8IQh88 constd4735e3a265e16eee03f5971) (let _00024sqo7RbK91 constd59eced1ded07f84c145592f) (let _00024sqo36U490 const4e07408562bedb8b60ce05c1) (let _00024sqo5saO93 const4a44dc15364204a80fe80e90) (let _00024sqo1aiI92 const4e07408562bedb8b60ce05c1) (let _00024sqo1ciC95 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo7rIE94 constd4735e3a265e16eee03f5971) (let _00024sqo0SAK97 const624b60c58c9d8bfb6ff1886c) (let _00024sqo1Nma96 const6b86b273ff34fce19d6b804e) (let _00024sqo2rtj99 constd59eced1ded07f84c145592f) (let _00024sqo2fAT98 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo1ciC95 _00024sqo7rIE94 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0lYp85 _00024sqo9LAW84 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo5UlO87 _00024sqo2Pn786 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo116y89 _00024sqo8IQh88 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo7RbK91 _00024sqo36U490 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5saO93 _00024sqo1aiI92 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo0SAK97 _00024sqo1Nma96 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2rtj99 _00024sqo2fAT98 _00024seq0) (join lst_ref (1 2 0) 2 _00024seq0 __tconst4tMq12 __t0saG13) (join lst_ref_ans (0 1) 1 __t0saG13 r) (letp _00024sql3t1j73 (aslst _00024seq0)) (let chk5EMF419 (llen _00024sql3t1j73)) (eq _00024sqc7CLq75 chk5EMF419) (letp chk6fsV420 (lref _00024sql3t1j73 _00024sqc2BUf76)) (eq _00024sqc9cGl77 chk6fsV420) (letp chk7qRh421 (lref _00024sql3t1j73 _00024sqc5J0l78)) (eq _00024sqc8mlt79 chk7qRh421) (letp chk2Lw2422 (lref _00024sql3t1j73 _00024sqc3TWC80)) (eq _00024sqc0vYG81 chk2Lw2422) (letp chk59Iw423 (lref _00024sql3t1j73 _00024sqc14Mu82)) (eq _00024sqc3HuO83 chk59Iw423)) (head (emit third (0) r)) lst_ops.slog:13 #f)
  class ReadTask381 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex370;  slog::Index** $seq_atindex371;  slog::Index** $seq_atindex372;  slog::Index** $seq_atindex373;  slog::Index** $seq_atrindex374;  slog::Index** $seq_atrindex375;  slog::Index** $seq_atrindex376;  slog::Index** lst_refindex377;  slog::Index** lst_ref_ansindex378;  slog::Index** $seq_atrdelta379;  slog::Index** $seq_atrdelta380;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("third");
      std::vector<u16> ord382({0});
      slog::Relation* readrel383 = db->getRelation("third");
      head_index[0] = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({0, 1, 2});
      slog::Relation* readrel385 = db->getRelation("$seq_atr");
      driver_index = readrel385->getIndex(ord384, true);
      std::vector<u16> ord386({0, 1, 2});
      slog::Relation* readrel387 = db->getRelation("$seq_at");
      $seq_atindex370 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({0, 1, 2});
      slog::Relation* readrel389 = db->getRelation("$seq_at");
      $seq_atindex371 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({0, 1, 2});
      slog::Relation* readrel391 = db->getRelation("$seq_at");
      $seq_atindex372 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({0, 1, 2});
      slog::Relation* readrel393 = db->getRelation("$seq_at");
      $seq_atindex373 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({0, 1, 2});
      slog::Relation* readrel395 = db->getRelation("$seq_atr");
      $seq_atrindex374 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1, 2});
      slog::Relation* readrel397 = db->getRelation("$seq_atr");
      $seq_atrindex375 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({0, 1, 2});
      slog::Relation* readrel399 = db->getRelation("$seq_atr");
      $seq_atrdelta379 = readrel399->getIndex(ord398, true);
      std::vector<u16> ord400({0, 1, 2});
      slog::Relation* readrel401 = db->getRelation("$seq_atr");
      $seq_atrindex376 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({0, 1, 2});
      slog::Relation* readrel403 = db->getRelation("$seq_atr");
      $seq_atrdelta380 = readrel403->getIndex(ord402, true);
      std::vector<u16> ord404({1, 2, 0});
      slog::Relation* readrel405 = db->getRelation("lst_ref");
      lst_refindex377 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({0, 1});
      slog::Relation* readrel407 = db->getRelation("lst_ref_ans");
      lst_ref_ansindex378 = readrel407->getIndex(ord406, false);
  
    }
    ReadTask381(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constd4735e3a265e16eee03f5971;
      u64 v_c48 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const4a44dc15364204a80fe80e90;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c53 = v_constd4735e3a265e16eee03f5971;
      u64 v_c54 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c55 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c56 = v_constd59eced1ded07f84c145592f;
      u64 v_c57 = v_const4a44dc15364204a80fe80e90;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd59eced1ded07f84c145592f;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const4a44dc15364204a80fe80e90;
      u64 v_c66 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c67 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_constd59eced1ded07f84c145592f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c67, v_c68, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m408) {
        u64 v_c19 = m408[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex370, std::array<u64,3>{v_c57, v_c58, v_c19}, [&](const std::array<u64,3>& m409) {
          slog::join_probe<3,3>($seq_atindex371, std::array<u64,3>{v_c59, v_c60, v_c19}, [&](const std::array<u64,3>& m410) {
            slog::join_probe<3,3>($seq_atindex372, std::array<u64,3>{v_c61, v_c62, v_c19}, [&](const std::array<u64,3>& m411) {
              slog::join_probe<3,3>($seq_atindex373, std::array<u64,3>{v_c63, v_c64, v_c19}, [&](const std::array<u64,3>& m412) {
                slog::join_probe<3,3>($seq_atrindex374, std::array<u64,3>{v_c65, v_c66, v_c19}, [&](const std::array<u64,3>& m413) {
                  slog::join_probe_old<3,3>($seq_atrindex375, $seq_atrdelta379, std::array<u64,3>{v_c69, v_c70, v_c19}, [&](const std::array<u64,3>& m414) {
                    slog::join_probe_old<3,3>($seq_atrindex376, $seq_atrdelta380, std::array<u64,3>{v_c71, v_c72, v_c19}, [&](const std::array<u64,3>& m415) {
                      slog::join_probe<3,2>(lst_refindex377, std::array<u64,3>{v_c19, v_c47, 0}, [&](const std::array<u64,3>& m416) {
                        u64 v_c73 = m416[2];
                        slog::join_probe<2,1>(lst_ref_ansindex378, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m417) {
                          u64 v_c21 = m417[1];
                          bool ok418 = true;
                          u64 v_c74 = _prim_aslst(db, v_c19, &ok418);
                          if (!ok418) return;
                          u64 v_c85 = _prim_llen(db, v_c74);
                          if (v_c85 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:13"); return; }
                          if (v_c48 != v_c85) return;
                          bool ok419 = true;
                          u64 v_c86 = _prim_lref(db, v_c74, v_c49, &ok419);
                          if (!ok419) return;
                          if (v_c50 != v_c86) return;
                          bool ok420 = true;
                          u64 v_c87 = _prim_lref(db, v_c74, v_c51, &ok420);
                          if (!ok420) return;
                          if (v_c52 != v_c87) return;
                          bool ok421 = true;
                          u64 v_c88 = _prim_lref(db, v_c74, v_c53, &ok421);
                          if (!ok421) return;
                          if (v_c54 != v_c88) return;
                          bool ok422 = true;
                          u64 v_c89 = _prim_lref(db, v_c74, v_c55, &ok422);
                          if (!ok422) return;
                          if (v_c56 != v_c89) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:13", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask381* _cont = new ReadTask381(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask381(db,b), false);
  // (crule (pre (let __tconst4tMq12 constd4735e3a265e16eee03f5971) (let _00024sqc7CLq75 const4b227777d4dd1fc61c6f884f) (let _00024sqc2BUf76 const5feceb66ffc86f38d952786c) (let _00024sqc9cGl77 const4a44dc15364204a80fe80e90) (let _00024sqc5J0l78 const6b86b273ff34fce19d6b804e) (let _00024sqc8mlt79 constf5ca38f748a1d6eaf726b8a4) (let _00024sqc3TWC80 constd4735e3a265e16eee03f5971) (let _00024sqc0vYG81 const624b60c58c9d8bfb6ff1886c) (let _00024sqc14Mu82 const4e07408562bedb8b60ce05c1) (let _00024sqc3HuO83 constd59eced1ded07f84c145592f) (let _00024sqo0lYp85 const4a44dc15364204a80fe80e90) (let _00024sqo9LAW84 const5feceb66ffc86f38d952786c) (let _00024sqo5UlO87 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo2Pn786 const6b86b273ff34fce19d6b804e) (let _00024sqo116y89 const624b60c58c9d8bfb6ff1886c) (let _00024sqo8IQh88 constd4735e3a265e16eee03f5971) (let _00024sqo7RbK91 constd59eced1ded07f84c145592f) (let _00024sqo36U490 const4e07408562bedb8b60ce05c1) (let _00024sqo5saO93 const4a44dc15364204a80fe80e90) (let _00024sqo1aiI92 const4e07408562bedb8b60ce05c1) (let _00024sqo1ciC95 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo7rIE94 constd4735e3a265e16eee03f5971) (let _00024sqo0SAK97 const624b60c58c9d8bfb6ff1886c) (let _00024sqo1Nma96 const6b86b273ff34fce19d6b804e) (let _00024sqo2rtj99 constd59eced1ded07f84c145592f) (let _00024sqo2fAT98 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo5saO93 _00024sqo1aiI92 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0lYp85 _00024sqo9LAW84 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo5UlO87 _00024sqo2Pn786 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo116y89 _00024sqo8IQh88 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo7RbK91 _00024sqo36U490 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1ciC95 _00024sqo7rIE94 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo0SAK97 _00024sqo1Nma96 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2rtj99 _00024sqo2fAT98 _00024seq0) (join lst_ref (1 2 0) 2 _00024seq0 __tconst4tMq12 __t0saG13) (join lst_ref_ans (0 1) 1 __t0saG13 r) (letp _00024sql3t1j73 (aslst _00024seq0)) (let chk3x24414 (llen _00024sql3t1j73)) (eq _00024sqc7CLq75 chk3x24414) (letp chk6nVW415 (lref _00024sql3t1j73 _00024sqc2BUf76)) (eq _00024sqc9cGl77 chk6nVW415) (letp chk7ORi416 (lref _00024sql3t1j73 _00024sqc5J0l78)) (eq _00024sqc8mlt79 chk7ORi416) (letp chk69ra417 (lref _00024sql3t1j73 _00024sqc3TWC80)) (eq _00024sqc0vYG81 chk69ra417) (letp chk5cFM418 (lref _00024sql3t1j73 _00024sqc14Mu82)) (eq _00024sqc3HuO83 chk5cFM418)) (head (emit third (0) r)) lst_ops.slog:13 #f)
  class ReadTask435 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex423;  slog::Index** $seq_atindex424;  slog::Index** $seq_atindex425;  slog::Index** $seq_atindex426;  slog::Index** $seq_atrindex427;  slog::Index** $seq_atrindex428;  slog::Index** $seq_atrindex429;  slog::Index** lst_refindex430;  slog::Index** lst_ref_ansindex431;  slog::Index** $seq_atrdelta432;  slog::Index** $seq_atrdelta433;  slog::Index** $seq_atrdelta434;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("third");
      std::vector<u16> ord436({0});
      slog::Relation* readrel437 = db->getRelation("third");
      head_index[0] = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({0, 1, 2});
      slog::Relation* readrel439 = db->getRelation("$seq_atr");
      driver_index = readrel439->getIndex(ord438, true);
      std::vector<u16> ord440({0, 1, 2});
      slog::Relation* readrel441 = db->getRelation("$seq_at");
      $seq_atindex423 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({0, 1, 2});
      slog::Relation* readrel443 = db->getRelation("$seq_at");
      $seq_atindex424 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({0, 1, 2});
      slog::Relation* readrel445 = db->getRelation("$seq_at");
      $seq_atindex425 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({0, 1, 2});
      slog::Relation* readrel447 = db->getRelation("$seq_at");
      $seq_atindex426 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({0, 1, 2});
      slog::Relation* readrel449 = db->getRelation("$seq_atr");
      $seq_atrindex427 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({0, 1, 2});
      slog::Relation* readrel451 = db->getRelation("$seq_atr");
      $seq_atrdelta432 = readrel451->getIndex(ord450, true);
      std::vector<u16> ord452({0, 1, 2});
      slog::Relation* readrel453 = db->getRelation("$seq_atr");
      $seq_atrindex428 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({0, 1, 2});
      slog::Relation* readrel455 = db->getRelation("$seq_atr");
      $seq_atrdelta433 = readrel455->getIndex(ord454, true);
      std::vector<u16> ord456({0, 1, 2});
      slog::Relation* readrel457 = db->getRelation("$seq_atr");
      $seq_atrindex429 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 1, 2});
      slog::Relation* readrel459 = db->getRelation("$seq_atr");
      $seq_atrdelta434 = readrel459->getIndex(ord458, true);
      std::vector<u16> ord460({1, 2, 0});
      slog::Relation* readrel461 = db->getRelation("lst_ref");
      lst_refindex430 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({0, 1});
      slog::Relation* readrel463 = db->getRelation("lst_ref_ans");
      lst_ref_ansindex431 = readrel463->getIndex(ord462, false);
  
    }
    ReadTask435(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constd4735e3a265e16eee03f5971;
      u64 v_c48 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const4a44dc15364204a80fe80e90;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c53 = v_constd4735e3a265e16eee03f5971;
      u64 v_c54 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c55 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c56 = v_constd59eced1ded07f84c145592f;
      u64 v_c57 = v_const4a44dc15364204a80fe80e90;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd59eced1ded07f84c145592f;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const4a44dc15364204a80fe80e90;
      u64 v_c66 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c67 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_constd59eced1ded07f84c145592f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c65, v_c66, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m464) {
        u64 v_c19 = m464[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex423, std::array<u64,3>{v_c57, v_c58, v_c19}, [&](const std::array<u64,3>& m465) {
          slog::join_probe<3,3>($seq_atindex424, std::array<u64,3>{v_c59, v_c60, v_c19}, [&](const std::array<u64,3>& m466) {
            slog::join_probe<3,3>($seq_atindex425, std::array<u64,3>{v_c61, v_c62, v_c19}, [&](const std::array<u64,3>& m467) {
              slog::join_probe<3,3>($seq_atindex426, std::array<u64,3>{v_c63, v_c64, v_c19}, [&](const std::array<u64,3>& m468) {
                slog::join_probe_old<3,3>($seq_atrindex427, $seq_atrdelta432, std::array<u64,3>{v_c67, v_c68, v_c19}, [&](const std::array<u64,3>& m469) {
                  slog::join_probe_old<3,3>($seq_atrindex428, $seq_atrdelta433, std::array<u64,3>{v_c69, v_c70, v_c19}, [&](const std::array<u64,3>& m470) {
                    slog::join_probe_old<3,3>($seq_atrindex429, $seq_atrdelta434, std::array<u64,3>{v_c71, v_c72, v_c19}, [&](const std::array<u64,3>& m471) {
                      slog::join_probe<3,2>(lst_refindex430, std::array<u64,3>{v_c19, v_c47, 0}, [&](const std::array<u64,3>& m472) {
                        u64 v_c73 = m472[2];
                        slog::join_probe<2,1>(lst_ref_ansindex431, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m473) {
                          u64 v_c21 = m473[1];
                          bool ok474 = true;
                          u64 v_c74 = _prim_aslst(db, v_c19, &ok474);
                          if (!ok474) return;
                          u64 v_c90 = _prim_llen(db, v_c74);
                          if (v_c90 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:13"); return; }
                          if (v_c48 != v_c90) return;
                          bool ok475 = true;
                          u64 v_c91 = _prim_lref(db, v_c74, v_c49, &ok475);
                          if (!ok475) return;
                          if (v_c50 != v_c91) return;
                          bool ok476 = true;
                          u64 v_c92 = _prim_lref(db, v_c74, v_c51, &ok476);
                          if (!ok476) return;
                          if (v_c52 != v_c92) return;
                          bool ok477 = true;
                          u64 v_c93 = _prim_lref(db, v_c74, v_c53, &ok477);
                          if (!ok477) return;
                          if (v_c54 != v_c93) return;
                          bool ok478 = true;
                          u64 v_c94 = _prim_lref(db, v_c74, v_c55, &ok478);
                          if (!ok478) return;
                          if (v_c56 != v_c94) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:13", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask435* _cont = new ReadTask435(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask435(db,b), false);
  // (crule (pre (let __tconst4tMq12 constd4735e3a265e16eee03f5971) (let _00024sqc7CLq75 const4b227777d4dd1fc61c6f884f) (let _00024sqc2BUf76 const5feceb66ffc86f38d952786c) (let _00024sqc9cGl77 const4a44dc15364204a80fe80e90) (let _00024sqc5J0l78 const6b86b273ff34fce19d6b804e) (let _00024sqc8mlt79 constf5ca38f748a1d6eaf726b8a4) (let _00024sqc3TWC80 constd4735e3a265e16eee03f5971) (let _00024sqc0vYG81 const624b60c58c9d8bfb6ff1886c) (let _00024sqc14Mu82 const4e07408562bedb8b60ce05c1) (let _00024sqc3HuO83 constd59eced1ded07f84c145592f) (let _00024sqo0lYp85 const4a44dc15364204a80fe80e90) (let _00024sqo9LAW84 const5feceb66ffc86f38d952786c) (let _00024sqo5UlO87 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo2Pn786 const6b86b273ff34fce19d6b804e) (let _00024sqo116y89 const624b60c58c9d8bfb6ff1886c) (let _00024sqo8IQh88 constd4735e3a265e16eee03f5971) (let _00024sqo7RbK91 constd59eced1ded07f84c145592f) (let _00024sqo36U490 const4e07408562bedb8b60ce05c1) (let _00024sqo5saO93 const4a44dc15364204a80fe80e90) (let _00024sqo1aiI92 const4e07408562bedb8b60ce05c1) (let _00024sqo1ciC95 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo7rIE94 constd4735e3a265e16eee03f5971) (let _00024sqo0SAK97 const624b60c58c9d8bfb6ff1886c) (let _00024sqo1Nma96 const6b86b273ff34fce19d6b804e) (let _00024sqo2rtj99 constd59eced1ded07f84c145592f) (let _00024sqo2fAT98 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo7RbK91 _00024sqo36U490 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0lYp85 _00024sqo9LAW84 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo5UlO87 _00024sqo2Pn786 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo116y89 _00024sqo8IQh88 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5saO93 _00024sqo1aiI92 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1ciC95 _00024sqo7rIE94 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo0SAK97 _00024sqo1Nma96 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2rtj99 _00024sqo2fAT98 _00024seq0) (join lst_ref (1 2 0) 2 _00024seq0 __tconst4tMq12 __t0saG13) (join lst_ref_ans (0 1) 1 __t0saG13 r) (letp _00024sql3t1j73 (aslst _00024seq0)) (let chk1vpR409 (llen _00024sql3t1j73)) (eq _00024sqc7CLq75 chk1vpR409) (letp chk6Wwz410 (lref _00024sql3t1j73 _00024sqc2BUf76)) (eq _00024sqc9cGl77 chk6Wwz410) (letp chk7TgL411 (lref _00024sql3t1j73 _00024sqc5J0l78)) (eq _00024sqc8mlt79 chk7TgL411) (letp chk4SAO412 (lref _00024sql3t1j73 _00024sqc3TWC80)) (eq _00024sqc0vYG81 chk4SAO412) (letp chk72No413 (lref _00024sql3t1j73 _00024sqc14Mu82)) (eq _00024sqc3HuO83 chk72No413)) (head (emit third (0) r)) lst_ops.slog:13 #f)
  class ReadTask492 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex479;  slog::Index** $seq_atindex480;  slog::Index** $seq_atindex481;  slog::Index** $seq_atrindex482;  slog::Index** $seq_atrindex483;  slog::Index** $seq_atrindex484;  slog::Index** $seq_atrindex485;  slog::Index** lst_refindex486;  slog::Index** lst_ref_ansindex487;  slog::Index** $seq_atrdelta488;  slog::Index** $seq_atrdelta489;  slog::Index** $seq_atrdelta490;  slog::Index** $seq_atrdelta491;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("third");
      std::vector<u16> ord493({0});
      slog::Relation* readrel494 = db->getRelation("third");
      head_index[0] = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({0, 1, 2});
      slog::Relation* readrel496 = db->getRelation("$seq_at");
      driver_index = readrel496->getIndex(ord495, true);
      std::vector<u16> ord497({0, 1, 2});
      slog::Relation* readrel498 = db->getRelation("$seq_at");
      $seq_atindex479 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0, 1, 2});
      slog::Relation* readrel500 = db->getRelation("$seq_at");
      $seq_atindex480 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({0, 1, 2});
      slog::Relation* readrel502 = db->getRelation("$seq_at");
      $seq_atindex481 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({0, 1, 2});
      slog::Relation* readrel504 = db->getRelation("$seq_atr");
      $seq_atrindex482 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({0, 1, 2});
      slog::Relation* readrel506 = db->getRelation("$seq_atr");
      $seq_atrdelta488 = readrel506->getIndex(ord505, true);
      std::vector<u16> ord507({0, 1, 2});
      slog::Relation* readrel508 = db->getRelation("$seq_atr");
      $seq_atrindex483 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({0, 1, 2});
      slog::Relation* readrel510 = db->getRelation("$seq_atr");
      $seq_atrdelta489 = readrel510->getIndex(ord509, true);
      std::vector<u16> ord511({0, 1, 2});
      slog::Relation* readrel512 = db->getRelation("$seq_atr");
      $seq_atrindex484 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({0, 1, 2});
      slog::Relation* readrel514 = db->getRelation("$seq_atr");
      $seq_atrdelta490 = readrel514->getIndex(ord513, true);
      std::vector<u16> ord515({0, 1, 2});
      slog::Relation* readrel516 = db->getRelation("$seq_atr");
      $seq_atrindex485 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({0, 1, 2});
      slog::Relation* readrel518 = db->getRelation("$seq_atr");
      $seq_atrdelta491 = readrel518->getIndex(ord517, true);
      std::vector<u16> ord519({1, 2, 0});
      slog::Relation* readrel520 = db->getRelation("lst_ref");
      lst_refindex486 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({0, 1});
      slog::Relation* readrel522 = db->getRelation("lst_ref_ans");
      lst_ref_ansindex487 = readrel522->getIndex(ord521, false);
  
    }
    ReadTask492(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constd4735e3a265e16eee03f5971;
      u64 v_c48 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const4a44dc15364204a80fe80e90;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c53 = v_constd4735e3a265e16eee03f5971;
      u64 v_c54 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c55 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c56 = v_constd59eced1ded07f84c145592f;
      u64 v_c57 = v_const4a44dc15364204a80fe80e90;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd59eced1ded07f84c145592f;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const4a44dc15364204a80fe80e90;
      u64 v_c66 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c67 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_constd59eced1ded07f84c145592f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c63, v_c64, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m523) {
        u64 v_c19 = m523[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex479, std::array<u64,3>{v_c57, v_c58, v_c19}, [&](const std::array<u64,3>& m524) {
          slog::join_probe<3,3>($seq_atindex480, std::array<u64,3>{v_c59, v_c60, v_c19}, [&](const std::array<u64,3>& m525) {
            slog::join_probe<3,3>($seq_atindex481, std::array<u64,3>{v_c61, v_c62, v_c19}, [&](const std::array<u64,3>& m526) {
              slog::join_probe_old<3,3>($seq_atrindex482, $seq_atrdelta488, std::array<u64,3>{v_c65, v_c66, v_c19}, [&](const std::array<u64,3>& m527) {
                slog::join_probe_old<3,3>($seq_atrindex483, $seq_atrdelta489, std::array<u64,3>{v_c67, v_c68, v_c19}, [&](const std::array<u64,3>& m528) {
                  slog::join_probe_old<3,3>($seq_atrindex484, $seq_atrdelta490, std::array<u64,3>{v_c69, v_c70, v_c19}, [&](const std::array<u64,3>& m529) {
                    slog::join_probe_old<3,3>($seq_atrindex485, $seq_atrdelta491, std::array<u64,3>{v_c71, v_c72, v_c19}, [&](const std::array<u64,3>& m530) {
                      slog::join_probe<3,2>(lst_refindex486, std::array<u64,3>{v_c19, v_c47, 0}, [&](const std::array<u64,3>& m531) {
                        u64 v_c73 = m531[2];
                        slog::join_probe<2,1>(lst_ref_ansindex487, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m532) {
                          u64 v_c21 = m532[1];
                          bool ok533 = true;
                          u64 v_c74 = _prim_aslst(db, v_c19, &ok533);
                          if (!ok533) return;
                          u64 v_c95 = _prim_llen(db, v_c74);
                          if (v_c95 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:13"); return; }
                          if (v_c48 != v_c95) return;
                          bool ok534 = true;
                          u64 v_c96 = _prim_lref(db, v_c74, v_c49, &ok534);
                          if (!ok534) return;
                          if (v_c50 != v_c96) return;
                          bool ok535 = true;
                          u64 v_c97 = _prim_lref(db, v_c74, v_c51, &ok535);
                          if (!ok535) return;
                          if (v_c52 != v_c97) return;
                          bool ok536 = true;
                          u64 v_c98 = _prim_lref(db, v_c74, v_c53, &ok536);
                          if (!ok536) return;
                          if (v_c54 != v_c98) return;
                          bool ok537 = true;
                          u64 v_c99 = _prim_lref(db, v_c74, v_c55, &ok537);
                          if (!ok537) return;
                          if (v_c56 != v_c99) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:13", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask492* _cont = new ReadTask492(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask492(db,b), false);
  // (crule (pre (let __tconst4tMq12 constd4735e3a265e16eee03f5971) (let _00024sqc7CLq75 const4b227777d4dd1fc61c6f884f) (let _00024sqc2BUf76 const5feceb66ffc86f38d952786c) (let _00024sqc9cGl77 const4a44dc15364204a80fe80e90) (let _00024sqc5J0l78 const6b86b273ff34fce19d6b804e) (let _00024sqc8mlt79 constf5ca38f748a1d6eaf726b8a4) (let _00024sqc3TWC80 constd4735e3a265e16eee03f5971) (let _00024sqc0vYG81 const624b60c58c9d8bfb6ff1886c) (let _00024sqc14Mu82 const4e07408562bedb8b60ce05c1) (let _00024sqc3HuO83 constd59eced1ded07f84c145592f) (let _00024sqo0lYp85 const4a44dc15364204a80fe80e90) (let _00024sqo9LAW84 const5feceb66ffc86f38d952786c) (let _00024sqo5UlO87 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo2Pn786 const6b86b273ff34fce19d6b804e) (let _00024sqo116y89 const624b60c58c9d8bfb6ff1886c) (let _00024sqo8IQh88 constd4735e3a265e16eee03f5971) (let _00024sqo7RbK91 constd59eced1ded07f84c145592f) (let _00024sqo36U490 const4e07408562bedb8b60ce05c1) (let _00024sqo5saO93 const4a44dc15364204a80fe80e90) (let _00024sqo1aiI92 const4e07408562bedb8b60ce05c1) (let _00024sqo1ciC95 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo7rIE94 constd4735e3a265e16eee03f5971) (let _00024sqo0SAK97 const624b60c58c9d8bfb6ff1886c) (let _00024sqo1Nma96 const6b86b273ff34fce19d6b804e) (let _00024sqo2rtj99 constd59eced1ded07f84c145592f) (let _00024sqo2fAT98 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo116y89 _00024sqo8IQh88 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0lYp85 _00024sqo9LAW84 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo5UlO87 _00024sqo2Pn786 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo7RbK91 _00024sqo36U490 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5saO93 _00024sqo1aiI92 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1ciC95 _00024sqo7rIE94 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo0SAK97 _00024sqo1Nma96 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2rtj99 _00024sqo2fAT98 _00024seq0) (join lst_ref (1 2 0) 2 _00024seq0 __tconst4tMq12 __t0saG13) (join lst_ref_ans (0 1) 1 __t0saG13 r) (letp _00024sql3t1j73 (aslst _00024seq0)) (let chk3IIX404 (llen _00024sql3t1j73)) (eq _00024sqc7CLq75 chk3IIX404) (letp chk5fGv405 (lref _00024sql3t1j73 _00024sqc2BUf76)) (eq _00024sqc9cGl77 chk5fGv405) (letp chk5zoW406 (lref _00024sql3t1j73 _00024sqc5J0l78)) (eq _00024sqc8mlt79 chk5zoW406) (letp chk7prV407 (lref _00024sql3t1j73 _00024sqc3TWC80)) (eq _00024sqc0vYG81 chk7prV407) (letp chk2FT3408 (lref _00024sql3t1j73 _00024sqc14Mu82)) (eq _00024sqc3HuO83 chk2FT3408)) (head (emit third (0) r)) lst_ops.slog:13 #f)
  class ReadTask552 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex538;  slog::Index** $seq_atindex539;  slog::Index** $seq_atindex540;  slog::Index** $seq_atrindex541;  slog::Index** $seq_atrindex542;  slog::Index** $seq_atrindex543;  slog::Index** $seq_atrindex544;  slog::Index** lst_refindex545;  slog::Index** lst_ref_ansindex546;  slog::Index** $seq_atdelta547;  slog::Index** $seq_atrdelta548;  slog::Index** $seq_atrdelta549;  slog::Index** $seq_atrdelta550;  slog::Index** $seq_atrdelta551;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("third");
      std::vector<u16> ord553({0});
      slog::Relation* readrel554 = db->getRelation("third");
      head_index[0] = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({0, 1, 2});
      slog::Relation* readrel556 = db->getRelation("$seq_at");
      driver_index = readrel556->getIndex(ord555, true);
      std::vector<u16> ord557({0, 1, 2});
      slog::Relation* readrel558 = db->getRelation("$seq_at");
      $seq_atindex538 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({0, 1, 2});
      slog::Relation* readrel560 = db->getRelation("$seq_at");
      $seq_atindex539 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({0, 1, 2});
      slog::Relation* readrel562 = db->getRelation("$seq_at");
      $seq_atindex540 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({0, 1, 2});
      slog::Relation* readrel564 = db->getRelation("$seq_at");
      $seq_atdelta547 = readrel564->getIndex(ord563, true);
      std::vector<u16> ord565({0, 1, 2});
      slog::Relation* readrel566 = db->getRelation("$seq_atr");
      $seq_atrindex541 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({0, 1, 2});
      slog::Relation* readrel568 = db->getRelation("$seq_atr");
      $seq_atrdelta548 = readrel568->getIndex(ord567, true);
      std::vector<u16> ord569({0, 1, 2});
      slog::Relation* readrel570 = db->getRelation("$seq_atr");
      $seq_atrindex542 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({0, 1, 2});
      slog::Relation* readrel572 = db->getRelation("$seq_atr");
      $seq_atrdelta549 = readrel572->getIndex(ord571, true);
      std::vector<u16> ord573({0, 1, 2});
      slog::Relation* readrel574 = db->getRelation("$seq_atr");
      $seq_atrindex543 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({0, 1, 2});
      slog::Relation* readrel576 = db->getRelation("$seq_atr");
      $seq_atrdelta550 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({0, 1, 2});
      slog::Relation* readrel578 = db->getRelation("$seq_atr");
      $seq_atrindex544 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({0, 1, 2});
      slog::Relation* readrel580 = db->getRelation("$seq_atr");
      $seq_atrdelta551 = readrel580->getIndex(ord579, true);
      std::vector<u16> ord581({1, 2, 0});
      slog::Relation* readrel582 = db->getRelation("lst_ref");
      lst_refindex545 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({0, 1});
      slog::Relation* readrel584 = db->getRelation("lst_ref_ans");
      lst_ref_ansindex546 = readrel584->getIndex(ord583, false);
  
    }
    ReadTask552(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constd4735e3a265e16eee03f5971;
      u64 v_c48 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const4a44dc15364204a80fe80e90;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c53 = v_constd4735e3a265e16eee03f5971;
      u64 v_c54 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c55 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c56 = v_constd59eced1ded07f84c145592f;
      u64 v_c57 = v_const4a44dc15364204a80fe80e90;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd59eced1ded07f84c145592f;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const4a44dc15364204a80fe80e90;
      u64 v_c66 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c67 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_constd59eced1ded07f84c145592f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c61, v_c62, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m585) {
        u64 v_c19 = m585[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex538, std::array<u64,3>{v_c57, v_c58, v_c19}, [&](const std::array<u64,3>& m586) {
          slog::join_probe<3,3>($seq_atindex539, std::array<u64,3>{v_c59, v_c60, v_c19}, [&](const std::array<u64,3>& m587) {
            slog::join_probe_old<3,3>($seq_atindex540, $seq_atdelta547, std::array<u64,3>{v_c63, v_c64, v_c19}, [&](const std::array<u64,3>& m588) {
              slog::join_probe_old<3,3>($seq_atrindex541, $seq_atrdelta548, std::array<u64,3>{v_c65, v_c66, v_c19}, [&](const std::array<u64,3>& m589) {
                slog::join_probe_old<3,3>($seq_atrindex542, $seq_atrdelta549, std::array<u64,3>{v_c67, v_c68, v_c19}, [&](const std::array<u64,3>& m590) {
                  slog::join_probe_old<3,3>($seq_atrindex543, $seq_atrdelta550, std::array<u64,3>{v_c69, v_c70, v_c19}, [&](const std::array<u64,3>& m591) {
                    slog::join_probe_old<3,3>($seq_atrindex544, $seq_atrdelta551, std::array<u64,3>{v_c71, v_c72, v_c19}, [&](const std::array<u64,3>& m592) {
                      slog::join_probe<3,2>(lst_refindex545, std::array<u64,3>{v_c19, v_c47, 0}, [&](const std::array<u64,3>& m593) {
                        u64 v_c73 = m593[2];
                        slog::join_probe<2,1>(lst_ref_ansindex546, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m594) {
                          u64 v_c21 = m594[1];
                          bool ok595 = true;
                          u64 v_c74 = _prim_aslst(db, v_c19, &ok595);
                          if (!ok595) return;
                          u64 v_c100 = _prim_llen(db, v_c74);
                          if (v_c100 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:13"); return; }
                          if (v_c48 != v_c100) return;
                          bool ok596 = true;
                          u64 v_c101 = _prim_lref(db, v_c74, v_c49, &ok596);
                          if (!ok596) return;
                          if (v_c50 != v_c101) return;
                          bool ok597 = true;
                          u64 v_c102 = _prim_lref(db, v_c74, v_c51, &ok597);
                          if (!ok597) return;
                          if (v_c52 != v_c102) return;
                          bool ok598 = true;
                          u64 v_c103 = _prim_lref(db, v_c74, v_c53, &ok598);
                          if (!ok598) return;
                          if (v_c54 != v_c103) return;
                          bool ok599 = true;
                          u64 v_c104 = _prim_lref(db, v_c74, v_c55, &ok599);
                          if (!ok599) return;
                          if (v_c56 != v_c104) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:13", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask552* _cont = new ReadTask552(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask552(db,b), false);
  // (crule (pre (let __tconst4tMq12 constd4735e3a265e16eee03f5971) (let _00024sqc7CLq75 const4b227777d4dd1fc61c6f884f) (let _00024sqc2BUf76 const5feceb66ffc86f38d952786c) (let _00024sqc9cGl77 const4a44dc15364204a80fe80e90) (let _00024sqc5J0l78 const6b86b273ff34fce19d6b804e) (let _00024sqc8mlt79 constf5ca38f748a1d6eaf726b8a4) (let _00024sqc3TWC80 constd4735e3a265e16eee03f5971) (let _00024sqc0vYG81 const624b60c58c9d8bfb6ff1886c) (let _00024sqc14Mu82 const4e07408562bedb8b60ce05c1) (let _00024sqc3HuO83 constd59eced1ded07f84c145592f) (let _00024sqo0lYp85 const4a44dc15364204a80fe80e90) (let _00024sqo9LAW84 const5feceb66ffc86f38d952786c) (let _00024sqo5UlO87 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo2Pn786 const6b86b273ff34fce19d6b804e) (let _00024sqo116y89 const624b60c58c9d8bfb6ff1886c) (let _00024sqo8IQh88 constd4735e3a265e16eee03f5971) (let _00024sqo7RbK91 constd59eced1ded07f84c145592f) (let _00024sqo36U490 const4e07408562bedb8b60ce05c1) (let _00024sqo5saO93 const4a44dc15364204a80fe80e90) (let _00024sqo1aiI92 const4e07408562bedb8b60ce05c1) (let _00024sqo1ciC95 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo7rIE94 constd4735e3a265e16eee03f5971) (let _00024sqo0SAK97 const624b60c58c9d8bfb6ff1886c) (let _00024sqo1Nma96 const6b86b273ff34fce19d6b804e) (let _00024sqo2rtj99 constd59eced1ded07f84c145592f) (let _00024sqo2fAT98 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo5UlO87 _00024sqo2Pn786 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0lYp85 _00024sqo9LAW84 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo116y89 _00024sqo8IQh88 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo7RbK91 _00024sqo36U490 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5saO93 _00024sqo1aiI92 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1ciC95 _00024sqo7rIE94 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo0SAK97 _00024sqo1Nma96 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2rtj99 _00024sqo2fAT98 _00024seq0) (join lst_ref (1 2 0) 2 _00024seq0 __tconst4tMq12 __t0saG13) (join lst_ref_ans (0 1) 1 __t0saG13 r) (letp _00024sql3t1j73 (aslst _00024seq0)) (let chk86Up399 (llen _00024sql3t1j73)) (eq _00024sqc7CLq75 chk86Up399) (letp chk0suf400 (lref _00024sql3t1j73 _00024sqc2BUf76)) (eq _00024sqc9cGl77 chk0suf400) (letp chk35fU401 (lref _00024sql3t1j73 _00024sqc5J0l78)) (eq _00024sqc8mlt79 chk35fU401) (letp chk2X4Q402 (lref _00024sql3t1j73 _00024sqc3TWC80)) (eq _00024sqc0vYG81 chk2X4Q402) (letp chk8Mg8403 (lref _00024sql3t1j73 _00024sqc14Mu82)) (eq _00024sqc3HuO83 chk8Mg8403)) (head (emit third (0) r)) lst_ops.slog:13 #f)
  class ReadTask615 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex600;  slog::Index** $seq_atindex601;  slog::Index** $seq_atindex602;  slog::Index** $seq_atrindex603;  slog::Index** $seq_atrindex604;  slog::Index** $seq_atrindex605;  slog::Index** $seq_atrindex606;  slog::Index** lst_refindex607;  slog::Index** lst_ref_ansindex608;  slog::Index** $seq_atdelta609;  slog::Index** $seq_atdelta610;  slog::Index** $seq_atrdelta611;  slog::Index** $seq_atrdelta612;  slog::Index** $seq_atrdelta613;  slog::Index** $seq_atrdelta614;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("third");
      std::vector<u16> ord616({0});
      slog::Relation* readrel617 = db->getRelation("third");
      head_index[0] = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({0, 1, 2});
      slog::Relation* readrel619 = db->getRelation("$seq_at");
      driver_index = readrel619->getIndex(ord618, true);
      std::vector<u16> ord620({0, 1, 2});
      slog::Relation* readrel621 = db->getRelation("$seq_at");
      $seq_atindex600 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({0, 1, 2});
      slog::Relation* readrel623 = db->getRelation("$seq_at");
      $seq_atindex601 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({0, 1, 2});
      slog::Relation* readrel625 = db->getRelation("$seq_at");
      $seq_atdelta609 = readrel625->getIndex(ord624, true);
      std::vector<u16> ord626({0, 1, 2});
      slog::Relation* readrel627 = db->getRelation("$seq_at");
      $seq_atindex602 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({0, 1, 2});
      slog::Relation* readrel629 = db->getRelation("$seq_at");
      $seq_atdelta610 = readrel629->getIndex(ord628, true);
      std::vector<u16> ord630({0, 1, 2});
      slog::Relation* readrel631 = db->getRelation("$seq_atr");
      $seq_atrindex603 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({0, 1, 2});
      slog::Relation* readrel633 = db->getRelation("$seq_atr");
      $seq_atrdelta611 = readrel633->getIndex(ord632, true);
      std::vector<u16> ord634({0, 1, 2});
      slog::Relation* readrel635 = db->getRelation("$seq_atr");
      $seq_atrindex604 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({0, 1, 2});
      slog::Relation* readrel637 = db->getRelation("$seq_atr");
      $seq_atrdelta612 = readrel637->getIndex(ord636, true);
      std::vector<u16> ord638({0, 1, 2});
      slog::Relation* readrel639 = db->getRelation("$seq_atr");
      $seq_atrindex605 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({0, 1, 2});
      slog::Relation* readrel641 = db->getRelation("$seq_atr");
      $seq_atrdelta613 = readrel641->getIndex(ord640, true);
      std::vector<u16> ord642({0, 1, 2});
      slog::Relation* readrel643 = db->getRelation("$seq_atr");
      $seq_atrindex606 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({0, 1, 2});
      slog::Relation* readrel645 = db->getRelation("$seq_atr");
      $seq_atrdelta614 = readrel645->getIndex(ord644, true);
      std::vector<u16> ord646({1, 2, 0});
      slog::Relation* readrel647 = db->getRelation("lst_ref");
      lst_refindex607 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({0, 1});
      slog::Relation* readrel649 = db->getRelation("lst_ref_ans");
      lst_ref_ansindex608 = readrel649->getIndex(ord648, false);
  
    }
    ReadTask615(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constd4735e3a265e16eee03f5971;
      u64 v_c48 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const4a44dc15364204a80fe80e90;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c53 = v_constd4735e3a265e16eee03f5971;
      u64 v_c54 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c55 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c56 = v_constd59eced1ded07f84c145592f;
      u64 v_c57 = v_const4a44dc15364204a80fe80e90;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd59eced1ded07f84c145592f;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const4a44dc15364204a80fe80e90;
      u64 v_c66 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c67 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_constd59eced1ded07f84c145592f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c59, v_c60, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m650) {
        u64 v_c19 = m650[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex600, std::array<u64,3>{v_c57, v_c58, v_c19}, [&](const std::array<u64,3>& m651) {
          slog::join_probe_old<3,3>($seq_atindex601, $seq_atdelta609, std::array<u64,3>{v_c61, v_c62, v_c19}, [&](const std::array<u64,3>& m652) {
            slog::join_probe_old<3,3>($seq_atindex602, $seq_atdelta610, std::array<u64,3>{v_c63, v_c64, v_c19}, [&](const std::array<u64,3>& m653) {
              slog::join_probe_old<3,3>($seq_atrindex603, $seq_atrdelta611, std::array<u64,3>{v_c65, v_c66, v_c19}, [&](const std::array<u64,3>& m654) {
                slog::join_probe_old<3,3>($seq_atrindex604, $seq_atrdelta612, std::array<u64,3>{v_c67, v_c68, v_c19}, [&](const std::array<u64,3>& m655) {
                  slog::join_probe_old<3,3>($seq_atrindex605, $seq_atrdelta613, std::array<u64,3>{v_c69, v_c70, v_c19}, [&](const std::array<u64,3>& m656) {
                    slog::join_probe_old<3,3>($seq_atrindex606, $seq_atrdelta614, std::array<u64,3>{v_c71, v_c72, v_c19}, [&](const std::array<u64,3>& m657) {
                      slog::join_probe<3,2>(lst_refindex607, std::array<u64,3>{v_c19, v_c47, 0}, [&](const std::array<u64,3>& m658) {
                        u64 v_c73 = m658[2];
                        slog::join_probe<2,1>(lst_ref_ansindex608, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m659) {
                          u64 v_c21 = m659[1];
                          bool ok660 = true;
                          u64 v_c74 = _prim_aslst(db, v_c19, &ok660);
                          if (!ok660) return;
                          u64 v_c105 = _prim_llen(db, v_c74);
                          if (v_c105 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:13"); return; }
                          if (v_c48 != v_c105) return;
                          bool ok661 = true;
                          u64 v_c106 = _prim_lref(db, v_c74, v_c49, &ok661);
                          if (!ok661) return;
                          if (v_c50 != v_c106) return;
                          bool ok662 = true;
                          u64 v_c107 = _prim_lref(db, v_c74, v_c51, &ok662);
                          if (!ok662) return;
                          if (v_c52 != v_c107) return;
                          bool ok663 = true;
                          u64 v_c108 = _prim_lref(db, v_c74, v_c53, &ok663);
                          if (!ok663) return;
                          if (v_c54 != v_c108) return;
                          bool ok664 = true;
                          u64 v_c109 = _prim_lref(db, v_c74, v_c55, &ok664);
                          if (!ok664) return;
                          if (v_c56 != v_c109) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:13", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask615* _cont = new ReadTask615(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask615(db,b), false);
  // (crule (pre (let __tconst4tMq12 constd4735e3a265e16eee03f5971) (let _00024sqc7CLq75 const4b227777d4dd1fc61c6f884f) (let _00024sqc2BUf76 const5feceb66ffc86f38d952786c) (let _00024sqc9cGl77 const4a44dc15364204a80fe80e90) (let _00024sqc5J0l78 const6b86b273ff34fce19d6b804e) (let _00024sqc8mlt79 constf5ca38f748a1d6eaf726b8a4) (let _00024sqc3TWC80 constd4735e3a265e16eee03f5971) (let _00024sqc0vYG81 const624b60c58c9d8bfb6ff1886c) (let _00024sqc14Mu82 const4e07408562bedb8b60ce05c1) (let _00024sqc3HuO83 constd59eced1ded07f84c145592f) (let _00024sqo0lYp85 const4a44dc15364204a80fe80e90) (let _00024sqo9LAW84 const5feceb66ffc86f38d952786c) (let _00024sqo5UlO87 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo2Pn786 const6b86b273ff34fce19d6b804e) (let _00024sqo116y89 const624b60c58c9d8bfb6ff1886c) (let _00024sqo8IQh88 constd4735e3a265e16eee03f5971) (let _00024sqo7RbK91 constd59eced1ded07f84c145592f) (let _00024sqo36U490 const4e07408562bedb8b60ce05c1) (let _00024sqo5saO93 const4a44dc15364204a80fe80e90) (let _00024sqo1aiI92 const4e07408562bedb8b60ce05c1) (let _00024sqo1ciC95 constf5ca38f748a1d6eaf726b8a4) (let _00024sqo7rIE94 constd4735e3a265e16eee03f5971) (let _00024sqo0SAK97 const624b60c58c9d8bfb6ff1886c) (let _00024sqo1Nma96 const6b86b273ff34fce19d6b804e) (let _00024sqo2rtj99 constd59eced1ded07f84c145592f) (let _00024sqo2fAT98 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo0lYp85 _00024sqo9LAW84 _00024seq0) (body (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo5UlO87 _00024sqo2Pn786 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo116y89 _00024sqo8IQh88 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo7RbK91 _00024sqo36U490 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5saO93 _00024sqo1aiI92 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1ciC95 _00024sqo7rIE94 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo0SAK97 _00024sqo1Nma96 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2rtj99 _00024sqo2fAT98 _00024seq0) (join lst_ref (1 2 0) 2 _00024seq0 __tconst4tMq12 __t0saG13) (join lst_ref_ans (0 1) 1 __t0saG13 r) (letp _00024sql3t1j73 (aslst _00024seq0)) (let chk5wti394 (llen _00024sql3t1j73)) (eq _00024sqc7CLq75 chk5wti394) (letp chk1bpl395 (lref _00024sql3t1j73 _00024sqc2BUf76)) (eq _00024sqc9cGl77 chk1bpl395) (letp chk7sJn396 (lref _00024sql3t1j73 _00024sqc5J0l78)) (eq _00024sqc8mlt79 chk7sJn396) (letp chk8gOD397 (lref _00024sql3t1j73 _00024sqc3TWC80)) (eq _00024sqc0vYG81 chk8gOD397) (letp chk5WxD398 (lref _00024sql3t1j73 _00024sqc14Mu82)) (eq _00024sqc3HuO83 chk5WxD398)) (head (emit third (0) r)) lst_ops.slog:13 #f)
  class ReadTask681 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex665;  slog::Index** $seq_atindex666;  slog::Index** $seq_atindex667;  slog::Index** $seq_atrindex668;  slog::Index** $seq_atrindex669;  slog::Index** $seq_atrindex670;  slog::Index** $seq_atrindex671;  slog::Index** lst_refindex672;  slog::Index** lst_ref_ansindex673;  slog::Index** $seq_atdelta674;  slog::Index** $seq_atdelta675;  slog::Index** $seq_atdelta676;  slog::Index** $seq_atrdelta677;  slog::Index** $seq_atrdelta678;  slog::Index** $seq_atrdelta679;  slog::Index** $seq_atrdelta680;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("third");
      std::vector<u16> ord682({0});
      slog::Relation* readrel683 = db->getRelation("third");
      head_index[0] = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({0, 1, 2});
      slog::Relation* readrel685 = db->getRelation("$seq_at");
      driver_index = readrel685->getIndex(ord684, true);
      std::vector<u16> ord686({0, 1, 2});
      slog::Relation* readrel687 = db->getRelation("$seq_at");
      $seq_atindex665 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1, 2});
      slog::Relation* readrel689 = db->getRelation("$seq_at");
      $seq_atdelta674 = readrel689->getIndex(ord688, true);
      std::vector<u16> ord690({0, 1, 2});
      slog::Relation* readrel691 = db->getRelation("$seq_at");
      $seq_atindex666 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({0, 1, 2});
      slog::Relation* readrel693 = db->getRelation("$seq_at");
      $seq_atdelta675 = readrel693->getIndex(ord692, true);
      std::vector<u16> ord694({0, 1, 2});
      slog::Relation* readrel695 = db->getRelation("$seq_at");
      $seq_atindex667 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({0, 1, 2});
      slog::Relation* readrel697 = db->getRelation("$seq_at");
      $seq_atdelta676 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({0, 1, 2});
      slog::Relation* readrel699 = db->getRelation("$seq_atr");
      $seq_atrindex668 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({0, 1, 2});
      slog::Relation* readrel701 = db->getRelation("$seq_atr");
      $seq_atrdelta677 = readrel701->getIndex(ord700, true);
      std::vector<u16> ord702({0, 1, 2});
      slog::Relation* readrel703 = db->getRelation("$seq_atr");
      $seq_atrindex669 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({0, 1, 2});
      slog::Relation* readrel705 = db->getRelation("$seq_atr");
      $seq_atrdelta678 = readrel705->getIndex(ord704, true);
      std::vector<u16> ord706({0, 1, 2});
      slog::Relation* readrel707 = db->getRelation("$seq_atr");
      $seq_atrindex670 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({0, 1, 2});
      slog::Relation* readrel709 = db->getRelation("$seq_atr");
      $seq_atrdelta679 = readrel709->getIndex(ord708, true);
      std::vector<u16> ord710({0, 1, 2});
      slog::Relation* readrel711 = db->getRelation("$seq_atr");
      $seq_atrindex671 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({0, 1, 2});
      slog::Relation* readrel713 = db->getRelation("$seq_atr");
      $seq_atrdelta680 = readrel713->getIndex(ord712, true);
      std::vector<u16> ord714({1, 2, 0});
      slog::Relation* readrel715 = db->getRelation("lst_ref");
      lst_refindex672 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({0, 1});
      slog::Relation* readrel717 = db->getRelation("lst_ref_ans");
      lst_ref_ansindex673 = readrel717->getIndex(ord716, false);
  
    }
    ReadTask681(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constd4735e3a265e16eee03f5971;
      u64 v_c48 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const4a44dc15364204a80fe80e90;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c53 = v_constd4735e3a265e16eee03f5971;
      u64 v_c54 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c55 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c56 = v_constd59eced1ded07f84c145592f;
      u64 v_c57 = v_const4a44dc15364204a80fe80e90;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd59eced1ded07f84c145592f;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c65 = v_const4a44dc15364204a80fe80e90;
      u64 v_c66 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c67 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
      u64 v_c69 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_constd59eced1ded07f84c145592f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c57, v_c58, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m718) {
        u64 v_c19 = m718[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex665, $seq_atdelta674, std::array<u64,3>{v_c59, v_c60, v_c19}, [&](const std::array<u64,3>& m719) {
          slog::join_probe_old<3,3>($seq_atindex666, $seq_atdelta675, std::array<u64,3>{v_c61, v_c62, v_c19}, [&](const std::array<u64,3>& m720) {
            slog::join_probe_old<3,3>($seq_atindex667, $seq_atdelta676, std::array<u64,3>{v_c63, v_c64, v_c19}, [&](const std::array<u64,3>& m721) {
              slog::join_probe_old<3,3>($seq_atrindex668, $seq_atrdelta677, std::array<u64,3>{v_c65, v_c66, v_c19}, [&](const std::array<u64,3>& m722) {
                slog::join_probe_old<3,3>($seq_atrindex669, $seq_atrdelta678, std::array<u64,3>{v_c67, v_c68, v_c19}, [&](const std::array<u64,3>& m723) {
                  slog::join_probe_old<3,3>($seq_atrindex670, $seq_atrdelta679, std::array<u64,3>{v_c69, v_c70, v_c19}, [&](const std::array<u64,3>& m724) {
                    slog::join_probe_old<3,3>($seq_atrindex671, $seq_atrdelta680, std::array<u64,3>{v_c71, v_c72, v_c19}, [&](const std::array<u64,3>& m725) {
                      slog::join_probe<3,2>(lst_refindex672, std::array<u64,3>{v_c19, v_c47, 0}, [&](const std::array<u64,3>& m726) {
                        u64 v_c73 = m726[2];
                        slog::join_probe<2,1>(lst_ref_ansindex673, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m727) {
                          u64 v_c21 = m727[1];
                          bool ok728 = true;
                          u64 v_c74 = _prim_aslst(db, v_c19, &ok728);
                          if (!ok728) return;
                          u64 v_c110 = _prim_llen(db, v_c74);
                          if (v_c110 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:13"); return; }
                          if (v_c48 != v_c110) return;
                          bool ok729 = true;
                          u64 v_c111 = _prim_lref(db, v_c74, v_c49, &ok729);
                          if (!ok729) return;
                          if (v_c50 != v_c111) return;
                          bool ok730 = true;
                          u64 v_c112 = _prim_lref(db, v_c74, v_c51, &ok730);
                          if (!ok730) return;
                          if (v_c52 != v_c112) return;
                          bool ok731 = true;
                          u64 v_c113 = _prim_lref(db, v_c74, v_c53, &ok731);
                          if (!ok731) return;
                          if (v_c54 != v_c113) return;
                          bool ok732 = true;
                          u64 v_c114 = _prim_lref(db, v_c74, v_c55, &ok732);
                          if (!ok732) return;
                          if (v_c56 != v_c114) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:13", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask681* _cont = new ReadTask681(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask681(db,b), false);
  // (crule (pre) (scan div_by_zero __erre6Nvb364 __errf39jv365 __errf7nTT366) (body) (head (emit error (0) __erre6Nvb364)) <internal>:1 #f)
  class ReadTask733 : public slog::Task
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
      std::vector<u16> ord734({0});
      slog::Relation* readrel735 = db->getRelation("error");
      head_index[0] = readrel735->getIndex(ord734, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask733(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c115 = _t[0];
        u64 v_c116 = _t[1];
        u64 v_c117 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c115}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask733* _cont = new ReadTask733(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask733(db,b), false);
  // (crule (pre (let _00024sqc392E129 constd4735e3a265e16eee03f5971) (let _00024sqc1yNa130 const5feceb66ffc86f38d952786c) (let _00024sqc3BRp131 const6b86b273ff34fce19d6b804e) (let _00024sqc5ygu132 const6b86b273ff34fce19d6b804e) (let _00024sqc5PHP133 constd4735e3a265e16eee03f5971) (let _00024sqo5Ucn135 const6b86b273ff34fce19d6b804e) (let _00024sqo7swt134 const5feceb66ffc86f38d952786c) (let _00024sqo37bp137 constd4735e3a265e16eee03f5971) (let _00024sqo53GR136 const6b86b273ff34fce19d6b804e) (let _00024sqo5vAI139 const6b86b273ff34fce19d6b804e) (let _00024sqo4inq138 const6b86b273ff34fce19d6b804e) (let _00024sqo8Uyz141 constd4735e3a265e16eee03f5971) (let _00024sqo0DeM140 const5feceb66ffc86f38d952786c) (let _00024sqc5wh1144 constd4735e3a265e16eee03f5971) (let _00024sqc5YMJ145 const5feceb66ffc86f38d952786c) (let _00024sqc3B2s146 const4e07408562bedb8b60ce05c1) (let _00024sqc2InF147 const6b86b273ff34fce19d6b804e) (let _00024sqc5FD5148 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Fjd150 const4e07408562bedb8b60ce05c1) (let _00024sqo9F2d149 const5feceb66ffc86f38d952786c) (let _00024sqo9ZUl152 const4b227777d4dd1fc61c6f884f) (let _00024sqo9bFX151 const6b86b273ff34fce19d6b804e) (let _00024sqo4sZr154 const4e07408562bedb8b60ce05c1) (let _00024sqo6gFL153 const6b86b273ff34fce19d6b804e) (let _00024sqo1YfQ156 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Zm7155 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo1YfQ156 _00024sqo5Zm7155 _00024seq1) (body (join $seq_at (0 1 2) 3 _00024sqo5Fjd150 _00024sqo9F2d149 _00024seq1) (join $seq_at (0 1 2) 3 _00024sqo9ZUl152 _00024sqo9bFX151 _00024seq1) (join $seq_atr (0 1 2) 3 _00024sqo4sZr154 _00024sqo6gFL153 _00024seq1) (exists $seq_at (0 1 2) 2 _00024sqo37bp137 _00024sqo53GR136) (exists $seq_atr (0 1 2) 2 _00024sqo5vAI139 _00024sqo4inq138) (exists $seq_atr (0 1 2) 2 _00024sqo8Uyz141 _00024sqo0DeM140) (exists lst_append (2 0 1) 1 _00024seq1) (join $seq_at (0 1 2) 2 _00024sqo5Ucn135 _00024sqo7swt134 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo37bp137 _00024sqo53GR136 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5vAI139 _00024sqo4inq138 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8Uyz141 _00024sqo0DeM140 _00024seq0) (join lst_append (1 2 0) 2 _00024seq0 _00024seq1 __t0k0o29) (join lst_append_ans (0 1) 1 __t0k0o29 r) (letp _00024sql2Drd127 (aslst _00024seq0)) (let chk59Yp500 (llen _00024sql2Drd127)) (eq _00024sqc392E129 chk59Yp500) (letp chk4Vlq501 (lref _00024sql2Drd127 _00024sqc1yNa130)) (eq _00024sqc3BRp131 chk4Vlq501) (letp chk1MIK502 (lref _00024sql2Drd127 _00024sqc5ygu132)) (eq _00024sqc5PHP133 chk1MIK502) (letp _00024sql9o7V142 (aslst _00024seq1)) (let chk9zNS503 (llen _00024sql9o7V142)) (eq _00024sqc5wh1144 chk9zNS503) (letp chk4TuD504 (lref _00024sql9o7V142 _00024sqc5YMJ145)) (eq _00024sqc3B2s146 chk4TuD504) (letp chk0xuL505 (lref _00024sql9o7V142 _00024sqc2InF147)) (eq _00024sqc5FD5148 chk0xuL505)) (head (emit appended (0) r)) lst_ops.slog:12 #f)
  class ReadTask749 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex736;  slog::Index** $seq_atindex737;  slog::Index** $seq_atrindex738;  slog::Index** $seq_atindex739;  slog::Index** $seq_atrindex740;  slog::Index** $seq_atrindex741;  slog::Index** lst_appendindex742;  slog::Index** $seq_atindex743;  slog::Index** $seq_atindex744;  slog::Index** $seq_atrindex745;  slog::Index** $seq_atrindex746;  slog::Index** lst_appendindex747;  slog::Index** lst_append_ansindex748;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("appended");
      std::vector<u16> ord750({0});
      slog::Relation* readrel751 = db->getRelation("appended");
      head_index[0] = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({0, 1, 2});
      slog::Relation* readrel753 = db->getRelation("$seq_atr");
      driver_index = readrel753->getIndex(ord752, true);
      std::vector<u16> ord754({0, 1, 2});
      slog::Relation* readrel755 = db->getRelation("$seq_at");
      $seq_atindex736 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({0, 1, 2});
      slog::Relation* readrel757 = db->getRelation("$seq_at");
      $seq_atindex737 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({0, 1, 2});
      slog::Relation* readrel759 = db->getRelation("$seq_atr");
      $seq_atrindex738 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({0, 1, 2});
      slog::Relation* readrel761 = db->getRelation("$seq_at");
      $seq_atindex739 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({0, 1, 2});
      slog::Relation* readrel763 = db->getRelation("$seq_atr");
      $seq_atrindex740 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({0, 1, 2});
      slog::Relation* readrel765 = db->getRelation("$seq_atr");
      $seq_atrindex741 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({2, 0, 1});
      slog::Relation* readrel767 = db->getRelation("lst_append");
      lst_appendindex742 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({0, 1, 2});
      slog::Relation* readrel769 = db->getRelation("$seq_at");
      $seq_atindex743 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({0, 1, 2});
      slog::Relation* readrel771 = db->getRelation("$seq_at");
      $seq_atindex744 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({0, 1, 2});
      slog::Relation* readrel773 = db->getRelation("$seq_atr");
      $seq_atrindex745 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({0, 1, 2});
      slog::Relation* readrel775 = db->getRelation("$seq_atr");
      $seq_atrindex746 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 2, 0});
      slog::Relation* readrel777 = db->getRelation("lst_append");
      lst_appendindex747 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({0, 1});
      slog::Relation* readrel779 = db->getRelation("lst_append_ans");
      lst_append_ansindex748 = readrel779->getIndex(ord778, false);
  
    }
    ReadTask749(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_constd4735e3a265e16eee03f5971;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_constd4735e3a265e16eee03f5971;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
      u64 v_c133 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c136 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c142, v_c143, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m780) {
        u64 v_c144 = m780[2];
        if (buckethash(v_c144) != bucket) return;
        slog::join_probe<3,3>($seq_atindex736, std::array<u64,3>{v_c136, v_c137, v_c144}, [&](const std::array<u64,3>& m781) {
          slog::join_probe<3,3>($seq_atindex737, std::array<u64,3>{v_c138, v_c139, v_c144}, [&](const std::array<u64,3>& m782) {
            slog::join_probe<3,3>($seq_atrindex738, std::array<u64,3>{v_c140, v_c141, v_c144}, [&](const std::array<u64,3>& m783) {
              if (!slog::exists_probe<3,2>($seq_atindex739, std::array<u64,3>{v_c125, v_c126, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex740, std::array<u64,3>{v_c127, v_c128, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex741, std::array<u64,3>{v_c129, v_c130, 0})) return;
              if (!slog::exists_probe<3,1>(lst_appendindex742, std::array<u64,3>{v_c144, 0, 0})) return;
              slog::join_probe<3,2>($seq_atindex743, std::array<u64,3>{v_c123, v_c124, 0}, [&](const std::array<u64,3>& m784) {
                u64 v_c19 = m784[2];
                slog::join_probe<3,3>($seq_atindex744, std::array<u64,3>{v_c125, v_c126, v_c19}, [&](const std::array<u64,3>& m785) {
                  slog::join_probe<3,3>($seq_atrindex745, std::array<u64,3>{v_c127, v_c128, v_c19}, [&](const std::array<u64,3>& m786) {
                    slog::join_probe<3,3>($seq_atrindex746, std::array<u64,3>{v_c129, v_c130, v_c19}, [&](const std::array<u64,3>& m787) {
                      slog::join_probe<3,2>(lst_appendindex747, std::array<u64,3>{v_c19, v_c144, 0}, [&](const std::array<u64,3>& m788) {
                        u64 v_c145 = m788[2];
                        slog::join_probe<2,1>(lst_append_ansindex748, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m789) {
                          u64 v_c21 = m789[1];
                          bool ok790 = true;
                          u64 v_c146 = _prim_aslst(db, v_c19, &ok790);
                          if (!ok790) return;
                          u64 v_c147 = _prim_llen(db, v_c146);
                          if (v_c147 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c118 != v_c147) return;
                          bool ok791 = true;
                          u64 v_c148 = _prim_lref(db, v_c146, v_c119, &ok791);
                          if (!ok791) return;
                          if (v_c120 != v_c148) return;
                          bool ok792 = true;
                          u64 v_c149 = _prim_lref(db, v_c146, v_c121, &ok792);
                          if (!ok792) return;
                          if (v_c122 != v_c149) return;
                          bool ok793 = true;
                          u64 v_c150 = _prim_aslst(db, v_c144, &ok793);
                          if (!ok793) return;
                          u64 v_c151 = _prim_llen(db, v_c150);
                          if (v_c151 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c131 != v_c151) return;
                          bool ok794 = true;
                          u64 v_c152 = _prim_lref(db, v_c150, v_c132, &ok794);
                          if (!ok794) return;
                          if (v_c133 != v_c152) return;
                          bool ok795 = true;
                          u64 v_c153 = _prim_lref(db, v_c150, v_c134, &ok795);
                          if (!ok795) return;
                          if (v_c135 != v_c153) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:12", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask749* _cont = new ReadTask749(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask749(db,b), false);
  // (crule (pre (let _00024sqc392E129 constd4735e3a265e16eee03f5971) (let _00024sqc1yNa130 const5feceb66ffc86f38d952786c) (let _00024sqc3BRp131 const6b86b273ff34fce19d6b804e) (let _00024sqc5ygu132 const6b86b273ff34fce19d6b804e) (let _00024sqc5PHP133 constd4735e3a265e16eee03f5971) (let _00024sqo5Ucn135 const6b86b273ff34fce19d6b804e) (let _00024sqo7swt134 const5feceb66ffc86f38d952786c) (let _00024sqo37bp137 constd4735e3a265e16eee03f5971) (let _00024sqo53GR136 const6b86b273ff34fce19d6b804e) (let _00024sqo5vAI139 const6b86b273ff34fce19d6b804e) (let _00024sqo4inq138 const6b86b273ff34fce19d6b804e) (let _00024sqo8Uyz141 constd4735e3a265e16eee03f5971) (let _00024sqo0DeM140 const5feceb66ffc86f38d952786c) (let _00024sqc5wh1144 constd4735e3a265e16eee03f5971) (let _00024sqc5YMJ145 const5feceb66ffc86f38d952786c) (let _00024sqc3B2s146 const4e07408562bedb8b60ce05c1) (let _00024sqc2InF147 const6b86b273ff34fce19d6b804e) (let _00024sqc5FD5148 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Fjd150 const4e07408562bedb8b60ce05c1) (let _00024sqo9F2d149 const5feceb66ffc86f38d952786c) (let _00024sqo9ZUl152 const4b227777d4dd1fc61c6f884f) (let _00024sqo9bFX151 const6b86b273ff34fce19d6b804e) (let _00024sqo4sZr154 const4e07408562bedb8b60ce05c1) (let _00024sqo6gFL153 const6b86b273ff34fce19d6b804e) (let _00024sqo1YfQ156 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Zm7155 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo4sZr154 _00024sqo6gFL153 _00024seq1) (body (join $seq_at (0 1 2) 3 _00024sqo5Fjd150 _00024sqo9F2d149 _00024seq1) (join $seq_at (0 1 2) 3 _00024sqo9ZUl152 _00024sqo9bFX151 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1YfQ156 _00024sqo5Zm7155 _00024seq1) (exists $seq_at (0 1 2) 2 _00024sqo37bp137 _00024sqo53GR136) (exists $seq_atr (0 1 2) 2 _00024sqo5vAI139 _00024sqo4inq138) (exists $seq_atr (0 1 2) 2 _00024sqo8Uyz141 _00024sqo0DeM140) (exists lst_append (2 0 1) 1 _00024seq1) (join $seq_at (0 1 2) 2 _00024sqo5Ucn135 _00024sqo7swt134 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo37bp137 _00024sqo53GR136 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5vAI139 _00024sqo4inq138 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8Uyz141 _00024sqo0DeM140 _00024seq0) (join lst_append (1 2 0) 2 _00024seq0 _00024seq1 __t0k0o29) (join lst_append_ans (0 1) 1 __t0k0o29 r) (letp _00024sql2Drd127 (aslst _00024seq0)) (let chk8wUM494 (llen _00024sql2Drd127)) (eq _00024sqc392E129 chk8wUM494) (letp chk0792495 (lref _00024sql2Drd127 _00024sqc1yNa130)) (eq _00024sqc3BRp131 chk0792495) (letp chk8zBo496 (lref _00024sql2Drd127 _00024sqc5ygu132)) (eq _00024sqc5PHP133 chk8zBo496) (letp _00024sql9o7V142 (aslst _00024seq1)) (let chk87Rr497 (llen _00024sql9o7V142)) (eq _00024sqc5wh1144 chk87Rr497) (letp chk76el498 (lref _00024sql9o7V142 _00024sqc5YMJ145)) (eq _00024sqc3B2s146 chk76el498) (letp chk68Hi499 (lref _00024sql9o7V142 _00024sqc2InF147)) (eq _00024sqc5FD5148 chk68Hi499)) (head (emit appended (0) r)) lst_ops.slog:12 #f)
  class ReadTask810 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex796;  slog::Index** $seq_atindex797;  slog::Index** $seq_atrindex798;  slog::Index** $seq_atindex799;  slog::Index** $seq_atrindex800;  slog::Index** $seq_atrindex801;  slog::Index** lst_appendindex802;  slog::Index** $seq_atindex803;  slog::Index** $seq_atindex804;  slog::Index** $seq_atrindex805;  slog::Index** $seq_atrindex806;  slog::Index** lst_appendindex807;  slog::Index** lst_append_ansindex808;  slog::Index** $seq_atrdelta809;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("appended");
      std::vector<u16> ord811({0});
      slog::Relation* readrel812 = db->getRelation("appended");
      head_index[0] = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({0, 1, 2});
      slog::Relation* readrel814 = db->getRelation("$seq_atr");
      driver_index = readrel814->getIndex(ord813, true);
      std::vector<u16> ord815({0, 1, 2});
      slog::Relation* readrel816 = db->getRelation("$seq_at");
      $seq_atindex796 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({0, 1, 2});
      slog::Relation* readrel818 = db->getRelation("$seq_at");
      $seq_atindex797 = readrel818->getIndex(ord817, false);
      std::vector<u16> ord819({0, 1, 2});
      slog::Relation* readrel820 = db->getRelation("$seq_atr");
      $seq_atrindex798 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({0, 1, 2});
      slog::Relation* readrel822 = db->getRelation("$seq_atr");
      $seq_atrdelta809 = readrel822->getIndex(ord821, true);
      std::vector<u16> ord823({0, 1, 2});
      slog::Relation* readrel824 = db->getRelation("$seq_at");
      $seq_atindex799 = readrel824->getIndex(ord823, false);
      std::vector<u16> ord825({0, 1, 2});
      slog::Relation* readrel826 = db->getRelation("$seq_atr");
      $seq_atrindex800 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({0, 1, 2});
      slog::Relation* readrel828 = db->getRelation("$seq_atr");
      $seq_atrindex801 = readrel828->getIndex(ord827, false);
      std::vector<u16> ord829({2, 0, 1});
      slog::Relation* readrel830 = db->getRelation("lst_append");
      lst_appendindex802 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({0, 1, 2});
      slog::Relation* readrel832 = db->getRelation("$seq_at");
      $seq_atindex803 = readrel832->getIndex(ord831, false);
      std::vector<u16> ord833({0, 1, 2});
      slog::Relation* readrel834 = db->getRelation("$seq_at");
      $seq_atindex804 = readrel834->getIndex(ord833, false);
      std::vector<u16> ord835({0, 1, 2});
      slog::Relation* readrel836 = db->getRelation("$seq_atr");
      $seq_atrindex805 = readrel836->getIndex(ord835, false);
      std::vector<u16> ord837({0, 1, 2});
      slog::Relation* readrel838 = db->getRelation("$seq_atr");
      $seq_atrindex806 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({1, 2, 0});
      slog::Relation* readrel840 = db->getRelation("lst_append");
      lst_appendindex807 = readrel840->getIndex(ord839, false);
      std::vector<u16> ord841({0, 1});
      slog::Relation* readrel842 = db->getRelation("lst_append_ans");
      lst_append_ansindex808 = readrel842->getIndex(ord841, false);
  
    }
    ReadTask810(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_constd4735e3a265e16eee03f5971;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_constd4735e3a265e16eee03f5971;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
      u64 v_c133 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c136 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c140, v_c141, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m843) {
        u64 v_c144 = m843[2];
        if (buckethash(v_c144) != bucket) return;
        slog::join_probe<3,3>($seq_atindex796, std::array<u64,3>{v_c136, v_c137, v_c144}, [&](const std::array<u64,3>& m844) {
          slog::join_probe<3,3>($seq_atindex797, std::array<u64,3>{v_c138, v_c139, v_c144}, [&](const std::array<u64,3>& m845) {
            slog::join_probe_old<3,3>($seq_atrindex798, $seq_atrdelta809, std::array<u64,3>{v_c142, v_c143, v_c144}, [&](const std::array<u64,3>& m846) {
              if (!slog::exists_probe<3,2>($seq_atindex799, std::array<u64,3>{v_c125, v_c126, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex800, std::array<u64,3>{v_c127, v_c128, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex801, std::array<u64,3>{v_c129, v_c130, 0})) return;
              if (!slog::exists_probe<3,1>(lst_appendindex802, std::array<u64,3>{v_c144, 0, 0})) return;
              slog::join_probe<3,2>($seq_atindex803, std::array<u64,3>{v_c123, v_c124, 0}, [&](const std::array<u64,3>& m847) {
                u64 v_c19 = m847[2];
                slog::join_probe<3,3>($seq_atindex804, std::array<u64,3>{v_c125, v_c126, v_c19}, [&](const std::array<u64,3>& m848) {
                  slog::join_probe<3,3>($seq_atrindex805, std::array<u64,3>{v_c127, v_c128, v_c19}, [&](const std::array<u64,3>& m849) {
                    slog::join_probe<3,3>($seq_atrindex806, std::array<u64,3>{v_c129, v_c130, v_c19}, [&](const std::array<u64,3>& m850) {
                      slog::join_probe<3,2>(lst_appendindex807, std::array<u64,3>{v_c19, v_c144, 0}, [&](const std::array<u64,3>& m851) {
                        u64 v_c145 = m851[2];
                        slog::join_probe<2,1>(lst_append_ansindex808, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m852) {
                          u64 v_c21 = m852[1];
                          bool ok853 = true;
                          u64 v_c146 = _prim_aslst(db, v_c19, &ok853);
                          if (!ok853) return;
                          u64 v_c154 = _prim_llen(db, v_c146);
                          if (v_c154 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c118 != v_c154) return;
                          bool ok854 = true;
                          u64 v_c155 = _prim_lref(db, v_c146, v_c119, &ok854);
                          if (!ok854) return;
                          if (v_c120 != v_c155) return;
                          bool ok855 = true;
                          u64 v_c156 = _prim_lref(db, v_c146, v_c121, &ok855);
                          if (!ok855) return;
                          if (v_c122 != v_c156) return;
                          bool ok856 = true;
                          u64 v_c150 = _prim_aslst(db, v_c144, &ok856);
                          if (!ok856) return;
                          u64 v_c157 = _prim_llen(db, v_c150);
                          if (v_c157 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c131 != v_c157) return;
                          bool ok857 = true;
                          u64 v_c158 = _prim_lref(db, v_c150, v_c132, &ok857);
                          if (!ok857) return;
                          if (v_c133 != v_c158) return;
                          bool ok858 = true;
                          u64 v_c159 = _prim_lref(db, v_c150, v_c134, &ok858);
                          if (!ok858) return;
                          if (v_c135 != v_c159) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:12", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask810* _cont = new ReadTask810(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask810(db,b), false);
  // (crule (pre (let _00024sqc392E129 constd4735e3a265e16eee03f5971) (let _00024sqc1yNa130 const5feceb66ffc86f38d952786c) (let _00024sqc3BRp131 const6b86b273ff34fce19d6b804e) (let _00024sqc5ygu132 const6b86b273ff34fce19d6b804e) (let _00024sqc5PHP133 constd4735e3a265e16eee03f5971) (let _00024sqo5Ucn135 const6b86b273ff34fce19d6b804e) (let _00024sqo7swt134 const5feceb66ffc86f38d952786c) (let _00024sqo37bp137 constd4735e3a265e16eee03f5971) (let _00024sqo53GR136 const6b86b273ff34fce19d6b804e) (let _00024sqo5vAI139 const6b86b273ff34fce19d6b804e) (let _00024sqo4inq138 const6b86b273ff34fce19d6b804e) (let _00024sqo8Uyz141 constd4735e3a265e16eee03f5971) (let _00024sqo0DeM140 const5feceb66ffc86f38d952786c) (let _00024sqc5wh1144 constd4735e3a265e16eee03f5971) (let _00024sqc5YMJ145 const5feceb66ffc86f38d952786c) (let _00024sqc3B2s146 const4e07408562bedb8b60ce05c1) (let _00024sqc2InF147 const6b86b273ff34fce19d6b804e) (let _00024sqc5FD5148 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Fjd150 const4e07408562bedb8b60ce05c1) (let _00024sqo9F2d149 const5feceb66ffc86f38d952786c) (let _00024sqo9ZUl152 const4b227777d4dd1fc61c6f884f) (let _00024sqo9bFX151 const6b86b273ff34fce19d6b804e) (let _00024sqo4sZr154 const4e07408562bedb8b60ce05c1) (let _00024sqo6gFL153 const6b86b273ff34fce19d6b804e) (let _00024sqo1YfQ156 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Zm7155 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo9ZUl152 _00024sqo9bFX151 _00024seq1) (body (join $seq_at (0 1 2) 3 _00024sqo5Fjd150 _00024sqo9F2d149 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sZr154 _00024sqo6gFL153 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1YfQ156 _00024sqo5Zm7155 _00024seq1) (exists $seq_at (0 1 2) 2 _00024sqo37bp137 _00024sqo53GR136) (exists $seq_atr (0 1 2) 2 _00024sqo5vAI139 _00024sqo4inq138) (exists $seq_atr (0 1 2) 2 _00024sqo8Uyz141 _00024sqo0DeM140) (exists lst_append (2 0 1) 1 _00024seq1) (join $seq_at (0 1 2) 2 _00024sqo5Ucn135 _00024sqo7swt134 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo37bp137 _00024sqo53GR136 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5vAI139 _00024sqo4inq138 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8Uyz141 _00024sqo0DeM140 _00024seq0) (join lst_append (1 2 0) 2 _00024seq0 _00024seq1 __t0k0o29) (join lst_append_ans (0 1) 1 __t0k0o29 r) (letp _00024sql2Drd127 (aslst _00024seq0)) (let chk7fNY488 (llen _00024sql2Drd127)) (eq _00024sqc392E129 chk7fNY488) (letp chk9jID489 (lref _00024sql2Drd127 _00024sqc1yNa130)) (eq _00024sqc3BRp131 chk9jID489) (letp chk6BFc490 (lref _00024sql2Drd127 _00024sqc5ygu132)) (eq _00024sqc5PHP133 chk6BFc490) (letp _00024sql9o7V142 (aslst _00024seq1)) (let chk7tfh491 (llen _00024sql9o7V142)) (eq _00024sqc5wh1144 chk7tfh491) (letp chk9wOB492 (lref _00024sql9o7V142 _00024sqc5YMJ145)) (eq _00024sqc3B2s146 chk9wOB492) (letp chk0Kun493 (lref _00024sql9o7V142 _00024sqc2InF147)) (eq _00024sqc5FD5148 chk0Kun493)) (head (emit appended (0) r)) lst_ops.slog:12 #f)
  class ReadTask874 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex859;  slog::Index** $seq_atrindex860;  slog::Index** $seq_atrindex861;  slog::Index** $seq_atindex862;  slog::Index** $seq_atrindex863;  slog::Index** $seq_atrindex864;  slog::Index** lst_appendindex865;  slog::Index** $seq_atindex866;  slog::Index** $seq_atindex867;  slog::Index** $seq_atrindex868;  slog::Index** $seq_atrindex869;  slog::Index** lst_appendindex870;  slog::Index** lst_append_ansindex871;  slog::Index** $seq_atrdelta872;  slog::Index** $seq_atrdelta873;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("appended");
      std::vector<u16> ord875({0});
      slog::Relation* readrel876 = db->getRelation("appended");
      head_index[0] = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({0, 1, 2});
      slog::Relation* readrel878 = db->getRelation("$seq_at");
      driver_index = readrel878->getIndex(ord877, true);
      std::vector<u16> ord879({0, 1, 2});
      slog::Relation* readrel880 = db->getRelation("$seq_at");
      $seq_atindex859 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({0, 1, 2});
      slog::Relation* readrel882 = db->getRelation("$seq_atr");
      $seq_atrindex860 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({0, 1, 2});
      slog::Relation* readrel884 = db->getRelation("$seq_atr");
      $seq_atrdelta872 = readrel884->getIndex(ord883, true);
      std::vector<u16> ord885({0, 1, 2});
      slog::Relation* readrel886 = db->getRelation("$seq_atr");
      $seq_atrindex861 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({0, 1, 2});
      slog::Relation* readrel888 = db->getRelation("$seq_atr");
      $seq_atrdelta873 = readrel888->getIndex(ord887, true);
      std::vector<u16> ord889({0, 1, 2});
      slog::Relation* readrel890 = db->getRelation("$seq_at");
      $seq_atindex862 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({0, 1, 2});
      slog::Relation* readrel892 = db->getRelation("$seq_atr");
      $seq_atrindex863 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({0, 1, 2});
      slog::Relation* readrel894 = db->getRelation("$seq_atr");
      $seq_atrindex864 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({2, 0, 1});
      slog::Relation* readrel896 = db->getRelation("lst_append");
      lst_appendindex865 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({0, 1, 2});
      slog::Relation* readrel898 = db->getRelation("$seq_at");
      $seq_atindex866 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({0, 1, 2});
      slog::Relation* readrel900 = db->getRelation("$seq_at");
      $seq_atindex867 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({0, 1, 2});
      slog::Relation* readrel902 = db->getRelation("$seq_atr");
      $seq_atrindex868 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({0, 1, 2});
      slog::Relation* readrel904 = db->getRelation("$seq_atr");
      $seq_atrindex869 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({1, 2, 0});
      slog::Relation* readrel906 = db->getRelation("lst_append");
      lst_appendindex870 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({0, 1});
      slog::Relation* readrel908 = db->getRelation("lst_append_ans");
      lst_append_ansindex871 = readrel908->getIndex(ord907, false);
  
    }
    ReadTask874(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_constd4735e3a265e16eee03f5971;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_constd4735e3a265e16eee03f5971;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
      u64 v_c133 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c136 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c138, v_c139, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m909) {
        u64 v_c144 = m909[2];
        if (buckethash(v_c144) != bucket) return;
        slog::join_probe<3,3>($seq_atindex859, std::array<u64,3>{v_c136, v_c137, v_c144}, [&](const std::array<u64,3>& m910) {
          slog::join_probe_old<3,3>($seq_atrindex860, $seq_atrdelta872, std::array<u64,3>{v_c140, v_c141, v_c144}, [&](const std::array<u64,3>& m911) {
            slog::join_probe_old<3,3>($seq_atrindex861, $seq_atrdelta873, std::array<u64,3>{v_c142, v_c143, v_c144}, [&](const std::array<u64,3>& m912) {
              if (!slog::exists_probe<3,2>($seq_atindex862, std::array<u64,3>{v_c125, v_c126, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex863, std::array<u64,3>{v_c127, v_c128, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex864, std::array<u64,3>{v_c129, v_c130, 0})) return;
              if (!slog::exists_probe<3,1>(lst_appendindex865, std::array<u64,3>{v_c144, 0, 0})) return;
              slog::join_probe<3,2>($seq_atindex866, std::array<u64,3>{v_c123, v_c124, 0}, [&](const std::array<u64,3>& m913) {
                u64 v_c19 = m913[2];
                slog::join_probe<3,3>($seq_atindex867, std::array<u64,3>{v_c125, v_c126, v_c19}, [&](const std::array<u64,3>& m914) {
                  slog::join_probe<3,3>($seq_atrindex868, std::array<u64,3>{v_c127, v_c128, v_c19}, [&](const std::array<u64,3>& m915) {
                    slog::join_probe<3,3>($seq_atrindex869, std::array<u64,3>{v_c129, v_c130, v_c19}, [&](const std::array<u64,3>& m916) {
                      slog::join_probe<3,2>(lst_appendindex870, std::array<u64,3>{v_c19, v_c144, 0}, [&](const std::array<u64,3>& m917) {
                        u64 v_c145 = m917[2];
                        slog::join_probe<2,1>(lst_append_ansindex871, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m918) {
                          u64 v_c21 = m918[1];
                          bool ok919 = true;
                          u64 v_c146 = _prim_aslst(db, v_c19, &ok919);
                          if (!ok919) return;
                          u64 v_c160 = _prim_llen(db, v_c146);
                          if (v_c160 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c118 != v_c160) return;
                          bool ok920 = true;
                          u64 v_c161 = _prim_lref(db, v_c146, v_c119, &ok920);
                          if (!ok920) return;
                          if (v_c120 != v_c161) return;
                          bool ok921 = true;
                          u64 v_c162 = _prim_lref(db, v_c146, v_c121, &ok921);
                          if (!ok921) return;
                          if (v_c122 != v_c162) return;
                          bool ok922 = true;
                          u64 v_c150 = _prim_aslst(db, v_c144, &ok922);
                          if (!ok922) return;
                          u64 v_c163 = _prim_llen(db, v_c150);
                          if (v_c163 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c131 != v_c163) return;
                          bool ok923 = true;
                          u64 v_c164 = _prim_lref(db, v_c150, v_c132, &ok923);
                          if (!ok923) return;
                          if (v_c133 != v_c164) return;
                          bool ok924 = true;
                          u64 v_c165 = _prim_lref(db, v_c150, v_c134, &ok924);
                          if (!ok924) return;
                          if (v_c135 != v_c165) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:12", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask874* _cont = new ReadTask874(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask874(db,b), false);
  // (crule (pre (let _00024sqc392E129 constd4735e3a265e16eee03f5971) (let _00024sqc1yNa130 const5feceb66ffc86f38d952786c) (let _00024sqc3BRp131 const6b86b273ff34fce19d6b804e) (let _00024sqc5ygu132 const6b86b273ff34fce19d6b804e) (let _00024sqc5PHP133 constd4735e3a265e16eee03f5971) (let _00024sqo5Ucn135 const6b86b273ff34fce19d6b804e) (let _00024sqo7swt134 const5feceb66ffc86f38d952786c) (let _00024sqo37bp137 constd4735e3a265e16eee03f5971) (let _00024sqo53GR136 const6b86b273ff34fce19d6b804e) (let _00024sqo5vAI139 const6b86b273ff34fce19d6b804e) (let _00024sqo4inq138 const6b86b273ff34fce19d6b804e) (let _00024sqo8Uyz141 constd4735e3a265e16eee03f5971) (let _00024sqo0DeM140 const5feceb66ffc86f38d952786c) (let _00024sqc5wh1144 constd4735e3a265e16eee03f5971) (let _00024sqc5YMJ145 const5feceb66ffc86f38d952786c) (let _00024sqc3B2s146 const4e07408562bedb8b60ce05c1) (let _00024sqc2InF147 const6b86b273ff34fce19d6b804e) (let _00024sqc5FD5148 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Fjd150 const4e07408562bedb8b60ce05c1) (let _00024sqo9F2d149 const5feceb66ffc86f38d952786c) (let _00024sqo9ZUl152 const4b227777d4dd1fc61c6f884f) (let _00024sqo9bFX151 const6b86b273ff34fce19d6b804e) (let _00024sqo4sZr154 const4e07408562bedb8b60ce05c1) (let _00024sqo6gFL153 const6b86b273ff34fce19d6b804e) (let _00024sqo1YfQ156 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Zm7155 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo5Fjd150 _00024sqo9F2d149 _00024seq1) (body (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo9ZUl152 _00024sqo9bFX151 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sZr154 _00024sqo6gFL153 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1YfQ156 _00024sqo5Zm7155 _00024seq1) (exists $seq_at (0 1 2) 2 _00024sqo37bp137 _00024sqo53GR136) (exists $seq_atr (0 1 2) 2 _00024sqo5vAI139 _00024sqo4inq138) (exists $seq_atr (0 1 2) 2 _00024sqo8Uyz141 _00024sqo0DeM140) (exists lst_append (2 0 1) 1 _00024seq1) (join $seq_at (0 1 2) 2 _00024sqo5Ucn135 _00024sqo7swt134 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo37bp137 _00024sqo53GR136 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5vAI139 _00024sqo4inq138 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8Uyz141 _00024sqo0DeM140 _00024seq0) (join lst_append (1 2 0) 2 _00024seq0 _00024seq1 __t0k0o29) (join lst_append_ans (0 1) 1 __t0k0o29 r) (letp _00024sql2Drd127 (aslst _00024seq0)) (let chk6tBp482 (llen _00024sql2Drd127)) (eq _00024sqc392E129 chk6tBp482) (letp chk0aRy483 (lref _00024sql2Drd127 _00024sqc1yNa130)) (eq _00024sqc3BRp131 chk0aRy483) (letp chk37tG484 (lref _00024sql2Drd127 _00024sqc5ygu132)) (eq _00024sqc5PHP133 chk37tG484) (letp _00024sql9o7V142 (aslst _00024seq1)) (let chk2Ren485 (llen _00024sql9o7V142)) (eq _00024sqc5wh1144 chk2Ren485) (letp chk9ehM486 (lref _00024sql9o7V142 _00024sqc5YMJ145)) (eq _00024sqc3B2s146 chk9ehM486) (letp chk9Uhx487 (lref _00024sql9o7V142 _00024sqc2InF147)) (eq _00024sqc5FD5148 chk9Uhx487)) (head (emit appended (0) r)) lst_ops.slog:12 #f)
  class ReadTask941 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex925;  slog::Index** $seq_atrindex926;  slog::Index** $seq_atrindex927;  slog::Index** $seq_atindex928;  slog::Index** $seq_atrindex929;  slog::Index** $seq_atrindex930;  slog::Index** lst_appendindex931;  slog::Index** $seq_atindex932;  slog::Index** $seq_atindex933;  slog::Index** $seq_atrindex934;  slog::Index** $seq_atrindex935;  slog::Index** lst_appendindex936;  slog::Index** lst_append_ansindex937;  slog::Index** $seq_atdelta938;  slog::Index** $seq_atrdelta939;  slog::Index** $seq_atrdelta940;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("appended");
      std::vector<u16> ord942({0});
      slog::Relation* readrel943 = db->getRelation("appended");
      head_index[0] = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({0, 1, 2});
      slog::Relation* readrel945 = db->getRelation("$seq_at");
      driver_index = readrel945->getIndex(ord944, true);
      std::vector<u16> ord946({0, 1, 2});
      slog::Relation* readrel947 = db->getRelation("$seq_at");
      $seq_atindex925 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({0, 1, 2});
      slog::Relation* readrel949 = db->getRelation("$seq_at");
      $seq_atdelta938 = readrel949->getIndex(ord948, true);
      std::vector<u16> ord950({0, 1, 2});
      slog::Relation* readrel951 = db->getRelation("$seq_atr");
      $seq_atrindex926 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({0, 1, 2});
      slog::Relation* readrel953 = db->getRelation("$seq_atr");
      $seq_atrdelta939 = readrel953->getIndex(ord952, true);
      std::vector<u16> ord954({0, 1, 2});
      slog::Relation* readrel955 = db->getRelation("$seq_atr");
      $seq_atrindex927 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({0, 1, 2});
      slog::Relation* readrel957 = db->getRelation("$seq_atr");
      $seq_atrdelta940 = readrel957->getIndex(ord956, true);
      std::vector<u16> ord958({0, 1, 2});
      slog::Relation* readrel959 = db->getRelation("$seq_at");
      $seq_atindex928 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({0, 1, 2});
      slog::Relation* readrel961 = db->getRelation("$seq_atr");
      $seq_atrindex929 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({0, 1, 2});
      slog::Relation* readrel963 = db->getRelation("$seq_atr");
      $seq_atrindex930 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({2, 0, 1});
      slog::Relation* readrel965 = db->getRelation("lst_append");
      lst_appendindex931 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({0, 1, 2});
      slog::Relation* readrel967 = db->getRelation("$seq_at");
      $seq_atindex932 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({0, 1, 2});
      slog::Relation* readrel969 = db->getRelation("$seq_at");
      $seq_atindex933 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({0, 1, 2});
      slog::Relation* readrel971 = db->getRelation("$seq_atr");
      $seq_atrindex934 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({0, 1, 2});
      slog::Relation* readrel973 = db->getRelation("$seq_atr");
      $seq_atrindex935 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 2, 0});
      slog::Relation* readrel975 = db->getRelation("lst_append");
      lst_appendindex936 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({0, 1});
      slog::Relation* readrel977 = db->getRelation("lst_append_ans");
      lst_append_ansindex937 = readrel977->getIndex(ord976, false);
  
    }
    ReadTask941(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_constd4735e3a265e16eee03f5971;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_constd4735e3a265e16eee03f5971;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
      u64 v_c133 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c136 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c136, v_c137, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m978) {
        u64 v_c144 = m978[2];
        if (buckethash(v_c144) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex925, $seq_atdelta938, std::array<u64,3>{v_c138, v_c139, v_c144}, [&](const std::array<u64,3>& m979) {
          slog::join_probe_old<3,3>($seq_atrindex926, $seq_atrdelta939, std::array<u64,3>{v_c140, v_c141, v_c144}, [&](const std::array<u64,3>& m980) {
            slog::join_probe_old<3,3>($seq_atrindex927, $seq_atrdelta940, std::array<u64,3>{v_c142, v_c143, v_c144}, [&](const std::array<u64,3>& m981) {
              if (!slog::exists_probe<3,2>($seq_atindex928, std::array<u64,3>{v_c125, v_c126, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex929, std::array<u64,3>{v_c127, v_c128, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex930, std::array<u64,3>{v_c129, v_c130, 0})) return;
              if (!slog::exists_probe<3,1>(lst_appendindex931, std::array<u64,3>{v_c144, 0, 0})) return;
              slog::join_probe<3,2>($seq_atindex932, std::array<u64,3>{v_c123, v_c124, 0}, [&](const std::array<u64,3>& m982) {
                u64 v_c19 = m982[2];
                slog::join_probe<3,3>($seq_atindex933, std::array<u64,3>{v_c125, v_c126, v_c19}, [&](const std::array<u64,3>& m983) {
                  slog::join_probe<3,3>($seq_atrindex934, std::array<u64,3>{v_c127, v_c128, v_c19}, [&](const std::array<u64,3>& m984) {
                    slog::join_probe<3,3>($seq_atrindex935, std::array<u64,3>{v_c129, v_c130, v_c19}, [&](const std::array<u64,3>& m985) {
                      slog::join_probe<3,2>(lst_appendindex936, std::array<u64,3>{v_c19, v_c144, 0}, [&](const std::array<u64,3>& m986) {
                        u64 v_c145 = m986[2];
                        slog::join_probe<2,1>(lst_append_ansindex937, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m987) {
                          u64 v_c21 = m987[1];
                          bool ok988 = true;
                          u64 v_c146 = _prim_aslst(db, v_c19, &ok988);
                          if (!ok988) return;
                          u64 v_c166 = _prim_llen(db, v_c146);
                          if (v_c166 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c118 != v_c166) return;
                          bool ok989 = true;
                          u64 v_c167 = _prim_lref(db, v_c146, v_c119, &ok989);
                          if (!ok989) return;
                          if (v_c120 != v_c167) return;
                          bool ok990 = true;
                          u64 v_c168 = _prim_lref(db, v_c146, v_c121, &ok990);
                          if (!ok990) return;
                          if (v_c122 != v_c168) return;
                          bool ok991 = true;
                          u64 v_c150 = _prim_aslst(db, v_c144, &ok991);
                          if (!ok991) return;
                          u64 v_c169 = _prim_llen(db, v_c150);
                          if (v_c169 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c131 != v_c169) return;
                          bool ok992 = true;
                          u64 v_c170 = _prim_lref(db, v_c150, v_c132, &ok992);
                          if (!ok992) return;
                          if (v_c133 != v_c170) return;
                          bool ok993 = true;
                          u64 v_c171 = _prim_lref(db, v_c150, v_c134, &ok993);
                          if (!ok993) return;
                          if (v_c135 != v_c171) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:12", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask941* _cont = new ReadTask941(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask941(db,b), false);
  // (crule (pre (let _00024sqc392E129 constd4735e3a265e16eee03f5971) (let _00024sqc1yNa130 const5feceb66ffc86f38d952786c) (let _00024sqc3BRp131 const6b86b273ff34fce19d6b804e) (let _00024sqc5ygu132 const6b86b273ff34fce19d6b804e) (let _00024sqc5PHP133 constd4735e3a265e16eee03f5971) (let _00024sqo5Ucn135 const6b86b273ff34fce19d6b804e) (let _00024sqo7swt134 const5feceb66ffc86f38d952786c) (let _00024sqo37bp137 constd4735e3a265e16eee03f5971) (let _00024sqo53GR136 const6b86b273ff34fce19d6b804e) (let _00024sqo5vAI139 const6b86b273ff34fce19d6b804e) (let _00024sqo4inq138 const6b86b273ff34fce19d6b804e) (let _00024sqo8Uyz141 constd4735e3a265e16eee03f5971) (let _00024sqo0DeM140 const5feceb66ffc86f38d952786c) (let _00024sqc5wh1144 constd4735e3a265e16eee03f5971) (let _00024sqc5YMJ145 const5feceb66ffc86f38d952786c) (let _00024sqc3B2s146 const4e07408562bedb8b60ce05c1) (let _00024sqc2InF147 const6b86b273ff34fce19d6b804e) (let _00024sqc5FD5148 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Fjd150 const4e07408562bedb8b60ce05c1) (let _00024sqo9F2d149 const5feceb66ffc86f38d952786c) (let _00024sqo9ZUl152 const4b227777d4dd1fc61c6f884f) (let _00024sqo9bFX151 const6b86b273ff34fce19d6b804e) (let _00024sqo4sZr154 const4e07408562bedb8b60ce05c1) (let _00024sqo6gFL153 const6b86b273ff34fce19d6b804e) (let _00024sqo1YfQ156 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Zm7155 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo8Uyz141 _00024sqo0DeM140 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo5Ucn135 _00024sqo7swt134 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo37bp137 _00024sqo53GR136 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5vAI139 _00024sqo4inq138 _00024seq0) (exists $seq_at (0 1 2) 2 _00024sqo9ZUl152 _00024sqo9bFX151) (exists $seq_atr (0 1 2) 2 _00024sqo4sZr154 _00024sqo6gFL153) (exists $seq_atr (0 1 2) 2 _00024sqo1YfQ156 _00024sqo5Zm7155) (exists lst_append (1 2 0) 1 _00024seq0) (join-old $seq_at (0 1 2) 2 (0 1 2) _00024sqo5Fjd150 _00024sqo9F2d149 _00024seq1) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo9ZUl152 _00024sqo9bFX151 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sZr154 _00024sqo6gFL153 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1YfQ156 _00024sqo5Zm7155 _00024seq1) (join lst_append (1 2 0) 2 _00024seq0 _00024seq1 __t0k0o29) (join lst_append_ans (0 1) 1 __t0k0o29 r) (letp _00024sql2Drd127 (aslst _00024seq0)) (let chk6s3Y476 (llen _00024sql2Drd127)) (eq _00024sqc392E129 chk6s3Y476) (letp chk6PJL477 (lref _00024sql2Drd127 _00024sqc1yNa130)) (eq _00024sqc3BRp131 chk6PJL477) (letp chk3ptH478 (lref _00024sql2Drd127 _00024sqc5ygu132)) (eq _00024sqc5PHP133 chk3ptH478) (letp _00024sql9o7V142 (aslst _00024seq1)) (let chk4TsK479 (llen _00024sql9o7V142)) (eq _00024sqc5wh1144 chk4TsK479) (letp chk9Wpq480 (lref _00024sql9o7V142 _00024sqc5YMJ145)) (eq _00024sqc3B2s146 chk9Wpq480) (letp chk6Iid481 (lref _00024sql9o7V142 _00024sqc2InF147)) (eq _00024sqc5FD5148 chk6Iid481)) (head (emit appended (0) r)) lst_ops.slog:12 #f)
  class ReadTask1011 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex994;  slog::Index** $seq_atindex995;  slog::Index** $seq_atrindex996;  slog::Index** $seq_atindex997;  slog::Index** $seq_atrindex998;  slog::Index** $seq_atrindex999;  slog::Index** lst_appendindex1000;  slog::Index** $seq_atindex1001;  slog::Index** $seq_atindex1002;  slog::Index** $seq_atrindex1003;  slog::Index** $seq_atrindex1004;  slog::Index** lst_appendindex1005;  slog::Index** lst_append_ansindex1006;  slog::Index** $seq_atdelta1007;  slog::Index** $seq_atdelta1008;  slog::Index** $seq_atrdelta1009;  slog::Index** $seq_atrdelta1010;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("appended");
      std::vector<u16> ord1012({0});
      slog::Relation* readrel1013 = db->getRelation("appended");
      head_index[0] = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({0, 1, 2});
      slog::Relation* readrel1015 = db->getRelation("$seq_atr");
      driver_index = readrel1015->getIndex(ord1014, true);
      std::vector<u16> ord1016({0, 1, 2});
      slog::Relation* readrel1017 = db->getRelation("$seq_at");
      $seq_atindex994 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({0, 1, 2});
      slog::Relation* readrel1019 = db->getRelation("$seq_at");
      $seq_atindex995 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({0, 1, 2});
      slog::Relation* readrel1021 = db->getRelation("$seq_atr");
      $seq_atrindex996 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({0, 1, 2});
      slog::Relation* readrel1023 = db->getRelation("$seq_at");
      $seq_atindex997 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({0, 1, 2});
      slog::Relation* readrel1025 = db->getRelation("$seq_atr");
      $seq_atrindex998 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({0, 1, 2});
      slog::Relation* readrel1027 = db->getRelation("$seq_atr");
      $seq_atrindex999 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({1, 2, 0});
      slog::Relation* readrel1029 = db->getRelation("lst_append");
      lst_appendindex1000 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({0, 1, 2});
      slog::Relation* readrel1031 = db->getRelation("$seq_at");
      $seq_atindex1001 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({0, 1, 2});
      slog::Relation* readrel1033 = db->getRelation("$seq_at");
      $seq_atdelta1007 = readrel1033->getIndex(ord1032, true);
      std::vector<u16> ord1034({0, 1, 2});
      slog::Relation* readrel1035 = db->getRelation("$seq_at");
      $seq_atindex1002 = readrel1035->getIndex(ord1034, false);
      std::vector<u16> ord1036({0, 1, 2});
      slog::Relation* readrel1037 = db->getRelation("$seq_at");
      $seq_atdelta1008 = readrel1037->getIndex(ord1036, true);
      std::vector<u16> ord1038({0, 1, 2});
      slog::Relation* readrel1039 = db->getRelation("$seq_atr");
      $seq_atrindex1003 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({0, 1, 2});
      slog::Relation* readrel1041 = db->getRelation("$seq_atr");
      $seq_atrdelta1009 = readrel1041->getIndex(ord1040, true);
      std::vector<u16> ord1042({0, 1, 2});
      slog::Relation* readrel1043 = db->getRelation("$seq_atr");
      $seq_atrindex1004 = readrel1043->getIndex(ord1042, false);
      std::vector<u16> ord1044({0, 1, 2});
      slog::Relation* readrel1045 = db->getRelation("$seq_atr");
      $seq_atrdelta1010 = readrel1045->getIndex(ord1044, true);
      std::vector<u16> ord1046({1, 2, 0});
      slog::Relation* readrel1047 = db->getRelation("lst_append");
      lst_appendindex1005 = readrel1047->getIndex(ord1046, false);
      std::vector<u16> ord1048({0, 1});
      slog::Relation* readrel1049 = db->getRelation("lst_append_ans");
      lst_append_ansindex1006 = readrel1049->getIndex(ord1048, false);
  
    }
    ReadTask1011(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_constd4735e3a265e16eee03f5971;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_constd4735e3a265e16eee03f5971;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
      u64 v_c133 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c136 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c129, v_c130, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1050) {
        u64 v_c19 = m1050[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex994, std::array<u64,3>{v_c123, v_c124, v_c19}, [&](const std::array<u64,3>& m1051) {
          slog::join_probe<3,3>($seq_atindex995, std::array<u64,3>{v_c125, v_c126, v_c19}, [&](const std::array<u64,3>& m1052) {
            slog::join_probe<3,3>($seq_atrindex996, std::array<u64,3>{v_c127, v_c128, v_c19}, [&](const std::array<u64,3>& m1053) {
              if (!slog::exists_probe<3,2>($seq_atindex997, std::array<u64,3>{v_c138, v_c139, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex998, std::array<u64,3>{v_c140, v_c141, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex999, std::array<u64,3>{v_c142, v_c143, 0})) return;
              if (!slog::exists_probe<3,1>(lst_appendindex1000, std::array<u64,3>{v_c19, 0, 0})) return;
              slog::join_probe_old<3,2>($seq_atindex1001, $seq_atdelta1007, std::array<u64,3>{v_c136, v_c137, 0}, [&](const std::array<u64,3>& m1054) {
                u64 v_c144 = m1054[2];
                slog::join_probe_old<3,3>($seq_atindex1002, $seq_atdelta1008, std::array<u64,3>{v_c138, v_c139, v_c144}, [&](const std::array<u64,3>& m1055) {
                  slog::join_probe_old<3,3>($seq_atrindex1003, $seq_atrdelta1009, std::array<u64,3>{v_c140, v_c141, v_c144}, [&](const std::array<u64,3>& m1056) {
                    slog::join_probe_old<3,3>($seq_atrindex1004, $seq_atrdelta1010, std::array<u64,3>{v_c142, v_c143, v_c144}, [&](const std::array<u64,3>& m1057) {
                      slog::join_probe<3,2>(lst_appendindex1005, std::array<u64,3>{v_c19, v_c144, 0}, [&](const std::array<u64,3>& m1058) {
                        u64 v_c145 = m1058[2];
                        slog::join_probe<2,1>(lst_append_ansindex1006, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m1059) {
                          u64 v_c21 = m1059[1];
                          bool ok1060 = true;
                          u64 v_c146 = _prim_aslst(db, v_c19, &ok1060);
                          if (!ok1060) return;
                          u64 v_c172 = _prim_llen(db, v_c146);
                          if (v_c172 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c118 != v_c172) return;
                          bool ok1061 = true;
                          u64 v_c173 = _prim_lref(db, v_c146, v_c119, &ok1061);
                          if (!ok1061) return;
                          if (v_c120 != v_c173) return;
                          bool ok1062 = true;
                          u64 v_c174 = _prim_lref(db, v_c146, v_c121, &ok1062);
                          if (!ok1062) return;
                          if (v_c122 != v_c174) return;
                          bool ok1063 = true;
                          u64 v_c150 = _prim_aslst(db, v_c144, &ok1063);
                          if (!ok1063) return;
                          u64 v_c175 = _prim_llen(db, v_c150);
                          if (v_c175 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c131 != v_c175) return;
                          bool ok1064 = true;
                          u64 v_c176 = _prim_lref(db, v_c150, v_c132, &ok1064);
                          if (!ok1064) return;
                          if (v_c133 != v_c176) return;
                          bool ok1065 = true;
                          u64 v_c177 = _prim_lref(db, v_c150, v_c134, &ok1065);
                          if (!ok1065) return;
                          if (v_c135 != v_c177) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:12", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1011* _cont = new ReadTask1011(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1011(db,b), false);
  // (crule (pre (let _00024sqc392E129 constd4735e3a265e16eee03f5971) (let _00024sqc1yNa130 const5feceb66ffc86f38d952786c) (let _00024sqc3BRp131 const6b86b273ff34fce19d6b804e) (let _00024sqc5ygu132 const6b86b273ff34fce19d6b804e) (let _00024sqc5PHP133 constd4735e3a265e16eee03f5971) (let _00024sqo5Ucn135 const6b86b273ff34fce19d6b804e) (let _00024sqo7swt134 const5feceb66ffc86f38d952786c) (let _00024sqo37bp137 constd4735e3a265e16eee03f5971) (let _00024sqo53GR136 const6b86b273ff34fce19d6b804e) (let _00024sqo5vAI139 const6b86b273ff34fce19d6b804e) (let _00024sqo4inq138 const6b86b273ff34fce19d6b804e) (let _00024sqo8Uyz141 constd4735e3a265e16eee03f5971) (let _00024sqo0DeM140 const5feceb66ffc86f38d952786c) (let _00024sqc5wh1144 constd4735e3a265e16eee03f5971) (let _00024sqc5YMJ145 const5feceb66ffc86f38d952786c) (let _00024sqc3B2s146 const4e07408562bedb8b60ce05c1) (let _00024sqc2InF147 const6b86b273ff34fce19d6b804e) (let _00024sqc5FD5148 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Fjd150 const4e07408562bedb8b60ce05c1) (let _00024sqo9F2d149 const5feceb66ffc86f38d952786c) (let _00024sqo9ZUl152 const4b227777d4dd1fc61c6f884f) (let _00024sqo9bFX151 const6b86b273ff34fce19d6b804e) (let _00024sqo4sZr154 const4e07408562bedb8b60ce05c1) (let _00024sqo6gFL153 const6b86b273ff34fce19d6b804e) (let _00024sqo1YfQ156 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Zm7155 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo5vAI139 _00024sqo4inq138 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo5Ucn135 _00024sqo7swt134 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo37bp137 _00024sqo53GR136 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8Uyz141 _00024sqo0DeM140 _00024seq0) (exists $seq_at (0 1 2) 2 _00024sqo9ZUl152 _00024sqo9bFX151) (exists $seq_atr (0 1 2) 2 _00024sqo4sZr154 _00024sqo6gFL153) (exists $seq_atr (0 1 2) 2 _00024sqo1YfQ156 _00024sqo5Zm7155) (exists lst_append (1 2 0) 1 _00024seq0) (join-old $seq_at (0 1 2) 2 (0 1 2) _00024sqo5Fjd150 _00024sqo9F2d149 _00024seq1) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo9ZUl152 _00024sqo9bFX151 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sZr154 _00024sqo6gFL153 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1YfQ156 _00024sqo5Zm7155 _00024seq1) (join lst_append (1 2 0) 2 _00024seq0 _00024seq1 __t0k0o29) (join lst_append_ans (0 1) 1 __t0k0o29 r) (letp _00024sql2Drd127 (aslst _00024seq0)) (let chk72Nj470 (llen _00024sql2Drd127)) (eq _00024sqc392E129 chk72Nj470) (letp chk14HG471 (lref _00024sql2Drd127 _00024sqc1yNa130)) (eq _00024sqc3BRp131 chk14HG471) (letp chk4Bgo472 (lref _00024sql2Drd127 _00024sqc5ygu132)) (eq _00024sqc5PHP133 chk4Bgo472) (letp _00024sql9o7V142 (aslst _00024seq1)) (let chk8kNS473 (llen _00024sql9o7V142)) (eq _00024sqc5wh1144 chk8kNS473) (letp chk88ri474 (lref _00024sql9o7V142 _00024sqc5YMJ145)) (eq _00024sqc3B2s146 chk88ri474) (letp chk8BD6475 (lref _00024sql9o7V142 _00024sqc2InF147)) (eq _00024sqc5FD5148 chk8BD6475)) (head (emit appended (0) r)) lst_ops.slog:12 #f)
  class ReadTask1084 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1066;  slog::Index** $seq_atindex1067;  slog::Index** $seq_atrindex1068;  slog::Index** $seq_atindex1069;  slog::Index** $seq_atrindex1070;  slog::Index** $seq_atrindex1071;  slog::Index** lst_appendindex1072;  slog::Index** $seq_atindex1073;  slog::Index** $seq_atindex1074;  slog::Index** $seq_atrindex1075;  slog::Index** $seq_atrindex1076;  slog::Index** lst_appendindex1077;  slog::Index** lst_append_ansindex1078;  slog::Index** $seq_atrdelta1079;  slog::Index** $seq_atdelta1080;  slog::Index** $seq_atdelta1081;  slog::Index** $seq_atrdelta1082;  slog::Index** $seq_atrdelta1083;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("appended");
      std::vector<u16> ord1085({0});
      slog::Relation* readrel1086 = db->getRelation("appended");
      head_index[0] = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({0, 1, 2});
      slog::Relation* readrel1088 = db->getRelation("$seq_atr");
      driver_index = readrel1088->getIndex(ord1087, true);
      std::vector<u16> ord1089({0, 1, 2});
      slog::Relation* readrel1090 = db->getRelation("$seq_at");
      $seq_atindex1066 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({0, 1, 2});
      slog::Relation* readrel1092 = db->getRelation("$seq_at");
      $seq_atindex1067 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({0, 1, 2});
      slog::Relation* readrel1094 = db->getRelation("$seq_atr");
      $seq_atrindex1068 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({0, 1, 2});
      slog::Relation* readrel1096 = db->getRelation("$seq_atr");
      $seq_atrdelta1079 = readrel1096->getIndex(ord1095, true);
      std::vector<u16> ord1097({0, 1, 2});
      slog::Relation* readrel1098 = db->getRelation("$seq_at");
      $seq_atindex1069 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({0, 1, 2});
      slog::Relation* readrel1100 = db->getRelation("$seq_atr");
      $seq_atrindex1070 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({0, 1, 2});
      slog::Relation* readrel1102 = db->getRelation("$seq_atr");
      $seq_atrindex1071 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({1, 2, 0});
      slog::Relation* readrel1104 = db->getRelation("lst_append");
      lst_appendindex1072 = readrel1104->getIndex(ord1103, false);
      std::vector<u16> ord1105({0, 1, 2});
      slog::Relation* readrel1106 = db->getRelation("$seq_at");
      $seq_atindex1073 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({0, 1, 2});
      slog::Relation* readrel1108 = db->getRelation("$seq_at");
      $seq_atdelta1080 = readrel1108->getIndex(ord1107, true);
      std::vector<u16> ord1109({0, 1, 2});
      slog::Relation* readrel1110 = db->getRelation("$seq_at");
      $seq_atindex1074 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({0, 1, 2});
      slog::Relation* readrel1112 = db->getRelation("$seq_at");
      $seq_atdelta1081 = readrel1112->getIndex(ord1111, true);
      std::vector<u16> ord1113({0, 1, 2});
      slog::Relation* readrel1114 = db->getRelation("$seq_atr");
      $seq_atrindex1075 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({0, 1, 2});
      slog::Relation* readrel1116 = db->getRelation("$seq_atr");
      $seq_atrdelta1082 = readrel1116->getIndex(ord1115, true);
      std::vector<u16> ord1117({0, 1, 2});
      slog::Relation* readrel1118 = db->getRelation("$seq_atr");
      $seq_atrindex1076 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({0, 1, 2});
      slog::Relation* readrel1120 = db->getRelation("$seq_atr");
      $seq_atrdelta1083 = readrel1120->getIndex(ord1119, true);
      std::vector<u16> ord1121({1, 2, 0});
      slog::Relation* readrel1122 = db->getRelation("lst_append");
      lst_appendindex1077 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({0, 1});
      slog::Relation* readrel1124 = db->getRelation("lst_append_ans");
      lst_append_ansindex1078 = readrel1124->getIndex(ord1123, false);
  
    }
    ReadTask1084(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_constd4735e3a265e16eee03f5971;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_constd4735e3a265e16eee03f5971;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
      u64 v_c133 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c136 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c127, v_c128, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1125) {
        u64 v_c19 = m1125[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1066, std::array<u64,3>{v_c123, v_c124, v_c19}, [&](const std::array<u64,3>& m1126) {
          slog::join_probe<3,3>($seq_atindex1067, std::array<u64,3>{v_c125, v_c126, v_c19}, [&](const std::array<u64,3>& m1127) {
            slog::join_probe_old<3,3>($seq_atrindex1068, $seq_atrdelta1079, std::array<u64,3>{v_c129, v_c130, v_c19}, [&](const std::array<u64,3>& m1128) {
              if (!slog::exists_probe<3,2>($seq_atindex1069, std::array<u64,3>{v_c138, v_c139, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex1070, std::array<u64,3>{v_c140, v_c141, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex1071, std::array<u64,3>{v_c142, v_c143, 0})) return;
              if (!slog::exists_probe<3,1>(lst_appendindex1072, std::array<u64,3>{v_c19, 0, 0})) return;
              slog::join_probe_old<3,2>($seq_atindex1073, $seq_atdelta1080, std::array<u64,3>{v_c136, v_c137, 0}, [&](const std::array<u64,3>& m1129) {
                u64 v_c144 = m1129[2];
                slog::join_probe_old<3,3>($seq_atindex1074, $seq_atdelta1081, std::array<u64,3>{v_c138, v_c139, v_c144}, [&](const std::array<u64,3>& m1130) {
                  slog::join_probe_old<3,3>($seq_atrindex1075, $seq_atrdelta1082, std::array<u64,3>{v_c140, v_c141, v_c144}, [&](const std::array<u64,3>& m1131) {
                    slog::join_probe_old<3,3>($seq_atrindex1076, $seq_atrdelta1083, std::array<u64,3>{v_c142, v_c143, v_c144}, [&](const std::array<u64,3>& m1132) {
                      slog::join_probe<3,2>(lst_appendindex1077, std::array<u64,3>{v_c19, v_c144, 0}, [&](const std::array<u64,3>& m1133) {
                        u64 v_c145 = m1133[2];
                        slog::join_probe<2,1>(lst_append_ansindex1078, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m1134) {
                          u64 v_c21 = m1134[1];
                          bool ok1135 = true;
                          u64 v_c146 = _prim_aslst(db, v_c19, &ok1135);
                          if (!ok1135) return;
                          u64 v_c178 = _prim_llen(db, v_c146);
                          if (v_c178 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c118 != v_c178) return;
                          bool ok1136 = true;
                          u64 v_c179 = _prim_lref(db, v_c146, v_c119, &ok1136);
                          if (!ok1136) return;
                          if (v_c120 != v_c179) return;
                          bool ok1137 = true;
                          u64 v_c180 = _prim_lref(db, v_c146, v_c121, &ok1137);
                          if (!ok1137) return;
                          if (v_c122 != v_c180) return;
                          bool ok1138 = true;
                          u64 v_c150 = _prim_aslst(db, v_c144, &ok1138);
                          if (!ok1138) return;
                          u64 v_c181 = _prim_llen(db, v_c150);
                          if (v_c181 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c131 != v_c181) return;
                          bool ok1139 = true;
                          u64 v_c182 = _prim_lref(db, v_c150, v_c132, &ok1139);
                          if (!ok1139) return;
                          if (v_c133 != v_c182) return;
                          bool ok1140 = true;
                          u64 v_c183 = _prim_lref(db, v_c150, v_c134, &ok1140);
                          if (!ok1140) return;
                          if (v_c135 != v_c183) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:12", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1084* _cont = new ReadTask1084(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1084(db,b), false);
  // (crule (pre (let _00024sqc392E129 constd4735e3a265e16eee03f5971) (let _00024sqc1yNa130 const5feceb66ffc86f38d952786c) (let _00024sqc3BRp131 const6b86b273ff34fce19d6b804e) (let _00024sqc5ygu132 const6b86b273ff34fce19d6b804e) (let _00024sqc5PHP133 constd4735e3a265e16eee03f5971) (let _00024sqo5Ucn135 const6b86b273ff34fce19d6b804e) (let _00024sqo7swt134 const5feceb66ffc86f38d952786c) (let _00024sqo37bp137 constd4735e3a265e16eee03f5971) (let _00024sqo53GR136 const6b86b273ff34fce19d6b804e) (let _00024sqo5vAI139 const6b86b273ff34fce19d6b804e) (let _00024sqo4inq138 const6b86b273ff34fce19d6b804e) (let _00024sqo8Uyz141 constd4735e3a265e16eee03f5971) (let _00024sqo0DeM140 const5feceb66ffc86f38d952786c) (let _00024sqc5wh1144 constd4735e3a265e16eee03f5971) (let _00024sqc5YMJ145 const5feceb66ffc86f38d952786c) (let _00024sqc3B2s146 const4e07408562bedb8b60ce05c1) (let _00024sqc2InF147 const6b86b273ff34fce19d6b804e) (let _00024sqc5FD5148 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Fjd150 const4e07408562bedb8b60ce05c1) (let _00024sqo9F2d149 const5feceb66ffc86f38d952786c) (let _00024sqo9ZUl152 const4b227777d4dd1fc61c6f884f) (let _00024sqo9bFX151 const6b86b273ff34fce19d6b804e) (let _00024sqo4sZr154 const4e07408562bedb8b60ce05c1) (let _00024sqo6gFL153 const6b86b273ff34fce19d6b804e) (let _00024sqo1YfQ156 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Zm7155 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo37bp137 _00024sqo53GR136 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo5Ucn135 _00024sqo7swt134 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5vAI139 _00024sqo4inq138 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8Uyz141 _00024sqo0DeM140 _00024seq0) (exists $seq_at (0 1 2) 2 _00024sqo9ZUl152 _00024sqo9bFX151) (exists $seq_atr (0 1 2) 2 _00024sqo4sZr154 _00024sqo6gFL153) (exists $seq_atr (0 1 2) 2 _00024sqo1YfQ156 _00024sqo5Zm7155) (exists lst_append (1 2 0) 1 _00024seq0) (join-old $seq_at (0 1 2) 2 (0 1 2) _00024sqo5Fjd150 _00024sqo9F2d149 _00024seq1) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo9ZUl152 _00024sqo9bFX151 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sZr154 _00024sqo6gFL153 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1YfQ156 _00024sqo5Zm7155 _00024seq1) (join lst_append (1 2 0) 2 _00024seq0 _00024seq1 __t0k0o29) (join lst_append_ans (0 1) 1 __t0k0o29 r) (letp _00024sql2Drd127 (aslst _00024seq0)) (let chk0HxE464 (llen _00024sql2Drd127)) (eq _00024sqc392E129 chk0HxE464) (letp chk2uVf465 (lref _00024sql2Drd127 _00024sqc1yNa130)) (eq _00024sqc3BRp131 chk2uVf465) (letp chk0zL4466 (lref _00024sql2Drd127 _00024sqc5ygu132)) (eq _00024sqc5PHP133 chk0zL4466) (letp _00024sql9o7V142 (aslst _00024seq1)) (let chk29HU467 (llen _00024sql9o7V142)) (eq _00024sqc5wh1144 chk29HU467) (letp chk19z3468 (lref _00024sql9o7V142 _00024sqc5YMJ145)) (eq _00024sqc3B2s146 chk19z3468) (letp chk4zMJ469 (lref _00024sql9o7V142 _00024sqc2InF147)) (eq _00024sqc5FD5148 chk4zMJ469)) (head (emit appended (0) r)) lst_ops.slog:12 #f)
  class ReadTask1160 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1141;  slog::Index** $seq_atrindex1142;  slog::Index** $seq_atrindex1143;  slog::Index** $seq_atindex1144;  slog::Index** $seq_atrindex1145;  slog::Index** $seq_atrindex1146;  slog::Index** lst_appendindex1147;  slog::Index** $seq_atindex1148;  slog::Index** $seq_atindex1149;  slog::Index** $seq_atrindex1150;  slog::Index** $seq_atrindex1151;  slog::Index** lst_appendindex1152;  slog::Index** lst_append_ansindex1153;  slog::Index** $seq_atrdelta1154;  slog::Index** $seq_atrdelta1155;  slog::Index** $seq_atdelta1156;  slog::Index** $seq_atdelta1157;  slog::Index** $seq_atrdelta1158;  slog::Index** $seq_atrdelta1159;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("appended");
      std::vector<u16> ord1161({0});
      slog::Relation* readrel1162 = db->getRelation("appended");
      head_index[0] = readrel1162->getIndex(ord1161, false);
      std::vector<u16> ord1163({0, 1, 2});
      slog::Relation* readrel1164 = db->getRelation("$seq_at");
      driver_index = readrel1164->getIndex(ord1163, true);
      std::vector<u16> ord1165({0, 1, 2});
      slog::Relation* readrel1166 = db->getRelation("$seq_at");
      $seq_atindex1141 = readrel1166->getIndex(ord1165, false);
      std::vector<u16> ord1167({0, 1, 2});
      slog::Relation* readrel1168 = db->getRelation("$seq_atr");
      $seq_atrindex1142 = readrel1168->getIndex(ord1167, false);
      std::vector<u16> ord1169({0, 1, 2});
      slog::Relation* readrel1170 = db->getRelation("$seq_atr");
      $seq_atrdelta1154 = readrel1170->getIndex(ord1169, true);
      std::vector<u16> ord1171({0, 1, 2});
      slog::Relation* readrel1172 = db->getRelation("$seq_atr");
      $seq_atrindex1143 = readrel1172->getIndex(ord1171, false);
      std::vector<u16> ord1173({0, 1, 2});
      slog::Relation* readrel1174 = db->getRelation("$seq_atr");
      $seq_atrdelta1155 = readrel1174->getIndex(ord1173, true);
      std::vector<u16> ord1175({0, 1, 2});
      slog::Relation* readrel1176 = db->getRelation("$seq_at");
      $seq_atindex1144 = readrel1176->getIndex(ord1175, false);
      std::vector<u16> ord1177({0, 1, 2});
      slog::Relation* readrel1178 = db->getRelation("$seq_atr");
      $seq_atrindex1145 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({0, 1, 2});
      slog::Relation* readrel1180 = db->getRelation("$seq_atr");
      $seq_atrindex1146 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({1, 2, 0});
      slog::Relation* readrel1182 = db->getRelation("lst_append");
      lst_appendindex1147 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({0, 1, 2});
      slog::Relation* readrel1184 = db->getRelation("$seq_at");
      $seq_atindex1148 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({0, 1, 2});
      slog::Relation* readrel1186 = db->getRelation("$seq_at");
      $seq_atdelta1156 = readrel1186->getIndex(ord1185, true);
      std::vector<u16> ord1187({0, 1, 2});
      slog::Relation* readrel1188 = db->getRelation("$seq_at");
      $seq_atindex1149 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({0, 1, 2});
      slog::Relation* readrel1190 = db->getRelation("$seq_at");
      $seq_atdelta1157 = readrel1190->getIndex(ord1189, true);
      std::vector<u16> ord1191({0, 1, 2});
      slog::Relation* readrel1192 = db->getRelation("$seq_atr");
      $seq_atrindex1150 = readrel1192->getIndex(ord1191, false);
      std::vector<u16> ord1193({0, 1, 2});
      slog::Relation* readrel1194 = db->getRelation("$seq_atr");
      $seq_atrdelta1158 = readrel1194->getIndex(ord1193, true);
      std::vector<u16> ord1195({0, 1, 2});
      slog::Relation* readrel1196 = db->getRelation("$seq_atr");
      $seq_atrindex1151 = readrel1196->getIndex(ord1195, false);
      std::vector<u16> ord1197({0, 1, 2});
      slog::Relation* readrel1198 = db->getRelation("$seq_atr");
      $seq_atrdelta1159 = readrel1198->getIndex(ord1197, true);
      std::vector<u16> ord1199({1, 2, 0});
      slog::Relation* readrel1200 = db->getRelation("lst_append");
      lst_appendindex1152 = readrel1200->getIndex(ord1199, false);
      std::vector<u16> ord1201({0, 1});
      slog::Relation* readrel1202 = db->getRelation("lst_append_ans");
      lst_append_ansindex1153 = readrel1202->getIndex(ord1201, false);
  
    }
    ReadTask1160(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_constd4735e3a265e16eee03f5971;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_constd4735e3a265e16eee03f5971;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
      u64 v_c133 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c136 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c125, v_c126, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1203) {
        u64 v_c19 = m1203[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1141, std::array<u64,3>{v_c123, v_c124, v_c19}, [&](const std::array<u64,3>& m1204) {
          slog::join_probe_old<3,3>($seq_atrindex1142, $seq_atrdelta1154, std::array<u64,3>{v_c127, v_c128, v_c19}, [&](const std::array<u64,3>& m1205) {
            slog::join_probe_old<3,3>($seq_atrindex1143, $seq_atrdelta1155, std::array<u64,3>{v_c129, v_c130, v_c19}, [&](const std::array<u64,3>& m1206) {
              if (!slog::exists_probe<3,2>($seq_atindex1144, std::array<u64,3>{v_c138, v_c139, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex1145, std::array<u64,3>{v_c140, v_c141, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex1146, std::array<u64,3>{v_c142, v_c143, 0})) return;
              if (!slog::exists_probe<3,1>(lst_appendindex1147, std::array<u64,3>{v_c19, 0, 0})) return;
              slog::join_probe_old<3,2>($seq_atindex1148, $seq_atdelta1156, std::array<u64,3>{v_c136, v_c137, 0}, [&](const std::array<u64,3>& m1207) {
                u64 v_c144 = m1207[2];
                slog::join_probe_old<3,3>($seq_atindex1149, $seq_atdelta1157, std::array<u64,3>{v_c138, v_c139, v_c144}, [&](const std::array<u64,3>& m1208) {
                  slog::join_probe_old<3,3>($seq_atrindex1150, $seq_atrdelta1158, std::array<u64,3>{v_c140, v_c141, v_c144}, [&](const std::array<u64,3>& m1209) {
                    slog::join_probe_old<3,3>($seq_atrindex1151, $seq_atrdelta1159, std::array<u64,3>{v_c142, v_c143, v_c144}, [&](const std::array<u64,3>& m1210) {
                      slog::join_probe<3,2>(lst_appendindex1152, std::array<u64,3>{v_c19, v_c144, 0}, [&](const std::array<u64,3>& m1211) {
                        u64 v_c145 = m1211[2];
                        slog::join_probe<2,1>(lst_append_ansindex1153, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m1212) {
                          u64 v_c21 = m1212[1];
                          bool ok1213 = true;
                          u64 v_c146 = _prim_aslst(db, v_c19, &ok1213);
                          if (!ok1213) return;
                          u64 v_c184 = _prim_llen(db, v_c146);
                          if (v_c184 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c118 != v_c184) return;
                          bool ok1214 = true;
                          u64 v_c185 = _prim_lref(db, v_c146, v_c119, &ok1214);
                          if (!ok1214) return;
                          if (v_c120 != v_c185) return;
                          bool ok1215 = true;
                          u64 v_c186 = _prim_lref(db, v_c146, v_c121, &ok1215);
                          if (!ok1215) return;
                          if (v_c122 != v_c186) return;
                          bool ok1216 = true;
                          u64 v_c150 = _prim_aslst(db, v_c144, &ok1216);
                          if (!ok1216) return;
                          u64 v_c187 = _prim_llen(db, v_c150);
                          if (v_c187 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c131 != v_c187) return;
                          bool ok1217 = true;
                          u64 v_c188 = _prim_lref(db, v_c150, v_c132, &ok1217);
                          if (!ok1217) return;
                          if (v_c133 != v_c188) return;
                          bool ok1218 = true;
                          u64 v_c189 = _prim_lref(db, v_c150, v_c134, &ok1218);
                          if (!ok1218) return;
                          if (v_c135 != v_c189) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:12", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1160* _cont = new ReadTask1160(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1160(db,b), false);
  // (crule (pre (let _00024sqc392E129 constd4735e3a265e16eee03f5971) (let _00024sqc1yNa130 const5feceb66ffc86f38d952786c) (let _00024sqc3BRp131 const6b86b273ff34fce19d6b804e) (let _00024sqc5ygu132 const6b86b273ff34fce19d6b804e) (let _00024sqc5PHP133 constd4735e3a265e16eee03f5971) (let _00024sqo5Ucn135 const6b86b273ff34fce19d6b804e) (let _00024sqo7swt134 const5feceb66ffc86f38d952786c) (let _00024sqo37bp137 constd4735e3a265e16eee03f5971) (let _00024sqo53GR136 const6b86b273ff34fce19d6b804e) (let _00024sqo5vAI139 const6b86b273ff34fce19d6b804e) (let _00024sqo4inq138 const6b86b273ff34fce19d6b804e) (let _00024sqo8Uyz141 constd4735e3a265e16eee03f5971) (let _00024sqo0DeM140 const5feceb66ffc86f38d952786c) (let _00024sqc5wh1144 constd4735e3a265e16eee03f5971) (let _00024sqc5YMJ145 const5feceb66ffc86f38d952786c) (let _00024sqc3B2s146 const4e07408562bedb8b60ce05c1) (let _00024sqc2InF147 const6b86b273ff34fce19d6b804e) (let _00024sqc5FD5148 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Fjd150 const4e07408562bedb8b60ce05c1) (let _00024sqo9F2d149 const5feceb66ffc86f38d952786c) (let _00024sqo9ZUl152 const4b227777d4dd1fc61c6f884f) (let _00024sqo9bFX151 const6b86b273ff34fce19d6b804e) (let _00024sqo4sZr154 const4e07408562bedb8b60ce05c1) (let _00024sqo6gFL153 const6b86b273ff34fce19d6b804e) (let _00024sqo1YfQ156 const4b227777d4dd1fc61c6f884f) (let _00024sqo5Zm7155 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo5Ucn135 _00024sqo7swt134 _00024seq0) (body (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo37bp137 _00024sqo53GR136 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5vAI139 _00024sqo4inq138 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8Uyz141 _00024sqo0DeM140 _00024seq0) (exists $seq_at (0 1 2) 2 _00024sqo9ZUl152 _00024sqo9bFX151) (exists $seq_atr (0 1 2) 2 _00024sqo4sZr154 _00024sqo6gFL153) (exists $seq_atr (0 1 2) 2 _00024sqo1YfQ156 _00024sqo5Zm7155) (exists lst_append (1 2 0) 1 _00024seq0) (join-old $seq_at (0 1 2) 2 (0 1 2) _00024sqo5Fjd150 _00024sqo9F2d149 _00024seq1) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo9ZUl152 _00024sqo9bFX151 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sZr154 _00024sqo6gFL153 _00024seq1) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1YfQ156 _00024sqo5Zm7155 _00024seq1) (join lst_append (1 2 0) 2 _00024seq0 _00024seq1 __t0k0o29) (join lst_append_ans (0 1) 1 __t0k0o29 r) (letp _00024sql2Drd127 (aslst _00024seq0)) (let chk3YKm458 (llen _00024sql2Drd127)) (eq _00024sqc392E129 chk3YKm458) (letp chk75vy459 (lref _00024sql2Drd127 _00024sqc1yNa130)) (eq _00024sqc3BRp131 chk75vy459) (letp chk5g3I460 (lref _00024sql2Drd127 _00024sqc5ygu132)) (eq _00024sqc5PHP133 chk5g3I460) (letp _00024sql9o7V142 (aslst _00024seq1)) (let chk8N61461 (llen _00024sql9o7V142)) (eq _00024sqc5wh1144 chk8N61461) (letp chk1RcO462 (lref _00024sql9o7V142 _00024sqc5YMJ145)) (eq _00024sqc3B2s146 chk1RcO462) (letp chk6lPi463 (lref _00024sql9o7V142 _00024sqc2InF147)) (eq _00024sqc5FD5148 chk6lPi463)) (head (emit appended (0) r)) lst_ops.slog:12 #f)
  class ReadTask1239 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1219;  slog::Index** $seq_atrindex1220;  slog::Index** $seq_atrindex1221;  slog::Index** $seq_atindex1222;  slog::Index** $seq_atrindex1223;  slog::Index** $seq_atrindex1224;  slog::Index** lst_appendindex1225;  slog::Index** $seq_atindex1226;  slog::Index** $seq_atindex1227;  slog::Index** $seq_atrindex1228;  slog::Index** $seq_atrindex1229;  slog::Index** lst_appendindex1230;  slog::Index** lst_append_ansindex1231;  slog::Index** $seq_atdelta1232;  slog::Index** $seq_atrdelta1233;  slog::Index** $seq_atrdelta1234;  slog::Index** $seq_atdelta1235;  slog::Index** $seq_atdelta1236;  slog::Index** $seq_atrdelta1237;  slog::Index** $seq_atrdelta1238;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("appended");
      std::vector<u16> ord1240({0});
      slog::Relation* readrel1241 = db->getRelation("appended");
      head_index[0] = readrel1241->getIndex(ord1240, false);
      std::vector<u16> ord1242({0, 1, 2});
      slog::Relation* readrel1243 = db->getRelation("$seq_at");
      driver_index = readrel1243->getIndex(ord1242, true);
      std::vector<u16> ord1244({0, 1, 2});
      slog::Relation* readrel1245 = db->getRelation("$seq_at");
      $seq_atindex1219 = readrel1245->getIndex(ord1244, false);
      std::vector<u16> ord1246({0, 1, 2});
      slog::Relation* readrel1247 = db->getRelation("$seq_at");
      $seq_atdelta1232 = readrel1247->getIndex(ord1246, true);
      std::vector<u16> ord1248({0, 1, 2});
      slog::Relation* readrel1249 = db->getRelation("$seq_atr");
      $seq_atrindex1220 = readrel1249->getIndex(ord1248, false);
      std::vector<u16> ord1250({0, 1, 2});
      slog::Relation* readrel1251 = db->getRelation("$seq_atr");
      $seq_atrdelta1233 = readrel1251->getIndex(ord1250, true);
      std::vector<u16> ord1252({0, 1, 2});
      slog::Relation* readrel1253 = db->getRelation("$seq_atr");
      $seq_atrindex1221 = readrel1253->getIndex(ord1252, false);
      std::vector<u16> ord1254({0, 1, 2});
      slog::Relation* readrel1255 = db->getRelation("$seq_atr");
      $seq_atrdelta1234 = readrel1255->getIndex(ord1254, true);
      std::vector<u16> ord1256({0, 1, 2});
      slog::Relation* readrel1257 = db->getRelation("$seq_at");
      $seq_atindex1222 = readrel1257->getIndex(ord1256, false);
      std::vector<u16> ord1258({0, 1, 2});
      slog::Relation* readrel1259 = db->getRelation("$seq_atr");
      $seq_atrindex1223 = readrel1259->getIndex(ord1258, false);
      std::vector<u16> ord1260({0, 1, 2});
      slog::Relation* readrel1261 = db->getRelation("$seq_atr");
      $seq_atrindex1224 = readrel1261->getIndex(ord1260, false);
      std::vector<u16> ord1262({1, 2, 0});
      slog::Relation* readrel1263 = db->getRelation("lst_append");
      lst_appendindex1225 = readrel1263->getIndex(ord1262, false);
      std::vector<u16> ord1264({0, 1, 2});
      slog::Relation* readrel1265 = db->getRelation("$seq_at");
      $seq_atindex1226 = readrel1265->getIndex(ord1264, false);
      std::vector<u16> ord1266({0, 1, 2});
      slog::Relation* readrel1267 = db->getRelation("$seq_at");
      $seq_atdelta1235 = readrel1267->getIndex(ord1266, true);
      std::vector<u16> ord1268({0, 1, 2});
      slog::Relation* readrel1269 = db->getRelation("$seq_at");
      $seq_atindex1227 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({0, 1, 2});
      slog::Relation* readrel1271 = db->getRelation("$seq_at");
      $seq_atdelta1236 = readrel1271->getIndex(ord1270, true);
      std::vector<u16> ord1272({0, 1, 2});
      slog::Relation* readrel1273 = db->getRelation("$seq_atr");
      $seq_atrindex1228 = readrel1273->getIndex(ord1272, false);
      std::vector<u16> ord1274({0, 1, 2});
      slog::Relation* readrel1275 = db->getRelation("$seq_atr");
      $seq_atrdelta1237 = readrel1275->getIndex(ord1274, true);
      std::vector<u16> ord1276({0, 1, 2});
      slog::Relation* readrel1277 = db->getRelation("$seq_atr");
      $seq_atrindex1229 = readrel1277->getIndex(ord1276, false);
      std::vector<u16> ord1278({0, 1, 2});
      slog::Relation* readrel1279 = db->getRelation("$seq_atr");
      $seq_atrdelta1238 = readrel1279->getIndex(ord1278, true);
      std::vector<u16> ord1280({1, 2, 0});
      slog::Relation* readrel1281 = db->getRelation("lst_append");
      lst_appendindex1230 = readrel1281->getIndex(ord1280, false);
      std::vector<u16> ord1282({0, 1});
      slog::Relation* readrel1283 = db->getRelation("lst_append_ans");
      lst_append_ansindex1231 = readrel1283->getIndex(ord1282, false);
  
    }
    ReadTask1239(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_const5feceb66ffc86f38d952786c;
      u64 v_c120 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_constd4735e3a265e16eee03f5971;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_constd4735e3a265e16eee03f5971;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
      u64 v_c133 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c136 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c141 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c142 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c123, v_c124, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1284) {
        u64 v_c19 = m1284[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex1219, $seq_atdelta1232, std::array<u64,3>{v_c125, v_c126, v_c19}, [&](const std::array<u64,3>& m1285) {
          slog::join_probe_old<3,3>($seq_atrindex1220, $seq_atrdelta1233, std::array<u64,3>{v_c127, v_c128, v_c19}, [&](const std::array<u64,3>& m1286) {
            slog::join_probe_old<3,3>($seq_atrindex1221, $seq_atrdelta1234, std::array<u64,3>{v_c129, v_c130, v_c19}, [&](const std::array<u64,3>& m1287) {
              if (!slog::exists_probe<3,2>($seq_atindex1222, std::array<u64,3>{v_c138, v_c139, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex1223, std::array<u64,3>{v_c140, v_c141, 0})) return;
              if (!slog::exists_probe<3,2>($seq_atrindex1224, std::array<u64,3>{v_c142, v_c143, 0})) return;
              if (!slog::exists_probe<3,1>(lst_appendindex1225, std::array<u64,3>{v_c19, 0, 0})) return;
              slog::join_probe_old<3,2>($seq_atindex1226, $seq_atdelta1235, std::array<u64,3>{v_c136, v_c137, 0}, [&](const std::array<u64,3>& m1288) {
                u64 v_c144 = m1288[2];
                slog::join_probe_old<3,3>($seq_atindex1227, $seq_atdelta1236, std::array<u64,3>{v_c138, v_c139, v_c144}, [&](const std::array<u64,3>& m1289) {
                  slog::join_probe_old<3,3>($seq_atrindex1228, $seq_atrdelta1237, std::array<u64,3>{v_c140, v_c141, v_c144}, [&](const std::array<u64,3>& m1290) {
                    slog::join_probe_old<3,3>($seq_atrindex1229, $seq_atrdelta1238, std::array<u64,3>{v_c142, v_c143, v_c144}, [&](const std::array<u64,3>& m1291) {
                      slog::join_probe<3,2>(lst_appendindex1230, std::array<u64,3>{v_c19, v_c144, 0}, [&](const std::array<u64,3>& m1292) {
                        u64 v_c145 = m1292[2];
                        slog::join_probe<2,1>(lst_append_ansindex1231, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m1293) {
                          u64 v_c21 = m1293[1];
                          bool ok1294 = true;
                          u64 v_c146 = _prim_aslst(db, v_c19, &ok1294);
                          if (!ok1294) return;
                          u64 v_c190 = _prim_llen(db, v_c146);
                          if (v_c190 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c118 != v_c190) return;
                          bool ok1295 = true;
                          u64 v_c191 = _prim_lref(db, v_c146, v_c119, &ok1295);
                          if (!ok1295) return;
                          if (v_c120 != v_c191) return;
                          bool ok1296 = true;
                          u64 v_c192 = _prim_lref(db, v_c146, v_c121, &ok1296);
                          if (!ok1296) return;
                          if (v_c122 != v_c192) return;
                          bool ok1297 = true;
                          u64 v_c150 = _prim_aslst(db, v_c144, &ok1297);
                          if (!ok1297) return;
                          u64 v_c193 = _prim_llen(db, v_c150);
                          if (v_c193 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:12"); return; }
                          if (v_c131 != v_c193) return;
                          bool ok1298 = true;
                          u64 v_c194 = _prim_lref(db, v_c150, v_c132, &ok1298);
                          if (!ok1298) return;
                          if (v_c133 != v_c194) return;
                          bool ok1299 = true;
                          u64 v_c195 = _prim_lref(db, v_c150, v_c134, &ok1299);
                          if (!ok1299) return;
                          if (v_c135 != v_c195) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:12", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1239* _cont = new ReadTask1239(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1239(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo56lA50 _00024sqo393o49 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo6djO58 _00024sqo09C757 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk2Rhy584 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk2Rhy584) (letp chk7UKa585 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk7UKa585) (letp chk9iEa586 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk9iEa586) (letp chk3imt587 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk3imt587) (letp chk6er6588 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk6er6588) (letp chk2muj589 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk2muj589)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1311 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1300;  slog::Index** $seq_atindex1301;  slog::Index** $seq_atindex1302;  slog::Index** $seq_atindex1303;  slog::Index** $seq_atindex1304;  slog::Index** $seq_atrindex1305;  slog::Index** $seq_atrindex1306;  slog::Index** $seq_atrindex1307;  slog::Index** $seq_atrindex1308;  slog::Index** lst_lenindex1309;  slog::Index** lst_len_ansindex1310;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1312({0});
      slog::Relation* readrel1313 = db->getRelation("n");
      head_index[0] = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({0, 1, 2});
      slog::Relation* readrel1315 = db->getRelation("$seq_atr");
      driver_index = readrel1315->getIndex(ord1314, true);
      std::vector<u16> ord1316({0, 1, 2});
      slog::Relation* readrel1317 = db->getRelation("$seq_at");
      $seq_atindex1300 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({0, 1, 2});
      slog::Relation* readrel1319 = db->getRelation("$seq_at");
      $seq_atindex1301 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({0, 1, 2});
      slog::Relation* readrel1321 = db->getRelation("$seq_at");
      $seq_atindex1302 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({0, 1, 2});
      slog::Relation* readrel1323 = db->getRelation("$seq_at");
      $seq_atindex1303 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({0, 1, 2});
      slog::Relation* readrel1325 = db->getRelation("$seq_at");
      $seq_atindex1304 = readrel1325->getIndex(ord1324, false);
      std::vector<u16> ord1326({0, 1, 2});
      slog::Relation* readrel1327 = db->getRelation("$seq_atr");
      $seq_atrindex1305 = readrel1327->getIndex(ord1326, false);
      std::vector<u16> ord1328({0, 1, 2});
      slog::Relation* readrel1329 = db->getRelation("$seq_atr");
      $seq_atrindex1306 = readrel1329->getIndex(ord1328, false);
      std::vector<u16> ord1330({0, 1, 2});
      slog::Relation* readrel1331 = db->getRelation("$seq_atr");
      $seq_atrindex1307 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({0, 1, 2});
      slog::Relation* readrel1333 = db->getRelation("$seq_atr");
      $seq_atrindex1308 = readrel1333->getIndex(ord1332, false);
      std::vector<u16> ord1334({1, 0});
      slog::Relation* readrel1335 = db->getRelation("lst_len");
      lst_lenindex1309 = readrel1335->getIndex(ord1334, false);
      std::vector<u16> ord1336({0, 1});
      slog::Relation* readrel1337 = db->getRelation("lst_len_ans");
      lst_len_ansindex1310 = readrel1337->getIndex(ord1336, false);
  
    }
    ReadTask1311(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c225, v_c226, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1338) {
        u64 v_c19 = m1338[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1300, std::array<u64,3>{v_c207, v_c208, v_c19}, [&](const std::array<u64,3>& m1339) {
          slog::join_probe<3,3>($seq_atindex1301, std::array<u64,3>{v_c209, v_c210, v_c19}, [&](const std::array<u64,3>& m1340) {
            slog::join_probe<3,3>($seq_atindex1302, std::array<u64,3>{v_c211, v_c212, v_c19}, [&](const std::array<u64,3>& m1341) {
              slog::join_probe<3,3>($seq_atindex1303, std::array<u64,3>{v_c213, v_c214, v_c19}, [&](const std::array<u64,3>& m1342) {
                slog::join_probe<3,3>($seq_atindex1304, std::array<u64,3>{v_c215, v_c216, v_c19}, [&](const std::array<u64,3>& m1343) {
                  slog::join_probe<3,3>($seq_atrindex1305, std::array<u64,3>{v_c217, v_c218, v_c19}, [&](const std::array<u64,3>& m1344) {
                    slog::join_probe<3,3>($seq_atrindex1306, std::array<u64,3>{v_c219, v_c220, v_c19}, [&](const std::array<u64,3>& m1345) {
                      slog::join_probe<3,3>($seq_atrindex1307, std::array<u64,3>{v_c221, v_c222, v_c19}, [&](const std::array<u64,3>& m1346) {
                        slog::join_probe<3,3>($seq_atrindex1308, std::array<u64,3>{v_c223, v_c224, v_c19}, [&](const std::array<u64,3>& m1347) {
                          slog::join_probe<2,1>(lst_lenindex1309, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1348) {
                            u64 v_c227 = m1348[1];
                            slog::join_probe<2,1>(lst_len_ansindex1310, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1349) {
                              u64 v_c21 = m1349[1];
                              bool ok1350 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1350);
                              if (!ok1350) return;
                              u64 v_c229 = _prim_llen(db, v_c228);
                              if (v_c229 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c229) return;
                              bool ok1351 = true;
                              u64 v_c230 = _prim_lref(db, v_c228, v_c197, &ok1351);
                              if (!ok1351) return;
                              if (v_c198 != v_c230) return;
                              bool ok1352 = true;
                              u64 v_c231 = _prim_lref(db, v_c228, v_c199, &ok1352);
                              if (!ok1352) return;
                              if (v_c200 != v_c231) return;
                              bool ok1353 = true;
                              u64 v_c232 = _prim_lref(db, v_c228, v_c201, &ok1353);
                              if (!ok1353) return;
                              if (v_c202 != v_c232) return;
                              bool ok1354 = true;
                              u64 v_c233 = _prim_lref(db, v_c228, v_c203, &ok1354);
                              if (!ok1354) return;
                              if (v_c204 != v_c233) return;
                              bool ok1355 = true;
                              u64 v_c234 = _prim_lref(db, v_c228, v_c205, &ok1355);
                              if (!ok1355) return;
                              if (v_c206 != v_c234) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1311* _cont = new ReadTask1311(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1311(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo56lA50 _00024sqo393o49 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo6djO58 _00024sqo09C757 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk0oC3578 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk0oC3578) (letp chk2TMF579 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk2TMF579) (letp chk39mb580 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk39mb580) (letp chk3e3X581 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk3e3X581) (letp chk3ADD582 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk3ADD582) (letp chk5wYo583 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk5wYo583)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1368 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1356;  slog::Index** $seq_atindex1357;  slog::Index** $seq_atindex1358;  slog::Index** $seq_atindex1359;  slog::Index** $seq_atindex1360;  slog::Index** $seq_atrindex1361;  slog::Index** $seq_atrindex1362;  slog::Index** $seq_atrindex1363;  slog::Index** $seq_atrindex1364;  slog::Index** lst_lenindex1365;  slog::Index** lst_len_ansindex1366;  slog::Index** $seq_atrdelta1367;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1369({0});
      slog::Relation* readrel1370 = db->getRelation("n");
      head_index[0] = readrel1370->getIndex(ord1369, false);
      std::vector<u16> ord1371({0, 1, 2});
      slog::Relation* readrel1372 = db->getRelation("$seq_atr");
      driver_index = readrel1372->getIndex(ord1371, true);
      std::vector<u16> ord1373({0, 1, 2});
      slog::Relation* readrel1374 = db->getRelation("$seq_at");
      $seq_atindex1356 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({0, 1, 2});
      slog::Relation* readrel1376 = db->getRelation("$seq_at");
      $seq_atindex1357 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({0, 1, 2});
      slog::Relation* readrel1378 = db->getRelation("$seq_at");
      $seq_atindex1358 = readrel1378->getIndex(ord1377, false);
      std::vector<u16> ord1379({0, 1, 2});
      slog::Relation* readrel1380 = db->getRelation("$seq_at");
      $seq_atindex1359 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({0, 1, 2});
      slog::Relation* readrel1382 = db->getRelation("$seq_at");
      $seq_atindex1360 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({0, 1, 2});
      slog::Relation* readrel1384 = db->getRelation("$seq_atr");
      $seq_atrindex1361 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({0, 1, 2});
      slog::Relation* readrel1386 = db->getRelation("$seq_atr");
      $seq_atrindex1362 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({0, 1, 2});
      slog::Relation* readrel1388 = db->getRelation("$seq_atr");
      $seq_atrindex1363 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({0, 1, 2});
      slog::Relation* readrel1390 = db->getRelation("$seq_atr");
      $seq_atrindex1364 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({0, 1, 2});
      slog::Relation* readrel1392 = db->getRelation("$seq_atr");
      $seq_atrdelta1367 = readrel1392->getIndex(ord1391, true);
      std::vector<u16> ord1393({1, 0});
      slog::Relation* readrel1394 = db->getRelation("lst_len");
      lst_lenindex1365 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({0, 1});
      slog::Relation* readrel1396 = db->getRelation("lst_len_ans");
      lst_len_ansindex1366 = readrel1396->getIndex(ord1395, false);
  
    }
    ReadTask1368(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c223, v_c224, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1397) {
        u64 v_c19 = m1397[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1356, std::array<u64,3>{v_c207, v_c208, v_c19}, [&](const std::array<u64,3>& m1398) {
          slog::join_probe<3,3>($seq_atindex1357, std::array<u64,3>{v_c209, v_c210, v_c19}, [&](const std::array<u64,3>& m1399) {
            slog::join_probe<3,3>($seq_atindex1358, std::array<u64,3>{v_c211, v_c212, v_c19}, [&](const std::array<u64,3>& m1400) {
              slog::join_probe<3,3>($seq_atindex1359, std::array<u64,3>{v_c213, v_c214, v_c19}, [&](const std::array<u64,3>& m1401) {
                slog::join_probe<3,3>($seq_atindex1360, std::array<u64,3>{v_c215, v_c216, v_c19}, [&](const std::array<u64,3>& m1402) {
                  slog::join_probe<3,3>($seq_atrindex1361, std::array<u64,3>{v_c217, v_c218, v_c19}, [&](const std::array<u64,3>& m1403) {
                    slog::join_probe<3,3>($seq_atrindex1362, std::array<u64,3>{v_c219, v_c220, v_c19}, [&](const std::array<u64,3>& m1404) {
                      slog::join_probe<3,3>($seq_atrindex1363, std::array<u64,3>{v_c221, v_c222, v_c19}, [&](const std::array<u64,3>& m1405) {
                        slog::join_probe_old<3,3>($seq_atrindex1364, $seq_atrdelta1367, std::array<u64,3>{v_c225, v_c226, v_c19}, [&](const std::array<u64,3>& m1406) {
                          slog::join_probe<2,1>(lst_lenindex1365, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1407) {
                            u64 v_c227 = m1407[1];
                            slog::join_probe<2,1>(lst_len_ansindex1366, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1408) {
                              u64 v_c21 = m1408[1];
                              bool ok1409 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1409);
                              if (!ok1409) return;
                              u64 v_c235 = _prim_llen(db, v_c228);
                              if (v_c235 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c235) return;
                              bool ok1410 = true;
                              u64 v_c236 = _prim_lref(db, v_c228, v_c197, &ok1410);
                              if (!ok1410) return;
                              if (v_c198 != v_c236) return;
                              bool ok1411 = true;
                              u64 v_c237 = _prim_lref(db, v_c228, v_c199, &ok1411);
                              if (!ok1411) return;
                              if (v_c200 != v_c237) return;
                              bool ok1412 = true;
                              u64 v_c238 = _prim_lref(db, v_c228, v_c201, &ok1412);
                              if (!ok1412) return;
                              if (v_c202 != v_c238) return;
                              bool ok1413 = true;
                              u64 v_c239 = _prim_lref(db, v_c228, v_c203, &ok1413);
                              if (!ok1413) return;
                              if (v_c204 != v_c239) return;
                              bool ok1414 = true;
                              u64 v_c240 = _prim_lref(db, v_c228, v_c205, &ok1414);
                              if (!ok1414) return;
                              if (v_c206 != v_c240) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1368* _cont = new ReadTask1368(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1368(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo56lA50 _00024sqo393o49 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo6djO58 _00024sqo09C757 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk62ru572 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk62ru572) (letp chk5XZw573 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk5XZw573) (letp chk58c0574 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk58c0574) (letp chk5YmT575 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk5YmT575) (letp chk3Dz5576 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk3Dz5576) (letp chk67Qc577 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk67Qc577)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1428 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1415;  slog::Index** $seq_atindex1416;  slog::Index** $seq_atindex1417;  slog::Index** $seq_atindex1418;  slog::Index** $seq_atindex1419;  slog::Index** $seq_atrindex1420;  slog::Index** $seq_atrindex1421;  slog::Index** $seq_atrindex1422;  slog::Index** $seq_atrindex1423;  slog::Index** lst_lenindex1424;  slog::Index** lst_len_ansindex1425;  slog::Index** $seq_atrdelta1426;  slog::Index** $seq_atrdelta1427;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1429({0});
      slog::Relation* readrel1430 = db->getRelation("n");
      head_index[0] = readrel1430->getIndex(ord1429, false);
      std::vector<u16> ord1431({0, 1, 2});
      slog::Relation* readrel1432 = db->getRelation("$seq_atr");
      driver_index = readrel1432->getIndex(ord1431, true);
      std::vector<u16> ord1433({0, 1, 2});
      slog::Relation* readrel1434 = db->getRelation("$seq_at");
      $seq_atindex1415 = readrel1434->getIndex(ord1433, false);
      std::vector<u16> ord1435({0, 1, 2});
      slog::Relation* readrel1436 = db->getRelation("$seq_at");
      $seq_atindex1416 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({0, 1, 2});
      slog::Relation* readrel1438 = db->getRelation("$seq_at");
      $seq_atindex1417 = readrel1438->getIndex(ord1437, false);
      std::vector<u16> ord1439({0, 1, 2});
      slog::Relation* readrel1440 = db->getRelation("$seq_at");
      $seq_atindex1418 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({0, 1, 2});
      slog::Relation* readrel1442 = db->getRelation("$seq_at");
      $seq_atindex1419 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({0, 1, 2});
      slog::Relation* readrel1444 = db->getRelation("$seq_atr");
      $seq_atrindex1420 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({0, 1, 2});
      slog::Relation* readrel1446 = db->getRelation("$seq_atr");
      $seq_atrindex1421 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({0, 1, 2});
      slog::Relation* readrel1448 = db->getRelation("$seq_atr");
      $seq_atrindex1422 = readrel1448->getIndex(ord1447, false);
      std::vector<u16> ord1449({0, 1, 2});
      slog::Relation* readrel1450 = db->getRelation("$seq_atr");
      $seq_atrdelta1426 = readrel1450->getIndex(ord1449, true);
      std::vector<u16> ord1451({0, 1, 2});
      slog::Relation* readrel1452 = db->getRelation("$seq_atr");
      $seq_atrindex1423 = readrel1452->getIndex(ord1451, false);
      std::vector<u16> ord1453({0, 1, 2});
      slog::Relation* readrel1454 = db->getRelation("$seq_atr");
      $seq_atrdelta1427 = readrel1454->getIndex(ord1453, true);
      std::vector<u16> ord1455({1, 0});
      slog::Relation* readrel1456 = db->getRelation("lst_len");
      lst_lenindex1424 = readrel1456->getIndex(ord1455, false);
      std::vector<u16> ord1457({0, 1});
      slog::Relation* readrel1458 = db->getRelation("lst_len_ans");
      lst_len_ansindex1425 = readrel1458->getIndex(ord1457, false);
  
    }
    ReadTask1428(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c221, v_c222, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1459) {
        u64 v_c19 = m1459[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1415, std::array<u64,3>{v_c207, v_c208, v_c19}, [&](const std::array<u64,3>& m1460) {
          slog::join_probe<3,3>($seq_atindex1416, std::array<u64,3>{v_c209, v_c210, v_c19}, [&](const std::array<u64,3>& m1461) {
            slog::join_probe<3,3>($seq_atindex1417, std::array<u64,3>{v_c211, v_c212, v_c19}, [&](const std::array<u64,3>& m1462) {
              slog::join_probe<3,3>($seq_atindex1418, std::array<u64,3>{v_c213, v_c214, v_c19}, [&](const std::array<u64,3>& m1463) {
                slog::join_probe<3,3>($seq_atindex1419, std::array<u64,3>{v_c215, v_c216, v_c19}, [&](const std::array<u64,3>& m1464) {
                  slog::join_probe<3,3>($seq_atrindex1420, std::array<u64,3>{v_c217, v_c218, v_c19}, [&](const std::array<u64,3>& m1465) {
                    slog::join_probe<3,3>($seq_atrindex1421, std::array<u64,3>{v_c219, v_c220, v_c19}, [&](const std::array<u64,3>& m1466) {
                      slog::join_probe_old<3,3>($seq_atrindex1422, $seq_atrdelta1426, std::array<u64,3>{v_c223, v_c224, v_c19}, [&](const std::array<u64,3>& m1467) {
                        slog::join_probe_old<3,3>($seq_atrindex1423, $seq_atrdelta1427, std::array<u64,3>{v_c225, v_c226, v_c19}, [&](const std::array<u64,3>& m1468) {
                          slog::join_probe<2,1>(lst_lenindex1424, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1469) {
                            u64 v_c227 = m1469[1];
                            slog::join_probe<2,1>(lst_len_ansindex1425, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1470) {
                              u64 v_c21 = m1470[1];
                              bool ok1471 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1471);
                              if (!ok1471) return;
                              u64 v_c241 = _prim_llen(db, v_c228);
                              if (v_c241 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c241) return;
                              bool ok1472 = true;
                              u64 v_c242 = _prim_lref(db, v_c228, v_c197, &ok1472);
                              if (!ok1472) return;
                              if (v_c198 != v_c242) return;
                              bool ok1473 = true;
                              u64 v_c243 = _prim_lref(db, v_c228, v_c199, &ok1473);
                              if (!ok1473) return;
                              if (v_c200 != v_c243) return;
                              bool ok1474 = true;
                              u64 v_c244 = _prim_lref(db, v_c228, v_c201, &ok1474);
                              if (!ok1474) return;
                              if (v_c202 != v_c244) return;
                              bool ok1475 = true;
                              u64 v_c245 = _prim_lref(db, v_c228, v_c203, &ok1475);
                              if (!ok1475) return;
                              if (v_c204 != v_c245) return;
                              bool ok1476 = true;
                              u64 v_c246 = _prim_lref(db, v_c228, v_c205, &ok1476);
                              if (!ok1476) return;
                              if (v_c206 != v_c246) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1428* _cont = new ReadTask1428(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1428(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo6djO58 _00024sqo09C757 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo56lA50 _00024sqo393o49 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk5RPf566 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk5RPf566) (letp chk6Yu7567 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk6Yu7567) (letp chk6yi8568 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk6yi8568) (letp chk4w4a569 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk4w4a569) (letp chk0nD8570 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk0nD8570) (letp chk3K9T571 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk3K9T571)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1491 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1477;  slog::Index** $seq_atindex1478;  slog::Index** $seq_atindex1479;  slog::Index** $seq_atindex1480;  slog::Index** $seq_atindex1481;  slog::Index** $seq_atrindex1482;  slog::Index** $seq_atrindex1483;  slog::Index** $seq_atrindex1484;  slog::Index** $seq_atrindex1485;  slog::Index** lst_lenindex1486;  slog::Index** lst_len_ansindex1487;  slog::Index** $seq_atrdelta1488;  slog::Index** $seq_atrdelta1489;  slog::Index** $seq_atrdelta1490;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1492({0});
      slog::Relation* readrel1493 = db->getRelation("n");
      head_index[0] = readrel1493->getIndex(ord1492, false);
      std::vector<u16> ord1494({0, 1, 2});
      slog::Relation* readrel1495 = db->getRelation("$seq_atr");
      driver_index = readrel1495->getIndex(ord1494, true);
      std::vector<u16> ord1496({0, 1, 2});
      slog::Relation* readrel1497 = db->getRelation("$seq_at");
      $seq_atindex1477 = readrel1497->getIndex(ord1496, false);
      std::vector<u16> ord1498({0, 1, 2});
      slog::Relation* readrel1499 = db->getRelation("$seq_at");
      $seq_atindex1478 = readrel1499->getIndex(ord1498, false);
      std::vector<u16> ord1500({0, 1, 2});
      slog::Relation* readrel1501 = db->getRelation("$seq_at");
      $seq_atindex1479 = readrel1501->getIndex(ord1500, false);
      std::vector<u16> ord1502({0, 1, 2});
      slog::Relation* readrel1503 = db->getRelation("$seq_at");
      $seq_atindex1480 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({0, 1, 2});
      slog::Relation* readrel1505 = db->getRelation("$seq_at");
      $seq_atindex1481 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({0, 1, 2});
      slog::Relation* readrel1507 = db->getRelation("$seq_atr");
      $seq_atrindex1482 = readrel1507->getIndex(ord1506, false);
      std::vector<u16> ord1508({0, 1, 2});
      slog::Relation* readrel1509 = db->getRelation("$seq_atr");
      $seq_atrindex1483 = readrel1509->getIndex(ord1508, false);
      std::vector<u16> ord1510({0, 1, 2});
      slog::Relation* readrel1511 = db->getRelation("$seq_atr");
      $seq_atrdelta1488 = readrel1511->getIndex(ord1510, true);
      std::vector<u16> ord1512({0, 1, 2});
      slog::Relation* readrel1513 = db->getRelation("$seq_atr");
      $seq_atrindex1484 = readrel1513->getIndex(ord1512, false);
      std::vector<u16> ord1514({0, 1, 2});
      slog::Relation* readrel1515 = db->getRelation("$seq_atr");
      $seq_atrdelta1489 = readrel1515->getIndex(ord1514, true);
      std::vector<u16> ord1516({0, 1, 2});
      slog::Relation* readrel1517 = db->getRelation("$seq_atr");
      $seq_atrindex1485 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({0, 1, 2});
      slog::Relation* readrel1519 = db->getRelation("$seq_atr");
      $seq_atrdelta1490 = readrel1519->getIndex(ord1518, true);
      std::vector<u16> ord1520({1, 0});
      slog::Relation* readrel1521 = db->getRelation("lst_len");
      lst_lenindex1486 = readrel1521->getIndex(ord1520, false);
      std::vector<u16> ord1522({0, 1});
      slog::Relation* readrel1523 = db->getRelation("lst_len_ans");
      lst_len_ansindex1487 = readrel1523->getIndex(ord1522, false);
  
    }
    ReadTask1491(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c219, v_c220, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1524) {
        u64 v_c19 = m1524[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1477, std::array<u64,3>{v_c207, v_c208, v_c19}, [&](const std::array<u64,3>& m1525) {
          slog::join_probe<3,3>($seq_atindex1478, std::array<u64,3>{v_c209, v_c210, v_c19}, [&](const std::array<u64,3>& m1526) {
            slog::join_probe<3,3>($seq_atindex1479, std::array<u64,3>{v_c211, v_c212, v_c19}, [&](const std::array<u64,3>& m1527) {
              slog::join_probe<3,3>($seq_atindex1480, std::array<u64,3>{v_c213, v_c214, v_c19}, [&](const std::array<u64,3>& m1528) {
                slog::join_probe<3,3>($seq_atindex1481, std::array<u64,3>{v_c215, v_c216, v_c19}, [&](const std::array<u64,3>& m1529) {
                  slog::join_probe<3,3>($seq_atrindex1482, std::array<u64,3>{v_c217, v_c218, v_c19}, [&](const std::array<u64,3>& m1530) {
                    slog::join_probe_old<3,3>($seq_atrindex1483, $seq_atrdelta1488, std::array<u64,3>{v_c221, v_c222, v_c19}, [&](const std::array<u64,3>& m1531) {
                      slog::join_probe_old<3,3>($seq_atrindex1484, $seq_atrdelta1489, std::array<u64,3>{v_c223, v_c224, v_c19}, [&](const std::array<u64,3>& m1532) {
                        slog::join_probe_old<3,3>($seq_atrindex1485, $seq_atrdelta1490, std::array<u64,3>{v_c225, v_c226, v_c19}, [&](const std::array<u64,3>& m1533) {
                          slog::join_probe<2,1>(lst_lenindex1486, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1534) {
                            u64 v_c227 = m1534[1];
                            slog::join_probe<2,1>(lst_len_ansindex1487, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1535) {
                              u64 v_c21 = m1535[1];
                              bool ok1536 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1536);
                              if (!ok1536) return;
                              u64 v_c247 = _prim_llen(db, v_c228);
                              if (v_c247 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c247) return;
                              bool ok1537 = true;
                              u64 v_c248 = _prim_lref(db, v_c228, v_c197, &ok1537);
                              if (!ok1537) return;
                              if (v_c198 != v_c248) return;
                              bool ok1538 = true;
                              u64 v_c249 = _prim_lref(db, v_c228, v_c199, &ok1538);
                              if (!ok1538) return;
                              if (v_c200 != v_c249) return;
                              bool ok1539 = true;
                              u64 v_c250 = _prim_lref(db, v_c228, v_c201, &ok1539);
                              if (!ok1539) return;
                              if (v_c202 != v_c250) return;
                              bool ok1540 = true;
                              u64 v_c251 = _prim_lref(db, v_c228, v_c203, &ok1540);
                              if (!ok1540) return;
                              if (v_c204 != v_c251) return;
                              bool ok1541 = true;
                              u64 v_c252 = _prim_lref(db, v_c228, v_c205, &ok1541);
                              if (!ok1541) return;
                              if (v_c206 != v_c252) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1491* _cont = new ReadTask1491(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1491(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo56lA50 _00024sqo393o49 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo6djO58 _00024sqo09C757 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk4XgF560 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk4XgF560) (letp chk1zYW561 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk1zYW561) (letp chk8dzK562 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk8dzK562) (letp chk0Zhi563 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk0Zhi563) (letp chk8URg564 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk8URg564) (letp chk4iw9565 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk4iw9565)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1557 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1542;  slog::Index** $seq_atindex1543;  slog::Index** $seq_atindex1544;  slog::Index** $seq_atindex1545;  slog::Index** $seq_atindex1546;  slog::Index** $seq_atrindex1547;  slog::Index** $seq_atrindex1548;  slog::Index** $seq_atrindex1549;  slog::Index** $seq_atrindex1550;  slog::Index** lst_lenindex1551;  slog::Index** lst_len_ansindex1552;  slog::Index** $seq_atrdelta1553;  slog::Index** $seq_atrdelta1554;  slog::Index** $seq_atrdelta1555;  slog::Index** $seq_atrdelta1556;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1558({0});
      slog::Relation* readrel1559 = db->getRelation("n");
      head_index[0] = readrel1559->getIndex(ord1558, false);
      std::vector<u16> ord1560({0, 1, 2});
      slog::Relation* readrel1561 = db->getRelation("$seq_atr");
      driver_index = readrel1561->getIndex(ord1560, true);
      std::vector<u16> ord1562({0, 1, 2});
      slog::Relation* readrel1563 = db->getRelation("$seq_at");
      $seq_atindex1542 = readrel1563->getIndex(ord1562, false);
      std::vector<u16> ord1564({0, 1, 2});
      slog::Relation* readrel1565 = db->getRelation("$seq_at");
      $seq_atindex1543 = readrel1565->getIndex(ord1564, false);
      std::vector<u16> ord1566({0, 1, 2});
      slog::Relation* readrel1567 = db->getRelation("$seq_at");
      $seq_atindex1544 = readrel1567->getIndex(ord1566, false);
      std::vector<u16> ord1568({0, 1, 2});
      slog::Relation* readrel1569 = db->getRelation("$seq_at");
      $seq_atindex1545 = readrel1569->getIndex(ord1568, false);
      std::vector<u16> ord1570({0, 1, 2});
      slog::Relation* readrel1571 = db->getRelation("$seq_at");
      $seq_atindex1546 = readrel1571->getIndex(ord1570, false);
      std::vector<u16> ord1572({0, 1, 2});
      slog::Relation* readrel1573 = db->getRelation("$seq_atr");
      $seq_atrindex1547 = readrel1573->getIndex(ord1572, false);
      std::vector<u16> ord1574({0, 1, 2});
      slog::Relation* readrel1575 = db->getRelation("$seq_atr");
      $seq_atrdelta1553 = readrel1575->getIndex(ord1574, true);
      std::vector<u16> ord1576({0, 1, 2});
      slog::Relation* readrel1577 = db->getRelation("$seq_atr");
      $seq_atrindex1548 = readrel1577->getIndex(ord1576, false);
      std::vector<u16> ord1578({0, 1, 2});
      slog::Relation* readrel1579 = db->getRelation("$seq_atr");
      $seq_atrdelta1554 = readrel1579->getIndex(ord1578, true);
      std::vector<u16> ord1580({0, 1, 2});
      slog::Relation* readrel1581 = db->getRelation("$seq_atr");
      $seq_atrindex1549 = readrel1581->getIndex(ord1580, false);
      std::vector<u16> ord1582({0, 1, 2});
      slog::Relation* readrel1583 = db->getRelation("$seq_atr");
      $seq_atrdelta1555 = readrel1583->getIndex(ord1582, true);
      std::vector<u16> ord1584({0, 1, 2});
      slog::Relation* readrel1585 = db->getRelation("$seq_atr");
      $seq_atrindex1550 = readrel1585->getIndex(ord1584, false);
      std::vector<u16> ord1586({0, 1, 2});
      slog::Relation* readrel1587 = db->getRelation("$seq_atr");
      $seq_atrdelta1556 = readrel1587->getIndex(ord1586, true);
      std::vector<u16> ord1588({1, 0});
      slog::Relation* readrel1589 = db->getRelation("lst_len");
      lst_lenindex1551 = readrel1589->getIndex(ord1588, false);
      std::vector<u16> ord1590({0, 1});
      slog::Relation* readrel1591 = db->getRelation("lst_len_ans");
      lst_len_ansindex1552 = readrel1591->getIndex(ord1590, false);
  
    }
    ReadTask1557(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c217, v_c218, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1592) {
        u64 v_c19 = m1592[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1542, std::array<u64,3>{v_c207, v_c208, v_c19}, [&](const std::array<u64,3>& m1593) {
          slog::join_probe<3,3>($seq_atindex1543, std::array<u64,3>{v_c209, v_c210, v_c19}, [&](const std::array<u64,3>& m1594) {
            slog::join_probe<3,3>($seq_atindex1544, std::array<u64,3>{v_c211, v_c212, v_c19}, [&](const std::array<u64,3>& m1595) {
              slog::join_probe<3,3>($seq_atindex1545, std::array<u64,3>{v_c213, v_c214, v_c19}, [&](const std::array<u64,3>& m1596) {
                slog::join_probe<3,3>($seq_atindex1546, std::array<u64,3>{v_c215, v_c216, v_c19}, [&](const std::array<u64,3>& m1597) {
                  slog::join_probe_old<3,3>($seq_atrindex1547, $seq_atrdelta1553, std::array<u64,3>{v_c219, v_c220, v_c19}, [&](const std::array<u64,3>& m1598) {
                    slog::join_probe_old<3,3>($seq_atrindex1548, $seq_atrdelta1554, std::array<u64,3>{v_c221, v_c222, v_c19}, [&](const std::array<u64,3>& m1599) {
                      slog::join_probe_old<3,3>($seq_atrindex1549, $seq_atrdelta1555, std::array<u64,3>{v_c223, v_c224, v_c19}, [&](const std::array<u64,3>& m1600) {
                        slog::join_probe_old<3,3>($seq_atrindex1550, $seq_atrdelta1556, std::array<u64,3>{v_c225, v_c226, v_c19}, [&](const std::array<u64,3>& m1601) {
                          slog::join_probe<2,1>(lst_lenindex1551, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1602) {
                            u64 v_c227 = m1602[1];
                            slog::join_probe<2,1>(lst_len_ansindex1552, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1603) {
                              u64 v_c21 = m1603[1];
                              bool ok1604 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1604);
                              if (!ok1604) return;
                              u64 v_c253 = _prim_llen(db, v_c228);
                              if (v_c253 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c253) return;
                              bool ok1605 = true;
                              u64 v_c254 = _prim_lref(db, v_c228, v_c197, &ok1605);
                              if (!ok1605) return;
                              if (v_c198 != v_c254) return;
                              bool ok1606 = true;
                              u64 v_c255 = _prim_lref(db, v_c228, v_c199, &ok1606);
                              if (!ok1606) return;
                              if (v_c200 != v_c255) return;
                              bool ok1607 = true;
                              u64 v_c256 = _prim_lref(db, v_c228, v_c201, &ok1607);
                              if (!ok1607) return;
                              if (v_c202 != v_c256) return;
                              bool ok1608 = true;
                              u64 v_c257 = _prim_lref(db, v_c228, v_c203, &ok1608);
                              if (!ok1608) return;
                              if (v_c204 != v_c257) return;
                              bool ok1609 = true;
                              u64 v_c258 = _prim_lref(db, v_c228, v_c205, &ok1609);
                              if (!ok1609) return;
                              if (v_c206 != v_c258) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1557* _cont = new ReadTask1557(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1557(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo56lA50 _00024sqo393o49 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo6djO58 _00024sqo09C757 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk8qVw554 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk8qVw554) (letp chk2ruS555 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk2ruS555) (letp chk2ASo556 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk2ASo556) (letp chk567E557 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk567E557) (letp chk2VKF558 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk2VKF558) (letp chk5pCB559 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk5pCB559)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1626 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1610;  slog::Index** $seq_atindex1611;  slog::Index** $seq_atindex1612;  slog::Index** $seq_atindex1613;  slog::Index** $seq_atrindex1614;  slog::Index** $seq_atrindex1615;  slog::Index** $seq_atrindex1616;  slog::Index** $seq_atrindex1617;  slog::Index** $seq_atrindex1618;  slog::Index** lst_lenindex1619;  slog::Index** lst_len_ansindex1620;  slog::Index** $seq_atrdelta1621;  slog::Index** $seq_atrdelta1622;  slog::Index** $seq_atrdelta1623;  slog::Index** $seq_atrdelta1624;  slog::Index** $seq_atrdelta1625;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1627({0});
      slog::Relation* readrel1628 = db->getRelation("n");
      head_index[0] = readrel1628->getIndex(ord1627, false);
      std::vector<u16> ord1629({0, 1, 2});
      slog::Relation* readrel1630 = db->getRelation("$seq_at");
      driver_index = readrel1630->getIndex(ord1629, true);
      std::vector<u16> ord1631({0, 1, 2});
      slog::Relation* readrel1632 = db->getRelation("$seq_at");
      $seq_atindex1610 = readrel1632->getIndex(ord1631, false);
      std::vector<u16> ord1633({0, 1, 2});
      slog::Relation* readrel1634 = db->getRelation("$seq_at");
      $seq_atindex1611 = readrel1634->getIndex(ord1633, false);
      std::vector<u16> ord1635({0, 1, 2});
      slog::Relation* readrel1636 = db->getRelation("$seq_at");
      $seq_atindex1612 = readrel1636->getIndex(ord1635, false);
      std::vector<u16> ord1637({0, 1, 2});
      slog::Relation* readrel1638 = db->getRelation("$seq_at");
      $seq_atindex1613 = readrel1638->getIndex(ord1637, false);
      std::vector<u16> ord1639({0, 1, 2});
      slog::Relation* readrel1640 = db->getRelation("$seq_atr");
      $seq_atrindex1614 = readrel1640->getIndex(ord1639, false);
      std::vector<u16> ord1641({0, 1, 2});
      slog::Relation* readrel1642 = db->getRelation("$seq_atr");
      $seq_atrdelta1621 = readrel1642->getIndex(ord1641, true);
      std::vector<u16> ord1643({0, 1, 2});
      slog::Relation* readrel1644 = db->getRelation("$seq_atr");
      $seq_atrindex1615 = readrel1644->getIndex(ord1643, false);
      std::vector<u16> ord1645({0, 1, 2});
      slog::Relation* readrel1646 = db->getRelation("$seq_atr");
      $seq_atrdelta1622 = readrel1646->getIndex(ord1645, true);
      std::vector<u16> ord1647({0, 1, 2});
      slog::Relation* readrel1648 = db->getRelation("$seq_atr");
      $seq_atrindex1616 = readrel1648->getIndex(ord1647, false);
      std::vector<u16> ord1649({0, 1, 2});
      slog::Relation* readrel1650 = db->getRelation("$seq_atr");
      $seq_atrdelta1623 = readrel1650->getIndex(ord1649, true);
      std::vector<u16> ord1651({0, 1, 2});
      slog::Relation* readrel1652 = db->getRelation("$seq_atr");
      $seq_atrindex1617 = readrel1652->getIndex(ord1651, false);
      std::vector<u16> ord1653({0, 1, 2});
      slog::Relation* readrel1654 = db->getRelation("$seq_atr");
      $seq_atrdelta1624 = readrel1654->getIndex(ord1653, true);
      std::vector<u16> ord1655({0, 1, 2});
      slog::Relation* readrel1656 = db->getRelation("$seq_atr");
      $seq_atrindex1618 = readrel1656->getIndex(ord1655, false);
      std::vector<u16> ord1657({0, 1, 2});
      slog::Relation* readrel1658 = db->getRelation("$seq_atr");
      $seq_atrdelta1625 = readrel1658->getIndex(ord1657, true);
      std::vector<u16> ord1659({1, 0});
      slog::Relation* readrel1660 = db->getRelation("lst_len");
      lst_lenindex1619 = readrel1660->getIndex(ord1659, false);
      std::vector<u16> ord1661({0, 1});
      slog::Relation* readrel1662 = db->getRelation("lst_len_ans");
      lst_len_ansindex1620 = readrel1662->getIndex(ord1661, false);
  
    }
    ReadTask1626(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c215, v_c216, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1663) {
        u64 v_c19 = m1663[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1610, std::array<u64,3>{v_c207, v_c208, v_c19}, [&](const std::array<u64,3>& m1664) {
          slog::join_probe<3,3>($seq_atindex1611, std::array<u64,3>{v_c209, v_c210, v_c19}, [&](const std::array<u64,3>& m1665) {
            slog::join_probe<3,3>($seq_atindex1612, std::array<u64,3>{v_c211, v_c212, v_c19}, [&](const std::array<u64,3>& m1666) {
              slog::join_probe<3,3>($seq_atindex1613, std::array<u64,3>{v_c213, v_c214, v_c19}, [&](const std::array<u64,3>& m1667) {
                slog::join_probe_old<3,3>($seq_atrindex1614, $seq_atrdelta1621, std::array<u64,3>{v_c217, v_c218, v_c19}, [&](const std::array<u64,3>& m1668) {
                  slog::join_probe_old<3,3>($seq_atrindex1615, $seq_atrdelta1622, std::array<u64,3>{v_c219, v_c220, v_c19}, [&](const std::array<u64,3>& m1669) {
                    slog::join_probe_old<3,3>($seq_atrindex1616, $seq_atrdelta1623, std::array<u64,3>{v_c221, v_c222, v_c19}, [&](const std::array<u64,3>& m1670) {
                      slog::join_probe_old<3,3>($seq_atrindex1617, $seq_atrdelta1624, std::array<u64,3>{v_c223, v_c224, v_c19}, [&](const std::array<u64,3>& m1671) {
                        slog::join_probe_old<3,3>($seq_atrindex1618, $seq_atrdelta1625, std::array<u64,3>{v_c225, v_c226, v_c19}, [&](const std::array<u64,3>& m1672) {
                          slog::join_probe<2,1>(lst_lenindex1619, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1673) {
                            u64 v_c227 = m1673[1];
                            slog::join_probe<2,1>(lst_len_ansindex1620, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1674) {
                              u64 v_c21 = m1674[1];
                              bool ok1675 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1675);
                              if (!ok1675) return;
                              u64 v_c259 = _prim_llen(db, v_c228);
                              if (v_c259 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c259) return;
                              bool ok1676 = true;
                              u64 v_c260 = _prim_lref(db, v_c228, v_c197, &ok1676);
                              if (!ok1676) return;
                              if (v_c198 != v_c260) return;
                              bool ok1677 = true;
                              u64 v_c261 = _prim_lref(db, v_c228, v_c199, &ok1677);
                              if (!ok1677) return;
                              if (v_c200 != v_c261) return;
                              bool ok1678 = true;
                              u64 v_c262 = _prim_lref(db, v_c228, v_c201, &ok1678);
                              if (!ok1678) return;
                              if (v_c202 != v_c262) return;
                              bool ok1679 = true;
                              u64 v_c263 = _prim_lref(db, v_c228, v_c203, &ok1679);
                              if (!ok1679) return;
                              if (v_c204 != v_c263) return;
                              bool ok1680 = true;
                              u64 v_c264 = _prim_lref(db, v_c228, v_c205, &ok1680);
                              if (!ok1680) return;
                              if (v_c206 != v_c264) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1626* _cont = new ReadTask1626(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1626(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo56lA50 _00024sqo393o49 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo6djO58 _00024sqo09C757 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk3doe548 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk3doe548) (letp chk6fvb549 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk6fvb549) (letp chk18p3550 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk18p3550) (letp chk6Jh9551 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk6Jh9551) (letp chk61E1552 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk61E1552) (letp chk2hwC553 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk2hwC553)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1698 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1681;  slog::Index** $seq_atindex1682;  slog::Index** $seq_atindex1683;  slog::Index** $seq_atindex1684;  slog::Index** $seq_atrindex1685;  slog::Index** $seq_atrindex1686;  slog::Index** $seq_atrindex1687;  slog::Index** $seq_atrindex1688;  slog::Index** $seq_atrindex1689;  slog::Index** lst_lenindex1690;  slog::Index** lst_len_ansindex1691;  slog::Index** $seq_atdelta1692;  slog::Index** $seq_atrdelta1693;  slog::Index** $seq_atrdelta1694;  slog::Index** $seq_atrdelta1695;  slog::Index** $seq_atrdelta1696;  slog::Index** $seq_atrdelta1697;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1699({0});
      slog::Relation* readrel1700 = db->getRelation("n");
      head_index[0] = readrel1700->getIndex(ord1699, false);
      std::vector<u16> ord1701({0, 1, 2});
      slog::Relation* readrel1702 = db->getRelation("$seq_at");
      driver_index = readrel1702->getIndex(ord1701, true);
      std::vector<u16> ord1703({0, 1, 2});
      slog::Relation* readrel1704 = db->getRelation("$seq_at");
      $seq_atindex1681 = readrel1704->getIndex(ord1703, false);
      std::vector<u16> ord1705({0, 1, 2});
      slog::Relation* readrel1706 = db->getRelation("$seq_at");
      $seq_atindex1682 = readrel1706->getIndex(ord1705, false);
      std::vector<u16> ord1707({0, 1, 2});
      slog::Relation* readrel1708 = db->getRelation("$seq_at");
      $seq_atindex1683 = readrel1708->getIndex(ord1707, false);
      std::vector<u16> ord1709({0, 1, 2});
      slog::Relation* readrel1710 = db->getRelation("$seq_at");
      $seq_atindex1684 = readrel1710->getIndex(ord1709, false);
      std::vector<u16> ord1711({0, 1, 2});
      slog::Relation* readrel1712 = db->getRelation("$seq_at");
      $seq_atdelta1692 = readrel1712->getIndex(ord1711, true);
      std::vector<u16> ord1713({0, 1, 2});
      slog::Relation* readrel1714 = db->getRelation("$seq_atr");
      $seq_atrindex1685 = readrel1714->getIndex(ord1713, false);
      std::vector<u16> ord1715({0, 1, 2});
      slog::Relation* readrel1716 = db->getRelation("$seq_atr");
      $seq_atrdelta1693 = readrel1716->getIndex(ord1715, true);
      std::vector<u16> ord1717({0, 1, 2});
      slog::Relation* readrel1718 = db->getRelation("$seq_atr");
      $seq_atrindex1686 = readrel1718->getIndex(ord1717, false);
      std::vector<u16> ord1719({0, 1, 2});
      slog::Relation* readrel1720 = db->getRelation("$seq_atr");
      $seq_atrdelta1694 = readrel1720->getIndex(ord1719, true);
      std::vector<u16> ord1721({0, 1, 2});
      slog::Relation* readrel1722 = db->getRelation("$seq_atr");
      $seq_atrindex1687 = readrel1722->getIndex(ord1721, false);
      std::vector<u16> ord1723({0, 1, 2});
      slog::Relation* readrel1724 = db->getRelation("$seq_atr");
      $seq_atrdelta1695 = readrel1724->getIndex(ord1723, true);
      std::vector<u16> ord1725({0, 1, 2});
      slog::Relation* readrel1726 = db->getRelation("$seq_atr");
      $seq_atrindex1688 = readrel1726->getIndex(ord1725, false);
      std::vector<u16> ord1727({0, 1, 2});
      slog::Relation* readrel1728 = db->getRelation("$seq_atr");
      $seq_atrdelta1696 = readrel1728->getIndex(ord1727, true);
      std::vector<u16> ord1729({0, 1, 2});
      slog::Relation* readrel1730 = db->getRelation("$seq_atr");
      $seq_atrindex1689 = readrel1730->getIndex(ord1729, false);
      std::vector<u16> ord1731({0, 1, 2});
      slog::Relation* readrel1732 = db->getRelation("$seq_atr");
      $seq_atrdelta1697 = readrel1732->getIndex(ord1731, true);
      std::vector<u16> ord1733({1, 0});
      slog::Relation* readrel1734 = db->getRelation("lst_len");
      lst_lenindex1690 = readrel1734->getIndex(ord1733, false);
      std::vector<u16> ord1735({0, 1});
      slog::Relation* readrel1736 = db->getRelation("lst_len_ans");
      lst_len_ansindex1691 = readrel1736->getIndex(ord1735, false);
  
    }
    ReadTask1698(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c213, v_c214, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1737) {
        u64 v_c19 = m1737[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1681, std::array<u64,3>{v_c207, v_c208, v_c19}, [&](const std::array<u64,3>& m1738) {
          slog::join_probe<3,3>($seq_atindex1682, std::array<u64,3>{v_c209, v_c210, v_c19}, [&](const std::array<u64,3>& m1739) {
            slog::join_probe<3,3>($seq_atindex1683, std::array<u64,3>{v_c211, v_c212, v_c19}, [&](const std::array<u64,3>& m1740) {
              slog::join_probe_old<3,3>($seq_atindex1684, $seq_atdelta1692, std::array<u64,3>{v_c215, v_c216, v_c19}, [&](const std::array<u64,3>& m1741) {
                slog::join_probe_old<3,3>($seq_atrindex1685, $seq_atrdelta1693, std::array<u64,3>{v_c217, v_c218, v_c19}, [&](const std::array<u64,3>& m1742) {
                  slog::join_probe_old<3,3>($seq_atrindex1686, $seq_atrdelta1694, std::array<u64,3>{v_c219, v_c220, v_c19}, [&](const std::array<u64,3>& m1743) {
                    slog::join_probe_old<3,3>($seq_atrindex1687, $seq_atrdelta1695, std::array<u64,3>{v_c221, v_c222, v_c19}, [&](const std::array<u64,3>& m1744) {
                      slog::join_probe_old<3,3>($seq_atrindex1688, $seq_atrdelta1696, std::array<u64,3>{v_c223, v_c224, v_c19}, [&](const std::array<u64,3>& m1745) {
                        slog::join_probe_old<3,3>($seq_atrindex1689, $seq_atrdelta1697, std::array<u64,3>{v_c225, v_c226, v_c19}, [&](const std::array<u64,3>& m1746) {
                          slog::join_probe<2,1>(lst_lenindex1690, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1747) {
                            u64 v_c227 = m1747[1];
                            slog::join_probe<2,1>(lst_len_ansindex1691, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1748) {
                              u64 v_c21 = m1748[1];
                              bool ok1749 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1749);
                              if (!ok1749) return;
                              u64 v_c265 = _prim_llen(db, v_c228);
                              if (v_c265 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c265) return;
                              bool ok1750 = true;
                              u64 v_c266 = _prim_lref(db, v_c228, v_c197, &ok1750);
                              if (!ok1750) return;
                              if (v_c198 != v_c266) return;
                              bool ok1751 = true;
                              u64 v_c267 = _prim_lref(db, v_c228, v_c199, &ok1751);
                              if (!ok1751) return;
                              if (v_c200 != v_c267) return;
                              bool ok1752 = true;
                              u64 v_c268 = _prim_lref(db, v_c228, v_c201, &ok1752);
                              if (!ok1752) return;
                              if (v_c202 != v_c268) return;
                              bool ok1753 = true;
                              u64 v_c269 = _prim_lref(db, v_c228, v_c203, &ok1753);
                              if (!ok1753) return;
                              if (v_c204 != v_c269) return;
                              bool ok1754 = true;
                              u64 v_c270 = _prim_lref(db, v_c228, v_c205, &ok1754);
                              if (!ok1754) return;
                              if (v_c206 != v_c270) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1698* _cont = new ReadTask1698(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1698(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo56lA50 _00024sqo393o49 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo6djO58 _00024sqo09C757 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk3QPq542 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk3QPq542) (letp chk8oTu543 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk8oTu543) (letp chk36gi544 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk36gi544) (letp chk2fOX545 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk2fOX545) (letp chk97Qz546 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk97Qz546) (letp chk1Q9E547 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk1Q9E547)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1773 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1755;  slog::Index** $seq_atindex1756;  slog::Index** $seq_atindex1757;  slog::Index** $seq_atindex1758;  slog::Index** $seq_atrindex1759;  slog::Index** $seq_atrindex1760;  slog::Index** $seq_atrindex1761;  slog::Index** $seq_atrindex1762;  slog::Index** $seq_atrindex1763;  slog::Index** lst_lenindex1764;  slog::Index** lst_len_ansindex1765;  slog::Index** $seq_atdelta1766;  slog::Index** $seq_atdelta1767;  slog::Index** $seq_atrdelta1768;  slog::Index** $seq_atrdelta1769;  slog::Index** $seq_atrdelta1770;  slog::Index** $seq_atrdelta1771;  slog::Index** $seq_atrdelta1772;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1774({0});
      slog::Relation* readrel1775 = db->getRelation("n");
      head_index[0] = readrel1775->getIndex(ord1774, false);
      std::vector<u16> ord1776({0, 1, 2});
      slog::Relation* readrel1777 = db->getRelation("$seq_at");
      driver_index = readrel1777->getIndex(ord1776, true);
      std::vector<u16> ord1778({0, 1, 2});
      slog::Relation* readrel1779 = db->getRelation("$seq_at");
      $seq_atindex1755 = readrel1779->getIndex(ord1778, false);
      std::vector<u16> ord1780({0, 1, 2});
      slog::Relation* readrel1781 = db->getRelation("$seq_at");
      $seq_atindex1756 = readrel1781->getIndex(ord1780, false);
      std::vector<u16> ord1782({0, 1, 2});
      slog::Relation* readrel1783 = db->getRelation("$seq_at");
      $seq_atindex1757 = readrel1783->getIndex(ord1782, false);
      std::vector<u16> ord1784({0, 1, 2});
      slog::Relation* readrel1785 = db->getRelation("$seq_at");
      $seq_atdelta1766 = readrel1785->getIndex(ord1784, true);
      std::vector<u16> ord1786({0, 1, 2});
      slog::Relation* readrel1787 = db->getRelation("$seq_at");
      $seq_atindex1758 = readrel1787->getIndex(ord1786, false);
      std::vector<u16> ord1788({0, 1, 2});
      slog::Relation* readrel1789 = db->getRelation("$seq_at");
      $seq_atdelta1767 = readrel1789->getIndex(ord1788, true);
      std::vector<u16> ord1790({0, 1, 2});
      slog::Relation* readrel1791 = db->getRelation("$seq_atr");
      $seq_atrindex1759 = readrel1791->getIndex(ord1790, false);
      std::vector<u16> ord1792({0, 1, 2});
      slog::Relation* readrel1793 = db->getRelation("$seq_atr");
      $seq_atrdelta1768 = readrel1793->getIndex(ord1792, true);
      std::vector<u16> ord1794({0, 1, 2});
      slog::Relation* readrel1795 = db->getRelation("$seq_atr");
      $seq_atrindex1760 = readrel1795->getIndex(ord1794, false);
      std::vector<u16> ord1796({0, 1, 2});
      slog::Relation* readrel1797 = db->getRelation("$seq_atr");
      $seq_atrdelta1769 = readrel1797->getIndex(ord1796, true);
      std::vector<u16> ord1798({0, 1, 2});
      slog::Relation* readrel1799 = db->getRelation("$seq_atr");
      $seq_atrindex1761 = readrel1799->getIndex(ord1798, false);
      std::vector<u16> ord1800({0, 1, 2});
      slog::Relation* readrel1801 = db->getRelation("$seq_atr");
      $seq_atrdelta1770 = readrel1801->getIndex(ord1800, true);
      std::vector<u16> ord1802({0, 1, 2});
      slog::Relation* readrel1803 = db->getRelation("$seq_atr");
      $seq_atrindex1762 = readrel1803->getIndex(ord1802, false);
      std::vector<u16> ord1804({0, 1, 2});
      slog::Relation* readrel1805 = db->getRelation("$seq_atr");
      $seq_atrdelta1771 = readrel1805->getIndex(ord1804, true);
      std::vector<u16> ord1806({0, 1, 2});
      slog::Relation* readrel1807 = db->getRelation("$seq_atr");
      $seq_atrindex1763 = readrel1807->getIndex(ord1806, false);
      std::vector<u16> ord1808({0, 1, 2});
      slog::Relation* readrel1809 = db->getRelation("$seq_atr");
      $seq_atrdelta1772 = readrel1809->getIndex(ord1808, true);
      std::vector<u16> ord1810({1, 0});
      slog::Relation* readrel1811 = db->getRelation("lst_len");
      lst_lenindex1764 = readrel1811->getIndex(ord1810, false);
      std::vector<u16> ord1812({0, 1});
      slog::Relation* readrel1813 = db->getRelation("lst_len_ans");
      lst_len_ansindex1765 = readrel1813->getIndex(ord1812, false);
  
    }
    ReadTask1773(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c211, v_c212, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1814) {
        u64 v_c19 = m1814[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1755, std::array<u64,3>{v_c207, v_c208, v_c19}, [&](const std::array<u64,3>& m1815) {
          slog::join_probe<3,3>($seq_atindex1756, std::array<u64,3>{v_c209, v_c210, v_c19}, [&](const std::array<u64,3>& m1816) {
            slog::join_probe_old<3,3>($seq_atindex1757, $seq_atdelta1766, std::array<u64,3>{v_c213, v_c214, v_c19}, [&](const std::array<u64,3>& m1817) {
              slog::join_probe_old<3,3>($seq_atindex1758, $seq_atdelta1767, std::array<u64,3>{v_c215, v_c216, v_c19}, [&](const std::array<u64,3>& m1818) {
                slog::join_probe_old<3,3>($seq_atrindex1759, $seq_atrdelta1768, std::array<u64,3>{v_c217, v_c218, v_c19}, [&](const std::array<u64,3>& m1819) {
                  slog::join_probe_old<3,3>($seq_atrindex1760, $seq_atrdelta1769, std::array<u64,3>{v_c219, v_c220, v_c19}, [&](const std::array<u64,3>& m1820) {
                    slog::join_probe_old<3,3>($seq_atrindex1761, $seq_atrdelta1770, std::array<u64,3>{v_c221, v_c222, v_c19}, [&](const std::array<u64,3>& m1821) {
                      slog::join_probe_old<3,3>($seq_atrindex1762, $seq_atrdelta1771, std::array<u64,3>{v_c223, v_c224, v_c19}, [&](const std::array<u64,3>& m1822) {
                        slog::join_probe_old<3,3>($seq_atrindex1763, $seq_atrdelta1772, std::array<u64,3>{v_c225, v_c226, v_c19}, [&](const std::array<u64,3>& m1823) {
                          slog::join_probe<2,1>(lst_lenindex1764, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1824) {
                            u64 v_c227 = m1824[1];
                            slog::join_probe<2,1>(lst_len_ansindex1765, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1825) {
                              u64 v_c21 = m1825[1];
                              bool ok1826 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1826);
                              if (!ok1826) return;
                              u64 v_c271 = _prim_llen(db, v_c228);
                              if (v_c271 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c271) return;
                              bool ok1827 = true;
                              u64 v_c272 = _prim_lref(db, v_c228, v_c197, &ok1827);
                              if (!ok1827) return;
                              if (v_c198 != v_c272) return;
                              bool ok1828 = true;
                              u64 v_c273 = _prim_lref(db, v_c228, v_c199, &ok1828);
                              if (!ok1828) return;
                              if (v_c200 != v_c273) return;
                              bool ok1829 = true;
                              u64 v_c274 = _prim_lref(db, v_c228, v_c201, &ok1829);
                              if (!ok1829) return;
                              if (v_c202 != v_c274) return;
                              bool ok1830 = true;
                              u64 v_c275 = _prim_lref(db, v_c228, v_c203, &ok1830);
                              if (!ok1830) return;
                              if (v_c204 != v_c275) return;
                              bool ok1831 = true;
                              u64 v_c276 = _prim_lref(db, v_c228, v_c205, &ok1831);
                              if (!ok1831) return;
                              if (v_c206 != v_c276) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1773* _cont = new ReadTask1773(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1773(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo56lA50 _00024sqo393o49 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo6djO58 _00024sqo09C757 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk31P6536 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk31P6536) (letp chk1TBp537 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk1TBp537) (letp chk89F1538 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk89F1538) (letp chk6gkp539 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk6gkp539) (letp chk1Xht540 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk1Xht540) (letp chk09im541 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk09im541)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1851 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1832;  slog::Index** $seq_atindex1833;  slog::Index** $seq_atindex1834;  slog::Index** $seq_atindex1835;  slog::Index** $seq_atrindex1836;  slog::Index** $seq_atrindex1837;  slog::Index** $seq_atrindex1838;  slog::Index** $seq_atrindex1839;  slog::Index** $seq_atrindex1840;  slog::Index** lst_lenindex1841;  slog::Index** lst_len_ansindex1842;  slog::Index** $seq_atdelta1843;  slog::Index** $seq_atdelta1844;  slog::Index** $seq_atdelta1845;  slog::Index** $seq_atrdelta1846;  slog::Index** $seq_atrdelta1847;  slog::Index** $seq_atrdelta1848;  slog::Index** $seq_atrdelta1849;  slog::Index** $seq_atrdelta1850;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1852({0});
      slog::Relation* readrel1853 = db->getRelation("n");
      head_index[0] = readrel1853->getIndex(ord1852, false);
      std::vector<u16> ord1854({0, 1, 2});
      slog::Relation* readrel1855 = db->getRelation("$seq_at");
      driver_index = readrel1855->getIndex(ord1854, true);
      std::vector<u16> ord1856({0, 1, 2});
      slog::Relation* readrel1857 = db->getRelation("$seq_at");
      $seq_atindex1832 = readrel1857->getIndex(ord1856, false);
      std::vector<u16> ord1858({0, 1, 2});
      slog::Relation* readrel1859 = db->getRelation("$seq_at");
      $seq_atindex1833 = readrel1859->getIndex(ord1858, false);
      std::vector<u16> ord1860({0, 1, 2});
      slog::Relation* readrel1861 = db->getRelation("$seq_at");
      $seq_atdelta1843 = readrel1861->getIndex(ord1860, true);
      std::vector<u16> ord1862({0, 1, 2});
      slog::Relation* readrel1863 = db->getRelation("$seq_at");
      $seq_atindex1834 = readrel1863->getIndex(ord1862, false);
      std::vector<u16> ord1864({0, 1, 2});
      slog::Relation* readrel1865 = db->getRelation("$seq_at");
      $seq_atdelta1844 = readrel1865->getIndex(ord1864, true);
      std::vector<u16> ord1866({0, 1, 2});
      slog::Relation* readrel1867 = db->getRelation("$seq_at");
      $seq_atindex1835 = readrel1867->getIndex(ord1866, false);
      std::vector<u16> ord1868({0, 1, 2});
      slog::Relation* readrel1869 = db->getRelation("$seq_at");
      $seq_atdelta1845 = readrel1869->getIndex(ord1868, true);
      std::vector<u16> ord1870({0, 1, 2});
      slog::Relation* readrel1871 = db->getRelation("$seq_atr");
      $seq_atrindex1836 = readrel1871->getIndex(ord1870, false);
      std::vector<u16> ord1872({0, 1, 2});
      slog::Relation* readrel1873 = db->getRelation("$seq_atr");
      $seq_atrdelta1846 = readrel1873->getIndex(ord1872, true);
      std::vector<u16> ord1874({0, 1, 2});
      slog::Relation* readrel1875 = db->getRelation("$seq_atr");
      $seq_atrindex1837 = readrel1875->getIndex(ord1874, false);
      std::vector<u16> ord1876({0, 1, 2});
      slog::Relation* readrel1877 = db->getRelation("$seq_atr");
      $seq_atrdelta1847 = readrel1877->getIndex(ord1876, true);
      std::vector<u16> ord1878({0, 1, 2});
      slog::Relation* readrel1879 = db->getRelation("$seq_atr");
      $seq_atrindex1838 = readrel1879->getIndex(ord1878, false);
      std::vector<u16> ord1880({0, 1, 2});
      slog::Relation* readrel1881 = db->getRelation("$seq_atr");
      $seq_atrdelta1848 = readrel1881->getIndex(ord1880, true);
      std::vector<u16> ord1882({0, 1, 2});
      slog::Relation* readrel1883 = db->getRelation("$seq_atr");
      $seq_atrindex1839 = readrel1883->getIndex(ord1882, false);
      std::vector<u16> ord1884({0, 1, 2});
      slog::Relation* readrel1885 = db->getRelation("$seq_atr");
      $seq_atrdelta1849 = readrel1885->getIndex(ord1884, true);
      std::vector<u16> ord1886({0, 1, 2});
      slog::Relation* readrel1887 = db->getRelation("$seq_atr");
      $seq_atrindex1840 = readrel1887->getIndex(ord1886, false);
      std::vector<u16> ord1888({0, 1, 2});
      slog::Relation* readrel1889 = db->getRelation("$seq_atr");
      $seq_atrdelta1850 = readrel1889->getIndex(ord1888, true);
      std::vector<u16> ord1890({1, 0});
      slog::Relation* readrel1891 = db->getRelation("lst_len");
      lst_lenindex1841 = readrel1891->getIndex(ord1890, false);
      std::vector<u16> ord1892({0, 1});
      slog::Relation* readrel1893 = db->getRelation("lst_len_ans");
      lst_len_ansindex1842 = readrel1893->getIndex(ord1892, false);
  
    }
    ReadTask1851(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c209, v_c210, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1894) {
        u64 v_c19 = m1894[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1832, std::array<u64,3>{v_c207, v_c208, v_c19}, [&](const std::array<u64,3>& m1895) {
          slog::join_probe_old<3,3>($seq_atindex1833, $seq_atdelta1843, std::array<u64,3>{v_c211, v_c212, v_c19}, [&](const std::array<u64,3>& m1896) {
            slog::join_probe_old<3,3>($seq_atindex1834, $seq_atdelta1844, std::array<u64,3>{v_c213, v_c214, v_c19}, [&](const std::array<u64,3>& m1897) {
              slog::join_probe_old<3,3>($seq_atindex1835, $seq_atdelta1845, std::array<u64,3>{v_c215, v_c216, v_c19}, [&](const std::array<u64,3>& m1898) {
                slog::join_probe_old<3,3>($seq_atrindex1836, $seq_atrdelta1846, std::array<u64,3>{v_c217, v_c218, v_c19}, [&](const std::array<u64,3>& m1899) {
                  slog::join_probe_old<3,3>($seq_atrindex1837, $seq_atrdelta1847, std::array<u64,3>{v_c219, v_c220, v_c19}, [&](const std::array<u64,3>& m1900) {
                    slog::join_probe_old<3,3>($seq_atrindex1838, $seq_atrdelta1848, std::array<u64,3>{v_c221, v_c222, v_c19}, [&](const std::array<u64,3>& m1901) {
                      slog::join_probe_old<3,3>($seq_atrindex1839, $seq_atrdelta1849, std::array<u64,3>{v_c223, v_c224, v_c19}, [&](const std::array<u64,3>& m1902) {
                        slog::join_probe_old<3,3>($seq_atrindex1840, $seq_atrdelta1850, std::array<u64,3>{v_c225, v_c226, v_c19}, [&](const std::array<u64,3>& m1903) {
                          slog::join_probe<2,1>(lst_lenindex1841, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1904) {
                            u64 v_c227 = m1904[1];
                            slog::join_probe<2,1>(lst_len_ansindex1842, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1905) {
                              u64 v_c21 = m1905[1];
                              bool ok1906 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1906);
                              if (!ok1906) return;
                              u64 v_c277 = _prim_llen(db, v_c228);
                              if (v_c277 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c277) return;
                              bool ok1907 = true;
                              u64 v_c278 = _prim_lref(db, v_c228, v_c197, &ok1907);
                              if (!ok1907) return;
                              if (v_c198 != v_c278) return;
                              bool ok1908 = true;
                              u64 v_c279 = _prim_lref(db, v_c228, v_c199, &ok1908);
                              if (!ok1908) return;
                              if (v_c200 != v_c279) return;
                              bool ok1909 = true;
                              u64 v_c280 = _prim_lref(db, v_c228, v_c201, &ok1909);
                              if (!ok1909) return;
                              if (v_c202 != v_c280) return;
                              bool ok1910 = true;
                              u64 v_c281 = _prim_lref(db, v_c228, v_c203, &ok1910);
                              if (!ok1910) return;
                              if (v_c204 != v_c281) return;
                              bool ok1911 = true;
                              u64 v_c282 = _prim_lref(db, v_c228, v_c205, &ok1911);
                              if (!ok1911) return;
                              if (v_c206 != v_c282) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1851* _cont = new ReadTask1851(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1851(db,b), false);
  // (crule (pre (let _00024sqc9pje34 constef2d127de37b942baad06145) (let _00024sqc5B9935 const5feceb66ffc86f38d952786c) (let _00024sqc3O1S36 const6b86b273ff34fce19d6b804e) (let _00024sqc8pXv37 const6b86b273ff34fce19d6b804e) (let _00024sqc9wtF38 constd4735e3a265e16eee03f5971) (let _00024sqc1oTi39 constd4735e3a265e16eee03f5971) (let _00024sqc9Sb640 const4e07408562bedb8b60ce05c1) (let _00024sqc9clu41 const4e07408562bedb8b60ce05c1) (let _00024sqc4DIH42 const4b227777d4dd1fc61c6f884f) (let _00024sqc7pKA43 const4b227777d4dd1fc61c6f884f) (let _00024sqc8vwz44 constef2d127de37b942baad06145) (let _00024sqo0yVj46 const6b86b273ff34fce19d6b804e) (let _00024sqo93Qy45 const5feceb66ffc86f38d952786c) (let _00024sqo1V4o48 constd4735e3a265e16eee03f5971) (let _00024sqo5l8H47 const6b86b273ff34fce19d6b804e) (let _00024sqo56lA50 const4e07408562bedb8b60ce05c1) (let _00024sqo393o49 constd4735e3a265e16eee03f5971) (let _00024sqo3KgT52 const4b227777d4dd1fc61c6f884f) (let _00024sqo8kJi51 const4e07408562bedb8b60ce05c1) (let _00024sqo3KCS54 constef2d127de37b942baad06145) (let _00024sqo5J9L53 const4b227777d4dd1fc61c6f884f) (let _00024sqo8tqk56 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vjk55 const4b227777d4dd1fc61c6f884f) (let _00024sqo6djO58 constd4735e3a265e16eee03f5971) (let _00024sqo09C757 const4e07408562bedb8b60ce05c1) (let _00024sqo8FAE60 const4e07408562bedb8b60ce05c1) (let _00024sqo8D3459 constd4735e3a265e16eee03f5971) (let _00024sqo8ZNu62 const4b227777d4dd1fc61c6f884f) (let _00024sqo6tNG61 const6b86b273ff34fce19d6b804e) (let _00024sqo4sjI64 constef2d127de37b942baad06145) (let _00024sqo397q63 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo0yVj46 _00024sqo93Qy45 _00024seq0) (body (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo1V4o48 _00024sqo5l8H47 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo56lA50 _00024sqo393o49 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo3KgT52 _00024sqo8kJi51 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo3KCS54 _00024sqo5J9L53 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8tqk56 _00024sqo2Vjk55 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo6djO58 _00024sqo09C757 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8FAE60 _00024sqo8D3459 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8ZNu62 _00024sqo6tNG61 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4sjI64 _00024sqo397q63 _00024seq0) (join lst_len (1 0) 1 _00024seq0 __t6BI05) (join lst_len_ans (0 1) 1 __t6BI05 r) (letp _00024sql9VVQ32 (aslst _00024seq0)) (let chk965Q530 (llen _00024sql9VVQ32)) (eq _00024sqc9pje34 chk965Q530) (letp chk3Z2i531 (lref _00024sql9VVQ32 _00024sqc5B9935)) (eq _00024sqc3O1S36 chk3Z2i531) (letp chk8Jsx532 (lref _00024sql9VVQ32 _00024sqc8pXv37)) (eq _00024sqc9wtF38 chk8Jsx532) (letp chk2hhW533 (lref _00024sql9VVQ32 _00024sqc1oTi39)) (eq _00024sqc9Sb640 chk2hhW533) (letp chk0eLh534 (lref _00024sql9VVQ32 _00024sqc9clu41)) (eq _00024sqc4DIH42 chk0eLh534) (letp chk4UgJ535 (lref _00024sql9VVQ32 _00024sqc7pKA43)) (eq _00024sqc8vwz44 chk4UgJ535)) (head (emit n (0) r)) lst_ops.slog:15 #f)
  class ReadTask1932 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1912;  slog::Index** $seq_atindex1913;  slog::Index** $seq_atindex1914;  slog::Index** $seq_atindex1915;  slog::Index** $seq_atrindex1916;  slog::Index** $seq_atrindex1917;  slog::Index** $seq_atrindex1918;  slog::Index** $seq_atrindex1919;  slog::Index** $seq_atrindex1920;  slog::Index** lst_lenindex1921;  slog::Index** lst_len_ansindex1922;  slog::Index** $seq_atdelta1923;  slog::Index** $seq_atdelta1924;  slog::Index** $seq_atdelta1925;  slog::Index** $seq_atdelta1926;  slog::Index** $seq_atrdelta1927;  slog::Index** $seq_atrdelta1928;  slog::Index** $seq_atrdelta1929;  slog::Index** $seq_atrdelta1930;  slog::Index** $seq_atrdelta1931;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1933({0});
      slog::Relation* readrel1934 = db->getRelation("n");
      head_index[0] = readrel1934->getIndex(ord1933, false);
      std::vector<u16> ord1935({0, 1, 2});
      slog::Relation* readrel1936 = db->getRelation("$seq_at");
      driver_index = readrel1936->getIndex(ord1935, true);
      std::vector<u16> ord1937({0, 1, 2});
      slog::Relation* readrel1938 = db->getRelation("$seq_at");
      $seq_atindex1912 = readrel1938->getIndex(ord1937, false);
      std::vector<u16> ord1939({0, 1, 2});
      slog::Relation* readrel1940 = db->getRelation("$seq_at");
      $seq_atdelta1923 = readrel1940->getIndex(ord1939, true);
      std::vector<u16> ord1941({0, 1, 2});
      slog::Relation* readrel1942 = db->getRelation("$seq_at");
      $seq_atindex1913 = readrel1942->getIndex(ord1941, false);
      std::vector<u16> ord1943({0, 1, 2});
      slog::Relation* readrel1944 = db->getRelation("$seq_at");
      $seq_atdelta1924 = readrel1944->getIndex(ord1943, true);
      std::vector<u16> ord1945({0, 1, 2});
      slog::Relation* readrel1946 = db->getRelation("$seq_at");
      $seq_atindex1914 = readrel1946->getIndex(ord1945, false);
      std::vector<u16> ord1947({0, 1, 2});
      slog::Relation* readrel1948 = db->getRelation("$seq_at");
      $seq_atdelta1925 = readrel1948->getIndex(ord1947, true);
      std::vector<u16> ord1949({0, 1, 2});
      slog::Relation* readrel1950 = db->getRelation("$seq_at");
      $seq_atindex1915 = readrel1950->getIndex(ord1949, false);
      std::vector<u16> ord1951({0, 1, 2});
      slog::Relation* readrel1952 = db->getRelation("$seq_at");
      $seq_atdelta1926 = readrel1952->getIndex(ord1951, true);
      std::vector<u16> ord1953({0, 1, 2});
      slog::Relation* readrel1954 = db->getRelation("$seq_atr");
      $seq_atrindex1916 = readrel1954->getIndex(ord1953, false);
      std::vector<u16> ord1955({0, 1, 2});
      slog::Relation* readrel1956 = db->getRelation("$seq_atr");
      $seq_atrdelta1927 = readrel1956->getIndex(ord1955, true);
      std::vector<u16> ord1957({0, 1, 2});
      slog::Relation* readrel1958 = db->getRelation("$seq_atr");
      $seq_atrindex1917 = readrel1958->getIndex(ord1957, false);
      std::vector<u16> ord1959({0, 1, 2});
      slog::Relation* readrel1960 = db->getRelation("$seq_atr");
      $seq_atrdelta1928 = readrel1960->getIndex(ord1959, true);
      std::vector<u16> ord1961({0, 1, 2});
      slog::Relation* readrel1962 = db->getRelation("$seq_atr");
      $seq_atrindex1918 = readrel1962->getIndex(ord1961, false);
      std::vector<u16> ord1963({0, 1, 2});
      slog::Relation* readrel1964 = db->getRelation("$seq_atr");
      $seq_atrdelta1929 = readrel1964->getIndex(ord1963, true);
      std::vector<u16> ord1965({0, 1, 2});
      slog::Relation* readrel1966 = db->getRelation("$seq_atr");
      $seq_atrindex1919 = readrel1966->getIndex(ord1965, false);
      std::vector<u16> ord1967({0, 1, 2});
      slog::Relation* readrel1968 = db->getRelation("$seq_atr");
      $seq_atrdelta1930 = readrel1968->getIndex(ord1967, true);
      std::vector<u16> ord1969({0, 1, 2});
      slog::Relation* readrel1970 = db->getRelation("$seq_atr");
      $seq_atrindex1920 = readrel1970->getIndex(ord1969, false);
      std::vector<u16> ord1971({0, 1, 2});
      slog::Relation* readrel1972 = db->getRelation("$seq_atr");
      $seq_atrdelta1931 = readrel1972->getIndex(ord1971, true);
      std::vector<u16> ord1973({1, 0});
      slog::Relation* readrel1974 = db->getRelation("lst_len");
      lst_lenindex1921 = readrel1974->getIndex(ord1973, false);
      std::vector<u16> ord1975({0, 1});
      slog::Relation* readrel1976 = db->getRelation("lst_len_ans");
      lst_len_ansindex1922 = readrel1976->getIndex(ord1975, false);
  
    }
    ReadTask1932(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_constef2d127de37b942baad06145;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c203 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c204 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c205 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c206 = v_constef2d127de37b942baad06145;
      u64 v_c207 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c211 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c212 = v_constd4735e3a265e16eee03f5971;
      u64 v_c213 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c214 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c215 = v_constef2d127de37b942baad06145;
      u64 v_c216 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c217 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c218 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c219 = v_constd4735e3a265e16eee03f5971;
      u64 v_c220 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c221 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c222 = v_constd4735e3a265e16eee03f5971;
      u64 v_c223 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c224 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c225 = v_constef2d127de37b942baad06145;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c207, v_c208, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1977) {
        u64 v_c19 = m1977[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex1912, $seq_atdelta1923, std::array<u64,3>{v_c209, v_c210, v_c19}, [&](const std::array<u64,3>& m1978) {
          slog::join_probe_old<3,3>($seq_atindex1913, $seq_atdelta1924, std::array<u64,3>{v_c211, v_c212, v_c19}, [&](const std::array<u64,3>& m1979) {
            slog::join_probe_old<3,3>($seq_atindex1914, $seq_atdelta1925, std::array<u64,3>{v_c213, v_c214, v_c19}, [&](const std::array<u64,3>& m1980) {
              slog::join_probe_old<3,3>($seq_atindex1915, $seq_atdelta1926, std::array<u64,3>{v_c215, v_c216, v_c19}, [&](const std::array<u64,3>& m1981) {
                slog::join_probe_old<3,3>($seq_atrindex1916, $seq_atrdelta1927, std::array<u64,3>{v_c217, v_c218, v_c19}, [&](const std::array<u64,3>& m1982) {
                  slog::join_probe_old<3,3>($seq_atrindex1917, $seq_atrdelta1928, std::array<u64,3>{v_c219, v_c220, v_c19}, [&](const std::array<u64,3>& m1983) {
                    slog::join_probe_old<3,3>($seq_atrindex1918, $seq_atrdelta1929, std::array<u64,3>{v_c221, v_c222, v_c19}, [&](const std::array<u64,3>& m1984) {
                      slog::join_probe_old<3,3>($seq_atrindex1919, $seq_atrdelta1930, std::array<u64,3>{v_c223, v_c224, v_c19}, [&](const std::array<u64,3>& m1985) {
                        slog::join_probe_old<3,3>($seq_atrindex1920, $seq_atrdelta1931, std::array<u64,3>{v_c225, v_c226, v_c19}, [&](const std::array<u64,3>& m1986) {
                          slog::join_probe<2,1>(lst_lenindex1921, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1987) {
                            u64 v_c227 = m1987[1];
                            slog::join_probe<2,1>(lst_len_ansindex1922, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1988) {
                              u64 v_c21 = m1988[1];
                              bool ok1989 = true;
                              u64 v_c228 = _prim_aslst(db, v_c19, &ok1989);
                              if (!ok1989) return;
                              u64 v_c283 = _prim_llen(db, v_c228);
                              if (v_c283 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:15"); return; }
                              if (v_c196 != v_c283) return;
                              bool ok1990 = true;
                              u64 v_c284 = _prim_lref(db, v_c228, v_c197, &ok1990);
                              if (!ok1990) return;
                              if (v_c198 != v_c284) return;
                              bool ok1991 = true;
                              u64 v_c285 = _prim_lref(db, v_c228, v_c199, &ok1991);
                              if (!ok1991) return;
                              if (v_c200 != v_c285) return;
                              bool ok1992 = true;
                              u64 v_c286 = _prim_lref(db, v_c228, v_c201, &ok1992);
                              if (!ok1992) return;
                              if (v_c202 != v_c286) return;
                              bool ok1993 = true;
                              u64 v_c287 = _prim_lref(db, v_c228, v_c203, &ok1993);
                              if (!ok1993) return;
                              if (v_c204 != v_c287) return;
                              bool ok1994 = true;
                              u64 v_c288 = _prim_lref(db, v_c228, v_c205, &ok1994);
                              if (!ok1994) return;
                              if (v_c206 != v_c288) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                            });
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:15", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1932* _cont = new ReadTask1932(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1932(db,b), false);
  // (crule (pre (let __tconst3Eu626 const7902699be42c8a8e46fbbb45) (let _00024sqc8qNr108 const4e07408562bedb8b60ce05c1) (let _00024sqc1Q1F109 const5feceb66ffc86f38d952786c) (let _00024sqc3i9t110 constef2d127de37b942baad06145) (let _00024sqc8LlS111 const6b86b273ff34fce19d6b804e) (let _00024sqc8pMe112 conste7f6c011776e8db7cd330b54) (let _00024sqc6DNO113 constd4735e3a265e16eee03f5971) (let _00024sqc1lbp114 const7902699be42c8a8e46fbbb45) (let _00024sqo8FLo116 constef2d127de37b942baad06145) (let _00024sqo5VHI115 const5feceb66ffc86f38d952786c) (let _00024sqo818G118 conste7f6c011776e8db7cd330b54) (let _00024sqo21NH117 const6b86b273ff34fce19d6b804e) (let _00024sqo7jL6120 const7902699be42c8a8e46fbbb45) (let _00024sqo6S5B119 constd4735e3a265e16eee03f5971) (let _00024sqo5alM122 constef2d127de37b942baad06145) (let _00024sqo2iA5121 constd4735e3a265e16eee03f5971) (let _00024sqo2vUW124 conste7f6c011776e8db7cd330b54) (let _00024sqo7jm3123 const6b86b273ff34fce19d6b804e) (let _00024sqo9y05126 const7902699be42c8a8e46fbbb45) (let _00024sqo9l2D125 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo9y05126 _00024sqo9l2D125 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8FLo116 _00024sqo5VHI115 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo818G118 _00024sqo21NH117 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo7jL6120 _00024sqo6S5B119 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5alM122 _00024sqo2iA5121 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo2vUW124 _00024sqo7jm3123 _00024seq0) (join lst_member (1 2 0) 2 _00024seq0 __tconst3Eu626 __t1vjT27) (join lst_member_ans (0 1) 1 __t1vjT27 r) (letp _00024sql3AAV106 (aslst _00024seq0)) (let chk3QgK526 (llen _00024sql3AAV106)) (eq _00024sqc8qNr108 chk3QgK526) (letp chk0er8527 (lref _00024sql3AAV106 _00024sqc1Q1F109)) (eq _00024sqc3i9t110 chk0er8527) (letp chk6Pmo528 (lref _00024sql3AAV106 _00024sqc8LlS111)) (eq _00024sqc8pMe112 chk6Pmo528) (letp chk2BVj529 (lref _00024sql3AAV106 _00024sqc6DNO113)) (eq _00024sqc1lbp114 chk2BVj529)) (head (emit has7 (0) r)) lst_ops.slog:14 #f)
  class ReadTask2002 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1995;  slog::Index** $seq_atindex1996;  slog::Index** $seq_atindex1997;  slog::Index** $seq_atrindex1998;  slog::Index** $seq_atrindex1999;  slog::Index** lst_memberindex2000;  slog::Index** lst_member_ansindex2001;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("has7");
      std::vector<u16> ord2003({0});
      slog::Relation* readrel2004 = db->getRelation("has7");
      head_index[0] = readrel2004->getIndex(ord2003, false);
      std::vector<u16> ord2005({0, 1, 2});
      slog::Relation* readrel2006 = db->getRelation("$seq_atr");
      driver_index = readrel2006->getIndex(ord2005, true);
      std::vector<u16> ord2007({0, 1, 2});
      slog::Relation* readrel2008 = db->getRelation("$seq_at");
      $seq_atindex1995 = readrel2008->getIndex(ord2007, false);
      std::vector<u16> ord2009({0, 1, 2});
      slog::Relation* readrel2010 = db->getRelation("$seq_at");
      $seq_atindex1996 = readrel2010->getIndex(ord2009, false);
      std::vector<u16> ord2011({0, 1, 2});
      slog::Relation* readrel2012 = db->getRelation("$seq_at");
      $seq_atindex1997 = readrel2012->getIndex(ord2011, false);
      std::vector<u16> ord2013({0, 1, 2});
      slog::Relation* readrel2014 = db->getRelation("$seq_atr");
      $seq_atrindex1998 = readrel2014->getIndex(ord2013, false);
      std::vector<u16> ord2015({0, 1, 2});
      slog::Relation* readrel2016 = db->getRelation("$seq_atr");
      $seq_atrindex1999 = readrel2016->getIndex(ord2015, false);
      std::vector<u16> ord2017({1, 2, 0});
      slog::Relation* readrel2018 = db->getRelation("lst_member");
      lst_memberindex2000 = readrel2018->getIndex(ord2017, false);
      std::vector<u16> ord2019({0, 1});
      slog::Relation* readrel2020 = db->getRelation("lst_member_ans");
      lst_member_ansindex2001 = readrel2020->getIndex(ord2019, false);
  
    }
    ReadTask2002(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c289 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c290 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c291 = v_const5feceb66ffc86f38d952786c;
      u64 v_c292 = v_constef2d127de37b942baad06145;
      u64 v_c293 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c294 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c295 = v_constd4735e3a265e16eee03f5971;
      u64 v_c296 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c297 = v_constef2d127de37b942baad06145;
      u64 v_c298 = v_const5feceb66ffc86f38d952786c;
      u64 v_c299 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c300 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c301 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c302 = v_constd4735e3a265e16eee03f5971;
      u64 v_c303 = v_constef2d127de37b942baad06145;
      u64 v_c304 = v_constd4735e3a265e16eee03f5971;
      u64 v_c305 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c306 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c307 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c308 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c307, v_c308, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m2021) {
        u64 v_c19 = m2021[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1995, std::array<u64,3>{v_c297, v_c298, v_c19}, [&](const std::array<u64,3>& m2022) {
          slog::join_probe<3,3>($seq_atindex1996, std::array<u64,3>{v_c299, v_c300, v_c19}, [&](const std::array<u64,3>& m2023) {
            slog::join_probe<3,3>($seq_atindex1997, std::array<u64,3>{v_c301, v_c302, v_c19}, [&](const std::array<u64,3>& m2024) {
              slog::join_probe<3,3>($seq_atrindex1998, std::array<u64,3>{v_c303, v_c304, v_c19}, [&](const std::array<u64,3>& m2025) {
                slog::join_probe<3,3>($seq_atrindex1999, std::array<u64,3>{v_c305, v_c306, v_c19}, [&](const std::array<u64,3>& m2026) {
                  slog::join_probe<3,2>(lst_memberindex2000, std::array<u64,3>{v_c19, v_c289, 0}, [&](const std::array<u64,3>& m2027) {
                    u64 v_c309 = m2027[2];
                    slog::join_probe<2,1>(lst_member_ansindex2001, std::array<u64,2>{v_c309, 0}, [&](const std::array<u64,2>& m2028) {
                      u64 v_c21 = m2028[1];
                      bool ok2029 = true;
                      u64 v_c310 = _prim_aslst(db, v_c19, &ok2029);
                      if (!ok2029) return;
                      u64 v_c311 = _prim_llen(db, v_c310);
                      if (v_c311 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:14"); return; }
                      if (v_c290 != v_c311) return;
                      bool ok2030 = true;
                      u64 v_c312 = _prim_lref(db, v_c310, v_c291, &ok2030);
                      if (!ok2030) return;
                      if (v_c292 != v_c312) return;
                      bool ok2031 = true;
                      u64 v_c313 = _prim_lref(db, v_c310, v_c293, &ok2031);
                      if (!ok2031) return;
                      if (v_c294 != v_c313) return;
                      bool ok2032 = true;
                      u64 v_c314 = _prim_lref(db, v_c310, v_c295, &ok2032);
                      if (!ok2032) return;
                      if (v_c296 != v_c314) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:14", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask2002* _cont = new ReadTask2002(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2002(db,b), false);
  // (crule (pre (let __tconst3Eu626 const7902699be42c8a8e46fbbb45) (let _00024sqc8qNr108 const4e07408562bedb8b60ce05c1) (let _00024sqc1Q1F109 const5feceb66ffc86f38d952786c) (let _00024sqc3i9t110 constef2d127de37b942baad06145) (let _00024sqc8LlS111 const6b86b273ff34fce19d6b804e) (let _00024sqc8pMe112 conste7f6c011776e8db7cd330b54) (let _00024sqc6DNO113 constd4735e3a265e16eee03f5971) (let _00024sqc1lbp114 const7902699be42c8a8e46fbbb45) (let _00024sqo8FLo116 constef2d127de37b942baad06145) (let _00024sqo5VHI115 const5feceb66ffc86f38d952786c) (let _00024sqo818G118 conste7f6c011776e8db7cd330b54) (let _00024sqo21NH117 const6b86b273ff34fce19d6b804e) (let _00024sqo7jL6120 const7902699be42c8a8e46fbbb45) (let _00024sqo6S5B119 constd4735e3a265e16eee03f5971) (let _00024sqo5alM122 constef2d127de37b942baad06145) (let _00024sqo2iA5121 constd4735e3a265e16eee03f5971) (let _00024sqo2vUW124 conste7f6c011776e8db7cd330b54) (let _00024sqo7jm3123 const6b86b273ff34fce19d6b804e) (let _00024sqo9y05126 const7902699be42c8a8e46fbbb45) (let _00024sqo9l2D125 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo2vUW124 _00024sqo7jm3123 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8FLo116 _00024sqo5VHI115 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo818G118 _00024sqo21NH117 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo7jL6120 _00024sqo6S5B119 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo5alM122 _00024sqo2iA5121 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9y05126 _00024sqo9l2D125 _00024seq0) (join lst_member (1 2 0) 2 _00024seq0 __tconst3Eu626 __t1vjT27) (join lst_member_ans (0 1) 1 __t1vjT27 r) (letp _00024sql3AAV106 (aslst _00024seq0)) (let chk02dh522 (llen _00024sql3AAV106)) (eq _00024sqc8qNr108 chk02dh522) (letp chk0dXr523 (lref _00024sql3AAV106 _00024sqc1Q1F109)) (eq _00024sqc3i9t110 chk0dXr523) (letp chk9lzV524 (lref _00024sql3AAV106 _00024sqc8LlS111)) (eq _00024sqc8pMe112 chk9lzV524) (letp chk8mV6525 (lref _00024sql3AAV106 _00024sqc6DNO113)) (eq _00024sqc1lbp114 chk8mV6525)) (head (emit has7 (0) r)) lst_ops.slog:14 #f)
  class ReadTask2041 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex2033;  slog::Index** $seq_atindex2034;  slog::Index** $seq_atindex2035;  slog::Index** $seq_atrindex2036;  slog::Index** $seq_atrindex2037;  slog::Index** lst_memberindex2038;  slog::Index** lst_member_ansindex2039;  slog::Index** $seq_atrdelta2040;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("has7");
      std::vector<u16> ord2042({0});
      slog::Relation* readrel2043 = db->getRelation("has7");
      head_index[0] = readrel2043->getIndex(ord2042, false);
      std::vector<u16> ord2044({0, 1, 2});
      slog::Relation* readrel2045 = db->getRelation("$seq_atr");
      driver_index = readrel2045->getIndex(ord2044, true);
      std::vector<u16> ord2046({0, 1, 2});
      slog::Relation* readrel2047 = db->getRelation("$seq_at");
      $seq_atindex2033 = readrel2047->getIndex(ord2046, false);
      std::vector<u16> ord2048({0, 1, 2});
      slog::Relation* readrel2049 = db->getRelation("$seq_at");
      $seq_atindex2034 = readrel2049->getIndex(ord2048, false);
      std::vector<u16> ord2050({0, 1, 2});
      slog::Relation* readrel2051 = db->getRelation("$seq_at");
      $seq_atindex2035 = readrel2051->getIndex(ord2050, false);
      std::vector<u16> ord2052({0, 1, 2});
      slog::Relation* readrel2053 = db->getRelation("$seq_atr");
      $seq_atrindex2036 = readrel2053->getIndex(ord2052, false);
      std::vector<u16> ord2054({0, 1, 2});
      slog::Relation* readrel2055 = db->getRelation("$seq_atr");
      $seq_atrindex2037 = readrel2055->getIndex(ord2054, false);
      std::vector<u16> ord2056({0, 1, 2});
      slog::Relation* readrel2057 = db->getRelation("$seq_atr");
      $seq_atrdelta2040 = readrel2057->getIndex(ord2056, true);
      std::vector<u16> ord2058({1, 2, 0});
      slog::Relation* readrel2059 = db->getRelation("lst_member");
      lst_memberindex2038 = readrel2059->getIndex(ord2058, false);
      std::vector<u16> ord2060({0, 1});
      slog::Relation* readrel2061 = db->getRelation("lst_member_ans");
      lst_member_ansindex2039 = readrel2061->getIndex(ord2060, false);
  
    }
    ReadTask2041(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c289 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c290 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c291 = v_const5feceb66ffc86f38d952786c;
      u64 v_c292 = v_constef2d127de37b942baad06145;
      u64 v_c293 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c294 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c295 = v_constd4735e3a265e16eee03f5971;
      u64 v_c296 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c297 = v_constef2d127de37b942baad06145;
      u64 v_c298 = v_const5feceb66ffc86f38d952786c;
      u64 v_c299 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c300 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c301 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c302 = v_constd4735e3a265e16eee03f5971;
      u64 v_c303 = v_constef2d127de37b942baad06145;
      u64 v_c304 = v_constd4735e3a265e16eee03f5971;
      u64 v_c305 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c306 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c307 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c308 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c305, v_c306, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m2062) {
        u64 v_c19 = m2062[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex2033, std::array<u64,3>{v_c297, v_c298, v_c19}, [&](const std::array<u64,3>& m2063) {
          slog::join_probe<3,3>($seq_atindex2034, std::array<u64,3>{v_c299, v_c300, v_c19}, [&](const std::array<u64,3>& m2064) {
            slog::join_probe<3,3>($seq_atindex2035, std::array<u64,3>{v_c301, v_c302, v_c19}, [&](const std::array<u64,3>& m2065) {
              slog::join_probe<3,3>($seq_atrindex2036, std::array<u64,3>{v_c303, v_c304, v_c19}, [&](const std::array<u64,3>& m2066) {
                slog::join_probe_old<3,3>($seq_atrindex2037, $seq_atrdelta2040, std::array<u64,3>{v_c307, v_c308, v_c19}, [&](const std::array<u64,3>& m2067) {
                  slog::join_probe<3,2>(lst_memberindex2038, std::array<u64,3>{v_c19, v_c289, 0}, [&](const std::array<u64,3>& m2068) {
                    u64 v_c309 = m2068[2];
                    slog::join_probe<2,1>(lst_member_ansindex2039, std::array<u64,2>{v_c309, 0}, [&](const std::array<u64,2>& m2069) {
                      u64 v_c21 = m2069[1];
                      bool ok2070 = true;
                      u64 v_c310 = _prim_aslst(db, v_c19, &ok2070);
                      if (!ok2070) return;
                      u64 v_c315 = _prim_llen(db, v_c310);
                      if (v_c315 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:14"); return; }
                      if (v_c290 != v_c315) return;
                      bool ok2071 = true;
                      u64 v_c316 = _prim_lref(db, v_c310, v_c291, &ok2071);
                      if (!ok2071) return;
                      if (v_c292 != v_c316) return;
                      bool ok2072 = true;
                      u64 v_c317 = _prim_lref(db, v_c310, v_c293, &ok2072);
                      if (!ok2072) return;
                      if (v_c294 != v_c317) return;
                      bool ok2073 = true;
                      u64 v_c318 = _prim_lref(db, v_c310, v_c295, &ok2073);
                      if (!ok2073) return;
                      if (v_c296 != v_c318) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:14", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask2041* _cont = new ReadTask2041(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2041(db,b), false);
  // (crule (pre (let __tconst3Eu626 const7902699be42c8a8e46fbbb45) (let _00024sqc8qNr108 const4e07408562bedb8b60ce05c1) (let _00024sqc1Q1F109 const5feceb66ffc86f38d952786c) (let _00024sqc3i9t110 constef2d127de37b942baad06145) (let _00024sqc8LlS111 const6b86b273ff34fce19d6b804e) (let _00024sqc8pMe112 conste7f6c011776e8db7cd330b54) (let _00024sqc6DNO113 constd4735e3a265e16eee03f5971) (let _00024sqc1lbp114 const7902699be42c8a8e46fbbb45) (let _00024sqo8FLo116 constef2d127de37b942baad06145) (let _00024sqo5VHI115 const5feceb66ffc86f38d952786c) (let _00024sqo818G118 conste7f6c011776e8db7cd330b54) (let _00024sqo21NH117 const6b86b273ff34fce19d6b804e) (let _00024sqo7jL6120 const7902699be42c8a8e46fbbb45) (let _00024sqo6S5B119 constd4735e3a265e16eee03f5971) (let _00024sqo5alM122 constef2d127de37b942baad06145) (let _00024sqo2iA5121 constd4735e3a265e16eee03f5971) (let _00024sqo2vUW124 conste7f6c011776e8db7cd330b54) (let _00024sqo7jm3123 const6b86b273ff34fce19d6b804e) (let _00024sqo9y05126 const7902699be42c8a8e46fbbb45) (let _00024sqo9l2D125 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo5alM122 _00024sqo2iA5121 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8FLo116 _00024sqo5VHI115 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo818G118 _00024sqo21NH117 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo7jL6120 _00024sqo6S5B119 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2vUW124 _00024sqo7jm3123 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9y05126 _00024sqo9l2D125 _00024seq0) (join lst_member (1 2 0) 2 _00024seq0 __tconst3Eu626 __t1vjT27) (join lst_member_ans (0 1) 1 __t1vjT27 r) (letp _00024sql3AAV106 (aslst _00024seq0)) (let chk38fL518 (llen _00024sql3AAV106)) (eq _00024sqc8qNr108 chk38fL518) (letp chk8g3j519 (lref _00024sql3AAV106 _00024sqc1Q1F109)) (eq _00024sqc3i9t110 chk8g3j519) (letp chk7wtb520 (lref _00024sql3AAV106 _00024sqc8LlS111)) (eq _00024sqc8pMe112 chk7wtb520) (letp chk0lsY521 (lref _00024sql3AAV106 _00024sqc6DNO113)) (eq _00024sqc1lbp114 chk0lsY521)) (head (emit has7 (0) r)) lst_ops.slog:14 #f)
  class ReadTask2083 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex2074;  slog::Index** $seq_atindex2075;  slog::Index** $seq_atindex2076;  slog::Index** $seq_atrindex2077;  slog::Index** $seq_atrindex2078;  slog::Index** lst_memberindex2079;  slog::Index** lst_member_ansindex2080;  slog::Index** $seq_atrdelta2081;  slog::Index** $seq_atrdelta2082;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("has7");
      std::vector<u16> ord2084({0});
      slog::Relation* readrel2085 = db->getRelation("has7");
      head_index[0] = readrel2085->getIndex(ord2084, false);
      std::vector<u16> ord2086({0, 1, 2});
      slog::Relation* readrel2087 = db->getRelation("$seq_atr");
      driver_index = readrel2087->getIndex(ord2086, true);
      std::vector<u16> ord2088({0, 1, 2});
      slog::Relation* readrel2089 = db->getRelation("$seq_at");
      $seq_atindex2074 = readrel2089->getIndex(ord2088, false);
      std::vector<u16> ord2090({0, 1, 2});
      slog::Relation* readrel2091 = db->getRelation("$seq_at");
      $seq_atindex2075 = readrel2091->getIndex(ord2090, false);
      std::vector<u16> ord2092({0, 1, 2});
      slog::Relation* readrel2093 = db->getRelation("$seq_at");
      $seq_atindex2076 = readrel2093->getIndex(ord2092, false);
      std::vector<u16> ord2094({0, 1, 2});
      slog::Relation* readrel2095 = db->getRelation("$seq_atr");
      $seq_atrindex2077 = readrel2095->getIndex(ord2094, false);
      std::vector<u16> ord2096({0, 1, 2});
      slog::Relation* readrel2097 = db->getRelation("$seq_atr");
      $seq_atrdelta2081 = readrel2097->getIndex(ord2096, true);
      std::vector<u16> ord2098({0, 1, 2});
      slog::Relation* readrel2099 = db->getRelation("$seq_atr");
      $seq_atrindex2078 = readrel2099->getIndex(ord2098, false);
      std::vector<u16> ord2100({0, 1, 2});
      slog::Relation* readrel2101 = db->getRelation("$seq_atr");
      $seq_atrdelta2082 = readrel2101->getIndex(ord2100, true);
      std::vector<u16> ord2102({1, 2, 0});
      slog::Relation* readrel2103 = db->getRelation("lst_member");
      lst_memberindex2079 = readrel2103->getIndex(ord2102, false);
      std::vector<u16> ord2104({0, 1});
      slog::Relation* readrel2105 = db->getRelation("lst_member_ans");
      lst_member_ansindex2080 = readrel2105->getIndex(ord2104, false);
  
    }
    ReadTask2083(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c289 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c290 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c291 = v_const5feceb66ffc86f38d952786c;
      u64 v_c292 = v_constef2d127de37b942baad06145;
      u64 v_c293 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c294 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c295 = v_constd4735e3a265e16eee03f5971;
      u64 v_c296 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c297 = v_constef2d127de37b942baad06145;
      u64 v_c298 = v_const5feceb66ffc86f38d952786c;
      u64 v_c299 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c300 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c301 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c302 = v_constd4735e3a265e16eee03f5971;
      u64 v_c303 = v_constef2d127de37b942baad06145;
      u64 v_c304 = v_constd4735e3a265e16eee03f5971;
      u64 v_c305 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c306 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c307 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c308 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c303, v_c304, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m2106) {
        u64 v_c19 = m2106[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex2074, std::array<u64,3>{v_c297, v_c298, v_c19}, [&](const std::array<u64,3>& m2107) {
          slog::join_probe<3,3>($seq_atindex2075, std::array<u64,3>{v_c299, v_c300, v_c19}, [&](const std::array<u64,3>& m2108) {
            slog::join_probe<3,3>($seq_atindex2076, std::array<u64,3>{v_c301, v_c302, v_c19}, [&](const std::array<u64,3>& m2109) {
              slog::join_probe_old<3,3>($seq_atrindex2077, $seq_atrdelta2081, std::array<u64,3>{v_c305, v_c306, v_c19}, [&](const std::array<u64,3>& m2110) {
                slog::join_probe_old<3,3>($seq_atrindex2078, $seq_atrdelta2082, std::array<u64,3>{v_c307, v_c308, v_c19}, [&](const std::array<u64,3>& m2111) {
                  slog::join_probe<3,2>(lst_memberindex2079, std::array<u64,3>{v_c19, v_c289, 0}, [&](const std::array<u64,3>& m2112) {
                    u64 v_c309 = m2112[2];
                    slog::join_probe<2,1>(lst_member_ansindex2080, std::array<u64,2>{v_c309, 0}, [&](const std::array<u64,2>& m2113) {
                      u64 v_c21 = m2113[1];
                      bool ok2114 = true;
                      u64 v_c310 = _prim_aslst(db, v_c19, &ok2114);
                      if (!ok2114) return;
                      u64 v_c319 = _prim_llen(db, v_c310);
                      if (v_c319 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:14"); return; }
                      if (v_c290 != v_c319) return;
                      bool ok2115 = true;
                      u64 v_c320 = _prim_lref(db, v_c310, v_c291, &ok2115);
                      if (!ok2115) return;
                      if (v_c292 != v_c320) return;
                      bool ok2116 = true;
                      u64 v_c321 = _prim_lref(db, v_c310, v_c293, &ok2116);
                      if (!ok2116) return;
                      if (v_c294 != v_c321) return;
                      bool ok2117 = true;
                      u64 v_c322 = _prim_lref(db, v_c310, v_c295, &ok2117);
                      if (!ok2117) return;
                      if (v_c296 != v_c322) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:14", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask2083* _cont = new ReadTask2083(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2083(db,b), false);
  // (crule (pre (let __tconst3Eu626 const7902699be42c8a8e46fbbb45) (let _00024sqc8qNr108 const4e07408562bedb8b60ce05c1) (let _00024sqc1Q1F109 const5feceb66ffc86f38d952786c) (let _00024sqc3i9t110 constef2d127de37b942baad06145) (let _00024sqc8LlS111 const6b86b273ff34fce19d6b804e) (let _00024sqc8pMe112 conste7f6c011776e8db7cd330b54) (let _00024sqc6DNO113 constd4735e3a265e16eee03f5971) (let _00024sqc1lbp114 const7902699be42c8a8e46fbbb45) (let _00024sqo8FLo116 constef2d127de37b942baad06145) (let _00024sqo5VHI115 const5feceb66ffc86f38d952786c) (let _00024sqo818G118 conste7f6c011776e8db7cd330b54) (let _00024sqo21NH117 const6b86b273ff34fce19d6b804e) (let _00024sqo7jL6120 const7902699be42c8a8e46fbbb45) (let _00024sqo6S5B119 constd4735e3a265e16eee03f5971) (let _00024sqo5alM122 constef2d127de37b942baad06145) (let _00024sqo2iA5121 constd4735e3a265e16eee03f5971) (let _00024sqo2vUW124 conste7f6c011776e8db7cd330b54) (let _00024sqo7jm3123 const6b86b273ff34fce19d6b804e) (let _00024sqo9y05126 const7902699be42c8a8e46fbbb45) (let _00024sqo9l2D125 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo7jL6120 _00024sqo6S5B119 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8FLo116 _00024sqo5VHI115 _00024seq0) (join $seq_at (0 1 2) 3 _00024sqo818G118 _00024sqo21NH117 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5alM122 _00024sqo2iA5121 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2vUW124 _00024sqo7jm3123 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9y05126 _00024sqo9l2D125 _00024seq0) (join lst_member (1 2 0) 2 _00024seq0 __tconst3Eu626 __t1vjT27) (join lst_member_ans (0 1) 1 __t1vjT27 r) (letp _00024sql3AAV106 (aslst _00024seq0)) (let chk7OAZ514 (llen _00024sql3AAV106)) (eq _00024sqc8qNr108 chk7OAZ514) (letp chk3QBf515 (lref _00024sql3AAV106 _00024sqc1Q1F109)) (eq _00024sqc3i9t110 chk3QBf515) (letp chk0jKa516 (lref _00024sql3AAV106 _00024sqc8LlS111)) (eq _00024sqc8pMe112 chk0jKa516) (letp chk71le517 (lref _00024sql3AAV106 _00024sqc6DNO113)) (eq _00024sqc1lbp114 chk71le517)) (head (emit has7 (0) r)) lst_ops.slog:14 #f)
  class ReadTask2128 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex2118;  slog::Index** $seq_atindex2119;  slog::Index** $seq_atrindex2120;  slog::Index** $seq_atrindex2121;  slog::Index** $seq_atrindex2122;  slog::Index** lst_memberindex2123;  slog::Index** lst_member_ansindex2124;  slog::Index** $seq_atrdelta2125;  slog::Index** $seq_atrdelta2126;  slog::Index** $seq_atrdelta2127;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("has7");
      std::vector<u16> ord2129({0});
      slog::Relation* readrel2130 = db->getRelation("has7");
      head_index[0] = readrel2130->getIndex(ord2129, false);
      std::vector<u16> ord2131({0, 1, 2});
      slog::Relation* readrel2132 = db->getRelation("$seq_at");
      driver_index = readrel2132->getIndex(ord2131, true);
      std::vector<u16> ord2133({0, 1, 2});
      slog::Relation* readrel2134 = db->getRelation("$seq_at");
      $seq_atindex2118 = readrel2134->getIndex(ord2133, false);
      std::vector<u16> ord2135({0, 1, 2});
      slog::Relation* readrel2136 = db->getRelation("$seq_at");
      $seq_atindex2119 = readrel2136->getIndex(ord2135, false);
      std::vector<u16> ord2137({0, 1, 2});
      slog::Relation* readrel2138 = db->getRelation("$seq_atr");
      $seq_atrindex2120 = readrel2138->getIndex(ord2137, false);
      std::vector<u16> ord2139({0, 1, 2});
      slog::Relation* readrel2140 = db->getRelation("$seq_atr");
      $seq_atrdelta2125 = readrel2140->getIndex(ord2139, true);
      std::vector<u16> ord2141({0, 1, 2});
      slog::Relation* readrel2142 = db->getRelation("$seq_atr");
      $seq_atrindex2121 = readrel2142->getIndex(ord2141, false);
      std::vector<u16> ord2143({0, 1, 2});
      slog::Relation* readrel2144 = db->getRelation("$seq_atr");
      $seq_atrdelta2126 = readrel2144->getIndex(ord2143, true);
      std::vector<u16> ord2145({0, 1, 2});
      slog::Relation* readrel2146 = db->getRelation("$seq_atr");
      $seq_atrindex2122 = readrel2146->getIndex(ord2145, false);
      std::vector<u16> ord2147({0, 1, 2});
      slog::Relation* readrel2148 = db->getRelation("$seq_atr");
      $seq_atrdelta2127 = readrel2148->getIndex(ord2147, true);
      std::vector<u16> ord2149({1, 2, 0});
      slog::Relation* readrel2150 = db->getRelation("lst_member");
      lst_memberindex2123 = readrel2150->getIndex(ord2149, false);
      std::vector<u16> ord2151({0, 1});
      slog::Relation* readrel2152 = db->getRelation("lst_member_ans");
      lst_member_ansindex2124 = readrel2152->getIndex(ord2151, false);
  
    }
    ReadTask2128(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c289 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c290 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c291 = v_const5feceb66ffc86f38d952786c;
      u64 v_c292 = v_constef2d127de37b942baad06145;
      u64 v_c293 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c294 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c295 = v_constd4735e3a265e16eee03f5971;
      u64 v_c296 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c297 = v_constef2d127de37b942baad06145;
      u64 v_c298 = v_const5feceb66ffc86f38d952786c;
      u64 v_c299 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c300 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c301 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c302 = v_constd4735e3a265e16eee03f5971;
      u64 v_c303 = v_constef2d127de37b942baad06145;
      u64 v_c304 = v_constd4735e3a265e16eee03f5971;
      u64 v_c305 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c306 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c307 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c308 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c301, v_c302, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m2153) {
        u64 v_c19 = m2153[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex2118, std::array<u64,3>{v_c297, v_c298, v_c19}, [&](const std::array<u64,3>& m2154) {
          slog::join_probe<3,3>($seq_atindex2119, std::array<u64,3>{v_c299, v_c300, v_c19}, [&](const std::array<u64,3>& m2155) {
            slog::join_probe_old<3,3>($seq_atrindex2120, $seq_atrdelta2125, std::array<u64,3>{v_c303, v_c304, v_c19}, [&](const std::array<u64,3>& m2156) {
              slog::join_probe_old<3,3>($seq_atrindex2121, $seq_atrdelta2126, std::array<u64,3>{v_c305, v_c306, v_c19}, [&](const std::array<u64,3>& m2157) {
                slog::join_probe_old<3,3>($seq_atrindex2122, $seq_atrdelta2127, std::array<u64,3>{v_c307, v_c308, v_c19}, [&](const std::array<u64,3>& m2158) {
                  slog::join_probe<3,2>(lst_memberindex2123, std::array<u64,3>{v_c19, v_c289, 0}, [&](const std::array<u64,3>& m2159) {
                    u64 v_c309 = m2159[2];
                    slog::join_probe<2,1>(lst_member_ansindex2124, std::array<u64,2>{v_c309, 0}, [&](const std::array<u64,2>& m2160) {
                      u64 v_c21 = m2160[1];
                      bool ok2161 = true;
                      u64 v_c310 = _prim_aslst(db, v_c19, &ok2161);
                      if (!ok2161) return;
                      u64 v_c323 = _prim_llen(db, v_c310);
                      if (v_c323 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:14"); return; }
                      if (v_c290 != v_c323) return;
                      bool ok2162 = true;
                      u64 v_c324 = _prim_lref(db, v_c310, v_c291, &ok2162);
                      if (!ok2162) return;
                      if (v_c292 != v_c324) return;
                      bool ok2163 = true;
                      u64 v_c325 = _prim_lref(db, v_c310, v_c293, &ok2163);
                      if (!ok2163) return;
                      if (v_c294 != v_c325) return;
                      bool ok2164 = true;
                      u64 v_c326 = _prim_lref(db, v_c310, v_c295, &ok2164);
                      if (!ok2164) return;
                      if (v_c296 != v_c326) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:14", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask2128* _cont = new ReadTask2128(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2128(db,b), false);
  // (crule (pre (let __tconst3Eu626 const7902699be42c8a8e46fbbb45) (let _00024sqc8qNr108 const4e07408562bedb8b60ce05c1) (let _00024sqc1Q1F109 const5feceb66ffc86f38d952786c) (let _00024sqc3i9t110 constef2d127de37b942baad06145) (let _00024sqc8LlS111 const6b86b273ff34fce19d6b804e) (let _00024sqc8pMe112 conste7f6c011776e8db7cd330b54) (let _00024sqc6DNO113 constd4735e3a265e16eee03f5971) (let _00024sqc1lbp114 const7902699be42c8a8e46fbbb45) (let _00024sqo8FLo116 constef2d127de37b942baad06145) (let _00024sqo5VHI115 const5feceb66ffc86f38d952786c) (let _00024sqo818G118 conste7f6c011776e8db7cd330b54) (let _00024sqo21NH117 const6b86b273ff34fce19d6b804e) (let _00024sqo7jL6120 const7902699be42c8a8e46fbbb45) (let _00024sqo6S5B119 constd4735e3a265e16eee03f5971) (let _00024sqo5alM122 constef2d127de37b942baad06145) (let _00024sqo2iA5121 constd4735e3a265e16eee03f5971) (let _00024sqo2vUW124 conste7f6c011776e8db7cd330b54) (let _00024sqo7jm3123 const6b86b273ff34fce19d6b804e) (let _00024sqo9y05126 const7902699be42c8a8e46fbbb45) (let _00024sqo9l2D125 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo818G118 _00024sqo21NH117 _00024seq0) (body (join $seq_at (0 1 2) 3 _00024sqo8FLo116 _00024sqo5VHI115 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo7jL6120 _00024sqo6S5B119 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5alM122 _00024sqo2iA5121 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2vUW124 _00024sqo7jm3123 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9y05126 _00024sqo9l2D125 _00024seq0) (join lst_member (1 2 0) 2 _00024seq0 __tconst3Eu626 __t1vjT27) (join lst_member_ans (0 1) 1 __t1vjT27 r) (letp _00024sql3AAV106 (aslst _00024seq0)) (let chk60Fg510 (llen _00024sql3AAV106)) (eq _00024sqc8qNr108 chk60Fg510) (letp chk8bMP511 (lref _00024sql3AAV106 _00024sqc1Q1F109)) (eq _00024sqc3i9t110 chk8bMP511) (letp chk1xcP512 (lref _00024sql3AAV106 _00024sqc8LlS111)) (eq _00024sqc8pMe112 chk1xcP512) (letp chk9zif513 (lref _00024sql3AAV106 _00024sqc6DNO113)) (eq _00024sqc1lbp114 chk9zif513)) (head (emit has7 (0) r)) lst_ops.slog:14 #f)
  class ReadTask2176 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex2165;  slog::Index** $seq_atindex2166;  slog::Index** $seq_atrindex2167;  slog::Index** $seq_atrindex2168;  slog::Index** $seq_atrindex2169;  slog::Index** lst_memberindex2170;  slog::Index** lst_member_ansindex2171;  slog::Index** $seq_atdelta2172;  slog::Index** $seq_atrdelta2173;  slog::Index** $seq_atrdelta2174;  slog::Index** $seq_atrdelta2175;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("has7");
      std::vector<u16> ord2177({0});
      slog::Relation* readrel2178 = db->getRelation("has7");
      head_index[0] = readrel2178->getIndex(ord2177, false);
      std::vector<u16> ord2179({0, 1, 2});
      slog::Relation* readrel2180 = db->getRelation("$seq_at");
      driver_index = readrel2180->getIndex(ord2179, true);
      std::vector<u16> ord2181({0, 1, 2});
      slog::Relation* readrel2182 = db->getRelation("$seq_at");
      $seq_atindex2165 = readrel2182->getIndex(ord2181, false);
      std::vector<u16> ord2183({0, 1, 2});
      slog::Relation* readrel2184 = db->getRelation("$seq_at");
      $seq_atindex2166 = readrel2184->getIndex(ord2183, false);
      std::vector<u16> ord2185({0, 1, 2});
      slog::Relation* readrel2186 = db->getRelation("$seq_at");
      $seq_atdelta2172 = readrel2186->getIndex(ord2185, true);
      std::vector<u16> ord2187({0, 1, 2});
      slog::Relation* readrel2188 = db->getRelation("$seq_atr");
      $seq_atrindex2167 = readrel2188->getIndex(ord2187, false);
      std::vector<u16> ord2189({0, 1, 2});
      slog::Relation* readrel2190 = db->getRelation("$seq_atr");
      $seq_atrdelta2173 = readrel2190->getIndex(ord2189, true);
      std::vector<u16> ord2191({0, 1, 2});
      slog::Relation* readrel2192 = db->getRelation("$seq_atr");
      $seq_atrindex2168 = readrel2192->getIndex(ord2191, false);
      std::vector<u16> ord2193({0, 1, 2});
      slog::Relation* readrel2194 = db->getRelation("$seq_atr");
      $seq_atrdelta2174 = readrel2194->getIndex(ord2193, true);
      std::vector<u16> ord2195({0, 1, 2});
      slog::Relation* readrel2196 = db->getRelation("$seq_atr");
      $seq_atrindex2169 = readrel2196->getIndex(ord2195, false);
      std::vector<u16> ord2197({0, 1, 2});
      slog::Relation* readrel2198 = db->getRelation("$seq_atr");
      $seq_atrdelta2175 = readrel2198->getIndex(ord2197, true);
      std::vector<u16> ord2199({1, 2, 0});
      slog::Relation* readrel2200 = db->getRelation("lst_member");
      lst_memberindex2170 = readrel2200->getIndex(ord2199, false);
      std::vector<u16> ord2201({0, 1});
      slog::Relation* readrel2202 = db->getRelation("lst_member_ans");
      lst_member_ansindex2171 = readrel2202->getIndex(ord2201, false);
  
    }
    ReadTask2176(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c289 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c290 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c291 = v_const5feceb66ffc86f38d952786c;
      u64 v_c292 = v_constef2d127de37b942baad06145;
      u64 v_c293 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c294 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c295 = v_constd4735e3a265e16eee03f5971;
      u64 v_c296 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c297 = v_constef2d127de37b942baad06145;
      u64 v_c298 = v_const5feceb66ffc86f38d952786c;
      u64 v_c299 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c300 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c301 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c302 = v_constd4735e3a265e16eee03f5971;
      u64 v_c303 = v_constef2d127de37b942baad06145;
      u64 v_c304 = v_constd4735e3a265e16eee03f5971;
      u64 v_c305 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c306 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c307 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c308 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c299, v_c300, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m2203) {
        u64 v_c19 = m2203[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex2165, std::array<u64,3>{v_c297, v_c298, v_c19}, [&](const std::array<u64,3>& m2204) {
          slog::join_probe_old<3,3>($seq_atindex2166, $seq_atdelta2172, std::array<u64,3>{v_c301, v_c302, v_c19}, [&](const std::array<u64,3>& m2205) {
            slog::join_probe_old<3,3>($seq_atrindex2167, $seq_atrdelta2173, std::array<u64,3>{v_c303, v_c304, v_c19}, [&](const std::array<u64,3>& m2206) {
              slog::join_probe_old<3,3>($seq_atrindex2168, $seq_atrdelta2174, std::array<u64,3>{v_c305, v_c306, v_c19}, [&](const std::array<u64,3>& m2207) {
                slog::join_probe_old<3,3>($seq_atrindex2169, $seq_atrdelta2175, std::array<u64,3>{v_c307, v_c308, v_c19}, [&](const std::array<u64,3>& m2208) {
                  slog::join_probe<3,2>(lst_memberindex2170, std::array<u64,3>{v_c19, v_c289, 0}, [&](const std::array<u64,3>& m2209) {
                    u64 v_c309 = m2209[2];
                    slog::join_probe<2,1>(lst_member_ansindex2171, std::array<u64,2>{v_c309, 0}, [&](const std::array<u64,2>& m2210) {
                      u64 v_c21 = m2210[1];
                      bool ok2211 = true;
                      u64 v_c310 = _prim_aslst(db, v_c19, &ok2211);
                      if (!ok2211) return;
                      u64 v_c327 = _prim_llen(db, v_c310);
                      if (v_c327 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:14"); return; }
                      if (v_c290 != v_c327) return;
                      bool ok2212 = true;
                      u64 v_c328 = _prim_lref(db, v_c310, v_c291, &ok2212);
                      if (!ok2212) return;
                      if (v_c292 != v_c328) return;
                      bool ok2213 = true;
                      u64 v_c329 = _prim_lref(db, v_c310, v_c293, &ok2213);
                      if (!ok2213) return;
                      if (v_c294 != v_c329) return;
                      bool ok2214 = true;
                      u64 v_c330 = _prim_lref(db, v_c310, v_c295, &ok2214);
                      if (!ok2214) return;
                      if (v_c296 != v_c330) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:14", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask2176* _cont = new ReadTask2176(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2176(db,b), false);
  // (crule (pre (let __tconst3Eu626 const7902699be42c8a8e46fbbb45) (let _00024sqc8qNr108 const4e07408562bedb8b60ce05c1) (let _00024sqc1Q1F109 const5feceb66ffc86f38d952786c) (let _00024sqc3i9t110 constef2d127de37b942baad06145) (let _00024sqc8LlS111 const6b86b273ff34fce19d6b804e) (let _00024sqc8pMe112 conste7f6c011776e8db7cd330b54) (let _00024sqc6DNO113 constd4735e3a265e16eee03f5971) (let _00024sqc1lbp114 const7902699be42c8a8e46fbbb45) (let _00024sqo8FLo116 constef2d127de37b942baad06145) (let _00024sqo5VHI115 const5feceb66ffc86f38d952786c) (let _00024sqo818G118 conste7f6c011776e8db7cd330b54) (let _00024sqo21NH117 const6b86b273ff34fce19d6b804e) (let _00024sqo7jL6120 const7902699be42c8a8e46fbbb45) (let _00024sqo6S5B119 constd4735e3a265e16eee03f5971) (let _00024sqo5alM122 constef2d127de37b942baad06145) (let _00024sqo2iA5121 constd4735e3a265e16eee03f5971) (let _00024sqo2vUW124 conste7f6c011776e8db7cd330b54) (let _00024sqo7jm3123 const6b86b273ff34fce19d6b804e) (let _00024sqo9y05126 const7902699be42c8a8e46fbbb45) (let _00024sqo9l2D125 const5feceb66ffc86f38d952786c)) (probe $seq_at (0 1 2) 2 _00024sqo8FLo116 _00024sqo5VHI115 _00024seq0) (body (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo818G118 _00024sqo21NH117 _00024seq0) (join-old $seq_at (0 1 2) 3 (0 1 2) _00024sqo7jL6120 _00024sqo6S5B119 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo5alM122 _00024sqo2iA5121 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo2vUW124 _00024sqo7jm3123 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9y05126 _00024sqo9l2D125 _00024seq0) (join lst_member (1 2 0) 2 _00024seq0 __tconst3Eu626 __t1vjT27) (join lst_member_ans (0 1) 1 __t1vjT27 r) (letp _00024sql3AAV106 (aslst _00024seq0)) (let chk9g8r506 (llen _00024sql3AAV106)) (eq _00024sqc8qNr108 chk9g8r506) (letp chk7Z3v507 (lref _00024sql3AAV106 _00024sqc1Q1F109)) (eq _00024sqc3i9t110 chk7Z3v507) (letp chk7OOk508 (lref _00024sql3AAV106 _00024sqc8LlS111)) (eq _00024sqc8pMe112 chk7OOk508) (letp chk6qdo509 (lref _00024sql3AAV106 _00024sqc6DNO113)) (eq _00024sqc1lbp114 chk6qdo509)) (head (emit has7 (0) r)) lst_ops.slog:14 #f)
  class ReadTask2227 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex2215;  slog::Index** $seq_atindex2216;  slog::Index** $seq_atrindex2217;  slog::Index** $seq_atrindex2218;  slog::Index** $seq_atrindex2219;  slog::Index** lst_memberindex2220;  slog::Index** lst_member_ansindex2221;  slog::Index** $seq_atdelta2222;  slog::Index** $seq_atdelta2223;  slog::Index** $seq_atrdelta2224;  slog::Index** $seq_atrdelta2225;  slog::Index** $seq_atrdelta2226;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("has7");
      std::vector<u16> ord2228({0});
      slog::Relation* readrel2229 = db->getRelation("has7");
      head_index[0] = readrel2229->getIndex(ord2228, false);
      std::vector<u16> ord2230({0, 1, 2});
      slog::Relation* readrel2231 = db->getRelation("$seq_at");
      driver_index = readrel2231->getIndex(ord2230, true);
      std::vector<u16> ord2232({0, 1, 2});
      slog::Relation* readrel2233 = db->getRelation("$seq_at");
      $seq_atindex2215 = readrel2233->getIndex(ord2232, false);
      std::vector<u16> ord2234({0, 1, 2});
      slog::Relation* readrel2235 = db->getRelation("$seq_at");
      $seq_atdelta2222 = readrel2235->getIndex(ord2234, true);
      std::vector<u16> ord2236({0, 1, 2});
      slog::Relation* readrel2237 = db->getRelation("$seq_at");
      $seq_atindex2216 = readrel2237->getIndex(ord2236, false);
      std::vector<u16> ord2238({0, 1, 2});
      slog::Relation* readrel2239 = db->getRelation("$seq_at");
      $seq_atdelta2223 = readrel2239->getIndex(ord2238, true);
      std::vector<u16> ord2240({0, 1, 2});
      slog::Relation* readrel2241 = db->getRelation("$seq_atr");
      $seq_atrindex2217 = readrel2241->getIndex(ord2240, false);
      std::vector<u16> ord2242({0, 1, 2});
      slog::Relation* readrel2243 = db->getRelation("$seq_atr");
      $seq_atrdelta2224 = readrel2243->getIndex(ord2242, true);
      std::vector<u16> ord2244({0, 1, 2});
      slog::Relation* readrel2245 = db->getRelation("$seq_atr");
      $seq_atrindex2218 = readrel2245->getIndex(ord2244, false);
      std::vector<u16> ord2246({0, 1, 2});
      slog::Relation* readrel2247 = db->getRelation("$seq_atr");
      $seq_atrdelta2225 = readrel2247->getIndex(ord2246, true);
      std::vector<u16> ord2248({0, 1, 2});
      slog::Relation* readrel2249 = db->getRelation("$seq_atr");
      $seq_atrindex2219 = readrel2249->getIndex(ord2248, false);
      std::vector<u16> ord2250({0, 1, 2});
      slog::Relation* readrel2251 = db->getRelation("$seq_atr");
      $seq_atrdelta2226 = readrel2251->getIndex(ord2250, true);
      std::vector<u16> ord2252({1, 2, 0});
      slog::Relation* readrel2253 = db->getRelation("lst_member");
      lst_memberindex2220 = readrel2253->getIndex(ord2252, false);
      std::vector<u16> ord2254({0, 1});
      slog::Relation* readrel2255 = db->getRelation("lst_member_ans");
      lst_member_ansindex2221 = readrel2255->getIndex(ord2254, false);
  
    }
    ReadTask2227(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c289 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c290 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c291 = v_const5feceb66ffc86f38d952786c;
      u64 v_c292 = v_constef2d127de37b942baad06145;
      u64 v_c293 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c294 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c295 = v_constd4735e3a265e16eee03f5971;
      u64 v_c296 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c297 = v_constef2d127de37b942baad06145;
      u64 v_c298 = v_const5feceb66ffc86f38d952786c;
      u64 v_c299 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c300 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c301 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c302 = v_constd4735e3a265e16eee03f5971;
      u64 v_c303 = v_constef2d127de37b942baad06145;
      u64 v_c304 = v_constd4735e3a265e16eee03f5971;
      u64 v_c305 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c306 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c307 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c308 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c297, v_c298, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m2256) {
        u64 v_c19 = m2256[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex2215, $seq_atdelta2222, std::array<u64,3>{v_c299, v_c300, v_c19}, [&](const std::array<u64,3>& m2257) {
          slog::join_probe_old<3,3>($seq_atindex2216, $seq_atdelta2223, std::array<u64,3>{v_c301, v_c302, v_c19}, [&](const std::array<u64,3>& m2258) {
            slog::join_probe_old<3,3>($seq_atrindex2217, $seq_atrdelta2224, std::array<u64,3>{v_c303, v_c304, v_c19}, [&](const std::array<u64,3>& m2259) {
              slog::join_probe_old<3,3>($seq_atrindex2218, $seq_atrdelta2225, std::array<u64,3>{v_c305, v_c306, v_c19}, [&](const std::array<u64,3>& m2260) {
                slog::join_probe_old<3,3>($seq_atrindex2219, $seq_atrdelta2226, std::array<u64,3>{v_c307, v_c308, v_c19}, [&](const std::array<u64,3>& m2261) {
                  slog::join_probe<3,2>(lst_memberindex2220, std::array<u64,3>{v_c19, v_c289, 0}, [&](const std::array<u64,3>& m2262) {
                    u64 v_c309 = m2262[2];
                    slog::join_probe<2,1>(lst_member_ansindex2221, std::array<u64,2>{v_c309, 0}, [&](const std::array<u64,2>& m2263) {
                      u64 v_c21 = m2263[1];
                      bool ok2264 = true;
                      u64 v_c310 = _prim_aslst(db, v_c19, &ok2264);
                      if (!ok2264) return;
                      u64 v_c331 = _prim_llen(db, v_c310);
                      if (v_c331 == slog_error) { slog::emit_pending_error(db, "lst_ops.slog:14"); return; }
                      if (v_c290 != v_c331) return;
                      bool ok2265 = true;
                      u64 v_c332 = _prim_lref(db, v_c310, v_c291, &ok2265);
                      if (!ok2265) return;
                      if (v_c292 != v_c332) return;
                      bool ok2266 = true;
                      u64 v_c333 = _prim_lref(db, v_c310, v_c293, &ok2266);
                      if (!ok2266) return;
                      if (v_c294 != v_c333) return;
                      bool ok2267 = true;
                      u64 v_c334 = _prim_lref(db, v_c310, v_c295, &ok2267);
                      if (!ok2267) return;
                      if (v_c296 != v_c334) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_ops.slog:14", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask2227* _cont = new ReadTask2227(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2227(db,b), false);
  // (crule (pre) (scan int_overflow __erre12yi370 __errf0mjs371 __errf3TBP372 __errf3Q75373) (body) (head (emit error (0) __erre12yi370)) <internal>:1 #f)
  class ReadTask2268 : public slog::Task
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
      std::vector<u16> ord2269({0});
      slog::Relation* readrel2270 = db->getRelation("error");
      head_index[0] = readrel2270->getIndex(ord2269, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask2268(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c335 = _t[0];
        u64 v_c336 = _t[1];
        u64 v_c337 = _t[2];
        u64 v_c338 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c335}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask2268* _cont = new ReadTask2268(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2268(db,b), false);
  // (crule (pre) (scan toint_range __erre80t4378 __errf6ujl379 __errf3QGu380) (body) (head (emit error (0) __erre80t4378)) <internal>:1 #f)
  class ReadTask2271 : public slog::Task
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
      std::vector<u16> ord2272({0});
      slog::Relation* readrel2273 = db->getRelation("error");
      head_index[0] = readrel2273->getIndex(ord2272, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask2271(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c339 = _t[0];
        u64 v_c340 = _t[1];
        u64 v_c341 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c339}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask2271* _cont = new ReadTask2271(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2271(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre6rFS367 __errf12Ob368 __errf2zs2369) (body) (head (emit error (0) __erre6rFS367)) <internal>:1 #f)
  class ReadTask2274 : public slog::Task
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
      std::vector<u16> ord2275({0});
      slog::Relation* readrel2276 = db->getRelation("error");
      head_index[0] = readrel2276->getIndex(ord2275, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask2274(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c342 = _t[0];
        u64 v_c343 = _t[1];
        u64 v_c344 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c342}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask2274* _cont = new ReadTask2274(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2274(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre4gxZ391 __errf5goR392 __errf4hLh393) (body) (head (emit error (0) __erre4gxZ391)) <internal>:1 #f)
  class ReadTask2277 : public slog::Task
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
      std::vector<u16> ord2278({0});
      slog::Relation* readrel2279 = db->getRelation("error");
      head_index[0] = readrel2279->getIndex(ord2278, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask2277(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c345 = _t[0];
        u64 v_c346 = _t[1];
        u64 v_c347 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c345}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask2277* _cont = new ReadTask2277(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2277(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre1zCO386 __errf6MaB387 __errf0Z2g388 __errf9d8I389 __errf3E4z390) (body) (head (emit error (0) __erre1zCO386)) <internal>:1 #f)
  class ReadTask2280 : public slog::Task
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
      std::vector<u16> ord2281({0});
      slog::Relation* readrel2282 = db->getRelation("error");
      head_index[0] = readrel2282->getIndex(ord2281, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask2280(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c348 = _t[0];
        u64 v_c349 = _t[1];
        u64 v_c350 = _t[2];
        u64 v_c351 = _t[3];
        u64 v_c352 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c348}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask2280* _cont = new ReadTask2280(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2280(db,b), false);
  // (crule (pre) (scan type_mismatch __erre11ls381 __errf3A5p382 __errf137y383 __errf2M1Y384 __errf58vK385) (body) (head (emit error (0) __erre11ls381)) <internal>:1 #f)
  class ReadTask2283 : public slog::Task
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
      std::vector<u16> ord2284({0});
      slog::Relation* readrel2285 = db->getRelation("error");
      head_index[0] = readrel2285->getIndex(ord2284, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask2283(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c353 = _t[0];
        u64 v_c354 = _t[1];
        u64 v_c355 = _t[2];
        u64 v_c356 = _t[3];
        u64 v_c357 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c353}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask2283* _cont = new ReadTask2283(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2283(db,b), false);
  // (crule (pre) (scan nan_result __erre1i0q374 __errf34LC375 __errf9WBw376 __errf8cst377) (body) (head (emit error (0) __erre1i0q374)) <internal>:1 #f)
  class ReadTask2286 : public slog::Task
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
      std::vector<u16> ord2287({0});
      slog::Relation* readrel2288 = db->getRelation("error");
      head_index[0] = readrel2288->getIndex(ord2287, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask2286(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c358 = _t[0];
        u64 v_c359 = _t[1];
        u64 v_c360 = _t[2];
        u64 v_c361 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c358}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask2286* _cont = new ReadTask2286(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2286(db,b), false);
  s->addReadRel("$seq_at");
  s->addReadRel("$seq_atr");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("lst_append");
  s->addReadRel("lst_append_ans");
  s->addReadRel("lst_len");
  s->addReadRel("lst_len_ans");
  s->addReadRel("lst_member");
  s->addReadRel("lst_member_ans");
  s->addReadRel("lst_ref");
  s->addReadRel("lst_ref_ans");
  s->addReadRel("lst_rev");
  s->addReadRel("lst_rev_ans");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$seq_atr");
  s->addDynamicRel("appended");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("has7");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("n");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("reversed");
  s->addDynamicRel("third");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

