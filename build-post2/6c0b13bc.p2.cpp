
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0bbd2fbd1dc4200473343503;
extern u64 v_const2a09f8e08b8d8243373579d9;
extern u64 v_const30f8b180d63559f2512b744f;
extern u64 v_const342a69eb5a93251c8b7e179a;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const5963fd3eff55776ca49412c5;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf6cdc3db4b71e0cdeda6912e;


void slog_rules_c5c167c09c2a294c0(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5) (let __tconst0xiC106 const30f8b180d63559f2512b744f) (let __tconst8Fnl80 const7297d2085ea0adffc396d546) (let __tconst2U2F71 constef2d127de37b942baad06145)) (scan temp2du61000 __t1hw196 __t528g79 __t5Wmv107 __t8dvA109 __t9Kbk85) (body (exists ref (1 0) 1 __tconst8Fnl80) (exists ref (1 0) 1 __tconst2uSL111) (exists ref (1 0) 1 __tconst0xiC106) (exists app (2 0 1) 1 __t1hw196) (join num (1 0) 1 __tconst2U2F71 __t8tX372) (join ref (1 0) 1 __tconst8Fnl80 __t0mBu81) (join ref (1 0) 1 __tconst2uSL111 __t0iVM91) (join ref (1 0) 1 __tconst0xiC106 __t2Kfn98) (join app (1 2 0) 2 __t2Kfn98 __t1hw196 __t6UC699) (let __t7KRi101 (lpush __t5Wmv107 __t6UC699))) (head (emit-temp temp8uWT1001 __t528g79 __t5Wmv107 __t7KRi101 __t8dvA109 __t9Kbk85) (mkstruct app (1 2 0) __t8wZP82 __t0mBu81 __t528g79)) analysis-demo.slog:11 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex0;  slog::Index** refindex1;  slog::Index** refindex2;  slog::Index** appindex3;  slog::Index** numindex4;  slog::Index** refindex5;  slog::Index** refindex6;  slog::Index** refindex7;  slog::Index** appindex8;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8uWT1001");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp2du61000");
      std::vector<u16> ord10({1, 0});
      slog::Relation* readrel11 = db->getRelation("ref");
      refindex0 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("ref");
      refindex1 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("ref");
      refindex2 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({2, 0, 1});
      slog::Relation* readrel17 = db->getRelation("app");
      appindex3 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 0});
      slog::Relation* readrel19 = db->getRelation("num");
      numindex4 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 0});
      slog::Relation* readrel21 = db->getRelation("ref");
      refindex5 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("ref");
      refindex6 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0});
      slog::Relation* readrel25 = db->getRelation("ref");
      refindex7 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 2, 0});
      slog::Relation* readrel27 = db->getRelation("app");
      appindex8 = readrel27->getIndex(ord26, false);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0457bba0679825d285ef7fa5;
      u64 v_c1 = v_const30f8b180d63559f2512b744f;
      u64 v_c2 = v_const7297d2085ea0adffc396d546;
      u64 v_c3 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<2,1>(refindex0, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(appindex3, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(numindex4, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m28) {
          u64 v_c9 = m28[1];
          slog::join_probe<2,1>(refindex5, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m29) {
            u64 v_c10 = m29[1];
            slog::join_probe<2,1>(refindex6, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m30) {
              u64 v_c11 = m30[1];
              slog::join_probe<2,1>(refindex7, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m31) {
                u64 v_c12 = m31[1];
                slog::join_probe<3,2>(appindex8, std::array<u64,3>{v_c12, v_c4, 0}, [&](const std::array<u64,3>& m32) {
                  u64 v_c13 = m32[2];
                  u64 v_c14 = _prim_lpush(db, v_c6, v_c13);
                  if (v_c14 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return; }
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c5, v_c6, v_c14, v_c7, v_c8});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c10, v_c5}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "delta:temp2du61000", _fires);
  
      if (!_done)
      {
        ReadTask9* _cont = new ReadTask9(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), false);
  // (crule (pre) (scan eval_ans __t3XtU156 vr) (body (join-old eval (0 2 1) 1 (0 2 1) __t3XtU156 c er) (exists letrec (2 1 3 0) 1 er) (join eval (2 0 1) 1 c __2TQp678 __t3lnK155) (join letrec (0 2 1 3) 2 __t3lnK155 er x eb)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:95 #f)
  class ReadTask38 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex33;  slog::Index** letrecindex34;  slog::Index** evalindex35;  slog::Index** letrecindex36;  slog::Index** evaldelta37;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord39({0, 1, 2});
      slog::Relation* readrel40 = db->getRelation("binding");
      head_index[0] = readrel40->getIndex(ord39, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord41({0, 1, 2});
      slog::Relation* readrel42 = db->getRelation("binding_event");
      head_index[1] = readrel42->getIndex(ord41, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord43({0, 2, 1});
      slog::Relation* readrel44 = db->getRelation("eval");
      evalindex33 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({0, 2, 1});
      slog::Relation* readrel46 = db->getRelation("eval");
      evaldelta37 = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({2, 1, 3, 0});
      slog::Relation* readrel48 = db->getRelation("letrec");
      letrecindex34 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({2, 0, 1});
      slog::Relation* readrel50 = db->getRelation("eval");
      evalindex35 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 2, 1, 3});
      slog::Relation* readrel52 = db->getRelation("letrec");
      letrecindex36 = readrel52->getIndex(ord51, false);
  
    }
    ReadTask38(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[0];
        u64 v_c16 = _t[1];
        slog::join_probe_old<3,1>(evalindex33, evaldelta37, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m53) {
          u64 v_c17 = m53[1]; u64 v_c18 = m53[2];
          if (!slog::exists_probe<4,1>(letrecindex34, std::array<u64,4>{v_c18, 0, 0, 0})) return;
          slog::join_probe<3,1>(evalindex35, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m54) {
            u64 v_c19 = m54[1]; u64 v_c20 = m54[2];
            slog::join_probe<4,2>(letrecindex36, std::array<u64,4>{v_c20, v_c18, 0, 0}, [&](const std::array<u64,4>& m55) {
              u64 v_c21 = m55[2]; u64 v_c22 = m55[3];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c21, v_c17, v_c16}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c21, v_c17, v_c17}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:eval_ans", _fires);
  
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
  // (crule (pre (let __tconst0flI607 const0122baa3ac55f1b433944eb1) (let __tconst2Cp4303 const06abaa100ecef791ce028c56) (let _00024sqc21WF437 constd4735e3a265e16eee03f5971) (let _00024sqc91nv438 const5feceb66ffc86f38d952786c) (let _00024sqc5PZ7439 const6b86b273ff34fce19d6b804e) (let _00024sqo16uv440 const5feceb66ffc86f38d952786c) (let _00024sqo3GRa441 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vbm442 const6b86b273ff34fce19d6b804e) (let _00024sqo8B0L443 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo3GRa441 __t9eYl306 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo16uv440 __t9eYl306 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2Vbm442 __t9eYl306 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8B0L443 __t9eYl306 _00024seq2) (exists _enum (1 0) 1 __tconst0flI607) (join delta (1 2 0) 2 __tconst2Cp4303 _00024seq2 __t2i9A304) (join _enum (1 0) 1 __tconst0flI607 __t8LeX301) (join boolval (0 1) 1 __t9eYl306 b) (letp _00024sql7hRC435 (aslst _00024seq2)) (let chk96jr1022 (llen _00024sql7hRC435)) (eq _00024sqc21WF437 chk96jr1022) (letp chk5Ff71023 (lref _00024sql7hRC435 _00024sqc91nv438)) (eq __t9eYl306 chk5Ff71023) (letp chk3nsA1024 (lref _00024sql7hRC435 _00024sqc5PZ7439)) (eq __t9eYl306 chk3nsA1024)) (head (emit-temp temp61mi1013 __t2i9A304) (mkstruct boolval (1 0) __t5m8l302 __t8LeX301)) interp.slog:118 #f)
  class ReadTask65 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex56;  slog::Index** $seq_atrindex57;  slog::Index** $seq_atrindex58;  slog::Index** _enumindex59;  slog::Index** deltaindex60;  slog::Index** _enumindex61;  slog::Index** boolvalindex62;  slog::Index** $seq_atrdelta63;  slog::Index** $seq_atrdelta64;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp61mi1013");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord66({1, 0, 2});
      slog::Relation* readrel67 = db->getRelation("$seq_at");
      driver_index = readrel67->getIndex(ord66, true);
      std::vector<u16> ord68({1, 0, 2});
      slog::Relation* readrel69 = db->getRelation("$seq_at");
      $seq_atindex56 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 0, 2});
      slog::Relation* readrel71 = db->getRelation("$seq_atr");
      $seq_atrindex57 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 0, 2});
      slog::Relation* readrel73 = db->getRelation("$seq_atr");
      $seq_atrdelta63 = readrel73->getIndex(ord72, true);
      std::vector<u16> ord74({1, 0, 2});
      slog::Relation* readrel75 = db->getRelation("$seq_atr");
      $seq_atrindex58 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 0, 2});
      slog::Relation* readrel77 = db->getRelation("$seq_atr");
      $seq_atrdelta64 = readrel77->getIndex(ord76, true);
      std::vector<u16> ord78({1, 0});
      slog::Relation* readrel79 = db->getRelation("_enum");
      _enumindex59 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 2, 0});
      slog::Relation* readrel81 = db->getRelation("delta");
      deltaindex60 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 0});
      slog::Relation* readrel83 = db->getRelation("_enum");
      _enumindex61 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("boolval");
      boolvalindex62 = readrel85->getIndex(ord84, false);
  
    }
    ReadTask65(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c24 = v_const06abaa100ecef791ce028c56;
      u64 v_c25 = v_constd4735e3a265e16eee03f5971;
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c28 = v_const5feceb66ffc86f38d952786c;
      u64 v_c29 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c29, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m86) {
        u64 v_c32 = m86[1];
        u64 v_c33 = m86[2];
        if (buckethash(v_c32) != bucket) return;
        slog::join_probe<3,3>($seq_atindex56, std::array<u64,3>{v_c28, v_c32, v_c33}, [&](const std::array<u64,3>& m87) {
          slog::join_probe_old<3,3>($seq_atrindex57, $seq_atrdelta63, std::array<u64,3>{v_c30, v_c32, v_c33}, [&](const std::array<u64,3>& m88) {
            slog::join_probe_old<3,3>($seq_atrindex58, $seq_atrdelta64, std::array<u64,3>{v_c31, v_c32, v_c33}, [&](const std::array<u64,3>& m89) {
              if (!slog::exists_probe<2,1>(_enumindex59, std::array<u64,2>{v_c23, 0})) return;
              slog::join_probe<3,2>(deltaindex60, std::array<u64,3>{v_c24, v_c33, 0}, [&](const std::array<u64,3>& m90) {
                u64 v_c34 = m90[2];
                slog::join_probe<2,1>(_enumindex61, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m91) {
                  u64 v_c35 = m91[1];
                  slog::join_probe<2,1>(boolvalindex62, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m92) {
                    u64 v_c36 = m92[1];
                    bool ok93 = true;
                    u64 v_c37 = _prim_aslst(db, v_c33, &ok93);
                    if (!ok93) return;
                    u64 v_c38 = _prim_llen(db, v_c37);
                    if (v_c38 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c25 != v_c38) return;
                    bool ok94 = true;
                    u64 v_c39 = _prim_lref(db, v_c37, v_c26, &ok94);
                    if (!ok94) return;
                    if (v_c32 != v_c39) return;
                    bool ok95 = true;
                    u64 v_c40 = _prim_lref(db, v_c37, v_c27, &ok95);
                    if (!ok95) return;
                    if (v_c32 != v_c40) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c34});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c35}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask65* _cont = new ReadTask65(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask65(db,b), false);
  // (crule (pre) (scan eval __t66Yt170 ef c) (body (exists eval_args (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t66Yt170) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __d0) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3FCg173) (exists eval_args_ans (0 1) 1 __t3FCg173) (join-old app (1 2 0) 2 (1 2 0) ef es __t6KUR174) (join-old tick (1 2 0) 2 (1 2 0) __t6KUR174 c __t9uJP175) (exists tick_ans (0 1) 1 __t9uJP175) (join eval_ans (0 1) 1 __t66Yt170 __t8UWw172) (join eval_args_ans (0 1) 1 __t3FCg173 vs) (join tick_ans (0 1) 1 __t9uJP175 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t8UWw172 __t3anZ171 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t3anZ171 xs eb)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask117 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex96;  slog::Index** appindex97;  slog::Index** tickindex98;  slog::Index** eval_ansindex99;  slog::Index** $sup56712x41x0x0x0index100;  slog::Index** appindex101;  slog::Index** eval_argsindex102;  slog::Index** eval_args_ansindex103;  slog::Index** appindex104;  slog::Index** tickindex105;  slog::Index** tick_ansindex106;  slog::Index** eval_ansindex107;  slog::Index** eval_args_ansindex108;  slog::Index** tick_ansindex109;  slog::Index** closureindex110;  slog::Index** lambdaindex111;  slog::Index** eval_argsdelta112;  slog::Index** appdelta113;  slog::Index** tickdelta114;  slog::Index** closuredelta115;  slog::Index** lambdadelta116;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord118({2, 0, 1});
      slog::Relation* readrel119 = db->getRelation("eval_args");
      eval_argsindex96 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 2, 0});
      slog::Relation* readrel121 = db->getRelation("app");
      appindex97 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({2, 0, 1});
      slog::Relation* readrel123 = db->getRelation("tick");
      tickindex98 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({0, 1});
      slog::Relation* readrel125 = db->getRelation("eval_ans");
      eval_ansindex99 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 3, 0});
      slog::Relation* readrel127 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index100 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("app");
      appindex101 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 2, 0});
      slog::Relation* readrel131 = db->getRelation("eval_args");
      eval_argsindex102 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("eval_args");
      eval_argsdelta112 = readrel133->getIndex(ord132, true);
      std::vector<u16> ord134({0, 1});
      slog::Relation* readrel135 = db->getRelation("eval_args_ans");
      eval_args_ansindex103 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("app");
      appindex104 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("app");
      appdelta113 = readrel139->getIndex(ord138, true);
      std::vector<u16> ord140({1, 2, 0});
      slog::Relation* readrel141 = db->getRelation("tick");
      tickindex105 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0});
      slog::Relation* readrel143 = db->getRelation("tick");
      tickdelta114 = readrel143->getIndex(ord142, true);
      std::vector<u16> ord144({0, 1});
      slog::Relation* readrel145 = db->getRelation("tick_ans");
      tick_ansindex106 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 1});
      slog::Relation* readrel147 = db->getRelation("eval_ans");
      eval_ansindex107 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0, 1});
      slog::Relation* readrel149 = db->getRelation("eval_args_ans");
      eval_args_ansindex108 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 1});
      slog::Relation* readrel151 = db->getRelation("tick_ans");
      tick_ansindex109 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({0, 1, 2});
      slog::Relation* readrel153 = db->getRelation("closure");
      closureindex110 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({0, 1, 2});
      slog::Relation* readrel155 = db->getRelation("closure");
      closuredelta115 = readrel155->getIndex(ord154, true);
      std::vector<u16> ord156({0, 1, 2});
      slog::Relation* readrel157 = db->getRelation("lambda");
      lambdaindex111 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0, 1, 2});
      slog::Relation* readrel159 = db->getRelation("lambda");
      lambdadelta116 = readrel159->getIndex(ord158, true);
  
    }
    ReadTask117(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<3,1>(eval_argsindex96, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex97, std::array<u64,3>{v_c42, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex98, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex99, std::array<u64,2>{v_c41, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index100, std::array<u64,4>{v_c17, v_c42, 0, 0}, [&](const std::array<u64,4>& m160) {
          u64 v_c43 = m160[2]; u64 v_c44 = m160[3];
          if (!slog::exists_probe<3,2>(appindex101, std::array<u64,3>{v_c42, v_c43, 0})) return;
          slog::join_probe_old<3,2>(eval_argsindex102, eval_argsdelta112, std::array<u64,3>{v_c43, v_c17, 0}, [&](const std::array<u64,3>& m161) {
            u64 v_c45 = m161[2];
            if (!slog::exists_probe<2,1>(eval_args_ansindex103, std::array<u64,2>{v_c45, 0})) return;
            slog::join_probe_old<3,2>(appindex104, appdelta113, std::array<u64,3>{v_c42, v_c43, 0}, [&](const std::array<u64,3>& m162) {
              u64 v_c46 = m162[2];
              slog::join_probe_old<3,2>(tickindex105, tickdelta114, std::array<u64,3>{v_c46, v_c17, 0}, [&](const std::array<u64,3>& m163) {
                u64 v_c47 = m163[2];
                if (!slog::exists_probe<2,1>(tick_ansindex106, std::array<u64,2>{v_c47, 0})) return;
                slog::join_probe<2,1>(eval_ansindex107, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m164) {
                  u64 v_c48 = m164[1];
                  slog::join_probe<2,1>(eval_args_ansindex108, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m165) {
                    u64 v_c49 = m165[1];
                    slog::join_probe<2,1>(tick_ansindex109, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m166) {
                      u64 v_c50 = m166[1];
                      slog::join_probe_old<3,1>(closureindex110, closuredelta115, std::array<u64,3>{v_c48, 0, 0}, [&](const std::array<u64,3>& m167) {
                        u64 v_c51 = m167[1]; u64 v_c52 = m167[2];
                        slog::join_probe_old<3,1>(lambdaindex111, lambdadelta116, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m168) {
                          u64 v_c53 = m168[1]; u64 v_c22 = m168[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c22, v_c50}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask117* _cont = new ReadTask117(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask117(db,b), false);
  // (crule (pre) (scan eval __t550i320 ef c) (body (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval_ans (0 1) 1 __t550i320 __t2qAJ322) (join eval (2 0 1) 1 c __5izx673 __t9nj7324) (exists tick (1 2 0) 2 __t9nj7324 c) (join-old app (0 1 2) 2 (0 1 2) __t9nj7324 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t8cVn323) (exists eval_args_ans (0 1) 1 __t8cVn323) (join-old tick (1 2 0) 2 (1 2 0) __t9nj7324 c __t3nAR325) (exists tick_ans (0 1) 1 __t3nAR325) (join eval_args_ans (0 1) 1 __t8cVn323 vs) (join tick_ans (0 1) 1 __t3nAR325 l) (join-old closure (0 1 2) 1 (0 1 2) __t2qAJ322 __t7ycN321 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7ycN321 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask190 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex169;  slog::Index** appindex170;  slog::Index** eval_argsindex171;  slog::Index** tickindex172;  slog::Index** eval_ansindex173;  slog::Index** evalindex174;  slog::Index** tickindex175;  slog::Index** appindex176;  slog::Index** eval_argsindex177;  slog::Index** eval_args_ansindex178;  slog::Index** tickindex179;  slog::Index** tick_ansindex180;  slog::Index** eval_args_ansindex181;  slog::Index** tick_ansindex182;  slog::Index** closureindex183;  slog::Index** lambdaindex184;  slog::Index** appdelta185;  slog::Index** eval_argsdelta186;  slog::Index** tickdelta187;  slog::Index** closuredelta188;  slog::Index** lambdadelta189;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord191({0, 1, 2, 3});
      slog::Relation* readrel192 = db->getRelation("bind_params");
      head_index[0] = readrel192->getIndex(ord191, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord193({0, 1});
      slog::Relation* readrel194 = db->getRelation("call_event");
      head_index[1] = readrel194->getIndex(ord193, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord195({2, 0, 1});
      slog::Relation* readrel196 = db->getRelation("eval");
      evalindex169 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 2, 0});
      slog::Relation* readrel198 = db->getRelation("app");
      appindex170 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({2, 0, 1});
      slog::Relation* readrel200 = db->getRelation("eval_args");
      eval_argsindex171 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({2, 0, 1});
      slog::Relation* readrel202 = db->getRelation("tick");
      tickindex172 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1});
      slog::Relation* readrel204 = db->getRelation("eval_ans");
      eval_ansindex173 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({2, 0, 1});
      slog::Relation* readrel206 = db->getRelation("eval");
      evalindex174 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 2, 0});
      slog::Relation* readrel208 = db->getRelation("tick");
      tickindex175 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({0, 1, 2});
      slog::Relation* readrel210 = db->getRelation("app");
      appindex176 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({0, 1, 2});
      slog::Relation* readrel212 = db->getRelation("app");
      appdelta185 = readrel212->getIndex(ord211, true);
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("eval_args");
      eval_argsindex177 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 2, 0});
      slog::Relation* readrel216 = db->getRelation("eval_args");
      eval_argsdelta186 = readrel216->getIndex(ord215, true);
      std::vector<u16> ord217({0, 1});
      slog::Relation* readrel218 = db->getRelation("eval_args_ans");
      eval_args_ansindex178 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 2, 0});
      slog::Relation* readrel220 = db->getRelation("tick");
      tickindex179 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({1, 2, 0});
      slog::Relation* readrel222 = db->getRelation("tick");
      tickdelta187 = readrel222->getIndex(ord221, true);
      std::vector<u16> ord223({0, 1});
      slog::Relation* readrel224 = db->getRelation("tick_ans");
      tick_ansindex180 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({0, 1});
      slog::Relation* readrel226 = db->getRelation("eval_args_ans");
      eval_args_ansindex181 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({0, 1});
      slog::Relation* readrel228 = db->getRelation("tick_ans");
      tick_ansindex182 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({0, 1, 2});
      slog::Relation* readrel230 = db->getRelation("closure");
      closureindex183 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 1, 2});
      slog::Relation* readrel232 = db->getRelation("closure");
      closuredelta188 = readrel232->getIndex(ord231, true);
      std::vector<u16> ord233({0, 1, 2});
      slog::Relation* readrel234 = db->getRelation("lambda");
      lambdaindex184 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 1, 2});
      slog::Relation* readrel236 = db->getRelation("lambda");
      lambdadelta189 = readrel236->getIndex(ord235, true);
  
    }
    ReadTask190(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c42 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex169, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex170, std::array<u64,3>{v_c42, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex171, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex172, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex173, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m237) {
          u64 v_c55 = m237[1];
          slog::join_probe<3,1>(evalindex174, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m238) {
            u64 v_c56 = m238[1]; u64 v_c57 = m238[2];
            if (!slog::exists_probe<3,2>(tickindex175, std::array<u64,3>{v_c57, v_c17, 0})) return;
            slog::join_probe_old<3,2>(appindex176, appdelta185, std::array<u64,3>{v_c57, v_c42, 0}, [&](const std::array<u64,3>& m239) {
              u64 v_c43 = m239[2];
              slog::join_probe_old<3,2>(eval_argsindex177, eval_argsdelta186, std::array<u64,3>{v_c43, v_c17, 0}, [&](const std::array<u64,3>& m240) {
                u64 v_c58 = m240[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex178, std::array<u64,2>{v_c58, 0})) return;
                slog::join_probe_old<3,2>(tickindex179, tickdelta187, std::array<u64,3>{v_c57, v_c17, 0}, [&](const std::array<u64,3>& m241) {
                  u64 v_c59 = m241[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex180, std::array<u64,2>{v_c59, 0})) return;
                  slog::join_probe<2,1>(eval_args_ansindex181, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m242) {
                    u64 v_c49 = m242[1];
                    slog::join_probe<2,1>(tick_ansindex182, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m243) {
                      u64 v_c60 = m243[1];
                      slog::join_probe_old<3,1>(closureindex183, closuredelta188, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m244) {
                        u64 v_c61 = m244[1]; u64 v_c52 = m244[2];
                        slog::join_probe_old<3,1>(lambdaindex184, lambdadelta189, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m245) {
                          u64 v_c53 = m245[1]; u64 v_c22 = m245[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c53, v_c49, v_c60, v_c17}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c60, v_c17}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask190* _cont = new ReadTask190(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask190(db,b), false);
  // (crule (pre) (scan temp7olY1010 __t60vU149 es x) (body (let __t43VN150 (lcat __t60vU149 es))) (head (emit-temp temp6lH41011 __t43VN150 x)) freevars.slog:35 #f)
  class ReadTask246 : public slog::Task
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
      head_rel[0] = db->getRelation("temp6lH41011");
      outer_rel = db->getRelation("temp7olY1010");
  
    }
    ReadTask246(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[1];
        u64 v_c21 = _t[2];
        u64 v_c63 = _prim_lcat(db, v_c62, v_c43);
        if (v_c63 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c63, v_c21});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp7olY1010", _fires);
  
      if (!_done)
      {
        ReadTask246* _cont = new ReadTask246(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask246(db,b), false);
  // (crule (pre (let __tconst9XQ5142 const06abaa100ecef791ce028c56) (let _00024sqc41dF446 constd4735e3a265e16eee03f5971) (let _00024sqc5yoB447 const5feceb66ffc86f38d952786c) (let _00024sqc1Cqz448 const6b86b273ff34fce19d6b804e) (let _00024sqo7aST449 const5feceb66ffc86f38d952786c) (let _00024sqo1C1f450 const6b86b273ff34fce19d6b804e) (let _00024sqo1Q0D451 const6b86b273ff34fce19d6b804e) (let _00024sqo7GLE452 const5feceb66ffc86f38d952786c)) (scan closure __t4Puk145 lm cb) (body (exists $seq_at (1 0 2) 2 _00024sqo1C1f450 __t4Puk145) (exists $seq_atr (1 0 2) 2 _00024sqo1Q0D451 __t4Puk145) (exists $seq_atr (1 0 2) 2 _00024sqo7GLE452 __t4Puk145) (exists delta (1 2 0) 1 __tconst9XQ5142) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo7aST449 __t4Puk145 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo1C1f450 __t4Puk145 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Q0D451 __t4Puk145 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7GLE452 __t4Puk145 _00024seq2) (join delta (1 2 0) 2 __tconst9XQ5142 _00024seq2 __t9sdv143) (join any_bool (0) 0 b) (letp _00024sql8vYG444 (aslst _00024seq2)) (let chk4GHh915 (llen _00024sql8vYG444)) (eq _00024sqc41dF446 chk4GHh915) (letp chk709H916 (lref _00024sql8vYG444 _00024sqc5yoB447)) (eq __t4Puk145 chk709H916) (letp chk1Wvd917 (lref _00024sql8vYG444 _00024sqc1Cqz448)) (eq __t4Puk145 chk1Wvd917)) (head (emit-temp temp8OpH912 __t9sdv143 b) (mkstruct boolval (1 0) __t9Ain141 b)) interp.slog:122 #f)
  class ReadTask261 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex247;  slog::Index** $seq_atrindex248;  slog::Index** $seq_atrindex249;  slog::Index** deltaindex250;  slog::Index** $seq_atindex251;  slog::Index** $seq_atindex252;  slog::Index** $seq_atrindex253;  slog::Index** $seq_atrindex254;  slog::Index** deltaindex255;  slog::Index** any_boolindex256;  slog::Index** $seq_atdelta257;  slog::Index** $seq_atdelta258;  slog::Index** $seq_atrdelta259;  slog::Index** $seq_atrdelta260;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8OpH912");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord262({1, 0, 2});
      slog::Relation* readrel263 = db->getRelation("$seq_at");
      $seq_atindex247 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 0, 2});
      slog::Relation* readrel265 = db->getRelation("$seq_atr");
      $seq_atrindex248 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 0, 2});
      slog::Relation* readrel267 = db->getRelation("$seq_atr");
      $seq_atrindex249 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 2, 0});
      slog::Relation* readrel269 = db->getRelation("delta");
      deltaindex250 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 0, 2});
      slog::Relation* readrel271 = db->getRelation("$seq_at");
      $seq_atindex251 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 0, 2});
      slog::Relation* readrel273 = db->getRelation("$seq_at");
      $seq_atdelta257 = readrel273->getIndex(ord272, true);
      std::vector<u16> ord274({1, 0, 2});
      slog::Relation* readrel275 = db->getRelation("$seq_at");
      $seq_atindex252 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 0, 2});
      slog::Relation* readrel277 = db->getRelation("$seq_at");
      $seq_atdelta258 = readrel277->getIndex(ord276, true);
      std::vector<u16> ord278({1, 0, 2});
      slog::Relation* readrel279 = db->getRelation("$seq_atr");
      $seq_atrindex253 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({1, 0, 2});
      slog::Relation* readrel281 = db->getRelation("$seq_atr");
      $seq_atrdelta259 = readrel281->getIndex(ord280, true);
      std::vector<u16> ord282({1, 0, 2});
      slog::Relation* readrel283 = db->getRelation("$seq_atr");
      $seq_atrindex254 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({1, 0, 2});
      slog::Relation* readrel285 = db->getRelation("$seq_atr");
      $seq_atrdelta260 = readrel285->getIndex(ord284, true);
      std::vector<u16> ord286({1, 2, 0});
      slog::Relation* readrel287 = db->getRelation("delta");
      deltaindex255 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({0});
      slog::Relation* readrel289 = db->getRelation("any_bool");
      any_boolindex256 = readrel289->getIndex(ord288, false);
  
    }
    ReadTask261(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c64 = v_const06abaa100ecef791ce028c56;
      u64 v_c65 = v_constd4735e3a265e16eee03f5971;
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
      u64 v_c67 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c72 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c52 = _t[2];
        if (!slog::exists_probe<3,2>($seq_atindex247, std::array<u64,3>{v_c69, v_c72, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex248, std::array<u64,3>{v_c70, v_c72, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex249, std::array<u64,3>{v_c71, v_c72, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex250, std::array<u64,3>{v_c64, 0, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex251, $seq_atdelta257, std::array<u64,3>{v_c68, v_c72, 0}, [&](const std::array<u64,3>& m290) {
          u64 v_c33 = m290[2];
          slog::join_probe_old<3,3>($seq_atindex252, $seq_atdelta258, std::array<u64,3>{v_c69, v_c72, v_c33}, [&](const std::array<u64,3>& m291) {
            slog::join_probe_old<3,3>($seq_atrindex253, $seq_atrdelta259, std::array<u64,3>{v_c70, v_c72, v_c33}, [&](const std::array<u64,3>& m292) {
              slog::join_probe_old<3,3>($seq_atrindex254, $seq_atrdelta260, std::array<u64,3>{v_c71, v_c72, v_c33}, [&](const std::array<u64,3>& m293) {
                slog::join_probe<3,2>(deltaindex255, std::array<u64,3>{v_c64, v_c33, 0}, [&](const std::array<u64,3>& m294) {
                  u64 v_c74 = m294[2];
                  slog::join_all<1>(any_boolindex256, [&](const std::array<u64,1>& m295) {
                    u64 v_c36 = m295[0];
                    bool ok296 = true;
                    u64 v_c75 = _prim_aslst(db, v_c33, &ok296);
                    if (!ok296) return;
                    u64 v_c76 = _prim_llen(db, v_c75);
                    if (v_c76 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c65 != v_c76) return;
                    bool ok297 = true;
                    u64 v_c77 = _prim_lref(db, v_c75, v_c66, &ok297);
                    if (!ok297) return;
                    if (v_c72 != v_c77) return;
                    bool ok298 = true;
                    u64 v_c78 = _prim_lref(db, v_c75, v_c67, &ok298);
                    if (!ok298) return;
                    if (v_c72 != v_c78) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c74, v_c36});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c36}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:closure", _fires);
  
      if (!_done)
      {
        ReadTask261* _cont = new ReadTask261(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask261(db,b), false);
  // (crule (pre) (scan eval_ans __t1yWg361 vr) (body (join-old eval (0 2 1) 1 (0 2 1) __t1yWg361 c er) (exists let (2 1 3 0) 1 er) (join eval (2 0 1) 1 c __9hFj634 __t9408360) (join-old let (0 2 1 3) 2 (0 2 1 3) __t9408360 er x eb)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:93 #f)
  class ReadTask305 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex299;  slog::Index** letindex300;  slog::Index** evalindex301;  slog::Index** letindex302;  slog::Index** evaldelta303;  slog::Index** letdelta304;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord306({0, 1, 2});
      slog::Relation* readrel307 = db->getRelation("binding");
      head_index[0] = readrel307->getIndex(ord306, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord308({0, 1, 2});
      slog::Relation* readrel309 = db->getRelation("binding_event");
      head_index[1] = readrel309->getIndex(ord308, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord310({0, 2, 1});
      slog::Relation* readrel311 = db->getRelation("eval");
      evalindex299 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({0, 2, 1});
      slog::Relation* readrel313 = db->getRelation("eval");
      evaldelta303 = readrel313->getIndex(ord312, true);
      std::vector<u16> ord314({2, 1, 3, 0});
      slog::Relation* readrel315 = db->getRelation("let");
      letindex300 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({2, 0, 1});
      slog::Relation* readrel317 = db->getRelation("eval");
      evalindex301 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({0, 2, 1, 3});
      slog::Relation* readrel319 = db->getRelation("let");
      letindex302 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 2, 1, 3});
      slog::Relation* readrel321 = db->getRelation("let");
      letdelta304 = readrel321->getIndex(ord320, true);
  
    }
    ReadTask305(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c79 = _t[0];
        u64 v_c16 = _t[1];
        slog::join_probe_old<3,1>(evalindex299, evaldelta303, std::array<u64,3>{v_c79, 0, 0}, [&](const std::array<u64,3>& m322) {
          u64 v_c17 = m322[1]; u64 v_c18 = m322[2];
          if (!slog::exists_probe<4,1>(letindex300, std::array<u64,4>{v_c18, 0, 0, 0})) return;
          slog::join_probe<3,1>(evalindex301, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m323) {
            u64 v_c80 = m323[1]; u64 v_c81 = m323[2];
            slog::join_probe_old<4,2>(letindex302, letdelta304, std::array<u64,4>{v_c81, v_c18, 0, 0}, [&](const std::array<u64,4>& m324) {
              u64 v_c21 = m324[2]; u64 v_c22 = m324[3];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c21, v_c17, v_c16}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c21, v_c17, v_c17}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask305* _cont = new ReadTask305(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask305(db,b), false);
  // (crule (pre) (scan eval_ans __t4U4F46 __v2) (body (join-old eval (0 2 1) 1 (0 2 1) __t4U4F46 c __v1) (exists eval (2 0 1) 1 c) (exists $sup56712x86x0x0x0 (1 0 2 3 4) 1 c) (join select_branch_ans (1 0) 1 __v1 __t5q6W45) (join-old eval (2 0 1) 1 (2 0 1) c __t7yOw43 __t3ePt42) (join-old $sup56712x86x0x0x0 (1 0 2 3 4) 2 (1 0 2 3 4) c __t7yOw43 e1 e2 e3) (join-old if (2 3 1 0) 4 (2 3 1 0) e2 e3 e1 __t3ePt42) (exists eval (1 2 0) 2 e1 c) (join-old select_branch (2 3 0 1) 3 (2 3 0 1) e2 e3 __t5q6W45 __v0) (exists eval_ans (1 0) 1 __v0) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t9ATC44) (join eval_ans (0 1) 2 __t9ATC44 __v0)) (head (emit eval_ans (0 1) __t7yOw43 __v2)) interp.slog:87 #f)
  class ReadTask343 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex325;  slog::Index** evalindex326;  slog::Index** $sup56712x86x0x0x0index327;  slog::Index** select_branch_ansindex328;  slog::Index** evalindex329;  slog::Index** $sup56712x86x0x0x0index330;  slog::Index** ifindex331;  slog::Index** evalindex332;  slog::Index** select_branchindex333;  slog::Index** eval_ansindex334;  slog::Index** evalindex335;  slog::Index** eval_ansindex336;  slog::Index** evaldelta337;  slog::Index** evaldelta338;  slog::Index** $sup56712x86x0x0x0delta339;  slog::Index** ifdelta340;  slog::Index** select_branchdelta341;  slog::Index** evaldelta342;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord344({0, 1});
      slog::Relation* readrel345 = db->getRelation("eval_ans");
      head_index[0] = readrel345->getIndex(ord344, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord346({0, 2, 1});
      slog::Relation* readrel347 = db->getRelation("eval");
      evalindex325 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({0, 2, 1});
      slog::Relation* readrel349 = db->getRelation("eval");
      evaldelta337 = readrel349->getIndex(ord348, true);
      std::vector<u16> ord350({2, 0, 1});
      slog::Relation* readrel351 = db->getRelation("eval");
      evalindex326 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 0, 2, 3, 4});
      slog::Relation* readrel353 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index327 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({1, 0});
      slog::Relation* readrel355 = db->getRelation("select_branch_ans");
      select_branch_ansindex328 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({2, 0, 1});
      slog::Relation* readrel357 = db->getRelation("eval");
      evalindex329 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({2, 0, 1});
      slog::Relation* readrel359 = db->getRelation("eval");
      evaldelta338 = readrel359->getIndex(ord358, true);
      std::vector<u16> ord360({1, 0, 2, 3, 4});
      slog::Relation* readrel361 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index330 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({1, 0, 2, 3, 4});
      slog::Relation* readrel363 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0delta339 = readrel363->getIndex(ord362, true);
      std::vector<u16> ord364({2, 3, 1, 0});
      slog::Relation* readrel365 = db->getRelation("if");
      ifindex331 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({2, 3, 1, 0});
      slog::Relation* readrel367 = db->getRelation("if");
      ifdelta340 = readrel367->getIndex(ord366, true);
      std::vector<u16> ord368({1, 2, 0});
      slog::Relation* readrel369 = db->getRelation("eval");
      evalindex332 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({2, 3, 0, 1});
      slog::Relation* readrel371 = db->getRelation("select_branch");
      select_branchindex333 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({2, 3, 0, 1});
      slog::Relation* readrel373 = db->getRelation("select_branch");
      select_branchdelta341 = readrel373->getIndex(ord372, true);
      std::vector<u16> ord374({1, 0});
      slog::Relation* readrel375 = db->getRelation("eval_ans");
      eval_ansindex334 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 2, 0});
      slog::Relation* readrel377 = db->getRelation("eval");
      evalindex335 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({1, 2, 0});
      slog::Relation* readrel379 = db->getRelation("eval");
      evaldelta342 = readrel379->getIndex(ord378, true);
      std::vector<u16> ord380({0, 1});
      slog::Relation* readrel381 = db->getRelation("eval_ans");
      eval_ansindex336 = readrel381->getIndex(ord380, false);
  
    }
    ReadTask343(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(evalindex325, evaldelta337, std::array<u64,3>{v_c82, 0, 0}, [&](const std::array<u64,3>& m382) {
          u64 v_c17 = m382[1]; u64 v_c84 = m382[2];
          if (!slog::exists_probe<3,1>(evalindex326, std::array<u64,3>{v_c17, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup56712x86x0x0x0index327, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(select_branch_ansindex328, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m383) {
            u64 v_c85 = m383[1];
            slog::join_probe_old<3,1>(evalindex329, evaldelta338, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m384) {
              u64 v_c86 = m384[1]; u64 v_c87 = m384[2];
              slog::join_probe_old<5,2>($sup56712x86x0x0x0index330, $sup56712x86x0x0x0delta339, std::array<u64,5>{v_c17, v_c86, 0, 0, 0}, [&](const std::array<u64,5>& m385) {
                u64 v_c88 = m385[2]; u64 v_c89 = m385[3]; u64 v_c90 = m385[4];
                slog::join_probe_old<4,4>(ifindex331, ifdelta340, std::array<u64,4>{v_c89, v_c90, v_c88, v_c87}, [&](const std::array<u64,4>& m386) {
                  if (!slog::exists_probe<3,2>(evalindex332, std::array<u64,3>{v_c88, v_c17, 0})) return;
                  slog::join_probe_old<4,3>(select_branchindex333, select_branchdelta341, std::array<u64,4>{v_c89, v_c90, v_c85, 0}, [&](const std::array<u64,4>& m387) {
                    u64 v_c50 = m387[3];
                    if (!slog::exists_probe<2,1>(eval_ansindex334, std::array<u64,2>{v_c50, 0})) return;
                    slog::join_probe_old<3,2>(evalindex335, evaldelta342, std::array<u64,3>{v_c88, v_c17, 0}, [&](const std::array<u64,3>& m388) {
                      u64 v_c91 = m388[2];
                      slog::join_probe<2,2>(eval_ansindex336, std::array<u64,2>{v_c91, v_c50}, [&](const std::array<u64,2>& m389) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c86, v_c83}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask343* _cont = new ReadTask343(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask343(db,b), false);
  // (crule (pre) (scan $sup56712x86x0x0x0 __t7yOw43 c e1 e2 e3) (body (exists eval (0 2 1) 2 __t7yOw43 c) (exists eval (1 2 0) 2 e1 c) (exists select_branch (2 3 0 1) 2 e2 e3) (exists eval (2 0 1) 1 c) (join-old if (2 3 1 0) 3 (2 3 1 0) e2 e3 e1 __t3ePt42) (join-old eval (0 2 1) 3 (0 2 1) __t7yOw43 c __t3ePt42) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t9ATC44) (exists eval_ans (0 1) 1 __t9ATC44) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t5q6W45 __v0) (join eval_ans (0 1) 2 __t9ATC44 __v0) (join select_branch_ans (0 1) 1 __t5q6W45 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t4U4F46) (join eval_ans (0 1) 1 __t4U4F46 __v2)) (head (emit eval_ans (0 1) __t7yOw43 __v2)) interp.slog:87 #f)
  class ReadTask408 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex390;  slog::Index** evalindex391;  slog::Index** select_branchindex392;  slog::Index** evalindex393;  slog::Index** ifindex394;  slog::Index** evalindex395;  slog::Index** evalindex396;  slog::Index** eval_ansindex397;  slog::Index** select_branchindex398;  slog::Index** eval_ansindex399;  slog::Index** select_branch_ansindex400;  slog::Index** evalindex401;  slog::Index** eval_ansindex402;  slog::Index** ifdelta403;  slog::Index** evaldelta404;  slog::Index** evaldelta405;  slog::Index** select_branchdelta406;  slog::Index** evaldelta407;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("eval_ans");
      head_index[0] = readrel410->getIndex(ord409, false);
      outer_rel = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord411({0, 2, 1});
      slog::Relation* readrel412 = db->getRelation("eval");
      evalindex390 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({1, 2, 0});
      slog::Relation* readrel414 = db->getRelation("eval");
      evalindex391 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({2, 3, 0, 1});
      slog::Relation* readrel416 = db->getRelation("select_branch");
      select_branchindex392 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({2, 0, 1});
      slog::Relation* readrel418 = db->getRelation("eval");
      evalindex393 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({2, 3, 1, 0});
      slog::Relation* readrel420 = db->getRelation("if");
      ifindex394 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({2, 3, 1, 0});
      slog::Relation* readrel422 = db->getRelation("if");
      ifdelta403 = readrel422->getIndex(ord421, true);
      std::vector<u16> ord423({0, 2, 1});
      slog::Relation* readrel424 = db->getRelation("eval");
      evalindex395 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({0, 2, 1});
      slog::Relation* readrel426 = db->getRelation("eval");
      evaldelta404 = readrel426->getIndex(ord425, true);
      std::vector<u16> ord427({1, 2, 0});
      slog::Relation* readrel428 = db->getRelation("eval");
      evalindex396 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({1, 2, 0});
      slog::Relation* readrel430 = db->getRelation("eval");
      evaldelta405 = readrel430->getIndex(ord429, true);
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("eval_ans");
      eval_ansindex397 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({2, 3, 0, 1});
      slog::Relation* readrel434 = db->getRelation("select_branch");
      select_branchindex398 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({2, 3, 0, 1});
      slog::Relation* readrel436 = db->getRelation("select_branch");
      select_branchdelta406 = readrel436->getIndex(ord435, true);
      std::vector<u16> ord437({0, 1});
      slog::Relation* readrel438 = db->getRelation("eval_ans");
      eval_ansindex399 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({0, 1});
      slog::Relation* readrel440 = db->getRelation("select_branch_ans");
      select_branch_ansindex400 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({1, 2, 0});
      slog::Relation* readrel442 = db->getRelation("eval");
      evalindex401 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 2, 0});
      slog::Relation* readrel444 = db->getRelation("eval");
      evaldelta407 = readrel444->getIndex(ord443, true);
      std::vector<u16> ord445({0, 1});
      slog::Relation* readrel446 = db->getRelation("eval_ans");
      eval_ansindex402 = readrel446->getIndex(ord445, false);
  
    }
    ReadTask408(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c86 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c88 = _t[2];
        u64 v_c89 = _t[3];
        u64 v_c90 = _t[4];
        if (!slog::exists_probe<3,2>(evalindex390, std::array<u64,3>{v_c86, v_c17, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex391, std::array<u64,3>{v_c88, v_c17, 0})) return;
        if (!slog::exists_probe<4,2>(select_branchindex392, std::array<u64,4>{v_c89, v_c90, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex393, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe_old<4,3>(ifindex394, ifdelta403, std::array<u64,4>{v_c89, v_c90, v_c88, 0}, [&](const std::array<u64,4>& m447) {
          u64 v_c87 = m447[3];
          slog::join_probe_old<3,3>(evalindex395, evaldelta404, std::array<u64,3>{v_c86, v_c17, v_c87}, [&](const std::array<u64,3>& m448) {
            slog::join_probe_old<3,2>(evalindex396, evaldelta405, std::array<u64,3>{v_c88, v_c17, 0}, [&](const std::array<u64,3>& m449) {
              u64 v_c91 = m449[2];
              if (!slog::exists_probe<2,1>(eval_ansindex397, std::array<u64,2>{v_c91, 0})) return;
              slog::join_probe_old<4,2>(select_branchindex398, select_branchdelta406, std::array<u64,4>{v_c89, v_c90, 0, 0}, [&](const std::array<u64,4>& m450) {
                u64 v_c85 = m450[2]; u64 v_c50 = m450[3];
                slog::join_probe<2,2>(eval_ansindex399, std::array<u64,2>{v_c91, v_c50}, [&](const std::array<u64,2>& m451) {
                  slog::join_probe<2,1>(select_branch_ansindex400, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m452) {
                    u64 v_c84 = m452[1];
                    slog::join_probe_old<3,2>(evalindex401, evaldelta407, std::array<u64,3>{v_c84, v_c17, 0}, [&](const std::array<u64,3>& m453) {
                      u64 v_c82 = m453[2];
                      slog::join_probe<2,1>(eval_ansindex402, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m454) {
                        u64 v_c83 = m454[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c86, v_c83}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:$sup56712x86x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst0GOL695 const0122baa3ac55f1b433944eb1) (let __tconst6e36161 const06abaa100ecef791ce028c56) (let _00024sqc80WS474 constd4735e3a265e16eee03f5971) (let _00024sqc8EM3475 const5feceb66ffc86f38d952786c) (let _00024sqc7MGk476 const6b86b273ff34fce19d6b804e) (let _00024sqo5t7q477 const5feceb66ffc86f38d952786c) (let _00024sqo2Tf4478 const6b86b273ff34fce19d6b804e) (let _00024sqo8e4d479 const6b86b273ff34fce19d6b804e) (let _00024sqo87UW480 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo87UW480 __t5NWC164 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5t7q477 __t5NWC164 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo2Tf4478 __t5NWC164 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo8e4d479 __t5NWC164 _00024seq2) (exists _enum (1 0) 1 __tconst0GOL695) (join delta (1 2 0) 2 __tconst6e36161 _00024seq2 __t2Zbc162) (join _enum (1 0) 1 __tconst0GOL695 __t2rtp159) (join prim (0 1) 1 __t5NWC164 op) (letp _00024sql8XpT472 (aslst _00024seq2)) (let chk7SFm987 (llen _00024sql8XpT472)) (eq _00024sqc80WS474 chk7SFm987) (letp chk6XK8988 (lref _00024sql8XpT472 _00024sqc8EM3475)) (eq __t5NWC164 chk6XK8988) (letp chk7d8v989 (lref _00024sql8XpT472 _00024sqc7MGk476)) (eq __t5NWC164 chk7d8v989)) (head (emit-temp temp50La972 __t2Zbc162) (mkstruct boolval (1 0) __t5Llk160 __t2rtp159)) interp.slog:119 #f)
  class ReadTask462 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex455;  slog::Index** $seq_atindex456;  slog::Index** $seq_atrindex457;  slog::Index** _enumindex458;  slog::Index** deltaindex459;  slog::Index** _enumindex460;  slog::Index** primindex461;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp50La972");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord463({1, 0, 2});
      slog::Relation* readrel464 = db->getRelation("$seq_atr");
      driver_index = readrel464->getIndex(ord463, true);
      std::vector<u16> ord465({1, 0, 2});
      slog::Relation* readrel466 = db->getRelation("$seq_at");
      $seq_atindex455 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({1, 0, 2});
      slog::Relation* readrel468 = db->getRelation("$seq_at");
      $seq_atindex456 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({1, 0, 2});
      slog::Relation* readrel470 = db->getRelation("$seq_atr");
      $seq_atrindex457 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 0});
      slog::Relation* readrel472 = db->getRelation("_enum");
      _enumindex458 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 2, 0});
      slog::Relation* readrel474 = db->getRelation("delta");
      deltaindex459 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({1, 0});
      slog::Relation* readrel476 = db->getRelation("_enum");
      _enumindex460 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({0, 1});
      slog::Relation* readrel478 = db->getRelation("prim");
      primindex461 = readrel478->getIndex(ord477, false);
  
    }
    ReadTask462(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c92 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c93 = v_const06abaa100ecef791ce028c56;
      u64 v_c94 = v_constd4735e3a265e16eee03f5971;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
      u64 v_c96 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c97 = v_const5feceb66ffc86f38d952786c;
      u64 v_c98 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c100 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c100, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m479) {
        u64 v_c101 = m479[1];
        u64 v_c33 = m479[2];
        if (buckethash(v_c101) != bucket) return;
        slog::join_probe<3,3>($seq_atindex455, std::array<u64,3>{v_c97, v_c101, v_c33}, [&](const std::array<u64,3>& m480) {
          slog::join_probe<3,3>($seq_atindex456, std::array<u64,3>{v_c98, v_c101, v_c33}, [&](const std::array<u64,3>& m481) {
            slog::join_probe<3,3>($seq_atrindex457, std::array<u64,3>{v_c99, v_c101, v_c33}, [&](const std::array<u64,3>& m482) {
              if (!slog::exists_probe<2,1>(_enumindex458, std::array<u64,2>{v_c92, 0})) return;
              slog::join_probe<3,2>(deltaindex459, std::array<u64,3>{v_c93, v_c33, 0}, [&](const std::array<u64,3>& m483) {
                u64 v_c102 = m483[2];
                slog::join_probe<2,1>(_enumindex460, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m484) {
                  u64 v_c103 = m484[1];
                  slog::join_probe<2,1>(primindex461, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m485) {
                    u64 v_c104 = m485[1];
                    bool ok486 = true;
                    u64 v_c105 = _prim_aslst(db, v_c33, &ok486);
                    if (!ok486) return;
                    u64 v_c106 = _prim_llen(db, v_c105);
                    if (v_c106 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c94 != v_c106) return;
                    bool ok487 = true;
                    u64 v_c107 = _prim_lref(db, v_c105, v_c95, &ok487);
                    if (!ok487) return;
                    if (v_c101 != v_c107) return;
                    bool ok488 = true;
                    u64 v_c108 = _prim_lref(db, v_c105, v_c96, &ok488);
                    if (!ok488) return;
                    if (v_c101 != v_c108) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c102});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c103}, std::array<u16,2>{1, 0});
                  });
                });
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
        ReadTask462* _cont = new ReadTask462(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask462(db,b), false);
  // (crule (pre) (scan eval __3Nvs603 __t3qv3128 c) (body (join-old app (0 1 2) 1 (0 1 2) __t3qv3128 ef es)) (head (mkstruct tick (1 2 0) __4klm604 __t3qv3128 c)) analysis.slog:11 #f)
  class ReadTask491 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex489;  slog::Index** appdelta490;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord492({0, 1, 2});
      slog::Relation* readrel493 = db->getRelation("app");
      appindex489 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1, 2});
      slog::Relation* readrel495 = db->getRelation("app");
      appdelta490 = readrel495->getIndex(ord494, true);
  
    }
    ReadTask491(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c109 = _t[0];
        u64 v_c110 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe_old<3,1>(appindex489, appdelta490, std::array<u64,3>{v_c110, 0, 0}, [&](const std::array<u64,3>& m496) {
          u64 v_c42 = m496[1]; u64 v_c43 = m496[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c110, v_c17}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis.slog:11", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask491* _cont = new ReadTask491(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask491(db,b), false);
  // (crule (pre (let __trid7lWj636 const5963fd3eff55776ca49412c5) (let __trel7Uwf637 const4a59dbb9cb3129dfcc75170b) (let __tcol6nlQ638 const5feceb66ffc86f38d952786c) (let __trel8Uno639 const4a59dbb9cb3129dfcc75170b) (let __tcol8ers640 const6b86b273ff34fce19d6b804e)) (scan $sup56712x74x0x0x0 __d0 c ef es) (body) (head (tycheck ef (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid7lWj636 __trel7Uwf637 __tcol6nlQ638 (1 2 3 4 0)) (tycheck c (accept seq) __trid7lWj636 __trel8Uno639 __tcol8ers640 (1 2 3 4 0)) (mkstruct eval (1 2 0) __0nRi635 ef c)) interp.slog:75 #f)
  class ReadTask506 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid497;  u32 sid498;  u32 sid499;  u32 sid500;  u32 sid501;  u32 sid502;  u32 sid503;  u32 sid504;  u32 sid505;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup56712x74x0x0x0");
      sid497 = db->getRelation("app")->getStructId();
      sid498 = db->getRelation("boolean")->getStructId();
      sid499 = db->getRelation("if")->getStructId();
      sid500 = db->getRelation("lambda")->getStructId();
      sid501 = db->getRelation("let")->getStructId();
      sid502 = db->getRelation("letrec")->getStructId();
      sid503 = db->getRelation("num")->getStructId();
      sid504 = db->getRelation("ref")->getStructId();
      sid505 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask506(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c111 = v_const5963fd3eff55776ca49412c5;
      u64 v_c112 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c113 = v_const5feceb66ffc86f38d952786c;
      u64 v_c114 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c115 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c44 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c42 = _t[2];
        u64 v_c43 = _t[3];
        ++_fires;
        if (!((is_struct(v_c42) && (decode_struct_id(v_c42) == sid497 || decode_struct_id(v_c42) == sid498 || decode_struct_id(v_c42) == sid499 || decode_struct_id(v_c42) == sid500 || decode_struct_id(v_c42) == sid501 || decode_struct_id(v_c42) == sid502 || decode_struct_id(v_c42) == sid503 || decode_struct_id(v_c42) == sid504 || decode_struct_id(v_c42) == sid505))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c111, v_c112, v_c113, v_c42}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c17)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c111, v_c114, v_c115, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c42, v_c17}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:$sup56712x74x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask506* _cont = new ReadTask506(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask506(db,b), false);
  // (crule (pre (let __tconst0GOL695 const0122baa3ac55f1b433944eb1) (let __tconst6e36161 const06abaa100ecef791ce028c56) (let _00024sqc80WS474 constd4735e3a265e16eee03f5971) (let _00024sqc8EM3475 const5feceb66ffc86f38d952786c) (let _00024sqc7MGk476 const6b86b273ff34fce19d6b804e) (let _00024sqo5t7q477 const5feceb66ffc86f38d952786c) (let _00024sqo2Tf4478 const6b86b273ff34fce19d6b804e) (let _00024sqo8e4d479 const6b86b273ff34fce19d6b804e) (let _00024sqo87UW480 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst6e36161 _00024seq2 __t2Zbc162) (body (letp _00024sql8XpT472 (aslst _00024seq2)) (letp __t5NWC164 (lref _00024sql8XpT472 _00024sqc8EM3475)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5t7q477 __t5NWC164 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2Tf4478 __t5NWC164 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8e4d479 __t5NWC164 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo87UW480 __t5NWC164 _00024seq2) (join _enum (1 0) 1 __tconst0GOL695 __t2rtp159) (join-old prim (0 1) 1 (0 1) __t5NWC164 op) (let chk6BuD973 (llen _00024sql8XpT472)) (eq _00024sqc80WS474 chk6BuD973) (letp chk7FEN974 (lref _00024sql8XpT472 _00024sqc7MGk476)) (eq __t5NWC164 chk7FEN974)) (head (emit-temp temp50La972 __t2Zbc162) (mkstruct boolval (1 0) __t5Llk160 __t2rtp159)) interp.slog:119 #f)
  class ReadTask518 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex507;  slog::Index** $seq_atindex508;  slog::Index** $seq_atrindex509;  slog::Index** $seq_atrindex510;  slog::Index** _enumindex511;  slog::Index** primindex512;  slog::Index** $seq_atdelta513;  slog::Index** $seq_atdelta514;  slog::Index** $seq_atrdelta515;  slog::Index** $seq_atrdelta516;  slog::Index** primdelta517;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp50La972");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord519({1, 2, 0});
      slog::Relation* readrel520 = db->getRelation("delta");
      driver_index = readrel520->getIndex(ord519, true);
      std::vector<u16> ord521({1, 0, 2});
      slog::Relation* readrel522 = db->getRelation("$seq_at");
      $seq_atindex507 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({1, 0, 2});
      slog::Relation* readrel524 = db->getRelation("$seq_at");
      $seq_atdelta513 = readrel524->getIndex(ord523, true);
      std::vector<u16> ord525({1, 0, 2});
      slog::Relation* readrel526 = db->getRelation("$seq_at");
      $seq_atindex508 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 0, 2});
      slog::Relation* readrel528 = db->getRelation("$seq_at");
      $seq_atdelta514 = readrel528->getIndex(ord527, true);
      std::vector<u16> ord529({1, 0, 2});
      slog::Relation* readrel530 = db->getRelation("$seq_atr");
      $seq_atrindex509 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({1, 0, 2});
      slog::Relation* readrel532 = db->getRelation("$seq_atr");
      $seq_atrdelta515 = readrel532->getIndex(ord531, true);
      std::vector<u16> ord533({1, 0, 2});
      slog::Relation* readrel534 = db->getRelation("$seq_atr");
      $seq_atrindex510 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 0, 2});
      slog::Relation* readrel536 = db->getRelation("$seq_atr");
      $seq_atrdelta516 = readrel536->getIndex(ord535, true);
      std::vector<u16> ord537({1, 0});
      slog::Relation* readrel538 = db->getRelation("_enum");
      _enumindex511 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({0, 1});
      slog::Relation* readrel540 = db->getRelation("prim");
      primindex512 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({0, 1});
      slog::Relation* readrel542 = db->getRelation("prim");
      primdelta517 = readrel542->getIndex(ord541, true);
  
    }
    ReadTask518(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c92 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c93 = v_const06abaa100ecef791ce028c56;
      u64 v_c94 = v_constd4735e3a265e16eee03f5971;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
      u64 v_c96 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c97 = v_const5feceb66ffc86f38d952786c;
      u64 v_c98 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c100 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c93, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m543) {
        u64 v_c33 = m543[1];
        u64 v_c102 = m543[2];
        if (buckethash(v_c33) != bucket) return;
        bool ok544 = true;
        u64 v_c105 = _prim_aslst(db, v_c33, &ok544);
        if (!ok544) return;
        bool ok545 = true;
        u64 v_c101 = _prim_lref(db, v_c105, v_c95, &ok545);
        if (!ok545) return;
        slog::join_probe_old<3,3>($seq_atindex507, $seq_atdelta513, std::array<u64,3>{v_c97, v_c101, v_c33}, [&](const std::array<u64,3>& m546) {
          slog::join_probe_old<3,3>($seq_atindex508, $seq_atdelta514, std::array<u64,3>{v_c98, v_c101, v_c33}, [&](const std::array<u64,3>& m547) {
            slog::join_probe_old<3,3>($seq_atrindex509, $seq_atrdelta515, std::array<u64,3>{v_c99, v_c101, v_c33}, [&](const std::array<u64,3>& m548) {
              slog::join_probe_old<3,3>($seq_atrindex510, $seq_atrdelta516, std::array<u64,3>{v_c100, v_c101, v_c33}, [&](const std::array<u64,3>& m549) {
                slog::join_probe<2,1>(_enumindex511, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m550) {
                  u64 v_c103 = m550[1];
                  slog::join_probe_old<2,1>(primindex512, primdelta517, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m551) {
                    u64 v_c104 = m551[1];
                    u64 v_c116 = _prim_llen(db, v_c105);
                    if (v_c116 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c94 != v_c116) return;
                    bool ok552 = true;
                    u64 v_c117 = _prim_lref(db, v_c105, v_c96, &ok552);
                    if (!ok552) return;
                    if (v_c101 != v_c117) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c102});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c103}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask518* _cont = new ReadTask518(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask518(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre960J817 __errf92DH818 __errf2Llk819) (body) (head (emit error (0) __erre960J817)) <internal>:1 #f)
  class ReadTask553 : public slog::Task
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
      std::vector<u16> ord554({0});
      slog::Relation* readrel555 = db->getRelation("error");
      head_index[0] = readrel555->getIndex(ord554, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask553(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c118 = _t[0];
        u64 v_c119 = _t[1];
        u64 v_c120 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c118}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask553* _cont = new ReadTask553(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask553(db,b), false);
  // (crule (pre) (scan eval_args __t2Zls334 es c) (body (exists eval (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t2Zls334) (join $sup56712x74x0x0x0 (1 3 0 2) 2 c es __d0 ef) (join eval (1 2 0) 2 ef c __t3Egw332) (join eval_ans (0 1) 1 __t3Egw332 __t68RF333) (join eval_args_ans (0 1) 1 __t2Zls334 vs) (join prim (0 1) 1 __t68RF333 op)) (head (mkstruct delta (1 2 0) __5JOh701 op vs)) interp.slog:75 #f)
  class ReadTask563 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex556;  slog::Index** eval_args_ansindex557;  slog::Index** $sup56712x74x0x0x0index558;  slog::Index** evalindex559;  slog::Index** eval_ansindex560;  slog::Index** eval_args_ansindex561;  slog::Index** primindex562;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord564({2, 0, 1});
      slog::Relation* readrel565 = db->getRelation("eval");
      evalindex556 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({0, 1});
      slog::Relation* readrel567 = db->getRelation("eval_args_ans");
      eval_args_ansindex557 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 3, 0, 2});
      slog::Relation* readrel569 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index558 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 2, 0});
      slog::Relation* readrel571 = db->getRelation("eval");
      evalindex559 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({0, 1});
      slog::Relation* readrel573 = db->getRelation("eval_ans");
      eval_ansindex560 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({0, 1});
      slog::Relation* readrel575 = db->getRelation("eval_args_ans");
      eval_args_ansindex561 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({0, 1});
      slog::Relation* readrel577 = db->getRelation("prim");
      primindex562 = readrel577->getIndex(ord576, false);
  
    }
    ReadTask563(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c121 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex556, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex557, std::array<u64,2>{v_c121, 0})) return;
        slog::join_probe<4,2>($sup56712x74x0x0x0index558, std::array<u64,4>{v_c17, v_c43, 0, 0}, [&](const std::array<u64,4>& m578) {
          u64 v_c44 = m578[2]; u64 v_c42 = m578[3];
          slog::join_probe<3,2>(evalindex559, std::array<u64,3>{v_c42, v_c17, 0}, [&](const std::array<u64,3>& m579) {
            u64 v_c122 = m579[2];
            slog::join_probe<2,1>(eval_ansindex560, std::array<u64,2>{v_c122, 0}, [&](const std::array<u64,2>& m580) {
              u64 v_c123 = m580[1];
              slog::join_probe<2,1>(eval_args_ansindex561, std::array<u64,2>{v_c121, 0}, [&](const std::array<u64,2>& m581) {
                u64 v_c49 = m581[1];
                slog::join_probe<2,1>(primindex562, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m582) {
                  u64 v_c104 = m582[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c104, v_c49}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask563* _cont = new ReadTask563(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask563(db,b), false);
  // (crule (pre) (scan eval __t4U4F46 __v1 c) (body (exists eval_ans (0 1) 1 __t4U4F46) (exists eval (2 0 1) 1 c) (exists $sup56712x86x0x0x0 (1 0 2 3 4) 1 c) (join select_branch_ans (1 0) 1 __v1 __t5q6W45) (join eval_ans (0 1) 1 __t4U4F46 __v2) (join eval (2 0 1) 1 c __t7yOw43 __t3ePt42) (join $sup56712x86x0x0x0 (1 0 2 3 4) 2 c __t7yOw43 e1 e2 e3) (join if (2 3 1 0) 4 e2 e3 e1 __t3ePt42) (exists eval (1 2 0) 2 e1 c) (join select_branch (2 3 0 1) 3 e2 e3 __t5q6W45 __v0) (exists eval_ans (1 0) 1 __v0) (join eval (1 2 0) 2 e1 c __t9ATC44) (join eval_ans (0 1) 2 __t9ATC44 __v0)) (head (emit eval_ans (0 1) __t7yOw43 __v2)) interp.slog:87 #f)
  class ReadTask596 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex583;  slog::Index** evalindex584;  slog::Index** $sup56712x86x0x0x0index585;  slog::Index** select_branch_ansindex586;  slog::Index** eval_ansindex587;  slog::Index** evalindex588;  slog::Index** $sup56712x86x0x0x0index589;  slog::Index** ifindex590;  slog::Index** evalindex591;  slog::Index** select_branchindex592;  slog::Index** eval_ansindex593;  slog::Index** evalindex594;  slog::Index** eval_ansindex595;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord597({0, 1});
      slog::Relation* readrel598 = db->getRelation("eval_ans");
      head_index[0] = readrel598->getIndex(ord597, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord599({0, 1});
      slog::Relation* readrel600 = db->getRelation("eval_ans");
      eval_ansindex583 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({2, 0, 1});
      slog::Relation* readrel602 = db->getRelation("eval");
      evalindex584 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({1, 0, 2, 3, 4});
      slog::Relation* readrel604 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index585 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({1, 0});
      slog::Relation* readrel606 = db->getRelation("select_branch_ans");
      select_branch_ansindex586 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({0, 1});
      slog::Relation* readrel608 = db->getRelation("eval_ans");
      eval_ansindex587 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({2, 0, 1});
      slog::Relation* readrel610 = db->getRelation("eval");
      evalindex588 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({1, 0, 2, 3, 4});
      slog::Relation* readrel612 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index589 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({2, 3, 1, 0});
      slog::Relation* readrel614 = db->getRelation("if");
      ifindex590 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("eval");
      evalindex591 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({2, 3, 0, 1});
      slog::Relation* readrel618 = db->getRelation("select_branch");
      select_branchindex592 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 0});
      slog::Relation* readrel620 = db->getRelation("eval_ans");
      eval_ansindex593 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({1, 2, 0});
      slog::Relation* readrel622 = db->getRelation("eval");
      evalindex594 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({0, 1});
      slog::Relation* readrel624 = db->getRelation("eval_ans");
      eval_ansindex595 = readrel624->getIndex(ord623, false);
  
    }
    ReadTask596(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c84 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<2,1>(eval_ansindex583, std::array<u64,2>{v_c82, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex584, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<5,1>($sup56712x86x0x0x0index585, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(select_branch_ansindex586, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m625) {
          u64 v_c85 = m625[1];
          slog::join_probe<2,1>(eval_ansindex587, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m626) {
            u64 v_c83 = m626[1];
            slog::join_probe<3,1>(evalindex588, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m627) {
              u64 v_c86 = m627[1]; u64 v_c87 = m627[2];
              slog::join_probe<5,2>($sup56712x86x0x0x0index589, std::array<u64,5>{v_c17, v_c86, 0, 0, 0}, [&](const std::array<u64,5>& m628) {
                u64 v_c88 = m628[2]; u64 v_c89 = m628[3]; u64 v_c90 = m628[4];
                slog::join_probe<4,4>(ifindex590, std::array<u64,4>{v_c89, v_c90, v_c88, v_c87}, [&](const std::array<u64,4>& m629) {
                  if (!slog::exists_probe<3,2>(evalindex591, std::array<u64,3>{v_c88, v_c17, 0})) return;
                  slog::join_probe<4,3>(select_branchindex592, std::array<u64,4>{v_c89, v_c90, v_c85, 0}, [&](const std::array<u64,4>& m630) {
                    u64 v_c50 = m630[3];
                    if (!slog::exists_probe<2,1>(eval_ansindex593, std::array<u64,2>{v_c50, 0})) return;
                    slog::join_probe<3,2>(evalindex594, std::array<u64,3>{v_c88, v_c17, 0}, [&](const std::array<u64,3>& m631) {
                      u64 v_c91 = m631[2];
                      slog::join_probe<2,2>(eval_ansindex595, std::array<u64,2>{v_c91, v_c50}, [&](const std::array<u64,2>& m632) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c86, v_c83}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask596* _cont = new ReadTask596(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask596(db,b), false);
  // (crule (pre (let __tconst63FS700 constb9e118781cea1f9fa01462e0)) (scan boolval __t9W2N213 __t2bEf212) (body (join _enum (0 1) 2 __t2bEf212 __tconst63FS700) (join-old select_branch (1 2 3 0) 1 (1 2 3 0) __t9W2N213 e2 e3 __t7eum214)) (head (emit select_branch_ans (0 1) __t7eum214 e3)) interp.slog:84 #f)
  class ReadTask636 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex633;  slog::Index** select_branchindex634;  slog::Index** select_branchdelta635;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord637({0, 1});
      slog::Relation* readrel638 = db->getRelation("select_branch_ans");
      head_index[0] = readrel638->getIndex(ord637, false);
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord639({0, 1});
      slog::Relation* readrel640 = db->getRelation("_enum");
      _enumindex633 = readrel640->getIndex(ord639, false);
      std::vector<u16> ord641({1, 2, 3, 0});
      slog::Relation* readrel642 = db->getRelation("select_branch");
      select_branchindex634 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({1, 2, 3, 0});
      slog::Relation* readrel644 = db->getRelation("select_branch");
      select_branchdelta635 = readrel644->getIndex(ord643, true);
  
    }
    ReadTask636(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c124 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c125 = _t[0];
        u64 v_c126 = _t[1];
        slog::join_probe<2,2>(_enumindex633, std::array<u64,2>{v_c126, v_c124}, [&](const std::array<u64,2>& m645) {
          slog::join_probe_old<4,1>(select_branchindex634, select_branchdelta635, std::array<u64,4>{v_c125, 0, 0, 0}, [&](const std::array<u64,4>& m646) {
            u64 v_c89 = m646[1]; u64 v_c90 = m646[2]; u64 v_c127 = m646[3];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c127, v_c90}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:84", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask636* _cont = new ReadTask636(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask636(db,b), false);
  // (crule (pre) (scan temp4IIT859 __t5icw66 c m site) (body (let __t895k67 (lpush __t5icw66 site))) (head (emit-temp temp2lwj860 __t895k67 c m)) context.slog:10 #f)
  class ReadTask647 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2lwj860");
      outer_rel = db->getRelation("temp4IIT859");
  
    }
    ReadTask647(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c128 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c129 = _t[2];
        u64 v_c130 = _t[3];
        u64 v_c131 = _prim_lpush(db, v_c128, v_c130);
        if (v_c131 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c131, v_c17, v_c129});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:temp4IIT859", _fires);
  
      if (!_done)
      {
        ReadTask647* _cont = new ReadTask647(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask647(db,b), false);
  // (crule (pre) (scan eval __t3Qfa308 __t8pF7307 c) (body (exists eval (2 0 1) 1 c) (join $sup56712x93x0x0x0 (0 1 2 3 4) 2 __t3Qfa308 c eb er x) (join letrec (2 1 3 0) 4 er x eb __t8pF7307) (exists eval (1 2 0) 2 eb c) (join-old eval (1 2 0) 2 (1 2 0) er c __t8bEj309) (exists eval_ans (0 1) 1 __t8bEj309) (join-old eval (1 2 0) 2 (1 2 0) eb c __t8NjM310) (exists eval_ans (0 1) 1 __t8NjM310) (join eval_ans (0 1) 1 __t8bEj309 vr) (join eval_ans (0 1) 1 __t8NjM310 v)) (head (emit eval_ans (0 1) __t3Qfa308 v)) interp.slog:94 #f)
  class ReadTask660 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex648;  slog::Index** $sup56712x93x0x0x0index649;  slog::Index** letrecindex650;  slog::Index** evalindex651;  slog::Index** evalindex652;  slog::Index** eval_ansindex653;  slog::Index** evalindex654;  slog::Index** eval_ansindex655;  slog::Index** eval_ansindex656;  slog::Index** eval_ansindex657;  slog::Index** evaldelta658;  slog::Index** evaldelta659;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord661({0, 1});
      slog::Relation* readrel662 = db->getRelation("eval_ans");
      head_index[0] = readrel662->getIndex(ord661, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord663({2, 0, 1});
      slog::Relation* readrel664 = db->getRelation("eval");
      evalindex648 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({0, 1, 2, 3, 4});
      slog::Relation* readrel666 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index649 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({2, 1, 3, 0});
      slog::Relation* readrel668 = db->getRelation("letrec");
      letrecindex650 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({1, 2, 0});
      slog::Relation* readrel670 = db->getRelation("eval");
      evalindex651 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({1, 2, 0});
      slog::Relation* readrel672 = db->getRelation("eval");
      evalindex652 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({1, 2, 0});
      slog::Relation* readrel674 = db->getRelation("eval");
      evaldelta658 = readrel674->getIndex(ord673, true);
      std::vector<u16> ord675({0, 1});
      slog::Relation* readrel676 = db->getRelation("eval_ans");
      eval_ansindex653 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({1, 2, 0});
      slog::Relation* readrel678 = db->getRelation("eval");
      evalindex654 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({1, 2, 0});
      slog::Relation* readrel680 = db->getRelation("eval");
      evaldelta659 = readrel680->getIndex(ord679, true);
      std::vector<u16> ord681({0, 1});
      slog::Relation* readrel682 = db->getRelation("eval_ans");
      eval_ansindex655 = readrel682->getIndex(ord681, false);
      std::vector<u16> ord683({0, 1});
      slog::Relation* readrel684 = db->getRelation("eval_ans");
      eval_ansindex656 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({0, 1});
      slog::Relation* readrel686 = db->getRelation("eval_ans");
      eval_ansindex657 = readrel686->getIndex(ord685, false);
  
    }
    ReadTask660(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c132 = _t[0];
        u64 v_c133 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex648, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe<5,2>($sup56712x93x0x0x0index649, std::array<u64,5>{v_c132, v_c17, 0, 0, 0}, [&](const std::array<u64,5>& m687) {
          u64 v_c22 = m687[2]; u64 v_c18 = m687[3]; u64 v_c21 = m687[4];
          slog::join_probe<4,4>(letrecindex650, std::array<u64,4>{v_c18, v_c21, v_c22, v_c133}, [&](const std::array<u64,4>& m688) {
            if (!slog::exists_probe<3,2>(evalindex651, std::array<u64,3>{v_c22, v_c17, 0})) return;
            slog::join_probe_old<3,2>(evalindex652, evaldelta658, std::array<u64,3>{v_c18, v_c17, 0}, [&](const std::array<u64,3>& m689) {
              u64 v_c134 = m689[2];
              if (!slog::exists_probe<2,1>(eval_ansindex653, std::array<u64,2>{v_c134, 0})) return;
              slog::join_probe_old<3,2>(evalindex654, evaldelta659, std::array<u64,3>{v_c22, v_c17, 0}, [&](const std::array<u64,3>& m690) {
                u64 v_c135 = m690[2];
                if (!slog::exists_probe<2,1>(eval_ansindex655, std::array<u64,2>{v_c135, 0})) return;
                slog::join_probe<2,1>(eval_ansindex656, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m691) {
                  u64 v_c16 = m691[1];
                  slog::join_probe<2,1>(eval_ansindex657, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m692) {
                    u64 v_c136 = m692[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c132, v_c136}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask660* _cont = new ReadTask660(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask660(db,b), false);
  // (crule (pre (let __trid3Ey3582 const342a69eb5a93251c8b7e179a) (let __trel65ch583 constf6cdc3db4b71e0cdeda6912e) (let __tcol4Ars584 const6b86b273ff34fce19d6b804e) (let __trel1pCT585 constf6cdc3db4b71e0cdeda6912e) (let __tcol8ZHX586 constd4735e3a265e16eee03f5971)) (scan $sup56712x86x0x0x0 __d0 c e1 e2 e3) (body (join-old eval (1 2 0) 2 (1 2 0) e1 c __t9qzE362) (join-old eval_ans (0 1) 1 (0 1) __t9qzE362 __v0)) (head (tycheck e2 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid3Ey3582 __trel65ch583 __tcol4Ars584 (1 2 3 4 0)) (tycheck e3 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid3Ey3582 __trel1pCT585 __tcol8ZHX586 (1 2 3 4 0)) (mkstruct select_branch (1 2 3 0) __9nb7581 __v0 e2 e3)) interp.slog:87 #f)
  class ReadTask706 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex693;  slog::Index** eval_ansindex694;  slog::Index** evaldelta695;  slog::Index** eval_ansdelta696;
    u32 sid697;  u32 sid698;  u32 sid699;  u32 sid700;  u32 sid701;  u32 sid702;  u32 sid703;  u32 sid704;  u32 sid705;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("select_branch");
      outer_rel = db->getRelation("$sup56712x86x0x0x0");
      std::vector<u16> ord707({1, 2, 0});
      slog::Relation* readrel708 = db->getRelation("eval");
      evalindex693 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 2, 0});
      slog::Relation* readrel710 = db->getRelation("eval");
      evaldelta695 = readrel710->getIndex(ord709, true);
      std::vector<u16> ord711({0, 1});
      slog::Relation* readrel712 = db->getRelation("eval_ans");
      eval_ansindex694 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({0, 1});
      slog::Relation* readrel714 = db->getRelation("eval_ans");
      eval_ansdelta696 = readrel714->getIndex(ord713, true);
      sid697 = db->getRelation("app")->getStructId();
      sid698 = db->getRelation("boolean")->getStructId();
      sid699 = db->getRelation("if")->getStructId();
      sid700 = db->getRelation("lambda")->getStructId();
      sid701 = db->getRelation("let")->getStructId();
      sid702 = db->getRelation("letrec")->getStructId();
      sid703 = db->getRelation("num")->getStructId();
      sid704 = db->getRelation("ref")->getStructId();
      sid705 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask706(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c137 = v_const342a69eb5a93251c8b7e179a;
      u64 v_c138 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c141 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c44 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c88 = _t[2];
        u64 v_c89 = _t[3];
        u64 v_c90 = _t[4];
        slog::join_probe_old<3,2>(evalindex693, evaldelta695, std::array<u64,3>{v_c88, v_c17, 0}, [&](const std::array<u64,3>& m715) {
          u64 v_c142 = m715[2];
          slog::join_probe_old<2,1>(eval_ansindex694, eval_ansdelta696, std::array<u64,2>{v_c142, 0}, [&](const std::array<u64,2>& m716) {
            u64 v_c50 = m716[1];
            ++_fires;
            if (!((is_struct(v_c89) && (decode_struct_id(v_c89) == sid697 || decode_struct_id(v_c89) == sid698 || decode_struct_id(v_c89) == sid699 || decode_struct_id(v_c89) == sid700 || decode_struct_id(v_c89) == sid701 || decode_struct_id(v_c89) == sid702 || decode_struct_id(v_c89) == sid703 || decode_struct_id(v_c89) == sid704 || decode_struct_id(v_c89) == sid705))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c137, v_c138, v_c139, v_c89}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!((is_struct(v_c90) && (decode_struct_id(v_c90) == sid697 || decode_struct_id(v_c90) == sid698 || decode_struct_id(v_c90) == sid699 || decode_struct_id(v_c90) == sid700 || decode_struct_id(v_c90) == sid701 || decode_struct_id(v_c90) == sid702 || decode_struct_id(v_c90) == sid703 || decode_struct_id(v_c90) == sid704 || decode_struct_id(v_c90) == sid705))))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c137, v_c140, v_c141, v_c90}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c50, v_c89, v_c90}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:$sup56712x86x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask706* _cont = new ReadTask706(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask706(db,b), false);
  // (crule (pre (let __tconst36mF602 constcd2a69ce5ca278db1d6da969) (let __tconst4MYs19 const06abaa100ecef791ce028c56) (let _00024sqc0R1w414 constd4735e3a265e16eee03f5971) (let _00024sqc2r3q415 const5feceb66ffc86f38d952786c) (let _00024sqc1pwY416 const6b86b273ff34fce19d6b804e) (let _00024sqo5Wc9417 const5feceb66ffc86f38d952786c) (let _00024sqo4N7A418 const6b86b273ff34fce19d6b804e) (let _00024sqo8u9a419 const6b86b273ff34fce19d6b804e) (let _00024sqo9jvY420 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo5Wc9417 __t2nOL22 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo4N7A418 __t2nOL22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8u9a419 __t2nOL22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9jvY420 __t2nOL22 _00024seq2) (join _enum (0 1) 2 __t2nOL22 __tconst36mF602) (join delta (1 2 0) 2 __tconst4MYs19 _00024seq2 __t9afR20) (join any_bool (0) 0 b) (letp _00024sql9osm412 (aslst _00024seq2)) (let chk9tsv847 (llen _00024sql9osm412)) (eq _00024sqc0R1w414 chk9tsv847) (letp chk2bSc848 (lref _00024sql9osm412 _00024sqc2r3q415)) (eq __t2nOL22 chk2bSc848) (letp chk6DGP849 (lref _00024sql9osm412 _00024sqc1pwY416)) (eq __t2nOL22 chk6DGP849)) (head (emit-temp temp4fHg844 __t9afR20 b) (mkstruct boolval (1 0) __t975c18 b)) interp.slog:121 #f)
  class ReadTask726 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex717;  slog::Index** $seq_atrindex718;  slog::Index** $seq_atrindex719;  slog::Index** _enumindex720;  slog::Index** deltaindex721;  slog::Index** any_boolindex722;  slog::Index** $seq_atdelta723;  slog::Index** $seq_atrdelta724;  slog::Index** $seq_atrdelta725;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4fHg844");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord727({1, 0, 2});
      slog::Relation* readrel728 = db->getRelation("$seq_at");
      driver_index = readrel728->getIndex(ord727, true);
      std::vector<u16> ord729({1, 0, 2});
      slog::Relation* readrel730 = db->getRelation("$seq_at");
      $seq_atindex717 = readrel730->getIndex(ord729, false);
      std::vector<u16> ord731({1, 0, 2});
      slog::Relation* readrel732 = db->getRelation("$seq_at");
      $seq_atdelta723 = readrel732->getIndex(ord731, true);
      std::vector<u16> ord733({1, 0, 2});
      slog::Relation* readrel734 = db->getRelation("$seq_atr");
      $seq_atrindex718 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({1, 0, 2});
      slog::Relation* readrel736 = db->getRelation("$seq_atr");
      $seq_atrdelta724 = readrel736->getIndex(ord735, true);
      std::vector<u16> ord737({1, 0, 2});
      slog::Relation* readrel738 = db->getRelation("$seq_atr");
      $seq_atrindex719 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({1, 0, 2});
      slog::Relation* readrel740 = db->getRelation("$seq_atr");
      $seq_atrdelta725 = readrel740->getIndex(ord739, true);
      std::vector<u16> ord741({0, 1});
      slog::Relation* readrel742 = db->getRelation("_enum");
      _enumindex720 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({1, 2, 0});
      slog::Relation* readrel744 = db->getRelation("delta");
      deltaindex721 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({0});
      slog::Relation* readrel746 = db->getRelation("any_bool");
      any_boolindex722 = readrel746->getIndex(ord745, false);
  
    }
    ReadTask726(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c143 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c144 = v_const06abaa100ecef791ce028c56;
      u64 v_c145 = v_constd4735e3a265e16eee03f5971;
      u64 v_c146 = v_const5feceb66ffc86f38d952786c;
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c148 = v_const5feceb66ffc86f38d952786c;
      u64 v_c149 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c151 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c148, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m747) {
        u64 v_c152 = m747[1];
        u64 v_c33 = m747[2];
        if (buckethash(v_c152) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex717, $seq_atdelta723, std::array<u64,3>{v_c149, v_c152, v_c33}, [&](const std::array<u64,3>& m748) {
          slog::join_probe_old<3,3>($seq_atrindex718, $seq_atrdelta724, std::array<u64,3>{v_c150, v_c152, v_c33}, [&](const std::array<u64,3>& m749) {
            slog::join_probe_old<3,3>($seq_atrindex719, $seq_atrdelta725, std::array<u64,3>{v_c151, v_c152, v_c33}, [&](const std::array<u64,3>& m750) {
              slog::join_probe<2,2>(_enumindex720, std::array<u64,2>{v_c152, v_c143}, [&](const std::array<u64,2>& m751) {
                slog::join_probe<3,2>(deltaindex721, std::array<u64,3>{v_c144, v_c33, 0}, [&](const std::array<u64,3>& m752) {
                  u64 v_c153 = m752[2];
                  slog::join_all<1>(any_boolindex722, [&](const std::array<u64,1>& m753) {
                    u64 v_c36 = m753[0];
                    bool ok754 = true;
                    u64 v_c154 = _prim_aslst(db, v_c33, &ok754);
                    if (!ok754) return;
                    u64 v_c155 = _prim_llen(db, v_c154);
                    if (v_c155 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c145 != v_c155) return;
                    bool ok755 = true;
                    u64 v_c156 = _prim_lref(db, v_c154, v_c146, &ok755);
                    if (!ok755) return;
                    if (v_c152 != v_c156) return;
                    bool ok756 = true;
                    u64 v_c157 = _prim_lref(db, v_c154, v_c147, &ok756);
                    if (!ok756) return;
                    if (v_c152 != v_c157) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c153, v_c36});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c36}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask726* _cont = new ReadTask726(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask726(db,b), false);
  // (crule (pre) (scan app __t5Orx186 ef es) (body (join eval (1 2 0) 1 __t5Orx186 c __2wtW609) (join freevar (0 1) 0 y __t0Osl187) (join binding (0 1 2) 1 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t0Osl187 xs eb)) (head (mkstruct tick (1 2 0) __4U5c610 __t5Orx186 c)) interp.slog:56 #f)
  class ReadTask762 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex757;  slog::Index** freevarindex758;  slog::Index** bindingindex759;  slog::Index** lambdaindex760;  slog::Index** lambdadelta761;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord763({1, 2, 0});
      slog::Relation* readrel764 = db->getRelation("eval");
      evalindex757 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({0, 1});
      slog::Relation* readrel766 = db->getRelation("freevar");
      freevarindex758 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({0, 1, 2});
      slog::Relation* readrel768 = db->getRelation("binding");
      bindingindex759 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({0, 1, 2});
      slog::Relation* readrel770 = db->getRelation("lambda");
      lambdaindex760 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({0, 1, 2});
      slog::Relation* readrel772 = db->getRelation("lambda");
      lambdadelta761 = readrel772->getIndex(ord771, true);
  
    }
    ReadTask762(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c158 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c43 = _t[2];
        slog::join_probe<3,1>(evalindex757, std::array<u64,3>{v_c158, 0, 0}, [&](const std::array<u64,3>& m773) {
          u64 v_c17 = m773[1]; u64 v_c159 = m773[2];
          slog::join_all<2>(freevarindex758, [&](const std::array<u64,2>& m774) {
            u64 v_c160 = m774[0]; u64 v_c161 = m774[1];
            slog::join_probe<3,1>(bindingindex759, std::array<u64,3>{v_c160, 0, 0}, [&](const std::array<u64,3>& m775) {
              u64 v_c52 = m775[1]; u64 v_c162 = m775[2];
              slog::join_probe_old<3,1>(lambdaindex760, lambdadelta761, std::array<u64,3>{v_c161, 0, 0}, [&](const std::array<u64,3>& m776) {
                u64 v_c53 = m776[1]; u64 v_c22 = m776[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c158, v_c17}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask762* _cont = new ReadTask762(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask762(db,b), false);
  // (crule (pre (let __trid95J5611 const2a09f8e08b8d8243373579d9) (let __trel66gb612 const0bbd2fbd1dc4200473343503) (let __tcol4iaP613 const5feceb66ffc86f38d952786c)) (scan lambda __t9t79153 xs eb) (body (join-old eval (1 2 0) 1 (1 2 0) __t9t79153 c __t0Xgw154)) (head (tycheck __t9t79153 (accept (struct lambda)) __trid95J5611 __trel66gb612 __tcol4iaP613 (1 2 3 4 0)) (emit-temp temp2ZKS1041 __t0Xgw154 __t9t79153 c) (mkstruct closure (1 2 0) __t8gPR152 __t9t79153 c)) interp.slog:29 #f)
  class ReadTask780 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex777;  slog::Index** evaldelta778;
    u32 sid779;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp2ZKS1041");
      head_rel[2] = db->getRelation("closure");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord781({1, 2, 0});
      slog::Relation* readrel782 = db->getRelation("eval");
      evalindex777 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({1, 2, 0});
      slog::Relation* readrel784 = db->getRelation("eval");
      evaldelta778 = readrel784->getIndex(ord783, true);
      sid779 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask780(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const2a09f8e08b8d8243373579d9;
      u64 v_c164 = v_const0bbd2fbd1dc4200473343503;
      u64 v_c165 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c166 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c22 = _t[2];
        slog::join_probe_old<3,1>(evalindex777, evaldelta778, std::array<u64,3>{v_c166, 0, 0}, [&](const std::array<u64,3>& m785) {
          u64 v_c17 = m785[1]; u64 v_c167 = m785[2];
          ++_fires;
          if (!((is_struct(v_c166) && (decode_struct_id(v_c166) == sid779))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c163, v_c164, v_c165, v_c166}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit_temp<3>(head_rel[1], newbatch[1], std::array<u64,3>{v_c167, v_c166, v_c17});
          slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c166, v_c17}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:29", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask780* _cont = new ReadTask780(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask780(db,b), false);
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5) (let __tconst2U2F71 constef2d127de37b942baad06145)) (scan temp3h2w1003 __t223e104 __t4GbJ88 __t8dvA109) (body (exists num (1 0) 1 __tconst2U2F71) (exists ref (1 0) 1 __tconst2uSL111) (join lambda (1 2 0) 2 __t8dvA109 __t223e104 __t0Gv1110) (join num (1 0) 1 __tconst2U2F71 __t8tX372) (join ref (1 0) 1 __tconst2uSL111 __t0iVM91) (let __t0nIl89 (lpush __t4GbJ88 __t8tX372))) (head (emit-temp temp5Kz61004 __t0Gv1110 __t0nIl89)) analysis-demo.slog:11 #f)
  class ReadTask791 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex786;  slog::Index** refindex787;  slog::Index** lambdaindex788;  slog::Index** numindex789;  slog::Index** refindex790;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5Kz61004");
      outer_rel = db->getRelation("temp3h2w1003");
      std::vector<u16> ord792({1, 0});
      slog::Relation* readrel793 = db->getRelation("num");
      numindex786 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({1, 0});
      slog::Relation* readrel795 = db->getRelation("ref");
      refindex787 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 0});
      slog::Relation* readrel797 = db->getRelation("lambda");
      lambdaindex788 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 0});
      slog::Relation* readrel799 = db->getRelation("num");
      numindex789 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 0});
      slog::Relation* readrel801 = db->getRelation("ref");
      refindex790 = readrel801->getIndex(ord800, false);
  
    }
    ReadTask791(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0457bba0679825d285ef7fa5;
      u64 v_c3 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c168 = _t[0];
        u64 v_c169 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<2,1>(numindex786, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(refindex787, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<3,2>(lambdaindex788, std::array<u64,3>{v_c7, v_c168, 0}, [&](const std::array<u64,3>& m802) {
          u64 v_c170 = m802[2];
          slog::join_probe<2,1>(numindex789, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m803) {
            u64 v_c9 = m803[1];
            slog::join_probe<2,1>(refindex790, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m804) {
              u64 v_c11 = m804[1];
              u64 v_c171 = _prim_lpush(db, v_c169, v_c9);
              if (v_c171 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return; }
              ++_fires;
              slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c170, v_c171});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "delta:temp3h2w1003", _fires);
  
      if (!_done)
      {
        ReadTask791* _cont = new ReadTask791(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask791(db,b), false);
  // (crule (pre (let __trid95J5611 const2a09f8e08b8d8243373579d9) (let __trel66gb612 const0bbd2fbd1dc4200473343503) (let __tcol4iaP613 const5feceb66ffc86f38d952786c)) (scan eval __t0Xgw154 __t9t79153 c) (body (join lambda (0 1 2) 1 __t9t79153 xs eb)) (head (tycheck __t9t79153 (accept (struct lambda)) __trid95J5611 __trel66gb612 __tcol4iaP613 (1 2 3 4 0)) (emit-temp temp2ZKS1041 __t0Xgw154 __t9t79153 c) (mkstruct closure (1 2 0) __t8gPR152 __t9t79153 c)) interp.slog:29 #f)
  class ReadTask807 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex805;
    u32 sid806;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp2ZKS1041");
      head_rel[2] = db->getRelation("closure");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord808({0, 1, 2});
      slog::Relation* readrel809 = db->getRelation("lambda");
      lambdaindex805 = readrel809->getIndex(ord808, false);
      sid806 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask807(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const2a09f8e08b8d8243373579d9;
      u64 v_c164 = v_const0bbd2fbd1dc4200473343503;
      u64 v_c165 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c167 = _t[0];
        u64 v_c166 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe<3,1>(lambdaindex805, std::array<u64,3>{v_c166, 0, 0}, [&](const std::array<u64,3>& m810) {
          u64 v_c53 = m810[1]; u64 v_c22 = m810[2];
          ++_fires;
          if (!((is_struct(v_c166) && (decode_struct_id(v_c166) == sid806))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c163, v_c164, v_c165, v_c166}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit_temp<3>(head_rel[1], newbatch[1], std::array<u64,3>{v_c167, v_c166, v_c17});
          slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c166, v_c17}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:29", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask807* _cont = new ReadTask807(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask807(db,b), false);
  // (crule (pre (let __tconst5mQl666 constb9e118781cea1f9fa01462e0) (let __tconst7ska196 const06abaa100ecef791ce028c56) (let _00024sqc2bs1547 constd4735e3a265e16eee03f5971) (let _00024sqc3b5Z548 const5feceb66ffc86f38d952786c) (let _00024sqc4cPv549 const6b86b273ff34fce19d6b804e) (let _00024sqo2orM550 const5feceb66ffc86f38d952786c) (let _00024sqo79dC551 const6b86b273ff34fce19d6b804e) (let _00024sqo7ukz552 const6b86b273ff34fce19d6b804e) (let _00024sqo5FdA553 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst7ska196 _00024seq0 __t0ECW197) (body (letp _00024sql4FKJ545 (aslst _00024seq0)) (letp v1 (lref _00024sql4FKJ545 _00024sqc3b5Z548)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2orM550 v1 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7ukz552 v1 _00024seq0) (letp v2 (lref _00024sql4FKJ545 _00024sqc4cPv549)) (neq v1 v2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo79dC551 v2 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5FdA553 v2 _00024seq0) (join _enum (1 0) 1 __tconst5mQl666 __t7sei194) (let chk9ZVH871 (llen _00024sql4FKJ545)) (eq _00024sqc2bs1547 chk9ZVH871)) (head (emit-temp temp5E9s870 __t0ECW197) (mkstruct boolval (1 0) __t2gQB195 __t7sei194)) interp.slog:120 #f)
  class ReadTask820 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex811;  slog::Index** $seq_atrindex812;  slog::Index** $seq_atindex813;  slog::Index** $seq_atrindex814;  slog::Index** _enumindex815;  slog::Index** $seq_atdelta816;  slog::Index** $seq_atrdelta817;  slog::Index** $seq_atdelta818;  slog::Index** $seq_atrdelta819;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5E9s870");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord821({1, 2, 0});
      slog::Relation* readrel822 = db->getRelation("delta");
      driver_index = readrel822->getIndex(ord821, true);
      std::vector<u16> ord823({1, 0, 2});
      slog::Relation* readrel824 = db->getRelation("$seq_at");
      $seq_atindex811 = readrel824->getIndex(ord823, false);
      std::vector<u16> ord825({1, 0, 2});
      slog::Relation* readrel826 = db->getRelation("$seq_at");
      $seq_atdelta816 = readrel826->getIndex(ord825, true);
      std::vector<u16> ord827({1, 0, 2});
      slog::Relation* readrel828 = db->getRelation("$seq_atr");
      $seq_atrindex812 = readrel828->getIndex(ord827, false);
      std::vector<u16> ord829({1, 0, 2});
      slog::Relation* readrel830 = db->getRelation("$seq_atr");
      $seq_atrdelta817 = readrel830->getIndex(ord829, true);
      std::vector<u16> ord831({1, 0, 2});
      slog::Relation* readrel832 = db->getRelation("$seq_at");
      $seq_atindex813 = readrel832->getIndex(ord831, false);
      std::vector<u16> ord833({1, 0, 2});
      slog::Relation* readrel834 = db->getRelation("$seq_at");
      $seq_atdelta818 = readrel834->getIndex(ord833, true);
      std::vector<u16> ord835({1, 0, 2});
      slog::Relation* readrel836 = db->getRelation("$seq_atr");
      $seq_atrindex814 = readrel836->getIndex(ord835, false);
      std::vector<u16> ord837({1, 0, 2});
      slog::Relation* readrel838 = db->getRelation("$seq_atr");
      $seq_atrdelta819 = readrel838->getIndex(ord837, true);
      std::vector<u16> ord839({1, 0});
      slog::Relation* readrel840 = db->getRelation("_enum");
      _enumindex815 = readrel840->getIndex(ord839, false);
  
    }
    ReadTask820(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c172 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c173 = v_const06abaa100ecef791ce028c56;
      u64 v_c174 = v_constd4735e3a265e16eee03f5971;
      u64 v_c175 = v_const5feceb66ffc86f38d952786c;
      u64 v_c176 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c177 = v_const5feceb66ffc86f38d952786c;
      u64 v_c178 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c179 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c180 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c173, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m841) {
        u64 v_c181 = m841[1];
        u64 v_c182 = m841[2];
        if (buckethash(v_c181) != bucket) return;
        bool ok842 = true;
        u64 v_c183 = _prim_aslst(db, v_c181, &ok842);
        if (!ok842) return;
        bool ok843 = true;
        u64 v_c184 = _prim_lref(db, v_c183, v_c175, &ok843);
        if (!ok843) return;
        slog::join_probe_old<3,3>($seq_atindex811, $seq_atdelta816, std::array<u64,3>{v_c177, v_c184, v_c181}, [&](const std::array<u64,3>& m844) {
          slog::join_probe_old<3,3>($seq_atrindex812, $seq_atrdelta817, std::array<u64,3>{v_c179, v_c184, v_c181}, [&](const std::array<u64,3>& m845) {
            bool ok846 = true;
            u64 v_c185 = _prim_lref(db, v_c183, v_c176, &ok846);
            if (!ok846) return;
            if (v_c184 == v_c185) return;
            slog::join_probe_old<3,3>($seq_atindex813, $seq_atdelta818, std::array<u64,3>{v_c178, v_c185, v_c181}, [&](const std::array<u64,3>& m847) {
              slog::join_probe_old<3,3>($seq_atrindex814, $seq_atrdelta819, std::array<u64,3>{v_c180, v_c185, v_c181}, [&](const std::array<u64,3>& m848) {
                slog::join_probe<2,1>(_enumindex815, std::array<u64,2>{v_c172, 0}, [&](const std::array<u64,2>& m849) {
                  u64 v_c186 = m849[1];
                  u64 v_c187 = _prim_llen(db, v_c183);
                  if (v_c187 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c174 != v_c187) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c182});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c186}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:120", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask820* _cont = new ReadTask820(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask820(db,b), false);
  // (crule (pre) (scan lambda __t7rcY179 xs eb) (body (exists eval (1 2 0) 1 eb) (join-old closure (1 2 0) 1 (1 2 0) __t7rcY179 cb __t4yWQ180) (join eval_ans (1 0) 1 __t4yWQ180 __t6e44178) (join eval (0 2 1) 1 __t6e44178 c ef) (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join $sup56712x41x0x0x0 (1 2 3 0) 2 c ef es __t6uzd177) (exists app (1 2 0) 2 ef es) (exists eval_args (1 2 0) 2 es c) (join eval (0 2 1) 2 __t6uzd177 c __t7cos183) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (exists tick (1 2 0) 2 __t7cos183 c) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6UxD181) (exists eval_args_ans (0 1) 1 __t6UxD181) (join-old tick (1 2 0) 2 (1 2 0) __t7cos183 c __t8kWT184) (exists tick_ans (0 1) 1 __t8kWT184) (join eval_args_ans (0 1) 1 __t6UxD181 vs) (join tick_ans (0 1) 1 __t8kWT184 __v0) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t56Is182) (join eval_ans (0 1) 1 __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask877 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex850;  slog::Index** closureindex851;  slog::Index** eval_ansindex852;  slog::Index** evalindex853;  slog::Index** evalindex854;  slog::Index** appindex855;  slog::Index** eval_argsindex856;  slog::Index** tickindex857;  slog::Index** $sup56712x41x0x0x0index858;  slog::Index** appindex859;  slog::Index** eval_argsindex860;  slog::Index** evalindex861;  slog::Index** appindex862;  slog::Index** tickindex863;  slog::Index** eval_argsindex864;  slog::Index** eval_args_ansindex865;  slog::Index** tickindex866;  slog::Index** tick_ansindex867;  slog::Index** eval_args_ansindex868;  slog::Index** tick_ansindex869;  slog::Index** evalindex870;  slog::Index** eval_ansindex871;  slog::Index** closuredelta872;  slog::Index** appdelta873;  slog::Index** eval_argsdelta874;  slog::Index** tickdelta875;  slog::Index** evaldelta876;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord878({0, 1});
      slog::Relation* readrel879 = db->getRelation("eval_ans");
      head_index[0] = readrel879->getIndex(ord878, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord880({1, 2, 0});
      slog::Relation* readrel881 = db->getRelation("eval");
      evalindex850 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({1, 2, 0});
      slog::Relation* readrel883 = db->getRelation("closure");
      closureindex851 = readrel883->getIndex(ord882, false);
      std::vector<u16> ord884({1, 2, 0});
      slog::Relation* readrel885 = db->getRelation("closure");
      closuredelta872 = readrel885->getIndex(ord884, true);
      std::vector<u16> ord886({1, 0});
      slog::Relation* readrel887 = db->getRelation("eval_ans");
      eval_ansindex852 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({0, 2, 1});
      slog::Relation* readrel889 = db->getRelation("eval");
      evalindex853 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({2, 0, 1});
      slog::Relation* readrel891 = db->getRelation("eval");
      evalindex854 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({1, 2, 0});
      slog::Relation* readrel893 = db->getRelation("app");
      appindex855 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({2, 0, 1});
      slog::Relation* readrel895 = db->getRelation("eval_args");
      eval_argsindex856 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({2, 0, 1});
      slog::Relation* readrel897 = db->getRelation("tick");
      tickindex857 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({1, 2, 3, 0});
      slog::Relation* readrel899 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index858 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({1, 2, 0});
      slog::Relation* readrel901 = db->getRelation("app");
      appindex859 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({1, 2, 0});
      slog::Relation* readrel903 = db->getRelation("eval_args");
      eval_argsindex860 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({0, 2, 1});
      slog::Relation* readrel905 = db->getRelation("eval");
      evalindex861 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({0, 1, 2});
      slog::Relation* readrel907 = db->getRelation("app");
      appindex862 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({0, 1, 2});
      slog::Relation* readrel909 = db->getRelation("app");
      appdelta873 = readrel909->getIndex(ord908, true);
      std::vector<u16> ord910({1, 2, 0});
      slog::Relation* readrel911 = db->getRelation("tick");
      tickindex863 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({1, 2, 0});
      slog::Relation* readrel913 = db->getRelation("eval_args");
      eval_argsindex864 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 2, 0});
      slog::Relation* readrel915 = db->getRelation("eval_args");
      eval_argsdelta874 = readrel915->getIndex(ord914, true);
      std::vector<u16> ord916({0, 1});
      slog::Relation* readrel917 = db->getRelation("eval_args_ans");
      eval_args_ansindex865 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 2, 0});
      slog::Relation* readrel919 = db->getRelation("tick");
      tickindex866 = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({1, 2, 0});
      slog::Relation* readrel921 = db->getRelation("tick");
      tickdelta875 = readrel921->getIndex(ord920, true);
      std::vector<u16> ord922({0, 1});
      slog::Relation* readrel923 = db->getRelation("tick_ans");
      tick_ansindex867 = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({0, 1});
      slog::Relation* readrel925 = db->getRelation("eval_args_ans");
      eval_args_ansindex868 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({0, 1});
      slog::Relation* readrel927 = db->getRelation("tick_ans");
      tick_ansindex869 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 2, 0});
      slog::Relation* readrel929 = db->getRelation("eval");
      evalindex870 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 2, 0});
      slog::Relation* readrel931 = db->getRelation("eval");
      evaldelta876 = readrel931->getIndex(ord930, true);
      std::vector<u16> ord932({0, 1});
      slog::Relation* readrel933 = db->getRelation("eval_ans");
      eval_ansindex871 = readrel933->getIndex(ord932, false);
  
    }
    ReadTask877(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c188 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c22 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex850, std::array<u64,3>{v_c22, 0, 0})) return;
        slog::join_probe_old<3,1>(closureindex851, closuredelta872, std::array<u64,3>{v_c188, 0, 0}, [&](const std::array<u64,3>& m934) {
          u64 v_c52 = m934[1]; u64 v_c189 = m934[2];
          slog::join_probe<2,1>(eval_ansindex852, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m935) {
            u64 v_c190 = m935[1];
            slog::join_probe<3,1>(evalindex853, std::array<u64,3>{v_c190, 0, 0}, [&](const std::array<u64,3>& m936) {
              u64 v_c17 = m936[1]; u64 v_c42 = m936[2];
              if (!slog::exists_probe<3,1>(evalindex854, std::array<u64,3>{v_c17, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex855, std::array<u64,3>{v_c42, 0, 0})) return;
              if (!slog::exists_probe<3,1>(eval_argsindex856, std::array<u64,3>{v_c17, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex857, std::array<u64,3>{v_c17, 0, 0})) return;
              slog::join_probe<4,2>($sup56712x41x0x0x0index858, std::array<u64,4>{v_c17, v_c42, 0, 0}, [&](const std::array<u64,4>& m937) {
                u64 v_c43 = m937[2]; u64 v_c191 = m937[3];
                if (!slog::exists_probe<3,2>(appindex859, std::array<u64,3>{v_c42, v_c43, 0})) return;
                if (!slog::exists_probe<3,2>(eval_argsindex860, std::array<u64,3>{v_c43, v_c17, 0})) return;
                slog::join_probe<3,2>(evalindex861, std::array<u64,3>{v_c191, v_c17, 0}, [&](const std::array<u64,3>& m938) {
                  u64 v_c192 = m938[2];
                  slog::join_probe_old<3,3>(appindex862, appdelta873, std::array<u64,3>{v_c192, v_c42, v_c43}, [&](const std::array<u64,3>& m939) {
                    if (!slog::exists_probe<3,2>(tickindex863, std::array<u64,3>{v_c192, v_c17, 0})) return;
                    slog::join_probe_old<3,2>(eval_argsindex864, eval_argsdelta874, std::array<u64,3>{v_c43, v_c17, 0}, [&](const std::array<u64,3>& m940) {
                      u64 v_c193 = m940[2];
                      if (!slog::exists_probe<2,1>(eval_args_ansindex865, std::array<u64,2>{v_c193, 0})) return;
                      slog::join_probe_old<3,2>(tickindex866, tickdelta875, std::array<u64,3>{v_c192, v_c17, 0}, [&](const std::array<u64,3>& m941) {
                        u64 v_c194 = m941[2];
                        if (!slog::exists_probe<2,1>(tick_ansindex867, std::array<u64,2>{v_c194, 0})) return;
                        slog::join_probe<2,1>(eval_args_ansindex868, std::array<u64,2>{v_c193, 0}, [&](const std::array<u64,2>& m942) {
                          u64 v_c49 = m942[1];
                          slog::join_probe<2,1>(tick_ansindex869, std::array<u64,2>{v_c194, 0}, [&](const std::array<u64,2>& m943) {
                            u64 v_c50 = m943[1];
                            slog::join_probe_old<3,2>(evalindex870, evaldelta876, std::array<u64,3>{v_c22, v_c50, 0}, [&](const std::array<u64,3>& m944) {
                              u64 v_c195 = m944[2];
                              slog::join_probe<2,1>(eval_ansindex871, std::array<u64,2>{v_c195, 0}, [&](const std::array<u64,2>& m945) {
                                u64 v_c136 = m945[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c191, v_c136}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask877* _cont = new ReadTask877(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask877(db,b), false);
  // (crule (pre) (scan if __t2oCE346 e1 e2 e3) (body (join freevar (1 0) 1 e1 x)) (head (emit freevar (0 1) x __t2oCE346)) freevars.slog:17 #f)
  class ReadTask947 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex946;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord948({0, 1});
      slog::Relation* readrel949 = db->getRelation("freevar");
      head_index[0] = readrel949->getIndex(ord948, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord950({1, 0});
      slog::Relation* readrel951 = db->getRelation("freevar");
      freevarindex946 = readrel951->getIndex(ord950, false);
  
    }
    ReadTask947(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c196 = _t[0];
        u64 v_c88 = _t[1];
        u64 v_c89 = _t[2];
        u64 v_c90 = _t[3];
        slog::join_probe<2,1>(freevarindex946, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m952) {
          u64 v_c21 = m952[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c196}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:if", _fires);
  
      if (!_done)
      {
        ReadTask947* _cont = new ReadTask947(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask947(db,b), false);
  // (crule (pre) (scan binding x c v) (body (join-old lookup (1 2 0) 2 (1 2 0) x c __t82W616)) (head (emit lookup_ans (0 1) __t82W616 v)) interp.slog:32 #f)
  class ReadTask955 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex953;  slog::Index** lookupdelta954;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup_ans");
      std::vector<u16> ord956({0, 1});
      slog::Relation* readrel957 = db->getRelation("lookup_ans");
      head_index[0] = readrel957->getIndex(ord956, false);
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord958({1, 2, 0});
      slog::Relation* readrel959 = db->getRelation("lookup");
      lookupindex953 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({1, 2, 0});
      slog::Relation* readrel961 = db->getRelation("lookup");
      lookupdelta954 = readrel961->getIndex(ord960, true);
  
    }
    ReadTask955(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c136 = _t[2];
        slog::join_probe_old<3,2>(lookupindex953, lookupdelta954, std::array<u64,3>{v_c21, v_c17, 0}, [&](const std::array<u64,3>& m962) {
          u64 v_c197 = m962[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c197, v_c136}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:32", "delta:binding", _fires);
  
      if (!_done)
      {
        ReadTask955* _cont = new ReadTask955(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask955(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre7xN6809 __errf7Uju810 __errf5ZEQ811 __errf6NuN812 __errf7Hrx813) (body) (head (emit error (0) __erre7xN6809)) <internal>:1 #f)
  class ReadTask963 : public slog::Task
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
      std::vector<u16> ord964({0});
      slog::Relation* readrel965 = db->getRelation("error");
      head_index[0] = readrel965->getIndex(ord964, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask963(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c198 = _t[0];
        u64 v_c199 = _t[1];
        u64 v_c200 = _t[2];
        u64 v_c201 = _t[3];
        u64 v_c202 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c198}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask963* _cont = new ReadTask963(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask963(db,b), false);
  // (crule (pre) (scan freevar x eb) (body (join letrec (3 0 1 2) 1 eb __t9Upp147 y er) (neq x y)) (head (emit freevar (0 1) x __t9Upp147)) freevars.slog:24 #f)
  class ReadTask967 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex966;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord968({0, 1});
      slog::Relation* readrel969 = db->getRelation("freevar");
      head_index[0] = readrel969->getIndex(ord968, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord970({3, 0, 1, 2});
      slog::Relation* readrel971 = db->getRelation("letrec");
      letrecindex966 = readrel971->getIndex(ord970, false);
  
    }
    ReadTask967(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        slog::join_probe<4,1>(letrecindex966, std::array<u64,4>{v_c22, 0, 0, 0}, [&](const std::array<u64,4>& m972) {
          u64 v_c203 = m972[1]; u64 v_c160 = m972[2]; u64 v_c18 = m972[3];
          if (v_c21 == v_c160) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c203}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:24", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask967* _cont = new ReadTask967(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask967(db,b), false);
  // (crule (pre) (scan lambda __t0Osl187 xs eb) (body (join freevar (1 0) 1 __t0Osl187 y) (join binding (0 1 2) 1 y cb vy) (join eval (0 2 1) 0 __2wtW609 c __t5Orx186) (join app (0 1 2) 1 __t5Orx186 ef es)) (head (mkstruct tick (1 2 0) __4U5c610 __t5Orx186 c)) interp.slog:56 #f)
  class ReadTask977 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex973;  slog::Index** bindingindex974;  slog::Index** evalindex975;  slog::Index** appindex976;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord978({1, 0});
      slog::Relation* readrel979 = db->getRelation("freevar");
      freevarindex973 = readrel979->getIndex(ord978, false);
      std::vector<u16> ord980({0, 1, 2});
      slog::Relation* readrel981 = db->getRelation("binding");
      bindingindex974 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({0, 2, 1});
      slog::Relation* readrel983 = db->getRelation("eval");
      evalindex975 = readrel983->getIndex(ord982, false);
      std::vector<u16> ord984({0, 1, 2});
      slog::Relation* readrel985 = db->getRelation("app");
      appindex976 = readrel985->getIndex(ord984, false);
  
    }
    ReadTask977(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c161 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c22 = _t[2];
        slog::join_probe<2,1>(freevarindex973, std::array<u64,2>{v_c161, 0}, [&](const std::array<u64,2>& m986) {
          u64 v_c160 = m986[1];
          slog::join_probe<3,1>(bindingindex974, std::array<u64,3>{v_c160, 0, 0}, [&](const std::array<u64,3>& m987) {
            u64 v_c52 = m987[1]; u64 v_c162 = m987[2];
            slog::join_all<3>(evalindex975, [&](const std::array<u64,3>& m988) {
              u64 v_c159 = m988[0]; u64 v_c17 = m988[1]; u64 v_c158 = m988[2];
              slog::join_probe<3,1>(appindex976, std::array<u64,3>{v_c158, 0, 0}, [&](const std::array<u64,3>& m989) {
                u64 v_c42 = m989[1]; u64 v_c43 = m989[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c158, v_c17}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask977* _cont = new ReadTask977(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask977(db,b), false);
  // (crule (pre) (scan freevar x e1) (body (join-old if (1 0 2 3) 1 (1 0 2 3) e1 __t2oCE346 e2 e3)) (head (emit freevar (0 1) x __t2oCE346)) freevars.slog:17 #f)
  class ReadTask992 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex990;  slog::Index** ifdelta991;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord993({0, 1});
      slog::Relation* readrel994 = db->getRelation("freevar");
      head_index[0] = readrel994->getIndex(ord993, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord995({1, 0, 2, 3});
      slog::Relation* readrel996 = db->getRelation("if");
      ifindex990 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 0, 2, 3});
      slog::Relation* readrel998 = db->getRelation("if");
      ifdelta991 = readrel998->getIndex(ord997, true);
  
    }
    ReadTask992(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[0];
        u64 v_c88 = _t[1];
        slog::join_probe_old<4,1>(ifindex990, ifdelta991, std::array<u64,4>{v_c88, 0, 0, 0}, [&](const std::array<u64,4>& m999) {
          u64 v_c196 = m999[1]; u64 v_c89 = m999[2]; u64 v_c90 = m999[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c196}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask992* _cont = new ReadTask992(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask992(db,b), false);
  // (crule (pre) (scan eval __4EnN698 __t1kar129 c) (body (join-old let (0 2 1 3) 1 (0 2 1 3) __t1kar129 er x eb)) (head (mkstruct eval (1 2 0) __8Q4o699 er c)) interp.slog:93 #f)
  class ReadTask1002 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1000;  slog::Index** letdelta1001;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1003({0, 2, 1, 3});
      slog::Relation* readrel1004 = db->getRelation("let");
      letindex1000 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({0, 2, 1, 3});
      slog::Relation* readrel1006 = db->getRelation("let");
      letdelta1001 = readrel1006->getIndex(ord1005, true);
  
    }
    ReadTask1002(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c204 = _t[0];
        u64 v_c205 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe_old<4,1>(letindex1000, letdelta1001, std::array<u64,4>{v_c205, 0, 0, 0}, [&](const std::array<u64,4>& m1007) {
          u64 v_c18 = m1007[1]; u64 v_c21 = m1007[2]; u64 v_c22 = m1007[3];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c18, v_c17}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1002* _cont = new ReadTask1002(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1002(db,b), false);
  // (crule (pre (let __tconst2Qtx688 const0122baa3ac55f1b433944eb1)) (scan temp0a5K990 __t2pLy138) (body (join _enum (1 0) 1 __tconst2Qtx688 __t67wA135) (join boolval (1 0) 1 __t67wA135 __t5iPS136)) (head (emit delta_ans (0 1) __t2pLy138 __t5iPS136)) interp.slog:113 #f)
  class ReadTask1010 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1008;  slog::Index** boolvalindex1009;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1011({0, 1});
      slog::Relation* readrel1012 = db->getRelation("delta_ans");
      head_index[0] = readrel1012->getIndex(ord1011, false);
      outer_rel = db->getRelation("temp0a5K990");
      std::vector<u16> ord1013({1, 0});
      slog::Relation* readrel1014 = db->getRelation("_enum");
      _enumindex1008 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({1, 0});
      slog::Relation* readrel1016 = db->getRelation("boolval");
      boolvalindex1009 = readrel1016->getIndex(ord1015, false);
  
    }
    ReadTask1010(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c206 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c207 = _t[0];
        slog::join_probe<2,1>(_enumindex1008, std::array<u64,2>{v_c206, 0}, [&](const std::array<u64,2>& m1017) {
          u64 v_c208 = m1017[1];
          slog::join_probe<2,1>(boolvalindex1009, std::array<u64,2>{v_c208, 0}, [&](const std::array<u64,2>& m1018) {
            u64 v_c209 = m1018[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c207, v_c209}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:113", "delta:temp0a5K990", _fires);
  
      if (!_done)
      {
        ReadTask1010* _cont = new ReadTask1010(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1010(db,b), false);
  // (crule (pre) (scan lookup __t7u4837 x c) (body (join primitive (0) 1 x)) (head (emit-temp temp6hC5862 __t7u4837 x) (mkstruct prim (1 0) __t7M6E36 x)) interp.slog:33 #f)
  class ReadTask1020 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primitiveindex1019;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6hC5862");
      head_rel[1] = db->getRelation("prim");
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord1021({0});
      slog::Relation* readrel1022 = db->getRelation("primitive");
      primitiveindex1019 = readrel1022->getIndex(ord1021, false);
  
    }
    ReadTask1020(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c17 = _t[2];
        slog::join_probe<1,1>(primitiveindex1019, std::array<u64,1>{v_c21}, [&](const std::array<u64,1>& m1023) {
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c210, v_c21});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c21}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:33", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask1020* _cont = new ReadTask1020(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1020(db,b), false);
}

