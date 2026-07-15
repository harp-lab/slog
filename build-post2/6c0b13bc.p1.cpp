
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const00b70a53bc33238570e12d7a;
extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0388ead47e9d5ccfc5320715;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const53a56174f3826669a422fc54;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const71dc04e9084b526ffd253a28;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const829935b42173b360da35f679;
extern u64 v_const879923da020d1533f4d8e921;
extern u64 v_const8c8656c5d114d7f8b2a412d2;
extern u64 v_const8ca5d81566f88badd698137a;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdcc297bb3300d9549a9d611a;
extern u64 v_constf77801bebb40767a1b303d97;


void slog_rules_c0d233b56a8765c89(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan eval_ans __t3KJV375 v) (body (join-old eval (0 2 1) 1 (0 2 1) __t3KJV375 c eb) (exists let (3 0 1 2) 1 eb) (exists eval (2 0 1) 1 c) (join-old $sup56712x91x0x0x0 (1 2 0 3 4) 2 (1 2 0 3 4) c eb __t9U3N373 er x) (exists eval (0 2 1) 2 __t9U3N373 c) (exists eval (1 2 0) 2 er c) (join-old let (2 1 3 0) 3 (2 1 3 0) er x eb __t78XS372) (join-old eval (0 2 1) 3 (0 2 1) __t9U3N373 c __t78XS372) (join-old eval (1 2 0) 2 (1 2 0) er c __t7j91374) (join eval_ans (0 1) 1 __t7j91374 vr)) (head (emit eval_ans (0 1) __t9U3N373 v)) interp.slog:92 #f)
  class ReadTask15 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex0;  slog::Index** letindex1;  slog::Index** evalindex2;  slog::Index** $sup56712x91x0x0x0index3;  slog::Index** evalindex4;  slog::Index** evalindex5;  slog::Index** letindex6;  slog::Index** evalindex7;  slog::Index** evalindex8;  slog::Index** eval_ansindex9;  slog::Index** evaldelta10;  slog::Index** $sup56712x91x0x0x0delta11;  slog::Index** letdelta12;  slog::Index** evaldelta13;  slog::Index** evaldelta14;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord16({0, 1});
      slog::Relation* readrel17 = db->getRelation("eval_ans");
      head_index[0] = readrel17->getIndex(ord16, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord18({0, 2, 1});
      slog::Relation* readrel19 = db->getRelation("eval");
      evalindex0 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 2, 1});
      slog::Relation* readrel21 = db->getRelation("eval");
      evaldelta10 = readrel21->getIndex(ord20, true);
      std::vector<u16> ord22({3, 0, 1, 2});
      slog::Relation* readrel23 = db->getRelation("let");
      letindex1 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({2, 0, 1});
      slog::Relation* readrel25 = db->getRelation("eval");
      evalindex2 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 2, 0, 3, 4});
      slog::Relation* readrel27 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index3 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 2, 0, 3, 4});
      slog::Relation* readrel29 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0delta11 = readrel29->getIndex(ord28, true);
      std::vector<u16> ord30({0, 2, 1});
      slog::Relation* readrel31 = db->getRelation("eval");
      evalindex4 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 2, 0});
      slog::Relation* readrel33 = db->getRelation("eval");
      evalindex5 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({2, 1, 3, 0});
      slog::Relation* readrel35 = db->getRelation("let");
      letindex6 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({2, 1, 3, 0});
      slog::Relation* readrel37 = db->getRelation("let");
      letdelta12 = readrel37->getIndex(ord36, true);
      std::vector<u16> ord38({0, 2, 1});
      slog::Relation* readrel39 = db->getRelation("eval");
      evalindex7 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({0, 2, 1});
      slog::Relation* readrel41 = db->getRelation("eval");
      evaldelta13 = readrel41->getIndex(ord40, true);
      std::vector<u16> ord42({1, 2, 0});
      slog::Relation* readrel43 = db->getRelation("eval");
      evalindex8 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 2, 0});
      slog::Relation* readrel45 = db->getRelation("eval");
      evaldelta14 = readrel45->getIndex(ord44, true);
      std::vector<u16> ord46({0, 1});
      slog::Relation* readrel47 = db->getRelation("eval_ans");
      eval_ansindex9 = readrel47->getIndex(ord46, false);
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(evalindex0, evaldelta10, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m48) {
          u64 v_c2 = m48[1]; u64 v_c3 = m48[2];
          if (!slog::exists_probe<4,1>(letindex1, std::array<u64,4>{v_c3, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex2, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x91x0x0x0index3, $sup56712x91x0x0x0delta11, std::array<u64,5>{v_c2, v_c3, 0, 0, 0}, [&](const std::array<u64,5>& m49) {
            u64 v_c4 = m49[2]; u64 v_c5 = m49[3]; u64 v_c6 = m49[4];
            if (!slog::exists_probe<3,2>(evalindex4, std::array<u64,3>{v_c4, v_c2, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex5, std::array<u64,3>{v_c5, v_c2, 0})) return;
            slog::join_probe_old<4,3>(letindex6, letdelta12, std::array<u64,4>{v_c5, v_c6, v_c3, 0}, [&](const std::array<u64,4>& m50) {
              u64 v_c7 = m50[3];
              slog::join_probe_old<3,3>(evalindex7, evaldelta13, std::array<u64,3>{v_c4, v_c2, v_c7}, [&](const std::array<u64,3>& m51) {
                slog::join_probe_old<3,2>(evalindex8, evaldelta14, std::array<u64,3>{v_c5, v_c2, 0}, [&](const std::array<u64,3>& m52) {
                  u64 v_c8 = m52[2];
                  slog::join_probe<2,1>(eval_ansindex9, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m53) {
                    u64 v_c9 = m53[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c1}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask15* _cont = new ReadTask15(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), false);
  // (crule (pre (let __tconst0GOL695 const0122baa3ac55f1b433944eb1) (let __tconst6e36161 const06abaa100ecef791ce028c56) (let _00024sqc80WS474 constd4735e3a265e16eee03f5971) (let _00024sqc8EM3475 const5feceb66ffc86f38d952786c) (let _00024sqc7MGk476 const6b86b273ff34fce19d6b804e) (let _00024sqo5t7q477 const5feceb66ffc86f38d952786c) (let _00024sqo2Tf4478 const6b86b273ff34fce19d6b804e) (let _00024sqo8e4d479 const6b86b273ff34fce19d6b804e) (let _00024sqo87UW480 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo2Tf4478 __t5NWC164 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5t7q477 __t5NWC164 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8e4d479 __t5NWC164 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo87UW480 __t5NWC164 _00024seq2) (exists _enum (1 0) 1 __tconst0GOL695) (join delta (1 2 0) 2 __tconst6e36161 _00024seq2 __t2Zbc162) (join _enum (1 0) 1 __tconst0GOL695 __t2rtp159) (join prim (0 1) 1 __t5NWC164 op) (letp _00024sql8XpT472 (aslst _00024seq2)) (let chk1laC981 (llen _00024sql8XpT472)) (eq _00024sqc80WS474 chk1laC981) (letp chk4UlM982 (lref _00024sql8XpT472 _00024sqc8EM3475)) (eq __t5NWC164 chk4UlM982) (letp chk44PT983 (lref _00024sql8XpT472 _00024sqc7MGk476)) (eq __t5NWC164 chk44PT983)) (head (emit-temp temp50La972 __t2Zbc162) (mkstruct boolval (1 0) __t5Llk160 __t2rtp159)) interp.slog:119 #f)
  class ReadTask63 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex54;  slog::Index** $seq_atrindex55;  slog::Index** $seq_atrindex56;  slog::Index** _enumindex57;  slog::Index** deltaindex58;  slog::Index** _enumindex59;  slog::Index** primindex60;  slog::Index** $seq_atrdelta61;  slog::Index** $seq_atrdelta62;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp50La972");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord64({1, 0, 2});
      slog::Relation* readrel65 = db->getRelation("$seq_at");
      driver_index = readrel65->getIndex(ord64, true);
      std::vector<u16> ord66({1, 0, 2});
      slog::Relation* readrel67 = db->getRelation("$seq_at");
      $seq_atindex54 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 0, 2});
      slog::Relation* readrel69 = db->getRelation("$seq_atr");
      $seq_atrindex55 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 0, 2});
      slog::Relation* readrel71 = db->getRelation("$seq_atr");
      $seq_atrdelta61 = readrel71->getIndex(ord70, true);
      std::vector<u16> ord72({1, 0, 2});
      slog::Relation* readrel73 = db->getRelation("$seq_atr");
      $seq_atrindex56 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({1, 0, 2});
      slog::Relation* readrel75 = db->getRelation("$seq_atr");
      $seq_atrdelta62 = readrel75->getIndex(ord74, true);
      std::vector<u16> ord76({1, 0});
      slog::Relation* readrel77 = db->getRelation("_enum");
      _enumindex57 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 2, 0});
      slog::Relation* readrel79 = db->getRelation("delta");
      deltaindex58 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 0});
      slog::Relation* readrel81 = db->getRelation("_enum");
      _enumindex59 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({0, 1});
      slog::Relation* readrel83 = db->getRelation("prim");
      primindex60 = readrel83->getIndex(ord82, false);
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c11 = v_const06abaa100ecef791ce028c56;
      u64 v_c12 = v_constd4735e3a265e16eee03f5971;
      u64 v_c13 = v_const5feceb66ffc86f38d952786c;
      u64 v_c14 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c15 = v_const5feceb66ffc86f38d952786c;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c17 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c16, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m84) {
        u64 v_c19 = m84[1];
        u64 v_c20 = m84[2];
        if (buckethash(v_c19) != bucket) return;
        slog::join_probe<3,3>($seq_atindex54, std::array<u64,3>{v_c15, v_c19, v_c20}, [&](const std::array<u64,3>& m85) {
          slog::join_probe_old<3,3>($seq_atrindex55, $seq_atrdelta61, std::array<u64,3>{v_c17, v_c19, v_c20}, [&](const std::array<u64,3>& m86) {
            slog::join_probe_old<3,3>($seq_atrindex56, $seq_atrdelta62, std::array<u64,3>{v_c18, v_c19, v_c20}, [&](const std::array<u64,3>& m87) {
              if (!slog::exists_probe<2,1>(_enumindex57, std::array<u64,2>{v_c10, 0})) return;
              slog::join_probe<3,2>(deltaindex58, std::array<u64,3>{v_c11, v_c20, 0}, [&](const std::array<u64,3>& m88) {
                u64 v_c21 = m88[2];
                slog::join_probe<2,1>(_enumindex59, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m89) {
                  u64 v_c22 = m89[1];
                  slog::join_probe<2,1>(primindex60, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m90) {
                    u64 v_c23 = m90[1];
                    bool ok91 = true;
                    u64 v_c24 = _prim_aslst(db, v_c20, &ok91);
                    if (!ok91) return;
                    u64 v_c25 = _prim_llen(db, v_c24);
                    if (v_c25 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c12 != v_c25) return;
                    bool ok92 = true;
                    u64 v_c26 = _prim_lref(db, v_c24, v_c13, &ok92);
                    if (!ok92) return;
                    if (v_c19 != v_c26) return;
                    bool ok93 = true;
                    u64 v_c27 = _prim_lref(db, v_c24, v_c14, &ok93);
                    if (!ok93) return;
                    if (v_c19 != v_c27) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c21});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask63* _cont = new ReadTask63(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask63(db,b), false);
  // (crule (pre) (scan temp8Oyq932 __t3TU6119 e) (body) (head (mkstruct eval (1 2 0) __7eGk618 e __t3TU6119)) interp.slog:129 #f)
  class ReadTask94 : public slog::Task
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
      outer_rel = db->getRelation("temp8Oyq932");
  
    }
    ReadTask94(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[0];
        u64 v_c29 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c29, v_c28}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:129", "delta:temp8Oyq932", _fires);
  
      if (!_done)
      {
        ReadTask94* _cont = new ReadTask94(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask94(db,b), false);
  // (crule (pre) (scan eval_ans __t7j91374 vr) (body (join-old eval (0 2 1) 1 (0 2 1) __t7j91374 c er) (exists let (2 1 3 0) 1 er) (exists eval (2 0 1) 1 c) (join-old $sup56712x91x0x0x0 (1 3 0 2 4) 2 (1 3 0 2 4) c er __t9U3N373 eb x) (exists eval (0 2 1) 2 __t9U3N373 c) (exists eval (1 2 0) 2 eb c) (join-old let (2 1 3 0) 3 (2 1 3 0) er x eb __t78XS372) (join-old eval (0 2 1) 3 (0 2 1) __t9U3N373 c __t78XS372) (join-old eval (1 2 0) 2 (1 2 0) eb c __t3KJV375) (join-old eval_ans (0 1) 1 (0 1) __t3KJV375 v)) (head (emit eval_ans (0 1) __t9U3N373 v)) interp.slog:92 #f)
  class ReadTask111 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex95;  slog::Index** letindex96;  slog::Index** evalindex97;  slog::Index** $sup56712x91x0x0x0index98;  slog::Index** evalindex99;  slog::Index** evalindex100;  slog::Index** letindex101;  slog::Index** evalindex102;  slog::Index** evalindex103;  slog::Index** eval_ansindex104;  slog::Index** evaldelta105;  slog::Index** $sup56712x91x0x0x0delta106;  slog::Index** letdelta107;  slog::Index** evaldelta108;  slog::Index** evaldelta109;  slog::Index** eval_ansdelta110;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord112({0, 1});
      slog::Relation* readrel113 = db->getRelation("eval_ans");
      head_index[0] = readrel113->getIndex(ord112, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord114({0, 2, 1});
      slog::Relation* readrel115 = db->getRelation("eval");
      evalindex95 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({0, 2, 1});
      slog::Relation* readrel117 = db->getRelation("eval");
      evaldelta105 = readrel117->getIndex(ord116, true);
      std::vector<u16> ord118({2, 1, 3, 0});
      slog::Relation* readrel119 = db->getRelation("let");
      letindex96 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({2, 0, 1});
      slog::Relation* readrel121 = db->getRelation("eval");
      evalindex97 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 3, 0, 2, 4});
      slog::Relation* readrel123 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0index98 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 3, 0, 2, 4});
      slog::Relation* readrel125 = db->getRelation("$sup56712x91x0x0x0");
      $sup56712x91x0x0x0delta106 = readrel125->getIndex(ord124, true);
      std::vector<u16> ord126({0, 2, 1});
      slog::Relation* readrel127 = db->getRelation("eval");
      evalindex99 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("eval");
      evalindex100 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({2, 1, 3, 0});
      slog::Relation* readrel131 = db->getRelation("let");
      letindex101 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({2, 1, 3, 0});
      slog::Relation* readrel133 = db->getRelation("let");
      letdelta107 = readrel133->getIndex(ord132, true);
      std::vector<u16> ord134({0, 2, 1});
      slog::Relation* readrel135 = db->getRelation("eval");
      evalindex102 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({0, 2, 1});
      slog::Relation* readrel137 = db->getRelation("eval");
      evaldelta108 = readrel137->getIndex(ord136, true);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("eval");
      evalindex103 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 0});
      slog::Relation* readrel141 = db->getRelation("eval");
      evaldelta109 = readrel141->getIndex(ord140, true);
      std::vector<u16> ord142({0, 1});
      slog::Relation* readrel143 = db->getRelation("eval_ans");
      eval_ansindex104 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({0, 1});
      slog::Relation* readrel145 = db->getRelation("eval_ans");
      eval_ansdelta110 = readrel145->getIndex(ord144, true);
  
    }
    ReadTask111(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[1];
        slog::join_probe_old<3,1>(evalindex95, evaldelta105, std::array<u64,3>{v_c8, 0, 0}, [&](const std::array<u64,3>& m146) {
          u64 v_c2 = m146[1]; u64 v_c5 = m146[2];
          if (!slog::exists_probe<4,1>(letindex96, std::array<u64,4>{v_c5, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex97, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x91x0x0x0index98, $sup56712x91x0x0x0delta106, std::array<u64,5>{v_c2, v_c5, 0, 0, 0}, [&](const std::array<u64,5>& m147) {
            u64 v_c4 = m147[2]; u64 v_c3 = m147[3]; u64 v_c6 = m147[4];
            if (!slog::exists_probe<3,2>(evalindex99, std::array<u64,3>{v_c4, v_c2, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex100, std::array<u64,3>{v_c3, v_c2, 0})) return;
            slog::join_probe_old<4,3>(letindex101, letdelta107, std::array<u64,4>{v_c5, v_c6, v_c3, 0}, [&](const std::array<u64,4>& m148) {
              u64 v_c7 = m148[3];
              slog::join_probe_old<3,3>(evalindex102, evaldelta108, std::array<u64,3>{v_c4, v_c2, v_c7}, [&](const std::array<u64,3>& m149) {
                slog::join_probe_old<3,2>(evalindex103, evaldelta109, std::array<u64,3>{v_c3, v_c2, 0}, [&](const std::array<u64,3>& m150) {
                  u64 v_c0 = m150[2];
                  slog::join_probe_old<2,1>(eval_ansindex104, eval_ansdelta110, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m151) {
                    u64 v_c1 = m151[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c1}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask111* _cont = new ReadTask111(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask111(db,b), false);
  // (crule (pre (let _00024sqc9r51426 const6b86b273ff34fce19d6b804e) (let _00024sqc0a7Y427 const5feceb66ffc86f38d952786c) (let _00024sqc6lAT428 const6b86b273ff34fce19d6b804e) (let _00024sqc6zTj429 const5feceb66ffc86f38d952786c) (let _00024sqo7QcU434 const5feceb66ffc86f38d952786c) (let __t31sY376 (lempty))) (scan eval_ans __t33Oa380 __v0) (body (exists $seq_at (1 0 2) 1 _00024sqo7QcU434) (join-old eval (0 2 1) 1 (0 2 1) __t33Oa380 c e) (exists $sup56712x37x0x0x0 (2 3 0 1 4) 2 c e) (exists eval_args (2 0 1) 1 c) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo7QcU434 e _00024seq0) (letp _00024sql0xMp424 (aslst _00024seq0)) (let _00024sqn1MBN425 (llen _00024sql0xMp424)) (cmp ge _00024sqn1MBN425 _00024sqc9r51426) (let _00024sqp04Wv430 (_0002d _00024sqn1MBN425 _00024sqc6zTj429)) (let es (lslice _00024sql0xMp424 _00024sqc6lAT428 _00024sqp04Wv430)) (exists eval_args (1 2 0) 2 _00024seq0 c) (exists eval_args (1 2 0) 2 es c) (join-old $sup56712x37x0x0x0 (0 3 4 2 1) 4 (0 3 4 2 1) _00024seq0 e es c __t1ye1379) (join-old eval_args (0 2 1) 3 (0 2 1) __t1ye1379 c _00024seq0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5lLk381) (join-old eval_args_ans (0 1) 1 (0 1) __t5lLk381 __v1) (letp chk70tH936 (lref _00024sql0xMp424 _00024sqc0a7Y427)) (eq e chk70tH936)) (head (emit-temp temp0JGK933 __t1ye1379 __t31sY376 __v0 __v1)) interp.slog:38 #f)
  class ReadTask169 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex152;  slog::Index** evalindex153;  slog::Index** $sup56712x37x0x0x0index154;  slog::Index** eval_argsindex155;  slog::Index** $seq_atindex156;  slog::Index** eval_argsindex157;  slog::Index** eval_argsindex158;  slog::Index** $sup56712x37x0x0x0index159;  slog::Index** eval_argsindex160;  slog::Index** eval_argsindex161;  slog::Index** eval_args_ansindex162;  slog::Index** evaldelta163;  slog::Index** $seq_atdelta164;  slog::Index** $sup56712x37x0x0x0delta165;  slog::Index** eval_argsdelta166;  slog::Index** eval_argsdelta167;  slog::Index** eval_args_ansdelta168;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0JGK933");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord170({1, 0, 2});
      slog::Relation* readrel171 = db->getRelation("$seq_at");
      $seq_atindex152 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({0, 2, 1});
      slog::Relation* readrel173 = db->getRelation("eval");
      evalindex153 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({0, 2, 1});
      slog::Relation* readrel175 = db->getRelation("eval");
      evaldelta163 = readrel175->getIndex(ord174, true);
      std::vector<u16> ord176({2, 3, 0, 1, 4});
      slog::Relation* readrel177 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index154 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({2, 0, 1});
      slog::Relation* readrel179 = db->getRelation("eval_args");
      eval_argsindex155 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 0, 2});
      slog::Relation* readrel181 = db->getRelation("$seq_at");
      $seq_atindex156 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({1, 0, 2});
      slog::Relation* readrel183 = db->getRelation("$seq_at");
      $seq_atdelta164 = readrel183->getIndex(ord182, true);
      std::vector<u16> ord184({1, 2, 0});
      slog::Relation* readrel185 = db->getRelation("eval_args");
      eval_argsindex157 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 2, 0});
      slog::Relation* readrel187 = db->getRelation("eval_args");
      eval_argsindex158 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({0, 3, 4, 2, 1});
      slog::Relation* readrel189 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index159 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({0, 3, 4, 2, 1});
      slog::Relation* readrel191 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0delta165 = readrel191->getIndex(ord190, true);
      std::vector<u16> ord192({0, 2, 1});
      slog::Relation* readrel193 = db->getRelation("eval_args");
      eval_argsindex160 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 2, 1});
      slog::Relation* readrel195 = db->getRelation("eval_args");
      eval_argsdelta166 = readrel195->getIndex(ord194, true);
      std::vector<u16> ord196({1, 2, 0});
      slog::Relation* readrel197 = db->getRelation("eval_args");
      eval_argsindex161 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({1, 2, 0});
      slog::Relation* readrel199 = db->getRelation("eval_args");
      eval_argsdelta167 = readrel199->getIndex(ord198, true);
      std::vector<u16> ord200({0, 1});
      slog::Relation* readrel201 = db->getRelation("eval_args_ans");
      eval_args_ansindex162 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({0, 1});
      slog::Relation* readrel203 = db->getRelation("eval_args_ans");
      eval_args_ansdelta168 = readrel203->getIndex(ord202, true);
  
    }
    ReadTask169(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_const5feceb66ffc86f38d952786c;
      u64 v_c34 = v_const5feceb66ffc86f38d952786c;
      u64 v_c35 = _prim_lempty(db);
      if (v_c35 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c36 = _t[0];
        u64 v_c37 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex152, std::array<u64,3>{v_c34, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex153, evaldelta163, std::array<u64,3>{v_c36, 0, 0}, [&](const std::array<u64,3>& m204) {
          u64 v_c2 = m204[1]; u64 v_c29 = m204[2];
          if (!slog::exists_probe<5,2>($sup56712x37x0x0x0index154, std::array<u64,5>{v_c2, v_c29, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex155, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<3,2>($seq_atindex156, $seq_atdelta164, std::array<u64,3>{v_c34, v_c29, 0}, [&](const std::array<u64,3>& m205) {
            u64 v_c38 = m205[2];
            bool ok206 = true;
            u64 v_c39 = _prim_aslst(db, v_c38, &ok206);
            if (!ok206) return;
            u64 v_c40 = _prim_llen(db, v_c39);
            if (v_c40 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
            u64 v_c41 = _prim_ge(db, v_c40, v_c30);
            if (v_c41 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
            if (!v_c41) return;
            u64 v_c42 = _prim__0002d(db, v_c40, v_c33);
            if (v_c42 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
            u64 v_c43 = _prim_lslice(db, v_c39, v_c32, v_c42);
            if (v_c43 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
            if (!slog::exists_probe<3,2>(eval_argsindex157, std::array<u64,3>{v_c38, v_c2, 0})) return;
            if (!slog::exists_probe<3,2>(eval_argsindex158, std::array<u64,3>{v_c43, v_c2, 0})) return;
            slog::join_probe_old<5,4>($sup56712x37x0x0x0index159, $sup56712x37x0x0x0delta165, std::array<u64,5>{v_c38, v_c29, v_c43, v_c2, 0}, [&](const std::array<u64,5>& m208) {
              u64 v_c44 = m208[4];
              slog::join_probe_old<3,3>(eval_argsindex160, eval_argsdelta166, std::array<u64,3>{v_c44, v_c2, v_c38}, [&](const std::array<u64,3>& m209) {
                slog::join_probe_old<3,2>(eval_argsindex161, eval_argsdelta167, std::array<u64,3>{v_c43, v_c2, 0}, [&](const std::array<u64,3>& m210) {
                  u64 v_c45 = m210[2];
                  slog::join_probe_old<2,1>(eval_args_ansindex162, eval_args_ansdelta168, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m211) {
                    u64 v_c46 = m211[1];
                    bool ok212 = true;
                    u64 v_c47 = _prim_lref(db, v_c39, v_c31, &ok212);
                    if (!ok212) return;
                    if (v_c29 != v_c47) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c44, v_c35, v_c37, v_c46});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:38", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask169* _cont = new ReadTask169(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask169(db,b), false);
  // (crule (pre) (scan eval __t9ATC44 e1 c) (body (exists if (1 0 2 3) 1 e1) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t9ATC44) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __t7yOw43 e2 e3) (exists eval (0 2 1) 2 __t7yOw43 c) (exists select_branch (2 3 0 1) 2 e2 e3) (join if (2 3 1 0) 3 e2 e3 e1 __t3ePt42) (join eval (0 2 1) 3 __t7yOw43 c __t3ePt42) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t5q6W45 __v0) (join eval_ans (0 1) 2 __t9ATC44 __v0) (join select_branch_ans (0 1) 1 __t5q6W45 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t4U4F46) (join eval_ans (0 1) 1 __t4U4F46 __v2)) (head (emit eval_ans (0 1) __t7yOw43 __v2)) interp.slog:87 #f)
  class ReadTask228 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex213;  slog::Index** evalindex214;  slog::Index** eval_ansindex215;  slog::Index** $sup56712x86x0x0x0index216;  slog::Index** evalindex217;  slog::Index** select_branchindex218;  slog::Index** ifindex219;  slog::Index** evalindex220;  slog::Index** select_branchindex221;  slog::Index** eval_ansindex222;  slog::Index** select_branch_ansindex223;  slog::Index** evalindex224;  slog::Index** eval_ansindex225;  slog::Index** select_branchdelta226;  slog::Index** evaldelta227;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord229({0, 1});
      slog::Relation* readrel230 = db->getRelation("eval_ans");
      head_index[0] = readrel230->getIndex(ord229, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord231({1, 0, 2, 3});
      slog::Relation* readrel232 = db->getRelation("if");
      ifindex213 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({2, 0, 1});
      slog::Relation* readrel234 = db->getRelation("eval");
      evalindex214 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 1});
      slog::Relation* readrel236 = db->getRelation("eval_ans");
      eval_ansindex215 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 0, 3, 4});
      slog::Relation* readrel238 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index216 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({0, 2, 1});
      slog::Relation* readrel240 = db->getRelation("eval");
      evalindex217 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({2, 3, 0, 1});
      slog::Relation* readrel242 = db->getRelation("select_branch");
      select_branchindex218 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({2, 3, 1, 0});
      slog::Relation* readrel244 = db->getRelation("if");
      ifindex219 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({0, 2, 1});
      slog::Relation* readrel246 = db->getRelation("eval");
      evalindex220 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({2, 3, 0, 1});
      slog::Relation* readrel248 = db->getRelation("select_branch");
      select_branchindex221 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({2, 3, 0, 1});
      slog::Relation* readrel250 = db->getRelation("select_branch");
      select_branchdelta226 = readrel250->getIndex(ord249, true);
      std::vector<u16> ord251({0, 1});
      slog::Relation* readrel252 = db->getRelation("eval_ans");
      eval_ansindex222 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({0, 1});
      slog::Relation* readrel254 = db->getRelation("select_branch_ans");
      select_branch_ansindex223 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({1, 2, 0});
      slog::Relation* readrel256 = db->getRelation("eval");
      evalindex224 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 2, 0});
      slog::Relation* readrel258 = db->getRelation("eval");
      evaldelta227 = readrel258->getIndex(ord257, true);
      std::vector<u16> ord259({0, 1});
      slog::Relation* readrel260 = db->getRelation("eval_ans");
      eval_ansindex225 = readrel260->getIndex(ord259, false);
  
    }
    ReadTask228(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<4,1>(ifindex213, std::array<u64,4>{v_c49, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex214, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex215, std::array<u64,2>{v_c48, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index216, std::array<u64,5>{v_c2, v_c49, 0, 0, 0}, [&](const std::array<u64,5>& m261) {
          u64 v_c50 = m261[2]; u64 v_c51 = m261[3]; u64 v_c52 = m261[4];
          if (!slog::exists_probe<3,2>(evalindex217, std::array<u64,3>{v_c50, v_c2, 0})) return;
          if (!slog::exists_probe<4,2>(select_branchindex218, std::array<u64,4>{v_c51, v_c52, 0, 0})) return;
          slog::join_probe<4,3>(ifindex219, std::array<u64,4>{v_c51, v_c52, v_c49, 0}, [&](const std::array<u64,4>& m262) {
            u64 v_c53 = m262[3];
            slog::join_probe<3,3>(evalindex220, std::array<u64,3>{v_c50, v_c2, v_c53}, [&](const std::array<u64,3>& m263) {
              slog::join_probe_old<4,2>(select_branchindex221, select_branchdelta226, std::array<u64,4>{v_c51, v_c52, 0, 0}, [&](const std::array<u64,4>& m264) {
                u64 v_c54 = m264[2]; u64 v_c37 = m264[3];
                slog::join_probe<2,2>(eval_ansindex222, std::array<u64,2>{v_c48, v_c37}, [&](const std::array<u64,2>& m265) {
                  slog::join_probe<2,1>(select_branch_ansindex223, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m266) {
                    u64 v_c46 = m266[1];
                    slog::join_probe_old<3,2>(evalindex224, evaldelta227, std::array<u64,3>{v_c46, v_c2, 0}, [&](const std::array<u64,3>& m267) {
                      u64 v_c55 = m267[2];
                      slog::join_probe<2,1>(eval_ansindex225, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m268) {
                        u64 v_c56 = m268[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c56}, std::array<u16,2>{0, 1});
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
        ReadTask228* _cont = new ReadTask228(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask228(db,b), false);
  // (crule (pre (let __tconst2fdM633 constcd2a69ce5ca278db1d6da969) (let _00024sqc7LFn532 constd4735e3a265e16eee03f5971) (let _00024sqc3SHd533 const5feceb66ffc86f38d952786c) (let _00024sqc4CLM534 const6b86b273ff34fce19d6b804e) (let _00024sqo90j9535 const5feceb66ffc86f38d952786c) (let _00024sqo88rK536 const6b86b273ff34fce19d6b804e) (let _00024sqo1A9y537 const6b86b273ff34fce19d6b804e) (let _00024sqo2hWF538 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo88rK536 __t26Zq339 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo90j9535 __t26Zq339 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1A9y537 __t26Zq339 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2hWF538 __t26Zq339 _00024seq2) (join _enum (0 1) 2 __t26Zq339 __tconst2fdM633) (join delta (2 0 1) 1 _00024seq2 __t1IV0337 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql96G9530 (aslst _00024seq2)) (let chk530a951 (llen _00024sql96G9530)) (eq _00024sqc7LFn532 chk530a951) (letp chk0HgA952 (lref _00024sql96G9530 _00024sqc3SHd533)) (eq __t26Zq339 chk0HgA952) (letp chk2j5J953 (lref _00024sql96G9530 _00024sqc4CLM534)) (eq __t26Zq339 chk2j5J953)) (head (emit-temp temp5ZiW945 __t1IV0337 b) (mkstruct boolval (1 0) __t4qAo336 b)) interp.slog:112 #f)
  class ReadTask278 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex269;  slog::Index** $seq_atrindex270;  slog::Index** $seq_atrindex271;  slog::Index** _enumindex272;  slog::Index** deltaindex273;  slog::Index** comparison_opindex274;  slog::Index** any_boolindex275;  slog::Index** $seq_atrdelta276;  slog::Index** $seq_atrdelta277;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5ZiW945");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord279({1, 0, 2});
      slog::Relation* readrel280 = db->getRelation("$seq_at");
      driver_index = readrel280->getIndex(ord279, true);
      std::vector<u16> ord281({1, 0, 2});
      slog::Relation* readrel282 = db->getRelation("$seq_at");
      $seq_atindex269 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 0, 2});
      slog::Relation* readrel284 = db->getRelation("$seq_atr");
      $seq_atrindex270 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({1, 0, 2});
      slog::Relation* readrel286 = db->getRelation("$seq_atr");
      $seq_atrdelta276 = readrel286->getIndex(ord285, true);
      std::vector<u16> ord287({1, 0, 2});
      slog::Relation* readrel288 = db->getRelation("$seq_atr");
      $seq_atrindex271 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 0, 2});
      slog::Relation* readrel290 = db->getRelation("$seq_atr");
      $seq_atrdelta277 = readrel290->getIndex(ord289, true);
      std::vector<u16> ord291({0, 1});
      slog::Relation* readrel292 = db->getRelation("_enum");
      _enumindex272 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({2, 0, 1});
      slog::Relation* readrel294 = db->getRelation("delta");
      deltaindex273 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({0});
      slog::Relation* readrel296 = db->getRelation("comparison_op");
      comparison_opindex274 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({0});
      slog::Relation* readrel298 = db->getRelation("any_bool");
      any_boolindex275 = readrel298->getIndex(ord297, false);
  
    }
    ReadTask278(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c58 = v_constd4735e3a265e16eee03f5971;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const5feceb66ffc86f38d952786c;
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c63 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c64 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c62, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m299) {
        u64 v_c65 = m299[1];
        u64 v_c20 = m299[2];
        if (buckethash(v_c65) != bucket) return;
        slog::join_probe<3,3>($seq_atindex269, std::array<u64,3>{v_c61, v_c65, v_c20}, [&](const std::array<u64,3>& m300) {
          slog::join_probe_old<3,3>($seq_atrindex270, $seq_atrdelta276, std::array<u64,3>{v_c63, v_c65, v_c20}, [&](const std::array<u64,3>& m301) {
            slog::join_probe_old<3,3>($seq_atrindex271, $seq_atrdelta277, std::array<u64,3>{v_c64, v_c65, v_c20}, [&](const std::array<u64,3>& m302) {
              slog::join_probe<2,2>(_enumindex272, std::array<u64,2>{v_c65, v_c57}, [&](const std::array<u64,2>& m303) {
                slog::join_probe<3,1>(deltaindex273, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m304) {
                  u64 v_c66 = m304[1]; u64 v_c23 = m304[2];
                  slog::join_probe<1,1>(comparison_opindex274, std::array<u64,1>{v_c23}, [&](const std::array<u64,1>& m305) {
                    slog::join_all<1>(any_boolindex275, [&](const std::array<u64,1>& m306) {
                      u64 v_c67 = m306[0];
                      bool ok307 = true;
                      u64 v_c68 = _prim_aslst(db, v_c20, &ok307);
                      if (!ok307) return;
                      u64 v_c69 = _prim_llen(db, v_c68);
                      if (v_c69 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c58 != v_c69) return;
                      bool ok308 = true;
                      u64 v_c70 = _prim_lref(db, v_c68, v_c59, &ok308);
                      if (!ok308) return;
                      if (v_c65 != v_c70) return;
                      bool ok309 = true;
                      u64 v_c71 = _prim_lref(db, v_c68, v_c60, &ok309);
                      if (!ok309) return;
                      if (v_c65 != v_c71) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c66, v_c67});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c67}, std::array<u16,2>{1, 0});
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
        ReadTask278* _cont = new ReadTask278(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask278(db,b), false);
  // (crule (pre) (scan delta __t3FWR391 op vs) (body (exists delta_ans (0 1) 1 __t3FWR391) (exists prim (1 0) 1 op) (join eval_args_ans (1 0) 1 vs __t4aOO390) (join delta_ans (0 1) 1 __t3FWR391 v) (join prim (1 0) 1 op __t22Li389) (join eval_ans (1 0) 1 __t22Li389 __t9EYC388) (join eval (0 2 1) 1 __t9EYC388 c ef) (exists $sup56712x74x0x0x0 (1 2 3 0) 2 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval_args (0 2 1) 2 __t4aOO390 c es) (exists app (1 2 0) 2 ef es) (join $sup56712x74x0x0x0 (1 2 3 0) 3 c ef es __t0zOO387) (exists eval (0 2 1) 2 __t0zOO387 c) (join app (1 2 0) 2 ef es __t2JOw386) (join eval (0 2 1) 3 __t0zOO387 c __t2JOw386)) (head (emit eval_ans (0 1) __t0zOO387 v)) interp.slog:75 #f)
  class ReadTask326 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** delta_ansindex310;  slog::Index** primindex311;  slog::Index** eval_args_ansindex312;  slog::Index** delta_ansindex313;  slog::Index** primindex314;  slog::Index** eval_ansindex315;  slog::Index** evalindex316;  slog::Index** $sup56712x74x0x0x0index317;  slog::Index** appindex318;  slog::Index** evalindex319;  slog::Index** eval_argsindex320;  slog::Index** appindex321;  slog::Index** $sup56712x74x0x0x0index322;  slog::Index** evalindex323;  slog::Index** appindex324;  slog::Index** evalindex325;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord327({0, 1});
      slog::Relation* readrel328 = db->getRelation("eval_ans");
      head_index[0] = readrel328->getIndex(ord327, false);
      outer_rel = db->getRelation("delta");
      std::vector<u16> ord329({0, 1});
      slog::Relation* readrel330 = db->getRelation("delta_ans");
      delta_ansindex310 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 0});
      slog::Relation* readrel332 = db->getRelation("prim");
      primindex311 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 0});
      slog::Relation* readrel334 = db->getRelation("eval_args_ans");
      eval_args_ansindex312 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({0, 1});
      slog::Relation* readrel336 = db->getRelation("delta_ans");
      delta_ansindex313 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({1, 0});
      slog::Relation* readrel338 = db->getRelation("prim");
      primindex314 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 0});
      slog::Relation* readrel340 = db->getRelation("eval_ans");
      eval_ansindex315 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({0, 2, 1});
      slog::Relation* readrel342 = db->getRelation("eval");
      evalindex316 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 3, 0});
      slog::Relation* readrel344 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index317 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 2, 0});
      slog::Relation* readrel346 = db->getRelation("app");
      appindex318 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({2, 0, 1});
      slog::Relation* readrel348 = db->getRelation("eval");
      evalindex319 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({0, 2, 1});
      slog::Relation* readrel350 = db->getRelation("eval_args");
      eval_argsindex320 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("app");
      appindex321 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 3, 0});
      slog::Relation* readrel354 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index322 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({0, 2, 1});
      slog::Relation* readrel356 = db->getRelation("eval");
      evalindex323 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({1, 2, 0});
      slog::Relation* readrel358 = db->getRelation("app");
      appindex324 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({0, 2, 1});
      slog::Relation* readrel360 = db->getRelation("eval");
      evalindex325 = readrel360->getIndex(ord359, false);
  
    }
    ReadTask326(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[1];
        u64 v_c73 = _t[2];
        if (!slog::exists_probe<2,1>(delta_ansindex310, std::array<u64,2>{v_c72, 0})) return;
        if (!slog::exists_probe<2,1>(primindex311, std::array<u64,2>{v_c23, 0})) return;
        slog::join_probe<2,1>(eval_args_ansindex312, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m361) {
          u64 v_c74 = m361[1];
          slog::join_probe<2,1>(delta_ansindex313, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m362) {
            u64 v_c1 = m362[1];
            slog::join_probe<2,1>(primindex314, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m363) {
              u64 v_c75 = m363[1];
              slog::join_probe<2,1>(eval_ansindex315, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m364) {
                u64 v_c76 = m364[1];
                slog::join_probe<3,1>(evalindex316, std::array<u64,3>{v_c76, 0, 0}, [&](const std::array<u64,3>& m365) {
                  u64 v_c2 = m365[1]; u64 v_c77 = m365[2];
                  if (!slog::exists_probe<4,2>($sup56712x74x0x0x0index317, std::array<u64,4>{v_c2, v_c77, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(appindex318, std::array<u64,3>{v_c77, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(evalindex319, std::array<u64,3>{v_c2, 0, 0})) return;
                  slog::join_probe<3,2>(eval_argsindex320, std::array<u64,3>{v_c74, v_c2, 0}, [&](const std::array<u64,3>& m366) {
                    u64 v_c43 = m366[2];
                    if (!slog::exists_probe<3,2>(appindex321, std::array<u64,3>{v_c77, v_c43, 0})) return;
                    slog::join_probe<4,3>($sup56712x74x0x0x0index322, std::array<u64,4>{v_c2, v_c77, v_c43, 0}, [&](const std::array<u64,4>& m367) {
                      u64 v_c78 = m367[3];
                      if (!slog::exists_probe<3,2>(evalindex323, std::array<u64,3>{v_c78, v_c2, 0})) return;
                      slog::join_probe<3,2>(appindex324, std::array<u64,3>{v_c77, v_c43, 0}, [&](const std::array<u64,3>& m368) {
                        u64 v_c79 = m368[2];
                        slog::join_probe<3,3>(evalindex325, std::array<u64,3>{v_c78, v_c2, v_c79}, [&](const std::array<u64,3>& m369) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c78, v_c1}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask326* _cont = new ReadTask326(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask326(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst39ZW253 const8ca5d81566f88badd698137a) (let __tconst6YSZ252 const8c8656c5d114d7f8b2a412d2) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715) (let __tconst2I8h285 const7297d2085ea0adffc396d546) (let __tconst4QwH278 const6b86b273ff34fce19d6b804e) (let __tconst48zw269 const0933fb667296882d8c45abca) (let __tconst16Fs254 const879923da020d1533f4d8e921) (let __tconst7F8v233 const53a56174f3826669a422fc54) (let __tconst85km226 constd4735e3a265e16eee03f5971)) (scan temp9PWx961 __t3DyN290 __t4Zol274 __t5yWE289 __t6N9H267 __t6vXM283 __t7YhR256 __t7rKO231 __t9tnf218) (body (exists ref (1 0) 1 __tconst2XD5276) (exists ref (1 0) 1 __tconst7wlx292) (exists num (1 0) 1 __tconst85km226) (exists num (1 0) 1 __tconst4QwH278) (exists ref (1 0) 1 __tconst7F8v233) (exists ref (1 0) 1 __tconst4aTz260) (exists ref (1 0) 1 __tconst6YSZ252) (exists ref (1 0) 1 __tconst39ZW253) (exists ref (1 0) 1 __tconst16Fs254) (exists ref (1 0) 1 __tconst48zw269) (exists ref (1 0) 1 __tconst2I8h285) (join ref (1 0) 1 __tconst7Bar243 __t8Ely220) (join ref (1 0) 1 __tconst2XD5276 __t55Yd223) (join ref (1 0) 1 __tconst7wlx292 __t1iN7225) (join num (1 0) 1 __tconst85km226 __t7w2Z227) (join num (1 0) 1 __tconst4QwH278 __t3YP0229) (join ref (1 0) 1 __tconst7F8v233 __t3grR234) (join ref (1 0) 1 __tconst4aTz260 __t41cT241) (join ref (1 0) 1 __tconst6YSZ252 __t7SX3246) (exists if (3 0 1 2) 1 __t7SX3246) (join ref (1 0) 1 __tconst39ZW253 __t1waL248) (join if (2 3 1 0) 2 __t1waL248 __t7SX3246 __t54jO250 __t4Qs4251) (join ref (0 1) 2 __t54jO250 __tconst16Fs254) (join ref (1 0) 1 __tconst48zw269 __t7uwu270) (join ref (1 0) 1 __tconst2I8h285 __t5wDB286) (let __t5xQ3284 (lpush __t6vXM283 __t3YP0229)) (let __t41Z9268 (lpush __t6N9H267 __t3YP0229)) (let __t4xcV257 (lpush __t7YhR256 __tconst39ZW253)) (let __t1sga232 (lpush __t7rKO231 __t7w2Z227))) (head (emit-temp temp4QGA962 __t1sga232 __t3DyN290 __t41Z9268 __t4Zol274 __t4xcV257 __t5xQ3284 __t5yWE289 __t9tnf218) (mkstruct app (1 2 0) __t9Hvd221 __t8Ely220 __t9tnf218)) analysis-demo.slog:21 #f)
  class ReadTask395 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex370;  slog::Index** refindex371;  slog::Index** numindex372;  slog::Index** numindex373;  slog::Index** refindex374;  slog::Index** refindex375;  slog::Index** refindex376;  slog::Index** refindex377;  slog::Index** refindex378;  slog::Index** refindex379;  slog::Index** refindex380;  slog::Index** refindex381;  slog::Index** refindex382;  slog::Index** refindex383;  slog::Index** numindex384;  slog::Index** numindex385;  slog::Index** refindex386;  slog::Index** refindex387;  slog::Index** refindex388;  slog::Index** ifindex389;  slog::Index** refindex390;  slog::Index** ifindex391;  slog::Index** refindex392;  slog::Index** refindex393;  slog::Index** refindex394;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4QGA962");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp9PWx961");
      std::vector<u16> ord396({1, 0});
      slog::Relation* readrel397 = db->getRelation("ref");
      refindex370 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 0});
      slog::Relation* readrel399 = db->getRelation("ref");
      refindex371 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 0});
      slog::Relation* readrel401 = db->getRelation("num");
      numindex372 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 0});
      slog::Relation* readrel403 = db->getRelation("num");
      numindex373 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 0});
      slog::Relation* readrel405 = db->getRelation("ref");
      refindex374 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 0});
      slog::Relation* readrel407 = db->getRelation("ref");
      refindex375 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 0});
      slog::Relation* readrel409 = db->getRelation("ref");
      refindex376 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({1, 0});
      slog::Relation* readrel411 = db->getRelation("ref");
      refindex377 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 0});
      slog::Relation* readrel413 = db->getRelation("ref");
      refindex378 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 0});
      slog::Relation* readrel415 = db->getRelation("ref");
      refindex379 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 0});
      slog::Relation* readrel417 = db->getRelation("ref");
      refindex380 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 0});
      slog::Relation* readrel419 = db->getRelation("ref");
      refindex381 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 0});
      slog::Relation* readrel421 = db->getRelation("ref");
      refindex382 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 0});
      slog::Relation* readrel423 = db->getRelation("ref");
      refindex383 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 0});
      slog::Relation* readrel425 = db->getRelation("num");
      numindex384 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 0});
      slog::Relation* readrel427 = db->getRelation("num");
      numindex385 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 0});
      slog::Relation* readrel429 = db->getRelation("ref");
      refindex386 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({1, 0});
      slog::Relation* readrel431 = db->getRelation("ref");
      refindex387 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({1, 0});
      slog::Relation* readrel433 = db->getRelation("ref");
      refindex388 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({3, 0, 1, 2});
      slog::Relation* readrel435 = db->getRelation("if");
      ifindex389 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 0});
      slog::Relation* readrel437 = db->getRelation("ref");
      refindex390 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({2, 3, 1, 0});
      slog::Relation* readrel439 = db->getRelation("if");
      ifindex391 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({0, 1});
      slog::Relation* readrel441 = db->getRelation("ref");
      refindex392 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({1, 0});
      slog::Relation* readrel443 = db->getRelation("ref");
      refindex393 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({1, 0});
      slog::Relation* readrel445 = db->getRelation("ref");
      refindex394 = readrel445->getIndex(ord444, false);
  
    }
    ReadTask395(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c80 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c81 = v_constf77801bebb40767a1b303d97;
      u64 v_c82 = v_const829935b42173b360da35f679;
      u64 v_c83 = v_const8ca5d81566f88badd698137a;
      u64 v_c84 = v_const8c8656c5d114d7f8b2a412d2;
      u64 v_c85 = v_const0388ead47e9d5ccfc5320715;
      u64 v_c86 = v_const7297d2085ea0adffc396d546;
      u64 v_c87 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c88 = v_const0933fb667296882d8c45abca;
      u64 v_c89 = v_const879923da020d1533f4d8e921;
      u64 v_c90 = v_const53a56174f3826669a422fc54;
      u64 v_c91 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c95 = _t[3];
        u64 v_c96 = _t[4];
        u64 v_c97 = _t[5];
        u64 v_c98 = _t[6];
        u64 v_c99 = _t[7];
        if (!slog::exists_probe<2,1>(refindex370, std::array<u64,2>{v_c81, 0})) return;
        if (!slog::exists_probe<2,1>(refindex371, std::array<u64,2>{v_c80, 0})) return;
        if (!slog::exists_probe<2,1>(numindex372, std::array<u64,2>{v_c91, 0})) return;
        if (!slog::exists_probe<2,1>(numindex373, std::array<u64,2>{v_c87, 0})) return;
        if (!slog::exists_probe<2,1>(refindex374, std::array<u64,2>{v_c90, 0})) return;
        if (!slog::exists_probe<2,1>(refindex375, std::array<u64,2>{v_c82, 0})) return;
        if (!slog::exists_probe<2,1>(refindex376, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<2,1>(refindex377, std::array<u64,2>{v_c83, 0})) return;
        if (!slog::exists_probe<2,1>(refindex378, std::array<u64,2>{v_c89, 0})) return;
        if (!slog::exists_probe<2,1>(refindex379, std::array<u64,2>{v_c88, 0})) return;
        if (!slog::exists_probe<2,1>(refindex380, std::array<u64,2>{v_c86, 0})) return;
        slog::join_probe<2,1>(refindex381, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m446) {
          u64 v_c100 = m446[1];
          slog::join_probe<2,1>(refindex382, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m447) {
            u64 v_c101 = m447[1];
            slog::join_probe<2,1>(refindex383, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m448) {
              u64 v_c102 = m448[1];
              slog::join_probe<2,1>(numindex384, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m449) {
                u64 v_c103 = m449[1];
                slog::join_probe<2,1>(numindex385, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m450) {
                  u64 v_c104 = m450[1];
                  slog::join_probe<2,1>(refindex386, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m451) {
                    u64 v_c105 = m451[1];
                    slog::join_probe<2,1>(refindex387, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m452) {
                      u64 v_c106 = m452[1];
                      slog::join_probe<2,1>(refindex388, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m453) {
                        u64 v_c107 = m453[1];
                        if (!slog::exists_probe<4,1>(ifindex389, std::array<u64,4>{v_c107, 0, 0, 0})) return;
                        slog::join_probe<2,1>(refindex390, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m454) {
                          u64 v_c108 = m454[1];
                          slog::join_probe<4,2>(ifindex391, std::array<u64,4>{v_c108, v_c107, 0, 0}, [&](const std::array<u64,4>& m455) {
                            u64 v_c109 = m455[2]; u64 v_c110 = m455[3];
                            slog::join_probe<2,2>(refindex392, std::array<u64,2>{v_c109, v_c89}, [&](const std::array<u64,2>& m456) {
                              slog::join_probe<2,1>(refindex393, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m457) {
                                u64 v_c111 = m457[1];
                                slog::join_probe<2,1>(refindex394, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m458) {
                                  u64 v_c112 = m458[1];
                                  u64 v_c113 = _prim_lpush(db, v_c96, v_c104);
                                  if (v_c113 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                  u64 v_c114 = _prim_lpush(db, v_c95, v_c104);
                                  if (v_c114 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                  u64 v_c115 = _prim_lpush(db, v_c97, v_c83);
                                  if (v_c115 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                  u64 v_c116 = _prim_lpush(db, v_c98, v_c103);
                                  if (v_c116 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                  ++_fires;
                                  slog::emit_temp<8>(head_rel[0], newbatch[0], std::array<u64,8>{v_c116, v_c92, v_c114, v_c93, v_c115, v_c113, v_c94, v_c99});
                                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c100, v_c99}, std::array<u16,3>{1, 2, 0});
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
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp9PWx961", _fires);
  
      if (!_done)
      {
        ReadTask395* _cont = new ReadTask395(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask395(db,b), false);
  // (crule (pre) (scan prim __t68RF333 op) (body (join eval_ans (1 0) 1 __t68RF333 __t3Egw332) (join eval (0 2 1) 1 __t3Egw332 c ef) (exists eval_args (2 0 1) 1 c) (join $sup56712x74x0x0x0 (1 2 3 0) 2 c ef es __d0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t2Zls334) (join eval_args_ans (0 1) 1 __t2Zls334 vs)) (head (mkstruct delta (1 2 0) __5JOh701 op vs)) interp.slog:75 #f)
  class ReadTask466 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex459;  slog::Index** evalindex460;  slog::Index** eval_argsindex461;  slog::Index** $sup56712x74x0x0x0index462;  slog::Index** eval_argsindex463;  slog::Index** eval_args_ansindex464;  slog::Index** eval_argsdelta465;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("prim");
      std::vector<u16> ord467({1, 0});
      slog::Relation* readrel468 = db->getRelation("eval_ans");
      eval_ansindex459 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({0, 2, 1});
      slog::Relation* readrel470 = db->getRelation("eval");
      evalindex460 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({2, 0, 1});
      slog::Relation* readrel472 = db->getRelation("eval_args");
      eval_argsindex461 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 2, 3, 0});
      slog::Relation* readrel474 = db->getRelation("$sup56712x74x0x0x0");
      $sup56712x74x0x0x0index462 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({1, 2, 0});
      slog::Relation* readrel476 = db->getRelation("eval_args");
      eval_argsindex463 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 2, 0});
      slog::Relation* readrel478 = db->getRelation("eval_args");
      eval_argsdelta465 = readrel478->getIndex(ord477, true);
      std::vector<u16> ord479({0, 1});
      slog::Relation* readrel480 = db->getRelation("eval_args_ans");
      eval_args_ansindex464 = readrel480->getIndex(ord479, false);
  
    }
    ReadTask466(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c117 = _t[0];
        u64 v_c23 = _t[1];
        slog::join_probe<2,1>(eval_ansindex459, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m481) {
          u64 v_c118 = m481[1];
          slog::join_probe<3,1>(evalindex460, std::array<u64,3>{v_c118, 0, 0}, [&](const std::array<u64,3>& m482) {
            u64 v_c2 = m482[1]; u64 v_c77 = m482[2];
            if (!slog::exists_probe<3,1>(eval_argsindex461, std::array<u64,3>{v_c2, 0, 0})) return;
            slog::join_probe<4,2>($sup56712x74x0x0x0index462, std::array<u64,4>{v_c2, v_c77, 0, 0}, [&](const std::array<u64,4>& m483) {
              u64 v_c43 = m483[2]; u64 v_c119 = m483[3];
              slog::join_probe_old<3,2>(eval_argsindex463, eval_argsdelta465, std::array<u64,3>{v_c43, v_c2, 0}, [&](const std::array<u64,3>& m484) {
                u64 v_c120 = m484[2];
                slog::join_probe<2,1>(eval_args_ansindex464, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m485) {
                  u64 v_c73 = m485[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c23, v_c73}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:prim", _fires);
  
      if (!_done)
      {
        ReadTask466* _cont = new ReadTask466(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask466(db,b), false);
  // (crule (pre (let _00024sqc67YX483 const6b86b273ff34fce19d6b804e) (let _00024sqc6yXy484 const5feceb66ffc86f38d952786c) (let _00024sqc5zPS485 const6b86b273ff34fce19d6b804e) (let _00024sqc5ri6486 const5feceb66ffc86f38d952786c) (let _00024sqo8WWm491 const5feceb66ffc86f38d952786c) (let __t8LOa148 (lempty))) (scan freevar x e) (body (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo8WWm491 e _00024seq0) (join-old argument_list (0) 1 (0) _00024seq0) (letp _00024sql8fmo481 (aslst _00024seq0)) (let _00024sqn5D5C482 (llen _00024sql8fmo481)) (cmp ge _00024sqn5D5C482 _00024sqc67YX483) (letp chk3C04866 (lref _00024sql8fmo481 _00024sqc6yXy484)) (eq e chk3C04866) (let _00024sqp6Eh2487 (_0002d _00024sqn5D5C482 _00024sqc5ri6486)) (let es (lslice _00024sql8fmo481 _00024sqc5zPS485 _00024sqp6Eh2487))) (head (emit-temp temp86Ay863 __t8LOa148 e es x)) freevars.slog:35 #f)
  class ReadTask490 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex486;  slog::Index** argument_listindex487;  slog::Index** $seq_atdelta488;  slog::Index** argument_listdelta489;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp86Ay863");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord491({1, 0, 2});
      slog::Relation* readrel492 = db->getRelation("$seq_at");
      $seq_atindex486 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 0, 2});
      slog::Relation* readrel494 = db->getRelation("$seq_at");
      $seq_atdelta488 = readrel494->getIndex(ord493, true);
      std::vector<u16> ord495({0});
      slog::Relation* readrel496 = db->getRelation("argument_list");
      argument_listindex487 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({0});
      slog::Relation* readrel498 = db->getRelation("argument_list");
      argument_listdelta489 = readrel498->getIndex(ord497, true);
  
    }
    ReadTask490(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_const5feceb66ffc86f38d952786c;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_const5feceb66ffc86f38d952786c;
      u64 v_c126 = _prim_lempty(db);
      if (v_c126 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        u64 v_c29 = _t[1];
        slog::join_probe_old<3,2>($seq_atindex486, $seq_atdelta488, std::array<u64,3>{v_c125, v_c29, 0}, [&](const std::array<u64,3>& m499) {
          u64 v_c38 = m499[2];
          slog::join_probe_old<1,1>(argument_listindex487, argument_listdelta489, std::array<u64,1>{v_c38}, [&](const std::array<u64,1>& m500) {
            bool ok501 = true;
            u64 v_c127 = _prim_aslst(db, v_c38, &ok501);
            if (!ok501) return;
            u64 v_c128 = _prim_llen(db, v_c127);
            if (v_c128 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c129 = _prim_ge(db, v_c128, v_c121);
            if (v_c129 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            if (!v_c129) return;
            bool ok503 = true;
            u64 v_c130 = _prim_lref(db, v_c127, v_c122, &ok503);
            if (!ok503) return;
            if (v_c29 != v_c130) return;
            u64 v_c131 = _prim__0002d(db, v_c128, v_c124);
            if (v_c131 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            u64 v_c43 = _prim_lslice(db, v_c127, v_c123, v_c131);
            if (v_c43 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c126, v_c29, v_c43, v_c6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:freevar", _fires);
  
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
  // (crule (pre (let __tconst5mQl666 constb9e118781cea1f9fa01462e0) (let __tconst7ska196 const06abaa100ecef791ce028c56) (let _00024sqc2bs1547 constd4735e3a265e16eee03f5971) (let _00024sqc3b5Z548 const5feceb66ffc86f38d952786c) (let _00024sqc4cPv549 const6b86b273ff34fce19d6b804e) (let _00024sqo2orM550 const5feceb66ffc86f38d952786c) (let _00024sqo79dC551 const6b86b273ff34fce19d6b804e) (let _00024sqo7ukz552 const6b86b273ff34fce19d6b804e) (let _00024sqo5FdA553 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo7ukz552 v1 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo2orM550 v1 _00024seq0) (letp _00024sql4FKJ545 (aslst _00024seq0)) (letp v2 (lref _00024sql4FKJ545 _00024sqc4cPv549)) (neq v1 v2) (join $seq_at (1 0 2) 3 _00024sqo79dC551 v2 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5FdA553 v2 _00024seq0) (exists _enum (1 0) 1 __tconst5mQl666) (join delta (1 2 0) 2 __tconst7ska196 _00024seq0 __t0ECW197) (join _enum (1 0) 1 __tconst5mQl666 __t7sei194) (let chk1wqp876 (llen _00024sql4FKJ545)) (eq _00024sqc2bs1547 chk1wqp876) (letp chk83Xc877 (lref _00024sql4FKJ545 _00024sqc3b5Z548)) (eq v1 chk83Xc877)) (head (emit-temp temp5E9s870 __t0ECW197) (mkstruct boolval (1 0) __t2gQB195 __t7sei194)) interp.slog:120 #f)
  class ReadTask511 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex504;  slog::Index** $seq_atindex505;  slog::Index** $seq_atrindex506;  slog::Index** _enumindex507;  slog::Index** deltaindex508;  slog::Index** _enumindex509;  slog::Index** $seq_atrdelta510;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5E9s870");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord512({1, 0, 2});
      slog::Relation* readrel513 = db->getRelation("$seq_atr");
      driver_index = readrel513->getIndex(ord512, true);
      std::vector<u16> ord514({1, 0, 2});
      slog::Relation* readrel515 = db->getRelation("$seq_at");
      $seq_atindex504 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 0, 2});
      slog::Relation* readrel517 = db->getRelation("$seq_at");
      $seq_atindex505 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 0, 2});
      slog::Relation* readrel519 = db->getRelation("$seq_atr");
      $seq_atrindex506 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({1, 0, 2});
      slog::Relation* readrel521 = db->getRelation("$seq_atr");
      $seq_atrdelta510 = readrel521->getIndex(ord520, true);
      std::vector<u16> ord522({1, 0});
      slog::Relation* readrel523 = db->getRelation("_enum");
      _enumindex507 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({1, 2, 0});
      slog::Relation* readrel525 = db->getRelation("delta");
      deltaindex508 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({1, 0});
      slog::Relation* readrel527 = db->getRelation("_enum");
      _enumindex509 = readrel527->getIndex(ord526, false);
  
    }
    ReadTask511(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c132 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c133 = v_const06abaa100ecef791ce028c56;
      u64 v_c134 = v_constd4735e3a265e16eee03f5971;
      u64 v_c135 = v_const5feceb66ffc86f38d952786c;
      u64 v_c136 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c139, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m528) {
        u64 v_c141 = m528[1];
        u64 v_c38 = m528[2];
        if (buckethash(v_c141) != bucket) return;
        slog::join_probe<3,3>($seq_atindex504, std::array<u64,3>{v_c137, v_c141, v_c38}, [&](const std::array<u64,3>& m529) {
          bool ok530 = true;
          u64 v_c142 = _prim_aslst(db, v_c38, &ok530);
          if (!ok530) return;
          bool ok531 = true;
          u64 v_c143 = _prim_lref(db, v_c142, v_c136, &ok531);
          if (!ok531) return;
          if (v_c141 == v_c143) return;
          slog::join_probe<3,3>($seq_atindex505, std::array<u64,3>{v_c138, v_c143, v_c38}, [&](const std::array<u64,3>& m532) {
            slog::join_probe_old<3,3>($seq_atrindex506, $seq_atrdelta510, std::array<u64,3>{v_c140, v_c143, v_c38}, [&](const std::array<u64,3>& m533) {
              if (!slog::exists_probe<2,1>(_enumindex507, std::array<u64,2>{v_c132, 0})) return;
              slog::join_probe<3,2>(deltaindex508, std::array<u64,3>{v_c133, v_c38, 0}, [&](const std::array<u64,3>& m534) {
                u64 v_c144 = m534[2];
                slog::join_probe<2,1>(_enumindex509, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m535) {
                  u64 v_c145 = m535[1];
                  u64 v_c146 = _prim_llen(db, v_c142);
                  if (v_c146 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c134 != v_c146) return;
                  bool ok536 = true;
                  u64 v_c147 = _prim_lref(db, v_c142, v_c135, &ok536);
                  if (!ok536) return;
                  if (v_c141 != v_c147) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c144});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c145}, std::array<u16,2>{1, 0});
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
        ReadTask511* _cont = new ReadTask511(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask511(db,b), false);
  // (crule (pre) (scan eval __t4vYZ364 e1 c) (body (exists eval_ans (0 1) 1 __t4vYZ364) (join $sup56712x86x0x0x0 (1 2 0 3 4) 2 c e1 __d0 e2 e3) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t7P7f365 __v0) (join eval_ans (0 1) 2 __t4vYZ364 __v0) (join select_branch_ans (0 1) 1 __t7P7f365 __v1)) (head (mkstruct eval (1 2 0) __4AHX627 __v1 c)) interp.slog:87 #f)
  class ReadTask543 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex537;  slog::Index** $sup56712x86x0x0x0index538;  slog::Index** select_branchindex539;  slog::Index** eval_ansindex540;  slog::Index** select_branch_ansindex541;  slog::Index** select_branchdelta542;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord544({0, 1});
      slog::Relation* readrel545 = db->getRelation("eval_ans");
      eval_ansindex537 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 2, 0, 3, 4});
      slog::Relation* readrel547 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index538 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({2, 3, 0, 1});
      slog::Relation* readrel549 = db->getRelation("select_branch");
      select_branchindex539 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({2, 3, 0, 1});
      slog::Relation* readrel551 = db->getRelation("select_branch");
      select_branchdelta542 = readrel551->getIndex(ord550, true);
      std::vector<u16> ord552({0, 1});
      slog::Relation* readrel553 = db->getRelation("eval_ans");
      eval_ansindex540 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({0, 1});
      slog::Relation* readrel555 = db->getRelation("select_branch_ans");
      select_branch_ansindex541 = readrel555->getIndex(ord554, false);
  
    }
    ReadTask543(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c148 = _t[0];
        u64 v_c49 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<2,1>(eval_ansindex537, std::array<u64,2>{v_c148, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index538, std::array<u64,5>{v_c2, v_c49, 0, 0, 0}, [&](const std::array<u64,5>& m556) {
          u64 v_c119 = m556[2]; u64 v_c51 = m556[3]; u64 v_c52 = m556[4];
          slog::join_probe_old<4,2>(select_branchindex539, select_branchdelta542, std::array<u64,4>{v_c51, v_c52, 0, 0}, [&](const std::array<u64,4>& m557) {
            u64 v_c149 = m557[2]; u64 v_c37 = m557[3];
            slog::join_probe<2,2>(eval_ansindex540, std::array<u64,2>{v_c148, v_c37}, [&](const std::array<u64,2>& m558) {
              slog::join_probe<2,1>(select_branch_ansindex541, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m559) {
                u64 v_c46 = m559[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c46, v_c2}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask543* _cont = new ReadTask543(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask543(db,b), false);
  // (crule (pre (let __tconst0flI607 const0122baa3ac55f1b433944eb1)) (scan temp61mi1013 __t2i9A304) (body (join _enum (1 0) 1 __tconst0flI607 __t8LeX301) (join boolval (1 0) 1 __t8LeX301 __t5m8l302)) (head (emit delta_ans (0 1) __t2i9A304 __t5m8l302)) interp.slog:118 #f)
  class ReadTask562 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex560;  slog::Index** boolvalindex561;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord563({0, 1});
      slog::Relation* readrel564 = db->getRelation("delta_ans");
      head_index[0] = readrel564->getIndex(ord563, false);
      outer_rel = db->getRelation("temp61mi1013");
      std::vector<u16> ord565({1, 0});
      slog::Relation* readrel566 = db->getRelation("_enum");
      _enumindex560 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 0});
      slog::Relation* readrel568 = db->getRelation("boolval");
      boolvalindex561 = readrel568->getIndex(ord567, false);
  
    }
    ReadTask562(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c150 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c151 = _t[0];
        slog::join_probe<2,1>(_enumindex560, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m569) {
          u64 v_c152 = m569[1];
          slog::join_probe<2,1>(boolvalindex561, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m570) {
            u64 v_c153 = m570[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c151, v_c153}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:temp61mi1013", _fires);
  
      if (!_done)
      {
        ReadTask562* _cont = new ReadTask562(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask562(db,b), false);
  // (crule (pre) (scan select_branch __t5q6W45 __v0 e2 e3) (body (exists $sup56712x86x0x0x0 (3 4 2 0 1) 2 e2 e3) (exists eval_ans (1 0) 1 __v0) (exists select_branch_ans (0 1) 1 __t5q6W45) (join if (2 3 1 0) 2 e2 e3 e1 __t3ePt42) (exists eval (1 2 0) 1 __t3ePt42) (exists eval (1 2 0) 1 e1) (join $sup56712x86x0x0x0 (3 4 2 0 1) 3 e2 e3 e1 __t7yOw43 c) (join eval (0 2 1) 3 __t7yOw43 c __t3ePt42) (exists eval (2 0 1) 1 c) (join eval (1 2 0) 2 e1 c __t9ATC44) (join eval_ans (0 1) 2 __t9ATC44 __v0) (join select_branch_ans (0 1) 1 __t5q6W45 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t4U4F46) (join eval_ans (0 1) 1 __t4U4F46 __v2)) (head (emit eval_ans (0 1) __t7yOw43 __v2)) interp.slog:87 #f)
  class ReadTask586 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x86x0x0x0index571;  slog::Index** eval_ansindex572;  slog::Index** select_branch_ansindex573;  slog::Index** ifindex574;  slog::Index** evalindex575;  slog::Index** evalindex576;  slog::Index** $sup56712x86x0x0x0index577;  slog::Index** evalindex578;  slog::Index** evalindex579;  slog::Index** evalindex580;  slog::Index** eval_ansindex581;  slog::Index** select_branch_ansindex582;  slog::Index** evalindex583;  slog::Index** eval_ansindex584;  slog::Index** evaldelta585;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("eval_ans");
      head_index[0] = readrel588->getIndex(ord587, false);
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord589({3, 4, 2, 0, 1});
      slog::Relation* readrel590 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index571 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 0});
      slog::Relation* readrel592 = db->getRelation("eval_ans");
      eval_ansindex572 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({0, 1});
      slog::Relation* readrel594 = db->getRelation("select_branch_ans");
      select_branch_ansindex573 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({2, 3, 1, 0});
      slog::Relation* readrel596 = db->getRelation("if");
      ifindex574 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 2, 0});
      slog::Relation* readrel598 = db->getRelation("eval");
      evalindex575 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({1, 2, 0});
      slog::Relation* readrel600 = db->getRelation("eval");
      evalindex576 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({3, 4, 2, 0, 1});
      slog::Relation* readrel602 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index577 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({0, 2, 1});
      slog::Relation* readrel604 = db->getRelation("eval");
      evalindex578 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({2, 0, 1});
      slog::Relation* readrel606 = db->getRelation("eval");
      evalindex579 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({1, 2, 0});
      slog::Relation* readrel608 = db->getRelation("eval");
      evalindex580 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({0, 1});
      slog::Relation* readrel610 = db->getRelation("eval_ans");
      eval_ansindex581 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({0, 1});
      slog::Relation* readrel612 = db->getRelation("select_branch_ans");
      select_branch_ansindex582 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({1, 2, 0});
      slog::Relation* readrel614 = db->getRelation("eval");
      evalindex583 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("eval");
      evaldelta585 = readrel616->getIndex(ord615, true);
      std::vector<u16> ord617({0, 1});
      slog::Relation* readrel618 = db->getRelation("eval_ans");
      eval_ansindex584 = readrel618->getIndex(ord617, false);
  
    }
    ReadTask586(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c37 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c52 = _t[3];
        if (!slog::exists_probe<5,2>($sup56712x86x0x0x0index571, std::array<u64,5>{v_c51, v_c52, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex572, std::array<u64,2>{v_c37, 0})) return;
        if (!slog::exists_probe<2,1>(select_branch_ansindex573, std::array<u64,2>{v_c54, 0})) return;
        slog::join_probe<4,2>(ifindex574, std::array<u64,4>{v_c51, v_c52, 0, 0}, [&](const std::array<u64,4>& m619) {
          u64 v_c49 = m619[2]; u64 v_c53 = m619[3];
          if (!slog::exists_probe<3,1>(evalindex575, std::array<u64,3>{v_c53, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex576, std::array<u64,3>{v_c49, 0, 0})) return;
          slog::join_probe<5,3>($sup56712x86x0x0x0index577, std::array<u64,5>{v_c51, v_c52, v_c49, 0, 0}, [&](const std::array<u64,5>& m620) {
            u64 v_c50 = m620[3]; u64 v_c2 = m620[4];
            slog::join_probe<3,3>(evalindex578, std::array<u64,3>{v_c50, v_c2, v_c53}, [&](const std::array<u64,3>& m621) {
              if (!slog::exists_probe<3,1>(evalindex579, std::array<u64,3>{v_c2, 0, 0})) return;
              slog::join_probe<3,2>(evalindex580, std::array<u64,3>{v_c49, v_c2, 0}, [&](const std::array<u64,3>& m622) {
                u64 v_c48 = m622[2];
                slog::join_probe<2,2>(eval_ansindex581, std::array<u64,2>{v_c48, v_c37}, [&](const std::array<u64,2>& m623) {
                  slog::join_probe<2,1>(select_branch_ansindex582, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m624) {
                    u64 v_c46 = m624[1];
                    slog::join_probe_old<3,2>(evalindex583, evaldelta585, std::array<u64,3>{v_c46, v_c2, 0}, [&](const std::array<u64,3>& m625) {
                      u64 v_c55 = m625[2];
                      slog::join_probe<2,1>(eval_ansindex584, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m626) {
                        u64 v_c56 = m626[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c56}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask586* _cont = new ReadTask586(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask586(db,b), false);
  // (crule (pre) (scan if __t2Vv2345 e1 e2 e3) (body (join freevar (1 0) 1 e2 x)) (head (emit freevar (0 1) x __t2Vv2345)) freevars.slog:17 #f)
  class ReadTask628 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex627;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord629({0, 1});
      slog::Relation* readrel630 = db->getRelation("freevar");
      head_index[0] = readrel630->getIndex(ord629, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord631({1, 0});
      slog::Relation* readrel632 = db->getRelation("freevar");
      freevarindex627 = readrel632->getIndex(ord631, false);
  
    }
    ReadTask628(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c49 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c52 = _t[3];
        slog::join_probe<2,1>(freevarindex627, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m633) {
          u64 v_c6 = m633[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c154}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:if", _fires);
  
      if (!_done)
      {
        ReadTask628* _cont = new ReadTask628(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask628(db,b), false);
  // (crule (pre) (scan eval __t3XtU156 er c) (body (exists eval (2 0 1) 1 c) (exists letrec (2 1 3 0) 1 er) (join eval_ans (0 1) 1 __t3XtU156 vr) (join eval (2 0 1) 1 c __2TQp678 __t3lnK155) (join letrec (0 2 1 3) 2 __t3lnK155 er x eb)) (head (emit binding (0 1 2) x c vr) (emit binding_event (0 1 2) x c c)) interp.slog:95 #f)
  class ReadTask639 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex634;  slog::Index** letrecindex635;  slog::Index** eval_ansindex636;  slog::Index** evalindex637;  slog::Index** letrecindex638;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord640({0, 1, 2});
      slog::Relation* readrel641 = db->getRelation("binding");
      head_index[0] = readrel641->getIndex(ord640, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord642({0, 1, 2});
      slog::Relation* readrel643 = db->getRelation("binding_event");
      head_index[1] = readrel643->getIndex(ord642, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord644({2, 0, 1});
      slog::Relation* readrel645 = db->getRelation("eval");
      evalindex634 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({2, 1, 3, 0});
      slog::Relation* readrel647 = db->getRelation("letrec");
      letrecindex635 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({0, 1});
      slog::Relation* readrel649 = db->getRelation("eval_ans");
      eval_ansindex636 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({2, 0, 1});
      slog::Relation* readrel651 = db->getRelation("eval");
      evalindex637 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 2, 1, 3});
      slog::Relation* readrel653 = db->getRelation("letrec");
      letrecindex638 = readrel653->getIndex(ord652, false);
  
    }
    ReadTask639(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c155 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex634, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letrecindex635, std::array<u64,4>{v_c5, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex636, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m654) {
          u64 v_c9 = m654[1];
          slog::join_probe<3,1>(evalindex637, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m655) {
            u64 v_c156 = m655[1]; u64 v_c157 = m655[2];
            slog::join_probe<4,2>(letrecindex638, std::array<u64,4>{v_c157, v_c5, 0, 0}, [&](const std::array<u64,4>& m656) {
              u64 v_c6 = m656[2]; u64 v_c3 = m656[3];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c6, v_c2, v_c9}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c6, v_c2, v_c2}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:95", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask639* _cont = new ReadTask639(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask639(db,b), false);
  // (crule (pre) (scan closure __t2qAJ322 __t7ycN321 cb) (body (join eval_ans (1 0) 1 __t2qAJ322 __t550i320) (join eval (0 2 1) 1 __t550i320 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __5izx673 __t9nj7324) (exists tick (1 2 0) 2 __t9nj7324 c) (join-old app (0 1 2) 2 (0 1 2) __t9nj7324 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t8cVn323) (exists eval_args_ans (0 1) 1 __t8cVn323) (join-old tick (1 2 0) 2 (1 2 0) __t9nj7324 c __t3nAR325) (exists tick_ans (0 1) 1 __t3nAR325) (join eval_args_ans (0 1) 1 __t8cVn323 vs) (join tick_ans (0 1) 1 __t3nAR325 l) (join lambda (0 1 2) 1 __t7ycN321 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask675 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex657;  slog::Index** evalindex658;  slog::Index** appindex659;  slog::Index** eval_argsindex660;  slog::Index** tickindex661;  slog::Index** evalindex662;  slog::Index** tickindex663;  slog::Index** appindex664;  slog::Index** eval_argsindex665;  slog::Index** eval_args_ansindex666;  slog::Index** tickindex667;  slog::Index** tick_ansindex668;  slog::Index** eval_args_ansindex669;  slog::Index** tick_ansindex670;  slog::Index** lambdaindex671;  slog::Index** appdelta672;  slog::Index** eval_argsdelta673;  slog::Index** tickdelta674;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord676({0, 1, 2, 3});
      slog::Relation* readrel677 = db->getRelation("bind_params");
      head_index[0] = readrel677->getIndex(ord676, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord678({0, 1});
      slog::Relation* readrel679 = db->getRelation("call_event");
      head_index[1] = readrel679->getIndex(ord678, false);
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord680({1, 0});
      slog::Relation* readrel681 = db->getRelation("eval_ans");
      eval_ansindex657 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({0, 2, 1});
      slog::Relation* readrel683 = db->getRelation("eval");
      evalindex658 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({1, 2, 0});
      slog::Relation* readrel685 = db->getRelation("app");
      appindex659 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({2, 0, 1});
      slog::Relation* readrel687 = db->getRelation("eval_args");
      eval_argsindex660 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({2, 0, 1});
      slog::Relation* readrel689 = db->getRelation("tick");
      tickindex661 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({2, 0, 1});
      slog::Relation* readrel691 = db->getRelation("eval");
      evalindex662 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 0});
      slog::Relation* readrel693 = db->getRelation("tick");
      tickindex663 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({0, 1, 2});
      slog::Relation* readrel695 = db->getRelation("app");
      appindex664 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({0, 1, 2});
      slog::Relation* readrel697 = db->getRelation("app");
      appdelta672 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({1, 2, 0});
      slog::Relation* readrel699 = db->getRelation("eval_args");
      eval_argsindex665 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 2, 0});
      slog::Relation* readrel701 = db->getRelation("eval_args");
      eval_argsdelta673 = readrel701->getIndex(ord700, true);
      std::vector<u16> ord702({0, 1});
      slog::Relation* readrel703 = db->getRelation("eval_args_ans");
      eval_args_ansindex666 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 2, 0});
      slog::Relation* readrel705 = db->getRelation("tick");
      tickindex667 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({1, 2, 0});
      slog::Relation* readrel707 = db->getRelation("tick");
      tickdelta674 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({0, 1});
      slog::Relation* readrel709 = db->getRelation("tick_ans");
      tick_ansindex668 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({0, 1});
      slog::Relation* readrel711 = db->getRelation("eval_args_ans");
      eval_args_ansindex669 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({0, 1});
      slog::Relation* readrel713 = db->getRelation("tick_ans");
      tick_ansindex670 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({0, 1, 2});
      slog::Relation* readrel715 = db->getRelation("lambda");
      lambdaindex671 = readrel715->getIndex(ord714, false);
  
    }
    ReadTask675(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c158 = _t[0];
        u64 v_c159 = _t[1];
        u64 v_c160 = _t[2];
        slog::join_probe<2,1>(eval_ansindex657, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m716) {
          u64 v_c161 = m716[1];
          slog::join_probe<3,1>(evalindex658, std::array<u64,3>{v_c161, 0, 0}, [&](const std::array<u64,3>& m717) {
            u64 v_c2 = m717[1]; u64 v_c77 = m717[2];
            if (!slog::exists_probe<3,1>(appindex659, std::array<u64,3>{v_c77, 0, 0})) return;
            if (!slog::exists_probe<3,1>(eval_argsindex660, std::array<u64,3>{v_c2, 0, 0})) return;
            if (!slog::exists_probe<3,1>(tickindex661, std::array<u64,3>{v_c2, 0, 0})) return;
            slog::join_probe<3,1>(evalindex662, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m718) {
              u64 v_c162 = m718[1]; u64 v_c163 = m718[2];
              if (!slog::exists_probe<3,2>(tickindex663, std::array<u64,3>{v_c163, v_c2, 0})) return;
              slog::join_probe_old<3,2>(appindex664, appdelta672, std::array<u64,3>{v_c163, v_c77, 0}, [&](const std::array<u64,3>& m719) {
                u64 v_c43 = m719[2];
                slog::join_probe_old<3,2>(eval_argsindex665, eval_argsdelta673, std::array<u64,3>{v_c43, v_c2, 0}, [&](const std::array<u64,3>& m720) {
                  u64 v_c164 = m720[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex666, std::array<u64,2>{v_c164, 0})) return;
                  slog::join_probe_old<3,2>(tickindex667, tickdelta674, std::array<u64,3>{v_c163, v_c2, 0}, [&](const std::array<u64,3>& m721) {
                    u64 v_c165 = m721[2];
                    if (!slog::exists_probe<2,1>(tick_ansindex668, std::array<u64,2>{v_c165, 0})) return;
                    slog::join_probe<2,1>(eval_args_ansindex669, std::array<u64,2>{v_c164, 0}, [&](const std::array<u64,2>& m722) {
                      u64 v_c73 = m722[1];
                      slog::join_probe<2,1>(tick_ansindex670, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m723) {
                        u64 v_c166 = m723[1];
                        slog::join_probe<3,1>(lambdaindex671, std::array<u64,3>{v_c159, 0, 0}, [&](const std::array<u64,3>& m724) {
                          u64 v_c167 = m724[1]; u64 v_c3 = m724[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c167, v_c73, v_c166, v_c2}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c166, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:closure", _fires);
  
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
  // (crule (pre (let __tconst2fdM633 constcd2a69ce5ca278db1d6da969) (let _00024sqc7LFn532 constd4735e3a265e16eee03f5971) (let _00024sqc3SHd533 const5feceb66ffc86f38d952786c) (let _00024sqc4CLM534 const6b86b273ff34fce19d6b804e) (let _00024sqo90j9535 const5feceb66ffc86f38d952786c) (let _00024sqo88rK536 const6b86b273ff34fce19d6b804e) (let _00024sqo1A9y537 const6b86b273ff34fce19d6b804e) (let _00024sqo2hWF538 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo1A9y537 __t26Zq339 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo90j9535 __t26Zq339 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo88rK536 __t26Zq339 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2hWF538 __t26Zq339 _00024seq2) (join _enum (0 1) 2 __t26Zq339 __tconst2fdM633) (join delta (2 0 1) 1 _00024seq2 __t1IV0337 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql96G9530 (aslst _00024seq2)) (let chk732R954 (llen _00024sql96G9530)) (eq _00024sqc7LFn532 chk732R954) (letp chk4CwL955 (lref _00024sql96G9530 _00024sqc3SHd533)) (eq __t26Zq339 chk4CwL955) (letp chk2cBL956 (lref _00024sql96G9530 _00024sqc4CLM534)) (eq __t26Zq339 chk2cBL956)) (head (emit-temp temp5ZiW945 __t1IV0337 b) (mkstruct boolval (1 0) __t4qAo336 b)) interp.slog:112 #f)
  class ReadTask733 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex725;  slog::Index** $seq_atindex726;  slog::Index** $seq_atrindex727;  slog::Index** _enumindex728;  slog::Index** deltaindex729;  slog::Index** comparison_opindex730;  slog::Index** any_boolindex731;  slog::Index** $seq_atrdelta732;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5ZiW945");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord734({1, 0, 2});
      slog::Relation* readrel735 = db->getRelation("$seq_atr");
      driver_index = readrel735->getIndex(ord734, true);
      std::vector<u16> ord736({1, 0, 2});
      slog::Relation* readrel737 = db->getRelation("$seq_at");
      $seq_atindex725 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({1, 0, 2});
      slog::Relation* readrel739 = db->getRelation("$seq_at");
      $seq_atindex726 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({1, 0, 2});
      slog::Relation* readrel741 = db->getRelation("$seq_atr");
      $seq_atrindex727 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 0, 2});
      slog::Relation* readrel743 = db->getRelation("$seq_atr");
      $seq_atrdelta732 = readrel743->getIndex(ord742, true);
      std::vector<u16> ord744({0, 1});
      slog::Relation* readrel745 = db->getRelation("_enum");
      _enumindex728 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({2, 0, 1});
      slog::Relation* readrel747 = db->getRelation("delta");
      deltaindex729 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({0});
      slog::Relation* readrel749 = db->getRelation("comparison_op");
      comparison_opindex730 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({0});
      slog::Relation* readrel751 = db->getRelation("any_bool");
      any_boolindex731 = readrel751->getIndex(ord750, false);
  
    }
    ReadTask733(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c58 = v_constd4735e3a265e16eee03f5971;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c61 = v_const5feceb66ffc86f38d952786c;
      u64 v_c62 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c63 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c64 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c63, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m752) {
        u64 v_c65 = m752[1];
        u64 v_c20 = m752[2];
        if (buckethash(v_c65) != bucket) return;
        slog::join_probe<3,3>($seq_atindex725, std::array<u64,3>{v_c61, v_c65, v_c20}, [&](const std::array<u64,3>& m753) {
          slog::join_probe<3,3>($seq_atindex726, std::array<u64,3>{v_c62, v_c65, v_c20}, [&](const std::array<u64,3>& m754) {
            slog::join_probe_old<3,3>($seq_atrindex727, $seq_atrdelta732, std::array<u64,3>{v_c64, v_c65, v_c20}, [&](const std::array<u64,3>& m755) {
              slog::join_probe<2,2>(_enumindex728, std::array<u64,2>{v_c65, v_c57}, [&](const std::array<u64,2>& m756) {
                slog::join_probe<3,1>(deltaindex729, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m757) {
                  u64 v_c66 = m757[1]; u64 v_c23 = m757[2];
                  slog::join_probe<1,1>(comparison_opindex730, std::array<u64,1>{v_c23}, [&](const std::array<u64,1>& m758) {
                    slog::join_all<1>(any_boolindex731, [&](const std::array<u64,1>& m759) {
                      u64 v_c67 = m759[0];
                      bool ok760 = true;
                      u64 v_c68 = _prim_aslst(db, v_c20, &ok760);
                      if (!ok760) return;
                      u64 v_c168 = _prim_llen(db, v_c68);
                      if (v_c168 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c58 != v_c168) return;
                      bool ok761 = true;
                      u64 v_c169 = _prim_lref(db, v_c68, v_c59, &ok761);
                      if (!ok761) return;
                      if (v_c65 != v_c169) return;
                      bool ok762 = true;
                      u64 v_c170 = _prim_lref(db, v_c68, v_c60, &ok762);
                      if (!ok762) return;
                      if (v_c65 != v_c170) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c66, v_c67});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c67}, std::array<u16,2>{1, 0});
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
        ReadTask733* _cont = new ReadTask733(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask733(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97)) (scan temp09au970 __t0Ieb261 __t4sa5291 __t7Cof275) (body (join let (2 1 3 0) 3 __t7Cof275 __tconst2XD5276 __t0Ieb261 __t0GXe277)) (head (emit-temp temp1uko971 __t0GXe277 __t4sa5291) (mkstruct let (2 1 3 0) __t9Jnj293 __t4sa5291 __tconst7wlx292 __t0GXe277)) analysis-demo.slog:21 #f)
  class ReadTask764 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex763;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1uko971");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp09au970");
      std::vector<u16> ord765({2, 1, 3, 0});
      slog::Relation* readrel766 = db->getRelation("let");
      letindex763 = readrel766->getIndex(ord765, false);
  
    }
    ReadTask764(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c80 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c81 = v_constf77801bebb40767a1b303d97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c171 = _t[0];
        u64 v_c172 = _t[1];
        u64 v_c173 = _t[2];
        slog::join_probe<4,3>(letindex763, std::array<u64,4>{v_c173, v_c81, v_c171, 0}, [&](const std::array<u64,4>& m767) {
          u64 v_c174 = m767[3];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c174, v_c172});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c172, v_c80, v_c174}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp09au970", _fires);
  
      if (!_done)
      {
        ReadTask764* _cont = new ReadTask764(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask764(db,b), false);
  // (crule (pre (let _00024sqc9r51426 const6b86b273ff34fce19d6b804e) (let _00024sqc0a7Y427 const5feceb66ffc86f38d952786c) (let _00024sqc6lAT428 const6b86b273ff34fce19d6b804e) (let _00024sqc6zTj429 const5feceb66ffc86f38d952786c) (let _00024sqo7QcU434 const5feceb66ffc86f38d952786c) (let __t31sY376 (lempty))) (scan $sup56712x37x0x0x0 _00024seq0 __t1ye1379 c e es) (body (join-old eval_args (0 2 1) 3 (0 2 1) __t1ye1379 c _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7QcU434 e _00024seq0) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) e c __t33Oa380) (exists eval_ans (0 1) 1 __t33Oa380) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5lLk381) (exists eval_args_ans (0 1) 1 __t5lLk381) (join eval_ans (0 1) 1 __t33Oa380 __v0) (join eval_args_ans (0 1) 1 __t5lLk381 __v1) (letp _00024sql0xMp424 (aslst _00024seq0)) (let _00024sqn1MBN425 (llen _00024sql0xMp424)) (cmp ge _00024sqn1MBN425 _00024sqc9r51426) (letp chk3Z5f939 (lref _00024sql0xMp424 _00024sqc0a7Y427)) (eq e chk3Z5f939) (let _00024sqp04Wv430 (_0002d _00024sqn1MBN425 _00024sqc6zTj429)) (let chk54CQ940 (lslice _00024sql0xMp424 _00024sqc6lAT428 _00024sqp04Wv430)) (eq es chk54CQ940)) (head (emit-temp temp0JGK933 __t1ye1379 __t31sY376 __v0 __v1)) interp.slog:38 #f)
  class ReadTask781 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex768;  slog::Index** $seq_atindex769;  slog::Index** eval_argsindex770;  slog::Index** evalindex771;  slog::Index** eval_ansindex772;  slog::Index** eval_argsindex773;  slog::Index** eval_args_ansindex774;  slog::Index** eval_ansindex775;  slog::Index** eval_args_ansindex776;  slog::Index** eval_argsdelta777;  slog::Index** $seq_atdelta778;  slog::Index** evaldelta779;  slog::Index** eval_argsdelta780;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0JGK933");
      outer_rel = db->getRelation("$sup56712x37x0x0x0");
      std::vector<u16> ord782({0, 2, 1});
      slog::Relation* readrel783 = db->getRelation("eval_args");
      eval_argsindex768 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({0, 2, 1});
      slog::Relation* readrel785 = db->getRelation("eval_args");
      eval_argsdelta777 = readrel785->getIndex(ord784, true);
      std::vector<u16> ord786({1, 0, 2});
      slog::Relation* readrel787 = db->getRelation("$seq_at");
      $seq_atindex769 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({1, 0, 2});
      slog::Relation* readrel789 = db->getRelation("$seq_at");
      $seq_atdelta778 = readrel789->getIndex(ord788, true);
      std::vector<u16> ord790({1, 2, 0});
      slog::Relation* readrel791 = db->getRelation("eval_args");
      eval_argsindex770 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({1, 2, 0});
      slog::Relation* readrel793 = db->getRelation("eval");
      evalindex771 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({1, 2, 0});
      slog::Relation* readrel795 = db->getRelation("eval");
      evaldelta779 = readrel795->getIndex(ord794, true);
      std::vector<u16> ord796({0, 1});
      slog::Relation* readrel797 = db->getRelation("eval_ans");
      eval_ansindex772 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 2, 0});
      slog::Relation* readrel799 = db->getRelation("eval_args");
      eval_argsindex773 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 2, 0});
      slog::Relation* readrel801 = db->getRelation("eval_args");
      eval_argsdelta780 = readrel801->getIndex(ord800, true);
      std::vector<u16> ord802({0, 1});
      slog::Relation* readrel803 = db->getRelation("eval_args_ans");
      eval_args_ansindex774 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({0, 1});
      slog::Relation* readrel805 = db->getRelation("eval_ans");
      eval_ansindex775 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({0, 1});
      slog::Relation* readrel807 = db->getRelation("eval_args_ans");
      eval_args_ansindex776 = readrel807->getIndex(ord806, false);
  
    }
    ReadTask781(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_const5feceb66ffc86f38d952786c;
      u64 v_c34 = v_const5feceb66ffc86f38d952786c;
      u64 v_c35 = _prim_lempty(db);
      if (v_c35 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c43 = _t[4];
        slog::join_probe_old<3,3>(eval_argsindex768, eval_argsdelta777, std::array<u64,3>{v_c44, v_c2, v_c38}, [&](const std::array<u64,3>& m808) {
          slog::join_probe_old<3,3>($seq_atindex769, $seq_atdelta778, std::array<u64,3>{v_c34, v_c29, v_c38}, [&](const std::array<u64,3>& m809) {
            if (!slog::exists_probe<3,2>(eval_argsindex770, std::array<u64,3>{v_c43, v_c2, 0})) return;
            slog::join_probe_old<3,2>(evalindex771, evaldelta779, std::array<u64,3>{v_c29, v_c2, 0}, [&](const std::array<u64,3>& m810) {
              u64 v_c36 = m810[2];
              if (!slog::exists_probe<2,1>(eval_ansindex772, std::array<u64,2>{v_c36, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex773, eval_argsdelta780, std::array<u64,3>{v_c43, v_c2, 0}, [&](const std::array<u64,3>& m811) {
                u64 v_c45 = m811[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex774, std::array<u64,2>{v_c45, 0})) return;
                slog::join_probe<2,1>(eval_ansindex775, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m812) {
                  u64 v_c37 = m812[1];
                  slog::join_probe<2,1>(eval_args_ansindex776, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m813) {
                    u64 v_c46 = m813[1];
                    bool ok814 = true;
                    u64 v_c39 = _prim_aslst(db, v_c38, &ok814);
                    if (!ok814) return;
                    u64 v_c40 = _prim_llen(db, v_c39);
                    if (v_c40 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c175 = _prim_ge(db, v_c40, v_c30);
                    if (v_c175 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (!v_c175) return;
                    bool ok816 = true;
                    u64 v_c176 = _prim_lref(db, v_c39, v_c31, &ok816);
                    if (!ok816) return;
                    if (v_c29 != v_c176) return;
                    u64 v_c42 = _prim__0002d(db, v_c40, v_c33);
                    if (v_c42 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    u64 v_c177 = _prim_lslice(db, v_c39, v_c32, v_c42);
                    if (v_c177 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
                    if (v_c43 != v_c177) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c44, v_c35, v_c37, v_c46});
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
        ReadTask781* _cont = new ReadTask781(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask781(db,b), false);
  // (crule (pre) (scan app __t9nj7324 ef es) (body (exists eval (1 2 0) 1 ef) (exists eval_args (1 2 0) 1 es) (exists tick (1 2 0) 1 __t9nj7324) (join eval (1 2 0) 1 __t9nj7324 c __5izx673) (exists eval_args (1 2 0) 2 es c) (exists tick (1 2 0) 2 __t9nj7324 c) (join eval (1 2 0) 2 ef c __t550i320) (exists eval_ans (0 1) 1 __t550i320) (join eval_args (1 2 0) 2 es c __t8cVn323) (exists eval_args_ans (0 1) 1 __t8cVn323) (join-old tick (1 2 0) 2 (1 2 0) __t9nj7324 c __t3nAR325) (exists tick_ans (0 1) 1 __t3nAR325) (join eval_ans (0 1) 1 __t550i320 __t2qAJ322) (join eval_args_ans (0 1) 1 __t8cVn323 vs) (join tick_ans (0 1) 1 __t3nAR325 l) (join closure (0 1 2) 1 __t2qAJ322 __t7ycN321 cb) (join lambda (0 1 2) 1 __t7ycN321 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask835 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex817;  slog::Index** eval_argsindex818;  slog::Index** tickindex819;  slog::Index** evalindex820;  slog::Index** eval_argsindex821;  slog::Index** tickindex822;  slog::Index** evalindex823;  slog::Index** eval_ansindex824;  slog::Index** eval_argsindex825;  slog::Index** eval_args_ansindex826;  slog::Index** tickindex827;  slog::Index** tick_ansindex828;  slog::Index** eval_ansindex829;  slog::Index** eval_args_ansindex830;  slog::Index** tick_ansindex831;  slog::Index** closureindex832;  slog::Index** lambdaindex833;  slog::Index** tickdelta834;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord836({0, 1, 2, 3});
      slog::Relation* readrel837 = db->getRelation("bind_params");
      head_index[0] = readrel837->getIndex(ord836, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord838({0, 1});
      slog::Relation* readrel839 = db->getRelation("call_event");
      head_index[1] = readrel839->getIndex(ord838, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord840({1, 2, 0});
      slog::Relation* readrel841 = db->getRelation("eval");
      evalindex817 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 2, 0});
      slog::Relation* readrel843 = db->getRelation("eval_args");
      eval_argsindex818 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({1, 2, 0});
      slog::Relation* readrel845 = db->getRelation("tick");
      tickindex819 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 2, 0});
      slog::Relation* readrel847 = db->getRelation("eval");
      evalindex820 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({1, 2, 0});
      slog::Relation* readrel849 = db->getRelation("eval_args");
      eval_argsindex821 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({1, 2, 0});
      slog::Relation* readrel851 = db->getRelation("tick");
      tickindex822 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({1, 2, 0});
      slog::Relation* readrel853 = db->getRelation("eval");
      evalindex823 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({0, 1});
      slog::Relation* readrel855 = db->getRelation("eval_ans");
      eval_ansindex824 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({1, 2, 0});
      slog::Relation* readrel857 = db->getRelation("eval_args");
      eval_argsindex825 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({0, 1});
      slog::Relation* readrel859 = db->getRelation("eval_args_ans");
      eval_args_ansindex826 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({1, 2, 0});
      slog::Relation* readrel861 = db->getRelation("tick");
      tickindex827 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({1, 2, 0});
      slog::Relation* readrel863 = db->getRelation("tick");
      tickdelta834 = readrel863->getIndex(ord862, true);
      std::vector<u16> ord864({0, 1});
      slog::Relation* readrel865 = db->getRelation("tick_ans");
      tick_ansindex828 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({0, 1});
      slog::Relation* readrel867 = db->getRelation("eval_ans");
      eval_ansindex829 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({0, 1});
      slog::Relation* readrel869 = db->getRelation("eval_args_ans");
      eval_args_ansindex830 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({0, 1});
      slog::Relation* readrel871 = db->getRelation("tick_ans");
      tick_ansindex831 = readrel871->getIndex(ord870, false);
      std::vector<u16> ord872({0, 1, 2});
      slog::Relation* readrel873 = db->getRelation("closure");
      closureindex832 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({0, 1, 2});
      slog::Relation* readrel875 = db->getRelation("lambda");
      lambdaindex833 = readrel875->getIndex(ord874, false);
  
    }
    ReadTask835(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c163 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c43 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex817, std::array<u64,3>{v_c77, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex818, std::array<u64,3>{v_c43, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex819, std::array<u64,3>{v_c163, 0, 0})) return;
        slog::join_probe<3,1>(evalindex820, std::array<u64,3>{v_c163, 0, 0}, [&](const std::array<u64,3>& m876) {
          u64 v_c2 = m876[1]; u64 v_c162 = m876[2];
          if (!slog::exists_probe<3,2>(eval_argsindex821, std::array<u64,3>{v_c43, v_c2, 0})) return;
          if (!slog::exists_probe<3,2>(tickindex822, std::array<u64,3>{v_c163, v_c2, 0})) return;
          slog::join_probe<3,2>(evalindex823, std::array<u64,3>{v_c77, v_c2, 0}, [&](const std::array<u64,3>& m877) {
            u64 v_c161 = m877[2];
            if (!slog::exists_probe<2,1>(eval_ansindex824, std::array<u64,2>{v_c161, 0})) return;
            slog::join_probe<3,2>(eval_argsindex825, std::array<u64,3>{v_c43, v_c2, 0}, [&](const std::array<u64,3>& m878) {
              u64 v_c164 = m878[2];
              if (!slog::exists_probe<2,1>(eval_args_ansindex826, std::array<u64,2>{v_c164, 0})) return;
              slog::join_probe_old<3,2>(tickindex827, tickdelta834, std::array<u64,3>{v_c163, v_c2, 0}, [&](const std::array<u64,3>& m879) {
                u64 v_c165 = m879[2];
                if (!slog::exists_probe<2,1>(tick_ansindex828, std::array<u64,2>{v_c165, 0})) return;
                slog::join_probe<2,1>(eval_ansindex829, std::array<u64,2>{v_c161, 0}, [&](const std::array<u64,2>& m880) {
                  u64 v_c158 = m880[1];
                  slog::join_probe<2,1>(eval_args_ansindex830, std::array<u64,2>{v_c164, 0}, [&](const std::array<u64,2>& m881) {
                    u64 v_c73 = m881[1];
                    slog::join_probe<2,1>(tick_ansindex831, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m882) {
                      u64 v_c166 = m882[1];
                      slog::join_probe<3,1>(closureindex832, std::array<u64,3>{v_c158, 0, 0}, [&](const std::array<u64,3>& m883) {
                        u64 v_c159 = m883[1]; u64 v_c160 = m883[2];
                        slog::join_probe<3,1>(lambdaindex833, std::array<u64,3>{v_c159, 0, 0}, [&](const std::array<u64,3>& m884) {
                          u64 v_c167 = m884[1]; u64 v_c3 = m884[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c167, v_c73, v_c166, v_c2}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c166, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask835* _cont = new ReadTask835(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask835(db,b), false);
  // (crule (pre (let __tconst5QMk601 constcd2a69ce5ca278db1d6da969)) (scan eval __t0S0V10 __t5ViU9 c) (body (join _enum (1 0) 1 __tconst5QMk601 __t0FqU8) (join num (0 1) 1 __t5ViU9 n)) (head (emit eval_ans (0 1) __t0S0V10 __t0FqU8)) interp.slog:26 #f)
  class ReadTask887 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex885;  slog::Index** numindex886;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord888({0, 1});
      slog::Relation* readrel889 = db->getRelation("eval_ans");
      head_index[0] = readrel889->getIndex(ord888, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord890({1, 0});
      slog::Relation* readrel891 = db->getRelation("_enum");
      _enumindex885 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({0, 1});
      slog::Relation* readrel893 = db->getRelation("num");
      numindex886 = readrel893->getIndex(ord892, false);
  
    }
    ReadTask887(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c178 = v_constcd2a69ce5ca278db1d6da969;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c179 = _t[0];
        u64 v_c180 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<2,1>(_enumindex885, std::array<u64,2>{v_c178, 0}, [&](const std::array<u64,2>& m894) {
          u64 v_c181 = m894[1];
          slog::join_probe<2,1>(numindex886, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m895) {
            u64 v_c182 = m895[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c179, v_c181}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:26", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask887* _cont = new ReadTask887(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask887(db,b), false);
  // (crule (pre) (scan eval __6RFP667 __t7pOP300 c) (body (join-old app (0 1 2) 1 (0 1 2) __t7pOP300 ef es)) (head (mkstruct eval_args (1 2 0) __80Wk668 es c)) interp.slog:48 #f)
  class ReadTask898 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex896;  slog::Index** appdelta897;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord899({0, 1, 2});
      slog::Relation* readrel900 = db->getRelation("app");
      appindex896 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({0, 1, 2});
      slog::Relation* readrel902 = db->getRelation("app");
      appdelta897 = readrel902->getIndex(ord901, true);
  
    }
    ReadTask898(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c183 = _t[0];
        u64 v_c184 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(appindex896, appdelta897, std::array<u64,3>{v_c184, 0, 0}, [&](const std::array<u64,3>& m903) {
          u64 v_c77 = m903[1]; u64 v_c43 = m903[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c43, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask898* _cont = new ReadTask898(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask898(db,b), false);
  // (crule (pre) (scan select_branch_ans __t5q6W45 __v1) (body (join-old eval (1 2 0) 1 (1 2 0) __v1 c __t4U4F46) (exists eval (2 0 1) 1 c) (exists $sup56712x86x0x0x0 (1 0 2 3 4) 1 c) (join-old eval_ans (0 1) 1 (0 1) __t4U4F46 __v2) (join-old eval (2 0 1) 1 (2 0 1) c __t7yOw43 __t3ePt42) (join-old $sup56712x86x0x0x0 (1 0 2 3 4) 2 (1 0 2 3 4) c __t7yOw43 e1 e2 e3) (join-old if (2 3 1 0) 4 (2 3 1 0) e2 e3 e1 __t3ePt42) (exists eval (1 2 0) 2 e1 c) (join-old select_branch (2 3 0 1) 3 (2 3 0 1) e2 e3 __t5q6W45 __v0) (exists eval_ans (1 0) 1 __v0) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t9ATC44) (join eval_ans (0 1) 2 __t9ATC44 __v0)) (head (emit eval_ans (0 1) __t7yOw43 __v2)) interp.slog:87 #f)
  class ReadTask923 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex904;  slog::Index** evalindex905;  slog::Index** $sup56712x86x0x0x0index906;  slog::Index** eval_ansindex907;  slog::Index** evalindex908;  slog::Index** $sup56712x86x0x0x0index909;  slog::Index** ifindex910;  slog::Index** evalindex911;  slog::Index** select_branchindex912;  slog::Index** eval_ansindex913;  slog::Index** evalindex914;  slog::Index** eval_ansindex915;  slog::Index** evaldelta916;  slog::Index** eval_ansdelta917;  slog::Index** evaldelta918;  slog::Index** $sup56712x86x0x0x0delta919;  slog::Index** ifdelta920;  slog::Index** select_branchdelta921;  slog::Index** evaldelta922;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord924({0, 1});
      slog::Relation* readrel925 = db->getRelation("eval_ans");
      head_index[0] = readrel925->getIndex(ord924, false);
      outer_rel = db->getRelation("select_branch_ans");
      std::vector<u16> ord926({1, 2, 0});
      slog::Relation* readrel927 = db->getRelation("eval");
      evalindex904 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 2, 0});
      slog::Relation* readrel929 = db->getRelation("eval");
      evaldelta916 = readrel929->getIndex(ord928, true);
      std::vector<u16> ord930({2, 0, 1});
      slog::Relation* readrel931 = db->getRelation("eval");
      evalindex905 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 0, 2, 3, 4});
      slog::Relation* readrel933 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index906 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({0, 1});
      slog::Relation* readrel935 = db->getRelation("eval_ans");
      eval_ansindex907 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({0, 1});
      slog::Relation* readrel937 = db->getRelation("eval_ans");
      eval_ansdelta917 = readrel937->getIndex(ord936, true);
      std::vector<u16> ord938({2, 0, 1});
      slog::Relation* readrel939 = db->getRelation("eval");
      evalindex908 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({2, 0, 1});
      slog::Relation* readrel941 = db->getRelation("eval");
      evaldelta918 = readrel941->getIndex(ord940, true);
      std::vector<u16> ord942({1, 0, 2, 3, 4});
      slog::Relation* readrel943 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index909 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({1, 0, 2, 3, 4});
      slog::Relation* readrel945 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0delta919 = readrel945->getIndex(ord944, true);
      std::vector<u16> ord946({2, 3, 1, 0});
      slog::Relation* readrel947 = db->getRelation("if");
      ifindex910 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({2, 3, 1, 0});
      slog::Relation* readrel949 = db->getRelation("if");
      ifdelta920 = readrel949->getIndex(ord948, true);
      std::vector<u16> ord950({1, 2, 0});
      slog::Relation* readrel951 = db->getRelation("eval");
      evalindex911 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({2, 3, 0, 1});
      slog::Relation* readrel953 = db->getRelation("select_branch");
      select_branchindex912 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({2, 3, 0, 1});
      slog::Relation* readrel955 = db->getRelation("select_branch");
      select_branchdelta921 = readrel955->getIndex(ord954, true);
      std::vector<u16> ord956({1, 0});
      slog::Relation* readrel957 = db->getRelation("eval_ans");
      eval_ansindex913 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({1, 2, 0});
      slog::Relation* readrel959 = db->getRelation("eval");
      evalindex914 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({1, 2, 0});
      slog::Relation* readrel961 = db->getRelation("eval");
      evaldelta922 = readrel961->getIndex(ord960, true);
      std::vector<u16> ord962({0, 1});
      slog::Relation* readrel963 = db->getRelation("eval_ans");
      eval_ansindex915 = readrel963->getIndex(ord962, false);
  
    }
    ReadTask923(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[1];
        slog::join_probe_old<3,1>(evalindex904, evaldelta916, std::array<u64,3>{v_c46, 0, 0}, [&](const std::array<u64,3>& m964) {
          u64 v_c2 = m964[1]; u64 v_c55 = m964[2];
          if (!slog::exists_probe<3,1>(evalindex905, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup56712x86x0x0x0index906, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(eval_ansindex907, eval_ansdelta917, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m965) {
            u64 v_c56 = m965[1];
            slog::join_probe_old<3,1>(evalindex908, evaldelta918, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m966) {
              u64 v_c50 = m966[1]; u64 v_c53 = m966[2];
              slog::join_probe_old<5,2>($sup56712x86x0x0x0index909, $sup56712x86x0x0x0delta919, std::array<u64,5>{v_c2, v_c50, 0, 0, 0}, [&](const std::array<u64,5>& m967) {
                u64 v_c49 = m967[2]; u64 v_c51 = m967[3]; u64 v_c52 = m967[4];
                slog::join_probe_old<4,4>(ifindex910, ifdelta920, std::array<u64,4>{v_c51, v_c52, v_c49, v_c53}, [&](const std::array<u64,4>& m968) {
                  if (!slog::exists_probe<3,2>(evalindex911, std::array<u64,3>{v_c49, v_c2, 0})) return;
                  slog::join_probe_old<4,3>(select_branchindex912, select_branchdelta921, std::array<u64,4>{v_c51, v_c52, v_c54, 0}, [&](const std::array<u64,4>& m969) {
                    u64 v_c37 = m969[3];
                    if (!slog::exists_probe<2,1>(eval_ansindex913, std::array<u64,2>{v_c37, 0})) return;
                    slog::join_probe_old<3,2>(evalindex914, evaldelta922, std::array<u64,3>{v_c49, v_c2, 0}, [&](const std::array<u64,3>& m970) {
                      u64 v_c48 = m970[2];
                      slog::join_probe<2,2>(eval_ansindex915, std::array<u64,2>{v_c48, v_c37}, [&](const std::array<u64,2>& m971) {
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c56}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:87", "delta:select_branch_ans", _fires);
  
      if (!_done)
      {
        ReadTask923* _cont = new ReadTask923(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask923(db,b), false);
  // (crule (pre (let __tconst1pJh47 const5feceb66ffc86f38d952786c)) (scan lst_take __t8UGh49 l n) (body (let __t0SHl48 (lslice l __tconst1pJh47 n))) (head (emit-temp temp9zJ31008 __t0SHl48 __t8UGh49)) list.slog:29 #f)
  class ReadTask972 : public slog::Task
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
      head_rel[0] = db->getRelation("temp9zJ31008");
      outer_rel = db->getRelation("lst_take");
  
    }
    ReadTask972(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c185 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c186 = _t[0];
        u64 v_c166 = _t[1];
        u64 v_c182 = _t[2];
        u64 v_c187 = _prim_lslice(db, v_c166, v_c185, v_c182);
        if (v_c187 == slog_error) { slog::emit_pending_error(db, "list.slog:29"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c187, v_c186});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list.slog:29", "delta:lst_take", _fires);
  
      if (!_done)
      {
        ReadTask972* _cont = new ReadTask972(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask972(db,b), false);
  // (crule (pre (let __tconst3aMB13 const6b86b273ff34fce19d6b804e) (let __trid483D630 const71dc04e9084b526ffd253a28) (let __trel5eGB631 const00b70a53bc33238570e12d7a) (let __tcol5FTK632 const5feceb66ffc86f38d952786c)) (scan freevar x eb) (body (exists lst_absent (2 0 1) 1 x) (exists lambda (2 0 1) 1 eb) (join-old lst_absent_ans (1 0) 1 (1 0) __tconst3aMB13 __t2LT912) (join-old lst_absent (0 2 1) 2 (0 2 1) __t2LT912 x xs) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t89QP11)) (head (tycheck x (accept str) __trid483D630 __trel5eGB631 __tcol5FTK632 (1 2 3 4 0)) (emit freevar (0 1) x __t89QP11)) freevars.slog:28 #f)
  class ReadTask981 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_absentindex973;  slog::Index** lambdaindex974;  slog::Index** lst_absent_ansindex975;  slog::Index** lst_absentindex976;  slog::Index** lambdaindex977;  slog::Index** lst_absent_ansdelta978;  slog::Index** lst_absentdelta979;  slog::Index** lambdadelta980;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("freevar");
      std::vector<u16> ord982({0, 1});
      slog::Relation* readrel983 = db->getRelation("freevar");
      head_index[1] = readrel983->getIndex(ord982, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord984({2, 0, 1});
      slog::Relation* readrel985 = db->getRelation("lst_absent");
      lst_absentindex973 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({2, 0, 1});
      slog::Relation* readrel987 = db->getRelation("lambda");
      lambdaindex974 = readrel987->getIndex(ord986, false);
      std::vector<u16> ord988({1, 0});
      slog::Relation* readrel989 = db->getRelation("lst_absent_ans");
      lst_absent_ansindex975 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({1, 0});
      slog::Relation* readrel991 = db->getRelation("lst_absent_ans");
      lst_absent_ansdelta978 = readrel991->getIndex(ord990, true);
      std::vector<u16> ord992({0, 2, 1});
      slog::Relation* readrel993 = db->getRelation("lst_absent");
      lst_absentindex976 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({0, 2, 1});
      slog::Relation* readrel995 = db->getRelation("lst_absent");
      lst_absentdelta979 = readrel995->getIndex(ord994, true);
      std::vector<u16> ord996({1, 2, 0});
      slog::Relation* readrel997 = db->getRelation("lambda");
      lambdaindex977 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({1, 2, 0});
      slog::Relation* readrel999 = db->getRelation("lambda");
      lambdadelta980 = readrel999->getIndex(ord998, true);
  
    }
    ReadTask981(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c188 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c189 = v_const71dc04e9084b526ffd253a28;
      u64 v_c190 = v_const00b70a53bc33238570e12d7a;
      u64 v_c191 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<3,1>(lst_absentindex973, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex974, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe_old<2,1>(lst_absent_ansindex975, lst_absent_ansdelta978, std::array<u64,2>{v_c188, 0}, [&](const std::array<u64,2>& m1000) {
          u64 v_c192 = m1000[1];
          slog::join_probe_old<3,2>(lst_absentindex976, lst_absentdelta979, std::array<u64,3>{v_c192, v_c6, 0}, [&](const std::array<u64,3>& m1001) {
            u64 v_c167 = m1001[2];
            slog::join_probe_old<3,2>(lambdaindex977, lambdadelta980, std::array<u64,3>{v_c167, v_c3, 0}, [&](const std::array<u64,3>& m1002) {
              u64 v_c193 = m1002[2];
              ++_fires;
              if (!(is_str(v_c6)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c189, v_c190, v_c191, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c6, v_c193}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask981* _cont = new ReadTask981(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask981(db,b), false);
  // (crule (pre) (scan eval_args_ans __t8cVn323 vs) (body (join-old eval_args (0 2 1) 1 (0 2 1) __t8cVn323 c es) (exists app (2 0 1) 1 es) (exists eval (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __5izx673 __t9nj7324) (exists tick (1 2 0) 2 __t9nj7324 c) (join-old app (2 0 1) 2 (2 0 1) es __t9nj7324 ef) (join-old eval (1 2 0) 2 (1 2 0) ef c __t550i320) (exists eval_ans (0 1) 1 __t550i320) (join-old tick (1 2 0) 2 (1 2 0) __t9nj7324 c __t3nAR325) (exists tick_ans (0 1) 1 __t3nAR325) (join eval_ans (0 1) 1 __t550i320 __t2qAJ322) (join-old tick_ans (0 1) 1 (0 1) __t3nAR325 l) (join-old closure (0 1 2) 1 (0 1 2) __t2qAJ322 __t7ycN321 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7ycN321 xs eb)) (head (emit bind_params (0 1 2 3) xs vs l c) (emit call_event (0 1) l c)) interp.slog:48 #f)
  class ReadTask1025 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex1003;  slog::Index** appindex1004;  slog::Index** evalindex1005;  slog::Index** tickindex1006;  slog::Index** evalindex1007;  slog::Index** tickindex1008;  slog::Index** appindex1009;  slog::Index** evalindex1010;  slog::Index** eval_ansindex1011;  slog::Index** tickindex1012;  slog::Index** tick_ansindex1013;  slog::Index** eval_ansindex1014;  slog::Index** tick_ansindex1015;  slog::Index** closureindex1016;  slog::Index** lambdaindex1017;  slog::Index** eval_argsdelta1018;  slog::Index** appdelta1019;  slog::Index** evaldelta1020;  slog::Index** tickdelta1021;  slog::Index** tick_ansdelta1022;  slog::Index** closuredelta1023;  slog::Index** lambdadelta1024;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_params");
      std::vector<u16> ord1026({0, 1, 2, 3});
      slog::Relation* readrel1027 = db->getRelation("bind_params");
      head_index[0] = readrel1027->getIndex(ord1026, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1028({0, 1});
      slog::Relation* readrel1029 = db->getRelation("call_event");
      head_index[1] = readrel1029->getIndex(ord1028, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord1030({0, 2, 1});
      slog::Relation* readrel1031 = db->getRelation("eval_args");
      eval_argsindex1003 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({0, 2, 1});
      slog::Relation* readrel1033 = db->getRelation("eval_args");
      eval_argsdelta1018 = readrel1033->getIndex(ord1032, true);
      std::vector<u16> ord1034({2, 0, 1});
      slog::Relation* readrel1035 = db->getRelation("app");
      appindex1004 = readrel1035->getIndex(ord1034, false);
      std::vector<u16> ord1036({2, 0, 1});
      slog::Relation* readrel1037 = db->getRelation("eval");
      evalindex1005 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({2, 0, 1});
      slog::Relation* readrel1039 = db->getRelation("tick");
      tickindex1006 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({2, 0, 1});
      slog::Relation* readrel1041 = db->getRelation("eval");
      evalindex1007 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({1, 2, 0});
      slog::Relation* readrel1043 = db->getRelation("tick");
      tickindex1008 = readrel1043->getIndex(ord1042, false);
      std::vector<u16> ord1044({2, 0, 1});
      slog::Relation* readrel1045 = db->getRelation("app");
      appindex1009 = readrel1045->getIndex(ord1044, false);
      std::vector<u16> ord1046({2, 0, 1});
      slog::Relation* readrel1047 = db->getRelation("app");
      appdelta1019 = readrel1047->getIndex(ord1046, true);
      std::vector<u16> ord1048({1, 2, 0});
      slog::Relation* readrel1049 = db->getRelation("eval");
      evalindex1010 = readrel1049->getIndex(ord1048, false);
      std::vector<u16> ord1050({1, 2, 0});
      slog::Relation* readrel1051 = db->getRelation("eval");
      evaldelta1020 = readrel1051->getIndex(ord1050, true);
      std::vector<u16> ord1052({0, 1});
      slog::Relation* readrel1053 = db->getRelation("eval_ans");
      eval_ansindex1011 = readrel1053->getIndex(ord1052, false);
      std::vector<u16> ord1054({1, 2, 0});
      slog::Relation* readrel1055 = db->getRelation("tick");
      tickindex1012 = readrel1055->getIndex(ord1054, false);
      std::vector<u16> ord1056({1, 2, 0});
      slog::Relation* readrel1057 = db->getRelation("tick");
      tickdelta1021 = readrel1057->getIndex(ord1056, true);
      std::vector<u16> ord1058({0, 1});
      slog::Relation* readrel1059 = db->getRelation("tick_ans");
      tick_ansindex1013 = readrel1059->getIndex(ord1058, false);
      std::vector<u16> ord1060({0, 1});
      slog::Relation* readrel1061 = db->getRelation("eval_ans");
      eval_ansindex1014 = readrel1061->getIndex(ord1060, false);
      std::vector<u16> ord1062({0, 1});
      slog::Relation* readrel1063 = db->getRelation("tick_ans");
      tick_ansindex1015 = readrel1063->getIndex(ord1062, false);
      std::vector<u16> ord1064({0, 1});
      slog::Relation* readrel1065 = db->getRelation("tick_ans");
      tick_ansdelta1022 = readrel1065->getIndex(ord1064, true);
      std::vector<u16> ord1066({0, 1, 2});
      slog::Relation* readrel1067 = db->getRelation("closure");
      closureindex1016 = readrel1067->getIndex(ord1066, false);
      std::vector<u16> ord1068({0, 1, 2});
      slog::Relation* readrel1069 = db->getRelation("closure");
      closuredelta1023 = readrel1069->getIndex(ord1068, true);
      std::vector<u16> ord1070({0, 1, 2});
      slog::Relation* readrel1071 = db->getRelation("lambda");
      lambdaindex1017 = readrel1071->getIndex(ord1070, false);
      std::vector<u16> ord1072({0, 1, 2});
      slog::Relation* readrel1073 = db->getRelation("lambda");
      lambdadelta1024 = readrel1073->getIndex(ord1072, true);
  
    }
    ReadTask1025(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c164 = _t[0];
        u64 v_c73 = _t[1];
        slog::join_probe_old<3,1>(eval_argsindex1003, eval_argsdelta1018, std::array<u64,3>{v_c164, 0, 0}, [&](const std::array<u64,3>& m1074) {
          u64 v_c2 = m1074[1]; u64 v_c43 = m1074[2];
          if (!slog::exists_probe<3,1>(appindex1004, std::array<u64,3>{v_c43, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex1005, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex1006, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe<3,1>(evalindex1007, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m1075) {
            u64 v_c162 = m1075[1]; u64 v_c163 = m1075[2];
            if (!slog::exists_probe<3,2>(tickindex1008, std::array<u64,3>{v_c163, v_c2, 0})) return;
            slog::join_probe_old<3,2>(appindex1009, appdelta1019, std::array<u64,3>{v_c43, v_c163, 0}, [&](const std::array<u64,3>& m1076) {
              u64 v_c77 = m1076[2];
              slog::join_probe_old<3,2>(evalindex1010, evaldelta1020, std::array<u64,3>{v_c77, v_c2, 0}, [&](const std::array<u64,3>& m1077) {
                u64 v_c161 = m1077[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1011, std::array<u64,2>{v_c161, 0})) return;
                slog::join_probe_old<3,2>(tickindex1012, tickdelta1021, std::array<u64,3>{v_c163, v_c2, 0}, [&](const std::array<u64,3>& m1078) {
                  u64 v_c165 = m1078[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex1013, std::array<u64,2>{v_c165, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1014, std::array<u64,2>{v_c161, 0}, [&](const std::array<u64,2>& m1079) {
                    u64 v_c158 = m1079[1];
                    slog::join_probe_old<2,1>(tick_ansindex1015, tick_ansdelta1022, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m1080) {
                      u64 v_c166 = m1080[1];
                      slog::join_probe_old<3,1>(closureindex1016, closuredelta1023, std::array<u64,3>{v_c158, 0, 0}, [&](const std::array<u64,3>& m1081) {
                        u64 v_c159 = m1081[1]; u64 v_c160 = m1081[2];
                        slog::join_probe_old<3,1>(lambdaindex1017, lambdadelta1024, std::array<u64,3>{v_c159, 0, 0}, [&](const std::array<u64,3>& m1082) {
                          u64 v_c167 = m1082[1]; u64 v_c3 = m1082[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c167, v_c73, v_c166, v_c2}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c166, v_c2}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask1025* _cont = new ReadTask1025(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1025(db,b), false);
  // (crule (pre) (scan eval __t1A8l169 __t2raq168 c) (body (join boolean (0 1) 1 __t2raq168 b)) (head (emit-temp temp6vCQ1007 __t1A8l169 b) (mkstruct boolval (1 0) __t0boW167 b)) interp.slog:27 #f)
  class ReadTask1084 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** booleanindex1083;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6vCQ1007");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1085({0, 1});
      slog::Relation* readrel1086 = db->getRelation("boolean");
      booleanindex1083 = readrel1086->getIndex(ord1085, false);
  
    }
    ReadTask1084(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c194 = _t[0];
        u64 v_c195 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<2,1>(booleanindex1083, std::array<u64,2>{v_c195, 0}, [&](const std::array<u64,2>& m1087) {
          u64 v_c67 = m1087[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c194, v_c67});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c67}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:27", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1084* _cont = new ReadTask1084(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1084(db,b), false);
  // (crule (pre) (scan eval __t7yOw43 __t3ePt42 c) (body (exists eval (2 0 1) 1 c) (join $sup56712x86x0x0x0 (1 0 2 3 4) 2 c __t7yOw43 e1 e2 e3) (join if (2 3 1 0) 4 e2 e3 e1 __t3ePt42) (exists select_branch (2 3 0 1) 2 e2 e3) (join-old eval (1 2 0) 2 (1 2 0) e1 c __t9ATC44) (exists eval_ans (0 1) 1 __t9ATC44) (join-old select_branch (2 3 0 1) 2 (2 3 0 1) e2 e3 __t5q6W45 __v0) (join eval_ans (0 1) 2 __t9ATC44 __v0) (join select_branch_ans (0 1) 1 __t5q6W45 __v1) (join-old eval (1 2 0) 2 (1 2 0) __v1 c __t4U4F46) (join eval_ans (0 1) 1 __t4U4F46 __v2)) (head (emit eval_ans (0 1) __t7yOw43 __v2)) interp.slog:87 #f)
  class ReadTask1102 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1088;  slog::Index** $sup56712x86x0x0x0index1089;  slog::Index** ifindex1090;  slog::Index** select_branchindex1091;  slog::Index** evalindex1092;  slog::Index** eval_ansindex1093;  slog::Index** select_branchindex1094;  slog::Index** eval_ansindex1095;  slog::Index** select_branch_ansindex1096;  slog::Index** evalindex1097;  slog::Index** eval_ansindex1098;  slog::Index** evaldelta1099;  slog::Index** select_branchdelta1100;  slog::Index** evaldelta1101;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1103({0, 1});
      slog::Relation* readrel1104 = db->getRelation("eval_ans");
      head_index[0] = readrel1104->getIndex(ord1103, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1105({2, 0, 1});
      slog::Relation* readrel1106 = db->getRelation("eval");
      evalindex1088 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({1, 0, 2, 3, 4});
      slog::Relation* readrel1108 = db->getRelation("$sup56712x86x0x0x0");
      $sup56712x86x0x0x0index1089 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({2, 3, 1, 0});
      slog::Relation* readrel1110 = db->getRelation("if");
      ifindex1090 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({2, 3, 0, 1});
      slog::Relation* readrel1112 = db->getRelation("select_branch");
      select_branchindex1091 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({1, 2, 0});
      slog::Relation* readrel1114 = db->getRelation("eval");
      evalindex1092 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({1, 2, 0});
      slog::Relation* readrel1116 = db->getRelation("eval");
      evaldelta1099 = readrel1116->getIndex(ord1115, true);
      std::vector<u16> ord1117({0, 1});
      slog::Relation* readrel1118 = db->getRelation("eval_ans");
      eval_ansindex1093 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({2, 3, 0, 1});
      slog::Relation* readrel1120 = db->getRelation("select_branch");
      select_branchindex1094 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({2, 3, 0, 1});
      slog::Relation* readrel1122 = db->getRelation("select_branch");
      select_branchdelta1100 = readrel1122->getIndex(ord1121, true);
      std::vector<u16> ord1123({0, 1});
      slog::Relation* readrel1124 = db->getRelation("eval_ans");
      eval_ansindex1095 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({0, 1});
      slog::Relation* readrel1126 = db->getRelation("select_branch_ans");
      select_branch_ansindex1096 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({1, 2, 0});
      slog::Relation* readrel1128 = db->getRelation("eval");
      evalindex1097 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 2, 0});
      slog::Relation* readrel1130 = db->getRelation("eval");
      evaldelta1101 = readrel1130->getIndex(ord1129, true);
      std::vector<u16> ord1131({0, 1});
      slog::Relation* readrel1132 = db->getRelation("eval_ans");
      eval_ansindex1098 = readrel1132->getIndex(ord1131, false);
  
    }
    ReadTask1102(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c50 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1088, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<5,2>($sup56712x86x0x0x0index1089, std::array<u64,5>{v_c2, v_c50, 0, 0, 0}, [&](const std::array<u64,5>& m1133) {
          u64 v_c49 = m1133[2]; u64 v_c51 = m1133[3]; u64 v_c52 = m1133[4];
          slog::join_probe<4,4>(ifindex1090, std::array<u64,4>{v_c51, v_c52, v_c49, v_c53}, [&](const std::array<u64,4>& m1134) {
            if (!slog::exists_probe<4,2>(select_branchindex1091, std::array<u64,4>{v_c51, v_c52, 0, 0})) return;
            slog::join_probe_old<3,2>(evalindex1092, evaldelta1099, std::array<u64,3>{v_c49, v_c2, 0}, [&](const std::array<u64,3>& m1135) {
              u64 v_c48 = m1135[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1093, std::array<u64,2>{v_c48, 0})) return;
              slog::join_probe_old<4,2>(select_branchindex1094, select_branchdelta1100, std::array<u64,4>{v_c51, v_c52, 0, 0}, [&](const std::array<u64,4>& m1136) {
                u64 v_c54 = m1136[2]; u64 v_c37 = m1136[3];
                slog::join_probe<2,2>(eval_ansindex1095, std::array<u64,2>{v_c48, v_c37}, [&](const std::array<u64,2>& m1137) {
                  slog::join_probe<2,1>(select_branch_ansindex1096, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m1138) {
                    u64 v_c46 = m1138[1];
                    slog::join_probe_old<3,2>(evalindex1097, evaldelta1101, std::array<u64,3>{v_c46, v_c2, 0}, [&](const std::array<u64,3>& m1139) {
                      u64 v_c55 = m1139[2];
                      slog::join_probe<2,1>(eval_ansindex1098, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m1140) {
                        u64 v_c56 = m1140[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c56}, std::array<u16,2>{0, 1});
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
        ReadTask1102* _cont = new ReadTask1102(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1102(db,b), false);
  // (crule (pre) (scan freevar x er) (body (join letrec (2 1 3 0) 1 er y eb __t0mOw146) (neq x y)) (head (emit freevar (0 1) x __t0mOw146)) freevars.slog:24 #f)
  class ReadTask1142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex1141;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1143({0, 1});
      slog::Relation* readrel1144 = db->getRelation("freevar");
      head_index[0] = readrel1144->getIndex(ord1143, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1145({2, 1, 3, 0});
      slog::Relation* readrel1146 = db->getRelation("letrec");
      letrecindex1141 = readrel1146->getIndex(ord1145, false);
  
    }
    ReadTask1142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<4,1>(letrecindex1141, std::array<u64,4>{v_c5, 0, 0, 0}, [&](const std::array<u64,4>& m1147) {
          u64 v_c196 = m1147[1]; u64 v_c3 = m1147[2]; u64 v_c197 = m1147[3];
          if (v_c6 == v_c196) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c197}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:24", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1142* _cont = new ReadTask1142(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1142(db,b), false);
  // (crule (pre (let __tconst3aMB13 const6b86b273ff34fce19d6b804e) (let __trid483D630 const71dc04e9084b526ffd253a28) (let __trel5eGB631 const00b70a53bc33238570e12d7a) (let __tcol5FTK632 const5feceb66ffc86f38d952786c)) (probe lst_absent_ans (1 0) 1 __tconst3aMB13 __t2LT912) (body (join-old lst_absent (0 2 1) 1 (0 2 1) __t2LT912 x xs) (exists lambda (1 2 0) 1 xs) (join freevar (0 1) 1 x eb) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t89QP11)) (head (tycheck x (accept str) __trid483D630 __trel5eGB631 __tcol5FTK632 (1 2 3 4 0)) (emit freevar (0 1) x __t89QP11)) freevars.slog:28 #f)
  class ReadTask1154 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lst_absentindex1148;  slog::Index** lambdaindex1149;  slog::Index** freevarindex1150;  slog::Index** lambdaindex1151;  slog::Index** lst_absentdelta1152;  slog::Index** lambdadelta1153;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("freevar");
      std::vector<u16> ord1155({0, 1});
      slog::Relation* readrel1156 = db->getRelation("freevar");
      head_index[1] = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({1, 0});
      slog::Relation* readrel1158 = db->getRelation("lst_absent_ans");
      driver_index = readrel1158->getIndex(ord1157, true);
      std::vector<u16> ord1159({0, 2, 1});
      slog::Relation* readrel1160 = db->getRelation("lst_absent");
      lst_absentindex1148 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({0, 2, 1});
      slog::Relation* readrel1162 = db->getRelation("lst_absent");
      lst_absentdelta1152 = readrel1162->getIndex(ord1161, true);
      std::vector<u16> ord1163({1, 2, 0});
      slog::Relation* readrel1164 = db->getRelation("lambda");
      lambdaindex1149 = readrel1164->getIndex(ord1163, false);
      std::vector<u16> ord1165({0, 1});
      slog::Relation* readrel1166 = db->getRelation("freevar");
      freevarindex1150 = readrel1166->getIndex(ord1165, false);
      std::vector<u16> ord1167({1, 2, 0});
      slog::Relation* readrel1168 = db->getRelation("lambda");
      lambdaindex1151 = readrel1168->getIndex(ord1167, false);
      std::vector<u16> ord1169({1, 2, 0});
      slog::Relation* readrel1170 = db->getRelation("lambda");
      lambdadelta1153 = readrel1170->getIndex(ord1169, true);
  
    }
    ReadTask1154(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c188 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c189 = v_const71dc04e9084b526ffd253a28;
      u64 v_c190 = v_const00b70a53bc33238570e12d7a;
      u64 v_c191 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c188, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1171) {
        u64 v_c192 = m1171[1];
        if (buckethash(v_c192) != bucket) return;
        slog::join_probe_old<3,1>(lst_absentindex1148, lst_absentdelta1152, std::array<u64,3>{v_c192, 0, 0}, [&](const std::array<u64,3>& m1172) {
          u64 v_c6 = m1172[1]; u64 v_c167 = m1172[2];
          if (!slog::exists_probe<3,1>(lambdaindex1149, std::array<u64,3>{v_c167, 0, 0})) return;
          slog::join_probe<2,1>(freevarindex1150, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m1173) {
            u64 v_c3 = m1173[1];
            slog::join_probe_old<3,2>(lambdaindex1151, lambdadelta1153, std::array<u64,3>{v_c167, v_c3, 0}, [&](const std::array<u64,3>& m1174) {
              u64 v_c193 = m1174[2];
              ++_fires;
              if (!(is_str(v_c6)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c189, v_c190, v_c191, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c6, v_c193}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:lst_absent_ans", _fires);
  
      if (!_done)
      {
        ReadTask1154* _cont = new ReadTask1154(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1154(db,b), false);
  // (crule (pre (let __tconst6TgB206 const6b86b273ff34fce19d6b804e)) (scan lst_absent __t37yX204 l y) (body (let __t6F2W205 (lmem l y)) (cmp lt __t6F2W205 __tconst6TgB206)) (head (emit lst_absent_ans (1 0) __tconst6TgB206 __t37yX204)) list.slog:33 #f)
  class ReadTask1175 : public slog::Task
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
      head_rel[0] = db->getRelation("lst_absent_ans");
      std::vector<u16> ord1176({1, 0});
      slog::Relation* readrel1177 = db->getRelation("lst_absent_ans");
      head_index[0] = readrel1177->getIndex(ord1176, false);
      outer_rel = db->getRelation("lst_absent");
  
    }
    ReadTask1175(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c199 = _t[0];
        u64 v_c166 = _t[1];
        u64 v_c196 = _t[2];
        u64 v_c200 = _prim_lmem(db, v_c166, v_c196);
        if (v_c200 == slog_error) { slog::emit_pending_error(db, "list.slog:33"); return; }
        u64 v_c201 = _prim_lt(db, v_c200, v_c198);
        if (v_c201 == slog_error) { slog::emit_pending_error(db, "list.slog:33"); return; }
        if (!v_c201) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c198, v_c199}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list.slog:33", "delta:lst_absent", _fires);
  
      if (!_done)
      {
        ReadTask1175* _cont = new ReadTask1175(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1175(db,b), false);
  // (crule (pre) (scan binding y cb vy) (body (join freevar (0 1) 1 y __t0Osl187) (join-old lambda (0 1 2) 1 (0 1 2) __t0Osl187 xs eb) (join eval (0 2 1) 0 __2wtW609 c __t5Orx186) (join-old app (0 1 2) 1 (0 1 2) __t5Orx186 ef es)) (head (mkstruct tick (1 2 0) __4U5c610 __t5Orx186 c)) interp.slog:56 #f)
  class ReadTask1185 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1179;  slog::Index** lambdaindex1180;  slog::Index** evalindex1181;  slog::Index** appindex1182;  slog::Index** lambdadelta1183;  slog::Index** appdelta1184;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord1186({0, 1});
      slog::Relation* readrel1187 = db->getRelation("freevar");
      freevarindex1179 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({0, 1, 2});
      slog::Relation* readrel1189 = db->getRelation("lambda");
      lambdaindex1180 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({0, 1, 2});
      slog::Relation* readrel1191 = db->getRelation("lambda");
      lambdadelta1183 = readrel1191->getIndex(ord1190, true);
      std::vector<u16> ord1192({0, 2, 1});
      slog::Relation* readrel1193 = db->getRelation("eval");
      evalindex1181 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({0, 1, 2});
      slog::Relation* readrel1195 = db->getRelation("app");
      appindex1182 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({0, 1, 2});
      slog::Relation* readrel1197 = db->getRelation("app");
      appdelta1184 = readrel1197->getIndex(ord1196, true);
  
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
        u64 v_c196 = _t[0];
        u64 v_c160 = _t[1];
        u64 v_c202 = _t[2];
        slog::join_probe<2,1>(freevarindex1179, std::array<u64,2>{v_c196, 0}, [&](const std::array<u64,2>& m1198) {
          u64 v_c203 = m1198[1];
          slog::join_probe_old<3,1>(lambdaindex1180, lambdadelta1183, std::array<u64,3>{v_c203, 0, 0}, [&](const std::array<u64,3>& m1199) {
            u64 v_c167 = m1199[1]; u64 v_c3 = m1199[2];
            slog::join_all<3>(evalindex1181, [&](const std::array<u64,3>& m1200) {
              u64 v_c204 = m1200[0]; u64 v_c2 = m1200[1]; u64 v_c205 = m1200[2];
              slog::join_probe_old<3,1>(appindex1182, appdelta1184, std::array<u64,3>{v_c205, 0, 0}, [&](const std::array<u64,3>& m1201) {
                u64 v_c77 = m1201[1]; u64 v_c43 = m1201[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c205, v_c2}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:binding", _fires);
  
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
  // (crule (pre (let __tconst5mQl666 constb9e118781cea1f9fa01462e0) (let __tconst7ska196 const06abaa100ecef791ce028c56) (let _00024sqc2bs1547 constd4735e3a265e16eee03f5971) (let _00024sqc3b5Z548 const5feceb66ffc86f38d952786c) (let _00024sqc4cPv549 const6b86b273ff34fce19d6b804e) (let _00024sqo2orM550 const5feceb66ffc86f38d952786c) (let _00024sqo79dC551 const6b86b273ff34fce19d6b804e) (let _00024sqo7ukz552 const6b86b273ff34fce19d6b804e) (let _00024sqo5FdA553 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo79dC551 v2 _00024seq0) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5FdA553 v2 _00024seq0) (letp _00024sql4FKJ545 (aslst _00024seq0)) (letp v1 (lref _00024sql4FKJ545 _00024sqc3b5Z548)) (neq v1 v2) (join $seq_at (1 0 2) 3 _00024sqo2orM550 v1 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7ukz552 v1 _00024seq0) (exists _enum (1 0) 1 __tconst5mQl666) (join delta (1 2 0) 2 __tconst7ska196 _00024seq0 __t0ECW197) (join _enum (1 0) 1 __tconst5mQl666 __t7sei194) (let chk5zbB874 (llen _00024sql4FKJ545)) (eq _00024sqc2bs1547 chk5zbB874) (letp chk1pAl875 (lref _00024sql4FKJ545 _00024sqc4cPv549)) (eq v2 chk1pAl875)) (head (emit-temp temp5E9s870 __t0ECW197) (mkstruct boolval (1 0) __t2gQB195 __t7sei194)) interp.slog:120 #f)
  class ReadTask1210 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex1202;  slog::Index** $seq_atindex1203;  slog::Index** $seq_atrindex1204;  slog::Index** _enumindex1205;  slog::Index** deltaindex1206;  slog::Index** _enumindex1207;  slog::Index** $seq_atrdelta1208;  slog::Index** $seq_atrdelta1209;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5E9s870");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1211({1, 0, 2});
      slog::Relation* readrel1212 = db->getRelation("$seq_at");
      driver_index = readrel1212->getIndex(ord1211, true);
      std::vector<u16> ord1213({1, 0, 2});
      slog::Relation* readrel1214 = db->getRelation("$seq_atr");
      $seq_atrindex1202 = readrel1214->getIndex(ord1213, false);
      std::vector<u16> ord1215({1, 0, 2});
      slog::Relation* readrel1216 = db->getRelation("$seq_atr");
      $seq_atrdelta1208 = readrel1216->getIndex(ord1215, true);
      std::vector<u16> ord1217({1, 0, 2});
      slog::Relation* readrel1218 = db->getRelation("$seq_at");
      $seq_atindex1203 = readrel1218->getIndex(ord1217, false);
      std::vector<u16> ord1219({1, 0, 2});
      slog::Relation* readrel1220 = db->getRelation("$seq_atr");
      $seq_atrindex1204 = readrel1220->getIndex(ord1219, false);
      std::vector<u16> ord1221({1, 0, 2});
      slog::Relation* readrel1222 = db->getRelation("$seq_atr");
      $seq_atrdelta1209 = readrel1222->getIndex(ord1221, true);
      std::vector<u16> ord1223({1, 0});
      slog::Relation* readrel1224 = db->getRelation("_enum");
      _enumindex1205 = readrel1224->getIndex(ord1223, false);
      std::vector<u16> ord1225({1, 2, 0});
      slog::Relation* readrel1226 = db->getRelation("delta");
      deltaindex1206 = readrel1226->getIndex(ord1225, false);
      std::vector<u16> ord1227({1, 0});
      slog::Relation* readrel1228 = db->getRelation("_enum");
      _enumindex1207 = readrel1228->getIndex(ord1227, false);
  
    }
    ReadTask1210(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c132 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c133 = v_const06abaa100ecef791ce028c56;
      u64 v_c134 = v_constd4735e3a265e16eee03f5971;
      u64 v_c135 = v_const5feceb66ffc86f38d952786c;
      u64 v_c136 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c139 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c140 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c138, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1229) {
        u64 v_c143 = m1229[1];
        u64 v_c38 = m1229[2];
        if (buckethash(v_c143) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex1202, $seq_atrdelta1208, std::array<u64,3>{v_c140, v_c143, v_c38}, [&](const std::array<u64,3>& m1230) {
          bool ok1231 = true;
          u64 v_c142 = _prim_aslst(db, v_c38, &ok1231);
          if (!ok1231) return;
          bool ok1232 = true;
          u64 v_c141 = _prim_lref(db, v_c142, v_c135, &ok1232);
          if (!ok1232) return;
          if (v_c141 == v_c143) return;
          slog::join_probe<3,3>($seq_atindex1203, std::array<u64,3>{v_c137, v_c141, v_c38}, [&](const std::array<u64,3>& m1233) {
            slog::join_probe_old<3,3>($seq_atrindex1204, $seq_atrdelta1209, std::array<u64,3>{v_c139, v_c141, v_c38}, [&](const std::array<u64,3>& m1234) {
              if (!slog::exists_probe<2,1>(_enumindex1205, std::array<u64,2>{v_c132, 0})) return;
              slog::join_probe<3,2>(deltaindex1206, std::array<u64,3>{v_c133, v_c38, 0}, [&](const std::array<u64,3>& m1235) {
                u64 v_c144 = m1235[2];
                slog::join_probe<2,1>(_enumindex1207, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m1236) {
                  u64 v_c145 = m1236[1];
                  u64 v_c206 = _prim_llen(db, v_c142);
                  if (v_c206 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c134 != v_c206) return;
                  bool ok1237 = true;
                  u64 v_c207 = _prim_lref(db, v_c142, v_c136, &ok1237);
                  if (!ok1237) return;
                  if (v_c143 != v_c207) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c144});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c145}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:120", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1210* _cont = new ReadTask1210(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1210(db,b), false);
  // (crule (pre) (scan eval __t6uzd177 __t7cos183 c) (body (exists $sup56712x41x0x0x0 (1 0 2 3) 2 c __t6uzd177) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join-old tick (1 2 0) 2 (1 2 0) __t7cos183 c __t8kWT184) (exists tick_ans (0 1) 1 __t8kWT184) (join $sup56712x41x0x0x0 (1 0 2 3) 2 c __t6uzd177 ef es) (join-old app (0 1 2) 3 (0 1 2) __t7cos183 ef es) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t6e44178) (exists eval_ans (0 1) 1 __t6e44178) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6UxD181) (exists eval_args_ans (0 1) 1 __t6UxD181) (join eval_ans (0 1) 1 __t6e44178 __t4yWQ180) (join eval_args_ans (0 1) 1 __t6UxD181 vs) (join tick_ans (0 1) 1 __t8kWT184 __v0) (exists eval (2 0 1) 1 __v0) (join-old closure (0 1 2) 1 (0 1 2) __t4yWQ180 __t7rcY179 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t7rcY179 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t56Is182) (join eval_ans (0 1) 1 __t56Is182 v)) (head (emit eval_ans (0 1) __t6uzd177 v)) interp.slog:42 #f)
  class ReadTask1265 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x41x0x0x0index1238;  slog::Index** evalindex1239;  slog::Index** eval_argsindex1240;  slog::Index** tickindex1241;  slog::Index** tick_ansindex1242;  slog::Index** $sup56712x41x0x0x0index1243;  slog::Index** appindex1244;  slog::Index** eval_argsindex1245;  slog::Index** evalindex1246;  slog::Index** eval_ansindex1247;  slog::Index** eval_argsindex1248;  slog::Index** eval_args_ansindex1249;  slog::Index** eval_ansindex1250;  slog::Index** eval_args_ansindex1251;  slog::Index** tick_ansindex1252;  slog::Index** evalindex1253;  slog::Index** closureindex1254;  slog::Index** lambdaindex1255;  slog::Index** evalindex1256;  slog::Index** eval_ansindex1257;  slog::Index** tickdelta1258;  slog::Index** appdelta1259;  slog::Index** evaldelta1260;  slog::Index** eval_argsdelta1261;  slog::Index** closuredelta1262;  slog::Index** lambdadelta1263;  slog::Index** evaldelta1264;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1266({0, 1});
      slog::Relation* readrel1267 = db->getRelation("eval_ans");
      head_index[0] = readrel1267->getIndex(ord1266, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1268({1, 0, 2, 3});
      slog::Relation* readrel1269 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1238 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({2, 0, 1});
      slog::Relation* readrel1271 = db->getRelation("eval");
      evalindex1239 = readrel1271->getIndex(ord1270, false);
      std::vector<u16> ord1272({2, 0, 1});
      slog::Relation* readrel1273 = db->getRelation("eval_args");
      eval_argsindex1240 = readrel1273->getIndex(ord1272, false);
      std::vector<u16> ord1274({1, 2, 0});
      slog::Relation* readrel1275 = db->getRelation("tick");
      tickindex1241 = readrel1275->getIndex(ord1274, false);
      std::vector<u16> ord1276({1, 2, 0});
      slog::Relation* readrel1277 = db->getRelation("tick");
      tickdelta1258 = readrel1277->getIndex(ord1276, true);
      std::vector<u16> ord1278({0, 1});
      slog::Relation* readrel1279 = db->getRelation("tick_ans");
      tick_ansindex1242 = readrel1279->getIndex(ord1278, false);
      std::vector<u16> ord1280({1, 0, 2, 3});
      slog::Relation* readrel1281 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1243 = readrel1281->getIndex(ord1280, false);
      std::vector<u16> ord1282({0, 1, 2});
      slog::Relation* readrel1283 = db->getRelation("app");
      appindex1244 = readrel1283->getIndex(ord1282, false);
      std::vector<u16> ord1284({0, 1, 2});
      slog::Relation* readrel1285 = db->getRelation("app");
      appdelta1259 = readrel1285->getIndex(ord1284, true);
      std::vector<u16> ord1286({1, 2, 0});
      slog::Relation* readrel1287 = db->getRelation("eval_args");
      eval_argsindex1245 = readrel1287->getIndex(ord1286, false);
      std::vector<u16> ord1288({1, 2, 0});
      slog::Relation* readrel1289 = db->getRelation("eval");
      evalindex1246 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({1, 2, 0});
      slog::Relation* readrel1291 = db->getRelation("eval");
      evaldelta1260 = readrel1291->getIndex(ord1290, true);
      std::vector<u16> ord1292({0, 1});
      slog::Relation* readrel1293 = db->getRelation("eval_ans");
      eval_ansindex1247 = readrel1293->getIndex(ord1292, false);
      std::vector<u16> ord1294({1, 2, 0});
      slog::Relation* readrel1295 = db->getRelation("eval_args");
      eval_argsindex1248 = readrel1295->getIndex(ord1294, false);
      std::vector<u16> ord1296({1, 2, 0});
      slog::Relation* readrel1297 = db->getRelation("eval_args");
      eval_argsdelta1261 = readrel1297->getIndex(ord1296, true);
      std::vector<u16> ord1298({0, 1});
      slog::Relation* readrel1299 = db->getRelation("eval_args_ans");
      eval_args_ansindex1249 = readrel1299->getIndex(ord1298, false);
      std::vector<u16> ord1300({0, 1});
      slog::Relation* readrel1301 = db->getRelation("eval_ans");
      eval_ansindex1250 = readrel1301->getIndex(ord1300, false);
      std::vector<u16> ord1302({0, 1});
      slog::Relation* readrel1303 = db->getRelation("eval_args_ans");
      eval_args_ansindex1251 = readrel1303->getIndex(ord1302, false);
      std::vector<u16> ord1304({0, 1});
      slog::Relation* readrel1305 = db->getRelation("tick_ans");
      tick_ansindex1252 = readrel1305->getIndex(ord1304, false);
      std::vector<u16> ord1306({2, 0, 1});
      slog::Relation* readrel1307 = db->getRelation("eval");
      evalindex1253 = readrel1307->getIndex(ord1306, false);
      std::vector<u16> ord1308({0, 1, 2});
      slog::Relation* readrel1309 = db->getRelation("closure");
      closureindex1254 = readrel1309->getIndex(ord1308, false);
      std::vector<u16> ord1310({0, 1, 2});
      slog::Relation* readrel1311 = db->getRelation("closure");
      closuredelta1262 = readrel1311->getIndex(ord1310, true);
      std::vector<u16> ord1312({0, 1, 2});
      slog::Relation* readrel1313 = db->getRelation("lambda");
      lambdaindex1255 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({0, 1, 2});
      slog::Relation* readrel1315 = db->getRelation("lambda");
      lambdadelta1263 = readrel1315->getIndex(ord1314, true);
      std::vector<u16> ord1316({1, 2, 0});
      slog::Relation* readrel1317 = db->getRelation("eval");
      evalindex1256 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({1, 2, 0});
      slog::Relation* readrel1319 = db->getRelation("eval");
      evaldelta1264 = readrel1319->getIndex(ord1318, true);
      std::vector<u16> ord1320({0, 1});
      slog::Relation* readrel1321 = db->getRelation("eval_ans");
      eval_ansindex1257 = readrel1321->getIndex(ord1320, false);
  
    }
    ReadTask1265(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c208 = _t[0];
        u64 v_c209 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index1238, std::array<u64,4>{v_c2, v_c208, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1239, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex1240, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe_old<3,2>(tickindex1241, tickdelta1258, std::array<u64,3>{v_c209, v_c2, 0}, [&](const std::array<u64,3>& m1322) {
          u64 v_c210 = m1322[2];
          if (!slog::exists_probe<2,1>(tick_ansindex1242, std::array<u64,2>{v_c210, 0})) return;
          slog::join_probe<4,2>($sup56712x41x0x0x0index1243, std::array<u64,4>{v_c2, v_c208, 0, 0}, [&](const std::array<u64,4>& m1323) {
            u64 v_c77 = m1323[2]; u64 v_c43 = m1323[3];
            slog::join_probe_old<3,3>(appindex1244, appdelta1259, std::array<u64,3>{v_c209, v_c77, v_c43}, [&](const std::array<u64,3>& m1324) {
              if (!slog::exists_probe<3,2>(eval_argsindex1245, std::array<u64,3>{v_c43, v_c2, 0})) return;
              slog::join_probe_old<3,2>(evalindex1246, evaldelta1260, std::array<u64,3>{v_c77, v_c2, 0}, [&](const std::array<u64,3>& m1325) {
                u64 v_c211 = m1325[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1247, std::array<u64,2>{v_c211, 0})) return;
                slog::join_probe_old<3,2>(eval_argsindex1248, eval_argsdelta1261, std::array<u64,3>{v_c43, v_c2, 0}, [&](const std::array<u64,3>& m1326) {
                  u64 v_c212 = m1326[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1249, std::array<u64,2>{v_c212, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1250, std::array<u64,2>{v_c211, 0}, [&](const std::array<u64,2>& m1327) {
                    u64 v_c213 = m1327[1];
                    slog::join_probe<2,1>(eval_args_ansindex1251, std::array<u64,2>{v_c212, 0}, [&](const std::array<u64,2>& m1328) {
                      u64 v_c73 = m1328[1];
                      slog::join_probe<2,1>(tick_ansindex1252, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m1329) {
                        u64 v_c37 = m1329[1];
                        if (!slog::exists_probe<3,1>(evalindex1253, std::array<u64,3>{v_c37, 0, 0})) return;
                        slog::join_probe_old<3,1>(closureindex1254, closuredelta1262, std::array<u64,3>{v_c213, 0, 0}, [&](const std::array<u64,3>& m1330) {
                          u64 v_c214 = m1330[1]; u64 v_c160 = m1330[2];
                          slog::join_probe_old<3,1>(lambdaindex1255, lambdadelta1263, std::array<u64,3>{v_c214, 0, 0}, [&](const std::array<u64,3>& m1331) {
                            u64 v_c167 = m1331[1]; u64 v_c3 = m1331[2];
                            slog::join_probe_old<3,2>(evalindex1256, evaldelta1264, std::array<u64,3>{v_c3, v_c37, 0}, [&](const std::array<u64,3>& m1332) {
                              u64 v_c215 = m1332[2];
                              slog::join_probe<2,1>(eval_ansindex1257, std::array<u64,2>{v_c215, 0}, [&](const std::array<u64,2>& m1333) {
                                u64 v_c1 = m1333[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c208, v_c1}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1265* _cont = new ReadTask1265(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1265(db,b), false);
  // (crule (pre) (scan tick_ans __t9uJP175 __v0) (body (join-old tick (0 2 1) 1 (0 2 1) __t9uJP175 c __t6KUR174) (exists $sup56712x41x0x0x0 (1 0 2 3) 1 c) (exists eval_args (2 0 1) 1 c) (join-old eval (2 0 1) 1 (2 0 1) c __t66Yt170 ef) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists eval_ans (0 1) 1 __t66Yt170) (join-old app (0 1 2) 2 (0 1 2) __t6KUR174 ef es) (exists eval_args (1 2 0) 2 es c) (join $sup56712x41x0x0x0 (1 2 3 0) 3 c ef es __d0) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t3FCg173) (exists eval_args_ans (0 1) 1 __t3FCg173) (join eval_ans (0 1) 1 __t66Yt170 __t8UWw172) (join eval_args_ans (0 1) 1 __t3FCg173 vs) (join-old closure (0 1 2) 1 (0 1 2) __t8UWw172 __t3anZ171 cb) (join-old lambda (0 1 2) 1 (0 1 2) __t3anZ171 xs eb)) (head (mkstruct eval (1 2 0) __1JuP642 eb __v0)) interp.slog:42 #f)
  class ReadTask1355 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tickindex1334;  slog::Index** $sup56712x41x0x0x0index1335;  slog::Index** eval_argsindex1336;  slog::Index** evalindex1337;  slog::Index** $sup56712x41x0x0x0index1338;  slog::Index** eval_ansindex1339;  slog::Index** appindex1340;  slog::Index** eval_argsindex1341;  slog::Index** $sup56712x41x0x0x0index1342;  slog::Index** eval_argsindex1343;  slog::Index** eval_args_ansindex1344;  slog::Index** eval_ansindex1345;  slog::Index** eval_args_ansindex1346;  slog::Index** closureindex1347;  slog::Index** lambdaindex1348;  slog::Index** tickdelta1349;  slog::Index** evaldelta1350;  slog::Index** appdelta1351;  slog::Index** eval_argsdelta1352;  slog::Index** closuredelta1353;  slog::Index** lambdadelta1354;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord1356({0, 2, 1});
      slog::Relation* readrel1357 = db->getRelation("tick");
      tickindex1334 = readrel1357->getIndex(ord1356, false);
      std::vector<u16> ord1358({0, 2, 1});
      slog::Relation* readrel1359 = db->getRelation("tick");
      tickdelta1349 = readrel1359->getIndex(ord1358, true);
      std::vector<u16> ord1360({1, 0, 2, 3});
      slog::Relation* readrel1361 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1335 = readrel1361->getIndex(ord1360, false);
      std::vector<u16> ord1362({2, 0, 1});
      slog::Relation* readrel1363 = db->getRelation("eval_args");
      eval_argsindex1336 = readrel1363->getIndex(ord1362, false);
      std::vector<u16> ord1364({2, 0, 1});
      slog::Relation* readrel1365 = db->getRelation("eval");
      evalindex1337 = readrel1365->getIndex(ord1364, false);
      std::vector<u16> ord1366({2, 0, 1});
      slog::Relation* readrel1367 = db->getRelation("eval");
      evaldelta1350 = readrel1367->getIndex(ord1366, true);
      std::vector<u16> ord1368({1, 2, 3, 0});
      slog::Relation* readrel1369 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1338 = readrel1369->getIndex(ord1368, false);
      std::vector<u16> ord1370({0, 1});
      slog::Relation* readrel1371 = db->getRelation("eval_ans");
      eval_ansindex1339 = readrel1371->getIndex(ord1370, false);
      std::vector<u16> ord1372({0, 1, 2});
      slog::Relation* readrel1373 = db->getRelation("app");
      appindex1340 = readrel1373->getIndex(ord1372, false);
      std::vector<u16> ord1374({0, 1, 2});
      slog::Relation* readrel1375 = db->getRelation("app");
      appdelta1351 = readrel1375->getIndex(ord1374, true);
      std::vector<u16> ord1376({1, 2, 0});
      slog::Relation* readrel1377 = db->getRelation("eval_args");
      eval_argsindex1341 = readrel1377->getIndex(ord1376, false);
      std::vector<u16> ord1378({1, 2, 3, 0});
      slog::Relation* readrel1379 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index1342 = readrel1379->getIndex(ord1378, false);
      std::vector<u16> ord1380({1, 2, 0});
      slog::Relation* readrel1381 = db->getRelation("eval_args");
      eval_argsindex1343 = readrel1381->getIndex(ord1380, false);
      std::vector<u16> ord1382({1, 2, 0});
      slog::Relation* readrel1383 = db->getRelation("eval_args");
      eval_argsdelta1352 = readrel1383->getIndex(ord1382, true);
      std::vector<u16> ord1384({0, 1});
      slog::Relation* readrel1385 = db->getRelation("eval_args_ans");
      eval_args_ansindex1344 = readrel1385->getIndex(ord1384, false);
      std::vector<u16> ord1386({0, 1});
      slog::Relation* readrel1387 = db->getRelation("eval_ans");
      eval_ansindex1345 = readrel1387->getIndex(ord1386, false);
      std::vector<u16> ord1388({0, 1});
      slog::Relation* readrel1389 = db->getRelation("eval_args_ans");
      eval_args_ansindex1346 = readrel1389->getIndex(ord1388, false);
      std::vector<u16> ord1390({0, 1, 2});
      slog::Relation* readrel1391 = db->getRelation("closure");
      closureindex1347 = readrel1391->getIndex(ord1390, false);
      std::vector<u16> ord1392({0, 1, 2});
      slog::Relation* readrel1393 = db->getRelation("closure");
      closuredelta1353 = readrel1393->getIndex(ord1392, true);
      std::vector<u16> ord1394({0, 1, 2});
      slog::Relation* readrel1395 = db->getRelation("lambda");
      lambdaindex1348 = readrel1395->getIndex(ord1394, false);
      std::vector<u16> ord1396({0, 1, 2});
      slog::Relation* readrel1397 = db->getRelation("lambda");
      lambdadelta1354 = readrel1397->getIndex(ord1396, true);
  
    }
    ReadTask1355(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c216 = _t[0];
        u64 v_c37 = _t[1];
        slog::join_probe_old<3,1>(tickindex1334, tickdelta1349, std::array<u64,3>{v_c216, 0, 0}, [&](const std::array<u64,3>& m1398) {
          u64 v_c2 = m1398[1]; u64 v_c217 = m1398[2];
          if (!slog::exists_probe<4,1>($sup56712x41x0x0x0index1335, std::array<u64,4>{v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex1336, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe_old<3,1>(evalindex1337, evaldelta1350, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m1399) {
            u64 v_c218 = m1399[1]; u64 v_c77 = m1399[2];
            if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index1338, std::array<u64,4>{v_c2, v_c77, 0, 0})) return;
            if (!slog::exists_probe<2,1>(eval_ansindex1339, std::array<u64,2>{v_c218, 0})) return;
            slog::join_probe_old<3,2>(appindex1340, appdelta1351, std::array<u64,3>{v_c217, v_c77, 0}, [&](const std::array<u64,3>& m1400) {
              u64 v_c43 = m1400[2];
              if (!slog::exists_probe<3,2>(eval_argsindex1341, std::array<u64,3>{v_c43, v_c2, 0})) return;
              slog::join_probe<4,3>($sup56712x41x0x0x0index1342, std::array<u64,4>{v_c2, v_c77, v_c43, 0}, [&](const std::array<u64,4>& m1401) {
                u64 v_c119 = m1401[3];
                slog::join_probe_old<3,2>(eval_argsindex1343, eval_argsdelta1352, std::array<u64,3>{v_c43, v_c2, 0}, [&](const std::array<u64,3>& m1402) {
                  u64 v_c219 = m1402[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1344, std::array<u64,2>{v_c219, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1345, std::array<u64,2>{v_c218, 0}, [&](const std::array<u64,2>& m1403) {
                    u64 v_c220 = m1403[1];
                    slog::join_probe<2,1>(eval_args_ansindex1346, std::array<u64,2>{v_c219, 0}, [&](const std::array<u64,2>& m1404) {
                      u64 v_c73 = m1404[1];
                      slog::join_probe_old<3,1>(closureindex1347, closuredelta1353, std::array<u64,3>{v_c220, 0, 0}, [&](const std::array<u64,3>& m1405) {
                        u64 v_c221 = m1405[1]; u64 v_c160 = m1405[2];
                        slog::join_probe_old<3,1>(lambdaindex1348, lambdadelta1354, std::array<u64,3>{v_c221, 0, 0}, [&](const std::array<u64,3>& m1406) {
                          u64 v_c167 = m1406[1]; u64 v_c3 = m1406[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c37}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:tick_ans", _fires);
  
      if (!_done)
      {
        ReadTask1355* _cont = new ReadTask1355(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1355(db,b), false);
  // (crule (pre) (scan $sup56712x91x0x0x0 __t9U3N373 c eb er x) (body (exists eval (0 2 1) 2 __t9U3N373 c) (exists eval (1 2 0) 2 er c) (exists eval (1 2 0) 2 eb c) (join-old let (2 1 3 0) 3 (2 1 3 0) er x eb __t78XS372) (join-old eval (0 2 1) 3 (0 2 1) __t9U3N373 c __t78XS372) (join-old eval (1 2 0) 2 (1 2 0) er c __t7j91374) (exists eval_ans (0 1) 1 __t7j91374) (join-old eval (1 2 0) 2 (1 2 0) eb c __t3KJV375) (exists eval_ans (0 1) 1 __t3KJV375) (join eval_ans (0 1) 1 __t7j91374 vr) (join eval_ans (0 1) 1 __t3KJV375 v)) (head (emit eval_ans (0 1) __t9U3N373 v)) interp.slog:92 #f)
  class ReadTask1422 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1407;  slog::Index** evalindex1408;  slog::Index** evalindex1409;  slog::Index** letindex1410;  slog::Index** evalindex1411;  slog::Index** evalindex1412;  slog::Index** eval_ansindex1413;  slog::Index** evalindex1414;  slog::Index** eval_ansindex1415;  slog::Index** eval_ansindex1416;  slog::Index** eval_ansindex1417;  slog::Index** letdelta1418;  slog::Index** evaldelta1419;  slog::Index** evaldelta1420;  slog::Index** evaldelta1421;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1423({0, 1});
      slog::Relation* readrel1424 = db->getRelation("eval_ans");
      head_index[0] = readrel1424->getIndex(ord1423, false);
      outer_rel = db->getRelation("$sup56712x91x0x0x0");
      std::vector<u16> ord1425({0, 2, 1});
      slog::Relation* readrel1426 = db->getRelation("eval");
      evalindex1407 = readrel1426->getIndex(ord1425, false);
      std::vector<u16> ord1427({1, 2, 0});
      slog::Relation* readrel1428 = db->getRelation("eval");
      evalindex1408 = readrel1428->getIndex(ord1427, false);
      std::vector<u16> ord1429({1, 2, 0});
      slog::Relation* readrel1430 = db->getRelation("eval");
      evalindex1409 = readrel1430->getIndex(ord1429, false);
      std::vector<u16> ord1431({2, 1, 3, 0});
      slog::Relation* readrel1432 = db->getRelation("let");
      letindex1410 = readrel1432->getIndex(ord1431, false);
      std::vector<u16> ord1433({2, 1, 3, 0});
      slog::Relation* readrel1434 = db->getRelation("let");
      letdelta1418 = readrel1434->getIndex(ord1433, true);
      std::vector<u16> ord1435({0, 2, 1});
      slog::Relation* readrel1436 = db->getRelation("eval");
      evalindex1411 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({0, 2, 1});
      slog::Relation* readrel1438 = db->getRelation("eval");
      evaldelta1419 = readrel1438->getIndex(ord1437, true);
      std::vector<u16> ord1439({1, 2, 0});
      slog::Relation* readrel1440 = db->getRelation("eval");
      evalindex1412 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({1, 2, 0});
      slog::Relation* readrel1442 = db->getRelation("eval");
      evaldelta1420 = readrel1442->getIndex(ord1441, true);
      std::vector<u16> ord1443({0, 1});
      slog::Relation* readrel1444 = db->getRelation("eval_ans");
      eval_ansindex1413 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({1, 2, 0});
      slog::Relation* readrel1446 = db->getRelation("eval");
      evalindex1414 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({1, 2, 0});
      slog::Relation* readrel1448 = db->getRelation("eval");
      evaldelta1421 = readrel1448->getIndex(ord1447, true);
      std::vector<u16> ord1449({0, 1});
      slog::Relation* readrel1450 = db->getRelation("eval_ans");
      eval_ansindex1415 = readrel1450->getIndex(ord1449, false);
      std::vector<u16> ord1451({0, 1});
      slog::Relation* readrel1452 = db->getRelation("eval_ans");
      eval_ansindex1416 = readrel1452->getIndex(ord1451, false);
      std::vector<u16> ord1453({0, 1});
      slog::Relation* readrel1454 = db->getRelation("eval_ans");
      eval_ansindex1417 = readrel1454->getIndex(ord1453, false);
  
    }
    ReadTask1422(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        if (!slog::exists_probe<3,2>(evalindex1407, std::array<u64,3>{v_c4, v_c2, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex1408, std::array<u64,3>{v_c5, v_c2, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex1409, std::array<u64,3>{v_c3, v_c2, 0})) return;
        slog::join_probe_old<4,3>(letindex1410, letdelta1418, std::array<u64,4>{v_c5, v_c6, v_c3, 0}, [&](const std::array<u64,4>& m1455) {
          u64 v_c7 = m1455[3];
          slog::join_probe_old<3,3>(evalindex1411, evaldelta1419, std::array<u64,3>{v_c4, v_c2, v_c7}, [&](const std::array<u64,3>& m1456) {
            slog::join_probe_old<3,2>(evalindex1412, evaldelta1420, std::array<u64,3>{v_c5, v_c2, 0}, [&](const std::array<u64,3>& m1457) {
              u64 v_c8 = m1457[2];
              if (!slog::exists_probe<2,1>(eval_ansindex1413, std::array<u64,2>{v_c8, 0})) return;
              slog::join_probe_old<3,2>(evalindex1414, evaldelta1421, std::array<u64,3>{v_c3, v_c2, 0}, [&](const std::array<u64,3>& m1458) {
                u64 v_c0 = m1458[2];
                if (!slog::exists_probe<2,1>(eval_ansindex1415, std::array<u64,2>{v_c0, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1416, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m1459) {
                  u64 v_c9 = m1459[1];
                  slog::join_probe<2,1>(eval_ansindex1417, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m1460) {
                    u64 v_c1 = m1460[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c1}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:92", "delta:$sup56712x91x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1422* _cont = new ReadTask1422(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1422(db,b), false);
  // (crule (pre (let __tconst0GOL695 const0122baa3ac55f1b433944eb1)) (scan temp50La972 __t2Zbc162) (body (join _enum (1 0) 1 __tconst0GOL695 __t2rtp159) (join boolval (1 0) 1 __t2rtp159 __t5Llk160)) (head (emit delta_ans (0 1) __t2Zbc162 __t5Llk160)) interp.slog:119 #f)
  class ReadTask1463 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1461;  slog::Index** boolvalindex1462;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1464({0, 1});
      slog::Relation* readrel1465 = db->getRelation("delta_ans");
      head_index[0] = readrel1465->getIndex(ord1464, false);
      outer_rel = db->getRelation("temp50La972");
      std::vector<u16> ord1466({1, 0});
      slog::Relation* readrel1467 = db->getRelation("_enum");
      _enumindex1461 = readrel1467->getIndex(ord1466, false);
      std::vector<u16> ord1468({1, 0});
      slog::Relation* readrel1469 = db->getRelation("boolval");
      boolvalindex1462 = readrel1469->getIndex(ord1468, false);
  
    }
    ReadTask1463(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        slog::join_probe<2,1>(_enumindex1461, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m1470) {
          u64 v_c22 = m1470[1];
          slog::join_probe<2,1>(boolvalindex1462, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m1471) {
            u64 v_c222 = m1471[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c222}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:temp50La972", _fires);
  
      if (!_done)
      {
        ReadTask1463* _cont = new ReadTask1463(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1463(db,b), false);
  // (crule (pre (let _00024sqc6SuE404 const6b86b273ff34fce19d6b804e) (let _00024sqc9Utg405 const5feceb66ffc86f38d952786c) (let _00024sqc5uCM406 const6b86b273ff34fce19d6b804e) (let _00024sqc4AZZ407 const5feceb66ffc86f38d952786c) (let __t8LOa148 (lempty))) (scan argument_list _00024seq0) (body (letp _00024sql7x6c402 (aslst _00024seq0)) (let _00024sqn8ZMQ403 (llen _00024sql7x6c402)) (cmp ge _00024sqn8ZMQ403 _00024sqc6SuE404) (let _00024sqp6wOP408 (_0002d _00024sqn8ZMQ403 _00024sqc4AZZ407)) (let es (lslice _00024sql7x6c402 _00024sqc5uCM406 _00024sqp6wOP408)) (join freevar_in_args (1 0) 1 es x) (letp e (lref _00024sql7x6c402 _00024sqc9Utg405))) (head (emit-temp temp9TwZ1009 __t8LOa148 e es x)) freevars.slog:35 #f)
  class ReadTask1473 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevar_in_argsindex1472;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9TwZ1009");
      outer_rel = db->getRelation("argument_list");
      std::vector<u16> ord1474({1, 0});
      slog::Relation* readrel1475 = db->getRelation("freevar_in_args");
      freevar_in_argsindex1472 = readrel1475->getIndex(ord1474, false);
  
    }
    ReadTask1473(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c223 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c224 = v_const5feceb66ffc86f38d952786c;
      u64 v_c225 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
      u64 v_c126 = _prim_lempty(db);
      if (v_c126 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        bool ok1476 = true;
        u64 v_c227 = _prim_aslst(db, v_c38, &ok1476);
        if (!ok1476) return;
        u64 v_c228 = _prim_llen(db, v_c227);
        if (v_c228 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        u64 v_c229 = _prim_ge(db, v_c228, v_c223);
        if (v_c229 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        if (!v_c229) return;
        u64 v_c230 = _prim__0002d(db, v_c228, v_c226);
        if (v_c230 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        u64 v_c43 = _prim_lslice(db, v_c227, v_c225, v_c230);
        if (v_c43 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        slog::join_probe<2,1>(freevar_in_argsindex1472, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m1478) {
          u64 v_c6 = m1478[1];
          bool ok1479 = true;
          u64 v_c29 = _prim_lref(db, v_c227, v_c224, &ok1479);
          if (!ok1479) return;
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c126, v_c29, v_c43, v_c6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:argument_list", _fires);
  
      if (!_done)
      {
        ReadTask1473* _cont = new ReadTask1473(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1473(db,b), false);
  // (crule (pre (let __tconst7wlx292 constdcc297bb3300d9549a9d611a) (let __tconst2XD5276 constf77801bebb40767a1b303d97) (let __tconst4aTz260 const829935b42173b360da35f679) (let __tconst6YSZ252 const8c8656c5d114d7f8b2a412d2) (let __tconst7Bar243 const0388ead47e9d5ccfc5320715) (let __tconst2I8h285 const7297d2085ea0adffc396d546) (let __tconst48zw269 const0933fb667296882d8c45abca) (let __tconst7F8v233 const53a56174f3826669a422fc54) (let __tconst39ZW253 const8ca5d81566f88badd698137a) (let __tconst16Fs254 const879923da020d1533f4d8e921)) (scan temp4QGA962 __t1sga232 __t3DyN290 __t41Z9268 __t4Zol274 __t4xcV257 __t5xQ3284 __t5yWE289 __t9tnf218) (body (exists app (2 0 1) 1 __t9tnf218) (exists ref (1 0) 1 __tconst2XD5276) (exists ref (1 0) 1 __tconst7wlx292) (exists ref (1 0) 1 __tconst7F8v233) (exists ref (1 0) 1 __tconst4aTz260) (exists ref (1 0) 1 __tconst48zw269) (exists ref (1 0) 1 __tconst2I8h285) (exists ref (1 0) 1 __tconst6YSZ252) (exists ref (1 0) 1 __tconst39ZW253) (exists ref (1 0) 1 __tconst16Fs254) (join ref (1 0) 1 __tconst7Bar243 __t8Ely220) (join app (1 2 0) 2 __t8Ely220 __t9tnf218 __t9Hvd221) (join ref (1 0) 1 __tconst2XD5276 __t55Yd223) (join ref (1 0) 1 __tconst7wlx292 __t1iN7225) (join ref (1 0) 1 __tconst7F8v233 __t3grR234) (join ref (1 0) 1 __tconst4aTz260 __t41cT241) (join ref (1 0) 1 __tconst48zw269 __t7uwu270) (join ref (1 0) 1 __tconst2I8h285 __t5wDB286) (join ref (1 0) 1 __tconst6YSZ252 __t7SX3246) (exists if (3 0 1 2) 1 __t7SX3246) (join ref (1 0) 1 __tconst39ZW253 __t1waL248) (join if (2 3 1 0) 2 __t1waL248 __t7SX3246 __t54jO250 __t4Qs4251) (join ref (0 1) 2 __t54jO250 __tconst16Fs254) (let __t5YMF258 (lpush __t4xcV257 __tconst6YSZ252))) (head (emit-temp temp1Z8g963 __t1sga232 __t3DyN290 __t41Z9268 __t4Zol274 __t5YMF258 __t5xQ3284 __t5yWE289 __t9Hvd221) (mkstruct app (1 2 0) __t36Tx287 __t5wDB286 __t5xQ3284) (mkstruct app (1 2 0) __t8kBG271 __t7uwu270 __t41Z9268) (mkstruct app (1 2 0) __t2Un6235 __t3grR234 __t1sga232)) analysis-demo.slog:21 #f)
  class ReadTask1503 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1480;  slog::Index** refindex1481;  slog::Index** refindex1482;  slog::Index** refindex1483;  slog::Index** refindex1484;  slog::Index** refindex1485;  slog::Index** refindex1486;  slog::Index** refindex1487;  slog::Index** refindex1488;  slog::Index** refindex1489;  slog::Index** refindex1490;  slog::Index** appindex1491;  slog::Index** refindex1492;  slog::Index** refindex1493;  slog::Index** refindex1494;  slog::Index** refindex1495;  slog::Index** refindex1496;  slog::Index** refindex1497;  slog::Index** refindex1498;  slog::Index** ifindex1499;  slog::Index** refindex1500;  slog::Index** ifindex1501;  slog::Index** refindex1502;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Z8g963");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      head_rel[3] = db->getRelation("app");
      outer_rel = db->getRelation("temp4QGA962");
      std::vector<u16> ord1504({2, 0, 1});
      slog::Relation* readrel1505 = db->getRelation("app");
      appindex1480 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({1, 0});
      slog::Relation* readrel1507 = db->getRelation("ref");
      refindex1481 = readrel1507->getIndex(ord1506, false);
      std::vector<u16> ord1508({1, 0});
      slog::Relation* readrel1509 = db->getRelation("ref");
      refindex1482 = readrel1509->getIndex(ord1508, false);
      std::vector<u16> ord1510({1, 0});
      slog::Relation* readrel1511 = db->getRelation("ref");
      refindex1483 = readrel1511->getIndex(ord1510, false);
      std::vector<u16> ord1512({1, 0});
      slog::Relation* readrel1513 = db->getRelation("ref");
      refindex1484 = readrel1513->getIndex(ord1512, false);
      std::vector<u16> ord1514({1, 0});
      slog::Relation* readrel1515 = db->getRelation("ref");
      refindex1485 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({1, 0});
      slog::Relation* readrel1517 = db->getRelation("ref");
      refindex1486 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({1, 0});
      slog::Relation* readrel1519 = db->getRelation("ref");
      refindex1487 = readrel1519->getIndex(ord1518, false);
      std::vector<u16> ord1520({1, 0});
      slog::Relation* readrel1521 = db->getRelation("ref");
      refindex1488 = readrel1521->getIndex(ord1520, false);
      std::vector<u16> ord1522({1, 0});
      slog::Relation* readrel1523 = db->getRelation("ref");
      refindex1489 = readrel1523->getIndex(ord1522, false);
      std::vector<u16> ord1524({1, 0});
      slog::Relation* readrel1525 = db->getRelation("ref");
      refindex1490 = readrel1525->getIndex(ord1524, false);
      std::vector<u16> ord1526({1, 2, 0});
      slog::Relation* readrel1527 = db->getRelation("app");
      appindex1491 = readrel1527->getIndex(ord1526, false);
      std::vector<u16> ord1528({1, 0});
      slog::Relation* readrel1529 = db->getRelation("ref");
      refindex1492 = readrel1529->getIndex(ord1528, false);
      std::vector<u16> ord1530({1, 0});
      slog::Relation* readrel1531 = db->getRelation("ref");
      refindex1493 = readrel1531->getIndex(ord1530, false);
      std::vector<u16> ord1532({1, 0});
      slog::Relation* readrel1533 = db->getRelation("ref");
      refindex1494 = readrel1533->getIndex(ord1532, false);
      std::vector<u16> ord1534({1, 0});
      slog::Relation* readrel1535 = db->getRelation("ref");
      refindex1495 = readrel1535->getIndex(ord1534, false);
      std::vector<u16> ord1536({1, 0});
      slog::Relation* readrel1537 = db->getRelation("ref");
      refindex1496 = readrel1537->getIndex(ord1536, false);
      std::vector<u16> ord1538({1, 0});
      slog::Relation* readrel1539 = db->getRelation("ref");
      refindex1497 = readrel1539->getIndex(ord1538, false);
      std::vector<u16> ord1540({1, 0});
      slog::Relation* readrel1541 = db->getRelation("ref");
      refindex1498 = readrel1541->getIndex(ord1540, false);
      std::vector<u16> ord1542({3, 0, 1, 2});
      slog::Relation* readrel1543 = db->getRelation("if");
      ifindex1499 = readrel1543->getIndex(ord1542, false);
      std::vector<u16> ord1544({1, 0});
      slog::Relation* readrel1545 = db->getRelation("ref");
      refindex1500 = readrel1545->getIndex(ord1544, false);
      std::vector<u16> ord1546({2, 3, 1, 0});
      slog::Relation* readrel1547 = db->getRelation("if");
      ifindex1501 = readrel1547->getIndex(ord1546, false);
      std::vector<u16> ord1548({0, 1});
      slog::Relation* readrel1549 = db->getRelation("ref");
      refindex1502 = readrel1549->getIndex(ord1548, false);
  
    }
    ReadTask1503(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c80 = v_constdcc297bb3300d9549a9d611a;
      u64 v_c81 = v_constf77801bebb40767a1b303d97;
      u64 v_c82 = v_const829935b42173b360da35f679;
      u64 v_c84 = v_const8c8656c5d114d7f8b2a412d2;
      u64 v_c85 = v_const0388ead47e9d5ccfc5320715;
      u64 v_c86 = v_const7297d2085ea0adffc396d546;
      u64 v_c88 = v_const0933fb667296882d8c45abca;
      u64 v_c90 = v_const53a56174f3826669a422fc54;
      u64 v_c83 = v_const8ca5d81566f88badd698137a;
      u64 v_c89 = v_const879923da020d1533f4d8e921;
  
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
        u64 v_c116 = _t[0];
        u64 v_c92 = _t[1];
        u64 v_c114 = _t[2];
        u64 v_c93 = _t[3];
        u64 v_c115 = _t[4];
        u64 v_c113 = _t[5];
        u64 v_c94 = _t[6];
        u64 v_c99 = _t[7];
        if (!slog::exists_probe<3,1>(appindex1480, std::array<u64,3>{v_c99, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1481, std::array<u64,2>{v_c81, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1482, std::array<u64,2>{v_c80, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1483, std::array<u64,2>{v_c90, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1484, std::array<u64,2>{v_c82, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1485, std::array<u64,2>{v_c88, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1486, std::array<u64,2>{v_c86, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1487, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1488, std::array<u64,2>{v_c83, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1489, std::array<u64,2>{v_c89, 0})) return;
        slog::join_probe<2,1>(refindex1490, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m1550) {
          u64 v_c100 = m1550[1];
          slog::join_probe<3,2>(appindex1491, std::array<u64,3>{v_c100, v_c99, 0}, [&](const std::array<u64,3>& m1551) {
            u64 v_c231 = m1551[2];
            slog::join_probe<2,1>(refindex1492, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m1552) {
              u64 v_c101 = m1552[1];
              slog::join_probe<2,1>(refindex1493, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m1553) {
                u64 v_c102 = m1553[1];
                slog::join_probe<2,1>(refindex1494, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m1554) {
                  u64 v_c105 = m1554[1];
                  slog::join_probe<2,1>(refindex1495, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m1555) {
                    u64 v_c106 = m1555[1];
                    slog::join_probe<2,1>(refindex1496, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m1556) {
                      u64 v_c111 = m1556[1];
                      slog::join_probe<2,1>(refindex1497, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m1557) {
                        u64 v_c112 = m1557[1];
                        slog::join_probe<2,1>(refindex1498, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m1558) {
                          u64 v_c107 = m1558[1];
                          if (!slog::exists_probe<4,1>(ifindex1499, std::array<u64,4>{v_c107, 0, 0, 0})) return;
                          slog::join_probe<2,1>(refindex1500, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m1559) {
                            u64 v_c108 = m1559[1];
                            slog::join_probe<4,2>(ifindex1501, std::array<u64,4>{v_c108, v_c107, 0, 0}, [&](const std::array<u64,4>& m1560) {
                              u64 v_c109 = m1560[2]; u64 v_c110 = m1560[3];
                              slog::join_probe<2,2>(refindex1502, std::array<u64,2>{v_c109, v_c89}, [&](const std::array<u64,2>& m1561) {
                                u64 v_c232 = _prim_lpush(db, v_c115, v_c84);
                                if (v_c232 == slog_error) { slog::emit_pending_error(db, "analysis-demo.slog:21"); return; }
                                ++_fires;
                                slog::emit_temp<8>(head_rel[0], newbatch[0], std::array<u64,8>{v_c116, v_c92, v_c114, v_c93, v_c232, v_c113, v_c94, v_c231});
                                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c112, v_c113}, std::array<u16,3>{1, 2, 0});
                                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c111, v_c114}, std::array<u16,3>{1, 2, 0});
                                slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c105, v_c116}, std::array<u16,3>{1, 2, 0});
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
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("analysis-demo.slog:21", "delta:temp4QGA962", _fires);
  
      if (!_done)
      {
        ReadTask1503* _cont = new ReadTask1503(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1503(db,b), false);
  // (crule (pre) (scan toint_range __erre8a5Y828 __errf5CQ5829 __errf41jV830) (body) (head (emit error (0) __erre8a5Y828)) <internal>:1 #f)
  class ReadTask1562 : public slog::Task
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
      std::vector<u16> ord1563({0});
      slog::Relation* readrel1564 = db->getRelation("error");
      head_index[0] = readrel1564->getIndex(ord1563, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask1562(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c233 = _t[0];
        u64 v_c234 = _t[1];
        u64 v_c235 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c233}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask1562* _cont = new ReadTask1562(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1562(db,b), false);
}

