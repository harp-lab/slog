
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const66804d12743756eb85fb3115;
u64 v_const57cb45de78dd46c657524688;
u64 v_const43e6e2bebb3774311cf0c867;
u64 v_const46a3ae93aa7a8b988080d6c9;
u64 v_consted725292f5f32d61535958c1;
u64 v_const7297d2085ea0adffc396d546;
u64 v_const2c8b6d4a8b88a4444dd3bdd5;
u64 v_constc9216a4bb2623d4056d2c458;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("db56f3e3");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const66804d12743756eb85fb3115 = db->encodeString("F");
  v_const57cb45de78dd46c657524688 = db->encodeString("T");
  v_const43e6e2bebb3774311cf0c867 = db->encodeString("E");
  v_const46a3ae93aa7a8b988080d6c9 = db->encodeString("n");
  v_consted725292f5f32d61535958c1 = db->encodeString("*");
  v_const7297d2085ea0adffc396d546 = db->encodeString("+");
  v_const2c8b6d4a8b88a4444dd3bdd5 = db->encodeString("(");
  v_constc9216a4bb2623d4056d2c458 = db->encodeString(")");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord189({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord190({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("tok");
  if (r == 0) db->addRelation("tok", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("tok");
      std::vector<u16> ord191({1, 0});
    
    r->addIndex<2>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord192({1, 0});
    
    r->addIndex<2>(ord192, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("tok"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord193({1, 2, 0});
    
    r->addIndex<3>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord194({0, 1, 2});
    
    r->addIndex<3>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp6Ucm219");
  if (r == 0) db->addTempRelation("temp6Ucm219", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp0RY0222");
  if (r == 0) db->addTempRelation("temp0RY0222", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord195({1, 2, 0});
    
    r->addIndex<3>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord196({0, 1, 2});
    
    r->addIndex<3>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("parse_ans");
  if (r == 0) db->addRelation("parse_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("parse_ans");
      std::vector<u16> ord197({0, 1});
    
    r->addIndex<2>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord198({1, 0});
    
    r->addIndex<2>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord199({1, 0});
    
    r->addIndex<2>(ord199, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("parse_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("parse");
  if (r == 0) db->addStruct("parse", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("parse");
      std::vector<u16> ord200({1, 2, 0});
    
    r->addIndex<3>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord201({0, 1, 2});
    
    r->addIndex<3>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("parse"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord202({1, 2, 3, 0});
    
    r->addIndex<4>(ord202, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord203({0, 1, 2, 3});
    
    r->addIndex<4>(ord203, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord204({1, 2, 0});
    
    r->addIndex<3>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord205({0, 1, 2});
    
    r->addIndex<3>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord206({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord207({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord208({1, 2, 0});
    
    r->addIndex<3>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord209({0, 1, 2});
    
    r->addIndex<3>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord210({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord210, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord211({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord211, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("len");
  if (r == 0) db->addRelation("len", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("len");
      std::vector<u16> ord212({0});
    
    r->addIndex<1>(ord212, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("len"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord213({1, 2, 3, 0});
    
    r->addIndex<4>(ord213, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord214({0, 1, 2, 3});
    
    r->addIndex<4>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord215({0});
    
    r->addIndex<1>(ord215, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord216({1, 2, 0});
    
    r->addIndex<3>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord217({0, 1, 2});
    
    r->addIndex<3>(ord217, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("accepted");
  if (r == 0) db->addRelation("accepted", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("accepted");
      std::vector<u16> ord218({0});
    
    r->addIndex<1>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("accepted"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord219({1, 0});
    
    r->addIndex<2>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord220({0, 1});
    
    r->addIndex<2>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst9Vwc8 const57cb45de78dd46c657524688) (let __tconst064z6 const6b86b273ff34fce19d6b804e) (let __tconst1oz95 const7297d2085ea0adffc396d546) (let __tconst2Ruz3 const43e6e2bebb3774311cf0c867)) (scan parse_ans __t9LpQ2 j) (body (join tok (1 0) 2 __tconst1oz95 j) (exists parse (1 2 0) 1 __tconst9Vwc8) (join parse (0 1 2) 2 __t9LpQ2 __tconst2Ruz3 i) (let __t0SA07 (_0002b j __tconst064z6)) (join parse (1 2 0) 2 __tconst9Vwc8 __t0SA07 __t2vLD9) (join parse_ans (0 1) 1 __t2vLD9 k)) (head (emit parse_ans (0 1) __t9LpQ2 k)) dem_parse.slog:16 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tokindex0;  slog::Index** parseindex1;  slog::Index** parseindex2;  slog::Index** parseindex3;  slog::Index** parse_ansindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse_ans");
      std::vector<u16> ord6({0, 1});
      slog::Relation* readrel7 = db->getRelation("parse_ans");
      head_index[0] = readrel7->getIndex(ord6, false);
      outer_rel = db->getRelation("parse_ans");
      std::vector<u16> ord8({1, 0});
      slog::Relation* readrel9 = db->getRelation("tok");
      tokindex0 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 2, 0});
      slog::Relation* readrel11 = db->getRelation("parse");
      parseindex1 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({0, 1, 2});
      slog::Relation* readrel13 = db->getRelation("parse");
      parseindex2 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 2, 0});
      slog::Relation* readrel15 = db->getRelation("parse");
      parseindex3 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({0, 1});
      slog::Relation* readrel17 = db->getRelation("parse_ans");
      parse_ansindex4 = readrel17->getIndex(ord16, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const57cb45de78dd46c657524688;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_const7297d2085ea0adffc396d546;
      u64 v_c3 = v_const43e6e2bebb3774311cf0c867;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<2,2>(tokindex0, std::array<u64,2>{v_c2, v_c5}, [&](const std::array<u64,2>& m18) {
          if (!slog::exists_probe<3,1>(parseindex1, std::array<u64,3>{v_c0, 0, 0})) return;
          slog::join_probe<3,2>(parseindex2, std::array<u64,3>{v_c4, v_c3, 0}, [&](const std::array<u64,3>& m19) {
            u64 v_c6 = m19[2];
            u64 v_c7 = _prim__0002b(db, v_c5, v_c1);
            if (v_c7 == slog_error) { slog::emit_pending_error(db, "dem_parse.slog:16"); return; }
            slog::join_probe<3,2>(parseindex3, std::array<u64,3>{v_c0, v_c7, 0}, [&](const std::array<u64,3>& m20) {
              u64 v_c8 = m20[2];
              slog::join_probe<2,1>(parse_ansindex4, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m21) {
                u64 v_c9 = m21[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c9}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:16", "delta:parse_ans", _fires);
  
      if (!_done)
      {
        ReadTask5* _cont = new ReadTask5(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), false);
  // (crule (pre (let __tconst1Dlv34 const66804d12743756eb85fb3115) (let __tconst04UH32 const6b86b273ff34fce19d6b804e) (let __tconst9i2K31 consted725292f5f32d61535958c1) (let __tconst2Jgp29 const57cb45de78dd46c657524688)) (scan parse_ans __t6XPr35 k) (body (exists tok (1 0) 1 __tconst9i2K31) (exists parse (1 2 0) 1 __tconst2Jgp29) (join parse (0 1 2) 2 __t6XPr35 __tconst1Dlv34 __t85cA33) (join tok (1 0) 1 __tconst9i2K31 j) (join-old parse_ans (1 0) 1 (1 0) j __t8jyV28) (join parse (0 1 2) 2 __t8jyV28 __tconst2Jgp29 i) (let chk1DUj221 (_0002b j __tconst04UH32)) (eq __t85cA33 chk1DUj221)) (head (emit parse_ans (0 1) __t8jyV28 k)) dem_parse.slog:20 #f)
  class ReadTask29 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tokindex22;  slog::Index** parseindex23;  slog::Index** parseindex24;  slog::Index** tokindex25;  slog::Index** parse_ansindex26;  slog::Index** parseindex27;  slog::Index** parse_ansdelta28;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse_ans");
      std::vector<u16> ord30({0, 1});
      slog::Relation* readrel31 = db->getRelation("parse_ans");
      head_index[0] = readrel31->getIndex(ord30, false);
      outer_rel = db->getRelation("parse_ans");
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("tok");
      tokindex22 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 2, 0});
      slog::Relation* readrel35 = db->getRelation("parse");
      parseindex23 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({0, 1, 2});
      slog::Relation* readrel37 = db->getRelation("parse");
      parseindex24 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 0});
      slog::Relation* readrel39 = db->getRelation("tok");
      tokindex25 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 0});
      slog::Relation* readrel41 = db->getRelation("parse_ans");
      parse_ansindex26 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 0});
      slog::Relation* readrel43 = db->getRelation("parse_ans");
      parse_ansdelta28 = readrel43->getIndex(ord42, true);
      std::vector<u16> ord44({0, 1, 2});
      slog::Relation* readrel45 = db->getRelation("parse");
      parseindex27 = readrel45->getIndex(ord44, false);
  
    }
    ReadTask29(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_const66804d12743756eb85fb3115;
      u64 v_c11 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c12 = v_consted725292f5f32d61535958c1;
      u64 v_c13 = v_const57cb45de78dd46c657524688;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c14 = _t[0];
        u64 v_c9 = _t[1];
        if (!slog::exists_probe<2,1>(tokindex22, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<3,1>(parseindex23, std::array<u64,3>{v_c13, 0, 0})) return;
        slog::join_probe<3,2>(parseindex24, std::array<u64,3>{v_c14, v_c10, 0}, [&](const std::array<u64,3>& m46) {
          u64 v_c15 = m46[2];
          slog::join_probe<2,1>(tokindex25, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m47) {
            u64 v_c5 = m47[1];
            slog::join_probe_old<2,1>(parse_ansindex26, parse_ansdelta28, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m48) {
              u64 v_c16 = m48[1];
              slog::join_probe<3,2>(parseindex27, std::array<u64,3>{v_c16, v_c13, 0}, [&](const std::array<u64,3>& m49) {
                u64 v_c6 = m49[2];
                u64 v_c17 = _prim__0002b(db, v_c5, v_c11);
                if (v_c17 == slog_error) { slog::emit_pending_error(db, "dem_parse.slog:20"); return; }
                if (v_c15 != v_c17) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c9}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:20", "delta:parse_ans", _fires);
  
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
  // (crule (pre) (scan temp0RY0222 __t1rI525 __t9B3e23) (body) (head (emit parse_ans (0 1) __t1rI525 __t9B3e23)) dem_parse.slog:24 #f)
  class ReadTask50 : public slog::Task
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
      head_rel[0] = db->getRelation("parse_ans");
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("parse_ans");
      head_index[0] = readrel52->getIndex(ord51, false);
      outer_rel = db->getRelation("temp0RY0222");
  
    }
    ReadTask50(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c18, v_c19}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:24", "delta:temp0RY0222", _fires);
  
      if (!_done)
      {
        ReadTask50* _cont = new ReadTask50(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask50(db,b), false);
  // (crule (pre) (scan type_mismatch __erre0AOA206 __errf0OTQ207 __errf1YN3208 __errf0kuz209 __errf7Pnb210) (body) (head (emit error (0) __erre0AOA206)) <internal>:1 #f)
  class ReadTask53 : public slog::Task
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
      std::vector<u16> ord54({0});
      slog::Relation* readrel55 = db->getRelation("error");
      head_index[0] = readrel55->getIndex(ord54, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask53(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c22 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c24 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c20}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
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
      s->addTask(phase_read, new ReadTask53(db,b), false);
  // (crule (pre) (scan temp6Ucm219 __t4XP872 __t842C74) (body) (head (emit parse_ans (0 1) __t842C74 __t4XP872)) dem_parse.slog:25 #f)
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
      head_rel[0] = db->getRelation("parse_ans");
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("parse_ans");
      head_index[0] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("temp6Ucm219");
  
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
        u64 v_c25 = _t[0];
        u64 v_c26 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c26, v_c25}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:25", "delta:temp6Ucm219", _fires);
  
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
  // (crule (pre) (scan toint_range __erre7N3G203 __errf1Dh6204 __errf6OPB205) (body) (head (emit error (0) __erre7N3G203)) <internal>:1 #f)
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
      outer_rel = db->getRelation("toint_range");
  
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
        u64 v_c27 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c29 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
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
  // (crule (pre) (scan mpz_overflow __erre72GQ211 __errf5Cw8212 __errf0Isc213 __errf06sr214 __errf8vSm215) (body) (head (emit error (0) __erre72GQ211)) <internal>:1 #f)
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
      outer_rel = db->getRelation("mpz_overflow");
  
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
        u64 v_c30 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c32 = _t[2];
        u64 v_c33 = _t[3];
        u64 v_c34 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c30}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
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
  // (crule (pre (let __tconst9lyh36 const57cb45de78dd46c657524688) (let __tconst6uPN38 const66804d12743756eb85fb3115)) (scan parse_ans __t9PVs39 j) (body (exists parse (1 2 0) 1 __tconst9lyh36) (join parse (0 1 2) 2 __t9PVs39 __tconst6uPN38 i) (join parse (1 2 0) 2 __tconst9lyh36 i __t4cXZ37)) (head (emit parse_ans (0 1) __t4cXZ37 j)) dem_parse.slog:21 #f)
  class ReadTask68 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** parseindex65;  slog::Index** parseindex66;  slog::Index** parseindex67;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse_ans");
      std::vector<u16> ord69({0, 1});
      slog::Relation* readrel70 = db->getRelation("parse_ans");
      head_index[0] = readrel70->getIndex(ord69, false);
      outer_rel = db->getRelation("parse_ans");
      std::vector<u16> ord71({1, 2, 0});
      slog::Relation* readrel72 = db->getRelation("parse");
      parseindex65 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({0, 1, 2});
      slog::Relation* readrel74 = db->getRelation("parse");
      parseindex66 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 2, 0});
      slog::Relation* readrel76 = db->getRelation("parse");
      parseindex67 = readrel76->getIndex(ord75, false);
  
    }
    ReadTask68(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c35 = v_const57cb45de78dd46c657524688;
      u64 v_c36 = v_const66804d12743756eb85fb3115;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c5 = _t[1];
        if (!slog::exists_probe<3,1>(parseindex65, std::array<u64,3>{v_c35, 0, 0})) return;
        slog::join_probe<3,2>(parseindex66, std::array<u64,3>{v_c37, v_c36, 0}, [&](const std::array<u64,3>& m77) {
          u64 v_c6 = m77[2];
          slog::join_probe<3,2>(parseindex67, std::array<u64,3>{v_c35, v_c6, 0}, [&](const std::array<u64,3>& m78) {
            u64 v_c38 = m78[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c38, v_c5}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:21", "delta:parse_ans", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre2XQv192 __errf3ieJ193 __errf820p194) (body) (head (emit error (0) __erre2XQv192)) <internal>:1 #f)
  class ReadTask79 : public slog::Task
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
      std::vector<u16> ord80({0});
      slog::Relation* readrel81 = db->getRelation("error");
      head_index[0] = readrel81->getIndex(ord80, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask79(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask79* _cont = new ReadTask79(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask79(db,b), false);
  // (crule (pre (let __tconst9Vwc8 const57cb45de78dd46c657524688) (let __tconst064z6 const6b86b273ff34fce19d6b804e) (let __tconst1oz95 const7297d2085ea0adffc396d546) (let __tconst2Ruz3 const43e6e2bebb3774311cf0c867)) (scan parse_ans __t2vLD9 k) (body (exists tok (1 0) 1 __tconst1oz95) (exists parse (1 2 0) 1 __tconst2Ruz3) (join parse (0 1 2) 2 __t2vLD9 __tconst9Vwc8 __t0SA07) (join tok (1 0) 1 __tconst1oz95 j) (join-old parse_ans (1 0) 1 (1 0) j __t9LpQ2) (join parse (0 1 2) 2 __t9LpQ2 __tconst2Ruz3 i) (let chk7nU8223 (_0002b j __tconst064z6)) (eq __t0SA07 chk7nU8223)) (head (emit parse_ans (0 1) __t9LpQ2 k)) dem_parse.slog:16 #f)
  class ReadTask89 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tokindex82;  slog::Index** parseindex83;  slog::Index** parseindex84;  slog::Index** tokindex85;  slog::Index** parse_ansindex86;  slog::Index** parseindex87;  slog::Index** parse_ansdelta88;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse_ans");
      std::vector<u16> ord90({0, 1});
      slog::Relation* readrel91 = db->getRelation("parse_ans");
      head_index[0] = readrel91->getIndex(ord90, false);
      outer_rel = db->getRelation("parse_ans");
      std::vector<u16> ord92({1, 0});
      slog::Relation* readrel93 = db->getRelation("tok");
      tokindex82 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 2, 0});
      slog::Relation* readrel95 = db->getRelation("parse");
      parseindex83 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({0, 1, 2});
      slog::Relation* readrel97 = db->getRelation("parse");
      parseindex84 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 0});
      slog::Relation* readrel99 = db->getRelation("tok");
      tokindex85 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 0});
      slog::Relation* readrel101 = db->getRelation("parse_ans");
      parse_ansindex86 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 0});
      slog::Relation* readrel103 = db->getRelation("parse_ans");
      parse_ansdelta88 = readrel103->getIndex(ord102, true);
      std::vector<u16> ord104({0, 1, 2});
      slog::Relation* readrel105 = db->getRelation("parse");
      parseindex87 = readrel105->getIndex(ord104, false);
  
    }
    ReadTask89(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const57cb45de78dd46c657524688;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_const7297d2085ea0adffc396d546;
      u64 v_c3 = v_const43e6e2bebb3774311cf0c867;
  
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
        if (!slog::exists_probe<2,1>(tokindex82, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,1>(parseindex83, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<3,2>(parseindex84, std::array<u64,3>{v_c8, v_c0, 0}, [&](const std::array<u64,3>& m106) {
          u64 v_c7 = m106[2];
          slog::join_probe<2,1>(tokindex85, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m107) {
            u64 v_c5 = m107[1];
            slog::join_probe_old<2,1>(parse_ansindex86, parse_ansdelta88, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m108) {
              u64 v_c4 = m108[1];
              slog::join_probe<3,2>(parseindex87, std::array<u64,3>{v_c4, v_c3, 0}, [&](const std::array<u64,3>& m109) {
                u64 v_c6 = m109[2];
                u64 v_c42 = _prim__0002b(db, v_c5, v_c1);
                if (v_c42 == slog_error) { slog::emit_pending_error(db, "dem_parse.slog:16"); return; }
                if (v_c7 != v_c42) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c9}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:16", "delta:parse_ans", _fires);
  
      if (!_done)
      {
        ReadTask89* _cont = new ReadTask89(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask89(db,b), false);
  // (crule (pre) (scan nan_result __erre5tuB199 __errf5D7N200 __errf439k201 __errf3wHa202) (body) (head (emit error (0) __erre5tuB199)) <internal>:1 #f)
  class ReadTask110 : public slog::Task
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
      std::vector<u16> ord111({0});
      slog::Relation* readrel112 = db->getRelation("error");
      head_index[0] = readrel112->getIndex(ord111, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask110(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c45 = _t[2];
        u64 v_c46 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c43}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask110* _cont = new ReadTask110(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask110(db,b), false);
  // (crule (pre (let __tconst1Dlv34 const66804d12743756eb85fb3115) (let __tconst04UH32 const6b86b273ff34fce19d6b804e) (let __tconst9i2K31 consted725292f5f32d61535958c1) (let __tconst2Jgp29 const57cb45de78dd46c657524688)) (scan parse_ans __t8jyV28 j) (body (join tok (1 0) 2 __tconst9i2K31 j) (exists parse (1 2 0) 1 __tconst1Dlv34) (join parse (0 1 2) 2 __t8jyV28 __tconst2Jgp29 i) (let __t85cA33 (_0002b j __tconst04UH32)) (join parse (1 2 0) 2 __tconst1Dlv34 __t85cA33 __t6XPr35) (join parse_ans (0 1) 1 __t6XPr35 k)) (head (emit parse_ans (0 1) __t8jyV28 k)) dem_parse.slog:20 #f)
  class ReadTask118 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tokindex113;  slog::Index** parseindex114;  slog::Index** parseindex115;  slog::Index** parseindex116;  slog::Index** parse_ansindex117;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse_ans");
      std::vector<u16> ord119({0, 1});
      slog::Relation* readrel120 = db->getRelation("parse_ans");
      head_index[0] = readrel120->getIndex(ord119, false);
      outer_rel = db->getRelation("parse_ans");
      std::vector<u16> ord121({1, 0});
      slog::Relation* readrel122 = db->getRelation("tok");
      tokindex113 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 0});
      slog::Relation* readrel124 = db->getRelation("parse");
      parseindex114 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({0, 1, 2});
      slog::Relation* readrel126 = db->getRelation("parse");
      parseindex115 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({1, 2, 0});
      slog::Relation* readrel128 = db->getRelation("parse");
      parseindex116 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("parse_ans");
      parse_ansindex117 = readrel130->getIndex(ord129, false);
  
    }
    ReadTask118(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_const66804d12743756eb85fb3115;
      u64 v_c11 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c12 = v_consted725292f5f32d61535958c1;
      u64 v_c13 = v_const57cb45de78dd46c657524688;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c16 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<2,2>(tokindex113, std::array<u64,2>{v_c12, v_c5}, [&](const std::array<u64,2>& m131) {
          if (!slog::exists_probe<3,1>(parseindex114, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe<3,2>(parseindex115, std::array<u64,3>{v_c16, v_c13, 0}, [&](const std::array<u64,3>& m132) {
            u64 v_c6 = m132[2];
            u64 v_c15 = _prim__0002b(db, v_c5, v_c11);
            if (v_c15 == slog_error) { slog::emit_pending_error(db, "dem_parse.slog:20"); return; }
            slog::join_probe<3,2>(parseindex116, std::array<u64,3>{v_c10, v_c15, 0}, [&](const std::array<u64,3>& m133) {
              u64 v_c14 = m133[2];
              slog::join_probe<2,1>(parse_ansindex117, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m134) {
                u64 v_c9 = m134[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c9}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:20", "delta:parse_ans", _fires);
  
      if (!_done)
      {
        ReadTask118* _cont = new ReadTask118(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask118(db,b), false);
  // (crule (pre (let __tconst9f5324 const66804d12743756eb85fb3115) (let __tconst7EwW26 const46a3ae93aa7a8b988080d6c9) (let __tconst2oLd22 const6b86b273ff34fce19d6b804e)) (probe tok (1 0) 1 __tconst7EwW26 i) (body (join parse (1 2 0) 2 __tconst9f5324 i __t1rI525) (let __t9B3e23 (_0002b i __tconst2oLd22))) (head (emit-temp temp0RY0222 __t1rI525 __t9B3e23)) dem_parse.slog:24 #f)
  class ReadTask136 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** parseindex135;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0RY0222");
      std::vector<u16> ord137({1, 0});
      slog::Relation* readrel138 = db->getRelation("tok");
      driver_index = readrel138->getIndex(ord137, true);
      std::vector<u16> ord139({1, 2, 0});
      slog::Relation* readrel140 = db->getRelation("parse");
      parseindex135 = readrel140->getIndex(ord139, false);
  
    }
    ReadTask136(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_const66804d12743756eb85fb3115;
      u64 v_c48 = v_const46a3ae93aa7a8b988080d6c9;
      u64 v_c49 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c48, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m141) {
        u64 v_c6 = m141[1];
        if (buckethash(v_c6) != bucket) return;
        slog::join_probe<3,2>(parseindex135, std::array<u64,3>{v_c47, v_c6, 0}, [&](const std::array<u64,3>& m142) {
          u64 v_c18 = m142[2];
          u64 v_c19 = _prim__0002b(db, v_c6, v_c49);
          if (v_c19 == slog_error) { slog::emit_pending_error(db, "dem_parse.slog:24"); return; }
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c18, v_c19});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:24", "all:tok", _fires);
  
      if (!_done)
      {
        ReadTask136* _cont = new ReadTask136(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask136(db,b), true);
  // (crule (pre) (scan mpz_table_overflow __erre4yL7216 __errf52VQ217 __errf9mt9218) (body) (head (emit error (0) __erre4yL7216)) <internal>:1 #f)
  class ReadTask143 : public slog::Task
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
      std::vector<u16> ord144({0});
      slog::Relation* readrel145 = db->getRelation("error");
      head_index[0] = readrel145->getIndex(ord144, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask143(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c50}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask143* _cont = new ReadTask143(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask143(db,b), false);
  // (crule (pre) (scan int_overflow __erre9KLO195 __errf9yjI196 __errf1cbP197 __errf0Qvt198) (body) (head (emit error (0) __erre9KLO195)) <internal>:1 #f)
  class ReadTask146 : public slog::Task
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
      std::vector<u16> ord147({0});
      slog::Relation* readrel148 = db->getRelation("error");
      head_index[0] = readrel148->getIndex(ord147, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask146(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c53 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c55 = _t[2];
        u64 v_c56 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask146* _cont = new ReadTask146(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask146(db,b), false);
  // (crule (pre) (scan div_by_zero __erre5fSE189 __errf4yW9190 __errf29Nu191) (body) (head (emit error (0) __erre5fSE189)) <internal>:1 #f)
  class ReadTask149 : public slog::Task
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
      std::vector<u16> ord150({0});
      slog::Relation* readrel151 = db->getRelation("error");
      head_index[0] = readrel151->getIndex(ord150, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask149(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c59 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask149* _cont = new ReadTask149(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask149(db,b), false);
  // (crule (pre (let __tconst3UMo73 const66804d12743756eb85fb3115) (let __tconst8HVN75 const2c8b6d4a8b88a4444dd3bdd5) (let __tconst1zhQ76 const6b86b273ff34fce19d6b804e) (let __tconst4m0Q78 const43e6e2bebb3774311cf0c867) (let __tconst4Y1x80 constc9216a4bb2623d4056d2c458)) (scan parse_ans __t4a8279 j) (body (join tok (1 0) 2 __tconst4Y1x80 j) (exists tok (1 0) 1 __tconst8HVN75) (exists parse (1 2 0) 1 __tconst3UMo73) (join parse (0 1 2) 2 __t4a8279 __tconst4m0Q78 __t0ak277) (join tok (1 0) 1 __tconst8HVN75 i) (join parse (1 2 0) 2 __tconst3UMo73 i __t842C74) (let chk9joH220 (_0002b i __tconst1zhQ76)) (eq __t0ak277 chk9joH220) (let __t4XP872 (_0002b j __tconst1zhQ76))) (head (emit-temp temp6Ucm219 __t4XP872 __t842C74)) dem_parse.slog:25 #f)
  class ReadTask158 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tokindex152;  slog::Index** tokindex153;  slog::Index** parseindex154;  slog::Index** parseindex155;  slog::Index** tokindex156;  slog::Index** parseindex157;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6Ucm219");
      outer_rel = db->getRelation("parse_ans");
      std::vector<u16> ord159({1, 0});
      slog::Relation* readrel160 = db->getRelation("tok");
      tokindex152 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 0});
      slog::Relation* readrel162 = db->getRelation("tok");
      tokindex153 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 0});
      slog::Relation* readrel164 = db->getRelation("parse");
      parseindex154 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({0, 1, 2});
      slog::Relation* readrel166 = db->getRelation("parse");
      parseindex155 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("tok");
      tokindex156 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("parse");
      parseindex157 = readrel170->getIndex(ord169, false);
  
    }
    ReadTask158(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c60 = v_const66804d12743756eb85fb3115;
      u64 v_c61 = v_const2c8b6d4a8b88a4444dd3bdd5;
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c63 = v_const43e6e2bebb3774311cf0c867;
      u64 v_c64 = v_constc9216a4bb2623d4056d2c458;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c65 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<2,2>(tokindex152, std::array<u64,2>{v_c64, v_c5}, [&](const std::array<u64,2>& m171) {
          if (!slog::exists_probe<2,1>(tokindex153, std::array<u64,2>{v_c61, 0})) return;
          if (!slog::exists_probe<3,1>(parseindex154, std::array<u64,3>{v_c60, 0, 0})) return;
          slog::join_probe<3,2>(parseindex155, std::array<u64,3>{v_c65, v_c63, 0}, [&](const std::array<u64,3>& m172) {
            u64 v_c66 = m172[2];
            slog::join_probe<2,1>(tokindex156, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m173) {
              u64 v_c6 = m173[1];
              slog::join_probe<3,2>(parseindex157, std::array<u64,3>{v_c60, v_c6, 0}, [&](const std::array<u64,3>& m174) {
                u64 v_c26 = m174[2];
                u64 v_c67 = _prim__0002b(db, v_c6, v_c62);
                if (v_c67 == slog_error) { slog::emit_pending_error(db, "dem_parse.slog:25"); return; }
                if (v_c66 != v_c67) return;
                u64 v_c25 = _prim__0002b(db, v_c5, v_c62);
                if (v_c25 == slog_error) { slog::emit_pending_error(db, "dem_parse.slog:25"); return; }
                ++_fires;
                slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c25, v_c26});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:25", "delta:parse_ans", _fires);
  
      if (!_done)
      {
        ReadTask158* _cont = new ReadTask158(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask158(db,b), false);
  // (crule (pre (let __tconst0IXf15 const43e6e2bebb3774311cf0c867) (let __tconst5Vn517 const57cb45de78dd46c657524688)) (scan parse_ans __t1Nmr18 j) (body (exists parse (1 2 0) 1 __tconst0IXf15) (join parse (0 1 2) 2 __t1Nmr18 __tconst5Vn517 i) (join parse (1 2 0) 2 __tconst0IXf15 i __t503216)) (head (emit parse_ans (0 1) __t503216 j)) dem_parse.slog:17 #f)
  class ReadTask178 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** parseindex175;  slog::Index** parseindex176;  slog::Index** parseindex177;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("parse_ans");
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("parse_ans");
      head_index[0] = readrel180->getIndex(ord179, false);
      outer_rel = db->getRelation("parse_ans");
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("parse");
      parseindex175 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({0, 1, 2});
      slog::Relation* readrel184 = db->getRelation("parse");
      parseindex176 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 2, 0});
      slog::Relation* readrel186 = db->getRelation("parse");
      parseindex177 = readrel186->getIndex(ord185, false);
  
    }
    ReadTask178(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c68 = v_const43e6e2bebb3774311cf0c867;
      u64 v_c69 = v_const57cb45de78dd46c657524688;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c70 = _t[0];
        u64 v_c5 = _t[1];
        if (!slog::exists_probe<3,1>(parseindex175, std::array<u64,3>{v_c68, 0, 0})) return;
        slog::join_probe<3,2>(parseindex176, std::array<u64,3>{v_c70, v_c69, 0}, [&](const std::array<u64,3>& m187) {
          u64 v_c6 = m187[2];
          slog::join_probe<3,2>(parseindex177, std::array<u64,3>{v_c68, v_c6, 0}, [&](const std::array<u64,3>& m188) {
            u64 v_c71 = m188[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c5}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_parse.slog:17", "delta:parse_ans", _fires);
  
      if (!_done)
      {
        ReadTask178* _cont = new ReadTask178(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask178(db,b), false);
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("parse");
  s->addReadRel("parse_ans");
  s->addReadRel("temp0RY0222");
  s->addReadRel("temp6Ucm219");
  s->addReadRel("toint_range");
  s->addReadRel("tok");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("parse_ans");
  s->addDynamicRel("temp0RY0222");
  s->addDynamicRel("temp6Ucm219");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("parse_ans");
  d->push(s);
  d->continueRun();
}

