
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constac8d8342bbb2362d13f0a559;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("7e0478df");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constac8d8342bbb2362d13f0a559 = db->encodeString("a");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord134({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord135({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("tok2");
  if (r == 0) db->addRelation("tok2", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tok2");
      std::vector<u16> ord136({0, 1});
    
    r->addIndex<2>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("tok2"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord137({1, 2, 0});
    
    r->addIndex<3>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord138({0, 1, 2});
    
    r->addIndex<3>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp9YoI86");
  if (r == 0) db->addTempRelation("temp9YoI86", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp33lJ87");
  if (r == 0) db->addTempRelation("temp33lJ87", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord139({1, 2, 0});
    
    r->addIndex<3>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord140({0, 1, 2});
    
    r->addIndex<3>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("parse2_ans");
  if (r == 0) db->addRelation("parse2_ans", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("parse2_ans");
      std::vector<u16> ord141({0, 1, 2});
    
    r->addIndex<3>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord142({1, 0, 2});
    
    r->addIndex<3>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), false);
      std::vector<u16> ord143({0, 1, 2});
    
    r->addIndex<3>(ord143, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("parse2_ans"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("parse2");
  if (r == 0) db->addStruct("parse2", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("parse2");
      std::vector<u16> ord144({1, 0});
    
    r->addIndex<2>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord145({0, 1});
    
    r->addIndex<2>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord146({0, 1});
    
    r->addIndex<2>(ord146, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord147({1, 0});
    
    r->addIndex<2>(ord147, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("parse2"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("node");
  if (r == 0) db->addStruct("node", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("node");
      std::vector<u16> ord148({1, 2, 0});
    
    r->addIndex<3>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord149({0, 1, 2});
    
    r->addIndex<3>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("node"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord150({1, 2, 3, 0});
    
    r->addIndex<4>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord151({0, 1, 2, 3});
    
    r->addIndex<4>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord152({1, 2, 0});
    
    r->addIndex<3>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord153({0, 1, 2});
    
    r->addIndex<3>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord154({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord155({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord156({1, 2, 0});
    
    r->addIndex<3>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord157({0, 1, 2});
    
    r->addIndex<3>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord158({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord159({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("leaf");
  if (r == 0) db->addStruct("leaf", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leaf");
      std::vector<u16> ord160({1, 0});
    
    r->addIndex<2>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord161({0, 1});
    
    r->addIndex<2>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("leaf"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord162({1, 2, 3, 0});
    
    r->addIndex<4>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord163({0, 1, 2, 3});
    
    r->addIndex<4>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("full");
  if (r == 0) db->addRelation("full", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("full");
      std::vector<u16> ord164({0});
    
    r->addIndex<1>(ord164, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("full"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord165({0});
    
    r->addIndex<1>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord166({1, 2, 0});
    
    r->addIndex<3>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord167({0, 1, 2});
    
    r->addIndex<3>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord168({1, 0});
    
    r->addIndex<2>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord169({0, 1});
    
    r->addIndex<2>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre) (scan mpz_overflow __erre9fuo78 __errf9jut79 __errf4lXq80 __errf1Dj881 __errf412C82) (body) (head (emit error (0) __erre9fuo78)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre) (scan type_mismatch __erre8lu773 __errf3qUb74 __errf72Yh75 __errf1L7876 __errf5gfN77) (body) (head (emit error (0) __erre8lu773)) <internal>:1 #f)
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
      outer_rel = db->getRelation("type_mismatch");
  
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
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
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
  // (crule (pre) (scan mpz_table_overflow __erre3piB83 __errf9rfD84 __errf0a4r85) (body) (head (emit error (0) __erre3piB83)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_table_overflow");
  
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
        u64 v_c10 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c10}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre (let __tconst1BcQ22 const5feceb66ffc86f38d952786c)) (once) (body) (head (mkstruct parse2 (1 0) __8I9A23 __tconst1BcQ22)) dem_sppf.slog:17 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse2");
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:17", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), true);
  // (crule (pre) (scan parse2_ans __t2oFr21 j t1) (body (join-old parse2 (0 1) 1 (0 1) __t2oFr21 i)) (head (mkstruct parse2 (1 0) __41EY25 j)) dem_sppf.slog:15 #f)
  class ReadTask12 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** parse2index10;  slog::Index** parse2delta11;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse2");
      outer_rel = db->getRelation("parse2_ans");
      std::vector<u16> ord13({0, 1});
      slog::Relation* readrel14 = db->getRelation("parse2");
      parse2index10 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("parse2");
      parse2delta11 = readrel16->getIndex(ord15, true);
  
    }
    ReadTask12(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c16 = _t[2];
        slog::join_probe_old<2,1>(parse2index10, parse2delta11, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m17) {
          u64 v_c17 = m17[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c15}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:15", "delta:parse2_ans", _fires);
  
      if (!_done)
      {
        ReadTask12* _cont = new ReadTask12(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask12(db,b), false);
  // (crule (pre) (scan toint_range __erre877U70 __errf64bw71 __errf4wIp72) (body) (head (emit error (0) __erre877U70)) <internal>:1 #f)
  class ReadTask18 : public slog::Task
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
      std::vector<u16> ord19({0});
      slog::Relation* readrel20 = db->getRelation("error");
      head_index[0] = readrel20->getIndex(ord19, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c20 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask18* _cont = new ReadTask18(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask18(db,b), false);
  // (crule (pre) (scan parse2 __t30Sa10 j) (body (exists parse2_ans (0 1 2) 1 __t30Sa10) (join parse2_ans (1 0 2) 1 j __t4aSm9 t1) (join parse2 (0 1) 1 __t4aSm9 i) (join parse2_ans (0 1 2) 1 __t30Sa10 k t2)) (head (emit-temp temp33lJ87 __t4aSm9 k t1 t2) (mkstruct node (1 2 0) __t3qk27 t1 t2)) dem_sppf.slog:15 #f)
  class ReadTask25 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** parse2_ansindex21;  slog::Index** parse2_ansindex22;  slog::Index** parse2index23;  slog::Index** parse2_ansindex24;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp33lJ87");
      head_rel[1] = db->getRelation("node");
      outer_rel = db->getRelation("parse2");
      std::vector<u16> ord26({0, 1, 2});
      slog::Relation* readrel27 = db->getRelation("parse2_ans");
      parse2_ansindex21 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 0, 2});
      slog::Relation* readrel29 = db->getRelation("parse2_ans");
      parse2_ansindex22 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1});
      slog::Relation* readrel31 = db->getRelation("parse2");
      parse2index23 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1, 2});
      slog::Relation* readrel33 = db->getRelation("parse2_ans");
      parse2_ansindex24 = readrel33->getIndex(ord32, false);
  
    }
    ReadTask25(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[0];
        u64 v_c15 = _t[1];
        if (!slog::exists_probe<3,1>(parse2_ansindex21, std::array<u64,3>{v_c21, 0, 0})) return;
        slog::join_probe<3,1>(parse2_ansindex22, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m34) {
          u64 v_c22 = m34[1]; u64 v_c16 = m34[2];
          slog::join_probe<2,1>(parse2index23, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m35) {
            u64 v_c17 = m35[1];
            slog::join_probe<3,1>(parse2_ansindex24, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m36) {
              u64 v_c23 = m36[1]; u64 v_c24 = m36[2];
              ++_fires;
              slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c22, v_c23, v_c16, v_c24});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c16, v_c24}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:15", "delta:parse2", _fires);
  
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
  // (crule (pre (let __tconst3R5O19 const5feceb66ffc86f38d952786c)) (once) (body) (head (mkstruct parse2 (1 0) __7fhu24 __tconst3R5O19)) dem_sppf.slog:19 #f)
  class ReadTask37 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse2");
  
    }
    ReadTask37(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c25}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:19", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask37(db,b), true);
  // (crule (pre) (scan parse2 __t2oFr21 i) (body (join parse2_ans (0 1 2) 1 __t2oFr21 j t1)) (head (mkstruct parse2 (1 0) __41EY25 j)) dem_sppf.slog:15 #f)
  class ReadTask39 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** parse2_ansindex38;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse2");
      outer_rel = db->getRelation("parse2");
      std::vector<u16> ord40({0, 1, 2});
      slog::Relation* readrel41 = db->getRelation("parse2_ans");
      parse2_ansindex38 = readrel41->getIndex(ord40, false);
  
    }
    ReadTask39(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[0];
        u64 v_c17 = _t[1];
        slog::join_probe<3,1>(parse2_ansindex38, std::array<u64,3>{v_c14, 0, 0}, [&](const std::array<u64,3>& m42) {
          u64 v_c15 = m42[1]; u64 v_c16 = m42[2];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c15}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:15", "delta:parse2", _fires);
  
      if (!_done)
      {
        ReadTask39* _cont = new ReadTask39(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask39(db,b), false);
  // (crule (pre) (scan temp9YoI86 __t22gO14 __t70jx13 i) (body (join leaf (1 0) 1 i __t9feN11)) (head (emit parse2_ans (0 1 2) __t22gO14 __t70jx13 __t9feN11)) dem_sppf.slog:14 #f)
  class ReadTask44 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** leafindex43;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse2_ans");
      std::vector<u16> ord45({0, 1, 2});
      slog::Relation* readrel46 = db->getRelation("parse2_ans");
      head_index[0] = readrel46->getIndex(ord45, false);
      outer_rel = db->getRelation("temp9YoI86");
      std::vector<u16> ord47({1, 0});
      slog::Relation* readrel48 = db->getRelation("leaf");
      leafindex43 = readrel48->getIndex(ord47, false);
  
    }
    ReadTask44(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe<2,1>(leafindex43, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m49) {
          u64 v_c28 = m49[1];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c26, v_c27, v_c28}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:14", "delta:temp9YoI86", _fires);
  
      if (!_done)
      {
        ReadTask44* _cont = new ReadTask44(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask44(db,b), false);
  // (crule (pre) (scan parse2_ans __t30Sa10 k t2) (body (join-old parse2 (0 1) 1 (0 1) __t30Sa10 j) (join parse2_ans (1 0 2) 1 j __t4aSm9 t1) (join-old parse2 (0 1) 1 (0 1) __t4aSm9 i)) (head (emit-temp temp33lJ87 __t4aSm9 k t1 t2) (mkstruct node (1 2 0) __t3qk27 t1 t2)) dem_sppf.slog:15 #f)
  class ReadTask55 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** parse2index50;  slog::Index** parse2_ansindex51;  slog::Index** parse2index52;  slog::Index** parse2delta53;  slog::Index** parse2delta54;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp33lJ87");
      head_rel[1] = db->getRelation("node");
      outer_rel = db->getRelation("parse2_ans");
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("parse2");
      parse2index50 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({0, 1});
      slog::Relation* readrel59 = db->getRelation("parse2");
      parse2delta53 = readrel59->getIndex(ord58, true);
      std::vector<u16> ord60({1, 0, 2});
      slog::Relation* readrel61 = db->getRelation("parse2_ans");
      parse2_ansindex51 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("parse2");
      parse2index52 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({0, 1});
      slog::Relation* readrel65 = db->getRelation("parse2");
      parse2delta54 = readrel65->getIndex(ord64, true);
  
    }
    ReadTask55(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        slog::join_probe_old<2,1>(parse2index50, parse2delta53, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m66) {
          u64 v_c15 = m66[1];
          slog::join_probe<3,1>(parse2_ansindex51, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m67) {
            u64 v_c22 = m67[1]; u64 v_c16 = m67[2];
            slog::join_probe_old<2,1>(parse2index52, parse2delta54, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m68) {
              u64 v_c17 = m68[1];
              ++_fires;
              slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c22, v_c23, v_c16, v_c24});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c16, v_c24}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:15", "delta:parse2_ans", _fires);
  
      if (!_done)
      {
        ReadTask55* _cont = new ReadTask55(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask55(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre2xMb59 __errf04Qp60 __errf796j61) (body) (head (emit error (0) __erre2xMb59)) <internal>:1 #f)
  class ReadTask69 : public slog::Task
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
      std::vector<u16> ord70({0});
      slog::Relation* readrel71 = db->getRelation("error");
      head_index[0] = readrel71->getIndex(ord70, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
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
        u64 v_c29 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c31 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c29}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
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
  // (crule (pre (let __tconst00N515 constac8d8342bbb2362d13f0a559) (let __tconst4ibr12 const6b86b273ff34fce19d6b804e)) (scan parse2 __t22gO14 i) (body (join tok2 (0 1) 2 i __tconst00N515) (let __t70jx13 (_0002b i __tconst4ibr12))) (head (emit-temp temp9YoI86 __t22gO14 __t70jx13 i) (mkstruct leaf (1 0) __t9feN11 i)) dem_sppf.slog:14 #f)
  class ReadTask73 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tok2index72;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9YoI86");
      head_rel[1] = db->getRelation("leaf");
      outer_rel = db->getRelation("parse2");
      std::vector<u16> ord74({0, 1});
      slog::Relation* readrel75 = db->getRelation("tok2");
      tok2index72 = readrel75->getIndex(ord74, false);
  
    }
    ReadTask73(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c32 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c33 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c26 = _t[0];
        u64 v_c17 = _t[1];
        slog::join_probe<2,2>(tok2index72, std::array<u64,2>{v_c17, v_c32}, [&](const std::array<u64,2>& m76) {
          u64 v_c27 = _prim__0002b(db, v_c17, v_c33);
          if (v_c27 == slog_error) { slog::emit_pending_error(db, "dem_sppf.slog:14"); return; }
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c26, v_c27, v_c17});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:14", "delta:parse2", _fires);
  
      if (!_done)
      {
        ReadTask73* _cont = new ReadTask73(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask73(db,b), false);
  // (crule (pre) (scan int_overflow __erre6w3U62 __errf7NDc63 __errf9WTE64 __errf2r9q65) (body) (head (emit error (0) __erre6w3U62)) <internal>:1 #f)
  class ReadTask77 : public slog::Task
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
      std::vector<u16> ord78({0});
      slog::Relation* readrel79 = db->getRelation("error");
      head_index[0] = readrel79->getIndex(ord78, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask77(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c34 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c37 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c34}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask77* _cont = new ReadTask77(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask77(db,b), false);
  // (crule (pre) (scan temp33lJ87 __t4aSm9 k t1 t2) (body (join node (1 2 0) 2 t1 t2 __t3qk27)) (head (emit parse2_ans (0 1 2) __t4aSm9 k __t3qk27)) dem_sppf.slog:15 #f)
  class ReadTask81 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nodeindex80;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse2_ans");
      std::vector<u16> ord82({0, 1, 2});
      slog::Relation* readrel83 = db->getRelation("parse2_ans");
      head_index[0] = readrel83->getIndex(ord82, false);
      outer_rel = db->getRelation("temp33lJ87");
      std::vector<u16> ord84({1, 2, 0});
      slog::Relation* readrel85 = db->getRelation("node");
      nodeindex80 = readrel85->getIndex(ord84, false);
  
    }
    ReadTask81(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c16 = _t[2];
        u64 v_c24 = _t[3];
        slog::join_probe<3,2>(nodeindex80, std::array<u64,3>{v_c16, v_c24, 0}, [&](const std::array<u64,3>& m86) {
          u64 v_c38 = m86[2];
          ++_fires;
          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c22, v_c23, v_c38}, std::array<u16,3>{0, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:15", "delta:temp33lJ87", _fires);
  
      if (!_done)
      {
        ReadTask81* _cont = new ReadTask81(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask81(db,b), false);
  // (crule (pre) (scan div_by_zero __erre8DSP56 __errf4TML57 __errf8F2D58) (body) (head (emit error (0) __erre8DSP56)) <internal>:1 #f)
  class ReadTask87 : public slog::Task
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
      std::vector<u16> ord88({0});
      slog::Relation* readrel89 = db->getRelation("error");
      head_index[0] = readrel89->getIndex(ord88, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask87(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c41 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c39}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask87* _cont = new ReadTask87(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask87(db,b), false);
  // (crule (pre) (scan parse2 __t4aSm9 i) (body (join parse2_ans (0 1 2) 1 __t4aSm9 j t1) (join-old parse2 (1 0) 1 (1 0) j __t30Sa10) (join parse2_ans (0 1 2) 1 __t30Sa10 k t2)) (head (emit-temp temp33lJ87 __t4aSm9 k t1 t2) (mkstruct node (1 2 0) __t3qk27 t1 t2)) dem_sppf.slog:15 #f)
  class ReadTask94 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** parse2_ansindex90;  slog::Index** parse2index91;  slog::Index** parse2_ansindex92;  slog::Index** parse2delta93;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp33lJ87");
      head_rel[1] = db->getRelation("node");
      outer_rel = db->getRelation("parse2");
      std::vector<u16> ord95({0, 1, 2});
      slog::Relation* readrel96 = db->getRelation("parse2_ans");
      parse2_ansindex90 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 0});
      slog::Relation* readrel98 = db->getRelation("parse2");
      parse2index91 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 0});
      slog::Relation* readrel100 = db->getRelation("parse2");
      parse2delta93 = readrel100->getIndex(ord99, true);
      std::vector<u16> ord101({0, 1, 2});
      slog::Relation* readrel102 = db->getRelation("parse2_ans");
      parse2_ansindex92 = readrel102->getIndex(ord101, false);
  
    }
    ReadTask94(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[0];
        u64 v_c17 = _t[1];
        slog::join_probe<3,1>(parse2_ansindex90, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m103) {
          u64 v_c15 = m103[1]; u64 v_c16 = m103[2];
          slog::join_probe_old<2,1>(parse2index91, parse2delta93, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m104) {
            u64 v_c21 = m104[1];
            slog::join_probe<3,1>(parse2_ansindex92, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m105) {
              u64 v_c23 = m105[1]; u64 v_c24 = m105[2];
              ++_fires;
              slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c22, v_c23, v_c16, v_c24});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c16, v_c24}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:15", "delta:parse2", _fires);
  
      if (!_done)
      {
        ReadTask94* _cont = new ReadTask94(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask94(db,b), false);
  // (crule (pre) (scan parse2_ans __t4aSm9 j t1) (body (exists parse2 (1 0) 1 j) (join-old parse2 (0 1) 1 (0 1) __t4aSm9 i) (join-old parse2 (1 0) 1 (1 0) j __t30Sa10) (join-old parse2_ans (0 1 2) 1 (0 1 2) __t30Sa10 k t2)) (head (emit-temp temp33lJ87 __t4aSm9 k t1 t2) (mkstruct node (1 2 0) __t3qk27 t1 t2)) dem_sppf.slog:15 #f)
  class ReadTask113 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** parse2index106;  slog::Index** parse2index107;  slog::Index** parse2index108;  slog::Index** parse2_ansindex109;  slog::Index** parse2delta110;  slog::Index** parse2delta111;  slog::Index** parse2_ansdelta112;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp33lJ87");
      head_rel[1] = db->getRelation("node");
      outer_rel = db->getRelation("parse2_ans");
      std::vector<u16> ord114({1, 0});
      slog::Relation* readrel115 = db->getRelation("parse2");
      parse2index106 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({0, 1});
      slog::Relation* readrel117 = db->getRelation("parse2");
      parse2index107 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({0, 1});
      slog::Relation* readrel119 = db->getRelation("parse2");
      parse2delta110 = readrel119->getIndex(ord118, true);
      std::vector<u16> ord120({1, 0});
      slog::Relation* readrel121 = db->getRelation("parse2");
      parse2index108 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 0});
      slog::Relation* readrel123 = db->getRelation("parse2");
      parse2delta111 = readrel123->getIndex(ord122, true);
      std::vector<u16> ord124({0, 1, 2});
      slog::Relation* readrel125 = db->getRelation("parse2_ans");
      parse2_ansindex109 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({0, 1, 2});
      slog::Relation* readrel127 = db->getRelation("parse2_ans");
      parse2_ansdelta112 = readrel127->getIndex(ord126, true);
  
    }
    ReadTask113(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c16 = _t[2];
        if (!slog::exists_probe<2,1>(parse2index106, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe_old<2,1>(parse2index107, parse2delta110, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m128) {
          u64 v_c17 = m128[1];
          slog::join_probe_old<2,1>(parse2index108, parse2delta111, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m129) {
            u64 v_c21 = m129[1];
            slog::join_probe_old<3,1>(parse2_ansindex109, parse2_ansdelta112, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m130) {
              u64 v_c23 = m130[1]; u64 v_c24 = m130[2];
              ++_fires;
              slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c22, v_c23, v_c16, v_c24});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c16, v_c24}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_sppf.slog:15", "delta:parse2_ans", _fires);
  
      if (!_done)
      {
        ReadTask113* _cont = new ReadTask113(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask113(db,b), false);
  // (crule (pre) (scan nan_result __erre6c3T66 __errf30fa67 __errf7nfM68 __errf6jZA69) (body) (head (emit error (0) __erre6c3T66)) <internal>:1 #f)
  class ReadTask131 : public slog::Task
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
      std::vector<u16> ord132({0});
      slog::Relation* readrel133 = db->getRelation("error");
      head_index[0] = readrel133->getIndex(ord132, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask131(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c42 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c44 = _t[2];
        u64 v_c45 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c42}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask131* _cont = new ReadTask131(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask131(db,b), false);
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("leaf");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("node");
  s->addReadRel("parse2");
  s->addReadRel("parse2_ans");
  s->addReadRel("temp33lJ87");
  s->addReadRel("temp9YoI86");
  s->addReadRel("toint_range");
  s->addReadRel("tok2");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("leaf");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("node");
  s->addDynamicRel("parse2");
  s->addDynamicRel("parse2_ans");
  s->addDynamicRel("temp33lJ87");
  s->addDynamicRel("temp9YoI86");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("parse2_ans");
  d->push(s);
  d->continueRun();
}

