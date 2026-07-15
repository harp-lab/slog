
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_conste3776bfed7f405de8017ecfa;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("010d6597");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_conste3776bfed7f405de8017ecfa = db->encodeString("pempty");
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
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord175({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord176({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord177({1, 2, 0});
    
    r->addIndex<3>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord178({0, 1, 2});
    
    r->addIndex<3>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp9ItJ1547");
  if (r == 0) db->addTempRelation("temp9ItJ1547", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("sz");
  if (r == 0) db->addRelation("sz", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("sz");
      std::vector<u16> ord179({0});
    
    r->addIndex<1>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("sz"), std::array<u16,1>{0}, b));
  r = db->getRelation("st_union_ans");
  if (r == 0) db->addRelation("st_union_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_union_ans");
      std::vector<u16> ord180({0, 1});
    
    r->addIndex<2>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_union_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_union");
  if (r == 0) db->addStruct("st_union", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_union");
      std::vector<u16> ord181({1, 2, 0});
    
    r->addIndex<3>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord182({0, 1, 2});
    
    r->addIndex<3>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_union"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_size_ans");
  if (r == 0) db->addRelation("st_size_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_size_ans");
      std::vector<u16> ord183({0, 1});
    
    r->addIndex<2>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord184({0, 1});
    
    r->addIndex<2>(ord184, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_size_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_size");
  if (r == 0) db->addStruct("st_size", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_size");
      std::vector<u16> ord185({1, 0});
    
    r->addIndex<2>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord186({0, 1});
    
    r->addIndex<2>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("st_size"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("st_msk_ans");
  if (r == 0) db->addRelation("st_msk_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_msk_ans");
      std::vector<u16> ord187({0, 1});
    
    r->addIndex<2>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_msk_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_msk");
  if (r == 0) db->addStruct("st_msk", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_msk");
      std::vector<u16> ord188({1, 2, 0});
    
    r->addIndex<3>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord189({0, 1, 2});
    
    r->addIndex<3>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_msk"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_mem_ans");
  if (r == 0) db->addRelation("st_mem_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem_ans");
      std::vector<u16> ord190({0, 1});
    
    r->addIndex<2>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_mem_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_mem0_ans");
  if (r == 0) db->addRelation("st_mem0_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem0_ans");
      std::vector<u16> ord191({0, 1});
    
    r->addIndex<2>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_mem0_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_mem0");
  if (r == 0) db->addStruct("st_mem0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem0");
      std::vector<u16> ord192({1, 2, 0});
    
    r->addIndex<3>(ord192, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord193({0, 1, 2});
    
    r->addIndex<3>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_mem0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_mem");
  if (r == 0) db->addStruct("st_mem", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem");
      std::vector<u16> ord194({2, 1, 0});
    
    r->addIndex<3>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord195({0, 2, 1});
    
    r->addIndex<3>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_mem"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("st_join_ans");
  if (r == 0) db->addRelation("st_join_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_join_ans");
      std::vector<u16> ord196({0, 1});
    
    r->addIndex<2>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_join_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_join");
  if (r == 0) db->addStruct("st_join", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_join");
      std::vector<u16> ord197({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord198({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("st_join"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("st_ins_ans");
  if (r == 0) db->addRelation("st_ins_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_ins_ans");
      std::vector<u16> ord199({0, 1});
    
    r->addIndex<2>(ord199, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_ins_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_ins");
  if (r == 0) db->addStruct("st_ins", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_ins");
      std::vector<u16> ord200({1, 2, 0});
    
    r->addIndex<3>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord201({0, 1, 2});
    
    r->addIndex<3>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_ins"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_hsb_ans");
  if (r == 0) db->addRelation("st_hsb_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_hsb_ans");
      std::vector<u16> ord202({0, 1});
    
    r->addIndex<2>(ord202, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_hsb_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_hsb");
  if (r == 0) db->addStruct("st_hsb", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_hsb");
      std::vector<u16> ord203({1, 0});
    
    r->addIndex<2>(ord203, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord204({0, 1});
    
    r->addIndex<2>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("st_hsb"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("st_fromlist_ans");
  if (r == 0) db->addRelation("st_fromlist_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord205({0, 1});
    
    r->addIndex<2>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_fromlist_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_fromlist");
  if (r == 0) db->addStruct("st_fromlist", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_fromlist");
      std::vector<u16> ord206({1, 0});
    
    r->addIndex<2>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord207({0, 1});
    
    r->addIndex<2>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("st_fromlist"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("st_diff_ans");
  if (r == 0) db->addRelation("st_diff_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_diff_ans");
      std::vector<u16> ord208({0, 1});
    
    r->addIndex<2>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_diff_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_diff");
  if (r == 0) db->addStruct("st_diff", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_diff");
      std::vector<u16> ord209({1, 2, 0});
    
    r->addIndex<3>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord210({0, 1, 2});
    
    r->addIndex<3>(ord210, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_diff"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_del_ans");
  if (r == 0) db->addRelation("st_del_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_del_ans");
      std::vector<u16> ord211({0, 1});
    
    r->addIndex<2>(ord211, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_del_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_del");
  if (r == 0) db->addStruct("st_del", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_del");
      std::vector<u16> ord212({1, 2, 0});
    
    r->addIndex<3>(ord212, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord213({0, 1, 2});
    
    r->addIndex<3>(ord213, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_del"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_bld_ans");
  if (r == 0) db->addRelation("st_bld_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_bld_ans");
      std::vector<u16> ord214({0, 1});
    
    r->addIndex<2>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_bld_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_bld");
  if (r == 0) db->addStruct("st_bld", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_bld");
      std::vector<u16> ord215({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord215, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord216({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("st_bld"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord217({1, 2, 0});
    
    r->addIndex<3>(ord217, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord218({0, 1, 2});
    
    r->addIndex<3>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("pleaf");
  if (r == 0) db->addStruct("pleaf", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pleaf");
      std::vector<u16> ord219({1, 0});
    
    r->addIndex<2>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord220({0, 1});
    
    r->addIndex<2>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("pleaf"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("pbranch");
  if (r == 0) db->addStruct("pbranch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pbranch");
      std::vector<u16> ord221({3, 1, 2, 4, 0});
    
    r->addIndex<5>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 1, 2, 4, 0}, false, b), true);
      std::vector<u16> ord222({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
      std::vector<u16> ord223({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord223, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("pbranch"), std::array<u16,5>{3, 1, 2, 4, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord224({1, 2, 3, 0});
    
    r->addIndex<4>(ord224, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord225({0, 1, 2, 3});
    
    r->addIndex<4>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord226({1, 2, 0});
    
    r->addIndex<3>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord227({0, 1, 2});
    
    r->addIndex<3>(ord227, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord228({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord229({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord229, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord230({1, 2, 0});
    
    r->addIndex<3>(ord230, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord231({0, 1, 2});
    
    r->addIndex<3>(ord231, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
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
  r = db->getRelation("m");
  if (r == 0) db->addRelation("m", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("m");
      std::vector<u16> ord234({0, 1});
    
    r->addIndex<2>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("m"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord235({1, 2, 3, 0});
    
    r->addIndex<4>(ord235, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord236({0, 1, 2, 3});
    
    r->addIndex<4>(ord236, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord237({0});
    
    r->addIndex<1>(ord237, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord238({1, 2, 0});
    
    r->addIndex<3>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord239({0, 1, 2});
    
    r->addIndex<3>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("dif");
  if (r == 0) db->addRelation("dif", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("dif");
      std::vector<u16> ord240({0});
    
    r->addIndex<1>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("dif"), std::array<u16,1>{0}, b));
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
  r = db->getRelation("$sup97714x23x0x0x1");
  if (r == 0) db->addRelation("$sup97714x23x0x0x1", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup97714x23x0x0x1");
      std::vector<u16> ord246({0, 1, 2});
    
    r->addIndex<3>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup97714x23x0x0x1"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup9688x90x0x0x0");
  if (r == 0) db->addRelation("$sup9688x90x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x90x0x0x0");
      std::vector<u16> ord247({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x90x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x88x0x0x0");
  if (r == 0) db->addRelation("$sup9688x88x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x88x0x0x0");
      std::vector<u16> ord248({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord248, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x88x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x87x0x0x0");
  if (r == 0) db->addRelation("$sup9688x87x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x87x0x0x0");
      std::vector<u16> ord249({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord249, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x87x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x72x0x0x0");
  if (r == 0) db->addRelation("$sup9688x72x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x72x0x0x0");
      std::vector<u16> ord250({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x72x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x70x0x0x0");
  if (r == 0) db->addRelation("$sup9688x70x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x70x0x0x0");
      std::vector<u16> ord251({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord251, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x70x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x69x0x0x0");
  if (r == 0) db->addRelation("$sup9688x69x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x69x0x0x0");
      std::vector<u16> ord252({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord252, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x69x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x62x0x0x0");
  if (r == 0) db->addRelation("$sup9688x62x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x62x0x0x0");
      std::vector<u16> ord253({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x62x0x0x0"), std::array<u16,6>{1, 5, 0, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x61x0x0x0");
  if (r == 0) db->addRelation("$sup9688x61x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x61x0x0x0");
      std::vector<u16> ord254({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord254, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x61x0x0x0"), std::array<u16,6>{1, 2, 0, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x54x0x0x0");
  if (r == 0) db->addRelation("$sup9688x54x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x54x0x0x0");
      std::vector<u16> ord255({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x54x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x52x0x0x1");
  if (r == 0) db->addRelation("$sup9688x52x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x52x0x0x1");
      std::vector<u16> ord256({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x52x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x52x0x0x0");
  if (r == 0) db->addRelation("$sup9688x52x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x52x0x0x0");
      std::vector<u16> ord257({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x52x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x50x0x0x1");
  if (r == 0) db->addRelation("$sup9688x50x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x50x0x0x1");
      std::vector<u16> ord258({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x50x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x50x0x0x0");
  if (r == 0) db->addRelation("$sup9688x50x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x50x0x0x0");
      std::vector<u16> ord259({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x50x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x40x0x0x2");
  if (r == 0) db->addRelation("$sup9688x40x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x40x0x0x2");
      std::vector<u16> ord260({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord260, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x40x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x40x0x0x1");
  if (r == 0) db->addRelation("$sup9688x40x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x40x0x0x1");
      std::vector<u16> ord261({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord261, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x40x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x40x0x0x0");
  if (r == 0) db->addRelation("$sup9688x40x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x40x0x0x0");
      std::vector<u16> ord262({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup9688x40x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x36x0x0x2");
  if (r == 0) db->addRelation("$sup9688x36x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x36x0x0x2");
      std::vector<u16> ord263({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x36x0x0x2"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x36x0x0x1");
  if (r == 0) db->addRelation("$sup9688x36x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x36x0x0x1");
      std::vector<u16> ord264({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x36x0x0x1"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x36x0x0x0");
  if (r == 0) db->addRelation("$sup9688x36x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x36x0x0x0");
      std::vector<u16> ord265({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup9688x36x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x168x0x0x0");
  if (r == 0) db->addRelation("$sup9688x168x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x168x0x0x0");
      std::vector<u16> ord266({0, 1, 2, 3});
    
    r->addIndex<4>(ord266, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup9688x168x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup9688x164x0x0x0");
  if (r == 0) db->addRelation("$sup9688x164x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x164x0x0x0");
      std::vector<u16> ord267({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord267, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, false, b), true);
      std::vector<u16> ord268({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord268, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup9688x164x0x0x0"), std::array<u16,5>{1, 0, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x154x0x0x0");
  if (r == 0) db->addRelation("$sup9688x154x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x154x0x0x0");
      std::vector<u16> ord269({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x154x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x151x0x0x0");
  if (r == 0) db->addRelation("$sup9688x151x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x151x0x0x0");
      std::vector<u16> ord270({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord270, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x151x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x148x0x0x0");
  if (r == 0) db->addRelation("$sup9688x148x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x148x0x0x0");
      std::vector<u16> ord271({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord271, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x148x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x145x0x0x0");
  if (r == 0) db->addRelation("$sup9688x145x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x145x0x0x0");
      std::vector<u16> ord272({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord272, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x145x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x142x0x0x0");
  if (r == 0) db->addRelation("$sup9688x142x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x142x0x0x0");
      std::vector<u16> ord273({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x142x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x139x0x0x0");
  if (r == 0) db->addRelation("$sup9688x139x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x139x0x0x0");
      std::vector<u16> ord274({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord274, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x139x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x136x0x0x0");
  if (r == 0) db->addRelation("$sup9688x136x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x136x0x0x0");
      std::vector<u16> ord275({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord275, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x136x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x120x0x0x0");
  if (r == 0) db->addRelation("$sup9688x120x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x120x0x0x0");
      std::vector<u16> ord276({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord276, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x120x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x117x0x0x1");
  if (r == 0) db->addRelation("$sup9688x117x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x117x0x0x1");
      std::vector<u16> ord277({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x117x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup9688x117x0x0x0");
  if (r == 0) db->addRelation("$sup9688x117x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x117x0x0x0");
      std::vector<u16> ord278({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord278, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x117x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x114x0x0x1");
  if (r == 0) db->addRelation("$sup9688x114x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x114x0x0x1");
      std::vector<u16> ord279({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord279, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x114x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup9688x114x0x0x0");
  if (r == 0) db->addRelation("$sup9688x114x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x114x0x0x0");
      std::vector<u16> ord280({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x114x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x110x0x0x0");
  if (r == 0) db->addRelation("$sup9688x110x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x110x0x0x0");
      std::vector<u16> ord281({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x110x0x0x0"), std::array<u16,11>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x106x0x0x1");
  if (r == 0) db->addRelation("$sup9688x106x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x106x0x0x1");
      std::vector<u16> ord282({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord282, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x106x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup9688x106x0x0x0");
  if (r == 0) db->addRelation("$sup9688x106x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x106x0x0x0");
      std::vector<u16> ord283({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord283, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x106x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x103x0x0x1");
  if (r == 0) db->addRelation("$sup9688x103x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x103x0x0x1");
      std::vector<u16> ord284({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord284, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x103x0x0x1"), std::array<u16,10>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup9688x103x0x0x0");
  if (r == 0) db->addRelation("$sup9688x103x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x103x0x0x0");
      std::vector<u16> ord285({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord285, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x103x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x100x0x0x0");
  if (r == 0) db->addRelation("$sup9688x100x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x100x0x0x0");
      std::vector<u16> ord286({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord286, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x100x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$seq_atr");
  if (r == 0) db->addRelation("$seq_atr", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_atr");
      std::vector<u16> ord287({0, 1, 2});
    
    r->addIndex<3>(ord287, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_atr"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord288({0, 1, 2});
    
    r->addIndex<3>(ord288, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("st_fromlist"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan modulo_by_zero __erre9lZU1520 __errf9hys1521 __errf7bpf1522) (body) (head (emit error (0) __erre9lZU1520)) <internal>:1 #f)
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
      outer_rel = db->getRelation("modulo_by_zero");
  
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
  // (crule (pre (let __tconst2m4g807 conste3776bfed7f405de8017ecfa) (let __tconst7yNB142 const5feceb66ffc86f38d952786c)) (probe _enum (1 0) 1 __tconst2m4g807 __t9hVK143) (body (join st_size (1 0) 1 __t9hVK143 __t9PTQ144)) (head (emit st_size_ans (0 1) __t9PTQ144 __tconst7yNB142)) set.slog:163 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** st_sizeindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_size_ans");
      std::vector<u16> ord5({0, 1});
      slog::Relation* readrel6 = db->getRelation("st_size_ans");
      head_index[0] = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("_enum");
      driver_index = readrel8->getIndex(ord7, true);
      std::vector<u16> ord9({1, 0});
      slog::Relation* readrel10 = db->getRelation("st_size");
      st_sizeindex3 = readrel10->getIndex(ord9, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c3, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m11) {
        u64 v_c5 = m11[1];
        if (buckethash(v_c5) != bucket) return;
        slog::join_probe<2,1>(st_sizeindex3, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m12) {
          u64 v_c6 = m12[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c4}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:163", "all:_enum", _fires);
  
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
  // (crule (pre (let __tconst6HhL447 const6b86b273ff34fce19d6b804e)) (scan pleaf __t4ECD448 k) (body (join st_size (1 0) 1 __t4ECD448 __t7JUL449)) (head (emit st_size_ans (0 1) __t7JUL449 __tconst6HhL447)) set.slog:164 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_sizeindex13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_size_ans");
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("st_size_ans");
      head_index[0] = readrel16->getIndex(ord15, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord17({1, 0});
      slog::Relation* readrel18 = db->getRelation("st_size");
      st_sizeindex13 = readrel18->getIndex(ord17, false);
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
  
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
        slog::join_probe<2,1>(st_sizeindex13, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m19) {
          u64 v_c10 = m19[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c7}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:164", "all:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask14* _cont = new ReadTask14(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask14(db,b), true);
  // (crule (pre (let __tconst11Ij204 const5feceb66ffc86f38d952786c)) (scan st_mem_ans __t5rNy206 a) (body (join st_mem (0 2 1) 1 __t5rNy206 k r) (exists pbranch (4 0 1 2 3) 1 r) (exists st_mem (2 1 0) 1 k) (join $sup9688x62x0x0x0 (1 5 0 2 3 4) 2 k r __t6Ulg203 l m p) (exists st_mem (0 2 1) 2 __t6Ulg203 k) (join pbranch (3 1 2 4 0) 4 l p m r __t6CZW202) (join st_mem (0 2 1) 3 __t6Ulg203 k __t6CZW202) (let __t6ihR205 (band k m)) (cmp gt __t6ihR205 __tconst11Ij204)) (head (emit st_mem_ans (0 1) __t6Ulg203 a)) set.slog:63 #f)
  class ReadTask27 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_memindex20;  slog::Index** pbranchindex21;  slog::Index** st_memindex22;  slog::Index** $sup9688x62x0x0x0index23;  slog::Index** st_memindex24;  slog::Index** pbranchindex25;  slog::Index** st_memindex26;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem_ans");
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("st_mem_ans");
      head_index[0] = readrel29->getIndex(ord28, false);
      outer_rel = db->getRelation("st_mem_ans");
      std::vector<u16> ord30({0, 2, 1});
      slog::Relation* readrel31 = db->getRelation("st_mem");
      st_memindex20 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({4, 0, 1, 2, 3});
      slog::Relation* readrel33 = db->getRelation("pbranch");
      pbranchindex21 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({2, 1, 0});
      slog::Relation* readrel35 = db->getRelation("st_mem");
      st_memindex22 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel37 = db->getRelation("$sup9688x62x0x0x0");
      $sup9688x62x0x0x0index23 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({0, 2, 1});
      slog::Relation* readrel39 = db->getRelation("st_mem");
      st_memindex24 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({3, 1, 2, 4, 0});
      slog::Relation* readrel41 = db->getRelation("pbranch");
      pbranchindex25 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({0, 2, 1});
      slog::Relation* readrel43 = db->getRelation("st_mem");
      st_memindex26 = readrel43->getIndex(ord42, false);
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
  
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
        slog::join_probe<3,1>(st_memindex20, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m44) {
          u64 v_c9 = m44[1]; u64 v_c14 = m44[2];
          if (!slog::exists_probe<5,1>(pbranchindex21, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_memindex22, std::array<u64,3>{v_c9, 0, 0})) return;
          slog::join_probe<6,2>($sup9688x62x0x0x0index23, std::array<u64,6>{v_c9, v_c14, 0, 0, 0, 0}, [&](const std::array<u64,6>& m45) {
            u64 v_c15 = m45[2]; u64 v_c16 = m45[3]; u64 v_c17 = m45[4]; u64 v_c18 = m45[5];
            if (!slog::exists_probe<3,2>(st_memindex24, std::array<u64,3>{v_c15, v_c9, 0})) return;
            slog::join_probe<5,4>(pbranchindex25, std::array<u64,5>{v_c16, v_c18, v_c17, v_c14, 0}, [&](const std::array<u64,5>& m46) {
              u64 v_c19 = m46[4];
              slog::join_probe<3,3>(st_memindex26, std::array<u64,3>{v_c15, v_c9, v_c19}, [&](const std::array<u64,3>& m47) {
                u64 v_c20 = _prim_band(db, v_c9, v_c17);
                if (v_c20 == slog_error) { slog::emit_pending_error(db, "set.slog:63"); return; }
                u64 v_c21 = _prim_gt(db, v_c20, v_c11);
                if (v_c21 == slog_error) { slog::emit_pending_error(db, "set.slog:63"); return; }
                if (!v_c21) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c15, v_c13}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:63", "delta:st_mem_ans", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre4baG1517 __errf19kR1518 __errf2MSY1519) (body) (head (emit error (0) __erre4baG1517)) <internal>:1 #f)
  class ReadTask49 : public slog::Task
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
      std::vector<u16> ord50({0});
      slog::Relation* readrel51 = db->getRelation("error");
      head_index[0] = readrel51->getIndex(ord50, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask49(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c22}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask49* _cont = new ReadTask49(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask49(db,b), false);
  // (crule (pre) (scan st_size_ans __t6AK3178 __v0) (body (join st_size (0 1) 1 __t6AK3178 l) (exists pbranch (3 1 2 4 0) 1 l) (join $sup9688x164x0x0x0 (1 0 2 3 4) 1 l __t1U9V177 m p r) (exists st_size (1 0) 1 r) (join pbranch (3 1 2 4 0) 4 l p m r __t8SqL176) (join st_size (0 1) 2 __t1U9V177 __t8SqL176) (join st_size (1 0) 1 r __t46sD179) (join-old st_size_ans (0 1) 1 (0 1) __t46sD179 __v1) (let __t0Opc175 (_0002b __v0 __v1))) (head (emit-temp temp9ItJ1547 __t0Opc175 __t1U9V177)) set.slog:165 #f)
  class ReadTask61 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_sizeindex52;  slog::Index** pbranchindex53;  slog::Index** $sup9688x164x0x0x0index54;  slog::Index** st_sizeindex55;  slog::Index** pbranchindex56;  slog::Index** st_sizeindex57;  slog::Index** st_sizeindex58;  slog::Index** st_size_ansindex59;  slog::Index** st_size_ansdelta60;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9ItJ1547");
      outer_rel = db->getRelation("st_size_ans");
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("st_size");
      st_sizeindex52 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({3, 1, 2, 4, 0});
      slog::Relation* readrel65 = db->getRelation("pbranch");
      pbranchindex53 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 0, 2, 3, 4});
      slog::Relation* readrel67 = db->getRelation("$sup9688x164x0x0x0");
      $sup9688x164x0x0x0index54 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 0});
      slog::Relation* readrel69 = db->getRelation("st_size");
      st_sizeindex55 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({3, 1, 2, 4, 0});
      slog::Relation* readrel71 = db->getRelation("pbranch");
      pbranchindex56 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({0, 1});
      slog::Relation* readrel73 = db->getRelation("st_size");
      st_sizeindex57 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({1, 0});
      slog::Relation* readrel75 = db->getRelation("st_size");
      st_sizeindex58 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({0, 1});
      slog::Relation* readrel77 = db->getRelation("st_size_ans");
      st_size_ansindex59 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("st_size_ans");
      st_size_ansdelta60 = readrel79->getIndex(ord78, true);
  
    }
    ReadTask61(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(st_sizeindex52, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m80) {
          u64 v_c16 = m80[1];
          if (!slog::exists_probe<5,1>(pbranchindex53, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
          slog::join_probe<5,1>($sup9688x164x0x0x0index54, std::array<u64,5>{v_c16, 0, 0, 0, 0}, [&](const std::array<u64,5>& m81) {
            u64 v_c27 = m81[1]; u64 v_c17 = m81[2]; u64 v_c18 = m81[3]; u64 v_c14 = m81[4];
            if (!slog::exists_probe<2,1>(st_sizeindex55, std::array<u64,2>{v_c14, 0})) return;
            slog::join_probe<5,4>(pbranchindex56, std::array<u64,5>{v_c16, v_c18, v_c17, v_c14, 0}, [&](const std::array<u64,5>& m82) {
              u64 v_c28 = m82[4];
              slog::join_probe<2,2>(st_sizeindex57, std::array<u64,2>{v_c27, v_c28}, [&](const std::array<u64,2>& m83) {
                slog::join_probe<2,1>(st_sizeindex58, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m84) {
                  u64 v_c29 = m84[1];
                  slog::join_probe_old<2,1>(st_size_ansindex59, st_size_ansdelta60, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m85) {
                    u64 v_c30 = m85[1];
                    u64 v_c31 = _prim__0002b(db, v_c26, v_c30);
                    if (v_c31 == slog_error) { slog::emit_pending_error(db, "set.slog:165"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c31, v_c27});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:165", "delta:st_size_ans", _fires);
  
      if (!_done)
      {
        ReadTask61* _cont = new ReadTask61(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask61(db,b), false);
  // (crule (pre (let __tconst0qdu476 const6b86b273ff34fce19d6b804e)) (scan pleaf __t34Vl477 k) (body (join st_mem (2 1 0) 2 k __t34Vl477 __t81An478)) (head (emit st_mem_ans (0 1) __t81An478 __tconst0qdu476)) set.slog:61 #f)
  class ReadTask87 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_memindex86;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem_ans");
      std::vector<u16> ord88({0, 1});
      slog::Relation* readrel89 = db->getRelation("st_mem_ans");
      head_index[0] = readrel89->getIndex(ord88, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord90({2, 1, 0});
      slog::Relation* readrel91 = db->getRelation("st_mem");
      st_memindex86 = readrel91->getIndex(ord90, false);
  
    }
    ReadTask87(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c33 = _t[0];
        u64 v_c9 = _t[1];
        slog::join_probe<3,2>(st_memindex86, std::array<u64,3>{v_c9, v_c33, 0}, [&](const std::array<u64,3>& m92) {
          u64 v_c34 = m92[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c34, v_c32}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:61", "all:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask87* _cont = new ReadTask87(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask87(db,b), true);
  // (crule (pre) (scan type_mismatch __erre3Tis1534 __errf4Vst1535 __errf9cVr1536 __errf0D5s1537 __errf3mTy1538) (body) (head (emit error (0) __erre3Tis1534)) <internal>:1 #f)
  class ReadTask93 : public slog::Task
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
      std::vector<u16> ord94({0});
      slog::Relation* readrel95 = db->getRelation("error");
      head_index[0] = readrel95->getIndex(ord94, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask93(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c35}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask93* _cont = new ReadTask93(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask93(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre9GiY1544 __errf6rYT1545 __errf4pgJ1546) (body) (head (emit error (0) __erre9GiY1544)) <internal>:1 #f)
  class ReadTask96 : public slog::Task
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
      std::vector<u16> ord97({0});
      slog::Relation* readrel98 = db->getRelation("error");
      head_index[0] = readrel98->getIndex(ord97, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask96(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask96* _cont = new ReadTask96(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask96(db,b), false);
  // (crule (pre (let __tconst3pO7221 const6b86b273ff34fce19d6b804e)) (scan st_mem_ans __t0BkK223 a) (body (join st_mem (0 2 1) 1 __t0BkK223 k l) (exists pbranch (3 1 2 4 0) 1 l) (exists st_mem (2 1 0) 1 k) (join $sup9688x61x0x0x0 (1 2 0 3 4 5) 2 k l __t6abM220 m p r) (exists st_mem (0 2 1) 2 __t6abM220 k) (join pbranch (3 1 2 4 0) 4 l p m r __t58iN219) (join st_mem (0 2 1) 3 __t6abM220 k __t58iN219) (let __t1EHj222 (band k m)) (cmp lt __t1EHj222 __tconst3pO7221)) (head (emit st_mem_ans (0 1) __t6abM220 a)) set.slog:62 #f)
  class ReadTask106 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_memindex99;  slog::Index** pbranchindex100;  slog::Index** st_memindex101;  slog::Index** $sup9688x61x0x0x0index102;  slog::Index** st_memindex103;  slog::Index** pbranchindex104;  slog::Index** st_memindex105;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem_ans");
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("st_mem_ans");
      head_index[0] = readrel108->getIndex(ord107, false);
      outer_rel = db->getRelation("st_mem_ans");
      std::vector<u16> ord109({0, 2, 1});
      slog::Relation* readrel110 = db->getRelation("st_mem");
      st_memindex99 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({3, 1, 2, 4, 0});
      slog::Relation* readrel112 = db->getRelation("pbranch");
      pbranchindex100 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({2, 1, 0});
      slog::Relation* readrel114 = db->getRelation("st_mem");
      st_memindex101 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel116 = db->getRelation("$sup9688x61x0x0x0");
      $sup9688x61x0x0x0index102 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({0, 2, 1});
      slog::Relation* readrel118 = db->getRelation("st_mem");
      st_memindex103 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({3, 1, 2, 4, 0});
      slog::Relation* readrel120 = db->getRelation("pbranch");
      pbranchindex104 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({0, 2, 1});
      slog::Relation* readrel122 = db->getRelation("st_mem");
      st_memindex105 = readrel122->getIndex(ord121, false);
  
    }
    ReadTask106(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c13 = _t[1];
        slog::join_probe<3,1>(st_memindex99, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m123) {
          u64 v_c9 = m123[1]; u64 v_c16 = m123[2];
          if (!slog::exists_probe<5,1>(pbranchindex100, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_memindex101, std::array<u64,3>{v_c9, 0, 0})) return;
          slog::join_probe<6,2>($sup9688x61x0x0x0index102, std::array<u64,6>{v_c9, v_c16, 0, 0, 0, 0}, [&](const std::array<u64,6>& m124) {
            u64 v_c45 = m124[2]; u64 v_c17 = m124[3]; u64 v_c18 = m124[4]; u64 v_c14 = m124[5];
            if (!slog::exists_probe<3,2>(st_memindex103, std::array<u64,3>{v_c45, v_c9, 0})) return;
            slog::join_probe<5,4>(pbranchindex104, std::array<u64,5>{v_c16, v_c18, v_c17, v_c14, 0}, [&](const std::array<u64,5>& m125) {
              u64 v_c46 = m125[4];
              slog::join_probe<3,3>(st_memindex105, std::array<u64,3>{v_c45, v_c9, v_c46}, [&](const std::array<u64,3>& m126) {
                u64 v_c47 = _prim_band(db, v_c9, v_c17);
                if (v_c47 == slog_error) { slog::emit_pending_error(db, "set.slog:62"); return; }
                u64 v_c48 = _prim_lt(db, v_c47, v_c43);
                if (v_c48 == slog_error) { slog::emit_pending_error(db, "set.slog:62"); return; }
                if (!v_c48) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c13}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:62", "delta:st_mem_ans", _fires);
  
      if (!_done)
      {
        ReadTask106* _cont = new ReadTask106(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask106(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre2cq21539 __errf962i1540 __errf1qmZ1541 __errf1ZnB1542 __errf7Mv21543) (body) (head (emit error (0) __erre2cq21539)) <internal>:1 #f)
  class ReadTask128 : public slog::Task
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
      std::vector<u16> ord129({0});
      slog::Relation* readrel130 = db->getRelation("error");
      head_index[0] = readrel130->getIndex(ord129, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask128(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c52 = _t[3];
        u64 v_c53 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c49}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre) (scan toint_range __erre10Pc1531 __errf0qqQ1532 __errf7AQ01533) (body) (head (emit error (0) __erre10Pc1531)) <internal>:1 #f)
  class ReadTask131 : public slog::Task
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
      std::vector<u16> ord132({0});
      slog::Relation* readrel133 = db->getRelation("error");
      head_index[0] = readrel133->getIndex(ord132, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask131(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[0];
        u64 v_c55 = _t[1];
        u64 v_c56 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c54}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask131* _cont = new ReadTask131(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask131(db,b), false);
  // (crule (pre) (scan nan_result __erre8KAR1527 __errf87uz1528 __errf5kiN1529 __errf4OX01530) (body) (head (emit error (0) __erre8KAR1527)) <internal>:1 #f)
  class ReadTask134 : public slog::Task
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
      std::vector<u16> ord135({0});
      slog::Relation* readrel136 = db->getRelation("error");
      head_index[0] = readrel136->getIndex(ord135, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask134(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c60 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask134* _cont = new ReadTask134(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask134(db,b), false);
  // (crule (pre) (scan temp9ItJ1547 __t0Opc175 __t1U9V177) (body) (head (emit st_size_ans (0 1) __t1U9V177 __t0Opc175)) set.slog:165 #f)
  class ReadTask137 : public slog::Task
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
      head_rel[0] = db->getRelation("st_size_ans");
      std::vector<u16> ord138({0, 1});
      slog::Relation* readrel139 = db->getRelation("st_size_ans");
      head_index[0] = readrel139->getIndex(ord138, false);
      outer_rel = db->getRelation("temp9ItJ1547");
  
    }
    ReadTask137(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c27, v_c31}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:165", "delta:temp9ItJ1547", _fires);
  
      if (!_done)
      {
        ReadTask137* _cont = new ReadTask137(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask137(db,b), false);
  // (crule (pre) (scan st_size_ans __t46sD179 __v1) (body (join st_size (0 1) 1 __t46sD179 r) (exists pbranch (4 0 1 2 3) 1 r) (join $sup9688x164x0x0x0 (4 0 1 2 3) 1 r __t1U9V177 l m p) (exists st_size (1 0) 1 l) (join pbranch (3 1 2 4 0) 4 l p m r __t8SqL176) (join st_size (0 1) 2 __t1U9V177 __t8SqL176) (join st_size (1 0) 1 l __t6AK3178) (join st_size_ans (0 1) 1 __t6AK3178 __v0) (let __t0Opc175 (_0002b __v0 __v1))) (head (emit-temp temp9ItJ1547 __t0Opc175 __t1U9V177)) set.slog:165 #f)
  class ReadTask148 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_sizeindex140;  slog::Index** pbranchindex141;  slog::Index** $sup9688x164x0x0x0index142;  slog::Index** st_sizeindex143;  slog::Index** pbranchindex144;  slog::Index** st_sizeindex145;  slog::Index** st_sizeindex146;  slog::Index** st_size_ansindex147;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9ItJ1547");
      outer_rel = db->getRelation("st_size_ans");
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("st_size");
      st_sizeindex140 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({4, 0, 1, 2, 3});
      slog::Relation* readrel152 = db->getRelation("pbranch");
      pbranchindex141 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({4, 0, 1, 2, 3});
      slog::Relation* readrel154 = db->getRelation("$sup9688x164x0x0x0");
      $sup9688x164x0x0x0index142 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 0});
      slog::Relation* readrel156 = db->getRelation("st_size");
      st_sizeindex143 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({3, 1, 2, 4, 0});
      slog::Relation* readrel158 = db->getRelation("pbranch");
      pbranchindex144 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({0, 1});
      slog::Relation* readrel160 = db->getRelation("st_size");
      st_sizeindex145 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 0});
      slog::Relation* readrel162 = db->getRelation("st_size");
      st_sizeindex146 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({0, 1});
      slog::Relation* readrel164 = db->getRelation("st_size_ans");
      st_size_ansindex147 = readrel164->getIndex(ord163, false);
  
    }
    ReadTask148(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c29 = _t[0];
        u64 v_c30 = _t[1];
        slog::join_probe<2,1>(st_sizeindex140, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m165) {
          u64 v_c14 = m165[1];
          if (!slog::exists_probe<5,1>(pbranchindex141, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
          slog::join_probe<5,1>($sup9688x164x0x0x0index142, std::array<u64,5>{v_c14, 0, 0, 0, 0}, [&](const std::array<u64,5>& m166) {
            u64 v_c27 = m166[1]; u64 v_c16 = m166[2]; u64 v_c17 = m166[3]; u64 v_c18 = m166[4];
            if (!slog::exists_probe<2,1>(st_sizeindex143, std::array<u64,2>{v_c16, 0})) return;
            slog::join_probe<5,4>(pbranchindex144, std::array<u64,5>{v_c16, v_c18, v_c17, v_c14, 0}, [&](const std::array<u64,5>& m167) {
              u64 v_c28 = m167[4];
              slog::join_probe<2,2>(st_sizeindex145, std::array<u64,2>{v_c27, v_c28}, [&](const std::array<u64,2>& m168) {
                slog::join_probe<2,1>(st_sizeindex146, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m169) {
                  u64 v_c25 = m169[1];
                  slog::join_probe<2,1>(st_size_ansindex147, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m170) {
                    u64 v_c26 = m170[1];
                    u64 v_c31 = _prim__0002b(db, v_c26, v_c30);
                    if (v_c31 == slog_error) { slog::emit_pending_error(db, "set.slog:165"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c31, v_c27});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:165", "delta:st_size_ans", _fires);
  
      if (!_done)
      {
        ReadTask148* _cont = new ReadTask148(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask148(db,b), false);
  // (crule (pre) (scan int_overflow __erre6wIm1523 __errf7g4l1524 __errf3bKi1525 __errf4iji1526) (body) (head (emit error (0) __erre6wIm1523)) <internal>:1 #f)
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
        u64 v_c61 = _t[0];
        u64 v_c62 = _t[1];
        u64 v_c63 = _t[2];
        u64 v_c64 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c61}, std::array<u16,1>{0});
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
  s->addReadRel("$sup9688x164x0x0x0");
  s->addReadRel("$sup9688x61x0x0x0");
  s->addReadRel("$sup9688x62x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("pbranch");
  s->addReadRel("pleaf");
  s->addReadRel("st_mem");
  s->addReadRel("st_mem_ans");
  s->addReadRel("st_size");
  s->addReadRel("st_size_ans");
  s->addReadRel("temp9ItJ1547");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$seq_atr");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("st_mem_ans");
  s->addDynamicRel("st_size_ans");
  s->addDynamicRel("temp9ItJ1547");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("st_mem_ans");
  d->push(s);
  d->continueRun();
}

