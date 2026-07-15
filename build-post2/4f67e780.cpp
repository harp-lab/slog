
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_conste3776bfed7f405de8017ecfa;
u64 v_constef2d127de37b942baad06145;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const2c624232cdd221771294dfbb;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constd8eb1fcc902b0421b7549624;
u64 v_const531b49b48a75e80df378d992;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const18fb5942c65f2f8b5fee74d1;
u64 v_constade5509183a7aaa4ea207893;
u64 v_const606e06328e00dd103d4f84bc;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("4f67e780");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_conste3776bfed7f405de8017ecfa = db->encodeString("pempty");
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const2c624232cdd221771294dfbb = s32_encode(8);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constd8eb1fcc902b0421b7549624 = db->encodeString("set.slog:63");
  v_const531b49b48a75e80df378d992 = db->encodeString("set.slog:62");
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const18fb5942c65f2f8b5fee74d1 = db->encodeString("st_size");
  v_constade5509183a7aaa4ea207893 = db->encodeString("st_mem");
  v_const606e06328e00dd103d4f84bc = db->encodeString("set.slog:165");
  r = db->getRelation("upd");
  if (r == 0) db->addRelation("upd", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("upd");
      std::vector<u16> ord176({0});
    
    r->addIndex<1>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("upd"), std::array<u16,1>{0}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord177({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord178({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord179({1, 2, 0});
    
    r->addIndex<3>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord180({0, 1, 2});
    
    r->addIndex<3>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("sz");
  if (r == 0) db->addRelation("sz", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("sz");
      std::vector<u16> ord181({0});
    
    r->addIndex<1>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("sz"), std::array<u16,1>{0}, b));
  r = db->getRelation("st_union_ans");
  if (r == 0) db->addRelation("st_union_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_union_ans");
      std::vector<u16> ord182({0, 1});
    
    r->addIndex<2>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_union_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_union");
  if (r == 0) db->addStruct("st_union", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_union");
      std::vector<u16> ord183({1, 2, 0});
    
    r->addIndex<3>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord184({0, 1, 2});
    
    r->addIndex<3>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_union"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_size_ans");
  if (r == 0) db->addRelation("st_size_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_size_ans");
      std::vector<u16> ord185({0, 1});
    
    r->addIndex<2>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_size_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_size");
  if (r == 0) db->addStruct("st_size", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_size");
      std::vector<u16> ord186({1, 0});
    
    r->addIndex<2>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord187({0, 1});
    
    r->addIndex<2>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("st_size"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("st_msk_ans");
  if (r == 0) db->addRelation("st_msk_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_msk_ans");
      std::vector<u16> ord188({0, 1});
    
    r->addIndex<2>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_msk_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_msk");
  if (r == 0) db->addStruct("st_msk", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_msk");
      std::vector<u16> ord189({1, 2, 0});
    
    r->addIndex<3>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord190({0, 1, 2});
    
    r->addIndex<3>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_msk"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_mem_ans");
  if (r == 0) db->addRelation("st_mem_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem_ans");
      std::vector<u16> ord191({0, 1});
    
    r->addIndex<2>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_mem_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_mem0_ans");
  if (r == 0) db->addRelation("st_mem0_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem0_ans");
      std::vector<u16> ord192({0, 1});
    
    r->addIndex<2>(ord192, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_mem0_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_mem0");
  if (r == 0) db->addStruct("st_mem0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem0");
      std::vector<u16> ord193({1, 2, 0});
    
    r->addIndex<3>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord194({0, 1, 2});
    
    r->addIndex<3>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord195({2, 0, 1});
    
    r->addIndex<3>(ord195, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_mem0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_mem");
  if (r == 0) db->addStruct("st_mem", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem");
      std::vector<u16> ord196({1, 2, 0});
    
    r->addIndex<3>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord197({0, 1, 2});
    
    r->addIndex<3>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_mem"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_join_ans");
  if (r == 0) db->addRelation("st_join_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_join_ans");
      std::vector<u16> ord198({0, 1});
    
    r->addIndex<2>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_join_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_join");
  if (r == 0) db->addStruct("st_join", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_join");
      std::vector<u16> ord199({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord199, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord200({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("st_join"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("st_ins_ans");
  if (r == 0) db->addRelation("st_ins_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_ins_ans");
      std::vector<u16> ord201({0, 1});
    
    r->addIndex<2>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_ins_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_ins");
  if (r == 0) db->addStruct("st_ins", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_ins");
      std::vector<u16> ord202({2, 1, 0});
    
    r->addIndex<3>(ord202, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord203({0, 1, 2});
    
    r->addIndex<3>(ord203, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord204({2, 0, 1});
    
    r->addIndex<3>(ord204, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_ins"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("st_hsb_ans");
  if (r == 0) db->addRelation("st_hsb_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_hsb_ans");
      std::vector<u16> ord205({0, 1});
    
    r->addIndex<2>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_hsb_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_hsb");
  if (r == 0) db->addStruct("st_hsb", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_hsb");
      std::vector<u16> ord206({1, 0});
    
    r->addIndex<2>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord207({0, 1});
    
    r->addIndex<2>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("st_hsb"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("st_fromlist_ans");
  if (r == 0) db->addRelation("st_fromlist_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord208({0, 1});
    
    r->addIndex<2>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_fromlist_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_fromlist");
  if (r == 0) db->addStruct("st_fromlist", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_fromlist");
      std::vector<u16> ord209({1, 0});
    
    r->addIndex<2>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord210({0, 1});
    
    r->addIndex<2>(ord210, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("st_fromlist"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("st_diff_ans");
  if (r == 0) db->addRelation("st_diff_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_diff_ans");
      std::vector<u16> ord211({0, 1});
    
    r->addIndex<2>(ord211, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_diff_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_diff");
  if (r == 0) db->addStruct("st_diff", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_diff");
      std::vector<u16> ord212({1, 2, 0});
    
    r->addIndex<3>(ord212, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord213({0, 1, 2});
    
    r->addIndex<3>(ord213, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_diff"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_del_ans");
  if (r == 0) db->addRelation("st_del_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_del_ans");
      std::vector<u16> ord214({0, 1});
    
    r->addIndex<2>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_del_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_del");
  if (r == 0) db->addStruct("st_del", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_del");
      std::vector<u16> ord215({1, 2, 0});
    
    r->addIndex<3>(ord215, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord216({0, 1, 2});
    
    r->addIndex<3>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord217({2, 0, 1});
    
    r->addIndex<3>(ord217, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_del"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_bld_ans");
  if (r == 0) db->addRelation("st_bld_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_bld_ans");
      std::vector<u16> ord218({0, 1});
    
    r->addIndex<2>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_bld_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_bld");
  if (r == 0) db->addStruct("st_bld", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_bld");
      std::vector<u16> ord219({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord220({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("st_bld"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord221({1, 2, 0});
    
    r->addIndex<3>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord222({0, 1, 2});
    
    r->addIndex<3>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("pleaf");
  if (r == 0) db->addStruct("pleaf", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pleaf");
      std::vector<u16> ord223({1, 0});
    
    r->addIndex<2>(ord223, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord224({0, 1});
    
    r->addIndex<2>(ord224, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("pleaf"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("pbranch");
  if (r == 0) db->addStruct("pbranch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pbranch");
      std::vector<u16> ord225({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord226({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("pbranch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord227({1, 2, 3, 0});
    
    r->addIndex<4>(ord227, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord228({0, 1, 2, 3});
    
    r->addIndex<4>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord229({1, 2, 0});
    
    r->addIndex<3>(ord229, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord230({0, 1, 2});
    
    r->addIndex<3>(ord230, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord231({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord231, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord232({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord232, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord233({1, 2, 0});
    
    r->addIndex<3>(ord233, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord234({0, 1, 2});
    
    r->addIndex<3>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord235({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord235, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord236({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord236, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("m");
  if (r == 0) db->addRelation("m", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("m");
      std::vector<u16> ord237({0, 1});
    
    r->addIndex<2>(ord237, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("m"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord238({1, 2, 3, 0});
    
    r->addIndex<4>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord239({0, 1, 2, 3});
    
    r->addIndex<4>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord240({0});
    
    r->addIndex<1>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord241({1, 2, 0});
    
    r->addIndex<3>(ord241, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord242({0, 1, 2});
    
    r->addIndex<3>(ord242, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("dif");
  if (r == 0) db->addRelation("dif", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("dif");
      std::vector<u16> ord243({0});
    
    r->addIndex<1>(ord243, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("dif"), std::array<u16,1>{0}, b));
  r = db->getRelation("canon");
  if (r == 0) db->addRelation("canon", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("canon");
      std::vector<u16> ord244({0});
    
    r->addIndex<1>(ord244, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("canon"), std::array<u16,1>{0}, b));
  r = db->getRelation("afterdel");
  if (r == 0) db->addRelation("afterdel", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("afterdel");
      std::vector<u16> ord245({0});
    
    r->addIndex<1>(ord245, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("afterdel"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord246({1, 0});
    
    r->addIndex<2>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord247({0, 1});
    
    r->addIndex<2>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord248({1, 0});
    
    r->addIndex<2>(ord248, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup97714x23x0x0x1");
  if (r == 0) db->addRelation("$sup97714x23x0x0x1", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup97714x23x0x0x1");
      std::vector<u16> ord249({0, 1, 2});
    
    r->addIndex<3>(ord249, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup97714x23x0x0x1"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup9688x90x0x0x0");
  if (r == 0) db->addRelation("$sup9688x90x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x90x0x0x0");
      std::vector<u16> ord250({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x90x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x88x0x0x0");
  if (r == 0) db->addRelation("$sup9688x88x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x88x0x0x0");
      std::vector<u16> ord251({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord251, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x88x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x87x0x0x0");
  if (r == 0) db->addRelation("$sup9688x87x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x87x0x0x0");
      std::vector<u16> ord252({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord252, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x87x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x72x0x0x0");
  if (r == 0) db->addRelation("$sup9688x72x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x72x0x0x0");
      std::vector<u16> ord253({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x72x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x70x0x0x0");
  if (r == 0) db->addRelation("$sup9688x70x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x70x0x0x0");
      std::vector<u16> ord254({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord254, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x70x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x69x0x0x0");
  if (r == 0) db->addRelation("$sup9688x69x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x69x0x0x0");
      std::vector<u16> ord255({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x69x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x62x0x0x0");
  if (r == 0) db->addRelation("$sup9688x62x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x62x0x0x0");
      std::vector<u16> ord256({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x62x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x61x0x0x0");
  if (r == 0) db->addRelation("$sup9688x61x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x61x0x0x0");
      std::vector<u16> ord257({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x61x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x54x0x0x0");
  if (r == 0) db->addRelation("$sup9688x54x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x54x0x0x0");
      std::vector<u16> ord258({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x54x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x52x0x0x1");
  if (r == 0) db->addRelation("$sup9688x52x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x52x0x0x1");
      std::vector<u16> ord259({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x52x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x52x0x0x0");
  if (r == 0) db->addRelation("$sup9688x52x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x52x0x0x0");
      std::vector<u16> ord260({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord260, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x52x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x50x0x0x1");
  if (r == 0) db->addRelation("$sup9688x50x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x50x0x0x1");
      std::vector<u16> ord261({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord261, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x50x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x50x0x0x0");
  if (r == 0) db->addRelation("$sup9688x50x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x50x0x0x0");
      std::vector<u16> ord262({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x50x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x40x0x0x2");
  if (r == 0) db->addRelation("$sup9688x40x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x40x0x0x2");
      std::vector<u16> ord263({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x40x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x40x0x0x1");
  if (r == 0) db->addRelation("$sup9688x40x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x40x0x0x1");
      std::vector<u16> ord264({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x40x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x40x0x0x0");
  if (r == 0) db->addRelation("$sup9688x40x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x40x0x0x0");
      std::vector<u16> ord265({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup9688x40x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x36x0x0x2");
  if (r == 0) db->addRelation("$sup9688x36x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x36x0x0x2");
      std::vector<u16> ord266({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord266, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x36x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x36x0x0x1");
  if (r == 0) db->addRelation("$sup9688x36x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x36x0x0x1");
      std::vector<u16> ord267({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord267, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x36x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x36x0x0x0");
  if (r == 0) db->addRelation("$sup9688x36x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x36x0x0x0");
      std::vector<u16> ord268({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord268, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup9688x36x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x168x0x0x0");
  if (r == 0) db->addRelation("$sup9688x168x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x168x0x0x0");
      std::vector<u16> ord269({0, 1, 2, 3});
    
    r->addIndex<4>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup9688x168x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup9688x164x0x0x0");
  if (r == 0) db->addRelation("$sup9688x164x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x164x0x0x0");
      std::vector<u16> ord270({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord270, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup9688x164x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x154x0x0x0");
  if (r == 0) db->addRelation("$sup9688x154x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x154x0x0x0");
      std::vector<u16> ord271({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord271, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x154x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x151x0x0x0");
  if (r == 0) db->addRelation("$sup9688x151x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x151x0x0x0");
      std::vector<u16> ord272({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord272, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x151x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x148x0x0x0");
  if (r == 0) db->addRelation("$sup9688x148x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x148x0x0x0");
      std::vector<u16> ord273({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x148x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x145x0x0x0");
  if (r == 0) db->addRelation("$sup9688x145x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x145x0x0x0");
      std::vector<u16> ord274({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord274, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x145x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x142x0x0x0");
  if (r == 0) db->addRelation("$sup9688x142x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x142x0x0x0");
      std::vector<u16> ord275({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord275, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x142x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x139x0x0x0");
  if (r == 0) db->addRelation("$sup9688x139x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x139x0x0x0");
      std::vector<u16> ord276({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord276, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x139x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x136x0x0x0");
  if (r == 0) db->addRelation("$sup9688x136x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x136x0x0x0");
      std::vector<u16> ord277({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x136x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x120x0x0x0");
  if (r == 0) db->addRelation("$sup9688x120x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x120x0x0x0");
      std::vector<u16> ord278({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord278, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x120x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x117x0x0x1");
  if (r == 0) db->addRelation("$sup9688x117x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x117x0x0x1");
      std::vector<u16> ord279({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord279, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x117x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup9688x117x0x0x0");
  if (r == 0) db->addRelation("$sup9688x117x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x117x0x0x0");
      std::vector<u16> ord280({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x117x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x114x0x0x1");
  if (r == 0) db->addRelation("$sup9688x114x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x114x0x0x1");
      std::vector<u16> ord281({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x114x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup9688x114x0x0x0");
  if (r == 0) db->addRelation("$sup9688x114x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x114x0x0x0");
      std::vector<u16> ord282({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord282, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x114x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x110x0x0x0");
  if (r == 0) db->addRelation("$sup9688x110x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x110x0x0x0");
      std::vector<u16> ord283({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord283, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x110x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x106x0x0x1");
  if (r == 0) db->addRelation("$sup9688x106x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x106x0x0x1");
      std::vector<u16> ord284({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord284, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x106x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup9688x106x0x0x0");
  if (r == 0) db->addRelation("$sup9688x106x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x106x0x0x0");
      std::vector<u16> ord285({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord285, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x106x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x103x0x0x1");
  if (r == 0) db->addRelation("$sup9688x103x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x103x0x0x1");
      std::vector<u16> ord286({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord286, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x103x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup9688x103x0x0x0");
  if (r == 0) db->addRelation("$sup9688x103x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x103x0x0x0");
      std::vector<u16> ord287({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord287, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x103x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x100x0x0x0");
  if (r == 0) db->addRelation("$sup9688x100x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x100x0x0x0");
      std::vector<u16> ord288({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord288, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x100x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$seq_atr");
  if (r == 0) db->addRelation("$seq_atr", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_atr");
      std::vector<u16> ord289({0, 1, 2});
    
    r->addIndex<3>(ord289, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_atr"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord290({0, 1, 2});
    
    r->addIndex<3>(ord290, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("st_fromlist"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan toint_range __erre0mAE1471 __errf1J7D1472 __errf9s6X1473) (body) (head (emit error (0) __erre0mAE1471)) <internal>:1 #f)
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
      outer_rel = db->getRelation("toint_range");
  
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
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
  // (crule (pre) (scan nan_result __erre8HJL1467 __errf3at21468 __errf8o6l1469 __errf4e6i1470) (body) (head (emit error (0) __erre8HJL1467)) <internal>:1 #f)
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
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c6 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre (let __trid1C8I794 const606e06328e00dd103d4f84bc) (let __trel01lj795 const18fb5942c65f2f8b5fee74d1) (let __tcol3pqx796 const5feceb66ffc86f38d952786c)) (scan $sup9688x164x0x0x0 __d0 l m p r) (body) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid1C8I794 __trel01lj795 __tcol3pqx796 (1 2 3 4 0)) (mkstruct st_size (1 0) __9EyU793 l)) set.slog:165 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid7;  u32 sid6;  u32 sid8;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_size");
      outer_rel = db->getRelation("$sup9688x164x0x0x0");
      sid7 = db->getRelation("_enum")->getStructId();
      sid6 = db->getRelation("pbranch")->getStructId();
      sid8 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c7 = v_const606e06328e00dd103d4f84bc;
      u64 v_c8 = v_const18fb5942c65f2f8b5fee74d1;
      u64 v_c9 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c10 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c14 = _t[4];
        ++_fires;
        if (!((is_struct(v_c11) && (decode_struct_id(v_c11) == sid6 || decode_struct_id(v_c11) == sid7 || decode_struct_id(v_c11) == sid8))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c7, v_c8, v_c9, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:165", "delta:$sup9688x164x0x0x0", _fires);
  
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
  // (crule (pre) (scan mpz_table_overflow __erre5HqJ1484 __errf2Ow91485 __errf1h1k1486) (body) (head (emit error (0) __erre5HqJ1484)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
  // (crule (pre (let __tconst4sEo445 constd4735e3a265e16eee03f5971)) (probe st_del (2 0 1) 1 __tconst4sEo445 __t2qit446 s) (body (join canon (0) 1 s) (join st_del_ans (0 1) 1 __t2qit446 r)) (head (emit afterdel (0) r)) st_basic.slog:23 #f)
  class ReadTask15 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** canonindex13;  slog::Index** st_del_ansindex14;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("afterdel");
      std::vector<u16> ord16({0});
      slog::Relation* readrel17 = db->getRelation("afterdel");
      head_index[0] = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({2, 0, 1});
      slog::Relation* readrel19 = db->getRelation("st_del");
      driver_index = readrel19->getIndex(ord18, true);
      std::vector<u16> ord20({0});
      slog::Relation* readrel21 = db->getRelation("canon");
      canonindex13 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({0, 1});
      slog::Relation* readrel23 = db->getRelation("st_del_ans");
      st_del_ansindex14 = readrel23->getIndex(ord22, false);
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c18 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c18, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m24) {
        u64 v_c19 = m24[1];
        u64 v_c20 = m24[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<1,1>(canonindex13, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m25) {
          slog::join_probe<2,1>(st_del_ansindex14, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m26) {
            u64 v_c14 = m26[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c14}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:23", "all:st_del", _fires);
  
      if (!_done)
      {
        ReadTask15* _cont = new ReadTask15(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), true);
  // (crule (pre) (scan modulo_by_zero __erre8Mmu1460 __errf245k1461 __errf2ip91462) (body) (head (emit error (0) __erre8Mmu1460)) <internal>:1 #f)
  class ReadTask27 : public slog::Task
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
      std::vector<u16> ord28({0});
      slog::Relation* readrel29 = db->getRelation("error");
      head_index[0] = readrel29->getIndex(ord28, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask27* _cont = new ReadTask27(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask27(db,b), false);
  // (crule (pre) (scan st_size __t9Cd25 __t9WeL4) (body (join pbranch (0 1 2 3 4) 1 __t9WeL4 p m l r)) (head (emit $sup9688x164x0x0x0 (0 1 2 3 4) __t9Cd25 l m p r)) set.slog:165 #f)
  class ReadTask31 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex30;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x164x0x0x0");
      std::vector<u16> ord32({0, 1, 2, 3, 4});
      slog::Relation* readrel33 = db->getRelation("$sup9688x164x0x0x0");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("st_size");
      std::vector<u16> ord34({0, 1, 2, 3, 4});
      slog::Relation* readrel35 = db->getRelation("pbranch");
      pbranchindex30 = readrel35->getIndex(ord34, false);
  
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
        u64 v_c24 = _t[0];
        u64 v_c25 = _t[1];
        slog::join_probe<5,1>(pbranchindex30, std::array<u64,5>{v_c25, 0, 0, 0, 0}, [&](const std::array<u64,5>& m36) {
          u64 v_c13 = m36[1]; u64 v_c12 = m36[2]; u64 v_c11 = m36[3]; u64 v_c14 = m36[4];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c24, v_c11, v_c12, v_c13, v_c14}, std::array<u16,5>{0, 1, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:165", "delta:st_size", _fires);
  
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
  // (crule (pre) (scan canon s) (body) (head (mkstruct st_size (1 0) __1r61886 s)) st_basic.slog:22 #f)
  class ReadTask37 : public slog::Task
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
      head_rel[0] = db->getRelation("st_size");
      outer_rel = db->getRelation("canon");
  
    }
    ReadTask37(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:22", "all:canon", _fires);
  
      if (!_done)
      {
        ReadTask37* _cont = new ReadTask37(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask37(db,b), true);
  // (crule (pre (let __trid99QE698 constd8eb1fcc902b0421b7549624) (let __trel8CSG699 constade5509183a7aaa4ea207893) (let __tcol9BVC700 const5feceb66ffc86f38d952786c) (let __trel3Ate701 constade5509183a7aaa4ea207893) (let __tcol0THe702 const6b86b273ff34fce19d6b804e)) (scan $sup9688x62x0x0x0 __d0 k l m p r) (body) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid99QE698 __trel8CSG699 __tcol9BVC700 (1 2 3 4 0)) (tycheck k (accept int) __trid99QE698 __trel3Ate701 __tcol0THe702 (1 2 3 4 0)) (mkstruct st_mem (1 2 0) __5uKn697 r k)) set.slog:63 #f)
  class ReadTask41 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid39;  u32 sid38;  u32 sid40;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_mem");
      outer_rel = db->getRelation("$sup9688x62x0x0x0");
      sid39 = db->getRelation("_enum")->getStructId();
      sid38 = db->getRelation("pbranch")->getStructId();
      sid40 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask41(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_constd8eb1fcc902b0421b7549624;
      u64 v_c27 = v_constade5509183a7aaa4ea207893;
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_constade5509183a7aaa4ea207893;
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c10 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c14 = _t[5];
        ++_fires;
        if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid38 || decode_struct_id(v_c14) == sid39 || decode_struct_id(v_c14) == sid40))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c26, v_c27, v_c28, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c31)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c26, v_c29, v_c30, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c14, v_c31}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:63", "delta:$sup9688x62x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask41* _cont = new ReadTask41(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask41(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre65Yv1479 __errf3ZTk1480 __errf2qSu1481 __errf9t1H1482 __errf6Mfu1483) (body) (head (emit error (0) __erre65Yv1479)) <internal>:1 #f)
  class ReadTask42 : public slog::Task
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
      std::vector<u16> ord43({0});
      slog::Relation* readrel44 = db->getRelation("error");
      head_index[0] = readrel44->getIndex(ord43, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask42(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c32}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask42* _cont = new ReadTask42(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask42(db,b), false);
  // (crule (pre (let __tconst3LXK328 const7902699be42c8a8e46fbbb45)) (probe st_ins (2 0 1) 1 __tconst3LXK328 __t4Ybh329 s) (body (join canon (0) 1 s) (join st_ins_ans (0 1) 1 __t4Ybh329 r)) (head (emit upd (0) r)) st_basic.slog:25 #f)
  class ReadTask47 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** canonindex45;  slog::Index** st_ins_ansindex46;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("upd");
      std::vector<u16> ord48({0});
      slog::Relation* readrel49 = db->getRelation("upd");
      head_index[0] = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({2, 0, 1});
      slog::Relation* readrel51 = db->getRelation("st_ins");
      driver_index = readrel51->getIndex(ord50, true);
      std::vector<u16> ord52({0});
      slog::Relation* readrel53 = db->getRelation("canon");
      canonindex45 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({0, 1});
      slog::Relation* readrel55 = db->getRelation("st_ins_ans");
      st_ins_ansindex46 = readrel55->getIndex(ord54, false);
  
    }
    ReadTask47(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c37, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m56) {
        u64 v_c38 = m56[1];
        u64 v_c20 = m56[2];
        if (buckethash(v_c38) != bucket) return;
        slog::join_probe<1,1>(canonindex45, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m57) {
          slog::join_probe<2,1>(st_ins_ansindex46, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m58) {
            u64 v_c14 = m58[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c14}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:25", "all:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask47* _cont = new ReadTask47(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask47(db,b), true);
  // (crule (pre (let __trid94z9975 const531b49b48a75e80df378d992) (let __trel4oOd976 constade5509183a7aaa4ea207893) (let __tcol3Oa6977 const5feceb66ffc86f38d952786c) (let __trel98sq978 constade5509183a7aaa4ea207893) (let __tcol8tb5979 const6b86b273ff34fce19d6b804e)) (scan $sup9688x61x0x0x0 __d0 k l m p r) (body) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid94z9975 __trel4oOd976 __tcol3Oa6977 (1 2 3 4 0)) (tycheck k (accept int) __trid94z9975 __trel98sq978 __tcol8tb5979 (1 2 3 4 0)) (mkstruct st_mem (1 2 0) __4U23974 l k)) set.slog:62 #f)
  class ReadTask62 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid60;  u32 sid59;  u32 sid61;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_mem");
      outer_rel = db->getRelation("$sup9688x61x0x0x0");
      sid60 = db->getRelation("_enum")->getStructId();
      sid59 = db->getRelation("pbranch")->getStructId();
      sid61 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask62(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_const531b49b48a75e80df378d992;
      u64 v_c40 = v_constade5509183a7aaa4ea207893;
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
      u64 v_c42 = v_constade5509183a7aaa4ea207893;
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c10 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c14 = _t[5];
        ++_fires;
        if (!((is_struct(v_c11) && (decode_struct_id(v_c11) == sid59 || decode_struct_id(v_c11) == sid60 || decode_struct_id(v_c11) == sid61))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c39, v_c40, v_c41, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c31)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c39, v_c42, v_c43, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c11, v_c31}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:62", "delta:$sup9688x61x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask62* _cont = new ReadTask62(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask62(db,b), false);
  // (crule (pre (let __tconst20AQ231 constef2d127de37b942baad06145)) (probe st_mem0 (2 0 1) 1 __tconst20AQ231 __t3YDH232 s) (body (join canon (0) 1 s) (join st_mem0_ans (0 1) 1 __t3YDH232 a)) (head (emit m (0 1) __tconst20AQ231 a)) st_basic.slog:20 #f)
  class ReadTask65 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** canonindex63;  slog::Index** st_mem0_ansindex64;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("m");
      std::vector<u16> ord66({0, 1});
      slog::Relation* readrel67 = db->getRelation("m");
      head_index[0] = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({2, 0, 1});
      slog::Relation* readrel69 = db->getRelation("st_mem0");
      driver_index = readrel69->getIndex(ord68, true);
      std::vector<u16> ord70({0});
      slog::Relation* readrel71 = db->getRelation("canon");
      canonindex63 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({0, 1});
      slog::Relation* readrel73 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex64 = readrel73->getIndex(ord72, false);
  
    }
    ReadTask65(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c44, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m74) {
        u64 v_c45 = m74[1];
        u64 v_c20 = m74[2];
        if (buckethash(v_c45) != bucket) return;
        slog::join_probe<1,1>(canonindex63, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m75) {
          slog::join_probe<2,1>(st_mem0_ansindex64, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m76) {
            u64 v_c46 = m76[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c44, v_c46}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:20", "all:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask65* _cont = new ReadTask65(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask65(db,b), true);
  // (crule (pre (let __tconst5hDj887 conste3776bfed7f405de8017ecfa) (let __tconst8ura19 const2c624232cdd221771294dfbb) (let __tconst1DHD22 constd4735e3a265e16eee03f5971)) (probe _enum (1 0) 1 __tconst5hDj887 __t2eNJ20) (body (exists st_ins (2 1 0) 1 __tconst1DHD22) (join st_ins (2 1 0) 2 __tconst8ura19 __t2eNJ20 __t4wcD21) (exists $sup97714x23x0x0x1 (0 1 2) 1 __t4wcD21) (join st_ins_ans (0 1) 1 __t4wcD21 __v0) (exists st_ins (2 1 0) 2 __tconst1DHD22 __v0) (join $sup97714x23x0x0x1 (0 1 2) 2 __t4wcD21 __v0 s) (exists canon (0) 1 s) (exists st_diff (1 2 0) 1 s) (join st_ins (2 1 0) 2 __tconst1DHD22 __v0 __t878f23) (join canon (0) 1 s) (join st_ins_ans (0 1) 1 __t878f23 o) (join st_diff (1 2 0) 2 s o __t4hFa24) (join st_diff_ans (0 1) 1 __t4hFa24 r)) (head (emit dif (0) r)) st_basic.slog:24 #f)
  class ReadTask90 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex77;  slog::Index** st_insindex78;  slog::Index** $sup97714x23x0x0x1index79;  slog::Index** st_ins_ansindex80;  slog::Index** st_insindex81;  slog::Index** $sup97714x23x0x0x1index82;  slog::Index** canonindex83;  slog::Index** st_diffindex84;  slog::Index** st_insindex85;  slog::Index** canonindex86;  slog::Index** st_ins_ansindex87;  slog::Index** st_diffindex88;  slog::Index** st_diff_ansindex89;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("dif");
      std::vector<u16> ord91({0});
      slog::Relation* readrel92 = db->getRelation("dif");
      head_index[0] = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 0});
      slog::Relation* readrel94 = db->getRelation("_enum");
      driver_index = readrel94->getIndex(ord93, true);
      std::vector<u16> ord95({2, 1, 0});
      slog::Relation* readrel96 = db->getRelation("st_ins");
      st_insindex77 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({2, 1, 0});
      slog::Relation* readrel98 = db->getRelation("st_ins");
      st_insindex78 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({0, 1, 2});
      slog::Relation* readrel100 = db->getRelation("$sup97714x23x0x0x1");
      $sup97714x23x0x0x1index79 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({0, 1});
      slog::Relation* readrel102 = db->getRelation("st_ins_ans");
      st_ins_ansindex80 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({2, 1, 0});
      slog::Relation* readrel104 = db->getRelation("st_ins");
      st_insindex81 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1, 2});
      slog::Relation* readrel106 = db->getRelation("$sup97714x23x0x0x1");
      $sup97714x23x0x0x1index82 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0});
      slog::Relation* readrel108 = db->getRelation("canon");
      canonindex83 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 2, 0});
      slog::Relation* readrel110 = db->getRelation("st_diff");
      st_diffindex84 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({2, 1, 0});
      slog::Relation* readrel112 = db->getRelation("st_ins");
      st_insindex85 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({0});
      slog::Relation* readrel114 = db->getRelation("canon");
      canonindex86 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 1});
      slog::Relation* readrel116 = db->getRelation("st_ins_ans");
      st_ins_ansindex87 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 2, 0});
      slog::Relation* readrel118 = db->getRelation("st_diff");
      st_diffindex88 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({0, 1});
      slog::Relation* readrel120 = db->getRelation("st_diff_ans");
      st_diff_ansindex89 = readrel120->getIndex(ord119, false);
  
    }
    ReadTask90(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c48 = v_const2c624232cdd221771294dfbb;
      u64 v_c49 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c47, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m121) {
        u64 v_c50 = m121[1];
        if (buckethash(v_c50) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex77, std::array<u64,3>{v_c49, 0, 0})) return;
        slog::join_probe<3,2>(st_insindex78, std::array<u64,3>{v_c48, v_c50, 0}, [&](const std::array<u64,3>& m122) {
          u64 v_c51 = m122[2];
          if (!slog::exists_probe<3,1>($sup97714x23x0x0x1index79, std::array<u64,3>{v_c51, 0, 0})) return;
          slog::join_probe<2,1>(st_ins_ansindex80, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m123) {
            u64 v_c52 = m123[1];
            if (!slog::exists_probe<3,2>(st_insindex81, std::array<u64,3>{v_c49, v_c52, 0})) return;
            slog::join_probe<3,2>($sup97714x23x0x0x1index82, std::array<u64,3>{v_c51, v_c52, 0}, [&](const std::array<u64,3>& m124) {
              u64 v_c20 = m124[2];
              if (!slog::exists_probe<1,1>(canonindex83, std::array<u64,1>{v_c20})) return;
              if (!slog::exists_probe<3,1>(st_diffindex84, std::array<u64,3>{v_c20, 0, 0})) return;
              slog::join_probe<3,2>(st_insindex85, std::array<u64,3>{v_c49, v_c52, 0}, [&](const std::array<u64,3>& m125) {
                u64 v_c53 = m125[2];
                slog::join_probe<1,1>(canonindex86, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m126) {
                  slog::join_probe<2,1>(st_ins_ansindex87, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m127) {
                    u64 v_c54 = m127[1];
                    slog::join_probe<3,2>(st_diffindex88, std::array<u64,3>{v_c20, v_c54, 0}, [&](const std::array<u64,3>& m128) {
                      u64 v_c55 = m128[2];
                      slog::join_probe<2,1>(st_diff_ansindex89, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m129) {
                        u64 v_c14 = m129[1];
                        ++_fires;
                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c14}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:24", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask90* _cont = new ReadTask90(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask90(db,b), true);
  // (crule (pre) (scan int_overflow __erre6UN01463 __errf4EAL1464 __errf1RoY1465 __errf1p0v1466) (body) (head (emit error (0) __erre6UN01463)) <internal>:1 #f)
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
      outer_rel = db->getRelation("int_overflow");
  
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
        u64 v_c56 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c58 = _t[2];
        u64 v_c59 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c56}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
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
  // (crule (pre) (scan malformed_deduction __erre1VzC1452 __errf9zzf1453 __errf8qkv1454 __errf6QgN1455 __errf70vb1456) (body) (head (emit error (0) __erre1VzC1452)) <internal>:1 #f)
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
      outer_rel = db->getRelation("malformed_deduction");
  
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
        u64 v_c60 = _t[0];
        u64 v_c61 = _t[1];
        u64 v_c62 = _t[2];
        u64 v_c63 = _t[3];
        u64 v_c64 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c60}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre8wIB1457 __errf6v8C1458 __errf12st1459) (body) (head (emit error (0) __erre8wIB1457)) <internal>:1 #f)
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
      outer_rel = db->getRelation("div_by_zero");
  
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
        u64 v_c65 = _t[0];
        u64 v_c66 = _t[1];
        u64 v_c67 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c65}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre (let __trid0ErY707 const606e06328e00dd103d4f84bc) (let __trel1zJL708 const18fb5942c65f2f8b5fee74d1) (let __tcol6RRe709 const5feceb66ffc86f38d952786c)) (scan $sup9688x164x0x0x0 __d0 l m p r) (body) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0ErY707 __trel1zJL708 __tcol6RRe709 (1 2 3 4 0)) (mkstruct st_size (1 0) __6fnY706 r)) set.slog:165 #f)
  class ReadTask142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid140;  u32 sid139;  u32 sid141;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_size");
      outer_rel = db->getRelation("$sup9688x164x0x0x0");
      sid140 = db->getRelation("_enum")->getStructId();
      sid139 = db->getRelation("pbranch")->getStructId();
      sid141 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c68 = v_const606e06328e00dd103d4f84bc;
      u64 v_c69 = v_const18fb5942c65f2f8b5fee74d1;
      u64 v_c70 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c10 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c14 = _t[4];
        ++_fires;
        if (!((is_struct(v_c14) && (decode_struct_id(v_c14) == sid139 || decode_struct_id(v_c14) == sid140 || decode_struct_id(v_c14) == sid141))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c68, v_c69, v_c70, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:165", "delta:$sup9688x164x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask142* _cont = new ReadTask142(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask142(db,b), false);
  // (crule (pre) (scan type_mismatch __erre8cY11474 __errf718h1475 __errf7Add1476 __errf37cQ1477 __errf3s5R1478) (body) (head (emit error (0) __erre8cY11474)) <internal>:1 #f)
  class ReadTask143 : public slog::Task
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
      std::vector<u16> ord144({0});
      slog::Relation* readrel145 = db->getRelation("error");
      head_index[0] = readrel145->getIndex(ord144, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask143(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c71 = _t[0];
        u64 v_c72 = _t[1];
        u64 v_c73 = _t[2];
        u64 v_c74 = _t[3];
        u64 v_c75 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c71}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask143* _cont = new ReadTask143(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask143(db,b), false);
  // (crule (pre (let __tconst7FOC366 const4e07408562bedb8b60ce05c1)) (probe st_mem0 (2 0 1) 1 __tconst7FOC366 __t55M4367 s) (body (join canon (0) 1 s) (join st_mem0_ans (0 1) 1 __t55M4367 a)) (head (emit m (0 1) __tconst7FOC366 a)) st_basic.slog:21 #f)
  class ReadTask148 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** canonindex146;  slog::Index** st_mem0_ansindex147;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("m");
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("m");
      head_index[0] = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({2, 0, 1});
      slog::Relation* readrel152 = db->getRelation("st_mem0");
      driver_index = readrel152->getIndex(ord151, true);
      std::vector<u16> ord153({0});
      slog::Relation* readrel154 = db->getRelation("canon");
      canonindex146 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({0, 1});
      slog::Relation* readrel156 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex147 = readrel156->getIndex(ord155, false);
  
    }
    ReadTask148(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c76 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c76, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m157) {
        u64 v_c77 = m157[1];
        u64 v_c20 = m157[2];
        if (buckethash(v_c77) != bucket) return;
        slog::join_probe<1,1>(canonindex146, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m158) {
          slog::join_probe<2,1>(st_mem0_ansindex147, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m159) {
            u64 v_c46 = m159[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c76, v_c46}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:21", "all:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask148* _cont = new ReadTask148(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask148(db,b), true);
  // (crule (pre (let __tconst0RCW553 const6b86b273ff34fce19d6b804e)) (scan st_mem __t7oDS552 __t2kqQ551 k) (body (join pbranch (0 1 2 3 4) 1 __t2kqQ551 p m l r) (let __t8VFL554 (band k m)) (cmp lt __t8VFL554 __tconst0RCW553)) (head (emit $sup9688x61x0x0x0 (0 1 2 3 4 5) __t7oDS552 k l m p r)) set.slog:62 #f)
  class ReadTask161 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex160;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x61x0x0x0");
      std::vector<u16> ord162({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel163 = db->getRelation("$sup9688x61x0x0x0");
      head_index[0] = readrel163->getIndex(ord162, false);
      outer_rel = db->getRelation("st_mem");
      std::vector<u16> ord164({0, 1, 2, 3, 4});
      slog::Relation* readrel165 = db->getRelation("pbranch");
      pbranchindex160 = readrel165->getIndex(ord164, false);
  
    }
    ReadTask161(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c78 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c79 = _t[0];
        u64 v_c80 = _t[1];
        u64 v_c31 = _t[2];
        slog::join_probe<5,1>(pbranchindex160, std::array<u64,5>{v_c80, 0, 0, 0, 0}, [&](const std::array<u64,5>& m166) {
          u64 v_c13 = m166[1]; u64 v_c12 = m166[2]; u64 v_c11 = m166[3]; u64 v_c14 = m166[4];
          u64 v_c81 = _prim_band(db, v_c31, v_c12);
          if (v_c81 == slog_error) { slog::emit_pending_error(db, "set.slog:62"); return; }
          u64 v_c82 = _prim_lt(db, v_c81, v_c78);
          if (v_c82 == slog_error) { slog::emit_pending_error(db, "set.slog:62"); return; }
          if (!v_c82) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c79, v_c31, v_c11, v_c12, v_c13, v_c14}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:62", "delta:st_mem", _fires);
  
      if (!_done)
      {
        ReadTask161* _cont = new ReadTask161(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask161(db,b), false);
  // (crule (pre (let __tconst8KvO373 const5feceb66ffc86f38d952786c)) (scan st_mem __t85K3372 __t6yNI371 k) (body (join pbranch (0 1 2 3 4) 1 __t6yNI371 p m l r) (let __t8iWf374 (band k m)) (cmp gt __t8iWf374 __tconst8KvO373)) (head (emit $sup9688x62x0x0x0 (0 1 2 3 4 5) __t85K3372 k l m p r)) set.slog:63 #f)
  class ReadTask169 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex168;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x62x0x0x0");
      std::vector<u16> ord170({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel171 = db->getRelation("$sup9688x62x0x0x0");
      head_index[0] = readrel171->getIndex(ord170, false);
      outer_rel = db->getRelation("st_mem");
      std::vector<u16> ord172({0, 1, 2, 3, 4});
      slog::Relation* readrel173 = db->getRelation("pbranch");
      pbranchindex168 = readrel173->getIndex(ord172, false);
  
    }
    ReadTask169(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
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
        u64 v_c85 = _t[1];
        u64 v_c31 = _t[2];
        slog::join_probe<5,1>(pbranchindex168, std::array<u64,5>{v_c85, 0, 0, 0, 0}, [&](const std::array<u64,5>& m174) {
          u64 v_c13 = m174[1]; u64 v_c12 = m174[2]; u64 v_c11 = m174[3]; u64 v_c14 = m174[4];
          u64 v_c86 = _prim_band(db, v_c31, v_c12);
          if (v_c86 == slog_error) { slog::emit_pending_error(db, "set.slog:63"); return; }
          u64 v_c87 = _prim_gt(db, v_c86, v_c83);
          if (v_c87 == slog_error) { slog::emit_pending_error(db, "set.slog:63"); return; }
          if (!v_c87) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c84, v_c31, v_c11, v_c12, v_c13, v_c14}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:63", "delta:st_mem", _fires);
  
      if (!_done)
      {
        ReadTask169* _cont = new ReadTask169(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask169(db,b), false);
  s->addReadRel("$sup9688x164x0x0x0");
  s->addReadRel("$sup9688x61x0x0x0");
  s->addReadRel("$sup9688x62x0x0x0");
  s->addReadRel("$sup97714x23x0x0x1");
  s->addReadRel("_enum");
  s->addReadRel("canon");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("pbranch");
  s->addReadRel("st_del");
  s->addReadRel("st_del_ans");
  s->addReadRel("st_diff");
  s->addReadRel("st_diff_ans");
  s->addReadRel("st_ins");
  s->addReadRel("st_ins_ans");
  s->addReadRel("st_mem");
  s->addReadRel("st_mem0");
  s->addReadRel("st_mem0_ans");
  s->addReadRel("st_size");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$seq_atr");
  s->addDynamicRel("$sup9688x164x0x0x0");
  s->addDynamicRel("$sup9688x61x0x0x0");
  s->addDynamicRel("$sup9688x62x0x0x0");
  s->addDynamicRel("afterdel");
  s->addDynamicRel("dif");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("m");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("st_mem");
  s->addDynamicRel("st_size");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addDynamicRel("upd");
  d->push(s);
  d->continueRun();
}

