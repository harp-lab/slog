
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
extern u64 v_consta221beeaebe583607e193be7;
extern u64 v_constab76c7d069d6f33dc950fb33;
extern u64 v_constba2df4903a2c14e86dc3bcca;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdef8bc82d3dca227c973a765;
extern u64 v_consteb8bf0d80db323992f6b634a;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;


void slog_rules_c9061fe357ae7d7d9(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan temp2cLk371 __t9n8k53) (body) (head (emit-temp temp0VQ2372 __t9n8k53) (mkstruct lall (1 0) __t8dtD54 __t9n8k53)) smt_sets.slog:15 #f)
  class ReadTask0 : public slog::Task
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
      head_rel[0] = db->getRelation("temp0VQ2372");
      head_rel[1] = db->getRelation("lall");
      outer_rel = db->getRelation("temp2cLk371");
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c0 = _t[0];
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_sets.slog:15", "delta:temp2cLk371", _fires);
  
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
  // (crule (pre (let __tconst3W9d292 consta221beeaebe583607e193be7)) (once) (body) (head (mkstruct _enum (1 0) __4vzk293 __tconst3W9d292)) <internal>:1 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("_enum");
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_consta221beeaebe583607e193be7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask1(db,b), true);
  // (crule (pre (let __tconst9NiH43 const6b86b273ff34fce19d6b804e) (let __tconst1ejW41 constd4735e3a265e16eee03f5971)) (scan temp0kwI370 __t8qhz52) (body (exists ic (1 0) 1 __tconst9NiH43) (join ic (1 0) 1 __tconst1ejW41 __t0b2d42) (exists lgt (2 1 0) 1 __t0b2d42) (join ic (1 0) 1 __tconst9NiH43 __t4FA344) (join lgt (2 1 0) 2 __t0b2d42 __t4FA344 __t9ypF45) (let __t9n8k53 (cins __t8qhz52 __t9ypF45))) (head (emit-temp temp2cLk371 __t9n8k53)) smt_sets.slog:15 #f)
  class ReadTask7 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex2;  slog::Index** icindex3;  slog::Index** lgtindex4;  slog::Index** icindex5;  slog::Index** lgtindex6;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2cLk371");
      outer_rel = db->getRelation("temp0kwI370");
      std::vector<u16> ord8({1, 0});
      slog::Relation* readrel9 = db->getRelation("ic");
      icindex2 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 0});
      slog::Relation* readrel11 = db->getRelation("ic");
      icindex3 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({2, 1, 0});
      slog::Relation* readrel13 = db->getRelation("lgt");
      lgtindex4 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("ic");
      icindex5 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({2, 1, 0});
      slog::Relation* readrel17 = db->getRelation("lgt");
      lgtindex6 = readrel17->getIndex(ord16, false);
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c4 = _t[0];
        if (!slog::exists_probe<2,1>(icindex2, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<2,1>(icindex3, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m18) {
          u64 v_c5 = m18[1];
          if (!slog::exists_probe<3,1>(lgtindex4, std::array<u64,3>{v_c5, 0, 0})) return;
          slog::join_probe<2,1>(icindex5, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m19) {
            u64 v_c6 = m19[1];
            slog::join_probe<3,2>(lgtindex6, std::array<u64,3>{v_c5, v_c6, 0}, [&](const std::array<u64,3>& m20) {
              u64 v_c7 = m20[2];
              u64 v_c0 = _prim_cins(db, v_c4, v_c7);
              if (v_c0 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:15"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:15", "delta:temp0kwI370", _fires);
  
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
  // (crule (pre (let __tconst62dH187 const4a44dc15364204a80fe80e90) (let __tconst1tfz185 constf5ca38f748a1d6eaf726b8a4) (let __tconst6E5W191 constef2d127de37b942baad06145) (let __tconst8ZVp189 const4e07408562bedb8b60ce05c1)) (seeded) (body (join ic (1 0) 1 __tconst62dH187 __t4UHo184) (exists lite (2 3 1 0) 1 __t4UHo184) (exists leq (2 1 0) 1 __t4UHo184) (exists ic (1 0) 1 __tconst8ZVp189) (exists ic (1 0) 1 __tconst6E5W191) (join ic (1 0) 1 __tconst1tfz185 __t3VVz186) (join lite (2 3 1 0) 2 __t4UHo184 __t3VVz186 __t7bbY193 __t1kp3194) (join leq (2 1 0) 2 __t4UHo184 __t1kp3194 __t8St0195) (join ic (1 0) 1 __tconst8ZVp189 __t17DP190) (join lgt (0 2 1) 2 __t7bbY193 __t17DP190 __t3PaA192) (join ic (0 1) 2 __t3PaA192 __tconst6E5W191)) (head (mkstruct smt_check (1 0) __0Bnp266 __t8St0195)) smt_sets.slog:23 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex21;  slog::Index** liteindex22;  slog::Index** leqindex23;  slog::Index** icindex24;  slog::Index** icindex25;  slog::Index** icindex26;  slog::Index** liteindex27;  slog::Index** leqindex28;  slog::Index** icindex29;  slog::Index** lgtindex30;  slog::Index** icindex31;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("smt_check");
      head_index[0] = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("ic");
      icindex21 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({2, 3, 1, 0});
      slog::Relation* readrel38 = db->getRelation("lite");
      liteindex22 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({2, 1, 0});
      slog::Relation* readrel40 = db->getRelation("leq");
      leqindex23 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 0});
      slog::Relation* readrel42 = db->getRelation("ic");
      icindex24 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 0});
      slog::Relation* readrel44 = db->getRelation("ic");
      icindex25 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 0});
      slog::Relation* readrel46 = db->getRelation("ic");
      icindex26 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({2, 3, 1, 0});
      slog::Relation* readrel48 = db->getRelation("lite");
      liteindex27 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({2, 1, 0});
      slog::Relation* readrel50 = db->getRelation("leq");
      leqindex28 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 0});
      slog::Relation* readrel52 = db->getRelation("ic");
      icindex29 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({0, 2, 1});
      slog::Relation* readrel54 = db->getRelation("lgt");
      lgtindex30 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("ic");
      icindex31 = readrel56->getIndex(ord55, false);
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
      u64 v_c9 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c10 = v_constef2d127de37b942baad06145;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex21, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m57) {
        u64 v_c12 = m57[1];
        if (!slog::exists_probe<4,1>(liteindex22, std::array<u64,4>{v_c12, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(leqindex23, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<2,1>(icindex24, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(icindex25, std::array<u64,2>{v_c10, 0})) return;
        slog::join_probe<2,1>(icindex26, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m58) {
          u64 v_c13 = m58[1];
          slog::join_probe<4,2>(liteindex27, std::array<u64,4>{v_c12, v_c13, 0, 0}, [&](const std::array<u64,4>& m59) {
            u64 v_c14 = m59[2]; u64 v_c15 = m59[3];
            slog::join_probe<3,2>(leqindex28, std::array<u64,3>{v_c12, v_c15, 0}, [&](const std::array<u64,3>& m60) {
              u64 v_c16 = m60[2];
              slog::join_probe<2,1>(icindex29, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m61) {
                u64 v_c17 = m61[1];
                slog::join_probe<3,2>(lgtindex30, std::array<u64,3>{v_c14, v_c17, 0}, [&](const std::array<u64,3>& m62) {
                  u64 v_c18 = m62[2];
                  slog::join_probe<2,2>(icindex31, std::array<u64,2>{v_c18, v_c10}, [&](const std::array<u64,2>& m63) {
                    ++_fires;
                    slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
                  });
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
      s->addTaskSeeded(phase_read, new ReadTask32(db,b));
  // (crule (pre (let __tconst9RaP82 const4e07408562bedb8b60ce05c1) (let __tconst5fnM80 const4b227777d4dd1fc61c6f884f)) (seeded) (body (join ic (1 0) 1 __tconst5fnM80 __t7EyB81) (exists lne (2 0 1) 1 __t7EyB81) (join ic (1 0) 1 __tconst9RaP82 __t62EP83) (join lne (1 2 0) 2 __t62EP83 __t7EyB81 __t48qM84)) (head (mkstruct smt_check (1 0) __6h39287 __t48qM84)) smt_sets.slog:25 #f)
  class ReadTask68 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex64;  slog::Index** lneindex65;  slog::Index** icindex66;  slog::Index** lneindex67;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      std::vector<u16> ord69({1, 0});
      slog::Relation* readrel70 = db->getRelation("smt_check");
      head_index[0] = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({1, 0});
      slog::Relation* readrel72 = db->getRelation("ic");
      icindex64 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({2, 0, 1});
      slog::Relation* readrel74 = db->getRelation("lne");
      lneindex65 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 0});
      slog::Relation* readrel76 = db->getRelation("ic");
      icindex66 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 2, 0});
      slog::Relation* readrel78 = db->getRelation("lne");
      lneindex67 = readrel78->getIndex(ord77, false);
  
    }
    ReadTask68(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c19 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c20 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex64, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m79) {
        u64 v_c21 = m79[1];
        if (!slog::exists_probe<3,1>(lneindex65, std::array<u64,3>{v_c21, 0, 0})) return;
        slog::join_probe<2,1>(icindex66, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m80) {
          u64 v_c22 = m80[1];
          slog::join_probe<3,2>(lneindex67, std::array<u64,3>{v_c22, v_c21, 0}, [&](const std::array<u64,3>& m81) {
            u64 v_c23 = m81[2];
            ++_fires;
            slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:25", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask68(db,b));
  // (crule (pre (let __tconst6j65260 constd4735e3a265e16eee03f5971) (let __tconst7FZI246 const4b227777d4dd1fc61c6f884f) (let __tconst5rfE248 const4e07408562bedb8b60ce05c1)) (scan temp6049396 __t6xkB257) (body (exists ic (1 0) 1 __tconst7FZI246) (join ic (1 0) 1 __tconst5rfE248 __t9yu4249) (exists lne (1 2 0) 1 __t9yu4249) (join ic (1 0) 1 __tconst7FZI246 __t2LML247) (join lne (1 2 0) 2 __t9yu4249 __t2LML247 __t1vDV250) (let __t2TSq258 (cins __t6xkB257 __t1vDV250))) (head (emit-temp temp6YoG397 __t2TSq258)) smt_sets.slog:31 #f)
  class ReadTask87 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex82;  slog::Index** icindex83;  slog::Index** lneindex84;  slog::Index** icindex85;  slog::Index** lneindex86;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6YoG397");
      outer_rel = db->getRelation("temp6049396");
      std::vector<u16> ord88({1, 0});
      slog::Relation* readrel89 = db->getRelation("ic");
      icindex82 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 0});
      slog::Relation* readrel91 = db->getRelation("ic");
      icindex83 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 2, 0});
      slog::Relation* readrel93 = db->getRelation("lne");
      lneindex84 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0});
      slog::Relation* readrel95 = db->getRelation("ic");
      icindex85 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 2, 0});
      slog::Relation* readrel97 = db->getRelation("lne");
      lneindex86 = readrel97->getIndex(ord96, false);
  
    }
    ReadTask87(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_constd4735e3a265e16eee03f5971;
      u64 v_c25 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c26 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c27 = _t[0];
        if (!slog::exists_probe<2,1>(icindex82, std::array<u64,2>{v_c25, 0})) return;
        slog::join_probe<2,1>(icindex83, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m98) {
          u64 v_c28 = m98[1];
          if (!slog::exists_probe<3,1>(lneindex84, std::array<u64,3>{v_c28, 0, 0})) return;
          slog::join_probe<2,1>(icindex85, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m99) {
            u64 v_c29 = m99[1];
            slog::join_probe<3,2>(lneindex86, std::array<u64,3>{v_c28, v_c29, 0}, [&](const std::array<u64,3>& m100) {
              u64 v_c30 = m100[2];
              u64 v_c31 = _prim_cins(db, v_c27, v_c30);
              if (v_c31 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:31"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c31});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:31", "delta:temp6049396", _fires);
  
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
  // (crule (pre (let __tconst7FZI246 const4b227777d4dd1fc61c6f884f) (let __tconst5rfE248 const4e07408562bedb8b60ce05c1) (let __tconst0uFl253 const6b86b273ff34fce19d6b804e) (let __tconst6j65260 constd4735e3a265e16eee03f5971)) (scan temp4zc4394 __t8rMA256) (body (exists ic (1 0) 1 __tconst6j65260) (exists ic (1 0) 1 __tconst5rfE248) (exists ic (1 0) 1 __tconst7FZI246) (join ic (1 0) 1 __tconst0uFl253 __t8epM254) (join ic (1 0) 1 __tconst6j65260 __t6OVc252) (join ic (1 0) 1 __tconst5rfE248 __t9yu4249) (join ic (1 0) 1 __tconst7FZI246 __t2LML247)) (head (emit-temp temp5QX9395 __t8rMA256) (mkstruct lne (1 2 0) __t1vDV250 __t9yu4249 __t2LML247) (mkstruct llt (1 2 0) __t5Gq8255 __t8epM254 __t6OVc252)) smt_sets.slog:31 #f)
  class ReadTask108 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex101;  slog::Index** icindex102;  slog::Index** icindex103;  slog::Index** icindex104;  slog::Index** icindex105;  slog::Index** icindex106;  slog::Index** icindex107;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5QX9395");
      head_rel[1] = db->getRelation("lne");
      head_rel[2] = db->getRelation("llt");
      outer_rel = db->getRelation("temp4zc4394");
      std::vector<u16> ord109({1, 0});
      slog::Relation* readrel110 = db->getRelation("ic");
      icindex101 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 0});
      slog::Relation* readrel112 = db->getRelation("ic");
      icindex102 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 0});
      slog::Relation* readrel114 = db->getRelation("ic");
      icindex103 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 0});
      slog::Relation* readrel116 = db->getRelation("ic");
      icindex104 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 0});
      slog::Relation* readrel118 = db->getRelation("ic");
      icindex105 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({1, 0});
      slog::Relation* readrel120 = db->getRelation("ic");
      icindex106 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 0});
      slog::Relation* readrel122 = db->getRelation("ic");
      icindex107 = readrel122->getIndex(ord121, false);
  
    }
    ReadTask108(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c26 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c24 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c33 = _t[0];
        if (!slog::exists_probe<2,1>(icindex101, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(icindex102, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(icindex103, std::array<u64,2>{v_c25, 0})) return;
        slog::join_probe<2,1>(icindex104, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m123) {
          u64 v_c34 = m123[1];
          slog::join_probe<2,1>(icindex105, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m124) {
            u64 v_c35 = m124[1];
            slog::join_probe<2,1>(icindex106, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m125) {
              u64 v_c28 = m125[1];
              slog::join_probe<2,1>(icindex107, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m126) {
                u64 v_c29 = m126[1];
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c33});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c28, v_c29}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c34, v_c35}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:31", "delta:temp4zc4394", _fires);
  
      if (!_done)
      {
        ReadTask108* _cont = new ReadTask108(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask108(db,b), false);
  // (crule (pre (let __tconst3LHf114 constba2df4903a2c14e86dc3bcca) (let __tconst9tZn112 const4e07408562bedb8b60ce05c1) (let __tconst0Nfc109 const6b86b273ff34fce19d6b804e) (let __tconst8Oey107 constd4735e3a265e16eee03f5971)) (scan temp7V3r380 __t4064117) (body (exists ic (1 0) 1 __tconst0Nfc109) (exists ic (1 0) 1 __tconst9tZn112) (exists iv (1 0) 1 __tconst3LHf114) (join ic (1 0) 1 __tconst8Oey107 __t0S7L108) (exists llt (2 0 1) 1 __t0S7L108) (join ic (1 0) 1 __tconst0Nfc109 __t9WV8110) (join llt (1 2 0) 2 __t9WV8110 __t0S7L108 __t6HC4111) (join ic (1 0) 1 __tconst9tZn112 __t09fp113) (exists llt (2 0 1) 1 __t09fp113) (join iv (1 0) 1 __tconst3LHf114 __t8A6J115) (join llt (1 2 0) 2 __t8A6J115 __t09fp113 __t3haz116) (let __t0V8M118 (cins __t4064117 __t3haz116))) (head (emit-temp temp79Im381 __t0V8M118)) smt_sets.slog:17 #f)
  class ReadTask138 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex127;  slog::Index** icindex128;  slog::Index** ivindex129;  slog::Index** icindex130;  slog::Index** lltindex131;  slog::Index** icindex132;  slog::Index** lltindex133;  slog::Index** icindex134;  slog::Index** lltindex135;  slog::Index** ivindex136;  slog::Index** lltindex137;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp79Im381");
      outer_rel = db->getRelation("temp7V3r380");
      std::vector<u16> ord139({1, 0});
      slog::Relation* readrel140 = db->getRelation("ic");
      icindex127 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 0});
      slog::Relation* readrel142 = db->getRelation("ic");
      icindex128 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 0});
      slog::Relation* readrel144 = db->getRelation("iv");
      ivindex129 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({1, 0});
      slog::Relation* readrel146 = db->getRelation("ic");
      icindex130 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({2, 0, 1});
      slog::Relation* readrel148 = db->getRelation("llt");
      lltindex131 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({1, 0});
      slog::Relation* readrel150 = db->getRelation("ic");
      icindex132 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 2, 0});
      slog::Relation* readrel152 = db->getRelation("llt");
      lltindex133 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 0});
      slog::Relation* readrel154 = db->getRelation("ic");
      icindex134 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({2, 0, 1});
      slog::Relation* readrel156 = db->getRelation("llt");
      lltindex135 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 0});
      slog::Relation* readrel158 = db->getRelation("iv");
      ivindex136 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("llt");
      lltindex137 = readrel160->getIndex(ord159, false);
  
    }
    ReadTask138(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c37 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c39 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        if (!slog::exists_probe<2,1>(icindex127, std::array<u64,2>{v_c38, 0})) return;
        if (!slog::exists_probe<2,1>(icindex128, std::array<u64,2>{v_c37, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex129, std::array<u64,2>{v_c36, 0})) return;
        slog::join_probe<2,1>(icindex130, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m161) {
          u64 v_c41 = m161[1];
          if (!slog::exists_probe<3,1>(lltindex131, std::array<u64,3>{v_c41, 0, 0})) return;
          slog::join_probe<2,1>(icindex132, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m162) {
            u64 v_c42 = m162[1];
            slog::join_probe<3,2>(lltindex133, std::array<u64,3>{v_c42, v_c41, 0}, [&](const std::array<u64,3>& m163) {
              u64 v_c43 = m163[2];
              slog::join_probe<2,1>(icindex134, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m164) {
                u64 v_c44 = m164[1];
                if (!slog::exists_probe<3,1>(lltindex135, std::array<u64,3>{v_c44, 0, 0})) return;
                slog::join_probe<2,1>(ivindex136, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m165) {
                  u64 v_c45 = m165[1];
                  slog::join_probe<3,2>(lltindex137, std::array<u64,3>{v_c45, v_c44, 0}, [&](const std::array<u64,3>& m166) {
                    u64 v_c46 = m166[2];
                    u64 v_c47 = _prim_cins(db, v_c40, v_c46);
                    if (v_c47 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:17"); return; }
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c47});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:17", "delta:temp7V3r380", _fires);
  
      if (!_done)
      {
        ReadTask138* _cont = new ReadTask138(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask138(db,b), false);
  // (crule (pre (let __tconst0JQ048 constba2df4903a2c14e86dc3bcca) (let __tconst3CQF46 const4e07408562bedb8b60ce05c1) (let __tconst9NiH43 const6b86b273ff34fce19d6b804e) (let __tconst1ejW41 constd4735e3a265e16eee03f5971)) (scan temp8q48369 __t4rBU51) (body (exists ic (1 0) 1 __tconst9NiH43) (exists ic (1 0) 1 __tconst3CQF46) (exists iv (1 0) 1 __tconst0JQ048) (join ic (1 0) 1 __tconst1ejW41 __t0b2d42) (exists lgt (2 1 0) 1 __t0b2d42) (join ic (1 0) 1 __tconst9NiH43 __t4FA344) (join lgt (2 1 0) 2 __t0b2d42 __t4FA344 __t9ypF45) (join ic (1 0) 1 __tconst3CQF46 __t2w9L47) (exists llt (2 0 1) 1 __t2w9L47) (join iv (1 0) 1 __tconst0JQ048 __t09gB49) (join llt (1 2 0) 2 __t09gB49 __t2w9L47 __t79yX50) (let __t8qhz52 (cins __t4rBU51 __t79yX50))) (head (emit-temp temp0kwI370 __t8qhz52)) smt_sets.slog:15 #f)
  class ReadTask178 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex167;  slog::Index** icindex168;  slog::Index** ivindex169;  slog::Index** icindex170;  slog::Index** lgtindex171;  slog::Index** icindex172;  slog::Index** lgtindex173;  slog::Index** icindex174;  slog::Index** lltindex175;  slog::Index** ivindex176;  slog::Index** lltindex177;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0kwI370");
      outer_rel = db->getRelation("temp8q48369");
      std::vector<u16> ord179({1, 0});
      slog::Relation* readrel180 = db->getRelation("ic");
      icindex167 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 0});
      slog::Relation* readrel182 = db->getRelation("ic");
      icindex168 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 0});
      slog::Relation* readrel184 = db->getRelation("iv");
      ivindex169 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 0});
      slog::Relation* readrel186 = db->getRelation("ic");
      icindex170 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({2, 1, 0});
      slog::Relation* readrel188 = db->getRelation("lgt");
      lgtindex171 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 0});
      slog::Relation* readrel190 = db->getRelation("ic");
      icindex172 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({2, 1, 0});
      slog::Relation* readrel192 = db->getRelation("lgt");
      lgtindex173 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({1, 0});
      slog::Relation* readrel194 = db->getRelation("ic");
      icindex174 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({2, 0, 1});
      slog::Relation* readrel196 = db->getRelation("llt");
      lltindex175 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 0});
      slog::Relation* readrel198 = db->getRelation("iv");
      ivindex176 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 2, 0});
      slog::Relation* readrel200 = db->getRelation("llt");
      lltindex177 = readrel200->getIndex(ord199, false);
  
    }
    ReadTask178(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c49 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c50 = _t[0];
        if (!slog::exists_probe<2,1>(icindex167, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(icindex168, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex169, std::array<u64,2>{v_c48, 0})) return;
        slog::join_probe<2,1>(icindex170, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m201) {
          u64 v_c5 = m201[1];
          if (!slog::exists_probe<3,1>(lgtindex171, std::array<u64,3>{v_c5, 0, 0})) return;
          slog::join_probe<2,1>(icindex172, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m202) {
            u64 v_c6 = m202[1];
            slog::join_probe<3,2>(lgtindex173, std::array<u64,3>{v_c5, v_c6, 0}, [&](const std::array<u64,3>& m203) {
              u64 v_c7 = m203[2];
              slog::join_probe<2,1>(icindex174, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m204) {
                u64 v_c51 = m204[1];
                if (!slog::exists_probe<3,1>(lltindex175, std::array<u64,3>{v_c51, 0, 0})) return;
                slog::join_probe<2,1>(ivindex176, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m205) {
                  u64 v_c52 = m205[1];
                  slog::join_probe<3,2>(lltindex177, std::array<u64,3>{v_c52, v_c51, 0}, [&](const std::array<u64,3>& m206) {
                    u64 v_c53 = m206[2];
                    u64 v_c4 = _prim_cins(db, v_c50, v_c53);
                    if (v_c4 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:15"); return; }
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c4});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:15", "delta:temp8q48369", _fires);
  
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
  // (crule (pre) (scan temp3QCQ382 __t1Iv4119) (body) (head (emit-temp temp2UHi383 __t1Iv4119) (mkstruct lall (1 0) __t5Is4120 __t1Iv4119)) smt_sets.slog:17 #f)
  class ReadTask207 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2UHi383");
      head_rel[1] = db->getRelation("lall");
      outer_rel = db->getRelation("temp3QCQ382");
  
    }
    ReadTask207(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c54});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c54}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_sets.slog:17", "delta:temp3QCQ382", _fires);
  
      if (!_done)
      {
        ReadTask207* _cont = new ReadTask207(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask207(db,b), false);
  // (crule (pre) (scan temp77Ij376 __t1I4R149) (body) (head (emit-temp temp8AEw377 __t1I4R149) (mkstruct lall (1 0) __t3z94150 __t1I4R149)) smt_sets.slog:11 #f)
  class ReadTask208 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8AEw377");
      head_rel[1] = db->getRelation("lall");
      outer_rel = db->getRelation("temp77Ij376");
  
    }
    ReadTask208(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c55});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c55}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_sets.slog:11", "delta:temp77Ij376", _fires);
  
      if (!_done)
      {
        ReadTask208* _cont = new ReadTask208(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask208(db,b), false);
  // (crule (pre) (scan temp1JQm402 __t1C2822) (body (join lall (1 0) 1 __t1C2822 __t6wAP23)) (head (mkstruct smt_check (1 0) __1Gom288 __t6wAP23)) smt_sets.slog:21 #f)
  class ReadTask210 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex209;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("temp1JQm402");
      std::vector<u16> ord211({1, 0});
      slog::Relation* readrel212 = db->getRelation("lall");
      lallindex209 = readrel212->getIndex(ord211, false);
  
    }
    ReadTask210(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[0];
        slog::join_probe<2,1>(lallindex209, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m213) {
          u64 v_c57 = m213[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:21", "delta:temp1JQm402", _fires);
  
      if (!_done)
      {
        ReadTask210* _cont = new ReadTask210(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask210(db,b), false);
  // (crule (pre (let __tconst6E5W191 constef2d127de37b942baad06145) (let __tconst8ZVp189 const4e07408562bedb8b60ce05c1) (let __tconst62dH187 const4a44dc15364204a80fe80e90) (let __tconst1tfz185 constf5ca38f748a1d6eaf726b8a4)) (scan lgt __t7bbY193 __t3PaA192 __t17DP190) (body (join ic (0 1) 2 __t17DP190 __tconst8ZVp189) (join ic (0 1) 2 __t3PaA192 __tconst6E5W191) (exists ic (1 0) 1 __tconst1tfz185) (join ic (1 0) 1 __tconst62dH187 __t4UHo184) (join ic (1 0) 1 __tconst1tfz185 __t3VVz186)) (head (mkstruct lite (2 3 1 0) __t1kp3194 __t4UHo184 __t3VVz186 __t7bbY193)) smt_sets.slog:23 #f)
  class ReadTask219 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex214;  slog::Index** icindex215;  slog::Index** icindex216;  slog::Index** icindex217;  slog::Index** icindex218;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lite");
      outer_rel = db->getRelation("lgt");
      std::vector<u16> ord220({0, 1});
      slog::Relation* readrel221 = db->getRelation("ic");
      icindex214 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({0, 1});
      slog::Relation* readrel223 = db->getRelation("ic");
      icindex215 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 0});
      slog::Relation* readrel225 = db->getRelation("ic");
      icindex216 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 0});
      slog::Relation* readrel227 = db->getRelation("ic");
      icindex217 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 0});
      slog::Relation* readrel229 = db->getRelation("ic");
      icindex218 = readrel229->getIndex(ord228, false);
  
    }
    ReadTask219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_constef2d127de37b942baad06145;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
      u64 v_c9 = v_constf5ca38f748a1d6eaf726b8a4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c14 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe<2,2>(icindex214, std::array<u64,2>{v_c17, v_c11}, [&](const std::array<u64,2>& m230) {
          slog::join_probe<2,2>(icindex215, std::array<u64,2>{v_c18, v_c10}, [&](const std::array<u64,2>& m231) {
            if (!slog::exists_probe<2,1>(icindex216, std::array<u64,2>{v_c9, 0})) return;
            slog::join_probe<2,1>(icindex217, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m232) {
              u64 v_c12 = m232[1];
              slog::join_probe<2,1>(icindex218, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m233) {
                u64 v_c13 = m233[1];
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c12, v_c13, v_c14}, std::array<u16,4>{2, 3, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:23", "delta:lgt", _fires);
  
      if (!_done)
      {
        ReadTask219* _cont = new ReadTask219(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask219(db,b), false);
  // (crule (pre (let __tconst0Nfc109 const6b86b273ff34fce19d6b804e) (let __tconst8Oey107 constd4735e3a265e16eee03f5971)) (scan temp79Im381 __t0V8M118) (body (exists ic (1 0) 1 __tconst0Nfc109) (join ic (1 0) 1 __tconst8Oey107 __t0S7L108) (exists llt (2 0 1) 1 __t0S7L108) (join ic (1 0) 1 __tconst0Nfc109 __t9WV8110) (join llt (1 2 0) 2 __t9WV8110 __t0S7L108 __t6HC4111) (let __t1Iv4119 (cins __t0V8M118 __t6HC4111))) (head (emit-temp temp3QCQ382 __t1Iv4119)) smt_sets.slog:17 #f)
  class ReadTask239 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex234;  slog::Index** icindex235;  slog::Index** lltindex236;  slog::Index** icindex237;  slog::Index** lltindex238;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3QCQ382");
      outer_rel = db->getRelation("temp79Im381");
      std::vector<u16> ord240({1, 0});
      slog::Relation* readrel241 = db->getRelation("ic");
      icindex234 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 0});
      slog::Relation* readrel243 = db->getRelation("ic");
      icindex235 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({2, 0, 1});
      slog::Relation* readrel245 = db->getRelation("llt");
      lltindex236 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 0});
      slog::Relation* readrel247 = db->getRelation("ic");
      icindex237 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 2, 0});
      slog::Relation* readrel249 = db->getRelation("llt");
      lltindex238 = readrel249->getIndex(ord248, false);
  
    }
    ReadTask239(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c39 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c47 = _t[0];
        if (!slog::exists_probe<2,1>(icindex234, std::array<u64,2>{v_c38, 0})) return;
        slog::join_probe<2,1>(icindex235, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m250) {
          u64 v_c41 = m250[1];
          if (!slog::exists_probe<3,1>(lltindex236, std::array<u64,3>{v_c41, 0, 0})) return;
          slog::join_probe<2,1>(icindex237, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m251) {
            u64 v_c42 = m251[1];
            slog::join_probe<3,2>(lltindex238, std::array<u64,3>{v_c42, v_c41, 0}, [&](const std::array<u64,3>& m252) {
              u64 v_c43 = m252[2];
              u64 v_c54 = _prim_cins(db, v_c47, v_c43);
              if (v_c54 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:17"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c54});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:17", "delta:temp79Im381", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre4neJ338 __errf5pkx339 __errf3uT7340) (body) (head (emit error (0) __erre4neJ338)) <internal>:1 #f)
  class ReadTask253 : public slog::Task
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
      std::vector<u16> ord254({0});
      slog::Relation* readrel255 = db->getRelation("error");
      head_index[0] = readrel255->getIndex(ord254, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask253(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[1];
        u64 v_c60 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c58}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask253* _cont = new ReadTask253(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask253(db,b), false);
  // (crule (pre) (scan temp2UHi383 __t1Iv4119) (body (join lall (1 0) 1 __t1Iv4119 __t5Is4120)) (head (mkstruct smt_check (1 0) __0YXC271 __t5Is4120)) smt_sets.slog:17 #f)
  class ReadTask257 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex256;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("temp2UHi383");
      std::vector<u16> ord258({1, 0});
      slog::Relation* readrel259 = db->getRelation("lall");
      lallindex256 = readrel259->getIndex(ord258, false);
  
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
        u64 v_c54 = _t[0];
        slog::join_probe<2,1>(lallindex256, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m260) {
          u64 v_c61 = m260[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c61}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:17", "delta:temp2UHi383", _fires);
  
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
  // (crule (pre (let __tconst7g7f15 const6b86b273ff34fce19d6b804e)) (scan temp6aCd407 __t8EzS13) (body (join lall (1 0) 1 __t8EzS13 __t3Jkz14)) (head (emit same (0 1) __tconst7g7f15 __t3Jkz14)) smt_sets.slog:30 #f)
  class ReadTask262 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex261;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("same");
      std::vector<u16> ord263({0, 1});
      slog::Relation* readrel264 = db->getRelation("same");
      head_index[0] = readrel264->getIndex(ord263, false);
      outer_rel = db->getRelation("temp6aCd407");
      std::vector<u16> ord265({1, 0});
      slog::Relation* readrel266 = db->getRelation("lall");
      lallindex261 = readrel266->getIndex(ord265, false);
  
    }
    ReadTask262(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c63 = _t[0];
        slog::join_probe<2,1>(lallindex261, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m267) {
          u64 v_c64 = m267[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c64}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:30", "delta:temp6aCd407", _fires);
  
      if (!_done)
      {
        ReadTask262* _cont = new ReadTask262(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask262(db,b), false);
  // (crule (pre (let __tconst62dH187 const4a44dc15364204a80fe80e90) (let __tconst1tfz185 constf5ca38f748a1d6eaf726b8a4) (let __tconst6E5W191 constef2d127de37b942baad06145) (let __tconst8ZVp189 const4e07408562bedb8b60ce05c1)) (scan lite __t1kp3194 __t7bbY193 __t4UHo184 __t3VVz186) (body (join ic (0 1) 2 __t4UHo184 __tconst62dH187) (join ic (0 1) 2 __t3VVz186 __tconst1tfz185) (exists ic (1 0) 1 __tconst6E5W191) (join ic (1 0) 1 __tconst8ZVp189 __t17DP190) (join lgt (0 2 1) 2 __t7bbY193 __t17DP190 __t3PaA192) (join ic (0 1) 2 __t3PaA192 __tconst6E5W191)) (head (mkstruct leq (2 1 0) __t8St0195 __t4UHo184 __t1kp3194)) smt_sets.slog:23 #f)
  class ReadTask274 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex268;  slog::Index** icindex269;  slog::Index** icindex270;  slog::Index** icindex271;  slog::Index** lgtindex272;  slog::Index** icindex273;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("leq");
      outer_rel = db->getRelation("lite");
      std::vector<u16> ord275({0, 1});
      slog::Relation* readrel276 = db->getRelation("ic");
      icindex268 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("ic");
      icindex269 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({1, 0});
      slog::Relation* readrel280 = db->getRelation("ic");
      icindex270 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 0});
      slog::Relation* readrel282 = db->getRelation("ic");
      icindex271 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({0, 2, 1});
      slog::Relation* readrel284 = db->getRelation("lgt");
      lgtindex272 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("ic");
      icindex273 = readrel286->getIndex(ord285, false);
  
    }
    ReadTask274(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
      u64 v_c9 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c10 = v_constef2d127de37b942baad06145;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c15 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c13 = _t[3];
        slog::join_probe<2,2>(icindex268, std::array<u64,2>{v_c12, v_c8}, [&](const std::array<u64,2>& m287) {
          slog::join_probe<2,2>(icindex269, std::array<u64,2>{v_c13, v_c9}, [&](const std::array<u64,2>& m288) {
            if (!slog::exists_probe<2,1>(icindex270, std::array<u64,2>{v_c10, 0})) return;
            slog::join_probe<2,1>(icindex271, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m289) {
              u64 v_c17 = m289[1];
              slog::join_probe<3,2>(lgtindex272, std::array<u64,3>{v_c14, v_c17, 0}, [&](const std::array<u64,3>& m290) {
                u64 v_c18 = m290[2];
                slog::join_probe<2,2>(icindex273, std::array<u64,2>{v_c18, v_c10}, [&](const std::array<u64,2>& m291) {
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c12, v_c15}, std::array<u16,3>{2, 1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:23", "delta:lite", _fires);
  
      if (!_done)
      {
        ReadTask274* _cont = new ReadTask274(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask274(db,b), false);
  // (crule (pre (let __tconst9RaP82 const4e07408562bedb8b60ce05c1) (let __tconst5fnM80 const4b227777d4dd1fc61c6f884f)) (scan lne __t48qM84 __t62EP83 __t7EyB81) (body (join ic (0 1) 2 __t7EyB81 __tconst5fnM80) (join ic (0 1) 2 __t62EP83 __tconst9RaP82)) (head (mkstruct smt_check (1 0) __6h39287 __t48qM84)) smt_sets.slog:25 #f)
  class ReadTask294 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex292;  slog::Index** icindex293;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("lne");
      std::vector<u16> ord295({0, 1});
      slog::Relation* readrel296 = db->getRelation("ic");
      icindex292 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({0, 1});
      slog::Relation* readrel298 = db->getRelation("ic");
      icindex293 = readrel298->getIndex(ord297, false);
  
    }
    ReadTask294(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c19 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c20 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c23 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c21 = _t[2];
        slog::join_probe<2,2>(icindex292, std::array<u64,2>{v_c21, v_c20}, [&](const std::array<u64,2>& m299) {
          slog::join_probe<2,2>(icindex293, std::array<u64,2>{v_c22, v_c19}, [&](const std::array<u64,2>& m300) {
            ++_fires;
            slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:25", "delta:lne", _fires);
  
      if (!_done)
      {
        ReadTask294* _cont = new ReadTask294(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask294(db,b), false);
  // (crule (pre) (scan temp6T4m392 __t6iSd97) (body) (head (emit-temp temp0iUR393 __t6iSd97) (mkstruct lany (1 0) __t652M98 __t6iSd97)) smt_sets.slog:19 #f)
  class ReadTask301 : public slog::Task
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
      head_rel[0] = db->getRelation("temp0iUR393");
      head_rel[1] = db->getRelation("lany");
      outer_rel = db->getRelation("temp6T4m392");
  
    }
    ReadTask301(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c65 = _t[0];
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c65});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c65}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_sets.slog:19", "delta:temp6T4m392", _fires);
  
      if (!_done)
      {
        ReadTask301* _cont = new ReadTask301(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask301(db,b), false);
  // (crule (pre (let __trid6UES289 const1951517e1abb2be9513ac082) (let __trel6Ag8290 const1dfd44c904fe1b3630c7e748) (let __tcol3Eq8291 const5feceb66ffc86f38d952786c) (let __t1C2822 (cmap))) (once) (body) (head (emit-temp temp8zkG401 __t1C2822)) smt_sets.slog:21 #f)
  class ReadTask302 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8zkG401");
  
    }
    ReadTask302(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_const1951517e1abb2be9513ac082;
      u64 v_c67 = v_const1dfd44c904fe1b3630c7e748;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
      u64 v_c56 = _prim_cmap(db);
      if (v_c56 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:21"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c56});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:21", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask302(db,b), true);
  // (crule (pre (let __tconst1NZm92 constba2df4903a2c14e86dc3bcca) (let __tconst60I490 const4e07408562bedb8b60ce05c1) (let __tconst7hzd87 const6b86b273ff34fce19d6b804e) (let __tconst9GyQ85 constd4735e3a265e16eee03f5971)) (scan temp0ETM390 __t7tqw95) (body (exists ic (1 0) 1 __tconst7hzd87) (exists ic (1 0) 1 __tconst60I490) (exists iv (1 0) 1 __tconst1NZm92) (join ic (1 0) 1 __tconst9GyQ85 __t18po86) (exists llt (2 0 1) 1 __t18po86) (join ic (1 0) 1 __tconst7hzd87 __t7qEk88) (join llt (1 2 0) 2 __t7qEk88 __t18po86 __t3YQQ89) (join ic (1 0) 1 __tconst60I490 __t4MDF91) (exists llt (2 0 1) 1 __t4MDF91) (join iv (1 0) 1 __tconst1NZm92 __t6QR393) (join llt (1 2 0) 2 __t6QR393 __t4MDF91 __t0PPB94) (let __t5AIw96 (cins __t7tqw95 __t0PPB94))) (head (emit-temp temp1QlB391 __t5AIw96)) smt_sets.slog:19 #f)
  class ReadTask314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex303;  slog::Index** icindex304;  slog::Index** ivindex305;  slog::Index** icindex306;  slog::Index** lltindex307;  slog::Index** icindex308;  slog::Index** lltindex309;  slog::Index** icindex310;  slog::Index** lltindex311;  slog::Index** ivindex312;  slog::Index** lltindex313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1QlB391");
      outer_rel = db->getRelation("temp0ETM390");
      std::vector<u16> ord315({1, 0});
      slog::Relation* readrel316 = db->getRelation("ic");
      icindex303 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 0});
      slog::Relation* readrel318 = db->getRelation("ic");
      icindex304 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 0});
      slog::Relation* readrel320 = db->getRelation("iv");
      ivindex305 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({1, 0});
      slog::Relation* readrel322 = db->getRelation("ic");
      icindex306 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({2, 0, 1});
      slog::Relation* readrel324 = db->getRelation("llt");
      lltindex307 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 0});
      slog::Relation* readrel326 = db->getRelation("ic");
      icindex308 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 2, 0});
      slog::Relation* readrel328 = db->getRelation("llt");
      lltindex309 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 0});
      slog::Relation* readrel330 = db->getRelation("ic");
      icindex310 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({2, 0, 1});
      slog::Relation* readrel332 = db->getRelation("llt");
      lltindex311 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 0});
      slog::Relation* readrel334 = db->getRelation("iv");
      ivindex312 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 2, 0});
      slog::Relation* readrel336 = db->getRelation("llt");
      lltindex313 = readrel336->getIndex(ord335, false);
  
    }
    ReadTask314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c69 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c70 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c71 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c72 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c73 = _t[0];
        if (!slog::exists_probe<2,1>(icindex303, std::array<u64,2>{v_c71, 0})) return;
        if (!slog::exists_probe<2,1>(icindex304, std::array<u64,2>{v_c70, 0})) return;
        if (!slog::exists_probe<2,1>(ivindex305, std::array<u64,2>{v_c69, 0})) return;
        slog::join_probe<2,1>(icindex306, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m337) {
          u64 v_c74 = m337[1];
          if (!slog::exists_probe<3,1>(lltindex307, std::array<u64,3>{v_c74, 0, 0})) return;
          slog::join_probe<2,1>(icindex308, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m338) {
            u64 v_c75 = m338[1];
            slog::join_probe<3,2>(lltindex309, std::array<u64,3>{v_c75, v_c74, 0}, [&](const std::array<u64,3>& m339) {
              u64 v_c76 = m339[2];
              slog::join_probe<2,1>(icindex310, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m340) {
                u64 v_c77 = m340[1];
                if (!slog::exists_probe<3,1>(lltindex311, std::array<u64,3>{v_c77, 0, 0})) return;
                slog::join_probe<2,1>(ivindex312, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m341) {
                  u64 v_c78 = m341[1];
                  slog::join_probe<3,2>(lltindex313, std::array<u64,3>{v_c78, v_c77, 0}, [&](const std::array<u64,3>& m342) {
                    u64 v_c79 = m342[2];
                    u64 v_c80 = _prim_cins(db, v_c73, v_c79);
                    if (v_c80 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:19"); return; }
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c80});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:19", "delta:temp0ETM390", _fires);
  
      if (!_done)
      {
        ReadTask314* _cont = new ReadTask314(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask314(db,b), false);
  // (crule (pre) (scan temp0VQ2372 __t9n8k53) (body (join lall (1 0) 1 __t9n8k53 __t8dtD54)) (head (mkstruct smt_check (1 0) __9WN4272 __t8dtD54)) smt_sets.slog:15 #f)
  class ReadTask344 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex343;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("temp0VQ2372");
      std::vector<u16> ord345({1, 0});
      slog::Relation* readrel346 = db->getRelation("lall");
      lallindex343 = readrel346->getIndex(ord345, false);
  
    }
    ReadTask344(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(lallindex343, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m347) {
          u64 v_c81 = m347[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c81}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:15", "delta:temp0VQ2372", _fires);
  
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
  // (crule (pre) (scan mpz_table_overflow __erre8CET365 __errf4D1D366 __errf6xe0367) (body) (head (emit error (0) __erre8CET365)) <internal>:1 #f)
  class ReadTask348 : public slog::Task
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
      std::vector<u16> ord349({0});
      slog::Relation* readrel350 = db->getRelation("error");
      head_index[0] = readrel350->getIndex(ord349, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask348(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c82 = _t[0];
        u64 v_c83 = _t[1];
        u64 v_c84 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c82}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask348* _cont = new ReadTask348(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask348(db,b), false);
  // (crule (pre (let __tconst3YP6144 constd4735e3a265e16eee03f5971) (let __tconst0J7X139 const6b86b273ff34fce19d6b804e) (let __t5vnO147 (cmap))) (once) (body) (head (emit-temp temp06Hk373 __t5vnO147) (mkstruct ic (1 0) __t6CXY140 __tconst0J7X139) (mkstruct ic (1 0) __t6QYl138 __tconst3YP6144)) smt_sets.slog:11 #f)
  class ReadTask351 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp06Hk373");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
  
    }
    ReadTask351(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c85 = v_constd4735e3a265e16eee03f5971;
      u64 v_c86 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c87 = _prim_cmap(db);
      if (v_c87 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:11"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c87});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c86}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c85}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("smt_sets.slog:11", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask351(db,b), true);
  // (crule (pre (let __tconst8Eqn1 constd4735e3a265e16eee03f5971) (let __tconst1Wl16 const4b227777d4dd1fc61c6f884f) (let __tconst5ETt8 const4e07408562bedb8b60ce05c1) (let __tconst7g7f15 const6b86b273ff34fce19d6b804e) (let __t0JBY11 (cmap))) (once) (body) (head (emit-temp temp1zBS403 __t0JBY11) (mkstruct ic (1 0) __t2Lgc2 __tconst8Eqn1) (mkstruct ic (1 0) __t05u84 __tconst7g7f15) (mkstruct ic (1 0) __t6hlX7 __tconst1Wl16) (mkstruct ic (1 0) __t4gzu9 __tconst5ETt8)) smt_sets.slog:30 #f)
  class ReadTask352 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1zBS403");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
      head_rel[3] = db->getRelation("ic");
      head_rel[4] = db->getRelation("ic");
  
    }
    ReadTask352(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_constd4735e3a265e16eee03f5971;
      u64 v_c89 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c90 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c91 = _prim_cmap(db);
      if (v_c91 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:30"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c91});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c88}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c62}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c89}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c90}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("smt_sets.slog:30", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask352(db,b), true);
  // (crule (pre) (scan temp4d4S387 __t9gMk242) (body) (head (emit-temp temp80WG388 __t9gMk242) (mkstruct lall (1 0) __t84sZ243 __t9gMk242)) smt_sets.slog:13 #f)
  class ReadTask353 : public slog::Task
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
      head_rel[0] = db->getRelation("temp80WG388");
      head_rel[1] = db->getRelation("lall");
      outer_rel = db->getRelation("temp4d4S387");
  
    }
    ReadTask353(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c92 = _t[0];
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c92});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c92}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("smt_sets.slog:13", "delta:temp4d4S387", _fires);
  
      if (!_done)
      {
        ReadTask353* _cont = new ReadTask353(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask353(db,b), false);
  // (crule (pre (let __tconst6j65260 constd4735e3a265e16eee03f5971)) (scan temp52TS398 __t2TSq258) (body (join lall (1 0) 1 __t2TSq258 __t5BqU259)) (head (emit same (0 1) __tconst6j65260 __t5BqU259)) smt_sets.slog:31 #f)
  class ReadTask355 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lallindex354;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("same");
      std::vector<u16> ord356({0, 1});
      slog::Relation* readrel357 = db->getRelation("same");
      head_index[0] = readrel357->getIndex(ord356, false);
      outer_rel = db->getRelation("temp52TS398");
      std::vector<u16> ord358({1, 0});
      slog::Relation* readrel359 = db->getRelation("lall");
      lallindex354 = readrel359->getIndex(ord358, false);
  
    }
    ReadTask355(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c31 = _t[0];
        slog::join_probe<2,1>(lallindex354, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m360) {
          u64 v_c93 = m360[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c24, v_c93}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:31", "delta:temp52TS398", _fires);
  
      if (!_done)
      {
        ReadTask355* _cont = new ReadTask355(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask355(db,b), false);
  // (crule (pre (let __tconst9RaP82 const4e07408562bedb8b60ce05c1) (let __tconst5fnM80 const4b227777d4dd1fc61c6f884f)) (probe ic (1 0) 1 __tconst5fnM80 __t7EyB81) (body (join ic (1 0) 1 __tconst9RaP82 __t62EP83)) (head (mkstruct lne (1 2 0) __t48qM84 __t62EP83 __t7EyB81)) smt_sets.slog:25 #f)
  class ReadTask362 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** icindex361;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lne");
      std::vector<u16> ord363({1, 0});
      slog::Relation* readrel364 = db->getRelation("ic");
      driver_index = readrel364->getIndex(ord363, true);
      std::vector<u16> ord365({1, 0});
      slog::Relation* readrel366 = db->getRelation("ic");
      icindex361 = readrel366->getIndex(ord365, false);
  
    }
    ReadTask362(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c19 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c20 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c20, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m367) {
        u64 v_c21 = m367[1];
        if (buckethash(v_c21) != bucket) return;
        slog::join_probe<2,1>(icindex361, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m368) {
          u64 v_c22 = m368[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c22, v_c21}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:25", "delta:ic", _fires);
  
      if (!_done)
      {
        ReadTask362* _cont = new ReadTask362(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask362(db,b), false);
  // (crule (pre (let __tconst0FTz237 const6b86b273ff34fce19d6b804e) (let __tconst7UvL235 constd4735e3a265e16eee03f5971)) (scan temp6VVM385 __t1p79240) (body (exists ic (1 0) 1 __tconst0FTz237) (join ic (1 0) 1 __tconst7UvL235 __t189l231) (exists llt (2 0 1) 1 __t189l231) (exists lgt (2 1 0) 1 __t189l231) (join ic (1 0) 1 __tconst0FTz237 __t4UmM233) (exists lgt (2 1 0) 2 __t189l231 __t4UmM233) (join llt (1 2 0) 2 __t4UmM233 __t189l231 __t3nYN234) (join lgt (2 1 0) 2 __t189l231 __t4UmM233 __t85IX239) (let __t7J7n241 (cins __t1p79240 __t85IX239))) (head (emit-temp temp4cMz386 __t7J7n241)) smt_sets.slog:13 #f)
  class ReadTask377 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex369;  slog::Index** icindex370;  slog::Index** lltindex371;  slog::Index** lgtindex372;  slog::Index** icindex373;  slog::Index** lgtindex374;  slog::Index** lltindex375;  slog::Index** lgtindex376;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4cMz386");
      outer_rel = db->getRelation("temp6VVM385");
      std::vector<u16> ord378({1, 0});
      slog::Relation* readrel379 = db->getRelation("ic");
      icindex369 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 0});
      slog::Relation* readrel381 = db->getRelation("ic");
      icindex370 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({2, 0, 1});
      slog::Relation* readrel383 = db->getRelation("llt");
      lltindex371 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({2, 1, 0});
      slog::Relation* readrel385 = db->getRelation("lgt");
      lgtindex372 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 0});
      slog::Relation* readrel387 = db->getRelation("ic");
      icindex373 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({2, 1, 0});
      slog::Relation* readrel389 = db->getRelation("lgt");
      lgtindex374 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 2, 0});
      slog::Relation* readrel391 = db->getRelation("llt");
      lltindex375 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({2, 1, 0});
      slog::Relation* readrel393 = db->getRelation("lgt");
      lgtindex376 = readrel393->getIndex(ord392, false);
  
    }
    ReadTask377(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c94 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c95 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c96 = _t[0];
        if (!slog::exists_probe<2,1>(icindex369, std::array<u64,2>{v_c94, 0})) return;
        slog::join_probe<2,1>(icindex370, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m394) {
          u64 v_c97 = m394[1];
          if (!slog::exists_probe<3,1>(lltindex371, std::array<u64,3>{v_c97, 0, 0})) return;
          if (!slog::exists_probe<3,1>(lgtindex372, std::array<u64,3>{v_c97, 0, 0})) return;
          slog::join_probe<2,1>(icindex373, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m395) {
            u64 v_c98 = m395[1];
            if (!slog::exists_probe<3,2>(lgtindex374, std::array<u64,3>{v_c97, v_c98, 0})) return;
            slog::join_probe<3,2>(lltindex375, std::array<u64,3>{v_c98, v_c97, 0}, [&](const std::array<u64,3>& m396) {
              u64 v_c99 = m396[2];
              slog::join_probe<3,2>(lgtindex376, std::array<u64,3>{v_c97, v_c98, 0}, [&](const std::array<u64,3>& m397) {
                u64 v_c100 = m397[2];
                u64 v_c101 = _prim_cins(db, v_c96, v_c100);
                if (v_c101 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:13"); return; }
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c101});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:13", "delta:temp6VVM385", _fires);
  
      if (!_done)
      {
        ReadTask377* _cont = new ReadTask377(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask377(db,b), false);
  // (crule (pre) (scan type_mismatch __erre3M2t355 __errf6ZW2356 __errf81Fo357 __errf2K2p358 __errf1409359) (body) (head (emit error (0) __erre3M2t355)) <internal>:1 #f)
  class ReadTask398 : public slog::Task
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
      std::vector<u16> ord399({0});
      slog::Relation* readrel400 = db->getRelation("error");
      head_index[0] = readrel400->getIndex(ord399, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask398(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c106 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c102}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask398* _cont = new ReadTask398(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask398(db,b), false);
  // (crule (pre (let __tconst1PMg296 consteb8bf0d80db323992f6b634a)) (once) (body) (head (mkstruct _enum (1 0) __4XBS297 __tconst1PMg296)) <internal>:1 #f)
  class ReadTask401 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("_enum");
  
    }
    ReadTask401(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_consteb8bf0d80db323992f6b634a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c107}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask401(db,b), true);
  // (crule (pre (let __tconst8qVS294 constab76c7d069d6f33dc950fb33)) (once) (body) (head (mkstruct _enum (1 0) __8IJ4295 __tconst8qVS294)) <internal>:1 #f)
  class ReadTask402 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("_enum");
  
    }
    ReadTask402(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_constab76c7d069d6f33dc950fb33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c108}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask402(db,b), true);
  // (crule (pre (let __tconst7g7f15 const6b86b273ff34fce19d6b804e) (let __tconst8Eqn1 constd4735e3a265e16eee03f5971)) (scan temp2RCa405 __t9hQe12) (body (exists ic (1 0) 1 __tconst8Eqn1) (join ic (1 0) 1 __tconst7g7f15 __t05u84) (exists llt (1 2 0) 1 __t05u84) (join ic (1 0) 1 __tconst8Eqn1 __t2Lgc2) (join llt (1 2 0) 2 __t05u84 __t2Lgc2 __t1OA85) (let __t8EzS13 (cins __t9hQe12 __t1OA85))) (head (emit-temp temp7kgo406 __t8EzS13)) smt_sets.slog:30 #f)
  class ReadTask408 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex403;  slog::Index** icindex404;  slog::Index** lltindex405;  slog::Index** icindex406;  slog::Index** lltindex407;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7kgo406");
      outer_rel = db->getRelation("temp2RCa405");
      std::vector<u16> ord409({1, 0});
      slog::Relation* readrel410 = db->getRelation("ic");
      icindex403 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 0});
      slog::Relation* readrel412 = db->getRelation("ic");
      icindex404 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({1, 2, 0});
      slog::Relation* readrel414 = db->getRelation("llt");
      lltindex405 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({1, 0});
      slog::Relation* readrel416 = db->getRelation("ic");
      icindex406 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 2, 0});
      slog::Relation* readrel418 = db->getRelation("llt");
      lltindex407 = readrel418->getIndex(ord417, false);
  
    }
    ReadTask408(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c88 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c109 = _t[0];
        if (!slog::exists_probe<2,1>(icindex403, std::array<u64,2>{v_c88, 0})) return;
        slog::join_probe<2,1>(icindex404, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m419) {
          u64 v_c110 = m419[1];
          if (!slog::exists_probe<3,1>(lltindex405, std::array<u64,3>{v_c110, 0, 0})) return;
          slog::join_probe<2,1>(icindex406, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m420) {
            u64 v_c111 = m420[1];
            slog::join_probe<3,2>(lltindex407, std::array<u64,3>{v_c110, v_c111, 0}, [&](const std::array<u64,3>& m421) {
              u64 v_c112 = m421[2];
              u64 v_c63 = _prim_cins(db, v_c109, v_c112);
              if (v_c63 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:30"); return; }
              ++_fires;
              slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c63});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:30", "delta:temp2RCa405", _fires);
  
      if (!_done)
      {
        ReadTask408* _cont = new ReadTask408(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask408(db,b), false);
  // (crule (pre (let __trid8bds284 const8cfcf41991382923e0d7fd17) (let __trel01iV285 constdef8bc82d3dca227c973a765) (let __tcol4T49286 const5feceb66ffc86f38d952786c) (let __t4TUW244 (cmap))) (once) (body) (head (emit-temp temp17I6399 __t4TUW244)) smt_sets.slog:22 #f)
  class ReadTask422 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp17I6399");
  
    }
    ReadTask422(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c113 = v_const8cfcf41991382923e0d7fd17;
      u64 v_c114 = v_constdef8bc82d3dca227c973a765;
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
      u64 v_c116 = _prim_cmap(db);
      if (v_c116 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:22"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c116});
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:22", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask422(db,b), true);
  // (crule (pre (let __tconst6j65260 constd4735e3a265e16eee03f5971) (let __tconst7FZI246 const4b227777d4dd1fc61c6f884f) (let __tconst5rfE248 const4e07408562bedb8b60ce05c1) (let __tconst0uFl253 const6b86b273ff34fce19d6b804e)) (scan temp5QX9395 __t8rMA256) (body (exists ic (1 0) 1 __tconst6j65260) (exists ic (1 0) 1 __tconst5rfE248) (exists ic (1 0) 1 __tconst7FZI246) (join ic (1 0) 1 __tconst0uFl253 __t8epM254) (exists llt (1 2 0) 1 __t8epM254) (join ic (1 0) 1 __tconst6j65260 __t6OVc252) (join llt (1 2 0) 2 __t8epM254 __t6OVc252 __t5Gq8255) (join ic (1 0) 1 __tconst5rfE248 __t9yu4249) (exists lne (1 2 0) 1 __t9yu4249) (join ic (1 0) 1 __tconst7FZI246 __t2LML247) (join lne (1 2 0) 2 __t9yu4249 __t2LML247 __t1vDV250) (let __t6xkB257 (cins __t8rMA256 __t5Gq8255))) (head (emit-temp temp6049396 __t6xkB257)) smt_sets.slog:31 #f)
  class ReadTask434 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** icindex423;  slog::Index** icindex424;  slog::Index** icindex425;  slog::Index** icindex426;  slog::Index** lltindex427;  slog::Index** icindex428;  slog::Index** lltindex429;  slog::Index** icindex430;  slog::Index** lneindex431;  slog::Index** icindex432;  slog::Index** lneindex433;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6049396");
      outer_rel = db->getRelation("temp5QX9395");
      std::vector<u16> ord435({1, 0});
      slog::Relation* readrel436 = db->getRelation("ic");
      icindex423 = readrel436->getIndex(ord435, false);
      std::vector<u16> ord437({1, 0});
      slog::Relation* readrel438 = db->getRelation("ic");
      icindex424 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({1, 0});
      slog::Relation* readrel440 = db->getRelation("ic");
      icindex425 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({1, 0});
      slog::Relation* readrel442 = db->getRelation("ic");
      icindex426 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 2, 0});
      slog::Relation* readrel444 = db->getRelation("llt");
      lltindex427 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({1, 0});
      slog::Relation* readrel446 = db->getRelation("ic");
      icindex428 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 2, 0});
      slog::Relation* readrel448 = db->getRelation("llt");
      lltindex429 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({1, 0});
      slog::Relation* readrel450 = db->getRelation("ic");
      icindex430 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({1, 2, 0});
      slog::Relation* readrel452 = db->getRelation("lne");
      lneindex431 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({1, 0});
      slog::Relation* readrel454 = db->getRelation("ic");
      icindex432 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 2, 0});
      slog::Relation* readrel456 = db->getRelation("lne");
      lneindex433 = readrel456->getIndex(ord455, false);
  
    }
    ReadTask434(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_constd4735e3a265e16eee03f5971;
      u64 v_c25 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c26 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c33 = _t[0];
        if (!slog::exists_probe<2,1>(icindex423, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(icindex424, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(icindex425, std::array<u64,2>{v_c25, 0})) return;
        slog::join_probe<2,1>(icindex426, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m457) {
          u64 v_c34 = m457[1];
          if (!slog::exists_probe<3,1>(lltindex427, std::array<u64,3>{v_c34, 0, 0})) return;
          slog::join_probe<2,1>(icindex428, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m458) {
            u64 v_c35 = m458[1];
            slog::join_probe<3,2>(lltindex429, std::array<u64,3>{v_c34, v_c35, 0}, [&](const std::array<u64,3>& m459) {
              u64 v_c117 = m459[2];
              slog::join_probe<2,1>(icindex430, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m460) {
                u64 v_c28 = m460[1];
                if (!slog::exists_probe<3,1>(lneindex431, std::array<u64,3>{v_c28, 0, 0})) return;
                slog::join_probe<2,1>(icindex432, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m461) {
                  u64 v_c29 = m461[1];
                  slog::join_probe<3,2>(lneindex433, std::array<u64,3>{v_c28, v_c29, 0}, [&](const std::array<u64,3>& m462) {
                    u64 v_c30 = m462[2];
                    u64 v_c27 = _prim_cins(db, v_c33, v_c117);
                    if (v_c27 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:31"); return; }
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c27});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:31", "delta:temp5QX9395", _fires);
  
      if (!_done)
      {
        ReadTask434* _cont = new ReadTask434(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask434(db,b), false);
  // (crule (pre (let __tconst7FZI246 const4b227777d4dd1fc61c6f884f) (let __tconst5rfE248 const4e07408562bedb8b60ce05c1) (let __tconst0uFl253 const6b86b273ff34fce19d6b804e) (let __tconst6j65260 constd4735e3a265e16eee03f5971) (let __t8rMA256 (cmap))) (once) (body) (head (emit-temp temp4zc4394 __t8rMA256) (mkstruct ic (1 0) __t2LML247 __tconst7FZI246) (mkstruct ic (1 0) __t9yu4249 __tconst5rfE248) (mkstruct ic (1 0) __t6OVc252 __tconst6j65260) (mkstruct ic (1 0) __t8epM254 __tconst0uFl253)) smt_sets.slog:31 #f)
  class ReadTask463 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4zc4394");
      head_rel[1] = db->getRelation("ic");
      head_rel[2] = db->getRelation("ic");
      head_rel[3] = db->getRelation("ic");
      head_rel[4] = db->getRelation("ic");
  
    }
    ReadTask463(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c26 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c24 = v_constd4735e3a265e16eee03f5971;
      u64 v_c33 = _prim_cmap(db);
      if (v_c33 == slog_error) { slog::emit_pending_error(db, "smt_sets.slog:31"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c33});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c25}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c26}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c32}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("smt_sets.slog:31", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask463(db,b), true);
  // (crule (pre (let __tconst9RaP82 const4e07408562bedb8b60ce05c1) (let __tconst5fnM80 const4b227777d4dd1fc61c6f884f)) (seeded) (body (join ic (1 0) 1 __tconst5fnM80 __t7EyB81) (join ic (1 0) 1 __tconst9RaP82 __t62EP83)) (head (mkstruct lne (1 2 0) __t48qM84 __t62EP83 __t7EyB81)) smt_sets.slog:25 #f)
  class ReadTask466 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** icindex464;  slog::Index** icindex465;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lne");
      std::vector<u16> ord467({1, 2, 0});
      slog::Relation* readrel468 = db->getRelation("lne");
      head_index[0] = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({1, 0});
      slog::Relation* readrel470 = db->getRelation("ic");
      icindex464 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 0});
      slog::Relation* readrel472 = db->getRelation("ic");
      icindex465 = readrel472->getIndex(ord471, false);
  
    }
    ReadTask466(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c19 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c20 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(icindex464, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m473) {
        u64 v_c21 = m473[1];
        slog::join_probe<2,1>(icindex465, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m474) {
          u64 v_c22 = m474[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c22, v_c21}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:25", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask466(db,b));
  // (crule (pre) (scan temp0iUR393 __t6iSd97) (body (join lany (1 0) 1 __t6iSd97 __t652M98)) (head (mkstruct smt_check (1 0) __31nE273 __t652M98)) smt_sets.slog:19 #f)
  class ReadTask476 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lanyindex475;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("smt_check");
      outer_rel = db->getRelation("temp0iUR393");
      std::vector<u16> ord477({1, 0});
      slog::Relation* readrel478 = db->getRelation("lany");
      lanyindex475 = readrel478->getIndex(ord477, false);
  
    }
    ReadTask476(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(lanyindex475, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m479) {
          u64 v_c118 = m479[1];
          ++_fires;
          slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c118}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("smt_sets.slog:19", "delta:temp0iUR393", _fires);
  
      if (!_done)
      {
        ReadTask476* _cont = new ReadTask476(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask476(db,b), false);
  // (crule (pre) (scan toint_range __erre32uO352 __errf7u02353 __errf0vbu354) (body) (head (emit error (0) __erre32uO352)) <internal>:1 #f)
  class ReadTask480 : public slog::Task
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
      std::vector<u16> ord481({0});
      slog::Relation* readrel482 = db->getRelation("error");
      head_index[0] = readrel482->getIndex(ord481, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask480(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c119 = _t[0];
        u64 v_c120 = _t[1];
        u64 v_c121 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c119}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask480* _cont = new ReadTask480(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask480(db,b), false);
}

