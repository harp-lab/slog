
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const4bc9274d8758b867e8c071a6;
u64 v_const3aae004f448787fcf06c2d53;
u64 v_const3fa5834dc920d385ca9b099c;
u64 v_constc100f95c1913f9c72fc1f4ef;
u64 v_constac8d8342bbb2362d13f0a559;
u64 v_const879923da020d1533f4d8e921;
u64 v_const7f3e916bf628c503cac5f6ba;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("c9385b0a");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const4bc9274d8758b867e8c071a6 = db->encodeString("red");
  v_const3aae004f448787fcf06c2d53 = db->encodeString("blue");
  v_const3fa5834dc920d385ca9b099c = db->encodeString("d");
  v_constc100f95c1913f9c72fc1f4ef = db->encodeString("b");
  v_constac8d8342bbb2362d13f0a559 = db->encodeString("a");
  v_const879923da020d1533f4d8e921 = db->encodeString("c");
  v_const7f3e916bf628c503cac5f6ba = db->encodeString("green");
  r = db->getRelation("verdict");
  if (r == 0) db->addRelation("verdict", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("verdict");
      std::vector<u16> ord23({0, 1});
    
    r->addIndex<2>(ord23, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("verdict"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord24({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord24, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord25({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord25, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord26({1, 2, 0});
    
    r->addIndex<3>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord27({0, 1, 2});
    
    r->addIndex<3>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord28({1, 2, 0});
    
    r->addIndex<3>(ord28, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord29({0, 1, 2});
    
    r->addIndex<3>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord30({1, 2, 3, 0});
    
    r->addIndex<4>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord31({0, 1, 2, 3});
    
    r->addIndex<4>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord32({1, 2, 0});
    
    r->addIndex<3>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord33({0, 1, 2});
    
    r->addIndex<3>(ord33, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord34({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord35({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord36({1, 2, 0});
    
    r->addIndex<3>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord37({0, 1, 2});
    
    r->addIndex<3>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord38({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord39({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("item");
  if (r == 0) db->addRelation("item", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("item");
      std::vector<u16> ord40({0, 1});
    
    r->addIndex<2>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("item"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("isred");
  if (r == 0) db->addRelation("isred", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("isred");
      std::vector<u16> ord41({0});
    
    r->addIndex<1>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("isred"), std::array<u16,1>{0}, b));
  r = db->getRelation("isgreen");
  if (r == 0) db->addRelation("isgreen", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("isgreen");
      std::vector<u16> ord42({0});
    
    r->addIndex<1>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("isgreen"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord43({1, 2, 3, 0});
    
    r->addIndex<4>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord44({0, 1, 2, 3});
    
    r->addIndex<4>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
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
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord48({1, 0});
    
    r->addIndex<2>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord49({0, 1});
    
    r->addIndex<2>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord50({1, 0});
    
    r->addIndex<2>(ord50, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst6Bzf12 const7f3e916bf628c503cac5f6ba) (let __tconst7rSk13 const4bc9274d8758b867e8c071a6) (let __tconst1MNc14 const3aae004f448787fcf06c2d53) (let __tconst4n3c4 constac8d8342bbb2362d13f0a559) (let __tconst578c6 constc100f95c1913f9c72fc1f4ef) (let __tconst55yX8 const879923da020d1533f4d8e921) (let __tconst5CBV10 const3fa5834dc920d385ca9b099c)) (probe _enum (1 0) 1 __tconst6Bzf12 __t7gPF5) (body (exists _enum (1 0) 1 __tconst1MNc14) (join _enum (1 0) 1 __tconst7rSk13 __t9yxi7) (join _enum (1 0) 1 __tconst1MNc14 __t8i0l9)) (head (emit item (0 1) __tconst4n3c4 __t9yxi7) (emit item (0 1) __tconst578c6 __t7gPF5) (emit item (0 1) __tconst55yX8 __t9yxi7) (emit item (0 1) __tconst5CBV10 __t8i0l9)) enum_basic.slog:12 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex0;  slog::Index** _enumindex1;  slog::Index** _enumindex2;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("item");
      std::vector<u16> ord4({0, 1});
      slog::Relation* readrel5 = db->getRelation("item");
      head_index[0] = readrel5->getIndex(ord4, false);
      head_rel[1] = db->getRelation("item");
      std::vector<u16> ord6({0, 1});
      slog::Relation* readrel7 = db->getRelation("item");
      head_index[1] = readrel7->getIndex(ord6, false);
      head_rel[2] = db->getRelation("item");
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("item");
      head_index[2] = readrel9->getIndex(ord8, false);
      head_rel[3] = db->getRelation("item");
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("item");
      head_index[3] = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("_enum");
      driver_index = readrel13->getIndex(ord12, true);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("_enum");
      _enumindex0 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("_enum");
      _enumindex1 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 0});
      slog::Relation* readrel19 = db->getRelation("_enum");
      _enumindex2 = readrel19->getIndex(ord18, false);
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7f3e916bf628c503cac5f6ba;
      u64 v_c1 = v_const4bc9274d8758b867e8c071a6;
      u64 v_c2 = v_const3aae004f448787fcf06c2d53;
      u64 v_c3 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c4 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c5 = v_const879923da020d1533f4d8e921;
      u64 v_c6 = v_const3fa5834dc920d385ca9b099c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m20) {
        u64 v_c7 = m20[1];
        if (buckethash(v_c7) != bucket) return;
        if (!slog::exists_probe<2,1>(_enumindex0, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<2,1>(_enumindex1, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m21) {
          u64 v_c8 = m21[1];
          slog::join_probe<2,1>(_enumindex2, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m22) {
            u64 v_c9 = m22[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c3, v_c8}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c4, v_c7}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c5, v_c8}, std::array<u16,2>{0, 1});
            slog::emit<2>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c6, v_c9}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("enum_basic.slog:12", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask3* _cont = new ReadTask3(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3(db,b), true);
  s->addReadRel("_enum");
  s->addDynamicRel("item");
  d->push(s);
  d->continueRun();
}

