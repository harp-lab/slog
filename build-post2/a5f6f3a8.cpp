
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constef2d127de37b942baad06145;
u64 v_constd59eced1ded07f84c145592f;
u64 v_const9556b82499cc0aaf86aee7f0;
u64 v_const1bad6b8cf97131fceab8543e;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("a5f6f3a8");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_constd59eced1ded07f84c145592f = s32_encode(40);
  v_const9556b82499cc0aaf86aee7f0 = s32_encode(255);
  v_const1bad6b8cf97131fceab8543e = s32_encode(-1);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord71({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord72({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord73({1, 2, 0});
    
    r->addIndex<3>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord74({0, 1, 2});
    
    r->addIndex<3>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord75({1, 2, 0});
    
    r->addIndex<3>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord76({0, 1, 2});
    
    r->addIndex<3>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("roundtrip");
  if (r == 0) db->addRelation("roundtrip", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("roundtrip");
      std::vector<u16> ord77({0});
    
    r->addIndex<1>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("roundtrip"), std::array<u16,1>{0}, b));
  r = db->getRelation("psub");
  if (r == 0) db->addRelation("psub", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("psub");
      std::vector<u16> ord78({0});
    
    r->addIndex<1>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("psub"), std::array<u16,1>{0}, b));
  r = db->getRelation("pshr");
  if (r == 0) db->addRelation("pshr", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pshr");
      std::vector<u16> ord79({0});
    
    r->addIndex<1>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pshr"), std::array<u16,1>{0}, b));
  r = db->getRelation("pshl");
  if (r == 0) db->addRelation("pshl", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pshl");
      std::vector<u16> ord80({0});
    
    r->addIndex<1>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pshl"), std::array<u16,1>{0}, b));
  r = db->getRelation("ppow");
  if (r == 0) db->addRelation("ppow", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ppow");
      std::vector<u16> ord81({0});
    
    r->addIndex<1>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("ppow"), std::array<u16,1>{0}, b));
  r = db->getRelation("pmul");
  if (r == 0) db->addRelation("pmul", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pmul");
      std::vector<u16> ord82({0});
    
    r->addIndex<1>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pmul"), std::array<u16,1>{0}, b));
  r = db->getRelation("pmin");
  if (r == 0) db->addRelation("pmin", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pmin");
      std::vector<u16> ord83({0});
    
    r->addIndex<1>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pmin"), std::array<u16,1>{0}, b));
  r = db->getRelation("pmax");
  if (r == 0) db->addRelation("pmax", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pmax");
      std::vector<u16> ord84({0});
    
    r->addIndex<1>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pmax"), std::array<u16,1>{0}, b));
  r = db->getRelation("pdiv");
  if (r == 0) db->addRelation("pdiv", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pdiv");
      std::vector<u16> ord85({0});
    
    r->addIndex<1>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pdiv"), std::array<u16,1>{0}, b));
  r = db->getRelation("pbor");
  if (r == 0) db->addRelation("pbor", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pbor");
      std::vector<u16> ord86({0});
    
    r->addIndex<1>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pbor"), std::array<u16,1>{0}, b));
  r = db->getRelation("pband");
  if (r == 0) db->addRelation("pband", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pband");
      std::vector<u16> ord87({0});
    
    r->addIndex<1>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pband"), std::array<u16,1>{0}, b));
  r = db->getRelation("padd");
  if (r == 0) db->addRelation("padd", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("padd");
      std::vector<u16> ord88({0});
    
    r->addIndex<1>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("padd"), std::array<u16,1>{0}, b));
  r = db->getRelation("pabs");
  if (r == 0) db->addRelation("pabs", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pabs");
      std::vector<u16> ord89({0});
    
    r->addIndex<1>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pabs"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord90({1, 2, 3, 0});
    
    r->addIndex<4>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord91({0, 1, 2, 3});
    
    r->addIndex<4>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord92({1, 2, 0});
    
    r->addIndex<3>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord93({0, 1, 2});
    
    r->addIndex<3>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord94({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord95({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord96({1, 2, 0});
    
    r->addIndex<3>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord97({0, 1, 2});
    
    r->addIndex<3>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("maxi");
  if (r == 0) db->addRelation("maxi", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("maxi");
      std::vector<u16> ord98({0});
    
    r->addIndex<1>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("maxi"), std::array<u16,1>{0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord99({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord100({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord101({1, 2, 3, 0});
    
    r->addIndex<4>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord102({0, 1, 2, 3});
    
    r->addIndex<4>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord103({0});
    
    r->addIndex<1>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord104({1, 2, 0});
    
    r->addIndex<3>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord105({0, 1, 2});
    
    r->addIndex<3>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bigger");
  if (r == 0) db->addRelation("bigger", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bigger");
      std::vector<u16> ord106({0});
    
    r->addIndex<1>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("bigger"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord107({1, 0});
    
    r->addIndex<2>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord108({0, 1});
    
    r->addIndex<2>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst7rVQ15 const6b86b273ff34fce19d6b804e)) (scan maxi M) (body (let __t2dSU16 (_0002b M __tconst7rVQ15)) (let __t8Io417 (min __t2dSU16 M))) (head (emit pmin (0) __t8Io417)) int_promote.slog:41 #f)
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
      head_rel[0] = db->getRelation("pmin");
      std::vector<u16> ord1({0});
      slog::Relation* readrel2 = db->getRelation("pmin");
      head_index[0] = readrel2->getIndex(ord1, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c2 = _prim__0002b(db, v_c1, v_c0);
        if (v_c2 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:41"); return; }
        u64 v_c3 = _prim_min(db, v_c2, v_c1);
        if (v_c3 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:41"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:41", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask0(db,b), true);
  // (crule (pre) (scan mpz_overflow __erre6qpK103 __errf9joW104 __errf0wi2105 __errf0zAN106 __errf5uKP107) (body) (head (emit error (0) __erre6qpK103)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre4jQt87 __errf6nUF88 __errf72Xi89 __errf0VcM90) (body) (head (emit error (0) __erre4jQt87)) <internal>:1 #f)
  class ReadTask6 : public slog::Task
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
      std::vector<u16> ord7({0});
      slog::Relation* readrel8 = db->getRelation("error");
      head_index[0] = readrel8->getIndex(ord7, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask6* _cont = new ReadTask6(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask6(db,b), false);
  // (crule (pre (let __tconst4qnu40 const6b86b273ff34fce19d6b804e) (let __tconst29im43 const1bad6b8cf97131fceab8543e)) (scan maxi M) (body (let __t3j1x41 (_0002b M __tconst4qnu40)) (let __t4lJF42 (neg __t3j1x41)) (let __t99aC44 (_0002f __t4lJF42 __tconst29im43))) (head (emit pdiv (0) __t99aC44)) int_promote.slog:36 #f)
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
      head_rel[0] = db->getRelation("pdiv");
      std::vector<u16> ord10({0});
      slog::Relation* readrel11 = db->getRelation("pdiv");
      head_index[0] = readrel11->getIndex(ord10, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_const1bad6b8cf97131fceab8543e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c15 = _prim__0002b(db, v_c1, v_c13);
        if (v_c15 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:36"); return; }
        u64 v_c16 = _prim_neg(db, v_c15);
        if (v_c16 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:36"); return; }
        u64 v_c17 = _prim__0002f(db, v_c16, v_c14);
        if (v_c17 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:36"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c17}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:36", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask9(db,b), true);
  // (crule (pre (let __tconst69te1 const6b86b273ff34fce19d6b804e)) (scan maxi M) (body (let __t3Dht2 (_0002b M __tconst69te1)) (let __t5LUX3 (max __t3Dht2 M))) (head (emit pmax (0) __t5LUX3)) int_promote.slog:42 #f)
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
      head_rel[0] = db->getRelation("pmax");
      std::vector<u16> ord13({0});
      slog::Relation* readrel14 = db->getRelation("pmax");
      head_index[0] = readrel14->getIndex(ord13, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask12(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c18 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c19 = _prim__0002b(db, v_c1, v_c18);
        if (v_c19 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:42"); return; }
        u64 v_c20 = _prim_max(db, v_c19, v_c1);
        if (v_c20 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:42"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c20}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:42", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask12(db,b), true);
  // (crule (pre) (scan mpz_table_overflow __erre1zS2108 __errf7umr109 __errf9Tij110) (body) (head (emit error (0) __erre1zS2108)) <internal>:1 #f)
  class ReadTask15 : public slog::Task
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
      std::vector<u16> ord16({0});
      slog::Relation* readrel17 = db->getRelation("error");
      head_index[0] = readrel17->getIndex(ord16, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask15* _cont = new ReadTask15(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), false);
  // (crule (pre) (scan div_by_zero __erre8Qg781 __errf5c4m82 __errf5yYL83) (body) (head (emit error (0) __erre8Qg781)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord19({0});
      slog::Relation* readrel20 = db->getRelation("error");
      head_index[0] = readrel20->getIndex(ord19, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre (let __tconst1beE25 const6b86b273ff34fce19d6b804e)) (scan maxi M) (body (let __t2HzF24 (_0002b M __tconst1beE25)) (let __t2PFe26 (_0002d __t2HzF24 __tconst1beE25)) (join maxi (0) 1 __t2PFe26)) (head (emit roundtrip (0) __t2PFe26)) int_promote.slog:47 #f)
  class ReadTask22 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** maxiindex21;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("roundtrip");
      std::vector<u16> ord23({0});
      slog::Relation* readrel24 = db->getRelation("roundtrip");
      head_index[0] = readrel24->getIndex(ord23, false);
      outer_rel = db->getRelation("maxi");
      std::vector<u16> ord25({0});
      slog::Relation* readrel26 = db->getRelation("maxi");
      maxiindex21 = readrel26->getIndex(ord25, false);
  
    }
    ReadTask22(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c28 = _prim__0002b(db, v_c1, v_c27);
        if (v_c28 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:47"); return; }
        u64 v_c29 = _prim__0002d(db, v_c28, v_c27);
        if (v_c29 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:47"); return; }
        slog::join_probe<1,1>(maxiindex21, std::array<u64,1>{v_c29}, [&](const std::array<u64,1>& m27) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c29}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:47", "all:maxi", _fires);
  
      if (!_done)
      {
        ReadTask22* _cont = new ReadTask22(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask22(db,b), true);
  // (crule (pre (let __tconst3gGp33 constd59eced1ded07f84c145592f) (let __tconst3bWI34 const6b86b273ff34fce19d6b804e) (let __tconst3sEY36 constef2d127de37b942baad06145) (let __t6LbB35 (shl __tconst3bWI34 __tconst3gGp33)) (let __t4bOv37 (bor __t6LbB35 __tconst3sEY36))) (scan maxi M) (body) (head (emit pbor (0) __t4bOv37)) int_promote.slog:40 #f)
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
      head_rel[0] = db->getRelation("pbor");
      std::vector<u16> ord29({0});
      slog::Relation* readrel30 = db->getRelation("pbor");
      head_index[0] = readrel30->getIndex(ord29, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_constd59eced1ded07f84c145592f;
      u64 v_c31 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c32 = v_constef2d127de37b942baad06145;
      u64 v_c33 = _prim_shl(db, v_c31, v_c30);
      if (v_c33 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:40"); return true; }
      u64 v_c34 = _prim_bor(db, v_c33, v_c32);
      if (v_c34 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:40"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c34}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:40", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask28(db,b), true);
  // (crule (pre (let __tconst6wz618 constd59eced1ded07f84c145592f) (let __tconst49u319 constd4735e3a265e16eee03f5971) (let __t3uYH20 (pow __tconst49u319 __tconst6wz618))) (scan maxi M) (body) (head (emit ppow (0) __t3uYH20)) int_promote.slog:30 #f)
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
      head_rel[0] = db->getRelation("ppow");
      std::vector<u16> ord32({0});
      slog::Relation* readrel33 = db->getRelation("ppow");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask31(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c35 = v_constd59eced1ded07f84c145592f;
      u64 v_c36 = v_constd4735e3a265e16eee03f5971;
      u64 v_c37 = _prim_pow(db, v_c36, v_c35);
      if (v_c37 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:30"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c37}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:30", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask31(db,b), true);
  // (crule (pre (let __tconst656G38 const6b86b273ff34fce19d6b804e)) (scan maxi M) (body (let __t5ijB39 (_0002b M __tconst656G38)) (cmp gt __t5ijB39 M)) (head (emit bigger (0) __t5ijB39)) int_promote.slog:44 #f)
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
      head_rel[0] = db->getRelation("bigger");
      std::vector<u16> ord35({0});
      slog::Relation* readrel36 = db->getRelation("bigger");
      head_index[0] = readrel36->getIndex(ord35, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask34(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c39 = _prim__0002b(db, v_c1, v_c38);
        if (v_c39 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:44"); return; }
        u64 v_c40 = _prim_gt(db, v_c39, v_c1);
        if (v_c40 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:44"); return; }
        if (!v_c40) return;
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:44", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask34(db,b), true);
  // (crule (pre) (scan type_mismatch __erre8oqF98 __errf4htb99 __errf7zgf100 __errf2AJX101 __errf4h7s102) (body) (head (emit error (0) __erre8oqF98)) <internal>:1 #f)
  class ReadTask38 : public slog::Task
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
      std::vector<u16> ord39({0});
      slog::Relation* readrel40 = db->getRelation("error");
      head_index[0] = readrel40->getIndex(ord39, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask38(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[3];
        u64 v_c45 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c41}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask38* _cont = new ReadTask38(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask38(db,b), false);
  // (crule (pre) (scan toint_range __erre9Kys95 __errf4C4B96 __errf2xrI97) (body) (head (emit error (0) __erre9Kys95)) <internal>:1 #f)
  class ReadTask41 : public slog::Task
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
      std::vector<u16> ord42({0});
      slog::Relation* readrel43 = db->getRelation("error");
      head_index[0] = readrel43->getIndex(ord42, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask41(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
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
  // (crule (pre (let __tconst5sEH4 constd59eced1ded07f84c145592f) (let __tconst5AXP5 const6b86b273ff34fce19d6b804e) (let __tconst4Vf17 const9556b82499cc0aaf86aee7f0) (let __t5k8a6 (shl __tconst5AXP5 __tconst5sEH4)) (let __t9K158 (band __t5k8a6 __tconst4Vf17))) (scan maxi M) (body) (head (emit pband (0) __t9K158)) int_promote.slog:39 #f)
  class ReadTask44 : public slog::Task
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
      head_rel[0] = db->getRelation("pband");
      std::vector<u16> ord45({0});
      slog::Relation* readrel46 = db->getRelation("pband");
      head_index[0] = readrel46->getIndex(ord45, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask44(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_constd59eced1ded07f84c145592f;
      u64 v_c50 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c51 = v_const9556b82499cc0aaf86aee7f0;
      u64 v_c52 = _prim_shl(db, v_c50, v_c49);
      if (v_c52 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:39"); return true; }
      u64 v_c53 = _prim_band(db, v_c52, v_c51);
      if (v_c53 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:39"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:39", "all:maxi", _fires);
  
      if (!_done)
      {
        ReadTask44* _cont = new ReadTask44(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask44(db,b), true);
  // (crule (pre (let __tconst8cHP21 constd4735e3a265e16eee03f5971)) (scan maxi M) (body (let __t3rDs22 (_0002a M __tconst8cHP21))) (head (emit pmul (0) __t3rDs22)) int_promote.slog:28 #f)
  class ReadTask47 : public slog::Task
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
      head_rel[0] = db->getRelation("pmul");
      std::vector<u16> ord48({0});
      slog::Relation* readrel49 = db->getRelation("pmul");
      head_index[0] = readrel49->getIndex(ord48, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask47(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c55 = _prim__0002a(db, v_c1, v_c54);
        if (v_c55 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:28"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c55}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:28", "all:maxi", _fires);
  
      if (!_done)
      {
        ReadTask47* _cont = new ReadTask47(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask47(db,b), true);
  // (crule (pre (let __tconst1Tex31 const6b86b273ff34fce19d6b804e)) (scan maxi M) (body (let __t9MMg32 (_0002b M __tconst1Tex31))) (head (emit padd (0) __t9MMg32)) int_promote.slog:27 #f)
  class ReadTask50 : public slog::Task
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
      head_rel[0] = db->getRelation("padd");
      std::vector<u16> ord51({0});
      slog::Relation* readrel52 = db->getRelation("padd");
      head_index[0] = readrel52->getIndex(ord51, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask50(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c57 = _prim__0002b(db, v_c1, v_c56);
        if (v_c57 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:27"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:27", "all:maxi", _fires);
  
      if (!_done)
      {
        ReadTask50* _cont = new ReadTask50(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask50(db,b), true);
  // (crule (pre (let __tconst5MrN12 constd59eced1ded07f84c145592f) (let __tconst8jZ113 const6b86b273ff34fce19d6b804e) (let __t6lJ314 (shl __tconst8jZ113 __tconst5MrN12))) (scan maxi M) (body) (head (emit pshl (0) __t6lJ314)) int_promote.slog:31 #f)
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
      head_rel[0] = db->getRelation("pshl");
      std::vector<u16> ord54({0});
      slog::Relation* readrel55 = db->getRelation("pshl");
      head_index[0] = readrel55->getIndex(ord54, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask53(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_constd59eced1ded07f84c145592f;
      u64 v_c59 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c60 = _prim_shl(db, v_c59, v_c58);
      if (v_c60 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:31"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c60}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:31", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask53(db,b), true);
  // (crule (pre (let __tconst7E529 constd4735e3a265e16eee03f5971)) (scan maxi M) (body (let __t7Ns110 (neg M)) (let __t6MLk11 (_0002d __t7Ns110 __tconst7E529))) (head (emit psub (0) __t6MLk11)) int_promote.slog:29 #f)
  class ReadTask56 : public slog::Task
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
      head_rel[0] = db->getRelation("psub");
      std::vector<u16> ord57({0});
      slog::Relation* readrel58 = db->getRelation("psub");
      head_index[0] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c62 = _prim_neg(db, v_c1);
        if (v_c62 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:29"); return; }
        u64 v_c63 = _prim__0002d(db, v_c62, v_c61);
        if (v_c63 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:29"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c63}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:29", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask56(db,b), true);
  // (crule (pre (let __tconst83l627 const6b86b273ff34fce19d6b804e)) (scan maxi M) (body (let __t1F4q28 (_0002b M __tconst83l627)) (let __t6phn29 (neg __t1F4q28)) (let __t558j30 (abs __t6phn29))) (head (emit pabs (0) __t558j30)) int_promote.slog:37 #f)
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
      head_rel[0] = db->getRelation("pabs");
      std::vector<u16> ord60({0});
      slog::Relation* readrel61 = db->getRelation("pabs");
      head_index[0] = readrel61->getIndex(ord60, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask59(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c64 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c65 = _prim__0002b(db, v_c1, v_c64);
        if (v_c65 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:37"); return; }
        u64 v_c66 = _prim_neg(db, v_c65);
        if (v_c66 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:37"); return; }
        u64 v_c67 = _prim_abs(db, v_c66);
        if (v_c67 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:37"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c67}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:37", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask59(db,b), true);
  // (crule (pre (let __tconst9kum46 const6b86b273ff34fce19d6b804e) (let __tconst2eFt48 constd59eced1ded07f84c145592f) (let __t9cxA47 (shl __tconst9kum46 __tconst2eFt48)) (let __t5yXM49 (shr __t9cxA47 __tconst2eFt48))) (scan maxi M) (body) (head (emit pshr (0) __t5yXM49)) int_promote.slog:32 #f)
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
      head_rel[0] = db->getRelation("pshr");
      std::vector<u16> ord63({0});
      slog::Relation* readrel64 = db->getRelation("pshr");
      head_index[0] = readrel64->getIndex(ord63, false);
      outer_rel = db->getRelation("maxi");
  
    }
    ReadTask62(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c68 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c69 = v_constd59eced1ded07f84c145592f;
      u64 v_c70 = _prim_shl(db, v_c68, v_c69);
      if (v_c70 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:32"); return true; }
      u64 v_c71 = _prim_shr(db, v_c70, v_c69);
      if (v_c71 == slog_error) { slog::emit_pending_error(db, "int_promote.slog:32"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c71}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("int_promote.slog:32", "all:maxi", _fires);
  
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
      s->addTask(phase_read, new ReadTask62(db,b), true);
  // (crule (pre) (scan nan_result __erre8z6q91 __errf3Lcf92 __errf4FKz93 __errf6IGF94) (body) (head (emit error (0) __erre8z6q91)) <internal>:1 #f)
  class ReadTask65 : public slog::Task
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
      std::vector<u16> ord66({0});
      slog::Relation* readrel67 = db->getRelation("error");
      head_index[0] = readrel67->getIndex(ord66, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask65(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c72 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c74 = _t[2];
        u64 v_c75 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c72}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask65* _cont = new ReadTask65(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask65(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre9vE784 __errf5O5J85 __errf9foB86) (body) (head (emit error (0) __erre9vE784)) <internal>:1 #f)
  class ReadTask68 : public slog::Task
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
      std::vector<u16> ord69({0});
      slog::Relation* readrel70 = db->getRelation("error");
      head_index[0] = readrel70->getIndex(ord69, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask68(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c76 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c78 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c76}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask68* _cont = new ReadTask68(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask68(db,b), false);
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("maxi");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("bigger");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("pabs");
  s->addDynamicRel("padd");
  s->addDynamicRel("pband");
  s->addDynamicRel("pbor");
  s->addDynamicRel("pdiv");
  s->addDynamicRel("pmax");
  s->addDynamicRel("pmin");
  s->addDynamicRel("pmul");
  s->addDynamicRel("ppow");
  s->addDynamicRel("pshl");
  s->addDynamicRel("pshr");
  s->addDynamicRel("psub");
  s->addDynamicRel("roundtrip");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

