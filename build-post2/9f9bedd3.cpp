
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const9a7407f3f7fd4c91ca5c2b75;
u64 v_const5407225b6f80c82685351e93;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("9f9bedd3");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const9a7407f3f7fd4c91ca5c2b75 = db->encodeString("lst_basic.slog:17");
  v_const5407225b6f80c82685351e93 = db->encodeString("heads");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord75({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord76({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord77({1, 2, 0});
    
    r->addIndex<3>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord78({0, 1, 2});
    
    r->addIndex<3>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp8fs7195");
  if (r == 0) db->addTempRelation("temp8fs7195", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7gtb203");
  if (r == 0) db->addTempRelation("temp7gtb203", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6agl201");
  if (r == 0) db->addTempRelation("temp6agl201", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5uBz192");
  if (r == 0) db->addTempRelation("temp5uBz192", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5nNz202");
  if (r == 0) db->addTempRelation("temp5nNz202", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5amt198");
  if (r == 0) db->addTempRelation("temp5amt198", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5Hoh200");
  if (r == 0) db->addTempRelation("temp5Hoh200", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3pOB197");
  if (r == 0) db->addTempRelation("temp3pOB197", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2uXG194");
  if (r == 0) db->addTempRelation("temp2uXG194", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2i09191");
  if (r == 0) db->addTempRelation("temp2i09191", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1jS4199");
  if (r == 0) db->addTempRelation("temp1jS4199", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp0h6Z193");
  if (r == 0) db->addTempRelation("temp0h6Z193", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp0NEd196");
  if (r == 0) db->addTempRelation("temp0NEd196", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("tails");
  if (r == 0) db->addRelation("tails", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tails");
      std::vector<u16> ord79({0});
    
    r->addIndex<1>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("tails"), std::array<u16,1>{0}, b));
  r = db->getRelation("swapped");
  if (r == 0) db->addRelation("swapped", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("swapped");
      std::vector<u16> ord80({0});
    
    r->addIndex<1>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("swapped"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord81({1, 2, 0});
    
    r->addIndex<3>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord82({0, 1, 2});
    
    r->addIndex<3>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord83({1, 2, 3, 0});
    
    r->addIndex<4>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord84({0, 1, 2, 3});
    
    r->addIndex<4>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord85({1, 2, 0});
    
    r->addIndex<3>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord86({0, 1, 2});
    
    r->addIndex<3>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord87({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord88({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord89({1, 2, 0});
    
    r->addIndex<3>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord90({0, 1, 2});
    
    r->addIndex<3>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord91({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord92({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("isnil");
  if (r == 0) db->addRelation("isnil", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("isnil");
      std::vector<u16> ord93({0});
    
    r->addIndex<1>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("isnil"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord94({1, 2, 3, 0});
    
    r->addIndex<4>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord95({0, 1, 2, 3});
    
    r->addIndex<4>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("input");
  if (r == 0) db->addRelation("input", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("input");
      std::vector<u16> ord96({0});
    
    r->addIndex<1>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("input"), std::array<u16,1>{0}, b));
  r = db->getRelation("heads");
  if (r == 0) db->addRelation("heads", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("heads");
      std::vector<u16> ord97({0});
    
    r->addIndex<1>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("heads"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord98({0});
    
    r->addIndex<1>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("edge");
  if (r == 0) db->addRelation("edge", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("edge");
      std::vector<u16> ord99({0, 1});
    
    r->addIndex<2>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("edge"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord100({1, 2, 0});
    
    r->addIndex<3>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord101({0, 1, 2});
    
    r->addIndex<3>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("built");
  if (r == 0) db->addRelation("built", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("built");
      std::vector<u16> ord102({0});
    
    r->addIndex<1>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("built"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord103({1, 0});
    
    r->addIndex<2>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord104({0, 1});
    
    r->addIndex<2>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre) (scan temp2i09191 __t2Tnt11 a b t x) (body (let __t7Szu12 (lpush __t2Tnt11 a))) (head (emit-temp temp5uBz192 __t7Szu12 b t x)) lst_basic.slog:20 #f)
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
      head_rel[0] = db->getRelation("temp5uBz192");
      outer_rel = db->getRelation("temp2i09191");
  
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
        u64 v_c5 = _prim_lpush(db, v_c0, v_c1);
        if (v_c5 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
        ++_fires;
        slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c5, v_c2, v_c3, v_c4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp2i09191", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre2v8I164 __errf7TVV165 __errf1Ds7166) (body) (head (emit error (0) __erre2v8I164)) <internal>:1 #f)
  class ReadTask1 : public slog::Task
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
      std::vector<u16> ord2({0});
      slog::Relation* readrel3 = db->getRelation("error");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c6}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask1* _cont = new ReadTask1(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1(db,b), false);
  // (crule (pre) (scan temp5amt198 __t8IBj19) (body) (head (emit built (0) __t8IBj19)) lst_basic.slog:18 #f)
  class ReadTask4 : public slog::Task
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
      head_rel[0] = db->getRelation("built");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("built");
      head_index[0] = readrel6->getIndex(ord5, false);
      outer_rel = db->getRelation("temp5amt198");
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[0];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:18", "delta:temp5amt198", _fires);
  
      if (!_done)
      {
        ReadTask4* _cont = new ReadTask4(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask4(db,b), false);
  // (crule (pre) (scan div_by_zero __erre1923161 __errf9GV9162 __errf78ZZ163) (body) (head (emit error (0) __erre1923161)) <internal>:1 #f)
  class ReadTask7 : public slog::Task
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
      std::vector<u16> ord8({0});
      slog::Relation* readrel9 = db->getRelation("error");
      head_index[0] = readrel9->getIndex(ord8, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask7* _cont = new ReadTask7(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask7(db,b), false);
  // (crule (pre) (scan temp6agl201 __t3hjJ13 t x) (body (let __t8K2W14 (lpush __t3hjJ13 x))) (head (emit-temp temp5nNz202 __t8K2W14 t)) lst_basic.slog:20 #f)
  class ReadTask10 : public slog::Task
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
      head_rel[0] = db->getRelation("temp5nNz202");
      outer_rel = db->getRelation("temp6agl201");
  
    }
    ReadTask10(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c14 = _prim_lpush(db, v_c13, v_c4);
        if (v_c14 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c14, v_c3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp6agl201", _fires);
  
      if (!_done)
      {
        ReadTask10* _cont = new ReadTask10(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask10(db,b), false);
  // (crule (pre) (scan temp5nNz202 __t8K2W14 t) (body (let __t29TL15 (lcat __t8K2W14 t))) (head (emit-temp temp7gtb203 __t29TL15)) lst_basic.slog:20 #f)
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
      head_rel[0] = db->getRelation("temp7gtb203");
      outer_rel = db->getRelation("temp5nNz202");
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        u64 v_c15 = _prim_lcat(db, v_c14, v_c3);
        if (v_c15 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c15});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp5nNz202", _fires);
  
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
      s->addTask(phase_read, new ReadTask11(db,b), false);
  // (crule (pre) (scan nan_result __erre88tG171 __errf5Pfj172 __errf15h7173 __errf9FTn174) (body) (head (emit error (0) __erre88tG171)) <internal>:1 #f)
  class ReadTask12 : public slog::Task
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
      std::vector<u16> ord13({0});
      slog::Relation* readrel14 = db->getRelation("error");
      head_index[0] = readrel14->getIndex(ord13, false);
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c16 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c19 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c16}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre (let _00024sqc2JpQ43 const5feceb66ffc86f38d952786c) (let __tconst27zf20 const6b86b273ff34fce19d6b804e)) (scan input _00024seq0) (body (letp _00024sql8hlD41 (aslst _00024seq0)) (let chk8BYc204 (llen _00024sql8hlD41)) (eq _00024sqc2JpQ43 chk8BYc204)) (head (emit isnil (0) __tconst27zf20)) lst_basic.slog:19 #f)
  class ReadTask15 : public slog::Task
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
      head_rel[0] = db->getRelation("isnil");
      std::vector<u16> ord16({0});
      slog::Relation* readrel17 = db->getRelation("isnil");
      head_index[0] = readrel17->getIndex(ord16, false);
      outer_rel = db->getRelation("input");
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const5feceb66ffc86f38d952786c;
      u64 v_c21 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        bool ok18 = true;
        u64 v_c23 = _prim_aslst(db, v_c22, &ok18);
        if (!ok18) return;
        u64 v_c24 = _prim_llen(db, v_c23);
        if (v_c24 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:19"); return; }
        if (v_c20 != v_c24) return;
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c21}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:19", "all:input", _fires);
  
      if (!_done)
      {
        ReadTask15* _cont = new ReadTask15(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), true);
  // (crule (pre (let _00024sqc7ski33 const6b86b273ff34fce19d6b804e) (let _00024sqc86ku34 const5feceb66ffc86f38d952786c) (let _00024sqc3nZa35 const6b86b273ff34fce19d6b804e) (let _00024sqc8AKk36 const5feceb66ffc86f38d952786c) (let __trid45Im54 const9a7407f3f7fd4c91ca5c2b75) (let __trel0ajt55 const5407225b6f80c82685351e93) (let __tcol16W856 const5feceb66ffc86f38d952786c)) (scan input _00024seq0) (body (letp _00024sql9AZ431 (aslst _00024seq0)) (let _00024sqn45UW32 (llen _00024sql9AZ431)) (cmp ge _00024sqn45UW32 _00024sqc7ski33) (letp x (lref _00024sql9AZ431 _00024sqc86ku34)) (let _00024sqp1idl37 (_0002d _00024sqn45UW32 _00024sqc8AKk36)) (let xs (lslice _00024sql9AZ431 _00024sqc3nZa35 _00024sqp1idl37))) (head (tycheck x (accept int) __trid45Im54 __trel0ajt55 __tcol16W856 (1 2 3 4 0)) (emit tails (0) xs) (emit heads (0) x)) lst_basic.slog:17 #f)
  class ReadTask19 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("tails");
      std::vector<u16> ord20({0});
      slog::Relation* readrel21 = db->getRelation("tails");
      head_index[1] = readrel21->getIndex(ord20, false);
      head_rel[2] = db->getRelation("heads");
      std::vector<u16> ord22({0});
      slog::Relation* readrel23 = db->getRelation("heads");
      head_index[2] = readrel23->getIndex(ord22, false);
      outer_rel = db->getRelation("input");
  
    }
    ReadTask19(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_const9a7407f3f7fd4c91ca5c2b75;
      u64 v_c30 = v_const5407225b6f80c82685351e93;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        bool ok24 = true;
        u64 v_c32 = _prim_aslst(db, v_c22, &ok24);
        if (!ok24) return;
        u64 v_c33 = _prim_llen(db, v_c32);
        if (v_c33 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:17"); return; }
        u64 v_c34 = _prim_ge(db, v_c33, v_c25);
        if (v_c34 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:17"); return; }
        if (!v_c34) return;
        bool ok26 = true;
        u64 v_c4 = _prim_lref(db, v_c32, v_c26, &ok26);
        if (!ok26) return;
        u64 v_c35 = _prim__0002d(db, v_c33, v_c28);
        if (v_c35 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:17"); return; }
        u64 v_c36 = _prim_lslice(db, v_c32, v_c27, v_c35);
        if (v_c36 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:17"); return; }
        ++_fires;
        if (!(is_int(v_c4)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c29, v_c30, v_c31, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c36}, std::array<u16,1>{0});
        slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("lst_basic.slog:17", "all:input", _fires);
  
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
      s->addTask(phase_read, new ReadTask19(db,b), true);
  // (crule (pre) (scan malformed_deduction __erre3tGq156 __errf0laX157 __errf2RDd158 __errf365K159 __errf09hB160) (body) (head (emit error (0) __erre3tGq156)) <internal>:1 #f)
  class ReadTask27 : public slog::Task
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
      std::vector<u16> ord28({0});
      slog::Relation* readrel29 = db->getRelation("error");
      head_index[0] = readrel29->getIndex(ord28, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c39 = _t[2];
        u64 v_c40 = _t[3];
        u64 v_c41 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c37}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask27* _cont = new ReadTask27(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask27(db,b), false);
  // (crule (pre) (scan temp7gtb203 __t29TL15) (body) (head (emit swapped (0) __t29TL15)) lst_basic.slog:20 #f)
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
      head_rel[0] = db->getRelation("swapped");
      std::vector<u16> ord31({0});
      slog::Relation* readrel32 = db->getRelation("swapped");
      head_index[0] = readrel32->getIndex(ord31, false);
      outer_rel = db->getRelation("temp7gtb203");
  
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
        u64 v_c15 = _t[0];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c15}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp7gtb203", _fires);
  
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
  // (crule (pre) (scan temp2uXG194 __t8K2W14 t) (body (let __t29TL15 (lcat __t8K2W14 t))) (head (emit-temp temp8fs7195 __t29TL15)) lst_basic.slog:20 #f)
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
      head_rel[0] = db->getRelation("temp8fs7195");
      outer_rel = db->getRelation("temp2uXG194");
  
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
        u64 v_c14 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c15 = _prim_lcat(db, v_c14, v_c3);
        if (v_c15 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c15});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp2uXG194", _fires);
  
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
  // (crule (pre) (scan temp8fs7195 __t29TL15) (body) (head (emit swapped (0) __t29TL15)) lst_basic.slog:20 #f)
  class ReadTask34 : public slog::Task
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
      head_rel[0] = db->getRelation("swapped");
      std::vector<u16> ord35({0});
      slog::Relation* readrel36 = db->getRelation("swapped");
      head_index[0] = readrel36->getIndex(ord35, false);
      outer_rel = db->getRelation("temp8fs7195");
  
    }
    ReadTask34(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[0];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c15}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp8fs7195", _fires);
  
      if (!_done)
      {
        ReadTask34* _cont = new ReadTask34(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask34(db,b), false);
  // (crule (pre) (scan int_overflow __erre4jCX167 __errf6DTW168 __errf1bh5169 __errf5Cnk170) (body) (head (emit error (0) __erre4jCX167)) <internal>:1 #f)
  class ReadTask37 : public slog::Task
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
      std::vector<u16> ord38({0});
      slog::Relation* readrel39 = db->getRelation("error");
      head_index[0] = readrel39->getIndex(ord38, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask37(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask37* _cont = new ReadTask37(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask37(db,b), false);
  // (crule (pre) (scan toint_range __erre99Bx175 __errf8lnV176 __errf6ah7177) (body) (head (emit error (0) __erre99Bx175)) <internal>:1 #f)
  class ReadTask40 : public slog::Task
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
      std::vector<u16> ord41({0});
      slog::Relation* readrel42 = db->getRelation("error");
      head_index[0] = readrel42->getIndex(ord41, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask40(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c46}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask40* _cont = new ReadTask40(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask40(db,b), false);
  // (crule (pre (let _00024sqc5na523 const6b86b273ff34fce19d6b804e) (let _00024sqc7UXE24 const5feceb66ffc86f38d952786c) (let _00024sqc9Y1225 const6b86b273ff34fce19d6b804e) (let _00024sqc3p0P26 const5feceb66ffc86f38d952786c) (let __t2Tnt11 (lempty))) (scan input _00024seq0) (body (join edge (0 1) 0 a b) (letp _00024sql1DCP21 (aslst _00024seq0)) (let _00024sqn8yhO22 (llen _00024sql1DCP21)) (cmp ge _00024sqn8yhO22 _00024sqc5na523) (letp x (lref _00024sql1DCP21 _00024sqc7UXE24)) (let _00024sqp3ANd27 (_0002d _00024sqn8yhO22 _00024sqc3p0P26)) (let t (lslice _00024sql1DCP21 _00024sqc9Y1225 _00024sqp3ANd27))) (head (emit-temp temp2i09191 __t2Tnt11 a b t x)) lst_basic.slog:20 #f)
  class ReadTask44 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** edgeindex43;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2i09191");
      outer_rel = db->getRelation("input");
      std::vector<u16> ord45({0, 1});
      slog::Relation* readrel46 = db->getRelation("edge");
      edgeindex43 = readrel46->getIndex(ord45, false);
  
    }
    ReadTask44(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c50 = v_const5feceb66ffc86f38d952786c;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_const5feceb66ffc86f38d952786c;
      u64 v_c0 = _prim_lempty(db);
      if (v_c0 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        slog::join_all<2>(edgeindex43, [&](const std::array<u64,2>& m47) {
          u64 v_c1 = m47[0]; u64 v_c2 = m47[1];
          bool ok48 = true;
          u64 v_c53 = _prim_aslst(db, v_c22, &ok48);
          if (!ok48) return;
          u64 v_c54 = _prim_llen(db, v_c53);
          if (v_c54 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
          u64 v_c55 = _prim_ge(db, v_c54, v_c49);
          if (v_c55 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
          if (!v_c55) return;
          bool ok50 = true;
          u64 v_c4 = _prim_lref(db, v_c53, v_c50, &ok50);
          if (!ok50) return;
          u64 v_c56 = _prim__0002d(db, v_c54, v_c52);
          if (v_c56 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
          u64 v_c3 = _prim_lslice(db, v_c53, v_c51, v_c56);
          if (v_c3 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
          ++_fires;
          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c0, v_c1, v_c2, v_c3, v_c4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "all:input", _fires);
  
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
      s->addTask(phase_read, new ReadTask44(db,b), true);
  // (crule (pre) (scan temp5uBz192 __t7Szu12 b t x) (body (let __t3hjJ13 (lpush __t7Szu12 b))) (head (emit-temp temp0h6Z193 __t3hjJ13 t x)) lst_basic.slog:20 #f)
  class ReadTask51 : public slog::Task
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
      head_rel[0] = db->getRelation("temp0h6Z193");
      outer_rel = db->getRelation("temp5uBz192");
  
    }
    ReadTask51(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c13 = _prim_lpush(db, v_c5, v_c2);
        if (v_c13 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c13, v_c3, v_c4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp5uBz192", _fires);
  
      if (!_done)
      {
        ReadTask51* _cont = new ReadTask51(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask51(db,b), false);
  // (crule (pre (let _00024sqc5UOD46 const6b86b273ff34fce19d6b804e) (let _00024sqc02aQ47 const5feceb66ffc86f38d952786c) (let _00024sqc1x8Z48 const6b86b273ff34fce19d6b804e) (let _00024sqc2r8d49 const5feceb66ffc86f38d952786c) (let __t2Tnt11 (lempty))) (scan input _00024seq0) (body (join edge (0 1) 0 b a) (letp _00024sql0Ssg44 (aslst _00024seq0)) (let _00024sqn56D145 (llen _00024sql0Ssg44)) (cmp ge _00024sqn56D145 _00024sqc5UOD46) (letp x (lref _00024sql0Ssg44 _00024sqc02aQ47)) (let _00024sqp7Cx450 (_0002d _00024sqn56D145 _00024sqc2r8d49)) (let t (lslice _00024sql0Ssg44 _00024sqc1x8Z48 _00024sqp7Cx450))) (head (emit-temp temp1jS4199 __t2Tnt11 a b t x)) lst_basic.slog:20 #f)
  class ReadTask53 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** edgeindex52;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1jS4199");
      outer_rel = db->getRelation("input");
      std::vector<u16> ord54({0, 1});
      slog::Relation* readrel55 = db->getRelation("edge");
      edgeindex52 = readrel55->getIndex(ord54, false);
  
    }
    ReadTask53(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
      u64 v_c0 = _prim_lempty(db);
      if (v_c0 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        slog::join_all<2>(edgeindex52, [&](const std::array<u64,2>& m56) {
          u64 v_c2 = m56[0]; u64 v_c1 = m56[1];
          bool ok57 = true;
          u64 v_c61 = _prim_aslst(db, v_c22, &ok57);
          if (!ok57) return;
          u64 v_c62 = _prim_llen(db, v_c61);
          if (v_c62 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
          u64 v_c63 = _prim_ge(db, v_c62, v_c57);
          if (v_c63 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
          if (!v_c63) return;
          bool ok59 = true;
          u64 v_c4 = _prim_lref(db, v_c61, v_c58, &ok59);
          if (!ok59) return;
          u64 v_c64 = _prim__0002d(db, v_c62, v_c60);
          if (v_c64 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
          u64 v_c3 = _prim_lslice(db, v_c61, v_c59, v_c64);
          if (v_c3 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
          ++_fires;
          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c0, v_c1, v_c2, v_c3, v_c4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "all:input", _fires);
  
      if (!_done)
      {
        ReadTask53* _cont = new ReadTask53(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask53(db,b), true);
  // (crule (pre (let __tconst7OaZ16 const5feceb66ffc86f38d952786c) (let __t38vi17 (lempty))) (scan input l) (body) (head (emit-temp temp0NEd196 __t38vi17 l)) lst_basic.slog:18 #f)
  class ReadTask60 : public slog::Task
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
      head_rel[0] = db->getRelation("temp0NEd196");
      outer_rel = db->getRelation("input");
  
    }
    ReadTask60(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = v_const5feceb66ffc86f38d952786c;
      u64 v_c66 = _prim_lempty(db);
      if (v_c66 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:18"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c67 = _t[0];
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c66, v_c67});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:18", "all:input", _fires);
  
      if (!_done)
      {
        ReadTask60* _cont = new ReadTask60(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask60(db,b), true);
  // (crule (pre) (scan temp3pOB197 __t542h18 l) (body (let __t8IBj19 (lcat __t542h18 l))) (head (emit-temp temp5amt198 __t8IBj19)) lst_basic.slog:18 #f)
  class ReadTask61 : public slog::Task
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
      head_rel[0] = db->getRelation("temp5amt198");
      outer_rel = db->getRelation("temp3pOB197");
  
    }
    ReadTask61(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c68 = _t[0];
        u64 v_c67 = _t[1];
        u64 v_c9 = _prim_lcat(db, v_c68, v_c67);
        if (v_c9 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:18"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c9});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:18", "delta:temp3pOB197", _fires);
  
      if (!_done)
      {
        ReadTask61* _cont = new ReadTask61(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask61(db,b), false);
  // (crule (pre) (scan temp5Hoh200 __t7Szu12 b t x) (body (let __t3hjJ13 (lpush __t7Szu12 b))) (head (emit-temp temp6agl201 __t3hjJ13 t x)) lst_basic.slog:20 #f)
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
      head_rel[0] = db->getRelation("temp6agl201");
      outer_rel = db->getRelation("temp5Hoh200");
  
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
        u64 v_c5 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c13 = _prim_lpush(db, v_c5, v_c2);
        if (v_c13 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c13, v_c3, v_c4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp5Hoh200", _fires);
  
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
  // (crule (pre (let __tconst7OaZ16 const5feceb66ffc86f38d952786c)) (scan temp0NEd196 __t38vi17 l) (body (let __t542h18 (lpush __t38vi17 __tconst7OaZ16))) (head (emit-temp temp3pOB197 __t542h18 l)) lst_basic.slog:18 #f)
  class ReadTask63 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3pOB197");
      outer_rel = db->getRelation("temp0NEd196");
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c68 = _prim_lpush(db, v_c66, v_c65);
        if (v_c68 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:18"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c68, v_c67});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:18", "delta:temp0NEd196", _fires);
  
      if (!_done)
      {
        ReadTask63* _cont = new ReadTask63(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask63(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre0nLj188 __errf4laK189 __errf0feo190) (body) (head (emit error (0) __erre0nLj188)) <internal>:1 #f)
  class ReadTask64 : public slog::Task
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
      std::vector<u16> ord65({0});
      slog::Relation* readrel66 = db->getRelation("error");
      head_index[0] = readrel66->getIndex(ord65, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask64(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c69 = _t[0];
        u64 v_c70 = _t[1];
        u64 v_c71 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c69}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask64* _cont = new ReadTask64(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask64(db,b), false);
  // (crule (pre) (scan temp1jS4199 __t2Tnt11 a b t x) (body (let __t7Szu12 (lpush __t2Tnt11 a))) (head (emit-temp temp5Hoh200 __t7Szu12 b t x)) lst_basic.slog:20 #f)
  class ReadTask67 : public slog::Task
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
      head_rel[0] = db->getRelation("temp5Hoh200");
      outer_rel = db->getRelation("temp1jS4199");
  
    }
    ReadTask67(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _prim_lpush(db, v_c0, v_c1);
        if (v_c5 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
        ++_fires;
        slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c5, v_c2, v_c3, v_c4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp1jS4199", _fires);
  
      if (!_done)
      {
        ReadTask67* _cont = new ReadTask67(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask67(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre7oxQ183 __errf6yjj184 __errf263B185 __errf4ucK186 __errf3xAW187) (body) (head (emit error (0) __erre7oxQ183)) <internal>:1 #f)
  class ReadTask68 : public slog::Task
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
      std::vector<u16> ord69({0});
      slog::Relation* readrel70 = db->getRelation("error");
      head_index[0] = readrel70->getIndex(ord69, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask68(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c72 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c74 = _t[2];
        u64 v_c75 = _t[3];
        u64 v_c76 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c72}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask68* _cont = new ReadTask68(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask68(db,b), false);
  // (crule (pre) (scan type_mismatch __erre2AGy178 __errf7x1k179 __errf8L8M180 __errf4av9181 __errf4qT3182) (body) (head (emit error (0) __erre2AGy178)) <internal>:1 #f)
  class ReadTask71 : public slog::Task
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
      std::vector<u16> ord72({0});
      slog::Relation* readrel73 = db->getRelation("error");
      head_index[0] = readrel73->getIndex(ord72, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask71(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c77 = _t[0];
        u64 v_c78 = _t[1];
        u64 v_c79 = _t[2];
        u64 v_c80 = _t[3];
        u64 v_c81 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c77}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask71* _cont = new ReadTask71(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask71(db,b), false);
  // (crule (pre) (scan temp0h6Z193 __t3hjJ13 t x) (body (let __t8K2W14 (lpush __t3hjJ13 x))) (head (emit-temp temp2uXG194 __t8K2W14 t)) lst_basic.slog:20 #f)
  class ReadTask74 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2uXG194");
      outer_rel = db->getRelation("temp0h6Z193");
  
    }
    ReadTask74(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c14 = _prim_lpush(db, v_c13, v_c4);
        if (v_c14 == slog_error) { slog::emit_pending_error(db, "lst_basic.slog:20"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c14, v_c3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_basic.slog:20", "delta:temp0h6Z193", _fires);
  
      if (!_done)
      {
        ReadTask74* _cont = new ReadTask74(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask74(db,b), false);
  s->addReadRel("div_by_zero");
  s->addReadRel("edge");
  s->addReadRel("input");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp0NEd196");
  s->addReadRel("temp0h6Z193");
  s->addReadRel("temp1jS4199");
  s->addReadRel("temp2i09191");
  s->addReadRel("temp2uXG194");
  s->addReadRel("temp3pOB197");
  s->addReadRel("temp5Hoh200");
  s->addReadRel("temp5amt198");
  s->addReadRel("temp5nNz202");
  s->addReadRel("temp5uBz192");
  s->addReadRel("temp6agl201");
  s->addReadRel("temp7gtb203");
  s->addReadRel("temp8fs7195");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("built");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("heads");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("isnil");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("swapped");
  s->addDynamicRel("tails");
  s->addDynamicRel("temp0NEd196");
  s->addDynamicRel("temp0h6Z193");
  s->addDynamicRel("temp1jS4199");
  s->addDynamicRel("temp2i09191");
  s->addDynamicRel("temp2uXG194");
  s->addDynamicRel("temp3pOB197");
  s->addDynamicRel("temp5Hoh200");
  s->addDynamicRel("temp5amt198");
  s->addDynamicRel("temp5nNz202");
  s->addDynamicRel("temp5uBz192");
  s->addDynamicRel("temp6agl201");
  s->addDynamicRel("temp7gtb203");
  s->addDynamicRel("temp8fs7195");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  d->push(s);
  d->continueRun();
}

