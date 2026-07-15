
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const52b66dd2767dc28cbbeacdde;
u64 v_const19581e27de7ced00ff1ce50b;
u64 v_const894a226afe261ec8f66c9d49;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("3563cb8b");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const52b66dd2767dc28cbbeacdde = db->encodeString("seq_split_mixed.slog:14");
  v_const19581e27de7ced00ff1ce50b = s32_encode(9);
  v_const894a226afe261ec8f66c9d49 = db->encodeString("pair2");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord65({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord66({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord67({1, 2, 0});
    
    r->addIndex<3>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord68({0, 1, 2});
    
    r->addIndex<3>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord69({1, 2, 0});
    
    r->addIndex<3>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord70({0, 1, 2});
    
    r->addIndex<3>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("pair2");
  if (r == 0) db->addRelation("pair2", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pair2");
      std::vector<u16> ord71({0, 1});
    
    r->addIndex<2>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("pair2"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord72({1, 2, 3, 0});
    
    r->addIndex<4>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord73({0, 1, 2, 3});
    
    r->addIndex<4>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord74({1, 2, 0});
    
    r->addIndex<3>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord75({0, 1, 2});
    
    r->addIndex<3>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord76({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord77({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord78({1, 2, 0});
    
    r->addIndex<3>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord79({0, 1, 2});
    
    r->addIndex<3>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord80({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord81({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord82({1, 2, 3, 0});
    
    r->addIndex<4>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord83({0, 1, 2, 3});
    
    r->addIndex<4>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord84({0});
    
    r->addIndex<1>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("doc");
  if (r == 0) db->addRelation("doc", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("doc");
      std::vector<u16> ord85({0});
    
    r->addIndex<1>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("doc"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord86({1, 2, 0});
    
    r->addIndex<3>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord87({0, 1, 2});
    
    r->addIndex<3>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("afterx");
  if (r == 0) db->addRelation("afterx", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("afterx");
      std::vector<u16> ord88({0, 1, 2});
    
    r->addIndex<3>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("afterx"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord89({1, 0});
    
    r->addIndex<2>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord90({0, 1});
    
    r->addIndex<2>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$seq_posdem");
  if (r == 0) db->addRelation("$seq_posdem", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_posdem");
      std::vector<u16> ord91({0, 1});
    
    r->addIndex<2>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("$seq_posdem"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("$seq_pos");
  if (r == 0) db->addRelation("$seq_pos", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_pos");
      std::vector<u16> ord92({0, 1, 2});
    
    r->addIndex<3>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord93({1, 0, 2});
    
    r->addIndex<3>(ord93, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_pos"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord94({0, 1, 2});
    
    r->addIndex<3>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord95({0, 1, 2});
    
    r->addIndex<3>(ord95, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{0, 1, 2}, b));
  {
    std::vector<u16> seqcols({0, 1, 2});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("afterx"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("doc"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre) (scan div_by_zero __erre4S78300 __errf5bwX301 __errf5AOZ302) (body) (head (emit error (0) __erre4S78300)) <internal>:1 #f)
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
      outer_rel = db->getRelation("div_by_zero");
  
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
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
  // (crule (pre) (scan mpz_overflow __erre0JpV322 __errf6DrZ323 __errf5a0x324 __errf2Mxf325 __errf5kMa326) (body) (head (emit error (0) __erre0JpV322)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre2Z0D303 __errf2lwa304 __errf3NNk305) (body) (head (emit error (0) __erre2Z0D303)) <internal>:1 #f)
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
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord7({0});
      slog::Relation* readrel8 = db->getRelation("error");
      head_index[0] = readrel8->getIndex(ord7, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c8 = _t[0];
        u64 v_c9 = _t[1];
        u64 v_c10 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
      s->addTask(phase_read, new ReadTask6(db,b), false);
  // (crule (pre) (scan toint_range __erre20vR314 __errf3FxA315 __errf70Nl316) (body) (head (emit error (0) __erre20vR314)) <internal>:1 #f)
  class ReadTask9 : public slog::Task
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
      std::vector<u16> ord10({0});
      slog::Relation* readrel11 = db->getRelation("error");
      head_index[0] = readrel11->getIndex(ord10, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c11}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask9* _cont = new ReadTask9(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), false);
  // (crule (pre (let _00024sqc2QJz42 const6b86b273ff34fce19d6b804e) (let _00024sqc9Rsa43 const6b86b273ff34fce19d6b804e) (let _00024sqc58tN46 const5feceb66ffc86f38d952786c) (let _00024sqc15jJ48 const19581e27de7ced00ff1ce50b) (let _00024sqo0e3G51 const19581e27de7ced00ff1ce50b) (let _00024sqc3TAg50 const5feceb66ffc86f38d952786c) (let _00024sqc3C0x52 const5feceb66ffc86f38d952786c) (let _00024sqc8aAs54 const5feceb66ffc86f38d952786c) (let _00024sqc6TTG58 const5feceb66ffc86f38d952786c) (let _00024sqc2UI061 constd4735e3a265e16eee03f5971) (let _00024sqc7WSF62 const6b86b273ff34fce19d6b804e) (let _00024sqc6kPM63 const6b86b273ff34fce19d6b804e)) (probe $seq_at (0 1 2) 1 _00024sqo0e3G51 _00024sqo2ENy49 _00024seq0) (body (join doc (0) 1 _00024seq0) (letp _00024sql1lqR40 (aslst _00024seq0)) (let _00024sqp2EiS44 (_0002d _00024sqo2ENy49 _00024sqc3TAg50)) (join $seq_pos (0 1 2) 3 _00024sql1lqR40 _00024sqc9Rsa43 _00024sqp2EiS44) (let _00024sqn0pOQ41 (llen _00024sql1lqR40)) (cmp ge _00024sqn0pOQ41 _00024sqc2QJz42) (let _00024sqp7QYK45 (_0002b _00024sqp2EiS44 _00024sqc9Rsa43)) (let _00024sqp9RZX53 (_0002d _00024sqn0pOQ41 _00024sqc3C0x52)) (cmp le _00024sqp7QYK45 _00024sqp9RZX53) (let _00024sqp8qVF47 (_0002b _00024sqp2EiS44 _00024sqc58tN46)) (letp chk1Z2A332 (lref _00024sql1lqR40 _00024sqp8qVF47)) (eq _00024sqc15jJ48 chk1Z2A332) (let as (lslice _00024sql1lqR40 _00024sqc8aAs54 _00024sqp2EiS44)) (let _00024sqp1fuP59 (_0002d _00024sqn0pOQ41 _00024sqc6TTG58)) (let _00024sqm6AXR60 (_0002d _00024sqp1fuP59 _00024sqp7QYK45)) (let _00024sqm9fgB64 (_0002a _00024sqc6kPM63 _00024sqm6AXR60)) (let _00024sqm6GBh65 (_0002b _00024sqm9fgB64 _00024sqc7WSF62)) (let _00024sqm3TFc66 (_0002f _00024sqm6GBh65 _00024sqc2UI061)) (let _00024sqp8fAa67 (_0002b _00024sqp7QYK45 _00024sqm3TFc66)) (let bs (lslice _00024sql1lqR40 _00024sqp7QYK45 _00024sqp8fAa67)) (let cs (lslice _00024sql1lqR40 _00024sqp8fAa67 _00024sqp1fuP59))) (head (emit afterx (0 1 2) as bs cs)) seq_split_mixed.slog:13 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** docindex12;  slog::Index** $seq_posindex13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("afterx");
      std::vector<u16> ord15({0, 1, 2});
      slog::Relation* readrel16 = db->getRelation("afterx");
      head_index[0] = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({0, 1, 2});
      slog::Relation* readrel18 = db->getRelation("$seq_at");
      driver_index = readrel18->getIndex(ord17, true);
      std::vector<u16> ord19({0});
      slog::Relation* readrel20 = db->getRelation("doc");
      docindex12 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({0, 1, 2});
      slog::Relation* readrel22 = db->getRelation("$seq_pos");
      $seq_posindex13 = readrel22->getIndex(ord21, false);
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c16 = v_const5feceb66ffc86f38d952786c;
      u64 v_c17 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c18 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
      u64 v_c20 = v_const5feceb66ffc86f38d952786c;
      u64 v_c21 = v_const5feceb66ffc86f38d952786c;
      u64 v_c22 = v_const5feceb66ffc86f38d952786c;
      u64 v_c23 = v_constd4735e3a265e16eee03f5971;
      u64 v_c24 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c25 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c18, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m23) {
        u64 v_c26 = m23[1];
        u64 v_c27 = m23[2];
        if (buckethash(v_c26) != bucket) return;
        slog::join_probe<1,1>(docindex12, std::array<u64,1>{v_c27}, [&](const std::array<u64,1>& m24) {
          bool ok25 = true;
          u64 v_c28 = _prim_aslst(db, v_c27, &ok25);
          if (!ok25) return;
          u64 v_c29 = _prim__0002d(db, v_c26, v_c19);
          if (v_c29 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
          slog::join_probe<3,3>($seq_posindex13, std::array<u64,3>{v_c28, v_c15, v_c29}, [&](const std::array<u64,3>& m26) {
            u64 v_c30 = _prim_llen(db, v_c28);
            if (v_c30 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c31 = _prim_ge(db, v_c30, v_c14);
            if (v_c31 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            if (!v_c31) return;
            u64 v_c32 = _prim__0002b(db, v_c29, v_c15);
            if (v_c32 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c33 = _prim__0002d(db, v_c30, v_c20);
            if (v_c33 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c34 = _prim_le(db, v_c32, v_c33);
            if (v_c34 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            if (!v_c34) return;
            u64 v_c35 = _prim__0002b(db, v_c29, v_c16);
            if (v_c35 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            bool ok29 = true;
            u64 v_c36 = _prim_lref(db, v_c28, v_c35, &ok29);
            if (!ok29) return;
            if (v_c17 != v_c36) return;
            u64 v_c37 = _prim_lslice(db, v_c28, v_c21, v_c29);
            if (v_c37 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c38 = _prim__0002d(db, v_c30, v_c22);
            if (v_c38 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c39 = _prim__0002d(db, v_c38, v_c32);
            if (v_c39 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c40 = _prim__0002a(db, v_c25, v_c39);
            if (v_c40 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c41 = _prim__0002b(db, v_c40, v_c24);
            if (v_c41 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c42 = _prim__0002f(db, v_c41, v_c23);
            if (v_c42 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c43 = _prim__0002b(db, v_c32, v_c42);
            if (v_c43 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c44 = _prim_lslice(db, v_c28, v_c32, v_c43);
            if (v_c44 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            u64 v_c45 = _prim_lslice(db, v_c28, v_c43, v_c38);
            if (v_c45 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:13"); return; }
            ++_fires;
            slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c37, v_c44, v_c45}, std::array<u16,3>{0, 1, 2});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_split_mixed.slog:13", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask14* _cont = new ReadTask14(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask14(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre0J61295 __errf1ITn296 __errf3Chk297 __errf92Jf298 __errf9Y2D299) (body) (head (emit error (0) __erre0J61295)) <internal>:1 #f)
  class ReadTask30 : public slog::Task
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
      std::vector<u16> ord31({0});
      slog::Relation* readrel32 = db->getRelation("error");
      head_index[0] = readrel32->getIndex(ord31, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask30(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[3];
        u64 v_c50 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c46}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask30* _cont = new ReadTask30(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask30(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre9dxw327 __errf58dq328 __errf5LpW329) (body) (head (emit error (0) __erre9dxw327)) <internal>:1 #f)
  class ReadTask33 : public slog::Task
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
      std::vector<u16> ord34({0});
      slog::Relation* readrel35 = db->getRelation("error");
      head_index[0] = readrel35->getIndex(ord34, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
        u64 v_c51 = _t[0];
        u64 v_c52 = _t[1];
        u64 v_c53 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c51}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre (let _00024sqc5p7A26 constd4735e3a265e16eee03f5971) (let _00024sqc1efz27 const6b86b273ff34fce19d6b804e) (let _00024sqc6QsM30 const5feceb66ffc86f38d952786c) (let _00024sqc00zM32 const6b86b273ff34fce19d6b804e) (let _00024sqc3I5g35 const5feceb66ffc86f38d952786c) (let _00024sqc63OG37 const5feceb66ffc86f38d952786c) (let __trid0gkS69 const52b66dd2767dc28cbbeacdde) (let __trel8tGP70 const894a226afe261ec8f66c9d49) (let __tcol1h6j71 const5feceb66ffc86f38d952786c) (let __trel8u7x72 const894a226afe261ec8f66c9d49) (let __tcol8yVH73 const6b86b273ff34fce19d6b804e)) (probe $seq_pos (1 0 2) 1 _00024sqc1efz27 _00024sql8rVE24 _00024sqp91XV28) (body (join $seq_pos (0 1 2) 2 _00024sql8rVE24 _00024sqc00zM32 _00024sqp17VS33) (join doc (0) 0 _00024seq0) (letp chk8hkV330 (aslst _00024seq0)) (eq _00024sql8rVE24 chk8hkV330) (let _00024sqn0xpN25 (llen _00024sql8rVE24)) (cmp ge _00024sqn0xpN25 _00024sqc5p7A26) (let _00024sqp1OJB29 (_0002b _00024sqp91XV28 _00024sqc1efz27)) (cmp le _00024sqp1OJB29 _00024sqp17VS33) (let _00024sqp2Yns34 (_0002b _00024sqp17VS33 _00024sqc00zM32)) (let _00024sqp5qlG38 (_0002d _00024sqn0xpN25 _00024sqc63OG37)) (cmp le _00024sqp2Yns34 _00024sqp5qlG38) (let _00024sqp9bYF31 (_0002b _00024sqp91XV28 _00024sqc6QsM30)) (letp x (lref _00024sql8rVE24 _00024sqp9bYF31)) (let _00024sqp6bpk36 (_0002b _00024sqp17VS33 _00024sqc3I5g35)) (letp y (lref _00024sql8rVE24 _00024sqp6bpk36))) (head (tycheck x (accept int) __trid0gkS69 __trel8tGP70 __tcol1h6j71 (1 2 3 4 0)) (tycheck y (accept int) __trid0gkS69 __trel8u7x72 __tcol8yVH73 (1 2 3 4 0)) (emit pair2 (0 1) x y)) seq_split_mixed.slog:14 #f)
  class ReadTask38 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_posindex36;  slog::Index** docindex37;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("pair2");
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("pair2");
      head_index[2] = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 0, 2});
      slog::Relation* readrel42 = db->getRelation("$seq_pos");
      driver_index = readrel42->getIndex(ord41, true);
      std::vector<u16> ord43({0, 1, 2});
      slog::Relation* readrel44 = db->getRelation("$seq_pos");
      $seq_posindex36 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({0});
      slog::Relation* readrel46 = db->getRelation("doc");
      docindex37 = readrel46->getIndex(ord45, false);
  
    }
    ReadTask38(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_constd4735e3a265e16eee03f5971;
      u64 v_c55 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c56 = v_const5feceb66ffc86f38d952786c;
      u64 v_c57 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const52b66dd2767dc28cbbeacdde;
      u64 v_c61 = v_const894a226afe261ec8f66c9d49;
      u64 v_c62 = v_const5feceb66ffc86f38d952786c;
      u64 v_c63 = v_const894a226afe261ec8f66c9d49;
      u64 v_c64 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c55, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m47) {
        u64 v_c65 = m47[1];
        u64 v_c66 = m47[2];
        if (buckethash(v_c65) != bucket) return;
        slog::join_probe<3,2>($seq_posindex36, std::array<u64,3>{v_c65, v_c57, 0}, [&](const std::array<u64,3>& m48) {
          u64 v_c67 = m48[2];
          slog::join_all<1>(docindex37, [&](const std::array<u64,1>& m49) {
            u64 v_c27 = m49[0];
            bool ok50 = true;
            u64 v_c68 = _prim_aslst(db, v_c27, &ok50);
            if (!ok50) return;
            if (v_c65 != v_c68) return;
            u64 v_c69 = _prim_llen(db, v_c65);
            if (v_c69 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:14"); return; }
            u64 v_c70 = _prim_ge(db, v_c69, v_c54);
            if (v_c70 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:14"); return; }
            if (!v_c70) return;
            u64 v_c71 = _prim__0002b(db, v_c66, v_c55);
            if (v_c71 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:14"); return; }
            u64 v_c72 = _prim_le(db, v_c71, v_c67);
            if (v_c72 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:14"); return; }
            if (!v_c72) return;
            u64 v_c73 = _prim__0002b(db, v_c67, v_c57);
            if (v_c73 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:14"); return; }
            u64 v_c74 = _prim__0002d(db, v_c69, v_c59);
            if (v_c74 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:14"); return; }
            u64 v_c75 = _prim_le(db, v_c73, v_c74);
            if (v_c75 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:14"); return; }
            if (!v_c75) return;
            u64 v_c76 = _prim__0002b(db, v_c66, v_c56);
            if (v_c76 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:14"); return; }
            bool ok54 = true;
            u64 v_c77 = _prim_lref(db, v_c65, v_c76, &ok54);
            if (!ok54) return;
            u64 v_c78 = _prim__0002b(db, v_c67, v_c58);
            if (v_c78 == slog_error) { slog::emit_pending_error(db, "seq_split_mixed.slog:14"); return; }
            bool ok55 = true;
            u64 v_c79 = _prim_lref(db, v_c65, v_c78, &ok55);
            if (!ok55) return;
            ++_fires;
            if (!(is_int(v_c77)))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c60, v_c61, v_c62, v_c77}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!(is_int(v_c79)))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c60, v_c63, v_c64, v_c79}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c77, v_c79}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("seq_split_mixed.slog:14", "all:$seq_pos", _fires);
  
      if (!_done)
      {
        ReadTask38* _cont = new ReadTask38(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask38(db,b), true);
  // (crule (pre) (scan type_mismatch __erre7SW1317 __errf7vpn318 __errf2dLz319 __errf183T320 __errf1bw7321) (body) (head (emit error (0) __erre7SW1317)) <internal>:1 #f)
  class ReadTask56 : public slog::Task
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
      std::vector<u16> ord57({0});
      slog::Relation* readrel58 = db->getRelation("error");
      head_index[0] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c80 = _t[0];
        u64 v_c81 = _t[1];
        u64 v_c82 = _t[2];
        u64 v_c83 = _t[3];
        u64 v_c84 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c80}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask56* _cont = new ReadTask56(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask56(db,b), false);
  // (crule (pre) (scan nan_result __erre7uND310 __errf0DIY311 __errf32zr312 __errf0bUH313) (body) (head (emit error (0) __erre7uND310)) <internal>:1 #f)
  class ReadTask59 : public slog::Task
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
      std::vector<u16> ord60({0});
      slog::Relation* readrel61 = db->getRelation("error");
      head_index[0] = readrel61->getIndex(ord60, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask59(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c85 = _t[0];
        u64 v_c86 = _t[1];
        u64 v_c87 = _t[2];
        u64 v_c88 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c85}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask59* _cont = new ReadTask59(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask59(db,b), false);
  // (crule (pre) (scan int_overflow __erre7YsO306 __errf9h0i307 __errf4Wnr308 __errf7Y8x309) (body) (head (emit error (0) __erre7YsO306)) <internal>:1 #f)
  class ReadTask62 : public slog::Task
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
      std::vector<u16> ord63({0});
      slog::Relation* readrel64 = db->getRelation("error");
      head_index[0] = readrel64->getIndex(ord63, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask62(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c89 = _t[0];
        u64 v_c90 = _t[1];
        u64 v_c91 = _t[2];
        u64 v_c92 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c89}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask62* _cont = new ReadTask62(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask62(db,b), false);
  s->addReadRel("$seq_at");
  s->addReadRel("$seq_pos");
  s->addReadRel("div_by_zero");
  s->addReadRel("doc");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("afterx");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("pair2");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

