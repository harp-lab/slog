
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const18d10c7d2b4b04aaf04254d1;
u64 v_const076de6e730df0b4c3860877a;
u64 v_const4bc9274d8758b867e8c071a6;
u64 v_const7265b875feb0d1730ead43d3;
u64 v_const7f3e916bf628c503cac5f6ba;
u64 v_const20c400557af0eddc0be4d9e0;
u64 v_constba2df4903a2c14e86dc3bcca;
u64 v_const2bc983a5942276eb00a75e21;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("731e2499");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const18d10c7d2b4b04aaf04254d1 = db->encodeString("true");
  v_const076de6e730df0b4c3860877a = db->encodeString("false");
  v_const4bc9274d8758b867e8c071a6 = db->encodeString("red");
  v_const7265b875feb0d1730ead43d3 = db->encodeString("w");
  v_const7f3e916bf628c503cac5f6ba = db->encodeString("green");
  v_const20c400557af0eddc0be4d9e0 = db->encodeString("z");
  v_constba2df4903a2c14e86dc3bcca = db->encodeString("x");
  v_const2bc983a5942276eb00a75e21 = db->encodeString("y");
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
  r = db->getRelation("saw_true");
  if (r == 0) db->addRelation("saw_true", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("saw_true");
      std::vector<u16> ord36({0});
    
    r->addIndex<1>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("saw_true"), std::array<u16,1>{0}, b));
  r = db->getRelation("saw_red");
  if (r == 0) db->addRelation("saw_red", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("saw_red");
      std::vector<u16> ord37({0});
    
    r->addIndex<1>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("saw_red"), std::array<u16,1>{0}, b));
  r = db->getRelation("saw_false");
  if (r == 0) db->addRelation("saw_false", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("saw_false");
      std::vector<u16> ord38({0});
    
    r->addIndex<1>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("saw_false"), std::array<u16,1>{0}, b));
  r = db->getRelation("obs");
  if (r == 0) db->addRelation("obs", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("obs");
      std::vector<u16> ord39({0, 1});
    
    r->addIndex<2>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("obs"), std::array<u16,2>{0, 1}, b));
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
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord52({0});
    
    r->addIndex<1>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord53({1, 2, 0});
    
    r->addIndex<3>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord54({0, 1, 2});
    
    r->addIndex<3>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord55({1, 0});
    
    r->addIndex<2>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord56({0, 1});
    
    r->addIndex<2>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord57({1, 0});
    
    r->addIndex<2>(ord57, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst9oz114 const7f3e916bf628c503cac5f6ba) (let __tconst7GgB15 const076de6e730df0b4c3860877a) (let __tconst6n8c16 const4bc9274d8758b867e8c071a6) (let __tconst5sWs17 const18d10c7d2b4b04aaf04254d1) (let __tconst1iVE8 const7265b875feb0d1730ead43d3) (let __tconst0ILp6 const20c400557af0eddc0be4d9e0) (let __tconst7Ax04 const2bc983a5942276eb00a75e21) (let __tconst7oBm2 constba2df4903a2c14e86dc3bcca)) (probe _enum (1 0) 1 __tconst9oz114 __t0gwD7) (body (exists _enum (1 0) 1 __tconst6n8c16) (exists _enum (1 0) 1 __tconst5sWs17) (join _enum (1 0) 1 __tconst7GgB15 __tconst5iVo5) (join _enum (1 0) 1 __tconst6n8c16 __t7yxK3) (join _enum (1 0) 1 __tconst5sWs17 __tconst14HO1)) (head (emit obs (0 1) __tconst1iVE8 __t0gwD7) (emit obs (0 1) __tconst0ILp6 __tconst5iVo5) (emit obs (0 1) __tconst7Ax04 __t7yxK3) (emit obs (0 1) __tconst7oBm2 __tconst14HO1)) enum_bools_mix.slog:12 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex0;  slog::Index** _enumindex1;  slog::Index** _enumindex2;  slog::Index** _enumindex3;  slog::Index** _enumindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("obs");
      std::vector<u16> ord6({0, 1});
      slog::Relation* readrel7 = db->getRelation("obs");
      head_index[0] = readrel7->getIndex(ord6, false);
      head_rel[1] = db->getRelation("obs");
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("obs");
      head_index[1] = readrel9->getIndex(ord8, false);
      head_rel[2] = db->getRelation("obs");
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("obs");
      head_index[2] = readrel11->getIndex(ord10, false);
      head_rel[3] = db->getRelation("obs");
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("obs");
      head_index[3] = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("_enum");
      driver_index = readrel15->getIndex(ord14, true);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("_enum");
      _enumindex0 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 0});
      slog::Relation* readrel19 = db->getRelation("_enum");
      _enumindex1 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 0});
      slog::Relation* readrel21 = db->getRelation("_enum");
      _enumindex2 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("_enum");
      _enumindex3 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0});
      slog::Relation* readrel25 = db->getRelation("_enum");
      _enumindex4 = readrel25->getIndex(ord24, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7f3e916bf628c503cac5f6ba;
      u64 v_c1 = v_const076de6e730df0b4c3860877a;
      u64 v_c2 = v_const4bc9274d8758b867e8c071a6;
      u64 v_c3 = v_const18d10c7d2b4b04aaf04254d1;
      u64 v_c4 = v_const7265b875feb0d1730ead43d3;
      u64 v_c5 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c6 = v_const2bc983a5942276eb00a75e21;
      u64 v_c7 = v_constba2df4903a2c14e86dc3bcca;
  
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
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m26) {
        u64 v_c8 = m26[1];
        if (buckethash(v_c8) != bucket) return;
        if (!slog::exists_probe<2,1>(_enumindex0, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex1, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(_enumindex2, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m27) {
          u64 v_c9 = m27[1];
          slog::join_probe<2,1>(_enumindex3, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m28) {
            u64 v_c10 = m28[1];
            slog::join_probe<2,1>(_enumindex4, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m29) {
              u64 v_c11 = m29[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c8}, std::array<u16,2>{0, 1});
              slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c5, v_c9}, std::array<u16,2>{0, 1});
              slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c6, v_c10}, std::array<u16,2>{0, 1});
              slog::emit<2>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c7, v_c11}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("enum_bools_mix.slog:12", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask5* _cont = new ReadTask5(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), true);
  s->addReadRel("_enum");
  s->addDynamicRel("obs");
  d->push(s);
  d->continueRun();
}

