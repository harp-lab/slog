
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0388ead47e9d5ccfc5320715;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const119eb3a23d030ee0dfe9f807;
extern u64 v_const2bc983a5942276eb00a75e21;
extern u64 v_const30f8b180d63559f2512b744f;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const829935b42173b360da35f679;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constba2df4903a2c14e86dc3bcca;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdcc297bb3300d9549a9d611a;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_conste90c92f3e6c3b47a7bc93e42;
extern u64 v_consteefaed435882b14b69e99d78;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf77801bebb40767a1b303d97;


void slog_rules_c7f50ece33a2e1dee(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst6UQc687 constb9e118781cea1f9fa01462e0) (let __tconst2Qtx688 const0122baa3ac55f1b433944eb1) (let __tconst6Cg6137 const60e3114d9b4b6577eea8cbc0) (let _00024sqc9tfN494 const6b86b273ff34fce19d6b804e) (let _00024sqc0jHU495 const5feceb66ffc86f38d952786c) (let _00024sqo7x4Q496 const5feceb66ffc86f38d952786c) (let _00024sqo5KfU497 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst6Cg6137 _00024seq1 __t2pLy138) (body (letp _00024sql9r92492 (aslst _00024seq1)) (letp __t687V140 (lref _00024sql9r92492 _00024sqc0jHU495)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7x4Q496 __t687V140 _00024seq1) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5KfU497 __t687V140 _00024seq1) (exists _enum (1 0) 1 __tconst2Qtx688) (join _enum (1 0) 1 __tconst6UQc687 __t4aV2139) (join-old boolval (0 1) 2 (0 1) __t687V140 __t4aV2139) (join _enum (1 0) 1 __tconst2Qtx688 __t67wA135) (let chk063u991 (llen _00024sql9r92492)) (eq _00024sqc9tfN494 chk063u991)) (head (emit-temp temp0a5K990 __t2pLy138) (mkstruct boolval (1 0) __t5iPS136 __t67wA135)) interp.slog:113 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex0;  slog::Index** $seq_atrindex1;  slog::Index** _enumindex2;  slog::Index** _enumindex3;  slog::Index** boolvalindex4;  slog::Index** _enumindex5;  slog::Index** $seq_atdelta6;  slog::Index** $seq_atrdelta7;  slog::Index** boolvaldelta8;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0a5K990");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord10({1, 2, 0});
      slog::Relation* readrel11 = db->getRelation("delta");
      driver_index = readrel11->getIndex(ord10, true);
      std::vector<u16> ord12({1, 0, 2});
      slog::Relation* readrel13 = db->getRelation("$seq_at");
      $seq_atindex0 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0, 2});
      slog::Relation* readrel15 = db->getRelation("$seq_at");
      $seq_atdelta6 = readrel15->getIndex(ord14, true);
      std::vector<u16> ord16({1, 0, 2});
      slog::Relation* readrel17 = db->getRelation("$seq_atr");
      $seq_atrindex1 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 0, 2});
      slog::Relation* readrel19 = db->getRelation("$seq_atr");
      $seq_atrdelta7 = readrel19->getIndex(ord18, true);
      std::vector<u16> ord20({1, 0});
      slog::Relation* readrel21 = db->getRelation("_enum");
      _enumindex2 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("_enum");
      _enumindex3 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({0, 1});
      slog::Relation* readrel25 = db->getRelation("boolval");
      boolvalindex4 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({0, 1});
      slog::Relation* readrel27 = db->getRelation("boolval");
      boolvaldelta8 = readrel27->getIndex(ord26, true);
      std::vector<u16> ord28({1, 0});
      slog::Relation* readrel29 = db->getRelation("_enum");
      _enumindex5 = readrel29->getIndex(ord28, false);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c1 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c2 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c2, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m30) {
        u64 v_c7 = m30[1];
        u64 v_c8 = m30[2];
        if (buckethash(v_c7) != bucket) return;
        bool ok31 = true;
        u64 v_c9 = _prim_aslst(db, v_c7, &ok31);
        if (!ok31) return;
        bool ok32 = true;
        u64 v_c10 = _prim_lref(db, v_c9, v_c4, &ok32);
        if (!ok32) return;
        slog::join_probe_old<3,3>($seq_atindex0, $seq_atdelta6, std::array<u64,3>{v_c5, v_c10, v_c7}, [&](const std::array<u64,3>& m33) {
          slog::join_probe_old<3,3>($seq_atrindex1, $seq_atrdelta7, std::array<u64,3>{v_c6, v_c10, v_c7}, [&](const std::array<u64,3>& m34) {
            if (!slog::exists_probe<2,1>(_enumindex2, std::array<u64,2>{v_c1, 0})) return;
            slog::join_probe<2,1>(_enumindex3, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m35) {
              u64 v_c11 = m35[1];
              slog::join_probe_old<2,2>(boolvalindex4, boolvaldelta8, std::array<u64,2>{v_c10, v_c11}, [&](const std::array<u64,2>& m36) {
                slog::join_probe<2,1>(_enumindex5, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m37) {
                  u64 v_c12 = m37[1];
                  u64 v_c13 = _prim_llen(db, v_c9);
                  if (v_c13 == slog_error) { slog::emit_pending_error(db, "interp.slog:113"); return; }
                  if (v_c3 != v_c13) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c8});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:113", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask9* _cont = new ReadTask9(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), false);
  // (crule (pre (let __tconst2fdM633 constcd2a69ce5ca278db1d6da969) (let _00024sqc7LFn532 constd4735e3a265e16eee03f5971) (let _00024sqc3SHd533 const5feceb66ffc86f38d952786c) (let _00024sqc4CLM534 const6b86b273ff34fce19d6b804e) (let _00024sqo90j9535 const5feceb66ffc86f38d952786c) (let _00024sqo88rK536 const6b86b273ff34fce19d6b804e) (let _00024sqo1A9y537 const6b86b273ff34fce19d6b804e) (let _00024sqo2hWF538 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo90j9535 __t26Zq339 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo88rK536 __t26Zq339 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1A9y537 __t26Zq339 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2hWF538 __t26Zq339 _00024seq2) (join _enum (0 1) 2 __t26Zq339 __tconst2fdM633) (join delta (2 0 1) 1 _00024seq2 __t1IV0337 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql96G9530 (aslst _00024seq2)) (let chk0FTO948 (llen _00024sql96G9530)) (eq _00024sqc7LFn532 chk0FTO948) (letp chk4Y5v949 (lref _00024sql96G9530 _00024sqc3SHd533)) (eq __t26Zq339 chk4Y5v949) (letp chk26P0950 (lref _00024sql96G9530 _00024sqc4CLM534)) (eq __t26Zq339 chk26P0950)) (head (emit-temp temp5ZiW945 __t1IV0337 b) (mkstruct boolval (1 0) __t4qAo336 b)) interp.slog:112 #f)
  class ReadTask48 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex38;  slog::Index** $seq_atrindex39;  slog::Index** $seq_atrindex40;  slog::Index** _enumindex41;  slog::Index** deltaindex42;  slog::Index** comparison_opindex43;  slog::Index** any_boolindex44;  slog::Index** $seq_atdelta45;  slog::Index** $seq_atrdelta46;  slog::Index** $seq_atrdelta47;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5ZiW945");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord49({1, 0, 2});
      slog::Relation* readrel50 = db->getRelation("$seq_at");
      driver_index = readrel50->getIndex(ord49, true);
      std::vector<u16> ord51({1, 0, 2});
      slog::Relation* readrel52 = db->getRelation("$seq_at");
      $seq_atindex38 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 0, 2});
      slog::Relation* readrel54 = db->getRelation("$seq_at");
      $seq_atdelta45 = readrel54->getIndex(ord53, true);
      std::vector<u16> ord55({1, 0, 2});
      slog::Relation* readrel56 = db->getRelation("$seq_atr");
      $seq_atrindex39 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 0, 2});
      slog::Relation* readrel58 = db->getRelation("$seq_atr");
      $seq_atrdelta46 = readrel58->getIndex(ord57, true);
      std::vector<u16> ord59({1, 0, 2});
      slog::Relation* readrel60 = db->getRelation("$seq_atr");
      $seq_atrindex40 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 0, 2});
      slog::Relation* readrel62 = db->getRelation("$seq_atr");
      $seq_atrdelta47 = readrel62->getIndex(ord61, true);
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("_enum");
      _enumindex41 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({2, 0, 1});
      slog::Relation* readrel66 = db->getRelation("delta");
      deltaindex42 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({0});
      slog::Relation* readrel68 = db->getRelation("comparison_op");
      comparison_opindex43 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({0});
      slog::Relation* readrel70 = db->getRelation("any_bool");
      any_boolindex44 = readrel70->getIndex(ord69, false);
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const5feceb66ffc86f38d952786c;
      u64 v_c17 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
      u64 v_c19 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c21 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c18, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m71) {
        u64 v_c22 = m71[1];
        u64 v_c23 = m71[2];
        if (buckethash(v_c22) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex38, $seq_atdelta45, std::array<u64,3>{v_c19, v_c22, v_c23}, [&](const std::array<u64,3>& m72) {
          slog::join_probe_old<3,3>($seq_atrindex39, $seq_atrdelta46, std::array<u64,3>{v_c20, v_c22, v_c23}, [&](const std::array<u64,3>& m73) {
            slog::join_probe_old<3,3>($seq_atrindex40, $seq_atrdelta47, std::array<u64,3>{v_c21, v_c22, v_c23}, [&](const std::array<u64,3>& m74) {
              slog::join_probe<2,2>(_enumindex41, std::array<u64,2>{v_c22, v_c14}, [&](const std::array<u64,2>& m75) {
                slog::join_probe<3,1>(deltaindex42, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m76) {
                  u64 v_c24 = m76[1]; u64 v_c25 = m76[2];
                  slog::join_probe<1,1>(comparison_opindex43, std::array<u64,1>{v_c25}, [&](const std::array<u64,1>& m77) {
                    slog::join_all<1>(any_boolindex44, [&](const std::array<u64,1>& m78) {
                      u64 v_c26 = m78[0];
                      bool ok79 = true;
                      u64 v_c27 = _prim_aslst(db, v_c23, &ok79);
                      if (!ok79) return;
                      u64 v_c28 = _prim_llen(db, v_c27);
                      if (v_c28 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c15 != v_c28) return;
                      bool ok80 = true;
                      u64 v_c29 = _prim_lref(db, v_c27, v_c16, &ok80);
                      if (!ok80) return;
                      if (v_c22 != v_c29) return;
                      bool ok81 = true;
                      u64 v_c30 = _prim_lref(db, v_c27, v_c17, &ok81);
                      if (!ok81) return;
                      if (v_c22 != v_c30) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c24, v_c26});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c26}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:112", "delta:$seq_at", _fires);
  
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
  // (crule (pre (let __tconst5mQl666 constb9e118781cea1f9fa01462e0) (let __tconst7ska196 const06abaa100ecef791ce028c56) (let _00024sqc2bs1547 constd4735e3a265e16eee03f5971) (let _00024sqc3b5Z548 const5feceb66ffc86f38d952786c) (let _00024sqc4cPv549 const6b86b273ff34fce19d6b804e) (let _00024sqo2orM550 const5feceb66ffc86f38d952786c) (let _00024sqo79dC551 const6b86b273ff34fce19d6b804e) (let _00024sqo7ukz552 const6b86b273ff34fce19d6b804e) (let _00024sqo5FdA553 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo5FdA553 v2 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo79dC551 v2 _00024seq0) (letp _00024sql4FKJ545 (aslst _00024seq0)) (letp v1 (lref _00024sql4FKJ545 _00024sqc3b5Z548)) (neq v1 v2) (join $seq_at (1 0 2) 3 _00024sqo2orM550 v1 _00024seq0) (join $seq_atr (1 0 2) 3 _00024sqo7ukz552 v1 _00024seq0) (exists _enum (1 0) 1 __tconst5mQl666) (join delta (1 2 0) 2 __tconst7ska196 _00024seq0 __t0ECW197) (join _enum (1 0) 1 __tconst5mQl666 __t7sei194) (let chk9G0c878 (llen _00024sql4FKJ545)) (eq _00024sqc2bs1547 chk9G0c878) (letp chk2EtH879 (lref _00024sql4FKJ545 _00024sqc4cPv549)) (eq v2 chk2EtH879)) (head (emit-temp temp5E9s870 __t0ECW197) (mkstruct boolval (1 0) __t2gQB195 __t7sei194)) interp.slog:120 #f)
  class ReadTask88 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex82;  slog::Index** $seq_atindex83;  slog::Index** $seq_atrindex84;  slog::Index** _enumindex85;  slog::Index** deltaindex86;  slog::Index** _enumindex87;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5E9s870");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord89({1, 0, 2});
      slog::Relation* readrel90 = db->getRelation("$seq_atr");
      driver_index = readrel90->getIndex(ord89, true);
      std::vector<u16> ord91({1, 0, 2});
      slog::Relation* readrel92 = db->getRelation("$seq_at");
      $seq_atindex82 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 0, 2});
      slog::Relation* readrel94 = db->getRelation("$seq_at");
      $seq_atindex83 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 0, 2});
      slog::Relation* readrel96 = db->getRelation("$seq_atr");
      $seq_atrindex84 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 0});
      slog::Relation* readrel98 = db->getRelation("_enum");
      _enumindex85 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 0});
      slog::Relation* readrel100 = db->getRelation("delta");
      deltaindex86 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("_enum");
      _enumindex87 = readrel102->getIndex(ord101, false);
  
    }
    ReadTask88(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c32 = v_const06abaa100ecef791ce028c56;
      u64 v_c33 = v_constd4735e3a265e16eee03f5971;
      u64 v_c34 = v_const5feceb66ffc86f38d952786c;
      u64 v_c35 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c36 = v_const5feceb66ffc86f38d952786c;
      u64 v_c37 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c39 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c39, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m103) {
        u64 v_c40 = m103[1];
        u64 v_c41 = m103[2];
        if (buckethash(v_c40) != bucket) return;
        slog::join_probe<3,3>($seq_atindex82, std::array<u64,3>{v_c37, v_c40, v_c41}, [&](const std::array<u64,3>& m104) {
          bool ok105 = true;
          u64 v_c42 = _prim_aslst(db, v_c41, &ok105);
          if (!ok105) return;
          bool ok106 = true;
          u64 v_c43 = _prim_lref(db, v_c42, v_c34, &ok106);
          if (!ok106) return;
          if (v_c43 == v_c40) return;
          slog::join_probe<3,3>($seq_atindex83, std::array<u64,3>{v_c36, v_c43, v_c41}, [&](const std::array<u64,3>& m107) {
            slog::join_probe<3,3>($seq_atrindex84, std::array<u64,3>{v_c38, v_c43, v_c41}, [&](const std::array<u64,3>& m108) {
              if (!slog::exists_probe<2,1>(_enumindex85, std::array<u64,2>{v_c31, 0})) return;
              slog::join_probe<3,2>(deltaindex86, std::array<u64,3>{v_c32, v_c41, 0}, [&](const std::array<u64,3>& m109) {
                u64 v_c44 = m109[2];
                slog::join_probe<2,1>(_enumindex87, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m110) {
                  u64 v_c45 = m110[1];
                  u64 v_c46 = _prim_llen(db, v_c42);
                  if (v_c46 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c33 != v_c46) return;
                  bool ok111 = true;
                  u64 v_c47 = _prim_lref(db, v_c42, v_c35, &ok111);
                  if (!ok111) return;
                  if (v_c40 != v_c47) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c44});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c45}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:120", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask88* _cont = new ReadTask88(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask88(db,b), false);
  // (crule (pre) (scan eval __t7KQr51 __t9rGt50 c) (body (join app (0 1 2) 1 __t9rGt50 ef es)) (head (emit $sup56712x74x0x0x0 (0 1 2 3) __t7KQr51 c ef es)) interp.slog:75 #f)
  class ReadTask113 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex112;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x74x0x0x0");
      std::vector<u16> ord114({0, 1, 2, 3});
      slog::Relation* readrel115 = db->getRelation("$sup56712x74x0x0x0");
      head_index[0] = readrel115->getIndex(ord114, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord116({0, 1, 2});
      slog::Relation* readrel117 = db->getRelation("app");
      appindex112 = readrel117->getIndex(ord116, false);
  
    }
    ReadTask113(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c48 = _t[0];
        u64 v_c49 = _t[1];
        u64 v_c50 = _t[2];
        slog::join_probe<3,1>(appindex112, std::array<u64,3>{v_c49, 0, 0}, [&](const std::array<u64,3>& m118) {
          u64 v_c51 = m118[1]; u64 v_c52 = m118[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c48, v_c50, v_c51, v_c52}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask113* _cont = new ReadTask113(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask113(db,b), false);
  // (crule (pre (let __tconst9XQ5142 const06abaa100ecef791ce028c56) (let _00024sqc41dF446 constd4735e3a265e16eee03f5971) (let _00024sqc5yoB447 const5feceb66ffc86f38d952786c) (let _00024sqc1Cqz448 const6b86b273ff34fce19d6b804e) (let _00024sqo7aST449 const5feceb66ffc86f38d952786c) (let _00024sqo1C1f450 const6b86b273ff34fce19d6b804e) (let _00024sqo1Q0D451 const6b86b273ff34fce19d6b804e) (let _00024sqo7GLE452 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo1Q0D451 __t4Puk145 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7aST449 __t4Puk145 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo1C1f450 __t4Puk145 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7GLE452 __t4Puk145 _00024seq2) (join delta (1 2 0) 2 __tconst9XQ5142 _00024seq2 __t9sdv143) (join closure (0 1 2) 1 __t4Puk145 lm cb) (join any_bool (0) 0 b) (letp _00024sql8vYG444 (aslst _00024seq2)) (let chk4KIZ924 (llen _00024sql8vYG444)) (eq _00024sqc41dF446 chk4KIZ924) (letp chk9ATI925 (lref _00024sql8vYG444 _00024sqc5yoB447)) (eq __t4Puk145 chk9ATI925) (letp chk14GC926 (lref _00024sql8vYG444 _00024sqc1Cqz448)) (eq __t4Puk145 chk14GC926)) (head (emit-temp temp8OpH912 __t9sdv143 b) (mkstruct boolval (1 0) __t9Ain141 b)) interp.slog:122 #f)
  class ReadTask126 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex119;  slog::Index** $seq_atindex120;  slog::Index** $seq_atrindex121;  slog::Index** deltaindex122;  slog::Index** closureindex123;  slog::Index** any_boolindex124;  slog::Index** $seq_atrdelta125;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8OpH912");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord127({1, 0, 2});
      slog::Relation* readrel128 = db->getRelation("$seq_atr");
      driver_index = readrel128->getIndex(ord127, true);
      std::vector<u16> ord129({1, 0, 2});
      slog::Relation* readrel130 = db->getRelation("$seq_at");
      $seq_atindex119 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({1, 0, 2});
      slog::Relation* readrel132 = db->getRelation("$seq_at");
      $seq_atindex120 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 0, 2});
      slog::Relation* readrel134 = db->getRelation("$seq_atr");
      $seq_atrindex121 = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 0, 2});
      slog::Relation* readrel136 = db->getRelation("$seq_atr");
      $seq_atrdelta125 = readrel136->getIndex(ord135, true);
      std::vector<u16> ord137({1, 2, 0});
      slog::Relation* readrel138 = db->getRelation("delta");
      deltaindex122 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({0, 1, 2});
      slog::Relation* readrel140 = db->getRelation("closure");
      closureindex123 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({0});
      slog::Relation* readrel142 = db->getRelation("any_bool");
      any_boolindex124 = readrel142->getIndex(ord141, false);
  
    }
    ReadTask126(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c53 = v_const06abaa100ecef791ce028c56;
      u64 v_c54 = v_constd4735e3a265e16eee03f5971;
      u64 v_c55 = v_const5feceb66ffc86f38d952786c;
      u64 v_c56 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c57 = v_const5feceb66ffc86f38d952786c;
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c59 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c59, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m143) {
        u64 v_c61 = m143[1];
        u64 v_c23 = m143[2];
        if (buckethash(v_c61) != bucket) return;
        slog::join_probe<3,3>($seq_atindex119, std::array<u64,3>{v_c57, v_c61, v_c23}, [&](const std::array<u64,3>& m144) {
          slog::join_probe<3,3>($seq_atindex120, std::array<u64,3>{v_c58, v_c61, v_c23}, [&](const std::array<u64,3>& m145) {
            slog::join_probe_old<3,3>($seq_atrindex121, $seq_atrdelta125, std::array<u64,3>{v_c60, v_c61, v_c23}, [&](const std::array<u64,3>& m146) {
              slog::join_probe<3,2>(deltaindex122, std::array<u64,3>{v_c53, v_c23, 0}, [&](const std::array<u64,3>& m147) {
                u64 v_c62 = m147[2];
                slog::join_probe<3,1>(closureindex123, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m148) {
                  u64 v_c63 = m148[1]; u64 v_c64 = m148[2];
                  slog::join_all<1>(any_boolindex124, [&](const std::array<u64,1>& m149) {
                    u64 v_c26 = m149[0];
                    bool ok150 = true;
                    u64 v_c65 = _prim_aslst(db, v_c23, &ok150);
                    if (!ok150) return;
                    u64 v_c66 = _prim_llen(db, v_c65);
                    if (v_c66 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c54 != v_c66) return;
                    bool ok151 = true;
                    u64 v_c67 = _prim_lref(db, v_c65, v_c55, &ok151);
                    if (!ok151) return;
                    if (v_c61 != v_c67) return;
                    bool ok152 = true;
                    u64 v_c68 = _prim_lref(db, v_c65, v_c56, &ok152);
                    if (!ok152) return;
                    if (v_c61 != v_c68) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c62, v_c26});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c26}, std::array<u16,2>{1, 0});
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
        ReadTask126* _cont = new ReadTask126(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask126(db,b), false);
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5) (let __tconst0xiC106 const30f8b180d63559f2512b744f) (let __tconst1ae2105 constba2df4903a2c14e86dc3bcca) (let __tconst7lFL83 const2bc983a5942276eb00a75e21) (let __tconst8Fnl80 const7297d2085ea0adffc396d546) (let __tconst8n1H73 const6b86b273ff34fce19d6b804e) (let __tconst2U2F71 constef2d127de37b942baad06145) (let __t5Wmv107 (lempty))) (once) (body) (head (emit-temp temp54az998 __t5Wmv107) (mkstruct ref (1 0) __t2Kfn98 __tconst0xiC106) (mkstruct ref (1 0) __t3lY294 __tconst1ae2105) (mkstruct ref (1 0) __t0iVM91 __tconst2uSL111) (mkstruct ref (1 0) __t0mBu81 __tconst8Fnl80) (mkstruct ref (1 0) __t4enh76 __tconst7lFL83) (mkstruct num (1 0) __t7RPv74 __tconst8n1H73) (mkstruct num (1 0) __t8tX372 __tconst2U2F71)) analysis-demo.slog:11 #f)
  class ReadTask153 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[8];
    slog::Index** head_index[8];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp54az998");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("ref");
      head_rel[6] = db->getRelation("num");
      head_rel[7] = db->getRelation("num");
  
    }
    ReadTask153(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c69 = v_const0457bba0679825d285ef7fa5;
      u64 v_c70 = v_const30f8b180d63559f2512b744f;
      u64 v_c71 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c72 = v_const2bc983a5942276eb00a75e21;
      u64 v_c73 = v_const7297d2085ea0adffc396d546;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c75 = v_constef2d127de37b942baad06145;
      u64 v_c76 = _prim_lempty(db);
      if (v_c76 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[8];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c76});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c70}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c71}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c69}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c73}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c72}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c74}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c75}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask153(db,b), true);
  // (crule (pre (let __tconst7saS665 constb9e118781cea1f9fa01462e0) (let __tconst4R6j353 const60e3114d9b4b6577eea8cbc0) (let _00024sqc9CpF541 const6b86b273ff34fce19d6b804e) (let _00024sqc8vSl542 const5feceb66ffc86f38d952786c) (let _00024sqo1EFx543 const5feceb66ffc86f38d952786c) (let _00024sqo1k6Q544 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo1EFx543 v _00024seq0) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1k6Q544 v _00024seq0) (exists _enum (1 0) 1 __tconst7saS665) (join delta (1 2 0) 2 __tconst4R6j353 _00024seq0 __t1geM354) (join _enum (1 0) 1 __tconst7saS665 __t73g6351) (join scheme_false (0) 0 fv) (neq v fv) (letp _00024sql7fhi539 (aslst _00024seq0)) (let chk9jID1037 (llen _00024sql7fhi539)) (eq _00024sqc9CpF541 chk9jID1037) (letp chk7Aur1038 (lref _00024sql7fhi539 _00024sqc8vSl542)) (eq v chk7Aur1038)) (head (emit-temp temp9mFJ1033 __t1geM354) (mkstruct boolval (1 0) __t1MPL352 __t73g6351)) interp.slog:114 #f)
  class ReadTask160 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex154;  slog::Index** _enumindex155;  slog::Index** deltaindex156;  slog::Index** _enumindex157;  slog::Index** scheme_falseindex158;  slog::Index** $seq_atrdelta159;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9mFJ1033");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord161({1, 0, 2});
      slog::Relation* readrel162 = db->getRelation("$seq_at");
      driver_index = readrel162->getIndex(ord161, true);
      std::vector<u16> ord163({1, 0, 2});
      slog::Relation* readrel164 = db->getRelation("$seq_atr");
      $seq_atrindex154 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 0, 2});
      slog::Relation* readrel166 = db->getRelation("$seq_atr");
      $seq_atrdelta159 = readrel166->getIndex(ord165, true);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("_enum");
      _enumindex155 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("delta");
      deltaindex156 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 0});
      slog::Relation* readrel172 = db->getRelation("_enum");
      _enumindex157 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({0});
      slog::Relation* readrel174 = db->getRelation("scheme_false");
      scheme_falseindex158 = readrel174->getIndex(ord173, false);
  
    }
    ReadTask160(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c77 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c78 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c80 = v_const5feceb66ffc86f38d952786c;
      u64 v_c81 = v_const5feceb66ffc86f38d952786c;
      u64 v_c82 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c81, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m175) {
        u64 v_c83 = m175[1];
        u64 v_c41 = m175[2];
        if (buckethash(v_c83) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex154, $seq_atrdelta159, std::array<u64,3>{v_c82, v_c83, v_c41}, [&](const std::array<u64,3>& m176) {
          if (!slog::exists_probe<2,1>(_enumindex155, std::array<u64,2>{v_c77, 0})) return;
          slog::join_probe<3,2>(deltaindex156, std::array<u64,3>{v_c78, v_c41, 0}, [&](const std::array<u64,3>& m177) {
            u64 v_c84 = m177[2];
            slog::join_probe<2,1>(_enumindex157, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m178) {
              u64 v_c85 = m178[1];
              slog::join_all<1>(scheme_falseindex158, [&](const std::array<u64,1>& m179) {
                u64 v_c86 = m179[0];
                if (v_c83 == v_c86) return;
                bool ok180 = true;
                u64 v_c87 = _prim_aslst(db, v_c41, &ok180);
                if (!ok180) return;
                u64 v_c88 = _prim_llen(db, v_c87);
                if (v_c88 == slog_error) { slog::emit_pending_error(db, "interp.slog:114"); return; }
                if (v_c79 != v_c88) return;
                bool ok181 = true;
                u64 v_c89 = _prim_lref(db, v_c87, v_c80, &ok181);
                if (!ok181) return;
                if (v_c83 != v_c89) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c84});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c85}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:114", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask160* _cont = new ReadTask160(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask160(db,b), false);
  // (crule (pre) (scan binding y cb vy) (body (join-old freevar (0 1) 1 (0 1) y __t8awf114) (join-old lambda (0 1 2) 1 (0 1 2) __t8awf114 xs eb) (join-old eval (0 2 1) 0 (0 2 1) __88TM561 c __t4vf0113) (join-old app (0 1 2) 1 (0 1 2) __t4vf0113 ef es)) (head (mkstruct eval (1 2 0) __7s92562 ef c)) interp.slog:56 #f)
  class ReadTask190 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex182;  slog::Index** lambdaindex183;  slog::Index** evalindex184;  slog::Index** appindex185;  slog::Index** freevardelta186;  slog::Index** lambdadelta187;  slog::Index** evaldelta188;  slog::Index** appdelta189;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord191({0, 1});
      slog::Relation* readrel192 = db->getRelation("freevar");
      freevarindex182 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({0, 1});
      slog::Relation* readrel194 = db->getRelation("freevar");
      freevardelta186 = readrel194->getIndex(ord193, true);
      std::vector<u16> ord195({0, 1, 2});
      slog::Relation* readrel196 = db->getRelation("lambda");
      lambdaindex183 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({0, 1, 2});
      slog::Relation* readrel198 = db->getRelation("lambda");
      lambdadelta187 = readrel198->getIndex(ord197, true);
      std::vector<u16> ord199({0, 2, 1});
      slog::Relation* readrel200 = db->getRelation("eval");
      evalindex184 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({0, 2, 1});
      slog::Relation* readrel202 = db->getRelation("eval");
      evaldelta188 = readrel202->getIndex(ord201, true);
      std::vector<u16> ord203({0, 1, 2});
      slog::Relation* readrel204 = db->getRelation("app");
      appindex185 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({0, 1, 2});
      slog::Relation* readrel206 = db->getRelation("app");
      appdelta189 = readrel206->getIndex(ord205, true);
  
    }
    ReadTask190(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c90 = _t[0];
        u64 v_c64 = _t[1];
        u64 v_c91 = _t[2];
        slog::join_probe_old<2,1>(freevarindex182, freevardelta186, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m207) {
          u64 v_c92 = m207[1];
          slog::join_probe_old<3,1>(lambdaindex183, lambdadelta187, std::array<u64,3>{v_c92, 0, 0}, [&](const std::array<u64,3>& m208) {
            u64 v_c93 = m208[1]; u64 v_c94 = m208[2];
            slog::join_all_old<3>(evalindex184, evaldelta188, [&](const std::array<u64,3>& m209) {
              u64 v_c95 = m209[0]; u64 v_c50 = m209[1]; u64 v_c96 = m209[2];
              slog::join_probe_old<3,1>(appindex185, appdelta189, std::array<u64,3>{v_c96, 0, 0}, [&](const std::array<u64,3>& m210) {
                u64 v_c51 = m210[1]; u64 v_c52 = m210[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c51, v_c50}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:binding", _fires);
  
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
  // (crule (pre) (scan select_branch __t13sL3 tv e2 e3) (body (join scheme_false (0) 0 fv) (neq tv fv)) (head (emit select_branch_ans (0 1) __t13sL3 e2)) interp.slog:85 #f)
  class ReadTask212 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** scheme_falseindex211;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord213({0, 1});
      slog::Relation* readrel214 = db->getRelation("select_branch_ans");
      head_index[0] = readrel214->getIndex(ord213, false);
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord215({0});
      slog::Relation* readrel216 = db->getRelation("scheme_false");
      scheme_falseindex211 = readrel216->getIndex(ord215, false);
  
    }
    ReadTask212(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c97 = _t[0];
        u64 v_c98 = _t[1];
        u64 v_c99 = _t[2];
        u64 v_c100 = _t[3];
        slog::join_all<1>(scheme_falseindex211, [&](const std::array<u64,1>& m217) {
          u64 v_c86 = m217[0];
          if (v_c98 == v_c86) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c97, v_c99}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:85", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask212* _cont = new ReadTask212(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask212(db,b), false);
  // (crule (pre (let __tconst6UQc687 constb9e118781cea1f9fa01462e0) (let __tconst2Qtx688 const0122baa3ac55f1b433944eb1) (let __tconst6Cg6137 const60e3114d9b4b6577eea8cbc0) (let _00024sqc9tfN494 const6b86b273ff34fce19d6b804e) (let _00024sqc0jHU495 const5feceb66ffc86f38d952786c) (let _00024sqo7x4Q496 const5feceb66ffc86f38d952786c) (let _00024sqo5KfU497 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo5KfU497 __t687V140 _00024seq1) (body (join $seq_at (1 0 2) 3 _00024sqo7x4Q496 __t687V140 _00024seq1) (exists _enum (1 0) 1 __tconst6UQc687) (exists _enum (1 0) 1 __tconst2Qtx688) (join delta (1 2 0) 2 __tconst6Cg6137 _00024seq1 __t2pLy138) (join _enum (1 0) 1 __tconst6UQc687 __t4aV2139) (join boolval (0 1) 2 __t687V140 __t4aV2139) (join _enum (1 0) 1 __tconst2Qtx688 __t67wA135) (letp _00024sql9r92492 (aslst _00024seq1)) (let chk7dbC996 (llen _00024sql9r92492)) (eq _00024sqc9tfN494 chk7dbC996) (letp chk5VPv997 (lref _00024sql9r92492 _00024sqc0jHU495)) (eq __t687V140 chk5VPv997)) (head (emit-temp temp0a5K990 __t2pLy138) (mkstruct boolval (1 0) __t5iPS136 __t67wA135)) interp.slog:113 #f)
  class ReadTask225 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex218;  slog::Index** _enumindex219;  slog::Index** _enumindex220;  slog::Index** deltaindex221;  slog::Index** _enumindex222;  slog::Index** boolvalindex223;  slog::Index** _enumindex224;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0a5K990");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord226({1, 0, 2});
      slog::Relation* readrel227 = db->getRelation("$seq_atr");
      driver_index = readrel227->getIndex(ord226, true);
      std::vector<u16> ord228({1, 0, 2});
      slog::Relation* readrel229 = db->getRelation("$seq_at");
      $seq_atindex218 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("_enum");
      _enumindex219 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("_enum");
      _enumindex220 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 0});
      slog::Relation* readrel235 = db->getRelation("delta");
      deltaindex221 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 0});
      slog::Relation* readrel237 = db->getRelation("_enum");
      _enumindex222 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({0, 1});
      slog::Relation* readrel239 = db->getRelation("boolval");
      boolvalindex223 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 0});
      slog::Relation* readrel241 = db->getRelation("_enum");
      _enumindex224 = readrel241->getIndex(ord240, false);
  
    }
    ReadTask225(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c1 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c2 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c6, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m242) {
        u64 v_c10 = m242[1];
        u64 v_c7 = m242[2];
        if (buckethash(v_c10) != bucket) return;
        slog::join_probe<3,3>($seq_atindex218, std::array<u64,3>{v_c5, v_c10, v_c7}, [&](const std::array<u64,3>& m243) {
          if (!slog::exists_probe<2,1>(_enumindex219, std::array<u64,2>{v_c0, 0})) return;
          if (!slog::exists_probe<2,1>(_enumindex220, std::array<u64,2>{v_c1, 0})) return;
          slog::join_probe<3,2>(deltaindex221, std::array<u64,3>{v_c2, v_c7, 0}, [&](const std::array<u64,3>& m244) {
            u64 v_c8 = m244[2];
            slog::join_probe<2,1>(_enumindex222, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m245) {
              u64 v_c11 = m245[1];
              slog::join_probe<2,2>(boolvalindex223, std::array<u64,2>{v_c10, v_c11}, [&](const std::array<u64,2>& m246) {
                slog::join_probe<2,1>(_enumindex224, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m247) {
                  u64 v_c12 = m247[1];
                  bool ok248 = true;
                  u64 v_c9 = _prim_aslst(db, v_c7, &ok248);
                  if (!ok248) return;
                  u64 v_c101 = _prim_llen(db, v_c9);
                  if (v_c101 == slog_error) { slog::emit_pending_error(db, "interp.slog:113"); return; }
                  if (v_c3 != v_c101) return;
                  bool ok249 = true;
                  u64 v_c102 = _prim_lref(db, v_c9, v_c4, &ok249);
                  if (!ok249) return;
                  if (v_c10 != v_c102) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c8});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
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
        ReadTask225* _cont = new ReadTask225(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask225(db,b), false);
  // (crule (pre) (scan eval __t4RAT208 __t1ou9207 c) (body (join ref (0 1) 1 __t1ou9207 x)) (head (mkstruct lookup (1 2 0) __54Gi608 x c)) interp.slog:30 #f)
  class ReadTask251 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex250;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord252({0, 1});
      slog::Relation* readrel253 = db->getRelation("ref");
      refindex250 = readrel253->getIndex(ord252, false);
  
    }
    ReadTask251(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c103 = _t[0];
        u64 v_c104 = _t[1];
        u64 v_c50 = _t[2];
        slog::join_probe<2,1>(refindex250, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m254) {
          u64 v_c105 = m254[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c105, v_c50}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask251* _cont = new ReadTask251(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask251(db,b), false);
  // (crule (pre (let __tconst36mF602 constcd2a69ce5ca278db1d6da969) (let __tconst4MYs19 const06abaa100ecef791ce028c56) (let _00024sqc0R1w414 constd4735e3a265e16eee03f5971) (let _00024sqc2r3q415 const5feceb66ffc86f38d952786c) (let _00024sqc1pwY416 const6b86b273ff34fce19d6b804e) (let _00024sqo5Wc9417 const5feceb66ffc86f38d952786c) (let _00024sqo4N7A418 const6b86b273ff34fce19d6b804e) (let _00024sqo8u9a419 const6b86b273ff34fce19d6b804e) (let _00024sqo9jvY420 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo9jvY420 __t2nOL22 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5Wc9417 __t2nOL22 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo4N7A418 __t2nOL22 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo8u9a419 __t2nOL22 _00024seq2) (join _enum (0 1) 2 __t2nOL22 __tconst36mF602) (join delta (1 2 0) 2 __tconst4MYs19 _00024seq2 __t9afR20) (join any_bool (0) 0 b) (letp _00024sql9osm412 (aslst _00024seq2)) (let chk5RH2856 (llen _00024sql9osm412)) (eq _00024sqc0R1w414 chk5RH2856) (letp chk8tfn857 (lref _00024sql9osm412 _00024sqc2r3q415)) (eq __t2nOL22 chk8tfn857) (letp chk2H8y858 (lref _00024sql9osm412 _00024sqc1pwY416)) (eq __t2nOL22 chk2H8y858)) (head (emit-temp temp4fHg844 __t9afR20 b) (mkstruct boolval (1 0) __t975c18 b)) interp.slog:121 #f)
  class ReadTask261 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex255;  slog::Index** $seq_atindex256;  slog::Index** $seq_atrindex257;  slog::Index** _enumindex258;  slog::Index** deltaindex259;  slog::Index** any_boolindex260;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4fHg844");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord262({1, 0, 2});
      slog::Relation* readrel263 = db->getRelation("$seq_atr");
      driver_index = readrel263->getIndex(ord262, true);
      std::vector<u16> ord264({1, 0, 2});
      slog::Relation* readrel265 = db->getRelation("$seq_at");
      $seq_atindex255 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 0, 2});
      slog::Relation* readrel267 = db->getRelation("$seq_at");
      $seq_atindex256 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 0, 2});
      slog::Relation* readrel269 = db->getRelation("$seq_atr");
      $seq_atrindex257 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("_enum");
      _enumindex258 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 2, 0});
      slog::Relation* readrel273 = db->getRelation("delta");
      deltaindex259 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({0});
      slog::Relation* readrel275 = db->getRelation("any_bool");
      any_boolindex260 = readrel275->getIndex(ord274, false);
  
    }
    ReadTask261(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c106 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c107 = v_const06abaa100ecef791ce028c56;
      u64 v_c108 = v_constd4735e3a265e16eee03f5971;
      u64 v_c109 = v_const5feceb66ffc86f38d952786c;
      u64 v_c110 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c111 = v_const5feceb66ffc86f38d952786c;
      u64 v_c112 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c113 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c114 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c114, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m276) {
        u64 v_c115 = m276[1];
        u64 v_c23 = m276[2];
        if (buckethash(v_c115) != bucket) return;
        slog::join_probe<3,3>($seq_atindex255, std::array<u64,3>{v_c111, v_c115, v_c23}, [&](const std::array<u64,3>& m277) {
          slog::join_probe<3,3>($seq_atindex256, std::array<u64,3>{v_c112, v_c115, v_c23}, [&](const std::array<u64,3>& m278) {
            slog::join_probe<3,3>($seq_atrindex257, std::array<u64,3>{v_c113, v_c115, v_c23}, [&](const std::array<u64,3>& m279) {
              slog::join_probe<2,2>(_enumindex258, std::array<u64,2>{v_c115, v_c106}, [&](const std::array<u64,2>& m280) {
                slog::join_probe<3,2>(deltaindex259, std::array<u64,3>{v_c107, v_c23, 0}, [&](const std::array<u64,3>& m281) {
                  u64 v_c116 = m281[2];
                  slog::join_all<1>(any_boolindex260, [&](const std::array<u64,1>& m282) {
                    u64 v_c26 = m282[0];
                    bool ok283 = true;
                    u64 v_c117 = _prim_aslst(db, v_c23, &ok283);
                    if (!ok283) return;
                    u64 v_c118 = _prim_llen(db, v_c117);
                    if (v_c118 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c108 != v_c118) return;
                    bool ok284 = true;
                    u64 v_c119 = _prim_lref(db, v_c117, v_c109, &ok284);
                    if (!ok284) return;
                    if (v_c115 != v_c119) return;
                    bool ok285 = true;
                    u64 v_c120 = _prim_lref(db, v_c117, v_c110, &ok285);
                    if (!ok285) return;
                    if (v_c115 != v_c120) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c116, v_c26});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c26}, std::array<u16,2>{1, 0});
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
        ReadTask261* _cont = new ReadTask261(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask261(db,b), false);
  // (crule (pre (let __tconst0flI607 const0122baa3ac55f1b433944eb1) (let __tconst2Cp4303 const06abaa100ecef791ce028c56) (let _00024sqc21WF437 constd4735e3a265e16eee03f5971) (let _00024sqc91nv438 const5feceb66ffc86f38d952786c) (let _00024sqc5PZ7439 const6b86b273ff34fce19d6b804e) (let _00024sqo16uv440 const5feceb66ffc86f38d952786c) (let _00024sqo3GRa441 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vbm442 const6b86b273ff34fce19d6b804e) (let _00024sqo8B0L443 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo16uv440 __t9eYl306 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo3GRa441 __t9eYl306 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2Vbm442 __t9eYl306 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8B0L443 __t9eYl306 _00024seq2) (exists _enum (1 0) 1 __tconst0flI607) (join delta (1 2 0) 2 __tconst2Cp4303 _00024seq2 __t2i9A304) (join _enum (1 0) 1 __tconst0flI607 __t8LeX301) (join boolval (0 1) 1 __t9eYl306 b) (letp _00024sql7hRC435 (aslst _00024seq2)) (let chk4FlS1019 (llen _00024sql7hRC435)) (eq _00024sqc21WF437 chk4FlS1019) (letp chk16fF1020 (lref _00024sql7hRC435 _00024sqc91nv438)) (eq __t9eYl306 chk16fF1020) (letp chk7jsu1021 (lref _00024sql7hRC435 _00024sqc5PZ7439)) (eq __t9eYl306 chk7jsu1021)) (head (emit-temp temp61mi1013 __t2i9A304) (mkstruct boolval (1 0) __t5m8l302 __t8LeX301)) interp.slog:118 #f)
  class ReadTask296 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex286;  slog::Index** $seq_atrindex287;  slog::Index** $seq_atrindex288;  slog::Index** _enumindex289;  slog::Index** deltaindex290;  slog::Index** _enumindex291;  slog::Index** boolvalindex292;  slog::Index** $seq_atdelta293;  slog::Index** $seq_atrdelta294;  slog::Index** $seq_atrdelta295;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp61mi1013");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord297({1, 0, 2});
      slog::Relation* readrel298 = db->getRelation("$seq_at");
      driver_index = readrel298->getIndex(ord297, true);
      std::vector<u16> ord299({1, 0, 2});
      slog::Relation* readrel300 = db->getRelation("$seq_at");
      $seq_atindex286 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 0, 2});
      slog::Relation* readrel302 = db->getRelation("$seq_at");
      $seq_atdelta293 = readrel302->getIndex(ord301, true);
      std::vector<u16> ord303({1, 0, 2});
      slog::Relation* readrel304 = db->getRelation("$seq_atr");
      $seq_atrindex287 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({1, 0, 2});
      slog::Relation* readrel306 = db->getRelation("$seq_atr");
      $seq_atrdelta294 = readrel306->getIndex(ord305, true);
      std::vector<u16> ord307({1, 0, 2});
      slog::Relation* readrel308 = db->getRelation("$seq_atr");
      $seq_atrindex288 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({1, 0, 2});
      slog::Relation* readrel310 = db->getRelation("$seq_atr");
      $seq_atrdelta295 = readrel310->getIndex(ord309, true);
      std::vector<u16> ord311({1, 0});
      slog::Relation* readrel312 = db->getRelation("_enum");
      _enumindex289 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 2, 0});
      slog::Relation* readrel314 = db->getRelation("delta");
      deltaindex290 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 0});
      slog::Relation* readrel316 = db->getRelation("_enum");
      _enumindex291 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({0, 1});
      slog::Relation* readrel318 = db->getRelation("boolval");
      boolvalindex292 = readrel318->getIndex(ord317, false);
  
    }
    ReadTask296(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c121 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c122 = v_const06abaa100ecef791ce028c56;
      u64 v_c123 = v_constd4735e3a265e16eee03f5971;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c126, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m319) {
        u64 v_c130 = m319[1];
        u64 v_c23 = m319[2];
        if (buckethash(v_c130) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex286, $seq_atdelta293, std::array<u64,3>{v_c127, v_c130, v_c23}, [&](const std::array<u64,3>& m320) {
          slog::join_probe_old<3,3>($seq_atrindex287, $seq_atrdelta294, std::array<u64,3>{v_c128, v_c130, v_c23}, [&](const std::array<u64,3>& m321) {
            slog::join_probe_old<3,3>($seq_atrindex288, $seq_atrdelta295, std::array<u64,3>{v_c129, v_c130, v_c23}, [&](const std::array<u64,3>& m322) {
              if (!slog::exists_probe<2,1>(_enumindex289, std::array<u64,2>{v_c121, 0})) return;
              slog::join_probe<3,2>(deltaindex290, std::array<u64,3>{v_c122, v_c23, 0}, [&](const std::array<u64,3>& m323) {
                u64 v_c131 = m323[2];
                slog::join_probe<2,1>(_enumindex291, std::array<u64,2>{v_c121, 0}, [&](const std::array<u64,2>& m324) {
                  u64 v_c132 = m324[1];
                  slog::join_probe<2,1>(boolvalindex292, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m325) {
                    u64 v_c26 = m325[1];
                    bool ok326 = true;
                    u64 v_c133 = _prim_aslst(db, v_c23, &ok326);
                    if (!ok326) return;
                    u64 v_c134 = _prim_llen(db, v_c133);
                    if (v_c134 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c123 != v_c134) return;
                    bool ok327 = true;
                    u64 v_c135 = _prim_lref(db, v_c133, v_c124, &ok327);
                    if (!ok327) return;
                    if (v_c130 != v_c135) return;
                    bool ok328 = true;
                    u64 v_c136 = _prim_lref(db, v_c133, v_c125, &ok328);
                    if (!ok328) return;
                    if (v_c130 != v_c136) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c131});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c132}, std::array<u16,2>{1, 0});
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
        ReadTask296* _cont = new ReadTask296(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask296(db,b), false);
  // (crule (pre (let __tconst4znW669 constcd2a69ce5ca278db1d6da969) (let _00024sqc3H5i520 constd4735e3a265e16eee03f5971) (let _00024sqc4tob521 const5feceb66ffc86f38d952786c) (let _00024sqc5Dhg522 const6b86b273ff34fce19d6b804e) (let _00024sqo4wSo523 const5feceb66ffc86f38d952786c) (let _00024sqo3X5o524 const6b86b273ff34fce19d6b804e) (let _00024sqo10Lc525 const6b86b273ff34fce19d6b804e) (let _00024sqo1tMi526 const5feceb66ffc86f38d952786c) (let __trid6dum670 consteefaed435882b14b69e99d78) (let __trel5mCG671 constdede4476644eb06b5a48b866) (let __tcol9ZQn672 const6b86b273ff34fce19d6b804e)) (probe $seq_at (1 0 2) 1 _00024sqo3X5o524 __t5cN641 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo4wSo523 __t5cN641 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo10Lc525 __t5cN641 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1tMi526 __t5cN641 _00024seq2) (join _enum (0 1) 2 __t5cN641 __tconst4znW669) (join delta (2 0 1) 1 _00024seq2 __t2MSw39 op) (join arithmetic_op (0) 1 op) (letp _00024sql8wbR518 (aslst _00024seq2)) (let chk0mbM903 (llen _00024sql8wbR518)) (eq _00024sqc3H5i520 chk0mbM903) (letp chk4vKI904 (lref _00024sql8wbR518 _00024sqc4tob521)) (eq __t5cN641 chk4vKI904) (letp chk9kZT905 (lref _00024sql8wbR518 _00024sqc5Dhg522)) (eq __t5cN641 chk9kZT905)) (head (tycheck __t5cN641 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid6dum670 __trel5mCG671 __tcol9ZQn672 (1 2 3 4 0)) (emit delta_ans (0 1) __t2MSw39 __t5cN641)) interp.slog:111 #f)
  class ReadTask342 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex329;  slog::Index** $seq_atrindex330;  slog::Index** $seq_atrindex331;  slog::Index** _enumindex332;  slog::Index** deltaindex333;  slog::Index** arithmetic_opindex334;  slog::Index** $seq_atrdelta335;  slog::Index** $seq_atrdelta336;
    u32 sid339;  u32 sid337;  u32 sid338;  u32 sid340;  u32 sid341;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord343({0, 1});
      slog::Relation* readrel344 = db->getRelation("delta_ans");
      head_index[1] = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 0, 2});
      slog::Relation* readrel346 = db->getRelation("$seq_at");
      driver_index = readrel346->getIndex(ord345, true);
      std::vector<u16> ord347({1, 0, 2});
      slog::Relation* readrel348 = db->getRelation("$seq_at");
      $seq_atindex329 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 0, 2});
      slog::Relation* readrel350 = db->getRelation("$seq_atr");
      $seq_atrindex330 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 0, 2});
      slog::Relation* readrel352 = db->getRelation("$seq_atr");
      $seq_atrdelta335 = readrel352->getIndex(ord351, true);
      std::vector<u16> ord353({1, 0, 2});
      slog::Relation* readrel354 = db->getRelation("$seq_atr");
      $seq_atrindex331 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 0, 2});
      slog::Relation* readrel356 = db->getRelation("$seq_atr");
      $seq_atrdelta336 = readrel356->getIndex(ord355, true);
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("_enum");
      _enumindex332 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({2, 0, 1});
      slog::Relation* readrel360 = db->getRelation("delta");
      deltaindex333 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({0});
      slog::Relation* readrel362 = db->getRelation("arithmetic_op");
      arithmetic_opindex334 = readrel362->getIndex(ord361, false);
      sid339 = db->getRelation("_enum")->getStructId();
      sid337 = db->getRelation("boolval")->getStructId();
      sid338 = db->getRelation("closure")->getStructId();
      sid340 = db->getRelation("prim")->getStructId();
      sid341 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask342(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c137 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c138 = v_constd4735e3a265e16eee03f5971;
      u64 v_c139 = v_const5feceb66ffc86f38d952786c;
      u64 v_c140 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c141 = v_const5feceb66ffc86f38d952786c;
      u64 v_c142 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c143 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c144 = v_const5feceb66ffc86f38d952786c;
      u64 v_c145 = v_consteefaed435882b14b69e99d78;
      u64 v_c146 = v_constdede4476644eb06b5a48b866;
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c142, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m363) {
        u64 v_c148 = m363[1];
        u64 v_c23 = m363[2];
        if (buckethash(v_c148) != bucket) return;
        slog::join_probe<3,3>($seq_atindex329, std::array<u64,3>{v_c141, v_c148, v_c23}, [&](const std::array<u64,3>& m364) {
          slog::join_probe_old<3,3>($seq_atrindex330, $seq_atrdelta335, std::array<u64,3>{v_c143, v_c148, v_c23}, [&](const std::array<u64,3>& m365) {
            slog::join_probe_old<3,3>($seq_atrindex331, $seq_atrdelta336, std::array<u64,3>{v_c144, v_c148, v_c23}, [&](const std::array<u64,3>& m366) {
              slog::join_probe<2,2>(_enumindex332, std::array<u64,2>{v_c148, v_c137}, [&](const std::array<u64,2>& m367) {
                slog::join_probe<3,1>(deltaindex333, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m368) {
                  u64 v_c149 = m368[1]; u64 v_c25 = m368[2];
                  slog::join_probe<1,1>(arithmetic_opindex334, std::array<u64,1>{v_c25}, [&](const std::array<u64,1>& m369) {
                    bool ok370 = true;
                    u64 v_c150 = _prim_aslst(db, v_c23, &ok370);
                    if (!ok370) return;
                    u64 v_c151 = _prim_llen(db, v_c150);
                    if (v_c151 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c138 != v_c151) return;
                    bool ok371 = true;
                    u64 v_c152 = _prim_lref(db, v_c150, v_c139, &ok371);
                    if (!ok371) return;
                    if (v_c148 != v_c152) return;
                    bool ok372 = true;
                    u64 v_c153 = _prim_lref(db, v_c150, v_c140, &ok372);
                    if (!ok372) return;
                    if (v_c148 != v_c153) return;
                    ++_fires;
                    if (!((is_struct(v_c148) && (decode_struct_id(v_c148) == sid337 || decode_struct_id(v_c148) == sid338 || decode_struct_id(v_c148) == sid339 || decode_struct_id(v_c148) == sid340 || decode_struct_id(v_c148) == sid341))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c145, v_c146, v_c147, v_c148}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c149, v_c148}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:111", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask342* _cont = new ReadTask342(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask342(db,b), false);
  // (crule (pre) (scan temp86Ay863 __t8LOa148 e es x) (body (let __t60vU149 (lpush __t8LOa148 e))) (head (emit-temp temp8YJO864 __t60vU149 es x)) freevars.slog:35 #f)
  class ReadTask373 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8YJO864");
      outer_rel = db->getRelation("temp86Ay863");
  
    }
    ReadTask373(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c154 = _t[0];
        u64 v_c155 = _t[1];
        u64 v_c52 = _t[2];
        u64 v_c105 = _t[3];
        u64 v_c156 = _prim_lpush(db, v_c154, v_c155);
        if (v_c156 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c156, v_c52, v_c105});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp86Ay863", _fires);
  
      if (!_done)
      {
        ReadTask373* _cont = new ReadTask373(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask373(db,b), false);
  // (crule (pre) (scan temp7a2g934 __t1E6c377 __t1ye1379 __v1) (body (let __t6vuA378 (lcat __t1E6c377 __v1))) (head (emit-temp temp5J1A935 __t1ye1379 __t6vuA378)) interp.slog:38 #f)
  class ReadTask374 : public slog::Task
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
      head_rel[0] = db->getRelation("temp5J1A935");
      outer_rel = db->getRelation("temp7a2g934");
  
    }
    ReadTask374(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c157 = _t[0];
        u64 v_c158 = _t[1];
        u64 v_c159 = _t[2];
        u64 v_c160 = _prim_lcat(db, v_c157, v_c159);
        if (v_c160 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c158, v_c160});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:temp7a2g934", _fires);
  
      if (!_done)
      {
        ReadTask374* _cont = new ReadTask374(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask374(db,b), false);
  // (crule (pre (let __t5FX9367 (lempty))) (scan lst_take __t7KjH370 __t82mC369 m) (body (join mlimit (0) 1 m) (join lst_take_ans (0 1) 1 __t7KjH370 __v0) (join tick (0 2 1) 0 __t18ya366 c site) (let __t70Q4368 (lpush __t5FX9367 site)) (let chk20lA931 (lcat __t70Q4368 c)) (eq __t82mC369 chk20lA931)) (head (emit tick_ans (0 1) __t18ya366 __v0)) context.slog:10 #f)
  class ReadTask378 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mlimitindex375;  slog::Index** lst_take_ansindex376;  slog::Index** tickindex377;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick_ans");
      std::vector<u16> ord379({0, 1});
      slog::Relation* readrel380 = db->getRelation("tick_ans");
      head_index[0] = readrel380->getIndex(ord379, false);
      outer_rel = db->getRelation("lst_take");
      std::vector<u16> ord381({0});
      slog::Relation* readrel382 = db->getRelation("mlimit");
      mlimitindex375 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({0, 1});
      slog::Relation* readrel384 = db->getRelation("lst_take_ans");
      lst_take_ansindex376 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({0, 2, 1});
      slog::Relation* readrel386 = db->getRelation("tick");
      tickindex377 = readrel386->getIndex(ord385, false);
  
    }
    ReadTask378(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c161 = _prim_lempty(db);
      if (v_c161 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c162 = _t[0];
        u64 v_c163 = _t[1];
        u64 v_c164 = _t[2];
        slog::join_probe<1,1>(mlimitindex375, std::array<u64,1>{v_c164}, [&](const std::array<u64,1>& m387) {
          slog::join_probe<2,1>(lst_take_ansindex376, std::array<u64,2>{v_c162, 0}, [&](const std::array<u64,2>& m388) {
            u64 v_c165 = m388[1];
            slog::join_all<3>(tickindex377, [&](const std::array<u64,3>& m389) {
              u64 v_c166 = m389[0]; u64 v_c50 = m389[1]; u64 v_c167 = m389[2];
              u64 v_c168 = _prim_lpush(db, v_c161, v_c167);
              if (v_c168 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
              u64 v_c169 = _prim_lcat(db, v_c168, v_c50);
              if (v_c169 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
              if (v_c163 != v_c169) return;
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c166, v_c165}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:lst_take", _fires);
  
      if (!_done)
      {
        ReadTask378* _cont = new ReadTask378(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask378(db,b), false);
  // (crule (pre (let _00024sqc6SuE404 const6b86b273ff34fce19d6b804e) (let _00024sqc9Utg405 const5feceb66ffc86f38d952786c) (let _00024sqc5uCM406 const6b86b273ff34fce19d6b804e) (let _00024sqc4AZZ407 const5feceb66ffc86f38d952786c) (let __t8LOa148 (lempty))) (scan freevar_in_args x es) (body (join-old argument_list (0) 0 (0) _00024seq0) (letp _00024sql7x6c402 (aslst _00024seq0)) (let _00024sqn8ZMQ403 (llen _00024sql7x6c402)) (cmp ge _00024sqn8ZMQ403 _00024sqc6SuE404) (letp e (lref _00024sql7x6c402 _00024sqc9Utg405)) (let _00024sqp6wOP408 (_0002d _00024sqn8ZMQ403 _00024sqc4AZZ407)) (let chk5PUG1012 (lslice _00024sql7x6c402 _00024sqc5uCM406 _00024sqp6wOP408)) (eq es chk5PUG1012)) (head (emit-temp temp9TwZ1009 __t8LOa148 e es x)) freevars.slog:35 #f)
  class ReadTask392 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** argument_listindex390;  slog::Index** argument_listdelta391;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9TwZ1009");
      outer_rel = db->getRelation("freevar_in_args");
      std::vector<u16> ord393({0});
      slog::Relation* readrel394 = db->getRelation("argument_list");
      argument_listindex390 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({0});
      slog::Relation* readrel396 = db->getRelation("argument_list");
      argument_listdelta391 = readrel396->getIndex(ord395, true);
  
    }
    ReadTask392(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c171 = v_const5feceb66ffc86f38d952786c;
      u64 v_c172 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c173 = v_const5feceb66ffc86f38d952786c;
      u64 v_c154 = _prim_lempty(db);
      if (v_c154 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c105 = _t[0];
        u64 v_c52 = _t[1];
        slog::join_all_old<1>(argument_listindex390, argument_listdelta391, [&](const std::array<u64,1>& m397) {
          u64 v_c41 = m397[0];
          bool ok398 = true;
          u64 v_c174 = _prim_aslst(db, v_c41, &ok398);
          if (!ok398) return;
          u64 v_c175 = _prim_llen(db, v_c174);
          if (v_c175 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
          u64 v_c176 = _prim_ge(db, v_c175, v_c170);
          if (v_c176 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
          if (!v_c176) return;
          bool ok400 = true;
          u64 v_c155 = _prim_lref(db, v_c174, v_c171, &ok400);
          if (!ok400) return;
          u64 v_c177 = _prim__0002d(db, v_c175, v_c173);
          if (v_c177 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
          u64 v_c178 = _prim_lslice(db, v_c174, v_c172, v_c177);
          if (v_c178 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
          if (v_c52 != v_c178) return;
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c154, v_c155, v_c52, v_c105});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:freevar_in_args", _fires);
  
      if (!_done)
      {
        ReadTask392* _cont = new ReadTask392(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask392(db,b), false);
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5)) (scan temp5Kz61004 __t0Gv1110 __t0nIl89) (body (join ref (1 0) 1 __tconst2uSL111 __t0iVM91)) (head (emit-temp temp9U5g1005 __t0Gv1110 __t0nIl89) (mkstruct app (1 2 0) __t7VwH92 __t0iVM91 __t0nIl89)) analysis-demo.slog:11 #f)
  class ReadTask402 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex401;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9U5g1005");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp5Kz61004");
      std::vector<u16> ord403({1, 0});
      slog::Relation* readrel404 = db->getRelation("ref");
      refindex401 = readrel404->getIndex(ord403, false);
  
    }
    ReadTask402(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c69 = v_const0457bba0679825d285ef7fa5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c179 = _t[0];
        u64 v_c180 = _t[1];
        slog::join_probe<2,1>(refindex401, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m405) {
          u64 v_c181 = m405[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c179, v_c180});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c181, v_c180}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "delta:temp5Kz61004", _fires);
  
      if (!_done)
      {
        ReadTask402* _cont = new ReadTask402(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask402(db,b), false);
  // (crule (pre) (scan freevar x eb) (body (join-old lambda (2 0 1) 1 (2 0 1) eb __t0FCM371 xs)) (head (mkstruct lst_absent (1 2 0) __2Kgy664 xs x)) freevars.slog:28 #f)
  class ReadTask408 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex406;  slog::Index** lambdadelta407;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lst_absent");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord409({2, 0, 1});
      slog::Relation* readrel410 = db->getRelation("lambda");
      lambdaindex406 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({2, 0, 1});
      slog::Relation* readrel412 = db->getRelation("lambda");
      lambdadelta407 = readrel412->getIndex(ord411, true);
  
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
        u64 v_c105 = _t[0];
        u64 v_c94 = _t[1];
        slog::join_probe_old<3,1>(lambdaindex406, lambdadelta407, std::array<u64,3>{v_c94, 0, 0}, [&](const std::array<u64,3>& m413) {
          u64 v_c182 = m413[1]; u64 v_c93 = m413[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c93, v_c105}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:freevar", _fires);
  
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
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715)) (scan temp0Rdi966 __t34RH259 __t4sa5291 __t6mUC239 __t7Cof275 __t9Hvd221) (body (join ref (1 0) 1 __tconst4aTz260 __t41cT241)) (head (emit-temp temp1Oz8967 __t34RH259 __t4sa5291 __t6mUC239 __t7Cof275 __t9Hvd221) (mkstruct app (1 2 0) __t1E72242 __t41cT241 __t6mUC239)) analysis-demo.slog:21 #f)
  class ReadTask415 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex414;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Oz8967");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp0Rdi966");
      std::vector<u16> ord416({1, 0});
      slog::Relation* readrel417 = db->getRelation("ref");
      refindex414 = readrel417->getIndex(ord416, false);
  
    }
    ReadTask415(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c183 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c184 = v_constf77801bebb40767a1b303d97;
      u64 v_c185 = v_const829935b42173b360da35f679;
      u64 v_c186 = v_const0388ead47e9d5ccfc5320715;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c187 = _t[0];
        u64 v_c188 = _t[1];
        u64 v_c189 = _t[2];
        u64 v_c190 = _t[3];
        u64 v_c191 = _t[4];
        slog::join_probe<2,1>(refindex414, std::array<u64,2>{v_c185, 0}, [&](const std::array<u64,2>& m418) {
          u64 v_c192 = m418[1];
          ++_fires;
          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c187, v_c188, v_c189, v_c190, v_c191});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c192, v_c189}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp0Rdi966", _fires);
  
      if (!_done)
      {
        ReadTask415* _cont = new ReadTask415(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask415(db,b), false);
  // (crule (pre (let __tconst0flI607 const0122baa3ac55f1b433944eb1) (let __tconst2Cp4303 const06abaa100ecef791ce028c56) (let _00024sqc21WF437 constd4735e3a265e16eee03f5971) (let _00024sqc91nv438 const5feceb66ffc86f38d952786c) (let _00024sqc5PZ7439 const6b86b273ff34fce19d6b804e) (let _00024sqo16uv440 const5feceb66ffc86f38d952786c) (let _00024sqo3GRa441 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vbm442 const6b86b273ff34fce19d6b804e) (let _00024sqo8B0L443 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst2Cp4303 _00024seq2 __t2i9A304) (body (letp _00024sql7hRC435 (aslst _00024seq2)) (letp __t9eYl306 (lref _00024sql7hRC435 _00024sqc91nv438)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo16uv440 __t9eYl306 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo3GRa441 __t9eYl306 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2Vbm442 __t9eYl306 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8B0L443 __t9eYl306 _00024seq2) (join _enum (1 0) 1 __tconst0flI607 __t8LeX301) (join-old boolval (0 1) 1 (0 1) __t9eYl306 b) (let chk9Hxp1014 (llen _00024sql7hRC435)) (eq _00024sqc21WF437 chk9Hxp1014) (letp chk7LCi1015 (lref _00024sql7hRC435 _00024sqc5PZ7439)) (eq __t9eYl306 chk7LCi1015)) (head (emit-temp temp61mi1013 __t2i9A304) (mkstruct boolval (1 0) __t5m8l302 __t8LeX301)) interp.slog:118 #f)
  class ReadTask430 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex419;  slog::Index** $seq_atindex420;  slog::Index** $seq_atrindex421;  slog::Index** $seq_atrindex422;  slog::Index** _enumindex423;  slog::Index** boolvalindex424;  slog::Index** $seq_atdelta425;  slog::Index** $seq_atdelta426;  slog::Index** $seq_atrdelta427;  slog::Index** $seq_atrdelta428;  slog::Index** boolvaldelta429;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp61mi1013");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord431({1, 2, 0});
      slog::Relation* readrel432 = db->getRelation("delta");
      driver_index = readrel432->getIndex(ord431, true);
      std::vector<u16> ord433({1, 0, 2});
      slog::Relation* readrel434 = db->getRelation("$seq_at");
      $seq_atindex419 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({1, 0, 2});
      slog::Relation* readrel436 = db->getRelation("$seq_at");
      $seq_atdelta425 = readrel436->getIndex(ord435, true);
      std::vector<u16> ord437({1, 0, 2});
      slog::Relation* readrel438 = db->getRelation("$seq_at");
      $seq_atindex420 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({1, 0, 2});
      slog::Relation* readrel440 = db->getRelation("$seq_at");
      $seq_atdelta426 = readrel440->getIndex(ord439, true);
      std::vector<u16> ord441({1, 0, 2});
      slog::Relation* readrel442 = db->getRelation("$seq_atr");
      $seq_atrindex421 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 0, 2});
      slog::Relation* readrel444 = db->getRelation("$seq_atr");
      $seq_atrdelta427 = readrel444->getIndex(ord443, true);
      std::vector<u16> ord445({1, 0, 2});
      slog::Relation* readrel446 = db->getRelation("$seq_atr");
      $seq_atrindex422 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 0, 2});
      slog::Relation* readrel448 = db->getRelation("$seq_atr");
      $seq_atrdelta428 = readrel448->getIndex(ord447, true);
      std::vector<u16> ord449({1, 0});
      slog::Relation* readrel450 = db->getRelation("_enum");
      _enumindex423 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({0, 1});
      slog::Relation* readrel452 = db->getRelation("boolval");
      boolvalindex424 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({0, 1});
      slog::Relation* readrel454 = db->getRelation("boolval");
      boolvaldelta429 = readrel454->getIndex(ord453, true);
  
    }
    ReadTask430(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c121 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c122 = v_const06abaa100ecef791ce028c56;
      u64 v_c123 = v_constd4735e3a265e16eee03f5971;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c122, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m455) {
        u64 v_c23 = m455[1];
        u64 v_c131 = m455[2];
        if (buckethash(v_c23) != bucket) return;
        bool ok456 = true;
        u64 v_c133 = _prim_aslst(db, v_c23, &ok456);
        if (!ok456) return;
        bool ok457 = true;
        u64 v_c130 = _prim_lref(db, v_c133, v_c124, &ok457);
        if (!ok457) return;
        slog::join_probe_old<3,3>($seq_atindex419, $seq_atdelta425, std::array<u64,3>{v_c126, v_c130, v_c23}, [&](const std::array<u64,3>& m458) {
          slog::join_probe_old<3,3>($seq_atindex420, $seq_atdelta426, std::array<u64,3>{v_c127, v_c130, v_c23}, [&](const std::array<u64,3>& m459) {
            slog::join_probe_old<3,3>($seq_atrindex421, $seq_atrdelta427, std::array<u64,3>{v_c128, v_c130, v_c23}, [&](const std::array<u64,3>& m460) {
              slog::join_probe_old<3,3>($seq_atrindex422, $seq_atrdelta428, std::array<u64,3>{v_c129, v_c130, v_c23}, [&](const std::array<u64,3>& m461) {
                slog::join_probe<2,1>(_enumindex423, std::array<u64,2>{v_c121, 0}, [&](const std::array<u64,2>& m462) {
                  u64 v_c132 = m462[1];
                  slog::join_probe_old<2,1>(boolvalindex424, boolvaldelta429, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m463) {
                    u64 v_c26 = m463[1];
                    u64 v_c193 = _prim_llen(db, v_c133);
                    if (v_c193 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c123 != v_c193) return;
                    bool ok464 = true;
                    u64 v_c194 = _prim_lref(db, v_c133, v_c125, &ok464);
                    if (!ok464) return;
                    if (v_c130 != v_c194) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c131});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c132}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask430* _cont = new ReadTask430(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask430(db,b), false);
  // (crule (pre) (scan temp7ASG865 __t43VN150 x) (body) (head (emit freevar_in_args (1 0) __t43VN150 x)) freevars.slog:35 #f)
  class ReadTask465 : public slog::Task
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
      head_rel[0] = db->getRelation("freevar_in_args");
      std::vector<u16> ord466({1, 0});
      slog::Relation* readrel467 = db->getRelation("freevar_in_args");
      head_index[0] = readrel467->getIndex(ord466, false);
      outer_rel = db->getRelation("temp7ASG865");
  
    }
    ReadTask465(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c195 = _t[0];
        u64 v_c105 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c195, v_c105}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp7ASG865", _fires);
  
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
  // (crule (pre (let _00024sqc9r51426 const6b86b273ff34fce19d6b804e) (let _00024sqc0a7Y427 const5feceb66ffc86f38d952786c) (let _00024sqc6lAT428 const6b86b273ff34fce19d6b804e) (let _00024sqc6zTj429 const5feceb66ffc86f38d952786c) (let _00024sqo7QcU434 const5feceb66ffc86f38d952786c) (let __t31sY376 (lempty))) (scan eval __t33Oa380 e c) (body (exists $sup56712x37x0x0x0 (2 3 0 1 4) 2 c e) (exists eval_args (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t33Oa380) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo7QcU434 e _00024seq0) (letp _00024sql0xMp424 (aslst _00024seq0)) (let _00024sqn1MBN425 (llen _00024sql0xMp424)) (cmp ge _00024sqn1MBN425 _00024sqc9r51426) (let _00024sqp04Wv430 (_0002d _00024sqn1MBN425 _00024sqc6zTj429)) (let es (lslice _00024sql0xMp424 _00024sqc6lAT428 _00024sqp04Wv430)) (exists eval_args (1 2 0) 2 _00024seq0 c) (exists eval_args (1 2 0) 2 es c) (join $sup56712x37x0x0x0 (0 3 4 2 1) 4 _00024seq0 e es c __t1ye1379) (join eval_args (0 2 1) 3 __t1ye1379 c _00024seq0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5lLk381) (exists eval_args_ans (0 1) 1 __t5lLk381) (join eval_ans (0 1) 1 __t33Oa380 __v0) (join eval_args_ans (0 1) 1 __t5lLk381 __v1) (letp chk0B7W941 (lref _00024sql0xMp424 _00024sqc0a7Y427)) (eq e chk0B7W941)) (head (emit-temp temp0JGK933 __t1ye1379 __t31sY376 __v0 __v1)) interp.slog:38 #f)
  class ReadTask482 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x37x0x0x0index468;  slog::Index** eval_argsindex469;  slog::Index** eval_ansindex470;  slog::Index** $seq_atindex471;  slog::Index** eval_argsindex472;  slog::Index** eval_argsindex473;  slog::Index** $sup56712x37x0x0x0index474;  slog::Index** eval_argsindex475;  slog::Index** eval_argsindex476;  slog::Index** eval_args_ansindex477;  slog::Index** eval_ansindex478;  slog::Index** eval_args_ansindex479;  slog::Index** $seq_atdelta480;  slog::Index** eval_argsdelta481;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0JGK933");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord483({2, 3, 0, 1, 4});
      slog::Relation* readrel484 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index468 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({2, 0, 1});
      slog::Relation* readrel486 = db->getRelation("eval_args");
      eval_argsindex469 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({0, 1});
      slog::Relation* readrel488 = db->getRelation("eval_ans");
      eval_ansindex470 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 0, 2});
      slog::Relation* readrel490 = db->getRelation("$seq_at");
      $seq_atindex471 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({1, 0, 2});
      slog::Relation* readrel492 = db->getRelation("$seq_at");
      $seq_atdelta480 = readrel492->getIndex(ord491, true);
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("eval_args");
      eval_argsindex472 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 0});
      slog::Relation* readrel496 = db->getRelation("eval_args");
      eval_argsindex473 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({0, 3, 4, 2, 1});
      slog::Relation* readrel498 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index474 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0, 2, 1});
      slog::Relation* readrel500 = db->getRelation("eval_args");
      eval_argsindex475 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({1, 2, 0});
      slog::Relation* readrel502 = db->getRelation("eval_args");
      eval_argsindex476 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 2, 0});
      slog::Relation* readrel504 = db->getRelation("eval_args");
      eval_argsdelta481 = readrel504->getIndex(ord503, true);
      std::vector<u16> ord505({0, 1});
      slog::Relation* readrel506 = db->getRelation("eval_args_ans");
      eval_args_ansindex477 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({0, 1});
      slog::Relation* readrel508 = db->getRelation("eval_ans");
      eval_ansindex478 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({0, 1});
      slog::Relation* readrel510 = db->getRelation("eval_args_ans");
      eval_args_ansindex479 = readrel510->getIndex(ord509, false);
  
    }
    ReadTask482(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const5feceb66ffc86f38d952786c;
      u64 v_c200 = v_const5feceb66ffc86f38d952786c;
      u64 v_c201 = _prim_lempty(db);
      if (v_c201 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c202 = _t[0];
        u64 v_c155 = _t[1];
        u64 v_c50 = _t[2];
        if (!slog::exists_probe<5,2>($sup56712x37x0x0x0index468, std::array<u64,5>{v_c50, v_c155, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex469, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex470, std::array<u64,2>{v_c202, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex471, $seq_atdelta480, std::array<u64,3>{v_c200, v_c155, 0}, [&](const std::array<u64,3>& m511) {
          u64 v_c41 = m511[2];
          bool ok512 = true;
          u64 v_c203 = _prim_aslst(db, v_c41, &ok512);
          if (!ok512) return;
          u64 v_c204 = _prim_llen(db, v_c203);
          if (v_c204 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
          u64 v_c205 = _prim_ge(db, v_c204, v_c196);
          if (v_c205 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
          if (!v_c205) return;
          u64 v_c206 = _prim__0002d(db, v_c204, v_c199);
          if (v_c206 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
          u64 v_c52 = _prim_lslice(db, v_c203, v_c198, v_c206);
          if (v_c52 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
          if (!slog::exists_probe<3,2>(eval_argsindex472, std::array<u64,3>{v_c41, v_c50, 0})) return;
          if (!slog::exists_probe<3,2>(eval_argsindex473, std::array<u64,3>{v_c52, v_c50, 0})) return;
          slog::join_probe<5,4>($sup56712x37x0x0x0index474, std::array<u64,5>{v_c41, v_c155, v_c52, v_c50, 0}, [&](const std::array<u64,5>& m514) {
            u64 v_c158 = m514[4];
            slog::join_probe<3,3>(eval_argsindex475, std::array<u64,3>{v_c158, v_c50, v_c41}, [&](const std::array<u64,3>& m515) {
              slog::join_probe_old<3,2>(eval_argsindex476, eval_argsdelta481, std::array<u64,3>{v_c52, v_c50, 0}, [&](const std::array<u64,3>& m516) {
                u64 v_c207 = m516[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex477, std::array<u64,2>{v_c207, 0})) return;
                slog::join_probe<2,1>(eval_ansindex478, std::array<u64,2>{v_c202, 0}, [&](const std::array<u64,2>& m517) {
                  u64 v_c165 = m517[1];
                  slog::join_probe<2,1>(eval_args_ansindex479, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m518) {
                    u64 v_c159 = m518[1];
                    bool ok519 = true;
                    u64 v_c208 = _prim_lref(db, v_c203, v_c197, &ok519);
                    if (!ok519) return;
                    if (v_c155 != v_c208) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c158, v_c201, v_c165, v_c159});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval", _fires);
  
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
  // (crule (pre) (scan eval_ans __t84Ji24 __t6CK626) (body (join-old eval (0 2 1) 1 (0 2 1) __t84Ji24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __64BN675 __t3Fr129) (exists tick (1 2 0) 2 __t3Fr129 c) (join-old app (0 1 2) 2 (0 1 2) __t3Fr129 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join-old tick (1 2 0) 2 (1 2 0) __t3Fr129 c __t0NvE30) (exists tick_ans (0 1) 1 __t0NvE30) (join-old eval_args_ans (0 1) 1 (0 1) __t3tQh27 vs) (join-old tick_ans (0 1) 1 (0 1) __t0NvE30 l) (join-old closure (0 1 2) 1 (0 1 2) __t6CK626 __t3miO28 cb) (exists binding (1 0 2) 1 cb) (join-old freevar (1 0) 1 (1 0) __t3miO28 y) (join-old binding (0 1 2) 2 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask548 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex520;  slog::Index** appindex521;  slog::Index** eval_argsindex522;  slog::Index** tickindex523;  slog::Index** evalindex524;  slog::Index** tickindex525;  slog::Index** appindex526;  slog::Index** eval_argsindex527;  slog::Index** eval_args_ansindex528;  slog::Index** tickindex529;  slog::Index** tick_ansindex530;  slog::Index** eval_args_ansindex531;  slog::Index** tick_ansindex532;  slog::Index** closureindex533;  slog::Index** bindingindex534;  slog::Index** freevarindex535;  slog::Index** bindingindex536;  slog::Index** lambdaindex537;  slog::Index** evaldelta538;  slog::Index** appdelta539;  slog::Index** eval_argsdelta540;  slog::Index** tickdelta541;  slog::Index** eval_args_ansdelta542;  slog::Index** tick_ansdelta543;  slog::Index** closuredelta544;  slog::Index** freevardelta545;  slog::Index** bindingdelta546;  slog::Index** lambdadelta547;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord549({0, 1, 2});
      slog::Relation* readrel550 = db->getRelation("binding");
      head_index[0] = readrel550->getIndex(ord549, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord551({0, 1, 2});
      slog::Relation* readrel552 = db->getRelation("binding_event");
      head_index[1] = readrel552->getIndex(ord551, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord553({0, 2, 1});
      slog::Relation* readrel554 = db->getRelation("eval");
      evalindex520 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({0, 2, 1});
      slog::Relation* readrel556 = db->getRelation("eval");
      evaldelta538 = readrel556->getIndex(ord555, true);
      std::vector<u16> ord557({1, 2, 0});
      slog::Relation* readrel558 = db->getRelation("app");
      appindex521 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({2, 0, 1});
      slog::Relation* readrel560 = db->getRelation("eval_args");
      eval_argsindex522 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({2, 0, 1});
      slog::Relation* readrel562 = db->getRelation("tick");
      tickindex523 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({2, 0, 1});
      slog::Relation* readrel564 = db->getRelation("eval");
      evalindex524 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({1, 2, 0});
      slog::Relation* readrel566 = db->getRelation("tick");
      tickindex525 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({0, 1, 2});
      slog::Relation* readrel568 = db->getRelation("app");
      appindex526 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({0, 1, 2});
      slog::Relation* readrel570 = db->getRelation("app");
      appdelta539 = readrel570->getIndex(ord569, true);
      std::vector<u16> ord571({1, 2, 0});
      slog::Relation* readrel572 = db->getRelation("eval_args");
      eval_argsindex527 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("eval_args");
      eval_argsdelta540 = readrel574->getIndex(ord573, true);
      std::vector<u16> ord575({0, 1});
      slog::Relation* readrel576 = db->getRelation("eval_args_ans");
      eval_args_ansindex528 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 2, 0});
      slog::Relation* readrel578 = db->getRelation("tick");
      tickindex529 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 2, 0});
      slog::Relation* readrel580 = db->getRelation("tick");
      tickdelta541 = readrel580->getIndex(ord579, true);
      std::vector<u16> ord581({0, 1});
      slog::Relation* readrel582 = db->getRelation("tick_ans");
      tick_ansindex530 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({0, 1});
      slog::Relation* readrel584 = db->getRelation("eval_args_ans");
      eval_args_ansindex531 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({0, 1});
      slog::Relation* readrel586 = db->getRelation("eval_args_ans");
      eval_args_ansdelta542 = readrel586->getIndex(ord585, true);
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("tick_ans");
      tick_ansindex532 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({0, 1});
      slog::Relation* readrel590 = db->getRelation("tick_ans");
      tick_ansdelta543 = readrel590->getIndex(ord589, true);
      std::vector<u16> ord591({0, 1, 2});
      slog::Relation* readrel592 = db->getRelation("closure");
      closureindex533 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({0, 1, 2});
      slog::Relation* readrel594 = db->getRelation("closure");
      closuredelta544 = readrel594->getIndex(ord593, true);
      std::vector<u16> ord595({1, 0, 2});
      slog::Relation* readrel596 = db->getRelation("binding");
      bindingindex534 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 0});
      slog::Relation* readrel598 = db->getRelation("freevar");
      freevarindex535 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({1, 0});
      slog::Relation* readrel600 = db->getRelation("freevar");
      freevardelta545 = readrel600->getIndex(ord599, true);
      std::vector<u16> ord601({0, 1, 2});
      slog::Relation* readrel602 = db->getRelation("binding");
      bindingindex536 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({0, 1, 2});
      slog::Relation* readrel604 = db->getRelation("binding");
      bindingdelta546 = readrel604->getIndex(ord603, true);
      std::vector<u16> ord605({0, 1, 2});
      slog::Relation* readrel606 = db->getRelation("lambda");
      lambdaindex537 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({0, 1, 2});
      slog::Relation* readrel608 = db->getRelation("lambda");
      lambdadelta547 = readrel608->getIndex(ord607, true);
  
    }
    ReadTask548(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c209 = _t[0];
        u64 v_c210 = _t[1];
        slog::join_probe_old<3,1>(evalindex520, evaldelta538, std::array<u64,3>{v_c209, 0, 0}, [&](const std::array<u64,3>& m609) {
          u64 v_c50 = m609[1]; u64 v_c51 = m609[2];
          if (!slog::exists_probe<3,1>(appindex521, std::array<u64,3>{v_c51, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex522, std::array<u64,3>{v_c50, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex523, std::array<u64,3>{v_c50, 0, 0})) return;
          slog::join_probe<3,1>(evalindex524, std::array<u64,3>{v_c50, 0, 0}, [&](const std::array<u64,3>& m610) {
            u64 v_c211 = m610[1]; u64 v_c212 = m610[2];
            if (!slog::exists_probe<3,2>(tickindex525, std::array<u64,3>{v_c212, v_c50, 0})) return;
            slog::join_probe_old<3,2>(appindex526, appdelta539, std::array<u64,3>{v_c212, v_c51, 0}, [&](const std::array<u64,3>& m611) {
              u64 v_c52 = m611[2];
              slog::join_probe_old<3,2>(eval_argsindex527, eval_argsdelta540, std::array<u64,3>{v_c52, v_c50, 0}, [&](const std::array<u64,3>& m612) {
                u64 v_c213 = m612[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex528, std::array<u64,2>{v_c213, 0})) return;
                slog::join_probe_old<3,2>(tickindex529, tickdelta541, std::array<u64,3>{v_c212, v_c50, 0}, [&](const std::array<u64,3>& m613) {
                  u64 v_c214 = m613[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex530, std::array<u64,2>{v_c214, 0})) return;
                  slog::join_probe_old<2,1>(eval_args_ansindex531, eval_args_ansdelta542, std::array<u64,2>{v_c213, 0}, [&](const std::array<u64,2>& m614) {
                    u64 v_c215 = m614[1];
                    slog::join_probe_old<2,1>(tick_ansindex532, tick_ansdelta543, std::array<u64,2>{v_c214, 0}, [&](const std::array<u64,2>& m615) {
                      u64 v_c216 = m615[1];
                      slog::join_probe_old<3,1>(closureindex533, closuredelta544, std::array<u64,3>{v_c210, 0, 0}, [&](const std::array<u64,3>& m616) {
                        u64 v_c217 = m616[1]; u64 v_c64 = m616[2];
                        if (!slog::exists_probe<3,1>(bindingindex534, std::array<u64,3>{v_c64, 0, 0})) return;
                        slog::join_probe_old<2,1>(freevarindex535, freevardelta545, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m617) {
                          u64 v_c90 = m617[1];
                          slog::join_probe_old<3,2>(bindingindex536, bindingdelta546, std::array<u64,3>{v_c90, v_c64, 0}, [&](const std::array<u64,3>& m618) {
                            u64 v_c91 = m618[2];
                            slog::join_probe_old<3,1>(lambdaindex537, lambdadelta547, std::array<u64,3>{v_c217, 0, 0}, [&](const std::array<u64,3>& m619) {
                              u64 v_c93 = m619[1]; u64 v_c94 = m619[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c90, v_c216, v_c91}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c90, v_c216, v_c50}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask548* _cont = new ReadTask548(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask548(db,b), false);
  // (crule (pre (let __tconst0flI607 const0122baa3ac55f1b433944eb1) (let __tconst2Cp4303 const06abaa100ecef791ce028c56) (let _00024sqc21WF437 constd4735e3a265e16eee03f5971) (let _00024sqc91nv438 const5feceb66ffc86f38d952786c) (let _00024sqc5PZ7439 const6b86b273ff34fce19d6b804e) (let _00024sqo16uv440 const5feceb66ffc86f38d952786c) (let _00024sqo3GRa441 const6b86b273ff34fce19d6b804e) (let _00024sqo2Vbm442 const6b86b273ff34fce19d6b804e) (let _00024sqo8B0L443 const5feceb66ffc86f38d952786c)) (scan boolval __t9eYl306 b) (body (exists $seq_at (1 0 2) 2 _00024sqo3GRa441 __t9eYl306) (exists $seq_atr (1 0 2) 2 _00024sqo2Vbm442 __t9eYl306) (exists $seq_atr (1 0 2) 2 _00024sqo8B0L443 __t9eYl306) (exists delta (1 2 0) 1 __tconst2Cp4303) (exists _enum (1 0) 1 __tconst0flI607) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo16uv440 __t9eYl306 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo3GRa441 __t9eYl306 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2Vbm442 __t9eYl306 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8B0L443 __t9eYl306 _00024seq2) (join delta (1 2 0) 2 __tconst2Cp4303 _00024seq2 __t2i9A304) (join _enum (1 0) 1 __tconst0flI607 __t8LeX301) (letp _00024sql7hRC435 (aslst _00024seq2)) (let chk5bQT1016 (llen _00024sql7hRC435)) (eq _00024sqc21WF437 chk5bQT1016) (letp chk2wce1017 (lref _00024sql7hRC435 _00024sqc91nv438)) (eq __t9eYl306 chk2wce1017) (letp chk2pR01018 (lref _00024sql7hRC435 _00024sqc5PZ7439)) (eq __t9eYl306 chk2pR01018)) (head (emit-temp temp61mi1013 __t2i9A304) (mkstruct boolval (1 0) __t5m8l302 __t8LeX301)) interp.slog:118 #f)
  class ReadTask635 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex620;  slog::Index** $seq_atrindex621;  slog::Index** $seq_atrindex622;  slog::Index** deltaindex623;  slog::Index** _enumindex624;  slog::Index** $seq_atindex625;  slog::Index** $seq_atindex626;  slog::Index** $seq_atrindex627;  slog::Index** $seq_atrindex628;  slog::Index** deltaindex629;  slog::Index** _enumindex630;  slog::Index** $seq_atdelta631;  slog::Index** $seq_atdelta632;  slog::Index** $seq_atrdelta633;  slog::Index** $seq_atrdelta634;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp61mi1013");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord636({1, 0, 2});
      slog::Relation* readrel637 = db->getRelation("$seq_at");
      $seq_atindex620 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 0, 2});
      slog::Relation* readrel639 = db->getRelation("$seq_atr");
      $seq_atrindex621 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 0, 2});
      slog::Relation* readrel641 = db->getRelation("$seq_atr");
      $seq_atrindex622 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 2, 0});
      slog::Relation* readrel643 = db->getRelation("delta");
      deltaindex623 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 0});
      slog::Relation* readrel645 = db->getRelation("_enum");
      _enumindex624 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 0, 2});
      slog::Relation* readrel647 = db->getRelation("$seq_at");
      $seq_atindex625 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 0, 2});
      slog::Relation* readrel649 = db->getRelation("$seq_at");
      $seq_atdelta631 = readrel649->getIndex(ord648, true);
      std::vector<u16> ord650({1, 0, 2});
      slog::Relation* readrel651 = db->getRelation("$seq_at");
      $seq_atindex626 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({1, 0, 2});
      slog::Relation* readrel653 = db->getRelation("$seq_at");
      $seq_atdelta632 = readrel653->getIndex(ord652, true);
      std::vector<u16> ord654({1, 0, 2});
      slog::Relation* readrel655 = db->getRelation("$seq_atr");
      $seq_atrindex627 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 0, 2});
      slog::Relation* readrel657 = db->getRelation("$seq_atr");
      $seq_atrdelta633 = readrel657->getIndex(ord656, true);
      std::vector<u16> ord658({1, 0, 2});
      slog::Relation* readrel659 = db->getRelation("$seq_atr");
      $seq_atrindex628 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 0, 2});
      slog::Relation* readrel661 = db->getRelation("$seq_atr");
      $seq_atrdelta634 = readrel661->getIndex(ord660, true);
      std::vector<u16> ord662({1, 2, 0});
      slog::Relation* readrel663 = db->getRelation("delta");
      deltaindex629 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 0});
      slog::Relation* readrel665 = db->getRelation("_enum");
      _enumindex630 = readrel665->getIndex(ord664, false);
  
    }
    ReadTask635(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c121 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c122 = v_const06abaa100ecef791ce028c56;
      u64 v_c123 = v_constd4735e3a265e16eee03f5971;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c129 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c130 = _t[0];
        u64 v_c26 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex620, std::array<u64,3>{v_c127, v_c130, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex621, std::array<u64,3>{v_c128, v_c130, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex622, std::array<u64,3>{v_c129, v_c130, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex623, std::array<u64,3>{v_c122, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex624, std::array<u64,2>{v_c121, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex625, $seq_atdelta631, std::array<u64,3>{v_c126, v_c130, 0}, [&](const std::array<u64,3>& m666) {
          u64 v_c23 = m666[2];
          slog::join_probe_old<3,3>($seq_atindex626, $seq_atdelta632, std::array<u64,3>{v_c127, v_c130, v_c23}, [&](const std::array<u64,3>& m667) {
            slog::join_probe_old<3,3>($seq_atrindex627, $seq_atrdelta633, std::array<u64,3>{v_c128, v_c130, v_c23}, [&](const std::array<u64,3>& m668) {
              slog::join_probe_old<3,3>($seq_atrindex628, $seq_atrdelta634, std::array<u64,3>{v_c129, v_c130, v_c23}, [&](const std::array<u64,3>& m669) {
                slog::join_probe<3,2>(deltaindex629, std::array<u64,3>{v_c122, v_c23, 0}, [&](const std::array<u64,3>& m670) {
                  u64 v_c131 = m670[2];
                  slog::join_probe<2,1>(_enumindex630, std::array<u64,2>{v_c121, 0}, [&](const std::array<u64,2>& m671) {
                    u64 v_c132 = m671[1];
                    bool ok672 = true;
                    u64 v_c133 = _prim_aslst(db, v_c23, &ok672);
                    if (!ok672) return;
                    u64 v_c218 = _prim_llen(db, v_c133);
                    if (v_c218 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c123 != v_c218) return;
                    bool ok673 = true;
                    u64 v_c219 = _prim_lref(db, v_c133, v_c124, &ok673);
                    if (!ok673) return;
                    if (v_c130 != v_c219) return;
                    bool ok674 = true;
                    u64 v_c220 = _prim_lref(db, v_c133, v_c125, &ok674);
                    if (!ok674) return;
                    if (v_c130 != v_c220) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c131});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c132}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask635* _cont = new ReadTask635(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask635(db,b), false);
  // (crule (pre) (scan int_overflow __erre57GP820 __errf2VEI821 __errf7Q6Z822 __errf1N5I823) (body) (head (emit error (0) __erre57GP820)) <internal>:1 #f)
  class ReadTask675 : public slog::Task
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
      std::vector<u16> ord676({0});
      slog::Relation* readrel677 = db->getRelation("error");
      head_index[0] = readrel677->getIndex(ord676, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask675(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c221 = _t[0];
        u64 v_c222 = _t[1];
        u64 v_c223 = _t[2];
        u64 v_c224 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c221}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask675* _cont = new ReadTask675(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask675(db,b), false);
  // (crule (pre (let __tconst2uSL111 const0457bba0679825d285ef7fa5) (let __tconst0xiC106 const30f8b180d63559f2512b744f) (let __tconst1ae2105 constba2df4903a2c14e86dc3bcca) (let __tconst7lFL83 const2bc983a5942276eb00a75e21) (let __tconst8Fnl80 const7297d2085ea0adffc396d546) (let __tconst8n1H73 const6b86b273ff34fce19d6b804e) (let __tconst2U2F71 constef2d127de37b942baad06145)) (scan temp54az998 __t5Wmv107) (body (exists num (1 0) 1 __tconst8n1H73) (exists ref (1 0) 1 __tconst7lFL83) (exists ref (1 0) 1 __tconst8Fnl80) (exists ref (1 0) 1 __tconst2uSL111) (exists ref (1 0) 1 __tconst1ae2105) (exists ref (1 0) 1 __tconst0xiC106) (join num (1 0) 1 __tconst2U2F71 __t8tX372) (join num (1 0) 1 __tconst8n1H73 __t7RPv74) (join ref (1 0) 1 __tconst7lFL83 __t4enh76) (join ref (1 0) 1 __tconst8Fnl80 __t0mBu81) (join ref (1 0) 1 __tconst2uSL111 __t0iVM91) (join ref (1 0) 1 __tconst1ae2105 __t3lY294) (join ref (1 0) 1 __tconst0xiC106 __t2Kfn98) (let __t6Al3108 (lpush __t5Wmv107 __tconst0xiC106)) (let __t1hw196 (lpush __t5Wmv107 __t3lY294)) (let __t9Kbk85 (lpush __t5Wmv107 __tconst7lFL83)) (let __t9ZBY78 (lpush __t5Wmv107 __t4enh76))) (head (emit-temp temp2J14999 __t1hw196 __t5Wmv107 __t6Al3108 __t9Kbk85 __t9ZBY78)) analysis-demo.slog:11 #f)
  class ReadTask691 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex678;  slog::Index** refindex679;  slog::Index** refindex680;  slog::Index** refindex681;  slog::Index** refindex682;  slog::Index** refindex683;  slog::Index** numindex684;  slog::Index** numindex685;  slog::Index** refindex686;  slog::Index** refindex687;  slog::Index** refindex688;  slog::Index** refindex689;  slog::Index** refindex690;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2J14999");
      outer_rel = db->getRelation("temp54az998");
      std::vector<u16> ord692({1, 0});
      slog::Relation* readrel693 = db->getRelation("num");
      numindex678 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 0});
      slog::Relation* readrel695 = db->getRelation("ref");
      refindex679 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({1, 0});
      slog::Relation* readrel697 = db->getRelation("ref");
      refindex680 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({1, 0});
      slog::Relation* readrel699 = db->getRelation("ref");
      refindex681 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 0});
      slog::Relation* readrel701 = db->getRelation("ref");
      refindex682 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 0});
      slog::Relation* readrel703 = db->getRelation("ref");
      refindex683 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 0});
      slog::Relation* readrel705 = db->getRelation("num");
      numindex684 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({1, 0});
      slog::Relation* readrel707 = db->getRelation("num");
      numindex685 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({1, 0});
      slog::Relation* readrel709 = db->getRelation("ref");
      refindex686 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({1, 0});
      slog::Relation* readrel711 = db->getRelation("ref");
      refindex687 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({1, 0});
      slog::Relation* readrel713 = db->getRelation("ref");
      refindex688 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({1, 0});
      slog::Relation* readrel715 = db->getRelation("ref");
      refindex689 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 0});
      slog::Relation* readrel717 = db->getRelation("ref");
      refindex690 = readrel717->getIndex(ord716, false);
  
    }
    ReadTask691(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c69 = v_const0457bba0679825d285ef7fa5;
      u64 v_c70 = v_const30f8b180d63559f2512b744f;
      u64 v_c71 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c72 = v_const2bc983a5942276eb00a75e21;
      u64 v_c73 = v_const7297d2085ea0adffc396d546;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c75 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c76 = _t[0];
        if (!slog::exists_probe<2,1>(numindex678, std::array<u64,2>{v_c74, 0})) return;
        if (!slog::exists_probe<2,1>(refindex679, std::array<u64,2>{v_c72, 0})) return;
        if (!slog::exists_probe<2,1>(refindex680, std::array<u64,2>{v_c73, 0})) return;
        if (!slog::exists_probe<2,1>(refindex681, std::array<u64,2>{v_c69, 0})) return;
        if (!slog::exists_probe<2,1>(refindex682, std::array<u64,2>{v_c71, 0})) return;
        if (!slog::exists_probe<2,1>(refindex683, std::array<u64,2>{v_c70, 0})) return;
        slog::join_probe<2,1>(numindex684, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m718) {
          u64 v_c225 = m718[1];
          slog::join_probe<2,1>(numindex685, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m719) {
            u64 v_c226 = m719[1];
            slog::join_probe<2,1>(refindex686, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m720) {
              u64 v_c227 = m720[1];
              slog::join_probe<2,1>(refindex687, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m721) {
                u64 v_c228 = m721[1];
                slog::join_probe<2,1>(refindex688, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m722) {
                  u64 v_c181 = m722[1];
                  slog::join_probe<2,1>(refindex689, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m723) {
                    u64 v_c229 = m723[1];
                    slog::join_probe<2,1>(refindex690, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m724) {
                      u64 v_c230 = m724[1];
                      u64 v_c231 = _prim_lpush(db, v_c76, v_c70);
                      if (v_c231 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return; }
                      u64 v_c232 = _prim_lpush(db, v_c76, v_c229);
                      if (v_c232 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return; }
                      u64 v_c233 = _prim_lpush(db, v_c76, v_c72);
                      if (v_c233 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return; }
                      u64 v_c234 = _prim_lpush(db, v_c76, v_c227);
                      if (v_c234 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:11"); return; }
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c232, v_c76, v_c231, v_c233, v_c234});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:11", "delta:temp54az998", _fires);
  
      if (!_done)
      {
        ReadTask691* _cont = new ReadTask691(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask691(db,b), false);
  // (crule (pre) (scan freevar x e3) (body (join-old if (3 0 1 2) 1 (3 0 1 2) e3 __t5qA5344 e1 e2)) (head (emit freevar (0 1) x __t5qA5344)) freevars.slog:17 #f)
  class ReadTask727 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex725;  slog::Index** ifdelta726;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord728({0, 1});
      slog::Relation* readrel729 = db->getRelation("freevar");
      head_index[0] = readrel729->getIndex(ord728, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord730({3, 0, 1, 2});
      slog::Relation* readrel731 = db->getRelation("if");
      ifindex725 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({3, 0, 1, 2});
      slog::Relation* readrel733 = db->getRelation("if");
      ifdelta726 = readrel733->getIndex(ord732, true);
  
    }
    ReadTask727(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c105 = _t[0];
        u64 v_c100 = _t[1];
        slog::join_probe_old<4,1>(ifindex725, ifdelta726, std::array<u64,4>{v_c100, 0, 0, 0}, [&](const std::array<u64,4>& m734) {
          u64 v_c235 = m734[1]; u64 v_c236 = m734[2]; u64 v_c99 = m734[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c105, v_c235}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask727* _cont = new ReadTask727(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask727(db,b), false);
  // (crule (pre (let _00024sqc9r51426 const6b86b273ff34fce19d6b804e) (let _00024sqc0a7Y427 const5feceb66ffc86f38d952786c) (let _00024sqc6lAT428 const6b86b273ff34fce19d6b804e) (let _00024sqc6zTj429 const5feceb66ffc86f38d952786c) (let _00024sqo7QcU434 const5feceb66ffc86f38d952786c) (let __t31sY376 (lempty))) (scan eval_args __t5lLk381 es c) (body (exists eval_args (2 0 1) 1 c) (exists $seq_at (1 0 2) 1 _00024sqo7QcU434) (exists eval (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t5lLk381) (join $sup56712x37x0x0x0 (2 4 0 1 3) 2 c es _00024seq0 __t1ye1379 e) (join eval_args (0 2 1) 3 __t1ye1379 c _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7QcU434 e _00024seq0) (join eval (1 2 0) 2 e c __t33Oa380) (join eval_ans (0 1) 1 __t33Oa380 __v0) (join eval_args_ans (0 1) 1 __t5lLk381 __v1) (letp _00024sql0xMp424 (aslst _00024seq0)) (let _00024sqn1MBN425 (llen _00024sql0xMp424)) (cmp ge _00024sqn1MBN425 _00024sqc9r51426) (letp chk1JFD942 (lref _00024sql0xMp424 _00024sqc0a7Y427)) (eq e chk1JFD942) (let _00024sqp04Wv430 (_0002d _00024sqn1MBN425 _00024sqc6zTj429)) (let chk58ZD943 (lslice _00024sql0xMp424 _00024sqc6lAT428 _00024sqp04Wv430)) (eq es chk58ZD943)) (head (emit-temp temp0JGK933 __t1ye1379 __t31sY376 __v0 __v1)) interp.slog:38 #f)
  class ReadTask746 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex735;  slog::Index** $seq_atindex736;  slog::Index** evalindex737;  slog::Index** eval_args_ansindex738;  slog::Index** $sup56712x37x0x0x0index739;  slog::Index** eval_argsindex740;  slog::Index** $seq_atindex741;  slog::Index** evalindex742;  slog::Index** eval_ansindex743;  slog::Index** eval_args_ansindex744;  slog::Index** $seq_atdelta745;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0JGK933");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord747({2, 0, 1});
      slog::Relation* readrel748 = db->getRelation("eval_args");
      eval_argsindex735 = readrel748->getIndex(ord747, false);
      std::vector<u16> ord749({1, 0, 2});
      slog::Relation* readrel750 = db->getRelation("$seq_at");
      $seq_atindex736 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({2, 0, 1});
      slog::Relation* readrel752 = db->getRelation("eval");
      evalindex737 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({0, 1});
      slog::Relation* readrel754 = db->getRelation("eval_args_ans");
      eval_args_ansindex738 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({2, 4, 0, 1, 3});
      slog::Relation* readrel756 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index739 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({0, 2, 1});
      slog::Relation* readrel758 = db->getRelation("eval_args");
      eval_argsindex740 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({1, 0, 2});
      slog::Relation* readrel760 = db->getRelation("$seq_at");
      $seq_atindex741 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({1, 0, 2});
      slog::Relation* readrel762 = db->getRelation("$seq_at");
      $seq_atdelta745 = readrel762->getIndex(ord761, true);
      std::vector<u16> ord763({1, 2, 0});
      slog::Relation* readrel764 = db->getRelation("eval");
      evalindex742 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({0, 1});
      slog::Relation* readrel766 = db->getRelation("eval_ans");
      eval_ansindex743 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({0, 1});
      slog::Relation* readrel768 = db->getRelation("eval_args_ans");
      eval_args_ansindex744 = readrel768->getIndex(ord767, false);
  
    }
    ReadTask746(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const5feceb66ffc86f38d952786c;
      u64 v_c200 = v_const5feceb66ffc86f38d952786c;
      u64 v_c201 = _prim_lempty(db);
      if (v_c201 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c207 = _t[0];
        u64 v_c52 = _t[1];
        u64 v_c50 = _t[2];
        if (!slog::exists_probe<3,1>(eval_argsindex735, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atindex736, std::array<u64,3>{v_c200, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex737, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex738, std::array<u64,2>{v_c207, 0})) return;
        slog::join_probe<5,2>($sup56712x37x0x0x0index739, std::array<u64,5>{v_c50, v_c52, 0, 0, 0}, [&](const std::array<u64,5>& m769) {
          u64 v_c41 = m769[2]; u64 v_c158 = m769[3]; u64 v_c155 = m769[4];
          slog::join_probe<3,3>(eval_argsindex740, std::array<u64,3>{v_c158, v_c50, v_c41}, [&](const std::array<u64,3>& m770) {
            slog::join_probe_old<3,3>($seq_atindex741, $seq_atdelta745, std::array<u64,3>{v_c200, v_c155, v_c41}, [&](const std::array<u64,3>& m771) {
              slog::join_probe<3,2>(evalindex742, std::array<u64,3>{v_c155, v_c50, 0}, [&](const std::array<u64,3>& m772) {
                u64 v_c202 = m772[2];
                slog::join_probe<2,1>(eval_ansindex743, std::array<u64,2>{v_c202, 0}, [&](const std::array<u64,2>& m773) {
                  u64 v_c165 = m773[1];
                  slog::join_probe<2,1>(eval_args_ansindex744, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m774) {
                    u64 v_c159 = m774[1];
                    bool ok775 = true;
                    u64 v_c203 = _prim_aslst(db, v_c41, &ok775);
                    if (!ok775) return;
                    u64 v_c204 = _prim_llen(db, v_c203);
                    if (v_c204 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c237 = _prim_ge(db, v_c204, v_c196);
                    if (v_c237 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (!v_c237) return;
                    bool ok777 = true;
                    u64 v_c238 = _prim_lref(db, v_c203, v_c197, &ok777);
                    if (!ok777) return;
                    if (v_c155 != v_c238) return;
                    u64 v_c206 = _prim__0002d(db, v_c204, v_c199);
                    if (v_c206 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c239 = _prim_lslice(db, v_c203, v_c198, v_c206);
                    if (v_c239 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (v_c52 != v_c239) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c158, v_c201, v_c165, v_c159});
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
        ReadTask746* _cont = new ReadTask746(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask746(db,b), false);
  // (crule (pre) (scan eval_ans __t8bEj309 vr) (body (join-old eval (0 2 1) 1 (0 2 1) __t8bEj309 c er) (exists letrec (2 1 3 0) 1 er) (exists eval (2 0 1) 1 c) (join-old $sup56712x93x0x0x0 (1 3 0 2 4) 2 (1 3 0 2 4) c er __t3Qfa308 eb x) (exists eval (0 2 1) 2 __t3Qfa308 c) (exists eval (1 2 0) 2 eb c) (join letrec (2 1 3 0) 3 er x eb __t8pF7307) (join-old eval (0 2 1) 3 (0 2 1) __t3Qfa308 c __t8pF7307) (join-old eval (1 2 0) 2 (1 2 0) eb c __t8NjM310) (join-old eval_ans (0 1) 1 (0 1) __t8NjM310 v)) (head (emit eval_ans (0 1) __t3Qfa308 v)) interp.slog:94 #f)
  class ReadTask793 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex778;  slog::Index** letrecindex779;  slog::Index** evalindex780;  slog::Index** $sup56712x93x0x0x0index781;  slog::Index** evalindex782;  slog::Index** evalindex783;  slog::Index** letrecindex784;  slog::Index** evalindex785;  slog::Index** evalindex786;  slog::Index** eval_ansindex787;  slog::Index** evaldelta788;  slog::Index** $sup56712x93x0x0x0delta789;  slog::Index** evaldelta790;  slog::Index** evaldelta791;  slog::Index** eval_ansdelta792;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord794({0, 1});
      slog::Relation* readrel795 = db->getRelation("eval_ans");
      head_index[0] = readrel795->getIndex(ord794, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord796({0, 2, 1});
      slog::Relation* readrel797 = db->getRelation("eval");
      evalindex778 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({0, 2, 1});
      slog::Relation* readrel799 = db->getRelation("eval");
      evaldelta788 = readrel799->getIndex(ord798, true);
      std::vector<u16> ord800({2, 1, 3, 0});
      slog::Relation* readrel801 = db->getRelation("letrec");
      letrecindex779 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({2, 0, 1});
      slog::Relation* readrel803 = db->getRelation("eval");
      evalindex780 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 3, 0, 2, 4});
      slog::Relation* readrel805 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index781 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 3, 0, 2, 4});
      slog::Relation* readrel807 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0delta789 = readrel807->getIndex(ord806, true);
      std::vector<u16> ord808({0, 2, 1});
      slog::Relation* readrel809 = db->getRelation("eval");
      evalindex782 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({1, 2, 0});
      slog::Relation* readrel811 = db->getRelation("eval");
      evalindex783 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({2, 1, 3, 0});
      slog::Relation* readrel813 = db->getRelation("letrec");
      letrecindex784 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({0, 2, 1});
      slog::Relation* readrel815 = db->getRelation("eval");
      evalindex785 = readrel815->getIndex(ord814, false);
      std::vector<u16> ord816({0, 2, 1});
      slog::Relation* readrel817 = db->getRelation("eval");
      evaldelta790 = readrel817->getIndex(ord816, true);
      std::vector<u16> ord818({1, 2, 0});
      slog::Relation* readrel819 = db->getRelation("eval");
      evalindex786 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 2, 0});
      slog::Relation* readrel821 = db->getRelation("eval");
      evaldelta791 = readrel821->getIndex(ord820, true);
      std::vector<u16> ord822({0, 1});
      slog::Relation* readrel823 = db->getRelation("eval_ans");
      eval_ansindex787 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("eval_ans");
      eval_ansdelta792 = readrel825->getIndex(ord824, true);
  
    }
    ReadTask793(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c241 = _t[1];
        slog::join_probe_old<3,1>(evalindex778, evaldelta788, std::array<u64,3>{v_c240, 0, 0}, [&](const std::array<u64,3>& m826) {
          u64 v_c50 = m826[1]; u64 v_c242 = m826[2];
          if (!slog::exists_probe<4,1>(letrecindex779, std::array<u64,4>{v_c242, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex780, std::array<u64,3>{v_c50, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x93x0x0x0index781, $sup56712x93x0x0x0delta789, std::array<u64,5>{v_c50, v_c242, 0, 0, 0}, [&](const std::array<u64,5>& m827) {
            u64 v_c243 = m827[2]; u64 v_c94 = m827[3]; u64 v_c105 = m827[4];
            if (!slog::exists_probe<3,2>(evalindex782, std::array<u64,3>{v_c243, v_c50, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex783, std::array<u64,3>{v_c94, v_c50, 0})) return;
            slog::join_probe<4,3>(letrecindex784, std::array<u64,4>{v_c242, v_c105, v_c94, 0}, [&](const std::array<u64,4>& m828) {
              u64 v_c244 = m828[3];
              slog::join_probe_old<3,3>(evalindex785, evaldelta790, std::array<u64,3>{v_c243, v_c50, v_c244}, [&](const std::array<u64,3>& m829) {
                slog::join_probe_old<3,2>(evalindex786, evaldelta791, std::array<u64,3>{v_c94, v_c50, 0}, [&](const std::array<u64,3>& m830) {
                  u64 v_c245 = m830[2];
                  slog::join_probe_old<2,1>(eval_ansindex787, eval_ansdelta792, std::array<u64,2>{v_c245, 0}, [&](const std::array<u64,2>& m831) {
                    u64 v_c83 = m831[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c243, v_c83}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask793* _cont = new ReadTask793(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask793(db,b), false);
  // (crule (pre (let __tconst4znW669 constcd2a69ce5ca278db1d6da969) (let _00024sqc3H5i520 constd4735e3a265e16eee03f5971) (let _00024sqc4tob521 const5feceb66ffc86f38d952786c) (let _00024sqc5Dhg522 const6b86b273ff34fce19d6b804e) (let _00024sqo4wSo523 const5feceb66ffc86f38d952786c) (let _00024sqo3X5o524 const6b86b273ff34fce19d6b804e) (let _00024sqo10Lc525 const6b86b273ff34fce19d6b804e) (let _00024sqo1tMi526 const5feceb66ffc86f38d952786c) (let __trid6dum670 consteefaed435882b14b69e99d78) (let __trel5mCG671 constdede4476644eb06b5a48b866) (let __tcol9ZQn672 const6b86b273ff34fce19d6b804e)) (probe $seq_atr (1 0 2) 1 _00024sqo1tMi526 __t5cN641 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo4wSo523 __t5cN641 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo3X5o524 __t5cN641 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo10Lc525 __t5cN641 _00024seq2) (join _enum (0 1) 2 __t5cN641 __tconst4znW669) (join delta (2 0 1) 1 _00024seq2 __t2MSw39 op) (join arithmetic_op (0) 1 op) (letp _00024sql8wbR518 (aslst _00024seq2)) (let chk3kNh909 (llen _00024sql8wbR518)) (eq _00024sqc3H5i520 chk3kNh909) (letp chk5KpO910 (lref _00024sql8wbR518 _00024sqc4tob521)) (eq __t5cN641 chk5KpO910) (letp chk3fpp911 (lref _00024sql8wbR518 _00024sqc5Dhg522)) (eq __t5cN641 chk3fpp911)) (head (tycheck __t5cN641 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid6dum670 __trel5mCG671 __tcol9ZQn672 (1 2 3 4 0)) (emit delta_ans (0 1) __t2MSw39 __t5cN641)) interp.slog:111 #f)
  class ReadTask843 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex832;  slog::Index** $seq_atindex833;  slog::Index** $seq_atrindex834;  slog::Index** _enumindex835;  slog::Index** deltaindex836;  slog::Index** arithmetic_opindex837;
    u32 sid840;  u32 sid838;  u32 sid839;  u32 sid841;  u32 sid842;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord844({0, 1});
      slog::Relation* readrel845 = db->getRelation("delta_ans");
      head_index[1] = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 0, 2});
      slog::Relation* readrel847 = db->getRelation("$seq_atr");
      driver_index = readrel847->getIndex(ord846, true);
      std::vector<u16> ord848({1, 0, 2});
      slog::Relation* readrel849 = db->getRelation("$seq_at");
      $seq_atindex832 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({1, 0, 2});
      slog::Relation* readrel851 = db->getRelation("$seq_at");
      $seq_atindex833 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({1, 0, 2});
      slog::Relation* readrel853 = db->getRelation("$seq_atr");
      $seq_atrindex834 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({0, 1});
      slog::Relation* readrel855 = db->getRelation("_enum");
      _enumindex835 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({2, 0, 1});
      slog::Relation* readrel857 = db->getRelation("delta");
      deltaindex836 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({0});
      slog::Relation* readrel859 = db->getRelation("arithmetic_op");
      arithmetic_opindex837 = readrel859->getIndex(ord858, false);
      sid840 = db->getRelation("_enum")->getStructId();
      sid838 = db->getRelation("boolval")->getStructId();
      sid839 = db->getRelation("closure")->getStructId();
      sid841 = db->getRelation("prim")->getStructId();
      sid842 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask843(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c137 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c138 = v_constd4735e3a265e16eee03f5971;
      u64 v_c139 = v_const5feceb66ffc86f38d952786c;
      u64 v_c140 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c141 = v_const5feceb66ffc86f38d952786c;
      u64 v_c142 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c143 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c144 = v_const5feceb66ffc86f38d952786c;
      u64 v_c145 = v_consteefaed435882b14b69e99d78;
      u64 v_c146 = v_constdede4476644eb06b5a48b866;
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c144, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m860) {
        u64 v_c148 = m860[1];
        u64 v_c23 = m860[2];
        if (buckethash(v_c148) != bucket) return;
        slog::join_probe<3,3>($seq_atindex832, std::array<u64,3>{v_c141, v_c148, v_c23}, [&](const std::array<u64,3>& m861) {
          slog::join_probe<3,3>($seq_atindex833, std::array<u64,3>{v_c142, v_c148, v_c23}, [&](const std::array<u64,3>& m862) {
            slog::join_probe<3,3>($seq_atrindex834, std::array<u64,3>{v_c143, v_c148, v_c23}, [&](const std::array<u64,3>& m863) {
              slog::join_probe<2,2>(_enumindex835, std::array<u64,2>{v_c148, v_c137}, [&](const std::array<u64,2>& m864) {
                slog::join_probe<3,1>(deltaindex836, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m865) {
                  u64 v_c149 = m865[1]; u64 v_c25 = m865[2];
                  slog::join_probe<1,1>(arithmetic_opindex837, std::array<u64,1>{v_c25}, [&](const std::array<u64,1>& m866) {
                    bool ok867 = true;
                    u64 v_c150 = _prim_aslst(db, v_c23, &ok867);
                    if (!ok867) return;
                    u64 v_c246 = _prim_llen(db, v_c150);
                    if (v_c246 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c138 != v_c246) return;
                    bool ok868 = true;
                    u64 v_c247 = _prim_lref(db, v_c150, v_c139, &ok868);
                    if (!ok868) return;
                    if (v_c148 != v_c247) return;
                    bool ok869 = true;
                    u64 v_c248 = _prim_lref(db, v_c150, v_c140, &ok869);
                    if (!ok869) return;
                    if (v_c148 != v_c248) return;
                    ++_fires;
                    if (!((is_struct(v_c148) && (decode_struct_id(v_c148) == sid838 || decode_struct_id(v_c148) == sid839 || decode_struct_id(v_c148) == sid840 || decode_struct_id(v_c148) == sid841 || decode_struct_id(v_c148) == sid842))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c145, v_c146, v_c147, v_c148}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c149, v_c148}, std::array<u16,2>{0, 1});
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
        ReadTask843* _cont = new ReadTask843(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask843(db,b), false);
  // (crule (pre (let __tconst2fdM633 constcd2a69ce5ca278db1d6da969) (let _00024sqc7LFn532 constd4735e3a265e16eee03f5971) (let _00024sqc3SHd533 const5feceb66ffc86f38d952786c) (let _00024sqc4CLM534 const6b86b273ff34fce19d6b804e) (let _00024sqo90j9535 const5feceb66ffc86f38d952786c) (let _00024sqo88rK536 const6b86b273ff34fce19d6b804e) (let _00024sqo1A9y537 const6b86b273ff34fce19d6b804e) (let _00024sqo2hWF538 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo2hWF538 __t26Zq339 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo90j9535 __t26Zq339 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo88rK536 __t26Zq339 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo1A9y537 __t26Zq339 _00024seq2) (join _enum (0 1) 2 __t26Zq339 __tconst2fdM633) (join delta (2 0 1) 1 _00024seq2 __t1IV0337 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql96G9530 (aslst _00024seq2)) (let chk13Y9957 (llen _00024sql96G9530)) (eq _00024sqc7LFn532 chk13Y9957) (letp chk6oiK958 (lref _00024sql96G9530 _00024sqc3SHd533)) (eq __t26Zq339 chk6oiK958) (letp chk43Vw959 (lref _00024sql96G9530 _00024sqc4CLM534)) (eq __t26Zq339 chk43Vw959)) (head (emit-temp temp5ZiW945 __t1IV0337 b) (mkstruct boolval (1 0) __t4qAo336 b)) interp.slog:112 #f)
  class ReadTask877 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex870;  slog::Index** $seq_atindex871;  slog::Index** $seq_atrindex872;  slog::Index** _enumindex873;  slog::Index** deltaindex874;  slog::Index** comparison_opindex875;  slog::Index** any_boolindex876;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5ZiW945");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord878({1, 0, 2});
      slog::Relation* readrel879 = db->getRelation("$seq_atr");
      driver_index = readrel879->getIndex(ord878, true);
      std::vector<u16> ord880({1, 0, 2});
      slog::Relation* readrel881 = db->getRelation("$seq_at");
      $seq_atindex870 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({1, 0, 2});
      slog::Relation* readrel883 = db->getRelation("$seq_at");
      $seq_atindex871 = readrel883->getIndex(ord882, false);
      std::vector<u16> ord884({1, 0, 2});
      slog::Relation* readrel885 = db->getRelation("$seq_atr");
      $seq_atrindex872 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({0, 1});
      slog::Relation* readrel887 = db->getRelation("_enum");
      _enumindex873 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({2, 0, 1});
      slog::Relation* readrel889 = db->getRelation("delta");
      deltaindex874 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({0});
      slog::Relation* readrel891 = db->getRelation("comparison_op");
      comparison_opindex875 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({0});
      slog::Relation* readrel893 = db->getRelation("any_bool");
      any_boolindex876 = readrel893->getIndex(ord892, false);
  
    }
    ReadTask877(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c15 = v_constd4735e3a265e16eee03f5971;
      u64 v_c16 = v_const5feceb66ffc86f38d952786c;
      u64 v_c17 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
      u64 v_c19 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c21 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c21, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m894) {
        u64 v_c22 = m894[1];
        u64 v_c23 = m894[2];
        if (buckethash(v_c22) != bucket) return;
        slog::join_probe<3,3>($seq_atindex870, std::array<u64,3>{v_c18, v_c22, v_c23}, [&](const std::array<u64,3>& m895) {
          slog::join_probe<3,3>($seq_atindex871, std::array<u64,3>{v_c19, v_c22, v_c23}, [&](const std::array<u64,3>& m896) {
            slog::join_probe<3,3>($seq_atrindex872, std::array<u64,3>{v_c20, v_c22, v_c23}, [&](const std::array<u64,3>& m897) {
              slog::join_probe<2,2>(_enumindex873, std::array<u64,2>{v_c22, v_c14}, [&](const std::array<u64,2>& m898) {
                slog::join_probe<3,1>(deltaindex874, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m899) {
                  u64 v_c24 = m899[1]; u64 v_c25 = m899[2];
                  slog::join_probe<1,1>(comparison_opindex875, std::array<u64,1>{v_c25}, [&](const std::array<u64,1>& m900) {
                    slog::join_all<1>(any_boolindex876, [&](const std::array<u64,1>& m901) {
                      u64 v_c26 = m901[0];
                      bool ok902 = true;
                      u64 v_c27 = _prim_aslst(db, v_c23, &ok902);
                      if (!ok902) return;
                      u64 v_c249 = _prim_llen(db, v_c27);
                      if (v_c249 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c15 != v_c249) return;
                      bool ok903 = true;
                      u64 v_c250 = _prim_lref(db, v_c27, v_c16, &ok903);
                      if (!ok903) return;
                      if (v_c22 != v_c250) return;
                      bool ok904 = true;
                      u64 v_c251 = _prim_lref(db, v_c27, v_c17, &ok904);
                      if (!ok904) return;
                      if (v_c22 != v_c251) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c24, v_c26});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c26}, std::array<u16,2>{1, 0});
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
        ReadTask877* _cont = new ReadTask877(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask877(db,b), false);
  // (crule (pre) (scan tick_ans __t0NvE30 l) (body (join-old tick (0 2 1) 1 (0 2 1) __t0NvE30 c __t3Fr129) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join eval (1 2 0) 2 __t3Fr129 c __64BN675) (join-old eval (2 0 1) 1 (2 0 1) c __t84Ji24 ef) (exists eval_ans (0 1) 1 __t84Ji24) (join-old app (0 1 2) 2 (0 1 2) __t3Fr129 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3tQh27) (exists eval_args_ans (0 1) 1 __t3tQh27) (join eval_ans (0 1) 1 __t84Ji24 __t6CK626) (join eval_args_ans (0 1) 1 __t3tQh27 vs) (join-old closure (0 1 2) 1 (0 1 2) __t6CK626 __t3miO28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t3miO28 y) (join binding (0 1 2) 2 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3miO28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask927 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tickindex905;  slog::Index** evalindex906;  slog::Index** eval_argsindex907;  slog::Index** evalindex908;  slog::Index** evalindex909;  slog::Index** eval_ansindex910;  slog::Index** appindex911;  slog::Index** eval_argsindex912;  slog::Index** eval_args_ansindex913;  slog::Index** eval_ansindex914;  slog::Index** eval_args_ansindex915;  slog::Index** closureindex916;  slog::Index** bindingindex917;  slog::Index** freevarindex918;  slog::Index** bindingindex919;  slog::Index** lambdaindex920;  slog::Index** tickdelta921;  slog::Index** evaldelta922;  slog::Index** appdelta923;  slog::Index** eval_argsdelta924;  slog::Index** closuredelta925;  slog::Index** lambdadelta926;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord928({0, 1, 2});
      slog::Relation* readrel929 = db->getRelation("binding");
      head_index[0] = readrel929->getIndex(ord928, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord930({0, 1, 2});
      slog::Relation* readrel931 = db->getRelation("binding_event");
      head_index[1] = readrel931->getIndex(ord930, false);
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord932({0, 2, 1});
      slog::Relation* readrel933 = db->getRelation("tick");
      tickindex905 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({0, 2, 1});
      slog::Relation* readrel935 = db->getRelation("tick");
      tickdelta921 = readrel935->getIndex(ord934, true);
      std::vector<u16> ord936({2, 0, 1});
      slog::Relation* readrel937 = db->getRelation("eval");
      evalindex906 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({2, 0, 1});
      slog::Relation* readrel939 = db->getRelation("eval_args");
      eval_argsindex907 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({1, 2, 0});
      slog::Relation* readrel941 = db->getRelation("eval");
      evalindex908 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({2, 0, 1});
      slog::Relation* readrel943 = db->getRelation("eval");
      evalindex909 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({2, 0, 1});
      slog::Relation* readrel945 = db->getRelation("eval");
      evaldelta922 = readrel945->getIndex(ord944, true);
      std::vector<u16> ord946({0, 1});
      slog::Relation* readrel947 = db->getRelation("eval_ans");
      eval_ansindex910 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({0, 1, 2});
      slog::Relation* readrel949 = db->getRelation("app");
      appindex911 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({0, 1, 2});
      slog::Relation* readrel951 = db->getRelation("app");
      appdelta923 = readrel951->getIndex(ord950, true);
      std::vector<u16> ord952({1, 2, 0});
      slog::Relation* readrel953 = db->getRelation("eval_args");
      eval_argsindex912 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({1, 2, 0});
      slog::Relation* readrel955 = db->getRelation("eval_args");
      eval_argsdelta924 = readrel955->getIndex(ord954, true);
      std::vector<u16> ord956({0, 1});
      slog::Relation* readrel957 = db->getRelation("eval_args_ans");
      eval_args_ansindex913 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({0, 1});
      slog::Relation* readrel959 = db->getRelation("eval_ans");
      eval_ansindex914 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({0, 1});
      slog::Relation* readrel961 = db->getRelation("eval_args_ans");
      eval_args_ansindex915 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({0, 1, 2});
      slog::Relation* readrel963 = db->getRelation("closure");
      closureindex916 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({0, 1, 2});
      slog::Relation* readrel965 = db->getRelation("closure");
      closuredelta925 = readrel965->getIndex(ord964, true);
      std::vector<u16> ord966({1, 0, 2});
      slog::Relation* readrel967 = db->getRelation("binding");
      bindingindex917 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({1, 0});
      slog::Relation* readrel969 = db->getRelation("freevar");
      freevarindex918 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({0, 1, 2});
      slog::Relation* readrel971 = db->getRelation("binding");
      bindingindex919 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({0, 1, 2});
      slog::Relation* readrel973 = db->getRelation("lambda");
      lambdaindex920 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({0, 1, 2});
      slog::Relation* readrel975 = db->getRelation("lambda");
      lambdadelta926 = readrel975->getIndex(ord974, true);
  
    }
    ReadTask927(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c214 = _t[0];
        u64 v_c216 = _t[1];
        slog::join_probe_old<3,1>(tickindex905, tickdelta921, std::array<u64,3>{v_c214, 0, 0}, [&](const std::array<u64,3>& m976) {
          u64 v_c50 = m976[1]; u64 v_c212 = m976[2];
          if (!slog::exists_probe<3,1>(evalindex906, std::array<u64,3>{v_c50, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex907, std::array<u64,3>{v_c50, 0, 0})) return;
          slog::join_probe<3,2>(evalindex908, std::array<u64,3>{v_c212, v_c50, 0}, [&](const std::array<u64,3>& m977) {
            u64 v_c211 = m977[2];
            slog::join_probe_old<3,1>(evalindex909, evaldelta922, std::array<u64,3>{v_c50, 0, 0}, [&](const std::array<u64,3>& m978) {
              u64 v_c209 = m978[1]; u64 v_c51 = m978[2];
              if (!slog::exists_probe<2,1>(eval_ansindex910, std::array<u64,2>{v_c209, 0})) return;
              slog::join_probe_old<3,2>(appindex911, appdelta923, std::array<u64,3>{v_c212, v_c51, 0}, [&](const std::array<u64,3>& m979) {
                u64 v_c52 = m979[2];
                slog::join_probe_old<3,2>(eval_argsindex912, eval_argsdelta924, std::array<u64,3>{v_c52, v_c50, 0}, [&](const std::array<u64,3>& m980) {
                  u64 v_c213 = m980[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex913, std::array<u64,2>{v_c213, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex914, std::array<u64,2>{v_c209, 0}, [&](const std::array<u64,2>& m981) {
                    u64 v_c210 = m981[1];
                    slog::join_probe<2,1>(eval_args_ansindex915, std::array<u64,2>{v_c213, 0}, [&](const std::array<u64,2>& m982) {
                      u64 v_c215 = m982[1];
                      slog::join_probe_old<3,1>(closureindex916, closuredelta925, std::array<u64,3>{v_c210, 0, 0}, [&](const std::array<u64,3>& m983) {
                        u64 v_c217 = m983[1]; u64 v_c64 = m983[2];
                        if (!slog::exists_probe<3,1>(bindingindex917, std::array<u64,3>{v_c64, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex918, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m984) {
                          u64 v_c90 = m984[1];
                          slog::join_probe<3,2>(bindingindex919, std::array<u64,3>{v_c90, v_c64, 0}, [&](const std::array<u64,3>& m985) {
                            u64 v_c91 = m985[2];
                            slog::join_probe_old<3,1>(lambdaindex920, lambdadelta926, std::array<u64,3>{v_c217, 0, 0}, [&](const std::array<u64,3>& m986) {
                              u64 v_c93 = m986[1]; u64 v_c94 = m986[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c90, v_c216, v_c91}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c90, v_c216, v_c50}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:tick_ans", _fires);
  
      if (!_done)
      {
        ReadTask927* _cont = new ReadTask927(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask927(db,b), false);
  // (crule (pre) (scan temp4fHg844 __t9afR20 b) (body (join boolval (1 0) 1 b __t975c18)) (head (emit delta_ans (0 1) __t9afR20 __t975c18)) interp.slog:121 #f)
  class ReadTask988 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex987;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord989({0, 1});
      slog::Relation* readrel990 = db->getRelation("delta_ans");
      head_index[0] = readrel990->getIndex(ord989, false);
      outer_rel = db->getRelation("temp4fHg844");
      std::vector<u16> ord991({1, 0});
      slog::Relation* readrel992 = db->getRelation("boolval");
      boolvalindex987 = readrel992->getIndex(ord991, false);
  
    }
    ReadTask988(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c116 = _t[0];
        u64 v_c26 = _t[1];
        slog::join_probe<2,1>(boolvalindex987, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m993) {
          u64 v_c252 = m993[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c116, v_c252}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:temp4fHg844", _fires);
  
      if (!_done)
      {
        ReadTask988* _cont = new ReadTask988(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask988(db,b), false);
  // (crule (pre) (scan tick __t9uJP175 __t6KUR174 c) (body (exists eval (2 0 1) 1 c) (exists $sup56712x41x0x0x0 (1 0 2 3) 1 c) (exists eval_args (2 0 1) 1 c) (join tick_ans (0 1) 1 __t9uJP175 __v0) (join eval (2 0 1) 1 c __t66Yt170 ef) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists eval_ans (0 1) 1 __t66Yt170) (join app (0 1 2) 2 __t6KUR174 ef es) (exists eval_args (1 2 0) 2 es c) (join $sup56712x41x0x0x0 (1 2 3 0) 3 c ef es __d0) (join eval_args (1 2 0) 2 es c __t3FCg173) (exists eval_args_ans (0 1) 1 __t3FCg173) (join eval_ans (0 1) 1 __t66Yt170 __t8UWw172) (join eval_args_ans (0 1) 1 __t3FCg173 vs) (join closure (0 1 2) 1 __t8UWw172 __t3anZ171 cb) (join lambda (0 1 2) 1 __t3anZ171 xs eb)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask1010 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex994;  slog::Index** $sup56712x41x0x0x0index995;  slog::Index** eval_argsindex996;  slog::Index** tick_ansindex997;  slog::Index** evalindex998;  slog::Index** $sup56712x41x0x0x0index999;  slog::Index** eval_ansindex1000;  slog::Index** appindex1001;  slog::Index** eval_argsindex1002;  slog::Index** $sup56712x41x0x0x0index1003;  slog::Index** eval_argsindex1004;  slog::Index** eval_args_ansindex1005;  slog::Index** eval_ansindex1006;  slog::Index** eval_args_ansindex1007;  slog::Index** closureindex1008;  slog::Index** lambdaindex1009;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord1011({2, 0, 1});
      slog::Relation* readrel1012 = db->getRelation("eval");
      evalindex994 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({1, 0, 2, 3});
      slog::Relation* readrel1014 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index995 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({2, 0, 1});
      slog::Relation* readrel1016 = db->getRelation("eval_args");
      eval_argsindex996 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({0, 1});
      slog::Relation* readrel1018 = db->getRelation("tick_ans");
      tick_ansindex997 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({2, 0, 1});
      slog::Relation* readrel1020 = db->getRelation("eval");
      evalindex998 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({1, 2, 3, 0});
      slog::Relation* readrel1022 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index999 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({0, 1});
      slog::Relation* readrel1024 = db->getRelation("eval_ans");
      eval_ansindex1000 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({0, 1, 2});
      slog::Relation* readrel1026 = db->getRelation("app");
      appindex1001 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({1, 2, 0});
      slog::Relation* readrel1028 = db->getRelation("eval_args");
      eval_argsindex1002 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({1, 2, 3, 0});
      slog::Relation* readrel1030 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1003 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({1, 2, 0});
      slog::Relation* readrel1032 = db->getRelation("eval_args");
      eval_argsindex1004 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({0, 1});
      slog::Relation* readrel1034 = db->getRelation("eval_args_ans");
      eval_args_ansindex1005 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({0, 1});
      slog::Relation* readrel1036 = db->getRelation("eval_ans");
      eval_ansindex1006 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({0, 1});
      slog::Relation* readrel1038 = db->getRelation("eval_args_ans");
      eval_args_ansindex1007 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({0, 1, 2});
      slog::Relation* readrel1040 = db->getRelation("closure");
      closureindex1008 = readrel1040->getIndex(ord1039, false);
      std::vector<u16> ord1041({0, 1, 2});
      slog::Relation* readrel1042 = db->getRelation("lambda");
      lambdaindex1009 = readrel1042->getIndex(ord1041, false);
  
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
        u64 v_c253 = _t[0];
        u64 v_c254 = _t[1];
        u64 v_c50 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex994, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup56712x41x0x0x0index995, std::array<u64,4>{v_c50, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex996, std::array<u64,3>{v_c50, 0, 0})) return;
        slog::join_probe<2,1>(tick_ansindex997, std::array<u64,2>{v_c253, 0}, [&](const std::array<u64,2>& m1043) {
          u64 v_c165 = m1043[1];
          slog::join_probe<3,1>(evalindex998, std::array<u64,3>{v_c50, 0, 0}, [&](const std::array<u64,3>& m1044) {
            u64 v_c255 = m1044[1]; u64 v_c51 = m1044[2];
            if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index999, std::array<u64,4>{v_c50, v_c51, 0, 0})) return;
            if (!slog::exists_probe<2,1>(eval_ansindex1000, std::array<u64,2>{v_c255, 0})) return;
            slog::join_probe<3,2>(appindex1001, std::array<u64,3>{v_c254, v_c51, 0}, [&](const std::array<u64,3>& m1045) {
              u64 v_c52 = m1045[2];
              if (!slog::exists_probe<3,2>(eval_argsindex1002, std::array<u64,3>{v_c52, v_c50, 0})) return;
              slog::join_probe<4,3>($sup56712x41x0x0x0index1003, std::array<u64,4>{v_c50, v_c51, v_c52, 0}, [&](const std::array<u64,4>& m1046) {
                u64 v_c256 = m1046[3];
                slog::join_probe<3,2>(eval_argsindex1004, std::array<u64,3>{v_c52, v_c50, 0}, [&](const std::array<u64,3>& m1047) {
                  u64 v_c257 = m1047[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1005, std::array<u64,2>{v_c257, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1006, std::array<u64,2>{v_c255, 0}, [&](const std::array<u64,2>& m1048) {
                    u64 v_c258 = m1048[1];
                    slog::join_probe<2,1>(eval_args_ansindex1007, std::array<u64,2>{v_c257, 0}, [&](const std::array<u64,2>& m1049) {
                      u64 v_c215 = m1049[1];
                      slog::join_probe<3,1>(closureindex1008, std::array<u64,3>{v_c258, 0, 0}, [&](const std::array<u64,3>& m1050) {
                        u64 v_c259 = m1050[1]; u64 v_c64 = m1050[2];
                        slog::join_probe<3,1>(lambdaindex1009, std::array<u64,3>{v_c259, 0, 0}, [&](const std::array<u64,3>& m1051) {
                          u64 v_c93 = m1051[1]; u64 v_c94 = m1051[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c94, v_c165}, std::array<u16,3>{1, 2, 0});
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
  // (crule (pre (let __trid6eK6570 const119eb3a23d030ee0dfe9f807) (let __trel6iLy571 conste90c92f3e6c3b47a7bc93e42) (let __tcol7IXN572 const5feceb66ffc86f38d952786c) (let __trel3DPZ573 conste90c92f3e6c3b47a7bc93e42) (let __tcol6UP4574 const6b86b273ff34fce19d6b804e)) (scan $sup56712x41x0x0x0 __d0 c ef es) (body) (head (tycheck es (accept seq) __trid6eK6570 __trel6iLy571 __tcol7IXN572 (1 2 3 4 0)) (tycheck c (accept seq) __trid6eK6570 __trel3DPZ573 __tcol6UP4574 (1 2 3 4 0)) (mkstruct eval_args (1 2 0) __6YUB569 es c)) interp.slog:42 #f)
  class ReadTask1052 : public slog::Task
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
      head_rel[2] = db->getRelation("eval_args");
      outer_rel = db->getRelation("$sup56712x41x0x0x0");
  
    }
    ReadTask1052(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c260 = v_const119eb3a23d030ee0dfe9f807;
      u64 v_c261 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c262 = v_const5feceb66ffc86f38d952786c;
      u64 v_c263 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c264 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c256 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c52 = _t[3];
        ++_fires;
        if (!(is_seq(v_c52)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c260, v_c261, v_c262, v_c52}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c50)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c260, v_c263, v_c264, v_c50}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c52, v_c50}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:$sup56712x41x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1052* _cont = new ReadTask1052(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1052(db,b), false);
  // (crule (pre) (scan lambda __t4lcS166 xs eb) (body (join freevar (1 0) 1 __t4lcS166 y) (join binding (0 1 2) 1 y cb vy) (join-old eval (0 2 1) 0 (0 2 1) __0ffn676 c __t45PK165) (join-old app (0 1 2) 1 (0 1 2) __t45PK165 ef es)) (head (mkstruct eval_args (1 2 0) __3T4u677 es c)) interp.slog:56 #f)
  class ReadTask1059 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1053;  slog::Index** bindingindex1054;  slog::Index** evalindex1055;  slog::Index** appindex1056;  slog::Index** evaldelta1057;  slog::Index** appdelta1058;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1060({1, 0});
      slog::Relation* readrel1061 = db->getRelation("freevar");
      freevarindex1053 = readrel1061->getIndex(ord1060, false);
      std::vector<u16> ord1062({0, 1, 2});
      slog::Relation* readrel1063 = db->getRelation("binding");
      bindingindex1054 = readrel1063->getIndex(ord1062, false);
      std::vector<u16> ord1064({0, 2, 1});
      slog::Relation* readrel1065 = db->getRelation("eval");
      evalindex1055 = readrel1065->getIndex(ord1064, false);
      std::vector<u16> ord1066({0, 2, 1});
      slog::Relation* readrel1067 = db->getRelation("eval");
      evaldelta1057 = readrel1067->getIndex(ord1066, true);
      std::vector<u16> ord1068({0, 1, 2});
      slog::Relation* readrel1069 = db->getRelation("app");
      appindex1056 = readrel1069->getIndex(ord1068, false);
      std::vector<u16> ord1070({0, 1, 2});
      slog::Relation* readrel1071 = db->getRelation("app");
      appdelta1058 = readrel1071->getIndex(ord1070, true);
  
    }
    ReadTask1059(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c265 = _t[0];
        u64 v_c93 = _t[1];
        u64 v_c94 = _t[2];
        slog::join_probe<2,1>(freevarindex1053, std::array<u64,2>{v_c265, 0}, [&](const std::array<u64,2>& m1072) {
          u64 v_c90 = m1072[1];
          slog::join_probe<3,1>(bindingindex1054, std::array<u64,3>{v_c90, 0, 0}, [&](const std::array<u64,3>& m1073) {
            u64 v_c64 = m1073[1]; u64 v_c91 = m1073[2];
            slog::join_all_old<3>(evalindex1055, evaldelta1057, [&](const std::array<u64,3>& m1074) {
              u64 v_c266 = m1074[0]; u64 v_c50 = m1074[1]; u64 v_c267 = m1074[2];
              slog::join_probe_old<3,1>(appindex1056, appdelta1058, std::array<u64,3>{v_c267, 0, 0}, [&](const std::array<u64,3>& m1075) {
                u64 v_c51 = m1075[1]; u64 v_c52 = m1075[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c52, v_c50}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1059* _cont = new ReadTask1059(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1059(db,b), false);
  // (crule (pre) (scan eval_args __t6UxD181 es c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t6UxD181) (join $sup56712x41x0x0x0 (1 3 0 2) 2 c es __t6uzd177 ef) (exists app (1 2 0) 2 ef es) (exists eval (1 2 0) 2 ef c) (join eval (0 2 1) 2 __t6uzd177 c __t7cos183) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (exists tick (1 2 0) 2 __t7cos183 c) (join eval (1 2 0) 2 ef c __t6e44178) (exists eval_ans (0 1) 1 __t6e44178) (join-old tick (1 2 0) 2 (1 2 0) __t7cos183 c __t8kWT184) (exists tick_ans (0 1) 1 __t8kWT184) (join eval_ans (0 1) 1 __t6e44178 __t4yWQ180) (join eval_args_ans (0 1) 1 __t6UxD181 vs) (join tick_ans (0 1) 1 __t8kWT184 __v0) (exists eval (2 0 1) 1 __v0) (join closure (0 1 2) 1 __t4yWQ180 __t7rcY179 cb) (join lambda (0 1 2) 1 __t7rcY179 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t56Is182) (join eval_ans (0 1) 1 __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask1101 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1076;  slog::Index** appindex1077;  slog::Index** tickindex1078;  slog::Index** eval_args_ansindex1079;  slog::Index** $sup56712x41x0x0x0index1080;  slog::Index** appindex1081;  slog::Index** evalindex1082;  slog::Index** evalindex1083;  slog::Index** appindex1084;  slog::Index** tickindex1085;  slog::Index** evalindex1086;  slog::Index** eval_ansindex1087;  slog::Index** tickindex1088;  slog::Index** tick_ansindex1089;  slog::Index** eval_ansindex1090;  slog::Index** eval_args_ansindex1091;  slog::Index** tick_ansindex1092;  slog::Index** evalindex1093;  slog::Index** closureindex1094;  slog::Index** lambdaindex1095;  slog::Index** evalindex1096;  slog::Index** eval_ansindex1097;  slog::Index** appdelta1098;  slog::Index** tickdelta1099;  slog::Index** evaldelta1100;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1102({0, 1});
      slog::Relation* readrel1103 = db->getRelation("eval_ans");
      head_index[0] = readrel1103->getIndex(ord1102, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord1104({2, 0, 1});
      slog::Relation* readrel1105 = db->getRelation("eval");
      evalindex1076 = readrel1105->getIndex(ord1104, false);
      std::vector<u16> ord1106({2, 0, 1});
      slog::Relation* readrel1107 = db->getRelation("app");
      appindex1077 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({2, 0, 1});
      slog::Relation* readrel1109 = db->getRelation("tick");
      tickindex1078 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({0, 1});
      slog::Relation* readrel1111 = db->getRelation("eval_args_ans");
      eval_args_ansindex1079 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({1, 3, 0, 2});
      slog::Relation* readrel1113 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1080 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({1, 2, 0});
      slog::Relation* readrel1115 = db->getRelation("app");
      appindex1081 = readrel1115->getIndex(ord1114, false);
      std::vector<u16> ord1116({1, 2, 0});
      slog::Relation* readrel1117 = db->getRelation("eval");
      evalindex1082 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({0, 2, 1});
      slog::Relation* readrel1119 = db->getRelation("eval");
      evalindex1083 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({0, 1, 2});
      slog::Relation* readrel1121 = db->getRelation("app");
      appindex1084 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({0, 1, 2});
      slog::Relation* readrel1123 = db->getRelation("app");
      appdelta1098 = readrel1123->getIndex(ord1122, true);
      std::vector<u16> ord1124({1, 2, 0});
      slog::Relation* readrel1125 = db->getRelation("tick");
      tickindex1085 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({1, 2, 0});
      slog::Relation* readrel1127 = db->getRelation("eval");
      evalindex1086 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({0, 1});
      slog::Relation* readrel1129 = db->getRelation("eval_ans");
      eval_ansindex1087 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({1, 2, 0});
      slog::Relation* readrel1131 = db->getRelation("tick");
      tickindex1088 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({1, 2, 0});
      slog::Relation* readrel1133 = db->getRelation("tick");
      tickdelta1099 = readrel1133->getIndex(ord1132, true);
      std::vector<u16> ord1134({0, 1});
      slog::Relation* readrel1135 = db->getRelation("tick_ans");
      tick_ansindex1089 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({0, 1});
      slog::Relation* readrel1137 = db->getRelation("eval_ans");
      eval_ansindex1090 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({0, 1});
      slog::Relation* readrel1139 = db->getRelation("eval_args_ans");
      eval_args_ansindex1091 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({0, 1});
      slog::Relation* readrel1141 = db->getRelation("tick_ans");
      tick_ansindex1092 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({2, 0, 1});
      slog::Relation* readrel1143 = db->getRelation("eval");
      evalindex1093 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({0, 1, 2});
      slog::Relation* readrel1145 = db->getRelation("closure");
      closureindex1094 = readrel1145->getIndex(ord1144, false);
      std::vector<u16> ord1146({0, 1, 2});
      slog::Relation* readrel1147 = db->getRelation("lambda");
      lambdaindex1095 = readrel1147->getIndex(ord1146, false);
      std::vector<u16> ord1148({1, 2, 0});
      slog::Relation* readrel1149 = db->getRelation("eval");
      evalindex1096 = readrel1149->getIndex(ord1148, false);
      std::vector<u16> ord1150({1, 2, 0});
      slog::Relation* readrel1151 = db->getRelation("eval");
      evaldelta1100 = readrel1151->getIndex(ord1150, true);
      std::vector<u16> ord1152({0, 1});
      slog::Relation* readrel1153 = db->getRelation("eval_ans");
      eval_ansindex1097 = readrel1153->getIndex(ord1152, false);
  
    }
    ReadTask1101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c268 = _t[0];
        u64 v_c52 = _t[1];
        u64 v_c50 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1076, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1077, std::array<u64,3>{v_c52, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1078, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex1079, std::array<u64,2>{v_c268, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index1080, std::array<u64,4>{v_c50, v_c52, 0, 0}, [&](const std::array<u64,4>& m1154) {
          u64 v_c269 = m1154[2]; u64 v_c51 = m1154[3];
          if (!slog::exists_probe<3,2>(appindex1081, std::array<u64,3>{v_c51, v_c52, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex1082, std::array<u64,3>{v_c51, v_c50, 0})) return;
          slog::join_probe<3,2>(evalindex1083, std::array<u64,3>{v_c269, v_c50, 0}, [&](const std::array<u64,3>& m1155) {
            u64 v_c270 = m1155[2];
            slog::join_probe_old<3,3>(appindex1084, appdelta1098, std::array<u64,3>{v_c270, v_c51, v_c52}, [&](const std::array<u64,3>& m1156) {
              if (!slog::exists_probe<3,2>(tickindex1085, std::array<u64,3>{v_c270, v_c50, 0})) return;
              slog::join_probe<3,2>(evalindex1086, std::array<u64,3>{v_c51, v_c50, 0}, [&](const std::array<u64,3>& m1157) {
                u64 v_c271 = m1157[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1087, std::array<u64,2>{v_c271, 0})) return;
                slog::join_probe_old<3,2>(tickindex1088, tickdelta1099, std::array<u64,3>{v_c270, v_c50, 0}, [&](const std::array<u64,3>& m1158) {
                  u64 v_c272 = m1158[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex1089, std::array<u64,2>{v_c272, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1090, std::array<u64,2>{v_c271, 0}, [&](const std::array<u64,2>& m1159) {
                    u64 v_c273 = m1159[1];
                    slog::join_probe<2,1>(eval_args_ansindex1091, std::array<u64,2>{v_c268, 0}, [&](const std::array<u64,2>& m1160) {
                      u64 v_c215 = m1160[1];
                      slog::join_probe<2,1>(tick_ansindex1092, std::array<u64,2>{v_c272, 0}, [&](const std::array<u64,2>& m1161) {
                        u64 v_c165 = m1161[1];
                        if (!slog::exists_probe<3,1>(evalindex1093, std::array<u64,3>{v_c165, 0, 0})) return;
                        slog::join_probe<3,1>(closureindex1094, std::array<u64,3>{v_c273, 0, 0}, [&](const std::array<u64,3>& m1162) {
                          u64 v_c274 = m1162[1]; u64 v_c64 = m1162[2];
                          slog::join_probe<3,1>(lambdaindex1095, std::array<u64,3>{v_c274, 0, 0}, [&](const std::array<u64,3>& m1163) {
                            u64 v_c93 = m1163[1]; u64 v_c94 = m1163[2];
                            slog::join_probe_old<3,2>(evalindex1096, evaldelta1100, std::array<u64,3>{v_c94, v_c165, 0}, [&](const std::array<u64,3>& m1164) {
                              u64 v_c275 = m1164[2];
                              slog::join_probe<2,1>(eval_ansindex1097, std::array<u64,2>{v_c275, 0}, [&](const std::array<u64,2>& m1165) {
                                u64 v_c83 = m1165[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c269, v_c83}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask1101* _cont = new ReadTask1101(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1101(db,b), false);
  // (crule (pre) (scan freevar x ef) (body (join-old app (1 2 0) 1 (1 2 0) ef es __t1DIg130)) (head (emit freevar (0 1) x __t1DIg130)) freevars.slog:13 #f)
  class ReadTask1168 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1166;  slog::Index** appdelta1167;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1169({0, 1});
      slog::Relation* readrel1170 = db->getRelation("freevar");
      head_index[0] = readrel1170->getIndex(ord1169, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1171({1, 2, 0});
      slog::Relation* readrel1172 = db->getRelation("app");
      appindex1166 = readrel1172->getIndex(ord1171, false);
      std::vector<u16> ord1173({1, 2, 0});
      slog::Relation* readrel1174 = db->getRelation("app");
      appdelta1167 = readrel1174->getIndex(ord1173, true);
  
    }
    ReadTask1168(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c105 = _t[0];
        u64 v_c51 = _t[1];
        slog::join_probe_old<3,1>(appindex1166, appdelta1167, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m1175) {
          u64 v_c52 = m1175[1]; u64 v_c276 = m1175[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c105, v_c276}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1168* _cont = new ReadTask1168(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1168(db,b), false);
  // (crule (pre (let __t5icw66 (lempty))) (scan tick __t6YR069 site c) (body (join mlimit (0) 0 m)) (head (emit-temp temp4IIT859 __t5icw66 c m site)) context.slog:10 #f)
  class ReadTask1177 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mlimitindex1176;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4IIT859");
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord1178({0});
      slog::Relation* readrel1179 = db->getRelation("mlimit");
      mlimitindex1176 = readrel1179->getIndex(ord1178, false);
  
    }
    ReadTask1177(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c277 = _prim_lempty(db);
      if (v_c277 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c278 = _t[0];
        u64 v_c167 = _t[1];
        u64 v_c50 = _t[2];
        slog::join_all<1>(mlimitindex1176, [&](const std::array<u64,1>& m1180) {
          u64 v_c164 = m1180[0];
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c277, v_c50, v_c164, v_c167});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask1177* _cont = new ReadTask1177(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1177(db,b), false);
  // (crule (pre) (scan app __t9RxE131 ef es) (body (join freevar_in_args (1 0) 1 es x)) (head (emit freevar (0 1) x __t9RxE131)) freevars.slog:13 #f)
  class ReadTask1182 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevar_in_argsindex1181;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1183({0, 1});
      slog::Relation* readrel1184 = db->getRelation("freevar");
      head_index[0] = readrel1184->getIndex(ord1183, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1185({1, 0});
      slog::Relation* readrel1186 = db->getRelation("freevar_in_args");
      freevar_in_argsindex1181 = readrel1186->getIndex(ord1185, false);
  
    }
    ReadTask1182(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c279 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c52 = _t[2];
        slog::join_probe<2,1>(freevar_in_argsindex1181, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m1187) {
          u64 v_c105 = m1187[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c105, v_c279}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1182* _cont = new ReadTask1182(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1182(db,b), false);
  // (crule (pre (let __tconst2WdB587 const0122baa3ac55f1b433944eb1) (let __tconst2sal328 const06abaa100ecef791ce028c56) (let _00024sqc4hbO465 constd4735e3a265e16eee03f5971) (let _00024sqc8eTz466 const5feceb66ffc86f38d952786c) (let _00024sqc7Ewc467 const6b86b273ff34fce19d6b804e) (let _00024sqo5RED468 const5feceb66ffc86f38d952786c) (let _00024sqo66CB469 const6b86b273ff34fce19d6b804e) (let _00024sqo5qV2470 const6b86b273ff34fce19d6b804e) (let _00024sqo4yFo471 const5feceb66ffc86f38d952786c)) (scan symval __t5qKD331 s) (body (exists $seq_at (1 0 2) 2 _00024sqo66CB469 __t5qKD331) (exists $seq_atr (1 0 2) 2 _00024sqo5qV2470 __t5qKD331) (exists $seq_atr (1 0 2) 2 _00024sqo4yFo471 __t5qKD331) (exists delta (1 2 0) 1 __tconst2sal328) (exists _enum (1 0) 1 __tconst2WdB587) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo5RED468 __t5qKD331 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo66CB469 __t5qKD331 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5qV2470 __t5qKD331 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4yFo471 __t5qKD331 _00024seq2) (join delta (1 2 0) 2 __tconst2sal328 _00024seq2 __t8DFh329) (join _enum (1 0) 1 __tconst2WdB587 __t44Xg326) (letp _00024sql2Y3P463 (aslst _00024seq2)) (let chk1LKJ883 (llen _00024sql2Y3P463)) (eq _00024sqc4hbO465 chk1LKJ883) (letp chk1LPj884 (lref _00024sql2Y3P463 _00024sqc8eTz466)) (eq __t5qKD331 chk1LPj884) (letp chk9QB2885 (lref _00024sql2Y3P463 _00024sqc7Ewc467)) (eq __t5qKD331 chk9QB2885)) (head (emit-temp temp24NP880 __t8DFh329) (mkstruct boolval (1 0) __t5zQU327 __t44Xg326)) interp.slog:117 #f)
  class ReadTask1203 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex1188;  slog::Index** $seq_atrindex1189;  slog::Index** $seq_atrindex1190;  slog::Index** deltaindex1191;  slog::Index** _enumindex1192;  slog::Index** $seq_atindex1193;  slog::Index** $seq_atindex1194;  slog::Index** $seq_atrindex1195;  slog::Index** $seq_atrindex1196;  slog::Index** deltaindex1197;  slog::Index** _enumindex1198;  slog::Index** $seq_atdelta1199;  slog::Index** $seq_atdelta1200;  slog::Index** $seq_atrdelta1201;  slog::Index** $seq_atrdelta1202;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp24NP880");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("symval");
      std::vector<u16> ord1204({1, 0, 2});
      slog::Relation* readrel1205 = db->getRelation("$seq_at");
      $seq_atindex1188 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({1, 0, 2});
      slog::Relation* readrel1207 = db->getRelation("$seq_atr");
      $seq_atrindex1189 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({1, 0, 2});
      slog::Relation* readrel1209 = db->getRelation("$seq_atr");
      $seq_atrindex1190 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 2, 0});
      slog::Relation* readrel1211 = db->getRelation("delta");
      deltaindex1191 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({1, 0});
      slog::Relation* readrel1213 = db->getRelation("_enum");
      _enumindex1192 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({1, 0, 2});
      slog::Relation* readrel1215 = db->getRelation("$seq_at");
      $seq_atindex1193 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({1, 0, 2});
      slog::Relation* readrel1217 = db->getRelation("$seq_at");
      $seq_atdelta1199 = readrel1217->getIndex(ord1216, true);
      std::vector<u16> ord1218({1, 0, 2});
      slog::Relation* readrel1219 = db->getRelation("$seq_at");
      $seq_atindex1194 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({1, 0, 2});
      slog::Relation* readrel1221 = db->getRelation("$seq_at");
      $seq_atdelta1200 = readrel1221->getIndex(ord1220, true);
      std::vector<u16> ord1222({1, 0, 2});
      slog::Relation* readrel1223 = db->getRelation("$seq_atr");
      $seq_atrindex1195 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({1, 0, 2});
      slog::Relation* readrel1225 = db->getRelation("$seq_atr");
      $seq_atrdelta1201 = readrel1225->getIndex(ord1224, true);
      std::vector<u16> ord1226({1, 0, 2});
      slog::Relation* readrel1227 = db->getRelation("$seq_atr");
      $seq_atrindex1196 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({1, 0, 2});
      slog::Relation* readrel1229 = db->getRelation("$seq_atr");
      $seq_atrdelta1202 = readrel1229->getIndex(ord1228, true);
      std::vector<u16> ord1230({1, 2, 0});
      slog::Relation* readrel1231 = db->getRelation("delta");
      deltaindex1197 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({1, 0});
      slog::Relation* readrel1233 = db->getRelation("_enum");
      _enumindex1198 = readrel1233->getIndex(ord1232, false);
  
    }
    ReadTask1203(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c280 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c281 = v_const06abaa100ecef791ce028c56;
      u64 v_c282 = v_constd4735e3a265e16eee03f5971;
      u64 v_c283 = v_const5feceb66ffc86f38d952786c;
      u64 v_c284 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c285 = v_const5feceb66ffc86f38d952786c;
      u64 v_c286 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c287 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c288 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c289 = _t[0];
        u64 v_c290 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex1188, std::array<u64,3>{v_c286, v_c289, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex1189, std::array<u64,3>{v_c287, v_c289, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex1190, std::array<u64,3>{v_c288, v_c289, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex1191, std::array<u64,3>{v_c281, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex1192, std::array<u64,2>{v_c280, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex1193, $seq_atdelta1199, std::array<u64,3>{v_c285, v_c289, 0}, [&](const std::array<u64,3>& m1234) {
          u64 v_c23 = m1234[2];
          slog::join_probe_old<3,3>($seq_atindex1194, $seq_atdelta1200, std::array<u64,3>{v_c286, v_c289, v_c23}, [&](const std::array<u64,3>& m1235) {
            slog::join_probe_old<3,3>($seq_atrindex1195, $seq_atrdelta1201, std::array<u64,3>{v_c287, v_c289, v_c23}, [&](const std::array<u64,3>& m1236) {
              slog::join_probe_old<3,3>($seq_atrindex1196, $seq_atrdelta1202, std::array<u64,3>{v_c288, v_c289, v_c23}, [&](const std::array<u64,3>& m1237) {
                slog::join_probe<3,2>(deltaindex1197, std::array<u64,3>{v_c281, v_c23, 0}, [&](const std::array<u64,3>& m1238) {
                  u64 v_c291 = m1238[2];
                  slog::join_probe<2,1>(_enumindex1198, std::array<u64,2>{v_c280, 0}, [&](const std::array<u64,2>& m1239) {
                    u64 v_c292 = m1239[1];
                    bool ok1240 = true;
                    u64 v_c293 = _prim_aslst(db, v_c23, &ok1240);
                    if (!ok1240) return;
                    u64 v_c294 = _prim_llen(db, v_c293);
                    if (v_c294 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c282 != v_c294) return;
                    bool ok1241 = true;
                    u64 v_c295 = _prim_lref(db, v_c293, v_c283, &ok1241);
                    if (!ok1241) return;
                    if (v_c289 != v_c295) return;
                    bool ok1242 = true;
                    u64 v_c296 = _prim_lref(db, v_c293, v_c284, &ok1242);
                    if (!ok1242) return;
                    if (v_c289 != v_c296) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c291});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c292}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:symval", _fires);
  
      if (!_done)
      {
        ReadTask1203* _cont = new ReadTask1203(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1203(db,b), false);
  // (crule (pre (let __tconst2WdB587 const0122baa3ac55f1b433944eb1) (let __tconst2sal328 const06abaa100ecef791ce028c56) (let _00024sqc4hbO465 constd4735e3a265e16eee03f5971) (let _00024sqc8eTz466 const5feceb66ffc86f38d952786c) (let _00024sqc7Ewc467 const6b86b273ff34fce19d6b804e) (let _00024sqo5RED468 const5feceb66ffc86f38d952786c) (let _00024sqo66CB469 const6b86b273ff34fce19d6b804e) (let _00024sqo5qV2470 const6b86b273ff34fce19d6b804e) (let _00024sqo4yFo471 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst2sal328 _00024seq2 __t8DFh329) (body (letp _00024sql2Y3P463 (aslst _00024seq2)) (letp __t5qKD331 (lref _00024sql2Y3P463 _00024sqc8eTz466)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5RED468 __t5qKD331 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo66CB469 __t5qKD331 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5qV2470 __t5qKD331 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4yFo471 __t5qKD331 _00024seq2) (join _enum (1 0) 1 __tconst2WdB587 __t44Xg326) (join-old symval (0 1) 1 (0 1) __t5qKD331 s) (let chk68ot881 (llen _00024sql2Y3P463)) (eq _00024sqc4hbO465 chk68ot881) (letp chk3nKO882 (lref _00024sql2Y3P463 _00024sqc7Ewc467)) (eq __t5qKD331 chk3nKO882)) (head (emit-temp temp24NP880 __t8DFh329) (mkstruct boolval (1 0) __t5zQU327 __t44Xg326)) interp.slog:117 #f)
  class ReadTask1254 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1243;  slog::Index** $seq_atindex1244;  slog::Index** $seq_atrindex1245;  slog::Index** $seq_atrindex1246;  slog::Index** _enumindex1247;  slog::Index** symvalindex1248;  slog::Index** $seq_atdelta1249;  slog::Index** $seq_atdelta1250;  slog::Index** $seq_atrdelta1251;  slog::Index** $seq_atrdelta1252;  slog::Index** symvaldelta1253;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp24NP880");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1255({1, 2, 0});
      slog::Relation* readrel1256 = db->getRelation("delta");
      driver_index = readrel1256->getIndex(ord1255, true);
      std::vector<u16> ord1257({1, 0, 2});
      slog::Relation* readrel1258 = db->getRelation("$seq_at");
      $seq_atindex1243 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({1, 0, 2});
      slog::Relation* readrel1260 = db->getRelation("$seq_at");
      $seq_atdelta1249 = readrel1260->getIndex(ord1259, true);
      std::vector<u16> ord1261({1, 0, 2});
      slog::Relation* readrel1262 = db->getRelation("$seq_at");
      $seq_atindex1244 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({1, 0, 2});
      slog::Relation* readrel1264 = db->getRelation("$seq_at");
      $seq_atdelta1250 = readrel1264->getIndex(ord1263, true);
      std::vector<u16> ord1265({1, 0, 2});
      slog::Relation* readrel1266 = db->getRelation("$seq_atr");
      $seq_atrindex1245 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({1, 0, 2});
      slog::Relation* readrel1268 = db->getRelation("$seq_atr");
      $seq_atrdelta1251 = readrel1268->getIndex(ord1267, true);
      std::vector<u16> ord1269({1, 0, 2});
      slog::Relation* readrel1270 = db->getRelation("$seq_atr");
      $seq_atrindex1246 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({1, 0, 2});
      slog::Relation* readrel1272 = db->getRelation("$seq_atr");
      $seq_atrdelta1252 = readrel1272->getIndex(ord1271, true);
      std::vector<u16> ord1273({1, 0});
      slog::Relation* readrel1274 = db->getRelation("_enum");
      _enumindex1247 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({0, 1});
      slog::Relation* readrel1276 = db->getRelation("symval");
      symvalindex1248 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({0, 1});
      slog::Relation* readrel1278 = db->getRelation("symval");
      symvaldelta1253 = readrel1278->getIndex(ord1277, true);
  
    }
    ReadTask1254(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c280 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c281 = v_const06abaa100ecef791ce028c56;
      u64 v_c282 = v_constd4735e3a265e16eee03f5971;
      u64 v_c283 = v_const5feceb66ffc86f38d952786c;
      u64 v_c284 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c285 = v_const5feceb66ffc86f38d952786c;
      u64 v_c286 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c287 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c288 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c281, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1279) {
        u64 v_c23 = m1279[1];
        u64 v_c291 = m1279[2];
        if (buckethash(v_c23) != bucket) return;
        bool ok1280 = true;
        u64 v_c293 = _prim_aslst(db, v_c23, &ok1280);
        if (!ok1280) return;
        bool ok1281 = true;
        u64 v_c289 = _prim_lref(db, v_c293, v_c283, &ok1281);
        if (!ok1281) return;
        slog::join_probe_old<3,3>($seq_atindex1243, $seq_atdelta1249, std::array<u64,3>{v_c285, v_c289, v_c23}, [&](const std::array<u64,3>& m1282) {
          slog::join_probe_old<3,3>($seq_atindex1244, $seq_atdelta1250, std::array<u64,3>{v_c286, v_c289, v_c23}, [&](const std::array<u64,3>& m1283) {
            slog::join_probe_old<3,3>($seq_atrindex1245, $seq_atrdelta1251, std::array<u64,3>{v_c287, v_c289, v_c23}, [&](const std::array<u64,3>& m1284) {
              slog::join_probe_old<3,3>($seq_atrindex1246, $seq_atrdelta1252, std::array<u64,3>{v_c288, v_c289, v_c23}, [&](const std::array<u64,3>& m1285) {
                slog::join_probe<2,1>(_enumindex1247, std::array<u64,2>{v_c280, 0}, [&](const std::array<u64,2>& m1286) {
                  u64 v_c292 = m1286[1];
                  slog::join_probe_old<2,1>(symvalindex1248, symvaldelta1253, std::array<u64,2>{v_c289, 0}, [&](const std::array<u64,2>& m1287) {
                    u64 v_c290 = m1287[1];
                    u64 v_c297 = _prim_llen(db, v_c293);
                    if (v_c297 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c282 != v_c297) return;
                    bool ok1288 = true;
                    u64 v_c298 = _prim_lref(db, v_c293, v_c284, &ok1288);
                    if (!ok1288) return;
                    if (v_c289 != v_c298) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c291});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c292}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask1254* _cont = new ReadTask1254(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1254(db,b), false);
  // (crule (pre (let _00024seq0 (lempty))) (scan program e) (body) (head (mkstruct eval (1 2 0) __22D9674 e _00024seq0)) interp.slog:130 #f)
  class ReadTask1289 : public slog::Task
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
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("program");
  
    }
    ReadTask1289(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = _prim_lempty(db);
      if (v_c41 == slog_error) { slog::emit_pending_error(db, "interp.slog:130"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c155 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c155, v_c41}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:130", "delta:program", _fires);
  
      if (!_done)
      {
        ReadTask1289* _cont = new ReadTask1289(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1289(db,b), false);
}

