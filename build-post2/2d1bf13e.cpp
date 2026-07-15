
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constab76c7d069d6f33dc950fb33;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("2d1bf13e");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constab76c7d069d6f33dc950fb33 = db->encodeString("sat");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord389({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord389, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord390({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord390, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord391({1, 2, 0});
    
    r->addIndex<3>(ord391, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord392({0, 1, 2});
    
    r->addIndex<3>(ord392, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp87TC150");
  if (r == 0) db->addTempRelation("temp87TC150", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6PBR149");
  if (r == 0) db->addTempRelation("temp6PBR149", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("src");
  if (r == 0) db->addRelation("src", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("src");
      std::vector<u16> ord393({0});
    
    r->addIndex<1>(ord393, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("src"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_vcode");
  if (r == 0) db->addRelation("smt_vcode", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_vcode");
      std::vector<u16> ord394({0, 1});
    
    r->addIndex<2>(ord394, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_vcode"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_unsat");
  if (r == 0) db->addRelation("smt_unsat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unsat");
      std::vector<u16> ord395({0});
    
    r->addIndex<1>(ord395, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unsat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_unknown");
  if (r == 0) db->addRelation("smt_unknown", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_unknown");
      std::vector<u16> ord396({0});
    
    r->addIndex<1>(ord396, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_unknown"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_sat");
  if (r == 0) db->addRelation("smt_sat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_sat");
      std::vector<u16> ord397({0});
    
    r->addIndex<1>(ord397, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("smt_sat"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_qsat_ans");
  if (r == 0) db->addRelation("smt_qsat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord398({0, 1});
    
    r->addIndex<2>(ord398, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qsat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qsat");
  if (r == 0) db->addStruct("smt_qsat", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qsat");
      std::vector<u16> ord399({1, 0});
    
    r->addIndex<2>(ord399, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord400({0, 1});
    
    r->addIndex<2>(ord400, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord401({0, 1});
    
    r->addIndex<2>(ord401, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord402({1, 0});
    
    r->addIndex<2>(ord402, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qsat"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qmodel_ans");
  if (r == 0) db->addRelation("smt_qmodel_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel_ans");
      std::vector<u16> ord403({0, 1});
    
    r->addIndex<2>(ord403, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qmodel_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qmodel");
  if (r == 0) db->addStruct("smt_qmodel", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qmodel");
      std::vector<u16> ord404({1, 0});
    
    r->addIndex<2>(ord404, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord405({0, 1});
    
    r->addIndex<2>(ord405, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qmodel"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_qcore_ans");
  if (r == 0) db->addRelation("smt_qcore_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore_ans");
      std::vector<u16> ord406({0, 1});
    
    r->addIndex<2>(ord406, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_qcore_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_qcore");
  if (r == 0) db->addStruct("smt_qcore", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_qcore");
      std::vector<u16> ord407({1, 0});
    
    r->addIndex<2>(ord407, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord408({0, 1});
    
    r->addIndex<2>(ord408, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_qcore"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_model_ans");
  if (r == 0) db->addRelation("smt_model_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model_ans");
      std::vector<u16> ord409({0, 1, 2});
    
    r->addIndex<3>(ord409, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_model_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_model");
  if (r == 0) db->addStruct("smt_model", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_model");
      std::vector<u16> ord410({1, 0});
    
    r->addIndex<2>(ord410, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord411({0, 1});
    
    r->addIndex<2>(ord411, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_model"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_core_ans");
  if (r == 0) db->addRelation("smt_core_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core_ans");
      std::vector<u16> ord412({0, 1, 2});
    
    r->addIndex<3>(ord412, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("smt_core_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_core");
  if (r == 0) db->addStruct("smt_core", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_core");
      std::vector<u16> ord413({1, 0});
    
    r->addIndex<2>(ord413, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord414({0, 1});
    
    r->addIndex<2>(ord414, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_core"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_check_ans");
  if (r == 0) db->addRelation("smt_check_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check_ans");
      std::vector<u16> ord415({0, 1});
    
    r->addIndex<2>(ord415, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord416({1, 0});
    
    r->addIndex<2>(ord416, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord417({1, 0});
    
    r->addIndex<2>(ord417, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("smt_check_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_check");
  if (r == 0) db->addStruct("smt_check", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_check");
      std::vector<u16> ord418({1, 0});
    
    r->addIndex<2>(ord418, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord419({0, 1});
    
    r->addIndex<2>(ord419, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord420({0, 1});
    
    r->addIndex<2>(ord420, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord421({1, 0});
    
    r->addIndex<2>(ord421, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("smt_check"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord422({1, 2, 0});
    
    r->addIndex<3>(ord422, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord423({0, 1, 2});
    
    r->addIndex<3>(ord423, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("sedge");
  if (r == 0) db->addRelation("sedge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("sedge");
      std::vector<u16> ord424({0, 2, 1});
    
    r->addIndex<3>(ord424, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), true);
      std::vector<u16> ord425({2, 0, 1});
    
    r->addIndex<3>(ord425, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("sedge"), std::array<u16,3>{0, 2, 1}, b));
  r = db->getRelation("rsize");
  if (r == 0) db->addRelation("rsize", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("rsize");
      std::vector<u16> ord426({0, 1});
    
    r->addIndex<2>(ord426, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("rsize"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("reach_has");
  if (r == 0) db->addRelation("reach_has", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("reach_has");
      std::vector<u16> ord427({1, 0});
    
    r->addIndex<2>(ord427, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("reach_has"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("reach");
  if (r == 0) db->addRelation("reach", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("reach");
  r->setLattice(LAT_EXTERN, false, 0, false, 0, "set-int", db->collections());
      std::vector<u16> ord428({0, 1});
    
    r->addMapIndex<2>(ord428);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<2>(db, r, std::array<u16,2>{0, 1}, b, db->getRelation("reach_has"), false), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<2>(db, db->getRelation("reach"), std::array<u16,2>{0, 1}, b, db->getRelation("reach_has"), false));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord429({1, 2, 3, 0});
    
    r->addIndex<4>(ord429, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord430({0, 1, 2, 3});
    
    r->addIndex<4>(ord430, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord431({1, 2, 0});
    
    r->addIndex<3>(ord431, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord432({0, 1, 2});
    
    r->addIndex<3>(ord432, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord433({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord433, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord434({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord434, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord435({1, 2, 0});
    
    r->addIndex<3>(ord435, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord436({0, 1, 2});
    
    r->addIndex<3>(ord436, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord437({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord437, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord438({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord438, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lsub");
  if (r == 0) db->addStruct("lsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lsub");
      std::vector<u16> ord439({1, 2, 0});
    
    r->addIndex<3>(ord439, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord440({0, 1, 2});
    
    r->addIndex<3>(ord440, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lsub"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lor");
  if (r == 0) db->addStruct("lor", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lor");
      std::vector<u16> ord441({1, 2, 0});
    
    r->addIndex<3>(ord441, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord442({0, 1, 2});
    
    r->addIndex<3>(ord442, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lor"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lnot");
  if (r == 0) db->addStruct("lnot", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lnot");
      std::vector<u16> ord443({1, 0});
    
    r->addIndex<2>(ord443, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord444({0, 1});
    
    r->addIndex<2>(ord444, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lnot"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("lne");
  if (r == 0) db->addStruct("lne", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lne");
      std::vector<u16> ord445({1, 2, 0});
    
    r->addIndex<3>(ord445, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord446({0, 1, 2});
    
    r->addIndex<3>(ord446, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lne"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lmul");
  if (r == 0) db->addStruct("lmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lmul");
      std::vector<u16> ord447({1, 2, 0});
    
    r->addIndex<3>(ord447, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord448({0, 1, 2});
    
    r->addIndex<3>(ord448, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lmul"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("llt");
  if (r == 0) db->addStruct("llt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("llt");
      std::vector<u16> ord449({1, 2, 0});
    
    r->addIndex<3>(ord449, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord450({0, 2, 1});
    
    r->addIndex<3>(ord450, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord451({2, 0, 1});
    
    r->addIndex<3>(ord451, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord452({0, 2, 1});
    
    r->addIndex<3>(ord452, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
      std::vector<u16> ord453({1, 2, 0});
    
    r->addIndex<3>(ord453, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("llt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lle");
  if (r == 0) db->addStruct("lle", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lle");
      std::vector<u16> ord454({1, 2, 0});
    
    r->addIndex<3>(ord454, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord455({0, 1, 2});
    
    r->addIndex<3>(ord455, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lle"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lite");
  if (r == 0) db->addStruct("lite", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lite");
      std::vector<u16> ord456({1, 2, 3, 0});
    
    r->addIndex<4>(ord456, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord457({0, 1, 2, 3});
    
    r->addIndex<4>(ord457, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("lite"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("limplies");
  if (r == 0) db->addStruct("limplies", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("limplies");
      std::vector<u16> ord458({1, 2, 0});
    
    r->addIndex<3>(ord458, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord459({0, 1, 2});
    
    r->addIndex<3>(ord459, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("limplies"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lgt");
  if (r == 0) db->addStruct("lgt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lgt");
      std::vector<u16> ord460({1, 2, 0});
    
    r->addIndex<3>(ord460, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord461({0, 1, 2});
    
    r->addIndex<3>(ord461, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lgt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lge");
  if (r == 0) db->addStruct("lge", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lge");
      std::vector<u16> ord462({1, 2, 0});
    
    r->addIndex<3>(ord462, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord463({0, 1, 2});
    
    r->addIndex<3>(ord463, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lge"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("leq");
  if (r == 0) db->addStruct("leq", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leq");
      std::vector<u16> ord464({1, 2, 0});
    
    r->addIndex<3>(ord464, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord465({0, 1, 2});
    
    r->addIndex<3>(ord465, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("leq"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lany");
  if (r == 0) db->addStruct("lany", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lany");
      std::vector<u16> ord466({1, 0});
    
    r->addIndex<2>(ord466, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord467({0, 1});
    
    r->addIndex<2>(ord467, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lany"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("land");
  if (r == 0) db->addStruct("land", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("land");
      std::vector<u16> ord468({1, 2, 0});
    
    r->addIndex<3>(ord468, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord469({0, 1, 2});
    
    r->addIndex<3>(ord469, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("land"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("lall");
  if (r == 0) db->addStruct("lall", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lall");
      std::vector<u16> ord470({1, 0});
    
    r->addIndex<2>(ord470, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord471({0, 1});
    
    r->addIndex<2>(ord471, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lall"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("ladd");
  if (r == 0) db->addStruct("ladd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ladd");
      std::vector<u16> ord472({1, 2, 0});
    
    r->addIndex<3>(ord472, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord473({0, 1, 2});
    
    r->addIndex<3>(ord473, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ladd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("iv");
  if (r == 0) db->addStruct("iv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("iv");
      std::vector<u16> ord474({1, 0});
    
    r->addIndex<2>(ord474, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord475({0, 1});
    
    r->addIndex<2>(ord475, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("iv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord476({1, 2, 3, 0});
    
    r->addIndex<4>(ord476, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord477({0, 1, 2, 3});
    
    r->addIndex<4>(ord477, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ic");
  if (r == 0) db->addStruct("ic", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ic");
      std::vector<u16> ord478({1, 0});
    
    r->addIndex<2>(ord478, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord479({0, 1});
    
    r->addIndex<2>(ord479, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord480({0, 1});
    
    r->addIndex<2>(ord480, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord481({1, 0});
    
    r->addIndex<2>(ord481, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ic"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("final");
  if (r == 0) db->addRelation("final", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("final");
      std::vector<u16> ord482({0, 1});
    
    r->addIndex<2>(ord482, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("final"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord483({0});
    
    r->addIndex<1>(ord483, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("edge");
  if (r == 0) db->addRelation("edge", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("edge");
      std::vector<u16> ord484({0, 1});
    
    r->addIndex<2>(ord484, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("edge"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord485({1, 2, 0});
    
    r->addIndex<3>(ord485, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord486({0, 1, 2});
    
    r->addIndex<3>(ord486, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bv");
  if (r == 0) db->addStruct("bv", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bv");
      std::vector<u16> ord487({1, 0});
    
    r->addIndex<2>(ord487, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord488({0, 1});
    
    r->addIndex<2>(ord488, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("bv"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord489({1, 0});
    
    r->addIndex<2>(ord489, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord490({0, 1});
    
    r->addIndex<2>(ord490, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  d->bindOracle(s, "smtcore", "smt_qcore", "smt_qcore_ans");
  d->bindOracle(s, "smtmodel", "smt_qmodel", "smt_qmodel_ans");
  d->bindOracle(s, "smt", "smt_qsat", "smt_qsat_ans");
  // (crule (pre (let __tconst5LQZ68 constab76c7d069d6f33dc950fb33) (let __tconst5jPI52 const4e07408562bedb8b60ce05c1) (let __t08Pw50 (cmap))) (scan ic __t4pFy54 g) (body (exists ic (1 0) 1 __tconst5jPI52) (exists llt (1 2 0) 1 __t4pFy54) (exists sedge (2 0 1) 1 g) (join _enum (1 0) 1 __tconst5LQZ68 __v0) (join smt_check_ans (1 0) 1 __v0 __t8FKp56) (join ic (1 0) 1 __tconst5jPI52 __t57FM53) (join-old llt (1 2 0) 2 (1 2 0) __t4pFy54 __t57FM53 __t5Ajn55) (join-old smt_check (0 1) 2 (0 1) __t8FKp56 __t5Ajn55) (join sedge (2 0 1) 1 g a b) (join reach_has (1 0) 1 a s) (let __t5nOz51 (cins __t08Pw50 b))) (head (emit-lat reach s __t5nOz51)) smt_rhas.slog:32 #f)
  class ReadTask12 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex0;  slog::Index** lltindex1;  slog::Index** sedgeindex2;  slog::Index** _enumindex3;  slog::Index** smt_check_ansindex4;  slog::Index** icindex5;  slog::Index** lltindex6;  slog::Index** smt_checkindex7;  slog::Index** sedgeindex8;  slog::Index** reach_hasindex9;  slog::Index** lltdelta10;  slog::Index** smt_checkdelta11;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      outer_rel = db->getRelation("ic");
      std::vector<u16> ord13({1, 0});
      slog::Relation* readrel14 = db->getRelation("ic");
      icindex0 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({1, 2, 0});
      slog::Relation* readrel16 = db->getRelation("llt");
      lltindex1 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({2, 0, 1});
      slog::Relation* readrel18 = db->getRelation("sedge");
      sedgeindex2 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("_enum");
      _enumindex3 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 0});
      slog::Relation* readrel22 = db->getRelation("smt_check_ans");
      smt_check_ansindex4 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 0});
      slog::Relation* readrel24 = db->getRelation("ic");
      icindex5 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 2, 0});
      slog::Relation* readrel26 = db->getRelation("llt");
      lltindex6 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 2, 0});
      slog::Relation* readrel28 = db->getRelation("llt");
      lltdelta10 = readrel28->getIndex(ord27, true);
      std::vector<u16> ord29({0, 1});
      slog::Relation* readrel30 = db->getRelation("smt_check");
      smt_checkindex7 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({0, 1});
      slog::Relation* readrel32 = db->getRelation("smt_check");
      smt_checkdelta11 = readrel32->getIndex(ord31, true);
      std::vector<u16> ord33({2, 0, 1});
      slog::Relation* readrel34 = db->getRelation("sedge");
      sedgeindex8 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("reach_has");
      reach_hasindex9 = readrel36->getIndex(ord35, false);
  
    }
    ReadTask12(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = _prim_cmap(db);
      if (v_c2 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return true; }
  
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
        if (!slog::exists_probe<2,1>(icindex0, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(lltindex1, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(sedgeindex2, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex3, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m37) {
          u64 v_c5 = m37[1];
          slog::join_probe<2,1>(smt_check_ansindex4, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m38) {
            u64 v_c6 = m38[1];
            slog::join_probe<2,1>(icindex5, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m39) {
              u64 v_c7 = m39[1];
              slog::join_probe_old<3,2>(lltindex6, lltdelta10, std::array<u64,3>{v_c3, v_c7, 0}, [&](const std::array<u64,3>& m40) {
                u64 v_c8 = m40[2];
                slog::join_probe_old<2,2>(smt_checkindex7, smt_checkdelta11, std::array<u64,2>{v_c6, v_c8}, [&](const std::array<u64,2>& m41) {
                  slog::join_probe<3,1>(sedgeindex8, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m42) {
                    u64 v_c9 = m42[1]; u64 v_c10 = m42[2];
                    slog::join_probe<2,1>(reach_hasindex9, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m43) {
                      u64 v_c11 = m43[1];
                      u64 v_c12 = _prim_cins(db, v_c2, v_c10);
                      if (v_c12 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return; }
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c12});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:32", "delta:ic", _fires);
  
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
  // (crule (pre) (scan smt_qsat_ans __t3s8b2 C) (body (join smt_vcode (0 1) 1 C V) (join-old smt_qsat (0 1) 1 (0 1) __t3s8b2 F) (join-old smt_check (1 0) 1 (1 0) F __t5xkK1)) (head (emit smt_check_ans (0 1) __t5xkK1 V)) smt.slog:69 #f)
  class ReadTask49 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_vcodeindex44;  slog::Index** smt_qsatindex45;  slog::Index** smt_checkindex46;  slog::Index** smt_qsatdelta47;  slog::Index** smt_checkdelta48;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check_ans");
      std::vector<u16> ord50({0, 1});
      slog::Relation* readrel51 = db->getRelation("smt_check_ans");
      head_index[0] = readrel51->getIndex(ord50, false);
      outer_rel = db->getRelation("smt_qsat_ans");
      std::vector<u16> ord52({0, 1});
      slog::Relation* readrel53 = db->getRelation("smt_vcode");
      smt_vcodeindex44 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({0, 1});
      slog::Relation* readrel55 = db->getRelation("smt_qsat");
      smt_qsatindex45 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("smt_qsat");
      smt_qsatdelta47 = readrel57->getIndex(ord56, true);
      std::vector<u16> ord58({1, 0});
      slog::Relation* readrel59 = db->getRelation("smt_check");
      smt_checkindex46 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 0});
      slog::Relation* readrel61 = db->getRelation("smt_check");
      smt_checkdelta48 = readrel61->getIndex(ord60, true);
  
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
        u64 v_c13 = _t[0];
        u64 v_c14 = _t[1];
        slog::join_probe<2,1>(smt_vcodeindex44, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m62) {
          u64 v_c15 = m62[1];
          slog::join_probe_old<2,1>(smt_qsatindex45, smt_qsatdelta47, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m63) {
            u64 v_c16 = m63[1];
            slog::join_probe_old<2,1>(smt_checkindex46, smt_checkdelta48, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m64) {
              u64 v_c17 = m64[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c17, v_c15}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_qsat_ans", _fires);
  
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
  // (crule (pre (let __tconst5LQZ68 constab76c7d069d6f33dc950fb33) (let __tconst5jPI52 const4e07408562bedb8b60ce05c1) (let __t08Pw50 (cmap))) (scan smt_check __t8FKp56 __t5Ajn55) (body (exists smt_check_ans (0 1) 1 __t8FKp56) (exists ic (1 0) 1 __tconst5jPI52) (join _enum (1 0) 1 __tconst5LQZ68 __v0) (join smt_check_ans (0 1) 2 __t8FKp56 __v0) (join ic (1 0) 1 __tconst5jPI52 __t57FM53) (join llt (0 2 1) 2 __t5Ajn55 __t57FM53 __t4pFy54) (join ic (0 1) 1 __t4pFy54 g) (join sedge (2 0 1) 1 g a b) (join reach_has (1 0) 1 a s) (let __t5nOz51 (cins __t08Pw50 b))) (head (emit-lat reach s __t5nOz51)) smt_rhas.slog:32 #f)
  class ReadTask74 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_check_ansindex65;  slog::Index** icindex66;  slog::Index** _enumindex67;  slog::Index** smt_check_ansindex68;  slog::Index** icindex69;  slog::Index** lltindex70;  slog::Index** icindex71;  slog::Index** sedgeindex72;  slog::Index** reach_hasindex73;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      outer_rel = db->getRelation("smt_check");
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("smt_check_ans");
      smt_check_ansindex65 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 0});
      slog::Relation* readrel78 = db->getRelation("ic");
      icindex66 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 0});
      slog::Relation* readrel80 = db->getRelation("_enum");
      _enumindex67 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({0, 1});
      slog::Relation* readrel82 = db->getRelation("smt_check_ans");
      smt_check_ansindex68 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 0});
      slog::Relation* readrel84 = db->getRelation("ic");
      icindex69 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 2, 1});
      slog::Relation* readrel86 = db->getRelation("llt");
      lltindex70 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("ic");
      icindex71 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({2, 0, 1});
      slog::Relation* readrel90 = db->getRelation("sedge");
      sedgeindex72 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({1, 0});
      slog::Relation* readrel92 = db->getRelation("reach_has");
      reach_hasindex73 = readrel92->getIndex(ord91, false);
  
    }
    ReadTask74(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = _prim_cmap(db);
      if (v_c2 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        u64 v_c8 = _t[1];
        if (!slog::exists_probe<2,1>(smt_check_ansindex65, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(icindex66, std::array<u64,2>{v_c1, 0})) return;
        slog::join_probe<2,1>(_enumindex67, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m93) {
          u64 v_c5 = m93[1];
          slog::join_probe<2,2>(smt_check_ansindex68, std::array<u64,2>{v_c6, v_c5}, [&](const std::array<u64,2>& m94) {
            slog::join_probe<2,1>(icindex69, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m95) {
              u64 v_c7 = m95[1];
              slog::join_probe<3,2>(lltindex70, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m96) {
                u64 v_c3 = m96[2];
                slog::join_probe<2,1>(icindex71, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m97) {
                  u64 v_c4 = m97[1];
                  slog::join_probe<3,1>(sedgeindex72, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m98) {
                    u64 v_c9 = m98[1]; u64 v_c10 = m98[2];
                    slog::join_probe<2,1>(reach_hasindex73, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m99) {
                      u64 v_c11 = m99[1];
                      u64 v_c12 = _prim_cins(db, v_c2, v_c10);
                      if (v_c12 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return; }
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c12});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:32", "delta:smt_check", _fires);
  
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
  // (crule (pre (let __tconst5LQZ68 constab76c7d069d6f33dc950fb33) (let __tconst5jPI52 const4e07408562bedb8b60ce05c1) (let __t08Pw50 (cmap))) (probe ic (1 0) 1 __tconst5jPI52 __t57FM53) (body (exists llt (2 0 1) 1 __t57FM53) (join _enum (1 0) 1 __tconst5LQZ68 __v0) (join smt_check_ans (1 0) 1 __v0 __t8FKp56) (join-old smt_check (0 1) 1 (0 1) __t8FKp56 __t5Ajn55) (join-old llt (0 2 1) 2 (0 2 1) __t5Ajn55 __t57FM53 __t4pFy54) (join-old ic (0 1) 1 (0 1) __t4pFy54 g) (join sedge (2 0 1) 1 g a b) (join reach_has (1 0) 1 a s) (let __t5nOz51 (cins __t08Pw50 b))) (head (emit-lat reach s __t5nOz51)) smt_rhas.slog:32 #f)
  class ReadTask111 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lltindex100;  slog::Index** _enumindex101;  slog::Index** smt_check_ansindex102;  slog::Index** smt_checkindex103;  slog::Index** lltindex104;  slog::Index** icindex105;  slog::Index** sedgeindex106;  slog::Index** reach_hasindex107;  slog::Index** smt_checkdelta108;  slog::Index** lltdelta109;  slog::Index** icdelta110;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      std::vector<u16> ord112({1, 0});
      slog::Relation* readrel113 = db->getRelation("ic");
      driver_index = readrel113->getIndex(ord112, true);
      std::vector<u16> ord114({2, 0, 1});
      slog::Relation* readrel115 = db->getRelation("llt");
      lltindex100 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 0});
      slog::Relation* readrel117 = db->getRelation("_enum");
      _enumindex101 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 0});
      slog::Relation* readrel119 = db->getRelation("smt_check_ans");
      smt_check_ansindex102 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({0, 1});
      slog::Relation* readrel121 = db->getRelation("smt_check");
      smt_checkindex103 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({0, 1});
      slog::Relation* readrel123 = db->getRelation("smt_check");
      smt_checkdelta108 = readrel123->getIndex(ord122, true);
      std::vector<u16> ord124({0, 2, 1});
      slog::Relation* readrel125 = db->getRelation("llt");
      lltindex104 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({0, 2, 1});
      slog::Relation* readrel127 = db->getRelation("llt");
      lltdelta109 = readrel127->getIndex(ord126, true);
      std::vector<u16> ord128({0, 1});
      slog::Relation* readrel129 = db->getRelation("ic");
      icindex105 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({0, 1});
      slog::Relation* readrel131 = db->getRelation("ic");
      icdelta110 = readrel131->getIndex(ord130, true);
      std::vector<u16> ord132({2, 0, 1});
      slog::Relation* readrel133 = db->getRelation("sedge");
      sedgeindex106 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("reach_has");
      reach_hasindex107 = readrel135->getIndex(ord134, false);
  
    }
    ReadTask111(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = _prim_cmap(db);
      if (v_c2 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c1, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m136) {
        u64 v_c7 = m136[1];
        if (buckethash(v_c7) != bucket) return;
        if (!slog::exists_probe<3,1>(lltindex100, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex101, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m137) {
          u64 v_c5 = m137[1];
          slog::join_probe<2,1>(smt_check_ansindex102, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m138) {
            u64 v_c6 = m138[1];
            slog::join_probe_old<2,1>(smt_checkindex103, smt_checkdelta108, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m139) {
              u64 v_c8 = m139[1];
              slog::join_probe_old<3,2>(lltindex104, lltdelta109, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m140) {
                u64 v_c3 = m140[2];
                slog::join_probe_old<2,1>(icindex105, icdelta110, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m141) {
                  u64 v_c4 = m141[1];
                  slog::join_probe<3,1>(sedgeindex106, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m142) {
                    u64 v_c9 = m142[1]; u64 v_c10 = m142[2];
                    slog::join_probe<2,1>(reach_hasindex107, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m143) {
                      u64 v_c11 = m143[1];
                      u64 v_c12 = _prim_cins(db, v_c2, v_c10);
                      if (v_c12 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return; }
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c12});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:32", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask111* _cont = new ReadTask111(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask111(db,b), false);
  // (crule (pre) (scan smt_check __t9ddA26 F) (body (join smt_vcode (0 1) 0 C V)) (head (mkstruct smt_qsat (1 0) __1JIu61 F)) smt.slog:69 #f)
  class ReadTask145 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_vcodeindex144;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_qsat");
      outer_rel = db->getRelation("smt_check");
      std::vector<u16> ord146({0, 1});
      slog::Relation* readrel147 = db->getRelation("smt_vcode");
      smt_vcodeindex144 = readrel147->getIndex(ord146, false);
  
    }
    ReadTask145(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[1];
        slog::join_all<2>(smt_vcodeindex144, [&](const std::array<u64,2>& m148) {
          u64 v_c14 = m148[0]; u64 v_c15 = m148[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_check", _fires);
  
      if (!_done)
      {
        ReadTask145* _cont = new ReadTask145(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask145(db,b), false);
  // (crule (pre) (scan smt_vcode C V) (body (join smt_core (0 1) 0 __t2YQI29 F)) (head (mkstruct smt_qcore (1 0) __3u7x76 F)) smt.slog:106 #f)
  class ReadTask150 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_coreindex149;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_qcore");
      outer_rel = db->getRelation("smt_vcode");
      std::vector<u16> ord151({0, 1});
      slog::Relation* readrel152 = db->getRelation("smt_core");
      smt_coreindex149 = readrel152->getIndex(ord151, false);
  
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
        u64 v_c14 = _t[0];
        u64 v_c15 = _t[1];
        slog::join_all<2>(smt_coreindex149, [&](const std::array<u64,2>& m153) {
          u64 v_c19 = m153[0]; u64 v_c16 = m153[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:106", "all:smt_vcode", _fires);
  
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
      s->addTask(phase_read, new ReadTask150(db,b), true);
  // (crule (pre) (scan type_mismatch __erre1sET133 __errf67D3134 __errf46Mm135 __errf0kJx136 __errf1RDD137) (body) (head (emit error (0) __erre1sET133)) <internal>:1 #f)
  class ReadTask154 : public slog::Task
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
      std::vector<u16> ord155({0});
      slog::Relation* readrel156 = db->getRelation("error");
      head_index[0] = readrel156->getIndex(ord155, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask154(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c24 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c20}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask154* _cont = new ReadTask154(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask154(db,b), false);
  // (crule (pre) (scan toint_range __erre81g4130 __errf1HDu131 __errf0WGy132) (body) (head (emit error (0) __erre81g4130)) <internal>:1 #f)
  class ReadTask157 : public slog::Task
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
      std::vector<u16> ord158({0});
      slog::Relation* readrel159 = db->getRelation("error");
      head_index[0] = readrel159->getIndex(ord158, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask157(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask157* _cont = new ReadTask157(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask157(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre7BV6119 __errf3aE0120 __errf8OdV121) (body) (head (emit error (0) __erre7BV6119)) <internal>:1 #f)
  class ReadTask160 : public slog::Task
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
      std::vector<u16> ord161({0});
      slog::Relation* readrel162 = db->getRelation("error");
      head_index[0] = readrel162->getIndex(ord161, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask160(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c28}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask160* _cont = new ReadTask160(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask160(db,b), false);
  // (crule (pre (let __tconst5LQZ68 constab76c7d069d6f33dc950fb33) (let __tconst5jPI52 const4e07408562bedb8b60ce05c1) (let __t08Pw50 (cmap))) (scan reach_has s a) (body (exists ic (1 0) 1 __tconst5jPI52) (exists sedge (0 2 1) 1 a) (join _enum (1 0) 1 __tconst5LQZ68 __v0) (join-old smt_check_ans (1 0) 1 (1 0) __v0 __t8FKp56) (join-old ic (1 0) 1 (1 0) __tconst5jPI52 __t57FM53) (exists llt (2 0 1) 1 __t57FM53) (join-old smt_check (0 1) 1 (0 1) __t8FKp56 __t5Ajn55) (join-old llt (0 2 1) 2 (0 2 1) __t5Ajn55 __t57FM53 __t4pFy54) (join-old ic (0 1) 1 (0 1) __t4pFy54 g) (join sedge (0 2 1) 2 a g b) (let __t5nOz51 (cins __t08Pw50 b))) (head (emit-lat reach s __t5nOz51)) smt_rhas.slog:32 #f)
  class ReadTask178 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex163;  slog::Index** sedgeindex164;  slog::Index** _enumindex165;  slog::Index** smt_check_ansindex166;  slog::Index** icindex167;  slog::Index** lltindex168;  slog::Index** smt_checkindex169;  slog::Index** lltindex170;  slog::Index** icindex171;  slog::Index** sedgeindex172;  slog::Index** smt_check_ansdelta173;  slog::Index** icdelta174;  slog::Index** smt_checkdelta175;  slog::Index** lltdelta176;  slog::Index** icdelta177;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      outer_rel = db->getRelation("reach_has");
      std::vector<u16> ord179({1, 0});
      slog::Relation* readrel180 = db->getRelation("ic");
      icindex163 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({0, 2, 1});
      slog::Relation* readrel182 = db->getRelation("sedge");
      sedgeindex164 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 0});
      slog::Relation* readrel184 = db->getRelation("_enum");
      _enumindex165 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 0});
      slog::Relation* readrel186 = db->getRelation("smt_check_ans");
      smt_check_ansindex166 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 0});
      slog::Relation* readrel188 = db->getRelation("smt_check_ans");
      smt_check_ansdelta173 = readrel188->getIndex(ord187, true);
      std::vector<u16> ord189({1, 0});
      slog::Relation* readrel190 = db->getRelation("ic");
      icindex167 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 0});
      slog::Relation* readrel192 = db->getRelation("ic");
      icdelta174 = readrel192->getIndex(ord191, true);
      std::vector<u16> ord193({2, 0, 1});
      slog::Relation* readrel194 = db->getRelation("llt");
      lltindex168 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({0, 1});
      slog::Relation* readrel196 = db->getRelation("smt_check");
      smt_checkindex169 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("smt_check");
      smt_checkdelta175 = readrel198->getIndex(ord197, true);
      std::vector<u16> ord199({0, 2, 1});
      slog::Relation* readrel200 = db->getRelation("llt");
      lltindex170 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({0, 2, 1});
      slog::Relation* readrel202 = db->getRelation("llt");
      lltdelta176 = readrel202->getIndex(ord201, true);
      std::vector<u16> ord203({0, 1});
      slog::Relation* readrel204 = db->getRelation("ic");
      icindex171 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({0, 1});
      slog::Relation* readrel206 = db->getRelation("ic");
      icdelta177 = readrel206->getIndex(ord205, true);
      std::vector<u16> ord207({0, 2, 1});
      slog::Relation* readrel208 = db->getRelation("sedge");
      sedgeindex172 = readrel208->getIndex(ord207, false);
  
    }
    ReadTask178(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = _prim_cmap(db);
      if (v_c2 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c9 = _t[1];
        if (!slog::exists_probe<2,1>(icindex163, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(sedgeindex164, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex165, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m209) {
          u64 v_c5 = m209[1];
          slog::join_probe_old<2,1>(smt_check_ansindex166, smt_check_ansdelta173, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m210) {
            u64 v_c6 = m210[1];
            slog::join_probe_old<2,1>(icindex167, icdelta174, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m211) {
              u64 v_c7 = m211[1];
              if (!slog::exists_probe<3,1>(lltindex168, std::array<u64,3>{v_c7, 0, 0})) return;
              slog::join_probe_old<2,1>(smt_checkindex169, smt_checkdelta175, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m212) {
                u64 v_c8 = m212[1];
                slog::join_probe_old<3,2>(lltindex170, lltdelta176, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m213) {
                  u64 v_c3 = m213[2];
                  slog::join_probe_old<2,1>(icindex171, icdelta177, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m214) {
                    u64 v_c4 = m214[1];
                    slog::join_probe<3,2>(sedgeindex172, std::array<u64,3>{v_c9, v_c4, 0}, [&](const std::array<u64,3>& m215) {
                      u64 v_c10 = m215[2];
                      u64 v_c12 = _prim_cins(db, v_c2, v_c10);
                      if (v_c12 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return; }
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c12});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:32", "delta:reach_has", _fires);
  
      if (!_done)
      {
        ReadTask178* _cont = new ReadTask178(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask178(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre32gZ138 __errf3AZi139 __errf1Kfs140 __errf1sfv141 __errf7Q2C142) (body) (head (emit error (0) __erre32gZ138)) <internal>:1 #f)
  class ReadTask216 : public slog::Task
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
      std::vector<u16> ord217({0});
      slog::Relation* readrel218 = db->getRelation("error");
      head_index[0] = readrel218->getIndex(ord217, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask216(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[2];
        u64 v_c34 = _t[3];
        u64 v_c35 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c31}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask216* _cont = new ReadTask216(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask216(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre45PK143 __errf2QCQ144 __errf1f2S145) (body) (head (emit error (0) __erre45PK143)) <internal>:1 #f)
  class ReadTask219 : public slog::Task
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
      std::vector<u16> ord220({0});
      slog::Relation* readrel221 = db->getRelation("error");
      head_index[0] = readrel221->getIndex(ord220, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c38 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c36}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask219* _cont = new ReadTask219(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask219(db,b), false);
  // (crule (pre) (scan smt_qsat __t3s8b2 F) (body (exists smt_check (1 0) 1 F) (join smt_qsat_ans (0 1) 1 __t3s8b2 C) (join smt_vcode (0 1) 1 C V) (join smt_check (1 0) 1 F __t5xkK1)) (head (emit smt_check_ans (0 1) __t5xkK1 V)) smt.slog:69 #f)
  class ReadTask226 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_checkindex222;  slog::Index** smt_qsat_ansindex223;  slog::Index** smt_vcodeindex224;  slog::Index** smt_checkindex225;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check_ans");
      std::vector<u16> ord227({0, 1});
      slog::Relation* readrel228 = db->getRelation("smt_check_ans");
      head_index[0] = readrel228->getIndex(ord227, false);
      outer_rel = db->getRelation("smt_qsat");
      std::vector<u16> ord229({1, 0});
      slog::Relation* readrel230 = db->getRelation("smt_check");
      smt_checkindex222 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 1});
      slog::Relation* readrel232 = db->getRelation("smt_qsat_ans");
      smt_qsat_ansindex223 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 1});
      slog::Relation* readrel234 = db->getRelation("smt_vcode");
      smt_vcodeindex224 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 0});
      slog::Relation* readrel236 = db->getRelation("smt_check");
      smt_checkindex225 = readrel236->getIndex(ord235, false);
  
    }
    ReadTask226(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[0];
        u64 v_c16 = _t[1];
        if (!slog::exists_probe<2,1>(smt_checkindex222, std::array<u64,2>{v_c16, 0})) return;
        slog::join_probe<2,1>(smt_qsat_ansindex223, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m237) {
          u64 v_c14 = m237[1];
          slog::join_probe<2,1>(smt_vcodeindex224, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m238) {
            u64 v_c15 = m238[1];
            slog::join_probe<2,1>(smt_checkindex225, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m239) {
              u64 v_c17 = m239[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c17, v_c15}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_qsat", _fires);
  
      if (!_done)
      {
        ReadTask226* _cont = new ReadTask226(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask226(db,b), false);
  // (crule (pre) (scan smt_bad_formula __erre9Uqw146 __errf8p7I147 __errf62H7148) (body) (head (emit error (0) __erre9Uqw146)) <internal>:1 #f)
  class ReadTask240 : public slog::Task
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
      std::vector<u16> ord241({0});
      slog::Relation* readrel242 = db->getRelation("error");
      head_index[0] = readrel242->getIndex(ord241, false);
      outer_rel = db->getRelation("smt_bad_formula");
  
    }
    ReadTask240(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c41 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:smt_bad_formula", _fires);
  
      if (!_done)
      {
        ReadTask240* _cont = new ReadTask240(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask240(db,b), false);
  // (crule (pre) (scan int_overflow __erre3E0K122 __errf2MUw123 __errf24aR124 __errf7D0x125) (body) (head (emit error (0) __erre3E0K122)) <internal>:1 #f)
  class ReadTask243 : public slog::Task
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
      std::vector<u16> ord244({0});
      slog::Relation* readrel245 = db->getRelation("error");
      head_index[0] = readrel245->getIndex(ord244, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask243(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c42 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c44 = _t[2];
        u64 v_c45 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c42}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask243* _cont = new ReadTask243(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask243(db,b), false);
  // (crule (pre (let __tconst5LQZ68 constab76c7d069d6f33dc950fb33) (let __tconst5jPI52 const4e07408562bedb8b60ce05c1) (let __t08Pw50 (cmap))) (scan smt_check_ans __t8FKp56 __v0) (body (join _enum (0 1) 2 __v0 __tconst5LQZ68) (join-old ic (1 0) 1 (1 0) __tconst5jPI52 __t57FM53) (exists llt (2 0 1) 1 __t57FM53) (join-old smt_check (0 1) 1 (0 1) __t8FKp56 __t5Ajn55) (join-old llt (0 2 1) 2 (0 2 1) __t5Ajn55 __t57FM53 __t4pFy54) (join-old ic (0 1) 1 (0 1) __t4pFy54 g) (join sedge (2 0 1) 1 g a b) (join reach_has (1 0) 1 a s) (let __t5nOz51 (cins __t08Pw50 b))) (head (emit-lat reach s __t5nOz51)) smt_rhas.slog:32 #f)
  class ReadTask258 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex246;  slog::Index** icindex247;  slog::Index** lltindex248;  slog::Index** smt_checkindex249;  slog::Index** lltindex250;  slog::Index** icindex251;  slog::Index** sedgeindex252;  slog::Index** reach_hasindex253;  slog::Index** icdelta254;  slog::Index** smt_checkdelta255;  slog::Index** lltdelta256;  slog::Index** icdelta257;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      outer_rel = db->getRelation("smt_check_ans");
      std::vector<u16> ord259({0, 1});
      slog::Relation* readrel260 = db->getRelation("_enum");
      _enumindex246 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 0});
      slog::Relation* readrel262 = db->getRelation("ic");
      icindex247 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 0});
      slog::Relation* readrel264 = db->getRelation("ic");
      icdelta254 = readrel264->getIndex(ord263, true);
      std::vector<u16> ord265({2, 0, 1});
      slog::Relation* readrel266 = db->getRelation("llt");
      lltindex248 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({0, 1});
      slog::Relation* readrel268 = db->getRelation("smt_check");
      smt_checkindex249 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({0, 1});
      slog::Relation* readrel270 = db->getRelation("smt_check");
      smt_checkdelta255 = readrel270->getIndex(ord269, true);
      std::vector<u16> ord271({0, 2, 1});
      slog::Relation* readrel272 = db->getRelation("llt");
      lltindex250 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({0, 2, 1});
      slog::Relation* readrel274 = db->getRelation("llt");
      lltdelta256 = readrel274->getIndex(ord273, true);
      std::vector<u16> ord275({0, 1});
      slog::Relation* readrel276 = db->getRelation("ic");
      icindex251 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("ic");
      icdelta257 = readrel278->getIndex(ord277, true);
      std::vector<u16> ord279({2, 0, 1});
      slog::Relation* readrel280 = db->getRelation("sedge");
      sedgeindex252 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 0});
      slog::Relation* readrel282 = db->getRelation("reach_has");
      reach_hasindex253 = readrel282->getIndex(ord281, false);
  
    }
    ReadTask258(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = _prim_cmap(db);
      if (v_c2 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<2,2>(_enumindex246, std::array<u64,2>{v_c5, v_c0}, [&](const std::array<u64,2>& m283) {
          slog::join_probe_old<2,1>(icindex247, icdelta254, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m284) {
            u64 v_c7 = m284[1];
            if (!slog::exists_probe<3,1>(lltindex248, std::array<u64,3>{v_c7, 0, 0})) return;
            slog::join_probe_old<2,1>(smt_checkindex249, smt_checkdelta255, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m285) {
              u64 v_c8 = m285[1];
              slog::join_probe_old<3,2>(lltindex250, lltdelta256, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m286) {
                u64 v_c3 = m286[2];
                slog::join_probe_old<2,1>(icindex251, icdelta257, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m287) {
                  u64 v_c4 = m287[1];
                  slog::join_probe<3,1>(sedgeindex252, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m288) {
                    u64 v_c9 = m288[1]; u64 v_c10 = m288[2];
                    slog::join_probe<2,1>(reach_hasindex253, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m289) {
                      u64 v_c11 = m289[1];
                      u64 v_c12 = _prim_cins(db, v_c2, v_c10);
                      if (v_c12 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return; }
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c12});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:32", "delta:smt_check_ans", _fires);
  
      if (!_done)
      {
        ReadTask258* _cont = new ReadTask258(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask258(db,b), false);
  // (crule (pre) (scan div_by_zero __erre37JA116 __errf2mkP117 __errf9PSd118) (body) (head (emit error (0) __erre37JA116)) <internal>:1 #f)
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
      outer_rel = db->getRelation("div_by_zero");
  
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
        u64 v_c46 = _t[0];
        u64 v_c47 = _t[1];
        u64 v_c48 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c46}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre) (scan smt_check __t5xkK1 F) (body (join-old smt_qsat (1 0) 1 (1 0) F __t3s8b2) (join smt_qsat_ans (0 1) 1 __t3s8b2 C) (join smt_vcode (0 1) 1 C V)) (head (emit smt_check_ans (0 1) __t5xkK1 V)) smt.slog:69 #f)
  class ReadTask297 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_qsatindex293;  slog::Index** smt_qsat_ansindex294;  slog::Index** smt_vcodeindex295;  slog::Index** smt_qsatdelta296;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check_ans");
      std::vector<u16> ord298({0, 1});
      slog::Relation* readrel299 = db->getRelation("smt_check_ans");
      head_index[0] = readrel299->getIndex(ord298, false);
      outer_rel = db->getRelation("smt_check");
      std::vector<u16> ord300({1, 0});
      slog::Relation* readrel301 = db->getRelation("smt_qsat");
      smt_qsatindex293 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 0});
      slog::Relation* readrel303 = db->getRelation("smt_qsat");
      smt_qsatdelta296 = readrel303->getIndex(ord302, true);
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("smt_qsat_ans");
      smt_qsat_ansindex294 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("smt_vcode");
      smt_vcodeindex295 = readrel307->getIndex(ord306, false);
  
    }
    ReadTask297(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[1];
        slog::join_probe_old<2,1>(smt_qsatindex293, smt_qsatdelta296, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m308) {
          u64 v_c13 = m308[1];
          slog::join_probe<2,1>(smt_qsat_ansindex294, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m309) {
            u64 v_c14 = m309[1];
            slog::join_probe<2,1>(smt_vcodeindex295, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m310) {
              u64 v_c15 = m310[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c17, v_c15}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:69", "delta:smt_check", _fires);
  
      if (!_done)
      {
        ReadTask297* _cont = new ReadTask297(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask297(db,b), false);
  // (crule (pre (let __tconst8uXk40 const4e07408562bedb8b60ce05c1)) (scan temp87TC150 __t79DW42) (body (exists llt (1 2 0) 1 __t79DW42) (join ic (1 0) 1 __tconst8uXk40 __t3n7R41) (join llt (1 2 0) 2 __t79DW42 __t3n7R41 __t2cQS43)) (head (mkstruct smt_check (1 0) __9RHN67 __t2cQS43)) smt_rhas.slog:32 #f)
  class ReadTask314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lltindex311;  slog::Index** icindex312;  slog::Index** lltindex313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("temp87TC150");
      std::vector<u16> ord315({1, 2, 0});
      slog::Relation* readrel316 = db->getRelation("llt");
      lltindex311 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 0});
      slog::Relation* readrel318 = db->getRelation("ic");
      icindex312 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 2, 0});
      slog::Relation* readrel320 = db->getRelation("llt");
      lltindex313 = readrel320->getIndex(ord319, false);
  
    }
    ReadTask314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c50 = _t[0];
        if (!slog::exists_probe<3,1>(lltindex311, std::array<u64,3>{v_c50, 0, 0})) return;
        slog::join_probe<2,1>(icindex312, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m321) {
          u64 v_c51 = m321[1];
          slog::join_probe<3,2>(lltindex313, std::array<u64,3>{v_c50, v_c51, 0}, [&](const std::array<u64,3>& m322) {
            u64 v_c52 = m322[2];
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c52}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:32", "delta:temp87TC150", _fires);
  
      if (!_done)
      {
        ReadTask314* _cont = new ReadTask314(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask314(db,b), false);
  // (crule (pre (let __t22ks17 (cmap))) (scan src s) (body (let __t6sUo18 (cins __t22ks17 s))) (head (emit-lat reach s __t6sUo18)) smt_rhas.slog:25 #f)
  class ReadTask323 : public slog::Task
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
      head_rel[0] = db->getRelation("reach");
      outer_rel = db->getRelation("src");
  
    }
    ReadTask323(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c53 = _prim_cmap(db);
      if (v_c53 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:25"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c54 = _prim_cins(db, v_c53, v_c11);
        if (v_c54 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:25"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c54});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:25", "all:src", _fires);
  
      if (!_done)
      {
        ReadTask323* _cont = new ReadTask323(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask323(db,b), true);
  // (crule (pre (let __tconst5LQZ68 constab76c7d069d6f33dc950fb33) (let __tconst5jPI52 const4e07408562bedb8b60ce05c1) (let __t08Pw50 (cmap))) (scan llt __t5Ajn55 __t4pFy54 __t57FM53) (body (join ic (0 1) 2 __t57FM53 __tconst5jPI52) (exists smt_check (1 0) 1 __t5Ajn55) (join _enum (1 0) 1 __tconst5LQZ68 __v0) (join smt_check_ans (1 0) 1 __v0 __t8FKp56) (join-old smt_check (0 1) 2 (0 1) __t8FKp56 __t5Ajn55) (join ic (0 1) 1 __t4pFy54 g) (join sedge (2 0 1) 1 g a b) (join reach_has (1 0) 1 a s) (let __t5nOz51 (cins __t08Pw50 b))) (head (emit-lat reach s __t5nOz51)) smt_rhas.slog:32 #f)
  class ReadTask333 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex324;  slog::Index** smt_checkindex325;  slog::Index** _enumindex326;  slog::Index** smt_check_ansindex327;  slog::Index** smt_checkindex328;  slog::Index** icindex329;  slog::Index** sedgeindex330;  slog::Index** reach_hasindex331;  slog::Index** smt_checkdelta332;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      outer_rel = db->getRelation("llt");
      std::vector<u16> ord334({0, 1});
      slog::Relation* readrel335 = db->getRelation("ic");
      icindex324 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 0});
      slog::Relation* readrel337 = db->getRelation("smt_check");
      smt_checkindex325 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 0});
      slog::Relation* readrel339 = db->getRelation("_enum");
      _enumindex326 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({1, 0});
      slog::Relation* readrel341 = db->getRelation("smt_check_ans");
      smt_check_ansindex327 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({0, 1});
      slog::Relation* readrel343 = db->getRelation("smt_check");
      smt_checkindex328 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({0, 1});
      slog::Relation* readrel345 = db->getRelation("smt_check");
      smt_checkdelta332 = readrel345->getIndex(ord344, true);
      std::vector<u16> ord346({0, 1});
      slog::Relation* readrel347 = db->getRelation("ic");
      icindex329 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({2, 0, 1});
      slog::Relation* readrel349 = db->getRelation("sedge");
      sedgeindex330 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 0});
      slog::Relation* readrel351 = db->getRelation("reach_has");
      reach_hasindex331 = readrel351->getIndex(ord350, false);
  
    }
    ReadTask333(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constab76c7d069d6f33dc950fb33;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = _prim_cmap(db);
      if (v_c2 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c8 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe<2,2>(icindex324, std::array<u64,2>{v_c7, v_c1}, [&](const std::array<u64,2>& m352) {
          if (!slog::exists_probe<2,1>(smt_checkindex325, std::array<u64,2>{v_c8, 0})) return;
          slog::join_probe<2,1>(_enumindex326, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m353) {
            u64 v_c5 = m353[1];
            slog::join_probe<2,1>(smt_check_ansindex327, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m354) {
              u64 v_c6 = m354[1];
              slog::join_probe_old<2,2>(smt_checkindex328, smt_checkdelta332, std::array<u64,2>{v_c6, v_c8}, [&](const std::array<u64,2>& m355) {
                slog::join_probe<2,1>(icindex329, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m356) {
                  u64 v_c4 = m356[1];
                  slog::join_probe<3,1>(sedgeindex330, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m357) {
                    u64 v_c9 = m357[1]; u64 v_c10 = m357[2];
                    slog::join_probe<2,1>(reach_hasindex331, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m358) {
                      u64 v_c11 = m358[1];
                      u64 v_c12 = _prim_cins(db, v_c2, v_c10);
                      if (v_c12 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return; }
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c12});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:32", "delta:llt", _fires);
  
      if (!_done)
      {
        ReadTask333* _cont = new ReadTask333(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask333(db,b), false);
  // (crule (pre) (scan nan_result __erre2Uwb126 __errf9cBF127 __errf3Swx128 __errf9Gid129) (body) (head (emit error (0) __erre2Uwb126)) <internal>:1 #f)
  class ReadTask359 : public slog::Task
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
      std::vector<u16> ord360({0});
      slog::Relation* readrel361 = db->getRelation("error");
      head_index[0] = readrel361->getIndex(ord360, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask359(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c57 = _t[2];
        u64 v_c58 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c55}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask359* _cont = new ReadTask359(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask359(db,b), false);
  // (crule (pre (let __tconst8uXk40 const4e07408562bedb8b60ce05c1)) (scan temp6PBR149 g) (body (exists ic (1 0) 1 __tconst8uXk40) (join ic (1 0) 1 g __t79DW42) (join ic (1 0) 1 __tconst8uXk40 __t3n7R41)) (head (emit-temp temp87TC150 __t79DW42) (mkstruct llt (1 2 0) __t2cQS43 __t79DW42 __t3n7R41)) smt_rhas.slog:32 #f)
  class ReadTask365 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex362;  slog::Index** icindex363;  slog::Index** icindex364;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp87TC150");
      head_rel[1] = db->getRelation("llt");
      outer_rel = db->getRelation("temp6PBR149");
      std::vector<u16> ord366({1, 0});
      slog::Relation* readrel367 = db->getRelation("ic");
      icindex362 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({1, 0});
      slog::Relation* readrel369 = db->getRelation("ic");
      icindex363 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({1, 0});
      slog::Relation* readrel371 = db->getRelation("ic");
      icindex364 = readrel371->getIndex(ord370, false);
  
    }
    ReadTask365(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c4 = _t[0];
        if (!slog::exists_probe<2,1>(icindex362, std::array<u64,2>{v_c49, 0})) return;
        slog::join_probe<2,1>(icindex363, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m372) {
          u64 v_c50 = m372[1];
          slog::join_probe<2,1>(icindex364, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m373) {
            u64 v_c51 = m373[1];
            ++_fires;
            slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c50});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c50, v_c51}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:32", "delta:temp6PBR149", _fires);
  
      if (!_done)
      {
        ReadTask365* _cont = new ReadTask365(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask365(db,b), false);
  // (crule (pre (let __t5KCa7 (cmap))) (scan reach_has s a) (body (join edge (0 1) 1 a b) (let __t7rmc8 (cins __t5KCa7 b))) (head (emit-lat reach s __t7rmc8)) smt_rhas.slog:28 #f)
  class ReadTask375 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** edgeindex374;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("reach");
      outer_rel = db->getRelation("reach_has");
      std::vector<u16> ord376({0, 1});
      slog::Relation* readrel377 = db->getRelation("edge");
      edgeindex374 = readrel377->getIndex(ord376, false);
  
    }
    ReadTask375(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c59 = _prim_cmap(db);
      if (v_c59 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:28"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c9 = _t[1];
        slog::join_probe<2,1>(edgeindex374, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m378) {
          u64 v_c10 = m378[1];
          u64 v_c60 = _prim_cins(db, v_c59, v_c10);
          if (v_c60 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:28"); return; }
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c60});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:28", "delta:reach_has", _fires);
  
      if (!_done)
      {
        ReadTask375* _cont = new ReadTask375(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask375(db,b), false);
  // (crule (pre) (scan smt_vcode C V) (body (join smt_model (0 1) 0 __t531x59 F)) (head (mkstruct smt_qmodel (1 0) __4W5262 F)) smt.slog:93 #f)
  class ReadTask380 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** smt_modelindex379;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_qmodel");
      outer_rel = db->getRelation("smt_vcode");
      std::vector<u16> ord381({0, 1});
      slog::Relation* readrel382 = db->getRelation("smt_model");
      smt_modelindex379 = readrel382->getIndex(ord381, false);
  
    }
    ReadTask380(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[0];
        u64 v_c15 = _t[1];
        slog::join_all<2>(smt_modelindex379, [&](const std::array<u64,2>& m383) {
          u64 v_c61 = m383[0]; u64 v_c16 = m383[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt.slog:93", "all:smt_vcode", _fires);
  
      if (!_done)
      {
        ReadTask380* _cont = new ReadTask380(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask380(db,b), true);
  // (crule (pre (let __tconst8uXk40 const4e07408562bedb8b60ce05c1) (let __t6f7p44 (cmap))) (scan reach_has s a) (body (join sedge (0 2 1) 1 a g b) (let __t4UuK45 (cins __t6f7p44 b))) (head (emit-temp temp6PBR149 g) (mkstruct ic (1 0) __t3n7R41 __tconst8uXk40) (mkstruct ic (1 0) __t79DW42 g)) smt_rhas.slog:32 #f)
  class ReadTask385 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** sedgeindex384;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6PBR149");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
      outer_rel = db->getRelation("reach_has");
      std::vector<u16> ord386({0, 2, 1});
      slog::Relation* readrel387 = db->getRelation("sedge");
      sedgeindex384 = readrel387->getIndex(ord386, false);
  
    }
    ReadTask385(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c62 = _prim_cmap(db);
      if (v_c62 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return true; }
  
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
        u64 v_c11 = _t[0];
        u64 v_c9 = _t[1];
        slog::join_probe<3,1>(sedgeindex384, std::array<u64,3>{v_c9, 0, 0}, [&](const std::array<u64,3>& m388) {
          u64 v_c4 = m388[1]; u64 v_c10 = m388[2];
          u64 v_c63 = _prim_cins(db, v_c62, v_c10);
          if (v_c63 == slog_error) { slog::emit_pending_error(db, "smt_rhas.slog:32"); return; }
          ++_fires;
          slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c4});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c49}, std::array<u16,2>{1, 0});
          slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_rhas.slog:32", "delta:reach_has", _fires);
  
      if (!_done)
      {
        ReadTask385* _cont = new ReadTask385(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask385(db,b), false);
  s->addReadRel("_enum");
  s->addReadRel("div_by_zero");
  s->addReadRel("edge");
  s->addReadRel("ic");
  s->addReadRel("int_overflow");
  s->addReadRel("llt");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("reach_has");
  s->addReadRel("sedge");
  s->addReadRel("smt_bad_formula");
  s->addReadRel("smt_check");
  s->addReadRel("smt_check_ans");
  s->addReadRel("smt_core");
  s->addReadRel("smt_model");
  s->addReadRel("smt_qsat");
  s->addReadRel("smt_qsat_ans");
  s->addReadRel("smt_vcode");
  s->addReadRel("src");
  s->addReadRel("temp6PBR149");
  s->addReadRel("temp87TC150");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("ic");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("llt");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("reach");
  s->addDynamicRel("reach_has");
  s->addDynamicRel("smt_bad_formula");
  s->addDynamicRel("smt_check");
  s->addDynamicRel("smt_check_ans");
  s->addDynamicRel("smt_qcore");
  s->addDynamicRel("smt_qcore_ans");
  s->addDynamicRel("smt_qmodel");
  s->addDynamicRel("smt_qmodel_ans");
  s->addDynamicRel("smt_qsat");
  s->addDynamicRel("smt_qsat_ans");
  s->addDynamicRel("temp6PBR149");
  s->addDynamicRel("temp87TC150");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

