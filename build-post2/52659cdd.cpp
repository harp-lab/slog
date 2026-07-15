
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const2c070a9498052f6e608df512;
u64 v_constf0add80747aca33dead79eea;
u64 v_const6d8bc911abd31f57d1b91158;
u64 v_const0dfced6e06d4ae6199e0f896;
u64 v_const439d97756c1f6d8e3f1b29c9;
u64 v_const5feceb66ffc86f38d952786c;
u64 v_constabce180ee56b2c323c19f642;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd1596cb698715803872591d6;
u64 v_conste7e898c68006c22d00270874;
u64 v_constc100f95c1913f9c72fc1f4ef;
u64 v_constac8d8342bbb2362d13f0a559;
u64 v_const4ab8424ce3e463ada0064da8;
u64 v_constf415be8f37f48a64565a412d;
u64 v_const12ae32cb1ec02d01eda3581b;
u64 v_const5c7fc02224fc3e7f3cf5fdfc;
u64 v_const04bd2b8089aaccc742a3c6c8;
u64 v_const30749c2c8a5c40a4f0a780b6;

void slog_rules_c000f683e5e76f6b0(slog::Database* db, slog::Stratum* s);
void slog_rules_c39d6ed8e25e73f9e(slog::Database* db, slog::Stratum* s);
void slog_rules_c4ad9e5821c4c179d(slog::Database* db, slog::Stratum* s);
void slog_rules_c52d32657b777eee0(slog::Database* db, slog::Stratum* s);


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("52659cdd");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const2c070a9498052f6e608df512 = db->encodeString("antimirov.slog:47");
  v_constf0add80747aca33dead79eea = db->encodeString("antimirov.slog:72");
  v_const6d8bc911abd31f57d1b91158 = db->encodeString("(a|b)*abb");
  v_const0dfced6e06d4ae6199e0f896 = db->encodeString("deriv");
  v_const439d97756c1f6d8e3f1b29c9 = db->encodeString("(a|ab)*");
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_constabce180ee56b2c323c19f642 = db->encodeString("eps");
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd1596cb698715803872591d6 = db->encodeString("nullable");
  v_conste7e898c68006c22d00270874 = db->encodeString("antimirov.slog:71");
  v_constc100f95c1913f9c72fc1f4ef = db->encodeString("b");
  v_constac8d8342bbb2362d13f0a559 = db->encodeString("a");
  v_const4ab8424ce3e463ada0064da8 = db->encodeString("antimirov.slog:84");
  v_constf415be8f37f48a64565a412d = db->encodeString("mkcat");
  v_const12ae32cb1ec02d01eda3581b = db->encodeString("");
  v_const5c7fc02224fc3e7f3cf5fdfc = db->encodeString("antimirov.slog:70");
  v_const04bd2b8089aaccc742a3c6c8 = db->encodeString("antimirov.slog:69");
  v_const30749c2c8a5c40a4f0a780b6 = db->encodeString("antimirov.slog:46");
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
  r = db->getRelation("temp8Et3328");
  if (r == 0) db->addTempRelation("temp8Et3328", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5pCD310");
  if (r == 0) db->addTempRelation("temp5pCD310", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5DUf326");
  if (r == 0) db->addTempRelation("temp5DUf326", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4sU7325");
  if (r == 0) db->addTempRelation("temp4sU7325", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4ebc327");
  if (r == 0) db->addTempRelation("temp4ebc327", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp31LP324");
  if (r == 0) db->addTempRelation("temp31LP324", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp262S323");
  if (r == 0) db->addTempRelation("temp262S323", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("subject");
  if (r == 0) db->addRelation("subject", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("subject");
      std::vector<u16> ord4({0});
    
    r->addIndex<1>(ord4, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("subject"), std::array<u16,1>{0}, b));
  r = db->getRelation("state");
  if (r == 0) db->addRelation("state", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("state");
      std::vector<u16> ord5({0});
    
    r->addIndex<1>(ord5, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
      std::vector<u16> ord6({0});
    
    r->addIndex<1>(ord6, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("state"), std::array<u16,1>{0}, b));
  r = db->getRelation("star");
  if (r == 0) db->addStruct("star", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("star");
      std::vector<u16> ord7({1, 0});
    
    r->addIndex<2>(ord7, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord8({0, 1});
    
    r->addIndex<2>(ord8, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord9({0, 1});
    
    r->addIndex<2>(ord9, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord10({1, 0});
    
    r->addIndex<2>(ord10, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("star"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord11({1, 2, 0});
    
    r->addIndex<3>(ord11, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord12({0, 1, 2});
    
    r->addIndex<3>(ord12, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("run_ans");
  if (r == 0) db->addRelation("run_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("run_ans");
      std::vector<u16> ord13({0, 1});
    
    r->addIndex<2>(ord13, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("run_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("run");
  if (r == 0) db->addStruct("run", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("run");
      std::vector<u16> ord14({1, 2, 0});
    
    r->addIndex<3>(ord14, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord15({0, 1, 2});
    
    r->addIndex<3>(ord15, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("run"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("query");
  if (r == 0) db->addRelation("query", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("query");
      std::vector<u16> ord16({0, 1});
    
    r->addIndex<2>(ord16, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("query"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nullable_ans");
  if (r == 0) db->addRelation("nullable_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nullable_ans");
      std::vector<u16> ord17({0, 1});
    
    r->addIndex<2>(ord17, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord18({0, 1});
    
    r->addIndex<2>(ord18, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("nullable_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nullable");
  if (r == 0) db->addStruct("nullable", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nullable");
      std::vector<u16> ord19({1, 0});
    
    r->addIndex<2>(ord19, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord20({0, 1});
    
    r->addIndex<2>(ord20, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord21({0, 1});
    
    r->addIndex<2>(ord21, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord22({1, 0});
    
    r->addIndex<2>(ord22, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("nullable"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("nfa");
  if (r == 0) db->addRelation("nfa", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nfa");
      std::vector<u16> ord23({0, 1, 2});
    
    r->addIndex<3>(ord23, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("nfa"), std::array<u16,3>{0, 1, 2}, b));
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
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord26({1, 2, 0});
    
    r->addIndex<3>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord27({0, 1, 2});
    
    r->addIndex<3>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord28({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord28, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord29({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord30({1, 2, 0});
    
    r->addIndex<3>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord31({0, 1, 2});
    
    r->addIndex<3>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mkcat_ans");
  if (r == 0) db->addRelation("mkcat_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mkcat_ans");
      std::vector<u16> ord32({0, 1});
    
    r->addIndex<2>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord33({0, 1});
    
    r->addIndex<2>(ord33, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mkcat_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mkcat");
  if (r == 0) db->addStruct("mkcat", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mkcat");
      std::vector<u16> ord34({1, 2, 0});
    
    r->addIndex<3>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord35({0, 1, 2});
    
    r->addIndex<3>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord36({2, 0, 1});
    
    r->addIndex<3>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord37({0, 1, 2});
    
    r->addIndex<3>(ord37, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord38({1, 2, 0});
    
    r->addIndex<3>(ord38, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mkcat"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("match");
  if (r == 0) db->addRelation("match", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("match");
      std::vector<u16> ord39({0, 1});
    
    r->addIndex<2>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("match"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord40({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord41({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord42({1, 2, 3, 0});
    
    r->addIndex<4>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord43({0, 1, 2, 3});
    
    r->addIndex<4>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("frag");
  if (r == 0) db->addRelation("frag", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("frag");
      std::vector<u16> ord44({0});
    
    r->addIndex<1>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("frag"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord45({0});
    
    r->addIndex<1>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord46({1, 2, 0});
    
    r->addIndex<3>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord47({0, 1, 2});
    
    r->addIndex<3>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("deriv_ans");
  if (r == 0) db->addRelation("deriv_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("deriv_ans");
      std::vector<u16> ord48({0, 1});
    
    r->addIndex<2>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord49({1, 0});
    
    r->addIndex<2>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord50({0, 1});
    
    r->addIndex<2>(ord50, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("deriv_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("deriv");
  if (r == 0) db->addStruct("deriv", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("deriv");
      std::vector<u16> ord51({1, 2, 0});
    
    r->addIndex<3>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord52({0, 1, 2});
    
    r->addIndex<3>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord53({2, 0, 1});
    
    r->addIndex<3>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord54({0, 1, 2});
    
    r->addIndex<3>(ord54, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord55({1, 2, 0});
    
    r->addIndex<3>(ord55, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord56({2, 0, 1});
    
    r->addIndex<3>(ord56, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("deriv"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("chr");
  if (r == 0) db->addStruct("chr", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("chr");
      std::vector<u16> ord57({1, 0});
    
    r->addIndex<2>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord58({0, 1});
    
    r->addIndex<2>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord59({0, 1});
    
    r->addIndex<2>(ord59, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord60({1, 0});
    
    r->addIndex<2>(ord60, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("chr"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("cat");
  if (r == 0) db->addStruct("cat", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("cat");
      std::vector<u16> ord61({1, 2, 0});
    
    r->addIndex<3>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord62({0, 1, 2});
    
    r->addIndex<3>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord63({2, 0, 1});
    
    r->addIndex<3>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord64({0, 1, 2});
    
    r->addIndex<3>(ord64, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord65({1, 2, 0});
    
    r->addIndex<3>(ord65, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord66({2, 0, 1});
    
    r->addIndex<3>(ord66, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("cat"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("alt");
  if (r == 0) db->addStruct("alt", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("alt");
      std::vector<u16> ord67({1, 2, 0});
    
    r->addIndex<3>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord68({0, 1, 2});
    
    r->addIndex<3>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord69({2, 0, 1});
    
    r->addIndex<3>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord70({0, 1, 2});
    
    r->addIndex<3>(ord70, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord71({1, 2, 0});
    
    r->addIndex<3>(ord71, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("alt"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("alpha");
  if (r == 0) db->addRelation("alpha", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("alpha");
      std::vector<u16> ord72({0});
    
    r->addIndex<1>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
      std::vector<u16> ord73({0});
    
    r->addIndex<1>(ord73, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("alpha"), std::array<u16,1>{0}, b));
  r = db->getRelation("accepting");
  if (r == 0) db->addRelation("accepting", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("accepting");
      std::vector<u16> ord74({0});
    
    r->addIndex<1>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("accepting"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord75({1, 0});
    
    r->addIndex<2>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord76({0, 1});
    
    r->addIndex<2>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup14449x83x0x0x0");
  if (r == 0) db->addRelation("$sup14449x83x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x83x0x0x0");
      std::vector<u16> ord77({2, 4, 0, 1, 3});
    
    r->addIndex<5>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 4, 0, 1, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup14449x83x0x0x0"), std::array<u16,5>{2, 4, 0, 1, 3}, b));
  r = db->getRelation("$sup14449x71x0x0x1");
  if (r == 0) db->addRelation("$sup14449x71x0x0x1", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x71x0x0x1");
      std::vector<u16> ord78({0, 2, 1, 3, 4, 5});
    
    r->addIndex<6>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 2, 1, 3, 4, 5}, false, b), true);
      std::vector<u16> ord79({1, 2, 3, 5, 4, 0});
    
    r->addIndex<6>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 3, 5, 4, 0}, false, b), false);
      std::vector<u16> ord80({1, 3, 4, 5, 0, 2});
    
    r->addIndex<6>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 5, 0, 2}, false, b), false);
      std::vector<u16> ord81({1, 4, 0, 2, 3, 5});
    
    r->addIndex<6>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 4, 0, 2, 3, 5}, false, b), false);
      std::vector<u16> ord82({2, 5, 0, 4, 1, 3});
    
    r->addIndex<6>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{2, 5, 0, 4, 1, 3}, false, b), false);
      std::vector<u16> ord83({4, 5, 0, 1, 2, 3});
    
    r->addIndex<6>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 5, 0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord84({1, 2, 3, 5, 4, 0});
    
    r->addIndex<6>(ord84, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 3, 5, 4, 0}, true, b), false);
      std::vector<u16> ord85({2, 5, 0, 4, 1, 3});
    
    r->addIndex<6>(ord85, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{2, 5, 0, 4, 1, 3}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup14449x71x0x0x1"), std::array<u16,6>{0, 2, 1, 3, 4, 5}, b));
  r = db->getRelation("$sup14449x71x0x0x0");
  if (r == 0) db->addRelation("$sup14449x71x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x71x0x0x0");
      std::vector<u16> ord86({2, 3, 0, 1});
    
    r->addIndex<4>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), true);
      std::vector<u16> ord87({0, 1, 2, 3});
    
    r->addIndex<4>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord88({1, 3, 2, 0});
    
    r->addIndex<4>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 2, 0}, false, b), false);
      std::vector<u16> ord89({1, 3, 2, 0});
    
    r->addIndex<4>(ord89, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup14449x71x0x0x0"), std::array<u16,4>{2, 3, 0, 1}, b));
  r = db->getRelation("$sup14449x70x0x0x0");
  if (r == 0) db->addRelation("$sup14449x70x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x70x0x0x0");
      std::vector<u16> ord90({3, 2, 0, 1});
    
    r->addIndex<4>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 2, 0, 1}, false, b), true);
      std::vector<u16> ord91({0, 1, 2, 3});
    
    r->addIndex<4>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord92({1, 2, 3, 0});
    
    r->addIndex<4>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), false);
      std::vector<u16> ord93({1, 2, 3, 0});
    
    r->addIndex<4>(ord93, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup14449x70x0x0x0"), std::array<u16,4>{3, 2, 0, 1}, b));
  r = db->getRelation("$sup14449x69x0x0x0");
  if (r == 0) db->addRelation("$sup14449x69x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x69x0x0x0");
      std::vector<u16> ord94({0, 1, 2, 3});
    
    r->addIndex<4>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
      std::vector<u16> ord95({1, 3, 0, 2});
    
    r->addIndex<4>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 0, 2}, false, b), false);
      std::vector<u16> ord96({2, 3, 0, 1});
    
    r->addIndex<4>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), false);
      std::vector<u16> ord97({1, 3, 0, 2});
    
    r->addIndex<4>(ord97, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 3, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup14449x69x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup14449x68x0x0x0");
  if (r == 0) db->addRelation("$sup14449x68x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x68x0x0x0");
      std::vector<u16> ord98({0, 1, 2, 3});
    
    r->addIndex<4>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
      std::vector<u16> ord99({1, 2, 0, 3});
    
    r->addIndex<4>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 0, 3}, false, b), false);
      std::vector<u16> ord100({2, 3, 0, 1});
    
    r->addIndex<4>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), false);
      std::vector<u16> ord101({1, 2, 0, 3});
    
    r->addIndex<4>(ord101, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 0, 3}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup14449x68x0x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$sup14449x46x0x0x0");
  if (r == 0) db->addRelation("$sup14449x46x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x46x0x0x0");
      std::vector<u16> ord102({0, 1, 2});
    
    r->addIndex<3>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord103({1, 2, 0});
    
    r->addIndex<3>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), false);
      std::vector<u16> ord104({2, 0, 1});
    
    r->addIndex<3>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord105({1, 2, 0});
    
    r->addIndex<3>(ord105, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord106({2, 0, 1});
    
    r->addIndex<3>(ord106, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup14449x46x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$sup14449x45x0x0x0");
  if (r == 0) db->addRelation("$sup14449x45x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup14449x45x0x0x0");
      std::vector<u16> ord107({0, 1, 2});
    
    r->addIndex<3>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord108({1, 2, 0});
    
    r->addIndex<3>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), false);
      std::vector<u16> ord109({2, 0, 1});
    
    r->addIndex<3>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord110({1, 2, 0});
    
    r->addIndex<3>(ord110, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord111({2, 0, 1});
    
    r->addIndex<3>(ord111, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup14449x45x0x0x0"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord112({0, 1, 2});
    
    r->addIndex<3>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("run"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  slog_rules_c000f683e5e76f6b0(db, s);
  slog_rules_c39d6ed8e25e73f9e(db, s);
  slog_rules_c4ad9e5821c4c179d(db, s);
  slog_rules_c52d32657b777eee0(db, s);
  s->addReadRel("$sup14449x45x0x0x0");
  s->addReadRel("$sup14449x46x0x0x0");
  s->addReadRel("$sup14449x68x0x0x0");
  s->addReadRel("$sup14449x69x0x0x0");
  s->addReadRel("$sup14449x70x0x0x0");
  s->addReadRel("$sup14449x71x0x0x0");
  s->addReadRel("$sup14449x71x0x0x1");
  s->addReadRel("$sup14449x83x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("alpha");
  s->addReadRel("alt");
  s->addReadRel("cat");
  s->addReadRel("chr");
  s->addReadRel("deriv");
  s->addReadRel("deriv_ans");
  s->addReadRel("div_by_zero");
  s->addReadRel("frag");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("mkcat");
  s->addReadRel("mkcat_ans");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("nullable");
  s->addReadRel("nullable_ans");
  s->addReadRel("query");
  s->addReadRel("run");
  s->addReadRel("star");
  s->addReadRel("state");
  s->addReadRel("subject");
  s->addReadRel("temp262S323");
  s->addReadRel("temp31LP324");
  s->addReadRel("temp4ebc327");
  s->addReadRel("temp4sU7325");
  s->addReadRel("temp5DUf326");
  s->addReadRel("temp5pCD310");
  s->addReadRel("temp8Et3328");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$sup14449x45x0x0x0");
  s->addDynamicRel("$sup14449x46x0x0x0");
  s->addDynamicRel("$sup14449x68x0x0x0");
  s->addDynamicRel("$sup14449x69x0x0x0");
  s->addDynamicRel("$sup14449x70x0x0x0");
  s->addDynamicRel("$sup14449x71x0x0x0");
  s->addDynamicRel("$sup14449x71x0x0x1");
  s->addDynamicRel("$sup14449x83x0x0x0");
  s->addDynamicRel("alpha");
  s->addDynamicRel("alt");
  s->addDynamicRel("cat");
  s->addDynamicRel("chr");
  s->addDynamicRel("deriv");
  s->addDynamicRel("deriv_ans");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("frag");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("mkcat");
  s->addDynamicRel("mkcat_ans");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("nfa");
  s->addDynamicRel("nullable");
  s->addDynamicRel("nullable_ans");
  s->addDynamicRel("query");
  s->addDynamicRel("run");
  s->addDynamicRel("star");
  s->addDynamicRel("state");
  s->addDynamicRel("temp262S323");
  s->addDynamicRel("temp31LP324");
  s->addDynamicRel("temp4ebc327");
  s->addDynamicRel("temp4sU7325");
  s->addDynamicRel("temp5DUf326");
  s->addDynamicRel("temp5pCD310");
  s->addDynamicRel("temp8Et3328");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("alpha");
  s->addAccelRel("deriv_ans");
  s->addAccelRel("frag");
  s->addAccelRel("mkcat_ans");
  s->addAccelRel("nfa");
  s->addAccelRel("nullable_ans");
  s->addAccelRel("query");
  s->addAccelRel("state");
  d->push(s);
  d->continueRun();
}

