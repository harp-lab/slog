
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_consta7fdc4e6e62bd8f54a36b6a0;
u64 v_constaee3d30407ccfb32dbb15266;
u64 v_const3239cd974435e50a8b8f46b4;
u64 v_conste523f9d32d200d4c898117c9;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("37c31970");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_consta7fdc4e6e62bd8f54a36b6a0 = db->encodeString("r3");
  v_constaee3d30407ccfb32dbb15266 = db->encodeString("r1");
  v_const3239cd974435e50a8b8f46b4 = db->encodeString("l1");
  v_conste523f9d32d200d4c898117c9 = db->encodeString("l2");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord140({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord141({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord142({1, 2, 0});
    
    r->addIndex<3>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord143({0, 1, 2});
    
    r->addIndex<3>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord144({1, 2, 0});
    
    r->addIndex<3>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord145({0, 1, 2});
    
    r->addIndex<3>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("right");
  if (r == 0) db->addRelation("right", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("right");
      std::vector<u16> ord146({0});
    
    r->addIndex<1>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("right"), std::array<u16,1>{0}, b));
  r = db->getRelation("neq");
  if (r == 0) db->addRelation("neq", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("neq");
      std::vector<u16> ord147({0, 1});
    
    r->addIndex<2>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("neq"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord148({1, 2, 3, 0});
    
    r->addIndex<4>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord149({0, 1, 2, 3});
    
    r->addIndex<4>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord150({1, 2, 0});
    
    r->addIndex<3>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord151({0, 1, 2});
    
    r->addIndex<3>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord152({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord153({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord154({1, 2, 0});
    
    r->addIndex<3>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord155({0, 1, 2});
    
    r->addIndex<3>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord156({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord157({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("left");
  if (r == 0) db->addRelation("left", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("left");
      std::vector<u16> ord158({0});
    
    r->addIndex<1>(ord158, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("left"), std::array<u16,1>{0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord159({1, 2, 3, 0});
    
    r->addIndex<4>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord160({0, 1, 2, 3});
    
    r->addIndex<4>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord161({0});
    
    r->addIndex<1>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("dnode");
  if (r == 0) db->addStruct("dnode", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("dnode");
      std::vector<u16> ord162({2, 1, 0});
    
    r->addIndex<3>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord163({0, 1, 2});
    
    r->addIndex<3>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord164({2, 0, 1});
    
    r->addIndex<3>(ord164, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("dnode"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("dleaf");
  if (r == 0) db->addStruct("dleaf", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("dleaf");
      std::vector<u16> ord165({1, 0});
    
    r->addIndex<2>(ord165, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord166({0, 1});
    
    r->addIndex<2>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord167({1, 0});
    
    r->addIndex<2>(ord167, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("dleaf"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord168({1, 2, 0});
    
    r->addIndex<3>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord169({0, 1, 2});
    
    r->addIndex<3>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("agree");
  if (r == 0) db->addRelation("agree", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("agree");
      std::vector<u16> ord170({0, 1, 2});
    
    r->addIndex<3>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("agree"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord171({1, 0});
    
    r->addIndex<2>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord172({0, 1});
    
    r->addIndex<2>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst8SVb14 const4e07408562bedb8b60ce05c1) (let __tconst9RUv13 consta7fdc4e6e62bd8f54a36b6a0) (let __tconst9c4b10 const6b86b273ff34fce19d6b804e) (let __tconst6SRI9 constaee3d30407ccfb32dbb15266) (let __tconst1VMC6 constd4735e3a265e16eee03f5971) (let __tconst5CQt5 conste523f9d32d200d4c898117c9) (let __tconst1R3Z1 const3239cd974435e50a8b8f46b4)) (probe dleaf (1 0) 1 __tconst9c4b10 __t3Ckq3) (body (exists dleaf (1 0) 1 __tconst8SVb14) (join dleaf (1 0) 1 __tconst1VMC6 __t6EsA7) (join dleaf (1 0) 1 __tconst8SVb14 __t048Z15)) (head (mkstruct dnode (2 1 0) __t9IRE16 __tconst9RUv13 __t048Z15) (mkstruct dnode (2 1 0) __t17r112 __tconst6SRI9 __t3Ckq3) (mkstruct dnode (2 1 0) __t75Ua8 __tconst5CQt5 __t6EsA7) (mkstruct dnode (2 1 0) __t6S9A4 __tconst1R3Z1 __t3Ckq3)) sdeep_deepjoin.slog:12 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** dleafindex0;  slog::Index** dleafindex1;  slog::Index** dleafindex2;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("dnode");
      head_rel[1] = db->getRelation("dnode");
      head_rel[2] = db->getRelation("dnode");
      head_rel[3] = db->getRelation("dnode");
      std::vector<u16> ord4({1, 0});
      slog::Relation* readrel5 = db->getRelation("dleaf");
      driver_index = readrel5->getIndex(ord4, true);
      std::vector<u16> ord6({1, 0});
      slog::Relation* readrel7 = db->getRelation("dleaf");
      dleafindex0 = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({1, 0});
      slog::Relation* readrel9 = db->getRelation("dleaf");
      dleafindex1 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 0});
      slog::Relation* readrel11 = db->getRelation("dleaf");
      dleafindex2 = readrel11->getIndex(ord10, false);
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_consta7fdc4e6e62bd8f54a36b6a0;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_conste523f9d32d200d4c898117c9;
      u64 v_c6 = v_const3239cd974435e50a8b8f46b4;
  
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
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c2, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m12) {
        u64 v_c7 = m12[1];
        if (buckethash(v_c7) != bucket) return;
        if (!slog::exists_probe<2,1>(dleafindex0, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(dleafindex1, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m13) {
          u64 v_c8 = m13[1];
          slog::join_probe<2,1>(dleafindex2, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m14) {
            u64 v_c9 = m14[1];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c9}, std::array<u16,3>{2, 1, 0});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c3, v_c7}, std::array<u16,3>{2, 1, 0});
            slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c5, v_c8}, std::array<u16,3>{2, 1, 0});
            slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c6, v_c7}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("sdeep_deepjoin.slog:12", "delta:dleaf", _fires);
  
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
      s->addTask(phase_read, new ReadTask3(db,b), false);
  // (crule (pre (let __tconst8SVb14 const4e07408562bedb8b60ce05c1) (let __tconst9RUv13 consta7fdc4e6e62bd8f54a36b6a0) (let __tconst9c4b10 const6b86b273ff34fce19d6b804e) (let __tconst6SRI9 constaee3d30407ccfb32dbb15266) (let __tconst1VMC6 constd4735e3a265e16eee03f5971) (let __tconst5CQt5 conste523f9d32d200d4c898117c9) (let __tconst1R3Z1 const3239cd974435e50a8b8f46b4)) (once) (body) (head (mkstruct dleaf (1 0) __t048Z15 __tconst8SVb14) (mkstruct dleaf (1 0) __t6EsA7 __tconst1VMC6) (mkstruct dleaf (1 0) __t3Ckq3 __tconst9c4b10)) sdeep_deepjoin.slog:12 #f)
  class ReadTask15 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("dleaf");
      head_rel[1] = db->getRelation("dleaf");
      head_rel[2] = db->getRelation("dleaf");
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_consta7fdc4e6e62bd8f54a36b6a0;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_conste523f9d32d200d4c898117c9;
      u64 v_c6 = v_const3239cd974435e50a8b8f46b4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("sdeep_deepjoin.slog:12", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), true);
  // (crule (pre (let __tconst9RUv13 consta7fdc4e6e62bd8f54a36b6a0) (let __tconst6SRI9 constaee3d30407ccfb32dbb15266) (let __tconst5CQt5 conste523f9d32d200d4c898117c9) (let __tconst1R3Z1 const3239cd974435e50a8b8f46b4) (let __tconst8SVb14 const4e07408562bedb8b60ce05c1) (let __tconst9c4b10 const6b86b273ff34fce19d6b804e) (let __tconst1VMC6 constd4735e3a265e16eee03f5971)) (probe dnode (2 0 1) 1 __tconst1R3Z1 __t6S9A4 __t3Ckq3) (body (join dleaf (0 1) 2 __t3Ckq3 __tconst9c4b10) (exists dleaf (1 0) 1 __tconst1VMC6) (exists dnode (2 1 0) 1 __tconst5CQt5) (exists dleaf (1 0) 1 __tconst8SVb14) (exists dnode (2 1 0) 1 __tconst9RUv13) (join dnode (2 1 0) 2 __tconst6SRI9 __t3Ckq3 __t17r112) (join dleaf (1 0) 1 __tconst1VMC6 __t6EsA7) (join dnode (2 1 0) 2 __tconst5CQt5 __t6EsA7 __t75Ua8) (join dleaf (1 0) 1 __tconst8SVb14 __t048Z15) (join dnode (2 1 0) 2 __tconst9RUv13 __t048Z15 __t9IRE16)) (head (emit right (0) __t9IRE16) (emit right (0) __t17r112) (emit left (0) __t75Ua8) (emit left (0) __t6S9A4)) sdeep_deepjoin.slog:12 #f)
  class ReadTask26 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** dleafindex16;  slog::Index** dleafindex17;  slog::Index** dnodeindex18;  slog::Index** dleafindex19;  slog::Index** dnodeindex20;  slog::Index** dnodeindex21;  slog::Index** dleafindex22;  slog::Index** dnodeindex23;  slog::Index** dleafindex24;  slog::Index** dnodeindex25;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("right");
      std::vector<u16> ord27({0});
      slog::Relation* readrel28 = db->getRelation("right");
      head_index[0] = readrel28->getIndex(ord27, false);
      head_rel[1] = db->getRelation("right");
      std::vector<u16> ord29({0});
      slog::Relation* readrel30 = db->getRelation("right");
      head_index[1] = readrel30->getIndex(ord29, false);
      head_rel[2] = db->getRelation("left");
      std::vector<u16> ord31({0});
      slog::Relation* readrel32 = db->getRelation("left");
      head_index[2] = readrel32->getIndex(ord31, false);
      head_rel[3] = db->getRelation("left");
      std::vector<u16> ord33({0});
      slog::Relation* readrel34 = db->getRelation("left");
      head_index[3] = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({2, 0, 1});
      slog::Relation* readrel36 = db->getRelation("dnode");
      driver_index = readrel36->getIndex(ord35, true);
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("dleaf");
      dleafindex16 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 0});
      slog::Relation* readrel40 = db->getRelation("dleaf");
      dleafindex17 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({2, 1, 0});
      slog::Relation* readrel42 = db->getRelation("dnode");
      dnodeindex18 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 0});
      slog::Relation* readrel44 = db->getRelation("dleaf");
      dleafindex19 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({2, 1, 0});
      slog::Relation* readrel46 = db->getRelation("dnode");
      dnodeindex20 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({2, 1, 0});
      slog::Relation* readrel48 = db->getRelation("dnode");
      dnodeindex21 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 0});
      slog::Relation* readrel50 = db->getRelation("dleaf");
      dleafindex22 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({2, 1, 0});
      slog::Relation* readrel52 = db->getRelation("dnode");
      dnodeindex23 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 0});
      slog::Relation* readrel54 = db->getRelation("dleaf");
      dleafindex24 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({2, 1, 0});
      slog::Relation* readrel56 = db->getRelation("dnode");
      dnodeindex25 = readrel56->getIndex(ord55, false);
  
    }
    ReadTask26(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_consta7fdc4e6e62bd8f54a36b6a0;
      u64 v_c3 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c5 = v_conste523f9d32d200d4c898117c9;
      u64 v_c6 = v_const3239cd974435e50a8b8f46b4;
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c6, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m57) {
        u64 v_c10 = m57[1];
        u64 v_c7 = m57[2];
        if (buckethash(v_c10) != bucket) return;
        slog::join_probe<2,2>(dleafindex16, std::array<u64,2>{v_c7, v_c2}, [&](const std::array<u64,2>& m58) {
          if (!slog::exists_probe<2,1>(dleafindex17, std::array<u64,2>{v_c4, 0})) return;
          if (!slog::exists_probe<3,1>(dnodeindex18, std::array<u64,3>{v_c5, 0, 0})) return;
          if (!slog::exists_probe<2,1>(dleafindex19, std::array<u64,2>{v_c0, 0})) return;
          if (!slog::exists_probe<3,1>(dnodeindex20, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe<3,2>(dnodeindex21, std::array<u64,3>{v_c3, v_c7, 0}, [&](const std::array<u64,3>& m59) {
            u64 v_c11 = m59[2];
            slog::join_probe<2,1>(dleafindex22, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m60) {
              u64 v_c8 = m60[1];
              slog::join_probe<3,2>(dnodeindex23, std::array<u64,3>{v_c5, v_c8, 0}, [&](const std::array<u64,3>& m61) {
                u64 v_c12 = m61[2];
                slog::join_probe<2,1>(dleafindex24, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m62) {
                  u64 v_c9 = m62[1];
                  slog::join_probe<3,2>(dnodeindex25, std::array<u64,3>{v_c1, v_c9, 0}, [&](const std::array<u64,3>& m63) {
                    u64 v_c13 = m63[2];
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
                    slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c11}, std::array<u16,1>{0});
                    slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
                    slog::emit<1>(head_rel[3], head_index[3], newbatch[3], std::array<u64,1>{v_c10}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("sdeep_deepjoin.slog:12", "delta:dnode", _fires);
  
      if (!_done)
      {
        ReadTask26* _cont = new ReadTask26(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask26(db,b), false);
  // (crule (pre (let __tconst9RUv13 consta7fdc4e6e62bd8f54a36b6a0) (let __tconst6SRI9 constaee3d30407ccfb32dbb15266) (let __tconst5CQt5 conste523f9d32d200d4c898117c9) (let __tconst1R3Z1 const3239cd974435e50a8b8f46b4) (let __tconst8SVb14 const4e07408562bedb8b60ce05c1) (let __tconst9c4b10 const6b86b273ff34fce19d6b804e) (let __tconst1VMC6 constd4735e3a265e16eee03f5971)) (seeded) (body (join dleaf (1 0) 1 __tconst9c4b10 __t3Ckq3) (exists dnode (2 1 0) 2 __tconst6SRI9 __t3Ckq3) (exists dleaf (1 0) 1 __tconst1VMC6) (exists dnode (2 1 0) 1 __tconst5CQt5) (exists dleaf (1 0) 1 __tconst8SVb14) (exists dnode (2 1 0) 1 __tconst9RUv13) (join dnode (2 1 0) 2 __tconst1R3Z1 __t3Ckq3 __t6S9A4) (join dnode (2 1 0) 2 __tconst6SRI9 __t3Ckq3 __t17r112) (join dleaf (1 0) 1 __tconst1VMC6 __t6EsA7) (join dnode (2 1 0) 2 __tconst5CQt5 __t6EsA7 __t75Ua8) (join dleaf (1 0) 1 __tconst8SVb14 __t048Z15) (join dnode (2 1 0) 2 __tconst9RUv13 __t048Z15 __t9IRE16)) (head (emit right (0) __t9IRE16) (emit right (0) __t17r112) (emit left (0) __t75Ua8) (emit left (0) __t6S9A4)) sdeep_deepjoin.slog:12 #f)
  class ReadTask76 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
    slog::Index** dleafindex64;  slog::Index** dnodeindex65;  slog::Index** dleafindex66;  slog::Index** dnodeindex67;  slog::Index** dleafindex68;  slog::Index** dnodeindex69;  slog::Index** dnodeindex70;  slog::Index** dnodeindex71;  slog::Index** dleafindex72;  slog::Index** dnodeindex73;  slog::Index** dleafindex74;  slog::Index** dnodeindex75;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("right");
      std::vector<u16> ord77({0});
      slog::Relation* readrel78 = db->getRelation("right");
      head_index[0] = readrel78->getIndex(ord77, false);
      head_rel[1] = db->getRelation("right");
      std::vector<u16> ord79({0});
      slog::Relation* readrel80 = db->getRelation("right");
      head_index[1] = readrel80->getIndex(ord79, false);
      head_rel[2] = db->getRelation("left");
      std::vector<u16> ord81({0});
      slog::Relation* readrel82 = db->getRelation("left");
      head_index[2] = readrel82->getIndex(ord81, false);
      head_rel[3] = db->getRelation("left");
      std::vector<u16> ord83({0});
      slog::Relation* readrel84 = db->getRelation("left");
      head_index[3] = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({1, 0});
      slog::Relation* readrel86 = db->getRelation("dleaf");
      dleafindex64 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({2, 1, 0});
      slog::Relation* readrel88 = db->getRelation("dnode");
      dnodeindex65 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 0});
      slog::Relation* readrel90 = db->getRelation("dleaf");
      dleafindex66 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({2, 1, 0});
      slog::Relation* readrel92 = db->getRelation("dnode");
      dnodeindex67 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 0});
      slog::Relation* readrel94 = db->getRelation("dleaf");
      dleafindex68 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({2, 1, 0});
      slog::Relation* readrel96 = db->getRelation("dnode");
      dnodeindex69 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({2, 1, 0});
      slog::Relation* readrel98 = db->getRelation("dnode");
      dnodeindex70 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({2, 1, 0});
      slog::Relation* readrel100 = db->getRelation("dnode");
      dnodeindex71 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("dleaf");
      dleafindex72 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({2, 1, 0});
      slog::Relation* readrel104 = db->getRelation("dnode");
      dnodeindex73 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 0});
      slog::Relation* readrel106 = db->getRelation("dleaf");
      dleafindex74 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({2, 1, 0});
      slog::Relation* readrel108 = db->getRelation("dnode");
      dnodeindex75 = readrel108->getIndex(ord107, false);
  
    }
    ReadTask76(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_consta7fdc4e6e62bd8f54a36b6a0;
      u64 v_c3 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c5 = v_conste523f9d32d200d4c898117c9;
      u64 v_c6 = v_const3239cd974435e50a8b8f46b4;
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(dleafindex64, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m109) {
        u64 v_c7 = m109[1];
        if (!slog::exists_probe<3,2>(dnodeindex65, std::array<u64,3>{v_c3, v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(dleafindex66, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(dnodeindex67, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<2,1>(dleafindex68, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<3,1>(dnodeindex69, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<3,2>(dnodeindex70, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m110) {
          u64 v_c10 = m110[2];
          slog::join_probe<3,2>(dnodeindex71, std::array<u64,3>{v_c3, v_c7, 0}, [&](const std::array<u64,3>& m111) {
            u64 v_c11 = m111[2];
            slog::join_probe<2,1>(dleafindex72, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m112) {
              u64 v_c8 = m112[1];
              slog::join_probe<3,2>(dnodeindex73, std::array<u64,3>{v_c5, v_c8, 0}, [&](const std::array<u64,3>& m113) {
                u64 v_c12 = m113[2];
                slog::join_probe<2,1>(dleafindex74, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m114) {
                  u64 v_c9 = m114[1];
                  slog::join_probe<3,2>(dnodeindex75, std::array<u64,3>{v_c1, v_c9, 0}, [&](const std::array<u64,3>& m115) {
                    u64 v_c13 = m115[2];
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c13}, std::array<u16,1>{0});
                    slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c11}, std::array<u16,1>{0});
                    slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c12}, std::array<u16,1>{0});
                    slog::emit<1>(head_rel[3], head_index[3], newbatch[3], std::array<u64,1>{v_c10}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("sdeep_deepjoin.slog:12", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask76(db,b));
  // (crule (pre (let __tconst8SVb14 const4e07408562bedb8b60ce05c1) (let __tconst9RUv13 consta7fdc4e6e62bd8f54a36b6a0) (let __tconst9c4b10 const6b86b273ff34fce19d6b804e) (let __tconst6SRI9 constaee3d30407ccfb32dbb15266) (let __tconst1VMC6 constd4735e3a265e16eee03f5971) (let __tconst5CQt5 conste523f9d32d200d4c898117c9) (let __tconst1R3Z1 const3239cd974435e50a8b8f46b4)) (seeded) (body (join dleaf (1 0) 1 __tconst9c4b10 __t3Ckq3) (exists dleaf (1 0) 1 __tconst8SVb14) (join dleaf (1 0) 1 __tconst1VMC6 __t6EsA7) (join dleaf (1 0) 1 __tconst8SVb14 __t048Z15)) (head (mkstruct dnode (2 1 0) __t9IRE16 __tconst9RUv13 __t048Z15) (mkstruct dnode (2 1 0) __t17r112 __tconst6SRI9 __t3Ckq3) (mkstruct dnode (2 1 0) __t75Ua8 __tconst5CQt5 __t6EsA7) (mkstruct dnode (2 1 0) __t6S9A4 __tconst1R3Z1 __t3Ckq3)) sdeep_deepjoin.slog:12 #f)
  class ReadTask120 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
    slog::Index** dleafindex116;  slog::Index** dleafindex117;  slog::Index** dleafindex118;  slog::Index** dleafindex119;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("dnode");
      std::vector<u16> ord121({2, 1, 0});
      slog::Relation* readrel122 = db->getRelation("dnode");
      head_index[0] = readrel122->getIndex(ord121, false);
      head_rel[1] = db->getRelation("dnode");
      std::vector<u16> ord123({2, 1, 0});
      slog::Relation* readrel124 = db->getRelation("dnode");
      head_index[1] = readrel124->getIndex(ord123, false);
      head_rel[2] = db->getRelation("dnode");
      std::vector<u16> ord125({2, 1, 0});
      slog::Relation* readrel126 = db->getRelation("dnode");
      head_index[2] = readrel126->getIndex(ord125, false);
      head_rel[3] = db->getRelation("dnode");
      std::vector<u16> ord127({2, 1, 0});
      slog::Relation* readrel128 = db->getRelation("dnode");
      head_index[3] = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({1, 0});
      slog::Relation* readrel130 = db->getRelation("dleaf");
      dleafindex116 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({1, 0});
      slog::Relation* readrel132 = db->getRelation("dleaf");
      dleafindex117 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 0});
      slog::Relation* readrel134 = db->getRelation("dleaf");
      dleafindex118 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 0});
      slog::Relation* readrel136 = db->getRelation("dleaf");
      dleafindex119 = readrel136->getIndex(ord135, false);
  
    }
    ReadTask120(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_consta7fdc4e6e62bd8f54a36b6a0;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c4 = v_constd4735e3a265e16eee03f5971;
      u64 v_c5 = v_conste523f9d32d200d4c898117c9;
      u64 v_c6 = v_const3239cd974435e50a8b8f46b4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(dleafindex116, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m137) {
        u64 v_c7 = m137[1];
        if (!slog::exists_probe<2,1>(dleafindex117, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(dleafindex118, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m138) {
          u64 v_c8 = m138[1];
          slog::join_probe<2,1>(dleafindex119, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m139) {
            u64 v_c9 = m139[1];
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c9}, std::array<u16,3>{2, 1, 0});
            slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c3, v_c7}, std::array<u16,3>{2, 1, 0});
            slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c5, v_c8}, std::array<u16,3>{2, 1, 0});
            slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c6, v_c7}, std::array<u16,3>{2, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("sdeep_deepjoin.slog:12", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask120(db,b));
  s->addReadRel("dleaf");
  s->addReadRel("dnode");
  s->addDynamicRel("dleaf");
  s->addDynamicRel("dnode");
  s->addDynamicRel("left");
  s->addDynamicRel("right");
  d->push(s);
  d->continueRun();
}

