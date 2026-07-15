
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0457bba0679825d285ef7fa5;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const119eb3a23d030ee0dfe9f807;
extern u64 v_const37664d5895f78758ec8e94e4;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5d1d34d1b1718cd7c9f1ee55;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const889c19fd926bc4ca61c0b4d9;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_consta05447c5b6502c5938db0f77;
extern u64 v_consta81ad7556291f9defc5163ec;
extern u64 v_constaee3d30407ccfb32dbb15266;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_conste90c92f3e6c3b47a7bc93e42;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_consteefaed435882b14b69e99d78;


void slog_rules_cfbd336767c33cec1(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst65GN810 const0122baa3ac55f1b433944eb1) (let __tconst3VNs307 const06abaa100ecef791ce028c56) (let _00024sqc89jA519 constd4735e3a265e16eee03f5971) (let _00024sqc5bE7520 const5feceb66ffc86f38d952786c) (let _00024sqc5WD6521 const6b86b273ff34fce19d6b804e) (let _00024sqo7nH0522 const5feceb66ffc86f38d952786c) (let _00024sqo8HCy523 const6b86b273ff34fce19d6b804e) (let _00024sqo1Uwu524 const6b86b273ff34fce19d6b804e) (let _00024sqo9OPL525 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo8HCy523 __t5ERV310 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7nH0522 __t5ERV310 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Uwu524 __t5ERV310 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9OPL525 __t5ERV310 _00024seq2) (exists _enum (1 0) 1 __tconst65GN810) (join delta (1 2 0) 2 __tconst3VNs307 _00024seq2 __t5HIm308) (join _enum (1 0) 1 __tconst65GN810 __t26fz305) (join symval (0 1) 1 __t5ERV310 s) (letp _00024sql2wmw517 (aslst _00024seq2)) (let chk86mS1155 (llen _00024sql2wmw517)) (eq _00024sqc89jA519 chk86mS1155) (letp chk9U7n1156 (lref _00024sql2wmw517 _00024sqc5bE7520)) (eq __t5ERV310 chk9U7n1156) (letp chk820y1157 (lref _00024sql2wmw517 _00024sqc5WD6521)) (eq __t5ERV310 chk820y1157)) (head (emit-temp temp0P9u1146 __t5HIm308) (mkstruct boolval (1 0) __t7uE5306 __t26fz305)) interp.slog:117 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex0;  slog::Index** $seq_atrindex1;  slog::Index** $seq_atrindex2;  slog::Index** _enumindex3;  slog::Index** deltaindex4;  slog::Index** _enumindex5;  slog::Index** symvalindex6;  slog::Index** $seq_atrdelta7;  slog::Index** $seq_atrdelta8;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0P9u1146");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord10({1, 0, 2});
      slog::Relation* readrel11 = db->getRelation("$seq_at");
      driver_index = readrel11->getIndex(ord10, true);
      std::vector<u16> ord12({1, 0, 2});
      slog::Relation* readrel13 = db->getRelation("$seq_at");
      $seq_atindex0 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0, 2});
      slog::Relation* readrel15 = db->getRelation("$seq_atr");
      $seq_atrindex1 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0, 2});
      slog::Relation* readrel17 = db->getRelation("$seq_atr");
      $seq_atrdelta7 = readrel17->getIndex(ord16, true);
      std::vector<u16> ord18({1, 0, 2});
      slog::Relation* readrel19 = db->getRelation("$seq_atr");
      $seq_atrindex2 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 0, 2});
      slog::Relation* readrel21 = db->getRelation("$seq_atr");
      $seq_atrdelta8 = readrel21->getIndex(ord20, true);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("_enum");
      _enumindex3 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 2, 0});
      slog::Relation* readrel25 = db->getRelation("delta");
      deltaindex4 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 0});
      slog::Relation* readrel27 = db->getRelation("_enum");
      _enumindex5 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("symval");
      symvalindex6 = readrel29->getIndex(ord28, false);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c1 = v_const06abaa100ecef791ce028c56;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c6, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m30) {
        u64 v_c9 = m30[1];
        u64 v_c10 = m30[2];
        if (buckethash(v_c9) != bucket) return;
        slog::join_probe<3,3>($seq_atindex0, std::array<u64,3>{v_c5, v_c9, v_c10}, [&](const std::array<u64,3>& m31) {
          slog::join_probe_old<3,3>($seq_atrindex1, $seq_atrdelta7, std::array<u64,3>{v_c7, v_c9, v_c10}, [&](const std::array<u64,3>& m32) {
            slog::join_probe_old<3,3>($seq_atrindex2, $seq_atrdelta8, std::array<u64,3>{v_c8, v_c9, v_c10}, [&](const std::array<u64,3>& m33) {
              if (!slog::exists_probe<2,1>(_enumindex3, std::array<u64,2>{v_c0, 0})) return;
              slog::join_probe<3,2>(deltaindex4, std::array<u64,3>{v_c1, v_c10, 0}, [&](const std::array<u64,3>& m34) {
                u64 v_c11 = m34[2];
                slog::join_probe<2,1>(_enumindex5, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m35) {
                  u64 v_c12 = m35[1];
                  slog::join_probe<2,1>(symvalindex6, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m36) {
                    u64 v_c13 = m36[1];
                    bool ok37 = true;
                    u64 v_c14 = _prim_aslst(db, v_c10, &ok37);
                    if (!ok37) return;
                    u64 v_c15 = _prim_llen(db, v_c14);
                    if (v_c15 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c2 != v_c15) return;
                    bool ok38 = true;
                    u64 v_c16 = _prim_lref(db, v_c14, v_c3, &ok38);
                    if (!ok38) return;
                    if (v_c9 != v_c16) return;
                    bool ok39 = true;
                    u64 v_c17 = _prim_lref(db, v_c14, v_c4, &ok39);
                    if (!ok39) return;
                    if (v_c9 != v_c17) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c11});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:$seq_at", _fires);
  
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
  // (crule (pre) (scan temp8zAf1176 __t6Vjn123 c m site) (body (let __t1MuT124 (lpush __t6Vjn123 site))) (head (emit-temp temp2sam1177 __t1MuT124 c m)) context.slog:10 #f)
  class ReadTask40 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2sam1177");
      outer_rel = db->getRelation("temp8zAf1176");
  
    }
    ReadTask40(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c20 = _t[2];
        u64 v_c21 = _t[3];
        u64 v_c22 = _prim_lpush(db, v_c18, v_c21);
        if (v_c22 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c22, v_c19, v_c20});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:temp8zAf1176", _fires);
  
      if (!_done)
      {
        ReadTask40* _cont = new ReadTask40(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask40(db,b), false);
  // (crule (pre (let __tconst1UOH427 const0457bba0679825d285ef7fa5)) (scan temp9V7J1172 __t0QD8426 __t5V4O405) (body (join ref (1 0) 1 __tconst1UOH427 __t4O08407)) (head (emit-temp temp0Cgl1173 __t0QD8426 __t5V4O405) (mkstruct app (1 2 0) __t2wub408 __t4O08407 __t5V4O405)) schemecfa.slog:26 #f)
  class ReadTask42 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex41;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Cgl1173");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp9V7J1172");
      std::vector<u16> ord43({1, 0});
      slog::Relation* readrel44 = db->getRelation("ref");
      refindex41 = readrel44->getIndex(ord43, false);
  
    }
    ReadTask42(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_const0457bba0679825d285ef7fa5;
  
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
        slog::join_probe<2,1>(refindex41, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m45) {
          u64 v_c26 = m45[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c24, v_c25});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c26, v_c25}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:26", "delta:temp9V7J1172", _fires);
  
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
  // (crule (pre) (scan eval __t2QyE111 __t1Lm9110 c) (body (join app (0 1 2) 1 __t1Lm9110 ef es)) (head (emit $sup56712x74x0x0x0 (0 1 2 3) __t2QyE111 c ef es)) interp.slog:75 #f)
  class ReadTask47 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex46;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup56712x74x0x0x0");
      std::vector<u16> ord48({0, 1, 2, 3});
      slog::Relation* readrel49 = db->getRelation("$sup56712x74x0x0x0");
      head_index[0] = readrel49->getIndex(ord48, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord50({0, 1, 2});
      slog::Relation* readrel51 = db->getRelation("app");
      appindex46 = readrel51->getIndex(ord50, false);
  
    }
    ReadTask47(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[2];
        slog::join_probe<3,1>(appindex46, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m52) {
          u64 v_c29 = m52[1]; u64 v_c30 = m52[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c27, v_c19, v_c29, v_c30}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:75", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask47* _cont = new ReadTask47(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask47(db,b), false);
  // (crule (pre (let __tconst5USv771 const0122baa3ac55f1b433944eb1) (let __tconst16Oe187 const06abaa100ecef791ce028c56) (let _00024sqc3CAR589 constd4735e3a265e16eee03f5971) (let _00024sqc4mHp590 const5feceb66ffc86f38d952786c) (let _00024sqc7zL8591 const6b86b273ff34fce19d6b804e) (let _00024sqo2ych592 const5feceb66ffc86f38d952786c) (let _00024sqo3d3H593 const6b86b273ff34fce19d6b804e) (let _00024sqo5WJE594 const6b86b273ff34fce19d6b804e) (let _00024sqo4b4d595 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo2ych592 __t76ef190 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo3d3H593 __t76ef190 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5WJE594 __t76ef190 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4b4d595 __t76ef190 _00024seq2) (exists _enum (1 0) 1 __tconst5USv771) (join delta (1 2 0) 2 __tconst16Oe187 _00024seq2 __t4OrE188) (join _enum (1 0) 1 __tconst5USv771 __t6FbR185) (join prim (0 1) 1 __t76ef190 op) (letp _00024sql3Mb9587 (aslst _00024seq2)) (let chk7EVx1064 (llen _00024sql3Mb9587)) (eq _00024sqc3CAR589 chk7EVx1064) (letp chk6VHT1065 (lref _00024sql3Mb9587 _00024sqc4mHp590)) (eq __t76ef190 chk6VHT1065) (letp chk4LZU1066 (lref _00024sql3Mb9587 _00024sqc7zL8591)) (eq __t76ef190 chk4LZU1066)) (head (emit-temp temp56SH1058 __t4OrE188) (mkstruct boolval (1 0) __t6RYP186 __t6FbR185)) interp.slog:119 #f)
  class ReadTask63 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex53;  slog::Index** $seq_atrindex54;  slog::Index** $seq_atrindex55;  slog::Index** _enumindex56;  slog::Index** deltaindex57;  slog::Index** _enumindex58;  slog::Index** primindex59;  slog::Index** $seq_atdelta60;  slog::Index** $seq_atrdelta61;  slog::Index** $seq_atrdelta62;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp56SH1058");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord64({1, 0, 2});
      slog::Relation* readrel65 = db->getRelation("$seq_at");
      driver_index = readrel65->getIndex(ord64, true);
      std::vector<u16> ord66({1, 0, 2});
      slog::Relation* readrel67 = db->getRelation("$seq_at");
      $seq_atindex53 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 0, 2});
      slog::Relation* readrel69 = db->getRelation("$seq_at");
      $seq_atdelta60 = readrel69->getIndex(ord68, true);
      std::vector<u16> ord70({1, 0, 2});
      slog::Relation* readrel71 = db->getRelation("$seq_atr");
      $seq_atrindex54 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 0, 2});
      slog::Relation* readrel73 = db->getRelation("$seq_atr");
      $seq_atrdelta61 = readrel73->getIndex(ord72, true);
      std::vector<u16> ord74({1, 0, 2});
      slog::Relation* readrel75 = db->getRelation("$seq_atr");
      $seq_atrindex55 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({1, 0, 2});
      slog::Relation* readrel77 = db->getRelation("$seq_atr");
      $seq_atrdelta62 = readrel77->getIndex(ord76, true);
      std::vector<u16> ord78({1, 0});
      slog::Relation* readrel79 = db->getRelation("_enum");
      _enumindex56 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 2, 0});
      slog::Relation* readrel81 = db->getRelation("delta");
      deltaindex57 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 0});
      slog::Relation* readrel83 = db->getRelation("_enum");
      _enumindex58 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({0, 1});
      slog::Relation* readrel85 = db->getRelation("prim");
      primindex59 = readrel85->getIndex(ord84, false);
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_const0122baa3ac55f1b433944eb1;
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
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c36, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m86) {
        u64 v_c40 = m86[1];
        u64 v_c10 = m86[2];
        if (buckethash(v_c40) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex53, $seq_atdelta60, std::array<u64,3>{v_c37, v_c40, v_c10}, [&](const std::array<u64,3>& m87) {
          slog::join_probe_old<3,3>($seq_atrindex54, $seq_atrdelta61, std::array<u64,3>{v_c38, v_c40, v_c10}, [&](const std::array<u64,3>& m88) {
            slog::join_probe_old<3,3>($seq_atrindex55, $seq_atrdelta62, std::array<u64,3>{v_c39, v_c40, v_c10}, [&](const std::array<u64,3>& m89) {
              if (!slog::exists_probe<2,1>(_enumindex56, std::array<u64,2>{v_c31, 0})) return;
              slog::join_probe<3,2>(deltaindex57, std::array<u64,3>{v_c32, v_c10, 0}, [&](const std::array<u64,3>& m90) {
                u64 v_c41 = m90[2];
                slog::join_probe<2,1>(_enumindex58, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m91) {
                  u64 v_c42 = m91[1];
                  slog::join_probe<2,1>(primindex59, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m92) {
                    u64 v_c43 = m92[1];
                    bool ok93 = true;
                    u64 v_c44 = _prim_aslst(db, v_c10, &ok93);
                    if (!ok93) return;
                    u64 v_c45 = _prim_llen(db, v_c44);
                    if (v_c45 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                    if (v_c33 != v_c45) return;
                    bool ok94 = true;
                    u64 v_c46 = _prim_lref(db, v_c44, v_c34, &ok94);
                    if (!ok94) return;
                    if (v_c40 != v_c46) return;
                    bool ok95 = true;
                    u64 v_c47 = _prim_lref(db, v_c44, v_c35, &ok95);
                    if (!ok95) return;
                    if (v_c40 != v_c47) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c41});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c42}, std::array<u16,2>{1, 0});
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
  // (crule (pre) (scan binding y cb vy) (body (join-old freevar (0 1) 1 (0 1) y __t8ny9128) (join-old lambda (0 1 2) 1 (0 1 2) __t8ny9128 xs eb) (join-old eval (0 2 1) 0 (0 2 1) __1mVf736 c __t8Z3R127) (join-old app (0 1 2) 1 (0 1 2) __t8Z3R127 ef es)) (head (mkstruct eval (1 2 0) __8uDI737 ef c)) interp.slog:56 #f)
  class ReadTask104 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex96;  slog::Index** lambdaindex97;  slog::Index** evalindex98;  slog::Index** appindex99;  slog::Index** freevardelta100;  slog::Index** lambdadelta101;  slog::Index** evaldelta102;  slog::Index** appdelta103;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("binding");
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("freevar");
      freevarindex96 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("freevar");
      freevardelta100 = readrel108->getIndex(ord107, true);
      std::vector<u16> ord109({0, 1, 2});
      slog::Relation* readrel110 = db->getRelation("lambda");
      lambdaindex97 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 1, 2});
      slog::Relation* readrel112 = db->getRelation("lambda");
      lambdadelta101 = readrel112->getIndex(ord111, true);
      std::vector<u16> ord113({0, 2, 1});
      slog::Relation* readrel114 = db->getRelation("eval");
      evalindex98 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 2, 1});
      slog::Relation* readrel116 = db->getRelation("eval");
      evaldelta102 = readrel116->getIndex(ord115, true);
      std::vector<u16> ord117({0, 1, 2});
      slog::Relation* readrel118 = db->getRelation("app");
      appindex99 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({0, 1, 2});
      slog::Relation* readrel120 = db->getRelation("app");
      appdelta103 = readrel120->getIndex(ord119, true);
  
    }
    ReadTask104(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(freevarindex96, freevardelta100, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m121) {
          u64 v_c51 = m121[1];
          slog::join_probe_old<3,1>(lambdaindex97, lambdadelta101, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m122) {
            u64 v_c52 = m122[1]; u64 v_c53 = m122[2];
            slog::join_all_old<3>(evalindex98, evaldelta102, [&](const std::array<u64,3>& m123) {
              u64 v_c54 = m123[0]; u64 v_c19 = m123[1]; u64 v_c55 = m123[2];
              slog::join_probe_old<3,1>(appindex99, appdelta103, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m124) {
                u64 v_c29 = m124[1]; u64 v_c30 = m124[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c29, v_c19}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:binding", _fires);
  
      if (!_done)
      {
        ReadTask104* _cont = new ReadTask104(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask104(db,b), false);
  // (crule (pre) (scan select_branch __t97Cg3 tv e2 e3) (body (join scheme_false (0) 0 fv) (neq tv fv)) (head (emit select_branch_ans (0 1) __t97Cg3 e2)) interp.slog:85 #f)
  class ReadTask126 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** scheme_falseindex125;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord127({0, 1});
      slog::Relation* readrel128 = db->getRelation("select_branch_ans");
      head_index[0] = readrel128->getIndex(ord127, false);
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord129({0});
      slog::Relation* readrel130 = db->getRelation("scheme_false");
      scheme_falseindex125 = readrel130->getIndex(ord129, false);
  
    }
    ReadTask126(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[3];
        slog::join_all<1>(scheme_falseindex125, [&](const std::array<u64,1>& m131) {
          u64 v_c60 = m131[0];
          if (v_c57 == v_c60) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c56, v_c58}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:85", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask126* _cont = new ReadTask126(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask126(db,b), false);
  // (crule (pre (let __tconst04ab676 constcd2a69ce5ca278db1d6da969) (let _00024sqc0NDP645 constd4735e3a265e16eee03f5971) (let _00024sqc7bIa646 const5feceb66ffc86f38d952786c) (let _00024sqc1Uf7647 const6b86b273ff34fce19d6b804e) (let _00024sqo7IWL648 const5feceb66ffc86f38d952786c) (let _00024sqo5kNQ649 const6b86b273ff34fce19d6b804e) (let _00024sqo9k7p650 const6b86b273ff34fce19d6b804e) (let _00024sqo7Xo2651 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo5kNQ649 __t2qlr318 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7IWL648 __t2qlr318 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9k7p650 __t2qlr318 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7Xo2651 __t2qlr318 _00024seq2) (join _enum (0 1) 2 __t2qlr318 __tconst04ab676) (join delta (2 0 1) 1 _00024seq2 __t6QsA316 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql2g05643 (aslst _00024seq2)) (let chk47BN1021 (llen _00024sql2g05643)) (eq _00024sqc0NDP645 chk47BN1021) (letp chk8l8e1022 (lref _00024sql2g05643 _00024sqc7bIa646)) (eq __t2qlr318 chk8l8e1022) (letp chk0n0G1023 (lref _00024sql2g05643 _00024sqc1Uf7647)) (eq __t2qlr318 chk0n0G1023)) (head (emit-temp temp53FS1015 __t6QsA316 b) (mkstruct boolval (1 0) __t3y4C315 b)) interp.slog:112 #f)
  class ReadTask141 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex132;  slog::Index** $seq_atrindex133;  slog::Index** $seq_atrindex134;  slog::Index** _enumindex135;  slog::Index** deltaindex136;  slog::Index** comparison_opindex137;  slog::Index** any_boolindex138;  slog::Index** $seq_atrdelta139;  slog::Index** $seq_atrdelta140;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp53FS1015");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord142({1, 0, 2});
      slog::Relation* readrel143 = db->getRelation("$seq_at");
      driver_index = readrel143->getIndex(ord142, true);
      std::vector<u16> ord144({1, 0, 2});
      slog::Relation* readrel145 = db->getRelation("$seq_at");
      $seq_atindex132 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({1, 0, 2});
      slog::Relation* readrel147 = db->getRelation("$seq_atr");
      $seq_atrindex133 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 0, 2});
      slog::Relation* readrel149 = db->getRelation("$seq_atr");
      $seq_atrdelta139 = readrel149->getIndex(ord148, true);
      std::vector<u16> ord150({1, 0, 2});
      slog::Relation* readrel151 = db->getRelation("$seq_atr");
      $seq_atrindex134 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({1, 0, 2});
      slog::Relation* readrel153 = db->getRelation("$seq_atr");
      $seq_atrdelta140 = readrel153->getIndex(ord152, true);
      std::vector<u16> ord154({0, 1});
      slog::Relation* readrel155 = db->getRelation("_enum");
      _enumindex135 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({2, 0, 1});
      slog::Relation* readrel157 = db->getRelation("delta");
      deltaindex136 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0});
      slog::Relation* readrel159 = db->getRelation("comparison_op");
      comparison_opindex137 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0});
      slog::Relation* readrel161 = db->getRelation("any_bool");
      any_boolindex138 = readrel161->getIndex(ord160, false);
  
    }
    ReadTask141(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_const5feceb66ffc86f38d952786c;
      u64 v_c64 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c65 = v_const5feceb66ffc86f38d952786c;
      u64 v_c66 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c67 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c66, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m162) {
        u64 v_c69 = m162[1];
        u64 v_c10 = m162[2];
        if (buckethash(v_c69) != bucket) return;
        slog::join_probe<3,3>($seq_atindex132, std::array<u64,3>{v_c65, v_c69, v_c10}, [&](const std::array<u64,3>& m163) {
          slog::join_probe_old<3,3>($seq_atrindex133, $seq_atrdelta139, std::array<u64,3>{v_c67, v_c69, v_c10}, [&](const std::array<u64,3>& m164) {
            slog::join_probe_old<3,3>($seq_atrindex134, $seq_atrdelta140, std::array<u64,3>{v_c68, v_c69, v_c10}, [&](const std::array<u64,3>& m165) {
              slog::join_probe<2,2>(_enumindex135, std::array<u64,2>{v_c69, v_c61}, [&](const std::array<u64,2>& m166) {
                slog::join_probe<3,1>(deltaindex136, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m167) {
                  u64 v_c70 = m167[1]; u64 v_c43 = m167[2];
                  slog::join_probe<1,1>(comparison_opindex137, std::array<u64,1>{v_c43}, [&](const std::array<u64,1>& m168) {
                    slog::join_all<1>(any_boolindex138, [&](const std::array<u64,1>& m169) {
                      u64 v_c71 = m169[0];
                      bool ok170 = true;
                      u64 v_c72 = _prim_aslst(db, v_c10, &ok170);
                      if (!ok170) return;
                      u64 v_c73 = _prim_llen(db, v_c72);
                      if (v_c73 == slog_error) { slog::emit_pending_error(db, "interp.slog:112"); return; }
                      if (v_c62 != v_c73) return;
                      bool ok171 = true;
                      u64 v_c74 = _prim_lref(db, v_c72, v_c63, &ok171);
                      if (!ok171) return;
                      if (v_c69 != v_c74) return;
                      bool ok172 = true;
                      u64 v_c75 = _prim_lref(db, v_c72, v_c64, &ok172);
                      if (!ok172) return;
                      if (v_c69 != v_c75) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c70, v_c71});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,2>{1, 0});
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
        ReadTask141* _cont = new ReadTask141(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask141(db,b), false);
  // (crule (pre (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9)) (scan temp2Bvj1057 __t2Jtx290 __t5GYK254) (body (join letrec (2 1 3 0) 3 __t2Jtx290 __tconst4G37291 __t5GYK254 __t8OWf292)) (head (emit program (0) __t8OWf292)) schemecfa.slog:70 #f)
  class ReadTask174 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex173;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord175({0});
      slog::Relation* readrel176 = db->getRelation("program");
      head_index[0] = readrel176->getIndex(ord175, false);
      outer_rel = db->getRelation("temp2Bvj1057");
      std::vector<u16> ord177({2, 1, 3, 0});
      slog::Relation* readrel178 = db->getRelation("letrec");
      letrecindex173 = readrel178->getIndex(ord177, false);
  
    }
    ReadTask174(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c76 = v_const889c19fd926bc4ca61c0b4d9;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c77 = _t[0];
        u64 v_c78 = _t[1];
        slog::join_probe<4,3>(letrecindex173, std::array<u64,4>{v_c77, v_c76, v_c78, 0}, [&](const std::array<u64,4>& m179) {
          u64 v_c79 = m179[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c79}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "delta:temp2Bvj1057", _fires);
  
      if (!_done)
      {
        ReadTask174* _cont = new ReadTask174(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask174(db,b), false);
  // (crule (pre) (scan temp2Fk51003 __t4EG4161 e es x) (body (let __t0whu162 (lpush __t4EG4161 e))) (head (emit-temp temp1wv51004 __t0whu162 es x)) freevars.slog:35 #f)
  class ReadTask180 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1wv51004");
      outer_rel = db->getRelation("temp2Fk51003");
  
    }
    ReadTask180(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c80 = _t[0];
        u64 v_c81 = _t[1];
        u64 v_c30 = _t[2];
        u64 v_c82 = _t[3];
        u64 v_c83 = _prim_lpush(db, v_c80, v_c81);
        if (v_c83 == slog_error) { slog::emit_pending_error(db, "freevars.slog:35"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c83, v_c30, v_c82});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp2Fk51003", _fires);
  
      if (!_done)
      {
        ReadTask180* _cont = new ReadTask180(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask180(db,b), false);
  // (crule (pre) (scan eval __t8VKv225 __t6Nsh224 c) (body (join ref (0 1) 1 __t6Nsh224 x)) (head (mkstruct lookup (1 2 0) __5TVo797 x c)) interp.slog:30 #f)
  class ReadTask182 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex181;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lookup");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord183({0, 1});
      slog::Relation* readrel184 = db->getRelation("ref");
      refindex181 = readrel184->getIndex(ord183, false);
  
    }
    ReadTask182(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c84 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_probe<2,1>(refindex181, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m185) {
          u64 v_c82 = m185[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c82, v_c19}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask182* _cont = new ReadTask182(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask182(db,b), false);
  // (crule (pre (let __tconst69HS686 constcd2a69ce5ca278db1d6da969) (let _00024sqc0vxk654 constd4735e3a265e16eee03f5971) (let _00024sqc9Xix655 const5feceb66ffc86f38d952786c) (let _00024sqc63kA656 const6b86b273ff34fce19d6b804e) (let _00024sqo95lm657 const5feceb66ffc86f38d952786c) (let _00024sqo4EpM658 const6b86b273ff34fce19d6b804e) (let _00024sqo7bBz659 const6b86b273ff34fce19d6b804e) (let _00024sqo5IeL660 const5feceb66ffc86f38d952786c) (let __trid88QO687 consteefaed435882b14b69e99d78) (let __trel4WdJ688 constdede4476644eb06b5a48b866) (let __tcol9WTP689 const6b86b273ff34fce19d6b804e)) (probe $seq_at (1 0 2) 1 _00024sqo4EpM658 __t4TBU101 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo95lm657 __t4TBU101 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7bBz659 __t4TBU101 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo5IeL660 __t4TBU101 _00024seq2) (join _enum (0 1) 2 __t4TBU101 __tconst69HS686) (join delta (2 0 1) 1 _00024seq2 __t3GFi99 op) (join arithmetic_op (0) 1 op) (letp _00024sql4o3F652 (aslst _00024seq2)) (let chk2Fp61082 (llen _00024sql4o3F652)) (eq _00024sqc0vxk654 chk2Fp61082) (letp chk8Tu51083 (lref _00024sql4o3F652 _00024sqc9Xix655)) (eq __t4TBU101 chk8Tu51083) (letp chk7nvU1084 (lref _00024sql4o3F652 _00024sqc63kA656)) (eq __t4TBU101 chk7nvU1084)) (head (tycheck __t4TBU101 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid88QO687 __trel4WdJ688 __tcol9WTP689 (1 2 3 4 0)) (emit delta_ans (0 1) __t3GFi99 __t4TBU101)) interp.slog:111 #f)
  class ReadTask199 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex186;  slog::Index** $seq_atrindex187;  slog::Index** $seq_atrindex188;  slog::Index** _enumindex189;  slog::Index** deltaindex190;  slog::Index** arithmetic_opindex191;  slog::Index** $seq_atrdelta192;  slog::Index** $seq_atrdelta193;
    u32 sid196;  u32 sid194;  u32 sid195;  u32 sid197;  u32 sid198;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord200({0, 1});
      slog::Relation* readrel201 = db->getRelation("delta_ans");
      head_index[1] = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({1, 0, 2});
      slog::Relation* readrel203 = db->getRelation("$seq_at");
      driver_index = readrel203->getIndex(ord202, true);
      std::vector<u16> ord204({1, 0, 2});
      slog::Relation* readrel205 = db->getRelation("$seq_at");
      $seq_atindex186 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 0, 2});
      slog::Relation* readrel207 = db->getRelation("$seq_atr");
      $seq_atrindex187 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 0, 2});
      slog::Relation* readrel209 = db->getRelation("$seq_atr");
      $seq_atrdelta192 = readrel209->getIndex(ord208, true);
      std::vector<u16> ord210({1, 0, 2});
      slog::Relation* readrel211 = db->getRelation("$seq_atr");
      $seq_atrindex188 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 0, 2});
      slog::Relation* readrel213 = db->getRelation("$seq_atr");
      $seq_atrdelta193 = readrel213->getIndex(ord212, true);
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("_enum");
      _enumindex189 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({2, 0, 1});
      slog::Relation* readrel217 = db->getRelation("delta");
      deltaindex190 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0});
      slog::Relation* readrel219 = db->getRelation("arithmetic_op");
      arithmetic_opindex191 = readrel219->getIndex(ord218, false);
      sid196 = db->getRelation("_enum")->getStructId();
      sid194 = db->getRelation("boolval")->getStructId();
      sid195 = db->getRelation("closure")->getStructId();
      sid197 = db->getRelation("prim")->getStructId();
      sid198 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask199(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c86 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c87 = v_constd4735e3a265e16eee03f5971;
      u64 v_c88 = v_const5feceb66ffc86f38d952786c;
      u64 v_c89 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c90 = v_const5feceb66ffc86f38d952786c;
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c92 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
      u64 v_c94 = v_consteefaed435882b14b69e99d78;
      u64 v_c95 = v_constdede4476644eb06b5a48b866;
      u64 v_c96 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c91, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m220) {
        u64 v_c97 = m220[1];
        u64 v_c10 = m220[2];
        if (buckethash(v_c97) != bucket) return;
        slog::join_probe<3,3>($seq_atindex186, std::array<u64,3>{v_c90, v_c97, v_c10}, [&](const std::array<u64,3>& m221) {
          slog::join_probe_old<3,3>($seq_atrindex187, $seq_atrdelta192, std::array<u64,3>{v_c92, v_c97, v_c10}, [&](const std::array<u64,3>& m222) {
            slog::join_probe_old<3,3>($seq_atrindex188, $seq_atrdelta193, std::array<u64,3>{v_c93, v_c97, v_c10}, [&](const std::array<u64,3>& m223) {
              slog::join_probe<2,2>(_enumindex189, std::array<u64,2>{v_c97, v_c86}, [&](const std::array<u64,2>& m224) {
                slog::join_probe<3,1>(deltaindex190, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m225) {
                  u64 v_c98 = m225[1]; u64 v_c43 = m225[2];
                  slog::join_probe<1,1>(arithmetic_opindex191, std::array<u64,1>{v_c43}, [&](const std::array<u64,1>& m226) {
                    bool ok227 = true;
                    u64 v_c99 = _prim_aslst(db, v_c10, &ok227);
                    if (!ok227) return;
                    u64 v_c100 = _prim_llen(db, v_c99);
                    if (v_c100 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c87 != v_c100) return;
                    bool ok228 = true;
                    u64 v_c101 = _prim_lref(db, v_c99, v_c88, &ok228);
                    if (!ok228) return;
                    if (v_c97 != v_c101) return;
                    bool ok229 = true;
                    u64 v_c102 = _prim_lref(db, v_c99, v_c89, &ok229);
                    if (!ok229) return;
                    if (v_c97 != v_c102) return;
                    ++_fires;
                    if (!((is_struct(v_c97) && (decode_struct_id(v_c97) == sid194 || decode_struct_id(v_c97) == sid195 || decode_struct_id(v_c97) == sid196 || decode_struct_id(v_c97) == sid197 || decode_struct_id(v_c97) == sid198))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c94, v_c95, v_c96, v_c97}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c98, v_c97}, std::array<u16,2>{0, 1});
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
        ReadTask199* _cont = new ReadTask199(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask199(db,b), false);
  // (crule (pre (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9)) (scan temp2OQF1055 __t0vlN275 __t5GYK254 __t5TOH285 __t6dUB289 __t8IFs269) (body (join if (1 3 2 0) 3 __t5TOH285 __t8IFs269 __t0vlN275 __t7WBr286)) (head (emit-temp temp0MTF1056 __t5GYK254 __t6dUB289 __t7WBr286) (mkstruct lambda (1 2 0) __t2Jtx290 __t6dUB289 __t7WBr286)) schemecfa.slog:70 #f)
  class ReadTask231 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex230;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0MTF1056");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp2OQF1055");
      std::vector<u16> ord232({1, 3, 2, 0});
      slog::Relation* readrel233 = db->getRelation("if");
      ifindex230 = readrel233->getIndex(ord232, false);
  
    }
    ReadTask231(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c76 = v_const889c19fd926bc4ca61c0b4d9;
  
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
        u64 v_c78 = _t[1];
        u64 v_c104 = _t[2];
        u64 v_c105 = _t[3];
        u64 v_c106 = _t[4];
        slog::join_probe<4,3>(ifindex230, std::array<u64,4>{v_c104, v_c106, v_c103, 0}, [&](const std::array<u64,4>& m234) {
          u64 v_c107 = m234[3];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c78, v_c105, v_c107});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c105, v_c107}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "delta:temp2OQF1055", _fires);
  
      if (!_done)
      {
        ReadTask231* _cont = new ReadTask231(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask231(db,b), false);
  // (crule (pre (let __tconst9IXP677 constcd2a69ce5ca278db1d6da969) (let __tconst51tI19 const06abaa100ecef791ce028c56) (let _00024sqc4T4Y544 constd4735e3a265e16eee03f5971) (let _00024sqc7lRr545 const5feceb66ffc86f38d952786c) (let _00024sqc1s5u546 const6b86b273ff34fce19d6b804e) (let _00024sqo831x547 const5feceb66ffc86f38d952786c) (let _00024sqo8QLE548 const6b86b273ff34fce19d6b804e) (let _00024sqo7qSx549 const6b86b273ff34fce19d6b804e) (let _00024sqo2F2K550 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst51tI19 _00024seq2 __t4bAF20) (body (letp _00024sql3fFG542 (aslst _00024seq2)) (letp __t1v1r22 (lref _00024sql3fFG542 _00024sqc7lRr545)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo831x547 __t1v1r22 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8QLE548 __t1v1r22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7qSx549 __t1v1r22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2F2K550 __t1v1r22 _00024seq2) (join _enum (0 1) 2 __t1v1r22 __tconst9IXP677) (join any_bool (0) 0 b) (let chk6nSs1035 (llen _00024sql3fFG542)) (eq _00024sqc4T4Y544 chk6nSs1035) (letp chk7OI71036 (lref _00024sql3fFG542 _00024sqc1s5u546)) (eq __t1v1r22 chk7OI71036)) (head (emit-temp temp46yO1034 __t4bAF20 b) (mkstruct boolval (1 0) __t6st618 b)) interp.slog:121 #f)
  class ReadTask245 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex235;  slog::Index** $seq_atindex236;  slog::Index** $seq_atrindex237;  slog::Index** $seq_atrindex238;  slog::Index** _enumindex239;  slog::Index** any_boolindex240;  slog::Index** $seq_atdelta241;  slog::Index** $seq_atdelta242;  slog::Index** $seq_atrdelta243;  slog::Index** $seq_atrdelta244;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp46yO1034");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord246({1, 2, 0});
      slog::Relation* readrel247 = db->getRelation("delta");
      driver_index = readrel247->getIndex(ord246, true);
      std::vector<u16> ord248({1, 0, 2});
      slog::Relation* readrel249 = db->getRelation("$seq_at");
      $seq_atindex235 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 0, 2});
      slog::Relation* readrel251 = db->getRelation("$seq_at");
      $seq_atdelta241 = readrel251->getIndex(ord250, true);
      std::vector<u16> ord252({1, 0, 2});
      slog::Relation* readrel253 = db->getRelation("$seq_at");
      $seq_atindex236 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 0, 2});
      slog::Relation* readrel255 = db->getRelation("$seq_at");
      $seq_atdelta242 = readrel255->getIndex(ord254, true);
      std::vector<u16> ord256({1, 0, 2});
      slog::Relation* readrel257 = db->getRelation("$seq_atr");
      $seq_atrindex237 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 0, 2});
      slog::Relation* readrel259 = db->getRelation("$seq_atr");
      $seq_atrdelta243 = readrel259->getIndex(ord258, true);
      std::vector<u16> ord260({1, 0, 2});
      slog::Relation* readrel261 = db->getRelation("$seq_atr");
      $seq_atrindex238 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({1, 0, 2});
      slog::Relation* readrel263 = db->getRelation("$seq_atr");
      $seq_atrdelta244 = readrel263->getIndex(ord262, true);
      std::vector<u16> ord264({0, 1});
      slog::Relation* readrel265 = db->getRelation("_enum");
      _enumindex239 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({0});
      slog::Relation* readrel267 = db->getRelation("any_bool");
      any_boolindex240 = readrel267->getIndex(ord266, false);
  
    }
    ReadTask245(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c109 = v_const06abaa100ecef791ce028c56;
      u64 v_c110 = v_constd4735e3a265e16eee03f5971;
      u64 v_c111 = v_const5feceb66ffc86f38d952786c;
      u64 v_c112 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c113 = v_const5feceb66ffc86f38d952786c;
      u64 v_c114 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c115 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c116 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c109, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m268) {
        u64 v_c10 = m268[1];
        u64 v_c117 = m268[2];
        if (buckethash(v_c10) != bucket) return;
        bool ok269 = true;
        u64 v_c118 = _prim_aslst(db, v_c10, &ok269);
        if (!ok269) return;
        bool ok270 = true;
        u64 v_c119 = _prim_lref(db, v_c118, v_c111, &ok270);
        if (!ok270) return;
        slog::join_probe_old<3,3>($seq_atindex235, $seq_atdelta241, std::array<u64,3>{v_c113, v_c119, v_c10}, [&](const std::array<u64,3>& m271) {
          slog::join_probe_old<3,3>($seq_atindex236, $seq_atdelta242, std::array<u64,3>{v_c114, v_c119, v_c10}, [&](const std::array<u64,3>& m272) {
            slog::join_probe_old<3,3>($seq_atrindex237, $seq_atrdelta243, std::array<u64,3>{v_c115, v_c119, v_c10}, [&](const std::array<u64,3>& m273) {
              slog::join_probe_old<3,3>($seq_atrindex238, $seq_atrdelta244, std::array<u64,3>{v_c116, v_c119, v_c10}, [&](const std::array<u64,3>& m274) {
                slog::join_probe<2,2>(_enumindex239, std::array<u64,2>{v_c119, v_c108}, [&](const std::array<u64,2>& m275) {
                  slog::join_all<1>(any_boolindex240, [&](const std::array<u64,1>& m276) {
                    u64 v_c71 = m276[0];
                    u64 v_c120 = _prim_llen(db, v_c118);
                    if (v_c120 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c110 != v_c120) return;
                    bool ok277 = true;
                    u64 v_c121 = _prim_lref(db, v_c118, v_c112, &ok277);
                    if (!ok277) return;
                    if (v_c119 != v_c121) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c117, v_c71});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask245* _cont = new ReadTask245(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask245(db,b), false);
  // (crule (pre (let __tconst3Nin376 consta81ad7556291f9defc5163ec) (let __tconst0pCN356 consted725292f5f32d61535958c1) (let __tconst88d3359 const6b86b273ff34fce19d6b804e)) (scan temp3NtF1114 __t3xwX335 __t4CVz374 __t72Zs370 __t7Mqx355) (body (exists num (1 0) 1 __tconst88d3359) (join ref (1 0) 1 __tconst0pCN356 __t56Hj357) (join num (1 0) 1 __tconst88d3359 __t29aP337)) (head (emit-temp temp3pOy1115 __t3xwX335 __t4CVz374 __t72Zs370 __t7Mqx355) (mkstruct app (1 2 0) __t5Ha7358 __t56Hj357 __t7Mqx355)) schemecfa.slog:12 #f)
  class ReadTask281 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex278;  slog::Index** refindex279;  slog::Index** numindex280;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3pOy1115");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp3NtF1114");
      std::vector<u16> ord282({1, 0});
      slog::Relation* readrel283 = db->getRelation("num");
      numindex278 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({1, 0});
      slog::Relation* readrel285 = db->getRelation("ref");
      refindex279 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 0});
      slog::Relation* readrel287 = db->getRelation("num");
      numindex280 = readrel287->getIndex(ord286, false);
  
    }
    ReadTask281(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c122 = v_consta81ad7556291f9defc5163ec;
      u64 v_c123 = v_consted725292f5f32d61535958c1;
      u64 v_c124 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c125 = _t[0];
        u64 v_c126 = _t[1];
        u64 v_c127 = _t[2];
        u64 v_c128 = _t[3];
        if (!slog::exists_probe<2,1>(numindex278, std::array<u64,2>{v_c124, 0})) return;
        slog::join_probe<2,1>(refindex279, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m288) {
          u64 v_c129 = m288[1];
          slog::join_probe<2,1>(numindex280, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m289) {
            u64 v_c130 = m289[1];
            ++_fires;
            slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c125, v_c126, v_c127, v_c128});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c129, v_c128}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:12", "delta:temp3NtF1114", _fires);
  
      if (!_done)
      {
        ReadTask281* _cont = new ReadTask281(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask281(db,b), false);
  // (crule (pre) (scan temp8Yy11005 __t4ZSk163 x) (body) (head (emit freevar_in_args (1 0) __t4ZSk163 x)) freevars.slog:35 #f)
  class ReadTask290 : public slog::Task
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
      std::vector<u16> ord291({1, 0});
      slog::Relation* readrel292 = db->getRelation("freevar_in_args");
      head_index[0] = readrel292->getIndex(ord291, false);
      outer_rel = db->getRelation("temp8Yy11005");
  
    }
    ReadTask290(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c131 = _t[0];
        u64 v_c82 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c131, v_c82}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:35", "delta:temp8Yy11005", _fires);
  
      if (!_done)
      {
        ReadTask290* _cont = new ReadTask290(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask290(db,b), false);
  // (crule (pre (let __t2ytA435 (lempty))) (scan lst_take __t1Al3438 __t2jGw437 m) (body (join mlimit (0) 1 m) (join lst_take_ans (0 1) 1 __t1Al3438 __v0) (join tick (0 2 1) 0 __t6dFG434 c site) (let __t33cB436 (lpush __t2ytA435 site)) (let chk1VtH1165 (lcat __t33cB436 c)) (eq __t2jGw437 chk1VtH1165)) (head (emit tick_ans (0 1) __t6dFG434 __v0)) context.slog:10 #f)
  class ReadTask296 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mlimitindex293;  slog::Index** lst_take_ansindex294;  slog::Index** tickindex295;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick_ans");
      std::vector<u16> ord297({0, 1});
      slog::Relation* readrel298 = db->getRelation("tick_ans");
      head_index[0] = readrel298->getIndex(ord297, false);
      outer_rel = db->getRelation("lst_take");
      std::vector<u16> ord299({0});
      slog::Relation* readrel300 = db->getRelation("mlimit");
      mlimitindex293 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({0, 1});
      slog::Relation* readrel302 = db->getRelation("lst_take_ans");
      lst_take_ansindex294 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({0, 2, 1});
      slog::Relation* readrel304 = db->getRelation("tick");
      tickindex295 = readrel304->getIndex(ord303, false);
  
    }
    ReadTask296(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c132 = _prim_lempty(db);
      if (v_c132 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c133 = _t[0];
        u64 v_c134 = _t[1];
        u64 v_c20 = _t[2];
        slog::join_probe<1,1>(mlimitindex293, std::array<u64,1>{v_c20}, [&](const std::array<u64,1>& m305) {
          slog::join_probe<2,1>(lst_take_ansindex294, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m306) {
            u64 v_c135 = m306[1];
            slog::join_all<3>(tickindex295, [&](const std::array<u64,3>& m307) {
              u64 v_c136 = m307[0]; u64 v_c19 = m307[1]; u64 v_c21 = m307[2];
              u64 v_c137 = _prim_lpush(db, v_c132, v_c21);
              if (v_c137 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
              u64 v_c138 = _prim_lcat(db, v_c137, v_c19);
              if (v_c138 == slog_error) { slog::emit_pending_error(db, "context.slog:10"); return; }
              if (v_c134 != v_c138) return;
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c136, v_c135}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:10", "delta:lst_take", _fires);
  
      if (!_done)
      {
        ReadTask296* _cont = new ReadTask296(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask296(db,b), false);
  // (crule (pre) (scan temp8iMn1101 __t00lI121 __t06qS122) (body) (head (emit eval_args_ans (0 1) __t06qS122 __t00lI121)) interp.slog:37 #f)
  class ReadTask308 : public slog::Task
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
      std::vector<u16> ord309({0, 1});
      slog::Relation* readrel310 = db->getRelation("eval_args_ans");
      head_index[0] = readrel310->getIndex(ord309, false);
      outer_rel = db->getRelation("temp8iMn1101");
  
    }
    ReadTask308(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c139 = _t[0];
        u64 v_c140 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c140, v_c139}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:37", "delta:temp8iMn1101", _fires);
  
      if (!_done)
      {
        ReadTask308* _cont = new ReadTask308(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask308(db,b), false);
  // (crule (pre (let __tconst6GmF96 const5d1d34d1b1718cd7c9f1ee55) (let __tconst4uoq76 constaee3d30407ccfb32dbb15266)) (scan temp51he960 __t351k62 __t9J9k75 __t9Uwo95) (body (join let (2 1 3 0) 3 __t9J9k75 __tconst4uoq76 __t351k62 __t00Fz77)) (head (emit-temp temp0SQX961 __t00Fz77 __t9Uwo95) (mkstruct let (2 1 3 0) __t515p97 __t9Uwo95 __tconst6GmF96 __t00Fz77)) schemecfa.slog:39 #f)
  class ReadTask312 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex311;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0SQX961");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp51he960");
      std::vector<u16> ord313({2, 1, 3, 0});
      slog::Relation* readrel314 = db->getRelation("let");
      letindex311 = readrel314->getIndex(ord313, false);
  
    }
    ReadTask312(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c141 = v_const5d1d34d1b1718cd7c9f1ee55;
      u64 v_c142 = v_constaee3d30407ccfb32dbb15266;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c143 = _t[0];
        u64 v_c144 = _t[1];
        u64 v_c145 = _t[2];
        slog::join_probe<4,3>(letindex311, std::array<u64,4>{v_c144, v_c142, v_c143, 0}, [&](const std::array<u64,4>& m315) {
          u64 v_c146 = m315[3];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c146, v_c145});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c145, v_c141, v_c146}, std::array<u16,4>{2, 1, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("schemecfa.slog:39", "delta:temp51he960", _fires);
  
      if (!_done)
      {
        ReadTask312* _cont = new ReadTask312(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask312(db,b), false);
  // (crule (pre) (scan freevar x eb) (body (join-old lambda (2 0 1) 1 (2 0 1) eb __t3i6R439 xs)) (head (mkstruct lst_absent (1 2 0) __8tPx738 xs x)) freevars.slog:28 #f)
  class ReadTask318 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex316;  slog::Index** lambdadelta317;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lst_absent");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord319({2, 0, 1});
      slog::Relation* readrel320 = db->getRelation("lambda");
      lambdaindex316 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({2, 0, 1});
      slog::Relation* readrel322 = db->getRelation("lambda");
      lambdadelta317 = readrel322->getIndex(ord321, true);
  
    }
    ReadTask318(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c53 = _t[1];
        slog::join_probe_old<3,1>(lambdaindex316, lambdadelta317, std::array<u64,3>{v_c53, 0, 0}, [&](const std::array<u64,3>& m323) {
          u64 v_c147 = m323[1]; u64 v_c52 = m323[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c52, v_c82}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:28", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask318* _cont = new ReadTask318(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask318(db,b), false);
  // (crule (pre) (scan eval_ans __t5MCM24 __t3Pto26) (body (join-old eval (0 2 1) 1 (0 2 1) __t5MCM24 c ef) (exists app (1 2 0) 1 ef) (exists eval_args (2 0 1) 1 c) (exists tick (2 0 1) 1 c) (join eval (2 0 1) 1 c __4cUN684 __t8j7u29) (exists tick (1 2 0) 2 __t8j7u29 c) (join-old app (0 1 2) 2 (0 1 2) __t8j7u29 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join-old tick (1 2 0) 2 (1 2 0) __t8j7u29 c __t0DSy30) (exists tick_ans (0 1) 1 __t0DSy30) (join-old eval_args_ans (0 1) 1 (0 1) __t5BFX27 vs) (join-old tick_ans (0 1) 1 (0 1) __t0DSy30 l) (join-old closure (0 1 2) 1 (0 1 2) __t3Pto26 __t0xip28 cb) (exists binding (1 0 2) 1 cb) (join-old freevar (1 0) 1 (1 0) __t0xip28 y) (join-old binding (0 1 2) 2 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask352 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex324;  slog::Index** appindex325;  slog::Index** eval_argsindex326;  slog::Index** tickindex327;  slog::Index** evalindex328;  slog::Index** tickindex329;  slog::Index** appindex330;  slog::Index** eval_argsindex331;  slog::Index** eval_args_ansindex332;  slog::Index** tickindex333;  slog::Index** tick_ansindex334;  slog::Index** eval_args_ansindex335;  slog::Index** tick_ansindex336;  slog::Index** closureindex337;  slog::Index** bindingindex338;  slog::Index** freevarindex339;  slog::Index** bindingindex340;  slog::Index** lambdaindex341;  slog::Index** evaldelta342;  slog::Index** appdelta343;  slog::Index** eval_argsdelta344;  slog::Index** tickdelta345;  slog::Index** eval_args_ansdelta346;  slog::Index** tick_ansdelta347;  slog::Index** closuredelta348;  slog::Index** freevardelta349;  slog::Index** bindingdelta350;  slog::Index** lambdadelta351;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord353({0, 1, 2});
      slog::Relation* readrel354 = db->getRelation("binding");
      head_index[0] = readrel354->getIndex(ord353, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord355({0, 1, 2});
      slog::Relation* readrel356 = db->getRelation("binding_event");
      head_index[1] = readrel356->getIndex(ord355, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord357({0, 2, 1});
      slog::Relation* readrel358 = db->getRelation("eval");
      evalindex324 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({0, 2, 1});
      slog::Relation* readrel360 = db->getRelation("eval");
      evaldelta342 = readrel360->getIndex(ord359, true);
      std::vector<u16> ord361({1, 2, 0});
      slog::Relation* readrel362 = db->getRelation("app");
      appindex325 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({2, 0, 1});
      slog::Relation* readrel364 = db->getRelation("eval_args");
      eval_argsindex326 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({2, 0, 1});
      slog::Relation* readrel366 = db->getRelation("tick");
      tickindex327 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({2, 0, 1});
      slog::Relation* readrel368 = db->getRelation("eval");
      evalindex328 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({1, 2, 0});
      slog::Relation* readrel370 = db->getRelation("tick");
      tickindex329 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({0, 1, 2});
      slog::Relation* readrel372 = db->getRelation("app");
      appindex330 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({0, 1, 2});
      slog::Relation* readrel374 = db->getRelation("app");
      appdelta343 = readrel374->getIndex(ord373, true);
      std::vector<u16> ord375({1, 2, 0});
      slog::Relation* readrel376 = db->getRelation("eval_args");
      eval_argsindex331 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({1, 2, 0});
      slog::Relation* readrel378 = db->getRelation("eval_args");
      eval_argsdelta344 = readrel378->getIndex(ord377, true);
      std::vector<u16> ord379({0, 1});
      slog::Relation* readrel380 = db->getRelation("eval_args_ans");
      eval_args_ansindex332 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 2, 0});
      slog::Relation* readrel382 = db->getRelation("tick");
      tickindex333 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({1, 2, 0});
      slog::Relation* readrel384 = db->getRelation("tick");
      tickdelta345 = readrel384->getIndex(ord383, true);
      std::vector<u16> ord385({0, 1});
      slog::Relation* readrel386 = db->getRelation("tick_ans");
      tick_ansindex334 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({0, 1});
      slog::Relation* readrel388 = db->getRelation("eval_args_ans");
      eval_args_ansindex335 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({0, 1});
      slog::Relation* readrel390 = db->getRelation("eval_args_ans");
      eval_args_ansdelta346 = readrel390->getIndex(ord389, true);
      std::vector<u16> ord391({0, 1});
      slog::Relation* readrel392 = db->getRelation("tick_ans");
      tick_ansindex336 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({0, 1});
      slog::Relation* readrel394 = db->getRelation("tick_ans");
      tick_ansdelta347 = readrel394->getIndex(ord393, true);
      std::vector<u16> ord395({0, 1, 2});
      slog::Relation* readrel396 = db->getRelation("closure");
      closureindex337 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({0, 1, 2});
      slog::Relation* readrel398 = db->getRelation("closure");
      closuredelta348 = readrel398->getIndex(ord397, true);
      std::vector<u16> ord399({1, 0, 2});
      slog::Relation* readrel400 = db->getRelation("binding");
      bindingindex338 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({1, 0});
      slog::Relation* readrel402 = db->getRelation("freevar");
      freevarindex339 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 0});
      slog::Relation* readrel404 = db->getRelation("freevar");
      freevardelta349 = readrel404->getIndex(ord403, true);
      std::vector<u16> ord405({0, 1, 2});
      slog::Relation* readrel406 = db->getRelation("binding");
      bindingindex340 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({0, 1, 2});
      slog::Relation* readrel408 = db->getRelation("binding");
      bindingdelta350 = readrel408->getIndex(ord407, true);
      std::vector<u16> ord409({0, 1, 2});
      slog::Relation* readrel410 = db->getRelation("lambda");
      lambdaindex341 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({0, 1, 2});
      slog::Relation* readrel412 = db->getRelation("lambda");
      lambdadelta351 = readrel412->getIndex(ord411, true);
  
    }
    ReadTask352(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c148 = _t[0];
        u64 v_c149 = _t[1];
        slog::join_probe_old<3,1>(evalindex324, evaldelta342, std::array<u64,3>{v_c148, 0, 0}, [&](const std::array<u64,3>& m413) {
          u64 v_c19 = m413[1]; u64 v_c29 = m413[2];
          if (!slog::exists_probe<3,1>(appindex325, std::array<u64,3>{v_c29, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex326, std::array<u64,3>{v_c19, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex327, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe<3,1>(evalindex328, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m414) {
            u64 v_c150 = m414[1]; u64 v_c151 = m414[2];
            if (!slog::exists_probe<3,2>(tickindex329, std::array<u64,3>{v_c151, v_c19, 0})) return;
            slog::join_probe_old<3,2>(appindex330, appdelta343, std::array<u64,3>{v_c151, v_c29, 0}, [&](const std::array<u64,3>& m415) {
              u64 v_c30 = m415[2];
              slog::join_probe_old<3,2>(eval_argsindex331, eval_argsdelta344, std::array<u64,3>{v_c30, v_c19, 0}, [&](const std::array<u64,3>& m416) {
                u64 v_c152 = m416[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex332, std::array<u64,2>{v_c152, 0})) return;
                slog::join_probe_old<3,2>(tickindex333, tickdelta345, std::array<u64,3>{v_c151, v_c19, 0}, [&](const std::array<u64,3>& m417) {
                  u64 v_c153 = m417[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex334, std::array<u64,2>{v_c153, 0})) return;
                  slog::join_probe_old<2,1>(eval_args_ansindex335, eval_args_ansdelta346, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m418) {
                    u64 v_c154 = m418[1];
                    slog::join_probe_old<2,1>(tick_ansindex336, tick_ansdelta347, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m419) {
                      u64 v_c155 = m419[1];
                      slog::join_probe_old<3,1>(closureindex337, closuredelta348, std::array<u64,3>{v_c149, 0, 0}, [&](const std::array<u64,3>& m420) {
                        u64 v_c156 = m420[1]; u64 v_c49 = m420[2];
                        if (!slog::exists_probe<3,1>(bindingindex338, std::array<u64,3>{v_c49, 0, 0})) return;
                        slog::join_probe_old<2,1>(freevarindex339, freevardelta349, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m421) {
                          u64 v_c48 = m421[1];
                          slog::join_probe_old<3,2>(bindingindex340, bindingdelta350, std::array<u64,3>{v_c48, v_c49, 0}, [&](const std::array<u64,3>& m422) {
                            u64 v_c50 = m422[2];
                            slog::join_probe_old<3,1>(lambdaindex341, lambdadelta351, std::array<u64,3>{v_c156, 0, 0}, [&](const std::array<u64,3>& m423) {
                              u64 v_c52 = m423[1]; u64 v_c53 = m423[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c48, v_c155, v_c50}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c48, v_c155, v_c19}, std::array<u16,3>{0, 1, 2});
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
        ReadTask352* _cont = new ReadTask352(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask352(db,b), false);
  // (crule (pre) (scan int_overflow __erre2P32929 __errf8BMa930 __errf1zzA931 __errf4tuU932) (body) (head (emit error (0) __erre2P32929)) <internal>:1 #f)
  class ReadTask424 : public slog::Task
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
      std::vector<u16> ord425({0});
      slog::Relation* readrel426 = db->getRelation("error");
      head_index[0] = readrel426->getIndex(ord425, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask424(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c160 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c157}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask424* _cont = new ReadTask424(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask424(db,b), false);
  // (crule (pre) (scan freevar x e3) (body (join-old if (3 0 1 2) 1 (3 0 1 2) e3 __t2nUQ323 e1 e2)) (head (emit freevar (0 1) x __t2nUQ323)) freevars.slog:17 #f)
  class ReadTask429 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex427;  slog::Index** ifdelta428;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord430({0, 1});
      slog::Relation* readrel431 = db->getRelation("freevar");
      head_index[0] = readrel431->getIndex(ord430, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord432({3, 0, 1, 2});
      slog::Relation* readrel433 = db->getRelation("if");
      ifindex427 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({3, 0, 1, 2});
      slog::Relation* readrel435 = db->getRelation("if");
      ifdelta428 = readrel435->getIndex(ord434, true);
  
    }
    ReadTask429(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[1];
        slog::join_probe_old<4,1>(ifindex427, ifdelta428, std::array<u64,4>{v_c59, 0, 0, 0}, [&](const std::array<u64,4>& m436) {
          u64 v_c161 = m436[1]; u64 v_c162 = m436[2]; u64 v_c58 = m436[3];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c82, v_c161}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:17", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask429* _cont = new ReadTask429(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask429(db,b), false);
  // (crule (pre (let _00024sqc8egv614 const6b86b273ff34fce19d6b804e) (let _00024sqc6fIG615 const5feceb66ffc86f38d952786c) (let _00024sqc4bXT616 const6b86b273ff34fce19d6b804e) (let _00024sqc8qtj617 const5feceb66ffc86f38d952786c) (let _00024sqo7FTM622 const5feceb66ffc86f38d952786c) (let __t9KsM444 (lempty))) (scan eval_args __t2W25447 _00024seq0 c) (body (letp _00024sql5v3i612 (aslst _00024seq0)) (letp e (lref _00024sql5v3i612 _00024sqc6fIG615)) (let _00024sqn11pi613 (llen _00024sql5v3i612)) (cmp ge _00024sqn11pi613 _00024sqc8egv614) (let _00024sqp7l34618 (_0002d _00024sqn11pi613 _00024sqc8qtj617)) (let es (lslice _00024sql5v3i612 _00024sqc4bXT616 _00024sqp7l34618)) (join $sup56712x37x0x0x0 (0 3 4 2 1) 5 _00024seq0 e es c __t2W25447) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7FTM622 e _00024seq0) (exists eval_args (1 2 0) 2 es c) (join-old eval (1 2 0) 2 (1 2 0) e c __t25lG448) (exists eval_ans (0 1) 1 __t25lG448) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t6oBa449) (exists eval_args_ans (0 1) 1 __t6oBa449) (join eval_ans (0 1) 1 __t25lG448 __v0) (join eval_args_ans (0 1) 1 __t6oBa449 __v1)) (head (emit-temp temp2fEO980 __t2W25447 __t9KsM444 __v0 __v1)) interp.slog:38 #f)
  class ReadTask449 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup56712x37x0x0x0index437;  slog::Index** $seq_atindex438;  slog::Index** eval_argsindex439;  slog::Index** evalindex440;  slog::Index** eval_ansindex441;  slog::Index** eval_argsindex442;  slog::Index** eval_args_ansindex443;  slog::Index** eval_ansindex444;  slog::Index** eval_args_ansindex445;  slog::Index** $seq_atdelta446;  slog::Index** evaldelta447;  slog::Index** eval_argsdelta448;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2fEO980");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord450({0, 3, 4, 2, 1});
      slog::Relation* readrel451 = db->getRelation("$sup56712x37x0x0x0");
      $sup56712x37x0x0x0index437 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 0, 2});
      slog::Relation* readrel453 = db->getRelation("$seq_at");
      $seq_atindex438 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 0, 2});
      slog::Relation* readrel455 = db->getRelation("$seq_at");
      $seq_atdelta446 = readrel455->getIndex(ord454, true);
      std::vector<u16> ord456({1, 2, 0});
      slog::Relation* readrel457 = db->getRelation("eval_args");
      eval_argsindex439 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 2, 0});
      slog::Relation* readrel459 = db->getRelation("eval");
      evalindex440 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({1, 2, 0});
      slog::Relation* readrel461 = db->getRelation("eval");
      evaldelta447 = readrel461->getIndex(ord460, true);
      std::vector<u16> ord462({0, 1});
      slog::Relation* readrel463 = db->getRelation("eval_ans");
      eval_ansindex441 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 0});
      slog::Relation* readrel465 = db->getRelation("eval_args");
      eval_argsindex442 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("eval_args");
      eval_argsdelta448 = readrel467->getIndex(ord466, true);
      std::vector<u16> ord468({0, 1});
      slog::Relation* readrel469 = db->getRelation("eval_args_ans");
      eval_args_ansindex443 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({0, 1});
      slog::Relation* readrel471 = db->getRelation("eval_ans");
      eval_ansindex444 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({0, 1});
      slog::Relation* readrel473 = db->getRelation("eval_args_ans");
      eval_args_ansindex445 = readrel473->getIndex(ord472, false);
  
    }
    ReadTask449(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c164 = v_const5feceb66ffc86f38d952786c;
      u64 v_c165 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c166 = v_const5feceb66ffc86f38d952786c;
      u64 v_c167 = v_const5feceb66ffc86f38d952786c;
      u64 v_c168 = _prim_lempty(db);
      if (v_c168 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c169 = _t[0];
        u64 v_c170 = _t[1];
        u64 v_c19 = _t[2];
        bool ok474 = true;
        u64 v_c171 = _prim_aslst(db, v_c170, &ok474);
        if (!ok474) return;
        bool ok475 = true;
        u64 v_c81 = _prim_lref(db, v_c171, v_c164, &ok475);
        if (!ok475) return;
        u64 v_c172 = _prim_llen(db, v_c171);
        if (v_c172 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c173 = _prim_ge(db, v_c172, v_c163);
        if (v_c173 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        if (!v_c173) return;
        u64 v_c174 = _prim__0002d(db, v_c172, v_c166);
        if (v_c174 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        u64 v_c30 = _prim_lslice(db, v_c171, v_c165, v_c174);
        if (v_c30 == slog_error) { slog::emit_pending_error(db, "interp.slog:38"); return; }
        slog::join_probe<5,5>($sup56712x37x0x0x0index437, std::array<u64,5>{v_c170, v_c81, v_c30, v_c19, v_c169}, [&](const std::array<u64,5>& m477) {
          slog::join_probe_old<3,3>($seq_atindex438, $seq_atdelta446, std::array<u64,3>{v_c167, v_c81, v_c170}, [&](const std::array<u64,3>& m478) {
            if (!slog::exists_probe<3,2>(eval_argsindex439, std::array<u64,3>{v_c30, v_c19, 0})) return;
            slog::join_probe_old<3,2>(evalindex440, evaldelta447, std::array<u64,3>{v_c81, v_c19, 0}, [&](const std::array<u64,3>& m479) {
              u64 v_c175 = m479[2];
              if (!slog::exists_probe<2,1>(eval_ansindex441, std::array<u64,2>{v_c175, 0})) return;
              slog::join_probe_old<3,2>(eval_argsindex442, eval_argsdelta448, std::array<u64,3>{v_c30, v_c19, 0}, [&](const std::array<u64,3>& m480) {
                u64 v_c176 = m480[2];
                if (!slog::exists_probe<2,1>(eval_args_ansindex443, std::array<u64,2>{v_c176, 0})) return;
                slog::join_probe<2,1>(eval_ansindex444, std::array<u64,2>{v_c175, 0}, [&](const std::array<u64,2>& m481) {
                  u64 v_c135 = m481[1];
                  slog::join_probe<2,1>(eval_args_ansindex445, std::array<u64,2>{v_c176, 0}, [&](const std::array<u64,2>& m482) {
                    u64 v_c177 = m482[1];
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c169, v_c168, v_c135, v_c177});
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
        ReadTask449* _cont = new ReadTask449(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask449(db,b), false);
  // (crule (pre (let __tconst4Btx248 const4e07408562bedb8b60ce05c1) (let __tconst1yQ3255 const6b86b273ff34fce19d6b804e) (let __tconst5n8U262 const0933fb667296882d8c45abca) (let __tconst0jEK272 const37664d5895f78758ec8e94e4) (let __tconst6yT0276 const5feceb66ffc86f38d952786c) (let __tconst3Rob283 const90fb9068eda6f2d68bb61c33) (let __tconst2l7U287 consta05447c5b6502c5938db0f77) (let __tconst4G37291 const889c19fd926bc4ca61c0b4d9)) (scan temp6Rvt1049 __t6t5b288) (body (exists num (1 0) 1 __tconst6yT0276) (exists ref (1 0) 1 __tconst0jEK272) (exists ref (1 0) 1 __tconst5n8U262) (exists ref (1 0) 1 __tconst2l7U287) (exists num (1 0) 1 __tconst1yQ3255) (exists ref (1 0) 1 __tconst4G37291) (exists num (1 0) 1 __tconst4Btx248) (join ref (1 0) 1 __tconst3Rob283 __t88QE284) (join num (1 0) 1 __tconst6yT0276 __t0Xcv277) (join ref (1 0) 1 __tconst0jEK272 __t42iX271) (join ref (1 0) 1 __tconst5n8U262 __t4C1l263) (join ref (1 0) 1 __tconst2l7U287 __t0OCP258) (join num (1 0) 1 __tconst1yQ3255 __t5z2C256) (join ref (1 0) 1 __tconst4G37291 __t8oYB253) (join num (1 0) 1 __tconst4Btx248 __t4N0a249) (let __t4a9o251 (lpush __t6t5b288 __t4N0a249)) (let __t2HAB274 (lpush __t6t5b288 __tconst0jEK272)) (let __t0Sqk281 (lpush __t6t5b288 __t0OCP258)) (let __t6dUB289 (lpush __t6t5b288 __tconst2l7U287))) (head (emit-temp temp7w7C1050 __t0Sqk281 __t2HAB274 __t4a9o251 __t6dUB289 __t6t5b288)) schemecfa.slog:70 #f)
  class ReadTask498 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex483;  slog::Index** refindex484;  slog::Index** refindex485;  slog::Index** refindex486;  slog::Index** numindex487;  slog::Index** refindex488;  slog::Index** numindex489;  slog::Index** refindex490;  slog::Index** numindex491;  slog::Index** refindex492;  slog::Index** refindex493;  slog::Index** refindex494;  slog::Index** numindex495;  slog::Index** refindex496;  slog::Index** numindex497;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7w7C1050");
      outer_rel = db->getRelation("temp6Rvt1049");
      std::vector<u16> ord499({1, 0});
      slog::Relation* readrel500 = db->getRelation("num");
      numindex483 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({1, 0});
      slog::Relation* readrel502 = db->getRelation("ref");
      refindex484 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 0});
      slog::Relation* readrel504 = db->getRelation("ref");
      refindex485 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 0});
      slog::Relation* readrel506 = db->getRelation("ref");
      refindex486 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 0});
      slog::Relation* readrel508 = db->getRelation("num");
      numindex487 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 0});
      slog::Relation* readrel510 = db->getRelation("ref");
      refindex488 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({1, 0});
      slog::Relation* readrel512 = db->getRelation("num");
      numindex489 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({1, 0});
      slog::Relation* readrel514 = db->getRelation("ref");
      refindex490 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({1, 0});
      slog::Relation* readrel516 = db->getRelation("num");
      numindex491 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({1, 0});
      slog::Relation* readrel518 = db->getRelation("ref");
      refindex492 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 0});
      slog::Relation* readrel520 = db->getRelation("ref");
      refindex493 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 0});
      slog::Relation* readrel522 = db->getRelation("ref");
      refindex494 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({1, 0});
      slog::Relation* readrel524 = db->getRelation("num");
      numindex495 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 0});
      slog::Relation* readrel526 = db->getRelation("ref");
      refindex496 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 0});
      slog::Relation* readrel528 = db->getRelation("num");
      numindex497 = readrel528->getIndex(ord527, false);
  
    }
    ReadTask498(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c178 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c179 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c180 = v_const0933fb667296882d8c45abca;
      u64 v_c181 = v_const37664d5895f78758ec8e94e4;
      u64 v_c182 = v_const5feceb66ffc86f38d952786c;
      u64 v_c183 = v_const90fb9068eda6f2d68bb61c33;
      u64 v_c184 = v_consta05447c5b6502c5938db0f77;
      u64 v_c76 = v_const889c19fd926bc4ca61c0b4d9;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c185 = _t[0];
        if (!slog::exists_probe<2,1>(numindex483, std::array<u64,2>{v_c182, 0})) return;
        if (!slog::exists_probe<2,1>(refindex484, std::array<u64,2>{v_c181, 0})) return;
        if (!slog::exists_probe<2,1>(refindex485, std::array<u64,2>{v_c180, 0})) return;
        if (!slog::exists_probe<2,1>(refindex486, std::array<u64,2>{v_c184, 0})) return;
        if (!slog::exists_probe<2,1>(numindex487, std::array<u64,2>{v_c179, 0})) return;
        if (!slog::exists_probe<2,1>(refindex488, std::array<u64,2>{v_c76, 0})) return;
        if (!slog::exists_probe<2,1>(numindex489, std::array<u64,2>{v_c178, 0})) return;
        slog::join_probe<2,1>(refindex490, std::array<u64,2>{v_c183, 0}, [&](const std::array<u64,2>& m529) {
          u64 v_c186 = m529[1];
          slog::join_probe<2,1>(numindex491, std::array<u64,2>{v_c182, 0}, [&](const std::array<u64,2>& m530) {
            u64 v_c187 = m530[1];
            slog::join_probe<2,1>(refindex492, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m531) {
              u64 v_c188 = m531[1];
              slog::join_probe<2,1>(refindex493, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m532) {
                u64 v_c189 = m532[1];
                slog::join_probe<2,1>(refindex494, std::array<u64,2>{v_c184, 0}, [&](const std::array<u64,2>& m533) {
                  u64 v_c190 = m533[1];
                  slog::join_probe<2,1>(numindex495, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m534) {
                    u64 v_c191 = m534[1];
                    slog::join_probe<2,1>(refindex496, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m535) {
                      u64 v_c192 = m535[1];
                      slog::join_probe<2,1>(numindex497, std::array<u64,2>{v_c178, 0}, [&](const std::array<u64,2>& m536) {
                        u64 v_c193 = m536[1];
                        u64 v_c194 = _prim_lpush(db, v_c185, v_c193);
                        if (v_c194 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:70"); return; }
                        u64 v_c195 = _prim_lpush(db, v_c185, v_c181);
                        if (v_c195 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:70"); return; }
                        u64 v_c196 = _prim_lpush(db, v_c185, v_c190);
                        if (v_c196 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:70"); return; }
                        u64 v_c105 = _prim_lpush(db, v_c185, v_c184);
                        if (v_c105 == slog_error) { slog::emit_pending_error(db, "schemecfa.slog:70"); return; }
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c196, v_c195, v_c194, v_c105, v_c185});
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
  
      if (_fires) db->bumpFires("schemecfa.slog:70", "delta:temp6Rvt1049", _fires);
  
      if (!_done)
      {
        ReadTask498* _cont = new ReadTask498(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask498(db,b), false);
  // (crule (pre (let __tconst7knU761 const0122baa3ac55f1b433944eb1)) (scan temp3tnu962 __t7NfZ245) (body (join _enum (1 0) 1 __tconst7knU761 __t4Ufa242) (join boolval (1 0) 1 __t4Ufa242 __t0oTa243)) (head (emit delta_ans (0 1) __t7NfZ245 __t0oTa243)) interp.slog:118 #f)
  class ReadTask539 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex537;  slog::Index** boolvalindex538;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord540({0, 1});
      slog::Relation* readrel541 = db->getRelation("delta_ans");
      head_index[0] = readrel541->getIndex(ord540, false);
      outer_rel = db->getRelation("temp3tnu962");
      std::vector<u16> ord542({1, 0});
      slog::Relation* readrel543 = db->getRelation("_enum");
      _enumindex537 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 0});
      slog::Relation* readrel545 = db->getRelation("boolval");
      boolvalindex538 = readrel545->getIndex(ord544, false);
  
    }
    ReadTask539(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c197 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c198 = _t[0];
        slog::join_probe<2,1>(_enumindex537, std::array<u64,2>{v_c197, 0}, [&](const std::array<u64,2>& m546) {
          u64 v_c199 = m546[1];
          slog::join_probe<2,1>(boolvalindex538, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m547) {
            u64 v_c200 = m547[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c198, v_c200}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:temp3tnu962", _fires);
  
      if (!_done)
      {
        ReadTask539* _cont = new ReadTask539(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask539(db,b), false);
  // (crule (pre (let __tconst69HS686 constcd2a69ce5ca278db1d6da969) (let _00024sqc0vxk654 constd4735e3a265e16eee03f5971) (let _00024sqc9Xix655 const5feceb66ffc86f38d952786c) (let _00024sqc63kA656 const6b86b273ff34fce19d6b804e) (let _00024sqo95lm657 const5feceb66ffc86f38d952786c) (let _00024sqo4EpM658 const6b86b273ff34fce19d6b804e) (let _00024sqo7bBz659 const6b86b273ff34fce19d6b804e) (let _00024sqo5IeL660 const5feceb66ffc86f38d952786c) (let __trid88QO687 consteefaed435882b14b69e99d78) (let __trel4WdJ688 constdede4476644eb06b5a48b866) (let __tcol9WTP689 const6b86b273ff34fce19d6b804e)) (probe $seq_atr (1 0 2) 1 _00024sqo5IeL660 __t4TBU101 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo95lm657 __t4TBU101 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo4EpM658 __t4TBU101 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo7bBz659 __t4TBU101 _00024seq2) (join _enum (0 1) 2 __t4TBU101 __tconst69HS686) (join delta (2 0 1) 1 _00024seq2 __t3GFi99 op) (join arithmetic_op (0) 1 op) (letp _00024sql4o3F652 (aslst _00024seq2)) (let chk1M3m1088 (llen _00024sql4o3F652)) (eq _00024sqc0vxk654 chk1M3m1088) (letp chk6acO1089 (lref _00024sql4o3F652 _00024sqc9Xix655)) (eq __t4TBU101 chk6acO1089) (letp chk9xlR1090 (lref _00024sql4o3F652 _00024sqc63kA656)) (eq __t4TBU101 chk9xlR1090)) (head (tycheck __t4TBU101 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid88QO687 __trel4WdJ688 __tcol9WTP689 (1 2 3 4 0)) (emit delta_ans (0 1) __t3GFi99 __t4TBU101)) interp.slog:111 #f)
  class ReadTask559 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex548;  slog::Index** $seq_atindex549;  slog::Index** $seq_atrindex550;  slog::Index** _enumindex551;  slog::Index** deltaindex552;  slog::Index** arithmetic_opindex553;
    u32 sid556;  u32 sid554;  u32 sid555;  u32 sid557;  u32 sid558;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord560({0, 1});
      slog::Relation* readrel561 = db->getRelation("delta_ans");
      head_index[1] = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 0, 2});
      slog::Relation* readrel563 = db->getRelation("$seq_atr");
      driver_index = readrel563->getIndex(ord562, true);
      std::vector<u16> ord564({1, 0, 2});
      slog::Relation* readrel565 = db->getRelation("$seq_at");
      $seq_atindex548 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({1, 0, 2});
      slog::Relation* readrel567 = db->getRelation("$seq_at");
      $seq_atindex549 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 0, 2});
      slog::Relation* readrel569 = db->getRelation("$seq_atr");
      $seq_atrindex550 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({0, 1});
      slog::Relation* readrel571 = db->getRelation("_enum");
      _enumindex551 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({2, 0, 1});
      slog::Relation* readrel573 = db->getRelation("delta");
      deltaindex552 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({0});
      slog::Relation* readrel575 = db->getRelation("arithmetic_op");
      arithmetic_opindex553 = readrel575->getIndex(ord574, false);
      sid556 = db->getRelation("_enum")->getStructId();
      sid554 = db->getRelation("boolval")->getStructId();
      sid555 = db->getRelation("closure")->getStructId();
      sid557 = db->getRelation("prim")->getStructId();
      sid558 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask559(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c86 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c87 = v_constd4735e3a265e16eee03f5971;
      u64 v_c88 = v_const5feceb66ffc86f38d952786c;
      u64 v_c89 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c90 = v_const5feceb66ffc86f38d952786c;
      u64 v_c91 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c92 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c93 = v_const5feceb66ffc86f38d952786c;
      u64 v_c94 = v_consteefaed435882b14b69e99d78;
      u64 v_c95 = v_constdede4476644eb06b5a48b866;
      u64 v_c96 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c93, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m576) {
        u64 v_c97 = m576[1];
        u64 v_c10 = m576[2];
        if (buckethash(v_c97) != bucket) return;
        slog::join_probe<3,3>($seq_atindex548, std::array<u64,3>{v_c90, v_c97, v_c10}, [&](const std::array<u64,3>& m577) {
          slog::join_probe<3,3>($seq_atindex549, std::array<u64,3>{v_c91, v_c97, v_c10}, [&](const std::array<u64,3>& m578) {
            slog::join_probe<3,3>($seq_atrindex550, std::array<u64,3>{v_c92, v_c97, v_c10}, [&](const std::array<u64,3>& m579) {
              slog::join_probe<2,2>(_enumindex551, std::array<u64,2>{v_c97, v_c86}, [&](const std::array<u64,2>& m580) {
                slog::join_probe<3,1>(deltaindex552, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m581) {
                  u64 v_c98 = m581[1]; u64 v_c43 = m581[2];
                  slog::join_probe<1,1>(arithmetic_opindex553, std::array<u64,1>{v_c43}, [&](const std::array<u64,1>& m582) {
                    bool ok583 = true;
                    u64 v_c99 = _prim_aslst(db, v_c10, &ok583);
                    if (!ok583) return;
                    u64 v_c201 = _prim_llen(db, v_c99);
                    if (v_c201 == slog_error) { slog::emit_pending_error(db, "interp.slog:111"); return; }
                    if (v_c87 != v_c201) return;
                    bool ok584 = true;
                    u64 v_c202 = _prim_lref(db, v_c99, v_c88, &ok584);
                    if (!ok584) return;
                    if (v_c97 != v_c202) return;
                    bool ok585 = true;
                    u64 v_c203 = _prim_lref(db, v_c99, v_c89, &ok585);
                    if (!ok585) return;
                    if (v_c97 != v_c203) return;
                    ++_fires;
                    if (!((is_struct(v_c97) && (decode_struct_id(v_c97) == sid554 || decode_struct_id(v_c97) == sid555 || decode_struct_id(v_c97) == sid556 || decode_struct_id(v_c97) == sid557 || decode_struct_id(v_c97) == sid558))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c94, v_c95, v_c96, v_c97}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c98, v_c97}, std::array<u16,2>{0, 1});
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
        ReadTask559* _cont = new ReadTask559(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask559(db,b), false);
  // (crule (pre) (scan boolean __t6acM194 b) (body (join-old eval (1 2 0) 1 (1 2 0) __t6acM194 c __t6kpB195)) (head (emit-temp temp0LsC994 __t6kpB195 b) (mkstruct boolval (1 0) __t7v8e193 b)) interp.slog:27 #f)
  class ReadTask588 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex586;  slog::Index** evaldelta587;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0LsC994");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("boolean");
      std::vector<u16> ord589({1, 2, 0});
      slog::Relation* readrel590 = db->getRelation("eval");
      evalindex586 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 2, 0});
      slog::Relation* readrel592 = db->getRelation("eval");
      evaldelta587 = readrel592->getIndex(ord591, true);
  
    }
    ReadTask588(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c204 = _t[0];
        u64 v_c71 = _t[1];
        slog::join_probe_old<3,1>(evalindex586, evaldelta587, std::array<u64,3>{v_c204, 0, 0}, [&](const std::array<u64,3>& m593) {
          u64 v_c19 = m593[1]; u64 v_c205 = m593[2];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c205, v_c71});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:27", "delta:boolean", _fires);
  
      if (!_done)
      {
        ReadTask588* _cont = new ReadTask588(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask588(db,b), false);
  // (crule (pre (let __tconst9IXP677 constcd2a69ce5ca278db1d6da969) (let __tconst51tI19 const06abaa100ecef791ce028c56) (let _00024sqc4T4Y544 constd4735e3a265e16eee03f5971) (let _00024sqc7lRr545 const5feceb66ffc86f38d952786c) (let _00024sqc1s5u546 const6b86b273ff34fce19d6b804e) (let _00024sqo831x547 const5feceb66ffc86f38d952786c) (let _00024sqo8QLE548 const6b86b273ff34fce19d6b804e) (let _00024sqo7qSx549 const6b86b273ff34fce19d6b804e) (let _00024sqo2F2K550 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo8QLE548 __t1v1r22 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo831x547 __t1v1r22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7qSx549 __t1v1r22 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2F2K550 __t1v1r22 _00024seq2) (join _enum (0 1) 2 __t1v1r22 __tconst9IXP677) (join delta (1 2 0) 2 __tconst51tI19 _00024seq2 __t4bAF20) (join any_bool (0) 0 b) (letp _00024sql3fFG542 (aslst _00024seq2)) (let chk37Do1040 (llen _00024sql3fFG542)) (eq _00024sqc4T4Y544 chk37Do1040) (letp chk4fhf1041 (lref _00024sql3fFG542 _00024sqc7lRr545)) (eq __t1v1r22 chk4fhf1041) (letp chk6KvJ1042 (lref _00024sql3fFG542 _00024sqc1s5u546)) (eq __t1v1r22 chk6KvJ1042)) (head (emit-temp temp46yO1034 __t4bAF20 b) (mkstruct boolval (1 0) __t6st618 b)) interp.slog:121 #f)
  class ReadTask602 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex594;  slog::Index** $seq_atrindex595;  slog::Index** $seq_atrindex596;  slog::Index** _enumindex597;  slog::Index** deltaindex598;  slog::Index** any_boolindex599;  slog::Index** $seq_atrdelta600;  slog::Index** $seq_atrdelta601;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp46yO1034");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord603({1, 0, 2});
      slog::Relation* readrel604 = db->getRelation("$seq_at");
      driver_index = readrel604->getIndex(ord603, true);
      std::vector<u16> ord605({1, 0, 2});
      slog::Relation* readrel606 = db->getRelation("$seq_at");
      $seq_atindex594 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({1, 0, 2});
      slog::Relation* readrel608 = db->getRelation("$seq_atr");
      $seq_atrindex595 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({1, 0, 2});
      slog::Relation* readrel610 = db->getRelation("$seq_atr");
      $seq_atrdelta600 = readrel610->getIndex(ord609, true);
      std::vector<u16> ord611({1, 0, 2});
      slog::Relation* readrel612 = db->getRelation("$seq_atr");
      $seq_atrindex596 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({1, 0, 2});
      slog::Relation* readrel614 = db->getRelation("$seq_atr");
      $seq_atrdelta601 = readrel614->getIndex(ord613, true);
      std::vector<u16> ord615({0, 1});
      slog::Relation* readrel616 = db->getRelation("_enum");
      _enumindex597 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 2, 0});
      slog::Relation* readrel618 = db->getRelation("delta");
      deltaindex598 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({0});
      slog::Relation* readrel620 = db->getRelation("any_bool");
      any_boolindex599 = readrel620->getIndex(ord619, false);
  
    }
    ReadTask602(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c109 = v_const06abaa100ecef791ce028c56;
      u64 v_c110 = v_constd4735e3a265e16eee03f5971;
      u64 v_c111 = v_const5feceb66ffc86f38d952786c;
      u64 v_c112 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c113 = v_const5feceb66ffc86f38d952786c;
      u64 v_c114 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c115 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c116 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c114, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m621) {
        u64 v_c119 = m621[1];
        u64 v_c10 = m621[2];
        if (buckethash(v_c119) != bucket) return;
        slog::join_probe<3,3>($seq_atindex594, std::array<u64,3>{v_c113, v_c119, v_c10}, [&](const std::array<u64,3>& m622) {
          slog::join_probe_old<3,3>($seq_atrindex595, $seq_atrdelta600, std::array<u64,3>{v_c115, v_c119, v_c10}, [&](const std::array<u64,3>& m623) {
            slog::join_probe_old<3,3>($seq_atrindex596, $seq_atrdelta601, std::array<u64,3>{v_c116, v_c119, v_c10}, [&](const std::array<u64,3>& m624) {
              slog::join_probe<2,2>(_enumindex597, std::array<u64,2>{v_c119, v_c108}, [&](const std::array<u64,2>& m625) {
                slog::join_probe<3,2>(deltaindex598, std::array<u64,3>{v_c109, v_c10, 0}, [&](const std::array<u64,3>& m626) {
                  u64 v_c117 = m626[2];
                  slog::join_all<1>(any_boolindex599, [&](const std::array<u64,1>& m627) {
                    u64 v_c71 = m627[0];
                    bool ok628 = true;
                    u64 v_c118 = _prim_aslst(db, v_c10, &ok628);
                    if (!ok628) return;
                    u64 v_c206 = _prim_llen(db, v_c118);
                    if (v_c206 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c110 != v_c206) return;
                    bool ok629 = true;
                    u64 v_c207 = _prim_lref(db, v_c118, v_c111, &ok629);
                    if (!ok629) return;
                    if (v_c119 != v_c207) return;
                    bool ok630 = true;
                    u64 v_c208 = _prim_lref(db, v_c118, v_c112, &ok630);
                    if (!ok630) return;
                    if (v_c119 != v_c208) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c117, v_c71});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,2>{1, 0});
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
        ReadTask602* _cont = new ReadTask602(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask602(db,b), false);
  // (crule (pre) (scan tick_ans __t0DSy30 l) (body (join-old tick (0 2 1) 1 (0 2 1) __t0DSy30 c __t8j7u29) (exists eval (2 0 1) 1 c) (exists eval_args (2 0 1) 1 c) (join eval (1 2 0) 2 __t8j7u29 c __4cUN684) (join-old eval (2 0 1) 1 (2 0 1) c __t5MCM24 ef) (exists eval_ans (0 1) 1 __t5MCM24) (join-old app (0 1 2) 2 (0 1 2) __t8j7u29 ef es) (join-old eval_args (1 2 0) 2 (1 2 0) es c __t5BFX27) (exists eval_args_ans (0 1) 1 __t5BFX27) (join eval_ans (0 1) 1 __t5MCM24 __t3Pto26) (join eval_args_ans (0 1) 1 __t5BFX27 vs) (join-old closure (0 1 2) 1 (0 1 2) __t3Pto26 __t0xip28 cb) (exists binding (1 0 2) 1 cb) (join freevar (1 0) 1 __t0xip28 y) (join binding (0 1 2) 2 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t0xip28 xs eb)) (head (emit binding (0 1 2) y l vy) (emit binding_event (0 1 2) y l c)) interp.slog:56 #f)
  class ReadTask653 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tickindex631;  slog::Index** evalindex632;  slog::Index** eval_argsindex633;  slog::Index** evalindex634;  slog::Index** evalindex635;  slog::Index** eval_ansindex636;  slog::Index** appindex637;  slog::Index** eval_argsindex638;  slog::Index** eval_args_ansindex639;  slog::Index** eval_ansindex640;  slog::Index** eval_args_ansindex641;  slog::Index** closureindex642;  slog::Index** bindingindex643;  slog::Index** freevarindex644;  slog::Index** bindingindex645;  slog::Index** lambdaindex646;  slog::Index** tickdelta647;  slog::Index** evaldelta648;  slog::Index** appdelta649;  slog::Index** eval_argsdelta650;  slog::Index** closuredelta651;  slog::Index** lambdadelta652;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("binding");
      std::vector<u16> ord654({0, 1, 2});
      slog::Relation* readrel655 = db->getRelation("binding");
      head_index[0] = readrel655->getIndex(ord654, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord656({0, 1, 2});
      slog::Relation* readrel657 = db->getRelation("binding_event");
      head_index[1] = readrel657->getIndex(ord656, false);
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord658({0, 2, 1});
      slog::Relation* readrel659 = db->getRelation("tick");
      tickindex631 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({0, 2, 1});
      slog::Relation* readrel661 = db->getRelation("tick");
      tickdelta647 = readrel661->getIndex(ord660, true);
      std::vector<u16> ord662({2, 0, 1});
      slog::Relation* readrel663 = db->getRelation("eval");
      evalindex632 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({2, 0, 1});
      slog::Relation* readrel665 = db->getRelation("eval_args");
      eval_argsindex633 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 0});
      slog::Relation* readrel667 = db->getRelation("eval");
      evalindex634 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({2, 0, 1});
      slog::Relation* readrel669 = db->getRelation("eval");
      evalindex635 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({2, 0, 1});
      slog::Relation* readrel671 = db->getRelation("eval");
      evaldelta648 = readrel671->getIndex(ord670, true);
      std::vector<u16> ord672({0, 1});
      slog::Relation* readrel673 = db->getRelation("eval_ans");
      eval_ansindex636 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({0, 1, 2});
      slog::Relation* readrel675 = db->getRelation("app");
      appindex637 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({0, 1, 2});
      slog::Relation* readrel677 = db->getRelation("app");
      appdelta649 = readrel677->getIndex(ord676, true);
      std::vector<u16> ord678({1, 2, 0});
      slog::Relation* readrel679 = db->getRelation("eval_args");
      eval_argsindex638 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 2, 0});
      slog::Relation* readrel681 = db->getRelation("eval_args");
      eval_argsdelta650 = readrel681->getIndex(ord680, true);
      std::vector<u16> ord682({0, 1});
      slog::Relation* readrel683 = db->getRelation("eval_args_ans");
      eval_args_ansindex639 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("eval_ans");
      eval_ansindex640 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({0, 1});
      slog::Relation* readrel687 = db->getRelation("eval_args_ans");
      eval_args_ansindex641 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1, 2});
      slog::Relation* readrel689 = db->getRelation("closure");
      closureindex642 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({0, 1, 2});
      slog::Relation* readrel691 = db->getRelation("closure");
      closuredelta651 = readrel691->getIndex(ord690, true);
      std::vector<u16> ord692({1, 0, 2});
      slog::Relation* readrel693 = db->getRelation("binding");
      bindingindex643 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 0});
      slog::Relation* readrel695 = db->getRelation("freevar");
      freevarindex644 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({0, 1, 2});
      slog::Relation* readrel697 = db->getRelation("binding");
      bindingindex645 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({0, 1, 2});
      slog::Relation* readrel699 = db->getRelation("lambda");
      lambdaindex646 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({0, 1, 2});
      slog::Relation* readrel701 = db->getRelation("lambda");
      lambdadelta652 = readrel701->getIndex(ord700, true);
  
    }
    ReadTask653(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c153 = _t[0];
        u64 v_c155 = _t[1];
        slog::join_probe_old<3,1>(tickindex631, tickdelta647, std::array<u64,3>{v_c153, 0, 0}, [&](const std::array<u64,3>& m702) {
          u64 v_c19 = m702[1]; u64 v_c151 = m702[2];
          if (!slog::exists_probe<3,1>(evalindex632, std::array<u64,3>{v_c19, 0, 0})) return;
          if (!slog::exists_probe<3,1>(eval_argsindex633, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe<3,2>(evalindex634, std::array<u64,3>{v_c151, v_c19, 0}, [&](const std::array<u64,3>& m703) {
            u64 v_c150 = m703[2];
            slog::join_probe_old<3,1>(evalindex635, evaldelta648, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m704) {
              u64 v_c148 = m704[1]; u64 v_c29 = m704[2];
              if (!slog::exists_probe<2,1>(eval_ansindex636, std::array<u64,2>{v_c148, 0})) return;
              slog::join_probe_old<3,2>(appindex637, appdelta649, std::array<u64,3>{v_c151, v_c29, 0}, [&](const std::array<u64,3>& m705) {
                u64 v_c30 = m705[2];
                slog::join_probe_old<3,2>(eval_argsindex638, eval_argsdelta650, std::array<u64,3>{v_c30, v_c19, 0}, [&](const std::array<u64,3>& m706) {
                  u64 v_c152 = m706[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex639, std::array<u64,2>{v_c152, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex640, std::array<u64,2>{v_c148, 0}, [&](const std::array<u64,2>& m707) {
                    u64 v_c149 = m707[1];
                    slog::join_probe<2,1>(eval_args_ansindex641, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m708) {
                      u64 v_c154 = m708[1];
                      slog::join_probe_old<3,1>(closureindex642, closuredelta651, std::array<u64,3>{v_c149, 0, 0}, [&](const std::array<u64,3>& m709) {
                        u64 v_c156 = m709[1]; u64 v_c49 = m709[2];
                        if (!slog::exists_probe<3,1>(bindingindex643, std::array<u64,3>{v_c49, 0, 0})) return;
                        slog::join_probe<2,1>(freevarindex644, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m710) {
                          u64 v_c48 = m710[1];
                          slog::join_probe<3,2>(bindingindex645, std::array<u64,3>{v_c48, v_c49, 0}, [&](const std::array<u64,3>& m711) {
                            u64 v_c50 = m711[2];
                            slog::join_probe_old<3,1>(lambdaindex646, lambdadelta652, std::array<u64,3>{v_c156, 0, 0}, [&](const std::array<u64,3>& m712) {
                              u64 v_c52 = m712[1]; u64 v_c53 = m712[2];
                              ++_fires;
                              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c48, v_c155, v_c50}, std::array<u16,3>{0, 1, 2});
                              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c48, v_c155, v_c19}, std::array<u16,3>{0, 1, 2});
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
        ReadTask653* _cont = new ReadTask653(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask653(db,b), false);
  // (crule (pre (let __tconst03NO760 constb9e118781cea1f9fa01462e0) (let __tconst3fuu217 const06abaa100ecef791ce028c56) (let _00024sqc1fPN569 constd4735e3a265e16eee03f5971) (let _00024sqc78q5570 const5feceb66ffc86f38d952786c) (let _00024sqc5TDx571 const6b86b273ff34fce19d6b804e) (let _00024sqo1Czp572 const5feceb66ffc86f38d952786c) (let _00024sqo2Uyj573 const6b86b273ff34fce19d6b804e) (let _00024sqo2qsW574 const6b86b273ff34fce19d6b804e) (let _00024sqo2mjM575 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo2Uyj573 v2 _00024seq0) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2mjM575 v2 _00024seq0) (letp _00024sql8W3E567 (aslst _00024seq0)) (letp v1 (lref _00024sql8W3E567 _00024sqc78q5570)) (neq v1 v2) (join $seq_at (1 0 2) 3 _00024sqo1Czp572 v1 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2qsW574 v1 _00024seq0) (exists _enum (1 0) 1 __tconst03NO760) (join delta (1 2 0) 2 __tconst3fuu217 _00024seq0 __t12h7218) (join _enum (1 0) 1 __tconst03NO760 __t6tMS215) (let chk9IAL1095 (llen _00024sql8W3E567)) (eq _00024sqc1fPN569 chk9IAL1095) (letp chk7GiI1096 (lref _00024sql8W3E567 _00024sqc5TDx571)) (eq v2 chk7GiI1096)) (head (emit-temp temp4VE71091 __t12h7218) (mkstruct boolval (1 0) __t5boA216 __t6tMS215)) interp.slog:120 #f)
  class ReadTask721 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex713;  slog::Index** $seq_atindex714;  slog::Index** $seq_atrindex715;  slog::Index** _enumindex716;  slog::Index** deltaindex717;  slog::Index** _enumindex718;  slog::Index** $seq_atrdelta719;  slog::Index** $seq_atrdelta720;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4VE71091");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord722({1, 0, 2});
      slog::Relation* readrel723 = db->getRelation("$seq_at");
      driver_index = readrel723->getIndex(ord722, true);
      std::vector<u16> ord724({1, 0, 2});
      slog::Relation* readrel725 = db->getRelation("$seq_atr");
      $seq_atrindex713 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({1, 0, 2});
      slog::Relation* readrel727 = db->getRelation("$seq_atr");
      $seq_atrdelta719 = readrel727->getIndex(ord726, true);
      std::vector<u16> ord728({1, 0, 2});
      slog::Relation* readrel729 = db->getRelation("$seq_at");
      $seq_atindex714 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({1, 0, 2});
      slog::Relation* readrel731 = db->getRelation("$seq_atr");
      $seq_atrindex715 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 0, 2});
      slog::Relation* readrel733 = db->getRelation("$seq_atr");
      $seq_atrdelta720 = readrel733->getIndex(ord732, true);
      std::vector<u16> ord734({1, 0});
      slog::Relation* readrel735 = db->getRelation("_enum");
      _enumindex716 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({1, 2, 0});
      slog::Relation* readrel737 = db->getRelation("delta");
      deltaindex717 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({1, 0});
      slog::Relation* readrel739 = db->getRelation("_enum");
      _enumindex718 = readrel739->getIndex(ord738, false);
  
    }
    ReadTask721(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c209 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c210 = v_const06abaa100ecef791ce028c56;
      u64 v_c211 = v_constd4735e3a265e16eee03f5971;
      u64 v_c212 = v_const5feceb66ffc86f38d952786c;
      u64 v_c213 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c214 = v_const5feceb66ffc86f38d952786c;
      u64 v_c215 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c216 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c217 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c215, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m740) {
        u64 v_c218 = m740[1];
        u64 v_c170 = m740[2];
        if (buckethash(v_c218) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex713, $seq_atrdelta719, std::array<u64,3>{v_c217, v_c218, v_c170}, [&](const std::array<u64,3>& m741) {
          bool ok742 = true;
          u64 v_c219 = _prim_aslst(db, v_c170, &ok742);
          if (!ok742) return;
          bool ok743 = true;
          u64 v_c220 = _prim_lref(db, v_c219, v_c212, &ok743);
          if (!ok743) return;
          if (v_c220 == v_c218) return;
          slog::join_probe<3,3>($seq_atindex714, std::array<u64,3>{v_c214, v_c220, v_c170}, [&](const std::array<u64,3>& m744) {
            slog::join_probe_old<3,3>($seq_atrindex715, $seq_atrdelta720, std::array<u64,3>{v_c216, v_c220, v_c170}, [&](const std::array<u64,3>& m745) {
              if (!slog::exists_probe<2,1>(_enumindex716, std::array<u64,2>{v_c209, 0})) return;
              slog::join_probe<3,2>(deltaindex717, std::array<u64,3>{v_c210, v_c170, 0}, [&](const std::array<u64,3>& m746) {
                u64 v_c221 = m746[2];
                slog::join_probe<2,1>(_enumindex718, std::array<u64,2>{v_c209, 0}, [&](const std::array<u64,2>& m747) {
                  u64 v_c222 = m747[1];
                  u64 v_c223 = _prim_llen(db, v_c219);
                  if (v_c223 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c211 != v_c223) return;
                  bool ok748 = true;
                  u64 v_c224 = _prim_lref(db, v_c219, v_c213, &ok748);
                  if (!ok748) return;
                  if (v_c218 != v_c224) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c221});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c222}, std::array<u16,2>{1, 0});
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
        ReadTask721* _cont = new ReadTask721(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask721(db,b), false);
  // (crule (pre) (scan tick __t3z31201 __t0nYt200 c) (body (exists eval (2 0 1) 1 c) (exists $sup56712x41x0x0x0 (1 0 2 3) 1 c) (exists eval_args (2 0 1) 1 c) (join tick_ans (0 1) 1 __t3z31201 __v0) (join eval (2 0 1) 1 c __t44Jo196 ef) (exists $sup56712x41x0x0x0 (1 2 3 0) 2 c ef) (exists eval_ans (0 1) 1 __t44Jo196) (join app (0 1 2) 2 __t0nYt200 ef es) (exists eval_args (1 2 0) 2 es c) (join $sup56712x41x0x0x0 (1 2 3 0) 3 c ef es __d0) (join eval_args (1 2 0) 2 es c __t3i0k199) (exists eval_args_ans (0 1) 1 __t3i0k199) (join eval_ans (0 1) 1 __t44Jo196 __t4ROj198) (join eval_args_ans (0 1) 1 __t3i0k199 vs) (join closure (0 1 2) 1 __t4ROj198 __t2BTJ197 cb) (join lambda (0 1 2) 1 __t2BTJ197 xs eb)) (head (mkstruct eval (1 2 0) __2uja685 eb __v0)) interp.slog:42 #f)
  class ReadTask765 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex749;  slog::Index** $sup56712x41x0x0x0index750;  slog::Index** eval_argsindex751;  slog::Index** tick_ansindex752;  slog::Index** evalindex753;  slog::Index** $sup56712x41x0x0x0index754;  slog::Index** eval_ansindex755;  slog::Index** appindex756;  slog::Index** eval_argsindex757;  slog::Index** $sup56712x41x0x0x0index758;  slog::Index** eval_argsindex759;  slog::Index** eval_args_ansindex760;  slog::Index** eval_ansindex761;  slog::Index** eval_args_ansindex762;  slog::Index** closureindex763;  slog::Index** lambdaindex764;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord766({2, 0, 1});
      slog::Relation* readrel767 = db->getRelation("eval");
      evalindex749 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 0, 2, 3});
      slog::Relation* readrel769 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index750 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({2, 0, 1});
      slog::Relation* readrel771 = db->getRelation("eval_args");
      eval_argsindex751 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({0, 1});
      slog::Relation* readrel773 = db->getRelation("tick_ans");
      tick_ansindex752 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({2, 0, 1});
      slog::Relation* readrel775 = db->getRelation("eval");
      evalindex753 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 2, 3, 0});
      slog::Relation* readrel777 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index754 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({0, 1});
      slog::Relation* readrel779 = db->getRelation("eval_ans");
      eval_ansindex755 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({0, 1, 2});
      slog::Relation* readrel781 = db->getRelation("app");
      appindex756 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({1, 2, 0});
      slog::Relation* readrel783 = db->getRelation("eval_args");
      eval_argsindex757 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({1, 2, 3, 0});
      slog::Relation* readrel785 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index758 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({1, 2, 0});
      slog::Relation* readrel787 = db->getRelation("eval_args");
      eval_argsindex759 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({0, 1});
      slog::Relation* readrel789 = db->getRelation("eval_args_ans");
      eval_args_ansindex760 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({0, 1});
      slog::Relation* readrel791 = db->getRelation("eval_ans");
      eval_ansindex761 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({0, 1});
      slog::Relation* readrel793 = db->getRelation("eval_args_ans");
      eval_args_ansindex762 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({0, 1, 2});
      slog::Relation* readrel795 = db->getRelation("closure");
      closureindex763 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({0, 1, 2});
      slog::Relation* readrel797 = db->getRelation("lambda");
      lambdaindex764 = readrel797->getIndex(ord796, false);
  
    }
    ReadTask765(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c225 = _t[0];
        u64 v_c226 = _t[1];
        u64 v_c19 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex749, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup56712x41x0x0x0index750, std::array<u64,4>{v_c19, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(eval_argsindex751, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe<2,1>(tick_ansindex752, std::array<u64,2>{v_c225, 0}, [&](const std::array<u64,2>& m798) {
          u64 v_c135 = m798[1];
          slog::join_probe<3,1>(evalindex753, std::array<u64,3>{v_c19, 0, 0}, [&](const std::array<u64,3>& m799) {
            u64 v_c227 = m799[1]; u64 v_c29 = m799[2];
            if (!slog::exists_probe<4,2>($sup56712x41x0x0x0index754, std::array<u64,4>{v_c19, v_c29, 0, 0})) return;
            if (!slog::exists_probe<2,1>(eval_ansindex755, std::array<u64,2>{v_c227, 0})) return;
            slog::join_probe<3,2>(appindex756, std::array<u64,3>{v_c226, v_c29, 0}, [&](const std::array<u64,3>& m800) {
              u64 v_c30 = m800[2];
              if (!slog::exists_probe<3,2>(eval_argsindex757, std::array<u64,3>{v_c30, v_c19, 0})) return;
              slog::join_probe<4,3>($sup56712x41x0x0x0index758, std::array<u64,4>{v_c19, v_c29, v_c30, 0}, [&](const std::array<u64,4>& m801) {
                u64 v_c228 = m801[3];
                slog::join_probe<3,2>(eval_argsindex759, std::array<u64,3>{v_c30, v_c19, 0}, [&](const std::array<u64,3>& m802) {
                  u64 v_c229 = m802[2];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex760, std::array<u64,2>{v_c229, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex761, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m803) {
                    u64 v_c230 = m803[1];
                    slog::join_probe<2,1>(eval_args_ansindex762, std::array<u64,2>{v_c229, 0}, [&](const std::array<u64,2>& m804) {
                      u64 v_c154 = m804[1];
                      slog::join_probe<3,1>(closureindex763, std::array<u64,3>{v_c230, 0, 0}, [&](const std::array<u64,3>& m805) {
                        u64 v_c231 = m805[1]; u64 v_c49 = m805[2];
                        slog::join_probe<3,1>(lambdaindex764, std::array<u64,3>{v_c231, 0, 0}, [&](const std::array<u64,3>& m806) {
                          u64 v_c52 = m806[1]; u64 v_c53 = m806[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c53, v_c135}, std::array<u16,3>{1, 2, 0});
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
        ReadTask765* _cont = new ReadTask765(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask765(db,b), false);
  // (crule (pre (let __trid2HFE691 const119eb3a23d030ee0dfe9f807) (let __trel6q3e692 conste90c92f3e6c3b47a7bc93e42) (let __tcol8uSO693 const5feceb66ffc86f38d952786c) (let __trel7YjB694 conste90c92f3e6c3b47a7bc93e42) (let __tcol46om695 const6b86b273ff34fce19d6b804e)) (scan $sup56712x41x0x0x0 __d0 c ef es) (body) (head (tycheck es (accept seq) __trid2HFE691 __trel6q3e692 __tcol8uSO693 (1 2 3 4 0)) (tycheck c (accept seq) __trid2HFE691 __trel7YjB694 __tcol46om695 (1 2 3 4 0)) (mkstruct eval_args (1 2 0) __0waD690 es c)) interp.slog:42 #f)
  class ReadTask807 : public slog::Task
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
    ReadTask807(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c232 = v_const119eb3a23d030ee0dfe9f807;
      u64 v_c233 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c234 = v_const5feceb66ffc86f38d952786c;
      u64 v_c235 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c236 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c228 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c30 = _t[3];
        ++_fires;
        if (!(is_seq(v_c30)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c232, v_c233, v_c234, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c19)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c232, v_c235, v_c236, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c30, v_c19}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:42", "delta:$sup56712x41x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst3bSs155 const06abaa100ecef791ce028c56) (let _00024sqc3YlI510 constd4735e3a265e16eee03f5971) (let _00024sqc65nX511 const5feceb66ffc86f38d952786c) (let _00024sqc75b9512 const6b86b273ff34fce19d6b804e) (let _00024sqo3TKl513 const5feceb66ffc86f38d952786c) (let _00024sqo2IHZ514 const6b86b273ff34fce19d6b804e) (let _00024sqo1Kdp515 const6b86b273ff34fce19d6b804e) (let _00024sqo0AcC516 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo1Kdp515 __t59ft158 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo3TKl513 __t59ft158 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo2IHZ514 __t59ft158 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0AcC516 __t59ft158 _00024seq2) (join delta (1 2 0) 2 __tconst3bSs155 _00024seq2 __t2lyA156) (join closure (0 1 2) 1 __t59ft158 lm cb) (join any_bool (0) 0 b) (letp _00024sql2qfO508 (aslst _00024seq2)) (let chk3oOQ1140 (llen _00024sql2qfO508)) (eq _00024sqc3YlI510 chk3oOQ1140) (letp chk9sw21141 (lref _00024sql2qfO508 _00024sqc65nX511)) (eq __t59ft158 chk9sw21141) (letp chk595t1142 (lref _00024sql2qfO508 _00024sqc75b9512)) (eq __t59ft158 chk595t1142)) (head (emit-temp temp3KOr1128 __t2lyA156 b) (mkstruct boolval (1 0) __t5Aug154 b)) interp.slog:122 #f)
  class ReadTask815 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex808;  slog::Index** $seq_atindex809;  slog::Index** $seq_atrindex810;  slog::Index** deltaindex811;  slog::Index** closureindex812;  slog::Index** any_boolindex813;  slog::Index** $seq_atrdelta814;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3KOr1128");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord816({1, 0, 2});
      slog::Relation* readrel817 = db->getRelation("$seq_atr");
      driver_index = readrel817->getIndex(ord816, true);
      std::vector<u16> ord818({1, 0, 2});
      slog::Relation* readrel819 = db->getRelation("$seq_at");
      $seq_atindex808 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 0, 2});
      slog::Relation* readrel821 = db->getRelation("$seq_at");
      $seq_atindex809 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 0, 2});
      slog::Relation* readrel823 = db->getRelation("$seq_atr");
      $seq_atrindex810 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({1, 0, 2});
      slog::Relation* readrel825 = db->getRelation("$seq_atr");
      $seq_atrdelta814 = readrel825->getIndex(ord824, true);
      std::vector<u16> ord826({1, 2, 0});
      slog::Relation* readrel827 = db->getRelation("delta");
      deltaindex811 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({0, 1, 2});
      slog::Relation* readrel829 = db->getRelation("closure");
      closureindex812 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({0});
      slog::Relation* readrel831 = db->getRelation("any_bool");
      any_boolindex813 = readrel831->getIndex(ord830, false);
  
    }
    ReadTask815(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c237 = v_const06abaa100ecef791ce028c56;
      u64 v_c238 = v_constd4735e3a265e16eee03f5971;
      u64 v_c239 = v_const5feceb66ffc86f38d952786c;
      u64 v_c240 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c241 = v_const5feceb66ffc86f38d952786c;
      u64 v_c242 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c243 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c244 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c243, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m832) {
        u64 v_c245 = m832[1];
        u64 v_c10 = m832[2];
        if (buckethash(v_c245) != bucket) return;
        slog::join_probe<3,3>($seq_atindex808, std::array<u64,3>{v_c241, v_c245, v_c10}, [&](const std::array<u64,3>& m833) {
          slog::join_probe<3,3>($seq_atindex809, std::array<u64,3>{v_c242, v_c245, v_c10}, [&](const std::array<u64,3>& m834) {
            slog::join_probe_old<3,3>($seq_atrindex810, $seq_atrdelta814, std::array<u64,3>{v_c244, v_c245, v_c10}, [&](const std::array<u64,3>& m835) {
              slog::join_probe<3,2>(deltaindex811, std::array<u64,3>{v_c237, v_c10, 0}, [&](const std::array<u64,3>& m836) {
                u64 v_c246 = m836[2];
                slog::join_probe<3,1>(closureindex812, std::array<u64,3>{v_c245, 0, 0}, [&](const std::array<u64,3>& m837) {
                  u64 v_c247 = m837[1]; u64 v_c49 = m837[2];
                  slog::join_all<1>(any_boolindex813, [&](const std::array<u64,1>& m838) {
                    u64 v_c71 = m838[0];
                    bool ok839 = true;
                    u64 v_c248 = _prim_aslst(db, v_c10, &ok839);
                    if (!ok839) return;
                    u64 v_c249 = _prim_llen(db, v_c248);
                    if (v_c249 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c238 != v_c249) return;
                    bool ok840 = true;
                    u64 v_c250 = _prim_lref(db, v_c248, v_c239, &ok840);
                    if (!ok840) return;
                    if (v_c245 != v_c250) return;
                    bool ok841 = true;
                    u64 v_c251 = _prim_lref(db, v_c248, v_c240, &ok841);
                    if (!ok841) return;
                    if (v_c245 != v_c251) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c246, v_c71});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,2>{1, 0});
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
        ReadTask815* _cont = new ReadTask815(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask815(db,b), false);
  // (crule (pre) (scan lambda __t75gL192 xs eb) (body (join freevar (1 0) 1 __t75gL192 y) (join binding (0 1 2) 1 y cb vy) (join-old eval (0 2 1) 0 (0 2 1) __36hc798 c __t36c5191) (join-old app (0 1 2) 1 (0 1 2) __t36c5191 ef es)) (head (mkstruct eval_args (1 2 0) __9QEA799 es c)) interp.slog:56 #f)
  class ReadTask848 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex842;  slog::Index** bindingindex843;  slog::Index** evalindex844;  slog::Index** appindex845;  slog::Index** evaldelta846;  slog::Index** appdelta847;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord849({1, 0});
      slog::Relation* readrel850 = db->getRelation("freevar");
      freevarindex842 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({0, 1, 2});
      slog::Relation* readrel852 = db->getRelation("binding");
      bindingindex843 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({0, 2, 1});
      slog::Relation* readrel854 = db->getRelation("eval");
      evalindex844 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({0, 2, 1});
      slog::Relation* readrel856 = db->getRelation("eval");
      evaldelta846 = readrel856->getIndex(ord855, true);
      std::vector<u16> ord857({0, 1, 2});
      slog::Relation* readrel858 = db->getRelation("app");
      appindex845 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({0, 1, 2});
      slog::Relation* readrel860 = db->getRelation("app");
      appdelta847 = readrel860->getIndex(ord859, true);
  
    }
    ReadTask848(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c252 = _t[0];
        u64 v_c52 = _t[1];
        u64 v_c53 = _t[2];
        slog::join_probe<2,1>(freevarindex842, std::array<u64,2>{v_c252, 0}, [&](const std::array<u64,2>& m861) {
          u64 v_c48 = m861[1];
          slog::join_probe<3,1>(bindingindex843, std::array<u64,3>{v_c48, 0, 0}, [&](const std::array<u64,3>& m862) {
            u64 v_c49 = m862[1]; u64 v_c50 = m862[2];
            slog::join_all_old<3>(evalindex844, evaldelta846, [&](const std::array<u64,3>& m863) {
              u64 v_c253 = m863[0]; u64 v_c19 = m863[1]; u64 v_c254 = m863[2];
              slog::join_probe_old<3,1>(appindex845, appdelta847, std::array<u64,3>{v_c254, 0, 0}, [&](const std::array<u64,3>& m864) {
                u64 v_c29 = m864[1]; u64 v_c30 = m864[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c30, v_c19}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:56", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask848* _cont = new ReadTask848(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask848(db,b), false);
  // (crule (pre) (scan eval_args __t58jO207 es c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 c) (exists eval_args_ans (0 1) 1 __t58jO207) (join $sup56712x41x0x0x0 (1 3 0 2) 2 c es __t9lTe203 ef) (exists app (1 2 0) 2 ef es) (exists eval (1 2 0) 2 ef c) (join eval (0 2 1) 2 __t9lTe203 c __t8x6E209) (join-old app (0 1 2) 3 (0 1 2) __t8x6E209 ef es) (exists tick (1 2 0) 2 __t8x6E209 c) (join eval (1 2 0) 2 ef c __t1DkM204) (exists eval_ans (0 1) 1 __t1DkM204) (join-old tick (1 2 0) 2 (1 2 0) __t8x6E209 c __t3KuN210) (exists tick_ans (0 1) 1 __t3KuN210) (join eval_ans (0 1) 1 __t1DkM204 __t6XAE206) (join eval_args_ans (0 1) 1 __t58jO207 vs) (join tick_ans (0 1) 1 __t3KuN210 __v0) (exists eval (2 0 1) 1 __v0) (join closure (0 1 2) 1 __t6XAE206 __t6hhS205 cb) (join lambda (0 1 2) 1 __t6hhS205 xs eb) (join-old eval (1 2 0) 2 (1 2 0) eb __v0 __t3K5j208) (join eval_ans (0 1) 1 __t3K5j208 v)) (head (emit eval_ans (0 1) __t9lTe203 v)) interp.slog:42 #f)
  class ReadTask890 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex865;  slog::Index** appindex866;  slog::Index** tickindex867;  slog::Index** eval_args_ansindex868;  slog::Index** $sup56712x41x0x0x0index869;  slog::Index** appindex870;  slog::Index** evalindex871;  slog::Index** evalindex872;  slog::Index** appindex873;  slog::Index** tickindex874;  slog::Index** evalindex875;  slog::Index** eval_ansindex876;  slog::Index** tickindex877;  slog::Index** tick_ansindex878;  slog::Index** eval_ansindex879;  slog::Index** eval_args_ansindex880;  slog::Index** tick_ansindex881;  slog::Index** evalindex882;  slog::Index** closureindex883;  slog::Index** lambdaindex884;  slog::Index** evalindex885;  slog::Index** eval_ansindex886;  slog::Index** appdelta887;  slog::Index** tickdelta888;  slog::Index** evaldelta889;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord891({0, 1});
      slog::Relation* readrel892 = db->getRelation("eval_ans");
      head_index[0] = readrel892->getIndex(ord891, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord893({2, 0, 1});
      slog::Relation* readrel894 = db->getRelation("eval");
      evalindex865 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({2, 0, 1});
      slog::Relation* readrel896 = db->getRelation("app");
      appindex866 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({2, 0, 1});
      slog::Relation* readrel898 = db->getRelation("tick");
      tickindex867 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({0, 1});
      slog::Relation* readrel900 = db->getRelation("eval_args_ans");
      eval_args_ansindex868 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({1, 3, 0, 2});
      slog::Relation* readrel902 = db->getRelation("$sup56712x41x0x0x0");
      $sup56712x41x0x0x0index869 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({1, 2, 0});
      slog::Relation* readrel904 = db->getRelation("app");
      appindex870 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({1, 2, 0});
      slog::Relation* readrel906 = db->getRelation("eval");
      evalindex871 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({0, 2, 1});
      slog::Relation* readrel908 = db->getRelation("eval");
      evalindex872 = readrel908->getIndex(ord907, false);
      std::vector<u16> ord909({0, 1, 2});
      slog::Relation* readrel910 = db->getRelation("app");
      appindex873 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({0, 1, 2});
      slog::Relation* readrel912 = db->getRelation("app");
      appdelta887 = readrel912->getIndex(ord911, true);
      std::vector<u16> ord913({1, 2, 0});
      slog::Relation* readrel914 = db->getRelation("tick");
      tickindex874 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({1, 2, 0});
      slog::Relation* readrel916 = db->getRelation("eval");
      evalindex875 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({0, 1});
      slog::Relation* readrel918 = db->getRelation("eval_ans");
      eval_ansindex876 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({1, 2, 0});
      slog::Relation* readrel920 = db->getRelation("tick");
      tickindex877 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({1, 2, 0});
      slog::Relation* readrel922 = db->getRelation("tick");
      tickdelta888 = readrel922->getIndex(ord921, true);
      std::vector<u16> ord923({0, 1});
      slog::Relation* readrel924 = db->getRelation("tick_ans");
      tick_ansindex878 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({0, 1});
      slog::Relation* readrel926 = db->getRelation("eval_ans");
      eval_ansindex879 = readrel926->getIndex(ord925, false);
      std::vector<u16> ord927({0, 1});
      slog::Relation* readrel928 = db->getRelation("eval_args_ans");
      eval_args_ansindex880 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({0, 1});
      slog::Relation* readrel930 = db->getRelation("tick_ans");
      tick_ansindex881 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({2, 0, 1});
      slog::Relation* readrel932 = db->getRelation("eval");
      evalindex882 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({0, 1, 2});
      slog::Relation* readrel934 = db->getRelation("closure");
      closureindex883 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({0, 1, 2});
      slog::Relation* readrel936 = db->getRelation("lambda");
      lambdaindex884 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({1, 2, 0});
      slog::Relation* readrel938 = db->getRelation("eval");
      evalindex885 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({1, 2, 0});
      slog::Relation* readrel940 = db->getRelation("eval");
      evaldelta889 = readrel940->getIndex(ord939, true);
      std::vector<u16> ord941({0, 1});
      slog::Relation* readrel942 = db->getRelation("eval_ans");
      eval_ansindex886 = readrel942->getIndex(ord941, false);
  
    }
    ReadTask890(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c255 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c19 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex865, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex866, std::array<u64,3>{v_c30, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex867, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex868, std::array<u64,2>{v_c255, 0})) return;
        slog::join_probe<4,2>($sup56712x41x0x0x0index869, std::array<u64,4>{v_c19, v_c30, 0, 0}, [&](const std::array<u64,4>& m943) {
          u64 v_c256 = m943[2]; u64 v_c29 = m943[3];
          if (!slog::exists_probe<3,2>(appindex870, std::array<u64,3>{v_c29, v_c30, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex871, std::array<u64,3>{v_c29, v_c19, 0})) return;
          slog::join_probe<3,2>(evalindex872, std::array<u64,3>{v_c256, v_c19, 0}, [&](const std::array<u64,3>& m944) {
            u64 v_c257 = m944[2];
            slog::join_probe_old<3,3>(appindex873, appdelta887, std::array<u64,3>{v_c257, v_c29, v_c30}, [&](const std::array<u64,3>& m945) {
              if (!slog::exists_probe<3,2>(tickindex874, std::array<u64,3>{v_c257, v_c19, 0})) return;
              slog::join_probe<3,2>(evalindex875, std::array<u64,3>{v_c29, v_c19, 0}, [&](const std::array<u64,3>& m946) {
                u64 v_c258 = m946[2];
                if (!slog::exists_probe<2,1>(eval_ansindex876, std::array<u64,2>{v_c258, 0})) return;
                slog::join_probe_old<3,2>(tickindex877, tickdelta888, std::array<u64,3>{v_c257, v_c19, 0}, [&](const std::array<u64,3>& m947) {
                  u64 v_c259 = m947[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex878, std::array<u64,2>{v_c259, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex879, std::array<u64,2>{v_c258, 0}, [&](const std::array<u64,2>& m948) {
                    u64 v_c260 = m948[1];
                    slog::join_probe<2,1>(eval_args_ansindex880, std::array<u64,2>{v_c255, 0}, [&](const std::array<u64,2>& m949) {
                      u64 v_c154 = m949[1];
                      slog::join_probe<2,1>(tick_ansindex881, std::array<u64,2>{v_c259, 0}, [&](const std::array<u64,2>& m950) {
                        u64 v_c135 = m950[1];
                        if (!slog::exists_probe<3,1>(evalindex882, std::array<u64,3>{v_c135, 0, 0})) return;
                        slog::join_probe<3,1>(closureindex883, std::array<u64,3>{v_c260, 0, 0}, [&](const std::array<u64,3>& m951) {
                          u64 v_c261 = m951[1]; u64 v_c49 = m951[2];
                          slog::join_probe<3,1>(lambdaindex884, std::array<u64,3>{v_c261, 0, 0}, [&](const std::array<u64,3>& m952) {
                            u64 v_c52 = m952[1]; u64 v_c53 = m952[2];
                            slog::join_probe_old<3,2>(evalindex885, evaldelta889, std::array<u64,3>{v_c53, v_c135, 0}, [&](const std::array<u64,3>& m953) {
                              u64 v_c262 = m953[2];
                              slog::join_probe<2,1>(eval_ansindex886, std::array<u64,2>{v_c262, 0}, [&](const std::array<u64,2>& m954) {
                                u64 v_c263 = m954[1];
                                ++_fires;
                                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c256, v_c263}, std::array<u16,2>{0, 1});
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
        ReadTask890* _cont = new ReadTask890(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask890(db,b), false);
  // (crule (pre (let __tconst7knU761 const0122baa3ac55f1b433944eb1) (let __tconst35kI244 const06abaa100ecef791ce028c56) (let _00024sqc59yj663 constd4735e3a265e16eee03f5971) (let _00024sqc7n8w664 const5feceb66ffc86f38d952786c) (let _00024sqc4sLR665 const6b86b273ff34fce19d6b804e) (let _00024sqo8MNY666 const5feceb66ffc86f38d952786c) (let _00024sqo0NcP667 const6b86b273ff34fce19d6b804e) (let _00024sqo0X3t668 const6b86b273ff34fce19d6b804e) (let _00024sqo6VJl669 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo8MNY666 __t1b46247 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo0NcP667 __t1b46247 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0X3t668 __t1b46247 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo6VJl669 __t1b46247 _00024seq2) (exists _enum (1 0) 1 __tconst7knU761) (join delta (1 2 0) 2 __tconst35kI244 _00024seq2 __t7NfZ245) (join _enum (1 0) 1 __tconst7knU761 __t4Ufa242) (join boolval (0 1) 1 __t1b46247 b) (letp _00024sql4qXJ661 (aslst _00024seq2)) (let chk2tte968 (llen _00024sql4qXJ661)) (eq _00024sqc59yj663 chk2tte968) (letp chk9vdJ969 (lref _00024sql4qXJ661 _00024sqc7n8w664)) (eq __t1b46247 chk9vdJ969) (letp chk2DI5970 (lref _00024sql4qXJ661 _00024sqc4sLR665)) (eq __t1b46247 chk2DI5970)) (head (emit-temp temp3tnu962 __t7NfZ245) (mkstruct boolval (1 0) __t0oTa243 __t4Ufa242)) interp.slog:118 #f)
  class ReadTask965 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex955;  slog::Index** $seq_atrindex956;  slog::Index** $seq_atrindex957;  slog::Index** _enumindex958;  slog::Index** deltaindex959;  slog::Index** _enumindex960;  slog::Index** boolvalindex961;  slog::Index** $seq_atdelta962;  slog::Index** $seq_atrdelta963;  slog::Index** $seq_atrdelta964;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3tnu962");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord966({1, 0, 2});
      slog::Relation* readrel967 = db->getRelation("$seq_at");
      driver_index = readrel967->getIndex(ord966, true);
      std::vector<u16> ord968({1, 0, 2});
      slog::Relation* readrel969 = db->getRelation("$seq_at");
      $seq_atindex955 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({1, 0, 2});
      slog::Relation* readrel971 = db->getRelation("$seq_at");
      $seq_atdelta962 = readrel971->getIndex(ord970, true);
      std::vector<u16> ord972({1, 0, 2});
      slog::Relation* readrel973 = db->getRelation("$seq_atr");
      $seq_atrindex956 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 0, 2});
      slog::Relation* readrel975 = db->getRelation("$seq_atr");
      $seq_atrdelta963 = readrel975->getIndex(ord974, true);
      std::vector<u16> ord976({1, 0, 2});
      slog::Relation* readrel977 = db->getRelation("$seq_atr");
      $seq_atrindex957 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({1, 0, 2});
      slog::Relation* readrel979 = db->getRelation("$seq_atr");
      $seq_atrdelta964 = readrel979->getIndex(ord978, true);
      std::vector<u16> ord980({1, 0});
      slog::Relation* readrel981 = db->getRelation("_enum");
      _enumindex958 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({1, 2, 0});
      slog::Relation* readrel983 = db->getRelation("delta");
      deltaindex959 = readrel983->getIndex(ord982, false);
      std::vector<u16> ord984({1, 0});
      slog::Relation* readrel985 = db->getRelation("_enum");
      _enumindex960 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({0, 1});
      slog::Relation* readrel987 = db->getRelation("boolval");
      boolvalindex961 = readrel987->getIndex(ord986, false);
  
    }
    ReadTask965(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c197 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c264 = v_const06abaa100ecef791ce028c56;
      u64 v_c265 = v_constd4735e3a265e16eee03f5971;
      u64 v_c266 = v_const5feceb66ffc86f38d952786c;
      u64 v_c267 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c268 = v_const5feceb66ffc86f38d952786c;
      u64 v_c269 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c270 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c271 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c268, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m988) {
        u64 v_c272 = m988[1];
        u64 v_c10 = m988[2];
        if (buckethash(v_c272) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex955, $seq_atdelta962, std::array<u64,3>{v_c269, v_c272, v_c10}, [&](const std::array<u64,3>& m989) {
          slog::join_probe_old<3,3>($seq_atrindex956, $seq_atrdelta963, std::array<u64,3>{v_c270, v_c272, v_c10}, [&](const std::array<u64,3>& m990) {
            slog::join_probe_old<3,3>($seq_atrindex957, $seq_atrdelta964, std::array<u64,3>{v_c271, v_c272, v_c10}, [&](const std::array<u64,3>& m991) {
              if (!slog::exists_probe<2,1>(_enumindex958, std::array<u64,2>{v_c197, 0})) return;
              slog::join_probe<3,2>(deltaindex959, std::array<u64,3>{v_c264, v_c10, 0}, [&](const std::array<u64,3>& m992) {
                u64 v_c198 = m992[2];
                slog::join_probe<2,1>(_enumindex960, std::array<u64,2>{v_c197, 0}, [&](const std::array<u64,2>& m993) {
                  u64 v_c199 = m993[1];
                  slog::join_probe<2,1>(boolvalindex961, std::array<u64,2>{v_c272, 0}, [&](const std::array<u64,2>& m994) {
                    u64 v_c71 = m994[1];
                    bool ok995 = true;
                    u64 v_c273 = _prim_aslst(db, v_c10, &ok995);
                    if (!ok995) return;
                    u64 v_c274 = _prim_llen(db, v_c273);
                    if (v_c274 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                    if (v_c265 != v_c274) return;
                    bool ok996 = true;
                    u64 v_c275 = _prim_lref(db, v_c273, v_c266, &ok996);
                    if (!ok996) return;
                    if (v_c272 != v_c275) return;
                    bool ok997 = true;
                    u64 v_c276 = _prim_lref(db, v_c273, v_c267, &ok997);
                    if (!ok997) return;
                    if (v_c272 != v_c276) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c198});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c199}, std::array<u16,2>{1, 0});
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
        ReadTask965* _cont = new ReadTask965(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask965(db,b), false);
  // (crule (pre (let __tconst65GN810 const0122baa3ac55f1b433944eb1) (let __tconst3VNs307 const06abaa100ecef791ce028c56) (let _00024sqc89jA519 constd4735e3a265e16eee03f5971) (let _00024sqc5bE7520 const5feceb66ffc86f38d952786c) (let _00024sqc5WD6521 const6b86b273ff34fce19d6b804e) (let _00024sqo7nH0522 const5feceb66ffc86f38d952786c) (let _00024sqo8HCy523 const6b86b273ff34fce19d6b804e) (let _00024sqo1Uwu524 const6b86b273ff34fce19d6b804e) (let _00024sqo9OPL525 const5feceb66ffc86f38d952786c)) (scan symval __t5ERV310 s) (body (exists $seq_at (1 0 2) 2 _00024sqo8HCy523 __t5ERV310) (exists $seq_atr (1 0 2) 2 _00024sqo1Uwu524 __t5ERV310) (exists $seq_atr (1 0 2) 2 _00024sqo9OPL525 __t5ERV310) (exists delta (1 2 0) 1 __tconst3VNs307) (exists _enum (1 0) 1 __tconst65GN810) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo7nH0522 __t5ERV310 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8HCy523 __t5ERV310 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Uwu524 __t5ERV310 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9OPL525 __t5ERV310 _00024seq2) (join delta (1 2 0) 2 __tconst3VNs307 _00024seq2 __t5HIm308) (join _enum (1 0) 1 __tconst65GN810 __t26fz305) (letp _00024sql2wmw517 (aslst _00024seq2)) (let chk8bCM1149 (llen _00024sql2wmw517)) (eq _00024sqc89jA519 chk8bCM1149) (letp chk8zik1150 (lref _00024sql2wmw517 _00024sqc5bE7520)) (eq __t5ERV310 chk8zik1150) (letp chk4EWx1151 (lref _00024sql2wmw517 _00024sqc5WD6521)) (eq __t5ERV310 chk4EWx1151)) (head (emit-temp temp0P9u1146 __t5HIm308) (mkstruct boolval (1 0) __t7uE5306 __t26fz305)) interp.slog:117 #f)
  class ReadTask1013 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex998;  slog::Index** $seq_atrindex999;  slog::Index** $seq_atrindex1000;  slog::Index** deltaindex1001;  slog::Index** _enumindex1002;  slog::Index** $seq_atindex1003;  slog::Index** $seq_atindex1004;  slog::Index** $seq_atrindex1005;  slog::Index** $seq_atrindex1006;  slog::Index** deltaindex1007;  slog::Index** _enumindex1008;  slog::Index** $seq_atdelta1009;  slog::Index** $seq_atdelta1010;  slog::Index** $seq_atrdelta1011;  slog::Index** $seq_atrdelta1012;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0P9u1146");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("symval");
      std::vector<u16> ord1014({1, 0, 2});
      slog::Relation* readrel1015 = db->getRelation("$seq_at");
      $seq_atindex998 = readrel1015->getIndex(ord1014, false);
      std::vector<u16> ord1016({1, 0, 2});
      slog::Relation* readrel1017 = db->getRelation("$seq_atr");
      $seq_atrindex999 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 0, 2});
      slog::Relation* readrel1019 = db->getRelation("$seq_atr");
      $seq_atrindex1000 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({1, 2, 0});
      slog::Relation* readrel1021 = db->getRelation("delta");
      deltaindex1001 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({1, 0});
      slog::Relation* readrel1023 = db->getRelation("_enum");
      _enumindex1002 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({1, 0, 2});
      slog::Relation* readrel1025 = db->getRelation("$seq_at");
      $seq_atindex1003 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 0, 2});
      slog::Relation* readrel1027 = db->getRelation("$seq_at");
      $seq_atdelta1009 = readrel1027->getIndex(ord1026, true);
      std::vector<u16> ord1028({1, 0, 2});
      slog::Relation* readrel1029 = db->getRelation("$seq_at");
      $seq_atindex1004 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 0, 2});
      slog::Relation* readrel1031 = db->getRelation("$seq_at");
      $seq_atdelta1010 = readrel1031->getIndex(ord1030, true);
      std::vector<u16> ord1032({1, 0, 2});
      slog::Relation* readrel1033 = db->getRelation("$seq_atr");
      $seq_atrindex1005 = readrel1033->getIndex(ord1032, false);
      std::vector<u16> ord1034({1, 0, 2});
      slog::Relation* readrel1035 = db->getRelation("$seq_atr");
      $seq_atrdelta1011 = readrel1035->getIndex(ord1034, true);
      std::vector<u16> ord1036({1, 0, 2});
      slog::Relation* readrel1037 = db->getRelation("$seq_atr");
      $seq_atrindex1006 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({1, 0, 2});
      slog::Relation* readrel1039 = db->getRelation("$seq_atr");
      $seq_atrdelta1012 = readrel1039->getIndex(ord1038, true);
      std::vector<u16> ord1040({1, 2, 0});
      slog::Relation* readrel1041 = db->getRelation("delta");
      deltaindex1007 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({1, 0});
      slog::Relation* readrel1043 = db->getRelation("_enum");
      _enumindex1008 = readrel1043->getIndex(ord1042, false);
  
    }
    ReadTask1013(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c1 = v_const06abaa100ecef791ce028c56;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        u64 v_c13 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex998, std::array<u64,3>{v_c6, v_c9, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex999, std::array<u64,3>{v_c7, v_c9, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex1000, std::array<u64,3>{v_c8, v_c9, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex1001, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex1002, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex1003, $seq_atdelta1009, std::array<u64,3>{v_c5, v_c9, 0}, [&](const std::array<u64,3>& m1044) {
          u64 v_c10 = m1044[2];
          slog::join_probe_old<3,3>($seq_atindex1004, $seq_atdelta1010, std::array<u64,3>{v_c6, v_c9, v_c10}, [&](const std::array<u64,3>& m1045) {
            slog::join_probe_old<3,3>($seq_atrindex1005, $seq_atrdelta1011, std::array<u64,3>{v_c7, v_c9, v_c10}, [&](const std::array<u64,3>& m1046) {
              slog::join_probe_old<3,3>($seq_atrindex1006, $seq_atrdelta1012, std::array<u64,3>{v_c8, v_c9, v_c10}, [&](const std::array<u64,3>& m1047) {
                slog::join_probe<3,2>(deltaindex1007, std::array<u64,3>{v_c1, v_c10, 0}, [&](const std::array<u64,3>& m1048) {
                  u64 v_c11 = m1048[2];
                  slog::join_probe<2,1>(_enumindex1008, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m1049) {
                    u64 v_c12 = m1049[1];
                    bool ok1050 = true;
                    u64 v_c14 = _prim_aslst(db, v_c10, &ok1050);
                    if (!ok1050) return;
                    u64 v_c277 = _prim_llen(db, v_c14);
                    if (v_c277 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c2 != v_c277) return;
                    bool ok1051 = true;
                    u64 v_c278 = _prim_lref(db, v_c14, v_c3, &ok1051);
                    if (!ok1051) return;
                    if (v_c9 != v_c278) return;
                    bool ok1052 = true;
                    u64 v_c279 = _prim_lref(db, v_c14, v_c4, &ok1052);
                    if (!ok1052) return;
                    if (v_c9 != v_c279) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c11});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
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
  // (crule (pre) (scan freevar x ef) (body (join-old app (1 2 0) 1 (1 2 0) ef es __t1aJ4143)) (head (emit freevar (0 1) x __t1aJ4143)) freevars.slog:13 #f)
  class ReadTask1055 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1053;  slog::Index** appdelta1054;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1056({0, 1});
      slog::Relation* readrel1057 = db->getRelation("freevar");
      head_index[0] = readrel1057->getIndex(ord1056, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1058({1, 2, 0});
      slog::Relation* readrel1059 = db->getRelation("app");
      appindex1053 = readrel1059->getIndex(ord1058, false);
      std::vector<u16> ord1060({1, 2, 0});
      slog::Relation* readrel1061 = db->getRelation("app");
      appdelta1054 = readrel1061->getIndex(ord1060, true);
  
    }
    ReadTask1055(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c29 = _t[1];
        slog::join_probe_old<3,1>(appindex1053, appdelta1054, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m1062) {
          u64 v_c30 = m1062[1]; u64 v_c280 = m1062[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c82, v_c280}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1055* _cont = new ReadTask1055(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1055(db,b), false);
  // (crule (pre (let __tconst65GN810 const0122baa3ac55f1b433944eb1) (let __tconst3VNs307 const06abaa100ecef791ce028c56) (let _00024sqc89jA519 constd4735e3a265e16eee03f5971) (let _00024sqc5bE7520 const5feceb66ffc86f38d952786c) (let _00024sqc5WD6521 const6b86b273ff34fce19d6b804e) (let _00024sqo7nH0522 const5feceb66ffc86f38d952786c) (let _00024sqo8HCy523 const6b86b273ff34fce19d6b804e) (let _00024sqo1Uwu524 const6b86b273ff34fce19d6b804e) (let _00024sqo9OPL525 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo7nH0522 __t5ERV310 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8HCy523 __t5ERV310 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Uwu524 __t5ERV310 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9OPL525 __t5ERV310 _00024seq2) (exists _enum (1 0) 1 __tconst65GN810) (join delta (1 2 0) 2 __tconst3VNs307 _00024seq2 __t5HIm308) (join _enum (1 0) 1 __tconst65GN810 __t26fz305) (join symval (0 1) 1 __t5ERV310 s) (letp _00024sql2wmw517 (aslst _00024seq2)) (let chk0WvJ1152 (llen _00024sql2wmw517)) (eq _00024sqc89jA519 chk0WvJ1152) (letp chk06SE1153 (lref _00024sql2wmw517 _00024sqc5bE7520)) (eq __t5ERV310 chk06SE1153) (letp chk5AQH1154 (lref _00024sql2wmw517 _00024sqc5WD6521)) (eq __t5ERV310 chk5AQH1154)) (head (emit-temp temp0P9u1146 __t5HIm308) (mkstruct boolval (1 0) __t7uE5306 __t26fz305)) interp.slog:117 #f)
  class ReadTask1073 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1063;  slog::Index** $seq_atrindex1064;  slog::Index** $seq_atrindex1065;  slog::Index** _enumindex1066;  slog::Index** deltaindex1067;  slog::Index** _enumindex1068;  slog::Index** symvalindex1069;  slog::Index** $seq_atdelta1070;  slog::Index** $seq_atrdelta1071;  slog::Index** $seq_atrdelta1072;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0P9u1146");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1074({1, 0, 2});
      slog::Relation* readrel1075 = db->getRelation("$seq_at");
      driver_index = readrel1075->getIndex(ord1074, true);
      std::vector<u16> ord1076({1, 0, 2});
      slog::Relation* readrel1077 = db->getRelation("$seq_at");
      $seq_atindex1063 = readrel1077->getIndex(ord1076, false);
      std::vector<u16> ord1078({1, 0, 2});
      slog::Relation* readrel1079 = db->getRelation("$seq_at");
      $seq_atdelta1070 = readrel1079->getIndex(ord1078, true);
      std::vector<u16> ord1080({1, 0, 2});
      slog::Relation* readrel1081 = db->getRelation("$seq_atr");
      $seq_atrindex1064 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({1, 0, 2});
      slog::Relation* readrel1083 = db->getRelation("$seq_atr");
      $seq_atrdelta1071 = readrel1083->getIndex(ord1082, true);
      std::vector<u16> ord1084({1, 0, 2});
      slog::Relation* readrel1085 = db->getRelation("$seq_atr");
      $seq_atrindex1065 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({1, 0, 2});
      slog::Relation* readrel1087 = db->getRelation("$seq_atr");
      $seq_atrdelta1072 = readrel1087->getIndex(ord1086, true);
      std::vector<u16> ord1088({1, 0});
      slog::Relation* readrel1089 = db->getRelation("_enum");
      _enumindex1066 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({1, 2, 0});
      slog::Relation* readrel1091 = db->getRelation("delta");
      deltaindex1067 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({1, 0});
      slog::Relation* readrel1093 = db->getRelation("_enum");
      _enumindex1068 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({0, 1});
      slog::Relation* readrel1095 = db->getRelation("symval");
      symvalindex1069 = readrel1095->getIndex(ord1094, false);
  
    }
    ReadTask1073(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c1 = v_const06abaa100ecef791ce028c56;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c5, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1096) {
        u64 v_c9 = m1096[1];
        u64 v_c10 = m1096[2];
        if (buckethash(v_c9) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex1063, $seq_atdelta1070, std::array<u64,3>{v_c6, v_c9, v_c10}, [&](const std::array<u64,3>& m1097) {
          slog::join_probe_old<3,3>($seq_atrindex1064, $seq_atrdelta1071, std::array<u64,3>{v_c7, v_c9, v_c10}, [&](const std::array<u64,3>& m1098) {
            slog::join_probe_old<3,3>($seq_atrindex1065, $seq_atrdelta1072, std::array<u64,3>{v_c8, v_c9, v_c10}, [&](const std::array<u64,3>& m1099) {
              if (!slog::exists_probe<2,1>(_enumindex1066, std::array<u64,2>{v_c0, 0})) return;
              slog::join_probe<3,2>(deltaindex1067, std::array<u64,3>{v_c1, v_c10, 0}, [&](const std::array<u64,3>& m1100) {
                u64 v_c11 = m1100[2];
                slog::join_probe<2,1>(_enumindex1068, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m1101) {
                  u64 v_c12 = m1101[1];
                  slog::join_probe<2,1>(symvalindex1069, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m1102) {
                    u64 v_c13 = m1102[1];
                    bool ok1103 = true;
                    u64 v_c14 = _prim_aslst(db, v_c10, &ok1103);
                    if (!ok1103) return;
                    u64 v_c281 = _prim_llen(db, v_c14);
                    if (v_c281 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                    if (v_c2 != v_c281) return;
                    bool ok1104 = true;
                    u64 v_c282 = _prim_lref(db, v_c14, v_c3, &ok1104);
                    if (!ok1104) return;
                    if (v_c9 != v_c282) return;
                    bool ok1105 = true;
                    u64 v_c283 = _prim_lref(db, v_c14, v_c4, &ok1105);
                    if (!ok1105) return;
                    if (v_c9 != v_c283) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c11});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1073* _cont = new ReadTask1073(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1073(db,b), false);
  // (crule (pre (let __tconst03NO760 constb9e118781cea1f9fa01462e0) (let __tconst3fuu217 const06abaa100ecef791ce028c56) (let _00024sqc1fPN569 constd4735e3a265e16eee03f5971) (let _00024sqc78q5570 const5feceb66ffc86f38d952786c) (let _00024sqc5TDx571 const6b86b273ff34fce19d6b804e) (let _00024sqo1Czp572 const5feceb66ffc86f38d952786c) (let _00024sqo2Uyj573 const6b86b273ff34fce19d6b804e) (let _00024sqo2qsW574 const6b86b273ff34fce19d6b804e) (let _00024sqo2mjM575 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo2qsW574 v1 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo1Czp572 v1 _00024seq0) (letp _00024sql8W3E567 (aslst _00024seq0)) (letp v2 (lref _00024sql8W3E567 _00024sqc5TDx571)) (neq v1 v2) (join $seq_at (1 0 2) 3 _00024sqo2Uyj573 v2 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo2mjM575 v2 _00024seq0) (exists _enum (1 0) 1 __tconst03NO760) (join delta (1 2 0) 2 __tconst3fuu217 _00024seq0 __t12h7218) (join _enum (1 0) 1 __tconst03NO760 __t6tMS215) (let chk4M281097 (llen _00024sql8W3E567)) (eq _00024sqc1fPN569 chk4M281097) (letp chk7MQ31098 (lref _00024sql8W3E567 _00024sqc78q5570)) (eq v1 chk7MQ31098)) (head (emit-temp temp4VE71091 __t12h7218) (mkstruct boolval (1 0) __t5boA216 __t6tMS215)) interp.slog:120 #f)
  class ReadTask1113 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1106;  slog::Index** $seq_atindex1107;  slog::Index** $seq_atrindex1108;  slog::Index** _enumindex1109;  slog::Index** deltaindex1110;  slog::Index** _enumindex1111;  slog::Index** $seq_atrdelta1112;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4VE71091");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1114({1, 0, 2});
      slog::Relation* readrel1115 = db->getRelation("$seq_atr");
      driver_index = readrel1115->getIndex(ord1114, true);
      std::vector<u16> ord1116({1, 0, 2});
      slog::Relation* readrel1117 = db->getRelation("$seq_at");
      $seq_atindex1106 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({1, 0, 2});
      slog::Relation* readrel1119 = db->getRelation("$seq_at");
      $seq_atindex1107 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({1, 0, 2});
      slog::Relation* readrel1121 = db->getRelation("$seq_atr");
      $seq_atrindex1108 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({1, 0, 2});
      slog::Relation* readrel1123 = db->getRelation("$seq_atr");
      $seq_atrdelta1112 = readrel1123->getIndex(ord1122, true);
      std::vector<u16> ord1124({1, 0});
      slog::Relation* readrel1125 = db->getRelation("_enum");
      _enumindex1109 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({1, 2, 0});
      slog::Relation* readrel1127 = db->getRelation("delta");
      deltaindex1110 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({1, 0});
      slog::Relation* readrel1129 = db->getRelation("_enum");
      _enumindex1111 = readrel1129->getIndex(ord1128, false);
  
    }
    ReadTask1113(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c209 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c210 = v_const06abaa100ecef791ce028c56;
      u64 v_c211 = v_constd4735e3a265e16eee03f5971;
      u64 v_c212 = v_const5feceb66ffc86f38d952786c;
      u64 v_c213 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c214 = v_const5feceb66ffc86f38d952786c;
      u64 v_c215 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c216 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c217 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c216, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1130) {
        u64 v_c220 = m1130[1];
        u64 v_c170 = m1130[2];
        if (buckethash(v_c220) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1106, std::array<u64,3>{v_c214, v_c220, v_c170}, [&](const std::array<u64,3>& m1131) {
          bool ok1132 = true;
          u64 v_c219 = _prim_aslst(db, v_c170, &ok1132);
          if (!ok1132) return;
          bool ok1133 = true;
          u64 v_c218 = _prim_lref(db, v_c219, v_c213, &ok1133);
          if (!ok1133) return;
          if (v_c220 == v_c218) return;
          slog::join_probe<3,3>($seq_atindex1107, std::array<u64,3>{v_c215, v_c218, v_c170}, [&](const std::array<u64,3>& m1134) {
            slog::join_probe_old<3,3>($seq_atrindex1108, $seq_atrdelta1112, std::array<u64,3>{v_c217, v_c218, v_c170}, [&](const std::array<u64,3>& m1135) {
              if (!slog::exists_probe<2,1>(_enumindex1109, std::array<u64,2>{v_c209, 0})) return;
              slog::join_probe<3,2>(deltaindex1110, std::array<u64,3>{v_c210, v_c170, 0}, [&](const std::array<u64,3>& m1136) {
                u64 v_c221 = m1136[2];
                slog::join_probe<2,1>(_enumindex1111, std::array<u64,2>{v_c209, 0}, [&](const std::array<u64,2>& m1137) {
                  u64 v_c222 = m1137[1];
                  u64 v_c284 = _prim_llen(db, v_c219);
                  if (v_c284 == slog_error) { slog::emit_pending_error(db, "interp.slog:120"); return; }
                  if (v_c211 != v_c284) return;
                  bool ok1138 = true;
                  u64 v_c285 = _prim_lref(db, v_c219, v_c212, &ok1138);
                  if (!ok1138) return;
                  if (v_c220 != v_c285) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c221});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c222}, std::array<u16,2>{1, 0});
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
        ReadTask1113* _cont = new ReadTask1113(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1113(db,b), false);
  // (crule (pre) (scan app __t2ZD3144 ef es) (body (join freevar_in_args (1 0) 1 es x)) (head (emit freevar (0 1) x __t2ZD3144)) freevars.slog:13 #f)
  class ReadTask1140 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevar_in_argsindex1139;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1141({0, 1});
      slog::Relation* readrel1142 = db->getRelation("freevar");
      head_index[0] = readrel1142->getIndex(ord1141, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1143({1, 0});
      slog::Relation* readrel1144 = db->getRelation("freevar_in_args");
      freevar_in_argsindex1139 = readrel1144->getIndex(ord1143, false);
  
    }
    ReadTask1140(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c286 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c30 = _t[2];
        slog::join_probe<2,1>(freevar_in_argsindex1139, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m1145) {
          u64 v_c82 = m1145[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c82, v_c286}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:app", _fires);
  
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
  // (crule (pre) (scan eval_ans __t32yp296 v) (body (join-old eval (0 2 1) 1 (0 2 1) __t32yp296 c eb) (exists letrec (3 0 1 2) 1 eb) (exists eval (2 0 1) 1 c) (join-old $sup56712x93x0x0x0 (1 2 0 3 4) 2 (1 2 0 3 4) c eb __t5OlD294 er x) (exists eval (0 2 1) 2 __t5OlD294 c) (exists eval (1 2 0) 2 er c) (join-old letrec (2 1 3 0) 3 (2 1 3 0) er x eb __t0H7q293) (join-old eval (0 2 1) 3 (0 2 1) __t5OlD294 c __t0H7q293) (join-old eval (1 2 0) 2 (1 2 0) er c __t9p2a295) (join eval_ans (0 1) 1 __t9p2a295 vr)) (head (emit eval_ans (0 1) __t5OlD294 v)) interp.slog:94 #f)
  class ReadTask1161 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1146;  slog::Index** letrecindex1147;  slog::Index** evalindex1148;  slog::Index** $sup56712x93x0x0x0index1149;  slog::Index** evalindex1150;  slog::Index** evalindex1151;  slog::Index** letrecindex1152;  slog::Index** evalindex1153;  slog::Index** evalindex1154;  slog::Index** eval_ansindex1155;  slog::Index** evaldelta1156;  slog::Index** $sup56712x93x0x0x0delta1157;  slog::Index** letrecdelta1158;  slog::Index** evaldelta1159;  slog::Index** evaldelta1160;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1162({0, 1});
      slog::Relation* readrel1163 = db->getRelation("eval_ans");
      head_index[0] = readrel1163->getIndex(ord1162, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1164({0, 2, 1});
      slog::Relation* readrel1165 = db->getRelation("eval");
      evalindex1146 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({0, 2, 1});
      slog::Relation* readrel1167 = db->getRelation("eval");
      evaldelta1156 = readrel1167->getIndex(ord1166, true);
      std::vector<u16> ord1168({3, 0, 1, 2});
      slog::Relation* readrel1169 = db->getRelation("letrec");
      letrecindex1147 = readrel1169->getIndex(ord1168, false);
      std::vector<u16> ord1170({2, 0, 1});
      slog::Relation* readrel1171 = db->getRelation("eval");
      evalindex1148 = readrel1171->getIndex(ord1170, false);
      std::vector<u16> ord1172({1, 2, 0, 3, 4});
      slog::Relation* readrel1173 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0index1149 = readrel1173->getIndex(ord1172, false);
      std::vector<u16> ord1174({1, 2, 0, 3, 4});
      slog::Relation* readrel1175 = db->getRelation("$sup56712x93x0x0x0");
      $sup56712x93x0x0x0delta1157 = readrel1175->getIndex(ord1174, true);
      std::vector<u16> ord1176({0, 2, 1});
      slog::Relation* readrel1177 = db->getRelation("eval");
      evalindex1150 = readrel1177->getIndex(ord1176, false);
      std::vector<u16> ord1178({1, 2, 0});
      slog::Relation* readrel1179 = db->getRelation("eval");
      evalindex1151 = readrel1179->getIndex(ord1178, false);
      std::vector<u16> ord1180({2, 1, 3, 0});
      slog::Relation* readrel1181 = db->getRelation("letrec");
      letrecindex1152 = readrel1181->getIndex(ord1180, false);
      std::vector<u16> ord1182({2, 1, 3, 0});
      slog::Relation* readrel1183 = db->getRelation("letrec");
      letrecdelta1158 = readrel1183->getIndex(ord1182, true);
      std::vector<u16> ord1184({0, 2, 1});
      slog::Relation* readrel1185 = db->getRelation("eval");
      evalindex1153 = readrel1185->getIndex(ord1184, false);
      std::vector<u16> ord1186({0, 2, 1});
      slog::Relation* readrel1187 = db->getRelation("eval");
      evaldelta1159 = readrel1187->getIndex(ord1186, true);
      std::vector<u16> ord1188({1, 2, 0});
      slog::Relation* readrel1189 = db->getRelation("eval");
      evalindex1154 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({1, 2, 0});
      slog::Relation* readrel1191 = db->getRelation("eval");
      evaldelta1160 = readrel1191->getIndex(ord1190, true);
      std::vector<u16> ord1192({0, 1});
      slog::Relation* readrel1193 = db->getRelation("eval_ans");
      eval_ansindex1155 = readrel1193->getIndex(ord1192, false);
  
    }
    ReadTask1161(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c287 = _t[0];
        u64 v_c263 = _t[1];
        slog::join_probe_old<3,1>(evalindex1146, evaldelta1156, std::array<u64,3>{v_c287, 0, 0}, [&](const std::array<u64,3>& m1194) {
          u64 v_c19 = m1194[1]; u64 v_c53 = m1194[2];
          if (!slog::exists_probe<4,1>(letrecindex1147, std::array<u64,4>{v_c53, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex1148, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe_old<5,2>($sup56712x93x0x0x0index1149, $sup56712x93x0x0x0delta1157, std::array<u64,5>{v_c19, v_c53, 0, 0, 0}, [&](const std::array<u64,5>& m1195) {
            u64 v_c288 = m1195[2]; u64 v_c289 = m1195[3]; u64 v_c82 = m1195[4];
            if (!slog::exists_probe<3,2>(evalindex1150, std::array<u64,3>{v_c288, v_c19, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex1151, std::array<u64,3>{v_c289, v_c19, 0})) return;
            slog::join_probe_old<4,3>(letrecindex1152, letrecdelta1158, std::array<u64,4>{v_c289, v_c82, v_c53, 0}, [&](const std::array<u64,4>& m1196) {
              u64 v_c290 = m1196[3];
              slog::join_probe_old<3,3>(evalindex1153, evaldelta1159, std::array<u64,3>{v_c288, v_c19, v_c290}, [&](const std::array<u64,3>& m1197) {
                slog::join_probe_old<3,2>(evalindex1154, evaldelta1160, std::array<u64,3>{v_c289, v_c19, 0}, [&](const std::array<u64,3>& m1198) {
                  u64 v_c291 = m1198[2];
                  slog::join_probe<2,1>(eval_ansindex1155, std::array<u64,2>{v_c291, 0}, [&](const std::array<u64,2>& m1199) {
                    u64 v_c292 = m1199[1];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c288, v_c263}, std::array<u16,2>{0, 1});
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
        ReadTask1161* _cont = new ReadTask1161(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1161(db,b), false);
  // (crule (pre (let __tconst3bSs155 const06abaa100ecef791ce028c56) (let _00024sqc3YlI510 constd4735e3a265e16eee03f5971) (let _00024sqc65nX511 const5feceb66ffc86f38d952786c) (let _00024sqc75b9512 const6b86b273ff34fce19d6b804e) (let _00024sqo3TKl513 const5feceb66ffc86f38d952786c) (let _00024sqo2IHZ514 const6b86b273ff34fce19d6b804e) (let _00024sqo1Kdp515 const6b86b273ff34fce19d6b804e) (let _00024sqo0AcC516 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo2IHZ514 __t59ft158 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo3TKl513 __t59ft158 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1Kdp515 __t59ft158 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0AcC516 __t59ft158 _00024seq2) (join delta (1 2 0) 2 __tconst3bSs155 _00024seq2 __t2lyA156) (join closure (0 1 2) 1 __t59ft158 lm cb) (join any_bool (0) 0 b) (letp _00024sql2qfO508 (aslst _00024seq2)) (let chk9Zbp1137 (llen _00024sql2qfO508)) (eq _00024sqc3YlI510 chk9Zbp1137) (letp chk0FAn1138 (lref _00024sql2qfO508 _00024sqc65nX511)) (eq __t59ft158 chk0FAn1138) (letp chk6Yim1139 (lref _00024sql2qfO508 _00024sqc75b9512)) (eq __t59ft158 chk6Yim1139)) (head (emit-temp temp3KOr1128 __t2lyA156 b) (mkstruct boolval (1 0) __t5Aug154 b)) interp.slog:122 #f)
  class ReadTask1208 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1200;  slog::Index** $seq_atrindex1201;  slog::Index** $seq_atrindex1202;  slog::Index** deltaindex1203;  slog::Index** closureindex1204;  slog::Index** any_boolindex1205;  slog::Index** $seq_atrdelta1206;  slog::Index** $seq_atrdelta1207;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3KOr1128");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1209({1, 0, 2});
      slog::Relation* readrel1210 = db->getRelation("$seq_at");
      driver_index = readrel1210->getIndex(ord1209, true);
      std::vector<u16> ord1211({1, 0, 2});
      slog::Relation* readrel1212 = db->getRelation("$seq_at");
      $seq_atindex1200 = readrel1212->getIndex(ord1211, false);
      std::vector<u16> ord1213({1, 0, 2});
      slog::Relation* readrel1214 = db->getRelation("$seq_atr");
      $seq_atrindex1201 = readrel1214->getIndex(ord1213, false);
      std::vector<u16> ord1215({1, 0, 2});
      slog::Relation* readrel1216 = db->getRelation("$seq_atr");
      $seq_atrdelta1206 = readrel1216->getIndex(ord1215, true);
      std::vector<u16> ord1217({1, 0, 2});
      slog::Relation* readrel1218 = db->getRelation("$seq_atr");
      $seq_atrindex1202 = readrel1218->getIndex(ord1217, false);
      std::vector<u16> ord1219({1, 0, 2});
      slog::Relation* readrel1220 = db->getRelation("$seq_atr");
      $seq_atrdelta1207 = readrel1220->getIndex(ord1219, true);
      std::vector<u16> ord1221({1, 2, 0});
      slog::Relation* readrel1222 = db->getRelation("delta");
      deltaindex1203 = readrel1222->getIndex(ord1221, false);
      std::vector<u16> ord1223({0, 1, 2});
      slog::Relation* readrel1224 = db->getRelation("closure");
      closureindex1204 = readrel1224->getIndex(ord1223, false);
      std::vector<u16> ord1225({0});
      slog::Relation* readrel1226 = db->getRelation("any_bool");
      any_boolindex1205 = readrel1226->getIndex(ord1225, false);
  
    }
    ReadTask1208(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c237 = v_const06abaa100ecef791ce028c56;
      u64 v_c238 = v_constd4735e3a265e16eee03f5971;
      u64 v_c239 = v_const5feceb66ffc86f38d952786c;
      u64 v_c240 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c241 = v_const5feceb66ffc86f38d952786c;
      u64 v_c242 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c243 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c244 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c242, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1227) {
        u64 v_c245 = m1227[1];
        u64 v_c10 = m1227[2];
        if (buckethash(v_c245) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1200, std::array<u64,3>{v_c241, v_c245, v_c10}, [&](const std::array<u64,3>& m1228) {
          slog::join_probe_old<3,3>($seq_atrindex1201, $seq_atrdelta1206, std::array<u64,3>{v_c243, v_c245, v_c10}, [&](const std::array<u64,3>& m1229) {
            slog::join_probe_old<3,3>($seq_atrindex1202, $seq_atrdelta1207, std::array<u64,3>{v_c244, v_c245, v_c10}, [&](const std::array<u64,3>& m1230) {
              slog::join_probe<3,2>(deltaindex1203, std::array<u64,3>{v_c237, v_c10, 0}, [&](const std::array<u64,3>& m1231) {
                u64 v_c246 = m1231[2];
                slog::join_probe<3,1>(closureindex1204, std::array<u64,3>{v_c245, 0, 0}, [&](const std::array<u64,3>& m1232) {
                  u64 v_c247 = m1232[1]; u64 v_c49 = m1232[2];
                  slog::join_all<1>(any_boolindex1205, [&](const std::array<u64,1>& m1233) {
                    u64 v_c71 = m1233[0];
                    bool ok1234 = true;
                    u64 v_c248 = _prim_aslst(db, v_c10, &ok1234);
                    if (!ok1234) return;
                    u64 v_c293 = _prim_llen(db, v_c248);
                    if (v_c293 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c238 != v_c293) return;
                    bool ok1235 = true;
                    u64 v_c294 = _prim_lref(db, v_c248, v_c239, &ok1235);
                    if (!ok1235) return;
                    if (v_c245 != v_c294) return;
                    bool ok1236 = true;
                    u64 v_c295 = _prim_lref(db, v_c248, v_c240, &ok1236);
                    if (!ok1236) return;
                    if (v_c245 != v_c295) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c246, v_c71});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c71}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1208* _cont = new ReadTask1208(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1208(db,b), false);
  // (crule (pre (let _00024seq0 (lempty))) (scan program e) (body) (head (mkstruct eval (1 2 0) __6O0d788 e _00024seq0)) interp.slog:130 #f)
  class ReadTask1237 : public slog::Task
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
    ReadTask1237(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = _prim_lempty(db);
      if (v_c170 == slog_error) { slog::emit_pending_error(db, "interp.slog:130"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c81 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c81, v_c170}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:130", "delta:program", _fires);
  
      if (!_done)
      {
        ReadTask1237* _cont = new ReadTask1237(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1237(db,b), false);
}

