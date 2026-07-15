
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const0fc34686741291b4dd06511b;
extern u64 v_const20c400557af0eddc0be4d9e0;
extern u64 v_const2d53b3c21fa5cc786ac46d72;
extern u64 v_const342a69eb5a93251c8b7e179a;
extern u64 v_const37664d5895f78758ec8e94e4;
extern u64 v_const39c6f8839ca547fa7b7a32c4;
extern u64 v_const46a3ae93aa7a8b988080d6c9;
extern u64 v_const5d1d34d1b1718cd7c9f1ee55;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const609d51837c7fc306b0cbb04a;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const889c19fd926bc4ca61c0b4d9;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_consta81ad7556291f9defc5163ec;
extern u64 v_constaee3d30407ccfb32dbb15266;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constc100f95c1913f9c72fc1f4ef;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_conste403ffb5ff0078a3e3c6bcc7;
extern u64 v_conste6c67f7247161354cd7e1d34;
extern u64 v_conste7f6c011776e8db7cd330b54;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_consteefaed435882b14b69e99d78;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;
extern u64 v_constf6cdc3db4b71e0cdeda6912e;


void slog_rules_cc1fa06f2e1d0c40c(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan lookup __t5YK333 x c) (body (exists ref (1 0) 1 x) (exists eval (2 0 1) 1 c) (join lookup_ans (0 1) 1 __t5YK333 __v0) (join ref (1 0) 1 x __t8y8931) (join eval (1 2 0) 2 __t8y8931 c __t0HZY32)) (head (emit eval_ans (0 1) __t0HZY32 __v0)) interp.slog:30 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex0;  slog::Index** evalindex1;  slog::Index** lookup_ansindex2;  slog::Index** refindex3;  slog::Index** evalindex4;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord6({0, 1});
      slog::Relation* readrel7 = db->getRelation("eval_ans");
      head_index[0] = readrel7->getIndex(ord6, false);
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord8({1, 0});
      slog::Relation* readrel9 = db->getRelation("ref");
      refindex0 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({2, 0, 1});
      slog::Relation* readrel11 = db->getRelation("eval");
      evalindex1 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("lookup_ans");
      lookup_ansindex2 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("ref");
      refindex3 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 2, 0});
      slog::Relation* readrel17 = db->getRelation("eval");
      evalindex4 = readrel17->getIndex(ord16, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(refindex0, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(lookup_ansindex2, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m18) {
          u64 v_c3 = m18[1];
          slog::join_probe<2,1>(refindex3, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m19) {
            u64 v_c4 = m19[1];
            slog::join_probe<3,2>(evalindex4, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m20) {
              u64 v_c5 = m20[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c3}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:lookup", _fires);
  
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
  // (crule (pre (let __tconst9IXP677 constcd2a69ce5ca278db1d6da969) (let __tconst51tI19 const06abaa100ecef791ce028c56) (let _00024sqc4T4Y544 constd4735e3a265e16eee03f5971) (let _00024sqc7lRr545 const5feceb66ffc86f38d952786c) (let _00024sqc1s5u546 const6b86b273ff34fce19d6b804e) (let _00024sqo831x547 const5feceb66ffc86f38d952786c) (let _00024sqo8QLE548 const6b86b273ff34fce19d6b804e) (let _00024sqo7qSx549 const6b86b273ff34fce19d6b804e) (let _00024sqo2F2K550 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo2F2K550 __t1v1r22 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo831x547 __t1v1r22 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo8QLE548 __t1v1r22 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo7qSx549 __t1v1r22 _00024seq2) (join _enum (0 1) 2 __t1v1r22 __tconst9IXP677) (join delta (1 2 0) 2 __tconst51tI19 _00024seq2 __t4bAF20) (join any_bool (0) 0 b) (letp _00024sql3fFG542 (aslst _00024seq2)) (let chk80jZ1046 (llen _00024sql3fFG542)) (eq _00024sqc4T4Y544 chk80jZ1046) (letp chk05ZT1047 (lref _00024sql3fFG542 _00024sqc7lRr545)) (eq __t1v1r22 chk05ZT1047) (letp chk804O1048 (lref _00024sql3fFG542 _00024sqc1s5u546)) (eq __t1v1r22 chk804O1048)) (head (emit-temp temp46yO1034 __t4bAF20 b) (mkstruct boolval (1 0) __t6st618 b)) interp.slog:121 #f)
  class ReadTask27 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex21;  slog::Index** $seq_atindex22;  slog::Index** $seq_atrindex23;  slog::Index** _enumindex24;  slog::Index** deltaindex25;  slog::Index** any_boolindex26;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp46yO1034");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord28({1, 0, 2});
      slog::Relation* readrel29 = db->getRelation("$seq_atr");
      driver_index = readrel29->getIndex(ord28, true);
      std::vector<u16> ord30({1, 0, 2});
      slog::Relation* readrel31 = db->getRelation("$seq_at");
      $seq_atindex21 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 0, 2});
      slog::Relation* readrel33 = db->getRelation("$seq_at");
      $seq_atindex22 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 0, 2});
      slog::Relation* readrel35 = db->getRelation("$seq_atr");
      $seq_atrindex23 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({0, 1});
      slog::Relation* readrel37 = db->getRelation("_enum");
      _enumindex24 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 2, 0});
      slog::Relation* readrel39 = db->getRelation("delta");
      deltaindex25 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({0});
      slog::Relation* readrel41 = db->getRelation("any_bool");
      any_boolindex26 = readrel41->getIndex(ord40, false);
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c7 = v_const06abaa100ecef791ce028c56;
      u64 v_c8 = v_constd4735e3a265e16eee03f5971;
      u64 v_c9 = v_const5feceb66ffc86f38d952786c;
      u64 v_c10 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c11 = v_const5feceb66ffc86f38d952786c;
      u64 v_c12 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c13 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c14 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c14, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m42) {
        u64 v_c15 = m42[1];
        u64 v_c16 = m42[2];
        if (buckethash(v_c15) != bucket) return;
        slog::join_probe<3,3>($seq_atindex21, std::array<u64,3>{v_c11, v_c15, v_c16}, [&](const std::array<u64,3>& m43) {
          slog::join_probe<3,3>($seq_atindex22, std::array<u64,3>{v_c12, v_c15, v_c16}, [&](const std::array<u64,3>& m44) {
            slog::join_probe<3,3>($seq_atrindex23, std::array<u64,3>{v_c13, v_c15, v_c16}, [&](const std::array<u64,3>& m45) {
              slog::join_probe<2,2>(_enumindex24, std::array<u64,2>{v_c15, v_c6}, [&](const std::array<u64,2>& m46) {
                slog::join_probe<3,2>(deltaindex25, std::array<u64,3>{v_c7, v_c16, 0}, [&](const std::array<u64,3>& m47) {
                  u64 v_c17 = m47[2];
                  slog::join_all<1>(any_boolindex26, [&](const std::array<u64,1>& m48) {
                    u64 v_c18 = m48[0];
                    bool ok49 = true;
                    u64 v_c19 = _prim_aslst(db, v_c16, &ok49);
                    if (!ok49) return;
                    u64 v_c20 = _prim_llen(db, v_c19);
                    if (v_c20 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c8 != v_c20) return;
                    bool ok50 = true;
                    u64 v_c21 = _prim_lref(db, v_c19, v_c9, &ok50);
                    if (!ok50) return;
                    if (v_c15 != v_c21) return;
                    bool ok51 = true;
                    u64 v_c22 = _prim_lref(db, v_c19, v_c10, &ok51);
                    if (!ok51) return;
                    if (v_c15 != v_c22) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c17, v_c18});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask27* _cont = new ReadTask27(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask27(db,b), false);
  // (crule (pre (let __tconst3F1g329 conste7f6c011776e8db7cd330b54) (let __tconst3nEA343 const0933fb667296882d8c45abca) (let __tconst0pCN356 consted725292f5f32d61535958c1) (let __tconst88d3359 const6b86b273ff34fce19d6b804e) (let __tconst2t4L361 const5feceb66ffc86f38d952786c) (let __tconst8nL2368 const90fb9068eda6f2d68bb61c33) (let __tconst2LxS372 const46a3ae93aa7a8b988080d6c9) (let __tconst3Nin376 consta81ad7556291f9defc5163ec)) (scan temp1EpF1108 __t6UsA373) (body (exists num (1 0) 1 __tconst2t4L361) (exists ref (1 0) 1 __tconst0pCN356) (exists ref (1 0) 1 __tconst3nEA343) (exists ref (1 0) 1 __tconst2LxS372) (exists num (1 0) 1 __tconst88d3359) (exists ref (1 0) 1 __tconst3Nin376) (exists num (1 0) 1 __tconst3F1g329) (join ref (1 0) 1 __tconst8nL2368 __t5g5j369) (join num (1 0) 1 __tconst2t4L361 __t9AJk362) (join ref (1 0) 1 __tconst0pCN356 __t56Hj357) (join ref (1 0) 1 __tconst3nEA343 __t85N1344) (join ref (1 0) 1 __tconst2LxS372 __t62US339) (join num (1 0) 1 __tconst88d3359 __t29aP337) (join ref (1 0) 1 __tconst3Nin376 __t7cCj334) (join num (1 0) 1 __tconst3F1g329 __t3dLQ330) (let __t0Kjq332 (lpush __t6UsA373 __t3dLQ330)) (let __t2xne366 (lpush __t6UsA373 __t62US339)) (let __t4CVz374 (lpush __t6UsA373 __tconst2LxS372))) (head (emit-temp temp7tzo1109 __t0Kjq332 __t2xne366 __t4CVz374 __t6UsA373)) schemecfa.slog:12 #f)
  class ReadTask67 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex52;  slog::Index** refindex53;  slog::Index** refindex54;  slog::Index** refindex55;  slog::Index** numindex56;  slog::Index** refindex57;  slog::Index** numindex58;  slog::Index** refindex59;  slog::Index** numindex60;  slog::Index** refindex61;  slog::Index** refindex62;  slog::Index** refindex63;  slog::Index** numindex64;  slog::Index** refindex65;  slog::Index** numindex66;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7tzo1109");
      outer_rel = db->getRelation("temp1EpF1108");
      std::vector<u16> ord68({1, 0});
      slog::Relation* readrel69 = db->getRelation("num");
      numindex52 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 0});
      slog::Relation* readrel71 = db->getRelation("ref");
      refindex53 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 0});
      slog::Relation* readrel73 = db->getRelation("ref");
      refindex54 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({1, 0});
      slog::Relation* readrel75 = db->getRelation("ref");
      refindex55 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 0});
      slog::Relation* readrel77 = db->getRelation("num");
      numindex56 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 0});
      slog::Relation* readrel79 = db->getRelation("ref");
      refindex57 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 0});
      slog::Relation* readrel81 = db->getRelation("num");
      numindex58 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 0});
      slog::Relation* readrel83 = db->getRelation("ref");
      refindex59 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 0});
      slog::Relation* readrel85 = db->getRelation("num");
      numindex60 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 0});
      slog::Relation* readrel87 = db->getRelation("ref");
      refindex61 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 0});
      slog::Relation* readrel89 = db->getRelation("ref");
      refindex62 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 0});
      slog::Relation* readrel91 = db->getRelation("ref");
      refindex63 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 0});
      slog::Relation* readrel93 = db->getRelation("num");
      numindex64 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0});
      slog::Relation* readrel95 = db->getRelation("ref");
      refindex65 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 0});
      slog::Relation* readrel97 = db->getRelation("num");
      numindex66 = readrel97->getIndex(ord96, false);
  
    }
    ReadTask67(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c24 = v_const0933fb667296882d8c45abca;
      u64 v_c25 = v_consted725292f5f32d61535958c1;
      u64 v_c26 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
      u64 v_c28 = v_const90fb9068eda6f2d68bb61c33;
      u64 v_c29 = v_const46a3ae93aa7a8b988080d6c9;
      u64 v_c30 = v_consta81ad7556291f9defc5163ec;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c31 = _t[0];
        if (!slog::exists_probe<2,1>(numindex52, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(refindex53, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(refindex54, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(refindex55, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(numindex56, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(refindex57, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(numindex58, std::array<u64,2>{v_c23, 0})) return;
        slog::join_probe<2,1>(refindex59, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m98) {
          u64 v_c32 = m98[1];
          slog::join_probe<2,1>(numindex60, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m99) {
            u64 v_c33 = m99[1];
            slog::join_probe<2,1>(refindex61, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m100) {
              u64 v_c34 = m100[1];
              slog::join_probe<2,1>(refindex62, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m101) {
                u64 v_c35 = m101[1];
                slog::join_probe<2,1>(refindex63, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m102) {
                  u64 v_c36 = m102[1];
                  slog::join_probe<2,1>(numindex64, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m103) {
                    u64 v_c37 = m103[1];
                    slog::join_probe<2,1>(refindex65, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m104) {
                      u64 v_c38 = m104[1];
                      slog::join_probe<2,1>(numindex66, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m105) {
                        u64 v_c39 = m105[1];
                        u64 v_c40 = _prim_lpush(db, v_c31, v_c39);
                        if (v_c40 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:12"); return; }
                        u64 v_c41 = _prim_lpush(db, v_c31, v_c36);
                        if (v_c41 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:12"); return; }
                        u64 v_c42 = _prim_lpush(db, v_c31, v_c29);
                        if (v_c42 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:12"); return; }
                        ++_fires;
                        slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c40, v_c41, v_c42, v_c31});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp1EpF1108", _fires);
  
      if (!_done)
      {
        ReadTask67* _cont = new ReadTask67(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask67(db,b), false);
  // (crule (pre (let __tconst6GmF96 const5d1d34d1b1718cd7c9f1ee55) (let __tconst4uoq76 constaee3d30407ccfb32dbb15266) (let __tconst3NP861 const609d51837c7fc306b0cbb04a) (let __tconst12zL90 conste6c67f7247161354cd7e1d34) (let __tconst65HW45 const06abaa100ecef791ce028c56)) (scan temp03dt957 __t0AJB72 __t0XVv44 __t45Au84 __t8AJw94 __t8p2B57) (body (exists app (2 0 1) 1 __t0XVv44) (exists ref (1 0) 1 __tconst6GmF96) (exists ref (1 0) 1 __tconst12zL90) (exists app (2 0 1) 1 __t45Au84) (join ref (1 0) 1 __tconst65HW45 __t2luW46) (join app (1 2 0) 2 __t2luW46 __t0XVv44 __t5uOh47) (join ref (1 0) 1 __tconst6GmF96 __t8XG759) (join ref (1 0) 1 __tconst12zL90 __t4l0k86) (join app (1 2 0) 2 __t4l0k86 __t45Au84 __t0UL087)) (head (emit-temp temp1U5N958 __t0AJB72 __t0UL087 __t5uOh47 __t8AJw94 __t8p2B57) (mkstruct lambda (1 2 0) __t9Uwo95 __t8AJw94 __t0UL087) (mkstruct app (1 2 0) __t9J9k75 __t8XG759 __t0AJB72) (mkstruct app (1 2 0) __t1pzN60 __t8XG759 __t8p2B57)) schemecfa.slog:39 #f)
  class ReadTask115 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex106;  slog::Index** refindex107;  slog::Index** refindex108;  slog::Index** appindex109;  slog::Index** refindex110;  slog::Index** appindex111;  slog::Index** refindex112;  slog::Index** refindex113;  slog::Index** appindex114;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1U5N958");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("app");
      head_rel[3] = db->getRelation("app");
      outer_rel = db->getRelation("temp03dt957");
      std::vector<u16> ord116({2, 0, 1});
      slog::Relation* readrel117 = db->getRelation("app");
      appindex106 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 0});
      slog::Relation* readrel119 = db->getRelation("ref");
      refindex107 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 0});
      slog::Relation* readrel121 = db->getRelation("ref");
      refindex108 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({2, 0, 1});
      slog::Relation* readrel123 = db->getRelation("app");
      appindex109 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 0});
      slog::Relation* readrel125 = db->getRelation("ref");
      refindex110 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("app");
      appindex111 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 0});
      slog::Relation* readrel129 = db->getRelation("ref");
      refindex112 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("ref");
      refindex113 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("app");
      appindex114 = readrel133->getIndex(ord132, false);
  
    }
    ReadTask115(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const5d1d34d1b1718cd7c9f1ee55;
      u64 v_c44 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c45 = v_const609d51837c7fc306b0cbb04a;
      u64 v_c46 = v_conste6c67f7247161354cd7e1d34;
      u64 v_c47 = v_const06abaa100ecef791ce028c56;
  
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
        u64 v_c48 = _t[0];
        u64 v_c49 = _t[1];
        u64 v_c50 = _t[2];
        u64 v_c51 = _t[3];
        u64 v_c52 = _t[4];
        if (!slog::exists_probe<3,1>(appindex106, std::array<u64,3>{v_c49, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex107, std::array<u64,2>{v_c43, 0})) return;
        if (!slog::exists_probe<2,1>(refindex108, std::array<u64,2>{v_c46, 0})) return;
        if (!slog::exists_probe<3,1>(appindex109, std::array<u64,3>{v_c50, 0, 0})) return;
        slog::join_probe<2,1>(refindex110, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m134) {
          u64 v_c53 = m134[1];
          slog::join_probe<3,2>(appindex111, std::array<u64,3>{v_c53, v_c49, 0}, [&](const std::array<u64,3>& m135) {
            u64 v_c54 = m135[2];
            slog::join_probe<2,1>(refindex112, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m136) {
              u64 v_c55 = m136[1];
              slog::join_probe<2,1>(refindex113, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m137) {
                u64 v_c56 = m137[1];
                slog::join_probe<3,2>(appindex114, std::array<u64,3>{v_c56, v_c50, 0}, [&](const std::array<u64,3>& m138) {
                  u64 v_c57 = m138[2];
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c48, v_c57, v_c54, v_c51, v_c52});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c51, v_c57}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c55, v_c48}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c55, v_c52}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:39", "delta:temp03dt957", _fires);
  
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
  // (crule (pre (let __tconst6ZoU727 constb9e118781cea1f9fa01462e0)) (scan select_branch __t1G3m235 __t0HMR234 e2 e3) (body (join _enum (1 0) 1 __tconst6ZoU727 __t2nGP233) (join boolval (0 1) 2 __t0HMR234 __t2nGP233)) (head (emit select_branch_ans (0 1) __t1G3m235 e3)) interp.slog:84 #f)
  class ReadTask141 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex139;  slog::Index** boolvalindex140;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord142({0, 1});
      slog::Relation* readrel143 = db->getRelation("select_branch_ans");
      head_index[0] = readrel143->getIndex(ord142, false);
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord144({1, 0});
      slog::Relation* readrel145 = db->getRelation("_enum");
      _enumindex139 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 1});
      slog::Relation* readrel147 = db->getRelation("boolval");
      boolvalindex140 = readrel147->getIndex(ord146, false);
  
    }
    ReadTask141(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c58 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c59 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c61 = _t[2];
        u64 v_c62 = _t[3];
        slog::join_probe<2,1>(_enumindex139, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m148) {
          u64 v_c63 = m148[1];
          slog::join_probe<2,2>(boolvalindex140, std::array<u64,2>{v_c60, v_c63}, [&](const std::array<u64,2>& m149) {
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c59, v_c62}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:84", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask141* _cont = new ReadTask141(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask141(db,b), false);
  // (crule (pre (let __tconst69HS686 constcd2a69ce5ca278db1d6da969) (let _00024sqc0vxk654 constd4735e3a265e16eee03f5971) (let _00024sqc9Xix655 const5feceb66ffc86f38d952786c) (let _00024sqc63kA656 const6b86b273ff34fce19d6b804e) (let _00024sqo95lm657 const5feceb66ffc86f38d952786c) (let _00024sqo4EpM658 const6b86b273ff34fce19d6b804e) (let _00024sqo7bBz659 const6b86b273ff34fce19d6b804e) (let _00024sqo5IeL660 const5feceb66ffc86f38d952786c) (let __trid88QO687 consteefaed435882b14b69e99d78) (let __trel4WdJ688 constdede4476644eb06b5a48b866) (let __tcol9WTP689 const6b86b273ff34fce19d6b804e)) (scan delta __t3GFi99 op _00024seq2) (body (letp _00024sql4o3F652 (aslst _00024seq2)) (letp __t4TBU101 (lref _00024sql4o3F652 _00024sqc9Xix655)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo95lm657 __t4TBU101 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo4EpM658 __t4TBU101 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7bBz659 __t4TBU101 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5IeL660 __t4TBU101 _00024seq2) (join _enum (0 1) 2 __t4TBU101 __tconst69HS686) (join arithmetic_op (0) 1 op) (let chk9E1G1077 (llen _00024sql4o3F652)) (eq _00024sqc0vxk654 chk9E1G1077) (letp chk6eyQ1078 (lref _00024sql4o3F652 _00024sqc63kA656)) (eq __t4TBU101 chk6eyQ1078)) (head (tycheck __t4TBU101 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid88QO687 __trel4WdJ688 __tcol9WTP689 (1 2 3 4 0)) (emit delta_ans (0 1) __t3GFi99 __t4TBU101)) interp.slog:111 #f)
  class ReadTask165 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex150;  slog::Index** $seq_atindex151;  slog::Index** $seq_atrindex152;  slog::Index** $seq_atrindex153;  slog::Index** _enumindex154;  slog::Index** arithmetic_opindex155;  slog::Index** $seq_atdelta156;  slog::Index** $seq_atdelta157;  slog::Index** $seq_atrdelta158;  slog::Index** $seq_atrdelta159;
    u32 sid162;  u32 sid160;  u32 sid161;  u32 sid163;  u32 sid164;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord166({0, 1});
      slog::Relation* readrel167 = db->getRelation("delta_ans");
      head_index[1] = readrel167->getIndex(ord166, false);
      outer_rel = db->getRelation("delta");
      std::vector<u16> ord168({1, 0, 2});
      slog::Relation* readrel169 = db->getRelation("$seq_at");
      $seq_atindex150 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 0, 2});
      slog::Relation* readrel171 = db->getRelation("$seq_at");
      $seq_atdelta156 = readrel171->getIndex(ord170, true);
      std::vector<u16> ord172({1, 0, 2});
      slog::Relation* readrel173 = db->getRelation("$seq_at");
      $seq_atindex151 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({1, 0, 2});
      slog::Relation* readrel175 = db->getRelation("$seq_at");
      $seq_atdelta157 = readrel175->getIndex(ord174, true);
      std::vector<u16> ord176({1, 0, 2});
      slog::Relation* readrel177 = db->getRelation("$seq_atr");
      $seq_atrindex152 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 0, 2});
      slog::Relation* readrel179 = db->getRelation("$seq_atr");
      $seq_atrdelta158 = readrel179->getIndex(ord178, true);
      std::vector<u16> ord180({1, 0, 2});
      slog::Relation* readrel181 = db->getRelation("$seq_atr");
      $seq_atrindex153 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({1, 0, 2});
      slog::Relation* readrel183 = db->getRelation("$seq_atr");
      $seq_atrdelta159 = readrel183->getIndex(ord182, true);
      std::vector<u16> ord184({0, 1});
      slog::Relation* readrel185 = db->getRelation("_enum");
      _enumindex154 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({0});
      slog::Relation* readrel187 = db->getRelation("arithmetic_op");
      arithmetic_opindex155 = readrel187->getIndex(ord186, false);
      sid162 = db->getRelation("_enum")->getStructId();
      sid160 = db->getRelation("boolval")->getStructId();
      sid161 = db->getRelation("closure")->getStructId();
      sid163 = db->getRelation("prim")->getStructId();
      sid164 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask165(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c64 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c65 = v_constd4735e3a265e16eee03f5971;
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
      u64 v_c67 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_const5feceb66ffc86f38d952786c;
      u64 v_c72 = v_consteefaed435882b14b69e99d78;
      u64 v_c73 = v_constdede4476644eb06b5a48b866;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c75 = _t[0];
        u64 v_c76 = _t[1];
        u64 v_c16 = _t[2];
        bool ok188 = true;
        u64 v_c77 = _prim_aslst(db, v_c16, &ok188);
        if (!ok188) return;
        bool ok189 = true;
        u64 v_c78 = _prim_lref(db, v_c77, v_c66, &ok189);
        if (!ok189) return;
        slog::join_probe_old<3,3>($seq_atindex150, $seq_atdelta156, std::array<u64,3>{v_c68, v_c78, v_c16}, [&](const std::array<u64,3>& m190) {
          slog::join_probe_old<3,3>($seq_atindex151, $seq_atdelta157, std::array<u64,3>{v_c69, v_c78, v_c16}, [&](const std::array<u64,3>& m191) {
            slog::join_probe_old<3,3>($seq_atrindex152, $seq_atrdelta158, std::array<u64,3>{v_c70, v_c78, v_c16}, [&](const std::array<u64,3>& m192) {
              slog::join_probe_old<3,3>($seq_atrindex153, $seq_atrdelta159, std::array<u64,3>{v_c71, v_c78, v_c16}, [&](const std::array<u64,3>& m193) {
                slog::join_probe<2,2>(_enumindex154, std::array<u64,2>{v_c78, v_c64}, [&](const std::array<u64,2>& m194) {
                  slog::join_probe<1,1>(arithmetic_opindex155, std::array<u64,1>{v_c76}, [&](const std::array<u64,1>& m195) {
                    u64 v_c79 = _prim_llen(db, v_c77);
                    if (v_c79 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c65 != v_c79) return;
                    bool ok196 = true;
                    u64 v_c80 = _prim_lref(db, v_c77, v_c67, &ok196);
                    if (!ok196) return;
                    if (v_c78 != v_c80) return;
                    ++_fires;
                    if (!((is_struct(v_c78) && (decode_struct_id(v_c78) == sid160 || decode_struct_id(v_c78) == sid161 || decode_struct_id(v_c78) == sid162 || decode_struct_id(v_c78) == sid163 || decode_struct_id(v_c78) == sid164))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c72, v_c73, v_c74, v_c78}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c75, v_c78}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:111", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask165* _cont = new ReadTask165(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask165(db,b), false);
  // (crule (pre (let _00024sqc0arD528 const6b86b273ff34fce19d6b804e) (let _00024sqc2v5j529 const5feceb66ffc86f38d952786c) (let _00024sqc1rQJ530 const6b86b273ff34fce19d6b804e) (let _00024sqc2Mjs531 const5feceb66ffc86f38d952786c)) (scan argument_list _00024seq0) (body (letp _00024sql8ryR526 (aslst _00024seq0)) (let _00024sqn2uQm527 (llen _00024sql8ryR526)) (cmp ge _00024sqn2uQm527 _00024sqc0arD528) (letp e (lref _00024sql8ryR526 _00024sqc2v5j529)) (let _00024sqp3ubs532 (_0002d _00024sqn2uQm527 _00024sqc2Mjs531)) (let es (lslice _00024sql8ryR526 _00024sqc1rQJ530 _00024sqp3ubs532))) (head (emit argument_list (0) es)) freevars.slog:34 #f)
  class ReadTask197 : public slog::Task
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
      head_rel[0] = db->getRelation("argument_list");
      std::vector<u16> ord198({0});
      slog::Relation* readrel199 = db->getRelation("argument_list");
      head_index[0] = readrel199->getIndex(ord198, false);
      outer_rel = db->getRelation("argument_list");
  
    }
    ReadTask197(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c81 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c82 = v_const5feceb66ffc86f38d952786c;
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c84 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c85 = _t[0];
        bool ok200 = true;
        u64 v_c86 = _prim_aslst(db, v_c85, &ok200);
        if (!ok200) return;
        u64 v_c87 = _prim_llen(db, v_c86);
        if (v_c87 == slog_error) { slog::emit_pending_error(db, "freevars.slog:34"); return; }
        u64 v_c88 = _prim_ge(db, v_c87, v_c81);
        if (v_c88 == slog_error) { slog::emit_pending_error(db, "freevars.slog:34"); return; }
        if (!v_c88) return;
        bool ok202 = true;
        u64 v_c89 = _prim_lref(db, v_c86, v_c82, &ok202);
        if (!ok202) return;
        u64 v_c90 = _prim__0002d(db, v_c87, v_c84);
        if (v_c90 == slog_error) { slog::emit_pending_error(db, "freevars.slog:34"); return; }
        u64 v_c91 = _prim_lslice(db, v_c86, v_c83, v_c90);
        if (v_c91 == slog_error) { slog::emit_pending_error(db, "freevars.slog:34"); return; }
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c91}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:34", "delta:argument_list", _fires);
  
      if (!_done)
      {
        ReadTask197* _cont = new ReadTask197(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask197(db,b), false);
  // (crule (pre) (scan lambda __t0xip28 xs eb) (body (exists closure (1 2 0) 1 __t0xip28) (join freevar (1 0) 1 __t0xip28 y) (join binding (0 1 2) 1 y cb vy) (join closure (1 2 0) 2 __t0xip28 cb __t3Pto26) (join eval_ans (1 0) 1 __t3Pto26 __t5MCM24) (join eval (0 2 1) 1 __t5MCM24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __4cUN684 __t8j7u29) (exists tick (1 2 0) 2 __t8j7u29 c) (join-old app (0 1 2) 2 (0 1 2) __t8j7u29 ef es) (join eval_args (1 2 0) 2 es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (exists tick_ans (0 1) 1 __t0DSy30) (join eval_args_ans (0 1) 1 __t5BFX27 vs) (join tick_ans (0 1) 1 __t0DSy30 l)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask223 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex203;  slog::Index** freevarindex204;  slog::Index** bindingindex205;  slog::Index** closureindex206;  slog::Index** eval_ansindex207;  slog::Index** evalindex208;  slog::Index** appindex209;  slog::Index** eval_argsindex210;  slog::Index** tickindex211;  slog::Index** evalindex212;  slog::Index** tickindex213;  slog::Index** appindex214;  slog::Index** eval_argsindex215;  slog::Index** eval_args_ansindex216;  slog::Index** tickindex217;  slog::Index** tick_ansindex218;  slog::Index** eval_args_ansindex219;  slog::Index** tick_ansindex220;  slog::Index** appdelta221;  slog::Index** tickdelta222;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord224({0, 1, 2});
      slog::Relation* readrel225 = db->getRelation("binding");
      head_index[0] = readrel225->getIndex(ord224, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord226({0, 1, 2});
      slog::Relation* readrel227 = db->getRelation("binding_event");
      head_index[1] = readrel227->getIndex(ord226, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord228({1, 2, 0});
      slog::Relation* readrel229 = db->getRelation("closure");
      closureindex203 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("freevar");
      freevarindex204 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 1, 2});
      slog::Relation* readrel233 = db->getRelation("binding");
      bindingindex205 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 0});
      slog::Relation* readrel235 = db->getRelation("closure");
      closureindex206 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 0});
      slog::Relation* readrel237 = db->getRelation("eval_ans");
      eval_ansindex207 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({0, 2, 1});
      slog::Relation* readrel239 = db->getRelation("eval");
      evalindex208 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 2, 0});
      slog::Relation* readrel241 = db->getRelation("app");
      appindex209 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({2, 0, 1});
      slog::Relation* readrel243 = db->getRelation("eval_args");
      eval_argsindex210 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({2, 0, 1});
      slog::Relation* readrel245 = db->getRelation("tick");
      tickindex211 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({2, 0, 1});
      slog::Relation* readrel247 = db->getRelation("eval");
      evalindex212 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 2, 0});
      slog::Relation* readrel249 = db->getRelation("tick");
      tickindex213 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 1, 2});
      slog::Relation* readrel251 = db->getRelation("app");
      appindex214 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({0, 1, 2});
      slog::Relation* readrel253 = db->getRelation("app");
      appdelta221 = readrel253->getIndex(ord252, true);
      std::vector<u16> ord254({1, 2, 0});
      slog::Relation* readrel255 = db->getRelation("eval_args");
      eval_argsindex215 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({0, 1});
      slog::Relation* readrel257 = db->getRelation("eval_args_ans");
      eval_args_ansindex216 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 2, 0});
      slog::Relation* readrel259 = db->getRelation("tick");
      tickindex217 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 2, 0});
      slog::Relation* readrel261 = db->getRelation("tick");
      tickdelta222 = readrel261->getIndex(ord260, true);
      std::vector<u16> ord262({0, 1});
      slog::Relation* readrel263 = db->getRelation("tick_ans");
      tick_ansindex218 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({0, 1});
      slog::Relation* readrel265 = db->getRelation("eval_args_ans");
      eval_args_ansindex219 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({0, 1});
      slog::Relation* readrel267 = db->getRelation("tick_ans");
      tick_ansindex220 = readrel267->getIndex(ord266, false);
  
    }
    ReadTask223(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c93 = _t[1];
        u64 v_c94 = _t[2];
        if (!slog::exists_probe<3,1>(closureindex203, std::array<u64,3>{v_c92, 0, 0})) return;
        slog::join_probe<2,1>(freevarindex204, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m268) {
          u64 v_c95 = m268[1];
          slog::join_probe<3,1>(bindingindex205, std::array<u64,3>{v_c95, 0, 0}, [&](const std::array<u64,3>& m269) {
            u64 v_c96 = m269[1]; u64 v_c97 = m269[2];
            slog::join_probe<3,2>(closureindex206, std::array<u64,3>{v_c92, v_c96, 0}, [&](const std::array<u64,3>& m270) {
              u64 v_c98 = m270[2];
              slog::join_probe<2,1>(eval_ansindex207, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m271) {
                u64 v_c99 = m271[1];
                slog::join_probe<3,1>(evalindex208, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m272) {
                  u64 v_c2 = m272[1]; u64 v_c100 = m272[2];
                  if (!slog::exists_probe<3,1>(appindex209, std::array<u64,3>{v_c100, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(eval_argsindex210, std::array<u64,3>{v_c2, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(tickindex211, std::array<u64,3>{v_c2, 0, 0})) return;
                  slog::join_probe<3,1>(evalindex212, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m273) {
                    u64 v_c101 = m273[1]; u64 v_c102 = m273[2];
                    if (!slog::exists_probe<3,2>(tickindex213, std::array<u64,3>{v_c102, v_c2, 0})) return;
                    slog::join_probe_old<3,2>(appindex214, appdelta221, std::array<u64,3>{v_c102, v_c100, 0}, [&](const std::array<u64,3>& m274) {
                      u64 v_c91 = m274[2];
                      slog::join_probe<3,2>(eval_argsindex215, std::array<u64,3>{v_c91, v_c2, 0}, [&](const std::array<u64,3>& m275) {
                        u64 v_c103 = m275[2];
                        if (!slog::exists_probe<2,1>(eval_args_ansindex216, std::array<u64,2>{v_c103, 0})) return;
                        slog::join_probe_old<3,2>(tickindex217, tickdelta222, std::array<u64,3>{v_c102, v_c2, 0}, [&](const std::array<u64,3>& m276) {
                          u64 v_c104 = m276[2];
                          if (!slog::exists_probe<2,1>(tick_ansindex218, std::array<u64,2>{v_c104, 0})) return;
                          slog::join_probe<2,1>(eval_args_ansindex219, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m277) {
                            u64 v_c105 = m277[1];
                            slog::join_probe<2,1>(tick_ansindex220, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m278) {
                              u64 v_c106 = m278[1];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c95, v_c106, v_c97}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c95, v_c106, v_c2}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask223* _cont = new ReadTask223(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask223(db,b), false);
  // (crule (pre (let __tconst7knU761 const0122baa3ac55f1b433944eb1) (let __tconst35kI244 const06abaa100ecef791ce028c56) (let _00024sqc59yj663 constd4735e3a265e16eee03f5971) (let _00024sqc7n8w664 const5feceb66ffc86f38d952786c) (let _00024sqc4sLR665 const6b86b273ff34fce19d6b804e) (let _00024sqo8MNY666 const5feceb66ffc86f38d952786c) (let _00024sqo0NcP667 const6b86b273ff34fce19d6b804e) (let _00024sqo0X3t668 const6b86b273ff34fce19d6b804e) (let _00024sqo6VJl669 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo0NcP667 __t1b46247 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo8MNY666 __t1b46247 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0X3t668 __t1b46247 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo6VJl669 __t1b46247 _00024seq2) (exists _enum (1 0) 1 __tconst7knU761) (join delta (1 2 0) 2 __tconst35kI244 _00024seq2 __t7NfZ245) (join _enum (1 0) 1 __tconst7knU761 __t4Ufa242) (join boolval (0 1) 1 __t1b46247 b) (letp _00024sql4qXJ661 (aslst _00024seq2)) (let chk6f8y971 (llen _00024sql4qXJ661)) (eq _00024sqc59yj663 chk6f8y971) (letp chk5Pou972 (lref _00024sql4qXJ661 _00024sqc7n8w664)) (eq __t1b46247 chk5Pou972) (letp chk4Paj973 (lref _00024sql4qXJ661 _00024sqc4sLR665)) (eq __t1b46247 chk4Paj973)) (head (emit-temp temp3tnu962 __t7NfZ245) (mkstruct boolval (1 0) __t0oTa243 __t4Ufa242)) interp.slog:118 #f)
  class ReadTask288 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex279;  slog::Index** $seq_atrindex280;  slog::Index** $seq_atrindex281;  slog::Index** _enumindex282;  slog::Index** deltaindex283;  slog::Index** _enumindex284;  slog::Index** boolvalindex285;  slog::Index** $seq_atrdelta286;  slog::Index** $seq_atrdelta287;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3tnu962");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord289({1, 0, 2});
      slog::Relation* readrel290 = db->getRelation("$seq_at");
      driver_index = readrel290->getIndex(ord289, true);
      std::vector<u16> ord291({1, 0, 2});
      slog::Relation* readrel292 = db->getRelation("$seq_at");
      $seq_atindex279 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 0, 2});
      slog::Relation* readrel294 = db->getRelation("$seq_atr");
      $seq_atrindex280 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({1, 0, 2});
      slog::Relation* readrel296 = db->getRelation("$seq_atr");
      $seq_atrdelta286 = readrel296->getIndex(ord295, true);
      std::vector<u16> ord297({1, 0, 2});
      slog::Relation* readrel298 = db->getRelation("$seq_atr");
      $seq_atrindex281 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({1, 0, 2});
      slog::Relation* readrel300 = db->getRelation("$seq_atr");
      $seq_atrdelta287 = readrel300->getIndex(ord299, true);
      std::vector<u16> ord301({1, 0});
      slog::Relation* readrel302 = db->getRelation("_enum");
      _enumindex282 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({1, 2, 0});
      slog::Relation* readrel304 = db->getRelation("delta");
      deltaindex283 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({1, 0});
      slog::Relation* readrel306 = db->getRelation("_enum");
      _enumindex284 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({0, 1});
      slog::Relation* readrel308 = db->getRelation("boolval");
      boolvalindex285 = readrel308->getIndex(ord307, false);
  
    }
    ReadTask288(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c108 = v_const06abaa100ecef791ce028c56;
      u64 v_c109 = v_constd4735e3a265e16eee03f5971;
      u64 v_c110 = v_const5feceb66ffc86f38d952786c;
      u64 v_c111 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c112 = v_const5feceb66ffc86f38d952786c;
      u64 v_c113 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c114 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c113, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m309) {
        u64 v_c116 = m309[1];
        u64 v_c16 = m309[2];
        if (buckethash(v_c116) != bucket) return;
        slog::join_probe<3,3>($seq_atindex279, std::array<u64,3>{v_c112, v_c116, v_c16}, [&](const std::array<u64,3>& m310) {
          slog::join_probe_old<3,3>($seq_atrindex280, $seq_atrdelta286, std::array<u64,3>{v_c114, v_c116, v_c16}, [&](const std::array<u64,3>& m311) {
            slog::join_probe_old<3,3>($seq_atrindex281, $seq_atrdelta287, std::array<u64,3>{v_c115, v_c116, v_c16}, [&](const std::array<u64,3>& m312) {
              if (!slog::exists_probe<2,1>(_enumindex282, std::array<u64,2>{v_c107, 0})) return;
              slog::join_probe<3,2>(deltaindex283, std::array<u64,3>{v_c108, v_c16, 0}, [&](const std::array<u64,3>& m313) {
                u64 v_c117 = m313[2];
                slog::join_probe<2,1>(_enumindex284, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m314) {
                  u64 v_c118 = m314[1];
                  slog::join_probe<2,1>(boolvalindex285, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m315) {
                    u64 v_c18 = m315[1];
                    bool ok316 = true;
                    u64 v_c119 = _prim_aslst(db, v_c16, &ok316);
                    if (!ok316) return;
                    u64 v_c120 = _prim_llen(db, v_c119);
                    if (v_c120 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c109 != v_c120) return;
                    bool ok317 = true;
                    u64 v_c121 = _prim_lref(db, v_c119, v_c110, &ok317);
                    if (!ok317) return;
                    if (v_c116 != v_c121) return;
                    bool ok318 = true;
                    u64 v_c122 = _prim_lref(db, v_c119, v_c111, &ok318);
                    if (!ok318) return;
                    if (v_c116 != v_c122) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c117});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c118}, std::array<u16,2>{1, 0});
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
        ReadTask288* _cont = new ReadTask288(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask288(db,b), false);
  // (crule (pre (let __tconst04ab676 constcd2a69ce5ca278db1d6da969) (let _00024sqc0NDP645 constd4735e3a265e16eee03f5971) (let _00024sqc7bIa646 const5feceb66ffc86f38d952786c) (let _00024sqc1Uf7647 const6b86b273ff34fce19d6b804e) (let _00024sqo7IWL648 const5feceb66ffc86f38d952786c) (let _00024sqo5kNQ649 const6b86b273ff34fce19d6b804e) (let _00024sqo9k7p650 const6b86b273ff34fce19d6b804e) (let _00024sqo7Xo2651 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo9k7p650 __t2qlr318 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7IWL648 __t2qlr318 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo5kNQ649 __t2qlr318 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7Xo2651 __t2qlr318 _00024seq2) (join _enum (0 1) 2 __t2qlr318 __tconst04ab676) (join delta (2 0 1) 1 _00024seq2 __t6QsA316 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql2g05643 (aslst _00024seq2)) (let chk1Qyo1024 (llen _00024sql2g05643)) (eq _00024sqc0NDP645 chk1Qyo1024) (letp chk8yBS1025 (lref _00024sql2g05643 _00024sqc7bIa646)) (eq __t2qlr318 chk8yBS1025) (letp chk2j7Q1026 (lref _00024sql2g05643 _00024sqc1Uf7647)) (eq __t2qlr318 chk2j7Q1026)) (head (emit-temp temp53FS1015 __t6QsA316 b) (mkstruct boolval (1 0) __t3y4C315 b)) interp.slog:112 #f)
  class ReadTask327 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex319;  slog::Index** $seq_atindex320;  slog::Index** $seq_atrindex321;  slog::Index** _enumindex322;  slog::Index** deltaindex323;  slog::Index** comparison_opindex324;  slog::Index** any_boolindex325;  slog::Index** $seq_atrdelta326;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp53FS1015");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord328({1, 0, 2});
      slog::Relation* readrel329 = db->getRelation("$seq_atr");
      driver_index = readrel329->getIndex(ord328, true);
      std::vector<u16> ord330({1, 0, 2});
      slog::Relation* readrel331 = db->getRelation("$seq_at");
      $seq_atindex319 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 0, 2});
      slog::Relation* readrel333 = db->getRelation("$seq_at");
      $seq_atindex320 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 0, 2});
      slog::Relation* readrel335 = db->getRelation("$seq_atr");
      $seq_atrindex321 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 0, 2});
      slog::Relation* readrel337 = db->getRelation("$seq_atr");
      $seq_atrdelta326 = readrel337->getIndex(ord336, true);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("_enum");
      _enumindex322 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({2, 0, 1});
      slog::Relation* readrel341 = db->getRelation("delta");
      deltaindex323 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({0});
      slog::Relation* readrel343 = db->getRelation("comparison_op");
      comparison_opindex324 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({0});
      slog::Relation* readrel345 = db->getRelation("any_bool");
      any_boolindex325 = readrel345->getIndex(ord344, false);
  
    }
    ReadTask327(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c123 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c124 = v_constd4735e3a265e16eee03f5971;
      u64 v_c125 = v_const5feceb66ffc86f38d952786c;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const5feceb66ffc86f38d952786c;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c129, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m346) {
        u64 v_c131 = m346[1];
        u64 v_c16 = m346[2];
        if (buckethash(v_c131) != bucket) return;
        slog::join_probe<3,3>($seq_atindex319, std::array<u64,3>{v_c127, v_c131, v_c16}, [&](const std::array<u64,3>& m347) {
          slog::join_probe<3,3>($seq_atindex320, std::array<u64,3>{v_c128, v_c131, v_c16}, [&](const std::array<u64,3>& m348) {
            slog::join_probe_old<3,3>($seq_atrindex321, $seq_atrdelta326, std::array<u64,3>{v_c130, v_c131, v_c16}, [&](const std::array<u64,3>& m349) {
              slog::join_probe<2,2>(_enumindex322, std::array<u64,2>{v_c131, v_c123}, [&](const std::array<u64,2>& m350) {
                slog::join_probe<3,1>(deltaindex323, std::array<u64,3>{v_c16, 0, 0}, [&](const std::array<u64,3>& m351) {
                  u64 v_c132 = m351[1]; u64 v_c76 = m351[2];
                  slog::join_probe<1,1>(comparison_opindex324, std::array<u64,1>{v_c76}, [&](const std::array<u64,1>& m352) {
                    slog::join_all<1>(any_boolindex325, [&](const std::array<u64,1>& m353) {
                      u64 v_c18 = m353[0];
                      bool ok354 = true;
                      u64 v_c133 = _prim_aslst(db, v_c16, &ok354);
                      if (!ok354) return;
                      u64 v_c134 = _prim_llen(db, v_c133);
                      if (v_c134 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c124 != v_c134) return;
                      bool ok355 = true;
                      u64 v_c135 = _prim_lref(db, v_c133, v_c125, &ok355);
                      if (!ok355) return;
                      if (v_c131 != v_c135) return;
                      bool ok356 = true;
                      u64 v_c136 = _prim_lref(db, v_c133, v_c126, &ok356);
                      if (!ok356) return;
                      if (v_c131 != v_c136) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c132, v_c18});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:112", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask327* _cont = new ReadTask327(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask327(db,b), false);
  // (crule (pre) (scan eval_ans __t9B5D299 __t4ng7301) (body (join-old eval (0 2 1) 1 (0 2 1) __t9B5D299 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __7p9q702 __t7NtH303) (exists tick (1 2 0) 2 __t7NtH303 c) (join-old app (0 1 2) 2 (0 1 2) __t7NtH303 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6sYC302) (exists eval_args_ans (0 1) 1 __t6sYC302) (join-old tick (1 2 0) 2 (1 2 0) __t7NtH303 c __t5Pln304) (exists tick_ans (0 1) 1 __t5Pln304) (join-old eval_args_ans (0 1) 1 (0 1) __t6sYC302 vs) (join-old tick_ans (0 1) 1 (0 1) __t5Pln304 l) (join-old closure (0 1 2) 1 (0 1 2) __t4ng7301 __t4mHn300 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t4mHn300 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask380 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex357;  slog::Index** appindex358;  slog::Index** eval_argsindex359;  slog::Index** tickindex360;  slog::Index** evalindex361;  slog::Index** tickindex362;  slog::Index** appindex363;  slog::Index** eval_argsindex364;  slog::Index** eval_args_ansindex365;  slog::Index** tickindex366;  slog::Index** tick_ansindex367;  slog::Index** eval_args_ansindex368;  slog::Index** tick_ansindex369;  slog::Index** closureindex370;  slog::Index** lambdaindex371;  slog::Index** evaldelta372;  slog::Index** appdelta373;  slog::Index** eval_argsdelta374;  slog::Index** tickdelta375;  slog::Index** eval_args_ansdelta376;  slog::Index** tick_ansdelta377;  slog::Index** closuredelta378;  slog::Index** lambdadelta379;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord381({0, 1, 2, 3});
      slog::Relation* readrel382 = db->getRelation("bind_params");
      head_index[0] = readrel382->getIndex(ord381, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord383({0, 1});
      slog::Relation* readrel384 = db->getRelation("call_event");
      head_index[1] = readrel384->getIndex(ord383, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord385({0, 2, 1});
      slog::Relation* readrel386 = db->getRelation("eval");
      evalindex357 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({0, 2, 1});
      slog::Relation* readrel388 = db->getRelation("eval");
      evaldelta372 = readrel388->getIndex(ord387, true);
      std::vector<u16> ord389({1, 2, 0});
      slog::Relation* readrel390 = db->getRelation("app");
      appindex358 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({2, 0, 1});
      slog::Relation* readrel392 = db->getRelation("eval_args");
      eval_argsindex359 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({2, 0, 1});
      slog::Relation* readrel394 = db->getRelation("tick");
      tickindex360 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({2, 0, 1});
      slog::Relation* readrel396 = db->getRelation("eval");
      evalindex361 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({1, 2, 0});
      slog::Relation* readrel398 = db->getRelation("tick");
      tickindex362 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({0, 1, 2});
      slog::Relation* readrel400 = db->getRelation("app");
      appindex363 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({0, 1, 2});
      slog::Relation* readrel402 = db->getRelation("app");
      appdelta373 = readrel402->getIndex(ord401, true);
      std::vector<u16> ord403({1, 2, 0});
      slog::Relation* readrel404 = db->getRelation("eval_args");
      eval_argsindex364 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("eval_args");
      eval_argsdelta374 = readrel406->getIndex(ord405, true);
      std::vector<u16> ord407({0, 1});
      slog::Relation* readrel408 = db->getRelation("eval_args_ans");
      eval_args_ansindex365 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({1, 2, 0});
      slog::Relation* readrel410 = db->getRelation("tick");
      tickindex366 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 2, 0});
      slog::Relation* readrel412 = db->getRelation("tick");
      tickdelta375 = readrel412->getIndex(ord411, true);
      std::vector<u16> ord413({0, 1});
      slog::Relation* readrel414 = db->getRelation("tick_ans");
      tick_ansindex367 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({0, 1});
      slog::Relation* readrel416 = db->getRelation("eval_args_ans");
      eval_args_ansindex368 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({0, 1});
      slog::Relation* readrel418 = db->getRelation("eval_args_ans");
      eval_args_ansdelta376 = readrel418->getIndex(ord417, true);
      std::vector<u16> ord419({0, 1});
      slog::Relation* readrel420 = db->getRelation("tick_ans");
      tick_ansindex369 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({0, 1});
      slog::Relation* readrel422 = db->getRelation("tick_ans");
      tick_ansdelta377 = readrel422->getIndex(ord421, true);
      std::vector<u16> ord423({0, 1, 2});
      slog::Relation* readrel424 = db->getRelation("closure");
      closureindex370 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({0, 1, 2});
      slog::Relation* readrel426 = db->getRelation("closure");
      closuredelta378 = readrel426->getIndex(ord425, true);
      std::vector<u16> ord427({0, 1, 2});
      slog::Relation* readrel428 = db->getRelation("lambda");
      lambdaindex371 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({0, 1, 2});
      slog::Relation* readrel430 = db->getRelation("lambda");
      lambdadelta379 = readrel430->getIndex(ord429, true);
  
    }
    ReadTask380(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c137 = _t[0];
        u64 v_c138 = _t[1];
        slog::join_probe_old<3,1>(evalindex357, evaldelta372, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m431) {
          u64 v_c2 = m431[1]; u64 v_c100 = m431[2];
          if (!slog::exists_probe<3,1>(appindex358, std::array<u64,3>{v_c100, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex359, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex360, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe<3,1>(evalindex361, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m432) {
            u64 v_c139 = m432[1]; u64 v_c140 = m432[2];
            if (!slog::exists_probe<3,2>(tickindex362, std::array<u64,3>{v_c140, v_c2, 0})) return;
            slog::join_probe_old<3,2>(appindex363, appdelta373, std::array<u64,3>{v_c140, v_c100, 0}, [&](const std::array<u64,3>& m433) {
              u64 v_c91 = m433[2];
              slog::join_probe_old<3,2>(eval_argsindex364, eval_argsdelta374, std::array<u64,3>{v_c91, v_c2, 0}, [&](const std::array<u64,3>& m434) {
                u64 v_c141 = m434[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex365, std::array<u64,2>{v_c141, 0})) return;
                slog::join_probe_old<3,2>(tickindex366, tickdelta375, std::array<u64,3>{v_c140, v_c2, 0}, [&](const std::array<u64,3>& m435) {
                  u64 v_c142 = m435[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex367, std::array<u64,2>{v_c142, 0})) return;
                  slog::join_probe_old<2,1>(eval_args_ansindex368, eval_args_ansdelta376, std::array<u64,2>{v_c141, 0}, [&](const std::array<u64,2>& m436) {
                    u64 v_c105 = m436[1];
                    slog::join_probe_old<2,1>(tick_ansindex369, tick_ansdelta377, std::array<u64,2>{v_c142, 0}, [&](const std::array<u64,2>& m437) {
                      u64 v_c106 = m437[1];
                      slog::join_probe_old<3,1>(closureindex370, closuredelta378, std::array<u64,3>{v_c138, 0, 0}, [&](const std::array<u64,3>& m438) {
                        u64 v_c143 = m438[1]; u64 v_c96 = m438[2];
                        slog::join_probe_old<3,1>(lambdaindex371, lambdadelta379, std::array<u64,3>{v_c143, 0, 0}, [&](const std::array<u64,3>& m439) {
                          u64 v_c93 = m439[1]; u64 v_c94 = m439[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c93, v_c105, v_c106, v_c2}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c106, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask380* _cont = new ReadTask380(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask380(db,b), false);
  // (crule (pre (let _00024sqc8R4Y563 const5feceb66ffc86f38d952786c) (let __t00lI121 (lempty))) (scan eval_args __t06qS122 _00024seq0 c) (body (letp _00024sql4sCn561 (aslst _00024seq0)) (let chk7Oy51102 (llen _00024sql4sCn561)) (eq _00024sqc8R4Y563 chk7Oy51102)) (head (emit-temp temp8iMn1101 __t00lI121 __t06qS122)) interp.slog:37 #f)
  class ReadTask440 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8iMn1101");
      outer_rel = db->getRelation("eval_args");
  
    }
    ReadTask440(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c144 = v_const5feceb66ffc86f38d952786c;
      u64 v_c145 = _prim_lempty(db);
      if (v_c145 == slog_error) { slog::emit_pending_error(db, "interp.slog:37"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c146 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c2 = _t[2];
        bool ok441 = true;
        u64 v_c147 = _prim_aslst(db, v_c85, &ok441);
        if (!ok441) return;
        u64 v_c148 = _prim_llen(db, v_c147);
        if (v_c148 == slog_error) { slog::emit_pending_error(db, "interp.slog:37"); return; }
        if (v_c144 != v_c148) return;
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c145, v_c146});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:37", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask440* _cont = new ReadTask440(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask440(db,b), false);
  // (crule (pre (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9) (let __tconst5n8U262 const0933fb667296882d8c45abca) (let __tconst0jEK272 const37664d5895f78758ec8e94e4) (let __tconst3Rob283 const90fb9068eda6f2d68bb61c33)) (scan temp4bTi1051 __t2HAB274 __t4a9o251 __t6cev261 __t6dUB289 __t6t5b288 __t9Oif282) (body (exists ref (1 0) 1 __tconst0jEK272) (exists lambda (1 2 0) 1 __t2HAB274) (exists ref (1 0) 1 __tconst5n8U262) (exists ref (1 0) 1 __tconst4G37291) (exists app (2 0 1) 1 __t4a9o251) (join ref (1 0) 1 __tconst3Rob283 __t88QE284) (join ref (1 0) 1 __tconst0jEK272 __t42iX271) (join lambda (1 2 0) 2 __t2HAB274 __t42iX271 __t0vlN275) (join ref (1 0) 1 __tconst5n8U262 __t4C1l263) (join ref (1 0) 1 __tconst4G37291 __t8oYB253) (join app (1 2 0) 2 __t8oYB253 __t4a9o251 __t5GYK254)) (head (emit-temp temp3sak1052 __t0vlN275 __t5GYK254 __t6cev261 __t6dUB289 __t6t5b288 __t9Oif282) (mkstruct app (1 2 0) __t4piH264 __t4C1l263 __t6cev261) (mkstruct app (1 2 0) __t5TOH285 __t88QE284 __t9Oif282)) schemecfa.slog:70 #f)
  class ReadTask453 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex442;  slog::Index** lambdaindex443;  slog::Index** refindex444;  slog::Index** refindex445;  slog::Index** appindex446;  slog::Index** refindex447;  slog::Index** refindex448;  slog::Index** lambdaindex449;  slog::Index** refindex450;  slog::Index** refindex451;  slog::Index** appindex452;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3sak1052");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      outer_rel = db->getRelation("temp4bTi1051");
      std::vector<u16> ord454({1, 0});
      slog::Relation* readrel455 = db->getRelation("ref");
      refindex442 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 2, 0});
      slog::Relation* readrel457 = db->getRelation("lambda");
      lambdaindex443 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 0});
      slog::Relation* readrel459 = db->getRelation("ref");
      refindex444 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({1, 0});
      slog::Relation* readrel461 = db->getRelation("ref");
      refindex445 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({2, 0, 1});
      slog::Relation* readrel463 = db->getRelation("app");
      appindex446 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 0});
      slog::Relation* readrel465 = db->getRelation("ref");
      refindex447 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 0});
      slog::Relation* readrel467 = db->getRelation("ref");
      refindex448 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 0});
      slog::Relation* readrel469 = db->getRelation("lambda");
      lambdaindex449 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 0});
      slog::Relation* readrel471 = db->getRelation("ref");
      refindex450 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0});
      slog::Relation* readrel473 = db->getRelation("ref");
      refindex451 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("app");
      appindex452 = readrel475->getIndex(ord474, false);
  
    }
    ReadTask453(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_const889c19fd926bc4ca61c0b4d9;
      u64 v_c150 = v_const0933fb667296882d8c45abca;
      u64 v_c151 = v_const37664d5895f78758ec8e94e4;
      u64 v_c152 = v_const90fb9068eda6f2d68bb61c33;
  
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
        u64 v_c153 = _t[0];
        u64 v_c154 = _t[1];
        u64 v_c155 = _t[2];
        u64 v_c156 = _t[3];
        u64 v_c157 = _t[4];
        u64 v_c158 = _t[5];
        if (!slog::exists_probe<2,1>(refindex442, std::array<u64,2>{v_c151, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex443, std::array<u64,3>{v_c153, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex444, std::array<u64,2>{v_c150, 0})) return;
        if (!slog::exists_probe<2,1>(refindex445, std::array<u64,2>{v_c149, 0})) return;
        if (!slog::exists_probe<3,1>(appindex446, std::array<u64,3>{v_c154, 0, 0})) return;
        slog::join_probe<2,1>(refindex447, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m476) {
          u64 v_c159 = m476[1];
          slog::join_probe<2,1>(refindex448, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m477) {
            u64 v_c160 = m477[1];
            slog::join_probe<3,2>(lambdaindex449, std::array<u64,3>{v_c153, v_c160, 0}, [&](const std::array<u64,3>& m478) {
              u64 v_c161 = m478[2];
              slog::join_probe<2,1>(refindex450, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m479) {
                u64 v_c162 = m479[1];
                slog::join_probe<2,1>(refindex451, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m480) {
                  u64 v_c163 = m480[1];
                  slog::join_probe<3,2>(appindex452, std::array<u64,3>{v_c163, v_c154, 0}, [&](const std::array<u64,3>& m481) {
                    u64 v_c164 = m481[2];
                    ++_fires;
                    slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c161, v_c164, v_c155, v_c156, v_c157, v_c158});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c162, v_c155}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c159, v_c158}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "delta:temp4bTi1051", _fires);
  
      if (!_done)
      {
        ReadTask453* _cont = new ReadTask453(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask453(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre4r5A945 __errf1xxs946 __errf05Mk947 __errf0kPw948 __errf9DDv949) (body) (head (emit error (0) __erre4r5A945)) <internal>:1 #f)
  class ReadTask482 : public slog::Task
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
      std::vector<u16> ord483({0});
      slog::Relation* readrel484 = db->getRelation("error");
      head_index[0] = readrel484->getIndex(ord483, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask482(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c165 = _t[0];
        u64 v_c166 = _t[1];
        u64 v_c167 = _t[2];
        u64 v_c168 = _t[3];
        u64 v_c169 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c165}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask482* _cont = new ReadTask482(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask482(db,b), false);
  // (crule (pre) (scan let __t66ko429 x er eb) (body (exists eval (1 2 0) 1 er) (join eval (1 2 0) 1 __t66ko429 c __4M4I787) (join-old eval (1 2 0) 2 (1 2 0) er c __t9SPH430) (join eval_ans (0 1) 1 __t9SPH430 vr)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:93 #f)
  class ReadTask490 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex485;  slog::Index** evalindex486;  slog::Index** evalindex487;  slog::Index** eval_ansindex488;  slog::Index** evaldelta489;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord491({0, 1, 2});
      slog::Relation* readrel492 = db->getRelation("binding");
      head_index[0] = readrel492->getIndex(ord491, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord493({0, 1, 2});
      slog::Relation* readrel494 = db->getRelation("binding_event");
      head_index[1] = readrel494->getIndex(ord493, false);
      outer_rel = db->getRelation("let");
      std::vector<u16> ord495({1, 2, 0});
      slog::Relation* readrel496 = db->getRelation("eval");
      evalindex485 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({1, 2, 0});
      slog::Relation* readrel498 = db->getRelation("eval");
      evalindex486 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({1, 2, 0});
      slog::Relation* readrel500 = db->getRelation("eval");
      evalindex487 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({1, 2, 0});
      slog::Relation* readrel502 = db->getRelation("eval");
      evaldelta489 = readrel502->getIndex(ord501, true);
      std::vector<u16> ord503({0, 1});
      slog::Relation* readrel504 = db->getRelation("eval_ans");
      eval_ansindex488 = readrel504->getIndex(ord503, false);
  
    }
    ReadTask490(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c170 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c171 = _t[2];
        u64 v_c94 = _t[3];
        if (!slog::exists_probe<3,1>(evalindex485, std::array<u64,3>{v_c171, 0, 0})) return;
        slog::join_probe<3,1>(evalindex486, std::array<u64,3>{v_c170, 0, 0}, [&](const std::array<u64,3>& m505) {
          u64 v_c2 = m505[1]; u64 v_c172 = m505[2];
          slog::join_probe_old<3,2>(evalindex487, evaldelta489, std::array<u64,3>{v_c171, v_c2, 0}, [&](const std::array<u64,3>& m506) {
            u64 v_c173 = m506[2];
            slog::join_probe<2,1>(eval_ansindex488, std::array<u64,2>{v_c173, 0}, [&](const std::array<u64,2>& m507) {
              u64 v_c174 = m507[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c1, v_c2, v_c174}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c1, v_c2, v_c2}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:let", _fires);
  
      if (!_done)
      {
        ReadTask490* _cont = new ReadTask490(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask490(db,b), false);
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec) (let __tconst3nEA343 const0933fb667296882d8c45abca) (let __tconst0pCN356 consted725292f5f32d61535958c1) (let __tconst88d3359 const6b86b273ff34fce19d6b804e) (let __tconst8nL2368 const90fb9068eda6f2d68bb61c33)) (scan temp7hN01110 __t0Kjq332 __t0UW1342 __t2xne366 __t4CVz374 __t65kJ367 __t6UsA373) (body (exists ref (1 0) 1 __tconst0pCN356) (exists ref (1 0) 1 __tconst3nEA343) (exists num (1 0) 1 __tconst88d3359) (exists ref (1 0) 1 __tconst3Nin376) (exists app (2 0 1) 1 __t0Kjq332) (join ref (1 0) 1 __tconst8nL2368 __t5g5j369) (join ref (1 0) 1 __tconst0pCN356 __t56Hj357) (join ref (1 0) 1 __tconst3nEA343 __t85N1344) (join num (1 0) 1 __tconst88d3359 __t29aP337) (join ref (1 0) 1 __tconst3Nin376 __t7cCj334) (join app (1 2 0) 2 __t7cCj334 __t0Kjq332 __t3xwX335)) (head (emit-temp temp2BL61111 __t0UW1342 __t2xne366 __t3xwX335 __t4CVz374 __t65kJ367 __t6UsA373) (mkstruct app (1 2 0) __t6nY1345 __t85N1344 __t0UW1342) (mkstruct app (1 2 0) __t72Zs370 __t5g5j369 __t65kJ367)) schemecfa.slog:12 #f)
  class ReadTask519 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex508;  slog::Index** refindex509;  slog::Index** numindex510;  slog::Index** refindex511;  slog::Index** appindex512;  slog::Index** refindex513;  slog::Index** refindex514;  slog::Index** refindex515;  slog::Index** numindex516;  slog::Index** refindex517;  slog::Index** appindex518;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2BL61111");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      outer_rel = db->getRelation("temp7hN01110");
      std::vector<u16> ord520({1, 0});
      slog::Relation* readrel521 = db->getRelation("ref");
      refindex508 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({1, 0});
      slog::Relation* readrel523 = db->getRelation("ref");
      refindex509 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({1, 0});
      slog::Relation* readrel525 = db->getRelation("num");
      numindex510 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({1, 0});
      slog::Relation* readrel527 = db->getRelation("ref");
      refindex511 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({2, 0, 1});
      slog::Relation* readrel529 = db->getRelation("app");
      appindex512 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 0});
      slog::Relation* readrel531 = db->getRelation("ref");
      refindex513 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({1, 0});
      slog::Relation* readrel533 = db->getRelation("ref");
      refindex514 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 0});
      slog::Relation* readrel535 = db->getRelation("ref");
      refindex515 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({1, 0});
      slog::Relation* readrel537 = db->getRelation("num");
      numindex516 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({1, 0});
      slog::Relation* readrel539 = db->getRelation("ref");
      refindex517 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 2, 0});
      slog::Relation* readrel541 = db->getRelation("app");
      appindex518 = readrel541->getIndex(ord540, false);
  
    }
    ReadTask519(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_consta81ad7556291f9defc5163ec;
      u64 v_c24 = v_const0933fb667296882d8c45abca;
      u64 v_c25 = v_consted725292f5f32d61535958c1;
      u64 v_c26 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c28 = v_const90fb9068eda6f2d68bb61c33;
  
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
        u64 v_c40 = _t[0];
        u64 v_c175 = _t[1];
        u64 v_c41 = _t[2];
        u64 v_c42 = _t[3];
        u64 v_c176 = _t[4];
        u64 v_c31 = _t[5];
        if (!slog::exists_probe<2,1>(refindex508, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(refindex509, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(numindex510, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(refindex511, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<3,1>(appindex512, std::array<u64,3>{v_c40, 0, 0})) return;
        slog::join_probe<2,1>(refindex513, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m542) {
          u64 v_c32 = m542[1];
          slog::join_probe<2,1>(refindex514, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m543) {
            u64 v_c34 = m543[1];
            slog::join_probe<2,1>(refindex515, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m544) {
              u64 v_c35 = m544[1];
              slog::join_probe<2,1>(numindex516, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m545) {
                u64 v_c37 = m545[1];
                slog::join_probe<2,1>(refindex517, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m546) {
                  u64 v_c38 = m546[1];
                  slog::join_probe<3,2>(appindex518, std::array<u64,3>{v_c38, v_c40, 0}, [&](const std::array<u64,3>& m547) {
                    u64 v_c177 = m547[2];
                    ++_fires;
                    slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c175, v_c41, v_c177, v_c42, v_c176, v_c31});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c35, v_c175}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c32, v_c176}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp7hN01110", _fires);
  
      if (!_done)
      {
        ReadTask519* _cont = new ReadTask519(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask519(db,b), false);
  // (crule (pre (let _00024sqc8egv614 const6b86b273ff34fce19d6b804e) (let _00024sqc6fIG615 const5feceb66ffc86f38d952786c) (let _00024sqc4bXT616 const6b86b273ff34fce19d6b804e) (let _00024sqc8qtj617 const5feceb66ffc86f38d952786c) (let _00024sqo7FTM622 const5feceb66ffc86f38d952786c) (let __t9KsM444 (lempty))) (scan $sup56712x37x0x0x0 _00024seq0 __t2W25447 c e es) (body (join-old eval_args (0 2 1) 3 (0 2 1) __t2W25447 c _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7FTM622 e _00024seq0) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) e c __t25lG448) (exists eval_ans (0 1) 1 __t25lG448) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6oBa449) (exists eval_args_ans (0 1) 1 __t6oBa449) (join eval_ans (0 1) 1 __t25lG448 __v0) (join eval_args_ans (0 1) 1 __t6oBa449 __v1) (letp _00024sql5v3i612 (aslst _00024seq0)) (let _00024sqn11pi613 (llen _00024sql5v3i612)) (cmp ge _00024sqn11pi613 _00024sqc8egv614) (letp chk4NIV986 (lref _00024sql5v3i612 _00024sqc6fIG615)) (eq e chk4NIV986) (let _00024sqp7l34618 (_0002d _00024sqn11pi613 _00024sqc8qtj617)) (let chk0Ei4987 (lslice _00024sql5v3i612 _00024sqc4bXT616 _00024sqp7l34618)) (eq es chk0Ei4987)) (head (emit-temp temp2fEO980 __t2W25447 __t9KsM444 __v0 __v1)) interp.slog:38 #f)
  class ReadTask561 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex548;  slog::Index** $seq_atindex549;  slog::Index** eval_argsindex550;  slog::Index** evalindex551;  slog::Index** eval_ansindex552;  slog::Index** eval_argsindex553;  slog::Index** eval_args_ansindex554;  slog::Index** eval_ansindex555;  slog::Index** eval_args_ansindex556;  slog::Index** eval_argsdelta557;  slog::Index** $seq_atdelta558;  slog::Index** evaldelta559;  slog::Index** eval_argsdelta560;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2fEO980");
      outer_rel = db->getRelation("$sup56712x37x0x0x0");
      std::vector<u16> ord562({0, 2, 1});
      slog::Relation* readrel563 = db->getRelation("eval_args");
      eval_argsindex548 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({0, 2, 1});
      slog::Relation* readrel565 = db->getRelation("eval_args");
      eval_argsdelta557 = readrel565->getIndex(ord564, true);
      std::vector<u16> ord566({1, 0, 2});
      slog::Relation* readrel567 = db->getRelation("$seq_at");
      $seq_atindex549 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 0, 2});
      slog::Relation* readrel569 = db->getRelation("$seq_at");
      $seq_atdelta558 = readrel569->getIndex(ord568, true);
      std::vector<u16> ord570({1, 2, 0});
      slog::Relation* readrel571 = db->getRelation("eval_args");
      eval_argsindex550 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 2, 0});
      slog::Relation* readrel573 = db->getRelation("eval");
      evalindex551 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 2, 0});
      slog::Relation* readrel575 = db->getRelation("eval");
      evaldelta559 = readrel575->getIndex(ord574, true);
      std::vector<u16> ord576({0, 1});
      slog::Relation* readrel577 = db->getRelation("eval_ans");
      eval_ansindex552 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({1, 2, 0});
      slog::Relation* readrel579 = db->getRelation("eval_args");
      eval_argsindex553 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 2, 0});
      slog::Relation* readrel581 = db->getRelation("eval_args");
      eval_argsdelta560 = readrel581->getIndex(ord580, true);
      std::vector<u16> ord582({0, 1});
      slog::Relation* readrel583 = db->getRelation("eval_args_ans");
      eval_args_ansindex554 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({0, 1});
      slog::Relation* readrel585 = db->getRelation("eval_ans");
      eval_ansindex555 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({0, 1});
      slog::Relation* readrel587 = db->getRelation("eval_args_ans");
      eval_args_ansindex556 = readrel587->getIndex(ord586, false);
  
    }
    ReadTask561(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c178 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c179 = v_const5feceb66ffc86f38d952786c;
      u64 v_c180 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c181 = v_const5feceb66ffc86f38d952786c;
      u64 v_c182 = v_const5feceb66ffc86f38d952786c;
      u64 v_c183 = _prim_lempty(db);
      if (v_c183 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c85 = _t[0];
        u64 v_c184 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c89 = _t[3];
        u64 v_c91 = _t[4];
        slog::join_probe_old<3,3>(eval_argsindex548, eval_argsdelta557, std::array<u64,3>{v_c184, v_c2, v_c85}, [&](const std::array<u64,3>& m588) {
          slog::join_probe_old<3,3>($seq_atindex549, $seq_atdelta558, std::array<u64,3>{v_c182, v_c89, v_c85}, [&](const std::array<u64,3>& m589) {
            if (!slog::exists_probe<3,2>(eval_argsindex550, std::array<u64,3>{v_c91, v_c2, 0})) return;
            slog::join_probe_old<3,2>(evalindex551, evaldelta559, std::array<u64,3>{v_c89, v_c2, 0}, [&](const std::array<u64,3>& m590) {
              u64 v_c185 = m590[2];
              if (!slog::exists_probe<2,1>(eval_ansindex552, std::array<u64,2>{v_c185, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex553, eval_argsdelta560, std::array<u64,3>{v_c91, v_c2, 0}, [&](const std::array<u64,3>& m591) {
                u64 v_c186 = m591[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex554, std::array<u64,2>{v_c186, 0})) return;
                slog::join_probe<2,1>(eval_ansindex555, std::array<u64,2>{v_c185, 0}, [&](const std::array<u64,2>& m592) {
                  u64 v_c3 = m592[1];
                  slog::join_probe<2,1>(eval_args_ansindex556, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m593) {
                    u64 v_c187 = m593[1];
                    bool ok594 = true;
                    u64 v_c188 = _prim_aslst(db, v_c85, &ok594);
                    if (!ok594) return;
                    u64 v_c189 = _prim_llen(db, v_c188);
                    if (v_c189 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c190 = _prim_ge(db, v_c189, v_c178);
                    if (v_c190 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (!v_c190) return;
                    bool ok596 = true;
                    u64 v_c191 = _prim_lref(db, v_c188, v_c179, &ok596);
                    if (!ok596) return;
                    if (v_c89 != v_c191) return;
                    u64 v_c192 = _prim__0002d(db, v_c189, v_c181);
                    if (v_c192 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c193 = _prim_lslice(db, v_c188, v_c180, v_c192);
                    if (v_c193 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (v_c91 != v_c193) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c184, v_c183, v_c3, v_c187});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:$sup56712x37x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask561* _cont = new ReadTask561(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask561(db,b), false);
  // (crule (pre (let _00024sqc8egv614 const6b86b273ff34fce19d6b804e) (let _00024sqc6fIG615 const5feceb66ffc86f38d952786c) (let _00024sqc4bXT616 const6b86b273ff34fce19d6b804e) (let _00024sqc8qtj617 const5feceb66ffc86f38d952786c) (let _00024sqo7FTM622 const5feceb66ffc86f38d952786c) (let __t9KsM444 (lempty))) (scan eval_args __t6oBa449 es c) (body (exists eval_args (2 0 1) 1 c) (exists $seq_at (1 0 2) 1 _00024sqo7FTM622) (exists eval (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t6oBa449) (join $sup56712x37x0x0x0 (2 4 0 1 3) 2 c es _00024seq0 __t2W25447 e) (join eval_args (0 2 1) 3 __t2W25447 c _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7FTM622 e _00024seq0) (join eval (1 2 0) 2 e c __t25lG448) (join eval_ans (0 1) 1 __t25lG448 __v0) (join eval_args_ans (0 1) 1 __t6oBa449 __v1) (letp _00024sql5v3i612 (aslst _00024seq0)) (let _00024sqn11pi613 (llen _00024sql5v3i612)) (cmp ge _00024sqn11pi613 _00024sqc8egv614) (letp chk7CXs989 (lref _00024sql5v3i612 _00024sqc6fIG615)) (eq e chk7CXs989) (let _00024sqp7l34618 (_0002d _00024sqn11pi613 _00024sqc8qtj617)) (let chk4avX990 (lslice _00024sql5v3i612 _00024sqc4bXT616 _00024sqp7l34618)) (eq es chk4avX990)) (head (emit-temp temp2fEO980 __t2W25447 __t9KsM444 __v0 __v1)) interp.slog:38 #f)
  class ReadTask608 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex597;  slog::Index** $seq_atindex598;  slog::Index** evalindex599;  slog::Index** eval_args_ansindex600;  slog::Index** $sup56712x37x0x0x0index601;  slog::Index** eval_argsindex602;  slog::Index** $seq_atindex603;  slog::Index** evalindex604;  slog::Index** eval_ansindex605;  slog::Index** eval_args_ansindex606;  slog::Index** $seq_atdelta607;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2fEO980");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord609({2, 0, 1});
      slog::Relation* readrel610 = db->getRelation("eval_args");
      eval_argsindex597 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({1, 0, 2});
      slog::Relation* readrel612 = db->getRelation("$seq_at");
      $seq_atindex598 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({2, 0, 1});
      slog::Relation* readrel614 = db->getRelation("eval");
      evalindex599 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({0, 1});
      slog::Relation* readrel616 = db->getRelation("eval_args_ans");
      eval_args_ansindex600 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({2, 4, 0, 1, 3});
      slog::Relation* readrel618 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index601 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({0, 2, 1});
      slog::Relation* readrel620 = db->getRelation("eval_args");
      eval_argsindex602 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({1, 0, 2});
      slog::Relation* readrel622 = db->getRelation("$seq_at");
      $seq_atindex603 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({1, 0, 2});
      slog::Relation* readrel624 = db->getRelation("$seq_at");
      $seq_atdelta607 = readrel624->getIndex(ord623, true);
      std::vector<u16> ord625({1, 2, 0});
      slog::Relation* readrel626 = db->getRelation("eval");
      evalindex604 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({0, 1});
      slog::Relation* readrel628 = db->getRelation("eval_ans");
      eval_ansindex605 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({0, 1});
      slog::Relation* readrel630 = db->getRelation("eval_args_ans");
      eval_args_ansindex606 = readrel630->getIndex(ord629, false);
  
    }
    ReadTask608(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c178 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c179 = v_const5feceb66ffc86f38d952786c;
      u64 v_c180 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c181 = v_const5feceb66ffc86f38d952786c;
      u64 v_c182 = v_const5feceb66ffc86f38d952786c;
      u64 v_c183 = _prim_lempty(db);
      if (v_c183 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c186 = _t[0];
        u64 v_c91 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(eval_argsindex597, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atindex598, std::array<u64,3>{v_c182, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex599, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex600, std::array<u64,2>{v_c186, 0})) return;
        slog::join_probe<5,2>($sup56712x37x0x0x0index601, std::array<u64,5>{v_c2, v_c91, 0, 0, 0}, [&](const std::array<u64,5>& m631) {
          u64 v_c85 = m631[2]; u64 v_c184 = m631[3]; u64 v_c89 = m631[4];
          slog::join_probe<3,3>(eval_argsindex602, std::array<u64,3>{v_c184, v_c2, v_c85}, [&](const std::array<u64,3>& m632) {
            slog::join_probe_old<3,3>($seq_atindex603, $seq_atdelta607, std::array<u64,3>{v_c182, v_c89, v_c85}, [&](const std::array<u64,3>& m633) {
              slog::join_probe<3,2>(evalindex604, std::array<u64,3>{v_c89, v_c2, 0}, [&](const std::array<u64,3>& m634) {
                u64 v_c185 = m634[2];
                slog::join_probe<2,1>(eval_ansindex605, std::array<u64,2>{v_c185, 0}, [&](const std::array<u64,2>& m635) {
                  u64 v_c3 = m635[1];
                  slog::join_probe<2,1>(eval_args_ansindex606, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m636) {
                    u64 v_c187 = m636[1];
                    bool ok637 = true;
                    u64 v_c188 = _prim_aslst(db, v_c85, &ok637);
                    if (!ok637) return;
                    u64 v_c189 = _prim_llen(db, v_c188);
                    if (v_c189 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c194 = _prim_ge(db, v_c189, v_c178);
                    if (v_c194 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (!v_c194) return;
                    bool ok639 = true;
                    u64 v_c195 = _prim_lref(db, v_c188, v_c179, &ok639);
                    if (!ok639) return;
                    if (v_c89 != v_c195) return;
                    u64 v_c192 = _prim__0002d(db, v_c189, v_c181);
                    if (v_c192 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c196 = _prim_lslice(db, v_c188, v_c180, v_c192);
                    if (v_c196 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (v_c91 != v_c196) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c184, v_c183, v_c3, v_c187});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask608* _cont = new ReadTask608(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask608(db,b), false);
  // (crule (pre) (scan eval_args __t5BFX27 es c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (join eval_args_ans (0 1) 1 __t5BFX27 vs) (join eval (2 0 1) 1 c __4cUN684 __t8j7u29) (exists tick (1 2 0) 2 __t8j7u29 c) (join-old app (2 0 1) 2 (2 0 1) es __t8j7u29 ef) (join eval (1 2 0) 2 ef c __t5MCM24) (exists eval_ans (0 1) 1 __t5MCM24) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (exists tick_ans (0 1) 1 __t0DSy30) (join eval_ans (0 1) 1 __t5MCM24 __t3Pto26) (join tick_ans (0 1) 1 __t0DSy30 l) (join closure (0 1 2) 1 __t3Pto26 __t0xip28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t0xip28 y) (join binding (0 1 2) 2 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask661 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex640;  slog::Index** appindex641;  slog::Index** tickindex642;  slog::Index** eval_args_ansindex643;  slog::Index** evalindex644;  slog::Index** tickindex645;  slog::Index** appindex646;  slog::Index** evalindex647;  slog::Index** eval_ansindex648;  slog::Index** tickindex649;  slog::Index** tick_ansindex650;  slog::Index** eval_ansindex651;  slog::Index** tick_ansindex652;  slog::Index** closureindex653;  slog::Index** bindingindex654;  slog::Index** freevarindex655;  slog::Index** bindingindex656;  slog::Index** lambdaindex657;  slog::Index** appdelta658;  slog::Index** tickdelta659;  slog::Index** lambdadelta660;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord662({0, 1, 2});
      slog::Relation* readrel663 = db->getRelation("binding");
      head_index[0] = readrel663->getIndex(ord662, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord664({0, 1, 2});
      slog::Relation* readrel665 = db->getRelation("binding_event");
      head_index[1] = readrel665->getIndex(ord664, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord666({2, 0, 1});
      slog::Relation* readrel667 = db->getRelation("eval");
      evalindex640 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({2, 0, 1});
      slog::Relation* readrel669 = db->getRelation("app");
      appindex641 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({2, 0, 1});
      slog::Relation* readrel671 = db->getRelation("tick");
      tickindex642 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({0, 1});
      slog::Relation* readrel673 = db->getRelation("eval_args_ans");
      eval_args_ansindex643 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({2, 0, 1});
      slog::Relation* readrel675 = db->getRelation("eval");
      evalindex644 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 2, 0});
      slog::Relation* readrel677 = db->getRelation("tick");
      tickindex645 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({2, 0, 1});
      slog::Relation* readrel679 = db->getRelation("app");
      appindex646 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({2, 0, 1});
      slog::Relation* readrel681 = db->getRelation("app");
      appdelta658 = readrel681->getIndex(ord680, true);
      std::vector<u16> ord682({1, 2, 0});
      slog::Relation* readrel683 = db->getRelation("eval");
      evalindex647 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("eval_ans");
      eval_ansindex648 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({1, 2, 0});
      slog::Relation* readrel687 = db->getRelation("tick");
      tickindex649 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({1, 2, 0});
      slog::Relation* readrel689 = db->getRelation("tick");
      tickdelta659 = readrel689->getIndex(ord688, true);
      std::vector<u16> ord690({0, 1});
      slog::Relation* readrel691 = db->getRelation("tick_ans");
      tick_ansindex650 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({0, 1});
      slog::Relation* readrel693 = db->getRelation("eval_ans");
      eval_ansindex651 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({0, 1});
      slog::Relation* readrel695 = db->getRelation("tick_ans");
      tick_ansindex652 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({0, 1, 2});
      slog::Relation* readrel697 = db->getRelation("closure");
      closureindex653 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({1, 0, 2});
      slog::Relation* readrel699 = db->getRelation("binding");
      bindingindex654 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 0});
      slog::Relation* readrel701 = db->getRelation("freevar");
      freevarindex655 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({0, 1, 2});
      slog::Relation* readrel703 = db->getRelation("binding");
      bindingindex656 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({0, 1, 2});
      slog::Relation* readrel705 = db->getRelation("lambda");
      lambdaindex657 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({0, 1, 2});
      slog::Relation* readrel707 = db->getRelation("lambda");
      lambdadelta660 = readrel707->getIndex(ord706, true);
  
    }
    ReadTask661(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c103 = _t[0];
        u64 v_c91 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex640, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex641, std::array<u64,3>{v_c91, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex642, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(eval_args_ansindex643, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m708) {
          u64 v_c105 = m708[1];
          slog::join_probe<3,1>(evalindex644, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m709) {
            u64 v_c101 = m709[1]; u64 v_c102 = m709[2];
            if (!slog::exists_probe<3,2>(tickindex645, std::array<u64,3>{v_c102, v_c2, 0})) return;
            slog::join_probe_old<3,2>(appindex646, appdelta658, std::array<u64,3>{v_c91, v_c102, 0}, [&](const std::array<u64,3>& m710) {
              u64 v_c100 = m710[2];
              slog::join_probe<3,2>(evalindex647, std::array<u64,3>{v_c100, v_c2, 0}, [&](const std::array<u64,3>& m711) {
                u64 v_c99 = m711[2];
                if (!slog::exists_probe<2,1>(eval_ansindex648, std::array<u64,2>{v_c99, 0})) return;
                slog::join_probe_old<3,2>(tickindex649, tickdelta659, std::array<u64,3>{v_c102, v_c2, 0}, [&](const std::array<u64,3>& m712) {
                  u64 v_c104 = m712[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex650, std::array<u64,2>{v_c104, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex651, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m713) {
                    u64 v_c98 = m713[1];
                    slog::join_probe<2,1>(tick_ansindex652, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m714) {
                      u64 v_c106 = m714[1];
                      slog::join_probe<3,1>(closureindex653, std::array<u64,3>{v_c98, 0, 0}, [&](const std::array<u64,3>& m715) {
                        u64 v_c92 = m715[1]; u64 v_c96 = m715[2];
                        if (!slog::exists_probe<3,1>(bindingindex654, std::array<u64,3>{v_c96, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex655, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m716) {
                          u64 v_c95 = m716[1];
                          slog::join_probe<3,2>(bindingindex656, std::array<u64,3>{v_c95, v_c96, 0}, [&](const std::array<u64,3>& m717) {
                            u64 v_c97 = m717[2];
                            slog::join_probe_old<3,1>(lambdaindex657, lambdadelta660, std::array<u64,3>{v_c92, 0, 0}, [&](const std::array<u64,3>& m718) {
                              u64 v_c93 = m718[1]; u64 v_c94 = m718[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c95, v_c106, v_c97}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c95, v_c106, v_c2}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask661* _cont = new ReadTask661(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask661(db,b), false);
  // (crule (pre (let __tconst7knU761 const0122baa3ac55f1b433944eb1) (let __tconst35kI244 const06abaa100ecef791ce028c56) (let _00024sqc59yj663 constd4735e3a265e16eee03f5971) (let _00024sqc7n8w664 const5feceb66ffc86f38d952786c) (let _00024sqc4sLR665 const6b86b273ff34fce19d6b804e) (let _00024sqo8MNY666 const5feceb66ffc86f38d952786c) (let _00024sqo0NcP667 const6b86b273ff34fce19d6b804e) (let _00024sqo0X3t668 const6b86b273ff34fce19d6b804e) (let _00024sqo6VJl669 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo0X3t668 __t1b46247 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo8MNY666 __t1b46247 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo0NcP667 __t1b46247 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo6VJl669 __t1b46247 _00024seq2) (exists _enum (1 0) 1 __tconst7knU761) (join delta (1 2 0) 2 __tconst35kI244 _00024seq2 __t7NfZ245) (join _enum (1 0) 1 __tconst7knU761 __t4Ufa242) (join boolval (0 1) 1 __t1b46247 b) (letp _00024sql4qXJ661 (aslst _00024seq2)) (let chk44iB974 (llen _00024sql4qXJ661)) (eq _00024sqc59yj663 chk44iB974) (letp chk97Vd975 (lref _00024sql4qXJ661 _00024sqc7n8w664)) (eq __t1b46247 chk97Vd975) (letp chk7dlG976 (lref _00024sql4qXJ661 _00024sqc4sLR665)) (eq __t1b46247 chk7dlG976)) (head (emit-temp temp3tnu962 __t7NfZ245) (mkstruct boolval (1 0) __t0oTa243 __t4Ufa242)) interp.slog:118 #f)
  class ReadTask727 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex719;  slog::Index** $seq_atindex720;  slog::Index** $seq_atrindex721;  slog::Index** _enumindex722;  slog::Index** deltaindex723;  slog::Index** _enumindex724;  slog::Index** boolvalindex725;  slog::Index** $seq_atrdelta726;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3tnu962");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord728({1, 0, 2});
      slog::Relation* readrel729 = db->getRelation("$seq_atr");
      driver_index = readrel729->getIndex(ord728, true);
      std::vector<u16> ord730({1, 0, 2});
      slog::Relation* readrel731 = db->getRelation("$seq_at");
      $seq_atindex719 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 0, 2});
      slog::Relation* readrel733 = db->getRelation("$seq_at");
      $seq_atindex720 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({1, 0, 2});
      slog::Relation* readrel735 = db->getRelation("$seq_atr");
      $seq_atrindex721 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({1, 0, 2});
      slog::Relation* readrel737 = db->getRelation("$seq_atr");
      $seq_atrdelta726 = readrel737->getIndex(ord736, true);
      std::vector<u16> ord738({1, 0});
      slog::Relation* readrel739 = db->getRelation("_enum");
      _enumindex722 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({1, 2, 0});
      slog::Relation* readrel741 = db->getRelation("delta");
      deltaindex723 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 0});
      slog::Relation* readrel743 = db->getRelation("_enum");
      _enumindex724 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({0, 1});
      slog::Relation* readrel745 = db->getRelation("boolval");
      boolvalindex725 = readrel745->getIndex(ord744, false);
  
    }
    ReadTask727(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c108 = v_const06abaa100ecef791ce028c56;
      u64 v_c109 = v_constd4735e3a265e16eee03f5971;
      u64 v_c110 = v_const5feceb66ffc86f38d952786c;
      u64 v_c111 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c112 = v_const5feceb66ffc86f38d952786c;
      u64 v_c113 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c114 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c114, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m746) {
        u64 v_c116 = m746[1];
        u64 v_c16 = m746[2];
        if (buckethash(v_c116) != bucket) return;
        slog::join_probe<3,3>($seq_atindex719, std::array<u64,3>{v_c112, v_c116, v_c16}, [&](const std::array<u64,3>& m747) {
          slog::join_probe<3,3>($seq_atindex720, std::array<u64,3>{v_c113, v_c116, v_c16}, [&](const std::array<u64,3>& m748) {
            slog::join_probe_old<3,3>($seq_atrindex721, $seq_atrdelta726, std::array<u64,3>{v_c115, v_c116, v_c16}, [&](const std::array<u64,3>& m749) {
              if (!slog::exists_probe<2,1>(_enumindex722, std::array<u64,2>{v_c107, 0})) return;
              slog::join_probe<3,2>(deltaindex723, std::array<u64,3>{v_c108, v_c16, 0}, [&](const std::array<u64,3>& m750) {
                u64 v_c117 = m750[2];
                slog::join_probe<2,1>(_enumindex724, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m751) {
                  u64 v_c118 = m751[1];
                  slog::join_probe<2,1>(boolvalindex725, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m752) {
                    u64 v_c18 = m752[1];
                    bool ok753 = true;
                    u64 v_c119 = _prim_aslst(db, v_c16, &ok753);
                    if (!ok753) return;
                    u64 v_c197 = _prim_llen(db, v_c119);
                    if (v_c197 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c109 != v_c197) return;
                    bool ok754 = true;
                    u64 v_c198 = _prim_lref(db, v_c119, v_c110, &ok754);
                    if (!ok754) return;
                    if (v_c116 != v_c198) return;
                    bool ok755 = true;
                    u64 v_c199 = _prim_lref(db, v_c119, v_c111, &ok755);
                    if (!ok755) return;
                    if (v_c116 != v_c199) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c117});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c118}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask727* _cont = new ReadTask727(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask727(db,b), false);
  // (crule (pre) (scan tick __t3KuN210 __t8x6E209 c) (body (exists $sup56712x41x0x0x0 (1 0 2 3) 1 c) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (exists tick_ans (0 1) 1 __t3KuN210) (join eval (1 2 0) 2 __t8x6E209 c __t9lTe203) (join $sup56712x41x0x0x0 (1 0 2 3) 2 c __t9lTe203 ef es) (join app (0 1 2) 3 __t8x6E209 ef es) (exists eval_args (1 2 0) 2 es c) (join eval (1 2 0) 2 ef c __t1DkM204) (exists eval_ans (0 1) 1 __t1DkM204) (join eval_args (1 2 0) 2 es c __t58jO207) (exists eval_args_ans (0 1) 1 __t58jO207) (join eval_ans (0 1) 1 __t1DkM204 __t6XAE206) (join eval_args_ans (0 1) 1 __t58jO207 vs) (join tick_ans (0 1) 1 __t3KuN210 __v0) (exists eval (2 0 1) 1 __v0) (join closure (0 1 2) 1 __t6XAE206 __t6hhS205 cb) (join lambda (0 1 2) 1 __t6hhS205 xs eb) (join eval (1 2 0) 2 eb __v0 __t3K5j208) (join eval_ans (0 1) 1 __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask776 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x41x0x0x0index756;  slog::Index** evalindex757;  slog::Index** eval_argsindex758;  slog::Index** tick_ansindex759;  slog::Index** evalindex760;  slog::Index** $sup56712x41x0x0x0index761;  slog::Index** appindex762;  slog::Index** eval_argsindex763;  slog::Index** evalindex764;  slog::Index** eval_ansindex765;  slog::Index** eval_argsindex766;  slog::Index** eval_args_ansindex767;  slog::Index** eval_ansindex768;  slog::Index** eval_args_ansindex769;  slog::Index** tick_ansindex770;  slog::Index** evalindex771;  slog::Index** closureindex772;  slog::Index** lambdaindex773;  slog::Index** evalindex774;  slog::Index** eval_ansindex775;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord777({0, 1});
      slog::Relation* readrel778 = db->getRelation("eval_ans");
      head_index[0] = readrel778->getIndex(ord777, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord779({1, 0, 2, 3});
      slog::Relation* readrel780 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index756 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({2, 0, 1});
      slog::Relation* readrel782 = db->getRelation("eval");
      evalindex757 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({2, 0, 1});
      slog::Relation* readrel784 = db->getRelation("eval_args");
      eval_argsindex758 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({0, 1});
      slog::Relation* readrel786 = db->getRelation("tick_ans");
      tick_ansindex759 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({1, 2, 0});
      slog::Relation* readrel788 = db->getRelation("eval");
      evalindex760 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 0, 2, 3});
      slog::Relation* readrel790 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index761 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({0, 1, 2});
      slog::Relation* readrel792 = db->getRelation("app");
      appindex762 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({1, 2, 0});
      slog::Relation* readrel794 = db->getRelation("eval_args");
      eval_argsindex763 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({1, 2, 0});
      slog::Relation* readrel796 = db->getRelation("eval");
      evalindex764 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({0, 1});
      slog::Relation* readrel798 = db->getRelation("eval_ans");
      eval_ansindex765 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({1, 2, 0});
      slog::Relation* readrel800 = db->getRelation("eval_args");
      eval_argsindex766 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({0, 1});
      slog::Relation* readrel802 = db->getRelation("eval_args_ans");
      eval_args_ansindex767 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({0, 1});
      slog::Relation* readrel804 = db->getRelation("eval_ans");
      eval_ansindex768 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({0, 1});
      slog::Relation* readrel806 = db->getRelation("eval_args_ans");
      eval_args_ansindex769 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({0, 1});
      slog::Relation* readrel808 = db->getRelation("tick_ans");
      tick_ansindex770 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({2, 0, 1});
      slog::Relation* readrel810 = db->getRelation("eval");
      evalindex771 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({0, 1, 2});
      slog::Relation* readrel812 = db->getRelation("closure");
      closureindex772 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({0, 1, 2});
      slog::Relation* readrel814 = db->getRelation("lambda");
      lambdaindex773 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 2, 0});
      slog::Relation* readrel816 = db->getRelation("eval");
      evalindex774 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({0, 1});
      slog::Relation* readrel818 = db->getRelation("eval_ans");
      eval_ansindex775 = readrel818->getIndex(ord817, false);
  
    }
    ReadTask776(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c200 = _t[0];
        u64 v_c201 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<4,1>($sup56712x41x0x0x0index756, std::array<u64,4>{v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex757, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex758, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(tick_ansindex759, std::array<u64,2>{v_c200, 0})) return;
        slog::join_probe<3,2>(evalindex760, std::array<u64,3>{v_c201, v_c2, 0}, [&](const std::array<u64,3>& m819) {
          u64 v_c202 = m819[2];
          slog::join_probe<4,2>($sup56712x41x0x0x0index761, std::array<u64,4>{v_c2, v_c202, 0, 0}, [&](const std::array<u64,4>& m820) {
            u64 v_c100 = m820[2]; u64 v_c91 = m820[3];
            slog::join_probe<3,3>(appindex762, std::array<u64,3>{v_c201, v_c100, v_c91}, [&](const std::array<u64,3>& m821) {
              if (!slog::exists_probe<3,2>(eval_argsindex763, std::array<u64,3>{v_c91, v_c2, 0})) return;
              slog::join_probe<3,2>(evalindex764, std::array<u64,3>{v_c100, v_c2, 0}, [&](const std::array<u64,3>& m822) {
                u64 v_c203 = m822[2];
                if (!slog::exists_probe<2,1>(eval_ansindex765, std::array<u64,2>{v_c203, 0})) return;
                slog::join_probe<3,2>(eval_argsindex766, std::array<u64,3>{v_c91, v_c2, 0}, [&](const std::array<u64,3>& m823) {
                  u64 v_c204 = m823[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex767, std::array<u64,2>{v_c204, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex768, std::array<u64,2>{v_c203, 0}, [&](const std::array<u64,2>& m824) {
                    u64 v_c205 = m824[1];
                    slog::join_probe<2,1>(eval_args_ansindex769, std::array<u64,2>{v_c204, 0}, [&](const std::array<u64,2>& m825) {
                      u64 v_c105 = m825[1];
                      slog::join_probe<2,1>(tick_ansindex770, std::array<u64,2>{v_c200, 0}, [&](const std::array<u64,2>& m826) {
                        u64 v_c3 = m826[1];
                        if (!slog::exists_probe<3,1>(evalindex771, std::array<u64,3>{v_c3, 0, 0})) return;
                        slog::join_probe<3,1>(closureindex772, std::array<u64,3>{v_c205, 0, 0}, [&](const std::array<u64,3>& m827) {
                          u64 v_c206 = m827[1]; u64 v_c96 = m827[2];
                          slog::join_probe<3,1>(lambdaindex773, std::array<u64,3>{v_c206, 0, 0}, [&](const std::array<u64,3>& m828) {
                            u64 v_c93 = m828[1]; u64 v_c94 = m828[2];
                            slog::join_probe<3,2>(evalindex774, std::array<u64,3>{v_c94, v_c3, 0}, [&](const std::array<u64,3>& m829) {
                              u64 v_c207 = m829[2];
                              slog::join_probe<2,1>(eval_ansindex775, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m830) {
                                u64 v_c208 = m830[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c202, v_c208}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask776* _cont = new ReadTask776(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask776(db,b), false);
  // (crule (pre (let _00024sqc8egv614 const6b86b273ff34fce19d6b804e) (let _00024sqc6fIG615 const5feceb66ffc86f38d952786c) (let _00024sqc4bXT616 const6b86b273ff34fce19d6b804e) (let _00024sqc8qtj617 const5feceb66ffc86f38d952786c) (let _00024sqo7FTM622 const5feceb66ffc86f38d952786c) (let __t9KsM444 (lempty))) (scan eval_args_ans __t6oBa449 __v1) (body (exists $seq_at (1 0 2) 1 _00024sqo7FTM622) (join-old eval_args (0 2 1) 1 (0 2 1) __t6oBa449 c es) (exists eval_args (2 0 1) 1 c) (exists eval (2 0 1) 1 c) (join-old $sup56712x37x0x0x0 (2 4 0 1 3) 2 (2 4 0 1 3) c es _00024seq0 __t2W25447 e) (join-old eval_args (0 2 1) 3 (0 2 1) __t2W25447 c _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7FTM622 e _00024seq0) (join-old eval (1 2 0) 2 (1 2 0) e c __t25lG448) (join eval_ans (0 1) 1 __t25lG448 __v0) (letp _00024sql5v3i612 (aslst _00024seq0)) (let _00024sqn11pi613 (llen _00024sql5v3i612)) (cmp ge _00024sqn11pi613 _00024sqc8egv614) (letp chk10vv984 (lref _00024sql5v3i612 _00024sqc6fIG615)) (eq e chk10vv984) (let _00024sqp7l34618 (_0002d _00024sqn11pi613 _00024sqc8qtj617)) (let chk1P36985 (lslice _00024sql5v3i612 _00024sqc4bXT616 _00024sqp7l34618)) (eq es chk1P36985)) (head (emit-temp temp2fEO980 __t2W25447 __t9KsM444 __v0 __v1)) interp.slog:38 #f)
  class ReadTask845 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex831;  slog::Index** eval_argsindex832;  slog::Index** eval_argsindex833;  slog::Index** evalindex834;  slog::Index** $sup56712x37x0x0x0index835;  slog::Index** eval_argsindex836;  slog::Index** $seq_atindex837;  slog::Index** evalindex838;  slog::Index** eval_ansindex839;  slog::Index** eval_argsdelta840;  slog::Index** $sup56712x37x0x0x0delta841;  slog::Index** eval_argsdelta842;  slog::Index** $seq_atdelta843;  slog::Index** evaldelta844;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2fEO980");
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord846({1, 0, 2});
      slog::Relation* readrel847 = db->getRelation("$seq_at");
      $seq_atindex831 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({0, 2, 1});
      slog::Relation* readrel849 = db->getRelation("eval_args");
      eval_argsindex832 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({0, 2, 1});
      slog::Relation* readrel851 = db->getRelation("eval_args");
      eval_argsdelta840 = readrel851->getIndex(ord850, true);
      std::vector<u16> ord852({2, 0, 1});
      slog::Relation* readrel853 = db->getRelation("eval_args");
      eval_argsindex833 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({2, 0, 1});
      slog::Relation* readrel855 = db->getRelation("eval");
      evalindex834 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({2, 4, 0, 1, 3});
      slog::Relation* readrel857 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index835 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({2, 4, 0, 1, 3});
      slog::Relation* readrel859 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0delta841 = readrel859->getIndex(ord858, true);
      std::vector<u16> ord860({0, 2, 1});
      slog::Relation* readrel861 = db->getRelation("eval_args");
      eval_argsindex836 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({0, 2, 1});
      slog::Relation* readrel863 = db->getRelation("eval_args");
      eval_argsdelta842 = readrel863->getIndex(ord862, true);
      std::vector<u16> ord864({1, 0, 2});
      slog::Relation* readrel865 = db->getRelation("$seq_at");
      $seq_atindex837 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({1, 0, 2});
      slog::Relation* readrel867 = db->getRelation("$seq_at");
      $seq_atdelta843 = readrel867->getIndex(ord866, true);
      std::vector<u16> ord868({1, 2, 0});
      slog::Relation* readrel869 = db->getRelation("eval");
      evalindex838 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({1, 2, 0});
      slog::Relation* readrel871 = db->getRelation("eval");
      evaldelta844 = readrel871->getIndex(ord870, true);
      std::vector<u16> ord872({0, 1});
      slog::Relation* readrel873 = db->getRelation("eval_ans");
      eval_ansindex839 = readrel873->getIndex(ord872, false);
  
    }
    ReadTask845(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c178 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c179 = v_const5feceb66ffc86f38d952786c;
      u64 v_c180 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c181 = v_const5feceb66ffc86f38d952786c;
      u64 v_c182 = v_const5feceb66ffc86f38d952786c;
      u64 v_c183 = _prim_lempty(db);
      if (v_c183 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c186 = _t[0];
        u64 v_c187 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex831, std::array<u64,3>{v_c182, 0, 0})) return;
        slog::join_probe_old<3,1>(eval_argsindex832, eval_argsdelta840, std::array<u64,3>{v_c186, 0, 0}, [&](const std::array<u64,3>& m874) {
          u64 v_c2 = m874[1]; u64 v_c91 = m874[2];
          if (!slog::exists_probe<3,1>(eval_argsindex833, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex834, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x37x0x0x0index835, $sup56712x37x0x0x0delta841, std::array<u64,5>{v_c2, v_c91, 0, 0, 0}, [&](const std::array<u64,5>& m875) {
            u64 v_c85 = m875[2]; u64 v_c184 = m875[3]; u64 v_c89 = m875[4];
            slog::join_probe_old<3,3>(eval_argsindex836, eval_argsdelta842, std::array<u64,3>{v_c184, v_c2, v_c85}, [&](const std::array<u64,3>& m876) {
              slog::join_probe_old<3,3>($seq_atindex837, $seq_atdelta843, std::array<u64,3>{v_c182, v_c89, v_c85}, [&](const std::array<u64,3>& m877) {
                slog::join_probe_old<3,2>(evalindex838, evaldelta844, std::array<u64,3>{v_c89, v_c2, 0}, [&](const std::array<u64,3>& m878) {
                  u64 v_c185 = m878[2];
                  slog::join_probe<2,1>(eval_ansindex839, std::array<u64,2>{v_c185, 0}, [&](const std::array<u64,2>& m879) {
                    u64 v_c3 = m879[1];
                    bool ok880 = true;
                    u64 v_c188 = _prim_aslst(db, v_c85, &ok880);
                    if (!ok880) return;
                    u64 v_c189 = _prim_llen(db, v_c188);
                    if (v_c189 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c209 = _prim_ge(db, v_c189, v_c178);
                    if (v_c209 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (!v_c209) return;
                    bool ok882 = true;
                    u64 v_c210 = _prim_lref(db, v_c188, v_c179, &ok882);
                    if (!ok882) return;
                    if (v_c89 != v_c210) return;
                    u64 v_c192 = _prim__0002d(db, v_c189, v_c181);
                    if (v_c192 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c211 = _prim_lslice(db, v_c188, v_c180, v_c192);
                    if (v_c211 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (v_c91 != v_c211) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c184, v_c183, v_c3, v_c187});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask845* _cont = new ReadTask845(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask845(db,b), false);
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec) (let __tconst3nEA343 const0933fb667296882d8c45abca) (let __tconst0pCN356 consted725292f5f32d61535958c1) (let __tconst88d3359 const6b86b273ff34fce19d6b804e) (let __tconst8nL2368 const90fb9068eda6f2d68bb61c33)) (scan temp2BL61111 __t0UW1342 __t2xne366 __t3xwX335 __t4CVz374 __t65kJ367 __t6UsA373) (body (exists app (2 0 1) 1 __t65kJ367) (exists ref (1 0) 1 __tconst0pCN356) (exists ref (1 0) 1 __tconst3nEA343) (exists app (2 0 1) 1 __t0UW1342) (exists num (1 0) 1 __tconst88d3359) (exists ref (1 0) 1 __tconst3Nin376) (join ref (1 0) 1 __tconst8nL2368 __t5g5j369) (join app (1 2 0) 2 __t5g5j369 __t65kJ367 __t72Zs370) (join ref (1 0) 1 __tconst0pCN356 __t56Hj357) (join ref (1 0) 1 __tconst3nEA343 __t85N1344) (join app (1 2 0) 2 __t85N1344 __t0UW1342 __t6nY1345) (join num (1 0) 1 __tconst88d3359 __t29aP337) (join ref (1 0) 1 __tconst3Nin376 __t7cCj334) (let __t9cbk347 (lpush __t6UsA373 __t6nY1345))) (head (emit-temp temp3f2d1112 __t2xne366 __t3xwX335 __t4CVz374 __t72Zs370 __t9cbk347)) schemecfa.slog:12 #f)
  class ReadTask896 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex883;  slog::Index** refindex884;  slog::Index** refindex885;  slog::Index** appindex886;  slog::Index** numindex887;  slog::Index** refindex888;  slog::Index** refindex889;  slog::Index** appindex890;  slog::Index** refindex891;  slog::Index** refindex892;  slog::Index** appindex893;  slog::Index** numindex894;  slog::Index** refindex895;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3f2d1112");
      outer_rel = db->getRelation("temp2BL61111");
      std::vector<u16> ord897({2, 0, 1});
      slog::Relation* readrel898 = db->getRelation("app");
      appindex883 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({1, 0});
      slog::Relation* readrel900 = db->getRelation("ref");
      refindex884 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({1, 0});
      slog::Relation* readrel902 = db->getRelation("ref");
      refindex885 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({2, 0, 1});
      slog::Relation* readrel904 = db->getRelation("app");
      appindex886 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({1, 0});
      slog::Relation* readrel906 = db->getRelation("num");
      numindex887 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({1, 0});
      slog::Relation* readrel908 = db->getRelation("ref");
      refindex888 = readrel908->getIndex(ord907, false);
      std::vector<u16> ord909({1, 0});
      slog::Relation* readrel910 = db->getRelation("ref");
      refindex889 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({1, 2, 0});
      slog::Relation* readrel912 = db->getRelation("app");
      appindex890 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({1, 0});
      slog::Relation* readrel914 = db->getRelation("ref");
      refindex891 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({1, 0});
      slog::Relation* readrel916 = db->getRelation("ref");
      refindex892 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({1, 2, 0});
      slog::Relation* readrel918 = db->getRelation("app");
      appindex893 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({1, 0});
      slog::Relation* readrel920 = db->getRelation("num");
      numindex894 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({1, 0});
      slog::Relation* readrel922 = db->getRelation("ref");
      refindex895 = readrel922->getIndex(ord921, false);
  
    }
    ReadTask896(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_consta81ad7556291f9defc5163ec;
      u64 v_c24 = v_const0933fb667296882d8c45abca;
      u64 v_c25 = v_consted725292f5f32d61535958c1;
      u64 v_c26 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c28 = v_const90fb9068eda6f2d68bb61c33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c175 = _t[0];
        u64 v_c41 = _t[1];
        u64 v_c177 = _t[2];
        u64 v_c42 = _t[3];
        u64 v_c176 = _t[4];
        u64 v_c31 = _t[5];
        if (!slog::exists_probe<3,1>(appindex883, std::array<u64,3>{v_c176, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex884, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(refindex885, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<3,1>(appindex886, std::array<u64,3>{v_c175, 0, 0})) return;
        if (!slog::exists_probe<2,1>(numindex887, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(refindex888, std::array<u64,2>{v_c30, 0})) return;
        slog::join_probe<2,1>(refindex889, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m923) {
          u64 v_c32 = m923[1];
          slog::join_probe<3,2>(appindex890, std::array<u64,3>{v_c32, v_c176, 0}, [&](const std::array<u64,3>& m924) {
            u64 v_c212 = m924[2];
            slog::join_probe<2,1>(refindex891, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m925) {
              u64 v_c34 = m925[1];
              slog::join_probe<2,1>(refindex892, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m926) {
                u64 v_c35 = m926[1];
                slog::join_probe<3,2>(appindex893, std::array<u64,3>{v_c35, v_c175, 0}, [&](const std::array<u64,3>& m927) {
                  u64 v_c213 = m927[2];
                  slog::join_probe<2,1>(numindex894, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m928) {
                    u64 v_c37 = m928[1];
                    slog::join_probe<2,1>(refindex895, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m929) {
                      u64 v_c38 = m929[1];
                      u64 v_c214 = _prim_lpush(db, v_c31, v_c213);
                      if (v_c214 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:12"); return; }
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c41, v_c177, v_c42, v_c212, v_c214});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp2BL61111", _fires);
  
      if (!_done)
      {
        ReadTask896* _cont = new ReadTask896(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask896(db,b), false);
  // (crule (pre) (scan eval __t9HBz103 __t2D2o102 c) (body (exists eval (2 0 1) 1 c) (join $sup56712x86x0x0x0 (1 0 2 3 4) 2 c __t9HBz103 e1 e2 e3) (join if (1 3 2 0) 4 e1 e3 e2 __t2D2o102) (exists select_branch (2 3 0 1) 2 e2 e3) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t0Z2s104) (exists eval_ans (0 1) 1 __t0Z2s104) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t8m22105 __v0) (join eval_ans (0 1) 2 __t0Z2s104 __v0) (join select_branch_ans (0 1) 1 __t8m22105 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t6lGP106) (join eval_ans (0 1) 1 __t6lGP106 __v2)) (head (emit eval_ans (0 1) __t9HBz103 __v2)) interp.slog:87 #f)
  class ReadTask944 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex930;  slog::Index** $sup56712x86x0x0x0index931;  slog::Index** ifindex932;  slog::Index** select_branchindex933;  slog::Index** evalindex934;  slog::Index** eval_ansindex935;  slog::Index** select_branchindex936;  slog::Index** eval_ansindex937;  slog::Index** select_branch_ansindex938;  slog::Index** evalindex939;  slog::Index** eval_ansindex940;  slog::Index** evaldelta941;  slog::Index** select_branchdelta942;  slog::Index** evaldelta943;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord945({0, 1});
      slog::Relation* readrel946 = db->getRelation("eval_ans");
      head_index[0] = readrel946->getIndex(ord945, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord947({2, 0, 1});
      slog::Relation* readrel948 = db->getRelation("eval");
      evalindex930 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 0, 2, 3, 4});
      slog::Relation* readrel950 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index931 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({1, 3, 2, 0});
      slog::Relation* readrel952 = db->getRelation("if");
      ifindex932 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({2, 3, 0, 1});
      slog::Relation* readrel954 = db->getRelation("select_branch");
      select_branchindex933 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({1, 2, 0});
      slog::Relation* readrel956 = db->getRelation("eval");
      evalindex934 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({1, 2, 0});
      slog::Relation* readrel958 = db->getRelation("eval");
      evaldelta941 = readrel958->getIndex(ord957, true);
      std::vector<u16> ord959({0, 1});
      slog::Relation* readrel960 = db->getRelation("eval_ans");
      eval_ansindex935 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({2, 3, 0, 1});
      slog::Relation* readrel962 = db->getRelation("select_branch");
      select_branchindex936 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({2, 3, 0, 1});
      slog::Relation* readrel964 = db->getRelation("select_branch");
      select_branchdelta942 = readrel964->getIndex(ord963, true);
      std::vector<u16> ord965({0, 1});
      slog::Relation* readrel966 = db->getRelation("eval_ans");
      eval_ansindex937 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({0, 1});
      slog::Relation* readrel968 = db->getRelation("select_branch_ans");
      select_branch_ansindex938 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({1, 2, 0});
      slog::Relation* readrel970 = db->getRelation("eval");
      evalindex939 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({1, 2, 0});
      slog::Relation* readrel972 = db->getRelation("eval");
      evaldelta943 = readrel972->getIndex(ord971, true);
      std::vector<u16> ord973({0, 1});
      slog::Relation* readrel974 = db->getRelation("eval_ans");
      eval_ansindex940 = readrel974->getIndex(ord973, false);
  
    }
    ReadTask944(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c215 = _t[0];
        u64 v_c216 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex930, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index931, std::array<u64,5>{v_c2, v_c215, 0, 0, 0}, [&](const std::array<u64,5>& m975) {
          u64 v_c217 = m975[2]; u64 v_c61 = m975[3]; u64 v_c62 = m975[4];
          slog::join_probe<4,4>(ifindex932, std::array<u64,4>{v_c217, v_c62, v_c61, v_c216}, [&](const std::array<u64,4>& m976) {
            if (!slog::exists_probe<4,2>(select_branchindex933, std::array<u64,4>{v_c61, v_c62, 0, 0})) return;
            slog::join_probe_old<3,2>(evalindex934, evaldelta941, std::array<u64,3>{v_c217, v_c2, 0}, [&](const std::array<u64,3>& m977) {
              u64 v_c218 = m977[2];
              if (!slog::exists_probe<2,1>(eval_ansindex935, std::array<u64,2>{v_c218, 0})) return;
              slog::join_probe_old<4,2>(select_branchindex936, select_branchdelta942, std::array<u64,4>{v_c61, v_c62, 0, 0}, [&](const std::array<u64,4>& m978) {
                u64 v_c219 = m978[2]; u64 v_c3 = m978[3];
                slog::join_probe<2,2>(eval_ansindex937, std::array<u64,2>{v_c218, v_c3}, [&](const std::array<u64,2>& m979) {
                  slog::join_probe<2,1>(select_branch_ansindex938, std::array<u64,2>{v_c219, 0}, [&](const std::array<u64,2>& m980) {
                    u64 v_c187 = m980[1];
                    slog::join_probe_old<3,2>(evalindex939, evaldelta943, std::array<u64,3>{v_c187, v_c2, 0}, [&](const std::array<u64,3>& m981) {
                      u64 v_c220 = m981[2];
                      slog::join_probe<2,1>(eval_ansindex940, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m982) {
                        u64 v_c221 = m982[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c215, v_c221}, std::array<u16,2>{0, 1});
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
        ReadTask944* _cont = new ReadTask944(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask944(db,b), false);
  // (crule (pre) (scan lookup_ans __t5YK333 __v0) (body (join-old lookup (0 1 2) 1 (0 1 2) __t5YK333 x c) (exists eval (2 0 1) 1 c) (join-old ref (1 0) 1 (1 0) x __t8y8931) (join-old eval (1 2 0) 2 (1 2 0) __t8y8931 c __t0HZY32)) (head (emit eval_ans (0 1) __t0HZY32 __v0)) interp.slog:30 #f)
  class ReadTask990 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex983;  slog::Index** evalindex984;  slog::Index** refindex985;  slog::Index** evalindex986;  slog::Index** lookupdelta987;  slog::Index** refdelta988;  slog::Index** evaldelta989;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord991({0, 1});
      slog::Relation* readrel992 = db->getRelation("eval_ans");
      head_index[0] = readrel992->getIndex(ord991, false);
      outer_rel = db->getRelation("lookup_ans");
      std::vector<u16> ord993({0, 1, 2});
      slog::Relation* readrel994 = db->getRelation("lookup");
      lookupindex983 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({0, 1, 2});
      slog::Relation* readrel996 = db->getRelation("lookup");
      lookupdelta987 = readrel996->getIndex(ord995, true);
      std::vector<u16> ord997({2, 0, 1});
      slog::Relation* readrel998 = db->getRelation("eval");
      evalindex984 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({1, 0});
      slog::Relation* readrel1000 = db->getRelation("ref");
      refindex985 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({1, 0});
      slog::Relation* readrel1002 = db->getRelation("ref");
      refdelta988 = readrel1002->getIndex(ord1001, true);
      std::vector<u16> ord1003({1, 2, 0});
      slog::Relation* readrel1004 = db->getRelation("eval");
      evalindex986 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({1, 2, 0});
      slog::Relation* readrel1006 = db->getRelation("eval");
      evaldelta989 = readrel1006->getIndex(ord1005, true);
  
    }
    ReadTask990(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        slog::join_probe_old<3,1>(lookupindex983, lookupdelta987, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m1007) {
          u64 v_c1 = m1007[1]; u64 v_c2 = m1007[2];
          if (!slog::exists_probe<3,1>(evalindex984, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<2,1>(refindex985, refdelta988, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m1008) {
            u64 v_c4 = m1008[1];
            slog::join_probe_old<3,2>(evalindex986, evaldelta989, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m1009) {
              u64 v_c5 = m1009[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c3}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:lookup_ans", _fires);
  
      if (!_done)
      {
        ReadTask990* _cont = new ReadTask990(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask990(db,b), false);
  // (crule (pre) (scan app __t3r1r450 ef es) (body) (head (emit argument_list (0) es)) freevars.slog:33 #f)
  class ReadTask1010 : public slog::Task
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
      head_rel[0] = db->getRelation("argument_list");
      std::vector<u16> ord1011({0});
      slog::Relation* readrel1012 = db->getRelation("argument_list");
      head_index[0] = readrel1012->getIndex(ord1011, false);
      outer_rel = db->getRelation("app");
  
    }
    ReadTask1010(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c222 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c91 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c91}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:33", "delta:app", _fires);
  
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
  // (crule (pre) (scan eval __1E5R778 __t7zZ2181 c) (body (join-old eval (2 0 1) 1 (2 0 1) c __t3m2r182 er) (exists eval_ans (0 1) 1 __t3m2r182) (join-old letrec (0 2 1 3) 2 (0 2 1 3) __t7zZ2181 er x eb) (join-old eval_ans (0 1) 1 (0 1) __t3m2r182 vr)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:95 #f)
  class ReadTask1020 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1013;  slog::Index** eval_ansindex1014;  slog::Index** letrecindex1015;  slog::Index** eval_ansindex1016;  slog::Index** evaldelta1017;  slog::Index** letrecdelta1018;  slog::Index** eval_ansdelta1019;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1021({0, 1, 2});
      slog::Relation* readrel1022 = db->getRelation("binding");
      head_index[0] = readrel1022->getIndex(ord1021, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1023({0, 1, 2});
      slog::Relation* readrel1024 = db->getRelation("binding_event");
      head_index[1] = readrel1024->getIndex(ord1023, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1025({2, 0, 1});
      slog::Relation* readrel1026 = db->getRelation("eval");
      evalindex1013 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({2, 0, 1});
      slog::Relation* readrel1028 = db->getRelation("eval");
      evaldelta1017 = readrel1028->getIndex(ord1027, true);
      std::vector<u16> ord1029({0, 1});
      slog::Relation* readrel1030 = db->getRelation("eval_ans");
      eval_ansindex1014 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({0, 2, 1, 3});
      slog::Relation* readrel1032 = db->getRelation("letrec");
      letrecindex1015 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({0, 2, 1, 3});
      slog::Relation* readrel1034 = db->getRelation("letrec");
      letrecdelta1018 = readrel1034->getIndex(ord1033, true);
      std::vector<u16> ord1035({0, 1});
      slog::Relation* readrel1036 = db->getRelation("eval_ans");
      eval_ansindex1016 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({0, 1});
      slog::Relation* readrel1038 = db->getRelation("eval_ans");
      eval_ansdelta1019 = readrel1038->getIndex(ord1037, true);
  
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
        u64 v_c223 = _t[0];
        u64 v_c224 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(evalindex1013, evaldelta1017, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m1039) {
          u64 v_c225 = m1039[1]; u64 v_c171 = m1039[2];
          if (!slog::exists_probe<2,1>(eval_ansindex1014, std::array<u64,2>{v_c225, 0})) return;
          slog::join_probe_old<4,2>(letrecindex1015, letrecdelta1018, std::array<u64,4>{v_c224, v_c171, 0, 0}, [&](const std::array<u64,4>& m1040) {
            u64 v_c1 = m1040[2]; u64 v_c94 = m1040[3];
            slog::join_probe_old<2,1>(eval_ansindex1016, eval_ansdelta1019, std::array<u64,2>{v_c225, 0}, [&](const std::array<u64,2>& m1041) {
              u64 v_c174 = m1041[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c1, v_c2, v_c174}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c1, v_c2, v_c2}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:eval", _fires);
  
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
  // (crule (pre) (scan freevar_in_args x es) (body (join-old app (2 0 1) 1 (2 0 1) es __t2ZD3144 ef)) (head (emit freevar (0 1) x __t2ZD3144)) freevars.slog:13 #f)
  class ReadTask1044 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1042;  slog::Index** appdelta1043;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1045({0, 1});
      slog::Relation* readrel1046 = db->getRelation("freevar");
      head_index[0] = readrel1046->getIndex(ord1045, false);
      outer_rel = db->getRelation("freevar_in_args");
      std::vector<u16> ord1047({2, 0, 1});
      slog::Relation* readrel1048 = db->getRelation("app");
      appindex1042 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({2, 0, 1});
      slog::Relation* readrel1050 = db->getRelation("app");
      appdelta1043 = readrel1050->getIndex(ord1049, true);
  
    }
    ReadTask1044(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[0];
        u64 v_c91 = _t[1];
        slog::join_probe_old<3,1>(appindex1042, appdelta1043, std::array<u64,3>{v_c91, 0, 0}, [&](const std::array<u64,3>& m1051) {
          u64 v_c226 = m1051[1]; u64 v_c100 = m1051[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c226}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:freevar_in_args", _fires);
  
      if (!_done)
      {
        ReadTask1044* _cont = new ReadTask1044(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1044(db,b), false);
  // (crule (pre) (scan eval __t8IKz184 __t5RW1183 c) (body (join app (0 1 2) 1 __t5RW1183 ef es)) (head (emit $sup56712x41x0x0x0 (1 0 2 3) c __t8IKz184 ef es)) interp.slog:42 #f)
  class ReadTask1053 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1052;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x41x0x0x0");
      std::vector<u16> ord1054({1, 0, 2, 3});
      slog::Relation* readrel1055 = db->getRelation("$sup56712x41x0x0x0");
      head_index[0] = readrel1055->getIndex(ord1054, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1056({0, 1, 2});
      slog::Relation* readrel1057 = db->getRelation("app");
      appindex1052 = readrel1057->getIndex(ord1056, false);
  
    }
    ReadTask1053(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c227 = _t[0];
        u64 v_c228 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<3,1>(appindex1052, std::array<u64,3>{v_c228, 0, 0}, [&](const std::array<u64,3>& m1058) {
          u64 v_c100 = m1058[1]; u64 v_c91 = m1058[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c2, v_c227, v_c100, v_c91}, std::array<u16,4>{1, 0, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1053* _cont = new ReadTask1053(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1053(db,b), false);
  // (crule (pre (let __trid28Qd741 const342a69eb5a93251c8b7e179a) (let __trel7X6u742 constf6cdc3db4b71e0cdeda6912e) (let __tcol4g8x743 const6b86b273ff34fce19d6b804e) (let __trel7qwO744 constf6cdc3db4b71e0cdeda6912e) (let __tcol8jiL745 constd4735e3a265e16eee03f5971)) (scan eval __t8BCY386 e1 c) (body (exists eval_ans (0 1) 1 __t8BCY386) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __d0 e2 e3) (join eval_ans (0 1) 1 __t8BCY386 __v0)) (head (tycheck e2 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid28Qd741 __trel7X6u742 __tcol4g8x743 (1 2 3 4 0)) (tycheck e3 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct ref) (struct sym)) __trid28Qd741 __trel7qwO744 __tcol8jiL745 (1 2 3 4 0)) (mkstruct select_branch (1 2 3 0) __7pWz740 __v0 e2 e3)) interp.slog:87 #f)
  class ReadTask1071 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex1059;  slog::Index** $sup56712x86x0x0x0index1060;  slog::Index** eval_ansindex1061;
    u32 sid1062;  u32 sid1063;  u32 sid1064;  u32 sid1065;  u32 sid1066;  u32 sid1067;  u32 sid1068;  u32 sid1069;  u32 sid1070;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("select_branch");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1072({0, 1});
      slog::Relation* readrel1073 = db->getRelation("eval_ans");
      eval_ansindex1059 = readrel1073->getIndex(ord1072, false);
      std::vector<u16> ord1074({1, 2, 0, 3, 4});
      slog::Relation* readrel1075 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index1060 = readrel1075->getIndex(ord1074, false);
      std::vector<u16> ord1076({0, 1});
      slog::Relation* readrel1077 = db->getRelation("eval_ans");
      eval_ansindex1061 = readrel1077->getIndex(ord1076, false);
      sid1062 = db->getRelation("app")->getStructId();
      sid1063 = db->getRelation("boolean")->getStructId();
      sid1064 = db->getRelation("if")->getStructId();
      sid1065 = db->getRelation("lambda")->getStructId();
      sid1066 = db->getRelation("let")->getStructId();
      sid1067 = db->getRelation("letrec")->getStructId();
      sid1068 = db->getRelation("num")->getStructId();
      sid1069 = db->getRelation("ref")->getStructId();
      sid1070 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1071(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c229 = v_const342a69eb5a93251c8b7e179a;
      u64 v_c230 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c231 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c232 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c233 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c234 = _t[0];
        u64 v_c217 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(eval_ansindex1059, std::array<u64,2>{v_c234, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index1060, std::array<u64,5>{v_c2, v_c217, 0, 0, 0}, [&](const std::array<u64,5>& m1078) {
          u64 v_c235 = m1078[2]; u64 v_c61 = m1078[3]; u64 v_c62 = m1078[4];
          slog::join_probe<2,1>(eval_ansindex1061, std::array<u64,2>{v_c234, 0}, [&](const std::array<u64,2>& m1079) {
            u64 v_c3 = m1079[1];
            ++_fires;
            if (!((is_struct(v_c61) && (decode_struct_id(v_c61) == sid1062 || decode_struct_id(v_c61) == sid1063 || decode_struct_id(v_c61) == sid1064 || decode_struct_id(v_c61) == sid1065 || decode_struct_id(v_c61) == sid1066 || decode_struct_id(v_c61) == sid1067 || decode_struct_id(v_c61) == sid1068 || decode_struct_id(v_c61) == sid1069 || decode_struct_id(v_c61) == sid1070))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c229, v_c230, v_c231, v_c61}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!((is_struct(v_c62) && (decode_struct_id(v_c62) == sid1062 || decode_struct_id(v_c62) == sid1063 || decode_struct_id(v_c62) == sid1064 || decode_struct_id(v_c62) == sid1065 || decode_struct_id(v_c62) == sid1066 || decode_struct_id(v_c62) == sid1067 || decode_struct_id(v_c62) == sid1068 || decode_struct_id(v_c62) == sid1069 || decode_struct_id(v_c62) == sid1070))))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c229, v_c232, v_c233, v_c62}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c3, v_c61, v_c62}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1071* _cont = new ReadTask1071(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1071(db,b), false);
  // (crule (pre) (scan eval __4CVi731 __t9wPj297 c) (body (join-old app (0 1 2) 1 (0 1 2) __t9wPj297 ef es)) (head (mkstruct eval (1 2 0) __0uUI732 ef c)) interp.slog:48 #f)
  class ReadTask1082 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1080;  slog::Index** appdelta1081;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1083({0, 1, 2});
      slog::Relation* readrel1084 = db->getRelation("app");
      appindex1080 = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({0, 1, 2});
      slog::Relation* readrel1086 = db->getRelation("app");
      appdelta1081 = readrel1086->getIndex(ord1085, true);
  
    }
    ReadTask1082(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c236 = _t[0];
        u64 v_c237 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(appindex1080, appdelta1081, std::array<u64,3>{v_c237, 0, 0}, [&](const std::array<u64,3>& m1087) {
          u64 v_c100 = m1087[1]; u64 v_c91 = m1087[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c100, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1082* _cont = new ReadTask1082(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1082(db,b), false);
  // (crule (pre) (scan ref __t6Nsh224 x) (body (join-old eval (1 2 0) 1 (1 2 0) __t6Nsh224 c __t8VKv225)) (head (mkstruct lookup (1 2 0) __5TVo797 x c)) interp.slog:30 #f)
  class ReadTask1090 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1088;  slog::Index** evaldelta1089;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup");
      outer_rel = db->getRelation("ref");
      std::vector<u16> ord1091({1, 2, 0});
      slog::Relation* readrel1092 = db->getRelation("eval");
      evalindex1088 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({1, 2, 0});
      slog::Relation* readrel1094 = db->getRelation("eval");
      evaldelta1089 = readrel1094->getIndex(ord1093, true);
  
    }
    ReadTask1090(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c238 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe_old<3,1>(evalindex1088, evaldelta1089, std::array<u64,3>{v_c238, 0, 0}, [&](const std::array<u64,3>& m1095) {
          u64 v_c2 = m1095[1]; u64 v_c239 = m1095[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask1090* _cont = new ReadTask1090(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1090(db,b), false);
  // (crule (pre) (scan letrec __t0hKJ115 x er eb) (body (join-old eval (1 2 0) 1 (1 2 0) __t0hKJ115 c __t60Dg116)) (head (emit $sup56712x93x0x0x0 (0 1 2 3 4) __t60Dg116 c eb er x)) interp.slog:94 #f)
  class ReadTask1098 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1096;  slog::Index** evaldelta1097;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x93x0x0x0");
      std::vector<u16> ord1099({0, 1, 2, 3, 4});
      slog::Relation* readrel1100 = db->getRelation("$sup56712x93x0x0x0");
      head_index[0] = readrel1100->getIndex(ord1099, false);
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord1101({1, 2, 0});
      slog::Relation* readrel1102 = db->getRelation("eval");
      evalindex1096 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({1, 2, 0});
      slog::Relation* readrel1104 = db->getRelation("eval");
      evaldelta1097 = readrel1104->getIndex(ord1103, true);
  
    }
    ReadTask1098(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c240 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c171 = _t[2];
        u64 v_c94 = _t[3];
        slog::join_probe_old<3,1>(evalindex1096, evaldelta1097, std::array<u64,3>{v_c240, 0, 0}, [&](const std::array<u64,3>& m1105) {
          u64 v_c2 = m1105[1]; u64 v_c241 = m1105[2];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c241, v_c2, v_c94, v_c171, v_c1}, std::array<u16,5>{0, 1, 2, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:letrec", _fires);
  
      if (!_done)
      {
        ReadTask1098* _cont = new ReadTask1098(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1098(db,b), false);
  // (crule (pre) (scan app __t0nYt200 ef es) (body (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (exists tick (1 2 0) 1 __t0nYt200) (join $sup56712x41x0x0x0 (2 3 0 1) 2 ef es __d0 c) (exists eval_args (1 2 0) 2 es c) (exists tick (1 2 0) 2 __t0nYt200 c) (join eval (1 2 0) 2 ef c __t44Jo196) (exists eval_ans (0 1) 1 __t44Jo196) (join eval_args (1 2 0) 2 es c __t3i0k199) (exists eval_args_ans (0 1) 1 __t3i0k199) (join-old tick (1 2 0) 2 (1 2 0) __t0nYt200 c __t3z31201) (exists tick_ans (0 1) 1 __t3z31201) (join eval_ans (0 1) 1 __t44Jo196 __t4ROj198) (join eval_args_ans (0 1) 1 __t3i0k199 vs) (join tick_ans (0 1) 1 __t3z31201 __v0) (join closure (0 1 2) 1 __t4ROj198 __t2BTJ197 cb) (join lambda (0 1 2) 1 __t2BTJ197 xs eb)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
  class ReadTask1124 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1106;  slog::Index** eval_argsindex1107;  slog::Index** tickindex1108;  slog::Index** $sup56712x41x0x0x0index1109;  slog::Index** eval_argsindex1110;  slog::Index** tickindex1111;  slog::Index** evalindex1112;  slog::Index** eval_ansindex1113;  slog::Index** eval_argsindex1114;  slog::Index** eval_args_ansindex1115;  slog::Index** tickindex1116;  slog::Index** tick_ansindex1117;  slog::Index** eval_ansindex1118;  slog::Index** eval_args_ansindex1119;  slog::Index** tick_ansindex1120;  slog::Index** closureindex1121;  slog::Index** lambdaindex1122;  slog::Index** tickdelta1123;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1125({1, 2, 0});
      slog::Relation* readrel1126 = db->getRelation("eval");
      evalindex1106 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({1, 2, 0});
      slog::Relation* readrel1128 = db->getRelation("eval_args");
      eval_argsindex1107 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 2, 0});
      slog::Relation* readrel1130 = db->getRelation("tick");
      tickindex1108 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({2, 3, 0, 1});
      slog::Relation* readrel1132 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1109 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({1, 2, 0});
      slog::Relation* readrel1134 = db->getRelation("eval_args");
      eval_argsindex1110 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({1, 2, 0});
      slog::Relation* readrel1136 = db->getRelation("tick");
      tickindex1111 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({1, 2, 0});
      slog::Relation* readrel1138 = db->getRelation("eval");
      evalindex1112 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({0, 1});
      slog::Relation* readrel1140 = db->getRelation("eval_ans");
      eval_ansindex1113 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({1, 2, 0});
      slog::Relation* readrel1142 = db->getRelation("eval_args");
      eval_argsindex1114 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({0, 1});
      slog::Relation* readrel1144 = db->getRelation("eval_args_ans");
      eval_args_ansindex1115 = readrel1144->getIndex(ord1143, false);
      std::vector<u16> ord1145({1, 2, 0});
      slog::Relation* readrel1146 = db->getRelation("tick");
      tickindex1116 = readrel1146->getIndex(ord1145, false);
      std::vector<u16> ord1147({1, 2, 0});
      slog::Relation* readrel1148 = db->getRelation("tick");
      tickdelta1123 = readrel1148->getIndex(ord1147, true);
      std::vector<u16> ord1149({0, 1});
      slog::Relation* readrel1150 = db->getRelation("tick_ans");
      tick_ansindex1117 = readrel1150->getIndex(ord1149, false);
      std::vector<u16> ord1151({0, 1});
      slog::Relation* readrel1152 = db->getRelation("eval_ans");
      eval_ansindex1118 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({0, 1});
      slog::Relation* readrel1154 = db->getRelation("eval_args_ans");
      eval_args_ansindex1119 = readrel1154->getIndex(ord1153, false);
      std::vector<u16> ord1155({0, 1});
      slog::Relation* readrel1156 = db->getRelation("tick_ans");
      tick_ansindex1120 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({0, 1, 2});
      slog::Relation* readrel1158 = db->getRelation("closure");
      closureindex1121 = readrel1158->getIndex(ord1157, false);
      std::vector<u16> ord1159({0, 1, 2});
      slog::Relation* readrel1160 = db->getRelation("lambda");
      lambdaindex1122 = readrel1160->getIndex(ord1159, false);
  
    }
    ReadTask1124(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c242 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c91 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1106, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1107, std::array<u64,3>{v_c91, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1108, std::array<u64,3>{v_c242, 0, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index1109, std::array<u64,4>{v_c100, v_c91, 0, 0}, [&](const std::array<u64,4>& m1161) {
          u64 v_c235 = m1161[2]; u64 v_c2 = m1161[3];
          if (!slog::exists_probe<3,2>(eval_argsindex1110, std::array<u64,3>{v_c91, v_c2, 0})) return;
          if (!slog::exists_probe<3,2>(tickindex1111, std::array<u64,3>{v_c242, v_c2, 0})) return;
          slog::join_probe<3,2>(evalindex1112, std::array<u64,3>{v_c100, v_c2, 0}, [&](const std::array<u64,3>& m1162) {
            u64 v_c243 = m1162[2];
            if (!slog::exists_probe<2,1>(eval_ansindex1113, std::array<u64,2>{v_c243, 0})) return;
            slog::join_probe<3,2>(eval_argsindex1114, std::array<u64,3>{v_c91, v_c2, 0}, [&](const std::array<u64,3>& m1163) {
              u64 v_c244 = m1163[2];
              if (!slog::exists_probe<2,1>(eval_args_ansindex1115, std::array<u64,2>{v_c244, 0})) return;
              slog::join_probe_old<3,2>(tickindex1116, tickdelta1123, std::array<u64,3>{v_c242, v_c2, 0}, [&](const std::array<u64,3>& m1164) {
                u64 v_c245 = m1164[2];
                if (!slog::exists_probe<2,1>(tick_ansindex1117, std::array<u64,2>{v_c245, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1118, std::array<u64,2>{v_c243, 0}, [&](const std::array<u64,2>& m1165) {
                  u64 v_c246 = m1165[1];
                  slog::join_probe<2,1>(eval_args_ansindex1119, std::array<u64,2>{v_c244, 0}, [&](const std::array<u64,2>& m1166) {
                    u64 v_c105 = m1166[1];
                    slog::join_probe<2,1>(tick_ansindex1120, std::array<u64,2>{v_c245, 0}, [&](const std::array<u64,2>& m1167) {
                      u64 v_c3 = m1167[1];
                      slog::join_probe<3,1>(closureindex1121, std::array<u64,3>{v_c246, 0, 0}, [&](const std::array<u64,3>& m1168) {
                        u64 v_c247 = m1168[1]; u64 v_c96 = m1168[2];
                        slog::join_probe<3,1>(lambdaindex1122, std::array<u64,3>{v_c247, 0, 0}, [&](const std::array<u64,3>& m1169) {
                          u64 v_c93 = m1169[1]; u64 v_c94 = m1169[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c94, v_c3}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1124* _cont = new ReadTask1124(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1124(db,b), false);
  // (crule (pre) (scan letrec __t0H7q293 x er eb) (body (exists eval (1 2 0) 1 __t0H7q293) (exists eval (1 2 0) 1 er) (exists eval (1 2 0) 1 eb) (join $sup56712x93x0x0x0 (2 3 4 0 1) 3 eb er x __t5OlD294 c) (join-old eval (0 2 1) 3 (0 2 1) __t5OlD294 c __t0H7q293) (exists eval (1 2 0) 2 eb c) (join-old eval (1 2 0) 2 (1 2 0) er c __t9p2a295) (exists eval_ans (0 1) 1 __t9p2a295) (join-old eval (1 2 0) 2 (1 2 0) eb c __t32yp296) (exists eval_ans (0 1) 1 __t32yp296) (join eval_ans (0 1) 1 __t9p2a295 vr) (join eval_ans (0 1) 1 __t32yp296 v)) (head (emit eval_ans (0 1) __t5OlD294 v)) interp.slog:94 #f)
  class ReadTask1185 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1170;  slog::Index** evalindex1171;  slog::Index** evalindex1172;  slog::Index** $sup56712x93x0x0x0index1173;  slog::Index** evalindex1174;  slog::Index** evalindex1175;  slog::Index** evalindex1176;  slog::Index** eval_ansindex1177;  slog::Index** evalindex1178;  slog::Index** eval_ansindex1179;  slog::Index** eval_ansindex1180;  slog::Index** eval_ansindex1181;  slog::Index** evaldelta1182;  slog::Index** evaldelta1183;  slog::Index** evaldelta1184;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1186({0, 1});
      slog::Relation* readrel1187 = db->getRelation("eval_ans");
      head_index[0] = readrel1187->getIndex(ord1186, false);
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord1188({1, 2, 0});
      slog::Relation* readrel1189 = db->getRelation("eval");
      evalindex1170 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({1, 2, 0});
      slog::Relation* readrel1191 = db->getRelation("eval");
      evalindex1171 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({1, 2, 0});
      slog::Relation* readrel1193 = db->getRelation("eval");
      evalindex1172 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({2, 3, 4, 0, 1});
      slog::Relation* readrel1195 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index1173 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({0, 2, 1});
      slog::Relation* readrel1197 = db->getRelation("eval");
      evalindex1174 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({0, 2, 1});
      slog::Relation* readrel1199 = db->getRelation("eval");
      evaldelta1182 = readrel1199->getIndex(ord1198, true);
      std::vector<u16> ord1200({1, 2, 0});
      slog::Relation* readrel1201 = db->getRelation("eval");
      evalindex1175 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({1, 2, 0});
      slog::Relation* readrel1203 = db->getRelation("eval");
      evalindex1176 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({1, 2, 0});
      slog::Relation* readrel1205 = db->getRelation("eval");
      evaldelta1183 = readrel1205->getIndex(ord1204, true);
      std::vector<u16> ord1206({0, 1});
      slog::Relation* readrel1207 = db->getRelation("eval_ans");
      eval_ansindex1177 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({1, 2, 0});
      slog::Relation* readrel1209 = db->getRelation("eval");
      evalindex1178 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 2, 0});
      slog::Relation* readrel1211 = db->getRelation("eval");
      evaldelta1184 = readrel1211->getIndex(ord1210, true);
      std::vector<u16> ord1212({0, 1});
      slog::Relation* readrel1213 = db->getRelation("eval_ans");
      eval_ansindex1179 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({0, 1});
      slog::Relation* readrel1215 = db->getRelation("eval_ans");
      eval_ansindex1180 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({0, 1});
      slog::Relation* readrel1217 = db->getRelation("eval_ans");
      eval_ansindex1181 = readrel1217->getIndex(ord1216, false);
  
    }
    ReadTask1185(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c248 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c171 = _t[2];
        u64 v_c94 = _t[3];
        if (!slog::exists_probe<3,1>(evalindex1170, std::array<u64,3>{v_c248, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1171, std::array<u64,3>{v_c171, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1172, std::array<u64,3>{v_c94, 0, 0})) return;
        slog::join_probe<5,3>($sup56712x93x0x0x0index1173, std::array<u64,5>{v_c94, v_c171, v_c1, 0, 0}, [&](const std::array<u64,5>& m1218) {
          u64 v_c249 = m1218[3]; u64 v_c2 = m1218[4];
          slog::join_probe_old<3,3>(evalindex1174, evaldelta1182, std::array<u64,3>{v_c249, v_c2, v_c248}, [&](const std::array<u64,3>& m1219) {
            if (!slog::exists_probe<3,2>(evalindex1175, std::array<u64,3>{v_c94, v_c2, 0})) return;
            slog::join_probe_old<3,2>(evalindex1176, evaldelta1183, std::array<u64,3>{v_c171, v_c2, 0}, [&](const std::array<u64,3>& m1220) {
              u64 v_c250 = m1220[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1177, std::array<u64,2>{v_c250, 0})) return;
              slog::join_probe_old<3,2>(evalindex1178, evaldelta1184, std::array<u64,3>{v_c94, v_c2, 0}, [&](const std::array<u64,3>& m1221) {
                u64 v_c251 = m1221[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1179, std::array<u64,2>{v_c251, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1180, std::array<u64,2>{v_c250, 0}, [&](const std::array<u64,2>& m1222) {
                  u64 v_c174 = m1222[1];
                  slog::join_probe<2,1>(eval_ansindex1181, std::array<u64,2>{v_c251, 0}, [&](const std::array<u64,2>& m1223) {
                    u64 v_c208 = m1223[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c249, v_c208}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:letrec", _fires);
  
      if (!_done)
      {
        ReadTask1185* _cont = new ReadTask1185(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1185(db,b), false);
  // (crule (pre) (scan eval_ans __t3K5j208 v) (body (join-old eval (0 2 1) 1 (0 2 1) __t3K5j208 __v0 eb) (exists lambda (2 0 1) 1 eb) (join-old tick_ans (1 0) 1 (1 0) __v0 __t3KuN210) (join-old lambda (2 0 1) 1 (2 0 1) eb __t6hhS205 xs) (join-old closure (1 2 0) 1 (1 2 0) __t6hhS205 cb __t6XAE206) (join eval_ans (1 0) 1 __t6XAE206 __t1DkM204) (join-old eval (0 2 1) 1 (0 2 1) __t1DkM204 c ef) (exists eval (2 0 1) 1 c) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (join-old tick (0 2 1) 2 (0 2 1) __t3KuN210 c __t8x6E209) (exists app (0 1 2) 2 __t8x6E209 ef) (join-old eval (1 2 0) 2 (1 2 0) __t8x6E209 c __t9lTe203) (join-old $sup56712x41x0x0x0 (1 0 2 3) 3 (1 0 2 3) c __t9lTe203 ef es) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t58jO207) (join eval_args_ans (0 1) 1 __t58jO207 vs)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask1252 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1224;  slog::Index** lambdaindex1225;  slog::Index** tick_ansindex1226;  slog::Index** lambdaindex1227;  slog::Index** closureindex1228;  slog::Index** eval_ansindex1229;  slog::Index** evalindex1230;  slog::Index** evalindex1231;  slog::Index** $sup56712x41x0x0x0index1232;  slog::Index** appindex1233;  slog::Index** eval_argsindex1234;  slog::Index** tickindex1235;  slog::Index** appindex1236;  slog::Index** evalindex1237;  slog::Index** $sup56712x41x0x0x0index1238;  slog::Index** appindex1239;  slog::Index** eval_argsindex1240;  slog::Index** eval_args_ansindex1241;  slog::Index** evaldelta1242;  slog::Index** tick_ansdelta1243;  slog::Index** lambdadelta1244;  slog::Index** closuredelta1245;  slog::Index** evaldelta1246;  slog::Index** tickdelta1247;  slog::Index** evaldelta1248;  slog::Index** $sup56712x41x0x0x0delta1249;  slog::Index** appdelta1250;  slog::Index** eval_argsdelta1251;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1253({0, 1});
      slog::Relation* readrel1254 = db->getRelation("eval_ans");
      head_index[0] = readrel1254->getIndex(ord1253, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1255({0, 2, 1});
      slog::Relation* readrel1256 = db->getRelation("eval");
      evalindex1224 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({0, 2, 1});
      slog::Relation* readrel1258 = db->getRelation("eval");
      evaldelta1242 = readrel1258->getIndex(ord1257, true);
      std::vector<u16> ord1259({2, 0, 1});
      slog::Relation* readrel1260 = db->getRelation("lambda");
      lambdaindex1225 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({1, 0});
      slog::Relation* readrel1262 = db->getRelation("tick_ans");
      tick_ansindex1226 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({1, 0});
      slog::Relation* readrel1264 = db->getRelation("tick_ans");
      tick_ansdelta1243 = readrel1264->getIndex(ord1263, true);
      std::vector<u16> ord1265({2, 0, 1});
      slog::Relation* readrel1266 = db->getRelation("lambda");
      lambdaindex1227 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({2, 0, 1});
      slog::Relation* readrel1268 = db->getRelation("lambda");
      lambdadelta1244 = readrel1268->getIndex(ord1267, true);
      std::vector<u16> ord1269({1, 2, 0});
      slog::Relation* readrel1270 = db->getRelation("closure");
      closureindex1228 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({1, 2, 0});
      slog::Relation* readrel1272 = db->getRelation("closure");
      closuredelta1245 = readrel1272->getIndex(ord1271, true);
      std::vector<u16> ord1273({1, 0});
      slog::Relation* readrel1274 = db->getRelation("eval_ans");
      eval_ansindex1229 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({0, 2, 1});
      slog::Relation* readrel1276 = db->getRelation("eval");
      evalindex1230 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({0, 2, 1});
      slog::Relation* readrel1278 = db->getRelation("eval");
      evaldelta1246 = readrel1278->getIndex(ord1277, true);
      std::vector<u16> ord1279({2, 0, 1});
      slog::Relation* readrel1280 = db->getRelation("eval");
      evalindex1231 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({1, 2, 3, 0});
      slog::Relation* readrel1282 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1232 = readrel1282->getIndex(ord1281, false);
      std::vector<u16> ord1283({1, 2, 0});
      slog::Relation* readrel1284 = db->getRelation("app");
      appindex1233 = readrel1284->getIndex(ord1283, false);
      std::vector<u16> ord1285({2, 0, 1});
      slog::Relation* readrel1286 = db->getRelation("eval_args");
      eval_argsindex1234 = readrel1286->getIndex(ord1285, false);
      std::vector<u16> ord1287({0, 2, 1});
      slog::Relation* readrel1288 = db->getRelation("tick");
      tickindex1235 = readrel1288->getIndex(ord1287, false);
      std::vector<u16> ord1289({0, 2, 1});
      slog::Relation* readrel1290 = db->getRelation("tick");
      tickdelta1247 = readrel1290->getIndex(ord1289, true);
      std::vector<u16> ord1291({0, 1, 2});
      slog::Relation* readrel1292 = db->getRelation("app");
      appindex1236 = readrel1292->getIndex(ord1291, false);
      std::vector<u16> ord1293({1, 2, 0});
      slog::Relation* readrel1294 = db->getRelation("eval");
      evalindex1237 = readrel1294->getIndex(ord1293, false);
      std::vector<u16> ord1295({1, 2, 0});
      slog::Relation* readrel1296 = db->getRelation("eval");
      evaldelta1248 = readrel1296->getIndex(ord1295, true);
      std::vector<u16> ord1297({1, 0, 2, 3});
      slog::Relation* readrel1298 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1238 = readrel1298->getIndex(ord1297, false);
      std::vector<u16> ord1299({1, 0, 2, 3});
      slog::Relation* readrel1300 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0delta1249 = readrel1300->getIndex(ord1299, true);
      std::vector<u16> ord1301({0, 1, 2});
      slog::Relation* readrel1302 = db->getRelation("app");
      appindex1239 = readrel1302->getIndex(ord1301, false);
      std::vector<u16> ord1303({0, 1, 2});
      slog::Relation* readrel1304 = db->getRelation("app");
      appdelta1250 = readrel1304->getIndex(ord1303, true);
      std::vector<u16> ord1305({1, 2, 0});
      slog::Relation* readrel1306 = db->getRelation("eval_args");
      eval_argsindex1240 = readrel1306->getIndex(ord1305, false);
      std::vector<u16> ord1307({1, 2, 0});
      slog::Relation* readrel1308 = db->getRelation("eval_args");
      eval_argsdelta1251 = readrel1308->getIndex(ord1307, true);
      std::vector<u16> ord1309({0, 1});
      slog::Relation* readrel1310 = db->getRelation("eval_args_ans");
      eval_args_ansindex1241 = readrel1310->getIndex(ord1309, false);
  
    }
    ReadTask1252(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c207 = _t[0];
        u64 v_c208 = _t[1];
        slog::join_probe_old<3,1>(evalindex1224, evaldelta1242, std::array<u64,3>{v_c207, 0, 0}, [&](const std::array<u64,3>& m1311) {
          u64 v_c3 = m1311[1]; u64 v_c94 = m1311[2];
          if (!slog::exists_probe<3,1>(lambdaindex1225, std::array<u64,3>{v_c94, 0, 0})) return;
          slog::join_probe_old<2,1>(tick_ansindex1226, tick_ansdelta1243, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m1312) {
            u64 v_c200 = m1312[1];
            slog::join_probe_old<3,1>(lambdaindex1227, lambdadelta1244, std::array<u64,3>{v_c94, 0, 0}, [&](const std::array<u64,3>& m1313) {
              u64 v_c206 = m1313[1]; u64 v_c93 = m1313[2];
              slog::join_probe_old<3,1>(closureindex1228, closuredelta1245, std::array<u64,3>{v_c206, 0, 0}, [&](const std::array<u64,3>& m1314) {
                u64 v_c96 = m1314[1]; u64 v_c205 = m1314[2];
                slog::join_probe<2,1>(eval_ansindex1229, std::array<u64,2>{v_c205, 0}, [&](const std::array<u64,2>& m1315) {
                  u64 v_c203 = m1315[1];
                  slog::join_probe_old<3,1>(evalindex1230, evaldelta1246, std::array<u64,3>{v_c203, 0, 0}, [&](const std::array<u64,3>& m1316) {
                    u64 v_c2 = m1316[1]; u64 v_c100 = m1316[2];
                    if (!slog::exists_probe<3,1>(evalindex1231, std::array<u64,3>{v_c2, 0, 0})) return;
                    if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index1232, std::array<u64,4>{v_c2, v_c100, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(appindex1233, std::array<u64,3>{v_c100, 0, 0})) return;
                    if (!slog::exists_probe<3,1>(eval_argsindex1234, std::array<u64,3>{v_c2, 0, 0})) return;
                    slog::join_probe_old<3,2>(tickindex1235, tickdelta1247, std::array<u64,3>{v_c200, v_c2, 0}, [&](const std::array<u64,3>& m1317) {
                      u64 v_c201 = m1317[2];
                      if (!slog::exists_probe<3,2>(appindex1236, std::array<u64,3>{v_c201, v_c100, 0})) return;
                      slog::join_probe_old<3,2>(evalindex1237, evaldelta1248, std::array<u64,3>{v_c201, v_c2, 0}, [&](const std::array<u64,3>& m1318) {
                        u64 v_c202 = m1318[2];
                        slog::join_probe_old<4,3>($sup56712x41x0x0x0index1238, $sup56712x41x0x0x0delta1249, std::array<u64,4>{v_c2, v_c202, v_c100, 0}, [&](const std::array<u64,4>& m1319) {
                          u64 v_c91 = m1319[3];
                          slog::join_probe_old<3,3>(appindex1239, appdelta1250, std::array<u64,3>{v_c201, v_c100, v_c91}, [&](const std::array<u64,3>& m1320) {
                            slog::join_probe_old<3,2>(eval_argsindex1240, eval_argsdelta1251, std::array<u64,3>{v_c91, v_c2, 0}, [&](const std::array<u64,3>& m1321) {
                              u64 v_c204 = m1321[2];
                              slog::join_probe<2,1>(eval_args_ansindex1241, std::array<u64,2>{v_c204, 0}, [&](const std::array<u64,2>& m1322) {
                                u64 v_c105 = m1322[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c202, v_c208}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask1252* _cont = new ReadTask1252(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1252(db,b), false);
  // (crule (pre) (scan app __t5RW1183 ef es) (body (join-old eval (1 2 0) 1 (1 2 0) __t5RW1183 c __t8IKz184)) (head (emit $sup56712x41x0x0x0 (1 0 2 3) c __t8IKz184 ef es)) interp.slog:42 #f)
  class ReadTask1325 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1323;  slog::Index** evaldelta1324;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x41x0x0x0");
      std::vector<u16> ord1326({1, 0, 2, 3});
      slog::Relation* readrel1327 = db->getRelation("$sup56712x41x0x0x0");
      head_index[0] = readrel1327->getIndex(ord1326, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1328({1, 2, 0});
      slog::Relation* readrel1329 = db->getRelation("eval");
      evalindex1323 = readrel1329->getIndex(ord1328, false);
      std::vector<u16> ord1330({1, 2, 0});
      slog::Relation* readrel1331 = db->getRelation("eval");
      evaldelta1324 = readrel1331->getIndex(ord1330, true);
  
    }
    ReadTask1325(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c228 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c91 = _t[2];
        slog::join_probe_old<3,1>(evalindex1323, evaldelta1324, std::array<u64,3>{v_c228, 0, 0}, [&](const std::array<u64,3>& m1332) {
          u64 v_c2 = m1332[1]; u64 v_c227 = m1332[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c2, v_c227, v_c100, v_c91}, std::array<u16,4>{1, 0, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1325* _cont = new ReadTask1325(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1325(db,b), false);
  // (crule (pre (let __tconst7knU761 const0122baa3ac55f1b433944eb1) (let __tconst35kI244 const06abaa100ecef791ce028c56) (let _00024sqc59yj663 constd4735e3a265e16eee03f5971) (let _00024sqc7n8w664 const5feceb66ffc86f38d952786c) (let _00024sqc4sLR665 const6b86b273ff34fce19d6b804e) (let _00024sqo8MNY666 const5feceb66ffc86f38d952786c) (let _00024sqo0NcP667 const6b86b273ff34fce19d6b804e) (let _00024sqo0X3t668 const6b86b273ff34fce19d6b804e) (let _00024sqo6VJl669 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo6VJl669 __t1b46247 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo8MNY666 __t1b46247 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo0NcP667 __t1b46247 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo0X3t668 __t1b46247 _00024seq2) (exists _enum (1 0) 1 __tconst7knU761) (join delta (1 2 0) 2 __tconst35kI244 _00024seq2 __t7NfZ245) (join _enum (1 0) 1 __tconst7knU761 __t4Ufa242) (join boolval (0 1) 1 __t1b46247 b) (letp _00024sql4qXJ661 (aslst _00024seq2)) (let chk1uhT977 (llen _00024sql4qXJ661)) (eq _00024sqc59yj663 chk1uhT977) (letp chk3WOK978 (lref _00024sql4qXJ661 _00024sqc7n8w664)) (eq __t1b46247 chk3WOK978) (letp chk0vLC979 (lref _00024sql4qXJ661 _00024sqc4sLR665)) (eq __t1b46247 chk0vLC979)) (head (emit-temp temp3tnu962 __t7NfZ245) (mkstruct boolval (1 0) __t0oTa243 __t4Ufa242)) interp.slog:118 #f)
  class ReadTask1340 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1333;  slog::Index** $seq_atindex1334;  slog::Index** $seq_atrindex1335;  slog::Index** _enumindex1336;  slog::Index** deltaindex1337;  slog::Index** _enumindex1338;  slog::Index** boolvalindex1339;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3tnu962");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1341({1, 0, 2});
      slog::Relation* readrel1342 = db->getRelation("$seq_atr");
      driver_index = readrel1342->getIndex(ord1341, true);
      std::vector<u16> ord1343({1, 0, 2});
      slog::Relation* readrel1344 = db->getRelation("$seq_at");
      $seq_atindex1333 = readrel1344->getIndex(ord1343, false);
      std::vector<u16> ord1345({1, 0, 2});
      slog::Relation* readrel1346 = db->getRelation("$seq_at");
      $seq_atindex1334 = readrel1346->getIndex(ord1345, false);
      std::vector<u16> ord1347({1, 0, 2});
      slog::Relation* readrel1348 = db->getRelation("$seq_atr");
      $seq_atrindex1335 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({1, 0});
      slog::Relation* readrel1350 = db->getRelation("_enum");
      _enumindex1336 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({1, 2, 0});
      slog::Relation* readrel1352 = db->getRelation("delta");
      deltaindex1337 = readrel1352->getIndex(ord1351, false);
      std::vector<u16> ord1353({1, 0});
      slog::Relation* readrel1354 = db->getRelation("_enum");
      _enumindex1338 = readrel1354->getIndex(ord1353, false);
      std::vector<u16> ord1355({0, 1});
      slog::Relation* readrel1356 = db->getRelation("boolval");
      boolvalindex1339 = readrel1356->getIndex(ord1355, false);
  
    }
    ReadTask1340(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c108 = v_const06abaa100ecef791ce028c56;
      u64 v_c109 = v_constd4735e3a265e16eee03f5971;
      u64 v_c110 = v_const5feceb66ffc86f38d952786c;
      u64 v_c111 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c112 = v_const5feceb66ffc86f38d952786c;
      u64 v_c113 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c114 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c115, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1357) {
        u64 v_c116 = m1357[1];
        u64 v_c16 = m1357[2];
        if (buckethash(v_c116) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1333, std::array<u64,3>{v_c112, v_c116, v_c16}, [&](const std::array<u64,3>& m1358) {
          slog::join_probe<3,3>($seq_atindex1334, std::array<u64,3>{v_c113, v_c116, v_c16}, [&](const std::array<u64,3>& m1359) {
            slog::join_probe<3,3>($seq_atrindex1335, std::array<u64,3>{v_c114, v_c116, v_c16}, [&](const std::array<u64,3>& m1360) {
              if (!slog::exists_probe<2,1>(_enumindex1336, std::array<u64,2>{v_c107, 0})) return;
              slog::join_probe<3,2>(deltaindex1337, std::array<u64,3>{v_c108, v_c16, 0}, [&](const std::array<u64,3>& m1361) {
                u64 v_c117 = m1361[2];
                slog::join_probe<2,1>(_enumindex1338, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m1362) {
                  u64 v_c118 = m1362[1];
                  slog::join_probe<2,1>(boolvalindex1339, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m1363) {
                    u64 v_c18 = m1363[1];
                    bool ok1364 = true;
                    u64 v_c119 = _prim_aslst(db, v_c16, &ok1364);
                    if (!ok1364) return;
                    u64 v_c252 = _prim_llen(db, v_c119);
                    if (v_c252 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c109 != v_c252) return;
                    bool ok1365 = true;
                    u64 v_c253 = _prim_lref(db, v_c119, v_c110, &ok1365);
                    if (!ok1365) return;
                    if (v_c116 != v_c253) return;
                    bool ok1366 = true;
                    u64 v_c254 = _prim_lref(db, v_c119, v_c111, &ok1366);
                    if (!ok1366) return;
                    if (v_c116 != v_c254) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c117});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c118}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1340* _cont = new ReadTask1340(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1340(db,b), false);
  // (crule (pre) (scan eval __4cUN684 __t8j7u29 c) (body (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (join-old tick_ans (0 1) 1 (0 1) __t0DSy30 l) (join-old eval (2 0 1) 1 (2 0 1) c __t5MCM24 ef) (exists eval_ans (0 1) 1 __t5MCM24) (join-old app (0 1 2) 2 (0 1 2) __t8j7u29 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join-old eval_ans (0 1) 1 (0 1) __t5MCM24 __t3Pto26) (join-old eval_args_ans (0 1) 1 (0 1) __t5BFX27 vs) (join-old closure (0 1 2) 1 (0 1 2) __t3Pto26 __t0xip28 cb) (exists binding (1 0 2) 1 cb) (join-old freevar (1 0) 1 (1 0) __t0xip28 y) (join-old binding (0 1 2) 2 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask1394 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1367;  slog::Index** eval_argsindex1368;  slog::Index** tickindex1369;  slog::Index** tick_ansindex1370;  slog::Index** evalindex1371;  slog::Index** eval_ansindex1372;  slog::Index** appindex1373;  slog::Index** eval_argsindex1374;  slog::Index** eval_args_ansindex1375;  slog::Index** eval_ansindex1376;  slog::Index** eval_args_ansindex1377;  slog::Index** closureindex1378;  slog::Index** bindingindex1379;  slog::Index** freevarindex1380;  slog::Index** bindingindex1381;  slog::Index** lambdaindex1382;  slog::Index** tickdelta1383;  slog::Index** tick_ansdelta1384;  slog::Index** evaldelta1385;  slog::Index** appdelta1386;  slog::Index** eval_argsdelta1387;  slog::Index** eval_ansdelta1388;  slog::Index** eval_args_ansdelta1389;  slog::Index** closuredelta1390;  slog::Index** freevardelta1391;  slog::Index** bindingdelta1392;  slog::Index** lambdadelta1393;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1395({0, 1, 2});
      slog::Relation* readrel1396 = db->getRelation("binding");
      head_index[0] = readrel1396->getIndex(ord1395, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1397({0, 1, 2});
      slog::Relation* readrel1398 = db->getRelation("binding_event");
      head_index[1] = readrel1398->getIndex(ord1397, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1399({2, 0, 1});
      slog::Relation* readrel1400 = db->getRelation("eval");
      evalindex1367 = readrel1400->getIndex(ord1399, false);
      std::vector<u16> ord1401({2, 0, 1});
      slog::Relation* readrel1402 = db->getRelation("eval_args");
      eval_argsindex1368 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({1, 2, 0});
      slog::Relation* readrel1404 = db->getRelation("tick");
      tickindex1369 = readrel1404->getIndex(ord1403, false);
      std::vector<u16> ord1405({1, 2, 0});
      slog::Relation* readrel1406 = db->getRelation("tick");
      tickdelta1383 = readrel1406->getIndex(ord1405, true);
      std::vector<u16> ord1407({0, 1});
      slog::Relation* readrel1408 = db->getRelation("tick_ans");
      tick_ansindex1370 = readrel1408->getIndex(ord1407, false);
      std::vector<u16> ord1409({0, 1});
      slog::Relation* readrel1410 = db->getRelation("tick_ans");
      tick_ansdelta1384 = readrel1410->getIndex(ord1409, true);
      std::vector<u16> ord1411({2, 0, 1});
      slog::Relation* readrel1412 = db->getRelation("eval");
      evalindex1371 = readrel1412->getIndex(ord1411, false);
      std::vector<u16> ord1413({2, 0, 1});
      slog::Relation* readrel1414 = db->getRelation("eval");
      evaldelta1385 = readrel1414->getIndex(ord1413, true);
      std::vector<u16> ord1415({0, 1});
      slog::Relation* readrel1416 = db->getRelation("eval_ans");
      eval_ansindex1372 = readrel1416->getIndex(ord1415, false);
      std::vector<u16> ord1417({0, 1, 2});
      slog::Relation* readrel1418 = db->getRelation("app");
      appindex1373 = readrel1418->getIndex(ord1417, false);
      std::vector<u16> ord1419({0, 1, 2});
      slog::Relation* readrel1420 = db->getRelation("app");
      appdelta1386 = readrel1420->getIndex(ord1419, true);
      std::vector<u16> ord1421({1, 2, 0});
      slog::Relation* readrel1422 = db->getRelation("eval_args");
      eval_argsindex1374 = readrel1422->getIndex(ord1421, false);
      std::vector<u16> ord1423({1, 2, 0});
      slog::Relation* readrel1424 = db->getRelation("eval_args");
      eval_argsdelta1387 = readrel1424->getIndex(ord1423, true);
      std::vector<u16> ord1425({0, 1});
      slog::Relation* readrel1426 = db->getRelation("eval_args_ans");
      eval_args_ansindex1375 = readrel1426->getIndex(ord1425, false);
      std::vector<u16> ord1427({0, 1});
      slog::Relation* readrel1428 = db->getRelation("eval_ans");
      eval_ansindex1376 = readrel1428->getIndex(ord1427, false);
      std::vector<u16> ord1429({0, 1});
      slog::Relation* readrel1430 = db->getRelation("eval_ans");
      eval_ansdelta1388 = readrel1430->getIndex(ord1429, true);
      std::vector<u16> ord1431({0, 1});
      slog::Relation* readrel1432 = db->getRelation("eval_args_ans");
      eval_args_ansindex1377 = readrel1432->getIndex(ord1431, false);
      std::vector<u16> ord1433({0, 1});
      slog::Relation* readrel1434 = db->getRelation("eval_args_ans");
      eval_args_ansdelta1389 = readrel1434->getIndex(ord1433, true);
      std::vector<u16> ord1435({0, 1, 2});
      slog::Relation* readrel1436 = db->getRelation("closure");
      closureindex1378 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({0, 1, 2});
      slog::Relation* readrel1438 = db->getRelation("closure");
      closuredelta1390 = readrel1438->getIndex(ord1437, true);
      std::vector<u16> ord1439({1, 0, 2});
      slog::Relation* readrel1440 = db->getRelation("binding");
      bindingindex1379 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({1, 0});
      slog::Relation* readrel1442 = db->getRelation("freevar");
      freevarindex1380 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({1, 0});
      slog::Relation* readrel1444 = db->getRelation("freevar");
      freevardelta1391 = readrel1444->getIndex(ord1443, true);
      std::vector<u16> ord1445({0, 1, 2});
      slog::Relation* readrel1446 = db->getRelation("binding");
      bindingindex1381 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({0, 1, 2});
      slog::Relation* readrel1448 = db->getRelation("binding");
      bindingdelta1392 = readrel1448->getIndex(ord1447, true);
      std::vector<u16> ord1449({0, 1, 2});
      slog::Relation* readrel1450 = db->getRelation("lambda");
      lambdaindex1382 = readrel1450->getIndex(ord1449, false);
      std::vector<u16> ord1451({0, 1, 2});
      slog::Relation* readrel1452 = db->getRelation("lambda");
      lambdadelta1393 = readrel1452->getIndex(ord1451, true);
  
    }
    ReadTask1394(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c101 = _t[0];
        u64 v_c102 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1367, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1368, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe_old<3,2>(tickindex1369, tickdelta1383, std::array<u64,3>{v_c102, v_c2, 0}, [&](const std::array<u64,3>& m1453) {
          u64 v_c104 = m1453[2];
          slog::join_probe_old<2,1>(tick_ansindex1370, tick_ansdelta1384, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m1454) {
            u64 v_c106 = m1454[1];
            slog::join_probe_old<3,1>(evalindex1371, evaldelta1385, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m1455) {
              u64 v_c99 = m1455[1]; u64 v_c100 = m1455[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1372, std::array<u64,2>{v_c99, 0})) return;
              slog::join_probe_old<3,2>(appindex1373, appdelta1386, std::array<u64,3>{v_c102, v_c100, 0}, [&](const std::array<u64,3>& m1456) {
                u64 v_c91 = m1456[2];
                slog::join_probe_old<3,2>(eval_argsindex1374, eval_argsdelta1387, std::array<u64,3>{v_c91, v_c2, 0}, [&](const std::array<u64,3>& m1457) {
                  u64 v_c103 = m1457[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1375, std::array<u64,2>{v_c103, 0})) return;
                  slog::join_probe_old<2,1>(eval_ansindex1376, eval_ansdelta1388, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m1458) {
                    u64 v_c98 = m1458[1];
                    slog::join_probe_old<2,1>(eval_args_ansindex1377, eval_args_ansdelta1389, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m1459) {
                      u64 v_c105 = m1459[1];
                      slog::join_probe_old<3,1>(closureindex1378, closuredelta1390, std::array<u64,3>{v_c98, 0, 0}, [&](const std::array<u64,3>& m1460) {
                        u64 v_c92 = m1460[1]; u64 v_c96 = m1460[2];
                        if (!slog::exists_probe<3,1>(bindingindex1379, std::array<u64,3>{v_c96, 0, 0})) return;
                        slog::join_probe_old<2,1>(freevarindex1380, freevardelta1391, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m1461) {
                          u64 v_c95 = m1461[1];
                          slog::join_probe_old<3,2>(bindingindex1381, bindingdelta1392, std::array<u64,3>{v_c95, v_c96, 0}, [&](const std::array<u64,3>& m1462) {
                            u64 v_c97 = m1462[2];
                            slog::join_probe_old<3,1>(lambdaindex1382, lambdadelta1393, std::array<u64,3>{v_c92, 0, 0}, [&](const std::array<u64,3>& m1463) {
                              u64 v_c93 = m1463[1]; u64 v_c94 = m1463[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c95, v_c106, v_c97}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c95, v_c106, v_c2}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1394* _cont = new ReadTask1394(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1394(db,b), false);
  // (crule (pre) (scan temp3czf982 __t2W25447 __t6A6H446) (body) (head (emit eval_args_ans (0 1) __t2W25447 __t6A6H446)) interp.slog:38 #f)
  class ReadTask1464 : public slog::Task
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
      head_rel[0] = db->getRelation("eval_args_ans");
      std::vector<u16> ord1465({0, 1});
      slog::Relation* readrel1466 = db->getRelation("eval_args_ans");
      head_index[0] = readrel1466->getIndex(ord1465, false);
      outer_rel = db->getRelation("temp3czf982");
  
    }
    ReadTask1464(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c184 = _t[0];
        u64 v_c255 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c184, v_c255}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:temp3czf982", _fires);
  
      if (!_done)
      {
        ReadTask1464* _cont = new ReadTask1464(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1464(db,b), false);
  // (crule (pre) (scan freevar y __t0xip28) (body (exists closure (1 2 0) 1 __t0xip28) (join-old binding (0 1 2) 1 (0 1 2) y cb vy) (join-old closure (1 2 0) 2 (1 2 0) __t0xip28 cb __t3Pto26) (join eval_ans (1 0) 1 __t3Pto26 __t5MCM24) (join-old eval (0 2 1) 1 (0 2 1) __t5MCM24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __4cUN684 __t8j7u29) (exists tick (1 2 0) 2 __t8j7u29 c) (join-old app (0 1 2) 2 (0 1 2) __t8j7u29 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (exists tick_ans (0 1) 1 __t0DSy30) (join eval_args_ans (0 1) 1 __t5BFX27 vs) (join-old tick_ans (0 1) 1 (0 1) __t0DSy30 l) (join-old lambda (0 1 2) 1 (0 1 2) __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask1493 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex1467;  slog::Index** bindingindex1468;  slog::Index** closureindex1469;  slog::Index** eval_ansindex1470;  slog::Index** evalindex1471;  slog::Index** appindex1472;  slog::Index** eval_argsindex1473;  slog::Index** tickindex1474;  slog::Index** evalindex1475;  slog::Index** tickindex1476;  slog::Index** appindex1477;  slog::Index** eval_argsindex1478;  slog::Index** eval_args_ansindex1479;  slog::Index** tickindex1480;  slog::Index** tick_ansindex1481;  slog::Index** eval_args_ansindex1482;  slog::Index** tick_ansindex1483;  slog::Index** lambdaindex1484;  slog::Index** bindingdelta1485;  slog::Index** closuredelta1486;  slog::Index** evaldelta1487;  slog::Index** appdelta1488;  slog::Index** eval_argsdelta1489;  slog::Index** tickdelta1490;  slog::Index** tick_ansdelta1491;  slog::Index** lambdadelta1492;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord1494({0, 1, 2});
      slog::Relation* readrel1495 = db->getRelation("binding");
      head_index[0] = readrel1495->getIndex(ord1494, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord1496({0, 1, 2});
      slog::Relation* readrel1497 = db->getRelation("binding_event");
      head_index[1] = readrel1497->getIndex(ord1496, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1498({1, 2, 0});
      slog::Relation* readrel1499 = db->getRelation("closure");
      closureindex1467 = readrel1499->getIndex(ord1498, false);
      std::vector<u16> ord1500({0, 1, 2});
      slog::Relation* readrel1501 = db->getRelation("binding");
      bindingindex1468 = readrel1501->getIndex(ord1500, false);
      std::vector<u16> ord1502({0, 1, 2});
      slog::Relation* readrel1503 = db->getRelation("binding");
      bindingdelta1485 = readrel1503->getIndex(ord1502, true);
      std::vector<u16> ord1504({1, 2, 0});
      slog::Relation* readrel1505 = db->getRelation("closure");
      closureindex1469 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({1, 2, 0});
      slog::Relation* readrel1507 = db->getRelation("closure");
      closuredelta1486 = readrel1507->getIndex(ord1506, true);
      std::vector<u16> ord1508({1, 0});
      slog::Relation* readrel1509 = db->getRelation("eval_ans");
      eval_ansindex1470 = readrel1509->getIndex(ord1508, false);
      std::vector<u16> ord1510({0, 2, 1});
      slog::Relation* readrel1511 = db->getRelation("eval");
      evalindex1471 = readrel1511->getIndex(ord1510, false);
      std::vector<u16> ord1512({0, 2, 1});
      slog::Relation* readrel1513 = db->getRelation("eval");
      evaldelta1487 = readrel1513->getIndex(ord1512, true);
      std::vector<u16> ord1514({1, 2, 0});
      slog::Relation* readrel1515 = db->getRelation("app");
      appindex1472 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({2, 0, 1});
      slog::Relation* readrel1517 = db->getRelation("eval_args");
      eval_argsindex1473 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({2, 0, 1});
      slog::Relation* readrel1519 = db->getRelation("tick");
      tickindex1474 = readrel1519->getIndex(ord1518, false);
      std::vector<u16> ord1520({2, 0, 1});
      slog::Relation* readrel1521 = db->getRelation("eval");
      evalindex1475 = readrel1521->getIndex(ord1520, false);
      std::vector<u16> ord1522({1, 2, 0});
      slog::Relation* readrel1523 = db->getRelation("tick");
      tickindex1476 = readrel1523->getIndex(ord1522, false);
      std::vector<u16> ord1524({0, 1, 2});
      slog::Relation* readrel1525 = db->getRelation("app");
      appindex1477 = readrel1525->getIndex(ord1524, false);
      std::vector<u16> ord1526({0, 1, 2});
      slog::Relation* readrel1527 = db->getRelation("app");
      appdelta1488 = readrel1527->getIndex(ord1526, true);
      std::vector<u16> ord1528({1, 2, 0});
      slog::Relation* readrel1529 = db->getRelation("eval_args");
      eval_argsindex1478 = readrel1529->getIndex(ord1528, false);
      std::vector<u16> ord1530({1, 2, 0});
      slog::Relation* readrel1531 = db->getRelation("eval_args");
      eval_argsdelta1489 = readrel1531->getIndex(ord1530, true);
      std::vector<u16> ord1532({0, 1});
      slog::Relation* readrel1533 = db->getRelation("eval_args_ans");
      eval_args_ansindex1479 = readrel1533->getIndex(ord1532, false);
      std::vector<u16> ord1534({1, 2, 0});
      slog::Relation* readrel1535 = db->getRelation("tick");
      tickindex1480 = readrel1535->getIndex(ord1534, false);
      std::vector<u16> ord1536({1, 2, 0});
      slog::Relation* readrel1537 = db->getRelation("tick");
      tickdelta1490 = readrel1537->getIndex(ord1536, true);
      std::vector<u16> ord1538({0, 1});
      slog::Relation* readrel1539 = db->getRelation("tick_ans");
      tick_ansindex1481 = readrel1539->getIndex(ord1538, false);
      std::vector<u16> ord1540({0, 1});
      slog::Relation* readrel1541 = db->getRelation("eval_args_ans");
      eval_args_ansindex1482 = readrel1541->getIndex(ord1540, false);
      std::vector<u16> ord1542({0, 1});
      slog::Relation* readrel1543 = db->getRelation("tick_ans");
      tick_ansindex1483 = readrel1543->getIndex(ord1542, false);
      std::vector<u16> ord1544({0, 1});
      slog::Relation* readrel1545 = db->getRelation("tick_ans");
      tick_ansdelta1491 = readrel1545->getIndex(ord1544, true);
      std::vector<u16> ord1546({0, 1, 2});
      slog::Relation* readrel1547 = db->getRelation("lambda");
      lambdaindex1484 = readrel1547->getIndex(ord1546, false);
      std::vector<u16> ord1548({0, 1, 2});
      slog::Relation* readrel1549 = db->getRelation("lambda");
      lambdadelta1492 = readrel1549->getIndex(ord1548, true);
  
    }
    ReadTask1493(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c95 = _t[0];
        u64 v_c92 = _t[1];
        if (!slog::exists_probe<3,1>(closureindex1467, std::array<u64,3>{v_c92, 0, 0})) return;
        slog::join_probe_old<3,1>(bindingindex1468, bindingdelta1485, std::array<u64,3>{v_c95, 0, 0}, [&](const std::array<u64,3>& m1550) {
          u64 v_c96 = m1550[1]; u64 v_c97 = m1550[2];
          slog::join_probe_old<3,2>(closureindex1469, closuredelta1486, std::array<u64,3>{v_c92, v_c96, 0}, [&](const std::array<u64,3>& m1551) {
            u64 v_c98 = m1551[2];
            slog::join_probe<2,1>(eval_ansindex1470, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m1552) {
              u64 v_c99 = m1552[1];
              slog::join_probe_old<3,1>(evalindex1471, evaldelta1487, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m1553) {
                u64 v_c2 = m1553[1]; u64 v_c100 = m1553[2];
                if (!slog::exists_probe<3,1>(appindex1472, std::array<u64,3>{v_c100, 0, 0})) return;
                if (!slog::exists_probe<3,1>(eval_argsindex1473, std::array<u64,3>{v_c2, 0, 0})) return;
                if (!slog::exists_probe<3,1>(tickindex1474, std::array<u64,3>{v_c2, 0, 0})) return;
                slog::join_probe<3,1>(evalindex1475, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m1554) {
                  u64 v_c101 = m1554[1]; u64 v_c102 = m1554[2];
                  if (!slog::exists_probe<3,2>(tickindex1476, std::array<u64,3>{v_c102, v_c2, 0})) return;
                  slog::join_probe_old<3,2>(appindex1477, appdelta1488, std::array<u64,3>{v_c102, v_c100, 0}, [&](const std::array<u64,3>& m1555) {
                    u64 v_c91 = m1555[2];
                    slog::join_probe_old<3,2>(eval_argsindex1478, eval_argsdelta1489, std::array<u64,3>{v_c91, v_c2, 0}, [&](const std::array<u64,3>& m1556) {
                      u64 v_c103 = m1556[2];
                      if (!slog::exists_probe<2,1>(eval_args_ansindex1479, std::array<u64,2>{v_c103, 0})) return;
                      slog::join_probe_old<3,2>(tickindex1480, tickdelta1490, std::array<u64,3>{v_c102, v_c2, 0}, [&](const std::array<u64,3>& m1557) {
                        u64 v_c104 = m1557[2];
                        if (!slog::exists_probe<2,1>(tick_ansindex1481, std::array<u64,2>{v_c104, 0})) return;
                        slog::join_probe<2,1>(eval_args_ansindex1482, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m1558) {
                          u64 v_c105 = m1558[1];
                          slog::join_probe_old<2,1>(tick_ansindex1483, tick_ansdelta1491, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m1559) {
                            u64 v_c106 = m1559[1];
                            slog::join_probe_old<3,1>(lambdaindex1484, lambdadelta1492, std::array<u64,3>{v_c92, 0, 0}, [&](const std::array<u64,3>& m1560) {
                              u64 v_c93 = m1560[1]; u64 v_c94 = m1560[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c95, v_c106, v_c97}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c95, v_c106, v_c2}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1493* _cont = new ReadTask1493(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1493(db,b), false);
  // (crule (pre) (scan eval __t0jgp442 er c) (body (exists let (2 1 3 0) 1 er) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t0jgp442) (join $sup56712x91x0x0x0 (1 3 0 2 4) 2 c er __t1bnm441 eb x) (exists eval (0 2 1) 2 __t1bnm441 c) (exists eval (1 2 0) 2 eb c) (join let (2 1 3 0) 3 er x eb __t0DPj440) (join eval (0 2 1) 3 __t1bnm441 c __t0DPj440) (join-old eval (1 2 0) 2 (1 2 0) eb c __t9j6S443) (exists eval_ans (0 1) 1 __t9j6S443) (join eval_ans (0 1) 1 __t0jgp442 vr) (join eval_ans (0 1) 1 __t9j6S443 v)) (head (emit eval_ans (0 1) __t1bnm441 v)) interp.slog:92 #f)
  class ReadTask1574 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1561;  slog::Index** evalindex1562;  slog::Index** eval_ansindex1563;  slog::Index** $sup56712x91x0x0x0index1564;  slog::Index** evalindex1565;  slog::Index** evalindex1566;  slog::Index** letindex1567;  slog::Index** evalindex1568;  slog::Index** evalindex1569;  slog::Index** eval_ansindex1570;  slog::Index** eval_ansindex1571;  slog::Index** eval_ansindex1572;  slog::Index** evaldelta1573;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1575({0, 1});
      slog::Relation* readrel1576 = db->getRelation("eval_ans");
      head_index[0] = readrel1576->getIndex(ord1575, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1577({2, 1, 3, 0});
      slog::Relation* readrel1578 = db->getRelation("let");
      letindex1561 = readrel1578->getIndex(ord1577, false);
      std::vector<u16> ord1579({2, 0, 1});
      slog::Relation* readrel1580 = db->getRelation("eval");
      evalindex1562 = readrel1580->getIndex(ord1579, false);
      std::vector<u16> ord1581({0, 1});
      slog::Relation* readrel1582 = db->getRelation("eval_ans");
      eval_ansindex1563 = readrel1582->getIndex(ord1581, false);
      std::vector<u16> ord1583({1, 3, 0, 2, 4});
      slog::Relation* readrel1584 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index1564 = readrel1584->getIndex(ord1583, false);
      std::vector<u16> ord1585({0, 2, 1});
      slog::Relation* readrel1586 = db->getRelation("eval");
      evalindex1565 = readrel1586->getIndex(ord1585, false);
      std::vector<u16> ord1587({1, 2, 0});
      slog::Relation* readrel1588 = db->getRelation("eval");
      evalindex1566 = readrel1588->getIndex(ord1587, false);
      std::vector<u16> ord1589({2, 1, 3, 0});
      slog::Relation* readrel1590 = db->getRelation("let");
      letindex1567 = readrel1590->getIndex(ord1589, false);
      std::vector<u16> ord1591({0, 2, 1});
      slog::Relation* readrel1592 = db->getRelation("eval");
      evalindex1568 = readrel1592->getIndex(ord1591, false);
      std::vector<u16> ord1593({1, 2, 0});
      slog::Relation* readrel1594 = db->getRelation("eval");
      evalindex1569 = readrel1594->getIndex(ord1593, false);
      std::vector<u16> ord1595({1, 2, 0});
      slog::Relation* readrel1596 = db->getRelation("eval");
      evaldelta1573 = readrel1596->getIndex(ord1595, true);
      std::vector<u16> ord1597({0, 1});
      slog::Relation* readrel1598 = db->getRelation("eval_ans");
      eval_ansindex1570 = readrel1598->getIndex(ord1597, false);
      std::vector<u16> ord1599({0, 1});
      slog::Relation* readrel1600 = db->getRelation("eval_ans");
      eval_ansindex1571 = readrel1600->getIndex(ord1599, false);
      std::vector<u16> ord1601({0, 1});
      slog::Relation* readrel1602 = db->getRelation("eval_ans");
      eval_ansindex1572 = readrel1602->getIndex(ord1601, false);
  
    }
    ReadTask1574(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c256 = _t[0];
        u64 v_c171 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<4,1>(letindex1561, std::array<u64,4>{v_c171, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1562, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1563, std::array<u64,2>{v_c256, 0})) return;
        slog::join_probe<5,2>($sup56712x91x0x0x0index1564, std::array<u64,5>{v_c2, v_c171, 0, 0, 0}, [&](const std::array<u64,5>& m1603) {
          u64 v_c257 = m1603[2]; u64 v_c94 = m1603[3]; u64 v_c1 = m1603[4];
          if (!slog::exists_probe<3,2>(evalindex1565, std::array<u64,3>{v_c257, v_c2, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex1566, std::array<u64,3>{v_c94, v_c2, 0})) return;
          slog::join_probe<4,3>(letindex1567, std::array<u64,4>{v_c171, v_c1, v_c94, 0}, [&](const std::array<u64,4>& m1604) {
            u64 v_c258 = m1604[3];
            slog::join_probe<3,3>(evalindex1568, std::array<u64,3>{v_c257, v_c2, v_c258}, [&](const std::array<u64,3>& m1605) {
              slog::join_probe_old<3,2>(evalindex1569, evaldelta1573, std::array<u64,3>{v_c94, v_c2, 0}, [&](const std::array<u64,3>& m1606) {
                u64 v_c259 = m1606[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1570, std::array<u64,2>{v_c259, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1571, std::array<u64,2>{v_c256, 0}, [&](const std::array<u64,2>& m1607) {
                  u64 v_c174 = m1607[1];
                  slog::join_probe<2,1>(eval_ansindex1572, std::array<u64,2>{v_c259, 0}, [&](const std::array<u64,2>& m1608) {
                    u64 v_c208 = m1608[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c257, v_c208}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1574* _cont = new ReadTask1574(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1574(db,b), false);
  // (crule (pre (let __tconst9sKD800 constb9e118781cea1f9fa01462e0)) (probe _enum (1 0) 1 __tconst9sKD800 __t4akT382) (body) (head (mkstruct boolval (1 0) __t7ocu383 __t4akT382)) interp.slog:81 #f)
  class ReadTask1609 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("boolval");
      std::vector<u16> ord1610({1, 0});
      slog::Relation* readrel1611 = db->getRelation("_enum");
      driver_index = readrel1611->getIndex(ord1610, true);
  
    }
    ReadTask1609(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c260 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c260, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1612) {
        u64 v_c261 = m1612[1];
        if (buckethash(v_c261) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c261}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:81", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask1609* _cont = new ReadTask1609(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1609(db,b), true);
  // (crule (pre (let __tconst6GmF96 const5d1d34d1b1718cd7c9f1ee55) (let __tconst4c9Y88 constc100f95c1913f9c72fc1f4ef) (let __tconst4uoq76 constaee3d30407ccfb32dbb15266) (let __tconst3NP861 const609d51837c7fc306b0cbb04a) (let __tconst12zL90 conste6c67f7247161354cd7e1d34) (let __tconst2skc63 constf5ca38f748a1d6eaf726b8a4) (let __tconst7EjY48 constd4735e3a265e16eee03f5971) (let __tconst65HW45 const06abaa100ecef791ce028c56)) (scan temp5yYR956 __t0XVv44 __t1KLO93 __t2Fmv56 __t45Au84 __t4TnP71) (body (exists num (1 0) 1 __tconst7EjY48) (exists ref (1 0) 1 __tconst6GmF96) (exists num (1 0) 1 __tconst2skc63) (exists ref (1 0) 1 __tconst12zL90) (join ref (1 0) 1 __tconst65HW45 __t2luW46) (join num (1 0) 1 __tconst7EjY48 __t61C349) (join ref (1 0) 1 __tconst6GmF96 __t8XG759) (join num (1 0) 1 __tconst2skc63 __t23M464) (join ref (1 0) 1 __tconst12zL90 __t4l0k86) (let __t8AJw94 (lpush __t1KLO93 __tconst4c9Y88)) (let __t0AJB72 (lpush __t4TnP71 __t23M464)) (let __t8p2B57 (lpush __t2Fmv56 __t61C349))) (head (emit-temp temp03dt957 __t0AJB72 __t0XVv44 __t45Au84 __t8AJw94 __t8p2B57) (mkstruct app (1 2 0) __t0UL087 __t4l0k86 __t45Au84) (mkstruct app (1 2 0) __t5uOh47 __t2luW46 __t0XVv44)) schemecfa.slog:39 #f)
  class ReadTask1622 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex1613;  slog::Index** refindex1614;  slog::Index** numindex1615;  slog::Index** refindex1616;  slog::Index** refindex1617;  slog::Index** numindex1618;  slog::Index** refindex1619;  slog::Index** numindex1620;  slog::Index** refindex1621;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp03dt957");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      outer_rel = db->getRelation("temp5yYR956");
      std::vector<u16> ord1623({1, 0});
      slog::Relation* readrel1624 = db->getRelation("num");
      numindex1613 = readrel1624->getIndex(ord1623, false);
      std::vector<u16> ord1625({1, 0});
      slog::Relation* readrel1626 = db->getRelation("ref");
      refindex1614 = readrel1626->getIndex(ord1625, false);
      std::vector<u16> ord1627({1, 0});
      slog::Relation* readrel1628 = db->getRelation("num");
      numindex1615 = readrel1628->getIndex(ord1627, false);
      std::vector<u16> ord1629({1, 0});
      slog::Relation* readrel1630 = db->getRelation("ref");
      refindex1616 = readrel1630->getIndex(ord1629, false);
      std::vector<u16> ord1631({1, 0});
      slog::Relation* readrel1632 = db->getRelation("ref");
      refindex1617 = readrel1632->getIndex(ord1631, false);
      std::vector<u16> ord1633({1, 0});
      slog::Relation* readrel1634 = db->getRelation("num");
      numindex1618 = readrel1634->getIndex(ord1633, false);
      std::vector<u16> ord1635({1, 0});
      slog::Relation* readrel1636 = db->getRelation("ref");
      refindex1619 = readrel1636->getIndex(ord1635, false);
      std::vector<u16> ord1637({1, 0});
      slog::Relation* readrel1638 = db->getRelation("num");
      numindex1620 = readrel1638->getIndex(ord1637, false);
      std::vector<u16> ord1639({1, 0});
      slog::Relation* readrel1640 = db->getRelation("ref");
      refindex1621 = readrel1640->getIndex(ord1639, false);
  
    }
    ReadTask1622(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_const5d1d34d1b1718cd7c9f1ee55;
      u64 v_c262 = v_constc100f95c1913f9c72fc1f4ef;
      u64 v_c44 = v_constaee3d30407ccfb32dbb15266;
      u64 v_c45 = v_const609d51837c7fc306b0cbb04a;
      u64 v_c46 = v_conste6c67f7247161354cd7e1d34;
      u64 v_c263 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c264 = v_constd4735e3a265e16eee03f5971;
      u64 v_c47 = v_const06abaa100ecef791ce028c56;
  
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
        u64 v_c49 = _t[0];
        u64 v_c265 = _t[1];
        u64 v_c266 = _t[2];
        u64 v_c50 = _t[3];
        u64 v_c267 = _t[4];
        if (!slog::exists_probe<2,1>(numindex1613, std::array<u64,2>{v_c264, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1614, std::array<u64,2>{v_c43, 0})) return;
        if (!slog::exists_probe<2,1>(numindex1615, std::array<u64,2>{v_c263, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1616, std::array<u64,2>{v_c46, 0})) return;
        slog::join_probe<2,1>(refindex1617, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m1641) {
          u64 v_c53 = m1641[1];
          slog::join_probe<2,1>(numindex1618, std::array<u64,2>{v_c264, 0}, [&](const std::array<u64,2>& m1642) {
            u64 v_c268 = m1642[1];
            slog::join_probe<2,1>(refindex1619, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m1643) {
              u64 v_c55 = m1643[1];
              slog::join_probe<2,1>(numindex1620, std::array<u64,2>{v_c263, 0}, [&](const std::array<u64,2>& m1644) {
                u64 v_c269 = m1644[1];
                slog::join_probe<2,1>(refindex1621, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m1645) {
                  u64 v_c56 = m1645[1];
                  u64 v_c51 = _prim_lpush(db, v_c265, v_c262);
                  if (v_c51 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                  u64 v_c48 = _prim_lpush(db, v_c267, v_c269);
                  if (v_c48 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                  u64 v_c52 = _prim_lpush(db, v_c266, v_c268);
                  if (v_c52 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:39"); return; }
                  ++_fires;
                  slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c48, v_c49, v_c50, v_c51, v_c52});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c56, v_c50}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c53, v_c49}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("schemecfa.slog:39", "delta:temp5yYR956", _fires);
  
      if (!_done)
      {
        ReadTask1622* _cont = new ReadTask1622(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1622(db,b), false);
  // (crule (pre (let __tconst8pH5498 const2d53b3c21fa5cc786ac46d72) (let __tconst7G6n490 conste403ffb5ff0078a3e3c6bcc7) (let __tconst49ZO477 const0fc34686741291b4dd06511b) (let __tconst2M9b468 const39c6f8839ca547fa7b7a32c4) (let __tconst0VKF494 const20c400557af0eddc0be4d9e0) (let __tconst3zss458 const06abaa100ecef791ce028c56)) (scan temp4IN11008 __t0FwI456 __t55Yy488 __t6BG8482 __t6DJ9464 __t7u8Q496 __t8QoE473) (body (exists ref (1 0) 1 __tconst3zss458) (exists ref (1 0) 1 __tconst7G6n490) (exists ref (1 0) 1 __tconst8pH5498) (exists ref (1 0) 1 __tconst0VKF494) (join ref (1 0) 1 __tconst2M9b468 __t7Te9452) (join ref (1 0) 1 __tconst3zss458 __t0Jxw459) (join ref (1 0) 1 __tconst7G6n490 __t58rC466) (join ref (1 0) 1 __tconst8pH5498 __t6Nc8484) (join ref (1 0) 1 __tconst0VKF494 __t6o9z493) (let __t54rR457 (lpush __t0FwI456 __t7Te9452))) (head (emit-temp temp4Sey1009 __t54rR457 __t55Yy488 __t6BG8482 __t6DJ9464 __t7u8Q496 __t8QoE473) (mkstruct lambda (1 2 0) __t18GV497 __t7u8Q496 __t6o9z493) (mkstruct app (1 2 0) __t6p4Y485 __t6Nc8484 __t6BG8482) (mkstruct app (1 2 0) __t0c92476 __t58rC466 __t8QoE473) (mkstruct app (1 2 0) __t7FRU467 __t58rC466 __t6DJ9464)) schemecfa.slog:51 #f)
  class ReadTask1655 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1646;  slog::Index** refindex1647;  slog::Index** refindex1648;  slog::Index** refindex1649;  slog::Index** refindex1650;  slog::Index** refindex1651;  slog::Index** refindex1652;  slog::Index** refindex1653;  slog::Index** refindex1654;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4Sey1009");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("app");
      head_rel[3] = db->getRelation("app");
      head_rel[4] = db->getRelation("app");
      outer_rel = db->getRelation("temp4IN11008");
      std::vector<u16> ord1656({1, 0});
      slog::Relation* readrel1657 = db->getRelation("ref");
      refindex1646 = readrel1657->getIndex(ord1656, false);
      std::vector<u16> ord1658({1, 0});
      slog::Relation* readrel1659 = db->getRelation("ref");
      refindex1647 = readrel1659->getIndex(ord1658, false);
      std::vector<u16> ord1660({1, 0});
      slog::Relation* readrel1661 = db->getRelation("ref");
      refindex1648 = readrel1661->getIndex(ord1660, false);
      std::vector<u16> ord1662({1, 0});
      slog::Relation* readrel1663 = db->getRelation("ref");
      refindex1649 = readrel1663->getIndex(ord1662, false);
      std::vector<u16> ord1664({1, 0});
      slog::Relation* readrel1665 = db->getRelation("ref");
      refindex1650 = readrel1665->getIndex(ord1664, false);
      std::vector<u16> ord1666({1, 0});
      slog::Relation* readrel1667 = db->getRelation("ref");
      refindex1651 = readrel1667->getIndex(ord1666, false);
      std::vector<u16> ord1668({1, 0});
      slog::Relation* readrel1669 = db->getRelation("ref");
      refindex1652 = readrel1669->getIndex(ord1668, false);
      std::vector<u16> ord1670({1, 0});
      slog::Relation* readrel1671 = db->getRelation("ref");
      refindex1653 = readrel1671->getIndex(ord1670, false);
      std::vector<u16> ord1672({1, 0});
      slog::Relation* readrel1673 = db->getRelation("ref");
      refindex1654 = readrel1673->getIndex(ord1672, false);
  
    }
    ReadTask1655(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c270 = v_const2d53b3c21fa5cc786ac46d72;
      u64 v_c271 = v_conste403ffb5ff0078a3e3c6bcc7;
      u64 v_c272 = v_const0fc34686741291b4dd06511b;
      u64 v_c273 = v_const39c6f8839ca547fa7b7a32c4;
      u64 v_c274 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c275 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c276 = _t[0];
        u64 v_c277 = _t[1];
        u64 v_c278 = _t[2];
        u64 v_c279 = _t[3];
        u64 v_c280 = _t[4];
        u64 v_c281 = _t[5];
        if (!slog::exists_probe<2,1>(refindex1646, std::array<u64,2>{v_c275, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1647, std::array<u64,2>{v_c271, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1648, std::array<u64,2>{v_c270, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1649, std::array<u64,2>{v_c274, 0})) return;
        slog::join_probe<2,1>(refindex1650, std::array<u64,2>{v_c273, 0}, [&](const std::array<u64,2>& m1674) {
          u64 v_c282 = m1674[1];
          slog::join_probe<2,1>(refindex1651, std::array<u64,2>{v_c275, 0}, [&](const std::array<u64,2>& m1675) {
            u64 v_c283 = m1675[1];
            slog::join_probe<2,1>(refindex1652, std::array<u64,2>{v_c271, 0}, [&](const std::array<u64,2>& m1676) {
              u64 v_c284 = m1676[1];
              slog::join_probe<2,1>(refindex1653, std::array<u64,2>{v_c270, 0}, [&](const std::array<u64,2>& m1677) {
                u64 v_c285 = m1677[1];
                slog::join_probe<2,1>(refindex1654, std::array<u64,2>{v_c274, 0}, [&](const std::array<u64,2>& m1678) {
                  u64 v_c286 = m1678[1];
                  u64 v_c287 = _prim_lpush(db, v_c276, v_c282);
                  if (v_c287 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:51"); return; }
                  ++_fires;
                  slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c287, v_c277, v_c278, v_c279, v_c280, v_c281});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c280, v_c286}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c285, v_c278}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c284, v_c281}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c284, v_c279}, std::array<u16,3>{1, 2, 0});
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
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("schemecfa.slog:51", "delta:temp4IN11008", _fires);
  
      if (!_done)
      {
        ReadTask1655* _cont = new ReadTask1655(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1655(db,b), false);
  // (crule (pre (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9) (let __tconst1yQ3255 const6b86b273ff34fce19d6b804e) (let __tconst5n8U262 const0933fb667296882d8c45abca) (let __tconst0jEK272 const37664d5895f78758ec8e94e4) (let __tconst6yT0276 const5feceb66ffc86f38d952786c) (let __tconst3Rob283 const90fb9068eda6f2d68bb61c33)) (scan temp7w7C1050 __t0Sqk281 __t2HAB274 __t4a9o251 __t6dUB289 __t6t5b288) (body (exists num (1 0) 1 __tconst6yT0276) (exists ref (1 0) 1 __tconst0jEK272) (exists ref (1 0) 1 __tconst5n8U262) (exists num (1 0) 1 __tconst1yQ3255) (exists ref (1 0) 1 __tconst4G37291) (join ref (1 0) 1 __tconst3Rob283 __t88QE284) (join num (1 0) 1 __tconst6yT0276 __t0Xcv277) (join ref (1 0) 1 __tconst0jEK272 __t42iX271) (join ref (1 0) 1 __tconst5n8U262 __t4C1l263) (join num (1 0) 1 __tconst1yQ3255 __t5z2C256) (join ref (1 0) 1 __tconst4G37291 __t8oYB253) (let __t6cev261 (lpush __t0Sqk281 __t5z2C256)) (let __t9Oif282 (lpush __t0Sqk281 __t0Xcv277))) (head (emit-temp temp4bTi1051 __t2HAB274 __t4a9o251 __t6cev261 __t6dUB289 __t6t5b288 __t9Oif282) (mkstruct app (1 2 0) __t5GYK254 __t8oYB253 __t4a9o251) (mkstruct lambda (1 2 0) __t0vlN275 __t2HAB274 __t42iX271)) schemecfa.slog:70 #f)
  class ReadTask1690 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex1679;  slog::Index** refindex1680;  slog::Index** refindex1681;  slog::Index** numindex1682;  slog::Index** refindex1683;  slog::Index** refindex1684;  slog::Index** numindex1685;  slog::Index** refindex1686;  slog::Index** refindex1687;  slog::Index** numindex1688;  slog::Index** refindex1689;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4bTi1051");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp7w7C1050");
      std::vector<u16> ord1691({1, 0});
      slog::Relation* readrel1692 = db->getRelation("num");
      numindex1679 = readrel1692->getIndex(ord1691, false);
      std::vector<u16> ord1693({1, 0});
      slog::Relation* readrel1694 = db->getRelation("ref");
      refindex1680 = readrel1694->getIndex(ord1693, false);
      std::vector<u16> ord1695({1, 0});
      slog::Relation* readrel1696 = db->getRelation("ref");
      refindex1681 = readrel1696->getIndex(ord1695, false);
      std::vector<u16> ord1697({1, 0});
      slog::Relation* readrel1698 = db->getRelation("num");
      numindex1682 = readrel1698->getIndex(ord1697, false);
      std::vector<u16> ord1699({1, 0});
      slog::Relation* readrel1700 = db->getRelation("ref");
      refindex1683 = readrel1700->getIndex(ord1699, false);
      std::vector<u16> ord1701({1, 0});
      slog::Relation* readrel1702 = db->getRelation("ref");
      refindex1684 = readrel1702->getIndex(ord1701, false);
      std::vector<u16> ord1703({1, 0});
      slog::Relation* readrel1704 = db->getRelation("num");
      numindex1685 = readrel1704->getIndex(ord1703, false);
      std::vector<u16> ord1705({1, 0});
      slog::Relation* readrel1706 = db->getRelation("ref");
      refindex1686 = readrel1706->getIndex(ord1705, false);
      std::vector<u16> ord1707({1, 0});
      slog::Relation* readrel1708 = db->getRelation("ref");
      refindex1687 = readrel1708->getIndex(ord1707, false);
      std::vector<u16> ord1709({1, 0});
      slog::Relation* readrel1710 = db->getRelation("num");
      numindex1688 = readrel1710->getIndex(ord1709, false);
      std::vector<u16> ord1711({1, 0});
      slog::Relation* readrel1712 = db->getRelation("ref");
      refindex1689 = readrel1712->getIndex(ord1711, false);
  
    }
    ReadTask1690(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_const889c19fd926bc4ca61c0b4d9;
      u64 v_c288 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c150 = v_const0933fb667296882d8c45abca;
      u64 v_c151 = v_const37664d5895f78758ec8e94e4;
      u64 v_c289 = v_const5feceb66ffc86f38d952786c;
      u64 v_c152 = v_const90fb9068eda6f2d68bb61c33;
  
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
        u64 v_c290 = _t[0];
        u64 v_c153 = _t[1];
        u64 v_c154 = _t[2];
        u64 v_c156 = _t[3];
        u64 v_c157 = _t[4];
        if (!slog::exists_probe<2,1>(numindex1679, std::array<u64,2>{v_c289, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1680, std::array<u64,2>{v_c151, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1681, std::array<u64,2>{v_c150, 0})) return;
        if (!slog::exists_probe<2,1>(numindex1682, std::array<u64,2>{v_c288, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1683, std::array<u64,2>{v_c149, 0})) return;
        slog::join_probe<2,1>(refindex1684, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m1713) {
          u64 v_c159 = m1713[1];
          slog::join_probe<2,1>(numindex1685, std::array<u64,2>{v_c289, 0}, [&](const std::array<u64,2>& m1714) {
            u64 v_c291 = m1714[1];
            slog::join_probe<2,1>(refindex1686, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m1715) {
              u64 v_c160 = m1715[1];
              slog::join_probe<2,1>(refindex1687, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m1716) {
                u64 v_c162 = m1716[1];
                slog::join_probe<2,1>(numindex1688, std::array<u64,2>{v_c288, 0}, [&](const std::array<u64,2>& m1717) {
                  u64 v_c292 = m1717[1];
                  slog::join_probe<2,1>(refindex1689, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m1718) {
                    u64 v_c163 = m1718[1];
                    u64 v_c155 = _prim_lpush(db, v_c290, v_c292);
                    if (v_c155 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:70"); return; }
                    u64 v_c158 = _prim_lpush(db, v_c290, v_c291);
                    if (v_c158 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:70"); return; }
                    ++_fires;
                    slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c153, v_c154, v_c155, v_c156, v_c157, v_c158});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c163, v_c154}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c153, v_c160}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "delta:temp7w7C1050", _fires);
  
      if (!_done)
      {
        ReadTask1690* _cont = new ReadTask1690(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1690(db,b), false);
  // (crule (pre) (scan eval __t1bnm441 __t0DPj440 c) (body (exists eval (2 0 1) 1 c) (join $sup56712x91x0x0x0 (0 1 2 3 4) 2 __t1bnm441 c eb er x) (join let (2 1 3 0) 4 er x eb __t0DPj440) (exists eval (1 2 0) 2 eb c) (join-old eval (1 2 0) 2 (1 2 0) er c __t0jgp442) (exists eval_ans (0 1) 1 __t0jgp442) (join-old eval (1 2 0) 2 (1 2 0) eb c __t9j6S443) (exists eval_ans (0 1) 1 __t9j6S443) (join eval_ans (0 1) 1 __t0jgp442 vr) (join eval_ans (0 1) 1 __t9j6S443 v)) (head (emit eval_ans (0 1) __t1bnm441 v)) interp.slog:92 #f)
  class ReadTask1731 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1719;  slog::Index** $sup56712x91x0x0x0index1720;  slog::Index** letindex1721;  slog::Index** evalindex1722;  slog::Index** evalindex1723;  slog::Index** eval_ansindex1724;  slog::Index** evalindex1725;  slog::Index** eval_ansindex1726;  slog::Index** eval_ansindex1727;  slog::Index** eval_ansindex1728;  slog::Index** evaldelta1729;  slog::Index** evaldelta1730;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1732({0, 1});
      slog::Relation* readrel1733 = db->getRelation("eval_ans");
      head_index[0] = readrel1733->getIndex(ord1732, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1734({2, 0, 1});
      slog::Relation* readrel1735 = db->getRelation("eval");
      evalindex1719 = readrel1735->getIndex(ord1734, false);
      std::vector<u16> ord1736({0, 1, 2, 3, 4});
      slog::Relation* readrel1737 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index1720 = readrel1737->getIndex(ord1736, false);
      std::vector<u16> ord1738({2, 1, 3, 0});
      slog::Relation* readrel1739 = db->getRelation("let");
      letindex1721 = readrel1739->getIndex(ord1738, false);
      std::vector<u16> ord1740({1, 2, 0});
      slog::Relation* readrel1741 = db->getRelation("eval");
      evalindex1722 = readrel1741->getIndex(ord1740, false);
      std::vector<u16> ord1742({1, 2, 0});
      slog::Relation* readrel1743 = db->getRelation("eval");
      evalindex1723 = readrel1743->getIndex(ord1742, false);
      std::vector<u16> ord1744({1, 2, 0});
      slog::Relation* readrel1745 = db->getRelation("eval");
      evaldelta1729 = readrel1745->getIndex(ord1744, true);
      std::vector<u16> ord1746({0, 1});
      slog::Relation* readrel1747 = db->getRelation("eval_ans");
      eval_ansindex1724 = readrel1747->getIndex(ord1746, false);
      std::vector<u16> ord1748({1, 2, 0});
      slog::Relation* readrel1749 = db->getRelation("eval");
      evalindex1725 = readrel1749->getIndex(ord1748, false);
      std::vector<u16> ord1750({1, 2, 0});
      slog::Relation* readrel1751 = db->getRelation("eval");
      evaldelta1730 = readrel1751->getIndex(ord1750, true);
      std::vector<u16> ord1752({0, 1});
      slog::Relation* readrel1753 = db->getRelation("eval_ans");
      eval_ansindex1726 = readrel1753->getIndex(ord1752, false);
      std::vector<u16> ord1754({0, 1});
      slog::Relation* readrel1755 = db->getRelation("eval_ans");
      eval_ansindex1727 = readrel1755->getIndex(ord1754, false);
      std::vector<u16> ord1756({0, 1});
      slog::Relation* readrel1757 = db->getRelation("eval_ans");
      eval_ansindex1728 = readrel1757->getIndex(ord1756, false);
  
    }
    ReadTask1731(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c257 = _t[0];
        u64 v_c258 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1719, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<5,2>($sup56712x91x0x0x0index1720, std::array<u64,5>{v_c257, v_c2, 0, 0, 0}, [&](const std::array<u64,5>& m1758) {
          u64 v_c94 = m1758[2]; u64 v_c171 = m1758[3]; u64 v_c1 = m1758[4];
          slog::join_probe<4,4>(letindex1721, std::array<u64,4>{v_c171, v_c1, v_c94, v_c258}, [&](const std::array<u64,4>& m1759) {
            if (!slog::exists_probe<3,2>(evalindex1722, std::array<u64,3>{v_c94, v_c2, 0})) return;
            slog::join_probe_old<3,2>(evalindex1723, evaldelta1729, std::array<u64,3>{v_c171, v_c2, 0}, [&](const std::array<u64,3>& m1760) {
              u64 v_c256 = m1760[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1724, std::array<u64,2>{v_c256, 0})) return;
              slog::join_probe_old<3,2>(evalindex1725, evaldelta1730, std::array<u64,3>{v_c94, v_c2, 0}, [&](const std::array<u64,3>& m1761) {
                u64 v_c259 = m1761[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1726, std::array<u64,2>{v_c259, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1727, std::array<u64,2>{v_c256, 0}, [&](const std::array<u64,2>& m1762) {
                  u64 v_c174 = m1762[1];
                  slog::join_probe<2,1>(eval_ansindex1728, std::array<u64,2>{v_c259, 0}, [&](const std::array<u64,2>& m1763) {
                    u64 v_c208 = m1763[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c257, v_c208}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1731* _cont = new ReadTask1731(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1731(db,b), false);
  // (crule (pre) (scan nan_result __erre5YJq933 __errf72gr934 __errf03jj935 __errf6tmn936) (body) (head (emit error (0) __erre5YJq933)) <internal>:1 #f)
  class ReadTask1764 : public slog::Task
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
      std::vector<u16> ord1765({0});
      slog::Relation* readrel1766 = db->getRelation("error");
      head_index[0] = readrel1766->getIndex(ord1765, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask1764(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c293 = _t[0];
        u64 v_c294 = _t[1];
        u64 v_c295 = _t[2];
        u64 v_c296 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c293}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask1764* _cont = new ReadTask1764(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1764(db,b), false);
  // (crule (pre) (scan temp2RWj1119 __t3YjV179 __t4BlY180 c) (body (join closure (1 2 0) 2 __t3YjV179 c __t7vnx178)) (head (emit eval_ans (0 1) __t4BlY180 __t7vnx178)) interp.slog:29 #f)
  class ReadTask1768 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex1767;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1769({0, 1});
      slog::Relation* readrel1770 = db->getRelation("eval_ans");
      head_index[0] = readrel1770->getIndex(ord1769, false);
      outer_rel = db->getRelation("temp2RWj1119");
      std::vector<u16> ord1771({1, 2, 0});
      slog::Relation* readrel1772 = db->getRelation("closure");
      closureindex1767 = readrel1772->getIndex(ord1771, false);
  
    }
    ReadTask1768(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c297 = _t[0];
        u64 v_c298 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<3,2>(closureindex1767, std::array<u64,3>{v_c297, v_c2, 0}, [&](const std::array<u64,3>& m1773) {
          u64 v_c299 = m1773[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c298, v_c299}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:29", "delta:temp2RWj1119", _fires);
  
      if (!_done)
      {
        ReadTask1768* _cont = new ReadTask1768(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1768(db,b), false);
  // (crule (pre (let __tconst69HS686 constcd2a69ce5ca278db1d6da969) (let _00024sqc0vxk654 constd4735e3a265e16eee03f5971) (let _00024sqc9Xix655 const5feceb66ffc86f38d952786c) (let _00024sqc63kA656 const6b86b273ff34fce19d6b804e) (let _00024sqo95lm657 const5feceb66ffc86f38d952786c) (let _00024sqo4EpM658 const6b86b273ff34fce19d6b804e) (let _00024sqo7bBz659 const6b86b273ff34fce19d6b804e) (let _00024sqo5IeL660 const5feceb66ffc86f38d952786c) (let __trid88QO687 consteefaed435882b14b69e99d78) (let __trel4WdJ688 constdede4476644eb06b5a48b866) (let __tcol9WTP689 const6b86b273ff34fce19d6b804e)) (probe $seq_atr (1 0 2) 1 _00024sqo7bBz659 __t4TBU101 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo95lm657 __t4TBU101 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo4EpM658 __t4TBU101 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5IeL660 __t4TBU101 _00024seq2) (join _enum (0 1) 2 __t4TBU101 __tconst69HS686) (join delta (2 0 1) 1 _00024seq2 __t3GFi99 op) (join arithmetic_op (0) 1 op) (letp _00024sql4o3F652 (aslst _00024seq2)) (let chk1AIj1085 (llen _00024sql4o3F652)) (eq _00024sqc0vxk654 chk1AIj1085) (letp chk0mgQ1086 (lref _00024sql4o3F652 _00024sqc9Xix655)) (eq __t4TBU101 chk0mgQ1086) (letp chk6hGQ1087 (lref _00024sql4o3F652 _00024sqc63kA656)) (eq __t4TBU101 chk6hGQ1087)) (head (tycheck __t4TBU101 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid88QO687 __trel4WdJ688 __tcol9WTP689 (1 2 3 4 0)) (emit delta_ans (0 1) __t3GFi99 __t4TBU101)) interp.slog:111 #f)
  class ReadTask1786 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1774;  slog::Index** $seq_atindex1775;  slog::Index** $seq_atrindex1776;  slog::Index** _enumindex1777;  slog::Index** deltaindex1778;  slog::Index** arithmetic_opindex1779;  slog::Index** $seq_atrdelta1780;
    u32 sid1783;  u32 sid1781;  u32 sid1782;  u32 sid1784;  u32 sid1785;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord1787({0, 1});
      slog::Relation* readrel1788 = db->getRelation("delta_ans");
      head_index[1] = readrel1788->getIndex(ord1787, false);
      std::vector<u16> ord1789({1, 0, 2});
      slog::Relation* readrel1790 = db->getRelation("$seq_atr");
      driver_index = readrel1790->getIndex(ord1789, true);
      std::vector<u16> ord1791({1, 0, 2});
      slog::Relation* readrel1792 = db->getRelation("$seq_at");
      $seq_atindex1774 = readrel1792->getIndex(ord1791, false);
      std::vector<u16> ord1793({1, 0, 2});
      slog::Relation* readrel1794 = db->getRelation("$seq_at");
      $seq_atindex1775 = readrel1794->getIndex(ord1793, false);
      std::vector<u16> ord1795({1, 0, 2});
      slog::Relation* readrel1796 = db->getRelation("$seq_atr");
      $seq_atrindex1776 = readrel1796->getIndex(ord1795, false);
      std::vector<u16> ord1797({1, 0, 2});
      slog::Relation* readrel1798 = db->getRelation("$seq_atr");
      $seq_atrdelta1780 = readrel1798->getIndex(ord1797, true);
      std::vector<u16> ord1799({0, 1});
      slog::Relation* readrel1800 = db->getRelation("_enum");
      _enumindex1777 = readrel1800->getIndex(ord1799, false);
      std::vector<u16> ord1801({2, 0, 1});
      slog::Relation* readrel1802 = db->getRelation("delta");
      deltaindex1778 = readrel1802->getIndex(ord1801, false);
      std::vector<u16> ord1803({0});
      slog::Relation* readrel1804 = db->getRelation("arithmetic_op");
      arithmetic_opindex1779 = readrel1804->getIndex(ord1803, false);
      sid1783 = db->getRelation("_enum")->getStructId();
      sid1781 = db->getRelation("boolval")->getStructId();
      sid1782 = db->getRelation("closure")->getStructId();
      sid1784 = db->getRelation("prim")->getStructId();
      sid1785 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask1786(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c64 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c65 = v_constd4735e3a265e16eee03f5971;
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
      u64 v_c67 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_const5feceb66ffc86f38d952786c;
      u64 v_c72 = v_consteefaed435882b14b69e99d78;
      u64 v_c73 = v_constdede4476644eb06b5a48b866;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c70, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1805) {
        u64 v_c78 = m1805[1];
        u64 v_c16 = m1805[2];
        if (buckethash(v_c78) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1774, std::array<u64,3>{v_c68, v_c78, v_c16}, [&](const std::array<u64,3>& m1806) {
          slog::join_probe<3,3>($seq_atindex1775, std::array<u64,3>{v_c69, v_c78, v_c16}, [&](const std::array<u64,3>& m1807) {
            slog::join_probe_old<3,3>($seq_atrindex1776, $seq_atrdelta1780, std::array<u64,3>{v_c71, v_c78, v_c16}, [&](const std::array<u64,3>& m1808) {
              slog::join_probe<2,2>(_enumindex1777, std::array<u64,2>{v_c78, v_c64}, [&](const std::array<u64,2>& m1809) {
                slog::join_probe<3,1>(deltaindex1778, std::array<u64,3>{v_c16, 0, 0}, [&](const std::array<u64,3>& m1810) {
                  u64 v_c75 = m1810[1]; u64 v_c76 = m1810[2];
                  slog::join_probe<1,1>(arithmetic_opindex1779, std::array<u64,1>{v_c76}, [&](const std::array<u64,1>& m1811) {
                    bool ok1812 = true;
                    u64 v_c77 = _prim_aslst(db, v_c16, &ok1812);
                    if (!ok1812) return;
                    u64 v_c300 = _prim_llen(db, v_c77);
                    if (v_c300 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c65 != v_c300) return;
                    bool ok1813 = true;
                    u64 v_c301 = _prim_lref(db, v_c77, v_c66, &ok1813);
                    if (!ok1813) return;
                    if (v_c78 != v_c301) return;
                    bool ok1814 = true;
                    u64 v_c302 = _prim_lref(db, v_c77, v_c67, &ok1814);
                    if (!ok1814) return;
                    if (v_c78 != v_c302) return;
                    ++_fires;
                    if (!((is_struct(v_c78) && (decode_struct_id(v_c78) == sid1781 || decode_struct_id(v_c78) == sid1782 || decode_struct_id(v_c78) == sid1783 || decode_struct_id(v_c78) == sid1784 || decode_struct_id(v_c78) == sid1785))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c72, v_c73, v_c74, v_c78}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c75, v_c78}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:111", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1786* _cont = new ReadTask1786(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1786(db,b), false);
  // (crule (pre) (scan app __t9wPj297 ef es) (body (join eval (1 2 0) 1 __t9wPj297 c __4CVi731)) (head (mkstruct eval (1 2 0) __0uUI732 ef c)) interp.slog:48 #f)
  class ReadTask1816 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1815;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1817({1, 2, 0});
      slog::Relation* readrel1818 = db->getRelation("eval");
      evalindex1815 = readrel1818->getIndex(ord1817, false);
  
    }
    ReadTask1816(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c237 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c91 = _t[2];
        slog::join_probe<3,1>(evalindex1815, std::array<u64,3>{v_c237, 0, 0}, [&](const std::array<u64,3>& m1819) {
          u64 v_c2 = m1819[1]; u64 v_c236 = m1819[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c100, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1816* _cont = new ReadTask1816(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1816(db,b), false);
  // (crule (pre (let __tconst4VQK721 constb9e118781cea1f9fa01462e0) (let __tconst22Ls722 const0122baa3ac55f1b433944eb1) (let __tconst5lFL150 const60e3114d9b4b6577eea8cbc0) (let _00024sqc6U6L608 const6b86b273ff34fce19d6b804e) (let _00024sqc4sFX609 const5feceb66ffc86f38d952786c) (let _00024sqo2S6J610 const5feceb66ffc86f38d952786c) (let _00024sqo0Kwi611 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo0Kwi611 __t9y9U153 _00024seq1) (body (join $seq_at (1 0 2) 3 _00024sqo2S6J610 __t9y9U153 _00024seq1) (exists _enum (1 0) 1 __tconst4VQK721) (exists _enum (1 0) 1 __tconst22Ls722) (join delta (1 2 0) 2 __tconst5lFL150 _00024seq1 __t1y17151) (join _enum (1 0) 1 __tconst4VQK721 __t0cMr152) (join boolval (0 1) 2 __t9y9U153 __t0cMr152) (join _enum (1 0) 1 __tconst22Ls722 __t5r57148) (letp _00024sql06hQ606 (aslst _00024seq1)) (let chk3PKX1126 (llen _00024sql06hQ606)) (eq _00024sqc6U6L608 chk3PKX1126) (letp chk6gEe1127 (lref _00024sql06hQ606 _00024sqc4sFX609)) (eq __t9y9U153 chk6gEe1127)) (head (emit-temp temp41lW1120 __t1y17151) (mkstruct boolval (1 0) __t2W4B149 __t5r57148)) interp.slog:113 #f)
  class ReadTask1827 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1820;  slog::Index** _enumindex1821;  slog::Index** _enumindex1822;  slog::Index** deltaindex1823;  slog::Index** _enumindex1824;  slog::Index** boolvalindex1825;  slog::Index** _enumindex1826;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp41lW1120");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1828({1, 0, 2});
      slog::Relation* readrel1829 = db->getRelation("$seq_atr");
      driver_index = readrel1829->getIndex(ord1828, true);
      std::vector<u16> ord1830({1, 0, 2});
      slog::Relation* readrel1831 = db->getRelation("$seq_at");
      $seq_atindex1820 = readrel1831->getIndex(ord1830, false);
      std::vector<u16> ord1832({1, 0});
      slog::Relation* readrel1833 = db->getRelation("_enum");
      _enumindex1821 = readrel1833->getIndex(ord1832, false);
      std::vector<u16> ord1834({1, 0});
      slog::Relation* readrel1835 = db->getRelation("_enum");
      _enumindex1822 = readrel1835->getIndex(ord1834, false);
      std::vector<u16> ord1836({1, 2, 0});
      slog::Relation* readrel1837 = db->getRelation("delta");
      deltaindex1823 = readrel1837->getIndex(ord1836, false);
      std::vector<u16> ord1838({1, 0});
      slog::Relation* readrel1839 = db->getRelation("_enum");
      _enumindex1824 = readrel1839->getIndex(ord1838, false);
      std::vector<u16> ord1840({0, 1});
      slog::Relation* readrel1841 = db->getRelation("boolval");
      boolvalindex1825 = readrel1841->getIndex(ord1840, false);
      std::vector<u16> ord1842({1, 0});
      slog::Relation* readrel1843 = db->getRelation("_enum");
      _enumindex1826 = readrel1843->getIndex(ord1842, false);
  
    }
    ReadTask1827(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c303 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c304 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c305 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c306 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c307 = v_const5feceb66ffc86f38d952786c;
      u64 v_c308 = v_const5feceb66ffc86f38d952786c;
      u64 v_c309 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c309, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1844) {
        u64 v_c310 = m1844[1];
        u64 v_c311 = m1844[2];
        if (buckethash(v_c310) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1820, std::array<u64,3>{v_c308, v_c310, v_c311}, [&](const std::array<u64,3>& m1845) {
          if (!slog::exists_probe<2,1>(_enumindex1821, std::array<u64,2>{v_c303, 0})) return;
          if (!slog::exists_probe<2,1>(_enumindex1822, std::array<u64,2>{v_c304, 0})) return;
          slog::join_probe<3,2>(deltaindex1823, std::array<u64,3>{v_c305, v_c311, 0}, [&](const std::array<u64,3>& m1846) {
            u64 v_c312 = m1846[2];
            slog::join_probe<2,1>(_enumindex1824, std::array<u64,2>{v_c303, 0}, [&](const std::array<u64,2>& m1847) {
              u64 v_c313 = m1847[1];
              slog::join_probe<2,2>(boolvalindex1825, std::array<u64,2>{v_c310, v_c313}, [&](const std::array<u64,2>& m1848) {
                slog::join_probe<2,1>(_enumindex1826, std::array<u64,2>{v_c304, 0}, [&](const std::array<u64,2>& m1849) {
                  u64 v_c314 = m1849[1];
                  bool ok1850 = true;
                  u64 v_c315 = _prim_aslst(db, v_c311, &ok1850);
                  if (!ok1850) return;
                  u64 v_c316 = _prim_llen(db, v_c315);
                  if (v_c316 == slog_error) { slog::emit_pending_error(db, "interp.slog:113"); return; }
                  if (v_c306 != v_c316) return;
                  bool ok1851 = true;
                  u64 v_c317 = _prim_lref(db, v_c315, v_c307, &ok1851);
                  if (!ok1851) return;
                  if (v_c310 != v_c317) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c312});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c314}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:113", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1827* _cont = new ReadTask1827(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1827(db,b), false);
}

