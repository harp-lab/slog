
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constef2d127de37b942baad06145;
u64 v_conste7f6c011776e8db7cd330b54;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const46a3ae93aa7a8b988080d6c9;
u64 v_consted725292f5f32d61535958c1;
u64 v_const7297d2085ea0adffc396d546;
u64 v_const2c8b6d4a8b88a4444dd3bdd5;
u64 v_constc9216a4bb2623d4056d2c458;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("2ad7eb45");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_conste7f6c011776e8db7cd330b54 = s32_encode(6);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const46a3ae93aa7a8b988080d6c9 = db->encodeString("n");
  v_consted725292f5f32d61535958c1 = db->encodeString("*");
  v_const7297d2085ea0adffc396d546 = db->encodeString("+");
  v_const2c8b6d4a8b88a4444dd3bdd5 = db->encodeString("(");
  v_constc9216a4bb2623d4056d2c458 = db->encodeString(")");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord17({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord17, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord18({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord18, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("tok");
  if (r == 0) db->addRelation("tok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tok");
      std::vector<u16> ord19({0, 1});
    
    r->addIndex<2>(ord19, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("tok"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord20({1, 2, 0});
    
    r->addIndex<3>(ord20, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord21({0, 1, 2});
    
    r->addIndex<3>(ord21, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord22({1, 2, 0});
    
    r->addIndex<3>(ord22, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord23({0, 1, 2});
    
    r->addIndex<3>(ord23, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("parse_ans");
  if (r == 0) db->addRelation("parse_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("parse_ans");
      std::vector<u16> ord24({0, 1});
    
    r->addIndex<2>(ord24, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("parse_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("parse");
  if (r == 0) db->addStruct("parse", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("parse");
      std::vector<u16> ord25({1, 2, 0});
    
    r->addIndex<3>(ord25, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord26({0, 1, 2});
    
    r->addIndex<3>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("parse"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord27({1, 2, 3, 0});
    
    r->addIndex<4>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord28({0, 1, 2, 3});
    
    r->addIndex<4>(ord28, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord29({1, 2, 0});
    
    r->addIndex<3>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord30({0, 1, 2});
    
    r->addIndex<3>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord31({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord32({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord33({1, 2, 0});
    
    r->addIndex<3>(ord33, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord34({0, 1, 2});
    
    r->addIndex<3>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord35({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord36({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("len");
  if (r == 0) db->addRelation("len", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("len");
      std::vector<u16> ord37({0});
    
    r->addIndex<1>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("len"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord38({1, 2, 3, 0});
    
    r->addIndex<4>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord39({0, 1, 2, 3});
    
    r->addIndex<4>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord40({0});
    
    r->addIndex<1>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord41({1, 2, 0});
    
    r->addIndex<3>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord42({0, 1, 2});
    
    r->addIndex<3>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("accepted");
  if (r == 0) db->addRelation("accepted", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("accepted");
      std::vector<u16> ord43({0});
    
    r->addIndex<1>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("accepted"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord44({1, 0});
    
    r->addIndex<2>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord45({0, 1});
    
    r->addIndex<2>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst1i6p40 const2c8b6d4a8b88a4444dd3bdd5) (let __tconst3A3241 const5feceb66ffc86f38d952786c) (let __tconst4vew43 const6b86b273ff34fce19d6b804e) (let __tconst51im44 const7297d2085ea0adffc396d546) (let __tconst48J545 constd4735e3a265e16eee03f5971) (let __tconst6O9y47 const4e07408562bedb8b60ce05c1) (let __tconst4TfM48 constc9216a4bb2623d4056d2c458) (let __tconst8gJg49 const4b227777d4dd1fc61c6f884f) (let __tconst7Tip50 consted725292f5f32d61535958c1) (let __tconst9kiB51 constef2d127de37b942baad06145) (let __tconst1LDo52 const46a3ae93aa7a8b988080d6c9) (let __tconst6p5953 conste7f6c011776e8db7cd330b54) (let __tconst4jFC54 const7902699be42c8a8e46fbbb45)) (once) (body) (head (emit tok (0 1) __tconst3A3241 __tconst1i6p40) (emit tok (0 1) __tconst4vew43 __tconst1LDo52) (emit tok (0 1) __tconst48J545 __tconst51im44) (emit tok (0 1) __tconst6O9y47 __tconst1LDo52) (emit tok (0 1) __tconst8gJg49 __tconst4TfM48) (emit tok (0 1) __tconst9kiB51 __tconst7Tip50) (emit tok (0 1) __tconst6p5953 __tconst1LDo52) (emit len (0) __tconst4jFC54)) dem_parse.slog:11 #f)
  class ReadTask0 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[8];
    slog::Index** head_index[8];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tok");
      std::vector<u16> ord1({0, 1});
      slog::Relation* readrel2 = db->getRelation("tok");
      head_index[0] = readrel2->getIndex(ord1, false);
      head_rel[1] = db->getRelation("tok");
      std::vector<u16> ord3({0, 1});
      slog::Relation* readrel4 = db->getRelation("tok");
      head_index[1] = readrel4->getIndex(ord3, false);
      head_rel[2] = db->getRelation("tok");
      std::vector<u16> ord5({0, 1});
      slog::Relation* readrel6 = db->getRelation("tok");
      head_index[2] = readrel6->getIndex(ord5, false);
      head_rel[3] = db->getRelation("tok");
      std::vector<u16> ord7({0, 1});
      slog::Relation* readrel8 = db->getRelation("tok");
      head_index[3] = readrel8->getIndex(ord7, false);
      head_rel[4] = db->getRelation("tok");
      std::vector<u16> ord9({0, 1});
      slog::Relation* readrel10 = db->getRelation("tok");
      head_index[4] = readrel10->getIndex(ord9, false);
      head_rel[5] = db->getRelation("tok");
      std::vector<u16> ord11({0, 1});
      slog::Relation* readrel12 = db->getRelation("tok");
      head_index[5] = readrel12->getIndex(ord11, false);
      head_rel[6] = db->getRelation("tok");
      std::vector<u16> ord13({0, 1});
      slog::Relation* readrel14 = db->getRelation("tok");
      head_index[6] = readrel14->getIndex(ord13, false);
      head_rel[7] = db->getRelation("len");
      std::vector<u16> ord15({0});
      slog::Relation* readrel16 = db->getRelation("len");
      head_index[7] = readrel16->getIndex(ord15, false);
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2c8b6d4a8b88a4444dd3bdd5;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const7297d2085ea0adffc396d546;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c6 = v_constc9216a4bb2623d4056d2c458;
      u64 v_c7 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c8 = v_consted725292f5f32d61535958c1;
      u64 v_c9 = v_constef2d127de37b942baad06145;
      u64 v_c10 = v_const46a3ae93aa7a8b988080d6c9;
      u64 v_c11 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c12 = v_const7902699be42c8a8e46fbbb45;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[8];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c0}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c2, v_c10}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c4, v_c3}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c5, v_c10}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[4], head_index[4], newbatch[4], std::array<u64,2>{v_c7, v_c6}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[5], head_index[5], newbatch[5], std::array<u64,2>{v_c9, v_c8}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[6], head_index[6], newbatch[6], std::array<u64,2>{v_c11, v_c10}, std::array<u16,2>{0, 1});
      slog::emit<1>(head_rel[7], head_index[7], newbatch[7], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
  
      if (_fires) db->bumpFires("dem_parse.slog:11", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  s->addDynamicRel("len");
  s->addDynamicRel("tok");
  d->push(s);
  d->continueRun();
}

