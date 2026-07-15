
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const9c24b3c5efa47d78a06173fd;
u64 v_constc0b63bd612a3529319444133;
u64 v_constfab6dbe6378a4772063f8745;
u64 v_constcff65e3a987ac3b552474055;
u64 v_constc0045d3096b5fb58ddb708e4;
u64 v_const434dac19a4d598622b9c67d7;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("e165df3b");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const9c24b3c5efa47d78a06173fd = db->encodeString("member_ok");
  v_constc0b63bd612a3529319444133 = db->encodeString("seq_oracle.slog:34");
  v_constfab6dbe6378a4772063f8745 = db->encodeString("absent_ok");
  v_constcff65e3a987ac3b552474055 = db->encodeString("seq_oracle.slog:44");
  v_constc0045d3096b5fb58ddb708e4 = db->encodeString("ref_ok");
  v_const434dac19a4d598622b9c67d7 = db->encodeString("seq_oracle.slog:39");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord217({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord217, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord218({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord219({1, 2, 0});
    
    r->addIndex<3>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord220({0, 1, 2});
    
    r->addIndex<3>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("take_ok");
  if (r == 0) db->addRelation("take_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("take_ok");
      std::vector<u16> ord221({0, 1});
    
    r->addIndex<2>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("take_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord222({1, 2, 0});
    
    r->addIndex<3>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord223({0, 1, 2});
    
    r->addIndex<3>(ord223, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("seed");
  if (r == 0) db->addRelation("seed", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("seed");
      std::vector<u16> ord224({0, 1});
    
    r->addIndex<2>(ord224, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("seed"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("rev_ok");
  if (r == 0) db->addRelation("rev_ok", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("rev_ok");
      std::vector<u16> ord225({0});
    
    r->addIndex<1>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("rev_ok"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref_ok");
  if (r == 0) db->addRelation("ref_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref_ok");
      std::vector<u16> ord226({0, 1});
    
    r->addIndex<2>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ref_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord227({0});
    
    r->addIndex<1>(ord227, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("probe"), std::array<u16,1>{0}, b));
  r = db->getRelation("ol_tolst_ans");
  if (r == 0) db->addRelation("ol_tolst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst_ans");
      std::vector<u16> ord228({0, 1});
    
    r->addIndex<2>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_tolst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_tolst");
  if (r == 0) db->addStruct("ol_tolst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst");
      std::vector<u16> ord229({1, 0});
    
    r->addIndex<2>(ord229, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord230({0, 1});
    
    r->addIndex<2>(ord230, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_tolst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_take_ans");
  if (r == 0) db->addRelation("ol_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take_ans");
      std::vector<u16> ord231({0, 1});
    
    r->addIndex<2>(ord231, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_take");
  if (r == 0) db->addStruct("ol_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take");
      std::vector<u16> ord232({1, 2, 0});
    
    r->addIndex<3>(ord232, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord233({0, 1, 2});
    
    r->addIndex<3>(ord233, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_rev_ans");
  if (r == 0) db->addRelation("ol_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_ans");
      std::vector<u16> ord234({0, 1});
    
    r->addIndex<2>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc_ans");
  if (r == 0) db->addRelation("ol_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc_ans");
      std::vector<u16> ord235({0, 1});
    
    r->addIndex<2>(ord235, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc");
  if (r == 0) db->addStruct("ol_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc");
      std::vector<u16> ord236({1, 2, 0});
    
    r->addIndex<3>(ord236, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord237({0, 1, 2});
    
    r->addIndex<3>(ord237, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_rev");
  if (r == 0) db->addStruct("ol_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev");
      std::vector<u16> ord238({1, 0});
    
    r->addIndex<2>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord239({0, 1});
    
    r->addIndex<2>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_ref_ans");
  if (r == 0) db->addRelation("ol_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref_ans");
      std::vector<u16> ord240({1, 0});
    
    r->addIndex<2>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_ref_ans"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_ref");
  if (r == 0) db->addStruct("ol_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref");
      std::vector<u16> ord241({2, 1, 0});
    
    r->addIndex<3>(ord241, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord242({0, 2, 1});
    
    r->addIndex<3>(ord242, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_ref"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("ol_member_ans");
  if (r == 0) db->addRelation("ol_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member_ans");
      std::vector<u16> ord243({1, 0});
    
    r->addIndex<2>(ord243, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_member_ans"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_member");
  if (r == 0) db->addStruct("ol_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member");
      std::vector<u16> ord244({2, 1, 0});
    
    r->addIndex<3>(ord244, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord245({0, 2, 1});
    
    r->addIndex<3>(ord245, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_member"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("ol_len_ans");
  if (r == 0) db->addRelation("ol_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len_ans");
      std::vector<u16> ord246({0, 1});
    
    r->addIndex<2>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_len");
  if (r == 0) db->addStruct("ol_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len");
      std::vector<u16> ord247({1, 0});
    
    r->addIndex<2>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord248({0, 1});
    
    r->addIndex<2>(ord248, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_fromlst_ans");
  if (r == 0) db->addRelation("ol_fromlst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord249({0, 1});
    
    r->addIndex<2>(ord249, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord250({1, 0});
    
    r->addIndex<2>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_fromlst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_fromlst");
  if (r == 0) db->addStruct("ol_fromlst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst");
      std::vector<u16> ord251({1, 0});
    
    r->addIndex<2>(ord251, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord252({0, 1});
    
    r->addIndex<2>(ord252, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_fromlst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_append_ans");
  if (r == 0) db->addRelation("ol_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append_ans");
      std::vector<u16> ord253({0, 1});
    
    r->addIndex<2>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_append");
  if (r == 0) db->addStruct("ol_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append");
      std::vector<u16> ord254({1, 2, 0});
    
    r->addIndex<3>(ord254, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord255({0, 1, 2});
    
    r->addIndex<3>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_absent_ans");
  if (r == 0) db->addRelation("ol_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent_ans");
      std::vector<u16> ord256({1, 0});
    
    r->addIndex<2>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_absent_ans"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_absent");
  if (r == 0) db->addStruct("ol_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent");
      std::vector<u16> ord257({2, 1, 0});
    
    r->addIndex<3>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord258({0, 2, 1});
    
    r->addIndex<3>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_absent"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("needle");
  if (r == 0) db->addRelation("needle", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("needle");
      std::vector<u16> ord259({0});
    
    r->addIndex<1>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("needle"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord260({1, 2, 3, 0});
    
    r->addIndex<4>(ord260, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord261({0, 1, 2, 3});
    
    r->addIndex<4>(ord261, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord262({1, 2, 0});
    
    r->addIndex<3>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord263({0, 1, 2});
    
    r->addIndex<3>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord264({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord265({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord266({1, 2, 0});
    
    r->addIndex<3>(ord266, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord267({0, 1, 2});
    
    r->addIndex<3>(ord267, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("member_ok");
  if (r == 0) db->addRelation("member_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("member_ok");
      std::vector<u16> ord268({0, 1});
    
    r->addIndex<2>(ord268, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("member_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord269({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord270({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord270, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lst_take_ans");
  if (r == 0) db->addRelation("lst_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take_ans");
      std::vector<u16> ord271({0, 1});
    
    r->addIndex<2>(ord271, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_take");
  if (r == 0) db->addStruct("lst_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take");
      std::vector<u16> ord272({1, 2, 0});
    
    r->addIndex<3>(ord272, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord273({0, 1, 2});
    
    r->addIndex<3>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev_ans");
  if (r == 0) db->addRelation("lst_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_ans");
      std::vector<u16> ord274({0, 1});
    
    r->addIndex<2>(ord274, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc_ans");
  if (r == 0) db->addRelation("lst_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc_ans");
      std::vector<u16> ord275({0, 1});
    
    r->addIndex<2>(ord275, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc");
  if (r == 0) db->addStruct("lst_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc");
      std::vector<u16> ord276({1, 2, 0});
    
    r->addIndex<3>(ord276, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord277({0, 1, 2});
    
    r->addIndex<3>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev");
  if (r == 0) db->addStruct("lst_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev");
      std::vector<u16> ord278({1, 0});
    
    r->addIndex<2>(ord278, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord279({0, 1});
    
    r->addIndex<2>(ord279, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_ref_ans");
  if (r == 0) db->addRelation("lst_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref_ans");
      std::vector<u16> ord280({0, 1});
    
    r->addIndex<2>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_ref");
  if (r == 0) db->addStruct("lst_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref");
      std::vector<u16> ord281({2, 1, 0});
    
    r->addIndex<3>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord282({0, 1, 2});
    
    r->addIndex<3>(ord282, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_ref"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lst_member_ans");
  if (r == 0) db->addRelation("lst_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member_ans");
      std::vector<u16> ord283({0, 1});
    
    r->addIndex<2>(ord283, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_member");
  if (r == 0) db->addStruct("lst_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member");
      std::vector<u16> ord284({2, 1, 0});
    
    r->addIndex<3>(ord284, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord285({0, 1, 2});
    
    r->addIndex<3>(ord285, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_member"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lst_len_ans");
  if (r == 0) db->addRelation("lst_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len_ans");
      std::vector<u16> ord286({0, 1});
    
    r->addIndex<2>(ord286, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_len");
  if (r == 0) db->addStruct("lst_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len");
      std::vector<u16> ord287({1, 0});
    
    r->addIndex<2>(ord287, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord288({0, 1});
    
    r->addIndex<2>(ord288, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_append_ans");
  if (r == 0) db->addRelation("lst_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append_ans");
      std::vector<u16> ord289({0, 1});
    
    r->addIndex<2>(ord289, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_append");
  if (r == 0) db->addStruct("lst_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append");
      std::vector<u16> ord290({1, 2, 0});
    
    r->addIndex<3>(ord290, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord291({0, 1, 2});
    
    r->addIndex<3>(ord291, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_absent_ans");
  if (r == 0) db->addRelation("lst_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent_ans");
      std::vector<u16> ord292({0, 1});
    
    r->addIndex<2>(ord292, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_absent");
  if (r == 0) db->addStruct("lst_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent");
      std::vector<u16> ord293({2, 1, 0});
    
    r->addIndex<3>(ord293, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord294({0, 1, 2});
    
    r->addIndex<3>(ord294, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_absent"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("len_ok");
  if (r == 0) db->addRelation("len_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("len_ok");
      std::vector<u16> ord295({0, 1});
    
    r->addIndex<2>(ord295, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("len_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord296({1, 2, 3, 0});
    
    r->addIndex<4>(ord296, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord297({0, 1, 2, 3});
    
    r->addIndex<4>(ord297, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord298({0});
    
    r->addIndex<1>(ord298, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord299({1, 2, 0});
    
    r->addIndex<3>(ord299, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord300({0, 1, 2});
    
    r->addIndex<3>(ord300, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ccons");
  if (r == 0) db->addStruct("ccons", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ccons");
      std::vector<u16> ord301({1, 2, 0});
    
    r->addIndex<3>(ord301, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord302({0, 1, 2});
    
    r->addIndex<3>(ord302, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ccons"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("append_ok");
  if (r == 0) db->addRelation("append_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("append_ok");
      std::vector<u16> ord303({0, 1});
    
    r->addIndex<2>(ord303, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("append_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("absent_ok");
  if (r == 0) db->addRelation("absent_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("absent_ok");
      std::vector<u16> ord304({0, 1});
    
    r->addIndex<2>(ord304, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("absent_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord305({1, 0});
    
    r->addIndex<2>(ord305, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord306({0, 1});
    
    r->addIndex<2>(ord306, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup76318x53x0x0x0");
  if (r == 0) db->addRelation("$sup76318x53x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x53x0x0x0");
      std::vector<u16> ord307({0, 1, 2});
    
    r->addIndex<3>(ord307, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x53x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x43x0x0x0");
  if (r == 0) db->addRelation("$sup76318x43x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x43x0x0x0");
      std::vector<u16> ord308({2, 0, 1});
    
    r->addIndex<3>(ord308, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x43x0x0x0"), std::array<u16,3>{2, 0, 1}, b));
  r = db->getRelation("$sup76318x38x0x0x0");
  if (r == 0) db->addRelation("$sup76318x38x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x38x0x0x0");
      std::vector<u16> ord309({2, 0, 1});
    
    r->addIndex<3>(ord309, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x38x0x0x0"), std::array<u16,3>{2, 0, 1}, b));
  r = db->getRelation("$sup76318x33x0x0x0");
  if (r == 0) db->addRelation("$sup76318x33x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x33x0x0x0");
      std::vector<u16> ord310({1, 0, 2});
    
    r->addIndex<3>(ord310, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x33x0x0x0"), std::array<u16,3>{1, 0, 2}, b));
  r = db->getRelation("$sup76318x27x0x0x0");
  if (r == 0) db->addRelation("$sup76318x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x27x0x0x0");
      std::vector<u16> ord311({0, 1, 2, 3});
    
    r->addIndex<4>(ord311, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup76318x27x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x48x0x0x0");
  if (r == 0) db->addRelation("$sup59985x48x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x48x0x0x0");
      std::vector<u16> ord312({0, 1, 2, 3});
    
    r->addIndex<4>(ord312, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x48x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x43x0x0x0");
  if (r == 0) db->addRelation("$sup59985x43x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x43x0x0x0");
      std::vector<u16> ord313({0, 1, 2, 3});
    
    r->addIndex<4>(ord313, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x43x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x37x0x0x0");
  if (r == 0) db->addRelation("$sup59985x37x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x37x0x0x0");
      std::vector<u16> ord314({0, 1, 2});
    
    r->addIndex<3>(ord314, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x37x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup59985x32x0x0x0");
  if (r == 0) db->addRelation("$sup59985x32x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x32x0x0x0");
      std::vector<u16> ord315({0, 1, 2, 3});
    
    r->addIndex<4>(ord315, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x32x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x27x0x0x0");
  if (r == 0) db->addRelation("$sup59985x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x27x0x0x0");
      std::vector<u16> ord316({0, 1, 2, 3});
    
    r->addIndex<4>(ord316, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x27x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x22x0x0x0");
  if (r == 0) db->addRelation("$sup59985x22x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x22x0x0x0");
      std::vector<u16> ord317({0, 1, 2, 3});
    
    r->addIndex<4>(ord317, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x22x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x17x0x0x0");
  if (r == 0) db->addRelation("$sup59985x17x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x17x0x0x0");
      std::vector<u16> ord318({0, 1, 2});
    
    r->addIndex<3>(ord318, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x17x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup59985x12x0x0x0");
  if (r == 0) db->addRelation("$sup59985x12x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x12x0x0x0");
      std::vector<u16> ord319({0, 1, 2, 3});
    
    r->addIndex<4>(ord319, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x12x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord320({0, 1, 2});
    
    r->addIndex<3>(ord320, false);
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
  // (crule (pre (let __trid4f6q304 constc0b63bd612a3529319444133) (let __trel8Rbe305 constc0045d3096b5fb58ddb708e4) (let __tcol9diz306 const5feceb66ffc86f38d952786c)) (scan probe k) (body (exists lst_ref (2 1 0) 1 k) (exists ol_ref (2 1 0) 1 k) (join $sup76318x33x0x0x0 (1 0 2) 1 k i l) (join seed (0 1) 2 i l) (exists ol_fromlst (1 0) 1 l) (join lst_ref (2 1 0) 2 k l __t4S3Y237) (join lst_ref_ans (0 1) 1 __t4S3Y237 v) (join ol_ref_ans (1 0) 1 v __t9seB239) (join ol_ref (0 2 1) 2 __t9seB239 k c) (join ol_fromlst_ans (1 0) 1 c __t06bo238) (join ol_fromlst (0 1) 2 __t06bo238 l)) (head (tycheck i (accept int) __trid4f6q304 __trel8Rbe305 __tcol9diz306 (1 2 3 4 0)) (emit ref_ok (0 1) i k)) seq_oracle.slog:34 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_refindex0;  slog::Index** ol_refindex1;  slog::Index** $sup76318x33x0x0x0index2;  slog::Index** seedindex3;  slog::Index** ol_fromlstindex4;  slog::Index** lst_refindex5;  slog::Index** lst_ref_ansindex6;  slog::Index** ol_ref_ansindex7;  slog::Index** ol_refindex8;  slog::Index** ol_fromlst_ansindex9;  slog::Index** ol_fromlstindex10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("ref_ok");
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("ref_ok");
      head_index[1] = readrel13->getIndex(ord12, false);
      outer_rel = db->getRelation("probe");
      std::vector<u16> ord14({2, 1, 0});
      slog::Relation* readrel15 = db->getRelation("lst_ref");
      lst_refindex0 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({2, 1, 0});
      slog::Relation* readrel17 = db->getRelation("ol_ref");
      ol_refindex1 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 0, 2});
      slog::Relation* readrel19 = db->getRelation("$sup76318x33x0x0x0");
      $sup76318x33x0x0x0index2 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("seed");
      seedindex3 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("ol_fromlst");
      ol_fromlstindex4 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({2, 1, 0});
      slog::Relation* readrel25 = db->getRelation("lst_ref");
      lst_refindex5 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({0, 1});
      slog::Relation* readrel27 = db->getRelation("lst_ref_ans");
      lst_ref_ansindex6 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 0});
      slog::Relation* readrel29 = db->getRelation("ol_ref_ans");
      ol_ref_ansindex7 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 2, 1});
      slog::Relation* readrel31 = db->getRelation("ol_ref");
      ol_refindex8 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex9 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("ol_fromlst");
      ol_fromlstindex10 = readrel35->getIndex(ord34, false);
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constc0b63bd612a3529319444133;
      u64 v_c1 = v_constc0045d3096b5fb58ddb708e4;
      u64 v_c2 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        if (!slog::exists_probe<3,1>(lst_refindex0, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ol_refindex1, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<3,1>($sup76318x33x0x0x0index2, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m36) {
          u64 v_c4 = m36[1]; u64 v_c5 = m36[2];
          slog::join_probe<2,2>(seedindex3, std::array<u64,2>{v_c4, v_c5}, [&](const std::array<u64,2>& m37) {
            if (!slog::exists_probe<2,1>(ol_fromlstindex4, std::array<u64,2>{v_c5, 0})) return;
            slog::join_probe<3,2>(lst_refindex5, std::array<u64,3>{v_c3, v_c5, 0}, [&](const std::array<u64,3>& m38) {
              u64 v_c6 = m38[2];
              slog::join_probe<2,1>(lst_ref_ansindex6, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m39) {
                u64 v_c7 = m39[1];
                slog::join_probe<2,1>(ol_ref_ansindex7, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m40) {
                  u64 v_c8 = m40[1];
                  slog::join_probe<3,2>(ol_refindex8, std::array<u64,3>{v_c8, v_c3, 0}, [&](const std::array<u64,3>& m41) {
                    u64 v_c9 = m41[2];
                    slog::join_probe<2,1>(ol_fromlst_ansindex9, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m42) {
                      u64 v_c10 = m42[1];
                      slog::join_probe<2,2>(ol_fromlstindex10, std::array<u64,2>{v_c10, v_c5}, [&](const std::array<u64,2>& m43) {
                        ++_fires;
                        if (!(is_int(v_c4)))
                        {
                          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
                          return;
                        }
                        slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c4, v_c3}, std::array<u16,2>{0, 1});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:34", "all:probe", _fires);
  
      if (!_done)
      {
        ReadTask11* _cont = new ReadTask11(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask11(db,b), true);
  // (crule (pre) (scan seed i l) (body (exists lst_len (1 0) 1 l) (exists ol_fromlst (1 0) 1 l) (join ol_fromlst_ans (0 1) 0 __t2fHx60 c) (exists ol_fromlst (0 1) 2 __t2fHx60 l) (exists ol_len (1 0) 1 c) (join lst_len (1 0) 1 l __t1DUd59) (join ol_fromlst (0 1) 2 __t2fHx60 l) (exists lst_len_ans (0 1) 1 __t1DUd59) (join ol_len (1 0) 1 c __t1i2561) (join3 n (full lst_len_ans (0 1) 1 () __t1DUd59 n) (full ol_len_ans (0 1) 1 () __t1i2561 n))) (head (emit len_ok (0 1) i n)) seq_oracle.slog:49 #f)
  class ReadTask55 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_lenindex44;  slog::Index** ol_fromlstindex45;  slog::Index** ol_fromlst_ansindex46;  slog::Index** ol_fromlstindex47;  slog::Index** ol_lenindex48;  slog::Index** lst_lenindex49;  slog::Index** ol_fromlstindex50;  slog::Index** lst_len_ansindex51;  slog::Index** ol_lenindex52;  slog::Index** lst_len_ansindex53;  slog::Index** ol_len_ansindex54;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("len_ok");
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("len_ok");
      head_index[0] = readrel57->getIndex(ord56, false);
      outer_rel = db->getRelation("seed");
      std::vector<u16> ord58({1, 0});
      slog::Relation* readrel59 = db->getRelation("lst_len");
      lst_lenindex44 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 0});
      slog::Relation* readrel61 = db->getRelation("ol_fromlst");
      ol_fromlstindex45 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex46 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({0, 1});
      slog::Relation* readrel65 = db->getRelation("ol_fromlst");
      ol_fromlstindex47 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 0});
      slog::Relation* readrel67 = db->getRelation("ol_len");
      ol_lenindex48 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 0});
      slog::Relation* readrel69 = db->getRelation("lst_len");
      lst_lenindex49 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({0, 1});
      slog::Relation* readrel71 = db->getRelation("ol_fromlst");
      ol_fromlstindex50 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({0, 1});
      slog::Relation* readrel73 = db->getRelation("lst_len_ans");
      lst_len_ansindex51 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({1, 0});
      slog::Relation* readrel75 = db->getRelation("ol_len");
      ol_lenindex52 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({0, 1});
      slog::Relation* readrel77 = db->getRelation("lst_len_ans");
      lst_len_ansindex53 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("ol_len_ans");
      ol_len_ansindex54 = readrel79->getIndex(ord78, false);
  
    }
    ReadTask55(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<2,1>(lst_lenindex44, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(ol_fromlstindex45, std::array<u64,2>{v_c5, 0})) return;
        slog::join_all<2>(ol_fromlst_ansindex46, [&](const std::array<u64,2>& m80) {
          u64 v_c11 = m80[0]; u64 v_c9 = m80[1];
          if (!slog::exists_probe<2,2>(ol_fromlstindex47, std::array<u64,2>{v_c11, v_c5})) return;
          if (!slog::exists_probe<2,1>(ol_lenindex48, std::array<u64,2>{v_c9, 0})) return;
          slog::join_probe<2,1>(lst_lenindex49, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m81) {
            u64 v_c12 = m81[1];
            slog::join_probe<2,2>(ol_fromlstindex50, std::array<u64,2>{v_c11, v_c5}, [&](const std::array<u64,2>& m82) {
              if (!slog::exists_probe<2,1>(lst_len_ansindex51, std::array<u64,2>{v_c12, 0})) return;
              slog::join_probe<2,1>(ol_lenindex52, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m83) {
                u64 v_c13 = m83[1];
                slog::join3<2,1,slog::Join3View::full,2,1,slog::Join3View::full>(lst_len_ansindex53, lst_len_ansindex53, std::array<u64,2>{v_c12, 0}, ol_len_ansindex54, ol_len_ansindex54, std::array<u64,2>{v_c13, 0}, [&](u64 cycle84) {
                u64 v_c14 = cycle84;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c14}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:49", "all:seed", _fires);
  
      if (!_done)
      {
        ReadTask55* _cont = new ReadTask55(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask55(db,b), true);
  // (crule (pre (let __trid4n5R330 const434dac19a4d598622b9c67d7) (let __trel5Zeg331 const9c24b3c5efa47d78a06173fd) (let __tcol1zES332 const5feceb66ffc86f38d952786c)) (scan needle y) (body (exists lst_member (2 1 0) 1 y) (exists ol_member (2 1 0) 1 y) (join $sup76318x38x0x0x0 (2 0 1) 1 y i l) (join seed (0 1) 2 i l) (exists ol_fromlst (1 0) 1 l) (join lst_member (2 1 0) 2 y l __t4Rmw5) (join lst_member_ans (0 1) 1 __t4Rmw5 r) (join ol_member_ans (1 0) 1 r __t4vH27) (join ol_member (0 2 1) 2 __t4vH27 y c) (join ol_fromlst_ans (1 0) 1 c __t19LN6) (join ol_fromlst (0 1) 2 __t19LN6 l)) (head (tycheck i (accept int) __trid4n5R330 __trel5Zeg331 __tcol1zES332 (1 2 3 4 0)) (emit member_ok (0 1) i y)) seq_oracle.slog:39 #f)
  class ReadTask96 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_memberindex85;  slog::Index** ol_memberindex86;  slog::Index** $sup76318x38x0x0x0index87;  slog::Index** seedindex88;  slog::Index** ol_fromlstindex89;  slog::Index** lst_memberindex90;  slog::Index** lst_member_ansindex91;  slog::Index** ol_member_ansindex92;  slog::Index** ol_memberindex93;  slog::Index** ol_fromlst_ansindex94;  slog::Index** ol_fromlstindex95;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("member_ok");
      std::vector<u16> ord97({0, 1});
      slog::Relation* readrel98 = db->getRelation("member_ok");
      head_index[1] = readrel98->getIndex(ord97, false);
      outer_rel = db->getRelation("needle");
      std::vector<u16> ord99({2, 1, 0});
      slog::Relation* readrel100 = db->getRelation("lst_member");
      lst_memberindex85 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({2, 1, 0});
      slog::Relation* readrel102 = db->getRelation("ol_member");
      ol_memberindex86 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({2, 0, 1});
      slog::Relation* readrel104 = db->getRelation("$sup76318x38x0x0x0");
      $sup76318x38x0x0x0index87 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("seed");
      seedindex88 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 0});
      slog::Relation* readrel108 = db->getRelation("ol_fromlst");
      ol_fromlstindex89 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({2, 1, 0});
      slog::Relation* readrel110 = db->getRelation("lst_member");
      lst_memberindex90 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 1});
      slog::Relation* readrel112 = db->getRelation("lst_member_ans");
      lst_member_ansindex91 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 0});
      slog::Relation* readrel114 = db->getRelation("ol_member_ans");
      ol_member_ansindex92 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 2, 1});
      slog::Relation* readrel116 = db->getRelation("ol_member");
      ol_memberindex93 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 0});
      slog::Relation* readrel118 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex94 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({0, 1});
      slog::Relation* readrel120 = db->getRelation("ol_fromlst");
      ol_fromlstindex95 = readrel120->getIndex(ord119, false);
  
    }
    ReadTask96(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_const434dac19a4d598622b9c67d7;
      u64 v_c16 = v_const9c24b3c5efa47d78a06173fd;
      u64 v_c17 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c18 = _t[0];
        if (!slog::exists_probe<3,1>(lst_memberindex85, std::array<u64,3>{v_c18, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ol_memberindex86, std::array<u64,3>{v_c18, 0, 0})) return;
        slog::join_probe<3,1>($sup76318x38x0x0x0index87, std::array<u64,3>{v_c18, 0, 0}, [&](const std::array<u64,3>& m121) {
          u64 v_c4 = m121[1]; u64 v_c5 = m121[2];
          slog::join_probe<2,2>(seedindex88, std::array<u64,2>{v_c4, v_c5}, [&](const std::array<u64,2>& m122) {
            if (!slog::exists_probe<2,1>(ol_fromlstindex89, std::array<u64,2>{v_c5, 0})) return;
            slog::join_probe<3,2>(lst_memberindex90, std::array<u64,3>{v_c18, v_c5, 0}, [&](const std::array<u64,3>& m123) {
              u64 v_c19 = m123[2];
              slog::join_probe<2,1>(lst_member_ansindex91, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m124) {
                u64 v_c20 = m124[1];
                slog::join_probe<2,1>(ol_member_ansindex92, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m125) {
                  u64 v_c21 = m125[1];
                  slog::join_probe<3,2>(ol_memberindex93, std::array<u64,3>{v_c21, v_c18, 0}, [&](const std::array<u64,3>& m126) {
                    u64 v_c9 = m126[2];
                    slog::join_probe<2,1>(ol_fromlst_ansindex94, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m127) {
                      u64 v_c22 = m127[1];
                      slog::join_probe<2,2>(ol_fromlstindex95, std::array<u64,2>{v_c22, v_c5}, [&](const std::array<u64,2>& m128) {
                        ++_fires;
                        if (!(is_int(v_c4)))
                        {
                          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c15, v_c16, v_c17, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
                          return;
                        }
                        slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c4, v_c18}, std::array<u16,2>{0, 1});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:39", "all:needle", _fires);
  
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
      s->addTask(phase_read, new ReadTask96(db,b), true);
  // (crule (pre (let __trid0Ya4347 constcff65e3a987ac3b552474055) (let __trel4erq348 constfab6dbe6378a4772063f8745) (let __tcol0fzn349 const5feceb66ffc86f38d952786c)) (scan needle y) (body (exists lst_absent (2 1 0) 1 y) (exists ol_absent (2 1 0) 1 y) (join $sup76318x43x0x0x0 (2 0 1) 1 y i l) (join seed (0 1) 2 i l) (exists ol_fromlst (1 0) 1 l) (join lst_absent (2 1 0) 2 y l __t9nDA72) (join lst_absent_ans (0 1) 1 __t9nDA72 r) (join ol_absent_ans (1 0) 1 r __t997o74) (join ol_absent (0 2 1) 2 __t997o74 y c) (join ol_fromlst_ans (1 0) 1 c __t2THJ73) (join ol_fromlst (0 1) 2 __t2THJ73 l)) (head (tycheck i (accept int) __trid0Ya4347 __trel4erq348 __tcol0fzn349 (1 2 3 4 0)) (emit absent_ok (0 1) i y)) seq_oracle.slog:44 #f)
  class ReadTask140 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_absentindex129;  slog::Index** ol_absentindex130;  slog::Index** $sup76318x43x0x0x0index131;  slog::Index** seedindex132;  slog::Index** ol_fromlstindex133;  slog::Index** lst_absentindex134;  slog::Index** lst_absent_ansindex135;  slog::Index** ol_absent_ansindex136;  slog::Index** ol_absentindex137;  slog::Index** ol_fromlst_ansindex138;  slog::Index** ol_fromlstindex139;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("absent_ok");
      std::vector<u16> ord141({0, 1});
      slog::Relation* readrel142 = db->getRelation("absent_ok");
      head_index[1] = readrel142->getIndex(ord141, false);
      outer_rel = db->getRelation("needle");
      std::vector<u16> ord143({2, 1, 0});
      slog::Relation* readrel144 = db->getRelation("lst_absent");
      lst_absentindex129 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({2, 1, 0});
      slog::Relation* readrel146 = db->getRelation("ol_absent");
      ol_absentindex130 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({2, 0, 1});
      slog::Relation* readrel148 = db->getRelation("$sup76318x43x0x0x0");
      $sup76318x43x0x0x0index131 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("seed");
      seedindex132 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 0});
      slog::Relation* readrel152 = db->getRelation("ol_fromlst");
      ol_fromlstindex133 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({2, 1, 0});
      slog::Relation* readrel154 = db->getRelation("lst_absent");
      lst_absentindex134 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({0, 1});
      slog::Relation* readrel156 = db->getRelation("lst_absent_ans");
      lst_absent_ansindex135 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 0});
      slog::Relation* readrel158 = db->getRelation("ol_absent_ans");
      ol_absent_ansindex136 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({0, 2, 1});
      slog::Relation* readrel160 = db->getRelation("ol_absent");
      ol_absentindex137 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 0});
      slog::Relation* readrel162 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex138 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({0, 1});
      slog::Relation* readrel164 = db->getRelation("ol_fromlst");
      ol_fromlstindex139 = readrel164->getIndex(ord163, false);
  
    }
    ReadTask140(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_constcff65e3a987ac3b552474055;
      u64 v_c24 = v_constfab6dbe6378a4772063f8745;
      u64 v_c25 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c18 = _t[0];
        if (!slog::exists_probe<3,1>(lst_absentindex129, std::array<u64,3>{v_c18, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ol_absentindex130, std::array<u64,3>{v_c18, 0, 0})) return;
        slog::join_probe<3,1>($sup76318x43x0x0x0index131, std::array<u64,3>{v_c18, 0, 0}, [&](const std::array<u64,3>& m165) {
          u64 v_c4 = m165[1]; u64 v_c5 = m165[2];
          slog::join_probe<2,2>(seedindex132, std::array<u64,2>{v_c4, v_c5}, [&](const std::array<u64,2>& m166) {
            if (!slog::exists_probe<2,1>(ol_fromlstindex133, std::array<u64,2>{v_c5, 0})) return;
            slog::join_probe<3,2>(lst_absentindex134, std::array<u64,3>{v_c18, v_c5, 0}, [&](const std::array<u64,3>& m167) {
              u64 v_c26 = m167[2];
              slog::join_probe<2,1>(lst_absent_ansindex135, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m168) {
                u64 v_c20 = m168[1];
                slog::join_probe<2,1>(ol_absent_ansindex136, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m169) {
                  u64 v_c27 = m169[1];
                  slog::join_probe<3,2>(ol_absentindex137, std::array<u64,3>{v_c27, v_c18, 0}, [&](const std::array<u64,3>& m170) {
                    u64 v_c9 = m170[2];
                    slog::join_probe<2,1>(ol_fromlst_ansindex138, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m171) {
                      u64 v_c28 = m171[1];
                      slog::join_probe<2,2>(ol_fromlstindex139, std::array<u64,2>{v_c28, v_c5}, [&](const std::array<u64,2>& m172) {
                        ++_fires;
                        if (!(is_int(v_c4)))
                        {
                          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c23, v_c24, v_c25, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
                          return;
                        }
                        slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c4, v_c18}, std::array<u16,2>{0, 1});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:44", "all:needle", _fires);
  
      if (!_done)
      {
        ReadTask140* _cont = new ReadTask140(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask140(db,b), true);
  // (crule (pre) (scan seed i l) (body (exists ol_fromlst (1 0) 1 l) (join lst_rev (1 0) 1 l __t6gX934) (join lst_rev_ans (0 1) 1 __t6gX934 r) (exists ol_fromlst (1 0) 1 r) (join ol_fromlst (1 0) 1 l __t6Xr235) (join ol_fromlst_ans (0 1) 1 __t6Xr235 c) (join ol_rev (1 0) 1 c __t4YW936) (join ol_rev_ans (0 1) 1 __t4YW936 cr) (join ol_fromlst_ans (1 0) 1 cr __t5IQL37) (join ol_fromlst (0 1) 2 __t5IQL37 r)) (head (emit rev_ok (0) i)) seq_oracle.slog:59 #f)
  class ReadTask183 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex173;  slog::Index** lst_revindex174;  slog::Index** lst_rev_ansindex175;  slog::Index** ol_fromlstindex176;  slog::Index** ol_fromlstindex177;  slog::Index** ol_fromlst_ansindex178;  slog::Index** ol_revindex179;  slog::Index** ol_rev_ansindex180;  slog::Index** ol_fromlst_ansindex181;  slog::Index** ol_fromlstindex182;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("rev_ok");
      std::vector<u16> ord184({0});
      slog::Relation* readrel185 = db->getRelation("rev_ok");
      head_index[0] = readrel185->getIndex(ord184, false);
      outer_rel = db->getRelation("seed");
      std::vector<u16> ord186({1, 0});
      slog::Relation* readrel187 = db->getRelation("ol_fromlst");
      ol_fromlstindex173 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 0});
      slog::Relation* readrel189 = db->getRelation("lst_rev");
      lst_revindex174 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex175 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({1, 0});
      slog::Relation* readrel193 = db->getRelation("ol_fromlst");
      ol_fromlstindex176 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 0});
      slog::Relation* readrel195 = db->getRelation("ol_fromlst");
      ol_fromlstindex177 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({0, 1});
      slog::Relation* readrel197 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex178 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({1, 0});
      slog::Relation* readrel199 = db->getRelation("ol_rev");
      ol_revindex179 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({0, 1});
      slog::Relation* readrel201 = db->getRelation("ol_rev_ans");
      ol_rev_ansindex180 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({1, 0});
      slog::Relation* readrel203 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex181 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({0, 1});
      slog::Relation* readrel205 = db->getRelation("ol_fromlst");
      ol_fromlstindex182 = readrel205->getIndex(ord204, false);
  
    }
    ReadTask183(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<2,1>(ol_fromlstindex173, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<2,1>(lst_revindex174, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m206) {
          u64 v_c29 = m206[1];
          slog::join_probe<2,1>(lst_rev_ansindex175, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m207) {
            u64 v_c20 = m207[1];
            if (!slog::exists_probe<2,1>(ol_fromlstindex176, std::array<u64,2>{v_c20, 0})) return;
            slog::join_probe<2,1>(ol_fromlstindex177, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m208) {
              u64 v_c30 = m208[1];
              slog::join_probe<2,1>(ol_fromlst_ansindex178, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m209) {
                u64 v_c9 = m209[1];
                slog::join_probe<2,1>(ol_revindex179, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m210) {
                  u64 v_c31 = m210[1];
                  slog::join_probe<2,1>(ol_rev_ansindex180, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m211) {
                    u64 v_c32 = m211[1];
                    slog::join_probe<2,1>(ol_fromlst_ansindex181, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m212) {
                      u64 v_c33 = m212[1];
                      slog::join_probe<2,2>(ol_fromlstindex182, std::array<u64,2>{v_c33, v_c20}, [&](const std::array<u64,2>& m213) {
                        ++_fires;
                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("seq_oracle.slog:59", "all:seed", _fires);
  
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
      s->addTask(phase_read, new ReadTask183(db,b), true);
  // (crule (pre) (scan malformed_deduction __erre5gVV935 __errf5dOS936 __errf0Anc937 __errf98gq938 __errf1318939) (body) (head (emit error (0) __erre5gVV935)) <internal>:1 #f)
  class ReadTask214 : public slog::Task
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
      std::vector<u16> ord215({0});
      slog::Relation* readrel216 = db->getRelation("error");
      head_index[0] = readrel216->getIndex(ord215, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask214(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask214* _cont = new ReadTask214(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask214(db,b), false);
  s->addReadRel("$sup76318x33x0x0x0");
  s->addReadRel("$sup76318x38x0x0x0");
  s->addReadRel("$sup76318x43x0x0x0");
  s->addReadRel("lst_absent");
  s->addReadRel("lst_absent_ans");
  s->addReadRel("lst_len");
  s->addReadRel("lst_len_ans");
  s->addReadRel("lst_member");
  s->addReadRel("lst_member_ans");
  s->addReadRel("lst_ref");
  s->addReadRel("lst_ref_ans");
  s->addReadRel("lst_rev");
  s->addReadRel("lst_rev_ans");
  s->addReadRel("malformed_deduction");
  s->addReadRel("needle");
  s->addReadRel("ol_absent");
  s->addReadRel("ol_absent_ans");
  s->addReadRel("ol_fromlst");
  s->addReadRel("ol_fromlst_ans");
  s->addReadRel("ol_len");
  s->addReadRel("ol_len_ans");
  s->addReadRel("ol_member");
  s->addReadRel("ol_member_ans");
  s->addReadRel("ol_ref");
  s->addReadRel("ol_ref_ans");
  s->addReadRel("ol_rev");
  s->addReadRel("ol_rev_ans");
  s->addReadRel("probe");
  s->addReadRel("seed");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("absent_ok");
  s->addDynamicRel("error");
  s->addDynamicRel("len_ok");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("member_ok");
  s->addDynamicRel("ref_ok");
  s->addDynamicRel("rev_ok");
  d->push(s);
  d->continueRun();
}

