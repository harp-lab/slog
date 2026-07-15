
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constc0b63bd612a3529319444133;
u64 v_const2f1258ada6e0e63820dc0fe2;
u64 v_constde3f85f3da4637dccad01619;
u64 v_constbbd5c1cc5d64a17fabdfe5a2;
u64 v_constc46b28403aa820d86ed70496;
u64 v_constf4f38a14dc105d05f231e2bf;
u64 v_const434dac19a4d598622b9c67d7;
u64 v_const057ff4484e1f56ff3c82c82e;
u64 v_constcff65e3a987ac3b552474055;
u64 v_const3f73d01b1816cdbaa7e90747;
u64 v_const9ac63e4426dab2edcc97bcf7;
u64 v_const154aa17dce57824acb89891d;

void slog_rules_c8cc1d9f9b87ffafc(slog::Database* db, slog::Stratum* s);
void slog_rules_cbdf1c850d9e95d30(slog::Database* db, slog::Stratum* s);


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("69afeba1");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constc0b63bd612a3529319444133 = db->encodeString("seq_oracle.slog:34");
  v_const2f1258ada6e0e63820dc0fe2 = db->encodeString("ol_append");
  v_constde3f85f3da4637dccad01619 = db->encodeString("ol_fromlst");
  v_constbbd5c1cc5d64a17fabdfe5a2 = db->encodeString("list-cons.slog:23");
  v_constc46b28403aa820d86ed70496 = db->encodeString("ol_take");
  v_constf4f38a14dc105d05f231e2bf = db->encodeString("seq_oracle.slog:28");
  v_const434dac19a4d598622b9c67d7 = db->encodeString("seq_oracle.slog:39");
  v_const057ff4484e1f56ff3c82c82e = db->encodeString("list-cons.slog:44");
  v_constcff65e3a987ac3b552474055 = db->encodeString("seq_oracle.slog:44");
  v_const3f73d01b1816cdbaa7e90747 = db->encodeString("list-cons.slog:13");
  v_const9ac63e4426dab2edcc97bcf7 = db->encodeString("cnil");
  v_const154aa17dce57824acb89891d = db->encodeString("seq_oracle.slog:54");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord0({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord0, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord1({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord1, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord2({1, 2, 0});
    
    r->addIndex<3>(ord2, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord3({0, 1, 2});
    
    r->addIndex<3>(ord3, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp9VKb789");
  if (r == 0) db->addTempRelation("temp9VKb789", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5iul788");
  if (r == 0) db->addTempRelation("temp5iul788", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3vIA778");
  if (r == 0) db->addTempRelation("temp3vIA778", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2mRb790");
  if (r == 0) db->addTempRelation("temp2mRb790", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2DKT786");
  if (r == 0) db->addTempRelation("temp2DKT786", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("take_ok");
  if (r == 0) db->addRelation("take_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("take_ok");
      std::vector<u16> ord4({0, 1});
    
    r->addIndex<2>(ord4, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("take_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord5({1, 2, 0});
    
    r->addIndex<3>(ord5, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord6({0, 1, 2});
    
    r->addIndex<3>(ord6, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("seed");
  if (r == 0) db->addRelation("seed", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("seed");
      std::vector<u16> ord7({1, 0});
    
    r->addIndex<2>(ord7, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("seed"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("rev_ok");
  if (r == 0) db->addRelation("rev_ok", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("rev_ok");
      std::vector<u16> ord8({0});
    
    r->addIndex<1>(ord8, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("rev_ok"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref_ok");
  if (r == 0) db->addRelation("ref_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref_ok");
      std::vector<u16> ord9({0, 1});
    
    r->addIndex<2>(ord9, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ref_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord10({0});
    
    r->addIndex<1>(ord10, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("probe"), std::array<u16,1>{0}, b));
  r = db->getRelation("ol_tolst_ans");
  if (r == 0) db->addRelation("ol_tolst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst_ans");
      std::vector<u16> ord11({0, 1});
    
    r->addIndex<2>(ord11, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_tolst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_tolst");
  if (r == 0) db->addStruct("ol_tolst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst");
      std::vector<u16> ord12({1, 0});
    
    r->addIndex<2>(ord12, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord13({0, 1});
    
    r->addIndex<2>(ord13, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_tolst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_take_ans");
  if (r == 0) db->addRelation("ol_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take_ans");
      std::vector<u16> ord14({0, 1});
    
    r->addIndex<2>(ord14, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_take");
  if (r == 0) db->addStruct("ol_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take");
      std::vector<u16> ord15({1, 2, 0});
    
    r->addIndex<3>(ord15, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord16({0, 2, 1});
    
    r->addIndex<3>(ord16, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord17({0, 2, 1});
    
    r->addIndex<3>(ord17, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
      std::vector<u16> ord18({1, 2, 0});
    
    r->addIndex<3>(ord18, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord19({2, 0, 1});
    
    r->addIndex<3>(ord19, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_rev_ans");
  if (r == 0) db->addRelation("ol_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_ans");
      std::vector<u16> ord20({0, 1});
    
    r->addIndex<2>(ord20, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc_ans");
  if (r == 0) db->addRelation("ol_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc_ans");
      std::vector<u16> ord21({0, 1});
    
    r->addIndex<2>(ord21, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc");
  if (r == 0) db->addStruct("ol_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc");
      std::vector<u16> ord22({1, 2, 0});
    
    r->addIndex<3>(ord22, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord23({0, 1, 2});
    
    r->addIndex<3>(ord23, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord24({1, 2, 0});
    
    r->addIndex<3>(ord24, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_rev");
  if (r == 0) db->addStruct("ol_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev");
      std::vector<u16> ord25({1, 0});
    
    r->addIndex<2>(ord25, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord26({0, 1});
    
    r->addIndex<2>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_ref_ans");
  if (r == 0) db->addRelation("ol_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref_ans");
      std::vector<u16> ord27({0, 1});
    
    r->addIndex<2>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_ref");
  if (r == 0) db->addStruct("ol_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref");
      std::vector<u16> ord28({1, 2, 0});
    
    r->addIndex<3>(ord28, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord29({0, 1, 2});
    
    r->addIndex<3>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_member_ans");
  if (r == 0) db->addRelation("ol_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member_ans");
      std::vector<u16> ord30({0, 1});
    
    r->addIndex<2>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_member");
  if (r == 0) db->addStruct("ol_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member");
      std::vector<u16> ord31({1, 2, 0});
    
    r->addIndex<3>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord32({0, 1, 2});
    
    r->addIndex<3>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_len_ans");
  if (r == 0) db->addRelation("ol_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len_ans");
      std::vector<u16> ord33({0, 1});
    
    r->addIndex<2>(ord33, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_len");
  if (r == 0) db->addStruct("ol_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len");
      std::vector<u16> ord34({1, 0});
    
    r->addIndex<2>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord35({0, 1});
    
    r->addIndex<2>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_fromlst_ans");
  if (r == 0) db->addRelation("ol_fromlst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord36({0, 1});
    
    r->addIndex<2>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord37({0, 1});
    
    r->addIndex<2>(ord37, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_fromlst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_fromlst");
  if (r == 0) db->addStruct("ol_fromlst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst");
      std::vector<u16> ord38({1, 0});
    
    r->addIndex<2>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord39({0, 1});
    
    r->addIndex<2>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord40({0, 1});
    
    r->addIndex<2>(ord40, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord41({1, 0});
    
    r->addIndex<2>(ord41, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_fromlst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_append_ans");
  if (r == 0) db->addRelation("ol_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append_ans");
      std::vector<u16> ord42({0, 1});
    
    r->addIndex<2>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_append");
  if (r == 0) db->addStruct("ol_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append");
      std::vector<u16> ord43({1, 2, 0});
    
    r->addIndex<3>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord44({0, 2, 1});
    
    r->addIndex<3>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord45({2, 0, 1});
    
    r->addIndex<3>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord46({0, 2, 1});
    
    r->addIndex<3>(ord46, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
      std::vector<u16> ord47({1, 2, 0});
    
    r->addIndex<3>(ord47, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_absent_ans");
  if (r == 0) db->addRelation("ol_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent_ans");
      std::vector<u16> ord48({0, 1});
    
    r->addIndex<2>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_absent");
  if (r == 0) db->addStruct("ol_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent");
      std::vector<u16> ord49({1, 2, 0});
    
    r->addIndex<3>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord50({0, 1, 2});
    
    r->addIndex<3>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("needle");
  if (r == 0) db->addRelation("needle", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("needle");
      std::vector<u16> ord51({0});
    
    r->addIndex<1>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("needle"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord52({1, 2, 3, 0});
    
    r->addIndex<4>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord53({0, 1, 2, 3});
    
    r->addIndex<4>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord54({1, 2, 0});
    
    r->addIndex<3>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord55({0, 1, 2});
    
    r->addIndex<3>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord56({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord57({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord58({1, 2, 0});
    
    r->addIndex<3>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord59({0, 1, 2});
    
    r->addIndex<3>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("member_ok");
  if (r == 0) db->addRelation("member_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("member_ok");
      std::vector<u16> ord60({0, 1});
    
    r->addIndex<2>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("member_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord61({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord62({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lst_take_ans");
  if (r == 0) db->addRelation("lst_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take_ans");
      std::vector<u16> ord63({0, 1});
    
    r->addIndex<2>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_take");
  if (r == 0) db->addStruct("lst_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take");
      std::vector<u16> ord64({1, 2, 0});
    
    r->addIndex<3>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord65({0, 1, 2});
    
    r->addIndex<3>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev_ans");
  if (r == 0) db->addRelation("lst_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_ans");
      std::vector<u16> ord66({0, 1});
    
    r->addIndex<2>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc_ans");
  if (r == 0) db->addRelation("lst_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc_ans");
      std::vector<u16> ord67({0, 1});
    
    r->addIndex<2>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc");
  if (r == 0) db->addStruct("lst_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc");
      std::vector<u16> ord68({1, 2, 0});
    
    r->addIndex<3>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord69({0, 1, 2});
    
    r->addIndex<3>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev");
  if (r == 0) db->addStruct("lst_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev");
      std::vector<u16> ord70({1, 0});
    
    r->addIndex<2>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord71({0, 1});
    
    r->addIndex<2>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_ref_ans");
  if (r == 0) db->addRelation("lst_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref_ans");
      std::vector<u16> ord72({0, 1});
    
    r->addIndex<2>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_ref");
  if (r == 0) db->addStruct("lst_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref");
      std::vector<u16> ord73({1, 2, 0});
    
    r->addIndex<3>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord74({0, 1, 2});
    
    r->addIndex<3>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_member_ans");
  if (r == 0) db->addRelation("lst_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member_ans");
      std::vector<u16> ord75({0, 1});
    
    r->addIndex<2>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_member");
  if (r == 0) db->addStruct("lst_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member");
      std::vector<u16> ord76({1, 2, 0});
    
    r->addIndex<3>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord77({0, 1, 2});
    
    r->addIndex<3>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_len_ans");
  if (r == 0) db->addRelation("lst_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len_ans");
      std::vector<u16> ord78({0, 1});
    
    r->addIndex<2>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_len");
  if (r == 0) db->addStruct("lst_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len");
      std::vector<u16> ord79({1, 0});
    
    r->addIndex<2>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord80({0, 1});
    
    r->addIndex<2>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_append_ans");
  if (r == 0) db->addRelation("lst_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append_ans");
      std::vector<u16> ord81({0, 1});
    
    r->addIndex<2>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_append");
  if (r == 0) db->addStruct("lst_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append");
      std::vector<u16> ord82({1, 2, 0});
    
    r->addIndex<3>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord83({0, 1, 2});
    
    r->addIndex<3>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord84({2, 0, 1});
    
    r->addIndex<3>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_absent_ans");
  if (r == 0) db->addRelation("lst_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent_ans");
      std::vector<u16> ord85({0, 1});
    
    r->addIndex<2>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_absent");
  if (r == 0) db->addStruct("lst_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent");
      std::vector<u16> ord86({1, 2, 0});
    
    r->addIndex<3>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord87({0, 1, 2});
    
    r->addIndex<3>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("len_ok");
  if (r == 0) db->addRelation("len_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("len_ok");
      std::vector<u16> ord88({0, 1});
    
    r->addIndex<2>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("len_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord89({1, 2, 3, 0});
    
    r->addIndex<4>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord90({0, 1, 2, 3});
    
    r->addIndex<4>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord91({0});
    
    r->addIndex<1>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord92({1, 2, 0});
    
    r->addIndex<3>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord93({0, 1, 2});
    
    r->addIndex<3>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ccons");
  if (r == 0) db->addStruct("ccons", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ccons");
      std::vector<u16> ord94({2, 1, 0});
    
    r->addIndex<3>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord95({0, 1, 2});
    
    r->addIndex<3>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord96({2, 1, 0});
    
    r->addIndex<3>(ord96, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ccons"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("append_ok");
  if (r == 0) db->addRelation("append_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("append_ok");
      std::vector<u16> ord97({0, 1});
    
    r->addIndex<2>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("append_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("absent_ok");
  if (r == 0) db->addRelation("absent_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("absent_ok");
      std::vector<u16> ord98({0, 1});
    
    r->addIndex<2>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("absent_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord99({1, 0});
    
    r->addIndex<2>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord100({0, 1});
    
    r->addIndex<2>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup76318x53x0x0x0");
  if (r == 0) db->addRelation("$sup76318x53x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x53x0x0x0");
      std::vector<u16> ord101({2, 0, 1});
    
    r->addIndex<3>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x53x0x0x0"), std::array<u16,3>{2, 0, 1}, b));
  r = db->getRelation("$sup76318x43x0x0x0");
  if (r == 0) db->addRelation("$sup76318x43x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x43x0x0x0");
      std::vector<u16> ord102({0, 1, 2});
    
    r->addIndex<3>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x43x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x38x0x0x0");
  if (r == 0) db->addRelation("$sup76318x38x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x38x0x0x0");
      std::vector<u16> ord103({0, 1, 2});
    
    r->addIndex<3>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x38x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x33x0x0x0");
  if (r == 0) db->addRelation("$sup76318x33x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x33x0x0x0");
      std::vector<u16> ord104({0, 1, 2});
    
    r->addIndex<3>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x33x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x27x0x0x0");
  if (r == 0) db->addRelation("$sup76318x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x27x0x0x0");
      std::vector<u16> ord105({0, 1, 2, 3});
    
    r->addIndex<4>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
      std::vector<u16> ord106({1, 0, 2, 3});
    
    r->addIndex<4>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 0, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup76318x27x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x48x0x0x0");
  if (r == 0) db->addRelation("$sup59985x48x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x48x0x0x0");
      std::vector<u16> ord107({0, 1, 2, 3});
    
    r->addIndex<4>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x48x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x43x0x0x0");
  if (r == 0) db->addRelation("$sup59985x43x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x43x0x0x0");
      std::vector<u16> ord108({3, 2, 0, 1});
    
    r->addIndex<4>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 2, 0, 1}, false, b), true);
      std::vector<u16> ord109({0, 1, 2, 3});
    
    r->addIndex<4>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord110({3, 2, 0, 1});
    
    r->addIndex<4>(ord110, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x43x0x0x0"), std::array<u16,4>{3, 2, 0, 1}, b));
  r = db->getRelation("$sup59985x37x0x0x0");
  if (r == 0) db->addRelation("$sup59985x37x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x37x0x0x0");
      std::vector<u16> ord111({0, 1, 2});
    
    r->addIndex<3>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x37x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup59985x32x0x0x0");
  if (r == 0) db->addRelation("$sup59985x32x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x32x0x0x0");
      std::vector<u16> ord112({0, 1, 2, 3});
    
    r->addIndex<4>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x32x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x27x0x0x0");
  if (r == 0) db->addRelation("$sup59985x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x27x0x0x0");
      std::vector<u16> ord113({0, 1, 2, 3});
    
    r->addIndex<4>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x27x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x22x0x0x0");
  if (r == 0) db->addRelation("$sup59985x22x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x22x0x0x0");
      std::vector<u16> ord114({0, 1, 2, 3});
    
    r->addIndex<4>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
      std::vector<u16> ord115({1, 3, 0, 2});
    
    r->addIndex<4>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 0, 2}, false, b), false);
      std::vector<u16> ord116({2, 3, 0, 1});
    
    r->addIndex<4>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), false);
      std::vector<u16> ord117({1, 3, 0, 2});
    
    r->addIndex<4>(ord117, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x22x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x17x0x0x0");
  if (r == 0) db->addRelation("$sup59985x17x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x17x0x0x0");
      std::vector<u16> ord118({0, 1, 2});
    
    r->addIndex<3>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x17x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup59985x12x0x0x0");
  if (r == 0) db->addRelation("$sup59985x12x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x12x0x0x0");
      std::vector<u16> ord119({3, 0, 2, 1});
    
    r->addIndex<4>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 0, 2, 1}, false, b), true);
      std::vector<u16> ord120({3, 0, 2, 1});
    
    r->addIndex<4>(ord120, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 0, 2, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x12x0x0x0"), std::array<u16,4>{3, 0, 2, 1}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord121({1, 0, 2});
    
    r->addIndex<3>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
      std::vector<u16> ord122({1, 0, 2});
    
    r->addIndex<3>(ord122, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{1, 0, 2}, b));
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
  slog_rules_c8cc1d9f9b87ffafc(db, s);
  slog_rules_cbdf1c850d9e95d30(db, s);
  s->addReadRel("$seq_at");
  s->addReadRel("$sup59985x12x0x0x0");
  s->addReadRel("$sup59985x22x0x0x0");
  s->addReadRel("$sup59985x43x0x0x0");
  s->addReadRel("$sup76318x27x0x0x0");
  s->addReadRel("$sup76318x33x0x0x0");
  s->addReadRel("$sup76318x38x0x0x0");
  s->addReadRel("$sup76318x43x0x0x0");
  s->addReadRel("$sup76318x53x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("ccons");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("lst_append");
  s->addReadRel("lst_append_ans");
  s->addReadRel("lst_rev");
  s->addReadRel("lst_rev_ans");
  s->addReadRel("lst_take");
  s->addReadRel("lst_take_ans");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("ol_append");
  s->addReadRel("ol_append_ans");
  s->addReadRel("ol_fromlst");
  s->addReadRel("ol_fromlst_ans");
  s->addReadRel("ol_rev");
  s->addReadRel("ol_rev_acc");
  s->addReadRel("ol_take");
  s->addReadRel("ol_take_ans");
  s->addReadRel("seed");
  s->addReadRel("temp2DKT786");
  s->addReadRel("temp2mRb790");
  s->addReadRel("temp3vIA778");
  s->addReadRel("temp5iul788");
  s->addReadRel("temp9VKb789");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$sup59985x12x0x0x0");
  s->addDynamicRel("$sup59985x22x0x0x0");
  s->addDynamicRel("$sup59985x43x0x0x0");
  s->addDynamicRel("ccons");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("ol_append");
  s->addDynamicRel("ol_append_ans");
  s->addDynamicRel("ol_fromlst");
  s->addDynamicRel("ol_fromlst_ans");
  s->addDynamicRel("ol_rev");
  s->addDynamicRel("ol_rev_acc");
  s->addDynamicRel("ol_take");
  s->addDynamicRel("ol_take_ans");
  s->addDynamicRel("temp2DKT786");
  s->addDynamicRel("temp2mRb790");
  s->addDynamicRel("temp3vIA778");
  s->addDynamicRel("temp5iul788");
  s->addDynamicRel("temp9VKb789");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("ol_append_ans");
  s->addAccelRel("ol_fromlst_ans");
  s->addAccelRel("ol_take_ans");
  d->push(s);
  d->continueRun();
}

