
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const1b0ed536deb39ddcf8e689b3;
u64 v_const0a50500b2a3435fe7472877e;
u64 v_conste0b04046fbfbc96f3437e471;
u64 v_const0de7cf39e1e6366122309794;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_constc100f95c1913f9c72fc1f4ef;
u64 v_const879923da020d1533f4d8e921;
u64 v_constac8d8342bbb2362d13f0a559;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("01d4d7e3");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const1b0ed536deb39ddcf8e689b3 = db->encodeString("bob");
  v_const0a50500b2a3435fe7472877e = db->encodeString("alice");
  v_conste0b04046fbfbc96f3437e471 = float_encode(9.5);
  v_const0de7cf39e1e6366122309794 = float_encode(7.0);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_constc100f95c1913f9c72fc1f4ef = db->encodeString("b");
  v_const879923da020d1533f4d8e921 = db->encodeString("c");
  v_constac8d8342bbb2362d13f0a559 = db->encodeString("a");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord48({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord49({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord50({1, 2, 0});
    
    r->addIndex<3>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord51({0, 1, 2});
    
    r->addIndex<3>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord52({1, 2, 0});
    
    r->addIndex<3>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord53({0, 1, 2});
    
    r->addIndex<3>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("score");
  if (r == 0) db->addRelation("score", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("score");
      std::vector<u16> ord54({0, 1});
    
    r->addIndex<2>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("score"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("owner");
  if (r == 0) db->addRelation("owner", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("owner");
      std::vector<u16> ord55({0, 1});
    
    r->addIndex<2>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("owner"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord56({1, 2, 3, 0});
    
    r->addIndex<4>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord57({0, 1, 2, 3});
    
    r->addIndex<4>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord58({1, 2, 0});
    
    r->addIndex<3>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord59({0, 1, 2});
    
    r->addIndex<3>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord60({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord61({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord62({1, 2, 0});
    
    r->addIndex<3>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord63({0, 1, 2});
    
    r->addIndex<3>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord64({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord65({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("keyname");
  if (r == 0) db->addRelation("keyname", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("keyname");
      std::vector<u16> ord66({0});
    
    r->addIndex<1>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("keyname"), std::array<u16,1>{0}, b));
  r = db->getRelation("key");
  if (r == 0) db->addStruct("key", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("key");
      std::vector<u16> ord67({1, 2, 0});
    
    r->addIndex<3>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord68({0, 1, 2});
    
    r->addIndex<3>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord69({1, 2, 0});
    
    r->addIndex<3>(ord69, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("key"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("joined");
  if (r == 0) db->addRelation("joined", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("joined");
      std::vector<u16> ord70({0, 1});
    
    r->addIndex<2>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("joined"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord71({1, 2, 3, 0});
    
    r->addIndex<4>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord72({0, 1, 2, 3});
    
    r->addIndex<4>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord73({0});
    
    r->addIndex<1>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord74({1, 2, 0});
    
    r->addIndex<3>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord75({0, 1, 2});
    
    r->addIndex<3>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord76({1, 0});
    
    r->addIndex<2>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord77({0, 1});
    
    r->addIndex<2>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst3seY15 const879923da020d1533f4d8e921) (let __tconst99jw14 const4e07408562bedb8b60ce05c1) (let __tconst2btf13 const0de7cf39e1e6366122309794) (let __tconst1SeH11 constac8d8342bbb2362d13f0a559) (let __tconst8AYn10 const6b86b273ff34fce19d6b804e) (let __tconst8EHZ9 conste0b04046fbfbc96f3437e471) (let __tconst2dw47 constc100f95c1913f9c72fc1f4ef) (let __tconst9DOP6 constd4735e3a265e16eee03f5971) (let __tconst5Xv95 const1b0ed536deb39ddcf8e689b3) (let __tconst66UO1 const0a50500b2a3435fe7472877e)) (once) (body) (head (mkstruct key (1 2 0) __t8zxk16 __tconst3seY15 __tconst99jw14) (mkstruct key (1 2 0) __t1bmE8 __tconst2dw47 __tconst9DOP6) (mkstruct key (1 2 0) __t3jtY4 __tconst1SeH11 __tconst8AYn10)) sdeep_joinkey.slog:13 #f)
  class ReadTask0 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("key");
      head_rel[1] = db->getRelation("key");
      head_rel[2] = db->getRelation("key");
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const879923da020d1533f4d8e921;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const0de7cf39e1e6366122309794;
      u64 v_c3 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_conste0b04046fbfbc96f3437e471;
      u64 v_c6 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_const1b0ed536deb39ddcf8e689b3;
      u64 v_c9 = v_const0a50500b2a3435fe7472877e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c0, v_c1}, std::array<u16,3>{1, 2, 0});
      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c6, v_c7}, std::array<u16,3>{1, 2, 0});
      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c3, v_c4}, std::array<u16,3>{1, 2, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("sdeep_joinkey.slog:13", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  // (crule (pre (let __tconst3seY15 const879923da020d1533f4d8e921) (let __tconst99jw14 const4e07408562bedb8b60ce05c1) (let __tconst2btf13 const0de7cf39e1e6366122309794) (let __tconst1SeH11 constac8d8342bbb2362d13f0a559) (let __tconst8AYn10 const6b86b273ff34fce19d6b804e) (let __tconst8EHZ9 conste0b04046fbfbc96f3437e471) (let __tconst2dw47 constc100f95c1913f9c72fc1f4ef) (let __tconst9DOP6 constd4735e3a265e16eee03f5971) (let __tconst5Xv95 const1b0ed536deb39ddcf8e689b3) (let __tconst66UO1 const0a50500b2a3435fe7472877e)) (seeded) (body (join key (1 2 0) 2 __tconst1SeH11 __tconst8AYn10 __t3jtY4) (exists key (1 2 0) 2 __tconst3seY15 __tconst99jw14) (join key (1 2 0) 2 __tconst2dw47 __tconst9DOP6 __t1bmE8) (join key (1 2 0) 2 __tconst3seY15 __tconst99jw14 __t8zxk16)) (head (emit score (0 1) __t8zxk16 __tconst2btf13) (emit score (0 1) __t3jtY4 __tconst8EHZ9) (emit owner (0 1) __t1bmE8 __tconst5Xv95) (emit owner (0 1) __t3jtY4 __tconst66UO1)) sdeep_joinkey.slog:13 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
    slog::Index** keyindex1;  slog::Index** keyindex2;  slog::Index** keyindex3;  slog::Index** keyindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("score");
      std::vector<u16> ord6({0, 1});
      slog::Relation* readrel7 = db->getRelation("score");
      head_index[0] = readrel7->getIndex(ord6, false);
      head_rel[1] = db->getRelation("score");
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("score");
      head_index[1] = readrel9->getIndex(ord8, false);
      head_rel[2] = db->getRelation("owner");
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("owner");
      head_index[2] = readrel11->getIndex(ord10, false);
      head_rel[3] = db->getRelation("owner");
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("owner");
      head_index[3] = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 2, 0});
      slog::Relation* readrel15 = db->getRelation("key");
      keyindex1 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 2, 0});
      slog::Relation* readrel17 = db->getRelation("key");
      keyindex2 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 2, 0});
      slog::Relation* readrel19 = db->getRelation("key");
      keyindex3 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 2, 0});
      slog::Relation* readrel21 = db->getRelation("key");
      keyindex4 = readrel21->getIndex(ord20, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const879923da020d1533f4d8e921;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const0de7cf39e1e6366122309794;
      u64 v_c3 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_conste0b04046fbfbc96f3437e471;
      u64 v_c6 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_const1b0ed536deb39ddcf8e689b3;
      u64 v_c9 = v_const0a50500b2a3435fe7472877e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      slog::join_probe<3,2>(keyindex1, std::array<u64,3>{v_c3, v_c4, 0}, [&](const std::array<u64,3>& m22) {
        u64 v_c10 = m22[2];
        if (!slog::exists_probe<3,2>(keyindex2, std::array<u64,3>{v_c0, v_c1, 0})) return;
        slog::join_probe<3,2>(keyindex3, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m23) {
          u64 v_c11 = m23[2];
          slog::join_probe<3,2>(keyindex4, std::array<u64,3>{v_c0, v_c1, 0}, [&](const std::array<u64,3>& m24) {
            u64 v_c12 = m24[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c2}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c10, v_c5}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c11, v_c8}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c10, v_c9}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("sdeep_joinkey.slog:13", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask5(db,b));
  // (crule (pre (let __tconst3seY15 const879923da020d1533f4d8e921) (let __tconst99jw14 const4e07408562bedb8b60ce05c1) (let __tconst2btf13 const0de7cf39e1e6366122309794) (let __tconst1SeH11 constac8d8342bbb2362d13f0a559) (let __tconst8AYn10 const6b86b273ff34fce19d6b804e) (let __tconst8EHZ9 conste0b04046fbfbc96f3437e471) (let __tconst2dw47 constc100f95c1913f9c72fc1f4ef) (let __tconst9DOP6 constd4735e3a265e16eee03f5971) (let __tconst5Xv95 const1b0ed536deb39ddcf8e689b3) (let __tconst66UO1 const0a50500b2a3435fe7472877e)) (probe key (1 2 0) 2 __tconst1SeH11 __tconst8AYn10 __t3jtY4) (body (exists key (1 2 0) 2 __tconst3seY15 __tconst99jw14) (join key (1 2 0) 2 __tconst2dw47 __tconst9DOP6 __t1bmE8) (join key (1 2 0) 2 __tconst3seY15 __tconst99jw14 __t8zxk16)) (head (emit score (0 1) __t8zxk16 __tconst2btf13) (emit score (0 1) __t3jtY4 __tconst8EHZ9) (emit owner (0 1) __t1bmE8 __tconst5Xv95) (emit owner (0 1) __t3jtY4 __tconst66UO1)) sdeep_joinkey.slog:13 #f)
  class ReadTask28 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** keyindex25;  slog::Index** keyindex26;  slog::Index** keyindex27;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("score");
      std::vector<u16> ord29({0, 1});
      slog::Relation* readrel30 = db->getRelation("score");
      head_index[0] = readrel30->getIndex(ord29, false);
      head_rel[1] = db->getRelation("score");
      std::vector<u16> ord31({0, 1});
      slog::Relation* readrel32 = db->getRelation("score");
      head_index[1] = readrel32->getIndex(ord31, false);
      head_rel[2] = db->getRelation("owner");
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("owner");
      head_index[2] = readrel34->getIndex(ord33, false);
      head_rel[3] = db->getRelation("owner");
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("owner");
      head_index[3] = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 0});
      slog::Relation* readrel38 = db->getRelation("key");
      driver_index = readrel38->getIndex(ord37, true);
      std::vector<u16> ord39({1, 2, 0});
      slog::Relation* readrel40 = db->getRelation("key");
      keyindex25 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("key");
      keyindex26 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("key");
      keyindex27 = readrel44->getIndex(ord43, false);
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const879923da020d1533f4d8e921;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const0de7cf39e1e6366122309794;
      u64 v_c3 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_conste0b04046fbfbc96f3437e471;
      u64 v_c6 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_const1b0ed536deb39ddcf8e689b3;
      u64 v_c9 = v_const0a50500b2a3435fe7472877e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c3, v_c4, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m45) {
        u64 v_c10 = m45[2];
        if (buckethash(v_c10) != bucket) return;
        if (!slog::exists_probe<3,2>(keyindex25, std::array<u64,3>{v_c0, v_c1, 0})) return;
        slog::join_probe<3,2>(keyindex26, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m46) {
          u64 v_c11 = m46[2];
          slog::join_probe<3,2>(keyindex27, std::array<u64,3>{v_c0, v_c1, 0}, [&](const std::array<u64,3>& m47) {
            u64 v_c12 = m47[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c2}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c10, v_c5}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c11, v_c8}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c10, v_c9}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("sdeep_joinkey.slog:13", "delta:key", _fires);
  
      if (!_done)
      {
        ReadTask28* _cont = new ReadTask28(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask28(db,b), false);
  s->addReadRel("key");
  s->addDynamicRel("key");
  s->addDynamicRel("owner");
  s->addDynamicRel("score");
  d->push(s);
  d->continueRun();
}

