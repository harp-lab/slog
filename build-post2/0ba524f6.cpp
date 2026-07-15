
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constef2d127de37b942baad06145;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const1f503613ae12cc0c5121fd74;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constba2df4903a2c14e86dc3bcca;
u64 v_const2bc983a5942276eb00a75e21;
u64 v_const0fc73630e591b4315396fe28;
u64 v_const9e5264d410a977c82c64ce0b;
u64 v_const829a7fd574414cb9d628fa26;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("0ba524f6");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const1f503613ae12cc0c5121fd74 = db->encodeString("mt");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constba2df4903a2c14e86dc3bcca = db->encodeString("x");
  v_const2bc983a5942276eb00a75e21 = db->encodeString("y");
  v_const0fc73630e591b4315396fe28 = db->encodeString("p3");
  v_const9e5264d410a977c82c64ce0b = db->encodeString("p1");
  v_const829a7fd574414cb9d628fa26 = db->encodeString("p2");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord564({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord564, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord565({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord565, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord566({1, 2, 0});
    
    r->addIndex<3>(ord566, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord567({0, 1, 2});
    
    r->addIndex<3>(ord567, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord568({1, 2, 0});
    
    r->addIndex<3>(ord568, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord569({0, 1, 2});
    
    r->addIndex<3>(ord569, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("root");
  if (r == 0) db->addRelation("root", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("root");
      std::vector<u16> ord570({0, 1});
    
    r->addIndex<2>(ord570, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("root"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("res");
  if (r == 0) db->addRelation("res", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("res");
      std::vector<u16> ord571({0, 1});
    
    r->addIndex<2>(ord571, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("res"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord572({1, 0});
    
    r->addIndex<2>(ord572, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord573({0, 1});
    
    r->addIndex<2>(ord573, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord574({1, 0});
    
    r->addIndex<2>(ord574, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("need");
  if (r == 0) db->addRelation("need", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("need");
      std::vector<u16> ord575({0, 1});
    
    r->addIndex<2>(ord575, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("need"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord576({1, 2, 3, 0});
    
    r->addIndex<4>(ord576, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord577({0, 1, 2, 3});
    
    r->addIndex<4>(ord577, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord578({1, 2, 0});
    
    r->addIndex<3>(ord578, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord579({0, 1, 2});
    
    r->addIndex<3>(ord579, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord580({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord580, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord581({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord581, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord582({1, 2, 0});
    
    r->addIndex<3>(ord582, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord583({0, 1, 2});
    
    r->addIndex<3>(ord583, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord584({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord584, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord585({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord585, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lookup");
  if (r == 0) db->addRelation("lookup", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lookup");
      std::vector<u16> ord586({0, 1, 2});
    
    r->addIndex<3>(ord586, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("lookup"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("lit");
  if (r == 0) db->addStruct("lit", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lit");
      std::vector<u16> ord587({1, 0});
    
    r->addIndex<2>(ord587, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord588({0, 1});
    
    r->addIndex<2>(ord588, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lit"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord589({1, 2, 3, 0});
    
    r->addIndex<4>(ord589, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord590({0, 1, 2, 3});
    
    r->addIndex<4>(ord590, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("ev");
  if (r == 0) db->addRelation("ev", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ev");
      std::vector<u16> ord591({0, 1, 2});
    
    r->addIndex<3>(ord591, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("ev"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord592({0});
    
    r->addIndex<1>(ord592, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("elet");
  if (r == 0) db->addStruct("elet", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("elet");
      std::vector<u16> ord593({1, 2, 3, 0});
    
    r->addIndex<4>(ord593, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord594({0, 1, 2, 3});
    
    r->addIndex<4>(ord594, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord595({1, 3, 0, 2});
    
    r->addIndex<4>(ord595, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 0, 2}, false, b), false);
      std::vector<u16> ord596({1, 0, 2, 3});
    
    r->addIndex<4>(ord596, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 0, 2, 3}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("elet"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord597({1, 2, 0});
    
    r->addIndex<3>(ord597, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord598({0, 1, 2});
    
    r->addIndex<3>(ord598, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bind");
  if (r == 0) db->addStruct("bind", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bind");
      std::vector<u16> ord599({1, 2, 3, 0});
    
    r->addIndex<4>(ord599, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord600({0, 1, 2, 3});
    
    r->addIndex<4>(ord600, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("bind"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("add");
  if (r == 0) db->addStruct("add", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("add");
      std::vector<u16> ord601({1, 2, 0});
    
    r->addIndex<3>(ord601, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord602({0, 1, 2});
    
    r->addIndex<3>(ord602, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("add"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord603({1, 0});
    
    r->addIndex<2>(ord603, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord604({0, 1});
    
    r->addIndex<2>(ord604, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst6p9h42 const0fc73630e591b4315396fe28) (let __tconst2vON40 constba2df4903a2c14e86dc3bcca) (let __tconst4guA28 const829a7fd574414cb9d628fa26) (let __tconst3hop22 const2bc983a5942276eb00a75e21) (let __tconst931g11 const9e5264d410a977c82c64ce0b) (let __tconst22C038 const6b86b273ff34fce19d6b804e) (let __tconst9kxl31 constef2d127de37b942baad06145) (let __tconst5jLG24 constd4735e3a265e16eee03f5971) (let __tconst2wJQ17 const4a44dc15364204a80fe80e90) (let __tconst6f1U7 const4e07408562bedb8b60ce05c1)) (seeded) (body (join ref (1 0) 1 __tconst2vON40 __t16aj3) (exists ref (1 0) 1 __tconst3hop22) (exists add (1 2 0) 1 __t16aj3) (exists lit (1 0) 1 __tconst2wJQ17) (exists lit (1 0) 1 __tconst5jLG24) (exists lit (1 0) 1 __tconst9kxl31) (exists lit (1 0) 1 __tconst22C038) (join lit (1 0) 1 __tconst6f1U7 __t4Fhy8) (join ref (1 0) 1 __tconst3hop22 __t83nl13) (join add (1 2 0) 2 __t16aj3 __t83nl13 __t5cGy16) (join lit (1 0) 1 __tconst2wJQ17 __t3GHw18) (join add (1 2 0) 2 __t16aj3 __t3GHw18 __t5BpD21) (join lit (1 0) 1 __tconst5jLG24 __t5Rcx25) (join lit (1 0) 1 __tconst9kxl31 __t10jL32) (join add (1 2 0) 2 __t16aj3 __t10jL32 __t29Rb35) (join lit (1 0) 1 __tconst22C038 __t1Wwq39) (join add (1 2 0) 1 __t16aj3 dup9uFD70 __t1EN56) (eq __t16aj3 dup9uFD70)) (head (mkstruct elet (1 2 3 0) __t6d9537 __tconst2vON40 __t29Rb35 __t16aj3) (mkstruct elet (1 2 3 0) __t573C23 __tconst3hop22 __t5BpD21 __t5cGy16) (mkstruct elet (1 2 3 0) __t4bd610 __tconst2vON40 __t4Fhy8 __t1EN56)) ex_let.slog:18 #f)
  class ReadTask17 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex0;  slog::Index** refindex1;  slog::Index** addindex2;  slog::Index** litindex3;  slog::Index** litindex4;  slog::Index** litindex5;  slog::Index** litindex6;  slog::Index** litindex7;  slog::Index** refindex8;  slog::Index** addindex9;  slog::Index** litindex10;  slog::Index** addindex11;  slog::Index** litindex12;  slog::Index** litindex13;  slog::Index** addindex14;  slog::Index** litindex15;  slog::Index** addindex16;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("elet");
      std::vector<u16> ord18({1, 2, 3, 0});
      slog::Relation* readrel19 = db->getRelation("elet");
      head_index[0] = readrel19->getIndex(ord18, false);
      head_rel[1] = db->getRelation("elet");
      std::vector<u16> ord20({1, 2, 3, 0});
      slog::Relation* readrel21 = db->getRelation("elet");
      head_index[1] = readrel21->getIndex(ord20, false);
      head_rel[2] = db->getRelation("elet");
      std::vector<u16> ord22({1, 2, 3, 0});
      slog::Relation* readrel23 = db->getRelation("elet");
      head_index[2] = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0});
      slog::Relation* readrel25 = db->getRelation("ref");
      refindex0 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 0});
      slog::Relation* readrel27 = db->getRelation("ref");
      refindex1 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 2, 0});
      slog::Relation* readrel29 = db->getRelation("add");
      addindex2 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 0});
      slog::Relation* readrel31 = db->getRelation("lit");
      litindex3 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("lit");
      litindex4 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 0});
      slog::Relation* readrel35 = db->getRelation("lit");
      litindex5 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 0});
      slog::Relation* readrel37 = db->getRelation("lit");
      litindex6 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 0});
      slog::Relation* readrel39 = db->getRelation("lit");
      litindex7 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 0});
      slog::Relation* readrel41 = db->getRelation("ref");
      refindex8 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 2, 0});
      slog::Relation* readrel43 = db->getRelation("add");
      addindex9 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 0});
      slog::Relation* readrel45 = db->getRelation("lit");
      litindex10 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 2, 0});
      slog::Relation* readrel47 = db->getRelation("add");
      addindex11 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 0});
      slog::Relation* readrel49 = db->getRelation("lit");
      litindex12 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("lit");
      litindex13 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 2, 0});
      slog::Relation* readrel53 = db->getRelation("add");
      addindex14 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 0});
      slog::Relation* readrel55 = db->getRelation("lit");
      litindex15 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 2, 0});
      slog::Relation* readrel57 = db->getRelation("add");
      addindex16 = readrel57->getIndex(ord56, false);
  
    }
    ReadTask17(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0fc73630e591b4315396fe28;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c2 = v_const829a7fd574414cb9d628fa26;
      u64 v_c3 = v_const2bc983a5942276eb00a75e21;
      u64 v_c4 = v_const9e5264d410a977c82c64ce0b;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constef2d127de37b942baad06145;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
      u64 v_c9 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m58) {
        u64 v_c10 = m58[1];
        if (!slog::exists_probe<2,1>(refindex1, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(addindex2, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<2,1>(litindex3, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(litindex4, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(litindex5, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(litindex6, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<2,1>(litindex7, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m59) {
          u64 v_c11 = m59[1];
          slog::join_probe<2,1>(refindex8, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m60) {
            u64 v_c12 = m60[1];
            slog::join_probe<3,2>(addindex9, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m61) {
              u64 v_c13 = m61[2];
              slog::join_probe<2,1>(litindex10, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m62) {
                u64 v_c14 = m62[1];
                slog::join_probe<3,2>(addindex11, std::array<u64,3>{v_c10, v_c14, 0}, [&](const std::array<u64,3>& m63) {
                  u64 v_c15 = m63[2];
                  slog::join_probe<2,1>(litindex12, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m64) {
                    u64 v_c16 = m64[1];
                    slog::join_probe<2,1>(litindex13, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m65) {
                      u64 v_c17 = m65[1];
                      slog::join_probe<3,2>(addindex14, std::array<u64,3>{v_c10, v_c17, 0}, [&](const std::array<u64,3>& m66) {
                        u64 v_c18 = m66[2];
                        slog::join_probe<2,1>(litindex15, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m67) {
                          u64 v_c19 = m67[1];
                          slog::join_probe<3,1>(addindex16, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m68) {
                            u64 v_c20 = m68[1]; u64 v_c21 = m68[2];
                            if (v_c10 != v_c20) return;
                            ++_fires;
                            slog::emit_struct_checked<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c1, v_c18, v_c10}, std::array<u16,4>{1, 2, 3, 0});
                            slog::emit_struct_checked<4>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c3, v_c15, v_c13}, std::array<u16,4>{1, 2, 3, 0});
                            slog::emit_struct_checked<4>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c1, v_c11, v_c21}, std::array<u16,4>{1, 2, 3, 0});
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
  
      if (_fires) db->bumpFires("ex_let.slog:18", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask17(db,b));
  // (crule (pre (let __tconst6p9h42 const0fc73630e591b4315396fe28) (let __tconst2vON40 constba2df4903a2c14e86dc3bcca) (let __tconst22C038 const6b86b273ff34fce19d6b804e) (let __tconst9kxl31 constef2d127de37b942baad06145) (let __tconst4guA28 const829a7fd574414cb9d628fa26) (let __tconst5jLG24 constd4735e3a265e16eee03f5971) (let __tconst3hop22 const2bc983a5942276eb00a75e21) (let __tconst2wJQ17 const4a44dc15364204a80fe80e90) (let __tconst931g11 const9e5264d410a977c82c64ce0b) (let __tconst6f1U7 const4e07408562bedb8b60ce05c1)) (once) (body) (head (mkstruct lit (1 0) __t1Wwq39 __tconst22C038) (mkstruct lit (1 0) __t10jL32 __tconst9kxl31) (mkstruct lit (1 0) __t5Rcx25 __tconst5jLG24) (mkstruct lit (1 0) __t3GHw18 __tconst2wJQ17) (mkstruct ref (1 0) __t83nl13 __tconst3hop22) (mkstruct lit (1 0) __t4Fhy8 __tconst6f1U7) (mkstruct ref (1 0) __t16aj3 __tconst2vON40)) ex_let.slog:18 #f)
  class ReadTask69 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lit");
      head_rel[1] = db->getRelation("lit");
      head_rel[2] = db->getRelation("lit");
      head_rel[3] = db->getRelation("lit");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("lit");
      head_rel[6] = db->getRelation("ref");
  
    }
    ReadTask69(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0fc73630e591b4315396fe28;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constef2d127de37b942baad06145;
      u64 v_c2 = v_const829a7fd574414cb9d628fa26;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const2bc983a5942276eb00a75e21;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
      u64 v_c4 = v_const9e5264d410a977c82c64ce0b;
      u64 v_c9 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[7];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c6}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c7}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c9}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("ex_let.slog:18", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask69(db,b), true);
  // (crule (pre (let __tconst2kqX67 const1f503613ae12cc0c5121fd74)) (once) (body) (head (mkstruct _enum (1 0) __7H2k68 __tconst2kqX67)) <internal>:1 #f)
  class ReadTask70 : public slog::Task
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
    ReadTask70(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const1f503613ae12cc0c5121fd74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask70(db,b), true);
  // (crule (pre (let __tconst6p9h42 const0fc73630e591b4315396fe28) (let __tconst2vON40 constba2df4903a2c14e86dc3bcca) (let __tconst4guA28 const829a7fd574414cb9d628fa26) (let __tconst3hop22 const2bc983a5942276eb00a75e21) (let __tconst931g11 const9e5264d410a977c82c64ce0b) (let __tconst22C038 const6b86b273ff34fce19d6b804e) (let __tconst9kxl31 constef2d127de37b942baad06145) (let __tconst5jLG24 constd4735e3a265e16eee03f5971) (let __tconst2wJQ17 const4a44dc15364204a80fe80e90) (let __tconst6f1U7 const4e07408562bedb8b60ce05c1)) (scan add __t1EN56 __t16aj3 dup55DM69) (body (eq __t16aj3 dup55DM69) (join ref (0 1) 2 __t16aj3 __tconst2vON40) (exists ref (1 0) 1 __tconst3hop22) (exists add (1 2 0) 1 __t16aj3) (exists lit (1 0) 1 __tconst2wJQ17) (exists lit (1 0) 1 __tconst5jLG24) (exists lit (1 0) 1 __tconst9kxl31) (exists lit (1 0) 1 __tconst22C038) (join lit (1 0) 1 __tconst6f1U7 __t4Fhy8) (join ref (1 0) 1 __tconst3hop22 __t83nl13) (join add (1 2 0) 2 __t16aj3 __t83nl13 __t5cGy16) (join lit (1 0) 1 __tconst2wJQ17 __t3GHw18) (join add (1 2 0) 2 __t16aj3 __t3GHw18 __t5BpD21) (join lit (1 0) 1 __tconst5jLG24 __t5Rcx25) (join lit (1 0) 1 __tconst9kxl31 __t10jL32) (join add (1 2 0) 2 __t16aj3 __t10jL32 __t29Rb35) (join lit (1 0) 1 __tconst22C038 __t1Wwq39)) (head (mkstruct elet (1 2 3 0) __t6d9537 __tconst2vON40 __t29Rb35 __t16aj3) (mkstruct elet (1 2 3 0) __t573C23 __tconst3hop22 __t5BpD21 __t5cGy16) (mkstruct elet (1 2 3 0) __t4bd610 __tconst2vON40 __t4Fhy8 __t1EN56)) ex_let.slog:18 #f)
  class ReadTask87 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex71;  slog::Index** refindex72;  slog::Index** addindex73;  slog::Index** litindex74;  slog::Index** litindex75;  slog::Index** litindex76;  slog::Index** litindex77;  slog::Index** litindex78;  slog::Index** refindex79;  slog::Index** addindex80;  slog::Index** litindex81;  slog::Index** addindex82;  slog::Index** litindex83;  slog::Index** litindex84;  slog::Index** addindex85;  slog::Index** litindex86;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("elet");
      head_rel[1] = db->getRelation("elet");
      head_rel[2] = db->getRelation("elet");
      outer_rel = db->getRelation("add");
      std::vector<u16> ord88({0, 1});
      slog::Relation* readrel89 = db->getRelation("ref");
      refindex71 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 0});
      slog::Relation* readrel91 = db->getRelation("ref");
      refindex72 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 2, 0});
      slog::Relation* readrel93 = db->getRelation("add");
      addindex73 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0});
      slog::Relation* readrel95 = db->getRelation("lit");
      litindex74 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 0});
      slog::Relation* readrel97 = db->getRelation("lit");
      litindex75 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 0});
      slog::Relation* readrel99 = db->getRelation("lit");
      litindex76 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 0});
      slog::Relation* readrel101 = db->getRelation("lit");
      litindex77 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 0});
      slog::Relation* readrel103 = db->getRelation("lit");
      litindex78 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 0});
      slog::Relation* readrel105 = db->getRelation("ref");
      refindex79 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 2, 0});
      slog::Relation* readrel107 = db->getRelation("add");
      addindex80 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 0});
      slog::Relation* readrel109 = db->getRelation("lit");
      litindex81 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 2, 0});
      slog::Relation* readrel111 = db->getRelation("add");
      addindex82 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 0});
      slog::Relation* readrel113 = db->getRelation("lit");
      litindex83 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({1, 0});
      slog::Relation* readrel115 = db->getRelation("lit");
      litindex84 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 0});
      slog::Relation* readrel117 = db->getRelation("add");
      addindex85 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 0});
      slog::Relation* readrel119 = db->getRelation("lit");
      litindex86 = readrel119->getIndex(ord118, false);
  
    }
    ReadTask87(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0fc73630e591b4315396fe28;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c2 = v_const829a7fd574414cb9d628fa26;
      u64 v_c3 = v_const2bc983a5942276eb00a75e21;
      u64 v_c4 = v_const9e5264d410a977c82c64ce0b;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constef2d127de37b942baad06145;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
      u64 v_c9 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c21 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c23 = _t[2];
        if (v_c10 != v_c23) return;
        slog::join_probe<2,2>(refindex71, std::array<u64,2>{v_c10, v_c1}, [&](const std::array<u64,2>& m120) {
          if (!slog::exists_probe<2,1>(refindex72, std::array<u64,2>{v_c3, 0})) return;
          if (!slog::exists_probe<3,1>(addindex73, std::array<u64,3>{v_c10, 0, 0})) return;
          if (!slog::exists_probe<2,1>(litindex74, std::array<u64,2>{v_c8, 0})) return;
          if (!slog::exists_probe<2,1>(litindex75, std::array<u64,2>{v_c7, 0})) return;
          if (!slog::exists_probe<2,1>(litindex76, std::array<u64,2>{v_c6, 0})) return;
          if (!slog::exists_probe<2,1>(litindex77, std::array<u64,2>{v_c5, 0})) return;
          slog::join_probe<2,1>(litindex78, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m121) {
            u64 v_c11 = m121[1];
            slog::join_probe<2,1>(refindex79, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m122) {
              u64 v_c12 = m122[1];
              slog::join_probe<3,2>(addindex80, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m123) {
                u64 v_c13 = m123[2];
                slog::join_probe<2,1>(litindex81, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m124) {
                  u64 v_c14 = m124[1];
                  slog::join_probe<3,2>(addindex82, std::array<u64,3>{v_c10, v_c14, 0}, [&](const std::array<u64,3>& m125) {
                    u64 v_c15 = m125[2];
                    slog::join_probe<2,1>(litindex83, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m126) {
                      u64 v_c16 = m126[1];
                      slog::join_probe<2,1>(litindex84, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m127) {
                        u64 v_c17 = m127[1];
                        slog::join_probe<3,2>(addindex85, std::array<u64,3>{v_c10, v_c17, 0}, [&](const std::array<u64,3>& m128) {
                          u64 v_c18 = m128[2];
                          slog::join_probe<2,1>(litindex86, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m129) {
                            u64 v_c19 = m129[1];
                            ++_fires;
                            slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c1, v_c18, v_c10}, std::array<u16,4>{1, 2, 3, 0});
                            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c3, v_c15, v_c13}, std::array<u16,4>{1, 2, 3, 0});
                            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c1, v_c11, v_c21}, std::array<u16,4>{1, 2, 3, 0});
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
  
      if (_fires) db->bumpFires("ex_let.slog:18", "delta:add", _fires);
  
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
      s->addTask(phase_read, new ReadTask87(db,b), false);
  // (crule (pre (let __tconst6p9h42 const0fc73630e591b4315396fe28) (let __tconst2vON40 constba2df4903a2c14e86dc3bcca) (let __tconst22C038 const6b86b273ff34fce19d6b804e) (let __tconst9kxl31 constef2d127de37b942baad06145) (let __tconst4guA28 const829a7fd574414cb9d628fa26) (let __tconst5jLG24 constd4735e3a265e16eee03f5971) (let __tconst3hop22 const2bc983a5942276eb00a75e21) (let __tconst2wJQ17 const4a44dc15364204a80fe80e90) (let __tconst931g11 const9e5264d410a977c82c64ce0b) (let __tconst6f1U7 const4e07408562bedb8b60ce05c1)) (seeded) (body (join ref (1 0) 1 __tconst2vON40 __t16aj3) (exists ref (1 0) 1 __tconst3hop22) (exists lit (1 0) 1 __tconst2wJQ17) (exists lit (1 0) 1 __tconst5jLG24) (exists lit (1 0) 1 __tconst9kxl31) (exists lit (1 0) 1 __tconst22C038) (join lit (1 0) 1 __tconst6f1U7 __t4Fhy8) (join ref (1 0) 1 __tconst3hop22 __t83nl13) (join lit (1 0) 1 __tconst2wJQ17 __t3GHw18) (join lit (1 0) 1 __tconst5jLG24 __t5Rcx25) (join lit (1 0) 1 __tconst9kxl31 __t10jL32) (join lit (1 0) 1 __tconst22C038 __t1Wwq39)) (head (mkstruct add (1 2 0) __t29Rb35 __t16aj3 __t10jL32) (mkstruct add (1 2 0) __t5BpD21 __t16aj3 __t3GHw18) (mkstruct add (1 2 0) __t5cGy16 __t16aj3 __t83nl13) (mkstruct add (1 2 0) __t1EN56 __t16aj3 __t16aj3)) ex_let.slog:18 #f)
  class ReadTask142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
    slog::Index** refindex130;  slog::Index** refindex131;  slog::Index** litindex132;  slog::Index** litindex133;  slog::Index** litindex134;  slog::Index** litindex135;  slog::Index** litindex136;  slog::Index** refindex137;  slog::Index** litindex138;  slog::Index** litindex139;  slog::Index** litindex140;  slog::Index** litindex141;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("add");
      std::vector<u16> ord143({1, 2, 0});
      slog::Relation* readrel144 = db->getRelation("add");
      head_index[0] = readrel144->getIndex(ord143, false);
      head_rel[1] = db->getRelation("add");
      std::vector<u16> ord145({1, 2, 0});
      slog::Relation* readrel146 = db->getRelation("add");
      head_index[1] = readrel146->getIndex(ord145, false);
      head_rel[2] = db->getRelation("add");
      std::vector<u16> ord147({1, 2, 0});
      slog::Relation* readrel148 = db->getRelation("add");
      head_index[2] = readrel148->getIndex(ord147, false);
      head_rel[3] = db->getRelation("add");
      std::vector<u16> ord149({1, 2, 0});
      slog::Relation* readrel150 = db->getRelation("add");
      head_index[3] = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 0});
      slog::Relation* readrel152 = db->getRelation("ref");
      refindex130 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 0});
      slog::Relation* readrel154 = db->getRelation("ref");
      refindex131 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 0});
      slog::Relation* readrel156 = db->getRelation("lit");
      litindex132 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 0});
      slog::Relation* readrel158 = db->getRelation("lit");
      litindex133 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 0});
      slog::Relation* readrel160 = db->getRelation("lit");
      litindex134 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 0});
      slog::Relation* readrel162 = db->getRelation("lit");
      litindex135 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 0});
      slog::Relation* readrel164 = db->getRelation("lit");
      litindex136 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 0});
      slog::Relation* readrel166 = db->getRelation("ref");
      refindex137 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("lit");
      litindex138 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 0});
      slog::Relation* readrel170 = db->getRelation("lit");
      litindex139 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 0});
      slog::Relation* readrel172 = db->getRelation("lit");
      litindex140 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 0});
      slog::Relation* readrel174 = db->getRelation("lit");
      litindex141 = readrel174->getIndex(ord173, false);
  
    }
    ReadTask142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0fc73630e591b4315396fe28;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constef2d127de37b942baad06145;
      u64 v_c2 = v_const829a7fd574414cb9d628fa26;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const2bc983a5942276eb00a75e21;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
      u64 v_c4 = v_const9e5264d410a977c82c64ce0b;
      u64 v_c9 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex130, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m175) {
        u64 v_c10 = m175[1];
        if (!slog::exists_probe<2,1>(refindex131, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(litindex132, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(litindex133, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(litindex134, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(litindex135, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<2,1>(litindex136, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m176) {
          u64 v_c11 = m176[1];
          slog::join_probe<2,1>(refindex137, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m177) {
            u64 v_c12 = m177[1];
            slog::join_probe<2,1>(litindex138, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m178) {
              u64 v_c14 = m178[1];
              slog::join_probe<2,1>(litindex139, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m179) {
                u64 v_c16 = m179[1];
                slog::join_probe<2,1>(litindex140, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m180) {
                  u64 v_c17 = m180[1];
                  slog::join_probe<2,1>(litindex141, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m181) {
                    u64 v_c19 = m181[1];
                    ++_fires;
                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c10, v_c14}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c10, v_c12}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c10, v_c10}, std::array<u16,3>{1, 2, 0});
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
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("ex_let.slog:18", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask142(db,b));
  // (crule (pre (let __tconst6p9h42 const0fc73630e591b4315396fe28) (let __tconst2vON40 constba2df4903a2c14e86dc3bcca) (let __tconst4guA28 const829a7fd574414cb9d628fa26) (let __tconst3hop22 const2bc983a5942276eb00a75e21) (let __tconst931g11 const9e5264d410a977c82c64ce0b) (let __tconst22C038 const6b86b273ff34fce19d6b804e) (let __tconst5jLG24 constd4735e3a265e16eee03f5971) (let __tconst6f1U7 const4e07408562bedb8b60ce05c1) (let __tconst9kxl31 constef2d127de37b942baad06145) (let __tconst2wJQ17 const4a44dc15364204a80fe80e90)) (probe elet (1 0 2 3) 1 __tconst2vON40 __t4bd610 __t4Fhy8 __t1EN56) (body (join lit (0 1) 2 __t4Fhy8 __tconst6f1U7) (exists elet (1 2 3 0) 1 __tconst2vON40) (exists lit (1 0) 1 __tconst9kxl31) (exists lit (1 0) 1 __tconst5jLG24) (exists lit (1 0) 1 __tconst22C038) (exists ref (1 0) 1 __tconst3hop22) (exists elet (1 2 3 0) 1 __tconst3hop22) (exists lit (1 0) 1 __tconst2wJQ17) (join ref (1 0) 1 __tconst2vON40 __t16aj3) (exists elet (1 3 0 2) 2 __tconst2vON40 __t16aj3) (exists add (1 2 0) 1 __t16aj3) (join add (0 1 2) 2 __t1EN56 __t16aj3 dup2Ti071) (eq __t16aj3 dup2Ti071) (join elet (1 3 0 2) 2 __tconst2vON40 __t16aj3 __t6d9537 __t29Rb35) (join add (0 1 2) 2 __t29Rb35 __t16aj3 __t10jL32) (join lit (0 1) 2 __t10jL32 __tconst9kxl31) (join lit (1 0) 1 __tconst5jLG24 __t5Rcx25) (join lit (1 0) 1 __tconst22C038 __t1Wwq39) (join ref (1 0) 1 __tconst3hop22 __t83nl13) (join add (1 2 0) 2 __t16aj3 __t83nl13 __t5cGy16) (join elet (1 3 0 2) 2 __tconst3hop22 __t5cGy16 __t573C23 __t5BpD21) (join add (0 1 2) 2 __t5BpD21 __t16aj3 __t3GHw18) (join lit (0 1) 2 __t3GHw18 __tconst2wJQ17)) (head (emit root (0 1) __tconst931g11 __t4bd610) (mkstruct elet (1 2 3 0) __t91ux41 __tconst2vON40 __t1Wwq39 __t6d9537) (mkstruct elet (1 2 3 0) __t6Hkm27 __tconst2vON40 __t5Rcx25 __t573C23)) ex_let.slog:18 #f)
  class ReadTask204 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** litindex182;  slog::Index** eletindex183;  slog::Index** litindex184;  slog::Index** litindex185;  slog::Index** litindex186;  slog::Index** refindex187;  slog::Index** eletindex188;  slog::Index** litindex189;  slog::Index** refindex190;  slog::Index** eletindex191;  slog::Index** addindex192;  slog::Index** addindex193;  slog::Index** eletindex194;  slog::Index** addindex195;  slog::Index** litindex196;  slog::Index** litindex197;  slog::Index** litindex198;  slog::Index** refindex199;  slog::Index** addindex200;  slog::Index** eletindex201;  slog::Index** addindex202;  slog::Index** litindex203;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("root");
      std::vector<u16> ord205({0, 1});
      slog::Relation* readrel206 = db->getRelation("root");
      head_index[0] = readrel206->getIndex(ord205, false);
      head_rel[1] = db->getRelation("elet");
      head_rel[2] = db->getRelation("elet");
      std::vector<u16> ord207({1, 0, 2, 3});
      slog::Relation* readrel208 = db->getRelation("elet");
      driver_index = readrel208->getIndex(ord207, true);
      std::vector<u16> ord209({0, 1});
      slog::Relation* readrel210 = db->getRelation("lit");
      litindex182 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 3, 0});
      slog::Relation* readrel212 = db->getRelation("elet");
      eletindex183 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 0});
      slog::Relation* readrel214 = db->getRelation("lit");
      litindex184 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 0});
      slog::Relation* readrel216 = db->getRelation("lit");
      litindex185 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 0});
      slog::Relation* readrel218 = db->getRelation("lit");
      litindex186 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 0});
      slog::Relation* readrel220 = db->getRelation("ref");
      refindex187 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({1, 2, 3, 0});
      slog::Relation* readrel222 = db->getRelation("elet");
      eletindex188 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 0});
      slog::Relation* readrel224 = db->getRelation("lit");
      litindex189 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 0});
      slog::Relation* readrel226 = db->getRelation("ref");
      refindex190 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 3, 0, 2});
      slog::Relation* readrel228 = db->getRelation("elet");
      eletindex191 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 0});
      slog::Relation* readrel230 = db->getRelation("add");
      addindex192 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 1, 2});
      slog::Relation* readrel232 = db->getRelation("add");
      addindex193 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 3, 0, 2});
      slog::Relation* readrel234 = db->getRelation("elet");
      eletindex194 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 1, 2});
      slog::Relation* readrel236 = db->getRelation("add");
      addindex195 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({0, 1});
      slog::Relation* readrel238 = db->getRelation("lit");
      litindex196 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 0});
      slog::Relation* readrel240 = db->getRelation("lit");
      litindex197 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({1, 0});
      slog::Relation* readrel242 = db->getRelation("lit");
      litindex198 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 0});
      slog::Relation* readrel244 = db->getRelation("ref");
      refindex199 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 2, 0});
      slog::Relation* readrel246 = db->getRelation("add");
      addindex200 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 3, 0, 2});
      slog::Relation* readrel248 = db->getRelation("elet");
      eletindex201 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({0, 1, 2});
      slog::Relation* readrel250 = db->getRelation("add");
      addindex202 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({0, 1});
      slog::Relation* readrel252 = db->getRelation("lit");
      litindex203 = readrel252->getIndex(ord251, false);
  
    }
    ReadTask204(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0fc73630e591b4315396fe28;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c2 = v_const829a7fd574414cb9d628fa26;
      u64 v_c3 = v_const2bc983a5942276eb00a75e21;
      u64 v_c4 = v_const9e5264d410a977c82c64ce0b;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c9 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c6 = v_constef2d127de37b942baad06145;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,1>(driver_index, std::array<u64,4>{v_c1, 0, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m253) {
        u64 v_c24 = m253[1];
        u64 v_c11 = m253[2];
        u64 v_c21 = m253[3];
        if (buckethash(v_c24) != bucket) return;
        slog::join_probe<2,2>(litindex182, std::array<u64,2>{v_c11, v_c9}, [&](const std::array<u64,2>& m254) {
          if (!slog::exists_probe<4,1>(eletindex183, std::array<u64,4>{v_c1, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(litindex184, std::array<u64,2>{v_c6, 0})) return;
          if (!slog::exists_probe<2,1>(litindex185, std::array<u64,2>{v_c7, 0})) return;
          if (!slog::exists_probe<2,1>(litindex186, std::array<u64,2>{v_c5, 0})) return;
          if (!slog::exists_probe<2,1>(refindex187, std::array<u64,2>{v_c3, 0})) return;
          if (!slog::exists_probe<4,1>(eletindex188, std::array<u64,4>{v_c3, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(litindex189, std::array<u64,2>{v_c8, 0})) return;
          slog::join_probe<2,1>(refindex190, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m255) {
            u64 v_c10 = m255[1];
            if (!slog::exists_probe<4,2>(eletindex191, std::array<u64,4>{v_c1, v_c10, 0, 0})) return;
            if (!slog::exists_probe<3,1>(addindex192, std::array<u64,3>{v_c10, 0, 0})) return;
            slog::join_probe<3,2>(addindex193, std::array<u64,3>{v_c21, v_c10, 0}, [&](const std::array<u64,3>& m256) {
              u64 v_c25 = m256[2];
              if (v_c10 != v_c25) return;
              slog::join_probe<4,2>(eletindex194, std::array<u64,4>{v_c1, v_c10, 0, 0}, [&](const std::array<u64,4>& m257) {
                u64 v_c26 = m257[2]; u64 v_c18 = m257[3];
                slog::join_probe<3,2>(addindex195, std::array<u64,3>{v_c18, v_c10, 0}, [&](const std::array<u64,3>& m258) {
                  u64 v_c17 = m258[2];
                  slog::join_probe<2,2>(litindex196, std::array<u64,2>{v_c17, v_c6}, [&](const std::array<u64,2>& m259) {
                    slog::join_probe<2,1>(litindex197, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m260) {
                      u64 v_c16 = m260[1];
                      slog::join_probe<2,1>(litindex198, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m261) {
                        u64 v_c19 = m261[1];
                        slog::join_probe<2,1>(refindex199, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m262) {
                          u64 v_c12 = m262[1];
                          slog::join_probe<3,2>(addindex200, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m263) {
                            u64 v_c13 = m263[2];
                            slog::join_probe<4,2>(eletindex201, std::array<u64,4>{v_c3, v_c13, 0, 0}, [&](const std::array<u64,4>& m264) {
                              u64 v_c27 = m264[2]; u64 v_c15 = m264[3];
                              slog::join_probe<3,2>(addindex202, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m265) {
                                u64 v_c14 = m265[2];
                                slog::join_probe<2,2>(litindex203, std::array<u64,2>{v_c14, v_c8}, [&](const std::array<u64,2>& m266) {
                                  ++_fires;
                                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c24}, std::array<u16,2>{0, 1});
                                  slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c1, v_c19, v_c26}, std::array<u16,4>{1, 2, 3, 0});
                                  slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c1, v_c16, v_c27}, std::array<u16,4>{1, 2, 3, 0});
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("ex_let.slog:18", "delta:elet", _fires);
  
      if (!_done)
      {
        ReadTask204* _cont = new ReadTask204(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask204(db,b), false);
  // (crule (pre (let __tconst6p9h42 const0fc73630e591b4315396fe28) (let __tconst2vON40 constba2df4903a2c14e86dc3bcca) (let __tconst4guA28 const829a7fd574414cb9d628fa26) (let __tconst3hop22 const2bc983a5942276eb00a75e21) (let __tconst22C038 const6b86b273ff34fce19d6b804e) (let __tconst5jLG24 constd4735e3a265e16eee03f5971) (let __tconst9kxl31 constef2d127de37b942baad06145) (let __tconst2wJQ17 const4a44dc15364204a80fe80e90)) (probe elet (1 0 2 3) 1 __tconst2vON40 __t6Hkm27 __t5Rcx25 __t573C23) (body (join lit (0 1) 2 __t5Rcx25 __tconst5jLG24) (exists lit (1 0) 1 __tconst22C038) (exists elet (1 2 3 0) 1 __tconst2vON40) (exists ref (1 0) 1 __tconst2vON40) (exists ref (1 0) 1 __tconst3hop22) (exists lit (1 0) 1 __tconst2wJQ17) (exists lit (1 0) 1 __tconst9kxl31) (join elet (0 1 2 3) 2 __t573C23 __tconst3hop22 __t5BpD21 __t5cGy16) (join lit (1 0) 1 __tconst22C038 __t1Wwq39) (join elet (1 2 3 0) 2 __tconst2vON40 __t1Wwq39 __t6d9537 __t91ux41) (join elet (0 1 2 3) 2 __t6d9537 __tconst2vON40 __t29Rb35 __t16aj3) (join ref (0 1) 2 __t16aj3 __tconst2vON40) (exists add (0 1 2) 2 __t5BpD21 __t16aj3) (exists add (0 1 2) 2 __t29Rb35 __t16aj3) (join add (0 1 2) 2 __t5cGy16 __t16aj3 __t83nl13) (join ref (0 1) 2 __t83nl13 __tconst3hop22) (join add (0 1 2) 2 __t5BpD21 __t16aj3 __t3GHw18) (join lit (0 1) 2 __t3GHw18 __tconst2wJQ17) (join add (0 1 2) 2 __t29Rb35 __t16aj3 __t10jL32) (join lit (0 1) 2 __t10jL32 __tconst9kxl31)) (head (emit root (0 1) __tconst6p9h42 __t91ux41) (emit root (0 1) __tconst4guA28 __t6Hkm27)) ex_let.slog:18 #f)
  class ReadTask287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** litindex267;  slog::Index** litindex268;  slog::Index** eletindex269;  slog::Index** refindex270;  slog::Index** refindex271;  slog::Index** litindex272;  slog::Index** litindex273;  slog::Index** eletindex274;  slog::Index** litindex275;  slog::Index** eletindex276;  slog::Index** eletindex277;  slog::Index** refindex278;  slog::Index** addindex279;  slog::Index** addindex280;  slog::Index** addindex281;  slog::Index** refindex282;  slog::Index** addindex283;  slog::Index** litindex284;  slog::Index** addindex285;  slog::Index** litindex286;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("root");
      std::vector<u16> ord288({0, 1});
      slog::Relation* readrel289 = db->getRelation("root");
      head_index[0] = readrel289->getIndex(ord288, false);
      head_rel[1] = db->getRelation("root");
      std::vector<u16> ord290({0, 1});
      slog::Relation* readrel291 = db->getRelation("root");
      head_index[1] = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 0, 2, 3});
      slog::Relation* readrel293 = db->getRelation("elet");
      driver_index = readrel293->getIndex(ord292, true);
      std::vector<u16> ord294({0, 1});
      slog::Relation* readrel295 = db->getRelation("lit");
      litindex267 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 0});
      slog::Relation* readrel297 = db->getRelation("lit");
      litindex268 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 2, 3, 0});
      slog::Relation* readrel299 = db->getRelation("elet");
      eletindex269 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 0});
      slog::Relation* readrel301 = db->getRelation("ref");
      refindex270 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 0});
      slog::Relation* readrel303 = db->getRelation("ref");
      refindex271 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 0});
      slog::Relation* readrel305 = db->getRelation("lit");
      litindex272 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({1, 0});
      slog::Relation* readrel307 = db->getRelation("lit");
      litindex273 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({0, 1, 2, 3});
      slog::Relation* readrel309 = db->getRelation("elet");
      eletindex274 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 0});
      slog::Relation* readrel311 = db->getRelation("lit");
      litindex275 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 3, 0});
      slog::Relation* readrel313 = db->getRelation("elet");
      eletindex276 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({0, 1, 2, 3});
      slog::Relation* readrel315 = db->getRelation("elet");
      eletindex277 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("ref");
      refindex278 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({0, 1, 2});
      slog::Relation* readrel319 = db->getRelation("add");
      addindex279 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 1, 2});
      slog::Relation* readrel321 = db->getRelation("add");
      addindex280 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({0, 1, 2});
      slog::Relation* readrel323 = db->getRelation("add");
      addindex281 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({0, 1});
      slog::Relation* readrel325 = db->getRelation("ref");
      refindex282 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({0, 1, 2});
      slog::Relation* readrel327 = db->getRelation("add");
      addindex283 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({0, 1});
      slog::Relation* readrel329 = db->getRelation("lit");
      litindex284 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({0, 1, 2});
      slog::Relation* readrel331 = db->getRelation("add");
      addindex285 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({0, 1});
      slog::Relation* readrel333 = db->getRelation("lit");
      litindex286 = readrel333->getIndex(ord332, false);
  
    }
    ReadTask287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0fc73630e591b4315396fe28;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c2 = v_const829a7fd574414cb9d628fa26;
      u64 v_c3 = v_const2bc983a5942276eb00a75e21;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_constef2d127de37b942baad06145;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,1>(driver_index, std::array<u64,4>{v_c1, 0, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m334) {
        u64 v_c28 = m334[1];
        u64 v_c16 = m334[2];
        u64 v_c27 = m334[3];
        if (buckethash(v_c28) != bucket) return;
        slog::join_probe<2,2>(litindex267, std::array<u64,2>{v_c16, v_c7}, [&](const std::array<u64,2>& m335) {
          if (!slog::exists_probe<2,1>(litindex268, std::array<u64,2>{v_c5, 0})) return;
          if (!slog::exists_probe<4,1>(eletindex269, std::array<u64,4>{v_c1, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex270, std::array<u64,2>{v_c1, 0})) return;
          if (!slog::exists_probe<2,1>(refindex271, std::array<u64,2>{v_c3, 0})) return;
          if (!slog::exists_probe<2,1>(litindex272, std::array<u64,2>{v_c8, 0})) return;
          if (!slog::exists_probe<2,1>(litindex273, std::array<u64,2>{v_c6, 0})) return;
          slog::join_probe<4,2>(eletindex274, std::array<u64,4>{v_c27, v_c3, 0, 0}, [&](const std::array<u64,4>& m336) {
            u64 v_c15 = m336[2]; u64 v_c13 = m336[3];
            slog::join_probe<2,1>(litindex275, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m337) {
              u64 v_c19 = m337[1];
              slog::join_probe<4,2>(eletindex276, std::array<u64,4>{v_c1, v_c19, 0, 0}, [&](const std::array<u64,4>& m338) {
                u64 v_c26 = m338[2]; u64 v_c29 = m338[3];
                slog::join_probe<4,2>(eletindex277, std::array<u64,4>{v_c26, v_c1, 0, 0}, [&](const std::array<u64,4>& m339) {
                  u64 v_c18 = m339[2]; u64 v_c10 = m339[3];
                  slog::join_probe<2,2>(refindex278, std::array<u64,2>{v_c10, v_c1}, [&](const std::array<u64,2>& m340) {
                    if (!slog::exists_probe<3,2>(addindex279, std::array<u64,3>{v_c15, v_c10, 0})) return;
                    if (!slog::exists_probe<3,2>(addindex280, std::array<u64,3>{v_c18, v_c10, 0})) return;
                    slog::join_probe<3,2>(addindex281, std::array<u64,3>{v_c13, v_c10, 0}, [&](const std::array<u64,3>& m341) {
                      u64 v_c12 = m341[2];
                      slog::join_probe<2,2>(refindex282, std::array<u64,2>{v_c12, v_c3}, [&](const std::array<u64,2>& m342) {
                        slog::join_probe<3,2>(addindex283, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m343) {
                          u64 v_c14 = m343[2];
                          slog::join_probe<2,2>(litindex284, std::array<u64,2>{v_c14, v_c8}, [&](const std::array<u64,2>& m344) {
                            slog::join_probe<3,2>(addindex285, std::array<u64,3>{v_c18, v_c10, 0}, [&](const std::array<u64,3>& m345) {
                              u64 v_c17 = m345[2];
                              slog::join_probe<2,2>(litindex286, std::array<u64,2>{v_c17, v_c6}, [&](const std::array<u64,2>& m346) {
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c29}, std::array<u16,2>{0, 1});
                                slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c2, v_c28}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("ex_let.slog:18", "delta:elet", _fires);
  
      if (!_done)
      {
        ReadTask287* _cont = new ReadTask287(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask287(db,b), false);
  // (crule (pre (let __tconst6p9h42 const0fc73630e591b4315396fe28) (let __tconst2vON40 constba2df4903a2c14e86dc3bcca) (let __tconst4guA28 const829a7fd574414cb9d628fa26) (let __tconst3hop22 const2bc983a5942276eb00a75e21) (let __tconst931g11 const9e5264d410a977c82c64ce0b) (let __tconst22C038 const6b86b273ff34fce19d6b804e) (let __tconst5jLG24 constd4735e3a265e16eee03f5971) (let __tconst6f1U7 const4e07408562bedb8b60ce05c1) (let __tconst9kxl31 constef2d127de37b942baad06145) (let __tconst2wJQ17 const4a44dc15364204a80fe80e90)) (seeded) (body (join ref (1 0) 1 __tconst2vON40 __t16aj3) (exists add (1 2 0) 1 __t16aj3) (exists lit (1 0) 1 __tconst9kxl31) (exists lit (1 0) 1 __tconst6f1U7) (exists elet (1 2 3 0) 1 __tconst2vON40) (exists lit (1 0) 1 __tconst5jLG24) (exists lit (1 0) 1 __tconst22C038) (exists ref (1 0) 1 __tconst3hop22) (exists elet (1 2 3 0) 1 __tconst3hop22) (exists lit (1 0) 1 __tconst2wJQ17) (join elet (1 3 0 2) 2 __tconst2vON40 __t16aj3 __t6d9537 __t29Rb35) (join add (0 1 2) 2 __t29Rb35 __t16aj3 __t10jL32) (join lit (0 1) 2 __t10jL32 __tconst9kxl31) (join lit (1 0) 1 __tconst6f1U7 __t4Fhy8) (join elet (1 2 3 0) 2 __tconst2vON40 __t4Fhy8 __t1EN56 __t4bd610) (join add (0 1 2) 2 __t1EN56 __t16aj3 dup87hp72) (eq __t16aj3 dup87hp72) (join lit (1 0) 1 __tconst5jLG24 __t5Rcx25) (join lit (1 0) 1 __tconst22C038 __t1Wwq39) (join ref (1 0) 1 __tconst3hop22 __t83nl13) (join add (1 2 0) 2 __t16aj3 __t83nl13 __t5cGy16) (join elet (1 3 0 2) 2 __tconst3hop22 __t5cGy16 __t573C23 __t5BpD21) (join add (0 1 2) 2 __t5BpD21 __t16aj3 __t3GHw18) (join lit (0 1) 2 __t3GHw18 __tconst2wJQ17)) (head (emit root (0 1) __tconst931g11 __t4bd610) (mkstruct elet (1 2 3 0) __t91ux41 __tconst2vON40 __t1Wwq39 __t6d9537) (mkstruct elet (1 2 3 0) __t6Hkm27 __tconst2vON40 __t5Rcx25 __t573C23)) ex_let.slog:18 #f)
  class ReadTask370 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex347;  slog::Index** addindex348;  slog::Index** litindex349;  slog::Index** litindex350;  slog::Index** eletindex351;  slog::Index** litindex352;  slog::Index** litindex353;  slog::Index** refindex354;  slog::Index** eletindex355;  slog::Index** litindex356;  slog::Index** eletindex357;  slog::Index** addindex358;  slog::Index** litindex359;  slog::Index** litindex360;  slog::Index** eletindex361;  slog::Index** addindex362;  slog::Index** litindex363;  slog::Index** litindex364;  slog::Index** refindex365;  slog::Index** addindex366;  slog::Index** eletindex367;  slog::Index** addindex368;  slog::Index** litindex369;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("root");
      std::vector<u16> ord371({0, 1});
      slog::Relation* readrel372 = db->getRelation("root");
      head_index[0] = readrel372->getIndex(ord371, false);
      head_rel[1] = db->getRelation("elet");
      std::vector<u16> ord373({1, 2, 3, 0});
      slog::Relation* readrel374 = db->getRelation("elet");
      head_index[1] = readrel374->getIndex(ord373, false);
      head_rel[2] = db->getRelation("elet");
      std::vector<u16> ord375({1, 2, 3, 0});
      slog::Relation* readrel376 = db->getRelation("elet");
      head_index[2] = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({1, 0});
      slog::Relation* readrel378 = db->getRelation("ref");
      refindex347 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 2, 0});
      slog::Relation* readrel380 = db->getRelation("add");
      addindex348 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 0});
      slog::Relation* readrel382 = db->getRelation("lit");
      litindex349 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({1, 0});
      slog::Relation* readrel384 = db->getRelation("lit");
      litindex350 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({1, 2, 3, 0});
      slog::Relation* readrel386 = db->getRelation("elet");
      eletindex351 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({1, 0});
      slog::Relation* readrel388 = db->getRelation("lit");
      litindex352 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({1, 0});
      slog::Relation* readrel390 = db->getRelation("lit");
      litindex353 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 0});
      slog::Relation* readrel392 = db->getRelation("ref");
      refindex354 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 2, 3, 0});
      slog::Relation* readrel394 = db->getRelation("elet");
      eletindex355 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 0});
      slog::Relation* readrel396 = db->getRelation("lit");
      litindex356 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({1, 3, 0, 2});
      slog::Relation* readrel398 = db->getRelation("elet");
      eletindex357 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({0, 1, 2});
      slog::Relation* readrel400 = db->getRelation("add");
      addindex358 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("lit");
      litindex359 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 0});
      slog::Relation* readrel404 = db->getRelation("lit");
      litindex360 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 3, 0});
      slog::Relation* readrel406 = db->getRelation("elet");
      eletindex361 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({0, 1, 2});
      slog::Relation* readrel408 = db->getRelation("add");
      addindex362 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({1, 0});
      slog::Relation* readrel410 = db->getRelation("lit");
      litindex363 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 0});
      slog::Relation* readrel412 = db->getRelation("lit");
      litindex364 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({1, 0});
      slog::Relation* readrel414 = db->getRelation("ref");
      refindex365 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({1, 2, 0});
      slog::Relation* readrel416 = db->getRelation("add");
      addindex366 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 3, 0, 2});
      slog::Relation* readrel418 = db->getRelation("elet");
      eletindex367 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({0, 1, 2});
      slog::Relation* readrel420 = db->getRelation("add");
      addindex368 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({0, 1});
      slog::Relation* readrel422 = db->getRelation("lit");
      litindex369 = readrel422->getIndex(ord421, false);
  
    }
    ReadTask370(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0fc73630e591b4315396fe28;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c2 = v_const829a7fd574414cb9d628fa26;
      u64 v_c3 = v_const2bc983a5942276eb00a75e21;
      u64 v_c4 = v_const9e5264d410a977c82c64ce0b;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c9 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c6 = v_constef2d127de37b942baad06145;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex347, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m423) {
        u64 v_c10 = m423[1];
        if (!slog::exists_probe<3,1>(addindex348, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<2,1>(litindex349, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(litindex350, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<4,1>(eletindex351, std::array<u64,4>{v_c1, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(litindex352, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(litindex353, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(refindex354, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<4,1>(eletindex355, std::array<u64,4>{v_c3, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(litindex356, std::array<u64,2>{v_c8, 0})) return;
        slog::join_probe<4,2>(eletindex357, std::array<u64,4>{v_c1, v_c10, 0, 0}, [&](const std::array<u64,4>& m424) {
          u64 v_c26 = m424[2]; u64 v_c18 = m424[3];
          slog::join_probe<3,2>(addindex358, std::array<u64,3>{v_c18, v_c10, 0}, [&](const std::array<u64,3>& m425) {
            u64 v_c17 = m425[2];
            slog::join_probe<2,2>(litindex359, std::array<u64,2>{v_c17, v_c6}, [&](const std::array<u64,2>& m426) {
              slog::join_probe<2,1>(litindex360, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m427) {
                u64 v_c11 = m427[1];
                slog::join_probe<4,2>(eletindex361, std::array<u64,4>{v_c1, v_c11, 0, 0}, [&](const std::array<u64,4>& m428) {
                  u64 v_c21 = m428[2]; u64 v_c24 = m428[3];
                  slog::join_probe<3,2>(addindex362, std::array<u64,3>{v_c21, v_c10, 0}, [&](const std::array<u64,3>& m429) {
                    u64 v_c30 = m429[2];
                    if (v_c10 != v_c30) return;
                    slog::join_probe<2,1>(litindex363, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m430) {
                      u64 v_c16 = m430[1];
                      slog::join_probe<2,1>(litindex364, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m431) {
                        u64 v_c19 = m431[1];
                        slog::join_probe<2,1>(refindex365, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m432) {
                          u64 v_c12 = m432[1];
                          slog::join_probe<3,2>(addindex366, std::array<u64,3>{v_c10, v_c12, 0}, [&](const std::array<u64,3>& m433) {
                            u64 v_c13 = m433[2];
                            slog::join_probe<4,2>(eletindex367, std::array<u64,4>{v_c3, v_c13, 0, 0}, [&](const std::array<u64,4>& m434) {
                              u64 v_c27 = m434[2]; u64 v_c15 = m434[3];
                              slog::join_probe<3,2>(addindex368, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m435) {
                                u64 v_c14 = m435[2];
                                slog::join_probe<2,2>(litindex369, std::array<u64,2>{v_c14, v_c8}, [&](const std::array<u64,2>& m436) {
                                  ++_fires;
                                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c24}, std::array<u16,2>{0, 1});
                                  slog::emit_struct_checked<4>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c1, v_c19, v_c26}, std::array<u16,4>{1, 2, 3, 0});
                                  slog::emit_struct_checked<4>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c1, v_c16, v_c27}, std::array<u16,4>{1, 2, 3, 0});
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("ex_let.slog:18", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask370(db,b));
  // (crule (pre (let __tconst6p9h42 const0fc73630e591b4315396fe28) (let __tconst2vON40 constba2df4903a2c14e86dc3bcca) (let __tconst4guA28 const829a7fd574414cb9d628fa26) (let __tconst3hop22 const2bc983a5942276eb00a75e21) (let __tconst22C038 const6b86b273ff34fce19d6b804e) (let __tconst5jLG24 constd4735e3a265e16eee03f5971) (let __tconst9kxl31 constef2d127de37b942baad06145) (let __tconst2wJQ17 const4a44dc15364204a80fe80e90)) (seeded) (body (join lit (1 0) 1 __tconst5jLG24 __t5Rcx25) (exists elet (1 2 3 0) 1 __tconst3hop22) (exists lit (1 0) 1 __tconst22C038) (exists elet (1 2 3 0) 1 __tconst2vON40) (exists ref (1 0) 1 __tconst2vON40) (exists ref (1 0) 1 __tconst3hop22) (exists lit (1 0) 1 __tconst2wJQ17) (exists lit (1 0) 1 __tconst9kxl31) (join elet (1 2 3 0) 2 __tconst2vON40 __t5Rcx25 __t573C23 __t6Hkm27) (join elet (0 1 2 3) 2 __t573C23 __tconst3hop22 __t5BpD21 __t5cGy16) (join lit (1 0) 1 __tconst22C038 __t1Wwq39) (join elet (1 2 3 0) 2 __tconst2vON40 __t1Wwq39 __t6d9537 __t91ux41) (join elet (0 1 2 3) 2 __t6d9537 __tconst2vON40 __t29Rb35 __t16aj3) (join ref (0 1) 2 __t16aj3 __tconst2vON40) (exists add (0 1 2) 2 __t5BpD21 __t16aj3) (exists add (0 1 2) 2 __t29Rb35 __t16aj3) (join add (0 1 2) 2 __t5cGy16 __t16aj3 __t83nl13) (join ref (0 1) 2 __t83nl13 __tconst3hop22) (join add (0 1 2) 2 __t5BpD21 __t16aj3 __t3GHw18) (join lit (0 1) 2 __t3GHw18 __tconst2wJQ17) (join add (0 1 2) 2 __t29Rb35 __t16aj3 __t10jL32) (join lit (0 1) 2 __t10jL32 __tconst9kxl31)) (head (emit root (0 1) __tconst6p9h42 __t91ux41) (emit root (0 1) __tconst4guA28 __t6Hkm27)) ex_let.slog:18 #f)
  class ReadTask459 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** litindex437;  slog::Index** eletindex438;  slog::Index** litindex439;  slog::Index** eletindex440;  slog::Index** refindex441;  slog::Index** refindex442;  slog::Index** litindex443;  slog::Index** litindex444;  slog::Index** eletindex445;  slog::Index** eletindex446;  slog::Index** litindex447;  slog::Index** eletindex448;  slog::Index** eletindex449;  slog::Index** refindex450;  slog::Index** addindex451;  slog::Index** addindex452;  slog::Index** addindex453;  slog::Index** refindex454;  slog::Index** addindex455;  slog::Index** litindex456;  slog::Index** addindex457;  slog::Index** litindex458;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("root");
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("root");
      head_index[0] = readrel461->getIndex(ord460, false);
      head_rel[1] = db->getRelation("root");
      std::vector<u16> ord462({0, 1});
      slog::Relation* readrel463 = db->getRelation("root");
      head_index[1] = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 0});
      slog::Relation* readrel465 = db->getRelation("lit");
      litindex437 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 2, 3, 0});
      slog::Relation* readrel467 = db->getRelation("elet");
      eletindex438 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 0});
      slog::Relation* readrel469 = db->getRelation("lit");
      litindex439 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 2, 3, 0});
      slog::Relation* readrel471 = db->getRelation("elet");
      eletindex440 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0});
      slog::Relation* readrel473 = db->getRelation("ref");
      refindex441 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 0});
      slog::Relation* readrel475 = db->getRelation("ref");
      refindex442 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 0});
      slog::Relation* readrel477 = db->getRelation("lit");
      litindex443 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 0});
      slog::Relation* readrel479 = db->getRelation("lit");
      litindex444 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 2, 3, 0});
      slog::Relation* readrel481 = db->getRelation("elet");
      eletindex445 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({0, 1, 2, 3});
      slog::Relation* readrel483 = db->getRelation("elet");
      eletindex446 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({1, 0});
      slog::Relation* readrel485 = db->getRelation("lit");
      litindex447 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({1, 2, 3, 0});
      slog::Relation* readrel487 = db->getRelation("elet");
      eletindex448 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({0, 1, 2, 3});
      slog::Relation* readrel489 = db->getRelation("elet");
      eletindex449 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({0, 1});
      slog::Relation* readrel491 = db->getRelation("ref");
      refindex450 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({0, 1, 2});
      slog::Relation* readrel493 = db->getRelation("add");
      addindex451 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1, 2});
      slog::Relation* readrel495 = db->getRelation("add");
      addindex452 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({0, 1, 2});
      slog::Relation* readrel497 = db->getRelation("add");
      addindex453 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({0, 1});
      slog::Relation* readrel499 = db->getRelation("ref");
      refindex454 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({0, 1, 2});
      slog::Relation* readrel501 = db->getRelation("add");
      addindex455 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({0, 1});
      slog::Relation* readrel503 = db->getRelation("lit");
      litindex456 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({0, 1, 2});
      slog::Relation* readrel505 = db->getRelation("add");
      addindex457 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({0, 1});
      slog::Relation* readrel507 = db->getRelation("lit");
      litindex458 = readrel507->getIndex(ord506, false);
  
    }
    ReadTask459(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0fc73630e591b4315396fe28;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c2 = v_const829a7fd574414cb9d628fa26;
      u64 v_c3 = v_const2bc983a5942276eb00a75e21;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_constef2d127de37b942baad06145;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(litindex437, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m508) {
        u64 v_c16 = m508[1];
        if (!slog::exists_probe<4,1>(eletindex438, std::array<u64,4>{v_c3, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(litindex439, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<4,1>(eletindex440, std::array<u64,4>{v_c1, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex441, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(refindex442, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(litindex443, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(litindex444, std::array<u64,2>{v_c6, 0})) return;
        slog::join_probe<4,2>(eletindex445, std::array<u64,4>{v_c1, v_c16, 0, 0}, [&](const std::array<u64,4>& m509) {
          u64 v_c27 = m509[2]; u64 v_c28 = m509[3];
          slog::join_probe<4,2>(eletindex446, std::array<u64,4>{v_c27, v_c3, 0, 0}, [&](const std::array<u64,4>& m510) {
            u64 v_c15 = m510[2]; u64 v_c13 = m510[3];
            slog::join_probe<2,1>(litindex447, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m511) {
              u64 v_c19 = m511[1];
              slog::join_probe<4,2>(eletindex448, std::array<u64,4>{v_c1, v_c19, 0, 0}, [&](const std::array<u64,4>& m512) {
                u64 v_c26 = m512[2]; u64 v_c29 = m512[3];
                slog::join_probe<4,2>(eletindex449, std::array<u64,4>{v_c26, v_c1, 0, 0}, [&](const std::array<u64,4>& m513) {
                  u64 v_c18 = m513[2]; u64 v_c10 = m513[3];
                  slog::join_probe<2,2>(refindex450, std::array<u64,2>{v_c10, v_c1}, [&](const std::array<u64,2>& m514) {
                    if (!slog::exists_probe<3,2>(addindex451, std::array<u64,3>{v_c15, v_c10, 0})) return;
                    if (!slog::exists_probe<3,2>(addindex452, std::array<u64,3>{v_c18, v_c10, 0})) return;
                    slog::join_probe<3,2>(addindex453, std::array<u64,3>{v_c13, v_c10, 0}, [&](const std::array<u64,3>& m515) {
                      u64 v_c12 = m515[2];
                      slog::join_probe<2,2>(refindex454, std::array<u64,2>{v_c12, v_c3}, [&](const std::array<u64,2>& m516) {
                        slog::join_probe<3,2>(addindex455, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m517) {
                          u64 v_c14 = m517[2];
                          slog::join_probe<2,2>(litindex456, std::array<u64,2>{v_c14, v_c8}, [&](const std::array<u64,2>& m518) {
                            slog::join_probe<3,2>(addindex457, std::array<u64,3>{v_c18, v_c10, 0}, [&](const std::array<u64,3>& m519) {
                              u64 v_c17 = m519[2];
                              slog::join_probe<2,2>(litindex458, std::array<u64,2>{v_c17, v_c6}, [&](const std::array<u64,2>& m520) {
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c29}, std::array<u16,2>{0, 1});
                                slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c2, v_c28}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("ex_let.slog:18", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask459(db,b));
  // (crule (pre (let __tconst6p9h42 const0fc73630e591b4315396fe28) (let __tconst2vON40 constba2df4903a2c14e86dc3bcca) (let __tconst22C038 const6b86b273ff34fce19d6b804e) (let __tconst9kxl31 constef2d127de37b942baad06145) (let __tconst4guA28 const829a7fd574414cb9d628fa26) (let __tconst5jLG24 constd4735e3a265e16eee03f5971) (let __tconst3hop22 const2bc983a5942276eb00a75e21) (let __tconst2wJQ17 const4a44dc15364204a80fe80e90) (let __tconst931g11 const9e5264d410a977c82c64ce0b) (let __tconst6f1U7 const4e07408562bedb8b60ce05c1)) (probe ref (1 0) 1 __tconst2vON40 __t16aj3) (body (exists ref (1 0) 1 __tconst3hop22) (exists lit (1 0) 1 __tconst2wJQ17) (exists lit (1 0) 1 __tconst5jLG24) (exists lit (1 0) 1 __tconst9kxl31) (exists lit (1 0) 1 __tconst22C038) (join lit (1 0) 1 __tconst6f1U7 __t4Fhy8) (join ref (1 0) 1 __tconst3hop22 __t83nl13) (join lit (1 0) 1 __tconst2wJQ17 __t3GHw18) (join lit (1 0) 1 __tconst5jLG24 __t5Rcx25) (join lit (1 0) 1 __tconst9kxl31 __t10jL32) (join lit (1 0) 1 __tconst22C038 __t1Wwq39)) (head (mkstruct add (1 2 0) __t29Rb35 __t16aj3 __t10jL32) (mkstruct add (1 2 0) __t5BpD21 __t16aj3 __t3GHw18) (mkstruct add (1 2 0) __t5cGy16 __t16aj3 __t83nl13) (mkstruct add (1 2 0) __t1EN56 __t16aj3 __t16aj3)) ex_let.slog:18 #f)
  class ReadTask532 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex521;  slog::Index** litindex522;  slog::Index** litindex523;  slog::Index** litindex524;  slog::Index** litindex525;  slog::Index** litindex526;  slog::Index** refindex527;  slog::Index** litindex528;  slog::Index** litindex529;  slog::Index** litindex530;  slog::Index** litindex531;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("add");
      head_rel[1] = db->getRelation("add");
      head_rel[2] = db->getRelation("add");
      head_rel[3] = db->getRelation("add");
      std::vector<u16> ord533({1, 0});
      slog::Relation* readrel534 = db->getRelation("ref");
      driver_index = readrel534->getIndex(ord533, true);
      std::vector<u16> ord535({1, 0});
      slog::Relation* readrel536 = db->getRelation("ref");
      refindex521 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 0});
      slog::Relation* readrel538 = db->getRelation("lit");
      litindex522 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 0});
      slog::Relation* readrel540 = db->getRelation("lit");
      litindex523 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 0});
      slog::Relation* readrel542 = db->getRelation("lit");
      litindex524 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 0});
      slog::Relation* readrel544 = db->getRelation("lit");
      litindex525 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 0});
      slog::Relation* readrel546 = db->getRelation("lit");
      litindex526 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 0});
      slog::Relation* readrel548 = db->getRelation("ref");
      refindex527 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({1, 0});
      slog::Relation* readrel550 = db->getRelation("lit");
      litindex528 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 0});
      slog::Relation* readrel552 = db->getRelation("lit");
      litindex529 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 0});
      slog::Relation* readrel554 = db->getRelation("lit");
      litindex530 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 0});
      slog::Relation* readrel556 = db->getRelation("lit");
      litindex531 = readrel556->getIndex(ord555, false);
  
    }
    ReadTask532(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0fc73630e591b4315396fe28;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_constef2d127de37b942baad06145;
      u64 v_c2 = v_const829a7fd574414cb9d628fa26;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const2bc983a5942276eb00a75e21;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
      u64 v_c4 = v_const9e5264d410a977c82c64ce0b;
      u64 v_c9 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c1, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m557) {
        u64 v_c10 = m557[1];
        if (buckethash(v_c10) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex521, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(litindex522, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(litindex523, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(litindex524, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(litindex525, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<2,1>(litindex526, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m558) {
          u64 v_c11 = m558[1];
          slog::join_probe<2,1>(refindex527, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m559) {
            u64 v_c12 = m559[1];
            slog::join_probe<2,1>(litindex528, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m560) {
              u64 v_c14 = m560[1];
              slog::join_probe<2,1>(litindex529, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m561) {
                u64 v_c16 = m561[1];
                slog::join_probe<2,1>(litindex530, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m562) {
                  u64 v_c17 = m562[1];
                  slog::join_probe<2,1>(litindex531, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m563) {
                    u64 v_c19 = m563[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c14}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c10, v_c12}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c10, v_c10}, std::array<u16,3>{1, 2, 0});
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
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("ex_let.slog:18", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask532* _cont = new ReadTask532(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask532(db,b), false);
  s->addReadRel("add");
  s->addReadRel("elet");
  s->addReadRel("lit");
  s->addReadRel("ref");
  s->addDynamicRel("_enum");
  s->addDynamicRel("add");
  s->addDynamicRel("elet");
  s->addDynamicRel("lit");
  s->addDynamicRel("ref");
  s->addDynamicRel("root");
  d->push(s);
  d->continueRun();
}

