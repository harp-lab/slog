
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const075bb5fb917b6c9c7bfeecc3;
extern u64 v_const3a655602588fe6d8c59d4a5a;
extern u64 v_const3b5b774db59f55c2fdaef73a;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const52b5e20f559958f34e533431;
extern u64 v_const5f7e60cb3d02e4170101c2bc;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const65c80aac3433a01ef8a7f298;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const72bac24066bb34077c1f6e71;
extern u64 v_const7f254967624b26d820569bd6;
extern u64 v_const846f120b6b6ab883fe02a53a;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd59eced1ded07f84c145592f;
extern u64 v_conste29c9c180c6279b0b02abd6a;
extern u64 v_conste7f6c011776e8db7cd330b54;
extern u64 v_consteb1e33e8a81b697b75855af6;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_cf63e360e728b7198(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst2JmK55 conste7f6c011776e8db7cd330b54) (let __tconst7dEi64 constef2d127de37b942baad06145) (let __tconst6c7T73 const4b227777d4dd1fc61c6f884f) (let __tconst56qw82 const4e07408562bedb8b60ce05c1) (let __tconst5MNq94 const5feceb66ffc86f38d952786c)) (scan temp0Ab21985 __t39ek93 __t3YaY47 __t66zQ63 __t8z2o72 __t9CBr54 __t9rwO81) (body (join let (1 2 3 0) 3 __tconst2JmK55 __t9CBr54 __t3YaY47 __t6Peh56)) (head (emit-temp temp9OrB1986 __t39ek93 __t66zQ63 __t6Peh56 __t8z2o72 __t9rwO81) (mkstruct let (1 2 3 0) __t953c65 __tconst7dEi64 __t66zQ63 __t6Peh56)) kcfa.slog:16 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9OrB1986");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp0Ab21985");
      std::vector<u16> ord2({1, 2, 3, 0});
      slog::Relation* readrel3 = db->getRelation("let");
      letindex0 = readrel3->getIndex(ord2, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c1 = v_constef2d127de37b942baad06145;
      u64 v_c2 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c3 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        u64 v_c9 = _t[4];
        u64 v_c10 = _t[5];
        slog::join_probe<4,3>(letindex0, std::array<u64,4>{v_c0, v_c9, v_c6, 0}, [&](const std::array<u64,4>& m4) {
          u64 v_c11 = m4[3];
          ++_fires;
          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c5, v_c7, v_c11, v_c8, v_c10});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c1, v_c7, v_c11}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:16", "delta:temp0Ab21985", _fires);
  
      if (!_done)
      {
        ReadTask1* _cont = new ReadTask1(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1(db,b), false);
  // (crule (pre) (scan mbranch __t8p1x448 p m l r) (body (exists mbranch (2 0 1 3 4) 1 m) (join mp_union (1 2 0) 1 __t8p1x448 __t8IRS449 __t7CA0447) (join-old mbranch (2 0 1 3 4) 2 (2 0 1 3 4) m __t8IRS449 q u v) (neq p q)) (head (mkstruct mp_join (1 2 3 4 0) __86XP1466 p __t8p1x448 q __t8IRS449)) map.slog:114 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex5;  slog::Index** mp_unionindex6;  slog::Index** mbranchindex7;  slog::Index** mbranchdelta8;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord10({2, 0, 1, 3, 4});
      slog::Relation* readrel11 = db->getRelation("mbranch");
      mbranchindex5 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 2, 0});
      slog::Relation* readrel13 = db->getRelation("mp_union");
      mp_unionindex6 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({2, 0, 1, 3, 4});
      slog::Relation* readrel15 = db->getRelation("mbranch");
      mbranchindex7 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({2, 0, 1, 3, 4});
      slog::Relation* readrel17 = db->getRelation("mbranch");
      mbranchdelta8 = readrel17->getIndex(ord16, true);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c16 = _t[4];
        if (!slog::exists_probe<5,1>(mbranchindex5, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
        slog::join_probe<3,1>(mp_unionindex6, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m18) {
          u64 v_c17 = m18[1]; u64 v_c18 = m18[2];
          slog::join_probe_old<5,2>(mbranchindex7, mbranchdelta8, std::array<u64,5>{v_c14, v_c17, 0, 0, 0}, [&](const std::array<u64,5>& m19) {
            u64 v_c19 = m19[2]; u64 v_c20 = m19[3]; u64 v_c21 = m19[4];
            if (v_c13 == v_c19) return;
            ++_fires;
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c13, v_c12, v_c19, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mbranch", _fires);
  
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
  // (crule (pre (let __tconst7YVO1086 constb9e118781cea1f9fa01462e0) (let __tconst0qOo437 const60e3114d9b4b6577eea8cbc0) (let _00024sqc0uxV1007 const6b86b273ff34fce19d6b804e) (let _00024sqc0jY31008 const5feceb66ffc86f38d952786c) (let _00024sqo1OME1009 const5feceb66ffc86f38d952786c) (let _00024sqo3mx21010 const5feceb66ffc86f38d952786c)) (scan scheme_false fv) (body (exists $seq_at (1 0 2) 1 _00024sqo1OME1009) (exists $seq_atr (1 0 2) 1 _00024sqo3mx21010) (exists delta (1 2 0) 1 __tconst0qOo437) (join _enum (1 0) 1 __tconst7YVO1086 __t2dgW435) (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo1OME1009 v _00024seq0) (neq v fv) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3mx21010 v _00024seq0) (join-old delta (1 2 0) 2 (1 2 0) __tconst0qOo437 _00024seq0 __t4KDF438) (letp _00024sql5Lne1005 (aslst _00024seq0)) (let chk6qfg1816 (llen _00024sql5Lne1005)) (eq _00024sqc0uxV1007 chk6qfg1816) (letp chk2by61817 (lref _00024sql5Lne1005 _00024sqc0jY31008)) (eq v chk2by61817)) (head (emit-temp temp6YY41815 __t4KDF438) (mkstruct boolval (1 0) __t83Bj436 __t2dgW435)) interp.slog:119 #f)
  class ReadTask30 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex20;  slog::Index** $seq_atrindex21;  slog::Index** deltaindex22;  slog::Index** _enumindex23;  slog::Index** $seq_atindex24;  slog::Index** $seq_atrindex25;  slog::Index** deltaindex26;  slog::Index** $seq_atdelta27;  slog::Index** $seq_atrdelta28;  slog::Index** deltadelta29;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6YY41815");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("scheme_false");
      std::vector<u16> ord31({1, 0, 2});
      slog::Relation* readrel32 = db->getRelation("$seq_at");
      $seq_atindex20 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0, 2});
      slog::Relation* readrel34 = db->getRelation("$seq_atr");
      $seq_atrindex21 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 2, 0});
      slog::Relation* readrel36 = db->getRelation("delta");
      deltaindex22 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 0});
      slog::Relation* readrel38 = db->getRelation("_enum");
      _enumindex23 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 0, 2});
      slog::Relation* readrel40 = db->getRelation("$seq_at");
      $seq_atindex24 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 0, 2});
      slog::Relation* readrel42 = db->getRelation("$seq_at");
      $seq_atdelta27 = readrel42->getIndex(ord41, true);
      std::vector<u16> ord43({1, 0, 2});
      slog::Relation* readrel44 = db->getRelation("$seq_atr");
      $seq_atrindex25 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 0, 2});
      slog::Relation* readrel46 = db->getRelation("$seq_atr");
      $seq_atrdelta28 = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({1, 2, 0});
      slog::Relation* readrel48 = db->getRelation("delta");
      deltaindex26 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 2, 0});
      slog::Relation* readrel50 = db->getRelation("delta");
      deltadelta29 = readrel50->getIndex(ord49, true);
  
    }
    ReadTask30(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c23 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c24 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c25 = v_const5feceb66ffc86f38d952786c;
      u64 v_c26 = v_const5feceb66ffc86f38d952786c;
      u64 v_c27 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c28 = _t[0];
        if (!slog::exists_probe<3,1>($seq_atindex20, std::array<u64,3>{v_c26, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atrindex21, std::array<u64,3>{v_c27, 0, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex22, std::array<u64,3>{v_c23, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex23, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m51) {
          u64 v_c29 = m51[1];
          slog::join_probe_old<3,1>($seq_atindex24, $seq_atdelta27, std::array<u64,3>{v_c26, 0, 0}, [&](const std::array<u64,3>& m52) {
            u64 v_c21 = m52[1]; u64 v_c30 = m52[2];
            if (v_c21 == v_c28) return;
            slog::join_probe_old<3,3>($seq_atrindex25, $seq_atrdelta28, std::array<u64,3>{v_c27, v_c21, v_c30}, [&](const std::array<u64,3>& m53) {
              slog::join_probe_old<3,2>(deltaindex26, deltadelta29, std::array<u64,3>{v_c23, v_c30, 0}, [&](const std::array<u64,3>& m54) {
                u64 v_c31 = m54[2];
                bool ok55 = true;
                u64 v_c32 = _prim_aslst(db, v_c30, &ok55);
                if (!ok55) return;
                u64 v_c33 = _prim_llen(db, v_c32);
                if (v_c33 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                if (v_c24 != v_c33) return;
                bool ok56 = true;
                u64 v_c34 = _prim_lref(db, v_c32, v_c25, &ok56);
                if (!ok56) return;
                if (v_c21 != v_c34) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c31});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c29}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:scheme_false", _fires);
  
      if (!_done)
      {
        ReadTask30* _cont = new ReadTask30(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask30(db,b), false);
  // (crule (pre (let __tconst2rWb405 const5feceb66ffc86f38d952786c)) (scan mbranch __t1qjI403 p m l r) (body (join-old mp_has0 (1 2 0) 1 (1 2 0) __t1qjI403 k __t5Upj404) (let __t4jzF406 (band k m)) (cmp gt __t4jzF406 __tconst2rWb405)) (head (emit $sup5638x62x0x0x0 (4 2 3 5 0 1) p l m r __t5Upj404 k)) map.slog:63 #f)
  class ReadTask59 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index57;  slog::Index** mp_has0delta58;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord60({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel61 = db->getRelation("$sup5638x62x0x0x0");
      head_index[0] = readrel61->getIndex(ord60, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord62({1, 2, 0});
      slog::Relation* readrel63 = db->getRelation("mp_has0");
      mp_has0index57 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 2, 0});
      slog::Relation* readrel65 = db->getRelation("mp_has0");
      mp_has0delta58 = readrel65->getIndex(ord64, true);
  
    }
    ReadTask59(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c35 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c36 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c16 = _t[4];
        slog::join_probe_old<3,1>(mp_has0index57, mp_has0delta58, std::array<u64,3>{v_c36, 0, 0}, [&](const std::array<u64,3>& m66) {
          u64 v_c37 = m66[1]; u64 v_c38 = m66[2];
          u64 v_c39 = _prim_band(db, v_c37, v_c14);
          if (v_c39 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
          u64 v_c40 = _prim_gt(db, v_c39, v_c35);
          if (v_c40 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
          if (!v_c40) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c13, v_c15, v_c14, v_c16, v_c38, v_c37}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask59* _cont = new ReadTask59(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask59(db,b), false);
  // (crule (pre (let __tconst4JFo1084 constcd2a69ce5ca278db1d6da969) (let _00024sqc2XJk894 constd4735e3a265e16eee03f5971) (let _00024sqc3Vvh895 const5feceb66ffc86f38d952786c) (let _00024sqc1G23896 const6b86b273ff34fce19d6b804e) (let _00024sqo5Yvx897 const5feceb66ffc86f38d952786c) (let _00024sqo6jkp898 const6b86b273ff34fce19d6b804e) (let _00024sqo3xdn899 const6b86b273ff34fce19d6b804e) (let _00024sqo4MmQ900 const5feceb66ffc86f38d952786c)) (scan delta __t7695542 op _00024seq2) (body (letp _00024sql014l892 (aslst _00024seq2)) (letp __t6Yod544 (lref _00024sql014l892 _00024sqc3Vvh895)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5Yvx897 __t6Yod544 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo6jkp898 __t6Yod544 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3xdn899 __t6Yod544 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4MmQ900 __t6Yod544 _00024seq2) (join _enum (0 1) 2 __t6Yod544 __tconst4JFo1084) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (let chk62Nm1796 (llen _00024sql014l892)) (eq _00024sqc2XJk894 chk62Nm1796) (letp chk56C71797 (lref _00024sql014l892 _00024sqc1G23896)) (eq __t6Yod544 chk56C71797)) (head (emit-temp temp4Zu91795 __t7695542 b) (mkstruct boolval (1 0) __t4iE5541 b)) interp.slog:117 #f)
  class ReadTask79 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex68;  slog::Index** $seq_atindex69;  slog::Index** $seq_atrindex70;  slog::Index** $seq_atrindex71;  slog::Index** _enumindex72;  slog::Index** comparison_opindex73;  slog::Index** any_boolindex74;  slog::Index** $seq_atdelta75;  slog::Index** $seq_atdelta76;  slog::Index** $seq_atrdelta77;  slog::Index** $seq_atrdelta78;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4Zu91795");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("delta");
      std::vector<u16> ord80({1, 0, 2});
      slog::Relation* readrel81 = db->getRelation("$seq_at");
      $seq_atindex68 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 0, 2});
      slog::Relation* readrel83 = db->getRelation("$seq_at");
      $seq_atdelta75 = readrel83->getIndex(ord82, true);
      std::vector<u16> ord84({1, 0, 2});
      slog::Relation* readrel85 = db->getRelation("$seq_at");
      $seq_atindex69 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 0, 2});
      slog::Relation* readrel87 = db->getRelation("$seq_at");
      $seq_atdelta76 = readrel87->getIndex(ord86, true);
      std::vector<u16> ord88({1, 0, 2});
      slog::Relation* readrel89 = db->getRelation("$seq_atr");
      $seq_atrindex70 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 0, 2});
      slog::Relation* readrel91 = db->getRelation("$seq_atr");
      $seq_atrdelta77 = readrel91->getIndex(ord90, true);
      std::vector<u16> ord92({1, 0, 2});
      slog::Relation* readrel93 = db->getRelation("$seq_atr");
      $seq_atrindex71 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0, 2});
      slog::Relation* readrel95 = db->getRelation("$seq_atr");
      $seq_atrdelta78 = readrel95->getIndex(ord94, true);
      std::vector<u16> ord96({0, 1});
      slog::Relation* readrel97 = db->getRelation("_enum");
      _enumindex72 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({0});
      slog::Relation* readrel99 = db->getRelation("comparison_op");
      comparison_opindex73 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({0});
      slog::Relation* readrel101 = db->getRelation("any_bool");
      any_boolindex74 = readrel101->getIndex(ord100, false);
  
    }
    ReadTask79(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c42 = v_constd4735e3a265e16eee03f5971;
      u64 v_c43 = v_const5feceb66ffc86f38d952786c;
      u64 v_c44 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c45 = v_const5feceb66ffc86f38d952786c;
      u64 v_c46 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c47 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c48 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c49 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c51 = _t[2];
        bool ok102 = true;
        u64 v_c52 = _prim_aslst(db, v_c51, &ok102);
        if (!ok102) return;
        bool ok103 = true;
        u64 v_c53 = _prim_lref(db, v_c52, v_c43, &ok103);
        if (!ok103) return;
        slog::join_probe_old<3,3>($seq_atindex68, $seq_atdelta75, std::array<u64,3>{v_c45, v_c53, v_c51}, [&](const std::array<u64,3>& m104) {
          slog::join_probe_old<3,3>($seq_atindex69, $seq_atdelta76, std::array<u64,3>{v_c46, v_c53, v_c51}, [&](const std::array<u64,3>& m105) {
            slog::join_probe_old<3,3>($seq_atrindex70, $seq_atrdelta77, std::array<u64,3>{v_c47, v_c53, v_c51}, [&](const std::array<u64,3>& m106) {
              slog::join_probe_old<3,3>($seq_atrindex71, $seq_atrdelta78, std::array<u64,3>{v_c48, v_c53, v_c51}, [&](const std::array<u64,3>& m107) {
                slog::join_probe<2,2>(_enumindex72, std::array<u64,2>{v_c53, v_c41}, [&](const std::array<u64,2>& m108) {
                  slog::join_probe<1,1>(comparison_opindex73, std::array<u64,1>{v_c50}, [&](const std::array<u64,1>& m109) {
                    slog::join_all<1>(any_boolindex74, [&](const std::array<u64,1>& m110) {
                      u64 v_c54 = m110[0];
                      u64 v_c55 = _prim_llen(db, v_c52);
                      if (v_c55 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                      if (v_c42 != v_c55) return;
                      bool ok111 = true;
                      u64 v_c56 = _prim_lref(db, v_c52, v_c44, &ok111);
                      if (!ok111) return;
                      if (v_c53 != v_c56) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c49, v_c54});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c54}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:delta", _fires);
  
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
  // (crule (pre) (scan temp5lsY1878 __t7WtB688 k v) (body (join mleaf (1 2 0) 2 k v __t9pzZ686)) (head (emit mp_put_ans (0 1) __t7WtB688 __t9pzZ686)) map.slog:38 #f)
  class ReadTask113 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex112;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord114({0, 1});
      slog::Relation* readrel115 = db->getRelation("mp_put_ans");
      head_index[0] = readrel115->getIndex(ord114, false);
      outer_rel = db->getRelation("temp5lsY1878");
      std::vector<u16> ord116({1, 2, 0});
      slog::Relation* readrel117 = db->getRelation("mleaf");
      mleafindex112 = readrel117->getIndex(ord116, false);
  
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
        u64 v_c57 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c21 = _t[2];
        slog::join_probe<3,2>(mleafindex112, std::array<u64,3>{v_c37, v_c21, 0}, [&](const std::array<u64,3>& m118) {
          u64 v_c58 = m118[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c57, v_c58}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:38", "delta:temp5lsY1878", _fires);
  
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
  // (crule (pre) (scan mp_join_ans __t77mZ27 res) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t77mZ27 p __t7Hza25 q __t3dlR26) (neq p q) (exists mbranch (0 1 2 3 4) 2 __t7Hza25 p) (exists mbranch (0 1 2 3 4) 2 __t3dlR26 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t7Hza25 __t3dlR26 __t2vfE24) (join-old mbranch (0 1 2 3 4) 2 (0 1 2 3 4) __t7Hza25 p m l r) (join-old mbranch (0 1 2 3 4) 3 (0 1 2 3 4) __t3dlR26 q m u v)) (head (emit mp_union_ans (0 1) __t2vfE24 res)) map.slog:114 #f)
  class ReadTask129 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex119;  slog::Index** mbranchindex120;  slog::Index** mbranchindex121;  slog::Index** mp_unionindex122;  slog::Index** mbranchindex123;  slog::Index** mbranchindex124;  slog::Index** mp_joindelta125;  slog::Index** mp_uniondelta126;  slog::Index** mbranchdelta127;  slog::Index** mbranchdelta128;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord130({0, 1});
      slog::Relation* readrel131 = db->getRelation("mp_union_ans");
      head_index[0] = readrel131->getIndex(ord130, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord132({0, 1, 2, 3, 4});
      slog::Relation* readrel133 = db->getRelation("mp_join");
      mp_joinindex119 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({0, 1, 2, 3, 4});
      slog::Relation* readrel135 = db->getRelation("mp_join");
      mp_joindelta125 = readrel135->getIndex(ord134, true);
      std::vector<u16> ord136({0, 1, 2, 3, 4});
      slog::Relation* readrel137 = db->getRelation("mbranch");
      mbranchindex120 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({0, 1, 2, 3, 4});
      slog::Relation* readrel139 = db->getRelation("mbranch");
      mbranchindex121 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 0});
      slog::Relation* readrel141 = db->getRelation("mp_union");
      mp_unionindex122 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0});
      slog::Relation* readrel143 = db->getRelation("mp_union");
      mp_uniondelta126 = readrel143->getIndex(ord142, true);
      std::vector<u16> ord144({0, 1, 2, 3, 4});
      slog::Relation* readrel145 = db->getRelation("mbranch");
      mbranchindex123 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 1, 2, 3, 4});
      slog::Relation* readrel147 = db->getRelation("mbranch");
      mbranchdelta127 = readrel147->getIndex(ord146, true);
      std::vector<u16> ord148({0, 1, 2, 3, 4});
      slog::Relation* readrel149 = db->getRelation("mbranch");
      mbranchindex124 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 1, 2, 3, 4});
      slog::Relation* readrel151 = db->getRelation("mbranch");
      mbranchdelta128 = readrel151->getIndex(ord150, true);
  
    }
    ReadTask129(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c60 = _t[1];
        slog::join_probe_old<5,1>(mp_joinindex119, mp_joindelta125, std::array<u64,5>{v_c59, 0, 0, 0, 0}, [&](const std::array<u64,5>& m152) {
          u64 v_c13 = m152[1]; u64 v_c61 = m152[2]; u64 v_c19 = m152[3]; u64 v_c62 = m152[4];
          if (v_c13 == v_c19) return;
          if (!slog::exists_probe<5,2>(mbranchindex120, std::array<u64,5>{v_c61, v_c13, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex121, std::array<u64,5>{v_c62, v_c19, 0, 0, 0})) return;
          slog::join_probe_old<3,2>(mp_unionindex122, mp_uniondelta126, std::array<u64,3>{v_c61, v_c62, 0}, [&](const std::array<u64,3>& m153) {
            u64 v_c63 = m153[2];
            slog::join_probe_old<5,2>(mbranchindex123, mbranchdelta127, std::array<u64,5>{v_c61, v_c13, 0, 0, 0}, [&](const std::array<u64,5>& m154) {
              u64 v_c14 = m154[2]; u64 v_c15 = m154[3]; u64 v_c16 = m154[4];
              slog::join_probe_old<5,3>(mbranchindex124, mbranchdelta128, std::array<u64,5>{v_c62, v_c19, v_c14, 0, 0}, [&](const std::array<u64,5>& m155) {
                u64 v_c20 = m155[3]; u64 v_c21 = m155[4];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c63, v_c60}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mp_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask129* _cont = new ReadTask129(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask129(db,b), false);
  // (crule (pre (let __tconst8hOq309 const6b86b273ff34fce19d6b804e)) (scan mp_del __t1hIi313 l k) (body (exists $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_del (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join mp_del_ans (0 1) 1 __t1hIi313 __v0) (exists mp_bld (3 0 1 2 4) 1 __v0) (join $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 k l __t0iNt308 m p r) (exists mp_bld (1 2 3 4 0) 4 p m __v0 r) (exists mp_del (0 2 1) 2 __t0iNt308 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join mbranch (1 2 3 4 0) 4 p m l r __t62gM307) (exists mp_del (0 2 1) 3 __t0iNt308 k __t62gM307) (join mp_bld (1 2 3 4 0) 4 p m __v0 r __t8pI6311) (join mp_del (0 2 1) 3 __t0iNt308 k __t62gM307) (exists mp_bld_ans (0 1) 1 __t8pI6311) (join mp_msk (1 2 0) 2 k m __t8vNz312) (join mp_msk_ans (0 1) 2 __t8vNz312 p) (join mp_bld_ans (0 1) 1 __t8pI6311 res) (let __t3mg0310 (band k m)) (cmp lt __t3mg0310 __tconst8hOq309)) (head (emit mp_del_ans (0 1) __t0iNt308 res)) map.slog:83 #f)
  class ReadTask175 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index156;  slog::Index** mbranchindex157;  slog::Index** mp_delindex158;  slog::Index** mp_mskindex159;  slog::Index** mp_del_ansindex160;  slog::Index** mp_bldindex161;  slog::Index** $sup5638x82x0x0x0index162;  slog::Index** mp_bldindex163;  slog::Index** mp_delindex164;  slog::Index** mp_mskindex165;  slog::Index** mp_msk_ansindex166;  slog::Index** mbranchindex167;  slog::Index** mp_delindex168;  slog::Index** mp_bldindex169;  slog::Index** mp_delindex170;  slog::Index** mp_bld_ansindex171;  slog::Index** mp_mskindex172;  slog::Index** mp_msk_ansindex173;  slog::Index** mp_bld_ansindex174;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord176({0, 1});
      slog::Relation* readrel177 = db->getRelation("mp_del_ans");
      head_index[0] = readrel177->getIndex(ord176, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord178({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel179 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index156 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({3, 0, 1, 2, 4});
      slog::Relation* readrel181 = db->getRelation("mbranch");
      mbranchindex157 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({2, 0, 1});
      slog::Relation* readrel183 = db->getRelation("mp_del");
      mp_delindex158 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 2, 0});
      slog::Relation* readrel185 = db->getRelation("mp_msk");
      mp_mskindex159 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({0, 1});
      slog::Relation* readrel187 = db->getRelation("mp_del_ans");
      mp_del_ansindex160 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({3, 0, 1, 2, 4});
      slog::Relation* readrel189 = db->getRelation("mp_bld");
      mp_bldindex161 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel191 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index162 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({1, 2, 3, 4, 0});
      slog::Relation* readrel193 = db->getRelation("mp_bld");
      mp_bldindex163 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 2, 1});
      slog::Relation* readrel195 = db->getRelation("mp_del");
      mp_delindex164 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 0});
      slog::Relation* readrel197 = db->getRelation("mp_msk");
      mp_mskindex165 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({1, 0});
      slog::Relation* readrel199 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex166 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 2, 3, 4, 0});
      slog::Relation* readrel201 = db->getRelation("mbranch");
      mbranchindex167 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({0, 2, 1});
      slog::Relation* readrel203 = db->getRelation("mp_del");
      mp_delindex168 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 2, 3, 4, 0});
      slog::Relation* readrel205 = db->getRelation("mp_bld");
      mp_bldindex169 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({0, 2, 1});
      slog::Relation* readrel207 = db->getRelation("mp_del");
      mp_delindex170 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({0, 1});
      slog::Relation* readrel209 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex171 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 2, 0});
      slog::Relation* readrel211 = db->getRelation("mp_msk");
      mp_mskindex172 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({0, 1});
      slog::Relation* readrel213 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex173 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex174 = readrel215->getIndex(ord214, false);
  
    }
    ReadTask175(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c64 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c65 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c37 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x82x0x0x0index156, std::array<u64,6>{v_c37, v_c15, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex157, std::array<u64,5>{v_c15, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex158, std::array<u64,3>{v_c37, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex159, std::array<u64,3>{v_c37, 0, 0})) return;
        slog::join_probe<2,1>(mp_del_ansindex160, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m216) {
          u64 v_c66 = m216[1];
          if (!slog::exists_probe<5,1>(mp_bldindex161, std::array<u64,5>{v_c66, 0, 0, 0, 0})) return;
          slog::join_probe<6,2>($sup5638x82x0x0x0index162, std::array<u64,6>{v_c37, v_c15, 0, 0, 0, 0}, [&](const std::array<u64,6>& m217) {
            u64 v_c67 = m217[2]; u64 v_c14 = m217[3]; u64 v_c13 = m217[4]; u64 v_c16 = m217[5];
            if (!slog::exists_probe<5,4>(mp_bldindex163, std::array<u64,5>{v_c13, v_c14, v_c66, v_c16, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex164, std::array<u64,3>{v_c67, v_c37, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex165, std::array<u64,3>{v_c37, v_c14, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex166, std::array<u64,2>{v_c13, 0})) return;
            slog::join_probe<5,4>(mbranchindex167, std::array<u64,5>{v_c13, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,5>& m218) {
              u64 v_c68 = m218[4];
              if (!slog::exists_probe<3,3>(mp_delindex168, std::array<u64,3>{v_c67, v_c37, v_c68})) return;
              slog::join_probe<5,4>(mp_bldindex169, std::array<u64,5>{v_c13, v_c14, v_c66, v_c16, 0}, [&](const std::array<u64,5>& m219) {
                u64 v_c69 = m219[4];
                slog::join_probe<3,3>(mp_delindex170, std::array<u64,3>{v_c67, v_c37, v_c68}, [&](const std::array<u64,3>& m220) {
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex171, std::array<u64,2>{v_c69, 0})) return;
                  slog::join_probe<3,2>(mp_mskindex172, std::array<u64,3>{v_c37, v_c14, 0}, [&](const std::array<u64,3>& m221) {
                    u64 v_c70 = m221[2];
                    slog::join_probe<2,2>(mp_msk_ansindex173, std::array<u64,2>{v_c70, v_c13}, [&](const std::array<u64,2>& m222) {
                      slog::join_probe<2,1>(mp_bld_ansindex174, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m223) {
                        u64 v_c60 = m223[1];
                        u64 v_c71 = _prim_band(db, v_c37, v_c14);
                        if (v_c71 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c72 = _prim_lt(db, v_c71, v_c64);
                        if (v_c72 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c72) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c67, v_c60}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del", _fires);
  
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
  // (crule (pre (let __tconst8WcI1085 const0122baa3ac55f1b433944eb1)) (scan temp7W0m2012 __t0WVv596) (body (join _enum (1 0) 1 __tconst8WcI1085 __t8vy6593) (join boolval (1 0) 1 __t8vy6593 __t17ui594)) (head (emit delta_ans (0 1) __t0WVv596 __t17ui594)) interp.slog:121 #f)
  class ReadTask227 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex225;  slog::Index** boolvalindex226;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord228({0, 1});
      slog::Relation* readrel229 = db->getRelation("delta_ans");
      head_index[0] = readrel229->getIndex(ord228, false);
      outer_rel = db->getRelation("temp7W0m2012");
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("_enum");
      _enumindex225 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("boolval");
      boolvalindex226 = readrel233->getIndex(ord232, false);
  
    }
    ReadTask227(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c74 = _t[0];
        slog::join_probe<2,1>(_enumindex225, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m234) {
          u64 v_c75 = m234[1];
          slog::join_probe<2,1>(boolvalindex226, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m235) {
            u64 v_c76 = m235[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c74, v_c76}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:temp7W0m2012", _fires);
  
      if (!_done)
      {
        ReadTask227* _cont = new ReadTask227(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask227(db,b), false);
  // (crule (pre) (scan eval __t4Rxn650 __v1 rho t) (body (exists $sup70016x87x0x0x0 (4 5 0 1 2 3) 2 rho t) (exists eval (2 3 0 1) 2 rho t) (exists select_branch_ans (1 0) 1 __v1) (exists eval_ans (0 1) 1 __t4Rxn650) (join eval (2 3 0 1) 2 rho t __t7kdB647 __t71xd646) (join $sup70016x87x0x0x0 (4 5 0 1 2 3) 3 rho t __t7kdB647 e1 e2 e3) (join if (1 3 2 0) 4 e1 e3 e2 __t71xd646) (exists select_branch (2 3 1 0) 2 e2 e3) (join eval (1 2 3 0) 3 e1 rho t __t2MYH648) (exists eval_ans (0 1) 1 __t2MYH648) (join select_branch (2 3 1 0) 2 e2 e3 __v0 __t1Vli649) (join eval_ans (0 1) 2 __t2MYH648 __v0) (join select_branch_ans (0 1) 2 __t1Vli649 __v1) (join eval_ans (0 1) 1 __t4Rxn650 __v2)) (head (emit eval_ans (0 1) __t7kdB647 __v2)) interp.slog:88 #f)
  class ReadTask250 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x87x0x0x0index236;  slog::Index** evalindex237;  slog::Index** select_branch_ansindex238;  slog::Index** eval_ansindex239;  slog::Index** evalindex240;  slog::Index** $sup70016x87x0x0x0index241;  slog::Index** ifindex242;  slog::Index** select_branchindex243;  slog::Index** evalindex244;  slog::Index** eval_ansindex245;  slog::Index** select_branchindex246;  slog::Index** eval_ansindex247;  slog::Index** select_branch_ansindex248;  slog::Index** eval_ansindex249;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord251({0, 1});
      slog::Relation* readrel252 = db->getRelation("eval_ans");
      head_index[0] = readrel252->getIndex(ord251, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord253({4, 5, 0, 1, 2, 3});
      slog::Relation* readrel254 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index236 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({2, 3, 0, 1});
      slog::Relation* readrel256 = db->getRelation("eval");
      evalindex237 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 0});
      slog::Relation* readrel258 = db->getRelation("select_branch_ans");
      select_branch_ansindex238 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({0, 1});
      slog::Relation* readrel260 = db->getRelation("eval_ans");
      eval_ansindex239 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({2, 3, 0, 1});
      slog::Relation* readrel262 = db->getRelation("eval");
      evalindex240 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({4, 5, 0, 1, 2, 3});
      slog::Relation* readrel264 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index241 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({1, 3, 2, 0});
      slog::Relation* readrel266 = db->getRelation("if");
      ifindex242 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({2, 3, 1, 0});
      slog::Relation* readrel268 = db->getRelation("select_branch");
      select_branchindex243 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({1, 2, 3, 0});
      slog::Relation* readrel270 = db->getRelation("eval");
      evalindex244 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({0, 1});
      slog::Relation* readrel272 = db->getRelation("eval_ans");
      eval_ansindex245 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({2, 3, 1, 0});
      slog::Relation* readrel274 = db->getRelation("select_branch");
      select_branchindex246 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({0, 1});
      slog::Relation* readrel276 = db->getRelation("eval_ans");
      eval_ansindex247 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({0, 1});
      slog::Relation* readrel278 = db->getRelation("select_branch_ans");
      select_branch_ansindex248 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({0, 1});
      slog::Relation* readrel280 = db->getRelation("eval_ans");
      eval_ansindex249 = readrel280->getIndex(ord279, false);
  
    }
    ReadTask250(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c77 = _t[0];
        u64 v_c78 = _t[1];
        u64 v_c79 = _t[2];
        u64 v_c80 = _t[3];
        if (!slog::exists_probe<6,2>($sup70016x87x0x0x0index236, std::array<u64,6>{v_c79, v_c80, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex237, std::array<u64,4>{v_c79, v_c80, 0, 0})) return;
        if (!slog::exists_probe<2,1>(select_branch_ansindex238, std::array<u64,2>{v_c78, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex239, std::array<u64,2>{v_c77, 0})) return;
        slog::join_probe<4,2>(evalindex240, std::array<u64,4>{v_c79, v_c80, 0, 0}, [&](const std::array<u64,4>& m281) {
          u64 v_c81 = m281[2]; u64 v_c82 = m281[3];
          slog::join_probe<6,3>($sup70016x87x0x0x0index241, std::array<u64,6>{v_c79, v_c80, v_c81, 0, 0, 0}, [&](const std::array<u64,6>& m282) {
            u64 v_c83 = m282[3]; u64 v_c84 = m282[4]; u64 v_c85 = m282[5];
            slog::join_probe<4,4>(ifindex242, std::array<u64,4>{v_c83, v_c85, v_c84, v_c82}, [&](const std::array<u64,4>& m283) {
              if (!slog::exists_probe<4,2>(select_branchindex243, std::array<u64,4>{v_c84, v_c85, 0, 0})) return;
              slog::join_probe<4,3>(evalindex244, std::array<u64,4>{v_c83, v_c79, v_c80, 0}, [&](const std::array<u64,4>& m284) {
                u64 v_c86 = m284[3];
                if (!slog::exists_probe<2,1>(eval_ansindex245, std::array<u64,2>{v_c86, 0})) return;
                slog::join_probe<4,2>(select_branchindex246, std::array<u64,4>{v_c84, v_c85, 0, 0}, [&](const std::array<u64,4>& m285) {
                  u64 v_c66 = m285[2]; u64 v_c87 = m285[3];
                  slog::join_probe<2,2>(eval_ansindex247, std::array<u64,2>{v_c86, v_c66}, [&](const std::array<u64,2>& m286) {
                    slog::join_probe<2,2>(select_branch_ansindex248, std::array<u64,2>{v_c87, v_c78}, [&](const std::array<u64,2>& m287) {
                      slog::join_probe<2,1>(eval_ansindex249, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m288) {
                        u64 v_c88 = m288[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c81, v_c88}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask250* _cont = new ReadTask250(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask250(db,b), false);
  // (crule (pre (let __tconst6I9K760 constd59eced1ded07f84c145592f)) (scan temp8oJc1904 __t1WhI754 __t2X4e744 __t5xOK723 __t7vYe738 __t8k6P758) (body (join if (1 3 2 0) 3 __t1WhI754 __t7vYe738 __t2X4e744 __t8UvH755)) (head (emit-temp temp4jKt1905 __t5xOK723 __t8UvH755 __t8k6P758) (mkstruct lambda (1 2 0) __t9E0P759 __t8k6P758 __t8UvH755)) kcfa.slog:70 #f)
  class ReadTask290 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex289;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4jKt1905");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("temp8oJc1904");
      std::vector<u16> ord291({1, 3, 2, 0});
      slog::Relation* readrel292 = db->getRelation("if");
      ifindex289 = readrel292->getIndex(ord291, false);
  
    }
    ReadTask290(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_constd59eced1ded07f84c145592f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c90 = _t[0];
        u64 v_c91 = _t[1];
        u64 v_c92 = _t[2];
        u64 v_c93 = _t[3];
        u64 v_c94 = _t[4];
        slog::join_probe<4,3>(ifindex289, std::array<u64,4>{v_c90, v_c93, v_c91, 0}, [&](const std::array<u64,4>& m293) {
          u64 v_c95 = m293[3];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c92, v_c95, v_c94});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c94, v_c95}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:70", "delta:temp8oJc1904", _fires);
  
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
  // (crule (pre) (scan mp_put __t42s0769 rho x t) (body (exists mp_put_ans (0 1) 1 __t42s0769) (join $sup70016x95x0x0x0 (3 4 5 0 1 2) 3 rho t x __d0 eb er) (join mp_put_ans (0 1) 1 __t42s0769 rho2)) (head (emit $sup70016x95x0x0x1 (1 5 0 2 3 4 6 7) __t42s0769 rho2 __d0 eb er rho t x)) interp.slog:96 #f)
  class ReadTask297 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_ansindex294;  slog::Index** $sup70016x95x0x0x0index295;  slog::Index** mp_put_ansindex296;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x95x0x0x1");
      std::vector<u16> ord298({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel299 = db->getRelation("$sup70016x95x0x0x1");
      head_index[0] = readrel299->getIndex(ord298, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord300({0, 1});
      slog::Relation* readrel301 = db->getRelation("mp_put_ans");
      mp_put_ansindex294 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel303 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index295 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("mp_put_ans");
      mp_put_ansindex296 = readrel305->getIndex(ord304, false);
  
    }
    ReadTask297(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c96 = _t[0];
        u64 v_c79 = _t[1];
        u64 v_c97 = _t[2];
        u64 v_c80 = _t[3];
        if (!slog::exists_probe<2,1>(mp_put_ansindex294, std::array<u64,2>{v_c96, 0})) return;
        slog::join_probe<6,3>($sup70016x95x0x0x0index295, std::array<u64,6>{v_c79, v_c80, v_c97, 0, 0, 0}, [&](const std::array<u64,6>& m306) {
          u64 v_c98 = m306[3]; u64 v_c99 = m306[4]; u64 v_c100 = m306[5];
          slog::join_probe<2,1>(mp_put_ansindex296, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m307) {
            u64 v_c101 = m307[1];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c96, v_c101, v_c98, v_c99, v_c100, v_c79, v_c80, v_c97}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask297* _cont = new ReadTask297(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask297(db,b), false);
  // (crule (pre) (scan mleaf __t3q5a687 k w) (body (join-old mp_put (1 2 3 0) 2 (1 2 3 0) __t3q5a687 k v __t7WtB688)) (head (emit-temp temp5lsY1878 __t7WtB688 k v) (mkstruct mleaf (1 2 0) __t9pzZ686 k v)) map.slog:38 #f)
  class ReadTask310 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex308;  slog::Index** mp_putdelta309;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5lsY1878");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord311({1, 2, 3, 0});
      slog::Relation* readrel312 = db->getRelation("mp_put");
      mp_putindex308 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 2, 3, 0});
      slog::Relation* readrel314 = db->getRelation("mp_put");
      mp_putdelta309 = readrel314->getIndex(ord313, true);
  
    }
    ReadTask310(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c102 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c103 = _t[2];
        slog::join_probe_old<4,2>(mp_putindex308, mp_putdelta309, std::array<u64,4>{v_c102, v_c37, 0, 0}, [&](const std::array<u64,4>& m315) {
          u64 v_c21 = m315[2]; u64 v_c57 = m315[3];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c57, v_c37, v_c21});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c37, v_c21}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:38", "delta:mleaf", _fires);
  
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
  // (crule (pre (let __tconst5cJe186 const4b227777d4dd1fc61c6f884f) (let __tconst0B8U188 const4e07408562bedb8b60ce05c1) (let __tconst1O2C203 const7297d2085ea0adffc396d546) (let __tconst0bgi206 conste29c9c180c6279b0b02abd6a) (let __tconst5diV207 consteb1e33e8a81b697b75855af6) (let __tconst2PAJ212 const624b60c58c9d8bfb6ff1886c)) (scan temp2NPt1949 __t9JAh208) (body (exists ref (1 0) 1 __tconst5diV207) (exists ref (1 0) 1 __tconst0bgi206) (exists ref (1 0) 1 __tconst2PAJ212) (exists num (1 0) 1 __tconst0B8U188) (exists num (1 0) 1 __tconst5cJe186) (join primref (1 0) 1 __tconst1O2C203 __t0nMB204) (join ref (1 0) 1 __tconst5diV207 __t4QtG199) (join ref (1 0) 1 __tconst0bgi206 __t7M5t197) (join ref (1 0) 1 __tconst2PAJ212 __t4x55194) (join num (1 0) 1 __tconst0B8U188 __t5xXk189) (join num (1 0) 1 __tconst5cJe186 __t5VhZ187) (let __t03ww191 (lpush __t9JAh208 __t5xXk189)) (let __t5bmL201 (lpush __t9JAh208 __t4QtG199)) (let __t5rXn209 (lpush __t9JAh208 __tconst5diV207))) (head (emit-temp temp2Udj1950 __t03ww191 __t5bmL201 __t5rXn209)) kcfa.slog:59 #f)
  class ReadTask327 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex316;  slog::Index** refindex317;  slog::Index** refindex318;  slog::Index** numindex319;  slog::Index** numindex320;  slog::Index** primrefindex321;  slog::Index** refindex322;  slog::Index** refindex323;  slog::Index** refindex324;  slog::Index** numindex325;  slog::Index** numindex326;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2Udj1950");
      outer_rel = db->getRelation("temp2NPt1949");
      std::vector<u16> ord328({1, 0});
      slog::Relation* readrel329 = db->getRelation("ref");
      refindex316 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 0});
      slog::Relation* readrel331 = db->getRelation("ref");
      refindex317 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 0});
      slog::Relation* readrel333 = db->getRelation("ref");
      refindex318 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 0});
      slog::Relation* readrel335 = db->getRelation("num");
      numindex319 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 0});
      slog::Relation* readrel337 = db->getRelation("num");
      numindex320 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 0});
      slog::Relation* readrel339 = db->getRelation("primref");
      primrefindex321 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({1, 0});
      slog::Relation* readrel341 = db->getRelation("ref");
      refindex322 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 0});
      slog::Relation* readrel343 = db->getRelation("ref");
      refindex323 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 0});
      slog::Relation* readrel345 = db->getRelation("ref");
      refindex324 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({1, 0});
      slog::Relation* readrel347 = db->getRelation("num");
      numindex325 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({1, 0});
      slog::Relation* readrel349 = db->getRelation("num");
      numindex326 = readrel349->getIndex(ord348, false);
  
    }
    ReadTask327(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c104 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c105 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c106 = v_const7297d2085ea0adffc396d546;
      u64 v_c107 = v_conste29c9c180c6279b0b02abd6a;
      u64 v_c108 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c109 = v_const624b60c58c9d8bfb6ff1886c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c110 = _t[0];
        if (!slog::exists_probe<2,1>(refindex316, std::array<u64,2>{v_c108, 0})) return;
        if (!slog::exists_probe<2,1>(refindex317, std::array<u64,2>{v_c107, 0})) return;
        if (!slog::exists_probe<2,1>(refindex318, std::array<u64,2>{v_c109, 0})) return;
        if (!slog::exists_probe<2,1>(numindex319, std::array<u64,2>{v_c105, 0})) return;
        if (!slog::exists_probe<2,1>(numindex320, std::array<u64,2>{v_c104, 0})) return;
        slog::join_probe<2,1>(primrefindex321, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m350) {
          u64 v_c111 = m350[1];
          slog::join_probe<2,1>(refindex322, std::array<u64,2>{v_c108, 0}, [&](const std::array<u64,2>& m351) {
            u64 v_c112 = m351[1];
            slog::join_probe<2,1>(refindex323, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m352) {
              u64 v_c113 = m352[1];
              slog::join_probe<2,1>(refindex324, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m353) {
                u64 v_c114 = m353[1];
                slog::join_probe<2,1>(numindex325, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m354) {
                  u64 v_c115 = m354[1];
                  slog::join_probe<2,1>(numindex326, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m355) {
                    u64 v_c116 = m355[1];
                    u64 v_c117 = _prim_lpush(db, v_c110, v_c115);
                    if (v_c117 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:59"); return; }
                    u64 v_c118 = _prim_lpush(db, v_c110, v_c112);
                    if (v_c118 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:59"); return; }
                    u64 v_c119 = _prim_lpush(db, v_c110, v_c108);
                    if (v_c119 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:59"); return; }
                    ++_fires;
                    slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c117, v_c118, v_c119});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:59", "delta:temp2NPt1949", _fires);
  
      if (!_done)
      {
        ReadTask327* _cont = new ReadTask327(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask327(db,b), false);
  // (crule (pre (let __tconst85Gw1131 constb9e118781cea1f9fa01462e0) (let __tconst3nKQ305 const06abaa100ecef791ce028c56) (let _00024sqc19MG1022 constd4735e3a265e16eee03f5971) (let _00024sqc5y4j1023 const5feceb66ffc86f38d952786c) (let _00024sqc09of1024 const6b86b273ff34fce19d6b804e) (let _00024sqo41XW1025 const5feceb66ffc86f38d952786c) (let _00024sqo2TL91026 const6b86b273ff34fce19d6b804e) (let _00024sqo4lhI1027 const6b86b273ff34fce19d6b804e) (let _00024sqo7qxI1028 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo7qxI1028 v2 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo2TL91026 v2 _00024seq0) (letp _00024sql8r1X1020 (aslst _00024seq0)) (letp v1 (lref _00024sql8r1X1020 _00024sqc5y4j1023)) (neq v1 v2) (join $seq_at (1 0 2) 3 _00024sqo41XW1025 v1 _00024seq0) (join $seq_atr (1 0 2) 3 _00024sqo4lhI1027 v1 _00024seq0) (exists _enum (1 0) 1 __tconst85Gw1131) (join delta (1 2 0) 2 __tconst3nKQ305 _00024seq0 __t44yZ306) (join _enum (1 0) 1 __tconst85Gw1131 __t4QRG303) (let chk0c4K2060 (llen _00024sql8r1X1020)) (eq _00024sqc19MG1022 chk0c4K2060) (letp chk1JXl2061 (lref _00024sql8r1X1020 _00024sqc09of1024)) (eq v2 chk1JXl2061)) (head (emit-temp temp2zCq2052 __t44yZ306) (mkstruct boolval (1 0) __t6gLd304 __t4QRG303)) interp.slog:124 #f)
  class ReadTask362 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex356;  slog::Index** $seq_atindex357;  slog::Index** $seq_atrindex358;  slog::Index** _enumindex359;  slog::Index** deltaindex360;  slog::Index** _enumindex361;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2zCq2052");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord363({1, 0, 2});
      slog::Relation* readrel364 = db->getRelation("$seq_atr");
      driver_index = readrel364->getIndex(ord363, true);
      std::vector<u16> ord365({1, 0, 2});
      slog::Relation* readrel366 = db->getRelation("$seq_at");
      $seq_atindex356 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({1, 0, 2});
      slog::Relation* readrel368 = db->getRelation("$seq_at");
      $seq_atindex357 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({1, 0, 2});
      slog::Relation* readrel370 = db->getRelation("$seq_atr");
      $seq_atrindex358 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({1, 0});
      slog::Relation* readrel372 = db->getRelation("_enum");
      _enumindex359 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({1, 2, 0});
      slog::Relation* readrel374 = db->getRelation("delta");
      deltaindex360 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({1, 0});
      slog::Relation* readrel376 = db->getRelation("_enum");
      _enumindex361 = readrel376->getIndex(ord375, false);
  
    }
    ReadTask362(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c120 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c121 = v_const06abaa100ecef791ce028c56;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const5feceb66ffc86f38d952786c;
      u64 v_c124 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c125 = v_const5feceb66ffc86f38d952786c;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c128, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m377) {
        u64 v_c129 = m377[1];
        u64 v_c30 = m377[2];
        if (buckethash(v_c129) != bucket) return;
        slog::join_probe<3,3>($seq_atindex356, std::array<u64,3>{v_c126, v_c129, v_c30}, [&](const std::array<u64,3>& m378) {
          bool ok379 = true;
          u64 v_c130 = _prim_aslst(db, v_c30, &ok379);
          if (!ok379) return;
          bool ok380 = true;
          u64 v_c131 = _prim_lref(db, v_c130, v_c123, &ok380);
          if (!ok380) return;
          if (v_c131 == v_c129) return;
          slog::join_probe<3,3>($seq_atindex357, std::array<u64,3>{v_c125, v_c131, v_c30}, [&](const std::array<u64,3>& m381) {
            slog::join_probe<3,3>($seq_atrindex358, std::array<u64,3>{v_c127, v_c131, v_c30}, [&](const std::array<u64,3>& m382) {
              if (!slog::exists_probe<2,1>(_enumindex359, std::array<u64,2>{v_c120, 0})) return;
              slog::join_probe<3,2>(deltaindex360, std::array<u64,3>{v_c121, v_c30, 0}, [&](const std::array<u64,3>& m383) {
                u64 v_c132 = m383[2];
                slog::join_probe<2,1>(_enumindex361, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m384) {
                  u64 v_c133 = m384[1];
                  u64 v_c134 = _prim_llen(db, v_c130);
                  if (v_c134 == slog_error) { slog::emit_pending_error(db, "interp.slog:124"); return; }
                  if (v_c122 != v_c134) return;
                  bool ok385 = true;
                  u64 v_c135 = _prim_lref(db, v_c130, v_c124, &ok385);
                  if (!ok385) return;
                  if (v_c129 != v_c135) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c132});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c133}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:124", "delta:$seq_atr", _fires);
  
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
  // (crule (pre (let _00024sqc5t6g874 const6b86b273ff34fce19d6b804e) (let _00024sqc6Vq0875 const5feceb66ffc86f38d952786c) (let _00024sqc7EIM876 const6b86b273ff34fce19d6b804e) (let _00024sqc3AAz877 const5feceb66ffc86f38d952786c) (let _00024sqc8VOs884 const6b86b273ff34fce19d6b804e) (let _00024sqc5QMC885 const5feceb66ffc86f38d952786c) (let _00024sqc6WRs886 const6b86b273ff34fce19d6b804e) (let _00024sqc7zXY887 const5feceb66ffc86f38d952786c) (let __trid4rvQ1333 const075bb5fb917b6c9c7bfeecc3) (let __trel8fMT1334 const65c80aac3433a01ef8a7f298) (let __tcol6Agz1335 const5feceb66ffc86f38d952786c) (let __trel6nGS1336 const52b5e20f559958f34e533431) (let __tcol0eVZ1337 const5feceb66ffc86f38d952786c) (let __trel9nyR1338 const52b5e20f559958f34e533431) (let __tcol8dz81339 constd4735e3a265e16eee03f5971)) (scan bind_store _00024seq0 _00024seq1 t2 t) (body (letp _00024sql0XgW872 (aslst _00024seq1)) (let _00024sqn3TP4873 (llen _00024sql0XgW872)) (cmp ge _00024sqn3TP4873 _00024sqc5t6g874) (letp _00024sql57ZT882 (aslst _00024seq0)) (let _00024sqn2L9K883 (llen _00024sql57ZT882)) (cmp ge _00024sqn2L9K883 _00024sqc8VOs884) (letp v (lref _00024sql0XgW872 _00024sqc6Vq0875)) (let _00024sqp00zi878 (_0002d _00024sqn3TP4873 _00024sqc3AAz877)) (let vs (lslice _00024sql0XgW872 _00024sqc7EIM876 _00024sqp00zi878)) (letp x (lref _00024sql57ZT882 _00024sqc5QMC885)) (let _00024sqp759G888 (_0002d _00024sqn2L9K883 _00024sqc7zXY887)) (let xs (lslice _00024sql57ZT882 _00024sqc6WRs886 _00024sqp759G888))) (head (tycheck x (accept int) __trid4rvQ1333 __trel8fMT1334 __tcol6Agz1335 (1 2 3 4 0)) (tycheck x (accept int) __trid4rvQ1333 __trel6nGS1336 __tcol0eVZ1337 (1 2 3 4 0)) (tycheck v (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid4rvQ1333 __trel9nyR1338 __tcol8dz81339 (1 2 3 4 0)) (emit bind_store (0 1 2 3) xs vs t2 t) (emit binding_event (0 1 2) x t2 t) (emit store (0 1 2) x t2 v)) interp.slog:68 #f)
  class ReadTask391 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid388;  u32 sid386;  u32 sid387;  u32 sid389;  u32 sid390;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("bind_store");
      std::vector<u16> ord392({0, 1, 2, 3});
      slog::Relation* readrel393 = db->getRelation("bind_store");
      head_index[3] = readrel393->getIndex(ord392, false);
      head_rel[4] = db->getRelation("binding_event");
      std::vector<u16> ord394({0, 1, 2});
      slog::Relation* readrel395 = db->getRelation("binding_event");
      head_index[4] = readrel395->getIndex(ord394, false);
      head_rel[5] = db->getRelation("store");
      std::vector<u16> ord396({0, 1, 2});
      slog::Relation* readrel397 = db->getRelation("store");
      head_index[5] = readrel397->getIndex(ord396, false);
      outer_rel = db->getRelation("bind_store");
      sid388 = db->getRelation("_enum")->getStructId();
      sid386 = db->getRelation("boolval")->getStructId();
      sid387 = db->getRelation("closure")->getStructId();
      sid389 = db->getRelation("prim")->getStructId();
      sid390 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask391(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c136 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c137 = v_const5feceb66ffc86f38d952786c;
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c139 = v_const5feceb66ffc86f38d952786c;
      u64 v_c140 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c141 = v_const5feceb66ffc86f38d952786c;
      u64 v_c142 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c143 = v_const5feceb66ffc86f38d952786c;
      u64 v_c144 = v_const075bb5fb917b6c9c7bfeecc3;
      u64 v_c145 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c146 = v_const5feceb66ffc86f38d952786c;
      u64 v_c147 = v_const52b5e20f559958f34e533431;
      u64 v_c148 = v_const5feceb66ffc86f38d952786c;
      u64 v_c149 = v_const52b5e20f559958f34e533431;
      u64 v_c150 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[6];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c30 = _t[0];
        u64 v_c151 = _t[1];
        u64 v_c152 = _t[2];
        u64 v_c80 = _t[3];
        bool ok398 = true;
        u64 v_c153 = _prim_aslst(db, v_c151, &ok398);
        if (!ok398) return;
        u64 v_c154 = _prim_llen(db, v_c153);
        if (v_c154 == slog_error) { slog::emit_pending_error(db, "interp.slog:68"); return; }
        u64 v_c155 = _prim_ge(db, v_c154, v_c136);
        if (v_c155 == slog_error) { slog::emit_pending_error(db, "interp.slog:68"); return; }
        if (!v_c155) return;
        bool ok400 = true;
        u64 v_c156 = _prim_aslst(db, v_c30, &ok400);
        if (!ok400) return;
        u64 v_c157 = _prim_llen(db, v_c156);
        if (v_c157 == slog_error) { slog::emit_pending_error(db, "interp.slog:68"); return; }
        u64 v_c158 = _prim_ge(db, v_c157, v_c140);
        if (v_c158 == slog_error) { slog::emit_pending_error(db, "interp.slog:68"); return; }
        if (!v_c158) return;
        bool ok402 = true;
        u64 v_c21 = _prim_lref(db, v_c153, v_c137, &ok402);
        if (!ok402) return;
        u64 v_c159 = _prim__0002d(db, v_c154, v_c139);
        if (v_c159 == slog_error) { slog::emit_pending_error(db, "interp.slog:68"); return; }
        u64 v_c160 = _prim_lslice(db, v_c153, v_c138, v_c159);
        if (v_c160 == slog_error) { slog::emit_pending_error(db, "interp.slog:68"); return; }
        bool ok403 = true;
        u64 v_c97 = _prim_lref(db, v_c156, v_c141, &ok403);
        if (!ok403) return;
        u64 v_c161 = _prim__0002d(db, v_c157, v_c143);
        if (v_c161 == slog_error) { slog::emit_pending_error(db, "interp.slog:68"); return; }
        u64 v_c162 = _prim_lslice(db, v_c156, v_c142, v_c161);
        if (v_c162 == slog_error) { slog::emit_pending_error(db, "interp.slog:68"); return; }
        ++_fires;
        if (!(is_int(v_c97)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c144, v_c145, v_c146, v_c97}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c97)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c144, v_c147, v_c148, v_c97}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c21) && (decode_struct_id(v_c21) == sid386 || decode_struct_id(v_c21) == sid387 || decode_struct_id(v_c21) == sid388 || decode_struct_id(v_c21) == sid389 || decode_struct_id(v_c21) == sid390))))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c144, v_c149, v_c150, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit<4>(head_rel[3], head_index[3], newbatch[3], std::array<u64,4>{v_c162, v_c160, v_c152, v_c80}, std::array<u16,4>{0, 1, 2, 3});
        slog::emit<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,3>{v_c97, v_c152, v_c80}, std::array<u16,3>{0, 1, 2});
        slog::emit<3>(head_rel[5], head_index[5], newbatch[5], std::array<u64,3>{v_c97, v_c152, v_c21}, std::array<u16,3>{0, 1, 2});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
  
      if (_fires) db->bumpFires("interp.slog:68", "delta:bind_store", _fires);
  
      if (!_done)
      {
        ReadTask391* _cont = new ReadTask391(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask391(db,b), false);
  // (crule (pre) (scan mp_join __t2akg809 p0 t0 p1 t1) (body) (head (emit $sup5638x25x0x0x0 (1 0 2 3 4) p0 __t2akg809 p1 t0 t1)) map.slog:26 #f)
  class ReadTask404 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord405({1, 0, 2, 3, 4});
      slog::Relation* readrel406 = db->getRelation("$sup5638x25x0x0x0");
      head_index[0] = readrel406->getIndex(ord405, false);
      outer_rel = db->getRelation("mp_join");
  
    }
    ReadTask404(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c163 = _t[0];
        u64 v_c164 = _t[1];
        u64 v_c165 = _t[2];
        u64 v_c166 = _t[3];
        u64 v_c167 = _t[4];
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c164, v_c163, v_c166, v_c165, v_c167}, std::array<u16,5>{1, 0, 2, 3, 4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask404* _cont = new ReadTask404(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask404(db,b), false);
  // (crule (pre) (scan extend_env __t5fzh540 rhoc xs t2) (body (exists $sup70016x51x0x0x1 (8 10 12 3 4 0 1 2 5 6 7 9 11) 3 rhoc t2 xs) (exists lambda (1 2 0) 1 xs) (exists closure (2 0 1) 1 rhoc) (exists eval (3 1 0 2) 1 t2) (exists extend_env_ans (0 1) 1 __t5fzh540) (join tick_ans (1 0) 1 t2 __t0CD9539) (join $sup70016x51x0x0x1 (8 10 12 3 4 0 1 2 5 6 7 9 11) 4 rhoc t2 xs __t0CD9539 eb __t2z6s532 __t5qy8533 __t2srV536 ef es rho t vs) (join $sup70016x51x0x0x0 (4 0 3 1 2) 5 t __t2z6s532 rho ef es) (join eval (2 3 0 1) 4 rho t __t5qy8533 ef) (join eval_args (3 2 0 1) 4 t rho __t2srV536 es) (exists app (1 2 0) 2 ef es) (exists tick (0 2 1) 2 __t0CD9539 t) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists lambda (1 2 0) 2 xs eb) (exists eval_ans (0 1) 1 __t5qy8533) (exists eval (3 1 0 2) 2 t2 eb) (join eval (2 3 0 1) 3 rho t __t2z6s532 __t5a7h538) (join app (0 1 2) 3 __t5a7h538 ef es) (join tick (0 2 1) 3 __t0CD9539 t __t5a7h538) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join lambda (1 2 0) 2 xs eb __t6iPm534) (join closure (1 2 0) 2 __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join eval (3 1 0 2) 2 t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask433 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x1index407;  slog::Index** lambdaindex408;  slog::Index** closureindex409;  slog::Index** evalindex410;  slog::Index** extend_env_ansindex411;  slog::Index** tick_ansindex412;  slog::Index** $sup70016x51x0x0x1index413;  slog::Index** $sup70016x51x0x0x0index414;  slog::Index** evalindex415;  slog::Index** eval_argsindex416;  slog::Index** appindex417;  slog::Index** tickindex418;  slog::Index** eval_args_ansindex419;  slog::Index** lambdaindex420;  slog::Index** eval_ansindex421;  slog::Index** evalindex422;  slog::Index** evalindex423;  slog::Index** appindex424;  slog::Index** tickindex425;  slog::Index** eval_args_ansindex426;  slog::Index** lambdaindex427;  slog::Index** closureindex428;  slog::Index** eval_ansindex429;  slog::Index** evalindex430;  slog::Index** extend_env_ansindex431;  slog::Index** eval_ansindex432;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord434({0, 1});
      slog::Relation* readrel435 = db->getRelation("eval_ans");
      head_index[0] = readrel435->getIndex(ord434, false);
      outer_rel = db->getRelation("extend_env");
      std::vector<u16> ord436({8, 10, 12, 3, 4, 0, 1, 2, 5, 6, 7, 9, 11});
      slog::Relation* readrel437 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index407 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({1, 2, 0});
      slog::Relation* readrel439 = db->getRelation("lambda");
      lambdaindex408 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({2, 0, 1});
      slog::Relation* readrel441 = db->getRelation("closure");
      closureindex409 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({3, 1, 0, 2});
      slog::Relation* readrel443 = db->getRelation("eval");
      evalindex410 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({0, 1});
      slog::Relation* readrel445 = db->getRelation("extend_env_ans");
      extend_env_ansindex411 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({1, 0});
      slog::Relation* readrel447 = db->getRelation("tick_ans");
      tick_ansindex412 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({8, 10, 12, 3, 4, 0, 1, 2, 5, 6, 7, 9, 11});
      slog::Relation* readrel449 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index413 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({4, 0, 3, 1, 2});
      slog::Relation* readrel451 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index414 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({2, 3, 0, 1});
      slog::Relation* readrel453 = db->getRelation("eval");
      evalindex415 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({3, 2, 0, 1});
      slog::Relation* readrel455 = db->getRelation("eval_args");
      eval_argsindex416 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 2, 0});
      slog::Relation* readrel457 = db->getRelation("app");
      appindex417 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 2, 1});
      slog::Relation* readrel459 = db->getRelation("tick");
      tickindex418 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("eval_args_ans");
      eval_args_ansindex419 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 2, 0});
      slog::Relation* readrel463 = db->getRelation("lambda");
      lambdaindex420 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({0, 1});
      slog::Relation* readrel465 = db->getRelation("eval_ans");
      eval_ansindex421 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({3, 1, 0, 2});
      slog::Relation* readrel467 = db->getRelation("eval");
      evalindex422 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({2, 3, 0, 1});
      slog::Relation* readrel469 = db->getRelation("eval");
      evalindex423 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({0, 1, 2});
      slog::Relation* readrel471 = db->getRelation("app");
      appindex424 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({0, 2, 1});
      slog::Relation* readrel473 = db->getRelation("tick");
      tickindex425 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({0, 1});
      slog::Relation* readrel475 = db->getRelation("eval_args_ans");
      eval_args_ansindex426 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("lambda");
      lambdaindex427 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 2, 0});
      slog::Relation* readrel479 = db->getRelation("closure");
      closureindex428 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({0, 1});
      slog::Relation* readrel481 = db->getRelation("eval_ans");
      eval_ansindex429 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({3, 1, 0, 2});
      slog::Relation* readrel483 = db->getRelation("eval");
      evalindex430 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({0, 1});
      slog::Relation* readrel485 = db->getRelation("extend_env_ans");
      extend_env_ansindex431 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({0, 1});
      slog::Relation* readrel487 = db->getRelation("eval_ans");
      eval_ansindex432 = readrel487->getIndex(ord486, false);
  
    }
    ReadTask433(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c168 = _t[0];
        u64 v_c169 = _t[1];
        u64 v_c162 = _t[2];
        u64 v_c152 = _t[3];
        if (!slog::exists_probe<13,3>($sup70016x51x0x0x1index407, std::array<u64,13>{v_c169, v_c152, v_c162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex408, std::array<u64,3>{v_c162, 0, 0})) return;
        if (!slog::exists_probe<3,1>(closureindex409, std::array<u64,3>{v_c169, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex410, std::array<u64,4>{v_c152, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(extend_env_ansindex411, std::array<u64,2>{v_c168, 0})) return;
        slog::join_probe<2,1>(tick_ansindex412, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m488) {
          u64 v_c170 = m488[1];
          slog::join_probe<13,4>($sup70016x51x0x0x1index413, std::array<u64,13>{v_c169, v_c152, v_c162, v_c170, 0, 0, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m489) {
            u64 v_c99 = m489[4]; u64 v_c171 = m489[5]; u64 v_c172 = m489[6]; u64 v_c173 = m489[7]; u64 v_c174 = m489[8]; u64 v_c175 = m489[9]; u64 v_c79 = m489[10]; u64 v_c80 = m489[11]; u64 v_c160 = m489[12];
            slog::join_probe<5,5>($sup70016x51x0x0x0index414, std::array<u64,5>{v_c80, v_c171, v_c79, v_c174, v_c175}, [&](const std::array<u64,5>& m490) {
              slog::join_probe<4,4>(evalindex415, std::array<u64,4>{v_c79, v_c80, v_c172, v_c174}, [&](const std::array<u64,4>& m491) {
                slog::join_probe<4,4>(eval_argsindex416, std::array<u64,4>{v_c80, v_c79, v_c173, v_c175}, [&](const std::array<u64,4>& m492) {
                  if (!slog::exists_probe<3,2>(appindex417, std::array<u64,3>{v_c174, v_c175, 0})) return;
                  if (!slog::exists_probe<3,2>(tickindex418, std::array<u64,3>{v_c170, v_c80, 0})) return;
                  if (!slog::exists_probe<2,2>(eval_args_ansindex419, std::array<u64,2>{v_c173, v_c160})) return;
                  if (!slog::exists_probe<3,2>(lambdaindex420, std::array<u64,3>{v_c162, v_c99, 0})) return;
                  if (!slog::exists_probe<2,1>(eval_ansindex421, std::array<u64,2>{v_c172, 0})) return;
                  if (!slog::exists_probe<4,2>(evalindex422, std::array<u64,4>{v_c152, v_c99, 0, 0})) return;
                  slog::join_probe<4,3>(evalindex423, std::array<u64,4>{v_c79, v_c80, v_c171, 0}, [&](const std::array<u64,4>& m493) {
                    u64 v_c176 = m493[3];
                    slog::join_probe<3,3>(appindex424, std::array<u64,3>{v_c176, v_c174, v_c175}, [&](const std::array<u64,3>& m494) {
                      slog::join_probe<3,3>(tickindex425, std::array<u64,3>{v_c170, v_c80, v_c176}, [&](const std::array<u64,3>& m495) {
                        slog::join_probe<2,2>(eval_args_ansindex426, std::array<u64,2>{v_c173, v_c160}, [&](const std::array<u64,2>& m496) {
                          slog::join_probe<3,2>(lambdaindex427, std::array<u64,3>{v_c162, v_c99, 0}, [&](const std::array<u64,3>& m497) {
                            u64 v_c177 = m497[2];
                            slog::join_probe<3,2>(closureindex428, std::array<u64,3>{v_c177, v_c169, 0}, [&](const std::array<u64,3>& m498) {
                              u64 v_c178 = m498[2];
                              slog::join_probe<2,2>(eval_ansindex429, std::array<u64,2>{v_c172, v_c178}, [&](const std::array<u64,2>& m499) {
                                slog::join_probe<4,2>(evalindex430, std::array<u64,4>{v_c152, v_c99, 0, 0}, [&](const std::array<u64,4>& m500) {
                                  u64 v_c179 = m500[2]; u64 v_c66 = m500[3];
                                  slog::join_probe<2,2>(extend_env_ansindex431, std::array<u64,2>{v_c168, v_c66}, [&](const std::array<u64,2>& m501) {
                                    slog::join_probe<2,1>(eval_ansindex432, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m502) {
                                      u64 v_c21 = m502[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c171, v_c21}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:extend_env", _fires);
  
      if (!_done)
      {
        ReadTask433* _cont = new ReadTask433(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask433(db,b), false);
  // (crule (pre) (scan tick __t2n7W617 __t3MQm616 t) (body (exists eval (3 1 0 2) 1 t) (exists eval_args (3 2 0 1) 1 t) (exists tick_ans (0 1) 1 __t2n7W617) (join eval (3 1 0 2) 2 t __t3MQm616 __3JBR1203 rho) (exists eval_args (3 2 0 1) 2 t rho) (join eval (2 3 0 1) 2 rho t __t7lOb612 ef) (exists eval_ans (0 1) 1 __t7lOb612) (join app (0 1 2) 2 __t3MQm616 ef es) (join eval_args (1 3 2 0) 3 es t rho __t192L615) (exists eval_args_ans (0 1) 1 __t192L615) (join eval_ans (0 1) 1 __t7lOb612 __t6tRF614) (join eval_args_ans (0 1) 1 __t192L615 vs) (join tick_ans (0 1) 1 __t2n7W617 t2) (join closure (0 1 2) 1 __t6tRF614 __t20Nd613 rhoc) (join lambda (0 1 2) 1 __t20Nd613 xs eb)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask518 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex503;  slog::Index** eval_argsindex504;  slog::Index** tick_ansindex505;  slog::Index** evalindex506;  slog::Index** eval_argsindex507;  slog::Index** evalindex508;  slog::Index** eval_ansindex509;  slog::Index** appindex510;  slog::Index** eval_argsindex511;  slog::Index** eval_args_ansindex512;  slog::Index** eval_ansindex513;  slog::Index** eval_args_ansindex514;  slog::Index** tick_ansindex515;  slog::Index** closureindex516;  slog::Index** lambdaindex517;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord519({0, 1, 2, 3});
      slog::Relation* readrel520 = db->getRelation("bind_store");
      head_index[0] = readrel520->getIndex(ord519, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord521({0, 1});
      slog::Relation* readrel522 = db->getRelation("call_event");
      head_index[1] = readrel522->getIndex(ord521, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord523({3, 1, 0, 2});
      slog::Relation* readrel524 = db->getRelation("eval");
      evalindex503 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({3, 2, 0, 1});
      slog::Relation* readrel526 = db->getRelation("eval_args");
      eval_argsindex504 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({0, 1});
      slog::Relation* readrel528 = db->getRelation("tick_ans");
      tick_ansindex505 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({3, 1, 0, 2});
      slog::Relation* readrel530 = db->getRelation("eval");
      evalindex506 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({3, 2, 0, 1});
      slog::Relation* readrel532 = db->getRelation("eval_args");
      eval_argsindex507 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({2, 3, 0, 1});
      slog::Relation* readrel534 = db->getRelation("eval");
      evalindex508 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({0, 1});
      slog::Relation* readrel536 = db->getRelation("eval_ans");
      eval_ansindex509 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({0, 1, 2});
      slog::Relation* readrel538 = db->getRelation("app");
      appindex510 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 3, 2, 0});
      slog::Relation* readrel540 = db->getRelation("eval_args");
      eval_argsindex511 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({0, 1});
      slog::Relation* readrel542 = db->getRelation("eval_args_ans");
      eval_args_ansindex512 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({0, 1});
      slog::Relation* readrel544 = db->getRelation("eval_ans");
      eval_ansindex513 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({0, 1});
      slog::Relation* readrel546 = db->getRelation("eval_args_ans");
      eval_args_ansindex514 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({0, 1});
      slog::Relation* readrel548 = db->getRelation("tick_ans");
      tick_ansindex515 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({0, 1, 2});
      slog::Relation* readrel550 = db->getRelation("closure");
      closureindex516 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({0, 1, 2});
      slog::Relation* readrel552 = db->getRelation("lambda");
      lambdaindex517 = readrel552->getIndex(ord551, false);
  
    }
    ReadTask518(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c180 = _t[0];
        u64 v_c181 = _t[1];
        u64 v_c80 = _t[2];
        if (!slog::exists_probe<4,1>(evalindex503, std::array<u64,4>{v_c80, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(eval_argsindex504, std::array<u64,4>{v_c80, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(tick_ansindex505, std::array<u64,2>{v_c180, 0})) return;
        slog::join_probe<4,2>(evalindex506, std::array<u64,4>{v_c80, v_c181, 0, 0}, [&](const std::array<u64,4>& m553) {
          u64 v_c182 = m553[2]; u64 v_c79 = m553[3];
          if (!slog::exists_probe<4,2>(eval_argsindex507, std::array<u64,4>{v_c80, v_c79, 0, 0})) return;
          slog::join_probe<4,2>(evalindex508, std::array<u64,4>{v_c79, v_c80, 0, 0}, [&](const std::array<u64,4>& m554) {
            u64 v_c183 = m554[2]; u64 v_c174 = m554[3];
            if (!slog::exists_probe<2,1>(eval_ansindex509, std::array<u64,2>{v_c183, 0})) return;
            slog::join_probe<3,2>(appindex510, std::array<u64,3>{v_c181, v_c174, 0}, [&](const std::array<u64,3>& m555) {
              u64 v_c175 = m555[2];
              slog::join_probe<4,3>(eval_argsindex511, std::array<u64,4>{v_c175, v_c80, v_c79, 0}, [&](const std::array<u64,4>& m556) {
                u64 v_c184 = m556[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex512, std::array<u64,2>{v_c184, 0})) return;
                slog::join_probe<2,1>(eval_ansindex513, std::array<u64,2>{v_c183, 0}, [&](const std::array<u64,2>& m557) {
                  u64 v_c185 = m557[1];
                  slog::join_probe<2,1>(eval_args_ansindex514, std::array<u64,2>{v_c184, 0}, [&](const std::array<u64,2>& m558) {
                    u64 v_c160 = m558[1];
                    slog::join_probe<2,1>(tick_ansindex515, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m559) {
                      u64 v_c152 = m559[1];
                      slog::join_probe<3,1>(closureindex516, std::array<u64,3>{v_c185, 0, 0}, [&](const std::array<u64,3>& m560) {
                        u64 v_c186 = m560[1]; u64 v_c169 = m560[2];
                        slog::join_probe<3,1>(lambdaindex517, std::array<u64,3>{v_c186, 0, 0}, [&](const std::array<u64,3>& m561) {
                          u64 v_c162 = m561[1]; u64 v_c99 = m561[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c162, v_c160, v_c152, v_c80}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c152, v_c80}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask518* _cont = new ReadTask518(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask518(db,b), false);
  // (crule (pre) (scan mp_union __t2vfE24 __t7Hza25 __t3dlR26) (body (join-old mp_join (2 4 0 1 3) 2 (2 4 0 1 3) __t7Hza25 __t3dlR26 __t77mZ27 p q) (neq p q) (exists mbranch (0 1 2 3 4) 2 __t3dlR26 q) (exists mp_join_ans (0 1) 1 __t77mZ27) (join-old mbranch (0 1 2 3 4) 2 (0 1 2 3 4) __t7Hza25 p m l r) (join-old mbranch (0 1 2 3 4) 3 (0 1 2 3 4) __t3dlR26 q m u v) (join mp_join_ans (0 1) 1 __t77mZ27 res)) (head (emit mp_union_ans (0 1) __t2vfE24 res)) map.slog:114 #f)
  class ReadTask571 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex562;  slog::Index** mbranchindex563;  slog::Index** mp_join_ansindex564;  slog::Index** mbranchindex565;  slog::Index** mbranchindex566;  slog::Index** mp_join_ansindex567;  slog::Index** mp_joindelta568;  slog::Index** mbranchdelta569;  slog::Index** mbranchdelta570;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord572({0, 1});
      slog::Relation* readrel573 = db->getRelation("mp_union_ans");
      head_index[0] = readrel573->getIndex(ord572, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord574({2, 4, 0, 1, 3});
      slog::Relation* readrel575 = db->getRelation("mp_join");
      mp_joinindex562 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({2, 4, 0, 1, 3});
      slog::Relation* readrel577 = db->getRelation("mp_join");
      mp_joindelta568 = readrel577->getIndex(ord576, true);
      std::vector<u16> ord578({0, 1, 2, 3, 4});
      slog::Relation* readrel579 = db->getRelation("mbranch");
      mbranchindex563 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({0, 1});
      slog::Relation* readrel581 = db->getRelation("mp_join_ans");
      mp_join_ansindex564 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({0, 1, 2, 3, 4});
      slog::Relation* readrel583 = db->getRelation("mbranch");
      mbranchindex565 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({0, 1, 2, 3, 4});
      slog::Relation* readrel585 = db->getRelation("mbranch");
      mbranchdelta569 = readrel585->getIndex(ord584, true);
      std::vector<u16> ord586({0, 1, 2, 3, 4});
      slog::Relation* readrel587 = db->getRelation("mbranch");
      mbranchindex566 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({0, 1, 2, 3, 4});
      slog::Relation* readrel589 = db->getRelation("mbranch");
      mbranchdelta570 = readrel589->getIndex(ord588, true);
      std::vector<u16> ord590({0, 1});
      slog::Relation* readrel591 = db->getRelation("mp_join_ans");
      mp_join_ansindex567 = readrel591->getIndex(ord590, false);
  
    }
    ReadTask571(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[0];
        u64 v_c61 = _t[1];
        u64 v_c62 = _t[2];
        slog::join_probe_old<5,2>(mp_joinindex562, mp_joindelta568, std::array<u64,5>{v_c61, v_c62, 0, 0, 0}, [&](const std::array<u64,5>& m592) {
          u64 v_c59 = m592[2]; u64 v_c13 = m592[3]; u64 v_c19 = m592[4];
          if (v_c13 == v_c19) return;
          if (!slog::exists_probe<5,2>(mbranchindex563, std::array<u64,5>{v_c62, v_c19, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex564, std::array<u64,2>{v_c59, 0})) return;
          slog::join_probe_old<5,2>(mbranchindex565, mbranchdelta569, std::array<u64,5>{v_c61, v_c13, 0, 0, 0}, [&](const std::array<u64,5>& m593) {
            u64 v_c14 = m593[2]; u64 v_c15 = m593[3]; u64 v_c16 = m593[4];
            slog::join_probe_old<5,3>(mbranchindex566, mbranchdelta570, std::array<u64,5>{v_c62, v_c19, v_c14, 0, 0}, [&](const std::array<u64,5>& m594) {
              u64 v_c20 = m594[3]; u64 v_c21 = m594[4];
              slog::join_probe<2,1>(mp_join_ansindex567, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m595) {
                u64 v_c60 = m595[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c63, v_c60}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask571* _cont = new ReadTask571(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask571(db,b), false);
  // (crule (pre) (scan mleaf __t4yTi228 k v) (body (join-old mp_get (1 2 0) 2 (1 2 0) __t4yTi228 k __t8tXp229)) (head (emit mp_get_ans (0 1) __t8tXp229 v)) map.slog:51 #f)
  class ReadTask598 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex596;  slog::Index** mp_getdelta597;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord599({0, 1});
      slog::Relation* readrel600 = db->getRelation("mp_get_ans");
      head_index[0] = readrel600->getIndex(ord599, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord601({1, 2, 0});
      slog::Relation* readrel602 = db->getRelation("mp_get");
      mp_getindex596 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({1, 2, 0});
      slog::Relation* readrel604 = db->getRelation("mp_get");
      mp_getdelta597 = readrel604->getIndex(ord603, true);
  
    }
    ReadTask598(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c187 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c21 = _t[2];
        slog::join_probe_old<3,2>(mp_getindex596, mp_getdelta597, std::array<u64,3>{v_c187, v_c37, 0}, [&](const std::array<u64,3>& m605) {
          u64 v_c188 = m605[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c188, v_c21}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:51", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask598* _cont = new ReadTask598(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask598(db,b), false);
  // (crule (pre) (scan mleaf __t4XKi420 k v) (body (exists mp_union (1 2 0) 1 __t4XKi420) (join-old mp_put (2 3 0 1) 2 (2 3 0 1) k v __t1yia422 t) (exists mp_put_ans (0 1) 1 __t1yia422) (join-old mp_union (1 2 0) 2 (1 2 0) __t4XKi420 t __t5GHT421) (join mp_put_ans (0 1) 1 __t1yia422 r)) (head (emit mp_union_ans (0 1) __t5GHT421 r)) map.slog:92 #f)
  class ReadTask613 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex606;  slog::Index** mp_putindex607;  slog::Index** mp_put_ansindex608;  slog::Index** mp_unionindex609;  slog::Index** mp_put_ansindex610;  slog::Index** mp_putdelta611;  slog::Index** mp_uniondelta612;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord614({0, 1});
      slog::Relation* readrel615 = db->getRelation("mp_union_ans");
      head_index[0] = readrel615->getIndex(ord614, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord616({1, 2, 0});
      slog::Relation* readrel617 = db->getRelation("mp_union");
      mp_unionindex606 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({2, 3, 0, 1});
      slog::Relation* readrel619 = db->getRelation("mp_put");
      mp_putindex607 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({2, 3, 0, 1});
      slog::Relation* readrel621 = db->getRelation("mp_put");
      mp_putdelta611 = readrel621->getIndex(ord620, true);
      std::vector<u16> ord622({0, 1});
      slog::Relation* readrel623 = db->getRelation("mp_put_ans");
      mp_put_ansindex608 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 0});
      slog::Relation* readrel625 = db->getRelation("mp_union");
      mp_unionindex609 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 2, 0});
      slog::Relation* readrel627 = db->getRelation("mp_union");
      mp_uniondelta612 = readrel627->getIndex(ord626, true);
      std::vector<u16> ord628({0, 1});
      slog::Relation* readrel629 = db->getRelation("mp_put_ans");
      mp_put_ansindex610 = readrel629->getIndex(ord628, false);
  
    }
    ReadTask613(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c189 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c21 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex606, std::array<u64,3>{v_c189, 0, 0})) return;
        slog::join_probe_old<4,2>(mp_putindex607, mp_putdelta611, std::array<u64,4>{v_c37, v_c21, 0, 0}, [&](const std::array<u64,4>& m630) {
          u64 v_c190 = m630[2]; u64 v_c80 = m630[3];
          if (!slog::exists_probe<2,1>(mp_put_ansindex608, std::array<u64,2>{v_c190, 0})) return;
          slog::join_probe_old<3,2>(mp_unionindex609, mp_uniondelta612, std::array<u64,3>{v_c189, v_c80, 0}, [&](const std::array<u64,3>& m631) {
            u64 v_c191 = m631[2];
            slog::join_probe<2,1>(mp_put_ansindex610, std::array<u64,2>{v_c190, 0}, [&](const std::array<u64,2>& m632) {
              u64 v_c16 = m632[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c191, v_c16}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask613* _cont = new ReadTask613(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask613(db,b), false);
  // (crule (pre (let __trid8zjw1508 const5f7e60cb3d02e4170101c2bc) (let __trel6ZK11509 const7f254967624b26d820569bd6) (let __tcol1e691510 const6b86b273ff34fce19d6b804e) (let __trel9oYr1511 const72bac24066bb34077c1f6e71) (let __tcol16nZ1512 const5feceb66ffc86f38d952786c) (let __trel6wY71513 const72bac24066bb34077c1f6e71) (let __tcol3HWh1514 const6b86b273ff34fce19d6b804e) (let __trel8qkm1515 const72bac24066bb34077c1f6e71) (let __tcol7vdS1516 constd4735e3a265e16eee03f5971) (let __trel9zU41517 const72bac24066bb34077c1f6e71) (let __tcol4Wra1518 const4e07408562bedb8b60ce05c1)) (scan $sup5638x104x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck u (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8zjw1508 __trel6ZK11509 __tcol1e691510 (1 2 3 4 0)) (tycheck p (accept int) __trid8zjw1508 __trel9oYr1511 __tcol16nZ1512 (1 2 3 4 0)) (tycheck m (accept int) __trid8zjw1508 __trel6wY71513 __tcol3HWh1514 (1 2 3 4 0)) (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8zjw1508 __trel8qkm1515 __tcol7vdS1516 (1 2 3 4 0)) (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8zjw1508 __trel9zU41517 __tcol4Wra1518 (1 2 3 4 0)) (emit-temp temp0VqC1776 l m p r u) (mkstruct mbranch (1 2 3 4 0) __t17aB636 p m l r)) map.slog:105 #f)
  class ReadTask636 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid634;  u32 sid633;  u32 sid635;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp0VqC1776");
      head_rel[6] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x104x0x0x1");
      sid634 = db->getRelation("_enum")->getStructId();
      sid633 = db->getRelation("mbranch")->getStructId();
      sid635 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask636(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c192 = v_const5f7e60cb3d02e4170101c2bc;
      u64 v_c193 = v_const7f254967624b26d820569bd6;
      u64 v_c194 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c195 = v_const72bac24066bb34077c1f6e71;
      u64 v_c196 = v_const5feceb66ffc86f38d952786c;
      u64 v_c197 = v_const72bac24066bb34077c1f6e71;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const72bac24066bb34077c1f6e71;
      u64 v_c200 = v_constd4735e3a265e16eee03f5971;
      u64 v_c201 = v_const72bac24066bb34077c1f6e71;
      u64 v_c202 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c98 = _t[0];
        u64 v_c203 = _t[1];
        u64 v_c15 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c204 = _t[4];
        u64 v_c13 = _t[5];
        u64 v_c19 = _t[6];
        u64 v_c16 = _t[7];
        u64 v_c20 = _t[8];
        u64 v_c21 = _t[9];
        ++_fires;
        if (!((is_struct(v_c20) && (decode_struct_id(v_c20) == sid633 || decode_struct_id(v_c20) == sid634 || decode_struct_id(v_c20) == sid635))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c192, v_c193, v_c194, v_c20}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c13)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c192, v_c195, v_c196, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c14)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c192, v_c197, v_c198, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c15) && (decode_struct_id(v_c15) == sid633 || decode_struct_id(v_c15) == sid634 || decode_struct_id(v_c15) == sid635))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c192, v_c199, v_c200, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c16) && (decode_struct_id(v_c16) == sid633 || decode_struct_id(v_c16) == sid634 || decode_struct_id(v_c16) == sid635))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c192, v_c201, v_c202, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c15, v_c14, v_c13, v_c16, v_c20});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c13, v_c14, v_c15, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x1", _fires);
  
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
  // (crule (pre (let __trid6abe1461 const846f120b6b6ab883fe02a53a) (let __trel9cxE1462 const3a655602588fe6d8c59d4a5a) (let __tcol7za61463 const5feceb66ffc86f38d952786c) (let __trel6q1j1464 const3a655602588fe6d8c59d4a5a) (let __tcol83TO1465 const6b86b273ff34fce19d6b804e)) (scan $sup5638x68x0x0x0 __d0 k t v) (body) (head (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid6abe1461 __trel9cxE1462 __tcol7za61463 (1 2 3 4 0)) (tycheck k (accept int) __trid6abe1461 __trel6q1j1464 __tcol83TO1465 (1 2 3 4 0)) (mkstruct mp_has0 (1 2 0) __2pWM1460 t k)) map.slog:69 #f)
  class ReadTask640 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid638;  u32 sid637;  u32 sid639;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("$sup5638x68x0x0x0");
      sid638 = db->getRelation("_enum")->getStructId();
      sid637 = db->getRelation("mbranch")->getStructId();
      sid639 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask640(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c205 = v_const846f120b6b6ab883fe02a53a;
      u64 v_c206 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c207 = v_const5feceb66ffc86f38d952786c;
      u64 v_c208 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c209 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c98 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c80 = _t[2];
        u64 v_c21 = _t[3];
        ++_fires;
        if (!((is_struct(v_c80) && (decode_struct_id(v_c80) == sid637 || decode_struct_id(v_c80) == sid638 || decode_struct_id(v_c80) == sid639))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c205, v_c206, v_c207, v_c80}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c37)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c205, v_c208, v_c209, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c80, v_c37}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:$sup5638x68x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst9Vzm1192 constd01925b37634a1a9d24159d8) (let __t3rFt824 (lempty))) (scan program e) (body (join _enum (1 0) 1 __tconst9Vzm1192 __t32BX825)) (head (emit-temp temp13Gs2071 __t3rFt824 e)) interp.slog:133 #f)
  class ReadTask642 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex641;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp13Gs2071");
      outer_rel = db->getRelation("program");
      std::vector<u16> ord643({1, 0});
      slog::Relation* readrel644 = db->getRelation("_enum");
      _enumindex641 = readrel644->getIndex(ord643, false);
  
    }
    ReadTask642(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c210 = v_constd01925b37634a1a9d24159d8;
      u64 v_c211 = _prim_lempty(db);
      if (v_c211 == slog_error) { slog::emit_pending_error(db, "interp.slog:133"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c212 = _t[0];
        slog::join_probe<2,1>(_enumindex641, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m645) {
          u64 v_c213 = m645[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c211, v_c212});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:133", "delta:program", _fires);
  
      if (!_done)
      {
        ReadTask642* _cont = new ReadTask642(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask642(db,b), false);
  // (crule (pre) (scan delta_ans __t9Mk1341 v) (body (join-old delta (0 1 2) 1 (0 1 2) __t9Mk1341 op vs) (exists prim (1 0) 1 op) (join eval_args_ans (1 0) 1 vs __t24hv340) (join-old prim (1 0) 1 (1 0) op __t1N6L339) (join eval_ans (1 0) 1 __t1N6L339 __t8KmI338) (join-old eval (0 1 2 3) 1 (0 1 2 3) __t8KmI338 ef rho t) (exists $sup70016x75x0x0x0 (1 3 4 2 0) 3 ef rho t) (exists eval (2 3 0 1) 2 rho t) (exists app (1 2 0) 1 ef) (join-old eval_args (3 2 0 1) 3 (3 2 0 1) t rho __t24hv340 es) (exists app (1 2 0) 2 ef es) (join-old $sup70016x75x0x0x0 (1 3 4 2 0) 4 (1 3 4 2 0) ef rho t es __t8Dhb337) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t8Dhb337 __t87KU336) (join-old app (0 1 2) 3 (0 1 2) __t87KU336 ef es)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask667 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** deltaindex646;  slog::Index** primindex647;  slog::Index** eval_args_ansindex648;  slog::Index** primindex649;  slog::Index** eval_ansindex650;  slog::Index** evalindex651;  slog::Index** $sup70016x75x0x0x0index652;  slog::Index** evalindex653;  slog::Index** appindex654;  slog::Index** eval_argsindex655;  slog::Index** appindex656;  slog::Index** $sup70016x75x0x0x0index657;  slog::Index** evalindex658;  slog::Index** appindex659;  slog::Index** deltadelta660;  slog::Index** primdelta661;  slog::Index** evaldelta662;  slog::Index** eval_argsdelta663;  slog::Index** $sup70016x75x0x0x0delta664;  slog::Index** evaldelta665;  slog::Index** appdelta666;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord668({0, 1});
      slog::Relation* readrel669 = db->getRelation("eval_ans");
      head_index[0] = readrel669->getIndex(ord668, false);
      outer_rel = db->getRelation("delta_ans");
      std::vector<u16> ord670({0, 1, 2});
      slog::Relation* readrel671 = db->getRelation("delta");
      deltaindex646 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({0, 1, 2});
      slog::Relation* readrel673 = db->getRelation("delta");
      deltadelta660 = readrel673->getIndex(ord672, true);
      std::vector<u16> ord674({1, 0});
      slog::Relation* readrel675 = db->getRelation("prim");
      primindex647 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 0});
      slog::Relation* readrel677 = db->getRelation("eval_args_ans");
      eval_args_ansindex648 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({1, 0});
      slog::Relation* readrel679 = db->getRelation("prim");
      primindex649 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 0});
      slog::Relation* readrel681 = db->getRelation("prim");
      primdelta661 = readrel681->getIndex(ord680, true);
      std::vector<u16> ord682({1, 0});
      slog::Relation* readrel683 = db->getRelation("eval_ans");
      eval_ansindex650 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({0, 1, 2, 3});
      slog::Relation* readrel685 = db->getRelation("eval");
      evalindex651 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({0, 1, 2, 3});
      slog::Relation* readrel687 = db->getRelation("eval");
      evaldelta662 = readrel687->getIndex(ord686, true);
      std::vector<u16> ord688({1, 3, 4, 2, 0});
      slog::Relation* readrel689 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index652 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({2, 3, 0, 1});
      slog::Relation* readrel691 = db->getRelation("eval");
      evalindex653 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 0});
      slog::Relation* readrel693 = db->getRelation("app");
      appindex654 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({3, 2, 0, 1});
      slog::Relation* readrel695 = db->getRelation("eval_args");
      eval_argsindex655 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({3, 2, 0, 1});
      slog::Relation* readrel697 = db->getRelation("eval_args");
      eval_argsdelta663 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({1, 2, 0});
      slog::Relation* readrel699 = db->getRelation("app");
      appindex656 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 3, 4, 2, 0});
      slog::Relation* readrel701 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index657 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 3, 4, 2, 0});
      slog::Relation* readrel703 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0delta664 = readrel703->getIndex(ord702, true);
      std::vector<u16> ord704({2, 3, 0, 1});
      slog::Relation* readrel705 = db->getRelation("eval");
      evalindex658 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({2, 3, 0, 1});
      slog::Relation* readrel707 = db->getRelation("eval");
      evaldelta665 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({0, 1, 2});
      slog::Relation* readrel709 = db->getRelation("app");
      appindex659 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({0, 1, 2});
      slog::Relation* readrel711 = db->getRelation("app");
      appdelta666 = readrel711->getIndex(ord710, true);
  
    }
    ReadTask667(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c214 = _t[0];
        u64 v_c21 = _t[1];
        slog::join_probe_old<3,1>(deltaindex646, deltadelta660, std::array<u64,3>{v_c214, 0, 0}, [&](const std::array<u64,3>& m712) {
          u64 v_c50 = m712[1]; u64 v_c160 = m712[2];
          if (!slog::exists_probe<2,1>(primindex647, std::array<u64,2>{v_c50, 0})) return;
          slog::join_probe<2,1>(eval_args_ansindex648, std::array<u64,2>{v_c160, 0}, [&](const std::array<u64,2>& m713) {
            u64 v_c215 = m713[1];
            slog::join_probe_old<2,1>(primindex649, primdelta661, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m714) {
              u64 v_c216 = m714[1];
              slog::join_probe<2,1>(eval_ansindex650, std::array<u64,2>{v_c216, 0}, [&](const std::array<u64,2>& m715) {
                u64 v_c217 = m715[1];
                slog::join_probe_old<4,1>(evalindex651, evaldelta662, std::array<u64,4>{v_c217, 0, 0, 0}, [&](const std::array<u64,4>& m716) {
                  u64 v_c174 = m716[1]; u64 v_c79 = m716[2]; u64 v_c80 = m716[3];
                  if (!slog::exists_probe<5,3>($sup70016x75x0x0x0index652, std::array<u64,5>{v_c174, v_c79, v_c80, 0, 0})) return;
                  if (!slog::exists_probe<4,2>(evalindex653, std::array<u64,4>{v_c79, v_c80, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(appindex654, std::array<u64,3>{v_c174, 0, 0})) return;
                  slog::join_probe_old<4,3>(eval_argsindex655, eval_argsdelta663, std::array<u64,4>{v_c80, v_c79, v_c215, 0}, [&](const std::array<u64,4>& m717) {
                    u64 v_c175 = m717[3];
                    if (!slog::exists_probe<3,2>(appindex656, std::array<u64,3>{v_c174, v_c175, 0})) return;
                    slog::join_probe_old<5,4>($sup70016x75x0x0x0index657, $sup70016x75x0x0x0delta664, std::array<u64,5>{v_c174, v_c79, v_c80, v_c175, 0}, [&](const std::array<u64,5>& m718) {
                      u64 v_c218 = m718[4];
                      slog::join_probe_old<4,3>(evalindex658, evaldelta665, std::array<u64,4>{v_c79, v_c80, v_c218, 0}, [&](const std::array<u64,4>& m719) {
                        u64 v_c219 = m719[3];
                        slog::join_probe_old<3,3>(appindex659, appdelta666, std::array<u64,3>{v_c219, v_c174, v_c175}, [&](const std::array<u64,3>& m720) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c218, v_c21}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:delta_ans", _fires);
  
      if (!_done)
      {
        ReadTask667* _cont = new ReadTask667(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask667(db,b), false);
  // (crule (pre) (scan temp05ov2047 l n q u v) (body (join mbranch (1 2 3 4 0) 4 q n u v __t5MWB602)) (head (mkstruct mp_union (1 2 0) __5pFz1108 l __t5MWB602)) map.slog:96 #f)
  class ReadTask722 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex721;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("temp05ov2047");
      std::vector<u16> ord723({1, 2, 3, 4, 0});
      slog::Relation* readrel724 = db->getRelation("mbranch");
      mbranchindex721 = readrel724->getIndex(ord723, false);
  
    }
    ReadTask722(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c204 = _t[1];
        u64 v_c19 = _t[2];
        u64 v_c20 = _t[3];
        u64 v_c21 = _t[4];
        slog::join_probe<5,4>(mbranchindex721, std::array<u64,5>{v_c19, v_c204, v_c20, v_c21, 0}, [&](const std::array<u64,5>& m725) {
          u64 v_c220 = m725[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c220}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:temp05ov2047", _fires);
  
      if (!_done)
      {
        ReadTask722* _cont = new ReadTask722(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask722(db,b), false);
  // (crule (pre (let __tconst85Gw1131 constb9e118781cea1f9fa01462e0) (let __tconst3nKQ305 const06abaa100ecef791ce028c56) (let _00024sqc19MG1022 constd4735e3a265e16eee03f5971) (let _00024sqc5y4j1023 const5feceb66ffc86f38d952786c) (let _00024sqc09of1024 const6b86b273ff34fce19d6b804e) (let _00024sqo41XW1025 const5feceb66ffc86f38d952786c) (let _00024sqo2TL91026 const6b86b273ff34fce19d6b804e) (let _00024sqo4lhI1027 const6b86b273ff34fce19d6b804e) (let _00024sqo7qxI1028 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst3nKQ305 _00024seq0 __t44yZ306) (body (letp _00024sql8r1X1020 (aslst _00024seq0)) (letp v1 (lref _00024sql8r1X1020 _00024sqc5y4j1023)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo41XW1025 v1 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4lhI1027 v1 _00024seq0) (letp v2 (lref _00024sql8r1X1020 _00024sqc09of1024)) (neq v1 v2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2TL91026 v2 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7qxI1028 v2 _00024seq0) (join _enum (1 0) 1 __tconst85Gw1131 __t4QRG303) (let chk8Jyb2053 (llen _00024sql8r1X1020)) (eq _00024sqc19MG1022 chk8Jyb2053)) (head (emit-temp temp2zCq2052 __t44yZ306) (mkstruct boolval (1 0) __t6gLd304 __t4QRG303)) interp.slog:124 #f)
  class ReadTask735 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex726;  slog::Index** $seq_atrindex727;  slog::Index** $seq_atindex728;  slog::Index** $seq_atrindex729;  slog::Index** _enumindex730;  slog::Index** $seq_atdelta731;  slog::Index** $seq_atrdelta732;  slog::Index** $seq_atdelta733;  slog::Index** $seq_atrdelta734;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2zCq2052");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord736({1, 2, 0});
      slog::Relation* readrel737 = db->getRelation("delta");
      driver_index = readrel737->getIndex(ord736, true);
      std::vector<u16> ord738({1, 0, 2});
      slog::Relation* readrel739 = db->getRelation("$seq_at");
      $seq_atindex726 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({1, 0, 2});
      slog::Relation* readrel741 = db->getRelation("$seq_at");
      $seq_atdelta731 = readrel741->getIndex(ord740, true);
      std::vector<u16> ord742({1, 0, 2});
      slog::Relation* readrel743 = db->getRelation("$seq_atr");
      $seq_atrindex727 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({1, 0, 2});
      slog::Relation* readrel745 = db->getRelation("$seq_atr");
      $seq_atrdelta732 = readrel745->getIndex(ord744, true);
      std::vector<u16> ord746({1, 0, 2});
      slog::Relation* readrel747 = db->getRelation("$seq_at");
      $seq_atindex728 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 0, 2});
      slog::Relation* readrel749 = db->getRelation("$seq_at");
      $seq_atdelta733 = readrel749->getIndex(ord748, true);
      std::vector<u16> ord750({1, 0, 2});
      slog::Relation* readrel751 = db->getRelation("$seq_atr");
      $seq_atrindex729 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 0, 2});
      slog::Relation* readrel753 = db->getRelation("$seq_atr");
      $seq_atrdelta734 = readrel753->getIndex(ord752, true);
      std::vector<u16> ord754({1, 0});
      slog::Relation* readrel755 = db->getRelation("_enum");
      _enumindex730 = readrel755->getIndex(ord754, false);
  
    }
    ReadTask735(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c120 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c121 = v_const06abaa100ecef791ce028c56;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const5feceb66ffc86f38d952786c;
      u64 v_c124 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c125 = v_const5feceb66ffc86f38d952786c;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c121, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m756) {
        u64 v_c30 = m756[1];
        u64 v_c132 = m756[2];
        if (buckethash(v_c30) != bucket) return;
        bool ok757 = true;
        u64 v_c130 = _prim_aslst(db, v_c30, &ok757);
        if (!ok757) return;
        bool ok758 = true;
        u64 v_c131 = _prim_lref(db, v_c130, v_c123, &ok758);
        if (!ok758) return;
        slog::join_probe_old<3,3>($seq_atindex726, $seq_atdelta731, std::array<u64,3>{v_c125, v_c131, v_c30}, [&](const std::array<u64,3>& m759) {
          slog::join_probe_old<3,3>($seq_atrindex727, $seq_atrdelta732, std::array<u64,3>{v_c127, v_c131, v_c30}, [&](const std::array<u64,3>& m760) {
            bool ok761 = true;
            u64 v_c129 = _prim_lref(db, v_c130, v_c124, &ok761);
            if (!ok761) return;
            if (v_c131 == v_c129) return;
            slog::join_probe_old<3,3>($seq_atindex728, $seq_atdelta733, std::array<u64,3>{v_c126, v_c129, v_c30}, [&](const std::array<u64,3>& m762) {
              slog::join_probe_old<3,3>($seq_atrindex729, $seq_atrdelta734, std::array<u64,3>{v_c128, v_c129, v_c30}, [&](const std::array<u64,3>& m763) {
                slog::join_probe<2,1>(_enumindex730, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m764) {
                  u64 v_c133 = m764[1];
                  u64 v_c221 = _prim_llen(db, v_c130);
                  if (v_c221 == slog_error) { slog::emit_pending_error(db, "interp.slog:124"); return; }
                  if (v_c122 != v_c221) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c132});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c133}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:124", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask735* _cont = new ReadTask735(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask735(db,b), false);
  // (crule (pre) (scan eval __t2MYH648 e1 rho t) (body (exists if (1 3 2 0) 1 e1) (exists eval (2 3 0 1) 2 rho t) (exists eval_ans (0 1) 1 __t2MYH648) (join $sup70016x87x0x0x0 (1 4 5 0 2 3) 3 e1 rho t __t7kdB647 e2 e3) (exists eval (2 3 0 1) 3 rho t __t7kdB647) (exists select_branch (2 3 1 0) 2 e2 e3) (join if (1 3 2 0) 3 e1 e3 e2 __t71xd646) (join eval (2 3 0 1) 4 rho t __t7kdB647 __t71xd646) (join-old select_branch (2 3 1 0) 2 (2 3 1 0) e2 e3 __v0 __t1Vli649) (join eval_ans (0 1) 2 __t2MYH648 __v0) (exists select_branch_ans (0 1) 1 __t1Vli649) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t4Rxn650 __v1) (join select_branch_ans (0 1) 2 __t1Vli649 __v1) (join eval_ans (0 1) 1 __t4Rxn650 __v2)) (head (emit eval_ans (0 1) __t7kdB647 __v2)) interp.slog:88 #f)
  class ReadTask781 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ifindex765;  slog::Index** evalindex766;  slog::Index** eval_ansindex767;  slog::Index** $sup70016x87x0x0x0index768;  slog::Index** evalindex769;  slog::Index** select_branchindex770;  slog::Index** ifindex771;  slog::Index** evalindex772;  slog::Index** select_branchindex773;  slog::Index** eval_ansindex774;  slog::Index** select_branch_ansindex775;  slog::Index** evalindex776;  slog::Index** select_branch_ansindex777;  slog::Index** eval_ansindex778;  slog::Index** select_branchdelta779;  slog::Index** evaldelta780;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord782({0, 1});
      slog::Relation* readrel783 = db->getRelation("eval_ans");
      head_index[0] = readrel783->getIndex(ord782, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord784({1, 3, 2, 0});
      slog::Relation* readrel785 = db->getRelation("if");
      ifindex765 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({2, 3, 0, 1});
      slog::Relation* readrel787 = db->getRelation("eval");
      evalindex766 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({0, 1});
      slog::Relation* readrel789 = db->getRelation("eval_ans");
      eval_ansindex767 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 4, 5, 0, 2, 3});
      slog::Relation* readrel791 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index768 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({2, 3, 0, 1});
      slog::Relation* readrel793 = db->getRelation("eval");
      evalindex769 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({2, 3, 1, 0});
      slog::Relation* readrel795 = db->getRelation("select_branch");
      select_branchindex770 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 3, 2, 0});
      slog::Relation* readrel797 = db->getRelation("if");
      ifindex771 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({2, 3, 0, 1});
      slog::Relation* readrel799 = db->getRelation("eval");
      evalindex772 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({2, 3, 1, 0});
      slog::Relation* readrel801 = db->getRelation("select_branch");
      select_branchindex773 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({2, 3, 1, 0});
      slog::Relation* readrel803 = db->getRelation("select_branch");
      select_branchdelta779 = readrel803->getIndex(ord802, true);
      std::vector<u16> ord804({0, 1});
      slog::Relation* readrel805 = db->getRelation("eval_ans");
      eval_ansindex774 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({0, 1});
      slog::Relation* readrel807 = db->getRelation("select_branch_ans");
      select_branch_ansindex775 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({2, 3, 0, 1});
      slog::Relation* readrel809 = db->getRelation("eval");
      evalindex776 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({2, 3, 0, 1});
      slog::Relation* readrel811 = db->getRelation("eval");
      evaldelta780 = readrel811->getIndex(ord810, true);
      std::vector<u16> ord812({0, 1});
      slog::Relation* readrel813 = db->getRelation("select_branch_ans");
      select_branch_ansindex777 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({0, 1});
      slog::Relation* readrel815 = db->getRelation("eval_ans");
      eval_ansindex778 = readrel815->getIndex(ord814, false);
  
    }
    ReadTask781(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c83 = _t[1];
        u64 v_c79 = _t[2];
        u64 v_c80 = _t[3];
        if (!slog::exists_probe<4,1>(ifindex765, std::array<u64,4>{v_c83, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex766, std::array<u64,4>{v_c79, v_c80, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex767, std::array<u64,2>{v_c86, 0})) return;
        slog::join_probe<6,3>($sup70016x87x0x0x0index768, std::array<u64,6>{v_c83, v_c79, v_c80, 0, 0, 0}, [&](const std::array<u64,6>& m816) {
          u64 v_c81 = m816[3]; u64 v_c84 = m816[4]; u64 v_c85 = m816[5];
          if (!slog::exists_probe<4,3>(evalindex769, std::array<u64,4>{v_c79, v_c80, v_c81, 0})) return;
          if (!slog::exists_probe<4,2>(select_branchindex770, std::array<u64,4>{v_c84, v_c85, 0, 0})) return;
          slog::join_probe<4,3>(ifindex771, std::array<u64,4>{v_c83, v_c85, v_c84, 0}, [&](const std::array<u64,4>& m817) {
            u64 v_c82 = m817[3];
            slog::join_probe<4,4>(evalindex772, std::array<u64,4>{v_c79, v_c80, v_c81, v_c82}, [&](const std::array<u64,4>& m818) {
              slog::join_probe_old<4,2>(select_branchindex773, select_branchdelta779, std::array<u64,4>{v_c84, v_c85, 0, 0}, [&](const std::array<u64,4>& m819) {
                u64 v_c66 = m819[2]; u64 v_c87 = m819[3];
                slog::join_probe<2,2>(eval_ansindex774, std::array<u64,2>{v_c86, v_c66}, [&](const std::array<u64,2>& m820) {
                  if (!slog::exists_probe<2,1>(select_branch_ansindex775, std::array<u64,2>{v_c87, 0})) return;
                  slog::join_probe_old<4,2>(evalindex776, evaldelta780, std::array<u64,4>{v_c79, v_c80, 0, 0}, [&](const std::array<u64,4>& m821) {
                    u64 v_c77 = m821[2]; u64 v_c78 = m821[3];
                    slog::join_probe<2,2>(select_branch_ansindex777, std::array<u64,2>{v_c87, v_c78}, [&](const std::array<u64,2>& m822) {
                      slog::join_probe<2,1>(eval_ansindex778, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m823) {
                        u64 v_c88 = m823[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c81, v_c88}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval", _fires);
  
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
  // (crule (pre (let __tconst2b6r460 const5feceb66ffc86f38d952786c)) (scan mp_put __t9vSj463 r k v) (body (exists $sup5638x42x0x0x1 (2 6 7 0 1 3 4 5) 3 k r v) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_put (2 3 0 1) 2 k v) (exists mp_msk (1 2 0) 1 k) (exists mp_put_ans (0 1) 1 __t9vSj463) (join $sup5638x42x0x0x0 (1 5 6 0 2 3 4) 3 k r v __t6Bbs459 l m p) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (3 0 2 1) 3 v __t6Bbs459 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t6Bbs459 k v __t5aM3462) (exists mp_msk (1 2 0) 3 k m __t5aM3462) (exists mp_msk_ans (0 1) 2 __t5aM3462 p) (join mbranch (1 2 3 4 0) 4 p m l r __t9ixF458) (join mp_put (0 2 1 3) 4 __t6Bbs459 k __t9ixF458 v) (join mp_msk (1 2 0) 3 k m __t5aM3462) (join mp_msk_ans (0 1) 2 __t5aM3462 p) (join mp_put_ans (0 1) 1 __t9vSj463 __v0) (let __t1jZ6461 (band k m)) (cmp gt __t1jZ6461 __tconst2b6r460)) (head (emit-temp temp7Xjy1975 __t6Bbs459 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t8oL5457 p m l __v0)) map.slog:43 #f)
  class ReadTask842 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x1index824;  slog::Index** mbranchindex825;  slog::Index** mp_putindex826;  slog::Index** mp_mskindex827;  slog::Index** mp_put_ansindex828;  slog::Index** $sup5638x42x0x0x0index829;  slog::Index** mbranchindex830;  slog::Index** mp_putindex831;  slog::Index** mp_mskindex832;  slog::Index** mp_msk_ansindex833;  slog::Index** $sup5638x42x0x0x1index834;  slog::Index** mp_mskindex835;  slog::Index** mp_msk_ansindex836;  slog::Index** mbranchindex837;  slog::Index** mp_putindex838;  slog::Index** mp_mskindex839;  slog::Index** mp_msk_ansindex840;  slog::Index** mp_put_ansindex841;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Xjy1975");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord843({2, 6, 7, 0, 1, 3, 4, 5});
      slog::Relation* readrel844 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index824 = readrel844->getIndex(ord843, false);
      std::vector<u16> ord845({4, 0, 1, 2, 3});
      slog::Relation* readrel846 = db->getRelation("mbranch");
      mbranchindex825 = readrel846->getIndex(ord845, false);
      std::vector<u16> ord847({2, 3, 0, 1});
      slog::Relation* readrel848 = db->getRelation("mp_put");
      mp_putindex826 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({1, 2, 0});
      slog::Relation* readrel850 = db->getRelation("mp_msk");
      mp_mskindex827 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({0, 1});
      slog::Relation* readrel852 = db->getRelation("mp_put_ans");
      mp_put_ansindex828 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 5, 6, 0, 2, 3, 4});
      slog::Relation* readrel854 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index829 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 2, 3, 4, 0});
      slog::Relation* readrel856 = db->getRelation("mbranch");
      mbranchindex830 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({3, 0, 2, 1});
      slog::Relation* readrel858 = db->getRelation("mp_put");
      mp_putindex831 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 2, 0});
      slog::Relation* readrel860 = db->getRelation("mp_msk");
      mp_mskindex832 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 0});
      slog::Relation* readrel862 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex833 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel864 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index834 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({1, 2, 0});
      slog::Relation* readrel866 = db->getRelation("mp_msk");
      mp_mskindex835 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({0, 1});
      slog::Relation* readrel868 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex836 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({1, 2, 3, 4, 0});
      slog::Relation* readrel870 = db->getRelation("mbranch");
      mbranchindex837 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({0, 2, 1, 3});
      slog::Relation* readrel872 = db->getRelation("mp_put");
      mp_putindex838 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 2, 0});
      slog::Relation* readrel874 = db->getRelation("mp_msk");
      mp_mskindex839 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({0, 1});
      slog::Relation* readrel876 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex840 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({0, 1});
      slog::Relation* readrel878 = db->getRelation("mp_put_ans");
      mp_put_ansindex841 = readrel878->getIndex(ord877, false);
  
    }
    ReadTask842(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c222 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c16 = _t[1];
        u64 v_c37 = _t[2];
        u64 v_c21 = _t[3];
        if (!slog::exists_probe<8,3>($sup5638x42x0x0x1index824, std::array<u64,8>{v_c37, v_c16, v_c21, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex825, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex826, std::array<u64,4>{v_c37, v_c21, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex827, std::array<u64,3>{v_c37, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex828, std::array<u64,2>{v_c223, 0})) return;
        slog::join_probe<7,3>($sup5638x42x0x0x0index829, std::array<u64,7>{v_c37, v_c16, v_c21, 0, 0, 0, 0}, [&](const std::array<u64,7>& m879) {
          u64 v_c224 = m879[3]; u64 v_c15 = m879[4]; u64 v_c14 = m879[5]; u64 v_c13 = m879[6];
          if (!slog::exists_probe<5,4>(mbranchindex830, std::array<u64,5>{v_c13, v_c14, v_c15, v_c16, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex831, std::array<u64,4>{v_c21, v_c224, v_c37, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex832, std::array<u64,3>{v_c37, v_c14, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex833, std::array<u64,2>{v_c13, 0})) return;
          slog::join_probe<8,7>($sup5638x42x0x0x1index834, std::array<u64,8>{v_c15, v_c14, v_c13, v_c16, v_c224, v_c37, v_c21, 0}, [&](const std::array<u64,8>& m880) {
            u64 v_c225 = m880[7];
            if (!slog::exists_probe<3,3>(mp_mskindex835, std::array<u64,3>{v_c37, v_c14, v_c225})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex836, std::array<u64,2>{v_c225, v_c13})) return;
            slog::join_probe<5,4>(mbranchindex837, std::array<u64,5>{v_c13, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,5>& m881) {
              u64 v_c226 = m881[4];
              slog::join_probe<4,4>(mp_putindex838, std::array<u64,4>{v_c224, v_c37, v_c226, v_c21}, [&](const std::array<u64,4>& m882) {
                slog::join_probe<3,3>(mp_mskindex839, std::array<u64,3>{v_c37, v_c14, v_c225}, [&](const std::array<u64,3>& m883) {
                  slog::join_probe<2,2>(mp_msk_ansindex840, std::array<u64,2>{v_c225, v_c13}, [&](const std::array<u64,2>& m884) {
                    slog::join_probe<2,1>(mp_put_ansindex841, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m885) {
                      u64 v_c66 = m885[1];
                      u64 v_c227 = _prim_band(db, v_c37, v_c14);
                      if (v_c227 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c228 = _prim_gt(db, v_c227, v_c222);
                      if (v_c228 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c228) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c224, v_c66, v_c15, v_c14, v_c13});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c13, v_c14, v_c15, v_c66}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask842* _cont = new ReadTask842(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask842(db,b), false);
  // (crule (pre) (scan select_branch __t4JBz631 __v0 e2 e3) (body (exists select_branch_ans (0 1) 1 __t4JBz631) (exists $sup70016x87x0x0x0 (2 3 1 0 4 5) 2 e2 e3) (join eval_ans (1 0) 1 __v0 __t5mTH630) (join select_branch_ans (0 1) 1 __t4JBz631 __v1) (join $sup70016x87x0x0x0 (2 3 1 0 4 5) 2 e2 e3 e1 __d0 rho t) (join eval (2 3 0 1) 4 rho t __t5mTH630 e1)) (head (mkstruct eval (1 2 3 0) __226z1519 __v1 rho t)) interp.slog:88 #f)
  class ReadTask893 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branch_ansindex887;  slog::Index** $sup70016x87x0x0x0index888;  slog::Index** eval_ansindex889;  slog::Index** select_branch_ansindex890;  slog::Index** $sup70016x87x0x0x0index891;  slog::Index** evalindex892;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord894({0, 1});
      slog::Relation* readrel895 = db->getRelation("select_branch_ans");
      select_branch_ansindex887 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel897 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index888 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({1, 0});
      slog::Relation* readrel899 = db->getRelation("eval_ans");
      eval_ansindex889 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({0, 1});
      slog::Relation* readrel901 = db->getRelation("select_branch_ans");
      select_branch_ansindex890 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel903 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index891 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({2, 3, 0, 1});
      slog::Relation* readrel905 = db->getRelation("eval");
      evalindex892 = readrel905->getIndex(ord904, false);
  
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
        u64 v_c229 = _t[0];
        u64 v_c66 = _t[1];
        u64 v_c84 = _t[2];
        u64 v_c85 = _t[3];
        if (!slog::exists_probe<2,1>(select_branch_ansindex887, std::array<u64,2>{v_c229, 0})) return;
        if (!slog::exists_probe<6,2>($sup70016x87x0x0x0index888, std::array<u64,6>{v_c84, v_c85, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex889, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m906) {
          u64 v_c230 = m906[1];
          slog::join_probe<2,1>(select_branch_ansindex890, std::array<u64,2>{v_c229, 0}, [&](const std::array<u64,2>& m907) {
            u64 v_c78 = m907[1];
            slog::join_probe<6,2>($sup70016x87x0x0x0index891, std::array<u64,6>{v_c84, v_c85, 0, 0, 0, 0}, [&](const std::array<u64,6>& m908) {
              u64 v_c83 = m908[2]; u64 v_c98 = m908[3]; u64 v_c79 = m908[4]; u64 v_c80 = m908[5];
              slog::join_probe<4,4>(evalindex892, std::array<u64,4>{v_c79, v_c80, v_c230, v_c83}, [&](const std::array<u64,4>& m909) {
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c78, v_c79, v_c80}, std::array<u16,4>{1, 2, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:select_branch", _fires);
  
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
  // (crule (pre (let __tconst9P2l620 const6b86b273ff34fce19d6b804e)) (scan mbranch __t9QVv618 p m l r) (body (join-old mp_has0 (1 2 0) 1 (1 2 0) __t9QVv618 k __t645L619) (let __t9jb4621 (band k m)) (cmp lt __t9jb4621 __tconst9P2l620)) (head (emit $sup5638x60x0x0x0 (4 2 3 5 0 1) p l m r __t645L619 k)) map.slog:61 #f)
  class ReadTask912 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index910;  slog::Index** mp_has0delta911;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord913({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel914 = db->getRelation("$sup5638x60x0x0x0");
      head_index[0] = readrel914->getIndex(ord913, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord915({1, 2, 0});
      slog::Relation* readrel916 = db->getRelation("mp_has0");
      mp_has0index910 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({1, 2, 0});
      slog::Relation* readrel918 = db->getRelation("mp_has0");
      mp_has0delta911 = readrel918->getIndex(ord917, true);
  
    }
    ReadTask912(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c231 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c232 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c16 = _t[4];
        slog::join_probe_old<3,1>(mp_has0index910, mp_has0delta911, std::array<u64,3>{v_c232, 0, 0}, [&](const std::array<u64,3>& m919) {
          u64 v_c37 = m919[1]; u64 v_c233 = m919[2];
          u64 v_c234 = _prim_band(db, v_c37, v_c14);
          if (v_c234 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
          u64 v_c235 = _prim_lt(db, v_c234, v_c231);
          if (v_c235 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
          if (!v_c235) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c13, v_c15, v_c14, v_c16, v_c233, v_c37}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask912* _cont = new ReadTask912(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask912(db,b), false);
  // (crule (pre) (scan int_overflow __erre5D7U1752 __errf7my71753 __errf73ml1754 __errf9EoL1755) (body) (head (emit error (0) __erre5D7U1752)) <internal>:1 #f)
  class ReadTask921 : public slog::Task
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
      std::vector<u16> ord922({0});
      slog::Relation* readrel923 = db->getRelation("error");
      head_index[0] = readrel923->getIndex(ord922, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask921(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c238 = _t[2];
        u64 v_c239 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c236}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask921* _cont = new ReadTask921(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask921(db,b), false);
  // (crule (pre (let __tconst85Gw1131 constb9e118781cea1f9fa01462e0) (let __tconst3nKQ305 const06abaa100ecef791ce028c56) (let _00024sqc19MG1022 constd4735e3a265e16eee03f5971) (let _00024sqc5y4j1023 const5feceb66ffc86f38d952786c) (let _00024sqc09of1024 const6b86b273ff34fce19d6b804e) (let _00024sqo41XW1025 const5feceb66ffc86f38d952786c) (let _00024sqo2TL91026 const6b86b273ff34fce19d6b804e) (let _00024sqo4lhI1027 const6b86b273ff34fce19d6b804e) (let _00024sqo7qxI1028 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo2TL91026 v2 _00024seq0) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7qxI1028 v2 _00024seq0) (letp _00024sql8r1X1020 (aslst _00024seq0)) (letp v1 (lref _00024sql8r1X1020 _00024sqc5y4j1023)) (neq v1 v2) (join $seq_at (1 0 2) 3 _00024sqo41XW1025 v1 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4lhI1027 v1 _00024seq0) (exists _enum (1 0) 1 __tconst85Gw1131) (join delta (1 2 0) 2 __tconst3nKQ305 _00024seq0 __t44yZ306) (join _enum (1 0) 1 __tconst85Gw1131 __t4QRG303) (let chk8DKw2056 (llen _00024sql8r1X1020)) (eq _00024sqc19MG1022 chk8DKw2056) (letp chk8pmB2057 (lref _00024sql8r1X1020 _00024sqc09of1024)) (eq v2 chk8pmB2057)) (head (emit-temp temp2zCq2052 __t44yZ306) (mkstruct boolval (1 0) __t6gLd304 __t4QRG303)) interp.slog:124 #f)
  class ReadTask932 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex924;  slog::Index** $seq_atindex925;  slog::Index** $seq_atrindex926;  slog::Index** _enumindex927;  slog::Index** deltaindex928;  slog::Index** _enumindex929;  slog::Index** $seq_atrdelta930;  slog::Index** $seq_atrdelta931;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2zCq2052");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord933({1, 0, 2});
      slog::Relation* readrel934 = db->getRelation("$seq_at");
      driver_index = readrel934->getIndex(ord933, true);
      std::vector<u16> ord935({1, 0, 2});
      slog::Relation* readrel936 = db->getRelation("$seq_atr");
      $seq_atrindex924 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({1, 0, 2});
      slog::Relation* readrel938 = db->getRelation("$seq_atr");
      $seq_atrdelta930 = readrel938->getIndex(ord937, true);
      std::vector<u16> ord939({1, 0, 2});
      slog::Relation* readrel940 = db->getRelation("$seq_at");
      $seq_atindex925 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({1, 0, 2});
      slog::Relation* readrel942 = db->getRelation("$seq_atr");
      $seq_atrindex926 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 0, 2});
      slog::Relation* readrel944 = db->getRelation("$seq_atr");
      $seq_atrdelta931 = readrel944->getIndex(ord943, true);
      std::vector<u16> ord945({1, 0});
      slog::Relation* readrel946 = db->getRelation("_enum");
      _enumindex927 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 0});
      slog::Relation* readrel948 = db->getRelation("delta");
      deltaindex928 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 0});
      slog::Relation* readrel950 = db->getRelation("_enum");
      _enumindex929 = readrel950->getIndex(ord949, false);
  
    }
    ReadTask932(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c120 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c121 = v_const06abaa100ecef791ce028c56;
      u64 v_c122 = v_constd4735e3a265e16eee03f5971;
      u64 v_c123 = v_const5feceb66ffc86f38d952786c;
      u64 v_c124 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c125 = v_const5feceb66ffc86f38d952786c;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c126, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m951) {
        u64 v_c129 = m951[1];
        u64 v_c30 = m951[2];
        if (buckethash(v_c129) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex924, $seq_atrdelta930, std::array<u64,3>{v_c128, v_c129, v_c30}, [&](const std::array<u64,3>& m952) {
          bool ok953 = true;
          u64 v_c130 = _prim_aslst(db, v_c30, &ok953);
          if (!ok953) return;
          bool ok954 = true;
          u64 v_c131 = _prim_lref(db, v_c130, v_c123, &ok954);
          if (!ok954) return;
          if (v_c131 == v_c129) return;
          slog::join_probe<3,3>($seq_atindex925, std::array<u64,3>{v_c125, v_c131, v_c30}, [&](const std::array<u64,3>& m955) {
            slog::join_probe_old<3,3>($seq_atrindex926, $seq_atrdelta931, std::array<u64,3>{v_c127, v_c131, v_c30}, [&](const std::array<u64,3>& m956) {
              if (!slog::exists_probe<2,1>(_enumindex927, std::array<u64,2>{v_c120, 0})) return;
              slog::join_probe<3,2>(deltaindex928, std::array<u64,3>{v_c121, v_c30, 0}, [&](const std::array<u64,3>& m957) {
                u64 v_c132 = m957[2];
                slog::join_probe<2,1>(_enumindex929, std::array<u64,2>{v_c120, 0}, [&](const std::array<u64,2>& m958) {
                  u64 v_c133 = m958[1];
                  u64 v_c240 = _prim_llen(db, v_c130);
                  if (v_c240 == slog_error) { slog::emit_pending_error(db, "interp.slog:124"); return; }
                  if (v_c122 != v_c240) return;
                  bool ok959 = true;
                  u64 v_c241 = _prim_lref(db, v_c130, v_c124, &ok959);
                  if (!ok959) return;
                  if (v_c129 != v_c241) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c132});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c133}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:124", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask932* _cont = new ReadTask932(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask932(db,b), false);
  // (crule (pre (let __trid5Kc01079 const3b5b774db59f55c2fdaef73a) (let __trel1d9a1080 const3a655602588fe6d8c59d4a5a) (let __tcol3HSJ1081 const5feceb66ffc86f38d952786c) (let __trel4G5u1082 const3a655602588fe6d8c59d4a5a) (let __tcol1U2O1083 const6b86b273ff34fce19d6b804e)) (scan $sup5638x62x0x0x0 __d0 k l m p r) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid5Kc01079 __trel1d9a1080 __tcol3HSJ1081 (1 2 3 4 0)) (tycheck k (accept int) __trid5Kc01079 __trel4G5u1082 __tcol1U2O1083 (1 2 3 4 0)) (mkstruct mp_has0 (1 2 0) __9dq71078 r k)) map.slog:63 #f)
  class ReadTask963 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid961;  u32 sid960;  u32 sid962;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_has0");
      outer_rel = db->getRelation("$sup5638x62x0x0x0");
      sid961 = db->getRelation("_enum")->getStructId();
      sid960 = db->getRelation("mbranch")->getStructId();
      sid962 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask963(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c242 = v_const3b5b774db59f55c2fdaef73a;
      u64 v_c243 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c244 = v_const5feceb66ffc86f38d952786c;
      u64 v_c245 = v_const3a655602588fe6d8c59d4a5a;
      u64 v_c246 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c98 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c15 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c16 = _t[5];
        ++_fires;
        if (!((is_struct(v_c16) && (decode_struct_id(v_c16) == sid960 || decode_struct_id(v_c16) == sid961 || decode_struct_id(v_c16) == sid962))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c242, v_c243, v_c244, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c37)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c242, v_c245, v_c246, v_c37}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c16, v_c37}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:$sup5638x62x0x0x0", _fires);
  
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
  // (crule (pre) (scan eval_ans __t7uXV815 vr) (body (join-old eval (0 1 2 3) 1 (0 1 2 3) __t7uXV815 er rho t) (exists mp_put (1 3 0 2) 2 rho t) (join $sup70016x92x0x0x0 (2 3 4 0 1 5) 3 er rho t __d0 eb x) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t3Rle816) (join-old mp_put_ans (0 1) 1 (0 1) __t3Rle816 __v0)) (head (emit $sup70016x92x0x0x1 (1 8 0 2 3 4 5 6 7 9) __t7uXV815 vr __d0 __t3Rle816 __v0 eb er rho t x)) interp.slog:93 #f)
  class ReadTask972 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex964;  slog::Index** mp_putindex965;  slog::Index** $sup70016x92x0x0x0index966;  slog::Index** mp_putindex967;  slog::Index** mp_put_ansindex968;  slog::Index** evaldelta969;  slog::Index** mp_putdelta970;  slog::Index** mp_put_ansdelta971;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x92x0x0x1");
      std::vector<u16> ord973({1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel974 = db->getRelation("$sup70016x92x0x0x1");
      head_index[0] = readrel974->getIndex(ord973, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord975({0, 1, 2, 3});
      slog::Relation* readrel976 = db->getRelation("eval");
      evalindex964 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({0, 1, 2, 3});
      slog::Relation* readrel978 = db->getRelation("eval");
      evaldelta969 = readrel978->getIndex(ord977, true);
      std::vector<u16> ord979({1, 3, 0, 2});
      slog::Relation* readrel980 = db->getRelation("mp_put");
      mp_putindex965 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({2, 3, 4, 0, 1, 5});
      slog::Relation* readrel982 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index966 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({1, 2, 3, 0});
      slog::Relation* readrel984 = db->getRelation("mp_put");
      mp_putindex967 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({1, 2, 3, 0});
      slog::Relation* readrel986 = db->getRelation("mp_put");
      mp_putdelta970 = readrel986->getIndex(ord985, true);
      std::vector<u16> ord987({0, 1});
      slog::Relation* readrel988 = db->getRelation("mp_put_ans");
      mp_put_ansindex968 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({0, 1});
      slog::Relation* readrel990 = db->getRelation("mp_put_ans");
      mp_put_ansdelta971 = readrel990->getIndex(ord989, true);
  
    }
    ReadTask972(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c247 = _t[0];
        u64 v_c248 = _t[1];
        slog::join_probe_old<4,1>(evalindex964, evaldelta969, std::array<u64,4>{v_c247, 0, 0, 0}, [&](const std::array<u64,4>& m991) {
          u64 v_c100 = m991[1]; u64 v_c79 = m991[2]; u64 v_c80 = m991[3];
          if (!slog::exists_probe<4,2>(mp_putindex965, std::array<u64,4>{v_c79, v_c80, 0, 0})) return;
          slog::join_probe<6,3>($sup70016x92x0x0x0index966, std::array<u64,6>{v_c100, v_c79, v_c80, 0, 0, 0}, [&](const std::array<u64,6>& m992) {
            u64 v_c98 = m992[3]; u64 v_c99 = m992[4]; u64 v_c97 = m992[5];
            slog::join_probe_old<4,3>(mp_putindex967, mp_putdelta970, std::array<u64,4>{v_c79, v_c97, v_c80, 0}, [&](const std::array<u64,4>& m993) {
              u64 v_c249 = m993[3];
              slog::join_probe_old<2,1>(mp_put_ansindex968, mp_put_ansdelta971, std::array<u64,2>{v_c249, 0}, [&](const std::array<u64,2>& m994) {
                u64 v_c66 = m994[1];
                ++_fires;
                slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c247, v_c248, v_c98, v_c249, v_c66, v_c99, v_c100, v_c79, v_c80, v_c97}, std::array<u16,10>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval_ans", _fires);
  
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
  // (crule (pre (let __tconst4JFo1084 constcd2a69ce5ca278db1d6da969) (let _00024sqc2XJk894 constd4735e3a265e16eee03f5971) (let _00024sqc3Vvh895 const5feceb66ffc86f38d952786c) (let _00024sqc1G23896 const6b86b273ff34fce19d6b804e) (let _00024sqo5Yvx897 const5feceb66ffc86f38d952786c) (let _00024sqo6jkp898 const6b86b273ff34fce19d6b804e) (let _00024sqo3xdn899 const6b86b273ff34fce19d6b804e) (let _00024sqo4MmQ900 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo5Yvx897 __t6Yod544 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo6jkp898 __t6Yod544 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3xdn899 __t6Yod544 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4MmQ900 __t6Yod544 _00024seq2) (join _enum (0 1) 2 __t6Yod544 __tconst4JFo1084) (join delta (2 0 1) 1 _00024seq2 __t7695542 op) (join comparison_op (0) 1 op) (join any_bool (0) 0 b) (letp _00024sql014l892 (aslst _00024seq2)) (let chk68rS1798 (llen _00024sql014l892)) (eq _00024sqc2XJk894 chk68rS1798) (letp chk1r4b1799 (lref _00024sql014l892 _00024sqc3Vvh895)) (eq __t6Yod544 chk1r4b1799) (letp chk2zHV1800 (lref _00024sql014l892 _00024sqc1G23896)) (eq __t6Yod544 chk2zHV1800)) (head (emit-temp temp4Zu91795 __t7695542 b) (mkstruct boolval (1 0) __t4iE5541 b)) interp.slog:117 #f)
  class ReadTask1005 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex995;  slog::Index** $seq_atrindex996;  slog::Index** $seq_atrindex997;  slog::Index** _enumindex998;  slog::Index** deltaindex999;  slog::Index** comparison_opindex1000;  slog::Index** any_boolindex1001;  slog::Index** $seq_atdelta1002;  slog::Index** $seq_atrdelta1003;  slog::Index** $seq_atrdelta1004;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4Zu91795");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1006({1, 0, 2});
      slog::Relation* readrel1007 = db->getRelation("$seq_at");
      driver_index = readrel1007->getIndex(ord1006, true);
      std::vector<u16> ord1008({1, 0, 2});
      slog::Relation* readrel1009 = db->getRelation("$seq_at");
      $seq_atindex995 = readrel1009->getIndex(ord1008, false);
      std::vector<u16> ord1010({1, 0, 2});
      slog::Relation* readrel1011 = db->getRelation("$seq_at");
      $seq_atdelta1002 = readrel1011->getIndex(ord1010, true);
      std::vector<u16> ord1012({1, 0, 2});
      slog::Relation* readrel1013 = db->getRelation("$seq_atr");
      $seq_atrindex996 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({1, 0, 2});
      slog::Relation* readrel1015 = db->getRelation("$seq_atr");
      $seq_atrdelta1003 = readrel1015->getIndex(ord1014, true);
      std::vector<u16> ord1016({1, 0, 2});
      slog::Relation* readrel1017 = db->getRelation("$seq_atr");
      $seq_atrindex997 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 0, 2});
      slog::Relation* readrel1019 = db->getRelation("$seq_atr");
      $seq_atrdelta1004 = readrel1019->getIndex(ord1018, true);
      std::vector<u16> ord1020({0, 1});
      slog::Relation* readrel1021 = db->getRelation("_enum");
      _enumindex998 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({2, 0, 1});
      slog::Relation* readrel1023 = db->getRelation("delta");
      deltaindex999 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({0});
      slog::Relation* readrel1025 = db->getRelation("comparison_op");
      comparison_opindex1000 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({0});
      slog::Relation* readrel1027 = db->getRelation("any_bool");
      any_boolindex1001 = readrel1027->getIndex(ord1026, false);
  
    }
    ReadTask1005(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c42 = v_constd4735e3a265e16eee03f5971;
      u64 v_c43 = v_const5feceb66ffc86f38d952786c;
      u64 v_c44 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c45 = v_const5feceb66ffc86f38d952786c;
      u64 v_c46 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c47 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c48 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c45, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1028) {
        u64 v_c53 = m1028[1];
        u64 v_c51 = m1028[2];
        if (buckethash(v_c53) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex995, $seq_atdelta1002, std::array<u64,3>{v_c46, v_c53, v_c51}, [&](const std::array<u64,3>& m1029) {
          slog::join_probe_old<3,3>($seq_atrindex996, $seq_atrdelta1003, std::array<u64,3>{v_c47, v_c53, v_c51}, [&](const std::array<u64,3>& m1030) {
            slog::join_probe_old<3,3>($seq_atrindex997, $seq_atrdelta1004, std::array<u64,3>{v_c48, v_c53, v_c51}, [&](const std::array<u64,3>& m1031) {
              slog::join_probe<2,2>(_enumindex998, std::array<u64,2>{v_c53, v_c41}, [&](const std::array<u64,2>& m1032) {
                slog::join_probe<3,1>(deltaindex999, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m1033) {
                  u64 v_c49 = m1033[1]; u64 v_c50 = m1033[2];
                  slog::join_probe<1,1>(comparison_opindex1000, std::array<u64,1>{v_c50}, [&](const std::array<u64,1>& m1034) {
                    slog::join_all<1>(any_boolindex1001, [&](const std::array<u64,1>& m1035) {
                      u64 v_c54 = m1035[0];
                      bool ok1036 = true;
                      u64 v_c52 = _prim_aslst(db, v_c51, &ok1036);
                      if (!ok1036) return;
                      u64 v_c250 = _prim_llen(db, v_c52);
                      if (v_c250 == slog_error) { slog::emit_pending_error(db, "interp.slog:117"); return; }
                      if (v_c42 != v_c250) return;
                      bool ok1037 = true;
                      u64 v_c251 = _prim_lref(db, v_c52, v_c43, &ok1037);
                      if (!ok1037) return;
                      if (v_c53 != v_c251) return;
                      bool ok1038 = true;
                      u64 v_c252 = _prim_lref(db, v_c52, v_c44, &ok1038);
                      if (!ok1038) return;
                      if (v_c53 != v_c252) return;
                      ++_fires;
                      slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c49, v_c54});
                      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c54}, std::array<u16,2>{1, 0});
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
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1005* _cont = new ReadTask1005(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1005(db,b), false);
  // (crule (pre (let __tconst5SF3829 const5feceb66ffc86f38d952786c)) (scan $sup5638x29x0x0x0 __d0 p0 p1 t0 t1) (body (join-old mp_hsb_ans (0 1) 0 (0 1) __t6kiQ828 __v0) (let __t9t7u827 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t6kiQ828 __t9t7u827) (let __t4k7L830 (band p0 __v0)) (cmp gt __t4k7L830 __tconst5SF3829)) (head (emit $sup5638x29x0x0x1 (1 2 0 3 4 5 6) __t6kiQ828 __v0 __d0 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask1043 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1039;  slog::Index** mp_hsbindex1040;  slog::Index** mp_hsb_ansdelta1041;  slog::Index** mp_hsbdelta1042;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord1044({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1045 = db->getRelation("$sup5638x29x0x0x1");
      head_index[0] = readrel1045->getIndex(ord1044, false);
      outer_rel = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord1046({0, 1});
      slog::Relation* readrel1047 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1039 = readrel1047->getIndex(ord1046, false);
      std::vector<u16> ord1048({0, 1});
      slog::Relation* readrel1049 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1041 = readrel1049->getIndex(ord1048, true);
      std::vector<u16> ord1050({0, 1});
      slog::Relation* readrel1051 = db->getRelation("mp_hsb");
      mp_hsbindex1040 = readrel1051->getIndex(ord1050, false);
      std::vector<u16> ord1052({0, 1});
      slog::Relation* readrel1053 = db->getRelation("mp_hsb");
      mp_hsbdelta1042 = readrel1053->getIndex(ord1052, true);
  
    }
    ReadTask1043(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c253 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c98 = _t[0];
        u64 v_c164 = _t[1];
        u64 v_c166 = _t[2];
        u64 v_c165 = _t[3];
        u64 v_c167 = _t[4];
        slog::join_all_old<2>(mp_hsb_ansindex1039, mp_hsb_ansdelta1041, [&](const std::array<u64,2>& m1054) {
          u64 v_c254 = m1054[0]; u64 v_c66 = m1054[1];
          u64 v_c255 = _prim_bxor(db, v_c164, v_c166);
          if (v_c255 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
          slog::join_probe_old<2,2>(mp_hsbindex1040, mp_hsbdelta1042, std::array<u64,2>{v_c254, v_c255}, [&](const std::array<u64,2>& m1055) {
            u64 v_c256 = _prim_band(db, v_c164, v_c66);
            if (v_c256 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            u64 v_c257 = _prim_gt(db, v_c256, v_c253);
            if (v_c257 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            if (!v_c257) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c254, v_c66, v_c98, v_c164, v_c166, v_c165, v_c167}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1043* _cont = new ReadTask1043(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1043(db,b), false);
  // (crule (pre) (scan mleaf __t8ls4627 j w) (body (exists mp_put (1 2 3 0) 1 __t8ls4627) (join-old mp_join (3 4 1 0 2) 2 (3 4 1 0 2) j __t8ls4627 k __t5fYY629 __t6AYq628) (neq j k) (exists mp_put (1 2 3 0) 2 __t8ls4627 k) (exists mp_join_ans (0 1) 1 __t5fYY629) (join-old mleaf (0 1 2) 2 (0 1 2) __t6AYq628 k v) (join mp_put (1 2 3 0) 3 __t8ls4627 k v __t4a7n626) (join mp_join_ans (0 1) 1 __t5fYY629 r)) (head (emit mp_put_ans (0 1) __t4a7n626 r)) map.slog:39 #f)
  class ReadTask1066 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex1057;  slog::Index** mp_joinindex1058;  slog::Index** mp_putindex1059;  slog::Index** mp_join_ansindex1060;  slog::Index** mleafindex1061;  slog::Index** mp_putindex1062;  slog::Index** mp_join_ansindex1063;  slog::Index** mp_joindelta1064;  slog::Index** mleafdelta1065;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord1067({0, 1});
      slog::Relation* readrel1068 = db->getRelation("mp_put_ans");
      head_index[0] = readrel1068->getIndex(ord1067, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord1069({1, 2, 3, 0});
      slog::Relation* readrel1070 = db->getRelation("mp_put");
      mp_putindex1057 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({3, 4, 1, 0, 2});
      slog::Relation* readrel1072 = db->getRelation("mp_join");
      mp_joinindex1058 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({3, 4, 1, 0, 2});
      slog::Relation* readrel1074 = db->getRelation("mp_join");
      mp_joindelta1064 = readrel1074->getIndex(ord1073, true);
      std::vector<u16> ord1075({1, 2, 3, 0});
      slog::Relation* readrel1076 = db->getRelation("mp_put");
      mp_putindex1059 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({0, 1});
      slog::Relation* readrel1078 = db->getRelation("mp_join_ans");
      mp_join_ansindex1060 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({0, 1, 2});
      slog::Relation* readrel1080 = db->getRelation("mleaf");
      mleafindex1061 = readrel1080->getIndex(ord1079, false);
      std::vector<u16> ord1081({0, 1, 2});
      slog::Relation* readrel1082 = db->getRelation("mleaf");
      mleafdelta1065 = readrel1082->getIndex(ord1081, true);
      std::vector<u16> ord1083({1, 2, 3, 0});
      slog::Relation* readrel1084 = db->getRelation("mp_put");
      mp_putindex1062 = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({0, 1});
      slog::Relation* readrel1086 = db->getRelation("mp_join_ans");
      mp_join_ansindex1063 = readrel1086->getIndex(ord1085, false);
  
    }
    ReadTask1066(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c258 = _t[0];
        u64 v_c259 = _t[1];
        u64 v_c103 = _t[2];
        if (!slog::exists_probe<4,1>(mp_putindex1057, std::array<u64,4>{v_c258, 0, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex1058, mp_joindelta1064, std::array<u64,5>{v_c259, v_c258, 0, 0, 0}, [&](const std::array<u64,5>& m1087) {
          u64 v_c37 = m1087[2]; u64 v_c260 = m1087[3]; u64 v_c261 = m1087[4];
          if (v_c259 == v_c37) return;
          if (!slog::exists_probe<4,2>(mp_putindex1059, std::array<u64,4>{v_c258, v_c37, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex1060, std::array<u64,2>{v_c260, 0})) return;
          slog::join_probe_old<3,2>(mleafindex1061, mleafdelta1065, std::array<u64,3>{v_c261, v_c37, 0}, [&](const std::array<u64,3>& m1088) {
            u64 v_c21 = m1088[2];
            slog::join_probe<4,3>(mp_putindex1062, std::array<u64,4>{v_c258, v_c37, v_c21, 0}, [&](const std::array<u64,4>& m1089) {
              u64 v_c262 = m1089[3];
              slog::join_probe<2,1>(mp_join_ansindex1063, std::array<u64,2>{v_c260, 0}, [&](const std::array<u64,2>& m1090) {
                u64 v_c16 = m1090[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c262, v_c16}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask1066* _cont = new ReadTask1066(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1066(db,b), false);
  // (crule (pre (let __tconst43q5382 const5feceb66ffc86f38d952786c)) (scan $sup5638x52x0x0x0 __t9K8V381 k l m p r) (body (exists mp_get (0 2 1) 2 __t9K8V381 k) (exists mp_get (1 2 0) 2 r k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5bK8380) (join-old mp_get (0 2 1) 3 (0 2 1) __t9K8V381 k __t5bK8380) (join-old mp_get (1 2 0) 2 (1 2 0) r k __t1KiE384) (join mp_get_ans (0 1) 1 __t1KiE384 v) (let __t0f7P383 (band k m)) (cmp gt __t0f7P383 __tconst43q5382)) (head (emit mp_get_ans (0 1) __t9K8V381 v)) map.slog:53 #f)
  class ReadTask1100 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex1091;  slog::Index** mp_getindex1092;  slog::Index** mbranchindex1093;  slog::Index** mp_getindex1094;  slog::Index** mp_getindex1095;  slog::Index** mp_get_ansindex1096;  slog::Index** mbranchdelta1097;  slog::Index** mp_getdelta1098;  slog::Index** mp_getdelta1099;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord1101({0, 1});
      slog::Relation* readrel1102 = db->getRelation("mp_get_ans");
      head_index[0] = readrel1102->getIndex(ord1101, false);
      outer_rel = db->getRelation("$sup5638x52x0x0x0");
      std::vector<u16> ord1103({0, 2, 1});
      slog::Relation* readrel1104 = db->getRelation("mp_get");
      mp_getindex1091 = readrel1104->getIndex(ord1103, false);
      std::vector<u16> ord1105({1, 2, 0});
      slog::Relation* readrel1106 = db->getRelation("mp_get");
      mp_getindex1092 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({1, 2, 3, 4, 0});
      slog::Relation* readrel1108 = db->getRelation("mbranch");
      mbranchindex1093 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({1, 2, 3, 4, 0});
      slog::Relation* readrel1110 = db->getRelation("mbranch");
      mbranchdelta1097 = readrel1110->getIndex(ord1109, true);
      std::vector<u16> ord1111({0, 2, 1});
      slog::Relation* readrel1112 = db->getRelation("mp_get");
      mp_getindex1094 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({0, 2, 1});
      slog::Relation* readrel1114 = db->getRelation("mp_get");
      mp_getdelta1098 = readrel1114->getIndex(ord1113, true);
      std::vector<u16> ord1115({1, 2, 0});
      slog::Relation* readrel1116 = db->getRelation("mp_get");
      mp_getindex1095 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({1, 2, 0});
      slog::Relation* readrel1118 = db->getRelation("mp_get");
      mp_getdelta1099 = readrel1118->getIndex(ord1117, true);
      std::vector<u16> ord1119({0, 1});
      slog::Relation* readrel1120 = db->getRelation("mp_get_ans");
      mp_get_ansindex1096 = readrel1120->getIndex(ord1119, false);
  
    }
    ReadTask1100(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c263 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c264 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c15 = _t[2];
        u64 v_c14 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c16 = _t[5];
        if (!slog::exists_probe<3,2>(mp_getindex1091, std::array<u64,3>{v_c264, v_c37, 0})) return;
        if (!slog::exists_probe<3,2>(mp_getindex1092, std::array<u64,3>{v_c16, v_c37, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex1093, mbranchdelta1097, std::array<u64,5>{v_c13, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,5>& m1121) {
          u64 v_c265 = m1121[4];
          slog::join_probe_old<3,3>(mp_getindex1094, mp_getdelta1098, std::array<u64,3>{v_c264, v_c37, v_c265}, [&](const std::array<u64,3>& m1122) {
            slog::join_probe_old<3,2>(mp_getindex1095, mp_getdelta1099, std::array<u64,3>{v_c16, v_c37, 0}, [&](const std::array<u64,3>& m1123) {
              u64 v_c266 = m1123[2];
              slog::join_probe<2,1>(mp_get_ansindex1096, std::array<u64,2>{v_c266, 0}, [&](const std::array<u64,2>& m1124) {
                u64 v_c21 = m1124[1];
                u64 v_c267 = _prim_band(db, v_c37, v_c14);
                if (v_c267 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                u64 v_c268 = _prim_gt(db, v_c267, v_c263);
                if (v_c268 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                if (!v_c268) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c264, v_c21}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:53", "delta:$sup5638x52x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1100* _cont = new ReadTask1100(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1100(db,b), false);
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan $sup5638x25x0x0x1 __t8CpS128 __t0Ayb132 __v0 p0 p1 t0 t1) (body (exists $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t8CpS128 p1 t0 t1) (exists mp_join (1 2 3 4 0) 5 p0 t0 p1 t1 __t8CpS128) (exists mp_hsb_ans (0 1) 1 __t0Ayb132) (exists mp_hsb_ans (0 1) 2 __t0Ayb132 __v0) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x25x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0 dup4t6F1978 dup2J5X1979 __v1 __v3) (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join-old $sup5638x25x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t8CpS128 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t8CpS128) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t40jf135) (join-old mp_msk_ans (0 1) 1 (0 1) __t40jf135 __v2) (let __t867d136 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t0Ayb132 __t867d136) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask1148 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x25x0x0x0index1126;  slog::Index** mp_joinindex1127;  slog::Index** mp_hsb_ansindex1128;  slog::Index** mp_hsb_ansindex1129;  slog::Index** mp_mskindex1130;  slog::Index** $sup5638x25x0x0x2index1131;  slog::Index** $sup5638x25x0x0x0index1132;  slog::Index** mp_joinindex1133;  slog::Index** mp_hsb_ansindex1134;  slog::Index** mp_hsb_ansindex1135;  slog::Index** mp_hsb_ansindex1136;  slog::Index** mp_mskindex1137;  slog::Index** mp_msk_ansindex1138;  slog::Index** mp_hsbindex1139;  slog::Index** $sup5638x25x0x0x0delta1140;  slog::Index** mp_joindelta1141;  slog::Index** mp_hsb_ansdelta1142;  slog::Index** mp_hsb_ansdelta1143;  slog::Index** mp_hsb_ansdelta1144;  slog::Index** mp_mskdelta1145;  slog::Index** mp_msk_ansdelta1146;  slog::Index** mp_hsbdelta1147;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord1149({1, 0, 2, 3, 4});
      slog::Relation* readrel1150 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index1126 = readrel1150->getIndex(ord1149, false);
      std::vector<u16> ord1151({1, 2, 3, 4, 0});
      slog::Relation* readrel1152 = db->getRelation("mp_join");
      mp_joinindex1127 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({0, 1});
      slog::Relation* readrel1154 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1128 = readrel1154->getIndex(ord1153, false);
      std::vector<u16> ord1155({0, 1});
      slog::Relation* readrel1156 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1129 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({1, 2, 0});
      slog::Relation* readrel1158 = db->getRelation("mp_msk");
      mp_mskindex1130 = readrel1158->getIndex(ord1157, false);
      std::vector<u16> ord1159({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel1160 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1131 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({1, 0, 2, 3, 4});
      slog::Relation* readrel1162 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index1132 = readrel1162->getIndex(ord1161, false);
      std::vector<u16> ord1163({1, 0, 2, 3, 4});
      slog::Relation* readrel1164 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0delta1140 = readrel1164->getIndex(ord1163, true);
      std::vector<u16> ord1165({1, 2, 3, 4, 0});
      slog::Relation* readrel1166 = db->getRelation("mp_join");
      mp_joinindex1133 = readrel1166->getIndex(ord1165, false);
      std::vector<u16> ord1167({1, 2, 3, 4, 0});
      slog::Relation* readrel1168 = db->getRelation("mp_join");
      mp_joindelta1141 = readrel1168->getIndex(ord1167, true);
      std::vector<u16> ord1169({0, 1});
      slog::Relation* readrel1170 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1134 = readrel1170->getIndex(ord1169, false);
      std::vector<u16> ord1171({0, 1});
      slog::Relation* readrel1172 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1142 = readrel1172->getIndex(ord1171, true);
      std::vector<u16> ord1173({0, 1});
      slog::Relation* readrel1174 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1135 = readrel1174->getIndex(ord1173, false);
      std::vector<u16> ord1175({0, 1});
      slog::Relation* readrel1176 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1143 = readrel1176->getIndex(ord1175, true);
      std::vector<u16> ord1177({0, 1});
      slog::Relation* readrel1178 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1136 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({0, 1});
      slog::Relation* readrel1180 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1144 = readrel1180->getIndex(ord1179, true);
      std::vector<u16> ord1181({1, 2, 0});
      slog::Relation* readrel1182 = db->getRelation("mp_msk");
      mp_mskindex1137 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({1, 2, 0});
      slog::Relation* readrel1184 = db->getRelation("mp_msk");
      mp_mskdelta1145 = readrel1184->getIndex(ord1183, true);
      std::vector<u16> ord1185({0, 1});
      slog::Relation* readrel1186 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1138 = readrel1186->getIndex(ord1185, false);
      std::vector<u16> ord1187({0, 1});
      slog::Relation* readrel1188 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta1146 = readrel1188->getIndex(ord1187, true);
      std::vector<u16> ord1189({0, 1});
      slog::Relation* readrel1190 = db->getRelation("mp_hsb");
      mp_hsbindex1139 = readrel1190->getIndex(ord1189, false);
      std::vector<u16> ord1191({0, 1});
      slog::Relation* readrel1192 = db->getRelation("mp_hsb");
      mp_hsbdelta1147 = readrel1192->getIndex(ord1191, true);
  
    }
    ReadTask1148(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c269 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c270 = _t[0];
        u64 v_c271 = _t[1];
        u64 v_c66 = _t[2];
        u64 v_c164 = _t[3];
        u64 v_c166 = _t[4];
        u64 v_c165 = _t[5];
        u64 v_c167 = _t[6];
        if (!slog::exists_probe<5,5>($sup5638x25x0x0x0index1126, std::array<u64,5>{v_c164, v_c270, v_c166, v_c165, v_c167})) return;
        if (!slog::exists_probe<5,5>(mp_joinindex1127, std::array<u64,5>{v_c164, v_c165, v_c166, v_c167, v_c270})) return;
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex1128, std::array<u64,2>{v_c271, 0})) return;
        if (!slog::exists_probe<2,2>(mp_hsb_ansindex1129, std::array<u64,2>{v_c271, v_c66})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1130, std::array<u64,3>{v_c164, 0, 0})) return;
        slog::join_probe<11,7>($sup5638x25x0x0x2index1131, std::array<u64,11>{v_c270, v_c164, v_c166, v_c165, v_c167, v_c271, v_c66, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1193) {
          u64 v_c272 = m1193[7]; u64 v_c273 = m1193[8]; u64 v_c78 = m1193[9]; u64 v_c274 = m1193[10];
          if (v_c271 != v_c273) return;
          if (v_c271 != v_c272) return;
          slog::join_probe_old<5,5>($sup5638x25x0x0x0index1132, $sup5638x25x0x0x0delta1140, std::array<u64,5>{v_c164, v_c270, v_c166, v_c165, v_c167}, [&](const std::array<u64,5>& m1194) {
            slog::join_probe_old<5,5>(mp_joinindex1133, mp_joindelta1141, std::array<u64,5>{v_c164, v_c165, v_c166, v_c167, v_c270}, [&](const std::array<u64,5>& m1195) {
              slog::join_probe_old<2,2>(mp_hsb_ansindex1134, mp_hsb_ansdelta1142, std::array<u64,2>{v_c271, v_c274}, [&](const std::array<u64,2>& m1196) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex1135, mp_hsb_ansdelta1143, std::array<u64,2>{v_c271, v_c78}, [&](const std::array<u64,2>& m1197) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex1136, mp_hsb_ansdelta1144, std::array<u64,2>{v_c271, v_c66}, [&](const std::array<u64,2>& m1198) {
                    slog::join_probe_old<3,2>(mp_mskindex1137, mp_mskdelta1145, std::array<u64,3>{v_c164, v_c78, 0}, [&](const std::array<u64,3>& m1199) {
                      u64 v_c275 = m1199[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex1138, mp_msk_ansdelta1146, std::array<u64,2>{v_c275, 0}, [&](const std::array<u64,2>& m1200) {
                        u64 v_c88 = m1200[1];
                        u64 v_c276 = _prim_bxor(db, v_c164, v_c166);
                        if (v_c276 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex1139, mp_hsbdelta1147, std::array<u64,2>{v_c271, v_c276}, [&](const std::array<u64,2>& m1201) {
                          u64 v_c277 = _prim_band(db, v_c164, v_c66);
                          if (v_c277 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c278 = _prim_lt(db, v_c277, v_c269);
                          if (v_c278 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c278) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c270, v_c88, v_c274, v_c165, v_c167});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c88, v_c274, v_c165, v_c167}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1148* _cont = new ReadTask1148(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1148(db,b), false);
  // (crule (pre) (scan app __t3cXN608 ef es) (body (join eval (1 2 3 0) 1 __t3cXN608 rho t __2hk41536)) (head (mkstruct eval_args (1 3 2 0) __2QMq1537 es t rho)) interp.slog:59 #f)
  class ReadTask1204 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1203;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_args");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1205({1, 2, 3, 0});
      slog::Relation* readrel1206 = db->getRelation("eval");
      evalindex1203 = readrel1206->getIndex(ord1205, false);
  
    }
    ReadTask1204(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c174 = _t[1];
        u64 v_c175 = _t[2];
        slog::join_probe<4,1>(evalindex1203, std::array<u64,4>{v_c279, 0, 0, 0}, [&](const std::array<u64,4>& m1207) {
          u64 v_c79 = m1207[1]; u64 v_c80 = m1207[2]; u64 v_c280 = m1207[3];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c175, v_c80, v_c79}, std::array<u16,4>{1, 3, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1204* _cont = new ReadTask1204(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1204(db,b), false);
  // (crule (pre) (scan eval_ans __t7TaT537 v) (body (join-old eval (0 1 2 3) 1 (0 1 2 3) __t7TaT537 eb __v0 t2) (exists extend_env_ans (1 0) 1 __v0) (exists extend_env (3 0 1 2) 1 t2) (exists $sup70016x51x0x0x1 (4 10 8 12 0 1 2 3 5 6 7 9 11) 2 eb t2) (exists lambda (2 0 1) 1 eb) (join-old tick_ans (1 0) 1 (1 0) t2 __t0CD9539) (exists $sup70016x51x0x0x1 (3 10 4 0 1 2 5 6 7 8 9 11 12) 3 __t0CD9539 t2 eb) (join-old extend_env_ans (1 0) 1 (1 0) __v0 __t5fzh540) (join-old extend_env (3 0 1 2) 2 (3 0 1 2) t2 __t5fzh540 rhoc xs) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (join-old $sup70016x51x0x0x1 (8 10 12 3 4 0 1 2 5 6 7 9 11) 5 (8 10 12 3 4 0 1 2 5 6 7 9 11) rhoc t2 xs __t0CD9539 eb __t2z6s532 __t5qy8533 __t2srV536 ef es rho t vs) (join-old $sup70016x51x0x0x0 (4 0 3 1 2) 5 (4 0 3 1 2) t __t2z6s532 rho ef es) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5qy8533 ef) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (exists app (1 2 0) 2 ef es) (exists tick (0 2 1) 2 __t0CD9539 t) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists eval_ans (0 1) 1 __t5qy8533) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t6iPm534) (join-old closure (1 2 0) 2 (1 2 0) __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask1247 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1208;  slog::Index** extend_env_ansindex1209;  slog::Index** extend_envindex1210;  slog::Index** $sup70016x51x0x0x1index1211;  slog::Index** lambdaindex1212;  slog::Index** tick_ansindex1213;  slog::Index** $sup70016x51x0x0x1index1214;  slog::Index** extend_env_ansindex1215;  slog::Index** extend_envindex1216;  slog::Index** lambdaindex1217;  slog::Index** closureindex1218;  slog::Index** $sup70016x51x0x0x1index1219;  slog::Index** $sup70016x51x0x0x0index1220;  slog::Index** evalindex1221;  slog::Index** eval_argsindex1222;  slog::Index** appindex1223;  slog::Index** tickindex1224;  slog::Index** eval_args_ansindex1225;  slog::Index** eval_ansindex1226;  slog::Index** evalindex1227;  slog::Index** appindex1228;  slog::Index** tickindex1229;  slog::Index** eval_args_ansindex1230;  slog::Index** lambdaindex1231;  slog::Index** closureindex1232;  slog::Index** eval_ansindex1233;  slog::Index** evaldelta1234;  slog::Index** tick_ansdelta1235;  slog::Index** extend_env_ansdelta1236;  slog::Index** extend_envdelta1237;  slog::Index** $sup70016x51x0x0x1delta1238;  slog::Index** $sup70016x51x0x0x0delta1239;  slog::Index** evaldelta1240;  slog::Index** eval_argsdelta1241;  slog::Index** evaldelta1242;  slog::Index** appdelta1243;  slog::Index** tickdelta1244;  slog::Index** lambdadelta1245;  slog::Index** closuredelta1246;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1248({0, 1});
      slog::Relation* readrel1249 = db->getRelation("eval_ans");
      head_index[0] = readrel1249->getIndex(ord1248, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1250({0, 1, 2, 3});
      slog::Relation* readrel1251 = db->getRelation("eval");
      evalindex1208 = readrel1251->getIndex(ord1250, false);
      std::vector<u16> ord1252({0, 1, 2, 3});
      slog::Relation* readrel1253 = db->getRelation("eval");
      evaldelta1234 = readrel1253->getIndex(ord1252, true);
      std::vector<u16> ord1254({1, 0});
      slog::Relation* readrel1255 = db->getRelation("extend_env_ans");
      extend_env_ansindex1209 = readrel1255->getIndex(ord1254, false);
      std::vector<u16> ord1256({3, 0, 1, 2});
      slog::Relation* readrel1257 = db->getRelation("extend_env");
      extend_envindex1210 = readrel1257->getIndex(ord1256, false);
      std::vector<u16> ord1258({4, 10, 8, 12, 0, 1, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel1259 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1211 = readrel1259->getIndex(ord1258, false);
      std::vector<u16> ord1260({2, 0, 1});
      slog::Relation* readrel1261 = db->getRelation("lambda");
      lambdaindex1212 = readrel1261->getIndex(ord1260, false);
      std::vector<u16> ord1262({1, 0});
      slog::Relation* readrel1263 = db->getRelation("tick_ans");
      tick_ansindex1213 = readrel1263->getIndex(ord1262, false);
      std::vector<u16> ord1264({1, 0});
      slog::Relation* readrel1265 = db->getRelation("tick_ans");
      tick_ansdelta1235 = readrel1265->getIndex(ord1264, true);
      std::vector<u16> ord1266({3, 10, 4, 0, 1, 2, 5, 6, 7, 8, 9, 11, 12});
      slog::Relation* readrel1267 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1214 = readrel1267->getIndex(ord1266, false);
      std::vector<u16> ord1268({1, 0});
      slog::Relation* readrel1269 = db->getRelation("extend_env_ans");
      extend_env_ansindex1215 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({1, 0});
      slog::Relation* readrel1271 = db->getRelation("extend_env_ans");
      extend_env_ansdelta1236 = readrel1271->getIndex(ord1270, true);
      std::vector<u16> ord1272({3, 0, 1, 2});
      slog::Relation* readrel1273 = db->getRelation("extend_env");
      extend_envindex1216 = readrel1273->getIndex(ord1272, false);
      std::vector<u16> ord1274({3, 0, 1, 2});
      slog::Relation* readrel1275 = db->getRelation("extend_env");
      extend_envdelta1237 = readrel1275->getIndex(ord1274, true);
      std::vector<u16> ord1276({1, 2, 0});
      slog::Relation* readrel1277 = db->getRelation("lambda");
      lambdaindex1217 = readrel1277->getIndex(ord1276, false);
      std::vector<u16> ord1278({2, 0, 1});
      slog::Relation* readrel1279 = db->getRelation("closure");
      closureindex1218 = readrel1279->getIndex(ord1278, false);
      std::vector<u16> ord1280({8, 10, 12, 3, 4, 0, 1, 2, 5, 6, 7, 9, 11});
      slog::Relation* readrel1281 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1219 = readrel1281->getIndex(ord1280, false);
      std::vector<u16> ord1282({8, 10, 12, 3, 4, 0, 1, 2, 5, 6, 7, 9, 11});
      slog::Relation* readrel1283 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1delta1238 = readrel1283->getIndex(ord1282, true);
      std::vector<u16> ord1284({4, 0, 3, 1, 2});
      slog::Relation* readrel1285 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1220 = readrel1285->getIndex(ord1284, false);
      std::vector<u16> ord1286({4, 0, 3, 1, 2});
      slog::Relation* readrel1287 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0delta1239 = readrel1287->getIndex(ord1286, true);
      std::vector<u16> ord1288({2, 3, 0, 1});
      slog::Relation* readrel1289 = db->getRelation("eval");
      evalindex1221 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({2, 3, 0, 1});
      slog::Relation* readrel1291 = db->getRelation("eval");
      evaldelta1240 = readrel1291->getIndex(ord1290, true);
      std::vector<u16> ord1292({3, 2, 0, 1});
      slog::Relation* readrel1293 = db->getRelation("eval_args");
      eval_argsindex1222 = readrel1293->getIndex(ord1292, false);
      std::vector<u16> ord1294({3, 2, 0, 1});
      slog::Relation* readrel1295 = db->getRelation("eval_args");
      eval_argsdelta1241 = readrel1295->getIndex(ord1294, true);
      std::vector<u16> ord1296({1, 2, 0});
      slog::Relation* readrel1297 = db->getRelation("app");
      appindex1223 = readrel1297->getIndex(ord1296, false);
      std::vector<u16> ord1298({0, 2, 1});
      slog::Relation* readrel1299 = db->getRelation("tick");
      tickindex1224 = readrel1299->getIndex(ord1298, false);
      std::vector<u16> ord1300({0, 1});
      slog::Relation* readrel1301 = db->getRelation("eval_args_ans");
      eval_args_ansindex1225 = readrel1301->getIndex(ord1300, false);
      std::vector<u16> ord1302({0, 1});
      slog::Relation* readrel1303 = db->getRelation("eval_ans");
      eval_ansindex1226 = readrel1303->getIndex(ord1302, false);
      std::vector<u16> ord1304({2, 3, 0, 1});
      slog::Relation* readrel1305 = db->getRelation("eval");
      evalindex1227 = readrel1305->getIndex(ord1304, false);
      std::vector<u16> ord1306({2, 3, 0, 1});
      slog::Relation* readrel1307 = db->getRelation("eval");
      evaldelta1242 = readrel1307->getIndex(ord1306, true);
      std::vector<u16> ord1308({0, 1, 2});
      slog::Relation* readrel1309 = db->getRelation("app");
      appindex1228 = readrel1309->getIndex(ord1308, false);
      std::vector<u16> ord1310({0, 1, 2});
      slog::Relation* readrel1311 = db->getRelation("app");
      appdelta1243 = readrel1311->getIndex(ord1310, true);
      std::vector<u16> ord1312({0, 2, 1});
      slog::Relation* readrel1313 = db->getRelation("tick");
      tickindex1229 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({0, 2, 1});
      slog::Relation* readrel1315 = db->getRelation("tick");
      tickdelta1244 = readrel1315->getIndex(ord1314, true);
      std::vector<u16> ord1316({0, 1});
      slog::Relation* readrel1317 = db->getRelation("eval_args_ans");
      eval_args_ansindex1230 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({1, 2, 0});
      slog::Relation* readrel1319 = db->getRelation("lambda");
      lambdaindex1231 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({1, 2, 0});
      slog::Relation* readrel1321 = db->getRelation("lambda");
      lambdadelta1245 = readrel1321->getIndex(ord1320, true);
      std::vector<u16> ord1322({1, 2, 0});
      slog::Relation* readrel1323 = db->getRelation("closure");
      closureindex1232 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({1, 2, 0});
      slog::Relation* readrel1325 = db->getRelation("closure");
      closuredelta1246 = readrel1325->getIndex(ord1324, true);
      std::vector<u16> ord1326({0, 1});
      slog::Relation* readrel1327 = db->getRelation("eval_ans");
      eval_ansindex1233 = readrel1327->getIndex(ord1326, false);
  
    }
    ReadTask1247(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c179 = _t[0];
        u64 v_c21 = _t[1];
        slog::join_probe_old<4,1>(evalindex1208, evaldelta1234, std::array<u64,4>{v_c179, 0, 0, 0}, [&](const std::array<u64,4>& m1328) {
          u64 v_c99 = m1328[1]; u64 v_c66 = m1328[2]; u64 v_c152 = m1328[3];
          if (!slog::exists_probe<2,1>(extend_env_ansindex1209, std::array<u64,2>{v_c66, 0})) return;
          if (!slog::exists_probe<4,1>(extend_envindex1210, std::array<u64,4>{v_c152, 0, 0, 0})) return;
          if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index1211, std::array<u64,13>{v_c99, v_c152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1212, std::array<u64,3>{v_c99, 0, 0})) return;
          slog::join_probe_old<2,1>(tick_ansindex1213, tick_ansdelta1235, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m1329) {
            u64 v_c170 = m1329[1];
            if (!slog::exists_probe<13,3>($sup70016x51x0x0x1index1214, std::array<u64,13>{v_c170, v_c152, v_c99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<2,1>(extend_env_ansindex1215, extend_env_ansdelta1236, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m1330) {
              u64 v_c168 = m1330[1];
              slog::join_probe_old<4,2>(extend_envindex1216, extend_envdelta1237, std::array<u64,4>{v_c152, v_c168, 0, 0}, [&](const std::array<u64,4>& m1331) {
                u64 v_c169 = m1331[2]; u64 v_c162 = m1331[3];
                if (!slog::exists_probe<3,2>(lambdaindex1217, std::array<u64,3>{v_c162, v_c99, 0})) return;
                if (!slog::exists_probe<3,1>(closureindex1218, std::array<u64,3>{v_c169, 0, 0})) return;
                slog::join_probe_old<13,5>($sup70016x51x0x0x1index1219, $sup70016x51x0x0x1delta1238, std::array<u64,13>{v_c169, v_c152, v_c162, v_c170, v_c99, 0, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1332) {
                  u64 v_c171 = m1332[5]; u64 v_c172 = m1332[6]; u64 v_c173 = m1332[7]; u64 v_c174 = m1332[8]; u64 v_c175 = m1332[9]; u64 v_c79 = m1332[10]; u64 v_c80 = m1332[11]; u64 v_c160 = m1332[12];
                  slog::join_probe_old<5,5>($sup70016x51x0x0x0index1220, $sup70016x51x0x0x0delta1239, std::array<u64,5>{v_c80, v_c171, v_c79, v_c174, v_c175}, [&](const std::array<u64,5>& m1333) {
                    slog::join_probe_old<4,4>(evalindex1221, evaldelta1240, std::array<u64,4>{v_c79, v_c80, v_c172, v_c174}, [&](const std::array<u64,4>& m1334) {
                      slog::join_probe_old<4,4>(eval_argsindex1222, eval_argsdelta1241, std::array<u64,4>{v_c80, v_c79, v_c173, v_c175}, [&](const std::array<u64,4>& m1335) {
                        if (!slog::exists_probe<3,2>(appindex1223, std::array<u64,3>{v_c174, v_c175, 0})) return;
                        if (!slog::exists_probe<3,2>(tickindex1224, std::array<u64,3>{v_c170, v_c80, 0})) return;
                        if (!slog::exists_probe<2,2>(eval_args_ansindex1225, std::array<u64,2>{v_c173, v_c160})) return;
                        if (!slog::exists_probe<2,1>(eval_ansindex1226, std::array<u64,2>{v_c172, 0})) return;
                        slog::join_probe_old<4,3>(evalindex1227, evaldelta1242, std::array<u64,4>{v_c79, v_c80, v_c171, 0}, [&](const std::array<u64,4>& m1336) {
                          u64 v_c176 = m1336[3];
                          slog::join_probe_old<3,3>(appindex1228, appdelta1243, std::array<u64,3>{v_c176, v_c174, v_c175}, [&](const std::array<u64,3>& m1337) {
                            slog::join_probe_old<3,3>(tickindex1229, tickdelta1244, std::array<u64,3>{v_c170, v_c80, v_c176}, [&](const std::array<u64,3>& m1338) {
                              slog::join_probe<2,2>(eval_args_ansindex1230, std::array<u64,2>{v_c173, v_c160}, [&](const std::array<u64,2>& m1339) {
                                slog::join_probe_old<3,2>(lambdaindex1231, lambdadelta1245, std::array<u64,3>{v_c162, v_c99, 0}, [&](const std::array<u64,3>& m1340) {
                                  u64 v_c177 = m1340[2];
                                  slog::join_probe_old<3,2>(closureindex1232, closuredelta1246, std::array<u64,3>{v_c177, v_c169, 0}, [&](const std::array<u64,3>& m1341) {
                                    u64 v_c178 = m1341[2];
                                    slog::join_probe<2,2>(eval_ansindex1233, std::array<u64,2>{v_c172, v_c178}, [&](const std::array<u64,2>& m1342) {
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c171, v_c21}, std::array<u16,2>{0, 1});
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
  // (crule (pre) (scan eval __3JBR1203 __t3MQm616 rho t) (body (exists eval (2 3 0 1) 2 rho t) (exists eval_args (3 2 0 1) 2 t rho) (join-old tick (1 2 0) 2 (1 2 0) __t3MQm616 t __t2n7W617) (exists tick_ans (0 1) 1 __t2n7W617) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t7lOb612 ef) (exists eval_ans (0 1) 1 __t7lOb612) (join-old app (0 1 2) 2 (0 1 2) __t3MQm616 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t192L615) (exists eval_args_ans (0 1) 1 __t192L615) (join-old eval_ans (0 1) 1 (0 1) __t7lOb612 __t6tRF614) (join-old eval_args_ans (0 1) 1 (0 1) __t192L615 vs) (join-old tick_ans (0 1) 1 (0 1) __t2n7W617 t2) (join-old closure (0 1 2) 1 (0 1 2) __t6tRF614 __t20Nd613 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t20Nd613 xs eb)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask1366 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1343;  slog::Index** eval_argsindex1344;  slog::Index** tickindex1345;  slog::Index** tick_ansindex1346;  slog::Index** evalindex1347;  slog::Index** eval_ansindex1348;  slog::Index** appindex1349;  slog::Index** eval_argsindex1350;  slog::Index** eval_args_ansindex1351;  slog::Index** eval_ansindex1352;  slog::Index** eval_args_ansindex1353;  slog::Index** tick_ansindex1354;  slog::Index** closureindex1355;  slog::Index** lambdaindex1356;  slog::Index** tickdelta1357;  slog::Index** evaldelta1358;  slog::Index** appdelta1359;  slog::Index** eval_argsdelta1360;  slog::Index** eval_ansdelta1361;  slog::Index** eval_args_ansdelta1362;  slog::Index** tick_ansdelta1363;  slog::Index** closuredelta1364;  slog::Index** lambdadelta1365;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord1367({0, 1, 2, 3});
      slog::Relation* readrel1368 = db->getRelation("bind_store");
      head_index[0] = readrel1368->getIndex(ord1367, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1369({0, 1});
      slog::Relation* readrel1370 = db->getRelation("call_event");
      head_index[1] = readrel1370->getIndex(ord1369, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1371({2, 3, 0, 1});
      slog::Relation* readrel1372 = db->getRelation("eval");
      evalindex1343 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({3, 2, 0, 1});
      slog::Relation* readrel1374 = db->getRelation("eval_args");
      eval_argsindex1344 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({1, 2, 0});
      slog::Relation* readrel1376 = db->getRelation("tick");
      tickindex1345 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({1, 2, 0});
      slog::Relation* readrel1378 = db->getRelation("tick");
      tickdelta1357 = readrel1378->getIndex(ord1377, true);
      std::vector<u16> ord1379({0, 1});
      slog::Relation* readrel1380 = db->getRelation("tick_ans");
      tick_ansindex1346 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({2, 3, 0, 1});
      slog::Relation* readrel1382 = db->getRelation("eval");
      evalindex1347 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({2, 3, 0, 1});
      slog::Relation* readrel1384 = db->getRelation("eval");
      evaldelta1358 = readrel1384->getIndex(ord1383, true);
      std::vector<u16> ord1385({0, 1});
      slog::Relation* readrel1386 = db->getRelation("eval_ans");
      eval_ansindex1348 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({0, 1, 2});
      slog::Relation* readrel1388 = db->getRelation("app");
      appindex1349 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({0, 1, 2});
      slog::Relation* readrel1390 = db->getRelation("app");
      appdelta1359 = readrel1390->getIndex(ord1389, true);
      std::vector<u16> ord1391({1, 3, 2, 0});
      slog::Relation* readrel1392 = db->getRelation("eval_args");
      eval_argsindex1350 = readrel1392->getIndex(ord1391, false);
      std::vector<u16> ord1393({1, 3, 2, 0});
      slog::Relation* readrel1394 = db->getRelation("eval_args");
      eval_argsdelta1360 = readrel1394->getIndex(ord1393, true);
      std::vector<u16> ord1395({0, 1});
      slog::Relation* readrel1396 = db->getRelation("eval_args_ans");
      eval_args_ansindex1351 = readrel1396->getIndex(ord1395, false);
      std::vector<u16> ord1397({0, 1});
      slog::Relation* readrel1398 = db->getRelation("eval_ans");
      eval_ansindex1352 = readrel1398->getIndex(ord1397, false);
      std::vector<u16> ord1399({0, 1});
      slog::Relation* readrel1400 = db->getRelation("eval_ans");
      eval_ansdelta1361 = readrel1400->getIndex(ord1399, true);
      std::vector<u16> ord1401({0, 1});
      slog::Relation* readrel1402 = db->getRelation("eval_args_ans");
      eval_args_ansindex1353 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({0, 1});
      slog::Relation* readrel1404 = db->getRelation("eval_args_ans");
      eval_args_ansdelta1362 = readrel1404->getIndex(ord1403, true);
      std::vector<u16> ord1405({0, 1});
      slog::Relation* readrel1406 = db->getRelation("tick_ans");
      tick_ansindex1354 = readrel1406->getIndex(ord1405, false);
      std::vector<u16> ord1407({0, 1});
      slog::Relation* readrel1408 = db->getRelation("tick_ans");
      tick_ansdelta1363 = readrel1408->getIndex(ord1407, true);
      std::vector<u16> ord1409({0, 1, 2});
      slog::Relation* readrel1410 = db->getRelation("closure");
      closureindex1355 = readrel1410->getIndex(ord1409, false);
      std::vector<u16> ord1411({0, 1, 2});
      slog::Relation* readrel1412 = db->getRelation("closure");
      closuredelta1364 = readrel1412->getIndex(ord1411, true);
      std::vector<u16> ord1413({0, 1, 2});
      slog::Relation* readrel1414 = db->getRelation("lambda");
      lambdaindex1356 = readrel1414->getIndex(ord1413, false);
      std::vector<u16> ord1415({0, 1, 2});
      slog::Relation* readrel1416 = db->getRelation("lambda");
      lambdadelta1365 = readrel1416->getIndex(ord1415, true);
  
    }
    ReadTask1366(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c182 = _t[0];
        u64 v_c181 = _t[1];
        u64 v_c79 = _t[2];
        u64 v_c80 = _t[3];
        if (!slog::exists_probe<4,2>(evalindex1343, std::array<u64,4>{v_c79, v_c80, 0, 0})) return;
        if (!slog::exists_probe<4,2>(eval_argsindex1344, std::array<u64,4>{v_c80, v_c79, 0, 0})) return;
        slog::join_probe_old<3,2>(tickindex1345, tickdelta1357, std::array<u64,3>{v_c181, v_c80, 0}, [&](const std::array<u64,3>& m1417) {
          u64 v_c180 = m1417[2];
          if (!slog::exists_probe<2,1>(tick_ansindex1346, std::array<u64,2>{v_c180, 0})) return;
          slog::join_probe_old<4,2>(evalindex1347, evaldelta1358, std::array<u64,4>{v_c79, v_c80, 0, 0}, [&](const std::array<u64,4>& m1418) {
            u64 v_c183 = m1418[2]; u64 v_c174 = m1418[3];
            if (!slog::exists_probe<2,1>(eval_ansindex1348, std::array<u64,2>{v_c183, 0})) return;
            slog::join_probe_old<3,2>(appindex1349, appdelta1359, std::array<u64,3>{v_c181, v_c174, 0}, [&](const std::array<u64,3>& m1419) {
              u64 v_c175 = m1419[2];
              slog::join_probe_old<4,3>(eval_argsindex1350, eval_argsdelta1360, std::array<u64,4>{v_c175, v_c80, v_c79, 0}, [&](const std::array<u64,4>& m1420) {
                u64 v_c184 = m1420[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1351, std::array<u64,2>{v_c184, 0})) return;
                slog::join_probe_old<2,1>(eval_ansindex1352, eval_ansdelta1361, std::array<u64,2>{v_c183, 0}, [&](const std::array<u64,2>& m1421) {
                  u64 v_c185 = m1421[1];
                  slog::join_probe_old<2,1>(eval_args_ansindex1353, eval_args_ansdelta1362, std::array<u64,2>{v_c184, 0}, [&](const std::array<u64,2>& m1422) {
                    u64 v_c160 = m1422[1];
                    slog::join_probe_old<2,1>(tick_ansindex1354, tick_ansdelta1363, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m1423) {
                      u64 v_c152 = m1423[1];
                      slog::join_probe_old<3,1>(closureindex1355, closuredelta1364, std::array<u64,3>{v_c185, 0, 0}, [&](const std::array<u64,3>& m1424) {
                        u64 v_c186 = m1424[1]; u64 v_c169 = m1424[2];
                        slog::join_probe_old<3,1>(lambdaindex1356, lambdadelta1365, std::array<u64,3>{v_c186, 0, 0}, [&](const std::array<u64,3>& m1425) {
                          u64 v_c162 = m1425[1]; u64 v_c99 = m1425[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c162, v_c160, v_c152, v_c80}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c152, v_c80}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1366* _cont = new ReadTask1366(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1366(db,b), false);
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan mp_hsb_ans __t0Ayb132 __v3) (body (exists mp_hsb_ans (0 1) 1 __t0Ayb132) (exists $sup5638x25x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t0Ayb132 __v3) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 1 __t0Ayb132) (join-old mp_hsb_ans (0 1) 1 (0 1) __t0Ayb132 __v1) (exists $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t0Ayb132 __v1 __v3) (exists mp_msk (2 0 1) 1 __v1) (join-old mp_hsb_ans (0 1) 1 (0 1) __t0Ayb132 __v0) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 2 __t0Ayb132 __v0) (join $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t0Ayb132 __v0 __v3 __v1 __t8CpS128 dup4t6F1978 dup2J5X1979 p0 p1 t0 t1) (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t8CpS128 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t8CpS128) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t40jf135) (join-old mp_msk_ans (0 1) 1 (0 1) __t40jf135 __v2) (let __t867d136 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t0Ayb132 __t867d136) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask1447 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1426;  slog::Index** $sup5638x25x0x0x2index1427;  slog::Index** $sup5638x25x0x0x1index1428;  slog::Index** mp_hsb_ansindex1429;  slog::Index** $sup5638x25x0x0x2index1430;  slog::Index** mp_mskindex1431;  slog::Index** mp_hsb_ansindex1432;  slog::Index** $sup5638x25x0x0x1index1433;  slog::Index** $sup5638x25x0x0x2index1434;  slog::Index** $sup5638x25x0x0x1index1435;  slog::Index** $sup5638x25x0x0x0index1436;  slog::Index** mp_joinindex1437;  slog::Index** mp_mskindex1438;  slog::Index** mp_msk_ansindex1439;  slog::Index** mp_hsbindex1440;  slog::Index** mp_hsb_ansdelta1441;  slog::Index** mp_hsb_ansdelta1442;  slog::Index** mp_joindelta1443;  slog::Index** mp_mskdelta1444;  slog::Index** mp_msk_ansdelta1445;  slog::Index** mp_hsbdelta1446;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord1448({0, 1});
      slog::Relation* readrel1449 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1426 = readrel1449->getIndex(ord1448, false);
      std::vector<u16> ord1450({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel1451 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1427 = readrel1451->getIndex(ord1450, false);
      std::vector<u16> ord1452({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1453 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index1428 = readrel1453->getIndex(ord1452, false);
      std::vector<u16> ord1454({0, 1});
      slog::Relation* readrel1455 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1429 = readrel1455->getIndex(ord1454, false);
      std::vector<u16> ord1456({0, 1});
      slog::Relation* readrel1457 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1441 = readrel1457->getIndex(ord1456, true);
      std::vector<u16> ord1458({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel1459 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1430 = readrel1459->getIndex(ord1458, false);
      std::vector<u16> ord1460({2, 0, 1});
      slog::Relation* readrel1461 = db->getRelation("mp_msk");
      mp_mskindex1431 = readrel1461->getIndex(ord1460, false);
      std::vector<u16> ord1462({0, 1});
      slog::Relation* readrel1463 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1432 = readrel1463->getIndex(ord1462, false);
      std::vector<u16> ord1464({0, 1});
      slog::Relation* readrel1465 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta1442 = readrel1465->getIndex(ord1464, true);
      std::vector<u16> ord1466({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1467 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index1433 = readrel1467->getIndex(ord1466, false);
      std::vector<u16> ord1468({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1469 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index1434 = readrel1469->getIndex(ord1468, false);
      std::vector<u16> ord1470({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1471 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index1435 = readrel1471->getIndex(ord1470, false);
      std::vector<u16> ord1472({1, 0, 2, 3, 4});
      slog::Relation* readrel1473 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index1436 = readrel1473->getIndex(ord1472, false);
      std::vector<u16> ord1474({1, 2, 3, 4, 0});
      slog::Relation* readrel1475 = db->getRelation("mp_join");
      mp_joinindex1437 = readrel1475->getIndex(ord1474, false);
      std::vector<u16> ord1476({1, 2, 3, 4, 0});
      slog::Relation* readrel1477 = db->getRelation("mp_join");
      mp_joindelta1443 = readrel1477->getIndex(ord1476, true);
      std::vector<u16> ord1478({1, 2, 0});
      slog::Relation* readrel1479 = db->getRelation("mp_msk");
      mp_mskindex1438 = readrel1479->getIndex(ord1478, false);
      std::vector<u16> ord1480({1, 2, 0});
      slog::Relation* readrel1481 = db->getRelation("mp_msk");
      mp_mskdelta1444 = readrel1481->getIndex(ord1480, true);
      std::vector<u16> ord1482({0, 1});
      slog::Relation* readrel1483 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1439 = readrel1483->getIndex(ord1482, false);
      std::vector<u16> ord1484({0, 1});
      slog::Relation* readrel1485 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta1445 = readrel1485->getIndex(ord1484, true);
      std::vector<u16> ord1486({0, 1});
      slog::Relation* readrel1487 = db->getRelation("mp_hsb");
      mp_hsbindex1440 = readrel1487->getIndex(ord1486, false);
      std::vector<u16> ord1488({0, 1});
      slog::Relation* readrel1489 = db->getRelation("mp_hsb");
      mp_hsbdelta1446 = readrel1489->getIndex(ord1488, true);
  
    }
    ReadTask1447(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c269 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c271 = _t[0];
        u64 v_c274 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex1426, std::array<u64,2>{v_c271, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index1427, std::array<u64,11>{v_c271, v_c274, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index1428, std::array<u64,7>{v_c271, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(mp_hsb_ansindex1429, mp_hsb_ansdelta1441, std::array<u64,2>{v_c271, 0}, [&](const std::array<u64,2>& m1490) {
          u64 v_c78 = m1490[1];
          if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index1430, std::array<u64,11>{v_c271, v_c78, v_c274, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex1431, std::array<u64,3>{v_c78, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex1432, mp_hsb_ansdelta1442, std::array<u64,2>{v_c271, 0}, [&](const std::array<u64,2>& m1491) {
            u64 v_c66 = m1491[1];
            if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index1433, std::array<u64,7>{v_c271, v_c66, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup5638x25x0x0x2index1434, std::array<u64,11>{v_c271, v_c66, v_c274, v_c78, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1492) {
              u64 v_c270 = m1492[4]; u64 v_c272 = m1492[5]; u64 v_c273 = m1492[6]; u64 v_c164 = m1492[7]; u64 v_c166 = m1492[8]; u64 v_c165 = m1492[9]; u64 v_c167 = m1492[10];
              if (v_c271 != v_c273) return;
              if (v_c271 != v_c272) return;
              slog::join_probe<7,7>($sup5638x25x0x0x1index1435, std::array<u64,7>{v_c270, v_c164, v_c166, v_c165, v_c167, v_c271, v_c66}, [&](const std::array<u64,7>& m1493) {
                slog::join_probe<5,5>($sup5638x25x0x0x0index1436, std::array<u64,5>{v_c164, v_c270, v_c166, v_c165, v_c167}, [&](const std::array<u64,5>& m1494) {
                  slog::join_probe_old<5,5>(mp_joinindex1437, mp_joindelta1443, std::array<u64,5>{v_c164, v_c165, v_c166, v_c167, v_c270}, [&](const std::array<u64,5>& m1495) {
                    slog::join_probe_old<3,2>(mp_mskindex1438, mp_mskdelta1444, std::array<u64,3>{v_c164, v_c78, 0}, [&](const std::array<u64,3>& m1496) {
                      u64 v_c275 = m1496[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex1439, mp_msk_ansdelta1445, std::array<u64,2>{v_c275, 0}, [&](const std::array<u64,2>& m1497) {
                        u64 v_c88 = m1497[1];
                        u64 v_c276 = _prim_bxor(db, v_c164, v_c166);
                        if (v_c276 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex1440, mp_hsbdelta1446, std::array<u64,2>{v_c271, v_c276}, [&](const std::array<u64,2>& m1498) {
                          u64 v_c277 = _prim_band(db, v_c164, v_c66);
                          if (v_c277 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c281 = _prim_lt(db, v_c277, v_c269);
                          if (v_c281 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c281) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c270, v_c88, v_c274, v_c165, v_c167});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c88, v_c274, v_c165, v_c167}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask1447* _cont = new ReadTask1447(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1447(db,b), false);
  // (crule (pre) (scan temp390O1909 __t53ZH245) (body) (head (mkstruct mp_hsb (1 0) __9fVT1303 __t53ZH245)) map.slog:26 #f)
  class ReadTask1500 : public slog::Task
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
      outer_rel = db->getRelation("temp390O1909");
  
    }
    ReadTask1500(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c282 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c282}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:temp390O1909", _fires);
  
      if (!_done)
      {
        ReadTask1500* _cont = new ReadTask1500(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1500(db,b), false);
}

