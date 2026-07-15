
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_constba2df4903a2c14e86dc3bcca;
u64 v_const2bc983a5942276eb00a75e21;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("3c6eacbd");
  if (s == nullptr) return;
  slog::Relation* r;
  v_constba2df4903a2c14e86dc3bcca = db->encodeString("x");
  v_const2bc983a5942276eb00a75e21 = db->encodeString("y");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord315({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord315, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord316({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord316, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord317({1, 2, 0});
    
    r->addIndex<3>(ord317, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord318({0, 1, 2});
    
    r->addIndex<3>(ord318, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord319({1, 2, 0});
    
    r->addIndex<3>(ord319, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord320({0, 1, 2});
    
    r->addIndex<3>(ord320, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("ref");
  if (r == 0) db->addStruct("ref", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("ref");
      std::vector<u16> ord321({1, 0});
    
    r->addIndex<2>(ord321, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord322({0, 1});
    
    r->addIndex<2>(ord322, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord323({1, 0});
    
    r->addIndex<2>(ord323, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("ref"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("program");
  if (r == 0) db->addRelation("program", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("program");
      std::vector<u16> ord324({0});
    
    r->addIndex<1>(ord324, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("program"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord325({1, 2, 3, 0});
    
    r->addIndex<4>(ord325, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord326({0, 1, 2, 3});
    
    r->addIndex<4>(ord326, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord327({1, 2, 0});
    
    r->addIndex<3>(ord327, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord328({0, 1, 2});
    
    r->addIndex<3>(ord328, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord329({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord329, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord330({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord330, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord331({1, 2, 0});
    
    r->addIndex<3>(ord331, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord332({0, 1, 2});
    
    r->addIndex<3>(ord332, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord333({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord333, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord334({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord334, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lambda");
  if (r == 0) db->addStruct("lambda", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lambda");
      std::vector<u16> ord335({1, 2, 0});
    
    r->addIndex<3>(ord335, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord336({0, 1, 2});
    
    r->addIndex<3>(ord336, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord337({1, 0, 2});
    
    r->addIndex<3>(ord337, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("lambda"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord338({1, 2, 3, 0});
    
    r->addIndex<4>(ord338, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord339({0, 1, 2, 3});
    
    r->addIndex<4>(ord339, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord340({0});
    
    r->addIndex<1>(ord340, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord341({1, 2, 0});
    
    r->addIndex<3>(ord341, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord342({0, 1, 2});
    
    r->addIndex<3>(ord342, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("app");
  if (r == 0) db->addStruct("app", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("app");
      std::vector<u16> ord343({1, 2, 0});
    
    r->addIndex<3>(ord343, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord344({0, 1, 2});
    
    r->addIndex<3>(ord344, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("app"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord345({1, 0});
    
    r->addIndex<2>(ord345, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord346({0, 1});
    
    r->addIndex<2>(ord346, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst2dKU13 const2bc983a5942276eb00a75e21) (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca)) (scan app __t0TEN22 __t7X6x21 __t553V14) (body (exists lambda (0 1 2) 2 __t553V14 __tconst2dKU13) (exists ref (1 0) 1 __tconst2dKU13) (exists ref (1 0) 1 __tconst2d0V20) (join lambda (0 1 2) 2 __t7X6x21 __tconst2d0V20 __t9QAB19) (join lambda (0 1 2) 2 __t553V14 __tconst2dKU13 __t3nP612) (join ref (1 0) 1 __tconst2dKU13 __t2oNi6) (exists app (1 2 0) 1 __t2oNi6) (join app (0 1 2) 2 __t3nP612 __t2oNi6 __t66ch9) (join app (0 1 2) 2 __t66ch9 __t2oNi6 dup9qtv85) (eq __t2oNi6 dup9qtv85) (join ref (1 0) 1 __tconst2d0V20 __t0D2T2) (join app (0 1 2) 2 __t9QAB19 __t0D2T2 dup7A4B84) (eq __t0D2T2 dup7A4B84)) (head (emit program (0) __t0TEN22)) prog0.slog:7 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex0;  slog::Index** refindex1;  slog::Index** refindex2;  slog::Index** lambdaindex3;  slog::Index** lambdaindex4;  slog::Index** refindex5;  slog::Index** appindex6;  slog::Index** appindex7;  slog::Index** appindex8;  slog::Index** refindex9;  slog::Index** appindex10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord12({0});
      slog::Relation* readrel13 = db->getRelation("program");
      head_index[0] = readrel13->getIndex(ord12, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord14({0, 1, 2});
      slog::Relation* readrel15 = db->getRelation("lambda");
      lambdaindex0 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("ref");
      refindex1 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 0});
      slog::Relation* readrel19 = db->getRelation("ref");
      refindex2 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 1, 2});
      slog::Relation* readrel21 = db->getRelation("lambda");
      lambdaindex3 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({0, 1, 2});
      slog::Relation* readrel23 = db->getRelation("lambda");
      lambdaindex4 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0});
      slog::Relation* readrel25 = db->getRelation("ref");
      refindex5 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 2, 0});
      slog::Relation* readrel27 = db->getRelation("app");
      appindex6 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1, 2});
      slog::Relation* readrel29 = db->getRelation("app");
      appindex7 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1, 2});
      slog::Relation* readrel31 = db->getRelation("app");
      appindex8 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("ref");
      refindex9 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1, 2});
      slog::Relation* readrel35 = db->getRelation("app");
      appindex10 = readrel35->getIndex(ord34, false);
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c2 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<3,2>(lambdaindex0, std::array<u64,3>{v_c4, v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2, std::array<u64,2>{v_c1, 0})) return;
        slog::join_probe<3,2>(lambdaindex3, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m36) {
          u64 v_c5 = m36[2];
          slog::join_probe<3,2>(lambdaindex4, std::array<u64,3>{v_c4, v_c0, 0}, [&](const std::array<u64,3>& m37) {
            u64 v_c6 = m37[2];
            slog::join_probe<2,1>(refindex5, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m38) {
              u64 v_c7 = m38[1];
              if (!slog::exists_probe<3,1>(appindex6, std::array<u64,3>{v_c7, 0, 0})) return;
              slog::join_probe<3,2>(appindex7, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m39) {
                u64 v_c8 = m39[2];
                slog::join_probe<3,2>(appindex8, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m40) {
                  u64 v_c9 = m40[2];
                  if (v_c7 != v_c9) return;
                  slog::join_probe<2,1>(refindex9, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m41) {
                    u64 v_c10 = m41[1];
                    slog::join_probe<3,2>(appindex10, std::array<u64,3>{v_c5, v_c10, 0}, [&](const std::array<u64,3>& m42) {
                      u64 v_c11 = m42[2];
                      if (v_c10 != v_c11) return;
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "delta:app", _fires);
  
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
  // (crule (pre (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca) (let __tconst2dKU13 const2bc983a5942276eb00a75e21)) (probe lambda (1 0 2) 1 __tconst2d0V20 __t3Oar4 __t0D2T2) (body (join ref (0 1) 2 __t0D2T2 __tconst2d0V20) (exists app (1 2 0) 1 __t0D2T2) (join ref (1 0) 1 __tconst2dKU13 __t2oNi6) (join app (1 2 0) 1 __t2oNi6 dup6Zhd72 __t66ch9) (eq __t2oNi6 dup6Zhd72) (join app (1 2 0) 1 __t0D2T2 dup8UwM73 __t9QAB19) (eq __t0D2T2 dup8UwM73)) (head (emit program (0) __t3Oar4) (mkstruct lambda (1 2 0) __t7X6x21 __tconst2d0V20 __t9QAB19) (mkstruct app (1 2 0) __t3nP612 __t2oNi6 __t66ch9)) prog0.slog:7 #f)
  class ReadTask48 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex43;  slog::Index** appindex44;  slog::Index** refindex45;  slog::Index** appindex46;  slog::Index** appindex47;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord49({0});
      slog::Relation* readrel50 = db->getRelation("program");
      head_index[0] = readrel50->getIndex(ord49, false);
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("app");
      std::vector<u16> ord51({1, 0, 2});
      slog::Relation* readrel52 = db->getRelation("lambda");
      driver_index = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({0, 1});
      slog::Relation* readrel54 = db->getRelation("ref");
      refindex43 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 0});
      slog::Relation* readrel56 = db->getRelation("app");
      appindex44 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 0});
      slog::Relation* readrel58 = db->getRelation("ref");
      refindex45 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("app");
      appindex46 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("app");
      appindex47 = readrel62->getIndex(ord61, false);
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c1, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m63) {
        u64 v_c12 = m63[1];
        u64 v_c10 = m63[2];
        if (buckethash(v_c12) != bucket) return;
        slog::join_probe<2,2>(refindex43, std::array<u64,2>{v_c10, v_c1}, [&](const std::array<u64,2>& m64) {
          if (!slog::exists_probe<3,1>(appindex44, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe<2,1>(refindex45, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m65) {
            u64 v_c7 = m65[1];
            slog::join_probe<3,1>(appindex46, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m66) {
              u64 v_c13 = m66[1]; u64 v_c8 = m66[2];
              if (v_c7 != v_c13) return;
              slog::join_probe<3,1>(appindex47, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m67) {
                u64 v_c14 = m67[1]; u64 v_c5 = m67[2];
                if (v_c10 != v_c14) return;
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c1, v_c5}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c7, v_c8}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask48* _cont = new ReadTask48(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask48(db,b), false);
  // (crule (pre (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca) (let __tconst2dKU13 const2bc983a5942276eb00a75e21)) (seeded) (body (join ref (1 0) 1 __tconst2d0V20 __t0D2T2) (join ref (1 0) 1 __tconst2dKU13 __t2oNi6)) (head (mkstruct app (1 2 0) __t9QAB19 __t0D2T2 __t0D2T2) (mkstruct app (1 2 0) __t66ch9 __t2oNi6 __t2oNi6) (mkstruct lambda (1 2 0) __t3Oar4 __tconst2d0V20 __t0D2T2)) prog0.slog:7 #f)
  class ReadTask70 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex68;  slog::Index** refindex69;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord71({1, 2, 0});
      slog::Relation* readrel72 = db->getRelation("app");
      head_index[0] = readrel72->getIndex(ord71, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord73({1, 2, 0});
      slog::Relation* readrel74 = db->getRelation("app");
      head_index[1] = readrel74->getIndex(ord73, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord75({1, 2, 0});
      slog::Relation* readrel76 = db->getRelation("lambda");
      head_index[2] = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 0});
      slog::Relation* readrel78 = db->getRelation("ref");
      refindex68 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 0});
      slog::Relation* readrel80 = db->getRelation("ref");
      refindex69 = readrel80->getIndex(ord79, false);
  
    }
    ReadTask70(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex68, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m81) {
        u64 v_c10 = m81[1];
        slog::join_probe<2,1>(refindex69, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m82) {
          u64 v_c7 = m82[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c10}, std::array<u16,3>{1, 2, 0});
          slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c7, v_c7}, std::array<u16,3>{1, 2, 0});
          slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c1, v_c10}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask70(db,b));
  // (crule (pre (let __tconst2dKU13 const2bc983a5942276eb00a75e21) (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca)) (seeded) (body (join ref (1 0) 1 __tconst2dKU13 __t2oNi6) (exists app (1 2 0) 1 __t2oNi6) (exists lambda (1 2 0) 1 __tconst2dKU13) (exists lambda (1 2 0) 1 __tconst2d0V20) (join ref (1 0) 1 __tconst2d0V20 __t0D2T2) (exists app (1 2 0) 1 __t0D2T2) (join app (1 2 0) 1 __t2oNi6 dup4IAA82 __t66ch9) (eq __t2oNi6 dup4IAA82) (join app (1 2 0) 2 __t2oNi6 __t66ch9 __t3nP612) (join lambda (1 2 0) 2 __tconst2dKU13 __t3nP612 __t553V14) (join app (1 2 0) 1 __t0D2T2 dup9JDm83 __t9QAB19) (eq __t0D2T2 dup9JDm83) (join lambda (1 2 0) 2 __tconst2d0V20 __t9QAB19 __t7X6x21)) (head (mkstruct app (1 2 0) __t0TEN22 __t7X6x21 __t553V14)) prog0.slog:7 #f)
  class ReadTask94 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex83;  slog::Index** appindex84;  slog::Index** lambdaindex85;  slog::Index** lambdaindex86;  slog::Index** refindex87;  slog::Index** appindex88;  slog::Index** appindex89;  slog::Index** appindex90;  slog::Index** lambdaindex91;  slog::Index** appindex92;  slog::Index** lambdaindex93;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord95({1, 2, 0});
      slog::Relation* readrel96 = db->getRelation("app");
      head_index[0] = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 0});
      slog::Relation* readrel98 = db->getRelation("ref");
      refindex83 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 0});
      slog::Relation* readrel100 = db->getRelation("app");
      appindex84 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 2, 0});
      slog::Relation* readrel102 = db->getRelation("lambda");
      lambdaindex85 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 0});
      slog::Relation* readrel104 = db->getRelation("lambda");
      lambdaindex86 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 0});
      slog::Relation* readrel106 = db->getRelation("ref");
      refindex87 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 2, 0});
      slog::Relation* readrel108 = db->getRelation("app");
      appindex88 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 2, 0});
      slog::Relation* readrel110 = db->getRelation("app");
      appindex89 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 2, 0});
      slog::Relation* readrel112 = db->getRelation("app");
      appindex90 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 2, 0});
      slog::Relation* readrel114 = db->getRelation("lambda");
      lambdaindex91 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 2, 0});
      slog::Relation* readrel116 = db->getRelation("app");
      appindex92 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 2, 0});
      slog::Relation* readrel118 = db->getRelation("lambda");
      lambdaindex93 = readrel118->getIndex(ord117, false);
  
    }
    ReadTask94(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex83, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m119) {
        u64 v_c7 = m119[1];
        if (!slog::exists_probe<3,1>(appindex84, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex85, std::array<u64,3>{v_c0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex86, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(refindex87, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m120) {
          u64 v_c10 = m120[1];
          if (!slog::exists_probe<3,1>(appindex88, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe<3,1>(appindex89, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m121) {
            u64 v_c15 = m121[1]; u64 v_c8 = m121[2];
            if (v_c7 != v_c15) return;
            slog::join_probe<3,2>(appindex90, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m122) {
              u64 v_c6 = m122[2];
              slog::join_probe<3,2>(lambdaindex91, std::array<u64,3>{v_c0, v_c6, 0}, [&](const std::array<u64,3>& m123) {
                u64 v_c4 = m123[2];
                slog::join_probe<3,1>(appindex92, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m124) {
                  u64 v_c16 = m124[1]; u64 v_c5 = m124[2];
                  if (v_c10 != v_c16) return;
                  slog::join_probe<3,2>(lambdaindex93, std::array<u64,3>{v_c1, v_c5, 0}, [&](const std::array<u64,3>& m125) {
                    u64 v_c3 = m125[2];
                    ++_fires;
                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c3, v_c4}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask94(db,b));
  // (crule (pre (let __tconst2dKU13 const2bc983a5942276eb00a75e21) (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca)) (seeded) (body (join ref (1 0) 1 __tconst2dKU13 __t2oNi6) (exists lambda (1 2 0) 1 __tconst2d0V20) (exists app (1 2 0) 1 __t2oNi6) (exists lambda (1 2 0) 1 __tconst2dKU13) (join ref (1 0) 1 __tconst2d0V20 __t0D2T2) (join app (1 2 0) 1 __t0D2T2 dup2G8H86 __t9QAB19) (eq __t0D2T2 dup2G8H86) (join lambda (1 2 0) 2 __tconst2d0V20 __t9QAB19 __t7X6x21) (exists app (1 2 0) 1 __t7X6x21) (join app (1 2 0) 1 __t2oNi6 dup2RpF87 __t66ch9) (eq __t2oNi6 dup2RpF87) (join app (1 2 0) 2 __t2oNi6 __t66ch9 __t3nP612) (join lambda (1 2 0) 2 __tconst2dKU13 __t3nP612 __t553V14) (join app (1 2 0) 2 __t7X6x21 __t553V14 __t0TEN22)) (head (emit program (0) __t0TEN22)) prog0.slog:7 #f)
  class ReadTask138 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex126;  slog::Index** lambdaindex127;  slog::Index** appindex128;  slog::Index** lambdaindex129;  slog::Index** refindex130;  slog::Index** appindex131;  slog::Index** lambdaindex132;  slog::Index** appindex133;  slog::Index** appindex134;  slog::Index** appindex135;  slog::Index** lambdaindex136;  slog::Index** appindex137;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord139({0});
      slog::Relation* readrel140 = db->getRelation("program");
      head_index[0] = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 0});
      slog::Relation* readrel142 = db->getRelation("ref");
      refindex126 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 2, 0});
      slog::Relation* readrel144 = db->getRelation("lambda");
      lambdaindex127 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({1, 2, 0});
      slog::Relation* readrel146 = db->getRelation("app");
      appindex128 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({1, 2, 0});
      slog::Relation* readrel148 = db->getRelation("lambda");
      lambdaindex129 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({1, 0});
      slog::Relation* readrel150 = db->getRelation("ref");
      refindex130 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 2, 0});
      slog::Relation* readrel152 = db->getRelation("app");
      appindex131 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 2, 0});
      slog::Relation* readrel154 = db->getRelation("lambda");
      lambdaindex132 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 2, 0});
      slog::Relation* readrel156 = db->getRelation("app");
      appindex133 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 2, 0});
      slog::Relation* readrel158 = db->getRelation("app");
      appindex134 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("app");
      appindex135 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 0});
      slog::Relation* readrel162 = db->getRelation("lambda");
      lambdaindex136 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 0});
      slog::Relation* readrel164 = db->getRelation("app");
      appindex137 = readrel164->getIndex(ord163, false);
  
    }
    ReadTask138(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex126, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m165) {
        u64 v_c7 = m165[1];
        if (!slog::exists_probe<3,1>(lambdaindex127, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex128, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex129, std::array<u64,3>{v_c0, 0, 0})) return;
        slog::join_probe<2,1>(refindex130, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m166) {
          u64 v_c10 = m166[1];
          slog::join_probe<3,1>(appindex131, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m167) {
            u64 v_c17 = m167[1]; u64 v_c5 = m167[2];
            if (v_c10 != v_c17) return;
            slog::join_probe<3,2>(lambdaindex132, std::array<u64,3>{v_c1, v_c5, 0}, [&](const std::array<u64,3>& m168) {
              u64 v_c3 = m168[2];
              if (!slog::exists_probe<3,1>(appindex133, std::array<u64,3>{v_c3, 0, 0})) return;
              slog::join_probe<3,1>(appindex134, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m169) {
                u64 v_c18 = m169[1]; u64 v_c8 = m169[2];
                if (v_c7 != v_c18) return;
                slog::join_probe<3,2>(appindex135, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m170) {
                  u64 v_c6 = m170[2];
                  slog::join_probe<3,2>(lambdaindex136, std::array<u64,3>{v_c0, v_c6, 0}, [&](const std::array<u64,3>& m171) {
                    u64 v_c4 = m171[2];
                    slog::join_probe<3,2>(appindex137, std::array<u64,3>{v_c3, v_c4, 0}, [&](const std::array<u64,3>& m172) {
                      u64 v_c2 = m172[2];
                      ++_fires;
                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask138(db,b));
  // (crule (pre (let __tconst2dKU13 const2bc983a5942276eb00a75e21) (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca)) (probe lambda (1 0 2) 1 __tconst2dKU13 __t553V14 __t3nP612) (body (exists ref (1 0) 1 __tconst2d0V20) (exists lambda (1 2 0) 1 __tconst2d0V20) (join ref (1 0) 1 __tconst2dKU13 __t2oNi6) (exists app (1 2 0) 1 __t2oNi6) (join app (0 1 2) 2 __t3nP612 __t2oNi6 __t66ch9) (join app (0 1 2) 2 __t66ch9 __t2oNi6 dup4sRM80) (eq __t2oNi6 dup4sRM80) (join ref (1 0) 1 __tconst2d0V20 __t0D2T2) (join app (1 2 0) 1 __t0D2T2 dup1mZF81 __t9QAB19) (eq __t0D2T2 dup1mZF81) (join lambda (1 2 0) 2 __tconst2d0V20 __t9QAB19 __t7X6x21)) (head (mkstruct app (1 2 0) __t0TEN22 __t7X6x21 __t553V14)) prog0.slog:7 #f)
  class ReadTask182 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex173;  slog::Index** lambdaindex174;  slog::Index** refindex175;  slog::Index** appindex176;  slog::Index** appindex177;  slog::Index** appindex178;  slog::Index** refindex179;  slog::Index** appindex180;  slog::Index** lambdaindex181;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord183({1, 0, 2});
      slog::Relation* readrel184 = db->getRelation("lambda");
      driver_index = readrel184->getIndex(ord183, true);
      std::vector<u16> ord185({1, 0});
      slog::Relation* readrel186 = db->getRelation("ref");
      refindex173 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 2, 0});
      slog::Relation* readrel188 = db->getRelation("lambda");
      lambdaindex174 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 0});
      slog::Relation* readrel190 = db->getRelation("ref");
      refindex175 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 2, 0});
      slog::Relation* readrel192 = db->getRelation("app");
      appindex176 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({0, 1, 2});
      slog::Relation* readrel194 = db->getRelation("app");
      appindex177 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({0, 1, 2});
      slog::Relation* readrel196 = db->getRelation("app");
      appindex178 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 0});
      slog::Relation* readrel198 = db->getRelation("ref");
      refindex179 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 2, 0});
      slog::Relation* readrel200 = db->getRelation("app");
      appindex180 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 2, 0});
      slog::Relation* readrel202 = db->getRelation("lambda");
      lambdaindex181 = readrel202->getIndex(ord201, false);
  
    }
    ReadTask182(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c0, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m203) {
        u64 v_c4 = m203[1];
        u64 v_c6 = m203[2];
        if (buckethash(v_c4) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex173, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex174, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(refindex175, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m204) {
          u64 v_c7 = m204[1];
          if (!slog::exists_probe<3,1>(appindex176, std::array<u64,3>{v_c7, 0, 0})) return;
          slog::join_probe<3,2>(appindex177, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m205) {
            u64 v_c8 = m205[2];
            slog::join_probe<3,2>(appindex178, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m206) {
              u64 v_c19 = m206[2];
              if (v_c7 != v_c19) return;
              slog::join_probe<2,1>(refindex179, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m207) {
                u64 v_c10 = m207[1];
                slog::join_probe<3,1>(appindex180, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m208) {
                  u64 v_c20 = m208[1]; u64 v_c5 = m208[2];
                  if (v_c10 != v_c20) return;
                  slog::join_probe<3,2>(lambdaindex181, std::array<u64,3>{v_c1, v_c5, 0}, [&](const std::array<u64,3>& m209) {
                    u64 v_c3 = m209[2];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c4}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask182* _cont = new ReadTask182(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask182(db,b), false);
  // (crule (pre (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca) (let __tconst2dKU13 const2bc983a5942276eb00a75e21)) (seeded) (body (join ref (1 0) 1 __tconst2dKU13 __t2oNi6) (exists app (1 2 0) 1 __t2oNi6) (exists lambda (1 2 0) 1 __tconst2d0V20) (join ref (1 0) 1 __tconst2d0V20 __t0D2T2) (exists app (1 2 0) 1 __t0D2T2) (join app (1 2 0) 1 __t2oNi6 dup0Kqk78 __t66ch9) (eq __t2oNi6 dup0Kqk78) (join app (1 2 0) 2 __t2oNi6 __t66ch9 __t3nP612) (join app (1 2 0) 1 __t0D2T2 dup29Yu79 __t9QAB19) (eq __t0D2T2 dup29Yu79) (join lambda (1 2 0) 2 __tconst2d0V20 __t9QAB19 __t7X6x21)) (head (mkstruct lambda (1 2 0) __t553V14 __tconst2dKU13 __t3nP612)) prog0.slog:7 #f)
  class ReadTask219 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex210;  slog::Index** appindex211;  slog::Index** lambdaindex212;  slog::Index** refindex213;  slog::Index** appindex214;  slog::Index** appindex215;  slog::Index** appindex216;  slog::Index** appindex217;  slog::Index** lambdaindex218;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("lambda");
      head_index[0] = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 0});
      slog::Relation* readrel223 = db->getRelation("ref");
      refindex210 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 0});
      slog::Relation* readrel225 = db->getRelation("app");
      appindex211 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 0});
      slog::Relation* readrel227 = db->getRelation("lambda");
      lambdaindex212 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 0});
      slog::Relation* readrel229 = db->getRelation("ref");
      refindex213 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 2, 0});
      slog::Relation* readrel231 = db->getRelation("app");
      appindex214 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 2, 0});
      slog::Relation* readrel233 = db->getRelation("app");
      appindex215 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 0});
      slog::Relation* readrel235 = db->getRelation("app");
      appindex216 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 2, 0});
      slog::Relation* readrel237 = db->getRelation("app");
      appindex217 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 0});
      slog::Relation* readrel239 = db->getRelation("lambda");
      lambdaindex218 = readrel239->getIndex(ord238, false);
  
    }
    ReadTask219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex210, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m240) {
        u64 v_c7 = m240[1];
        if (!slog::exists_probe<3,1>(appindex211, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex212, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(refindex213, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m241) {
          u64 v_c10 = m241[1];
          if (!slog::exists_probe<3,1>(appindex214, std::array<u64,3>{v_c10, 0, 0})) return;
          slog::join_probe<3,1>(appindex215, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m242) {
            u64 v_c21 = m242[1]; u64 v_c8 = m242[2];
            if (v_c7 != v_c21) return;
            slog::join_probe<3,2>(appindex216, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m243) {
              u64 v_c6 = m243[2];
              slog::join_probe<3,1>(appindex217, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m244) {
                u64 v_c22 = m244[1]; u64 v_c5 = m244[2];
                if (v_c10 != v_c22) return;
                slog::join_probe<3,2>(lambdaindex218, std::array<u64,3>{v_c1, v_c5, 0}, [&](const std::array<u64,3>& m245) {
                  u64 v_c3 = m245[2];
                  ++_fires;
                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c6}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask219(db,b));
  // (crule (pre (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca) (let __tconst2dKU13 const2bc983a5942276eb00a75e21)) (seeded) (body (join ref (1 0) 1 __tconst2d0V20 __t0D2T2) (exists ref (1 0) 1 __tconst2dKU13) (exists app (1 2 0) 1 __t0D2T2) (join lambda (1 2 0) 2 __tconst2d0V20 __t0D2T2 __t3Oar4) (join ref (1 0) 1 __tconst2dKU13 __t2oNi6) (join app (1 2 0) 1 __t2oNi6 dup9l8K74 __t66ch9) (eq __t2oNi6 dup9l8K74) (join app (1 2 0) 1 __t0D2T2 dup55sd75 __t9QAB19) (eq __t0D2T2 dup55sd75)) (head (emit program (0) __t3Oar4) (mkstruct lambda (1 2 0) __t7X6x21 __tconst2d0V20 __t9QAB19) (mkstruct app (1 2 0) __t3nP612 __t2oNi6 __t66ch9)) prog0.slog:7 #f)
  class ReadTask253 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex246;  slog::Index** refindex247;  slog::Index** appindex248;  slog::Index** lambdaindex249;  slog::Index** refindex250;  slog::Index** appindex251;  slog::Index** appindex252;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord254({0});
      slog::Relation* readrel255 = db->getRelation("program");
      head_index[0] = readrel255->getIndex(ord254, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord256({1, 2, 0});
      slog::Relation* readrel257 = db->getRelation("lambda");
      head_index[1] = readrel257->getIndex(ord256, false);
      head_rel[2] = db->getRelation("app");
      std::vector<u16> ord258({1, 2, 0});
      slog::Relation* readrel259 = db->getRelation("app");
      head_index[2] = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 0});
      slog::Relation* readrel261 = db->getRelation("ref");
      refindex246 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({1, 0});
      slog::Relation* readrel263 = db->getRelation("ref");
      refindex247 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 2, 0});
      slog::Relation* readrel265 = db->getRelation("app");
      appindex248 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 2, 0});
      slog::Relation* readrel267 = db->getRelation("lambda");
      lambdaindex249 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 0});
      slog::Relation* readrel269 = db->getRelation("ref");
      refindex250 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 2, 0});
      slog::Relation* readrel271 = db->getRelation("app");
      appindex251 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 2, 0});
      slog::Relation* readrel273 = db->getRelation("app");
      appindex252 = readrel273->getIndex(ord272, false);
  
    }
    ReadTask253(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex246, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m274) {
        u64 v_c10 = m274[1];
        if (!slog::exists_probe<2,1>(refindex247, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex248, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex249, std::array<u64,3>{v_c1, v_c10, 0}, [&](const std::array<u64,3>& m275) {
          u64 v_c12 = m275[2];
          slog::join_probe<2,1>(refindex250, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m276) {
            u64 v_c7 = m276[1];
            slog::join_probe<3,1>(appindex251, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m277) {
              u64 v_c23 = m277[1]; u64 v_c8 = m277[2];
              if (v_c7 != v_c23) return;
              slog::join_probe<3,1>(appindex252, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m278) {
                u64 v_c24 = m278[1]; u64 v_c5 = m278[2];
                if (v_c10 != v_c24) return;
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
                slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c1, v_c5}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c7, v_c8}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask253(db,b));
  // (crule (pre (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca) (let __tconst2dKU13 const2bc983a5942276eb00a75e21)) (once) (body) (head (mkstruct ref (1 0) __t2oNi6 __tconst2dKU13) (mkstruct ref (1 0) __t0D2T2 __tconst2d0V20)) prog0.slog:7 #f)
  class ReadTask279 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ref");
      head_rel[1] = db->getRelation("ref");
  
    }
    ReadTask279(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask279(db,b), true);
  // (crule (pre (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca) (let __tconst2dKU13 const2bc983a5942276eb00a75e21)) (scan app __t3nP612 __t2oNi6 __t66ch9) (body (join ref (0 1) 2 __t2oNi6 __tconst2dKU13) (exists ref (1 0) 1 __tconst2d0V20) (exists lambda (1 2 0) 1 __tconst2d0V20) (join app (0 1 2) 2 __t66ch9 __t2oNi6 dup9l0a76) (eq __t2oNi6 dup9l0a76) (join ref (1 0) 1 __tconst2d0V20 __t0D2T2) (join app (1 2 0) 1 __t0D2T2 dup5Vqr77 __t9QAB19) (eq __t0D2T2 dup5Vqr77) (join lambda (1 2 0) 2 __tconst2d0V20 __t9QAB19 __t7X6x21)) (head (mkstruct lambda (1 2 0) __t553V14 __tconst2dKU13 __t3nP612)) prog0.slog:7 #f)
  class ReadTask287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex280;  slog::Index** refindex281;  slog::Index** lambdaindex282;  slog::Index** appindex283;  slog::Index** refindex284;  slog::Index** appindex285;  slog::Index** lambdaindex286;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord288({0, 1});
      slog::Relation* readrel289 = db->getRelation("ref");
      refindex280 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 0});
      slog::Relation* readrel291 = db->getRelation("ref");
      refindex281 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 2, 0});
      slog::Relation* readrel293 = db->getRelation("lambda");
      lambdaindex282 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({0, 1, 2});
      slog::Relation* readrel295 = db->getRelation("app");
      appindex283 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 0});
      slog::Relation* readrel297 = db->getRelation("ref");
      refindex284 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 2, 0});
      slog::Relation* readrel299 = db->getRelation("app");
      appindex285 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 2, 0});
      slog::Relation* readrel301 = db->getRelation("lambda");
      lambdaindex286 = readrel301->getIndex(ord300, false);
  
    }
    ReadTask287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
  
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
        slog::join_probe<2,2>(refindex280, std::array<u64,2>{v_c7, v_c0}, [&](const std::array<u64,2>& m302) {
          if (!slog::exists_probe<2,1>(refindex281, std::array<u64,2>{v_c1, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex282, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe<3,2>(appindex283, std::array<u64,3>{v_c8, v_c7, 0}, [&](const std::array<u64,3>& m303) {
            u64 v_c25 = m303[2];
            if (v_c7 != v_c25) return;
            slog::join_probe<2,1>(refindex284, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m304) {
              u64 v_c10 = m304[1];
              slog::join_probe<3,1>(appindex285, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m305) {
                u64 v_c26 = m305[1]; u64 v_c5 = m305[2];
                if (v_c10 != v_c26) return;
                slog::join_probe<3,2>(lambdaindex286, std::array<u64,3>{v_c1, v_c5, 0}, [&](const std::array<u64,3>& m306) {
                  u64 v_c3 = m306[2];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c0, v_c6}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask287* _cont = new ReadTask287(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask287(db,b), false);
  // (crule (pre (let __tconst2d0V20 constba2df4903a2c14e86dc3bcca) (let __tconst2dKU13 const2bc983a5942276eb00a75e21)) (probe ref (1 0) 1 __tconst2d0V20 __t0D2T2) (body (join ref (1 0) 1 __tconst2dKU13 __t2oNi6)) (head (mkstruct app (1 2 0) __t9QAB19 __t0D2T2 __t0D2T2) (mkstruct app (1 2 0) __t66ch9 __t2oNi6 __t2oNi6) (mkstruct lambda (1 2 0) __t3Oar4 __tconst2d0V20 __t0D2T2)) prog0.slog:7 #f)
  class ReadTask308 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex307;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord309({1, 0});
      slog::Relation* readrel310 = db->getRelation("ref");
      driver_index = readrel310->getIndex(ord309, true);
      std::vector<u16> ord311({1, 0});
      slog::Relation* readrel312 = db->getRelation("ref");
      refindex307 = readrel312->getIndex(ord311, false);
  
    }
    ReadTask308(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c1, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m313) {
        u64 v_c10 = m313[1];
        if (buckethash(v_c10) != bucket) return;
        slog::join_probe<2,1>(refindex307, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m314) {
          u64 v_c7 = m314[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c10}, std::array<u16,3>{1, 2, 0});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c7, v_c7}, std::array<u16,3>{1, 2, 0});
          slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c10}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("prog0.slog:7", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask308* _cont = new ReadTask308(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask308(db,b), false);
  s->addReadRel("app");
  s->addReadRel("lambda");
  s->addReadRel("ref");
  s->addDynamicRel("app");
  s->addDynamicRel("lambda");
  s->addDynamicRel("program");
  s->addDynamicRel("ref");
  d->push(s);
  d->continueRun();
}

