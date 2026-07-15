
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const4b227777d4dd1fc61c6f884f;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("c0b4becc");
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
      std::vector<u16> ord93({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord94({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord95({1, 2, 0});
    
    r->addIndex<3>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord96({0, 1, 2});
    
    r->addIndex<3>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp8RKK10");
  if (r == 0) db->addTempRelation("temp8RKK10", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord97({1, 2, 0});
    
    r->addIndex<3>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord98({0, 1, 2});
    
    r->addIndex<3>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("rebuilt");
  if (r == 0) db->addRelation("rebuilt", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("rebuilt");
      std::vector<u16> ord99({0});
    
    r->addIndex<1>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("rebuilt"), std::array<u16,1>{0}, b));
  r = db->getRelation("pair");
  if (r == 0) db->addStruct("pair", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pair");
      std::vector<u16> ord100({1, 2, 0});
    
    r->addIndex<3>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord101({0, 1, 2});
    
    r->addIndex<3>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord102({0, 1, 2});
    
    r->addIndex<3>(ord102, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord103({1, 2, 0});
    
    r->addIndex<3>(ord103, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("pair"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord104({1, 2, 3, 0});
    
    r->addIndex<4>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord105({0, 1, 2, 3});
    
    r->addIndex<4>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord106({1, 2, 0});
    
    r->addIndex<3>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord107({0, 1, 2});
    
    r->addIndex<3>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord108({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord109({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord110({1, 2, 0});
    
    r->addIndex<3>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord111({0, 1, 2});
    
    r->addIndex<3>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mk");
  if (r == 0) db->addRelation("mk", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mk");
      std::vector<u16> ord112({0});
    
    r->addIndex<1>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("mk"), std::array<u16,1>{0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord113({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord114({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord115({1, 2, 3, 0});
    
    r->addIndex<4>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord116({0, 1, 2, 3});
    
    r->addIndex<4>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("fsts");
  if (r == 0) db->addRelation("fsts", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fsts");
      std::vector<u16> ord117({0});
    
    r->addIndex<1>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
      std::vector<u16> ord118({0});
    
    r->addIndex<1>(ord118, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("fsts"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord119({0});
    
    r->addIndex<1>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord120({1, 2, 0});
    
    r->addIndex<3>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord121({0, 1, 2});
    
    r->addIndex<3>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("both");
  if (r == 0) db->addRelation("both", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("both");
      std::vector<u16> ord122({0, 1});
    
    r->addIndex<2>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("both"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord123({1, 0});
    
    r->addIndex<2>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord124({0, 1});
    
    r->addIndex<2>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst5w8S5 const4e07408562bedb8b60ce05c1) (let __tconst778J4 const4b227777d4dd1fc61c6f884f) (let __tconst3TAK2 const6b86b273ff34fce19d6b804e) (let __tconst170m1 constd4735e3a265e16eee03f5971)) (probe pair (1 2 0) 2 __tconst3TAK2 __tconst170m1 __t9jTF3) (body (join pair (1 2 0) 2 __tconst5w8S5 __tconst778J4 __t9pP66)) (head (emit mk (0) __t9pP66) (emit mk (0) __t9jTF3)) strat_struct.slog:11 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** pairindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mk");
      std::vector<u16> ord2({0});
      slog::Relation* readrel3 = db->getRelation("mk");
      head_index[0] = readrel3->getIndex(ord2, false);
      head_rel[1] = db->getRelation("mk");
      std::vector<u16> ord4({0});
      slog::Relation* readrel5 = db->getRelation("mk");
      head_index[1] = readrel5->getIndex(ord4, false);
      std::vector<u16> ord6({1, 2, 0});
      slog::Relation* readrel7 = db->getRelation("pair");
      driver_index = readrel7->getIndex(ord6, true);
      std::vector<u16> ord8({1, 2, 0});
      slog::Relation* readrel9 = db->getRelation("pair");
      pairindex0 = readrel9->getIndex(ord8, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c2, v_c3, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m10) {
        u64 v_c4 = m10[2];
        if (buckethash(v_c4) != bucket) return;
        slog::join_probe<3,2>(pairindex0, std::array<u64,3>{v_c0, v_c1, 0}, [&](const std::array<u64,3>& m11) {
          u64 v_c5 = m11[2];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("strat_struct.slog:11", "delta:pair", _fires);
  
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
  // (crule (pre) (scan mk __t7yPP9) (body (join-old pair (0 1 2) 1 (0 1 2) __t7yPP9 X Y)) (head (emit fsts (0) X)) strat_struct.slog:15 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pairindex12;  slog::Index** pairdelta13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("fsts");
      std::vector<u16> ord15({0});
      slog::Relation* readrel16 = db->getRelation("fsts");
      head_index[0] = readrel16->getIndex(ord15, false);
      outer_rel = db->getRelation("mk");
      std::vector<u16> ord17({0, 1, 2});
      slog::Relation* readrel18 = db->getRelation("pair");
      pairindex12 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({0, 1, 2});
      slog::Relation* readrel20 = db->getRelation("pair");
      pairdelta13 = readrel20->getIndex(ord19, true);
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[0];
        slog::join_probe_old<3,1>(pairindex12, pairdelta13, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m21) {
          u64 v_c7 = m21[1]; u64 v_c8 = m21[2];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("strat_struct.slog:15", "delta:mk", _fires);
  
      if (!_done)
      {
        ReadTask14* _cont = new ReadTask14(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask14(db,b), false);
  // (crule (pre (let __tconst5w8S5 const4e07408562bedb8b60ce05c1) (let __tconst778J4 const4b227777d4dd1fc61c6f884f) (let __tconst3TAK2 const6b86b273ff34fce19d6b804e) (let __tconst170m1 constd4735e3a265e16eee03f5971)) (once) (body) (head (mkstruct pair (1 2 0) __t9pP66 __tconst5w8S5 __tconst778J4) (mkstruct pair (1 2 0) __t9jTF3 __tconst3TAK2 __tconst170m1)) strat_struct.slog:11 #f)
  class ReadTask22 : public slog::Task
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
    ReadTask22(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c0, v_c1}, std::array<u16,3>{1, 2, 0});
      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c2, v_c3}, std::array<u16,3>{1, 2, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("strat_struct.slog:11", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask22(db,b), true);
  // (crule (pre) (scan temp8RKK10 X Y) (body (join pair (1 2 0) 2 Y X __t5YYp8)) (head (emit rebuilt (0) __t5YYp8)) strat_struct.slog:17 #f)
  class ReadTask24 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pairindex23;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("rebuilt");
      std::vector<u16> ord25({0});
      slog::Relation* readrel26 = db->getRelation("rebuilt");
      head_index[0] = readrel26->getIndex(ord25, false);
      outer_rel = db->getRelation("temp8RKK10");
      std::vector<u16> ord27({1, 2, 0});
      slog::Relation* readrel28 = db->getRelation("pair");
      pairindex23 = readrel28->getIndex(ord27, false);
  
    }
    ReadTask24(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[0];
        u64 v_c8 = _t[1];
        slog::join_probe<3,2>(pairindex23, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m29) {
          u64 v_c9 = m29[2];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("strat_struct.slog:17", "delta:temp8RKK10", _fires);
  
      if (!_done)
      {
        ReadTask24* _cont = new ReadTask24(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask24(db,b), false);
  // (crule (pre) (scan pair __t7yPP9 X Y) (body (join mk (0) 1 __t7yPP9)) (head (emit fsts (0) X)) strat_struct.slog:15 #f)
  class ReadTask31 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkindex30;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("fsts");
      std::vector<u16> ord32({0});
      slog::Relation* readrel33 = db->getRelation("fsts");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("pair");
      std::vector<u16> ord34({0});
      slog::Relation* readrel35 = db->getRelation("mk");
      mkindex30 = readrel35->getIndex(ord34, false);
  
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
        u64 v_c6 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        slog::join_probe<1,1>(mkindex30, std::array<u64,1>{v_c6}, [&](const std::array<u64,1>& m36) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("strat_struct.slog:15", "delta:pair", _fires);
  
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
  // (crule (pre (let __tconst5w8S5 const4e07408562bedb8b60ce05c1) (let __tconst778J4 const4b227777d4dd1fc61c6f884f) (let __tconst3TAK2 const6b86b273ff34fce19d6b804e) (let __tconst170m1 constd4735e3a265e16eee03f5971)) (seeded) (body (join pair (1 2 0) 2 __tconst3TAK2 __tconst170m1 __t9jTF3) (join pair (1 2 0) 2 __tconst5w8S5 __tconst778J4 __t9pP66)) (head (emit mk (0) __t9pP66) (emit mk (0) __t9jTF3)) strat_struct.slog:11 #f)
  class ReadTask39 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** pairindex37;  slog::Index** pairindex38;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mk");
      std::vector<u16> ord40({0});
      slog::Relation* readrel41 = db->getRelation("mk");
      head_index[0] = readrel41->getIndex(ord40, false);
      head_rel[1] = db->getRelation("mk");
      std::vector<u16> ord42({0});
      slog::Relation* readrel43 = db->getRelation("mk");
      head_index[1] = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 2, 0});
      slog::Relation* readrel45 = db->getRelation("pair");
      pairindex37 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 2, 0});
      slog::Relation* readrel47 = db->getRelation("pair");
      pairindex38 = readrel47->getIndex(ord46, false);
  
    }
    ReadTask39(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<3,2>(pairindex37, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m48) {
        u64 v_c4 = m48[2];
        slog::join_probe<3,2>(pairindex38, std::array<u64,3>{v_c0, v_c1, 0}, [&](const std::array<u64,3>& m49) {
          u64 v_c5 = m49[2];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("strat_struct.slog:11", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask39(db,b));
  // (crule (pre) (scan mk __t9F607) (body (join-old pair (0 1 2) 1 (0 1 2) __t9F607 X Y) (join-old fsts (0) 1 (0) X)) (head (emit both (0 1) X Y)) strat_struct.slog:16 #f)
  class ReadTask54 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pairindex50;  slog::Index** fstsindex51;  slog::Index** pairdelta52;  slog::Index** fstsdelta53;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("both");
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("both");
      head_index[0] = readrel56->getIndex(ord55, false);
      outer_rel = db->getRelation("mk");
      std::vector<u16> ord57({0, 1, 2});
      slog::Relation* readrel58 = db->getRelation("pair");
      pairindex50 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({0, 1, 2});
      slog::Relation* readrel60 = db->getRelation("pair");
      pairdelta52 = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({0});
      slog::Relation* readrel62 = db->getRelation("fsts");
      fstsindex51 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({0});
      slog::Relation* readrel64 = db->getRelation("fsts");
      fstsdelta53 = readrel64->getIndex(ord63, true);
  
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
        u64 v_c10 = _t[0];
        slog::join_probe_old<3,1>(pairindex50, pairdelta52, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m65) {
          u64 v_c7 = m65[1]; u64 v_c8 = m65[2];
          slog::join_probe_old<1,1>(fstsindex51, fstsdelta53, std::array<u64,1>{v_c7}, [&](const std::array<u64,1>& m66) {
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c8}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("strat_struct.slog:16", "delta:mk", _fires);
  
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
  // (crule (pre) (scan fsts X) (body (join pair (1 2 0) 1 X Y __t9F607) (join mk (0) 1 __t9F607)) (head (emit both (0 1) X Y)) strat_struct.slog:16 #f)
  class ReadTask69 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pairindex67;  slog::Index** mkindex68;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("both");
      std::vector<u16> ord70({0, 1});
      slog::Relation* readrel71 = db->getRelation("both");
      head_index[0] = readrel71->getIndex(ord70, false);
      outer_rel = db->getRelation("fsts");
      std::vector<u16> ord72({1, 2, 0});
      slog::Relation* readrel73 = db->getRelation("pair");
      pairindex67 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({0});
      slog::Relation* readrel75 = db->getRelation("mk");
      mkindex68 = readrel75->getIndex(ord74, false);
  
    }
    ReadTask69(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[0];
        slog::join_probe<3,1>(pairindex67, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m76) {
          u64 v_c8 = m76[1]; u64 v_c10 = m76[2];
          slog::join_probe<1,1>(mkindex68, std::array<u64,1>{v_c10}, [&](const std::array<u64,1>& m77) {
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c8}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("strat_struct.slog:16", "delta:fsts", _fires);
  
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
  // (crule (pre) (scan both X Y) (body) (head (emit-temp temp8RKK10 X Y) (mkstruct pair (1 2 0) __t5YYp8 Y X)) strat_struct.slog:17 #f)
  class ReadTask78 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8RKK10");
      head_rel[1] = db->getRelation("pair");
      outer_rel = db->getRelation("both");
  
    }
    ReadTask78(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[0];
        u64 v_c8 = _t[1];
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c7, v_c8});
        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c8, v_c7}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("strat_struct.slog:17", "delta:both", _fires);
  
      if (!_done)
      {
        ReadTask78* _cont = new ReadTask78(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask78(db,b), false);
  // (crule (pre) (scan pair __t9F607 X Y) (body (join mk (0) 1 __t9F607) (join-old fsts (0) 1 (0) X)) (head (emit both (0 1) X Y)) strat_struct.slog:16 #f)
  class ReadTask82 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkindex79;  slog::Index** fstsindex80;  slog::Index** fstsdelta81;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("both");
      std::vector<u16> ord83({0, 1});
      slog::Relation* readrel84 = db->getRelation("both");
      head_index[0] = readrel84->getIndex(ord83, false);
      outer_rel = db->getRelation("pair");
      std::vector<u16> ord85({0});
      slog::Relation* readrel86 = db->getRelation("mk");
      mkindex79 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({0});
      slog::Relation* readrel88 = db->getRelation("fsts");
      fstsindex80 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({0});
      slog::Relation* readrel90 = db->getRelation("fsts");
      fstsdelta81 = readrel90->getIndex(ord89, true);
  
    }
    ReadTask82(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        slog::join_probe<1,1>(mkindex79, std::array<u64,1>{v_c10}, [&](const std::array<u64,1>& m91) {
          slog::join_probe_old<1,1>(fstsindex80, fstsdelta81, std::array<u64,1>{v_c7}, [&](const std::array<u64,1>& m92) {
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c7, v_c8}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("strat_struct.slog:16", "delta:pair", _fires);
  
      if (!_done)
      {
        ReadTask82* _cont = new ReadTask82(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask82(db,b), false);
  s->addReadRel("both");
  s->addReadRel("fsts");
  s->addReadRel("mk");
  s->addReadRel("pair");
  s->addReadRel("temp8RKK10");
  s->addDynamicRel("both");
  s->addDynamicRel("fsts");
  s->addDynamicRel("mk");
  s->addDynamicRel("pair");
  s->addDynamicRel("rebuilt");
  s->addDynamicRel("temp8RKK10");
  s->addAccelRel("both");
  s->addAccelRel("fsts");
  s->addAccelRel("mk");
  s->addAccelRel("rebuilt");
  d->push(s);
  d->continueRun();
}

