
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const4fc82b26aecb47d2868c4efb;
u64 v_const6b51d431df5d7f141cbececc;
u64 v_const3fdba35f04dc8c462986c992;
u64 v_const8527a891e224136950ff32ca;
u64 v_conste629fa6598d732768f7c726b;
u64 v_constb17ef6d19c7a5b1ee83b907c;
u64 v_const5feceb66ffc86f38d952786c;
u64 v_constb8736b999909049671d0ea07;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4523540f1504cd17100c4835;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4ec9599fc203d176a301536c;
u64 v_constc100f95c1913f9c72fc1f4ef;
u64 v_constac8d8342bbb2362d13f0a559;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const9400f1b21cb527d7fa3d3eab;
u64 v_const8c1f1046219ddd216a023f79;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constf5ca38f748a1d6eaf726b8a4;
u64 v_constef2d127de37b942baad06145;
u64 v_const6f4b6612125fb3a0daecd279;
u64 v_conste7f6c011776e8db7cd330b54;
u64 v_const785f3ec7eb32f30b90cd0fcf;
u64 v_const2c624232cdd221771294dfbb;
u64 v_constd59eced1ded07f84c145592f;
u64 v_const19581e27de7ced00ff1ce50b;
u64 v_const9ac63e4426dab2edcc97bcf7;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("68c2e277");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const4fc82b26aecb47d2868c4efb = s32_encode(11);
  v_const6b51d431df5d7f141cbececc = s32_encode(12);
  v_const3fdba35f04dc8c462986c992 = s32_encode(13);
  v_const8527a891e224136950ff32ca = s32_encode(14);
  v_conste629fa6598d732768f7c726b = s32_encode(15);
  v_constb17ef6d19c7a5b1ee83b907c = s32_encode(16);
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_constb8736b999909049671d0ea07 = float_encode(2.5);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4523540f1504cd17100c4835 = s32_encode(17);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4ec9599fc203d176a301536c = s32_encode(18);
  v_constc100f95c1913f9c72fc1f4ef = db->encodeString("b");
  v_constac8d8342bbb2362d13f0a559 = db->encodeString("a");
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const9400f1b21cb527d7fa3d3eab = s32_encode(19);
  v_const8c1f1046219ddd216a023f79 = s32_encode(99);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constf5ca38f748a1d6eaf726b8a4 = s32_encode(20);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const6f4b6612125fb3a0daecd279 = s32_encode(21);
  v_conste7f6c011776e8db7cd330b54 = s32_encode(6);
  v_const785f3ec7eb32f30b90cd0fcf = s32_encode(22);
  v_const2c624232cdd221771294dfbb = s32_encode(8);
  v_constd59eced1ded07f84c145592f = s32_encode(40);
  v_const19581e27de7ced00ff1ce50b = s32_encode(9);
  v_const9ac63e4426dab2edcc97bcf7 = db->encodeString("cnil");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord84({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord85({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord86({1, 2, 0});
    
    r->addIndex<3>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord87({0, 1, 2});
    
    r->addIndex<3>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp9P5L492");
  if (r == 0) db->addTempRelation("temp9P5L492", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp9II1508");
  if (r == 0) db->addTempRelation("temp9II1508", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8wf8507");
  if (r == 0) db->addTempRelation("temp8wf8507", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8BRz485");
  if (r == 0) db->addTempRelation("temp8BRz485", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7UhH509");
  if (r == 0) db->addTempRelation("temp7UhH509", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7JIl491");
  if (r == 0) db->addTempRelation("temp7JIl491", 7);
  else if (r->getArity() != 7) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6vgA504");
  if (r == 0) db->addTempRelation("temp6vgA504", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp67UX488");
  if (r == 0) db->addTempRelation("temp67UX488", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp62j7489");
  if (r == 0) db->addTempRelation("temp62j7489", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp62Y4490");
  if (r == 0) db->addTempRelation("temp62Y4490", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5WL2496");
  if (r == 0) db->addTempRelation("temp5WL2496", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5HCD487");
  if (r == 0) db->addTempRelation("temp5HCD487", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4wIF493");
  if (r == 0) db->addTempRelation("temp4wIF493", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4ZjV499");
  if (r == 0) db->addTempRelation("temp4ZjV499", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4Qfu486");
  if (r == 0) db->addTempRelation("temp4Qfu486", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4P8M501");
  if (r == 0) db->addTempRelation("temp4P8M501", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4L8p502");
  if (r == 0) db->addTempRelation("temp4L8p502", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3vdp510");
  if (r == 0) db->addTempRelation("temp3vdp510", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3Ykl497");
  if (r == 0) db->addTempRelation("temp3Ykl497", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3VcG495");
  if (r == 0) db->addTempRelation("temp3VcG495", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3Pnb498");
  if (r == 0) db->addTempRelation("temp3Pnb498", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3FcD500");
  if (r == 0) db->addTempRelation("temp3FcD500", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2V3n505");
  if (r == 0) db->addTempRelation("temp2V3n505", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp26JV506");
  if (r == 0) db->addTempRelation("temp26JV506", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1v37494");
  if (r == 0) db->addTempRelation("temp1v37494", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1IDy503");
  if (r == 0) db->addTempRelation("temp1IDy503", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("take_ok");
  if (r == 0) db->addRelation("take_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("take_ok");
      std::vector<u16> ord88({0, 1});
    
    r->addIndex<2>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("take_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord89({1, 2, 0});
    
    r->addIndex<3>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord90({0, 1, 2});
    
    r->addIndex<3>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("seed");
  if (r == 0) db->addRelation("seed", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("seed");
      std::vector<u16> ord91({0, 1});
    
    r->addIndex<2>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("seed"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("rev_ok");
  if (r == 0) db->addRelation("rev_ok", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("rev_ok");
      std::vector<u16> ord92({0});
    
    r->addIndex<1>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("rev_ok"), std::array<u16,1>{0}, b));
  r = db->getRelation("ref_ok");
  if (r == 0) db->addRelation("ref_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref_ok");
      std::vector<u16> ord93({0, 1});
    
    r->addIndex<2>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ref_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("probe");
  if (r == 0) db->addRelation("probe", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("probe");
      std::vector<u16> ord94({0});
    
    r->addIndex<1>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("probe"), std::array<u16,1>{0}, b));
  r = db->getRelation("ol_tolst_ans");
  if (r == 0) db->addRelation("ol_tolst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst_ans");
      std::vector<u16> ord95({0, 1});
    
    r->addIndex<2>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_tolst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_tolst");
  if (r == 0) db->addStruct("ol_tolst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_tolst");
      std::vector<u16> ord96({1, 0});
    
    r->addIndex<2>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord97({0, 1});
    
    r->addIndex<2>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_tolst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_take_ans");
  if (r == 0) db->addRelation("ol_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take_ans");
      std::vector<u16> ord98({0, 1});
    
    r->addIndex<2>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_take");
  if (r == 0) db->addStruct("ol_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_take");
      std::vector<u16> ord99({1, 2, 0});
    
    r->addIndex<3>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord100({0, 1, 2});
    
    r->addIndex<3>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_rev_ans");
  if (r == 0) db->addRelation("ol_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_ans");
      std::vector<u16> ord101({0, 1});
    
    r->addIndex<2>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc_ans");
  if (r == 0) db->addRelation("ol_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc_ans");
      std::vector<u16> ord102({0, 1});
    
    r->addIndex<2>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_rev_acc");
  if (r == 0) db->addStruct("ol_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev_acc");
      std::vector<u16> ord103({1, 2, 0});
    
    r->addIndex<3>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord104({0, 1, 2});
    
    r->addIndex<3>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_rev");
  if (r == 0) db->addStruct("ol_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_rev");
      std::vector<u16> ord105({1, 0});
    
    r->addIndex<2>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord106({0, 1});
    
    r->addIndex<2>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_ref_ans");
  if (r == 0) db->addRelation("ol_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref_ans");
      std::vector<u16> ord107({0, 1});
    
    r->addIndex<2>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_ref");
  if (r == 0) db->addStruct("ol_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_ref");
      std::vector<u16> ord108({1, 2, 0});
    
    r->addIndex<3>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord109({0, 1, 2});
    
    r->addIndex<3>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_member_ans");
  if (r == 0) db->addRelation("ol_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member_ans");
      std::vector<u16> ord110({0, 1});
    
    r->addIndex<2>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_member");
  if (r == 0) db->addStruct("ol_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_member");
      std::vector<u16> ord111({1, 2, 0});
    
    r->addIndex<3>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord112({0, 1, 2});
    
    r->addIndex<3>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_len_ans");
  if (r == 0) db->addRelation("ol_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len_ans");
      std::vector<u16> ord113({0, 1});
    
    r->addIndex<2>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_len");
  if (r == 0) db->addStruct("ol_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_len");
      std::vector<u16> ord114({1, 0});
    
    r->addIndex<2>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord115({0, 1});
    
    r->addIndex<2>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_fromlst_ans");
  if (r == 0) db->addRelation("ol_fromlst_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord116({0, 1});
    
    r->addIndex<2>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_fromlst_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_fromlst");
  if (r == 0) db->addStruct("ol_fromlst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_fromlst");
      std::vector<u16> ord117({1, 0});
    
    r->addIndex<2>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord118({0, 1});
    
    r->addIndex<2>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ol_fromlst"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ol_append_ans");
  if (r == 0) db->addRelation("ol_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append_ans");
      std::vector<u16> ord119({0, 1});
    
    r->addIndex<2>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_append");
  if (r == 0) db->addStruct("ol_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_append");
      std::vector<u16> ord120({1, 2, 0});
    
    r->addIndex<3>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord121({0, 1, 2});
    
    r->addIndex<3>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ol_absent_ans");
  if (r == 0) db->addRelation("ol_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent_ans");
      std::vector<u16> ord122({0, 1});
    
    r->addIndex<2>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ol_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ol_absent");
  if (r == 0) db->addStruct("ol_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ol_absent");
      std::vector<u16> ord123({1, 2, 0});
    
    r->addIndex<3>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord124({0, 1, 2});
    
    r->addIndex<3>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ol_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("needle");
  if (r == 0) db->addRelation("needle", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("needle");
      std::vector<u16> ord125({0});
    
    r->addIndex<1>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("needle"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord126({1, 2, 3, 0});
    
    r->addIndex<4>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord127({0, 1, 2, 3});
    
    r->addIndex<4>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord128({1, 2, 0});
    
    r->addIndex<3>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord129({0, 1, 2});
    
    r->addIndex<3>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord130({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord131({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord132({1, 2, 0});
    
    r->addIndex<3>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord133({0, 1, 2});
    
    r->addIndex<3>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("member_ok");
  if (r == 0) db->addRelation("member_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("member_ok");
      std::vector<u16> ord134({0, 1});
    
    r->addIndex<2>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("member_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord135({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord136({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lst_take_ans");
  if (r == 0) db->addRelation("lst_take_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take_ans");
      std::vector<u16> ord137({0, 1});
    
    r->addIndex<2>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_take_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_take");
  if (r == 0) db->addStruct("lst_take", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_take");
      std::vector<u16> ord138({1, 2, 0});
    
    r->addIndex<3>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord139({0, 1, 2});
    
    r->addIndex<3>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_take"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev_ans");
  if (r == 0) db->addRelation("lst_rev_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_ans");
      std::vector<u16> ord140({0, 1});
    
    r->addIndex<2>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc_ans");
  if (r == 0) db->addRelation("lst_rev_acc_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc_ans");
      std::vector<u16> ord141({0, 1});
    
    r->addIndex<2>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_rev_acc_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_rev_acc");
  if (r == 0) db->addStruct("lst_rev_acc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev_acc");
      std::vector<u16> ord142({1, 2, 0});
    
    r->addIndex<3>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord143({0, 1, 2});
    
    r->addIndex<3>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_rev_acc"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_rev");
  if (r == 0) db->addStruct("lst_rev", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_rev");
      std::vector<u16> ord144({1, 0});
    
    r->addIndex<2>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord145({0, 1});
    
    r->addIndex<2>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_rev"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_ref_ans");
  if (r == 0) db->addRelation("lst_ref_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref_ans");
      std::vector<u16> ord146({0, 1});
    
    r->addIndex<2>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_ref_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_ref");
  if (r == 0) db->addStruct("lst_ref", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_ref");
      std::vector<u16> ord147({1, 2, 0});
    
    r->addIndex<3>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord148({0, 1, 2});
    
    r->addIndex<3>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_ref"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_member_ans");
  if (r == 0) db->addRelation("lst_member_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member_ans");
      std::vector<u16> ord149({0, 1});
    
    r->addIndex<2>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_member_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_member");
  if (r == 0) db->addStruct("lst_member", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_member");
      std::vector<u16> ord150({1, 2, 0});
    
    r->addIndex<3>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord151({0, 1, 2});
    
    r->addIndex<3>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_member"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_len_ans");
  if (r == 0) db->addRelation("lst_len_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len_ans");
      std::vector<u16> ord152({0, 1});
    
    r->addIndex<2>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_len_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_len");
  if (r == 0) db->addStruct("lst_len", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_len");
      std::vector<u16> ord153({1, 0});
    
    r->addIndex<2>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord154({0, 1});
    
    r->addIndex<2>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lst_len"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lst_append_ans");
  if (r == 0) db->addRelation("lst_append_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append_ans");
      std::vector<u16> ord155({0, 1});
    
    r->addIndex<2>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_append_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_append");
  if (r == 0) db->addStruct("lst_append", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_append");
      std::vector<u16> ord156({1, 2, 0});
    
    r->addIndex<3>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord157({0, 1, 2});
    
    r->addIndex<3>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_append"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lst_absent_ans");
  if (r == 0) db->addRelation("lst_absent_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent_ans");
      std::vector<u16> ord158({0, 1});
    
    r->addIndex<2>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("lst_absent_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("lst_absent");
  if (r == 0) db->addStruct("lst_absent", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lst_absent");
      std::vector<u16> ord159({1, 2, 0});
    
    r->addIndex<3>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord160({0, 1, 2});
    
    r->addIndex<3>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lst_absent"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("len_ok");
  if (r == 0) db->addRelation("len_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("len_ok");
      std::vector<u16> ord161({0, 1});
    
    r->addIndex<2>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("len_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord162({1, 2, 3, 0});
    
    r->addIndex<4>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord163({0, 1, 2, 3});
    
    r->addIndex<4>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord164({0});
    
    r->addIndex<1>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord165({1, 2, 0});
    
    r->addIndex<3>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord166({0, 1, 2});
    
    r->addIndex<3>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ccons");
  if (r == 0) db->addStruct("ccons", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ccons");
      std::vector<u16> ord167({1, 2, 0});
    
    r->addIndex<3>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord168({0, 1, 2});
    
    r->addIndex<3>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ccons"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("append_ok");
  if (r == 0) db->addRelation("append_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("append_ok");
      std::vector<u16> ord169({0, 1});
    
    r->addIndex<2>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("append_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("absent_ok");
  if (r == 0) db->addRelation("absent_ok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("absent_ok");
      std::vector<u16> ord170({0, 1});
    
    r->addIndex<2>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("absent_ok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord171({1, 0});
    
    r->addIndex<2>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord172({0, 1});
    
    r->addIndex<2>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup76318x53x0x0x0");
  if (r == 0) db->addRelation("$sup76318x53x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x53x0x0x0");
      std::vector<u16> ord173({0, 1, 2});
    
    r->addIndex<3>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x53x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x43x0x0x0");
  if (r == 0) db->addRelation("$sup76318x43x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x43x0x0x0");
      std::vector<u16> ord174({0, 1, 2});
    
    r->addIndex<3>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x43x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x38x0x0x0");
  if (r == 0) db->addRelation("$sup76318x38x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x38x0x0x0");
      std::vector<u16> ord175({0, 1, 2});
    
    r->addIndex<3>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x38x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x33x0x0x0");
  if (r == 0) db->addRelation("$sup76318x33x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x33x0x0x0");
      std::vector<u16> ord176({0, 1, 2});
    
    r->addIndex<3>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup76318x33x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup76318x27x0x0x0");
  if (r == 0) db->addRelation("$sup76318x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup76318x27x0x0x0");
      std::vector<u16> ord177({0, 1, 2, 3});
    
    r->addIndex<4>(ord177, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup76318x27x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x48x0x0x0");
  if (r == 0) db->addRelation("$sup59985x48x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x48x0x0x0");
      std::vector<u16> ord178({0, 1, 2, 3});
    
    r->addIndex<4>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x48x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x43x0x0x0");
  if (r == 0) db->addRelation("$sup59985x43x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x43x0x0x0");
      std::vector<u16> ord179({0, 1, 2, 3});
    
    r->addIndex<4>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x43x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x37x0x0x0");
  if (r == 0) db->addRelation("$sup59985x37x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x37x0x0x0");
      std::vector<u16> ord180({0, 1, 2});
    
    r->addIndex<3>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x37x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup59985x32x0x0x0");
  if (r == 0) db->addRelation("$sup59985x32x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x32x0x0x0");
      std::vector<u16> ord181({0, 1, 2, 3});
    
    r->addIndex<4>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x32x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x27x0x0x0");
  if (r == 0) db->addRelation("$sup59985x27x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x27x0x0x0");
      std::vector<u16> ord182({0, 1, 2, 3});
    
    r->addIndex<4>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x27x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x22x0x0x0");
  if (r == 0) db->addRelation("$sup59985x22x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x22x0x0x0");
      std::vector<u16> ord183({0, 1, 2, 3});
    
    r->addIndex<4>(ord183, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x22x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup59985x17x0x0x0");
  if (r == 0) db->addRelation("$sup59985x17x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x17x0x0x0");
      std::vector<u16> ord184({0, 1, 2});
    
    r->addIndex<3>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup59985x17x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup59985x12x0x0x0");
  if (r == 0) db->addRelation("$sup59985x12x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup59985x12x0x0x0");
      std::vector<u16> ord185({0, 1, 2, 3});
    
    r->addIndex<4>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup59985x12x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord186({0, 1, 2});
    
    r->addIndex<3>(ord186, false);
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
  // (crule (pre) (scan nan_result __erre7a4T465 __errf6473466 __errf5B43467 __errf0B49468) (body) (head (emit error (0) __erre7a4T465)) <internal>:1 #f)
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
      outer_rel = db->getRelation("nan_result");
  
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst5XJ6167 const2c624232cdd221771294dfbb) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp3VcG495 __t1D24182) (body (let __t78uK183 (lpush __t1D24182 __tconst5XJ6167))) (head (emit-temp temp5WL2496 __t78uK183)) seq_oracle.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp5WL2496");
      outer_rel = db->getRelation("temp3VcG495");
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const2c624232cdd221771294dfbb;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        u64 v_c21 = _prim_lpush(db, v_c20, v_c18);
        if (v_c21 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c21});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp3VcG495", _fires);
  
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp4ZjV499 __t7KMq186) (body (let __t1dTM187 (lpush __t7KMq186 __tconst6Gdj163))) (head (emit-temp temp3FcD500 __t1dTM187)) seq_oracle.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp3FcD500");
      outer_rel = db->getRelation("temp4ZjV499");
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        u64 v_c23 = _prim_lpush(db, v_c22, v_c14);
        if (v_c23 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp4ZjV499", _fires);
  
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
      s->addTask(phase_read, new ReadTask4(db,b), false);
  // (crule (pre (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp3vdp510 __t3Aj6197) (body) (head (emit seed (0 1) __tconst65Mz198 __t3Aj6197)) seq_oracle.slog:13 #f)
  class ReadTask5 : public slog::Task
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
      head_rel[0] = db->getRelation("seed");
      std::vector<u16> ord6({0, 1});
      slog::Relation* readrel7 = db->getRelation("seed");
      head_index[0] = readrel7->getIndex(ord6, false);
      outer_rel = db->getRelation("temp3vdp510");
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c24 = _t[0];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c19, v_c24}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp3vdp510", _fires);
  
      if (!_done)
      {
        ReadTask5* _cont = new ReadTask5(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), false);
  // (crule (pre (let __tconst3Lgs127 constd4735e3a265e16eee03f5971) (let __tconst0YKo128 const6b86b273ff34fce19d6b804e)) (scan temp8BRz485 __t6G0j129) (body (let __t06gU130 (lpush __t6G0j129 __tconst0YKo128))) (head (emit-temp temp4Qfu486 __t06gU130)) seq_oracle.slog:25 #f)
  class ReadTask8 : public slog::Task
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
      head_rel[0] = db->getRelation("temp4Qfu486");
      outer_rel = db->getRelation("temp8BRz485");
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_constd4735e3a265e16eee03f5971;
      u64 v_c26 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c27 = _t[0];
        u64 v_c28 = _prim_lpush(db, v_c27, v_c26);
        if (v_c28 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:25"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c28});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:25", "delta:temp8BRz485", _fires);
  
      if (!_done)
      {
        ReadTask8* _cont = new ReadTask8(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask8(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre63XB482 __errf0FZJ483 __errf9Cj0484) (body) (head (emit error (0) __erre63XB482)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
        u64 v_c29 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c31 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c29}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp26JV506 __t6DUa193) (body (let __t23s0194 (lpush __t6DUa193 __tconst1IHf156))) (head (emit-temp temp8wf8507 __t23s0194)) seq_oracle.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp8wf8507");
      outer_rel = db->getRelation("temp26JV506");
  
    }
    ReadTask12(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c32 = _t[0];
        u64 v_c33 = _prim_lpush(db, v_c32, v_c7);
        if (v_c33 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c33});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp26JV506", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre6trs461 __errf3Me5462 __errf8vyx463 __errf0fUd464) (body) (head (emit error (0) __erre6trs461)) <internal>:1 #f)
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
      outer_rel = db->getRelation("int_overflow");
  
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
        u64 v_c34 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c37 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c34}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst5XJ6167 const2c624232cdd221771294dfbb) (let __tconst4JN7168 const7902699be42c8a8e46fbbb45) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f) (let __tconst62sx203 constac8d8342bbb2362d13f0a559) (let __tconst7QKk210 constef2d127de37b942baad06145) (let __tconst5EkG230 conste7f6c011776e8db7cd330b54)) (scan temp9P5L492 __t0w43179 __t2xbR227 __t4Gf1224 __t5GeB208 __t7xqF143) (body (let __t8f98180 (lpush __t0w43179 __tconst7QKk210)) (let __t9hCR209 (lpush __t5GeB208 __tconst62sx203)) (let __t6tQu228 (lpush __t2xbR227 __t7xqF143))) (head (emit-temp temp4wIF493 __t4Gf1224 __t6tQu228 __t8f98180 __t9hCR209)) seq_oracle.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp4wIF493");
      outer_rel = db->getRelation("temp9P5L492");
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const2c624232cdd221771294dfbb;
      u64 v_c38 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c39 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c40 = v_constef2d127de37b942baad06145;
      u64 v_c41 = v_conste7f6c011776e8db7cd330b54;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c42 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c44 = _t[2];
        u64 v_c45 = _t[3];
        u64 v_c46 = _t[4];
        u64 v_c47 = _prim_lpush(db, v_c42, v_c40);
        if (v_c47 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c48 = _prim_lpush(db, v_c45, v_c39);
        if (v_c48 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c49 = _prim_lpush(db, v_c43, v_c46);
        if (v_c49 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c44, v_c49, v_c47, v_c48});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp9P5L492", _fires);
  
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp8wf8507 __t23s0194) (body (let __t0Sw6195 (lpush __t23s0194 __tconst5CLm155))) (head (emit-temp temp9II1508 __t0Sw6195)) seq_oracle.slog:13 #f)
  class ReadTask17 : public slog::Task
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
      head_rel[0] = db->getRelation("temp9II1508");
      outer_rel = db->getRelation("temp8wf8507");
  
    }
    ReadTask17(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c33 = _t[0];
        u64 v_c50 = _prim_lpush(db, v_c33, v_c6);
        if (v_c50 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c50});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp8wf8507", _fires);
  
      if (!_done)
      {
        ReadTask17* _cont = new ReadTask17(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask17(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp1IDy503 __t8gHB190) (body (let __t4sr5191 (lpush __t8gHB190 __tconst25c1159))) (head (emit-temp temp6vgA504 __t4sr5191)) seq_oracle.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp6vgA504");
      outer_rel = db->getRelation("temp1IDy503");
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c51 = _t[0];
        u64 v_c52 = _prim_lpush(db, v_c51, v_c10);
        if (v_c52 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c52});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp1IDy503", _fires);
  
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp3Pnb498 __t38yp185) (body (let __t7KMq186 (lpush __t38yp185 __tconst9Wln164))) (head (emit-temp temp4ZjV499 __t7KMq186)) seq_oracle.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp4ZjV499");
      outer_rel = db->getRelation("temp3Pnb498");
  
    }
    ReadTask19(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c53 = _t[0];
        u64 v_c22 = _prim_lpush(db, v_c53, v_c15);
        if (v_c22 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c22});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp3Pnb498", _fires);
  
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst5XJ6167 const2c624232cdd221771294dfbb) (let __tconst4JN7168 const7902699be42c8a8e46fbbb45) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f) (let __tconst7QKk210 constef2d127de37b942baad06145) (let __tconst5EkG230 conste7f6c011776e8db7cd330b54)) (scan temp4wIF493 __t4Gf1224 __t6tQu228 __t8f98180 __t9hCR209) (body (let __t54ug181 (lpush __t8f98180 __tconst5EkG230)) (let __t8doc229 (lpush __t6tQu228 __t4Gf1224))) (head (emit-temp temp1v37494 __t54ug181 __t8doc229) (emit seed (0 1) __tconst7QKk210 __t9hCR209)) seq_oracle.slog:13 #f)
  class ReadTask20 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1v37494");
      head_rel[1] = db->getRelation("seed");
      std::vector<u16> ord21({0, 1});
      slog::Relation* readrel22 = db->getRelation("seed");
      head_index[1] = readrel22->getIndex(ord21, false);
      outer_rel = db->getRelation("temp4wIF493");
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const2c624232cdd221771294dfbb;
      u64 v_c38 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c40 = v_constef2d127de37b942baad06145;
      u64 v_c41 = v_conste7f6c011776e8db7cd330b54;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c49 = _t[1];
        u64 v_c47 = _t[2];
        u64 v_c48 = _t[3];
        u64 v_c54 = _prim_lpush(db, v_c47, v_c41);
        if (v_c54 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c55 = _prim_lpush(db, v_c49, v_c44);
        if (v_c55 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c54, v_c55});
        slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c40, v_c48}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp4wIF493", _fires);
  
      if (!_done)
      {
        ReadTask20* _cont = new ReadTask20(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask20(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp6vgA504 __t4sr5191) (body (let __t8zRv192 (lpush __t4sr5191 __tconst8Mpx158))) (head (emit-temp temp2V3n505 __t8zRv192)) seq_oracle.slog:13 #f)
  class ReadTask23 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2V3n505");
      outer_rel = db->getRelation("temp6vgA504");
  
    }
    ReadTask23(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c52 = _t[0];
        u64 v_c56 = _prim_lpush(db, v_c52, v_c9);
        if (v_c56 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c56});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp6vgA504", _fires);
  
      if (!_done)
      {
        ReadTask23* _cont = new ReadTask23(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask23(db,b), false);
  // (crule (pre) (scan type_mismatch __erre9Vqu472 __errf1KE6473 __errf4bCy474 __errf2oki475 __errf3lET476) (body) (head (emit error (0) __erre9Vqu472)) <internal>:1 #f)
  class ReadTask24 : public slog::Task
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
      std::vector<u16> ord25({0});
      slog::Relation* readrel26 = db->getRelation("error");
      head_index[0] = readrel26->getIndex(ord25, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask24(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp5WL2496 __t78uK183) (body (let __t4YNT184 (lpush __t78uK183 __tconst9c8T166))) (head (emit-temp temp3Ykl497 __t4YNT184)) seq_oracle.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp3Ykl497");
      outer_rel = db->getRelation("temp5WL2496");
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c62 = _prim_lpush(db, v_c21, v_c17);
        if (v_c62 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c62});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp5WL2496", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre5sOP455 __errf7PTg456 __errf1jKS457) (body) (head (emit error (0) __erre5sOP455)) <internal>:1 #f)
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
      outer_rel = db->getRelation("div_by_zero");
  
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
        u64 v_c63 = _t[0];
        u64 v_c64 = _t[1];
        u64 v_c65 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c63}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre) (scan temp5HCD487 __t8S8j131) (body) (head (emit needle (0) __t8S8j131)) seq_oracle.slog:25 #f)
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
      head_rel[0] = db->getRelation("needle");
      std::vector<u16> ord32({0});
      slog::Relation* readrel33 = db->getRelation("needle");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("temp5HCD487");
  
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
        u64 v_c66 = _t[0];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c66}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:25", "delta:temp5HCD487", _fires);
  
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
  // (crule (pre) (scan toint_range __erre4P3T469 __errf4zFV470 __errf2CAE471) (body) (head (emit error (0) __erre4P3T469)) <internal>:1 #f)
  class ReadTask34 : public slog::Task
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
      std::vector<u16> ord35({0});
      slog::Relation* readrel36 = db->getRelation("error");
      head_index[0] = readrel36->getIndex(ord35, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask34(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c67 = _t[0];
        u64 v_c68 = _t[1];
        u64 v_c69 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c67}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask34* _cont = new ReadTask34(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask34(db,b), false);
  // (crule (pre (let __tconst5nQx94 constd59eced1ded07f84c145592f) (let __tconst7lZb93 const6f4b6612125fb3a0daecd279) (let __tconst3hgi92 constef2d127de37b942baad06145) (let __tconst24bd91 constd4735e3a265e16eee03f5971) (let __tconst0epT90 const5feceb66ffc86f38d952786c)) (once) (body) (head (emit probe (0) __tconst5nQx94) (emit probe (0) __tconst7lZb93) (emit probe (0) __tconst3hgi92) (emit probe (0) __tconst24bd91) (emit probe (0) __tconst0epT90)) seq_oracle.slog:22 #f)
  class ReadTask37 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("probe");
      std::vector<u16> ord38({0});
      slog::Relation* readrel39 = db->getRelation("probe");
      head_index[0] = readrel39->getIndex(ord38, false);
      head_rel[1] = db->getRelation("probe");
      std::vector<u16> ord40({0});
      slog::Relation* readrel41 = db->getRelation("probe");
      head_index[1] = readrel41->getIndex(ord40, false);
      head_rel[2] = db->getRelation("probe");
      std::vector<u16> ord42({0});
      slog::Relation* readrel43 = db->getRelation("probe");
      head_index[2] = readrel43->getIndex(ord42, false);
      head_rel[3] = db->getRelation("probe");
      std::vector<u16> ord44({0});
      slog::Relation* readrel45 = db->getRelation("probe");
      head_index[3] = readrel45->getIndex(ord44, false);
      head_rel[4] = db->getRelation("probe");
      std::vector<u16> ord46({0});
      slog::Relation* readrel47 = db->getRelation("probe");
      head_index[4] = readrel47->getIndex(ord46, false);
  
    }
    ReadTask37(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c70 = v_constd59eced1ded07f84c145592f;
      u64 v_c71 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c72 = v_constef2d127de37b942baad06145;
      u64 v_c73 = v_constd4735e3a265e16eee03f5971;
      u64 v_c74 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c70}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c72}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[3], head_index[3], newbatch[3], std::array<u64,1>{v_c73}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[4], head_index[4], newbatch[4], std::array<u64,1>{v_c74}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:22", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask37(db,b), true);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst5XJ6167 const2c624232cdd221771294dfbb) (let __tconst4JN7168 const7902699be42c8a8e46fbbb45) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f) (let __tconst9tvM200 constb8736b999909049671d0ea07) (let __tconst3L5u201 constc100f95c1913f9c72fc1f4ef) (let __tconst62sx203 constac8d8342bbb2362d13f0a559) (let __tconst7QKk210 constef2d127de37b942baad06145) (let __tconst4IrW216 const4e07408562bedb8b60ce05c1) (let __tconst8BnD220 constd4735e3a265e16eee03f5971) (let __tconst7QpE221 const6b86b273ff34fce19d6b804e) (let __tconst5EkG230 conste7f6c011776e8db7cd330b54)) (scan temp67UX488 __t4KbT225) (body (let __t7xqF143 (lpush __t4KbT225 __tconst4IrW216)) (let __t3PAv151 (lpush __t4KbT225 __tconst7QKk210)) (let __t4Ykf176 (lpush __t4KbT225 __tconst7QpE221)) (let __t3DHo205 (lpush __t4KbT225 __tconst62sx203))) (head (emit-temp temp62j7489 __t3DHo205 __t3PAv151 __t4KbT225 __t4Ykf176 __t7xqF143) (emit seed (0 1) __tconst8BnD220 __t4KbT225)) seq_oracle.slog:13 #f)
  class ReadTask48 : public slog::Task
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
      head_rel[0] = db->getRelation("temp62j7489");
      head_rel[1] = db->getRelation("seed");
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("seed");
      head_index[1] = readrel50->getIndex(ord49, false);
      outer_rel = db->getRelation("temp67UX488");
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const2c624232cdd221771294dfbb;
      u64 v_c38 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c75 = v_constb8736b999909049671d0ea07;
      u64 v_c76 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c39 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c40 = v_constef2d127de37b942baad06145;
      u64 v_c77 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c78 = v_constd4735e3a265e16eee03f5971;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_conste7f6c011776e8db7cd330b54;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c80 = _t[0];
        u64 v_c46 = _prim_lpush(db, v_c80, v_c77);
        if (v_c46 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c81 = _prim_lpush(db, v_c80, v_c40);
        if (v_c81 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c82 = _prim_lpush(db, v_c80, v_c79);
        if (v_c82 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c83 = _prim_lpush(db, v_c80, v_c39);
        if (v_c83 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c83, v_c81, v_c80, v_c82, v_c46});
        slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c78, v_c80}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp67UX488", _fires);
  
      if (!_done)
      {
        ReadTask48* _cont = new ReadTask48(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask48(db,b), false);
  // (crule (pre (let __tconst1X23423 const9ac63e4426dab2edcc97bcf7)) (once) (body) (head (mkstruct _enum (1 0) __1oFP424 __tconst1X23423)) <internal>:1 #f)
  class ReadTask51 : public slog::Task
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
    ReadTask51(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c84 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c84}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask51(db,b), true);
  // (crule (pre) (scan mpz_overflow __erre0A32477 __errf0Pvj478 __errf9NlI479 __errf1ShU480 __errf9c0V481) (body) (head (emit error (0) __erre0A32477)) <internal>:1 #f)
  class ReadTask52 : public slog::Task
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
      std::vector<u16> ord53({0});
      slog::Relation* readrel54 = db->getRelation("error");
      head_index[0] = readrel54->getIndex(ord53, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask52(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c85 = _t[0];
        u64 v_c86 = _t[1];
        u64 v_c87 = _t[2];
        u64 v_c88 = _t[3];
        u64 v_c89 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c85}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask52* _cont = new ReadTask52(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask52(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp3Ykl497 __t4YNT184) (body (let __t38yp185 (lpush __t4YNT184 __tconst9uif165))) (head (emit-temp temp3Pnb498 __t38yp185)) seq_oracle.slog:13 #f)
  class ReadTask55 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3Pnb498");
      outer_rel = db->getRelation("temp3Ykl497");
  
    }
    ReadTask55(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c62 = _t[0];
        u64 v_c53 = _prim_lpush(db, v_c62, v_c16);
        if (v_c53 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c53});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp3Ykl497", _fires);
  
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
      s->addTask(phase_read, new ReadTask55(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst5XJ6167 const2c624232cdd221771294dfbb) (let __tconst4JN7168 const7902699be42c8a8e46fbbb45) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f) (let __tconst9tvM200 constb8736b999909049671d0ea07) (let __tconst62sx203 constac8d8342bbb2362d13f0a559) (let __tconst7QKk210 constef2d127de37b942baad06145) (let __tconst7QpE221 const6b86b273ff34fce19d6b804e) (let __tconst5EkG230 conste7f6c011776e8db7cd330b54)) (scan temp7JIl491 __t4Gf1224 __t4Hi3226 __t4KbT225 __t537F178 __t53GN145 __t7b8W207 __t7xqF143) (body (let __t0w43179 (lpush __t537F178 __tconst65Mz198)) (let __t5GeB208 (lpush __t7b8W207 __tconst9tvM200)) (let __t2xbR227 (lpush __t4Hi3226 __t4KbT225))) (head (emit-temp temp9P5L492 __t0w43179 __t2xbR227 __t4Gf1224 __t5GeB208 __t7xqF143) (emit seed (0 1) __tconst7QpE221 __t53GN145)) seq_oracle.slog:13 #f)
  class ReadTask56 : public slog::Task
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
      head_rel[0] = db->getRelation("temp9P5L492");
      head_rel[1] = db->getRelation("seed");
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("seed");
      head_index[1] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("temp7JIl491");
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const2c624232cdd221771294dfbb;
      u64 v_c38 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c75 = v_constb8736b999909049671d0ea07;
      u64 v_c39 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c40 = v_constef2d127de37b942baad06145;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_conste7f6c011776e8db7cd330b54;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c90 = _t[1];
        u64 v_c80 = _t[2];
        u64 v_c91 = _t[3];
        u64 v_c92 = _t[4];
        u64 v_c93 = _t[5];
        u64 v_c46 = _t[6];
        u64 v_c42 = _prim_lpush(db, v_c91, v_c19);
        if (v_c42 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c45 = _prim_lpush(db, v_c93, v_c75);
        if (v_c45 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c43 = _prim_lpush(db, v_c90, v_c80);
        if (v_c43 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c42, v_c43, v_c44, v_c45, v_c46});
        slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c79, v_c92}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp7JIl491", _fires);
  
      if (!_done)
      {
        ReadTask56* _cont = new ReadTask56(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask56(db,b), false);
  // (crule (pre (let __tconst3Lgs127 constd4735e3a265e16eee03f5971)) (scan temp4Qfu486 __t06gU130) (body (let __t8S8j131 (lpush __t06gU130 __tconst3Lgs127))) (head (emit-temp temp5HCD487 __t8S8j131)) seq_oracle.slog:25 #f)
  class ReadTask59 : public slog::Task
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
      head_rel[0] = db->getRelation("temp5HCD487");
      outer_rel = db->getRelation("temp4Qfu486");
  
    }
    ReadTask59(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c28 = _t[0];
        u64 v_c66 = _prim_lpush(db, v_c28, v_c25);
        if (v_c66 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:25"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c66});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:25", "delta:temp4Qfu486", _fires);
  
      if (!_done)
      {
        ReadTask59* _cont = new ReadTask59(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask59(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst5XJ6167 const2c624232cdd221771294dfbb) (let __tconst4JN7168 const7902699be42c8a8e46fbbb45) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f) (let __tconst9tvM200 constb8736b999909049671d0ea07) (let __tconst3L5u201 constc100f95c1913f9c72fc1f4ef) (let __tconst62sx203 constac8d8342bbb2362d13f0a559) (let __tconst7QKk210 constef2d127de37b942baad06145) (let __tconst4IrW216 const4e07408562bedb8b60ce05c1) (let __tconst8BnD220 constd4735e3a265e16eee03f5971) (let __tconst7QpE221 const6b86b273ff34fce19d6b804e) (let __tconst5EkG230 conste7f6c011776e8db7cd330b54) (let __t4KbT225 (lempty))) (once) (body) (head (emit-temp temp67UX488 __t4KbT225)) seq_oracle.slog:13 #f)
  class ReadTask60 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp67UX488");
  
    }
    ReadTask60(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const2c624232cdd221771294dfbb;
      u64 v_c38 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c75 = v_constb8736b999909049671d0ea07;
      u64 v_c76 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c39 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c40 = v_constef2d127de37b942baad06145;
      u64 v_c77 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c78 = v_constd4735e3a265e16eee03f5971;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c80 = _prim_lempty(db);
      if (v_c80 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c80});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask60(db,b), true);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp3FcD500 __t1dTM187) (body (let __t2Qvt188 (lpush __t1dTM187 __tconst9JLe162))) (head (emit-temp temp4P8M501 __t2Qvt188)) seq_oracle.slog:13 #f)
  class ReadTask61 : public slog::Task
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
      head_rel[0] = db->getRelation("temp4P8M501");
      outer_rel = db->getRelation("temp3FcD500");
  
    }
    ReadTask61(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c23 = _t[0];
        u64 v_c94 = _prim_lpush(db, v_c23, v_c13);
        if (v_c94 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c94});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp3FcD500", _fires);
  
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp2V3n505 __t8zRv192) (body (let __t6DUa193 (lpush __t8zRv192 __tconst9QsM157))) (head (emit-temp temp26JV506 __t6DUa193)) seq_oracle.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp26JV506");
      outer_rel = db->getRelation("temp2V3n505");
  
    }
    ReadTask62(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c56 = _t[0];
        u64 v_c32 = _prim_lpush(db, v_c56, v_c8);
        if (v_c32 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c32});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp2V3n505", _fires);
  
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
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp9II1508 __t0Sw6195) (body (let __t8IGL196 (lpush __t0Sw6195 __tconst1LNd154))) (head (emit-temp temp7UhH509 __t8IGL196)) seq_oracle.slog:13 #f)
  class ReadTask63 : public slog::Task
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
      head_rel[0] = db->getRelation("temp7UhH509");
      outer_rel = db->getRelation("temp9II1508");
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c50 = _t[0];
        u64 v_c95 = _prim_lpush(db, v_c50, v_c5);
        if (v_c95 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c95});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp9II1508", _fires);
  
      if (!_done)
      {
        ReadTask63* _cont = new ReadTask63(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask63(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst5XJ6167 const2c624232cdd221771294dfbb) (let __tconst4JN7168 const7902699be42c8a8e46fbbb45) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f) (let __tconst5EkG230 conste7f6c011776e8db7cd330b54)) (scan temp1v37494 __t54ug181 __t8doc229) (body (let __t1D24182 (lpush __t54ug181 __tconst4JN7168))) (head (emit-temp temp3VcG495 __t1D24182) (emit seed (0 1) __tconst5EkG230 __t8doc229)) seq_oracle.slog:13 #f)
  class ReadTask64 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3VcG495");
      head_rel[1] = db->getRelation("seed");
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("seed");
      head_index[1] = readrel66->getIndex(ord65, false);
      outer_rel = db->getRelation("temp1v37494");
  
    }
    ReadTask64(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const2c624232cdd221771294dfbb;
      u64 v_c38 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c41 = v_conste7f6c011776e8db7cd330b54;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c54 = _t[0];
        u64 v_c55 = _t[1];
        u64 v_c20 = _prim_lpush(db, v_c54, v_c38);
        if (v_c20 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c20});
        slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c41, v_c55}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp1v37494", _fires);
  
      if (!_done)
      {
        ReadTask64* _cont = new ReadTask64(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask64(db,b), false);
  // (crule (pre (let __tconst5gqA125 constc100f95c1913f9c72fc1f4ef) (let __tconst0i7S126 const8c1f1046219ddd216a023f79) (let __tconst3Lgs127 constd4735e3a265e16eee03f5971) (let __tconst0YKo128 const6b86b273ff34fce19d6b804e) (let __t6G0j129 (lempty))) (once) (body) (head (emit-temp temp8BRz485 __t6G0j129) (emit needle (0) __tconst3Lgs127) (emit needle (0) __tconst5gqA125) (emit needle (0) __tconst0i7S126)) seq_oracle.slog:25 #f)
  class ReadTask67 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8BRz485");
      head_rel[1] = db->getRelation("needle");
      std::vector<u16> ord68({0});
      slog::Relation* readrel69 = db->getRelation("needle");
      head_index[1] = readrel69->getIndex(ord68, false);
      head_rel[2] = db->getRelation("needle");
      std::vector<u16> ord70({0});
      slog::Relation* readrel71 = db->getRelation("needle");
      head_index[2] = readrel71->getIndex(ord70, false);
      head_rel[3] = db->getRelation("needle");
      std::vector<u16> ord72({0});
      slog::Relation* readrel73 = db->getRelation("needle");
      head_index[3] = readrel73->getIndex(ord72, false);
  
    }
    ReadTask67(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c96 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c97 = v_const8c1f1046219ddd216a023f79;
      u64 v_c25 = v_constd4735e3a265e16eee03f5971;
      u64 v_c26 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c27 = _prim_lempty(db);
      if (v_c27 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:25"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c27});
      slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c25}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c96}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[3], head_index[3], newbatch[3], std::array<u64,1>{v_c97}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:25", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask67(db,b), true);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst5XJ6167 const2c624232cdd221771294dfbb) (let __tconst4JN7168 const7902699be42c8a8e46fbbb45) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f) (let __tconst9tvM200 constb8736b999909049671d0ea07) (let __tconst3L5u201 constc100f95c1913f9c72fc1f4ef) (let __tconst62sx203 constac8d8342bbb2362d13f0a559) (let __tconst7QKk210 constef2d127de37b942baad06145) (let __tconst4IrW216 const4e07408562bedb8b60ce05c1) (let __tconst8BnD220 constd4735e3a265e16eee03f5971) (let __tconst7QpE221 const6b86b273ff34fce19d6b804e) (let __tconst5EkG230 conste7f6c011776e8db7cd330b54)) (scan temp62Y4490 __t1fDS206 __t4Gf1224 __t4KbT225 __t6aDB144 __t7xqF143) (body (let __t53GN145 (lpush __t6aDB144 __tconst8BnD220)) (let __t537F178 (lpush __t4Gf1224 __tconst4IrW216)) (let __t7b8W207 (lpush __t1fDS206 __tconst3L5u201)) (let __t4Hi3226 (lpush __t4KbT225 __t4Gf1224))) (head (emit-temp temp7JIl491 __t4Gf1224 __t4Hi3226 __t4KbT225 __t537F178 __t53GN145 __t7b8W207 __t7xqF143)) seq_oracle.slog:13 #f)
  class ReadTask74 : public slog::Task
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
      head_rel[0] = db->getRelation("temp7JIl491");
      outer_rel = db->getRelation("temp62Y4490");
  
    }
    ReadTask74(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const2c624232cdd221771294dfbb;
      u64 v_c38 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c75 = v_constb8736b999909049671d0ea07;
      u64 v_c76 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c39 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c40 = v_constef2d127de37b942baad06145;
      u64 v_c77 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c78 = v_constd4735e3a265e16eee03f5971;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_conste7f6c011776e8db7cd330b54;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c98 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c80 = _t[2];
        u64 v_c99 = _t[3];
        u64 v_c46 = _t[4];
        u64 v_c92 = _prim_lpush(db, v_c99, v_c78);
        if (v_c92 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c91 = _prim_lpush(db, v_c44, v_c77);
        if (v_c91 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c93 = _prim_lpush(db, v_c98, v_c76);
        if (v_c93 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c90 = _prim_lpush(db, v_c80, v_c44);
        if (v_c90 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<7>(head_rel[0], newbatch[0], std::array<u64,7>{v_c44, v_c90, v_c80, v_c91, v_c92, v_c93, v_c46});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp62Y4490", _fires);
  
      if (!_done)
      {
        ReadTask74* _cont = new ReadTask74(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask74(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst9JLe162 const3fdba35f04dc8c462986c992) (let __tconst6Gdj163 const6b51d431df5d7f141cbececc) (let __tconst9Wln164 const4fc82b26aecb47d2868c4efb) (let __tconst9uif165 const4a44dc15364204a80fe80e90) (let __tconst9c8T166 const19581e27de7ced00ff1ce50b) (let __tconst5XJ6167 const2c624232cdd221771294dfbb) (let __tconst4JN7168 const7902699be42c8a8e46fbbb45) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f) (let __tconst9tvM200 constb8736b999909049671d0ea07) (let __tconst3L5u201 constc100f95c1913f9c72fc1f4ef) (let __tconst62sx203 constac8d8342bbb2362d13f0a559) (let __tconst7QKk210 constef2d127de37b942baad06145) (let __tconst4IrW216 const4e07408562bedb8b60ce05c1) (let __tconst8BnD220 constd4735e3a265e16eee03f5971) (let __tconst7QpE221 const6b86b273ff34fce19d6b804e) (let __tconst5EkG230 conste7f6c011776e8db7cd330b54)) (scan temp62j7489 __t3DHo205 __t3PAv151 __t4KbT225 __t4Ykf176 __t7xqF143) (body (let __t6aDB144 (lpush __t7xqF143 __tconst7QpE221)) (let __t1fDS206 (lpush __t3DHo205 __tconst8BnD220)) (let __t4Gf1224 (lpush __t4Ykf176 __tconst8BnD220))) (head (emit-temp temp62Y4490 __t1fDS206 __t4Gf1224 __t4KbT225 __t6aDB144 __t7xqF143) (emit seed (0 1) __tconst4IrW216 __t3PAv151)) seq_oracle.slog:13 #f)
  class ReadTask75 : public slog::Task
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
      head_rel[0] = db->getRelation("temp62Y4490");
      head_rel[1] = db->getRelation("seed");
      std::vector<u16> ord76({0, 1});
      slog::Relation* readrel77 = db->getRelation("seed");
      head_index[1] = readrel77->getIndex(ord76, false);
      outer_rel = db->getRelation("temp62j7489");
  
    }
    ReadTask75(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const6b51d431df5d7f141cbececc;
      u64 v_c15 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c16 = v_const4a44dc15364204a80fe80e90;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const2c624232cdd221771294dfbb;
      u64 v_c38 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c75 = v_constb8736b999909049671d0ea07;
      u64 v_c76 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c39 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c40 = v_constef2d127de37b942baad06145;
      u64 v_c77 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c78 = v_constd4735e3a265e16eee03f5971;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c41 = v_conste7f6c011776e8db7cd330b54;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c83 = _t[0];
        u64 v_c81 = _t[1];
        u64 v_c80 = _t[2];
        u64 v_c82 = _t[3];
        u64 v_c46 = _t[4];
        u64 v_c99 = _prim_lpush(db, v_c46, v_c79);
        if (v_c99 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c98 = _prim_lpush(db, v_c83, v_c78);
        if (v_c98 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        u64 v_c44 = _prim_lpush(db, v_c82, v_c78);
        if (v_c44 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c98, v_c44, v_c80, v_c99, v_c46});
        slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c77, v_c81}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp62j7489", _fires);
  
      if (!_done)
      {
        ReadTask75* _cont = new ReadTask75(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask75(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst64Fc161 const8527a891e224136950ff32ca) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp4P8M501 __t2Qvt188) (body (let __t6TTg189 (lpush __t2Qvt188 __tconst64Fc161))) (head (emit-temp temp4L8p502 __t6TTg189)) seq_oracle.slog:13 #f)
  class ReadTask78 : public slog::Task
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
      head_rel[0] = db->getRelation("temp4L8p502");
      outer_rel = db->getRelation("temp4P8M501");
  
    }
    ReadTask78(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c12 = v_const8527a891e224136950ff32ca;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c94 = _t[0];
        u64 v_c100 = _prim_lpush(db, v_c94, v_c12);
        if (v_c100 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c100});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp4P8M501", _fires);
  
      if (!_done)
      {
        ReadTask78* _cont = new ReadTask78(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask78(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp7UhH509 __t8IGL196) (body (let __t3Aj6197 (lpush __t8IGL196 __tconst84F3153))) (head (emit-temp temp3vdp510 __t3Aj6197)) seq_oracle.slog:13 #f)
  class ReadTask79 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3vdp510");
      outer_rel = db->getRelation("temp7UhH509");
  
    }
    ReadTask79(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c95 = _t[0];
        u64 v_c24 = _prim_lpush(db, v_c95, v_c4);
        if (v_c24 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c24});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp7UhH509", _fires);
  
      if (!_done)
      {
        ReadTask79* _cont = new ReadTask79(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask79(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre2i99458 __errf5sD9459 __errf2GQl460) (body) (head (emit error (0) __erre2i99458)) <internal>:1 #f)
  class ReadTask80 : public slog::Task
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
      std::vector<u16> ord81({0});
      slog::Relation* readrel82 = db->getRelation("error");
      head_index[0] = readrel82->getIndex(ord81, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask80(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c101 = _t[0];
        u64 v_c102 = _t[1];
        u64 v_c103 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c101}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask80* _cont = new ReadTask80(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask80(db,b), false);
  // (crule (pre (let __tconst84F3153 const785f3ec7eb32f30b90cd0fcf) (let __tconst1LNd154 const6f4b6612125fb3a0daecd279) (let __tconst5CLm155 constf5ca38f748a1d6eaf726b8a4) (let __tconst1IHf156 const9400f1b21cb527d7fa3d3eab) (let __tconst9QsM157 const4ec9599fc203d176a301536c) (let __tconst8Mpx158 const4523540f1504cd17100c4835) (let __tconst25c1159 constb17ef6d19c7a5b1ee83b907c) (let __tconst51BV160 conste629fa6598d732768f7c726b) (let __tconst65Mz198 const4b227777d4dd1fc61c6f884f)) (scan temp4L8p502 __t6TTg189) (body (let __t8gHB190 (lpush __t6TTg189 __tconst51BV160))) (head (emit-temp temp1IDy503 __t8gHB190)) seq_oracle.slog:13 #f)
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
      head_rel[0] = db->getRelation("temp1IDy503");
      outer_rel = db->getRelation("temp4L8p502");
  
    }
    ReadTask83(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c5 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c6 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c7 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c8 = v_const4ec9599fc203d176a301536c;
      u64 v_c9 = v_const4523540f1504cd17100c4835;
      u64 v_c10 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c11 = v_conste629fa6598d732768f7c726b;
      u64 v_c19 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c100 = _t[0];
        u64 v_c51 = _prim_lpush(db, v_c100, v_c11);
        if (v_c51 == slog_error) { slog::emit_pending_error(db, "seq_oracle.slog:13"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c51});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:13", "delta:temp4L8p502", _fires);
  
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
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp1IDy503");
  s->addReadRel("temp1v37494");
  s->addReadRel("temp26JV506");
  s->addReadRel("temp2V3n505");
  s->addReadRel("temp3FcD500");
  s->addReadRel("temp3Pnb498");
  s->addReadRel("temp3VcG495");
  s->addReadRel("temp3Ykl497");
  s->addReadRel("temp3vdp510");
  s->addReadRel("temp4L8p502");
  s->addReadRel("temp4P8M501");
  s->addReadRel("temp4Qfu486");
  s->addReadRel("temp4ZjV499");
  s->addReadRel("temp4wIF493");
  s->addReadRel("temp5HCD487");
  s->addReadRel("temp5WL2496");
  s->addReadRel("temp62Y4490");
  s->addReadRel("temp62j7489");
  s->addReadRel("temp67UX488");
  s->addReadRel("temp6vgA504");
  s->addReadRel("temp7JIl491");
  s->addReadRel("temp7UhH509");
  s->addReadRel("temp8BRz485");
  s->addReadRel("temp8wf8507");
  s->addReadRel("temp9II1508");
  s->addReadRel("temp9P5L492");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("_enum");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("needle");
  s->addDynamicRel("probe");
  s->addDynamicRel("seed");
  s->addDynamicRel("temp1IDy503");
  s->addDynamicRel("temp1v37494");
  s->addDynamicRel("temp26JV506");
  s->addDynamicRel("temp2V3n505");
  s->addDynamicRel("temp3FcD500");
  s->addDynamicRel("temp3Pnb498");
  s->addDynamicRel("temp3VcG495");
  s->addDynamicRel("temp3Ykl497");
  s->addDynamicRel("temp3vdp510");
  s->addDynamicRel("temp4L8p502");
  s->addDynamicRel("temp4P8M501");
  s->addDynamicRel("temp4Qfu486");
  s->addDynamicRel("temp4ZjV499");
  s->addDynamicRel("temp4wIF493");
  s->addDynamicRel("temp5HCD487");
  s->addDynamicRel("temp5WL2496");
  s->addDynamicRel("temp62Y4490");
  s->addDynamicRel("temp62j7489");
  s->addDynamicRel("temp67UX488");
  s->addDynamicRel("temp6vgA504");
  s->addDynamicRel("temp7JIl491");
  s->addDynamicRel("temp7UhH509");
  s->addDynamicRel("temp8BRz485");
  s->addDynamicRel("temp8wf8507");
  s->addDynamicRel("temp9II1508");
  s->addDynamicRel("temp9P5L492");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

