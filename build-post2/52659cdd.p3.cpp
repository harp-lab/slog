
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const2c070a9498052f6e608df512;
extern u64 v_const439d97756c1f6d8e3f1b29c9;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6d8bc911abd31f57d1b91158;
extern u64 v_constabce180ee56b2c323c19f642;
extern u64 v_constac8d8342bbb2362d13f0a559;
extern u64 v_constc100f95c1913f9c72fc1f4ef;
extern u64 v_constd1596cb698715803872591d6;
extern u64 v_constf0add80747aca33dead79eea;


void slog_rules_c4ad9e5821c4c179d(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst53SJ104 const439d97756c1f6d8e3f1b29c9) (let __tconst3Xg1100 constac8d8342bbb2362d13f0a559) (let __tconst8qEb95 constc100f95c1913f9c72fc1f4ef)) (scan alt __t5G2v102 __t4w1Y98 __t4yUC99) (body (join chr (0 1) 2 __t4w1Y98 __tconst3Xg1100) (exists chr (1 0) 1 __tconst8qEb95) (join cat (0 1 2) 2 __t4yUC99 __t4w1Y98 __t6I9I96) (join chr (0 1) 2 __t6I9I96 __tconst8qEb95)) (head (mkstruct star (1 0) __t4CfV103 __t5G2v102)) antimirov.slog:130 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex0;  slog::Index** chrindex1;  slog::Index** catindex2;  slog::Index** chrindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("star");
      outer_rel = db->getRelation("alt");
      std::vector<u16> ord5({0, 1});
      slog::Relation* readrel6 = db->getRelation("chr");
      chrindex0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("chr");
      chrindex1 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({0, 1, 2});
      slog::Relation* readrel10 = db->getRelation("cat");
      catindex2 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({0, 1});
      slog::Relation* readrel12 = db->getRelation("chr");
      chrindex3 = readrel12->getIndex(ord11, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const439d97756c1f6d8e3f1b29c9;
      u64 v_c1 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c2 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe<2,2>(chrindex0, std::array<u64,2>{v_c4, v_c1}, [&](const std::array<u64,2>& m13) {
          if (!slog::exists_probe<2,1>(chrindex1, std::array<u64,2>{v_c2, 0})) return;
          slog::join_probe<3,2>(catindex2, std::array<u64,3>{v_c5, v_c4, 0}, [&](const std::array<u64,3>& m14) {
            u64 v_c6 = m14[2];
            slog::join_probe<2,2>(chrindex3, std::array<u64,2>{v_c6, v_c2}, [&](const std::array<u64,2>& m15) {
              ++_fires;
              slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:130", "delta:alt", _fires);
  
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
  // (crule (pre (let __tconst9dp567 const6d8bc911abd31f57d1b91158) (let __tconst77RG62 constac8d8342bbb2362d13f0a559) (let __tconst7i6460 constc100f95c1913f9c72fc1f4ef)) (scan cat __t9z7256 __t7SBZ53 dup0UsF317) (body (eq __t7SBZ53 dup0UsF317) (join chr (0 1) 2 __t7SBZ53 __tconst7i6460) (exists alt (2 0 1) 1 __t7SBZ53) (join chr (1 0) 1 __tconst77RG62 __t8Axk58) (join alt (1 2 0) 2 __t8Axk58 __t7SBZ53 __t8pHj64)) (head (mkstruct star (1 0) __t5cfw65 __t8pHj64) (mkstruct cat (1 2 0) __t2gMK59 __t8Axk58 __t9z7256)) antimirov.slog:126 #f)
  class ReadTask20 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex16;  slog::Index** altindex17;  slog::Index** chrindex18;  slog::Index** altindex19;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("star");
      head_rel[1] = db->getRelation("cat");
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord21({0, 1});
      slog::Relation* readrel22 = db->getRelation("chr");
      chrindex16 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({2, 0, 1});
      slog::Relation* readrel24 = db->getRelation("alt");
      altindex17 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 0});
      slog::Relation* readrel26 = db->getRelation("chr");
      chrindex18 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 2, 0});
      slog::Relation* readrel28 = db->getRelation("alt");
      altindex19 = readrel28->getIndex(ord27, false);
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c7 = v_const6d8bc911abd31f57d1b91158;
      u64 v_c8 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c9 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c10 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        if (v_c11 != v_c12) return;
        slog::join_probe<2,2>(chrindex16, std::array<u64,2>{v_c11, v_c9}, [&](const std::array<u64,2>& m29) {
          if (!slog::exists_probe<3,1>(altindex17, std::array<u64,3>{v_c11, 0, 0})) return;
          slog::join_probe<2,1>(chrindex18, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m30) {
            u64 v_c13 = m30[1];
            slog::join_probe<3,2>(altindex19, std::array<u64,3>{v_c13, v_c11, 0}, [&](const std::array<u64,3>& m31) {
              u64 v_c14 = m31[2];
              ++_fires;
              slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c13, v_c10}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:126", "delta:cat", _fires);
  
      if (!_done)
      {
        ReadTask20* _cont = new ReadTask20(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask20(db,b), false);
  // (crule (pre) (scan deriv __t9dkM2 __t3xJI4 c) (body (exists deriv (2 0 1) 1 c) (exists mkcat (2 0 1) 1 __t3xJI4) (join-old star (0 1) 1 (0 1) __t3xJI4 r) (join-old deriv (1 2 0) 2 (1 2 0) r c __t70si3) (join deriv_ans (0 1) 1 __t70si3 __v0) (join-old mkcat (1 2 0) 2 (1 2 0) __v0 __t3xJI4 __t3A2z5) (join mkcat_ans (0 1) 1 __t3A2z5 __v1)) (head (emit deriv_ans (0 1) __t9dkM2 __v1)) antimirov.slog:73 #f)
  class ReadTask42 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex32;  slog::Index** mkcatindex33;  slog::Index** starindex34;  slog::Index** derivindex35;  slog::Index** deriv_ansindex36;  slog::Index** mkcatindex37;  slog::Index** mkcat_ansindex38;  slog::Index** stardelta39;  slog::Index** derivdelta40;  slog::Index** mkcatdelta41;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord43({0, 1});
      slog::Relation* readrel44 = db->getRelation("deriv_ans");
      head_index[0] = readrel44->getIndex(ord43, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord45({2, 0, 1});
      slog::Relation* readrel46 = db->getRelation("deriv");
      derivindex32 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({2, 0, 1});
      slog::Relation* readrel48 = db->getRelation("mkcat");
      mkcatindex33 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("star");
      starindex34 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("star");
      stardelta39 = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({1, 2, 0});
      slog::Relation* readrel54 = db->getRelation("deriv");
      derivindex35 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 0});
      slog::Relation* readrel56 = db->getRelation("deriv");
      derivdelta40 = readrel56->getIndex(ord55, true);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("deriv_ans");
      deriv_ansindex36 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("mkcat");
      mkcatindex37 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("mkcat");
      mkcatdelta41 = readrel62->getIndex(ord61, true);
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("mkcat_ans");
      mkcat_ansindex38 = readrel64->getIndex(ord63, false);
  
    }
    ReadTask42(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<3,1>(derivindex32, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mkcatindex33, std::array<u64,3>{v_c16, 0, 0})) return;
        slog::join_probe_old<2,1>(starindex34, stardelta39, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m65) {
          u64 v_c18 = m65[1];
          slog::join_probe_old<3,2>(derivindex35, derivdelta40, std::array<u64,3>{v_c18, v_c17, 0}, [&](const std::array<u64,3>& m66) {
            u64 v_c19 = m66[2];
            slog::join_probe<2,1>(deriv_ansindex36, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m67) {
              u64 v_c20 = m67[1];
              slog::join_probe_old<3,2>(mkcatindex37, mkcatdelta41, std::array<u64,3>{v_c20, v_c16, 0}, [&](const std::array<u64,3>& m68) {
                u64 v_c21 = m68[2];
                slog::join_probe<2,1>(mkcat_ansindex38, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m69) {
                  u64 v_c22 = m69[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c15, v_c22}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:deriv", _fires);
  
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
  // (crule (pre) (scan nullable __t0lgX114 s) (body (exists $sup14449x46x0x0x0 (2 0 1) 1 s) (exists alt (2 0 1) 1 s) (join nullable_ans (0 1) 1 __t0lgX114 __v1) (join $sup14449x46x0x0x0 (2 0 1) 1 s __t4S29112 r) (exists nullable (1 0) 1 r) (join alt (1 2 0) 2 r s __t8cCt111) (join nullable (0 1) 2 __t4S29112 __t8cCt111) (join nullable (1 0) 1 r __t6Byf113) (join nullable_ans (0 1) 1 __t6Byf113 __v0) (let __t1cXu110 (max __v0 __v1))) (head (emit-temp temp31LP324 __t1cXu110 __t4S29112)) antimirov.slog:47 #f)
  class ReadTask79 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x46x0x0x0index70;  slog::Index** altindex71;  slog::Index** nullable_ansindex72;  slog::Index** $sup14449x46x0x0x0index73;  slog::Index** nullableindex74;  slog::Index** altindex75;  slog::Index** nullableindex76;  slog::Index** nullableindex77;  slog::Index** nullable_ansindex78;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp31LP324");
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord80({2, 0, 1});
      slog::Relation* readrel81 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0index70 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({2, 0, 1});
      slog::Relation* readrel83 = db->getRelation("alt");
      altindex71 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("nullable_ans");
      nullable_ansindex72 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({2, 0, 1});
      slog::Relation* readrel87 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0index73 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 0});
      slog::Relation* readrel89 = db->getRelation("nullable");
      nullableindex74 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 2, 0});
      slog::Relation* readrel91 = db->getRelation("alt");
      altindex75 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({0, 1});
      slog::Relation* readrel93 = db->getRelation("nullable");
      nullableindex76 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0});
      slog::Relation* readrel95 = db->getRelation("nullable");
      nullableindex77 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({0, 1});
      slog::Relation* readrel97 = db->getRelation("nullable_ans");
      nullable_ansindex78 = readrel97->getIndex(ord96, false);
  
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
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        if (!slog::exists_probe<3,1>($sup14449x46x0x0x0index70, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<3,1>(altindex71, std::array<u64,3>{v_c24, 0, 0})) return;
        slog::join_probe<2,1>(nullable_ansindex72, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m98) {
          u64 v_c22 = m98[1];
          slog::join_probe<3,1>($sup14449x46x0x0x0index73, std::array<u64,3>{v_c24, 0, 0}, [&](const std::array<u64,3>& m99) {
            u64 v_c25 = m99[1]; u64 v_c18 = m99[2];
            if (!slog::exists_probe<2,1>(nullableindex74, std::array<u64,2>{v_c18, 0})) return;
            slog::join_probe<3,2>(altindex75, std::array<u64,3>{v_c18, v_c24, 0}, [&](const std::array<u64,3>& m100) {
              u64 v_c26 = m100[2];
              slog::join_probe<2,2>(nullableindex76, std::array<u64,2>{v_c25, v_c26}, [&](const std::array<u64,2>& m101) {
                slog::join_probe<2,1>(nullableindex77, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m102) {
                  u64 v_c27 = m102[1];
                  slog::join_probe<2,1>(nullable_ansindex78, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m103) {
                    u64 v_c20 = m103[1];
                    u64 v_c28 = _prim_max(db, v_c20, v_c22);
                    if (v_c28 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:47"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c28, v_c25});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:nullable", _fires);
  
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
  // (crule (pre) (scan $sup14449x46x0x0x0 __t4S29112 r s) (body (exists nullable (1 0) 1 r) (exists nullable (1 0) 1 s) (join-old alt (1 2 0) 2 (1 2 0) r s __t8cCt111) (join-old nullable (0 1) 2 (0 1) __t4S29112 __t8cCt111) (join-old nullable (1 0) 1 (1 0) r __t6Byf113) (join nullable_ans (0 1) 1 __t6Byf113 __v0) (join-old nullable (1 0) 1 (1 0) s __t0lgX114) (join nullable_ans (0 1) 1 __t0lgX114 __v1) (let __t1cXu110 (max __v0 __v1))) (head (emit-temp temp31LP324 __t1cXu110 __t4S29112)) antimirov.slog:47 #f)
  class ReadTask116 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex104;  slog::Index** nullableindex105;  slog::Index** altindex106;  slog::Index** nullableindex107;  slog::Index** nullableindex108;  slog::Index** nullable_ansindex109;  slog::Index** nullableindex110;  slog::Index** nullable_ansindex111;  slog::Index** altdelta112;  slog::Index** nullabledelta113;  slog::Index** nullabledelta114;  slog::Index** nullabledelta115;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp31LP324");
      outer_rel = db->getRelation("$sup14449x46x0x0x0");
      std::vector<u16> ord117({1, 0});
      slog::Relation* readrel118 = db->getRelation("nullable");
      nullableindex104 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({1, 0});
      slog::Relation* readrel120 = db->getRelation("nullable");
      nullableindex105 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("alt");
      altindex106 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 0});
      slog::Relation* readrel124 = db->getRelation("alt");
      altdelta112 = readrel124->getIndex(ord123, true);
      std::vector<u16> ord125({0, 1});
      slog::Relation* readrel126 = db->getRelation("nullable");
      nullableindex107 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({0, 1});
      slog::Relation* readrel128 = db->getRelation("nullable");
      nullabledelta113 = readrel128->getIndex(ord127, true);
      std::vector<u16> ord129({1, 0});
      slog::Relation* readrel130 = db->getRelation("nullable");
      nullableindex108 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({1, 0});
      slog::Relation* readrel132 = db->getRelation("nullable");
      nullabledelta114 = readrel132->getIndex(ord131, true);
      std::vector<u16> ord133({0, 1});
      slog::Relation* readrel134 = db->getRelation("nullable_ans");
      nullable_ansindex109 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 0});
      slog::Relation* readrel136 = db->getRelation("nullable");
      nullableindex110 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 0});
      slog::Relation* readrel138 = db->getRelation("nullable");
      nullabledelta115 = readrel138->getIndex(ord137, true);
      std::vector<u16> ord139({0, 1});
      slog::Relation* readrel140 = db->getRelation("nullable_ans");
      nullable_ansindex111 = readrel140->getIndex(ord139, false);
  
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
        u64 v_c25 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c24 = _t[2];
        if (!slog::exists_probe<2,1>(nullableindex104, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(nullableindex105, std::array<u64,2>{v_c24, 0})) return;
        slog::join_probe_old<3,2>(altindex106, altdelta112, std::array<u64,3>{v_c18, v_c24, 0}, [&](const std::array<u64,3>& m141) {
          u64 v_c26 = m141[2];
          slog::join_probe_old<2,2>(nullableindex107, nullabledelta113, std::array<u64,2>{v_c25, v_c26}, [&](const std::array<u64,2>& m142) {
            slog::join_probe_old<2,1>(nullableindex108, nullabledelta114, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m143) {
              u64 v_c27 = m143[1];
              slog::join_probe<2,1>(nullable_ansindex109, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m144) {
                u64 v_c20 = m144[1];
                slog::join_probe_old<2,1>(nullableindex110, nullabledelta115, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m145) {
                  u64 v_c23 = m145[1];
                  slog::join_probe<2,1>(nullable_ansindex111, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m146) {
                    u64 v_c22 = m146[1];
                    u64 v_c28 = _prim_max(db, v_c20, v_c22);
                    if (v_c28 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:47"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c28, v_c25});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:$sup14449x46x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst9dp567 const6d8bc911abd31f57d1b91158) (let __tconst77RG62 constac8d8342bbb2362d13f0a559) (let __tconst7i6460 constc100f95c1913f9c72fc1f4ef)) (scan cat __t2gMK59 __t8Axk58 __t9z7256) (body (join chr (0 1) 2 __t8Axk58 __tconst77RG62) (exists alt (1 2 0) 1 __t8Axk58) (join chr (1 0) 1 __tconst7i6460 __t7SBZ53) (exists alt (1 2 0) 2 __t8Axk58 __t7SBZ53) (join cat (0 1 2) 2 __t9z7256 __t7SBZ53 dup8qvH319) (eq __t7SBZ53 dup8qvH319) (join alt (1 2 0) 2 __t8Axk58 __t7SBZ53 __t8pHj64) (join star (1 0) 1 __t8pHj64 __t5cfw65)) (head (mkstruct cat (1 2 0) __t3C3W66 __t5cfw65 __t2gMK59)) antimirov.slog:126 #f)
  class ReadTask154 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** chrindex147;  slog::Index** altindex148;  slog::Index** chrindex149;  slog::Index** altindex150;  slog::Index** catindex151;  slog::Index** altindex152;  slog::Index** starindex153;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("cat");
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord155({0, 1});
      slog::Relation* readrel156 = db->getRelation("chr");
      chrindex147 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 2, 0});
      slog::Relation* readrel158 = db->getRelation("alt");
      altindex148 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 0});
      slog::Relation* readrel160 = db->getRelation("chr");
      chrindex149 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 0});
      slog::Relation* readrel162 = db->getRelation("alt");
      altindex150 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({0, 1, 2});
      slog::Relation* readrel164 = db->getRelation("cat");
      catindex151 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 2, 0});
      slog::Relation* readrel166 = db->getRelation("alt");
      altindex152 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("star");
      starindex153 = readrel168->getIndex(ord167, false);
  
    }
    ReadTask154(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c7 = v_const6d8bc911abd31f57d1b91158;
      u64 v_c8 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c9 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c29 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c10 = _t[2];
        slog::join_probe<2,2>(chrindex147, std::array<u64,2>{v_c13, v_c8}, [&](const std::array<u64,2>& m169) {
          if (!slog::exists_probe<3,1>(altindex148, std::array<u64,3>{v_c13, 0, 0})) return;
          slog::join_probe<2,1>(chrindex149, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m170) {
            u64 v_c11 = m170[1];
            if (!slog::exists_probe<3,2>(altindex150, std::array<u64,3>{v_c13, v_c11, 0})) return;
            slog::join_probe<3,2>(catindex151, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m171) {
              u64 v_c30 = m171[2];
              if (v_c11 != v_c30) return;
              slog::join_probe<3,2>(altindex152, std::array<u64,3>{v_c13, v_c11, 0}, [&](const std::array<u64,3>& m172) {
                u64 v_c14 = m172[2];
                slog::join_probe<2,1>(starindex153, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m173) {
                  u64 v_c31 = m173[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c31, v_c29}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:126", "delta:cat", _fires);
  
      if (!_done)
      {
        ReadTask154* _cont = new ReadTask154(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask154(db,b), false);
  // (crule (pre) (scan cat __t7ukI68 r s) (body (join frag (0) 1 __t7ukI68)) (head (emit frag (0) s) (emit frag (0) r)) antimirov.slog:106 #f)
  class ReadTask175 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** fragindex174;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("frag");
      std::vector<u16> ord176({0});
      slog::Relation* readrel177 = db->getRelation("frag");
      head_index[0] = readrel177->getIndex(ord176, false);
      head_rel[1] = db->getRelation("frag");
      std::vector<u16> ord178({0});
      slog::Relation* readrel179 = db->getRelation("frag");
      head_index[1] = readrel179->getIndex(ord178, false);
      outer_rel = db->getRelation("cat");
      std::vector<u16> ord180({0});
      slog::Relation* readrel181 = db->getRelation("frag");
      fragindex174 = readrel181->getIndex(ord180, false);
  
    }
    ReadTask175(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c24 = _t[2];
        slog::join_probe<1,1>(fragindex174, std::array<u64,1>{v_c32}, [&](const std::array<u64,1>& m182) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:106", "delta:cat", _fires);
  
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
  // (crule (pre) (scan nullable_ans __t5WkW89 __v1) (body (join-old nullable (0 1) 1 (0 1) __t5WkW89 s) (exists cat (2 0 1) 1 s) (join-old $sup14449x45x0x0x0 (2 0 1) 1 (2 0 1) s __t7U0R87 r) (exists nullable (1 0) 1 r) (join-old cat (1 2 0) 2 (1 2 0) r s __t3mF986) (join-old nullable (0 1) 2 (0 1) __t7U0R87 __t3mF986) (join-old nullable (1 0) 1 (1 0) r __t7OBQ88) (join nullable_ans (0 1) 1 __t7OBQ88 __v0) (let __t18aQ85 (_0002a __v0 __v1))) (head (emit-temp temp8Et3328 __t18aQ85 __t7U0R87)) antimirov.slog:46 #f)
  class ReadTask196 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex183;  slog::Index** catindex184;  slog::Index** $sup14449x45x0x0x0index185;  slog::Index** nullableindex186;  slog::Index** catindex187;  slog::Index** nullableindex188;  slog::Index** nullableindex189;  slog::Index** nullable_ansindex190;  slog::Index** nullabledelta191;  slog::Index** $sup14449x45x0x0x0delta192;  slog::Index** catdelta193;  slog::Index** nullabledelta194;  slog::Index** nullabledelta195;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Et3328");
      outer_rel = db->getRelation("nullable_ans");
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("nullable");
      nullableindex183 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({0, 1});
      slog::Relation* readrel200 = db->getRelation("nullable");
      nullabledelta191 = readrel200->getIndex(ord199, true);
      std::vector<u16> ord201({2, 0, 1});
      slog::Relation* readrel202 = db->getRelation("cat");
      catindex184 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({2, 0, 1});
      slog::Relation* readrel204 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0index185 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({2, 0, 1});
      slog::Relation* readrel206 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0delta192 = readrel206->getIndex(ord205, true);
      std::vector<u16> ord207({1, 0});
      slog::Relation* readrel208 = db->getRelation("nullable");
      nullableindex186 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 0});
      slog::Relation* readrel210 = db->getRelation("cat");
      catindex187 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 0});
      slog::Relation* readrel212 = db->getRelation("cat");
      catdelta193 = readrel212->getIndex(ord211, true);
      std::vector<u16> ord213({0, 1});
      slog::Relation* readrel214 = db->getRelation("nullable");
      nullableindex188 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({0, 1});
      slog::Relation* readrel216 = db->getRelation("nullable");
      nullabledelta194 = readrel216->getIndex(ord215, true);
      std::vector<u16> ord217({1, 0});
      slog::Relation* readrel218 = db->getRelation("nullable");
      nullableindex189 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 0});
      slog::Relation* readrel220 = db->getRelation("nullable");
      nullabledelta195 = readrel220->getIndex(ord219, true);
      std::vector<u16> ord221({0, 1});
      slog::Relation* readrel222 = db->getRelation("nullable_ans");
      nullable_ansindex190 = readrel222->getIndex(ord221, false);
  
    }
    ReadTask196(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[1];
        slog::join_probe_old<2,1>(nullableindex183, nullabledelta191, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m223) {
          u64 v_c24 = m223[1];
          if (!slog::exists_probe<3,1>(catindex184, std::array<u64,3>{v_c24, 0, 0})) return;
          slog::join_probe_old<3,1>($sup14449x45x0x0x0index185, $sup14449x45x0x0x0delta192, std::array<u64,3>{v_c24, 0, 0}, [&](const std::array<u64,3>& m224) {
            u64 v_c34 = m224[1]; u64 v_c18 = m224[2];
            if (!slog::exists_probe<2,1>(nullableindex186, std::array<u64,2>{v_c18, 0})) return;
            slog::join_probe_old<3,2>(catindex187, catdelta193, std::array<u64,3>{v_c18, v_c24, 0}, [&](const std::array<u64,3>& m225) {
              u64 v_c35 = m225[2];
              slog::join_probe_old<2,2>(nullableindex188, nullabledelta194, std::array<u64,2>{v_c34, v_c35}, [&](const std::array<u64,2>& m226) {
                slog::join_probe_old<2,1>(nullableindex189, nullabledelta195, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m227) {
                  u64 v_c36 = m227[1];
                  slog::join_probe<2,1>(nullable_ansindex190, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m228) {
                    u64 v_c20 = m228[1];
                    u64 v_c37 = _prim__0002a(db, v_c20, v_c22);
                    if (v_c37 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:46"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c37, v_c34});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:nullable_ans", _fires);
  
      if (!_done)
      {
        ReadTask196* _cont = new ReadTask196(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask196(db,b), false);
  // (crule (pre (let __tconst06uO43 const6b86b273ff34fce19d6b804e)) (scan nullable __t4mn745 __t51g944) (body (join star (0 1) 1 __t51g944 r)) (head (emit nullable_ans (0 1) __t4mn745 __tconst06uO43)) antimirov.slog:45 #f)
  class ReadTask230 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** starindex229;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("nullable_ans");
      std::vector<u16> ord231({0, 1});
      slog::Relation* readrel232 = db->getRelation("nullable_ans");
      head_index[0] = readrel232->getIndex(ord231, false);
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord233({0, 1});
      slog::Relation* readrel234 = db->getRelation("star");
      starindex229 = readrel234->getIndex(ord233, false);
  
    }
    ReadTask230(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
  
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
        slog::join_probe<2,1>(starindex229, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m235) {
          u64 v_c18 = m235[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c39, v_c38}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:45", "delta:nullable", _fires);
  
      if (!_done)
      {
        ReadTask230* _cont = new ReadTask230(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask230(db,b), false);
  // (crule (pre (let __trid5cU6210 const2c070a9498052f6e608df512) (let __trel5VW7211 constd1596cb698715803872591d6) (let __tcol14IL212 const5feceb66ffc86f38d952786c)) (scan $sup14449x46x0x0x0 __d0 r s) (body) (head (tycheck s (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid5cU6210 __trel5VW7211 __tcol14IL212 (1 2 3 4 0)) (mkstruct nullable (1 0) __2gMC209 s)) antimirov.slog:47 #f)
  class ReadTask241 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid239;  u32 sid236;  u32 sid237;  u32 sid238;  u32 sid240;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("nullable");
      outer_rel = db->getRelation("$sup14449x46x0x0x0");
      sid239 = db->getRelation("_enum")->getStructId();
      sid236 = db->getRelation("alt")->getStructId();
      sid237 = db->getRelation("cat")->getStructId();
      sid238 = db->getRelation("chr")->getStructId();
      sid240 = db->getRelation("star")->getStructId();
  
    }
    ReadTask241(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const2c070a9498052f6e608df512;
      u64 v_c42 = v_constd1596cb698715803872591d6;
      u64 v_c43 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c24 = _t[2];
        ++_fires;
        if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid236 || decode_struct_id(v_c24) == sid237 || decode_struct_id(v_c24) == sid238 || decode_struct_id(v_c24) == sid239 || decode_struct_id(v_c24) == sid240))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c41, v_c42, v_c43, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:$sup14449x46x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask241* _cont = new ReadTask241(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask241(db,b), false);
  // (crule (pre) (scan frag __t7ukI68) (body (join-old cat (0 1 2) 1 (0 1 2) __t7ukI68 r s)) (head (emit frag (0) s) (emit frag (0) r)) antimirov.slog:106 #f)
  class ReadTask244 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** catindex242;  slog::Index** catdelta243;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("frag");
      std::vector<u16> ord245({0});
      slog::Relation* readrel246 = db->getRelation("frag");
      head_index[0] = readrel246->getIndex(ord245, false);
      head_rel[1] = db->getRelation("frag");
      std::vector<u16> ord247({0});
      slog::Relation* readrel248 = db->getRelation("frag");
      head_index[1] = readrel248->getIndex(ord247, false);
      outer_rel = db->getRelation("frag");
      std::vector<u16> ord249({0, 1, 2});
      slog::Relation* readrel250 = db->getRelation("cat");
      catindex242 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({0, 1, 2});
      slog::Relation* readrel252 = db->getRelation("cat");
      catdelta243 = readrel252->getIndex(ord251, true);
  
    }
    ReadTask244(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[0];
        slog::join_probe_old<3,1>(catindex242, catdelta243, std::array<u64,3>{v_c32, 0, 0}, [&](const std::array<u64,3>& m253) {
          u64 v_c18 = m253[1]; u64 v_c24 = m253[2];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
          slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:106", "delta:frag", _fires);
  
      if (!_done)
      {
        ReadTask244* _cont = new ReadTask244(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask244(db,b), false);
  // (crule (pre (let __tconst4GwN227 constabce180ee56b2c323c19f642) (let __tconst0cw9129 const6b86b273ff34fce19d6b804e)) (scan nullable __t9TtP131 __t7D7Q130) (body (join _enum (0 1) 2 __t7D7Q130 __tconst4GwN227)) (head (emit nullable_ans (0 1) __t9TtP131 __tconst0cw9129)) antimirov.slog:43 #f)
  class ReadTask255 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex254;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("nullable_ans");
      std::vector<u16> ord256({0, 1});
      slog::Relation* readrel257 = db->getRelation("nullable_ans");
      head_index[0] = readrel257->getIndex(ord256, false);
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord258({0, 1});
      slog::Relation* readrel259 = db->getRelation("_enum");
      _enumindex254 = readrel259->getIndex(ord258, false);
  
    }
    ReadTask255(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_constabce180ee56b2c323c19f642;
      u64 v_c46 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c47 = _t[0];
        u64 v_c48 = _t[1];
        slog::join_probe<2,2>(_enumindex254, std::array<u64,2>{v_c48, v_c45}, [&](const std::array<u64,2>& m260) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c47, v_c46}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:43", "delta:nullable", _fires);
  
      if (!_done)
      {
        ReadTask255* _cont = new ReadTask255(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask255(db,b), false);
  // (crule (pre) (scan deriv __t72SS120 s c) (body (exists alt (2 0 1) 1 s) (exists deriv (2 0 1) 1 c) (exists deriv_ans (0 1) 1 __t72SS120) (join $sup14449x69x0x0x0 (1 3 0 2) 2 c s __t0tyF119 r) (exists deriv (2 0 1) 2 c __t0tyF119) (join alt (1 2 0) 2 r s __t2ubg118) (join deriv (0 1 2) 3 __t0tyF119 __t2ubg118 c) (join deriv_ans (0 1) 1 __t72SS120 __v0)) (head (emit deriv_ans (0 1) __t0tyF119 __v0)) antimirov.slog:70 #f)
  class ReadTask269 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** altindex261;  slog::Index** derivindex262;  slog::Index** deriv_ansindex263;  slog::Index** $sup14449x69x0x0x0index264;  slog::Index** derivindex265;  slog::Index** altindex266;  slog::Index** derivindex267;  slog::Index** deriv_ansindex268;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("deriv_ans");
      head_index[0] = readrel271->getIndex(ord270, false);
      outer_rel = db->getRelation("deriv");
      std::vector<u16> ord272({2, 0, 1});
      slog::Relation* readrel273 = db->getRelation("alt");
      altindex261 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({2, 0, 1});
      slog::Relation* readrel275 = db->getRelation("deriv");
      derivindex262 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({0, 1});
      slog::Relation* readrel277 = db->getRelation("deriv_ans");
      deriv_ansindex263 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({1, 3, 0, 2});
      slog::Relation* readrel279 = db->getRelation("$sup14449x69x0x0x0");
      $sup14449x69x0x0x0index264 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({2, 0, 1});
      slog::Relation* readrel281 = db->getRelation("deriv");
      derivindex265 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({1, 2, 0});
      slog::Relation* readrel283 = db->getRelation("alt");
      altindex266 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({0, 1, 2});
      slog::Relation* readrel285 = db->getRelation("deriv");
      derivindex267 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({0, 1});
      slog::Relation* readrel287 = db->getRelation("deriv_ans");
      deriv_ansindex268 = readrel287->getIndex(ord286, false);
  
    }
    ReadTask269(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<3,1>(altindex261, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<3,1>(derivindex262, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<2,1>(deriv_ansindex263, std::array<u64,2>{v_c49, 0})) return;
        slog::join_probe<4,2>($sup14449x69x0x0x0index264, std::array<u64,4>{v_c17, v_c24, 0, 0}, [&](const std::array<u64,4>& m288) {
          u64 v_c50 = m288[2]; u64 v_c18 = m288[3];
          if (!slog::exists_probe<3,2>(derivindex265, std::array<u64,3>{v_c17, v_c50, 0})) return;
          slog::join_probe<3,2>(altindex266, std::array<u64,3>{v_c18, v_c24, 0}, [&](const std::array<u64,3>& m289) {
            u64 v_c51 = m289[2];
            slog::join_probe<3,3>(derivindex267, std::array<u64,3>{v_c50, v_c51, v_c17}, [&](const std::array<u64,3>& m290) {
              slog::join_probe<2,1>(deriv_ansindex268, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m291) {
                u64 v_c20 = m291[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c20}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:70", "delta:deriv", _fires);
  
      if (!_done)
      {
        ReadTask269* _cont = new ReadTask269(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask269(db,b), false);
  // (crule (pre) (scan star __t7r4Z93 a) (body (join-old mkcat (1 2 0) 1 (1 2 0) __t7r4Z93 s __t08Xq94)) (head (emit-temp temp5pCD310 __t08Xq94 __t7r4Z93 s) (mkstruct cat (1 2 0) __t7HJf92 __t7r4Z93 s)) antimirov.slog:60 #f)
  class ReadTask294 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcatindex292;  slog::Index** mkcatdelta293;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5pCD310");
      head_rel[1] = db->getRelation("cat");
      outer_rel = db->getRelation("star");
      std::vector<u16> ord295({1, 2, 0});
      slog::Relation* readrel296 = db->getRelation("mkcat");
      mkcatindex292 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 2, 0});
      slog::Relation* readrel298 = db->getRelation("mkcat");
      mkcatdelta293 = readrel298->getIndex(ord297, true);
  
    }
    ReadTask294(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[0];
        u64 v_c53 = _t[1];
        slog::join_probe_old<3,1>(mkcatindex292, mkcatdelta293, std::array<u64,3>{v_c52, 0, 0}, [&](const std::array<u64,3>& m299) {
          u64 v_c24 = m299[1]; u64 v_c54 = m299[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c54, v_c52, v_c24});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c52, v_c24}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:60", "delta:star", _fires);
  
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
  // (crule (pre) (scan query nm r) (body) (head (emit state (0) r)) antimirov.slog:114 #f)
  class ReadTask300 : public slog::Task
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
      head_rel[0] = db->getRelation("state");
      std::vector<u16> ord301({0});
      slog::Relation* readrel302 = db->getRelation("state");
      head_index[0] = readrel302->getIndex(ord301, false);
      outer_rel = db->getRelation("query");
  
    }
    ReadTask300(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c55 = _t[0];
        u64 v_c18 = _t[1];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:114", "delta:query", _fires);
  
      if (!_done)
      {
        ReadTask300* _cont = new ReadTask300(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask300(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre6Q8t306 __errf1NOY307 __errf2Edh308) (body) (head (emit error (0) __erre6Q8t306)) <internal>:1 #f)
  class ReadTask303 : public slog::Task
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
      std::vector<u16> ord304({0});
      slog::Relation* readrel305 = db->getRelation("error");
      head_index[0] = readrel305->getIndex(ord304, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask303(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[1];
        u64 v_c58 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c56}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask303* _cont = new ReadTask303(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask303(db,b), false);
  // (crule (pre (let __tconst9dp567 const6d8bc911abd31f57d1b91158) (let __tconst77RG62 constac8d8342bbb2362d13f0a559) (let __tconst7i6460 constc100f95c1913f9c72fc1f4ef)) (once) (body) (head (mkstruct chr (1 0) __t8Axk58 __tconst77RG62) (mkstruct chr (1 0) __t7SBZ53 __tconst7i6460)) antimirov.slog:126 #f)
  class ReadTask306 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("chr");
      head_rel[1] = db->getRelation("chr");
  
    }
    ReadTask306(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c7 = v_const6d8bc911abd31f57d1b91158;
      u64 v_c8 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c9 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c9}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:126", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask306(db,b), true);
  // (crule (pre) (scan nullable __t7OBQ88 r) (body (exists $sup14449x45x0x0x0 (1 2 0) 1 r) (exists cat (1 2 0) 1 r) (join nullable_ans (0 1) 1 __t7OBQ88 __v0) (join $sup14449x45x0x0x0 (1 2 0) 1 r s __t7U0R87) (exists nullable (1 0) 1 s) (join cat (1 2 0) 2 r s __t3mF986) (join nullable (0 1) 2 __t7U0R87 __t3mF986) (join-old nullable (1 0) 1 (1 0) s __t5WkW89) (join nullable_ans (0 1) 1 __t5WkW89 __v1) (let __t18aQ85 (_0002a __v0 __v1))) (head (emit-temp temp8Et3328 __t18aQ85 __t7U0R87)) antimirov.slog:46 #f)
  class ReadTask317 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup14449x45x0x0x0index307;  slog::Index** catindex308;  slog::Index** nullable_ansindex309;  slog::Index** $sup14449x45x0x0x0index310;  slog::Index** nullableindex311;  slog::Index** catindex312;  slog::Index** nullableindex313;  slog::Index** nullableindex314;  slog::Index** nullable_ansindex315;  slog::Index** nullabledelta316;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8Et3328");
      outer_rel = db->getRelation("nullable");
      std::vector<u16> ord318({1, 2, 0});
      slog::Relation* readrel319 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0index307 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({1, 2, 0});
      slog::Relation* readrel321 = db->getRelation("cat");
      catindex308 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({0, 1});
      slog::Relation* readrel323 = db->getRelation("nullable_ans");
      nullable_ansindex309 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 2, 0});
      slog::Relation* readrel325 = db->getRelation("$sup14449x45x0x0x0");
      $sup14449x45x0x0x0index310 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 0});
      slog::Relation* readrel327 = db->getRelation("nullable");
      nullableindex311 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 2, 0});
      slog::Relation* readrel329 = db->getRelation("cat");
      catindex312 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({0, 1});
      slog::Relation* readrel331 = db->getRelation("nullable");
      nullableindex313 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 0});
      slog::Relation* readrel333 = db->getRelation("nullable");
      nullableindex314 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 0});
      slog::Relation* readrel335 = db->getRelation("nullable");
      nullabledelta316 = readrel335->getIndex(ord334, true);
      std::vector<u16> ord336({0, 1});
      slog::Relation* readrel337 = db->getRelation("nullable_ans");
      nullable_ansindex315 = readrel337->getIndex(ord336, false);
  
    }
    ReadTask317(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c18 = _t[1];
        if (!slog::exists_probe<3,1>($sup14449x45x0x0x0index307, std::array<u64,3>{v_c18, 0, 0})) return;
        if (!slog::exists_probe<3,1>(catindex308, std::array<u64,3>{v_c18, 0, 0})) return;
        slog::join_probe<2,1>(nullable_ansindex309, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m338) {
          u64 v_c20 = m338[1];
          slog::join_probe<3,1>($sup14449x45x0x0x0index310, std::array<u64,3>{v_c18, 0, 0}, [&](const std::array<u64,3>& m339) {
            u64 v_c24 = m339[1]; u64 v_c34 = m339[2];
            if (!slog::exists_probe<2,1>(nullableindex311, std::array<u64,2>{v_c24, 0})) return;
            slog::join_probe<3,2>(catindex312, std::array<u64,3>{v_c18, v_c24, 0}, [&](const std::array<u64,3>& m340) {
              u64 v_c35 = m340[2];
              slog::join_probe<2,2>(nullableindex313, std::array<u64,2>{v_c34, v_c35}, [&](const std::array<u64,2>& m341) {
                slog::join_probe_old<2,1>(nullableindex314, nullabledelta316, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m342) {
                  u64 v_c33 = m342[1];
                  slog::join_probe<2,1>(nullable_ansindex315, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m343) {
                    u64 v_c22 = m343[1];
                    u64 v_c37 = _prim__0002a(db, v_c20, v_c22);
                    if (v_c37 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:46"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c37, v_c34});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:46", "delta:nullable", _fires);
  
      if (!_done)
      {
        ReadTask317* _cont = new ReadTask317(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask317(db,b), false);
  // (crule (pre (let __tconst53SJ104 const439d97756c1f6d8e3f1b29c9) (let __tconst3Xg1100 constac8d8342bbb2362d13f0a559) (let __tconst8qEb95 constc100f95c1913f9c72fc1f4ef)) (seeded) (body (join chr (1 0) 1 __tconst3Xg1100 __t4w1Y98) (exists cat (1 2 0) 1 __t4w1Y98) (exists alt (1 2 0) 1 __t4w1Y98) (join chr (1 0) 1 __tconst8qEb95 __t6I9I96) (join cat (1 2 0) 2 __t4w1Y98 __t6I9I96 __t4yUC99) (join alt (1 2 0) 2 __t4w1Y98 __t4yUC99 __t5G2v102)) (head (mkstruct star (1 0) __t4CfV103 __t5G2v102)) antimirov.slog:130 #f)
  class ReadTask350 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** chrindex344;  slog::Index** catindex345;  slog::Index** altindex346;  slog::Index** chrindex347;  slog::Index** catindex348;  slog::Index** altindex349;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("star");
      std::vector<u16> ord351({1, 0});
      slog::Relation* readrel352 = db->getRelation("star");
      head_index[0] = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 0});
      slog::Relation* readrel354 = db->getRelation("chr");
      chrindex344 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 2, 0});
      slog::Relation* readrel356 = db->getRelation("cat");
      catindex345 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({1, 2, 0});
      slog::Relation* readrel358 = db->getRelation("alt");
      altindex346 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({1, 0});
      slog::Relation* readrel360 = db->getRelation("chr");
      chrindex347 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 2, 0});
      slog::Relation* readrel362 = db->getRelation("cat");
      catindex348 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({1, 2, 0});
      slog::Relation* readrel364 = db->getRelation("alt");
      altindex349 = readrel364->getIndex(ord363, false);
  
    }
    ReadTask350(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const439d97756c1f6d8e3f1b29c9;
      u64 v_c1 = v_constac8d8342bbb2362d13f0a559;
      u64 v_c2 = v_constc100f95c1913f9c72fc1f4ef;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(chrindex344, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m365) {
        u64 v_c4 = m365[1];
        if (!slog::exists_probe<3,1>(catindex345, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(altindex346, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(chrindex347, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m366) {
          u64 v_c6 = m366[1];
          slog::join_probe<3,2>(catindex348, std::array<u64,3>{v_c4, v_c6, 0}, [&](const std::array<u64,3>& m367) {
            u64 v_c5 = m367[2];
            slog::join_probe<3,2>(altindex349, std::array<u64,3>{v_c4, v_c5, 0}, [&](const std::array<u64,3>& m368) {
              u64 v_c3 = m368[2];
              ++_fires;
              slog::emit_struct_checked<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:130", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask350(db,b));
  // (crule (pre) (scan star __t4ieC109 r) (body (join frag (0) 1 __t4ieC109)) (head (emit frag (0) r)) antimirov.slog:108 #f)
  class ReadTask370 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** fragindex369;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("frag");
      std::vector<u16> ord371({0});
      slog::Relation* readrel372 = db->getRelation("frag");
      head_index[0] = readrel372->getIndex(ord371, false);
      outer_rel = db->getRelation("star");
      std::vector<u16> ord373({0});
      slog::Relation* readrel374 = db->getRelation("frag");
      fragindex369 = readrel374->getIndex(ord373, false);
  
    }
    ReadTask370(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[0];
        u64 v_c18 = _t[1];
        slog::join_probe<1,1>(fragindex369, std::array<u64,1>{v_c59}, [&](const std::array<u64,1>& m375) {
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c18}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:108", "delta:star", _fires);
  
      if (!_done)
      {
        ReadTask370* _cont = new ReadTask370(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask370(db,b), false);
  // (crule (pre) (scan star __t3xJI4 r) (body (exists deriv (1 2 0) 1 r) (exists mkcat (2 0 1) 1 __t3xJI4) (join deriv (1 2 0) 1 __t3xJI4 c __t9dkM2) (join deriv (1 2 0) 2 r c __t70si3) (join deriv_ans (0 1) 1 __t70si3 __v0) (join-old mkcat (1 2 0) 2 (1 2 0) __v0 __t3xJI4 __t3A2z5) (join mkcat_ans (0 1) 1 __t3A2z5 __v1)) (head (emit deriv_ans (0 1) __t9dkM2 __v1)) antimirov.slog:73 #f)
  class ReadTask384 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex376;  slog::Index** mkcatindex377;  slog::Index** derivindex378;  slog::Index** derivindex379;  slog::Index** deriv_ansindex380;  slog::Index** mkcatindex381;  slog::Index** mkcat_ansindex382;  slog::Index** mkcatdelta383;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord385({0, 1});
      slog::Relation* readrel386 = db->getRelation("deriv_ans");
      head_index[0] = readrel386->getIndex(ord385, false);
      outer_rel = db->getRelation("star");
      std::vector<u16> ord387({1, 2, 0});
      slog::Relation* readrel388 = db->getRelation("deriv");
      derivindex376 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({2, 0, 1});
      slog::Relation* readrel390 = db->getRelation("mkcat");
      mkcatindex377 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 0});
      slog::Relation* readrel392 = db->getRelation("deriv");
      derivindex378 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 2, 0});
      slog::Relation* readrel394 = db->getRelation("deriv");
      derivindex379 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({0, 1});
      slog::Relation* readrel396 = db->getRelation("deriv_ans");
      deriv_ansindex380 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({1, 2, 0});
      slog::Relation* readrel398 = db->getRelation("mkcat");
      mkcatindex381 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("mkcat");
      mkcatdelta383 = readrel400->getIndex(ord399, true);
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("mkcat_ans");
      mkcat_ansindex382 = readrel402->getIndex(ord401, false);
  
    }
    ReadTask384(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[1];
        if (!slog::exists_probe<3,1>(derivindex376, std::array<u64,3>{v_c18, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mkcatindex377, std::array<u64,3>{v_c16, 0, 0})) return;
        slog::join_probe<3,1>(derivindex378, std::array<u64,3>{v_c16, 0, 0}, [&](const std::array<u64,3>& m403) {
          u64 v_c17 = m403[1]; u64 v_c15 = m403[2];
          slog::join_probe<3,2>(derivindex379, std::array<u64,3>{v_c18, v_c17, 0}, [&](const std::array<u64,3>& m404) {
            u64 v_c19 = m404[2];
            slog::join_probe<2,1>(deriv_ansindex380, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m405) {
              u64 v_c20 = m405[1];
              slog::join_probe_old<3,2>(mkcatindex381, mkcatdelta383, std::array<u64,3>{v_c20, v_c16, 0}, [&](const std::array<u64,3>& m406) {
                u64 v_c21 = m406[2];
                slog::join_probe<2,1>(mkcat_ansindex382, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m407) {
                  u64 v_c22 = m407[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c15, v_c22}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:73", "delta:star", _fires);
  
      if (!_done)
      {
        ReadTask384* _cont = new ReadTask384(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask384(db,b), false);
  // (crule (pre) (scan nullable_ans __t0lgX114 __v1) (body (join-old nullable (0 1) 1 (0 1) __t0lgX114 s) (exists alt (2 0 1) 1 s) (join-old $sup14449x46x0x0x0 (2 0 1) 1 (2 0 1) s __t4S29112 r) (exists nullable (1 0) 1 r) (join-old alt (1 2 0) 2 (1 2 0) r s __t8cCt111) (join-old nullable (0 1) 2 (0 1) __t4S29112 __t8cCt111) (join-old nullable (1 0) 1 (1 0) r __t6Byf113) (join nullable_ans (0 1) 1 __t6Byf113 __v0) (let __t1cXu110 (max __v0 __v1))) (head (emit-temp temp31LP324 __t1cXu110 __t4S29112)) antimirov.slog:47 #f)
  class ReadTask421 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** nullableindex408;  slog::Index** altindex409;  slog::Index** $sup14449x46x0x0x0index410;  slog::Index** nullableindex411;  slog::Index** altindex412;  slog::Index** nullableindex413;  slog::Index** nullableindex414;  slog::Index** nullable_ansindex415;  slog::Index** nullabledelta416;  slog::Index** $sup14449x46x0x0x0delta417;  slog::Index** altdelta418;  slog::Index** nullabledelta419;  slog::Index** nullabledelta420;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp31LP324");
      outer_rel = db->getRelation("nullable_ans");
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("nullable");
      nullableindex408 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({0, 1});
      slog::Relation* readrel425 = db->getRelation("nullable");
      nullabledelta416 = readrel425->getIndex(ord424, true);
      std::vector<u16> ord426({2, 0, 1});
      slog::Relation* readrel427 = db->getRelation("alt");
      altindex409 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({2, 0, 1});
      slog::Relation* readrel429 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0index410 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({2, 0, 1});
      slog::Relation* readrel431 = db->getRelation("$sup14449x46x0x0x0");
      $sup14449x46x0x0x0delta417 = readrel431->getIndex(ord430, true);
      std::vector<u16> ord432({1, 0});
      slog::Relation* readrel433 = db->getRelation("nullable");
      nullableindex411 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 2, 0});
      slog::Relation* readrel435 = db->getRelation("alt");
      altindex412 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 2, 0});
      slog::Relation* readrel437 = db->getRelation("alt");
      altdelta418 = readrel437->getIndex(ord436, true);
      std::vector<u16> ord438({0, 1});
      slog::Relation* readrel439 = db->getRelation("nullable");
      nullableindex413 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({0, 1});
      slog::Relation* readrel441 = db->getRelation("nullable");
      nullabledelta419 = readrel441->getIndex(ord440, true);
      std::vector<u16> ord442({1, 0});
      slog::Relation* readrel443 = db->getRelation("nullable");
      nullableindex414 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({1, 0});
      slog::Relation* readrel445 = db->getRelation("nullable");
      nullabledelta420 = readrel445->getIndex(ord444, true);
      std::vector<u16> ord446({0, 1});
      slog::Relation* readrel447 = db->getRelation("nullable_ans");
      nullable_ansindex415 = readrel447->getIndex(ord446, false);
  
    }
    ReadTask421(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[1];
        slog::join_probe_old<2,1>(nullableindex408, nullabledelta416, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m448) {
          u64 v_c24 = m448[1];
          if (!slog::exists_probe<3,1>(altindex409, std::array<u64,3>{v_c24, 0, 0})) return;
          slog::join_probe_old<3,1>($sup14449x46x0x0x0index410, $sup14449x46x0x0x0delta417, std::array<u64,3>{v_c24, 0, 0}, [&](const std::array<u64,3>& m449) {
            u64 v_c25 = m449[1]; u64 v_c18 = m449[2];
            if (!slog::exists_probe<2,1>(nullableindex411, std::array<u64,2>{v_c18, 0})) return;
            slog::join_probe_old<3,2>(altindex412, altdelta418, std::array<u64,3>{v_c18, v_c24, 0}, [&](const std::array<u64,3>& m450) {
              u64 v_c26 = m450[2];
              slog::join_probe_old<2,2>(nullableindex413, nullabledelta419, std::array<u64,2>{v_c25, v_c26}, [&](const std::array<u64,2>& m451) {
                slog::join_probe_old<2,1>(nullableindex414, nullabledelta420, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m452) {
                  u64 v_c27 = m452[1];
                  slog::join_probe<2,1>(nullable_ansindex415, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m453) {
                    u64 v_c20 = m453[1];
                    u64 v_c28 = _prim_max(db, v_c20, v_c22);
                    if (v_c28 == slog_error) { slog::emit_pending_error(db, "antimirov.slog:47"); return; }
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c28, v_c25});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:47", "delta:nullable_ans", _fires);
  
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
  // (crule (pre) (scan type_mismatch __erre0Dbi296 __errf6Q4u297 __errf8NEg298 __errf8bFs299 __errf5CV4300) (body) (head (emit error (0) __erre0Dbi296)) <internal>:1 #f)
  class ReadTask454 : public slog::Task
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
      std::vector<u16> ord455({0});
      slog::Relation* readrel456 = db->getRelation("error");
      head_index[0] = readrel456->getIndex(ord455, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask454(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c60 = _t[0];
        u64 v_c61 = _t[1];
        u64 v_c62 = _t[2];
        u64 v_c63 = _t[3];
        u64 v_c64 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c60}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask454* _cont = new ReadTask454(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask454(db,b), false);
  // (crule (pre (let __trid6QHg224 constf0add80747aca33dead79eea) (let __trel3sQp225 constd1596cb698715803872591d6) (let __tcol4JUN226 const5feceb66ffc86f38d952786c)) (scan $sup14449x71x0x0x0 __d0 c r s) (body) (head (tycheck r (accept (struct alt) (struct cat) (struct chr) (struct _enum) (struct star)) __trid6QHg224 __trel3sQp225 __tcol4JUN226 (1 2 3 4 0)) (mkstruct nullable (1 0) __2YvS223 r)) antimirov.slog:72 #f)
  class ReadTask462 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid460;  u32 sid457;  u32 sid458;  u32 sid459;  u32 sid461;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("nullable");
      outer_rel = db->getRelation("$sup14449x71x0x0x0");
      sid460 = db->getRelation("_enum")->getStructId();
      sid457 = db->getRelation("alt")->getStructId();
      sid458 = db->getRelation("cat")->getStructId();
      sid459 = db->getRelation("chr")->getStructId();
      sid461 = db->getRelation("star")->getStructId();
  
    }
    ReadTask462(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c65 = v_constf0add80747aca33dead79eea;
      u64 v_c66 = v_constd1596cb698715803872591d6;
      u64 v_c67 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c44 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c24 = _t[3];
        ++_fires;
        if (!((is_struct(v_c18) && (decode_struct_id(v_c18) == sid457 || decode_struct_id(v_c18) == sid458 || decode_struct_id(v_c18) == sid459 || decode_struct_id(v_c18) == sid460 || decode_struct_id(v_c18) == sid461))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c65, v_c66, v_c67, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("antimirov.slog:72", "delta:$sup14449x71x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask462* _cont = new ReadTask462(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask462(db,b), false);
  // (crule (pre) (scan mkcat_ans __t3Hfq20 __v1) (body (join-old mkcat (0 1 2) 1 (0 1 2) __t3Hfq20 __v0 s) (exists cat (2 0 1) 1 s) (exists $sup14449x70x0x0x0 (3 2 0 1) 1 s) (join deriv_ans (1 0) 1 __v0 __t3USy19) (join-old cat (2 0 1) 1 (2 0 1) s __t9RZg17 r) (exists $sup14449x70x0x0x0 (3 2 0 1) 2 s r) (exists deriv (1 2 0) 1 __t9RZg17) (join-old deriv (0 1 2) 2 (0 1 2) __t3USy19 r c) (exists deriv (1 2 0) 2 __t9RZg17 c) (join-old $sup14449x70x0x0x0 (1 2 3 0) 3 (1 2 3 0) c r s __t1fTl18) (join-old deriv (0 1 2) 3 (0 1 2) __t1fTl18 __t9RZg17 c)) (head (emit deriv_ans (0 1) __t1fTl18 __v1)) antimirov.slog:71 #f)
  class ReadTask479 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mkcatindex463;  slog::Index** catindex464;  slog::Index** $sup14449x70x0x0x0index465;  slog::Index** deriv_ansindex466;  slog::Index** catindex467;  slog::Index** $sup14449x70x0x0x0index468;  slog::Index** derivindex469;  slog::Index** derivindex470;  slog::Index** derivindex471;  slog::Index** $sup14449x70x0x0x0index472;  slog::Index** derivindex473;  slog::Index** mkcatdelta474;  slog::Index** catdelta475;  slog::Index** derivdelta476;  slog::Index** $sup14449x70x0x0x0delta477;  slog::Index** derivdelta478;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord480({0, 1});
      slog::Relation* readrel481 = db->getRelation("deriv_ans");
      head_index[0] = readrel481->getIndex(ord480, false);
      outer_rel = db->getRelation("mkcat_ans");
      std::vector<u16> ord482({0, 1, 2});
      slog::Relation* readrel483 = db->getRelation("mkcat");
      mkcatindex463 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({0, 1, 2});
      slog::Relation* readrel485 = db->getRelation("mkcat");
      mkcatdelta474 = readrel485->getIndex(ord484, true);
      std::vector<u16> ord486({2, 0, 1});
      slog::Relation* readrel487 = db->getRelation("cat");
      catindex464 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({3, 2, 0, 1});
      slog::Relation* readrel489 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index465 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 0});
      slog::Relation* readrel491 = db->getRelation("deriv_ans");
      deriv_ansindex466 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({2, 0, 1});
      slog::Relation* readrel493 = db->getRelation("cat");
      catindex467 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({2, 0, 1});
      slog::Relation* readrel495 = db->getRelation("cat");
      catdelta475 = readrel495->getIndex(ord494, true);
      std::vector<u16> ord496({3, 2, 0, 1});
      slog::Relation* readrel497 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index468 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({1, 2, 0});
      slog::Relation* readrel499 = db->getRelation("deriv");
      derivindex469 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({0, 1, 2});
      slog::Relation* readrel501 = db->getRelation("deriv");
      derivindex470 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({0, 1, 2});
      slog::Relation* readrel503 = db->getRelation("deriv");
      derivdelta476 = readrel503->getIndex(ord502, true);
      std::vector<u16> ord504({1, 2, 0});
      slog::Relation* readrel505 = db->getRelation("deriv");
      derivindex471 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({1, 2, 3, 0});
      slog::Relation* readrel507 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0index472 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 2, 3, 0});
      slog::Relation* readrel509 = db->getRelation("$sup14449x70x0x0x0");
      $sup14449x70x0x0x0delta477 = readrel509->getIndex(ord508, true);
      std::vector<u16> ord510({0, 1, 2});
      slog::Relation* readrel511 = db->getRelation("deriv");
      derivindex473 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({0, 1, 2});
      slog::Relation* readrel513 = db->getRelation("deriv");
      derivdelta478 = readrel513->getIndex(ord512, true);
  
    }
    ReadTask479(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c22 = _t[1];
        slog::join_probe_old<3,1>(mkcatindex463, mkcatdelta474, std::array<u64,3>{v_c68, 0, 0}, [&](const std::array<u64,3>& m514) {
          u64 v_c20 = m514[1]; u64 v_c24 = m514[2];
          if (!slog::exists_probe<3,1>(catindex464, std::array<u64,3>{v_c24, 0, 0})) return;
          if (!slog::exists_probe<4,1>($sup14449x70x0x0x0index465, std::array<u64,4>{v_c24, 0, 0, 0})) return;
          slog::join_probe<2,1>(deriv_ansindex466, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m515) {
            u64 v_c69 = m515[1];
            slog::join_probe_old<3,1>(catindex467, catdelta475, std::array<u64,3>{v_c24, 0, 0}, [&](const std::array<u64,3>& m516) {
              u64 v_c70 = m516[1]; u64 v_c18 = m516[2];
              if (!slog::exists_probe<4,2>($sup14449x70x0x0x0index468, std::array<u64,4>{v_c24, v_c18, 0, 0})) return;
              if (!slog::exists_probe<3,1>(derivindex469, std::array<u64,3>{v_c70, 0, 0})) return;
              slog::join_probe_old<3,2>(derivindex470, derivdelta476, std::array<u64,3>{v_c69, v_c18, 0}, [&](const std::array<u64,3>& m517) {
                u64 v_c17 = m517[2];
                if (!slog::exists_probe<3,2>(derivindex471, std::array<u64,3>{v_c70, v_c17, 0})) return;
                slog::join_probe_old<4,3>($sup14449x70x0x0x0index472, $sup14449x70x0x0x0delta477, std::array<u64,4>{v_c17, v_c18, v_c24, 0}, [&](const std::array<u64,4>& m518) {
                  u64 v_c71 = m518[3];
                  slog::join_probe_old<3,3>(derivindex473, derivdelta478, std::array<u64,3>{v_c71, v_c70, v_c17}, [&](const std::array<u64,3>& m519) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c22}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:71", "delta:mkcat_ans", _fires);
  
      if (!_done)
      {
        ReadTask479* _cont = new ReadTask479(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask479(db,b), false);
  // (crule (pre) (scan deriv_ans __t72SS120 __v0) (body (join-old deriv (0 1 2) 1 (0 1 2) __t72SS120 s c) (exists alt (2 0 1) 1 s) (exists deriv (2 0 1) 1 c) (join-old $sup14449x69x0x0x0 (1 3 0 2) 2 (1 3 0 2) c s __t0tyF119 r) (exists deriv (2 0 1) 2 c __t0tyF119) (join-old alt (1 2 0) 2 (1 2 0) r s __t2ubg118) (join-old deriv (0 1 2) 3 (0 1 2) __t0tyF119 __t2ubg118 c)) (head (emit deriv_ans (0 1) __t0tyF119 __v0)) antimirov.slog:70 #f)
  class ReadTask531 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** derivindex520;  slog::Index** altindex521;  slog::Index** derivindex522;  slog::Index** $sup14449x69x0x0x0index523;  slog::Index** derivindex524;  slog::Index** altindex525;  slog::Index** derivindex526;  slog::Index** derivdelta527;  slog::Index** $sup14449x69x0x0x0delta528;  slog::Index** altdelta529;  slog::Index** derivdelta530;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("deriv_ans");
      std::vector<u16> ord532({0, 1});
      slog::Relation* readrel533 = db->getRelation("deriv_ans");
      head_index[0] = readrel533->getIndex(ord532, false);
      outer_rel = db->getRelation("deriv_ans");
      std::vector<u16> ord534({0, 1, 2});
      slog::Relation* readrel535 = db->getRelation("deriv");
      derivindex520 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({0, 1, 2});
      slog::Relation* readrel537 = db->getRelation("deriv");
      derivdelta527 = readrel537->getIndex(ord536, true);
      std::vector<u16> ord538({2, 0, 1});
      slog::Relation* readrel539 = db->getRelation("alt");
      altindex521 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({2, 0, 1});
      slog::Relation* readrel541 = db->getRelation("deriv");
      derivindex522 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({1, 3, 0, 2});
      slog::Relation* readrel543 = db->getRelation("$sup14449x69x0x0x0");
      $sup14449x69x0x0x0index523 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 3, 0, 2});
      slog::Relation* readrel545 = db->getRelation("$sup14449x69x0x0x0");
      $sup14449x69x0x0x0delta528 = readrel545->getIndex(ord544, true);
      std::vector<u16> ord546({2, 0, 1});
      slog::Relation* readrel547 = db->getRelation("deriv");
      derivindex524 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 2, 0});
      slog::Relation* readrel549 = db->getRelation("alt");
      altindex525 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({1, 2, 0});
      slog::Relation* readrel551 = db->getRelation("alt");
      altdelta529 = readrel551->getIndex(ord550, true);
      std::vector<u16> ord552({0, 1, 2});
      slog::Relation* readrel553 = db->getRelation("deriv");
      derivindex526 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({0, 1, 2});
      slog::Relation* readrel555 = db->getRelation("deriv");
      derivdelta530 = readrel555->getIndex(ord554, true);
  
    }
    ReadTask531(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[0];
        u64 v_c20 = _t[1];
        slog::join_probe_old<3,1>(derivindex520, derivdelta527, std::array<u64,3>{v_c49, 0, 0}, [&](const std::array<u64,3>& m556) {
          u64 v_c24 = m556[1]; u64 v_c17 = m556[2];
          if (!slog::exists_probe<3,1>(altindex521, std::array<u64,3>{v_c24, 0, 0})) return;
          if (!slog::exists_probe<3,1>(derivindex522, std::array<u64,3>{v_c17, 0, 0})) return;
          slog::join_probe_old<4,2>($sup14449x69x0x0x0index523, $sup14449x69x0x0x0delta528, std::array<u64,4>{v_c17, v_c24, 0, 0}, [&](const std::array<u64,4>& m557) {
            u64 v_c50 = m557[2]; u64 v_c18 = m557[3];
            if (!slog::exists_probe<3,2>(derivindex524, std::array<u64,3>{v_c17, v_c50, 0})) return;
            slog::join_probe_old<3,2>(altindex525, altdelta529, std::array<u64,3>{v_c18, v_c24, 0}, [&](const std::array<u64,3>& m558) {
              u64 v_c51 = m558[2];
              slog::join_probe_old<3,3>(derivindex526, derivdelta530, std::array<u64,3>{v_c50, v_c51, v_c17}, [&](const std::array<u64,3>& m559) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c20}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("antimirov.slog:70", "delta:deriv_ans", _fires);
  
      if (!_done)
      {
        ReadTask531* _cont = new ReadTask531(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask531(db,b), false);
}

