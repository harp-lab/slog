
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const4b227777d4dd1fc61c6f884f;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("0f690da3");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord30({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord31({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord32({1, 2, 0});
    
    r->addIndex<3>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord33({0, 1, 2});
    
    r->addIndex<3>(ord33, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord34({1, 2, 0});
    
    r->addIndex<3>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord35({0, 1, 2});
    
    r->addIndex<3>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("seen");
  if (r == 0) db->addRelation("seen", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("seen");
      std::vector<u16> ord36({0});
    
    r->addIndex<1>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("seen"), std::array<u16,1>{0}, b));
  r = db->getRelation("pair");
  if (r == 0) db->addStruct("pair", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pair");
      std::vector<u16> ord37({1, 2, 0});
    
    r->addIndex<3>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord38({0, 1, 2});
    
    r->addIndex<3>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord39({1, 2, 0});
    
    r->addIndex<3>(ord39, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("pair"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord40({1, 2, 3, 0});
    
    r->addIndex<4>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord41({0, 1, 2, 3});
    
    r->addIndex<4>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord42({1, 2, 0});
    
    r->addIndex<3>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord43({0, 1, 2});
    
    r->addIndex<3>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord44({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord45({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord46({1, 2, 0});
    
    r->addIndex<3>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord47({0, 1, 2});
    
    r->addIndex<3>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord48({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord49({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord50({1, 2, 3, 0});
    
    r->addIndex<4>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord51({0, 1, 2, 3});
    
    r->addIndex<4>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("fresh");
  if (r == 0) db->addRelation("fresh", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fresh");
      std::vector<u16> ord52({0});
    
    r->addIndex<1>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("fresh"), std::array<u16,1>{0}, b));
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
  r = db->getRelation("cand");
  if (r == 0) db->addRelation("cand", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("cand");
      std::vector<u16> ord56({0});
    
    r->addIndex<1>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("cand"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord57({1, 0});
    
    r->addIndex<2>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord58({0, 1});
    
    r->addIndex<2>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst7R5n8 const6b86b273ff34fce19d6b804e) (let __tconst0V9M7 constd4735e3a265e16eee03f5971) (let __tconst304Y5 const4e07408562bedb8b60ce05c1) (let __tconst0luG4 const4b227777d4dd1fc61c6f884f)) (probe pair (1 2 0) 2 __tconst7R5n8 __tconst0V9M7 __t8BaP3) (body (join pair (1 2 0) 2 __tconst304Y5 __tconst0luG4 __t5CLq6)) (head (emit seen (0) __t8BaP3) (emit cand (0) __t5CLq6) (emit cand (0) __t8BaP3)) neg_struct_key.slog:9 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** pairindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("seen");
      std::vector<u16> ord2({0});
      slog::Relation* readrel3 = db->getRelation("seen");
      head_index[0] = readrel3->getIndex(ord2, false);
      head_rel[1] = db->getRelation("cand");
      std::vector<u16> ord4({0});
      slog::Relation* readrel5 = db->getRelation("cand");
      head_index[1] = readrel5->getIndex(ord4, false);
      head_rel[2] = db->getRelation("cand");
      std::vector<u16> ord6({0});
      slog::Relation* readrel7 = db->getRelation("cand");
      head_index[2] = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({1, 2, 0});
      slog::Relation* readrel9 = db->getRelation("pair");
      driver_index = readrel9->getIndex(ord8, true);
      std::vector<u16> ord10({1, 2, 0});
      slog::Relation* readrel11 = db->getRelation("pair");
      pairindex0 = readrel11->getIndex(ord10, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c3 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c0, v_c1, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m12) {
        u64 v_c4 = m12[2];
        if (buckethash(v_c4) != bucket) return;
        slog::join_probe<3,2>(pairindex0, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m13) {
          u64 v_c5 = m13[2];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("neg_struct_key.slog:9", "delta:pair", _fires);
  
      if (!_done)
      {
        ReadTask1* _cont = new ReadTask1(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1(db,b), false);
  // (crule (pre (let __tconst7R5n8 const6b86b273ff34fce19d6b804e) (let __tconst0V9M7 constd4735e3a265e16eee03f5971) (let __tconst304Y5 const4e07408562bedb8b60ce05c1) (let __tconst0luG4 const4b227777d4dd1fc61c6f884f)) (once) (body) (head (mkstruct pair (1 2 0) __t5CLq6 __tconst304Y5 __tconst0luG4) (mkstruct pair (1 2 0) __t8BaP3 __tconst7R5n8 __tconst0V9M7)) neg_struct_key.slog:9 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("pair");
      head_rel[1] = db->getRelation("pair");
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c3 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c3}, std::array<u16,3>{1, 2, 0});
      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c0, v_c1}, std::array<u16,3>{1, 2, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("neg_struct_key.slog:9", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask14(db,b), true);
  // (crule (pre (let __tconst7R5n8 const6b86b273ff34fce19d6b804e) (let __tconst0V9M7 constd4735e3a265e16eee03f5971) (let __tconst304Y5 const4e07408562bedb8b60ce05c1) (let __tconst0luG4 const4b227777d4dd1fc61c6f884f)) (seeded) (body (join pair (1 2 0) 2 __tconst7R5n8 __tconst0V9M7 __t8BaP3) (join pair (1 2 0) 2 __tconst304Y5 __tconst0luG4 __t5CLq6)) (head (emit seen (0) __t8BaP3) (emit cand (0) __t5CLq6) (emit cand (0) __t8BaP3)) neg_struct_key.slog:9 #f)
  class ReadTask17 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** pairindex15;  slog::Index** pairindex16;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("seen");
      std::vector<u16> ord18({0});
      slog::Relation* readrel19 = db->getRelation("seen");
      head_index[0] = readrel19->getIndex(ord18, false);
      head_rel[1] = db->getRelation("cand");
      std::vector<u16> ord20({0});
      slog::Relation* readrel21 = db->getRelation("cand");
      head_index[1] = readrel21->getIndex(ord20, false);
      head_rel[2] = db->getRelation("cand");
      std::vector<u16> ord22({0});
      slog::Relation* readrel23 = db->getRelation("cand");
      head_index[2] = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 2, 0});
      slog::Relation* readrel25 = db->getRelation("pair");
      pairindex15 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 2, 0});
      slog::Relation* readrel27 = db->getRelation("pair");
      pairindex16 = readrel27->getIndex(ord26, false);
  
    }
    ReadTask17(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c3 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<3,2>(pairindex15, std::array<u64,3>{v_c0, v_c1, 0}, [&](const std::array<u64,3>& m28) {
        u64 v_c4 = m28[2];
        slog::join_probe<3,2>(pairindex16, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m29) {
          u64 v_c5 = m29[2];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("neg_struct_key.slog:9", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask17(db,b));
  s->addReadRel("pair");
  s->addDynamicRel("cand");
  s->addDynamicRel("pair");
  s->addDynamicRel("seen");
  d->push(s);
  d->continueRun();
}

