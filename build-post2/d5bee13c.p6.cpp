
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0453462f31b2bcf68e33a91f;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5d6ab4fefffae2e4c15033db;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6f4b6612125fb3a0daecd279;
extern u64 v_const72bac24066bb34077c1f6e71;
extern u64 v_const7f254967624b26d820569bd6;
extern u64 v_const844546be553b9dcbf71ae163;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constc99bf3037b4c2fce0fbaab85;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd59eced1ded07f84c145592f;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_conste7f6c011776e8db7cd330b54;
extern u64 v_conste90c92f3e6c3b47a7bc93e42;
extern u64 v_consteca796f75a14387c3a7674e7;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;
extern u64 v_constfc04a7193b8b865723e61851;
extern u64 v_constfee494ff4827aeb0635bb714;


void slog_rules_c0e8c31e363826667(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst9fQa703 const844546be553b9dcbf71ae163) (let __tconst09sA701 const0453462f31b2bcf68e33a91f)) (scan temp4ydz1814 __t1VB8711) (body (exists if (1 3 2 0) 1 __t1VB8711) (exists sym (1 0) 1 __tconst9fQa703) (join sym (1 0) 1 __tconst09sA701 __t1F7O702) (join if (1 3 2 0) 2 __t1VB8711 __t1F7O702 __t3RPz704 __t7BKw712) (join sym (0 1) 2 __t3RPz704 __tconst9fQa703)) (head (emit program (0) __t7BKw712)) kcfa.slog:52 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex0;  slog::Index** symindex1;  slog::Index** symindex2;  slog::Index** ifindex3;  slog::Index** symindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord6({0});
      slog::Relation* readrel7 = db->getRelation("program");
      head_index[0] = readrel7->getIndex(ord6, false);
      outer_rel = db->getRelation("temp4ydz1814");
      std::vector<u16> ord8({1, 3, 2, 0});
      slog::Relation* readrel9 = db->getRelation("if");
      ifindex0 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 0});
      slog::Relation* readrel11 = db->getRelation("sym");
      symindex1 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("sym");
      symindex2 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 3, 2, 0});
      slog::Relation* readrel15 = db->getRelation("if");
      ifindex3 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({0, 1});
      slog::Relation* readrel17 = db->getRelation("sym");
      symindex4 = readrel17->getIndex(ord16, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const844546be553b9dcbf71ae163;
      u64 v_c1 = v_const0453462f31b2bcf68e33a91f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c2 = _t[0];
        if (!slog::exists_probe<4,1>(ifindex0, std::array<u64,4>{v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(symindex1, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(symindex2, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m18) {
          u64 v_c3 = m18[1];
          slog::join_probe<4,2>(ifindex3, std::array<u64,4>{v_c2, v_c3, 0, 0}, [&](const std::array<u64,4>& m19) {
            u64 v_c4 = m19[2]; u64 v_c5 = m19[3];
            slog::join_probe<2,2>(symindex4, std::array<u64,2>{v_c4, v_c0}, [&](const std::array<u64,2>& m20) {
              ++_fires;
              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:52", "delta:temp4ydz1814", _fires);
  
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
  // (crule (pre (let __trid8TSk1361 constfee494ff4827aeb0635bb714) (let __trel2WUu1362 constdd7bbf31ce5f578b9805e840) (let __tcol0YSk1363 const5feceb66ffc86f38d952786c) (let __trel8bxh1364 constdd7bbf31ce5f578b9805e840) (let __tcol7kI81365 const6b86b273ff34fce19d6b804e)) (scan $sup5638x84x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid8TSk1361 __trel2WUu1362 __tcol0YSk1363 (1 2 3 4 0)) (tycheck m (accept int) __trid8TSk1361 __trel8bxh1364 __tcol7kI81365 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __4KC11360 k m)) map.slog:85 #f)
  class ReadTask21 : public slog::Task
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
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_msk");
      outer_rel = db->getRelation("$sup5638x84x0x0x0");
  
    }
    ReadTask21(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constfee494ff4827aeb0635bb714;
      u64 v_c7 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
      u64 v_c9 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c16 = _t[5];
        ++_fires;
        if (!(is_int(v_c12)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c6, v_c7, v_c8, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c14)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c6, v_c9, v_c10, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c12, v_c14}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:$sup5638x84x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask21* _cont = new ReadTask21(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask21(db,b), false);
  // (crule (pre (let __tconst9Vzm1192 constd01925b37634a1a9d24159d8)) (scan temp13Gs2071 __t3rFt824 e) (body (join _enum (1 0) 1 __tconst9Vzm1192 __t32BX825)) (head (mkstruct eval (1 2 3 0) __7tgc1191 e __t32BX825 __t3rFt824)) interp.slog:133 #f)
  class ReadTask23 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex22;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("temp13Gs2071");
      std::vector<u16> ord24({1, 0});
      slog::Relation* readrel25 = db->getRelation("_enum");
      _enumindex22 = readrel25->getIndex(ord24, false);
  
    }
    ReadTask23(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_constd01925b37634a1a9d24159d8;
  
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
        slog::join_probe<2,1>(_enumindex22, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m26) {
          u64 v_c20 = m26[1];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c19, v_c20, v_c18}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:133", "delta:temp13Gs2071", _fires);
  
      if (!_done)
      {
        ReadTask23* _cont = new ReadTask23(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask23(db,b), false);
  // (crule (pre (let __trid9n3x1549 const5d6ab4fefffae2e4c15033db) (let __trel5eWq1550 const4a59dbb9cb3129dfcc75170b) (let __tcol6eZ31551 constd4735e3a265e16eee03f5971)) (scan eval __9QsM1547 __t7vAU766 rho t) (body (join-old mp_put (1 3 0 2) 2 (1 3 0 2) rho t __t9Rkj767 x) (exists mp_put_ans (0 1) 1 __t9Rkj767) (join-old letrec (0 1 2 3) 2 (0 1 2 3) __t7vAU766 x er eb) (join-old mp_put_ans (0 1) 1 (0 1) __t9Rkj767 rho2)) (head (tycheck t (accept seq) __trid9n3x1549 __trel5eWq1550 __tcol6eZ31551 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __6xaV1548 er rho2 t)) interp.slog:98 #f)
  class ReadTask34 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex27;  slog::Index** mp_put_ansindex28;  slog::Index** letrecindex29;  slog::Index** mp_put_ansindex30;  slog::Index** mp_putdelta31;  slog::Index** letrecdelta32;  slog::Index** mp_put_ansdelta33;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord35({1, 3, 0, 2});
      slog::Relation* readrel36 = db->getRelation("mp_put");
      mp_putindex27 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 3, 0, 2});
      slog::Relation* readrel38 = db->getRelation("mp_put");
      mp_putdelta31 = readrel38->getIndex(ord37, true);
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("mp_put_ans");
      mp_put_ansindex28 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({0, 1, 2, 3});
      slog::Relation* readrel42 = db->getRelation("letrec");
      letrecindex29 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 1, 2, 3});
      slog::Relation* readrel44 = db->getRelation("letrec");
      letrecdelta32 = readrel44->getIndex(ord43, true);
      std::vector<u16> ord45({0, 1});
      slog::Relation* readrel46 = db->getRelation("mp_put_ans");
      mp_put_ansindex30 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("mp_put_ans");
      mp_put_ansdelta33 = readrel48->getIndex(ord47, true);
  
    }
    ReadTask34(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c21 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c22 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c23 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c24 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c27 = _t[3];
        slog::join_probe_old<4,2>(mp_putindex27, mp_putdelta31, std::array<u64,4>{v_c26, v_c27, 0, 0}, [&](const std::array<u64,4>& m49) {
          u64 v_c28 = m49[2]; u64 v_c29 = m49[3];
          if (!slog::exists_probe<2,1>(mp_put_ansindex28, std::array<u64,2>{v_c28, 0})) return;
          slog::join_probe_old<4,2>(letrecindex29, letrecdelta32, std::array<u64,4>{v_c25, v_c29, 0, 0}, [&](const std::array<u64,4>& m50) {
            u64 v_c30 = m50[2]; u64 v_c31 = m50[3];
            slog::join_probe_old<2,1>(mp_put_ansindex30, mp_put_ansdelta33, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m51) {
              u64 v_c32 = m51[1];
              ++_fires;
              if (!(is_seq(v_c27)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c21, v_c22, v_c23, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c30, v_c32, v_c27}, std::array<u16,4>{1, 2, 3, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:eval", _fires);
  
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
  // (crule (pre) (scan temp6Noe1976 __t252g323) (body) (head (mkstruct mp_hsb (1 0) __0Xud1459 __t252g323)) map.slog:26 #f)
  class ReadTask52 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_hsb");
      outer_rel = db->getRelation("temp6Noe1976");
  
    }
    ReadTask52(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c33 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c33}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:temp6Noe1976", _fires);
  
      if (!_done)
      {
        ReadTask52* _cont = new ReadTask52(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask52(db,b), false);
  // (crule (pre (let __tconst84Si675 const6b86b273ff34fce19d6b804e)) (scan mbranch __t9W40673 p m l r) (body (join-old mp_get (1 2 0) 1 (1 2 0) __t9W40673 k __t4yhY674) (let __t0O9f676 (band k m)) (cmp lt __t0O9f676 __tconst84Si675)) (head (emit $sup5638x51x0x0x0 (0 1 2 3 4 5) __t4yhY674 k l m p r)) map.slog:52 #f)
  class ReadTask55 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex53;  slog::Index** mp_getdelta54;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x51x0x0x0");
      std::vector<u16> ord56({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel57 = db->getRelation("$sup5638x51x0x0x0");
      head_index[0] = readrel57->getIndex(ord56, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord58({1, 2, 0});
      slog::Relation* readrel59 = db->getRelation("mp_get");
      mp_getindex53 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 2, 0});
      slog::Relation* readrel61 = db->getRelation("mp_get");
      mp_getdelta54 = readrel61->getIndex(ord60, true);
  
    }
    ReadTask55(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c35 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c16 = _t[4];
        slog::join_probe_old<3,1>(mp_getindex53, mp_getdelta54, std::array<u64,3>{v_c35, 0, 0}, [&](const std::array<u64,3>& m62) {
          u64 v_c12 = m62[1]; u64 v_c36 = m62[2];
          u64 v_c37 = _prim_band(db, v_c12, v_c14);
          if (v_c37 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
          u64 v_c38 = _prim_lt(db, v_c37, v_c34);
          if (v_c38 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
          if (!v_c38) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c36, v_c12, v_c13, v_c14, v_c15, v_c16}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:52", "delta:mbranch", _fires);
  
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
  // (crule (pre) (scan eval_ans __t6VzV444 vr) (body (join-old eval (0 1 2 3) 1 (0 1 2 3) __t6VzV444 er rho t) (exists let (2 0 1 3) 1 er) (join eval (2 3 0 1) 2 rho t __4PdZ1446 __t3kGW443) (join-old let (0 2 1 3) 2 (0 2 1 3) __t3kGW443 er x eb)) (head (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:94 #f)
  class ReadTask70 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex64;  slog::Index** letindex65;  slog::Index** evalindex66;  slog::Index** letindex67;  slog::Index** evaldelta68;  slog::Index** letdelta69;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord71({0, 1, 2});
      slog::Relation* readrel72 = db->getRelation("store");
      head_index[0] = readrel72->getIndex(ord71, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord73({0, 1, 2});
      slog::Relation* readrel74 = db->getRelation("binding_event");
      head_index[1] = readrel74->getIndex(ord73, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord75({0, 1, 2, 3});
      slog::Relation* readrel76 = db->getRelation("eval");
      evalindex64 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({0, 1, 2, 3});
      slog::Relation* readrel78 = db->getRelation("eval");
      evaldelta68 = readrel78->getIndex(ord77, true);
      std::vector<u16> ord79({2, 0, 1, 3});
      slog::Relation* readrel80 = db->getRelation("let");
      letindex65 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({2, 3, 0, 1});
      slog::Relation* readrel82 = db->getRelation("eval");
      evalindex66 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({0, 2, 1, 3});
      slog::Relation* readrel84 = db->getRelation("let");
      letindex67 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 2, 1, 3});
      slog::Relation* readrel86 = db->getRelation("let");
      letdelta69 = readrel86->getIndex(ord85, true);
  
    }
    ReadTask70(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[0];
        u64 v_c40 = _t[1];
        slog::join_probe_old<4,1>(evalindex64, evaldelta68, std::array<u64,4>{v_c39, 0, 0, 0}, [&](const std::array<u64,4>& m87) {
          u64 v_c30 = m87[1]; u64 v_c26 = m87[2]; u64 v_c27 = m87[3];
          if (!slog::exists_probe<4,1>(letindex65, std::array<u64,4>{v_c30, 0, 0, 0})) return;
          slog::join_probe<4,2>(evalindex66, std::array<u64,4>{v_c26, v_c27, 0, 0}, [&](const std::array<u64,4>& m88) {
            u64 v_c41 = m88[2]; u64 v_c42 = m88[3];
            slog::join_probe_old<4,2>(letindex67, letdelta69, std::array<u64,4>{v_c42, v_c30, 0, 0}, [&](const std::array<u64,4>& m89) {
              u64 v_c29 = m89[2]; u64 v_c31 = m89[3];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c29, v_c27, v_c40}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c29, v_c27, v_c27}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask70* _cont = new ReadTask70(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask70(db,b), false);
  // (crule (pre (let __tconst2JmK55 conste7f6c011776e8db7cd330b54) (let __tconst7dEi64 constef2d127de37b942baad06145) (let __tconst6c7T73 const4b227777d4dd1fc61c6f884f) (let __tconst56qw82 const4e07408562bedb8b60ce05c1) (let __tconst5MNq94 const5feceb66ffc86f38d952786c) (let __tconst0SLc45 const06abaa100ecef791ce028c56) (let __tconst2aC790 const6b86b273ff34fce19d6b804e)) (scan temp1cP31983 __t1Qwq78 __t1uVZ69 __t5wMp60 __t7j3b88 __t8XJL92 __t8ZUv44) (body (exists lambda (1 2 0) 1 __t7j3b88) (exists ref (1 0) 1 __tconst5MNq94) (exists app (2 0 1) 1 __t1Qwq78) (exists app (2 0 1) 1 __t1uVZ69) (exists ref (1 0) 1 __tconst56qw82) (exists app (2 0 1) 1 __t5wMp60) (exists ref (1 0) 1 __tconst6c7T73) (exists primref (1 0) 1 __tconst0SLc45) (join ref (1 0) 1 __tconst2aC790 __t6rYz85) (join lambda (1 2 0) 2 __t7j3b88 __t6rYz85 __t32mX89) (join ref (1 0) 1 __tconst5MNq94 __t0g1Q71) (exists app (1 2 0) 2 __t0g1Q71 __t1uVZ69) (join app (1 2 0) 2 __t0g1Q71 __t1Qwq78 __t9rwO81) (join app (1 2 0) 2 __t0g1Q71 __t1uVZ69 __t8z2o72) (join ref (1 0) 1 __tconst56qw82 __t7Sy862) (join app (1 2 0) 2 __t7Sy862 __t5wMp60 __t66zQ63) (join ref (1 0) 1 __tconst6c7T73 __t5Ugf53) (join app (1 2 0) 2 __t5Ugf53 __t5wMp60 __t9CBr54) (join primref (1 0) 1 __tconst0SLc45 __t0d6446)) (head (emit-temp temp2vYa1984 __t32mX89 __t66zQ63 __t8XJL92 __t8ZUv44 __t8z2o72 __t9CBr54 __t9rwO81) (mkstruct app (1 2 0) __t3YaY47 __t0d6446 __t8ZUv44) (mkstruct lambda (1 2 0) __t39ek93 __t8XJL92 __t32mX89)) kcfa.slog:16 #f)
  class ReadTask109 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex90;  slog::Index** refindex91;  slog::Index** appindex92;  slog::Index** appindex93;  slog::Index** refindex94;  slog::Index** appindex95;  slog::Index** refindex96;  slog::Index** primrefindex97;  slog::Index** refindex98;  slog::Index** lambdaindex99;  slog::Index** refindex100;  slog::Index** appindex101;  slog::Index** appindex102;  slog::Index** appindex103;  slog::Index** refindex104;  slog::Index** appindex105;  slog::Index** refindex106;  slog::Index** appindex107;  slog::Index** primrefindex108;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2vYa1984");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp1cP31983");
      std::vector<u16> ord110({1, 2, 0});
      slog::Relation* readrel111 = db->getRelation("lambda");
      lambdaindex90 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 0});
      slog::Relation* readrel113 = db->getRelation("ref");
      refindex91 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({2, 0, 1});
      slog::Relation* readrel115 = db->getRelation("app");
      appindex92 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({2, 0, 1});
      slog::Relation* readrel117 = db->getRelation("app");
      appindex93 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 0});
      slog::Relation* readrel119 = db->getRelation("ref");
      refindex94 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({2, 0, 1});
      slog::Relation* readrel121 = db->getRelation("app");
      appindex95 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 0});
      slog::Relation* readrel123 = db->getRelation("ref");
      refindex96 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 0});
      slog::Relation* readrel125 = db->getRelation("primref");
      primrefindex97 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 0});
      slog::Relation* readrel127 = db->getRelation("ref");
      refindex98 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("lambda");
      lambdaindex99 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("ref");
      refindex100 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("app");
      appindex101 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 2, 0});
      slog::Relation* readrel135 = db->getRelation("app");
      appindex102 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("app");
      appindex103 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 0});
      slog::Relation* readrel139 = db->getRelation("ref");
      refindex104 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 0});
      slog::Relation* readrel141 = db->getRelation("app");
      appindex105 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 0});
      slog::Relation* readrel143 = db->getRelation("ref");
      refindex106 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 2, 0});
      slog::Relation* readrel145 = db->getRelation("app");
      appindex107 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({1, 0});
      slog::Relation* readrel147 = db->getRelation("primref");
      primrefindex108 = readrel147->getIndex(ord146, false);
  
    }
    ReadTask109(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c44 = v_constef2d127de37b942baad06145;
      u64 v_c45 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c46 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c47 = v_const5feceb66ffc86f38d952786c;
      u64 v_c48 = v_const06abaa100ecef791ce028c56;
      u64 v_c49 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c50 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c52 = _t[2];
        u64 v_c53 = _t[3];
        u64 v_c54 = _t[4];
        u64 v_c55 = _t[5];
        if (!slog::exists_probe<3,1>(lambdaindex90, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex91, std::array<u64,2>{v_c47, 0})) return;
        if (!slog::exists_probe<3,1>(appindex92, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex93, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex94, std::array<u64,2>{v_c46, 0})) return;
        if (!slog::exists_probe<3,1>(appindex95, std::array<u64,3>{v_c52, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex96, std::array<u64,2>{v_c45, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex97, std::array<u64,2>{v_c48, 0})) return;
        slog::join_probe<2,1>(refindex98, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m148) {
          u64 v_c56 = m148[1];
          slog::join_probe<3,2>(lambdaindex99, std::array<u64,3>{v_c53, v_c56, 0}, [&](const std::array<u64,3>& m149) {
            u64 v_c57 = m149[2];
            slog::join_probe<2,1>(refindex100, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m150) {
              u64 v_c58 = m150[1];
              if (!slog::exists_probe<3,2>(appindex101, std::array<u64,3>{v_c58, v_c51, 0})) return;
              slog::join_probe<3,2>(appindex102, std::array<u64,3>{v_c58, v_c50, 0}, [&](const std::array<u64,3>& m151) {
                u64 v_c59 = m151[2];
                slog::join_probe<3,2>(appindex103, std::array<u64,3>{v_c58, v_c51, 0}, [&](const std::array<u64,3>& m152) {
                  u64 v_c60 = m152[2];
                  slog::join_probe<2,1>(refindex104, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m153) {
                    u64 v_c61 = m153[1];
                    slog::join_probe<3,2>(appindex105, std::array<u64,3>{v_c61, v_c52, 0}, [&](const std::array<u64,3>& m154) {
                      u64 v_c62 = m154[2];
                      slog::join_probe<2,1>(refindex106, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m155) {
                        u64 v_c63 = m155[1];
                        slog::join_probe<3,2>(appindex107, std::array<u64,3>{v_c63, v_c52, 0}, [&](const std::array<u64,3>& m156) {
                          u64 v_c64 = m156[2];
                          slog::join_probe<2,1>(primrefindex108, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m157) {
                            u64 v_c65 = m157[1];
                            ++_fires;
                            slog::emit_temp<7>(head_rel[0], newbatch[0], std::array<u64,7>{v_c57, v_c62, v_c54, v_c55, v_c60, v_c64, v_c59});
                            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c65, v_c55}, std::array<u16,3>{1, 2, 0});
                            slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c54, v_c57}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("kcfa.slog:16", "delta:temp1cP31983", _fires);
  
      if (!_done)
      {
        ReadTask109* _cont = new ReadTask109(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask109(db,b), false);
  // (crule (pre (let __trid90UH1137 constc99bf3037b4c2fce0fbaab85) (let __trel4c0R1138 const7f254967624b26d820569bd6) (let __tcol8vdg1139 const5feceb66ffc86f38d952786c) (let __trel9BGs1140 const72bac24066bb34077c1f6e71) (let __tcol5rcl1141 const5feceb66ffc86f38d952786c) (let __trel6xCG1142 const72bac24066bb34077c1f6e71) (let __tcol8YEv1143 const6b86b273ff34fce19d6b804e) (let __trel3day1144 const72bac24066bb34077c1f6e71) (let __tcol96481145 constd4735e3a265e16eee03f5971) (let __trel1Jvt1146 const72bac24066bb34077c1f6e71) (let __tcol5ih31147 const4e07408562bedb8b60ce05c1)) (scan $sup5638x98x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid90UH1137 __trel4c0R1138 __tcol8vdg1139 (1 2 3 4 0)) (tycheck q (accept int) __trid90UH1137 __trel9BGs1140 __tcol5rcl1141 (1 2 3 4 0)) (tycheck n (accept int) __trid90UH1137 __trel6xCG1142 __tcol8YEv1143 (1 2 3 4 0)) (tycheck u (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid90UH1137 __trel3day1144 __tcol96481145 (1 2 3 4 0)) (tycheck v (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid90UH1137 __trel1Jvt1146 __tcol5ih31147 (1 2 3 4 0)) (emit-temp temp7LDM2048 n q r u v) (mkstruct mbranch (1 2 3 4 0) __t0LfW530 q n u v)) map.slog:99 #f)
  class ReadTask161 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid159;  u32 sid158;  u32 sid160;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp7LDM2048");
      head_rel[6] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x98x0x0x1");
      sid159 = db->getRelation("_enum")->getStructId();
      sid158 = db->getRelation("mbranch")->getStructId();
      sid160 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask161(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_constc99bf3037b4c2fce0fbaab85;
      u64 v_c67 = v_const7f254967624b26d820569bd6;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
      u64 v_c69 = v_const72bac24066bb34077c1f6e71;
      u64 v_c70 = v_const5feceb66ffc86f38d952786c;
      u64 v_c71 = v_const72bac24066bb34077c1f6e71;
      u64 v_c72 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c73 = v_const72bac24066bb34077c1f6e71;
      u64 v_c74 = v_constd4735e3a265e16eee03f5971;
      u64 v_c75 = v_const72bac24066bb34077c1f6e71;
      u64 v_c76 = v_const4e07408562bedb8b60ce05c1;
  
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
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c78 = _t[4];
        u64 v_c15 = _t[5];
        u64 v_c79 = _t[6];
        u64 v_c16 = _t[7];
        u64 v_c80 = _t[8];
        u64 v_c81 = _t[9];
        ++_fires;
        if (!((is_struct(v_c16) && (decode_struct_id(v_c16) == sid158 || decode_struct_id(v_c16) == sid159 || decode_struct_id(v_c16) == sid160))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c66, v_c67, v_c68, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c79)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c66, v_c69, v_c70, v_c79}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c78)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c66, v_c71, v_c72, v_c78}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c80) && (decode_struct_id(v_c80) == sid158 || decode_struct_id(v_c80) == sid159 || decode_struct_id(v_c80) == sid160))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c66, v_c73, v_c74, v_c80}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c81) && (decode_struct_id(v_c81) == sid158 || decode_struct_id(v_c81) == sid159 || decode_struct_id(v_c81) == sid160))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c66, v_c75, v_c76, v_c81}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c78, v_c79, v_c16, v_c80, v_c81});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c79, v_c78, v_c80, v_c81}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:$sup5638x98x0x0x1", _fires);
  
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
  // (crule (pre (let __tconst2EWQ349 const6b86b273ff34fce19d6b804e)) (scan mp_get __t7Zfl351 l k) (body (exists $sup5638x51x0x0x0 (1 2 0 3 4 5) 2 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_get (2 0 1) 1 k) (join mp_get_ans (0 1) 1 __t7Zfl351 v) (join $sup5638x51x0x0x0 (1 2 0 3 4 5) 2 k l __t50Md348 m p r) (exists mp_get (0 2 1) 2 __t50Md348 k) (join mbranch (1 2 3 4 0) 4 p m l r __t5IXI347) (join mp_get (0 2 1) 3 __t50Md348 k __t5IXI347) (let __t51z6350 (band k m)) (cmp lt __t51z6350 __tconst2EWQ349)) (head (emit mp_get_ans (0 1) __t50Md348 v)) map.slog:52 #f)
  class ReadTask170 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x51x0x0x0index162;  slog::Index** mbranchindex163;  slog::Index** mp_getindex164;  slog::Index** mp_get_ansindex165;  slog::Index** $sup5638x51x0x0x0index166;  slog::Index** mp_getindex167;  slog::Index** mbranchindex168;  slog::Index** mp_getindex169;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("mp_get_ans");
      head_index[0] = readrel172->getIndex(ord171, false);
      outer_rel = db->getRelation("mp_get");
      std::vector<u16> ord173({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel174 = db->getRelation("$sup5638x51x0x0x0");
      $sup5638x51x0x0x0index162 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({3, 0, 1, 2, 4});
      slog::Relation* readrel176 = db->getRelation("mbranch");
      mbranchindex163 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({2, 0, 1});
      slog::Relation* readrel178 = db->getRelation("mp_get");
      mp_getindex164 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("mp_get_ans");
      mp_get_ansindex165 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel182 = db->getRelation("$sup5638x51x0x0x0");
      $sup5638x51x0x0x0index166 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({0, 2, 1});
      slog::Relation* readrel184 = db->getRelation("mp_get");
      mp_getindex167 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 2, 3, 4, 0});
      slog::Relation* readrel186 = db->getRelation("mbranch");
      mbranchindex168 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({0, 2, 1});
      slog::Relation* readrel188 = db->getRelation("mp_get");
      mp_getindex169 = readrel188->getIndex(ord187, false);
  
    }
    ReadTask170(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c82 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c83 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x51x0x0x0index162, std::array<u64,6>{v_c12, v_c13, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex163, std::array<u64,5>{v_c13, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_getindex164, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<2,1>(mp_get_ansindex165, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m189) {
          u64 v_c81 = m189[1];
          slog::join_probe<6,2>($sup5638x51x0x0x0index166, std::array<u64,6>{v_c12, v_c13, 0, 0, 0, 0}, [&](const std::array<u64,6>& m190) {
            u64 v_c84 = m190[2]; u64 v_c14 = m190[3]; u64 v_c15 = m190[4]; u64 v_c16 = m190[5];
            if (!slog::exists_probe<3,2>(mp_getindex167, std::array<u64,3>{v_c84, v_c12, 0})) return;
            slog::join_probe<5,4>(mbranchindex168, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, 0}, [&](const std::array<u64,5>& m191) {
              u64 v_c85 = m191[4];
              slog::join_probe<3,3>(mp_getindex169, std::array<u64,3>{v_c84, v_c12, v_c85}, [&](const std::array<u64,3>& m192) {
                u64 v_c86 = _prim_band(db, v_c12, v_c14);
                if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                u64 v_c87 = _prim_lt(db, v_c86, v_c82);
                if (v_c87 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                if (!v_c87) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c81}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:52", "delta:mp_get", _fires);
  
      if (!_done)
      {
        ReadTask170* _cont = new ReadTask170(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask170(db,b), false);
  // (crule (pre (let __tconst8hOq309 const6b86b273ff34fce19d6b804e)) (scan $sup5638x82x0x0x0 __t0iNt308 k l m p r) (body (exists mp_del (0 2 1) 2 __t0iNt308 k) (exists mp_bld (2 1 4 0 3) 3 m p r) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 l k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t62gM307) (join-old mp_del (0 2 1) 3 (0 2 1) __t0iNt308 k __t62gM307) (join-old mp_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t8pI6311 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8pI6311) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t8vNz312) (join mp_msk_ans (0 1) 2 __t8vNz312 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t1hIi313) (join mp_del_ans (0 1) 2 __t1hIi313 __v0) (join mp_bld_ans (0 1) 1 __t8pI6311 res) (let __t3mg0310 (band k m)) (cmp lt __t3mg0310 __tconst8hOq309)) (head (emit mp_del_ans (0 1) __t0iNt308 res)) map.slog:83 #f)
  class ReadTask214 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex194;  slog::Index** mp_bldindex195;  slog::Index** mp_mskindex196;  slog::Index** mp_msk_ansindex197;  slog::Index** mp_delindex198;  slog::Index** mbranchindex199;  slog::Index** mp_delindex200;  slog::Index** mp_bldindex201;  slog::Index** mp_del_ansindex202;  slog::Index** mp_bld_ansindex203;  slog::Index** mp_mskindex204;  slog::Index** mp_msk_ansindex205;  slog::Index** mp_delindex206;  slog::Index** mp_del_ansindex207;  slog::Index** mp_bld_ansindex208;  slog::Index** mbranchdelta209;  slog::Index** mp_deldelta210;  slog::Index** mp_blddelta211;  slog::Index** mp_mskdelta212;  slog::Index** mp_deldelta213;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord215({0, 1});
      slog::Relation* readrel216 = db->getRelation("mp_del_ans");
      head_index[0] = readrel216->getIndex(ord215, false);
      outer_rel = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord217({0, 2, 1});
      slog::Relation* readrel218 = db->getRelation("mp_del");
      mp_delindex194 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({2, 1, 4, 0, 3});
      slog::Relation* readrel220 = db->getRelation("mp_bld");
      mp_bldindex195 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({1, 2, 0});
      slog::Relation* readrel222 = db->getRelation("mp_msk");
      mp_mskindex196 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 0});
      slog::Relation* readrel224 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex197 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 2, 0});
      slog::Relation* readrel226 = db->getRelation("mp_del");
      mp_delindex198 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 2, 3, 4, 0});
      slog::Relation* readrel228 = db->getRelation("mbranch");
      mbranchindex199 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 3, 4, 0});
      slog::Relation* readrel230 = db->getRelation("mbranch");
      mbranchdelta209 = readrel230->getIndex(ord229, true);
      std::vector<u16> ord231({0, 2, 1});
      slog::Relation* readrel232 = db->getRelation("mp_del");
      mp_delindex200 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 2, 1});
      slog::Relation* readrel234 = db->getRelation("mp_del");
      mp_deldelta210 = readrel234->getIndex(ord233, true);
      std::vector<u16> ord235({2, 1, 4, 0, 3});
      slog::Relation* readrel236 = db->getRelation("mp_bld");
      mp_bldindex201 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({2, 1, 4, 0, 3});
      slog::Relation* readrel238 = db->getRelation("mp_bld");
      mp_blddelta211 = readrel238->getIndex(ord237, true);
      std::vector<u16> ord239({1, 0});
      slog::Relation* readrel240 = db->getRelation("mp_del_ans");
      mp_del_ansindex202 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({0, 1});
      slog::Relation* readrel242 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex203 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 2, 0});
      slog::Relation* readrel244 = db->getRelation("mp_msk");
      mp_mskindex204 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 2, 0});
      slog::Relation* readrel246 = db->getRelation("mp_msk");
      mp_mskdelta212 = readrel246->getIndex(ord245, true);
      std::vector<u16> ord247({0, 1});
      slog::Relation* readrel248 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex205 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("mp_del");
      mp_delindex206 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 2, 0});
      slog::Relation* readrel252 = db->getRelation("mp_del");
      mp_deldelta213 = readrel252->getIndex(ord251, true);
      std::vector<u16> ord253({0, 1});
      slog::Relation* readrel254 = db->getRelation("mp_del_ans");
      mp_del_ansindex207 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({0, 1});
      slog::Relation* readrel256 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex208 = readrel256->getIndex(ord255, false);
  
    }
    ReadTask214(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c89 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c16 = _t[5];
        if (!slog::exists_probe<3,2>(mp_delindex194, std::array<u64,3>{v_c89, v_c12, 0})) return;
        if (!slog::exists_probe<5,3>(mp_bldindex195, std::array<u64,5>{v_c14, v_c15, v_c16, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex196, std::array<u64,3>{v_c12, v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex197, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<3,2>(mp_delindex198, std::array<u64,3>{v_c13, v_c12, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex199, mbranchdelta209, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, 0}, [&](const std::array<u64,5>& m257) {
          u64 v_c90 = m257[4];
          slog::join_probe_old<3,3>(mp_delindex200, mp_deldelta210, std::array<u64,3>{v_c89, v_c12, v_c90}, [&](const std::array<u64,3>& m258) {
            slog::join_probe_old<5,3>(mp_bldindex201, mp_blddelta211, std::array<u64,5>{v_c14, v_c15, v_c16, 0, 0}, [&](const std::array<u64,5>& m259) {
              u64 v_c91 = m259[3]; u64 v_c92 = m259[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex202, std::array<u64,2>{v_c92, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex203, std::array<u64,2>{v_c91, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex204, mp_mskdelta212, std::array<u64,3>{v_c12, v_c14, 0}, [&](const std::array<u64,3>& m260) {
                u64 v_c93 = m260[2];
                slog::join_probe<2,2>(mp_msk_ansindex205, std::array<u64,2>{v_c93, v_c15}, [&](const std::array<u64,2>& m261) {
                  slog::join_probe_old<3,2>(mp_delindex206, mp_deldelta213, std::array<u64,3>{v_c13, v_c12, 0}, [&](const std::array<u64,3>& m262) {
                    u64 v_c94 = m262[2];
                    slog::join_probe<2,2>(mp_del_ansindex207, std::array<u64,2>{v_c94, v_c92}, [&](const std::array<u64,2>& m263) {
                      slog::join_probe<2,1>(mp_bld_ansindex208, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m264) {
                        u64 v_c95 = m264[1];
                        u64 v_c96 = _prim_band(db, v_c12, v_c14);
                        if (v_c96 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c97 = _prim_lt(db, v_c96, v_c88);
                        if (v_c97 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c97) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c89, v_c95}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:$sup5638x82x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask214* _cont = new ReadTask214(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask214(db,b), false);
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan mp_join __t7O3e781 p0 t0 p1 t1) (body (join $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t7O3e781 p1 t0 t1) (exists $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t7O3e781 p0 p1 t0 t1) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x29x0x0x1 (0 3 4 5 6 1 2) 5 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0) (exists mp_hsb_ans (0 1) 1 __t8x7Q785) (exists mp_hsb_ans (0 1) 2 __t8x7Q785 __v0) (join $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0 dup6QI21998 dup4FCe1999 __v1 __v3) (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join mp_hsb_ans (0 1) 2 __t8x7Q785 __v3) (join mp_hsb_ans (0 1) 2 __t8x7Q785 __v1) (join mp_hsb_ans (0 1) 2 __t8x7Q785 __v0) (join mp_msk (1 2 0) 2 p0 __v1 __t4ZDq788) (join mp_msk_ans (0 1) 1 __t4ZDq788 __v2) (let __t1znr789 (bxor p0 p1)) (join mp_hsb (0 1) 2 __t8x7Q785 __t1znr789) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask279 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x29x0x0x0index266;  slog::Index** $sup5638x29x0x0x2index267;  slog::Index** mp_mskindex268;  slog::Index** $sup5638x29x0x0x1index269;  slog::Index** mp_hsb_ansindex270;  slog::Index** mp_hsb_ansindex271;  slog::Index** $sup5638x29x0x0x2index272;  slog::Index** mp_hsb_ansindex273;  slog::Index** mp_hsb_ansindex274;  slog::Index** mp_hsb_ansindex275;  slog::Index** mp_mskindex276;  slog::Index** mp_msk_ansindex277;  slog::Index** mp_hsbindex278;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord280({1, 0, 2, 3, 4});
      slog::Relation* readrel281 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index266 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel283 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index267 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({1, 2, 0});
      slog::Relation* readrel285 = db->getRelation("mp_msk");
      mp_mskindex268 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel287 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index269 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({0, 1});
      slog::Relation* readrel289 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex270 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({0, 1});
      slog::Relation* readrel291 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex271 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel293 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index272 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({0, 1});
      slog::Relation* readrel295 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex273 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({0, 1});
      slog::Relation* readrel297 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex274 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({0, 1});
      slog::Relation* readrel299 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex275 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 2, 0});
      slog::Relation* readrel301 = db->getRelation("mp_msk");
      mp_mskindex276 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({0, 1});
      slog::Relation* readrel303 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex277 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("mp_hsb");
      mp_hsbindex278 = readrel305->getIndex(ord304, false);
  
    }
    ReadTask279(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c99 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c101 = _t[2];
        u64 v_c102 = _t[3];
        u64 v_c103 = _t[4];
        slog::join_probe<5,5>($sup5638x29x0x0x0index266, std::array<u64,5>{v_c100, v_c99, v_c102, v_c101, v_c103}, [&](const std::array<u64,5>& m306) {
          if (!slog::exists_probe<11,5>($sup5638x29x0x0x2index267, std::array<u64,11>{v_c99, v_c100, v_c102, v_c101, v_c103, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex268, std::array<u64,3>{v_c100, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x29x0x0x1index269, std::array<u64,7>{v_c99, v_c100, v_c102, v_c101, v_c103, 0, 0}, [&](const std::array<u64,7>& m307) {
            u64 v_c104 = m307[5]; u64 v_c92 = m307[6];
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex270, std::array<u64,2>{v_c104, 0})) return;
            if (!slog::exists_probe<2,2>(mp_hsb_ansindex271, std::array<u64,2>{v_c104, v_c92})) return;
            slog::join_probe<11,7>($sup5638x29x0x0x2index272, std::array<u64,11>{v_c99, v_c100, v_c102, v_c101, v_c103, v_c104, v_c92, 0, 0, 0, 0}, [&](const std::array<u64,11>& m308) {
              u64 v_c105 = m308[7]; u64 v_c106 = m308[8]; u64 v_c107 = m308[9]; u64 v_c108 = m308[10];
              if (v_c104 != v_c106) return;
              if (v_c104 != v_c105) return;
              slog::join_probe<2,2>(mp_hsb_ansindex273, std::array<u64,2>{v_c104, v_c108}, [&](const std::array<u64,2>& m309) {
                slog::join_probe<2,2>(mp_hsb_ansindex274, std::array<u64,2>{v_c104, v_c107}, [&](const std::array<u64,2>& m310) {
                  slog::join_probe<2,2>(mp_hsb_ansindex275, std::array<u64,2>{v_c104, v_c92}, [&](const std::array<u64,2>& m311) {
                    slog::join_probe<3,2>(mp_mskindex276, std::array<u64,3>{v_c100, v_c107, 0}, [&](const std::array<u64,3>& m312) {
                      u64 v_c109 = m312[2];
                      slog::join_probe<2,1>(mp_msk_ansindex277, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m313) {
                        u64 v_c110 = m313[1];
                        u64 v_c111 = _prim_bxor(db, v_c100, v_c102);
                        if (v_c111 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe<2,2>(mp_hsbindex278, std::array<u64,2>{v_c104, v_c111}, [&](const std::array<u64,2>& m314) {
                          u64 v_c112 = _prim_band(db, v_c100, v_c92);
                          if (v_c112 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c113 = _prim_gt(db, v_c112, v_c98);
                          if (v_c113 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c113) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c99, v_c110, v_c108, v_c101, v_c103});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c110, v_c108, v_c103, v_c101}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask279* _cont = new ReadTask279(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask279(db,b), false);
  // (crule (pre) (scan mp_msk __t7tLj279 p n) (body (exists $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (join mp_msk_ans (0 1) 1 __t7tLj279 q) (join $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) __d0 u __t7tLj279 l m n p q r v)) map.slog:105 #f)
  class ReadTask319 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index316;  slog::Index** mp_msk_ansindex317;  slog::Index** $sup5638x104x0x0x0index318;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord320({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel321 = db->getRelation("$sup5638x104x0x0x1");
      head_index[0] = readrel321->getIndex(ord320, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord322({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel323 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index316 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({0, 1});
      slog::Relation* readrel325 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex317 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel327 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index318 = readrel327->getIndex(ord326, false);
  
    }
    ReadTask319(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c114 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c78 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index316, std::array<u64,9>{v_c78, v_c15, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex317, std::array<u64,2>{v_c114, 0}, [&](const std::array<u64,2>& m328) {
          u64 v_c79 = m328[1];
          slog::join_probe<9,3>($sup5638x104x0x0x0index318, std::array<u64,9>{v_c78, v_c15, v_c79, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m329) {
            u64 v_c11 = m329[3]; u64 v_c13 = m329[4]; u64 v_c14 = m329[5]; u64 v_c16 = m329[6]; u64 v_c80 = m329[7]; u64 v_c81 = m329[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c11, v_c80, v_c114, v_c13, v_c14, v_c78, v_c15, v_c79, v_c16, v_c81}, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask319* _cont = new ReadTask319(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask319(db,b), false);
  // (crule (pre) (scan mp_msk __t4Cp5299 k m) (body (exists $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 2 k m) (join mp_msk_ans (0 1) 1 __t4Cp5299 p) (join $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 3 k m p __d0 l r v)) (head (emit $sup5638x40x0x0x1 (1 5 0 2 3 4 6 7) __t4Cp5299 p __d0 k l m r v)) map.slog:41 #f)
  class ReadTask333 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x0index330;  slog::Index** mp_msk_ansindex331;  slog::Index** $sup5638x40x0x0x0index332;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord334({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel335 = db->getRelation("$sup5638x40x0x0x1");
      head_index[0] = readrel335->getIndex(ord334, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord336({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel337 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index330 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex331 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel341 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index332 = readrel341->getIndex(ord340, false);
  
    }
    ReadTask333(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c115 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x40x0x0x0index330, std::array<u64,7>{v_c12, v_c14, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex331, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m342) {
          u64 v_c15 = m342[1];
          slog::join_probe<7,3>($sup5638x40x0x0x0index332, std::array<u64,7>{v_c12, v_c14, v_c15, 0, 0, 0, 0}, [&](const std::array<u64,7>& m343) {
            u64 v_c11 = m343[3]; u64 v_c13 = m343[4]; u64 v_c16 = m343[5]; u64 v_c81 = m343[6];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c115, v_c15, v_c11, v_c12, v_c13, v_c14, v_c16, v_c81}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask333* _cont = new ReadTask333(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask333(db,b), false);
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan mp_hsb_ans __t0Ayb132 __v1) (body (exists mp_hsb_ans (0 1) 1 __t0Ayb132) (exists $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 2 __t0Ayb132 __v1) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 1 __t0Ayb132) (exists mp_msk (2 0 1) 1 __v1) (join mp_hsb_ans (0 1) 1 __t0Ayb132 __v3) (exists $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t0Ayb132 __v1 __v3) (join-old mp_hsb_ans (0 1) 1 (0 1) __t0Ayb132 __v0) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 2 __t0Ayb132 __v0) (join $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t0Ayb132 __v0 __v3 __v1 __t8CpS128 dup4t6F1978 dup2J5X1979 p0 p1 t0 t1) (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t8CpS128 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t8CpS128) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t40jf135) (join mp_msk_ans (0 1) 1 __t40jf135 __v2) (let __t867d136 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t0Ayb132 __t867d136) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask363 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex344;  slog::Index** $sup5638x25x0x0x2index345;  slog::Index** $sup5638x25x0x0x1index346;  slog::Index** mp_mskindex347;  slog::Index** mp_hsb_ansindex348;  slog::Index** $sup5638x25x0x0x2index349;  slog::Index** mp_hsb_ansindex350;  slog::Index** $sup5638x25x0x0x1index351;  slog::Index** $sup5638x25x0x0x2index352;  slog::Index** $sup5638x25x0x0x1index353;  slog::Index** $sup5638x25x0x0x0index354;  slog::Index** mp_joinindex355;  slog::Index** mp_mskindex356;  slog::Index** mp_msk_ansindex357;  slog::Index** mp_hsbindex358;  slog::Index** mp_hsb_ansdelta359;  slog::Index** mp_joindelta360;  slog::Index** mp_mskdelta361;  slog::Index** mp_hsbdelta362;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord364({0, 1});
      slog::Relation* readrel365 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex344 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel367 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index345 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel369 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index346 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({2, 0, 1});
      slog::Relation* readrel371 = db->getRelation("mp_msk");
      mp_mskindex347 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({0, 1});
      slog::Relation* readrel373 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex348 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel375 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index349 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({0, 1});
      slog::Relation* readrel377 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex350 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 1});
      slog::Relation* readrel379 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta359 = readrel379->getIndex(ord378, true);
      std::vector<u16> ord380({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel381 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index351 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel383 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index352 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel385 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index353 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 0, 2, 3, 4});
      slog::Relation* readrel387 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index354 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 2, 3, 4, 0});
      slog::Relation* readrel389 = db->getRelation("mp_join");
      mp_joinindex355 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 2, 3, 4, 0});
      slog::Relation* readrel391 = db->getRelation("mp_join");
      mp_joindelta360 = readrel391->getIndex(ord390, true);
      std::vector<u16> ord392({1, 2, 0});
      slog::Relation* readrel393 = db->getRelation("mp_msk");
      mp_mskindex356 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 2, 0});
      slog::Relation* readrel395 = db->getRelation("mp_msk");
      mp_mskdelta361 = readrel395->getIndex(ord394, true);
      std::vector<u16> ord396({0, 1});
      slog::Relation* readrel397 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex357 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({0, 1});
      slog::Relation* readrel399 = db->getRelation("mp_hsb");
      mp_hsbindex358 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({0, 1});
      slog::Relation* readrel401 = db->getRelation("mp_hsb");
      mp_hsbdelta362 = readrel401->getIndex(ord400, true);
  
    }
    ReadTask363(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c117 = _t[0];
        u64 v_c107 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex344, std::array<u64,2>{v_c117, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index345, std::array<u64,11>{v_c117, v_c107, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index346, std::array<u64,7>{v_c117, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex347, std::array<u64,3>{v_c107, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex348, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m402) {
          u64 v_c108 = m402[1];
          if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index349, std::array<u64,11>{v_c117, v_c107, v_c108, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex350, mp_hsb_ansdelta359, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m403) {
            u64 v_c92 = m403[1];
            if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index351, std::array<u64,7>{v_c117, v_c92, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x25x0x0x2index352, std::array<u64,11>{v_c117, v_c92, v_c108, v_c107, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m404) {
              u64 v_c118 = m404[4]; u64 v_c119 = m404[5]; u64 v_c120 = m404[6]; u64 v_c100 = m404[7]; u64 v_c102 = m404[8]; u64 v_c101 = m404[9]; u64 v_c103 = m404[10];
              if (v_c117 != v_c120) return;
              if (v_c117 != v_c119) return;
              slog::join_probe<7,7>($sup5638x25x0x0x1index353, std::array<u64,7>{v_c118, v_c100, v_c102, v_c101, v_c103, v_c117, v_c92}, [&](const std::array<u64,7>& m405) {
                slog::join_probe<5,5>($sup5638x25x0x0x0index354, std::array<u64,5>{v_c100, v_c118, v_c102, v_c101, v_c103}, [&](const std::array<u64,5>& m406) {
                  slog::join_probe_old<5,5>(mp_joinindex355, mp_joindelta360, std::array<u64,5>{v_c100, v_c101, v_c102, v_c103, v_c118}, [&](const std::array<u64,5>& m407) {
                    slog::join_probe_old<3,2>(mp_mskindex356, mp_mskdelta361, std::array<u64,3>{v_c100, v_c107, 0}, [&](const std::array<u64,3>& m408) {
                      u64 v_c121 = m408[2];
                      slog::join_probe<2,1>(mp_msk_ansindex357, std::array<u64,2>{v_c121, 0}, [&](const std::array<u64,2>& m409) {
                        u64 v_c110 = m409[1];
                        u64 v_c122 = _prim_bxor(db, v_c100, v_c102);
                        if (v_c122 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex358, mp_hsbdelta362, std::array<u64,2>{v_c117, v_c122}, [&](const std::array<u64,2>& m410) {
                          u64 v_c123 = _prim_band(db, v_c100, v_c92);
                          if (v_c123 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c124 = _prim_lt(db, v_c123, v_c116);
                          if (v_c124 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c124) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c118, v_c110, v_c108, v_c101, v_c103});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c110, v_c108, v_c101, v_c103}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask363* _cont = new ReadTask363(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask363(db,b), false);
  // (crule (pre (let __tconst4JFo1084 constcd2a69ce5ca278db1d6da969) (let _00024sqc2XJk894 constd4735e3a265e16eee03f5971) (let _00024sqc3Vvh895 const5feceb66ffc86f38d952786c) (let _00024sqc1G23896 const6b86b273ff34fce19d6b804e) (let _00024sqo5Yvx897 const5feceb66ffc86f38d952786c) (let _00024sqo6jkp898 const6b86b273ff34fce19d6b804e) (let _00024sqo3xdn899 const6b86b273ff34fce19d6b804e) (let _00024sqo4MmQ900 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo3xdn899 __t6Yod544 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5Yvx897 __t6Yod544 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo6jkp898 __t6Yod544 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4MmQ900 __t6Yod544 _00024seq2) (join _enum (0 1) 2 __t6Yod544 __tconst4JFo1084) (join delta (2 0 1) 1 _00024seq2 __t7695542 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql014l892 (aslst _00024seq2)) (let chk4BfB1804 (llen _00024sql014l892)) (eq _00024sqc2XJk894 chk4BfB1804) (letp chk5dzs1805 (lref _00024sql014l892 _00024sqc3Vvh895)) (eq __t6Yod544 chk5dzs1805) (letp chk9Oo01806 (lref _00024sql014l892 _00024sqc1G23896)) (eq __t6Yod544 chk9Oo01806)) (head (emit-temp temp4Zu91795 __t7695542 b) (mkstruct boolval (1 0) __t4iE5541 b)) interp.slog:117 #f)
  class ReadTask420 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex412;  slog::Index** $seq_atindex413;  slog::Index** $seq_atrindex414;  slog::Index** _enumindex415;  slog::Index** deltaindex416;  slog::Index** comparison_opindex417;  slog::Index** any_boolindex418;  slog::Index** $seq_atrdelta419;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4Zu91795");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord421({1, 0, 2});
      slog::Relation* readrel422 = db->getRelation("$seq_atr");
      driver_index = readrel422->getIndex(ord421, true);
      std::vector<u16> ord423({1, 0, 2});
      slog::Relation* readrel424 = db->getRelation("$seq_at");
      $seq_atindex412 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({1, 0, 2});
      slog::Relation* readrel426 = db->getRelation("$seq_at");
      $seq_atindex413 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({1, 0, 2});
      slog::Relation* readrel428 = db->getRelation("$seq_atr");
      $seq_atrindex414 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({1, 0, 2});
      slog::Relation* readrel430 = db->getRelation("$seq_atr");
      $seq_atrdelta419 = readrel430->getIndex(ord429, true);
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("_enum");
      _enumindex415 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({2, 0, 1});
      slog::Relation* readrel434 = db->getRelation("delta");
      deltaindex416 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({0});
      slog::Relation* readrel436 = db->getRelation("comparison_op");
      comparison_opindex417 = readrel436->getIndex(ord435, false);
      std::vector<u16> ord437({0});
      slog::Relation* readrel438 = db->getRelation("any_bool");
      any_boolindex418 = readrel438->getIndex(ord437, false);
  
    }
    ReadTask420(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c125 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c126 = v_constd4735e3a265e16eee03f5971;
      u64 v_c127 = v_const5feceb66ffc86f38d952786c;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_const5feceb66ffc86f38d952786c;
      u64 v_c130 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c131 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c132 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c131, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m439) {
        u64 v_c133 = m439[1];
        u64 v_c134 = m439[2];
        if (buckethash(v_c133) != bucket) return;
        slog::join_probe<3,3>($seq_atindex412, std::array<u64,3>{v_c129, v_c133, v_c134}, [&](const std::array<u64,3>& m440) {
          slog::join_probe<3,3>($seq_atindex413, std::array<u64,3>{v_c130, v_c133, v_c134}, [&](const std::array<u64,3>& m441) {
            slog::join_probe_old<3,3>($seq_atrindex414, $seq_atrdelta419, std::array<u64,3>{v_c132, v_c133, v_c134}, [&](const std::array<u64,3>& m442) {
              slog::join_probe<2,2>(_enumindex415, std::array<u64,2>{v_c133, v_c125}, [&](const std::array<u64,2>& m443) {
                slog::join_probe<3,1>(deltaindex416, std::array<u64,3>{v_c134, 0, 0}, [&](const std::array<u64,3>& m444) {
                  u64 v_c135 = m444[1]; u64 v_c136 = m444[2];
                  slog::join_probe<1,1>(comparison_opindex417, std::array<u64,1>{v_c136}, [&](const std::array<u64,1>& m445) {
                    slog::join_all<1>(any_boolindex418, [&](const std::array<u64,1>& m446) {
                      u64 v_c137 = m446[0];
                      bool ok447 = true;
                      u64 v_c138 = _prim_aslst(db, v_c134, &ok447);
                      if (!ok447) return;
                      u64 v_c139 = _prim_llen(db, v_c138);
                      if (v_c139 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                      if (v_c126 != v_c139) return;
                      bool ok448 = true;
                      u64 v_c140 = _prim_lref(db, v_c138, v_c127, &ok448);
                      if (!ok448) return;
                      if (v_c133 != v_c140) return;
                      bool ok449 = true;
                      u64 v_c141 = _prim_lref(db, v_c138, v_c128, &ok449);
                      if (!ok449) return;
                      if (v_c133 != v_c141) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c135, v_c137});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c137}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask420* _cont = new ReadTask420(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask420(db,b), false);
  // (crule (pre (let _00024sqc4Fzm988 constd4735e3a265e16eee03f5971) (let _00024sqc6SKj989 const5feceb66ffc86f38d952786c) (let _00024sqc8JKk990 const6b86b273ff34fce19d6b804e) (let _00024sqc2Wqs993 const6b86b273ff34fce19d6b804e) (let _00024sqc3gqm994 const5feceb66ffc86f38d952786c) (let _00024sqc5u0R995 const6b86b273ff34fce19d6b804e) (let _00024sqc2qd4996 const5feceb66ffc86f38d952786c) (let _00024sqo0rW61001 const5feceb66ffc86f38d952786c)) (scan mp_fromlist_ans __t3r8n764 __v0) (body (exists $seq_at (1 0 2) 1 _00024sqo0rW61001) (exists mp_put (1 2 3 0) 1 __v0) (join mp_fromlist (0 1) 1 __t3r8n764 xs) (exists $sup5638x127x0x0x0 (5 0 1 2 3 4) 1 xs) (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo0rW61001 _00024seq0 _00024seq1) (letp _00024sql7g5s986 (aslst _00024seq0)) (letp k (lref _00024sql7g5s986 _00024sqc6SKj989)) (letp v (lref _00024sql7g5s986 _00024sqc8JKk990)) (exists mp_put (1 2 3 0) 3 __v0 k v) (exists mp_fromlist (1 0) 1 _00024seq1) (join $sup5638x127x0x0x0 (3 4 5 0 1 2) 5 k v xs _00024seq0 _00024seq1 __t1Wom763) (exists mp_fromlist (0 1) 2 __t1Wom763 _00024seq1) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) __v0 k v __t5IsX765) (join mp_fromlist (0 1) 2 __t1Wom763 _00024seq1) (join-old mp_put_ans (0 1) 1 (0 1) __t5IsX765 __v1) (letp _00024sql4o7j991 (aslst _00024seq1)) (let _00024sqn095f992 (llen _00024sql4o7j991)) (cmp ge _00024sqn095f992 _00024sqc2Wqs993) (let chk95Ux1879 (llen _00024sql7g5s986)) (eq _00024sqc4Fzm988 chk95Ux1879) (letp chk7T4A1880 (lref _00024sql4o7j991 _00024sqc3gqm994)) (eq _00024seq0 chk7T4A1880) (let _00024sqp3avN997 (_0002d _00024sqn095f992 _00024sqc2qd4996)) (let chk8AuQ1881 (lslice _00024sql4o7j991 _00024sqc5u0R995 _00024sqp3avN997)) (eq xs chk8AuQ1881)) (head (emit mp_fromlist_ans (1 0) __v1 __t1Wom763)) map.slog:128 #f)
  class ReadTask465 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex450;  slog::Index** mp_putindex451;  slog::Index** mp_fromlistindex452;  slog::Index** $sup5638x127x0x0x0index453;  slog::Index** $seq_atindex454;  slog::Index** mp_putindex455;  slog::Index** mp_fromlistindex456;  slog::Index** $sup5638x127x0x0x0index457;  slog::Index** mp_fromlistindex458;  slog::Index** mp_putindex459;  slog::Index** mp_fromlistindex460;  slog::Index** mp_put_ansindex461;  slog::Index** $seq_atdelta462;  slog::Index** mp_putdelta463;  slog::Index** mp_put_ansdelta464;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord466({1, 0});
      slog::Relation* readrel467 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel467->getIndex(ord466, false);
      outer_rel = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord468({1, 0, 2});
      slog::Relation* readrel469 = db->getRelation("$seq_at");
      $seq_atindex450 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 2, 3, 0});
      slog::Relation* readrel471 = db->getRelation("mp_put");
      mp_putindex451 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({0, 1});
      slog::Relation* readrel473 = db->getRelation("mp_fromlist");
      mp_fromlistindex452 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({5, 0, 1, 2, 3, 4});
      slog::Relation* readrel475 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index453 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 0, 2});
      slog::Relation* readrel477 = db->getRelation("$seq_at");
      $seq_atindex454 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 0, 2});
      slog::Relation* readrel479 = db->getRelation("$seq_at");
      $seq_atdelta462 = readrel479->getIndex(ord478, true);
      std::vector<u16> ord480({1, 2, 3, 0});
      slog::Relation* readrel481 = db->getRelation("mp_put");
      mp_putindex455 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 0});
      slog::Relation* readrel483 = db->getRelation("mp_fromlist");
      mp_fromlistindex456 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel485 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index457 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({0, 1});
      slog::Relation* readrel487 = db->getRelation("mp_fromlist");
      mp_fromlistindex458 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({1, 2, 3, 0});
      slog::Relation* readrel489 = db->getRelation("mp_put");
      mp_putindex459 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 2, 3, 0});
      slog::Relation* readrel491 = db->getRelation("mp_put");
      mp_putdelta463 = readrel491->getIndex(ord490, true);
      std::vector<u16> ord492({0, 1});
      slog::Relation* readrel493 = db->getRelation("mp_fromlist");
      mp_fromlistindex460 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1});
      slog::Relation* readrel495 = db->getRelation("mp_put_ans");
      mp_put_ansindex461 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({0, 1});
      slog::Relation* readrel497 = db->getRelation("mp_put_ans");
      mp_put_ansdelta464 = readrel497->getIndex(ord496, true);
  
    }
    ReadTask465(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_constd4735e3a265e16eee03f5971;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
      u64 v_c144 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c145 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c146 = v_const5feceb66ffc86f38d952786c;
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c148 = v_const5feceb66ffc86f38d952786c;
      u64 v_c149 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c150 = _t[0];
        u64 v_c92 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex450, std::array<u64,3>{v_c149, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex451, std::array<u64,4>{v_c92, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_fromlistindex452, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m498) {
          u64 v_c151 = m498[1];
          if (!slog::exists_probe<6,1>($sup5638x127x0x0x0index453, std::array<u64,6>{v_c151, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>($seq_atindex454, $seq_atdelta462, std::array<u64,3>{v_c149, 0, 0}, [&](const std::array<u64,3>& m499) {
            u64 v_c152 = m499[1]; u64 v_c153 = m499[2];
            bool ok500 = true;
            u64 v_c154 = _prim_aslst(db, v_c152, &ok500);
            if (!ok500) return;
            bool ok501 = true;
            u64 v_c12 = _prim_lref(db, v_c154, v_c143, &ok501);
            if (!ok501) return;
            bool ok502 = true;
            u64 v_c81 = _prim_lref(db, v_c154, v_c144, &ok502);
            if (!ok502) return;
            if (!slog::exists_probe<4,3>(mp_putindex455, std::array<u64,4>{v_c92, v_c12, v_c81, 0})) return;
            if (!slog::exists_probe<2,1>(mp_fromlistindex456, std::array<u64,2>{v_c153, 0})) return;
            slog::join_probe<6,5>($sup5638x127x0x0x0index457, std::array<u64,6>{v_c12, v_c81, v_c151, v_c152, v_c153, 0}, [&](const std::array<u64,6>& m503) {
              u64 v_c155 = m503[5];
              if (!slog::exists_probe<2,2>(mp_fromlistindex458, std::array<u64,2>{v_c155, v_c153})) return;
              slog::join_probe_old<4,3>(mp_putindex459, mp_putdelta463, std::array<u64,4>{v_c92, v_c12, v_c81, 0}, [&](const std::array<u64,4>& m504) {
                u64 v_c156 = m504[3];
                slog::join_probe<2,2>(mp_fromlistindex460, std::array<u64,2>{v_c155, v_c153}, [&](const std::array<u64,2>& m505) {
                  slog::join_probe_old<2,1>(mp_put_ansindex461, mp_put_ansdelta464, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m506) {
                    u64 v_c107 = m506[1];
                    bool ok507 = true;
                    u64 v_c157 = _prim_aslst(db, v_c153, &ok507);
                    if (!ok507) return;
                    u64 v_c158 = _prim_llen(db, v_c157);
                    if (v_c158 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    u64 v_c159 = _prim_ge(db, v_c158, v_c145);
                    if (v_c159 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (!v_c159) return;
                    u64 v_c160 = _prim_llen(db, v_c154);
                    if (v_c160 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c142 != v_c160) return;
                    bool ok509 = true;
                    u64 v_c161 = _prim_lref(db, v_c157, v_c146, &ok509);
                    if (!ok509) return;
                    if (v_c152 != v_c161) return;
                    u64 v_c162 = _prim__0002d(db, v_c158, v_c148);
                    if (v_c162 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    u64 v_c163 = _prim_lslice(db, v_c157, v_c147, v_c162);
                    if (v_c163 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c151 != v_c163) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c107, v_c155}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_fromlist_ans", _fires);
  
      if (!_done)
      {
        ReadTask465* _cont = new ReadTask465(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask465(db,b), false);
  // (crule (pre (let __tconst2Vg0546 const06abaa100ecef791ce028c56) (let _00024sqc2T6l964 constd4735e3a265e16eee03f5971) (let _00024sqc2Wzv965 const5feceb66ffc86f38d952786c) (let _00024sqc80On966 const6b86b273ff34fce19d6b804e) (let _00024sqo5uVM967 const5feceb66ffc86f38d952786c) (let _00024sqo11r2968 const6b86b273ff34fce19d6b804e) (let _00024sqo89F1969 const6b86b273ff34fce19d6b804e) (let _00024sqo57Hb970 const5feceb66ffc86f38d952786c)) (scan closure __t40a6549 lm rc) (body (exists $seq_at (1 0 2) 2 _00024sqo11r2968 __t40a6549) (exists $seq_atr (1 0 2) 2 _00024sqo89F1969 __t40a6549) (exists $seq_atr (1 0 2) 2 _00024sqo57Hb970 __t40a6549) (exists delta (1 2 0) 1 __tconst2Vg0546) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo5uVM967 __t40a6549 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo11r2968 __t40a6549 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo89F1969 __t40a6549 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo57Hb970 __t40a6549 _00024seq2) (join delta (1 2 0) 2 __tconst2Vg0546 _00024seq2 __t6qCW547) (join any_bool (0) 0 b) (letp _00024sql3t08962 (aslst _00024seq2)) (let chk6RSo1841 (llen _00024sql3t08962)) (eq _00024sqc2T6l964 chk6RSo1841) (letp chk4lA41842 (lref _00024sql3t08962 _00024sqc2Wzv965)) (eq __t40a6549 chk4lA41842) (letp chk0qML1843 (lref _00024sql3t08962 _00024sqc80On966)) (eq __t40a6549 chk0qML1843)) (head (emit-temp temp7z5q1838 __t6qCW547 b) (mkstruct boolval (1 0) __t1Eis545 b)) interp.slog:126 #f)
  class ReadTask524 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex510;  slog::Index** $seq_atrindex511;  slog::Index** $seq_atrindex512;  slog::Index** deltaindex513;  slog::Index** $seq_atindex514;  slog::Index** $seq_atindex515;  slog::Index** $seq_atrindex516;  slog::Index** $seq_atrindex517;  slog::Index** deltaindex518;  slog::Index** any_boolindex519;  slog::Index** $seq_atdelta520;  slog::Index** $seq_atdelta521;  slog::Index** $seq_atrdelta522;  slog::Index** $seq_atrdelta523;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7z5q1838");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord525({1, 0, 2});
      slog::Relation* readrel526 = db->getRelation("$seq_at");
      $seq_atindex510 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 0, 2});
      slog::Relation* readrel528 = db->getRelation("$seq_atr");
      $seq_atrindex511 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({1, 0, 2});
      slog::Relation* readrel530 = db->getRelation("$seq_atr");
      $seq_atrindex512 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({1, 2, 0});
      slog::Relation* readrel532 = db->getRelation("delta");
      deltaindex513 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({1, 0, 2});
      slog::Relation* readrel534 = db->getRelation("$seq_at");
      $seq_atindex514 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 0, 2});
      slog::Relation* readrel536 = db->getRelation("$seq_at");
      $seq_atdelta520 = readrel536->getIndex(ord535, true);
      std::vector<u16> ord537({1, 0, 2});
      slog::Relation* readrel538 = db->getRelation("$seq_at");
      $seq_atindex515 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 0, 2});
      slog::Relation* readrel540 = db->getRelation("$seq_at");
      $seq_atdelta521 = readrel540->getIndex(ord539, true);
      std::vector<u16> ord541({1, 0, 2});
      slog::Relation* readrel542 = db->getRelation("$seq_atr");
      $seq_atrindex516 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 0, 2});
      slog::Relation* readrel544 = db->getRelation("$seq_atr");
      $seq_atrdelta522 = readrel544->getIndex(ord543, true);
      std::vector<u16> ord545({1, 0, 2});
      slog::Relation* readrel546 = db->getRelation("$seq_atr");
      $seq_atrindex517 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 0, 2});
      slog::Relation* readrel548 = db->getRelation("$seq_atr");
      $seq_atrdelta523 = readrel548->getIndex(ord547, true);
      std::vector<u16> ord549({1, 2, 0});
      slog::Relation* readrel550 = db->getRelation("delta");
      deltaindex518 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({0});
      slog::Relation* readrel552 = db->getRelation("any_bool");
      any_boolindex519 = readrel552->getIndex(ord551, false);
  
    }
    ReadTask524(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c164 = v_const06abaa100ecef791ce028c56;
      u64 v_c165 = v_constd4735e3a265e16eee03f5971;
      u64 v_c166 = v_const5feceb66ffc86f38d952786c;
      u64 v_c167 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c168 = v_const5feceb66ffc86f38d952786c;
      u64 v_c169 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c170 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c171 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c172 = _t[0];
        u64 v_c173 = _t[1];
        u64 v_c174 = _t[2];
        if (!slog::exists_probe<3,2>($seq_atindex510, std::array<u64,3>{v_c169, v_c172, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex511, std::array<u64,3>{v_c170, v_c172, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex512, std::array<u64,3>{v_c171, v_c172, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex513, std::array<u64,3>{v_c164, 0, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex514, $seq_atdelta520, std::array<u64,3>{v_c168, v_c172, 0}, [&](const std::array<u64,3>& m553) {
          u64 v_c134 = m553[2];
          slog::join_probe_old<3,3>($seq_atindex515, $seq_atdelta521, std::array<u64,3>{v_c169, v_c172, v_c134}, [&](const std::array<u64,3>& m554) {
            slog::join_probe_old<3,3>($seq_atrindex516, $seq_atrdelta522, std::array<u64,3>{v_c170, v_c172, v_c134}, [&](const std::array<u64,3>& m555) {
              slog::join_probe_old<3,3>($seq_atrindex517, $seq_atrdelta523, std::array<u64,3>{v_c171, v_c172, v_c134}, [&](const std::array<u64,3>& m556) {
                slog::join_probe<3,2>(deltaindex518, std::array<u64,3>{v_c164, v_c134, 0}, [&](const std::array<u64,3>& m557) {
                  u64 v_c175 = m557[2];
                  slog::join_all<1>(any_boolindex519, [&](const std::array<u64,1>& m558) {
                    u64 v_c137 = m558[0];
                    bool ok559 = true;
                    u64 v_c176 = _prim_aslst(db, v_c134, &ok559);
                    if (!ok559) return;
                    u64 v_c177 = _prim_llen(db, v_c176);
                    if (v_c177 == slog_error) { slog::emit_pending_error(db, "interp.slog:126"); return; }
                    if (v_c165 != v_c177) return;
                    bool ok560 = true;
                    u64 v_c178 = _prim_lref(db, v_c176, v_c166, &ok560);
                    if (!ok560) return;
                    if (v_c172 != v_c178) return;
                    bool ok561 = true;
                    u64 v_c179 = _prim_lref(db, v_c176, v_c167, &ok561);
                    if (!ok561) return;
                    if (v_c172 != v_c179) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c175, v_c137});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c137}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:126", "delta:closure", _fires);
  
      if (!_done)
      {
        ReadTask524* _cont = new ReadTask524(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask524(db,b), false);
  // (crule (pre (let __tconst7YVO1086 constb9e118781cea1f9fa01462e0) (let __tconst0qOo437 const60e3114d9b4b6577eea8cbc0) (let _00024sqc0uxV1007 const6b86b273ff34fce19d6b804e) (let _00024sqc0jY31008 const5feceb66ffc86f38d952786c) (let _00024sqo1OME1009 const5feceb66ffc86f38d952786c) (let _00024sqo3mx21010 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo3mx21010 v _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo1OME1009 v _00024seq0) (exists _enum (1 0) 1 __tconst7YVO1086) (join delta (1 2 0) 2 __tconst0qOo437 _00024seq0 __t4KDF438) (join _enum (1 0) 1 __tconst7YVO1086 __t2dgW435) (join scheme_false (0) 0 fv) (neq v fv) (letp _00024sql5Lne1005 (aslst _00024seq0)) (let chk6R2T1821 (llen _00024sql5Lne1005)) (eq _00024sqc0uxV1007 chk6R2T1821) (letp chk5qTh1822 (lref _00024sql5Lne1005 _00024sqc0jY31008)) (eq v chk5qTh1822)) (head (emit-temp temp6YY41815 __t4KDF438) (mkstruct boolval (1 0) __t83Bj436 __t2dgW435)) interp.slog:119 #f)
  class ReadTask567 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex562;  slog::Index** _enumindex563;  slog::Index** deltaindex564;  slog::Index** _enumindex565;  slog::Index** scheme_falseindex566;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6YY41815");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord568({1, 0, 2});
      slog::Relation* readrel569 = db->getRelation("$seq_atr");
      driver_index = readrel569->getIndex(ord568, true);
      std::vector<u16> ord570({1, 0, 2});
      slog::Relation* readrel571 = db->getRelation("$seq_at");
      $seq_atindex562 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 0});
      slog::Relation* readrel573 = db->getRelation("_enum");
      _enumindex563 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 2, 0});
      slog::Relation* readrel575 = db->getRelation("delta");
      deltaindex564 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 0});
      slog::Relation* readrel577 = db->getRelation("_enum");
      _enumindex565 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({0});
      slog::Relation* readrel579 = db->getRelation("scheme_false");
      scheme_falseindex566 = readrel579->getIndex(ord578, false);
  
    }
    ReadTask567(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c180 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c181 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c182 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c183 = v_const5feceb66ffc86f38d952786c;
      u64 v_c184 = v_const5feceb66ffc86f38d952786c;
      u64 v_c185 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c185, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m580) {
        u64 v_c81 = m580[1];
        u64 v_c152 = m580[2];
        if (buckethash(v_c81) != bucket) return;
        slog::join_probe<3,3>($seq_atindex562, std::array<u64,3>{v_c184, v_c81, v_c152}, [&](const std::array<u64,3>& m581) {
          if (!slog::exists_probe<2,1>(_enumindex563, std::array<u64,2>{v_c180, 0})) return;
          slog::join_probe<3,2>(deltaindex564, std::array<u64,3>{v_c181, v_c152, 0}, [&](const std::array<u64,3>& m582) {
            u64 v_c186 = m582[2];
            slog::join_probe<2,1>(_enumindex565, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m583) {
              u64 v_c187 = m583[1];
              slog::join_all<1>(scheme_falseindex566, [&](const std::array<u64,1>& m584) {
                u64 v_c188 = m584[0];
                if (v_c81 == v_c188) return;
                bool ok585 = true;
                u64 v_c189 = _prim_aslst(db, v_c152, &ok585);
                if (!ok585) return;
                u64 v_c190 = _prim_llen(db, v_c189);
                if (v_c190 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                if (v_c182 != v_c190) return;
                bool ok586 = true;
                u64 v_c191 = _prim_lref(db, v_c189, v_c183, &ok586);
                if (!ok586) return;
                if (v_c81 != v_c191) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c186});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c187}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask567* _cont = new ReadTask567(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask567(db,b), false);
  // (crule (pre) (scan mp_get __t0Izo363 rho x) (body (exists mp_get_ans (0 1) 1 __t0Izo363) (exists store (0 1 2) 1 x) (join lookup (1 2 0) 2 x rho __t95yV362) (join mp_get_ans (0 1) 1 __t0Izo363 tx) (join store (0 1 2) 2 x tx v)) (head (emit lookup_ans (0 1) __t95yV362 v)) interp.slog:39 #f)
  class ReadTask592 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_get_ansindex587;  slog::Index** storeindex588;  slog::Index** lookupindex589;  slog::Index** mp_get_ansindex590;  slog::Index** storeindex591;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord593({0, 1});
      slog::Relation* readrel594 = db->getRelation("lookup_ans");
      head_index[0] = readrel594->getIndex(ord593, false);
      outer_rel = db->getRelation("mp_get");
      std::vector<u16> ord595({0, 1});
      slog::Relation* readrel596 = db->getRelation("mp_get_ans");
      mp_get_ansindex587 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({0, 1, 2});
      slog::Relation* readrel598 = db->getRelation("store");
      storeindex588 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({1, 2, 0});
      slog::Relation* readrel600 = db->getRelation("lookup");
      lookupindex589 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({0, 1});
      slog::Relation* readrel602 = db->getRelation("mp_get_ans");
      mp_get_ansindex590 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({0, 1, 2});
      slog::Relation* readrel604 = db->getRelation("store");
      storeindex591 = readrel604->getIndex(ord603, false);
  
    }
    ReadTask592(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c192 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c29 = _t[2];
        if (!slog::exists_probe<2,1>(mp_get_ansindex587, std::array<u64,2>{v_c192, 0})) return;
        if (!slog::exists_probe<3,1>(storeindex588, std::array<u64,3>{v_c29, 0, 0})) return;
        slog::join_probe<3,2>(lookupindex589, std::array<u64,3>{v_c29, v_c26, 0}, [&](const std::array<u64,3>& m605) {
          u64 v_c193 = m605[2];
          slog::join_probe<2,1>(mp_get_ansindex590, std::array<u64,2>{v_c192, 0}, [&](const std::array<u64,2>& m606) {
            u64 v_c194 = m606[1];
            slog::join_probe<3,2>(storeindex591, std::array<u64,3>{v_c29, v_c194, 0}, [&](const std::array<u64,3>& m607) {
              u64 v_c81 = m607[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c193, v_c81}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:39", "delta:mp_get", _fires);
  
      if (!_done)
      {
        ReadTask592* _cont = new ReadTask592(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask592(db,b), false);
  // (crule (pre (let __trid8LqO1205 constfee494ff4827aeb0635bb714) (let __trel2H7m1206 const20347926ddb307a8e2bdb71b) (let __tcol2B611207 constd4735e3a265e16eee03f5971)) (scan mp_msk __t0gIW440 k m) (body (exists $sup5638x84x0x0x0 (1 3 4 0 2 5) 2 k m) (exists mp_del (2 0 1) 1 k) (join mp_msk_ans (0 1) 1 __t0gIW440 p) (join $sup5638x84x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t33MJ441) (join mp_del_ans (0 1) 1 __t33MJ441 __v0)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8LqO1205 __trel2H7m1206 __tcol2B611207 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __0kM11204 p m l __v0)) map.slog:85 #f)
  class ReadTask618 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index608;  slog::Index** mp_delindex609;  slog::Index** mp_msk_ansindex610;  slog::Index** $sup5638x84x0x0x0index611;  slog::Index** mp_delindex612;  slog::Index** mp_del_ansindex613;  slog::Index** mp_deldelta614;
    u32 sid616;  u32 sid615;  u32 sid617;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord619({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel620 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index608 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({2, 0, 1});
      slog::Relation* readrel622 = db->getRelation("mp_del");
      mp_delindex609 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({0, 1});
      slog::Relation* readrel624 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex610 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel626 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index611 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 2, 0});
      slog::Relation* readrel628 = db->getRelation("mp_del");
      mp_delindex612 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({1, 2, 0});
      slog::Relation* readrel630 = db->getRelation("mp_del");
      mp_deldelta614 = readrel630->getIndex(ord629, true);
      std::vector<u16> ord631({0, 1});
      slog::Relation* readrel632 = db->getRelation("mp_del_ans");
      mp_del_ansindex613 = readrel632->getIndex(ord631, false);
      sid616 = db->getRelation("_enum")->getStructId();
      sid615 = db->getRelation("mbranch")->getStructId();
      sid617 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask618(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c195 = v_constfee494ff4827aeb0635bb714;
      u64 v_c196 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c197 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c198 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x84x0x0x0index608, std::array<u64,6>{v_c12, v_c14, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex609, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex610, std::array<u64,2>{v_c198, 0}, [&](const std::array<u64,2>& m633) {
          u64 v_c15 = m633[1];
          slog::join_probe<6,3>($sup5638x84x0x0x0index611, std::array<u64,6>{v_c12, v_c14, v_c15, 0, 0, 0}, [&](const std::array<u64,6>& m634) {
            u64 v_c11 = m634[3]; u64 v_c13 = m634[4]; u64 v_c16 = m634[5];
            slog::join_probe_old<3,2>(mp_delindex612, mp_deldelta614, std::array<u64,3>{v_c16, v_c12, 0}, [&](const std::array<u64,3>& m635) {
              u64 v_c199 = m635[2];
              slog::join_probe<2,1>(mp_del_ansindex613, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m636) {
                u64 v_c92 = m636[1];
                ++_fires;
                if (!((is_struct(v_c13) && (decode_struct_id(v_c13) == sid615 || decode_struct_id(v_c13) == sid616 || decode_struct_id(v_c13) == sid617))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c195, v_c196, v_c197, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c14, v_c13, v_c92}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask618* _cont = new ReadTask618(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask618(db,b), false);
  // (crule (pre) (scan primref __t90hH820 op) (body (join primitive (0) 1 op) (join-old eval (1 2 3 0) 1 (1 2 3 0) __t90hH820 rho t __t7AlQ821)) (head (emit-temp temp9R9Y1810 __t7AlQ821 op) (mkstruct prim (1 0) __t1HR7819 op)) interp.slog:35 #f)
  class ReadTask640 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primitiveindex637;  slog::Index** evalindex638;  slog::Index** evaldelta639;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9R9Y1810");
      head_rel[1] = db->getRelation("prim");
      outer_rel = db->getRelation("primref");
      std::vector<u16> ord641({0});
      slog::Relation* readrel642 = db->getRelation("primitive");
      primitiveindex637 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({1, 2, 3, 0});
      slog::Relation* readrel644 = db->getRelation("eval");
      evalindex638 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({1, 2, 3, 0});
      slog::Relation* readrel646 = db->getRelation("eval");
      evaldelta639 = readrel646->getIndex(ord645, true);
  
    }
    ReadTask640(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c200 = _t[0];
        u64 v_c136 = _t[1];
        slog::join_probe<1,1>(primitiveindex637, std::array<u64,1>{v_c136}, [&](const std::array<u64,1>& m647) {
          slog::join_probe_old<4,1>(evalindex638, evaldelta639, std::array<u64,4>{v_c200, 0, 0, 0}, [&](const std::array<u64,4>& m648) {
            u64 v_c26 = m648[1]; u64 v_c27 = m648[2]; u64 v_c201 = m648[3];
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c201, v_c136});
            slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c136}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:35", "delta:primref", _fires);
  
      if (!_done)
      {
        ReadTask640* _cont = new ReadTask640(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask640(db,b), false);
  // (crule (pre) (scan lambda __t20Nd613 xs eb) (body (join-old closure (1 2 0) 1 (1 2 0) __t20Nd613 rhoc __t6tRF614) (join eval_ans (1 0) 1 __t6tRF614 __t7lOb612) (join eval (0 1 2 3) 1 __t7lOb612 ef rho t) (exists app (1 2 0) 1 ef) (exists eval_args (3 2 0 1) 2 t rho) (exists tick (2 0 1) 1 t) (join eval (2 3 0 1) 2 rho t __3JBR1203 __t3MQm616) (exists tick (1 2 0) 2 __t3MQm616 t) (join-old app (0 1 2) 2 (0 1 2) __t3MQm616 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t192L615) (exists eval_args_ans (0 1) 1 __t192L615) (join-old tick (1 2 0) 2 (1 2 0) __t3MQm616 t __t2n7W617) (exists tick_ans (0 1) 1 __t2n7W617) (join eval_args_ans (0 1) 1 __t192L615 vs) (join tick_ans (0 1) 1 __t2n7W617 t2)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask668 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex649;  slog::Index** eval_ansindex650;  slog::Index** evalindex651;  slog::Index** appindex652;  slog::Index** eval_argsindex653;  slog::Index** tickindex654;  slog::Index** evalindex655;  slog::Index** tickindex656;  slog::Index** appindex657;  slog::Index** eval_argsindex658;  slog::Index** eval_args_ansindex659;  slog::Index** tickindex660;  slog::Index** tick_ansindex661;  slog::Index** eval_args_ansindex662;  slog::Index** tick_ansindex663;  slog::Index** closuredelta664;  slog::Index** appdelta665;  slog::Index** eval_argsdelta666;  slog::Index** tickdelta667;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord669({0, 1, 2, 3});
      slog::Relation* readrel670 = db->getRelation("bind_store");
      head_index[0] = readrel670->getIndex(ord669, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord671({0, 1});
      slog::Relation* readrel672 = db->getRelation("call_event");
      head_index[1] = readrel672->getIndex(ord671, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord673({1, 2, 0});
      slog::Relation* readrel674 = db->getRelation("closure");
      closureindex649 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({1, 2, 0});
      slog::Relation* readrel676 = db->getRelation("closure");
      closuredelta664 = readrel676->getIndex(ord675, true);
      std::vector<u16> ord677({1, 0});
      slog::Relation* readrel678 = db->getRelation("eval_ans");
      eval_ansindex650 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({0, 1, 2, 3});
      slog::Relation* readrel680 = db->getRelation("eval");
      evalindex651 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({1, 2, 0});
      slog::Relation* readrel682 = db->getRelation("app");
      appindex652 = readrel682->getIndex(ord681, false);
      std::vector<u16> ord683({3, 2, 0, 1});
      slog::Relation* readrel684 = db->getRelation("eval_args");
      eval_argsindex653 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({2, 0, 1});
      slog::Relation* readrel686 = db->getRelation("tick");
      tickindex654 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({2, 3, 0, 1});
      slog::Relation* readrel688 = db->getRelation("eval");
      evalindex655 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 0});
      slog::Relation* readrel690 = db->getRelation("tick");
      tickindex656 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({0, 1, 2});
      slog::Relation* readrel692 = db->getRelation("app");
      appindex657 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({0, 1, 2});
      slog::Relation* readrel694 = db->getRelation("app");
      appdelta665 = readrel694->getIndex(ord693, true);
      std::vector<u16> ord695({1, 3, 2, 0});
      slog::Relation* readrel696 = db->getRelation("eval_args");
      eval_argsindex658 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({1, 3, 2, 0});
      slog::Relation* readrel698 = db->getRelation("eval_args");
      eval_argsdelta666 = readrel698->getIndex(ord697, true);
      std::vector<u16> ord699({0, 1});
      slog::Relation* readrel700 = db->getRelation("eval_args_ans");
      eval_args_ansindex659 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 0});
      slog::Relation* readrel702 = db->getRelation("tick");
      tickindex660 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 2, 0});
      slog::Relation* readrel704 = db->getRelation("tick");
      tickdelta667 = readrel704->getIndex(ord703, true);
      std::vector<u16> ord705({0, 1});
      slog::Relation* readrel706 = db->getRelation("tick_ans");
      tick_ansindex661 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({0, 1});
      slog::Relation* readrel708 = db->getRelation("eval_args_ans");
      eval_args_ansindex662 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({0, 1});
      slog::Relation* readrel710 = db->getRelation("tick_ans");
      tick_ansindex663 = readrel710->getIndex(ord709, false);
  
    }
    ReadTask668(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c202 = _t[0];
        u64 v_c151 = _t[1];
        u64 v_c31 = _t[2];
        slog::join_probe_old<3,1>(closureindex649, closuredelta664, std::array<u64,3>{v_c202, 0, 0}, [&](const std::array<u64,3>& m711) {
          u64 v_c203 = m711[1]; u64 v_c204 = m711[2];
          slog::join_probe<2,1>(eval_ansindex650, std::array<u64,2>{v_c204, 0}, [&](const std::array<u64,2>& m712) {
            u64 v_c205 = m712[1];
            slog::join_probe<4,1>(evalindex651, std::array<u64,4>{v_c205, 0, 0, 0}, [&](const std::array<u64,4>& m713) {
              u64 v_c206 = m713[1]; u64 v_c26 = m713[2]; u64 v_c27 = m713[3];
              if (!slog::exists_probe<3,1>(appindex652, std::array<u64,3>{v_c206, 0, 0})) return;
              if (!slog::exists_probe<4,2>(eval_argsindex653, std::array<u64,4>{v_c27, v_c26, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex654, std::array<u64,3>{v_c27, 0, 0})) return;
              slog::join_probe<4,2>(evalindex655, std::array<u64,4>{v_c26, v_c27, 0, 0}, [&](const std::array<u64,4>& m714) {
                u64 v_c207 = m714[2]; u64 v_c208 = m714[3];
                if (!slog::exists_probe<3,2>(tickindex656, std::array<u64,3>{v_c208, v_c27, 0})) return;
                slog::join_probe_old<3,2>(appindex657, appdelta665, std::array<u64,3>{v_c208, v_c206, 0}, [&](const std::array<u64,3>& m715) {
                  u64 v_c209 = m715[2];
                  slog::join_probe_old<4,3>(eval_argsindex658, eval_argsdelta666, std::array<u64,4>{v_c209, v_c27, v_c26, 0}, [&](const std::array<u64,4>& m716) {
                    u64 v_c210 = m716[3];
                    if (!slog::exists_probe<2,1>(eval_args_ansindex659, std::array<u64,2>{v_c210, 0})) return;
                    slog::join_probe_old<3,2>(tickindex660, tickdelta667, std::array<u64,3>{v_c208, v_c27, 0}, [&](const std::array<u64,3>& m717) {
                      u64 v_c211 = m717[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex661, std::array<u64,2>{v_c211, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex662, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m718) {
                        u64 v_c212 = m718[1];
                        slog::join_probe<2,1>(tick_ansindex663, std::array<u64,2>{v_c211, 0}, [&](const std::array<u64,2>& m719) {
                          u64 v_c213 = m719[1];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c151, v_c212, v_c213, v_c27}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c213, v_c27}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask668* _cont = new ReadTask668(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask668(db,b), false);
  // (crule (pre) (scan app __t3MQm616 ef es) (body (exists eval (1 2 3 0) 1 __t3MQm616) (exists eval (1 2 3 0) 1 ef) (exists eval_args (1 3 2 0) 1 es) (join-old tick (1 2 0) 1 (1 2 0) __t3MQm616 t __t2n7W617) (exists eval (3 1 0 2) 2 t ef) (exists eval_args (1 3 2 0) 2 es t) (exists tick_ans (0 1) 1 __t2n7W617) (join eval (3 1 0 2) 2 t __t3MQm616 __3JBR1203 rho) (exists eval_args (1 3 2 0) 3 es t rho) (join eval (1 2 3 0) 3 ef rho t __t7lOb612) (exists eval_ans (0 1) 1 __t7lOb612) (join eval_args (1 3 2 0) 3 es t rho __t192L615) (exists eval_args_ans (0 1) 1 __t192L615) (join eval_ans (0 1) 1 __t7lOb612 __t6tRF614) (join eval_args_ans (0 1) 1 __t192L615 vs) (join tick_ans (0 1) 1 __t2n7W617 t2) (join closure (0 1 2) 1 __t6tRF614 __t20Nd613 rhoc) (join lambda (0 1 2) 1 __t20Nd613 xs eb)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask739 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex720;  slog::Index** evalindex721;  slog::Index** eval_argsindex722;  slog::Index** tickindex723;  slog::Index** evalindex724;  slog::Index** eval_argsindex725;  slog::Index** tick_ansindex726;  slog::Index** evalindex727;  slog::Index** eval_argsindex728;  slog::Index** evalindex729;  slog::Index** eval_ansindex730;  slog::Index** eval_argsindex731;  slog::Index** eval_args_ansindex732;  slog::Index** eval_ansindex733;  slog::Index** eval_args_ansindex734;  slog::Index** tick_ansindex735;  slog::Index** closureindex736;  slog::Index** lambdaindex737;  slog::Index** tickdelta738;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord740({0, 1, 2, 3});
      slog::Relation* readrel741 = db->getRelation("bind_store");
      head_index[0] = readrel741->getIndex(ord740, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord742({0, 1});
      slog::Relation* readrel743 = db->getRelation("call_event");
      head_index[1] = readrel743->getIndex(ord742, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord744({1, 2, 3, 0});
      slog::Relation* readrel745 = db->getRelation("eval");
      evalindex720 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({1, 2, 3, 0});
      slog::Relation* readrel747 = db->getRelation("eval");
      evalindex721 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 3, 2, 0});
      slog::Relation* readrel749 = db->getRelation("eval_args");
      eval_argsindex722 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 0});
      slog::Relation* readrel751 = db->getRelation("tick");
      tickindex723 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 2, 0});
      slog::Relation* readrel753 = db->getRelation("tick");
      tickdelta738 = readrel753->getIndex(ord752, true);
      std::vector<u16> ord754({3, 1, 0, 2});
      slog::Relation* readrel755 = db->getRelation("eval");
      evalindex724 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 3, 2, 0});
      slog::Relation* readrel757 = db->getRelation("eval_args");
      eval_argsindex725 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({0, 1});
      slog::Relation* readrel759 = db->getRelation("tick_ans");
      tick_ansindex726 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({3, 1, 0, 2});
      slog::Relation* readrel761 = db->getRelation("eval");
      evalindex727 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 3, 2, 0});
      slog::Relation* readrel763 = db->getRelation("eval_args");
      eval_argsindex728 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 2, 3, 0});
      slog::Relation* readrel765 = db->getRelation("eval");
      evalindex729 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({0, 1});
      slog::Relation* readrel767 = db->getRelation("eval_ans");
      eval_ansindex730 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 3, 2, 0});
      slog::Relation* readrel769 = db->getRelation("eval_args");
      eval_argsindex731 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({0, 1});
      slog::Relation* readrel771 = db->getRelation("eval_args_ans");
      eval_args_ansindex732 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({0, 1});
      slog::Relation* readrel773 = db->getRelation("eval_ans");
      eval_ansindex733 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({0, 1});
      slog::Relation* readrel775 = db->getRelation("eval_args_ans");
      eval_args_ansindex734 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({0, 1});
      slog::Relation* readrel777 = db->getRelation("tick_ans");
      tick_ansindex735 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({0, 1, 2});
      slog::Relation* readrel779 = db->getRelation("closure");
      closureindex736 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({0, 1, 2});
      slog::Relation* readrel781 = db->getRelation("lambda");
      lambdaindex737 = readrel781->getIndex(ord780, false);
  
    }
    ReadTask739(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c208 = _t[0];
        u64 v_c206 = _t[1];
        u64 v_c209 = _t[2];
        if (!slog::exists_probe<4,1>(evalindex720, std::array<u64,4>{v_c208, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex721, std::array<u64,4>{v_c206, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(eval_argsindex722, std::array<u64,4>{v_c209, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(tickindex723, tickdelta738, std::array<u64,3>{v_c208, 0, 0}, [&](const std::array<u64,3>& m782) {
          u64 v_c27 = m782[1]; u64 v_c211 = m782[2];
          if (!slog::exists_probe<4,2>(evalindex724, std::array<u64,4>{v_c27, v_c206, 0, 0})) return;
          if (!slog::exists_probe<4,2>(eval_argsindex725, std::array<u64,4>{v_c209, v_c27, 0, 0})) return;
          if (!slog::exists_probe<2,1>(tick_ansindex726, std::array<u64,2>{v_c211, 0})) return;
          slog::join_probe<4,2>(evalindex727, std::array<u64,4>{v_c27, v_c208, 0, 0}, [&](const std::array<u64,4>& m783) {
            u64 v_c207 = m783[2]; u64 v_c26 = m783[3];
            if (!slog::exists_probe<4,3>(eval_argsindex728, std::array<u64,4>{v_c209, v_c27, v_c26, 0})) return;
            slog::join_probe<4,3>(evalindex729, std::array<u64,4>{v_c206, v_c26, v_c27, 0}, [&](const std::array<u64,4>& m784) {
              u64 v_c205 = m784[3];
              if (!slog::exists_probe<2,1>(eval_ansindex730, std::array<u64,2>{v_c205, 0})) return;
              slog::join_probe<4,3>(eval_argsindex731, std::array<u64,4>{v_c209, v_c27, v_c26, 0}, [&](const std::array<u64,4>& m785) {
                u64 v_c210 = m785[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex732, std::array<u64,2>{v_c210, 0})) return;
                slog::join_probe<2,1>(eval_ansindex733, std::array<u64,2>{v_c205, 0}, [&](const std::array<u64,2>& m786) {
                  u64 v_c204 = m786[1];
                  slog::join_probe<2,1>(eval_args_ansindex734, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m787) {
                    u64 v_c212 = m787[1];
                    slog::join_probe<2,1>(tick_ansindex735, std::array<u64,2>{v_c211, 0}, [&](const std::array<u64,2>& m788) {
                      u64 v_c213 = m788[1];
                      slog::join_probe<3,1>(closureindex736, std::array<u64,3>{v_c204, 0, 0}, [&](const std::array<u64,3>& m789) {
                        u64 v_c202 = m789[1]; u64 v_c203 = m789[2];
                        slog::join_probe<3,1>(lambdaindex737, std::array<u64,3>{v_c202, 0, 0}, [&](const std::array<u64,3>& m790) {
                          u64 v_c151 = m790[1]; u64 v_c31 = m790[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c151, v_c212, v_c213, v_c27}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c213, v_c27}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask739* _cont = new ReadTask739(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask739(db,b), false);
  // (crule (pre (let __tconst0xOc223 const5feceb66ffc86f38d952786c)) (scan $sup5638x98x0x0x0 __t14N0222 l m n p q r u v) (body (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk (1 2 0) 2 q m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 1 r) (join-old $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 (7 2 3 5 0 4 6 8 9 1) r l m p __t14N0222 n q u v __t4NVE225) (exists mp_msk (1 2 0) 3 q m __t4NVE225) (exists mp_msk_ans (0 1) 2 __t4NVE225 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t006N221) (exists mp_union (0 1 2) 2 __t14N0222 __t006N221) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t5FeR226) (join-old mp_union (0 1 2) 3 (0 1 2) __t14N0222 __t006N221 __t5FeR226) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t4NVE225) (join mp_msk_ans (0 1) 2 __t4NVE225 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t5FeR226 __t6Lp3227) (join mp_union_ans (0 1) 1 __t6Lp3227 __v0) (let __t91c5224 (band q m)) (cmp gt __t91c5224 __tconst0xOc223)) (head (emit-temp temp0Tjz1856 __t14N0222 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t1O3D219 p m l __v0)) map.slog:99 #f)
  class ReadTask813 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex791;  slog::Index** mbranchindex792;  slog::Index** mp_mskindex793;  slog::Index** mp_msk_ansindex794;  slog::Index** mp_unionindex795;  slog::Index** $sup5638x98x0x0x1index796;  slog::Index** mp_mskindex797;  slog::Index** mp_msk_ansindex798;  slog::Index** mbranchindex799;  slog::Index** mp_unionindex800;  slog::Index** mbranchindex801;  slog::Index** mp_unionindex802;  slog::Index** mp_mskindex803;  slog::Index** mp_msk_ansindex804;  slog::Index** mp_unionindex805;  slog::Index** mp_union_ansindex806;  slog::Index** $sup5638x98x0x0x1delta807;  slog::Index** mbranchdelta808;  slog::Index** mbranchdelta809;  slog::Index** mp_uniondelta810;  slog::Index** mp_mskdelta811;  slog::Index** mp_uniondelta812;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Tjz1856");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord814({1, 2, 3, 4, 0});
      slog::Relation* readrel815 = db->getRelation("mbranch");
      mbranchindex791 = readrel815->getIndex(ord814, false);
      std::vector<u16> ord816({1, 2, 3, 4, 0});
      slog::Relation* readrel817 = db->getRelation("mbranch");
      mbranchindex792 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({1, 2, 0});
      slog::Relation* readrel819 = db->getRelation("mp_msk");
      mp_mskindex793 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 0});
      slog::Relation* readrel821 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex794 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 2, 0});
      slog::Relation* readrel823 = db->getRelation("mp_union");
      mp_unionindex795 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel825 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index796 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel827 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1delta807 = readrel827->getIndex(ord826, true);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("mp_msk");
      mp_mskindex797 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({0, 1});
      slog::Relation* readrel831 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex798 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 3, 4, 0});
      slog::Relation* readrel833 = db->getRelation("mbranch");
      mbranchindex799 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({1, 2, 3, 4, 0});
      slog::Relation* readrel835 = db->getRelation("mbranch");
      mbranchdelta808 = readrel835->getIndex(ord834, true);
      std::vector<u16> ord836({0, 1, 2});
      slog::Relation* readrel837 = db->getRelation("mp_union");
      mp_unionindex800 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 2, 3, 4, 0});
      slog::Relation* readrel839 = db->getRelation("mbranch");
      mbranchindex801 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({1, 2, 3, 4, 0});
      slog::Relation* readrel841 = db->getRelation("mbranch");
      mbranchdelta809 = readrel841->getIndex(ord840, true);
      std::vector<u16> ord842({0, 1, 2});
      slog::Relation* readrel843 = db->getRelation("mp_union");
      mp_unionindex802 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({0, 1, 2});
      slog::Relation* readrel845 = db->getRelation("mp_union");
      mp_uniondelta810 = readrel845->getIndex(ord844, true);
      std::vector<u16> ord846({1, 2, 0});
      slog::Relation* readrel847 = db->getRelation("mp_msk");
      mp_mskindex803 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({1, 2, 0});
      slog::Relation* readrel849 = db->getRelation("mp_msk");
      mp_mskdelta811 = readrel849->getIndex(ord848, true);
      std::vector<u16> ord850({0, 1});
      slog::Relation* readrel851 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex804 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({1, 2, 0});
      slog::Relation* readrel853 = db->getRelation("mp_union");
      mp_unionindex805 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({1, 2, 0});
      slog::Relation* readrel855 = db->getRelation("mp_union");
      mp_uniondelta812 = readrel855->getIndex(ord854, true);
      std::vector<u16> ord856({0, 1});
      slog::Relation* readrel857 = db->getRelation("mp_union_ans");
      mp_union_ansindex806 = readrel857->getIndex(ord856, false);
  
    }
    ReadTask813(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c214 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c215 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c78 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c79 = _t[5];
        u64 v_c16 = _t[6];
        u64 v_c80 = _t[7];
        u64 v_c81 = _t[8];
        u64 v_c216 = _prim_lt(db, v_c78, v_c14);
        if (v_c216 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
        if (!v_c216) return;
        if (!slog::exists_probe<5,4>(mbranchindex791, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, 0})) return;
        if (!slog::exists_probe<5,4>(mbranchindex792, std::array<u64,5>{v_c79, v_c78, v_c80, v_c81, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex793, std::array<u64,3>{v_c79, v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex794, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex795, std::array<u64,3>{v_c16, 0, 0})) return;
        slog::join_probe_old<10,9>($sup5638x98x0x0x1index796, $sup5638x98x0x0x1delta807, std::array<u64,10>{v_c16, v_c13, v_c14, v_c15, v_c215, v_c78, v_c79, v_c80, v_c81, 0}, [&](const std::array<u64,10>& m859) {
          u64 v_c217 = m859[9];
          if (!slog::exists_probe<3,3>(mp_mskindex797, std::array<u64,3>{v_c79, v_c14, v_c217})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex798, std::array<u64,2>{v_c217, v_c15})) return;
          slog::join_probe_old<5,4>(mbranchindex799, mbranchdelta808, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, 0}, [&](const std::array<u64,5>& m860) {
            u64 v_c218 = m860[4];
            if (!slog::exists_probe<3,2>(mp_unionindex800, std::array<u64,3>{v_c215, v_c218, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex801, mbranchdelta809, std::array<u64,5>{v_c79, v_c78, v_c80, v_c81, 0}, [&](const std::array<u64,5>& m861) {
              u64 v_c219 = m861[4];
              slog::join_probe_old<3,3>(mp_unionindex802, mp_uniondelta810, std::array<u64,3>{v_c215, v_c218, v_c219}, [&](const std::array<u64,3>& m862) {
                slog::join_probe_old<3,3>(mp_mskindex803, mp_mskdelta811, std::array<u64,3>{v_c79, v_c14, v_c217}, [&](const std::array<u64,3>& m863) {
                  slog::join_probe<2,2>(mp_msk_ansindex804, std::array<u64,2>{v_c217, v_c15}, [&](const std::array<u64,2>& m864) {
                    slog::join_probe_old<3,2>(mp_unionindex805, mp_uniondelta812, std::array<u64,3>{v_c16, v_c219, 0}, [&](const std::array<u64,3>& m865) {
                      u64 v_c220 = m865[2];
                      slog::join_probe<2,1>(mp_union_ansindex806, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m866) {
                        u64 v_c92 = m866[1];
                        u64 v_c221 = _prim_band(db, v_c79, v_c14);
                        if (v_c221 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c222 = _prim_gt(db, v_c221, v_c214);
                        if (v_c222 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c222) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c215, v_c92, v_c13, v_c14, v_c15});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c14, v_c13, v_c92}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:$sup5638x98x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask813* _cont = new ReadTask813(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask813(db,b), false);
  // (crule (pre) (scan mp_del __t5Y7y396 __t8pu9395 k) (body (exists mp_msk (1 2 0) 1 k) (join $sup5638x81x0x0x0 (0 1 2 3 4 5) 2 __t5Y7y396 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t8pu9395) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t0MS8397) (join mp_msk_ans (0 1) 1 __t0MS8397 __v0) (neq p __v0)) (head (emit mp_del_ans (0 1) __t5Y7y396 __t8pu9395)) map.slog:82 #f)
  class ReadTask874 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex868;  slog::Index** $sup5638x81x0x0x0index869;  slog::Index** mbranchindex870;  slog::Index** mp_mskindex871;  slog::Index** mp_msk_ansindex872;  slog::Index** mp_mskdelta873;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord875({0, 1});
      slog::Relation* readrel876 = db->getRelation("mp_del_ans");
      head_index[0] = readrel876->getIndex(ord875, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord877({1, 2, 0});
      slog::Relation* readrel878 = db->getRelation("mp_msk");
      mp_mskindex868 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel880 = db->getRelation("$sup5638x81x0x0x0");
      $sup5638x81x0x0x0index869 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 3, 4, 0});
      slog::Relation* readrel882 = db->getRelation("mbranch");
      mbranchindex870 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 2, 0});
      slog::Relation* readrel884 = db->getRelation("mp_msk");
      mp_mskindex871 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 2, 0});
      slog::Relation* readrel886 = db->getRelation("mp_msk");
      mp_mskdelta873 = readrel886->getIndex(ord885, true);
      std::vector<u16> ord887({0, 1});
      slog::Relation* readrel888 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex872 = readrel888->getIndex(ord887, false);
  
    }
    ReadTask874(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c223 = _t[0];
        u64 v_c224 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<3,1>(mp_mskindex868, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x81x0x0x0index869, std::array<u64,6>{v_c223, v_c12, 0, 0, 0, 0}, [&](const std::array<u64,6>& m889) {
          u64 v_c13 = m889[2]; u64 v_c14 = m889[3]; u64 v_c15 = m889[4]; u64 v_c16 = m889[5];
          slog::join_probe<5,5>(mbranchindex870, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, v_c224}, [&](const std::array<u64,5>& m890) {
            slog::join_probe_old<3,2>(mp_mskindex871, mp_mskdelta873, std::array<u64,3>{v_c12, v_c14, 0}, [&](const std::array<u64,3>& m891) {
              u64 v_c225 = m891[2];
              slog::join_probe<2,1>(mp_msk_ansindex872, std::array<u64,2>{v_c225, 0}, [&](const std::array<u64,2>& m892) {
                u64 v_c92 = m892[1];
                if (v_c15 == v_c92) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c223, v_c224}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask874* _cont = new ReadTask874(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask874(db,b), false);
  // (crule (pre) (scan temp6y8Y1938 __t2Q40639 __t8cgD644 __t8xy6642) (body (let __t6ckH643 (_0002a __t8xy6642 __t2Q40639))) (head (emit-temp temp9u0L1939 __t6ckH643 __t8cgD644)) map.slog:22 #f)
  class ReadTask893 : public slog::Task
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
      head_rel[0] = db->getRelation("temp9u0L1939");
      outer_rel = db->getRelation("temp6y8Y1938");
  
    }
    ReadTask893(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c226 = _t[0];
        u64 v_c227 = _t[1];
        u64 v_c228 = _t[2];
        u64 v_c229 = _prim__0002a(db, v_c228, v_c226);
        if (v_c229 == slog_error) { slog::emit_pending_error(db, "map.slog:22"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c229, v_c227});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:22", "delta:temp6y8Y1938", _fires);
  
      if (!_done)
      {
        ReadTask893* _cont = new ReadTask893(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask893(db,b), false);
  // (crule (pre (let __tconst49eD1184 constcd2a69ce5ca278db1d6da969) (let __tconst7GbT659 const06abaa100ecef791ce028c56) (let _00024sqc0jJd1013 constd4735e3a265e16eee03f5971) (let _00024sqc54us1014 const5feceb66ffc86f38d952786c) (let _00024sqc6uOX1015 const6b86b273ff34fce19d6b804e) (let _00024sqo8ZRa1016 const5feceb66ffc86f38d952786c) (let _00024sqo9lkw1017 const6b86b273ff34fce19d6b804e) (let _00024sqo8so11018 const6b86b273ff34fce19d6b804e) (let _00024sqo0qa11019 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo9lkw1017 __t013P662 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo8ZRa1016 __t013P662 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8so11018 __t013P662 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0qa11019 __t013P662 _00024seq2) (join _enum (0 1) 2 __t013P662 __tconst49eD1184) (join delta (1 2 0) 2 __tconst7GbT659 _00024seq2 __t6erK660) (join any_bool (0) 0 b) (letp _00024sql99Ol1011 (aslst _00024seq2)) (let chk7EfI1784 (llen _00024sql99Ol1011)) (eq _00024sqc0jJd1013 chk7EfI1784) (letp chk0ZaG1785 (lref _00024sql99Ol1011 _00024sqc54us1014)) (eq __t013P662 chk0ZaG1785) (letp chk3b8K1786 (lref _00024sql99Ol1011 _00024sqc6uOX1015)) (eq __t013P662 chk3b8K1786)) (head (emit-temp temp3q8l1778 __t6erK660 b) (mkstruct boolval (1 0) __t5eIx658 b)) interp.slog:125 #f)
  class ReadTask902 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex894;  slog::Index** $seq_atrindex895;  slog::Index** $seq_atrindex896;  slog::Index** _enumindex897;  slog::Index** deltaindex898;  slog::Index** any_boolindex899;  slog::Index** $seq_atrdelta900;  slog::Index** $seq_atrdelta901;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3q8l1778");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord903({1, 0, 2});
      slog::Relation* readrel904 = db->getRelation("$seq_at");
      driver_index = readrel904->getIndex(ord903, true);
      std::vector<u16> ord905({1, 0, 2});
      slog::Relation* readrel906 = db->getRelation("$seq_at");
      $seq_atindex894 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({1, 0, 2});
      slog::Relation* readrel908 = db->getRelation("$seq_atr");
      $seq_atrindex895 = readrel908->getIndex(ord907, false);
      std::vector<u16> ord909({1, 0, 2});
      slog::Relation* readrel910 = db->getRelation("$seq_atr");
      $seq_atrdelta900 = readrel910->getIndex(ord909, true);
      std::vector<u16> ord911({1, 0, 2});
      slog::Relation* readrel912 = db->getRelation("$seq_atr");
      $seq_atrindex896 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({1, 0, 2});
      slog::Relation* readrel914 = db->getRelation("$seq_atr");
      $seq_atrdelta901 = readrel914->getIndex(ord913, true);
      std::vector<u16> ord915({0, 1});
      slog::Relation* readrel916 = db->getRelation("_enum");
      _enumindex897 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({1, 2, 0});
      slog::Relation* readrel918 = db->getRelation("delta");
      deltaindex898 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({0});
      slog::Relation* readrel920 = db->getRelation("any_bool");
      any_boolindex899 = readrel920->getIndex(ord919, false);
  
    }
    ReadTask902(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c230 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c231 = v_const06abaa100ecef791ce028c56;
      u64 v_c232 = v_constd4735e3a265e16eee03f5971;
      u64 v_c233 = v_const5feceb66ffc86f38d952786c;
      u64 v_c234 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c235 = v_const5feceb66ffc86f38d952786c;
      u64 v_c236 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c237 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c238 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c236, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m921) {
        u64 v_c239 = m921[1];
        u64 v_c134 = m921[2];
        if (buckethash(v_c239) != bucket) return;
        slog::join_probe<3,3>($seq_atindex894, std::array<u64,3>{v_c235, v_c239, v_c134}, [&](const std::array<u64,3>& m922) {
          slog::join_probe_old<3,3>($seq_atrindex895, $seq_atrdelta900, std::array<u64,3>{v_c237, v_c239, v_c134}, [&](const std::array<u64,3>& m923) {
            slog::join_probe_old<3,3>($seq_atrindex896, $seq_atrdelta901, std::array<u64,3>{v_c238, v_c239, v_c134}, [&](const std::array<u64,3>& m924) {
              slog::join_probe<2,2>(_enumindex897, std::array<u64,2>{v_c239, v_c230}, [&](const std::array<u64,2>& m925) {
                slog::join_probe<3,2>(deltaindex898, std::array<u64,3>{v_c231, v_c134, 0}, [&](const std::array<u64,3>& m926) {
                  u64 v_c240 = m926[2];
                  slog::join_all<1>(any_boolindex899, [&](const std::array<u64,1>& m927) {
                    u64 v_c137 = m927[0];
                    bool ok928 = true;
                    u64 v_c241 = _prim_aslst(db, v_c134, &ok928);
                    if (!ok928) return;
                    u64 v_c242 = _prim_llen(db, v_c241);
                    if (v_c242 == slog_error) { slog::emit_pending_error(db, "interp.slog:125"); return; }
                    if (v_c232 != v_c242) return;
                    bool ok929 = true;
                    u64 v_c243 = _prim_lref(db, v_c241, v_c233, &ok929);
                    if (!ok929) return;
                    if (v_c239 != v_c243) return;
                    bool ok930 = true;
                    u64 v_c244 = _prim_lref(db, v_c241, v_c234, &ok930);
                    if (!ok930) return;
                    if (v_c239 != v_c244) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c240, v_c137});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c137}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:125", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask902* _cont = new ReadTask902(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask902(db,b), false);
  // (crule (pre (let __tconst70WV799 const5feceb66ffc86f38d952786c)) (scan mp_del __t2paO798 __t29Nf797 k) (body (exists mp_msk (1 2 0) 1 k) (exists mp_del (2 0 1) 1 k) (join $sup5638x84x0x0x0 (0 1 2 3 4 5) 2 __t2paO798 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t29Nf797) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 r k) (join-old mp_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t2Csk801) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t2Csk801) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4hJg802) (join mp_msk_ans (0 1) 2 __t4hJg802 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t1FSo803) (join mp_del_ans (0 1) 2 __t1FSo803 __v0) (join mp_bld_ans (0 1) 1 __t2Csk801 res) (let __t1QoP800 (band k m)) (cmp gt __t1QoP800 __tconst70WV799)) (head (emit mp_del_ans (0 1) __t2paO798 res)) map.slog:85 #f)
  class ReadTask949 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex931;  slog::Index** mp_delindex932;  slog::Index** $sup5638x84x0x0x0index933;  slog::Index** mbranchindex934;  slog::Index** mp_mskindex935;  slog::Index** mp_msk_ansindex936;  slog::Index** mp_delindex937;  slog::Index** mp_bldindex938;  slog::Index** mp_del_ansindex939;  slog::Index** mp_bld_ansindex940;  slog::Index** mp_mskindex941;  slog::Index** mp_msk_ansindex942;  slog::Index** mp_delindex943;  slog::Index** mp_del_ansindex944;  slog::Index** mp_bld_ansindex945;  slog::Index** mp_blddelta946;  slog::Index** mp_mskdelta947;  slog::Index** mp_deldelta948;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord950({0, 1});
      slog::Relation* readrel951 = db->getRelation("mp_del_ans");
      head_index[0] = readrel951->getIndex(ord950, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord952({1, 2, 0});
      slog::Relation* readrel953 = db->getRelation("mp_msk");
      mp_mskindex931 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({2, 0, 1});
      slog::Relation* readrel955 = db->getRelation("mp_del");
      mp_delindex932 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel957 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index933 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({1, 2, 3, 4, 0});
      slog::Relation* readrel959 = db->getRelation("mbranch");
      mbranchindex934 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({1, 2, 0});
      slog::Relation* readrel961 = db->getRelation("mp_msk");
      mp_mskindex935 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({1, 0});
      slog::Relation* readrel963 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex936 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({1, 2, 0});
      slog::Relation* readrel965 = db->getRelation("mp_del");
      mp_delindex937 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({1, 2, 3, 4, 0});
      slog::Relation* readrel967 = db->getRelation("mp_bld");
      mp_bldindex938 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({1, 2, 3, 4, 0});
      slog::Relation* readrel969 = db->getRelation("mp_bld");
      mp_blddelta946 = readrel969->getIndex(ord968, true);
      std::vector<u16> ord970({1, 0});
      slog::Relation* readrel971 = db->getRelation("mp_del_ans");
      mp_del_ansindex939 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({0, 1});
      slog::Relation* readrel973 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex940 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 2, 0});
      slog::Relation* readrel975 = db->getRelation("mp_msk");
      mp_mskindex941 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({1, 2, 0});
      slog::Relation* readrel977 = db->getRelation("mp_msk");
      mp_mskdelta947 = readrel977->getIndex(ord976, true);
      std::vector<u16> ord978({0, 1});
      slog::Relation* readrel979 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex942 = readrel979->getIndex(ord978, false);
      std::vector<u16> ord980({1, 2, 0});
      slog::Relation* readrel981 = db->getRelation("mp_del");
      mp_delindex943 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({1, 2, 0});
      slog::Relation* readrel983 = db->getRelation("mp_del");
      mp_deldelta948 = readrel983->getIndex(ord982, true);
      std::vector<u16> ord984({0, 1});
      slog::Relation* readrel985 = db->getRelation("mp_del_ans");
      mp_del_ansindex944 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({0, 1});
      slog::Relation* readrel987 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex945 = readrel987->getIndex(ord986, false);
  
    }
    ReadTask949(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c245 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c246 = _t[0];
        u64 v_c247 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<3,1>(mp_mskindex931, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex932, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x84x0x0x0index933, std::array<u64,6>{v_c246, v_c12, 0, 0, 0, 0}, [&](const std::array<u64,6>& m988) {
          u64 v_c13 = m988[2]; u64 v_c14 = m988[3]; u64 v_c15 = m988[4]; u64 v_c16 = m988[5];
          slog::join_probe<5,5>(mbranchindex934, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, v_c247}, [&](const std::array<u64,5>& m989) {
            if (!slog::exists_probe<3,2>(mp_mskindex935, std::array<u64,3>{v_c12, v_c14, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex936, std::array<u64,2>{v_c15, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex937, std::array<u64,3>{v_c16, v_c12, 0})) return;
            slog::join_probe_old<5,3>(mp_bldindex938, mp_blddelta946, std::array<u64,5>{v_c15, v_c14, v_c13, 0, 0}, [&](const std::array<u64,5>& m990) {
              u64 v_c92 = m990[3]; u64 v_c248 = m990[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex939, std::array<u64,2>{v_c92, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex940, std::array<u64,2>{v_c248, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex941, mp_mskdelta947, std::array<u64,3>{v_c12, v_c14, 0}, [&](const std::array<u64,3>& m991) {
                u64 v_c249 = m991[2];
                slog::join_probe<2,2>(mp_msk_ansindex942, std::array<u64,2>{v_c249, v_c15}, [&](const std::array<u64,2>& m992) {
                  slog::join_probe_old<3,2>(mp_delindex943, mp_deldelta948, std::array<u64,3>{v_c16, v_c12, 0}, [&](const std::array<u64,3>& m993) {
                    u64 v_c250 = m993[2];
                    slog::join_probe<2,2>(mp_del_ansindex944, std::array<u64,2>{v_c250, v_c92}, [&](const std::array<u64,2>& m994) {
                      slog::join_probe<2,1>(mp_bld_ansindex945, std::array<u64,2>{v_c248, 0}, [&](const std::array<u64,2>& m995) {
                        u64 v_c95 = m995[1];
                        u64 v_c251 = _prim_band(db, v_c12, v_c14);
                        if (v_c251 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c252 = _prim_gt(db, v_c251, v_c245);
                        if (v_c252 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c252) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c246, v_c95}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask949* _cont = new ReadTask949(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask949(db,b), false);
  // (crule (pre) (scan mbranch __t6AX6390 p m l r) (body (exists mp_join (1 2 3 4 0) 2 p __t6AX6390) (exists mp_union (1 2 0) 1 __t6AX6390) (exists mp_msk (1 2 0) 1 p) (join $sup5638x110x0x0x0 (1 2 4 6 7 3 0 5 8 9 10) 5 l m p r __t6AX6390 n __t5Qtl389 q __t46nL391 u v) (cmp lt m n) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t46nL391) (exists mp_union (0 1 2) 3 __t5Qtl389 __t6AX6390 __t46nL391) (exists mp_msk (1 2 0) 2 p n) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t6AX6390 q __t46nL391 __t6UVn392) (join mp_union (0 1 2) 3 __t5Qtl389 __t6AX6390 __t46nL391) (exists mp_join_ans (0 1) 1 __t6UVn392) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t827P393) (join mp_msk_ans (0 1) 1 __t827P393 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t6UVn392 res)) (head (emit mp_union_ans (0 1) __t5Qtl389 res)) map.slog:111 #f)
  class ReadTask1013 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex997;  slog::Index** mp_unionindex998;  slog::Index** mp_mskindex999;  slog::Index** $sup5638x110x0x0x0index1000;  slog::Index** mbranchindex1001;  slog::Index** mp_unionindex1002;  slog::Index** mp_mskindex1003;  slog::Index** mp_joinindex1004;  slog::Index** mp_unionindex1005;  slog::Index** mp_join_ansindex1006;  slog::Index** mp_mskindex1007;  slog::Index** mp_msk_ansindex1008;  slog::Index** mp_join_ansindex1009;  slog::Index** mbranchdelta1010;  slog::Index** mp_joindelta1011;  slog::Index** mp_mskdelta1012;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1014({0, 1});
      slog::Relation* readrel1015 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1015->getIndex(ord1014, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1016({1, 2, 3, 4, 0});
      slog::Relation* readrel1017 = db->getRelation("mp_join");
      mp_joinindex997 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 2, 0});
      slog::Relation* readrel1019 = db->getRelation("mp_union");
      mp_unionindex998 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({1, 2, 0});
      slog::Relation* readrel1021 = db->getRelation("mp_msk");
      mp_mskindex999 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel1023 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index1000 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({1, 2, 3, 4, 0});
      slog::Relation* readrel1025 = db->getRelation("mbranch");
      mbranchindex1001 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 2, 3, 4, 0});
      slog::Relation* readrel1027 = db->getRelation("mbranch");
      mbranchdelta1010 = readrel1027->getIndex(ord1026, true);
      std::vector<u16> ord1028({0, 1, 2});
      slog::Relation* readrel1029 = db->getRelation("mp_union");
      mp_unionindex1002 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 2, 0});
      slog::Relation* readrel1031 = db->getRelation("mp_msk");
      mp_mskindex1003 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({1, 2, 3, 4, 0});
      slog::Relation* readrel1033 = db->getRelation("mp_join");
      mp_joinindex1004 = readrel1033->getIndex(ord1032, false);
      std::vector<u16> ord1034({1, 2, 3, 4, 0});
      slog::Relation* readrel1035 = db->getRelation("mp_join");
      mp_joindelta1011 = readrel1035->getIndex(ord1034, true);
      std::vector<u16> ord1036({0, 1, 2});
      slog::Relation* readrel1037 = db->getRelation("mp_union");
      mp_unionindex1005 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({0, 1});
      slog::Relation* readrel1039 = db->getRelation("mp_join_ans");
      mp_join_ansindex1006 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({1, 2, 0});
      slog::Relation* readrel1041 = db->getRelation("mp_msk");
      mp_mskindex1007 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({1, 2, 0});
      slog::Relation* readrel1043 = db->getRelation("mp_msk");
      mp_mskdelta1012 = readrel1043->getIndex(ord1042, true);
      std::vector<u16> ord1044({0, 1});
      slog::Relation* readrel1045 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1008 = readrel1045->getIndex(ord1044, false);
      std::vector<u16> ord1046({0, 1});
      slog::Relation* readrel1047 = db->getRelation("mp_join_ans");
      mp_join_ansindex1009 = readrel1047->getIndex(ord1046, false);
  
    }
    ReadTask1013(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c253 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c16 = _t[4];
        if (!slog::exists_probe<5,2>(mp_joinindex997, std::array<u64,5>{v_c15, v_c253, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex998, std::array<u64,3>{v_c253, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex999, std::array<u64,3>{v_c15, 0, 0})) return;
        slog::join_probe<11,5>($sup5638x110x0x0x0index1000, std::array<u64,11>{v_c13, v_c14, v_c15, v_c16, v_c253, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1048) {
          u64 v_c78 = m1048[5]; u64 v_c254 = m1048[6]; u64 v_c79 = m1048[7]; u64 v_c255 = m1048[8]; u64 v_c80 = m1048[9]; u64 v_c81 = m1048[10];
          u64 v_c256 = _prim_lt(db, v_c14, v_c78);
          if (v_c256 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
          if (!v_c256) return;
          slog::join_probe_old<5,5>(mbranchindex1001, mbranchdelta1010, std::array<u64,5>{v_c79, v_c78, v_c80, v_c81, v_c255}, [&](const std::array<u64,5>& m1050) {
            if (!slog::exists_probe<3,3>(mp_unionindex1002, std::array<u64,3>{v_c254, v_c253, v_c255})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex1003, std::array<u64,3>{v_c15, v_c78, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex1004, mp_joindelta1011, std::array<u64,5>{v_c15, v_c253, v_c79, v_c255, 0}, [&](const std::array<u64,5>& m1051) {
              u64 v_c257 = m1051[4];
              slog::join_probe<3,3>(mp_unionindex1005, std::array<u64,3>{v_c254, v_c253, v_c255}, [&](const std::array<u64,3>& m1052) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex1006, std::array<u64,2>{v_c257, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex1007, mp_mskdelta1012, std::array<u64,3>{v_c15, v_c78, 0}, [&](const std::array<u64,3>& m1053) {
                  u64 v_c258 = m1053[2];
                  slog::join_probe<2,1>(mp_msk_ansindex1008, std::array<u64,2>{v_c258, 0}, [&](const std::array<u64,2>& m1054) {
                    u64 v_c92 = m1054[1];
                    if (v_c79 == v_c92) return;
                    slog::join_probe<2,1>(mp_join_ansindex1009, std::array<u64,2>{v_c257, 0}, [&](const std::array<u64,2>& m1055) {
                      u64 v_c95 = m1055[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c254, v_c95}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1013* _cont = new ReadTask1013(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1013(db,b), false);
  // (crule (pre (let __tconst70WV799 const5feceb66ffc86f38d952786c)) (scan mp_del __t1FSo803 r k) (body (exists $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_del (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join mp_del_ans (0 1) 1 __t1FSo803 __v0) (exists mp_bld (4 0 1 2 3) 1 __v0) (join $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r __t2paO798 l m p) (exists mp_bld (1 2 3 4 0) 4 p m l __v0) (exists mp_del (0 2 1) 2 __t2paO798 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join mbranch (1 2 3 4 0) 4 p m l r __t29Nf797) (exists mp_del (0 2 1) 3 __t2paO798 k __t29Nf797) (join mp_bld (1 2 3 4 0) 4 p m l __v0 __t2Csk801) (join mp_del (0 2 1) 3 __t2paO798 k __t29Nf797) (exists mp_bld_ans (0 1) 1 __t2Csk801) (join mp_msk (1 2 0) 2 k m __t4hJg802) (join mp_msk_ans (0 1) 2 __t4hJg802 p) (join mp_bld_ans (0 1) 1 __t2Csk801 res) (let __t1QoP800 (band k m)) (cmp gt __t1QoP800 __tconst70WV799)) (head (emit mp_del_ans (0 1) __t2paO798 res)) map.slog:85 #f)
  class ReadTask1075 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index1056;  slog::Index** mbranchindex1057;  slog::Index** mp_delindex1058;  slog::Index** mp_mskindex1059;  slog::Index** mp_del_ansindex1060;  slog::Index** mp_bldindex1061;  slog::Index** $sup5638x84x0x0x0index1062;  slog::Index** mp_bldindex1063;  slog::Index** mp_delindex1064;  slog::Index** mp_mskindex1065;  slog::Index** mp_msk_ansindex1066;  slog::Index** mbranchindex1067;  slog::Index** mp_delindex1068;  slog::Index** mp_bldindex1069;  slog::Index** mp_delindex1070;  slog::Index** mp_bld_ansindex1071;  slog::Index** mp_mskindex1072;  slog::Index** mp_msk_ansindex1073;  slog::Index** mp_bld_ansindex1074;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1076({0, 1});
      slog::Relation* readrel1077 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1077->getIndex(ord1076, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord1078({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel1079 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1056 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({4, 0, 1, 2, 3});
      slog::Relation* readrel1081 = db->getRelation("mbranch");
      mbranchindex1057 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({2, 0, 1});
      slog::Relation* readrel1083 = db->getRelation("mp_del");
      mp_delindex1058 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({1, 2, 0});
      slog::Relation* readrel1085 = db->getRelation("mp_msk");
      mp_mskindex1059 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({0, 1});
      slog::Relation* readrel1087 = db->getRelation("mp_del_ans");
      mp_del_ansindex1060 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({4, 0, 1, 2, 3});
      slog::Relation* readrel1089 = db->getRelation("mp_bld");
      mp_bldindex1061 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel1091 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1062 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({1, 2, 3, 4, 0});
      slog::Relation* readrel1093 = db->getRelation("mp_bld");
      mp_bldindex1063 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({0, 2, 1});
      slog::Relation* readrel1095 = db->getRelation("mp_del");
      mp_delindex1064 = readrel1095->getIndex(ord1094, false);
      std::vector<u16> ord1096({1, 2, 0});
      slog::Relation* readrel1097 = db->getRelation("mp_msk");
      mp_mskindex1065 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({1, 0});
      slog::Relation* readrel1099 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1066 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 2, 3, 4, 0});
      slog::Relation* readrel1101 = db->getRelation("mbranch");
      mbranchindex1067 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({0, 2, 1});
      slog::Relation* readrel1103 = db->getRelation("mp_del");
      mp_delindex1068 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({1, 2, 3, 4, 0});
      slog::Relation* readrel1105 = db->getRelation("mp_bld");
      mp_bldindex1069 = readrel1105->getIndex(ord1104, false);
      std::vector<u16> ord1106({0, 2, 1});
      slog::Relation* readrel1107 = db->getRelation("mp_del");
      mp_delindex1070 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({0, 1});
      slog::Relation* readrel1109 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1071 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({1, 2, 0});
      slog::Relation* readrel1111 = db->getRelation("mp_msk");
      mp_mskindex1072 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({0, 1});
      slog::Relation* readrel1113 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1073 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({0, 1});
      slog::Relation* readrel1115 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1074 = readrel1115->getIndex(ord1114, false);
  
    }
    ReadTask1075(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c245 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c250 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c12 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x84x0x0x0index1056, std::array<u64,6>{v_c12, v_c16, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1057, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex1058, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1059, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<2,1>(mp_del_ansindex1060, std::array<u64,2>{v_c250, 0}, [&](const std::array<u64,2>& m1116) {
          u64 v_c92 = m1116[1];
          if (!slog::exists_probe<5,1>(mp_bldindex1061, std::array<u64,5>{v_c92, 0, 0, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x84x0x0x0index1062, std::array<u64,6>{v_c12, v_c16, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1117) {
            u64 v_c246 = m1117[2]; u64 v_c13 = m1117[3]; u64 v_c14 = m1117[4]; u64 v_c15 = m1117[5];
            if (!slog::exists_probe<5,4>(mp_bldindex1063, std::array<u64,5>{v_c15, v_c14, v_c13, v_c92, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex1064, std::array<u64,3>{v_c246, v_c12, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex1065, std::array<u64,3>{v_c12, v_c14, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex1066, std::array<u64,2>{v_c15, 0})) return;
            slog::join_probe<5,4>(mbranchindex1067, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, 0}, [&](const std::array<u64,5>& m1118) {
              u64 v_c247 = m1118[4];
              if (!slog::exists_probe<3,3>(mp_delindex1068, std::array<u64,3>{v_c246, v_c12, v_c247})) return;
              slog::join_probe<5,4>(mp_bldindex1069, std::array<u64,5>{v_c15, v_c14, v_c13, v_c92, 0}, [&](const std::array<u64,5>& m1119) {
                u64 v_c248 = m1119[4];
                slog::join_probe<3,3>(mp_delindex1070, std::array<u64,3>{v_c246, v_c12, v_c247}, [&](const std::array<u64,3>& m1120) {
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex1071, std::array<u64,2>{v_c248, 0})) return;
                  slog::join_probe<3,2>(mp_mskindex1072, std::array<u64,3>{v_c12, v_c14, 0}, [&](const std::array<u64,3>& m1121) {
                    u64 v_c249 = m1121[2];
                    slog::join_probe<2,2>(mp_msk_ansindex1073, std::array<u64,2>{v_c249, v_c15}, [&](const std::array<u64,2>& m1122) {
                      slog::join_probe<2,1>(mp_bld_ansindex1074, std::array<u64,2>{v_c248, 0}, [&](const std::array<u64,2>& m1123) {
                        u64 v_c95 = m1123[1];
                        u64 v_c251 = _prim_band(db, v_c12, v_c14);
                        if (v_c251 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c259 = _prim_gt(db, v_c251, v_c245);
                        if (v_c259 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c259) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c246, v_c95}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask1075* _cont = new ReadTask1075(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1075(db,b), false);
  // (crule (pre (let __tconst7VkA464 constef2d127de37b942baad06145) (let __tconst3zaK478 const0933fb667296882d8c45abca) (let __tconst6GsZ491 consted725292f5f32d61535958c1) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e) (let __tconst8C9X496 const5feceb66ffc86f38d952786c) (let __tconst91JR503 const90fb9068eda6f2d68bb61c33) (let __tconst8eEZ507 const6f4b6612125fb3a0daecd279) (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4)) (scan temp4TYC2001 __t4qrC508) (body (exists num (1 0) 1 __tconst8C9X496) (exists primref (1 0) 1 __tconst6GsZ491) (exists primref (1 0) 1 __tconst3zaK478) (exists ref (1 0) 1 __tconst8eEZ507) (exists num (1 0) 1 __tconst0Ob1494) (exists ref (1 0) 1 __tconst2mJz511) (exists num (1 0) 1 __tconst7VkA464) (join primref (1 0) 1 __tconst91JR503 __t8Gth504) (join num (1 0) 1 __tconst8C9X496 __t8p4J497) (join primref (1 0) 1 __tconst6GsZ491 __t3x0f492) (join primref (1 0) 1 __tconst3zaK478 __t2abh479) (join ref (1 0) 1 __tconst8eEZ507 __t6w00474) (join num (1 0) 1 __tconst0Ob1494 __t1oVV472) (join ref (1 0) 1 __tconst2mJz511 __t1y5d469) (join num (1 0) 1 __tconst7VkA464 __t67Xh465) (let __t8A1z467 (lpush __t4qrC508 __t67Xh465)) (let __t3yjA501 (lpush __t4qrC508 __t6w00474)) (let __t0cTh509 (lpush __t4qrC508 __tconst8eEZ507))) (head (emit-temp temp7cao2002 __t0cTh509 __t3yjA501 __t4qrC508 __t8A1z467)) kcfa.slog:40 #f)
  class ReadTask1140 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex1125;  slog::Index** primrefindex1126;  slog::Index** primrefindex1127;  slog::Index** refindex1128;  slog::Index** numindex1129;  slog::Index** refindex1130;  slog::Index** numindex1131;  slog::Index** primrefindex1132;  slog::Index** numindex1133;  slog::Index** primrefindex1134;  slog::Index** primrefindex1135;  slog::Index** refindex1136;  slog::Index** numindex1137;  slog::Index** refindex1138;  slog::Index** numindex1139;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7cao2002");
      outer_rel = db->getRelation("temp4TYC2001");
      std::vector<u16> ord1141({1, 0});
      slog::Relation* readrel1142 = db->getRelation("num");
      numindex1125 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({1, 0});
      slog::Relation* readrel1144 = db->getRelation("primref");
      primrefindex1126 = readrel1144->getIndex(ord1143, false);
      std::vector<u16> ord1145({1, 0});
      slog::Relation* readrel1146 = db->getRelation("primref");
      primrefindex1127 = readrel1146->getIndex(ord1145, false);
      std::vector<u16> ord1147({1, 0});
      slog::Relation* readrel1148 = db->getRelation("ref");
      refindex1128 = readrel1148->getIndex(ord1147, false);
      std::vector<u16> ord1149({1, 0});
      slog::Relation* readrel1150 = db->getRelation("num");
      numindex1129 = readrel1150->getIndex(ord1149, false);
      std::vector<u16> ord1151({1, 0});
      slog::Relation* readrel1152 = db->getRelation("ref");
      refindex1130 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({1, 0});
      slog::Relation* readrel1154 = db->getRelation("num");
      numindex1131 = readrel1154->getIndex(ord1153, false);
      std::vector<u16> ord1155({1, 0});
      slog::Relation* readrel1156 = db->getRelation("primref");
      primrefindex1132 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({1, 0});
      slog::Relation* readrel1158 = db->getRelation("num");
      numindex1133 = readrel1158->getIndex(ord1157, false);
      std::vector<u16> ord1159({1, 0});
      slog::Relation* readrel1160 = db->getRelation("primref");
      primrefindex1134 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({1, 0});
      slog::Relation* readrel1162 = db->getRelation("primref");
      primrefindex1135 = readrel1162->getIndex(ord1161, false);
      std::vector<u16> ord1163({1, 0});
      slog::Relation* readrel1164 = db->getRelation("ref");
      refindex1136 = readrel1164->getIndex(ord1163, false);
      std::vector<u16> ord1165({1, 0});
      slog::Relation* readrel1166 = db->getRelation("num");
      numindex1137 = readrel1166->getIndex(ord1165, false);
      std::vector<u16> ord1167({1, 0});
      slog::Relation* readrel1168 = db->getRelation("ref");
      refindex1138 = readrel1168->getIndex(ord1167, false);
      std::vector<u16> ord1169({1, 0});
      slog::Relation* readrel1170 = db->getRelation("num");
      numindex1139 = readrel1170->getIndex(ord1169, false);
  
    }
    ReadTask1140(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c260 = v_constef2d127de37b942baad06145;
      u64 v_c261 = v_const0933fb667296882d8c45abca;
      u64 v_c262 = v_consted725292f5f32d61535958c1;
      u64 v_c263 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c264 = v_const5feceb66ffc86f38d952786c;
      u64 v_c265 = v_const90fb9068eda6f2d68bb61c33;
      u64 v_c266 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c267 = v_constf5ca38f748a1d6eaf726b8a4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c268 = _t[0];
        if (!slog::exists_probe<2,1>(numindex1125, std::array<u64,2>{v_c264, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex1126, std::array<u64,2>{v_c262, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex1127, std::array<u64,2>{v_c261, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1128, std::array<u64,2>{v_c266, 0})) return;
        if (!slog::exists_probe<2,1>(numindex1129, std::array<u64,2>{v_c263, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1130, std::array<u64,2>{v_c267, 0})) return;
        if (!slog::exists_probe<2,1>(numindex1131, std::array<u64,2>{v_c260, 0})) return;
        slog::join_probe<2,1>(primrefindex1132, std::array<u64,2>{v_c265, 0}, [&](const std::array<u64,2>& m1171) {
          u64 v_c269 = m1171[1];
          slog::join_probe<2,1>(numindex1133, std::array<u64,2>{v_c264, 0}, [&](const std::array<u64,2>& m1172) {
            u64 v_c270 = m1172[1];
            slog::join_probe<2,1>(primrefindex1134, std::array<u64,2>{v_c262, 0}, [&](const std::array<u64,2>& m1173) {
              u64 v_c271 = m1173[1];
              slog::join_probe<2,1>(primrefindex1135, std::array<u64,2>{v_c261, 0}, [&](const std::array<u64,2>& m1174) {
                u64 v_c272 = m1174[1];
                slog::join_probe<2,1>(refindex1136, std::array<u64,2>{v_c266, 0}, [&](const std::array<u64,2>& m1175) {
                  u64 v_c273 = m1175[1];
                  slog::join_probe<2,1>(numindex1137, std::array<u64,2>{v_c263, 0}, [&](const std::array<u64,2>& m1176) {
                    u64 v_c274 = m1176[1];
                    slog::join_probe<2,1>(refindex1138, std::array<u64,2>{v_c267, 0}, [&](const std::array<u64,2>& m1177) {
                      u64 v_c275 = m1177[1];
                      slog::join_probe<2,1>(numindex1139, std::array<u64,2>{v_c260, 0}, [&](const std::array<u64,2>& m1178) {
                        u64 v_c276 = m1178[1];
                        u64 v_c277 = _prim_lpush(db, v_c268, v_c276);
                        if (v_c277 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:40"); return; }
                        u64 v_c278 = _prim_lpush(db, v_c268, v_c273);
                        if (v_c278 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:40"); return; }
                        u64 v_c279 = _prim_lpush(db, v_c268, v_c266);
                        if (v_c279 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:40"); return; }
                        ++_fires;
                        slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c279, v_c278, v_c268, v_c277});
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
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp4TYC2001", _fires);
  
      if (!_done)
      {
        ReadTask1140* _cont = new ReadTask1140(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1140(db,b), false);
  // (crule (pre) (scan eval_args __t192L615 es rho t) (body (exists app (2 0 1) 1 es) (exists eval (2 3 0 1) 2 rho t) (exists tick (2 0 1) 1 t) (exists eval_args_ans (0 1) 1 __t192L615) (join eval (2 3 0 1) 2 rho t __3JBR1203 __t3MQm616) (exists tick (1 2 0) 2 __t3MQm616 t) (join-old app (2 0 1) 2 (2 0 1) es __t3MQm616 ef) (join eval (1 2 3 0) 3 ef rho t __t7lOb612) (exists eval_ans (0 1) 1 __t7lOb612) (join-old tick (1 2 0) 2 (1 2 0) __t3MQm616 t __t2n7W617) (exists tick_ans (0 1) 1 __t2n7W617) (join eval_ans (0 1) 1 __t7lOb612 __t6tRF614) (join eval_args_ans (0 1) 1 __t192L615 vs) (join tick_ans (0 1) 1 __t2n7W617 t2) (join closure (0 1 2) 1 __t6tRF614 __t20Nd613 rhoc) (join lambda (0 1 2) 1 __t20Nd613 xs eb)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask1197 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1179;  slog::Index** evalindex1180;  slog::Index** tickindex1181;  slog::Index** eval_args_ansindex1182;  slog::Index** evalindex1183;  slog::Index** tickindex1184;  slog::Index** appindex1185;  slog::Index** evalindex1186;  slog::Index** eval_ansindex1187;  slog::Index** tickindex1188;  slog::Index** tick_ansindex1189;  slog::Index** eval_ansindex1190;  slog::Index** eval_args_ansindex1191;  slog::Index** tick_ansindex1192;  slog::Index** closureindex1193;  slog::Index** lambdaindex1194;  slog::Index** appdelta1195;  slog::Index** tickdelta1196;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord1198({0, 1, 2, 3});
      slog::Relation* readrel1199 = db->getRelation("bind_store");
      head_index[0] = readrel1199->getIndex(ord1198, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1200({0, 1});
      slog::Relation* readrel1201 = db->getRelation("call_event");
      head_index[1] = readrel1201->getIndex(ord1200, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord1202({2, 0, 1});
      slog::Relation* readrel1203 = db->getRelation("app");
      appindex1179 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({2, 3, 0, 1});
      slog::Relation* readrel1205 = db->getRelation("eval");
      evalindex1180 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({2, 0, 1});
      slog::Relation* readrel1207 = db->getRelation("tick");
      tickindex1181 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({0, 1});
      slog::Relation* readrel1209 = db->getRelation("eval_args_ans");
      eval_args_ansindex1182 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({2, 3, 0, 1});
      slog::Relation* readrel1211 = db->getRelation("eval");
      evalindex1183 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({1, 2, 0});
      slog::Relation* readrel1213 = db->getRelation("tick");
      tickindex1184 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({2, 0, 1});
      slog::Relation* readrel1215 = db->getRelation("app");
      appindex1185 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({2, 0, 1});
      slog::Relation* readrel1217 = db->getRelation("app");
      appdelta1195 = readrel1217->getIndex(ord1216, true);
      std::vector<u16> ord1218({1, 2, 3, 0});
      slog::Relation* readrel1219 = db->getRelation("eval");
      evalindex1186 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({0, 1});
      slog::Relation* readrel1221 = db->getRelation("eval_ans");
      eval_ansindex1187 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({1, 2, 0});
      slog::Relation* readrel1223 = db->getRelation("tick");
      tickindex1188 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({1, 2, 0});
      slog::Relation* readrel1225 = db->getRelation("tick");
      tickdelta1196 = readrel1225->getIndex(ord1224, true);
      std::vector<u16> ord1226({0, 1});
      slog::Relation* readrel1227 = db->getRelation("tick_ans");
      tick_ansindex1189 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({0, 1});
      slog::Relation* readrel1229 = db->getRelation("eval_ans");
      eval_ansindex1190 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({0, 1});
      slog::Relation* readrel1231 = db->getRelation("eval_args_ans");
      eval_args_ansindex1191 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({0, 1});
      slog::Relation* readrel1233 = db->getRelation("tick_ans");
      tick_ansindex1192 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({0, 1, 2});
      slog::Relation* readrel1235 = db->getRelation("closure");
      closureindex1193 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({0, 1, 2});
      slog::Relation* readrel1237 = db->getRelation("lambda");
      lambdaindex1194 = readrel1237->getIndex(ord1236, false);
  
    }
    ReadTask1197(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c210 = _t[0];
        u64 v_c209 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c27 = _t[3];
        if (!slog::exists_probe<3,1>(appindex1179, std::array<u64,3>{v_c209, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex1180, std::array<u64,4>{v_c26, v_c27, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1181, std::array<u64,3>{v_c27, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex1182, std::array<u64,2>{v_c210, 0})) return;
        slog::join_probe<4,2>(evalindex1183, std::array<u64,4>{v_c26, v_c27, 0, 0}, [&](const std::array<u64,4>& m1238) {
          u64 v_c207 = m1238[2]; u64 v_c208 = m1238[3];
          if (!slog::exists_probe<3,2>(tickindex1184, std::array<u64,3>{v_c208, v_c27, 0})) return;
          slog::join_probe_old<3,2>(appindex1185, appdelta1195, std::array<u64,3>{v_c209, v_c208, 0}, [&](const std::array<u64,3>& m1239) {
            u64 v_c206 = m1239[2];
            slog::join_probe<4,3>(evalindex1186, std::array<u64,4>{v_c206, v_c26, v_c27, 0}, [&](const std::array<u64,4>& m1240) {
              u64 v_c205 = m1240[3];
              if (!slog::exists_probe<2,1>(eval_ansindex1187, std::array<u64,2>{v_c205, 0})) return;
              slog::join_probe_old<3,2>(tickindex1188, tickdelta1196, std::array<u64,3>{v_c208, v_c27, 0}, [&](const std::array<u64,3>& m1241) {
                u64 v_c211 = m1241[2];
                if (!slog::exists_probe<2,1>(tick_ansindex1189, std::array<u64,2>{v_c211, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1190, std::array<u64,2>{v_c205, 0}, [&](const std::array<u64,2>& m1242) {
                  u64 v_c204 = m1242[1];
                  slog::join_probe<2,1>(eval_args_ansindex1191, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m1243) {
                    u64 v_c212 = m1243[1];
                    slog::join_probe<2,1>(tick_ansindex1192, std::array<u64,2>{v_c211, 0}, [&](const std::array<u64,2>& m1244) {
                      u64 v_c213 = m1244[1];
                      slog::join_probe<3,1>(closureindex1193, std::array<u64,3>{v_c204, 0, 0}, [&](const std::array<u64,3>& m1245) {
                        u64 v_c202 = m1245[1]; u64 v_c203 = m1245[2];
                        slog::join_probe<3,1>(lambdaindex1194, std::array<u64,3>{v_c202, 0, 0}, [&](const std::array<u64,3>& m1246) {
                          u64 v_c151 = m1246[1]; u64 v_c31 = m1246[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c151, v_c212, v_c213, v_c27}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c213, v_c27}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask1197* _cont = new ReadTask1197(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1197(db,b), false);
  // (crule (pre (let __trid9YGR1554 consteca796f75a14387c3a7674e7) (let __trel6DtZ1555 constdd7bbf31ce5f578b9805e840) (let __tcol2ERf1556 const5feceb66ffc86f38d952786c) (let __trel7GSg1557 constdd7bbf31ce5f578b9805e840) (let __tcol1E8T1558 const6b86b273ff34fce19d6b804e)) (scan $sup5638x29x0x0x2 __d0 __d1 __d2 __d4 __v0 __v1 __v3 p0 p1 t0 t1) (body) (head (tycheck p0 (accept int) __trid9YGR1554 __trel6DtZ1555 __tcol2ERf1556 (1 2 3 4 0)) (tycheck __v1 (accept int) __trid9YGR1554 __trel7GSg1557 __tcol1E8T1558 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __75qg1553 p0 __v1)) map.slog:30 #f)
  class ReadTask1247 : public slog::Task
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
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_msk");
      outer_rel = db->getRelation("$sup5638x29x0x0x2");
  
    }
    ReadTask1247(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c280 = v_consteca796f75a14387c3a7674e7;
      u64 v_c281 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c282 = v_const5feceb66ffc86f38d952786c;
      u64 v_c283 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c284 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c11 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c285 = _t[2];
        u64 v_c286 = _t[3];
        u64 v_c92 = _t[4];
        u64 v_c107 = _t[5];
        u64 v_c108 = _t[6];
        u64 v_c100 = _t[7];
        u64 v_c102 = _t[8];
        u64 v_c101 = _t[9];
        u64 v_c103 = _t[10];
        ++_fires;
        if (!(is_int(v_c100)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c280, v_c281, v_c282, v_c100}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c107)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c280, v_c283, v_c284, v_c107}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c100, v_c107}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x2", _fires);
  
      if (!_done)
      {
        ReadTask1247* _cont = new ReadTask1247(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1247(db,b), false);
  // (crule (pre) (scan mp_union_ans __t1OdF455 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t1OdF455 l u) (exists mbranch (3 0 1 2 4) 1 u) (exists mbranch (3 0 1 2 4) 1 l) (join-old $sup5638x93x0x0x0 (1 5 0 2 3 4 6) 2 (1 5 0 2 3 4 6) l u __t70BJ454 m p r v) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 r v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t1p4P452) (exists mp_union (2 0 1) 2 __t1p4P452 __t70BJ454) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4xjy453) (join-old mp_union (0 1 2) 3 (0 1 2) __t70BJ454 __t4xjy453 __t1p4P452) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t4atM456) (join-old mp_union_ans (0 1) 1 (0 1) __t4atM456 __v1)) (head (emit-temp temp9Yrn2045 __t70BJ454 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t8Q9x451 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask1267 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1248;  slog::Index** mbranchindex1249;  slog::Index** mbranchindex1250;  slog::Index** $sup5638x93x0x0x0index1251;  slog::Index** mbranchindex1252;  slog::Index** mp_unionindex1253;  slog::Index** mbranchindex1254;  slog::Index** mp_unionindex1255;  slog::Index** mbranchindex1256;  slog::Index** mp_unionindex1257;  slog::Index** mp_unionindex1258;  slog::Index** mp_union_ansindex1259;  slog::Index** mp_uniondelta1260;  slog::Index** $sup5638x93x0x0x0delta1261;  slog::Index** mbranchdelta1262;  slog::Index** mbranchdelta1263;  slog::Index** mp_uniondelta1264;  slog::Index** mp_uniondelta1265;  slog::Index** mp_union_ansdelta1266;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Yrn2045");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord1268({0, 1, 2});
      slog::Relation* readrel1269 = db->getRelation("mp_union");
      mp_unionindex1248 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({0, 1, 2});
      slog::Relation* readrel1271 = db->getRelation("mp_union");
      mp_uniondelta1260 = readrel1271->getIndex(ord1270, true);
      std::vector<u16> ord1272({3, 0, 1, 2, 4});
      slog::Relation* readrel1273 = db->getRelation("mbranch");
      mbranchindex1249 = readrel1273->getIndex(ord1272, false);
      std::vector<u16> ord1274({3, 0, 1, 2, 4});
      slog::Relation* readrel1275 = db->getRelation("mbranch");
      mbranchindex1250 = readrel1275->getIndex(ord1274, false);
      std::vector<u16> ord1276({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel1277 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index1251 = readrel1277->getIndex(ord1276, false);
      std::vector<u16> ord1278({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel1279 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0delta1261 = readrel1279->getIndex(ord1278, true);
      std::vector<u16> ord1280({1, 2, 3, 4, 0});
      slog::Relation* readrel1281 = db->getRelation("mbranch");
      mbranchindex1252 = readrel1281->getIndex(ord1280, false);
      std::vector<u16> ord1282({1, 2, 0});
      slog::Relation* readrel1283 = db->getRelation("mp_union");
      mp_unionindex1253 = readrel1283->getIndex(ord1282, false);
      std::vector<u16> ord1284({1, 2, 3, 4, 0});
      slog::Relation* readrel1285 = db->getRelation("mbranch");
      mbranchindex1254 = readrel1285->getIndex(ord1284, false);
      std::vector<u16> ord1286({1, 2, 3, 4, 0});
      slog::Relation* readrel1287 = db->getRelation("mbranch");
      mbranchdelta1262 = readrel1287->getIndex(ord1286, true);
      std::vector<u16> ord1288({2, 0, 1});
      slog::Relation* readrel1289 = db->getRelation("mp_union");
      mp_unionindex1255 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({1, 2, 3, 4, 0});
      slog::Relation* readrel1291 = db->getRelation("mbranch");
      mbranchindex1256 = readrel1291->getIndex(ord1290, false);
      std::vector<u16> ord1292({1, 2, 3, 4, 0});
      slog::Relation* readrel1293 = db->getRelation("mbranch");
      mbranchdelta1263 = readrel1293->getIndex(ord1292, true);
      std::vector<u16> ord1294({0, 1, 2});
      slog::Relation* readrel1295 = db->getRelation("mp_union");
      mp_unionindex1257 = readrel1295->getIndex(ord1294, false);
      std::vector<u16> ord1296({0, 1, 2});
      slog::Relation* readrel1297 = db->getRelation("mp_union");
      mp_uniondelta1264 = readrel1297->getIndex(ord1296, true);
      std::vector<u16> ord1298({1, 2, 0});
      slog::Relation* readrel1299 = db->getRelation("mp_union");
      mp_unionindex1258 = readrel1299->getIndex(ord1298, false);
      std::vector<u16> ord1300({1, 2, 0});
      slog::Relation* readrel1301 = db->getRelation("mp_union");
      mp_uniondelta1265 = readrel1301->getIndex(ord1300, true);
      std::vector<u16> ord1302({0, 1});
      slog::Relation* readrel1303 = db->getRelation("mp_union_ans");
      mp_union_ansindex1259 = readrel1303->getIndex(ord1302, false);
      std::vector<u16> ord1304({0, 1});
      slog::Relation* readrel1305 = db->getRelation("mp_union_ans");
      mp_union_ansdelta1266 = readrel1305->getIndex(ord1304, true);
  
    }
    ReadTask1267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c287 = _t[0];
        u64 v_c92 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex1248, mp_uniondelta1260, std::array<u64,3>{v_c287, 0, 0}, [&](const std::array<u64,3>& m1306) {
          u64 v_c13 = m1306[1]; u64 v_c80 = m1306[2];
          if (!slog::exists_probe<5,1>(mbranchindex1249, std::array<u64,5>{v_c80, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex1250, std::array<u64,5>{v_c13, 0, 0, 0, 0})) return;
          slog::join_probe_old<7,2>($sup5638x93x0x0x0index1251, $sup5638x93x0x0x0delta1261, std::array<u64,7>{v_c13, v_c80, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m1307) {
            u64 v_c288 = m1307[2]; u64 v_c14 = m1307[3]; u64 v_c15 = m1307[4]; u64 v_c16 = m1307[5]; u64 v_c81 = m1307[6];
            if (!slog::exists_probe<5,4>(mbranchindex1252, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, 0})) return;
            if (!slog::exists_probe<3,2>(mp_unionindex1253, std::array<u64,3>{v_c16, v_c81, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex1254, mbranchdelta1262, std::array<u64,5>{v_c15, v_c14, v_c80, v_c81, 0}, [&](const std::array<u64,5>& m1308) {
              u64 v_c289 = m1308[4];
              if (!slog::exists_probe<3,2>(mp_unionindex1255, std::array<u64,3>{v_c289, v_c288, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex1256, mbranchdelta1263, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, 0}, [&](const std::array<u64,5>& m1309) {
                u64 v_c290 = m1309[4];
                slog::join_probe_old<3,3>(mp_unionindex1257, mp_uniondelta1264, std::array<u64,3>{v_c288, v_c290, v_c289}, [&](const std::array<u64,3>& m1310) {
                  slog::join_probe_old<3,2>(mp_unionindex1258, mp_uniondelta1265, std::array<u64,3>{v_c16, v_c81, 0}, [&](const std::array<u64,3>& m1311) {
                    u64 v_c291 = m1311[2];
                    slog::join_probe_old<2,1>(mp_union_ansindex1259, mp_union_ansdelta1266, std::array<u64,2>{v_c291, 0}, [&](const std::array<u64,2>& m1312) {
                      u64 v_c107 = m1312[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c288, v_c92, v_c107, v_c14, v_c15});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c14, v_c92, v_c107}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask1267* _cont = new ReadTask1267(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1267(db,b), false);
  // (crule (pre (let __trid1FMn1391 constfc04a7193b8b865723e61851) (let __trel9Eox1392 conste90c92f3e6c3b47a7bc93e42) (let __tcol72ok1393 const5feceb66ffc86f38d952786c) (let __trel0OlG1394 conste90c92f3e6c3b47a7bc93e42) (let __tcol183Q1395 const6b86b273ff34fce19d6b804e) (let __trel5FH81396 conste90c92f3e6c3b47a7bc93e42) (let __tcol5rPg1397 constd4735e3a265e16eee03f5971)) (scan $sup70016x75x0x0x0 __d0 ef es rho t) (body) (head (tycheck es (accept seq) __trid1FMn1391 __trel9Eox1392 __tcol72ok1393 (1 2 3 4 0)) (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid1FMn1391 __trel0OlG1394 __tcol183Q1395 (1 2 3 4 0)) (tycheck t (accept seq) __trid1FMn1391 __trel5FH81396 __tcol5rPg1397 (1 2 3 4 0)) (mkstruct eval_args (1 3 2 0) __88gN1390 es t rho)) interp.slog:76 #f)
  class ReadTask1316 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1314;  u32 sid1313;  u32 sid1315;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval_args");
      outer_rel = db->getRelation("$sup70016x75x0x0x0");
      sid1314 = db->getRelation("_enum")->getStructId();
      sid1313 = db->getRelation("mbranch")->getStructId();
      sid1315 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1316(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c292 = v_constfc04a7193b8b865723e61851;
      u64 v_c293 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c294 = v_const5feceb66ffc86f38d952786c;
      u64 v_c295 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c296 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c297 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c298 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c206 = _t[1];
        u64 v_c209 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c27 = _t[4];
        ++_fires;
        if (!(is_seq(v_c209)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c292, v_c293, v_c294, v_c209}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c26) && (decode_struct_id(v_c26) == sid1313 || decode_struct_id(v_c26) == sid1314 || decode_struct_id(v_c26) == sid1315))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c292, v_c295, v_c296, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c27)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c292, v_c297, v_c298, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c209, v_c27, v_c26}, std::array<u16,4>{1, 3, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:$sup70016x75x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1316* _cont = new ReadTask1316(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1316(db,b), false);
  // (crule (pre (let __tconst4bk430 const5feceb66ffc86f38d952786c)) (scan mp_get __t3H4x29 __t9yY728 k) (body (join mbranch (0 1 2 3 4) 1 __t9yY728 p m l r) (let __t9Jlq31 (band k m)) (cmp gt __t9Jlq31 __tconst4bk430)) (head (emit $sup5638x52x0x0x0 (0 1 2 3 4 5) __t3H4x29 k l m p r)) map.slog:53 #f)
  class ReadTask1318 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1317;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x52x0x0x0");
      std::vector<u16> ord1319({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel1320 = db->getRelation("$sup5638x52x0x0x0");
      head_index[0] = readrel1320->getIndex(ord1319, false);
      outer_rel = db->getRelation("mp_get");
      std::vector<u16> ord1321({0, 1, 2, 3, 4});
      slog::Relation* readrel1322 = db->getRelation("mbranch");
      mbranchindex1317 = readrel1322->getIndex(ord1321, false);
  
    }
    ReadTask1318(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c299 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c300 = _t[0];
        u64 v_c301 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe<5,1>(mbranchindex1317, std::array<u64,5>{v_c301, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1323) {
          u64 v_c15 = m1323[1]; u64 v_c14 = m1323[2]; u64 v_c13 = m1323[3]; u64 v_c16 = m1323[4];
          u64 v_c302 = _prim_band(db, v_c12, v_c14);
          if (v_c302 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
          u64 v_c303 = _prim_gt(db, v_c302, v_c299);
          if (v_c303 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
          if (!v_c303) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c300, v_c12, v_c13, v_c14, v_c15, v_c16}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:53", "delta:mp_get", _fires);
  
      if (!_done)
      {
        ReadTask1318* _cont = new ReadTask1318(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1318(db,b), false);
  // (crule (pre (let __tconst6I9K760 constd59eced1ded07f84c145592f)) (scan temp4jKt1905 __t5xOK723 __t8UvH755 __t8k6P758) (body (join lambda (1 2 0) 2 __t8k6P758 __t8UvH755 __t9E0P759)) (head (emit-temp temp6yZq1906 __t5xOK723 __t9E0P759) (mkstruct letrec (1 2 3 0) __t79Wk761 __tconst6I9K760 __t9E0P759 __t5xOK723)) kcfa.slog:70 #f)
  class ReadTask1326 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex1325;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6yZq1906");
      head_rel[1] = db->getRelation("letrec");
      outer_rel = db->getRelation("temp4jKt1905");
      std::vector<u16> ord1327({1, 2, 0});
      slog::Relation* readrel1328 = db->getRelation("lambda");
      lambdaindex1325 = readrel1328->getIndex(ord1327, false);
  
    }
    ReadTask1326(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c304 = v_constd59eced1ded07f84c145592f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c305 = _t[0];
        u64 v_c306 = _t[1];
        u64 v_c307 = _t[2];
        slog::join_probe<3,2>(lambdaindex1325, std::array<u64,3>{v_c307, v_c306, 0}, [&](const std::array<u64,3>& m1329) {
          u64 v_c308 = m1329[2];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c305, v_c308});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c304, v_c308, v_c305}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:70", "delta:temp4jKt1905", _fires);
  
      if (!_done)
      {
        ReadTask1326* _cont = new ReadTask1326(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1326(db,b), false);
  // (crule (pre) (scan letrec __t7PJK811 x er eb) (body (join-old eval (1 2 3 0) 1 (1 2 3 0) __t7PJK811 rho t __t94oK812)) (head (emit $sup70016x95x0x0x0 (1 4 2 0 3 5) eb t er __t94oK812 rho x)) interp.slog:96 #f)
  class ReadTask1332 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1330;  slog::Index** evaldelta1331;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x95x0x0x0");
      std::vector<u16> ord1333({1, 4, 2, 0, 3, 5});
      slog::Relation* readrel1334 = db->getRelation("$sup70016x95x0x0x0");
      head_index[0] = readrel1334->getIndex(ord1333, false);
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord1335({1, 2, 3, 0});
      slog::Relation* readrel1336 = db->getRelation("eval");
      evalindex1330 = readrel1336->getIndex(ord1335, false);
      std::vector<u16> ord1337({1, 2, 3, 0});
      slog::Relation* readrel1338 = db->getRelation("eval");
      evaldelta1331 = readrel1338->getIndex(ord1337, true);
  
    }
    ReadTask1332(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c309 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c30 = _t[2];
        u64 v_c31 = _t[3];
        slog::join_probe_old<4,1>(evalindex1330, evaldelta1331, std::array<u64,4>{v_c309, 0, 0, 0}, [&](const std::array<u64,4>& m1339) {
          u64 v_c26 = m1339[1]; u64 v_c27 = m1339[2]; u64 v_c310 = m1339[3];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c31, v_c27, v_c30, v_c310, v_c26, v_c29}, std::array<u16,6>{1, 4, 2, 0, 3, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:letrec", _fires);
  
      if (!_done)
      {
        ReadTask1332* _cont = new ReadTask1332(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1332(db,b), false);
  // (crule (pre) (scan mp_union __t5awj693 __t1ouF694 __t1a8C695) (body (exists $sup5638x101x0x0x0 (0 7 8 1 2 3 4 5 6 9 10) 3 __t5awj693 __t1ouF694 __t1a8C695) (join-old mp_join (2 4 0 1 3) 2 (2 4 0 1 3) __t1ouF694 __t1a8C695 __t8BsD696 p q) (exists mbranch (0 1 2 3 4) 2 __t1ouF694 p) (exists mbranch (0 1 2 3 4) 2 __t1a8C695 q) (exists mp_msk (1 2 0) 1 q) (exists mp_join_ans (0 1) 1 __t8BsD696) (join $sup5638x101x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 5 p q __t1ouF694 __t1a8C695 __t5awj693 l m n r u v) (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t1ouF694) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t1a8C695) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t84wf697) (join mp_msk_ans (0 1) 1 __t84wf697 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t8BsD696 res)) (head (emit mp_union_ans (0 1) __t5awj693 res)) map.slog:102 #f)
  class ReadTask1356 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x101x0x0x0index1340;  slog::Index** mp_joinindex1341;  slog::Index** mbranchindex1342;  slog::Index** mbranchindex1343;  slog::Index** mp_mskindex1344;  slog::Index** mp_join_ansindex1345;  slog::Index** $sup5638x101x0x0x0index1346;  slog::Index** mbranchindex1347;  slog::Index** mbranchindex1348;  slog::Index** mp_mskindex1349;  slog::Index** mp_msk_ansindex1350;  slog::Index** mp_join_ansindex1351;  slog::Index** mp_joindelta1352;  slog::Index** mbranchdelta1353;  slog::Index** mbranchdelta1354;  slog::Index** mp_mskdelta1355;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1357({0, 1});
      slog::Relation* readrel1358 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1358->getIndex(ord1357, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1359({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
      slog::Relation* readrel1360 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index1340 = readrel1360->getIndex(ord1359, false);
      std::vector<u16> ord1361({2, 4, 0, 1, 3});
      slog::Relation* readrel1362 = db->getRelation("mp_join");
      mp_joinindex1341 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({2, 4, 0, 1, 3});
      slog::Relation* readrel1364 = db->getRelation("mp_join");
      mp_joindelta1352 = readrel1364->getIndex(ord1363, true);
      std::vector<u16> ord1365({0, 1, 2, 3, 4});
      slog::Relation* readrel1366 = db->getRelation("mbranch");
      mbranchindex1342 = readrel1366->getIndex(ord1365, false);
      std::vector<u16> ord1367({0, 1, 2, 3, 4});
      slog::Relation* readrel1368 = db->getRelation("mbranch");
      mbranchindex1343 = readrel1368->getIndex(ord1367, false);
      std::vector<u16> ord1369({1, 2, 0});
      slog::Relation* readrel1370 = db->getRelation("mp_msk");
      mp_mskindex1344 = readrel1370->getIndex(ord1369, false);
      std::vector<u16> ord1371({0, 1});
      slog::Relation* readrel1372 = db->getRelation("mp_join_ans");
      mp_join_ansindex1345 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel1374 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index1346 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({1, 2, 3, 4, 0});
      slog::Relation* readrel1376 = db->getRelation("mbranch");
      mbranchindex1347 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({1, 2, 3, 4, 0});
      slog::Relation* readrel1378 = db->getRelation("mbranch");
      mbranchdelta1353 = readrel1378->getIndex(ord1377, true);
      std::vector<u16> ord1379({1, 2, 3, 4, 0});
      slog::Relation* readrel1380 = db->getRelation("mbranch");
      mbranchindex1348 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({1, 2, 3, 4, 0});
      slog::Relation* readrel1382 = db->getRelation("mbranch");
      mbranchdelta1354 = readrel1382->getIndex(ord1381, true);
      std::vector<u16> ord1383({1, 2, 0});
      slog::Relation* readrel1384 = db->getRelation("mp_msk");
      mp_mskindex1349 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({1, 2, 0});
      slog::Relation* readrel1386 = db->getRelation("mp_msk");
      mp_mskdelta1355 = readrel1386->getIndex(ord1385, true);
      std::vector<u16> ord1387({0, 1});
      slog::Relation* readrel1388 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1350 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({0, 1});
      slog::Relation* readrel1390 = db->getRelation("mp_join_ans");
      mp_join_ansindex1351 = readrel1390->getIndex(ord1389, false);
  
    }
    ReadTask1356(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c311 = _t[0];
        u64 v_c312 = _t[1];
        u64 v_c313 = _t[2];
        if (!slog::exists_probe<11,3>($sup5638x101x0x0x0index1340, std::array<u64,11>{v_c311, v_c312, v_c313, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex1341, mp_joindelta1352, std::array<u64,5>{v_c312, v_c313, 0, 0, 0}, [&](const std::array<u64,5>& m1391) {
          u64 v_c314 = m1391[2]; u64 v_c15 = m1391[3]; u64 v_c79 = m1391[4];
          if (!slog::exists_probe<5,2>(mbranchindex1342, std::array<u64,5>{v_c312, v_c15, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex1343, std::array<u64,5>{v_c313, v_c79, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex1344, std::array<u64,3>{v_c79, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex1345, std::array<u64,2>{v_c314, 0})) return;
          slog::join_probe<11,5>($sup5638x101x0x0x0index1346, std::array<u64,11>{v_c15, v_c79, v_c312, v_c313, v_c311, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1392) {
            u64 v_c13 = m1392[5]; u64 v_c14 = m1392[6]; u64 v_c78 = m1392[7]; u64 v_c16 = m1392[8]; u64 v_c80 = m1392[9]; u64 v_c81 = m1392[10];
            u64 v_c315 = _prim_lt(db, v_c78, v_c14);
            if (v_c315 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c315) return;
            slog::join_probe_old<5,5>(mbranchindex1347, mbranchdelta1353, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, v_c312}, [&](const std::array<u64,5>& m1394) {
              slog::join_probe_old<5,5>(mbranchindex1348, mbranchdelta1354, std::array<u64,5>{v_c79, v_c78, v_c80, v_c81, v_c313}, [&](const std::array<u64,5>& m1395) {
                slog::join_probe_old<3,2>(mp_mskindex1349, mp_mskdelta1355, std::array<u64,3>{v_c79, v_c14, 0}, [&](const std::array<u64,3>& m1396) {
                  u64 v_c316 = m1396[2];
                  slog::join_probe<2,1>(mp_msk_ansindex1350, std::array<u64,2>{v_c316, 0}, [&](const std::array<u64,2>& m1397) {
                    u64 v_c92 = m1397[1];
                    if (v_c15 == v_c92) return;
                    slog::join_probe<2,1>(mp_join_ansindex1351, std::array<u64,2>{v_c314, 0}, [&](const std::array<u64,2>& m1398) {
                      u64 v_c95 = m1398[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c311, v_c95}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask1356* _cont = new ReadTask1356(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1356(db,b), false);
  // (crule (pre) (scan mp_union __t5Qtl389 __t6AX6390 __t46nL391) (body (exists $sup5638x110x0x0x0 (0 7 8 1 2 3 4 5 6 9 10) 3 __t5Qtl389 __t6AX6390 __t46nL391) (join-old mp_join (2 4 0 1 3) 2 (2 4 0 1 3) __t6AX6390 __t46nL391 __t6UVn392 p q) (exists mbranch (0 1 2 3 4) 2 __t6AX6390 p) (exists mbranch (0 1 2 3 4) 2 __t46nL391 q) (exists mp_msk (1 2 0) 1 p) (exists mp_join_ans (0 1) 1 __t6UVn392) (join $sup5638x110x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 5 p q __t6AX6390 __t46nL391 __t5Qtl389 l m n r u v) (cmp lt m n) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6AX6390) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t46nL391) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t827P393) (join mp_msk_ans (0 1) 1 __t827P393 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t6UVn392 res)) (head (emit mp_union_ans (0 1) __t5Qtl389 res)) map.slog:111 #f)
  class ReadTask1415 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x110x0x0x0index1399;  slog::Index** mp_joinindex1400;  slog::Index** mbranchindex1401;  slog::Index** mbranchindex1402;  slog::Index** mp_mskindex1403;  slog::Index** mp_join_ansindex1404;  slog::Index** $sup5638x110x0x0x0index1405;  slog::Index** mbranchindex1406;  slog::Index** mbranchindex1407;  slog::Index** mp_mskindex1408;  slog::Index** mp_msk_ansindex1409;  slog::Index** mp_join_ansindex1410;  slog::Index** mp_joindelta1411;  slog::Index** mbranchdelta1412;  slog::Index** mbranchdelta1413;  slog::Index** mp_mskdelta1414;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1416({0, 1});
      slog::Relation* readrel1417 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1417->getIndex(ord1416, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1418({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
      slog::Relation* readrel1419 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index1399 = readrel1419->getIndex(ord1418, false);
      std::vector<u16> ord1420({2, 4, 0, 1, 3});
      slog::Relation* readrel1421 = db->getRelation("mp_join");
      mp_joinindex1400 = readrel1421->getIndex(ord1420, false);
      std::vector<u16> ord1422({2, 4, 0, 1, 3});
      slog::Relation* readrel1423 = db->getRelation("mp_join");
      mp_joindelta1411 = readrel1423->getIndex(ord1422, true);
      std::vector<u16> ord1424({0, 1, 2, 3, 4});
      slog::Relation* readrel1425 = db->getRelation("mbranch");
      mbranchindex1401 = readrel1425->getIndex(ord1424, false);
      std::vector<u16> ord1426({0, 1, 2, 3, 4});
      slog::Relation* readrel1427 = db->getRelation("mbranch");
      mbranchindex1402 = readrel1427->getIndex(ord1426, false);
      std::vector<u16> ord1428({1, 2, 0});
      slog::Relation* readrel1429 = db->getRelation("mp_msk");
      mp_mskindex1403 = readrel1429->getIndex(ord1428, false);
      std::vector<u16> ord1430({0, 1});
      slog::Relation* readrel1431 = db->getRelation("mp_join_ans");
      mp_join_ansindex1404 = readrel1431->getIndex(ord1430, false);
      std::vector<u16> ord1432({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel1433 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index1405 = readrel1433->getIndex(ord1432, false);
      std::vector<u16> ord1434({1, 2, 3, 4, 0});
      slog::Relation* readrel1435 = db->getRelation("mbranch");
      mbranchindex1406 = readrel1435->getIndex(ord1434, false);
      std::vector<u16> ord1436({1, 2, 3, 4, 0});
      slog::Relation* readrel1437 = db->getRelation("mbranch");
      mbranchdelta1412 = readrel1437->getIndex(ord1436, true);
      std::vector<u16> ord1438({1, 2, 3, 4, 0});
      slog::Relation* readrel1439 = db->getRelation("mbranch");
      mbranchindex1407 = readrel1439->getIndex(ord1438, false);
      std::vector<u16> ord1440({1, 2, 3, 4, 0});
      slog::Relation* readrel1441 = db->getRelation("mbranch");
      mbranchdelta1413 = readrel1441->getIndex(ord1440, true);
      std::vector<u16> ord1442({1, 2, 0});
      slog::Relation* readrel1443 = db->getRelation("mp_msk");
      mp_mskindex1408 = readrel1443->getIndex(ord1442, false);
      std::vector<u16> ord1444({1, 2, 0});
      slog::Relation* readrel1445 = db->getRelation("mp_msk");
      mp_mskdelta1414 = readrel1445->getIndex(ord1444, true);
      std::vector<u16> ord1446({0, 1});
      slog::Relation* readrel1447 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1409 = readrel1447->getIndex(ord1446, false);
      std::vector<u16> ord1448({0, 1});
      slog::Relation* readrel1449 = db->getRelation("mp_join_ans");
      mp_join_ansindex1410 = readrel1449->getIndex(ord1448, false);
  
    }
    ReadTask1415(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c254 = _t[0];
        u64 v_c253 = _t[1];
        u64 v_c255 = _t[2];
        if (!slog::exists_probe<11,3>($sup5638x110x0x0x0index1399, std::array<u64,11>{v_c254, v_c253, v_c255, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex1400, mp_joindelta1411, std::array<u64,5>{v_c253, v_c255, 0, 0, 0}, [&](const std::array<u64,5>& m1450) {
          u64 v_c257 = m1450[2]; u64 v_c15 = m1450[3]; u64 v_c79 = m1450[4];
          if (!slog::exists_probe<5,2>(mbranchindex1401, std::array<u64,5>{v_c253, v_c15, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex1402, std::array<u64,5>{v_c255, v_c79, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex1403, std::array<u64,3>{v_c15, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex1404, std::array<u64,2>{v_c257, 0})) return;
          slog::join_probe<11,5>($sup5638x110x0x0x0index1405, std::array<u64,11>{v_c15, v_c79, v_c253, v_c255, v_c254, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1451) {
            u64 v_c13 = m1451[5]; u64 v_c14 = m1451[6]; u64 v_c78 = m1451[7]; u64 v_c16 = m1451[8]; u64 v_c80 = m1451[9]; u64 v_c81 = m1451[10];
            u64 v_c317 = _prim_lt(db, v_c14, v_c78);
            if (v_c317 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c317) return;
            slog::join_probe_old<5,5>(mbranchindex1406, mbranchdelta1412, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, v_c253}, [&](const std::array<u64,5>& m1453) {
              slog::join_probe_old<5,5>(mbranchindex1407, mbranchdelta1413, std::array<u64,5>{v_c79, v_c78, v_c80, v_c81, v_c255}, [&](const std::array<u64,5>& m1454) {
                slog::join_probe_old<3,2>(mp_mskindex1408, mp_mskdelta1414, std::array<u64,3>{v_c15, v_c78, 0}, [&](const std::array<u64,3>& m1455) {
                  u64 v_c258 = m1455[2];
                  slog::join_probe<2,1>(mp_msk_ansindex1409, std::array<u64,2>{v_c258, 0}, [&](const std::array<u64,2>& m1456) {
                    u64 v_c92 = m1456[1];
                    if (v_c79 == v_c92) return;
                    slog::join_probe<2,1>(mp_join_ansindex1410, std::array<u64,2>{v_c257, 0}, [&](const std::array<u64,2>& m1457) {
                      u64 v_c95 = m1457[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c254, v_c95}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask1415* _cont = new ReadTask1415(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1415(db,b), false);
  // (crule (pre (let __tconst35Xg1071 const0122baa3ac55f1b433944eb1) (let __tconst3u5R106 const06abaa100ecef791ce028c56) (let _00024sqc9bdu903 constd4735e3a265e16eee03f5971) (let _00024sqc9U0q904 const5feceb66ffc86f38d952786c) (let _00024sqc3xmn905 const6b86b273ff34fce19d6b804e) (let _00024sqo7aO7906 const5feceb66ffc86f38d952786c) (let _00024sqo8pFe907 const6b86b273ff34fce19d6b804e) (let _00024sqo3hRp908 const6b86b273ff34fce19d6b804e) (let _00024sqo4hee909 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo4hee909 __t5IbK109 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7aO7906 __t5IbK109 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo8pFe907 __t5IbK109 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo3hRp908 __t5IbK109 _00024seq2) (exists _enum (1 0) 1 __tconst35Xg1071) (join delta (1 2 0) 2 __tconst3u5R106 _00024seq2 __t8l3B107) (join _enum (1 0) 1 __tconst35Xg1071 __t6gQ5104) (join boolval (0 1) 1 __t5IbK109 b) (letp _00024sql6c1M901 (aslst _00024seq2)) (let chk5Qrn1970 (llen _00024sql6c1M901)) (eq _00024sqc9bdu903 chk5Qrn1970) (letp chk45X91971 (lref _00024sql6c1M901 _00024sqc9U0q904)) (eq __t5IbK109 chk45X91971) (letp chk7Chx1972 (lref _00024sql6c1M901 _00024sqc3xmn905)) (eq __t5IbK109 chk7Chx1972)) (head (emit-temp temp1yql1955 __t8l3B107) (mkstruct boolval (1 0) __t274c105 __t6gQ5104)) interp.slog:122 #f)
  class ReadTask1465 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1458;  slog::Index** $seq_atindex1459;  slog::Index** $seq_atrindex1460;  slog::Index** _enumindex1461;  slog::Index** deltaindex1462;  slog::Index** _enumindex1463;  slog::Index** boolvalindex1464;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1yql1955");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1466({1, 0, 2});
      slog::Relation* readrel1467 = db->getRelation("$seq_atr");
      driver_index = readrel1467->getIndex(ord1466, true);
      std::vector<u16> ord1468({1, 0, 2});
      slog::Relation* readrel1469 = db->getRelation("$seq_at");
      $seq_atindex1458 = readrel1469->getIndex(ord1468, false);
      std::vector<u16> ord1470({1, 0, 2});
      slog::Relation* readrel1471 = db->getRelation("$seq_at");
      $seq_atindex1459 = readrel1471->getIndex(ord1470, false);
      std::vector<u16> ord1472({1, 0, 2});
      slog::Relation* readrel1473 = db->getRelation("$seq_atr");
      $seq_atrindex1460 = readrel1473->getIndex(ord1472, false);
      std::vector<u16> ord1474({1, 0});
      slog::Relation* readrel1475 = db->getRelation("_enum");
      _enumindex1461 = readrel1475->getIndex(ord1474, false);
      std::vector<u16> ord1476({1, 2, 0});
      slog::Relation* readrel1477 = db->getRelation("delta");
      deltaindex1462 = readrel1477->getIndex(ord1476, false);
      std::vector<u16> ord1478({1, 0});
      slog::Relation* readrel1479 = db->getRelation("_enum");
      _enumindex1463 = readrel1479->getIndex(ord1478, false);
      std::vector<u16> ord1480({0, 1});
      slog::Relation* readrel1481 = db->getRelation("boolval");
      boolvalindex1464 = readrel1481->getIndex(ord1480, false);
  
    }
    ReadTask1465(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c318 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c319 = v_const06abaa100ecef791ce028c56;
      u64 v_c320 = v_constd4735e3a265e16eee03f5971;
      u64 v_c321 = v_const5feceb66ffc86f38d952786c;
      u64 v_c322 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c323 = v_const5feceb66ffc86f38d952786c;
      u64 v_c324 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c325 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c326 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c326, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1482) {
        u64 v_c327 = m1482[1];
        u64 v_c134 = m1482[2];
        if (buckethash(v_c327) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1458, std::array<u64,3>{v_c323, v_c327, v_c134}, [&](const std::array<u64,3>& m1483) {
          slog::join_probe<3,3>($seq_atindex1459, std::array<u64,3>{v_c324, v_c327, v_c134}, [&](const std::array<u64,3>& m1484) {
            slog::join_probe<3,3>($seq_atrindex1460, std::array<u64,3>{v_c325, v_c327, v_c134}, [&](const std::array<u64,3>& m1485) {
              if (!slog::exists_probe<2,1>(_enumindex1461, std::array<u64,2>{v_c318, 0})) return;
              slog::join_probe<3,2>(deltaindex1462, std::array<u64,3>{v_c319, v_c134, 0}, [&](const std::array<u64,3>& m1486) {
                u64 v_c328 = m1486[2];
                slog::join_probe<2,1>(_enumindex1463, std::array<u64,2>{v_c318, 0}, [&](const std::array<u64,2>& m1487) {
                  u64 v_c329 = m1487[1];
                  slog::join_probe<2,1>(boolvalindex1464, std::array<u64,2>{v_c327, 0}, [&](const std::array<u64,2>& m1488) {
                    u64 v_c137 = m1488[1];
                    bool ok1489 = true;
                    u64 v_c330 = _prim_aslst(db, v_c134, &ok1489);
                    if (!ok1489) return;
                    u64 v_c331 = _prim_llen(db, v_c330);
                    if (v_c331 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c320 != v_c331) return;
                    bool ok1490 = true;
                    u64 v_c332 = _prim_lref(db, v_c330, v_c321, &ok1490);
                    if (!ok1490) return;
                    if (v_c327 != v_c332) return;
                    bool ok1491 = true;
                    u64 v_c333 = _prim_lref(db, v_c330, v_c322, &ok1491);
                    if (!ok1491) return;
                    if (v_c327 != v_c333) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c328});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c329}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1465* _cont = new ReadTask1465(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1465(db,b), false);
  // (crule (pre) (scan mbranch __t0JuJ609 p m l r) (body (join-old mp_has0 (1 2 0) 1 (1 2 0) __t0JuJ609 k __t4ZKg610)) (head (emit $sup5638x59x0x0x0 (0 1 2 3 4 5) __t4ZKg610 k l m p r)) map.slog:60 #f)
  class ReadTask1494 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index1492;  slog::Index** mp_has0delta1493;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord1495({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel1496 = db->getRelation("$sup5638x59x0x0x0");
      head_index[0] = readrel1496->getIndex(ord1495, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1497({1, 2, 0});
      slog::Relation* readrel1498 = db->getRelation("mp_has0");
      mp_has0index1492 = readrel1498->getIndex(ord1497, false);
      std::vector<u16> ord1499({1, 2, 0});
      slog::Relation* readrel1500 = db->getRelation("mp_has0");
      mp_has0delta1493 = readrel1500->getIndex(ord1499, true);
  
    }
    ReadTask1494(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c334 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c16 = _t[4];
        slog::join_probe_old<3,1>(mp_has0index1492, mp_has0delta1493, std::array<u64,3>{v_c334, 0, 0}, [&](const std::array<u64,3>& m1501) {
          u64 v_c12 = m1501[1]; u64 v_c335 = m1501[2];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c335, v_c12, v_c13, v_c14, v_c15, v_c16}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1494* _cont = new ReadTask1494(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1494(db,b), false);
  // (crule (pre) (scan eval_ans __t5qy8533 __t9dfl535) (body (exists $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) 1 __t5qy8533) (join-old closure (0 1 2) 1 (0 1 2) __t9dfl535 __t6iPm534 rhoc) (exists extend_env (1 2 3 0) 1 rhoc) (exists $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) 2 __t5qy8533 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t6iPm534 xs eb) (exists $sup70016x51x0x0x1 (4 12 8 1 10 0 2 3 5 6 7 9 11) 4 eb xs rhoc __t5qy8533) (exists eval (1 2 3 0) 1 eb) (join-old extend_env (1 2 3 0) 2 (1 2 3 0) rhoc xs t2 __t5fzh540) (exists tick_ans (1 0) 1 t2) (exists eval (3 1 0 2) 2 t2 eb) (exists extend_env_ans (0 1) 1 __t5fzh540) (join-old $sup70016x51x0x0x1 (4 12 8 1 10 0 2 3 5 6 7 9 11) 5 (4 12 8 1 10 0 2 3 5 6 7 9 11) eb xs rhoc __t5qy8533 t2 __t2z6s532 __t2srV536 __t0CD9539 ef es rho t vs) (join-old $sup70016x51x0x0x0 (4 0 3 1 2) 5 (4 0 3 1 2) t __t2z6s532 rho ef es) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5qy8533 ef) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (exists app (1 2 0) 2 ef es) (exists tick (0 2 1) 2 __t0CD9539 t) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join-old eval_args_ans (0 1) 2 (0 1) __t2srV536 vs) (join-old tick_ans (0 1) 2 (0 1) __t0CD9539 t2) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join-old extend_env_ans (0 1) 2 (0 1) __t5fzh540 __v0) (join-old eval_ans (0 1) 1 (0 1) __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask1544 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x1index1502;  slog::Index** closureindex1503;  slog::Index** extend_envindex1504;  slog::Index** $sup70016x51x0x0x1index1505;  slog::Index** lambdaindex1506;  slog::Index** $sup70016x51x0x0x1index1507;  slog::Index** evalindex1508;  slog::Index** extend_envindex1509;  slog::Index** tick_ansindex1510;  slog::Index** evalindex1511;  slog::Index** extend_env_ansindex1512;  slog::Index** $sup70016x51x0x0x1index1513;  slog::Index** $sup70016x51x0x0x0index1514;  slog::Index** evalindex1515;  slog::Index** eval_argsindex1516;  slog::Index** appindex1517;  slog::Index** tickindex1518;  slog::Index** eval_args_ansindex1519;  slog::Index** tick_ansindex1520;  slog::Index** evalindex1521;  slog::Index** appindex1522;  slog::Index** tickindex1523;  slog::Index** eval_args_ansindex1524;  slog::Index** tick_ansindex1525;  slog::Index** evalindex1526;  slog::Index** extend_env_ansindex1527;  slog::Index** eval_ansindex1528;  slog::Index** closuredelta1529;  slog::Index** lambdadelta1530;  slog::Index** extend_envdelta1531;  slog::Index** $sup70016x51x0x0x1delta1532;  slog::Index** $sup70016x51x0x0x0delta1533;  slog::Index** evaldelta1534;  slog::Index** eval_argsdelta1535;  slog::Index** evaldelta1536;  slog::Index** appdelta1537;  slog::Index** tickdelta1538;  slog::Index** eval_args_ansdelta1539;  slog::Index** tick_ansdelta1540;  slog::Index** evaldelta1541;  slog::Index** extend_env_ansdelta1542;  slog::Index** eval_ansdelta1543;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1545({0, 1});
      slog::Relation* readrel1546 = db->getRelation("eval_ans");
      head_index[0] = readrel1546->getIndex(ord1545, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1547({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel1548 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1502 = readrel1548->getIndex(ord1547, false);
      std::vector<u16> ord1549({0, 1, 2});
      slog::Relation* readrel1550 = db->getRelation("closure");
      closureindex1503 = readrel1550->getIndex(ord1549, false);
      std::vector<u16> ord1551({0, 1, 2});
      slog::Relation* readrel1552 = db->getRelation("closure");
      closuredelta1529 = readrel1552->getIndex(ord1551, true);
      std::vector<u16> ord1553({1, 2, 3, 0});
      slog::Relation* readrel1554 = db->getRelation("extend_env");
      extend_envindex1504 = readrel1554->getIndex(ord1553, false);
      std::vector<u16> ord1555({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel1556 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1505 = readrel1556->getIndex(ord1555, false);
      std::vector<u16> ord1557({0, 1, 2});
      slog::Relation* readrel1558 = db->getRelation("lambda");
      lambdaindex1506 = readrel1558->getIndex(ord1557, false);
      std::vector<u16> ord1559({0, 1, 2});
      slog::Relation* readrel1560 = db->getRelation("lambda");
      lambdadelta1530 = readrel1560->getIndex(ord1559, true);
      std::vector<u16> ord1561({4, 12, 8, 1, 10, 0, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel1562 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1507 = readrel1562->getIndex(ord1561, false);
      std::vector<u16> ord1563({1, 2, 3, 0});
      slog::Relation* readrel1564 = db->getRelation("eval");
      evalindex1508 = readrel1564->getIndex(ord1563, false);
      std::vector<u16> ord1565({1, 2, 3, 0});
      slog::Relation* readrel1566 = db->getRelation("extend_env");
      extend_envindex1509 = readrel1566->getIndex(ord1565, false);
      std::vector<u16> ord1567({1, 2, 3, 0});
      slog::Relation* readrel1568 = db->getRelation("extend_env");
      extend_envdelta1531 = readrel1568->getIndex(ord1567, true);
      std::vector<u16> ord1569({1, 0});
      slog::Relation* readrel1570 = db->getRelation("tick_ans");
      tick_ansindex1510 = readrel1570->getIndex(ord1569, false);
      std::vector<u16> ord1571({3, 1, 0, 2});
      slog::Relation* readrel1572 = db->getRelation("eval");
      evalindex1511 = readrel1572->getIndex(ord1571, false);
      std::vector<u16> ord1573({0, 1});
      slog::Relation* readrel1574 = db->getRelation("extend_env_ans");
      extend_env_ansindex1512 = readrel1574->getIndex(ord1573, false);
      std::vector<u16> ord1575({4, 12, 8, 1, 10, 0, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel1576 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1513 = readrel1576->getIndex(ord1575, false);
      std::vector<u16> ord1577({4, 12, 8, 1, 10, 0, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel1578 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1delta1532 = readrel1578->getIndex(ord1577, true);
      std::vector<u16> ord1579({4, 0, 3, 1, 2});
      slog::Relation* readrel1580 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1514 = readrel1580->getIndex(ord1579, false);
      std::vector<u16> ord1581({4, 0, 3, 1, 2});
      slog::Relation* readrel1582 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0delta1533 = readrel1582->getIndex(ord1581, true);
      std::vector<u16> ord1583({2, 3, 0, 1});
      slog::Relation* readrel1584 = db->getRelation("eval");
      evalindex1515 = readrel1584->getIndex(ord1583, false);
      std::vector<u16> ord1585({2, 3, 0, 1});
      slog::Relation* readrel1586 = db->getRelation("eval");
      evaldelta1534 = readrel1586->getIndex(ord1585, true);
      std::vector<u16> ord1587({3, 2, 0, 1});
      slog::Relation* readrel1588 = db->getRelation("eval_args");
      eval_argsindex1516 = readrel1588->getIndex(ord1587, false);
      std::vector<u16> ord1589({3, 2, 0, 1});
      slog::Relation* readrel1590 = db->getRelation("eval_args");
      eval_argsdelta1535 = readrel1590->getIndex(ord1589, true);
      std::vector<u16> ord1591({1, 2, 0});
      slog::Relation* readrel1592 = db->getRelation("app");
      appindex1517 = readrel1592->getIndex(ord1591, false);
      std::vector<u16> ord1593({0, 2, 1});
      slog::Relation* readrel1594 = db->getRelation("tick");
      tickindex1518 = readrel1594->getIndex(ord1593, false);
      std::vector<u16> ord1595({0, 1});
      slog::Relation* readrel1596 = db->getRelation("eval_args_ans");
      eval_args_ansindex1519 = readrel1596->getIndex(ord1595, false);
      std::vector<u16> ord1597({0, 1});
      slog::Relation* readrel1598 = db->getRelation("tick_ans");
      tick_ansindex1520 = readrel1598->getIndex(ord1597, false);
      std::vector<u16> ord1599({2, 3, 0, 1});
      slog::Relation* readrel1600 = db->getRelation("eval");
      evalindex1521 = readrel1600->getIndex(ord1599, false);
      std::vector<u16> ord1601({2, 3, 0, 1});
      slog::Relation* readrel1602 = db->getRelation("eval");
      evaldelta1536 = readrel1602->getIndex(ord1601, true);
      std::vector<u16> ord1603({0, 1, 2});
      slog::Relation* readrel1604 = db->getRelation("app");
      appindex1522 = readrel1604->getIndex(ord1603, false);
      std::vector<u16> ord1605({0, 1, 2});
      slog::Relation* readrel1606 = db->getRelation("app");
      appdelta1537 = readrel1606->getIndex(ord1605, true);
      std::vector<u16> ord1607({0, 2, 1});
      slog::Relation* readrel1608 = db->getRelation("tick");
      tickindex1523 = readrel1608->getIndex(ord1607, false);
      std::vector<u16> ord1609({0, 2, 1});
      slog::Relation* readrel1610 = db->getRelation("tick");
      tickdelta1538 = readrel1610->getIndex(ord1609, true);
      std::vector<u16> ord1611({0, 1});
      slog::Relation* readrel1612 = db->getRelation("eval_args_ans");
      eval_args_ansindex1524 = readrel1612->getIndex(ord1611, false);
      std::vector<u16> ord1613({0, 1});
      slog::Relation* readrel1614 = db->getRelation("eval_args_ans");
      eval_args_ansdelta1539 = readrel1614->getIndex(ord1613, true);
      std::vector<u16> ord1615({0, 1});
      slog::Relation* readrel1616 = db->getRelation("tick_ans");
      tick_ansindex1525 = readrel1616->getIndex(ord1615, false);
      std::vector<u16> ord1617({0, 1});
      slog::Relation* readrel1618 = db->getRelation("tick_ans");
      tick_ansdelta1540 = readrel1618->getIndex(ord1617, true);
      std::vector<u16> ord1619({3, 1, 0, 2});
      slog::Relation* readrel1620 = db->getRelation("eval");
      evalindex1526 = readrel1620->getIndex(ord1619, false);
      std::vector<u16> ord1621({3, 1, 0, 2});
      slog::Relation* readrel1622 = db->getRelation("eval");
      evaldelta1541 = readrel1622->getIndex(ord1621, true);
      std::vector<u16> ord1623({0, 1});
      slog::Relation* readrel1624 = db->getRelation("extend_env_ans");
      extend_env_ansindex1527 = readrel1624->getIndex(ord1623, false);
      std::vector<u16> ord1625({0, 1});
      slog::Relation* readrel1626 = db->getRelation("extend_env_ans");
      extend_env_ansdelta1542 = readrel1626->getIndex(ord1625, true);
      std::vector<u16> ord1627({0, 1});
      slog::Relation* readrel1628 = db->getRelation("eval_ans");
      eval_ansindex1528 = readrel1628->getIndex(ord1627, false);
      std::vector<u16> ord1629({0, 1});
      slog::Relation* readrel1630 = db->getRelation("eval_ans");
      eval_ansdelta1543 = readrel1630->getIndex(ord1629, true);
  
    }
    ReadTask1544(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c336 = _t[0];
        u64 v_c337 = _t[1];
        if (!slog::exists_probe<13,1>($sup70016x51x0x0x1index1502, std::array<u64,13>{v_c336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(closureindex1503, closuredelta1529, std::array<u64,3>{v_c337, 0, 0}, [&](const std::array<u64,3>& m1631) {
          u64 v_c338 = m1631[1]; u64 v_c203 = m1631[2];
          if (!slog::exists_probe<4,1>(extend_envindex1504, std::array<u64,4>{v_c203, 0, 0, 0})) return;
          if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index1505, std::array<u64,13>{v_c336, v_c203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(lambdaindex1506, lambdadelta1530, std::array<u64,3>{v_c338, 0, 0}, [&](const std::array<u64,3>& m1632) {
            u64 v_c151 = m1632[1]; u64 v_c31 = m1632[2];
            if (!slog::exists_probe<13,4>($sup70016x51x0x0x1index1507, std::array<u64,13>{v_c31, v_c151, v_c203, v_c336, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<4,1>(evalindex1508, std::array<u64,4>{v_c31, 0, 0, 0})) return;
            slog::join_probe_old<4,2>(extend_envindex1509, extend_envdelta1531, std::array<u64,4>{v_c203, v_c151, 0, 0}, [&](const std::array<u64,4>& m1633) {
              u64 v_c213 = m1633[2]; u64 v_c339 = m1633[3];
              if (!slog::exists_probe<2,1>(tick_ansindex1510, std::array<u64,2>{v_c213, 0})) return;
              if (!slog::exists_probe<4,2>(evalindex1511, std::array<u64,4>{v_c213, v_c31, 0, 0})) return;
              if (!slog::exists_probe<2,1>(extend_env_ansindex1512, std::array<u64,2>{v_c339, 0})) return;
              slog::join_probe_old<13,5>($sup70016x51x0x0x1index1513, $sup70016x51x0x0x1delta1532, std::array<u64,13>{v_c31, v_c151, v_c203, v_c336, v_c213, 0, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1634) {
                u64 v_c340 = m1634[5]; u64 v_c341 = m1634[6]; u64 v_c342 = m1634[7]; u64 v_c206 = m1634[8]; u64 v_c209 = m1634[9]; u64 v_c26 = m1634[10]; u64 v_c27 = m1634[11]; u64 v_c212 = m1634[12];
                slog::join_probe_old<5,5>($sup70016x51x0x0x0index1514, $sup70016x51x0x0x0delta1533, std::array<u64,5>{v_c27, v_c340, v_c26, v_c206, v_c209}, [&](const std::array<u64,5>& m1635) {
                  slog::join_probe_old<4,4>(evalindex1515, evaldelta1534, std::array<u64,4>{v_c26, v_c27, v_c336, v_c206}, [&](const std::array<u64,4>& m1636) {
                    slog::join_probe_old<4,4>(eval_argsindex1516, eval_argsdelta1535, std::array<u64,4>{v_c27, v_c26, v_c341, v_c209}, [&](const std::array<u64,4>& m1637) {
                      if (!slog::exists_probe<3,2>(appindex1517, std::array<u64,3>{v_c206, v_c209, 0})) return;
                      if (!slog::exists_probe<3,2>(tickindex1518, std::array<u64,3>{v_c342, v_c27, 0})) return;
                      if (!slog::exists_probe<2,2>(eval_args_ansindex1519, std::array<u64,2>{v_c341, v_c212})) return;
                      if (!slog::exists_probe<2,2>(tick_ansindex1520, std::array<u64,2>{v_c342, v_c213})) return;
                      slog::join_probe_old<4,3>(evalindex1521, evaldelta1536, std::array<u64,4>{v_c26, v_c27, v_c340, 0}, [&](const std::array<u64,4>& m1638) {
                        u64 v_c343 = m1638[3];
                        slog::join_probe_old<3,3>(appindex1522, appdelta1537, std::array<u64,3>{v_c343, v_c206, v_c209}, [&](const std::array<u64,3>& m1639) {
                          slog::join_probe_old<3,3>(tickindex1523, tickdelta1538, std::array<u64,3>{v_c342, v_c27, v_c343}, [&](const std::array<u64,3>& m1640) {
                            slog::join_probe_old<2,2>(eval_args_ansindex1524, eval_args_ansdelta1539, std::array<u64,2>{v_c341, v_c212}, [&](const std::array<u64,2>& m1641) {
                              slog::join_probe_old<2,2>(tick_ansindex1525, tick_ansdelta1540, std::array<u64,2>{v_c342, v_c213}, [&](const std::array<u64,2>& m1642) {
                                slog::join_probe_old<4,2>(evalindex1526, evaldelta1541, std::array<u64,4>{v_c213, v_c31, 0, 0}, [&](const std::array<u64,4>& m1643) {
                                  u64 v_c344 = m1643[2]; u64 v_c92 = m1643[3];
                                  slog::join_probe_old<2,2>(extend_env_ansindex1527, extend_env_ansdelta1542, std::array<u64,2>{v_c339, v_c92}, [&](const std::array<u64,2>& m1644) {
                                    slog::join_probe_old<2,1>(eval_ansindex1528, eval_ansdelta1543, std::array<u64,2>{v_c344, 0}, [&](const std::array<u64,2>& m1645) {
                                      u64 v_c81 = m1645[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c340, v_c81}, std::array<u16,2>{0, 1});
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
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask1544* _cont = new ReadTask1544(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1544(db,b), false);
  // (crule (pre (let _00024sqc250U943 const6b86b273ff34fce19d6b804e) (let _00024sqc6BYS944 const5feceb66ffc86f38d952786c) (let _00024sqc0VjW945 const6b86b273ff34fce19d6b804e) (let _00024sqc8uew946 const5feceb66ffc86f38d952786c) (let _00024sqo2y2x951 const5feceb66ffc86f38d952786c) (let __t6qtm791 (lempty))) (scan eval_args __t7ZV0794 _00024seq0 rho t) (body (letp _00024sql7raK941 (aslst _00024seq0)) (letp e (lref _00024sql7raK941 _00024sqc6BYS944)) (let _00024sqn1wbQ942 (llen _00024sql7raK941)) (cmp ge _00024sqn1wbQ942 _00024sqc250U943) (let _00024sqp9fgp947 (_0002d _00024sqn1wbQ942 _00024sqc8uew946)) (let es (lslice _00024sql7raK941 _00024sqc0VjW945 _00024sqp9fgp947)) (join $sup70016x43x0x0x0 (0 2 3 4 5 1) 6 _00024seq0 e es rho t __t7ZV0794) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2y2x951 e _00024seq0) (exists eval_args (1 3 2 0) 3 es t rho) (join-old eval (1 2 3 0) 3 (1 2 3 0) e rho t __t7vCW795) (exists eval_ans (0 1) 1 __t7vCW795) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t9m2L796) (exists eval_args_ans (0 1) 1 __t9m2L796) (join eval_ans (0 1) 1 __t7vCW795 __v0) (join eval_args_ans (0 1) 1 __t9m2L796 __v1)) (head (emit-temp temp2swd2033 __t6qtm791 __t7ZV0794 __v0 __v1)) interp.slog:44 #f)
  class ReadTask1658 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x43x0x0x0index1646;  slog::Index** $seq_atindex1647;  slog::Index** eval_argsindex1648;  slog::Index** evalindex1649;  slog::Index** eval_ansindex1650;  slog::Index** eval_argsindex1651;  slog::Index** eval_args_ansindex1652;  slog::Index** eval_ansindex1653;  slog::Index** eval_args_ansindex1654;  slog::Index** $seq_atdelta1655;  slog::Index** evaldelta1656;  slog::Index** eval_argsdelta1657;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2swd2033");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord1659({0, 2, 3, 4, 5, 1});
      slog::Relation* readrel1660 = db->getRelation("$sup70016x43x0x0x0");
      $sup70016x43x0x0x0index1646 = readrel1660->getIndex(ord1659, false);
      std::vector<u16> ord1661({1, 0, 2});
      slog::Relation* readrel1662 = db->getRelation("$seq_at");
      $seq_atindex1647 = readrel1662->getIndex(ord1661, false);
      std::vector<u16> ord1663({1, 0, 2});
      slog::Relation* readrel1664 = db->getRelation("$seq_at");
      $seq_atdelta1655 = readrel1664->getIndex(ord1663, true);
      std::vector<u16> ord1665({1, 3, 2, 0});
      slog::Relation* readrel1666 = db->getRelation("eval_args");
      eval_argsindex1648 = readrel1666->getIndex(ord1665, false);
      std::vector<u16> ord1667({1, 2, 3, 0});
      slog::Relation* readrel1668 = db->getRelation("eval");
      evalindex1649 = readrel1668->getIndex(ord1667, false);
      std::vector<u16> ord1669({1, 2, 3, 0});
      slog::Relation* readrel1670 = db->getRelation("eval");
      evaldelta1656 = readrel1670->getIndex(ord1669, true);
      std::vector<u16> ord1671({0, 1});
      slog::Relation* readrel1672 = db->getRelation("eval_ans");
      eval_ansindex1650 = readrel1672->getIndex(ord1671, false);
      std::vector<u16> ord1673({1, 3, 2, 0});
      slog::Relation* readrel1674 = db->getRelation("eval_args");
      eval_argsindex1651 = readrel1674->getIndex(ord1673, false);
      std::vector<u16> ord1675({1, 3, 2, 0});
      slog::Relation* readrel1676 = db->getRelation("eval_args");
      eval_argsdelta1657 = readrel1676->getIndex(ord1675, true);
      std::vector<u16> ord1677({0, 1});
      slog::Relation* readrel1678 = db->getRelation("eval_args_ans");
      eval_args_ansindex1652 = readrel1678->getIndex(ord1677, false);
      std::vector<u16> ord1679({0, 1});
      slog::Relation* readrel1680 = db->getRelation("eval_ans");
      eval_ansindex1653 = readrel1680->getIndex(ord1679, false);
      std::vector<u16> ord1681({0, 1});
      slog::Relation* readrel1682 = db->getRelation("eval_args_ans");
      eval_args_ansindex1654 = readrel1682->getIndex(ord1681, false);
  
    }
    ReadTask1658(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c345 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c346 = v_const5feceb66ffc86f38d952786c;
      u64 v_c347 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c348 = v_const5feceb66ffc86f38d952786c;
      u64 v_c349 = v_const5feceb66ffc86f38d952786c;
      u64 v_c350 = _prim_lempty(db);
      if (v_c350 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c351 = _t[0];
        u64 v_c152 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c27 = _t[3];
        bool ok1683 = true;
        u64 v_c352 = _prim_aslst(db, v_c152, &ok1683);
        if (!ok1683) return;
        bool ok1684 = true;
        u64 v_c19 = _prim_lref(db, v_c352, v_c346, &ok1684);
        if (!ok1684) return;
        u64 v_c353 = _prim_llen(db, v_c352);
        if (v_c353 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        u64 v_c354 = _prim_ge(db, v_c353, v_c345);
        if (v_c354 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        if (!v_c354) return;
        u64 v_c355 = _prim__0002d(db, v_c353, v_c348);
        if (v_c355 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        u64 v_c209 = _prim_lslice(db, v_c352, v_c347, v_c355);
        if (v_c209 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        slog::join_probe<6,6>($sup70016x43x0x0x0index1646, std::array<u64,6>{v_c152, v_c19, v_c209, v_c26, v_c27, v_c351}, [&](const std::array<u64,6>& m1686) {
          slog::join_probe_old<3,3>($seq_atindex1647, $seq_atdelta1655, std::array<u64,3>{v_c349, v_c19, v_c152}, [&](const std::array<u64,3>& m1687) {
            if (!slog::exists_probe<4,3>(eval_argsindex1648, std::array<u64,4>{v_c209, v_c27, v_c26, 0})) return;
            slog::join_probe_old<4,3>(evalindex1649, evaldelta1656, std::array<u64,4>{v_c19, v_c26, v_c27, 0}, [&](const std::array<u64,4>& m1688) {
              u64 v_c356 = m1688[3];
              if (!slog::exists_probe<2,1>(eval_ansindex1650, std::array<u64,2>{v_c356, 0})) return;
              slog::join_probe_old<4,3>(eval_argsindex1651, eval_argsdelta1657, std::array<u64,4>{v_c209, v_c27, v_c26, 0}, [&](const std::array<u64,4>& m1689) {
                u64 v_c357 = m1689[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1652, std::array<u64,2>{v_c357, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1653, std::array<u64,2>{v_c356, 0}, [&](const std::array<u64,2>& m1690) {
                  u64 v_c92 = m1690[1];
                  slog::join_probe<2,1>(eval_args_ansindex1654, std::array<u64,2>{v_c357, 0}, [&](const std::array<u64,2>& m1691) {
                    u64 v_c107 = m1691[1];
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c350, v_c351, v_c92, v_c107});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask1658* _cont = new ReadTask1658(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1658(db,b), false);
  // (crule (pre) (scan mp_join __t8BsD696 p __t1ouF694 q __t1a8C695) (body (exists mbranch (0 1 2 3 4) 2 __t1ouF694 p) (exists mbranch (0 1 2 3 4) 2 __t1a8C695 q) (exists mp_union (1 2 0) 2 __t1ouF694 __t1a8C695) (exists mp_msk (1 2 0) 1 q) (exists mp_join_ans (0 1) 1 __t8BsD696) (join $sup5638x101x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 p q __t1ouF694 __t1a8C695 __t5awj693 l m n r u v) (cmp lt n m) (join mbranch (1 2 3 4 0) 5 p m l r __t1ouF694) (join mbranch (1 2 3 4 0) 5 q n u v __t1a8C695) (join mp_union (0 1 2) 3 __t5awj693 __t1ouF694 __t1a8C695) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t84wf697) (join mp_msk_ans (0 1) 1 __t84wf697 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t8BsD696 res)) (head (emit mp_union_ans (0 1) __t5awj693 res)) map.slog:102 #f)
  class ReadTask1705 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1692;  slog::Index** mbranchindex1693;  slog::Index** mp_unionindex1694;  slog::Index** mp_mskindex1695;  slog::Index** mp_join_ansindex1696;  slog::Index** $sup5638x101x0x0x0index1697;  slog::Index** mbranchindex1698;  slog::Index** mbranchindex1699;  slog::Index** mp_unionindex1700;  slog::Index** mp_mskindex1701;  slog::Index** mp_msk_ansindex1702;  slog::Index** mp_join_ansindex1703;  slog::Index** mp_mskdelta1704;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1706({0, 1});
      slog::Relation* readrel1707 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1707->getIndex(ord1706, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord1708({0, 1, 2, 3, 4});
      slog::Relation* readrel1709 = db->getRelation("mbranch");
      mbranchindex1692 = readrel1709->getIndex(ord1708, false);
      std::vector<u16> ord1710({0, 1, 2, 3, 4});
      slog::Relation* readrel1711 = db->getRelation("mbranch");
      mbranchindex1693 = readrel1711->getIndex(ord1710, false);
      std::vector<u16> ord1712({1, 2, 0});
      slog::Relation* readrel1713 = db->getRelation("mp_union");
      mp_unionindex1694 = readrel1713->getIndex(ord1712, false);
      std::vector<u16> ord1714({1, 2, 0});
      slog::Relation* readrel1715 = db->getRelation("mp_msk");
      mp_mskindex1695 = readrel1715->getIndex(ord1714, false);
      std::vector<u16> ord1716({0, 1});
      slog::Relation* readrel1717 = db->getRelation("mp_join_ans");
      mp_join_ansindex1696 = readrel1717->getIndex(ord1716, false);
      std::vector<u16> ord1718({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel1719 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index1697 = readrel1719->getIndex(ord1718, false);
      std::vector<u16> ord1720({1, 2, 3, 4, 0});
      slog::Relation* readrel1721 = db->getRelation("mbranch");
      mbranchindex1698 = readrel1721->getIndex(ord1720, false);
      std::vector<u16> ord1722({1, 2, 3, 4, 0});
      slog::Relation* readrel1723 = db->getRelation("mbranch");
      mbranchindex1699 = readrel1723->getIndex(ord1722, false);
      std::vector<u16> ord1724({0, 1, 2});
      slog::Relation* readrel1725 = db->getRelation("mp_union");
      mp_unionindex1700 = readrel1725->getIndex(ord1724, false);
      std::vector<u16> ord1726({1, 2, 0});
      slog::Relation* readrel1727 = db->getRelation("mp_msk");
      mp_mskindex1701 = readrel1727->getIndex(ord1726, false);
      std::vector<u16> ord1728({1, 2, 0});
      slog::Relation* readrel1729 = db->getRelation("mp_msk");
      mp_mskdelta1704 = readrel1729->getIndex(ord1728, true);
      std::vector<u16> ord1730({0, 1});
      slog::Relation* readrel1731 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1702 = readrel1731->getIndex(ord1730, false);
      std::vector<u16> ord1732({0, 1});
      slog::Relation* readrel1733 = db->getRelation("mp_join_ans");
      mp_join_ansindex1703 = readrel1733->getIndex(ord1732, false);
  
    }
    ReadTask1705(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c314 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c312 = _t[2];
        u64 v_c79 = _t[3];
        u64 v_c313 = _t[4];
        if (!slog::exists_probe<5,2>(mbranchindex1692, std::array<u64,5>{v_c312, v_c15, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mbranchindex1693, std::array<u64,5>{v_c313, v_c79, 0, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mp_unionindex1694, std::array<u64,3>{v_c312, v_c313, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1695, std::array<u64,3>{v_c79, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex1696, std::array<u64,2>{v_c314, 0})) return;
        slog::join_probe<11,4>($sup5638x101x0x0x0index1697, std::array<u64,11>{v_c15, v_c79, v_c312, v_c313, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1734) {
          u64 v_c311 = m1734[4]; u64 v_c13 = m1734[5]; u64 v_c14 = m1734[6]; u64 v_c78 = m1734[7]; u64 v_c16 = m1734[8]; u64 v_c80 = m1734[9]; u64 v_c81 = m1734[10];
          u64 v_c358 = _prim_lt(db, v_c78, v_c14);
          if (v_c358 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
          if (!v_c358) return;
          slog::join_probe<5,5>(mbranchindex1698, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, v_c312}, [&](const std::array<u64,5>& m1736) {
            slog::join_probe<5,5>(mbranchindex1699, std::array<u64,5>{v_c79, v_c78, v_c80, v_c81, v_c313}, [&](const std::array<u64,5>& m1737) {
              slog::join_probe<3,3>(mp_unionindex1700, std::array<u64,3>{v_c311, v_c312, v_c313}, [&](const std::array<u64,3>& m1738) {
                slog::join_probe_old<3,2>(mp_mskindex1701, mp_mskdelta1704, std::array<u64,3>{v_c79, v_c14, 0}, [&](const std::array<u64,3>& m1739) {
                  u64 v_c316 = m1739[2];
                  slog::join_probe<2,1>(mp_msk_ansindex1702, std::array<u64,2>{v_c316, 0}, [&](const std::array<u64,2>& m1740) {
                    u64 v_c92 = m1740[1];
                    if (v_c15 == v_c92) return;
                    slog::join_probe<2,1>(mp_join_ansindex1703, std::array<u64,2>{v_c314, 0}, [&](const std::array<u64,2>& m1741) {
                      u64 v_c95 = m1741[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c311, v_c95}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask1705* _cont = new ReadTask1705(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1705(db,b), false);
  // (crule (pre (let __tconst6I9K760 constd59eced1ded07f84c145592f) (let __tconst7lpr731 const0933fb667296882d8c45abca) (let __tconst1Nf0752 const90fb9068eda6f2d68bb61c33)) (scan temp6XDA1901 __t0esl751 __t2X4e744 __t3uI9730 __t5xOK723 __t75NQ757 __t8k6P758) (body (exists app (2 0 1) 1 __t0esl751) (exists primref (1 0) 1 __tconst7lpr731) (exists app (2 0 1) 1 __t3uI9730) (exists ref (1 0) 1 __tconst6I9K760) (join primref (1 0) 1 __tconst1Nf0752 __t6Asn753) (join app (1 2 0) 2 __t6Asn753 __t0esl751 __t1WhI754) (join primref (1 0) 1 __tconst7lpr731 __t1nv4732) (join app (1 2 0) 2 __t1nv4732 __t3uI9730 __t55Nx733) (join ref (1 0) 1 __tconst6I9K760 __t9NO9722) (let __t5Neo735 (lpush __t75NQ757 __t55Nx733))) (head (emit-temp temp1ppH1902 __t1WhI754 __t2X4e744 __t5Neo735 __t5xOK723 __t8k6P758)) kcfa.slog:70 #f)
  class ReadTask1751 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1742;  slog::Index** primrefindex1743;  slog::Index** appindex1744;  slog::Index** refindex1745;  slog::Index** primrefindex1746;  slog::Index** appindex1747;  slog::Index** primrefindex1748;  slog::Index** appindex1749;  slog::Index** refindex1750;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1ppH1902");
      outer_rel = db->getRelation("temp6XDA1901");
      std::vector<u16> ord1752({2, 0, 1});
      slog::Relation* readrel1753 = db->getRelation("app");
      appindex1742 = readrel1753->getIndex(ord1752, false);
      std::vector<u16> ord1754({1, 0});
      slog::Relation* readrel1755 = db->getRelation("primref");
      primrefindex1743 = readrel1755->getIndex(ord1754, false);
      std::vector<u16> ord1756({2, 0, 1});
      slog::Relation* readrel1757 = db->getRelation("app");
      appindex1744 = readrel1757->getIndex(ord1756, false);
      std::vector<u16> ord1758({1, 0});
      slog::Relation* readrel1759 = db->getRelation("ref");
      refindex1745 = readrel1759->getIndex(ord1758, false);
      std::vector<u16> ord1760({1, 0});
      slog::Relation* readrel1761 = db->getRelation("primref");
      primrefindex1746 = readrel1761->getIndex(ord1760, false);
      std::vector<u16> ord1762({1, 2, 0});
      slog::Relation* readrel1763 = db->getRelation("app");
      appindex1747 = readrel1763->getIndex(ord1762, false);
      std::vector<u16> ord1764({1, 0});
      slog::Relation* readrel1765 = db->getRelation("primref");
      primrefindex1748 = readrel1765->getIndex(ord1764, false);
      std::vector<u16> ord1766({1, 2, 0});
      slog::Relation* readrel1767 = db->getRelation("app");
      appindex1749 = readrel1767->getIndex(ord1766, false);
      std::vector<u16> ord1768({1, 0});
      slog::Relation* readrel1769 = db->getRelation("ref");
      refindex1750 = readrel1769->getIndex(ord1768, false);
  
    }
    ReadTask1751(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c304 = v_constd59eced1ded07f84c145592f;
      u64 v_c359 = v_const0933fb667296882d8c45abca;
      u64 v_c360 = v_const90fb9068eda6f2d68bb61c33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c361 = _t[0];
        u64 v_c362 = _t[1];
        u64 v_c363 = _t[2];
        u64 v_c305 = _t[3];
        u64 v_c364 = _t[4];
        u64 v_c307 = _t[5];
        if (!slog::exists_probe<3,1>(appindex1742, std::array<u64,3>{v_c361, 0, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex1743, std::array<u64,2>{v_c359, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1744, std::array<u64,3>{v_c363, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1745, std::array<u64,2>{v_c304, 0})) return;
        slog::join_probe<2,1>(primrefindex1746, std::array<u64,2>{v_c360, 0}, [&](const std::array<u64,2>& m1770) {
          u64 v_c365 = m1770[1];
          slog::join_probe<3,2>(appindex1747, std::array<u64,3>{v_c365, v_c361, 0}, [&](const std::array<u64,3>& m1771) {
            u64 v_c366 = m1771[2];
            slog::join_probe<2,1>(primrefindex1748, std::array<u64,2>{v_c359, 0}, [&](const std::array<u64,2>& m1772) {
              u64 v_c367 = m1772[1];
              slog::join_probe<3,2>(appindex1749, std::array<u64,3>{v_c367, v_c363, 0}, [&](const std::array<u64,3>& m1773) {
                u64 v_c368 = m1773[2];
                slog::join_probe<2,1>(refindex1750, std::array<u64,2>{v_c304, 0}, [&](const std::array<u64,2>& m1774) {
                  u64 v_c369 = m1774[1];
                  u64 v_c370 = _prim_lpush(db, v_c364, v_c368);
                  if (v_c370 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:70"); return; }
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c366, v_c362, v_c370, v_c305, v_c307});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:70", "delta:temp6XDA1901", _fires);
  
      if (!_done)
      {
        ReadTask1751* _cont = new ReadTask1751(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1751(db,b), false);
  // (crule (pre) (scan select_branch __t7CcU1 tv e2 e3) (body (join scheme_false (0) 0 fv) (neq tv fv)) (head (emit select_branch_ans (0 1) __t7CcU1 e2)) interp.slog:86 #f)
  class ReadTask1776 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** scheme_falseindex1775;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord1777({0, 1});
      slog::Relation* readrel1778 = db->getRelation("select_branch_ans");
      head_index[0] = readrel1778->getIndex(ord1777, false);
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord1779({0});
      slog::Relation* readrel1780 = db->getRelation("scheme_false");
      scheme_falseindex1775 = readrel1780->getIndex(ord1779, false);
  
    }
    ReadTask1776(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c371 = _t[0];
        u64 v_c372 = _t[1];
        u64 v_c373 = _t[2];
        u64 v_c374 = _t[3];
        slog::join_all<1>(scheme_falseindex1775, [&](const std::array<u64,1>& m1781) {
          u64 v_c188 = m1781[0];
          if (v_c372 == v_c188) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c371, v_c373}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:86", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask1776* _cont = new ReadTask1776(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1776(db,b), false);
  // (crule (pre (let __tconst2rWb405 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t5Upj404 __t1qjI403 k) (body (join mbranch (0 1 2 3 4) 1 __t1qjI403 p m l r) (let __t4jzF406 (band k m)) (cmp gt __t4jzF406 __tconst2rWb405)) (head (emit $sup5638x62x0x0x0 (4 2 3 5 0 1) p l m r __t5Upj404 k)) map.slog:63 #f)
  class ReadTask1783 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1782;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord1784({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1785 = db->getRelation("$sup5638x62x0x0x0");
      head_index[0] = readrel1785->getIndex(ord1784, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord1786({0, 1, 2, 3, 4});
      slog::Relation* readrel1787 = db->getRelation("mbranch");
      mbranchindex1782 = readrel1787->getIndex(ord1786, false);
  
    }
    ReadTask1783(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c375 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c376 = _t[0];
        u64 v_c377 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe<5,1>(mbranchindex1782, std::array<u64,5>{v_c377, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1788) {
          u64 v_c15 = m1788[1]; u64 v_c14 = m1788[2]; u64 v_c13 = m1788[3]; u64 v_c16 = m1788[4];
          u64 v_c378 = _prim_band(db, v_c12, v_c14);
          if (v_c378 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
          u64 v_c379 = _prim_gt(db, v_c378, v_c375);
          if (v_c379 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
          if (!v_c379) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c15, v_c13, v_c14, v_c16, v_c376, v_c12}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask1783* _cont = new ReadTask1783(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1783(db,b), false);
  // (crule (pre (let __tconst5SF3829 const5feceb66ffc86f38d952786c)) (scan mp_hsb_ans __t6kiQ828 __v0) (body (join-old mp_hsb (0 1) 1 (0 1) __t6kiQ828 __t9t7u827) (join $sup5638x29x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t4k7L830 (band p0 __v0)) (cmp gt __t4k7L830 __tconst5SF3829) (let chk3clT2031 (bxor p0 p1)) (eq __t9t7u827 chk3clT2031)) (head (emit $sup5638x29x0x0x1 (1 2 0 3 4 5 6) __t6kiQ828 __v0 __d0 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask1793 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsbindex1790;  slog::Index** $sup5638x29x0x0x0index1791;  slog::Index** mp_hsbdelta1792;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord1794({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1795 = db->getRelation("$sup5638x29x0x0x1");
      head_index[0] = readrel1795->getIndex(ord1794, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord1796({0, 1});
      slog::Relation* readrel1797 = db->getRelation("mp_hsb");
      mp_hsbindex1790 = readrel1797->getIndex(ord1796, false);
      std::vector<u16> ord1798({0, 1});
      slog::Relation* readrel1799 = db->getRelation("mp_hsb");
      mp_hsbdelta1792 = readrel1799->getIndex(ord1798, true);
      std::vector<u16> ord1800({1, 0, 2, 3, 4});
      slog::Relation* readrel1801 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index1791 = readrel1801->getIndex(ord1800, false);
  
    }
    ReadTask1793(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c380 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c381 = _t[0];
        u64 v_c92 = _t[1];
        slog::join_probe_old<2,1>(mp_hsbindex1790, mp_hsbdelta1792, std::array<u64,2>{v_c381, 0}, [&](const std::array<u64,2>& m1802) {
          u64 v_c382 = m1802[1];
          slog::join_all<5>($sup5638x29x0x0x0index1791, [&](const std::array<u64,5>& m1803) {
            u64 v_c100 = m1803[0]; u64 v_c11 = m1803[1]; u64 v_c102 = m1803[2]; u64 v_c101 = m1803[3]; u64 v_c103 = m1803[4];
            u64 v_c383 = _prim_band(db, v_c100, v_c92);
            if (v_c383 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            u64 v_c384 = _prim_gt(db, v_c383, v_c380);
            if (v_c384 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (!v_c384) return;
            u64 v_c385 = _prim_bxor(db, v_c100, v_c102);
            if (v_c385 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (v_c382 != v_c385) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c381, v_c92, v_c11, v_c100, v_c102, v_c101, v_c103}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1793* _cont = new ReadTask1793(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1793(db,b), false);
  // (crule (pre (let __tconst8wBL581 const5feceb66ffc86f38d952786c)) (scan $sup5638x59x0x0x0 __t8lWf583 k l m p r) (body (exists mp_has0 (0 2 1) 2 __t8lWf583 k) (exists mp_msk (1 2 0) 2 k m) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0T68582) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t8lWf583 k __t0T68582) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t7zc5584) (join mp_msk_ans (0 1) 1 __t7zc5584 __v0) (neq p __v0)) (head (emit mp_has0_ans (0 1) __t8lWf583 __tconst8wBL581)) map.slog:60 #f)
  class ReadTask1814 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index1805;  slog::Index** mp_mskindex1806;  slog::Index** mbranchindex1807;  slog::Index** mp_has0index1808;  slog::Index** mp_mskindex1809;  slog::Index** mp_msk_ansindex1810;  slog::Index** mbranchdelta1811;  slog::Index** mp_has0delta1812;  slog::Index** mp_mskdelta1813;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1815({0, 1});
      slog::Relation* readrel1816 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1816->getIndex(ord1815, false);
      outer_rel = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord1817({0, 2, 1});
      slog::Relation* readrel1818 = db->getRelation("mp_has0");
      mp_has0index1805 = readrel1818->getIndex(ord1817, false);
      std::vector<u16> ord1819({1, 2, 0});
      slog::Relation* readrel1820 = db->getRelation("mp_msk");
      mp_mskindex1806 = readrel1820->getIndex(ord1819, false);
      std::vector<u16> ord1821({1, 2, 3, 4, 0});
      slog::Relation* readrel1822 = db->getRelation("mbranch");
      mbranchindex1807 = readrel1822->getIndex(ord1821, false);
      std::vector<u16> ord1823({1, 2, 3, 4, 0});
      slog::Relation* readrel1824 = db->getRelation("mbranch");
      mbranchdelta1811 = readrel1824->getIndex(ord1823, true);
      std::vector<u16> ord1825({0, 2, 1});
      slog::Relation* readrel1826 = db->getRelation("mp_has0");
      mp_has0index1808 = readrel1826->getIndex(ord1825, false);
      std::vector<u16> ord1827({0, 2, 1});
      slog::Relation* readrel1828 = db->getRelation("mp_has0");
      mp_has0delta1812 = readrel1828->getIndex(ord1827, true);
      std::vector<u16> ord1829({1, 2, 0});
      slog::Relation* readrel1830 = db->getRelation("mp_msk");
      mp_mskindex1809 = readrel1830->getIndex(ord1829, false);
      std::vector<u16> ord1831({1, 2, 0});
      slog::Relation* readrel1832 = db->getRelation("mp_msk");
      mp_mskdelta1813 = readrel1832->getIndex(ord1831, true);
      std::vector<u16> ord1833({0, 1});
      slog::Relation* readrel1834 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1810 = readrel1834->getIndex(ord1833, false);
  
    }
    ReadTask1814(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c386 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c387 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c16 = _t[5];
        if (!slog::exists_probe<3,2>(mp_has0index1805, std::array<u64,3>{v_c387, v_c12, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex1806, std::array<u64,3>{v_c12, v_c14, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex1807, mbranchdelta1811, std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, 0}, [&](const std::array<u64,5>& m1835) {
          u64 v_c388 = m1835[4];
          slog::join_probe_old<3,3>(mp_has0index1808, mp_has0delta1812, std::array<u64,3>{v_c387, v_c12, v_c388}, [&](const std::array<u64,3>& m1836) {
            slog::join_probe_old<3,2>(mp_mskindex1809, mp_mskdelta1813, std::array<u64,3>{v_c12, v_c14, 0}, [&](const std::array<u64,3>& m1837) {
              u64 v_c389 = m1837[2];
              slog::join_probe<2,1>(mp_msk_ansindex1810, std::array<u64,2>{v_c389, 0}, [&](const std::array<u64,2>& m1838) {
                u64 v_c92 = m1838[1];
                if (v_c15 == v_c92) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c387, v_c386}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:$sup5638x59x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1814* _cont = new ReadTask1814(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1814(db,b), false);
  // (crule (pre (let __tconst81hP570 const5feceb66ffc86f38d952786c)) (scan mbranch __t01On568 p m l r) (body (join-old mp_put (1 2 3 0) 1 (1 2 3 0) __t01On568 k v __t05Ld569) (let __t62ag571 (band k m)) (cmp gt __t62ag571 __tconst81hP570)) (head (emit $sup5638x42x0x0x0 (4 2 3 5 0 1 6) p l m r __t05Ld569 k v)) map.slog:43 #f)
  class ReadTask1841 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex1839;  slog::Index** mp_putdelta1840;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord1842({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1843 = db->getRelation("$sup5638x42x0x0x0");
      head_index[0] = readrel1843->getIndex(ord1842, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1844({1, 2, 3, 0});
      slog::Relation* readrel1845 = db->getRelation("mp_put");
      mp_putindex1839 = readrel1845->getIndex(ord1844, false);
      std::vector<u16> ord1846({1, 2, 3, 0});
      slog::Relation* readrel1847 = db->getRelation("mp_put");
      mp_putdelta1840 = readrel1847->getIndex(ord1846, true);
  
    }
    ReadTask1841(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c390 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c391 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c16 = _t[4];
        slog::join_probe_old<4,1>(mp_putindex1839, mp_putdelta1840, std::array<u64,4>{v_c391, 0, 0, 0}, [&](const std::array<u64,4>& m1848) {
          u64 v_c12 = m1848[1]; u64 v_c81 = m1848[2]; u64 v_c392 = m1848[3];
          u64 v_c393 = _prim_band(db, v_c12, v_c14);
          if (v_c393 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
          u64 v_c394 = _prim_gt(db, v_c393, v_c390);
          if (v_c394 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
          if (!v_c394) return;
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c15, v_c13, v_c14, v_c16, v_c392, v_c12, v_c81}, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1841* _cont = new ReadTask1841(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1841(db,b), false);
}

