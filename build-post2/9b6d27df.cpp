
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_constb7edbb1d306a68faf170673e;
u64 v_constb8736b999909049671d0ea07;
u64 v_const114662d43e5a7e5a16f8ea2b;
u64 v_constd84bdb34d4eeef4034d77e54;
u64 v_constfbd04e1aae9ce0b11a8946e2;
u64 v_consta416ea84421fa7e1351582da;
u64 v_const8ab31b5afaea56114427e1f0;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("9b6d27df");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_constb7edbb1d306a68faf170673e = float_encode(9.0);
  v_constb8736b999909049671d0ea07 = float_encode(2.5);
  v_const114662d43e5a7e5a16f8ea2b = float_encode(6.25);
  v_constd84bdb34d4eeef4034d77e54 = float_encode(2.0);
  v_constfbd04e1aae9ce0b11a8946e2 = float_encode(4.0);
  v_consta416ea84421fa7e1351582da = float_encode(3.0);
  v_const8ab31b5afaea56114427e1f0 = float_encode(6.0);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord15({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord15, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord16({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord16, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord17({1, 2, 0});
    
    r->addIndex<3>(ord17, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord18({0, 1, 2});
    
    r->addIndex<3>(ord18, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ti");
  if (r == 0) db->addRelation("ti", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ti");
      std::vector<u16> ord19({0, 1});
    
    r->addIndex<2>(ord19, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ti"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("tf");
  if (r == 0) db->addRelation("tf", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tf");
      std::vector<u16> ord20({0, 1});
    
    r->addIndex<2>(ord20, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("tf"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord21({1, 2, 0});
    
    r->addIndex<3>(ord21, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord22({0, 1, 2});
    
    r->addIndex<3>(ord22, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nplus");
  if (r == 0) db->addRelation("nplus", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nplus");
      std::vector<u16> ord23({0});
    
    r->addIndex<1>(ord23, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("nplus"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord24({1, 2, 3, 0});
    
    r->addIndex<4>(ord24, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord25({0, 1, 2, 3});
    
    r->addIndex<4>(ord25, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("n");
  if (r == 0) db->addRelation("n", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("n");
      std::vector<u16> ord26({0});
    
    r->addIndex<1>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("n"), std::array<u16,1>{0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord27({1, 2, 0});
    
    r->addIndex<3>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord28({0, 1, 2});
    
    r->addIndex<3>(ord28, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord29({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord30({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord31({1, 2, 0});
    
    r->addIndex<3>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord32({0, 1, 2});
    
    r->addIndex<3>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord33({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord33, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord34({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord35({1, 2, 3, 0});
    
    r->addIndex<4>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord36({0, 1, 2, 3});
    
    r->addIndex<4>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("fsub");
  if (r == 0) db->addRelation("fsub", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fsub");
      std::vector<u16> ord37({0, 1, 2});
    
    r->addIndex<3>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("fsub"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("fsqrt");
  if (r == 0) db->addRelation("fsqrt", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fsqrt");
      std::vector<u16> ord38({0, 1});
    
    r->addIndex<2>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("fsqrt"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("fround");
  if (r == 0) db->addRelation("fround", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fround");
      std::vector<u16> ord39({0, 1});
    
    r->addIndex<2>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("fround"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("fpow");
  if (r == 0) db->addRelation("fpow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fpow");
      std::vector<u16> ord40({0, 1, 2});
    
    r->addIndex<3>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("fpow"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("fneg");
  if (r == 0) db->addRelation("fneg", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fneg");
      std::vector<u16> ord41({0, 1});
    
    r->addIndex<2>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("fneg"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("fmul");
  if (r == 0) db->addRelation("fmul", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fmul");
      std::vector<u16> ord42({0, 1, 2});
    
    r->addIndex<3>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("fmul"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("fmod2");
  if (r == 0) db->addRelation("fmod2", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fmod2");
      std::vector<u16> ord43({0, 1, 2});
    
    r->addIndex<3>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("fmod2"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("fmin");
  if (r == 0) db->addRelation("fmin", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fmin");
      std::vector<u16> ord44({0, 1, 2});
    
    r->addIndex<3>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("fmin"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("fmax");
  if (r == 0) db->addRelation("fmax", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fmax");
      std::vector<u16> ord45({0, 1, 2});
    
    r->addIndex<3>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("fmax"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("ffloor");
  if (r == 0) db->addRelation("ffloor", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ffloor");
      std::vector<u16> ord46({0, 1});
    
    r->addIndex<2>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ffloor"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("fdiv");
  if (r == 0) db->addRelation("fdiv", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fdiv");
      std::vector<u16> ord47({0, 1, 2});
    
    r->addIndex<3>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("fdiv"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("fceil");
  if (r == 0) db->addRelation("fceil", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fceil");
      std::vector<u16> ord48({0, 1});
    
    r->addIndex<2>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("fceil"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("fadd");
  if (r == 0) db->addRelation("fadd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fadd");
      std::vector<u16> ord49({0, 1, 2});
    
    r->addIndex<3>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("fadd"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("fabsd");
  if (r == 0) db->addRelation("fabsd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fabsd");
      std::vector<u16> ord50({0, 1, 2});
    
    r->addIndex<3>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("fabsd"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("f2");
  if (r == 0) db->addRelation("f2", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("f2");
      std::vector<u16> ord51({0, 1});
    
    r->addIndex<2>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("f2"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("f1");
  if (r == 0) db->addRelation("f1", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("f1");
      std::vector<u16> ord52({0});
    
    r->addIndex<1>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("f1"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord53({0});
    
    r->addIndex<1>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord54({1, 2, 0});
    
    r->addIndex<3>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord55({0, 1, 2});
    
    r->addIndex<3>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord56({1, 0});
    
    r->addIndex<2>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord57({0, 1});
    
    r->addIndex<2>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst1pNL23 const4a44dc15364204a80fe80e90) (let __tconst70wR22 const4e07408562bedb8b60ce05c1) (let __tconst4Lpu21 constb7edbb1d306a68faf170673e) (let __tconst05va20 constb8736b999909049671d0ea07) (let __tconst9Fa419 const114662d43e5a7e5a16f8ea2b) (let __tconst6IN818 consta416ea84421fa7e1351582da) (let __tconst2Ptd17 constd84bdb34d4eeef4034d77e54) (let __tconst2xVR16 const8ab31b5afaea56114427e1f0) (let __tconst4yfH15 constfbd04e1aae9ce0b11a8946e2)) (once) (body) (head (emit n (0) __tconst1pNL23) (emit n (0) __tconst70wR22) (emit f1 (0) __tconst4Lpu21) (emit f1 (0) __tconst05va20) (emit f1 (0) __tconst9Fa419) (emit f2 (0 1) __tconst6IN818 __tconst2Ptd17) (emit f2 (0 1) __tconst2xVR16 __tconst4yfH15)) prim_float.slog:29 #f)
  class ReadTask0 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n");
      std::vector<u16> ord1({0});
      slog::Relation* readrel2 = db->getRelation("n");
      head_index[0] = readrel2->getIndex(ord1, false);
      head_rel[1] = db->getRelation("n");
      std::vector<u16> ord3({0});
      slog::Relation* readrel4 = db->getRelation("n");
      head_index[1] = readrel4->getIndex(ord3, false);
      head_rel[2] = db->getRelation("f1");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("f1");
      head_index[2] = readrel6->getIndex(ord5, false);
      head_rel[3] = db->getRelation("f1");
      std::vector<u16> ord7({0});
      slog::Relation* readrel8 = db->getRelation("f1");
      head_index[3] = readrel8->getIndex(ord7, false);
      head_rel[4] = db->getRelation("f1");
      std::vector<u16> ord9({0});
      slog::Relation* readrel10 = db->getRelation("f1");
      head_index[4] = readrel10->getIndex(ord9, false);
      head_rel[5] = db->getRelation("f2");
      std::vector<u16> ord11({0, 1});
      slog::Relation* readrel12 = db->getRelation("f2");
      head_index[5] = readrel12->getIndex(ord11, false);
      head_rel[6] = db->getRelation("f2");
      std::vector<u16> ord13({0, 1});
      slog::Relation* readrel14 = db->getRelation("f2");
      head_index[6] = readrel14->getIndex(ord13, false);
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4a44dc15364204a80fe80e90;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_constb7edbb1d306a68faf170673e;
      u64 v_c3 = v_constb8736b999909049671d0ea07;
      u64 v_c4 = v_const114662d43e5a7e5a16f8ea2b;
      u64 v_c5 = v_consta416ea84421fa7e1351582da;
      u64 v_c6 = v_constd84bdb34d4eeef4034d77e54;
      u64 v_c7 = v_const8ab31b5afaea56114427e1f0;
      u64 v_c8 = v_constfbd04e1aae9ce0b11a8946e2;
  
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
      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[3], head_index[3], newbatch[3], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[4], head_index[4], newbatch[4], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
      slog::emit<2>(head_rel[5], head_index[5], newbatch[5], std::array<u64,2>{v_c5, v_c6}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[6], head_index[6], newbatch[6], std::array<u64,2>{v_c7, v_c8}, std::array<u16,2>{0, 1});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("prim_float.slog:29", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  s->addDynamicRel("f1");
  s->addDynamicRel("f2");
  s->addDynamicRel("n");
  d->push(s);
  d->continueRun();
}

