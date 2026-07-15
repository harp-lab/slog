
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constef2d127de37b942baad06145;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const4a44dc15364204a80fe80e90;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("300b03a9");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord7({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord7, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord8({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord8, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord9({1, 2, 0});
    
    r->addIndex<3>(ord9, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord10({0, 1, 2});
    
    r->addIndex<3>(ord10, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
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
  r = db->getRelation("nobest");
  if (r == 0) db->addRelation("nobest", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nobest");
      std::vector<u16> ord13({0});
    
    r->addIndex<1>(ord13, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("nobest"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord14({1, 2, 3, 0});
    
    r->addIndex<4>(ord14, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord15({0, 1, 2, 3});
    
    r->addIndex<4>(ord15, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord16({1, 2, 0});
    
    r->addIndex<3>(ord16, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord17({0, 1, 2});
    
    r->addIndex<3>(ord17, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord18({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord18, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord19({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord19, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord20({1, 2, 0});
    
    r->addIndex<3>(ord20, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord21({0, 1, 2});
    
    r->addIndex<3>(ord21, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord22({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord22, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord23({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord23, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("k");
  if (r == 0) db->addRelation("k", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("k");
      std::vector<u16> ord24({0});
    
    r->addIndex<1>(ord24, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("k"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord25({1, 2, 3, 0});
    
    r->addIndex<4>(ord25, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord26({0, 1, 2, 3});
    
    r->addIndex<4>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord27({0});
    
    r->addIndex<1>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord28({1, 2, 0});
    
    r->addIndex<3>(ord28, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord29({0, 1, 2});
    
    r->addIndex<3>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("best");
  if (r == 0) db->addRelation("best", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("best");
  r->setLattice(LAT_MIN, false, 0, false, 0, "min-int", db->collections());
      std::vector<u16> ord30({0, 1});
    
    r->addMapIndex<2>(ord30);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<2>(db, r, std::array<u16,2>{0, 1}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<2>(db, db->getRelation("best"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord31({1, 0});
    
    r->addIndex<2>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord32({0, 1});
    
    r->addIndex<2>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst0hnx1 const4a44dc15364204a80fe80e90) (let __tconst63443 constef2d127de37b942baad06145) (let __tconst1gHM5 const7902699be42c8a8e46fbbb45) (let __tconst0Bfu7 const6b86b273ff34fce19d6b804e) (let __tconst7PvX8 constd4735e3a265e16eee03f5971) (let __tconst0JMb9 const4e07408562bedb8b60ce05c1)) (once) (body) (head (emit-lat best __tconst0Bfu7 __tconst0hnx1) (emit-lat best __tconst0Bfu7 __tconst63443) (emit-lat best __tconst7PvX8 __tconst1gHM5) (emit k (0) __tconst0Bfu7) (emit k (0) __tconst7PvX8) (emit k (0) __tconst0JMb9)) neg_lat.slog:9 #f)
  class ReadTask0 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("best");
      head_rel[1] = db->getRelation("best");
      head_rel[2] = db->getRelation("best");
      head_rel[3] = db->getRelation("k");
      std::vector<u16> ord1({0});
      slog::Relation* readrel2 = db->getRelation("k");
      head_index[3] = readrel2->getIndex(ord1, false);
      head_rel[4] = db->getRelation("k");
      std::vector<u16> ord3({0});
      slog::Relation* readrel4 = db->getRelation("k");
      head_index[4] = readrel4->getIndex(ord3, false);
      head_rel[5] = db->getRelation("k");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("k");
      head_index[5] = readrel6->getIndex(ord5, false);
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4a44dc15364204a80fe80e90;
      u64 v_c1 = v_constef2d127de37b942baad06145;
      u64 v_c2 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[6];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c0});
      slog::emit_temp<2>(head_rel[1], newbatch[1], std::array<u64,2>{v_c3, v_c1});
      slog::emit_temp<2>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c2});
      slog::emit<1>(head_rel[3], head_index[3], newbatch[3], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[4], head_index[4], newbatch[4], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[5], head_index[5], newbatch[5], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
  
      if (_fires) db->bumpFires("neg_lat.slog:9", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  s->addDynamicRel("best");
  s->addDynamicRel("k");
  d->push(s);
  d->continueRun();
}

