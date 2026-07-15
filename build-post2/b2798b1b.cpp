
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const1f503613ae12cc0c5121fd74;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("b2798b1b");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const1f503613ae12cc0c5121fd74 = db->encodeString("mt");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord335({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord335, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord336({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord336, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord337({1, 2, 0});
    
    r->addIndex<3>(ord337, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord338({0, 1, 2});
    
    r->addIndex<3>(ord338, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp84uP133");
  if (r == 0) db->addTempRelation("temp84uP133", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord339({1, 2, 0});
    
    r->addIndex<3>(ord339, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord340({0, 1, 2});
    
    r->addIndex<3>(ord340, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("root");
  if (r == 0) db->addRelation("root", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("root");
      std::vector<u16> ord341({0, 1});
    
    r->addIndex<2>(ord341, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("root"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("res");
  if (r == 0) db->addRelation("res", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("res");
      std::vector<u16> ord342({0, 1});
    
    r->addIndex<2>(ord342, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("res"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord343({1, 0});
    
    r->addIndex<2>(ord343, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord344({0, 1});
    
    r->addIndex<2>(ord344, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("need");
  if (r == 0) db->addRelation("need", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("need");
      std::vector<u16> ord345({0, 1});
    
    r->addIndex<2>(ord345, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord346({1, 0});
    
    r->addIndex<2>(ord346, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord347({1, 0});
    
    r->addIndex<2>(ord347, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("need"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord348({1, 2, 3, 0});
    
    r->addIndex<4>(ord348, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord349({0, 1, 2, 3});
    
    r->addIndex<4>(ord349, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord350({1, 2, 0});
    
    r->addIndex<3>(ord350, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord351({0, 1, 2});
    
    r->addIndex<3>(ord351, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord352({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord352, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord353({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord353, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord354({1, 2, 0});
    
    r->addIndex<3>(ord354, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord355({0, 1, 2});
    
    r->addIndex<3>(ord355, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord356({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord356, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord357({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord357, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lookup");
  if (r == 0) db->addRelation("lookup", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lookup");
      std::vector<u16> ord358({0, 1, 2});
    
    r->addIndex<3>(ord358, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord359({0, 1, 2});
    
    r->addIndex<3>(ord359, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("lookup"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("lit");
  if (r == 0) db->addStruct("lit", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lit");
      std::vector<u16> ord360({1, 0});
    
    r->addIndex<2>(ord360, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord361({0, 1});
    
    r->addIndex<2>(ord361, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lit"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord362({1, 2, 3, 0});
    
    r->addIndex<4>(ord362, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord363({0, 1, 2, 3});
    
    r->addIndex<4>(ord363, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ev");
  if (r == 0) db->addRelation("ev", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ev");
      std::vector<u16> ord364({0, 1, 2});
    
    r->addIndex<3>(ord364, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord365({1, 2, 0});
    
    r->addIndex<3>(ord365, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), false);
      std::vector<u16> ord366({0, 1, 2});
    
    r->addIndex<3>(ord366, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord367({1, 2, 0});
    
    r->addIndex<3>(ord367, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("ev"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord368({0});
    
    r->addIndex<1>(ord368, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("elet");
  if (r == 0) db->addStruct("elet", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("elet");
      std::vector<u16> ord369({1, 2, 3, 0});
    
    r->addIndex<4>(ord369, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord370({0, 2, 1, 3});
    
    r->addIndex<4>(ord370, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 2, 1, 3}, false, b), false);
      std::vector<u16> ord371({2, 0, 1, 3});
    
    r->addIndex<4>(ord371, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 0, 1, 3}, false, b), false);
      std::vector<u16> ord372({3, 0, 1, 2});
    
    r->addIndex<4>(ord372, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("elet"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord373({1, 2, 0});
    
    r->addIndex<3>(ord373, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord374({0, 1, 2});
    
    r->addIndex<3>(ord374, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bind");
  if (r == 0) db->addStruct("bind", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bind");
      std::vector<u16> ord375({3, 2, 1, 0});
    
    r->addIndex<4>(ord375, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 2, 1, 0}, false, b), true);
      std::vector<u16> ord376({0, 1, 2, 3});
    
    r->addIndex<4>(ord376, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord377({0, 1, 2, 3});
    
    r->addIndex<4>(ord377, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, true, b), false);
      std::vector<u16> ord378({3, 2, 1, 0});
    
    r->addIndex<4>(ord378, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 2, 1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("bind"), std::array<u16,4>{3, 2, 1, 0}, b));
  r = db->getRelation("add");
  if (r == 0) db->addStruct("add", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("add");
      std::vector<u16> ord379({1, 2, 0});
    
    r->addIndex<3>(ord379, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord380({0, 1, 2});
    
    r->addIndex<3>(ord380, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord381({2, 0, 1});
    
    r->addIndex<3>(ord381, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("add"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord382({1, 0});
    
    r->addIndex<2>(ord382, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord383({0, 1});
    
    r->addIndex<2>(ord383, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord384({1, 0});
    
    r->addIndex<2>(ord384, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre) (scan mpz_overflow __erre3MtL125 __errf32gr126 __errf8eWm127 __errf4mU6128 __errf1Hca129) (body) (head (emit error (0) __erre3MtL125)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c4 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre) (scan ev e1 rho w1) (body (exists elet (2 0 1 3) 1 e1) (exists need (1 0) 1 rho) (join-old bind (3 2 1 0) 2 (3 2 1 0) rho w1 nm __t9AKq52) (exists ev (1 2 0) 1 __t9AKq52) (join elet (1 2 3 0) 2 nm e1 e2 __t8R2A51) (join need (0 1) 2 __t8R2A51 rho) (join-old ev (0 1 2) 2 (0 1 2) e2 __t9AKq52 w2)) (head (emit ev (0 1 2) __t8R2A51 rho w2)) ex_let.slog:35 #f)
  class ReadTask12 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eletindex3;  slog::Index** needindex4;  slog::Index** bindindex5;  slog::Index** evindex6;  slog::Index** eletindex7;  slog::Index** needindex8;  slog::Index** evindex9;  slog::Index** binddelta10;  slog::Index** evdelta11;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord13({0, 1, 2});
      slog::Relation* readrel14 = db->getRelation("ev");
      head_index[0] = readrel14->getIndex(ord13, false);
      outer_rel = db->getRelation("ev");
      std::vector<u16> ord15({2, 0, 1, 3});
      slog::Relation* readrel16 = db->getRelation("elet");
      eletindex3 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 0});
      slog::Relation* readrel18 = db->getRelation("need");
      needindex4 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({3, 2, 1, 0});
      slog::Relation* readrel20 = db->getRelation("bind");
      bindindex5 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({3, 2, 1, 0});
      slog::Relation* readrel22 = db->getRelation("bind");
      binddelta10 = readrel22->getIndex(ord21, true);
      std::vector<u16> ord23({1, 2, 0});
      slog::Relation* readrel24 = db->getRelation("ev");
      evindex6 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 2, 3, 0});
      slog::Relation* readrel26 = db->getRelation("elet");
      eletindex7 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({0, 1});
      slog::Relation* readrel28 = db->getRelation("need");
      needindex8 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({0, 1, 2});
      slog::Relation* readrel30 = db->getRelation("ev");
      evindex9 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({0, 1, 2});
      slog::Relation* readrel32 = db->getRelation("ev");
      evdelta11 = readrel32->getIndex(ord31, true);
  
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
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<4,1>(eletindex3, std::array<u64,4>{v_c5, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(needindex4, std::array<u64,2>{v_c6, 0})) return;
        slog::join_probe_old<4,2>(bindindex5, binddelta10, std::array<u64,4>{v_c6, v_c7, 0, 0}, [&](const std::array<u64,4>& m33) {
          u64 v_c8 = m33[2]; u64 v_c9 = m33[3];
          if (!slog::exists_probe<3,1>(evindex6, std::array<u64,3>{v_c9, 0, 0})) return;
          slog::join_probe<4,2>(eletindex7, std::array<u64,4>{v_c8, v_c5, 0, 0}, [&](const std::array<u64,4>& m34) {
            u64 v_c10 = m34[2]; u64 v_c11 = m34[3];
            slog::join_probe<2,2>(needindex8, std::array<u64,2>{v_c11, v_c6}, [&](const std::array<u64,2>& m35) {
              slog::join_probe_old<3,2>(evindex9, evdelta11, std::array<u64,3>{v_c10, v_c9, 0}, [&](const std::array<u64,3>& m36) {
                u64 v_c12 = m36[2];
                ++_fires;
                slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c11, v_c6, v_c12}, std::array<u16,3>{0, 1, 2});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:35", "delta:ev", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre5Ada106 __errf2yuj107 __errf1YjC108) (body) (head (emit error (0) __erre5Ada106)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord38({0});
      slog::Relation* readrel39 = db->getRelation("error");
      head_index[0] = readrel39->getIndex(ord38, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
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
        u64 v_c13 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c15 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
      s->addTask(phase_read, new ReadTask37(db,b), false);
  // (crule (pre) (scan lookup rest nm w) (body (join-old bind (3 2 1 0) 1 (3 2 1 0) rest ____6j2k47 other __t5FRN46) (neq nm other)) (head (emit lookup (0 1 2) __t5FRN46 nm w)) ex_let.slog:41 #f)
  class ReadTask42 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindindex40;  slog::Index** binddelta41;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup");
      std::vector<u16> ord43({0, 1, 2});
      slog::Relation* readrel44 = db->getRelation("lookup");
      head_index[0] = readrel44->getIndex(ord43, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord45({3, 2, 1, 0});
      slog::Relation* readrel46 = db->getRelation("bind");
      bindindex40 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({3, 2, 1, 0});
      slog::Relation* readrel48 = db->getRelation("bind");
      binddelta41 = readrel48->getIndex(ord47, true);
  
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
        u64 v_c16 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe_old<4,1>(bindindex40, binddelta41, std::array<u64,4>{v_c16, 0, 0, 0}, [&](const std::array<u64,4>& m49) {
          u64 v_c18 = m49[1]; u64 v_c19 = m49[2]; u64 v_c20 = m49[3];
          if (v_c8 == v_c19) return;
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c20, v_c8, v_c17}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:41", "delta:lookup", _fires);
  
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
  // (crule (pre) (scan need __t0FJ656 rho) (body (exists ev (1 2 0) 1 rho) (join-old ev (1 2 0) 1 (1 2 0) rho wa a) (join add (0 1 2) 2 __t0FJ656 a b) (join-old ev (0 1 2) 2 (0 1 2) b rho wb) (let __t5MpC57 (_0002b wa wb))) (head (emit ev (0 1 2) __t0FJ656 rho __t5MpC57)) ex_let.slog:32 #f)
  class ReadTask56 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evindex50;  slog::Index** evindex51;  slog::Index** addindex52;  slog::Index** evindex53;  slog::Index** evdelta54;  slog::Index** evdelta55;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord57({0, 1, 2});
      slog::Relation* readrel58 = db->getRelation("ev");
      head_index[0] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("need");
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("ev");
      evindex50 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("ev");
      evindex51 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 2, 0});
      slog::Relation* readrel64 = db->getRelation("ev");
      evdelta54 = readrel64->getIndex(ord63, true);
      std::vector<u16> ord65({0, 1, 2});
      slog::Relation* readrel66 = db->getRelation("add");
      addindex52 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({0, 1, 2});
      slog::Relation* readrel68 = db->getRelation("ev");
      evindex53 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({0, 1, 2});
      slog::Relation* readrel70 = db->getRelation("ev");
      evdelta55 = readrel70->getIndex(ord69, true);
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<3,1>(evindex50, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe_old<3,1>(evindex51, evdelta54, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m71) {
          u64 v_c22 = m71[1]; u64 v_c23 = m71[2];
          slog::join_probe<3,2>(addindex52, std::array<u64,3>{v_c21, v_c23, 0}, [&](const std::array<u64,3>& m72) {
            u64 v_c24 = m72[2];
            slog::join_probe_old<3,2>(evindex53, evdelta55, std::array<u64,3>{v_c24, v_c6, 0}, [&](const std::array<u64,3>& m73) {
              u64 v_c25 = m73[2];
              u64 v_c26 = _prim__0002b(db, v_c22, v_c25);
              if (v_c26 == slog_error) { slog::emit_pending_error(db, "ex_let.slog:32"); return; }
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c21, v_c6, v_c26}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:32", "delta:need", _fires);
  
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
  // (crule (pre) (scan ev e1 rho w) (body (exists elet (2 0 1 3) 1 e1) (join-old need (1 0) 1 (1 0) rho __t9PS754) (join elet (0 2 1 3) 2 __t9PS754 e1 nm e2)) (head (emit-temp temp84uP133 e2 nm rho w) (mkstruct bind (3 2 1 0) __t9Fhp53 rho w nm)) ex_let.slog:26 #f)
  class ReadTask78 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eletindex74;  slog::Index** needindex75;  slog::Index** eletindex76;  slog::Index** needdelta77;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp84uP133");
      head_rel[1] = db->getRelation("bind");
      outer_rel = db->getRelation("ev");
      std::vector<u16> ord79({2, 0, 1, 3});
      slog::Relation* readrel80 = db->getRelation("elet");
      eletindex74 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({1, 0});
      slog::Relation* readrel82 = db->getRelation("need");
      needindex75 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 0});
      slog::Relation* readrel84 = db->getRelation("need");
      needdelta77 = readrel84->getIndex(ord83, true);
      std::vector<u16> ord85({0, 2, 1, 3});
      slog::Relation* readrel86 = db->getRelation("elet");
      eletindex76 = readrel86->getIndex(ord85, false);
  
    }
    ReadTask78(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<4,1>(eletindex74, std::array<u64,4>{v_c5, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(needindex75, needdelta77, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m87) {
          u64 v_c27 = m87[1];
          slog::join_probe<4,2>(eletindex76, std::array<u64,4>{v_c27, v_c5, 0, 0}, [&](const std::array<u64,4>& m88) {
            u64 v_c8 = m88[2]; u64 v_c10 = m88[3];
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c10, v_c8, v_c6, v_c17});
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c6, v_c17, v_c8}, std::array<u16,4>{3, 2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("ex_let.slog:26", "delta:ev", _fires);
  
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
  // (crule (pre) (scan bind __t9AKq52 nm w1 rho) (body (exists elet (1 2 3 0) 1 nm) (exists need (1 0) 1 rho) (exists ev (1 2 0) 1 __t9AKq52) (join ev (1 2 0) 2 rho w1 e1) (join elet (1 2 3 0) 2 nm e1 e2 __t8R2A51) (join need (0 1) 2 __t8R2A51 rho) (join ev (0 1 2) 2 e2 __t9AKq52 w2)) (head (emit ev (0 1 2) __t8R2A51 rho w2)) ex_let.slog:35 #f)
  class ReadTask96 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eletindex89;  slog::Index** needindex90;  slog::Index** evindex91;  slog::Index** evindex92;  slog::Index** eletindex93;  slog::Index** needindex94;  slog::Index** evindex95;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord97({0, 1, 2});
      slog::Relation* readrel98 = db->getRelation("ev");
      head_index[0] = readrel98->getIndex(ord97, false);
      outer_rel = db->getRelation("bind");
      std::vector<u16> ord99({1, 2, 3, 0});
      slog::Relation* readrel100 = db->getRelation("elet");
      eletindex89 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("need");
      needindex90 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 0});
      slog::Relation* readrel104 = db->getRelation("ev");
      evindex91 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 2, 0});
      slog::Relation* readrel106 = db->getRelation("ev");
      evindex92 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 2, 3, 0});
      slog::Relation* readrel108 = db->getRelation("elet");
      eletindex93 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("need");
      needindex94 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 1, 2});
      slog::Relation* readrel112 = db->getRelation("ev");
      evindex95 = readrel112->getIndex(ord111, false);
  
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
        u64 v_c9 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        if (!slog::exists_probe<4,1>(eletindex89, std::array<u64,4>{v_c8, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(needindex90, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(evindex91, std::array<u64,3>{v_c9, 0, 0})) return;
        slog::join_probe<3,2>(evindex92, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m113) {
          u64 v_c5 = m113[2];
          slog::join_probe<4,2>(eletindex93, std::array<u64,4>{v_c8, v_c5, 0, 0}, [&](const std::array<u64,4>& m114) {
            u64 v_c10 = m114[2]; u64 v_c11 = m114[3];
            slog::join_probe<2,2>(needindex94, std::array<u64,2>{v_c11, v_c6}, [&](const std::array<u64,2>& m115) {
              slog::join_probe<3,2>(evindex95, std::array<u64,3>{v_c10, v_c9, 0}, [&](const std::array<u64,3>& m116) {
                u64 v_c12 = m116[2];
                ++_fires;
                slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c11, v_c6, v_c12}, std::array<u16,3>{0, 1, 2});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:35", "delta:bind", _fires);
  
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
  // (crule (pre) (scan mpz_table_overflow __erre2ZTP130 __errf7SV7131 __errf8mOG132) (body) (head (emit error (0) __erre2ZTP130)) <internal>:1 #f)
  class ReadTask117 : public slog::Task
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
      std::vector<u16> ord118({0});
      slog::Relation* readrel119 = db->getRelation("error");
      head_index[0] = readrel119->getIndex(ord118, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask117(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask117* _cont = new ReadTask117(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask117(db,b), false);
  // (crule (pre) (scan ev a rho wa) (body (exists add (1 2 0) 1 a) (exists ev (1 2 0) 1 rho) (join need (1 0) 1 rho __t0FJ656) (join add (0 1 2) 2 __t0FJ656 a b) (join-old ev (0 1 2) 2 (0 1 2) b rho wb) (let __t5MpC57 (_0002b wa wb))) (head (emit ev (0 1 2) __t0FJ656 rho __t5MpC57)) ex_let.slog:32 #f)
  class ReadTask126 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** addindex120;  slog::Index** evindex121;  slog::Index** needindex122;  slog::Index** addindex123;  slog::Index** evindex124;  slog::Index** evdelta125;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord127({0, 1, 2});
      slog::Relation* readrel128 = db->getRelation("ev");
      head_index[0] = readrel128->getIndex(ord127, false);
      outer_rel = db->getRelation("ev");
      std::vector<u16> ord129({1, 2, 0});
      slog::Relation* readrel130 = db->getRelation("add");
      addindex120 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({1, 2, 0});
      slog::Relation* readrel132 = db->getRelation("ev");
      evindex121 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 0});
      slog::Relation* readrel134 = db->getRelation("need");
      needindex122 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({0, 1, 2});
      slog::Relation* readrel136 = db->getRelation("add");
      addindex123 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({0, 1, 2});
      slog::Relation* readrel138 = db->getRelation("ev");
      evindex124 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({0, 1, 2});
      slog::Relation* readrel140 = db->getRelation("ev");
      evdelta125 = readrel140->getIndex(ord139, true);
  
    }
    ReadTask126(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c22 = _t[2];
        if (!slog::exists_probe<3,1>(addindex120, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evindex121, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(needindex122, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m141) {
          u64 v_c21 = m141[1];
          slog::join_probe<3,2>(addindex123, std::array<u64,3>{v_c21, v_c23, 0}, [&](const std::array<u64,3>& m142) {
            u64 v_c24 = m142[2];
            slog::join_probe_old<3,2>(evindex124, evdelta125, std::array<u64,3>{v_c24, v_c6, 0}, [&](const std::array<u64,3>& m143) {
              u64 v_c25 = m143[2];
              u64 v_c26 = _prim__0002b(db, v_c22, v_c25);
              if (v_c26 == slog_error) { slog::emit_pending_error(db, "ex_let.slog:32"); return; }
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c21, v_c6, v_c26}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:32", "delta:ev", _fires);
  
      if (!_done)
      {
        ReadTask126* _cont = new ReadTask126(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask126(db,b), false);
  // (crule (pre) (scan ev b rho wb) (body (exists add (2 0 1) 1 b) (exists ev (1 2 0) 1 rho) (join need (1 0) 1 rho __t0FJ656) (join add (2 0 1) 2 b __t0FJ656 a) (join ev (0 1 2) 2 a rho wa) (let __t5MpC57 (_0002b wa wb))) (head (emit ev (0 1 2) __t0FJ656 rho __t5MpC57)) ex_let.slog:32 #f)
  class ReadTask149 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** addindex144;  slog::Index** evindex145;  slog::Index** needindex146;  slog::Index** addindex147;  slog::Index** evindex148;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord150({0, 1, 2});
      slog::Relation* readrel151 = db->getRelation("ev");
      head_index[0] = readrel151->getIndex(ord150, false);
      outer_rel = db->getRelation("ev");
      std::vector<u16> ord152({2, 0, 1});
      slog::Relation* readrel153 = db->getRelation("add");
      addindex144 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 2, 0});
      slog::Relation* readrel155 = db->getRelation("ev");
      evindex145 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({1, 0});
      slog::Relation* readrel157 = db->getRelation("need");
      needindex146 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({2, 0, 1});
      slog::Relation* readrel159 = db->getRelation("add");
      addindex147 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0, 1, 2});
      slog::Relation* readrel161 = db->getRelation("ev");
      evindex148 = readrel161->getIndex(ord160, false);
  
    }
    ReadTask149(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c25 = _t[2];
        if (!slog::exists_probe<3,1>(addindex144, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evindex145, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(needindex146, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m162) {
          u64 v_c21 = m162[1];
          slog::join_probe<3,2>(addindex147, std::array<u64,3>{v_c24, v_c21, 0}, [&](const std::array<u64,3>& m163) {
            u64 v_c23 = m163[2];
            slog::join_probe<3,2>(evindex148, std::array<u64,3>{v_c23, v_c6, 0}, [&](const std::array<u64,3>& m164) {
              u64 v_c22 = m164[2];
              u64 v_c26 = _prim__0002b(db, v_c22, v_c25);
              if (v_c26 == slog_error) { slog::emit_pending_error(db, "ex_let.slog:32"); return; }
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c21, v_c6, v_c26}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:32", "delta:ev", _fires);
  
      if (!_done)
      {
        ReadTask149* _cont = new ReadTask149(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask149(db,b), false);
  // (crule (pre) (scan int_overflow __erre02kC109 __errf2SYC110 __errf4fOS111 __errf22Pf112) (body) (head (emit error (0) __erre02kC109)) <internal>:1 #f)
  class ReadTask165 : public slog::Task
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
      std::vector<u16> ord166({0});
      slog::Relation* readrel167 = db->getRelation("error");
      head_index[0] = readrel167->getIndex(ord166, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask165(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c31}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask165* _cont = new ReadTask165(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask165(db,b), false);
  // (crule (pre) (scan bind __t9SGm60 nm w ____0aP561) (body) (head (emit lookup (0 1 2) __t9SGm60 nm w)) ex_let.slog:40 #f)
  class ReadTask168 : public slog::Task
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
      head_rel[0] = db->getRelation("lookup");
      std::vector<u16> ord169({0, 1, 2});
      slog::Relation* readrel170 = db->getRelation("lookup");
      head_index[0] = readrel170->getIndex(ord169, false);
      outer_rel = db->getRelation("bind");
  
    }
    ReadTask168(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c36 = _t[3];
        ++_fires;
        slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c35, v_c8, v_c17}, std::array<u16,3>{0, 1, 2});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:40", "delta:bind", _fires);
  
      if (!_done)
      {
        ReadTask168* _cont = new ReadTask168(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask168(db,b), false);
  // (crule (pre) (scan nan_result __erre5T3u113 __errf1lbI114 __errf4hC9115 __errf0TiH116) (body) (head (emit error (0) __erre5T3u113)) <internal>:1 #f)
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
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c37 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c39 = _t[2];
        u64 v_c40 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c37}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre) (scan ev e2 __t9AKq52 w2) (body (join elet (3 0 1 2) 1 e2 __t8R2A51 nm e1) (exists ev (0 1 2) 1 e1) (exists need (0 1) 1 __t8R2A51) (join-old bind (0 1 2 3) 2 (0 1 2 3) __t9AKq52 nm w1 rho) (join ev (0 1 2) 3 e1 rho w1) (join need (0 1) 2 __t8R2A51 rho)) (head (emit ev (0 1 2) __t8R2A51 rho w2)) ex_let.slog:35 #f)
  class ReadTask181 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eletindex174;  slog::Index** evindex175;  slog::Index** needindex176;  slog::Index** bindindex177;  slog::Index** evindex178;  slog::Index** needindex179;  slog::Index** binddelta180;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord182({0, 1, 2});
      slog::Relation* readrel183 = db->getRelation("ev");
      head_index[0] = readrel183->getIndex(ord182, false);
      outer_rel = db->getRelation("ev");
      std::vector<u16> ord184({3, 0, 1, 2});
      slog::Relation* readrel185 = db->getRelation("elet");
      eletindex174 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({0, 1, 2});
      slog::Relation* readrel187 = db->getRelation("ev");
      evindex175 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("need");
      needindex176 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({0, 1, 2, 3});
      slog::Relation* readrel191 = db->getRelation("bind");
      bindindex177 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({0, 1, 2, 3});
      slog::Relation* readrel193 = db->getRelation("bind");
      binddelta180 = readrel193->getIndex(ord192, true);
      std::vector<u16> ord194({0, 1, 2});
      slog::Relation* readrel195 = db->getRelation("ev");
      evindex178 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({0, 1});
      slog::Relation* readrel197 = db->getRelation("need");
      needindex179 = readrel197->getIndex(ord196, false);
  
    }
    ReadTask181(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe<4,1>(eletindex174, std::array<u64,4>{v_c10, 0, 0, 0}, [&](const std::array<u64,4>& m198) {
          u64 v_c11 = m198[1]; u64 v_c8 = m198[2]; u64 v_c5 = m198[3];
          if (!slog::exists_probe<3,1>(evindex175, std::array<u64,3>{v_c5, 0, 0})) return;
          if (!slog::exists_probe<2,1>(needindex176, std::array<u64,2>{v_c11, 0})) return;
          slog::join_probe_old<4,2>(bindindex177, binddelta180, std::array<u64,4>{v_c9, v_c8, 0, 0}, [&](const std::array<u64,4>& m199) {
            u64 v_c7 = m199[2]; u64 v_c6 = m199[3];
            slog::join_probe<3,3>(evindex178, std::array<u64,3>{v_c5, v_c6, v_c7}, [&](const std::array<u64,3>& m200) {
              slog::join_probe<2,2>(needindex179, std::array<u64,2>{v_c11, v_c6}, [&](const std::array<u64,2>& m201) {
                ++_fires;
                slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c11, v_c6, v_c12}, std::array<u16,3>{0, 1, 2});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:35", "delta:ev", _fires);
  
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
  // (crule (pre (let __tconst4oBu66 const1f503613ae12cc0c5121fd74)) (probe _enum (1 0) 1 __tconst4oBu66 __t5drm48) (body (join root (0 1) 0 ____1cBa49 ee)) (head (emit need (0 1) ee __t5drm48)) ex_let.slog:24 #f)
  class ReadTask203 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** rootindex202;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("need");
      std::vector<u16> ord204({0, 1});
      slog::Relation* readrel205 = db->getRelation("need");
      head_index[0] = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 0});
      slog::Relation* readrel207 = db->getRelation("_enum");
      driver_index = readrel207->getIndex(ord206, true);
      std::vector<u16> ord208({0, 1});
      slog::Relation* readrel209 = db->getRelation("root");
      rootindex202 = readrel209->getIndex(ord208, false);
  
    }
    ReadTask203(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const1f503613ae12cc0c5121fd74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c41, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m210) {
        u64 v_c42 = m210[1];
        if (buckethash(v_c42) != bucket) return;
        slog::join_all<2>(rootindex202, [&](const std::array<u64,2>& m211) {
          u64 v_c43 = m211[0]; u64 v_c44 = m211[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c44, v_c42}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:24", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask203* _cont = new ReadTask203(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask203(db,b), true);
  // (crule (pre) (scan need __t1LBD43 rho) (body (join add (0 1 2) 1 __t1LBD43 a b)) (head (emit need (0 1) b rho) (emit need (0 1) a rho)) ex_let.slog:27 #f)
  class ReadTask213 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** addindex212;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("need");
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("need");
      head_index[0] = readrel215->getIndex(ord214, false);
      head_rel[1] = db->getRelation("need");
      std::vector<u16> ord216({0, 1});
      slog::Relation* readrel217 = db->getRelation("need");
      head_index[1] = readrel217->getIndex(ord216, false);
      outer_rel = db->getRelation("need");
      std::vector<u16> ord218({0, 1, 2});
      slog::Relation* readrel219 = db->getRelation("add");
      addindex212 = readrel219->getIndex(ord218, false);
  
    }
    ReadTask213(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c45 = _t[0];
        u64 v_c6 = _t[1];
        slog::join_probe<3,1>(addindex212, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m220) {
          u64 v_c23 = m220[1]; u64 v_c24 = m220[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c6}, std::array<u16,2>{0, 1});
          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c23, v_c6}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("ex_let.slog:27", "delta:need", _fires);
  
      if (!_done)
      {
        ReadTask213* _cont = new ReadTask213(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask213(db,b), false);
  // (crule (pre) (scan lookup rho nm w) (body (exists ref (1 0) 1 nm) (join need (1 0) 1 rho __t3DuD45) (join ref (0 1) 2 __t3DuD45 nm)) (head (emit ev (0 1 2) __t3DuD45 rho w)) ex_let.slog:31 #f)
  class ReadTask224 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex221;  slog::Index** needindex222;  slog::Index** refindex223;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord225({0, 1, 2});
      slog::Relation* readrel226 = db->getRelation("ev");
      head_index[0] = readrel226->getIndex(ord225, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord227({1, 0});
      slog::Relation* readrel228 = db->getRelation("ref");
      refindex221 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 0});
      slog::Relation* readrel230 = db->getRelation("need");
      needindex222 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 1});
      slog::Relation* readrel232 = db->getRelation("ref");
      refindex223 = readrel232->getIndex(ord231, false);
  
    }
    ReadTask224(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<2,1>(refindex221, std::array<u64,2>{v_c8, 0})) return;
        slog::join_probe<2,1>(needindex222, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m233) {
          u64 v_c46 = m233[1];
          slog::join_probe<2,2>(refindex223, std::array<u64,2>{v_c46, v_c8}, [&](const std::array<u64,2>& m234) {
            ++_fires;
            slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c46, v_c6, v_c17}, std::array<u16,3>{0, 1, 2});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:31", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask224* _cont = new ReadTask224(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask224(db,b), false);
  // (crule (pre) (scan bind __t5FRN46 other ____6j2k47 rest) (body (join lookup (0 1 2) 1 rest nm w) (neq nm other)) (head (emit lookup (0 1 2) __t5FRN46 nm w)) ex_let.slog:41 #f)
  class ReadTask236 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex235;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup");
      std::vector<u16> ord237({0, 1, 2});
      slog::Relation* readrel238 = db->getRelation("lookup");
      head_index[0] = readrel238->getIndex(ord237, false);
      outer_rel = db->getRelation("bind");
      std::vector<u16> ord239({0, 1, 2});
      slog::Relation* readrel240 = db->getRelation("lookup");
      lookupindex235 = readrel240->getIndex(ord239, false);
  
    }
    ReadTask236(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c16 = _t[3];
        slog::join_probe<3,1>(lookupindex235, std::array<u64,3>{v_c16, 0, 0}, [&](const std::array<u64,3>& m241) {
          u64 v_c8 = m241[1]; u64 v_c17 = m241[2];
          if (v_c8 == v_c19) return;
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c20, v_c8, v_c17}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:41", "delta:bind", _fires);
  
      if (!_done)
      {
        ReadTask236* _cont = new ReadTask236(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask236(db,b), false);
  // (crule (pre) (scan type_mismatch __erre7P69120 __errf3dmn121 __errf7e0P122 __errf3l63123 __errf577d124) (body) (head (emit error (0) __erre7P69120)) <internal>:1 #f)
  class ReadTask242 : public slog::Task
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
      std::vector<u16> ord243({0});
      slog::Relation* readrel244 = db->getRelation("error");
      head_index[0] = readrel244->getIndex(ord243, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask242(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c48 = _t[1];
        u64 v_c49 = _t[2];
        u64 v_c50 = _t[3];
        u64 v_c51 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c47}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask242* _cont = new ReadTask242(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask242(db,b), false);
  // (crule (pre) (scan need __t9PS754 rho) (body (join ev (1 2 0) 1 rho w e1) (join elet (0 2 1 3) 2 __t9PS754 e1 nm e2)) (head (emit-temp temp84uP133 e2 nm rho w) (mkstruct bind (3 2 1 0) __t9Fhp53 rho w nm)) ex_let.slog:26 #f)
  class ReadTask247 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evindex245;  slog::Index** eletindex246;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp84uP133");
      head_rel[1] = db->getRelation("bind");
      outer_rel = db->getRelation("need");
      std::vector<u16> ord248({1, 2, 0});
      slog::Relation* readrel249 = db->getRelation("ev");
      evindex245 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 2, 1, 3});
      slog::Relation* readrel251 = db->getRelation("elet");
      eletindex246 = readrel251->getIndex(ord250, false);
  
    }
    ReadTask247(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c27 = _t[0];
        u64 v_c6 = _t[1];
        slog::join_probe<3,1>(evindex245, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m252) {
          u64 v_c17 = m252[1]; u64 v_c5 = m252[2];
          slog::join_probe<4,2>(eletindex246, std::array<u64,4>{v_c27, v_c5, 0, 0}, [&](const std::array<u64,4>& m253) {
            u64 v_c8 = m253[2]; u64 v_c10 = m253[3];
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c10, v_c8, v_c6, v_c17});
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c6, v_c17, v_c8}, std::array<u16,4>{3, 2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("ex_let.slog:26", "delta:need", _fires);
  
      if (!_done)
      {
        ReadTask247* _cont = new ReadTask247(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask247(db,b), false);
  // (crule (pre) (scan need __t9Zqb59 rho) (body (join lit (0 1) 1 __t9Zqb59 n)) (head (emit ev (0 1 2) __t9Zqb59 rho n)) ex_let.slog:30 #f)
  class ReadTask255 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** litindex254;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord256({0, 1, 2});
      slog::Relation* readrel257 = db->getRelation("ev");
      head_index[0] = readrel257->getIndex(ord256, false);
      outer_rel = db->getRelation("need");
      std::vector<u16> ord258({0, 1});
      slog::Relation* readrel259 = db->getRelation("lit");
      litindex254 = readrel259->getIndex(ord258, false);
  
    }
    ReadTask255(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        slog::join_probe<2,1>(litindex254, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m260) {
          u64 v_c53 = m260[1];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c52, v_c6, v_c53}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:30", "delta:need", _fires);
  
      if (!_done)
      {
        ReadTask255* _cont = new ReadTask255(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask255(db,b), false);
  // (crule (pre) (scan need __t3gvv62 rho) (body (join elet (0 2 1 3) 1 __t3gvv62 e1 ____1ah463 ____86x564)) (head (emit need (0 1) e1 rho)) ex_let.slog:25 #f)
  class ReadTask262 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eletindex261;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("need");
      std::vector<u16> ord263({0, 1});
      slog::Relation* readrel264 = db->getRelation("need");
      head_index[0] = readrel264->getIndex(ord263, false);
      outer_rel = db->getRelation("need");
      std::vector<u16> ord265({0, 2, 1, 3});
      slog::Relation* readrel266 = db->getRelation("elet");
      eletindex261 = readrel266->getIndex(ord265, false);
  
    }
    ReadTask262(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        slog::join_probe<4,1>(eletindex261, std::array<u64,4>{v_c54, 0, 0, 0}, [&](const std::array<u64,4>& m267) {
          u64 v_c5 = m267[1]; u64 v_c55 = m267[2]; u64 v_c56 = m267[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c6}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:25", "delta:need", _fires);
  
      if (!_done)
      {
        ReadTask262* _cont = new ReadTask262(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask262(db,b), false);
  // (crule (pre) (scan temp84uP133 e2 nm rho w) (body (join bind (3 2 1 0) 3 rho w nm __t9Fhp53)) (head (emit need (0 1) e2 __t9Fhp53)) ex_let.slog:26 #f)
  class ReadTask269 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindindex268;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("need");
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("need");
      head_index[0] = readrel271->getIndex(ord270, false);
      outer_rel = db->getRelation("temp84uP133");
      std::vector<u16> ord272({3, 2, 1, 0});
      slog::Relation* readrel273 = db->getRelation("bind");
      bindindex268 = readrel273->getIndex(ord272, false);
  
    }
    ReadTask269(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c17 = _t[3];
        slog::join_probe<4,3>(bindindex268, std::array<u64,4>{v_c6, v_c17, v_c8, 0}, [&](const std::array<u64,4>& m274) {
          u64 v_c57 = m274[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c57}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:26", "delta:temp84uP133", _fires);
  
      if (!_done)
      {
        ReadTask269* _cont = new ReadTask269(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask269(db,b), false);
  // (crule (pre) (scan div_by_zero __erre5juE103 __errf56qC104 __errf1Yf1105) (body) (head (emit error (0) __erre5juE103)) <internal>:1 #f)
  class ReadTask275 : public slog::Task
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
      std::vector<u16> ord276({0});
      slog::Relation* readrel277 = db->getRelation("error");
      head_index[0] = readrel277->getIndex(ord276, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask275(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask275* _cont = new ReadTask275(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask275(db,b), false);
  // (crule (pre) (scan need __t3DuD45 rho) (body (exists lookup (0 1 2) 1 rho) (join ref (0 1) 1 __t3DuD45 nm) (join-old lookup (0 1 2) 2 (0 1 2) rho nm w)) (head (emit ev (0 1 2) __t3DuD45 rho w)) ex_let.slog:31 #f)
  class ReadTask282 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex278;  slog::Index** refindex279;  slog::Index** lookupindex280;  slog::Index** lookupdelta281;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord283({0, 1, 2});
      slog::Relation* readrel284 = db->getRelation("ev");
      head_index[0] = readrel284->getIndex(ord283, false);
      outer_rel = db->getRelation("need");
      std::vector<u16> ord285({0, 1, 2});
      slog::Relation* readrel286 = db->getRelation("lookup");
      lookupindex278 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({0, 1});
      slog::Relation* readrel288 = db->getRelation("ref");
      refindex279 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1, 2});
      slog::Relation* readrel290 = db->getRelation("lookup");
      lookupindex280 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({0, 1, 2});
      slog::Relation* readrel292 = db->getRelation("lookup");
      lookupdelta281 = readrel292->getIndex(ord291, true);
  
    }
    ReadTask282(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<3,1>(lookupindex278, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(refindex279, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m293) {
          u64 v_c8 = m293[1];
          slog::join_probe_old<3,2>(lookupindex280, lookupdelta281, std::array<u64,3>{v_c6, v_c8, 0}, [&](const std::array<u64,3>& m294) {
            u64 v_c17 = m294[2];
            ++_fires;
            slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c46, v_c6, v_c17}, std::array<u16,3>{0, 1, 2});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:31", "delta:need", _fires);
  
      if (!_done)
      {
        ReadTask282* _cont = new ReadTask282(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask282(db,b), false);
  // (crule (pre) (scan toint_range __erre32M9117 __errf3pwV118 __errf1QCi119) (body) (head (emit error (0) __erre32M9117)) <internal>:1 #f)
  class ReadTask295 : public slog::Task
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
      std::vector<u16> ord296({0});
      slog::Relation* readrel297 = db->getRelation("error");
      head_index[0] = readrel297->getIndex(ord296, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask295(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c61}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask295* _cont = new ReadTask295(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask295(db,b), false);
  // (crule (pre) (scan need __t8R2A51 rho) (body (exists bind (3 2 1 0) 1 rho) (join-old ev (1 2 0) 1 (1 2 0) rho w1 e1) (exists bind (3 2 1 0) 2 rho w1) (join elet (0 2 1 3) 2 __t8R2A51 e1 nm e2) (exists ev (0 1 2) 1 e2) (join-old bind (3 2 1 0) 3 (3 2 1 0) rho w1 nm __t9AKq52) (join-old ev (0 1 2) 2 (0 1 2) e2 __t9AKq52 w2)) (head (emit ev (0 1 2) __t8R2A51 rho w2)) ex_let.slog:35 #f)
  class ReadTask308 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** bindindex298;  slog::Index** evindex299;  slog::Index** bindindex300;  slog::Index** eletindex301;  slog::Index** evindex302;  slog::Index** bindindex303;  slog::Index** evindex304;  slog::Index** evdelta305;  slog::Index** binddelta306;  slog::Index** evdelta307;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ev");
      std::vector<u16> ord309({0, 1, 2});
      slog::Relation* readrel310 = db->getRelation("ev");
      head_index[0] = readrel310->getIndex(ord309, false);
      outer_rel = db->getRelation("need");
      std::vector<u16> ord311({3, 2, 1, 0});
      slog::Relation* readrel312 = db->getRelation("bind");
      bindindex298 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 2, 0});
      slog::Relation* readrel314 = db->getRelation("ev");
      evindex299 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 2, 0});
      slog::Relation* readrel316 = db->getRelation("ev");
      evdelta305 = readrel316->getIndex(ord315, true);
      std::vector<u16> ord317({3, 2, 1, 0});
      slog::Relation* readrel318 = db->getRelation("bind");
      bindindex300 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({0, 2, 1, 3});
      slog::Relation* readrel320 = db->getRelation("elet");
      eletindex301 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({0, 1, 2});
      slog::Relation* readrel322 = db->getRelation("ev");
      evindex302 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({3, 2, 1, 0});
      slog::Relation* readrel324 = db->getRelation("bind");
      bindindex303 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({3, 2, 1, 0});
      slog::Relation* readrel326 = db->getRelation("bind");
      binddelta306 = readrel326->getIndex(ord325, true);
      std::vector<u16> ord327({0, 1, 2});
      slog::Relation* readrel328 = db->getRelation("ev");
      evindex304 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({0, 1, 2});
      slog::Relation* readrel330 = db->getRelation("ev");
      evdelta307 = readrel330->getIndex(ord329, true);
  
    }
    ReadTask308(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[0];
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<4,1>(bindindex298, std::array<u64,4>{v_c6, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(evindex299, evdelta305, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m331) {
          u64 v_c7 = m331[1]; u64 v_c5 = m331[2];
          if (!slog::exists_probe<4,2>(bindindex300, std::array<u64,4>{v_c6, v_c7, 0, 0})) return;
          slog::join_probe<4,2>(eletindex301, std::array<u64,4>{v_c11, v_c5, 0, 0}, [&](const std::array<u64,4>& m332) {
            u64 v_c8 = m332[2]; u64 v_c10 = m332[3];
            if (!slog::exists_probe<3,1>(evindex302, std::array<u64,3>{v_c10, 0, 0})) return;
            slog::join_probe_old<4,3>(bindindex303, binddelta306, std::array<u64,4>{v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,4>& m333) {
              u64 v_c9 = m333[3];
              slog::join_probe_old<3,2>(evindex304, evdelta307, std::array<u64,3>{v_c10, v_c9, 0}, [&](const std::array<u64,3>& m334) {
                u64 v_c12 = m334[2];
                ++_fires;
                slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c11, v_c6, v_c12}, std::array<u16,3>{0, 1, 2});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_let.slog:35", "delta:need", _fires);
  
      if (!_done)
      {
        ReadTask308* _cont = new ReadTask308(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask308(db,b), false);
  s->addReadRel("_enum");
  s->addReadRel("add");
  s->addReadRel("bind");
  s->addReadRel("div_by_zero");
  s->addReadRel("elet");
  s->addReadRel("ev");
  s->addReadRel("int_overflow");
  s->addReadRel("lit");
  s->addReadRel("lookup");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("need");
  s->addReadRel("ref");
  s->addReadRel("root");
  s->addReadRel("temp84uP133");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("bind");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("ev");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("lookup");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("need");
  s->addDynamicRel("temp84uP133");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("ev");
  s->addAccelRel("lookup");
  s->addAccelRel("need");
  d->push(s);
  d->continueRun();
}

