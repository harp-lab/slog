
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constd703a74a3d00a0728a67422c;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const81744fc1e95f3b4f2a49b26c;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("e86f0055");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constd703a74a3d00a0728a67422c = db->encodeString("dem_ack.slog:9");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const81744fc1e95f3b4f2a49b26c = db->encodeString("ack");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord372({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord372, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord373({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord373, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord374({1, 2, 0});
    
    r->addIndex<3>(ord374, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord375({0, 1, 2});
    
    r->addIndex<3>(ord375, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp78Qw134");
  if (r == 0) db->addTempRelation("temp78Qw134", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6q9K133");
  if (r == 0) db->addTempRelation("temp6q9K133", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6exO140");
  if (r == 0) db->addTempRelation("temp6exO140", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3Qoo132");
  if (r == 0) db->addTempRelation("temp3Qoo132", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord376({1, 2, 0});
    
    r->addIndex<3>(ord376, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord377({0, 1, 2});
    
    r->addIndex<3>(ord377, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("res");
  if (r == 0) db->addRelation("res", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("res");
      std::vector<u16> ord378({0, 1, 2});
    
    r->addIndex<3>(ord378, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("res"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord379({1, 2, 3, 0});
    
    r->addIndex<4>(ord379, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord380({0, 1, 2, 3});
    
    r->addIndex<4>(ord380, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord381({1, 2, 0});
    
    r->addIndex<3>(ord381, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord382({0, 1, 2});
    
    r->addIndex<3>(ord382, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord383({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord383, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord384({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord384, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord385({1, 2, 0});
    
    r->addIndex<3>(ord385, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord386({0, 1, 2});
    
    r->addIndex<3>(ord386, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord387({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord387, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord388({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord388, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord389({1, 2, 3, 0});
    
    r->addIndex<4>(ord389, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord390({0, 1, 2, 3});
    
    r->addIndex<4>(ord390, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord391({0});
    
    r->addIndex<1>(ord391, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord392({1, 2, 0});
    
    r->addIndex<3>(ord392, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord393({0, 1, 2});
    
    r->addIndex<3>(ord393, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ack_ans");
  if (r == 0) db->addRelation("ack_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ack_ans");
      std::vector<u16> ord394({0, 1});
    
    r->addIndex<2>(ord394, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord395({1, 0});
    
    r->addIndex<2>(ord395, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord396({0, 1});
    
    r->addIndex<2>(ord396, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("ack_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("ack");
  if (r == 0) db->addStruct("ack", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ack");
      std::vector<u16> ord397({1, 2, 0});
    
    r->addIndex<3>(ord397, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord398({0, 2, 1});
    
    r->addIndex<3>(ord398, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord399({2, 0, 1});
    
    r->addIndex<3>(ord399, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord400({0, 2, 1});
    
    r->addIndex<3>(ord400, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
      std::vector<u16> ord401({1, 2, 0});
    
    r->addIndex<3>(ord401, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord402({2, 0, 1});
    
    r->addIndex<3>(ord402, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("ack"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord403({1, 0});
    
    r->addIndex<2>(ord403, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord404({0, 1});
    
    r->addIndex<2>(ord404, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup35494x8x0x0x1");
  if (r == 0) db->addRelation("$sup35494x8x0x0x1", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup35494x8x0x0x1");
      std::vector<u16> ord405({2, 1, 0, 3, 4});
    
    r->addIndex<5>(ord405, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 1, 0, 3, 4}, false, b), true);
      std::vector<u16> ord406({0, 3, 4, 1, 2});
    
    r->addIndex<5>(ord406, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 3, 4, 1, 2}, false, b), false);
      std::vector<u16> ord407({1, 3, 0, 2, 4});
    
    r->addIndex<5>(ord407, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 3, 0, 2, 4}, false, b), false);
      std::vector<u16> ord408({2, 1, 0, 3, 4});
    
    r->addIndex<5>(ord408, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 1, 0, 3, 4}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup35494x8x0x0x1"), std::array<u16,5>{2, 1, 0, 3, 4}, b));
  // (crule (pre) (scan mpz_overflow __erre0QnA124 __errf9vDP125 __errf8e2l126 __errf1Wxv127 __errf170E128) (body) (head (emit error (0) __erre0QnA124)) <internal>:1 #f)
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
  // (crule (pre) (scan temp3Qoo132 __t0to322 __t3l0U24) (body) (head (emit ack_ans (0 1) __t3l0U24 __t0to322)) dem_ack.slog:7 #f)
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
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord4({0, 1});
      slog::Relation* readrel5 = db->getRelation("ack_ans");
      head_index[0] = readrel5->getIndex(ord4, false);
      outer_rel = db->getRelation("temp3Qoo132");
  
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
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c5}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:7", "delta:temp3Qoo132", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre0lDV108 __errf8Z7t109 __errf4EWq110 __errf7uJF111) (body) (head (emit error (0) __erre0lDV108)) <internal>:1 #f)
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
      outer_rel = db->getRelation("int_overflow");
  
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
        u64 v_c7 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
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
  // (crule (pre (let __tconst9nO523 const5feceb66ffc86f38d952786c) (let __tconst9rsq21 const6b86b273ff34fce19d6b804e)) (probe ack (1 2 0) 1 __tconst9nO523 n __t3l0U24) (body (let __t0to322 (_0002b n __tconst9rsq21))) (head (emit-temp temp3Qoo132 __t0to322 __t3l0U24)) dem_ack.slog:7 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Qoo132");
      std::vector<u16> ord10({1, 2, 0});
      slog::Relation* readrel11 = db->getRelation("ack");
      driver_index = readrel11->getIndex(ord10, true);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
      u64 v_c12 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c11, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m12) {
        u64 v_c13 = m12[1];
        u64 v_c6 = m12[2];
        if (buckethash(v_c13) != bucket) return;
        u64 v_c5 = _prim__0002b(db, v_c13, v_c12);
        if (v_c5 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:7"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c6});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:7", "delta:ack", _fires);
  
      if (!_done)
      {
        ReadTask9* _cont = new ReadTask9(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), false);
  // (crule (pre (let __tconst36yH50 const5feceb66ffc86f38d952786c) (let __tconst5uQR51 const6b86b273ff34fce19d6b804e)) (scan ack __t1Esa48 m n) (body (cmp lt __tconst36yH50 m) (cmp lt __tconst36yH50 n) (let __t3uJU52 (_0002d n __tconst5uQR51)) (join-old ack (1 2 0) 2 (1 2 0) m __t3uJU52 __t85f553) (join ack_ans (0 1) 1 __t85f553 __v0)) (head (emit $sup35494x8x0x0x1 (2 1 0 3 4) __v0 __t85f553 __t1Esa48 m n)) dem_ack.slog:9 #f)
  class ReadTask16 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ackindex13;  slog::Index** ack_ansindex14;  slog::Index** ackdelta15;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup35494x8x0x0x1");
      std::vector<u16> ord17({2, 1, 0, 3, 4});
      slog::Relation* readrel18 = db->getRelation("$sup35494x8x0x0x1");
      head_index[0] = readrel18->getIndex(ord17, false);
      outer_rel = db->getRelation("ack");
      std::vector<u16> ord19({1, 2, 0});
      slog::Relation* readrel20 = db->getRelation("ack");
      ackindex13 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 2, 0});
      slog::Relation* readrel22 = db->getRelation("ack");
      ackdelta15 = readrel22->getIndex(ord21, true);
      std::vector<u16> ord23({0, 1});
      slog::Relation* readrel24 = db->getRelation("ack_ans");
      ack_ansindex14 = readrel24->getIndex(ord23, false);
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_const5feceb66ffc86f38d952786c;
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c16 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c18 = _prim_lt(db, v_c14, v_c17);
        if (v_c18 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c18) return;
        u64 v_c19 = _prim_lt(db, v_c14, v_c13);
        if (v_c19 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c19) return;
        u64 v_c20 = _prim__0002d(db, v_c13, v_c15);
        if (v_c20 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        slog::join_probe_old<3,2>(ackindex13, ackdelta15, std::array<u64,3>{v_c17, v_c20, 0}, [&](const std::array<u64,3>& m27) {
          u64 v_c21 = m27[2];
          slog::join_probe<2,1>(ack_ansindex14, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m28) {
            u64 v_c22 = m28[1];
            ++_fires;
            slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c22, v_c21, v_c16, v_c17, v_c13}, std::array<u16,5>{2, 1, 0, 3, 4});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:ack", _fires);
  
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
  // (crule (pre) (scan mpz_table_overflow __erre6Z2y129 __errf0Z8b130 __errf9Uhv131) (body) (head (emit error (0) __erre6Z2y129)) <internal>:1 #f)
  class ReadTask29 : public slog::Task
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
      std::vector<u16> ord30({0});
      slog::Relation* readrel31 = db->getRelation("error");
      head_index[0] = readrel31->getIndex(ord30, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask29(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask29* _cont = new ReadTask29(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask29(db,b), false);
  // (crule (pre (let __tconst869H10 const5feceb66ffc86f38d952786c) (let __tconst2eQz12 const6b86b273ff34fce19d6b804e)) (probe ack (2 0 1) 1 __tconst2eQz12 __t5L6U14 __t17vQ13) (body (exists ack (2 0 1) 1 __tconst869H10) (join ack_ans (0 1) 1 __t5L6U14 __v0) (join ack (2 0 1) 1 __tconst869H10 __t8RII9 m) (cmp lt __tconst869H10 m) (let chk1Oxu142 (_0002d m __tconst2eQz12)) (eq __t17vQ13 chk1Oxu142)) (head (emit ack_ans (0 1) __t8RII9 __v0)) dem_ack.slog:8 #f)
  class ReadTask35 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** ackindex32;  slog::Index** ack_ansindex33;  slog::Index** ackindex34;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord36({0, 1});
      slog::Relation* readrel37 = db->getRelation("ack_ans");
      head_index[0] = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({2, 0, 1});
      slog::Relation* readrel39 = db->getRelation("ack");
      driver_index = readrel39->getIndex(ord38, true);
      std::vector<u16> ord40({2, 0, 1});
      slog::Relation* readrel41 = db->getRelation("ack");
      ackindex32 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({0, 1});
      slog::Relation* readrel43 = db->getRelation("ack_ans");
      ack_ansindex33 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({2, 0, 1});
      slog::Relation* readrel45 = db->getRelation("ack");
      ackindex34 = readrel45->getIndex(ord44, false);
  
    }
    ReadTask35(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c27, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m46) {
        u64 v_c28 = m46[1];
        u64 v_c29 = m46[2];
        if (buckethash(v_c28) != bucket) return;
        if (!slog::exists_probe<3,1>(ackindex32, std::array<u64,3>{v_c26, 0, 0})) return;
        slog::join_probe<2,1>(ack_ansindex33, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m47) {
          u64 v_c22 = m47[1];
          slog::join_probe<3,1>(ackindex34, std::array<u64,3>{v_c26, 0, 0}, [&](const std::array<u64,3>& m48) {
            u64 v_c30 = m48[1]; u64 v_c17 = m48[2];
            u64 v_c31 = _prim_lt(db, v_c26, v_c17);
            if (v_c31 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:8"); return; }
            if (!v_c31) return;
            u64 v_c32 = _prim__0002d(db, v_c17, v_c27);
            if (v_c32 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:8"); return; }
            if (v_c29 != v_c32) return;
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c30, v_c22}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:8", "delta:ack", _fires);
  
      if (!_done)
      {
        ReadTask35* _cont = new ReadTask35(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask35(db,b), false);
  // (crule (pre (let __tconst36yH50 const5feceb66ffc86f38d952786c) (let __tconst5uQR51 const6b86b273ff34fce19d6b804e)) (scan ack_ans __t85f553 __v0) (body (join-old ack (0 2 1) 1 (0 2 1) __t85f553 __t3uJU52 m) (cmp lt __tconst36yH50 m) (join-old ack (1 2 0) 1 (1 2 0) m n __t1Esa48) (cmp lt __tconst36yH50 n) (let chk591o135 (_0002d n __tconst5uQR51)) (eq __t3uJU52 chk591o135)) (head (emit $sup35494x8x0x0x1 (2 1 0 3 4) __v0 __t85f553 __t1Esa48 m n)) dem_ack.slog:9 #f)
  class ReadTask54 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ackindex50;  slog::Index** ackindex51;  slog::Index** ackdelta52;  slog::Index** ackdelta53;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup35494x8x0x0x1");
      std::vector<u16> ord55({2, 1, 0, 3, 4});
      slog::Relation* readrel56 = db->getRelation("$sup35494x8x0x0x1");
      head_index[0] = readrel56->getIndex(ord55, false);
      outer_rel = db->getRelation("ack_ans");
      std::vector<u16> ord57({0, 2, 1});
      slog::Relation* readrel58 = db->getRelation("ack");
      ackindex50 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({0, 2, 1});
      slog::Relation* readrel60 = db->getRelation("ack");
      ackdelta52 = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("ack");
      ackindex51 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 2, 0});
      slog::Relation* readrel64 = db->getRelation("ack");
      ackdelta53 = readrel64->getIndex(ord63, true);
  
    }
    ReadTask54(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_const5feceb66ffc86f38d952786c;
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_probe_old<3,1>(ackindex50, ackdelta52, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m65) {
          u64 v_c20 = m65[1]; u64 v_c17 = m65[2];
          u64 v_c33 = _prim_lt(db, v_c14, v_c17);
          if (v_c33 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
          if (!v_c33) return;
          slog::join_probe_old<3,1>(ackindex51, ackdelta53, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m67) {
            u64 v_c13 = m67[1]; u64 v_c16 = m67[2];
            u64 v_c34 = _prim_lt(db, v_c14, v_c13);
            if (v_c34 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
            if (!v_c34) return;
            u64 v_c35 = _prim__0002d(db, v_c13, v_c15);
            if (v_c35 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
            if (v_c20 != v_c35) return;
            ++_fires;
            slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c22, v_c21, v_c16, v_c17, v_c13}, std::array<u16,5>{2, 1, 0, 3, 4});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:ack_ans", _fires);
  
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
  // (crule (pre (let __tconst78tO27 const5feceb66ffc86f38d952786c) (let __tconst9sKc31 const6b86b273ff34fce19d6b804e)) (scan ack __t0iBx30 m __t4ow729) (body (cmp lt __tconst78tO27 m) (exists ack (1 2 0) 1 m) (exists ack_ans (0 1) 1 __t0iBx30) (join $sup35494x8x0x0x1 (1 3 0 2 4) 2 __t0iBx30 m __t6ie525 __v0 n) (cmp lt __tconst78tO27 n) (join ack (0 2 1) 3 __t6ie525 n m) (join ack_ans (0 1) 2 __t0iBx30 __v0) (let __t1zrb32 (_0002d m __tconst9sKc31)) (join-old ack (1 2 0) 2 (1 2 0) __t1zrb32 __v0 __t7GoZ33) (join ack_ans (0 1) 1 __t7GoZ33 __v1) (let chk0yX3138 (_0002d n __tconst9sKc31)) (eq __t4ow729 chk0yX3138)) (head (emit ack_ans (0 1) __t6ie525 __v1)) dem_ack.slog:9 #f)
  class ReadTask77 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ackindex69;  slog::Index** ack_ansindex70;  slog::Index** $sup35494x8x0x0x1index71;  slog::Index** ackindex72;  slog::Index** ack_ansindex73;  slog::Index** ackindex74;  slog::Index** ack_ansindex75;  slog::Index** ackdelta76;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("ack_ans");
      head_index[0] = readrel79->getIndex(ord78, false);
      outer_rel = db->getRelation("ack");
      std::vector<u16> ord80({1, 2, 0});
      slog::Relation* readrel81 = db->getRelation("ack");
      ackindex69 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({0, 1});
      slog::Relation* readrel83 = db->getRelation("ack_ans");
      ack_ansindex70 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 3, 0, 2, 4});
      slog::Relation* readrel85 = db->getRelation("$sup35494x8x0x0x1");
      $sup35494x8x0x0x1index71 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({0, 2, 1});
      slog::Relation* readrel87 = db->getRelation("ack");
      ackindex72 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({0, 1});
      slog::Relation* readrel89 = db->getRelation("ack_ans");
      ack_ansindex73 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 2, 0});
      slog::Relation* readrel91 = db->getRelation("ack");
      ackindex74 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 2, 0});
      slog::Relation* readrel93 = db->getRelation("ack");
      ackdelta76 = readrel93->getIndex(ord92, true);
      std::vector<u16> ord94({0, 1});
      slog::Relation* readrel95 = db->getRelation("ack_ans");
      ack_ansindex75 = readrel95->getIndex(ord94, false);
  
    }
    ReadTask77(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const5feceb66ffc86f38d952786c;
      u64 v_c37 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c39 = _t[2];
        u64 v_c40 = _prim_lt(db, v_c36, v_c17);
        if (v_c40 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c40) return;
        if (!slog::exists_probe<3,1>(ackindex69, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<2,1>(ack_ansindex70, std::array<u64,2>{v_c38, 0})) return;
        slog::join_probe<5,2>($sup35494x8x0x0x1index71, std::array<u64,5>{v_c38, v_c17, 0, 0, 0}, [&](const std::array<u64,5>& m97) {
          u64 v_c41 = m97[2]; u64 v_c22 = m97[3]; u64 v_c13 = m97[4];
          u64 v_c42 = _prim_lt(db, v_c36, v_c13);
          if (v_c42 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
          if (!v_c42) return;
          slog::join_probe<3,3>(ackindex72, std::array<u64,3>{v_c41, v_c13, v_c17}, [&](const std::array<u64,3>& m99) {
            slog::join_probe<2,2>(ack_ansindex73, std::array<u64,2>{v_c38, v_c22}, [&](const std::array<u64,2>& m100) {
              u64 v_c43 = _prim__0002d(db, v_c17, v_c37);
              if (v_c43 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
              slog::join_probe_old<3,2>(ackindex74, ackdelta76, std::array<u64,3>{v_c43, v_c22, 0}, [&](const std::array<u64,3>& m101) {
                u64 v_c44 = m101[2];
                slog::join_probe<2,1>(ack_ansindex75, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m102) {
                  u64 v_c45 = m102[1];
                  u64 v_c46 = _prim__0002d(db, v_c13, v_c37);
                  if (v_c46 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
                  if (v_c39 != v_c46) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c45}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:ack", _fires);
  
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
  // (crule (pre (let __tconst36yH50 const5feceb66ffc86f38d952786c) (let __tconst5uQR51 const6b86b273ff34fce19d6b804e)) (scan ack __t85f553 m __t3uJU52) (body (cmp lt __tconst36yH50 m) (exists ack (1 2 0) 1 m) (join ack_ans (0 1) 1 __t85f553 __v0) (join ack (1 2 0) 1 m n __t1Esa48) (cmp lt __tconst36yH50 n) (let chk3wiX136 (_0002d n __tconst5uQR51)) (eq __t3uJU52 chk3wiX136)) (head (emit $sup35494x8x0x0x1 (2 1 0 3 4) __v0 __t85f553 __t1Esa48 m n)) dem_ack.slog:9 #f)
  class ReadTask106 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ackindex103;  slog::Index** ack_ansindex104;  slog::Index** ackindex105;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup35494x8x0x0x1");
      std::vector<u16> ord107({2, 1, 0, 3, 4});
      slog::Relation* readrel108 = db->getRelation("$sup35494x8x0x0x1");
      head_index[0] = readrel108->getIndex(ord107, false);
      outer_rel = db->getRelation("ack");
      std::vector<u16> ord109({1, 2, 0});
      slog::Relation* readrel110 = db->getRelation("ack");
      ackindex103 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 1});
      slog::Relation* readrel112 = db->getRelation("ack_ans");
      ack_ansindex104 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 2, 0});
      slog::Relation* readrel114 = db->getRelation("ack");
      ackindex105 = readrel114->getIndex(ord113, false);
  
    }
    ReadTask106(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_const5feceb66ffc86f38d952786c;
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c20 = _t[2];
        u64 v_c47 = _prim_lt(db, v_c14, v_c17);
        if (v_c47 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c47) return;
        if (!slog::exists_probe<3,1>(ackindex103, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe<2,1>(ack_ansindex104, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m116) {
          u64 v_c22 = m116[1];
          slog::join_probe<3,1>(ackindex105, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m117) {
            u64 v_c13 = m117[1]; u64 v_c16 = m117[2];
            u64 v_c48 = _prim_lt(db, v_c14, v_c13);
            if (v_c48 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
            if (!v_c48) return;
            u64 v_c49 = _prim__0002d(db, v_c13, v_c15);
            if (v_c49 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
            if (v_c20 != v_c49) return;
            ++_fires;
            slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c22, v_c21, v_c16, v_c17, v_c13}, std::array<u16,5>{2, 1, 0, 3, 4});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:ack", _fires);
  
      if (!_done)
      {
        ReadTask106* _cont = new ReadTask106(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask106(db,b), false);
  // (crule (pre (let __tconst78tO27 const5feceb66ffc86f38d952786c) (let __tconst9sKc31 const6b86b273ff34fce19d6b804e)) (scan ack_ans __t7GoZ33 __v1) (body (join-old ack (0 2 1) 1 (0 2 1) __t7GoZ33 __v0 __t1zrb32) (exists $sup35494x8x0x0x1 (2 1 0 3 4) 1 __v0) (join ack_ans (1 0) 1 __v0 __t0iBx30) (join-old $sup35494x8x0x0x1 (2 1 0 3 4) 2 (2 1 0 3 4) __v0 __t0iBx30 __t6ie525 m n) (cmp lt __tconst78tO27 m) (cmp lt __tconst78tO27 n) (join-old ack (0 2 1) 3 (0 2 1) __t6ie525 n m) (let __t4ow729 (_0002d n __tconst9sKc31)) (join-old ack (0 2 1) 3 (0 2 1) __t0iBx30 __t4ow729 m) (let chk1IfM137 (_0002d m __tconst9sKc31)) (eq __t1zrb32 chk1IfM137)) (head (emit ack_ans (0 1) __t6ie525 __v1)) dem_ack.slog:9 #f)
  class ReadTask129 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ackindex119;  slog::Index** $sup35494x8x0x0x1index120;  slog::Index** ack_ansindex121;  slog::Index** $sup35494x8x0x0x1index122;  slog::Index** ackindex123;  slog::Index** ackindex124;  slog::Index** ackdelta125;  slog::Index** $sup35494x8x0x0x1delta126;  slog::Index** ackdelta127;  slog::Index** ackdelta128;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord130({0, 1});
      slog::Relation* readrel131 = db->getRelation("ack_ans");
      head_index[0] = readrel131->getIndex(ord130, false);
      outer_rel = db->getRelation("ack_ans");
      std::vector<u16> ord132({0, 2, 1});
      slog::Relation* readrel133 = db->getRelation("ack");
      ackindex119 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({0, 2, 1});
      slog::Relation* readrel135 = db->getRelation("ack");
      ackdelta125 = readrel135->getIndex(ord134, true);
      std::vector<u16> ord136({2, 1, 0, 3, 4});
      slog::Relation* readrel137 = db->getRelation("$sup35494x8x0x0x1");
      $sup35494x8x0x0x1index120 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 0});
      slog::Relation* readrel139 = db->getRelation("ack_ans");
      ack_ansindex121 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({2, 1, 0, 3, 4});
      slog::Relation* readrel141 = db->getRelation("$sup35494x8x0x0x1");
      $sup35494x8x0x0x1index122 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({2, 1, 0, 3, 4});
      slog::Relation* readrel143 = db->getRelation("$sup35494x8x0x0x1");
      $sup35494x8x0x0x1delta126 = readrel143->getIndex(ord142, true);
      std::vector<u16> ord144({0, 2, 1});
      slog::Relation* readrel145 = db->getRelation("ack");
      ackindex123 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 2, 1});
      slog::Relation* readrel147 = db->getRelation("ack");
      ackdelta127 = readrel147->getIndex(ord146, true);
      std::vector<u16> ord148({0, 2, 1});
      slog::Relation* readrel149 = db->getRelation("ack");
      ackindex124 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 2, 1});
      slog::Relation* readrel151 = db->getRelation("ack");
      ackdelta128 = readrel151->getIndex(ord150, true);
  
    }
    ReadTask129(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const5feceb66ffc86f38d952786c;
      u64 v_c37 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c45 = _t[1];
        slog::join_probe_old<3,1>(ackindex119, ackdelta125, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m152) {
          u64 v_c22 = m152[1]; u64 v_c43 = m152[2];
          if (!slog::exists_probe<5,1>($sup35494x8x0x0x1index120, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(ack_ansindex121, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m153) {
            u64 v_c38 = m153[1];
            slog::join_probe_old<5,2>($sup35494x8x0x0x1index122, $sup35494x8x0x0x1delta126, std::array<u64,5>{v_c22, v_c38, 0, 0, 0}, [&](const std::array<u64,5>& m154) {
              u64 v_c41 = m154[2]; u64 v_c17 = m154[3]; u64 v_c13 = m154[4];
              u64 v_c50 = _prim_lt(db, v_c36, v_c17);
              if (v_c50 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
              if (!v_c50) return;
              u64 v_c51 = _prim_lt(db, v_c36, v_c13);
              if (v_c51 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
              if (!v_c51) return;
              slog::join_probe_old<3,3>(ackindex123, ackdelta127, std::array<u64,3>{v_c41, v_c13, v_c17}, [&](const std::array<u64,3>& m157) {
                u64 v_c39 = _prim__0002d(db, v_c13, v_c37);
                if (v_c39 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
                slog::join_probe_old<3,3>(ackindex124, ackdelta128, std::array<u64,3>{v_c38, v_c39, v_c17}, [&](const std::array<u64,3>& m158) {
                  u64 v_c52 = _prim__0002d(db, v_c17, v_c37);
                  if (v_c52 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
                  if (v_c43 != v_c52) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c45}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:ack_ans", _fires);
  
      if (!_done)
      {
        ReadTask129* _cont = new ReadTask129(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask129(db,b), false);
  // (crule (pre (let __tconst6zmP5 const5feceb66ffc86f38d952786c) (let __tconst7BU61 const6b86b273ff34fce19d6b804e)) (scan ack __t9IQx3 m n) (body (cmp lt __tconst6zmP5 m) (cmp lt __tconst6zmP5 n) (let __t2n9q2 (_0002d n __tconst7BU61))) (head (emit-temp temp78Qw134 __t2n9q2 m)) dem_ack.slog:9 #f)
  class ReadTask159 : public slog::Task
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
      head_rel[0] = db->getRelation("temp78Qw134");
      outer_rel = db->getRelation("ack");
  
    }
    ReadTask159(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c53 = v_const5feceb66ffc86f38d952786c;
      u64 v_c54 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c55 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c56 = _prim_lt(db, v_c53, v_c17);
        if (v_c56 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c56) return;
        u64 v_c57 = _prim_lt(db, v_c53, v_c13);
        if (v_c57 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c57) return;
        u64 v_c58 = _prim__0002d(db, v_c13, v_c54);
        if (v_c58 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c58, v_c17});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:ack", _fires);
  
      if (!_done)
      {
        ReadTask159* _cont = new ReadTask159(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask159(db,b), false);
  // (crule (pre) (scan temp78Qw134 __t2n9q2 m) (body) (head (mkstruct ack (1 2 0) __92Wn58 m __t2n9q2)) dem_ack.slog:9 #f)
  class ReadTask162 : public slog::Task
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
      head_rel[0] = db->getRelation("ack");
      outer_rel = db->getRelation("temp78Qw134");
  
    }
    ReadTask162(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c58 = _t[0];
        u64 v_c17 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c17, v_c58}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:temp78Qw134", _fires);
  
      if (!_done)
      {
        ReadTask162* _cont = new ReadTask162(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask162(db,b), false);
  // (crule (pre (let __trid1d5S55 constd703a74a3d00a0728a67422c) (let __trel3kpJ56 const81744fc1e95f3b4f2a49b26c) (let __tcol7mis57 const6b86b273ff34fce19d6b804e) (let __tconst6IjH41 const6b86b273ff34fce19d6b804e)) (scan $sup35494x8x0x0x1 __d0 __d1 __v0 m n) (body (let __t9Rt442 (_0002d m __tconst6IjH41))) (head (tycheck __v0 (accept int) __trid1d5S55 __trel3kpJ56 __tcol7mis57 (1 2 3 4 0)) (emit-temp temp6q9K133 __t9Rt442 __v0)) dem_ack.slog:9 #f)
  class ReadTask163 : public slog::Task
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
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp6q9K133");
      outer_rel = db->getRelation("$sup35494x8x0x0x1");
  
    }
    ReadTask163(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c59 = v_constd703a74a3d00a0728a67422c;
      u64 v_c60 = v_const81744fc1e95f3b4f2a49b26c;
      u64 v_c61 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c63 = _t[0];
        u64 v_c64 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c65 = _prim__0002d(db, v_c17, v_c62);
        if (v_c65 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        ++_fires;
        if (!(is_int(v_c22)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c59, v_c60, v_c61, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<2>(head_rel[1], newbatch[1], std::array<u64,2>{v_c65, v_c22});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:$sup35494x8x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask163* _cont = new ReadTask163(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask163(db,b), false);
  // (crule (pre) (scan toint_range __erre6B8b116 __errf2oV7117 __errf33xT118) (body) (head (emit error (0) __erre6B8b116)) <internal>:1 #f)
  class ReadTask164 : public slog::Task
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
      std::vector<u16> ord165({0});
      slog::Relation* readrel166 = db->getRelation("error");
      head_index[0] = readrel166->getIndex(ord165, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask164(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c66}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask164* _cont = new ReadTask164(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask164(db,b), false);
  // (crule (pre (let __tconst78tO27 const5feceb66ffc86f38d952786c) (let __tconst9sKc31 const6b86b273ff34fce19d6b804e)) (scan ack __t6ie525 m n) (body (cmp lt __tconst78tO27 m) (cmp lt __tconst78tO27 n) (exists ack (1 2 0) 1 m) (join $sup35494x8x0x0x1 (0 3 4 1 2) 3 __t6ie525 m n __t0iBx30 __v0) (join ack_ans (0 1) 2 __t0iBx30 __v0) (let __t4ow729 (_0002d n __tconst9sKc31)) (join-old ack (0 2 1) 3 (0 2 1) __t0iBx30 __t4ow729 m) (let __t1zrb32 (_0002d m __tconst9sKc31)) (join-old ack (1 2 0) 2 (1 2 0) __t1zrb32 __v0 __t7GoZ33) (join ack_ans (0 1) 1 __t7GoZ33 __v1)) (head (emit ack_ans (0 1) __t6ie525 __v1)) dem_ack.slog:9 #f)
  class ReadTask175 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ackindex167;  slog::Index** $sup35494x8x0x0x1index168;  slog::Index** ack_ansindex169;  slog::Index** ackindex170;  slog::Index** ackindex171;  slog::Index** ack_ansindex172;  slog::Index** ackdelta173;  slog::Index** ackdelta174;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord176({0, 1});
      slog::Relation* readrel177 = db->getRelation("ack_ans");
      head_index[0] = readrel177->getIndex(ord176, false);
      outer_rel = db->getRelation("ack");
      std::vector<u16> ord178({1, 2, 0});
      slog::Relation* readrel179 = db->getRelation("ack");
      ackindex167 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({0, 3, 4, 1, 2});
      slog::Relation* readrel181 = db->getRelation("$sup35494x8x0x0x1");
      $sup35494x8x0x0x1index168 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({0, 1});
      slog::Relation* readrel183 = db->getRelation("ack_ans");
      ack_ansindex169 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({0, 2, 1});
      slog::Relation* readrel185 = db->getRelation("ack");
      ackindex170 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({0, 2, 1});
      slog::Relation* readrel187 = db->getRelation("ack");
      ackdelta173 = readrel187->getIndex(ord186, true);
      std::vector<u16> ord188({1, 2, 0});
      slog::Relation* readrel189 = db->getRelation("ack");
      ackindex171 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({1, 2, 0});
      slog::Relation* readrel191 = db->getRelation("ack");
      ackdelta174 = readrel191->getIndex(ord190, true);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("ack_ans");
      ack_ansindex172 = readrel193->getIndex(ord192, false);
  
    }
    ReadTask175(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const5feceb66ffc86f38d952786c;
      u64 v_c37 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c41 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c69 = _prim_lt(db, v_c36, v_c17);
        if (v_c69 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c69) return;
        u64 v_c70 = _prim_lt(db, v_c36, v_c13);
        if (v_c70 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c70) return;
        if (!slog::exists_probe<3,1>(ackindex167, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe<5,3>($sup35494x8x0x0x1index168, std::array<u64,5>{v_c41, v_c17, v_c13, 0, 0}, [&](const std::array<u64,5>& m196) {
          u64 v_c38 = m196[3]; u64 v_c22 = m196[4];
          slog::join_probe<2,2>(ack_ansindex169, std::array<u64,2>{v_c38, v_c22}, [&](const std::array<u64,2>& m197) {
            u64 v_c39 = _prim__0002d(db, v_c13, v_c37);
            if (v_c39 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
            slog::join_probe_old<3,3>(ackindex170, ackdelta173, std::array<u64,3>{v_c38, v_c39, v_c17}, [&](const std::array<u64,3>& m198) {
              u64 v_c43 = _prim__0002d(db, v_c17, v_c37);
              if (v_c43 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
              slog::join_probe_old<3,2>(ackindex171, ackdelta174, std::array<u64,3>{v_c43, v_c22, 0}, [&](const std::array<u64,3>& m199) {
                u64 v_c44 = m199[2];
                slog::join_probe<2,1>(ack_ansindex172, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m200) {
                  u64 v_c45 = m200[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c45}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:ack", _fires);
  
      if (!_done)
      {
        ReadTask175* _cont = new ReadTask175(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask175(db,b), false);
  // (crule (pre (let __tconst78tO27 const5feceb66ffc86f38d952786c) (let __tconst9sKc31 const6b86b273ff34fce19d6b804e)) (scan $sup35494x8x0x0x1 __t6ie525 __t0iBx30 __v0 m n) (body (cmp lt __tconst78tO27 m) (cmp lt __tconst78tO27 n) (join-old ack (0 2 1) 3 (0 2 1) __t6ie525 n m) (join ack_ans (0 1) 2 __t0iBx30 __v0) (let __t4ow729 (_0002d n __tconst9sKc31)) (join-old ack (0 2 1) 3 (0 2 1) __t0iBx30 __t4ow729 m) (let __t1zrb32 (_0002d m __tconst9sKc31)) (join-old ack (1 2 0) 2 (1 2 0) __t1zrb32 __v0 __t7GoZ33) (join ack_ans (0 1) 1 __t7GoZ33 __v1)) (head (emit ack_ans (0 1) __t6ie525 __v1)) dem_ack.slog:9 #f)
  class ReadTask209 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ackindex201;  slog::Index** ack_ansindex202;  slog::Index** ackindex203;  slog::Index** ackindex204;  slog::Index** ack_ansindex205;  slog::Index** ackdelta206;  slog::Index** ackdelta207;  slog::Index** ackdelta208;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord210({0, 1});
      slog::Relation* readrel211 = db->getRelation("ack_ans");
      head_index[0] = readrel211->getIndex(ord210, false);
      outer_rel = db->getRelation("$sup35494x8x0x0x1");
      std::vector<u16> ord212({0, 2, 1});
      slog::Relation* readrel213 = db->getRelation("ack");
      ackindex201 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({0, 2, 1});
      slog::Relation* readrel215 = db->getRelation("ack");
      ackdelta206 = readrel215->getIndex(ord214, true);
      std::vector<u16> ord216({0, 1});
      slog::Relation* readrel217 = db->getRelation("ack_ans");
      ack_ansindex202 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0, 2, 1});
      slog::Relation* readrel219 = db->getRelation("ack");
      ackindex203 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({0, 2, 1});
      slog::Relation* readrel221 = db->getRelation("ack");
      ackdelta207 = readrel221->getIndex(ord220, true);
      std::vector<u16> ord222({1, 2, 0});
      slog::Relation* readrel223 = db->getRelation("ack");
      ackindex204 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 0});
      slog::Relation* readrel225 = db->getRelation("ack");
      ackdelta208 = readrel225->getIndex(ord224, true);
      std::vector<u16> ord226({0, 1});
      slog::Relation* readrel227 = db->getRelation("ack_ans");
      ack_ansindex205 = readrel227->getIndex(ord226, false);
  
    }
    ReadTask209(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const5feceb66ffc86f38d952786c;
      u64 v_c37 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c41 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c71 = _prim_lt(db, v_c36, v_c17);
        if (v_c71 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c71) return;
        u64 v_c72 = _prim_lt(db, v_c36, v_c13);
        if (v_c72 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
        if (!v_c72) return;
        slog::join_probe_old<3,3>(ackindex201, ackdelta206, std::array<u64,3>{v_c41, v_c13, v_c17}, [&](const std::array<u64,3>& m230) {
          slog::join_probe<2,2>(ack_ansindex202, std::array<u64,2>{v_c38, v_c22}, [&](const std::array<u64,2>& m231) {
            u64 v_c39 = _prim__0002d(db, v_c13, v_c37);
            if (v_c39 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
            slog::join_probe_old<3,3>(ackindex203, ackdelta207, std::array<u64,3>{v_c38, v_c39, v_c17}, [&](const std::array<u64,3>& m232) {
              u64 v_c43 = _prim__0002d(db, v_c17, v_c37);
              if (v_c43 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
              slog::join_probe_old<3,2>(ackindex204, ackdelta208, std::array<u64,3>{v_c43, v_c22, 0}, [&](const std::array<u64,3>& m233) {
                u64 v_c44 = m233[2];
                slog::join_probe<2,1>(ack_ansindex205, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m234) {
                  u64 v_c45 = m234[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c45}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:$sup35494x8x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask209* _cont = new ReadTask209(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask209(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre4WVA105 __errf0r61106 __errf7zQh107) (body) (head (emit error (0) __erre4WVA105)) <internal>:1 #f)
  class ReadTask235 : public slog::Task
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
      std::vector<u16> ord236({0});
      slog::Relation* readrel237 = db->getRelation("error");
      head_index[0] = readrel237->getIndex(ord236, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask235(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c73 = _t[0];
        u64 v_c74 = _t[1];
        u64 v_c75 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c73}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask235* _cont = new ReadTask235(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask235(db,b), false);
  // (crule (pre (let __tconst869H10 const5feceb66ffc86f38d952786c) (let __tconst2eQz12 const6b86b273ff34fce19d6b804e)) (probe ack (2 0 1) 1 __tconst869H10 __t8RII9 m) (body (cmp lt __tconst869H10 m) (let __t17vQ13 (_0002d m __tconst2eQz12)) (join-old ack (1 2 0) 2 (1 2 0) __t17vQ13 __tconst2eQz12 __t5L6U14) (join ack_ans (0 1) 1 __t5L6U14 __v0)) (head (emit ack_ans (0 1) __t8RII9 __v0)) dem_ack.slog:8 #f)
  class ReadTask241 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** ackindex238;  slog::Index** ack_ansindex239;  slog::Index** ackdelta240;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord242({0, 1});
      slog::Relation* readrel243 = db->getRelation("ack_ans");
      head_index[0] = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({2, 0, 1});
      slog::Relation* readrel245 = db->getRelation("ack");
      driver_index = readrel245->getIndex(ord244, true);
      std::vector<u16> ord246({1, 2, 0});
      slog::Relation* readrel247 = db->getRelation("ack");
      ackindex238 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 2, 0});
      slog::Relation* readrel249 = db->getRelation("ack");
      ackdelta240 = readrel249->getIndex(ord248, true);
      std::vector<u16> ord250({0, 1});
      slog::Relation* readrel251 = db->getRelation("ack_ans");
      ack_ansindex239 = readrel251->getIndex(ord250, false);
  
    }
    ReadTask241(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c26, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m252) {
        u64 v_c30 = m252[1];
        u64 v_c17 = m252[2];
        if (buckethash(v_c30) != bucket) return;
        u64 v_c76 = _prim_lt(db, v_c26, v_c17);
        if (v_c76 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:8"); return; }
        if (!v_c76) return;
        u64 v_c29 = _prim__0002d(db, v_c17, v_c27);
        if (v_c29 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:8"); return; }
        slog::join_probe_old<3,2>(ackindex238, ackdelta240, std::array<u64,3>{v_c29, v_c27, 0}, [&](const std::array<u64,3>& m254) {
          u64 v_c28 = m254[2];
          slog::join_probe<2,1>(ack_ansindex239, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m255) {
            u64 v_c22 = m255[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c30, v_c22}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:8", "delta:ack", _fires);
  
      if (!_done)
      {
        ReadTask241* _cont = new ReadTask241(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask241(db,b), false);
  // (crule (pre (let __tconst6sPB40 const4e07408562bedb8b60ce05c1)) (once) (body) (head (mkstruct ack (1 2 0) __5PUS59 __tconst6sPB40 __tconst6sPB40)) dem_ack.slog:13 #f)
  class ReadTask256 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack");
  
    }
    ReadTask256(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c77 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c77, v_c77}, std::array<u16,3>{1, 2, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:13", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask256(db,b), true);
  // (crule (pre) (scan malformed_deduction __erre0GCB97 __errf6P9U98 __errf2nXk99 __errf3lon100 __errf2DEu101) (body) (head (emit error (0) __erre0GCB97)) <internal>:1 #f)
  class ReadTask257 : public slog::Task
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
      std::vector<u16> ord258({0});
      slog::Relation* readrel259 = db->getRelation("error");
      head_index[0] = readrel259->getIndex(ord258, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask257(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c78 = _t[0];
        u64 v_c79 = _t[1];
        u64 v_c80 = _t[2];
        u64 v_c81 = _t[3];
        u64 v_c82 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c78}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask257* _cont = new ReadTask257(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask257(db,b), false);
  // (crule (pre) (scan type_mismatch __erre5ngc119 __errf6ya6120 __errf54nW121 __errf1HsK122 __errf8gf7123) (body) (head (emit error (0) __erre5ngc119)) <internal>:1 #f)
  class ReadTask260 : public slog::Task
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
      std::vector<u16> ord261({0});
      slog::Relation* readrel262 = db->getRelation("error");
      head_index[0] = readrel262->getIndex(ord261, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask260(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c83 = _t[0];
        u64 v_c84 = _t[1];
        u64 v_c85 = _t[2];
        u64 v_c86 = _t[3];
        u64 v_c87 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c83}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask260* _cont = new ReadTask260(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask260(db,b), false);
  // (crule (pre (let __tconst869H10 const5feceb66ffc86f38d952786c) (let __tconst2eQz12 const6b86b273ff34fce19d6b804e)) (scan ack_ans __t5L6U14 __v0) (body (exists ack (2 0 1) 1 __tconst869H10) (join-old ack (0 2 1) 2 (0 2 1) __t5L6U14 __tconst2eQz12 __t17vQ13) (join-old ack (2 0 1) 1 (2 0 1) __tconst869H10 __t8RII9 m) (cmp lt __tconst869H10 m) (let chk5Hto141 (_0002d m __tconst2eQz12)) (eq __t17vQ13 chk5Hto141)) (head (emit ack_ans (0 1) __t8RII9 __v0)) dem_ack.slog:8 #f)
  class ReadTask268 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ackindex263;  slog::Index** ackindex264;  slog::Index** ackindex265;  slog::Index** ackdelta266;  slog::Index** ackdelta267;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord269({0, 1});
      slog::Relation* readrel270 = db->getRelation("ack_ans");
      head_index[0] = readrel270->getIndex(ord269, false);
      outer_rel = db->getRelation("ack_ans");
      std::vector<u16> ord271({2, 0, 1});
      slog::Relation* readrel272 = db->getRelation("ack");
      ackindex263 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({0, 2, 1});
      slog::Relation* readrel274 = db->getRelation("ack");
      ackindex264 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({0, 2, 1});
      slog::Relation* readrel276 = db->getRelation("ack");
      ackdelta266 = readrel276->getIndex(ord275, true);
      std::vector<u16> ord277({2, 0, 1});
      slog::Relation* readrel278 = db->getRelation("ack");
      ackindex265 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({2, 0, 1});
      slog::Relation* readrel280 = db->getRelation("ack");
      ackdelta267 = readrel280->getIndex(ord279, true);
  
    }
    ReadTask268(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c28 = _t[0];
        u64 v_c22 = _t[1];
        if (!slog::exists_probe<3,1>(ackindex263, std::array<u64,3>{v_c26, 0, 0})) return;
        slog::join_probe_old<3,2>(ackindex264, ackdelta266, std::array<u64,3>{v_c28, v_c27, 0}, [&](const std::array<u64,3>& m281) {
          u64 v_c29 = m281[2];
          slog::join_probe_old<3,1>(ackindex265, ackdelta267, std::array<u64,3>{v_c26, 0, 0}, [&](const std::array<u64,3>& m282) {
            u64 v_c30 = m282[1]; u64 v_c17 = m282[2];
            u64 v_c88 = _prim_lt(db, v_c26, v_c17);
            if (v_c88 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:8"); return; }
            if (!v_c88) return;
            u64 v_c89 = _prim__0002d(db, v_c17, v_c27);
            if (v_c89 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:8"); return; }
            if (v_c29 != v_c89) return;
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c30, v_c22}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:8", "delta:ack_ans", _fires);
  
      if (!_done)
      {
        ReadTask268* _cont = new ReadTask268(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask268(db,b), false);
  // (crule (pre) (scan nan_result __erre7w0P112 __errf0KdJ113 __errf81V3114 __errf9GIC115) (body) (head (emit error (0) __erre7w0P112)) <internal>:1 #f)
  class ReadTask284 : public slog::Task
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
      std::vector<u16> ord285({0});
      slog::Relation* readrel286 = db->getRelation("error");
      head_index[0] = readrel286->getIndex(ord285, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask284(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c90 = _t[0];
        u64 v_c91 = _t[1];
        u64 v_c92 = _t[2];
        u64 v_c93 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c90}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask284* _cont = new ReadTask284(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask284(db,b), false);
  // (crule (pre (let __tconst78tO27 const5feceb66ffc86f38d952786c) (let __tconst9sKc31 const6b86b273ff34fce19d6b804e)) (scan ack_ans __t0iBx30 __v0) (body (exists ack (2 0 1) 1 __v0) (join-old $sup35494x8x0x0x1 (2 1 0 3 4) 2 (2 1 0 3 4) __v0 __t0iBx30 __t6ie525 m n) (cmp lt __tconst78tO27 m) (cmp lt __tconst78tO27 n) (join-old ack (0 2 1) 3 (0 2 1) __t6ie525 n m) (let __t4ow729 (_0002d n __tconst9sKc31)) (join-old ack (0 2 1) 3 (0 2 1) __t0iBx30 __t4ow729 m) (let __t1zrb32 (_0002d m __tconst9sKc31)) (join-old ack (1 2 0) 2 (1 2 0) __t1zrb32 __v0 __t7GoZ33) (join-old ack_ans (0 1) 1 (0 1) __t7GoZ33 __v1)) (head (emit ack_ans (0 1) __t6ie525 __v1)) dem_ack.slog:9 #f)
  class ReadTask298 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ackindex287;  slog::Index** $sup35494x8x0x0x1index288;  slog::Index** ackindex289;  slog::Index** ackindex290;  slog::Index** ackindex291;  slog::Index** ack_ansindex292;  slog::Index** $sup35494x8x0x0x1delta293;  slog::Index** ackdelta294;  slog::Index** ackdelta295;  slog::Index** ackdelta296;  slog::Index** ack_ansdelta297;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord299({0, 1});
      slog::Relation* readrel300 = db->getRelation("ack_ans");
      head_index[0] = readrel300->getIndex(ord299, false);
      outer_rel = db->getRelation("ack_ans");
      std::vector<u16> ord301({2, 0, 1});
      slog::Relation* readrel302 = db->getRelation("ack");
      ackindex287 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({2, 1, 0, 3, 4});
      slog::Relation* readrel304 = db->getRelation("$sup35494x8x0x0x1");
      $sup35494x8x0x0x1index288 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({2, 1, 0, 3, 4});
      slog::Relation* readrel306 = db->getRelation("$sup35494x8x0x0x1");
      $sup35494x8x0x0x1delta293 = readrel306->getIndex(ord305, true);
      std::vector<u16> ord307({0, 2, 1});
      slog::Relation* readrel308 = db->getRelation("ack");
      ackindex289 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({0, 2, 1});
      slog::Relation* readrel310 = db->getRelation("ack");
      ackdelta294 = readrel310->getIndex(ord309, true);
      std::vector<u16> ord311({0, 2, 1});
      slog::Relation* readrel312 = db->getRelation("ack");
      ackindex290 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({0, 2, 1});
      slog::Relation* readrel314 = db->getRelation("ack");
      ackdelta295 = readrel314->getIndex(ord313, true);
      std::vector<u16> ord315({1, 2, 0});
      slog::Relation* readrel316 = db->getRelation("ack");
      ackindex291 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 2, 0});
      slog::Relation* readrel318 = db->getRelation("ack");
      ackdelta296 = readrel318->getIndex(ord317, true);
      std::vector<u16> ord319({0, 1});
      slog::Relation* readrel320 = db->getRelation("ack_ans");
      ack_ansindex292 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({0, 1});
      slog::Relation* readrel322 = db->getRelation("ack_ans");
      ack_ansdelta297 = readrel322->getIndex(ord321, true);
  
    }
    ReadTask298(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const5feceb66ffc86f38d952786c;
      u64 v_c37 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c22 = _t[1];
        if (!slog::exists_probe<3,1>(ackindex287, std::array<u64,3>{v_c22, 0, 0})) return;
        slog::join_probe_old<5,2>($sup35494x8x0x0x1index288, $sup35494x8x0x0x1delta293, std::array<u64,5>{v_c22, v_c38, 0, 0, 0}, [&](const std::array<u64,5>& m323) {
          u64 v_c41 = m323[2]; u64 v_c17 = m323[3]; u64 v_c13 = m323[4];
          u64 v_c94 = _prim_lt(db, v_c36, v_c17);
          if (v_c94 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
          if (!v_c94) return;
          u64 v_c95 = _prim_lt(db, v_c36, v_c13);
          if (v_c95 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
          if (!v_c95) return;
          slog::join_probe_old<3,3>(ackindex289, ackdelta294, std::array<u64,3>{v_c41, v_c13, v_c17}, [&](const std::array<u64,3>& m326) {
            u64 v_c39 = _prim__0002d(db, v_c13, v_c37);
            if (v_c39 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
            slog::join_probe_old<3,3>(ackindex290, ackdelta295, std::array<u64,3>{v_c38, v_c39, v_c17}, [&](const std::array<u64,3>& m327) {
              u64 v_c43 = _prim__0002d(db, v_c17, v_c37);
              if (v_c43 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
              slog::join_probe_old<3,2>(ackindex291, ackdelta296, std::array<u64,3>{v_c43, v_c22, 0}, [&](const std::array<u64,3>& m328) {
                u64 v_c44 = m328[2];
                slog::join_probe_old<2,1>(ack_ansindex292, ack_ansdelta297, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m329) {
                  u64 v_c45 = m329[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c45}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:ack_ans", _fires);
  
      if (!_done)
      {
        ReadTask298* _cont = new ReadTask298(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask298(db,b), false);
  // (crule (pre (let __tconst7yTE7 constd4735e3a265e16eee03f5971) (let __tconst4FbX6 const4e07408562bedb8b60ce05c1)) (once) (body) (head (mkstruct ack (1 2 0) __2BAy61 __tconst7yTE7 __tconst4FbX6)) dem_ack.slog:12 #f)
  class ReadTask330 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack");
  
    }
    ReadTask330(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c96 = v_constd4735e3a265e16eee03f5971;
      u64 v_c97 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c96, v_c97}, std::array<u16,3>{1, 2, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:12", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask330(db,b), true);
  // (crule (pre (let __tconst6oaS20 const5feceb66ffc86f38d952786c) (let __tconst2pP116 const6b86b273ff34fce19d6b804e)) (probe ack (2 0 1) 1 __tconst6oaS20 __t88dM19 m) (body (cmp lt __tconst6oaS20 m) (let __t9qIO17 (_0002d m __tconst2pP116))) (head (emit-temp temp6exO140 __t9qIO17)) dem_ack.slog:8 #f)
  class ReadTask331 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6exO140");
      std::vector<u16> ord332({2, 0, 1});
      slog::Relation* readrel333 = db->getRelation("ack");
      driver_index = readrel333->getIndex(ord332, true);
  
    }
    ReadTask331(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c98, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m334) {
        u64 v_c100 = m334[1];
        u64 v_c17 = m334[2];
        if (buckethash(v_c100) != bucket) return;
        u64 v_c101 = _prim_lt(db, v_c98, v_c17);
        if (v_c101 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:8"); return; }
        if (!v_c101) return;
        u64 v_c102 = _prim__0002d(db, v_c17, v_c99);
        if (v_c102 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:8"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c102});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:8", "delta:ack", _fires);
  
      if (!_done)
      {
        ReadTask331* _cont = new ReadTask331(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask331(db,b), false);
  // (crule (pre (let __tconst2pP116 const6b86b273ff34fce19d6b804e)) (scan temp6exO140 __t9qIO17) (body) (head (mkstruct ack (1 2 0) __5NaV60 __t9qIO17 __tconst2pP116)) dem_ack.slog:8 #f)
  class ReadTask336 : public slog::Task
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
      head_rel[0] = db->getRelation("ack");
      outer_rel = db->getRelation("temp6exO140");
  
    }
    ReadTask336(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c102 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c102, v_c99}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:8", "delta:temp6exO140", _fires);
  
      if (!_done)
      {
        ReadTask336* _cont = new ReadTask336(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask336(db,b), false);
  // (crule (pre (let __tconst78tO27 const5feceb66ffc86f38d952786c) (let __tconst9sKc31 const6b86b273ff34fce19d6b804e)) (scan ack __t7GoZ33 __t1zrb32 __v0) (body (exists $sup35494x8x0x0x1 (2 1 0 3 4) 1 __v0) (exists ack_ans (0 1) 1 __t7GoZ33) (join ack_ans (1 0) 1 __v0 __t0iBx30) (join $sup35494x8x0x0x1 (2 1 0 3 4) 2 __v0 __t0iBx30 __t6ie525 m n) (cmp lt __tconst78tO27 m) (cmp lt __tconst78tO27 n) (join ack (0 2 1) 3 __t6ie525 n m) (let __t4ow729 (_0002d n __tconst9sKc31)) (join ack (0 2 1) 3 __t0iBx30 __t4ow729 m) (join ack_ans (0 1) 1 __t7GoZ33 __v1) (let chk436v139 (_0002d m __tconst9sKc31)) (eq __t1zrb32 chk436v139)) (head (emit ack_ans (0 1) __t6ie525 __v1)) dem_ack.slog:9 #f)
  class ReadTask344 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup35494x8x0x0x1index337;  slog::Index** ack_ansindex338;  slog::Index** ack_ansindex339;  slog::Index** $sup35494x8x0x0x1index340;  slog::Index** ackindex341;  slog::Index** ackindex342;  slog::Index** ack_ansindex343;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ack_ans");
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("ack_ans");
      head_index[0] = readrel346->getIndex(ord345, false);
      outer_rel = db->getRelation("ack");
      std::vector<u16> ord347({2, 1, 0, 3, 4});
      slog::Relation* readrel348 = db->getRelation("$sup35494x8x0x0x1");
      $sup35494x8x0x0x1index337 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({0, 1});
      slog::Relation* readrel350 = db->getRelation("ack_ans");
      ack_ansindex338 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 0});
      slog::Relation* readrel352 = db->getRelation("ack_ans");
      ack_ansindex339 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({2, 1, 0, 3, 4});
      slog::Relation* readrel354 = db->getRelation("$sup35494x8x0x0x1");
      $sup35494x8x0x0x1index340 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({0, 2, 1});
      slog::Relation* readrel356 = db->getRelation("ack");
      ackindex341 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({0, 2, 1});
      slog::Relation* readrel358 = db->getRelation("ack");
      ackindex342 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({0, 1});
      slog::Relation* readrel360 = db->getRelation("ack_ans");
      ack_ansindex343 = readrel360->getIndex(ord359, false);
  
    }
    ReadTask344(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const5feceb66ffc86f38d952786c;
      u64 v_c37 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c22 = _t[2];
        if (!slog::exists_probe<5,1>($sup35494x8x0x0x1index337, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(ack_ansindex338, std::array<u64,2>{v_c44, 0})) return;
        slog::join_probe<2,1>(ack_ansindex339, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m361) {
          u64 v_c38 = m361[1];
          slog::join_probe<5,2>($sup35494x8x0x0x1index340, std::array<u64,5>{v_c22, v_c38, 0, 0, 0}, [&](const std::array<u64,5>& m362) {
            u64 v_c41 = m362[2]; u64 v_c17 = m362[3]; u64 v_c13 = m362[4];
            u64 v_c103 = _prim_lt(db, v_c36, v_c17);
            if (v_c103 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
            if (!v_c103) return;
            u64 v_c104 = _prim_lt(db, v_c36, v_c13);
            if (v_c104 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
            if (!v_c104) return;
            slog::join_probe<3,3>(ackindex341, std::array<u64,3>{v_c41, v_c13, v_c17}, [&](const std::array<u64,3>& m365) {
              u64 v_c39 = _prim__0002d(db, v_c13, v_c37);
              if (v_c39 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
              slog::join_probe<3,3>(ackindex342, std::array<u64,3>{v_c38, v_c39, v_c17}, [&](const std::array<u64,3>& m366) {
                slog::join_probe<2,1>(ack_ansindex343, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m367) {
                  u64 v_c45 = m367[1];
                  u64 v_c105 = _prim__0002d(db, v_c17, v_c37);
                  if (v_c105 == slog_error) { slog::emit_pending_error(db, "dem_ack.slog:9"); return; }
                  if (v_c43 != v_c105) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c45}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:ack", _fires);
  
      if (!_done)
      {
        ReadTask344* _cont = new ReadTask344(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask344(db,b), false);
  // (crule (pre) (scan div_by_zero __erre3rcO102 __errf4h3J103 __errf2RI0104) (body) (head (emit error (0) __erre3rcO102)) <internal>:1 #f)
  class ReadTask368 : public slog::Task
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
      std::vector<u16> ord369({0});
      slog::Relation* readrel370 = db->getRelation("error");
      head_index[0] = readrel370->getIndex(ord369, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask368(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c106 = _t[0];
        u64 v_c107 = _t[1];
        u64 v_c108 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c106}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask368* _cont = new ReadTask368(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask368(db,b), false);
  // (crule (pre) (scan temp6q9K133 __t9Rt442 __v0) (body) (head (mkstruct ack (1 2 0) __7O7J54 __t9Rt442 __v0)) dem_ack.slog:9 #f)
  class ReadTask371 : public slog::Task
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
      head_rel[0] = db->getRelation("ack");
      outer_rel = db->getRelation("temp6q9K133");
  
    }
    ReadTask371(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c65 = _t[0];
        u64 v_c22 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c65, v_c22}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_ack.slog:9", "delta:temp6q9K133", _fires);
  
      if (!_done)
      {
        ReadTask371* _cont = new ReadTask371(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask371(db,b), false);
  s->addReadRel("$sup35494x8x0x0x1");
  s->addReadRel("ack");
  s->addReadRel("ack_ans");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp3Qoo132");
  s->addReadRel("temp6exO140");
  s->addReadRel("temp6q9K133");
  s->addReadRel("temp78Qw134");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$sup35494x8x0x0x1");
  s->addDynamicRel("ack");
  s->addDynamicRel("ack_ans");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("temp3Qoo132");
  s->addDynamicRel("temp6exO140");
  s->addDynamicRel("temp6q9K133");
  s->addDynamicRel("temp78Qw134");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("ack_ans");
  d->push(s);
  d->continueRun();
}

