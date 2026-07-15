
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("3180a3fd");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord34({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord35({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord36({1, 2, 0});
    
    r->addIndex<3>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord37({0, 1, 2});
    
    r->addIndex<3>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("thirds");
  if (r == 0) db->addRelation("thirds", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("thirds");
      std::vector<u16> ord38({0, 1, 2});
    
    r->addIndex<3>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("thirds"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord39({1, 2, 0});
    
    r->addIndex<3>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord40({0, 1, 2});
    
    r->addIndex<3>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("rebuilt");
  if (r == 0) db->addRelation("rebuilt", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("rebuilt");
      std::vector<u16> ord41({0});
    
    r->addIndex<1>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("rebuilt"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord42({1, 2, 3, 0});
    
    r->addIndex<4>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord43({0, 1, 2, 3});
    
    r->addIndex<4>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord44({1, 2, 0});
    
    r->addIndex<3>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord45({0, 1, 2});
    
    r->addIndex<3>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord46({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord47({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord48({1, 2, 0});
    
    r->addIndex<3>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord49({0, 1, 2});
    
    r->addIndex<3>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("midthird");
  if (r == 0) db->addRelation("midthird", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("midthird");
      std::vector<u16> ord50({0});
    
    r->addIndex<1>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("midthird"), std::array<u16,1>{0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord51({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord52({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord53({1, 2, 3, 0});
    
    r->addIndex<4>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord54({0, 1, 2, 3});
    
    r->addIndex<4>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord55({0});
    
    r->addIndex<1>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("doc");
  if (r == 0) db->addRelation("doc", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("doc");
      std::vector<u16> ord56({0});
    
    r->addIndex<1>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("doc"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord57({1, 2, 0});
    
    r->addIndex<3>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord58({0, 1, 2});
    
    r->addIndex<3>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord59({1, 0});
    
    r->addIndex<2>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord60({0, 1});
    
    r->addIndex<2>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre) (scan toint_range __erre3aFh178 __errf1uG5179 __errf0kAN180) (body) (head (emit error (0) __erre3aFh178)) <internal>:1 #f)
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
      outer_rel = db->getRelation("toint_range");
  
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre2Lhz167 __errf1Lu3168 __errf1J1x169) (body) (head (emit error (0) __erre2Lhz167)) <internal>:1 #f)
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
      outer_rel = db->getRelation("modulo_by_zero");
  
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
        u64 v_c3 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
  // (crule (pre (let _00024sqc4fIj30 const5feceb66ffc86f38d952786c) (let _00024sqc4NC231 const5feceb66ffc86f38d952786c) (let _00024sqc6JbN32 const5feceb66ffc86f38d952786c) (let _00024sqc7dQV35 const4e07408562bedb8b60ce05c1) (let _00024sqc63QM36 constd4735e3a265e16eee03f5971) (let _00024sqc6ZDd37 const6b86b273ff34fce19d6b804e) (let _00024sqc2Qox42 constd4735e3a265e16eee03f5971)) (scan doc _00024seq0) (body (letp _00024sql5hXU28 (aslst _00024seq0)) (let _00024sqn4gdP29 (llen _00024sql5hXU28)) (cmp ge _00024sqn4gdP29 _00024sqc4fIj30) (let _00024sqp80GN33 (_0002d _00024sqn4gdP29 _00024sqc6JbN32)) (let _00024sqm4tVz34 (_0002d _00024sqp80GN33 _00024sqc4NC231)) (let _00024sqm6O5K38 (_0002a _00024sqc6ZDd37 _00024sqm4tVz34)) (let _00024sqm8KyR39 (_0002b _00024sqm6O5K38 _00024sqc63QM36)) (let _00024sqm2RNG40 (_0002f _00024sqm8KyR39 _00024sqc7dQV35)) (let _00024sqp74q941 (_0002b _00024sqc4NC231 _00024sqm2RNG40)) (let _00024sqm01JM43 (_0002a _00024sqc2Qox42 _00024sqm4tVz34)) (let _00024sqm9iL744 (_0002b _00024sqm01JM43 _00024sqc63QM36)) (let _00024sqm35hL45 (_0002f _00024sqm9iL744 _00024sqc7dQV35)) (let _00024sqp9fKS46 (_0002b _00024sqc4NC231 _00024sqm35hL45)) (let bs (lslice _00024sql5hXU28 _00024sqp74q941 _00024sqp9fKS46))) (head (emit midthird (0) bs)) seq_split_kway.slog:15 #f)
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
      head_rel[0] = db->getRelation("midthird");
      std::vector<u16> ord7({0});
      slog::Relation* readrel8 = db->getRelation("midthird");
      head_index[0] = readrel8->getIndex(ord7, false);
      outer_rel = db->getRelation("doc");
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
      u64 v_c7 = v_const5feceb66ffc86f38d952786c;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c10 = v_constd4735e3a265e16eee03f5971;
      u64 v_c11 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c13 = _t[0];
        bool ok9 = true;
        u64 v_c14 = _prim_aslst(db, v_c13, &ok9);
        if (!ok9) return;
        u64 v_c15 = _prim_llen(db, v_c14);
        if (v_c15 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c16 = _prim_ge(db, v_c15, v_c6);
        if (v_c16 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        if (!v_c16) return;
        u64 v_c17 = _prim__0002d(db, v_c15, v_c8);
        if (v_c17 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c18 = _prim__0002d(db, v_c17, v_c7);
        if (v_c18 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c19 = _prim__0002a(db, v_c11, v_c18);
        if (v_c19 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c20 = _prim__0002b(db, v_c19, v_c10);
        if (v_c20 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c21 = _prim__0002f(db, v_c20, v_c9);
        if (v_c21 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c22 = _prim__0002b(db, v_c7, v_c21);
        if (v_c22 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c23 = _prim__0002a(db, v_c12, v_c18);
        if (v_c23 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c24 = _prim__0002b(db, v_c23, v_c10);
        if (v_c24 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c25 = _prim__0002f(db, v_c24, v_c9);
        if (v_c25 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c26 = _prim__0002b(db, v_c7, v_c25);
        if (v_c26 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        u64 v_c27 = _prim_lslice(db, v_c14, v_c22, v_c26);
        if (v_c27 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:15"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_split_kway.slog:15", "all:doc", _fires);
  
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
      s->addTask(phase_read, new ReadTask6(db,b), true);
  // (crule (pre (let _00024sqc2FBx49 const5feceb66ffc86f38d952786c) (let _00024sqc7SxY50 const5feceb66ffc86f38d952786c) (let _00024sqc55jG51 const5feceb66ffc86f38d952786c) (let _00024sqc9oIt54 const4e07408562bedb8b60ce05c1) (let _00024sqc15sz55 constd4735e3a265e16eee03f5971) (let _00024sqc31ek56 const6b86b273ff34fce19d6b804e) (let _00024sqc8Rnh61 constd4735e3a265e16eee03f5971)) (scan doc _00024seq0) (body (letp _00024sql3fOM47 (aslst _00024seq0)) (let _00024sqn2drF48 (llen _00024sql3fOM47)) (cmp ge _00024sqn2drF48 _00024sqc2FBx49) (let _00024sqp5GnN52 (_0002d _00024sqn2drF48 _00024sqc55jG51)) (let _00024sqm1ybB53 (_0002d _00024sqp5GnN52 _00024sqc7SxY50)) (let _00024sqm3u9P57 (_0002a _00024sqc31ek56 _00024sqm1ybB53)) (let _00024sqm26BC58 (_0002b _00024sqm3u9P57 _00024sqc15sz55)) (let _00024sqm18Vb59 (_0002f _00024sqm26BC58 _00024sqc9oIt54)) (let _00024sqp6yS760 (_0002b _00024sqc7SxY50 _00024sqm18Vb59)) (let _00024sqm9RCj62 (_0002a _00024sqc8Rnh61 _00024sqm1ybB53)) (let _00024sqm6aXr63 (_0002b _00024sqm9RCj62 _00024sqc15sz55)) (let _00024sqm9HkQ64 (_0002f _00024sqm6aXr63 _00024sqc9oIt54)) (let _00024sqp2aPJ65 (_0002b _00024sqc7SxY50 _00024sqm9HkQ64)) (let as (lslice _00024sql3fOM47 _00024sqc7SxY50 _00024sqp6yS760)) (let bs (lslice _00024sql3fOM47 _00024sqp6yS760 _00024sqp2aPJ65)) (let cs (lslice _00024sql3fOM47 _00024sqp2aPJ65 _00024sqp5GnN52))) (head (emit thirds (0 1 2) as bs cs)) seq_split_kway.slog:14 #f)
  class ReadTask11 : public slog::Task
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
      head_rel[0] = db->getRelation("thirds");
      std::vector<u16> ord12({0, 1, 2});
      slog::Relation* readrel13 = db->getRelation("thirds");
      head_index[0] = readrel13->getIndex(ord12, false);
      outer_rel = db->getRelation("doc");
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_const5feceb66ffc86f38d952786c;
      u64 v_c30 = v_const5feceb66ffc86f38d952786c;
      u64 v_c31 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c32 = v_constd4735e3a265e16eee03f5971;
      u64 v_c33 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c34 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c13 = _t[0];
        bool ok14 = true;
        u64 v_c35 = _prim_aslst(db, v_c13, &ok14);
        if (!ok14) return;
        u64 v_c36 = _prim_llen(db, v_c35);
        if (v_c36 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c37 = _prim_ge(db, v_c36, v_c28);
        if (v_c37 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        if (!v_c37) return;
        u64 v_c38 = _prim__0002d(db, v_c36, v_c30);
        if (v_c38 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c39 = _prim__0002d(db, v_c38, v_c29);
        if (v_c39 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c40 = _prim__0002a(db, v_c33, v_c39);
        if (v_c40 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c41 = _prim__0002b(db, v_c40, v_c32);
        if (v_c41 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c42 = _prim__0002f(db, v_c41, v_c31);
        if (v_c42 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c43 = _prim__0002b(db, v_c29, v_c42);
        if (v_c43 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c44 = _prim__0002a(db, v_c34, v_c39);
        if (v_c44 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c45 = _prim__0002b(db, v_c44, v_c32);
        if (v_c45 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c46 = _prim__0002f(db, v_c45, v_c31);
        if (v_c46 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c47 = _prim__0002b(db, v_c29, v_c46);
        if (v_c47 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c48 = _prim_lslice(db, v_c35, v_c29, v_c43);
        if (v_c48 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c27 = _prim_lslice(db, v_c35, v_c43, v_c47);
        if (v_c27 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        u64 v_c49 = _prim_lslice(db, v_c35, v_c47, v_c38);
        if (v_c49 == slog_error) { slog::emit_pending_error(db, "seq_split_kway.slog:14"); return; }
        ++_fires;
        slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c48, v_c27, v_c49}, std::array<u16,3>{0, 1, 2});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_split_kway.slog:14", "all:doc", _fires);
  
      if (!_done)
      {
        ReadTask11* _cont = new ReadTask11(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask11(db,b), true);
  // (crule (pre) (scan int_overflow __erre7Sbm170 __errf3mMc171 __errf8LmR172 __errf67ZU173) (body) (head (emit error (0) __erre7Sbm170)) <internal>:1 #f)
  class ReadTask16 : public slog::Task
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
      std::vector<u16> ord17({0});
      slog::Relation* readrel18 = db->getRelation("error");
      head_index[0] = readrel18->getIndex(ord17, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c50 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c52 = _t[2];
        u64 v_c53 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c50}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask16* _cont = new ReadTask16(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask16(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre0skI186 __errf4raD187 __errf2wkd188 __errf9GHI189 __errf0dRm190) (body) (head (emit error (0) __erre0skI186)) <internal>:1 #f)
  class ReadTask19 : public slog::Task
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
      std::vector<u16> ord20({0});
      slog::Relation* readrel21 = db->getRelation("error");
      head_index[0] = readrel21->getIndex(ord20, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask19(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[1];
        u64 v_c56 = _t[2];
        u64 v_c57 = _t[3];
        u64 v_c58 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c54}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask19* _cont = new ReadTask19(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask19(db,b), false);
  // (crule (pre) (scan nan_result __erre2Qb7174 __errf8UWo175 __errf6nEY176 __errf8FJM177) (body) (head (emit error (0) __erre2Qb7174)) <internal>:1 #f)
  class ReadTask22 : public slog::Task
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
      std::vector<u16> ord23({0});
      slog::Relation* readrel24 = db->getRelation("error");
      head_index[0] = readrel24->getIndex(ord23, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask22(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c61 = _t[2];
        u64 v_c62 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c59}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
      s->addTask(phase_read, new ReadTask22(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre4RJF191 __errf3rf4192 __errf445b193) (body) (head (emit error (0) __erre4RJF191)) <internal>:1 #f)
  class ReadTask25 : public slog::Task
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
      std::vector<u16> ord26({0});
      slog::Relation* readrel27 = db->getRelation("error");
      head_index[0] = readrel27->getIndex(ord26, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask25(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[0];
        u64 v_c64 = _t[1];
        u64 v_c65 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c63}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask25* _cont = new ReadTask25(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask25(db,b), false);
  // (crule (pre) (scan type_mismatch __erre6XkX181 __errf8T01182 __errf6uS0183 __errf0Cv3184 __errf9b9h185) (body) (head (emit error (0) __erre6XkX181)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord29({0});
      slog::Relation* readrel30 = db->getRelation("error");
      head_index[0] = readrel30->getIndex(ord29, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c66 = _t[0];
        u64 v_c67 = _t[1];
        u64 v_c68 = _t[2];
        u64 v_c69 = _t[3];
        u64 v_c70 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c66}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
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
      s->addTask(phase_read, new ReadTask28(db,b), false);
  // (crule (pre) (scan div_by_zero __erre6UAM164 __errf3kb6165 __errf3sP6166) (body) (head (emit error (0) __erre6UAM164)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord32({0});
      slog::Relation* readrel33 = db->getRelation("error");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask31(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c71 = _t[0];
        u64 v_c72 = _t[1];
        u64 v_c73 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c71}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
      s->addTask(phase_read, new ReadTask31(db,b), false);
  s->addReadRel("div_by_zero");
  s->addReadRel("doc");
  s->addReadRel("int_overflow");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("midthird");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("thirds");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

