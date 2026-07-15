
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constef2d127de37b942baad06145;
u64 v_conste7f6c011776e8db7cd330b54;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const2c624232cdd221771294dfbb;
u64 v_const19581e27de7ced00ff1ce50b;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("88726feb");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_conste7f6c011776e8db7cd330b54 = s32_encode(6);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const2c624232cdd221771294dfbb = s32_encode(8);
  v_const19581e27de7ced00ff1ce50b = s32_encode(9);
  r = db->getRelation("wrap");
  if (r == 0) db->addStruct("wrap", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("wrap");
      std::vector<u16> ord81({2, 1, 0});
    
    r->addIndex<3>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord82({0, 1, 2});
    
    r->addIndex<3>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord83({2, 0, 1});
    
    r->addIndex<3>(ord83, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("wrap"), std::array<u16,3>{2, 1, 0}, b));
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
  r = db->getRelation("temp7zgv27");
  if (r == 0) db->addTempRelation("temp7zgv27", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3R9b28");
  if (r == 0) db->addTempRelation("temp3R9b28", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1ry726");
  if (r == 0) db->addTempRelation("temp1ry726", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("src");
  if (r == 0) db->addRelation("src", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("src");
      std::vector<u16> ord88({0, 1, 2});
    
    r->addIndex<3>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("src"), std::array<u16,3>{0, 1, 2}, b));
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
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord91({1, 2, 3, 0});
    
    r->addIndex<4>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord92({0, 1, 2, 3});
    
    r->addIndex<4>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord93({1, 2, 0});
    
    r->addIndex<3>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord94({0, 1, 2});
    
    r->addIndex<3>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord95({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord96({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord97({1, 2, 0});
    
    r->addIndex<3>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord98({0, 1, 2});
    
    r->addIndex<3>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mid");
  if (r == 0) db->addStruct("mid", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mid");
      std::vector<u16> ord99({1, 2, 0});
    
    r->addIndex<3>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord100({0, 2, 1});
    
    r->addIndex<3>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord101({2, 0, 1});
    
    r->addIndex<3>(ord101, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mid"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord102({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord103({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("leaf");
  if (r == 0) db->addStruct("leaf", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leaf");
      std::vector<u16> ord104({1, 0});
    
    r->addIndex<2>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord105({0, 1});
    
    r->addIndex<2>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord106({1, 0});
    
    r->addIndex<2>(ord106, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("leaf"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord107({1, 2, 3, 0});
    
    r->addIndex<4>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord108({0, 1, 2, 3});
    
    r->addIndex<4>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("given");
  if (r == 0) db->addRelation("given", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("given");
      std::vector<u16> ord109({0});
    
    r->addIndex<1>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("given"), std::array<u16,1>{0}, b));
  r = db->getRelation("getx");
  if (r == 0) db->addRelation("getx", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("getx");
      std::vector<u16> ord110({0});
    
    r->addIndex<1>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("getx"), std::array<u16,1>{0}, b));
  r = db->getRelation("getm");
  if (r == 0) db->addRelation("getm", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("getm");
      std::vector<u16> ord111({0});
    
    r->addIndex<1>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("getm"), std::array<u16,1>{0}, b));
  r = db->getRelation("getg");
  if (r == 0) db->addRelation("getg", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("getg");
      std::vector<u16> ord112({0, 1, 2});
    
    r->addIndex<3>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("getg"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord113({0});
    
    r->addIndex<1>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord114({1, 2, 0});
    
    r->addIndex<3>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord115({0, 1, 2});
    
    r->addIndex<3>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("built");
  if (r == 0) db->addRelation("built", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("built");
      std::vector<u16> ord116({0});
    
    r->addIndex<1>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("built"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord117({1, 0});
    
    r->addIndex<2>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord118({0, 1});
    
    r->addIndex<2>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre) (scan temp1ry726 X Y Z) (body (join leaf (1 0) 1 X __t3cn36)) (head (emit-temp temp7zgv27 Y Z __t3cn36) (mkstruct mid (1 2 0) __t9u977 __t3cn36 Y)) sdeep_nest3.slog:20 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** leafindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7zgv27");
      head_rel[1] = db->getRelation("mid");
      outer_rel = db->getRelation("temp1ry726");
      std::vector<u16> ord2({1, 0});
      slog::Relation* readrel3 = db->getRelation("leaf");
      leafindex0 = readrel3->getIndex(ord2, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c0 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<2,1>(leafindex0, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m4) {
          u64 v_c3 = m4[1];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c1, v_c2, v_c3});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c3, v_c1}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:20", "delta:temp1ry726", _fires);
  
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
  // (crule (pre (let __tconst9f0m20 const19581e27de7ced00ff1ce50b) (let __tconst2fp221 const2c624232cdd221771294dfbb) (let __tconst915V22 const7902699be42c8a8e46fbbb45)) (seeded) (body (join leaf (1 0) 1 __tconst915V22 __t89Kw23) (exists wrap (2 1 0) 1 __tconst9f0m20) (join mid (1 2 0) 2 __t89Kw23 __tconst2fp221 __t1XCi24) (join wrap (2 1 0) 2 __tconst9f0m20 __t1XCi24 __t0AFd25)) (head (emit given (0) __t0AFd25)) sdeep_nest3.slog:15 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** leafindex5;  slog::Index** wrapindex6;  slog::Index** midindex7;  slog::Index** wrapindex8;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("given");
      std::vector<u16> ord10({0});
      slog::Relation* readrel11 = db->getRelation("given");
      head_index[0] = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("leaf");
      leafindex5 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({2, 1, 0});
      slog::Relation* readrel15 = db->getRelation("wrap");
      wrapindex6 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 2, 0});
      slog::Relation* readrel17 = db->getRelation("mid");
      midindex7 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({2, 1, 0});
      slog::Relation* readrel19 = db->getRelation("wrap");
      wrapindex8 = readrel19->getIndex(ord18, false);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c5 = v_const2c624232cdd221771294dfbb;
      u64 v_c6 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(leafindex5, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m20) {
        u64 v_c7 = m20[1];
        if (!slog::exists_probe<3,1>(wrapindex6, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<3,2>(midindex7, std::array<u64,3>{v_c7, v_c5, 0}, [&](const std::array<u64,3>& m21) {
          u64 v_c8 = m21[2];
          slog::join_probe<3,2>(wrapindex8, std::array<u64,3>{v_c4, v_c8, 0}, [&](const std::array<u64,3>& m22) {
            u64 v_c9 = m22[2];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:15", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask9(db,b));
  // (crule (pre (let __tconst9f0m20 const19581e27de7ced00ff1ce50b) (let __tconst2fp221 const2c624232cdd221771294dfbb) (let __tconst915V22 const7902699be42c8a8e46fbbb45)) (probe wrap (2 0 1) 1 __tconst9f0m20 __t0AFd25 __t1XCi24) (body (exists leaf (1 0) 1 __tconst915V22) (join mid (0 2 1) 2 __t1XCi24 __tconst2fp221 __t89Kw23) (join leaf (0 1) 2 __t89Kw23 __tconst915V22)) (head (emit given (0) __t0AFd25)) sdeep_nest3.slog:15 #f)
  class ReadTask26 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** leafindex23;  slog::Index** midindex24;  slog::Index** leafindex25;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("given");
      std::vector<u16> ord27({0});
      slog::Relation* readrel28 = db->getRelation("given");
      head_index[0] = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({2, 0, 1});
      slog::Relation* readrel30 = db->getRelation("wrap");
      driver_index = readrel30->getIndex(ord29, true);
      std::vector<u16> ord31({1, 0});
      slog::Relation* readrel32 = db->getRelation("leaf");
      leafindex23 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({0, 2, 1});
      slog::Relation* readrel34 = db->getRelation("mid");
      midindex24 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("leaf");
      leafindex25 = readrel36->getIndex(ord35, false);
  
    }
    ReadTask26(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c5 = v_const2c624232cdd221771294dfbb;
      u64 v_c6 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c4, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m37) {
        u64 v_c9 = m37[1];
        u64 v_c8 = m37[2];
        if (buckethash(v_c9) != bucket) return;
        if (!slog::exists_probe<2,1>(leafindex23, std::array<u64,2>{v_c6, 0})) return;
        slog::join_probe<3,2>(midindex24, std::array<u64,3>{v_c8, v_c5, 0}, [&](const std::array<u64,3>& m38) {
          u64 v_c7 = m38[2];
          slog::join_probe<2,2>(leafindex25, std::array<u64,2>{v_c7, v_c6}, [&](const std::array<u64,2>& m39) {
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:15", "delta:wrap", _fires);
  
      if (!_done)
      {
        ReadTask26* _cont = new ReadTask26(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask26(db,b), false);
  // (crule (pre (let __tconst2fp221 const2c624232cdd221771294dfbb) (let __tconst9f0m20 const19581e27de7ced00ff1ce50b) (let __tconst915V22 const7902699be42c8a8e46fbbb45)) (probe mid (2 0 1) 1 __tconst2fp221 __t1XCi24 __t89Kw23) (body (join leaf (0 1) 2 __t89Kw23 __tconst915V22)) (head (mkstruct wrap (2 1 0) __t0AFd25 __tconst9f0m20 __t1XCi24)) sdeep_nest3.slog:15 #f)
  class ReadTask41 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** leafindex40;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("wrap");
      std::vector<u16> ord42({2, 0, 1});
      slog::Relation* readrel43 = db->getRelation("mid");
      driver_index = readrel43->getIndex(ord42, true);
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("leaf");
      leafindex40 = readrel45->getIndex(ord44, false);
  
    }
    ReadTask41(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const2c624232cdd221771294dfbb;
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c6 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c5, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m46) {
        u64 v_c8 = m46[1];
        u64 v_c7 = m46[2];
        if (buckethash(v_c8) != bucket) return;
        slog::join_probe<2,2>(leafindex40, std::array<u64,2>{v_c7, v_c6}, [&](const std::array<u64,2>& m47) {
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c8}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:15", "delta:mid", _fires);
  
      if (!_done)
      {
        ReadTask41* _cont = new ReadTask41(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask41(db,b), false);
  // (crule (pre) (scan src X Y Z) (body) (head (emit-temp temp1ry726 X Y Z) (mkstruct leaf (1 0) __t3cn36 X)) sdeep_nest3.slog:20 #f)
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
      head_rel[0] = db->getRelation("temp1ry726");
      head_rel[1] = db->getRelation("leaf");
      outer_rel = db->getRelation("src");
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c0 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c0, v_c1, v_c2});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:20", "delta:src", _fires);
  
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
  // (crule (pre (let __tconst915V22 const7902699be42c8a8e46fbbb45) (let __tconst2fp221 const2c624232cdd221771294dfbb) (let __tconst9f0m20 const19581e27de7ced00ff1ce50b)) (probe leaf (1 0) 1 __tconst915V22 __t89Kw23) (body) (head (mkstruct mid (1 2 0) __t1XCi24 __t89Kw23 __tconst2fp221)) sdeep_nest3.slog:15 #f)
  class ReadTask49 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mid");
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("leaf");
      driver_index = readrel51->getIndex(ord50, true);
  
    }
    ReadTask49(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c5 = v_const2c624232cdd221771294dfbb;
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c6, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m52) {
        u64 v_c7 = m52[1];
        if (buckethash(v_c7) != bucket) return;
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c7, v_c5}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:15", "delta:leaf", _fires);
  
      if (!_done)
      {
        ReadTask49* _cont = new ReadTask49(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask49(db,b), false);
  // (crule (pre) (scan temp3R9b28 Z __t9u977) (body (join wrap (2 1 0) 2 Z __t9u977 __t9toM8)) (head (emit built (0) __t9toM8)) sdeep_nest3.slog:20 #f)
  class ReadTask54 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** wrapindex53;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("built");
      std::vector<u16> ord55({0});
      slog::Relation* readrel56 = db->getRelation("built");
      head_index[0] = readrel56->getIndex(ord55, false);
      outer_rel = db->getRelation("temp3R9b28");
      std::vector<u16> ord57({2, 1, 0});
      slog::Relation* readrel58 = db->getRelation("wrap");
      wrapindex53 = readrel58->getIndex(ord57, false);
  
    }
    ReadTask54(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe<3,2>(wrapindex53, std::array<u64,3>{v_c2, v_c10, 0}, [&](const std::array<u64,3>& m59) {
          u64 v_c11 = m59[2];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c11}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:20", "delta:temp3R9b28", _fires);
  
      if (!_done)
      {
        ReadTask54* _cont = new ReadTask54(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask54(db,b), false);
  // (crule (pre (let __tconst915V22 const7902699be42c8a8e46fbbb45) (let __tconst2fp221 const2c624232cdd221771294dfbb) (let __tconst9f0m20 const19581e27de7ced00ff1ce50b) (let __tconst3mMR19 const4b227777d4dd1fc61c6f884f) (let __tconst01LZ18 constef2d127de37b942baad06145) (let __tconst3I9W17 conste7f6c011776e8db7cd330b54) (let __tconst3d7J16 const6b86b273ff34fce19d6b804e) (let __tconst99km15 constd4735e3a265e16eee03f5971) (let __tconst402g14 const4e07408562bedb8b60ce05c1)) (once) (body) (head (mkstruct leaf (1 0) __t89Kw23 __tconst915V22) (emit src (0 1 2) __tconst3mMR19 __tconst01LZ18 __tconst3I9W17) (emit src (0 1 2) __tconst3d7J16 __tconst99km15 __tconst402g14)) sdeep_nest3.slog:15 #f)
  class ReadTask60 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("leaf");
      head_rel[1] = db->getRelation("src");
      std::vector<u16> ord61({0, 1, 2});
      slog::Relation* readrel62 = db->getRelation("src");
      head_index[1] = readrel62->getIndex(ord61, false);
      head_rel[2] = db->getRelation("src");
      std::vector<u16> ord63({0, 1, 2});
      slog::Relation* readrel64 = db->getRelation("src");
      head_index[2] = readrel64->getIndex(ord63, false);
  
    }
    ReadTask60(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c5 = v_const2c624232cdd221771294dfbb;
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c12 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c13 = v_constef2d127de37b942baad06145;
      u64 v_c14 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c16 = v_constd4735e3a265e16eee03f5971;
      u64 v_c17 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c6}, std::array<u16,2>{1, 0});
      slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c12, v_c13, v_c14}, std::array<u16,3>{0, 1, 2});
      slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c15, v_c16, v_c17}, std::array<u16,3>{0, 1, 2});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:15", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask60(db,b), true);
  // (crule (pre) (scan temp7zgv27 Y Z __t3cn36) (body (join mid (1 2 0) 2 __t3cn36 Y __t9u977)) (head (emit-temp temp3R9b28 Z __t9u977) (mkstruct wrap (2 1 0) __t9toM8 Z __t9u977)) sdeep_nest3.slog:20 #f)
  class ReadTask66 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** midindex65;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3R9b28");
      head_rel[1] = db->getRelation("wrap");
      outer_rel = db->getRelation("temp7zgv27");
      std::vector<u16> ord67({1, 2, 0});
      slog::Relation* readrel68 = db->getRelation("mid");
      midindex65 = readrel68->getIndex(ord67, false);
  
    }
    ReadTask66(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        slog::join_probe<3,2>(midindex65, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m69) {
          u64 v_c10 = m69[2];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c10});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c2, v_c10}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:20", "delta:temp7zgv27", _fires);
  
      if (!_done)
      {
        ReadTask66* _cont = new ReadTask66(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask66(db,b), false);
  // (crule (pre (let __tconst2fp221 const2c624232cdd221771294dfbb) (let __tconst9f0m20 const19581e27de7ced00ff1ce50b) (let __tconst915V22 const7902699be42c8a8e46fbbb45)) (seeded) (body (join leaf (1 0) 1 __tconst915V22 __t89Kw23) (join mid (1 2 0) 2 __t89Kw23 __tconst2fp221 __t1XCi24)) (head (mkstruct wrap (2 1 0) __t0AFd25 __tconst9f0m20 __t1XCi24)) sdeep_nest3.slog:15 #f)
  class ReadTask72 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** leafindex70;  slog::Index** midindex71;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("wrap");
      std::vector<u16> ord73({2, 1, 0});
      slog::Relation* readrel74 = db->getRelation("wrap");
      head_index[0] = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 0});
      slog::Relation* readrel76 = db->getRelation("leaf");
      leafindex70 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 2, 0});
      slog::Relation* readrel78 = db->getRelation("mid");
      midindex71 = readrel78->getIndex(ord77, false);
  
    }
    ReadTask72(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const2c624232cdd221771294dfbb;
      u64 v_c4 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c6 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(leafindex70, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m79) {
        u64 v_c7 = m79[1];
        slog::join_probe<3,2>(midindex71, std::array<u64,3>{v_c7, v_c5, 0}, [&](const std::array<u64,3>& m80) {
          u64 v_c8 = m80[2];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c8}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("sdeep_nest3.slog:15", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask72(db,b));
  s->addReadRel("leaf");
  s->addReadRel("mid");
  s->addReadRel("src");
  s->addReadRel("temp1ry726");
  s->addReadRel("temp3R9b28");
  s->addReadRel("temp7zgv27");
  s->addReadRel("wrap");
  s->addDynamicRel("built");
  s->addDynamicRel("given");
  s->addDynamicRel("leaf");
  s->addDynamicRel("mid");
  s->addDynamicRel("src");
  s->addDynamicRel("temp1ry726");
  s->addDynamicRel("temp3R9b28");
  s->addDynamicRel("temp7zgv27");
  s->addDynamicRel("wrap");
  s->addAccelRel("built");
  s->addAccelRel("given");
  s->addAccelRel("src");
  d->push(s);
  d->continueRun();
}

