
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const8687ddba6906021b5a4bac9b;
u64 v_constaae57d1a02887551630c1e3d;
u64 v_const7d24ae77b98941e042da3f94;
u64 v_const1b184dfe78d73e9e64378261;
u64 v_constbb5a31ed15121428c352c59b;
u64 v_constf4f38a14dc105d05f231e2bf;
u64 v_constb2879a30c6ed138226ee848f;
u64 v_const0c81821545944b087b718eeb;
u64 v_constfdbf5e2af450f963953acef1;
u64 v_consta7c87b54a14930acc837ba7c;
u64 v_const154aa17dce57824acb89891d;
u64 v_const9ac63e4426dab2edcc97bcf7;
u64 v_constf604aff6a32f1912a44cb1c7;
u64 v_const58bedc2e3ff72fba5236f715;
u64 v_const20f7f401d42560fee602a8bd;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("a9a86a19");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const8687ddba6906021b5a4bac9b = db->encodeString("list-cons.slog:49");
  v_constaae57d1a02887551630c1e3d = db->encodeString("list-cons.slog:33");
  v_const7d24ae77b98941e042da3f94 = db->encodeString("ol_ref");
  v_const1b184dfe78d73e9e64378261 = db->encodeString("ol_absent");
  v_constbb5a31ed15121428c352c59b = db->encodeString("take_ok");
  v_constf4f38a14dc105d05f231e2bf = db->encodeString("seq_oracle.slog:28");
  v_constb2879a30c6ed138226ee848f = db->encodeString("ol_len");
  v_const0c81821545944b087b718eeb = db->encodeString("list-cons.slog:18");
  v_constfdbf5e2af450f963953acef1 = db->encodeString("append_ok");
  v_consta7c87b54a14930acc837ba7c = db->encodeString("ol_tolst");
  v_const154aa17dce57824acb89891d = db->encodeString("seq_oracle.slog:54");
  v_const9ac63e4426dab2edcc97bcf7 = db->encodeString("cnil");
  v_constf604aff6a32f1912a44cb1c7 = db->encodeString("ol_member");
  v_const58bedc2e3ff72fba5236f715 = db->encodeString("list-cons.slog:38");
  v_const20f7f401d42560fee602a8bd = db->encodeString("list-cons.slog:28");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord312({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord312, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord313({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord313, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord314({1, 2, 0});
    
    r->addIndex<3>(ord314, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord315({0, 1, 2});
    
    r->addIndex<3>(ord315, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp0U9L863");
  if (r == 0) db->addTempRelation("temp0U9L863", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("take_ok");
  if (r == 0) db->addRelation("take_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("take_ok");
      std::vector<u16> ord316({0, 1});
    
    r->addIndex<2>(ord316, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("take_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord317({1, 2, 0});
    
    r->addIndex<3>(ord317, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord318({0, 1, 2});
    
    r->addIndex<3>(ord318, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("seed");
  if (r == 0) db->addRelation("seed", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("seed");
      std::vector<u16> ord319({0, 1});
    
    r->addIndex<2>(ord319, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("seed"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("rev_ok");
  if (r == 0) db->addRelation("rev_ok", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("rev_ok");
      std::vector<u16> ord320({0});
    
    r->addIndex<1>(ord320, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("rev_ok"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref_ok");
  if (r == 0) db->addRelation("ref_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref_ok");
      std::vector<u16> ord321({0, 1});
    
    r->addIndex<2>(ord321, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ref_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord322({0});
    
    r->addIndex<1>(ord322, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("probe"), std::array<u16,1>{0}, b));
  r = db->getRelation("ol_tolst_ans");
  if (r == 0) db->addRelation("ol_tolst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst_ans");
      std::vector<u16> ord323({0, 1});
    
    r->addIndex<2>(ord323, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_tolst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_tolst");
  if (r == 0) db->addStruct("ol_tolst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst");
      std::vector<u16> ord324({1, 0});
    
    r->addIndex<2>(ord324, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord325({0, 1});
    
    r->addIndex<2>(ord325, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_tolst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_take_ans");
  if (r == 0) db->addRelation("ol_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take_ans");
      std::vector<u16> ord326({0, 1});
    
    r->addIndex<2>(ord326, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_take");
  if (r == 0) db->addStruct("ol_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take");
      std::vector<u16> ord327({2, 1, 0});
    
    r->addIndex<3>(ord327, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord328({0, 1, 2});
    
    r->addIndex<3>(ord328, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_take"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("ol_rev_ans");
  if (r == 0) db->addRelation("ol_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_ans");
      std::vector<u16> ord329({0, 1});
    
    r->addIndex<2>(ord329, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc_ans");
  if (r == 0) db->addRelation("ol_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc_ans");
      std::vector<u16> ord330({0, 1});
    
    r->addIndex<2>(ord330, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc");
  if (r == 0) db->addStruct("ol_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc");
      std::vector<u16> ord331({1, 2, 0});
    
    r->addIndex<3>(ord331, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord332({0, 1, 2});
    
    r->addIndex<3>(ord332, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_rev");
  if (r == 0) db->addStruct("ol_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev");
      std::vector<u16> ord333({1, 0});
    
    r->addIndex<2>(ord333, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord334({0, 1});
    
    r->addIndex<2>(ord334, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_ref_ans");
  if (r == 0) db->addRelation("ol_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref_ans");
      std::vector<u16> ord335({0, 1});
    
    r->addIndex<2>(ord335, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_ref");
  if (r == 0) db->addStruct("ol_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref");
      std::vector<u16> ord336({1, 2, 0});
    
    r->addIndex<3>(ord336, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord337({0, 1, 2});
    
    r->addIndex<3>(ord337, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_member_ans");
  if (r == 0) db->addRelation("ol_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member_ans");
      std::vector<u16> ord338({0, 1});
    
    r->addIndex<2>(ord338, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_member");
  if (r == 0) db->addStruct("ol_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member");
      std::vector<u16> ord339({1, 2, 0});
    
    r->addIndex<3>(ord339, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord340({0, 1, 2});
    
    r->addIndex<3>(ord340, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_len_ans");
  if (r == 0) db->addRelation("ol_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len_ans");
      std::vector<u16> ord341({0, 1});
    
    r->addIndex<2>(ord341, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_len");
  if (r == 0) db->addStruct("ol_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len");
      std::vector<u16> ord342({1, 0});
    
    r->addIndex<2>(ord342, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord343({0, 1});
    
    r->addIndex<2>(ord343, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_fromlst_ans");
  if (r == 0) db->addRelation("ol_fromlst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord344({0, 1});
    
    r->addIndex<2>(ord344, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord345({1, 0});
    
    r->addIndex<2>(ord345, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_fromlst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_fromlst");
  if (r == 0) db->addStruct("ol_fromlst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst");
      std::vector<u16> ord346({1, 0});
    
    r->addIndex<2>(ord346, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord347({0, 1});
    
    r->addIndex<2>(ord347, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_fromlst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_append_ans");
  if (r == 0) db->addRelation("ol_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append_ans");
      std::vector<u16> ord348({0, 1});
    
    r->addIndex<2>(ord348, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_append");
  if (r == 0) db->addStruct("ol_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append");
      std::vector<u16> ord349({1, 2, 0});
    
    r->addIndex<3>(ord349, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord350({0, 1, 2});
    
    r->addIndex<3>(ord350, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_absent_ans");
  if (r == 0) db->addRelation("ol_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent_ans");
      std::vector<u16> ord351({0, 1});
    
    r->addIndex<2>(ord351, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_absent");
  if (r == 0) db->addStruct("ol_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent");
      std::vector<u16> ord352({1, 2, 0});
    
    r->addIndex<3>(ord352, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord353({0, 1, 2});
    
    r->addIndex<3>(ord353, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("needle");
  if (r == 0) db->addRelation("needle", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("needle");
      std::vector<u16> ord354({0});
    
    r->addIndex<1>(ord354, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("needle"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord355({1, 2, 3, 0});
    
    r->addIndex<4>(ord355, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord356({0, 1, 2, 3});
    
    r->addIndex<4>(ord356, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord357({1, 2, 0});
    
    r->addIndex<3>(ord357, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord358({0, 1, 2});
    
    r->addIndex<3>(ord358, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord359({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord359, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord360({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord360, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord361({1, 2, 0});
    
    r->addIndex<3>(ord361, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord362({0, 1, 2});
    
    r->addIndex<3>(ord362, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("member_ok");
  if (r == 0) db->addRelation("member_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("member_ok");
      std::vector<u16> ord363({0, 1});
    
    r->addIndex<2>(ord363, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("member_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord364({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord364, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord365({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord365, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lst_take_ans");
  if (r == 0) db->addRelation("lst_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take_ans");
      std::vector<u16> ord366({0, 1});
    
    r->addIndex<2>(ord366, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_take");
  if (r == 0) db->addStruct("lst_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take");
      std::vector<u16> ord367({2, 1, 0});
    
    r->addIndex<3>(ord367, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord368({0, 1, 2});
    
    r->addIndex<3>(ord368, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_take"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("lst_rev_ans");
  if (r == 0) db->addRelation("lst_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_ans");
      std::vector<u16> ord369({0, 1});
    
    r->addIndex<2>(ord369, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc_ans");
  if (r == 0) db->addRelation("lst_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc_ans");
      std::vector<u16> ord370({0, 1});
    
    r->addIndex<2>(ord370, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc");
  if (r == 0) db->addStruct("lst_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc");
      std::vector<u16> ord371({1, 2, 0});
    
    r->addIndex<3>(ord371, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord372({0, 1, 2});
    
    r->addIndex<3>(ord372, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev");
  if (r == 0) db->addStruct("lst_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev");
      std::vector<u16> ord373({1, 0});
    
    r->addIndex<2>(ord373, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord374({0, 1});
    
    r->addIndex<2>(ord374, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_ref_ans");
  if (r == 0) db->addRelation("lst_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref_ans");
      std::vector<u16> ord375({0, 1});
    
    r->addIndex<2>(ord375, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_ref");
  if (r == 0) db->addStruct("lst_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref");
      std::vector<u16> ord376({1, 2, 0});
    
    r->addIndex<3>(ord376, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord377({0, 1, 2});
    
    r->addIndex<3>(ord377, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_member_ans");
  if (r == 0) db->addRelation("lst_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member_ans");
      std::vector<u16> ord378({0, 1});
    
    r->addIndex<2>(ord378, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_member");
  if (r == 0) db->addStruct("lst_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member");
      std::vector<u16> ord379({1, 2, 0});
    
    r->addIndex<3>(ord379, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord380({0, 1, 2});
    
    r->addIndex<3>(ord380, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_len_ans");
  if (r == 0) db->addRelation("lst_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len_ans");
      std::vector<u16> ord381({0, 1});
    
    r->addIndex<2>(ord381, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_len");
  if (r == 0) db->addStruct("lst_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len");
      std::vector<u16> ord382({1, 0});
    
    r->addIndex<2>(ord382, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord383({0, 1});
    
    r->addIndex<2>(ord383, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_append_ans");
  if (r == 0) db->addRelation("lst_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append_ans");
      std::vector<u16> ord384({0, 1});
    
    r->addIndex<2>(ord384, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_append");
  if (r == 0) db->addStruct("lst_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append");
      std::vector<u16> ord385({1, 2, 0});
    
    r->addIndex<3>(ord385, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord386({0, 1, 2});
    
    r->addIndex<3>(ord386, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_absent_ans");
  if (r == 0) db->addRelation("lst_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent_ans");
      std::vector<u16> ord387({0, 1});
    
    r->addIndex<2>(ord387, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_absent");
  if (r == 0) db->addStruct("lst_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent");
      std::vector<u16> ord388({1, 2, 0});
    
    r->addIndex<3>(ord388, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord389({0, 1, 2});
    
    r->addIndex<3>(ord389, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("len_ok");
  if (r == 0) db->addRelation("len_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("len_ok");
      std::vector<u16> ord390({0, 1});
    
    r->addIndex<2>(ord390, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("len_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord391({1, 2, 3, 0});
    
    r->addIndex<4>(ord391, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord392({0, 1, 2, 3});
    
    r->addIndex<4>(ord392, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord393({0});
    
    r->addIndex<1>(ord393, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord394({1, 2, 0});
    
    r->addIndex<3>(ord394, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord395({0, 1, 2});
    
    r->addIndex<3>(ord395, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ccons");
  if (r == 0) db->addStruct("ccons", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ccons");
      std::vector<u16> ord396({2, 1, 0});
    
    r->addIndex<3>(ord396, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord397({0, 1, 2});
    
    r->addIndex<3>(ord397, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ccons"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("append_ok");
  if (r == 0) db->addRelation("append_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("append_ok");
      std::vector<u16> ord398({0, 1});
    
    r->addIndex<2>(ord398, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("append_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("absent_ok");
  if (r == 0) db->addRelation("absent_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("absent_ok");
      std::vector<u16> ord399({0, 1});
    
    r->addIndex<2>(ord399, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("absent_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord400({1, 0});
    
    r->addIndex<2>(ord400, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord401({0, 1});
    
    r->addIndex<2>(ord401, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord402({1, 0});
    
    r->addIndex<2>(ord402, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup76318x53x0x0x0");
  if (r == 0) db->addRelation("$sup76318x53x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x53x0x0x0");
      std::vector<u16> ord403({1, 0, 2});
    
    r->addIndex<3>(ord403, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x53x0x0x0"), std::array<u16,3>{1, 0, 2}, b));
  r = db->getRelation("$sup76318x43x0x0x0");
  if (r == 0) db->addRelation("$sup76318x43x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x43x0x0x0");
      std::vector<u16> ord404({1, 2, 0});
    
    r->addIndex<3>(ord404, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x43x0x0x0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("$sup76318x38x0x0x0");
  if (r == 0) db->addRelation("$sup76318x38x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x38x0x0x0");
      std::vector<u16> ord405({1, 2, 0});
    
    r->addIndex<3>(ord405, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x38x0x0x0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("$sup76318x33x0x0x0");
  if (r == 0) db->addRelation("$sup76318x33x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x33x0x0x0");
      std::vector<u16> ord406({1, 2, 0});
    
    r->addIndex<3>(ord406, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x33x0x0x0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("$sup76318x27x0x0x0");
  if (r == 0) db->addRelation("$sup76318x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x27x0x0x0");
      std::vector<u16> ord407({0, 2, 1, 3});
    
    r->addIndex<4>(ord407, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 2, 1, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup76318x27x0x0x0"), std::array<u16,4>{0, 2, 1, 3}, b));
  r = db->getRelation("$sup59985x48x0x0x0");
  if (r == 0) db->addRelation("$sup59985x48x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x48x0x0x0");
      std::vector<u16> ord408({0, 1, 2, 3});
    
    r->addIndex<4>(ord408, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x48x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x43x0x0x0");
  if (r == 0) db->addRelation("$sup59985x43x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x43x0x0x0");
      std::vector<u16> ord409({0, 1, 2, 3});
    
    r->addIndex<4>(ord409, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x43x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x37x0x0x0");
  if (r == 0) db->addRelation("$sup59985x37x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x37x0x0x0");
      std::vector<u16> ord410({0, 1, 2});
    
    r->addIndex<3>(ord410, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x37x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup59985x32x0x0x0");
  if (r == 0) db->addRelation("$sup59985x32x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x32x0x0x0");
      std::vector<u16> ord411({0, 1, 2, 3});
    
    r->addIndex<4>(ord411, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x32x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x27x0x0x0");
  if (r == 0) db->addRelation("$sup59985x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x27x0x0x0");
      std::vector<u16> ord412({0, 1, 2, 3});
    
    r->addIndex<4>(ord412, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x27x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x22x0x0x0");
  if (r == 0) db->addRelation("$sup59985x22x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x22x0x0x0");
      std::vector<u16> ord413({0, 1, 2, 3});
    
    r->addIndex<4>(ord413, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x22x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x17x0x0x0");
  if (r == 0) db->addRelation("$sup59985x17x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x17x0x0x0");
      std::vector<u16> ord414({0, 1, 2});
    
    r->addIndex<3>(ord414, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x17x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup59985x12x0x0x0");
  if (r == 0) db->addRelation("$sup59985x12x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x12x0x0x0");
      std::vector<u16> ord415({0, 1, 2, 3});
    
    r->addIndex<4>(ord415, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x12x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord416({0, 1, 2});
    
    r->addIndex<3>(ord416, false);
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
  // (crule (pre) (scan ol_tolst __t1w1076 __t8puL75) (body (join ccons (0 1 2) 1 __t8puL75 x xs)) (head (emit $sup59985x17x0x0x0 (0 1 2) __t1w1076 x xs)) list-cons.slog:18 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup59985x17x0x0x0");
      std::vector<u16> ord2({0, 1, 2});
      slog::Relation* readrel3 = db->getRelation("$sup59985x17x0x0x0");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("ol_tolst");
      std::vector<u16> ord4({0, 1, 2});
      slog::Relation* readrel5 = db->getRelation("ccons");
      cconsindex0 = readrel5->getIndex(ord4, false);
  
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
        u64 v_c0 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe<3,1>(cconsindex0, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m6) {
          u64 v_c2 = m6[1]; u64 v_c3 = m6[2];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c0, v_c2, v_c3}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:18", "delta:ol_tolst", _fires);
  
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
  // (crule (pre (let __trid4Zok354 const154aa17dce57824acb89891d) (let __trel1U0o355 constbb5a31ed15121428c352c59b) (let __tcol4Kxk356 const5feceb66ffc86f38d952786c)) (scan probe k) (body (exists lst_take (2 1 0) 1 k) (exists ol_take (2 1 0) 1 k) (join $sup76318x53x0x0x0 (1 0 2) 1 k i l) (join seed (0 1) 2 i l) (exists ol_fromlst (1 0) 1 l) (join lst_take (2 1 0) 2 k l __t2SIB244) (join lst_take_ans (0 1) 1 __t2SIB244 r) (exists ol_fromlst (1 0) 1 r) (join ol_fromlst (1 0) 1 l __t8nUV245) (join ol_fromlst_ans (0 1) 1 __t8nUV245 c) (join ol_take (2 1 0) 2 k c __t91YM246) (join ol_take_ans (0 1) 1 __t91YM246 cr) (join ol_fromlst_ans (1 0) 1 cr __t6H3I247) (join ol_fromlst (0 1) 2 __t6H3I247 r)) (head (tycheck i (accept int) __trid4Zok354 __trel1U0o355 __tcol4Kxk356 (1 2 3 4 0)) (emit take_ok (0 1) i k)) seq_oracle.slog:54 #f)
  class ReadTask21 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_takeindex7;  slog::Index** ol_takeindex8;  slog::Index** $sup76318x53x0x0x0index9;  slog::Index** seedindex10;  slog::Index** ol_fromlstindex11;  slog::Index** lst_takeindex12;  slog::Index** lst_take_ansindex13;  slog::Index** ol_fromlstindex14;  slog::Index** ol_fromlstindex15;  slog::Index** ol_fromlst_ansindex16;  slog::Index** ol_takeindex17;  slog::Index** ol_take_ansindex18;  slog::Index** ol_fromlst_ansindex19;  slog::Index** ol_fromlstindex20;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("take_ok");
      std::vector<u16> ord22({0, 1});
      slog::Relation* readrel23 = db->getRelation("take_ok");
      head_index[1] = readrel23->getIndex(ord22, false);
      outer_rel = db->getRelation("probe");
      std::vector<u16> ord24({2, 1, 0});
      slog::Relation* readrel25 = db->getRelation("lst_take");
      lst_takeindex7 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({2, 1, 0});
      slog::Relation* readrel27 = db->getRelation("ol_take");
      ol_takeindex8 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 0, 2});
      slog::Relation* readrel29 = db->getRelation("$sup76318x53x0x0x0");
      $sup76318x53x0x0x0index9 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1});
      slog::Relation* readrel31 = db->getRelation("seed");
      seedindex10 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("ol_fromlst");
      ol_fromlstindex11 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({2, 1, 0});
      slog::Relation* readrel35 = db->getRelation("lst_take");
      lst_takeindex12 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({0, 1});
      slog::Relation* readrel37 = db->getRelation("lst_take_ans");
      lst_take_ansindex13 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 0});
      slog::Relation* readrel39 = db->getRelation("ol_fromlst");
      ol_fromlstindex14 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 0});
      slog::Relation* readrel41 = db->getRelation("ol_fromlst");
      ol_fromlstindex15 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({0, 1});
      slog::Relation* readrel43 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex16 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({2, 1, 0});
      slog::Relation* readrel45 = db->getRelation("ol_take");
      ol_takeindex17 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({0, 1});
      slog::Relation* readrel47 = db->getRelation("ol_take_ans");
      ol_take_ansindex18 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 0});
      slog::Relation* readrel49 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex19 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({0, 1});
      slog::Relation* readrel51 = db->getRelation("ol_fromlst");
      ol_fromlstindex20 = readrel51->getIndex(ord50, false);
  
    }
    ReadTask21(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const154aa17dce57824acb89891d;
      u64 v_c5 = v_constbb5a31ed15121428c352c59b;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c7 = _t[0];
        if (!slog::exists_probe<3,1>(lst_takeindex7, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ol_takeindex8, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<3,1>($sup76318x53x0x0x0index9, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m52) {
          u64 v_c8 = m52[1]; u64 v_c9 = m52[2];
          slog::join_probe<2,2>(seedindex10, std::array<u64,2>{v_c8, v_c9}, [&](const std::array<u64,2>& m53) {
            if (!slog::exists_probe<2,1>(ol_fromlstindex11, std::array<u64,2>{v_c9, 0})) return;
            slog::join_probe<3,2>(lst_takeindex12, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m54) {
              u64 v_c10 = m54[2];
              slog::join_probe<2,1>(lst_take_ansindex13, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m55) {
                u64 v_c11 = m55[1];
                if (!slog::exists_probe<2,1>(ol_fromlstindex14, std::array<u64,2>{v_c11, 0})) return;
                slog::join_probe<2,1>(ol_fromlstindex15, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m56) {
                  u64 v_c12 = m56[1];
                  slog::join_probe<2,1>(ol_fromlst_ansindex16, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m57) {
                    u64 v_c13 = m57[1];
                    slog::join_probe<3,2>(ol_takeindex17, std::array<u64,3>{v_c7, v_c13, 0}, [&](const std::array<u64,3>& m58) {
                      u64 v_c14 = m58[2];
                      slog::join_probe<2,1>(ol_take_ansindex18, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m59) {
                        u64 v_c15 = m59[1];
                        slog::join_probe<2,1>(ol_fromlst_ansindex19, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m60) {
                          u64 v_c16 = m60[1];
                          slog::join_probe<2,2>(ol_fromlstindex20, std::array<u64,2>{v_c16, v_c11}, [&](const std::array<u64,2>& m61) {
                            ++_fires;
                            if (!(is_int(v_c8)))
                            {
                              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c4, v_c5, v_c6, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
                              return;
                            }
                            slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c8, v_c7}, std::array<u16,2>{0, 1});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:54", "all:probe", _fires);
  
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
      s->addTask(phase_read, new ReadTask21(db,b), true);
  // (crule (pre) (scan malformed_deduction __erre0Lc7828 __errf0u7N829 __errf2Dry830 __errf6OcY831 __errf2Ik3832) (body) (head (emit error (0) __erre0Lc7828)) <internal>:1 #f)
  class ReadTask62 : public slog::Task
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
      std::vector<u16> ord63({0});
      slog::Relation* readrel64 = db->getRelation("error");
      head_index[0] = readrel64->getIndex(ord63, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask62(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[1];
        u64 v_c19 = _t[2];
        u64 v_c20 = _t[3];
        u64 v_c21 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c17}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
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
  // (crule (pre) (scan lst_member_ans __t81Ln54 r) (body (join lst_member (0 1 2) 1 __t81Ln54 l y) (exists ol_fromlst (1 0) 1 l) (join $sup76318x38x0x0x0 (1 2 0) 2 l y i) (join ol_fromlst (1 0) 1 l __t4gWM55) (join ol_fromlst_ans (0 1) 1 __t4gWM55 c)) (head (mkstruct ol_member (1 2 0) __16B2422 c y)) seq_oracle.slog:39 #f)
  class ReadTask70 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_memberindex65;  slog::Index** ol_fromlstindex66;  slog::Index** $sup76318x38x0x0x0index67;  slog::Index** ol_fromlstindex68;  slog::Index** ol_fromlst_ansindex69;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_member");
      outer_rel = db->getRelation("lst_member_ans");
      std::vector<u16> ord71({0, 1, 2});
      slog::Relation* readrel72 = db->getRelation("lst_member");
      lst_memberindex65 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 0});
      slog::Relation* readrel74 = db->getRelation("ol_fromlst");
      ol_fromlstindex66 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 2, 0});
      slog::Relation* readrel76 = db->getRelation("$sup76318x38x0x0x0");
      $sup76318x38x0x0x0index67 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 0});
      slog::Relation* readrel78 = db->getRelation("ol_fromlst");
      ol_fromlstindex68 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex69 = readrel80->getIndex(ord79, false);
  
    }
    ReadTask70(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        slog::join_probe<3,1>(lst_memberindex65, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m81) {
          u64 v_c9 = m81[1]; u64 v_c23 = m81[2];
          if (!slog::exists_probe<2,1>(ol_fromlstindex66, std::array<u64,2>{v_c9, 0})) return;
          slog::join_probe<3,2>($sup76318x38x0x0x0index67, std::array<u64,3>{v_c9, v_c23, 0}, [&](const std::array<u64,3>& m82) {
            u64 v_c8 = m82[2];
            slog::join_probe<2,1>(ol_fromlstindex68, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m83) {
              u64 v_c24 = m83[1];
              slog::join_probe<2,1>(ol_fromlst_ansindex69, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m84) {
                u64 v_c13 = m84[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c13, v_c23}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:39", "all:lst_member_ans", _fires);
  
      if (!_done)
      {
        ReadTask70* _cont = new ReadTask70(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask70(db,b), true);
  // (crule (pre) (scan nan_result __erre6GVF843 __errf0xYx844 __errf4Lr0845 __errf7Jt6846) (body) (head (emit error (0) __erre6GVF843)) <internal>:1 #f)
  class ReadTask85 : public slog::Task
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
      std::vector<u16> ord86({0});
      slog::Relation* readrel87 = db->getRelation("error");
      head_index[0] = readrel87->getIndex(ord86, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask85(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[2];
        u64 v_c28 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask85* _cont = new ReadTask85(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask85(db,b), false);
  // (crule (pre) (scan lst_absent_ans __t11fw242 r) (body (join lst_absent (0 1 2) 1 __t11fw242 l y) (exists ol_fromlst (1 0) 1 l) (join $sup76318x43x0x0x0 (1 2 0) 2 l y i) (join ol_fromlst (1 0) 1 l __t5EPQ243) (join ol_fromlst_ans (0 1) 1 __t5EPQ243 c)) (head (mkstruct ol_absent (1 2 0) __39I7399 c y)) seq_oracle.slog:44 #f)
  class ReadTask93 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_absentindex88;  slog::Index** ol_fromlstindex89;  slog::Index** $sup76318x43x0x0x0index90;  slog::Index** ol_fromlstindex91;  slog::Index** ol_fromlst_ansindex92;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_absent");
      outer_rel = db->getRelation("lst_absent_ans");
      std::vector<u16> ord94({0, 1, 2});
      slog::Relation* readrel95 = db->getRelation("lst_absent");
      lst_absentindex88 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 0});
      slog::Relation* readrel97 = db->getRelation("ol_fromlst");
      ol_fromlstindex89 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 2, 0});
      slog::Relation* readrel99 = db->getRelation("$sup76318x43x0x0x0");
      $sup76318x43x0x0x0index90 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 0});
      slog::Relation* readrel101 = db->getRelation("ol_fromlst");
      ol_fromlstindex91 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 1});
      slog::Relation* readrel103 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex92 = readrel103->getIndex(ord102, false);
  
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
        u64 v_c29 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_probe<3,1>(lst_absentindex88, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m104) {
          u64 v_c9 = m104[1]; u64 v_c23 = m104[2];
          if (!slog::exists_probe<2,1>(ol_fromlstindex89, std::array<u64,2>{v_c9, 0})) return;
          slog::join_probe<3,2>($sup76318x43x0x0x0index90, std::array<u64,3>{v_c9, v_c23, 0}, [&](const std::array<u64,3>& m105) {
            u64 v_c8 = m105[2];
            slog::join_probe<2,1>(ol_fromlstindex91, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m106) {
              u64 v_c30 = m106[1];
              slog::join_probe<2,1>(ol_fromlst_ansindex92, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m107) {
                u64 v_c13 = m107[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c13, v_c23}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:44", "all:lst_absent_ans", _fires);
  
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
      s->addTask(phase_read, new ReadTask93(db,b), true);
  // (crule (pre) (scan ol_len __t3Oib89 __t9xHA88) (body (join ccons (0 1 2) 1 __t9xHA88 x xs)) (head (emit $sup59985x37x0x0x0 (0 1 2) __t3Oib89 x xs)) list-cons.slog:38 #f)
  class ReadTask109 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex108;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup59985x37x0x0x0");
      std::vector<u16> ord110({0, 1, 2});
      slog::Relation* readrel111 = db->getRelation("$sup59985x37x0x0x0");
      head_index[0] = readrel111->getIndex(ord110, false);
      outer_rel = db->getRelation("ol_len");
      std::vector<u16> ord112({0, 1, 2});
      slog::Relation* readrel113 = db->getRelation("ccons");
      cconsindex108 = readrel113->getIndex(ord112, false);
  
    }
    ReadTask109(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[1];
        slog::join_probe<3,1>(cconsindex108, std::array<u64,3>{v_c32, 0, 0}, [&](const std::array<u64,3>& m114) {
          u64 v_c2 = m114[1]; u64 v_c3 = m114[2];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c31, v_c2, v_c3}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:38", "delta:ol_len", _fires);
  
      if (!_done)
      {
        ReadTask109* _cont = new ReadTask109(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask109(db,b), false);
  // (crule (pre) (scan int_overflow __erre5ZKa839 __errf9gDy840 __errf777b841 __errf8jXh842) (body) (head (emit error (0) __erre5ZKa839)) <internal>:1 #f)
  class ReadTask115 : public slog::Task
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
      std::vector<u16> ord116({0});
      slog::Relation* readrel117 = db->getRelation("error");
      head_index[0] = readrel117->getIndex(ord116, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask115(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c35 = _t[2];
        u64 v_c36 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c33}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask115* _cont = new ReadTask115(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask115(db,b), false);
  // (crule (pre (let __trid7Aou308 constaae57d1a02887551630c1e3d) (let __trel4k1i309 constf604aff6a32f1912a44cb1c7) (let __tcol6V8r310 const5feceb66ffc86f38d952786c)) (scan $sup59985x32x0x0x0 __d0 x xs y) (body) (head (tycheck xs (accept (struct ccons) (struct _enum)) __trid7Aou308 __trel4k1i309 __tcol6V8r310 (1 2 3 4 0)) (mkstruct ol_member (1 2 0) __7mfS307 xs y)) list-cons.slog:33 #f)
  class ReadTask120 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid119;  u32 sid118;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("ol_member");
      outer_rel = db->getRelation("$sup59985x32x0x0x0");
      sid119 = db->getRelation("_enum")->getStructId();
      sid118 = db->getRelation("ccons")->getStructId();
  
    }
    ReadTask120(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_constaae57d1a02887551630c1e3d;
      u64 v_c38 = v_constf604aff6a32f1912a44cb1c7;
      u64 v_c39 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c23 = _t[3];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid118 || decode_struct_id(v_c3) == sid119))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c37, v_c38, v_c39, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c3, v_c23}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:33", "delta:$sup59985x32x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask120* _cont = new ReadTask120(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask120(db,b), false);
  // (crule (pre) (scan div_by_zero __erre1gDw833 __errf1U5v834 __errf77Hm835) (body) (head (emit error (0) __erre1gDw833)) <internal>:1 #f)
  class ReadTask121 : public slog::Task
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
      std::vector<u16> ord122({0});
      slog::Relation* readrel123 = db->getRelation("error");
      head_index[0] = readrel123->getIndex(ord122, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask121(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c41}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask121* _cont = new ReadTask121(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask121(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre657j860 __errf8dBb861 __errf8WMh862) (body) (head (emit error (0) __erre657j860)) <internal>:1 #f)
  class ReadTask124 : public slog::Task
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
      std::vector<u16> ord125({0});
      slog::Relation* readrel126 = db->getRelation("error");
      head_index[0] = readrel126->getIndex(ord125, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask124(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[0];
        u64 v_c45 = _t[1];
        u64 v_c46 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c44}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask124* _cont = new ReadTask124(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask124(db,b), false);
  // (crule (pre) (scan ol_rev_acc_ans __t3haS83 r) (body (join ol_rev_acc (0 1 2) 1 __t3haS83 xs __t507z82) (join ccons (2 1 0) 1 xs x __t36IB80) (exists ol_rev_acc (1 2 0) 1 __t36IB80) (join ccons (0 1 2) 2 __t507z82 x acc) (join ol_rev_acc (1 2 0) 2 __t36IB80 acc __t3Kbh81)) (head (emit ol_rev_acc_ans (0 1) __t3Kbh81 r)) list-cons.slog:54 #f)
  class ReadTask132 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_rev_accindex127;  slog::Index** cconsindex128;  slog::Index** ol_rev_accindex129;  slog::Index** cconsindex130;  slog::Index** ol_rev_accindex131;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_rev_acc_ans");
      std::vector<u16> ord133({0, 1});
      slog::Relation* readrel134 = db->getRelation("ol_rev_acc_ans");
      head_index[0] = readrel134->getIndex(ord133, false);
      outer_rel = db->getRelation("ol_rev_acc_ans");
      std::vector<u16> ord135({0, 1, 2});
      slog::Relation* readrel136 = db->getRelation("ol_rev_acc");
      ol_rev_accindex127 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({2, 1, 0});
      slog::Relation* readrel138 = db->getRelation("ccons");
      cconsindex128 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 2, 0});
      slog::Relation* readrel140 = db->getRelation("ol_rev_acc");
      ol_rev_accindex129 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({0, 1, 2});
      slog::Relation* readrel142 = db->getRelation("ccons");
      cconsindex130 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 2, 0});
      slog::Relation* readrel144 = db->getRelation("ol_rev_acc");
      ol_rev_accindex131 = readrel144->getIndex(ord143, false);
  
    }
    ReadTask132(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        slog::join_probe<3,1>(ol_rev_accindex127, std::array<u64,3>{v_c47, 0, 0}, [&](const std::array<u64,3>& m145) {
          u64 v_c3 = m145[1]; u64 v_c48 = m145[2];
          slog::join_probe<3,1>(cconsindex128, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m146) {
            u64 v_c2 = m146[1]; u64 v_c49 = m146[2];
            if (!slog::exists_probe<3,1>(ol_rev_accindex129, std::array<u64,3>{v_c49, 0, 0})) return;
            slog::join_probe<3,2>(cconsindex130, std::array<u64,3>{v_c48, v_c2, 0}, [&](const std::array<u64,3>& m147) {
              u64 v_c50 = m147[2];
              slog::join_probe<3,2>(ol_rev_accindex131, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m148) {
                u64 v_c51 = m148[2];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c51, v_c11}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:54", "delta:ol_rev_acc_ans", _fires);
  
      if (!_done)
      {
        ReadTask132* _cont = new ReadTask132(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask132(db,b), false);
  // (crule (pre) (scan ol_member __t2dWi133 __t2xd5132 y) (body (join ccons (0 1 2) 1 __t2xd5132 x xs) (neq x y)) (head (emit $sup59985x32x0x0x0 (0 1 2 3) __t2dWi133 x xs y)) list-cons.slog:33 #f)
  class ReadTask150 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex149;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup59985x32x0x0x0");
      std::vector<u16> ord151({0, 1, 2, 3});
      slog::Relation* readrel152 = db->getRelation("$sup59985x32x0x0x0");
      head_index[0] = readrel152->getIndex(ord151, false);
      outer_rel = db->getRelation("ol_member");
      std::vector<u16> ord153({0, 1, 2});
      slog::Relation* readrel154 = db->getRelation("ccons");
      cconsindex149 = readrel154->getIndex(ord153, false);
  
    }
    ReadTask150(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe<3,1>(cconsindex149, std::array<u64,3>{v_c53, 0, 0}, [&](const std::array<u64,3>& m155) {
          u64 v_c2 = m155[1]; u64 v_c3 = m155[2];
          if (v_c2 == v_c23) return;
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c52, v_c2, v_c3, v_c23}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:33", "delta:ol_member", _fires);
  
      if (!_done)
      {
        ReadTask150* _cont = new ReadTask150(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask150(db,b), false);
  // (crule (pre) (scan lst_ref_ans __t0j6b32 v) (body (join lst_ref (0 1 2) 1 __t0j6b32 l k) (exists ol_fromlst (1 0) 1 l) (join $sup76318x33x0x0x0 (1 2 0) 2 k l i) (join ol_fromlst (1 0) 1 l __t4opN33) (join ol_fromlst_ans (0 1) 1 __t4opN33 c)) (head (mkstruct ol_ref (1 2 0) __5PMe300 c k)) seq_oracle.slog:34 #f)
  class ReadTask161 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_refindex156;  slog::Index** ol_fromlstindex157;  slog::Index** $sup76318x33x0x0x0index158;  slog::Index** ol_fromlstindex159;  slog::Index** ol_fromlst_ansindex160;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_ref");
      outer_rel = db->getRelation("lst_ref_ans");
      std::vector<u16> ord162({0, 1, 2});
      slog::Relation* readrel163 = db->getRelation("lst_ref");
      lst_refindex156 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 0});
      slog::Relation* readrel165 = db->getRelation("ol_fromlst");
      ol_fromlstindex157 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({1, 2, 0});
      slog::Relation* readrel167 = db->getRelation("$sup76318x33x0x0x0");
      $sup76318x33x0x0x0index158 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({1, 0});
      slog::Relation* readrel169 = db->getRelation("ol_fromlst");
      ol_fromlstindex159 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({0, 1});
      slog::Relation* readrel171 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex160 = readrel171->getIndex(ord170, false);
  
    }
    ReadTask161(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<3,1>(lst_refindex156, std::array<u64,3>{v_c54, 0, 0}, [&](const std::array<u64,3>& m172) {
          u64 v_c9 = m172[1]; u64 v_c7 = m172[2];
          if (!slog::exists_probe<2,1>(ol_fromlstindex157, std::array<u64,2>{v_c9, 0})) return;
          slog::join_probe<3,2>($sup76318x33x0x0x0index158, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m173) {
            u64 v_c8 = m173[2];
            slog::join_probe<2,1>(ol_fromlstindex159, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m174) {
              u64 v_c56 = m174[1];
              slog::join_probe<2,1>(ol_fromlst_ansindex160, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m175) {
                u64 v_c13 = m175[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c13, v_c7}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:34", "all:lst_ref_ans", _fires);
  
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
      s->addTask(phase_read, new ReadTask161(db,b), true);
  // (crule (pre) (scan modulo_by_zero __erre7JlN836 __errf5st3837 __errf0ndp838) (body) (head (emit error (0) __erre7JlN836)) <internal>:1 #f)
  class ReadTask176 : public slog::Task
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
      std::vector<u16> ord177({0});
      slog::Relation* readrel178 = db->getRelation("error");
      head_index[0] = readrel178->getIndex(ord177, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask176(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask176* _cont = new ReadTask176(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask176(db,b), false);
  // (crule (pre (let __trid6B5A390 const8687ddba6906021b5a4bac9b) (let __trel97uP391 const1b184dfe78d73e9e64378261) (let __tcol0QQU392 const5feceb66ffc86f38d952786c)) (scan $sup59985x48x0x0x0 __d0 x xs y) (body) (head (tycheck xs (accept (struct ccons) (struct _enum)) __trid6B5A390 __trel97uP391 __tcol0QQU392 (1 2 3 4 0)) (mkstruct ol_absent (1 2 0) __8HMf389 xs y)) list-cons.slog:49 #f)
  class ReadTask181 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid180;  u32 sid179;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("ol_absent");
      outer_rel = db->getRelation("$sup59985x48x0x0x0");
      sid180 = db->getRelation("_enum")->getStructId();
      sid179 = db->getRelation("ccons")->getStructId();
  
    }
    ReadTask181(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c60 = v_const8687ddba6906021b5a4bac9b;
      u64 v_c61 = v_const1b184dfe78d73e9e64378261;
      u64 v_c62 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c23 = _t[3];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid179 || decode_struct_id(v_c3) == sid180))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c60, v_c61, v_c62, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c3, v_c23}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:49", "delta:$sup59985x48x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask181* _cont = new ReadTask181(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask181(db,b), false);
  // (crule (pre) (scan toint_range __erre2isS847 __errf0iyk848 __errf9VC1849) (body) (head (emit error (0) __erre2isS847)) <internal>:1 #f)
  class ReadTask182 : public slog::Task
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
      std::vector<u16> ord183({0});
      slog::Relation* readrel184 = db->getRelation("error");
      head_index[0] = readrel184->getIndex(ord183, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask182(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[0];
        u64 v_c64 = _t[1];
        u64 v_c65 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c63}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask182* _cont = new ReadTask182(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask182(db,b), false);
  // (crule (pre) (scan ol_absent __t33kD241 __t9kC8240 y) (body (join ccons (0 1 2) 1 __t9kC8240 x xs) (neq x y)) (head (emit $sup59985x48x0x0x0 (0 1 2 3) __t33kD241 x xs y)) list-cons.slog:49 #f)
  class ReadTask186 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex185;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup59985x48x0x0x0");
      std::vector<u16> ord187({0, 1, 2, 3});
      slog::Relation* readrel188 = db->getRelation("$sup59985x48x0x0x0");
      head_index[0] = readrel188->getIndex(ord187, false);
      outer_rel = db->getRelation("ol_absent");
      std::vector<u16> ord189({0, 1, 2});
      slog::Relation* readrel190 = db->getRelation("ccons");
      cconsindex185 = readrel190->getIndex(ord189, false);
  
    }
    ReadTask186(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c66 = _t[0];
        u64 v_c67 = _t[1];
        u64 v_c23 = _t[2];
        slog::join_probe<3,1>(cconsindex185, std::array<u64,3>{v_c67, 0, 0}, [&](const std::array<u64,3>& m191) {
          u64 v_c2 = m191[1]; u64 v_c3 = m191[2];
          if (v_c2 == v_c23) return;
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c66, v_c2, v_c3, v_c23}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:49", "delta:ol_absent", _fires);
  
      if (!_done)
      {
        ReadTask186* _cont = new ReadTask186(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask186(db,b), false);
  // (crule (pre (let __trid5c4U334 constf4f38a14dc105d05f231e2bf) (let __trel8fJ2335 constfdbf5e2af450f963953acef1) (let __tcol1ZSa336 const5feceb66ffc86f38d952786c) (let __trel4I8Z337 constfdbf5e2af450f963953acef1) (let __tcol3dxZ338 const6b86b273ff34fce19d6b804e)) (scan seed i a) (body (exists lst_append (1 2 0) 1 a) (exists ol_fromlst (1 0) 1 a) (join $sup76318x27x0x0x0 (0 2 1 3) 2 a i b j) (join seed (0 1) 2 j b) (exists ol_fromlst (1 0) 1 b) (join lst_append (1 2 0) 2 a b __t9Ykc134) (join lst_append_ans (0 1) 1 __t9Ykc134 r) (exists ol_fromlst (1 0) 1 r) (join ol_fromlst (1 0) 1 a __t0tMk135) (join ol_fromlst_ans (0 1) 1 __t0tMk135 ca) (exists ol_append (1 2 0) 1 ca) (join ol_fromlst (1 0) 1 b __t0QYk136) (join ol_fromlst_ans (0 1) 1 __t0QYk136 cb) (join ol_append (1 2 0) 2 ca cb __t041z137) (join ol_append_ans (0 1) 1 __t041z137 cr) (join ol_fromlst_ans (1 0) 1 cr __t3TXD138) (join ol_fromlst (0 1) 2 __t3TXD138 r)) (head (tycheck i (accept int) __trid5c4U334 __trel8fJ2335 __tcol1ZSa336 (1 2 3 4 0)) (tycheck j (accept int) __trid5c4U334 __trel4I8Z337 __tcol3dxZ338 (1 2 3 4 0)) (emit append_ok (0 1) i j)) seq_oracle.slog:28 #f)
  class ReadTask209 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_appendindex192;  slog::Index** ol_fromlstindex193;  slog::Index** $sup76318x27x0x0x0index194;  slog::Index** seedindex195;  slog::Index** ol_fromlstindex196;  slog::Index** lst_appendindex197;  slog::Index** lst_append_ansindex198;  slog::Index** ol_fromlstindex199;  slog::Index** ol_fromlstindex200;  slog::Index** ol_fromlst_ansindex201;  slog::Index** ol_appendindex202;  slog::Index** ol_fromlstindex203;  slog::Index** ol_fromlst_ansindex204;  slog::Index** ol_appendindex205;  slog::Index** ol_append_ansindex206;  slog::Index** ol_fromlst_ansindex207;  slog::Index** ol_fromlstindex208;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("append_ok");
      std::vector<u16> ord210({0, 1});
      slog::Relation* readrel211 = db->getRelation("append_ok");
      head_index[2] = readrel211->getIndex(ord210, false);
      outer_rel = db->getRelation("seed");
      std::vector<u16> ord212({1, 2, 0});
      slog::Relation* readrel213 = db->getRelation("lst_append");
      lst_appendindex192 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 0});
      slog::Relation* readrel215 = db->getRelation("ol_fromlst");
      ol_fromlstindex193 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({0, 2, 1, 3});
      slog::Relation* readrel217 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index194 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0, 1});
      slog::Relation* readrel219 = db->getRelation("seed");
      seedindex195 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 0});
      slog::Relation* readrel221 = db->getRelation("ol_fromlst");
      ol_fromlstindex196 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 0});
      slog::Relation* readrel223 = db->getRelation("lst_append");
      lst_appendindex197 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({0, 1});
      slog::Relation* readrel225 = db->getRelation("lst_append_ans");
      lst_append_ansindex198 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 0});
      slog::Relation* readrel227 = db->getRelation("ol_fromlst");
      ol_fromlstindex199 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 0});
      slog::Relation* readrel229 = db->getRelation("ol_fromlst");
      ol_fromlstindex200 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({0, 1});
      slog::Relation* readrel231 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex201 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 2, 0});
      slog::Relation* readrel233 = db->getRelation("ol_append");
      ol_appendindex202 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 0});
      slog::Relation* readrel235 = db->getRelation("ol_fromlst");
      ol_fromlstindex203 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({0, 1});
      slog::Relation* readrel237 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex204 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 0});
      slog::Relation* readrel239 = db->getRelation("ol_append");
      ol_appendindex205 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({0, 1});
      slog::Relation* readrel241 = db->getRelation("ol_append_ans");
      ol_append_ansindex206 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 0});
      slog::Relation* readrel243 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex207 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({0, 1});
      slog::Relation* readrel245 = db->getRelation("ol_fromlst");
      ol_fromlstindex208 = readrel245->getIndex(ord244, false);
  
    }
    ReadTask209(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c68 = v_constf4f38a14dc105d05f231e2bf;
      u64 v_c69 = v_constfdbf5e2af450f963953acef1;
      u64 v_c70 = v_const5feceb66ffc86f38d952786c;
      u64 v_c71 = v_constfdbf5e2af450f963953acef1;
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c8 = _t[0];
        u64 v_c73 = _t[1];
        if (!slog::exists_probe<3,1>(lst_appendindex192, std::array<u64,3>{v_c73, 0, 0})) return;
        if (!slog::exists_probe<2,1>(ol_fromlstindex193, std::array<u64,2>{v_c73, 0})) return;
        slog::join_probe<4,2>($sup76318x27x0x0x0index194, std::array<u64,4>{v_c73, v_c8, 0, 0}, [&](const std::array<u64,4>& m246) {
          u64 v_c74 = m246[2]; u64 v_c75 = m246[3];
          slog::join_probe<2,2>(seedindex195, std::array<u64,2>{v_c75, v_c74}, [&](const std::array<u64,2>& m247) {
            if (!slog::exists_probe<2,1>(ol_fromlstindex196, std::array<u64,2>{v_c74, 0})) return;
            slog::join_probe<3,2>(lst_appendindex197, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m248) {
              u64 v_c76 = m248[2];
              slog::join_probe<2,1>(lst_append_ansindex198, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m249) {
                u64 v_c11 = m249[1];
                if (!slog::exists_probe<2,1>(ol_fromlstindex199, std::array<u64,2>{v_c11, 0})) return;
                slog::join_probe<2,1>(ol_fromlstindex200, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m250) {
                  u64 v_c77 = m250[1];
                  slog::join_probe<2,1>(ol_fromlst_ansindex201, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m251) {
                    u64 v_c78 = m251[1];
                    if (!slog::exists_probe<3,1>(ol_appendindex202, std::array<u64,3>{v_c78, 0, 0})) return;
                    slog::join_probe<2,1>(ol_fromlstindex203, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m252) {
                      u64 v_c79 = m252[1];
                      slog::join_probe<2,1>(ol_fromlst_ansindex204, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m253) {
                        u64 v_c80 = m253[1];
                        slog::join_probe<3,2>(ol_appendindex205, std::array<u64,3>{v_c78, v_c80, 0}, [&](const std::array<u64,3>& m254) {
                          u64 v_c81 = m254[2];
                          slog::join_probe<2,1>(ol_append_ansindex206, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m255) {
                            u64 v_c15 = m255[1];
                            slog::join_probe<2,1>(ol_fromlst_ansindex207, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m256) {
                              u64 v_c82 = m256[1];
                              slog::join_probe<2,2>(ol_fromlstindex208, std::array<u64,2>{v_c82, v_c11}, [&](const std::array<u64,2>& m257) {
                                ++_fires;
                                if (!(is_int(v_c8)))
                                {
                                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c68, v_c69, v_c70, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
                                  return;
                                }
                                if (!(is_int(v_c75)))
                                {
                                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c68, v_c71, v_c72, v_c75}, std::array<u16,5>{1, 2, 3, 4, 0});
                                  return;
                                }
                                slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c8, v_c75}, std::array<u16,2>{0, 1});
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:28", "all:seed", _fires);
  
      if (!_done)
      {
        ReadTask209* _cont = new ReadTask209(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask209(db,b), true);
  // (crule (pre (let __tconst0r9L259 const5feceb66ffc86f38d952786c)) (scan ol_ref __t3tEA258 __t6wJp257 n) (body (cmp lt __tconst0r9L259 n) (join ccons (0 1 2) 1 __t6wJp257 x xs)) (head (emit $sup59985x27x0x0x0 (0 1 2 3) __t3tEA258 n x xs)) list-cons.slog:28 #f)
  class ReadTask259 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex258;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup59985x27x0x0x0");
      std::vector<u16> ord260({0, 1, 2, 3});
      slog::Relation* readrel261 = db->getRelation("$sup59985x27x0x0x0");
      head_index[0] = readrel261->getIndex(ord260, false);
      outer_rel = db->getRelation("ol_ref");
      std::vector<u16> ord262({0, 1, 2});
      slog::Relation* readrel263 = db->getRelation("ccons");
      cconsindex258 = readrel263->getIndex(ord262, false);
  
    }
    ReadTask259(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c86 = _t[2];
        u64 v_c87 = _prim_lt(db, v_c83, v_c86);
        if (v_c87 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:28"); return; }
        if (!v_c87) return;
        slog::join_probe<3,1>(cconsindex258, std::array<u64,3>{v_c85, 0, 0}, [&](const std::array<u64,3>& m265) {
          u64 v_c2 = m265[1]; u64 v_c3 = m265[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c84, v_c86, v_c2, v_c3}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:28", "delta:ol_ref", _fires);
  
      if (!_done)
      {
        ReadTask259* _cont = new ReadTask259(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask259(db,b), false);
  // (crule (pre) (scan temp0U9L863 __t45JF51 xs) (body) (head (mkstruct ol_ref (1 2 0) __68eI343 xs __t45JF51)) list-cons.slog:28 #f)
  class ReadTask266 : public slog::Task
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
      head_rel[0] = db->getRelation("ol_ref");
      outer_rel = db->getRelation("temp0U9L863");
  
    }
    ReadTask266(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c88 = _t[0];
        u64 v_c3 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c88}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:28", "delta:temp0U9L863", _fires);
  
      if (!_done)
      {
        ReadTask266* _cont = new ReadTask266(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask266(db,b), false);
  // (crule (pre) (scan seed i l) (body (exists ol_fromlst (1 0) 1 l) (join lst_len (1 0) 1 l __t1l1H38) (join lst_len_ans (0 1) 1 __t1l1H38 n) (join ol_fromlst (1 0) 1 l __t4iuu39) (join ol_fromlst_ans (0 1) 1 __t4iuu39 c)) (head (mkstruct ol_len (1 0) __0RMU418 c)) seq_oracle.slog:49 #f)
  class ReadTask272 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex267;  slog::Index** lst_lenindex268;  slog::Index** lst_len_ansindex269;  slog::Index** ol_fromlstindex270;  slog::Index** ol_fromlst_ansindex271;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_len");
      outer_rel = db->getRelation("seed");
      std::vector<u16> ord273({1, 0});
      slog::Relation* readrel274 = db->getRelation("ol_fromlst");
      ol_fromlstindex267 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({1, 0});
      slog::Relation* readrel276 = db->getRelation("lst_len");
      lst_lenindex268 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("lst_len_ans");
      lst_len_ansindex269 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({1, 0});
      slog::Relation* readrel280 = db->getRelation("ol_fromlst");
      ol_fromlstindex270 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({0, 1});
      slog::Relation* readrel282 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex271 = readrel282->getIndex(ord281, false);
  
    }
    ReadTask272(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[0];
        u64 v_c9 = _t[1];
        if (!slog::exists_probe<2,1>(ol_fromlstindex267, std::array<u64,2>{v_c9, 0})) return;
        slog::join_probe<2,1>(lst_lenindex268, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m283) {
          u64 v_c89 = m283[1];
          slog::join_probe<2,1>(lst_len_ansindex269, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m284) {
            u64 v_c86 = m284[1];
            slog::join_probe<2,1>(ol_fromlstindex270, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m285) {
              u64 v_c90 = m285[1];
              slog::join_probe<2,1>(ol_fromlst_ansindex271, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m286) {
                u64 v_c13 = m286[1];
                ++_fires;
                slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:49", "all:seed", _fires);
  
      if (!_done)
      {
        ReadTask272* _cont = new ReadTask272(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask272(db,b), true);
  // (crule (pre (let __trid9gZZ415 const58bedc2e3ff72fba5236f715) (let __trel8oDC416 constb2879a30c6ed138226ee848f) (let __tcol1rcT417 const5feceb66ffc86f38d952786c)) (scan $sup59985x37x0x0x0 __d0 x xs) (body) (head (tycheck xs (accept (struct ccons) (struct _enum)) __trid9gZZ415 __trel8oDC416 __tcol1rcT417 (1 2 3 4 0)) (mkstruct ol_len (1 0) __3Ovx414 xs)) list-cons.slog:38 #f)
  class ReadTask289 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid288;  u32 sid287;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("ol_len");
      outer_rel = db->getRelation("$sup59985x37x0x0x0");
      sid288 = db->getRelation("_enum")->getStructId();
      sid287 = db->getRelation("ccons")->getStructId();
  
    }
    ReadTask289(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const58bedc2e3ff72fba5236f715;
      u64 v_c92 = v_constb2879a30c6ed138226ee848f;
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid287 || decode_struct_id(v_c3) == sid288))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c91, v_c92, v_c93, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:38", "delta:$sup59985x37x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask289* _cont = new ReadTask289(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask289(db,b), false);
  // (crule (pre) (scan type_mismatch __erre0azz850 __errf0WTr851 __errf1qqD852 __errf4oj5853 __errf7Ubn854) (body) (head (emit error (0) __erre0azz850)) <internal>:1 #f)
  class ReadTask290 : public slog::Task
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
      std::vector<u16> ord291({0});
      slog::Relation* readrel292 = db->getRelation("error");
      head_index[0] = readrel292->getIndex(ord291, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask290(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c94 = _t[0];
        u64 v_c95 = _t[1];
        u64 v_c96 = _t[2];
        u64 v_c97 = _t[3];
        u64 v_c98 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c94}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask290* _cont = new ReadTask290(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask290(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre8FOo855 __errf1Vni856 __errf5Lys857 __errf4fZm858 __errf2EQY859) (body) (head (emit error (0) __erre8FOo855)) <internal>:1 #f)
  class ReadTask293 : public slog::Task
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
      std::vector<u16> ord294({0});
      slog::Relation* readrel295 = db->getRelation("error");
      head_index[0] = readrel295->getIndex(ord294, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask293(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c99 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c101 = _t[2];
        u64 v_c102 = _t[3];
        u64 v_c103 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c99}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask293* _cont = new ReadTask293(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask293(db,b), false);
  // (crule (pre (let __trid7Xxy344 const20f7f401d42560fee602a8bd) (let __trel4qn2345 const7d24ae77b98941e042da3f94) (let __tcol46MR346 const5feceb66ffc86f38d952786c) (let __tconst14S350 const6b86b273ff34fce19d6b804e)) (scan $sup59985x27x0x0x0 __d0 n x xs) (body (let __t45JF51 (_0002d n __tconst14S350))) (head (tycheck xs (accept (struct ccons) (struct _enum)) __trid7Xxy344 __trel4qn2345 __tcol46MR346 (1 2 3 4 0)) (emit-temp temp0U9L863 __t45JF51 xs)) list-cons.slog:28 #f)
  class ReadTask298 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid297;  u32 sid296;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp0U9L863");
      outer_rel = db->getRelation("$sup59985x27x0x0x0");
      sid297 = db->getRelation("_enum")->getStructId();
      sid296 = db->getRelation("ccons")->getStructId();
  
    }
    ReadTask298(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c104 = v_const20f7f401d42560fee602a8bd;
      u64 v_c105 = v_const7d24ae77b98941e042da3f94;
      u64 v_c106 = v_const5feceb66ffc86f38d952786c;
      u64 v_c107 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c86 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c88 = _prim__0002d(db, v_c86, v_c107);
        if (v_c88 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:28"); return; }
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid296 || decode_struct_id(v_c3) == sid297))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c104, v_c105, v_c106, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<2>(head_rel[1], newbatch[1], std::array<u64,2>{v_c88, v_c3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:28", "delta:$sup59985x27x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask298* _cont = new ReadTask298(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask298(db,b), false);
  // (crule (pre (let __trid0FN0377 const0c81821545944b087b718eeb) (let __trel3i0N378 consta7c87b54a14930acc837ba7c) (let __tcol2DXv379 const5feceb66ffc86f38d952786c)) (scan $sup59985x17x0x0x0 __d0 x xs) (body) (head (tycheck xs (accept (struct ccons) (struct _enum)) __trid0FN0377 __trel3i0N378 __tcol2DXv379 (1 2 3 4 0)) (mkstruct ol_tolst (1 0) __3YZu376 xs)) list-cons.slog:18 #f)
  class ReadTask301 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid300;  u32 sid299;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("ol_tolst");
      outer_rel = db->getRelation("$sup59985x17x0x0x0");
      sid300 = db->getRelation("_enum")->getStructId();
      sid299 = db->getRelation("ccons")->getStructId();
  
    }
    ReadTask301(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_const0c81821545944b087b718eeb;
      u64 v_c109 = v_consta7c87b54a14930acc837ba7c;
      u64 v_c110 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid299 || decode_struct_id(v_c3) == sid300))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c108, v_c109, v_c110, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:18", "delta:$sup59985x17x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask301* _cont = new ReadTask301(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask301(db,b), false);
  // (crule (pre (let __tconst60Bl358 const9ac63e4426dab2edcc97bcf7)) (probe _enum (1 0) 1 __tconst60Bl358 __t6FPX122) (body (join ol_rev_acc (1 2 0) 1 __t6FPX122 acc __t0gmU123)) (head (emit ol_rev_acc_ans (0 1) __t0gmU123 acc)) list-cons.slog:53 #f)
  class ReadTask303 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** ol_rev_accindex302;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_rev_acc_ans");
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("ol_rev_acc_ans");
      head_index[0] = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({1, 0});
      slog::Relation* readrel307 = db->getRelation("_enum");
      driver_index = readrel307->getIndex(ord306, true);
      std::vector<u16> ord308({1, 2, 0});
      slog::Relation* readrel309 = db->getRelation("ol_rev_acc");
      ol_rev_accindex302 = readrel309->getIndex(ord308, false);
  
    }
    ReadTask303(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c111 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c111, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m310) {
        u64 v_c112 = m310[1];
        if (buckethash(v_c112) != bucket) return;
        slog::join_probe<3,1>(ol_rev_accindex302, std::array<u64,3>{v_c112, 0, 0}, [&](const std::array<u64,3>& m311) {
          u64 v_c50 = m311[1]; u64 v_c113 = m311[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c113, v_c50}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:53", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask303* _cont = new ReadTask303(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask303(db,b), true);
  s->addReadRel("$sup59985x17x0x0x0");
  s->addReadRel("$sup59985x27x0x0x0");
  s->addReadRel("$sup59985x32x0x0x0");
  s->addReadRel("$sup59985x37x0x0x0");
  s->addReadRel("$sup59985x48x0x0x0");
  s->addReadRel("$sup76318x27x0x0x0");
  s->addReadRel("$sup76318x33x0x0x0");
  s->addReadRel("$sup76318x38x0x0x0");
  s->addReadRel("$sup76318x43x0x0x0");
  s->addReadRel("$sup76318x53x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("ccons");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("lst_absent");
  s->addReadRel("lst_absent_ans");
  s->addReadRel("lst_append");
  s->addReadRel("lst_append_ans");
  s->addReadRel("lst_len");
  s->addReadRel("lst_len_ans");
  s->addReadRel("lst_member");
  s->addReadRel("lst_member_ans");
  s->addReadRel("lst_ref");
  s->addReadRel("lst_ref_ans");
  s->addReadRel("lst_take");
  s->addReadRel("lst_take_ans");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("ol_absent");
  s->addReadRel("ol_append");
  s->addReadRel("ol_append_ans");
  s->addReadRel("ol_fromlst");
  s->addReadRel("ol_fromlst_ans");
  s->addReadRel("ol_len");
  s->addReadRel("ol_member");
  s->addReadRel("ol_ref");
  s->addReadRel("ol_rev_acc");
  s->addReadRel("ol_rev_acc_ans");
  s->addReadRel("ol_take");
  s->addReadRel("ol_take_ans");
  s->addReadRel("ol_tolst");
  s->addReadRel("probe");
  s->addReadRel("seed");
  s->addReadRel("temp0U9L863");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$sup59985x17x0x0x0");
  s->addDynamicRel("$sup59985x27x0x0x0");
  s->addDynamicRel("$sup59985x32x0x0x0");
  s->addDynamicRel("$sup59985x37x0x0x0");
  s->addDynamicRel("$sup59985x48x0x0x0");
  s->addDynamicRel("append_ok");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("ol_absent");
  s->addDynamicRel("ol_len");
  s->addDynamicRel("ol_member");
  s->addDynamicRel("ol_ref");
  s->addDynamicRel("ol_rev_acc_ans");
  s->addDynamicRel("ol_tolst");
  s->addDynamicRel("take_ok");
  s->addDynamicRel("temp0U9L863");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("ol_rev_acc_ans");
  d->push(s);
  d->continueRun();
}

