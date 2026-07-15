
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const18d10c7d2b4b04aaf04254d1;
u64 v_const076de6e730df0b4c3860877a;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("918fd06c");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const18d10c7d2b4b04aaf04254d1 = db->encodeString("true");
  v_const076de6e730df0b4c3860877a = db->encodeString("false");
  r = db->getRelation("yes");
  if (r == 0) db->addRelation("yes", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("yes");
      std::vector<u16> ord44({0});
    
    r->addIndex<1>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("yes"), std::array<u16,1>{0}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord45({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord46({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord47({1, 2, 0});
    
    r->addIndex<3>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord48({0, 1, 2});
    
    r->addIndex<3>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord49({1, 2, 0});
    
    r->addIndex<3>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord50({0, 1, 2});
    
    r->addIndex<3>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord51({1, 2, 3, 0});
    
    r->addIndex<4>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord52({0, 1, 2, 3});
    
    r->addIndex<4>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord53({1, 2, 0});
    
    r->addIndex<3>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord54({0, 1, 2});
    
    r->addIndex<3>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord55({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord56({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord57({1, 2, 0});
    
    r->addIndex<3>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord58({0, 1, 2});
    
    r->addIndex<3>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord59({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord60({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("inverted");
  if (r == 0) db->addRelation("inverted", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("inverted");
      std::vector<u16> ord61({0, 1});
    
    r->addIndex<2>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("inverted"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord62({1, 2, 3, 0});
    
    r->addIndex<4>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord63({0, 1, 2, 3});
    
    r->addIndex<4>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("flag");
  if (r == 0) db->addRelation("flag", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("flag");
      std::vector<u16> ord64({1, 0});
    
    r->addIndex<2>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("flag"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord65({0});
    
    r->addIndex<1>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord66({1, 2, 0});
    
    r->addIndex<3>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord67({0, 1, 2});
    
    r->addIndex<3>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord68({1, 0});
    
    r->addIndex<2>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord69({0, 1});
    
    r->addIndex<2>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord70({1, 0});
    
    r->addIndex<2>(ord70, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst6xtH16 const18d10c7d2b4b04aaf04254d1)) (probe _enum (1 0) 1 __tconst6xtH16 __tconst125S9) (body (join flag (1 0) 1 __tconst125S9 n)) (head (emit yes (0) n)) bools.slog:12 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** flagindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("yes");
      std::vector<u16> ord2({0});
      slog::Relation* readrel3 = db->getRelation("yes");
      head_index[0] = readrel3->getIndex(ord2, false);
      std::vector<u16> ord4({1, 0});
      slog::Relation* readrel5 = db->getRelation("_enum");
      driver_index = readrel5->getIndex(ord4, true);
      std::vector<u16> ord6({1, 0});
      slog::Relation* readrel7 = db->getRelation("flag");
      flagindex0 = readrel7->getIndex(ord6, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const18d10c7d2b4b04aaf04254d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m8) {
        u64 v_c1 = m8[1];
        if (buckethash(v_c1) != bucket) return;
        slog::join_probe<2,1>(flagindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m9) {
          u64 v_c2 = m9[1];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("bools.slog:12", "all:_enum", _fires);
  
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
      s->addTask(phase_read, new ReadTask1(db,b), true);
  // (crule (pre (let __tconst2P5m12 const18d10c7d2b4b04aaf04254d1) (let __tconst3tWJ13 const076de6e730df0b4c3860877a)) (probe _enum (1 0) 1 __tconst2P5m12 __tconst7Qdn4) (body (exists flag (1 0) 1 __tconst7Qdn4) (join _enum (1 0) 1 __tconst3tWJ13 __tconst3D893) (join flag (1 0) 1 __tconst7Qdn4 n)) (head (emit inverted (0 1) n __tconst3D893)) bools.slog:14 #f)
  class ReadTask13 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** flagindex10;  slog::Index** _enumindex11;  slog::Index** flagindex12;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("inverted");
      std::vector<u16> ord14({0, 1});
      slog::Relation* readrel15 = db->getRelation("inverted");
      head_index[0] = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("_enum");
      driver_index = readrel17->getIndex(ord16, true);
      std::vector<u16> ord18({1, 0});
      slog::Relation* readrel19 = db->getRelation("flag");
      flagindex10 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 0});
      slog::Relation* readrel21 = db->getRelation("_enum");
      _enumindex11 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("flag");
      flagindex12 = readrel23->getIndex(ord22, false);
  
    }
    ReadTask13(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_const18d10c7d2b4b04aaf04254d1;
      u64 v_c4 = v_const076de6e730df0b4c3860877a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c3, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m24) {
        u64 v_c5 = m24[1];
        if (buckethash(v_c5) != bucket) return;
        if (!slog::exists_probe<2,1>(flagindex10, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<2,1>(_enumindex11, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m25) {
          u64 v_c6 = m25[1];
          slog::join_probe<2,1>(flagindex12, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m26) {
            u64 v_c2 = m26[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c2, v_c6}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("bools.slog:14", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask13* _cont = new ReadTask13(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask13(db,b), true);
  // (crule (pre (let __tconst3hQ410 const076de6e730df0b4c3860877a) (let __tconst5SEV11 const18d10c7d2b4b04aaf04254d1)) (probe _enum (1 0) 1 __tconst3hQ410 __tconst4gDo2) (body (exists flag (1 0) 1 __tconst4gDo2) (join _enum (1 0) 1 __tconst5SEV11 __tconst4Joj1) (join flag (1 0) 1 __tconst4gDo2 n)) (head (emit inverted (0 1) n __tconst4Joj1)) bools.slog:15 #f)
  class ReadTask30 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** flagindex27;  slog::Index** _enumindex28;  slog::Index** flagindex29;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("inverted");
      std::vector<u16> ord31({0, 1});
      slog::Relation* readrel32 = db->getRelation("inverted");
      head_index[0] = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("_enum");
      driver_index = readrel34->getIndex(ord33, true);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("flag");
      flagindex27 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 0});
      slog::Relation* readrel38 = db->getRelation("_enum");
      _enumindex28 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 0});
      slog::Relation* readrel40 = db->getRelation("flag");
      flagindex29 = readrel40->getIndex(ord39, false);
  
    }
    ReadTask30(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c7 = v_const076de6e730df0b4c3860877a;
      u64 v_c8 = v_const18d10c7d2b4b04aaf04254d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c7, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m41) {
        u64 v_c9 = m41[1];
        if (buckethash(v_c9) != bucket) return;
        if (!slog::exists_probe<2,1>(flagindex27, std::array<u64,2>{v_c9, 0})) return;
        slog::join_probe<2,1>(_enumindex28, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m42) {
          u64 v_c10 = m42[1];
          slog::join_probe<2,1>(flagindex29, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m43) {
            u64 v_c2 = m43[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c2, v_c10}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("bools.slog:15", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask30* _cont = new ReadTask30(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask30(db,b), true);
  s->addReadRel("_enum");
  s->addReadRel("flag");
  s->addDynamicRel("inverted");
  s->addDynamicRel("yes");
  d->push(s);
  d->continueRun();
}

