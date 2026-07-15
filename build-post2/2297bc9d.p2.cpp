
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const2bc983a5942276eb00a75e21;
extern u64 v_const30f8b180d63559f2512b744f;
extern u64 v_const38c0e144c051f35df0684885;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b51d0145b30dda2c4043c68;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_constb40d060f542e4963e0fc1392;
extern u64 v_constba2df4903a2c14e86dc3bcca;


void slog_rules_c24b1db1dd6410ea4(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan ck_ans __t37kq10 t1) (body (join-old arrow (1 2 0) 1 (1 2 0) t1 t2 __t9HVg9) (join ck_ans (1 0) 1 __t9HVg9 __t17cq8) (join-old ck (0 1 2) 1 (0 1 2) __t17cq8 env e1) (exists $sup76879x16x0x0x0 (1 3 0 2) 2 e1 env) (exists app (1 2 0) 1 e1) (exists ck (1 2 0) 1 env) (join-old ck (0 1 2) 2 (0 1 2) __t37kq10 env e2) (exists app (1 2 0) 2 e1 e2) (join-old $sup76879x16x0x0x0 (1 2 3 0) 3 (1 2 3 0) e1 e2 env __t6Npw7) (exists ck (0 1 2) 2 __t6Npw7 env) (join-old app (1 2 0) 2 (1 2 0) e1 e2 __t3xua6) (join-old ck (0 1 2) 3 (0 1 2) __t6Npw7 env __t3xua6)) (head (emit ck_ans (0 1) __t6Npw7 t2)) dem_stlc.slog:17 #f)
  class ReadTask18 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** arrowindex0;  slog::Index** ck_ansindex1;  slog::Index** ckindex2;  slog::Index** $sup76879x16x0x0x0index3;  slog::Index** appindex4;  slog::Index** ckindex5;  slog::Index** ckindex6;  slog::Index** appindex7;  slog::Index** $sup76879x16x0x0x0index8;  slog::Index** ckindex9;  slog::Index** appindex10;  slog::Index** ckindex11;  slog::Index** arrowdelta12;  slog::Index** ckdelta13;  slog::Index** ckdelta14;  slog::Index** $sup76879x16x0x0x0delta15;  slog::Index** appdelta16;  slog::Index** ckdelta17;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord19({0, 1});
      slog::Relation* readrel20 = db->getRelation("ck_ans");
      head_index[0] = readrel20->getIndex(ord19, false);
      outer_rel = db->getRelation("ck_ans");
      std::vector<u16> ord21({1, 2, 0});
      slog::Relation* readrel22 = db->getRelation("arrow");
      arrowindex0 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 2, 0});
      slog::Relation* readrel24 = db->getRelation("arrow");
      arrowdelta12 = readrel24->getIndex(ord23, true);
      std::vector<u16> ord25({1, 0});
      slog::Relation* readrel26 = db->getRelation("ck_ans");
      ck_ansindex1 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({0, 1, 2});
      slog::Relation* readrel28 = db->getRelation("ck");
      ckindex2 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({0, 1, 2});
      slog::Relation* readrel30 = db->getRelation("ck");
      ckdelta13 = readrel30->getIndex(ord29, true);
      std::vector<u16> ord31({1, 3, 0, 2});
      slog::Relation* readrel32 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0index3 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0});
      slog::Relation* readrel34 = db->getRelation("app");
      appindex4 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 2, 0});
      slog::Relation* readrel36 = db->getRelation("ck");
      ckindex5 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({0, 1, 2});
      slog::Relation* readrel38 = db->getRelation("ck");
      ckindex6 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 1, 2});
      slog::Relation* readrel40 = db->getRelation("ck");
      ckdelta14 = readrel40->getIndex(ord39, true);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("app");
      appindex7 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 3, 0});
      slog::Relation* readrel44 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0index8 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 2, 3, 0});
      slog::Relation* readrel46 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0delta15 = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({0, 1, 2});
      slog::Relation* readrel48 = db->getRelation("ck");
      ckindex9 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 2, 0});
      slog::Relation* readrel50 = db->getRelation("app");
      appindex10 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("app");
      appdelta16 = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({0, 1, 2});
      slog::Relation* readrel54 = db->getRelation("ck");
      ckindex11 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({0, 1, 2});
      slog::Relation* readrel56 = db->getRelation("ck");
      ckdelta17 = readrel56->getIndex(ord55, true);
  
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
        u64 v_c0 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe_old<3,1>(arrowindex0, arrowdelta12, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m57) {
          u64 v_c2 = m57[1]; u64 v_c3 = m57[2];
          slog::join_probe<2,1>(ck_ansindex1, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m58) {
            u64 v_c4 = m58[1];
            slog::join_probe_old<3,1>(ckindex2, ckdelta13, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m59) {
              u64 v_c5 = m59[1]; u64 v_c6 = m59[2];
              if (!slog::exists_probe<4,2>($sup76879x16x0x0x0index3, std::array<u64,4>{v_c6, v_c5, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex4, std::array<u64,3>{v_c6, 0, 0})) return;
              if (!slog::exists_probe<3,1>(ckindex5, std::array<u64,3>{v_c5, 0, 0})) return;
              slog::join_probe_old<3,2>(ckindex6, ckdelta14, std::array<u64,3>{v_c0, v_c5, 0}, [&](const std::array<u64,3>& m60) {
                u64 v_c7 = m60[2];
                if (!slog::exists_probe<3,2>(appindex7, std::array<u64,3>{v_c6, v_c7, 0})) return;
                slog::join_probe_old<4,3>($sup76879x16x0x0x0index8, $sup76879x16x0x0x0delta15, std::array<u64,4>{v_c6, v_c7, v_c5, 0}, [&](const std::array<u64,4>& m61) {
                  u64 v_c8 = m61[3];
                  if (!slog::exists_probe<3,2>(ckindex9, std::array<u64,3>{v_c8, v_c5, 0})) return;
                  slog::join_probe_old<3,2>(appindex10, appdelta16, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m62) {
                    u64 v_c9 = m62[2];
                    slog::join_probe_old<3,3>(ckindex11, ckdelta17, std::array<u64,3>{v_c8, v_c5, v_c9}, [&](const std::array<u64,3>& m63) {
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c8, v_c2}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:ck_ans", _fires);
  
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
  // (crule (pre (let __tconst0hXo78 constb40d060f542e4963e0fc1392)) (scan ck __t0Y0I55 env __t6P2x54) (body (join _enum (1 0) 1 __tconst0hXo78 __t2VZ853) (join num (0 1) 1 __t6P2x54 i)) (head (emit ck_ans (0 1) __t0Y0I55 __t2VZ853)) dem_stlc.slog:14 #f)
  class ReadTask66 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex64;  slog::Index** numindex65;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord67({0, 1});
      slog::Relation* readrel68 = db->getRelation("ck_ans");
      head_index[0] = readrel68->getIndex(ord67, false);
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord69({1, 0});
      slog::Relation* readrel70 = db->getRelation("_enum");
      _enumindex64 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({0, 1});
      slog::Relation* readrel72 = db->getRelation("num");
      numindex65 = readrel72->getIndex(ord71, false);
  
    }
    ReadTask66(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_constb40d060f542e4963e0fc1392;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe<2,1>(_enumindex64, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m73) {
          u64 v_c13 = m73[1];
          slog::join_probe<2,1>(numindex65, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m74) {
            u64 v_c14 = m74[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c11, v_c13}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:14", "delta:ck", _fires);
  
      if (!_done)
      {
        ReadTask66* _cont = new ReadTask66(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask66(db,b), false);
  // (crule (pre) (scan lookup __t5u0262 __t1moV61 x) (body (join ext (0 2 1 3) 1 __t1moV61 y env ____7sx763) (neq x y)) (head (emit $sup76879x10x0x0x0 (0 2 1 3) __t5u0262 x env y)) dem_stlc.slog:11 #f)
  class ReadTask76 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extindex75;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup76879x10x0x0x0");
      std::vector<u16> ord77({0, 2, 1, 3});
      slog::Relation* readrel78 = db->getRelation("$sup76879x10x0x0x0");
      head_index[0] = readrel78->getIndex(ord77, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord79({0, 2, 1, 3});
      slog::Relation* readrel80 = db->getRelation("ext");
      extindex75 = readrel80->getIndex(ord79, false);
  
    }
    ReadTask76(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe<4,1>(extindex75, std::array<u64,4>{v_c16, 0, 0, 0}, [&](const std::array<u64,4>& m81) {
          u64 v_c18 = m81[1]; u64 v_c5 = m81[2]; u64 v_c19 = m81[3];
          if (v_c17 == v_c18) return;
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c15, v_c17, v_c5, v_c18}, std::array<u16,4>{0, 2, 1, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:11", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask76* _cont = new ReadTask76(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask76(db,b), false);
  // (crule (pre) (scan lookup __t7RPo65 __t9GTJ64 x) (body (join ext (0 2 1 3) 2 __t9GTJ64 x env t)) (head (emit lookup_ans (0 1) __t7RPo65 t)) dem_stlc.slog:10 #f)
  class ReadTask83 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extindex82;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("lookup_ans");
      head_index[0] = readrel85->getIndex(ord84, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord86({0, 2, 1, 3});
      slog::Relation* readrel87 = db->getRelation("ext");
      extindex82 = readrel87->getIndex(ord86, false);
  
    }
    ReadTask83(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[2];
        slog::join_probe<4,2>(extindex82, std::array<u64,4>{v_c21, v_c17, 0, 0}, [&](const std::array<u64,4>& m88) {
          u64 v_c5 = m88[2]; u64 v_c22 = m88[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c20, v_c22}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:10", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask83* _cont = new ReadTask83(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask83(db,b), false);
  // (crule (pre) (scan var __t6OR216 x) (body (exists lookup (2 0 1) 1 x) (join-old ck (2 0 1) 1 (2 0 1) __t6OR216 __t43Yp17 env) (join-old lookup (1 2 0) 2 (1 2 0) env x __t9Fqg18) (join lookup_ans (0 1) 1 __t9Fqg18 __v0)) (head (emit ck_ans (0 1) __t43Yp17 __v0)) dem_stlc.slog:15 #f)
  class ReadTask95 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex89;  slog::Index** ckindex90;  slog::Index** lookupindex91;  slog::Index** lookup_ansindex92;  slog::Index** ckdelta93;  slog::Index** lookupdelta94;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord96({0, 1});
      slog::Relation* readrel97 = db->getRelation("ck_ans");
      head_index[0] = readrel97->getIndex(ord96, false);
      outer_rel = db->getRelation("var");
      std::vector<u16> ord98({2, 0, 1});
      slog::Relation* readrel99 = db->getRelation("lookup");
      lookupindex89 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({2, 0, 1});
      slog::Relation* readrel101 = db->getRelation("ck");
      ckindex90 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({2, 0, 1});
      slog::Relation* readrel103 = db->getRelation("ck");
      ckdelta93 = readrel103->getIndex(ord102, true);
      std::vector<u16> ord104({1, 2, 0});
      slog::Relation* readrel105 = db->getRelation("lookup");
      lookupindex91 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 2, 0});
      slog::Relation* readrel107 = db->getRelation("lookup");
      lookupdelta94 = readrel107->getIndex(ord106, true);
      std::vector<u16> ord108({0, 1});
      slog::Relation* readrel109 = db->getRelation("lookup_ans");
      lookup_ansindex92 = readrel109->getIndex(ord108, false);
  
    }
    ReadTask95(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        if (!slog::exists_probe<3,1>(lookupindex89, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe_old<3,1>(ckindex90, ckdelta93, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m110) {
          u64 v_c24 = m110[1]; u64 v_c5 = m110[2];
          slog::join_probe_old<3,2>(lookupindex91, lookupdelta94, std::array<u64,3>{v_c5, v_c17, 0}, [&](const std::array<u64,3>& m111) {
            u64 v_c25 = m111[2];
            slog::join_probe<2,1>(lookup_ansindex92, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m112) {
              u64 v_c26 = m112[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c26}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:15", "delta:var", _fires);
  
      if (!_done)
      {
        ReadTask95* _cont = new ReadTask95(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask95(db,b), false);
  // (crule (pre) (scan ext __t538W56 env y ____2zPL59) (body (exists lookup (1 2 0) 1 __t538W56) (exists lookup (1 2 0) 1 env) (join $sup76879x10x0x0x0 (1 3 0 2) 2 env y __t4rN257 x) (neq x y) (join-old lookup (0 2 1) 3 (0 2 1) __t4rN257 x __t538W56) (join-old lookup (1 2 0) 2 (1 2 0) env x __t8ds158) (join lookup_ans (0 1) 1 __t8ds158 t)) (head (emit lookup_ans (0 1) __t4rN257 t)) dem_stlc.slog:11 #f)
  class ReadTask121 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex113;  slog::Index** lookupindex114;  slog::Index** $sup76879x10x0x0x0index115;  slog::Index** lookupindex116;  slog::Index** lookupindex117;  slog::Index** lookup_ansindex118;  slog::Index** lookupdelta119;  slog::Index** lookupdelta120;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord122({0, 1});
      slog::Relation* readrel123 = db->getRelation("lookup_ans");
      head_index[0] = readrel123->getIndex(ord122, false);
      outer_rel = db->getRelation("ext");
      std::vector<u16> ord124({1, 2, 0});
      slog::Relation* readrel125 = db->getRelation("lookup");
      lookupindex113 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("lookup");
      lookupindex114 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 3, 0, 2});
      slog::Relation* readrel129 = db->getRelation("$sup76879x10x0x0x0");
      $sup76879x10x0x0x0index115 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({0, 2, 1});
      slog::Relation* readrel131 = db->getRelation("lookup");
      lookupindex116 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({0, 2, 1});
      slog::Relation* readrel133 = db->getRelation("lookup");
      lookupdelta119 = readrel133->getIndex(ord132, true);
      std::vector<u16> ord134({1, 2, 0});
      slog::Relation* readrel135 = db->getRelation("lookup");
      lookupindex117 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("lookup");
      lookupdelta120 = readrel137->getIndex(ord136, true);
      std::vector<u16> ord138({0, 1});
      slog::Relation* readrel139 = db->getRelation("lookup_ans");
      lookup_ansindex118 = readrel139->getIndex(ord138, false);
  
    }
    ReadTask121(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c28 = _t[3];
        if (!slog::exists_probe<3,1>(lookupindex113, std::array<u64,3>{v_c27, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lookupindex114, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<4,2>($sup76879x10x0x0x0index115, std::array<u64,4>{v_c5, v_c18, 0, 0}, [&](const std::array<u64,4>& m140) {
          u64 v_c29 = m140[2]; u64 v_c17 = m140[3];
          if (v_c17 == v_c18) return;
          slog::join_probe_old<3,3>(lookupindex116, lookupdelta119, std::array<u64,3>{v_c29, v_c17, v_c27}, [&](const std::array<u64,3>& m141) {
            slog::join_probe_old<3,2>(lookupindex117, lookupdelta120, std::array<u64,3>{v_c5, v_c17, 0}, [&](const std::array<u64,3>& m142) {
              u64 v_c30 = m142[2];
              slog::join_probe<2,1>(lookup_ansindex118, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m143) {
                u64 v_c22 = m143[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c22}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:11", "delta:ext", _fires);
  
      if (!_done)
      {
        ReadTask121* _cont = new ReadTask121(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask121(db,b), false);
  // (crule (pre) (scan app __t3xua6 e1 e2) (body (exists ck (2 0 1) 1 __t3xua6) (exists ck (2 0 1) 1 e1) (exists ck (2 0 1) 1 e2) (join $sup76879x16x0x0x0 (1 2 3 0) 2 e1 e2 env __t6Npw7) (join-old ck (0 1 2) 3 (0 1 2) __t6Npw7 env __t3xua6) (exists ck (1 2 0) 2 env e2) (join-old ck (1 2 0) 2 (1 2 0) env e1 __t17cq8) (exists ck_ans (0 1) 1 __t17cq8) (join-old ck (1 2 0) 2 (1 2 0) env e2 __t37kq10) (exists ck_ans (0 1) 1 __t37kq10) (join ck_ans (0 1) 1 __t17cq8 __t9HVg9) (join ck_ans (0 1) 1 __t37kq10 t1) (join-old arrow (0 1 2) 2 (0 1 2) __t9HVg9 t1 t2)) (head (emit ck_ans (0 1) __t6Npw7 t2)) dem_stlc.slog:17 #f)
  class ReadTask161 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex144;  slog::Index** ckindex145;  slog::Index** ckindex146;  slog::Index** $sup76879x16x0x0x0index147;  slog::Index** ckindex148;  slog::Index** ckindex149;  slog::Index** ckindex150;  slog::Index** ck_ansindex151;  slog::Index** ckindex152;  slog::Index** ck_ansindex153;  slog::Index** ck_ansindex154;  slog::Index** ck_ansindex155;  slog::Index** arrowindex156;  slog::Index** ckdelta157;  slog::Index** ckdelta158;  slog::Index** ckdelta159;  slog::Index** arrowdelta160;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord162({0, 1});
      slog::Relation* readrel163 = db->getRelation("ck_ans");
      head_index[0] = readrel163->getIndex(ord162, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord164({2, 0, 1});
      slog::Relation* readrel165 = db->getRelation("ck");
      ckindex144 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({2, 0, 1});
      slog::Relation* readrel167 = db->getRelation("ck");
      ckindex145 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({2, 0, 1});
      slog::Relation* readrel169 = db->getRelation("ck");
      ckindex146 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 2, 3, 0});
      slog::Relation* readrel171 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0index147 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({0, 1, 2});
      slog::Relation* readrel173 = db->getRelation("ck");
      ckindex148 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({0, 1, 2});
      slog::Relation* readrel175 = db->getRelation("ck");
      ckdelta157 = readrel175->getIndex(ord174, true);
      std::vector<u16> ord176({1, 2, 0});
      slog::Relation* readrel177 = db->getRelation("ck");
      ckindex149 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 2, 0});
      slog::Relation* readrel179 = db->getRelation("ck");
      ckindex150 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 2, 0});
      slog::Relation* readrel181 = db->getRelation("ck");
      ckdelta158 = readrel181->getIndex(ord180, true);
      std::vector<u16> ord182({0, 1});
      slog::Relation* readrel183 = db->getRelation("ck_ans");
      ck_ansindex151 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 2, 0});
      slog::Relation* readrel185 = db->getRelation("ck");
      ckindex152 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 2, 0});
      slog::Relation* readrel187 = db->getRelation("ck");
      ckdelta159 = readrel187->getIndex(ord186, true);
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("ck_ans");
      ck_ansindex153 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({0, 1});
      slog::Relation* readrel191 = db->getRelation("ck_ans");
      ck_ansindex154 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("ck_ans");
      ck_ansindex155 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 1, 2});
      slog::Relation* readrel195 = db->getRelation("arrow");
      arrowindex156 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({0, 1, 2});
      slog::Relation* readrel197 = db->getRelation("arrow");
      arrowdelta160 = readrel197->getIndex(ord196, true);
  
    }
    ReadTask161(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<3,1>(ckindex144, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ckindex145, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ckindex146, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<4,2>($sup76879x16x0x0x0index147, std::array<u64,4>{v_c6, v_c7, 0, 0}, [&](const std::array<u64,4>& m198) {
          u64 v_c5 = m198[2]; u64 v_c8 = m198[3];
          slog::join_probe_old<3,3>(ckindex148, ckdelta157, std::array<u64,3>{v_c8, v_c5, v_c9}, [&](const std::array<u64,3>& m199) {
            if (!slog::exists_probe<3,2>(ckindex149, std::array<u64,3>{v_c5, v_c7, 0})) return;
            slog::join_probe_old<3,2>(ckindex150, ckdelta158, std::array<u64,3>{v_c5, v_c6, 0}, [&](const std::array<u64,3>& m200) {
              u64 v_c4 = m200[2];
              if (!slog::exists_probe<2,1>(ck_ansindex151, std::array<u64,2>{v_c4, 0})) return;
              slog::join_probe_old<3,2>(ckindex152, ckdelta159, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m201) {
                u64 v_c0 = m201[2];
                if (!slog::exists_probe<2,1>(ck_ansindex153, std::array<u64,2>{v_c0, 0})) return;
                slog::join_probe<2,1>(ck_ansindex154, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m202) {
                  u64 v_c3 = m202[1];
                  slog::join_probe<2,1>(ck_ansindex155, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m203) {
                    u64 v_c1 = m203[1];
                    slog::join_probe_old<3,2>(arrowindex156, arrowdelta160, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m204) {
                      u64 v_c2 = m204[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c8, v_c2}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask161* _cont = new ReadTask161(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask161(db,b), false);
  // (crule (pre (let __tconst8dNm51 constba2df4903a2c14e86dc3bcca) (let __tconst3JhQ48 const2bc983a5942276eb00a75e21) (let __tconst9nbj32 const30f8b180d63559f2512b744f) (let __tconst1wvy37 const4e07408562bedb8b60ce05c1) (let __tconst1K9r35 const4b227777d4dd1fc61c6f884f) (let __tconst8kEV24 const6b86b273ff34fce19d6b804e) (let __tconst6P6s76 constb40d060f542e4963e0fc1392)) (probe lam (1 0 2 3) 1 __tconst8dNm51 __t16B123 __t3zgy50 __t0OY020) (body (join _enum (0 1) 2 __t3zgy50 __tconst6P6s76) (join var (0 1) 2 __t0OY020 __tconst8dNm51) (exists var (1 0) 1 __tconst9nbj32) (exists num (1 0) 1 __tconst1K9r35) (exists num (1 0) 1 __tconst1wvy37) (exists var (1 0) 1 __tconst3JhQ48) (exists app (2 0 1) 1 __t0OY020) (exists arrow (1 2 0) 1 __t3zgy50) (join num (1 0) 1 __tconst8kEV24 __t95AJ25) (exists app (2 0 1) 1 __t95AJ25) (join var (1 0) 1 __tconst9nbj32 __t6EL627) (join app (1 2 0) 2 __t6EL627 __t95AJ25 __t7G7R28) (join num (1 0) 1 __tconst1K9r35 __t35Fj36) (exists app (2 0 1) 1 __t35Fj36) (join num (1 0) 1 __tconst1wvy37 __t7sPi38) (join app (1 2 0) 2 __t7sPi38 __t35Fj36 __t4b7B39) (join var (1 0) 1 __tconst3JhQ48 __t7Q1C43) (join app (1 2 0) 2 __t7Q1C43 __t0OY020 __t2MLp44) (join arrow (1 2 0) 1 __t3zgy50 dup2ODL112 __t4oeC31) (eq __t3zgy50 dup2ODL112)) (head (emit prog (0) __t4b7B39) (mkstruct lam (1 2 3 0) __t5JUn49 __tconst3JhQ48 __t4oeC31 __t2MLp44) (mkstruct lam (1 2 3 0) __t9fNk33 __tconst9nbj32 __t4oeC31 __t7G7R28)) dem_stlc.slog:23 #f)
  class ReadTask224 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,4> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex205;  slog::Index** varindex206;  slog::Index** varindex207;  slog::Index** numindex208;  slog::Index** numindex209;  slog::Index** varindex210;  slog::Index** appindex211;  slog::Index** arrowindex212;  slog::Index** numindex213;  slog::Index** appindex214;  slog::Index** varindex215;  slog::Index** appindex216;  slog::Index** numindex217;  slog::Index** appindex218;  slog::Index** numindex219;  slog::Index** appindex220;  slog::Index** varindex221;  slog::Index** appindex222;  slog::Index** arrowindex223;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord225({0});
      slog::Relation* readrel226 = db->getRelation("prog");
      head_index[0] = readrel226->getIndex(ord225, false);
      head_rel[1] = db->getRelation("lam");
      head_rel[2] = db->getRelation("lam");
      std::vector<u16> ord227({1, 0, 2, 3});
      slog::Relation* readrel228 = db->getRelation("lam");
      driver_index = readrel228->getIndex(ord227, true);
      std::vector<u16> ord229({0, 1});
      slog::Relation* readrel230 = db->getRelation("_enum");
      _enumindex205 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 1});
      slog::Relation* readrel232 = db->getRelation("var");
      varindex206 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 0});
      slog::Relation* readrel234 = db->getRelation("var");
      varindex207 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 0});
      slog::Relation* readrel236 = db->getRelation("num");
      numindex208 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 0});
      slog::Relation* readrel238 = db->getRelation("num");
      numindex209 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 0});
      slog::Relation* readrel240 = db->getRelation("var");
      varindex210 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({2, 0, 1});
      slog::Relation* readrel242 = db->getRelation("app");
      appindex211 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 2, 0});
      slog::Relation* readrel244 = db->getRelation("arrow");
      arrowindex212 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 0});
      slog::Relation* readrel246 = db->getRelation("num");
      numindex213 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({2, 0, 1});
      slog::Relation* readrel248 = db->getRelation("app");
      appindex214 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 0});
      slog::Relation* readrel250 = db->getRelation("var");
      varindex215 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 2, 0});
      slog::Relation* readrel252 = db->getRelation("app");
      appindex216 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 0});
      slog::Relation* readrel254 = db->getRelation("num");
      numindex217 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({2, 0, 1});
      slog::Relation* readrel256 = db->getRelation("app");
      appindex218 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 0});
      slog::Relation* readrel258 = db->getRelation("num");
      numindex219 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("app");
      appindex220 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 0});
      slog::Relation* readrel262 = db->getRelation("var");
      varindex221 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 2, 0});
      slog::Relation* readrel264 = db->getRelation("app");
      appindex222 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({1, 2, 0});
      slog::Relation* readrel266 = db->getRelation("arrow");
      arrowindex223 = readrel266->getIndex(ord265, false);
  
    }
    ReadTask224(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c32 = v_const2bc983a5942276eb00a75e21;
      u64 v_c33 = v_const30f8b180d63559f2512b744f;
      u64 v_c34 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c35 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c36 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c37 = v_constb40d060f542e4963e0fc1392;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,4> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<4,1>(driver_index, std::array<u64,4>{v_c31, 0, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,4>& m267) {
        u64 v_c38 = m267[1];
        u64 v_c39 = m267[2];
        u64 v_c40 = m267[3];
        if (buckethash(v_c38) != bucket) return;
        slog::join_probe<2,2>(_enumindex205, std::array<u64,2>{v_c39, v_c37}, [&](const std::array<u64,2>& m268) {
          slog::join_probe<2,2>(varindex206, std::array<u64,2>{v_c40, v_c31}, [&](const std::array<u64,2>& m269) {
            if (!slog::exists_probe<2,1>(varindex207, std::array<u64,2>{v_c33, 0})) return;
            if (!slog::exists_probe<2,1>(numindex208, std::array<u64,2>{v_c35, 0})) return;
            if (!slog::exists_probe<2,1>(numindex209, std::array<u64,2>{v_c34, 0})) return;
            if (!slog::exists_probe<2,1>(varindex210, std::array<u64,2>{v_c32, 0})) return;
            if (!slog::exists_probe<3,1>(appindex211, std::array<u64,3>{v_c40, 0, 0})) return;
            if (!slog::exists_probe<3,1>(arrowindex212, std::array<u64,3>{v_c39, 0, 0})) return;
            slog::join_probe<2,1>(numindex213, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m270) {
              u64 v_c41 = m270[1];
              if (!slog::exists_probe<3,1>(appindex214, std::array<u64,3>{v_c41, 0, 0})) return;
              slog::join_probe<2,1>(varindex215, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m271) {
                u64 v_c42 = m271[1];
                slog::join_probe<3,2>(appindex216, std::array<u64,3>{v_c42, v_c41, 0}, [&](const std::array<u64,3>& m272) {
                  u64 v_c43 = m272[2];
                  slog::join_probe<2,1>(numindex217, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m273) {
                    u64 v_c44 = m273[1];
                    if (!slog::exists_probe<3,1>(appindex218, std::array<u64,3>{v_c44, 0, 0})) return;
                    slog::join_probe<2,1>(numindex219, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m274) {
                      u64 v_c45 = m274[1];
                      slog::join_probe<3,2>(appindex220, std::array<u64,3>{v_c45, v_c44, 0}, [&](const std::array<u64,3>& m275) {
                        u64 v_c46 = m275[2];
                        slog::join_probe<2,1>(varindex221, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m276) {
                          u64 v_c47 = m276[1];
                          slog::join_probe<3,2>(appindex222, std::array<u64,3>{v_c47, v_c40, 0}, [&](const std::array<u64,3>& m277) {
                            u64 v_c48 = m277[2];
                            slog::join_probe<3,1>(arrowindex223, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m278) {
                              u64 v_c49 = m278[1]; u64 v_c50 = m278[2];
                              if (v_c39 != v_c49) return;
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c46}, std::array<u16,1>{0});
                              slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c32, v_c50, v_c48}, std::array<u16,4>{1, 2, 3, 0});
                              slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c33, v_c50, v_c43}, std::array<u16,4>{1, 2, 3, 0});
                            });
                          });
                        });
                      });
                    });
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
  
      if (_fires) db->bumpFires("dem_stlc.slog:23", "delta:lam", _fires);
  
      if (!_done)
      {
        ReadTask224* _cont = new ReadTask224(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask224(db,b), false);
  // (crule (pre) (scan ck __t43Yp17 env __t6OR216) (body (exists lookup (1 2 0) 1 env) (join var (0 1) 1 __t6OR216 x) (join-old lookup (1 2 0) 2 (1 2 0) env x __t9Fqg18) (join lookup_ans (0 1) 1 __t9Fqg18 __v0)) (head (emit ck_ans (0 1) __t43Yp17 __v0)) dem_stlc.slog:15 #f)
  class ReadTask284 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex279;  slog::Index** varindex280;  slog::Index** lookupindex281;  slog::Index** lookup_ansindex282;  slog::Index** lookupdelta283;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("ck_ans");
      head_index[0] = readrel286->getIndex(ord285, false);
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord287({1, 2, 0});
      slog::Relation* readrel288 = db->getRelation("lookup");
      lookupindex279 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1});
      slog::Relation* readrel290 = db->getRelation("var");
      varindex280 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 2, 0});
      slog::Relation* readrel292 = db->getRelation("lookup");
      lookupindex281 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 2, 0});
      slog::Relation* readrel294 = db->getRelation("lookup");
      lookupdelta283 = readrel294->getIndex(ord293, true);
      std::vector<u16> ord295({0, 1});
      slog::Relation* readrel296 = db->getRelation("lookup_ans");
      lookup_ansindex282 = readrel296->getIndex(ord295, false);
  
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
        u64 v_c24 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c23 = _t[2];
        if (!slog::exists_probe<3,1>(lookupindex279, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<2,1>(varindex280, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m297) {
          u64 v_c17 = m297[1];
          slog::join_probe_old<3,2>(lookupindex281, lookupdelta283, std::array<u64,3>{v_c5, v_c17, 0}, [&](const std::array<u64,3>& m298) {
            u64 v_c25 = m298[2];
            slog::join_probe<2,1>(lookup_ansindex282, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m299) {
              u64 v_c26 = m299[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c26}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:15", "delta:ck", _fires);
  
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
  // (crule (pre) (scan lookup_ans __t9Fqg18 __v0) (body (join-old lookup (0 2 1) 1 (0 2 1) __t9Fqg18 x env) (exists ck (1 2 0) 1 env) (join-old var (1 0) 1 (1 0) x __t6OR216) (join-old ck (1 2 0) 2 (1 2 0) env __t6OR216 __t43Yp17)) (head (emit ck_ans (0 1) __t43Yp17 __v0)) dem_stlc.slog:15 #f)
  class ReadTask307 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex300;  slog::Index** ckindex301;  slog::Index** varindex302;  slog::Index** ckindex303;  slog::Index** lookupdelta304;  slog::Index** vardelta305;  slog::Index** ckdelta306;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord308({0, 1});
      slog::Relation* readrel309 = db->getRelation("ck_ans");
      head_index[0] = readrel309->getIndex(ord308, false);
      outer_rel = db->getRelation("lookup_ans");
      std::vector<u16> ord310({0, 2, 1});
      slog::Relation* readrel311 = db->getRelation("lookup");
      lookupindex300 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({0, 2, 1});
      slog::Relation* readrel313 = db->getRelation("lookup");
      lookupdelta304 = readrel313->getIndex(ord312, true);
      std::vector<u16> ord314({1, 2, 0});
      slog::Relation* readrel315 = db->getRelation("ck");
      ckindex301 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 0});
      slog::Relation* readrel317 = db->getRelation("var");
      varindex302 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 0});
      slog::Relation* readrel319 = db->getRelation("var");
      vardelta305 = readrel319->getIndex(ord318, true);
      std::vector<u16> ord320({1, 2, 0});
      slog::Relation* readrel321 = db->getRelation("ck");
      ckindex303 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 2, 0});
      slog::Relation* readrel323 = db->getRelation("ck");
      ckdelta306 = readrel323->getIndex(ord322, true);
  
    }
    ReadTask307(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(lookupindex300, lookupdelta304, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m324) {
          u64 v_c17 = m324[1]; u64 v_c5 = m324[2];
          if (!slog::exists_probe<3,1>(ckindex301, std::array<u64,3>{v_c5, 0, 0})) return;
          slog::join_probe_old<2,1>(varindex302, vardelta305, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m325) {
            u64 v_c23 = m325[1];
            slog::join_probe_old<3,2>(ckindex303, ckdelta306, std::array<u64,3>{v_c5, v_c23, 0}, [&](const std::array<u64,3>& m326) {
              u64 v_c24 = m326[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c26}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:15", "delta:lookup_ans", _fires);
  
      if (!_done)
      {
        ReadTask307* _cont = new ReadTask307(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask307(db,b), false);
  // (crule (pre) (scan ck __t99AN3 env __t8P1X2) (body (exists ext (1 2 3 0) 1 env) (join lam (0 1 2 3) 1 __t8P1X2 x t1 e) (exists ck (2 0 1) 1 e) (join-old ext (1 2 3 0) 3 (1 2 3 0) env x t1 __t1FJ54) (join-old ck (1 2 0) 2 (1 2 0) __t1FJ54 e __t57LD5) (join ck_ans (0 1) 1 __t57LD5 __v0)) (head (emit-temp temp9j5e118 __t99AN3 __v0 t1) (mkstruct arrow (1 2 0) __t82gT1 t1 __v0)) dem_stlc.slog:16 #f)
  class ReadTask335 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extindex327;  slog::Index** lamindex328;  slog::Index** ckindex329;  slog::Index** extindex330;  slog::Index** ckindex331;  slog::Index** ck_ansindex332;  slog::Index** extdelta333;  slog::Index** ckdelta334;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9j5e118");
      head_rel[1] = db->getRelation("arrow");
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord336({1, 2, 3, 0});
      slog::Relation* readrel337 = db->getRelation("ext");
      extindex327 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({0, 1, 2, 3});
      slog::Relation* readrel339 = db->getRelation("lam");
      lamindex328 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({2, 0, 1});
      slog::Relation* readrel341 = db->getRelation("ck");
      ckindex329 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 2, 3, 0});
      slog::Relation* readrel343 = db->getRelation("ext");
      extindex330 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 2, 3, 0});
      slog::Relation* readrel345 = db->getRelation("ext");
      extdelta333 = readrel345->getIndex(ord344, true);
      std::vector<u16> ord346({1, 2, 0});
      slog::Relation* readrel347 = db->getRelation("ck");
      ckindex331 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({1, 2, 0});
      slog::Relation* readrel349 = db->getRelation("ck");
      ckdelta334 = readrel349->getIndex(ord348, true);
      std::vector<u16> ord350({0, 1});
      slog::Relation* readrel351 = db->getRelation("ck_ans");
      ck_ansindex332 = readrel351->getIndex(ord350, false);
  
    }
    ReadTask335(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c51 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c52 = _t[2];
        if (!slog::exists_probe<4,1>(extindex327, std::array<u64,4>{v_c5, 0, 0, 0})) return;
        slog::join_probe<4,1>(lamindex328, std::array<u64,4>{v_c52, 0, 0, 0}, [&](const std::array<u64,4>& m352) {
          u64 v_c17 = m352[1]; u64 v_c1 = m352[2]; u64 v_c53 = m352[3];
          if (!slog::exists_probe<3,1>(ckindex329, std::array<u64,3>{v_c53, 0, 0})) return;
          slog::join_probe_old<4,3>(extindex330, extdelta333, std::array<u64,4>{v_c5, v_c17, v_c1, 0}, [&](const std::array<u64,4>& m353) {
            u64 v_c54 = m353[3];
            slog::join_probe_old<3,2>(ckindex331, ckdelta334, std::array<u64,3>{v_c54, v_c53, 0}, [&](const std::array<u64,3>& m354) {
              u64 v_c55 = m354[2];
              slog::join_probe<2,1>(ck_ansindex332, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m355) {
                u64 v_c26 = m355[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c51, v_c26, v_c1});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c1, v_c26}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:16", "delta:ck", _fires);
  
      if (!_done)
      {
        ReadTask335* _cont = new ReadTask335(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask335(db,b), false);
  // (crule (pre) (scan ext __t1FJ54 env x t1) (body (exists ck (1 2 0) 1 env) (exists ck (1 2 0) 1 __t1FJ54) (join lam (1 2 3 0) 2 x t1 e __t8P1X2) (exists ck (1 2 0) 2 __t1FJ54 e) (join ck (1 2 0) 2 env __t8P1X2 __t99AN3) (join-old ck (1 2 0) 2 (1 2 0) __t1FJ54 e __t57LD5) (join ck_ans (0 1) 1 __t57LD5 __v0)) (head (emit-temp temp9j5e118 __t99AN3 __v0 t1) (mkstruct arrow (1 2 0) __t82gT1 t1 __v0)) dem_stlc.slog:16 #f)
  class ReadTask364 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex356;  slog::Index** ckindex357;  slog::Index** lamindex358;  slog::Index** ckindex359;  slog::Index** ckindex360;  slog::Index** ckindex361;  slog::Index** ck_ansindex362;  slog::Index** ckdelta363;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9j5e118");
      head_rel[1] = db->getRelation("arrow");
      outer_rel = db->getRelation("ext");
      std::vector<u16> ord365({1, 2, 0});
      slog::Relation* readrel366 = db->getRelation("ck");
      ckindex356 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({1, 2, 0});
      slog::Relation* readrel368 = db->getRelation("ck");
      ckindex357 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({1, 2, 3, 0});
      slog::Relation* readrel370 = db->getRelation("lam");
      lamindex358 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({1, 2, 0});
      slog::Relation* readrel372 = db->getRelation("ck");
      ckindex359 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({1, 2, 0});
      slog::Relation* readrel374 = db->getRelation("ck");
      ckindex360 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({1, 2, 0});
      slog::Relation* readrel376 = db->getRelation("ck");
      ckindex361 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({1, 2, 0});
      slog::Relation* readrel378 = db->getRelation("ck");
      ckdelta363 = readrel378->getIndex(ord377, true);
      std::vector<u16> ord379({0, 1});
      slog::Relation* readrel380 = db->getRelation("ck_ans");
      ck_ansindex362 = readrel380->getIndex(ord379, false);
  
    }
    ReadTask364(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c1 = _t[3];
        if (!slog::exists_probe<3,1>(ckindex356, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ckindex357, std::array<u64,3>{v_c54, 0, 0})) return;
        slog::join_probe<4,2>(lamindex358, std::array<u64,4>{v_c17, v_c1, 0, 0}, [&](const std::array<u64,4>& m381) {
          u64 v_c53 = m381[2]; u64 v_c52 = m381[3];
          if (!slog::exists_probe<3,2>(ckindex359, std::array<u64,3>{v_c54, v_c53, 0})) return;
          slog::join_probe<3,2>(ckindex360, std::array<u64,3>{v_c5, v_c52, 0}, [&](const std::array<u64,3>& m382) {
            u64 v_c51 = m382[2];
            slog::join_probe_old<3,2>(ckindex361, ckdelta363, std::array<u64,3>{v_c54, v_c53, 0}, [&](const std::array<u64,3>& m383) {
              u64 v_c55 = m383[2];
              slog::join_probe<2,1>(ck_ansindex362, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m384) {
                u64 v_c26 = m384[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c51, v_c26, v_c1});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c1, v_c26}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:16", "delta:ext", _fires);
  
      if (!_done)
      {
        ReadTask364* _cont = new ReadTask364(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask364(db,b), false);
  // (crule (pre (let __trid9kXb71 const6b51d0145b30dda2c4043c68) (let __trel8N6O72 const38c0e144c051f35df0684885) (let __tcol0PN573 const5feceb66ffc86f38d952786c) (let __trel9GAv74 const38c0e144c051f35df0684885) (let __tcol3Gev75 const6b86b273ff34fce19d6b804e)) (scan $sup76879x10x0x0x0 __d0 env x y) (body) (head (tycheck env (accept (struct ext) (struct _enum)) __trid9kXb71 __trel8N6O72 __tcol0PN573 (1 2 3 4 0)) (tycheck x (accept str) __trid9kXb71 __trel9GAv74 __tcol3Gev75 (1 2 3 4 0)) (mkstruct lookup (1 2 0) __9VEu70 env x)) dem_stlc.slog:11 #f)
  class ReadTask387 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid386;  u32 sid385;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("lookup");
      outer_rel = db->getRelation("$sup76879x10x0x0x0");
      sid386 = db->getRelation("_enum")->getStructId();
      sid385 = db->getRelation("ext")->getStructId();
  
    }
    ReadTask387(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_const6b51d0145b30dda2c4043c68;
      u64 v_c57 = v_const38c0e144c051f35df0684885;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_const38c0e144c051f35df0684885;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c61 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c18 = _t[3];
        ++_fires;
        if (!((is_struct(v_c5) && (decode_struct_id(v_c5) == sid385 || decode_struct_id(v_c5) == sid386))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c56, v_c57, v_c58, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_str(v_c17)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c56, v_c59, v_c60, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c5, v_c17}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:11", "delta:$sup76879x10x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask387* _cont = new ReadTask387(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask387(db,b), false);
  // (crule (pre) (scan ck __t17cq8 env e1) (body (exists app (1 2 0) 1 e1) (exists ck (1 2 0) 1 env) (exists ck_ans (0 1) 1 __t17cq8) (join $sup76879x16x0x0x0 (1 3 0 2) 2 e1 env __t6Npw7 e2) (exists ck (0 1 2) 2 __t6Npw7 env) (exists ck (1 2 0) 2 env e2) (join app (1 2 0) 2 e1 e2 __t3xua6) (join ck (0 1 2) 3 __t6Npw7 env __t3xua6) (join-old ck (1 2 0) 2 (1 2 0) env e2 __t37kq10) (exists ck_ans (0 1) 1 __t37kq10) (join ck_ans (0 1) 1 __t17cq8 __t9HVg9) (join ck_ans (0 1) 1 __t37kq10 t1) (join-old arrow (0 1 2) 2 (0 1 2) __t9HVg9 t1 t2)) (head (emit ck_ans (0 1) __t6Npw7 t2)) dem_stlc.slog:17 #f)
  class ReadTask403 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex388;  slog::Index** ckindex389;  slog::Index** ck_ansindex390;  slog::Index** $sup76879x16x0x0x0index391;  slog::Index** ckindex392;  slog::Index** ckindex393;  slog::Index** appindex394;  slog::Index** ckindex395;  slog::Index** ckindex396;  slog::Index** ck_ansindex397;  slog::Index** ck_ansindex398;  slog::Index** ck_ansindex399;  slog::Index** arrowindex400;  slog::Index** ckdelta401;  slog::Index** arrowdelta402;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("ck_ans");
      head_index[0] = readrel405->getIndex(ord404, false);
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord406({1, 2, 0});
      slog::Relation* readrel407 = db->getRelation("app");
      appindex388 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 2, 0});
      slog::Relation* readrel409 = db->getRelation("ck");
      ckindex389 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 1});
      slog::Relation* readrel411 = db->getRelation("ck_ans");
      ck_ansindex390 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 3, 0, 2});
      slog::Relation* readrel413 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0index391 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({0, 1, 2});
      slog::Relation* readrel415 = db->getRelation("ck");
      ckindex392 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 2, 0});
      slog::Relation* readrel417 = db->getRelation("ck");
      ckindex393 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 2, 0});
      slog::Relation* readrel419 = db->getRelation("app");
      appindex394 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({0, 1, 2});
      slog::Relation* readrel421 = db->getRelation("ck");
      ckindex395 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 2, 0});
      slog::Relation* readrel423 = db->getRelation("ck");
      ckindex396 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 2, 0});
      slog::Relation* readrel425 = db->getRelation("ck");
      ckdelta401 = readrel425->getIndex(ord424, true);
      std::vector<u16> ord426({0, 1});
      slog::Relation* readrel427 = db->getRelation("ck_ans");
      ck_ansindex397 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({0, 1});
      slog::Relation* readrel429 = db->getRelation("ck_ans");
      ck_ansindex398 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({0, 1});
      slog::Relation* readrel431 = db->getRelation("ck_ans");
      ck_ansindex399 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({0, 1, 2});
      slog::Relation* readrel433 = db->getRelation("arrow");
      arrowindex400 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({0, 1, 2});
      slog::Relation* readrel435 = db->getRelation("arrow");
      arrowdelta402 = readrel435->getIndex(ord434, true);
  
    }
    ReadTask403(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        if (!slog::exists_probe<3,1>(appindex388, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ckindex389, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<2,1>(ck_ansindex390, std::array<u64,2>{v_c4, 0})) return;
        slog::join_probe<4,2>($sup76879x16x0x0x0index391, std::array<u64,4>{v_c6, v_c5, 0, 0}, [&](const std::array<u64,4>& m436) {
          u64 v_c8 = m436[2]; u64 v_c7 = m436[3];
          if (!slog::exists_probe<3,2>(ckindex392, std::array<u64,3>{v_c8, v_c5, 0})) return;
          if (!slog::exists_probe<3,2>(ckindex393, std::array<u64,3>{v_c5, v_c7, 0})) return;
          slog::join_probe<3,2>(appindex394, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m437) {
            u64 v_c9 = m437[2];
            slog::join_probe<3,3>(ckindex395, std::array<u64,3>{v_c8, v_c5, v_c9}, [&](const std::array<u64,3>& m438) {
              slog::join_probe_old<3,2>(ckindex396, ckdelta401, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m439) {
                u64 v_c0 = m439[2];
                if (!slog::exists_probe<2,1>(ck_ansindex397, std::array<u64,2>{v_c0, 0})) return;
                slog::join_probe<2,1>(ck_ansindex398, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m440) {
                  u64 v_c3 = m440[1];
                  slog::join_probe<2,1>(ck_ansindex399, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m441) {
                    u64 v_c1 = m441[1];
                    slog::join_probe_old<3,2>(arrowindex400, arrowdelta402, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m442) {
                      u64 v_c2 = m442[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c8, v_c2}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:ck", _fires);
  
      if (!_done)
      {
        ReadTask403* _cont = new ReadTask403(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask403(db,b), false);
  // (crule (pre (let __tconst0hXo78 constb40d060f542e4963e0fc1392)) (scan num __t6P2x54 i) (body (exists ck (2 0 1) 1 __t6P2x54) (join _enum (1 0) 1 __tconst0hXo78 __t2VZ853) (join-old ck (2 0 1) 1 (2 0 1) __t6P2x54 __t0Y0I55 env)) (head (emit ck_ans (0 1) __t0Y0I55 __t2VZ853)) dem_stlc.slog:14 #f)
  class ReadTask447 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex443;  slog::Index** _enumindex444;  slog::Index** ckindex445;  slog::Index** ckdelta446;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord448({0, 1});
      slog::Relation* readrel449 = db->getRelation("ck_ans");
      head_index[0] = readrel449->getIndex(ord448, false);
      outer_rel = db->getRelation("num");
      std::vector<u16> ord450({2, 0, 1});
      slog::Relation* readrel451 = db->getRelation("ck");
      ckindex443 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 0});
      slog::Relation* readrel453 = db->getRelation("_enum");
      _enumindex444 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({2, 0, 1});
      slog::Relation* readrel455 = db->getRelation("ck");
      ckindex445 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({2, 0, 1});
      slog::Relation* readrel457 = db->getRelation("ck");
      ckdelta446 = readrel457->getIndex(ord456, true);
  
    }
    ReadTask447(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_constb40d060f542e4963e0fc1392;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c12 = _t[0];
        u64 v_c14 = _t[1];
        if (!slog::exists_probe<3,1>(ckindex443, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex444, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m458) {
          u64 v_c13 = m458[1];
          slog::join_probe_old<3,1>(ckindex445, ckdelta446, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m459) {
            u64 v_c11 = m459[1]; u64 v_c5 = m459[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c11, v_c13}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:14", "delta:num", _fires);
  
      if (!_done)
      {
        ReadTask447* _cont = new ReadTask447(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask447(db,b), false);
  // (crule (pre) (scan lookup __t8ds158 env x) (body (exists lookup (2 0 1) 1 x) (exists ext (1 2 3 0) 1 env) (exists lookup_ans (0 1) 1 __t8ds158) (join $sup76879x10x0x0x0 (1 2 0 3) 2 env x __t4rN257 y) (neq x y) (exists ext (1 2 3 0) 2 env y) (join lookup (0 2 1) 2 __t4rN257 x __t538W56) (join ext (0 2 1 3) 3 __t538W56 y env ____2zPL59) (join lookup_ans (0 1) 1 __t8ds158 t)) (head (emit lookup_ans (0 1) __t4rN257 t)) dem_stlc.slog:11 #f)
  class ReadTask468 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex460;  slog::Index** extindex461;  slog::Index** lookup_ansindex462;  slog::Index** $sup76879x10x0x0x0index463;  slog::Index** extindex464;  slog::Index** lookupindex465;  slog::Index** extindex466;  slog::Index** lookup_ansindex467;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord469({0, 1});
      slog::Relation* readrel470 = db->getRelation("lookup_ans");
      head_index[0] = readrel470->getIndex(ord469, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord471({2, 0, 1});
      slog::Relation* readrel472 = db->getRelation("lookup");
      lookupindex460 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 2, 3, 0});
      slog::Relation* readrel474 = db->getRelation("ext");
      extindex461 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({0, 1});
      slog::Relation* readrel476 = db->getRelation("lookup_ans");
      lookup_ansindex462 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 2, 0, 3});
      slog::Relation* readrel478 = db->getRelation("$sup76879x10x0x0x0");
      $sup76879x10x0x0x0index463 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({1, 2, 3, 0});
      slog::Relation* readrel480 = db->getRelation("ext");
      extindex464 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({0, 2, 1});
      slog::Relation* readrel482 = db->getRelation("lookup");
      lookupindex465 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({0, 2, 1, 3});
      slog::Relation* readrel484 = db->getRelation("ext");
      extindex466 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({0, 1});
      slog::Relation* readrel486 = db->getRelation("lookup_ans");
      lookup_ansindex467 = readrel486->getIndex(ord485, false);
  
    }
    ReadTask468(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<3,1>(lookupindex460, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<4,1>(extindex461, std::array<u64,4>{v_c5, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(lookup_ansindex462, std::array<u64,2>{v_c30, 0})) return;
        slog::join_probe<4,2>($sup76879x10x0x0x0index463, std::array<u64,4>{v_c5, v_c17, 0, 0}, [&](const std::array<u64,4>& m487) {
          u64 v_c29 = m487[2]; u64 v_c18 = m487[3];
          if (v_c17 == v_c18) return;
          if (!slog::exists_probe<4,2>(extindex464, std::array<u64,4>{v_c5, v_c18, 0, 0})) return;
          slog::join_probe<3,2>(lookupindex465, std::array<u64,3>{v_c29, v_c17, 0}, [&](const std::array<u64,3>& m488) {
            u64 v_c27 = m488[2];
            slog::join_probe<4,3>(extindex466, std::array<u64,4>{v_c27, v_c18, v_c5, 0}, [&](const std::array<u64,4>& m489) {
              u64 v_c28 = m489[3];
              slog::join_probe<2,1>(lookup_ansindex467, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m490) {
                u64 v_c22 = m490[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c22}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:11", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask468* _cont = new ReadTask468(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask468(db,b), false);
  // (crule (pre) (scan ck __t37kq10 env e2) (body (exists app (2 0 1) 1 e2) (exists ck (1 2 0) 1 env) (exists ck_ans (0 1) 1 __t37kq10) (join $sup76879x16x0x0x0 (2 3 0 1) 2 e2 env __t6Npw7 e1) (exists ck (0 1 2) 2 __t6Npw7 env) (exists ck (1 2 0) 2 env e1) (join app (1 2 0) 2 e1 e2 __t3xua6) (join ck (0 1 2) 3 __t6Npw7 env __t3xua6) (join ck (1 2 0) 2 env e1 __t17cq8) (join ck_ans (0 1) 1 __t17cq8 __t9HVg9) (join ck_ans (0 1) 1 __t37kq10 t1) (join arrow (0 1 2) 2 __t9HVg9 t1 t2)) (head (emit ck_ans (0 1) __t6Npw7 t2)) dem_stlc.slog:17 #f)
  class ReadTask503 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex491;  slog::Index** ckindex492;  slog::Index** ck_ansindex493;  slog::Index** $sup76879x16x0x0x0index494;  slog::Index** ckindex495;  slog::Index** ckindex496;  slog::Index** appindex497;  slog::Index** ckindex498;  slog::Index** ckindex499;  slog::Index** ck_ansindex500;  slog::Index** ck_ansindex501;  slog::Index** arrowindex502;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord504({0, 1});
      slog::Relation* readrel505 = db->getRelation("ck_ans");
      head_index[0] = readrel505->getIndex(ord504, false);
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord506({2, 0, 1});
      slog::Relation* readrel507 = db->getRelation("app");
      appindex491 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("ck");
      ckindex492 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({0, 1});
      slog::Relation* readrel511 = db->getRelation("ck_ans");
      ck_ansindex493 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({2, 3, 0, 1});
      slog::Relation* readrel513 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0index494 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({0, 1, 2});
      slog::Relation* readrel515 = db->getRelation("ck");
      ckindex495 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 2, 0});
      slog::Relation* readrel517 = db->getRelation("ck");
      ckindex496 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 2, 0});
      slog::Relation* readrel519 = db->getRelation("app");
      appindex497 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({0, 1, 2});
      slog::Relation* readrel521 = db->getRelation("ck");
      ckindex498 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({1, 2, 0});
      slog::Relation* readrel523 = db->getRelation("ck");
      ckindex499 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({0, 1});
      slog::Relation* readrel525 = db->getRelation("ck_ans");
      ck_ansindex500 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({0, 1});
      slog::Relation* readrel527 = db->getRelation("ck_ans");
      ck_ansindex501 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({0, 1, 2});
      slog::Relation* readrel529 = db->getRelation("arrow");
      arrowindex502 = readrel529->getIndex(ord528, false);
  
    }
    ReadTask503(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<3,1>(appindex491, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ckindex492, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<2,1>(ck_ansindex493, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<4,2>($sup76879x16x0x0x0index494, std::array<u64,4>{v_c7, v_c5, 0, 0}, [&](const std::array<u64,4>& m530) {
          u64 v_c8 = m530[2]; u64 v_c6 = m530[3];
          if (!slog::exists_probe<3,2>(ckindex495, std::array<u64,3>{v_c8, v_c5, 0})) return;
          if (!slog::exists_probe<3,2>(ckindex496, std::array<u64,3>{v_c5, v_c6, 0})) return;
          slog::join_probe<3,2>(appindex497, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m531) {
            u64 v_c9 = m531[2];
            slog::join_probe<3,3>(ckindex498, std::array<u64,3>{v_c8, v_c5, v_c9}, [&](const std::array<u64,3>& m532) {
              slog::join_probe<3,2>(ckindex499, std::array<u64,3>{v_c5, v_c6, 0}, [&](const std::array<u64,3>& m533) {
                u64 v_c4 = m533[2];
                slog::join_probe<2,1>(ck_ansindex500, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m534) {
                  u64 v_c3 = m534[1];
                  slog::join_probe<2,1>(ck_ansindex501, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m535) {
                    u64 v_c1 = m535[1];
                    slog::join_probe<3,2>(arrowindex502, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m536) {
                      u64 v_c2 = m536[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c8, v_c2}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:ck", _fires);
  
      if (!_done)
      {
        ReadTask503* _cont = new ReadTask503(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask503(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre3wLN104 __errf8Y5A105 __errf1qa9106 __errf6KId107 __errf3O8i108) (body) (head (emit error (0) __erre3wLN104)) <internal>:1 #f)
  class ReadTask537 : public slog::Task
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
      std::vector<u16> ord538({0});
      slog::Relation* readrel539 = db->getRelation("error");
      head_index[0] = readrel539->getIndex(ord538, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask537(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c62 = _t[0];
        u64 v_c63 = _t[1];
        u64 v_c64 = _t[2];
        u64 v_c65 = _t[3];
        u64 v_c66 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c62}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask537* _cont = new ReadTask537(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask537(db,b), false);
  // (crule (pre) (scan app __t7Y9q66 e1 e2) (body (join-old ck (2 0 1) 1 (2 0 1) __t7Y9q66 __t0iEo67 env)) (head (emit $sup76879x16x0x0x0 (0 3 1 2) __t0iEo67 env e1 e2)) dem_stlc.slog:17 #f)
  class ReadTask542 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex540;  slog::Index** ckdelta541;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup76879x16x0x0x0");
      std::vector<u16> ord543({0, 3, 1, 2});
      slog::Relation* readrel544 = db->getRelation("$sup76879x16x0x0x0");
      head_index[0] = readrel544->getIndex(ord543, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord545({2, 0, 1});
      slog::Relation* readrel546 = db->getRelation("ck");
      ckindex540 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({2, 0, 1});
      slog::Relation* readrel548 = db->getRelation("ck");
      ckdelta541 = readrel548->getIndex(ord547, true);
  
    }
    ReadTask542(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c67 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe_old<3,1>(ckindex540, ckdelta541, std::array<u64,3>{v_c67, 0, 0}, [&](const std::array<u64,3>& m549) {
          u64 v_c68 = m549[1]; u64 v_c5 = m549[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c68, v_c5, v_c6, v_c7}, std::array<u16,4>{0, 3, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask542* _cont = new ReadTask542(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask542(db,b), false);
  // (crule (pre) (scan ck __t6Npw7 env __t3xua6) (body (exists ck (1 2 0) 1 env) (join $sup76879x16x0x0x0 (0 3 1 2) 2 __t6Npw7 env e1 e2) (join app (0 2 1) 3 __t3xua6 e2 e1) (exists ck (1 2 0) 2 env e2) (join-old ck (1 2 0) 2 (1 2 0) env e1 __t17cq8) (exists ck_ans (0 1) 1 __t17cq8) (join-old ck (1 2 0) 2 (1 2 0) env e2 __t37kq10) (exists ck_ans (0 1) 1 __t37kq10) (join ck_ans (0 1) 1 __t17cq8 __t9HVg9) (join ck_ans (0 1) 1 __t37kq10 t1) (join-old arrow (0 1 2) 2 (0 1 2) __t9HVg9 t1 t2)) (head (emit ck_ans (0 1) __t6Npw7 t2)) dem_stlc.slog:17 #f)
  class ReadTask564 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex550;  slog::Index** $sup76879x16x0x0x0index551;  slog::Index** appindex552;  slog::Index** ckindex553;  slog::Index** ckindex554;  slog::Index** ck_ansindex555;  slog::Index** ckindex556;  slog::Index** ck_ansindex557;  slog::Index** ck_ansindex558;  slog::Index** ck_ansindex559;  slog::Index** arrowindex560;  slog::Index** ckdelta561;  slog::Index** ckdelta562;  slog::Index** arrowdelta563;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ck_ans");
      std::vector<u16> ord565({0, 1});
      slog::Relation* readrel566 = db->getRelation("ck_ans");
      head_index[0] = readrel566->getIndex(ord565, false);
      outer_rel = db->getRelation("ck");
      std::vector<u16> ord567({1, 2, 0});
      slog::Relation* readrel568 = db->getRelation("ck");
      ckindex550 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({0, 3, 1, 2});
      slog::Relation* readrel570 = db->getRelation("$sup76879x16x0x0x0");
      $sup76879x16x0x0x0index551 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({0, 2, 1});
      slog::Relation* readrel572 = db->getRelation("app");
      appindex552 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("ck");
      ckindex553 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 0});
      slog::Relation* readrel576 = db->getRelation("ck");
      ckindex554 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 2, 0});
      slog::Relation* readrel578 = db->getRelation("ck");
      ckdelta561 = readrel578->getIndex(ord577, true);
      std::vector<u16> ord579({0, 1});
      slog::Relation* readrel580 = db->getRelation("ck_ans");
      ck_ansindex555 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 2, 0});
      slog::Relation* readrel582 = db->getRelation("ck");
      ckindex556 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 2, 0});
      slog::Relation* readrel584 = db->getRelation("ck");
      ckdelta562 = readrel584->getIndex(ord583, true);
      std::vector<u16> ord585({0, 1});
      slog::Relation* readrel586 = db->getRelation("ck_ans");
      ck_ansindex557 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("ck_ans");
      ck_ansindex558 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({0, 1});
      slog::Relation* readrel590 = db->getRelation("ck_ans");
      ck_ansindex559 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({0, 1, 2});
      slog::Relation* readrel592 = db->getRelation("arrow");
      arrowindex560 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({0, 1, 2});
      slog::Relation* readrel594 = db->getRelation("arrow");
      arrowdelta563 = readrel594->getIndex(ord593, true);
  
    }
    ReadTask564(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c9 = _t[2];
        if (!slog::exists_probe<3,1>(ckindex550, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<4,2>($sup76879x16x0x0x0index551, std::array<u64,4>{v_c8, v_c5, 0, 0}, [&](const std::array<u64,4>& m595) {
          u64 v_c6 = m595[2]; u64 v_c7 = m595[3];
          slog::join_probe<3,3>(appindex552, std::array<u64,3>{v_c9, v_c7, v_c6}, [&](const std::array<u64,3>& m596) {
            if (!slog::exists_probe<3,2>(ckindex553, std::array<u64,3>{v_c5, v_c7, 0})) return;
            slog::join_probe_old<3,2>(ckindex554, ckdelta561, std::array<u64,3>{v_c5, v_c6, 0}, [&](const std::array<u64,3>& m597) {
              u64 v_c4 = m597[2];
              if (!slog::exists_probe<2,1>(ck_ansindex555, std::array<u64,2>{v_c4, 0})) return;
              slog::join_probe_old<3,2>(ckindex556, ckdelta562, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m598) {
                u64 v_c0 = m598[2];
                if (!slog::exists_probe<2,1>(ck_ansindex557, std::array<u64,2>{v_c0, 0})) return;
                slog::join_probe<2,1>(ck_ansindex558, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m599) {
                  u64 v_c3 = m599[1];
                  slog::join_probe<2,1>(ck_ansindex559, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m600) {
                    u64 v_c1 = m600[1];
                    slog::join_probe_old<3,2>(arrowindex560, arrowdelta563, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m601) {
                      u64 v_c2 = m601[2];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c8, v_c2}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:17", "delta:ck", _fires);
  
      if (!_done)
      {
        ReadTask564* _cont = new ReadTask564(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask564(db,b), false);
  // (crule (pre) (scan ck_ans __t57LD5 __v0) (body (join-old ck (0 1 2) 1 (0 1 2) __t57LD5 __t1FJ54 e) (join-old lam (3 1 0 2) 1 (3 1 0 2) e x __t8P1X2 t1) (exists ck (2 0 1) 1 __t8P1X2) (join-old ext (2 3 0 1) 3 (2 3 0 1) x t1 __t1FJ54 env) (join-old ck (1 2 0) 2 (1 2 0) env __t8P1X2 __t99AN3)) (head (emit-temp temp9j5e118 __t99AN3 __v0 t1) (mkstruct arrow (1 2 0) __t82gT1 t1 __v0)) dem_stlc.slog:16 #f)
  class ReadTask611 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex602;  slog::Index** lamindex603;  slog::Index** ckindex604;  slog::Index** extindex605;  slog::Index** ckindex606;  slog::Index** ckdelta607;  slog::Index** lamdelta608;  slog::Index** extdelta609;  slog::Index** ckdelta610;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9j5e118");
      head_rel[1] = db->getRelation("arrow");
      outer_rel = db->getRelation("ck_ans");
      std::vector<u16> ord612({0, 1, 2});
      slog::Relation* readrel613 = db->getRelation("ck");
      ckindex602 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({0, 1, 2});
      slog::Relation* readrel615 = db->getRelation("ck");
      ckdelta607 = readrel615->getIndex(ord614, true);
      std::vector<u16> ord616({3, 1, 0, 2});
      slog::Relation* readrel617 = db->getRelation("lam");
      lamindex603 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({3, 1, 0, 2});
      slog::Relation* readrel619 = db->getRelation("lam");
      lamdelta608 = readrel619->getIndex(ord618, true);
      std::vector<u16> ord620({2, 0, 1});
      slog::Relation* readrel621 = db->getRelation("ck");
      ckindex604 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({2, 3, 0, 1});
      slog::Relation* readrel623 = db->getRelation("ext");
      extindex605 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({2, 3, 0, 1});
      slog::Relation* readrel625 = db->getRelation("ext");
      extdelta609 = readrel625->getIndex(ord624, true);
      std::vector<u16> ord626({1, 2, 0});
      slog::Relation* readrel627 = db->getRelation("ck");
      ckindex606 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({1, 2, 0});
      slog::Relation* readrel629 = db->getRelation("ck");
      ckdelta610 = readrel629->getIndex(ord628, true);
  
    }
    ReadTask611(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[0];
        u64 v_c26 = _t[1];
        slog::join_probe_old<3,1>(ckindex602, ckdelta607, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m630) {
          u64 v_c54 = m630[1]; u64 v_c53 = m630[2];
          slog::join_probe_old<4,1>(lamindex603, lamdelta608, std::array<u64,4>{v_c53, 0, 0, 0}, [&](const std::array<u64,4>& m631) {
            u64 v_c17 = m631[1]; u64 v_c52 = m631[2]; u64 v_c1 = m631[3];
            if (!slog::exists_probe<3,1>(ckindex604, std::array<u64,3>{v_c52, 0, 0})) return;
            slog::join_probe_old<4,3>(extindex605, extdelta609, std::array<u64,4>{v_c17, v_c1, v_c54, 0}, [&](const std::array<u64,4>& m632) {
              u64 v_c5 = m632[3];
              slog::join_probe_old<3,2>(ckindex606, ckdelta610, std::array<u64,3>{v_c5, v_c52, 0}, [&](const std::array<u64,3>& m633) {
                u64 v_c51 = m633[2];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c51, v_c26, v_c1});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c1, v_c26}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:16", "delta:ck_ans", _fires);
  
      if (!_done)
      {
        ReadTask611* _cont = new ReadTask611(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask611(db,b), false);
  // (crule (pre (let __tconst8dNm51 constba2df4903a2c14e86dc3bcca) (let __tconst3JhQ48 const2bc983a5942276eb00a75e21) (let __tconst9nbj32 const30f8b180d63559f2512b744f) (let __tconst6P6s76 constb40d060f542e4963e0fc1392) (let __tconst8kEV24 const6b86b273ff34fce19d6b804e)) (seeded) (body (join _enum (1 0) 1 __tconst6P6s76 __t3zgy50) (exists var (1 0) 1 __tconst8dNm51) (exists num (1 0) 1 __tconst8kEV24) (exists var (1 0) 1 __tconst9nbj32) (exists lam (1 2 3 0) 1 __tconst9nbj32) (exists arrow (1 2 0) 1 __t3zgy50) (exists lam (1 2 3 0) 1 __tconst3JhQ48) (exists var (1 0) 1 __tconst3JhQ48) (join lam (1 2 3 0) 2 __tconst8dNm51 __t3zgy50 __t0OY020 __t16B123) (join var (0 1) 2 __t0OY020 __tconst8dNm51) (exists app (2 0 1) 1 __t0OY020) (join num (1 0) 1 __tconst8kEV24 __t95AJ25) (exists app (2 0 1) 1 __t95AJ25) (join var (1 0) 1 __tconst9nbj32 __t6EL627) (join app (1 2 0) 2 __t6EL627 __t95AJ25 __t7G7R28) (join lam (3 1 0 2) 2 __t7G7R28 __tconst9nbj32 __t9fNk33 __t4oeC31) (exists lam (1 2 3 0) 2 __tconst3JhQ48 __t4oeC31) (join arrow (0 1 2) 2 __t4oeC31 __t3zgy50 dup8FCI115) (eq __t3zgy50 dup8FCI115) (join lam (1 2 3 0) 2 __tconst3JhQ48 __t4oeC31 __t2MLp44 __t5JUn49) (join app (0 2 1) 2 __t2MLp44 __t0OY020 __t7Q1C43) (join var (0 1) 2 __t7Q1C43 __tconst3JhQ48)) (head (mkstruct lam (1 2 3 0) __t5Erl52 __tconst8dNm51 __t3zgy50 __t5JUn49) (mkstruct app (1 2 0) __t2P4j34 __t9fNk33 __t16B123)) dem_stlc.slog:23 #f)
  class ReadTask655 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** _enumindex634;  slog::Index** varindex635;  slog::Index** numindex636;  slog::Index** varindex637;  slog::Index** lamindex638;  slog::Index** arrowindex639;  slog::Index** lamindex640;  slog::Index** varindex641;  slog::Index** lamindex642;  slog::Index** varindex643;  slog::Index** appindex644;  slog::Index** numindex645;  slog::Index** appindex646;  slog::Index** varindex647;  slog::Index** appindex648;  slog::Index** lamindex649;  slog::Index** lamindex650;  slog::Index** arrowindex651;  slog::Index** lamindex652;  slog::Index** appindex653;  slog::Index** varindex654;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lam");
      std::vector<u16> ord656({1, 2, 3, 0});
      slog::Relation* readrel657 = db->getRelation("lam");
      head_index[0] = readrel657->getIndex(ord656, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord658({1, 2, 0});
      slog::Relation* readrel659 = db->getRelation("app");
      head_index[1] = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 0});
      slog::Relation* readrel661 = db->getRelation("_enum");
      _enumindex634 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 0});
      slog::Relation* readrel663 = db->getRelation("var");
      varindex635 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 0});
      slog::Relation* readrel665 = db->getRelation("num");
      numindex636 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 0});
      slog::Relation* readrel667 = db->getRelation("var");
      varindex637 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 2, 3, 0});
      slog::Relation* readrel669 = db->getRelation("lam");
      lamindex638 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({1, 2, 0});
      slog::Relation* readrel671 = db->getRelation("arrow");
      arrowindex639 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 2, 3, 0});
      slog::Relation* readrel673 = db->getRelation("lam");
      lamindex640 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 0});
      slog::Relation* readrel675 = db->getRelation("var");
      varindex641 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 2, 3, 0});
      slog::Relation* readrel677 = db->getRelation("lam");
      lamindex642 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({0, 1});
      slog::Relation* readrel679 = db->getRelation("var");
      varindex643 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({2, 0, 1});
      slog::Relation* readrel681 = db->getRelation("app");
      appindex644 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 0});
      slog::Relation* readrel683 = db->getRelation("num");
      numindex645 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({2, 0, 1});
      slog::Relation* readrel685 = db->getRelation("app");
      appindex646 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({1, 0});
      slog::Relation* readrel687 = db->getRelation("var");
      varindex647 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({1, 2, 0});
      slog::Relation* readrel689 = db->getRelation("app");
      appindex648 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({3, 1, 0, 2});
      slog::Relation* readrel691 = db->getRelation("lam");
      lamindex649 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 3, 0});
      slog::Relation* readrel693 = db->getRelation("lam");
      lamindex650 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({0, 1, 2});
      slog::Relation* readrel695 = db->getRelation("arrow");
      arrowindex651 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({1, 2, 3, 0});
      slog::Relation* readrel697 = db->getRelation("lam");
      lamindex652 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({0, 2, 1});
      slog::Relation* readrel699 = db->getRelation("app");
      appindex653 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({0, 1});
      slog::Relation* readrel701 = db->getRelation("var");
      varindex654 = readrel701->getIndex(ord700, false);
  
    }
    ReadTask655(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c32 = v_const2bc983a5942276eb00a75e21;
      u64 v_c33 = v_const30f8b180d63559f2512b744f;
      u64 v_c37 = v_constb40d060f542e4963e0fc1392;
      u64 v_c36 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex634, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m702) {
        u64 v_c39 = m702[1];
        if (!slog::exists_probe<2,1>(varindex635, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<2,1>(numindex636, std::array<u64,2>{v_c36, 0})) return;
        if (!slog::exists_probe<2,1>(varindex637, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<4,1>(lamindex638, std::array<u64,4>{v_c33, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(arrowindex639, std::array<u64,3>{v_c39, 0, 0})) return;
        if (!slog::exists_probe<4,1>(lamindex640, std::array<u64,4>{v_c32, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(varindex641, std::array<u64,2>{v_c32, 0})) return;
        slog::join_probe<4,2>(lamindex642, std::array<u64,4>{v_c31, v_c39, 0, 0}, [&](const std::array<u64,4>& m703) {
          u64 v_c40 = m703[2]; u64 v_c38 = m703[3];
          slog::join_probe<2,2>(varindex643, std::array<u64,2>{v_c40, v_c31}, [&](const std::array<u64,2>& m704) {
            if (!slog::exists_probe<3,1>(appindex644, std::array<u64,3>{v_c40, 0, 0})) return;
            slog::join_probe<2,1>(numindex645, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m705) {
              u64 v_c41 = m705[1];
              if (!slog::exists_probe<3,1>(appindex646, std::array<u64,3>{v_c41, 0, 0})) return;
              slog::join_probe<2,1>(varindex647, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m706) {
                u64 v_c42 = m706[1];
                slog::join_probe<3,2>(appindex648, std::array<u64,3>{v_c42, v_c41, 0}, [&](const std::array<u64,3>& m707) {
                  u64 v_c43 = m707[2];
                  slog::join_probe<4,2>(lamindex649, std::array<u64,4>{v_c43, v_c33, 0, 0}, [&](const std::array<u64,4>& m708) {
                    u64 v_c69 = m708[2]; u64 v_c50 = m708[3];
                    if (!slog::exists_probe<4,2>(lamindex650, std::array<u64,4>{v_c32, v_c50, 0, 0})) return;
                    slog::join_probe<3,2>(arrowindex651, std::array<u64,3>{v_c50, v_c39, 0}, [&](const std::array<u64,3>& m709) {
                      u64 v_c70 = m709[2];
                      if (v_c39 != v_c70) return;
                      slog::join_probe<4,2>(lamindex652, std::array<u64,4>{v_c32, v_c50, 0, 0}, [&](const std::array<u64,4>& m710) {
                        u64 v_c48 = m710[2]; u64 v_c71 = m710[3];
                        slog::join_probe<3,2>(appindex653, std::array<u64,3>{v_c48, v_c40, 0}, [&](const std::array<u64,3>& m711) {
                          u64 v_c47 = m711[2];
                          slog::join_probe<2,2>(varindex654, std::array<u64,2>{v_c47, v_c32}, [&](const std::array<u64,2>& m712) {
                            ++_fires;
                            slog::emit_struct_checked<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c31, v_c39, v_c71}, std::array<u16,4>{1, 2, 3, 0});
                            slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c69, v_c38}, std::array<u16,3>{1, 2, 0});
                          });
                        });
                      });
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:23", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask655(db,b));
  // (crule (pre (let __tconst6P6s76 constb40d060f542e4963e0fc1392) (let __tconst8dNm51 constba2df4903a2c14e86dc3bcca) (let __tconst3JhQ48 const2bc983a5942276eb00a75e21) (let __tconst1wvy37 const4e07408562bedb8b60ce05c1) (let __tconst1K9r35 const4b227777d4dd1fc61c6f884f) (let __tconst9nbj32 const30f8b180d63559f2512b744f) (let __tconst8kEV24 const6b86b273ff34fce19d6b804e)) (probe _enum (1 0) 1 __tconst6P6s76 __t3zgy50) (body) (head (mkstruct var (1 0) __t7Q1C43 __tconst3JhQ48) (mkstruct num (1 0) __t7sPi38 __tconst1wvy37) (mkstruct num (1 0) __t35Fj36 __tconst1K9r35) (mkstruct arrow (1 2 0) __t4oeC31 __t3zgy50 __t3zgy50) (mkstruct var (1 0) __t6EL627 __tconst9nbj32) (mkstruct num (1 0) __t95AJ25 __tconst8kEV24) (mkstruct var (1 0) __t0OY020 __tconst8dNm51)) dem_stlc.slog:23 #f)
  class ReadTask713 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("var");
      head_rel[1] = db->getRelation("num");
      head_rel[2] = db->getRelation("num");
      head_rel[3] = db->getRelation("arrow");
      head_rel[4] = db->getRelation("var");
      head_rel[5] = db->getRelation("num");
      head_rel[6] = db->getRelation("var");
      std::vector<u16> ord714({1, 0});
      slog::Relation* readrel715 = db->getRelation("_enum");
      driver_index = readrel715->getIndex(ord714, true);
  
    }
    ReadTask713(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c37 = v_constb40d060f542e4963e0fc1392;
      u64 v_c31 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c32 = v_const2bc983a5942276eb00a75e21;
      u64 v_c34 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c35 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c33 = v_const30f8b180d63559f2512b744f;
      u64 v_c36 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[7];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c37, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m716) {
        u64 v_c39 = m716[1];
        if (buckethash(v_c39) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c32}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c34}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c35}, std::array<u16,2>{1, 0});
        slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c39, v_c39}, std::array<u16,3>{1, 2, 0});
        slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c33}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c36}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c31}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:23", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask713* _cont = new ReadTask713(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask713(db,b), true);
  // (crule (pre) (scan var __t65ap68 x) (body (join-old ck (2 0 1) 1 (2 0 1) __t65ap68 __t8xpU69 env)) (head (mkstruct lookup (1 2 0) __2bB777 env x)) dem_stlc.slog:15 #f)
  class ReadTask719 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ckindex717;  slog::Index** ckdelta718;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup");
      outer_rel = db->getRelation("var");
      std::vector<u16> ord720({2, 0, 1});
      slog::Relation* readrel721 = db->getRelation("ck");
      ckindex717 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({2, 0, 1});
      slog::Relation* readrel723 = db->getRelation("ck");
      ckdelta718 = readrel723->getIndex(ord722, true);
  
    }
    ReadTask719(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        slog::join_probe_old<3,1>(ckindex717, ckdelta718, std::array<u64,3>{v_c72, 0, 0}, [&](const std::array<u64,3>& m724) {
          u64 v_c73 = m724[1]; u64 v_c5 = m724[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c17}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_stlc.slog:15", "delta:var", _fires);
  
      if (!_done)
      {
        ReadTask719* _cont = new ReadTask719(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask719(db,b), false);
}

