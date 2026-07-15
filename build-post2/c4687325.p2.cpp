
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1951517e1abb2be9513ac082;
extern u64 v_const1dfd44c904fe1b3630c7e748;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const8cfcf41991382923e0d7fd17;
extern u64 v_constba2df4903a2c14e86dc3bcca;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdef8bc82d3dca227c973a765;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;


void slog_rules_c325adc56f5b1b123(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst6E5W191 constef2d127de37b942baad06145) (let __tconst8ZVp189 const4e07408562bedb8b60ce05c1) (let __tconst62dH187 const4a44dc15364204a80fe80e90) (let __tconst1tfz185 constf5ca38f748a1d6eaf726b8a4)) (seeded) (body (join ic (1 0) 1 __tconst62dH187 __t4UHo184) (exists ic (1 0) 1 __tconst8ZVp189) (exists ic (1 0) 1 __tconst6E5W191) (join ic (1 0) 1 __tconst1tfz185 __t3VVz186) (join ic (1 0) 1 __tconst8ZVp189 __t17DP190) (exists lgt (2 1 0) 1 __t17DP190) (join ic (1 0) 1 __tconst6E5W191 __t3PaA192) (join lgt (2 1 0) 2 __t17DP190 __t3PaA192 __t7bbY193)) (head (mkstruct lite (2 3 1 0) __t1kp3194 __t4UHo184 __t3VVz186 __t7bbY193)) smt_sets.slog:23 #f)
  class ReadTask8 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex0;  slog::Index** icindex1;  slog::Index** icindex2;  slog::Index** icindex3;  slog::Index** icindex4;  slog::Index** lgtindex5;  slog::Index** icindex6;  slog::Index** lgtindex7;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lite");
      std::vector<u16> ord9({2, 3, 1, 0});
      slog::Relation* readrel10 = db->getRelation("lite");
      head_index[0] = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({1, 0});
      slog::Relation* readrel12 = db->getRelation("ic");
      icindex0 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({1, 0});
      slog::Relation* readrel14 = db->getRelation("ic");
      icindex1 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({1, 0});
      slog::Relation* readrel16 = db->getRelation("ic");
      icindex2 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 0});
      slog::Relation* readrel18 = db->getRelation("ic");
      icindex3 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("ic");
      icindex4 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({2, 1, 0});
      slog::Relation* readrel22 = db->getRelation("lgt");
      lgtindex5 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 0});
      slog::Relation* readrel24 = db->getRelation("ic");
      icindex6 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({2, 1, 0});
      slog::Relation* readrel26 = db->getRelation("lgt");
      lgtindex7 = readrel26->getIndex(ord25, false);
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const4a44dc15364204a80fe80e90;
      u64 v_c3 = v_constf5ca38f748a1d6eaf726b8a4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex0, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m27) {
        u64 v_c4 = m27[1];
        if (!slog::exists_probe<2,1>(icindex1, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(icindex2, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(icindex3, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m28) {
          u64 v_c5 = m28[1];
          slog::join_probe<2,1>(icindex4, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m29) {
            u64 v_c6 = m29[1];
            if (!slog::exists_probe<3,1>(lgtindex5, std::array<u64,3>{v_c6, 0, 0})) return;
            slog::join_probe<2,1>(icindex6, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m30) {
              u64 v_c7 = m30[1];
              slog::join_probe<3,2>(lgtindex7, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m31) {
                u64 v_c8 = m31[2];
                ++_fires;
                slog::emit_struct_checked<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c4, v_c5, v_c8}, std::array<u16,4>{2, 3, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:23", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask8(db,b));
  // (crule (pre (let __tconst6E5W191 constef2d127de37b942baad06145) (let __tconst8ZVp189 const4e07408562bedb8b60ce05c1) (let __tconst62dH187 const4a44dc15364204a80fe80e90) (let __tconst1tfz185 constf5ca38f748a1d6eaf726b8a4)) (once) (body) (head (mkstruct ic (1 0) __t3PaA192 __tconst6E5W191) (mkstruct ic (1 0) __t17DP190 __tconst8ZVp189) (mkstruct ic (1 0) __t3VVz186 __tconst1tfz185) (mkstruct ic (1 0) __t4UHo184 __tconst62dH187)) smt_sets.slog:23 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
      head_rel[3] = db->getRelation("ic");
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const4a44dc15364204a80fe80e90;
      u64 v_c3 = v_constf5ca38f748a1d6eaf726b8a4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("smt_sets.slog:23", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask32(db,b), true);
  // (crule (pre) (scan temp5uEq400 __t4TUW244) (body (join lany (1 0) 1 __t4TUW244 __t7SGz245)) (head (mkstruct smt_check (1 0) __3pjS283 __t7SGz245)) smt_sets.slog:22 #f)
  class ReadTask34 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lanyindex33;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("temp5uEq400");
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("lany");
      lanyindex33 = readrel36->getIndex(ord35, false);
  
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
        u64 v_c9 = _t[0];
        slog::join_probe<2,1>(lanyindex33, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m37) {
          u64 v_c10 = m37[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c10}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:22", "delta:temp5uEq400", _fires);
  
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
  // (crule (pre (let __trid8bds284 const8cfcf41991382923e0d7fd17) (let __trel01iV285 constdef8bc82d3dca227c973a765) (let __tcol4T49286 const5feceb66ffc86f38d952786c)) (scan temp17I6399 __t4TUW244) (body) (head (tycheck __t4TUW244 (accept cnode) __trid8bds284 __trel01iV285 __tcol4T49286 (1 2 3 4 0)) (emit-temp temp5uEq400 __t4TUW244) (mkstruct lany (1 0) __t7SGz245 __t4TUW244)) smt_sets.slog:22 #f)
  class ReadTask38 : public slog::Task
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
      head_rel[1] = db->getRelation("temp5uEq400");
      head_rel[2] = db->getRelation("lany");
      outer_rel = db->getRelation("temp17I6399");
  
    }
    ReadTask38(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_const8cfcf41991382923e0d7fd17;
      u64 v_c12 = v_constdef8bc82d3dca227c973a765;
      u64 v_c13 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c9 = _t[0];
        ++_fires;
        if (!(is_cnode(v_c9)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c11, v_c12, v_c13, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<1>(head_rel[1], newbatch[1], std::array<u64,1>{v_c9});
        slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c9}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:22", "delta:temp17I6399", _fires);
  
      if (!_done)
      {
        ReadTask38* _cont = new ReadTask38(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask38(db,b), false);
  // (crule (pre (let __tconst3YP6144 constd4735e3a265e16eee03f5971) (let __tconst0J7X139 const6b86b273ff34fce19d6b804e)) (scan temp06Hk373 __t5vnO147) (body (exists ic (1 0) 1 __tconst0J7X139) (join ic (1 0) 1 __tconst3YP6144 __t6QYl138) (join ic (1 0) 1 __tconst0J7X139 __t6CXY140)) (head (emit-temp temp8ai2374 __t5vnO147) (mkstruct lle (1 2 0) __t6Q1F146 __t6QYl138 __t6QYl138) (mkstruct llt (1 2 0) __t6viR141 __t6CXY140 __t6QYl138)) smt_sets.slog:11 #f)
  class ReadTask42 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex39;  slog::Index** icindex40;  slog::Index** icindex41;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8ai2374");
      head_rel[1] = db->getRelation("lle");
      head_rel[2] = db->getRelation("llt");
      outer_rel = db->getRelation("temp06Hk373");
      std::vector<u16> ord43({1, 0});
      slog::Relation* readrel44 = db->getRelation("ic");
      icindex39 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 0});
      slog::Relation* readrel46 = db->getRelation("ic");
      icindex40 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 0});
      slog::Relation* readrel48 = db->getRelation("ic");
      icindex41 = readrel48->getIndex(ord47, false);
  
    }
    ReadTask42(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c16 = _t[0];
        if (!slog::exists_probe<2,1>(icindex39, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<2,1>(icindex40, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m49) {
          u64 v_c17 = m49[1];
          slog::join_probe<2,1>(icindex41, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m50) {
            u64 v_c18 = m50[1];
            ++_fires;
            slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c16});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c17, v_c17}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c18, v_c17}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:11", "delta:temp06Hk373", _fires);
  
      if (!_done)
      {
        ReadTask42* _cont = new ReadTask42(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask42(db,b), false);
  // (crule (pre (let __tconst1NZm92 constba2df4903a2c14e86dc3bcca) (let __tconst60I490 const4e07408562bedb8b60ce05c1) (let __tconst7hzd87 const6b86b273ff34fce19d6b804e) (let __tconst9GyQ85 constd4735e3a265e16eee03f5971) (let __t7tqw95 (cmap))) (once) (body) (head (emit-temp temp2BuW389 __t7tqw95) (mkstruct iv (1 0) __t6QR393 __tconst1NZm92) (mkstruct ic (1 0) __t4MDF91 __tconst60I490) (mkstruct ic (1 0) __t7qEk88 __tconst7hzd87) (mkstruct ic (1 0) __t18po86 __tconst9GyQ85)) smt_sets.slog:19 #f)
  class ReadTask51 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2BuW389");
      head_rel[1] = db->getRelation("iv");
      head_rel[2] = db->getRelation("ic");
      head_rel[3] = db->getRelation("ic");
      head_rel[4] = db->getRelation("ic");
  
    }
    ReadTask51(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c19 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c20 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c21 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c22 = v_constd4735e3a265e16eee03f5971;
      u64 v_c23 = _prim_cmap(db);
      if (v_c23 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:19"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c19}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c21}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("smt_sets.slog:19", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask51(db,b), true);
  // (crule (pre (let __tconst62dH187 const4a44dc15364204a80fe80e90) (let __tconst1tfz185 constf5ca38f748a1d6eaf726b8a4) (let __tconst6E5W191 constef2d127de37b942baad06145) (let __tconst8ZVp189 const4e07408562bedb8b60ce05c1)) (seeded) (body (join ic (1 0) 1 __tconst62dH187 __t4UHo184) (exists lite (2 3 1 0) 1 __t4UHo184) (exists ic (1 0) 1 __tconst8ZVp189) (exists ic (1 0) 1 __tconst6E5W191) (join ic (1 0) 1 __tconst1tfz185 __t3VVz186) (join lite (2 3 1 0) 2 __t4UHo184 __t3VVz186 __t7bbY193 __t1kp3194) (join ic (1 0) 1 __tconst8ZVp189 __t17DP190) (join lgt (0 2 1) 2 __t7bbY193 __t17DP190 __t3PaA192) (join ic (0 1) 2 __t3PaA192 __tconst6E5W191)) (head (mkstruct leq (2 1 0) __t8St0195 __t4UHo184 __t1kp3194)) smt_sets.slog:23 #f)
  class ReadTask61 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex52;  slog::Index** liteindex53;  slog::Index** icindex54;  slog::Index** icindex55;  slog::Index** icindex56;  slog::Index** liteindex57;  slog::Index** icindex58;  slog::Index** lgtindex59;  slog::Index** icindex60;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("leq");
      std::vector<u16> ord62({2, 1, 0});
      slog::Relation* readrel63 = db->getRelation("leq");
      head_index[0] = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 0});
      slog::Relation* readrel65 = db->getRelation("ic");
      icindex52 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({2, 3, 1, 0});
      slog::Relation* readrel67 = db->getRelation("lite");
      liteindex53 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 0});
      slog::Relation* readrel69 = db->getRelation("ic");
      icindex54 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 0});
      slog::Relation* readrel71 = db->getRelation("ic");
      icindex55 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 0});
      slog::Relation* readrel73 = db->getRelation("ic");
      icindex56 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({2, 3, 1, 0});
      slog::Relation* readrel75 = db->getRelation("lite");
      liteindex57 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 0});
      slog::Relation* readrel77 = db->getRelation("ic");
      icindex58 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({0, 2, 1});
      slog::Relation* readrel79 = db->getRelation("lgt");
      lgtindex59 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({0, 1});
      slog::Relation* readrel81 = db->getRelation("ic");
      icindex60 = readrel81->getIndex(ord80, false);
  
    }
    ReadTask61(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const4a44dc15364204a80fe80e90;
      u64 v_c3 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex52, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m82) {
        u64 v_c4 = m82[1];
        if (!slog::exists_probe<4,1>(liteindex53, std::array<u64,4>{v_c4, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(icindex54, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(icindex55, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(icindex56, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m83) {
          u64 v_c5 = m83[1];
          slog::join_probe<4,2>(liteindex57, std::array<u64,4>{v_c4, v_c5, 0, 0}, [&](const std::array<u64,4>& m84) {
            u64 v_c8 = m84[2]; u64 v_c24 = m84[3];
            slog::join_probe<2,1>(icindex58, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m85) {
              u64 v_c6 = m85[1];
              slog::join_probe<3,2>(lgtindex59, std::array<u64,3>{v_c8, v_c6, 0}, [&](const std::array<u64,3>& m86) {
                u64 v_c7 = m86[2];
                slog::join_probe<2,2>(icindex60, std::array<u64,2>{v_c7, v_c0}, [&](const std::array<u64,2>& m87) {
                  ++_fires;
                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c24}, std::array<u16,3>{2, 1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:23", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask61(db,b));
  // (crule (pre) (scan temp80WG388 __t9gMk242) (body (join lall (1 0) 1 __t9gMk242 __t84sZ243)) (head (mkstruct smt_check (1 0) __7joD274 __t84sZ243)) smt_sets.slog:13 #f)
  class ReadTask89 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex88;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("temp80WG388");
      std::vector<u16> ord90({1, 0});
      slog::Relation* readrel91 = db->getRelation("lall");
      lallindex88 = readrel91->getIndex(ord90, false);
  
    }
    ReadTask89(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(lallindex88, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m92) {
          u64 v_c26 = m92[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c26}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:13", "delta:temp80WG388", _fires);
  
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
  // (crule (pre) (scan modulo_by_zero __erre30If341 __errf54hR342 __errf7WbU343) (body) (head (emit error (0) __erre30If341)) <internal>:1 #f)
  class ReadTask93 : public slog::Task
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
      std::vector<u16> ord94({0});
      slog::Relation* readrel95 = db->getRelation("error");
      head_index[0] = readrel95->getIndex(ord94, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask93(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask93* _cont = new ReadTask93(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask93(db,b), false);
  // (crule (pre (let __tconst0FTz237 const6b86b273ff34fce19d6b804e) (let __tconst7UvL235 constd4735e3a265e16eee03f5971)) (scan temp4cMz386 __t7J7n241) (body (exists ic (1 0) 1 __tconst0FTz237) (join ic (1 0) 1 __tconst7UvL235 __t189l231) (exists llt (2 0 1) 1 __t189l231) (join ic (1 0) 1 __tconst0FTz237 __t4UmM233) (join llt (1 2 0) 2 __t4UmM233 __t189l231 __t3nYN234) (let __t9gMk242 (cins __t7J7n241 __t3nYN234))) (head (emit-temp temp4d4S387 __t9gMk242)) smt_sets.slog:13 #f)
  class ReadTask101 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex96;  slog::Index** icindex97;  slog::Index** lltindex98;  slog::Index** icindex99;  slog::Index** lltindex100;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4d4S387");
      outer_rel = db->getRelation("temp4cMz386");
      std::vector<u16> ord102({1, 0});
      slog::Relation* readrel103 = db->getRelation("ic");
      icindex96 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 0});
      slog::Relation* readrel105 = db->getRelation("ic");
      icindex97 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({2, 0, 1});
      slog::Relation* readrel107 = db->getRelation("llt");
      lltindex98 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 0});
      slog::Relation* readrel109 = db->getRelation("ic");
      icindex99 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 2, 0});
      slog::Relation* readrel111 = db->getRelation("llt");
      lltindex100 = readrel111->getIndex(ord110, false);
  
    }
    ReadTask101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c31 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c32 = _t[0];
        if (!slog::exists_probe<2,1>(icindex96, std::array<u64,2>{v_c30, 0})) return;
        slog::join_probe<2,1>(icindex97, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m112) {
          u64 v_c33 = m112[1];
          if (!slog::exists_probe<3,1>(lltindex98, std::array<u64,3>{v_c33, 0, 0})) return;
          slog::join_probe<2,1>(icindex99, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m113) {
            u64 v_c34 = m113[1];
            slog::join_probe<3,2>(lltindex100, std::array<u64,3>{v_c34, v_c33, 0}, [&](const std::array<u64,3>& m114) {
              u64 v_c35 = m114[2];
              u64 v_c25 = _prim_cins(db, v_c32, v_c35);
              if (v_c25 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:13"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c25});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:13", "delta:temp4cMz386", _fires);
  
      if (!_done)
      {
        ReadTask101* _cont = new ReadTask101(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask101(db,b), false);
  // (crule (pre (let __trid6UES289 const1951517e1abb2be9513ac082) (let __trel6Ag8290 const1dfd44c904fe1b3630c7e748) (let __tcol3Eq8291 const5feceb66ffc86f38d952786c)) (scan temp8zkG401 __t1C2822) (body) (head (tycheck __t1C2822 (accept cnode) __trid6UES289 __trel6Ag8290 __tcol3Eq8291 (1 2 3 4 0)) (emit-temp temp1JQm402 __t1C2822) (mkstruct lall (1 0) __t6wAP23 __t1C2822)) smt_sets.slog:21 #f)
  class ReadTask115 : public slog::Task
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
      head_rel[1] = db->getRelation("temp1JQm402");
      head_rel[2] = db->getRelation("lall");
      outer_rel = db->getRelation("temp8zkG401");
  
    }
    ReadTask115(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const1951517e1abb2be9513ac082;
      u64 v_c37 = v_const1dfd44c904fe1b3630c7e748;
      u64 v_c38 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c39 = _t[0];
        ++_fires;
        if (!(is_cnode(v_c39)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c36, v_c37, v_c38, v_c39}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<1>(head_rel[1], newbatch[1], std::array<u64,1>{v_c39});
        slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c39}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:21", "delta:temp8zkG401", _fires);
  
      if (!_done)
      {
        ReadTask115* _cont = new ReadTask115(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask115(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre2TJK360 __errf4RIQ361 __errf5cZ9362 __errf8Pg9363 __errf93q0364) (body) (head (emit error (0) __erre2TJK360)) <internal>:1 #f)
  class ReadTask116 : public slog::Task
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
      std::vector<u16> ord117({0});
      slog::Relation* readrel118 = db->getRelation("error");
      head_index[0] = readrel118->getIndex(ord117, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c40 = _t[0];
        u64 v_c41 = _t[1];
        u64 v_c42 = _t[2];
        u64 v_c43 = _t[3];
        u64 v_c44 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c40}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask116* _cont = new ReadTask116(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask116(db,b), false);
  // (crule (pre (let __tconst7g7f15 const6b86b273ff34fce19d6b804e)) (scan temp7kgo406 __t8EzS13) (body) (head (emit-temp temp6aCd407 __t8EzS13) (mkstruct lall (1 0) __t3Jkz14 __t8EzS13)) smt_sets.slog:30 #f)
  class ReadTask119 : public slog::Task
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
      head_rel[0] = db->getRelation("temp6aCd407");
      head_rel[1] = db->getRelation("lall");
      outer_rel = db->getRelation("temp7kgo406");
  
    }
    ReadTask119(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c46 = _t[0];
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c46});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c46}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_sets.slog:30", "delta:temp7kgo406", _fires);
  
      if (!_done)
      {
        ReadTask119* _cont = new ReadTask119(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask119(db,b), false);
  // (crule (pre (let __tconst0JQ048 constba2df4903a2c14e86dc3bcca) (let __tconst3CQF46 const4e07408562bedb8b60ce05c1) (let __tconst9NiH43 const6b86b273ff34fce19d6b804e) (let __tconst1ejW41 constd4735e3a265e16eee03f5971)) (scan temp4NJZ368 __t4rBU51) (body (exists ic (1 0) 1 __tconst9NiH43) (exists ic (1 0) 1 __tconst3CQF46) (exists iv (1 0) 1 __tconst0JQ048) (join ic (1 0) 1 __tconst1ejW41 __t0b2d42) (join ic (1 0) 1 __tconst9NiH43 __t4FA344) (join ic (1 0) 1 __tconst3CQF46 __t2w9L47) (join iv (1 0) 1 __tconst0JQ048 __t09gB49)) (head (emit-temp temp8q48369 __t4rBU51) (mkstruct llt (1 2 0) __t79yX50 __t09gB49 __t2w9L47) (mkstruct lgt (2 1 0) __t9ypF45 __t0b2d42 __t4FA344)) smt_sets.slog:15 #f)
  class ReadTask127 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex120;  slog::Index** icindex121;  slog::Index** ivindex122;  slog::Index** icindex123;  slog::Index** icindex124;  slog::Index** icindex125;  slog::Index** ivindex126;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8q48369");
      head_rel[1] = db->getRelation("llt");
      head_rel[2] = db->getRelation("lgt");
      outer_rel = db->getRelation("temp4NJZ368");
      std::vector<u16> ord128({1, 0});
      slog::Relation* readrel129 = db->getRelation("ic");
      icindex120 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("ic");
      icindex121 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("iv");
      ivindex122 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("ic");
      icindex123 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0});
      slog::Relation* readrel137 = db->getRelation("ic");
      icindex124 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 0});
      slog::Relation* readrel139 = db->getRelation("ic");
      icindex125 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 0});
      slog::Relation* readrel141 = db->getRelation("iv");
      ivindex126 = readrel141->getIndex(ord140, false);
  
    }
    ReadTask127(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c48 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c49 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c50 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c51 = _t[0];
        if (!slog::exists_probe<2,1>(icindex120, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<2,1>(icindex121, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex122, std::array<u64,2>{v_c47, 0})) return;
        slog::join_probe<2,1>(icindex123, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m142) {
          u64 v_c52 = m142[1];
          slog::join_probe<2,1>(icindex124, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m143) {
            u64 v_c53 = m143[1];
            slog::join_probe<2,1>(icindex125, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m144) {
              u64 v_c54 = m144[1];
              slog::join_probe<2,1>(ivindex126, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m145) {
                u64 v_c55 = m145[1];
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c51});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c55, v_c54}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c52, v_c53}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:15", "delta:temp4NJZ368", _fires);
  
      if (!_done)
      {
        ReadTask127* _cont = new ReadTask127(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask127(db,b), false);
  // (crule (pre (let __tconst0FTz237 const6b86b273ff34fce19d6b804e) (let __tconst7UvL235 constd4735e3a265e16eee03f5971) (let __t1p79240 (cmap))) (once) (body) (head (emit-temp temp368G384 __t1p79240) (mkstruct ic (1 0) __t4UmM233 __tconst0FTz237) (mkstruct ic (1 0) __t189l231 __tconst7UvL235)) smt_sets.slog:13 #f)
  class ReadTask146 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp368G384");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
  
    }
    ReadTask146(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c31 = v_constd4735e3a265e16eee03f5971;
      u64 v_c56 = _prim_cmap(db);
      if (v_c56 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:13"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c56});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c30}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c31}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:13", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask146(db,b), true);
  // (crule (pre (let __tconst0FTz237 const6b86b273ff34fce19d6b804e) (let __tconst7UvL235 constd4735e3a265e16eee03f5971)) (scan temp368G384 __t1p79240) (body (exists ic (1 0) 1 __tconst0FTz237) (join ic (1 0) 1 __tconst7UvL235 __t189l231) (join ic (1 0) 1 __tconst0FTz237 __t4UmM233)) (head (emit-temp temp6VVM385 __t1p79240) (mkstruct lgt (2 1 0) __t85IX239 __t189l231 __t4UmM233) (mkstruct llt (1 2 0) __t3nYN234 __t4UmM233 __t189l231)) smt_sets.slog:13 #f)
  class ReadTask150 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex147;  slog::Index** icindex148;  slog::Index** icindex149;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6VVM385");
      head_rel[1] = db->getRelation("lgt");
      head_rel[2] = db->getRelation("llt");
      outer_rel = db->getRelation("temp368G384");
      std::vector<u16> ord151({1, 0});
      slog::Relation* readrel152 = db->getRelation("ic");
      icindex147 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 0});
      slog::Relation* readrel154 = db->getRelation("ic");
      icindex148 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 0});
      slog::Relation* readrel156 = db->getRelation("ic");
      icindex149 = readrel156->getIndex(ord155, false);
  
    }
    ReadTask150(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c31 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c56 = _t[0];
        if (!slog::exists_probe<2,1>(icindex147, std::array<u64,2>{v_c30, 0})) return;
        slog::join_probe<2,1>(icindex148, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m157) {
          u64 v_c33 = m157[1];
          slog::join_probe<2,1>(icindex149, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m158) {
            u64 v_c34 = m158[1];
            ++_fires;
            slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c56});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c33, v_c34}, std::array<u16,3>{2, 1, 0});
            slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c34, v_c33}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:13", "delta:temp368G384", _fires);
  
      if (!_done)
      {
        ReadTask150* _cont = new ReadTask150(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask150(db,b), false);
  // (crule (pre (let __tconst3LHf114 constba2df4903a2c14e86dc3bcca) (let __tconst9tZn112 const4e07408562bedb8b60ce05c1) (let __tconst0Nfc109 const6b86b273ff34fce19d6b804e) (let __tconst8Oey107 constd4735e3a265e16eee03f5971)) (scan temp52Or379 __t4064117) (body (exists ic (1 0) 1 __tconst0Nfc109) (exists ic (1 0) 1 __tconst9tZn112) (exists iv (1 0) 1 __tconst3LHf114) (join ic (1 0) 1 __tconst8Oey107 __t0S7L108) (join ic (1 0) 1 __tconst0Nfc109 __t9WV8110) (join ic (1 0) 1 __tconst9tZn112 __t09fp113) (join iv (1 0) 1 __tconst3LHf114 __t8A6J115)) (head (emit-temp temp7V3r380 __t4064117) (mkstruct llt (1 2 0) __t3haz116 __t8A6J115 __t09fp113) (mkstruct llt (1 2 0) __t6HC4111 __t9WV8110 __t0S7L108)) smt_sets.slog:17 #f)
  class ReadTask166 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex159;  slog::Index** icindex160;  slog::Index** ivindex161;  slog::Index** icindex162;  slog::Index** icindex163;  slog::Index** icindex164;  slog::Index** ivindex165;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7V3r380");
      head_rel[1] = db->getRelation("llt");
      head_rel[2] = db->getRelation("llt");
      outer_rel = db->getRelation("temp52Or379");
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("ic");
      icindex159 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 0});
      slog::Relation* readrel170 = db->getRelation("ic");
      icindex160 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 0});
      slog::Relation* readrel172 = db->getRelation("iv");
      ivindex161 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 0});
      slog::Relation* readrel174 = db->getRelation("ic");
      icindex162 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 0});
      slog::Relation* readrel176 = db->getRelation("ic");
      icindex163 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 0});
      slog::Relation* readrel178 = db->getRelation("ic");
      icindex164 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 0});
      slog::Relation* readrel180 = db->getRelation("iv");
      ivindex165 = readrel180->getIndex(ord179, false);
  
    }
    ReadTask166(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c58 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c59 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c60 = v_constd4735e3a265e16eee03f5971;
  
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
        if (!slog::exists_probe<2,1>(icindex159, std::array<u64,2>{v_c59, 0})) return;
        if (!slog::exists_probe<2,1>(icindex160, std::array<u64,2>{v_c58, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex161, std::array<u64,2>{v_c57, 0})) return;
        slog::join_probe<2,1>(icindex162, std::array<u64,2>{v_c60, 0}, [&](const std::array<u64,2>& m181) {
          u64 v_c62 = m181[1];
          slog::join_probe<2,1>(icindex163, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m182) {
            u64 v_c63 = m182[1];
            slog::join_probe<2,1>(icindex164, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m183) {
              u64 v_c64 = m183[1];
              slog::join_probe<2,1>(ivindex165, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m184) {
                u64 v_c65 = m184[1];
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c61});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c65, v_c64}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c63, v_c62}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:17", "delta:temp52Or379", _fires);
  
      if (!_done)
      {
        ReadTask166* _cont = new ReadTask166(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask166(db,b), false);
  // (crule (pre (let __tconst0JQ048 constba2df4903a2c14e86dc3bcca) (let __tconst3CQF46 const4e07408562bedb8b60ce05c1) (let __tconst9NiH43 const6b86b273ff34fce19d6b804e) (let __tconst1ejW41 constd4735e3a265e16eee03f5971) (let __t4rBU51 (cmap))) (once) (body) (head (emit-temp temp4NJZ368 __t4rBU51) (mkstruct iv (1 0) __t09gB49 __tconst0JQ048) (mkstruct ic (1 0) __t2w9L47 __tconst3CQF46) (mkstruct ic (1 0) __t4FA344 __tconst9NiH43) (mkstruct ic (1 0) __t0b2d42 __tconst1ejW41)) smt_sets.slog:15 #f)
  class ReadTask185 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4NJZ368");
      head_rel[1] = db->getRelation("iv");
      head_rel[2] = db->getRelation("ic");
      head_rel[3] = db->getRelation("ic");
      head_rel[4] = db->getRelation("ic");
  
    }
    ReadTask185(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c48 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c49 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c50 = v_constd4735e3a265e16eee03f5971;
      u64 v_c51 = _prim_cmap(db);
      if (v_c51 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:15"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c51});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c47}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c48}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c49}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c50}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("smt_sets.slog:15", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask185(db,b), true);
  // (crule (pre (let __tconst6j65260 constd4735e3a265e16eee03f5971)) (scan temp6YoG397 __t2TSq258) (body) (head (emit-temp temp52TS398 __t2TSq258) (mkstruct lall (1 0) __t5BqU259 __t2TSq258)) smt_sets.slog:31 #f)
  class ReadTask186 : public slog::Task
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
      head_rel[0] = db->getRelation("temp52TS398");
      head_rel[1] = db->getRelation("lall");
      outer_rel = db->getRelation("temp6YoG397");
  
    }
    ReadTask186(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c67 = _t[0];
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c67});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c67}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_sets.slog:31", "delta:temp6YoG397", _fires);
  
      if (!_done)
      {
        ReadTask186* _cont = new ReadTask186(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask186(db,b), false);
  // (crule (pre) (scan int_overflow __erre6h68344 __errf458u345 __errf0OBp346 __errf5Wap347) (body) (head (emit error (0) __erre6h68344)) <internal>:1 #f)
  class ReadTask187 : public slog::Task
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
      std::vector<u16> ord188({0});
      slog::Relation* readrel189 = db->getRelation("error");
      head_index[0] = readrel189->getIndex(ord188, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask187(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c69 = _t[1];
        u64 v_c70 = _t[2];
        u64 v_c71 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c68}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask187* _cont = new ReadTask187(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask187(db,b), false);
  // (crule (pre (let __tconst6E5W191 constef2d127de37b942baad06145) (let __tconst8ZVp189 const4e07408562bedb8b60ce05c1) (let __tconst62dH187 const4a44dc15364204a80fe80e90) (let __tconst1tfz185 constf5ca38f748a1d6eaf726b8a4)) (probe ic (1 0) 1 __tconst62dH187 __t4UHo184) (body (exists ic (1 0) 1 __tconst8ZVp189) (exists ic (1 0) 1 __tconst6E5W191) (join ic (1 0) 1 __tconst1tfz185 __t3VVz186) (join ic (1 0) 1 __tconst8ZVp189 __t17DP190) (join ic (1 0) 1 __tconst6E5W191 __t3PaA192)) (head (mkstruct lgt (2 1 0) __t7bbY193 __t17DP190 __t3PaA192)) smt_sets.slog:23 #f)
  class ReadTask195 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex190;  slog::Index** icindex191;  slog::Index** icindex192;  slog::Index** icindex193;  slog::Index** icindex194;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lgt");
      std::vector<u16> ord196({1, 0});
      slog::Relation* readrel197 = db->getRelation("ic");
      driver_index = readrel197->getIndex(ord196, true);
      std::vector<u16> ord198({1, 0});
      slog::Relation* readrel199 = db->getRelation("ic");
      icindex190 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 0});
      slog::Relation* readrel201 = db->getRelation("ic");
      icindex191 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({1, 0});
      slog::Relation* readrel203 = db->getRelation("ic");
      icindex192 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 0});
      slog::Relation* readrel205 = db->getRelation("ic");
      icindex193 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 0});
      slog::Relation* readrel207 = db->getRelation("ic");
      icindex194 = readrel207->getIndex(ord206, false);
  
    }
    ReadTask195(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const4a44dc15364204a80fe80e90;
      u64 v_c3 = v_constf5ca38f748a1d6eaf726b8a4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c2, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m208) {
        u64 v_c4 = m208[1];
        if (buckethash(v_c4) != bucket) return;
        if (!slog::exists_probe<2,1>(icindex190, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(icindex191, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(icindex192, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m209) {
          u64 v_c5 = m209[1];
          slog::join_probe<2,1>(icindex193, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m210) {
            u64 v_c6 = m210[1];
            slog::join_probe<2,1>(icindex194, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m211) {
              u64 v_c7 = m211[1];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c6, v_c7}, std::array<u16,3>{2, 1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:23", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask195* _cont = new ReadTask195(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask195(db,b), false);
  // (crule (pre (let __tconst3LHf114 constba2df4903a2c14e86dc3bcca) (let __tconst9tZn112 const4e07408562bedb8b60ce05c1) (let __tconst0Nfc109 const6b86b273ff34fce19d6b804e) (let __tconst8Oey107 constd4735e3a265e16eee03f5971) (let __t4064117 (cmap))) (once) (body) (head (emit-temp temp52Or379 __t4064117) (mkstruct iv (1 0) __t8A6J115 __tconst3LHf114) (mkstruct ic (1 0) __t09fp113 __tconst9tZn112) (mkstruct ic (1 0) __t9WV8110 __tconst0Nfc109) (mkstruct ic (1 0) __t0S7L108 __tconst8Oey107)) smt_sets.slog:17 #f)
  class ReadTask212 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp52Or379");
      head_rel[1] = db->getRelation("iv");
      head_rel[2] = db->getRelation("ic");
      head_rel[3] = db->getRelation("ic");
      head_rel[4] = db->getRelation("ic");
  
    }
    ReadTask212(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c58 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c59 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c60 = v_constd4735e3a265e16eee03f5971;
      u64 v_c61 = _prim_cmap(db);
      if (v_c61 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:17"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c61});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c57}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c58}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c59}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c60}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("smt_sets.slog:17", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask212(db,b), true);
  // (crule (pre (let __tconst1NZm92 constba2df4903a2c14e86dc3bcca) (let __tconst60I490 const4e07408562bedb8b60ce05c1) (let __tconst7hzd87 const6b86b273ff34fce19d6b804e) (let __tconst9GyQ85 constd4735e3a265e16eee03f5971)) (scan temp2BuW389 __t7tqw95) (body (exists ic (1 0) 1 __tconst7hzd87) (exists ic (1 0) 1 __tconst60I490) (exists iv (1 0) 1 __tconst1NZm92) (join ic (1 0) 1 __tconst9GyQ85 __t18po86) (join ic (1 0) 1 __tconst7hzd87 __t7qEk88) (join ic (1 0) 1 __tconst60I490 __t4MDF91) (join iv (1 0) 1 __tconst1NZm92 __t6QR393)) (head (emit-temp temp0ETM390 __t7tqw95) (mkstruct llt (1 2 0) __t0PPB94 __t6QR393 __t4MDF91) (mkstruct llt (1 2 0) __t3YQQ89 __t7qEk88 __t18po86)) smt_sets.slog:19 #f)
  class ReadTask220 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex213;  slog::Index** icindex214;  slog::Index** ivindex215;  slog::Index** icindex216;  slog::Index** icindex217;  slog::Index** icindex218;  slog::Index** ivindex219;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0ETM390");
      head_rel[1] = db->getRelation("llt");
      head_rel[2] = db->getRelation("llt");
      outer_rel = db->getRelation("temp2BuW389");
      std::vector<u16> ord221({1, 0});
      slog::Relation* readrel222 = db->getRelation("ic");
      icindex213 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 0});
      slog::Relation* readrel224 = db->getRelation("ic");
      icindex214 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 0});
      slog::Relation* readrel226 = db->getRelation("iv");
      ivindex215 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 0});
      slog::Relation* readrel228 = db->getRelation("ic");
      icindex216 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 0});
      slog::Relation* readrel230 = db->getRelation("ic");
      icindex217 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 0});
      slog::Relation* readrel232 = db->getRelation("ic");
      icindex218 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 0});
      slog::Relation* readrel234 = db->getRelation("iv");
      ivindex219 = readrel234->getIndex(ord233, false);
  
    }
    ReadTask220(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c19 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c20 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c21 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c22 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c23 = _t[0];
        if (!slog::exists_probe<2,1>(icindex213, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(icindex214, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex215, std::array<u64,2>{v_c19, 0})) return;
        slog::join_probe<2,1>(icindex216, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m235) {
          u64 v_c72 = m235[1];
          slog::join_probe<2,1>(icindex217, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m236) {
            u64 v_c73 = m236[1];
            slog::join_probe<2,1>(icindex218, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m237) {
              u64 v_c74 = m237[1];
              slog::join_probe<2,1>(ivindex219, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m238) {
                u64 v_c75 = m238[1];
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c75, v_c74}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c73, v_c72}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:19", "delta:temp2BuW389", _fires);
  
      if (!_done)
      {
        ReadTask220* _cont = new ReadTask220(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask220(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre5JrJ333 __errf0GKV334 __errf89ej335 __errf9cZ1336 __errf7zZR337) (body) (head (emit error (0) __erre5JrJ333)) <internal>:1 #f)
  class ReadTask239 : public slog::Task
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
      std::vector<u16> ord240({0});
      slog::Relation* readrel241 = db->getRelation("error");
      head_index[0] = readrel241->getIndex(ord240, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask239(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c76 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c78 = _t[2];
        u64 v_c79 = _t[3];
        u64 v_c80 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c76}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask239* _cont = new ReadTask239(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask239(db,b), false);
  // (crule (pre (let __tconst3YP6144 constd4735e3a265e16eee03f5971) (let __tconst0J7X139 const6b86b273ff34fce19d6b804e)) (scan temp9C8t375 __t3P3r148) (body (exists ic (1 0) 1 __tconst0J7X139) (join ic (1 0) 1 __tconst3YP6144 __t6QYl138) (exists llt (2 0 1) 1 __t6QYl138) (join ic (1 0) 1 __tconst0J7X139 __t6CXY140) (join llt (1 2 0) 2 __t6CXY140 __t6QYl138 __t6viR141) (let __t1I4R149 (cins __t3P3r148 __t6viR141))) (head (emit-temp temp77Ij376 __t1I4R149)) smt_sets.slog:11 #f)
  class ReadTask247 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex242;  slog::Index** icindex243;  slog::Index** lltindex244;  slog::Index** icindex245;  slog::Index** lltindex246;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp77Ij376");
      outer_rel = db->getRelation("temp9C8t375");
      std::vector<u16> ord248({1, 0});
      slog::Relation* readrel249 = db->getRelation("ic");
      icindex242 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 0});
      slog::Relation* readrel251 = db->getRelation("ic");
      icindex243 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({2, 0, 1});
      slog::Relation* readrel253 = db->getRelation("llt");
      lltindex244 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 0});
      slog::Relation* readrel255 = db->getRelation("ic");
      icindex245 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 2, 0});
      slog::Relation* readrel257 = db->getRelation("llt");
      lltindex246 = readrel257->getIndex(ord256, false);
  
    }
    ReadTask247(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
      u64 v_c15 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c81 = _t[0];
        if (!slog::exists_probe<2,1>(icindex242, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<2,1>(icindex243, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m258) {
          u64 v_c17 = m258[1];
          if (!slog::exists_probe<3,1>(lltindex244, std::array<u64,3>{v_c17, 0, 0})) return;
          slog::join_probe<2,1>(icindex245, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m259) {
            u64 v_c18 = m259[1];
            slog::join_probe<3,2>(lltindex246, std::array<u64,3>{v_c18, v_c17, 0}, [&](const std::array<u64,3>& m260) {
              u64 v_c82 = m260[2];
              u64 v_c83 = _prim_cins(db, v_c81, v_c82);
              if (v_c83 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:11"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c83});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:11", "delta:temp9C8t375", _fires);
  
      if (!_done)
      {
        ReadTask247* _cont = new ReadTask247(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask247(db,b), false);
  // (crule (pre (let __tconst7g7f15 const6b86b273ff34fce19d6b804e) (let __tconst8Eqn1 constd4735e3a265e16eee03f5971) (let __tconst1Wl16 const4b227777d4dd1fc61c6f884f) (let __tconst5ETt8 const4e07408562bedb8b60ce05c1)) (scan temp8oBi404 __t0JBY11) (body (exists ic (1 0) 1 __tconst1Wl16) (exists ic (1 0) 1 __tconst7g7f15) (exists ic (1 0) 1 __tconst8Eqn1) (join ic (1 0) 1 __tconst5ETt8 __t4gzu9) (exists lne (1 2 0) 1 __t4gzu9) (join ic (1 0) 1 __tconst1Wl16 __t6hlX7) (join lne (1 2 0) 2 __t4gzu9 __t6hlX7 __t3A4I10) (join ic (1 0) 1 __tconst7g7f15 __t05u84) (exists llt (1 2 0) 1 __t05u84) (join ic (1 0) 1 __tconst8Eqn1 __t2Lgc2) (join llt (1 2 0) 2 __t05u84 __t2Lgc2 __t1OA85) (let __t9hQe12 (cins __t0JBY11 __t3A4I10))) (head (emit-temp temp2RCa405 __t9hQe12)) smt_sets.slog:30 #f)
  class ReadTask272 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex261;  slog::Index** icindex262;  slog::Index** icindex263;  slog::Index** icindex264;  slog::Index** lneindex265;  slog::Index** icindex266;  slog::Index** lneindex267;  slog::Index** icindex268;  slog::Index** lltindex269;  slog::Index** icindex270;  slog::Index** lltindex271;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2RCa405");
      outer_rel = db->getRelation("temp8oBi404");
      std::vector<u16> ord273({1, 0});
      slog::Relation* readrel274 = db->getRelation("ic");
      icindex261 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({1, 0});
      slog::Relation* readrel276 = db->getRelation("ic");
      icindex262 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 0});
      slog::Relation* readrel278 = db->getRelation("ic");
      icindex263 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({1, 0});
      slog::Relation* readrel280 = db->getRelation("ic");
      icindex264 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 2, 0});
      slog::Relation* readrel282 = db->getRelation("lne");
      lneindex265 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 0});
      slog::Relation* readrel284 = db->getRelation("ic");
      icindex266 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({1, 2, 0});
      slog::Relation* readrel286 = db->getRelation("lne");
      lneindex267 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 0});
      slog::Relation* readrel288 = db->getRelation("ic");
      icindex268 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 2, 0});
      slog::Relation* readrel290 = db->getRelation("llt");
      lltindex269 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 0});
      slog::Relation* readrel292 = db->getRelation("ic");
      icindex270 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 2, 0});
      slog::Relation* readrel294 = db->getRelation("llt");
      lltindex271 = readrel294->getIndex(ord293, false);
  
    }
    ReadTask272(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c84 = v_constd4735e3a265e16eee03f5971;
      u64 v_c85 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c86 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c87 = _t[0];
        if (!slog::exists_probe<2,1>(icindex261, std::array<u64,2>{v_c85, 0})) return;
        if (!slog::exists_probe<2,1>(icindex262, std::array<u64,2>{v_c45, 0})) return;
        if (!slog::exists_probe<2,1>(icindex263, std::array<u64,2>{v_c84, 0})) return;
        slog::join_probe<2,1>(icindex264, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m295) {
          u64 v_c88 = m295[1];
          if (!slog::exists_probe<3,1>(lneindex265, std::array<u64,3>{v_c88, 0, 0})) return;
          slog::join_probe<2,1>(icindex266, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m296) {
            u64 v_c89 = m296[1];
            slog::join_probe<3,2>(lneindex267, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m297) {
              u64 v_c90 = m297[2];
              slog::join_probe<2,1>(icindex268, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m298) {
                u64 v_c91 = m298[1];
                if (!slog::exists_probe<3,1>(lltindex269, std::array<u64,3>{v_c91, 0, 0})) return;
                slog::join_probe<2,1>(icindex270, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m299) {
                  u64 v_c92 = m299[1];
                  slog::join_probe<3,2>(lltindex271, std::array<u64,3>{v_c91, v_c92, 0}, [&](const std::array<u64,3>& m300) {
                    u64 v_c93 = m300[2];
                    u64 v_c94 = _prim_cins(db, v_c87, v_c90);
                    if (v_c94 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:30"); return; }
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c94});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:30", "delta:temp8oBi404", _fires);
  
      if (!_done)
      {
        ReadTask272* _cont = new ReadTask272(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask272(db,b), false);
  // (crule (pre (let __tconst62dH187 const4a44dc15364204a80fe80e90) (let __tconst1tfz185 constf5ca38f748a1d6eaf726b8a4) (let __tconst6E5W191 constef2d127de37b942baad06145) (let __tconst8ZVp189 const4e07408562bedb8b60ce05c1)) (scan leq __t8St0195 __t1kp3194 __t4UHo184) (body (join ic (0 1) 2 __t4UHo184 __tconst62dH187) (exists ic (1 0) 1 __tconst1tfz185) (exists ic (1 0) 1 __tconst8ZVp189) (exists ic (1 0) 1 __tconst6E5W191) (join lite (0 2 1 3) 2 __t1kp3194 __t4UHo184 __t7bbY193 __t3VVz186) (join ic (0 1) 2 __t3VVz186 __tconst1tfz185) (join ic (1 0) 1 __tconst8ZVp189 __t17DP190) (join lgt (0 2 1) 2 __t7bbY193 __t17DP190 __t3PaA192) (join ic (0 1) 2 __t3PaA192 __tconst6E5W191)) (head (mkstruct smt_check (1 0) __0Bnp266 __t8St0195)) smt_sets.slog:23 #f)
  class ReadTask310 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex301;  slog::Index** icindex302;  slog::Index** icindex303;  slog::Index** icindex304;  slog::Index** liteindex305;  slog::Index** icindex306;  slog::Index** icindex307;  slog::Index** lgtindex308;  slog::Index** icindex309;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("leq");
      std::vector<u16> ord311({0, 1});
      slog::Relation* readrel312 = db->getRelation("ic");
      icindex301 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 0});
      slog::Relation* readrel314 = db->getRelation("ic");
      icindex302 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 0});
      slog::Relation* readrel316 = db->getRelation("ic");
      icindex303 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 0});
      slog::Relation* readrel318 = db->getRelation("ic");
      icindex304 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({0, 2, 1, 3});
      slog::Relation* readrel320 = db->getRelation("lite");
      liteindex305 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({0, 1});
      slog::Relation* readrel322 = db->getRelation("ic");
      icindex306 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({1, 0});
      slog::Relation* readrel324 = db->getRelation("ic");
      icindex307 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({0, 2, 1});
      slog::Relation* readrel326 = db->getRelation("lgt");
      lgtindex308 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({0, 1});
      slog::Relation* readrel328 = db->getRelation("ic");
      icindex309 = readrel328->getIndex(ord327, false);
  
    }
    ReadTask310(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const4a44dc15364204a80fe80e90;
      u64 v_c3 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c95 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe<2,2>(icindex301, std::array<u64,2>{v_c4, v_c2}, [&](const std::array<u64,2>& m329) {
          if (!slog::exists_probe<2,1>(icindex302, std::array<u64,2>{v_c3, 0})) return;
          if (!slog::exists_probe<2,1>(icindex303, std::array<u64,2>{v_c1, 0})) return;
          if (!slog::exists_probe<2,1>(icindex304, std::array<u64,2>{v_c0, 0})) return;
          slog::join_probe<4,2>(liteindex305, std::array<u64,4>{v_c24, v_c4, 0, 0}, [&](const std::array<u64,4>& m330) {
            u64 v_c8 = m330[2]; u64 v_c5 = m330[3];
            slog::join_probe<2,2>(icindex306, std::array<u64,2>{v_c5, v_c3}, [&](const std::array<u64,2>& m331) {
              slog::join_probe<2,1>(icindex307, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m332) {
                u64 v_c6 = m332[1];
                slog::join_probe<3,2>(lgtindex308, std::array<u64,3>{v_c8, v_c6, 0}, [&](const std::array<u64,3>& m333) {
                  u64 v_c7 = m333[2];
                  slog::join_probe<2,2>(icindex309, std::array<u64,2>{v_c7, v_c0}, [&](const std::array<u64,2>& m334) {
                    ++_fires;
                    slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c95}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:23", "delta:leq", _fires);
  
      if (!_done)
      {
        ReadTask310* _cont = new ReadTask310(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask310(db,b), false);
  // (crule (pre (let __tconst6E5W191 constef2d127de37b942baad06145) (let __tconst8ZVp189 const4e07408562bedb8b60ce05c1) (let __tconst62dH187 const4a44dc15364204a80fe80e90) (let __tconst1tfz185 constf5ca38f748a1d6eaf726b8a4)) (seeded) (body (join ic (1 0) 1 __tconst62dH187 __t4UHo184) (exists ic (1 0) 1 __tconst8ZVp189) (exists ic (1 0) 1 __tconst6E5W191) (join ic (1 0) 1 __tconst1tfz185 __t3VVz186) (join ic (1 0) 1 __tconst8ZVp189 __t17DP190) (join ic (1 0) 1 __tconst6E5W191 __t3PaA192)) (head (mkstruct lgt (2 1 0) __t7bbY193 __t17DP190 __t3PaA192)) smt_sets.slog:23 #f)
  class ReadTask341 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex335;  slog::Index** icindex336;  slog::Index** icindex337;  slog::Index** icindex338;  slog::Index** icindex339;  slog::Index** icindex340;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lgt");
      std::vector<u16> ord342({2, 1, 0});
      slog::Relation* readrel343 = db->getRelation("lgt");
      head_index[0] = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 0});
      slog::Relation* readrel345 = db->getRelation("ic");
      icindex335 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({1, 0});
      slog::Relation* readrel347 = db->getRelation("ic");
      icindex336 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({1, 0});
      slog::Relation* readrel349 = db->getRelation("ic");
      icindex337 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 0});
      slog::Relation* readrel351 = db->getRelation("ic");
      icindex338 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 0});
      slog::Relation* readrel353 = db->getRelation("ic");
      icindex339 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({1, 0});
      slog::Relation* readrel355 = db->getRelation("ic");
      icindex340 = readrel355->getIndex(ord354, false);
  
    }
    ReadTask341(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const4a44dc15364204a80fe80e90;
      u64 v_c3 = v_constf5ca38f748a1d6eaf726b8a4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex335, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m356) {
        u64 v_c4 = m356[1];
        if (!slog::exists_probe<2,1>(icindex336, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(icindex337, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(icindex338, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m357) {
          u64 v_c5 = m357[1];
          slog::join_probe<2,1>(icindex339, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m358) {
            u64 v_c6 = m358[1];
            slog::join_probe<2,1>(icindex340, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m359) {
              u64 v_c7 = m359[1];
              ++_fires;
              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c7}, std::array<u16,3>{2, 1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:23", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask341(db,b));
  // (crule (pre) (scan temp8AEw377 __t1I4R149) (body (join lall (1 0) 1 __t1I4R149 __t3z94150)) (head (mkstruct smt_check (1 0) __91p1264 __t3z94150)) smt_sets.slog:11 #f)
  class ReadTask361 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex360;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("temp8AEw377");
      std::vector<u16> ord362({1, 0});
      slog::Relation* readrel363 = db->getRelation("lall");
      lallindex360 = readrel363->getIndex(ord362, false);
  
    }
    ReadTask361(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(lallindex360, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m364) {
          u64 v_c96 = m364[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c96}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:11", "delta:temp8AEw377", _fires);
  
      if (!_done)
      {
        ReadTask361* _cont = new ReadTask361(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask361(db,b), false);
  // (crule (pre (let __tconst8Eqn1 constd4735e3a265e16eee03f5971) (let __tconst1Wl16 const4b227777d4dd1fc61c6f884f) (let __tconst5ETt8 const4e07408562bedb8b60ce05c1) (let __tconst7g7f15 const6b86b273ff34fce19d6b804e)) (scan temp1zBS403 __t0JBY11) (body (exists ic (1 0) 1 __tconst1Wl16) (exists ic (1 0) 1 __tconst7g7f15) (exists ic (1 0) 1 __tconst8Eqn1) (join ic (1 0) 1 __tconst5ETt8 __t4gzu9) (join ic (1 0) 1 __tconst1Wl16 __t6hlX7) (join ic (1 0) 1 __tconst7g7f15 __t05u84) (join ic (1 0) 1 __tconst8Eqn1 __t2Lgc2)) (head (emit-temp temp8oBi404 __t0JBY11) (mkstruct llt (1 2 0) __t1OA85 __t05u84 __t2Lgc2) (mkstruct lne (1 2 0) __t3A4I10 __t4gzu9 __t6hlX7)) smt_sets.slog:30 #f)
  class ReadTask372 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex365;  slog::Index** icindex366;  slog::Index** icindex367;  slog::Index** icindex368;  slog::Index** icindex369;  slog::Index** icindex370;  slog::Index** icindex371;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8oBi404");
      head_rel[1] = db->getRelation("llt");
      head_rel[2] = db->getRelation("lne");
      outer_rel = db->getRelation("temp1zBS403");
      std::vector<u16> ord373({1, 0});
      slog::Relation* readrel374 = db->getRelation("ic");
      icindex365 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({1, 0});
      slog::Relation* readrel376 = db->getRelation("ic");
      icindex366 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({1, 0});
      slog::Relation* readrel378 = db->getRelation("ic");
      icindex367 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 0});
      slog::Relation* readrel380 = db->getRelation("ic");
      icindex368 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 0});
      slog::Relation* readrel382 = db->getRelation("ic");
      icindex369 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({1, 0});
      slog::Relation* readrel384 = db->getRelation("ic");
      icindex370 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({1, 0});
      slog::Relation* readrel386 = db->getRelation("ic");
      icindex371 = readrel386->getIndex(ord385, false);
  
    }
    ReadTask372(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c84 = v_constd4735e3a265e16eee03f5971;
      u64 v_c85 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c86 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c87 = _t[0];
        if (!slog::exists_probe<2,1>(icindex365, std::array<u64,2>{v_c85, 0})) return;
        if (!slog::exists_probe<2,1>(icindex366, std::array<u64,2>{v_c45, 0})) return;
        if (!slog::exists_probe<2,1>(icindex367, std::array<u64,2>{v_c84, 0})) return;
        slog::join_probe<2,1>(icindex368, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m387) {
          u64 v_c88 = m387[1];
          slog::join_probe<2,1>(icindex369, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m388) {
            u64 v_c89 = m388[1];
            slog::join_probe<2,1>(icindex370, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m389) {
              u64 v_c91 = m389[1];
              slog::join_probe<2,1>(icindex371, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m390) {
                u64 v_c92 = m390[1];
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c87});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c91, v_c92}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c88, v_c89}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:30", "delta:temp1zBS403", _fires);
  
      if (!_done)
      {
        ReadTask372* _cont = new ReadTask372(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask372(db,b), false);
  // (crule (pre (let __tconst7hzd87 const6b86b273ff34fce19d6b804e) (let __tconst9GyQ85 constd4735e3a265e16eee03f5971)) (scan temp1QlB391 __t5AIw96) (body (exists ic (1 0) 1 __tconst7hzd87) (join ic (1 0) 1 __tconst9GyQ85 __t18po86) (exists llt (2 0 1) 1 __t18po86) (join ic (1 0) 1 __tconst7hzd87 __t7qEk88) (join llt (1 2 0) 2 __t7qEk88 __t18po86 __t3YQQ89) (let __t6iSd97 (cins __t5AIw96 __t3YQQ89))) (head (emit-temp temp6T4m392 __t6iSd97)) smt_sets.slog:19 #f)
  class ReadTask396 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex391;  slog::Index** icindex392;  slog::Index** lltindex393;  slog::Index** icindex394;  slog::Index** lltindex395;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6T4m392");
      outer_rel = db->getRelation("temp1QlB391");
      std::vector<u16> ord397({1, 0});
      slog::Relation* readrel398 = db->getRelation("ic");
      icindex391 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 0});
      slog::Relation* readrel400 = db->getRelation("ic");
      icindex392 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({2, 0, 1});
      slog::Relation* readrel402 = db->getRelation("llt");
      lltindex393 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 0});
      slog::Relation* readrel404 = db->getRelation("ic");
      icindex394 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("llt");
      lltindex395 = readrel406->getIndex(ord405, false);
  
    }
    ReadTask396(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c21 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c22 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c97 = _t[0];
        if (!slog::exists_probe<2,1>(icindex391, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe<2,1>(icindex392, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m407) {
          u64 v_c72 = m407[1];
          if (!slog::exists_probe<3,1>(lltindex393, std::array<u64,3>{v_c72, 0, 0})) return;
          slog::join_probe<2,1>(icindex394, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m408) {
            u64 v_c73 = m408[1];
            slog::join_probe<3,2>(lltindex395, std::array<u64,3>{v_c73, v_c72, 0}, [&](const std::array<u64,3>& m409) {
              u64 v_c98 = m409[2];
              u64 v_c99 = _prim_cins(db, v_c97, v_c98);
              if (v_c99 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:19"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c99});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:19", "delta:temp1QlB391", _fires);
  
      if (!_done)
      {
        ReadTask396* _cont = new ReadTask396(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask396(db,b), false);
  // (crule (pre (let __tconst9RaP82 const4e07408562bedb8b60ce05c1) (let __tconst5fnM80 const4b227777d4dd1fc61c6f884f)) (once) (body) (head (mkstruct ic (1 0) __t62EP83 __tconst9RaP82) (mkstruct ic (1 0) __t7EyB81 __tconst5fnM80)) smt_sets.slog:25 #f)
  class ReadTask410 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ic");
      head_rel[1] = db->getRelation("ic");
  
    }
    ReadTask410(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c100 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c101 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c100}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c101}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_sets.slog:25", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask410(db,b), true);
  // (crule (pre) (scan nan_result __erre9Omz348 __errf26XV349 __errf7yxa350 __errf9oLB351) (body) (head (emit error (0) __erre9Omz348)) <internal>:1 #f)
  class ReadTask411 : public slog::Task
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
      std::vector<u16> ord412({0});
      slog::Relation* readrel413 = db->getRelation("error");
      head_index[0] = readrel413->getIndex(ord412, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask411(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c102 = _t[0];
        u64 v_c103 = _t[1];
        u64 v_c104 = _t[2];
        u64 v_c105 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c102}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask411* _cont = new ReadTask411(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask411(db,b), false);
  // (crule (pre (let __tconst3YP6144 constd4735e3a265e16eee03f5971) (let __tconst0J7X139 const6b86b273ff34fce19d6b804e)) (scan temp8ai2374 __t5vnO147) (body (exists ic (1 0) 1 __tconst0J7X139) (join ic (1 0) 1 __tconst3YP6144 __t6QYl138) (exists llt (2 0 1) 1 __t6QYl138) (exists lle (1 2 0) 1 __t6QYl138) (join ic (1 0) 1 __tconst0J7X139 __t6CXY140) (join llt (1 2 0) 2 __t6CXY140 __t6QYl138 __t6viR141) (join lle (1 2 0) 1 __t6QYl138 dup8PTs378 __t6Q1F146) (eq __t6QYl138 dup8PTs378) (let __t3P3r148 (cins __t5vnO147 __t6Q1F146))) (head (emit-temp temp9C8t375 __t3P3r148)) smt_sets.slog:11 #f)
  class ReadTask421 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex414;  slog::Index** icindex415;  slog::Index** lltindex416;  slog::Index** lleindex417;  slog::Index** icindex418;  slog::Index** lltindex419;  slog::Index** lleindex420;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9C8t375");
      outer_rel = db->getRelation("temp8ai2374");
      std::vector<u16> ord422({1, 0});
      slog::Relation* readrel423 = db->getRelation("ic");
      icindex414 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 0});
      slog::Relation* readrel425 = db->getRelation("ic");
      icindex415 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({2, 0, 1});
      slog::Relation* readrel427 = db->getRelation("llt");
      lltindex416 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 2, 0});
      slog::Relation* readrel429 = db->getRelation("lle");
      lleindex417 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({1, 0});
      slog::Relation* readrel431 = db->getRelation("ic");
      icindex418 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({1, 2, 0});
      slog::Relation* readrel433 = db->getRelation("llt");
      lltindex419 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 2, 0});
      slog::Relation* readrel435 = db->getRelation("lle");
      lleindex420 = readrel435->getIndex(ord434, false);
  
    }
    ReadTask421(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_constd4735e3a265e16eee03f5971;
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
        if (!slog::exists_probe<2,1>(icindex414, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe<2,1>(icindex415, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m436) {
          u64 v_c17 = m436[1];
          if (!slog::exists_probe<3,1>(lltindex416, std::array<u64,3>{v_c17, 0, 0})) return;
          if (!slog::exists_probe<3,1>(lleindex417, std::array<u64,3>{v_c17, 0, 0})) return;
          slog::join_probe<2,1>(icindex418, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m437) {
            u64 v_c18 = m437[1];
            slog::join_probe<3,2>(lltindex419, std::array<u64,3>{v_c18, v_c17, 0}, [&](const std::array<u64,3>& m438) {
              u64 v_c82 = m438[2];
              slog::join_probe<3,1>(lleindex420, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m439) {
                u64 v_c106 = m439[1]; u64 v_c107 = m439[2];
                if (v_c17 != v_c106) return;
                u64 v_c81 = _prim_cins(db, v_c16, v_c107);
                if (v_c81 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:11"); return; }
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c81});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:11", "delta:temp8ai2374", _fires);
  
      if (!_done)
      {
        ReadTask421* _cont = new ReadTask421(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask421(db,b), false);
}

