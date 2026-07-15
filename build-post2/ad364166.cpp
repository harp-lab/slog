
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const9ac63e4426dab2edcc97bcf7;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("ad364166");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const9ac63e4426dab2edcc97bcf7 = db->encodeString("cnil");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord231({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord231, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord232({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord232, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord233({1, 2, 0});
    
    r->addIndex<3>(ord233, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord234({0, 1, 2});
    
    r->addIndex<3>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp945P926");
  if (r == 0) db->addTempRelation("temp945P926", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8eK6924");
  if (r == 0) db->addTempRelation("temp8eK6924", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4JmH925");
  if (r == 0) db->addTempRelation("temp4JmH925", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2zhK928");
  if (r == 0) db->addTempRelation("temp2zhK928", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp251S927");
  if (r == 0) db->addTempRelation("temp251S927", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("take_ok");
  if (r == 0) db->addRelation("take_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("take_ok");
      std::vector<u16> ord235({0, 1});
    
    r->addIndex<2>(ord235, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("take_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord236({1, 2, 0});
    
    r->addIndex<3>(ord236, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord237({0, 1, 2});
    
    r->addIndex<3>(ord237, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("seed");
  if (r == 0) db->addRelation("seed", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("seed");
      std::vector<u16> ord238({0, 1});
    
    r->addIndex<2>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("seed"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("rev_ok");
  if (r == 0) db->addRelation("rev_ok", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("rev_ok");
      std::vector<u16> ord239({0});
    
    r->addIndex<1>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("rev_ok"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref_ok");
  if (r == 0) db->addRelation("ref_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref_ok");
      std::vector<u16> ord240({0, 1});
    
    r->addIndex<2>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ref_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord241({0});
    
    r->addIndex<1>(ord241, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("probe"), std::array<u16,1>{0}, b));
  r = db->getRelation("ol_tolst_ans");
  if (r == 0) db->addRelation("ol_tolst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst_ans");
      std::vector<u16> ord242({0, 1});
    
    r->addIndex<2>(ord242, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_tolst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_tolst");
  if (r == 0) db->addStruct("ol_tolst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst");
      std::vector<u16> ord243({1, 0});
    
    r->addIndex<2>(ord243, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord244({0, 1});
    
    r->addIndex<2>(ord244, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_tolst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_take_ans");
  if (r == 0) db->addRelation("ol_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take_ans");
      std::vector<u16> ord245({0, 1});
    
    r->addIndex<2>(ord245, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_take");
  if (r == 0) db->addStruct("ol_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take");
      std::vector<u16> ord246({1, 2, 0});
    
    r->addIndex<3>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord247({0, 1, 2});
    
    r->addIndex<3>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_rev_ans");
  if (r == 0) db->addRelation("ol_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_ans");
      std::vector<u16> ord248({0, 1});
    
    r->addIndex<2>(ord248, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc_ans");
  if (r == 0) db->addRelation("ol_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc_ans");
      std::vector<u16> ord249({0, 1});
    
    r->addIndex<2>(ord249, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc");
  if (r == 0) db->addStruct("ol_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc");
      std::vector<u16> ord250({2, 1, 0});
    
    r->addIndex<3>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord251({0, 1, 2});
    
    r->addIndex<3>(ord251, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_rev_acc"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("ol_rev");
  if (r == 0) db->addStruct("ol_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev");
      std::vector<u16> ord252({1, 0});
    
    r->addIndex<2>(ord252, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord253({0, 1});
    
    r->addIndex<2>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_ref_ans");
  if (r == 0) db->addRelation("ol_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref_ans");
      std::vector<u16> ord254({0, 1});
    
    r->addIndex<2>(ord254, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_ref");
  if (r == 0) db->addStruct("ol_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref");
      std::vector<u16> ord255({1, 2, 0});
    
    r->addIndex<3>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord256({0, 1, 2});
    
    r->addIndex<3>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord257({2, 0, 1});
    
    r->addIndex<3>(ord257, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_member_ans");
  if (r == 0) db->addRelation("ol_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member_ans");
      std::vector<u16> ord258({0, 1});
    
    r->addIndex<2>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_member");
  if (r == 0) db->addStruct("ol_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member");
      std::vector<u16> ord259({2, 1, 0});
    
    r->addIndex<3>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord260({0, 2, 1});
    
    r->addIndex<3>(ord260, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_member"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("ol_len_ans");
  if (r == 0) db->addRelation("ol_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len_ans");
      std::vector<u16> ord261({0, 1});
    
    r->addIndex<2>(ord261, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_len");
  if (r == 0) db->addStruct("ol_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len");
      std::vector<u16> ord262({1, 0});
    
    r->addIndex<2>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord263({0, 1});
    
    r->addIndex<2>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_fromlst_ans");
  if (r == 0) db->addRelation("ol_fromlst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord264({0, 1});
    
    r->addIndex<2>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_fromlst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_fromlst");
  if (r == 0) db->addStruct("ol_fromlst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst");
      std::vector<u16> ord265({1, 0});
    
    r->addIndex<2>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord266({0, 1});
    
    r->addIndex<2>(ord266, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_fromlst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_append_ans");
  if (r == 0) db->addRelation("ol_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append_ans");
      std::vector<u16> ord267({0, 1});
    
    r->addIndex<2>(ord267, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_append");
  if (r == 0) db->addStruct("ol_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append");
      std::vector<u16> ord268({1, 2, 0});
    
    r->addIndex<3>(ord268, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord269({0, 1, 2});
    
    r->addIndex<3>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_absent_ans");
  if (r == 0) db->addRelation("ol_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent_ans");
      std::vector<u16> ord270({0, 1});
    
    r->addIndex<2>(ord270, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_absent");
  if (r == 0) db->addStruct("ol_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent");
      std::vector<u16> ord271({1, 2, 0});
    
    r->addIndex<3>(ord271, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord272({0, 2, 1});
    
    r->addIndex<3>(ord272, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord273({2, 0, 1});
    
    r->addIndex<3>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("needle");
  if (r == 0) db->addRelation("needle", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("needle");
      std::vector<u16> ord274({0});
    
    r->addIndex<1>(ord274, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("needle"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord275({1, 2, 3, 0});
    
    r->addIndex<4>(ord275, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord276({0, 1, 2, 3});
    
    r->addIndex<4>(ord276, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord277({1, 2, 0});
    
    r->addIndex<3>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord278({0, 1, 2});
    
    r->addIndex<3>(ord278, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord279({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord279, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord280({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord281({1, 2, 0});
    
    r->addIndex<3>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord282({0, 1, 2});
    
    r->addIndex<3>(ord282, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("member_ok");
  if (r == 0) db->addRelation("member_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("member_ok");
      std::vector<u16> ord283({0, 1});
    
    r->addIndex<2>(ord283, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("member_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord284({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord284, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord285({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord285, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lst_take_ans");
  if (r == 0) db->addRelation("lst_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take_ans");
      std::vector<u16> ord286({0, 1});
    
    r->addIndex<2>(ord286, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_take");
  if (r == 0) db->addStruct("lst_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take");
      std::vector<u16> ord287({1, 2, 0});
    
    r->addIndex<3>(ord287, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord288({0, 1, 2});
    
    r->addIndex<3>(ord288, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev_ans");
  if (r == 0) db->addRelation("lst_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_ans");
      std::vector<u16> ord289({0, 1});
    
    r->addIndex<2>(ord289, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc_ans");
  if (r == 0) db->addRelation("lst_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc_ans");
      std::vector<u16> ord290({0, 1});
    
    r->addIndex<2>(ord290, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc");
  if (r == 0) db->addStruct("lst_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc");
      std::vector<u16> ord291({1, 2, 0});
    
    r->addIndex<3>(ord291, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord292({0, 1, 2});
    
    r->addIndex<3>(ord292, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev");
  if (r == 0) db->addStruct("lst_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev");
      std::vector<u16> ord293({1, 0});
    
    r->addIndex<2>(ord293, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord294({0, 1});
    
    r->addIndex<2>(ord294, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_ref_ans");
  if (r == 0) db->addRelation("lst_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref_ans");
      std::vector<u16> ord295({0, 1});
    
    r->addIndex<2>(ord295, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_ref");
  if (r == 0) db->addStruct("lst_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref");
      std::vector<u16> ord296({1, 2, 0});
    
    r->addIndex<3>(ord296, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord297({0, 1, 2});
    
    r->addIndex<3>(ord297, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_member_ans");
  if (r == 0) db->addRelation("lst_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member_ans");
      std::vector<u16> ord298({0, 1});
    
    r->addIndex<2>(ord298, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_member");
  if (r == 0) db->addStruct("lst_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member");
      std::vector<u16> ord299({1, 2, 0});
    
    r->addIndex<3>(ord299, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord300({0, 1, 2});
    
    r->addIndex<3>(ord300, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_len_ans");
  if (r == 0) db->addRelation("lst_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len_ans");
      std::vector<u16> ord301({0, 1});
    
    r->addIndex<2>(ord301, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_len");
  if (r == 0) db->addStruct("lst_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len");
      std::vector<u16> ord302({1, 0});
    
    r->addIndex<2>(ord302, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord303({0, 1});
    
    r->addIndex<2>(ord303, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_append_ans");
  if (r == 0) db->addRelation("lst_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append_ans");
      std::vector<u16> ord304({0, 1});
    
    r->addIndex<2>(ord304, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_append");
  if (r == 0) db->addStruct("lst_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append");
      std::vector<u16> ord305({1, 2, 0});
    
    r->addIndex<3>(ord305, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord306({0, 1, 2});
    
    r->addIndex<3>(ord306, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_absent_ans");
  if (r == 0) db->addRelation("lst_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent_ans");
      std::vector<u16> ord307({0, 1});
    
    r->addIndex<2>(ord307, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_absent");
  if (r == 0) db->addStruct("lst_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent");
      std::vector<u16> ord308({1, 2, 0});
    
    r->addIndex<3>(ord308, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord309({0, 1, 2});
    
    r->addIndex<3>(ord309, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("len_ok");
  if (r == 0) db->addRelation("len_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("len_ok");
      std::vector<u16> ord310({0, 1});
    
    r->addIndex<2>(ord310, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("len_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord311({1, 2, 3, 0});
    
    r->addIndex<4>(ord311, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord312({0, 1, 2, 3});
    
    r->addIndex<4>(ord312, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord313({0});
    
    r->addIndex<1>(ord313, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord314({1, 2, 0});
    
    r->addIndex<3>(ord314, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord315({0, 1, 2});
    
    r->addIndex<3>(ord315, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ccons");
  if (r == 0) db->addStruct("ccons", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ccons");
      std::vector<u16> ord316({2, 1, 0});
    
    r->addIndex<3>(ord316, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord317({0, 1, 2});
    
    r->addIndex<3>(ord317, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ccons"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("append_ok");
  if (r == 0) db->addRelation("append_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("append_ok");
      std::vector<u16> ord318({0, 1});
    
    r->addIndex<2>(ord318, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("append_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("absent_ok");
  if (r == 0) db->addRelation("absent_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("absent_ok");
      std::vector<u16> ord319({0, 1});
    
    r->addIndex<2>(ord319, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("absent_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord320({1, 0});
    
    r->addIndex<2>(ord320, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord321({0, 1});
    
    r->addIndex<2>(ord321, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord322({1, 0});
    
    r->addIndex<2>(ord322, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup76318x53x0x0x0");
  if (r == 0) db->addRelation("$sup76318x53x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x53x0x0x0");
      std::vector<u16> ord323({0, 1, 2});
    
    r->addIndex<3>(ord323, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x53x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x43x0x0x0");
  if (r == 0) db->addRelation("$sup76318x43x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x43x0x0x0");
      std::vector<u16> ord324({0, 1, 2});
    
    r->addIndex<3>(ord324, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x43x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x38x0x0x0");
  if (r == 0) db->addRelation("$sup76318x38x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x38x0x0x0");
      std::vector<u16> ord325({0, 1, 2});
    
    r->addIndex<3>(ord325, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x38x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x33x0x0x0");
  if (r == 0) db->addRelation("$sup76318x33x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x33x0x0x0");
      std::vector<u16> ord326({0, 1, 2});
    
    r->addIndex<3>(ord326, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x33x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x27x0x0x0");
  if (r == 0) db->addRelation("$sup76318x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x27x0x0x0");
      std::vector<u16> ord327({0, 1, 2, 3});
    
    r->addIndex<4>(ord327, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup76318x27x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x48x0x0x0");
  if (r == 0) db->addRelation("$sup59985x48x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x48x0x0x0");
      std::vector<u16> ord328({2, 3, 0, 1});
    
    r->addIndex<4>(ord328, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x48x0x0x0"), std::array<u16,4>{2, 3, 0, 1}, b));
  r = db->getRelation("$sup59985x43x0x0x0");
  if (r == 0) db->addRelation("$sup59985x43x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x43x0x0x0");
      std::vector<u16> ord329({0, 1, 2, 3});
    
    r->addIndex<4>(ord329, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x43x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x37x0x0x0");
  if (r == 0) db->addRelation("$sup59985x37x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x37x0x0x0");
      std::vector<u16> ord330({2, 0, 1});
    
    r->addIndex<3>(ord330, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x37x0x0x0"), std::array<u16,3>{2, 0, 1}, b));
  r = db->getRelation("$sup59985x32x0x0x0");
  if (r == 0) db->addRelation("$sup59985x32x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x32x0x0x0");
      std::vector<u16> ord331({2, 3, 0, 1});
    
    r->addIndex<4>(ord331, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x32x0x0x0"), std::array<u16,4>{2, 3, 0, 1}, b));
  r = db->getRelation("$sup59985x27x0x0x0");
  if (r == 0) db->addRelation("$sup59985x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x27x0x0x0");
      std::vector<u16> ord332({3, 2, 0, 1});
    
    r->addIndex<4>(ord332, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 2, 0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x27x0x0x0"), std::array<u16,4>{3, 2, 0, 1}, b));
  r = db->getRelation("$sup59985x22x0x0x0");
  if (r == 0) db->addRelation("$sup59985x22x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x22x0x0x0");
      std::vector<u16> ord333({0, 1, 2, 3});
    
    r->addIndex<4>(ord333, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x22x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x17x0x0x0");
  if (r == 0) db->addRelation("$sup59985x17x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x17x0x0x0");
      std::vector<u16> ord334({2, 0, 1});
    
    r->addIndex<3>(ord334, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x17x0x0x0"), std::array<u16,3>{2, 0, 1}, b));
  r = db->getRelation("$sup59985x12x0x0x0");
  if (r == 0) db->addRelation("$sup59985x12x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x12x0x0x0");
      std::vector<u16> ord335({0, 1, 2, 3});
    
    r->addIndex<4>(ord335, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x12x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord336({0, 1, 2});
    
    r->addIndex<3>(ord336, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
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
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("ol_fromlst"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("ol_tolst_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("seed"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan temp945P926 __t00TJ12 __t6rHr9 z) (body (let __t6JUH10 (lcat __t6rHr9 z))) (head (emit-temp temp251S927 __t00TJ12 __t6JUH10)) list-cons.slog:18 #f)
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
      head_rel[0] = db->getRelation("temp251S927");
      outer_rel = db->getRelation("temp945P926");
  
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
        u64 v_c3 = _prim_lcat(db, v_c1, v_c2);
        if (v_c3 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:18"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c0, v_c3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:18", "delta:temp945P926", _fires);
  
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
  // (crule (pre) (scan temp8eK6924 __t0AOz65 __t2ue563) (body) (head (emit ol_len_ans (0 1) __t0AOz65 __t2ue563)) list-cons.slog:38 #f)
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
      head_rel[0] = db->getRelation("ol_len_ans");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("ol_len_ans");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("temp8eK6924");
  
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
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c5}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:38", "delta:temp8eK6924", _fires);
  
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
  // (crule (pre (let __tconst34RW394 const9ac63e4426dab2edcc97bcf7)) (probe _enum (1 0) 1 __tconst34RW394 __t4kHq252) (body (join ol_rev_acc (2 1 0) 1 __t4kHq252 l __t8JOa253) (exists ol_rev (1 0) 1 l) (join ol_rev_acc_ans (0 1) 1 __t8JOa253 __v0) (join ol_rev (1 0) 1 l __t2PIe251)) (head (emit ol_rev_ans (0 1) __t2PIe251 __v0)) list-cons.slog:56 #f)
  class ReadTask8 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ol_rev_accindex4;  slog::Index** ol_revindex5;  slog::Index** ol_rev_acc_ansindex6;  slog::Index** ol_revindex7;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_rev_ans");
      std::vector<u16> ord9({0, 1});
      slog::Relation* readrel10 = db->getRelation("ol_rev_ans");
      head_index[0] = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({1, 0});
      slog::Relation* readrel12 = db->getRelation("_enum");
      driver_index = readrel12->getIndex(ord11, true);
      std::vector<u16> ord13({2, 1, 0});
      slog::Relation* readrel14 = db->getRelation("ol_rev_acc");
      ol_rev_accindex4 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({1, 0});
      slog::Relation* readrel16 = db->getRelation("ol_rev");
      ol_revindex5 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({0, 1});
      slog::Relation* readrel18 = db->getRelation("ol_rev_acc_ans");
      ol_rev_acc_ansindex6 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("ol_rev");
      ol_revindex7 = readrel20->getIndex(ord19, false);
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c6, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m21) {
        u64 v_c7 = m21[1];
        if (buckethash(v_c7) != bucket) return;
        slog::join_probe<3,1>(ol_rev_accindex4, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m22) {
          u64 v_c8 = m22[1]; u64 v_c9 = m22[2];
          if (!slog::exists_probe<2,1>(ol_revindex5, std::array<u64,2>{v_c8, 0})) return;
          slog::join_probe<2,1>(ol_rev_acc_ansindex6, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m23) {
            u64 v_c10 = m23[1];
            slog::join_probe<2,1>(ol_revindex7, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m24) {
              u64 v_c11 = m24[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c11, v_c10}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:56", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask8* _cont = new ReadTask8(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask8(db,b), true);
  // (crule (pre) (scan ol_member_ans __t9sqL58 r) (body (join ol_member (0 2 1) 1 __t9sqL58 y xs) (exists ccons (2 1 0) 1 xs) (exists ol_member (2 1 0) 1 y) (join $sup59985x32x0x0x0 (2 3 0 1) 2 xs y __t7R6l57 x) (neq x y) (exists ol_member (0 2 1) 2 __t7R6l57 y) (join ccons (2 1 0) 2 xs x __t1AJ256) (join ol_member (0 2 1) 3 __t7R6l57 y __t1AJ256)) (head (emit ol_member_ans (0 1) __t7R6l57 r)) list-cons.slog:33 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_memberindex25;  slog::Index** cconsindex26;  slog::Index** ol_memberindex27;  slog::Index** $sup59985x32x0x0x0index28;  slog::Index** ol_memberindex29;  slog::Index** cconsindex30;  slog::Index** ol_memberindex31;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_member_ans");
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("ol_member_ans");
      head_index[0] = readrel34->getIndex(ord33, false);
      outer_rel = db->getRelation("ol_member_ans");
      std::vector<u16> ord35({0, 2, 1});
      slog::Relation* readrel36 = db->getRelation("ol_member");
      ol_memberindex25 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({2, 1, 0});
      slog::Relation* readrel38 = db->getRelation("ccons");
      cconsindex26 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({2, 1, 0});
      slog::Relation* readrel40 = db->getRelation("ol_member");
      ol_memberindex27 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({2, 3, 0, 1});
      slog::Relation* readrel42 = db->getRelation("$sup59985x32x0x0x0");
      $sup59985x32x0x0x0index28 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 2, 1});
      slog::Relation* readrel44 = db->getRelation("ol_member");
      ol_memberindex29 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({2, 1, 0});
      slog::Relation* readrel46 = db->getRelation("ccons");
      cconsindex30 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({0, 2, 1});
      slog::Relation* readrel48 = db->getRelation("ol_member");
      ol_memberindex31 = readrel48->getIndex(ord47, false);
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<3,1>(ol_memberindex25, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m49) {
          u64 v_c14 = m49[1]; u64 v_c15 = m49[2];
          if (!slog::exists_probe<3,1>(cconsindex26, std::array<u64,3>{v_c15, 0, 0})) return;
          if (!slog::exists_probe<3,1>(ol_memberindex27, std::array<u64,3>{v_c14, 0, 0})) return;
          slog::join_probe<4,2>($sup59985x32x0x0x0index28, std::array<u64,4>{v_c15, v_c14, 0, 0}, [&](const std::array<u64,4>& m50) {
            u64 v_c16 = m50[2]; u64 v_c17 = m50[3];
            if (v_c17 == v_c14) return;
            if (!slog::exists_probe<3,2>(ol_memberindex29, std::array<u64,3>{v_c16, v_c14, 0})) return;
            slog::join_probe<3,2>(cconsindex30, std::array<u64,3>{v_c15, v_c17, 0}, [&](const std::array<u64,3>& m51) {
              u64 v_c18 = m51[2];
              slog::join_probe<3,3>(ol_memberindex31, std::array<u64,3>{v_c16, v_c14, v_c18}, [&](const std::array<u64,3>& m52) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c13}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:33", "delta:ol_member_ans", _fires);
  
      if (!_done)
      {
        ReadTask32* _cont = new ReadTask32(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask32(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre7psa921 __errf9oVR922 __errf4LUH923) (body) (head (emit error (0) __erre7psa921)) <internal>:1 #f)
  class ReadTask53 : public slog::Task
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
      std::vector<u16> ord54({0});
      slog::Relation* readrel55 = db->getRelation("error");
      head_index[0] = readrel55->getIndex(ord54, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask53(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c21 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask53* _cont = new ReadTask53(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask53(db,b), false);
  // (crule (pre (let __t8Ml28 (lempty))) (scan ol_tolst_ans __t3Ft013 z) (body (join ol_tolst (0 1) 1 __t3Ft013 xs) (exists ccons (2 1 0) 1 xs) (join $sup59985x17x0x0x0 (2 0 1) 1 xs __t00TJ12 x) (join ccons (2 1 0) 2 xs x __t48B011) (join ol_tolst (0 1) 2 __t00TJ12 __t48B011)) (head (emit-temp temp4JmH925 __t00TJ12 __t8Ml28 x z)) list-cons.slog:18 #f)
  class ReadTask61 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_tolstindex56;  slog::Index** cconsindex57;  slog::Index** $sup59985x17x0x0x0index58;  slog::Index** cconsindex59;  slog::Index** ol_tolstindex60;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4JmH925");
      outer_rel = db->getRelation("ol_tolst_ans");
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("ol_tolst");
      ol_tolstindex56 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({2, 1, 0});
      slog::Relation* readrel65 = db->getRelation("ccons");
      cconsindex57 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({2, 0, 1});
      slog::Relation* readrel67 = db->getRelation("$sup59985x17x0x0x0");
      $sup59985x17x0x0x0index58 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({2, 1, 0});
      slog::Relation* readrel69 = db->getRelation("ccons");
      cconsindex59 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({0, 1});
      slog::Relation* readrel71 = db->getRelation("ol_tolst");
      ol_tolstindex60 = readrel71->getIndex(ord70, false);
  
    }
    ReadTask61(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = _prim_lempty(db);
      if (v_c22 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:18"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c23 = _t[0];
        u64 v_c2 = _t[1];
        slog::join_probe<2,1>(ol_tolstindex56, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m72) {
          u64 v_c15 = m72[1];
          if (!slog::exists_probe<3,1>(cconsindex57, std::array<u64,3>{v_c15, 0, 0})) return;
          slog::join_probe<3,1>($sup59985x17x0x0x0index58, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m73) {
            u64 v_c0 = m73[1]; u64 v_c17 = m73[2];
            slog::join_probe<3,2>(cconsindex59, std::array<u64,3>{v_c15, v_c17, 0}, [&](const std::array<u64,3>& m74) {
              u64 v_c24 = m74[2];
              slog::join_probe<2,2>(ol_tolstindex60, std::array<u64,2>{v_c0, v_c24}, [&](const std::array<u64,2>& m75) {
                ++_fires;
                slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c22, v_c17, v_c2});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:18", "delta:ol_tolst_ans", _fires);
  
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
  // (crule (pre (let __tconst5DVC119 const6b86b273ff34fce19d6b804e)) (scan ccons __t3SEs120 x xs) (body (join ol_member (2 1 0) 2 x __t3SEs120 __t4DRI121)) (head (emit ol_member_ans (0 1) __t4DRI121 __tconst5DVC119)) list-cons.slog:32 #f)
  class ReadTask77 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_memberindex76;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_member_ans");
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("ol_member_ans");
      head_index[0] = readrel79->getIndex(ord78, false);
      outer_rel = db->getRelation("ccons");
      std::vector<u16> ord80({2, 1, 0});
      slog::Relation* readrel81 = db->getRelation("ol_member");
      ol_memberindex76 = readrel81->getIndex(ord80, false);
  
    }
    ReadTask77(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c26 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c15 = _t[2];
        slog::join_probe<3,2>(ol_memberindex76, std::array<u64,3>{v_c17, v_c26, 0}, [&](const std::array<u64,3>& m82) {
          u64 v_c27 = m82[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c27, v_c25}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:32", "all:ccons", _fires);
  
      if (!_done)
      {
        ReadTask77* _cont = new ReadTask77(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask77(db,b), true);
  // (crule (pre) (scan int_overflow __erre97g8900 __errf8JOK901 __errf3xgE902 __errf96W5903) (body) (head (emit error (0) __erre97g8900)) <internal>:1 #f)
  class ReadTask83 : public slog::Task
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
      std::vector<u16> ord84({0});
      slog::Relation* readrel85 = db->getRelation("error");
      head_index[0] = readrel85->getIndex(ord84, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask83(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c30 = _t[2];
        u64 v_c31 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c28}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask83* _cont = new ReadTask83(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask83(db,b), false);
  // (crule (pre (let __tconst04yM268 const5feceb66ffc86f38d952786c) (let __tconst67kj269 const6b86b273ff34fce19d6b804e)) (scan ol_ref_ans __t8fjH271 r) (body (join ol_ref (0 1 2) 1 __t8fjH271 xs __t9GxQ270) (exists $sup59985x27x0x0x0 (3 2 0 1) 1 xs) (join ccons (2 1 0) 1 xs x __t8U2m266) (exists ol_ref (1 2 0) 1 __t8U2m266) (join $sup59985x27x0x0x0 (3 2 0 1) 2 xs x __t2UQ6267 n) (cmp lt __tconst04yM268 n) (join ol_ref (1 2 0) 3 __t8U2m266 n __t2UQ6267) (let chk5Jbb929 (_0002d n __tconst67kj269)) (eq __t9GxQ270 chk5Jbb929)) (head (emit ol_ref_ans (0 1) __t2UQ6267 r)) list-cons.slog:28 #f)
  class ReadTask92 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_refindex86;  slog::Index** $sup59985x27x0x0x0index87;  slog::Index** cconsindex88;  slog::Index** ol_refindex89;  slog::Index** $sup59985x27x0x0x0index90;  slog::Index** ol_refindex91;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_ref_ans");
      std::vector<u16> ord93({0, 1});
      slog::Relation* readrel94 = db->getRelation("ol_ref_ans");
      head_index[0] = readrel94->getIndex(ord93, false);
      outer_rel = db->getRelation("ol_ref_ans");
      std::vector<u16> ord95({0, 1, 2});
      slog::Relation* readrel96 = db->getRelation("ol_ref");
      ol_refindex86 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({3, 2, 0, 1});
      slog::Relation* readrel98 = db->getRelation("$sup59985x27x0x0x0");
      $sup59985x27x0x0x0index87 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({2, 1, 0});
      slog::Relation* readrel100 = db->getRelation("ccons");
      cconsindex88 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 2, 0});
      slog::Relation* readrel102 = db->getRelation("ol_ref");
      ol_refindex89 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({3, 2, 0, 1});
      slog::Relation* readrel104 = db->getRelation("$sup59985x27x0x0x0");
      $sup59985x27x0x0x0index90 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 2, 0});
      slog::Relation* readrel106 = db->getRelation("ol_ref");
      ol_refindex91 = readrel106->getIndex(ord105, false);
  
    }
    ReadTask92(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c32 = v_const5feceb66ffc86f38d952786c;
      u64 v_c33 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c34 = _t[0];
        u64 v_c13 = _t[1];
        slog::join_probe<3,1>(ol_refindex86, std::array<u64,3>{v_c34, 0, 0}, [&](const std::array<u64,3>& m107) {
          u64 v_c15 = m107[1]; u64 v_c35 = m107[2];
          if (!slog::exists_probe<4,1>($sup59985x27x0x0x0index87, std::array<u64,4>{v_c15, 0, 0, 0})) return;
          slog::join_probe<3,1>(cconsindex88, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m108) {
            u64 v_c17 = m108[1]; u64 v_c36 = m108[2];
            if (!slog::exists_probe<3,1>(ol_refindex89, std::array<u64,3>{v_c36, 0, 0})) return;
            slog::join_probe<4,2>($sup59985x27x0x0x0index90, std::array<u64,4>{v_c15, v_c17, 0, 0}, [&](const std::array<u64,4>& m109) {
              u64 v_c37 = m109[2]; u64 v_c38 = m109[3];
              u64 v_c39 = _prim_lt(db, v_c32, v_c38);
              if (v_c39 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:28"); return; }
              if (!v_c39) return;
              slog::join_probe<3,3>(ol_refindex91, std::array<u64,3>{v_c36, v_c38, v_c37}, [&](const std::array<u64,3>& m111) {
                u64 v_c40 = _prim__0002d(db, v_c38, v_c33);
                if (v_c40 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:28"); return; }
                if (v_c35 != v_c40) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c37, v_c13}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:28", "delta:ol_ref_ans", _fires);
  
      if (!_done)
      {
        ReadTask92* _cont = new ReadTask92(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask92(db,b), false);
  // (crule (pre) (scan temp251S927 __t00TJ12 __t6JUH10) (body) (head (emit ol_tolst_ans (0 1) __t00TJ12 __t6JUH10)) list-cons.slog:18 #f)
  class ReadTask112 : public slog::Task
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
      head_rel[0] = db->getRelation("ol_tolst_ans");
      std::vector<u16> ord113({0, 1});
      slog::Relation* readrel114 = db->getRelation("ol_tolst_ans");
      head_index[0] = readrel114->getIndex(ord113, false);
      outer_rel = db->getRelation("temp251S927");
  
    }
    ReadTask112(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c3}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:18", "delta:temp251S927", _fires);
  
      if (!_done)
      {
        ReadTask112* _cont = new ReadTask112(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask112(db,b), false);
  // (crule (pre (let __tconst1AgU17 const5feceb66ffc86f38d952786c)) (probe ol_ref (2 0 1) 1 __tconst1AgU17 __t4WtZ19 __t9XIY18) (body (join ccons (0 1 2) 1 __t9XIY18 x xs)) (head (emit ol_ref_ans (0 1) __t4WtZ19 x)) list-cons.slog:27 #f)
  class ReadTask116 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** cconsindex115;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_ref_ans");
      std::vector<u16> ord117({0, 1});
      slog::Relation* readrel118 = db->getRelation("ol_ref_ans");
      head_index[0] = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({2, 0, 1});
      slog::Relation* readrel120 = db->getRelation("ol_ref");
      driver_index = readrel120->getIndex(ord119, true);
      std::vector<u16> ord121({0, 1, 2});
      slog::Relation* readrel122 = db->getRelation("ccons");
      cconsindex115 = readrel122->getIndex(ord121, false);
  
    }
    ReadTask116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c41, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m123) {
        u64 v_c42 = m123[1];
        u64 v_c43 = m123[2];
        if (buckethash(v_c42) != bucket) return;
        slog::join_probe<3,1>(cconsindex115, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m124) {
          u64 v_c17 = m124[1]; u64 v_c15 = m124[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c42, v_c17}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:27", "all:ol_ref", _fires);
  
      if (!_done)
      {
        ReadTask116* _cont = new ReadTask116(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask116(db,b), true);
  // (crule (pre (let __tconst6sVr369 const9ac63e4426dab2edcc97bcf7)) (scan temp2zhK928 __t4BUI231) (body (join _enum (1 0) 1 __tconst6sVr369 __t6vVh232) (join ol_tolst (1 0) 1 __t6vVh232 __t7L5l233)) (head (emit ol_tolst_ans (0 1) __t7L5l233 __t4BUI231)) list-cons.slog:17 #f)
  class ReadTask127 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex125;  slog::Index** ol_tolstindex126;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_tolst_ans");
      std::vector<u16> ord128({0, 1});
      slog::Relation* readrel129 = db->getRelation("ol_tolst_ans");
      head_index[0] = readrel129->getIndex(ord128, false);
      outer_rel = db->getRelation("temp2zhK928");
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("_enum");
      _enumindex125 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("ol_tolst");
      ol_tolstindex126 = readrel133->getIndex(ord132, false);
  
    }
    ReadTask127(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c45 = _t[0];
        slog::join_probe<2,1>(_enumindex125, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m134) {
          u64 v_c46 = m134[1];
          slog::join_probe<2,1>(ol_tolstindex126, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m135) {
            u64 v_c47 = m135[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c47, v_c45}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:17", "delta:temp2zhK928", _fires);
  
      if (!_done)
      {
        ReadTask127* _cont = new ReadTask127(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask127(db,b), false);
  // (crule (pre) (scan ol_absent_ans __t1uAs31 r) (body (join ol_absent (0 2 1) 1 __t1uAs31 y xs) (exists ccons (2 1 0) 1 xs) (exists ol_absent (2 0 1) 1 y) (join $sup59985x48x0x0x0 (2 3 0 1) 2 xs y __t4Ax830 x) (neq x y) (exists ol_absent (0 2 1) 2 __t4Ax830 y) (join ccons (2 1 0) 2 xs x __t9u0Z29) (join ol_absent (0 2 1) 3 __t4Ax830 y __t9u0Z29)) (head (emit ol_absent_ans (0 1) __t4Ax830 r)) list-cons.slog:49 #f)
  class ReadTask143 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_absentindex136;  slog::Index** cconsindex137;  slog::Index** ol_absentindex138;  slog::Index** $sup59985x48x0x0x0index139;  slog::Index** ol_absentindex140;  slog::Index** cconsindex141;  slog::Index** ol_absentindex142;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_absent_ans");
      std::vector<u16> ord144({0, 1});
      slog::Relation* readrel145 = db->getRelation("ol_absent_ans");
      head_index[0] = readrel145->getIndex(ord144, false);
      outer_rel = db->getRelation("ol_absent_ans");
      std::vector<u16> ord146({0, 2, 1});
      slog::Relation* readrel147 = db->getRelation("ol_absent");
      ol_absentindex136 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({2, 1, 0});
      slog::Relation* readrel149 = db->getRelation("ccons");
      cconsindex137 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({2, 0, 1});
      slog::Relation* readrel151 = db->getRelation("ol_absent");
      ol_absentindex138 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({2, 3, 0, 1});
      slog::Relation* readrel153 = db->getRelation("$sup59985x48x0x0x0");
      $sup59985x48x0x0x0index139 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({0, 2, 1});
      slog::Relation* readrel155 = db->getRelation("ol_absent");
      ol_absentindex140 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({2, 1, 0});
      slog::Relation* readrel157 = db->getRelation("ccons");
      cconsindex141 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0, 2, 1});
      slog::Relation* readrel159 = db->getRelation("ol_absent");
      ol_absentindex142 = readrel159->getIndex(ord158, false);
  
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
        u64 v_c48 = _t[0];
        u64 v_c13 = _t[1];
        slog::join_probe<3,1>(ol_absentindex136, std::array<u64,3>{v_c48, 0, 0}, [&](const std::array<u64,3>& m160) {
          u64 v_c14 = m160[1]; u64 v_c15 = m160[2];
          if (!slog::exists_probe<3,1>(cconsindex137, std::array<u64,3>{v_c15, 0, 0})) return;
          if (!slog::exists_probe<3,1>(ol_absentindex138, std::array<u64,3>{v_c14, 0, 0})) return;
          slog::join_probe<4,2>($sup59985x48x0x0x0index139, std::array<u64,4>{v_c15, v_c14, 0, 0}, [&](const std::array<u64,4>& m161) {
            u64 v_c49 = m161[2]; u64 v_c17 = m161[3];
            if (v_c17 == v_c14) return;
            if (!slog::exists_probe<3,2>(ol_absentindex140, std::array<u64,3>{v_c49, v_c14, 0})) return;
            slog::join_probe<3,2>(cconsindex141, std::array<u64,3>{v_c15, v_c17, 0}, [&](const std::array<u64,3>& m162) {
              u64 v_c50 = m162[2];
              slog::join_probe<3,3>(ol_absentindex142, std::array<u64,3>{v_c49, v_c14, v_c50}, [&](const std::array<u64,3>& m163) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c13}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:49", "delta:ol_absent_ans", _fires);
  
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
  // (crule (pre) (scan toint_range __erre4CJn908 __errf5uWy909 __errf1jxZ910) (body) (head (emit error (0) __erre4CJn908)) <internal>:1 #f)
  class ReadTask164 : public slog::Task
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
      std::vector<u16> ord165({0});
      slog::Relation* readrel166 = db->getRelation("error");
      head_index[0] = readrel166->getIndex(ord165, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask164(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c51 = _t[0];
        u64 v_c52 = _t[1];
        u64 v_c53 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c51}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask164* _cont = new ReadTask164(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask164(db,b), false);
  // (crule (pre) (scan div_by_zero __erre0bVJ894 __errf1Jgk895 __errf4Oou896) (body) (head (emit error (0) __erre0bVJ894)) <internal>:1 #f)
  class ReadTask167 : public slog::Task
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
      std::vector<u16> ord168({0});
      slog::Relation* readrel169 = db->getRelation("error");
      head_index[0] = readrel169->getIndex(ord168, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask167(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask167* _cont = new ReadTask167(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask167(db,b), false);
  // (crule (pre) (scan temp4JmH925 __t00TJ12 __t8Ml28 x z) (body (let __t6rHr9 (lpush __t8Ml28 x))) (head (emit-temp temp945P926 __t00TJ12 __t6rHr9 z)) list-cons.slog:18 #f)
  class ReadTask170 : public slog::Task
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
      head_rel[0] = db->getRelation("temp945P926");
      outer_rel = db->getRelation("temp4JmH925");
  
    }
    ReadTask170(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c1 = _prim_lpush(db, v_c22, v_c17);
        if (v_c1 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:18"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c0, v_c1, v_c2});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:18", "delta:temp4JmH925", _fires);
  
      if (!_done)
      {
        ReadTask170* _cont = new ReadTask170(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask170(db,b), false);
  // (crule (pre) (scan type_mismatch __erre4A1x911 __errf6Ehv912 __errf3Ulq913 __errf5Oid914 __errf4Pe9915) (body) (head (emit error (0) __erre4A1x911)) <internal>:1 #f)
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
      outer_rel = db->getRelation("type_mismatch");
  
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
        u64 v_c57 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c60 = _t[3];
        u64 v_c61 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
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
  // (crule (pre) (scan nan_result __erre7qYO904 __errf7jDc905 __errf7uf5906 __errf1pXV907) (body) (head (emit error (0) __erre7qYO904)) <internal>:1 #f)
  class ReadTask174 : public slog::Task
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
      std::vector<u16> ord175({0});
      slog::Relation* readrel176 = db->getRelation("error");
      head_index[0] = readrel176->getIndex(ord175, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask174(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c62 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        u64 v_c65 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c62}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask174* _cont = new ReadTask174(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask174(db,b), false);
  // (crule (pre (let __tconst5abK386 const9ac63e4426dab2edcc97bcf7) (let __tconst7rp4254 const5feceb66ffc86f38d952786c)) (probe _enum (1 0) 1 __tconst5abK386 __t2JBS255) (body (join ol_len (1 0) 1 __t2JBS255 __t7sLf256)) (head (emit ol_len_ans (0 1) __t7sLf256 __tconst7rp4254)) list-cons.slog:37 #f)
  class ReadTask178 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ol_lenindex177;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_len_ans");
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("ol_len_ans");
      head_index[0] = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 0});
      slog::Relation* readrel182 = db->getRelation("_enum");
      driver_index = readrel182->getIndex(ord181, true);
      std::vector<u16> ord183({1, 0});
      slog::Relation* readrel184 = db->getRelation("ol_len");
      ol_lenindex177 = readrel184->getIndex(ord183, false);
  
    }
    ReadTask178(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_const9ac63e4426dab2edcc97bcf7;
      u64 v_c67 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c66, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m185) {
        u64 v_c68 = m185[1];
        if (buckethash(v_c68) != bucket) return;
        slog::join_probe<2,1>(ol_lenindex177, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m186) {
          u64 v_c69 = m186[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c69, v_c67}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:37", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask178* _cont = new ReadTask178(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask178(db,b), true);
  // (crule (pre (let __tconst97RB62 const6b86b273ff34fce19d6b804e)) (scan ol_len_ans __t62fF66 __v0) (body (join ol_len (0 1) 1 __t62fF66 xs) (exists ccons (2 1 0) 1 xs) (join $sup59985x37x0x0x0 (2 0 1) 1 xs __t0AOz65 x) (join ccons (2 1 0) 2 xs x __t9GMK64) (join ol_len (0 1) 2 __t0AOz65 __t9GMK64) (let __t2ue563 (_0002b __v0 __tconst97RB62))) (head (emit-temp temp8eK6924 __t0AOz65 __t2ue563)) list-cons.slog:38 #f)
  class ReadTask192 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_lenindex187;  slog::Index** cconsindex188;  slog::Index** $sup59985x37x0x0x0index189;  slog::Index** cconsindex190;  slog::Index** ol_lenindex191;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8eK6924");
      outer_rel = db->getRelation("ol_len_ans");
      std::vector<u16> ord193({0, 1});
      slog::Relation* readrel194 = db->getRelation("ol_len");
      ol_lenindex187 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({2, 1, 0});
      slog::Relation* readrel196 = db->getRelation("ccons");
      cconsindex188 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({2, 0, 1});
      slog::Relation* readrel198 = db->getRelation("$sup59985x37x0x0x0");
      $sup59985x37x0x0x0index189 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({2, 1, 0});
      slog::Relation* readrel200 = db->getRelation("ccons");
      cconsindex190 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({0, 1});
      slog::Relation* readrel202 = db->getRelation("ol_len");
      ol_lenindex191 = readrel202->getIndex(ord201, false);
  
    }
    ReadTask192(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c71 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe<2,1>(ol_lenindex187, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m203) {
          u64 v_c15 = m203[1];
          if (!slog::exists_probe<3,1>(cconsindex188, std::array<u64,3>{v_c15, 0, 0})) return;
          slog::join_probe<3,1>($sup59985x37x0x0x0index189, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m204) {
            u64 v_c4 = m204[1]; u64 v_c17 = m204[2];
            slog::join_probe<3,2>(cconsindex190, std::array<u64,3>{v_c15, v_c17, 0}, [&](const std::array<u64,3>& m205) {
              u64 v_c72 = m205[2];
              slog::join_probe<2,2>(ol_lenindex191, std::array<u64,2>{v_c4, v_c72}, [&](const std::array<u64,2>& m206) {
                u64 v_c5 = _prim__0002b(db, v_c10, v_c70);
                if (v_c5 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:38"); return; }
                ++_fires;
                slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c5});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:38", "delta:ol_len_ans", _fires);
  
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
  // (crule (pre (let __tconst6Gj8401 const9ac63e4426dab2edcc97bcf7) (let __tconst9PCv234 const6b86b273ff34fce19d6b804e)) (probe _enum (1 0) 1 __tconst6Gj8401 __t4N1v235) (body (join ol_absent (1 2 0) 1 __t4N1v235 y __t9MqC236)) (head (emit ol_absent_ans (0 1) __t9MqC236 __tconst9PCv234)) list-cons.slog:48 #f)
  class ReadTask208 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ol_absentindex207;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_absent_ans");
      std::vector<u16> ord209({0, 1});
      slog::Relation* readrel210 = db->getRelation("ol_absent_ans");
      head_index[0] = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 0});
      slog::Relation* readrel212 = db->getRelation("_enum");
      driver_index = readrel212->getIndex(ord211, true);
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("ol_absent");
      ol_absentindex207 = readrel214->getIndex(ord213, false);
  
    }
    ReadTask208(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_const9ac63e4426dab2edcc97bcf7;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c73, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m215) {
        u64 v_c75 = m215[1];
        if (buckethash(v_c75) != bucket) return;
        slog::join_probe<3,1>(ol_absentindex207, std::array<u64,3>{v_c75, 0, 0}, [&](const std::array<u64,3>& m216) {
          u64 v_c14 = m216[1]; u64 v_c76 = m216[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c76, v_c74}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:48", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask208* _cont = new ReadTask208(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask208(db,b), true);
  // (crule (pre) (scan mpz_overflow __erre8fmr916 __errf1ewM917 __errf85Db918 __errf9sxm919 __errf6f9C920) (body) (head (emit error (0) __erre8fmr916)) <internal>:1 #f)
  class ReadTask217 : public slog::Task
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
      std::vector<u16> ord218({0});
      slog::Relation* readrel219 = db->getRelation("error");
      head_index[0] = readrel219->getIndex(ord218, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask217(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c77 = _t[0];
        u64 v_c78 = _t[1];
        u64 v_c79 = _t[2];
        u64 v_c80 = _t[3];
        u64 v_c81 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c77}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask217* _cont = new ReadTask217(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask217(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre3eqQ897 __errf0qYw898 __errf9Dts899) (body) (head (emit error (0) __erre3eqQ897)) <internal>:1 #f)
  class ReadTask220 : public slog::Task
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
      std::vector<u16> ord221({0});
      slog::Relation* readrel222 = db->getRelation("error");
      head_index[0] = readrel222->getIndex(ord221, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask220(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c82 = _t[0];
        u64 v_c83 = _t[1];
        u64 v_c84 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c82}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask220* _cont = new ReadTask220(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask220(db,b), false);
  // (crule (pre (let __tconst6sVr369 const9ac63e4426dab2edcc97bcf7) (let __t4BUI231 (lempty))) (probe _enum (1 0) 1 __tconst6sVr369 __t6vVh232) (body (join ol_tolst (1 0) 1 __t6vVh232 __t7L5l233)) (head (emit-temp temp2zhK928 __t4BUI231)) list-cons.slog:17 #f)
  class ReadTask224 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ol_tolstindex223;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2zhK928");
      std::vector<u16> ord225({1, 0});
      slog::Relation* readrel226 = db->getRelation("_enum");
      driver_index = readrel226->getIndex(ord225, true);
      std::vector<u16> ord227({1, 0});
      slog::Relation* readrel228 = db->getRelation("ol_tolst");
      ol_tolstindex223 = readrel228->getIndex(ord227, false);
  
    }
    ReadTask224(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_const9ac63e4426dab2edcc97bcf7;
      u64 v_c45 = _prim_lempty(db);
      if (v_c45 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:17"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c44, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m229) {
        u64 v_c46 = m229[1];
        if (buckethash(v_c46) != bucket) return;
        slog::join_probe<2,1>(ol_tolstindex223, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m230) {
          u64 v_c47 = m230[1];
          ++_fires;
          slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c45});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:17", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask224* _cont = new ReadTask224(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask224(db,b), true);
  s->addReadRel("$sup59985x17x0x0x0");
  s->addReadRel("$sup59985x27x0x0x0");
  s->addReadRel("$sup59985x32x0x0x0");
  s->addReadRel("$sup59985x37x0x0x0");
  s->addReadRel("$sup59985x48x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("ccons");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("ol_absent");
  s->addReadRel("ol_absent_ans");
  s->addReadRel("ol_len");
  s->addReadRel("ol_len_ans");
  s->addReadRel("ol_member");
  s->addReadRel("ol_member_ans");
  s->addReadRel("ol_ref");
  s->addReadRel("ol_ref_ans");
  s->addReadRel("ol_rev");
  s->addReadRel("ol_rev_acc");
  s->addReadRel("ol_rev_acc_ans");
  s->addReadRel("ol_tolst");
  s->addReadRel("ol_tolst_ans");
  s->addReadRel("temp251S927");
  s->addReadRel("temp2zhK928");
  s->addReadRel("temp4JmH925");
  s->addReadRel("temp8eK6924");
  s->addReadRel("temp945P926");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("ol_absent_ans");
  s->addDynamicRel("ol_len_ans");
  s->addDynamicRel("ol_member_ans");
  s->addDynamicRel("ol_ref_ans");
  s->addDynamicRel("ol_rev_ans");
  s->addDynamicRel("ol_tolst_ans");
  s->addDynamicRel("temp251S927");
  s->addDynamicRel("temp2zhK928");
  s->addDynamicRel("temp4JmH925");
  s->addDynamicRel("temp8eK6924");
  s->addDynamicRel("temp945P926");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("ol_absent_ans");
  s->addAccelRel("ol_len_ans");
  s->addAccelRel("ol_member_ans");
  s->addAccelRel("ol_ref_ans");
  s->addAccelRel("ol_tolst_ans");
  d->push(s);
  d->continueRun();
}

