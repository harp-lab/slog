
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_conste593eb62d5b2b78aac29610d;
u64 v_const019f836fc5ed4942d15bf125;
u64 v_const99071cf3586be89134ffc1b3;
u64 v_const830c2aa2e7d609d49bcea753;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("81fa179a");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_conste593eb62d5b2b78aac29610d = db->encodeString("_lam54764x26x19");
  v_const019f836fc5ed4942d15bf125 = db->encodeString("dem_lambda.slog:10");
  v_const99071cf3586be89134ffc1b3 = db->encodeString("_lam54764x26x40");
  v_const830c2aa2e7d609d49bcea753 = db->encodeString("map2");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord70({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord71({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("twice");
  if (r == 0) db->addRelation("twice", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("twice");
      std::vector<u16> ord72({0});
    
    r->addIndex<1>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("twice"), std::array<u16,1>{0}, b));
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
  r = db->getRelation("temp3se2241");
  if (r == 0) db->addTempRelation("temp3se2241", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
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
  r = db->getRelation("scaled");
  if (r == 0) db->addRelation("scaled", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("scaled");
      std::vector<u16> ord77({0});
    
    r->addIndex<1>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("scaled"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord78({1, 2, 3, 0});
    
    r->addIndex<4>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord79({0, 1, 2, 3});
    
    r->addIndex<4>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord80({1, 2, 0});
    
    r->addIndex<3>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord81({0, 1, 2});
    
    r->addIndex<3>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord82({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord83({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord84({1, 2, 0});
    
    r->addIndex<3>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord85({0, 1, 2});
    
    r->addIndex<3>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("map2_ans");
  if (r == 0) db->addRelation("map2_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map2_ans");
      std::vector<u16> ord86({0, 1});
    
    r->addIndex<2>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("map2_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("map2");
  if (r == 0) db->addStruct("map2", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("map2");
      std::vector<u16> ord87({1, 2, 0});
    
    r->addIndex<3>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord88({0, 1, 2});
    
    r->addIndex<3>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("map2"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord89({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord90({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("kv");
  if (r == 0) db->addRelation("kv", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("kv");
      std::vector<u16> ord91({0});
    
    r->addIndex<1>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("kv"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord92({1, 2, 3, 0});
    
    r->addIndex<4>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord93({0, 1, 2, 3});
    
    r->addIndex<4>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("input");
  if (r == 0) db->addRelation("input", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("input");
      std::vector<u16> ord94({0});
    
    r->addIndex<1>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("input"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord95({0});
    
    r->addIndex<1>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord96({1, 2, 0});
    
    r->addIndex<3>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord97({0, 1, 2});
    
    r->addIndex<3>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("compose_ans");
  if (r == 0) db->addRelation("compose_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("compose_ans");
      std::vector<u16> ord98({0, 1});
    
    r->addIndex<2>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("compose_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("compose");
  if (r == 0) db->addStruct("compose", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("compose");
      std::vector<u16> ord99({2, 1, 0});
    
    r->addIndex<3>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord100({0, 1, 2});
    
    r->addIndex<3>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("compose"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("apply1_ans");
  if (r == 0) db->addRelation("apply1_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply1_ans");
      std::vector<u16> ord101({0, 1});
    
    r->addIndex<2>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("apply1_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("apply1");
  if (r == 0) db->addStruct("apply1", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("apply1");
      std::vector<u16> ord102({1, 2, 0});
    
    r->addIndex<3>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord103({0, 1, 2});
    
    r->addIndex<3>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("apply1"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_lam54764x22x18");
  if (r == 0) db->addStruct("_lam54764x22x18", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_lam54764x22x18");
      std::vector<u16> ord104({1, 2, 0});
    
    r->addIndex<3>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord105({0, 1, 2});
    
    r->addIndex<3>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("_lam54764x22x18"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_lam54764x18x33");
  if (r == 0) db->addStruct("_lam54764x18x33", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_lam54764x18x33");
      std::vector<u16> ord106({1, 0});
    
    r->addIndex<2>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord107({0, 1});
    
    r->addIndex<2>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_lam54764x18x33"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord108({1, 0});
    
    r->addIndex<2>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord109({0, 1});
    
    r->addIndex<2>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord110({1, 0});
    
    r->addIndex<2>(ord110, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup54764x9x0x0x0");
  if (r == 0) db->addRelation("$sup54764x9x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup54764x9x0x0x0");
      std::vector<u16> ord111({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup54764x9x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup54764x22x18x0x0");
  if (r == 0) db->addRelation("$sup54764x22x18x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup54764x22x18x0x0");
      std::vector<u16> ord112({0, 1, 2, 3});
    
    r->addIndex<4>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup54764x22x18x0x0"), std::array<u16,4>{0, 1, 2, 3}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord113({0, 1, 2});
    
    r->addIndex<3>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("input"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("map2"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("map2_ans"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("scaled"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("twice"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan type_mismatch __erre2gmB228 __errf7YyD229 __errf2NBJ230 __errf04E9231 __errf0kEq232) (body) (head (emit error (0) __erre2gmB228)) <internal>:1 #f)
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
      outer_rel = db->getRelation("type_mismatch");
  
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
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
  // (crule (pre (let __tconst8zXO91 const99071cf3586be89134ffc1b3) (let __tconst6xpa92 conste593eb62d5b2b78aac29610d)) (probe _enum (1 0) 1 __tconst8zXO91 __t1AgY45) (body (exists compose (2 1 0) 1 __t1AgY45) (join _enum (1 0) 1 __tconst6xpa92 __t5Log46) (join compose (2 1 0) 2 __t1AgY45 __t5Log46 __t8THt47) (join compose_ans (0 1) 1 __t8THt47 h) (join input (0) 0 l)) (head (mkstruct map2 (1 2 0) __99bz93 h l)) dem_lambda.slog:26 #f)
  class ReadTask8 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** composeindex3;  slog::Index** _enumindex4;  slog::Index** composeindex5;  slog::Index** compose_ansindex6;  slog::Index** inputindex7;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("map2");
      std::vector<u16> ord9({1, 0});
      slog::Relation* readrel10 = db->getRelation("_enum");
      driver_index = readrel10->getIndex(ord9, true);
      std::vector<u16> ord11({2, 1, 0});
      slog::Relation* readrel12 = db->getRelation("compose");
      composeindex3 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({1, 0});
      slog::Relation* readrel14 = db->getRelation("_enum");
      _enumindex4 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({2, 1, 0});
      slog::Relation* readrel16 = db->getRelation("compose");
      composeindex5 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({0, 1});
      slog::Relation* readrel18 = db->getRelation("compose_ans");
      compose_ansindex6 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({0});
      slog::Relation* readrel20 = db->getRelation("input");
      inputindex7 = readrel20->getIndex(ord19, false);
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const99071cf3586be89134ffc1b3;
      u64 v_c6 = v_conste593eb62d5b2b78aac29610d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c5, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m21) {
        u64 v_c7 = m21[1];
        if (buckethash(v_c7) != bucket) return;
        if (!slog::exists_probe<3,1>(composeindex3, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex4, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m22) {
          u64 v_c8 = m22[1];
          slog::join_probe<3,2>(composeindex5, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m23) {
            u64 v_c9 = m23[2];
            slog::join_probe<2,1>(compose_ansindex6, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m24) {
              u64 v_c10 = m24[1];
              slog::join_all<1>(inputindex7, [&](const std::array<u64,1>& m25) {
                u64 v_c11 = m25[0];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c11}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:26", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask8* _cont = new ReadTask8(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask8(db,b), true);
  // (crule (pre) (scan mpz_overflow __erre7m0N233 __errf3WkT234 __errf1CLZ235 __errf0qZd236 __errf6cSd237) (body) (head (emit error (0) __erre7m0N233)) <internal>:1 #f)
  class ReadTask26 : public slog::Task
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
      std::vector<u16> ord27({0});
      slog::Relation* readrel28 = db->getRelation("error");
      head_index[0] = readrel28->getIndex(ord27, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask26(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c16 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask26* _cont = new ReadTask26(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask26(db,b), false);
  // (crule (pre) (scan div_by_zero __erre4l7T211 __errf8Dw5212 __errf8JIg213) (body) (head (emit error (0) __erre4l7T211)) <internal>:1 #f)
  class ReadTask29 : public slog::Task
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
      std::vector<u16> ord30({0});
      slog::Relation* readrel31 = db->getRelation("error");
      head_index[0] = readrel31->getIndex(ord30, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask29(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c17}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask29* _cont = new ReadTask29(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask29(db,b), false);
  // (crule (pre) (scan temp3se2241 k l) (body (join _lam54764x18x33 (1 0) 1 k __t7dpw48)) (head (mkstruct map2 (1 2 0) __6FCw100 __t7dpw48 l)) dem_lambda.slog:19 #f)
  class ReadTask33 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _lam54764x18x33index32;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("map2");
      outer_rel = db->getRelation("temp3se2241");
      std::vector<u16> ord34({1, 0});
      slog::Relation* readrel35 = db->getRelation("_lam54764x18x33");
      _lam54764x18x33index32 = readrel35->getIndex(ord34, false);
  
    }
    ReadTask33(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        slog::join_probe<2,1>(_lam54764x18x33index32, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m36) {
          u64 v_c21 = m36[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c21, v_c11}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:19", "delta:temp3se2241", _fires);
  
      if (!_done)
      {
        ReadTask33* _cont = new ReadTask33(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask33(db,b), false);
  // (crule (pre) (scan toint_range __erre5FZg225 __errf7rzh226 __errf3QLF227) (body) (head (emit error (0) __erre5FZg225)) <internal>:1 #f)
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
      outer_rel = db->getRelation("toint_range");
  
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
        u64 v_c22 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c22}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre0CFq217 __errf7FXC218 __errf80gL219 __errf9Wqt220) (body) (head (emit error (0) __erre0CFq217)) <internal>:1 #f)
  class ReadTask40 : public slog::Task
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
      std::vector<u16> ord41({0});
      slog::Relation* readrel42 = db->getRelation("error");
      head_index[0] = readrel42->getIndex(ord41, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask40(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask40* _cont = new ReadTask40(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask40(db,b), false);
  // (crule (pre (let _00024sqc10U765 const6b86b273ff34fce19d6b804e) (let _00024sqc4bRQ66 const5feceb66ffc86f38d952786c) (let _00024sqc4jya67 const6b86b273ff34fce19d6b804e) (let _00024sqc5oI268 const5feceb66ffc86f38d952786c)) (scan map2 __t8BVN23 f _00024seq0) (body (letp _00024sql1Lor63 (aslst _00024seq0)) (let _00024sqn0XrK64 (llen _00024sql1Lor63)) (cmp ge _00024sqn0XrK64 _00024sqc10U765) (letp x (lref _00024sql1Lor63 _00024sqc4bRQ66)) (let _00024sqp4cAa69 (_0002d _00024sqn0XrK64 _00024sqc5oI268)) (let xs (lslice _00024sql1Lor63 _00024sqc4jya67 _00024sqp4cAa69))) (head (emit $sup54764x9x0x0x0 (0 1 2 3 4) _00024seq0 __t8BVN23 f x xs)) dem_lambda.slog:10 #f)
  class ReadTask43 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup54764x9x0x0x0");
      std::vector<u16> ord44({0, 1, 2, 3, 4});
      slog::Relation* readrel45 = db->getRelation("$sup54764x9x0x0x0");
      head_index[0] = readrel45->getIndex(ord44, false);
      outer_rel = db->getRelation("map2");
  
    }
    ReadTask43(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c32 = v_const5feceb66ffc86f38d952786c;
  
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
        bool ok46 = true;
        u64 v_c36 = _prim_aslst(db, v_c35, &ok46);
        if (!ok46) return;
        u64 v_c37 = _prim_llen(db, v_c36);
        if (v_c37 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        u64 v_c38 = _prim_ge(db, v_c37, v_c29);
        if (v_c38 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        if (!v_c38) return;
        bool ok48 = true;
        u64 v_c39 = _prim_lref(db, v_c36, v_c30, &ok48);
        if (!ok48) return;
        u64 v_c40 = _prim__0002d(db, v_c37, v_c32);
        if (v_c40 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        u64 v_c41 = _prim_lslice(db, v_c36, v_c31, v_c40);
        if (v_c41 == slog_error) { slog::emit_pending_error(db, "dem_lambda.slog:10"); return; }
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c35, v_c33, v_c34, v_c39, v_c41}, std::array<u16,5>{0, 1, 2, 3, 4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:10", "delta:map2", _fires);
  
      if (!_done)
      {
        ReadTask43* _cont = new ReadTask43(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask43(db,b), false);
  // (crule (pre) (scan nan_result __erre3WE6221 __errf2auA222 __errf6TOf223 __errf2ZVG224) (body) (head (emit error (0) __erre3WE6221)) <internal>:1 #f)
  class ReadTask49 : public slog::Task
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
      std::vector<u16> ord50({0});
      slog::Relation* readrel51 = db->getRelation("error");
      head_index[0] = readrel51->getIndex(ord50, false);
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c42 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c44 = _t[2];
        u64 v_c45 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c42}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre) (scan input l) (body (join kv (0) 0 k)) (head (emit-temp temp3se2241 k l) (mkstruct _lam54764x18x33 (1 0) __t7dpw48 k)) dem_lambda.slog:19 #f)
  class ReadTask53 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** kvindex52;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3se2241");
      head_rel[1] = db->getRelation("_lam54764x18x33");
      outer_rel = db->getRelation("input");
      std::vector<u16> ord54({0});
      slog::Relation* readrel55 = db->getRelation("kv");
      kvindex52 = readrel55->getIndex(ord54, false);
  
    }
    ReadTask53(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[0];
        slog::join_all<1>(kvindex52, [&](const std::array<u64,1>& m56) {
          u64 v_c20 = m56[0];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c20, v_c11});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:19", "all:input", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre5HJV214 __errf6tXo215 __errf2dSV216) (body) (head (emit error (0) __erre5HJV214)) <internal>:1 #f)
  class ReadTask57 : public slog::Task
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
      std::vector<u16> ord58({0});
      slog::Relation* readrel59 = db->getRelation("error");
      head_index[0] = readrel59->getIndex(ord58, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask57(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask57* _cont = new ReadTask57(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask57(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre9Lpk238 __errf0NIh239 __errf7Sn2240) (body) (head (emit error (0) __erre9Lpk238)) <internal>:1 #f)
  class ReadTask60 : public slog::Task
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
      std::vector<u16> ord61({0});
      slog::Relation* readrel62 = db->getRelation("error");
      head_index[0] = readrel62->getIndex(ord61, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask60(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c51 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c49}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask60* _cont = new ReadTask60(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask60(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre54Xx206 __errf74bw207 __errf3WYo208 __errf8tIY209 __errf90DY210) (body) (head (emit error (0) __erre54Xx206)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord64({0});
      slog::Relation* readrel65 = db->getRelation("error");
      head_index[0] = readrel65->getIndex(ord64, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[2];
        u64 v_c55 = _t[3];
        u64 v_c56 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c52}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
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
  // (crule (pre (let __trid7o3j79 const019f836fc5ed4942d15bf125) (let __trel3G0o80 const830c2aa2e7d609d49bcea753) (let __tcol8GZ281 const5feceb66ffc86f38d952786c) (let __trel6GWL82 const830c2aa2e7d609d49bcea753) (let __tcol6qVY83 const6b86b273ff34fce19d6b804e)) (scan $sup54764x9x0x0x0 _00024seq0 __d0 f x xs) (body) (head (tycheck f (accept (struct _lam54764x18x33) (struct _lam54764x22x18) (struct _enum)) __trid7o3j79 __trel3G0o80 __tcol8GZ281 (1 2 3 4 0)) (tycheck xs (accept seq) __trid7o3j79 __trel6GWL82 __tcol6qVY83 (1 2 3 4 0)) (mkstruct map2 (1 2 0) __42gh78 f xs)) dem_lambda.slog:10 #f)
  class ReadTask69 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid68;  u32 sid66;  u32 sid67;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("map2");
      outer_rel = db->getRelation("$sup54764x9x0x0x0");
      sid68 = db->getRelation("_enum")->getStructId();
      sid66 = db->getRelation("_lam54764x18x33")->getStructId();
      sid67 = db->getRelation("_lam54764x22x18")->getStructId();
  
    }
    ReadTask69(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_const019f836fc5ed4942d15bf125;
      u64 v_c58 = v_const830c2aa2e7d609d49bcea753;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const830c2aa2e7d609d49bcea753;
      u64 v_c61 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c35 = _t[0];
        u64 v_c62 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c39 = _t[3];
        u64 v_c41 = _t[4];
        ++_fires;
        if (!((is_struct(v_c34) && (decode_struct_id(v_c34) == sid66 || decode_struct_id(v_c34) == sid67 || decode_struct_id(v_c34) == sid68))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c57, v_c58, v_c59, v_c34}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c41)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c57, v_c60, v_c61, v_c41}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c34, v_c41}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("dem_lambda.slog:10", "delta:$sup54764x9x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask69* _cont = new ReadTask69(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask69(db,b), false);
  s->addReadRel("$sup54764x9x0x0x0");
  s->addReadRel("_enum");
  s->addReadRel("_lam54764x18x33");
  s->addReadRel("compose");
  s->addReadRel("compose_ans");
  s->addReadRel("div_by_zero");
  s->addReadRel("input");
  s->addReadRel("int_overflow");
  s->addReadRel("kv");
  s->addReadRel("malformed_deduction");
  s->addReadRel("map2");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp3se2241");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$sup54764x9x0x0x0");
  s->addDynamicRel("_lam54764x18x33");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("map2");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("temp3se2241");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

